%define parse.error verbose 
%{
#include "scanType.h"
#include "YYError/yyerror.h"
#include <stdio.h>
#include <cstring>

extern treeNode* GLOBAL_HEAD;

extern int yylex();
extern FILE *yyin;
extern int line; //err line number from scanner
extern int numErrors; //err count

/* Old yyerror
#define YYERROR_VERBOSE
void yyerror(const char *msg){
    printf("ERROR(%d): %s\n", line, msg);
    //printf("CurrentToken: %s \n", yytext);
    //printToken(yychar, tokenString);
    numErrors++;
}*/

%}

%union{
    ExpType type;
    TokenData *tokenData;
    treeNode *tree;
}

%token <tokenData>SIZEOF CHSIGN ID NUMCONST CHARCONST STRINGCONST BOOLCONST BOOL INT CHAR IF THEN ELSE WHILE FOR DO TO BY RETURN BREAK OR AND NOT STATIC SEMI COMMA COLON LBRACK RBRACK LCURL RCURL INC DEC ADDASS DECASS MULASS DIVASS LEQ GEQ LESS GREATER EQ NEQ ADD SUB MUL DIV MOD QMARK ASSIGN LPAREN RPAREN
%type <tokenData>  sizeof chsign
%type <tree> assignop paramID paramIDList paramTypeList declist decl varDecl scopedVarDecl varDeclList varDeclInit varDeclID funDecl params paramList stmt expStmt compoundStmt LocalDecls stmtList openSelectStatement closedSelectStatement openItrStmt closedItrStmt itrRange returnStmt breakStmt exp simpleExp andExp unaryRelExp relExp relop sumExp sumop mulExp mulop unaryExp unaryOp factor mutable immutable call args argList constant openStatement closedStatement simpleStatement
%type <type> typeSpec
// This is where my brain breaks
//temp for shizzle 

%%
program : declist       {/*printf("accept Program\n");*/ GLOBAL_HEAD = $1;}
        ;

declist : declist decl  {if($1!=NULL) $1-> addSibling($2); $1->BGlobal(true); $$ = $1;}
        | decl          {$$=$1;}    
        ;

decl    : varDecl  {$$=$1;}
        | funDecl  {$$=$1;}
        | error    {$$ = NULL;} // Do we need yxyerrok?
        ;

varDecl : typeSpec varDeclList SEMI  {if($2 != NULL){$2->EType($1);  $2->BGlobal(true);} $$=$2;}
        | error varDeclList SEMI     {$$=NULL; yyerrok;}
        | typeSpec error SEMI     {$$=NULL; yyerrok; }
        ;

scopedVarDecl   : STATIC typeSpec varDeclList SEMI  {if($3!=NULL){$3->EType($2); $3->BStatic(true);} $$=$3; yyerrok;}      
                | typeSpec varDeclList SEMI         {if($2!=NULL) $2->EType($1); $$=$2; yyerrok; /*This might be wrong actually*/}
                | error varDeclList SEMI            {$$=NULL; yyerrok;} //??
                | typeSpec error SEMI               {$$=NULL; yyerrok;} //??
                ;

varDeclList     : varDeclList COMMA varDeclInit  {if($1!=NULL) $1->addSibling($3); $$ = $1; yyerrok;}   //Need yxyerrok?
                | varDeclInit                    {$$=$1;}
                | varDeclList COMMA error        {$$=NULL;} //No yxyerrok?
                | error                          {$$=NULL;} //No yxyerrok?
                ;

varDeclInit     : varDeclID                    {$$ = $1;}                 
                | varDeclID COLON simpleExp    {if($1!=NULL)$1->addChildren($3, 0); $$ = $1;}
                | error COLON simpleExp             {$$ = NULL; yyerrok; }     
                ;

varDeclID       : ID                            {$$ = newDeclNode(VarK, UndefinedType, $1); $$->SetSize(1); }                        
                | ID LBRACK NUMCONST RBRACK     {treeNode* node = newDeclNode(VarK, UndefinedType, $1); node->setArray(true); node->SetSize($3->nvalue + 1); $$ = node;}    
                | ID LBRACK error               {$$=NULL;} //Hmm
                | error RBRACK                  {$$=NULL; yyerrok;} //Hmm
                ;

