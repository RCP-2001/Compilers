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
#line 1 "parser.y"

#include "scanType.h"
#include <stdio.h>
#include <cstring>

double vars[26]; // this is just for caluclator lol

treeNode* GLOBAL_HEAD;

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMCONST = 4,                   /* NUMCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_STRINGCONST = 6,                /* STRINGCONST  */
  YYSYMBOL_BOOLCONST = 7,                  /* BOOLCONST  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_TO = 17,                        /* TO  */
  YYSYMBOL_BY = 18,                        /* BY  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_STATIC = 24,                    /* STATIC  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_LBRACK = 28,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 29,                    /* RBRACK  */
  YYSYMBOL_LCURL = 30,                     /* LCURL  */
  YYSYMBOL_RCURL = 31,                     /* RCURL  */
  YYSYMBOL_INC = 32,                       /* INC  */
  YYSYMBOL_DEC = 33,                       /* DEC  */
  YYSYMBOL_ADDASS = 34,                    /* ADDASS  */
  YYSYMBOL_DECASS = 35,                    /* DECASS  */
  YYSYMBOL_MULASS = 36,                    /* MULASS  */
  YYSYMBOL_DIVASS = 37,                    /* DIVASS  */
  YYSYMBOL_LEQ = 38,                       /* LEQ  */
  YYSYMBOL_GEQ = 39,                       /* GEQ  */
  YYSYMBOL_LESS = 40,                      /* LESS  */
  YYSYMBOL_GREATER = 41,                   /* GREATER  */
  YYSYMBOL_EQ = 42,                        /* EQ  */
  YYSYMBOL_NEQ = 43,                       /* NEQ  */
  YYSYMBOL_ADD = 44,                       /* ADD  */
  YYSYMBOL_SUB = 45,                       /* SUB  */
  YYSYMBOL_MUL = 46,                       /* MUL  */
  YYSYMBOL_DIV = 47,                       /* DIV  */
  YYSYMBOL_MOD = 48,                       /* MOD  */
  YYSYMBOL_QMARK = 49,                     /* QMARK  */
  YYSYMBOL_ASSIGN = 50,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 51,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 52,                    /* RPAREN  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_declist = 55,                   /* declist  */
  YYSYMBOL_decl = 56,                      /* decl  */
  YYSYMBOL_varDecl = 57,                   /* varDecl  */
  YYSYMBOL_scopedVarDecl = 58,             /* scopedVarDecl  */
  YYSYMBOL_varDeclList = 59,               /* varDeclList  */
  YYSYMBOL_varDeclInit = 60,               /* varDeclInit  */
  YYSYMBOL_varDeclID = 61,                 /* varDeclID  */
  YYSYMBOL_typeSpec = 62,                  /* typeSpec  */
  YYSYMBOL_funDecl = 63,                   /* funDecl  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_paramList = 65,                 /* paramList  */
  YYSYMBOL_paramTypeList = 66,             /* paramTypeList  */
  YYSYMBOL_paramIDList = 67,               /* paramIDList  */
  YYSYMBOL_paramID = 68,                   /* paramID  */
  YYSYMBOL_stmt = 69,                      /* stmt  */
  YYSYMBOL_openStatement = 70,             /* openStatement  */
  YYSYMBOL_closedStatement = 71,           /* closedStatement  */
  YYSYMBOL_openSelectStatement = 72,       /* openSelectStatement  */
  YYSYMBOL_closedSelectStatement = 73,     /* closedSelectStatement  */
  YYSYMBOL_simpleStatement = 74,           /* simpleStatement  */
  YYSYMBOL_expStmt = 75,                   /* expStmt  */
  YYSYMBOL_compoundStmt = 76,              /* compoundStmt  */
  YYSYMBOL_LocalDecls = 77,                /* LocalDecls  */
  YYSYMBOL_stmtList = 78,                  /* stmtList  */
  YYSYMBOL_openItrStmt = 79,               /* openItrStmt  */
  YYSYMBOL_closedItrStmt = 80,             /* closedItrStmt  */
  YYSYMBOL_itrRange = 81,                  /* itrRange  */
  YYSYMBOL_returnStmt = 82,                /* returnStmt  */
  YYSYMBOL_breakStmt = 83,                 /* breakStmt  */
  YYSYMBOL_exp = 84,                       /* exp  */
  YYSYMBOL_assignop = 85,                  /* assignop  */
  YYSYMBOL_simpleExp = 86,                 /* simpleExp  */
  YYSYMBOL_andExp = 87,                    /* andExp  */
  YYSYMBOL_unaryRelExp = 88,               /* unaryRelExp  */
  YYSYMBOL_relExp = 89,                    /* relExp  */
  YYSYMBOL_relop = 90,                     /* relop  */
  YYSYMBOL_sumExp = 91,                    /* sumExp  */
  YYSYMBOL_sumop = 92,                     /* sumop  */
  YYSYMBOL_mulExp = 93,                    /* mulExp  */
  YYSYMBOL_mulop = 94,                     /* mulop  */
  YYSYMBOL_unaryExp = 95,                  /* unaryExp  */
  YYSYMBOL_unaryOp = 96,                   /* unaryOp  */
  YYSYMBOL_CHSIGN = 97,                    /* CHSIGN  */
  YYSYMBOL_SIZEOF = 98,                    /* SIZEOF  */
  YYSYMBOL_factor = 99,                    /* factor  */
  YYSYMBOL_mutable = 100,                  /* mutable  */
  YYSYMBOL_immutable = 101,                /* immutable  */
  YYSYMBOL_call = 102,                     /* call  */
  YYSYMBOL_args = 103,                     /* args  */
  YYSYMBOL_argList = 104,                  /* argList  */
  YYSYMBOL_constant = 105                  /* constant  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    42,    43,    46,    47,    50,    53,    54,
      57,    58,    61,    62,    65,    66,    69,    70,    71,    74,
      75,    78,    79,    82,    83,    86,    89,    90,    94,    95,
      98,    99,   102,   103,   106,   107,   108,   111,   112,   114,
     117,   118,   119,   120,   123,   124,   127,   130,   131,   134,
     135,   138,   139,   142,   143,   146,   147,   150,   151,   154,
     157,   158,   159,   160,   162,   163,   164,   165,   166,   169,
     170,   173,   174,   177,   178,   181,   182,   185,   186,   187,
     188,   189,   190,   193,   194,   197,   198,   201,   202,   205,
     206,   207,   210,   211,   214,   215,   216,   219,   221,   224,
     225,   228,   229,   232,   233,   234,   237,   240,   241,   244,
     245,   248,   249,   250,   251
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMCONST",
  "CHARCONST", "STRINGCONST", "BOOLCONST", "BOOL", "INT", "CHAR", "IF",
  "THEN", "ELSE", "WHILE", "FOR", "DO", "TO", "BY", "RETURN", "BREAK",
  "OR", "AND", "NOT", "STATIC", "SEMI", "COMMA", "COLON", "LBRACK",
  "RBRACK", "LCURL", "RCURL", "INC", "DEC", "ADDASS", "DECASS", "MULASS",
  "DIVASS", "LEQ", "GEQ", "LESS", "GREATER", "EQ", "NEQ", "ADD", "SUB",
  "MUL", "DIV", "MOD", "QMARK", "ASSIGN", "LPAREN", "RPAREN", "$accept",
  "program", "declist", "decl", "varDecl", "scopedVarDecl", "varDeclList",
  "varDeclInit", "varDeclID", "typeSpec", "funDecl", "params", "paramList",
  "paramTypeList", "paramIDList", "paramID", "stmt", "openStatement",
  "closedStatement", "openSelectStatement", "closedSelectStatement",
  "simpleStatement", "expStmt", "compoundStmt", "LocalDecls", "stmtList",
  "openItrStmt", "closedItrStmt", "itrRange", "returnStmt", "breakStmt",
  "exp", "assignop", "simpleExp", "andExp", "unaryRelExp", "relExp",
  "relop", "sumExp", "sumop", "mulExp", "mulop", "unaryExp", "unaryOp",
  "CHSIGN", "SIZEOF", "factor", "mutable", "immutable", "call", "args",
  "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     140,   -45,   -81,   -81,   -81,    47,   140,   -81,   -81,    13,
     -81,   108,   -81,   -81,   -18,    66,   -81,    22,    49,    21,
      53,   -81,    76,   108,   -81,    91,    15,    78,    93,   -81,
      99,   108,   103,    89,   117,   -81,    -5,   -81,   -81,   -81,
     -81,    15,   -81,   -81,   -81,    15,   126,   129,   -81,   -81,
     115,   125,   -81,     8,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   134,    49,   -81,   -81,   -81,   -81,    99,    15,    15,
     -81,   122,   126,   102,    15,    15,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,     8,     8,   -81,   -81,   -81,     8,
     -81,   -81,   -81,    59,   -81,   146,   -81,   124,   143,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    15,   129,   -81,
      64,   125,   -81,   108,   -81,    91,    25,   -81,   -81,    15,
     -81,    91,   136,    15,    15,   174,   119,   153,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   154,   -81,   141,   -81,   168,   -12,   131,   -81,
     157,   -81,   -81,   -81,    82,    82,    15,   -81,   -81,   170,
     -81,   -81,   169,    41,    82,    82,    15,   -81,   -81,   -81,
     -81,    16,    15,   126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    17,    16,    18,     0,     2,     4,     5,     0,
       6,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     7,     0,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,   101,   111,   112,   113,
     114,     0,    97,    98,    96,     0,    13,    70,    72,    74,
      76,    84,    88,     0,    94,    95,    93,    99,   100,   104,
     105,     0,     0,    48,    20,    23,    15,     0,     0,   108,
      73,     0,    63,    99,     0,     0,    78,    80,    77,    79,
      81,    82,    85,    86,     0,     0,    89,    90,    91,     0,
      92,    29,    26,    50,    19,     0,   110,     0,   107,   103,
      61,    62,    65,    66,    67,    68,    64,     0,    69,    71,
      75,    83,    87,     0,    47,     0,     0,   102,   106,     0,
      60,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      49,    30,    31,    33,    34,    36,    40,    41,    32,    35,
      43,    42,     0,   109,     0,     9,     0,     0,     0,    57,
       0,    59,    44,     8,     0,     0,     0,    58,    37,    31,
      51,    53,     0,     0,     0,     0,     0,    38,    39,    52,
      54,    55,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   178,   -81,   -81,   -80,   161,   -81,     2,
     -81,   164,   -81,   158,   -81,   128,    34,   -65,   -51,   -81,
     -81,   -81,   -81,   -25,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -42,   -81,   -26,   118,   -24,   -81,   -81,   107,   -81,
     109,   -81,   -46,   -81,   -81,   -81,   -81,   -44,   -81,   -81,
     -81,   -81,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   114,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,   130,   131,   132,   133,
     134,   135,   136,   137,    93,   116,   138,   139,   162,   140,
     141,   142,   107,    72,    47,    48,    49,    84,    50,    85,
      51,    89,    52,    53,    54,    55,    56,    57,    58,    59,
      97,    98,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    73,     9,    71,   155,    64,    11,    90,     9,    74,
      22,    36,    37,    38,    39,    40,    14,    70,    36,    37,
      38,    39,    40,    68,    73,    73,    95,    96,    36,    37,
      38,    39,    40,    23,   172,   122,   123,    74,    41,   124,
     125,   144,    94,   112,   126,   127,    69,    12,    41,    26,
     128,   109,    27,    42,    43,    63,   129,    44,   166,    45,
      42,    43,    74,    73,    44,   120,    45,     2,     3,     4,
      42,    43,    73,    30,    44,    73,    45,   143,    31,    73,
      32,   146,    73,   113,   150,    36,    37,    38,    39,    40,
     160,    24,    25,   123,    34,   115,   124,   125,   147,   167,
     169,   126,   127,   159,   161,    41,    61,   128,    82,    83,
      73,    73,    63,   168,   170,   121,     2,     3,     4,    62,
      73,    73,    36,    37,    38,    39,    40,    42,    43,    63,
     163,    44,    66,    45,   100,   101,   102,   103,   104,   105,
     171,    67,    41,     1,   149,    22,   173,    74,     2,     3,
       4,    75,   106,    76,    77,    78,    79,    80,    81,    82,
      83,   145,    25,    91,    42,    43,   153,    25,    44,   119,
      45,    86,    87,    88,    99,   117,   118,   148,   151,   152,
     154,   156,   157,   164,    13,   165,    35,    33,   158,    65,
      92,   110,   108,     0,   111
};

static const yytype_int16 yycheck[] =
{
      26,    45,     0,    45,    16,    30,    51,    53,     6,    21,
      28,     3,     4,     5,     6,     7,     3,    41,     3,     4,
       5,     6,     7,    28,    68,    69,    68,    69,     3,     4,
       5,     6,     7,    51,    18,   115,    11,    21,    23,    14,
      15,   121,    67,    89,    19,    20,    51,     0,    23,    27,
      25,    75,     3,    45,    46,    30,    31,    49,    17,    51,
      45,    46,    21,   107,    49,   107,    51,     8,     9,    10,
      45,    46,   116,    52,    49,   119,    51,   119,    25,   123,
       4,   123,   126,    24,   126,     3,     4,     5,     6,     7,
     155,    25,    26,    11,     3,    93,    14,    15,   124,   164,
     165,    19,    20,   154,   155,    23,    28,    25,    44,    45,
     154,   155,    30,   164,   165,   113,     8,     9,    10,    26,
     164,   165,     3,     4,     5,     6,     7,    45,    46,    30,
     156,    49,    29,    51,    32,    33,    34,    35,    36,    37,
     166,    52,    23,     3,    25,    28,   172,    21,     8,     9,
      10,    22,    50,    38,    39,    40,    41,    42,    43,    44,
      45,    25,    26,    29,    45,    46,    25,    26,    49,    26,
      51,    46,    47,    48,    52,    29,    52,     3,    25,    25,
      12,    50,    25,    13,     6,    16,    25,    23,   154,    31,
      62,    84,    74,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    10,    54,    55,    56,    57,    62,
      63,    51,     0,    56,     3,    59,    60,    61,    62,    64,
      65,    66,    28,    51,    25,    26,    27,     3,    67,    68,
      52,    25,     4,    64,     3,    60,     3,     4,     5,     6,
       7,    23,    45,    46,    49,    51,    86,    87,    88,    89,
      91,    93,    95,    96,    97,    98,    99,   100,   101,   102,
     105,    28,    26,    30,    76,    66,    29,    52,    28,    51,
      88,    84,    86,   100,    21,    22,    38,    39,    40,    41,
      42,    43,    44,    45,    90,    92,    46,    47,    48,    94,
      95,    29,    68,    77,    76,    84,    84,   103,   104,    52,
      32,    33,    34,    35,    36,    37,    50,    85,    87,    88,
      91,    93,    95,    24,    58,    62,    78,    29,    52,    26,
      84,    62,    59,    11,    14,    15,    19,    20,    25,    31,
      69,    70,    71,    72,    73,    74,    75,    76,    79,    80,
      82,    83,    84,    84,    59,    25,    84,    86,     3,    25,
      84,    25,    25,    25,    12,    16,    50,    25,    69,    71,
      70,    71,    81,    86,    13,    16,    17,    70,    71,    70,
      71,    86,    18,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    72,    72,    73,
      74,    74,    74,    74,    75,    75,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    96,    97,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   103,   103,   104,
     104,   105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     3,
       3,     1,     1,     3,     1,     4,     1,     1,     1,     6,
       5,     1,     0,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     6,
       1,     1,     1,     1,     2,     1,     4,     2,     0,     2,
       0,     4,     6,     4,     6,     3,     5,     2,     3,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     4,     1,     0,     3,
       1,     1,     1,     1,     1
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
#line 39 "parser.y"
                        {printf("accept Program\n"); GLOBAL_HEAD = (yyvsp[0].tree);}
#line 1325 "parser.tab.c"
    break;

  case 3: /* declist: declist decl  */
