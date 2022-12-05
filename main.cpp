
#include "scanType.h"
#include "Semantic.h"
#include "parser.tab.h"
#include "SymTbl/symbolTable.h"
#include "IO.h"
#include "YYError/yyerror.h"
#include "MemLocFinder/MemLoc.h"
#include "CodeGen/CodeGen.h"
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <getopt.h>

treeNode *GLOBAL_HEAD;
extern FILE *yyin;      // defined in parser.l
extern int numErrors;   // defined in parser.l
extern int numWarnings; // defined in parser.l
extern int goffset;     // defined in MemLoc

extern int yydebug;
int main(int argc, char *argv[])
{
    numErrors = 0;
    numWarnings = 0;

    int Debug = 0;
    int Print = 0;
    int SymDebug = 0;
    int TypePrint = 0;
    int help = 0;
    int MemPrint = 0;

    int opt;
    while ((opt = getopt(argc, argv, "dpDPhM")) != -1)
    {
        switch (opt)
        {
        case 'd':
            Debug = 1;
            break;
        case 'p':
            Print = 1;
            break;
        case 'P':
            TypePrint = 1;
            break;
        case 'D':
            SymDebug = 1;
            break;
        case 'h':
            help = 1;
            break;
        case 'M':
            MemPrint = 1;
            break;
        default:
            break;
        }
    }
    // printf("Debug: %d, Print: %d\n", Debug, Print);
    // Init map
    initErrorProcessing();

    if (Debug == 1)
    {
        yydebug = 1;
    }
    if (help == 1)
    {
        printf("usage: -c [options] [sourcefile]\n");
        printf("options:\n");
        printf("-d - turn on parser debugging\n");
        printf("-D - turn on symbol table debugging\n");
        printf("-h - print this usage message\n");
        printf("-p - print the abstract syntax tree");
        printf("-P - print the abstract syntax tree plus type information");
        printf("-M - print the abstract syntax tree plus memmory location information");
    }

    treeNode *IOTree = MakeIOFuncs();

    GLOBAL_HEAD = NULL;

    if ((yyin = fopen(argv[optind], "r")))
    {
        // file open successful
    }
    else
    {
        printf("ERROR(ARGLIST): source file \"%s\" could not be opened.\n", argv[optind]);
        printf("Number of warnings: 0\n");
        printf("Number of errors: 1\n");
        exit(1);
    }

    //***********************End of setup type beat**********************

    yyparse();
    SymbolTable *symTbl = new SymbolTable;
    if (SymDebug == 1)
    {
        symTbl->debug(true);
    }
    // symTbl->debug(true);

    if (Print == 1)
    {
        if (GLOBAL_HEAD != NULL)
        {
            GLOBAL_HEAD->printTree(1, 1);
            printf("\n");
        }
    }
    // Sematic analysus
    if (numErrors == 0)
    {
        // add IO funcs to symTbl
        semanticAnalysis(symTbl, IOTree);
        // fprintf(stderr,"Token %s\n",  IOTree->token()->tokenstr);

        semanticAnalysis(symTbl, GLOBAL_HEAD);
        // symTbl->print(printTreeNode);

        symTbl->applyToAllGlobal(CheckForUse);

        treeNode *n = (treeNode *)symTbl->lookup("main");
        if (n == NULL)
        {
            printf("ERROR(LINKER): A function named 'main' with no parameters must be defined.\n");
            numErrors++;
        }
        else if (n->GetChild(0) != NULL)
        {
            printf("ERROR(LINKER): A function named 'main' with no parameters must be defined.\n");
            numErrors++;
        }
        else if (n->DKind() != FuncK)
        {
            printf("ERROR(LINKER): A function named 'main' with no parameters must be defined.\n");
            numErrors++;
        }
    }
    if (TypePrint == 1 && numErrors == 0)
    {
        if (GLOBAL_HEAD != NULL)
        {
            SymbolTable *PrintSymTbl = new SymbolTable;
            if (SymDebug == 1)
            {
                PrintSymTbl->debug(true);
            }
            // Add IO to new SymTbl
            semanticAnalysis(PrintSymTbl, IOTree);
            // PrintSymTbl->debug(true);
            GLOBAL_HEAD->printTree(1, 1, PrintSymTbl);
            printf("\n");
        }
    }

    if (MemPrint == 1 && numErrors == 0)
    {
        if (GLOBAL_HEAD != NULL)
        {
            SymbolTable *Mem = new SymbolTable;
            MemLocSet(GLOBAL_HEAD, Mem);
            SymbolTable *PrintSymTbl = new SymbolTable;
            if (SymDebug == 1)
            {
                PrintSymTbl->debug(true);
            }
            if (SymDebug == 1)
            {
                //    Mem->debug(true);
            }
            // Add IO to new SymTbl
            semanticAnalysis(PrintSymTbl, IOTree);
            // PrintSymTbl->debug(true);
            GLOBAL_HEAD->printMemTree(1, 1, PrintSymTbl);
            printf("\n");
        }
        printf("Offset for end of global space: %d\n", goffset);
    }

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    // Deleting Tree because we are done with it
    // note: Make sure the complier is 100% done done before doing this
    if (GLOBAL_HEAD != NULL)
    {
        std::string OutfileName = basename(argv[optind]);

        // OutfileName = basename(argv[o]);
        OutfileName = OutfileName.substr(0, OutfileName.find_first_of("."));
        std::cout << OutfileName << std::endl;
        // return 0;
        std::ofstream Outfile(OutfileName + ".tm");

        // CodeGen Before deletion
        ListNode *H = Linearize(GLOBAL_HEAD);
        GenerateIOLib(Outfile);
        H->GenerateCode(Outfile);
        Init(Outfile);
        Outfile.close();
        delete GLOBAL_HEAD; //
        GLOBAL_HEAD = NULL;
    }
    // printf("Number of errors: %d\n", numErrors);
}