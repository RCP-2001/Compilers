#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "SymTbl/symbolTable.h"
#include "scanType.h"
#include <string>


void printTreeNode(void* node);


void semanticAnalysis(SymbolTable* symTbl, treeNode* tree);

bool OpTokenIsBool(char *);
std::string OpType(char *);

void CheckForUse(std::string, void *);


treeNode* CheckType(treeNode*, SymbolTable*);

void InitSiblings(treeNode* );

bool  FindArrayAccessorOp(treeNode*);
bool FindAssingOp(treeNode*);

void ParamTypeCheck(treeNode* n, treeNode* t, SymbolTable* symTbl);

bool FindReturn(treeNode* Func, treeNode* test, SymbolTable* symTbl);

void FindBreaks(treeNode* test);

#endif