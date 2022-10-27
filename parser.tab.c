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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   865

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

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
      55,    58,    59,    64,    65,    66,    67,    70,    71,    72,
      75,    76,    77,    78,    81,    82,    83,    86,    87,    88,
      89,    90,    91,    94,    95,    98,    99,   100,   101,   104,
     105,   108,   109,   110,   111,   115,   116,   119,   120,   123,
     124,   127,   128,   129,   132,   133,   134,   135,   136,   138,
     139,   142,   143,   144,   145,   148,   149,   150,   153,   156,
     157,   160,   161,   164,   165,   168,   169,   170,   171,   175,
     176,   179,   180,   181,   182,   185,   186,   187,   188,   189,
     192,   193,   194,   197,   200,   201,   202,   203,   204,   205,
     206,   207,   210,   211,   212,   213,   214,   217,   218,   219,
     222,   223,   224,   227,   228,   229,   232,   233,   234,   237,
     238,   239,   240,   241,   242,   245,   246,   247,   250,   251,
     254,   255,   256,   259,   260,   261,   264,   265,   266,   269,
     270,   271,   274,   277,   281,   282,   285,   286,   291,   292,
     293,   294,   297,   298,   301,   302,   305,   306,   307,   310,
     311,   312,   313
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

#define YYPACT_NINF (-225)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-156)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     193,   129,     3,  -225,  -225,  -225,    41,   178,  -225,  -225,
      39,  -225,   130,    27,    60,  -225,    18,     6,  -225,  -225,
     143,    -1,    89,   159,  -225,    68,  -225,   123,   159,   -12,
     142,     5,    76,  -225,  -225,    11,  -225,    57,    40,  -225,
    -225,  -225,  -225,   345,  -225,  -225,  -225,   354,   113,   118,
    -225,  -225,   290,   205,  -225,   699,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,  -225,   114,   130,  -225,   113,   120,   132,
     141,  -225,    29,   121,   -12,    97,  -225,   375,   148,    57,
    -225,   811,   128,   113,    71,   405,   426,  -225,  -225,  -225,
    -225,  -225,  -225,  -225,  -225,   727,   736,  -225,  -225,  -225,
     748,    57,  -225,  -225,   144,   186,  -225,  -225,  -225,  -225,
    -225,   160,   811,   169,  -225,   154,   183,  -225,  -225,  -225,
    -225,  -225,  -225,  -225,   375,  -225,  -225,  -225,   435,    57,
     118,    57,  -225,    57,   190,    57,   205,    57,  -225,  -225,
    -225,  -225,   109,  -225,  -225,  -225,   456,  -225,   811,  -225,
     250,  -225,   192,   225,   811,  -225,   192,   221,   799,   486,
     507,   208,   320,   195,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,   197,   241,
    -225,  -225,   725,   226,    10,    63,   228,   199,   805,  -225,
     229,  -225,  -225,  -225,   258,   201,   291,   291,   291,   516,
    -225,  -225,   537,   567,   218,   255,   262,   588,   597,   224,
    -225,  -225,   269,  -225,  -225,  -225,  -225,    17,   268,   216,
     777,   273,    13,    77,  -225,   236,   258,   201,   771,   275,
      31,    78,  -225,   239,   291,   291,   292,   291,   618,   258,
     258,   258,   258,   648,  -225,  -225,   265,   291,   201,   201,
     669,  -225,  -225,  -225,  -225,  -225,  -225,  -225,    57,     4,
     279,    25,   277,   262,   286,    28,   284,   678,   258,   258,
     258,   201,   201,   201,    57,   113
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    25,    24,    26,     0,     0,     4,     5,
       0,     6,    16,    20,     0,    14,    17,     0,     1,     3,
      29,    20,     0,     0,    23,     0,     9,     0,     0,    31,
       0,     0,    33,    36,    10,     0,     8,     0,   146,   159,
     160,   161,   162,     0,   142,   143,   141,     0,    19,   108,
     111,   114,   117,   126,   131,     0,   139,   140,   137,   144,
     145,   149,   150,    22,     0,    15,    13,    18,    40,    45,
      39,    42,     0,     0,    30,     0,   153,     0,     0,   115,
     113,   151,     0,    97,   144,     0,     0,   120,   122,   119,
     121,   123,   124,   128,   129,     0,     0,   133,   134,   135,
       0,   138,   136,    21,     0,     0,    32,    70,    28,    37,
      35,     0,     0,     0,   157,     0,   154,   100,   101,   103,
     104,   105,   106,   102,     0,   148,    95,    96,     0,   109,
     107,   112,   110,   118,   116,   127,   125,   132,   130,    46,
      43,    41,    72,    27,   147,   152,     0,    98,    99,    94,
       0,    69,     0,     0,   158,   156,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    71,    47,    48,    50,
      51,    53,    61,    62,    49,    52,    64,    63,     0,     0,
      12,    66,    56,     0,    77,     0,    75,     0,     0,    90,
       0,    93,    65,    11,     0,     0,     0,     0,     0,     0,
      92,    91,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    54,    48,    78,    84,    73,    79,     0,     0,     0,
       0,     0,    83,     0,    81,     0,     0,     0,    56,     0,
      77,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    58,     0,     0,     0,     0,
       0,    55,    59,    76,    82,    88,    74,    80,    87,    85,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,  -225,   296,  -225,  -225,    -6,   283,  -225,     2,
    -225,   280,  -225,   244,  -225,   209,   166,  -159,  -143,  -225,
    -225,  -225,  -225,   -61,  -225,  -225,  -225,  -180,  -224,  -225,
    -225,   -44,   238,   -22,   235,   -35,  -225,  -225,   245,  -225,
     247,  -225,   -42,  -225,  -225,  -225,  -225,   -23,  -225,  -225,
    -225,  -225,  -225
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   151,    14,    15,    16,    30,
      11,    31,    32,    33,    70,    71,   211,   167,   205,   169,
     170,   171,   172,   173,   142,   153,   174,   175,   218,   176,
     177,   178,   124,    83,    49,    50,    51,    95,    52,    96,
      53,   100,    54,    55,    56,    57,    58,    84,    60,    61,
     115,   116,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    48,    10,    82,    22,    59,    67,    29,    80,    10,
     168,   108,    74,   102,   206,   -38,     3,     4,     5,   262,
      59,     3,     4,     5,   267,   -83,   266,    85,   197,    25,
     106,   241,    59,   113,   114,   235,   210,   236,   213,   215,
      20,    18,   -38,   269,    21,   236,   272,    28,   236,   248,
     143,   132,    35,   212,   214,   216,    17,    25,   138,    72,
     -34,   107,    59,    59,    76,   -34,   263,    76,   245,    63,
      77,    76,    59,    59,    64,   251,   253,    59,   256,    76,
     147,   198,    76,   244,   149,    76,    85,    26,    27,   213,
     215,   252,   254,    78,   257,   242,   249,   260,   214,   216,
      85,    85,   155,    73,   264,   126,   127,   119,   120,   121,
     122,    76,   251,   253,   256,   183,    36,    27,   190,     3,
       4,     5,   109,   123,    65,   252,   254,   257,    13,    -7,
      12,     3,     4,     5,    13,   150,    85,    59,   185,    -7,
      -7,    -7,    86,    68,   152,   103,   157,    69,   -44,   112,
     179,   111,   156,    38,    39,    40,    41,    42,   221,    23,
      37,    24,   104,   229,    38,    39,    40,    41,    42,   105,
      34,   -16,    23,    43,    24,   139,    59,   219,    -2,     1,
      59,   223,   125,     2,    43,    59,   231,   140,     3,     4,
       5,    69,   107,    12,     1,    44,    45,    13,     2,    46,
     144,    47,  -155,     3,     4,     5,    44,    45,   145,   186,
      46,   146,    47,   187,   207,    59,   259,   208,   209,   224,
      59,   219,   191,   225,   192,   232,   158,    59,   219,   233,
      38,    39,    40,    41,    42,   238,    93,    94,   159,    85,
     196,   160,   161,   -81,    59,   275,   162,   163,   180,    27,
      43,   199,   164,    97,    98,    99,   201,   107,   165,   158,
       3,     4,     5,    38,    39,    40,    41,    42,   193,    27,
     226,   202,    44,    45,   203,   204,    46,   227,    47,   162,
     163,   203,   204,    43,   234,   164,   237,   240,   243,   247,
     107,   250,   158,   255,   268,   270,    38,    39,    40,    41,
      42,   271,   273,    19,   159,    44,    45,   160,   161,    46,
      66,    47,   162,   163,   141,    75,    43,   110,   164,   166,
     130,   188,   128,   107,     0,    38,    39,    40,    41,    42,
      87,    88,    89,    90,    91,    92,    93,    94,    44,    45,
     134,     0,    46,   136,    47,    43,    79,   189,     0,     0,
      38,    39,    40,    41,    42,    81,     0,     0,     0,    38,
      39,    40,    41,    42,     0,     0,     0,    44,    45,     0,
      43,    46,     0,    47,     0,     0,   112,     0,     0,    43,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,    46,     0,    47,     0,
      43,    44,    45,     0,     0,    46,   129,    47,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,    46,   131,    47,     0,
      43,    38,    39,    40,    41,    42,   148,     0,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,    43,    44,    45,     0,     0,    46,   154,    47,     0,
      43,    38,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,    46,     0,    47,
       0,    43,    44,    45,     0,     0,    46,   182,    47,     0,
       0,    38,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,    46,   184,    47,
       0,    43,    38,    39,    40,    41,    42,   217,     0,     0,
       0,    38,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,    43,    44,    45,     0,     0,    46,   220,    47,
       0,    43,    38,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,    46,     0,
      47,     0,    43,    44,    45,     0,     0,    46,   222,    47,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,    46,   228,
      47,     0,    43,    38,    39,    40,    41,    42,   230,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,    43,    44,    45,     0,     0,    46,   258,
      47,     0,    43,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,    46,
       0,    47,     0,    43,    44,    45,     0,     0,    46,   261,
      47,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,    46,
     265,    47,     0,    43,    38,    39,    40,    41,    42,   274,
       0,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,    43,    44,    45,     0,     0,    46,
     101,    47,     0,    43,    38,    39,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
      46,     0,    47,     0,     0,    44,    45,     0,   133,    46,
       0,    47,    38,    39,    40,    41,    42,   135,     0,   194,
     195,    38,    39,    40,    41,    42,    44,    45,     0,   137,
      46,     0,    47,    38,    39,    40,    41,    42,     0,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,   123,    46,    76,
      47,     0,     0,    44,    45,   246,   195,    46,     0,    47,
       0,   239,     0,     0,     0,    44,    45,     0,     0,    46,
       0,    47,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,   123,     0,    76,   181,     0,     0,   123,
       0,    76,   200,   117,   118,   119,   120,   121,   122,   117,
     118,   119,   120,   121,   122,   117,   118,   119,   120,   121,
     122,   123,     0,    76,     0,     0,     0,   123,     0,    76,
       0,     0,     0,   123,     0,    76
};

