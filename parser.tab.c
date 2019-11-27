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
#line 1 "parser.y" /* yacc.c:339  */

  #include <string>
  #include <stdio.h>
  using namespace std;
  #include "ast_print.h"

  extern "C" int yylex();
  extern "C" int yyparse();
  extern FILE *yyin;
  extern int yylineno;
  void yyerror(char *s);

#line 79 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INT = 259,
    CHAR = 260,
    BOOL = 261,
    VOID = 262,
    IF = 263,
    ELSE = 264,
    FOR = 265,
    WHILE = 266,
    INPUT = 267,
    PRINT = 268,
    ROP = 269,
    STRING = 270,
    FLOAT = 271,
    RDOP = 272,
    AOP = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    TRUE = 277,
    FALSE = 278,
    EQUAL = 279,
    BREAK = 280,
    RETURN = 281,
    IN = 282,
    OUT = 283,
    SOP = 284,
    MOP = 285,
    NUMBER = 286,
    FLT_NUM = 287,
    LETTER = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:355  */

  struct ASTNode *node;
  string *text;
  int number;
  float flt;
  char letter;

#line 161 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 178 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      36,    37,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    34,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    34,    35,    37,    38,    41,    43,    44,
      47,    48,    50,    51,    52,    53,    55,    56,    57,    58,
      59,    61,    62,    64,    67,    68,    70,    71,    72,    73,
      74,    77,    78,    80,    82,    83,    85,    87,    88,    89,
      90,    93,    96,    97,   100,   101,   104,   106,   107,   108,
     109,   111,   112,   114,   115,   117,   118,   120,   121,   122,
     124,   125,   127,   128,   130,   131,   132,   134,   135,   137,
     138,   139,   140,   141,   143,   144,   145,   147,   149,   150,
     151,   153,   154,   155,   156
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT", "CHAR", "BOOL", "VOID",
  "IF", "ELSE", "FOR", "WHILE", "INPUT", "PRINT", "ROP", "STRING", "FLOAT",
  "RDOP", "AOP", "AND", "OR", "NOT", "TRUE", "FALSE", "EQUAL", "BREAK",
  "RETURN", "IN", "OUT", "SOP", "MOP", "NUMBER", "FLT_NUM", "LETTER",
  "';'", "','", "'('", "')'", "'{'", "'}'", "'?'", "':'", "'['", "']'",
  "$accept", "Goal", "DecList", "VarDecList", "VarDec", "VarList",
  "FuncDecList", "FuncDec", "Type", "ParamList", "Param", "StatList",
  "Statement", "IOStat", "InpStat", "InpList", "OutStat", "OutList",
  "RetStat", "LoopStat", "CondStat", "ExprStat", "Expr", "TerExpr",
  "OrTerm", "AndTerm", "RelTerm", "SumTerm", "MulTerm", "UnTerm", "Term",
  "Var", "NonVar", "FunCall", "ArgList", "Constant", YY_NULLPTR
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
     285,   286,   287,   288,    59,    44,    40,    41,   123,   125,
      63,    58,    91,    93
};
# endif

