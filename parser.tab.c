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

  #include <stdio.h>
  #include "ast_print.h"
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(char *s);

#line 75 "parser.tab.c" /* yacc.c:339  */

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
    RDOP = 271,
    SOP = 272,
    MOP = 273,
    AOP = 274,
    AND = 275,
    OR = 276,
    NOT = 277,
    TRUE = 278,
    FALSE = 279,
    EQUAL = 280,
    BREAK = 281,
    RETURN = 282,
    IN = 283,
    OUT = 284,
    NUMBER = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "parser.y" /* yacc.c:355  */

  char *text;
  struct ASTNode *node;
  int number;

#line 152 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 169 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      33,    34,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    31,
       2,     2,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    26,    27,    29,    30,    33,    35,    36,
      39,    40,    42,    43,    44,    45,    47,    48,    49,    50,
      52,    53,    55,    58,    59,    61,    62,    63,    64,    65,
      68,    69,    71,    73,    74,    76,    78,    79,    80,    81,
      84,    85,    88,    89,    90,    91,    94,    95,    96,    97,
      98,    99,   102,   104,   105,   106,   107,   109,   110,   112,
     113,   115,   116,   118,   119,   120,   122,   123,   124,   126,
     127,   129,   130,   132,   133,   135,   136,   137,   138,   139,
     141,   142,   143,   145,   147,   148,   149,   151,   152,   153
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT", "CHAR", "BOOL", "VOID",
  "IF", "ELSE", "FOR", "WHILE", "INPUT", "PRINT", "ROP", "STRING", "RDOP",
  "SOP", "MOP", "AOP", "AND", "OR", "NOT", "TRUE", "FALSE", "EQUAL",
  "BREAK", "RETURN", "IN", "OUT", "NUMBER", "';'", "','", "'('", "')'",
  "'{'", "'}'", "'?'", "':'", "'['", "']'", "$accept", "Goal", "DecList",
  "VarDecList", "VarDec", "VarList", "FuncDecList", "FuncDec", "Type",
  "ParamList", "Param", "StatList", "Statement", "IOStat", "InpStat",
  "InpList", "OutStat", "OutList", "RetStat", "LoopStat", "CondStat",
  "ExprStat", "Expr", "TerExpr", "OrTerm", "AndTerm", "UnTerm", "RelTerm",
  "SumTerm", "MulTerm", "Term", "Var", "NonVar", "FunCall", "ArgList",
  "Constant", YY_NULLPTR
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
     285,    59,    44,    40,    41,   123,   125,    63,    58,    91,
      93
};
# endif

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,  -118,  -118,  -118,  -118,     5,  -118,  -118,   -19,  -118,
      84,    16,  -118,    84,  -118,    27,   -24,  -118,     7,  -118,
      13,    61,   131,    27,    36,    27,    -3,  -118,   -11,   232,
     232,  -118,  -118,  -118,   232,    38,    15,    43,    60,    62,
    -118,  -118,     0,    68,  -118,    26,  -118,  -118,  -118,  -118,
     162,  -118,    84,    57,   232,  -118,  -118,  -118,    59,   232,
      55,   232,   232,   232,    46,    46,    46,    46,   232,    20,
      63,    64,    66,    72,    74,   200,   188,    65,   188,  -118,
      76,    77,  -118,  -118,  -118,  -118,    78,  -118,   162,    73,
      80,  -118,    71,   232,   -17,    62,  -118,    95,    95,    68,
    -118,  -118,  -118,  -118,   232,   232,   232,    27,   217,  -118,
      85,    79,  -118,  -118,  -118,  -118,  -118,   188,    81,   232,
    -118,  -118,    89,   232,    86,    90,    97,  -118,    96,   106,
    -118,   110,  -118,  -118,   104,  -118,  -118,  -118,    60,   107,
     232,   108,    27,   217,   217,  -118,   162,   113,   162,  -118,
    -118,  -118,   188,   105,   232,   188,   109,   111,   137,   115,
     114,  -118,   142,   117,   121,  -118,   125,   162,   162,   162,
     188,   126,   188,   127,   188,   140,   141,  -118,   144,  -118,
     145,  -118,  -118,  -118,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    17,    18,    19,     0,     2,     4,     0,     3,
      11,     0,     1,     6,    10,     0,    75,     7,     9,     5,
      75,     0,     0,     0,     0,     0,     0,    21,    75,     0,
       0,    88,    89,    87,     0,    76,     0,    56,    58,    60,
      62,    65,    68,    70,    72,    73,    74,    82,    81,     8,
       0,    22,     0,     0,    86,    64,    73,    63,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    28,
       0,     0,    29,    27,    26,    25,     0,    20,     0,    85,
       0,    80,     0,     0,     0,    59,    61,    66,    67,    69,
      71,    53,    55,    54,     0,     0,     0,     0,     0,    40,
       0,     0,    15,    24,    30,    31,    52,     0,     0,    86,
      83,    78,     0,     0,     0,     0,     0,    32,    34,    39,
      35,    37,    41,    14,     0,    13,    84,    79,    57,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,    33,
      38,    36,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    45,    46,     0,     0,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,    43,
       0,    49,    50,    42,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,   -10,  -118,   155,  -118,  -118,    11,  -118,
     130,   -42,  -118,  -118,  -118,    41,  -118,  -117,  -118,  -118,
    -118,  -118,   -21,  -118,   -59,   128,   -22,  -118,     9,   122,
     120,    -5,  -118,  -118,    75,  -118
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    17,     9,    10,    15,    26,
      27,    77,    78,    79,    80,   127,    81,   130,    82,    83,
      84,    85,    86,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    90,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      14,    36,    94,    19,    62,    12,    18,    55,    57,    21,
      18,    11,    13,    58,    64,    22,    65,    66,    18,    16,
      51,   123,    54,    28,    56,    56,   150,   151,    22,    52,
      20,    53,    25,    89,   111,   102,   113,    29,    92,    23,
      76,    96,    30,    31,    32,    68,   118,   101,   103,    28,
      33,    69,    22,    34,   110,    60,    56,    56,    56,    56,
      56,    56,    56,    25,   138,     1,     2,     3,     4,    31,
      32,    50,   122,    97,    98,   134,    33,    59,   117,    34,
      61,    62,    63,   124,   125,   126,    67,   131,     1,     2,
       3,     4,    88,    91,    93,    24,   104,   105,    89,   106,
     107,   112,   128,   108,   153,   119,   156,   114,   115,   116,
     157,   121,    66,   160,   120,   133,   132,   135,    56,   147,
     139,   140,   131,   131,   142,   171,   173,   175,   176,   137,
     178,   141,   180,   159,    28,   143,   152,   128,   155,   144,
     145,   158,   146,   148,   154,   161,   163,   162,    29,   164,
     165,   166,   167,    30,    31,    32,   168,   170,   172,   174,
     169,    33,   177,   179,    34,    28,     1,     2,     3,     4,
      70,    35,    71,    72,    73,    74,   181,   182,    49,    29,
     183,   184,    87,   149,    30,    31,    32,   100,    99,    75,
      95,    28,    33,     0,   136,    34,    70,     0,    71,    72,
      73,    74,     0,    28,     0,    29,     0,     0,     0,     0,
      30,    31,    32,     0,     0,    75,     0,    29,    33,     0,
      28,    34,    30,    31,    32,     0,     0,     0,     0,     0,
      33,   109,   129,    34,    29,    28,     0,     0,     0,    30,
      31,    32,     0,     0,     0,     0,     0,    33,     0,    29,
      34,     0,     0,     0,    30,    31,    32,     0,     0,     0,
       0,     0,    33,     0,     0,    34
};

