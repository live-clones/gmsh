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

// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
#include "Colors.h"
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


/* Line 189 of yacc.c  */
#line 167 "Gmsh.tab.cpp"

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
     tSprintf = 292,
     tStrCat = 293,
     tStrPrefix = 294,
     tStrRelative = 295,
     tBoundingBox = 296,
     tDraw = 297,
     tToday = 298,
     tSyncModel = 299,
     tCreateTopology = 300,
     tCreateTopologyNoHoles = 301,
     tDistanceFunction = 302,
     tDefineConstant = 303,
     tPoint = 304,
     tCircle = 305,
     tEllipse = 306,
     tLine = 307,
     tSphere = 308,
     tPolarSphere = 309,
     tSurface = 310,
     tSpline = 311,
     tVolume = 312,
     tCharacteristic = 313,
     tLength = 314,
     tParametric = 315,
     tElliptic = 316,
     tRefineMesh = 317,
     tPlane = 318,
     tRuled = 319,
     tTransfinite = 320,
     tComplex = 321,
     tPhysical = 322,
     tCompound = 323,
     tPeriodic = 324,
     tUsing = 325,
     tPlugin = 326,
     tDegenerated = 327,
     tRotate = 328,
     tTranslate = 329,
     tSymmetry = 330,
     tDilate = 331,
     tExtrude = 332,
     tLevelset = 333,
     tRecombine = 334,
     tSmoother = 335,
     tSplit = 336,
     tDelete = 337,
     tCoherence = 338,
     tIntersect = 339,
     tLayers = 340,
     tHole = 341,
     tAlias = 342,
     tAliasWithOptions = 343,
     tQuadTriDbl = 344,
     tQuadTriSngl = 345,
     tRecombLaterals = 346,
     tTransfQuadTri = 347,
     tText2D = 348,
     tText3D = 349,
     tInterpolationScheme = 350,
     tTime = 351,
     tCombine = 352,
     tBSpline = 353,
     tBezier = 354,
     tNurbs = 355,
     tNurbsOrder = 356,
     tNurbsKnots = 357,
     tColor = 358,
     tColorTable = 359,
     tFor = 360,
     tIn = 361,
     tEndFor = 362,
     tIf = 363,
     tEndIf = 364,
     tExit = 365,
     tField = 366,
     tReturn = 367,
     tCall = 368,
     tFunction = 369,
     tShow = 370,
     tHide = 371,
     tGetValue = 372,
     tGetEnv = 373,
     tGetString = 374,
     tHomology = 375,
     tCohomology = 376,
     tGMSH_MAJOR_VERSION = 377,
     tGMSH_MINOR_VERSION = 378,
     tGMSH_PATCH_VERSION = 379,
     tAFFECTDIVIDE = 380,
     tAFFECTTIMES = 381,
     tAFFECTMINUS = 382,
     tAFFECTPLUS = 383,
     tOR = 384,
     tAND = 385,
     tNOTEQUAL = 386,
     tEQUAL = 387,
     tGREATEROREQUAL = 388,
     tLESSOREQUAL = 389,
     UNARYPREC = 390,
     tMINUSMINUS = 391,
     tPLUSPLUS = 392
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 87 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 214 of yacc.c  */
#line 352 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 364 "Gmsh.tab.cpp"

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
#define YYLAST   7603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  158
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  413
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1420

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   392

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,     2,   153,     2,   142,     2,     2,
     148,   149,   140,   138,   154,   139,   152,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     134,     2,   135,   129,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   150,     2,   151,   147,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,     2,   156,   157,     2,     2,     2,
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
     125,   126,   127,   128,   130,   131,   132,   133,   136,   137,
     144,   145,   146
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    51,    57,    65,    73,    83,
      90,    97,   104,   105,   108,   111,   114,   117,   120,   122,
     126,   128,   132,   133,   134,   145,   147,   151,   152,   166,
     168,   172,   173,   189,   198,   213,   214,   221,   223,   225,
     227,   229,   231,   233,   235,   241,   246,   253,   261,   271,
     275,   282,   287,   294,   304,   311,   321,   327,   336,   345,
     357,   364,   374,   380,   388,   398,   408,   420,   430,   440,
     441,   443,   444,   448,   454,   455,   465,   466,   469,   473,
     477,   479,   481,   482,   488,   489,   492,   500,   501,   511,
     518,   526,   531,   539,   548,   557,   565,   573,   585,   594,
     603,   604,   614,   623,   633,   637,   642,   653,   661,   669,
     678,   687,   700,   701,   711,   720,   728,   737,   738,   748,
     754,   766,   772,   782,   787,   797,   807,   809,   811,   812,
     815,   822,   829,   836,   843,   852,   863,   878,   895,   908,
     917,   926,   933,   948,   953,   960,   967,   971,   976,   982,
     986,   990,   995,  1000,  1004,  1012,  1020,  1024,  1032,  1036,
    1039,  1042,  1045,  1061,  1064,  1067,  1070,  1073,  1080,  1089,
    1098,  1109,  1111,  1114,  1116,  1120,  1125,  1127,  1133,  1145,
    1159,  1160,  1168,  1169,  1183,  1184,  1200,  1201,  1208,  1217,
    1226,  1235,  1248,  1261,  1274,  1289,  1304,  1319,  1320,  1333,
    1334,  1347,  1348,  1361,  1362,  1379,  1380,  1397,  1398,  1415,
    1416,  1435,  1436,  1455,  1456,  1475,  1477,  1480,  1486,  1494,
    1504,  1507,  1510,  1514,  1517,  1521,  1531,  1538,  1539,  1543,
    1544,  1546,  1547,  1550,  1551,  1554,  1562,  1569,  1578,  1584,
    1588,  1594,  1601,  1608,  1621,  1632,  1643,  1654,  1665,  1668,
    1672,  1679,  1681,  1683,  1686,  1692,  1700,  1702,  1706,  1709,
    1712,  1715,  1719,  1723,  1727,  1731,  1735,  1739,  1743,  1747,
    1751,  1755,  1759,  1763,  1767,  1771,  1777,  1782,  1787,  1792,
    1797,  1802,  1807,  1812,  1817,  1822,  1827,  1834,  1839,  1844,
    1849,  1854,  1859,  1864,  1871,  1878,  1885,  1890,  1895,  1900,
    1905,  1910,  1915,  1920,  1925,  1930,  1935,  1940,  1947,  1952,
    1957,  1962,  1967,  1972,  1977,  1984,  1991,  1998,  2003,  2005,
    2007,  2009,  2011,  2013,  2015,  2017,  2019,  2025,  2030,  2035,
    2038,  2044,  2048,  2055,  2060,  2068,  2075,  2077,  2080,  2083,
    2087,  2091,  2103,  2113,  2121,  2129,  2131,  2135,  2137,  2139,
    2142,  2146,  2151,  2157,  2159,  2161,  2164,  2168,  2172,  2178,
    2183,  2186,  2189,  2192,  2195,  2197,  2199,  2203,  2208,  2215,
    2217,  2219,  2223,  2227,  2237,  2245,  2247,  2253,  2257,  2264,
    2266,  2270,  2272,  2274,  2278,  2285,  2287,  2289,  2294,  2301,
    2308,  2313,  2318,  2323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     159,     0,    -1,   160,    -1,     1,     6,    -1,    -1,   160,
     161,    -1,   164,    -1,   163,    -1,   182,    -1,   191,    -1,
     196,    -1,   200,    -1,   201,    -1,   202,    -1,   205,    -1,
     225,    -1,   226,    -1,   227,    -1,   228,    -1,   204,    -1,
     203,    -1,   199,    -1,   230,    -1,   135,    -1,   135,   135,
      -1,    36,   148,     5,   149,     6,    -1,    36,   148,     5,
     149,   162,   243,     6,    -1,    36,   148,     5,   154,   239,
     149,     6,    -1,    36,   148,     5,   154,   239,   149,   162,
     243,     6,    -1,     4,     5,   155,   165,   156,     6,    -1,
      87,     4,   150,   231,   151,     6,    -1,    88,     4,   150,
     231,   151,     6,    -1,    -1,   165,   168,    -1,   165,   172,
      -1,   165,   175,    -1,   165,   177,    -1,   165,   178,    -1,
     231,    -1,   166,   154,   231,    -1,   231,    -1,   167,   154,
     231,    -1,    -1,    -1,     4,   169,   148,   166,   149,   170,
     155,   167,   156,     6,    -1,   243,    -1,   171,   154,   243,
      -1,    -1,    93,   148,   231,   154,   231,   154,   231,   149,
     173,   155,   171,   156,     6,    -1,   243,    -1,   174,   154,
     243,    -1,    -1,    94,   148,   231,   154,   231,   154,   231,
     154,   231,   149,   176,   155,   174,   156,     6,    -1,    95,
     155,   235,   156,   155,   235,   156,     6,    -1,    95,   155,
     235,   156,   155,   235,   156,   155,   235,   156,   155,   235,
     156,     6,    -1,    -1,    96,   179,   155,   167,   156,     6,
      -1,     7,    -1,   128,    -1,   127,    -1,   126,    -1,   125,
      -1,   146,    -1,   145,    -1,    48,   150,   184,   151,     6,
      -1,     4,   180,   236,     6,    -1,     4,   150,   151,   180,
     236,     6,    -1,     4,   150,   231,   151,   180,   231,     6,
      -1,     4,   150,   155,   239,   156,   151,   180,   236,     6,
      -1,     4,   181,     6,    -1,     4,   150,   231,   151,   181,
       6,    -1,     4,     7,   244,     6,    -1,     4,   152,     4,
       7,   244,     6,    -1,     4,   150,   231,   151,   152,     4,
       7,   244,     6,    -1,     4,   152,     4,   180,   231,     6,
      -1,     4,   150,   231,   151,   152,     4,   180,   231,     6,
      -1,     4,   152,     4,   181,     6,    -1,     4,   150,   231,
     151,   152,     4,   181,     6,    -1,     4,   152,   103,   152,
       4,     7,   240,     6,    -1,     4,   150,   231,   151,   152,
     103,   152,     4,     7,   240,     6,    -1,     4,   152,   104,
       7,   241,     6,    -1,     4,   150,   231,   151,   152,   104,
       7,   241,     6,    -1,     4,   111,     7,   231,     6,    -1,
     111,   150,   231,   151,     7,     4,     6,    -1,   111,   150,
     231,   151,   152,     4,     7,   231,     6,    -1,   111,   150,
     231,   151,   152,     4,     7,   244,     6,    -1,   111,   150,
     231,   151,   152,     4,     7,   155,   239,   156,     6,    -1,
      71,   148,     4,   149,   152,     4,     7,   231,     6,    -1,
      71,   148,     4,   149,   152,     4,     7,   244,     6,    -1,
      -1,   154,    -1,    -1,   184,   183,     4,    -1,   184,   183,
       4,     7,   231,    -1,    -1,   184,   183,     4,     7,   155,
     231,   185,   186,   156,    -1,    -1,   186,   187,    -1,   154,
       4,   236,    -1,   154,     4,     5,    -1,   231,    -1,   244,
      -1,    -1,   106,    53,   155,   231,   156,    -1,    -1,    63,
     233,    -1,    49,   148,   231,   149,     7,   233,     6,    -1,
      -1,    67,    49,   192,   148,   188,   149,     7,   236,     6,
      -1,    58,    59,   236,     7,   231,     6,    -1,    52,   148,
     231,   149,     7,   236,     6,    -1,    72,    52,   236,     6,
      -1,    56,   148,   231,   149,     7,   236,     6,    -1,    50,
     148,   231,   149,     7,   236,   190,     6,    -1,    51,   148,
     231,   149,     7,   236,   190,     6,    -1,    98,   148,   231,
     149,     7,   236,     6,    -1,    99,   148,   231,   149,     7,
     236,     6,    -1,   100,   148,   231,   149,     7,   236,   102,
     236,   101,   231,     6,    -1,    52,     4,   148,   231,   149,
       7,   236,     6,    -1,    68,    52,   148,   231,   149,     7,
     236,     6,    -1,    -1,    67,    52,   193,   148,   188,   149,
       7,   236,     6,    -1,    63,    55,   148,   231,   149,     7,
     236,     6,    -1,    64,    55,   148,   231,   149,     7,   236,
     189,     6,    -1,    12,    13,     6,    -1,    13,    55,   231,
       6,    -1,    60,    55,   148,   231,   149,     7,     5,     5,
       5,     6,    -1,    53,   148,   231,   149,     7,   236,     6,
      -1,    54,   148,   231,   149,     7,   236,     6,    -1,    55,
       4,   148,   231,   149,     7,   236,     6,    -1,    68,    55,
     148,   231,   149,     7,   236,     6,    -1,    68,    55,   148,
     231,   149,     7,   236,     4,   155,   235,   156,     6,    -1,
      -1,    67,    55,   194,   148,   188,   149,     7,   236,     6,
      -1,    66,    57,   148,   231,   149,     7,   236,     6,    -1,
      57,   148,   231,   149,     7,   236,     6,    -1,    68,    57,
     148,   231,   149,     7,   236,     6,    -1,    -1,    67,    57,
     195,   148,   188,   149,     7,   236,     6,    -1,    74,   233,
     155,   197,   156,    -1,    73,   155,   233,   154,   233,   154,
     231,   156,   155,   197,   156,    -1,    75,   233,   155,   197,
     156,    -1,    76,   155,   233,   154,   231,   156,   155,   197,
     156,    -1,     4,   155,   197,   156,    -1,    84,    52,   155,
     239,   156,    55,   155,   231,   156,    -1,    81,    52,   148,
     231,   149,   155,   239,   156,     6,    -1,   198,    -1,   196,
      -1,    -1,   198,   191,    -1,   198,    49,   155,   239,   156,
       6,    -1,   198,    52,   155,   239,   156,     6,    -1,   198,
      55,   155,   239,   156,     6,    -1,   198,    57,   155,   239,
     156,     6,    -1,    78,    63,   148,   231,   149,     7,   236,
       6,    -1,    78,    49,   148,   231,   149,     7,   155,   235,
     156,     6,    -1,    78,    63,   148,   231,   149,     7,   155,
     233,   154,   233,   154,   239,   156,     6,    -1,    78,    63,
     148,   231,   149,     7,   155,   233,   154,   233,   154,   233,
     154,   239,   156,     6,    -1,    78,    53,   148,   231,   149,
       7,   155,   233,   154,   239,   156,     6,    -1,    78,     4,
     148,   231,   149,     7,   236,     6,    -1,    78,     4,   148,
     231,   149,     7,     5,     6,    -1,    78,     4,   155,   231,
     156,     6,    -1,    78,     4,   148,   231,   149,     7,   155,
     233,   154,   233,   154,   239,   156,     6,    -1,    82,   155,
     198,   156,    -1,    82,   111,   150,   231,   151,     6,    -1,
      82,     4,   150,   231,   151,     6,    -1,    82,     4,     6,
      -1,    82,     4,     4,     6,    -1,   103,   240,   155,   198,
     156,    -1,   115,     5,     6,    -1,   116,     5,     6,    -1,
     115,   155,   198,   156,    -1,   116,   155,   198,   156,    -1,
       4,   244,     6,    -1,     4,     4,   150,   231,   151,   243,
       6,    -1,     4,     4,     4,   150,   231,   151,     6,    -1,
       4,   231,     6,    -1,    71,   148,     4,   149,   152,     4,
       6,    -1,    97,     4,     6,    -1,   110,     6,    -1,    44,
       6,    -1,    41,     6,    -1,    41,   155,   231,   154,   231,
     154,   231,   154,   231,   154,   231,   154,   231,   156,     6,
      -1,    42,     6,    -1,    45,     6,    -1,    46,     6,    -1,
      62,     6,    -1,   105,   148,   231,     8,   231,   149,    -1,
     105,   148,   231,     8,   231,     8,   231,   149,    -1,   105,
       4,   106,   155,   231,     8,   231,   156,    -1,   105,     4,
     106,   155,   231,     8,   231,     8,   231,   156,    -1,   107,
      -1,   114,     4,    -1,   112,    -1,   113,     4,     6,    -1,
     108,   148,   231,   149,    -1,   109,    -1,    77,   233,   155,
     198,   156,    -1,    77,   155,   233,   154,   233,   154,   231,
     156,   155,   198,   156,    -1,    77,   155,   233,   154,   233,
     154,   233,   154,   231,   156,   155,   198,   156,    -1,    -1,
      77,   233,   155,   198,   206,   219,   156,    -1,    -1,    77,
     155,   233,   154,   233,   154,   231,   156,   155,   198,   207,
     219,   156,    -1,    -1,    77,   155,   233,   154,   233,   154,
     233,   154,   231,   156,   155,   198,   208,   219,   156,    -1,
      -1,    77,   155,   198,   209,   219,   156,    -1,    77,    49,
     155,   231,   154,   233,   156,     6,    -1,    77,    52,   155,
     231,   154,   233,   156,     6,    -1,    77,    55,   155,   231,
     154,   233,   156,     6,    -1,    77,    49,   155,   231,   154,
     233,   154,   233,   154,   231,   156,     6,    -1,    77,    52,
     155,   231,   154,   233,   154,   233,   154,   231,   156,     6,
      -1,    77,    55,   155,   231,   154,   233,   154,   233,   154,
     231,   156,     6,    -1,    77,    49,   155,   231,   154,   233,
     154,   233,   154,   233,   154,   231,   156,     6,    -1,    77,
      52,   155,   231,   154,   233,   154,   233,   154,   233,   154,
     231,   156,     6,    -1,    77,    55,   155,   231,   154,   233,
     154,   233,   154,   233,   154,   231,   156,     6,    -1,    -1,
      77,    49,   155,   231,   154,   233,   156,   210,   155,   219,
     156,     6,    -1,    -1,    77,    52,   155,   231,   154,   233,
     156,   211,   155,   219,   156,     6,    -1,    -1,    77,    55,
     155,   231,   154,   233,   156,   212,   155,   219,   156,     6,
      -1,    -1,    77,    49,   155,   231,   154,   233,   154,   233,
     154,   231,   156,   213,   155,   219,   156,     6,    -1,    -1,
      77,    52,   155,   231,   154,   233,   154,   233,   154,   231,
     156,   214,   155,   219,   156,     6,    -1,    -1,    77,    55,
     155,   231,   154,   233,   154,   233,   154,   231,   156,   215,
     155,   219,   156,     6,    -1,    -1,    77,    49,   155,   231,
     154,   233,   154,   233,   154,   233,   154,   231,   156,   216,
     155,   219,   156,     6,    -1,    -1,    77,    52,   155,   231,
     154,   233,   154,   233,   154,   233,   154,   231,   156,   217,
     155,   219,   156,     6,    -1,    -1,    77,    55,   155,   231,
     154,   233,   154,   233,   154,   233,   154,   231,   156,   218,
     155,   219,   156,     6,    -1,   220,    -1,   219,   220,    -1,
      85,   155,   231,   156,     6,    -1,    85,   155,   236,   154,
     236,   156,     6,    -1,    85,   155,   236,   154,   236,   154,
     236,   156,     6,    -1,    79,     6,    -1,    89,     6,    -1,
      89,    91,     6,    -1,    90,     6,    -1,    90,    91,     6,
      -1,    86,   148,   231,   149,     7,   236,    70,   231,     6,
      -1,    70,     4,   150,   231,   151,     6,    -1,    -1,    70,
       4,   231,    -1,    -1,     4,    -1,    -1,     7,   236,    -1,
      -1,     7,   231,    -1,    65,    52,   237,     7,   231,   221,
       6,    -1,    65,    55,   237,   223,   222,     6,    -1,    61,
      55,   155,   231,   156,     7,   236,     6,    -1,    65,    57,
     237,   223,     6,    -1,    92,   237,     6,    -1,    79,    55,
     237,   224,     6,    -1,    80,    55,   236,     7,   231,     6,
      -1,    69,    52,   236,     7,   236,     6,    -1,    69,    55,
     231,   155,   239,   156,     7,   231,   155,   239,   156,     6,
      -1,    49,   155,   239,   156,   106,    55,   155,   231,   156,
       6,    -1,    52,   155,   239,   156,   106,    55,   155,   231,
     156,     6,    -1,    52,   155,   239,   156,   106,    57,   155,
     231,   156,     6,    -1,    55,   155,   239,   156,   106,    57,
     155,   231,   156,     6,    -1,    83,     6,    -1,    83,     4,
       6,    -1,    83,    49,   155,   239,   156,     6,    -1,   120,
      -1,   121,    -1,   229,     6,    -1,   229,   155,   236,   156,
       6,    -1,   229,   155,   236,   154,   236,   156,     6,    -1,
     232,    -1,   148,   231,   149,    -1,   139,   231,    -1,   138,
     231,    -1,   143,   231,    -1,   231,   139,   231,    -1,   231,
     138,   231,    -1,   231,   140,   231,    -1,   231,   141,   231,
      -1,   231,   142,   231,    -1,   231,   147,   231,    -1,   231,
     134,   231,    -1,   231,   135,   231,    -1,   231,   137,   231,
      -1,   231,   136,   231,    -1,   231,   133,   231,    -1,   231,
     132,   231,    -1,   231,   131,   231,    -1,   231,   130,   231,
      -1,   231,   129,   231,     8,   231,    -1,    14,   148,   231,
     149,    -1,    15,   148,   231,   149,    -1,    16,   148,   231,
     149,    -1,    17,   148,   231,   149,    -1,    18,   148,   231,
     149,    -1,    19,   148,   231,   149,    -1,    20,   148,   231,
     149,    -1,    21,   148,   231,   149,    -1,    22,   148,   231,
     149,    -1,    24,   148,   231,   149,    -1,    25,   148,   231,
     154,   231,   149,    -1,    26,   148,   231,   149,    -1,    27,
     148,   231,   149,    -1,    28,   148,   231,   149,    -1,    29,
     148,   231,   149,    -1,    30,   148,   231,   149,    -1,    31,
     148,   231,   149,    -1,    32,   148,   231,   154,   231,   149,
      -1,    33,   148,   231,   154,   231,   149,    -1,    34,   148,
     231,   154,   231,   149,    -1,    23,   148,   231,   149,    -1,
      14,   150,   231,   151,    -1,    15,   150,   231,   151,    -1,
      16,   150,   231,   151,    -1,    17,   150,   231,   151,    -1,
      18,   150,   231,   151,    -1,    19,   150,   231,   151,    -1,
      20,   150,   231,   151,    -1,    21,   150,   231,   151,    -1,
      22,   150,   231,   151,    -1,    24,   150,   231,   151,    -1,
      25,   150,   231,   154,   231,   151,    -1,    26,   150,   231,
     151,    -1,    27,   150,   231,   151,    -1,    28,   150,   231,
     151,    -1,    29,   150,   231,   151,    -1,    30,   150,   231,
     151,    -1,    31,   150,   231,   151,    -1,    32,   150,   231,
     154,   231,   151,    -1,    33,   150,   231,   154,   231,   151,
      -1,    34,   150,   231,   154,   231,   151,    -1,    23,   150,
     231,   151,    -1,     3,    -1,     9,    -1,    10,    -1,    11,
      -1,   122,    -1,   123,    -1,   124,    -1,     4,    -1,     4,
     157,   155,   231,   156,    -1,     4,   150,   231,   151,    -1,
     153,     4,   150,   151,    -1,     4,   181,    -1,     4,   150,
     231,   151,   181,    -1,     4,   152,     4,    -1,     4,   150,
     231,   151,   152,     4,    -1,     4,   152,     4,   181,    -1,
       4,   150,   231,   151,   152,     4,   181,    -1,   117,   148,
     243,   154,   231,   149,    -1,   234,    -1,   139,   233,    -1,
     138,   233,    -1,   233,   139,   233,    -1,   233,   138,   233,
      -1,   155,   231,   154,   231,   154,   231,   154,   231,   154,
     231,   156,    -1,   155,   231,   154,   231,   154,   231,   154,
     231,   156,    -1,   155,   231,   154,   231,   154,   231,   156,
      -1,   148,   231,   154,   231,   154,   231,   149,    -1,   236,
      -1,   235,   154,   236,    -1,   231,    -1,   238,    -1,   155,
     156,    -1,   155,   239,   156,    -1,   139,   155,   239,   156,
      -1,   231,   140,   155,   239,   156,    -1,   236,    -1,     5,
      -1,   139,   238,    -1,   231,   140,   238,    -1,   231,     8,
     231,    -1,   231,     8,   231,     8,   231,    -1,    49,   155,
     231,   156,    -1,    49,     5,    -1,    52,     5,    -1,    55,
       5,    -1,    57,     5,    -1,   196,    -1,   205,    -1,     4,
     150,   151,    -1,    35,   150,     4,   151,    -1,     4,   150,
     155,   239,   156,   151,    -1,   231,    -1,   238,    -1,   239,
     154,   231,    -1,   239,   154,   238,    -1,   155,   231,   154,
     231,   154,   231,   154,   231,   156,    -1,   155,   231,   154,
     231,   154,   231,   156,    -1,     4,    -1,     4,   152,   103,
     152,     4,    -1,   155,   242,   156,    -1,     4,   150,   231,
     151,   152,   104,    -1,   240,    -1,   242,   154,   240,    -1,
     244,    -1,     4,    -1,     4,   152,     4,    -1,     4,   150,
     231,   151,   152,     4,    -1,     5,    -1,    43,    -1,   118,
     148,   243,   149,    -1,   119,   148,   243,   154,   243,   149,
      -1,    38,   148,   243,   154,   243,   149,    -1,    39,   148,
     243,   149,    -1,    40,   148,   243,   149,    -1,    37,   148,
     243,   149,    -1,    37,   148,   243,   154,   239,   149,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   158,   158,   159,   164,   166,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   190,   194,   201,   206,   220,   233,   261,
     275,   286,   301,   306,   307,   308,   309,   310,   314,   316,
     321,   323,   329,   433,   328,   451,   458,   469,   468,   486,
     493,   504,   503,   520,   537,   560,   559,   573,   574,   575,
     576,   577,   581,   582,   588,   590,   653,   683,   716,   762,
     777,   793,   802,   808,   817,   835,   853,   862,   874,   879,
     887,   907,   930,   941,   949,   971,   994,  1022,  1034,  1048,
    1048,  1050,  1052,  1063,  1075,  1074,  1087,  1088,  1092,  1103,
    1116,  1120,  1131,  1134,  1147,  1150,  1160,  1184,  1183,  1203,
    1225,  1243,  1264,  1282,  1312,  1342,  1360,  1378,  1404,  1422,
    1441,  1440,  1463,  1481,  1520,  1526,  1532,  1539,  1564,  1589,
    1606,  1623,  1655,  1654,  1678,  1696,  1713,  1730,  1729,  1755,
    1760,  1765,  1770,  1775,  1798,  1804,  1815,  1816,  1821,  1824,
    1828,  1851,  1874,  1897,  1925,  1946,  1969,  1990,  2012,  2032,
    2144,  2163,  2201,  2310,  2319,  2325,  2340,  2368,  2385,  2399,
    2405,  2411,  2420,  2434,  2476,  2493,  2508,  2527,  2539,  2563,
    2567,  2574,  2580,  2585,  2591,  2595,  2599,  2609,  2626,  2643,
    2664,  2685,  2720,  2728,  2734,  2741,  2745,  2754,  2762,  2770,
    2779,  2778,  2792,  2791,  2805,  2804,  2818,  2817,  2830,  2837,
    2844,  2851,  2858,  2865,  2872,  2879,  2886,  2894,  2893,  2906,
    2905,  2918,  2917,  2930,  2929,  2942,  2941,  2954,  2953,  2966,
    2965,  2978,  2977,  2990,  2989,  3005,  3008,  3014,  3023,  3043,
    3066,  3070,  3074,  3078,  3082,  3086,  3105,  3118,  3121,  3137,
    3140,  3153,  3156,  3162,  3165,  3172,  3228,  3298,  3303,  3370,
    3406,  3449,  3474,  3501,  3545,  3568,  3591,  3594,  3603,  3607,
    3617,  3652,  3653,  3657,  3662,  3673,  3695,  3696,  3697,  3698,
    3699,  3700,  3701,  3702,  3703,  3710,  3711,  3712,  3713,  3714,
    3715,  3716,  3717,  3718,  3719,  3720,  3721,  3722,  3723,  3724,
    3725,  3726,  3727,  3728,  3729,  3730,  3731,  3732,  3733,  3734,
    3735,  3736,  3737,  3738,  3739,  3740,  3741,  3743,  3744,  3745,
    3746,  3747,  3748,  3749,  3750,  3751,  3752,  3753,  3754,  3755,
    3756,  3757,  3758,  3759,  3760,  3761,  3762,  3763,  3772,  3773,
    3774,  3775,  3776,  3777,  3778,  3782,  3802,  3821,  3839,  3851,
    3868,  3889,  3894,  3899,  3909,  3919,  3927,  3931,  3935,  3939,
    3943,  3950,  3954,  3958,  3962,  3969,  3974,  3981,  3986,  3990,
    3995,  3999,  4007,  4018,  4022,  4034,  4042,  4050,  4057,  4068,
    4088,  4092,  4096,  4100,  4104,  4114,  4124,  4136,  4148,  4169,
    4174,  4178,  4182,  4194,  4198,  4210,  4217,  4227,  4231,  4246,
    4251,  4258,  4262,  4275,  4283,  4294,  4298,  4306,  4314,  4322,
    4330,  4344,  4358,  4362
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
  "tList", "tPrintf", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tPoint", "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tField", "tReturn", "tCall",
  "tFunction", "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString",
  "tHomology", "tCohomology", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "Comma", "DefineConstants", "$@6",
  "FloatParameterOptions", "FloatParameterOption", "PhysicalId",
  "InSphereCenter", "CircleOptions", "Shape", "$@7", "$@8", "$@9", "$@10",
  "Transform", "MultipleShape", "ListOfShapes", "LevelSet", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "Transfinite", "Periodic", "Embedding", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr", 0
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,    63,
     384,   385,   386,   387,    60,    62,   388,   389,    43,    45,
      42,    47,    37,    33,   390,   391,   392,    94,    40,    41,
      91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   158,   159,   159,   160,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   163,   163,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   166,   166,
     167,   167,   169,   170,   168,   171,   171,   173,   172,   174,
     174,   176,   175,   177,   177,   179,   178,   180,   180,   180,
     180,   180,   181,   181,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   184,   184,   184,   185,   184,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   192,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     193,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   194,   191,   191,   191,   191,   195,   191,   196,
     196,   196,   196,   196,   196,   196,   197,   197,   198,   198,
     198,   198,   198,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   200,   201,   202,
     202,   202,   202,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   205,   205,   205,
     206,   205,   207,   205,   208,   205,   209,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   210,   205,   211,
     205,   212,   205,   213,   205,   214,   205,   215,   205,   216,
     205,   217,   205,   218,   205,   219,   219,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   227,   227,   227,   227,   228,   228,
     228,   229,   229,   230,   230,   230,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   233,   233,
     233,   234,   234,   234,   234,   235,   235,   236,   236,   236,
     236,   236,   236,   237,   237,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   239,
     239,   239,   239,   240,   240,   240,   240,   241,   241,   242,
     242,   243,   243,   243,   243,   244,   244,   244,   244,   244,
     244,   244,   244,   244
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     6,     7,     9,     3,
       6,     4,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     9,     9,     0,
       1,     0,     3,     5,     0,     9,     0,     2,     3,     3,
       1,     1,     0,     5,     0,     2,     7,     0,     9,     6,
       7,     4,     7,     8,     8,     7,     7,    11,     8,     8,
       0,     9,     8,     9,     3,     4,    10,     7,     7,     8,
       8,    12,     0,     9,     8,     7,     8,     0,     9,     5,
      11,     5,     9,     4,     9,     9,     1,     1,     0,     2,
       6,     6,     6,     6,     8,    10,    14,    16,    12,     8,
       8,     6,    14,     4,     6,     6,     3,     4,     5,     3,
       3,     4,     4,     3,     7,     7,     3,     7,     3,     2,
       2,     2,    15,     2,     2,     2,     2,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     2,     3,     2,     3,     9,     6,     0,     3,     0,
       1,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       5,     6,     6,    12,    10,    10,    10,    10,     2,     3,
       6,     1,     1,     2,     5,     7,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     4,     2,
       5,     3,     6,     4,     7,     6,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     1,     1,     3,     4,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     4,     6,     6,
       4,     4,     4,     6
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
       0,   196,     0,     0,   193,     0,     0,     0,     0,   271,
     272,     5,     7,     6,     8,     9,    10,    21,    11,    12,
      13,    20,    19,    14,    15,    16,    17,    18,     0,    22,
     338,   345,   405,    57,   339,   340,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   406,     0,     0,     0,     0,   342,   343,   344,
      61,    60,    59,    58,     0,     0,     0,    63,    62,     0,
       0,     0,     0,   148,     0,     0,     0,   276,     0,     0,
       0,     0,   181,     0,   183,   180,   184,   185,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,     0,
       0,     0,   107,   120,   132,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   356,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,   268,     0,
       0,     0,     0,   345,   374,     0,     0,     0,     0,     0,
       0,     0,   384,   385,   367,   373,     0,   368,     0,     0,
       0,     0,   395,     0,     0,     0,     0,     0,   179,     0,
       0,   192,     0,   148,     0,   148,   273,     0,     0,     0,
       0,     0,   349,    32,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   345,   279,   278,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,   146,     0,    69,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   124,     0,     0,     0,    89,     0,     0,   389,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   358,   357,     0,     0,     0,     0,   148,
     148,     0,     0,     0,     0,     0,     0,     0,   206,     0,
     148,     0,     0,     0,     0,     0,   253,     0,     0,     0,
     166,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,   380,     0,   381,   382,   383,     0,   278,   375,   369,
       0,     0,     0,   259,   178,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,   194,   169,     0,   170,     0,
       0,     0,     0,   351,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
       0,   401,     0,     0,     0,     0,     0,     0,     0,     0,
     277,    57,     0,     0,     0,    57,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,   149,    65,     0,   294,
     293,   292,   291,   287,   288,   290,   289,   282,   281,   283,
     284,   285,   286,   125,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,   360,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,   163,     0,     0,     0,     0,   386,     0,
       0,     0,     0,     0,   370,   377,     0,   283,   376,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,   171,
     172,     0,     0,     0,   347,   353,     0,    42,     0,     0,
       0,    55,     0,    33,    34,    35,    36,    37,   296,   317,
     297,   318,   298,   319,   299,   320,   300,   321,   301,   322,
     302,   323,   303,   324,   304,   325,   316,   337,   305,   326,
       0,     0,   307,   328,   308,   329,   309,   330,   310,   331,
     311,   332,   312,   333,     0,     0,     0,     0,     0,     0,
       0,     0,   412,     0,     0,   410,   411,    82,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,   348,     0,     0,     0,     0,     0,    25,
      23,     0,     0,     0,    64,    92,     0,   391,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   252,   250,     0,
     258,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,     0,   197,     0,     0,     0,     0,     0,     0,   254,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     347,   387,   379,   371,     0,     0,     0,     0,     0,     0,
       0,   168,     0,     0,     0,     0,     0,   274,     0,     0,
     350,     0,   346,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   403,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,    70,
      72,    74,     0,     0,   399,     0,    80,     0,     0,     0,
       0,   295,    24,     0,     0,     0,     0,     0,     0,   104,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,   241,     0,   243,     0,   207,   236,     0,     0,     0,
     161,     0,     0,     0,   261,     0,   165,   164,   270,     0,
      30,    31,     0,   378,   372,     0,     0,     0,   396,     0,
       0,     0,   187,     0,     0,     0,   175,   352,   174,     0,
       0,     0,     0,   365,     0,   306,   327,   313,   334,   314,
     335,   315,   336,     0,   413,   409,   355,   408,     0,    57,
       0,     0,     0,     0,    67,     0,     0,     0,   397,     0,
       0,     0,     0,    26,    27,     0,     0,     0,    93,   106,
       0,     0,     0,     0,     0,   110,     0,     0,   127,   128,
       0,     0,   112,   135,     0,     0,     0,   102,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,   148,     0,   217,     0,   219,     0,
     221,     0,   367,     0,     0,   242,   244,     0,     0,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     115,   116,     0,     0,     0,     0,    83,     0,   275,   354,
       0,    38,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,    77,     0,     0,    78,     0,   400,   150,   151,
     152,   153,     0,     0,    94,     0,   105,   113,   114,   118,
       0,     0,   129,     0,     0,   257,   122,     0,     0,   248,
     134,     0,     0,     0,     0,   119,     0,   130,   136,     0,
       0,     0,     0,   364,     0,   363,     0,     0,   208,     0,
       0,   209,     0,     0,   210,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,   159,     0,     0,     0,   154,
       0,     0,     0,     0,   394,     0,   189,   188,     0,     0,
       0,    43,     0,     0,     0,   366,     0,     0,     0,   404,
      68,    73,    75,     0,    81,     0,    28,     0,    96,     0,
       0,     0,     0,     0,     0,   123,   108,   121,   133,   138,
       0,     0,    87,    88,   148,     0,   142,     0,     0,     0,
       0,     0,     0,     0,   237,     0,     0,   148,     0,     0,
       0,     0,     0,   145,   144,     0,     0,     0,     0,    84,
      85,     0,    39,     0,     0,     0,    41,    56,     0,   398,
       0,     0,   264,   265,   266,   267,   126,     0,     0,     0,
       0,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,     0,     0,     0,   202,     0,     0,   155,
       0,     0,     0,   393,   190,     0,     0,     0,     0,     0,
      79,     0,     0,    95,    97,     0,     0,     0,   140,     0,
     223,     0,     0,   225,     0,     0,   227,     0,     0,     0,
     238,     0,   198,     0,   148,     0,     0,     0,   117,    86,
       0,    47,     0,    53,     0,     0,     0,   103,   131,   263,
     361,   211,     0,     0,   218,   212,     0,     0,   220,   213,
       0,     0,   222,     0,     0,     0,   204,     0,   158,     0,
       0,     0,     0,     0,     0,     0,    99,    98,     0,   229,
       0,   231,     0,   233,   239,   245,   203,   199,     0,     0,
       0,     0,    44,     0,    51,     0,     0,     0,   214,     0,
       0,   215,     0,     0,   216,     0,     0,   162,     0,   156,
       0,    45,     0,     0,   182,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,   224,     0,   226,
       0,   228,     0,   157,    46,    48,     0,    49,     0,     0,
       0,     0,     0,     0,    54,   230,   232,   234,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    71,   741,    72,    73,   465,  1080,  1086,
     663,   843,  1231,  1380,   664,  1342,  1406,   665,  1382,   666,
     667,   847,   144,   262,    74,   559,   355,  1188,  1241,  1284,
     772,  1118,  1012,   536,   381,   382,   383,   384,   232,   330,
     331,    77,    78,    79,    80,    81,    82,   233,   803,  1303,
    1358,   608,  1139,  1142,  1145,  1322,  1326,  1330,  1369,  1372,
    1375,   799,   800,   907,   769,   582,   617,    84,    85,    86,
      87,    88,    89,   234,   147,   394,   199,   972,   973,   236,
     237,   440,   244,   732,   875,   510,   511
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1059
static const yytype_int16 yypact[] =
{
    3924,    52,    64,  4005, -1059, -1059,  1833,    57,   -35,   -72,
      20,    74,    89,   113,   126,    44,  -104,    -9,    28,    26,
      49,    60,    14,    63,    70,   123,   145,   152,   209,   193,
     197,   252,   198,   202,   292,   -13,   110,   251,   172,   301,
     301,   173,   256,    41,   269,   291,   298,    13,    59,   333,
     372,   385,  1986,   388,   245,   262,   270,    15,     4, -1059,
     276, -1059,   411,   278, -1059,   433,   444,     2,    32, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,    34, -1059,
   -1059,    21,   286,    98, -1059, -1059, -1059,   277,   364,   367,
     415,   428,   440,   448,   468,   495,   505,   514,   547,   561,
     566,   569,   586,   587,   598,   601,   637,   638,   306,   309,
     331,   335, -1059,   465,   336,   360,   386, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,  3532,  3532,  3532, -1059, -1059,  3532,
    1758,     9,   469,   457,  2427,   483,  1142, -1059,   534,   548,
    3532,   506, -1059,  3532, -1059, -1059, -1059, -1059, -1059,  3532,
    3456,  3532,  3532,   391,  3532,  3456,  3532,  3532,   416,  3456,
    3532,  3532,  2427,   424,   430, -1059,   436,   441,  1986,  1986,
    1986,   451, -1059, -1059, -1059, -1059,   459,   474,   484,  2427,
    3532,   609,  2427,   301,   301,   301,  3532,  3532,   -67, -1059,
      75,   301,   476,   480,   501,  3244,    81,  -100,   521,   522,
     526,  1986,  2427,   535,    43,   509, -1059,   676, -1059,   531,
     550,   544,   558,   325, -1059,   563,    33,   715,   722,   740,
    2574,  1679, -1059, -1059,  3664, -1059,   744, -1059,   747,  3532,
    3532,  3532,   602,  3532,   606,   666,  3532,  3532, -1059,  3532,
     762, -1059,   769, -1059,   797, -1059, -1059,  2427,   621,  3532,
     774,   627, -1059, -1059, -1059,   801,  3532,  3532,  3532,  3532,
    3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,
    3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,
    3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,
    3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,   315,   315,
     315,   315,  3532,   315,   315,   315,   624,   643,   643,   643,
    6322,    76,  3456,  5563,   319,   661,   809,   673,   674, -1059,
     672,  4078,   826, -1059, -1059,  3532,  3532,  3532,  3532,  3532,
    3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,  3532,
   -1059, -1059,  1262,   161,  4861,    29,  6343,  3456,  3696, -1059,
     232,  6364,  6385,  3532,  6406,   533,  6427,  6448,  3532,   640,
    6469,  6490,   835,  3532,  3532,  3532,  3532,   845,   849,   849,
    3532,   695,   712,   713,   717,  3532,  3532,  3532,   861,  4781,
     723,   889,   -33, -1059, -1059,  4887,  4913,   301,   301,   457,
     457,    67,  3532,  3532,  3532,  3244,  3244,  3532,  4078,    93,
   -1059,  3532,  3532,  3532,  3532,  3532,   869,   893,  3532,   900,
   -1059,  3532,  3532,  1086, -1059,  3456,  3456,  3532,  3532,  3091,
     903, -1059,  3532, -1059, -1059, -1059,  3456,   643, -1059, -1059,
     645,  3532,  2721, -1059, -1059,  6511,  6532,  6553,   810,  4939,
   -1059,   757,  3715,  6574,  5586, -1059, -1059,  1362, -1059,  1423,
     646,  3532,  5609,   -36,  3532,     6, -1059,  6595,  5632,  6616,
    5655,  6637,  5678,  6658,  5701,  6679,  5724,  6700,  5747,  6721,
    5770,  6742,  5793,  6763,  5816,  6784,  5839,  6805,  5862,  4965,
    4991,  6826,  5885,  6847,  5908,  6868,  5931,  6889,  5954,  6910,
    5977,  6931,  6000,  5017,  5043,  5069,  5095,  5121,  5147,   662,
     168, -1059,   768,   788,   789,  1495,   775,   802,   779,  3532,
   -1059, -1059,  2427,   665,   238,    98,  3532,   911,   938,    17,
     799, -1059,   -86,    31,    30,   -57, -1059, -1059,  3734,   838,
    1208,   901,   901,   763,   763,   763,   763,   395,   395,   643,
     643,   643,   643, -1059,     5,  3456,  3532,   955, -1059,   962,
     984,  3456,  3456,   896,   992,   998,  6952,  1002,   906,  1006,
    1024,  6973,   927,  1037,  1039,  3532,  6994,  4109,  7015,  7036,
    3532,  2427,  1045,  1048,  7057,  3597,  3597,  3597,  3597,  7078,
    7099,  7120,  2427,  3456,   905, -1059,   301,  3532,  3532, -1059,
   -1059,   904,   907,  3532,  5173,  5199,  5225,  4835,     7,   301,
    1866,  7141,  4137,  7162,  7183,  7204,  3532,  1055,  3532,  7225,
   -1059,  6023,  6046, -1059,   668,   692,  6069,  6092, -1059,  3456,
    6115,   913,  4165,   693, -1059,  3761,  3456,   643, -1059,  1058,
    1059,  1060,   916,  3532,  2033,  3532,  3532, -1059,    46, -1059,
   -1059,  2427,  1063,  6138,    77, -1059,  4193, -1059,   922,   924,
     919, -1059,  1069, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
    3532,  3532, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059, -1059,  3532,  3532,  3532,  3532,  3532,  3532,
    3532,  1074, -1059,  3456,   315, -1059, -1059, -1059,  3532, -1059,
     315,  1073,   929,    19,  3532,  1076,  1077,  2383, -1059,  1078,
     934,    15,  1080, -1059,  3456,  3456,  3456,  3456,  3532, -1059,
     952,   315,   169,  5251, -1059,  1081,   301,  3696, -1059,  1034,
    2427,  2427,  1084,  2427,   798,  2427,  2427,  1089,  1036,  2427,
    2427,  2530,  1093,  1094,  1095,  1097,  3809, -1059, -1059,  1099,
   -1059,  1100,   959,  7456, -1059,   963,   980,   982,  1126,  1144,
    1148,  1150,   703,  1156,   324,  5277,  5303, -1059, -1059,  4221,
     301,   301,   301,  1157,  1158,  1008,  1017,    16,    40,   -29,
   -1059,   352, -1059,     7,  1161,  1163,  1167,  1169,  1172,  7456,
   -1059,  2677,  1015,  1174,  1177,  1181,  1133,  1183,  1184,   710,
     -79, -1059, -1059, -1059,  3532,   742,  2427,  2427,  2427,  1187,
    5329, -1059,  3780,   985,  1188,  1189,  1038, -1059,  1190,  1193,
   -1059,  1192, -1059,  1051,  3532,  3532,  2427,  1047, -1059,  7246,
    6161,  7267,  6184,  7288,  6207,  7309,  6230,  6253, -1059,   207,
    1057,  7330,  1061, -1059,    76,   341,  1052,  1201,  2824, -1059,
   -1059, -1059,    15,  3532, -1059,   764, -1059,   765,   771,   772,
     776,  7456, -1059,  1194,     8,  3532,  3309,    10,  1054,  1149,
    1149,  2427,  1205,  1062,  1065,  1207,  1210,  2427,  1066,  1212,
    1216, -1059,  1209,  2427,  2427,  2427,  1219,  1218, -1059,  2427,
    1222,  1223,  1224,  1225,  2427,  2427,  2427, -1059,  1226,   119,
    3532,  3532,  3532,  1070,    88,   221,   275,  1085, -1059,  2427,
    3532, -1059,  1220, -1059,  1230, -1059, -1059,  3244,   -11,  2133,
   -1059,  1082,  1083,  2868, -1059,  3456, -1059, -1059, -1059,  1088,
   -1059, -1059,  1096,  7456, -1059,  1233,  1234,  1151, -1059,  3532,
    3532,  3532, -1059,  1238,  1239,  1245, -1059,   -36, -1059,  3532,
    5355,  5381,   780, -1059,  3532, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,  1103, -1059, -1059, -1059, -1059,  2427,    98,
    3532,  1251,  1254,    17, -1059,  1253,  6276,    15, -1059,  1256,
    1257,  1259,  1260, -1059, -1059,   315,  5407,  3532,  7456, -1059,
    3532,   301,  1263,  1280,  1281, -1059,  3532,  3532, -1059, -1059,
    1284,  3532, -1059, -1059,  1255,  1286,  1287,  1191,  3532, -1059,
    1288,  2427,  2427,  2427,  2427,  1290,   937,  1292,  3532, -1059,
    3597,  4249,  7351,  4025,   457,   301,  1294,   301,  1296,   301,
    1297,  3532,   363,  1153,  7372, -1059, -1059,  4277,   419, -1059,
    1298,  1531,  1299,  2427,   301,  1531,  1302,   792,  3532, -1059,
   -1059, -1059,  2427,  4053,   752,  7393, -1059,  3162, -1059, -1059,
     224,  7456,  3532,  3532,  2427,  1155,   793,  7456,  1307,  1306,
    1308,  3215, -1059,  1309,  1311, -1059,  1166, -1059, -1059, -1059,
   -1059, -1059,  1314,  3532,  7456,  4305,    12, -1059, -1059, -1059,
    4333,  4361, -1059,  4389,  1310, -1059, -1059,  1268,  1316,  7456,
   -1059,  1317,  1318,  1322,  1323, -1059,  1175, -1059, -1059,  4808,
    3276,  1326,  1178, -1059,  3532, -1059,  1179,   421, -1059,  1198,
     423, -1059,  1202,   429, -1059,  1203,  6299,  1328,  2427,  1332,
    1204,  3532, -1059,  3015,   432, -1059,   806,   470,   482, -1059,
    1350,  4417,  1261,  3532, -1059,  3532, -1059, -1059,  3456,  3561,
    1354, -1059,  3532,  5433,  5459, -1059,  2427,  3532,  1357, -1059,
   -1059, -1059, -1059,    15, -1059,  1264, -1059,  5485, -1059,  1358,
    1360,  1361,  1363,  1364,  1217, -1059, -1059, -1059, -1059, -1059,
    2427,  3456, -1059, -1059,   457,  4081, -1059,  3244,     7,  3244,
       7,  3244,     7,  1365, -1059,   811,  2427, -1059,  4445,   301,
    1367,  3456,   301, -1059, -1059,  3532,  4473,  4501,   827, -1059,
   -1059,  1221,  7456,  3532,  3532,   832,  7456, -1059,  1372, -1059,
    3532,   833, -1059, -1059, -1059, -1059, -1059,  3532,   836,   840,
    1227,  3532, -1059,  4529,   488,   437,  4557,   490,   439,  4585,
     511,   582, -1059,  2427,  1373,  1312,  2180,  1229,   537, -1059,
     841,   539,  3626, -1059, -1059,  1374,  3532,  7414,  5511,    37,
   -1059,  5537,  1381, -1059, -1059,  4613,  1380,  1382, -1059,  4641,
    1383,  3532,  1399,  1400,  3532,  1401,  1402,  3532,  1415,  1231,
   -1059,  3532, -1059,     7, -1059,  3456,  1418,  3015, -1059, -1059,
     844, -1059,  3532, -1059,  2427,  3532,  2280, -1059, -1059, -1059,
   -1059, -1059,  1272,  4669, -1059, -1059,  1276,  4697, -1059, -1059,
    1277,  4725, -1059,  1427,  3645,   636,  2327,   852, -1059,   542,
     863,  1431,  1283,  7435,   864,  4753, -1059, -1059,     7,  1433,
       7,  1434,     7,  1435, -1059, -1059, -1059, -1059,     7,  1436,
    3456,  1438, -1059,   315, -1059,  1291,  1439,   654, -1059,  1293,
     677, -1059,  1295,   694, -1059,  1303,   719, -1059,   867, -1059,
     870, -1059,  1304,  2427, -1059,  1441,     7,  1443,     7,  1445,
       7, -1059,  1446,   315,  1451,   315,   871, -1059,   741, -1059,
     755, -1059,   784, -1059, -1059, -1059,   874, -1059,  1457,  1458,
    1459,  1460,   315,  1461, -1059, -1059, -1059, -1059, -1059, -1059
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1059, -1059, -1059, -1059,   584, -1059, -1059, -1059, -1059,   194,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059, -1059,  -312,    -3, -1059, -1059, -1059, -1059, -1059, -1059,
    -135, -1059,   581,  1479, -1059, -1059, -1059, -1059,     3,  -398,
    -201, -1059, -1059, -1059, -1059, -1059, -1059,  1482, -1059, -1059,
   -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059, -1059,
   -1059,  -593,  -710, -1059, -1059,  1109, -1059, -1059, -1059, -1059,
   -1059, -1059, -1059,    -6, -1059,    45, -1059, -1058,   422,   134,
     316,   222,  -695,   499, -1059,  -282,    18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     146,   601,   602,   145,   408,  1156,    76,   252,   245,   522,
     657,   739,   526,   324,  1004,   423,  1009,   214,   168,   242,
     150,   730,   931,   865,   148,   258,   152,   512,   513,   514,
     163,   516,   517,   518,   168,   163,   874,   254,   431,   189,
     256,   793,   190,  1313,   159,   207,   933,   419,   411,   420,
     794,   160,   457,   834,   459,   412,   795,   796,     4,   793,
     797,   798,   159,   217,     5,   218,   137,   138,   794,   734,
     149,   397,   398,   839,   795,   796,   151,   793,   797,   798,
     154,   509,   264,   521,   198,   200,   794,   206,   399,   936,
     208,   171,   795,   796,   209,   155,   797,   798,   737,   658,
     659,   660,   661,   264,   210,   397,   398,   932,   219,   137,
     138,   265,   325,   326,   118,   119,   120,   121,  1235,   156,
     122,   596,   866,   867,   215,  1039,  1040,   935,   317,   318,
     319,   934,   157,   320,   323,   118,   119,   120,   121,   161,
     740,   122,  1248,   740,   352,  1059,   329,   354,   397,   398,
     397,   398,   246,   356,   358,   361,   362,   253,   364,   358,
     366,   367,   662,   358,   370,   371,   137,   138,   216,   169,
     243,   259,   731,   260,   164,   153,   162,   995,   261,   164,
     557,   165,   172,   558,   389,   736,   735,   255,   432,   257,
     395,   396,  1314,   421,   158,   125,   126,   166,   835,   396,
     173,   130,   131,   132,   133,   397,   398,   174,   167,   610,
     938,   170,   724,   397,   398,   175,   125,   126,   171,   397,
     398,   603,   137,   138,   437,   358,   397,   398,   936,   839,
     400,   397,   398,   445,   446,   447,   410,   449,   392,   393,
     452,   453,  1045,   454,  1046,   521,   401,   609,   176,   644,
     409,   182,   177,   462,   183,   181,  1344,   184,   191,   185,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,  1097,   192,   178,   202,   515,   179,   203,   180,
     554,   204,   377,   378,   379,   555,   358,   712,   884,   509,
     264,   527,   713,   562,   211,  1396,   525,   193,   201,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   186,   416,   212,   187,   989,   188,
     213,   437,   118,   119,   120,   121,   984,   566,   122,   397,
     398,   562,   571,   130,   131,   132,   133,   576,   577,   578,
     579,   441,   841,  1171,   584,  1047,   221,  1048,  1172,   589,
     590,   591,   360,   137,   138,   220,   562,   365,   563,   222,
     723,   369,   238,   239,   194,   195,   604,   605,   606,   317,
     318,   607,   329,   329,   196,   611,   612,   613,   614,   615,
     240,   205,   619,   397,   398,   621,   622,   248,   241,   358,
     358,   626,   627,   630,   247,   266,   632,   267,   249,  1049,
     358,  1050,   860,   125,   126,   635,   637,   250,   862,   194,
     195,   263,   599,   600,   130,   131,   132,   133,   251,   196,
     393,   775,   776,   777,   308,   653,   197,   309,   656,   883,
     655,   328,   397,   398,   137,   138,   130,   131,   132,   133,
     137,   138,   312,   327,   235,   429,   359,   260,   920,   310,
     143,   359,   261,   311,   313,   359,   137,   138,  1238,   333,
     397,   398,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   442,   347,   348,   937,   793,   314,   793,
     349,   353,   268,   630,   269,   270,   794,   271,   794,  1147,
     727,   725,   795,   796,   795,   796,   797,   798,   797,   798,
      38,    39,    40,    41,   315,   346,   347,   348,    46,   363,
     350,    49,   349,   726,   523,   936,   438,   359,   936,   358,
     743,   936,   988,   990,   351,   637,   747,   397,   398,   397,
     398,   397,   398,   272,   368,   273,   332,   397,   398,   761,
     397,   398,   373,  1151,   766,  1207,   274,  1209,   275,   773,
     773,   773,   773,  1211,   375,   374,  1219,   358,   276,   376,
     277,   785,   786,  1292,   372,  1295,   278,   789,   279,   380,
     235,   235,   235,   774,   774,   774,   774,   385,   397,   398,
     809,   388,   811,   390,   391,  1255,   280,  1258,   281,  1261,
     397,   398,   386,   358,  1221,   936,   397,   398,   397,   398,
     358,   402,   387,   235,   417,   403,  1222,   830,   359,   832,
     833,   784,  1291,   282,  1294,   283,  1136,   624,   625,   397,
     398,   840,   793,   284,   801,   285,   404,   936,   633,   422,
     936,   794,   286,   936,   287,  1297,   936,   795,   796,   413,
     414,   797,   798,   438,   415,   397,   398,   397,   398,   460,
     397,   398,   424,   418,   849,   850,   425,   562,   936,   568,
     936,  1305,   936,  1307,   427,   288,  1360,   289,   851,   852,
     853,   854,   855,   856,   857,   426,   793,   358,   428,   290,
    1335,   291,   861,   430,   292,   794,   293,   294,   868,   295,
     433,   795,   796,  1102,   793,   797,   798,   434,   358,   358,
     358,   358,   881,   794,   296,   298,   297,   299,  1298,   795,
     796,   359,   359,   797,   798,   435,   300,   793,   301,   302,
     443,   303,   359,   444,   448,  1367,   794,  1370,   638,  1373,
    1165,   450,   795,   796,   793,  1376,   797,   798,   455,   137,
     138,   461,   451,   794,   519,   456,   260,   742,   463,   795,
     796,   261,   464,   797,   798,   304,   306,   305,   307,   793,
     349,   887,  1356,  1398,   562,  1400,   572,  1402,   794,   562,
     651,   634,   652,   458,   795,   796,  1250,   466,   797,   798,
    1385,   793,   710,   528,   711,   782,   529,   840,   953,   562,
     794,   722,   562,   530,   815,   793,   795,   796,   531,   143,
     797,   798,   537,  1387,   794,   924,   925,   926,   970,   971,
     795,   796,   575,   585,   797,   798,   562,   562,   816,   823,
    1389,   819,   580,   893,   793,   894,   581,   562,   825,   918,
     586,   587,   991,   794,   562,   588,   952,   996,   592,   795,
     796,   359,   594,   797,   798,  1391,   616,   638,   748,  1006,
    1008,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   595,   562,  1409,   954,   349,
     618,   344,   345,   346,   347,   348,   620,   631,  1166,   359,
     349,  1410,   645,   642,  1041,  1042,  1043,   728,   997,   562,
     998,   999,   714,  1052,  1054,   562,   562,  1000,  1001,   718,
     562,  1057,  1002,   720,  1084,   859,  1085,   715,   716,   358,
    1411,  1126,   729,  1127,   721,   359,   562,  1177,  1160,  1178,
     733,   719,   359,  1073,  1074,  1075,   877,   878,   879,   880,
    1084,   744,  1220,  1081,  1079,  1263,   745,  1264,  1087,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   562,  1058,  1275,  1091,   349,  1084,  1282,  1279,  1283,
    1084,   746,  1286,   961,   562,   562,  1287,  1306,  1177,   750,
    1341,  1104,   749,   767,  1105,   751,   562,  1090,  1359,   753,
    1110,  1111,   754,   755,   781,  1113,  1266,   562,  1084,  1361,
    1365,   562,  1119,  1392,  1393,  1084,  1394,  1408,  1412,   359,
    1413,   756,  1129,   758,  1130,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   759,  1146,   760,   329,   349,   768,
     359,   359,   359,   359,   770,   358,  1106,   783,  1131,   358,
     787,   810,  1161,   788,   821,   826,   827,   828,   829,   837,
     844,  1169,   845,   836,   846,   848,  1173,  1174,   858,   863,
     864,  1381,   869,   870,   873,   872,   876,   882,   886,   888,
    1137,   891,  1140,   898,  1143,  1170,   897,  1187,     7,     8,
     902,   903,   904,  1336,   905,   908,  1154,   909,   910,  1157,
    1158,  1404,   911,  1407,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,  1205,   912,
    1418,   913,   349,   914,   962,   532,    17,    18,   533,    20,
      21,   534,    23,   535,    25,  1218,    26,   437,   334,    29,
      30,   915,    32,    33,    34,   916,   917,  1226,    37,  1227,
     919,   927,   358,   929,   928,   930,  1232,  1067,   939,   940,
     945,  1236,   889,   890,   941,   892,   942,   895,   896,   943,
     946,   899,   900,   947,    54,    55,    56,   948,   949,   950,
     951,   958,   963,   964,   965,   358,   966,   967,   968,   969,
    1003,  1253,   974,  1256,   992,  1259,   985,   329,   993,  1010,
     987,  1015,  1011,  1018,  1024,   358,  1019,  1016,  1022,  1272,
    1017,  1021,  1023,  1028,  1029,  1044,  1055,  1277,  1278,  1031,
    1032,  1033,  1034,  1038,  1281,  1051,  1056,  1063,  1064,  1070,
    1071,  1285,   623,  1068,  1076,  1289,  1077,  1069,   955,   956,
     957,  1078,  1254,  1072,  1257,  1088,  1260,  1092,  1093,  1095,
    1114,   359,  1098,  1099,  1268,  1100,  1101,  1271,   553,  1107,
    1087,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,  1323,  1108,  1109,  1327,   349,
    1112,  1331,  1115,  1116,  1120,  1334,  1125,  1117,  1128,   358,
    1138,   358,  1141,  1144,  1152,  1155,  1343,  1148,  1159,  1345,
    1176,  1179,  1180,  1014,  1181,  1193,  1183,  1184,  1185,  1020,
    1186,  1194,  1195,  1196,  1197,  1025,  1026,  1027,  1198,  1199,
    1200,  1030,  1203,  1204,  1214,  1206,  1035,  1036,  1037,  1216,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,  1053,  1339,  1208,   358,   349,  1223,  1210,  1212,  1217,
    1230,  1062,  1225,  1237,  1242,  1066,  1243,  1244,  1239,  1245,
    1246,  1262,  1247,  1269,     7,     8,  1276,   359,  1280,  1300,
    1309,   359,  1301,  1288,  1304,  1316,  1318,  1333,  1319,  1321,
    1228,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,  1324,  1325,  1328,  1329,   349,
    1089,   532,    17,    18,   533,    20,    21,   534,    23,   535,
      25,  1332,    26,  1249,  1338,    29,    30,  1348,    32,    33,
      34,  1350,  1352,  1354,    37,     7,     8,  1362,  1363,  1368,
    1371,  1374,  1377,  1270,  1379,  1384,  1383,  1397,  1386,  1399,
    1388,  1401,  1403,  1121,  1122,  1123,  1124,  1405,  1390,  1395,
      54,    55,    56,  1414,  1415,  1416,  1417,  1419,  1005,   438,
    1310,  1013,   532,    17,    18,   533,    20,    21,   534,    23,
     535,    25,    75,    26,   359,    83,    29,    30,   583,    32,
      33,    34,  1094,     0,  1162,    37,     0,     0,     0,     0,
       0,   717,     0,     0,     0,     0,  1175,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   649,     0,
       0,    54,    55,    56,     0,     0,     0,  1337,     0,  1340,
       0,     0,     0,     0,    90,   223,     0,   359,     0,     0,
      94,    95,    96,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   225,     0,     0,     0,
    1215,     0,     0,     0,     0,     0,     0,     0,     0,   650,
     226,     0,  1378,   227,     0,     0,   228,     0,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,     0,
       0,     0,    46,     0,     0,    49,     0,     0,     0,     0,
       0,   359,     0,   359,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,  1265,     0,
       0,     0,   349,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   405,
    1153,     0,     0,     0,   136,     0,   359,     0,     0,   407,
       0,     0,    90,   223,   142,  1299,   197,   439,    94,    95,
      96,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,     0,
       0,   227,     0,     0,   228,     0,   229,     0,  1347,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
      46,    90,   316,    49,     0,     0,     0,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,   124,     0,     0,     0,
       0,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   357,     0,
       0,     0,   136,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,     0,   439,    90,    91,    92,     0,
      93,     0,    94,    95,    96,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
     118,   119,   120,   121,     0,   124,   122,     0,     7,     8,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,     0,     0,
       0,   136,     0,     0,     0,     0,   139,     0,     0,   321,
       0,   142,     0,   322,     0,   532,    17,    18,   533,    20,
      21,   534,    23,   535,    25,     0,    26,     0,     0,    29,
      30,     0,    32,    33,    34,     0,     0,     0,    37,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   127,   128,   129,   130,   131,
     132,   133,     0,     0,    54,    55,    56,     0,     0,     0,
       0,   134,   135,     0,     0,     0,   136,     0,   137,   138,
       0,   139,     0,   140,     0,   141,   142,     0,   143,    90,
     223,   224,     0,     0,     0,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   225,   802,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,     0,     0,   227,     0,
       0,   228,     0,   229,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,     0,     0,    46,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,    17,    18,   533,    20,    21,   534,    23,
     535,    25,     0,    26,     0,     0,    29,    30,     0,    32,
      33,    34,     0,   124,     0,    37,     0,     0,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   230,     0,     0,     0,   136,
       0,    54,    55,    56,   139,     0,    90,   223,  1060,   142,
       0,   231,    94,    95,    96,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,     0,   227,     0,     0,   228,   831,
     229,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,    46,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
      17,    18,   533,    20,    21,   534,    23,   535,    25,     0,
      26,     0,     0,    29,    30,     0,    32,    33,    34,     0,
     124,     0,    37,     0,     0,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   230,     0,     0,     0,   136,     0,    54,    55,
      56,   139,     0,    90,   223,  1346,   142,     0,  1061,    94,
      95,    96,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
       0,     0,   227,     0,     0,   228,  1302,   229,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,    46,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,    17,    18,   533,
      20,    21,   534,    23,   535,    25,     0,    26,     0,   871,
      29,    30,     0,    32,    33,    34,     0,   124,     0,    37,
       0,     0,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   230,
       0,     0,     0,   136,     0,    54,    55,    56,   139,     0,
      90,   223,     0,   142,     0,   231,    94,    95,    96,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,   227,
       0,     0,   228,  1357,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,    46,     0,
       0,    49,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,   901,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   230,     0,     0,     0,
     136,     0,     0,     0,     0,   139,     0,    90,   223,     0,
     142,     0,   231,    94,    95,    96,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,   227,     0,     0,   228,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,     0,     0,     0,    46,     0,     0,    49,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,   944,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   357,     0,     0,     0,   136,     0,     0,
       0,     0,   139,     0,    90,   223,     0,   142,     0,   436,
      94,    95,    96,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,     0,     0,   227,     0,     0,   228,     0,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,     0,
       0,     0,    46,     0,     0,    49,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
     994,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     357,     0,     0,     0,   136,     0,     0,     0,     0,   139,
       0,    90,   223,     0,   142,     0,   636,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,     0,     0,
     227,     0,     0,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,     0,     0,     0,    46,
       0,     0,    49,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,     0,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   230,     0,     0,
       0,   136,     0,     0,     0,     0,   139,     0,    90,   223,
       0,   142,     0,  1065,    94,    95,    96,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,     0,     0,   227,     0,     0,
     228,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,     0,    90,   316,    46,     0,     0,    49,
      94,    95,    96,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,     0,
       0,     0,   124,     0,     0,     0,     0,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,  1153,     0,     0,     0,   136,     0,
       0,     0,     0,   407,     0,    90,   316,   264,   142,     0,
     197,    94,    95,    96,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,   120,   121,     0,     0,   122,     0,     0,   124,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,     0,
       0,  1182,     0,     0,     0,     0,     0,     0,     0,   134,
     135,     0,     0,     0,   136,     0,     0,     0,     0,   139,
       0,     0,   628,     0,   142,     0,   629,    90,   316,     0,
       0,     0,     0,    94,    95,    96,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   124,
     125,   126,  1202,     0,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,     0,     0,     0,   136,     0,     0,     0,     0,
     139,     0,    90,   316,     0,   142,     0,  1168,    94,    95,
      96,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,   124,   349,     0,     0,     0,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   405,   406,     0,     0,     0,   136,     0,     0,
       0,     0,   407,     0,     0,     0,     0,   142,     0,   197,
       0,     0,     0,     0,     0,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,   124,     0,     0,     0,
       0,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,     0,
       0,     0,   136,     0,     0,     0,     0,   139,     0,    90,
     223,     0,   142,     0,  1007,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,     0,     0,   227,     0,
       0,   228,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,    90,   316,    46,     0,     0,
      49,    94,    95,    96,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,  1229,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   357,     0,     0,     0,   136,
      90,   316,   264,     0,   139,     0,    94,    95,    96,   142,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,  1308,     0,   118,   119,   120,   121,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,  1355,     0,     0,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   441,     0,     0,   136,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   142,     0,     0,     0,     0,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   441,     0,     0,     0,   349,     0,
       0,     0,     0,     0,   124,   125,   126,     0,     0,   127,
     128,   129,     0,   646,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
     136,     0,   738,     0,     0,   139,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   824,
       0,     0,     0,   349,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   960,     0,
       0,     0,   349,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   442,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   561,   347,   348,     0,
       0,     0,     0,   349,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,   906,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,    -4,     1,     0,   349,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     6,
       0,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     9,     0,     0,    -4,    -4,    10,    11,     0,    12,
      13,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       7,     8,    50,    51,     0,     0,     0,    52,     0,     0,
       0,     0,    53,    54,    55,    56,     0,     0,    57,     0,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,    69,    70,   532,    17,    18,
     533,    20,    21,   534,    23,   535,    25,     0,    26,     0,
       0,    29,    30,     0,    32,    33,    34,     0,     0,     0,
      37,     0,     0,     0,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,    54,    55,    56,  1134,
       0,  1135,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,  1163,     0,  1164,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,  1251,     0,  1252,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,   763,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,   805,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,   822,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,   842,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,     0,   923,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,  1132,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,  1150,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,  1189,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,  1190,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,     0,  1191,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,  1192,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,  1224,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,  1267,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,  1273,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,     0,  1274,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,  1290,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,  1293,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,  1296,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,  1317,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,     0,  1320,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,  1349,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,  1351,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,  1353,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,     0,     0,  1366,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,   593,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,  1201,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   520,     0,     0,     0,     0,   597,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,   556,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,   597,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,   598,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,   643,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,   690,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,   691,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,   704,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,   705,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,   706,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,   707,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,   708,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,   709,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,   790,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,   791,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,   792,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,   885,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,   921,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,   922,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,   959,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,  1082,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,  1083,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,  1103,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,     0,  1233,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,  1234,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,  1240,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,  1312,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,  1315,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,   524,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   648,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
     654,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,   669,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,   671,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,   673,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,   675,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,   677,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,   679,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,   681,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,   683,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   685,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
     687,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,   689,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,   693,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,   695,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,   697,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,   699,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,   701,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,   703,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,   813,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   814,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
     817,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,   818,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,   820,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,   838,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,   976,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,   978,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,   980,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,   982,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,   983,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,  1096,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
    1213,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   520,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   560,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   564,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   565,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   567,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   569,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   570,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   573,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   574,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     639,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   640,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   641,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   647,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   668,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   670,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   672,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   674,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   676,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   678,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     680,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   682,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   684,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   686,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   688,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   692,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   694,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   696,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   698,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   700,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     702,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   752,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   757,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   762,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   764,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   765,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   771,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   778,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   779,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   780,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     804,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   806,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   807,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   808,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   812,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   975,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   977,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   979,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   981,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   986,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
    1133,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,  1149,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,  1167,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,  1311,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,  1364,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349
};

