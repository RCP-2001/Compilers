#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "Semantic.h"
//#include "SymTbl/symbolTable.cpp"

#ifndef MAX_CHILDREN
#define MAX_CHILDREN 3
// const int MAX_CHILDREN = 3;
//  porbably need to move more magic numbers here
#endif

#ifndef TYPES
#define TYPES
enum NodeKind
{
    DeclK,
    StmtK,
    ExpK
};
enum DeclKind
{
    VarK,
    FuncK,
    ParamK
};
enum StmtKind
{
    NullK,
    IfK,
    WhileK,
    ForK,
    CompoundK,
    ReturnK,
    BreaK,
    RangeK
};
enum ExpKind
{
    OpK,
    constantK,
    IdK,
    AssingK,
    InitK,
    CallK
};
enum ExpType
{
    Void,
    Integer,
    boolean,
    Char,
    CharInt,
    Equal,
    Str,
    UndefinedType
};
enum VarKind
{
    None,
    Local,
    Global,
    Parameter,
    LocalStatic
};

struct TokenData
{
    int tokenclass;
    int linenum;
    char *tokenstr;
    char cvalue;
    int nvalue;
    char *svalue;
};
#endif

#ifndef AST
#define AST

std::string RETYPE(ExpType e);

class treeNode
{
private:
    struct treeNode *child[MAX_CHILDREN];
    struct treeNode *sibling;

    // node type
    // int line_num;
    NodeKind nodeKind; // type? Probably need to figure something out
    union
    {
        DeclKind decl;
        StmtKind stmt;
        ExpKind exp;
    } subkind;

    // this is the attr union in notes,
    // might need to add some stuff to struct
    TokenData *attr;

    ExpType expType;

    bool isArray;
    bool isStatic;
    bool isGlobal;
    // may be dumb haha
    bool isUsed;
    bool isInit;
    int Size;
    int Loc;
    //bool InitMessagePlayed;

public:
    // inline functions
    void SetNodeKind(NodeKind nkind)
    {
        nodeKind = nkind;
    }
    void SubKind(ExpKind k)
    {
        subkind.exp = k;
    }
    void SubKind(StmtKind k)
    {
        subkind.stmt = k;
    }
    void SubKind(DeclKind k)
    {
        subkind.decl = k;
    }
    void addAttr(TokenData *n)
    {
        if (attr != NULL)
        {
            fprintf(stderr, "Err- probably a mem leak\n");
        }
        attr = n;
    }

    void setArray(bool val)
    {
        isArray = val;
    }

    std::string RetETYPE()
    {
        return RETYPE(expType);
    }

    // Constructor
    treeNode()
    {
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            child[i] = NULL;
        }
        sibling = NULL;
        attr = NULL;
        isArray = false;
        isStatic = false;
        isGlobal = false;
        isInit = false;
        isUsed = false;
        //InitMessagePlayed = false;
    }
    ~treeNode()
    {
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            if (child[i] != NULL)
            {
                delete child[i];
                child[i] = NULL;
            }
        }
        if (sibling != NULL)
        {
            delete sibling;
            sibling = NULL;
        }
        // Small chance of seg fault when working "properly"
        // Something in parser.y probably gets the same token
        // Will deal with
        if (attr != NULL)
        {
            if (attr->tokenstr != NULL)
            {
                //free(attr->tokenstr);
            }
            if (attr->svalue != NULL)
            {
                //free(attr->svalue);
            }
            //delete attr;
            //attr == NULL;
        }
    }

    // other functions
    void BStatic(bool);
    void BGlobal(bool);
    void EType(ExpType);
    void addSibling(treeNode *);
    void addChildren(treeNode *, int child);
    void printTree(int levels, int);
    void printTree(int levels, int, SymbolTable* symTbl);
    void printMemTree(int levels, int, SymbolTable* symTbl);
    int GetChildren(int);
    std::string StringVal();

    // function for acessing private elements
    // Ideally should be read only
    TokenData *token() { return attr; }
    treeNode *nextSibling() { return sibling; }
    treeNode *GetChild(int c) { return child[c]; }
    NodeKind Kind() { return nodeKind; }
    DeclKind DKind() { return subkind.decl; }
    ExpKind EKind() { return subkind.exp; }
    StmtKind SKind() { return subkind.stmt; }
    ExpType EType() { return expType; }
    bool ArrayIs() {return isArray; }
    bool UsedIs() {return isUsed;}
    void UsedIs(bool x){ isUsed = x; }
    bool InitIs() {return isInit;}
    void InitIs(bool x){ isInit = x; }
    bool StaticIs(){ return isStatic;}
    bool GlobablIs() {return isGlobal;}

    void SetSize(int x){ Size = x;}
    void SetLoc(int x){ Loc = x;}
    int GetLoc(){return Loc;}
    int GetSize() {return Size;}

    int SiblingSize();


};

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);
treeNode *newStmtNode(StmtKind kind, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);
treeNode *newExpNode(ExpKind kind, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);

char* getMemType(treeNode*, SymbolTable*);

#endif
