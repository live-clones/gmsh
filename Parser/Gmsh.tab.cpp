/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         gmsh_yyparse
#define yylex           gmsh_yylex
#define yyerror         gmsh_yyerror
#define yylval          gmsh_yylval
#define yychar          gmsh_yychar
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "fullMatrix.h"
#include "MallocUtils.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "StringUtils.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Options.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "OS.h"
#include "CreateFile.h"
#include "gmshSurface.h"
#include "gmshLevelset.h"
#include "fullMatrix.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "BackgroundMesh.h"
#include "HighOrder.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#endif

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string> gmsh_yystringsymbols;
#if defined(HAVE_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static int curPhysDim = 0;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static const char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

struct doubleXstring{
  double d;
  char *s;
};



/* Line 189 of yacc.c  */
#line 173 "Gmsh.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tDOUBLE = 258,
     tSTRING = 259,
     tBIGSTR = 260,
     tEND = 261,
     tAFFECT = 262,
     tDOTS = 263,
     tPi = 264,
     tMPI_Rank = 265,
     tMPI_Size = 266,
     tEuclidian = 267,
     tCoordinates = 268,
     tExp = 269,
     tLog = 270,
     tLog10 = 271,
     tSqrt = 272,
     tSin = 273,
     tAsin = 274,
     tCos = 275,
     tAcos = 276,
     tTan = 277,
     tRand = 278,
     tAtan = 279,
     tAtan2 = 280,
     tSinh = 281,
     tCosh = 282,
     tTanh = 283,
     tFabs = 284,
     tFloor = 285,
     tCeil = 286,
     tFmod = 287,
     tModulo = 288,
     tHypot = 289,
     tList = 290,
     tPrintf = 291,
     tError = 292,
     tSprintf = 293,
     tStrCat = 294,
     tStrPrefix = 295,
     tStrRelative = 296,
     tStrFind = 297,
     tTextAttributes = 298,
     tBoundingBox = 299,
     tDraw = 300,
     tToday = 301,
     tSyncModel = 302,
     tCreateTopology = 303,
     tCreateTopologyNoHoles = 304,
     tDistanceFunction = 305,
     tDefineConstant = 306,
     tPoint = 307,
     tCircle = 308,
     tEllipse = 309,
     tLine = 310,
     tSphere = 311,
     tPolarSphere = 312,
     tSurface = 313,
     tSpline = 314,
     tVolume = 315,
     tCharacteristic = 316,
     tLength = 317,
     tParametric = 318,
     tElliptic = 319,
     tRefineMesh = 320,
     tPlane = 321,
     tRuled = 322,
     tTransfinite = 323,
     tComplex = 324,
     tPhysical = 325,
     tCompound = 326,
     tPeriodic = 327,
     tUsing = 328,
     tPlugin = 329,
     tDegenerated = 330,
     tRotate = 331,
     tTranslate = 332,
     tSymmetry = 333,
     tDilate = 334,
     tExtrude = 335,
     tLevelset = 336,
     tRecombine = 337,
     tSmoother = 338,
     tSplit = 339,
     tDelete = 340,
     tCoherence = 341,
     tIntersect = 342,
     tMeshAlgorithm = 343,
     tLayers = 344,
     tHole = 345,
     tAlias = 346,
     tAliasWithOptions = 347,
     tQuadTriDbl = 348,
     tQuadTriSngl = 349,
     tRecombLaterals = 350,
     tTransfQuadTri = 351,
     tText2D = 352,
     tText3D = 353,
     tInterpolationScheme = 354,
     tTime = 355,
     tCombine = 356,
     tBSpline = 357,
     tBezier = 358,
     tNurbs = 359,
     tNurbsOrder = 360,
     tNurbsKnots = 361,
     tColor = 362,
     tColorTable = 363,
     tFor = 364,
     tIn = 365,
     tEndFor = 366,
     tIf = 367,
     tEndIf = 368,
     tExit = 369,
     tAbort = 370,
     tField = 371,
     tReturn = 372,
     tCall = 373,
     tFunction = 374,
     tShow = 375,
     tHide = 376,
     tGetValue = 377,
     tGetEnv = 378,
     tGetString = 379,
     tHomology = 380,
     tCohomology = 381,
     tBetti = 382,
     tSetOrder = 383,
     tGMSH_MAJOR_VERSION = 384,
     tGMSH_MINOR_VERSION = 385,
     tGMSH_PATCH_VERSION = 386,
     tAFFECTDIVIDE = 387,
     tAFFECTTIMES = 388,
     tAFFECTMINUS = 389,
     tAFFECTPLUS = 390,
     tOR = 391,
     tAND = 392,
     tNOTEQUAL = 393,
     tEQUAL = 394,
     tGREATEROREQUAL = 395,
     tLESSOREQUAL = 396,
     UNARYPREC = 397,
     tMINUSMINUS = 398,
     tPLUSPLUS = 399
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 93 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 214 of yacc.c  */
#line 365 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 377 "Gmsh.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8044

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  446
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1532

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   399

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   150,     2,   160,     2,   149,     2,     2,
     155,   156,   147,   145,   161,   146,   159,   148,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     141,     2,   142,   136,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   157,     2,   158,   154,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   162,     2,   163,   164,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   137,   138,   139,   140,   143,   144,   151,   152,   153
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    51,    57,    63,    71,    79,
      87,    97,   104,   111,   118,   119,   122,   125,   128,   131,
     134,   136,   140,   142,   146,   147,   148,   159,   161,   165,
     166,   180,   182,   186,   187,   203,   212,   227,   228,   235,
     237,   239,   241,   243,   245,   247,   249,   255,   260,   267,
     275,   283,   293,   303,   307,   314,   319,   326,   336,   343,
     353,   359,   368,   377,   389,   396,   406,   412,   420,   430,
     440,   452,   460,   470,   480,   481,   483,   484,   488,   494,
     495,   505,   511,   512,   522,   526,   532,   533,   536,   540,
     546,   550,   551,   554,   558,   562,   568,   570,   572,   573,
     579,   580,   583,   591,   592,   602,   609,   617,   622,   630,
     639,   648,   656,   664,   676,   685,   694,   695,   705,   714,
     724,   728,   733,   744,   752,   760,   769,   778,   791,   792,
     802,   811,   819,   828,   829,   839,   845,   857,   863,   873,
     883,   888,   898,   908,   910,   912,   913,   916,   923,   930,
     937,   944,   953,   964,   979,   996,  1009,  1018,  1027,  1034,
    1049,  1054,  1061,  1068,  1072,  1077,  1083,  1087,  1091,  1096,
    1101,  1105,  1113,  1121,  1125,  1133,  1137,  1140,  1143,  1146,
    1149,  1165,  1168,  1171,  1174,  1177,  1181,  1188,  1197,  1206,
    1217,  1219,  1222,  1224,  1228,  1233,  1235,  1241,  1253,  1267,
    1268,  1276,  1277,  1291,  1292,  1308,  1309,  1316,  1325,  1334,
    1343,  1356,  1369,  1382,  1397,  1412,  1427,  1428,  1441,  1442,
    1455,  1456,  1469,  1470,  1487,  1488,  1505,  1506,  1523,  1524,
    1543,  1544,  1563,  1564,  1583,  1585,  1588,  1594,  1602,  1612,
    1615,  1618,  1622,  1625,  1629,  1639,  1646,  1647,  1651,  1652,
    1654,  1655,  1658,  1659,  1662,  1670,  1677,  1686,  1692,  1696,
    1704,  1710,  1715,  1722,  1729,  1742,  1753,  1764,  1775,  1786,
    1789,  1793,  1800,  1802,  1804,  1806,  1809,  1815,  1823,  1834,
    1836,  1840,  1843,  1846,  1849,  1853,  1857,  1861,  1865,  1869,
    1873,  1877,  1881,  1885,  1889,  1893,  1897,  1901,  1905,  1911,
    1916,  1921,  1926,  1931,  1936,  1941,  1946,  1951,  1956,  1961,
    1968,  1973,  1978,  1983,  1988,  1993,  1998,  2005,  2012,  2019,
    2024,  2029,  2034,  2039,  2044,  2049,  2054,  2059,  2064,  2069,
    2074,  2081,  2086,  2091,  2096,  2101,  2106,  2111,  2118,  2125,
    2132,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,
    2159,  2164,  2169,  2172,  2178,  2182,  2189,  2194,  2202,  2209,
    2216,  2221,  2223,  2226,  2229,  2233,  2237,  2249,  2259,  2267,
    2275,  2277,  2281,  2283,  2285,  2288,  2292,  2297,  2303,  2305,
    2307,  2310,  2314,  2318,  2324,  2329,  2332,  2335,  2338,  2341,
    2347,  2353,  2359,  2365,  2367,  2369,  2373,  2377,  2382,  2389,
    2396,  2398,  2400,  2404,  2408,  2418,  2426,  2428,  2434,  2438,
    2445,  2447,  2451,  2453,  2455,  2459,  2466,  2468,  2470,  2475,
    2482,  2489,  2494,  2499,  2504,  2511,  2513
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,   167,    -1,     1,     6,    -1,    -1,   167,
     168,    -1,   171,    -1,   170,    -1,   189,    -1,   202,    -1,
     207,    -1,   211,    -1,   212,    -1,   213,    -1,   216,    -1,
     236,    -1,   237,    -1,   238,    -1,   239,    -1,   215,    -1,
     214,    -1,   210,    -1,   241,    -1,   142,    -1,   142,   142,
      -1,    36,   155,     5,   156,     6,    -1,    37,   155,     5,
     156,     6,    -1,    36,   155,     5,   156,   169,   254,     6,
      -1,    36,   155,     5,   161,   250,   156,     6,    -1,    37,
     155,     5,   161,   250,   156,     6,    -1,    36,   155,     5,
     161,   250,   156,   169,   254,     6,    -1,     4,     5,   162,
     172,   163,     6,    -1,    91,     4,   157,   242,   158,     6,
      -1,    92,     4,   157,   242,   158,     6,    -1,    -1,   172,
     175,    -1,   172,   179,    -1,   172,   182,    -1,   172,   184,
      -1,   172,   185,    -1,   242,    -1,   173,   161,   242,    -1,
     242,    -1,   174,   161,   242,    -1,    -1,    -1,     4,   176,
     155,   173,   156,   177,   162,   174,   163,     6,    -1,   254,
      -1,   178,   161,   254,    -1,    -1,    97,   155,   242,   161,
     242,   161,   242,   156,   180,   162,   178,   163,     6,    -1,
     254,    -1,   181,   161,   254,    -1,    -1,    98,   155,   242,
     161,   242,   161,   242,   161,   242,   156,   183,   162,   181,
     163,     6,    -1,    99,   162,   246,   163,   162,   246,   163,
       6,    -1,    99,   162,   246,   163,   162,   246,   163,   162,
     246,   163,   162,   246,   163,     6,    -1,    -1,   100,   186,
     162,   174,   163,     6,    -1,     7,    -1,   135,    -1,   134,
      -1,   133,    -1,   132,    -1,   153,    -1,   152,    -1,    51,
     157,   191,   158,     6,    -1,     4,   187,   247,     6,    -1,
       4,   157,   158,   187,   247,     6,    -1,     4,   157,   242,
     158,   187,   242,     6,    -1,     4,   155,   242,   156,   187,
     242,     6,    -1,     4,   157,   162,   250,   163,   158,   187,
     247,     6,    -1,     4,   155,   162,   250,   163,   156,   187,
     247,     6,    -1,     4,   188,     6,    -1,     4,   157,   242,
     158,   188,     6,    -1,     4,     7,   255,     6,    -1,     4,
     159,     4,     7,   255,     6,    -1,     4,   157,   242,   158,
     159,     4,     7,   255,     6,    -1,     4,   159,     4,   187,
     242,     6,    -1,     4,   157,   242,   158,   159,     4,   187,
     242,     6,    -1,     4,   159,     4,   188,     6,    -1,     4,
     157,   242,   158,   159,     4,   188,     6,    -1,     4,   159,
     107,   159,     4,     7,   251,     6,    -1,     4,   157,   242,
     158,   159,   107,   159,     4,     7,   251,     6,    -1,     4,
     159,   108,     7,   252,     6,    -1,     4,   157,   242,   158,
     159,   108,     7,   252,     6,    -1,     4,   116,     7,   242,
       6,    -1,   116,   157,   242,   158,     7,     4,     6,    -1,
     116,   157,   242,   158,   159,     4,     7,   242,     6,    -1,
     116,   157,   242,   158,   159,     4,     7,   255,     6,    -1,
     116,   157,   242,   158,   159,     4,     7,   162,   250,   163,
       6,    -1,   116,   157,   242,   158,   159,     4,     6,    -1,
      74,   155,     4,   156,   159,     4,     7,   242,     6,    -1,
      74,   155,     4,   156,   159,     4,     7,   255,     6,    -1,
      -1,   161,    -1,    -1,   191,   190,     4,    -1,   191,   190,
       4,     7,   242,    -1,    -1,   191,   190,     4,     7,   162,
     242,   192,   195,   163,    -1,   191,   190,     4,     7,   255,
      -1,    -1,   191,   190,     4,     7,   162,   255,   193,   197,
     163,    -1,   242,     7,   255,    -1,   194,   161,   242,     7,
     255,    -1,    -1,   195,   196,    -1,   161,     4,   247,    -1,
     161,     4,   162,   194,   163,    -1,   161,     4,     5,    -1,
      -1,   197,   198,    -1,   161,     4,   242,    -1,   161,     4,
       5,    -1,   161,     4,   162,   256,   163,    -1,   242,    -1,
     255,    -1,    -1,   110,    56,   162,   242,   163,    -1,    -1,
      66,   244,    -1,    52,   155,   242,   156,     7,   244,     6,
      -1,    -1,    70,    52,   203,   155,   199,   156,     7,   247,
       6,    -1,    61,    62,   247,     7,   242,     6,    -1,    55,
     155,   242,   156,     7,   247,     6,    -1,    75,    55,   247,
       6,    -1,    59,   155,   242,   156,     7,   247,     6,    -1,
      53,   155,   242,   156,     7,   247,   201,     6,    -1,    54,
     155,   242,   156,     7,   247,   201,     6,    -1,   102,   155,
     242,   156,     7,   247,     6,    -1,   103,   155,   242,   156,
       7,   247,     6,    -1,   104,   155,   242,   156,     7,   247,
     106,   247,   105,   242,     6,    -1,    55,     4,   155,   242,
     156,     7,   247,     6,    -1,    71,    55,   155,   242,   156,
       7,   247,     6,    -1,    -1,    70,    55,   204,   155,   199,
     156,     7,   247,     6,    -1,    66,    58,   155,   242,   156,
       7,   247,     6,    -1,    67,    58,   155,   242,   156,     7,
     247,   200,     6,    -1,    12,    13,     6,    -1,    13,    58,
     242,     6,    -1,    63,    58,   155,   242,   156,     7,     5,
       5,     5,     6,    -1,    56,   155,   242,   156,     7,   247,
       6,    -1,    57,   155,   242,   156,     7,   247,     6,    -1,
      58,     4,   155,   242,   156,     7,   247,     6,    -1,    71,
      58,   155,   242,   156,     7,   247,     6,    -1,    71,    58,
     155,   242,   156,     7,   247,     4,   162,   246,   163,     6,
      -1,    -1,    70,    58,   205,   155,   199,   156,     7,   247,
       6,    -1,    69,    60,   155,   242,   156,     7,   247,     6,
      -1,    60,   155,   242,   156,     7,   247,     6,    -1,    71,
      60,   155,   242,   156,     7,   247,     6,    -1,    -1,    70,
      60,   206,   155,   199,   156,     7,   247,     6,    -1,    77,
     244,   162,   208,   163,    -1,    76,   162,   244,   161,   244,
     161,   242,   163,   162,   208,   163,    -1,    78,   244,   162,
     208,   163,    -1,    79,   162,   244,   161,   242,   163,   162,
     208,   163,    -1,    79,   162,   244,   161,   244,   163,   162,
     208,   163,    -1,     4,   162,   208,   163,    -1,    87,    55,
     162,   250,   163,    58,   162,   242,   163,    -1,    84,    55,
     155,   242,   156,   162,   250,   163,     6,    -1,   209,    -1,
     207,    -1,    -1,   209,   202,    -1,   209,    52,   162,   250,
     163,     6,    -1,   209,    55,   162,   250,   163,     6,    -1,
     209,    58,   162,   250,   163,     6,    -1,   209,    60,   162,
     250,   163,     6,    -1,    81,    66,   155,   242,   156,     7,
     247,     6,    -1,    81,    52,   155,   242,   156,     7,   162,
     246,   163,     6,    -1,    81,    66,   155,   242,   156,     7,
     162,   244,   161,   244,   161,   250,   163,     6,    -1,    81,
      66,   155,   242,   156,     7,   162,   244,   161,   244,   161,
     244,   161,   250,   163,     6,    -1,    81,    56,   155,   242,
     156,     7,   162,   244,   161,   250,   163,     6,    -1,    81,
       4,   155,   242,   156,     7,   247,     6,    -1,    81,     4,
     155,   242,   156,     7,     5,     6,    -1,    81,     4,   162,
     242,   163,     6,    -1,    81,     4,   155,   242,   156,     7,
     162,   244,   161,   244,   161,   250,   163,     6,    -1,    85,
     162,   209,   163,    -1,    85,   116,   157,   242,   158,     6,
      -1,    85,     4,   157,   242,   158,     6,    -1,    85,     4,
       6,    -1,    85,     4,     4,     6,    -1,   107,   251,   162,
     209,   163,    -1,   120,     5,     6,    -1,   121,     5,     6,
      -1,   120,   162,   209,   163,    -1,   121,   162,   209,   163,
      -1,     4,   255,     6,    -1,     4,     4,   157,   242,   158,
     254,     6,    -1,     4,     4,     4,   157,   242,   158,     6,
      -1,     4,   242,     6,    -1,    74,   155,     4,   156,   159,
       4,     6,    -1,   101,     4,     6,    -1,   114,     6,    -1,
     115,     6,    -1,    47,     6,    -1,    44,     6,    -1,    44,
     162,   242,   161,   242,   161,   242,   161,   242,   161,   242,
     161,   242,   163,     6,    -1,    45,     6,    -1,    48,     6,
      -1,    49,     6,    -1,    65,     6,    -1,   128,   242,     6,
      -1,   109,   155,   242,     8,   242,   156,    -1,   109,   155,
     242,     8,   242,     8,   242,   156,    -1,   109,     4,   110,
     162,   242,     8,   242,   163,    -1,   109,     4,   110,   162,
     242,     8,   242,     8,   242,   163,    -1,   111,    -1,   119,
       4,    -1,   117,    -1,   118,     4,     6,    -1,   112,   155,
     242,   156,    -1,   113,    -1,    80,   244,   162,   209,   163,
      -1,    80,   162,   244,   161,   244,   161,   242,   163,   162,
     209,   163,    -1,    80,   162,   244,   161,   244,   161,   244,
     161,   242,   163,   162,   209,   163,    -1,    -1,    80,   244,
     162,   209,   217,   230,   163,    -1,    -1,    80,   162,   244,
     161,   244,   161,   242,   163,   162,   209,   218,   230,   163,
      -1,    -1,    80,   162,   244,   161,   244,   161,   244,   161,
     242,   163,   162,   209,   219,   230,   163,    -1,    -1,    80,
     162,   209,   220,   230,   163,    -1,    80,    52,   162,   242,
     161,   244,   163,     6,    -1,    80,    55,   162,   242,   161,
     244,   163,     6,    -1,    80,    58,   162,   242,   161,   244,
     163,     6,    -1,    80,    52,   162,   242,   161,   244,   161,
     244,   161,   242,   163,     6,    -1,    80,    55,   162,   242,
     161,   244,   161,   244,   161,   242,   163,     6,    -1,    80,
      58,   162,   242,   161,   244,   161,   244,   161,   242,   163,
       6,    -1,    80,    52,   162,   242,   161,   244,   161,   244,
     161,   244,   161,   242,   163,     6,    -1,    80,    55,   162,
     242,   161,   244,   161,   244,   161,   244,   161,   242,   163,
       6,    -1,    80,    58,   162,   242,   161,   244,   161,   244,
     161,   244,   161,   242,   163,     6,    -1,    -1,    80,    52,
     162,   242,   161,   244,   163,   221,   162,   230,   163,     6,
      -1,    -1,    80,    55,   162,   242,   161,   244,   163,   222,
     162,   230,   163,     6,    -1,    -1,    80,    58,   162,   242,
     161,   244,   163,   223,   162,   230,   163,     6,    -1,    -1,
      80,    52,   162,   242,   161,   244,   161,   244,   161,   242,
     163,   224,   162,   230,   163,     6,    -1,    -1,    80,    55,
     162,   242,   161,   244,   161,   244,   161,   242,   163,   225,
     162,   230,   163,     6,    -1,    -1,    80,    58,   162,   242,
     161,   244,   161,   244,   161,   242,   163,   226,   162,   230,
     163,     6,    -1,    -1,    80,    52,   162,   242,   161,   244,
     161,   244,   161,   244,   161,   242,   163,   227,   162,   230,
     163,     6,    -1,    -1,    80,    55,   162,   242,   161,   244,
     161,   244,   161,   244,   161,   242,   163,   228,   162,   230,
     163,     6,    -1,    -1,    80,    58,   162,   242,   161,   244,
     161,   244,   161,   244,   161,   242,   163,   229,   162,   230,
     163,     6,    -1,   231,    -1,   230,   231,    -1,    89,   162,
     242,   163,     6,    -1,    89,   162,   247,   161,   247,   163,
       6,    -1,    89,   162,   247,   161,   247,   161,   247,   163,
       6,    -1,    82,     6,    -1,    93,     6,    -1,    93,    95,
       6,    -1,    94,     6,    -1,    94,    95,     6,    -1,    90,
     155,   242,   156,     7,   247,    73,   242,     6,    -1,    73,
       4,   157,   242,   158,     6,    -1,    -1,    73,     4,   242,
      -1,    -1,     4,    -1,    -1,     7,   247,    -1,    -1,     7,
     242,    -1,    68,    55,   248,     7,   242,   232,     6,    -1,
      68,    58,   248,   234,   233,     6,    -1,    64,    58,   162,
     242,   163,     7,   247,     6,    -1,    68,    60,   248,   234,
       6,    -1,    96,   248,     6,    -1,    88,    58,   162,   250,
     163,   242,     6,    -1,    82,    58,   248,   235,     6,    -1,
      82,    60,   248,     6,    -1,    83,    58,   247,     7,   242,
       6,    -1,    72,    55,   247,     7,   247,     6,    -1,    72,
      58,   242,   162,   250,   163,     7,   242,   162,   250,   163,
       6,    -1,    52,   162,   250,   163,   110,    58,   162,   242,
     163,     6,    -1,    55,   162,   250,   163,   110,    58,   162,
     242,   163,     6,    -1,    55,   162,   250,   163,   110,    60,
     162,   242,   163,     6,    -1,    58,   162,   250,   163,   110,
      60,   162,   242,   163,     6,    -1,    86,     6,    -1,    86,
       4,     6,    -1,    86,    52,   162,   250,   163,     6,    -1,
     125,    -1,   126,    -1,   127,    -1,   240,     6,    -1,   240,
     162,   247,   163,     6,    -1,   240,   162,   247,   161,   247,
     163,     6,    -1,   240,   155,   247,   156,   162,   247,   161,
     247,   163,     6,    -1,   243,    -1,   155,   242,   156,    -1,
     146,   242,    -1,   145,   242,    -1,   150,   242,    -1,   242,
     146,   242,    -1,   242,   145,   242,    -1,   242,   147,   242,
      -1,   242,   148,   242,    -1,   242,   149,   242,    -1,   242,
     154,   242,    -1,   242,   141,   242,    -1,   242,   142,   242,
      -1,   242,   144,   242,    -1,   242,   143,   242,    -1,   242,
     140,   242,    -1,   242,   139,   242,    -1,   242,   138,   242,
      -1,   242,   137,   242,    -1,   242,   136,   242,     8,   242,
      -1,    14,   155,   242,   156,    -1,    15,   155,   242,   156,
      -1,    16,   155,   242,   156,    -1,    17,   155,   242,   156,
      -1,    18,   155,   242,   156,    -1,    19,   155,   242,   156,
      -1,    20,   155,   242,   156,    -1,    21,   155,   242,   156,
      -1,    22,   155,   242,   156,    -1,    24,   155,   242,   156,
      -1,    25,   155,   242,   161,   242,   156,    -1,    26,   155,
     242,   156,    -1,    27,   155,   242,   156,    -1,    28,   155,
     242,   156,    -1,    29,   155,   242,   156,    -1,    30,   155,
     242,   156,    -1,    31,   155,   242,   156,    -1,    32,   155,
     242,   161,   242,   156,    -1,    33,   155,   242,   161,   242,
     156,    -1,    34,   155,   242,   161,   242,   156,    -1,    23,
     155,   242,   156,    -1,    14,   157,   242,   158,    -1,    15,
     157,   242,   158,    -1,    16,   157,   242,   158,    -1,    17,
     157,   242,   158,    -1,    18,   157,   242,   158,    -1,    19,
     157,   242,   158,    -1,    20,   157,   242,   158,    -1,    21,
     157,   242,   158,    -1,    22,   157,   242,   158,    -1,    24,
     157,   242,   158,    -1,    25,   157,   242,   161,   242,   158,
      -1,    26,   157,   242,   158,    -1,    27,   157,   242,   158,
      -1,    28,   157,   242,   158,    -1,    29,   157,   242,   158,
      -1,    30,   157,   242,   158,    -1,    31,   157,   242,   158,
      -1,    32,   157,   242,   161,   242,   158,    -1,    33,   157,
     242,   161,   242,   158,    -1,    34,   157,   242,   161,   242,
     158,    -1,    23,   157,   242,   158,    -1,     3,    -1,     9,
      -1,    10,    -1,    11,    -1,   129,    -1,   130,    -1,   131,
      -1,     4,    -1,     4,   164,   162,   242,   163,    -1,     4,
     157,   242,   158,    -1,   160,     4,   157,   158,    -1,     4,
     188,    -1,     4,   157,   242,   158,   188,    -1,     4,   159,
       4,    -1,     4,   157,   242,   158,   159,     4,    -1,     4,
     159,     4,   188,    -1,     4,   157,   242,   158,   159,     4,
     188,    -1,   122,   155,   254,   161,   242,   156,    -1,    42,
     155,   254,   161,   254,   156,    -1,    43,   155,   256,   156,
      -1,   245,    -1,   146,   244,    -1,   145,   244,    -1,   244,
     146,   244,    -1,   244,   145,   244,    -1,   162,   242,   161,
     242,   161,   242,   161,   242,   161,   242,   163,    -1,   162,
     242,   161,   242,   161,   242,   161,   242,   163,    -1,   162,
     242,   161,   242,   161,   242,   163,    -1,   155,   242,   161,
     242,   161,   242,   156,    -1,   247,    -1,   246,   161,   247,
      -1,   242,    -1,   249,    -1,   162,   163,    -1,   162,   250,
     163,    -1,   146,   162,   250,   163,    -1,   242,   147,   162,
     250,   163,    -1,   247,    -1,     5,    -1,   146,   249,    -1,
     242,   147,   249,    -1,   242,     8,   242,    -1,   242,     8,
     242,     8,   242,    -1,    52,   162,   242,   163,    -1,    52,
       5,    -1,    55,     5,    -1,    58,     5,    -1,    60,     5,
      -1,    70,    52,   162,   250,   163,    -1,    70,    55,   162,
     250,   163,    -1,    70,    58,   162,   250,   163,    -1,    70,
      60,   162,   250,   163,    -1,   207,    -1,   216,    -1,     4,
     157,   158,    -1,     4,   155,   156,    -1,    35,   157,     4,
     158,    -1,     4,   157,   162,   250,   163,   158,    -1,     4,
     155,   162,   250,   163,   156,    -1,   242,    -1,   249,    -1,
     250,   161,   242,    -1,   250,   161,   249,    -1,   162,   242,
     161,   242,   161,   242,   161,   242,   163,    -1,   162,   242,
     161,   242,   161,   242,   163,    -1,     4,    -1,     4,   159,
     107,   159,     4,    -1,   162,   253,   163,    -1,     4,   157,
     242,   158,   159,   108,    -1,   251,    -1,   253,   161,   251,
      -1,   255,    -1,     4,    -1,     4,   159,     4,    -1,     4,
     157,   242,   158,   159,     4,    -1,     5,    -1,    46,    -1,
     123,   155,   254,   156,    -1,   124,   155,   254,   161,   254,
     156,    -1,    39,   155,   254,   161,   254,   156,    -1,    40,
     155,   254,   156,    -1,    41,   155,   254,   156,    -1,    38,
     155,   254,   156,    -1,    38,   155,   254,   161,   250,   156,
      -1,   254,    -1,   256,   161,   254,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   167,   172,   174,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   198,   202,   209,   214,   219,   233,   246,
     259,   287,   301,   312,   327,   332,   333,   334,   335,   336,
     340,   342,   347,   349,   355,   459,   354,   477,   484,   495,
     494,   512,   519,   530,   529,   546,   563,   586,   585,   599,
     600,   601,   602,   603,   607,   608,   614,   616,   678,   708,
     743,   777,   825,   872,   887,   903,   912,   918,   927,   945,
     963,   972,   984,   989,   997,  1017,  1040,  1051,  1059,  1081,
    1104,  1130,  1151,  1163,  1177,  1177,  1179,  1181,  1192,  1204,
    1203,  1215,  1227,  1226,  1241,  1247,  1254,  1255,  1259,  1270,
    1285,  1295,  1296,  1301,  1309,  1318,  1337,  1341,  1352,  1355,
    1368,  1371,  1381,  1405,  1404,  1424,  1446,  1464,  1485,  1503,
    1533,  1563,  1581,  1599,  1625,  1643,  1662,  1661,  1684,  1702,
    1741,  1747,  1753,  1760,  1785,  1810,  1827,  1844,  1876,  1875,
    1899,  1917,  1934,  1951,  1950,  1976,  1981,  1986,  1991,  1996,
    2001,  2024,  2030,  2041,  2042,  2047,  2050,  2054,  2077,  2100,
    2123,  2151,  2172,  2195,  2216,  2238,  2258,  2370,  2389,  2427,
    2536,  2545,  2551,  2566,  2594,  2611,  2625,  2631,  2637,  2646,
    2660,  2705,  2722,  2737,  2756,  2768,  2792,  2796,  2801,  2808,
    2814,  2819,  2825,  2829,  2833,  2838,  2848,  2865,  2882,  2903,
    2924,  2959,  2967,  2973,  2980,  2984,  2993,  3001,  3009,  3018,
    3017,  3031,  3030,  3044,  3043,  3057,  3056,  3069,  3076,  3083,
    3090,  3097,  3104,  3111,  3118,  3125,  3133,  3132,  3145,  3144,
    3157,  3156,  3169,  3168,  3181,  3180,  3193,  3192,  3205,  3204,
    3217,  3216,  3229,  3228,  3244,  3247,  3253,  3262,  3282,  3305,
    3309,  3313,  3317,  3321,  3325,  3344,  3357,  3360,  3376,  3379,
    3392,  3395,  3401,  3404,  3411,  3467,  3537,  3542,  3609,  3645,
    3654,  3697,  3736,  3761,  3788,  3835,  3858,  3881,  3884,  3893,
    3897,  3907,  3942,  3943,  3944,  3948,  3954,  3966,  3984,  4012,
    4013,  4014,  4015,  4016,  4017,  4018,  4019,  4020,  4027,  4028,
    4029,  4030,  4031,  4032,  4033,  4034,  4035,  4036,  4037,  4038,
    4039,  4040,  4041,  4042,  4043,  4044,  4045,  4046,  4047,  4048,
    4049,  4050,  4051,  4052,  4053,  4054,  4055,  4056,  4057,  4058,
    4061,  4062,  4063,  4064,  4065,  4066,  4067,  4068,  4069,  4070,
    4071,  4072,  4073,  4074,  4075,  4076,  4077,  4078,  4079,  4080,
    4081,  4090,  4091,  4092,  4093,  4094,  4095,  4096,  4100,  4121,
    4140,  4158,  4170,  4187,  4208,  4213,  4218,  4228,  4238,  4243,
    4252,  4279,  4283,  4287,  4291,  4295,  4302,  4306,  4310,  4314,
    4321,  4326,  4333,  4338,  4342,  4347,  4351,  4359,  4370,  4374,
    4386,  4394,  4402,  4409,  4419,  4439,  4443,  4447,  4451,  4455,
    4484,  4513,  4542,  4571,  4581,  4591,  4604,  4616,  4628,  4647,
    4668,  4673,  4677,  4681,  4693,  4697,  4709,  4716,  4726,  4730,
    4745,  4750,  4757,  4761,  4774,  4782,  4793,  4797,  4805,  4813,
    4821,  4829,  4843,  4857,  4861,  4883,  4888
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tExp", "tLog", "tLog10", "tSqrt", "tSin", "tAsin",
  "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh", "tCosh",
  "tTanh", "tFabs", "tFloor", "tCeil", "tFmod", "tModulo", "tHypot",
  "tList", "tPrintf", "tError", "tSprintf", "tStrCat", "tStrPrefix",
  "tStrRelative", "tStrFind", "tTextAttributes", "tBoundingBox", "tDraw",
  "tToday", "tSyncModel", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tPoint", "tCircle", "tEllipse",
  "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tPlane", "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tLayers", "tHole", "tAlias",
  "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tFunction",
  "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString", "tHomology",
  "tCohomology", "tBetti", "tSetOrder", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "$@1", "$@2", "Text2DValues", "Text2D",
  "$@3", "Text3DValues", "Text3D", "$@4", "InterpolationMatrix", "Time",
  "$@5", "NumericAffectation", "NumericIncrement", "Affectation", "Comma",
  "DefineConstants", "$@6", "$@7", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "$@8", "$@9",
  "$@10", "$@11", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "Transfinite", "Periodic", "Embedding", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "RecursiveListOfStringExprVar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,    63,   391,   392,   393,
     394,    60,    62,   395,   396,    43,    45,    42,    47,    37,
      33,   397,   398,   399,    94,    40,    41,    91,    93,    46,
      35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   166,   167,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   169,   169,   170,   170,   170,   170,   170,
     170,   171,   171,   171,   172,   172,   172,   172,   172,   172,
     173,   173,   174,   174,   176,   177,   175,   178,   178,   180,
     179,   181,   181,   183,   182,   184,   184,   186,   185,   187,
     187,   187,   187,   187,   188,   188,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   190,   190,   191,   191,   191,   192,
     191,   191,   193,   191,   194,   194,   195,   195,   196,   196,
     196,   197,   197,   198,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   203,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   204,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   205,   202,
     202,   202,   202,   206,   202,   207,   207,   207,   207,   207,
     207,   207,   207,   208,   208,   209,   209,   209,   209,   209,
     209,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     211,   211,   211,   211,   211,   212,   213,   213,   213,   213,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   216,   216,   216,   217,
     216,   218,   216,   219,   216,   220,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   221,   216,   222,   216,
     223,   216,   224,   216,   225,   216,   226,   216,   227,   216,
     228,   216,   229,   216,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   232,   232,   233,   233,
     234,   234,   235,   235,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   237,   237,   238,   238,   238,   238,   239,
     239,   239,   240,   240,   240,   241,   241,   241,   241,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   244,   244,   244,   244,   244,   245,   245,   245,   245,
     246,   246,   247,   247,   247,   247,   247,   247,   248,   248,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     250,   250,   250,   250,   251,   251,   251,   251,   252,   252,
     253,   253,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   256,   256
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     5,     7,     7,     7,
       9,     6,     6,     6,     0,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     0,     0,    10,     1,     3,     0,
      13,     1,     3,     0,    15,     8,    14,     0,     6,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     6,     7,
       7,     9,     9,     3,     6,     4,     6,     9,     6,     9,
       5,     8,     8,    11,     6,     9,     5,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     5,     0,     9,     3,     5,     0,     2,     3,     5,
       3,     0,     2,     3,     3,     5,     1,     1,     0,     5,
       0,     2,     7,     0,     9,     6,     7,     4,     7,     8,
       8,     7,     7,    11,     8,     8,     0,     9,     8,     9,
       3,     4,    10,     7,     7,     8,     8,    12,     0,     9,
       8,     7,     8,     0,     9,     5,    11,     5,     9,     9,
       4,     9,     9,     1,     1,     0,     2,     6,     6,     6,
       6,     8,    10,    14,    16,    12,     8,     8,     6,    14,
       4,     6,     6,     3,     4,     5,     3,     3,     4,     4,
       3,     7,     7,     3,     7,     3,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     3,     6,     8,     8,    10,
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     3,     2,     3,     9,     6,     0,     3,     0,     1,
       0,     2,     0,     2,     7,     6,     8,     5,     3,     7,
       5,     4,     6,     6,    12,    10,    10,    10,    10,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     4,     2,     5,     3,     6,     4,     7,     6,     6,
       4,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     1,
       2,     3,     3,     5,     4,     2,     2,     2,     2,     5,
       5,     5,     5,     1,     1,     3,     3,     4,     6,     6,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     3,     6,     1,     1,     4,     6,
       6,     4,     4,     4,     6,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,     0,   215,     0,     0,     0,   212,     0,     0,
       0,     0,   292,   293,   294,     0,     5,     7,     6,     8,
       9,    10,    21,    11,    12,    13,    20,    19,    14,    15,
      16,    17,    18,     0,    22,   361,   368,   436,    59,   362,
     363,   364,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   437,
       0,     0,     0,     0,   365,   366,   367,    63,    62,    61,
      60,     0,     0,     0,    65,    64,     0,     0,     0,     0,
     165,     0,     0,     0,   299,     0,     0,     0,     0,     0,
     199,     0,   201,   198,   202,   203,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
     123,   136,   148,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   381,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,   289,     0,     0,
       0,     0,     0,   368,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   414,   392,   398,     0,   393,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
     196,   197,     0,     0,   211,     0,   165,     0,   165,   368,
       0,   295,     0,     0,     0,     0,     0,     0,   372,    34,
     436,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   301,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,   163,
       0,    73,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   140,
       0,     0,     0,     0,    94,     0,     0,   420,   421,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,   382,     0,     0,     0,     0,   165,   165,
       0,     0,     0,     0,     0,     0,     0,   225,     0,   165,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     183,     0,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,   405,     0,   406,   407,   408,     0,     0,
       0,     0,     0,   301,   400,     0,   394,     0,     0,     0,
     278,   195,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,   213,   186,     0,   187,     0,     0,   205,     0,
       0,     0,     0,   374,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   433,
       0,   432,     0,     0,     0,     0,   445,     0,     0,     0,
       0,     0,     0,   300,    59,     0,     0,     0,    59,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,   166,
      67,     0,   317,   316,   315,   314,   310,   311,   313,   312,
     305,   304,   306,   307,   308,   309,   141,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,   385,   384,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,   184,     0,     0,   180,
       0,     0,     0,     0,     0,   416,     0,   415,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   300,   395,   402,
       0,   306,   401,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,   188,   189,     0,     0,     0,     0,   370,
     376,     0,    44,     0,     0,     0,    57,     0,    35,    36,
      37,    38,    39,   319,   340,   320,   341,   321,   342,   322,
     343,   323,   344,   324,   345,   325,   346,   326,   347,   327,
     348,   339,   360,   328,   349,     0,     0,   330,   351,   331,
     352,   332,   353,   333,   354,   334,   355,   335,   356,     0,
       0,     0,     0,     0,     0,     0,     0,   443,     0,     0,
     441,   442,     0,   380,     0,    86,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,   371,     0,     0,     0,     0,     0,    25,
      23,     0,     0,    26,     0,     0,    66,    97,     0,   422,
     423,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   271,
     269,     0,   277,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,     0,   216,     0,     0,     0,     0,
       0,     0,   273,   280,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   370,   417,   404,     0,     0,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
     185,     0,     0,     0,     0,     0,     0,   296,     0,     0,
     373,     0,   369,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,     0,
       0,     0,   446,     0,     0,     0,     0,    68,     0,     0,
       0,     0,     0,    74,    76,    78,     0,     0,   430,     0,
      84,     0,     0,     0,     0,   318,    24,     0,     0,     0,
       0,     0,     0,     0,   120,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,   260,     0,   262,
       0,   226,   255,     0,     0,     0,   178,     0,     0,     0,
     282,     0,   182,   181,   291,     0,     0,    32,    33,     0,
       0,   409,   410,   411,   412,   403,   397,     0,     0,     0,
     427,     0,     0,     0,   206,     0,     0,     0,     0,   192,
     375,   191,     0,     0,     0,     0,   390,     0,   329,   350,
     336,   357,   337,   358,   338,   359,     0,   444,   440,   379,
     378,   439,     0,    70,     0,    59,     0,     0,     0,     0,
      69,     0,     0,     0,   428,     0,     0,     0,     0,    27,
      28,     0,    29,     0,     0,    98,   101,   122,     0,     0,
       0,     0,     0,   126,     0,     0,   143,   144,     0,     0,
     128,   151,     0,     0,     0,   118,     0,   274,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,     0,     0,
       0,     0,   165,   165,     0,   236,     0,   238,     0,   240,
       0,   392,     0,     0,   261,   263,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   419,
     418,   131,   132,     0,     0,     0,     0,    87,    91,     0,
       0,   297,   377,     0,    40,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,    81,     0,     0,    82,
       0,   431,   167,   168,   169,   170,     0,     0,    99,   102,
       0,   121,   129,   130,   134,     0,     0,   145,     0,     0,
     276,   138,     0,     0,   267,   150,     0,     0,     0,     0,
     135,     0,   146,   152,     0,     0,     0,     0,   389,     0,
     388,     0,     0,     0,   227,     0,     0,   228,     0,     0,
     229,     0,     0,     0,     0,     0,     0,     0,   177,     0,
       0,   176,     0,     0,     0,   171,     0,     0,     0,     0,
     425,     0,   208,   207,     0,     0,     0,     0,    45,     0,
       0,     0,   391,     0,     0,     0,   435,    72,    71,    77,
      79,     0,    85,     0,    30,     0,   106,   111,     0,     0,
       0,     0,     0,     0,   139,   124,   137,   149,   154,     0,
       0,    92,    93,   165,     0,   158,   159,     0,     0,     0,
       0,     0,     0,     0,   256,     0,     0,   165,     0,     0,
       0,     0,     0,   162,   161,     0,     0,     0,     0,    88,
      89,     0,     0,    41,     0,     0,     0,    43,    58,     0,
     429,     0,     0,     0,   285,   286,   287,   288,   142,     0,
       0,     0,     0,     0,   387,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,     0,     0,   221,     0,
       0,   172,     0,     0,     0,   424,   209,     0,   298,     0,
       0,     0,     0,    83,     0,     0,   100,   107,     0,   103,
     112,     0,     0,     0,   156,     0,   242,     0,     0,   244,
       0,     0,   246,     0,     0,     0,   257,     0,   217,     0,
     165,     0,     0,     0,   133,    90,     0,    49,     0,    55,
       0,     0,     0,     0,   119,   147,   284,   386,   230,     0,
       0,   237,   231,     0,     0,   239,   232,     0,     0,   241,
       0,     0,     0,   223,     0,   175,     0,     0,     0,     0,
       0,     0,     0,   110,     0,   108,   114,     0,   113,     0,
     248,     0,   250,     0,   252,   258,   264,   222,   218,     0,
       0,     0,     0,    46,     0,    53,     0,     0,     0,   420,
       0,     0,   233,     0,     0,   234,     0,     0,   235,     0,
       0,   179,     0,   173,     0,    47,     0,     0,   200,     0,
     109,     0,   115,     0,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,   104,   243,     0,   245,
       0,   247,     0,   174,    48,    50,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    56,   105,   249,   251,   253,
      52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    76,   791,    77,    78,   495,  1163,  1169,
     708,   903,  1322,  1484,   709,  1439,  1516,   710,  1486,   711,
     712,   907,   151,   278,    79,   594,   374,  1276,  1277,  1468,
    1332,  1377,  1333,  1380,   824,  1203,  1090,   569,   400,   401,
     402,   403,   244,   348,   349,    82,    83,    84,    85,    86,
      87,   245,   856,  1399,  1459,   643,  1225,  1228,  1231,  1419,
    1423,  1427,  1473,  1476,  1479,   852,   853,   972,   821,   617,
     652,    89,    90,    91,    92,    93,    94,   246,   154,   413,
     207,  1045,   247,   248,   249,   467,   256,   782,   939,   546,
     541,   547
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1142
static const yytype_int16 yypact[] =
{
    4330,     2,    41,  4416, -1142, -1142,  2109,    45,   -23,  -101,
     -89,    36,    44,    70,    84,   119,   -11,   -29,    24,    53,
       1,    57,    65,    22,    69,    99,    92,   129,   147,   331,
     200,   264,   163,   276,   216,   217,    80,   188,   295,   207,
     -77,   -77,   213,   749,    47,    54,   320,   340,    16,    13,
     346,   358,   403,   429,  2303,   450,   303,   309,   322,    23,
      52, -1142,   348, -1142,   472,   489,   354, -1142,   516,   533,
      31,    32, -1142, -1142, -1142,   831, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142,    42, -1142, -1142,     5,   376,   504, -1142,
   -1142, -1142,    87,   109,   300,   344,   412,   447,   452,   455,
     477,   491,   510,   536,   542,   546,   567,   575,   618,   633,
     642,   671,   672,   392,   408,   415,   416,   432,   441, -1142,
     599,   446,   456,   482, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142,   831,   831,   831, -1142, -1142,  3815,  1522,    12,   646,
     629,  2765,   645,   436, -1142,   648,   652,   831,   656,   657,
   -1142,   831, -1142, -1142, -1142, -1142, -1142,   831,  4004,   831,
     831,   514,   831,  4004,   831,   831,   519,  4004,   831,   831,
    2765,   526,   532, -1142,   549,   566,  2303,  2303,  2303,   571,
   -1142, -1142, -1142, -1142,   576,   580,   581,  2765,   831,   739,
    2765,   -77,   -77,   -77,   831,   831,   -71, -1142,   -41,   -77,
     592,   598,   601,  3850,   -15,    26,   612,   619,   625,  2303,
    2303,  2765,   632,    49,   639, -1142,   796, -1142,   641,   681,
     704,   713,   714,   224, -1142,   718,    33,   871,   882,   887,
     506,  2919,   831,  1928, -1142, -1142,  3975, -1142,   891, -1142,
     894,   831,   831,   831,   734,   831,   743,   791,   831,   831,
   -1142, -1142,   831,   903, -1142,   911, -1142,   912, -1142,   355,
     676, -1142,  2765,  2765,   753,   831,   910,   765, -1142, -1142,
   -1142,   928,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,    77,    77,    77,    77,    77,    77,
     831,    77,    77,    77,   770,   770,   770,  4004,  6735,    81,
    4004,  5976,   490,   771,   930,   784,   778, -1142,   788,  4493,
     941, -1142, -1142,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   831,   831, -1142, -1142,
    1290,   169,   173,  5274,   290,  6756,  4004,  4063, -1142,   616,
    6777,  6798,   831,  6819,   670,  6840,  6861,   831,   675,  6882,
    6903,   965,   831,   831,   831,   831,   975,   991,   991,   831,
     814,   818,   832,   852,   831,   831,   831,   997,  5194,   860,
    1005,   100, -1142, -1142,  5300,  5326,   -77,   -77,   629,   629,
     181,   831,   831,   831,  3850,  3850,   831,  4493,   254, -1142,
     831,   831,   831,   831,   831,  1008,  1036,  1040,   831,  1046,
   -1142,   831,   831,  1212, -1142,  4004,  4004,  4004,   831,   831,
    -149,  3620,  1049, -1142,   831, -1142, -1142, -1142,   921,   929,
     932,   933,  4004,   770, -1142,  6924, -1142,   706,   831,  3073,
   -1142, -1142,  6945,  6966,  6987,   959,  5352, -1142,   940,  4082,
    7008,  5999, -1142, -1142,  1677, -1142,  2146,   831, -1142,   901,
     719,   831,  6022,   -52,   831,    11, -1142,  7029,  6045,  7050,
    6068,  7071,  6091,  7092,  6114,  7113,  6137,  7134,  6160,  7155,
    6183,  7176,  6206,  7197,  6229,  7218,  6252,  7239,  6275,  5378,
    5404,  7260,  6298,  7281,  6321,  7302,  6344,  7323,  6367,  7344,
    6390,  7365,  6413,  5430,  5456,  5482,  5508,  5534,  5560,   680,
     212, -1142,   914,   915,   934,   919, -1142,   252,  1324,   949,
     963,   979,   725,    81, -1142,  2765,   735,   341,   504,   831,
    1120,  1147,    29,   994, -1142,    27,    28,    30,    55, -1142,
   -1142,  4101,  1455,  1515,  1235,  1235,   810,   810,   810,   810,
     622,   622,   770,   770,   770,   770, -1142,     8,  4004,  1148,
    4004,   831,  1149, -1142,  1152,  1153,  4004,  4004,  1052,  1158,
    1160,  7386,  1161,  1059,  1164,  1166,  7407,  1066,  1168,  1170,
     831,  7428,  4522,  7449,  7470,   831,  2765,  1155,  1172,  7491,
    4152,  4152,  4152,  4152,  7512,  7533,  7554,  2765,  4004,  1021,
   -1142,   -77,   831,   831, -1142, -1142,  1018,  1019,  3850,  5586,
    5612,  5638,  5248,   586,   -77,  2339,  7575,  4550,  7596,  7617,
    7638,   831,  1177, -1142,   831,  7659, -1142,  6436,  6459, -1142,
     762,   783,   789,  6482,  6505, -1142,  4004, -1142,  4004,  6528,
    1026,  4578,  4004,  4004,  4004,  4004,   804, -1142, -1142,  4123,
    4004,   770, -1142,  1180,  1181,  1184,  1035,   831,  2493,   831,
     831, -1142,    50, -1142, -1142,  1034,  2765,  1191,  6551,   754,
   -1142,  4606, -1142,  1044,  1061,  1056, -1142,  1216, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142,   831,   831, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,   831,
     831,   831,   831,   831,   831,   831,  1219, -1142,  4004,    77,
   -1142, -1142,    77, -1142,    77, -1142,   831, -1142,    77,  1070,
     831,  1222,  1071,    35,   831,  1224,  1226,  1489, -1142,  1227,
    1076,    23,  1233, -1142,  4004,  4004,  4004,  4004,   831, -1142,
    1098,    77,   330, -1142,   349,  5664, -1142,  1234,   -77,  4063,
   -1142,  1185,  2765,  2765,  1237,  2765,   908,  2765,  2765,  1238,
    1182,  2765,  2765,  1555,  1239,  1241,  1243,  1244,  4211, -1142,
   -1142,  1247, -1142,  1248,  1100,  7890, -1142,  1102,  1103,  1104,
    1254,  1256,  1267,  1270,   817,  1250,   266,  5690,  5716, -1142,
   -1142,  4634,   -39,   -77,   -77,   -77,  1273,  1274,  1122,  1130,
      34,    39,   -10, -1142,   280, -1142,   586,  1279,  1283,  1284,
    1286,  1287,  7890, -1142,  1739,  1128,  1292,  1297,  1298,  1252,
     831,  1299,  1300,   829,   842,   -82, -1142, -1142,   847,   858,
     859,   863, -1142,   831,   864,  2765,  2765,  2765,  1304,  5742,
   -1142,  4179,  1065,  1307,  1308,  2765,  1156, -1142,  1312,  1316,
   -1142,  1315, -1142,  1176,   831,   831,  2765,  1163, -1142,  7680,
    6574,  7701,  6597,  7722,  6620,  7743,  6643,  6666, -1142,   380,
    1171,  1178, -1142,  7764,  1179,    81,  1888, -1142,    81,   585,
    1173,  1326,  2032, -1142, -1142, -1142,    23,   831, -1142,   872,
   -1142,   875,   878,   885,   895,  7890, -1142,  1330,    38,  1332,
     831,  3535,     6,  1186,  1276,  1276,  2765,  1333,  1187,  1188,
    1334,  1338,  2765,  1189,  1340,  1346, -1142,  1348,  2765,  2765,
    2765,  1350,  1351, -1142,  2765,  1349,  1352,  1353,  1354,  2765,
    2765,  2765, -1142,  1355,   130,   831,   831,   831,  1201,  1202,
     -99,   186,   221,  1208, -1142,  2765,   831, -1142,  1360, -1142,
    1362, -1142, -1142,  3850,   251,  2457, -1142,  1207,  1209,  3227,
   -1142,  4004, -1142, -1142, -1142,  1210,  2138, -1142, -1142,  1214,
    1215, -1142, -1142, -1142, -1142,  7890, -1142,  1368,  1381,  1288,
   -1142,   831,   831,   831, -1142,  1384,   154,  1231,  1387, -1142,
     -52, -1142,   831,  5768,  5794,   899, -1142,   831, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142, -1142,  1245, -1142, -1142, -1142,
   -1142, -1142,  2765, -1142,  2765,   504,   831,  1390,  1393,    29,
   -1142,  1392,  6689,    23, -1142,  1394,  1396,  1397,  1399, -1142,
   -1142,    77, -1142,  5820,  4152,  7890, -1142, -1142,   831,   -77,
    1401,  1402,  1404, -1142,   831,   831, -1142, -1142,  1406,   831,
   -1142, -1142,  1410,  1411,  1414,  1311,   831, -1142,  1418,  2765,
    2765,  2765,  2765,  1419,  1057,  1434,   831, -1142,  4152,  4662,
    7785,  4437,   629,   629,   -77,  1435,   -77,  1440,   -77,  1441,
     831,    89,  1289,  7806, -1142, -1142,  4690,   289, -1142,  1442,
    1773,  1447,  2765,   -77,  1773,  1448,   904,   831, -1142, -1142,
   -1142, -1142, -1142,  2765,  4465,   386,  7827, -1142, -1142,  3579,
    2765, -1142, -1142,   390,  7890,   831,   831,  2765,  1293,   909,
    7890,  1452,  1451,  1468,  1469,  2871, -1142,  1470,  1473, -1142,
    1317, -1142, -1142, -1142, -1142, -1142,  1474,   831,  7890, -1142,
    4718,   133, -1142, -1142, -1142,  4746,  4774, -1142,  4802,  1453,
   -1142, -1142,  1425,  1476,  7890, -1142,  1478,  1480,  1482,  1483,
   -1142,  1328, -1142, -1142,  5221,  2891,  1485,  1331, -1142,   831,
   -1142,  1329,  1336,   292, -1142,  1339,   323, -1142,  1341,   326,
   -1142,  1342,  6712,  1488,  2765,  1493,  1343,   831, -1142,  3381,
     335, -1142,   913,   337,   495, -1142,  1496,  4830,  1403,   831,
   -1142,   831, -1142, -1142,  4004,  3036,  1501,  1347, -1142,   831,
    5846,  5872, -1142,  2765,   831,  1503, -1142, -1142, -1142, -1142,
   -1142,    23, -1142,  1407, -1142,  5898, -1142, -1142,  1505,  1506,
    1508,  1510,  1512,  1357, -1142, -1142, -1142, -1142, -1142,  2765,
    4004, -1142, -1142,   629,  4494, -1142, -1142,  3850,   586,  3850,
     586,  3850,   586,  1514, -1142,   918,  2765, -1142,  4858,   -77,
    1516,  4004,   -77, -1142, -1142,   831,  4886,  4914,   938, -1142,
   -1142,  1518,  1372,  7890,   831,   831,   942,  7890, -1142,  1551,
   -1142,   831,   945,   946, -1142, -1142, -1142, -1142, -1142,   831,
     950,   954,  1395,   831, -1142,  4942,   499,   316,  4970,   583,
     466,  4998,   594,   716, -1142,  2765,  1553,  1487,  2647,  1400,
     596, -1142,   957,   600,  3180, -1142, -1142,  1557, -1142,   831,
    7848,  5924,    37, -1142,  5950,  1562, -1142, -1142,  1564, -1142,
   -1142,  5026,  1563,  1565, -1142,  5054,  1566,   831,  1568,  1569,
     831,  1570,  1571,   831,  1572,  1420, -1142,   831, -1142,   586,
   -1142,  4004,  1576,  3381, -1142, -1142,   962, -1142,   831, -1142,
    2765,   831,  2611,  3780, -1142, -1142, -1142, -1142, -1142,  1408,
    5082, -1142, -1142,  1422,  5110, -1142, -1142,  1424,  5138, -1142,
    1581,  3199,   826,  2801,   966, -1142,   620,   969,  1582,  1427,
    7869,   970,  5166, -1142,  1928, -1142, -1142,    77,  7890,   586,
    1599,   586,  1601,   586,  1602, -1142, -1142, -1142, -1142,   586,
    1604,  4004,  1605, -1142,    77, -1142,  1450,  1608,   973,  3343,
     976,   839, -1142,  1456,   849, -1142,  1457,   881, -1142,  1459,
     906, -1142,   980, -1142,   983, -1142,  1460,  2765, -1142,   831,
   -1142,   504, -1142,  1609,   586,  1611,   586,  1617,   586, -1142,
    1618,    77,  1639,    77,   986,  3956, -1142, -1142,   924, -1142,
     961, -1142,   995, -1142, -1142, -1142,   987, -1142,  1640,   504,
    1641,  1642,  1643,    77,  1644, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1142, -1142, -1142, -1142,   717, -1142, -1142, -1142, -1142,   297,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142,  -290,    -3, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142,  -105, -1142,   715,  1668, -1142, -1142,
   -1142, -1142,    -1,  -408,  -207, -1142, -1142, -1142, -1142, -1142,
   -1142,  1671, -1142, -1142, -1142, -1142, -1142, -1142, -1142, -1142,
   -1142, -1142, -1142, -1142, -1142,  -796,  -785, -1142, -1142,  1278,
   -1142, -1142, -1142, -1142, -1142, -1142, -1142,    -2, -1142,    46,
   -1142, -1141,   611,   -92,   855,   -75,  -750,   609, -1142,  -303,
      -6,   232
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     155,  1242,    81,   152,   153,   171,   427,   665,     4,   274,
     636,   637,  1087,   666,   789,   702,   342,   226,   443,   227,
     223,   540,   542,   543,   544,   545,   176,   254,   549,   550,
     551,   938,   171,   780,   176,   157,   265,   267,   453,   929,
     997,     5,   160,  1409,  1080,   999,   416,   417,   271,   555,
     162,   215,   559,   439,   158,   440,   257,   893,   156,   484,
    1004,   486,  1124,   846,  1125,   228,   159,  1002,   202,   203,
     144,   145,   847,   270,   416,   417,   163,   899,   204,   848,
     849,   539,   280,   850,   851,   205,   206,   208,   554,   214,
     164,   418,   281,   379,   396,   397,   398,   468,   384,   216,
     144,   145,   388,   217,   416,   417,   416,   417,   703,   704,
     705,   706,   219,   218,   220,   123,   124,   125,   126,   343,
     344,   419,  1326,   129,   989,   165,   167,   435,   436,   998,
     416,   417,   224,   168,  1000,   197,  1117,  1118,   198,   334,
     335,   336,   930,   931,   338,   341,   166,   429,  1340,   347,
     790,   416,   417,  1001,   180,   370,   172,   144,   145,   373,
    1158,  1159,   275,   173,   276,   375,   377,   380,   381,   277,
     383,   377,   385,   386,   707,   377,   389,   390,   225,   169,
     790,   430,   167,   172,   177,   255,  1071,   181,   431,   784,
     785,   781,   786,   266,   268,   454,   408,   272,   161,  1410,
     132,   133,   414,   415,   273,   182,   441,   258,   170,   894,
     179,   415,   174,   137,   138,   139,   140,   787,   186,  1002,
     175,   187,   645,   188,   178,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   469,   365,   366,   463,
     465,   377,   282,   367,   283,   416,   417,   411,   412,   472,
     473,   474,  1233,   476,   179,   420,   479,   480,   184,   428,
     481,   631,   552,   770,   284,   556,   285,   774,   190,  1441,
     688,   191,   194,   492,   192,   195,   193,   196,   416,   417,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   185,  1181,   846,   587,   416,   417,   548,   589,
     588,   416,   417,   847,   590,   377,   189,   183,   377,   560,
     848,   849,   638,   199,   850,   851,  1504,  1126,   554,  1127,
     200,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   416,   417,   757,   201,
     660,   661,   662,   758,   463,   209,   144,   145,   221,   450,
     601,   451,  1128,   276,  1129,   606,   150,   676,   277,   846,
     611,   612,   613,   614,  1251,   222,   901,   619,   847,   416,
     417,   229,   624,   625,   626,   848,   849,   231,   763,   850,
     851,   416,   417,   764,  1138,   644,   230,   347,   347,   639,
     640,   641,   334,   335,   642,   416,   417,   985,   646,   647,
     648,   649,   650,   232,   416,   417,   655,   416,   417,   657,
     658,  1003,   352,   377,   377,   377,   663,   664,   592,   669,
    1237,   593,   671,  1297,   250,   286,   920,   287,   251,   921,
     377,   922,   634,   635,   252,   924,   679,   681,   416,   417,
     412,   416,   417,   137,   138,   139,   140,   253,   260,  1388,
     416,   417,   416,   417,  1299,   669,   948,  1301,   947,   698,
     700,   597,   701,   144,   145,   261,  1309,   558,  1311,   288,
     773,   289,  1347,   259,  1350,   949,  1353,   144,   145,   280,
     597,   262,   487,   792,   276,   794,   827,   828,   829,   277,
     263,  1329,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,  1057,   264,   279,   846,
     367,   597,   123,   124,   125,   126,  1258,   324,   847,  1252,
     129,  1259,   776,   834,   775,   848,   849,   777,   458,   850,
     851,   459,  1002,   325,   460,  1002,   461,   290,  1002,   291,
     326,   327,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   377,   328,   377,   795,
     367,   873,  1065,   874,   681,   799,   329,   878,   879,   880,
     881,   331,   292,  1432,   293,   884,   330,   294,   813,   295,
     296,   332,   297,   818,   826,   826,   826,   826,   825,   825,
     825,   825,   137,   138,   139,   140,   377,   132,   133,  1391,
     837,   838,   298,   346,   299,  1062,   841,   333,  1064,  1066,
     416,   417,   144,   145,   416,   417,   300,  1002,   301,   862,
     345,   351,   864,  1471,   368,  1474,  1312,  1477,   369,   846,
    1387,   371,   372,  1480,   377,   302,   377,   303,   847,   382,
     377,   377,   377,   377,   387,   848,   849,   836,   377,   850,
     851,   392,   488,   919,   842,   889,  1002,   891,   892,  1002,
     854,   304,  1002,   305,   393,  1002,   900,   306,  1508,   307,
    1510,   308,  1512,   309,   394,    39,    40,    41,    42,   941,
     942,   943,   944,    47,  1221,  1222,    50,   137,   138,   139,
     140,   395,   310,  1002,   311,  1002,   399,  1002,   416,   417,
     312,   404,   313,   909,   910,   405,   406,   144,   145,   416,
     417,   416,   417,   409,  1390,   416,   417,   911,   912,   913,
     914,   915,   916,   917,   421,  1393,   377,  1401,   539,   280,
     422,  1403,   350,   423,   923,   416,   417,   432,   926,   364,
     365,   366,   932,   314,   433,   315,   367,   597,  1186,   598,
     434,  1461,   377,   377,   377,   377,   945,   438,   316,   846,
     317,   391,   123,   124,   125,   126,   442,   318,   847,   319,
     129,   210,   444,   445,   211,   848,   849,   212,   407,   850,
     851,   410,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   320,   322,   321,   323,
     367,   597,   437,   603,    95,   269,   597,   755,   607,   756,
      99,   100,   101,   446,   952,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   447,   597,  1016,   678,
     448,   449,   900,   127,   128,   452,   455,   132,   133,  1394,
     696,  1025,   697,   489,   490,  1342,   597,   456,   769,   990,
     991,   992,   457,   475,   202,   203,   597,   470,   772,   846,
     471,   478,  1043,  1044,   204,   477,   144,   145,   847,   482,
     491,   213,   846,   899,   493,   848,   849,   483,   485,   850,
     851,   847,   846,   597,   367,   868,  1067,   494,   848,   849,
     561,   847,   850,   851,   496,  1072,  1146,   562,   848,   849,
     150,   563,   850,   851,   597,  1086,   869,   570,  1083,  1085,
     597,   564,   870,   131,   846,   362,   363,   364,   365,   366,
     134,   135,   136,   847,   367,   597,   958,   882,   959,   620,
     848,   849,   610,   621,   850,   851,   141,   142,   597,   846,
     983,   143,   615,  1119,  1120,  1121,   242,   622,   847,  1457,
     597,   149,  1019,  1131,  1133,   848,   849,   846,   616,   850,
     851,  1136,  1493,   597,   627,  1020,   847,   623,   597,   377,
    1021,   630,  1495,   848,   849,   651,   629,   850,   851,   597,
     597,  1022,  1023,   378,   597,   597,  1024,  1026,   378,  1154,
    1155,  1156,   378,  1073,   846,  1074,   597,  1162,  1075,   597,
    1164,  1076,   653,   847,  1497,  1170,   597,   654,  1077,  1137,
     848,   849,   656,   670,   850,   851,   597,   695,  1078,  1174,
    1167,  1211,  1168,  1212,  1175,   597,   686,  1246,   846,  1499,
    1264,   760,  1265,  1033,  1167,   759,  1310,   847,  1189,  1355,
     762,  1356,  1188,   672,   848,   849,  1190,  1520,   850,   851,
     761,   673,  1195,  1196,   674,   675,   464,  1198,   378,   597,
    1358,  1367,   689,  1167,  1204,  1372,  1375,  1378,  1376,  1379,
     766,  1167,  1216,  1382,  1214,   597,  1215,  1383,   597,   767,
    1402,   347,   347,  1264,  1521,  1438,   778,   597,  1232,  1460,
     597,  1167,  1462,  1466,  1489,  1191,  1490,   764,   377,  1492,
     768,   597,   377,  1500,  1501,  1247,  1502,  1167,  1523,  1518,
    1524,   779,   783,  1256,   793,   796,   797,  1255,  1522,   820,
     798,  1485,   801,  1260,  1261,   802,   771,   803,   805,   806,
    1223,   807,  1226,   808,  1229,   811,   810,   812,   822,  1318,
     835,   839,   840,   863,   876,  1275,  1240,   885,   886,  1243,
    1244,   887,   378,  1433,   888,   378,   895,   897,  1514,   904,
    1517,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,  1341,   905,  1294,   906,   367,
    1530,  1034,   908,   918,     7,     8,   925,   819,   927,   928,
     933,   464,   934,   937,   936,  1308,  1362,   463,   833,   940,
     946,   951,   963,   953,   956,   962,   967,  1316,   968,  1317,
     969,   970,   377,   973,   984,   974,   975,  1323,   976,   977,
     978,   979,  1327,   980,   565,    18,    19,   566,    21,    22,
     567,    24,   568,    26,   981,    27,   982,   993,    30,    31,
     994,    33,    34,    35,   995,   996,  1005,    38,   377,  1006,
    1011,  1007,   347,  1008,  1009,  1345,   586,  1348,  1012,  1351,
     378,   378,   378,  1013,  1014,  1017,  1018,   896,  1030,   377,
    1015,  1035,  1036,  1364,    56,    57,    58,   378,  1039,  1038,
    1040,  1041,  1370,  1371,   682,  1047,  1434,  1058,  1437,  1374,
     765,  1042,  1068,  1069,  1059,  1061,  1079,  1381,  1082,  1093,
    1096,  1385,  1089,  1346,  1097,  1349,  1100,  1352,  1088,  1094,
    1095,  1099,  1101,  1102,  1106,  1360,  1109,  1107,  1363,  1110,
    1111,  1112,  1116,  1122,  1123,  1130,  1134,  1170,  1135,  1142,
    1149,  1143,  1147,  1150,  1151,   659,   358,   359,   360,   361,
     362,   363,   364,   365,   366,  1420,  1482,  1152,  1424,   367,
    1157,  1428,  1160,  1161,  1153,  1431,  1176,  1177,  1179,   377,
    1182,   377,  1183,  1184,  1171,  1185,  1440,  1192,  1193,  1442,
    1194,  1448,  1197,   954,   955,  1199,   957,  1200,   960,   961,
    1201,  1202,   964,   965,  1205,  1210,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
    1213,  1224,  1469,   378,   367,   378,  1227,  1230,  1238,  1436,
    1234,   682,   800,  1241,  1245,  1263,  1266,  1267,  1282,   377,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,  1268,  1269,  1273,  1271,   367,  1272,
    1274,  1283,  1284,   378,  1285,  1506,  1286,  1505,  1287,  1288,
    1289,  1292,  1295,  1293,  1304,   935,  1027,  1028,  1029,  1296,
    1306,  1298,  1313,  1300,  1302,  1307,  1037,  1320,  1315,  1328,
    1321,  1334,  1335,  1526,  1336,  1330,  1337,  1046,  1338,  1339,
    1354,   378,  1361,   378,  1368,    95,   269,   378,   378,   378,
     378,    99,   100,   101,  1369,   378,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,  1373,  1384,  1396,
    1397,   966,  1400,  1405,   127,   128,  1412,  1092,  1413,  1415,
    1449,  1416,  1418,  1098,  1421,  1422,  1425,  1426,  1429,  1103,
    1104,  1105,  1435,  1430,  1451,  1108,  1453,  1455,  1463,  1464,
    1113,  1114,  1115,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,  1472,  1132,  1475,  1478,   367,
    1481,  1483,  1487,   378,  1488,  1507,  1141,  1509,  1494,  1496,
    1145,  1498,  1503,  1511,  1513,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   378,
     378,   378,   378,   367,   131,  1515,  1525,  1527,  1528,  1529,
    1531,   134,   135,   136,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,  1081,  1406,   141,   142,   367,
    1091,    80,   143,  1172,    88,  1173,   618,   242,  1178,  1470,
     339,     0,   149,     0,   340,     0,     0,     0,     0,     7,
       8,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1206,  1207,  1208,  1209,     0,     0,     0,     0,     0,   565,
      18,    19,   566,    21,    22,   567,    24,   568,    26,     0,
      27,     0,     0,    30,    31,  1010,    33,    34,    35,     0,
       0,     0,    38,  1046,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1248,     0,     0,     0,     0,     0,
       0,  1257,     0,     0,     0,     0,    95,   233,  1262,    56,
      57,    58,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   235,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,   237,     0,
       0,   238,     0,   239,     0,     0,     0,     0,     0,     0,
     693,     0,     0,   240,     0,  1305,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,     0,     0,     0,     0,     0,   378,     0,     0,     0,
       0,     0,     0,     0,  1046,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,  1063,   131,     0,     0,     0,     0,
    1046,     0,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1357,   424,  1239,
       0,     0,     0,   143,     0,     0,     0,     0,   426,     0,
       0,    95,   233,   149,     0,   205,   466,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   235,     0,     0,  1395,     0,     0,     0,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,   237,     0,     0,   238,     0,   239,     0,
       0,     0,     0,     0,     0,   378,     0,     0,   240,   378,
       0,     0,     0,     0,    39,    40,    41,    42,    43,     0,
       0,     0,    47,     0,     0,    50,     0,     0,     0,     0,
       0,  1046,     0,  1445,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,  1070,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   376,     0,     0,     0,   143,     0,
       0,     0,     0,   242,     0,     0,     0,     0,   149,     0,
       0,   466,     0,     0,   464,     0,     0,     0,  1046,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   378,
       0,     0,    95,    96,    97,     0,    98,     0,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,  1148,   378,     0,   123,   124,   125,
     126,   127,   128,     0,     0,   129,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   378,     0,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,    18,
      19,   566,    21,    22,   567,    24,   568,    26,     0,    27,
       0,     0,    30,    31,     0,    33,    34,    35,     0,     0,
       0,    38,     0,     0,     0,   130,     0,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,    56,    57,
      58,     0,     0,     0,   141,   142,   378,     0,   378,   143,
       0,   144,   145,     0,   146,     0,   147,     0,   148,   149,
       0,   150,     0,     0,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,   378,
       0,     0,     0,     0,     0,     0,    95,   233,   234,   694,
       0,     0,    99,   100,   101,     0,   378,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   235,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     7,     8,     0,     0,   236,     0,     0,   237,     0,
       0,   238,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,   565,    18,    19,   566,    21,    22,   567,    24,   568,
      26,     0,    27,     0,     0,    30,    31,     0,    33,    34,
      35,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,   134,   135,   136,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,     0,     0,     0,   141,   241,
       0,     0,     0,   143,     0,     0,     0,     0,   242,     0,
      95,   233,  1139,   149,     0,   243,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   235,     0,     0,     0,     0,     0,     0,   127,
     128,     0,   855,     0,     0,     7,     8,     0,     0,   236,
       0,     0,   237,     0,     0,   238,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,   565,    18,    19,   566,    21,
      22,   567,    24,   568,    26,     0,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,     0,   134,   135,   136,     0,
       0,     0,     0,     0,     0,    56,    57,    58,     0,     0,
       0,     0,   141,   241,     0,     0,     0,   143,     0,     0,
       0,     0,   242,     0,    95,   233,  1443,   149,     0,  1140,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   235,     0,     0,     0,
       0,     0,     0,   127,   128,     0,   890,     0,     0,     7,
       8,     0,     0,   236,     0,     0,   237,     0,     0,   238,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,   565,
      18,    19,   566,    21,    22,   567,    24,   568,    26,     0,
      27,     0,     0,    30,    31,     0,    33,    34,    35,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,     0,     0,    56,
      57,    58,     0,     0,     0,     0,   141,   241,     0,     0,
       0,   143,     0,     0,     0,     0,   242,     0,    95,   233,
       0,   149,     0,  1444,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     235,     0,     0,     0,     0,     0,     0,   127,   128,     0,
    1398,     0,     0,     7,     8,     0,     0,   236,     0,     0,
     237,     0,     0,   238,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,   565,    18,    19,   566,    21,    22,   567,
      24,   568,    26,     0,    27,     0,     0,    30,    31,     0,
      33,    34,    35,     0,     0,     0,    38,  1270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
       0,     0,     0,     0,   134,   135,   136,  1291,     0,     0,
       0,     0,     0,    56,    57,    58,     0,     0,     0,     0,
     141,   241,     0,     0,     0,   143,     0,     0,     0,     0,
     242,     0,    95,   233,     0,   149,     0,   243,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   235,     0,     0,     0,     0,     0,
       0,   127,   128,     0,  1458,     0,     0,     0,     0,     0,
       0,   236,     0,     0,   237,     0,     0,   238,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   131,  1319,     0,     0,   367,     0,     0,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   376,     0,     0,     0,   143,
       0,     0,     0,     0,   242,     0,    95,   233,     0,   149,
       0,   462,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   235,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,   237,     0,
       0,   238,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,  1404,     0,     0,     0,
     367,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,   134,   135,   136,  1456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   376,
       0,     0,     0,   143,     0,     0,     0,     0,   242,     0,
      95,   233,     0,   149,     0,   680,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   235,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,   237,     0,     0,   238,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,     0,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   131,
    1491,   468,     0,   367,     0,     0,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   241,     0,     0,     0,   143,     0,     0,
       0,     0,   242,     0,    95,   233,     0,   149,     0,  1144,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   235,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,   237,     0,     0,   238,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     596,   365,   366,     0,     0,     0,     0,   367,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   424,  1239,     0,     0,
       0,   143,     0,     0,     0,     0,   426,     0,    95,   269,
     280,   149,     0,   205,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,   123,   124,   125,   126,   127,   128,     0,
       0,   129,    95,   269,   280,     0,     0,     0,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   123,   124,   125,
     126,   127,   128,    95,   269,   129,     0,     0,     0,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,   131,   132,   133,
       0,     0,   127,   128,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,     0,     0,     0,   143,     0,     0,     0,     0,
     242,     0,     0,     0,     0,   149,     0,  1084,     0,     0,
       0,   131,   132,   133,     0,     0,     0,     0,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,     0,     0,     0,   143,
       0,     0,     0,     0,   242,     0,     0,     0,     0,   149,
       0,  1254,   131,     0,     0,     0,     0,     0,     0,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
     143,     0,     0,     0,     0,   242,     0,     0,   667,     0,
     149,     0,   668,    95,   269,  1446,     0,     0,     0,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,    95,   269,
       0,     0,   127,   128,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,    95,   269,     0,     0,   127,   128,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,     0,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
     143,     0,     0,     0,     0,   242,     0,   131,     0,     0,
     149,     0,  1447,     0,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,     0,  1519,     0,   143,     0,     0,     0,     0,
     242,     0,   131,     0,     0,   149,     0,   337,     0,   134,
     135,   136,     0,   468,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,   425,     0,     0,     0,
     143,     0,     0,     0,     0,   426,     0,    95,   233,     0,
     149,     0,   205,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   235,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,   237,
       0,     0,   238,     0,   239,     0,     0,     0,     0,     0,
       0,   468,     0,     0,   240,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     0,     0,    47,     0,
     690,    50,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,   788,
     367,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   469,   365,   366,     0,   131,     0,     0,   367,
       0,   883,     0,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     376,     0,     0,     0,   143,    95,   269,   280,     0,   242,
       0,    99,   100,   101,   149,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,  1032,     0,     0,
     123,   124,   125,   126,   127,   128,     0,     0,   129,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     596,   365,   366,     0,     0,     0,     0,   367,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,     0,     0,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,   131,   132,   133,   367,     0,     0,
       0,   134,   135,   136,   971,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,     0,
       0,     0,   143,     0,     0,     0,     0,   242,     0,     0,
       0,     0,   149,     0,     0,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
      -4,     1,     0,   367,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,    -4,    -4,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       6,    -4,    -4,     0,     0,     0,    -4,     0,     7,     8,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     9,    10,     0,    -4,    -4,    -4,    -4,     0,
      11,    12,     0,    13,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     7,     8,    52,    53,     0,
       0,     0,    54,     0,     0,     0,     0,    55,    56,    57,
      58,     0,     0,    59,     0,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
       0,    72,    73,    74,    75,   565,    18,    19,   566,    21,
      22,   567,    24,   568,    26,     0,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,     0,     0,    38,     0,
       0,     0,     0,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,     0,     0,    56,    57,    58,  1219,     0,
    1220,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,  1249,     0,  1250,     0,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,  1343,     0,  1344,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,   815,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,   858,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,   877,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,   902,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,   988,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,  1217,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,  1236,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,  1278,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,  1279,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,  1280,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,  1281,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,  1314,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,  1359,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,  1365,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,  1366,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,  1386,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,  1389,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,  1392,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,  1414,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,     0,  1417,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,     0,     0,  1450,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,  1452,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,  1454,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,  1467,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,   628,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,     0,     0,     0,
       0,     0,     0,  1290,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   677,     0,     0,     0,     0,   632,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,   591,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,   632,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,   633,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,   687,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,   735,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,   736,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,   749,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,   750,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,   751,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,   752,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,   753,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,   754,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,   843,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,   844,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,   845,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,   950,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,   986,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,   987,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,  1031,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,  1165,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,  1166,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,  1187,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,  1324,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
       0,     0,     0,  1325,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,  1331,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,  1408,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,  1411,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,   557,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,     0,     0,   692,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
     699,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,     0,     0,   714,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,   716,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,     0,     0,   718,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,   720,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,     0,     0,   722,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,   724,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,     0,
       0,   726,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,   728,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,     0,     0,   730,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
     732,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,     0,     0,   734,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,   738,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,     0,     0,   740,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,   742,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,     0,     0,   744,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,   746,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,     0,
       0,   748,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,   866,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,     0,     0,   867,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
     871,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,     0,     0,   872,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,     0,     0,   875,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,     0,     0,   898,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
       0,     0,  1049,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,     0,     0,  1051,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,     0,     0,  1053,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,     0,
       0,  1055,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,     0,     0,  1056,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,     0,     0,  1180,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,     0,     0,
    1303,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,   553,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,   595,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,   599,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   600,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,   602,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,   604,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,   605,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,   608,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,   609,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
     677,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,   683,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,   684,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,   685,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   691,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,   713,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,   715,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,   717,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,   719,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,   721,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
     723,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,   725,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,   727,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,   729,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   731,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,   733,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,   737,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,   739,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,   741,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,   743,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
     745,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,   747,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,   804,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,   809,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   814,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,   816,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,   817,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,   823,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,   830,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,   831,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
     832,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,   857,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,   859,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,   860,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,   861,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,   865,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367,     0,  1048,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,     0,     0,     0,     0,   367,     0,  1050,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   367,     0,  1052,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,     0,     0,     0,     0,   367,     0,  1054,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,     0,     0,     0,     0,   367,     0,
    1060,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,     0,     0,     0,     0,   367,
       0,  1218,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     0,     0,     0,     0,
     367,     0,  1235,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,     0,     0,     0,
       0,   367,     0,  1253,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,     0,     0,
       0,     0,   367,     0,  1407,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,     0,   367,     0,  1465,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
       0,     0,     0,     0,   367
};