#line 42 "parser.y"
                        {(yyvsp[-1].tree)-> addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}
#line 1331 "parser.tab.c"
    break;

  case 4: /* declist: decl  */
#line 43 "parser.y"
                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1337 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 46 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1343 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 47 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1349 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec varDeclList SEMI  */
#line 50 "parser.y"
                                     {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyval.tree)=(yyvsp[-1].tree);}
#line 1355 "parser.tab.c"
    break;

  case 8: /* scopedVarDecl: STATIC typeSpec varDeclList SEMI  */
#line 53 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true); (yyval.tree)=(yyvsp[-1].tree);}
#line 1361 "parser.tab.c"
    break;

  case 9: /* scopedVarDecl: typeSpec varDeclList SEMI  */
#line 54 "parser.y"
                                                    {(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyval.tree)=(yyvsp[-1].tree); /*This might be wrong actually*/}
#line 1367 "parser.tab.c"
    break;

  case 10: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 57 "parser.y"
                                                 {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  }
#line 1373 "parser.tab.c"
    break;

  case 11: /* varDeclList: varDeclInit  */
#line 58 "parser.y"
                                                 {(yyval.tree)=(yyvsp[0].tree);}
#line 1379 "parser.tab.c"
    break;

  case 12: /* varDeclInit: varDeclID  */
