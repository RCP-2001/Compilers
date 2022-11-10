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
#line 2 "parser.y"

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
#define YYLAST   715

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

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
       0,    40,    40,    43,    44,    47,    48,    49,    52,    53,
      54,    57,    58,    59,    60,    63,    64,    65,    66,    69,
      70,    71,    74,    75,    76,    77,    80,    81,    82,    85,
      86,    87,    88,    89,    90,    93,    94,    97,    98,    99,
     100,   103,   104,   107,   108,   109,   110,   114,   115,   118,
     119,   122,   123,   126,   127,   128,   131,   132,   133,   135,
     137,   138,   140,   142,   146,   147,   148,   149,   152,   153,
     154,   157,   160,   161,   164,   165,   168,   169,   172,   173,
     174,   175,   179,   180,   183,   184,   185,   186,   189,   190,
     191,   192,   193,   196,   197,   198,   201,   204,   205,   206,
     207,   208,   209,   210,   211,   214,   215,   216,   217,   218,
     221,   222,   223,   226,   227,   228,   231,   232,   233,   236,
     237,   238,   241,   242,   243,   244,   245,   246,   249,   250,
     251,   254,   255,   258,   259,   260,   263,   264,   265,   268,
     269,   270,   273,   274,   275,   278,   281,   285,   286,   289,
     290,   295,   296,   297,   298,   301,   302,   305,   306,   309,
     310,   311,   314,   315,   316,   317
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

#define YYPACT_NINF (-185)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-159)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     238,   119,   -24,  -185,  -185,  -185,    41,   127,  -185,  -185,
      96,  -185,    38,     0,   115,  -185,    32,    27,  -185,  -185,
     255,   -18,   152,   315,  -185,    15,  -185,   121,   315,   -14,
     170,    21,    60,  -185,  -185,    35,  -185,    55,    30,  -185,
    -185,  -185,  -185,   340,  -185,  -185,  -185,   349,    93,   124,
    -185,  -185,   632,    86,  -185,    43,  -185,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,   123,    38,  -185,    93,   138,   144,
     167,  -185,    26,   245,   -14,   160,  -185,   370,    17,    55,
    -185,   291,   162,    93,   589,   400,   421,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,   641,   650,  -185,  -185,  -185,
     662,    55,  -185,  -185,   178,   195,  -185,  -185,  -185,  -185,
    -185,   203,   291,   207,  -185,   197,   237,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,   370,  -185,  -185,  -185,   430,    55,
     124,    55,  -185,    55,   217,    55,    86,    55,  -185,  -185,
    -185,  -185,   151,  -185,  -185,  -185,   451,  -185,   291,  -185,
     196,   278,  -185,   218,   220,   291,  -185,   269,   196,   193,
     282,   427,   481,   502,   229,    98,   249,  -185,  -185,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,  -185,
    -185,   252,  -185,   287,  -185,  -185,  -185,   155,   284,    64,
      -4,   257,   260,   508,  -185,   290,  -185,  -185,  -185,   253,
     286,   253,   253,   253,   511,  -185,  -185,  -185,   304,   532,
     562,   239,  -185,  -185,   316,  -185,  -185,  -185,  -185,    56,
     314,   258,   253,   346,   321,    13,    92,  -185,   299,   253,
     253,   335,   253,   583,  -185,  -185,   286,   286,   286,   286,
     592,  -185,  -185,  -185,  -185,  -185,  -185,  -185,    55,   183,
     323,   327,    80,   334,   613,   286,   286,   286,   286,    55,
      93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    27,    26,    28,     0,     0,     4,     5,
       0,     6,    18,    22,     0,    16,    19,     0,     1,     3,
      31,    22,     0,     0,    25,     0,     9,     0,     0,    33,
       0,     0,    35,    38,    10,     0,     8,     0,   149,   162,
     163,   164,   165,     0,   145,   146,   144,     0,    21,   111,
     114,   117,   120,   129,   134,     0,   142,   143,   140,   147,
     148,   152,   153,    24,     0,    17,    15,    20,    42,    47,
      41,    44,     0,     0,    32,     0,   156,     0,     0,   118,
     116,   154,     0,   100,   147,     0,     0,   123,   125,   122,
     124,   126,   127,   131,   132,     0,     0,   136,   137,   138,
       0,   141,   139,    23,     0,     0,    34,    73,    30,    39,
      37,     0,     0,     0,   160,     0,   157,   103,   104,   106,
     107,   108,   109,   105,     0,   151,    98,    99,     0,   112,
     110,   115,   113,   121,   119,   130,   128,   135,   133,    48,
      45,    43,     0,    29,   150,   155,     0,   101,   102,    97,
       0,     0,    72,     0,     0,   161,   159,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    74,
      49,    50,    52,    53,    55,    64,    65,    51,    54,    67,
      66,     0,    13,     0,    14,    12,    69,    61,     0,    80,
       0,    78,     0,     0,    93,     0,    96,    68,    11,     0,
       0,     0,     0,     0,     0,    95,    94,    58,    50,     0,
       0,     0,    62,    56,    50,    81,    87,    76,    82,     0,
       0,     0,     0,    61,     0,    86,     0,    84,     0,     0,
       0,     0,     0,     0,    59,    63,     0,     0,     0,     0,
       0,    57,    60,    79,    85,    91,    77,    83,    90,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,  -185,  -185,   298,  -185,  -185,    -3,   326,  -185,     2,
    -185,   324,  -185,   294,  -185,   259,  -184,   -17,  -144,  -185,
    -185,  -185,  -185,   -68,  -185,  -185,  -185,  -185,   129,  -185,
    -185,   -44,   288,   -22,   285,   -32,  -185,  -185,   295,  -185,
     277,  -185,   -47,  -185,  -185,  -185,  -185,   -23,  -185,  -185,
    -185,  -185,  -185
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   152,    14,    15,    16,    30,
      11,    31,    32,    33,    70,    71,   169,   170,   216,   172,
     173,   174,   175,   176,   142,   154,   177,   178,   220,   179,
     180,   181,   124,    83,    49,    50,    51,    95,    52,    96,
      53,   100,    54,    55,    56,    57,    58,    84,    60,    61,
     115,   116,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    48,    10,    82,   108,    59,    67,    22,   102,    10,
     171,    80,    25,   -40,   203,   207,    63,   213,   112,    85,
      59,    64,    38,    39,    40,    41,    42,   106,    29,    17,
      25,   238,    59,   113,   114,    35,    74,     3,     4,     5,
     -40,    18,    43,   143,   101,     3,     4,     5,    38,    39,
      40,    41,    42,   138,   132,   208,   212,   214,   107,   218,
      77,    28,    59,    59,    44,    45,    76,    23,    46,    24,
      47,  -158,    59,    59,   230,    72,   231,    59,   235,   -86,
     147,   -36,   202,    78,   149,   242,   244,    73,   247,   -36,
      44,    45,   250,   251,    46,   218,    47,    20,   257,   193,
     231,    21,   156,    38,    39,    40,    41,    42,    76,    76,
     239,   235,   242,   244,   247,    85,    85,    76,   188,    -7,
      12,   195,    65,    43,    13,   194,    13,    -2,     1,    -7,
      -7,    -7,     2,    76,    97,    98,    99,     3,     4,     5,
      59,   190,    26,    27,   153,    44,    45,   157,    86,    46,
     160,    47,   150,   158,   103,   183,   -75,   -75,   -75,   -75,
     -75,     3,     4,     5,   -75,   224,   -46,   -75,   -75,   199,
     200,    68,   -75,   -75,   104,    69,   -75,   151,   -75,    36,
      27,    59,   221,   -75,   -75,   215,   217,    59,   226,   117,
     118,   119,   120,   121,   122,   105,   140,    12,   -75,   -75,
      69,    13,   -75,   254,   -75,   234,    85,   123,    76,   139,
      59,   249,   241,   243,   111,   246,   125,    59,   221,   159,
     184,   161,    23,    13,    24,    38,    39,    40,    41,    42,
     191,    59,   260,   162,   192,   107,   163,   164,   144,     1,
     227,   165,   166,     2,   228,    43,   109,   167,     3,     4,
       5,   145,   107,   168,   161,     3,     4,     5,    38,    39,
      40,    41,    42,    93,    94,   146,   162,    44,    45,   163,
     164,    46,   -84,    47,   165,   166,   196,   233,    43,   197,
     167,    85,    34,   -18,    23,   107,    24,   161,     3,     4,
       5,    38,    39,    40,    41,    42,   182,    27,   201,   209,
      44,    45,   210,   211,    46,    19,    47,   165,   166,   185,
      27,    43,   204,   167,   198,    27,    37,   206,   107,   222,
      38,    39,    40,    41,    42,   117,   118,   119,   120,   121,
     122,   229,   232,    44,    45,   237,   245,    46,   255,    47,
      43,    79,   256,   123,    76,    38,    39,    40,    41,    42,
      81,   240,   258,    66,    38,    39,    40,    41,    42,    75,
     236,   200,    44,    45,   141,    43,    46,   110,    47,   253,
     130,   112,   128,   136,    43,    38,    39,    40,    41,    42,
     117,   118,   119,   120,   121,   122,     0,    44,    45,     0,
     134,    46,     0,    47,     0,    43,    44,    45,   123,    76,
      46,   129,    47,     0,     0,    38,    39,    40,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,    46,   131,    47,     0,    43,    38,    39,    40,    41,
      42,   148,     0,     0,     0,    38,    39,    40,    41,    42,
       0,     0,     0,     0,     0,     0,    43,    44,    45,     0,
       0,    46,   155,    47,   186,    43,    38,    39,    40,    41,
      42,   117,   118,   119,   120,   121,   122,     0,    44,    45,
       0,     0,    46,     0,    47,     0,    43,    44,    45,   123,
      76,    46,   187,    47,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,    46,   189,    47,     0,    43,    38,    39,    40,
      41,    42,   219,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,     0,    46,   223,    47,   205,    43,    38,    39,    40,
      41,    42,   117,   118,   119,   120,   121,   122,     0,    44,
      45,     0,     0,    46,     0,    47,     0,    43,    44,    45,
     123,    76,    46,   225,    47,     0,     0,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,    46,   248,    47,     0,    43,    38,    39,
      40,    41,    42,   252,     0,     0,     0,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,     0,    43,    44,
      45,     0,     0,    46,   259,    47,     0,    43,    38,    39,
      40,    41,    42,   126,   127,   119,   120,   121,   122,     0,
      44,    45,     0,     0,    46,     0,    47,     0,    43,    44,
      45,   123,   133,    46,     0,    47,    38,    39,    40,    41,
      42,   135,     0,     0,     0,    38,    39,    40,    41,    42,
      44,    45,     0,   137,    46,     0,    47,    38,    39,    40,
      41,    42,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
       0,     0,    46,     0,    47,     0,     0,    44,    45,     0,
       0,    46,     0,    47,     0,     0,     0,     0,     0,    44,
      45,     0,     0,    46,     0,    47
};

