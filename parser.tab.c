/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

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


#line 95 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SIZEOF = 3,                     /* SIZEOF  */
  YYSYMBOL_CHSIGN = 4,                     /* CHSIGN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_NUMCONST = 6,                   /* NUMCONST  */
  YYSYMBOL_CHARCONST = 7,                  /* CHARCONST  */
  YYSYMBOL_STRINGCONST = 8,                /* STRINGCONST  */
  YYSYMBOL_BOOLCONST = 9,                  /* BOOLCONST  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_TO = 19,                        /* TO  */
  YYSYMBOL_BY = 20,                        /* BY  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_BREAK = 22,                     /* BREAK  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_STATIC = 26,                    /* STATIC  */
  YYSYMBOL_SEMI = 27,                      /* SEMI  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_COLON = 29,                     /* COLON  */
  YYSYMBOL_LBRACK = 30,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 31,                    /* RBRACK  */
  YYSYMBOL_LCURL = 32,                     /* LCURL  */
  YYSYMBOL_RCURL = 33,                     /* RCURL  */
  YYSYMBOL_INC = 34,                       /* INC  */
  YYSYMBOL_DEC = 35,                       /* DEC  */
  YYSYMBOL_ADDASS = 36,                    /* ADDASS  */
  YYSYMBOL_DECASS = 37,                    /* DECASS  */
  YYSYMBOL_MULASS = 38,                    /* MULASS  */
  YYSYMBOL_DIVASS = 39,                    /* DIVASS  */
  YYSYMBOL_LEQ = 40,                       /* LEQ  */
  YYSYMBOL_GEQ = 41,                       /* GEQ  */
  YYSYMBOL_LESS = 42,                      /* LESS  */
  YYSYMBOL_GREATER = 43,                   /* GREATER  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_NEQ = 45,                       /* NEQ  */
  YYSYMBOL_ADD = 46,                       /* ADD  */
  YYSYMBOL_SUB = 47,                       /* SUB  */
  YYSYMBOL_MUL = 48,                       /* MUL  */
  YYSYMBOL_DIV = 49,                       /* DIV  */
  YYSYMBOL_MOD = 50,                       /* MOD  */
  YYSYMBOL_QMARK = 51,                     /* QMARK  */
  YYSYMBOL_ASSIGN = 52,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 53,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 54,                    /* RPAREN  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_declist = 57,                   /* declist  */
  YYSYMBOL_decl = 58,                      /* decl  */
  YYSYMBOL_varDecl = 59,                   /* varDecl  */
  YYSYMBOL_scopedVarDecl = 60,             /* scopedVarDecl  */
  YYSYMBOL_varDeclList = 61,               /* varDeclList  */
  YYSYMBOL_varDeclInit = 62,               /* varDeclInit  */
  YYSYMBOL_varDeclID = 63,                 /* varDeclID  */
  YYSYMBOL_typeSpec = 64,                  /* typeSpec  */
  YYSYMBOL_funDecl = 65,                   /* funDecl  */
  YYSYMBOL_params = 66,                    /* params  */
  YYSYMBOL_paramList = 67,                 /* paramList  */
  YYSYMBOL_paramTypeList = 68,             /* paramTypeList  */
  YYSYMBOL_paramIDList = 69,               /* paramIDList  */
  YYSYMBOL_paramID = 70,                   /* paramID  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_openStatement = 72,             /* openStatement  */
  YYSYMBOL_closedStatement = 73,           /* closedStatement  */
  YYSYMBOL_openSelectStatement = 74,       /* openSelectStatement  */
  YYSYMBOL_closedSelectStatement = 75,     /* closedSelectStatement  */
  YYSYMBOL_simpleStatement = 76,           /* simpleStatement  */
  YYSYMBOL_expStmt = 77,                   /* expStmt  */
  YYSYMBOL_compoundStmt = 78,              /* compoundStmt  */
  YYSYMBOL_LocalDecls = 79,                /* LocalDecls  */
  YYSYMBOL_stmtList = 80,                  /* stmtList  */
  YYSYMBOL_openItrStmt = 81,               /* openItrStmt  */
  YYSYMBOL_closedItrStmt = 82,             /* closedItrStmt  */
  YYSYMBOL_itrRange = 83,                  /* itrRange  */
  YYSYMBOL_returnStmt = 84,                /* returnStmt  */
  YYSYMBOL_breakStmt = 85,                 /* breakStmt  */
  YYSYMBOL_exp = 86,                       /* exp  */
  YYSYMBOL_assignop = 87,                  /* assignop  */
  YYSYMBOL_simpleExp = 88,                 /* simpleExp  */
  YYSYMBOL_andExp = 89,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 90,               /* unaryRelExp  */
  YYSYMBOL_relExp = 91,                    /* relExp  */
  YYSYMBOL_relop = 92,                     /* relop  */
  YYSYMBOL_sumExp = 93,                    /* sumExp  */
  YYSYMBOL_sumop = 94,                     /* sumop  */
  YYSYMBOL_mulExp = 95,                    /* mulExp  */
  YYSYMBOL_mulop = 96,                     /* mulop  */
  YYSYMBOL_unaryExp = 97,                  /* unaryExp  */
  YYSYMBOL_unaryOp = 98,                   /* unaryOp  */
  YYSYMBOL_chsign = 99,                    /* chsign  */
  YYSYMBOL_sizeof = 100,                   /* sizeof  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_mutable = 102,                  /* mutable  */
  YYSYMBOL_immutable = 103,                /* immutable  */
  YYSYMBOL_call = 104,                     /* call  */
  YYSYMBOL_args = 105,                     /* args  */
  YYSYMBOL_argList = 106,                  /* argList  */
  YYSYMBOL_constant = 107                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    44,    45,    48,    49,    50,    53,    54,
      55,    58,    59,    62,    63,    66,    67,    70,    71,    74,
      75,    76,    79,    80,    83,    84,    87,    88,    91,    94,
      95,    99,   100,   103,   104,   107,   108,   111,   112,   113,
     116,   117,   119,   122,   123,   124,   125,   128,   129,   132,
     135,   136,   139,   140,   143,   144,   149,   150,   155,   156,
     159,   160,   163,   166,   167,   168,   169,   171,   172,   173,
     174,   175,   178,   179,   182,   183,   186,   187,   190,   191,
     194,   195,   196,   197,   198,   199,   202,   203,   206,   207,
     210,   211,   214,   215,   216,   219,   220,   223,   224,   225,
     228,   231,   235,   236,   239,   240,   245,   246,   247,   250,
     253,   254,   257,   258,   261,   262,   263,   264
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SIZEOF", "CHSIGN",
  "ID", "NUMCONST", "CHARCONST", "STRINGCONST", "BOOLCONST", "BOOL", "INT",
  "CHAR", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO", "TO", "BY", "RETURN",
  "BREAK", "OR", "AND", "NOT", "STATIC", "SEMI", "COMMA", "COLON",
  "LBRACK", "RBRACK", "LCURL", "RCURL", "INC", "DEC", "ADDASS", "DECASS",
  "MULASS", "DIVASS", "LEQ", "GEQ", "LESS", "GREATER", "EQ", "NEQ", "ADD",
  "SUB", "MUL", "DIV", "MOD", "QMARK", "ASSIGN", "LPAREN", "RPAREN",
  "$accept", "program", "declist", "decl", "varDecl", "scopedVarDecl",
  "varDeclList", "varDeclInit", "varDeclID", "typeSpec", "funDecl",
  "params", "paramList", "paramTypeList", "paramIDList", "paramID", "stmt",
  "openStatement", "closedStatement", "openSelectStatement",
  "closedSelectStatement", "simpleStatement", "expStmt", "compoundStmt",
  "LocalDecls", "stmtList", "openItrStmt", "closedItrStmt", "itrRange",
  "returnStmt", "breakStmt", "exp", "assignop", "simpleExp", "andExp",
  "unaryRelExp", "relExp", "relop", "sumExp", "sumop", "mulExp", "mulop",
  "unaryExp", "unaryOp", "chsign", "sizeof", "factor", "mutable",
  "immutable", "call", "args", "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     144,     9,   -33,  -149,  -149,  -149,     7,   101,  -149,  -149,
      46,  -149,     4,    45,  -149,    12,    73,  -149,  -149,    22,
     -20,    53,    60,  -149,     9,   155,    64,    21,    51,  -149,
    -149,    73,  -149,    56,  -149,    -7,  -149,  -149,  -149,  -149,
     155,  -149,  -149,  -149,   155,    67,    76,  -149,  -149,   141,
      80,  -149,   162,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
      77,    95,  -149,   105,    73,    71,  -149,   155,   155,  -149,
      84,    67,    58,   155,   155,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,   162,   162,  -149,  -149,  -149,   162,  -149,
     109,    64,  -149,  -149,  -149,   105,   110,  -149,    90,   122,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   155,    76,
    -149,    57,    80,  -149,  -149,  -149,    42,  -149,  -149,  -149,
     155,  -149,    73,  -149,     9,    23,  -149,     9,    87,   155,
     155,   152,    10,   132,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   138,    93,
    -149,   158,   -10,   114,  -149,   148,  -149,  -149,  -149,   126,
     126,   155,  -149,  -149,   161,  -149,  -149,   160,    41,   126,
     126,   155,  -149,  -149,  -149,  -149,    39,   155,    67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     0,    20,    19,    21,     0,     0,     4,     5,
       0,     6,    17,     0,    14,    15,    25,     1,     3,     0,
      17,     0,     0,     9,     0,     0,     0,     0,    24,    27,
      10,    25,     8,     0,    13,   104,   114,   115,   116,   117,
       0,   100,   101,    99,     0,    16,    73,    75,    77,    79,
      87,    91,     0,    97,    98,    96,   102,   103,   107,   108,
      31,    28,    30,     0,     0,     0,    18,     0,   111,    76,
       0,    66,   102,     0,     0,    81,    83,    80,    82,    84,
      85,    88,    89,     0,     0,    92,    93,    94,     0,    95,
       0,     0,    51,    23,    26,     0,     0,   113,     0,   110,
     106,    64,    65,    68,    69,    70,    71,    67,     0,    72,
      74,    78,    86,    90,    32,    29,    53,    22,   105,   109,
       0,    63,     0,    50,     0,     0,   112,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    52,    33,    34,    36,
      37,    39,    43,    44,    35,    38,    46,    45,     0,     0,
      12,     0,     0,     0,    60,     0,    62,    47,    11,     0,
       0,     0,    61,    40,    34,    54,    56,     0,     0,     0,
       0,     0,    41,    42,    55,    57,    58,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,   182,  -149,  -149,    -5,   166,  -149,     2,
    -149,   163,  -149,   127,  -149,   102,    33,  -148,   -61,  -149,
    -149,  -149,  -149,   -52,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,   -41,  -149,   -25,   123,   -36,  -149,  -149,   112,  -149,
     113,  -149,   -46,  -149,  -149,  -149,  -149,   -43,  -149,  -149,
    -149,  -149,  -149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   123,    13,    14,    15,    26,
      11,    27,    28,    29,    61,    62,   136,   137,   138,   139,
     140,   141,   142,   143,   116,   125,   144,   145,   167,   146,
     147,   148,   108,    71,    46,    47,    48,    83,    49,    84,
      50,    88,    51,    52,    53,    54,    55,    56,    57,    58,
      98,    99,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    72,    10,    70,    69,    21,    89,    17,   160,    10,
      22,    93,   165,    73,    12,    35,    36,    37,    38,    39,
      16,   172,   174,    67,    72,    72,    96,    97,    35,    36,
      37,    38,    39,    31,    22,    40,   129,   154,   110,   130,
     131,    25,   113,   117,   132,   133,    68,    19,    40,    30,
     134,    20,     3,     4,     5,    92,   135,    41,    42,   177,
     171,    43,    73,    44,    73,    72,    33,   121,   122,    60,
      41,    42,    23,    24,    43,    63,    44,    72,    64,   126,
      32,    24,    72,     3,     4,     5,    72,    66,   151,    72,
      73,   155,   101,   102,   103,   104,   105,   106,   164,   166,
      74,    -2,     1,    81,    82,   152,     2,    90,   173,   175,
     107,     3,     4,     5,   150,    24,    72,    72,   124,   128,
     158,    24,   149,    91,   127,    95,    72,    72,    85,    86,
      87,    35,    36,    37,    38,    39,   168,    92,   100,   129,
     114,   118,   130,   131,   119,     1,   176,   132,   133,     2,
     120,    40,   178,   134,     3,     4,     5,   153,    92,   156,
      35,    36,    37,    38,    39,   157,   161,    35,    36,    37,
      38,    39,   159,    41,    42,   162,   169,    43,   170,    44,
      40,    75,    76,    77,    78,    79,    80,    81,    82,    18,
      34,    94,   163,   115,    65,   111,   109,   112,     0,     0,
       0,     0,    41,    42,     0,     0,    43,     0,    44,    41,
      42,     0,     0,    43,     0,    44
};