#line 61 "parser.y"
                                               {(yyval.tree) = (yyvsp[0].tree);}
#line 1385 "parser.tab.c"
    break;

  case 13: /* varDeclInit: varDeclID COLON simpleExp  */
#line 62 "parser.y"
                                               {(yyvsp[-2].tree)->addChildren((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);}
#line 1391 "parser.tab.c"
    break;

  case 14: /* varDeclID: ID  */
#line 65 "parser.y"
                                                {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tokenData)); }
#line 1397 "parser.tab.c"
    break;

  case 15: /* varDeclID: ID LBRACK NUMCONST RBRACK  */
#line 66 "parser.y"
                                                {treeNode* node = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tokenData)); node->isArray = true; (yyval.tree) = node;}
#line 1403 "parser.tab.c"
    break;

  case 16: /* typeSpec: INT  */
#line 69 "parser.y"
                        {(yyval.type) = Integer;}
#line 1409 "parser.tab.c"
    break;

  case 17: /* typeSpec: BOOL  */
#line 70 "parser.y"
                        {(yyval.type) = boolean;}
#line 1415 "parser.tab.c"
    break;

  case 18: /* typeSpec: CHAR  */
#line 71 "parser.y"
                        {(yyval.type) = Char;}
#line 1421 "parser.tab.c"
    break;

  case 19: /* funDecl: typeSpec ID LPAREN params RPAREN compoundStmt  */
