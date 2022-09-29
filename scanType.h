#include <stdlib.h>
#include <stdio.h>
const int MAX_CHILDREN = 3;
// porbably need to move more magic numbers here

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


class treeNode
{
    private:
    struct treeNode *child[MAX_CHILDREN];
    struct treeNode *sibling;

    // node type
    //int line_num;
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

    public:


    // inline functions
    void SetNodeKind(NodeKind nkind){
        nodeKind=nkind;
    }
    void SubKind(ExpKind k){
        subkind.exp = k;
    }
    void SubKind(StmtKind k){
        subkind.stmt = k;
    }
    void SubKind(DeclKind k){
        subkind.decl = k;
    }
    void addAttr(TokenData* n){
        if(attr != NULL){
            fprintf(stderr ,"Err- probably a mem leak\n");
        }
        attr = n;
    }

    void setArray(bool val){
        isArray = val;
    }

    const char *RetETYPE()
    {
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
    }
    ~treeNode(){
        for(int i =0; i < MAX_CHILDREN; i++){
            if(child[i] != NULL){
                delete child[i];
                child[i] = NULL;
            }
        }
        if(sibling != NULL){
            delete sibling;
            sibling = NULL;
        }
        if(attr != NULL){
            if(attr->tokenstr != NULL){
                free(attr->tokenstr);
            }
            if(attr->svalue != NULL){
                free(attr->svalue);
            }
            delete attr;
        }



    }

    // other functions
    void BStatic(bool);
    void EType(ExpType);
    void addSibling(treeNode *);
    void addChildren(treeNode *, int child);
    void printTree(int levels, int);

    //function for acessing private elements
    //Ideally should be read only
    TokenData* token(){ return attr; }
    
};

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);
treeNode *newStmtNode(StmtKind kind, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);
treeNode *newExpNode(ExpKind kind, TokenData *token = NULL, treeNode *c0 = NULL, treeNode *c1 = NULL, treeNode *c2 = NULL);