static const yytype_int16 yycheck[] =
{
       6,   399,   400,     6,   205,  1063,     3,     5,     4,   321,
       4,     6,   324,     4,     6,   216,     6,     4,     4,     4,
      55,     4,     6,     4,     6,     4,     6,   309,   310,   311,
       4,   313,   314,   315,     4,     4,   731,     5,     5,    52,
       6,    70,    55,     6,   148,     4,     6,     4,   148,     6,
      79,   155,   253,     7,   255,   155,    85,    86,     6,    70,
      89,    90,   148,     4,     0,     6,   145,   146,    79,   155,
      13,   138,   139,   152,    85,    86,   148,    70,    89,    90,
       6,     4,     5,     7,    39,    40,    79,    42,   155,   799,
      49,   148,    85,    86,    53,     6,    89,    90,   155,    93,
      94,    95,    96,     5,    63,   138,   139,    91,    49,   145,
     146,    93,   103,   104,    37,    38,    39,    40,  1176,     6,
      43,   154,   103,   104,   111,     6,     7,   156,   134,   135,
     136,    91,     6,   139,   140,    37,    38,    39,    40,   148,
     135,    43,  1200,   135,   150,   156,   143,   153,   138,   139,
     138,   139,   148,   159,   160,   161,   162,   155,   164,   165,
     166,   167,   156,   169,   170,   171,   145,   146,   155,   155,
     155,   150,   155,   152,   148,   155,   148,   872,   157,   148,
     151,   155,    59,   154,   190,   155,   155,   155,   155,   155,
     196,   197,   155,   150,   150,   118,   119,   148,   152,   205,
      55,   125,   126,   127,   128,   138,   139,    55,   148,   410,
     803,   148,   524,   138,   139,     6,   118,   119,   148,   138,
     139,   154,   145,   146,   230,   231,   138,   139,   938,   152,
     155,   138,   139,   239,   240,   241,   155,   243,   193,   194,
     246,   247,   154,   249,   156,     7,   201,   154,    55,   450,
     205,    49,    55,   259,    52,    57,  1314,    55,   148,    57,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   997,    52,    52,    49,   312,    55,    52,    57,
     149,    55,   178,   179,   180,   154,   322,   149,   149,     4,
       5,   324,   154,   154,    55,  1383,     7,   155,   155,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,    52,   211,    55,    55,     7,    57,
      52,   357,    37,    38,    39,    40,   149,   363,    43,   138,
     139,   154,   368,   125,   126,   127,   128,   373,   374,   375,
     376,     8,   654,   149,   380,   154,     4,   156,   154,   385,
     386,   387,   160,   145,   146,    52,   154,   165,   156,     4,
     152,   169,     4,   148,   138,   139,   402,   403,   404,   405,
     406,   407,   399,   400,   148,   411,   412,   413,   414,   415,
     148,   155,   418,   138,   139,   421,   422,     6,   148,   425,
     426,   427,   428,   429,   148,   148,   432,   150,   150,   154,
     436,   156,   714,   118,   119,   441,   442,     4,   720,   138,
     139,   155,   397,   398,   125,   126,   127,   128,     4,   148,
     405,   586,   587,   588,   148,   461,   155,   148,   464,   741,
     463,     4,   138,   139,   145,   146,   125,   126,   127,   128,
     145,   146,     7,     4,    52,   150,   160,   152,   154,   148,
     155,   165,   157,   148,   148,   169,   145,   146,  1183,     6,
     138,   139,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   154,    70,   148,    70,
     147,     5,   148,   519,   150,   148,    79,   150,    79,   156,
     526,   524,    85,    86,    85,    86,    89,    90,    89,    90,
      73,    74,    75,    76,   148,   140,   141,   142,    81,   148,
       6,    84,   147,   525,   322,  1255,   230,   231,  1258,   555,
     556,  1261,   864,   865,     6,   561,   562,   138,   139,   138,
     139,   138,   139,   148,   148,   150,   144,   138,   139,   575,
     138,   139,   148,   154,   580,   154,   148,   154,   150,   585,
     586,   587,   588,   154,   148,   155,   154,   593,   148,   148,
     150,   597,   598,   156,   172,   156,   148,   603,   150,   148,
     178,   179,   180,   585,   586,   587,   588,   148,   138,   139,
     616,   189,   618,     4,   192,  1208,   148,  1210,   150,  1212,
     138,   139,   148,   629,   154,  1335,   138,   139,   138,   139,
     636,   155,   148,   211,   212,   155,   154,   643,   322,   645,
     646,   596,   154,   148,   154,   150,  1044,   425,   426,   138,
     139,   654,    70,   148,   609,   150,   155,  1367,   436,   150,
    1370,    79,   148,  1373,   150,   154,  1376,    85,    86,   148,
     148,    89,    90,   357,   148,   138,   139,   138,   139,   257,
     138,   139,     6,   148,   690,   691,   155,   154,  1398,   156,
    1400,   154,  1402,   154,   150,   148,   154,   150,   704,   705,
     706,   707,   708,   709,   710,   155,    70,   713,   150,   148,
    1303,   150,   718,   150,   148,    79,   150,   148,   724,   150,
       5,    85,    86,  1005,    70,    89,    90,     5,   734,   735,
     736,   737,   738,    79,   148,   148,   150,   150,   156,    85,
      86,   425,   426,    89,    90,     5,   148,    70,   150,   148,
       6,   150,   436,     6,   152,  1348,    79,  1350,   442,  1352,
       8,   155,    85,    86,    70,  1358,    89,    90,     6,   145,
     146,   150,   106,    79,   150,     6,   152,   555,     4,    85,
      86,   157,   155,    89,    90,   148,   148,   150,   150,    70,
     147,   746,   156,  1386,   154,  1388,   156,  1390,    79,   154,
     154,   156,   156,     6,    85,    86,  1204,     6,    89,    90,
     156,    70,   150,   152,   152,   593,     7,   820,   824,   154,
      79,   156,   154,   150,   156,    70,    85,    86,   156,   155,
      89,    90,     6,   156,    79,   790,   791,   792,   844,   845,
      85,    86,     7,   148,    89,    90,   154,   154,   156,   156,
     156,   629,     7,    55,    70,    57,     7,   154,   636,   156,
     148,   148,   865,    79,   154,   148,   156,   873,     7,    85,
      86,   555,   149,    89,    90,   156,     7,   561,   562,   885,
     886,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     6,   154,   156,   156,   147,
       7,   138,   139,   140,   141,   142,     6,     4,   156,   593,
     147,   156,   155,   103,   920,   921,   922,     6,   154,   154,
     156,   156,   154,   929,   930,   154,   154,   156,   156,   154,
     154,   937,   156,   154,   154,   713,   156,   149,   149,   945,
     156,     4,     4,     6,   522,   629,   154,   154,   156,   156,
     151,   149,   636,   959,   960,   961,   734,   735,   736,   737,
     154,     6,   156,   969,   967,   154,     4,   156,   974,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   154,   937,   156,   990,   147,   154,   154,   156,   156,
     154,     7,   156,     8,   154,   154,   156,   156,   154,     7,
     156,  1007,   106,   581,  1010,     7,   154,   989,   156,     7,
    1016,  1017,   106,     7,   592,  1021,  1217,   154,   154,   156,
     156,   154,  1028,   156,   154,   154,   156,   156,   154,   713,
     156,     7,  1038,   106,  1040,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     7,  1051,     7,  1044,   147,     4,
     734,   735,   736,   737,     6,  1061,  1011,   152,  1040,  1065,
     156,     6,  1068,   156,   151,     7,     7,     7,   152,     6,
     148,  1077,   148,   651,   155,     6,  1082,  1083,     4,     6,
     151,  1363,     6,     6,   150,     7,     6,   135,     7,    55,
    1045,     7,  1047,    57,  1049,  1077,     7,  1103,    12,    13,
       7,     7,     7,  1304,     7,     6,  1061,     7,   149,  1064,
    1065,  1393,   149,  1395,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,  1134,   149,
    1412,   149,   147,     7,   149,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,  1151,    60,  1153,     6,    63,
      64,     7,    66,    67,    68,     7,     6,  1163,    72,  1165,
       4,     4,  1168,   155,     6,   148,  1172,   945,     7,     6,
     155,  1177,   750,   751,     7,   753,     7,   755,   756,     7,
       6,   759,   760,     6,    98,    99,   100,     6,    55,     6,
       6,     4,     4,     4,   156,  1201,     6,     4,     6,   148,
       6,  1207,   155,  1209,   152,  1211,   149,  1204,     7,   155,
     149,     6,    63,     6,     5,  1221,     6,   155,     6,  1225,
     155,   155,     6,     4,     6,   155,     6,  1233,  1234,     7,
       7,     7,     7,     7,  1240,   150,     6,   155,   155,     6,
       6,  1247,   156,   155,     6,  1251,     7,   151,   826,   827,
     828,     6,  1207,   102,  1209,   152,  1211,     6,     4,     6,
       5,   945,     6,     6,  1219,     6,     6,  1222,     6,     6,
    1276,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,  1291,     6,     6,  1294,   147,
       6,  1297,     6,     6,     6,  1301,     6,   106,     6,  1305,
       6,  1307,     6,     6,     6,     6,  1312,   154,     6,  1315,
     155,     4,     6,   891,     6,     5,     7,     6,   152,   897,
       6,    53,     6,     6,     6,   903,   904,   905,     6,     6,
     155,   909,     6,   155,     6,   156,   914,   915,   916,     7,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   929,  1307,   155,  1360,   147,     6,   155,   155,   155,
       6,   939,   101,     6,     6,   943,     6,     6,   104,     6,
       6,     6,   155,     6,    12,    13,   155,  1061,     6,     6,
       6,  1065,    70,   156,   155,     4,     6,   156,     6,     6,
    1168,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     6,     6,     6,     6,   147,
     988,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     6,    60,  1201,     6,    63,    64,   155,    66,    67,
      68,   155,   155,     6,    72,    12,    13,     6,   155,     6,
       6,     6,     6,  1221,     6,     6,   155,     6,   155,     6,
     155,     6,     6,  1031,  1032,  1033,  1034,     6,   155,   155,
      98,    99,   100,     6,     6,     6,     6,     6,   884,  1153,
    1276,   890,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     3,    60,  1168,     3,    63,    64,   379,    66,
      67,    68,   993,    -1,  1072,    72,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1201,   156,    -1,
      -1,    98,    99,   100,    -1,    -1,    -1,  1305,    -1,  1307,
      -1,    -1,    -1,    -1,     3,     4,    -1,  1221,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
    1148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      49,    -1,  1360,    52,    -1,    -1,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,  1305,    -1,  1307,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,  1216,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,    -1,   143,    -1,  1360,    -1,    -1,   148,
      -1,    -1,     3,     4,   153,  1263,   155,   156,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    -1,  1316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,     3,     4,    84,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,     3,     4,     5,    -1,
       7,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    38,    39,    40,    -1,   117,    43,    -1,    12,    13,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,   153,    -1,   155,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,    -1,   143,    -1,   145,   146,
      -1,   148,    -1,   150,    -1,   152,   153,    -1,   155,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    -1,    66,
      67,    68,    -1,   117,    -1,    72,    -1,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,   143,
      -1,    98,    99,   100,   148,    -1,     3,     4,     5,   153,
      -1,   155,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,   156,
      57,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    68,    -1,
     117,    -1,    72,    -1,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,    -1,    -1,    -1,   143,    -1,    98,    99,
     100,   148,    -1,     3,     4,     5,   153,    -1,   155,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,   156,    57,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,     6,
      63,    64,    -1,    66,    67,    68,    -1,   117,    -1,    72,
      -1,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
      -1,    -1,    -1,   143,    -1,    98,    99,   100,   148,    -1,
       3,     4,    -1,   153,    -1,   155,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,   156,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
      -1,    84,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,   148,    -1,     3,     4,    -1,
     153,    -1,   155,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    84,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,    -1,     3,     4,    -1,   153,    -1,   155,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    84,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
      -1,     3,     4,    -1,   153,    -1,   155,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,
      -1,    -1,    84,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,   148,    -1,     3,     4,
      -1,   153,    -1,   155,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,     3,     4,    81,    -1,    -1,    84,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,   148,    -1,     3,     4,     5,   153,    -1,
     155,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    -1,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,   153,    -1,   155,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   117,
     118,   119,     6,    -1,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,    -1,     3,     4,    -1,   153,    -1,   155,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   117,   147,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,   117,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,   148,    -1,     3,
       4,    -1,   153,    -1,   155,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,     3,     4,    81,    -1,    -1,
      84,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,   143,
       3,     4,     5,    -1,   148,    -1,     9,    10,    11,   153,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,    -1,    37,    38,    39,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,     6,    -1,    -1,   122,   123,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,     8,    -1,    -1,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     8,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,    -1,    -1,   122,
     123,   124,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,
     143,    -1,     8,    -1,    -1,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     8,
      -1,    -1,    -1,   147,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     8,    -1,
      -1,    -1,   147,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    70,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,     0,     1,    -1,   147,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     4,
      -1,    87,    88,    -1,    -1,    -1,    92,    12,    13,    -1,
      -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,   105,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    36,    -1,    -1,   120,   121,    41,    42,    -1,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      12,    13,    87,    88,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,    -1,    -1,   103,    -1,
     105,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,   120,   121,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      72,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    98,    99,   100,   154,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,   151,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     151,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,   151,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,   151,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,   151,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     151,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,   151,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,   151,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,   151,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     151,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,    -1,    -1,   151,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,   151,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,   151,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,   151,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,   151,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,   151,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
     151,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
     149,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
     149,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
     149,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
     149,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,
     149,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
     147,    -1,   149,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,   147,    -1,   149,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   159,   160,     6,     0,     4,    12,    13,    36,
      41,    42,    44,    45,    46,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      87,    88,    92,    97,    98,    99,   100,   103,   105,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   120,
     121,   161,   163,   164,   182,   191,   196,   199,   200,   201,
     202,   203,   204,   205,   225,   226,   227,   228,   229,   230,
       3,     4,     5,     7,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    37,    38,
      39,    40,    43,   111,   117,   118,   119,   122,   123,   124,
     125,   126,   127,   128,   138,   139,   143,   145,   146,   148,
     150,   152,   153,   155,   180,   181,   231,   232,   244,    13,
      55,   148,     6,   155,     6,     6,     6,     6,   150,   148,
     155,   148,   148,     4,   148,   155,   148,   148,     4,   155,
     148,   148,    59,    55,    55,     6,    55,    55,    52,    55,
      57,    57,    49,    52,    55,    57,    52,    55,    57,    52,
      55,   148,    52,   155,   138,   139,   148,   155,   233,   234,
     233,   155,    49,    52,    55,   155,   233,     4,    49,    53,
      63,    55,    55,    52,     4,   111,   155,     4,     6,    49,
      52,     4,     4,     4,     5,    35,    49,    52,    55,    57,
     139,   155,   196,   205,   231,   236,   237,   238,     4,   148,
     148,   148,     4,   155,   240,     4,   148,   148,     6,   150,
       4,     4,     5,   155,     5,   155,     6,   155,     4,   150,
     152,   157,   181,   155,     5,   244,   148,   150,   148,   150,
     148,   150,   148,   150,   148,   150,   148,   150,   148,   150,
     148,   150,   148,   150,   148,   150,   148,   150,   148,   150,
     148,   150,   148,   150,   148,   150,   148,   150,   148,   150,
     148,   150,   148,   150,   148,   150,   148,   150,   148,   148,
     148,   148,     7,   148,   148,   148,     4,   231,   231,   231,
     231,   151,   155,   231,     4,   103,   104,     4,     4,   196,
     197,   198,   236,     6,     6,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   147,
       6,     6,   231,     5,   231,   184,   231,   139,   231,   238,
     239,   231,   231,   148,   231,   239,   231,   231,   148,   239,
     231,   231,   236,   148,   155,   148,   148,   237,   237,   237,
     148,   192,   193,   194,   195,   148,   148,   148,   236,   231,
       4,   236,   233,   233,   233,   231,   231,   138,   139,   155,
     155,   233,   155,   155,   155,   138,   139,   148,   198,   233,
     155,   148,   155,   148,   148,   148,   237,   236,   148,     4,
       6,   150,   150,   198,     6,   155,   155,   150,   150,   150,
     150,     5,   155,     5,     5,     5,   155,   231,   238,   156,
     239,     8,   140,     6,     6,   231,   231,   231,   152,   231,
     155,   106,   231,   231,   231,     6,     6,   198,     6,   198,
     236,   150,   231,     4,   155,   165,     6,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,     4,
     243,   244,   243,   243,   243,   231,   243,   243,   243,   150,
     149,     7,   180,   239,   151,     7,   180,   181,   152,     7,
     150,   156,    49,    52,    55,    57,   191,     6,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,     6,   149,   154,   154,   151,   154,   183,
     149,   140,   154,   156,   149,   149,   231,   149,   156,   149,
     149,   231,   156,   149,   149,     7,   231,   231,   231,   231,
       7,     7,   223,   223,   231,   148,   148,   148,   148,   231,
     231,   231,     7,   155,   149,     6,   154,   154,   154,   233,
     233,   197,   197,   154,   231,   231,   231,   231,   209,   154,
     198,   231,   231,   231,   231,   231,     7,   224,     7,   231,
       6,   231,   231,   156,   239,   239,   231,   231,   151,   155,
     231,     4,   231,   239,   156,   231,   155,   231,   238,   149,
     149,   149,   103,   154,   198,   155,     8,   149,   151,   156,
     156,   154,   156,   231,   151,   181,   231,     4,    93,    94,
      95,    96,   156,   168,   172,   175,   177,   178,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     154,   154,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   154,   154,   154,   154,   154,   154,
     150,   152,   149,   154,   154,   149,   149,     6,   154,   149,
     154,   236,   156,   152,   180,   181,   244,   231,     6,     4,
       4,   155,   241,   151,   155,   155,   155,   155,     8,     6,
     135,   162,   239,   231,     6,     4,     7,   231,   238,   106,
       7,     7,   149,     7,   106,     7,     7,   149,   106,     7,
       7,   231,   149,   156,   149,   149,   231,   236,     4,   222,
       6,   149,   188,   231,   244,   188,   188,   188,   149,   149,
     149,   236,   239,   152,   233,   231,   231,   156,   156,   231,
     154,   154,   154,    70,    79,    85,    86,    89,    90,   219,
     220,   233,   156,   206,   149,   156,   149,   149,   149,   231,
       6,   231,   149,   151,   151,   156,   156,   151,   151,   239,
     151,   151,   156,   156,     8,   239,     7,     7,     7,   152,
     231,   156,   231,   231,     7,   152,   236,     6,   151,   152,
     181,   243,   156,   169,   148,   148,   155,   179,     6,   231,
     231,   231,   231,   231,   231,   231,   231,   231,     4,   239,
     243,   231,   243,     6,   151,     4,   103,   104,   231,     6,
       6,     6,     7,   150,   240,   242,     6,   239,   239,   239,
     239,   231,   135,   243,   149,   154,     7,   233,    55,   236,
     236,     7,   236,    55,    57,   236,   236,     7,    57,   236,
     236,     6,     7,     7,     7,     7,    70,   221,     6,     7,
     149,   149,   149,   149,     7,     7,     7,     6,   156,     4,
     154,   154,   154,   156,   233,   233,   233,     4,     6,   155,
     148,     6,    91,     6,    91,   156,   220,   154,   219,     7,
       6,     7,     7,     7,     6,   155,     6,     6,     6,    55,
       6,     6,   156,   231,   156,   236,   236,   236,     4,   154,
       8,     8,   149,     4,     4,   156,     6,     4,     6,   148,
     231,   231,   235,   236,   155,   149,   151,   149,   151,   149,
     151,   149,   151,   151,   149,   149,   149,   149,   180,     7,
     180,   181,   152,     7,     6,   240,   231,   154,   156,   156,
     156,   156,   156,     6,     6,   162,   231,   155,   231,     6,
     155,    63,   190,   190,   236,     6,   155,   155,     6,     6,
     236,   155,     6,     6,     5,   236,   236,   236,     4,     6,
     236,     7,     7,     7,     7,   236,   236,   236,     7,     6,
       7,   231,   231,   231,   155,   154,   156,   154,   156,   154,
     156,   150,   231,   236,   231,     6,     6,   231,   233,   156,
       5,   155,   236,   155,   155,   155,   236,   239,   155,   151,
       6,     6,   102,   231,   231,   231,     6,     7,     6,   181,
     166,   231,   154,   154,   154,   156,   167,   231,   152,   236,
     244,   231,     6,     4,   241,     6,   151,   240,     6,     6,
       6,     6,   243,   154,   231,   231,   233,     6,     6,     6,
     231,   231,     6,   231,     5,     6,     6,   106,   189,   231,
       6,   236,   236,   236,   236,     6,     4,     6,     6,   231,
     231,   244,   156,   149,   154,   156,   197,   233,     6,   210,
     233,     6,   211,   233,     6,   212,   231,   156,   154,   149,
     156,   154,     6,   139,   233,     6,   235,   233,   233,     6,
     156,   231,   236,   154,   156,     8,   156,   149,   155,   231,
     244,   149,   154,   231,   231,   236,   155,   154,   156,     4,
       6,     6,     6,     7,     6,   152,     6,   231,   185,   156,
     156,   156,   156,     5,    53,     6,     6,     6,     6,     6,
     155,   155,     6,     6,   155,   231,   156,   154,   155,   154,
     155,   154,   155,   151,     6,   236,     7,   155,   231,   154,
     156,   154,   154,     6,   156,   101,   231,   231,   239,     6,
       6,   170,   231,   154,   154,   235,   231,     6,   240,   104,
     154,   186,     6,     6,     6,     6,     6,   155,   235,   239,
     197,   154,   156,   231,   233,   219,   231,   233,   219,   231,
     233,   219,     6,   154,   156,   236,   198,   156,   233,     6,
     239,   233,   231,   156,   156,   156,   155,   231,   231,   156,
       6,   231,   154,   156,   187,   231,   156,   156,   156,   231,
     156,   154,   156,   156,   154,   156,   156,   154,   156,   236,
       6,    70,   156,   207,   155,   154,   156,   154,     6,     6,
     167,   149,   154,     6,   155,   154,     4,   156,     6,     6,
     156,     6,   213,   231,     6,     6,   214,   231,     6,     6,
     215,   231,     6,   156,   231,   219,   198,   239,     6,   233,
     239,   156,   173,   231,   235,   231,     5,   236,   155,   156,
     155,   156,   155,   156,     6,     6,   156,   156,   208,   156,
     154,   156,     6,   155,   149,   156,   156,   219,     6,   216,
     219,     6,   217,   219,     6,   218,   219,     6,   239,     6,
     171,   243,   176,   155,     6,   156,   155,   156,   155,   156,
     155,   156,   156,   154,   156,   155,   235,     6,   219,     6,
     219,     6,   219,     6,   243,     6,   174,   243,   156,   156,
     156,   156,   154,   156,     6,     6,     6,     6,   243,     6
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
#line 159 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 171 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 172 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 173 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 174 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 195 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 202 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 207 "Gmsh.y"
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

  case 27:

/* Line 1464 of yacc.c  */
#line 221 "Gmsh.y"
    {
      char tmpstring[1024];
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

  case 28:

/* Line 1464 of yacc.c  */
#line 234 "Gmsh.y"
    {
      char tmpstring[1024];
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

  case 29:

/* Line 1464 of yacc.c  */
#line 262 "Gmsh.y"
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

  case 30:

/* Line 1464 of yacc.c  */
#line 276 "Gmsh.y"
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

  case 31:

/* Line 1464 of yacc.c  */
#line 287 "Gmsh.y"
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

  case 32:

/* Line 1464 of yacc.c  */
#line 301 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 315 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 317 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 322 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 324 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 329 "Gmsh.y"
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

  case 43:

/* Line 1464 of yacc.c  */
#line 433 "Gmsh.y"
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

  case 44:

/* Line 1464 of yacc.c  */
#line 443 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 452 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 459 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 469 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 478 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 487 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 494 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 522 "Gmsh.y"
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

  case 54:

/* Line 1464 of yacc.c  */
#line 541 "Gmsh.y"
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

  case 55:

/* Line 1464 of yacc.c  */
#line 560 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 566 "Gmsh.y"
    {
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 573 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 574 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 575 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 576 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 577 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 581 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 582 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 591 "Gmsh.y"
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

  case 66:

/* Line 1464 of yacc.c  */
#line 654 "Gmsh.y"
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

  case 67:

/* Line 1464 of yacc.c  */
#line 684 "Gmsh.y"
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

  case 68:

/* Line 1464 of yacc.c  */
#line 717 "Gmsh.y"
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

  case 69:

/* Line 1464 of yacc.c  */
#line 763 "Gmsh.y"
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

  case 70:

/* Line 1464 of yacc.c  */
#line 778 "Gmsh.y"
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

  case 71:

/* Line 1464 of yacc.c  */
#line 794 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 803 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 809 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 818 "Gmsh.y"
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

  case 75:

/* Line 1464 of yacc.c  */
#line 836 "Gmsh.y"
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

  case 76:

/* Line 1464 of yacc.c  */
#line 854 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 863 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 875 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 880 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 888 "Gmsh.y"
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

  case 81:

/* Line 1464 of yacc.c  */
#line 908 "Gmsh.y"
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

  case 82:

/* Line 1464 of yacc.c  */
#line 931 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->boundaryLayer_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 942 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 950 "Gmsh.y"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 972 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string() = (yyvsp[(8) - (9)].c); }
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

  case 86:

/* Line 1464 of yacc.c  */
#line 995 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  std::list<int> &vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	    double id;
	    List_Read((yyvsp[(9) - (11)].l), i, &id);
	    vl.push_back((int)id);
	  }
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

  case 87:

/* Line 1464 of yacc.c  */
#line 1023 "Gmsh.y"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 1035 "Gmsh.y"
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

  case 92:

/* Line 1464 of yacc.c  */
#line 1053 "Gmsh.y"
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

  case 93:

/* Line 1464 of yacc.c  */
#line 1064 "Gmsh.y"
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

  case 94:

/* Line 1464 of yacc.c  */
#line 1075 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1077 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
    ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1093 "Gmsh.y"
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

  case 99:

/* Line 1464 of yacc.c  */
#line 1104 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1117 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1121 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1131 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1135 "Gmsh.y"
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

  case 104:

/* Line 1464 of yacc.c  */
#line 1147 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1151 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1161 "Gmsh.y"
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

  case 107:

/* Line 1464 of yacc.c  */
#line 1184 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1188 "Gmsh.y"
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

  case 109:

/* Line 1464 of yacc.c  */
#line 1204 "Gmsh.y"
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

  case 110:

/* Line 1464 of yacc.c  */
#line 1226 "Gmsh.y"
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

  case 111:

/* Line 1464 of yacc.c  */
#line 1244 "Gmsh.y"
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

  case 112:

/* Line 1464 of yacc.c  */
#line 1265 "Gmsh.y"
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

  case 113:

/* Line 1464 of yacc.c  */
#line 1283 "Gmsh.y"
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

  case 114:

/* Line 1464 of yacc.c  */
#line 1313 "Gmsh.y"
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

  case 115:

/* Line 1464 of yacc.c  */
#line 1343 "Gmsh.y"
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

  case 116:

/* Line 1464 of yacc.c  */
#line 1361 "Gmsh.y"
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

  case 117:

/* Line 1464 of yacc.c  */
#line 1379 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1405 "Gmsh.y"
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

  case 119:

/* Line 1464 of yacc.c  */
#line 1423 "Gmsh.y"
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

  case 120:

/* Line 1464 of yacc.c  */
#line 1441 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1445 "Gmsh.y"
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

  case 122:

/* Line 1464 of yacc.c  */
#line 1464 "Gmsh.y"
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

  case 123:

/* Line 1464 of yacc.c  */
#line 1482 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1521 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1527 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1533 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1540 "Gmsh.y"
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

  case 128:

/* Line 1464 of yacc.c  */
#line 1565 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1590 "Gmsh.y"
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

  case 130:

/* Line 1464 of yacc.c  */
#line 1607 "Gmsh.y"
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

  case 131:

/* Line 1464 of yacc.c  */
#line 1625 "Gmsh.y"
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

  case 132:

/* Line 1464 of yacc.c  */
#line 1655 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1659 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1679 "Gmsh.y"
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

  case 135:

/* Line 1464 of yacc.c  */
#line 1697 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1714 "Gmsh.y"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1730 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1734 "Gmsh.y"
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

  case 139:

/* Line 1464 of yacc.c  */
#line 1756 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1761 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1766 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1771 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1776 "Gmsh.y"
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

  case 144:

/* Line 1464 of yacc.c  */
#line 1799 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1805 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1815 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1816 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1821 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1825 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1829 "Gmsh.y"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1852 "Gmsh.y"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1875 "Gmsh.y"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 1898 "Gmsh.y"
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

  case 154:

/* Line 1464 of yacc.c  */
#line 1926 "Gmsh.y"
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

  case 155:

/* Line 1464 of yacc.c  */
#line 1947 "Gmsh.y"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 1971 "Gmsh.y"
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

  case 157:

/* Line 1464 of yacc.c  */
#line 1992 "Gmsh.y"
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

  case 158:

/* Line 1464 of yacc.c  */
#line 2013 "Gmsh.y"
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

  case 159:

/* Line 1464 of yacc.c  */
#line 2033 "Gmsh.y"
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

  case 160:

/* Line 1464 of yacc.c  */
#line 2145 "Gmsh.y"
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

  case 161:

/* Line 1464 of yacc.c  */
#line 2164 "Gmsh.y"
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

  case 162:

/* Line 1464 of yacc.c  */
#line 2203 "Gmsh.y"
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

  case 163:

/* Line 1464 of yacc.c  */
#line 2311 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2320 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2326 "Gmsh.y"
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

  case 166:

/* Line 1464 of yacc.c  */
#line 2341 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2369 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2386 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 2400 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2406 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2412 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2421 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 2435 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	Msg::StatusBar(2, true, "Reading '%s'...", tmp.c_str());
	ParseFile(tmp, false, true);
	SetBoundingBox();
	Msg::StatusBar(2, true, "Done reading '%s'", tmp.c_str());
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "System"))
	SystemCall((yyvsp[(2) - (3)].c));
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName"))
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2477 "Gmsh.y"
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

  case 175:

/* Line 1464 of yacc.c  */
#line 2494 "Gmsh.y"
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

  case 176:

/* Line 1464 of yacc.c  */
#line 2509 "Gmsh.y"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 2528 "Gmsh.y"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 2540 "Gmsh.y"
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

  case 179:

/* Line 1464 of yacc.c  */
#line 2564 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 2568 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 2575 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2581 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2586 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 2592 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2596 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2600 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2610 "Gmsh.y"
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

  case 188:

/* Line 1464 of yacc.c  */
#line 2627 "Gmsh.y"
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

  case 189:

/* Line 1464 of yacc.c  */
#line 2644 "Gmsh.y"
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

  case 190:

/* Line 1464 of yacc.c  */
#line 2665 "Gmsh.y"
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

  case 191:

/* Line 1464 of yacc.c  */
#line 2686 "Gmsh.y"
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

  case 192:

/* Line 1464 of yacc.c  */
#line 2721 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 2729 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2735 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2742 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 2746 "Gmsh.y"
    {
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2755 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2763 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2771 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2779 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2784 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2792 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2797 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2805 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2810 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2818 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2823 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2831 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2838 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2845 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2852 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2859 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2866 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2873 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2880 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2887 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2894 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2899 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2906 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2911 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2918 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2923 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2930 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2935 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2942 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2947 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2954 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2959 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 2966 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 2978 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 2983 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 2990 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 2995 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3006 "Gmsh.y"
    {
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3009 "Gmsh.y"
    {
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3024 "Gmsh.y"
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

  case 239:

/* Line 1464 of yacc.c  */
#line 3044 "Gmsh.y"
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

  case 240:

/* Line 1464 of yacc.c  */
#line 3067 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3071 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3075 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3079 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3083 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3087 "Gmsh.y"
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

  case 246:

/* Line 1464 of yacc.c  */
#line 3106 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3118 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3122 "Gmsh.y"
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

  case 249:

/* Line 1464 of yacc.c  */
#line 3137 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3141 "Gmsh.y"
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

  case 251:

/* Line 1464 of yacc.c  */
#line 3153 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3157 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3162 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3166 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3173 "Gmsh.y"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 3229 "Gmsh.y"
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

  case 257:

/* Line 1464 of yacc.c  */
#line 3299 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3304 "Gmsh.y"
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

  case 259:

/* Line 1464 of yacc.c  */
#line 3371 "Gmsh.y"
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

  case 260:

/* Line 1464 of yacc.c  */
#line 3407 "Gmsh.y"
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

  case 261:

/* Line 1464 of yacc.c  */
#line 3450 "Gmsh.y"
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

  case 262:

/* Line 1464 of yacc.c  */
#line 3475 "Gmsh.y"
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
            c_slave->meshMaster = j_master;
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

  case 263:

/* Line 1464 of yacc.c  */
#line 3503 "Gmsh.y"
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
          s_slave->meshMaster = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (12)].l), i, &ds);
            List_Read((yyvsp[(10) - (12)].l), i, &dm);
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
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 3546 "Gmsh.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 3569 "Gmsh.y"
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

  case 266:

/* Line 1464 of yacc.c  */
#line 3592 "Gmsh.y"
    {
    ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 3595 "Gmsh.y"
    {
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3604 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3608 "Gmsh.y"
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

  case 270:

/* Line 1464 of yacc.c  */
#line 3618 "Gmsh.y"
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

  case 271:

/* Line 1464 of yacc.c  */
#line 3652 "Gmsh.y"
    { (yyval.c) = (char*)"Generators"; ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3653 "Gmsh.y"
    { (yyval.c) = (char*)"DualGenerators"; ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3658 "Gmsh.y"
    {
      std::vector<int> domain, subdomain;
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain);
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3663 "Gmsh.y"
    {
      std::vector<int> domain, subdomain;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain);
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3674 "Gmsh.y"
    {
      std::vector<int> domain, subdomain;
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
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3695 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3696 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3697 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3698 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3699 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3700 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3701 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3702 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3704 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3710 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3711 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3712 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3713 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3714 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3715 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3716 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3717 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3718 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3719 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3720 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3721 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3722 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3723 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3724 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3725 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3726 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3727 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3728 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3729 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3730 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3731 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3732 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3733 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3734 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3735 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3736 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3737 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3738 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3739 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3740 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3741 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3743 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3744 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3745 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3746 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3747 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3748 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3749 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3750 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3751 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3752 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3753 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3754 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3755 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3756 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3757 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3758 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3759 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3760 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3761 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3762 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3763 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3772 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3773 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3774 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3775 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3776 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3777 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3778 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3783 "Gmsh.y"
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

  case 346:

/* Line 1464 of yacc.c  */
#line 3803 "Gmsh.y"
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

  case 347:

/* Line 1464 of yacc.c  */
#line 3822 "Gmsh.y"
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

  case 348:

/* Line 1464 of yacc.c  */
#line 3840 "Gmsh.y"
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

  case 349:

/* Line 1464 of yacc.c  */
#line 3852 "Gmsh.y"
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

  case 350:

/* Line 1464 of yacc.c  */
#line 3869 "Gmsh.y"
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

  case 351:

/* Line 1464 of yacc.c  */
#line 3890 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3895 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3900 "Gmsh.y"
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

  case 354:

/* Line 1464 of yacc.c  */
#line 3910 "Gmsh.y"
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

  case 355:

/* Line 1464 of yacc.c  */
#line 3920 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 3928 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 3932 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 3936 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3940 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3944 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3951 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3955 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3959 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 3963 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 3970 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 3975 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 3982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 3987 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 3991 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 3996 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4000 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4008 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4019 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4023 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4035 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4051 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d) || ((yyvsp[(1) - (5)].d) < (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) < 0) || ((yyvsp[(1) - (5)].d) > (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) > 0)){
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
	List_Add((yyval.l), &((yyvsp[(1) - (5)].d)));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
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

  case 380:

/* Line 1464 of yacc.c  */
#line 4089 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4093 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4097 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4101 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4105 "Gmsh.y"
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

  case 385:

/* Line 1464 of yacc.c  */
#line 4115 "Gmsh.y"
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

  case 386:

/* Line 1464 of yacc.c  */
#line 4125 "Gmsh.y"
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

  case 387:

/* Line 1464 of yacc.c  */
#line 4137 "Gmsh.y"
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

  case 388:

/* Line 1464 of yacc.c  */
#line 4149 "Gmsh.y"
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

  case 389:

/* Line 1464 of yacc.c  */
#line 4170 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4175 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4179 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4183 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4195 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4199 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4211 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4218 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4228 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4232 "Gmsh.y"
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

  case 399:

/* Line 1464 of yacc.c  */
#line 4247 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4252 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4259 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4263 "Gmsh.y"
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

  case 403:

/* Line 1464 of yacc.c  */
#line 4276 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4284 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4295 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4299 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4307 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4315 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4323 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4331 "Gmsh.y"
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

  case 411:

/* Line 1464 of yacc.c  */
#line 4345 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4359 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 4363 "Gmsh.y"
    {
      char tmpstring[1024];
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



/* Line 1464 of yacc.c  */
#line 9983 "Gmsh.tab.cpp"
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
#line 4383 "Gmsh.y"


int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  int j, k;
  char tmp1[256], tmp2[256];

  j = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j);
  buffer[j]='\0';
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
      return List_Nbr(list)-i;
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

