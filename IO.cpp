#include "IO.h"
#include <string.h>

treeNode *MakeIOFuncs()
{
    // make "tokens" for the tree
    TokenData *InputToken = new TokenData();
    InputToken->tokenstr = strdup("input");
    InputToken->svalue = strdup("input");
    InputToken->cvalue = '\0';
    InputToken->linenum = -1;
    InputToken->nvalue = 0;
    InputToken->tokenclass = 260; // ID type Number

    TokenData *InputbToken = new TokenData();
    InputbToken->tokenstr = strdup("inputb");
    InputbToken->svalue = strdup("inputb");
    InputbToken->cvalue = '\0';
    InputbToken->linenum = -1;
    InputbToken->nvalue = 0;
    InputbToken->tokenclass = 260; // ID type Number

    TokenData *InputcToken = new TokenData();
    InputcToken->tokenstr = strdup("inputc");
    InputcToken->svalue = strdup("inputc");
    InputcToken->cvalue = '\0';
    InputcToken->linenum = -1;
    InputcToken->nvalue = 0;
    InputcToken->tokenclass = 260; // ID type Number

    TokenData *OutputToken = new TokenData();
    OutputToken->tokenstr = strdup("output");
    OutputToken->svalue = strdup("output");
    OutputToken->cvalue = '\0';
    OutputToken->linenum = -1;
    OutputToken->nvalue = 0;
    OutputToken->tokenclass = 260; // ID type Number

    TokenData *OutputbToken = new TokenData();
    OutputbToken->tokenstr = strdup("outputb");
    OutputbToken->svalue = strdup("outputb");
    OutputbToken->cvalue = '\0';
    OutputbToken->linenum = -1;
    OutputbToken->nvalue = 0;
    OutputbToken->tokenclass = 260; // ID type Number

    TokenData *OutputcToken = new TokenData();
    OutputcToken->tokenstr = strdup("outputc");
    OutputcToken->svalue = strdup("outputc");
    OutputcToken->cvalue = '\0';
    OutputcToken->linenum = -1;
    OutputcToken->nvalue = 0;
    OutputcToken->tokenclass = 260; // ID type Number

    TokenData *OutputnlToken = new TokenData();
    OutputnlToken->tokenstr = strdup("outnl");
    OutputnlToken->svalue = strdup("outnl");
    OutputnlToken->cvalue = '\0';
    OutputnlToken->linenum = -1;
    OutputnlToken->nvalue = 0;
    OutputnlToken->tokenclass = 260; // ID type Number

    //"Tokens" for Params
    TokenData *OutputParamToken = new TokenData();
    OutputParamToken->tokenstr = strdup("param");
    OutputParamToken->svalue = strdup("param");
    OutputParamToken->cvalue = '\0';
    OutputParamToken->linenum = -1;
    OutputParamToken->nvalue = 0;
    OutputParamToken->tokenclass = 260; // ID type Number

    TokenData *OutputBParamToken = new TokenData();
    OutputBParamToken->tokenstr = strdup("paramB");
    OutputBParamToken->svalue = strdup("paramB");
    OutputBParamToken->cvalue = '\0';
    OutputBParamToken->linenum = -1;
    OutputBParamToken->nvalue = 0;
    OutputBParamToken->tokenclass = 260; // ID type Number

    TokenData *OutputCParamToken = new TokenData();
    OutputCParamToken->tokenstr = strdup("paramC");
    OutputCParamToken->svalue = strdup("paramC");
    OutputCParamToken->cvalue = '\0';
    OutputCParamToken->linenum = -1;
    OutputCParamToken->nvalue = 0;
    OutputCParamToken->tokenclass = 260; // ID type Number

    // tree nodes for params
    treeNode *OutputParam = newDeclNode(ParamK, Integer, OutputParamToken);
    treeNode *OutputBParam = newDeclNode(ParamK, boolean, OutputBParamToken);
    treeNode *OutputCParam = newDeclNode(ParamK, Char, OutputCParamToken);

    // Params are "Used" (probably will be able to get rid of)
    OutputParam->UsedIs(true);
    OutputBParam->UsedIs(true);
    OutputCParam->UsedIs(true);

    // create tree nodes for funcs
    treeNode *Input = newDeclNode(FuncK, Integer, InputToken);
    treeNode *InputB = newDeclNode(FuncK, boolean, InputbToken);
    treeNode *InputC = newDeclNode(FuncK, Char, InputcToken);
    treeNode *Output = newDeclNode(FuncK, Void, OutputToken);
    treeNode *OutputB = newDeclNode(FuncK, Void, OutputbToken);
    treeNode *OutputC = newDeclNode(FuncK, Void, OutputcToken);
    treeNode *Outputnl = newDeclNode(FuncK, Void, OutputnlToken);

    // TreeNodes "are used"
    Input->UsedIs(true);
    InputB->UsedIs(true);
    InputC->UsedIs(true);
    Output->UsedIs(true);
    OutputB->UsedIs(true);
    OutputC->UsedIs(true);
    Outputnl->UsedIs(true);
    // Add params as Children
    Output->addChildren(OutputParam, 0);
    OutputB->addChildren(OutputBParam, 0);
    OutputC->addChildren(OutputCParam, 0);

    // Return Statements Output
    // Still Dummy Stuff\

    // all of these bad boys ass siblings to Input
    Input->addSibling(InputB);
    Input->addSibling(InputC);
    Input->addSibling(Output);
    Input->addSibling(OutputC);
    Input->addSibling(OutputB);
    Input->addSibling(Outputnl);

    return Input;
}