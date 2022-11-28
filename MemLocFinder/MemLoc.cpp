#include "MemLoc.h"

int foffset = 0;
int goffset = 0;

// I might be able to do this in Semantic analaysis (and tbh that would be where id do it in a perfect world)
// But Semantic analysis is a mess so...
// TBH should have doe Semantic Analysis like this KEKW
void MemLocSet(treeNode *node, SymbolTable *symTbl)
{
    if (node == NULL)
    {
        return;
    }
    int oldfoffset;
    treeNode *DecNode;      // only need to use with ID
    treeNode *ParamsOrVars; // start of params in Funcs and Vars in Compound

    switch (node->Kind())
    {
    case DeclK:
        // put in symTbl
        symTbl->insert(node->token()->tokenstr, node);
        switch (node->DKind())
        {
        case VarK:
            MemLocSet(node->GetChild(0), symTbl);
            if (node->StaticIs() || node->GlobablIs())
            {
                if (node->ArrayIs() == true)
                {
                    node->SetLoc(goffset - 1);
                    goffset = goffset - node->GetSize();
                }
                else
                {
                    node->SetLoc(goffset);
                    goffset = goffset - node->GetSize();
                }
            }
            else
            {
                if (node->ArrayIs() == true)
                {
                    node->SetLoc(foffset - 1);
                    foffset = foffset - node->GetSize();
                }
                else
                {
                    node->SetLoc(foffset);
                    foffset = foffset - node->GetSize();
                }
            }
            break;
        case ParamK:
            MemLocSet(node->GetChild(0), symTbl);
            // printf("Current f offset: %d\n",foffset);
            node->SetLoc(foffset);
            //  printf("Current Node offset: %d\n", node->GetLoc());
            foffset = foffset - node->GetSize();
            // ((treeNode*) NULL)->GetLoc();
            break;
        case FuncK:
            ParamsOrVars = node->GetChild(0);
            if (ParamsOrVars != NULL)
            {
                node->SetSize(-(ParamsOrVars->SiblingSize() + 2));
            }
            else
            {
                node->SetSize(-2);
            }
            // node->SetSize(0); // size is completly wrong
            node->SetLoc(0); // Loc is right, idk why

            oldfoffset = foffset; //??? idk if this is what i want
            foffset = 0;
            foffset = -2; // loc = old frame pointer, loc-1 is addr of return point
                          // printf("New f offset: %d\n",foffset);
            symTbl->enter(node->token()->tokenstr);
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl); //-- Wrong
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            symTbl->leave();
            foffset = oldfoffset;
            break;
        default:
            break;
        }
        break;
    case StmtK:
        switch (node->SKind())
        {
        case CompoundK:
            ParamsOrVars = node->GetChild(0);
            if (ParamsOrVars != NULL)
            {
                node->SetSize(-(ParamsOrVars->SiblingSize()) + foffset);
            }
            else
            {
                node->SetSize(foffset);
            }
            // node->SetSize(foffset);
            //  node->SetSize(0); // size is completly wrong
            // node->SetSize(0); // Temp I guess LOL
            node->SetLoc(0); // Correct??

            oldfoffset = foffset; //??? idk if this is what i want
            // foffset = 0;
            symTbl->enter("Compound"); //--Oh Wrong for sure
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            symTbl->leave();
            foffset = oldfoffset;
            break;
        case ForK:
            ParamsOrVars = node->GetChild(0);
            if (ParamsOrVars != NULL)
            {
                node->SetSize(-(ParamsOrVars->SiblingSize()) + foffset);
            }
            else
            {
                node->SetSize(foffset);
            }
            oldfoffset = foffset; //??? idk if this is what i want
            // foffset = 0;
            symTbl->enter("For Loop"); //--Oh Wrong for sure
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            symTbl->leave();
            foffset = oldfoffset;
            break;
        // Other stmts dont have a Size/Loc, so set it to 0
        default:
            // node->SetSize(0); // (not) temp I guess
            // node->SetLoc(0);  // Correct??
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            break;
        }
        break;
    case ExpK:
        switch (node->EKind())
        {

        case constantK:
            if (node->ArrayIs() == true)
            {
                // node->BGlobal(true); ???
                node->SetLoc(goffset-1);
                goffset = goffset - node->GetSize();
            }
            break;
        case IdK:
            DecNode = (treeNode *)symTbl->lookup(node->token()->tokenstr);
            node->SetLoc(DecNode->GetLoc());
            node->SetSize(DecNode->GetSize());
            node->SetIDKind(DecNode->DKind());
            break;
        case OpK:
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            break;
        case AssingK:
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            break;
        case CallK:
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    // Now Do siblings:
    MemLocSet(node->nextSibling(), symTbl);
}