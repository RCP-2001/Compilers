#include "CodeGen.h"

ListNode::~ListNode()
{
    if (next != NULL)
    {
        delete next;
    }
}

ListNode::ListNode(treeNode* node){
    TokenStr = node->token()->tokenstr;
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
    ListNode* Current = new ListNode(TreeNode);
    ListNode* Child0 = Linearize(TreeNode->GetChild(0));
    ListNode* Child1 = Linearize(TreeNode->GetChild(1));
    ListNode* Child2 = Linearize(TreeNode->GetChild(2));
    Current->AddNode(Child0);
    Current->AddNode(Child1);
    Current->AddNode(Child2);

    ListNode* Sibling = Linearize(TreeNode->nextSibling());
    Current->AddNode(Sibling);
    return Current;
}

void ListNode::GenerateCode(std::ofstream &Fileout){
    Fileout << "PoggerTest \n";
    if(next!=NULL){
        next->GenerateCode(Fileout);
    }
}