static const yytype_int16 yycheck[] =
{
      10,    22,    61,    13,    21,     0,    11,    29,    30,    33,
      15,     0,    31,    34,    14,    39,    16,    17,    23,     3,
      25,    38,    33,     3,    29,    30,   143,   144,    39,    32,
       3,    34,    21,    54,    76,    15,    78,    17,    59,    32,
      50,    63,    22,    23,    24,    19,    88,    68,    69,     3,
      30,    25,    39,    33,    75,    40,    61,    62,    63,    64,
      65,    66,    67,    52,   123,     4,     5,     6,     7,    23,
      24,    35,    93,    64,    65,   117,    30,    39,    88,    33,
      37,    21,    20,   104,   105,   106,    18,   108,     4,     5,
       6,     7,    35,    34,    39,    34,    33,    33,   119,    33,
      28,    36,   107,    29,   146,    32,   148,    31,    31,    31,
     152,    40,    17,   155,    34,    36,    31,    36,   123,   140,
      34,    31,   143,   144,    28,   167,   168,   169,   170,    40,
     172,    34,   174,   154,     3,    29,   146,   142,   148,    29,
      36,    36,    35,    35,    31,    36,     9,    36,    17,    34,
      36,     9,    35,    22,    23,    24,    35,   167,   168,   169,
      35,    30,    36,    36,    33,     3,     4,     5,     6,     7,
       8,    40,    10,    11,    12,    13,    36,    36,    23,    17,
      36,    36,    52,   142,    22,    23,    24,    67,    66,    27,
      62,     3,    30,    -1,   119,    33,     8,    -1,    10,    11,
      12,    13,    -1,     3,    -1,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    -1,    27,    -1,    17,    30,    -1,
       3,    33,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    15,    33,    17,     3,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    17,
      33,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,    42,    43,    44,    45,    47,
      48,    49,     0,    31,    44,    49,     3,    46,    72,    44,
       3,    33,    39,    32,    34,    49,    50,    51,     3,    17,
      22,    23,    24,    30,    33,    40,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    76,    46,
      35,    72,    32,    34,    33,    67,    72,    67,    63,    39,
      40,    37,    21,    20,    14,    16,    17,    18,    19,    25,
       8,    10,    11,    12,    13,    27,    44,    52,    53,    54,
      55,    57,    59,    60,    61,    62,    63,    51,    35,    63,
      75,    34,    63,    39,    65,    66,    67,    69,    69,    70,
      71,    63,    15,    63,    33,    33,    33,    28,    29,    31,
      63,    52,    36,    52,    31,    31,    31,    44,    52,    32,
      34,    40,    63,    38,    63,    63,    63,    56,    72,    15,
      58,    63,    31,    36,    52,    36,    75,    40,    65,    34,
      31,    34,    28,    29,    29,    36,    35,    63,    35,    56,
      58,    58,    44,    52,    31,    44,    52,    52,    36,    63,
      52,    36,    36,     9,    34,    36,     9,    35,    35,    35,
      44,    52,    44,    52,    44,    52,    52,    36,    52,    36,
      52,    36,    36,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    55,    56,    56,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    75,    75,    75,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     2,     3,     1,
       2,     1,     9,     8,     8,     7,     1,     1,     1,     1,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     1,     3,     3,     1,     3,     1,
       2,     3,    12,    11,     8,     7,     8,     7,    13,    12,
      12,    11,     2,     3,     3,     3,     1,     5,     1,     3,
       1,     3,     1,     2,     2,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     4,     6,     7,
       3,     1,     1,     4,     3,     1,     0,     1,     1,     1
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
        case 5:
#line 29 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarDecList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 30 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarDecList((yyvsp[-1].node), NULL);}
#line 1392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 33 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVarList((yyvsp[-1].node), (yyvsp[0].node));}
#line 1398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 35 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVardec((yyvsp[-2].node), (yyvsp[0].node));}
#line 1404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 36 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeVardec((yyvsp[0].node), NULL);}
#line 1410 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 39 "parser.y" /* yacc.c:1646  */
    {printAST((yyvsp[0].node));}
#line 1416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 40 "parser.y" /* yacc.c:1646  */
    {printAST((yyvsp[0].node));}
#line 1422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 42 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-8].node), (yyvsp[-7].text), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 43 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-7].node), (yyvsp[-6].text), (yyvsp[-4].node), NULL, (yyvsp[-1].node));}
#line 1434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 44 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-7].node), (yyvsp[-6].text), NULL, (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 45 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunction((yyvsp[-6].node), (yyvsp[-5].text), NULL, NULL, (yyvsp[-1].node));}
#line 1446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 47 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType("int");}
#line 1452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 48 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType("char");}
#line 1458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 49 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType("bool");}
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 50 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeDType("void");}
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 52 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParamList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 53 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParamList((yyvsp[0].node), NULL);}
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 55 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeParam((yyvsp[-1].node), (yyvsp[0].node));}
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 58 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStat((yyvsp[0].node), NULL);}
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 59 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStat((yyvsp[-1].node), (yyvsp[0].node));}
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 68 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputStat((yyvsp[0].node));}
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputList((yyvsp[-2].node), (yyvsp[0].node));}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeInputList((yyvsp[0].node), NULL);}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputStat((yyvsp[0].node));}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList((yyvsp[-2].node), NULL, (yyvsp[0].node));}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList((yyvsp[0].node), NULL, NULL);}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList(NULL, (yyvsp[-2].text), (yyvsp[0].node));}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeOutputList(NULL, (yyvsp[0].text), NULL);}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeReturn(NULL);}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeReturn((yyvsp[-1].node));}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFor((yyvsp[-9].node), (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), NULL, (yyvsp[-1].node));}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeWhile((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeWhile((yyvsp[-4].node), NULL, (yyvsp[-1].node));}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-4].node), NULL, (yyvsp[-1].node), NULL, NULL);}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-10].node), (yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-5].node), NULL, (yyvsp[-1].node));}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-9].node), NULL, (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIf((yyvsp[-8].node), NULL, (yyvsp[-5].node), NULL, (yyvsp[-1].node));}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), DASSIGN, (yyvsp[-1].text));}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), ASSIGN, (yyvsp[-1].text));}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeStringOp((yyvsp[-2].node), (yyvsp[0].text));}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeTernaryOp((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), OROP, (yyvsp[-1].text));}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), ANDOP, (yyvsp[-1].text));}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeUnaryOp((yyvsp[0].node), NOTOP, (yyvsp[-1].text));}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeUnaryOp((yyvsp[0].node), SUMOP, (yyvsp[-1].text));}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), RELOP, (yyvsp[-1].text));}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), RELDOP, (yyvsp[-1].text));}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), SUMOP, (yyvsp[-1].text));}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBinaryOp((yyvsp[-2].node), (yyvsp[0].node), MULOP, (yyvsp[-1].text));}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIDLiteral((yyvsp[0].text));}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode1DArray((yyvsp[-2].text), NULL);}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode1DArray((yyvsp[-3].text), (yyvsp[-1].node));}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode2DArray((yyvsp[-5].text), NULL, (yyvsp[-1].node));}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNode2DArray((yyvsp[-6].text), (yyvsp[-4].node), (yyvsp[-1].node));}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeFunCall((yyvsp[-3].text), (yyvsp[-1].node));}
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg((yyvsp[-2].node), (yyvsp[0].node));}
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg((yyvsp[0].node), NULL);}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeArg(NULL, NULL);}
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 151 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeIntLiteral((yyvsp[0].number)); }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBoolLiteral((yyvsp[0].text));}
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getASTNodeBoolLiteral((yyvsp[0].text));}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1792 "parser.tab.c" /* yacc.c:1646  */
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
#line 155 "parser.y" /* yacc.c:1906  */


void yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

main(int argc, char **argv)
{
  yyparse();
  printf("Parsing Over\n");
}