static const yytype_int16 yycheck[] =
{
      25,    44,     0,    44,    40,    10,    52,     0,    18,     7,
      30,    63,   160,    23,     5,     5,     6,     7,     8,     9,
      53,   169,   170,    30,    67,    68,    67,    68,     5,     6,
       7,     8,     9,    53,    30,    25,    13,    27,    74,    16,
      17,    29,    88,    95,    21,    22,    53,     1,    25,    27,
      27,     5,    10,    11,    12,    32,    33,    47,    48,    20,
      19,    51,    23,    53,    23,   108,     6,   108,    26,     5,
      47,    48,    27,    28,    51,    54,    53,   120,    27,   120,
      27,    28,   125,    10,    11,    12,   129,    31,   129,   132,
      23,   132,    34,    35,    36,    37,    38,    39,   159,   160,
      24,     0,     1,    46,    47,   130,     5,    30,   169,   170,
      52,    10,    11,    12,    27,    28,   159,   160,   116,   124,
      27,    28,   127,    28,   122,    54,   169,   170,    48,    49,
      50,     5,     6,     7,     8,     9,   161,    32,    54,    13,
      31,    31,    16,    17,    54,     1,   171,    21,    22,     5,
      28,    25,   177,    27,    10,    11,    12,     5,    32,    27,
       5,     6,     7,     8,     9,    27,    52,     5,     6,     7,
       8,     9,    14,    47,    48,    27,    15,    51,    18,    53,
      25,    40,    41,    42,    43,    44,    45,    46,    47,     7,
      24,    64,   159,    91,    31,    83,    73,    84,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    -1,    53,    47,
      48,    -1,    -1,    51,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    10,    11,    12,    56,    57,    58,    59,
      64,    65,     5,    61,    62,    63,    53,     0,    58,     1,
       5,    61,    30,    27,    28,    29,    64,    66,    67,    68,
      27,    53,    27,     6,    62,     5,     6,     7,     8,     9,
      25,    47,    48,    51,    53,    88,    89,    90,    91,    93,
      95,    97,    98,    99,   100,   101,   102,   103,   104,   107,
       5,    69,    70,    54,    27,    66,    31,    30,    53,    90,
      86,    88,   102,    23,    24,    40,    41,    42,    43,    44,
      45,    46,    47,    92,    94,    48,    49,    50,    96,    97,
      30,    28,    32,    78,    68,    54,    86,    86,   105,   106,
      54,    34,    35,    36,    37,    38,    39,    52,    87,    89,
      90,    93,    95,    97,    31,    70,    79,    78,    31,    54,
      28,    86,    26,    60,    64,    80,    86,    64,    61,    13,
      16,    17,    21,    22,    27,    33,    71,    72,    73,    74,
      75,    76,    77,    78,    81,    82,    84,    85,    86,    61,
      27,    86,    88,     5,    27,    86,    27,    27,    27,    14,
      18,    52,    27,    71,    73,    72,    73,    83,    88,    15,
      18,    19,    72,    73,    72,    73,    88,    20,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    75,    76,    76,    76,    76,    77,    77,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    97,    97,    98,    98,    98,
      99,   100,   101,   101,   102,   102,   103,   103,   103,   104,
     105,   105,   106,   106,   107,   107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     3,     3,     1,     1,     3,     1,     4,     1,
       1,     1,     6,     5,     1,     0,     3,     1,     2,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     6,     1,     1,     1,     1,     2,     1,     4,
       2,     0,     2,     0,     4,     6,     4,     6,     3,     5,
       2,     3,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     1,     4,
       1,     0,     3,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declist  */
#line 41 "parser.y"
                        {/*printf("accept Program\n");*/ GLOBAL_HEAD = (yyvsp[0].tree);}
#line 1601 "parser.tab.c"
    break;

  case 3: /* declist: declist decl  */
#line 44 "parser.y"
                        {(yyvsp[-1].tree)-> addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}
#line 1607 "parser.tab.c"
    break;

  case 4: /* declist: decl  */
#line 45 "parser.y"
                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1613 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 48 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1619 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 49 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1625 "parser.tab.c"
    break;

  case 7: /* decl: error  */
#line 50 "parser.y"
                   {(yyval.tree) = NULL;}
#line 1631 "parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMI  */
#line 53 "parser.y"
                                     {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true); (yyval.tree)=(yyvsp[-1].tree);}