#line 74 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree)); node-> addChildren((yyvsp[0].tree)); (yyval.tree)= node;}
#line 1427 "parser.tab.c"
    break;

  case 20: /* funDecl: ID LPAREN params RPAREN compoundStmt  */
#line 75 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, Void, (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree)); node-> addChildren((yyvsp[0].tree)); (yyval.tree)= node;}
#line 1433 "parser.tab.c"
    break;

  case 21: /* params: paramList  */
#line 78 "parser.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1439 "parser.tab.c"
    break;

  case 22: /* params: %empty  */
#line 79 "parser.y"
                                {(yyval.tree)= NULL;}
#line 1445 "parser.tab.c"
    break;

  case 23: /* paramList: paramList SEMI paramTypeList  */
#line 82 "parser.y"
                                                   {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 1451 "parser.tab.c"
    break;

  case 24: /* paramList: paramTypeList  */
#line 83 "parser.y"
                                                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1457 "parser.tab.c"
    break;

  case 25: /* paramTypeList: typeSpec paramIDList  */
#line 86 "parser.y"
                                                {(yyvsp[0].tree)->EType((yyvsp[-1].type)); (yyval.tree)=(yyvsp[0].tree); /*This might be wrong actually*/}
#line 1463 "parser.tab.c"
    break;

  case 26: /* paramIDList: paramIDList COMMA paramID  */
#line 89 "parser.y"
                                                {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  }
#line 1469 "parser.tab.c"
    break;

  case 27: /* paramIDList: paramID  */
#line 90 "parser.y"
                                                {(yyval.tree)=(yyvsp[0].tree);}
#line 1475 "parser.tab.c"
    break;

  case 28: /* paramID: ID  */
#line 94 "parser.y"
                                               {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tokenData)); }
