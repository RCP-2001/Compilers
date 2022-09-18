%{
#include "scanType.h"
#include <stdio.h>
#include <cstring>

double vars[26]; // this is just for caluclator lol

extern int yylex();
extern FILE *yyin;
extern int line; //err line number from scanner
extern int numErrors; //err count

#define YYERROR_VERBOSE
void yyerror(const char *msg){
    printf("ERROR(%d): %s\n", line, msg);
    //printf("CurrentToken: %s \n", yytext);
    //printToken(yychar, tokenString);
    numErrors++;
}

%}

%union{
    ExpType type;
    TokenData *tokenData;
    treeNode tree;
}

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST BOOL INT CHAR IF THEN ELSE WHILE FOR DO TO BY RETURN BREAK OR AND NOT STATIC SEMI COMMA COLON LBRACK RBRACK LCURL RCURL INC DEC ADDASS DECASS MULASS DIVASS LEQ GEQ LESS GREATER EQ NEQ ADD SUB MUL DIV MOD QMARK ASSIGN LPAREN RPAREN
%type <tree> declist decl varDecl scopedVarDecl varDeclList varDeclInit varDeclID typeSpec funDecl params paramList stmt expStmt compoundStmt LocalDecls stmtList openSelectStatement closedSelectStatement openItrStmt closedItrStmt itrRange returnStmt breakStmt exp simpleExp andExp unaryRelExp relExp relop sumExp sumop mulExp mulop unaryExp unaryOp factor mutable immutable call args argList constant openStatement closedStatement simpleStatement
// This is where my brain breaks
//temp for shizzle 

%%
program : declist       {printf("accept Program\n");}
        ;

declist : declist decl  
        | decl          
        ;

decl    : varDecl  
        | funDecl  
        ;

varDecl : typeSpec varDeclList SEMI        
        ;

scopedVarDecl   : STATIC typeSpec varDeclList SEMI       
                | typeSpec varDeclList SEMI         
                ;

varDeclList     : varDeclList COMMA varDeclInit     
                | varDeclInit                       
                ;

varDeclInit     : varDeclID                        
                | varDeclID COLON simpleExp         
                ;

varDeclID       : ID                               
                | ID LBRACK NUMCONST RBRACK         
                ;

typeSpec        : INT                               
                | BOOL                              
                | CHAR                           
                ;

funDecl         : typeSpec ID LPAREN params RPAREN compoundStmt
                | ID LPAREN params RPAREN compoundStmt                     
                ;

params          : paramList 
                | %empty    
                ;

paramList       : paramList SEMI paramTypeList     
                | paramTypeList                    
                ;

paramTypeList   : typeSpec paramIDList             
                ;

paramIDList     : paramIDList COMMA paramID         
                | paramID                          
                ;


paramID         : ID                              
                | ID LBRACK RBRACK             
                ;

stmt            : openStatement     
                | closedStatement   
                ;

openStatement   : openItrStmt              
                | openSelectStatement       
                ;

closedStatement: closedSelectStatement      
                | closedItrStmt             
                | simpleStatement           


openSelectStatement     : IF exp THEN stmt         
                        | IF exp THEN closedStatement ELSE openStatement   

closedSelectStatement : IF exp THEN closedStatement ELSE closedStatement  
                      ;

simpleStatement : expStmt              
                | compoundStmt        
                | breakStmt            
                | returnStmt         
                ;

expStmt         : exp SEMI
                | SEMI       
                ;

compoundStmt    : LCURL LocalDecls stmtList RCURL     
                ;

LocalDecls      : LocalDecls scopedVarDecl            
                | %empty                                
                ;

stmtList        : stmtList stmt    
                | %empty           
                ;

openItrStmt     : WHILE simpleExp DO openStatement      
                | FOR ID ASSIGN itrRange DO openStatement   
                ;

closedItrStmt   : WHILE simpleExp DO closedStatement    
                | FOR ID ASSIGN itrRange DO closedStatement 
                ;

itrRange        : simpleExp TO simpleExp                
                | simpleExp TO simpleExp BY simpleExp  
                ;

returnStmt      : RETURN SEMI           
                | RETURN exp SEMI       
                ;

breakStmt       : BREAK SEMI           
                ;

exp             : mutable assignop exp     
                | mutable INC               
                | mutable DEC              
                | simpleExp                

assignop        : ASSIGN        
                | ADDASS        
                | DECASS        
                | MULASS        
                | DIVASS        
                ;

simpleExp       : simpleExp OR andExp   
                | andExp                
                ;

andExp          : andExp AND unaryRelExp    
                | unaryRelExp              
                ;

unaryRelExp     : NOT unaryRelExp 
                | relExp 
                ;

relExp          : sumExp relop sumExp  
                | sumExp               
                ;

relop           : LESS 
                | LEQ 
                | GREATER 
                | GEQ 
                | EQ
                | NEQ
                ;

sumExp          : sumExp sumop mulExp 
                | mulExp 
                ;

sumop           : ADD 
                | SUB 
                ;

mulExp          : mulExp mulop unaryExp 
                | unaryExp     
                ;

mulop           : MUL 
                | DIV 
                | MOD
                ;

unaryExp        : unaryOp unaryExp 
                | factor            
                ;

unaryOp         : SUB 
                | MUL 
                | QMARK 
                ;

factor          : mutable 
                | immutable 
                ;

mutable         : ID 
                | ID LBRACK exp RBRACK 
                ;

immutable       : LPAREN exp RPAREN 
                | call              
                | constant          
                ;

call            : ID LPAREN args RPAREN 
                ;

args            : argList           
                | %empty          
                ;

argList         : argList COMMA exp 
                | exp
                ;

constant        : NUMCONST 
                | CHARCONST 
                | STRINGCONST 
                | BOOLCONST 


%%
extern int yydebug;
int main(int argc, char *argv[]){
    //yydebug = 1;

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