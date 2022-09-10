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

// This is where my brain breaks
//temp for shizzle 

%%
tokenList : token tokenList
          | token
          ;

token     : ID          {printf("Line %d Token: ID Value: %s\n", $1->linenum, $1->svalue); } 
          | NUMCONST    {printf("Line %d Token: NUMCONST Value: %d  Input: %s\n", $1->linenum, $1->nvalue, $1->tokenstr);}
          | CHARCONST   {printf("Line %d Token: CHARCONST Value: '%c'  Input: %s\n", $1->linenum, $1->cvalue, $1->tokenstr);}
          | STRINGCONST {printf("Line %d Token: STRINGCONST Value: \"%s\"  Len: %d  Input: %s\n", $1->linenum, $1->svalue, strlen($1->svalue), $1->tokenstr);}
          | BOOLCONST   {printf("Line %d Token: BOOLCONST Value: %d  Input: %s\n", $1->linenum, $1->nvalue, $1->tokenstr);}
          | BOOL        {printf("Line %d Token: BOOL\n", $1->linenum);}
          | INT         {printf("Line %d Token: INT\n", $1->linenum);}
          | CHAR        {printf("Line %d Token: CHAR\n", $1->linenum);}
          | IF          {printf("Line %d Token: IF\n", $1->linenum);}
          | THEN        {printf("Line %d Token: THEN\n", $1->linenum);}
          | ELSE        {printf("Line %d Token: ELSE\n", $1->linenum);}
          | WHILE       {printf("Line %d Token: WHILE\n", $1->linenum);}
          | FOR         {printf("Line %d Token: FOR\n", $1->linenum);}
          | DO          {printf("Line %d Token: DO\n", $1->linenum);}
          | TO          {printf("Line %d Token: TO\n", $1->linenum);}
          | BY          {printf("Line %d Token: BY\n", $1->linenum);}
          | RETURN      {printf("Line %d Token: RETURN\n", $1->linenum);}
          | BREAK       {printf("Line %d Token: BREAK\n", $1->linenum);}
          | OR          {printf("Line %d Token: OR\n", $1->linenum);}
          | AND         {printf("Line %d Token: AND\n", $1->linenum);}
          | NOT         {printf("Line %d Token: NOT\n", $1->linenum);}
          | STATIC      {printf("Line %d Token: STATIC\n", $1->linenum);}
          | SEMI        {printf("Line %d Token: ;\n", $1->linenum);}
          | COMMA       {printf("Line %d Token: ,\n", $1->linenum);}
          | COLON       {printf("Line %d Token: :\n", $1->linenum);}
          | LBRACK      {printf("Line %d Token: [\n", $1->linenum);}
          | RBRACK      {printf("Line %d Token: ]\n", $1->linenum);}
          | LCURL       {printf("Line %d Token: {\n", $1->linenum);}
          | RCURL       {printf("Line %d Token: }\n", $1->linenum);}
          | INC         {printf("Line %d Token: INC\n", $1->linenum);}
          | DEC         {printf("Line %d Token: DEC\n", $1->linenum);}
          | ADDASS      {printf("Line %d Token: ADDASS\n", $1->linenum);}
          | DECASS      {printf("Line %d Token: DECASS\n", $1->linenum);}
          | MULASS      {printf("Line %d Token: MULASS\n", $1->linenum);}
          | DIVASS      {printf("Line %d Token: DIVASS\n", $1->linenum);}
          | LEQ         {printf("Line %d Token: LEQ\n", $1->linenum);}
          | GEQ         {printf("Line %d Token: GEQ\n", $1->linenum);}
          | LESS        {printf("Line %d Token: <\n", $1->linenum);}
          | GREATER     {printf("Line %d Token: >\n", $1->linenum);}
          | EQ          {printf("Line %d Token: EQ\n", $1->linenum);}
          | NEQ         {printf("Line %d Token: NEQ\n", $1->linenum);}
          | ADD         {printf("Line %d Token: +\n", $1->linenum);}
          | SUB         {printf("Line %d Token: -\n", $1->linenum);}
          | MUL         {printf("Line %d Token: *\n", $1->linenum);}
          | DIV         {printf("Line %d Token: /\n", $1->linenum);}
          | MOD         {printf("Line %d Token: %%\n", $1->linenum);}
          | QMARK       {printf("Line %d Token: ?\n", $1->linenum);}
          | ASSIGN      {printf("Line %d Token: =\n", $1->linenum);}
          | LPAREN      {printf("Line %d Token: (\n", $1->linenum);}
          | RPAREN      {printf("Line %d Token: )\n", $1->linenum);}

          ;
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