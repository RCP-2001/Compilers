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

declist : declist decl  {$1-> addSibling($2); $$ = $1;}
        | decl          {$$=$1;}    
        ;

decl    : varDecl  {$$=$1;}
        | funDecl  {$$=$1;}
        ;

varDecl : typeSpec varDeclList SEMI  {$2->EType($1); $2->BStatic(true); $$=$2;}
        ;

scopedVarDecl   : STATIC typeSpec varDeclList SEMI  {$3->EType($2); $3->BStatic(true); $$=$3;}      
                | typeSpec varDeclList SEMI         {$2->EType($1); $$=$2; /*This might be wrong actually*/}
                ;

varDeclList     : varDeclList COMMA varDeclInit  {$1->addSibling($3); $$ = $1;  }   
                | varDeclInit                    {$$=$1;}    
                ;

varDeclInit     : varDeclID                    {$$ = $1;}                 
                | varDeclID COLON simpleExp    {$1->addChildren($3, 0); $$ = $1;}     
                ;

varDeclID       : ID                            {$$ = newDeclNode(VarK, UndefinedType, $1); }                        
                | ID LBRACK NUMCONST RBRACK     {treeNode* node = newDeclNode(VarK, UndefinedType, $1); node->setArray(true); $$ = node;}    
                ;

typeSpec        : INT   {$$ = Integer;}                            
                | BOOL  {$$ = boolean;}                            
                | CHAR  {$$ = Char;}                         
                ;

funDecl         : typeSpec ID LPAREN params RPAREN compoundStmt   {treeNode* node = newDeclNode(FuncK, $1, $2); node-> addChildren($4, 0); node-> addChildren($6,1); $$= node;}
                | ID LPAREN params RPAREN compoundStmt            {treeNode* node = newDeclNode(FuncK, Void, $1); node-> addChildren($3, 0); node-> addChildren($5, 1); $$= node;}
                ;

params          : paramList     {$$ = $1;}
                | %empty        {$$= NULL;}
                ;

paramList       : paramList SEMI paramTypeList     {$1->addSibling($3); $$=$1;}
                | paramTypeList                    {$$=$1;}
                ;

paramTypeList   : typeSpec paramIDList          {$2->EType($1); $$=$2; /*This might be wrong actually*/}  
                ;

paramIDList     : paramIDList COMMA paramID     {$1->addSibling($3); $$ = $1;  }    
                | paramID                       {$$=$1;}   
                ;


paramID         : ID                           {$$ = newDeclNode(ParamK, UndefinedType, $1); }                          
                | ID LBRACK RBRACK             {treeNode* node = newDeclNode(ParamK, UndefinedType, $1); node->setArray(true); $$ = node;} 
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

closedSelectStatement : IF exp THEN closedStatement ELSE closedStatement        {treeNode *node = newStmtNode(IfK, $1, $2, $4, $6); $$=node;}
                      ;

simpleStatement : expStmt            {$$= $1;}
                | compoundStmt       {$$= $1;}
                | breakStmt          {$$= $1;}
                | returnStmt         {$$= $1;}
                ;

expStmt         : exp SEMI          {$$=$1;}
                | SEMI              {$$=NULL; /*WTF this porbably will break something i am sad wtf*/}
                ;

compoundStmt    : LCURL LocalDecls stmtList RCURL   {treeNode *node = newStmtNode(CompoundK, $1, $2, $3, NULL ); $$= node;}  
                ;

LocalDecls      : LocalDecls scopedVarDecl          {if($1 == NULL){$$=$2;} else{$1->addSibling($2); $$ = $1;}}
                | %empty                             {$$= NULL;}  
                ;

stmtList        : stmtList stmt    {if($1 == NULL){$$=$2;} else{$1->addSibling($2); $$ = $1;}}
                | %empty           {$$= NULL;}  
                ;

openItrStmt     : WHILE simpleExp DO openStatement      {treeNode* node = newStmtNode(WhileK, $1, $2, $4, NULL ); $$=node;}  
                | FOR ID ASSIGN itrRange DO openStatement   {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, $2, NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, $2, IDNode, $4, $6); $$ = node;  /*Totally wrong lmafo*/}
                ;

