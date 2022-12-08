#include "CodeGen.h"

static int currentAddr = 39;
static int TOFF = 0;
static int MainAddr = 0;

ListNode::~ListNode()
{
    if (next != NULL)
    {
        delete next;
    }
}

ListNode::ListNode(treeNode *node)
{
    TokenStr = node->token()->tokenstr;
    AssociatedNode = node;
    GenCodeFromTree();
}

void ListNode::GenCodeFromTree()
{
    printf("NODE\n");
    switch (AssociatedNode->Kind())
    {
    case DeclK:
        switch (AssociatedNode->DKind())
        {
        case FuncK:
            Code = "* ** ** ** ** ** ** ** ** ** ** ** ** \n";
            Code = Code + "* FUNCTION " + AssociatedNode->token()->tokenstr + "\n";
            // TOFFSET???
            Code = Code + std::to_string(currentAddr) + " : ST  3,-1(1)     Store Return addr\n";
            currentAddr++;
            TOFF = TOFF + AssociatedNode->GetSize();
            Code = Code + "* TOFF = " + std::to_string(TOFF) + "\n";
            break;
        case ParamK:

            break;

        default:
            break;
        }
        break;

    case StmtK:
        switch (AssociatedNode->SKind())
        {
        case CompoundK:
            Code = "* COMPOUND STATEMENT \n";
            printf("Adding Code form Compound Statement\n");
            TOFF = AssociatedNode->GetSize();
            Code = Code + "*TOFF = " + std::to_string(TOFF) + "\n";
            break;

        default:
            break;
        }
        break;
    case ExpK:
        switch (AssociatedNode->EKind())
        {

        case CallK:
            Code = Code + std::to_string(currentAddr) + " : ST " + std::to_string(FRAMEPOINTER) + ",-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)\n";
            currentAddr++;

            // Pass by Ref!!!
            LoadConstants(AssociatedNode->GetChild(0), Code);
            Code = Code + std::to_string(currentAddr++) + " : LDA " + std::to_string(FRAMEPOINTER) + ",-2(1)     Ghost frame becomes new active frame\n";
            Code = Code + std::to_string(currentAddr++) + " : LDA " + std::to_string(AC1) + ",1(7)     return addr in ac\n";
            Code = Code + std::to_string(currentAddr++) + " : JMP " + std::to_string(PC) + ",-40(7)     Call func (IDK how to do this properly tbh\n";
            Code = Code + std::to_string(currentAddr++) + " : LDA " + std::to_string(AC1) + ",0(2)    Save Result in AC \n";

            break;
        case constantK:
            Code = Code + "* CONST NODE\n";
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
}

void ListNode::AddNode(ListNode *newNode)
{
    if (newNode == NULL)
    {
        return;
    }
    if (next == NULL)
    {
        next = newNode;
        return;
    }
    next->AddNode(newNode);
}

ListNode *Linearize(treeNode *TreeNode)
{
    if (TreeNode == NULL)
    {
        return NULL;
    }
    ListNode *Current = new ListNode(TreeNode);
    ListNode *Child0 = Linearize(TreeNode->GetChild(0));
    ListNode *Child1 = Linearize(TreeNode->GetChild(1));
    ListNode *Child2 = Linearize(TreeNode->GetChild(2));
    Current->AddNode(Child0);
    Current->AddNode(Child1);
    Current->AddNode(Child2);

    // Current-> Code = (std::string) TreeNode->token()->tokenstr + "\n";

    ListNode *Sibling = Linearize(TreeNode->nextSibling());
    Current->AddNode(Sibling);
    return Current;
}

void ListNode::GenerateCode(std::ofstream &Fileout)
{
    printf("Adding to page???\n");
    Fileout << Code;
    if (next != NULL)
    {
        next->GenerateCode(Fileout);
    }
    // if(AssociatedNode->Kind() == DeclK && AssociatedNode()->
}

void GenerateIOLib(std::ofstream &Fileout)
{
    Fileout << "* ** ** ** ** ** ** ** ** ** ** ** **" << std::endl;
    Fileout << "*FUNCTION input" << std::endl;
    Fileout << "1 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "2 : IN 2, 2, 2 Grab int input " << std::endl;
    Fileout << "3 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "4 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "5 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION input" << std::endl;
    Fileout << "*";
    Fileout << "************************* " << std::endl;
    Fileout << "*FUNCTION output " << std::endl;
    Fileout << "6 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "7 : LD 3, -2(1)Load parameter " << std::endl;
    Fileout << "8 : OUT 3, 3, 3 Output integer " << std::endl;
    Fileout << "9 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "10 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "11 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION output " << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "************************* " << std::endl;
    Fileout << "*FUNCTION inputb " << std::endl;
    Fileout << "12 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "13 : INB 2, 2, 2 Grab bool input" << std::endl;
    Fileout << "14 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "15 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "16 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION inputb " << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "*************************" << std::endl;
    Fileout << "*FUNCTION outputb " << std::endl;
    Fileout << "17 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "18 : LD 3, -2(1)Load parameter " << std::endl;
    Fileout << "19 : OUTB 3, 3, 3 Output bool " << std::endl;
    Fileout << "20 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "21 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "22 : JMP 7, 0(3)Return " << std::endl;
    Fileout << "*END FUNCTION outputb" << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "*************************" << std::endl;
    Fileout << "*FUNCTION inputc " << std::endl;
    Fileout << "23 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "24 : INC 2, 2, 2 Grab char input " << std::endl;
    Fileout << "25 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "26 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "27 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION inputc" << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "*************************" << std::endl;
    Fileout << "*FUNCTION outputc " << std::endl;
    Fileout << "28 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "29 : LD 3, -2(1)Load parameter " << std::endl;
    Fileout << "30 : OUTC 3, 3, 3 Output char " << std::endl;
    Fileout << "31 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "32 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "33 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION outputc" << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "*************************" << std::endl;
    Fileout << "*FUNCTION outnl " << std::endl;
    Fileout << "34 : ST 3, -1(1)Store return address" << std::endl;
    Fileout << "35 : OUTNL 3, 3, 3 Output a newline" << std::endl;
    Fileout << "36 : LD 3, -1(1)Load return address" << std::endl;
    Fileout << "37 : LD 1, 0(1)Adjust fp" << std::endl;
    Fileout << "38 : JMP 7, 0(3)Return" << std::endl;
    Fileout << "*END FUNCTION outnl " << std::endl;
    Fileout << "* " << std::endl;
    Fileout << "*************************" << std::endl;
    currentAddr = 39;
}

void LoadConstants(treeNode *CurrentNode, std::string &Code)
{
    if (CurrentNode == NULL)
    {
        return;
    }

    Code = Code + "*LOADING CALL PARAMS\n";
    if (CurrentNode->Kind() != ExpK)
    {
        // Should never get here
        Code = Code + "*ERRR: Not Exp??? \n";
        return;
    }
    switch (CurrentNode->EKind())
    {
    case constantK:
        Code = Code + "* CONST\n";
        switch (CurrentNode->EType())
        {
        case Integer:
            Code = Code + std::to_string(currentAddr) + " : LDC " + std::to_string(AC1) + "," + std::to_string(CurrentNode->token()->nvalue) + "(0)   Load Integer Constant \n";
            currentAddr++;
            Code = Code + std::to_string(currentAddr) + " : ST " + std::to_string(AC1) + "," + std::to_string(TOFF) + "(1)   \n";
            currentAddr++;

            break;
        case Char:
            if (CurrentNode->ArrayIs() == false)
            {
                Code = Code + std::to_string(currentAddr) + " : LDC " + std::to_string(AC1) + "," + std::to_string(CurrentNode->token()->cvalue) + "(0)   Load Char Constant \n";
                currentAddr++;
                Code = Code + std::to_string(currentAddr) + " : ST " + std::to_string(AC1) + "," + std::to_string(TOFF) + "(1)   \n";
                currentAddr++;
            }
            else
            {
                Code = Code + "Im Sad \n";
            }
            break;
        case boolean:
            Code = Code + std::to_string(currentAddr) + " : LDC " + std::to_string(AC1) + "," + std::to_string(CurrentNode->token()->nvalue) + "(0)   Load Integer Constant \n";
            currentAddr++;
            Code = Code + std::to_string(currentAddr) + " : ST " + std::to_string(AC1) + "," + std::to_string(TOFF) + "(1)   \n";
            currentAddr++;
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
    LoadConstants(CurrentNode->nextSibling(), Code);
}

void Init(std::ofstream &Fileout)
{
    Fileout << "*INIT \n";
    Fileout << "0 : JMP 7," << currentAddr - 1 << "(7)     Jmp to init \n";
    Fileout << currentAddr++ << " : LDA 1,0(0)  set frist frame\n";
    Fileout << currentAddr++ << " : ST 1,0(1)   Store old fp (point to self?)\n";
    Fileout << "* GLOBLS + STATICS (idk how to do this KEKW)\n";
    Fileout << currentAddr++ << " : LDA 3,1(7)  return addr in ac? \n";
    Fileout << currentAddr++ << " : JMP 7,-10(7)   Jump to main\n";
    Fileout << currentAddr++ << " : HALT 0,0,0 DONE\n";
}

void GenerateCodeTree(treeNode *Node, std::ofstream &Fileout, bool PushParam)
{
    if (Node == NULL)
    {
        return;
    }

    switch (Node->Kind())
    {
    case DeclK:
        switch (Node->DKind())
        {
        case FuncK:
            Fileout << "* ** ** ** ** ** ** ** ** ** ** ** ** \n";
            Fileout << "* FUNC " << Node->token()->tokenstr << std::endl;
            TOFF = Node->GetSize();
            Fileout << "* TOFF = " << TOFF << std::endl;

            Fileout << currentAddr++ << " : ST  " << AC1 << ",-1"
                    << "(" << FRAMEPOINTER << ")"
                    << " Store Ret Addr" << std::endl;

            // Generate Code in Children
            GenerateCodeTree(Node->GetChild(0), Fileout);
            GenerateCodeTree(Node->GetChild(1), Fileout);

            // Standard End
            Fileout << "* add Standard end in case of no return \n";
            Fileout << currentAddr++ << " : LDC " << RETURN << ",0"
                    << "(0)"
                    << "   Set Ret val to 0" << std::endl;
            Fileout << currentAddr++ << " : LD " << AC1 << ",-1"
                    << "(" << FRAMEPOINTER << ")"
                    << " Load Return addr" << std::endl;
            Fileout << currentAddr++ << " : LD " << FRAMEPOINTER << ",0"
                    << "(" << FRAMEPOINTER << ")"
                    << "   Adjust Frame Pointer " << std::endl;
            Fileout << currentAddr++ << " : JMP " << PC << ",0 "
                    << "(" << AC1 << ")"
                    << "  Ret" << std::endl;

            Fileout << "* END OF FUNC " << Node->token()->tokenstr << std::endl;

            break;

        default:
            break;
        }
        break;
    case StmtK:
        switch (Node->SKind())
        {
        case CompoundK:
            Fileout << "* COMPOUND" << std::endl;
            TOFF = Node->GetSize();
            Fileout << "* TOFF = " << TOFF << std::endl;

            GenerateCodeTree(Node->GetChild(0), Fileout);
            GenerateCodeTree(Node->GetChild(1), Fileout);

            Fileout << "* End of Compound " << std::endl;

            break;

        default:
            break;
        }

        break;
    case ExpK:
        switch (Node->EKind())
        {
        case constantK:
            Fileout << "* CONST" << std::endl;
            // Load into AC1 (Might need to make a few diffrent ones?)
            switch (Node->EType())
            {
            case Integer:
                Fileout << currentAddr++ << " : "
                        << "LDC " << AC1 << "," << Node->token()->nvalue << "(0)"
                        << "Load Integer Const" << std::endl;
                if (PushParam == true)
                {
                    Fileout << currentAddr++ << " : "
                            << "ST " << AC1 << "," << TOFF << "(" << FRAMEPOINTER << ")"
                            << "Push Param" << std::endl;
                }
                break;
            case Char:
                break;
            case boolean:
                break;

            default:
                break;
            }
            break;
        case CallK:
            Fileout << "* CALL output" << std::endl;
            Fileout << currentAddr++ << " : "
                    << "ST " << FRAMEPOINTER << "," << TOFF << "(" << FRAMEPOINTER << ")"
                    << " FP in ghost frame for output" << std::endl;
            TOFF--;
            Fileout << "* TOFF =" << TOFF << std::endl;
            GenerateCodeTree(Node->GetChild(0), Fileout, true);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    GenerateCodeTree(Node->nextSibling(), Fileout, PushParam);
}