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

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST BOOL INT CHAR

// This is where my brain breaks
//temp for shizzle 

%%
tokenList : token tokenList
          | token
          ;

token     : ID          {printf("Line %d Token: ID value: %s \n", $1->linenum, $1->svalue); } 
          | NUMCONST    {printf("Line %d Token: NUMCONST Value: %d Input: %s\n", $1->linenum, $1->nvalue, $1->tokenstr);}
          | CHARCONST   {printf("Line %d Token: CHARCONST Value: '%c' Input: %s \n", $1->linenum, $1->cvalue, $1->svalue);}
          | STRINGCONST {printf("Line %d Token: STRINGCONST Value: \"%s\" Len: %d Input: %s \n", $1->linenum, $1->svalue, strlen($1->svalue), $1->svalue);}
          | BOOLCONST   {printf("Line %d Token: BOOLCONST Value: %d Input: %s \n", $1->linenum, $1->nvalue, $1->tokenstr);}
          | BOOL        {printf("Line %d Token: BOOL\n", $1->linenum);}
          | INT        {printf("Line %d Token: INT\n", $1->linenum);}
          | CHAR        {printf("Line %d Token: CHAR\n", $1->linenum);}
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

        printf("Number of errors: %d\n", numErrors);
    
}