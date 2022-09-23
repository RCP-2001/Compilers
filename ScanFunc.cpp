#include "scanType.h"
#include <string.h>

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    // fprintf(stderr, "DECL NODE START\n");
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;

    node->sibling = NULL;
    // node.line_num = ???;
    node->nodeKind = DeclK;
    node->subkind.decl = kind;
    node->attr = token;

    node->expType = type;

    // fprintf(stderr, "DEC NODE  Return\n");
    return node;
}

treeNode *newStmtNode(StmtKind kind, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    // fprintf(stderr, "STMT NODE START\n");
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;
    printf("");

    node->sibling = NULL;
    // node.line_num = ???;
    node->nodeKind = StmtK;
    node->subkind.stmt = kind;
    node->attr = token;
    // fprintf(stderr, "STMT NODE START\n");
    return node;
}

treeNode *newExpNode(ExpKind kind, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;

    node->sibling = NULL;
    // node.line_num = ???;
    node->nodeKind = ExpK;
    node->subkind.exp = kind;
    node->attr = token;

    return node;
}

void treeNode::addSibling(treeNode *aNode)
{
    // fprintf(stderr, "SIBLING NODE START\n");
    if (sibling == NULL)
    {
        // fprintf(stderr, "SIBLING NODE IF\n");
        sibling = aNode;
        return;
    }
    else
    {
        //   fprintf(stderr, "SIBLING NODE ELSE\n");
        sibling->addSibling(aNode);
    }
}

void treeNode::EType(ExpType etype)
{
    expType = etype;
    if (sibling != NULL)
    {
        sibling->EType(etype);
    }
}

void treeNode::BStatic(bool type)
{
    isStatic = type;
}

void treeNode::addChildren(treeNode *aNode, int c)
{
    if (c >= MAX_CHILDREN)
    {
        fprintf(stderr, "too many children LOL\n");
    }
    // should make sure child[c] does already have something LMAO
    child[c] = aNode;
}

void treeNode::printTree(int levels, int siblingNum)
{
    // printf("\n");

    // this will almost 100% be the print sturcture, just want to make sure i got the tree mostly right
    switch (nodeKind)
    {
    case DeclK:
        // printf("DeclNode, kind: %d , ETYPE= %d, [line: %d]", subkind.decl, expType, attr->linenum);
        char* Stat;
        if(isStatic == true){
            Stat = strdup(" static");
        }
        else{
            Stat = strdup("\0");
        }


        switch (subkind.decl)
        {
        case VarK:
            if (isArray == true)
            {
                printf("Var: %s of array of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE(), attr->linenum);
            }
            else
            {
                printf("Var: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE(), attr->linenum);
            }
            break;
        case FuncK:
            if (isArray == true)
            {
                printf("Func: %s returns array type %s [line: %d]", attr->svalue, RetETYPE(), attr->linenum); // dont know if nesscisary
            }
            else
            {
                printf("Func: %s returns type %s [line: %d]", attr->svalue, RetETYPE(), attr->linenum);
            }
            break;
        case ParamK:
            if (isArray == true)
            {
                printf("Parm: %s of%s array of type %s [line: %d]", attr->svalue, Stat, RetETYPE(), attr->linenum);
            }
            else
            {
                printf("Parm: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE(), attr->linenum);
            }
            break;
        default:
            fprintf(stderr, "DECLK error- no valid subkind");
            break;
        }
        free(Stat);
        Stat = NULL;
        break;

    case StmtK:
        // printf("StmtNode, Kind: %d,  [line: %d]", subkind.stmt, attr->linenum);
        switch (subkind.stmt)
        {
        case NullK:
            printf("Null [line: %d]", attr->linenum);
            break;
        case IfK:
            printf("If [line: %d]", attr->linenum);
            break;
        case WhileK:
            printf("While [line: %d]", attr->linenum);
            break;
        case ForK:
            printf("For [line: %d]", attr->linenum);
            break;
        case CompoundK:
            printf("Compound [line: %d]", attr->linenum);
            break;
        case ReturnK:
            printf("Return [line: %d]", attr->linenum);
            break;
        case BreaK:
            printf("Break [line: %d]", attr->linenum);
            break;
        case RangeK:
            printf("Range [line: %d]", attr->linenum);
            break;
        default:
            fprintf(stderr, "STMTK error- no valid subkind");
            break;
        }
        break;

    case ExpK:
        // printf("ExpNode, Kind: %d,  [line: %d]-- Testing something: %s", subkind.exp, attr->linenum, attr->tokenstr);
        switch (subkind.exp)
        {
        case OpK:
            printf("Op: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case constantK:
            printf("Const %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case IdK:
            printf("Id: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case AssingK:
            printf("Assign: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case InitK:
            printf("Init: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case CallK:
            printf("Call: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        default:
            break;
        }
        break;

    default:
        fprintf(stderr, "WTF!! nodeKind = %d\n ", nodeKind);
        break;
    }

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        if (child[i] != NULL)
        {
            printf("\n");
            for (int j = 0; j < levels; j++)
            {
                printf(".   ");
            }

            printf("Child: %d  ", i);
            child[i]->printTree(levels + 1, 1);
        }
    }

    if (sibling != NULL)
    {
        printf("\n");
        for (int i = 1; i < levels; i++)
        {
            printf(".   ");
        }
        printf("Sibling: %d  ", siblingNum);
        sibling->printTree(levels, siblingNum + 1);
    }
}
