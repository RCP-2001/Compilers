
#include "scanType.h"
#include "Semantic.h"
#include "parser.tab.h"
#include "SymTbl/symbolTable.h"
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <getopt.h>

treeNode *GLOBAL_HEAD;
extern FILE *yyin;      // defined in parser.l
extern int numErrors;   // defined in parser.l
int numWarnings; // defined in parser.l

extern int yydebug;
int main(int argc, char *argv[])
{
    numErrors = 0;
    numWarnings = 0;

    int Debug = 0;
    int Print = 0;
    int opt;
    while ((opt = getopt(argc, argv, "dp")) != -1)
    {
        switch (opt)
        {
        case 'd':
            Debug = 1;
            break;
        case 'p':
            Print = 1;
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

    GLOBAL_HEAD = NULL;
    if (argc > 1)
    {
        if ((yyin = fopen(argv[optind], "r")))
        {
            // file open successful
        }
        else
        {
            printf("ERR: Failed to open %s \n", argv[optind]);
            exit(1);
        }
    }
    //***********************End of setup type beat**********************

    yyparse();
    SymbolTable *symTbl = new SymbolTable;
    //symTbl->debug(true);
    symTbl->print( printTreeNode );

    if (Print == 1)
    {
        if (GLOBAL_HEAD != NULL)
        {
            GLOBAL_HEAD->printTree(1, 1);
            printf("\n");
        }
    }
    semanticAnalysis(symTbl, GLOBAL_HEAD);


    // Deleting Tree because we are done with it
    // note: Make sure the complier is 100% done done before doing this
    if (GLOBAL_HEAD != NULL)
    {
        delete GLOBAL_HEAD;
        GLOBAL_HEAD = NULL;
    }
    // printf("Number of errors: %d\n", numErrors);
}