#define YYPACT_NINF -100

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,  -100,  -100,  -100,  -100,  -100,     7,  -100,   -20,   -15,
    -100,    88,    20,  -100,    88,    88,  -100,    37,   -26,  -100,
     -14,  -100,  -100,    50,    28,   197,     5,    50,    12,    29,
      50,    35,    31,     2,   186,  -100,  -100,   186,  -100,  -100,
     186,    32,    33,    39,    55,    61,  -100,    18,    51,  -100,
    -100,    21,  -100,  -100,  -100,  -100,   118,  -100,    49,    88,
     186,  -100,  -100,  -100,    54,   186,    58,   186,   186,   186,
     186,   186,   186,   186,   186,    67,    69,    70,    71,    81,
      82,   186,   152,    72,   152,  -100,    63,    75,  -100,  -100,
    -100,  -100,    78,   118,  -100,    83,    95,  -100,    76,   186,
     -17,    61,  -100,    91,    91,    51,  -100,  -100,  -100,  -100,
     186,   186,   186,    50,   164,    99,    97,  -100,  -100,  -100,
    -100,  -100,   152,    98,   186,  -100,  -100,   100,   186,   101,
     108,   109,  -100,   126,   117,  -100,   128,  -100,  -100,   119,
    -100,  -100,  -100,    55,   121,   186,   130,    50,   164,   164,
    -100,   152,   123,   152,  -100,  -100,  -100,   127,   186,   131,
     160,   134,  -100,   138,   139,   152,   152,   133,   141,  -100,
    -100
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    18,    19,    20,     0,     2,     0,     0,
       4,    11,     0,     1,     0,     6,    10,     0,    69,     7,
       9,     3,     5,     0,     0,     0,     0,     0,    69,     0,
       0,     0,    22,    69,     0,    83,    84,     0,    81,    82,
       0,    70,     0,    50,    52,    54,    56,    59,    61,    63,
      66,    67,    68,    76,    75,     8,     0,    23,     0,     0,
      80,    64,    67,    65,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    29,     0,     0,    30,    28,
      27,    26,     0,     0,    21,    79,     0,    74,     0,     0,
       0,    53,    55,    57,    58,    60,    62,    47,    49,    48,
       0,     0,     0,     0,     0,     0,     0,    15,    25,    31,
      32,    46,     0,     0,    80,    77,    72,     0,     0,     0,
       0,     0,    33,    35,    40,    36,    38,    41,    14,     0,
      13,    78,    73,    51,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,    34,    39,    37,     0,     0,     0,
      44,     0,    43,     0,     0,     0,     0,     0,     0,    45,
      42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,   -10,  -100,   155,    -2,  -100,     6,   132,
    -100,   -80,  -100,  -100,  -100,    43,  -100,   -99,  -100,  -100,
    -100,  -100,     3,  -100,   -66,   124,   125,   -19,   140,    -4,
    -100,   -12,  -100,  -100,    73,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    19,    10,    11,    23,    31,
      32,    83,    84,    85,    86,   132,    87,   135,    88,    89,
      90,    91,    92,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    96,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,   100,   116,    68,   118,    22,    12,    13,    33,    16,
      25,    20,    21,   123,    14,    20,    26,    17,    57,    15,
      17,    27,    62,    18,   128,    62,    34,    35,    36,    42,
      61,    30,    70,    63,    37,    71,    38,    39,    60,    74,
      24,    40,   139,    64,    26,    75,    82,    72,    41,   155,
     156,   103,   104,    28,    26,    62,    62,    62,    62,    62,
      62,    62,   143,    95,    25,    30,    59,    56,    98,   106,
      33,   157,    58,   159,    65,    68,    66,   107,   109,    67,
      69,    73,   108,   122,   115,   167,   168,    93,    34,    35,
      36,    97,     1,     2,     3,     4,    37,   119,    38,    39,
      99,   133,   127,    40,     5,   110,   111,   112,   113,   120,
     114,   117,   121,   129,   130,   131,    62,   136,   124,   126,
      72,    33,     1,     2,     3,     4,    76,    95,    77,    78,
      79,    80,   125,   137,     5,   133,   138,   140,   144,    34,
      35,    36,   145,   142,    81,   148,   146,    37,   152,    38,
      39,   136,   136,   147,    40,    33,   149,   158,   150,   151,
      76,   161,    77,    78,    79,    80,   160,    33,   153,   163,
     162,   164,   169,    34,    35,    36,   165,   166,    81,   134,
     170,    37,    55,    38,    39,    34,    35,    36,    40,    33,
     154,    94,   101,    37,   102,    38,    39,   141,     0,     0,
      40,     1,     2,     3,     4,     0,     0,    34,    35,    36,
       0,     0,   105,     5,     0,    37,     0,    38,    39,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
      12,    67,    82,    20,    84,    15,     0,     0,     3,    11,
      36,    23,    14,    93,    34,    27,    42,    11,    30,    34,
      14,    35,    34,     3,    41,    37,    21,    22,    23,    26,
      34,    25,    14,    37,    29,    17,    31,    32,    36,    18,
       3,    36,   122,    40,    42,    24,    56,    29,    43,   148,
     149,    70,    71,     3,    42,    67,    68,    69,    70,    71,
      72,    73,   128,    60,    36,    59,    35,    38,    65,    73,
       3,   151,    37,   153,    42,    20,    43,    74,    75,    40,
      19,    30,    15,    93,    81,   165,   166,    38,    21,    22,
      23,    37,     4,     5,     6,     7,    29,    34,    31,    32,
      42,   113,    99,    36,    16,    36,    36,    36,    27,    34,
      28,    39,    34,   110,   111,   112,   128,   114,    35,    43,
      29,     3,     4,     5,     6,     7,     8,   124,    10,    11,
      12,    13,    37,    34,    16,   147,    39,    39,    37,    21,
      22,    23,    34,    43,    26,    28,    37,    29,   145,    31,
      32,   148,   149,    27,    36,     3,    28,    34,    39,    38,
       8,   158,    10,    11,    12,    13,    39,     3,    38,     9,
      39,    37,    39,    21,    22,    23,    38,    38,    26,    15,
      39,    29,    27,    31,    32,    21,    22,    23,    36,     3,
     147,    59,    68,    29,    69,    31,    32,   124,    -1,    -1,
      36,     4,     5,     6,     7,    -1,    -1,    21,    22,    23,
      -1,    -1,    72,    16,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,    16,    45,    46,    47,    48,
      50,    51,    52,     0,    34,    34,    50,    52,     3,    49,
      75,    50,    47,    52,     3,    36,    42,    35,     3,    37,
      52,    53,    54,     3,    21,    22,    23,    29,    31,    32,
      36,    43,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    79,    49,    38,    75,    37,    35,
      36,    73,    75,    73,    66,    42,    43,    40,    20,    19,
      14,    17,    29,    30,    18,    24,     8,    10,    11,    12,
      13,    26,    47,    55,    56,    57,    58,    60,    62,    63,
      64,    65,    66,    38,    53,    66,    78,    37,    66,    42,
      68,    69,    70,    71,    71,    72,    73,    66,    15,    66,
      36,    36,    36,    27,    28,    66,    55,    39,    55,    34,
      34,    34,    47,    55,    35,    37,    43,    66,    41,    66,
      66,    66,    59,    75,    15,    61,    66,    34,    39,    55,
      39,    78,    43,    68,    37,    34,    37,    27,    28,    28,
      39,    38,    66,    38,    59,    61,    61,    55,    34,    55,
      39,    66,    39,     9,    37,    38,    38,    55,    55,    39,
      39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    60,    61,    61,    61,
      61,    62,    63,    63,    64,    64,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    77,    78,    78,
      78,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     2,     2,     3,     1,
       2,     1,     9,     8,     8,     7,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     1,     3,     3,     1,     3,
       1,     3,    11,     7,     7,    11,     2,     3,     3,     3,
       1,     5,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       3,     4,     6,     7,     3,     1,     1,     4,     3,     1,
       0,     1,     1,     1,     1
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
#line 33 "parser.y" /* yacc.c:1646  */
    {printf("AST Generated code:-\n");printAST((yyvsp[0].node));printIR((yyvsp[0].node));}
