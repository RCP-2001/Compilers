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


#line 93 "parser.tab.c"

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
  YYSYMBOL_factor = 97,                    /* factor  */
  YYSYMBOL_mutable = 98,                   /* mutable  */
  YYSYMBOL_immutable = 99,                 /* immutable  */
  YYSYMBOL_call = 100,                     /* call  */
  YYSYMBOL_args = 101,                     /* args  */
  YYSYMBOL_argList = 102,                  /* argList  */
  YYSYMBOL_constant = 103                  /* constant  */
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
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

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
       0,    34,    34,    37,    38,    41,    42,    45,    48,    49,
      52,    53,    56,    57,    60,    61,    64,    65,    66,    69,
      70,    73,    74,    77,    78,    81,    84,    85,    89,    90,
      93,    94,    97,    98,   101,   102,   103,   106,   107,   109,
     112,   113,   114,   115,   118,   119,   122,   125,   126,   129,
     130,   133,   134,   137,   138,   141,   142,   145,   146,   149,
     152,   153,   154,   155,   157,   158,   159,   160,   161,   164,
     165,   168,   169,   172,   173,   176,   177,   180,   181,   182,
     183,   184,   185,   188,   189,   192,   193,   196,   197,   200,
     201,   202,   205,   206,   209,   210,   211,   214,   215,   218,
     219,   222,   223,   224,   227,   230,   231,   234,   235,   238,
     239,   240,   241
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
  "factor", "mutable", "immutable", "call", "args", "argList", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     138,   -47,   -75,   -75,   -75,    32,   138,   -75,   -75,     3,
     -75,   151,   -75,   -75,    -7,   -11,   -75,    22,    53,     8,
      42,   -75,    74,   151,   -75,    78,    13,    64,    91,   -75,
      60,   151,    75,    87,    99,   -75,    38,   -75,   -75,   -75,
     -75,    13,   -75,   -75,   -75,    13,   122,   127,   -75,   -75,
     113,   123,   -75,     6,   -75,   -75,   -75,   -75,   -75,   116,
      53,   -75,   -75,   -75,   -75,    60,    13,    13,   -75,   115,
     122,   100,    13,    13,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,     6,     6,   -75,   -75,   -75,     6,   -75,   -75,
     -75,   106,   -75,   145,   -75,   124,   149,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,    13,   127,   -75,    62,   123,
     -75,   151,   -75,    78,    23,   -75,   -75,    13,   -75,    78,
     139,    13,    13,   174,   117,   153,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     154,   -75,   147,   -75,   168,    55,   131,   -75,   157,   -75,
     -75,   -75,    80,    80,    13,   -75,   -75,   170,   -75,   -75,
     169,    14,    80,    80,    13,   -75,   -75,   -75,   -75,    29,
      13,   122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    17,    16,    18,     0,     2,     4,     5,     0,
       6,    22,     1,     3,    14,     0,    11,    12,     0,     0,
      21,    24,     0,    22,     7,     0,     0,    28,    25,    27,
       0,     0,     0,     0,    14,    10,    99,   109,   110,   111,
     112,     0,    94,    95,    96,     0,    13,    70,    72,    74,
      76,    84,    88,     0,    93,    97,    98,   102,   103,     0,
       0,    48,    20,    23,    15,     0,     0,   106,    73,     0,
      63,    97,     0,     0,    78,    80,    77,    79,    81,    82,
      85,    86,     0,     0,    89,    90,    91,     0,    92,    29,
      26,    50,    19,     0,   108,     0,   105,   101,    61,    62,
      65,    66,    67,    68,    64,     0,    69,    71,    75,    83,
      87,     0,    47,     0,     0,   100,   104,     0,    60,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    49,    30,
      31,    33,    34,    36,    40,    41,    32,    35,    43,    42,
       0,   107,     0,     9,     0,     0,     0,    57,     0,    59,
      44,     8,     0,     0,     0,    58,    37,    31,    51,    53,
       0,     0,     0,     0,     0,    38,    39,    52,    54,    55,
       0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   178,   -75,   -75,   -74,   161,   -75,     2,
     -75,   164,   -75,   158,   -75,   128,    39,   -65,   -51,   -75,
     -75,   -75,   -75,   -25,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -42,   -75,   -26,   118,    -8,   -75,   -75,   110,   -75,
     111,   -75,   -46,   -75,   -75,   -44,   -75,   -75,   -75,   -75,
     -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   112,    15,    16,    17,    18,
      10,    19,    20,    21,    28,    29,   128,   129,   130,   131,
     132,   133,   134,   135,    91,   114,   136,   137,   160,   138,
     139,   140,   105,    70,    47,    48,    49,    82,    50,    83,
      51,    87,    52,    53,    54,    55,    56,    57,    95,    96,
      58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    71,     9,    69,    11,    62,    14,    88,     9,    36,
      37,    38,    39,    40,    24,    25,    36,    37,    38,    39,
      40,    22,    71,    71,    93,    94,    36,    37,    38,    39,
      40,   164,    12,    68,   121,    72,    41,   122,   123,   120,
      92,   110,   124,   125,    23,   142,    41,   170,   126,    26,
      72,    42,    43,    61,   127,    44,    27,    45,    42,    43,
      30,    71,    44,   118,    45,   107,    66,    31,    42,    43,
      71,   153,    44,    71,    45,   141,    72,    71,    32,   144,
      71,    34,   148,    36,    37,    38,    39,    40,   158,    67,
      61,   121,    59,   113,   122,   123,   145,   165,   167,   124,
     125,   157,   159,    41,    64,   126,    80,    81,    71,    71,
      61,   166,   168,   119,     2,     3,     4,    60,    71,    71,
      36,    37,    38,    39,    40,    42,    43,    22,   161,    44,
     111,    45,    98,    99,   100,   101,   102,   103,   169,    65,
      41,     1,   147,    72,   171,    89,     2,     3,     4,    73,
     104,    74,    75,    76,    77,    78,    79,    80,    81,     2,
       3,     4,    42,    43,   143,    25,    44,    97,    45,    84,
      85,    86,   151,    25,   115,   117,   116,   146,   149,   150,
     152,   154,   155,   162,    13,   163,    35,    33,    90,    63,
     106,   156,   108,     0,   109
};