static const yytype_int16 yycheck[] =
{
      23,    23,     0,    47,    10,    28,    28,     1,    43,     7,
     153,    72,     1,    55,   194,    27,    10,    11,    12,   243,
      43,    10,    11,    12,    20,    15,   250,    23,    18,    30,
       1,    18,    55,    77,    78,    18,   195,    20,   197,   198,
       1,     0,    54,    18,     5,    20,    18,    29,    20,    18,
     111,    86,    53,   196,   197,   198,    53,    30,   100,    54,
      54,    32,    85,    86,    54,    54,   246,    54,   227,     1,
      30,    54,    95,    96,     6,   234,   235,   100,   237,    54,
     124,    18,    54,   226,   128,    54,    23,    27,    28,   248,
     249,   234,   235,    53,   237,    18,    18,   240,   241,   242,
      23,    23,   146,    27,   247,    34,    35,    36,    37,    38,
      39,    54,   271,   272,   273,   159,    27,    28,   162,    10,
      11,    12,     1,    52,     1,   268,   269,   270,     5,     0,
       1,    10,    11,    12,     5,    26,    23,   160,   160,    10,
      11,    12,    24,     1,   142,    31,   152,     5,    28,     1,
     156,    54,   150,     5,     6,     7,     8,     9,   202,    29,
       1,    31,    30,   207,     5,     6,     7,     8,     9,    28,
      27,    28,    29,    25,    31,    31,   199,   199,     0,     1,
     203,   203,    54,     5,    25,   208,   208,     1,    10,    11,
      12,     5,    32,     1,     1,    47,    48,     5,     5,    51,
      31,    53,    54,    10,    11,    12,    47,    48,    54,     1,
      51,    28,    53,     5,    13,   238,   238,    16,    17,     1,
     243,   243,    27,     5,    27,     1,     1,   250,   250,     5,
       5,     6,     7,     8,     9,    19,    46,    47,    13,    23,
      14,    16,    17,    15,   267,   267,    21,    22,    27,    28,
      25,    52,    27,    48,    49,    50,    27,    32,    33,     1,
      10,    11,    12,     5,     6,     7,     8,     9,    27,    28,
      15,    13,    47,    48,    16,    17,    51,    15,    53,    21,
      22,    16,    17,    25,    15,    27,    18,    14,    52,    14,
      32,    52,     1,     1,    15,    18,     5,     6,     7,     8,
       9,    15,    18,     7,    13,    47,    48,    16,    17,    51,
      27,    53,    21,    22,   105,    35,    25,    73,    27,   153,
      85,     1,    84,    32,    -1,     5,     6,     7,     8,     9,
      40,    41,    42,    43,    44,    45,    46,    47,    47,    48,
      95,    -1,    51,    96,    53,    25,     1,    27,    -1,    -1,
       5,     6,     7,     8,     9,     1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    47,    48,    -1,
      25,    51,    -1,    53,    -1,    -1,     1,    -1,    -1,    25,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    -1,    53,    -1,
      25,    47,    48,    -1,    -1,    51,     1,    53,    -1,    -1,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,     1,    53,    -1,
      25,     5,     6,     7,     8,     9,     1,    -1,    -1,    -1,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    47,    48,    -1,    -1,    51,     1,    53,    -1,
      25,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,    53,
      -1,    25,    47,    48,    -1,    -1,    51,     1,    53,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    51,     1,    53,
      -1,    25,     5,     6,     7,     8,     9,     1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    47,    48,    -1,    -1,    51,     1,    53,
      -1,    25,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,
      53,    -1,    25,    47,    48,    -1,    -1,    51,     1,    53,
      -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,     1,
      53,    -1,    25,     5,     6,     7,     8,     9,     1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    47,    48,    -1,    -1,    51,     1,
      53,    -1,    25,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,
      -1,    53,    -1,    25,    47,    48,    -1,    -1,    51,     1,
      53,    -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,
       1,    53,    -1,    25,     5,     6,     7,     8,     9,     1,
      -1,    -1,    -1,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    47,    48,    -1,    -1,    51,
       1,    53,    -1,    25,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      51,    -1,    53,    -1,    -1,    47,    48,    -1,     1,    51,
      -1,    53,     5,     6,     7,     8,     9,     1,    -1,    14,
      15,     5,     6,     7,     8,     9,    47,    48,    -1,     1,
      51,    -1,    53,     5,     6,     7,     8,     9,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    52,    51,    54,
      53,    -1,    -1,    47,    48,    14,    15,    51,    -1,    53,
      -1,    14,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    54,    27,    -1,    -1,    52,
      -1,    54,    27,    34,    35,    36,    37,    38,    39,    34,
      35,    36,    37,    38,    39,    34,    35,    36,    37,    38,
      39,    52,    -1,    54,    -1,    -1,    -1,    52,    -1,    54,
      -1,    -1,    -1,    52,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,    10,    11,    12,    56,    57,    58,    59,
      64,    65,     1,     5,    61,    62,    63,    53,     0,    58,
       1,     5,    61,    29,    31,    30,    27,    28,    29,     1,
      64,    66,    67,    68,    27,    53,    27,     1,     5,     6,
       7,     8,     9,    25,    47,    48,    51,    53,    88,    89,
      90,    91,    93,    95,    97,    98,    99,   100,   101,   102,
     103,   104,   107,     1,     6,     1,    62,    88,     1,     5,
      69,    70,    54,    27,     1,    66,    54,    30,    53,     1,
      90,     1,    86,    88,   102,    23,    24,    40,    41,    42,
      43,    44,    45,    46,    47,    92,    94,    48,    49,    50,
      96,     1,    97,    31,    30,    28,     1,    32,    78,     1,
      68,    54,     1,    86,    86,   105,   106,    34,    35,    36,
      37,    38,    39,    52,    87,    54,    34,    35,    87,     1,
      89,     1,    90,     1,    93,     1,    95,     1,    97,    31,
       1,    70,    79,    78,    31,    54,    28,    86,     1,    86,
      26,    60,    64,    80,     1,    86,    64,    61,     1,    13,
      16,    17,    21,    22,    27,    33,    71,    72,    73,    74,
      75,    76,    77,    78,    81,    82,    84,    85,    86,    61,
      27,    27,     1,    86,     1,    88,     1,     5,     1,    27,
      86,    27,    27,    27,    14,    15,    14,    18,    18,    52,
      27,    27,    13,    16,    17,    73,    82,    13,    16,    17,
      72,    71,    73,    72,    73,    72,    73,     1,    83,    88,
       1,    86,     1,    88,     1,     5,    15,    15,     1,    86,
       1,    88,     1,     5,    15,    18,    20,    18,    19,    14,
      14,    18,    18,    52,    73,    72,    14,    14,    18,    18,
      52,    72,    73,    72,    73,     1,    72,    73,     1,    88,
      73,     1,    83,    82,    73,     1,    83,    20,    15,    18,
      18,    15,    18,    18,     1,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    77,    77,    77,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    99,   100,   101,   101,   102,   102,   103,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     3,     3,     1,     3,     1,     1,     3,     3,
       1,     4,     3,     2,     1,     1,     1,     6,     5,     2,
       4,     3,     5,     1,     0,     3,     1,     3,     1,     2,
       2,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     2,     4,     6,     6,
       6,     1,     1,     1,     1,     2,     2,     1,     4,     2,
       0,     2,     0,     4,     6,     2,     6,     2,     4,     4,
       6,     2,     6,     2,     4,     3,     5,     3,     3,     5,
       2,     3,     3,     2,     3,     2,     2,     1,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     1,     3,     2,     1,     2,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     2,     4,     2,     1,     0,     3,     1,     3,     1,
       1,     1,     1
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
#line 1776 "parser.tab.c"
    break;

  case 3: /* declist: declist decl  */
#line 44 "parser.y"
                        {if((yyvsp[-1].tree)!=NULL) (yyvsp[-1].tree)-> addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}
#line 1782 "parser.tab.c"
    break;

  case 4: /* declist: decl  */
#line 45 "parser.y"
                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1788 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 48 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1794 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 49 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1800 "parser.tab.c"
    break;

  case 7: /* decl: error  */
#line 50 "parser.y"
                   {(yyval.tree) = NULL;}
#line 1806 "parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMI  */
#line 53 "parser.y"
                                     {if((yyvsp[-1].tree) != NULL){(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true);} (yyval.tree)=(yyvsp[-1].tree);}
#line 1812 "parser.tab.c"
    break;

  case 9: /* varDecl: error varDeclList SEMI  */
#line 54 "parser.y"
                                     {(yyval.tree)=NULL; yyerrok;}
#line 1818 "parser.tab.c"
    break;

  case 10: /* varDecl: typeSpec error SEMI  */
#line 55 "parser.y"
                                  {(yyval.tree)=NULL; yyerrok; }
#line 1824 "parser.tab.c"
    break;

  case 11: /* scopedVarDecl: STATIC typeSpec varDeclList SEMI  */
#line 58 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true); (yyval.tree)=(yyvsp[-1].tree); yyerrok;}
#line 1830 "parser.tab.c"
    break;

  case 12: /* scopedVarDecl: typeSpec varDeclList SEMI  */
#line 59 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyval.tree)=(yyvsp[-1].tree); yyerrok; /*This might be wrong actually*/}
#line 1836 "parser.tab.c"
    break;

  case 13: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 64 "parser.y"
                                                 {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree); yyerrok;}
