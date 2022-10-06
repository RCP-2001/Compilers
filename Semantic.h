#include "SymTbl/symbolTable.h"
#include "scanType.h"
#include <string>


void printTreeNode(void* node);


void semanticAnalysis(SymbolTable* symTbl, treeNode* tree);

bool OpTokenIsBool(char *);
std::string OpType(char *);

void CheckForUse(std::string, void *);

// Finds LHS of assign and array accessor
treeNode* FindSymbol(treeNode*);