%{
#include "scanType.h"
#include <stdio.h>
#include <cstring>

double vars[26]; // might not need? figure our what does

extern int yylex();
extern FILE *yyin;
extern int line; //err line number from scanner
extern int numErrors; //err count

#define YYERROR_VERBOSE
void yyerror(const char *msg){
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}

%}

%union{
    TokenData *tokenData;
    double value;
}

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST BOOL INT CHAR IF THEN ELSE WHILE FOR DO TO BY RETURN BREAK OR AND NOT STATIC SEMI COMMA COLON LBRACK RBRACK LCURL RCURL INC DEC ADDASS DECASS MULASS DIVASS LEQ GEQ LESS GREATER EQ NEQ ADD SUB MUL DIV MOD QMARK ASSIGN LPAREN RPAREN
%type <tokenData> declist decl varDecl scopedVarDecl varDeclList varDeclInit varDeclID typeSpec funDecl params paramList stmt expStmt compoundStmt LocalDecls stmtList openSelectStatement closedSelectStatement openItrStmt closedItrStmt itrRange returnStmt breakStmt exp simpleExp andExp unaryRelExp relExp relop sumExp sumop mulExp mulop unaryExp unaryOp factor mutable immutable call args argList constant openStatement closedStatement simpleStatement
// This is where my brain breaks
//temp for shizzle 

%%
program : declist       {printf("program accepted\n");}
        ;

declist : declist decl  {printf("declist\n");}
        | decl          {printf("declist\n");}
        ;

decl    : varDecl  {printf("decl \n");}
        | funDecl  {printf("decl \n");}
        ;

varDecl : typeSpec varDeclList SEMI         {printf("varDecl\n");}
        ;

scopedVarDecl   : STATIC typeSpec varDecl SEMI       {printf("scopedVardecl \n");}
                | typeSpec varDeclList SEMI         {printf("scopedVardecl \n");}
                ;

varDeclList     : varDeclList COMMA varDeclInit     {printf("VardecLList \n");}
                | varDeclInit                       {printf("VardecLList \n");}
                ;

varDeclInit     : varDeclID                         {printf("VardecLInnit \n");}
                | varDeclID COLON simpleExp         {printf("VardecLInnit \n");}
                ;

varDeclID       : ID                                {printf("VarDecID\n");}
                | ID LBRACK NUMCONST RBRACK         {printf("VarDecID\n");}
                ;

typeSpec        : INT                               {printf("typespec\n");}
                | BOOL                              {printf("typespec\n");}
                | CHAR                              {printf("typespec\n");}
                ;

funDecl         : typeSpec ID LPAREN params RPAREN compoundStmt             {printf("funDecl\n");}
                | ID LPAREN params RPAREN compoundStmt                      {printf("funDecl\n");}
                ;

params          : paramList {printf("params\n");}
                | %empty    {printf("params \n");}
                ;

paramList       : paramList SEMI paramTypeList      {printf("paramList\n");} 
                | paramTypeList                     {printf("paramList\n");}
                ;

paramTypeList   : typeSpec paramIDList              {printf("paramTypeList\n");}
                ;

paramIDList     : paramIDList COMMA paramID         {printf("paramIdList\n");}
                | paramID                           {printf("paramIdList\n");}
                ;


paramID         : ID                                {printf("ParamID\n");} 
                | ID LBRACK RBRACK                  {printf("ParamID\n");}
                ;

stmt            : openStatement     {printf("stmt\n");}
                | closedStatement   {printf("stmt\n");}
                ;

openStatement   : openItrStmt               {printf("openStatement\n");}
                | openSelectStatement       {printf("openStatement\n");}
                ;

closedStatement: closedSelectStatement      {printf("closedStatement\n");} 
                | closedItrStmt             {printf("closedStatemnet\n");}
                | simpleStatement           {printf("closedStatement\n");}


openSelectStatement     : IF LPAREN exp RPAREN stmt         {printf("OpenSelectaStatemnet\n");}
                        | IF LPAREN exp RPAREN closedStatement ELSE openStatement   {printf("openSelectaStatement\n");}

closedSelectStatement : IF LPAREN exp RPAREN closedStatement ELSE closedStatement   {printf("closedSelctaStatement\n");}
                      ;

simpleStatement : expStmt               {printf("Simpstmt\n");}
                | compoundStmt          {printf("Simpstmt\n");}
                | breakStmt             {printf("Simpstmt\n");}
                | returnStmt            {printf("Simpstmt\n");}
                ;

expStmt         : exp COLON         {printf("expStmt\n");}
                ;

compoundStmt    : LCURL LocalDecls stmtList RCURL       {printf("compound\n");}
                ;

