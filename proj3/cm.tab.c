/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cm.y" /* yacc.c:339  */

#define YYPARSER
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define MAX_STACK 256
#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo; /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static Type savedType;

int yyerror(char * message);
static int yylex(void);

static TokenType StackOp[MAX_STACK];
static char* StackID[MAX_STACK];
static Type StackType[MAX_STACK];
static int top = -1,top_id = -1,top_type = -1;

static int temp;

static void push_op(TokenType);
static int pop_op();
static void push_ID(char*);
static char* pop_ID();
static void push_type(Type);
static Type pop_type();

#define SAVEID do{\
    push_ID(copyString(prev));\
    savedLineNo = lineno;\
}while(0)\

#line 103 "cm.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cm.tab.h".  */
#ifndef YY_YY_CM_TAB_H_INCLUDED
# define YY_YY_CM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENDFILE = 258,
    ERROR = 259,
    IF = 260,
    INT = 261,
    VOID = 262,
    ELSE = 263,
    WHILE = 264,
    RETURN = 265,
    ID = 266,
    NUM = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    OVER = 271,
    GET = 272,
    GT = 273,
    LET = 274,
    LT = 275,
    EQ = 276,
    NEQ = 277,
    ASSIGN = 278,
    SEMI = 279,
    COMMA = 280,
    LPAREN = 281,
    RPAREN = 282,
    LCBRAKET = 283,
    RCBRAKET = 284,
    LSBRAKET = 285,
    RSBRAKET = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "cm.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    54,    65,    68,    69,    72,    72,    79,
      79,    79,    89,    90,    93,    93,   105,   106,   109,   117,
     120,   129,   129,   141,   149,   160,   163,   174,   177,   178,
     179,   180,   181,   184,   185,   188,   194,   203,   211,   215,
     223,   230,   233,   239,   239,   248,   255,   258,   259,   260,
     261,   262,   263,   266,   273,   277,   278,   281,   288,   291,
     292,   295,   296,   297,   298,   306,   306,   314,   315,   318,
     330,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENDFILE", "ERROR", "IF", "INT", "VOID",
  "ELSE", "WHILE", "RETURN", "ID", "NUM", "PLUS", "MINUS", "TIMES", "OVER",
  "GET", "GT", "LET", "LT", "EQ", "NEQ", "ASSIGN", "SEMI", "COMMA",
  "LPAREN", "RPAREN", "LCBRAKET", "RCBRAKET", "LSBRAKET", "RSBRAKET",
  "$accept", "program", "declaration-list", "declaration",
  "var-declaration", "$@1", "$@2", "$@3", "type-specifier",
  "fun-declaration", "$@4", "params", "param-list", "param", "$@5",
  "compound-stmt", "local-declarations", "statement-list", "statement",
  "expression-stmt", "selection-stmt", "iteration-stmt", "return-stmt",
  "expression", "var", "$@6", "simple-expression", "relop",
  "additive-expression", "addop", "term", "mulop", "factor", "call", "$@7",
  "args", "arg-list", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      34,   -60,   -60,     3,    34,   -60,   -60,    -6,   -60,   -60,
     -60,    -2,   -13,   -17,    -8,   -60,    20,    58,   -60,    28,
      59,    44,    47,   -60,    42,    45,    46,    34,    52,    48,
     -60,   -60,   -60,   -60,    49,    34,   -60,   -60,   -60,    66,
      -3,   -60,    53,    56,    60,    23,    22,   -60,   -60,    25,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,    57,    61,   -60,
      40,    51,   -60,   -60,    25,    25,   -60,    63,    62,    64,
      67,   -60,    25,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,    25,    25,   -60,   -60,    25,    68,    69,   -60,    25,
      25,   -60,   -60,   -60,    55,    51,   -60,     5,     5,    54,
     -60,    70,    73,   -60,    71,   -60,   -60,   -60,    25,     5,
     -60,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,     0,     2,     4,     5,     0,     6,     1,
       3,     7,     0,     0,     0,     8,     0,     0,    10,    13,
       0,     0,    16,    19,     0,    20,     0,     0,     0,     0,
      71,    15,    18,    11,     0,    71,    25,    22,    24,     0,
       0,    27,     7,     0,     0,     0,    42,    64,    34,     0,
      23,    29,    26,    28,    30,    31,    32,     0,    62,    41,
      46,    54,    58,    63,     0,     0,    38,     0,     0,     0,
       0,    33,     0,    55,    56,    50,    49,    48,    47,    51,
      52,     0,     0,    59,    60,     0,     0,     0,    39,     0,
      71,    61,    40,    62,    45,    53,    57,     0,     0,     0,
      70,     0,    67,    68,    35,    37,    44,    66,     0,     0,
      69,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,    84,    65,   -60,   -60,   -60,    -5,   -60,
     -60,   -60,   -60,    72,   -60,    75,   -60,   -60,   -59,   -60,
     -60,   -60,   -60,   -45,   -39,   -60,   -60,   -60,     8,   -60,
       9,   -60,    17,   -60,   -60,   -60,   -60,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    12,    13,    24,     7,     8,
      14,    21,    22,    23,    29,    51,    35,    40,    52,    53,
      54,    55,    56,    57,    58,    68,    59,    81,    60,    82,
      61,    85,    62,    63,    69,   101,   102,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    41,    43,     9,    70,    11,    44,    45,    46,    47,
      43,    15,    20,    16,    44,    45,    46,    47,    17,    86,
      87,    48,    20,    49,   -14,    30,    50,    92,    -9,    48,
      39,    49,    18,    30,    46,    47,    46,    47,   104,   105,
       1,     2,    93,    93,    99,   100,    93,    66,   -65,    49,
     111,    49,   -43,    73,    74,   -17,   103,    75,    76,    77,
      78,    79,    80,   110,     1,    19,    83,    84,    73,    74,
      25,    26,    27,    28,    30,   -21,    33,    42,    34,   109,
      37,    71,    64,    -9,    72,   106,    65,    88,    10,    94,
      90,    95,    89,     0,    91,    97,    98,   107,   108,    32,
      38,    31,    96
};

