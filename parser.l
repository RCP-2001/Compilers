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
"if"                        {return setValue(line, IF, yytext);}
"then"                      {return setValue(line, THEN, yytext);}
"else"                      {return setValue(line, ELSE, yytext);}

"while"                     {return setValue(line, WHILE, yytext);}
"for"                       {return setValue(line, FOR, yytext);}
"do"                        {return setValue(line, DO, yytext);}
"to"                        {return setValue(line, TO, yytext);}
"by"                        {return setValue(line, BY, yytext);}

"return"                    {return setValue(line, RETURN, yytext);}
"break"                     {return setValue(line, BREAK, yytext);}

"or"                        {return setValue(line, OR, yytext);}
"and"                       {return setValue(line, AND, yytext );}
"not"                       {return setValue(line, NOT, yytext );}

"static"                    {return setValue(line, STATIC, yytext);}
"int"                       {return setValue(line, INT, yytext);}
"bool"                      {return setValue(line, BOOL, yytext);}
"char"                      {return setValue(line, CHAR, yytext);}
"true"|"false"              {return setValue(line, BOOLCONST, yytext); }

[a-zA-Z][a-zA-Z0-9]*        {return setValue(line, ID, yytext); }
[0-9]+                      {return setValue(line, NUMCONST, yytext); }
\'.*\'                      {return setValue(line, CHARCONST, yytext);}
["].*["]                    {return setValue(line, STRINGCONST, yytext);}

;                           {return setValue(line, SEMI, yytext);}
,                           {return setValue(line, COMMA, yytext);}
:                           {return setValue(line, COLON, yytext);}
\[                          {return setValue(line, LBRACK, yytext);}  
]                           {return setValue(line, RBRACK, yytext);} 
\{                          {return setValue(line, LCURL, yytext);}
\}                          {return setValue(line, RCURL, yytext);}
\(                          {return setValue(line, LPAREN, yytext);}
\)                           {return setValue(line, RPAREN, yytext);}

"++"                        {return setValue(line, INC, yytext);}
"--"                        {return setValue(line, DEC, yytext);}
"+="                        {return setValue(line, ADDASS, yytext);}
"-="                        {return setValue(line, DECASS, yytext);}
"*="                        {return setValue(line, MULASS, yytext);}
"/="                        {return setValue(line, DIVASS, yytext);}

"<="                        {return setValue(line, LEQ, yytext);}
">="                        {return setValue(line, GEQ, yytext);}
\<                           {return setValue(line, LESS, yytext);}
>                           {return setValue(line, GREATER, yytext);}
"=="                        {return setValue(line, EQ, yytext);}
"!="                        {return setValue(line, NEQ, yytext);}
\+                          {return setValue(line, ADD, yytext);}
-                           {return setValue(line, SUB, yytext);}
\*                          {return setValue(line, MUL, yytext);}   
\/                          {return setValue(line, DIV, yytext);}
%                           {return setValue(line, MOD, yytext);}
\?                          {return setValue(line, QMARK, yytext);}
=                           {return setValue(line, ASSIGN, yytext);}



[ \t]                       ;
\/\/.*                      ;
\n                          {line++;}

.                           { printf("ERROR(%d): Invalid or misplaced input character: '%c'. Character Ignored.\n", line, yytext[0]); numErrors++;}
%%
