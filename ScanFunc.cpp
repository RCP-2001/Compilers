#include "scanType.h"

treeNode *newDeclNode(DeclKind kind, ExpType type, TokenData* token, treeNode* c0, treeNode* c1, treeNode* c2){
    //fprintf(stderr, "DECL NODE START\n"); 
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;

    node->sibling = NULL;
    //node.line_num = ???;
    node->nodeKind = DeclK;
    node->subkind.decl = kind;
    node->attr = token;

    node->expType = type;

    //fprintf(stderr, "DEC NODE  Return\n"); 
    return node;
}

treeNode *newStmtNode(StmtKind kind, TokenData* token, treeNode* c0, treeNode* c1, treeNode* c2){
   // fprintf(stderr, "STMT NODE START\n");
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;
    printf("");

    node->sibling = NULL;
    //node.line_num = ???;
    node->nodeKind = StmtK;
    node->subkind.stmt = kind;
    node->attr = token;
    //fprintf(stderr, "STMT NODE START\n");
    return node;
}

treeNode *newExpNode(ExpKind kind, TokenData* token, treeNode* c0, treeNode* c1, treeNode* c2){
    treeNode *node = new treeNode;
    node->child[0] = c0;
    node->child[1] = c1;
    node->child[2] = c2;

    node->sibling = NULL;
    //node.line_num = ???;
    node->nodeKind = ExpK;
    node->subkind.exp = kind;
    node->attr = token;

    return node;

}

void treeNode::addSibling(treeNode* aNode){
    // fprintf(stderr, "SIBLING NODE START\n");
    if(sibling == NULL){
        //fprintf(stderr, "SIBLING NODE IF\n");
        sibling = aNode;
        return;
    }
    else{
     //   fprintf(stderr, "SIBLING NODE ELSE\n");
        sibling->addSibling(aNode);
    }
}

void treeNode::EType(ExpType etype){
    expType = etype;
}

void treeNode::BStatic(bool type){
    isStatic = type;
}

void treeNode::addChildren(treeNode *aNode){
    for(int i = 0; i < MAX_CHILDREN; i++){
        if(child[i] == NULL){
            child[i] = aNode;
            return;
        }
    }
    fprintf(stderr, "Could not add child. IDK something off now\n"); 
}