#line 1637 "parser.tab.c"
    break;

  case 9: /* varDecl: error varDeclList SEMI  */
#line 54 "parser.y"
                                     {(yyval.tree)=NULL; yyerrok;}
#line 1643 "parser.tab.c"
    break;

  case 10: /* varDecl: typeSpec error SEMI  */
#line 55 "parser.y"
                                  {(yyval.tree)=NULL; yyerrok; }
#line 1649 "parser.tab.c"
    break;

  case 11: /* scopedVarDecl: STATIC typeSpec varDeclList SEMI  */
#line 58 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true); (yyval.tree)=(yyvsp[-1].tree);}
#line 1655 "parser.tab.c"
    break;

  case 12: /* scopedVarDecl: typeSpec varDeclList SEMI  */
#line 59 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyval.tree)=(yyvsp[-1].tree); /*This might be wrong actually*/}
#line 1661 "parser.tab.c"
    break;

  case 13: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 62 "parser.y"
                                                 {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  }
#line 1667 "parser.tab.c"
    break;

  case 14: /* varDeclList: varDeclInit  */
#line 63 "parser.y"
                                                 {(yyval.tree)=(yyvsp[0].tree);}
#line 1673 "parser.tab.c"
    break;

  case 15: /* varDeclInit: varDeclID  */
