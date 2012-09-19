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

struct doubleXstring{
  double d;
  char *s;
};



/* Line 189 of yacc.c  */
#line 172 "Gmsh.tab.cpp"

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
     tMeshAlgorithm = 340,
     tLayers = 341,
     tHole = 342,
     tAlias = 343,
     tAliasWithOptions = 344,
     tQuadTriDbl = 345,
     tQuadTriSngl = 346,
     tRecombLaterals = 347,
     tTransfQuadTri = 348,
     tText2D = 349,
     tText3D = 350,
     tInterpolationScheme = 351,
     tTime = 352,
     tCombine = 353,
     tBSpline = 354,
     tBezier = 355,
     tNurbs = 356,
     tNurbsOrder = 357,
     tNurbsKnots = 358,
     tColor = 359,
     tColorTable = 360,
     tFor = 361,
     tIn = 362,
     tEndFor = 363,
     tIf = 364,
     tEndIf = 365,
     tExit = 366,
     tField = 367,
     tReturn = 368,
     tCall = 369,
     tFunction = 370,
     tShow = 371,
     tHide = 372,
     tGetValue = 373,
     tGetEnv = 374,
     tGetString = 375,
     tHomology = 376,
     tCohomology = 377,
     tGMSH_MAJOR_VERSION = 378,
     tGMSH_MINOR_VERSION = 379,
     tGMSH_PATCH_VERSION = 380,
     tAFFECTDIVIDE = 381,
     tAFFECTTIMES = 382,
     tAFFECTMINUS = 383,
     tAFFECTPLUS = 384,
     tOR = 385,
     tAND = 386,
     tNOTEQUAL = 387,
     tEQUAL = 388,
     tGREATEROREQUAL = 389,
     tLESSOREQUAL = 390,
     UNARYPREC = 391,
     tMINUSMINUS = 392,
     tPLUSPLUS = 393
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 92 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 214 of yacc.c  */
#line 358 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 370 "Gmsh.tab.cpp"

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
#define YYLAST   7639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  420
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1452

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   393

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,     2,   154,     2,   143,     2,     2,
     149,   150,   141,   139,   155,   140,   153,   142,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     135,     2,   136,   130,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   151,     2,   152,   148,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   156,     2,   157,   158,     2,     2,     2,
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
     125,   126,   127,   128,   129,   131,   132,   133,   134,   137,
     138,   145,   146,   147
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
     357,   364,   374,   380,   388,   398,   408,   420,   428,   438,
     448,   449,   451,   452,   456,   462,   463,   473,   477,   483,
     484,   487,   491,   497,   501,   503,   505,   506,   512,   513,
     516,   524,   525,   535,   542,   550,   555,   563,   572,   581,
     589,   597,   609,   618,   627,   628,   638,   647,   657,   661,
     666,   677,   685,   693,   702,   711,   724,   725,   735,   744,
     752,   761,   762,   772,   778,   790,   796,   806,   816,   821,
     831,   841,   843,   845,   846,   849,   856,   863,   870,   877,
     886,   897,   912,   929,   942,   951,   960,   967,   982,   987,
     994,  1001,  1005,  1010,  1016,  1020,  1024,  1029,  1034,  1038,
    1046,  1054,  1058,  1066,  1070,  1073,  1076,  1079,  1095,  1098,
    1101,  1104,  1107,  1114,  1123,  1132,  1143,  1145,  1148,  1150,
    1154,  1159,  1161,  1167,  1179,  1193,  1194,  1202,  1203,  1217,
    1218,  1234,  1235,  1242,  1251,  1260,  1269,  1282,  1295,  1308,
    1323,  1338,  1353,  1354,  1367,  1368,  1381,  1382,  1395,  1396,
    1413,  1414,  1431,  1432,  1449,  1450,  1469,  1470,  1489,  1490,
    1509,  1511,  1514,  1520,  1528,  1538,  1541,  1544,  1548,  1551,
    1555,  1565,  1572,  1573,  1577,  1578,  1580,  1581,  1584,  1585,
    1588,  1596,  1603,  1612,  1618,  1622,  1630,  1636,  1643,  1650,
    1663,  1674,  1685,  1696,  1707,  1710,  1714,  1721,  1723,  1725,
    1728,  1734,  1742,  1753,  1755,  1759,  1762,  1765,  1768,  1772,
    1776,  1780,  1784,  1788,  1792,  1796,  1800,  1804,  1808,  1812,
    1816,  1820,  1824,  1830,  1835,  1840,  1845,  1850,  1855,  1860,
    1865,  1870,  1875,  1880,  1887,  1892,  1897,  1902,  1907,  1912,
    1917,  1924,  1931,  1938,  1943,  1948,  1953,  1958,  1963,  1968,
    1973,  1978,  1983,  1988,  1993,  2000,  2005,  2010,  2015,  2020,
    2025,  2030,  2037,  2044,  2051,  2056,  2058,  2060,  2062,  2064,
    2066,  2068,  2070,  2072,  2078,  2083,  2088,  2091,  2097,  2101,
    2108,  2113,  2121,  2128,  2130,  2133,  2136,  2140,  2144,  2156,
    2166,  2174,  2182,  2184,  2188,  2190,  2192,  2195,  2199,  2204,
    2210,  2212,  2214,  2217,  2221,  2225,  2231,  2236,  2239,  2242,
    2245,  2248,  2250,  2252,  2256,  2261,  2268,  2270,  2272,  2276,
    2280,  2290,  2298,  2300,  2306,  2310,  2317,  2319,  2323,  2325,
    2327,  2331,  2338,  2340,  2342,  2347,  2354,  2361,  2366,  2371,
    2376
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,   161,    -1,     1,     6,    -1,    -1,   161,
     162,    -1,   165,    -1,   164,    -1,   183,    -1,   193,    -1,
     198,    -1,   202,    -1,   203,    -1,   204,    -1,   207,    -1,
     227,    -1,   228,    -1,   229,    -1,   230,    -1,   206,    -1,
     205,    -1,   201,    -1,   232,    -1,   136,    -1,   136,   136,
      -1,    36,   149,     5,   150,     6,    -1,    36,   149,     5,
     150,   163,   245,     6,    -1,    36,   149,     5,   155,   241,
     150,     6,    -1,    36,   149,     5,   155,   241,   150,   163,
     245,     6,    -1,     4,     5,   156,   166,   157,     6,    -1,
      88,     4,   151,   233,   152,     6,    -1,    89,     4,   151,
     233,   152,     6,    -1,    -1,   166,   169,    -1,   166,   173,
      -1,   166,   176,    -1,   166,   178,    -1,   166,   179,    -1,
     233,    -1,   167,   155,   233,    -1,   233,    -1,   168,   155,
     233,    -1,    -1,    -1,     4,   170,   149,   167,   150,   171,
     156,   168,   157,     6,    -1,   245,    -1,   172,   155,   245,
      -1,    -1,    94,   149,   233,   155,   233,   155,   233,   150,
     174,   156,   172,   157,     6,    -1,   245,    -1,   175,   155,
     245,    -1,    -1,    95,   149,   233,   155,   233,   155,   233,
     155,   233,   150,   177,   156,   175,   157,     6,    -1,    96,
     156,   237,   157,   156,   237,   157,     6,    -1,    96,   156,
     237,   157,   156,   237,   157,   156,   237,   157,   156,   237,
     157,     6,    -1,    -1,    97,   180,   156,   168,   157,     6,
      -1,     7,    -1,   129,    -1,   128,    -1,   127,    -1,   126,
      -1,   147,    -1,   146,    -1,    48,   151,   185,   152,     6,
      -1,     4,   181,   238,     6,    -1,     4,   151,   152,   181,
     238,     6,    -1,     4,   151,   233,   152,   181,   233,     6,
      -1,     4,   151,   156,   241,   157,   152,   181,   238,     6,
      -1,     4,   182,     6,    -1,     4,   151,   233,   152,   182,
       6,    -1,     4,     7,   246,     6,    -1,     4,   153,     4,
       7,   246,     6,    -1,     4,   151,   233,   152,   153,     4,
       7,   246,     6,    -1,     4,   153,     4,   181,   233,     6,
      -1,     4,   151,   233,   152,   153,     4,   181,   233,     6,
      -1,     4,   153,     4,   182,     6,    -1,     4,   151,   233,
     152,   153,     4,   182,     6,    -1,     4,   153,   104,   153,
       4,     7,   242,     6,    -1,     4,   151,   233,   152,   153,
     104,   153,     4,     7,   242,     6,    -1,     4,   153,   105,
       7,   243,     6,    -1,     4,   151,   233,   152,   153,   105,
       7,   243,     6,    -1,     4,   112,     7,   233,     6,    -1,
     112,   151,   233,   152,     7,     4,     6,    -1,   112,   151,
     233,   152,   153,     4,     7,   233,     6,    -1,   112,   151,
     233,   152,   153,     4,     7,   246,     6,    -1,   112,   151,
     233,   152,   153,     4,     7,   156,   241,   157,     6,    -1,
     112,   151,   233,   152,   153,     4,     6,    -1,    71,   149,
       4,   150,   153,     4,     7,   233,     6,    -1,    71,   149,
       4,   150,   153,     4,     7,   246,     6,    -1,    -1,   155,
      -1,    -1,   185,   184,     4,    -1,   185,   184,     4,     7,
     233,    -1,    -1,   185,   184,     4,     7,   156,   233,   186,
     188,   157,    -1,   233,     7,   246,    -1,   187,   155,   233,
       7,   246,    -1,    -1,   188,   189,    -1,   155,     4,   238,
      -1,   155,     4,   156,   187,   157,    -1,   155,     4,     5,
      -1,   233,    -1,   246,    -1,    -1,   107,    53,   156,   233,
     157,    -1,    -1,    63,   235,    -1,    49,   149,   233,   150,
       7,   235,     6,    -1,    -1,    67,    49,   194,   149,   190,
     150,     7,   238,     6,    -1,    58,    59,   238,     7,   233,
       6,    -1,    52,   149,   233,   150,     7,   238,     6,    -1,
      72,    52,   238,     6,    -1,    56,   149,   233,   150,     7,
     238,     6,    -1,    50,   149,   233,   150,     7,   238,   192,
       6,    -1,    51,   149,   233,   150,     7,   238,   192,     6,
      -1,    99,   149,   233,   150,     7,   238,     6,    -1,   100,
     149,   233,   150,     7,   238,     6,    -1,   101,   149,   233,
     150,     7,   238,   103,   238,   102,   233,     6,    -1,    52,
       4,   149,   233,   150,     7,   238,     6,    -1,    68,    52,
     149,   233,   150,     7,   238,     6,    -1,    -1,    67,    52,
     195,   149,   190,   150,     7,   238,     6,    -1,    63,    55,
     149,   233,   150,     7,   238,     6,    -1,    64,    55,   149,
     233,   150,     7,   238,   191,     6,    -1,    12,    13,     6,
      -1,    13,    55,   233,     6,    -1,    60,    55,   149,   233,
     150,     7,     5,     5,     5,     6,    -1,    53,   149,   233,
     150,     7,   238,     6,    -1,    54,   149,   233,   150,     7,
     238,     6,    -1,    55,     4,   149,   233,   150,     7,   238,
       6,    -1,    68,    55,   149,   233,   150,     7,   238,     6,
      -1,    68,    55,   149,   233,   150,     7,   238,     4,   156,
     237,   157,     6,    -1,    -1,    67,    55,   196,   149,   190,
     150,     7,   238,     6,    -1,    66,    57,   149,   233,   150,
       7,   238,     6,    -1,    57,   149,   233,   150,     7,   238,
       6,    -1,    68,    57,   149,   233,   150,     7,   238,     6,
      -1,    -1,    67,    57,   197,   149,   190,   150,     7,   238,
       6,    -1,    74,   235,   156,   199,   157,    -1,    73,   156,
     235,   155,   235,   155,   233,   157,   156,   199,   157,    -1,
      75,   235,   156,   199,   157,    -1,    76,   156,   235,   155,
     233,   157,   156,   199,   157,    -1,    76,   156,   235,   155,
     235,   157,   156,   199,   157,    -1,     4,   156,   199,   157,
      -1,    84,    52,   156,   241,   157,    55,   156,   233,   157,
      -1,    81,    52,   149,   233,   150,   156,   241,   157,     6,
      -1,   200,    -1,   198,    -1,    -1,   200,   193,    -1,   200,
      49,   156,   241,   157,     6,    -1,   200,    52,   156,   241,
     157,     6,    -1,   200,    55,   156,   241,   157,     6,    -1,
     200,    57,   156,   241,   157,     6,    -1,    78,    63,   149,
     233,   150,     7,   238,     6,    -1,    78,    49,   149,   233,
     150,     7,   156,   237,   157,     6,    -1,    78,    63,   149,
     233,   150,     7,   156,   235,   155,   235,   155,   241,   157,
       6,    -1,    78,    63,   149,   233,   150,     7,   156,   235,
     155,   235,   155,   235,   155,   241,   157,     6,    -1,    78,
      53,   149,   233,   150,     7,   156,   235,   155,   241,   157,
       6,    -1,    78,     4,   149,   233,   150,     7,   238,     6,
      -1,    78,     4,   149,   233,   150,     7,     5,     6,    -1,
      78,     4,   156,   233,   157,     6,    -1,    78,     4,   149,
     233,   150,     7,   156,   235,   155,   235,   155,   241,   157,
       6,    -1,    82,   156,   200,   157,    -1,    82,   112,   151,
     233,   152,     6,    -1,    82,     4,   151,   233,   152,     6,
      -1,    82,     4,     6,    -1,    82,     4,     4,     6,    -1,
     104,   242,   156,   200,   157,    -1,   116,     5,     6,    -1,
     117,     5,     6,    -1,   116,   156,   200,   157,    -1,   117,
     156,   200,   157,    -1,     4,   246,     6,    -1,     4,     4,
     151,   233,   152,   245,     6,    -1,     4,     4,     4,   151,
     233,   152,     6,    -1,     4,   233,     6,    -1,    71,   149,
       4,   150,   153,     4,     6,    -1,    98,     4,     6,    -1,
     111,     6,    -1,    44,     6,    -1,    41,     6,    -1,    41,
     156,   233,   155,   233,   155,   233,   155,   233,   155,   233,
     155,   233,   157,     6,    -1,    42,     6,    -1,    45,     6,
      -1,    46,     6,    -1,    62,     6,    -1,   106,   149,   233,
       8,   233,   150,    -1,   106,   149,   233,     8,   233,     8,
     233,   150,    -1,   106,     4,   107,   156,   233,     8,   233,
     157,    -1,   106,     4,   107,   156,   233,     8,   233,     8,
     233,   157,    -1,   108,    -1,   115,     4,    -1,   113,    -1,
     114,     4,     6,    -1,   109,   149,   233,   150,    -1,   110,
      -1,    77,   235,   156,   200,   157,    -1,    77,   156,   235,
     155,   235,   155,   233,   157,   156,   200,   157,    -1,    77,
     156,   235,   155,   235,   155,   235,   155,   233,   157,   156,
     200,   157,    -1,    -1,    77,   235,   156,   200,   208,   221,
     157,    -1,    -1,    77,   156,   235,   155,   235,   155,   233,
     157,   156,   200,   209,   221,   157,    -1,    -1,    77,   156,
     235,   155,   235,   155,   235,   155,   233,   157,   156,   200,
     210,   221,   157,    -1,    -1,    77,   156,   200,   211,   221,
     157,    -1,    77,    49,   156,   233,   155,   235,   157,     6,
      -1,    77,    52,   156,   233,   155,   235,   157,     6,    -1,
      77,    55,   156,   233,   155,   235,   157,     6,    -1,    77,
      49,   156,   233,   155,   235,   155,   235,   155,   233,   157,
       6,    -1,    77,    52,   156,   233,   155,   235,   155,   235,
     155,   233,   157,     6,    -1,    77,    55,   156,   233,   155,
     235,   155,   235,   155,   233,   157,     6,    -1,    77,    49,
     156,   233,   155,   235,   155,   235,   155,   235,   155,   233,
     157,     6,    -1,    77,    52,   156,   233,   155,   235,   155,
     235,   155,   235,   155,   233,   157,     6,    -1,    77,    55,
     156,   233,   155,   235,   155,   235,   155,   235,   155,   233,
     157,     6,    -1,    -1,    77,    49,   156,   233,   155,   235,
     157,   212,   156,   221,   157,     6,    -1,    -1,    77,    52,
     156,   233,   155,   235,   157,   213,   156,   221,   157,     6,
      -1,    -1,    77,    55,   156,   233,   155,   235,   157,   214,
     156,   221,   157,     6,    -1,    -1,    77,    49,   156,   233,
     155,   235,   155,   235,   155,   233,   157,   215,   156,   221,
     157,     6,    -1,    -1,    77,    52,   156,   233,   155,   235,
     155,   235,   155,   233,   157,   216,   156,   221,   157,     6,
      -1,    -1,    77,    55,   156,   233,   155,   235,   155,   235,
     155,   233,   157,   217,   156,   221,   157,     6,    -1,    -1,
      77,    49,   156,   233,   155,   235,   155,   235,   155,   235,
     155,   233,   157,   218,   156,   221,   157,     6,    -1,    -1,
      77,    52,   156,   233,   155,   235,   155,   235,   155,   235,
     155,   233,   157,   219,   156,   221,   157,     6,    -1,    -1,
      77,    55,   156,   233,   155,   235,   155,   235,   155,   235,
     155,   233,   157,   220,   156,   221,   157,     6,    -1,   222,
      -1,   221,   222,    -1,    86,   156,   233,   157,     6,    -1,
      86,   156,   238,   155,   238,   157,     6,    -1,    86,   156,
     238,   155,   238,   155,   238,   157,     6,    -1,    79,     6,
      -1,    90,     6,    -1,    90,    92,     6,    -1,    91,     6,
      -1,    91,    92,     6,    -1,    87,   149,   233,   150,     7,
     238,    70,   233,     6,    -1,    70,     4,   151,   233,   152,
       6,    -1,    -1,    70,     4,   233,    -1,    -1,     4,    -1,
      -1,     7,   238,    -1,    -1,     7,   233,    -1,    65,    52,
     239,     7,   233,   223,     6,    -1,    65,    55,   239,   225,
     224,     6,    -1,    61,    55,   156,   233,   157,     7,   238,
       6,    -1,    65,    57,   239,   225,     6,    -1,    93,   239,
       6,    -1,    85,    55,   156,   241,   157,   233,     6,    -1,
      79,    55,   239,   226,     6,    -1,    80,    55,   238,     7,
     233,     6,    -1,    69,    52,   238,     7,   238,     6,    -1,
      69,    55,   233,   156,   241,   157,     7,   233,   156,   241,
     157,     6,    -1,    49,   156,   241,   157,   107,    55,   156,
     233,   157,     6,    -1,    52,   156,   241,   157,   107,    55,
     156,   233,   157,     6,    -1,    52,   156,   241,   157,   107,
      57,   156,   233,   157,     6,    -1,    55,   156,   241,   157,
     107,    57,   156,   233,   157,     6,    -1,    83,     6,    -1,
      83,     4,     6,    -1,    83,    49,   156,   241,   157,     6,
      -1,   121,    -1,   122,    -1,   231,     6,    -1,   231,   156,
     238,   157,     6,    -1,   231,   156,   238,   155,   238,   157,
       6,    -1,   231,   149,   238,   150,   156,   238,   155,   238,
     157,     6,    -1,   234,    -1,   149,   233,   150,    -1,   140,
     233,    -1,   139,   233,    -1,   144,   233,    -1,   233,   140,
     233,    -1,   233,   139,   233,    -1,   233,   141,   233,    -1,
     233,   142,   233,    -1,   233,   143,   233,    -1,   233,   148,
     233,    -1,   233,   135,   233,    -1,   233,   136,   233,    -1,
     233,   138,   233,    -1,   233,   137,   233,    -1,   233,   134,
     233,    -1,   233,   133,   233,    -1,   233,   132,   233,    -1,
     233,   131,   233,    -1,   233,   130,   233,     8,   233,    -1,
      14,   149,   233,   150,    -1,    15,   149,   233,   150,    -1,
      16,   149,   233,   150,    -1,    17,   149,   233,   150,    -1,
      18,   149,   233,   150,    -1,    19,   149,   233,   150,    -1,
      20,   149,   233,   150,    -1,    21,   149,   233,   150,    -1,
      22,   149,   233,   150,    -1,    24,   149,   233,   150,    -1,
      25,   149,   233,   155,   233,   150,    -1,    26,   149,   233,
     150,    -1,    27,   149,   233,   150,    -1,    28,   149,   233,
     150,    -1,    29,   149,   233,   150,    -1,    30,   149,   233,
     150,    -1,    31,   149,   233,   150,    -1,    32,   149,   233,
     155,   233,   150,    -1,    33,   149,   233,   155,   233,   150,
      -1,    34,   149,   233,   155,   233,   150,    -1,    23,   149,
     233,   150,    -1,    14,   151,   233,   152,    -1,    15,   151,
     233,   152,    -1,    16,   151,   233,   152,    -1,    17,   151,
     233,   152,    -1,    18,   151,   233,   152,    -1,    19,   151,
     233,   152,    -1,    20,   151,   233,   152,    -1,    21,   151,
     233,   152,    -1,    22,   151,   233,   152,    -1,    24,   151,
     233,   152,    -1,    25,   151,   233,   155,   233,   152,    -1,
      26,   151,   233,   152,    -1,    27,   151,   233,   152,    -1,
      28,   151,   233,   152,    -1,    29,   151,   233,   152,    -1,
      30,   151,   233,   152,    -1,    31,   151,   233,   152,    -1,
      32,   151,   233,   155,   233,   152,    -1,    33,   151,   233,
     155,   233,   152,    -1,    34,   151,   233,   155,   233,   152,
      -1,    23,   151,   233,   152,    -1,     3,    -1,     9,    -1,
      10,    -1,    11,    -1,   123,    -1,   124,    -1,   125,    -1,
       4,    -1,     4,   158,   156,   233,   157,    -1,     4,   151,
     233,   152,    -1,   154,     4,   151,   152,    -1,     4,   182,
      -1,     4,   151,   233,   152,   182,    -1,     4,   153,     4,
      -1,     4,   151,   233,   152,   153,     4,    -1,     4,   153,
       4,   182,    -1,     4,   151,   233,   152,   153,     4,   182,
      -1,   118,   149,   245,   155,   233,   150,    -1,   236,    -1,
     140,   235,    -1,   139,   235,    -1,   235,   140,   235,    -1,
     235,   139,   235,    -1,   156,   233,   155,   233,   155,   233,
     155,   233,   155,   233,   157,    -1,   156,   233,   155,   233,
     155,   233,   155,   233,   157,    -1,   156,   233,   155,   233,
     155,   233,   157,    -1,   149,   233,   155,   233,   155,   233,
     150,    -1,   238,    -1,   237,   155,   238,    -1,   233,    -1,
     240,    -1,   156,   157,    -1,   156,   241,   157,    -1,   140,
     156,   241,   157,    -1,   233,   141,   156,   241,   157,    -1,
     238,    -1,     5,    -1,   140,   240,    -1,   233,   141,   240,
      -1,   233,     8,   233,    -1,   233,     8,   233,     8,   233,
      -1,    49,   156,   233,   157,    -1,    49,     5,    -1,    52,
       5,    -1,    55,     5,    -1,    57,     5,    -1,   198,    -1,
     207,    -1,     4,   151,   152,    -1,    35,   151,     4,   152,
      -1,     4,   151,   156,   241,   157,   152,    -1,   233,    -1,
     240,    -1,   241,   155,   233,    -1,   241,   155,   240,    -1,
     156,   233,   155,   233,   155,   233,   155,   233,   157,    -1,
     156,   233,   155,   233,   155,   233,   157,    -1,     4,    -1,
       4,   153,   104,   153,     4,    -1,   156,   244,   157,    -1,
       4,   151,   233,   152,   153,   105,    -1,   242,    -1,   244,
     155,   242,    -1,   246,    -1,     4,    -1,     4,   153,     4,
      -1,     4,   151,   233,   152,   153,     4,    -1,     5,    -1,
      43,    -1,   119,   149,   245,   150,    -1,   120,   149,   245,
     155,   245,   150,    -1,    38,   149,   245,   155,   245,   150,
      -1,    39,   149,   245,   150,    -1,    40,   149,   245,   150,
      -1,    37,   149,   245,   150,    -1,    37,   149,   245,   155,
     241,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   164,   169,   171,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   195,   199,   206,   211,   225,   238,   266,
     280,   291,   306,   311,   312,   313,   314,   315,   319,   321,
     326,   328,   334,   438,   333,   456,   463,   474,   473,   491,
     498,   509,   508,   525,   542,   565,   564,   578,   579,   580,
     581,   582,   586,   587,   593,   595,   658,   688,   721,   767,
     782,   798,   807,   813,   822,   840,   858,   867,   879,   884,
     892,   912,   935,   946,   954,   976,   999,  1025,  1046,  1058,
    1072,  1072,  1074,  1076,  1087,  1099,  1098,  1112,  1118,  1125,
    1126,  1130,  1141,  1156,  1169,  1173,  1184,  1187,  1200,  1203,
    1213,  1237,  1236,  1256,  1278,  1296,  1317,  1335,  1365,  1395,
    1413,  1431,  1457,  1475,  1494,  1493,  1516,  1534,  1573,  1579,
    1585,  1592,  1617,  1642,  1659,  1676,  1708,  1707,  1731,  1749,
    1766,  1783,  1782,  1808,  1813,  1818,  1823,  1828,  1833,  1856,
    1862,  1873,  1874,  1879,  1882,  1886,  1909,  1932,  1955,  1983,
    2004,  2027,  2048,  2070,  2090,  2202,  2221,  2259,  2368,  2377,
    2383,  2398,  2426,  2443,  2457,  2463,  2469,  2478,  2492,  2537,
    2554,  2569,  2588,  2600,  2624,  2628,  2635,  2641,  2646,  2652,
    2656,  2660,  2670,  2687,  2704,  2725,  2746,  2781,  2789,  2795,
    2802,  2806,  2815,  2823,  2831,  2840,  2839,  2853,  2852,  2866,
    2865,  2879,  2878,  2891,  2898,  2905,  2912,  2919,  2926,  2933,
    2940,  2947,  2955,  2954,  2967,  2966,  2979,  2978,  2991,  2990,
    3003,  3002,  3015,  3014,  3027,  3026,  3039,  3038,  3051,  3050,
    3066,  3069,  3075,  3084,  3104,  3127,  3131,  3135,  3139,  3143,
    3147,  3166,  3179,  3182,  3198,  3201,  3214,  3217,  3223,  3226,
    3233,  3289,  3359,  3364,  3431,  3467,  3476,  3519,  3544,  3571,
    3615,  3638,  3661,  3664,  3673,  3677,  3687,  3722,  3723,  3727,
    3734,  3747,  3766,  3794,  3795,  3796,  3797,  3798,  3799,  3800,
    3801,  3802,  3809,  3810,  3811,  3812,  3813,  3814,  3815,  3816,
    3817,  3818,  3819,  3820,  3821,  3822,  3823,  3824,  3825,  3826,
    3827,  3828,  3829,  3830,  3831,  3832,  3833,  3834,  3835,  3836,
    3837,  3838,  3839,  3840,  3842,  3843,  3844,  3845,  3846,  3847,
    3848,  3849,  3850,  3851,  3852,  3853,  3854,  3855,  3856,  3857,
    3858,  3859,  3860,  3861,  3862,  3871,  3872,  3873,  3874,  3875,
    3876,  3877,  3881,  3901,  3920,  3938,  3950,  3967,  3988,  3993,
    3998,  4008,  4018,  4026,  4030,  4034,  4038,  4042,  4049,  4053,
    4057,  4061,  4068,  4073,  4080,  4085,  4089,  4094,  4098,  4106,
    4117,  4121,  4133,  4141,  4149,  4156,  4167,  4187,  4191,  4195,
    4199,  4203,  4213,  4223,  4235,  4247,  4268,  4273,  4277,  4281,
    4293,  4297,  4309,  4316,  4326,  4330,  4345,  4350,  4357,  4361,
    4374,  4382,  4393,  4397,  4405,  4413,  4421,  4429,  4443,  4457,
    4461
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
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tLayers", "tHole", "tAlias", "tAliasWithOptions",
  "tQuadTriDbl", "tQuadTriSngl", "tRecombLaterals", "tTransfQuadTri",
  "tText2D", "tText3D", "tInterpolationScheme", "tTime", "tCombine",
  "tBSpline", "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit",
  "tField", "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "Comma", "DefineConstants", "$@6",
  "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "$@7", "$@8",
  "$@9", "$@10", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "ExtrudeParameters", "ExtrudeParameter",
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
      63,   385,   386,   387,   388,    60,    62,   389,   390,    43,
      45,    42,    47,    37,    33,   391,   392,   393,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   159,   160,   160,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   163,   163,   164,   164,   164,   164,   165,
     165,   165,   166,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   170,   171,   169,   172,   172,   174,   173,   175,
     175,   177,   176,   178,   178,   180,   179,   181,   181,   181,
     181,   181,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   184,   185,   185,   185,   186,   185,   187,   187,   188,
     188,   189,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   194,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   195,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   196,   193,   193,   193,
     193,   197,   193,   198,   198,   198,   198,   198,   198,   198,
     198,   199,   199,   200,   200,   200,   200,   200,   200,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   202,   203,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   207,   207,   207,   208,   207,   209,   207,   210,
     207,   211,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   212,   207,   213,   207,   214,   207,   215,   207,
     216,   207,   217,   207,   218,   207,   219,   207,   220,   207,
     221,   221,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   223,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   227,   227,   227,   227,   227,   227,   228,   228,
     229,   229,   229,   229,   230,   230,   230,   231,   231,   232,
     232,   232,   232,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   235,   236,   236,
     236,   236,   237,   237,   238,   238,   238,   238,   238,   238,
     239,   239,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   241,   241,   241,   241,
     242,   242,   242,   242,   243,   243,   244,   244,   245,   245,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246
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
       6,     9,     5,     7,     9,     9,    11,     7,     9,     9,
       0,     1,     0,     3,     5,     0,     9,     3,     5,     0,
       2,     3,     5,     3,     1,     1,     0,     5,     0,     2,
       7,     0,     9,     6,     7,     4,     7,     8,     8,     7,
       7,    11,     8,     8,     0,     9,     8,     9,     3,     4,
      10,     7,     7,     8,     8,    12,     0,     9,     8,     7,
       8,     0,     9,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     6,     6,     6,     8,
      10,    14,    16,    12,     8,     8,     6,    14,     4,     6,
       6,     3,     4,     5,     3,     3,     4,     4,     3,     7,
       7,     3,     7,     3,     2,     2,     2,    15,     2,     2,
       2,     2,     6,     8,     8,    10,     1,     2,     1,     3,
       4,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     2,     3,     2,     3,
       9,     6,     0,     3,     0,     1,     0,     2,     0,     2,
       7,     6,     8,     5,     3,     7,     5,     6,     6,    12,
      10,    10,    10,    10,     2,     3,     6,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     4,     2,     5,     3,     6,
       4,     7,     6,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     2,     2,     2,
       2,     1,     1,     3,     4,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     1,     4,     6,     6,     4,     4,     4,
       6
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
     196,     0,   201,     0,     0,   198,     0,     0,     0,     0,
     277,   278,     5,     7,     6,     8,     9,    10,    21,    11,
      12,    13,    20,    19,    14,    15,    16,    17,    18,     0,
      22,   345,   352,   412,    57,   346,   347,   348,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,   349,   350,
     351,    61,    60,    59,    58,     0,     0,     0,    63,    62,
       0,     0,     0,     0,   153,     0,     0,     0,   283,     0,
       0,     0,     0,   186,     0,   188,   185,   189,   190,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,     0,     0,     0,
       0,     0,     0,   111,   124,   136,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,   274,
       0,     0,     0,     0,     0,   352,   381,     0,     0,     0,
       0,     0,     0,     0,   391,   392,   374,   380,     0,   375,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
     184,     0,     0,   197,     0,   153,     0,   153,   279,     0,
       0,     0,     0,     0,     0,   356,    32,   412,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     286,   285,   287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,   151,     0,    69,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   178,   128,     0,     0,     0,    90,     0,
       0,   396,   397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,   364,     0,     0,
       0,     0,   153,   153,     0,     0,     0,     0,     0,     0,
       0,   211,     0,   153,     0,     0,     0,     0,     0,   258,
       0,     0,     0,   171,     0,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,   387,     0,   388,   389,   390,
       0,   285,   382,   376,     0,     0,     0,   264,   183,     0,
       0,     0,     0,     0,   153,     0,     0,     0,     0,   199,
     174,     0,   175,     0,     0,     0,     0,     0,   358,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,   408,     0,     0,     0,
       0,     0,     0,     0,     0,   284,    57,     0,     0,     0,
      57,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,   154,    65,     0,   301,   300,   299,   298,   294,   295,
     297,   296,   289,   288,   290,   291,   292,   293,   129,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,   367,   366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,   168,     0,
       0,     0,     0,     0,   393,     0,     0,     0,     0,     0,
     377,   384,     0,   290,   383,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,   176,   177,     0,     0,     0,
       0,   354,   360,     0,    42,     0,     0,     0,    55,     0,
      33,    34,    35,    36,    37,   303,   324,   304,   325,   305,
     326,   306,   327,   307,   328,   308,   329,   309,   330,   310,
     331,   311,   332,   323,   344,   312,   333,     0,     0,   314,
     335,   315,   336,   316,   337,   317,   338,   318,   339,   319,
     340,     0,     0,     0,     0,     0,     0,     0,     0,   419,
       0,     0,   417,   418,    82,     0,   414,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,    25,    23,     0,     0,
       0,    64,    93,     0,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   257,   255,     0,   263,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
     202,     0,     0,     0,     0,     0,     0,   259,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   354,
     394,   386,   378,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,     0,     0,     0,     0,   280,     0,     0,
     357,     0,   353,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,    70,
      72,    74,     0,     0,   406,     0,    80,     0,     0,     0,
       0,   302,    24,     0,     0,     0,     0,     0,     0,   108,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,   246,     0,   248,     0,   212,   241,     0,     0,
       0,   166,     0,     0,     0,   267,     0,   170,   169,   276,
       0,     0,    30,    31,     0,   385,   379,     0,     0,     0,
     403,     0,     0,     0,   192,     0,     0,     0,     0,   180,
     359,   179,     0,     0,     0,     0,   372,     0,   313,   334,
     320,   341,   321,   342,   322,   343,     0,   420,   416,   362,
     415,     0,    57,     0,     0,     0,     0,    67,     0,     0,
       0,   404,     0,     0,     0,     0,    26,    27,     0,     0,
       0,    94,   110,     0,     0,     0,     0,     0,   114,     0,
       0,   131,   132,     0,     0,   116,   139,     0,     0,     0,
     106,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,     0,     0,   153,   153,     0,
     222,     0,   224,     0,   226,     0,   374,     0,     0,   247,
     249,     0,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   395,   119,   120,     0,     0,     0,
       0,    83,    87,     0,     0,   281,   361,     0,    38,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,    77,
       0,     0,    78,     0,   407,   155,   156,   157,   158,     0,
       0,    95,     0,   109,   117,   118,   122,     0,     0,   133,
       0,     0,   262,   126,     0,     0,   253,   138,     0,     0,
       0,     0,   123,     0,   134,   140,     0,     0,     0,     0,
     371,     0,   370,     0,     0,     0,   213,     0,     0,   214,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,   164,     0,     0,     0,   159,     0,     0,
       0,     0,   401,     0,   194,   193,     0,     0,     0,     0,
      43,     0,     0,     0,   373,     0,     0,     0,   411,    68,
      73,    75,     0,    81,     0,    28,     0,    99,     0,     0,
       0,     0,     0,     0,   127,   112,   125,   137,   142,     0,
       0,    88,    89,   153,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,   242,     0,     0,   153,     0,     0,
       0,     0,     0,   150,   149,     0,     0,     0,     0,    84,
      85,     0,     0,    39,     0,     0,     0,    41,    56,     0,
     405,     0,     0,   270,   271,   272,   273,   130,     0,     0,
       0,     0,     0,   369,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,   207,     0,     0,
     160,     0,     0,     0,   400,   195,     0,   282,     0,     0,
       0,     0,    79,     0,     0,    96,   100,     0,     0,     0,
     144,     0,   228,     0,     0,   230,     0,     0,   232,     0,
       0,     0,   243,     0,   203,     0,   153,     0,     0,     0,
     121,    86,     0,    47,     0,    53,     0,     0,     0,   107,
     135,   269,   368,   216,     0,     0,   223,   217,     0,     0,
     225,   218,     0,     0,   227,     0,     0,     0,   209,     0,
     163,     0,     0,     0,     0,     0,     0,     0,   103,     0,
     101,     0,   234,     0,   236,     0,   238,   244,   250,   208,
     204,     0,     0,     0,     0,    44,     0,    51,     0,     0,
       0,   396,     0,   219,     0,     0,   220,     0,     0,   221,
       0,     0,   167,     0,   161,     0,    45,     0,     0,   187,
       0,   102,     0,     0,     0,     0,     0,     0,     0,   210,
       0,     0,     0,     0,     0,     0,    97,   229,     0,   231,
       0,   233,     0,   162,    46,    48,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    54,    98,   235,   237,   239,
      50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,   748,    73,    74,   470,  1097,  1103,
     670,   853,  1252,  1405,   671,  1364,  1436,   672,  1407,   673,
     674,   857,   145,   265,    75,   564,   358,  1207,  1390,  1262,
    1306,   779,  1135,  1025,   541,   384,   385,   386,   387,   234,
     333,   334,    78,    79,    80,    81,    82,    83,   235,   811,
    1325,  1381,   613,  1157,  1160,  1163,  1344,  1348,  1352,  1394,
    1397,  1400,   807,   808,   917,   776,   587,   622,    85,    86,
      87,    88,    89,    90,   236,   148,   397,   200,   985,   986,
     238,   239,   444,   246,   739,   885,   515,   516
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1020
static const yytype_int16 yypact[] =
{
    3957,    39,    28,  4039, -1020, -1020,  1852,     4,    26,   -93,
      16,   118,   142,   149,   182,    56,   -96,    83,   106,    -3,
     114,   207,    17,   224,   231,   325,   356,   363,   394,   369,
     386,   264,   385,   667,   315,    60,   305,   403,   303,   175,
     175,   327,    -9,   201,   438,   439,   447,    11,    57,   480,
     499,   531,   532,  2006,   558,   414,   423,   444,    19,     8,
   -1020,   463, -1020,   620,   466, -1020,   627,   630,    34,    36,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,    38,
   -1020, -1020,    33,   479,   355, -1020, -1020, -1020,   171,   248,
     286,   314,   372,   382,   424,   453,   464,   471,   481,   504,
     535,   554,   555,   582,   596,   599,   602,   628,   641,   489,
     490,   493,   508, -1020,   656,   518,   522,   525, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020,  3562,  3562,  3562, -1020, -1020,
    3562,   886,    12,   673,    23,  2450,   672,  1324, -1020,   677,
     686,  3562,   702, -1020,  3562, -1020, -1020, -1020, -1020, -1020,
    3562,  3486,  3562,  3562,   550,  3562,  3486,  3562,  3562,   559,
    3486,  3562,  3562,  2450,   568,   564, -1020,   578,   585,  2006,
    2006,  2006,   595, -1020, -1020, -1020, -1020,   603,   610,   613,
    2450,  3562,   724,  2450,   175,   175,   175,  3562,  3562,   215,
   -1020,   222,   175,   626,   631,   635,  3272,   226,   -87,   634,
     637,   649,  2006,  2450,   679,     5,   587, -1020,   770, -1020,
     678,   700,   701,   709,   713,   579, -1020,   733,    37,   824,
     869,   880,  2598,  1695, -1020, -1020,  3695, -1020,   882, -1020,
     885,  3562,  3562,  3562,   739,  3562,   742,   792,  3562,  3562,
   -1020,  3562,   920, -1020,   930, -1020,   938, -1020, -1020,  2450,
    2450,   801,  3562,   923,   816, -1020, -1020, -1020,   973,  3562,
    3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,
    3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,
    3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,
    3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,
    3562,    82,    82,    82,    82,  3562,    82,    82,    82,   614,
     844,   844,   844,  6357,    94,  3486,  5598,   344,   849,   990,
     865,   861, -1020,   872,  4113,  1016, -1020, -1020,  3562,  3562,
    3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  3562,
    3562,  3562,  3562, -1020, -1020,  1652,   -55,  4896,    51,  6378,
    3486,  3727, -1020,   349,  6399,  6420,  3562,  6441,   371,  6462,
    6483,  3562,   639,  6504,  6525,  1026,  3562,  3562,  3562,  3562,
    1029,  1030,  1030,  3562,   892,   899,   916,   937,  3562,  3562,
    3562,  1062,  4816,   922,  1082,   -64, -1020, -1020,  4922,  4948,
     175,   175,    23,    23,   -37,  3562,  3562,  3562,  3272,  3272,
    3562,  4113,   172, -1020,  3562,  3562,  3562,  3562,  3562,  1085,
    1086,  3562,  1083, -1020,  3562,  3562,  1147, -1020,  3486,  3486,
    3486,  3562,  3562,  3118,  1090, -1020,  3562, -1020, -1020, -1020,
    3486,   844, -1020, -1020,   640,  3562,  2746, -1020, -1020,  6546,
    6567,  6588,   991,  4974, -1020,   940,  3746,  6609,  5621, -1020,
   -1020,  1296, -1020,  1579,   949,   663,  3562,  5644,   -76,  3562,
      14, -1020,  6630,  5667,  6651,  5690,  6672,  5713,  6693,  5736,
    6714,  5759,  6735,  5782,  6756,  5805,  6777,  5828,  6798,  5851,
    6819,  5874,  6840,  5897,  5000,  5026,  6861,  5920,  6882,  5943,
    6903,  5966,  6924,  5989,  6945,  6012,  6966,  6035,  5052,  5078,
    5104,  5130,  5156,  5182,   668,    98, -1020,   945,   951,   952,
    1769,   950,   956,   953,  3562, -1020, -1020,  2450,   670,   206,
     355,  3562,  1101,  1106,    21,   960, -1020,   -77,    25,    22,
      69, -1020, -1020,  3765,  1689,  1289,  1234,  1234,   729,   729,
     729,   729,   426,   426,   844,   844,   844,   844, -1020,    18,
    3486,  3562,  1108, -1020,  1111,  1109,  3486,  3486,  1010,  1112,
    1113,  6987,  1114,  1015,  1117,  1119,  7008,  1020,  1123,  1124,
    3562,  7029,  4144,  7050,  7071,  3562,  2450,  1128,  1127,  7092,
    3628,  3628,  3628,  3628,  7113,  7134,  7155,  2450,  3486,   981,
   -1020,   175,  3562,  3562, -1020, -1020,   978,   979,  3272,  5208,
    5234,  5260,  4870,   147,   175,  1885,  7176,  4172,  7197,  7218,
    7239,  3562,  1132,  3562,  7260, -1020,  6058,  6081, -1020,   682,
     685,   688,  6104,  6127, -1020,  3486,  6150,   988,  4200,   689,
   -1020,  3793,  3486,   844, -1020,  1135,  1136,  1137,   992,  3562,
    2053,  3562,  3562, -1020,    44, -1020, -1020,   994,  2450,  1140,
    6173,    89, -1020,  4228, -1020,   998,   999,   995, -1020,  1146,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020,  3562,  3562, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,  3562,  3562,  3562,  3562,  3562,  3562,  3562,  1150, -1020,
    3486,    82, -1020, -1020, -1020,  3562, -1020,    82,  1149,  1004,
      46,  3562,  1151,  1152,  2405, -1020,  1156,  1013,    19,  1159,
   -1020,  3486,  3486,  3486,  3486,  3562, -1020,  1032,    82,   107,
    5286, -1020,  1163,   175,  3727, -1020,  1116,  2450,  2450,  1165,
    2450,   810,  2450,  2450,  1171,  1125,  2450,  2450,  2424,  1173,
    1176,  1178,  1179,  3841, -1020, -1020,  1160, -1020,  1180,  1038,
    7491, -1020,  1040,  1041,  1042,  1186,  1188,  1199,  1202,   723,
    1205,   270,  5312,  5338, -1020, -1020,  4256,   -75,   175,   175,
     175,  1208,  1210,  1061,  1071,    13,    53,   -13, -1020,   281,
   -1020,   147,  1214,  1217,  1219,  1221,  1223,  7491, -1020,  2563,
    1068,  1225,  1226,  1227,  1181,  3562,  1229,  1231,   766,   112,
   -1020, -1020, -1020,  3562,   767,  2450,  2450,  2450,  1236,  5364,
   -1020,  3812,   674,  1237,  1238,  2450,  1081, -1020,  1239,  1245,
   -1020,  1244, -1020,  1102,  3562,  3562,  2450,  1098, -1020,  7281,
    6196,  7302,  6219,  7323,  6242,  7344,  6265,  6288, -1020,   111,
    1105,  7365,  1107, -1020,    94,   350,  1103,  1251,  2701, -1020,
   -1020, -1020,    19,  3562, -1020,   776, -1020,   777,   780,   785,
     786,  7491, -1020,  1254,    49,  3562,  3338,     2,  1115,  1198,
    1198,  2450,  1256,  1118,  1120,  1257,  1258,  2450,  1126,  1259,
    1261, -1020,  1263,  2450,  2450,  2450,  1265,  1266, -1020,  2450,
    1268,  1273,  1276,  1277,  2450,  2450,  2450, -1020,  1278,   130,
    3562,  3562,  3562,  1130,  1131,   -72,    59,    72,  1122, -1020,
    2450,  3562, -1020,  1282, -1020,  1284, -1020, -1020,  3272,   239,
    2154, -1020,  1138,  1139,  2894, -1020,  3486, -1020, -1020, -1020,
    1141,  2720, -1020, -1020,  1148,  7491, -1020,  1285,  1287,  1195,
   -1020,  3562,  3562,  3562, -1020,  1295,   384,  1155,  1297, -1020,
     -76, -1020,  3562,  5390,  5416,   790, -1020,  3562, -1020, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020,  1153, -1020, -1020, -1020,
   -1020,  2450,   355,  3562,  1299,  1298,    21, -1020,  1301,  6311,
      19, -1020,  1306,  1307,  1309,  1310, -1020, -1020,    82,  5442,
    3562,  7491, -1020,  3562,   175,  1312,  1313,  1314, -1020,  3562,
    3562, -1020, -1020,  1316,  3562, -1020, -1020,  1318,  1320,  1322,
    1222,  3562, -1020,  1325,  2450,  2450,  2450,  2450,  1331,   944,
    1334,  3562, -1020,  3628,  4284,  7386,  4060,    23,    23,   175,
    1335,   175,  1338,   175,  1349,  3562,   377,  1169,  7407, -1020,
   -1020,  4312,   293, -1020,  1351,  1532,  1352,  2450,   175,  1532,
    1355,   794,  3562, -1020, -1020, -1020, -1020,  2450,  4088,   409,
    7428, -1020, -1020,  3190,  2450, -1020, -1020,   213,  7491,  3562,
    3562,  2450,  1209,   820,  7491,  1362,  1372,  1374,  2859, -1020,
    1376,  1378, -1020,  1233, -1020, -1020, -1020, -1020, -1020,  1382,
    3562,  7491,  4340,   -26, -1020, -1020, -1020,  4368,  4396, -1020,
    4424,  1385, -1020, -1020,  1339,  1387,  7491, -1020,  1388,  1392,
    1393,  1394, -1020,  1235, -1020, -1020,  4843,  3243,  1395,  1246,
   -1020,  3562, -1020,  1247,  1248,   307, -1020,  1253,   313, -1020,
    1260,   345, -1020,  1262,  6334,  1397,  2450,  1400,  1264,  3562,
   -1020,  3042,   398, -1020,   821,   416,   437, -1020,  1404,  4452,
    1315,  3562, -1020,  3562, -1020, -1020,  3486,  3301,  1408,  1279,
   -1020,  3562,  5468,  5494, -1020,  2450,  3562,  1409, -1020, -1020,
   -1020, -1020,    19, -1020,  1329, -1020,  5520, -1020,  1413,  1429,
    1432,  1433,  1434,  1286, -1020, -1020, -1020, -1020, -1020,  2450,
    3486, -1020, -1020,    23,  4116, -1020, -1020,  3272,   147,  3272,
     147,  3272,   147,  1437, -1020,   827,  2450, -1020,  4480,   175,
    1438,  3486,   175, -1020, -1020,  3562,  4508,  4536,   831, -1020,
   -1020,  1439,  1290,  7491,  3562,  3562,   832,  7491, -1020,  1441,
   -1020,  3562,   850, -1020, -1020, -1020, -1020, -1020,  3562,   851,
     858,  1291,  3562, -1020,  4564,   440,   370,  4592,   442,   537,
    4620,   470,   589, -1020,  2450,  1443,  1380,  2201,  1317,   497,
   -1020,   888,   530,  3591, -1020, -1020,  1445, -1020,  3562,  7449,
    5546,    27, -1020,  5572,  1448, -1020, -1020,  4648,  1462,  1463,
   -1020,  4676,  1464,  3562,  1465,  1468,  3562,  1469,  1470,  3562,
    1472,  1323, -1020,  3562, -1020,   147, -1020,  3486,  1473,  3042,
   -1020, -1020,   889, -1020,  3562, -1020,  2450,  3562,  2302, -1020,
   -1020, -1020, -1020, -1020,  1326,  4704, -1020, -1020,  1328,  4732,
   -1020, -1020,  1330,  4760, -1020,  1475,  3657,   611,  2349,   897,
   -1020,   533,   898,  1479,  1332,  7470,   903,  4788, -1020,  1695,
   -1020,   147,  1481,   147,  1486,   147,  1487, -1020, -1020, -1020,
   -1020,   147,  1488,  3486,  1490, -1020,    82, -1020,  1341,  1492,
     907,   825,   684, -1020,  1343,   694, -1020,  1347,   768, -1020,
    1348,   796, -1020,   921, -1020,   924, -1020,  1350,  2450, -1020,
    3562, -1020,   355,  1499,   147,  1501,   147,  1503,   147, -1020,
    1504,    82,  1505,    82,   927,  3676, -1020, -1020,   904, -1020,
     933, -1020,   980, -1020, -1020, -1020,   928, -1020,  1507,   355,
    1508,  1509,  1511,    82,  1512, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1020, -1020, -1020, -1020,   625, -1020, -1020, -1020, -1020,   223,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,  -314,     1, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020,  -111, -1020,   622,  1517, -1020, -1020, -1020, -1020,    -1,
    -397,  -203, -1020, -1020, -1020, -1020, -1020, -1020,  1520, -1020,
   -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020, -1020,
   -1020, -1020,  -727,  -787, -1020, -1020,  1142, -1020, -1020, -1020,
   -1020, -1020, -1020, -1020,    -2, -1020,    50, -1020, -1019,   576,
    -132,   433,    58,  -700,   519, -1020,  -282,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     149,   164,    77,   411,   147,   606,   607,   146,  1022,   422,
     527,   423,   247,   531,   426,   215,   327,   150,   664,   942,
     947,   169,   153,   244,   746,   737,   169,   331,     5,   164,
     517,   518,   519,  1335,   521,   522,   523,   261,   884,   254,
     203,   256,   435,   204,   258,     4,   205,   380,   381,   382,
     875,   843,   461,   160,   463,  1017,   152,   801,  1174,   944,
     161,   218,   414,   219,   400,   401,   802,   400,   401,   415,
     138,   139,   160,   803,   804,   400,   401,   805,   806,   741,
     419,   151,   934,  1059,   949,  1060,   514,   267,   268,   199,
     201,   601,   207,   514,   267,   559,    38,    39,    40,    41,
     560,   526,   400,   401,    46,   943,   220,    49,   665,   666,
     667,   668,   190,   400,   401,   191,   328,   329,   608,   119,
     120,   121,   122,   216,   155,   123,   119,   120,   121,   122,
     195,   196,   123,   320,   321,   322,  1052,  1053,   323,   326,
     197,   400,   401,   332,   946,   945,   165,   206,   156,   355,
     876,   877,   357,   166,   747,   157,   424,   248,   359,   361,
     364,   365,   947,   367,   361,   369,   370,   217,   361,   373,
     374,   669,   154,   170,   165,   245,  1256,   738,   743,   138,
     139,   742,  1008,  1336,   262,   747,   263,   259,   158,   392,
     255,   264,   257,   436,   260,   398,   399,   844,   400,   401,
    1269,   126,   127,   562,   399,   208,   563,   159,   126,   127,
     615,   400,   401,   526,  1061,   731,  1062,   801,   172,   363,
     131,   132,   133,   134,   368,   744,   802,  1063,   372,  1064,
     441,   361,   162,   803,   804,   138,   139,   805,   806,   449,
     450,   451,   849,   453,   395,   396,   456,   457,   719,   458,
     209,   650,   404,   720,   210,   163,   412,   894,   138,   139,
     467,   997,   567,   167,   211,   849,   567,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   801,
    1114,   400,   401,   520,   195,   196,   179,  1366,   802,   180,
     269,   181,   270,   361,   197,   803,   804,   614,   532,   805,
     806,   198,   131,   132,   133,   134,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   530,   138,   139,   400,   401,   168,  1002,   441,   730,
     267,   400,   401,  1190,   571,   400,   401,   187,  1191,   576,
     188,   402,   189,   171,   581,   582,   583,   584,   403,   851,
     172,   589,   413,   528,   173,   445,   594,   595,   596,  1424,
    1092,  1093,   119,   120,   121,   122,  1073,   271,   123,   272,
     176,   332,   332,   609,   610,   611,   320,   321,   612,   400,
     401,   174,   616,   617,   618,   619,   620,  1183,   175,   624,
     400,   401,   626,   627,   177,   930,   361,   361,   361,   632,
     633,   636,   400,   401,   638,   273,   948,   274,   361,   870,
     801,   178,   182,   641,   643,   872,   400,   401,  1169,   802,
     604,   605,   400,   401,   192,   193,   803,   804,   396,   194,
     805,   806,  1227,   275,   660,   276,   893,   663,  1229,   662,
     131,   132,   133,   134,   126,   127,   131,   132,   133,   134,
     782,   783,   784,   202,   400,   401,   629,   630,   631,   947,
     138,   139,   947,   212,   213,   947,   138,   139,   639,   214,
    1231,  1276,  1259,  1279,   567,  1282,   568,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   446,   350,
     351,   277,   636,   278,   733,   352,   567,  1314,   573,   734,
     732,   279,   221,   280,  1165,   223,   224,   400,   401,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,  1239,   222,   400,   401,   352,   361,   750,
    1001,  1003,   240,   241,   643,   754,  1184,   349,   350,   351,
     947,  1241,   242,   281,   352,   282,   400,   401,   768,   400,
     401,   400,   401,   773,   781,   781,   781,   781,   780,   780,
     780,   780,  1242,   243,   362,  1313,   361,  1316,  1357,   362,
     792,   793,   283,   362,   284,   947,   796,   801,   947,   400,
     401,   947,   249,   285,   947,   286,   802,   251,   749,   817,
     287,   819,   288,   803,   804,  1319,   250,   805,   806,   237,
     289,   252,   290,   361,   253,   266,   400,   401,   311,   312,
     361,   947,   313,   947,  1392,   947,  1395,   839,  1398,   841,
     842,   791,  1327,   291,  1401,   292,   789,   314,   797,   801,
    1153,  1154,   850,   315,   809,   442,   362,   316,   802,   400,
     401,   317,   400,   401,   318,   803,   804,   330,   336,   805,
     806,   801,   973,   353,   293,  1329,   294,  1428,  1383,  1430,
     802,  1432,   354,   828,  1317,   859,   860,   803,   804,   366,
     834,   805,   806,   295,   297,   296,   298,   356,   371,   861,
     862,   863,   864,   865,   866,   867,   183,   376,   361,   184,
     377,   335,   185,   871,   186,   138,   139,   378,   393,   878,
     433,   299,   263,   300,   379,   144,  1119,   264,   425,   361,
     361,   361,   361,   891,   383,   301,  1320,   302,   303,   375,
     304,   305,   388,   306,   801,   237,   237,   237,   362,   389,
     138,   139,   390,   802,   801,   524,   391,   263,  1379,   394,
     803,   804,   264,   802,   805,   806,   427,   307,   869,   308,
     803,   804,   405,   416,   805,   806,   417,   406,   237,   420,
     309,   407,   310,   442,   567,   567,   577,   640,   418,   887,
     888,   889,   890,   897,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   658,   717,
     659,   718,   352,   961,   974,   567,  1271,   729,   421,   437,
     850,   965,  1412,   445,   428,   464,   465,   567,   801,   823,
     567,  1413,   824,   567,   567,   825,   832,   802,   935,   936,
     937,  1415,   983,   984,   803,   804,   429,   430,   805,   806,
     431,   362,   362,   362,   432,   903,   801,   904,   347,   348,
     349,   350,   351,   362,   438,   802,  1004,   352,   567,   644,
     928,  1009,   803,   804,   434,   439,   805,   806,   447,    91,
     319,   448,   452,  1019,  1021,    95,    96,    97,   454,   455,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   567,   567,   964,   966,  1417,   459,   468,  1054,  1055,
    1056,  1010,   567,  1011,  1012,   567,   460,  1013,  1066,  1068,
     567,   567,  1014,  1015,   462,  1101,  1071,  1102,  1143,   567,
    1144,  1178,   466,  1419,   361,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   566,   350,   351,  1088,
    1089,  1090,   469,   352,   801,  1196,  1101,  1197,  1240,   471,
    1098,  1096,  1284,   802,  1285,  1104,   567,  1101,  1296,  1301,
     803,   804,   352,   362,   805,   806,  1107,   534,  1072,   644,
     755,  1108,   533,   801,   125,  1304,  1101,  1305,  1308,   128,
     129,   130,   802,   567,  1081,  1309,   535,   144,  1121,   803,
     804,  1122,   542,   805,   806,   135,   136,  1127,  1128,   536,
     137,   362,  1130,   580,  1287,   140,   585,   586,   324,  1136,
     143,   590,   325,   567,  1196,  1328,  1363,  1148,   591,  1146,
     801,  1147,   567,   567,  1382,  1384,   332,   332,  1101,   802,
    1388,  1440,  1410,  1164,  1411,   592,   803,   804,   362,   597,
     805,   806,   599,   361,  1123,   362,   567,   361,  1420,  1421,
    1179,  1422,  1101,  1443,  1438,  1444,   593,  1188,   600,   625,
    1441,  1187,   621,   623,   637,   648,   651,  1192,  1193,   657,
     721,   722,   723,   728,  1406,   725,   726,   735,   727,  1155,
     736,  1158,   740,  1161,   751,   752,   753,   756,  1206,   757,
     758,   760,   761,  1358,   762,  1172,   763,   765,  1175,  1176,
     766,   767,   775,   777,   790,   794,   795,  1442,   818,  1434,
     830,  1437,   835,   836,   837,   838,   847,   854,   855,  1224,
     845,   856,   858,   362,   868,   873,   874,   879,   880,     7,
       8,  1450,   774,   882,   883,   886,   918,  1238,   892,   441,
     896,   898,   901,   788,   362,   362,   362,   362,   907,  1246,
     912,  1247,   908,   913,   361,   914,   915,   919,   920,  1253,
     921,   922,   923,   924,  1257,   925,   537,    17,    18,   538,
      20,    21,   539,    23,   540,    25,   926,    26,   927,   929,
      29,    30,   938,    32,    33,    34,   939,   940,   361,    37,
     941,   950,   332,   951,   956,  1274,   952,  1277,   953,  1280,
     954,   957,   958,   959,   846,   962,   960,   963,   978,   361,
     970,   975,   976,  1293,  1248,   979,    55,    56,    57,   980,
     981,   982,  1299,  1300,   987,   998,  1005,  1000,  1006,  1303,
    1016,  1024,  1028,  1031,  1032,  1035,  1307,  1036,  1037,  1041,
    1311,  1023,  1042,  1065,  1029,  1044,  1030,  1275,  1270,  1278,
    1045,  1281,  1034,  1046,  1047,  1051,  1057,  1058,  1069,  1289,
    1070,  1085,  1292,  1086,  1077,  1078,  1104,  1082,  1087,  1291,
    1084,  1091,  1110,  1095,   628,  1109,  1105,  1112,     7,     8,
    1094,  1345,  1115,  1116,  1349,  1117,  1118,  1353,  1124,  1125,
    1126,  1356,  1129,  1131,  1166,   361,  1132,   361,  1133,  1134,
     337,  1137,  1365,   899,   900,  1367,   902,  1142,   905,   906,
    1145,  1156,   909,   910,  1159,   537,    17,    18,   538,    20,
      21,   539,    23,   540,    25,  1162,    26,  1170,  1173,    29,
      30,  1177,    32,    33,    34,  1195,  1198,  1391,    37,   343,
     344,   345,   346,   347,   348,   349,   350,   351,  1199,  1361,
    1200,   361,   352,  1202,  1203,  1359,  1204,  1362,  1205,   362,
    1212,  1219,  1213,  1214,  1215,    55,    56,    57,  1216,  1217,
    1218,  1222,  1223,  1234,  1225,  1226,  1426,  1236,  1425,  1228,
    1243,   967,   968,   969,  1250,  1258,  1230,  1245,  1232,  1263,
    1237,   977,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,  1446,  1260,  1264,  1251,   352,  1265,  1266,
    1267,  1403,  1268,  1283,  1290,  1297,  1298,  1302,  1310,  1322,
    1323,  1331,  1338,   655,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,  1340,  1341,
    1343,  1346,   352,  1326,  1347,  1350,  1351,  1027,  1354,  1360,
    1355,  1377,  1371,  1033,  1373,  1385,  1375,  1393,  1386,  1038,
    1039,  1040,  1396,  1399,  1402,  1043,  1404,  1408,  1409,  1414,
    1048,  1049,  1050,  1416,  1418,  1427,  1423,  1429,   362,  1431,
    1433,  1435,   362,  1445,  1447,  1448,  1067,  1449,  1451,  1018,
      76,  1332,  1026,    84,   588,  1111,  1076,     0,     0,     0,
    1080,     0,     0,     0,     0,    91,   225,     0,     0,     0,
       0,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1106,     0,     0,
       0,   228,     0,     0,   229,     0,     0,   230,     0,   231,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   442,    38,    39,    40,    41,    42,
       0,     0,     0,    46,     0,     0,    49,     0,     0,   362,
    1138,  1139,  1140,  1141,     0,     0,     0,     0,   537,    17,
      18,   538,    20,    21,   539,    23,   540,    25,     0,    26,
       0,     0,    29,    30,     0,    32,    33,    34,     0,     0,
     125,    37,     0,   362,     0,   128,   129,   130,   558,     0,
       0,     0,     0,  1180,     0,     0,     0,     0,     0,     0,
    1189,   408,  1171,     0,   362,     0,   137,  1194,    55,    56,
      57,   410,     0,     0,     0,     0,   143,     0,   198,   443,
       0,     0,     0,     0,     0,     0,     0,     0,    91,   225,
       0,     0,     0,     0,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     227,     0,     0,     0,     0,     0,   656,     0,     0,     0,
       0,     0,  1235,     0,   228,     0,     0,   229,     0,     0,
     230,     0,   231,     0,     0,     0,     0,     0,     0,     0,
     362,     0,   362,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,     0,     0,   724,    46,     0,     0,    49,
       0,     0,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1286,   125,     0,     0,   362,     0,   128,   129,
     130,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,   135,   360,     0,   352,     0,   137,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   143,
       0,     0,   443,     0,     0,    91,    92,    93,     0,    94,
    1321,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,     0,   119,
     120,   121,   122,     0,     0,   123,     0,     7,     8,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,  1370,     0,     0,   352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,    17,    18,   538,    20,    21,
     539,    23,   540,    25,     0,    26,     0,     0,    29,    30,
       0,    32,    33,    34,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,   128,   129,   130,   131,   132,
     133,   134,     0,     0,    55,    56,    57,     0,     0,     0,
       0,   135,   136,     0,     0,     0,   137,     0,   138,   139,
       0,   140,     0,   141,     0,   142,   143,     0,   144,    91,
     225,   226,     0,     0,     0,    95,    96,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   227,   810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,   229,     0,
       0,   230,     0,   231,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,     0,     0,    46,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,    17,    18,   538,    20,    21,   539,    23,
     540,    25,     0,    26,     0,     0,    29,    30,     0,    32,
      33,    34,     0,     0,   125,    37,     0,     0,     0,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   232,     0,     0,     0,
     137,     0,    55,    56,    57,   140,     0,    91,   225,  1074,
     143,     0,   233,    95,    96,    97,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,     0,     0,   229,     0,     0,   230,
     840,   231,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,     0,     0,     0,    46,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,    17,    18,   538,    20,    21,   539,    23,   540,    25,
       0,    26,     0,     0,    29,    30,     0,    32,    33,    34,
       0,     0,   125,    37,     0,     0,     0,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   232,     0,     0,     0,   137,     0,
      55,    56,    57,   140,     0,    91,   225,  1368,   143,     0,
    1075,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,     0,   229,     0,     0,   230,  1324,   231,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,    42,
       0,     0,     0,    46,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,    17,
      18,   538,    20,    21,   539,    23,   540,    25,     0,    26,
       0,   881,    29,    30,     0,    32,    33,    34,     0,     0,
     125,    37,     0,     0,     0,   128,   129,   130,     0,     0,
     911,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   232,     0,     0,     0,   137,     0,    55,    56,
      57,   140,     0,    91,   225,     0,   143,     0,  1369,    95,
      96,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
       0,     0,   229,     0,     0,   230,  1380,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,    46,     0,     0,    49,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   125,   955,
       0,     0,   352,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     232,     0,     0,     0,   137,     0,     0,     0,     0,   140,
       0,    91,   225,     0,   143,     0,   233,    95,    96,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
     229,     0,     0,   230,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,     0,     0,     0,    46,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,  1007,     0,     0,
       0,   352,     0,     0,     0,     0,   125,     0,     0,     0,
       0,   128,   129,   130,     0,     0,  1083,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   360,     0,
       0,     0,   137,     0,     0,     0,     0,   140,     0,    91,
     225,     0,   143,     0,   440,    95,    96,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,   229,     0,
       0,   230,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,     0,     0,    46,     0,     0,
      49,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   125,  1201,     0,     0,   352,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   360,     0,     0,     0,
     137,     0,     0,     0,     0,   140,     0,    91,   225,     0,
     143,     0,   642,    95,    96,    97,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,     0,     0,   229,     0,     0,   230,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,     0,     0,     0,    46,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,     0,
       0,     0,   125,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   232,     0,     0,     0,   137,     0,
       0,     0,     0,   140,     0,    91,   225,     0,   143,     0,
    1079,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,     0,   229,     0,     0,   230,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,    42,
       0,    91,   319,    46,     0,     0,    49,    95,    96,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   408,  1171,     0,     0,     0,   137,     0,     0,     0,
       0,   410,     0,    91,   319,   267,   143,     0,   198,    95,
      96,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,     0,     0,   119,   120,   121,
     122,     0,     0,   123,     0,     0,   125,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,     0,     0,  1221,
       0,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,   137,     0,     0,     0,     0,   140,     0,     0,
     634,     0,   143,     0,   635,    91,   319,     0,     0,     0,
       0,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,  1249,   125,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     136,     0,     0,     0,   137,     0,     0,     0,     0,   140,
       0,    91,   319,     0,   143,     0,  1186,    95,    96,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
     125,   352,     0,     0,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   408,   409,     0,     0,     0,   137,     0,     0,     0,
       0,   410,     0,     0,     0,     0,   143,     0,   198,     0,
       0,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,   137,     0,     0,     0,     0,   140,     0,    91,
     225,     0,   143,     0,  1020,    95,    96,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   228,     0,     0,   229,     0,
       0,   230,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,     0,    91,   319,    46,     0,     0,
      49,    95,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,  1330,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   360,     0,     0,     0,
     137,    91,   319,   267,     0,   140,     0,    95,    96,    97,
     143,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,  1378,     0,   119,   120,   121,   122,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,  1439,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,   445,     0,     0,   137,     0,     0,     0,
       0,   140,     0,     0,     0,     0,   143,     0,     0,     0,
       0,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   445,     0,     0,     0,   352,
       0,     0,     0,     0,     0,     0,   125,   126,   127,     0,
       0,   128,   129,   130,   652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   136,     0,
       0,     0,   137,   745,     0,     0,     0,   140,     0,     0,
       0,     0,   143,     0,     0,     0,     0,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   833,     0,     0,     0,   352,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     972,     0,     0,     0,   352,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   446,   350,   351,     0,
       0,     0,     0,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   566,   350,
     351,     0,     0,     0,     0,   352,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,   916,     0,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,    -4,     1,     0,
     352,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     6,     0,    -4,    -4,     0,     0,     0,
      -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     9,     0,     0,    -4,    -4,
      10,    11,     0,    12,    13,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     7,     8,    51,    52,     0,
       0,     0,    53,     0,     0,     0,     0,    54,    55,    56,
      57,     0,     0,    58,     0,    59,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
      70,    71,   537,    17,    18,   538,    20,    21,   539,    23,
     540,    25,     0,    26,     0,     0,    29,    30,     0,    32,
      33,    34,     0,     0,     0,    37,     0,     0,     0,     0,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,    55,    56,    57,  1151,     0,  1152,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,  1181,     0,  1182,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,  1272,     0,  1273,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,   770,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,   813,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,     0,     0,   831,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,   852,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,     0,     0,   933,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,  1149,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,  1168,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,     0,     0,  1208,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,  1209,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,     0,     0,  1210,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,  1211,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,  1244,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,     0,     0,  1288,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,  1294,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,     0,     0,  1295,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,  1312,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,  1315,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,     0,     0,  1318,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,  1339,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,     0,     0,  1342,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,  1372,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,  1374,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,     0,     0,  1376,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,  1389,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,     0,   598,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,     0,     0,     0,     0,     0,     0,  1220,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     525,     0,     0,     0,     0,   602,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,   561,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,   602,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   603,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,   649,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,   697,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,   698,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,   711,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   712,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,   713,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,   714,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,   715,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,   716,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   798,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,   799,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,   800,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,   895,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,   931,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,   932,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,   971,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,  1099,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,  1100,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,  1120,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,  1254,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,     0,     0,     0,  1255,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,     0,     0,     0,  1261,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,     0,     0,
       0,  1334,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,  1337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
     529,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,   654,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,   661,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,     0,     0,   676,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,   678,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,     0,     0,   680,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,   682,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,     0,
       0,   684,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,   686,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,     0,     0,   688,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
     690,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,   692,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,   694,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,     0,     0,   696,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,   700,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,     0,     0,   702,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,   704,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,     0,
       0,   706,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,   708,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,     0,     0,   710,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
     821,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,   822,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,   826,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,     0,     0,   827,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
       0,     0,   829,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,     0,     0,   848,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,     0,     0,   989,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,     0,
       0,   991,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,     0,     0,   993,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,     0,     0,   995,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,     0,     0,
     996,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,     0,     0,  1113,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,     0,     0,  1233,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,   525,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,   565,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,   569,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     570,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,   572,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   574,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,   575,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,   578,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,   579,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,   645,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,   646,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,   647,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,   653,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     675,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,   677,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   679,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,   681,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,   683,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,   685,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,   687,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,   689,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,   691,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,   693,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     695,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,   699,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   701,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,   703,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,   705,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,   707,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,   709,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,   759,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,   764,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,   769,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     771,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,   772,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   778,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,   785,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,   786,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,   787,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,   812,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,   814,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,   815,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,   816,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
     820,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352,
       0,   988,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,     0,     0,     0,     0,
     352,     0,   990,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     0,     0,
       0,   352,     0,   992,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,     0,   352,     0,   994,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,     0,
       0,     0,     0,   352,     0,   999,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
       0,     0,     0,     0,   352,     0,  1150,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,     0,     0,     0,     0,   352,     0,  1167,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,     0,     0,     0,     0,   352,     0,  1185,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     0,     0,     0,   352,     0,  1333,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,     0,     0,     0,     0,   352,     0,
    1387,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,     0,     0,     0,     0,   352
};