closedItrStmt   : WHILE simpleExp DO closedStatement     {treeNode* node = newStmtNode(WhileK, $1, $2, $4, NULL ); $$=node;}  
                | FOR ID ASSIGN itrRange DO closedStatement {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, $2, NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, $2, IDNode, $4, $6); $$ = node;  /*Totally wrong lmafo*/}
                ;

itrRange        : simpleExp TO simpleExp                {treeNode* node = newStmtNode(RangeK, $2, $1, $3, NULL); $$=node;}
                | simpleExp TO simpleExp BY simpleExp   {treeNode* node = newStmtNode(RangeK, $2, $1, $3, $5); $$=node;}
                ;

returnStmt      : RETURN SEMI           {treeNode* node = newStmtNode(ReturnK, $1, NULL, NULL, NULL); $$=node;}
                | RETURN exp SEMI       {treeNode* node = newStmtNode(ReturnK, $1, $2, NULL, NULL); $$=node;}
                ;

breakStmt       : BREAK SEMI           {treeNode* node = newStmtNode(BreaK, $1, NULL, NULL, NULL); $$=node;}
                ;

exp             : mutable assignop exp    {$2->addChildren($1,0); $2->addChildren($3,1); $$=$2;}
                | mutable INC             {treeNode* node = newExpNode(AssingK, $2, $1, NULL, NULL); $$=node; }
                | mutable DEC             {treeNode* node = newExpNode(AssingK, $2, $1, NULL, NULL); $$=node; }
                | simpleExp               {$$=$1; /*not sure this is right either tbh*/}

assignop        : ASSIGN         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Check yourself before you wreck yourself*/}
                | ADDASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /**/}
                | DECASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                | MULASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                | DIVASS         {treeNode* node = newExpNode(AssingK, $1); $$=node; /*Fairly certien this will give wrong tree structure*/}
                ;

simpleExp       : simpleExp OR andExp   {treeNode* node = newExpNode(OpK, $2, $1, $3, NULL); $$=node; }
                | andExp                {$$=$1;}
                ;

andExp          : andExp AND unaryRelExp    {treeNode* node = newExpNode(OpK, $2, $1, $3, NULL); $$=node; }
                | unaryRelExp              {$$=$1;}
                ;

unaryRelExp     : NOT unaryRelExp       {treeNode* node = newExpNode(OpK, $1, $2, NULL, NULL); $$=node; }
                | relExp                {$$=$1;}
                ;

relExp          : sumExp relop sumExp  {$2->addChildren($1,0); $2->addChildren($3,1); $$=$2;}
                | sumExp              {$$=$1;}   
                ;

relop           : LESS      {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | LEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | GREATER   {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | GEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | EQ        {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                | NEQ       {treeNode* node = newExpNode(OpK, $1); $$=node;}    
                ;

sumExp          : sumExp sumop mulExp {$2->addChildren($1,0); $2->addChildren($3,1); $$=$2;}
                | mulExp              {$$=$1;}
                ;

sumop           : ADD {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | SUB {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                ;

mulExp          : mulExp mulop unaryExp {$2->addChildren($1,0); $2->addChildren($3,1); $$=$2;}
                | unaryExp     {$$=$1;}
                ;

mulop           : MUL {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | DIV {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                | MOD {treeNode* node = newExpNode(OpK, $1, NULL, NULL, NULL); $$=node; }
                ;

unaryExp        : unaryOp unaryExp {$1->addChildren($2,0); $$=$1;}
                | factor            {$$=$1;}
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

immutable       : LPAREN exp RPAREN     {$$=$2;}
                | call                  {$$=$1;}
                | constant              {$$=$1;}
                ;

call            : ID LPAREN args RPAREN  {treeNode* node = newExpNode(CallK, $1, $3, NULL, NULL); $$=node;}
                ;

args            : argList   {$$=$1;}        
                | %empty   {$$=NULL;}       
                ;

argList         : argList COMMA exp {$1->addSibling($3); $$=$1;}
                | exp           {$$=$1;}
                ;

constant        : NUMCONST       {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Integer), $$=node; }
                | CHARCONST      {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Char), $$=node; }
                | STRINGCONST    {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(Char), node->setArray(true); $$=node; }
                | BOOLCONST      {treeNode* node = newExpNode(constantK, $1, NULL, NULL, NULL); node->EType(boolean), $$=node; }


%%