LocalDecls      : LocalDecls scopedVarDecl              {printf("localDecals\n");} 
                | %empty                                {printf("Localdecals\n");} 
                ;

stmtList        : stmtList stmt     {printf("stmtList\n");}
                | %empty            {printf("stmtList\n");}
                ;

openItrStmt     : WHILE simpleExp DO openStatement      {printf("OpenItrStmt\n");} 
                | FOR ID EQ itrRange DO openStatement   {printf("OpenItrStmt\n");} 
                ;

closedItrStmt   : WHILE simpleExp DO closedStatement    {printf("ClosedItrStmt\n");} 
                | FOR ID EQ itrRange DO closedStatement {printf("ClosedItrStmt\n");} 
                ;

itrRange        : simpleExp TO simpleExp                {printf("itrRange");} 
                | simpleExp TO simpleExp BY simpleExp   {printf("itrRange");}
                ;

returnStmt      : RETURN SEMI             {printf("returnStmt\n");}
                | RETURN exp SEMI         {printf("returnStmt\n");}
                ;

breakStmt       : BREAK SEMI            {printf("BreakStmt\n");}
                ;

exp             : mutable assignop exp      {printf("mutable assignop exp\n");} 
                | mutable INC               {printf("mutable INC exp\n");}
                | mutable DEC               {printf("mutable DEC exp\n");}
                | simpleExp                 {printf("Simpleexp exp\n");}

assignop        : ASSIGN        {printf("assignop\n");} 
                | ADDASS        {printf("assignop\n");}
                | DECASS        {printf("assignop\n");}
                | MULASS        {printf("assignop\n");}
                | DIVASS        {printf("assignop\n");}
                ;

simpleExp       : simpleExp OR andExp   {printf("simpleExp\n");} 
                | andExp                {printf("simpleExp\n");}
                ;

andExp          : andExp AND unaryRelExp    {printf("andExp\n");} 
                | unaryRelExp               {printf("andExp\n");}
                ;

unaryRelExp     : NOT unaryRelExp {printf("unaryRelExp\n");} 
                | relExp  {printf("unaryRelExp\n");}
                ;

relExp          : sumExp relop sumExp  {printf("relExp\n");}
                | sumExp                {printf("relExp\n");}
                ;

relop           : LESS {printf("relOp\n");}
                | LEQ {printf("relOp\n");}
                | GREATER {printf("relOp\n");}
                | GEQ {printf("relOp\n");}
                | EQ {printf("relOp\n");}
                | NEQ{printf("relOp\n");}
                ;

sumExp          : sumExp sumop mulExp {printf("sumExp\n");}
                | mulExp {printf("sumExp\n");}
                ;

sumop           : ADD {printf("sumOp\n");}
                | SUB {printf("sumOp\n");}
                ;

mulExp          : mulExp mulop unaryExp {printf("mulExp\n");}
                | unaryExp     {printf("mulExp\n");}
                ;

mulop           : MUL {printf("mulOp\n");}
                | DIV {printf("mulOp\n");}
                | MOD{printf("mulOp\n");}
                ;

unaryExp        : unaryOp unaryExp {printf("unaryExp\n");}
                | factor            {printf("unaryExp\n");}
                ;

unaryOp         : SUB {printf("unaryOp\n");}
                | MUL {printf("unaryOp\n");}
                | QMARK {printf("unaryOp\n");}
                ;

factor          : mutable {printf("factor\n");} 
                | immutable {printf("factor\n");}
                ;

mutable         : ID {printf("mutable\n");}
                | ID LBRACK exp RBRACK {printf("mutable\n");}
                ;

immutable       : LPAREN exp RPAREN {printf("immuntabe\n");}
                | call              {printf("immuntable\n");}
                | constant          {printf("immutable\n");}
                ;

call            : ID LPAREN args RPAREN {printf("call\n");}
                ;

args            : argList           {printf("args\n");}
                | %empty          {printf("args\n");}
                ;

argList         : argList COMMA exp {printf("argList\n");}
                | exp
                ;

constant        : NUMCONST {printf("constant\n");}
                | CHARCONST {printf("constant\n");}
                | STRINGCONST {printf("constant\n");}
                | BOOLCONST {printf("constant\n");}


%%
extern int yydebug;
int main(int argc, char *argv[]){
    if(argc > 1){
        if ((yyin = fopen(argv[1], "r"))){
            //file open successful
        }
        else{
            printf("ERR: Failed to open %s \n", argv[1]);
            exit(1);
        }

    }
    for(int i=0; i<26; i++){
        vars[i] = 0.0;
    }
        numErrors = 0;
        yyparse();

        //printf("Number of errors: %d\n", numErrors);
    
}