
#include "scanType.h"
#include "Semantic.h"
#include "parser.tab.h"
#include "SymTbl/symbolTable.h"
#include "IO.h"
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <getopt.h>

treeNode *GLOBAL_HEAD;
extern FILE *yyin;      // defined in parser.l
extern int numErrors;   // defined in parser.l
extern int numWarnings; // defined in parser.l

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

    int opt;
    while ((opt = getopt(argc, argv, "dpDPh")) != -1)
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
        default:
            break;
        }
    }
    // printf("Debug: %d, Print: %d\n", Debug, Print);

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

    if (TypePrint == 1 && numErrors == 0)
    {
        // not going to worry about making a proper -P option just yet (will work on after turning in to test harnness)
        // If this is in the version that gets graded... Sadge
        if (GLOBAL_HEAD != NULL)
        {
            SymbolTable *PrintSymTbl = new SymbolTable;
            //Add IO to new SymTbl
            semanticAnalysis(PrintSymTbl, IOTree);
            // PrintSymTbl->debug(true);
            GLOBAL_HEAD->printTree(1, 1, PrintSymTbl);
            printf("\n");
        }
    }
    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    // Deleting Tree because we are done with it
    // note: Make sure the complier is 100% done done before doing this
    if (GLOBAL_HEAD != NULL)
    {
        delete GLOBAL_HEAD;
        GLOBAL_HEAD = NULL;
    }
    // printf("Number of errors: %d\n", numErrors);
}