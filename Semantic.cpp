#include "Semantic.h"
#include <string.h>
#include <string>

extern int numErrors;
extern int numWarnings;

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
            numErrors++;
        }
        symTbl->enter(TData->tokenstr);
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(1));
        symTbl->applyToAll(CheckForUse);
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
            numErrors++;
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
        symTbl->applyToAll(CheckForUse);
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    // for loops
    else if (tree->Kind() == StmtK && tree->SKind() == ForK)
    {
        // idk this might be wrong KEKW
        symTbl->enter("ForLoop");
        semanticAnalysis(symTbl, tree->GetChild(0));
        semanticAnalysis(symTbl, tree->GetChild(1));
        semanticAnalysis(symTbl, tree->GetChild(2));
        symTbl->applyToAll(CheckForUse);
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }
    // return cool
    else if (tree->Kind() == StmtK && tree->SKind() == ReturnK)
    {
        if (tree->GetChild(0) != NULL)
        {
            if (tree->GetChild(0)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): Cannot return an array.\n", tree->token()->linenum);
                        numErrors++;
                    }
                }
            }
        }
    }
    //******************
    // Everything above returns early (because reasons)

    //********************
    // calls
    if (tree->Kind() == ExpK && tree->EKind() == CallK)
    {
        treeNode *n = (treeNode *)symTbl->lookup(tree->token()->tokenstr);
        if (n == NULL)
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", tree->token()->linenum, tree->token()->tokenstr);
            numErrors++;
        }
        else if (n->DKind() != FuncK)
        {
            printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", tree->token()->linenum, tree->token()->tokenstr);
            numErrors++;
        }

        // printf("CallK \n");
        // printTreeNode(tree);
        // printf("\n\n\n\n\n\n");
    }
    // Refrences to variables
    else if (tree->Kind() == ExpK && tree->EKind() == IdK)
    {
        treeNode *p = (treeNode *)symTbl->lookup(TData->tokenstr);
        if (p != NULL)
        {
            if (p->DKind() == FuncK)
            {
                printf("ERROR(%d): Cannot use function '%s' as a variable.\n", tree->token()->linenum, p->token()->tokenstr);
                numErrors++;
            }
            p->UsedIs(true);
        }
        else
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", TData->linenum, TData->tokenstr);
            numErrors++;
        }
    }

    //**********
    // OPERATORS THIS IS GOING TO BE PAINFUL SADGE
    else if (tree->Kind() == ExpK && (tree->EKind() == OpK || tree->EKind() == AssingK))
    {
        ExpType op1 = UndefinedType;
        ExpType op2 = UndefinedType;
        bool op1A = false;
        bool op2A = false;

        // Bool, Bool Operators
        if (strcmp(tree->token()->tokenstr, "and") == 0 || strcmp(tree->token()->tokenstr, "or") == 0)
        {
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n == NULL)
                {
                    // printf("??? X %s \n\n\n", tree->token()->tokenstr);
                    // get handelded later
                }

                else if (n->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE().c_str());
                    numErrors++;
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK || tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n == NULL)
                {
                    // printf("???\n\n\n");
                    // Get handedled later
                }

                else if (n->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE());
                    numErrors++;
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == OpK)
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "bool" != 0)
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", opType.c_str());
                    numErrors++;
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == OpK)
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (opType != "bool")
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", opType.c_str());
                    numErrors++;
                }
            }
        }
        //********************************
        // Equal Type (Including assingment)
        if (strcmp(tree->token()->tokenstr, "==") == 0 || strcmp(tree->token()->tokenstr, "!=") == 0 || strcmp(tree->token()->tokenstr, "<") == 0 || strcmp(tree->token()->tokenstr, "<=") == 0 || strcmp(tree->token()->tokenstr, ">") == 0 || strcmp(tree->token()->tokenstr, ">=") == 0 || strcmp(tree->token()->tokenstr, "=") == 0)
        {
            // check if child 0 is ID
            // Might need another check for assinment operators
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);

                if (n == NULL)
                {
                    // printf("??? XX1X %s \n\n\n", tree->token()->tokenstr);
                    // fprintf(stderr, "just checking things out\n");
                    // fprintf(stderr, "line: %d token %s \n", tree->token()->linenum, tree->token()->tokenstr);
                    /// if (tree->token()->linenum == 54)
                    //{
                    //     fprintf(stderr, "Line 54\n");
                    //  }
                }
                else
                {
                    op1 = n->EType();
                    op1A = n->ArrayIs();
                }
            }
            // check if child 1 is ID
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK || tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n == NULL)
                {
                    // printf("??? %s \n\n\n", tree->token()->tokenstr);
                    // fprintf(stderr, "just checking things out\n");
                }
                else
                {
                    op2 = n->EType();
                    op2A = n->ArrayIs();
                }
            }
            // check if child 0 is Ops
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK))
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType == "bool")
                {
                    op1 = boolean;
                }
                else if (opType == "int")
                {
                    op1 = Integer;
                }
                else if ((opType == "ArrayAcc") || (opType == "assign"))
                {
                    // may need to make recusive????
                    treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->GetChild(0)->token()->tokenstr);
                    if (n == NULL)
                    {
                        // fprintf(stderr, "Token str %s\n", tree->token()->tokenstr);
                        printf("???\n");
                    }
                    else
                    {
                        op1 = n->EType();
                        op1A = n->ArrayIs();
                    }
                }
            }
            // check if child 1 is Ops
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == OpK || tree->GetChild(1)->EKind() == AssingK))
            {
                // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (opType == "bool")
                {
                    op2 = boolean;
                }
                else if (opType == "int")
                {
                    op2 = Integer;
                }
                else if ((opType == "ArrayAcc") || (opType == "assign"))
                {
                    // need to make recusive
                    treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->GetChild(0)->token()->tokenstr);
                    if (n == NULL)
                    {
                        fprintf(stderr, "Token str %s\n", tree->token()->tokenstr);

                        printf("???\n");
                    }
                    else
                    {
                        op2 = n->EType();
                        op2A = n->ArrayIs();
                    }
                }
            }
            // check if child 0 is Const
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                op1 = tree->GetChild(0)->EType();
                op1A = tree->GetChild(0)->ArrayIs();
            }
            // check if child 1 is Const
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                op2 = tree->GetChild(1)->EType();
                op1A = tree->GetChild(1)->ArrayIs();
            }

            // final print

            if (op1 != op2)
            {
                if (op1 != UndefinedType && op2 != UndefinedType)
                {
                    printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(op1).c_str(), RETYPE(op2).c_str());
                    numErrors++;
                }
                else if (op1A == true && op2A == false)
                {
                    printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", tree->token()->linenum);
                    numErrors++;
                }
                else if (op1A == false && op2A == true)
                {
                    printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", tree->token()->linenum);
                    numErrors++;
                }
            }
        }
        // int, int ******************************
        if ((strcmp(tree->token()->tokenstr, "+=") == 0) || (strcmp(tree->token()->tokenstr, "-=") == 0) || (strcmp(tree->token()->tokenstr, "*=") == 0) || (strcmp(tree->token()->tokenstr, "/=") == 0) || (strcmp(tree->token()->tokenstr, "+") == 0) || (strcmp(tree->token()->tokenstr, "-") == 0) || (strcmp(tree->token()->tokenstr, "*") == 0) || (strcmp(tree->token()->tokenstr, "/") == 0) || (strcmp(tree->token()->tokenstr, "%") == 0))
        {
            bool sideIsArray = false; // To prevent duplicate  error messages
            // Left Hand Side************************************8
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(0)->EType()).c_str());
                    numErrors++;
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK) || (tree->GetChild(0)->EKind() == CallK))
            {
                // possible segmentation fault KEKW
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        sideIsArray = true;
                        numErrors++;
                    }
                }
            }
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == OpK) || (tree->GetChild(0)->EKind() == AssingK))
            {

                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType == "int")
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(0)->EType()).c_str());
                    numErrors++;
                }
            }
            //***********Right Hand Side*********************
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                if (tree->GetChild(1)->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(1)->EType()).c_str());
                    numErrors++;
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK) || (tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true && sideIsArray == false)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == OpK) || (tree->GetChild(1)->EKind() == AssingK))
            {

                std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (opType != "int")
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(1)->EType()).c_str());
                    numErrors++;
                }
            }
        }
        //****
        // Unary Operators
        if (strcmp(tree->token()->tokenstr, "--") == 0 || strcmp(tree->token()->tokenstr, "++") == 0 || strcmp(tree->token()->tokenstr, "chsign") == 0 || strcmp(tree->token()->tokenstr, "?") == 0)
        {
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != Integer)
                {
                    printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(0)->EType()).c_str());
                    numErrors++;
                }
            }
            else if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK) || ExpK && (tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->EType() != Integer)
                    {
                        printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                }
            }
            else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == OpK)
            {
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "int")
                {
                    printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), opType.c_str());
                    numErrors++;
                }
            }
        }
        else if (strcmp(tree->token()->tokenstr, "not") == 0)
        {
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != boolean)
                {
                    printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(boolean).c_str(), RETYPE(tree->GetChild(0)->EType()).c_str());
                    numErrors++;
                }
            }
            else if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK) || ExpK && (tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->EType() != boolean)
                    {
                        printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(boolean).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                }
            }
            else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
            {
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "bool")
                {
                    printf("ERROR(%d): Unary '%s' requires an operand of %s but was given %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), opType.c_str());
                    numErrors++;
                }
            }
        }
        // size of unary op
        else if (strcmp(tree->token()->tokenstr, "sizeof") == 0)
        {
            // check for string const
            // might need to do more?
            if (tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->ArrayIs() != true)
                {
                    printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                    numErrors++;
                }
            }
            // check if ID is array
            else if (tree->GetChild(0)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->ArrayIs() != true)
                    {
                        printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                    // else should get handeled???
                }
            }
            // check for operators that return left hand side
            // not perfect, may need to put in a recusive func
            else if (((tree->GetChild(0)->EKind() == OpK) || (tree->GetChild(0)->EKind() == OpK)) && ((tree->GetChild(0)->token()->tokenstr == "=") || (tree->GetChild(0)->token()->tokenstr == "[")))
            {
                if (tree->GetChild(0)->GetChild(0)->EKind() == constantK)
                {
                    if (tree->GetChild(0)->GetChild(0)->ArrayIs() != true)
                    {
                        printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                }
                else if (tree->GetChild(0)->GetChild(0)->EKind() == IdK)
                {
                    treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->GetChild(0)->token()->tokenstr);
                    if (n != NULL)
                    {
                        if (n->ArrayIs() != true)
                        {
                            printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                            numErrors++;
                        }
                        // else should get handeled???
                    }
                }
            }
            // check for exps that cant be an array at all
            else if ((tree->GetChild(0)->EKind() == OpK) || (tree->GetChild(0)->EKind() == AssingK) || (tree->GetChild(0)->EKind() == CallK))
            {
                printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
        }
        //***********
        // Array Index op
        if (strcmp(tree->token()->tokenstr, "[") == 0)
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
                numErrors++;
            }
            // check left for operation that ret
            //  fprintf(stderr, "Out of1 %d \n", tree->token()->linenum);

            // Check Right for int
            if (tree->GetChild(1)->token()->tokenstr == NULL)
            {
                // fprintf(stderr, "how tf did this happen???");
                // exit(0);
            }

            // if right child is Operation
            if (((tree->GetChild(1)->EKind()) == OpK) || ((tree->GetChild(1)->EKind()) == AssingK))
            {
                // fprintf(stderr, "Tokenstr  %s \n", tree->token()->tokenstr);
                // if(tree->token()->linenum == 44){
                //  fprintf(stderr, "TESTING!!\n");
                //}
                std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if ((opType != "int"))
                {
                    printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->token()->tokenstr, opType.c_str());
                    numErrors++;
                }
            }
            // if right is ID or Func
            else if ((tree->GetChild(1)->EKind() == IdK) || (tree->GetChild(1)->EKind() == CallK))
            {
                // fprintf(stderr, "Tokenstr of child1 %s \n", tree->GetChild(1)->token()->tokenstr);

                n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->EType() != Integer)
                    {
                        // printf("test\n");
                        // printf("TEST TEST TEST %s \n", RETYPE(n->EType()).c_str());
                        printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->token()->tokenstr, RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): Array index is the unindexed array '%s'.\n", tree->token()->linenum, n->token()->tokenstr);
                        numErrors++;
                    }
                    // fpr
                }
                // printf("check pls\n");

                // intf(stderr, "Out of2");
            }
        }
        //**
        //*******************************************************
    }
    //************

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
}

void printTreeNode(void *node)
{
    treeNode *tNode = (treeNode *)node;
    printf("TS: %s, numVale %d, cval NahLOL, sval Later ", tNode->token()->tokenstr, tNode->token()->nvalue, tNode->token()->cvalue, tNode->token()->svalue);
}

std::string OpType(char *Token)
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

void CheckForUse(std::string s, void *p)
{
    treeNode *n = (treeNode *)p;
    if (n->UsedIs() == false)
    {
        printf("WARNING(%d): The variable '%s' seems not to be used.\n", n->token()->linenum, n->token()->tokenstr);
        numWarnings++;
    }
}