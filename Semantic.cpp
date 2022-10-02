#include "Semantic.h"
#include "string.h"
int testGlobal = 0;
void semanticAnalysis(SymbolTable *symTbl, treeNode *tree)
{
    if (tree == NULL)
    {
        return;
    }

    TokenData *TData = tree->token();

    // Functions
    if (tree->Kind() == DeclK && tree->DKind() == FuncK)
    {
        if (symTbl->insert(TData->tokenstr, tree) == false)
        {
            treeNode *n = (treeNode *)symTbl->lookup(TData->tokenstr);
            printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", TData->linenum, TData->tokenstr, n->token()->linenum);
        }
        symTbl->enter(TData->tokenstr);
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());

        return;
        // printf("TEST TYPE BEAT %s \n\n\n", TData->tokenstr);
    }
    // params and variables
    else if (tree->Kind() == DeclK)
    {
        if (symTbl->insert(TData->tokenstr, tree) == false)
        {
            treeNode *n = (treeNode *)symTbl->lookup(TData->tokenstr);
            printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", TData->linenum, TData->tokenstr, n->token()->linenum);
        }

        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        semanticAnalysis(symTbl, tree->GetChild(2));
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    // Compund Statements
    else if (tree->Kind() == StmtK && tree->SKind() == CompoundK)
    {
        symTbl->enter("CompundStatement");
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    else if (tree->Kind() == StmtK && tree->SKind() == ForK)
    {
        // idk this might be wrong KEKW
        symTbl->enter("ForLoop");
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    //******************

    //********************
    else if (tree->Kind() == ExpK && tree->EKind() == CallK)
    {
        treeNode *n = (treeNode *)symTbl->lookup(tree->token()->tokenstr);
        if (n == NULL)
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", tree->token()->linenum, tree->token()->tokenstr);
        }
        else if (n->DKind() != FuncK)
        {
            printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", tree->token()->linenum, tree->token()->tokenstr);
        }

        // printf("CallK \n");
        // printTreeNode(tree);
        // printf("\n\n\n\n\n\n");
    }
    //**********
    // OPERATORS THIS IS GOING TO BE PAINFUL SADGE
    else if (tree->Kind() == ExpK && (tree->EKind() == OpK || tree->EKind() == AssingK))
    {
        ExpType op1;
        ExpType op2;

        // Bool, Bool Operators
        if (strcmp(tree->token()->tokenstr, "and") == 0 || strcmp(tree->token()->tokenstr, "or") == 0)
        {
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n == NULL)
                {
                    printf("??? X %s \n\n\n", tree->token()->tokenstr);
                }
                else if (n->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE());
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n == NULL)
                {
                    printf("???\n\n\n");
                }
                else if (n->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but rhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE());
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == OpK)
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                const char *opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (strcmp(opType, "bool") != 0)
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", opType);
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == OpK)
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                const char *opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (strcmp(opType, "bool") != 0)
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", opType);
                }
            }
        }
        //********************************
        // Equal Type (Including assingment)
        if (strcmp(tree->token()->tokenstr, "==") == 0 || strcmp(tree->token()->tokenstr, "!=") == 0 || strcmp(tree->token()->tokenstr, "<") == 0 || strcmp(tree->token()->tokenstr, "<=") == 0 || strcmp(tree->token()->tokenstr, ">") == 0 || strcmp(tree->token()->tokenstr, ">=") == 0 || strcmp(tree->token()->tokenstr, "=") == 0)
        {
            // check if child 0 is ID
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n == NULL)
                {
                    // printf("??? XX1X %s \n\n\n", tree->token()->tokenstr);
                }
                else
                {
                    op1 = n->EType();
                }
            }
            // check if child 1 is ID
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n == NULL)
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                }
                else
                {
                    op2 = n->EType();
                }
            }
            // check if child 0 is Ops
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK))
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                const char *opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (strcmp(opType, "bool") == 0)
                {
                    op1 = boolean;
                }
                else if (strcmp(opType, "int") == 0)
                {
                    op1 = Integer;
                }
                else if ((strcmp(opType, "ArrayAcc") == 0) || (strcmp(opType, "assign") == 0))
                {
                    treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->GetChild(0)->token()->tokenstr);
                    if (n == NULL)
                    {
                        printf("???\n");
                    }
                    else
                    {
                        op1 = n->EType();
                    }
                }
            }
            // check if child 1 is Ops
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == OpK || tree->GetChild(1)->EKind() == AssingK))
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                const char *opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (strcmp(opType, "bool") == 0)
                {
                    op2 = boolean;
                }
                else if (strcmp(opType, "int") == 0)
                {
                    op2 = Integer;
                }
                else if ((strcmp(opType, "ArrayAcc") == 0) || (strcmp(opType, "assign") == 0))
                {
                    treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->GetChild(0)->token()->tokenstr);
                    if (n == NULL)
                    {
                        printf("???\n");
                    }
                    else
                    {
                        op2 = n->EType();
                    }
                }
            }
            // check if child 0 is Const
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                op1 = tree->GetChild(0)->EType();
            }
            // check if child 1 is Const
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                op2 = tree->GetChild(1)->EType();
            }

            // final print
            if (op1 != op2)
            {
                printf("ERROR(%d): '%s' requires operands of the same type but lhs is %s and rhs is %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(op1), RETYPE(op2));
            }
        }
        // int, int ******************************
        if ((strcmp(tree->token()->tokenstr, "+=") == 0) || (strcmp(tree->token()->tokenstr, "-=") == 0) || (strcmp(tree->token()->tokenstr, "*=") == 0) || (strcmp(tree->token()->tokenstr, "/=") == 0) || (strcmp(tree->token()->tokenstr, "+") == 0) || (strcmp(tree->token()->tokenstr, "-") == 0) || (strcmp(tree->token()->tokenstr, "*") == 0) || (strcmp(tree->token()->tokenstr, "/") == 0) || (strcmp(tree->token()->tokenstr, "%") == 0))
        {
            // Left Hand Side************************************8
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(0)->EType()));
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK) || (tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(n->EType()));
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == OpK) || (tree->GetChild(0)->EKind() == AssingK))
            {

                const char *opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (strcmp(opType, "int") != 0)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(0)->EType()));
                }
            }
            //***********Right Hand Side*********************
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                if (tree->GetChild(1)->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(1)->EType()));
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK) || (tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(n->EType()));
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == OpK) || (tree->GetChild(1)->EKind() == AssingK))
            {

                const char *opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (strcmp(opType, "int") != 1)
                {
                    printf("ERROR(%d): '%s' requires operands of %s but lhs is of %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(1)->EType()));
                }
            }
        }
        //****
        // Unary Operators
        if (strcmp(tree->token()->tokenstr, "--") == 0 || strcmp(tree->token()->tokenstr, "++") == 0 || strcmp(tree->token()->tokenstr, "chsign") == 0 || strcmp(tree->token()->tokenstr, "?") == 0)
        {
            if (tree->GetChild(0)->EType() != Integer)
            {
                printf("ERROR(%d): Unary '%s' requires an operand of %s but was given %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(0)->EType()));
            }
        }
        else if (strcmp(tree->token()->tokenstr, "not") == 0)
        {
            if (tree->GetChild(0)->EType() != boolean)
            {
                printf("ERROR(%d): Unary '%s' requires an operand of %s but was given %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer), RETYPE(tree->GetChild(0)->EType()));
            }
        }
        else if (strcmp(tree->token()->tokenstr, "sizeof") == 0)
        {
            if (tree->GetChild(0)->ArrayIs() != true)
            {
                printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
            }
        }
        //***********
        // Array Index op
        if (strcmp(tree->token()->tokenstr, "["))
        {
            // Check left for array
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
            if (n == NULL)
            {
                // should get taken care of later
            }
            else if (n->ArrayIs() != true)
            {
                printf("ERROR(%d): Cannot index nonarray '%s'.\n", tree->token()->linenum, tree->GetChild(0)->token()->svalue);
            }
            // Check Right for int
            if ((tree->GetChild(1)->EKind() == OpK) || (tree->GetChild(1)->EKind() == AssingK))
            {
                const char *opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (strcmp(opType, "int") != 0)
                {
                    printf("ERROR(%d): Array '%s' should be indexed by type int but got %s.\n", tree->token()->linenum, opType);
                }
            }
            else if ((tree->GetChild(1)->EKind() == IdK) || (tree->GetChild(1)->EKind() == CallK))
            {
                n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n == NULL)
                {
                    // Should get handled later?
                }
                else if (n->EType() != Integer)
                {
                    printf("ERROR(%d): Array '%s' should be indexed by type int but got %s.\n", tree->token()->linenum, RETYPE(n->EType()));
                }
            }
        }
        //**
        //*******************************************************
    }
    //************

    // Refrences to variables
    else if (tree->Kind() == ExpK && tree->EKind() == IdK)
    {
        void *p = symTbl->lookup(TData->tokenstr);
        if (p == NULL)
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", TData->linenum, TData->tokenstr);
        }
    }

    //  symTbl->print( printTreeNode );

    // symTbl->enter("sub 1 ");
    semanticAnalysis(symTbl, tree->GetChild(0));
    // symTbl->leave();

    // symTbl->enter("sub 2 ");
    semanticAnalysis(symTbl, tree->GetChild(1));
    // symTbl->leave();

    // symTbl->enter("sub 3 ");
    semanticAnalysis(symTbl, tree->GetChild(2));
    // symTbl->leave();
    // symTbl->leave();

    semanticAnalysis(symTbl, tree->nextSibling());

    //  symTbl->print( printTreeNode );
}

void printTreeNode(void *node)
{
    treeNode *tNode = (treeNode *)node;
    printf("TS: %s, numVale %d, cval %c, sval %s ", tNode->token()->tokenstr, tNode->token()->nvalue, tNode->token()->cvalue, tNode->token()->svalue);
}

const char *OpType(char *Token)
{
    if (strcmp(Token, "and") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "or") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "==") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "!=") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "<") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "<=") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, ">") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, ">=") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, ">=") == 0)
    {
        return "bool";
    }
    else if (strcmp(Token, "+") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "-") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "*") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "/") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "%") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "[") == 0)
    {
        return "ArrayAcc";
    }
    else if (strcmp(Token, "+=") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "-=") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "*=") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "/=") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "=") == 0)
    {
        return "assign";
    }
    else
    {
        return "IDK";
    }
}