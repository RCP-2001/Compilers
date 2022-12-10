
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
