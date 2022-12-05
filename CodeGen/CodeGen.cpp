#include "CodeGen.h"

static int currentAddr = 39;
static int TOFF = 0;

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
    case ExpK:
        switch (AssociatedNode->EKind())
        {
        case CompoundK:
            Code = Code + "* COMPOUND STATEMENT \n";
            break;
        case CallK:
            Code = Code + std::to_string(currentAddr) + " : ST 1,-2(1)   Store fp in ghost Frame output? (IDK what that means tbh)\n";
            currentAddr++;

            // Pass by Ref!!!
            LoadConstants(AssociatedNode->GetChild(0), Code);
            Code = Code + std::to_string(currentAddr++) + " : LDA 1,-2(1)     Ghost frame becomes new active frame\n";
            Code = Code + std::to_string(currentAddr++) + " : LDA 3,1(7)     return addr in ac\n";
            Code = Code + std::to_string(currentAddr++) + " : JMP 7,-40(7)     Call func (IDK how to do this properly tbh\n";
            Code = Code + std::to_string(currentAddr++) + " : LDA 3,0(2)    Save Result in AC \n";

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
    Fileout << Code;
    if (next != NULL)
    {
        next->GenerateCode(Fileout);
    }
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
            Code = Code + std::to_string(currentAddr) + " : LDC " + "3," + std::to_string(CurrentNode->token()->nvalue) + "(0)   Load Integer Constant \n";
            currentAddr++;
            Code = Code + std::to_string(currentAddr) + " : ST " + "3," + std::to_string(TOFF) + "(1)   \n";
            currentAddr++;

            break;
        case Char:
            if (CurrentNode->ArrayIs() == false)
            {
                Code = Code + std::to_string(currentAddr) + " : LDC " + "3," + std::to_string(CurrentNode->token()->cvalue) + "(0)   Load Char Constant \n";
                currentAddr++;
                Code = Code + std::to_string(currentAddr) + " : ST " + "3," + std::to_string(TOFF) + "(1)   \n";
                currentAddr++;
            }
            else
            {
                Code = Code + "Im Sad \n";
            }
            break;
        case boolean:
            Code = Code + std::to_string(currentAddr) + " : LDC " + "3," + std::to_string(CurrentNode->token()->nvalue) + "(0)   Load Integer Constant \n";
            currentAddr++;
            Code = Code + std::to_string(currentAddr) + " : ST " + "3," + std::to_string(TOFF) + "(1)   \n";
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

void Init(std::ofstream Fileout){
    Fileout << "*INIT \n";
    Fileout << "0 : JMP 7,75(7)     Jmp to init \n";
    Fileout << currentAddr++ << " : LDA 1,0(0)  set frist frame\n";
}