static const yytype_int8 yycheck[] =
{
      45,    35,     5,     0,    49,    11,     9,    10,    11,    12,
       5,    24,    17,    30,     9,    10,    11,    12,    26,    64,
      65,    24,    27,    26,    26,    28,    29,    72,    30,    24,
      35,    26,    12,    28,    11,    12,    11,    12,    97,    98,
       6,     7,    81,    82,    89,    90,    85,    24,    26,    26,
     109,    26,    30,    13,    14,    27,    90,    17,    18,    19,
      20,    21,    22,   108,     6,     7,    15,    16,    13,    14,
      11,    27,    25,    31,    28,    30,    24,    11,    30,     8,
      31,    24,    26,    30,    23,    31,    26,    24,     4,    81,
      26,    82,    30,    -1,    27,    27,    27,    27,    25,    27,
      35,    26,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    33,    34,    35,    36,    40,    41,     0,
      35,    11,    37,    38,    42,    24,    30,    26,    12,     7,
      40,    43,    44,    45,    39,    11,    27,    25,    31,    46,
      28,    47,    45,    24,    30,    48,    69,    31,    36,    40,
      49,    69,    11,     5,     9,    10,    11,    12,    24,    26,
      29,    47,    50,    51,    52,    53,    54,    55,    56,    58,
      60,    62,    64,    65,    26,    26,    24,    55,    57,    66,
      55,    24,    23,    13,    14,    17,    18,    19,    20,    21,
      22,    59,    61,    15,    16,    63,    55,    55,    24,    30,
      26,    27,    55,    56,    60,    62,    64,    27,    27,    55,
      55,    67,    68,    69,    50,    50,    31,    27,    25,     8,
      55,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    37,    36,    38,
      39,    36,    40,    40,    42,    41,    43,    43,    44,    44,
      45,    46,    45,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    57,    56,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    66,    65,    67,    67,    68,
      68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     4,     0,
       0,     8,     1,     1,     0,     7,     1,     1,     3,     1,
       2,     0,     5,     4,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     5,     7,     5,     2,     3,
       3,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     0,     5,     1,     1,     3,
       1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 51 "cm.y" /* yacc.c:1646  */
    {savedTree = (yyvsp[0]);}
#line 1347 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "cm.y" /* yacc.c:1646  */
    {
                                YYSTYPE t = (yyvsp[-1]);
                                if (t != NULL){ 
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = (yyvsp[0]);
                                    (yyval) = (yyvsp[-1]); 
                                }
                                else (yyval) = (yyvsp[0]);
                            }
#line 1362 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1368 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 68 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1374 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1380 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "cm.y" /* yacc.c:1646  */
    { SAVEID; }
#line 1386 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newDeclNode(VarK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> lineno = savedLineNo;
                                (yyval) -> type = pop_type();
                            }
