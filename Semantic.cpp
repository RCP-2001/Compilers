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
        // params *Should be init*
        InitSiblings(tree->GetChild(0)); // dont know if i should do it like this, but here we are

        //******
        symTbl->enter(TData->tokenstr);
        semanticAnalysis(symTbl, tree->GetChild(0));
        // Avoid following Compund Statement
        if (tree->GetChild(1) != NULL)
        {
            semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(0));
            semanticAnalysis(symTbl, tree->GetChild(1)->GetChild(1));
        }
        // find return statements and give them a type
        if (FindReturn(tree, tree->GetChild(1), symTbl) == false && tree->EType() != Void && (strcmp(tree->token()->tokenstr, "input") != 0 && strcmp(tree->token()->tokenstr, "inputb") != 0 && strcmp(tree->token()->tokenstr, "inputc") != 0))
        {
            printf("WARNING(%d): Expecting to return type %s but function '%s' has no return statement.\n", tree->token()->linenum, tree->RetETYPE().c_str(), tree->token()->tokenstr);
            numWarnings++;
        }

        symTbl->applyToAll(CheckForUse);
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());

        return;
        // printf("TEST TYPE BEAT %s \n\n\n", TData->tokenstr);
    }
    // params and variables
    else if (tree->Kind() == DeclK)
    {
        semanticAnalysis(symTbl, tree->GetChild(0));

        if (symTbl->insert(TData->tokenstr, tree) == false)
        {
            treeNode *n = (treeNode *)symTbl->lookup(TData->tokenstr);
            printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", TData->linenum, TData->tokenstr, n->token()->linenum);
            numErrors++;
        }
        // set init
        if (tree->GetChild(0) != NULL)
        {
            FindNonConstExp(tree, tree->GetChild(0));
            ///

            if (tree->GetChild(0)->EKind() == constantK && tree->EType() != tree->GetChild(0)->EType())
            {
                printf("ERROR(%d): Initializer for variable '%s' of type %s is of type %s\n", tree->token()->linenum, tree->token()->tokenstr, tree->RetETYPE().c_str(), tree->GetChild(0)->RetETYPE().c_str());
                numErrors++;
            }
            if (tree->ArrayIs() == true && tree->GetChild(0)->ArrayIs() != true)
            {
                printf("ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is an array and rhs is not an array.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
            else if (tree->ArrayIs() != true && tree->GetChild(0)->ArrayIs() == true)
            {
                printf("ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is not an array and rhs is an array.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }

            if (tree->GetChild(0)->EKind() == AssingK || tree->GetChild(0)->EKind() == OpK)
            {
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != tree->RetETYPE())
                {

                    if (opType == "ArrayAcc" || opType == "assign")
                    {
                        treeNode *LeftSym = CheckType(tree->GetChild(0), symTbl); // find Left most Symbol
                        treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                        if (LeftDec->EType() != tree->EType())
                        {
                            printf("ERROR(%d): Initializer for variable '%s' of type %s is of type %s\n", tree->token()->linenum, tree->token()->tokenstr, tree->RetETYPE().c_str(), LeftDec->RetETYPE().c_str());
                            numErrors++;
                        }
                    }
                    else
                    {
                        printf("ERROR(%d): Initializer for variable '%s' of type %s is of type %s\n", tree->token()->linenum, tree->token()->tokenstr, tree->RetETYPE().c_str(), opType.c_str());
                        numErrors++;
                    }
                }
            }

            if (tree->GetChild(0)->EKind() == CallK || tree->GetChild(0)->EKind() == IdK || strcmp(tree->GetChild(0)->token()->tokenstr, "?") == 0)
            {
                //   printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", tree->token()->linenum, tree->token()->tokenstr);
                //  numErrors++;
                // IDK how much this matters, but this is an error that comes up
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL && n->EType() != tree->EType())
                {
                    printf("ERROR(%d): Initializer for variable '%s' of type %s is of type %s\n", tree->token()->linenum, tree->token()->tokenstr, tree->RetETYPE().c_str(), n->RetETYPE().c_str());
                    numErrors++;
                }
            }

            tree->InitIs(true);
        }
        if (tree->StaticIs() == true)
        {
            tree->InitIs(true);
        }

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
        // Find Breaks and set their "is used" to true
        FindBreaks(tree->GetChild(2));
        //
        // tree->GetChild(0)->UsedIs(true);
        symTbl->enter("ForLoop");

        semanticAnalysis(symTbl, tree->GetChild(0));
        // set init to true for for loop vars
        tree->GetChild(0)->InitIs(true);
        semanticAnalysis(symTbl, tree->GetChild(1));

        // check if next stmt is compund stmt
        if (tree->GetChild(2) != NULL && tree->GetChild(2)->SKind() == CompoundK)
        {
            // skip new scope Compund Statement
            semanticAnalysis(symTbl, tree->GetChild(2)->GetChild(0));
            semanticAnalysis(symTbl, tree->GetChild(2)->GetChild(1));
        }
        else
        {
            semanticAnalysis(symTbl, tree->GetChild(2));
        }
        // symTbl->print(printTreeNode);
        // printf("\n\n\n");
        symTbl->applyToAll(CheckForUse);
        symTbl->leave();
        semanticAnalysis(symTbl, tree->nextSibling());
        return;
    }

    //******************
    // Everything above returns early (because reasons)

    // Break
    else if (tree->Kind() == StmtK && tree->SKind() == BreaK)
    {
        if (tree->UsedIs() == false)
        {
            printf("ERROR(%d): Cannot have a break statement outside of loop.\n", tree->token()->linenum);
            numErrors++;
        }
    }

    // Range Brothers out the roof we're not the same (He's Baby Keem)
    else if (tree->Kind() == StmtK && tree->SKind() == RangeK)
    {
        // Check Child 0
        // Const
        if (tree->GetChild(0)->EKind() == constantK && tree->GetChild(0)->EType() != Integer)
        {
            printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 1, tree->GetChild(0)->RetETYPE().c_str());
            numErrors++;
        }
        else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
        {
            std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
            if (opType != "int")
            {

                if (opType == "ArrayAcc" || opType == "assign")
                {
                    treeNode *LeftSym = CheckType(tree->GetChild(0), symTbl); // find Left most Symbol
                    treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                    if (LeftDec->EType() != Integer)
                    {
                        printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 1, LeftDec->RetETYPE().c_str());
                        numErrors++;
                    }
                }
                else
                {
                    printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 1, opType.c_str());
                    numErrors++;
                }
            }
        }
        else if (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK)
        {
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
            if (n != NULL && n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(0)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(0)->EKind() == IdK)))
            {
                printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 1, n->RetETYPE().c_str());
                numErrors++;
            }
            if (n != NULL && n->ArrayIs() == true)
            {
                printf("ERROR(%d): Cannot use array in position %d in range of for statement.\n", tree->token()->linenum, 1);
                numErrors++;
            }
        }

        // check Child 1
        if (tree->GetChild(1)->EKind() == constantK && tree->GetChild(1)->EType() != Integer)
        {
            printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 2, tree->GetChild(1)->RetETYPE().c_str());
            numErrors++;
        }
        else if (tree->GetChild(1)->EKind() == OpK || tree->GetChild(1)->EKind() == AssingK)
        {
            std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
            if (opType != "int")
            {
                if (opType == "ArrayAcc" || opType == "assign")
                {
                    treeNode *LeftSym = CheckType(tree->GetChild(1), symTbl); // find Left most Symbol
                    treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                    if (LeftDec->EType() != Integer)
                    {
                        printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 2, LeftDec->RetETYPE().c_str());
                        numErrors++;
                    }
                }
                else
                {
                    printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 2, opType.c_str());
                    numErrors++;
                }
            }
        }
        else if (tree->GetChild(1)->EKind() == IdK || tree->GetChild(1)->EKind() == CallK)
        {
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
            if (n != NULL && n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(1)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(1)->EKind() == IdK)))
            {
                printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 2, n->RetETYPE().c_str());
                numErrors++;
            }
            if (n != NULL && n->ArrayIs() == true)
            {
                printf("ERROR(%d): Cannot use array in position %d in range of for statement.\n", tree->token()->linenum, 2);
                numErrors++;
            }
        }
        // Check Child 2
        if (tree->GetChild(2) != NULL)
        {
            if (tree->GetChild(2)->EKind() == constantK && tree->GetChild(2)->EType() != Integer)
            {
                printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 3, tree->GetChild(2)->RetETYPE().c_str());
                numErrors++;
            }
            else if (tree->GetChild(2)->EKind() == OpK || tree->GetChild(2)->EKind() == AssingK)
            {
                std::string opType = OpType(tree->GetChild(2)->token()->tokenstr);
                if (opType != "int")
                {
                    if (opType == "ArrayAcc" || opType == "assign")
                    {
                        treeNode *LeftSym = CheckType(tree->GetChild(2), symTbl); // find Left most Symbol
                        treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                        if (LeftDec->EType() != Integer)
                        {
                            printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 3, LeftDec->RetETYPE().c_str());
                            numErrors++;
                        }
                    }
                    else
                    {

                        printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 3, opType.c_str());
                        numErrors++;
                    }
                }
            }
            else if (tree->GetChild(2)->EKind() == IdK || tree->GetChild(2)->EKind() == CallK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(2)->token()->tokenstr);
                if (n != NULL && n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(2)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(2)->EKind() == IdK)))
                {
                    printf("ERROR(%d): Expecting type int in position %d in range of for statement but got type %s.\n", tree->token()->linenum, 3, n->RetETYPE().c_str());
                    numErrors++;
                }
                if (n != NULL && n->ArrayIs() == true)
                {
                    printf("ERROR(%d): Cannot use array in position %d in range of for statement.\n", tree->token()->linenum, 3);
                    numErrors++;
                }
            }
        }
    }

    else if (tree->Kind() == StmtK && tree->SKind() == IfK)
    {
        if (tree->GetChild(0)->EKind() == constantK && tree->GetChild(0)->EType() != boolean)
        {
            printf("ERROR(%d): Expecting Boolean test condition in if statement but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->RetETYPE().c_str());
            numErrors++;
        }
        else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
        {
            std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
            if (opType != "bool")
            {
                if (opType == "ArrayAcc" || opType == "assign")
                {
                    treeNode *LeftSym = CheckType(tree->GetChild(0), symTbl); // find Left most Symbol
                    treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                    if (LeftDec->EType() != boolean)
                    {
                        printf("ERROR(%d): Expecting Boolean test condition in if statement but got type %s.\n", tree->token()->linenum, LeftDec->RetETYPE().c_str());
                        numErrors++;
                    }
                }
                else
                {
                    printf("ERROR(%d): Expecting Boolean test condition in if statement but got type %s.\n", tree->token()->linenum, opType.c_str());
                    numErrors++;
                }
            }
        }
        else if (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK)
        {
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
            if (n != NULL)
            {
                if (n->EType() != boolean)
                {
                    printf("ERROR(%d): Expecting Boolean test condition in if statement but got type %s.\n", tree->token()->linenum, n->RetETYPE().c_str());
                    numErrors++;
                }
                if (n->ArrayIs() == true)
                {
                    printf("ERROR(%d): Cannot use array as test condition in if statement.\n", tree->token()->linenum);
                    numErrors++;
                }
            }
        }
    }

    else if (tree->Kind() == StmtK && tree->SKind() == WhileK)
    {
        // Finding Breaks
        FindBreaks(tree->GetChild(1));

        if (tree->GetChild(0)->EKind() == constantK && tree->GetChild(0)->EType() != boolean)
        {
            printf("ERROR(%d): Expecting Boolean test condition in while statement but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->RetETYPE().c_str());
            numErrors++;
        }
        else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
        {
            std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
            if (opType != "bool")
            {
                printf("ERROR(%d): Expecting Boolean test condition in while statement but got type %s.\n", tree->token()->linenum, opType.c_str());
                numErrors++;
            }
        }
        else if (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK)
        {
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
            if (n != NULL)
            {
                if (n->EType() != boolean)
                {
                    printf("ERROR(%d): Expecting Boolean test condition in while statement but got type %s.\n", tree->token()->linenum, n->RetETYPE().c_str());
                    numErrors++;
                }
                if (n->ArrayIs() == true)
                {
                    printf("ERROR(%d): Cannot use array as test condition in while statement.\n", tree->token()->linenum);
                    numErrors++;
                }
            }
        }
    }

    //********************
    // return cool
    //
    else if (tree->Kind() == StmtK && tree->SKind() == ReturnK)
    {
        // Was going to do it this way, but now do it during Func Decleration
        // Well, techninclly after lol, Keeping for memes
        /*if (tree->GetChild(0) != NULL)
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
        }*/
    }
    // calls
    if (tree->Kind() == ExpK && tree->EKind() == CallK)
    {
        treeNode *n = (treeNode *)symTbl->lookup(tree->token()->tokenstr);
        if (n == NULL)
        {
            printf("ERROR(%d): Symbol '%s' is not declared.\n", tree->token()->linenum, tree->token()->tokenstr);
            numErrors++;
        }
        else
        {
            n->UsedIs(true);
            if (n->DKind() != FuncK)
            {
                printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
            else
            {
                if (n->GetChildren(0) > tree->GetChildren(0))
                {
                    printf("ERROR(%d): Too few parameters passed for function '%s' declared on line %d.\n", tree->token()->linenum, tree->token()->tokenstr, n->token()->linenum);
                    numErrors++;
                }
                else if (n->GetChildren(0) < tree->GetChildren(0))
                {
                    printf("ERROR(%d): Too many parameters passed for function '%s' declared on line %d.\n", tree->token()->linenum, tree->token()->tokenstr, n->token()->linenum);
                    numErrors++;
                }
            }
            ParamTypeCheck(n, tree, symTbl);
        }
        // fprintf(stderr, "n Child: %d, tree Child %d \n", n->GetChildren(0), tree->GetChildren(0));

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
            else if (p->InitIs() == false)
            {
                printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, p->token()->tokenstr);
                p->InitIs(true); // dont need to be annoying about uninit vars
                numWarnings++;
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
            // Refactor and check
            // might need right child be looked at first
            bool sideIsArray = false; // To prevent duplicate  error messages
            // IDK and CallK
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->InitIs() == false && tree->GetChild(1)->EKind() == IdK && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }

                    if (n->EType() != boolean && ((n->DKind() == FuncK && tree->GetChild(0)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(0)->EKind() == IdK)))
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE().c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                        sideIsArray = true;
                    }
                    // Variable has been init (it it wasnt already)
                    // n->InitIs(true);
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK || tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n != NULL)
                {

                    if (n->InitIs() == false && tree->GetChild(1)->EKind() == IdK && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }
                    if (n->EType() != boolean && ((n->DKind() == FuncK && tree->GetChild(1)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(1)->EKind() == IdK)))
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", n->RetETYPE().c_str());
                        numErrors++;
                    }
                    if ((n->ArrayIs() == true) && sideIsArray == false)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }

                    // check init
                }
            }
            // Ops
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

                    printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", opType.c_str());
                    numErrors++;
                }
            }
            // Const
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", tree->GetChild(0)->RetETYPE().c_str());
                    numErrors++;
                }
            }
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                if (tree->GetChild(1)->EType() != boolean)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, "bool", tree->GetChild(1)->RetETYPE().c_str());
                    numErrors++;
                }
            }
        }

        //********************************
        // Equal Type (Including assingment)
        if (strcmp(tree->token()->tokenstr, "==") == 0 || strcmp(tree->token()->tokenstr, "!=") == 0 || strcmp(tree->token()->tokenstr, "<") == 0 || strcmp(tree->token()->tokenstr, "<=") == 0 || strcmp(tree->token()->tokenstr, ">") == 0 || strcmp(tree->token()->tokenstr, ">=") == 0 || strcmp(tree->token()->tokenstr, "=") == 0)
        {
            // CHILD 1***************************
            //  check if child 1 is ID
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == IdK || tree->GetChild(1)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n != NULL /*&& n->EType() != Void*/)
                {
                   if ((n->DKind() == FuncK && tree->GetChild(1)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(1)->EKind() == IdK))
                    {
                        op2 = n->EType();
                    }

                    op2A = n->ArrayIs();
                    if (n->InitIs() == false && tree->GetChild(1)->EKind() == IdK && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
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
                    FindUnintVariables(tree->GetChild(1), symTbl);
                }
                else if (opType == "int")
                {
                    op2 = Integer;
                    FindUnintVariables(tree->GetChild(1), symTbl);
                }
                else if ((opType == "ArrayAcc") || (opType == "assign"))
                {
                    // need to make recusive
                    // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(1)->GetChild(0)->token()->tokenstr);
                    // bool TypeReturnIsArray = false; // only really applies to ArrayAcc
                    treeNode *p = CheckType(tree->GetChild(1), symTbl); // find Left most Symbol
                    bool a = FindAssingOp(tree->GetChild(1));           // check if sides are innit
                    bool b = FindArrayAccessorOp(tree->GetChild(1));
                    // bool a = FindAssingOp
                    treeNode *n = (treeNode *)symTbl->lookup(p->token()->tokenstr); // loopup left most symbol
                    // fprintf(stderr, "n Token: %s, n Arra arra value %d\n", n->token()->tokenstr, n->ArrayIs());
                    //
                    if (n != NULL)
                    {
                        op2 = n->EType();
                        // really need to make recusive
                        // makes this acutally wrong
                        if (b == true)
                        {
                            op2A = false;
                            if (n->InitIs() == false && n->DKind() != FuncK && a == false)
                            {
                                printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                                n->InitIs(true); // dont need to be annoying about uninit vars
                                numWarnings++;
                            }
                        }
                        else
                        {
                            op2A = n->ArrayIs();
                        }
                    }
                }
            }
            // check if child 1 is Const
            if (tree->GetChild(1)->Kind() == ExpK && tree->GetChild(1)->EKind() == constantK)
            {
                op2 = tree->GetChild(1)->EType();
                op2A = tree->GetChild(1)->ArrayIs();
            }

            // CHILD 0****************************8
            //  check if child 0 is ID
            //  Might need another check for assinment operators
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK || tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);

                if (n != NULL && n->EType() != Void)
                {
                    if ((n->DKind() == FuncK && tree->GetChild(0)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(0)->EKind() == IdK))
                    {
                        op1 = n->EType();
                    }
                    op1A = n->ArrayIs();
                    // set init if assign
                    if (strcmp(tree->token()->tokenstr, "=") == 0)
                    {
                        n->InitIs(true);
                    }
                    // otherwise, yell
                    else if (n->InitIs() == false && tree->GetChild(1)->EKind() == IdK && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }
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
                    FindUnintVariables(tree->GetChild(0), symTbl);
                }
                else if (opType == "int")
                {
                    op1 = Integer;
                    FindUnintVariables(tree->GetChild(0), symTbl);
                }
                else if ((opType == "ArrayAcc") || (opType == "assign"))
                {
                    // may need to make recusive????
                    // treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->GetChild(0)->token()->tokenstr);
                    treeNode *p = CheckType(tree->GetChild(0), symTbl);
                    treeNode *n = (treeNode *)symTbl->lookup(p->token()->tokenstr);
                    bool b = FindArrayAccessorOp(tree->GetChild(0));
                    // fprintf(stderr, "n Token: %s, n Arra arra value %d\n", n->token()->tokenstr, n->ArrayIs());

                    if (n != NULL)
                    {
                        op1 = n->EType();
                        if (b == true)
                        {
                            op1A = false;
                            if (strcmp(tree->token()->tokenstr, "=") == 0)
                            {
                                n->InitIs(true);
                            }
                            else if (n->InitIs() == false && n->DKind() != FuncK)
                            {
                                printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                                n->InitIs(true); // dont need to be annoying about uninit vars
                                numWarnings++;
                            }
                        }
                        else
                        {
                            op1A = n->ArrayIs();
                        }
                        // n->InitIs(true);
                    }
                }
            }

            // check if child 0 is Const
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                op1 = tree->GetChild(0)->EType();
                op1A = tree->GetChild(0)->ArrayIs();
            }

            // final print

            if (op1 != op2)
            {
                if (op1 != UndefinedType && op2 != UndefinedType)
                {
                    printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(op1).c_str(), RETYPE(op2).c_str());
                    numErrors++;
                }
            }
            if (op1A == true && op2A == false)
            {
                printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
            if (op1A == false && op2A == true)
            {
                printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
        }
        // int, int ******************************
        if ((strcmp(tree->token()->tokenstr, "+=") == 0) || (strcmp(tree->token()->tokenstr, "-=") == 0) || (strcmp(tree->token()->tokenstr, "*=") == 0) || (strcmp(tree->token()->tokenstr, "/=") == 0) || (strcmp(tree->token()->tokenstr, "+") == 0) || (strcmp(tree->token()->tokenstr, "-") == 0) || (strcmp(tree->token()->tokenstr, "*") == 0) || (strcmp(tree->token()->tokenstr, "/") == 0) || (strcmp(tree->token()->tokenstr, "%") == 0))
        {
            bool sideIsArray = false; // To prevent duplicate  error messages

            // Left Hand Side************************************8
            // const
            if (tree->GetChild(0)->Kind() == ExpK && tree->GetChild(0)->EKind() == constantK)
            {
                if (tree->GetChild(0)->EType() != Integer)
                {
                    printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(tree->GetChild(0)->EType()).c_str());
                    numErrors++;
                }
            }
            // id
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == IdK) || (tree->GetChild(0)->EKind() == CallK))
            {
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        sideIsArray = true;
                        numErrors++;
                    }
                    if (n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(0)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(0)->EKind() == IdK)))
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }
                    // assing ops make init true
                    if (strcmp(tree->token()->tokenstr, "+=") == 0 || strcmp(tree->token()->tokenstr, "-=") == 0 || strcmp(tree->token()->tokenstr, "*=") == 0 || strcmp(tree->token()->tokenstr, "/=") == 0)
                    {
                        n->InitIs(true);
                    }
                }
            }
            // op
            if (tree->GetChild(0)->Kind() == ExpK && (tree->GetChild(0)->EKind() == OpK) || (tree->GetChild(0)->EKind() == AssingK))
            {
                FindUnintVariables(tree->GetChild(0), symTbl);      // Need????
                treeNode *p = CheckType(tree->GetChild(0), symTbl); // finds type of left most
                treeNode *n = (treeNode *)symTbl->lookup(p->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "int")
                {

                    if (n != NULL && n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), n->RetETYPE().c_str());
                        numErrors++;
                    }
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
                    if (n->InitIs() == false && tree->GetChild(1)->EKind() == IdK && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars

                        numWarnings++;
                    }
                    if (n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(1)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(1)->EKind() == IdK)))
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
            // op
            if (tree->GetChild(1)->Kind() == ExpK && (tree->GetChild(1)->EKind() == OpK) || (tree->GetChild(1)->EKind() == AssingK))
            {
                FindUnintVariables(tree->GetChild(1), symTbl); // need???

                treeNode *p = CheckType(tree->GetChild(1), symTbl); // finds type of left most
                treeNode *n = (treeNode *)symTbl->lookup(p->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (opType != "int")
                {
                    if (opType == "ArrayAcc" && n != NULL && n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), n->RetETYPE().c_str());
                        numErrors++;
                    }
                    // printf("OpType: %s\n\n\n", opType.c_str());
                    else if (n != NULL && n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), opType.c_str());
                        numErrors++;
                    }
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
                    if (n->InitIs() == false && n->ArrayIs() == false && (tree->GetChild(0)->EKind() == IdK) && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }
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
            // ops
            else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
            {
                FindUnintVariables(tree->GetChild(0), symTbl); // need??

                treeNode *p = CheckType(tree->GetChild(0), symTbl); // finds type of left most
                treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "int")
                {
                    if (n != NULL && n->EType() != Integer)
                    {
                        printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(Integer).c_str(), opType.c_str());
                        numErrors++;
                    }
                }
            }
        }
        // Unary Not
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
                    if (n->InitIs() == false && (tree->GetChild(0)->EKind() == IdK) && n->DKind() != FuncK)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }
                    if (n->EType() != boolean)
                    {
                        printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(boolean).c_str(), RETYPE(n->EType()).c_str());
                        numErrors++;
                    }

                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): The operation '%s' does not work with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                }
            }
            else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
            {
                FindUnintVariables(tree->GetChild(0), symTbl); // need???

                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                if (opType != "bool")
                {
                    printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", tree->token()->linenum, tree->token()->tokenstr, RETYPE(boolean).c_str(), opType.c_str());
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
                    if (n->InitIs() == false && n->StaticIs() == false)
                    {
                        printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true); // dont need to be annoying about uninit vars
                        numWarnings++;
                    }

                    // else should get handeled???
                }
            }
            else if (tree->GetChild(0)->EKind() == CallK)
            {
                printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                numErrors++;
            }
            // check for operators that return left hand side
            // not perfect, may need to put in a recusive func
            else if (tree->GetChild(0)->EKind() == OpK || tree->GetChild(0)->EKind() == AssingK)
            {
                std::string opType = OpType(tree->GetChild(0)->token()->tokenstr);
                bool ArraAcc = FindArrayAccessorOp(tree->GetChild(0));

                if (/*opType == "ArrayAcc" ||*/ opType == "assign") // Array Acc might not be right here tbh
                {
                    treeNode *LeftSym = CheckType(tree->GetChild(0), symTbl); // find Left most Symbol
                    treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                    if (LeftDec != NULL && LeftDec->ArrayIs() == false)
                    {
                        printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                        numErrors++;
                    }
                }
                else if (tree->GetChild(0)->EKind() != AssingK)
                {
                    printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                    numErrors++;
                }
                else if (ArraAcc == true)
                {
                    // printf("EMEMEMMEMEM\n\n");
                    printf("ERROR(%d): The operation '%s' only works with arrays.\n", tree->token()->linenum, tree->token()->tokenstr);
                    numErrors++;
                }
            }
        }
        //***********
        // Array Index op
        if (strcmp(tree->token()->tokenstr, "[") == 0)
        {
            // Check left for array
            treeNode *n = (treeNode *)symTbl->lookup(tree->GetChild(0)->token()->tokenstr);
            if (n != NULL)
            {
                /*if (n->InitIs() == false && (tree->GetChild(0)->EKind() == IdK) && n->DKind() != FuncK)
                {
                    printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", tree->token()->linenum, n->token()->tokenstr);
                    n->InitIs(true); // dont need to be annoying about uninit vars
                    numWarnings++;
                }*/
                if (n->ArrayIs() != true || n->DKind() == FuncK)
                {
                    printf("ERROR(%d): Cannot index nonarray '%s'.\n", tree->token()->linenum, tree->GetChild(0)->token()->svalue);
                    numErrors++;
                }
                // n->InitIs(true);
            }
            else
            {
                // idk if this is really what i want
                //  but i think i need it to match the output? (either that, or something else is wrong haha)
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
            else if (((tree->GetChild(1)->EKind()) == OpK) || ((tree->GetChild(1)->EKind()) == AssingK))
            {
                // fprintf(stderr, "Tokenstr  %s \n", tree->token()->tokenstr);
                // if(tree->token()->linenum == 44){
                //  fprintf(stderr, "TESTING!!\n");
                //}
                // std::string opType = OpType(tree->GetChild(1)->token()->tokenstr);
                if (OpType(tree->GetChild(1)->token()->tokenstr) != "int")
                {
                    treeNode *n = CheckType(tree->GetChild(1), symTbl);
                    if ((n->EType() != Integer))
                    {
                        printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->token()->tokenstr, RETYPE(n->EType()).c_str());
                        numErrors++;
                        n->InitIs(true);
                    }
                }
            }
            // if right is ID or Func
            else if ((tree->GetChild(1)->EKind() == IdK) || (tree->GetChild(1)->EKind() == CallK))
            {
                // fprintf(stderr, "Tokenstr of child1 %s \n", tree->GetChild(1)->token()->tokenstr);

                n = (treeNode *)symTbl->lookup(tree->GetChild(1)->token()->tokenstr);
                if (n != NULL)
                {
                    // Some of this is too prevent cascading errors
                    if (n->EType() != Integer && ((n->DKind() == FuncK && tree->GetChild(1)->EKind() == CallK) || (n->DKind() != FuncK && tree->GetChild(1)->EKind() == IdK)))
                    {
                        // printf("test\n");
                        // printf("TEST TEST TEST %s \n", RETYPE(n->EType()).c_str());
                        printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->token()->tokenstr, RETYPE(n->EType()).c_str());
                        n->InitIs(true);
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): Array index is the unindexed array '%s'.\n", tree->token()->linenum, n->token()->tokenstr);
                        n->InitIs(true);
                        numErrors++;
                    }
                    // fpr
                }
                // printf("check pls\n");

                // intf(stderr, "Out of2");
            }
            else if ((tree->GetChild(1)->EKind() == constantK && tree->GetChild(1)->EType() != Integer))
            {
                printf("ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", tree->token()->linenum, tree->GetChild(0)->token()->tokenstr, RETYPE(tree->GetChild(1)->EType()).c_str());
                numErrors++;
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
    else if (strcmp(Token, "chsign") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "sizeof") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "--") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "++") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "?") == 0)
    {
        return "int";
    }
    else if (strcmp(Token, "not") == 0)
    {
        return "bool";
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
        if (n->DKind() == VarK)
        {
            printf("WARNING(%d): The variable '%s' seems not to be used.\n", n->token()->linenum, n->token()->tokenstr);
            numWarnings++;
        }
        else if (n->DKind() == ParamK)
        {
            printf("WARNING(%d): The parameter '%s' seems not to be used.\n", n->token()->linenum, n->token()->tokenstr);
            numWarnings++;
        }
        else if (n->DKind() == FuncK && strcmp(n->token()->tokenstr, "main") != 0)
        {
            printf("WARNING(%d): The function '%s' seems not to be used.\n", n->token()->linenum, n->token()->tokenstr);
            numWarnings++;
        }
    }
}