static const yytype_int16 yycheck[] =
{
       6,     4,     3,   206,     6,   402,   403,     6,     6,     4,
     324,     6,     4,   327,   217,     4,     4,    13,     4,     6,
     807,     4,     6,     4,     6,     4,     4,     4,     0,     4,
     312,   313,   314,     6,   316,   317,   318,     4,   738,     5,
      49,     5,     5,    52,     6,     6,    55,   179,   180,   181,
       4,     7,   255,   149,   257,     6,   149,    70,  1077,     6,
     156,     4,   149,     6,   139,   140,    79,   139,   140,   156,
     146,   147,   149,    86,    87,   139,   140,    90,    91,   156,
     212,    55,   157,   155,   811,   157,     4,     5,    94,    39,
      40,   155,    42,     4,     5,   150,    73,    74,    75,    76,
     155,     7,   139,   140,    81,    92,    49,    84,    94,    95,
      96,    97,    52,   139,   140,    55,   104,   105,   155,    37,
      38,    39,    40,   112,     6,    43,    37,    38,    39,    40,
     139,   140,    43,   135,   136,   137,     6,     7,   140,   141,
     149,   139,   140,   144,   157,    92,   149,   156,     6,   151,
     104,   105,   154,   156,   136,     6,   151,   149,   160,   161,
     162,   163,   949,   165,   166,   167,   168,   156,   170,   171,
     172,   157,   156,   156,   149,   156,  1195,   156,   156,   146,
     147,   156,   882,   156,   151,   136,   153,   149,     6,   191,
     156,   158,   156,   156,   156,   197,   198,   153,   139,   140,
    1219,   119,   120,   152,   206,     4,   155,   151,   119,   120,
     413,   139,   140,     7,   155,   529,   157,    70,   149,   161,
     126,   127,   128,   129,   166,   156,    79,   155,   170,   157,
     232,   233,   149,    86,    87,   146,   147,    90,    91,   241,
     242,   243,   153,   245,   194,   195,   248,   249,   150,   251,
      49,   454,   202,   155,    53,   149,   206,   150,   146,   147,
     262,   150,   155,   149,    63,   153,   155,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    70,
    1010,   139,   140,   315,   139,   140,    52,  1336,    79,    55,
     149,    57,   151,   325,   149,    86,    87,   155,   327,    90,
      91,   156,   126,   127,   128,   129,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,     7,   146,   147,   139,   140,   149,     7,   360,   153,
       5,   139,   140,   150,   366,   139,   140,    52,   155,   371,
      55,   156,    57,   149,   376,   377,   378,   379,   156,   661,
     149,   383,   156,   325,    59,     8,   388,   389,   390,  1408,
       6,     7,    37,    38,    39,    40,   157,   149,    43,   151,
       6,   402,   403,   405,   406,   407,   408,   409,   410,   139,
     140,    55,   414,   415,   416,   417,   418,     8,    55,   421,
     139,   140,   424,   425,    55,   155,   428,   429,   430,   431,
     432,   433,   139,   140,   436,   149,   155,   151,   440,   721,
      70,    55,    57,   445,   446,   727,   139,   140,   155,    79,
     400,   401,   139,   140,   149,    52,    86,    87,   408,   156,
      90,    91,   155,   149,   466,   151,   748,   469,   155,   468,
     126,   127,   128,   129,   119,   120,   126,   127,   128,   129,
     591,   592,   593,   156,   139,   140,   428,   429,   430,  1276,
     146,   147,  1279,    55,    55,  1282,   146,   147,   440,    52,
     155,  1228,  1202,  1230,   155,  1232,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   149,   524,   151,   530,   148,   155,   157,   157,   531,
     529,   149,    52,   151,   157,     4,     4,   139,   140,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   155,    55,   139,   140,   148,   560,   561,
     874,   875,     4,   149,   566,   567,   157,   141,   142,   143,
    1357,   155,   149,   149,   148,   151,   139,   140,   580,   139,
     140,   139,   140,   585,   590,   591,   592,   593,   590,   591,
     592,   593,   155,   149,   161,   155,   598,   155,  1325,   166,
     602,   603,   149,   170,   151,  1392,   608,    70,  1395,   139,
     140,  1398,   149,   149,  1401,   151,    79,   151,   560,   621,
     149,   623,   151,    86,    87,   155,     6,    90,    91,    53,
     149,     4,   151,   635,     4,   156,   139,   140,   149,   149,
     642,  1428,   149,  1430,  1371,  1432,  1373,   649,  1375,   651,
     652,   601,   155,   149,  1381,   151,   598,   149,   608,    70,
    1057,  1058,   661,     7,   614,   232,   233,   149,    79,   139,
     140,   149,   139,   140,   149,    86,    87,     4,     6,    90,
      91,    70,     8,     6,   149,   155,   151,  1414,   155,  1416,
      79,  1418,     6,   635,   157,   697,   698,    86,    87,   149,
     642,    90,    91,   149,   149,   151,   151,     5,   149,   711,
     712,   713,   714,   715,   716,   717,    49,   149,   720,    52,
     156,   145,    55,   725,    57,   146,   147,   149,     4,   731,
     151,   149,   153,   151,   149,   156,  1018,   158,   151,   741,
     742,   743,   744,   745,   149,   149,   157,   151,   149,   173,
     151,   149,   149,   151,    70,   179,   180,   181,   325,   149,
     146,   147,   149,    79,    70,   151,   190,   153,   157,   193,
      86,    87,   158,    79,    90,    91,     6,   149,   720,   151,
      86,    87,   156,   149,    90,    91,   149,   156,   212,   213,
     149,   156,   151,   360,   155,   155,   157,   157,   149,   741,
     742,   743,   744,   753,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   155,   151,
     157,   153,   148,   825,   150,   155,  1223,   157,   149,     5,
     829,   833,     7,     8,   156,   259,   260,   155,    70,   157,
     155,   157,   157,   155,   155,   157,   157,    79,   798,   799,
     800,   157,   854,   855,    86,    87,   156,   156,    90,    91,
     151,   428,   429,   430,   151,    55,    70,    57,   139,   140,
     141,   142,   143,   440,     5,    79,   875,   148,   155,   446,
     157,   883,    86,    87,   151,     5,    90,    91,     6,     3,
       4,     6,   153,   895,   896,     9,    10,    11,   156,   107,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   155,   155,   157,   157,   157,     6,     4,   930,   931,
     932,   155,   155,   157,   157,   155,     6,   157,   940,   941,
     155,   155,   157,   157,     6,   155,   948,   157,     4,   155,
       6,   157,   151,   157,   956,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   971,
     972,   973,   156,   148,    70,   155,   155,   157,   157,     6,
     982,   980,   155,    79,   157,   987,   155,   155,   157,   157,
      86,    87,   148,   560,    90,    91,  1002,     7,   948,   566,
     567,  1003,   153,    70,   118,   155,   155,   157,   157,   123,
     124,   125,    79,   155,   956,   157,   151,   156,  1020,    86,
      87,  1023,     6,    90,    91,   139,   140,  1029,  1030,   157,
     144,   598,  1034,     7,  1237,   149,     7,     7,   152,  1041,
     154,   149,   156,   155,   155,   157,   157,  1053,   149,  1051,
      70,  1053,   155,   155,   157,   157,  1057,  1058,   155,    79,
     157,   157,   155,  1065,   157,   149,    86,    87,   635,     7,
      90,    91,   150,  1075,  1024,   642,   155,  1079,   157,   155,
    1082,   157,   155,   155,   157,   157,   149,  1093,     6,     6,
     157,  1093,     7,     7,     4,   104,   156,  1099,  1100,   150,
     155,   150,   150,   527,  1386,   155,   150,     6,   155,  1059,
       4,  1061,   152,  1063,     6,     4,     7,   107,  1120,     7,
       7,     7,   107,  1326,     7,  1075,     7,   107,  1078,  1079,
       7,     7,     4,     6,   153,   157,   157,   157,     6,  1421,
     152,  1423,     7,     7,     7,   153,     6,   149,   149,  1151,
     156,   156,     6,   720,     4,     6,   152,     6,     6,    12,
      13,  1443,   586,     7,   151,     6,     6,  1169,   136,  1171,
       7,    55,     7,   597,   741,   742,   743,   744,     7,  1181,
       7,  1183,    57,     7,  1186,     7,     7,     7,   150,  1191,
     150,   150,   150,     7,  1196,     7,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     7,    60,     6,     4,
      63,    64,     4,    66,    67,    68,     6,   156,  1220,    72,
     149,     7,  1223,     6,   156,  1227,     7,  1229,     7,  1231,
       7,     6,     6,     6,   658,     6,    55,     6,   157,  1241,
       4,     4,     4,  1245,  1186,     6,    99,   100,   101,     4,
       6,   149,  1254,  1255,   156,   150,   153,   150,     7,  1261,
       6,    63,     6,     6,     6,     6,  1268,     6,     5,     4,
    1272,   156,     6,   151,   156,     7,   156,  1227,  1220,  1229,
       7,  1231,   156,     7,     7,     7,   156,   156,     6,  1239,
       6,     6,  1242,     6,   156,   156,  1298,   156,   103,  1241,
     152,     6,     4,     6,   157,     6,   153,     6,    12,    13,
     155,  1313,     6,     6,  1316,     6,     6,  1319,     6,     6,
       6,  1323,     6,     5,   155,  1327,     6,  1329,     6,   107,
       6,     6,  1334,   757,   758,  1337,   760,     6,   762,   763,
       6,     6,   766,   767,     6,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     6,    60,     6,     6,    63,
      64,     6,    66,    67,    68,   156,     4,  1369,    72,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     6,  1329,
       6,  1383,   148,     7,     6,  1327,   153,  1329,     6,   956,
       5,   156,    53,     6,     6,    99,   100,   101,     6,     6,
       6,     6,   156,     6,   157,   157,  1412,     7,  1410,   156,
       6,   835,   836,   837,     6,     6,   156,   102,   156,     6,
     156,   845,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,  1439,   105,     6,   157,   148,     6,     6,
       6,  1383,   156,     6,     6,     6,   156,     6,   157,     6,
      70,     6,     4,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     6,     6,
       6,     6,   148,   156,     6,     6,     6,   901,     6,     6,
     157,     6,   156,   907,   156,     6,   156,     6,   156,   913,
     914,   915,     6,     6,     6,   919,     6,   156,     6,   156,
     924,   925,   926,   156,   156,     6,   156,     6,  1075,     6,
       6,     6,  1079,     6,     6,     6,   940,     6,     6,   894,
       3,  1298,   900,     3,   382,  1006,   950,    -1,    -1,    -1,
     954,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    55,    -1,    57,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1171,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,  1186,
    1044,  1045,  1046,  1047,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,
     118,    72,    -1,  1220,    -1,   123,   124,   125,     6,    -1,
      -1,    -1,    -1,  1087,    -1,    -1,    -1,    -1,    -1,    -1,
    1094,   139,   140,    -1,  1241,    -1,   144,  1101,    99,   100,
     101,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,  1166,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1327,    -1,  1329,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    -1,     6,    81,    -1,    -1,    84,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,  1369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1236,   118,    -1,    -1,  1383,    -1,   123,   124,
     125,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,   139,   140,    -1,   148,    -1,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,   157,    -1,    -1,     3,     4,     5,    -1,     7,
    1284,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    12,    13,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,  1338,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    60,    -1,    -1,    63,    64,
      -1,    66,    67,    68,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    99,   100,   101,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,   144,    -1,   146,   147,
      -1,   149,    -1,   151,    -1,   153,   154,    -1,   156,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    -1,    66,
      67,    68,    -1,    -1,   118,    72,    -1,    -1,    -1,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,
     144,    -1,    99,   100,   101,   149,    -1,     3,     4,     5,
     154,    -1,   156,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,
     157,    57,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    63,    64,    -1,    66,    67,    68,
      -1,    -1,   118,    72,    -1,    -1,    -1,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,
      99,   100,   101,   149,    -1,     3,     4,     5,   154,    -1,
     156,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    55,   157,    57,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,     6,    63,    64,    -1,    66,    67,    68,    -1,    -1,
     118,    72,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,   144,    -1,    99,   100,
     101,   149,    -1,     3,     4,    -1,   154,    -1,   156,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    -1,    -1,    55,   157,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    81,    -1,    -1,    84,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   118,     6,
      -1,    -1,   148,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,     3,     4,    -1,   154,    -1,   156,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     6,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,     3,
       4,    -1,   154,    -1,   156,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,
      84,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   118,     6,    -1,    -1,   148,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,   149,    -1,     3,     4,    -1,
     154,    -1,   156,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,   149,    -1,     3,     4,    -1,   154,    -1,
     156,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      -1,     3,     4,    81,    -1,    -1,    84,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,     3,     4,     5,   154,    -1,   156,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     152,    -1,   154,    -1,   156,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,   118,   119,
     120,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,     3,     4,    -1,   154,    -1,   156,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     118,   148,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,     3,
       4,    -1,   154,    -1,   156,     9,    10,    11,    -1,    -1,
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
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,
     144,     3,     4,     5,    -1,   149,    -1,     9,    10,    11,
     154,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,    -1,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,     7,    -1,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,     8,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     8,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,    -1,
      -1,   123,   124,   125,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,
      -1,    -1,   144,     8,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     8,    -1,    -1,    -1,   148,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       8,    -1,    -1,    -1,   148,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    70,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,     0,     1,    -1,
     148,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,    -1,    88,    89,    -1,    -1,    -1,
      93,    12,    13,    -1,    -1,    98,    99,   100,   101,    -1,
      -1,   104,    -1,   106,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    36,    -1,    -1,   121,   122,
      41,    42,    -1,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    12,    13,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,    -1,   104,    -1,   106,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    -1,    66,
      67,    68,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    99,   100,   101,   155,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,   155,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
     152,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,   152,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,   152,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,   152,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,   152,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
     152,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,   152,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,   152,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,   152,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,   152,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
     152,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,   152,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,   152,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,   152,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,   152,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
     152,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,   152,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,   150,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,   150,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,   150,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,   150,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,   150,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,   150,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,   150,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,   150,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,   150,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,   150,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,   150,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,   150,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,   150,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,   150,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,   150,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,   150,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,   150,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,   150,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,   150,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,   150,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
     150,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   160,   161,     6,     0,     4,    12,    13,    36,
      41,    42,    44,    45,    46,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    88,    89,    93,    98,    99,   100,   101,   104,   106,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     121,   122,   162,   164,   165,   183,   193,   198,   201,   202,
     203,   204,   205,   206,   207,   227,   228,   229,   230,   231,
     232,     3,     4,     5,     7,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    37,
      38,    39,    40,    43,   112,   118,   119,   120,   123,   124,
     125,   126,   127,   128,   129,   139,   140,   144,   146,   147,
     149,   151,   153,   154,   156,   181,   182,   233,   234,   246,
      13,    55,   149,     6,   156,     6,     6,     6,     6,   151,
     149,   156,   149,   149,     4,   149,   156,   149,   149,     4,
     156,   149,   149,    59,    55,    55,     6,    55,    55,    52,
      55,    57,    57,    49,    52,    55,    57,    52,    55,    57,
      52,    55,   149,    52,   156,   139,   140,   149,   156,   235,
     236,   235,   156,    49,    52,    55,   156,   235,     4,    49,
      53,    63,    55,    55,    52,     4,   112,   156,     4,     6,
      49,    52,    55,     4,     4,     4,     5,    35,    49,    52,
      55,    57,   140,   156,   198,   207,   233,   238,   239,   240,
       4,   149,   149,   149,     4,   156,   242,     4,   149,   149,
       6,   151,     4,     4,     5,   156,     5,   156,     6,   149,
     156,     4,   151,   153,   158,   182,   156,     5,   246,   149,
     151,   149,   151,   149,   151,   149,   151,   149,   151,   149,
     151,   149,   151,   149,   151,   149,   151,   149,   151,   149,
     151,   149,   151,   149,   151,   149,   151,   149,   151,   149,
     151,   149,   151,   149,   151,   149,   151,   149,   151,   149,
     151,   149,   149,   149,   149,     7,   149,   149,   149,     4,
     233,   233,   233,   233,   152,   156,   233,     4,   104,   105,
       4,     4,   198,   199,   200,   238,     6,     6,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   148,     6,     6,   233,     5,   233,   185,   233,
     140,   233,   240,   241,   233,   233,   149,   233,   241,   233,
     233,   149,   241,   233,   233,   238,   149,   156,   149,   149,
     239,   239,   239,   149,   194,   195,   196,   197,   149,   149,
     149,   238,   233,     4,   238,   235,   235,   235,   233,   233,
     139,   140,   156,   156,   235,   156,   156,   156,   139,   140,
     149,   200,   235,   156,   149,   156,   149,   149,   149,   239,
     238,   149,     4,     6,   151,   151,   200,     6,   156,   156,
     156,   151,   151,   151,   151,     5,   156,     5,     5,     5,
     156,   233,   240,   157,   241,     8,   141,     6,     6,   233,
     233,   233,   153,   233,   156,   107,   233,   233,   233,     6,
       6,   200,     6,   200,   238,   238,   151,   233,     4,   156,
     166,     6,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,     4,   245,   246,   245,   245,   245,
     233,   245,   245,   245,   151,   150,     7,   181,   241,   152,
       7,   181,   182,   153,     7,   151,   157,    49,    52,    55,
      57,   193,     6,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,     6,   150,
     155,   155,   152,   155,   184,   150,   141,   155,   157,   150,
     150,   233,   150,   157,   150,   150,   233,   157,   150,   150,
       7,   233,   233,   233,   233,     7,     7,   225,   225,   233,
     149,   149,   149,   149,   233,   233,   233,     7,   156,   150,
       6,   155,   155,   155,   235,   235,   199,   199,   155,   233,
     233,   233,   233,   211,   155,   200,   233,   233,   233,   233,
     233,     7,   226,     7,   233,     6,   233,   233,   157,   241,
     241,   241,   233,   233,   152,   156,   233,     4,   233,   241,
     157,   233,   156,   233,   240,   150,   150,   150,   104,   155,
     200,   156,     8,   150,   152,   157,   157,   150,   155,   157,
     233,   152,   182,   233,     4,    94,    95,    96,    97,   157,
     169,   173,   176,   178,   179,   150,   152,   150,   152,   150,
     152,   150,   152,   150,   152,   150,   152,   150,   152,   150,
     152,   150,   152,   150,   152,   150,   152,   155,   155,   150,
     152,   150,   152,   150,   152,   150,   152,   150,   152,   150,
     152,   155,   155,   155,   155,   155,   155,   151,   153,   150,
     155,   155,   150,   150,     6,   155,   150,   155,   238,   157,
     153,   181,   182,   246,   233,     6,     4,     4,   156,   243,
     152,   156,   156,   156,   156,     8,     6,   136,   163,   241,
     233,     6,     4,     7,   233,   240,   107,     7,     7,   150,
       7,   107,     7,     7,   150,   107,     7,     7,   233,   150,
     157,   150,   150,   233,   238,     4,   224,     6,   150,   190,
     233,   246,   190,   190,   190,   150,   150,   150,   238,   241,
     153,   235,   233,   233,   157,   157,   233,   235,   155,   155,
     155,    70,    79,    86,    87,    90,    91,   221,   222,   235,
     157,   208,   150,   157,   150,   150,   150,   233,     6,   233,
     150,   152,   152,   157,   157,   157,   152,   152,   241,   152,
     152,   157,   157,     8,   241,     7,     7,     7,   153,   233,
     157,   233,   233,     7,   153,   156,   238,     6,   152,   153,
     182,   245,   157,   170,   149,   149,   156,   180,     6,   233,
     233,   233,   233,   233,   233,   233,   233,   233,     4,   241,
     245,   233,   245,     6,   152,     4,   104,   105,   233,     6,
       6,     6,     7,   151,   242,   244,     6,   241,   241,   241,
     241,   233,   136,   245,   150,   155,     7,   235,    55,   238,
     238,     7,   238,    55,    57,   238,   238,     7,    57,   238,
     238,     6,     7,     7,     7,     7,    70,   223,     6,     7,
     150,   150,   150,   150,     7,     7,     7,     6,   157,     4,
     155,   155,   155,   157,   157,   235,   235,   235,     4,     6,
     156,   149,     6,    92,     6,    92,   157,   222,   155,   221,
       7,     6,     7,     7,     7,     6,   156,     6,     6,     6,
      55,   233,     6,     6,   157,   233,   157,   238,   238,   238,
       4,   155,     8,     8,   150,     4,     4,   238,   157,     6,
       4,     6,   149,   233,   233,   237,   238,   156,   150,   152,
     150,   152,   150,   152,   150,   152,   152,   150,   150,   150,
     150,   181,     7,   181,   182,   153,     7,     6,   242,   233,
     155,   157,   157,   157,   157,   157,     6,     6,   163,   233,
     156,   233,     6,   156,    63,   192,   192,   238,     6,   156,
     156,     6,     6,   238,   156,     6,     6,     5,   238,   238,
     238,     4,     6,   238,     7,     7,     7,     7,   238,   238,
     238,     7,     6,     7,   233,   233,   233,   156,   156,   155,
     157,   155,   157,   155,   157,   151,   233,   238,   233,     6,
       6,   233,   235,   157,     5,   156,   238,   156,   156,   156,
     238,   241,   156,     6,   152,     6,     6,   103,   233,   233,
     233,     6,     6,     7,   155,     6,   182,   167,   233,   155,
     155,   155,   157,   168,   233,   153,   238,   246,   233,     6,
       4,   243,     6,   152,   242,     6,     6,     6,     6,   245,
     155,   233,   233,   235,     6,     6,     6,   233,   233,     6,
     233,     5,     6,     6,   107,   191,   233,     6,   238,   238,
     238,   238,     6,     4,     6,     6,   233,   233,   246,   157,
     150,   155,   157,   199,   199,   235,     6,   212,   235,     6,
     213,   235,     6,   214,   233,   157,   155,   150,   157,   155,
       6,   140,   235,     6,   237,   235,   235,     6,   157,   233,
     238,   155,   157,     8,   157,   150,   156,   233,   246,   238,
     150,   155,   233,   233,   238,   156,   155,   157,     4,     6,
       6,     6,     7,     6,   153,     6,   233,   186,   157,   157,
     157,   157,     5,    53,     6,     6,     6,     6,     6,   156,
     156,     6,     6,   156,   233,   157,   157,   155,   156,   155,
     156,   155,   156,   152,     6,   238,     7,   156,   233,   155,
     157,   155,   155,     6,   157,   102,   233,   233,   241,     6,
       6,   157,   171,   233,   155,   155,   237,   233,     6,   242,
     105,   155,   188,     6,     6,     6,     6,     6,   156,   237,
     241,   199,   155,   157,   233,   235,   221,   233,   235,   221,
     233,   235,   221,     6,   155,   157,   238,   200,   157,   235,
       6,   241,   235,   233,   157,   157,   157,     6,   156,   233,
     233,   157,     6,   233,   155,   157,   189,   233,   157,   157,
     157,   233,   157,   155,   157,   157,   155,   157,   157,   155,
     157,   238,     6,    70,   157,   209,   156,   155,   157,   155,
       6,     6,   168,   150,   155,     6,   156,   155,     4,   157,
       6,     6,   157,     6,   215,   233,     6,     6,   216,   233,
       6,     6,   217,   233,     6,   157,   233,   221,   200,   241,
       6,   235,   241,   157,   174,   233,   237,   233,     5,   156,
     238,   156,   157,   156,   157,   156,   157,     6,     6,   157,
     157,   210,   157,   155,   157,     6,   156,   150,   157,   157,
     187,   233,   221,     6,   218,   221,     6,   219,   221,     6,
     220,   221,     6,   241,     6,   172,   245,   177,   156,     6,
     155,   157,     7,   157,   156,   157,   156,   157,   156,   157,
     157,   155,   157,   156,   237,   233,   246,     6,   221,     6,
     221,     6,   221,     6,   245,     6,   175,   245,   157,     7,
     157,   157,   157,   155,   157,     6,   246,     6,     6,     6,
     245,     6
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
#line 164 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 196 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 200 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 207 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 212 "Gmsh.y"
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
#line 226 "Gmsh.y"
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
#line 239 "Gmsh.y"
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
#line 267 "Gmsh.y"
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
#line 281 "Gmsh.y"
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
#line 292 "Gmsh.y"
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
#line 306 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 320 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 322 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 327 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 329 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 334 "Gmsh.y"
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
#line 438 "Gmsh.y"
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
#line 448 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 457 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 464 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 474 "Gmsh.y"
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
#line 483 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 492 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 499 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 509 "Gmsh.y"
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
#line 517 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 527 "Gmsh.y"
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
#line 546 "Gmsh.y"
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
#line 565 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 571 "Gmsh.y"
    {
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 578 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 579 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 580 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 581 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 582 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 586 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 587 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 596 "Gmsh.y"
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
#line 659 "Gmsh.y"
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
#line 689 "Gmsh.y"
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
#line 722 "Gmsh.y"
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
#line 768 "Gmsh.y"
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
#line 783 "Gmsh.y"
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
#line 799 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 808 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 814 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 823 "Gmsh.y"
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
#line 841 "Gmsh.y"
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
#line 859 "Gmsh.y"
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
#line 868 "Gmsh.y"
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
#line 880 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 885 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 893 "Gmsh.y"
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
#line 913 "Gmsh.y"
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
#line 936 "Gmsh.y"
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

  case 83:

/* Line 1464 of yacc.c  */
#line 947 "Gmsh.y"
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
#line 955 "Gmsh.y"
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
#line 977 "Gmsh.y"
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

  case 86:

/* Line 1464 of yacc.c  */
#line 1000 "Gmsh.y"
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

  case 87:

/* Line 1464 of yacc.c  */
#line 1026 "Gmsh.y"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 1047 "Gmsh.y"
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

  case 89:

/* Line 1464 of yacc.c  */
#line 1059 "Gmsh.y"
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

  case 93:

/* Line 1464 of yacc.c  */
#line 1077 "Gmsh.y"
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

  case 94:

/* Line 1464 of yacc.c  */
#line 1088 "Gmsh.y"
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

  case 95:

/* Line 1464 of yacc.c  */
#line 1099 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1101 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
    ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1113 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1119 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1131 "Gmsh.y"
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

  case 102:

/* Line 1464 of yacc.c  */
#line 1142 "Gmsh.y"
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

  case 103:

/* Line 1464 of yacc.c  */
#line 1157 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1170 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1174 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1184 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1188 "Gmsh.y"
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

  case 108:

/* Line 1464 of yacc.c  */
#line 1200 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1204 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1214 "Gmsh.y"
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

  case 111:

/* Line 1464 of yacc.c  */
#line 1237 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1241 "Gmsh.y"
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

  case 113:

/* Line 1464 of yacc.c  */
#line 1257 "Gmsh.y"
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

  case 114:

/* Line 1464 of yacc.c  */
#line 1279 "Gmsh.y"
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

  case 115:

/* Line 1464 of yacc.c  */
#line 1297 "Gmsh.y"
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

  case 116:

/* Line 1464 of yacc.c  */
#line 1318 "Gmsh.y"
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

  case 117:

/* Line 1464 of yacc.c  */
#line 1336 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1366 "Gmsh.y"
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

  case 119:

/* Line 1464 of yacc.c  */
#line 1396 "Gmsh.y"
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

  case 120:

/* Line 1464 of yacc.c  */
#line 1414 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1432 "Gmsh.y"
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

  case 122:

/* Line 1464 of yacc.c  */
#line 1458 "Gmsh.y"
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

  case 123:

/* Line 1464 of yacc.c  */
#line 1476 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1494 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1498 "Gmsh.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 1517 "Gmsh.y"
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

  case 127:

/* Line 1464 of yacc.c  */
#line 1535 "Gmsh.y"
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

  case 128:

/* Line 1464 of yacc.c  */
#line 1574 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1580 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 1586 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 1593 "Gmsh.y"
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

  case 132:

/* Line 1464 of yacc.c  */
#line 1618 "Gmsh.y"
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

  case 133:

/* Line 1464 of yacc.c  */
#line 1643 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1660 "Gmsh.y"
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

  case 135:

/* Line 1464 of yacc.c  */
#line 1678 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1708 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1712 "Gmsh.y"
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

  case 138:

/* Line 1464 of yacc.c  */
#line 1732 "Gmsh.y"
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

  case 139:

/* Line 1464 of yacc.c  */
#line 1750 "Gmsh.y"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 1767 "Gmsh.y"
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

  case 141:

/* Line 1464 of yacc.c  */
#line 1783 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1787 "Gmsh.y"
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

  case 143:

/* Line 1464 of yacc.c  */
#line 1809 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1814 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1819 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1824 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1829 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1834 "Gmsh.y"
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

  case 149:

/* Line 1464 of yacc.c  */
#line 1857 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1863 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1873 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1874 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1879 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1883 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1887 "Gmsh.y"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 1910 "Gmsh.y"
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

  case 157:

/* Line 1464 of yacc.c  */
#line 1933 "Gmsh.y"
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

  case 158:

/* Line 1464 of yacc.c  */
#line 1956 "Gmsh.y"
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

  case 159:

/* Line 1464 of yacc.c  */
#line 1984 "Gmsh.y"
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

  case 160:

/* Line 1464 of yacc.c  */
#line 2005 "Gmsh.y"
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

  case 161:

/* Line 1464 of yacc.c  */
#line 2029 "Gmsh.y"
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

  case 162:

/* Line 1464 of yacc.c  */
#line 2050 "Gmsh.y"
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

  case 163:

/* Line 1464 of yacc.c  */
#line 2071 "Gmsh.y"
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

  case 164:

/* Line 1464 of yacc.c  */
#line 2091 "Gmsh.y"
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

  case 165:

/* Line 1464 of yacc.c  */
#line 2203 "Gmsh.y"
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

  case 166:

/* Line 1464 of yacc.c  */
#line 2222 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2261 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2369 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 2378 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2384 "Gmsh.y"
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

  case 171:

/* Line 1464 of yacc.c  */
#line 2399 "Gmsh.y"
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

  case 172:

/* Line 1464 of yacc.c  */
#line 2427 "Gmsh.y"
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

  case 173:

/* Line 1464 of yacc.c  */
#line 2444 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2458 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 2464 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2470 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 2479 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 2493 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	Msg::StatusBar(2, true, "Reading '%s'...", tmp.c_str());
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

  case 179:

/* Line 1464 of yacc.c  */
#line 2538 "Gmsh.y"
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

  case 180:

/* Line 1464 of yacc.c  */
#line 2555 "Gmsh.y"
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

  case 181:

/* Line 1464 of yacc.c  */
#line 2570 "Gmsh.y"
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

  case 182:

/* Line 1464 of yacc.c  */
#line 2589 "Gmsh.y"
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

  case 183:

/* Line 1464 of yacc.c  */
#line 2601 "Gmsh.y"
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

  case 184:

/* Line 1464 of yacc.c  */
#line 2625 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2629 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2636 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2642 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2647 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2653 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2657 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2661 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 2671 "Gmsh.y"
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

  case 193:

/* Line 1464 of yacc.c  */
#line 2688 "Gmsh.y"
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

  case 194:

/* Line 1464 of yacc.c  */
#line 2705 "Gmsh.y"
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

  case 195:

/* Line 1464 of yacc.c  */
#line 2726 "Gmsh.y"
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

  case 196:

/* Line 1464 of yacc.c  */
#line 2747 "Gmsh.y"
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

  case 197:

/* Line 1464 of yacc.c  */
#line 2782 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2790 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2796 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2803 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2807 "Gmsh.y"
    {
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2816 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2824 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2832 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2840 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2845 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2853 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2858 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2866 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2871 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2879 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2884 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2892 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2899 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2906 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2913 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2920 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2927 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2934 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2941 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2948 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2955 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2960 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2967 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2972 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2984 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2991 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 2996 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3008 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3020 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3027 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3032 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3039 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3044 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3051 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3056 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3067 "Gmsh.y"
    {
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3070 "Gmsh.y"
    {
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3076 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3085 "Gmsh.y"
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

  case 244:

/* Line 1464 of yacc.c  */
#line 3105 "Gmsh.y"
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

  case 245:

/* Line 1464 of yacc.c  */
#line 3128 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3132 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3136 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3140 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3144 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3148 "Gmsh.y"
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

  case 251:

/* Line 1464 of yacc.c  */
#line 3167 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3179 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3183 "Gmsh.y"
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

  case 254:

/* Line 1464 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3202 "Gmsh.y"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 3214 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3218 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3223 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3227 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3234 "Gmsh.y"
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

  case 261:

/* Line 1464 of yacc.c  */
#line 3290 "Gmsh.y"
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

  case 262:

/* Line 1464 of yacc.c  */
#line 3360 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3365 "Gmsh.y"
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

  case 264:

/* Line 1464 of yacc.c  */
#line 3432 "Gmsh.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 3468 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3477 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3520 "Gmsh.y"
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

  case 268:

/* Line 1464 of yacc.c  */
#line 3545 "Gmsh.y"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 3573 "Gmsh.y"
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

  case 270:

/* Line 1464 of yacc.c  */
#line 3616 "Gmsh.y"
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

  case 271:

/* Line 1464 of yacc.c  */
#line 3639 "Gmsh.y"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 3662 "Gmsh.y"
    {
    ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3665 "Gmsh.y"
    {
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3674 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3678 "Gmsh.y"
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

  case 276:

/* Line 1464 of yacc.c  */
#line 3688 "Gmsh.y"
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

  case 277:

/* Line 1464 of yacc.c  */
#line 3722 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3723 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3728 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3735 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3748 "Gmsh.y"
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
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3767 "Gmsh.y"
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

  case 283:

/* Line 1464 of yacc.c  */
#line 3794 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3795 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3796 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3797 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3798 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3799 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3800 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3801 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3803 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3809 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3810 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3811 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3812 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3813 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3814 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3815 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3816 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3817 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3818 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3819 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3820 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3821 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3822 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3823 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3824 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3825 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3826 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3827 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3828 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3829 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3830 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3831 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3832 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3833 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3834 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3835 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3836 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3837 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3838 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3839 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3840 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3842 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3843 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3844 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3845 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3846 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3847 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3848 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3849 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3850 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3851 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3852 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3853 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3854 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3855 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3856 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3857 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3858 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3860 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3861 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3862 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3871 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3872 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3873 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3874 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3875 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3876 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3877 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3882 "Gmsh.y"
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

  case 353:

/* Line 1464 of yacc.c  */
#line 3902 "Gmsh.y"
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

  case 354:

/* Line 1464 of yacc.c  */
#line 3921 "Gmsh.y"
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

  case 355:

/* Line 1464 of yacc.c  */
#line 3939 "Gmsh.y"
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

  case 356:

/* Line 1464 of yacc.c  */
#line 3951 "Gmsh.y"
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

  case 357:

/* Line 1464 of yacc.c  */
#line 3968 "Gmsh.y"
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

  case 358:

/* Line 1464 of yacc.c  */
#line 3989 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3994 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3999 "Gmsh.y"
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

  case 361:

/* Line 1464 of yacc.c  */
#line 4009 "Gmsh.y"
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

  case 362:

/* Line 1464 of yacc.c  */
#line 4019 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4031 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4035 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4039 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4054 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4062 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4074 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4081 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4086 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4090 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4095 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4099 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4107 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4118 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4122 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4134 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4142 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4150 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4157 "Gmsh.y"
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

  case 386:

/* Line 1464 of yacc.c  */
#line 4168 "Gmsh.y"
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

  case 387:

/* Line 1464 of yacc.c  */
#line 4188 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4192 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4196 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4200 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4204 "Gmsh.y"
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

  case 392:

/* Line 1464 of yacc.c  */
#line 4214 "Gmsh.y"
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

  case 393:

/* Line 1464 of yacc.c  */
#line 4224 "Gmsh.y"
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

  case 394:

/* Line 1464 of yacc.c  */
#line 4236 "Gmsh.y"
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

  case 395:

/* Line 1464 of yacc.c  */
#line 4248 "Gmsh.y"
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

  case 396:

/* Line 1464 of yacc.c  */
#line 4269 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4274 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4278 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4282 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4294 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4298 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4310 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4317 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4327 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4331 "Gmsh.y"
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

  case 406:

/* Line 1464 of yacc.c  */
#line 4346 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4351 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4358 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4362 "Gmsh.y"
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

  case 410:

/* Line 1464 of yacc.c  */
#line 4375 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4383 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 4394 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 4398 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 4406 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4414 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 4422 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 4430 "Gmsh.y"
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

  case 418:

/* Line 1464 of yacc.c  */
#line 4444 "Gmsh.y"
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

  case 419:

/* Line 1464 of yacc.c  */
#line 4458 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4462 "Gmsh.y"
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
#line 10142 "Gmsh.tab.cpp"
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
#line 4482 "Gmsh.y"


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