static const yytype_int16 yycheck[] =
{
       6,  1142,     3,     6,     6,     4,   213,   156,     6,     4,
     418,   419,     6,   162,     6,     4,     4,     4,   225,     6,
       4,   324,   325,   326,   327,   328,     4,     4,   331,   332,
     333,   781,     4,     4,     4,    58,     5,     5,     5,     4,
       6,     0,     6,     6,     6,     6,   145,   146,     6,   339,
       6,     4,   342,     4,   155,     6,     4,     7,    13,   266,
     856,   268,   161,    73,   163,    52,   155,   852,   145,   146,
     152,   153,    82,    75,   145,   146,     6,   159,   155,    89,
      90,     4,     5,    93,    94,   162,    40,    41,     7,    43,
       6,   162,    98,   168,   186,   187,   188,     8,   173,    52,
     152,   153,   177,    56,   145,   146,   145,   146,    97,    98,
      99,   100,    58,    66,    60,    38,    39,    40,    41,   107,
     108,   162,  1263,    46,   163,     6,   155,   219,   220,    95,
     145,   146,   116,   162,    95,    55,     6,     7,    58,   141,
     142,   143,   107,   108,   146,   147,   157,   162,  1289,   150,
     142,   145,   146,   163,    62,   157,   155,   152,   153,   161,
       6,     7,   157,   162,   159,   167,   168,   169,   170,   164,
     172,   173,   174,   175,   163,   177,   178,   179,   162,   155,
     142,   155,   155,   155,   162,   162,   936,    58,   162,   162,
     162,   162,   162,   162,   162,   162,   198,   155,   162,   162,
     123,   124,   204,   205,   162,    58,   157,   155,   155,   159,
     155,   213,   155,   132,   133,   134,   135,   162,    55,  1004,
     155,    58,   429,    60,   155,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   241,
     242,   243,   155,   154,   157,   145,   146,   201,   202,   251,
     252,   253,   163,   255,   155,   209,   258,   259,    58,   213,
     262,   161,   337,   553,   155,   340,   157,   557,    52,  1410,
     477,    55,    55,   275,    58,    58,    60,    60,   145,   146,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,    58,  1073,    73,   156,   145,   146,   330,   156,
     161,   145,   146,    82,   161,   337,    60,     6,   340,   342,
      89,    90,   161,   155,    93,    94,  1487,   161,     7,   163,
      55,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   145,   146,   156,   162,
     445,   446,   447,   161,   376,   162,   152,   153,    58,   155,
     382,   157,   161,   159,   163,   387,   162,   462,   164,    73,
     392,   393,   394,   395,     8,    55,   699,   399,    82,   145,
     146,    55,   404,   405,   406,    89,    90,     4,   156,    93,
      94,   145,   146,   161,   163,   161,    58,   418,   419,   421,
     422,   423,   424,   425,   426,   145,   146,   161,   430,   431,
     432,   433,   434,     4,   145,   146,   438,   145,   146,   441,
     442,   161,     6,   445,   446,   447,   448,   449,   158,   451,
     161,   161,   454,   161,     4,   155,   759,   157,   155,   762,
     462,   764,   416,   417,   155,   768,   468,   469,   145,   146,
     424,   145,   146,   132,   133,   134,   135,   155,     6,   163,
     145,   146,   145,   146,   161,   487,   156,   161,   791,   491,
     493,   161,   494,   152,   153,     6,   161,     7,   161,   155,
     159,   157,  1298,   155,  1300,   156,  1302,   152,   153,     5,
     161,   157,   157,   588,   159,   590,   621,   622,   623,   164,
       4,  1271,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   156,     4,   162,    73,
     154,   161,    38,    39,    40,    41,   156,   155,    82,   163,
      46,   161,   558,   628,   557,    89,    90,   559,    52,    93,
      94,    55,  1347,   155,    58,  1350,    60,   155,  1353,   157,
     155,   155,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   588,   155,   590,   591,
     154,   666,     7,   668,   596,   597,   155,   672,   673,   674,
     675,   155,   155,  1399,   157,   680,     7,   155,   610,   157,
     155,   155,   157,   615,   620,   621,   622,   623,   620,   621,
     622,   623,   132,   133,   134,   135,   628,   123,   124,   163,
     632,   633,   155,     4,   157,   925,   638,   155,   928,   929,
     145,   146,   152,   153,   145,   146,   155,  1432,   157,   651,
       4,     6,   654,  1449,     6,  1451,   161,  1453,     6,    73,
     161,     5,     5,  1459,   666,   155,   668,   157,    82,   155,
     672,   673,   674,   675,   155,    89,    90,   631,   680,    93,
      94,   155,     6,   758,   638,   687,  1471,   689,   690,  1474,
     644,   155,  1477,   157,   162,  1480,   699,   155,  1494,   157,
    1496,   155,  1498,   157,   155,    76,    77,    78,    79,   784,
     785,   786,   787,    84,  1122,  1123,    87,   132,   133,   134,
     135,   155,   155,  1508,   157,  1510,   155,  1512,   145,   146,
     155,   155,   157,   735,   736,   155,   155,   152,   153,   145,
     146,   145,   146,     4,   161,   145,   146,   749,   750,   751,
     752,   753,   754,   755,   162,   161,   758,   161,     4,     5,
     162,   161,   151,   162,   766,   145,   146,   155,   770,   147,
     148,   149,   774,   155,   155,   157,   154,   161,  1081,   163,
     155,   161,   784,   785,   786,   787,   788,   155,   155,    73,
     157,   180,    38,    39,    40,    41,   157,   155,    82,   157,
      46,    52,     6,   162,    55,    89,    90,    58,   197,    93,
      94,   200,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   155,   155,   157,   157,
     154,   161,   221,   163,     3,     4,   161,   157,   163,   159,
       9,    10,    11,   162,   798,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   162,   161,   870,   163,
     157,   157,   875,    42,    43,   157,     5,   123,   124,   163,
     161,   883,   163,   272,   273,  1293,   161,     5,   163,   843,
     844,   845,     5,   159,   145,   146,   161,     6,   163,    73,
       6,   110,   904,   905,   155,   162,   152,   153,    82,     6,
     157,   162,    73,   159,     4,    89,    90,     6,     6,    93,
      94,    82,    73,   161,   154,   163,   929,   162,    89,    90,
     159,    82,    93,    94,     6,   937,  1011,     7,    89,    90,
     162,   157,    93,    94,   161,   951,   163,     6,   950,   951,
     161,   163,   163,   122,    73,   145,   146,   147,   148,   149,
     129,   130,   131,    82,   154,   161,    58,   163,    60,   155,
      89,    90,     7,   155,    93,    94,   145,   146,   161,    73,
     163,   150,     7,   985,   986,   987,   155,   155,    82,   163,
     161,   160,   163,   995,   996,    89,    90,    73,     7,    93,
      94,  1003,   163,   161,     7,   163,    82,   155,   161,  1011,
     163,     6,   163,    89,    90,     7,   156,    93,    94,   161,
     161,   163,   163,   168,   161,   161,   163,   163,   173,  1031,
    1032,  1033,   177,   161,    73,   163,   161,  1040,   163,   161,
    1042,   163,     6,    82,   163,  1047,   161,     7,   163,  1003,
      89,    90,     6,     4,    93,    94,   161,   156,   163,  1065,
     161,     4,   163,     6,  1066,   161,   107,   163,    73,   163,
     161,   156,   163,     8,   161,   161,   163,    82,  1084,   161,
     161,   163,  1084,   162,    89,    90,  1088,   163,    93,    94,
     156,   162,  1094,  1095,   162,   162,   241,  1099,   243,   161,
    1307,   163,   162,   161,  1106,   163,   161,   161,   163,   163,
     161,   161,  1118,   163,  1116,   161,  1118,   163,   161,   156,
     163,  1122,  1123,   161,   163,   163,     6,   161,  1130,   163,
     161,   161,   163,   163,   161,  1089,   163,   161,  1140,   163,
     161,   161,  1144,   163,   161,  1147,   163,   161,   161,   163,
     163,     4,   158,  1159,     6,     6,     4,  1159,   163,     4,
       7,  1464,   110,  1165,  1166,     7,   555,     7,     7,   110,
    1124,     7,  1126,     7,  1128,     7,   110,     7,     6,  1254,
     159,   163,   163,     6,   158,  1187,  1140,     7,     7,  1143,
    1144,     7,   337,  1400,   159,   340,   162,     6,  1501,   155,
    1503,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,  1290,   155,  1219,   162,   154,
    1523,   156,     6,     4,    12,    13,   156,   616,     6,   158,
       6,   376,     6,   157,     7,  1237,  1311,  1239,   627,     6,
     142,     7,    60,    58,     7,     7,     7,  1249,     7,  1251,
       7,     7,  1254,     6,     4,     7,   156,  1259,   156,   156,
     156,     7,  1264,     7,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     7,    63,     6,     4,    66,    67,
       6,    69,    70,    71,   162,   155,     7,    75,  1290,     6,
     162,     7,  1293,     7,     7,  1297,     6,  1299,     6,  1301,
     445,   446,   447,     6,     6,     6,     6,   696,     4,  1311,
      58,     4,     4,  1315,   102,   103,   104,   462,     6,   163,
       4,     6,  1324,  1325,   469,   162,  1401,   156,  1403,  1331,
       6,   155,   159,     7,   156,   156,     6,  1339,     6,     6,
       6,  1343,    66,  1297,     6,  1299,     6,  1301,   162,   162,
     162,   162,     6,     5,     4,  1309,     7,     6,  1312,     7,
       7,     7,     7,   162,   162,   157,     6,  1369,     6,   162,
     156,   162,   162,   158,     6,   163,   141,   142,   143,   144,
     145,   146,   147,   148,   149,  1387,  1461,     6,  1390,   154,
       6,  1393,   161,     6,   106,  1397,     6,     4,     6,  1401,
       6,  1403,     6,     6,   159,     6,  1408,     6,     6,  1411,
       6,  1413,     6,   802,   803,     5,   805,     6,   807,   808,
       6,   110,   811,   812,     6,     6,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       6,     6,  1444,   588,   154,   590,     6,     6,     6,  1403,
     161,   596,   597,     6,     6,   162,     4,     6,     5,  1461,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     6,     6,   159,     7,   154,     6,
       6,    56,     6,   628,     6,  1491,     6,  1489,     6,     6,
     162,     6,   163,   162,     6,     6,   885,   886,   887,   163,
       7,   162,     6,   162,   162,   162,   895,     6,   105,     6,
     163,     6,     6,  1519,     6,   108,     6,   906,     6,   162,
       6,   666,     6,   668,     6,     3,     4,   672,   673,   674,
     675,     9,    10,    11,   162,   680,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,   163,     6,
      73,     6,   162,     6,    42,    43,     4,   956,     4,     6,
     162,     6,     6,   962,     6,     6,     6,     6,     6,   968,
     969,   970,     6,   163,   162,   974,   162,     6,     6,   162,
     979,   980,   981,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     6,   995,     6,     6,   154,
       6,     6,   162,   758,     6,     6,  1005,     6,   162,   162,
    1009,   162,   162,     6,     6,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   784,
     785,   786,   787,   154,   122,     6,     6,     6,     6,     6,
       6,   129,   130,   131,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   948,  1369,   145,   146,   154,
     955,     3,   150,  1062,     3,  1064,   398,   155,  1069,  1447,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    12,
      13,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,    -1,    -1,    66,    67,     6,    69,    70,    71,    -1,
      -1,    -1,    75,  1142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1153,    -1,    -1,    -1,    -1,    -1,
      -1,  1160,    -1,    -1,    -1,    -1,     3,     4,  1167,   102,
     103,   104,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    70,    -1,  1234,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,  1011,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1263,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,     6,   122,    -1,    -1,    -1,    -1,
    1289,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1306,   145,   146,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,
      -1,     3,     4,   160,    -1,   162,   163,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,  1355,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,  1140,    -1,    -1,    70,  1144,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,  1410,    -1,  1412,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     6,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,    -1,
      -1,   163,    -1,    -1,  1239,    -1,    -1,    -1,  1487,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     6,  1290,    -1,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,  1311,    -1,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,   102,   103,
     104,    -1,    -1,    -1,   145,   146,  1401,    -1,  1403,   150,
      -1,   152,   153,    -1,   155,    -1,   157,    -1,   159,   160,
      -1,   162,    -1,    -1,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,  1444,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,   163,
      -1,    -1,     9,    10,    11,    -1,  1461,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    52,    -1,    -1,    55,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,    -1,    -1,   145,   146,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,
       3,     4,     5,   160,    -1,   162,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,   163,    -1,    -1,    12,    13,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
      -1,    -1,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   155,    -1,     3,     4,     5,   160,    -1,   162,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,   163,    -1,    -1,    12,
      13,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,    -1,    -1,    66,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,    -1,    -1,    -1,    -1,   145,   146,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,   155,    -1,     3,     4,
      -1,   160,    -1,   162,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
     163,    -1,    -1,    12,    13,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    63,    -1,    -1,    66,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    75,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,     6,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,    -1,    -1,    -1,    -1,
     145,   146,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
     155,    -1,     3,     4,    -1,   160,    -1,   162,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   122,     6,    -1,    -1,   154,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,   155,    -1,     3,     4,    -1,   160,
      -1,   162,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     6,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,
       3,     4,    -1,   160,    -1,   162,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   122,
       7,     8,    -1,   154,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   155,    -1,     3,     4,    -1,   160,    -1,   162,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,   155,    -1,     3,     4,
       5,   160,    -1,   162,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,     3,     4,    46,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,   122,   123,   124,
      -1,    -1,    42,    43,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,   160,    -1,   162,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
      -1,   162,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,   155,    -1,    -1,   158,    -1,
     160,    -1,   162,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,     3,     4,
      -1,    -1,    42,    43,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,     3,     4,    -1,    -1,    42,    43,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,   155,    -1,   122,    -1,    -1,
     160,    -1,   162,    -1,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,    -1,     7,    -1,   150,    -1,    -1,    -1,    -1,
     155,    -1,   122,    -1,    -1,   160,    -1,   162,    -1,   129,
     130,   131,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,   155,    -1,     3,     4,    -1,
     160,    -1,   162,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,
       8,    87,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,     8,
     154,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   122,    -1,    -1,   154,
      -1,     8,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,    -1,    -1,    -1,   150,     3,     4,     5,    -1,   155,
      -1,     9,    10,    11,   160,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     8,    -1,    -1,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,   122,   123,   124,   154,    -1,    -1,
      -1,   129,   130,   131,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,   160,    -1,    -1,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
       0,     1,    -1,   154,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
       4,    91,    92,    -1,    -1,    -1,    96,    -1,    12,    13,
      -1,   101,   102,   103,   104,    -1,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    36,    37,    -1,   125,   126,   127,   128,    -1,
      44,    45,    -1,    47,    48,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    12,    13,    91,    92,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,    -1,    -1,   107,    -1,   109,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,   126,   127,   128,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    63,    -1,    -1,    66,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,   102,   103,   104,   161,    -1,
     163,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,   163,    -1,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,   163,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,   158,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
     158,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,   158,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,   158,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,   158,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,   158,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
     158,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,   158,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,   158,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,   158,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,   158,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
     158,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,   158,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,   158,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    -1,   158,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
      -1,   158,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,    -1,    -1,   158,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,   158,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
     158,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
     156,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
     156,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
     156,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
     156,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,    -1,
     156,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,    -1,   156,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   166,   167,     6,     0,     4,    12,    13,    36,
      37,    44,    45,    47,    48,    49,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    91,    92,    96,   101,   102,   103,   104,   107,
     109,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   125,   126,   127,   128,   168,   170,   171,   189,
     202,   207,   210,   211,   212,   213,   214,   215,   216,   236,
     237,   238,   239,   240,   241,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    39,    40,    41,    42,    43,    46,
     116,   122,   123,   124,   129,   130,   131,   132,   133,   134,
     135,   145,   146,   150,   152,   153,   155,   157,   159,   160,
     162,   187,   188,   242,   243,   255,    13,    58,   155,   155,
       6,   162,     6,     6,     6,     6,   157,   155,   162,   155,
     155,     4,   155,   162,   155,   155,     4,   162,   155,   155,
      62,    58,    58,     6,    58,    58,    55,    58,    60,    60,
      52,    55,    58,    60,    55,    58,    60,    55,    58,   155,
      55,   162,   145,   146,   155,   162,   244,   245,   244,   162,
      52,    55,    58,   162,   244,     4,    52,    56,    66,    58,
      60,    58,    55,     4,   116,   162,     4,     6,    52,    55,
      58,     4,     4,     4,     5,    35,    52,    55,    58,    60,
      70,   146,   155,   162,   207,   216,   242,   247,   248,   249,
       4,   155,   155,   155,     4,   162,   251,     4,   155,   155,
       6,     6,   157,     4,     4,     5,   162,     5,   162,     4,
     242,     6,   155,   162,     4,   157,   159,   164,   188,   162,
       5,   255,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   155,   155,   155,   155,   155,
       7,   155,   155,   155,   242,   242,   242,   162,   242,   158,
     162,   242,     4,   107,   108,     4,     4,   207,   208,   209,
     247,     6,     6,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   154,     6,     6,
     242,     5,     5,   242,   191,   242,   146,   242,   249,   250,
     242,   242,   155,   242,   250,   242,   242,   155,   250,   242,
     242,   247,   155,   162,   155,   155,   248,   248,   248,   155,
     203,   204,   205,   206,   155,   155,   155,   247,   242,     4,
     247,   244,   244,   244,   242,   242,   145,   146,   162,   162,
     244,   162,   162,   162,   145,   146,   155,   209,   244,   162,
     155,   162,   155,   155,   155,   248,   248,   247,   155,     4,
       6,   157,   157,   209,     6,   162,   162,   162,   157,   157,
     155,   157,   157,     5,   162,     5,     5,     5,    52,    55,
      58,    60,   162,   242,   249,   242,   163,   250,     8,   147,
       6,     6,   242,   242,   242,   159,   242,   162,   110,   242,
     242,   242,     6,     6,   209,     6,   209,   157,     6,   247,
     247,   157,   242,     4,   162,   172,     6,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,     4,
     254,   255,   254,   254,   254,   254,   254,   256,   242,   254,
     254,   254,   250,   156,     7,   187,   250,   158,     7,   187,
     188,   159,     7,   157,   163,    52,    55,    58,    60,   202,
       6,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,     6,   156,   161,   156,
     161,   161,   158,   161,   190,   156,   147,   161,   163,   156,
     156,   242,   156,   163,   156,   156,   242,   163,   156,   156,
       7,   242,   242,   242,   242,     7,     7,   234,   234,   242,
     155,   155,   155,   155,   242,   242,   242,     7,   162,   156,
       6,   161,   161,   161,   244,   244,   208,   208,   161,   242,
     242,   242,   242,   220,   161,   209,   242,   242,   242,   242,
     242,     7,   235,     6,     7,   242,     6,   242,   242,   163,
     250,   250,   250,   242,   242,   156,   162,   158,   162,   242,
       4,   242,   162,   162,   162,   162,   250,   156,   163,   242,
     162,   242,   249,   156,   156,   156,   107,   161,   209,   162,
       8,   156,   158,   163,   163,   156,   161,   163,   242,   158,
     188,   242,     4,    97,    98,    99,   100,   163,   175,   179,
     182,   184,   185,   156,   158,   156,   158,   156,   158,   156,
     158,   156,   158,   156,   158,   156,   158,   156,   158,   156,
     158,   156,   158,   156,   158,   161,   161,   156,   158,   156,
     158,   156,   158,   156,   158,   156,   158,   156,   158,   161,
     161,   161,   161,   161,   161,   157,   159,   156,   161,   161,
     156,   156,   161,   156,   161,     6,   161,   156,   161,   163,
     187,   247,   163,   159,   187,   188,   255,   242,     6,     4,
       4,   162,   252,   158,   162,   162,   162,   162,     8,     6,
     142,   169,   250,     6,   250,   242,     6,     4,     7,   242,
     249,   110,     7,     7,   156,     7,   110,     7,     7,   156,
     110,     7,     7,   242,   156,   163,   156,   156,   242,   247,
       4,   233,     6,   156,   199,   242,   255,   199,   199,   199,
     156,   156,   156,   247,   250,   159,   244,   242,   242,   163,
     163,   242,   244,   161,   161,   161,    73,    82,    89,    90,
      93,    94,   230,   231,   244,   163,   217,   156,   163,   156,
     156,   156,   242,     6,   242,   156,   158,   158,   163,   163,
     163,   158,   158,   250,   250,   158,   158,   163,   250,   250,
     250,   250,   163,     8,   250,     7,     7,     7,   159,   242,
     163,   242,   242,     7,   159,   162,   247,     6,   158,   159,
     188,   254,   163,   176,   155,   155,   162,   186,     6,   242,
     242,   242,   242,   242,   242,   242,   242,   242,     4,   250,
     254,   254,   254,   242,   254,   156,   242,     6,   158,     4,
     107,   108,   242,     6,     6,     6,     7,   157,   251,   253,
       6,   250,   250,   250,   250,   242,   142,   254,   156,   156,
     161,     7,   244,    58,   247,   247,     7,   247,    58,    60,
     247,   247,     7,    60,   247,   247,     6,     7,     7,     7,
       7,    73,   232,     6,     7,   156,   156,   156,   156,     7,
       7,     7,     6,   163,     4,   161,   161,   161,   163,   163,
     244,   244,   244,     4,     6,   162,   155,     6,    95,     6,
      95,   163,   231,   161,   230,     7,     6,     7,     7,     7,
       6,   162,     6,     6,     6,    58,   242,     6,     6,   163,
     163,   163,   163,   163,   163,   242,   163,   247,   247,   247,
       4,   161,     8,     8,   156,     4,     4,   247,   163,     6,
       4,     6,   155,   242,   242,   246,   247,   162,   156,   158,
     156,   158,   156,   158,   156,   158,   158,   156,   156,   156,
     156,   156,   187,     6,   187,     7,   187,   188,   159,     7,
       6,   251,   242,   161,   163,   163,   163,   163,   163,     6,
       6,   169,     6,   242,   162,   242,   255,     6,   162,    66,
     201,   201,   247,     6,   162,   162,     6,     6,   247,   162,
       6,     6,     5,   247,   247,   247,     4,     6,   247,     7,
       7,     7,     7,   247,   247,   247,     7,     6,     7,   242,
     242,   242,   162,   162,   161,   163,   161,   163,   161,   163,
     157,   242,   247,   242,     6,     6,   242,   244,   163,     5,
     162,   247,   162,   162,   162,   247,   250,   162,     6,   156,
     158,     6,     6,   106,   242,   242,   242,     6,     6,     7,
     161,     6,   188,   173,   242,   161,   161,   161,   163,   174,
     242,   159,   247,   247,   255,   242,     6,     4,   252,     6,
     158,   251,     6,     6,     6,     6,   254,   161,   242,   255,
     242,   244,     6,     6,     6,   242,   242,     6,   242,     5,
       6,     6,   110,   200,   242,     6,   247,   247,   247,   247,
       6,     4,     6,     6,   242,   242,   255,   163,   156,   161,
     163,   208,   208,   244,     6,   221,   244,     6,   222,   244,
       6,   223,   242,   163,   161,   156,   163,   161,     6,   146,
     244,     6,   246,   244,   244,     6,   163,   242,   247,   161,
     163,     8,   163,   156,   162,   242,   255,   247,   156,   161,
     242,   242,   247,   162,   161,   163,     4,     6,     6,     6,
       6,     7,     6,   159,     6,   242,   192,   193,   163,   163,
     163,   163,     5,    56,     6,     6,     6,     6,     6,   162,
     162,     6,     6,   162,   242,   163,   163,   161,   162,   161,
     162,   161,   162,   158,     6,   247,     7,   162,   242,   161,
     163,   161,   161,     6,   163,   105,   242,   242,   250,     6,
       6,   163,   177,   242,   161,   161,   246,   242,     6,   251,
     108,   161,   195,   197,     6,     6,     6,     6,     6,   162,
     246,   250,   208,   161,   163,   242,   244,   230,   242,   244,
     230,   242,   244,   230,     6,   161,   163,   247,   209,   163,
     244,     6,   250,   244,   242,   163,   163,   163,     6,   162,
     242,   242,   163,     6,   242,   161,   163,   196,   161,   163,
     198,   242,   163,   163,   163,   242,   163,   161,   163,   163,
     161,   163,   163,   161,   163,   247,     6,    73,   163,   218,
     162,   161,   163,   161,     6,     6,   174,   156,   161,     6,
     162,   161,     4,     4,   163,     6,     6,   163,     6,   224,
     242,     6,     6,   225,   242,     6,     6,   226,   242,     6,
     163,   242,   230,   209,   250,     6,   244,   250,   163,   180,
     242,   246,   242,     5,   162,   247,     5,   162,   242,   162,
     163,   162,   163,   162,   163,     6,     6,   163,   163,   219,
     163,   161,   163,     6,   162,   156,   163,   163,   194,   242,
     256,   230,     6,   227,   230,     6,   228,   230,     6,   229,
     230,     6,   250,     6,   178,   254,   183,   162,     6,   161,
     163,     7,   163,   163,   162,   163,   162,   163,   162,   163,
     163,   161,   163,   162,   246,   242,   255,     6,   230,     6,
     230,     6,   230,     6,   254,     6,   181,   254,   163,     7,
     163,   163,   163,   161,   163,     6,   255,     6,     6,     6,
     254,     6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1464 of yacc.c  */
#line 167 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 194 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 199 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 203 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 210 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 215 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 220 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
      FILE *fp = fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[(3) - (7)].c));
	fclose(fp);
      }
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 234 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 247 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 260 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(8) - (9)].c));
	FILE *fp = fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
      List_Delete((yyvsp[(5) - (9)].l));
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 288 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[(2) - (6)].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 302 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 313 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 327 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 341 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 343 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 348 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 350 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 355 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strncmp((yyvsp[(1) - (1)].c), "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 459 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 469 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 478 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 485 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 495 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 513 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 520 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 530 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 538 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 548 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
	(ViewData->NbSY || ViewData->NbVY) ? TYPE_PYR :
	(ViewData->NbSI || ViewData->NbVI) ? TYPE_PRI :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (8)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (8)].l)));
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 567 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(9) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(12) - (14)].l)));
#endif
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 586 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 592 "Gmsh.y"
    {
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 599 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 600 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 601 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 602 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 603 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 607 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 608 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 617 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c)) && (yyvsp[(2) - (4)].i) && List_Nbr((yyvsp[(3) - (4)].l)) == 1){
        yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if(!(yyvsp[(2) - (4)].i)) s.list = (List_Nbr((yyvsp[(3) - (4)].l)) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr((yyvsp[(3) - (4)].l)) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", (yyvsp[(1) - (4)].c));
          }
          else{
            double d;
            List_Read((yyvsp[(3) - (4)].l), 0, &d);
            if(s.value.empty()){
              if((yyvsp[(2) - (4)].i)) yymsg(1, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
              s.value.resize(1, 0.);
            }
            switch((yyvsp[(2) - (4)].i)){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), d);
              break;
            }
          }
        }
        else{ // list of expressions
          switch((yyvsp[(2) - (4)].i)){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
              std::vector<double>::iterator it = std::find(s.value.begin(),
                                                           s.value.end(), d);
              if(it != s.value.end()) s.value.erase(it);
            }
            break;
          default:
            yymsg(0, "Operators *= and /= not available for lists");
            break;
          }
        }
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 679 "Gmsh.y"
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
      s.list = true;
      double d;
      switch((yyvsp[(4) - (6)].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 709 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 744 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
          s.list = true;
	  s.value.resize(index + 1, 0.);
	  s.value[index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (7)].c)]);
        if(s.list){
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch((yyvsp[(5) - (7)].i)){
          case 0 : s.value[index] = (yyvsp[(6) - (7)].d); break;
          case 1 : s.value[index] += (yyvsp[(6) - (7)].d); break;
          case 2 : s.value[index] -= (yyvsp[(6) - (7)].d); break;
          case 3 : s.value[index] *= (yyvsp[(6) - (7)].d); break;
          case 4 :
            if((yyvsp[(6) - (7)].d)) s.value[index] /= (yyvsp[(6) - (7)].d);
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
            break;
          }
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (7)].c));
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 778 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 826 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
            gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
            s.list = true;
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      s.value.resize(index + 1, 0.);
	      s.value[index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
          gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (9)].c)]);
          if(s.list){
            for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
              int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
              double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
              if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
              switch((yyvsp[(7) - (9)].i)){
              case 0 : s.value[index] = d; break;
              case 1 : s.value[index] += d; break;
              case 2 : s.value[index] -= d; break;
              case 3 : s.value[index] *= d; break;
              case 4 :
                if((yyvsp[(8) - (9)].l)) s.value[index] /= d;
                else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
                break;
              }
            }
          }
          else
            yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (9)].c));
        }
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 873 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else if(!s.list)
          s.value[0] += (yyvsp[(2) - (3)].i);
        else
          yymsg(0, "Variable '%s' is a list", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 888 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
        if(s.list){
          int index = (int)(yyvsp[(3) - (6)].d);
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          s.value[index] += (yyvsp[(5) - (6)].i);
        }
        else
          yymsg(0, "Variable '%s' is not a list", (yyvsp[(1) - (6)].c));
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 904 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 913 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 919 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 928 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d)){
	switch((yyvsp[(4) - (6)].i)){
	case 0 : d = (yyvsp[(5) - (6)].d); break;
	case 1 : d += (yyvsp[(5) - (6)].d); break;
	case 2 : d -= (yyvsp[(5) - (6)].d); break;
	case 3 : d *= (yyvsp[(5) - (6)].d); break;
	case 4 :
	  if((yyvsp[(5) - (6)].d)) d /= (yyvsp[(5) - (6)].d);
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d);
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 946 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d)){
	switch((yyvsp[(7) - (9)].i)){
	case 0 : d = (yyvsp[(8) - (9)].d); break;
	case 1 : d += (yyvsp[(8) - (9)].d); break;
	case 2 : d -= (yyvsp[(8) - (9)].d); break;
	case 3 : d *= (yyvsp[(8) - (9)].d); break;
	case 4 :
	  if((yyvsp[(8) - (9)].d)) d /= (yyvsp[(8) - (9)].d);
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d);
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 964 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 973 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 985 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 990 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 998 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[(5) - (6)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(5) - (6)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1018 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (9)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (9)].d));
      else{
	ct->size = List_Nbr((yyvsp[(8) - (9)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[(3) - (9)].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(8) - (9)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1041 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1052 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1060 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->numericalValue((yyvsp[(8) - (9)].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1082 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string((yyvsp[(8) - (9)].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1105 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  std::list<int> vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
          option->list(vl);
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
#endif
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1131 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (7)].d));
      if(field){
        FieldCallback *callback = field->callbacks[(yyvsp[(6) - (7)].c)];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              (yyvsp[(6) - (7)].c), (int)(yyvsp[(3) - (7)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (7)].d));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1152 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1164 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1182 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1193 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1204 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1206 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
    ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1216 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      floatOptions.clear(); charOptions.clear();
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1227 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1229 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1242 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1248 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1260 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
        double v;
        List_Read((yyvsp[(3) - (3)].l), i, &v);
        floatOptions[key].push_back(v);
      }
      Free((yyvsp[(2) - (3)].c));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1271 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[(4) - (5)].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[(4) - (5)].l), i))->s);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1286 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1302 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1310 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (5)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        char *s;
        List_Read((yyvsp[(4) - (5)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(2) - (5)].c));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1338 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1342 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1352 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1356 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v);
      }
    ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1368 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1372 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1382 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
      }
      else{
	double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
	double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
	double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
	double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
	if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
	Vertex *v;
	if(!myGmshSurface)
	  v = Create_Vertex(num, x, y, z, lc, 1.0);
	else
	  v = Create_Vertex(num, x, y, myGmshSurface, lc);
	Tree_Add(GModel::current()->getGEOInternals()->Points, &v);
	AddToTemporaryBoundingBox(v->Pos.X, v->Pos.Y, v->Pos.Z);
      }
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1405 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 1409 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1425 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v)
	  v->lc = (yyvsp[(5) - (6)].d);
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv)
	    gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
	}
      }
      List_Delete((yyvsp[(3) - (6)].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1447 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1465 "Gmsh.y"
    {
      for (int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int) fabs(dnum);
	Curve *c = FindCurve(num);
	if (c){
	  c->degenerated = true;
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(num);
	  if (!ge){
	    yymsg(0, "Curve %d does not exist", num);
	  }
	  else{
	    ge->setTooSmall(true);
	  }
	}
      }
    ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 1486 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1504 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 1534 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (8)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          c->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          c->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          c->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[(7) - (8)].v)[0] || (yyvsp[(7) - (8)].v)[1] || (yyvsp[(7) - (8)].v)[2]){
          rc->Circle.n[0] = (yyvsp[(7) - (8)].v)[0];
          rc->Circle.n[1] = (yyvsp[(7) - (8)].v)[1];
          rc->Circle.n[2] = (yyvsp[(7) - (8)].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 1564 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1582 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1600 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      if(List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1 != List_Nbr((yyvsp[(8) - (11)].l))){
	yymsg(0, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[(3) - (11)].d), List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(6) - (11)].l)), (int)(yyvsp[(10) - (11)].d), List_Nbr((yyvsp[(6) - (11)].l)) + (int)(yyvsp[(10) - (11)].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(0, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (11)].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[(10) - (11)].d), temp, (yyvsp[(8) - (11)].l),
				  -1, -1, 0., 1.);
	  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1626 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindEdgeLoop(num)){
	yymsg(0, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1644 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        Curve *c = Create_Curve(num, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          c->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1662 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1666 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1685 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1703 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (9)].d), type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[(7) - (9)].l), 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d));
	if(!el){
	  yymsg(0, "Unknown line loop %d", (int)d);
	}
	else{
	  int j = List_Nbr(el->Curves);
	  if(j == 4){
	    type = MSH_SURF_REGL;
	  }
	  else if(j == 3){
	    type = MSH_SURF_TRIC;
	  }
	  else{
	    yymsg(0, "Wrong definition of Ruled Surface %d: "
		  "%d borders instead of 3 or 4", num, j);
	    type = MSH_SURF_PLAN;
	  }
	  Surface *s = Create_Surface(num, type);
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  s->InSphereCenter = (yyvsp[(8) - (9)].l);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1742 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1748 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1754 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1761 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(0, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(0, "Sphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(0, "Sphere %d : unknown point %d", num, (int)p2);
	if(v1 && v2)
	  myGmshSurface = gmshSphere::NewSphere
	    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		  (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		  (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1786 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if (List_Nbr((yyvsp[(6) - (7)].l)) != 2){
	yymsg(0, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[(6) - (7)].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[(6) - (7)].l), 0, &p1);
	List_Read((yyvsp[(6) - (7)].l), 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p2);
	if(v1 && v2)
	  myGmshSurface = gmshPolarSphere::NewPolarSphere
	    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		  (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		  (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1811 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1828 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	}
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1846 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (12)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
        Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (12)].l)); i++)
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (12)].l), i));
	for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
          if(i > 3){
            yymsg(0, "Too many boundary specifiers in compound surface");
            break;
          }
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i);
          for (int j = 0; j < List_Nbr(l); j++){
            s->compoundBoundary[i].push_back((int)*(double*)List_Pointer(l, j));
	  }
	}
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (12)].l));
      for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
      List_Delete((yyvsp[(10) - (12)].l));
      Free((yyvsp[(8) - (12)].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1876 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1880 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1900 "Gmsh.y"
    {
      yymsg(0, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1918 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(6) - (7)].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1935 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++)
          v->compound.push_back((int)*(double*)List_Pointer((yyvsp[(7) - (8)].l), i));
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1951 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1955 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(8) - (9)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(8) - (9)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1977 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1982 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1987 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1992 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1997 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2002 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[(1) - (4)].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "Boundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), false);
      }
      else if(!strcmp((yyvsp[(1) - (4)].c), "CombinedBoundary")){
        BoundaryShapes((yyvsp[(3) - (4)].l), (yyval.l), true);
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[(1) - (4)].c));
      }
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 2025 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2031 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 2041 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2042 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2047 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2051 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2055 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = MSH_POINT;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GVertex *gv = GModel::current()->getVertexByTag(std::abs(TheShape.Num));
	  if(gv){
	    TheShape.Type = MSH_POINT_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(1, "Unknown point %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 2078 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(std::abs(TheShape.Num));
	if(c){
	  TheShape.Type = c->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(std::abs(TheShape.Num));
	  if(ge){
	    TheShape.Type = MSH_SEGM_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(1, "Unknown curve %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 2101 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(std::abs(TheShape.Num));
	if(s){
	  TheShape.Type = s->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GFace *gf = GModel::current()->getFaceByTag(std::abs(TheShape.Num));
	  if(gf){
	    TheShape.Type = MSH_SURF_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(1, "Unknown surface %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2124 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = v->Typ;
	  List_Add((yyval.l), &TheShape);
	}
	else{
	  GRegion *gr = GModel::current()->getRegionByTag(std::abs(TheShape.Num));
	  if(gr){
	    TheShape.Type = MSH_VOLUME_FROM_GMODEL;
	    List_Add((yyval.l), &TheShape);
	  }
	  else
	    yymsg(1, "Unknown volume %d", TheShape.Num);
	}
      }
    ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2152 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(7) - (8)].l)) == 4){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[(7) - (8)].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
#endif
    ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2173 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      int t = (int)(yyvsp[(4) - (10)].d);
      if(FindLevelSet(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	//Msg::Info("nb = %d \n",List_Nbr($8) );
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    //Msg::Info("nb j = %d \n",List_Nbr(l) );
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
	 gLevelset *ls = new gLevelsetPoints(centers, t);
	 LevelSet *l = Create_LevelSet(ls->getTag(), ls);
	 Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
      }
#endif
    ;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 2197 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 0){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double n[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt, n, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
#endif
    ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2218 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(14) - (16)].l)) == 0){
        int t = (int)(yyvsp[(4) - (16)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt1[3] = {(yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2]};
          double pt2[3] = {(yyvsp[(10) - (16)].v)[0], (yyvsp[(10) - (16)].v)[1], (yyvsp[(10) - (16)].v)[2]};
          double pt3[3] = {(yyvsp[(12) - (16)].v)[0], (yyvsp[(12) - (16)].v)[1], (yyvsp[(12) - (16)].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (16)].d));
#endif
    ;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 2239 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[(10) - (12)].l)) == 1){
        int t = (int)(yyvsp[(4) - (12)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(10) - (12)].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (12)].d));