#line 1481 "parser.tab.c"
    break;

  case 29: /* paramID: ID LBRACK RBRACK  */
#line 95 "parser.y"
                                               {treeNode* node = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tokenData)); node->isArray = true; (yyval.tree) = node;}
#line 1487 "parser.tab.c"
    break;

  case 30: /* stmt: openStatement  */
#line 98 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 1493 "parser.tab.c"
    break;

  case 31: /* stmt: closedStatement  */
#line 99 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 1499 "parser.tab.c"
    break;

  case 32: /* openStatement: openItrStmt  */
#line 102 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1505 "parser.tab.c"
    break;

  case 33: /* openStatement: openSelectStatement  */
#line 103 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1511 "parser.tab.c"
    break;

  case 34: /* closedStatement: closedSelectStatement  */
#line 106 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1517 "parser.tab.c"
    break;

  case 35: /* closedStatement: closedItrStmt  */
#line 107 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1523 "parser.tab.c"
    break;

  case 36: /* closedStatement: simpleStatement  */
#line 108 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 1529 "parser.tab.c"
    break;

  case 37: /* openSelectStatement: IF exp THEN stmt  */
#line 111 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 1535 "parser.tab.c"
    break;

  case 38: /* openSelectStatement: IF exp THEN closedStatement ELSE openStatement  */