typeSpec        : INT   {$$ = Integer;}                            
                | BOOL  {$$ = boolean;}                            
                | CHAR  {$$ = Char;}                         
                ;

funDecl         : typeSpec ID LPAREN params RPAREN compoundStmt   {treeNode* node = newDeclNode(FuncK, $1, $2); node-> addChildren($4, 0); node-> addChildren($6,1); $$= node;}
                | ID LPAREN params RPAREN compoundStmt            {treeNode* node = newDeclNode(FuncK, Void, $1); node-> addChildren($3, 0); node-> addChildren($5, 1); $$= node;}
                | typeSpec error                                  {$$=NULL;}
                | typeSpec ID LPAREN error                       {$$=NULL;}
                | ID LPAREN error                                       {$$=NULL;} 
                | ID LPAREN params RPAREN error                 {$$=NULL;}
                ;

params          : paramList     {$$ = $1;}
                | %empty        {$$= NULL;}
                ;

paramList       : paramList SEMI paramTypeList     {if($1!=NULL) $1->addSibling($3); $$=$1;}
                | paramTypeList                    {$$=$1;}
                | paramList SEMI error             {$$= NULL;}
                | error                            {$$= NULL;}
                ;

paramTypeList   : typeSpec paramIDList          {if($2 != NULL) $2->EType($1); $$=$2; /*This might be wrong actually*/}  
                | typeSpec error                {$$= NULL;}
                ;

paramIDList     : paramIDList COMMA paramID     {if($1!=NULL) $1->addSibling($3); $$ = $1;  yyerrok;}    
                | paramID                       {$$=$1;}   
                | paramIDList COMMA error       {$$= NULL;}
                | error                         {$$= NULL;}
                ;


paramID         : ID                           {$$ = newDeclNode(ParamK, UndefinedType, $1); $$->SetSize(1); }                          
                | ID LBRACK RBRACK             {treeNode* node = newDeclNode(ParamK, UndefinedType, $1); node->setArray(true); node->SetSize(1); $$ = node;} 
                ;

stmt            : openStatement             {$$=$1;}
                | closedStatement           {$$=$1;}
                ;

openStatement   : openItrStmt            {$$=$1;}  
                | openSelectStatement    {$$=$1;}   
                ;

closedStatement: closedSelectStatement   {$$=$1;}   
                | closedItrStmt          {$$=$1;}   
                | simpleStatement        {$$=$1;}   


openSelectStatement     : IF exp THEN stmt                                      {treeNode *node = newStmtNode(IfK, $1, $2, $4, NULL); $$=node;}
                        | IF exp THEN closedStatement ELSE openStatement        {treeNode *node = newStmtNode(IfK, $1, $2, $4, $6); $$=node;}
                        | IF error THEN stmt    {$$=NULL; yyerrok;}
                        
                        | IF error THEN closedStatement ELSE openStatement {$$=NULL; yyerrok;}

closedSelectStatement : IF exp THEN closedStatement ELSE closedStatement        {treeNode *node = newStmtNode(IfK, $1, $2, $4, $6); $$=node;}
                        | IF error                                              {$$=NULL; }

                        | IF error ELSE closedStatement                         {$$=NULL; yyerrok;}

                        | IF error THEN closedStatement ELSE closedStatement      {$$=NULL; yyerrok;}

                      ;

simpleStatement : expStmt            {$$= $1;}
                | compoundStmt       {$$= $1;}
                | breakStmt          {$$= $1;}
                | returnStmt         {$$= $1;}
                ;

expStmt         : exp SEMI          {$$=$1; yyerrok; }
                | error SEMI        {$$=NULL; yyerrok;}
                | SEMI              {$$=NULL; /*WTF this porbably will break something i am sad wtf*/}
                ;

