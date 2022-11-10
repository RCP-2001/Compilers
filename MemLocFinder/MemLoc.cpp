#include "MemLoc.h"

// I might be able to do this in Semantic analaysis (and tbh that would be where id do it in a perfect world)
// But Semantic analysis is a mess so...
// TBH should have doe Semantic Analysis like this KEKW
void MemLocSet(treeNode *node, SymbolTable *symTbl)
{
    switch (node->Kind())
    {
    case DeclK:
        // put in symTbl
        symTbl->insert(node->token()->tokenstr, node);
        switch (node->DKind())
        {
        case VarK:
            if (node->StaticIs() || node->GlobablIs())
            {
                node->SetLoc(goffset + node->GetSize());
                goffset = goffset+node->GetSize();
            }
            else{
                node->SetLoc(foffset + node->GetSize());
                foffset = foffset + node->GetSize();
            }
            break;
        case ParamK:
            node->SetLoc(foffset + node->GetSize());
            foffset = foffset + node->GetSize();
        case FuncK:
            int oldfoffset = foffset; //??? idk if this is what i want
            foffset = 0;
            symTbl->enter(node->token()->tokenstr);
            MemLocSet(node->GetChild(0), symTbl);
            MemLocSet(node->GetChild(1), symTbl);
            MemLocSet(node->GetChild(2), symTbl); // This could be incorrect lol
            break;
        default:
            break;
        }
        break; 
    case StmtK:
        switch (node->SKind())
        {
        case CompoundK:
            XXX ON A KILLSTREAK;
            break;
        
        default:
            break;
        }
        break;
    case ExpK:
        switch (node->EKind())
        {
        case OpK:
            // IDK
            break;
        case AssingK:
            // hmmmm
            break;
        case constantK:
            // String const need something for sure. not sure about other tho KEKW
            break;
        case IdK:
            treeNode* DecNode = (treeNode*) symTbl->lookup(node->token()->tokenstr);
            node->SetLoc(DecNode->GetLoc());
            node->SetSize(DecNode->GetSize());
        case CallK:
            //IDK
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}