#line 112 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1541 "parser.tab.c"
    break;

  case 39: /* closedSelectStatement: IF exp THEN closedStatement ELSE closedStatement  */
#line 114 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1547 "parser.tab.c"
    break;

  case 40: /* simpleStatement: expStmt  */
#line 117 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1553 "parser.tab.c"
    break;

  case 41: /* simpleStatement: compoundStmt  */
#line 118 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1559 "parser.tab.c"
    break;

  case 42: /* simpleStatement: breakStmt  */
#line 119 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1565 "parser.tab.c"
    break;

  case 43: /* simpleStatement: returnStmt  */
#line 120 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 1571 "parser.tab.c"
    break;

  case 44: /* expStmt: exp SEMI  */
#line 123 "parser.y"
                                    {(yyval.tree)=(yyvsp[-1].tree);}
#line 1577 "parser.tab.c"
    break;

  case 45: /* expStmt: SEMI  */
#line 124 "parser.y"
                                    {(yyval.tree)=NULL; /*WTF this porbably will break something i am sad wtf*/}
#line 1583 "parser.tab.c"
    break;

  case 46: /* compoundStmt: LCURL LocalDecls stmtList RCURL  */
#line 127 "parser.y"
                                                    {treeNode *node = newStmtNode(CompoundK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[-1].tree), NULL ); (yyval.tree)= node;}
#line 1589 "parser.tab.c"
    break;

  case 47: /* LocalDecls: LocalDecls scopedVarDecl  */
