#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "../scanType.h"

#ifndef REG
#define REG

#define GLOBAL 0 
#define FRAMEPOINTER 1
#define RETURN 2
#define AC1 3
#define AC2 4
#define AC3 5
#define AC4 6
#define PC 7

#endif


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

void Init(std::ofstream &Fileout);

void GenerateIOLib(std::ofstream &Fileout);

void LoadConstants(treeNode *, std::string &);

void GenerateCodeTree(treeNode *Node, std::ofstream &Fileout, bool PushParam = false);
