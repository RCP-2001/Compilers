%{

#include "scanType.h" // TokenData Type
#include "parser.tab.h" // token definition from bison? might not need this (yet)


int line = 1; 
int numErrors = 0;
int numWarnings = 0;
char* lastToken = NULL;

static int setValue(int linenum, int tokenClass, char *svalue){
    // create the pass-bacc data space
    yylval.tokenData = new TokenData; 
    
    //fill it up
    yylval.tokenData->tokenclass = tokenClass;
    yylval.tokenData->linenum = linenum;
    yylval.tokenData->tokenstr = strdup(svalue);
    yylval.tokenData->cvalue = '\0';
    yylval.tokenData->nvalue = 0;
    yylval.tokenData->svalue = NULL;

    //refactor as switch????
    if(tokenClass == NUMCONST){
        //printf("NUMCONST Set val\n");
        yylval.tokenData->nvalue = atoi(svalue); // Set value to number in svalue
    }
    else if(tokenClass == ID){
        //printf("ID Set val\n");
        //fprintf(stderr, "ID Number %d\n", ID);
        yylval.tokenData->svalue = strdup(svalue); 

    }
    else if(tokenClass == CHARCONST){
        //printf("Charconst Set val\n");
        if(strlen(svalue) == 2){
            printf("ERROR(3): Empty character ''. Characters ignored.\n");
            numErrors++;
        }

        else if(svalue[1] == '\\'){
            if(strlen(svalue) > 4){
                printf("WARNING(%d): character is %d characters long and not a single character: '%s'.  The first char will be used.\n", linenum, strlen(svalue)-2, svalue);
                numWarnings++;
            }
            if(svalue[2] == 'n'){
                yylval.tokenData->cvalue = '\n';
            }
            else if(svalue[2] == '0'){
                yylval.tokenData->cvalue = '\0';
            }
            else {
                yylval.tokenData->cvalue = svalue[2]; 
            }
        }
        else{
            if(strlen(svalue) > 3){
                printf("WARNING(%d): character is %d characters long and not a single character: '%s'.  The first char will be used.\n", linenum, strlen(svalue)-2, svalue);
                numWarnings++;
            }
            yylval.tokenData->cvalue = svalue[1];
        }

    }
    else if(tokenClass == STRINGCONST){
        //printf("Stringconst Set val\n");
       //yylval.tokenData->svalue = strdup(svalue);
       // yylval.tokenData->svalue = (char*) malloc((sizeof(char) * (strlen(svalue))) + 1);
       // yylval.tokenData->svalue = (char*) malloc(sizeof(char)*100);
       // int size = sprintf(yylval.tokenData->svalue, svalue);
        //printf("%s \n\n\n\n\n", yylval.tokenData->svalue);
        /*if(size == -1){
            printf("copying in a bad way (FIX!!) \n\n\n");
            yylval.tokenData->svalue = strdup(svalue);
        }*/
        int sizeOfString = strlen(svalue);
        yylval.tokenData->svalue = (char *) malloc((sizeof(char)) * sizeOfString);
        int inStringPos = 0;
        bool LASTCHARSLASH = false;
        for(int i = 1; i < sizeOfString-1; i++){
            if(svalue[i] != '\\' && LASTCHARSLASH == false){
                yylval.tokenData->svalue[inStringPos] = svalue[i];
                inStringPos++;
                LASTCHARSLASH = false;
            }
            else if(svalue[i] != '\\' && LASTCHARSLASH == true){
                if(svalue[i] == 'n'){
                    yylval.tokenData->svalue[inStringPos] = '\n';
                    inStringPos++;
                }
                else if(svalue[i] == '0'){
                    yylval.tokenData->svalue[inStringPos] = '\0';
                    inStringPos++;
                }
                else {
                    yylval.tokenData->svalue[inStringPos] = svalue[i];
                    inStringPos++;
                }
                LASTCHARSLASH = false;
            }
            else if(svalue[i] == '\\' && LASTCHARSLASH == true){ 
                if(svalue[i+1]=='\\'){
                    //do nothing lol
                    LASTCHARSLASH = true;
                }
                else{
                    yylval.tokenData->svalue[inStringPos] = svalue[i];
                    inStringPos++;
                    LASTCHARSLASH = false; // It's like this because, techincally, the escape \ came first (I dont like this either tbh)
                    
                }
            }
            else if(svalue[i] == '\\' && LASTCHARSLASH == false){
                LASTCHARSLASH = true;
            }
            else{
                printf("test\n");
            }

        }         
   
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
"if"                        {lastToken = yytext; return setValue(line, IF, yytext);}
"then"                      {lastToken = yytext; return setValue(line, THEN, yytext);}
"else"                      {lastToken = yytext; return setValue(line, ELSE, yytext);}

"while"                     {lastToken = yytext; return setValue(line, WHILE, yytext);}
"for"                       {lastToken = yytext; return setValue(line, FOR, yytext);}
"do"                        {lastToken = yytext; return setValue(line, DO, yytext);}
"to"                        {lastToken = yytext; return setValue(line, TO, yytext);}
"by"                        {lastToken = yytext; return setValue(line, BY, yytext);}

"return"                    {lastToken = yytext; return setValue(line, RETURN, yytext);}
"break"                     {lastToken = yytext; return setValue(line, BREAK, yytext);}

"or"                        {lastToken = yytext; return setValue(line, OR, yytext);}
"and"                       {lastToken = yytext; return setValue(line, AND, yytext );}
"not"                       {lastToken = yytext; return setValue(line, NOT, yytext );}

"static"                    {lastToken = yytext; return setValue(line, STATIC, yytext);}
"int"                       {lastToken = yytext; return setValue(line, INT, yytext);}
"bool"                      {lastToken = yytext; return setValue(line, BOOL, yytext);}
"char"                      {lastToken = yytext; return setValue(line, CHAR, yytext);}
"true"|"false"              {lastToken = yytext; return setValue(line, BOOLCONST, yytext); }

[a-zA-Z][a-zA-Z0-9]*        {lastToken = yytext; return setValue(line, ID, yytext); }
[0-9]+                      {lastToken = yytext; return setValue(line, NUMCONST, yytext); }
L?'(\\.|[^\\'\n])*'	        {lastToken = yytext; return setValue(line, CHARCONST, yytext);}
L?\"(\\.|[^\\"\n])*\"       {lastToken = yytext; return setValue(line, STRINGCONST, yytext);}