#line 1842 "parser.tab.c"
    break;

  case 14: /* varDeclList: varDeclInit  */
#line 65 "parser.y"
                                                 {(yyval.tree)=(yyvsp[0].tree);}
#line 1848 "parser.tab.c"
    break;

  case 15: /* varDeclList: varDeclList COMMA error  */
#line 66 "parser.y"
                                                 {(yyval.tree)=NULL;}
#line 1854 "parser.tab.c"
    break;

  case 16: /* varDeclList: error  */
#line 67 "parser.y"
                                                 {(yyval.tree)=NULL;}
#line 1860 "parser.tab.c"
    break;

  case 17: /* varDeclInit: varDeclID  */
#line 70 "parser.y"
                                               {(yyval.tree) = (yyvsp[0].tree);}
#line 1866 "parser.tab.c"
    break;

  case 18: /* varDeclInit: varDeclID COLON simpleExp  */
#line 71 "parser.y"
                                               {(yyvsp[-2].tree)->addChildren((yyvsp[0].tree), 0); (yyval.tree) = (yyvsp[-2].tree);}
#line 1872 "parser.tab.c"
    break;

  case 19: /* varDeclInit: error COLON simpleExp  */
#line 72 "parser.y"
                                                    {(yyval.tree) = NULL; yyerrok; }
