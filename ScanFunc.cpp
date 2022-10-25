#include "scanType.h"
#include <string.h>
#include <string>

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    // fprintf(stderr, "DECL NODE START\n");
    treeNode *node = new treeNode;
    node->addChildren(c0, 0);
    node->addChildren(c1, 1);
    node->addChildren(c2, 2);

    // node->sibling = NULL;
    //  node.line_num = ???;
    node->SetNodeKind(DeclK);
    node->SubKind(kind);
    node->addAttr(token);

    node->EType(type);

    // fprintf(stderr, "DEC NODE  Return\n");
    return node;
}

treeNode *newStmtNode(StmtKind kind, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    // fprintf(stderr, "STMT NODE START\n");
    treeNode *node = new treeNode;
    node->addChildren(c0, 0);
    node->addChildren(c1, 1);
    node->addChildren(c2, 2);
    printf("");

    // node->sibling = NULL;
    //  node.line_num = ???;
    node->SetNodeKind(StmtK);
    node->SubKind(kind);
    node->addAttr(token);
    // fprintf(stderr, "STMT NODE START\n");
    return node;
}

treeNode *newExpNode(ExpKind kind, TokenData *token, treeNode *c0, treeNode *c1, treeNode *c2)
{
    treeNode *node = new treeNode;
    node->addChildren(c0, 0);
    node->addChildren(c1, 1);
    node->addChildren(c2, 2);

    // node->sibling = NULL;
    //  node.line_num = ???;
    node->SetNodeKind(ExpK);
    node->SubKind(kind);
    node->addAttr(token);

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
    if (sibling != NULL)
    {
        sibling->BStatic(type);
    }
}

