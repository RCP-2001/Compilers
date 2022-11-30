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
    std:

    std::string Type;
    std::string TokenStr;

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