treeNode *CheckType(treeNode *n, SymbolTable *symTbl)
{
    if (n->Kind() == ExpK && (n->EKind() == OpK || n->EKind() == AssingK))
    {
        std::string opType = OpType(n->token()->tokenstr);
        if (opType == "ArrayAcc" || opType == "assign")
        {
            return CheckType(n->GetChild(0), symTbl);
        }

        return n->GetChild(0);
    }
    else if (n->Kind() == ExpK && (n->EKind() == IdK || n->EKind() == CallK))
    {
        treeNode *x = (treeNode *)symTbl->lookup(n->token()->tokenstr);
        if (x != NULL)
        {
            return x;
        }
        else
        {
            return n;
        }
    }
    else if (n->Kind() == ExpK && (n->EKind() == constantK))
    {
        return n;
    }
    // probably shouldnt get here???
    return n;
}

void InitSiblings(treeNode *n)
{
    if (n != NULL)
    {
        n->InitIs(true);
        InitSiblings(n->nextSibling());
    }
    return;
}

bool FindArrayAccessorOp(treeNode *n)
{
    if (n == NULL)
    {
        return false;
    }
    if (strcmp(n->token()->tokenstr, "[") == 0)
    {
        return true;
    }
    else
    {
        return FindArrayAccessorOp(n->GetChild(0));
    }
}