static const yytype_int16 yycheck[] =
{
      23,    23,     0,    47,    72,    28,    28,    10,    55,     7,
     154,    43,    30,    27,    18,   199,     1,   201,     1,    23,
      43,     6,     5,     6,     7,     8,     9,     1,     1,    53,
      30,    18,    55,    77,    78,    53,     1,    10,    11,    12,
      54,     0,    25,   111,     1,    10,    11,    12,     5,     6,
       7,     8,     9,   100,    86,   199,   200,   201,    32,   203,
      30,    29,    85,    86,    47,    48,    53,    29,    51,    31,
      53,    54,    95,    96,    18,    54,    20,   100,   222,    15,
     124,    54,    18,    53,   128,   229,   230,    27,   232,    54,
      47,    48,   236,   237,    51,   239,    53,     1,    18,     1,
      20,     5,   146,     5,     6,     7,     8,     9,    53,    53,
      18,   255,   256,   257,   258,    23,    23,    53,   162,     0,
       1,   165,     1,    25,     5,    27,     5,     0,     1,    10,
      11,    12,     5,    53,    48,    49,    50,    10,    11,    12,
     163,   163,    27,    28,   142,    47,    48,   150,    24,    51,
     153,    53,     1,   151,    31,   158,     5,     6,     7,     8,
       9,    10,    11,    12,    13,   209,    28,    16,    17,    14,
      15,     1,    21,    22,    30,     5,    25,    26,    27,    27,
      28,   204,   204,    32,    33,   202,   203,   210,   210,    34,
      35,    36,    37,    38,    39,    28,     1,     1,    47,    48,
       5,     5,    51,    20,    53,   222,    23,    52,    53,    31,
     233,   233,   229,   230,    54,   232,    54,   240,   240,     1,
      27,     1,    29,     5,    31,     5,     6,     7,     8,     9,
       1,   254,   254,    13,     5,    32,    16,    17,    31,     1,
       1,    21,    22,     5,     5,    25,     1,    27,    10,    11,
      12,    54,    32,    33,     1,    10,    11,    12,     5,     6,
       7,     8,     9,    46,    47,    28,    13,    47,    48,    16,
      17,    51,    15,    53,    21,    22,    27,    19,    25,    27,
      27,    23,    27,    28,    29,    32,    31,     1,    10,    11,
      12,     5,     6,     7,     8,     9,    27,    28,    14,    13,
      47,    48,    16,    17,    51,     7,    53,    21,    22,    27,
      28,    25,    52,    27,    27,    28,     1,    27,    32,    15,
       5,     6,     7,     8,     9,    34,    35,    36,    37,    38,
      39,    15,    18,    47,    48,    14,     1,    51,    15,    53,
      25,     1,    15,    52,    53,     5,     6,     7,     8,     9,
       1,    52,    18,    27,     5,     6,     7,     8,     9,    35,
      14,    15,    47,    48,   105,    25,    51,    73,    53,   240,
      85,     1,    84,    96,    25,     5,     6,     7,     8,     9,
      34,    35,    36,    37,    38,    39,    -1,    47,    48,    -1,
      95,    51,    -1,    53,    -1,    25,    47,    48,    52,    53,
      51,     1,    53,    -1,    -1,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    51,     1,    53,    -1,    25,     5,     6,     7,     8,
       9,     1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    47,    48,    -1,
      -1,    51,     1,    53,    27,    25,     5,     6,     7,     8,
       9,    34,    35,    36,    37,    38,    39,    -1,    47,    48,
      -1,    -1,    51,    -1,    53,    -1,    25,    47,    48,    52,
      53,    51,     1,    53,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,     1,    53,    -1,    25,     5,     6,     7,
       8,     9,     1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    25,    47,    48,
      -1,    -1,    51,     1,    53,    27,    25,     5,     6,     7,
       8,     9,    34,    35,    36,    37,    38,    39,    -1,    47,
      48,    -1,    -1,    51,    -1,    53,    -1,    25,    47,    48,
      52,    53,    51,     1,    53,    -1,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,     1,    53,    -1,    25,     5,     6,
       7,     8,     9,     1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    25,    47,
      48,    -1,    -1,    51,     1,    53,    -1,    25,     5,     6,
       7,     8,     9,    34,    35,    36,    37,    38,    39,    -1,
      47,    48,    -1,    -1,    51,    -1,    53,    -1,    25,    47,
      48,    52,     1,    51,    -1,    53,     5,     6,     7,     8,
       9,     1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      47,    48,    -1,     1,    51,    -1,    53,     5,     6,     7,
       8,     9,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,    -1,    53,    -1,    -1,    47,    48,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    53
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
      69,    70,    54,    27,     1,    66,    53,    30,    53,     1,
      90,     1,    86,    88,   102,    23,    24,    40,    41,    42,
      43,    44,    45,    46,    47,    92,    94,    48,    49,    50,
      96,     1,    97,    31,    30,    28,     1,    32,    78,     1,
      68,    54,     1,    86,    86,   105,   106,    34,    35,    36,
      37,    38,    39,    52,    87,    54,    34,    35,    87,     1,
      89,     1,    90,     1,    93,     1,    95,     1,    97,    31,
       1,    70,    79,    78,    31,    54,    28,    86,     1,    86,
       1,    26,    60,    64,    80,     1,    86,    61,    64,     1,
      61,     1,    13,    16,    17,    21,    22,    27,    33,    71,
      72,    73,    74,    75,    76,    77,    78,    81,    82,    84,
      85,    86,    27,    61,    27,    27,    27,     1,    86,     1,
      88,     1,     5,     1,    27,    86,    27,    27,    27,    14,
      15,    14,    18,    18,    52,    27,    27,    71,    73,    13,
      16,    17,    73,    71,    73,    72,    73,    72,    73,     1,
      83,    88,    15,     1,    86,     1,    88,     1,     5,    15,
      18,    20,    18,    19,    72,    73,    14,    14,    18,    18,
      52,    72,    73,    72,    73,     1,    72,    73,     1,    88,
      73,    73,     1,    83,    20,    15,    15,    18,    18,     1,
      88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76,    77,    77,
      77,    78,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      88,    88,    88,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    94,    94,    95,    95,    95,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    99,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     3,     3,     3,     3,     1,     3,     1,     1,
       3,     3,     1,     4,     3,     2,     1,     1,     1,     6,
       5,     2,     4,     3,     5,     1,     0,     3,     1,     3,
       1,     2,     2,     3,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     6,
       6,     2,     4,     6,     1,     1,     1,     1,     2,     2,
       1,     4,     2,     0,     2,     0,     4,     6,     2,     6,
       2,     4,     4,     6,     2,     6,     2,     4,     3,     5,
       3,     3,     5,     2,     3,     3,     2,     3,     2,     2,
       1,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     1,     3,     2,     1,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     2,     4,     2,     1,     0,     3,
       1,     3,     1,     1,     1,     1
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
#line 40 "parser.y"
                        {/*printf("accept Program\n");*/ GLOBAL_HEAD = (yyvsp[0].tree);}
#line 1743 "parser.tab.c"
    break;

  case 3: /* declist: declist decl  */
#line 43 "parser.y"
                        {if((yyvsp[-1].tree)!=NULL) (yyvsp[-1].tree)-> addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}
#line 1749 "parser.tab.c"
    break;

  case 4: /* declist: decl  */
#line 44 "parser.y"
                        {(yyval.tree)=(yyvsp[0].tree);}
#line 1755 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 47 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1761 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 48 "parser.y"
                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1767 "parser.tab.c"
    break;

  case 7: /* decl: error  */
#line 49 "parser.y"
                   {(yyval.tree) = NULL;}
#line 1773 "parser.tab.c"
    break;

  case 8: /* varDecl: typeSpec varDeclList SEMI  */
#line 52 "parser.y"
                                     {if((yyvsp[-1].tree) != NULL){(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true);} (yyval.tree)=(yyvsp[-1].tree);}
#line 1779 "parser.tab.c"
    break;

  case 9: /* varDecl: error varDeclList SEMI  */
#line 53 "parser.y"
                                     {(yyval.tree)=NULL; yyerrok;}
#line 1785 "parser.tab.c"
    break;

  case 10: /* varDecl: typeSpec error SEMI  */
#line 54 "parser.y"
                                  {(yyval.tree)=NULL; yyerrok; }
#line 1791 "parser.tab.c"
    break;

  case 11: /* scopedVarDecl: STATIC typeSpec varDeclList SEMI  */
#line 57 "parser.y"
                                                    {if((yyvsp[-1].tree)!=NULL){(yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyvsp[-1].tree)->BStatic(true);} (yyval.tree)=(yyvsp[-1].tree); yyerrok;}
#line 1797 "parser.tab.c"
    break;

  case 12: /* scopedVarDecl: typeSpec varDeclList SEMI  */
#line 58 "parser.y"
                                                    {if((yyvsp[-1].tree)!=NULL) (yyvsp[-1].tree)->EType((yyvsp[-2].type)); (yyval.tree)=(yyvsp[-1].tree); yyerrok; /*This might be wrong actually*/}
#line 1803 "parser.tab.c"
    break;

  case 13: /* scopedVarDecl: error varDeclList SEMI  */
#line 59 "parser.y"
                                                    {(yyval.tree)=NULL; yyerrok;}
#line 1809 "parser.tab.c"
    break;

  case 14: /* scopedVarDecl: typeSpec error SEMI  */
#line 60 "parser.y"
                                                    {(yyval.tree)=NULL; yyerrok;}
#line 1815 "parser.tab.c"
    break;

  case 15: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 63 "parser.y"
                                                 {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree); yyerrok;}