#line 1397 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "cm.y" /* yacc.c:1646  */
    { SAVEID; }
#line 1403 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 79 "cm.y" /* yacc.c:1646  */
    {temp = atoi(tokenString);}
#line 1409 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newDeclNode(VarArrK);
                                (yyval) -> attr.decl.name =Integer_ID();
                                (yyval) -> lineno = savedLineNo;
                                (yyval) -> type = pop_type();
                                (yyval) -> attr.decl.arr_size = temp;
                            }
#line 1421 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "cm.y" /* yacc.c:1646  */
    {push_type(Integer);}
#line 1427 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "cm.y" /* yacc.c:1646  */
    {push_type(Void);}
#line 1433 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 93 "cm.y" /* yacc.c:1646  */
    {SAVEID;}
#line 1439 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newDeclNode(FunK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> lineno = savedLineNo;
                                (yyval) -> type = pop_type();
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                                (yyval) -> child[1] -> kind.decl = FompndK;
                            }
#line 1453 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 105 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1459 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "cm.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1465 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "cm.y" /* yacc.c:1646  */
    {
                                YYSTYPE t = (yyvsp[-2]);
                                while (t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = (yyvsp[0]);
                                (yyval) = (yyvsp[-2]);
                            }
#line 1477 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 117 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1483 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 121 "cm.y" /* yacc.c:1646  */
    {
                                SAVEID;
                                (yyval) = newDeclNode(ParaK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> lineno = savedLineNo;
                                (yyval) -> type = pop_type();

                            }
#line 1496 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 129 "cm.y" /* yacc.c:1646  */
    { SAVEID; }
#line 1502 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 130 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newDeclNode(ParaK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> lineno = savedLineNo;
                                (yyval) -> type = Array;
                                if(pop_type() == Void)
                                    (yyval) -> type = Err;
                                (yyval) -> attr.decl.arr_size = 0;
                            }
#line 1516 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(CompndK);
                                (yyval) -> child[0] = (yyvsp[-2]);//enable to be null
                                (yyval) -> child[1] = (yyvsp[-1]);//enable to be null
                            }
#line 1526 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 150 "cm.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-1]) != NULL){
                                    YYSTYPE t = (yyvsp[-1]);
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = (yyvsp[0]);
                                    (yyval) = (yyvsp[-1]);
                                }
                                else (yyval) = (yyvsp[0]);
                            }
#line 1541 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 160 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1547 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 164 "cm.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-1]) != NULL){
                                    YYSTYPE t = (yyvsp[-1]);
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = (yyvsp[0]);
                                    (yyval) = (yyvsp[-1]);
                                }
                                else (yyval) = (yyvsp[0]);
                            }
#line 1562 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1568 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1574 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 178 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1580 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1586 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 180 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1592 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1598 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 184 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1604 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 185 "cm.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1610 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 189 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(SelcK);
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                            }
#line 1620 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(SelcK);
                                (yyval) -> child[0] = (yyvsp[-4]);
                                (yyval) -> child[1] = (yyvsp[-2]);
                                (yyval) -> child[2] = (yyvsp[0]);
                            }
#line 1631 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 204 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(IterK);
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                            }
#line 1641 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(RetK);
                            }
#line 1649 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(RetK);
                                (yyval) -> child[0] = (yyvsp[-1]);
                            }
#line 1658 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 224 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(OpK);
                                (yyval) -> attr.op = ASSIGN;
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                            }
#line 1669 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 230 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1675 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "cm.y" /* yacc.c:1646  */
    {
                                SAVEID;
                                (yyval) = newExpNode(IdK);
                                (yyval) -> attr.decl.name = pop_ID();
                            }