#line 66 "parser.y"
                                               {(yyval.tree) = (yyvsp[0].tree);}
#line 1679 "parser.tab.c"
    break;

  case 16: /* varDeclInit: varDeclID COLON simpleExp  */
#line 67 "parser.y"
                                               {(yyvsp[-2].tree)->addChildren((yyvsp[0].tree), 0); (yyval.tree) = (yyvsp[-2].tree);}
#line 1685 "parser.tab.c"
    break;

  case 17: /* varDeclID: ID  */
#line 70 "parser.y"
                                                {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tokenData)); }
#line 1691 "parser.tab.c"
    break;

  case 18: /* varDeclID: ID LBRACK NUMCONST RBRACK  */
#line 71 "parser.y"
                                                {treeNode* node = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tokenData)); node->setArray(true); (yyval.tree) = node;}
#line 1697 "parser.tab.c"
    break;

  case 19: /* typeSpec: INT  */
#line 74 "parser.y"
                        {(yyval.type) = Integer;}
#line 1703 "parser.tab.c"
    break;

  case 20: /* typeSpec: BOOL  */
#line 75 "parser.y"
                        {(yyval.type) = boolean;}
#line 1709 "parser.tab.c"
    break;

  case 21: /* typeSpec: CHAR  */
#line 76 "parser.y"
                        {(yyval.type) = Char;}