#line 1821 "parser.tab.c"
    break;

  case 16: /* varDeclList: varDeclInit  */
#line 64 "parser.y"
                                                 {(yyval.tree)=(yyvsp[0].tree);}
#line 1827 "parser.tab.c"
    break;

  case 17: /* varDeclList: varDeclList COMMA error  */
#line 65 "parser.y"
                                                 {(yyval.tree)=NULL;}
#line 1833 "parser.tab.c"
    break;

  case 18: /* varDeclList: error  */
#line 66 "parser.y"
                                                 {(yyval.tree)=NULL;}
#line 1839 "parser.tab.c"
    break;

  case 19: /* varDeclInit: varDeclID  */
#line 69 "parser.y"
                                               {(yyval.tree) = (yyvsp[0].tree);}
#line 1845 "parser.tab.c"
    break;

  case 20: /* varDeclInit: varDeclID COLON simpleExp  */
#line 70 "parser.y"
                                               {if((yyvsp[-2].tree)!=NULL)(yyvsp[-2].tree)->addChildren((yyvsp[0].tree), 0); (yyval.tree) = (yyvsp[-2].tree);}
#line 1851 "parser.tab.c"
    break;

  case 21: /* varDeclInit: error COLON simpleExp  */
#line 71 "parser.y"
                                                    {(yyval.tree) = NULL; yyerrok; }
