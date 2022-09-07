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
[ \t]                       ;
\/\/.*                      ;
\n                          {line++;}
[\[\]{}=><+-/\*]            { return setValue(line, ASSOP, yytext); }
.                           { printf("ERROR(%d): Invalid or misplaced input character: '%c'. Character Ignored.\n", line, yytext[0]); numErrors++;}
%%