#line 1715 "parser.tab.c"
    break;

  case 22: /* funDecl: typeSpec ID LPAREN params RPAREN compoundStmt  */
#line 79 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree),1); (yyval.tree)= node;}
#line 1721 "parser.tab.c"
    break;

  case 23: /* funDecl: ID LPAREN params RPAREN compoundStmt  */
#line 80 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, Void, (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree), 1); (yyval.tree)= node;}
#line 1727 "parser.tab.c"
    break;

  case 24: /* params: paramList  */
#line 83 "parser.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1733 "parser.tab.c"
    break;

  case 25: /* params: %empty  */
#line 84 "parser.y"
                                {(yyval.tree)= NULL;}
#line 1739 "parser.tab.c"
    break;

  case 26: /* paramList: paramList SEMI paramTypeList  */
#line 87 "parser.y"
                                                   {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 1745 "parser.tab.c"
    break;

  case 27: /* paramList: paramTypeList  */
#line 88 "parser.y"
                                                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1751 "parser.tab.c"
    break;

  case 28: /* paramTypeList: typeSpec paramIDList  */
#line 91 "parser.y"
                                                {(yyvsp[0].tree)->EType((yyvsp[-1].type)); (yyval.tree)=(yyvsp[0].tree); /*This might be wrong actually*/}
#line 1757 "parser.tab.c"
    break;

  case 29: /* paramIDList: paramIDList COMMA paramID  */
#line 94 "parser.y"
                                                {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  }
#line 1763 "parser.tab.c"
    break;

  case 30: /* paramIDList: paramID  */
#line 95 "parser.y"
                                                {(yyval.tree)=(yyvsp[0].tree);}
#line 1769 "parser.tab.c"
    break;

  case 31: /* paramID: ID  */
#line 99 "parser.y"
                                               {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tokenData)); }