#line 1857 "parser.tab.c"
    break;

  case 22: /* varDeclID: ID  */
#line 74 "parser.y"
                                                {(yyval.tree) = newDeclNode(VarK, UndefinedType, (yyvsp[0].tokenData)); (yyval.tree)->SetSize(1); }
#line 1863 "parser.tab.c"
    break;

  case 23: /* varDeclID: ID LBRACK NUMCONST RBRACK  */
#line 75 "parser.y"
                                                {treeNode* node = newDeclNode(VarK, UndefinedType, (yyvsp[-3].tokenData)); node->setArray(true); node->SetSize((yyvsp[-1].tokenData)->nvalue + 1); (yyval.tree) = node;}
#line 1869 "parser.tab.c"
    break;

  case 24: /* varDeclID: ID LBRACK error  */
#line 76 "parser.y"
                                                {(yyval.tree)=NULL;}
#line 1875 "parser.tab.c"
    break;

  case 25: /* varDeclID: error RBRACK  */
#line 77 "parser.y"
                                                {(yyval.tree)=NULL; yyerrok;}
#line 1881 "parser.tab.c"
    break;

  case 26: /* typeSpec: INT  */
#line 80 "parser.y"
                        {(yyval.type) = Integer;}
#line 1887 "parser.tab.c"
    break;

  case 27: /* typeSpec: BOOL  */
#line 81 "parser.y"
                        {(yyval.type) = boolean;}
#line 1893 "parser.tab.c"
    break;

  case 28: /* typeSpec: CHAR  */
#line 82 "parser.y"
                        {(yyval.type) = Char;}
#line 1899 "parser.tab.c"
    break;

  case 29: /* funDecl: typeSpec ID LPAREN params RPAREN compoundStmt  */
#line 85 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, (yyvsp[-5].type), (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree),1); (yyval.tree)= node;}
#line 1905 "parser.tab.c"
    break;

  case 30: /* funDecl: ID LPAREN params RPAREN compoundStmt  */
#line 86 "parser.y"
                                                                  {treeNode* node = newDeclNode(FuncK, Void, (yyvsp[-4].tokenData)); node-> addChildren((yyvsp[-2].tree), 0); node-> addChildren((yyvsp[0].tree), 1); (yyval.tree)= node;}
#line 1911 "parser.tab.c"
    break;

  case 31: /* funDecl: typeSpec error  */
#line 87 "parser.y"
                                                                  {(yyval.tree)=NULL;}
#line 1917 "parser.tab.c"
    break;

  case 32: /* funDecl: typeSpec ID LPAREN error  */
#line 88 "parser.y"
                                                                 {(yyval.tree)=NULL;}
#line 1923 "parser.tab.c"
    break;

  case 33: /* funDecl: ID LPAREN error  */
#line 89 "parser.y"
                                                                        {(yyval.tree)=NULL;}
#line 1929 "parser.tab.c"
    break;

  case 34: /* funDecl: ID LPAREN params RPAREN error  */