#line 1878 "parser.tab.c"
    break;

  case 20: /* varDeclID: ID  */
#line 75 "parser.y"
                                                {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tokenData)); }
#line 1884 "parser.tab.c"
    break;

  case 21: /* varDeclID: ID LBRACK NUMCONST RBRACK  */
#line 76 "parser.y"
                                                {treeNode* node = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tokenData)); node->setArray(true); (yyval.tree) = node;}
#line 1890 "parser.tab.c"
    break;

  case 22: /* varDeclID: ID LBRACK error  */
#line 77 "parser.y"
                                                {(yyval.tree)=NULL;}
#line 1896 "parser.tab.c"
    break;

  case 23: /* varDeclID: error RBRACK  */
#line 78 "parser.y"
                                                {(yyval.tree)=NULL; yyerrok;}
#line 1902 "parser.tab.c"
    break;

  case 24: /* typeSpec: INT  */
#line 81 "parser.y"
                        {(yyval.type) = Integer;}
#line 1908 "parser.tab.c"
    break;

  case 25: /* typeSpec: BOOL  */
#line 82 "parser.y"
                        {(yyval.type) = boolean;}
#line 1914 "parser.tab.c"
    break;

  case 26: /* typeSpec: CHAR  */
#line 83 "parser.y"
                        {(yyval.type) = Char;}