#line 1775 "parser.tab.c"
    break;

  case 32: /* paramID: ID LBRACK RBRACK  */
#line 100 "parser.y"
                                               {treeNode* node = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tokenData)); node->setArray(true); (yyval.tree) = node;}
#line 1781 "parser.tab.c"
    break;

  case 33: /* stmt: openStatement  */
#line 103 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 1787 "parser.tab.c"
    break;

  case 34: /* stmt: closedStatement  */
#line 104 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 1793 "parser.tab.c"
    break;

  case 35: /* openStatement: openItrStmt  */
#line 107 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1799 "parser.tab.c"
    break;

  case 36: /* openStatement: openSelectStatement  */
#line 108 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1805 "parser.tab.c"
    break;

  case 37: /* closedStatement: closedSelectStatement  */
#line 111 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1811 "parser.tab.c"
    break;

  case 38: /* closedStatement: closedItrStmt  */
#line 112 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1817 "parser.tab.c"
    break;

  case 39: /* closedStatement: simpleStatement  */
#line 113 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1823 "parser.tab.c"
    break;

  case 40: /* openSelectStatement: IF exp THEN stmt  */
#line 116 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 1829 "parser.tab.c"
    break;

  case 41: /* openSelectStatement: IF exp THEN closedStatement ELSE openStatement  */
#line 117 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1835 "parser.tab.c"
    break;

  case 42: /* closedSelectStatement: IF exp THEN closedStatement ELSE closedStatement  */
#line 119 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1841 "parser.tab.c"
    break;

  case 43: /* simpleStatement: expStmt  */
#line 122 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1847 "parser.tab.c"
    break;

  case 44: /* simpleStatement: compoundStmt  */
#line 123 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1853 "parser.tab.c"
    break;

  case 45: /* simpleStatement: breakStmt  */
#line 124 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1859 "parser.tab.c"
    break;

  case 46: /* simpleStatement: returnStmt  */
#line 125 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1865 "parser.tab.c"
    break;

  case 47: /* expStmt: exp SEMI  */
#line 128 "parser.y"
                                    {(yyval.tree)=(yyvsp[-1].tree);}
#line 1871 "parser.tab.c"
    break;

  case 48: /* expStmt: SEMI  */
#line 129 "parser.y"
                                    {(yyval.tree)=NULL; /*WTF this porbably will break something i am sad wtf*/}
#line 1877 "parser.tab.c"
    break;

  case 49: /* compoundStmt: LCURL LocalDecls stmtList RCURL  */
#line 132 "parser.y"
                                                    {treeNode *node = newStmtNode(CompoundK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[-1].tree), NULL ); (yyval.tree)= node;}
#line 1883 "parser.tab.c"
    break;

  case 50: /* LocalDecls: LocalDecls scopedVarDecl  */
