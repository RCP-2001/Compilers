%{

#include "scanType.h" // TokenData Type
#include "parser.tab.h" // token definition from bison? might not need this (yet)

int line = 1; 
int numErrors;

static int setValue(int linenum, int tokenClass, char *svalue){
    // create the pass-bacc data space
    yylval.tokenData = new TokenData; 

    //fill it up
    yylval.tokenData->linenum = linenum;
    yylval.tokenData->tokenstr = strdup(svalue);

    //refactor as switch????
    if(tokenClass == NUMCONST){
        //printf("NUMCONST Set val\n");
        yylval.tokenData->nvalue = atoi(svalue); // Set value to number in svalue
    }
    else if(tokenClass == ID){
        //printf("ID Set val\n");
        yylval.tokenData->svalue = strdup(svalue); // really dont understand this KEKW

    }
    else if(tokenClass == CHARCONST){
        //printf("Charconst Set val\n");
        yylval.tokenData->cvalue = svalue[1];
    }
    else if(tokenClass == STRINGCONST){
        //printf("Stringconst Set val\n");
        yylval.tokenData->svalue = strdup(svalue);
    }
    else if(tokenClass == BOOLCONST){
        if(strcmp(svalue, "false") == 0){
          yylval.tokenData->nvalue = 0;
        }
        else{
            yylval.tokenData->nvalue = 1;
        }
    }
    //return the token class
    return tokenClass;

}

%}

%option noyywrap

%%
[a-zA-Z][a-zA-Z0-9]*        {/*printf("ID LEXER\n");*/ return setValue(line, ID, yytext); }
[0-9]+                      {/*printf("NUMCONST LEXER\n");*/return setValue(line, NUMCONST, yytext); }
\'.*\'                      {/*printf("CHARCONST LEXER\n");*/return setValue(line, CHARCONST, yytext);}
["].+["]                    {/*printf("STRINGCONST LEXER\n");*/return setValue(line, STRINGCONST, yytext);}
[ \t]                       {/*printf("TAB\n");*/}
\/\/.*                      {/*printf("Comment LOL\n");*/}
\n                          {/*printf("NEWLINE LEXER\n");*/ line++; /*return setValue(line, yytext[0], yytext)*/; }
[=><+-/\*]                  { return setValue(line, ID, yytext); }
"true"|"false"              { return setValue(line, BOOLCONST, yytext); }
.                           { printf("ERROR(%d): Invalid or misplaced input character: '%c'. Character Ignored.\n", numErrors, yytext[0]); numErrors++;}
%%