#line 1920 "parser.tab.c"
    break;

  case 27: /* funDecl: typeSpec ID LPAREN params RPAREN compoundStmt  */
#line 86 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree),1); (yyval.tree)= node;}
#line 1926 "parser.tab.c"
    break;

  case 28: /* funDecl: ID LPAREN params RPAREN compoundStmt  */
#line 87 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, Void, (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree), 1); (yyval.tree)= node;}
#line 1932 "parser.tab.c"
    break;

  case 29: /* funDecl: typeSpec error  */
#line 88 "parser.y"
                                                                  {(yyval.tree)=NULL;}
#line 1938 "parser.tab.c"
    break;

  case 30: /* funDecl: typeSpec ID LPAREN error  */
#line 89 "parser.y"
                                                                 {(yyval.tree)=NULL;}
#line 1944 "parser.tab.c"
    break;

  case 31: /* funDecl: ID LPAREN error  */
#line 90 "parser.y"
                                                                        {(yyval.tree)=NULL;}
#line 1950 "parser.tab.c"
    break;

  case 32: /* funDecl: ID LPAREN params RPAREN error  */
#line 91 "parser.y"
                                                                {(yyval.tree)=NULL;}
#line 1956 "parser.tab.c"
    break;

  case 33: /* params: paramList  */
#line 94 "parser.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1962 "parser.tab.c"
    break;

  case 34: /* params: %empty  */
#line 95 "parser.y"
                                {(yyval.tree)= NULL;}
#line 1968 "parser.tab.c"
    break;

  case 35: /* paramList: paramList SEMI paramTypeList  */
#line 98 "parser.y"
                                                   {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 1974 "parser.tab.c"
    break;

  case 36: /* paramList: paramTypeList  */
#line 99 "parser.y"
                                                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1980 "parser.tab.c"
    break;

  case 37: /* paramList: paramList SEMI error  */
#line 100 "parser.y"
                                                   {(yyval.tree)= NULL;}
#line 1986 "parser.tab.c"
    break;

  case 38: /* paramList: error  */
#line 101 "parser.y"
                                                   {(yyval.tree)= NULL;}
#line 1992 "parser.tab.c"
    break;

  case 39: /* paramTypeList: typeSpec paramIDList  */
#line 104 "parser.y"
                                                {if((yyvsp[0].tree) != NULL) (yyvsp[0].tree)->EType((yyvsp[-1].type)); (yyval.tree)=(yyvsp[0].tree); /*This might be wrong actually*/}
#line 1998 "parser.tab.c"
    break;

  case 40: /* paramTypeList: typeSpec error  */
#line 105 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 2004 "parser.tab.c"
    break;

  case 41: /* paramIDList: paramIDList COMMA paramID  */
#line 108 "parser.y"
                                                {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  yyerrok;}
#line 2010 "parser.tab.c"
    break;

  case 42: /* paramIDList: paramID  */
#line 109 "parser.y"
                                                {(yyval.tree)=(yyvsp[0].tree);}
#line 2016 "parser.tab.c"
    break;

  case 43: /* paramIDList: paramIDList COMMA error  */
#line 110 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 2022 "parser.tab.c"
    break;

  case 44: /* paramIDList: error  */
#line 111 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 2028 "parser.tab.c"
    break;

  case 45: /* paramID: ID  */
#line 115 "parser.y"
                                               {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tokenData)); }
#line 2034 "parser.tab.c"
    break;

  case 46: /* paramID: ID LBRACK RBRACK  */
#line 116 "parser.y"
                                               {treeNode* node = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tokenData)); node->setArray(true); (yyval.tree) = node;}
#line 2040 "parser.tab.c"
    break;

  case 47: /* stmt: openStatement  */
#line 119 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2046 "parser.tab.c"
    break;

  case 48: /* stmt: closedStatement  */
#line 120 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2052 "parser.tab.c"
    break;

  case 49: /* openStatement: openItrStmt  */
#line 123 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2058 "parser.tab.c"
    break;

  case 50: /* openStatement: openSelectStatement  */
#line 124 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2064 "parser.tab.c"
    break;

  case 51: /* closedStatement: closedSelectStatement  */
#line 127 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2070 "parser.tab.c"
    break;

  case 52: /* closedStatement: closedItrStmt  */
#line 128 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2076 "parser.tab.c"
    break;

  case 53: /* closedStatement: simpleStatement  */
#line 129 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2082 "parser.tab.c"
    break;

  case 54: /* openSelectStatement: IF exp THEN stmt  */
#line 132 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 2088 "parser.tab.c"
    break;

  case 55: /* openSelectStatement: IF exp THEN closedStatement ELSE openStatement  */
#line 133 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2094 "parser.tab.c"
    break;

  case 56: /* openSelectStatement: IF error  */
#line 134 "parser.y"
                                                                                {(yyval.tree)=NULL;}
#line 2100 "parser.tab.c"
    break;

  case 57: /* openSelectStatement: IF error ELSE openStatement  */