#line 1386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDecList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 35 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDecList(NULL, (yyvsp[0].node));}
#line 1398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 37 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarDecList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 38 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarDecList((yyvsp[-1].node), NULL);}
#line 1410 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 41 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 43 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVardec((yyvsp[-2].node), (yyvsp[0].node));}
#line 1422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 44 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVardec((yyvsp[0].node), NULL);}
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 47 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFuncList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 48 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFuncList((yyvsp[0].node), NULL);}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 50 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-8].node), (yyvsp[-7].text), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 51 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-7].node), (yyvsp[-6].text), (yyvsp[-4].node), NULL, (yyvsp[-1].node));}
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 52 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-7].node), (yyvsp[-6].text), NULL, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 53 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-6].node), (yyvsp[-5].text), NULL, NULL, (yyvsp[-1].node));}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType((yyvsp[0].text));}
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 56 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType((yyvsp[0].text));}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 57 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType((yyvsp[0].text));}
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 58 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType((yyvsp[0].text));}
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 59 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType((yyvsp[0].text));}
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 61 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParamList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 62 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParamList((yyvsp[0].node), NULL);}
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 64 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParam((yyvsp[-1].node), (yyvsp[0].node));}
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 67 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStat((yyvsp[0].node), NULL);}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 68 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStat((yyvsp[-1].node), (yyvsp[0].node));}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputStat((yyvsp[0].node));}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputList((yyvsp[0].node), NULL);}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputStat((yyvsp[0].node));}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList((yyvsp[-2].node), new string("NULL"), (yyvsp[0].node));}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList((yyvsp[0].node), new string("NULL"), NULL);}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList(NULL, (yyvsp[-2].text), (yyvsp[0].node));}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList(NULL, (yyvsp[0].text), NULL);}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeReturn((yyvsp[-1].node));}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeWhile((yyvsp[-4].node), (yyvsp[-1].node));}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-4].node), (yyvsp[-1].node), NULL);}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), DASSIGN, (yyvsp[-1].text));}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), ASSIGN, (yyvsp[-1].text));}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStringOp((yyvsp[-2].node), (yyvsp[0].text));}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeTernaryOp((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), OROP, (yyvsp[-1].text));}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), ANDOP, (yyvsp[-1].text));}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), RELOP, (yyvsp[-1].text));}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 121 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), RELDOP, (yyvsp[-1].text));}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), SUMOP, (yyvsp[-1].text));}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), MULOP, (yyvsp[-1].text));}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeUnaryOp((yyvsp[0].node), NOTOP, (yyvsp[-1].text));}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeUnaryOp((yyvsp[0].node), SUMOP, (yyvsp[-1].text));}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIDLiteral((yyvsp[0].text));}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode1DArray((yyvsp[-2].text), NULL);}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode1DArray((yyvsp[-3].text), (yyvsp[-1].node));}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode2DArray((yyvsp[-5].text), NULL, (yyvsp[-1].node));}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode2DArray((yyvsp[-6].text), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunCall((yyvsp[-3].text), (yyvsp[-1].node));}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg((yyvsp[-2].node), (yyvsp[0].node));}
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg((yyvsp[0].node), NULL);}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg(NULL, NULL);}
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIntLiteral((yyvsp[0].number)); }
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFloatLiteral((yyvsp[0].flt));}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBoolLiteral((yyvsp[0].text));}
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBoolLiteral((yyvsp[0].text));}
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1780 "parser.tab.c" /* yacc.c:1646  */
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
#line 158 "parser.y" /* yacc.c:1906  */


void yyerror(char *s)
{
  fprintf(stderr, "error: %s line %d\n", s, yylineno);
}

int main(int argc, char **argv)
{
  yyparse();
}
