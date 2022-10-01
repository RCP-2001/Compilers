#include "Semantic.h"
int testGlobal = 0;
void semanticAnalysis(SymbolTable *symTbl, treeNode *tree)
{
    if (tree == NULL)
    {
        return;
    }

    TokenData *TData = tree->token();

    // Functions
    if (tree->Kind() == DeclK && tree->DKind() == FuncK)
    {
        if (symTbl->insert(TData->tokenstr, tree) == false)
        {
            treeNode *n = (treeNode *)symTbl->lookup(TData->tokenstr);
            printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", TData->linenum, TData->tokenstr, n->token()->linenum);
        }
        symTbl->enter(TData->tokenstr);
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());

        return;
        // printf("TEST TYPE BEAT %s \n\n\n", TData->tokenstr);
    }
    // params and variables
    else if (tree->Kind() == DeclK)
    {
        if (symTbl->insert(TData->tokenstr, tree) == false)
        {
            treeNode *n = (treeNode *)symTbl->lookup(TData->tokenstr);
            printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", TData->linenum, TData->tokenstr, n->token()->linenum);
        }

        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        semanticAnalysis(symTbl, tree->GetChild(2));
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    // Compund Statements
    else if (tree->Kind() == StmtK && tree->SKind() == CompoundK)
    {
        symTbl->enter("CompundStatement");
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    else if (tree->Kind() == StmtK && tree->SKind() == ForK)
    {
        //idk this might be wrong KEKW
        symTbl->enter("ForLoop");
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    //******************

    //********************

    // Refrences to variables
    else if (tree->Kind() == ExpK && tree->EKind() == IdK)
    {
        void *p = symTbl->lookup(TData->tokenstr);
        if (p == NULL)
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", TData->linenum, TData->tokenstr);
        }
    }

    //  symTbl->print( printTreeNode );

    // symTbl->enter("sub 1 ");
    semanticAnalysis(symTbl, tree->GetChild(0));
    // symTbl->leave();

    // symTbl->enter("sub 2 ");
    semanticAnalysis(symTbl, tree->GetChild(1));
    // symTbl->leave();

    // symTbl->enter("sub 3 ");
    semanticAnalysis(symTbl, tree->GetChild(2));
    // symTbl->leave();
    // symTbl->leave();

    semanticAnalysis(symTbl, tree->nextSibling());

    //  symTbl->print( printTreeNode );
}

void printTreeNode(void *node)
{
    treeNode *tNode = (treeNode *)node;
    printf("TS: %s, numVale %d, cval %c, sval %s ", tNode->token()->tokenstr, tNode->token()->nvalue, tNode->token()->cvalue, tNode->token()->svalue);
}