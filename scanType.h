#include<stdlib.h>
#include<stdio.h>
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

class treeNode{
    public:             //All this should be public lol. Will fix later
    struct treeNode *child[MAX_CHILDREN];
    struct treeNode *sibling;
    void addSibling(treeNode*);
    void addChildren(treeNode*, int child);

    void printTree(int levels, int);

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
    TokenData* attr;

    ExpType expType;
    void EType(ExpType);
    const char* RetETYPE(){
        char *c;
        switch (expType)
        {
        case Void:
            return "void";
            break;
        case Integer:
            return "int";
            break;
        case boolean:
            return "bool";
            break;
        case Char:
            return "char";
            break;
        case CharInt:
            return "CharInt";
            break;
        case Equal:
            return "Equal";
            break;
        case UndefinedType:
            return "UndefinedType";
            break;
        default:
            return "ERRR TYPE";
            break;
        }
    }

    bool isArray;
    bool isStatic;
    void BStatic(bool);

    treeNode(){
        for(int i = 0; i<MAX_CHILDREN; i++){
            child[i] = NULL;
        }
        sibling = NULL;
        attr = NULL;
        isArray = false;
        isStatic = false;
    }
};

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);
treeNode *newStmtNode(StmtKind kind, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);
treeNode *newExpNode(ExpKind kind, TokenData* token=NULL, treeNode* c0=NULL, treeNode* c1=NULL, treeNode* c2=NULL);