bool FindAssingOp(treeNode *n)
{
    if (n == NULL)
    {
        return false;
    }
    if (strcmp(n->token()->tokenstr, "=") == 0)
    {
        return true;
    }
    else
    {
        return FindAssingOp(n->GetChild(1));
    }
}

void ParamTypeCheck(treeNode *n, treeNode *c, SymbolTable *symTbl)
{
    int param = 1;
    treeNode *FuncChild = n->GetChild(0);
    treeNode *CallChild = c->GetChild(0);

    while (FuncChild != NULL && CallChild != NULL)
    {
        treeNode *p = (treeNode *)symTbl->lookup(CallChild->token()->tokenstr);

        if (FuncChild->EType() != CallChild->EType())
        {
            if ((p != NULL) && CallChild->Kind() == ExpK && (CallChild->EKind() == CallK || CallChild->EKind() == IdK))
            {
                if ((p->EType() != FuncChild->EType()))
                {
                    printf("ERROR(%d): Expecting type %s in parameter %i of call to '%s' declared on line %d but got type %s.\n", c->token()->linenum, FuncChild->RetETYPE().c_str(), param, n->token()->tokenstr, n->token()->linenum, p->RetETYPE().c_str());
                    numErrors++;
                }
                // Array Test
                if (p->ArrayIs() != true && FuncChild->ArrayIs() == true)
                {
                    printf("ERROR(%d): Expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                    numErrors++;
                    // printf("p token:%s, n token %s \n", p->token()->tokenstr, n->token()->tokenstr);
                }
                else if (p->ArrayIs() == true && FuncChild->ArrayIs() != true)
                {
                    printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                    numErrors++;
                    // printf("p token:%s, n token %s \n", p->token()->tokenstr, n->token()->tokenstr);
                }
            }
            else if (CallChild->Kind() == ExpK && (CallChild->EKind() == OpK || CallChild->EKind() == AssingK))
            {
                std::string opType = OpType(CallChild->token()->tokenstr);
                bool HasArrayAccOp = FindArrayAccessorOp(CallChild);
                if (opType != FuncChild->RetETYPE())
                {
                    if (opType == "ArrayAcc" || opType == "assign")
                    {
                        treeNode *LeftSym = CheckType(CallChild, symTbl); // find Left most Symbol
                        treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                        if (LeftDec != NULL && LeftDec->EType() != FuncChild->EType())
                        {
                            printf("ERROR(%d): Expecting type %s in parameter %i of call to '%s' declared on line %d but got type %s.\n", c->token()->linenum, FuncChild->RetETYPE().c_str(), param, n->token()->tokenstr, n->token()->linenum, LeftSym->RetETYPE().c_str());
                            // printf("MEMEMEMEMEM\n");
                            numErrors++;
                        }
                        if (LeftDec != NULL && LeftDec->ArrayIs() != true && FuncChild->ArrayIs() == true)
                        {
                            printf("ERROR(%d): Expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                            numErrors++;
                            // printf("p token:%s, n token %s \n", p->token()->tokenstr, n->token()->tokenstr);
                        }
                        else if (LeftDec != NULL && LeftDec->ArrayIs() == true && FuncChild->ArrayIs() != true && opType != "ArrayAcc" && HasArrayAccOp == false)
                        {
                            printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                            numErrors++;
                            // printf("p token:%s, n token %s \n", p->token()->tokenstr, n->token()->tokenstr);
                        }
                    }
                    else
                    {
                        printf("ERROR(%d): Expecting type %s in parameter %i of call to '%s' declared on line %d but got type %s.\n", c->token()->linenum, FuncChild->RetETYPE().c_str(), param, n->token()->tokenstr, n->token()->linenum, opType.c_str());
                        numErrors++;
                    }
                }
                if (FuncChild->ArrayIs() == true && opType != "assign")
                {
                    printf("ERROR(%d): Expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                    // printf("MEMEMEMEMEMME\n\n\n\n\n");
                    numErrors++;
                }
                else if (FuncChild->ArrayIs() != true && opType == "assign")
                {
                    treeNode *LeftSym = CheckType(CallChild, symTbl); // find Left most Symbol
                    treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                    if (LeftDec->ArrayIs() == true && HasArrayAccOp == false)
                    {
                        printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                        numErrors++;
                    }
                }
            }
            else if ((p == NULL) && (CallChild->EKind() == CallK || CallChild->EKind() == IdK))
            {
                // symbol not declared, will get handedled laterbasi
            }
            else
            {
                // printf("EMEMMEMEM\n\n\n");
                printf("ERROR(%d): Expecting type %s in parameter %i of call to '%s' declared on line %d but got type %s.\n", c->token()->linenum, FuncChild->RetETYPE().c_str(), param, n->token()->tokenstr, n->token()->linenum, CallChild->RetETYPE().c_str());
                numErrors++;
            }
        }
        // Test for Constant Arrays
        if (CallChild->EKind() == constantK && CallChild->ArrayIs() == true)
        {
            if (FuncChild->ArrayIs() != true)
            {
                printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                numErrors++;
            }
        }
        else if (CallChild->EKind() == constantK && CallChild->ArrayIs() != true)
        {
            if (FuncChild->ArrayIs() == true)
            {
                printf("ERROR(%d): Expecting array in parameter %i of call to '%s' declared on line %d.\n", c->token()->linenum, param, n->token()->tokenstr, n->token()->linenum);
                numErrors++;
            }
        }
        // printf("Func: %s, Call: %s \n", FuncChild->token()->tokenstr, CallChild->token()->tokenstr);

        FuncChild = FuncChild->nextSibling();
        CallChild = CallChild->nextSibling();
        param++;
    }
}

bool FindReturn(treeNode *Func, treeNode *test, SymbolTable *symTbl)
{
    // has return been found?
    bool retVal = false;
    if (test == NULL)
    {
        // printf("returning\n");
        return retVal;
    }
    // printf("Test Token %s \n", test->token()->tokenstr );
    if (test->Kind() == StmtK && test->SKind() == ReturnK)
    {
        retVal = true;
        // printf("Is Return Statment\n");
        if (test->GetChild(0) == NULL && Func->EType() != Void)
        {
            printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but return has no value.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum, Func->RetETYPE().c_str());
            numErrors++;
        }
        if (test->GetChild(0) != NULL)
        {
            // Constantk
            if (test->GetChild(0)->EKind() == constantK)
            {
                if (Func->EType() == Void)
                {
                    printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has a value.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum);
                    numErrors++;
                }
                else if (test->GetChild(0)->EType() != Func->EType())
                {
                    printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum, Func->RetETYPE().c_str(), test->GetChild(0)->RetETYPE().c_str());
                    numErrors++;
                }
                if (test->GetChild(0)->ArrayIs() == true)
                {
                    printf("ERROR(%d): Cannot return an array.\n", test->token()->linenum);
                    numErrors++;
                }
            }
            // Calls and ID
            if (test->GetChild(0)->EKind() == CallK || test->GetChild(0)->EKind() == IdK)
            {
                treeNode *n = (treeNode *)symTbl->lookup(test->GetChild(0)->token()->tokenstr);
                if (n != NULL)
                {
                    if (Func->EType() == Void)
                    {
                        printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has a value.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum);
                        numErrors++;
                    }
                    else if (n->EType() != Func->EType())
                    {
                        printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum, Func->RetETYPE().c_str(), n->RetETYPE().c_str());
                        numErrors++;
                    }
                    if (n->ArrayIs() == true)
                    {
                        printf("ERROR(%d): Cannot return an array.\n", test->token()->linenum);
                        numErrors++;
                    }
                }
            }
            // Ops
            if (test->GetChild(0)->EKind() == OpK || test->GetChild(0)->EKind() == AssingK)
            {
                std::string opType = OpType(test->GetChild(0)->token()->tokenstr);
                if (Func->EType() == Void)
                {
                    printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has a value.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum);
                    numErrors++;
                }
                else if (opType != Func->RetETYPE())
                {
                    if (opType == "ArrayAcc" || opType == "assign")
                    {
                        treeNode *LeftSym = CheckType(test->GetChild(0), symTbl); // find Left most Symbol
                        treeNode *LeftDec = (treeNode *)symTbl->lookup(LeftSym->token()->tokenstr);
                        if (LeftDec != NULL)
                        {
                            if (LeftDec->EType() != Func->EType())
                            {
                                printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum, Func->RetETYPE().c_str(), LeftDec->RetETYPE().c_str());
                                numErrors++;
                            }
                            if (LeftDec->ArrayIs() == true && opType != "ArrayAcc")
                            {
                                printf("ERROR(%d): Cannot return an array.\n", test->token()->linenum);
                                numErrors++;
                            }
                        }
                    }
                    else
                    {
                        printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", test->token()->linenum, Func->token()->tokenstr, Func->token()->linenum, Func->RetETYPE().c_str(), opType.c_str());
                        numErrors++;
                    }
                }
            }
        }
        // test->EType(Func->EType());
    }

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        retVal = (FindReturn(Func, test->GetChild(i), symTbl) || retVal);
    }
    retVal = (FindReturn(Func, test->nextSibling(), symTbl) || retVal);
    return retVal;
}

