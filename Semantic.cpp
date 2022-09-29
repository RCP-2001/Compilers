#include "Semantic.h"

void semanticAnalysis(SymbolTable* symTbl, treeNode* tree){
    TokenData* TData = tree->token();
    printf("TEST TYPE BEAT %s \n\n\n", TData->tokenstr);
}

void printTreeNode(treeNode* node){
    printf("");
}