;                           {lastToken = yytext; return setValue(line, SEMI, yytext);}
,                           {lastToken = yytext; return setValue(line, COMMA, yytext);}
:                           {lastToken = yytext; return setValue(line, COLON, yytext);}
\[                          {lastToken = yytext; return setValue(line, LBRACK, yytext);}  
]                           {lastToken = yytext; return setValue(line, RBRACK, yytext);} 
\{                          {lastToken = yytext; return setValue(line, LCURL, yytext);}
\}                          {lastToken = yytext; return setValue(line, RCURL, yytext);}
\(                          {lastToken = yytext; return setValue(line, LPAREN, yytext);}
\)                          {lastToken = yytext; return setValue(line, RPAREN, yytext);}

"++"                        {lastToken = yytext; return setValue(line, INC, yytext);}
"--"                        {lastToken = yytext; return setValue(line, DEC, yytext);}
"+="                        {lastToken = yytext; return setValue(line, ADDASS, yytext);}
"-="                        {lastToken = yytext; return setValue(line, DECASS, yytext);}
"*="                        {lastToken = yytext; return setValue(line, MULASS, yytext);}
"/="                        {lastToken = yytext; return setValue(line, DIVASS, yytext);}

"<="                        {lastToken = yytext; return setValue(line, LEQ, yytext);}
">="                        {lastToken = yytext; return setValue(line, GEQ, yytext);}
\<                          {lastToken = yytext; return setValue(line, LESS, yytext);}
>                           {lastToken = yytext; return setValue(line, GREATER, yytext);}
"=="                        {lastToken = yytext; return setValue(line, EQ, yytext);}
"!="                        {lastToken = yytext; return setValue(line, NEQ, yytext);}
\+                          {lastToken = yytext; return setValue(line, ADD, yytext);}
-                           {lastToken = yytext; return setValue(line, SUB, yytext);}
\*                          {lastToken = yytext; return setValue(line, MUL, yytext);}   
\/                          {lastToken = yytext; return setValue(line, DIV, yytext);}
%                           {lastToken = yytext; return setValue(line, MOD, yytext);}
\?                          {lastToken = yytext; return setValue(line, QMARK, yytext);}
=                           {lastToken = yytext; return setValue(line, ASSIGN, yytext);}



[ \t]                       ;
\/\/.*                      ;
\n                          {line++;}

.                           { printf("ERROR(%d): Invalid or misplaced input character: '%c'. Character Ignored.\n", line, yytext[0]); numErrors++;}
%%
