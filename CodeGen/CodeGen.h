#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "../scanType.h"

class ListNode
{
private:
    // Codegen goes here?

    // Pretty sure I dont need these
    // just here for testing
    std::string address;
    std::string instruction;
    std::string comment;

    std::string Type;
    std::string TokenStr;

    treeNode *AssociatedNode;
    void GenCodeFromTree();
    std::string Code;

    ListNode *next;

public:

    ListNode()
    {
        next = NULL;
    }
    ListNode(treeNode *);
    ~ListNode();
    void AddNode(ListNode *);
    void GenerateCode(std::ofstream &Fileout);
};

ListNode *Linearize(treeNode *TreeNode);

void GenerateIOLib(std::ofstream &Fileout);