#line 135 "parser.y"
                                                                                {(yyval.tree) =NULL; yyerrok;}
#line 2106 "parser.tab.c"
    break;

  case 58: /* openSelectStatement: IF error THEN closedItrStmt ELSE openStatement  */
#line 136 "parser.y"
                                                                                {(yyval.tree)=NULL; yyerrok;}
#line 2112 "parser.tab.c"
    break;

  case 59: /* closedSelectStatement: IF exp THEN closedStatement ELSE closedStatement  */
#line 138 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2118 "parser.tab.c"
    break;

  case 60: /* closedSelectStatement: IF error THEN closedStatement ELSE closedStatement  */
#line 139 "parser.y"
                                                                                {(yyval.tree)=NULL; yyerrok;}
#line 2124 "parser.tab.c"
    break;

  case 61: /* simpleStatement: expStmt  */
#line 142 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2130 "parser.tab.c"
    break;

  case 62: /* simpleStatement: compoundStmt  */
#line 143 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2136 "parser.tab.c"
    break;

  case 63: /* simpleStatement: breakStmt  */
#line 144 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2142 "parser.tab.c"
    break;

  case 64: /* simpleStatement: returnStmt  */
#line 145 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2148 "parser.tab.c"
    break;

  case 65: /* expStmt: exp SEMI  */
#line 148 "parser.y"
                                    {(yyval.tree)=(yyvsp[-1].tree);}
#line 2154 "parser.tab.c"
    break;

  case 66: /* expStmt: error SEMI  */
#line 149 "parser.y"
                                    {(yyval.tree)=NULL; yyerrok;}
#line 2160 "parser.tab.c"
    break;

  case 67: /* expStmt: SEMI  */
#line 150 "parser.y"
                                    {(yyval.tree)=NULL; /*WTF this porbably will break something i am sad wtf*/}
#line 2166 "parser.tab.c"
    break;

  case 68: /* compoundStmt: LCURL LocalDecls stmtList RCURL  */
#line 153 "parser.y"
                                                    {treeNode *node = newStmtNode(CompoundK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[-1].tree), NULL ); (yyval.tree)= node; yyerrok;}
#line 2172 "parser.tab.c"
    break;

  case 69: /* LocalDecls: LocalDecls scopedVarDecl  */
#line 156 "parser.y"
                                                    {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 2178 "parser.tab.c"
    break;

  case 70: /* LocalDecls: %empty  */
#line 157 "parser.y"
                                                     {(yyval.tree)= NULL;}
#line 2184 "parser.tab.c"
    break;

  case 71: /* stmtList: stmtList stmt  */
#line 160 "parser.y"
                                   {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);} }
#line 2190 "parser.tab.c"
    break;

  case 72: /* stmtList: %empty  */
#line 161 "parser.y"
                                   {(yyval.tree)= NULL;}
#line 2196 "parser.tab.c"
    break;

  case 73: /* openItrStmt: WHILE simpleExp DO openStatement  */