void FindBreaks(treeNode *test)
{
    if (test == NULL)
    {
        return;
    }
    if (test->Kind() == StmtK && test->SKind() == BreaK)
    {
        test->UsedIs(true);
    }
    FindBreaks(test->GetChild(0));
    FindBreaks(test->GetChild(1));
    FindBreaks(test->GetChild(2));
    FindBreaks(test->nextSibling());
}

void FindUnintVariables(treeNode *Test, SymbolTable *symTbl)
{
    if (Test == NULL)
    {
        return;
    }
    if (Test->EKind() == IdK)
    {
        treeNode *n = (treeNode *)symTbl->lookup(Test->token()->tokenstr);
        if (n != NULL && n->InitIs() != true)
        {
            printf("WARNING(%d): Variable '%s' may be uninitialized when used here.\n", Test->token()->linenum, n->token()->tokenstr);
            numWarnings++;
            n->InitIs(true);
        }
    }
    FindUnintVariables(Test->GetChild(0), symTbl);
    FindUnintVariables(Test->GetChild(1), symTbl);
    FindUnintVariables(Test->GetChild(2), symTbl);
}

bool FindNonConstExp(treeNode *ID, treeNode *Test)
{
    if (Test == NULL)
    {
        return false;
    }
    if (Test->EKind() == IdK || Test->EKind() == CallK)
    {
        // printf("MEMEMEM\n");

        printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", Test->token()->linenum, ID->token()->tokenstr);
        numErrors++;
        return true;
    }
    if (strcmp(Test->token()->tokenstr, "?") == 0)
    {
        // printf("MEMEMEM\n");
        printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", Test->token()->linenum, ID->token()->tokenstr);
        numErrors++;
        return true;
    }
    if (FindNonConstExp(ID, Test->GetChild(0)) == true)
    {
        return true;
    }
    if (FindNonConstExp(ID, Test->GetChild(1)) == true)
    {
        return true;
    }
    if (FindNonConstExp(ID, Test->GetChild(2)) == true)
    {
        return true;
    }
    return false;
}