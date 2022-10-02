#include "SymTbl/symbolTable.h"
#include "scanType.h"



void printTreeNode(void* node);


void semanticAnalysis(SymbolTable* symTbl, treeNode* tree);

bool OpTokenIsBool(char *);
const char* OpType(char *);