#line 164 "parser.y"
                                                        {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 2202 "parser.tab.c"
    break;

  case 74: /* openItrStmt: FOR ID ASSIGN itrRange DO openStatement  */
#line 165 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 2210 "parser.tab.c"
    break;

  case 75: /* openItrStmt: FOR error  */
#line 168 "parser.y"
                                {(yyval.tree)=NULL;}
#line 2216 "parser.tab.c"
    break;

  case 76: /* openItrStmt: FOR ID ASSIGN error DO openStatement  */
#line 169 "parser.y"
                                                        {(yyval.tree)=NULL; yyerrok;}
#line 2222 "parser.tab.c"
    break;

  case 77: /* openItrStmt: WHILE error  */
#line 170 "parser.y"
                              {(yyval.tree)=NULL;}
#line 2228 "parser.tab.c"
    break;

  case 78: /* openItrStmt: WHILE error DO openStatement  */
#line 171 "parser.y"
                                               {(yyval.tree)=NULL; yyerrok;}
#line 2234 "parser.tab.c"
    break;

  case 79: /* closedItrStmt: WHILE simpleExp DO closedStatement  */
#line 175 "parser.y"
                                                         {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 2240 "parser.tab.c"
    break;

  case 80: /* closedItrStmt: FOR ID ASSIGN itrRange DO closedStatement  */
#line 176 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 2248 "parser.tab.c"
    break;

  case 81: /* closedItrStmt: FOR error  */
#line 179 "parser.y"
                                {(yyval.tree)=NULL;}
#line 2254 "parser.tab.c"
    break;

  case 82: /* closedItrStmt: FOR ID ASSIGN error DO closedStatement  */
#line 180 "parser.y"
                                                          {(yyval.tree)=NULL; yyerrok;}
#line 2260 "parser.tab.c"
    break;

  case 83: /* closedItrStmt: WHILE error  */
#line 181 "parser.y"
                              {(yyval.tree)=NULL;}
#line 2266 "parser.tab.c"
    break;

  case 84: /* closedItrStmt: WHILE error DO closedStatement  */
#line 182 "parser.y"
                                                 {(yyval.tree)=NULL; yyerrok;}
#line 2272 "parser.tab.c"
    break;

  case 85: /* itrRange: simpleExp TO simpleExp  */
#line 185 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 2278 "parser.tab.c"
    break;

  case 86: /* itrRange: simpleExp TO simpleExp BY simpleExp  */
#line 186 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-3].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2284 "parser.tab.c"
    break;

  case 87: /* itrRange: simpleExp TO error  */
#line 187 "parser.y"
                                     {(yyval.tree)=NULL;}
#line 2290 "parser.tab.c"
    break;

  case 88: /* itrRange: error BY error  */
#line 188 "parser.y"
                                     {(yyval.tree)=NULL; yyerrok;}
#line 2296 "parser.tab.c"
    break;

  case 89: /* itrRange: simpleExp TO simpleExp BY error  */
#line 189 "parser.y"
                                                  {(yyval.tree)=NULL;}
#line 2302 "parser.tab.c"
    break;

  case 90: /* returnStmt: RETURN SEMI  */
#line 192 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 2308 "parser.tab.c"
    break;

  case 91: /* returnStmt: RETURN exp SEMI  */
#line 193 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-2].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; yyerrok;}
#line 2314 "parser.tab.c"
    break;

  case 92: /* returnStmt: RETURN error SEMI  */
#line 194 "parser.y"
                                        {(yyval.tree)=NULL; yyerrok;}
#line 2320 "parser.tab.c"
    break;

  case 93: /* breakStmt: BREAK SEMI  */
#line 197 "parser.y"
                                       {treeNode* node = newStmtNode(BreaK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 2326 "parser.tab.c"
    break;

  case 94: /* exp: mutable assignop exp  */
#line 200 "parser.y"
                                          {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2332 "parser.tab.c"
    break;

  case 95: /* exp: mutable INC  */
#line 201 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 2338 "parser.tab.c"
    break;

  case 96: /* exp: mutable DEC  */
#line 202 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 2344 "parser.tab.c"
    break;

  case 97: /* exp: simpleExp  */
#line 203 "parser.y"
                                          {(yyval.tree)=(yyvsp[0].tree); /*not sure this is right either tbh*/}
#line 2350 "parser.tab.c"
    break;

  case 98: /* exp: error assignop exp  */
#line 204 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2356 "parser.tab.c"
    break;

  case 99: /* exp: mutable assignop error  */
#line 205 "parser.y"
                                          {(yyval.tree)=NULL; }
#line 2362 "parser.tab.c"
    break;

  case 100: /* exp: error INC  */
#line 206 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2368 "parser.tab.c"
    break;

  case 101: /* exp: error DEC  */
#line 207 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2374 "parser.tab.c"
    break;

  case 102: /* assignop: ASSIGN  */
#line 210 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Check yourself before you wreck yourself*/}
#line 2380 "parser.tab.c"
    break;

  case 103: /* assignop: ADDASS  */
#line 211 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /**/}
#line 2386 "parser.tab.c"
    break;

  case 104: /* assignop: DECASS  */
#line 212 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2392 "parser.tab.c"
    break;

  case 105: /* assignop: MULASS  */
#line 213 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2398 "parser.tab.c"
    break;

  case 106: /* assignop: DIVASS  */
#line 214 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2404 "parser.tab.c"
    break;

  case 107: /* simpleExp: simpleExp OR andExp  */
#line 217 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2410 "parser.tab.c"
    break;

  case 108: /* simpleExp: andExp  */
#line 218 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2416 "parser.tab.c"
    break;

  case 109: /* simpleExp: simpleExp OR error  */
#line 219 "parser.y"
                                        {(yyval.tree) = NULL;}
#line 2422 "parser.tab.c"
    break;

  case 110: /* andExp: andExp AND unaryRelExp  */
#line 222 "parser.y"
                                            {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2428 "parser.tab.c"
    break;

  case 111: /* andExp: unaryRelExp  */
#line 223 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2434 "parser.tab.c"
    break;

  case 112: /* andExp: andExp AND error  */
#line 224 "parser.y"
                                            {(yyval.tree) = NULL;}
#line 2440 "parser.tab.c"
    break;

  case 113: /* unaryRelExp: NOT unaryRelExp  */
#line 227 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree), NULL, NULL); (yyval.tree)=node; }
#line 2446 "parser.tab.c"
    break;

  case 114: /* unaryRelExp: relExp  */
#line 228 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2452 "parser.tab.c"
    break;

  case 115: /* unaryRelExp: NOT error  */
#line 229 "parser.y"
                                        {(yyval.tree)=NULL;}
#line 2458 "parser.tab.c"
    break;

  case 116: /* relExp: sumExp relop sumExp  */
#line 232 "parser.y"
                                       {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2464 "parser.tab.c"
    break;

  case 117: /* relExp: sumExp  */
#line 233 "parser.y"
                                       {(yyval.tree)=(yyvsp[0].tree);}
#line 2470 "parser.tab.c"
    break;

  case 118: /* relExp: sumExp relop error  */
#line 234 "parser.y"
                                       {(yyval.tree)=NULL;}
#line 2476 "parser.tab.c"
    break;

  case 119: /* relop: LESS  */
#line 237 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2482 "parser.tab.c"
    break;

  case 120: /* relop: LEQ  */
#line 238 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2488 "parser.tab.c"
    break;

  case 121: /* relop: GREATER  */
#line 239 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2494 "parser.tab.c"
    break;

  case 122: /* relop: GEQ  */
#line 240 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2500 "parser.tab.c"
    break;

  case 123: /* relop: EQ  */
#line 241 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2506 "parser.tab.c"
    break;

  case 124: /* relop: NEQ  */
#line 242 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2512 "parser.tab.c"
    break;

  case 125: /* sumExp: sumExp sumop mulExp  */
#line 245 "parser.y"
                                      {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2518 "parser.tab.c"
    break;

  case 126: /* sumExp: mulExp  */
#line 246 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree); }
#line 2524 "parser.tab.c"
    break;

  case 127: /* sumExp: sumExp sumop error  */
#line 247 "parser.y"
                                      {(yyval.tree)=NULL; }
#line 2530 "parser.tab.c"
    break;

  case 128: /* sumop: ADD  */
#line 250 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2536 "parser.tab.c"
    break;

  case 129: /* sumop: SUB  */
#line 251 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2542 "parser.tab.c"
    break;

  case 130: /* mulExp: mulExp mulop unaryExp  */
#line 254 "parser.y"
                                        {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1); (yyval.tree)=(yyvsp[-1].tree);}
#line 2548 "parser.tab.c"
    break;

  case 131: /* mulExp: unaryExp  */
#line 255 "parser.y"
                               {(yyval.tree)=(yyvsp[0].tree);}
#line 2554 "parser.tab.c"
    break;

  case 132: /* mulExp: mulExp mulop error  */
#line 256 "parser.y"
                                     {(yyval.tree)=NULL; }
#line 2560 "parser.tab.c"
    break;

  case 133: /* mulop: MUL  */
#line 259 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2566 "parser.tab.c"
    break;

  case 134: /* mulop: DIV  */
#line 260 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2572 "parser.tab.c"
    break;

  case 135: /* mulop: MOD  */
#line 261 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2578 "parser.tab.c"
    break;

  case 136: /* unaryExp: unaryOp unaryExp  */
#line 264 "parser.y"
                                   {(yyvsp[-1].tree)->addChildren((yyvsp[0].tree),0); (yyval.tree)=(yyvsp[-1].tree);}
#line 2584 "parser.tab.c"
    break;

  case 137: /* unaryExp: factor  */
#line 265 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2590 "parser.tab.c"
    break;

  case 138: /* unaryExp: unaryOp error  */
#line 266 "parser.y"
                                   {(yyval.tree)=NULL; }
#line 2596 "parser.tab.c"
    break;

  case 139: /* unaryOp: chsign  */
#line 269 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2602 "parser.tab.c"
    break;

  case 140: /* unaryOp: sizeof  */
#line 270 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2608 "parser.tab.c"
    break;

  case 141: /* unaryOp: QMARK  */
#line 271 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2614 "parser.tab.c"
    break;

  case 142: /* chsign: SUB  */
#line 274 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("chsign"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2621 "parser.tab.c"
    break;

  case 143: /* sizeof: MUL  */
#line 277 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("sizeof"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2628 "parser.tab.c"
    break;

  case 144: /* factor: mutable  */
#line 281 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2634 "parser.tab.c"
    break;

  case 145: /* factor: immutable  */
#line 282 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2640 "parser.tab.c"
    break;

  case 146: /* mutable: ID  */
#line 285 "parser.y"
                                             {treeNode* node = newExpNode(IdK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2646 "parser.tab.c"
    break;

  case 147: /* mutable: ID LBRACK exp RBRACK  */
#line 286 "parser.y"
                                            {
                                                treeNode* IDNode = newExpNode(IdK, (yyvsp[-3].tokenData), NULL, NULL, NULL);
                                                treeNode* node = newExpNode(OpK, (yyvsp[-2].tokenData), IDNode, (yyvsp[-1].tree), NULL); (yyval.tree)=node; /*Something is up with this one LOL*/ }
#line 2654 "parser.tab.c"
    break;

  case 148: /* immutable: LPAREN exp RPAREN  */
#line 291 "parser.y"
                                        {(yyval.tree)=(yyvsp[-1].tree); yyerrok;}
#line 2660 "parser.tab.c"
    break;

  case 149: /* immutable: call  */
#line 292 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2666 "parser.tab.c"
    break;

  case 150: /* immutable: constant  */
#line 293 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2672 "parser.tab.c"
    break;

  case 151: /* immutable: LPAREN error  */
#line 294 "parser.y"
                                        {(yyval.tree)=NULL; }
#line 2678 "parser.tab.c"
    break;

  case 152: /* call: ID LPAREN args RPAREN  */
#line 297 "parser.y"
                                         {treeNode* node = newExpNode(CallK, (yyvsp[-3].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 2684 "parser.tab.c"
    break;

  case 153: /* call: error RPAREN  */
#line 298 "parser.y"
                                    {(yyval.tree)=NULL; yyerrok; }
#line 2690 "parser.tab.c"
    break;

  case 154: /* args: argList  */
#line 301 "parser.y"
                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2696 "parser.tab.c"
    break;

  case 155: /* args: %empty  */
#line 302 "parser.y"
                           {(yyval.tree)=NULL;}
#line 2702 "parser.tab.c"
    break;

  case 156: /* argList: argList COMMA exp  */
#line 305 "parser.y"
                                    {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree); yyerrok;}
#line 2708 "parser.tab.c"
    break;

  case 157: /* argList: exp  */
#line 306 "parser.y"
                                {(yyval.tree)=(yyvsp[0].tree);}
#line 2714 "parser.tab.c"
    break;

  case 158: /* argList: argList COMMA error  */
#line 307 "parser.y"
                                      {(yyval.tree)=NULL;}
#line 2720 "parser.tab.c"
    break;

  case 159: /* constant: NUMCONST  */
#line 310 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Integer), (yyval.tree)=node; }
#line 2726 "parser.tab.c"
    break;

  case 160: /* constant: CHARCONST  */
#line 311 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), (yyval.tree)=node; }
#line 2732 "parser.tab.c"
    break;

  case 161: /* constant: STRINGCONST  */
#line 312 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), node->setArray(true); (yyval.tree)=node; }
#line 2738 "parser.tab.c"
    break;

  case 162: /* constant: BOOLCONST  */
#line 313 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(boolean), (yyval.tree)=node; }
#line 2744 "parser.tab.c"
    break;


#line 2748 "parser.tab.c"

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

#line 316 "parser.y"