#line 135 "parser.y"
                                                    {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 1889 "parser.tab.c"
    break;

  case 51: /* LocalDecls: %empty  */
#line 136 "parser.y"
                                                     {(yyval.tree)= NULL;}
#line 1895 "parser.tab.c"
    break;

  case 52: /* stmtList: stmtList stmt  */
#line 139 "parser.y"
                                   {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 1901 "parser.tab.c"
    break;

  case 53: /* stmtList: %empty  */
#line 140 "parser.y"
                                   {(yyval.tree)= NULL;}
#line 1907 "parser.tab.c"
    break;

  case 54: /* openItrStmt: WHILE simpleExp DO openStatement  */
#line 143 "parser.y"
                                                        {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 1913 "parser.tab.c"
    break;

  case 55: /* openItrStmt: FOR ID ASSIGN itrRange DO openStatement  */
#line 144 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 1921 "parser.tab.c"
    break;

  case 56: /* closedItrStmt: WHILE simpleExp DO closedStatement  */
#line 149 "parser.y"
                                                         {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 1927 "parser.tab.c"
    break;

  case 57: /* closedItrStmt: FOR ID ASSIGN itrRange DO closedStatement  */
#line 150 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 1935 "parser.tab.c"
    break;

  case 58: /* itrRange: simpleExp TO simpleExp  */
#line 155 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 1941 "parser.tab.c"
    break;

  case 59: /* itrRange: simpleExp TO simpleExp BY simpleExp  */
#line 156 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-3].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1947 "parser.tab.c"
    break;

  case 60: /* returnStmt: RETURN SEMI  */
#line 159 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 1953 "parser.tab.c"
    break;

  case 61: /* returnStmt: RETURN exp SEMI  */
#line 160 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-2].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 1959 "parser.tab.c"
    break;

  case 62: /* breakStmt: BREAK SEMI  */
#line 163 "parser.y"
                                       {treeNode* node = newStmtNode(BreaK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 1965 "parser.tab.c"
    break;

  case 63: /* exp: mutable assignop exp  */
#line 166 "parser.y"
                                          {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 1971 "parser.tab.c"
    break;

  case 64: /* exp: mutable INC  */
#line 167 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 1977 "parser.tab.c"
    break;

  case 65: /* exp: mutable DEC  */
#line 168 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 1983 "parser.tab.c"
    break;

  case 66: /* exp: simpleExp  */
#line 169 "parser.y"
                                          {(yyval.tree)=(yyvsp[0].tree); /*not sure this is right either tbh*/}
#line 1989 "parser.tab.c"
    break;

  case 67: /* assignop: ASSIGN  */
#line 171 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Check yourself before you wreck yourself*/}
#line 1995 "parser.tab.c"
    break;

  case 68: /* assignop: ADDASS  */
#line 172 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /**/}
#line 2001 "parser.tab.c"
    break;

  case 69: /* assignop: DECASS  */
#line 173 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2007 "parser.tab.c"
    break;

  case 70: /* assignop: MULASS  */
#line 174 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2013 "parser.tab.c"
    break;

  case 71: /* assignop: DIVASS  */
#line 175 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2019 "parser.tab.c"
    break;

  case 72: /* simpleExp: simpleExp OR andExp  */
#line 178 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2025 "parser.tab.c"
    break;

  case 73: /* simpleExp: andExp  */
#line 179 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2031 "parser.tab.c"
    break;

  case 74: /* andExp: andExp AND unaryRelExp  */
#line 182 "parser.y"
                                            {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2037 "parser.tab.c"
    break;

  case 75: /* andExp: unaryRelExp  */
#line 183 "parser.y"
                                           {(yyval.tree)=(yyvsp[0].tree);}
#line 2043 "parser.tab.c"
    break;

  case 76: /* unaryRelExp: NOT unaryRelExp  */
#line 186 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree), NULL, NULL); (yyval.tree)=node; }
#line 2049 "parser.tab.c"
    break;

  case 77: /* unaryRelExp: relExp  */
#line 187 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2055 "parser.tab.c"
    break;

  case 78: /* relExp: sumExp relop sumExp  */
#line 190 "parser.y"
                                       {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2061 "parser.tab.c"
    break;

  case 79: /* relExp: sumExp  */
#line 191 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree);}
#line 2067 "parser.tab.c"
    break;

  case 80: /* relop: LESS  */
#line 194 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2073 "parser.tab.c"
    break;

  case 81: /* relop: LEQ  */
#line 195 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2079 "parser.tab.c"
    break;

  case 82: /* relop: GREATER  */
#line 196 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2085 "parser.tab.c"
    break;

  case 83: /* relop: GEQ  */
#line 197 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2091 "parser.tab.c"
    break;

  case 84: /* relop: EQ  */
#line 198 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2097 "parser.tab.c"
    break;

  case 85: /* relop: NEQ  */
#line 199 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2103 "parser.tab.c"
    break;

  case 86: /* sumExp: sumExp sumop mulExp  */
#line 202 "parser.y"
                                      {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2109 "parser.tab.c"
    break;

  case 87: /* sumExp: mulExp  */
#line 203 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree);}
#line 2115 "parser.tab.c"
    break;

  case 88: /* sumop: ADD  */
#line 206 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2121 "parser.tab.c"
    break;

  case 89: /* sumop: SUB  */
#line 207 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2127 "parser.tab.c"
    break;

  case 90: /* mulExp: mulExp mulop unaryExp  */
#line 210 "parser.y"
                                        {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2133 "parser.tab.c"
    break;

  case 91: /* mulExp: unaryExp  */
#line 211 "parser.y"
                               {(yyval.tree)=(yyvsp[0].tree);}
#line 2139 "parser.tab.c"
    break;

  case 92: /* mulop: MUL  */
#line 214 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2145 "parser.tab.c"
    break;

  case 93: /* mulop: DIV  */
#line 215 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2151 "parser.tab.c"
    break;

  case 94: /* mulop: MOD  */
#line 216 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2157 "parser.tab.c"
    break;

  case 95: /* unaryExp: unaryOp unaryExp  */
#line 219 "parser.y"
                                   {(yyvsp[-1].tree)->addChildren((yyvsp[0].tree),0); (yyval.tree)=(yyvsp[-1].tree);}
#line 2163 "parser.tab.c"
    break;

  case 96: /* unaryExp: factor  */
#line 220 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2169 "parser.tab.c"
    break;

  case 97: /* unaryOp: chsign  */
#line 223 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2175 "parser.tab.c"
    break;

  case 98: /* unaryOp: sizeof  */
#line 224 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2181 "parser.tab.c"
    break;

  case 99: /* unaryOp: QMARK  */
#line 225 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2187 "parser.tab.c"
    break;

  case 100: /* chsign: SUB  */
#line 228 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("chsign"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2194 "parser.tab.c"
    break;

  case 101: /* sizeof: MUL  */
#line 231 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("sizeof"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2201 "parser.tab.c"
    break;

  case 102: /* factor: mutable  */
#line 235 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2207 "parser.tab.c"
    break;

  case 103: /* factor: immutable  */
#line 236 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2213 "parser.tab.c"
    break;

  case 104: /* mutable: ID  */
#line 239 "parser.y"
                                             {treeNode* node = newExpNode(IdK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2219 "parser.tab.c"
    break;

  case 105: /* mutable: ID LBRACK exp RBRACK  */
#line 240 "parser.y"
                                            {
                                                treeNode* IDNode = newExpNode(IdK, (yyvsp[-3].tokenData), NULL, NULL, NULL);
                                                treeNode* node = newExpNode(OpK, (yyvsp[-2].tokenData), IDNode, (yyvsp[-1].tree), NULL); (yyval.tree)=node; /*Something is up with this one LOL*/ }
#line 2227 "parser.tab.c"
    break;

  case 106: /* immutable: LPAREN exp RPAREN  */
#line 245 "parser.y"
                                        {(yyval.tree)=(yyvsp[-1].tree);}
#line 2233 "parser.tab.c"
    break;

  case 107: /* immutable: call  */
#line 246 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2239 "parser.tab.c"
    break;

  case 108: /* immutable: constant  */
#line 247 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2245 "parser.tab.c"
    break;

  case 109: /* call: ID LPAREN args RPAREN  */
#line 250 "parser.y"
                                         {treeNode* node = newExpNode(CallK, (yyvsp[-3].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 2251 "parser.tab.c"
    break;

  case 110: /* args: argList  */
#line 253 "parser.y"
                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2257 "parser.tab.c"
    break;

  case 111: /* args: %empty  */
#line 254 "parser.y"
                           {(yyval.tree)=NULL;}
#line 2263 "parser.tab.c"
    break;

  case 112: /* argList: argList COMMA exp  */
#line 257 "parser.y"
                                    {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 2269 "parser.tab.c"
    break;

  case 113: /* argList: exp  */
#line 258 "parser.y"
                                {(yyval.tree)=(yyvsp[0].tree);}
#line 2275 "parser.tab.c"
    break;

  case 114: /* constant: NUMCONST  */
#line 261 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Integer), (yyval.tree)=node; }
#line 2281 "parser.tab.c"
    break;

  case 115: /* constant: CHARCONST  */
#line 262 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), (yyval.tree)=node; }
#line 2287 "parser.tab.c"
    break;

  case 116: /* constant: STRINGCONST  */
#line 263 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), node->setArray(true); (yyval.tree)=node; }
#line 2293 "parser.tab.c"
    break;

  case 117: /* constant: BOOLCONST  */
#line 264 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(boolean), (yyval.tree)=node; }
#line 2299 "parser.tab.c"
    break;


#line 2303 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 267 "parser.y"