compoundStmt    : LCURL LocalDecls stmtList RCURL   {treeNode *node = newStmtNode(CompoundK, $1, $2, $3, NULL ); $$= node; yyerrok;}  
                ;

LocalDecls      : LocalDecls scopedVarDecl          {if($1 == NULL){$$=$2;} else{$1->addSibling($2); $$ = $1;}}
                | %empty                             {$$= NULL;}  
                ;

stmtList        : stmtList stmt    {if($1 == NULL){$$=$2;} else{$1->addSibling($2); $$ = $1;}  }
                | %empty           {$$= NULL;}  
                ;

openItrStmt     : WHILE simpleExp DO openStatement      {treeNode* node = newStmtNode(WhileK, $1, $2, $4, NULL ); $$=node;}  
                | FOR ID ASSIGN itrRange DO openStatement   {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, $2, NULL, NULL, NULL);
                                                            IDNode->SetSize(1);
                                                            treeNode* node = newStmtNode(ForK, $2, IDNode, $4, $6); $$ = node;  /*Totally wrong lmafo*/}
                | FOR error     {$$=NULL;}
                | FOR ID ASSIGN error DO openStatement  {$$=NULL; yyerrok;}
                | WHILE error {$$=NULL;}
                | WHILE error DO openStatement {$$=NULL; yyerrok;}
                
                ;

closedItrStmt   : WHILE simpleExp DO closedStatement     {treeNode* node = newStmtNode(WhileK, $1, $2, $4, NULL ); $$=node;}  
                | FOR ID ASSIGN itrRange DO closedStatement {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, $2, NULL, NULL, NULL);
                                                            IDNode->SetSize(1);
                                                            treeNode* node = newStmtNode(ForK, $2, IDNode, $4, $6); $$ = node;  /*Totally wrong lmafo*/}
                | FOR error     {$$=NULL;}
                | FOR ID ASSIGN error DO closedStatement  {$$=NULL; yyerrok;}
                | WHILE error {$$=NULL;}
                | WHILE error DO closedStatement {$$=NULL; yyerrok;}
                ;

itrRange        : simpleExp TO simpleExp                {treeNode* node = newStmtNode(RangeK, $2, $1, $3, NULL); $$=node;}
                | simpleExp TO simpleExp BY simpleExp   {treeNode* node = newStmtNode(RangeK, $2, $1, $3, $5); $$=node;}
                | simpleExp TO error {$$=NULL;}
                | error BY error     {$$=NULL; yyerrok;}
                | simpleExp TO simpleExp BY error {$$=NULL;}
                ;

returnStmt      : RETURN SEMI           {treeNode* node = newStmtNode(ReturnK, $1, NULL, NULL, NULL); $$=node;}
                | RETURN exp SEMI       {treeNode* node = newStmtNode(ReturnK, $1, $2, NULL, NULL); $$=node; yyerrok;}
                | RETURN error SEMI     {$$=NULL; yyerrok;}
                ;

breakStmt       : BREAK SEMI           {treeNode* node = newStmtNode(BreaK, $1, NULL, NULL, NULL); $$=node;}
                ;

exp             : mutable assignop exp    {if($2!=NULL){$2->addChildren($1,0); $2->addChildren($3,1);} $$=$2;}
                | mutable INC             {treeNode* node = newExpNode(AssingK, $2, $1, NULL, NULL); $$=node; }
                | mutable DEC             {treeNode* node = newExpNode(AssingK, $2, $1, NULL, NULL); $$=node; }
                | simpleExp               {$$=$1; /*not sure this is right either tbh*/}
                | error assignop exp      {$$=NULL; yyerrok;}
                | mutable assignop error  {$$=NULL; }
                | error INC               {$$=NULL; yyerrok;}
                | error DEC               {$$=NULL; yyerrok;}
                ;

assignop        : ASSIGN         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Check yourself before you wreck yourself*/}
                | ADDASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /**/}
                | DECASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                | MULASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                | DIVASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                ;