#line 130 "parser.y"
                                                    {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 1595 "parser.tab.c"
    break;

  case 48: /* LocalDecls: %empty  */
#line 131 "parser.y"
                                                     {(yyval.tree)= NULL;}
#line 1601 "parser.tab.c"
    break;

  case 49: /* stmtList: stmtList stmt  */
#line 134 "parser.y"
                                   {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 1607 "parser.tab.c"
    break;

  case 50: /* stmtList: %empty  */
#line 135 "parser.y"
                                   {(yyval.tree)= NULL;}
#line 1613 "parser.tab.c"
    break;

  case 51: /* openItrStmt: WHILE simpleExp DO openStatement  */
#line 138 "parser.y"
                                                        {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 1619 "parser.tab.c"
    break;

  case 52: /* openItrStmt: FOR ID ASSIGN itrRange DO openStatement  */
#line 139 "parser.y"
                                                            {treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), NULL, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 1625 "parser.tab.c"
    break;

  case 53: /* closedItrStmt: WHILE simpleExp DO closedStatement  */
#line 142 "parser.y"
                                                         {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 1631 "parser.tab.c"
    break;

  case 54: /* closedItrStmt: FOR ID ASSIGN itrRange DO closedStatement  */
#line 143 "parser.y"
                                                            {treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), NULL, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;   /*Totally wrong lmafo*/}
#line 1637 "parser.tab.c"
    break;

  case 55: /* itrRange: simpleExp TO simpleExp  */
#line 146 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 1643 "parser.tab.c"
    break;

  case 56: /* itrRange: simpleExp TO simpleExp BY simpleExp  */
#line 147 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-3].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 1649 "parser.tab.c"
    break;

  case 57: /* returnStmt: RETURN SEMI  */
#line 150 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 1655 "parser.tab.c"
    break;

  case 58: /* returnStmt: RETURN exp SEMI  */
#line 151 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-2].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 1661 "parser.tab.c"
    break;

  case 59: /* breakStmt: BREAK SEMI  */
#line 154 "parser.y"
                                       {treeNode* node = newStmtNode(ReturnK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 1667 "parser.tab.c"
    break;

  case 60: /* exp: mutable assignop exp  */
#line 157 "parser.y"
                                          {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree)); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-1].tree);}
#line 1673 "parser.tab.c"
    break;

  case 61: /* exp: mutable INC  */
#line 158 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 1679 "parser.tab.c"
    break;

  case 62: /* exp: mutable DEC  */
#line 159 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 1685 "parser.tab.c"
    break;

  case 63: /* exp: simpleExp  */
#line 160 "parser.y"
                                          {(yyval.tree)=(yyvsp[0].tree); /*not sure this is right either tbh*/}
#line 1691 "parser.tab.c"
    break;

  case 64: /* assignop: ASSIGN  */
#line 162 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Check yourself before you wreck yourself*/}
#line 1697 "parser.tab.c"
    break;

  case 65: /* assignop: ADDASS  */
#line 163 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Cuz bitches like you iz bad 4 my healt*/}
#line 1703 "parser.tab.c"
    break;

  case 66: /* assignop: DECASS  */
#line 164 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 1709 "parser.tab.c"
    break;

  case 67: /* assignop: MULASS  */
#line 165 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 1715 "parser.tab.c"
    break;

  case 68: /* assignop: DIVASS  */
#line 166 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 1721 "parser.tab.c"
    break;

  case 69: /* simpleExp: simpleExp OR andExp  */
#line 169 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 1727 "parser.tab.c"
    break;

  case 70: /* simpleExp: andExp  */
#line 170 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1733 "parser.tab.c"
    break;

  case 71: /* andExp: andExp AND unaryRelExp  */
#line 173 "parser.y"
                                            {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 1739 "parser.tab.c"
    break;

  case 72: /* andExp: unaryRelExp  */
#line 174 "parser.y"
                                           {(yyval.tree)=(yyvsp[0].tree);}
#line 1745 "parser.tab.c"
    break;

  case 73: /* unaryRelExp: NOT unaryRelExp  */
#line 177 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree), NULL, NULL); (yyval.tree)=node; }
#line 1751 "parser.tab.c"
    break;

  case 74: /* unaryRelExp: relExp  */
#line 178 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1757 "parser.tab.c"
    break;

  case 75: /* relExp: sumExp relop sumExp  */
#line 181 "parser.y"
                                       {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree)); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-1].tree);}
#line 1763 "parser.tab.c"
    break;

  case 76: /* relExp: sumExp  */
#line 182 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree);}
#line 1769 "parser.tab.c"
    break;

  case 77: /* relop: LESS  */
#line 185 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1775 "parser.tab.c"
    break;

  case 78: /* relop: LEQ  */
#line 186 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1781 "parser.tab.c"
    break;

  case 79: /* relop: GREATER  */
#line 187 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1787 "parser.tab.c"
    break;

  case 80: /* relop: GEQ  */
#line 188 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1793 "parser.tab.c"
    break;

  case 81: /* relop: EQ  */
#line 189 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1799 "parser.tab.c"
    break;

  case 82: /* relop: NEQ  */
#line 190 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 1805 "parser.tab.c"
    break;

  case 83: /* sumExp: sumExp sumop mulExp  */
#line 193 "parser.y"
                                      {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree)); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-1].tree);}
#line 1811 "parser.tab.c"
    break;

  case 84: /* sumExp: mulExp  */
#line 194 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree);}
#line 1817 "parser.tab.c"
    break;

  case 85: /* sumop: ADD  */
#line 197 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1823 "parser.tab.c"
    break;

  case 86: /* sumop: SUB  */
#line 198 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1829 "parser.tab.c"
    break;

  case 87: /* mulExp: mulExp mulop unaryExp  */
#line 201 "parser.y"
                                        {(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree)); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-1].tree);}
#line 1835 "parser.tab.c"
    break;

  case 88: /* mulExp: unaryExp  */
