#include "SymTbl/symbolTable.h"
#include "scanType.h"
#include <string>


void printTreeNode(void* node);


void semanticAnalysis(SymbolTable* symTbl, treeNode* tree);

bool OpTokenIsBool(char *);
std::string OpType(char *);