#line 90 "parser.y"
                                                                {(yyval.tree)=NULL;}
#line 1935 "parser.tab.c"
    break;

  case 35: /* params: paramList  */
#line 93 "parser.y"
                                {(yyval.tree) = (yyvsp[0].tree);}
#line 1941 "parser.tab.c"
    break;

  case 36: /* params: %empty  */
#line 94 "parser.y"
                                {(yyval.tree)= NULL;}
#line 1947 "parser.tab.c"
    break;

  case 37: /* paramList: paramList SEMI paramTypeList  */
#line 97 "parser.y"
                                                   {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree);}
#line 1953 "parser.tab.c"
    break;

  case 38: /* paramList: paramTypeList  */
#line 98 "parser.y"
                                                   {(yyval.tree)=(yyvsp[0].tree);}
#line 1959 "parser.tab.c"
    break;

  case 39: /* paramList: paramList SEMI error  */
#line 99 "parser.y"
                                                   {(yyval.tree)= NULL;}
#line 1965 "parser.tab.c"
    break;

  case 40: /* paramList: error  */
#line 100 "parser.y"
                                                   {(yyval.tree)= NULL;}
#line 1971 "parser.tab.c"
    break;

  case 41: /* paramTypeList: typeSpec paramIDList  */
#line 103 "parser.y"
                                                {if((yyvsp[0].tree) != NULL) (yyvsp[0].tree)->EType((yyvsp[-1].type)); (yyval.tree)=(yyvsp[0].tree); /*This might be wrong actually*/}
#line 1977 "parser.tab.c"
    break;

  case 42: /* paramTypeList: typeSpec error  */
#line 104 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 1983 "parser.tab.c"
    break;

  case 43: /* paramIDList: paramIDList COMMA paramID  */
#line 107 "parser.y"
                                                {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-2].tree);  yyerrok;}
#line 1989 "parser.tab.c"
    break;

  case 44: /* paramIDList: paramID  */
#line 108 "parser.y"
                                                {(yyval.tree)=(yyvsp[0].tree);}
#line 1995 "parser.tab.c"
    break;

  case 45: /* paramIDList: paramIDList COMMA error  */
#line 109 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 2001 "parser.tab.c"
    break;

  case 46: /* paramIDList: error  */
#line 110 "parser.y"
                                                {(yyval.tree)= NULL;}
#line 2007 "parser.tab.c"
    break;

  case 47: /* paramID: ID  */
#line 114 "parser.y"
                                               {(yyval.tree) = newDeclNode(ParamK, UndefinedType, (yyvsp[0].tokenData)); }
#line 2013 "parser.tab.c"
    break;

  case 48: /* paramID: ID LBRACK RBRACK  */
#line 115 "parser.y"
                                               {treeNode* node = newDeclNode(ParamK, UndefinedType, (yyvsp[-2].tokenData)); node->setArray(true); (yyval.tree) = node;}
#line 2019 "parser.tab.c"
    break;

  case 49: /* stmt: openStatement  */
#line 118 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2025 "parser.tab.c"
    break;

  case 50: /* stmt: closedStatement  */
#line 119 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2031 "parser.tab.c"
    break;

  case 51: /* openStatement: openItrStmt  */
#line 122 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2037 "parser.tab.c"
    break;

  case 52: /* openStatement: openSelectStatement  */
#line 123 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2043 "parser.tab.c"
    break;

  case 53: /* closedStatement: closedSelectStatement  */
#line 126 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2049 "parser.tab.c"
    break;

  case 54: /* closedStatement: closedItrStmt  */
#line 127 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2055 "parser.tab.c"
    break;

  case 55: /* closedStatement: simpleStatement  */
#line 128 "parser.y"
                                         {(yyval.tree)=(yyvsp[0].tree);}
#line 2061 "parser.tab.c"
    break;

  case 56: /* openSelectStatement: IF exp THEN stmt  */
#line 131 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 2067 "parser.tab.c"
    break;

  case 57: /* openSelectStatement: IF exp THEN closedStatement ELSE openStatement  */
#line 132 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2073 "parser.tab.c"
    break;

  case 58: /* openSelectStatement: IF error THEN stmt  */
#line 133 "parser.y"
                                                {(yyval.tree)=NULL; yyerrok;}
#line 2079 "parser.tab.c"
    break;

  case 59: /* openSelectStatement: IF error THEN closedStatement ELSE openStatement  */
#line 135 "parser.y"
                                                                           {(yyval.tree)=NULL; yyerrok;}
#line 2085 "parser.tab.c"
    break;

  case 60: /* closedSelectStatement: IF exp THEN closedStatement ELSE closedStatement  */