#line 1685 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 239 "cm.y" /* yacc.c:1646  */
    { SAVEID; }
#line 1691 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 240 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(IdK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> child[0] = (yyvsp[-1]);
                                (yyval) -> type = Array_Nocheck;
                            }
#line 1702 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 249 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(OpK);
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                                (yyval) -> attr.op = pop_op();
                            }
#line 1713 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1719 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 258 "cm.y" /* yacc.c:1646  */
    {push_op(LT);}
#line 1725 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 259 "cm.y" /* yacc.c:1646  */
    {push_op(LET);}
#line 1731 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "cm.y" /* yacc.c:1646  */
    {push_op(GT);}
#line 1737 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "cm.y" /* yacc.c:1646  */
    {push_op(GET);}
#line 1743 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 262 "cm.y" /* yacc.c:1646  */
    {push_op(EQ);}
#line 1749 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 263 "cm.y" /* yacc.c:1646  */
    {push_op(NEQ);}
#line 1755 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(OpK);
                                (yyval) -> attr.op = pop_op();
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                            }
#line 1766 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1772 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 277 "cm.y" /* yacc.c:1646  */
    {push_op(PLUS);}
#line 1778 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 278 "cm.y" /* yacc.c:1646  */
    {push_op(MINUS);}
#line 1784 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 282 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(OpK);
                                (yyval) -> attr.op = pop_op();
                                (yyval) -> child[0] = (yyvsp[-2]);
                                (yyval) -> child[1] = (yyvsp[0]);
                            }
#line 1795 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 288 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1801 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 291 "cm.y" /* yacc.c:1646  */
    {push_op(TIMES);}
#line 1807 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 292 "cm.y" /* yacc.c:1646  */
    {push_op(OVER);}
#line 1813 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 295 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1819 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 296 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1825 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 297 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1831 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 299 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newExpNode(ConstK);
                                (yyval)->attr.val = atoi(tokenString);
                                (yyval) -> type = Integer;
                            }
#line 1841 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 306 "cm.y" /* yacc.c:1646  */
    {SAVEID;}
#line 1847 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 307 "cm.y" /* yacc.c:1646  */
    {
                                (yyval) = newStmtNode(CallK);
                                (yyval) -> attr.decl.name = pop_ID();
                                (yyval) -> child[0] = (yyvsp[-1]);
                            }
#line 1857 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 314 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1863 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 315 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1869 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 319 "cm.y" /* yacc.c:1646  */
    {
                                if((yyvsp[-2]) != NULL){
                                    YYSTYPE t = (yyvsp[-2]);
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = (yyvsp[0]);
                                    (yyval) = (yyvsp[-2]);
                                }
                                else (yyval) = (yyvsp[0]);

                            }
#line 1885 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 330 "cm.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1891 "cm.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 332 "cm.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1897 "cm.tab.c" /* yacc.c:1646  */
    break;


#line 1901 "cm.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 334 "cm.y" /* yacc.c:1906  */

static void push_op(TokenType op){
    if(top >= MAX_STACK)
        return;
    StackOp[++top] = op;
}
static TokenType pop_op(){
    if(top >= 0)
        return StackOp[top--];
    return -1;
}
static void push_ID(char* id){
    if(top_id >= MAX_STACK)
        return;
    StackID[++top_id] = id;
}
static char* pop_ID(){
    if(top_id >= 0)
        return StackID[top_id--];
    return NULL;
}
static void push_type(Type t){
    if(top_type >= MAX_STACK)
        return;
    StackType[++top_type] = t;
}
static Type pop_type(){
    if(top_type >= 0)
        return StackType[top_type--];
    return 0;
}


int yyerror(char * message){
    fprintf(listing, "Syntax error at line %d: %s\n" ,lineno,message);
    fprintf(listing, "Current token: ");
    printToken(yychar,tokenString);
    Error = TRUE;
    return 0;
}


/* yylex calls getToken to make Yacc/Bison output
* cαnpatible with earlier versions of
* the TINY scanner
*/
static int yylex(void){
    int token = getToken();
    return token;
}
TreeNode* parse(void){
    yyparse();
    return savedTree;
}