#line 202 "parser.y"
                               {(yyval.tree)=(yyvsp[0].tree);}
#line 1841 "parser.tab.c"
    break;

  case 89: /* mulop: MUL  */
#line 205 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1847 "parser.tab.c"
    break;

  case 90: /* mulop: DIV  */
#line 206 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1853 "parser.tab.c"
    break;

  case 91: /* mulop: MOD  */
#line 207 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1859 "parser.tab.c"
    break;

  case 92: /* unaryExp: unaryOp unaryExp  */
#line 210 "parser.y"
                                   {(yyvsp[-1].tree)->addChildren((yyvsp[0].tree)); (yyval.tree)=(yyvsp[0].tree);}
#line 1865 "parser.tab.c"
    break;

  case 93: /* unaryExp: factor  */
#line 211 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 1871 "parser.tab.c"
    break;

  case 94: /* unaryOp: CHSIGN  */
#line 214 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1877 "parser.tab.c"
    break;

  case 95: /* unaryOp: SIZEOF  */
#line 215 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1883 "parser.tab.c"
    break;

  case 96: /* unaryOp: QMARK  */
#line 216 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1889 "parser.tab.c"
    break;

  case 97: /* CHSIGN: SUB  */
#line 219 "parser.y"
                        {(yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 1895 "parser.tab.c"
    break;

  case 98: /* SIZEOF: MUL  */
#line 221 "parser.y"
                        {(yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 1901 "parser.tab.c"
    break;

  case 99: /* factor: mutable  */
#line 224 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 1907 "parser.tab.c"
    break;

  case 100: /* factor: immutable  */
#line 225 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 1913 "parser.tab.c"
    break;

  case 101: /* mutable: ID  */
#line 228 "parser.y"
                                             {treeNode* node = newExpNode(IdK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1919 "parser.tab.c"
    break;

  case 102: /* mutable: ID LBRACK exp RBRACK  */
#line 229 "parser.y"
                                            {treeNode* node = newExpNode(IdK, (yyvsp[-3].tokenData), NULL, NULL, NULL); (yyval.tree)=node; /*Something is up with this one LOL*/ }
#line 1925 "parser.tab.c"
    break;

  case 103: /* immutable: LPAREN exp RPAREN  */
#line 232 "parser.y"
                                            {/*figure our in sec*/}
#line 1931 "parser.tab.c"
    break;

  case 104: /* immutable: call  */
#line 233 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1937 "parser.tab.c"
    break;

  case 105: /* immutable: constant  */
#line 234 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1943 "parser.tab.c"
    break;

  case 106: /* call: ID LPAREN args RPAREN  */
#line 237 "parser.y"
                                         {treeNode* node = newExpNode(CallK, (yyvsp[-3].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 1949 "parser.tab.c"
    break;

  case 107: /* args: argList  */
#line 240 "parser.y"
                            {(yyval.tree)=(yyvsp[0].tree);}
#line 1955 "parser.tab.c"
    break;

  case 108: /* args: %empty  */
#line 241 "parser.y"
                           {(yyval.tree)=NULL;}
#line 1961 "parser.tab.c"
    break;

  case 109: /* argList: argList COMMA exp  */
#line 244 "parser.y"
                                    {(yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 1967 "parser.tab.c"
    break;

  case 110: /* argList: exp  */
#line 245 "parser.y"
                                {(yyval.tree)=(yyvsp[0].tree);}
#line 1973 "parser.tab.c"
    break;

  case 111: /* constant: NUMCONST  */
#line 248 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1979 "parser.tab.c"
    break;

  case 112: /* constant: CHARCONST  */
#line 249 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1985 "parser.tab.c"
    break;

  case 113: /* constant: STRINGCONST  */
#line 250 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1991 "parser.tab.c"
    break;

  case 114: /* constant: BOOLCONST  */
#line 251 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 1997 "parser.tab.c"
    break;


#line 2001 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 254 "parser.y"

extern int yydebug;
int main(int argc, char *argv[]){
    //yydebug = 1;
    GLOBAL_HEAD = NULL;
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

       GLOBAL_HEAD->printTree(1,1);

        //printf("Number of errors: %d\n", numErrors);
    
}
