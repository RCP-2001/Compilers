#include<stdlib.h>

typedef int OpKind;
enum NodeKind {DeclK, StmtK, ExpK};
enum DeclKind {VarK, FuncK, ParamK};
enum StmtKind {NullK, IfK, WhileK, ForK, CompoundK, ReturnK, BreaK, RangeK};
enum ExpKind {OpK, constantK, IdK, AssingK, InitK, CallK};
enum ExpType {Void, Integer, boolean, Char, CharInt, Equal, UndefinedType};
enum VarKind {None, Local, Global, Parameter, LocalStatic};

// might turn all these into classes??? IDK

struct TokenData{
    int tokenclass;
    int linenum;
    char *tokenstr;
    char cvalue;
    int nvalue;
    char *svalue;
};

const int MAX_CHILDREN = 3; // idk 3 probably isnt enough but we can mess with this lol

typedef struct treeNode{
    struct treeNode *child[MAX_CHILDREN];
    struct treeNode *sibling;

    //node type
    int line_num;
    NodeKind nodeKind; // type? Probably need to figure something out
    union
    {
        DeclKind decl;
        StmtKind stmt;
        ExpKind exp;
    } subkind;

    //this is the attr union in notes, 
    //might need to add some stuff to struct
    TokenData attr;

    ExpType expType;
    bool isArray;
    bool isStatic;
} treeNode;

treeNode newDeclNode(DeclKind kind, ExpType type, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);
treeNode newStmtNode(DeclKind kind, ExpType type, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);
treeNode newExpNode(DeclKind kind, ExpType type, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);