void treeNode::addChildren(treeNode *aNode, int c)
{
    if (c >= MAX_CHILDREN)
    {
        fprintf(stderr, "too many children LOL\n");
    }
    // should make sure child[c] does already have something LMAO
    if (child[c] != NULL)
    {
        fprintf(stderr, "Err- probably a mem leak\n");
    }
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
        char *Stat;
        if (isStatic == true)
        {
            Stat = strdup(" static");
        }
        else
        {
            Stat = strdup("\0");
        }

        switch (subkind.decl)
        {
        case VarK:
            if (isArray == true)
            {
                printf("Var: %s is array of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            else
            {
                printf("Var: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            break;
        case FuncK:
            if (isArray == true)
            {
                printf("Func: %s returns array type %s [line: %d]", attr->svalue, RetETYPE().c_str(), attr->linenum); // dont know if nesscisary
            }
            else
            {
                printf("Func: %s returns type %s [line: %d]", attr->svalue, RetETYPE().c_str(), attr->linenum);
            }
            break;
        case ParamK:
            if (isArray == true)
            {
                printf("Parm: %s is%s array of type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            else
            {
                printf("Parm: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
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

std::string RETYPE(ExpType e)
{
    switch (e)
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
//********************************************************

void treeNode::printTree(int levels, int siblingNum, SymbolTable *symTbl)
{
    // printf("\n");
    std::string opType;
    treeNode *p;
    treeNode *n;

    // this will almost 100% be the print sturcture, just want to make sure i got the tree mostly right
    switch (nodeKind)
    {
    case DeclK:
        // printf("DeclNode, kind: %d , ETYPE= %d, [line: %d]", subkind.decl, expType, attr->linenum);
        symTbl->insert(attr->tokenstr, this);

        char *Stat;
        if (isStatic == true)
        {
            Stat = strdup(""); // sample output doesnt specify static this time i guess lol
        }
        else
        {
            Stat = strdup("\0");
        }

        switch (subkind.decl)
        {
        case VarK:
            if (isArray == true)
            {
                printf("Var: %s is array of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            else
            {
                printf("Var: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            break;
        case FuncK:
            symTbl->enter(attr->tokenstr);
            if (isArray == true)
            {
                printf("Func: %s returns array type %s [line: %d]", attr->svalue, RetETYPE().c_str(), attr->linenum); // dont know if nesscisary
            }
            else
            {
                printf("Func: %s returns type %s [line: %d]", attr->svalue, RetETYPE().c_str(), attr->linenum);
            }
            break;
        case ParamK:
            if (isArray == true)
            {
                printf("Parm: %s is%s array of type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
            }
            else
            {
                printf("Parm: %s of%s type %s [line: %d]", attr->svalue, Stat, RetETYPE().c_str(), attr->linenum);
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
            opType = OpType(attr->tokenstr);
            if (opType != "assign" && opType != "ArrayAcc")
            {
                printf("Op: %s of type %s [line: %d]", attr->tokenstr, opType.c_str(), attr->linenum);
            }
            else
            {
                n = CheckType(GetChild(0), symTbl);
                printf("Op: %s of type %s [line: %d]", attr->tokenstr, n->RetETYPE().c_str(), attr->linenum);
            }
            break;
        case constantK:
            if (isArray == true)
            {
                printf("Const is array %s of type %s [line: %d]", StringVal().c_str(), RetETYPE().c_str(), attr->linenum);
            }
            else
            {
                printf("Const %s of type %s [line: %d]", StringVal().c_str(), RetETYPE().c_str(), attr->linenum);
            }
            break;
        case IdK:
            n = (treeNode *)symTbl->lookup(attr->tokenstr);
            printf("Id: %s of type %s [line: %d]", attr->tokenstr, n->RetETYPE().c_str(), attr->linenum);
            break;
        case AssingK:
            opType = OpType(attr->tokenstr);
            if (opType != "assign" && opType != "ArrayAcc")
            {
                printf("Assign: %s of type %s [line: %d]", attr->tokenstr, opType.c_str(), attr->linenum);
            }
            else
            {
                p = CheckType(GetChild(0), symTbl);
                n = (treeNode *)symTbl->lookup(p->token()->tokenstr);
                printf("Assign: %s of type %s [line: %d]", attr->tokenstr, n->RetETYPE().c_str(), attr->linenum);
            }
            break;
        case InitK:
            printf("Init: %s [line: %d]", attr->tokenstr, attr->linenum);
            break;
        case CallK:
            n = (treeNode *)symTbl->lookup(attr->tokenstr);
            printf("Call: %s of type %s [line: %d]", attr->tokenstr, n->RetETYPE().c_str(), attr->linenum);
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
            if ((nodeKind == DeclK && subkind.decl != FuncK) || (nodeKind != DeclK))
            {
                if (child[i]->nodeKind == StmtK && child[i]->subkind.stmt == CompoundK)
                {
                    symTbl->enter("CompundStmt");
                }
            }

            printf("\n");
            for (int j = 0; j < levels; j++)
            {
                printf(".   ");
            }

            printf("Child: %d  ", i);
            child[i]->printTree(levels + 1, 1, symTbl);
        }
    }
    if ((nodeKind == DeclK && subkind.decl == FuncK))
    {
        symTbl->leave();
    }

    if (sibling != NULL)
    {
        if (sibling->Kind() == StmtK && sibling->SKind() == CompoundK)
        {
            symTbl->enter("Compound Statement");
        }
        if (nodeKind == StmtK && subkind.stmt == CompoundK)
        {
            symTbl->leave();
        }

        printf("\n");
        for (int i = 1; i < levels; i++)
        {
            printf(".   ");
        }
        printf("Sibling: %d  ", siblingNum);
        sibling->printTree(levels, siblingNum + 1, symTbl);
    }
}

int treeNode::GetChildren(int c)
{
    int count = 0;
    treeNode *CurrentChild = child[c];
    while (CurrentChild != NULL)
    {
        count++;
        CurrentChild = CurrentChild->nextSibling();
    }
    return count;
}

std::string treeNode::StringVal()
{
    if (expType == Integer)
    {
        return std::to_string(attr->nvalue);
    }
    else if (expType == Char && isArray == true)
    {
        std::string Ret = (attr->svalue);
        Ret = "\"" + Ret + "\"";
        return Ret;
    }
    else if (expType == Char && isArray == false)
    {
        std::string Ret = &(attr->cvalue);
        Ret = "\'" + Ret + "\'";
        return Ret;
    }
    else if (expType == boolean && attr->nvalue == 0)
    {
        return "false";
    }
    else if (expType == boolean && attr->nvalue == 1)
    {
        return "true";
    }
    else
    {
        return "Something went wrong";
    }
}