simpleExp       : simpleExp OR andExp   {treeNode* node = newExpNode(OpK, $2, $1, $3, NULL); $$=node; }
                | andExp                {$$=$1;}
                | simpleExp OR error    {$$ = NULL;}
                ;

andExp          : andExp AND unaryRelExp    {treeNode* node = newExpNode(OpK, $2, $1, $3, NULL); $$=node; }
                | unaryRelExp               {$$=$1;}
                | andExp AND error          {$$ = NULL;}
                ;

unaryRelExp     : NOT unaryRelExp       {treeNode* node = newExpNode(OpK, $1, $2, NULL, NULL); $$=node; }
                | relExp                {$$=$1;}
                | NOT error             {$$=NULL;}
                ;

relExp          : sumExp relop sumExp  {if($2!=NULL){$2->addChildren($1,0); $2->addChildren($3,1);} $$=$2;}
                | sumExp               {$$=$1;}
                | sumExp relop error   {$$=NULL;}   
                ;

relop           : LESS      {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | LEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | GREATER   {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | GEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | EQ        {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | NEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                ;

sumExp          : sumExp sumop mulExp {if($2!=NULL){$2->addChildren($1,0); $2->addChildren($3,1);} $$=$2;}
                | mulExp              {$$=$1; }
                | sumExp sumop error  {$$=NULL; }
                ;

sumop           : ADD {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | SUB {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                ;

mulExp          : mulExp mulop unaryExp {if($2!=NULL){$2->addChildren($1,0); $2->addChildren($3,1);} $$=$2;}
                | unaryExp     {$$=$1;}
                | mulExp mulop error {$$=NULL; }
                ;

mulop           : MUL {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | DIV {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | MOD {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                ;

unaryExp        : unaryOp unaryExp {if($1!=NULL)$1->addChildren($2,0); $$=$1;}
                | factor            {$$=$1;}
                | unaryOp error    {$$=NULL; }
                ;

unaryOp         : chsign        {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | sizeof        {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | QMARK         {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                ;

chsign      : SUB       {   free ($1->tokenstr);
                            $1->tokenstr=strdup("chsign"); $$=$1;  /*This might be really really wrong lol*/}
            ;
sizeof      : MUL       {   free ($1->tokenstr);
                            $1->tokenstr=strdup("sizeof"); $$=$1;  /*This might be really really wrong lol*/}
            ;

factor          : mutable           {$$=$1;}
                | immutable         {$$=$1;}
                ;

mutable         : ID                         {treeNode* node = newExpNode(IdK, $1, NULL, NULL, NULL); $$=node; }
                | ID LBRACK exp RBRACK      {
                                                treeNode* IDNode = newExpNode(IdK, $1, NULL, NULL, NULL);
                                                treeNode* node = newExpNode(OpK, $2, IDNode, $3, NULL); $$=node; /*Something is up with this one LOL*/ }
                ;

immutable       : LPAREN exp RPAREN     {$$=$2; yyerrok;}
                | call                  {$$=$1;}
                | constant              {$$=$1;}
                | LPAREN error          {$$=NULL; }
                ;

call            : ID LPAREN args RPAREN  {treeNode* node = newExpNode(CallK, $1, $3, NULL, NULL); $$=node;}
                | error LPAREN      {$$=NULL;  yyerrok; } /* in gramar on website, but seems to give close results without?*/
                ;

args            : argList   {$$=$1;}        
                | %empty   {$$=NULL;}       
                ;

argList         : argList COMMA exp {if($1!=NULL) $1->addSibling($3); $$=$1; yyerrok;}
                | exp           {$$=$1;}
                | argList COMMA error {$$=NULL;}
                ;

constant        : NUMCONST       {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Integer); node->SetSize(1); $$=node; }
                | CHARCONST      {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Char); node->SetSize(1); $$=node; }
                | STRINGCONST    {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Char); node->setArray(true); node->SetSize(strlen($1->svalue)+1); $$=node; }
                | BOOLCONST      {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(boolean); node->SetSize(1); $$=node; }


%%
