/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SIZEOF = 258,                  /* SIZEOF  */
    CHSIGN = 259,                  /* CHSIGN  */
    ID = 260,                      /* ID  */
    NUMCONST = 261,                /* NUMCONST  */
    CHARCONST = 262,               /* CHARCONST  */
    STRINGCONST = 263,             /* STRINGCONST  */
    BOOLCONST = 264,               /* BOOLCONST  */
    BOOL = 265,                    /* BOOL  */
    INT = 266,                     /* INT  */
    CHAR = 267,                    /* CHAR  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    FOR = 272,                     /* FOR  */
    DO = 273,                      /* DO  */
    TO = 274,                      /* TO  */
    BY = 275,                      /* BY  */
    RETURN = 276,                  /* RETURN  */
    BREAK = 277,                   /* BREAK  */
    OR = 278,                      /* OR  */
    AND = 279,                     /* AND  */
    NOT = 280,                     /* NOT  */
    STATIC = 281,                  /* STATIC  */
    SEMI = 282,                    /* SEMI  */
    COMMA = 283,                   /* COMMA  */
    COLON = 284,                   /* COLON  */
    LBRACK = 285,                  /* LBRACK  */
    RBRACK = 286,                  /* RBRACK  */
    LCURL = 287,                   /* LCURL  */
    RCURL = 288,                   /* RCURL  */
    INC = 289,                     /* INC  */
    DEC = 290,                     /* DEC  */
    ADDASS = 291,                  /* ADDASS  */
    DECASS = 292,                  /* DECASS  */
    MULASS = 293,                  /* MULASS  */
    DIVASS = 294,                  /* DIVASS  */
    LEQ = 295,                     /* LEQ  */
    GEQ = 296,                     /* GEQ  */
    LESS = 297,                    /* LESS  */
    GREATER = 298,                 /* GREATER  */
    EQ = 299,                      /* EQ  */
    NEQ = 300,                     /* NEQ  */
    ADD = 301,                     /* ADD  */
    SUB = 302,                     /* SUB  */
    MUL = 303,                     /* MUL  */
    DIV = 304,                     /* DIV  */
    MOD = 305,                     /* MOD  */
    QMARK = 306,                   /* QMARK  */
    ASSIGN = 307,                  /* ASSIGN  */
    LPAREN = 308,                  /* LPAREN  */
    RPAREN = 309                   /* RPAREN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    ExpType type;
    TokenData *tokenData;
    treeNode *tree;

#line 124 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