static const yytype_int16 yycheck[] =
{
      26,    45,     0,    45,    51,    30,     3,    53,     6,     3,
       4,     5,     6,     7,    25,    26,     3,     4,     5,     6,
       7,    28,    66,    67,    66,    67,     3,     4,     5,     6,
       7,    17,     0,    41,    11,    21,    23,    14,    15,   113,
      65,    87,    19,    20,    51,   119,    23,    18,    25,    27,
      21,    45,    46,    30,    31,    49,     3,    51,    45,    46,
      52,   105,    49,   105,    51,    73,    28,    25,    45,    46,
     114,    16,    49,   117,    51,   117,    21,   121,     4,   121,
     124,     3,   124,     3,     4,     5,     6,     7,   153,    51,
      30,    11,    28,    91,    14,    15,   122,   162,   163,    19,
      20,   152,   153,    23,    29,    25,    44,    45,   152,   153,
      30,   162,   163,   111,     8,     9,    10,    26,   162,   163,
       3,     4,     5,     6,     7,    45,    46,    28,   154,    49,
      24,    51,    32,    33,    34,    35,    36,    37,   164,    52,
      23,     3,    25,    21,   170,    29,     8,     9,    10,    22,
      50,    38,    39,    40,    41,    42,    43,    44,    45,     8,
       9,    10,    45,    46,    25,    26,    49,    52,    51,    46,
      47,    48,    25,    26,    29,    26,    52,     3,    25,    25,
      12,    50,    25,    13,     6,    16,    25,    23,    60,    31,
      72,   152,    82,    -1,    83
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
      91,    93,    95,    96,    97,    98,    99,   100,   103,    28,
      26,    30,    76,    66,    29,    52,    28,    51,    88,    84,
      86,    98,    21,    22,    38,    39,    40,    41,    42,    43,
      44,    45,    90,    92,    46,    47,    48,    94,    95,    29,
      68,    77,    76,    84,    84,   101,   102,    52,    32,    33,
      34,    35,    36,    37,    50,    85,    87,    88,    91,    93,
      95,    24,    58,    62,    78,    29,    52,    26,    84,    62,
      59,    11,    14,    15,    19,    20,    25,    31,    69,    70,
      71,    72,    73,    74,    75,    76,    79,    80,    82,    83,
      84,    84,    59,    25,    84,    86,     3,    25,    84,    25,
      25,    25,    12,    16,    50,    25,    69,    71,    70,    71,
      81,    86,    13,    16,    17,    70,    71,    70,    71,    86,
      18,    86
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
      94,    94,    95,    95,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   101,   101,   102,   102,   103,
     103,   103,   103
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
       4,     3,     1,     1,     4,     1,     0,     3,     1,     1,
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
#line 34 "parser.y"
                        {printf("program accepted\n");}
#line 1320 "parser.tab.c"
    break;

  case 3: /* declist: declist decl  */
#line 37 "parser.y"
                        {printf("declist\n");}
#line 1326 "parser.tab.c"
    break;

  case 4: /* declist: decl  */
#line 38 "parser.y"
                        {printf("declist\n");}
#line 1332 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 41 "parser.y"
                   {printf("decl \n");}
#line 1338 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 42 "parser.y"
                   {printf("decl \n");}
#line 1344 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec varDeclList SEMI  */
#line 45 "parser.y"
                                            {printf("varDecl\n");}
#line 1350 "parser.tab.c"
    break;

  case 8: /* scopedVarDecl: STATIC typeSpec varDeclList SEMI  */
#line 48 "parser.y"
                                                         {printf("scopedVardecl \n");}
#line 1356 "parser.tab.c"
    break;

  case 9: /* scopedVarDecl: typeSpec varDeclList SEMI  */
#line 49 "parser.y"
                                                    {printf("scopedVardecl \n");}
#line 1362 "parser.tab.c"
    break;

  case 10: /* varDeclList: varDeclList COMMA varDeclInit  */
#line 52 "parser.y"
                                                    {printf("VardecLList \n");}
#line 1368 "parser.tab.c"
    break;

  case 11: /* varDeclList: varDeclInit  */
#line 53 "parser.y"
                                                    {printf("VardecLList \n");}
#line 1374 "parser.tab.c"
    break;

  case 12: /* varDeclInit: varDeclID  */
#line 56 "parser.y"
                                                    {printf("VardecLInnit \n");}
#line 1380 "parser.tab.c"
    break;

  case 13: /* varDeclInit: varDeclID COLON simpleExp  */
#line 57 "parser.y"
                                                    {printf("VardecLInnit \n");}
#line 1386 "parser.tab.c"
    break;

  case 14: /* varDeclID: ID  */
#line 60 "parser.y"
                                                    {printf("VarDecID\n");}
#line 1392 "parser.tab.c"
    break;

  case 15: /* varDeclID: ID LBRACK NUMCONST RBRACK  */
#line 61 "parser.y"
                                                    {printf("VarDecID\n");}
#line 1398 "parser.tab.c"
    break;

  case 16: /* typeSpec: INT  */
#line 64 "parser.y"
                                                    {printf("typespec\n");}
#line 1404 "parser.tab.c"
    break;

  case 17: /* typeSpec: BOOL  */
#line 65 "parser.y"
                                                    {printf("typespec\n");}
#line 1410 "parser.tab.c"
    break;

  case 18: /* typeSpec: CHAR  */
#line 66 "parser.y"
                                                    {printf("typespec\n");}
#line 1416 "parser.tab.c"
    break;

  case 19: /* funDecl: typeSpec ID LPAREN params RPAREN compoundStmt  */
#line 69 "parser.y"
                                                                            {printf("funDecl\n");}
#line 1422 "parser.tab.c"
    break;

  case 20: /* funDecl: ID LPAREN params RPAREN compoundStmt  */
#line 70 "parser.y"
                                                                            {printf("funDecl\n");}
#line 1428 "parser.tab.c"
    break;

  case 21: /* params: paramList  */
#line 73 "parser.y"
                            {printf("params\n");}
#line 1434 "parser.tab.c"
    break;

  case 22: /* params: %empty  */
#line 74 "parser.y"
                            {printf("params \n");}
#line 1440 "parser.tab.c"
    break;

  case 23: /* paramList: paramList SEMI paramTypeList  */
#line 77 "parser.y"
                                                    {printf("paramList\n");}
#line 1446 "parser.tab.c"
    break;

  case 24: /* paramList: paramTypeList  */
#line 78 "parser.y"
                                                    {printf("paramList\n");}
#line 1452 "parser.tab.c"
    break;

  case 25: /* paramTypeList: typeSpec paramIDList  */
#line 81 "parser.y"
                                                    {printf("paramTypeList\n");}
#line 1458 "parser.tab.c"
    break;

  case 26: /* paramIDList: paramIDList COMMA paramID  */
#line 84 "parser.y"
                                                    {printf("paramIdList\n");}
#line 1464 "parser.tab.c"
    break;

  case 27: /* paramIDList: paramID  */
#line 85 "parser.y"
                                                    {printf("paramIdList\n");}
#line 1470 "parser.tab.c"
    break;

  case 28: /* paramID: ID  */
#line 89 "parser.y"
                                                    {printf("ParamID\n");}
#line 1476 "parser.tab.c"
    break;

  case 29: /* paramID: ID LBRACK RBRACK  */
#line 90 "parser.y"
                                                    {printf("ParamID\n");}
#line 1482 "parser.tab.c"
    break;

  case 30: /* stmt: openStatement  */
#line 93 "parser.y"
                                    {printf("stmt\n");}
#line 1488 "parser.tab.c"
    break;

  case 31: /* stmt: closedStatement  */
#line 94 "parser.y"
                                    {printf("stmt\n");}
#line 1494 "parser.tab.c"
    break;

  case 32: /* openStatement: openItrStmt  */
#line 97 "parser.y"
                                            {printf("openStatement\n");}
#line 1500 "parser.tab.c"
    break;

  case 33: /* openStatement: openSelectStatement  */
#line 98 "parser.y"
                                            {printf("openStatement\n");}
#line 1506 "parser.tab.c"
    break;

  case 34: /* closedStatement: closedSelectStatement  */
#line 101 "parser.y"
                                            {printf("closedStatement\n");}
#line 1512 "parser.tab.c"
    break;

  case 35: /* closedStatement: closedItrStmt  */
#line 102 "parser.y"
                                            {printf("closedStatemnet\n");}
#line 1518 "parser.tab.c"
    break;

  case 36: /* closedStatement: simpleStatement  */
#line 103 "parser.y"
                                            {printf("closedStatement\n");}
#line 1524 "parser.tab.c"
    break;

  case 37: /* openSelectStatement: IF exp THEN stmt  */
#line 106 "parser.y"
                                                   {printf("OpenSelectaStatemnet\n");}
#line 1530 "parser.tab.c"
    break;

  case 38: /* openSelectStatement: IF exp THEN closedStatement ELSE openStatement  */
#line 107 "parser.y"
                                                                           {printf("openSelectaStatement\n");}
#line 1536 "parser.tab.c"
    break;

  case 39: /* closedSelectStatement: IF exp THEN closedStatement ELSE closedStatement  */
#line 109 "parser.y"
                                                                           {printf("closedSelctaStatement\n");}
#line 1542 "parser.tab.c"
    break;

  case 40: /* simpleStatement: expStmt  */
#line 112 "parser.y"
                                        {printf("Simpstmt\n");}
#line 1548 "parser.tab.c"
    break;

  case 41: /* simpleStatement: compoundStmt  */
#line 113 "parser.y"
                                        {printf("Simpstmt\n");}
#line 1554 "parser.tab.c"
    break;

  case 42: /* simpleStatement: breakStmt  */
#line 114 "parser.y"
                                        {printf("Simpstmt\n");}
#line 1560 "parser.tab.c"
    break;

  case 43: /* simpleStatement: returnStmt  */
#line 115 "parser.y"
                                        {printf("Simpstmt\n");}
#line 1566 "parser.tab.c"
    break;

  case 45: /* expStmt: SEMI  */
#line 119 "parser.y"
                               {printf("expStmt\n");}
#line 1572 "parser.tab.c"
    break;

  case 46: /* compoundStmt: LCURL LocalDecls stmtList RCURL  */
#line 122 "parser.y"
                                                        {printf("compound\n");}
#line 1578 "parser.tab.c"
    break;

  case 47: /* LocalDecls: LocalDecls scopedVarDecl  */
#line 125 "parser.y"
                                                        {printf("localDecals\n");}
#line 1584 "parser.tab.c"
    break;

  case 48: /* LocalDecls: %empty  */
#line 126 "parser.y"
                                                        {printf("Localdecals\n");}
#line 1590 "parser.tab.c"
    break;

  case 49: /* stmtList: stmtList stmt  */
#line 129 "parser.y"
                                    {printf("stmtList\n");}
#line 1596 "parser.tab.c"
    break;

  case 50: /* stmtList: %empty  */
#line 130 "parser.y"
                                    {printf("stmtList\n");}
#line 1602 "parser.tab.c"
    break;

  case 51: /* openItrStmt: WHILE simpleExp DO openStatement  */
#line 133 "parser.y"
                                                        {printf("OpenItrStmt\n");}
#line 1608 "parser.tab.c"
    break;

  case 52: /* openItrStmt: FOR ID ASSIGN itrRange DO openStatement  */
#line 134 "parser.y"
                                                            {printf("OpenItrStmt\n");}
#line 1614 "parser.tab.c"
    break;

  case 53: /* closedItrStmt: WHILE simpleExp DO closedStatement  */
#line 137 "parser.y"
                                                        {printf("ClosedItrStmt\n");}
#line 1620 "parser.tab.c"
    break;

  case 54: /* closedItrStmt: FOR ID ASSIGN itrRange DO closedStatement  */
#line 138 "parser.y"
                                                            {printf("ClosedItrStmt\n");}
#line 1626 "parser.tab.c"
    break;

  case 55: /* itrRange: simpleExp TO simpleExp  */
#line 141 "parser.y"
                                                        {printf("itrRange");}
#line 1632 "parser.tab.c"
    break;

  case 56: /* itrRange: simpleExp TO simpleExp BY simpleExp  */
#line 142 "parser.y"
                                                        {printf("itrRange");}
#line 1638 "parser.tab.c"
    break;

  case 57: /* returnStmt: RETURN SEMI  */
#line 145 "parser.y"
                                          {printf("returnStmt\n");}
#line 1644 "parser.tab.c"
    break;

  case 58: /* returnStmt: RETURN exp SEMI  */
#line 146 "parser.y"
                                          {printf("returnStmt\n");}
#line 1650 "parser.tab.c"
    break;

  case 59: /* breakStmt: BREAK SEMI  */
#line 149 "parser.y"
                                        {printf("BreakStmt\n");}
#line 1656 "parser.tab.c"
    break;

  case 60: /* exp: mutable assignop exp  */
#line 152 "parser.y"
                                            {printf("mutable assignop exp\n");}
#line 1662 "parser.tab.c"
    break;

  case 61: /* exp: mutable INC  */
#line 153 "parser.y"
                                            {printf("mutable INC exp\n");}
#line 1668 "parser.tab.c"
    break;

  case 62: /* exp: mutable DEC  */
#line 154 "parser.y"
                                            {printf("mutable DEC exp\n");}
#line 1674 "parser.tab.c"
    break;

  case 63: /* exp: simpleExp  */
#line 155 "parser.y"
                                            {printf("Simpleexp exp\n");}
#line 1680 "parser.tab.c"
    break;

  case 64: /* assignop: ASSIGN  */
#line 157 "parser.y"
                                {printf("assignop\n");}
#line 1686 "parser.tab.c"
    break;

  case 65: /* assignop: ADDASS  */
#line 158 "parser.y"
                                {printf("assignop\n");}
#line 1692 "parser.tab.c"
    break;

  case 66: /* assignop: DECASS  */
#line 159 "parser.y"
                                {printf("assignop\n");}
#line 1698 "parser.tab.c"
    break;

  case 67: /* assignop: MULASS  */
#line 160 "parser.y"
                                {printf("assignop\n");}
#line 1704 "parser.tab.c"
    break;

  case 68: /* assignop: DIVASS  */
#line 161 "parser.y"
                                {printf("assignop\n");}
#line 1710 "parser.tab.c"
    break;

  case 69: /* simpleExp: simpleExp OR andExp  */
#line 164 "parser.y"
                                        {printf("simpleExp\n");}
#line 1716 "parser.tab.c"
    break;

  case 70: /* simpleExp: andExp  */
#line 165 "parser.y"
                                        {printf("simpleExp\n");}
#line 1722 "parser.tab.c"
    break;

  case 71: /* andExp: andExp AND unaryRelExp  */
#line 168 "parser.y"
                                            {printf("andExp\n");}
#line 1728 "parser.tab.c"
    break;

  case 72: /* andExp: unaryRelExp  */
#line 169 "parser.y"
                                            {printf("andExp\n");}
#line 1734 "parser.tab.c"
    break;

  case 73: /* unaryRelExp: NOT unaryRelExp  */
#line 172 "parser.y"
                                  {printf("unaryRelExp\n");}
#line 1740 "parser.tab.c"
    break;

  case 74: /* unaryRelExp: relExp  */
#line 173 "parser.y"
                          {printf("unaryRelExp\n");}
#line 1746 "parser.tab.c"
    break;

  case 75: /* relExp: sumExp relop sumExp  */
#line 176 "parser.y"
                                       {printf("relExp\n");}
#line 1752 "parser.tab.c"
    break;

  case 76: /* relExp: sumExp  */
#line 177 "parser.y"
                                        {printf("relExp\n");}
#line 1758 "parser.tab.c"
    break;

  case 77: /* relop: LESS  */
#line 180 "parser.y"
                       {printf("relOp\n");}
#line 1764 "parser.tab.c"
    break;

  case 78: /* relop: LEQ  */
#line 181 "parser.y"
                      {printf("relOp\n");}
#line 1770 "parser.tab.c"
    break;

  case 79: /* relop: GREATER  */
#line 182 "parser.y"
                          {printf("relOp\n");}
#line 1776 "parser.tab.c"
    break;

  case 80: /* relop: GEQ  */
#line 183 "parser.y"
                      {printf("relOp\n");}
#line 1782 "parser.tab.c"
    break;

  case 81: /* relop: EQ  */
#line 184 "parser.y"
                     {printf("relOp\n");}
#line 1788 "parser.tab.c"
    break;

  case 82: /* relop: NEQ  */
#line 185 "parser.y"
                     {printf("relOp\n");}
#line 1794 "parser.tab.c"
    break;

  case 83: /* sumExp: sumExp sumop mulExp  */
#line 188 "parser.y"
                                      {printf("sumExp\n");}
#line 1800 "parser.tab.c"
    break;

  case 84: /* sumExp: mulExp  */
#line 189 "parser.y"
                         {printf("sumExp\n");}
#line 1806 "parser.tab.c"
    break;

  case 85: /* sumop: ADD  */
#line 192 "parser.y"
                      {printf("sumOp\n");}
#line 1812 "parser.tab.c"
    break;

  case 86: /* sumop: SUB  */
#line 193 "parser.y"
                      {printf("sumOp\n");}
#line 1818 "parser.tab.c"
    break;

  case 87: /* mulExp: mulExp mulop unaryExp  */
#line 196 "parser.y"
                                        {printf("mulExp\n");}
#line 1824 "parser.tab.c"
    break;

  case 88: /* mulExp: unaryExp  */
#line 197 "parser.y"
                               {printf("mulExp\n");}
#line 1830 "parser.tab.c"
    break;

  case 89: /* mulop: MUL  */
#line 200 "parser.y"
                      {printf("mulOp\n");}
#line 1836 "parser.tab.c"
    break;

  case 90: /* mulop: DIV  */
#line 201 "parser.y"
                      {printf("mulOp\n");}
#line 1842 "parser.tab.c"
    break;

  case 91: /* mulop: MOD  */
#line 202 "parser.y"
                     {printf("mulOp\n");}
#line 1848 "parser.tab.c"
    break;

  case 92: /* unaryExp: unaryOp unaryExp  */
#line 205 "parser.y"
                                   {printf("unaryExp\n");}
#line 1854 "parser.tab.c"
    break;

  case 93: /* unaryExp: factor  */
#line 206 "parser.y"
                                    {printf("unaryExp\n");}
#line 1860 "parser.tab.c"
    break;

  case 94: /* unaryOp: SUB  */
#line 209 "parser.y"
                      {printf("unaryOp\n");}
#line 1866 "parser.tab.c"
    break;

  case 95: /* unaryOp: MUL  */
#line 210 "parser.y"
                      {printf("unaryOp\n");}
#line 1872 "parser.tab.c"
    break;

  case 96: /* unaryOp: QMARK  */
#line 211 "parser.y"
                        {printf("unaryOp\n");}
#line 1878 "parser.tab.c"
    break;

  case 97: /* factor: mutable  */
#line 214 "parser.y"
                          {printf("factor\n");}
#line 1884 "parser.tab.c"
    break;

  case 98: /* factor: immutable  */
#line 215 "parser.y"
                            {printf("factor\n");}
#line 1890 "parser.tab.c"
    break;

  case 99: /* mutable: ID  */
#line 218 "parser.y"
                     {printf("mutable\n");}
#line 1896 "parser.tab.c"
    break;

  case 100: /* mutable: ID LBRACK exp RBRACK  */
#line 219 "parser.y"
                                       {printf("mutable\n");}
#line 1902 "parser.tab.c"
    break;

  case 101: /* immutable: LPAREN exp RPAREN  */
#line 222 "parser.y"
                                    {printf("immuntabe\n");}
#line 1908 "parser.tab.c"
    break;

  case 102: /* immutable: call  */
#line 223 "parser.y"
                                    {printf("immuntable\n");}
#line 1914 "parser.tab.c"
    break;

  case 103: /* immutable: constant  */
#line 224 "parser.y"
                                    {printf("immutable\n");}
#line 1920 "parser.tab.c"
    break;

  case 104: /* call: ID LPAREN args RPAREN  */
#line 227 "parser.y"
                                        {printf("call\n");}
#line 1926 "parser.tab.c"
    break;

  case 105: /* args: argList  */
#line 230 "parser.y"
                                    {printf("args\n");}
#line 1932 "parser.tab.c"
    break;

  case 106: /* args: %empty  */
#line 231 "parser.y"
                                  {printf("args\n");}
#line 1938 "parser.tab.c"
    break;

  case 107: /* argList: argList COMMA exp  */
#line 234 "parser.y"
                                    {printf("argList\n");}
#line 1944 "parser.tab.c"
    break;

  case 109: /* constant: NUMCONST  */
#line 238 "parser.y"
                           {printf("constant\n");}
#line 1950 "parser.tab.c"
    break;

  case 110: /* constant: CHARCONST  */
#line 239 "parser.y"
                            {printf("constant\n");}
#line 1956 "parser.tab.c"
    break;

  case 111: /* constant: STRINGCONST  */
#line 240 "parser.y"
                              {printf("constant\n");}
#line 1962 "parser.tab.c"
    break;

  case 112: /* constant: BOOLCONST  */
#line 241 "parser.y"
                            {printf("constant\n");}
#line 1968 "parser.tab.c"
    break;


#line 1972 "parser.tab.c"

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

#line 244 "parser.y"

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