#line 137 "parser.y"
                                                                                {treeNode *node = newStmtNode(IfK, (yyvsp[-5].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2091 "parser.tab.c"
    break;

  case 61: /* closedSelectStatement: IF error  */
#line 138 "parser.y"
                                                                                {(yyval.tree)=NULL; }
#line 2097 "parser.tab.c"
    break;

  case 62: /* closedSelectStatement: IF error ELSE closedStatement  */
#line 140 "parser.y"
                                                                                {(yyval.tree)=NULL; yyerrok;}
#line 2103 "parser.tab.c"
    break;

  case 63: /* closedSelectStatement: IF error THEN closedStatement ELSE closedStatement  */
#line 142 "parser.y"
                                                                                  {(yyval.tree)=NULL; yyerrok;}
#line 2109 "parser.tab.c"
    break;

  case 64: /* simpleStatement: expStmt  */
#line 146 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2115 "parser.tab.c"
    break;

  case 65: /* simpleStatement: compoundStmt  */
#line 147 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2121 "parser.tab.c"
    break;

  case 66: /* simpleStatement: breakStmt  */
#line 148 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2127 "parser.tab.c"
    break;

  case 67: /* simpleStatement: returnStmt  */
#line 149 "parser.y"
                                     {(yyval.tree)= (yyvsp[0].tree);}
#line 2133 "parser.tab.c"
    break;

  case 68: /* expStmt: exp SEMI  */
#line 152 "parser.y"
                                    {(yyval.tree)=(yyvsp[-1].tree); yyerrok; }
#line 2139 "parser.tab.c"
    break;

  case 69: /* expStmt: error SEMI  */
#line 153 "parser.y"
                                    {(yyval.tree)=NULL; yyerrok;}
#line 2145 "parser.tab.c"
    break;

  case 70: /* expStmt: SEMI  */
#line 154 "parser.y"
                                    {(yyval.tree)=NULL; /*WTF this porbably will break something i am sad wtf*/}
#line 2151 "parser.tab.c"
    break;

  case 71: /* compoundStmt: LCURL LocalDecls stmtList RCURL  */
#line 157 "parser.y"
                                                    {treeNode *node = newStmtNode(CompoundK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[-1].tree), NULL ); (yyval.tree)= node; yyerrok;}
#line 2157 "parser.tab.c"
    break;

  case 72: /* LocalDecls: LocalDecls scopedVarDecl  */
#line 160 "parser.y"
                                                    {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}}
#line 2163 "parser.tab.c"
    break;

  case 73: /* LocalDecls: %empty  */
#line 161 "parser.y"
                                                     {(yyval.tree)= NULL;}
#line 2169 "parser.tab.c"
    break;

  case 74: /* stmtList: stmtList stmt  */
#line 164 "parser.y"
                                   {if((yyvsp[-1].tree) == NULL){(yyval.tree)=(yyvsp[0].tree);} else{(yyvsp[-1].tree)->addSibling((yyvsp[0].tree)); (yyval.tree) = (yyvsp[-1].tree);}  }
#line 2175 "parser.tab.c"
    break;

  case 75: /* stmtList: %empty  */
#line 165 "parser.y"
                                   {(yyval.tree)= NULL;}
#line 2181 "parser.tab.c"
    break;

  case 76: /* openItrStmt: WHILE simpleExp DO openStatement  */
#line 168 "parser.y"
                                                        {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 2187 "parser.tab.c"
    break;

  case 77: /* openItrStmt: FOR ID ASSIGN itrRange DO openStatement  */
#line 169 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 2195 "parser.tab.c"
    break;

  case 78: /* openItrStmt: FOR error  */
#line 172 "parser.y"
                                {(yyval.tree)=NULL;}
#line 2201 "parser.tab.c"
    break;

  case 79: /* openItrStmt: FOR ID ASSIGN error DO openStatement  */
#line 173 "parser.y"
                                                        {(yyval.tree)=NULL; yyerrok;}
#line 2207 "parser.tab.c"
    break;

  case 80: /* openItrStmt: WHILE error  */
#line 174 "parser.y"
                              {(yyval.tree)=NULL;}
#line 2213 "parser.tab.c"
    break;

  case 81: /* openItrStmt: WHILE error DO openStatement  */
#line 175 "parser.y"
                                               {(yyval.tree)=NULL; yyerrok;}
#line 2219 "parser.tab.c"
    break;

  case 82: /* closedItrStmt: WHILE simpleExp DO closedStatement  */
#line 179 "parser.y"
                                                         {treeNode* node = newStmtNode(WhileK, (yyvsp[-3].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL ); (yyval.tree)=node;}
#line 2225 "parser.tab.c"
    break;

  case 83: /* closedItrStmt: FOR ID ASSIGN itrRange DO closedStatement  */
#line 180 "parser.y"
                                                            {
                                                            treeNode* IDNode = newDeclNode(VarK, Integer, (yyvsp[-4].tokenData), NULL, NULL, NULL);
                                                            treeNode* node = newStmtNode(ForK, (yyvsp[-4].tokenData), IDNode, (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree) = node;  /*Totally wrong lmafo*/}
#line 2233 "parser.tab.c"
    break;

  case 84: /* closedItrStmt: FOR error  */
#line 183 "parser.y"
                                {(yyval.tree)=NULL;}
#line 2239 "parser.tab.c"
    break;

  case 85: /* closedItrStmt: FOR ID ASSIGN error DO closedStatement  */
#line 184 "parser.y"
                                                          {(yyval.tree)=NULL; yyerrok;}
#line 2245 "parser.tab.c"
    break;

  case 86: /* closedItrStmt: WHILE error  */
#line 185 "parser.y"
                              {(yyval.tree)=NULL;}
#line 2251 "parser.tab.c"
    break;

  case 87: /* closedItrStmt: WHILE error DO closedStatement  */
#line 186 "parser.y"
                                                 {(yyval.tree)=NULL; yyerrok;}
#line 2257 "parser.tab.c"
    break;

  case 88: /* itrRange: simpleExp TO simpleExp  */
#line 189 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node;}
#line 2263 "parser.tab.c"
    break;

  case 89: /* itrRange: simpleExp TO simpleExp BY simpleExp  */
#line 190 "parser.y"
                                                        {treeNode* node = newStmtNode(RangeK, (yyvsp[-3].tokenData), (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree)); (yyval.tree)=node;}
#line 2269 "parser.tab.c"
    break;

  case 90: /* itrRange: simpleExp TO error  */
#line 191 "parser.y"
                                     {(yyval.tree)=NULL;}
#line 2275 "parser.tab.c"
    break;

  case 91: /* itrRange: error BY error  */
#line 192 "parser.y"
                                     {(yyval.tree)=NULL; yyerrok;}
#line 2281 "parser.tab.c"
    break;

  case 92: /* itrRange: simpleExp TO simpleExp BY error  */
#line 193 "parser.y"
                                                  {(yyval.tree)=NULL;}
#line 2287 "parser.tab.c"
    break;

  case 93: /* returnStmt: RETURN SEMI  */
#line 196 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 2293 "parser.tab.c"
    break;

  case 94: /* returnStmt: RETURN exp SEMI  */
#line 197 "parser.y"
                                        {treeNode* node = newStmtNode(ReturnK, (yyvsp[-2].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; yyerrok;}
#line 2299 "parser.tab.c"
    break;

  case 95: /* returnStmt: RETURN error SEMI  */
#line 198 "parser.y"
                                        {(yyval.tree)=NULL; yyerrok;}
#line 2305 "parser.tab.c"
    break;

  case 96: /* breakStmt: BREAK SEMI  */
#line 201 "parser.y"
                                       {treeNode* node = newStmtNode(BreaK, (yyvsp[-1].tokenData), NULL, NULL, NULL); (yyval.tree)=node;}
#line 2311 "parser.tab.c"
    break;

  case 97: /* exp: mutable assignop exp  */
#line 204 "parser.y"
                                          {if((yyvsp[-1].tree)!=NULL){(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1);} (yyval.tree)=(yyvsp[-1].tree);}
#line 2317 "parser.tab.c"
    break;

  case 98: /* exp: mutable INC  */
#line 205 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 2323 "parser.tab.c"
    break;

  case 99: /* exp: mutable DEC  */
#line 206 "parser.y"
                                          {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node; }
#line 2329 "parser.tab.c"
    break;

  case 100: /* exp: simpleExp  */
#line 207 "parser.y"
                                          {(yyval.tree)=(yyvsp[0].tree); /*not sure this is right either tbh*/}
#line 2335 "parser.tab.c"
    break;

  case 101: /* exp: error assignop exp  */
#line 208 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2341 "parser.tab.c"
    break;

  case 102: /* exp: mutable assignop error  */
#line 209 "parser.y"
                                          {(yyval.tree)=NULL; }
#line 2347 "parser.tab.c"
    break;

  case 103: /* exp: error INC  */
#line 210 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2353 "parser.tab.c"
    break;

  case 104: /* exp: error DEC  */
#line 211 "parser.y"
                                          {(yyval.tree)=NULL; yyerrok;}
#line 2359 "parser.tab.c"
    break;

  case 105: /* assignop: ASSIGN  */
#line 214 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Check yourself before you wreck yourself*/}
#line 2365 "parser.tab.c"
    break;

  case 106: /* assignop: ADDASS  */
#line 215 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /**/}
#line 2371 "parser.tab.c"
    break;

  case 107: /* assignop: DECASS  */
#line 216 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2377 "parser.tab.c"
    break;

  case 108: /* assignop: MULASS  */
#line 217 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2383 "parser.tab.c"
    break;

  case 109: /* assignop: DIVASS  */
#line 218 "parser.y"
                                 {treeNode* node = newExpNode(AssingK, (yyvsp[0].tokenData)); (yyval.tree)=node; /*Fairly certien this will give wrong tree structure*/}
#line 2389 "parser.tab.c"
    break;

  case 110: /* simpleExp: simpleExp OR andExp  */
#line 221 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2395 "parser.tab.c"
    break;

  case 111: /* simpleExp: andExp  */
#line 222 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2401 "parser.tab.c"
    break;

  case 112: /* simpleExp: simpleExp OR error  */
#line 223 "parser.y"
                                        {(yyval.tree) = NULL;}
#line 2407 "parser.tab.c"
    break;

  case 113: /* andExp: andExp AND unaryRelExp  */
#line 226 "parser.y"
                                            {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[-2].tree), (yyvsp[0].tree), NULL); (yyval.tree)=node; }
#line 2413 "parser.tab.c"
    break;

  case 114: /* andExp: unaryRelExp  */
#line 227 "parser.y"
                                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2419 "parser.tab.c"
    break;

  case 115: /* andExp: andExp AND error  */
#line 228 "parser.y"
                                            {(yyval.tree) = NULL;}
#line 2425 "parser.tab.c"
    break;

  case 116: /* unaryRelExp: NOT unaryRelExp  */
#line 231 "parser.y"
                                        {treeNode* node = newExpNode(OpK, (yyvsp[-1].tokenData), (yyvsp[0].tree), NULL, NULL); (yyval.tree)=node; }
#line 2431 "parser.tab.c"
    break;

  case 117: /* unaryRelExp: relExp  */
#line 232 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2437 "parser.tab.c"
    break;

  case 118: /* unaryRelExp: NOT error  */
#line 233 "parser.y"
                                        {(yyval.tree)=NULL;}
#line 2443 "parser.tab.c"
    break;

  case 119: /* relExp: sumExp relop sumExp  */
#line 236 "parser.y"
                                       {if((yyvsp[-1].tree)!=NULL){(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1);} (yyval.tree)=(yyvsp[-1].tree);}
#line 2449 "parser.tab.c"
    break;

  case 120: /* relExp: sumExp  */
#line 237 "parser.y"
                                       {(yyval.tree)=(yyvsp[0].tree);}
#line 2455 "parser.tab.c"
    break;

  case 121: /* relExp: sumExp relop error  */
#line 238 "parser.y"
                                       {(yyval.tree)=NULL;}
#line 2461 "parser.tab.c"
    break;

  case 122: /* relop: LESS  */
#line 241 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2467 "parser.tab.c"
    break;

  case 123: /* relop: LEQ  */
#line 242 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2473 "parser.tab.c"
    break;

  case 124: /* relop: GREATER  */
#line 243 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2479 "parser.tab.c"
    break;

  case 125: /* relop: GEQ  */
#line 244 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2485 "parser.tab.c"
    break;

  case 126: /* relop: EQ  */
#line 245 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2491 "parser.tab.c"
    break;

  case 127: /* relop: NEQ  */
#line 246 "parser.y"
                            {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData)); (yyval.tree)=node;}
#line 2497 "parser.tab.c"
    break;

  case 128: /* sumExp: sumExp sumop mulExp  */
#line 249 "parser.y"
                                      {if((yyvsp[-1].tree)!=NULL){(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1);} (yyval.tree)=(yyvsp[-1].tree);}
#line 2503 "parser.tab.c"
    break;

  case 129: /* sumExp: mulExp  */
#line 250 "parser.y"
                                      {(yyval.tree)=(yyvsp[0].tree); }
#line 2509 "parser.tab.c"
    break;

  case 130: /* sumExp: sumExp sumop error  */
#line 251 "parser.y"
                                      {(yyval.tree)=NULL; }
#line 2515 "parser.tab.c"
    break;

  case 131: /* sumop: ADD  */
#line 254 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2521 "parser.tab.c"
    break;

  case 132: /* sumop: SUB  */
#line 255 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2527 "parser.tab.c"
    break;

  case 133: /* mulExp: mulExp mulop unaryExp  */
#line 258 "parser.y"
                                        {if((yyvsp[-1].tree)!=NULL){(yyvsp[-1].tree)->addChildren((yyvsp[-2].tree),0); (yyvsp[-1].tree)->addChildren((yyvsp[0].tree),1);} (yyval.tree)=(yyvsp[-1].tree);}
#line 2533 "parser.tab.c"
    break;

  case 134: /* mulExp: unaryExp  */
#line 259 "parser.y"
                               {(yyval.tree)=(yyvsp[0].tree);}
#line 2539 "parser.tab.c"
    break;

  case 135: /* mulExp: mulExp mulop error  */
#line 260 "parser.y"
                                     {(yyval.tree)=NULL; }
#line 2545 "parser.tab.c"
    break;

  case 136: /* mulop: MUL  */
#line 263 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2551 "parser.tab.c"
    break;

  case 137: /* mulop: DIV  */
#line 264 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2557 "parser.tab.c"
    break;

  case 138: /* mulop: MOD  */
#line 265 "parser.y"
                      {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2563 "parser.tab.c"
    break;

  case 139: /* unaryExp: unaryOp unaryExp  */
#line 268 "parser.y"
                                   {if((yyvsp[-1].tree)!=NULL)(yyvsp[-1].tree)->addChildren((yyvsp[0].tree),0); (yyval.tree)=(yyvsp[-1].tree);}
#line 2569 "parser.tab.c"
    break;

  case 140: /* unaryExp: factor  */
#line 269 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2575 "parser.tab.c"
    break;

  case 141: /* unaryExp: unaryOp error  */
#line 270 "parser.y"
                                   {(yyval.tree)=NULL; }
#line 2581 "parser.tab.c"
    break;

  case 142: /* unaryOp: chsign  */
#line 273 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2587 "parser.tab.c"
    break;

  case 143: /* unaryOp: sizeof  */
#line 274 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2593 "parser.tab.c"
    break;

  case 144: /* unaryOp: QMARK  */
#line 275 "parser.y"
                                {treeNode* node = newExpNode(OpK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2599 "parser.tab.c"
    break;

  case 145: /* chsign: SUB  */
#line 278 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("chsign"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2606 "parser.tab.c"
    break;

  case 146: /* sizeof: MUL  */
#line 281 "parser.y"
                        {   free ((yyvsp[0].tokenData)->tokenstr);
                            (yyvsp[0].tokenData)->tokenstr=strdup("sizeof"); (yyval.tokenData)=(yyvsp[0].tokenData);  /*This might be really really wrong lol*/}
#line 2613 "parser.tab.c"
    break;

  case 147: /* factor: mutable  */
#line 285 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2619 "parser.tab.c"
    break;

  case 148: /* factor: immutable  */
#line 286 "parser.y"
                                    {(yyval.tree)=(yyvsp[0].tree);}
#line 2625 "parser.tab.c"
    break;

  case 149: /* mutable: ID  */
#line 289 "parser.y"
                                             {treeNode* node = newExpNode(IdK, (yyvsp[0].tokenData), NULL, NULL, NULL); (yyval.tree)=node; }
#line 2631 "parser.tab.c"
    break;

  case 150: /* mutable: ID LBRACK exp RBRACK  */
#line 290 "parser.y"
                                            {
                                                treeNode* IDNode = newExpNode(IdK, (yyvsp[-3].tokenData), NULL, NULL, NULL);
                                                treeNode* node = newExpNode(OpK, (yyvsp[-2].tokenData), IDNode, (yyvsp[-1].tree), NULL); (yyval.tree)=node; /*Something is up with this one LOL*/ }
#line 2639 "parser.tab.c"
    break;

  case 151: /* immutable: LPAREN exp RPAREN  */
#line 295 "parser.y"
                                        {(yyval.tree)=(yyvsp[-1].tree); yyerrok;}
#line 2645 "parser.tab.c"
    break;

  case 152: /* immutable: call  */
#line 296 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2651 "parser.tab.c"
    break;

  case 153: /* immutable: constant  */
#line 297 "parser.y"
                                        {(yyval.tree)=(yyvsp[0].tree);}
#line 2657 "parser.tab.c"
    break;

  case 154: /* immutable: LPAREN error  */
#line 298 "parser.y"
                                        {(yyval.tree)=NULL; }
#line 2663 "parser.tab.c"
    break;

  case 155: /* call: ID LPAREN args RPAREN  */
#line 301 "parser.y"
                                         {treeNode* node = newExpNode(CallK, (yyvsp[-3].tokenData), (yyvsp[-1].tree), NULL, NULL); (yyval.tree)=node;}
#line 2669 "parser.tab.c"
    break;

  case 156: /* call: error LPAREN  */
#line 302 "parser.y"
                                    {(yyval.tree)=NULL;  yyerrok; }
#line 2675 "parser.tab.c"
    break;

  case 157: /* args: argList  */
#line 305 "parser.y"
                            {(yyval.tree)=(yyvsp[0].tree);}
#line 2681 "parser.tab.c"
    break;

  case 158: /* args: %empty  */
#line 306 "parser.y"
                           {(yyval.tree)=NULL;}
#line 2687 "parser.tab.c"
    break;

  case 159: /* argList: argList COMMA exp  */
#line 309 "parser.y"
                                    {if((yyvsp[-2].tree)!=NULL) (yyvsp[-2].tree)->addSibling((yyvsp[0].tree)); (yyval.tree)=(yyvsp[-2].tree); yyerrok;}
#line 2693 "parser.tab.c"
    break;

  case 160: /* argList: exp  */
#line 310 "parser.y"
                                {(yyval.tree)=(yyvsp[0].tree);}
#line 2699 "parser.tab.c"
    break;

  case 161: /* argList: argList COMMA error  */
#line 311 "parser.y"
                                      {(yyval.tree)=NULL;}
#line 2705 "parser.tab.c"
    break;

  case 162: /* constant: NUMCONST  */
#line 314 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Integer), (yyval.tree)=node; }
#line 2711 "parser.tab.c"
    break;

  case 163: /* constant: CHARCONST  */
#line 315 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), (yyval.tree)=node; }
#line 2717 "parser.tab.c"
    break;

  case 164: /* constant: STRINGCONST  */
#line 316 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(Char), node->setArray(true); (yyval.tree)=node; }
#line 2723 "parser.tab.c"
    break;

  case 165: /* constant: BOOLCONST  */
#line 317 "parser.y"
                                 {treeNode* node = newExpNode(constantK, (yyvsp[0].tokenData), NULL, NULL, NULL); node->EType(boolean), (yyval.tree)=node; }
#line 2729 "parser.tab.c"
    break;


#line 2733 "parser.tab.c"

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

#line 320 "parser.y"