#endif
    ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2259 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Intersection")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Cut")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Crack")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Crack %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCrack(vl);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Reverse")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(7) - (8)].l), 0, &d);
          LevelSet *pl = FindLevelSet((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Levelset Reverse %d : unknown levelset %d", t, (int)d);
          else ls = new gLevelsetReverse(pl->ls);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[(2) - (8)].c), "PostView")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[(7) - (8)].l)) > 0){
            double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            LevelSet *l = Create_LevelSet(ls->getTag(), ls);
            Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (8)].d));
      Free((yyvsp[(2) - (8)].c));
#endif
    ;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 2371 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "MathEval")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[(7) - (8)].c), t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(7) - (8)].c));
#endif
    ;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 2390 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, false, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 2429 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cone") && List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 2){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Cylinder") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Ellipsoid") && List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[(2) - (14)].c), "Quadric") && List_Nbr((yyvsp[(12) - (14)].l)) == 5){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[(4) - (14)].d));
      Free((yyvsp[(2) - (14)].c));
#endif
    ;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 2537 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 2546 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2552 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[(2) - (6)].c));
#endif
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2567 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy();
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	GModel::current()->getGEOInternals()->reset_physicals();
	GModel::current()->deletePhysicalGroups();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count((yyvsp[(2) - (3)].c)))
	  gmsh_yysymbols.erase((yyvsp[(2) - (3)].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 2595 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (4)].c), "Empty") && !strcmp((yyvsp[(3) - (4)].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", (yyvsp[(2) - (4)].c), (yyvsp[(3) - (4)].c));
#endif
      Free((yyvsp[(2) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2612 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2626 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2632 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2638 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2647 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2661 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	Msg::StatusBar(true, "Reading '%s'...", tmp.c_str());
	// Warning: we explicitly ask ParseFile not to fclose() the included
        // file, in order to allow user functions definitions in these files.
        // The files will be closed in the next time OpenFile terminates. If
        // you need to include many many files and don't have functions in
        // the files, use "Merge" instead of "Include", as some OSes limit
        // the number of files a process can open simultaneously. (A better
        // solution would be to modify FunctionManager to reopen the files
        // instead of using the FILE pointer...)
	ParseFile(tmp, false, true);
	SetBoundingBox();
	Msg::StatusBar(true, "Done reading '%s'", tmp.c_str());
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Print")){
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall"))
	SystemCall((yyvsp[(2) - (3)].c), true);
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2706 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 2723 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 2738 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
	GModel::current()->importGEOInternals();
	GModel::current()->mesh((int)(yyvsp[(2) - (3)].d));
	CTX::instance()->lock = lock;
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2757 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
#endif
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2769 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 2793 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2797 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2802 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2809 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2815 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2820 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2826 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2830 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2834 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2839 "Gmsh.y"
    {
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete);
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2849 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2866 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2883 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2904 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2925 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        const char *name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name);
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name);
          }
        }
        else{
          LoopControlVariablesTab[ImbricatedLoop - 1][0] += step;
        }
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
        if((step > 0. && x0 <= x1) || (step < 0. && x0 >= x1)){
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2960 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2968 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2974 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2981 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2985 "Gmsh.y"
    {
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2994 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 3002 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 3010 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 3018 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 3023 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 3031 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 3036 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 3044 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 3049 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 3057 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 3062 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 3070 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 3077 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3091 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3105 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3133 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3145 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3150 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3157 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3162 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3169 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3181 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3186 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3193 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3205 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3210 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3217 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3222 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3229 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3245 "Gmsh.y"
    {
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3248 "Gmsh.y"
    {
    ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 3254 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3263 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (7)].l));
      if(List_Nbr((yyvsp[(3) - (7)].l)) == List_Nbr((yyvsp[(5) - (7)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (7)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(5) - (7)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[(3) - (7)].l)), List_Nbr((yyvsp[(5) - (7)].l)));
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3283 "Gmsh.y"
    {
      yymsg(0, "Explicit region numbers in layers are deprecated");
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (9)].l));
      if(List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(5) - (9)].l)) && List_Nbr((yyvsp[(3) - (9)].l)) == List_Nbr((yyvsp[(7) - (9)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (9)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(7) - (9)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d, %d}", List_Nbr((yyvsp[(3) - (9)].l)),
	      List_Nbr((yyvsp[(5) - (9)].l)), List_Nbr((yyvsp[(7) - (9)].l)));
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3306 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3314 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3318 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3322 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 3326 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (9)].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
	extr.mesh.Holes[num].second.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
	  double d;
	  List_Read((yyvsp[(6) - (9)].l), i, &d);
	  extr.mesh.Holes[num].second.push_back((int)d);
	}
      }
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 3345 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3357 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 3361 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3376 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3380 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
        (yyval.i) = -1;
      else // alternated
        (yyval.i) = 0;
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3392 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3396 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3401 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3412 "Gmsh.y"
    {
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      if(!(yyvsp[(3) - (7)].l)){
        List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->Method = MESH_TRANSFINITE;
            c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            c->typeTransfinite = type;
            c->coeffTransfinite = coef;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.Method = MESH_TRANSFINITE;
            (*it)->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
            (*it)->meshAttributes.typeTransfinite = type;
            (*it)->meshAttributes.coeffTransfinite = coef;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (7)].l), i, &d);
          int j = (int)fabs(d);
          for(int sign = -1; sign <= 1; sign += 2){
            Curve *c = FindCurve(sign * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
              c->typeTransfinite = type * sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sign * j);
              if(ge){
                ge->meshAttributes.Method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[(5) - (7)].d) > 2) ? (int)(yyvsp[(5) - (7)].d) : 2;
                ge->meshAttributes.typeTransfinite = type * sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sign > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[(3) - (7)].l));
      }
    ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3468 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (6)].l));
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
      }
      else{
        if(!(yyvsp[(3) - (6)].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Surface *s;
              List_Read(tmp, i, &s);
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
            }
          }
          else{
            for(GModel::fiter it = GModel::current()->firstFace();
                it != GModel::current()->lastFace(); it++){
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
              (*it)->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (6)].l), i, &d);
            Surface *s = FindSurface((int)d);
            if(s){
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[(5) - (6)].i);
              List_Reset(s->TrsfPoints);
              for(int j = 0; j < k; j++){
                double p;
                List_Read((yyvsp[(4) - (6)].l), j, &p);
                Vertex *v = FindPoint((int)fabs(p));
                if(v)
                  List_Add(s->TrsfPoints, &v);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GFace *gf = GModel::current()->getFaceByTag((int)d);
              if(gf){
                gf->meshAttributes.Method = MESH_TRANSFINITE;
                gf->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
                for(int j = 0; j < k; j++){
                  double p;
                  List_Read((yyvsp[(4) - (6)].l), j, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gf->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown surface %d", (int)d);
            }
          }
          List_Delete((yyvsp[(3) - (6)].l));
        }
      }
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3543 "Gmsh.y"
    {
      int k = List_Nbr((yyvsp[(4) - (5)].l));
      if(k != 0 && k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume: "
              "%d points instead of 6 or 8", k);
      }
      else{
        if(!(yyvsp[(3) - (5)].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Volume *v;
              List_Read(tmp, i, &v);
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
            }
          }
          else{
            for(GModel::riter it = GModel::current()->firstRegion();
                it != GModel::current()->lastRegion(); it++){
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (5)].l), i, &d);
            Volume *v = FindVolume((int)d);
            if(v){
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
              for(int i = 0; i < k; i++){
                double p;
                List_Read((yyvsp[(4) - (5)].l), i, &p);
                Vertex *vert = FindPoint((int)fabs(p));
                if(vert)
                  List_Add(v->TrsfPoints, &vert);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GRegion *gr = GModel::current()->getRegionByTag((int)d);
              if(gr){
                gr->meshAttributes.Method = MESH_TRANSFINITE;
                for(int i = 0; i < k; i++){
                  double p;
                  List_Read((yyvsp[(4) - (5)].l), i, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gr->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown volume %d", (int)d);
            }
          }
          List_Delete((yyvsp[(3) - (5)].l));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3610 "Gmsh.y"
    {
      if(!(yyvsp[(2) - (3)].l)){
  	  List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++)
            (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (3)].l)); i++){
          double d;
          List_Read((yyvsp[(2) - (3)].l), i, &d);
          Volume *v = FindVolume((int)d);
          if(v)
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr)
              gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
            else
              yymsg(1, "Unknown region %d", (int)d);
          }
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3646 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3655 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (5)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.recombine = 1;
            (*it)->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[(4) - (5)].i);
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.recombine = 1;
              gf->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
    ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3698 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->Recombine3D = 1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++){
            (*it)->meshAttributes.recombine3D = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Volume *v = FindVolume((int)d);
          if(v){
            v->Recombine3D = 1;
          }
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr){
              gr->meshAttributes.recombine3D = 1;
            }
            else
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3737 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s){
          s->TransfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
        else{
	  GFace *gf = GModel::current()->getFaceByTag(j);
	  if(gf)
            gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
          else
	    yymsg(1, "Unknown surface %d", (int)(yyvsp[(5) - (6)].d));
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3762 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(5) - (6)].l)) != List_Nbr((yyvsp[(3) - (6)].l))){
	yymsg(0, "Number of master (%d) different from number of slave (%d) lines",
              List_Nbr((yyvsp[(5) - (6)].l)), List_Nbr((yyvsp[(3) - (6)].l)));
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(5) - (6)].l), i, &d_master);
          List_Read((yyvsp[(3) - (6)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          Curve *c_slave = FindCurve(abs(j_slave));
          if(c_slave){
	    GModel::current()->getGEOInternals()->periodicEdges[j_slave] = j_master;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag(abs(j_slave));
            if(ge) ge->setMeshMaster(j_master);
            else yymsg(0, "Unknown line %d", j_slave);
          }
        }
      }
      List_Delete((yyvsp[(3) - (6)].l));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3790 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
	yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        Surface *s_slave = FindSurface(abs(j_slave));
        if(s_slave){
	  GModel::current()->getGEOInternals()->periodicFaces[j_slave] = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (12)].l), i, &ds);
            List_Read((yyvsp[(10) - (12)].l), i, &dm);
	    GModel::current()->getGEOInternals()->periodicEdges[(int)ds] = (int)dm;
            s_slave->edgeCounterparts[(int)ds] = (int)dm;
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
          if(gf){
            gf->setMeshMaster(j_master);
            for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
              double dm, ds;
              List_Read((yyvsp[(5) - (12)].l), i, &ds);
              List_Read((yyvsp[(10) - (12)].l), i, &dm);
              gf->edgeCounterparts[(int)ds] = (int)dm;
	      GEdge *ges = GModel::current()->getEdgeByTag(abs((int)ds));
	      ges->setMeshMaster((int)dm);
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3836 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iPoint;
            List_Read((yyvsp[(3) - (10)].l), i, &iPoint);
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(gv)
              gf->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            int iCurve;
            List_Read((yyvsp[(3) - (10)].l), i, &iCurve);
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
            if(ge)
              gf->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown line %d", iCurve);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)(yyvsp[(8) - (10)].d));
      }
    ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3882 "Gmsh.y"
    {
    ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3885 "Gmsh.y"
    {
    ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3894 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3898 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3908 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (6)].l)) >= 2){
        double d;
        List_Read((yyvsp[(4) - (6)].l), 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target)
          yymsg(0, "Could not find Point %d", (int)d);
        else{
          double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
          for(int i = 1; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
            List_Read((yyvsp[(4) - (6)].l), i, &d);
            Vertex *source = FindPoint((int)d);
            if(!source) yymsg(0, "Could not find Point %d", (int)d);
            if(target && source){
              source->Typ = target->Typ;
              source->Pos.X = x;
              source->Pos.Y = y;
              source->Pos.Z = z;
              source->boundaryLayerIndex = target->boundaryLayerIndex;
            }
          }
          ExtrudeParams::normalsCoherence.push_back(SPoint3(x, y, z));
        }
      }
      else
        yymsg(0, "Need at least two points to merge");
      ReplaceAllDuplicates();
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3942 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3943 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3944 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3949 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3955 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3967 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (7)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(5) - (7)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3985 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (10)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (10)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (10)].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (10)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(6) - (10)].l));
      List_Delete((yyvsp[(8) - (10)].l));
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 4012 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 4013 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 4014 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 4015 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 4016 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 4017 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 4018 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 4019 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 4021 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 4028 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 4029 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 4030 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 4031 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 4032 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 4033 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 4034 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 4035 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 4036 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 4037 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 4039 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 4040 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 4041 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 4042 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 4044 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 4045 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 4046 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 4047 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 4049 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 4051 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 4052 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 4053 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 4054 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 4055 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 4056 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 4057 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 4061 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 4062 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 4063 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 4064 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 4065 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 4066 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 4067 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 4068 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 4070 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 4071 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 4072 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 4073 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 4074 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 4075 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 4076 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 4077 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 4078 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 4079 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 4080 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 4081 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4090 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4091 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4092 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4093 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4094 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4095 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4096 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4101 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (1)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4122 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[tmpstring]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", tmpstring);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4141 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4159 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (4)].c)]);
	(yyval.d) = s.value.size();
      }
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4171 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (2)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4188 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[(5) - (5)].i));
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4209 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4214 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4219 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d)){
	d += (yyvsp[(4) - (4)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4229 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d)){
	d += (yyvsp[(7) - (7)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4239 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4244 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4253 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[(3) - (4)].l)) % 2){
        yyerror("Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr((yyvsp[(3) - (4)].l)); i += 2){
          char *s1, *s2; List_Read((yyvsp[(3) - (4)].l), i, &s1); List_Read((yyvsp[(3) - (4)].l), i + 1, &s2);
          std::string key(s1), val(s2);
          Free(s1); Free(s2);
#if defined(HAVE_OPENGL)
          if(key == "Font")
            font = drawContext::global()->getFontIndex(val.c_str());
          else if(key == "FontSize")
            fontsize = atoi(val.c_str());
          else if(key == "Align")
            align = drawContext::global()->getFontAlign(val.c_str());
#endif
        }
      }
      List_Delete((yyvsp[(3) - (4)].l));
      (yyval.d) = (double)((align<<16)|(font<<8)|(fontsize));
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4280 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4284 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4288 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4292 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4296 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4303 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4307 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4311 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4315 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4322 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4327 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4334 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4339 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4343 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4348 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4352 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4360 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4371 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4375 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4387 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4395 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4403 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4410 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4420 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
	yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
	double d = 0.0;
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
	List_Add((yyval.l), &d);
      }
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4440 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4444 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4448 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4452 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4456 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_POINT);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[0].find((int)num);
          if(it != groups[0].end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4485 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_LINE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[1].find((int)num);
          if(it != groups[1].end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4514 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_SURFACE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[2].find((int)num);
          if(it != groups[2].end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 4543 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
        double num;
        List_Read((yyvsp[(4) - (5)].l), i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_VOLUME);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add((yyval.l), &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups[4];
          GModel::current()->getPhysicalGroups(groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups[3].find((int)num);
          if(it != groups[3].end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 4572 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 4582 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4592 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 4605 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 4617 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(3) - (4)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(3) - (4)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(3) - (4)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 4629 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4648 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4669 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4674 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4678 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4682 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4694 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4698 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 4710 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4717 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 4727 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 4731 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (6)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (6)].d));
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 4746 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4751 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 4758 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4762 "Gmsh.y"
    {
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.c) = (yyvsp[(1) - (1)].c);
      }
      else{
	std::string val = gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)];
	(yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
	strcpy((yyval.c), val.c_str());
	Free((yyvsp[(1) - (1)].c));
      }
    ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4775 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4783 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4794 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4798 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4806 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4814 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 4822 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 4830 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[(3) - (4)].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4844 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '/' || (yyvsp[(3) - (4)].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      else
	strcpy((yyval.c), &(yyvsp[(3) - (4)].c)[i+1]);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 4858 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 4862 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 4884 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 4889 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10786 "Gmsh.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 4892 "Gmsh.y"


int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  int numFormats = 0;
  for(unsigned int i = 0; i < strlen(format); i++)
    if(format[i] == '%') numFormats++;
  if(!numFormats){
    strcpy(buffer, format);
    for(int i = 0; i < List_Nbr(list); i++){
      double d;
      List_Read(list, i, &d);
      char tmp[256];
      sprintf(tmp, " [%d]%g", i, d);
      strcat(buffer, tmp);
    }
    return 0;
  }

  char tmp1[256], tmp2[256];
  int j = 0, k = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j);
  buffer[j] = '\0';
  for(int i = 0; i < List_Nbr(list); i++){
    k = j;
    j++;
    if(j < (int)strlen(format)){
      if(format[j] == '%'){
	strcat(buffer, "%");
	j++;
      }
      while(j < (int)strlen(format) && format[j] != '%') j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k] = '\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list, i));
	strcat(buffer, tmp2);
      }
    }
    else
      return List_Nbr(list) - i;
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list)
{
  int M = List_Nbr(list);
  int N = 0;
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    N = std::max(N, List_Nbr(line));
  }
  fullMatrix<double> mat(M, N);
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    for(int j = 0; j < List_Nbr(line); j++){
      double val;
      List_Read(line, j, &val);
      mat(i, j) = val;
    }
  }
  for(int i = 0; i < List_Nbr(list); i++)
    List_Delete(*(List_T**)List_Pointer(list, i));
  List_Delete(list);
  return mat;
}

void yyerror(const char *s)
{
  Msg::Error("'%s', line %d : %s (%s)", gmsh_yyname.c_str(), gmsh_yylineno - 1,
             s, gmsh_yytext);
  gmsh_yyerrorstate++;
}

void yymsg(int level, const char *fmt, ...)
{
  va_list args;
  char tmp[1024];

  va_start(args, fmt);
  vsprintf(tmp, fmt, args);
  va_end(args);

  if(level == 0){
    Msg::Error("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
}

