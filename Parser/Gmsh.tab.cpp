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
     tError = 292,
     tSprintf = 293,
     tStrCat = 294,
     tStrPrefix = 295,
     tStrRelative = 296,
     tBoundingBox = 297,
     tDraw = 298,
     tToday = 299,
     tSyncModel = 300,
     tCreateTopology = 301,
     tCreateTopologyNoHoles = 302,
     tDistanceFunction = 303,
     tDefineConstant = 304,
     tPoint = 305,
     tCircle = 306,
     tEllipse = 307,
     tLine = 308,
     tSphere = 309,
     tPolarSphere = 310,
     tSurface = 311,
     tSpline = 312,
     tVolume = 313,
     tCharacteristic = 314,
     tLength = 315,
     tParametric = 316,
     tElliptic = 317,
     tRefineMesh = 318,
     tPlane = 319,
     tRuled = 320,
     tTransfinite = 321,
     tComplex = 322,
     tPhysical = 323,
     tCompound = 324,
     tPeriodic = 325,
     tUsing = 326,
     tPlugin = 327,
     tDegenerated = 328,
     tRotate = 329,
     tTranslate = 330,
     tSymmetry = 331,
     tDilate = 332,
     tExtrude = 333,
     tLevelset = 334,
     tRecombine = 335,
     tSmoother = 336,
     tSplit = 337,
     tDelete = 338,
     tCoherence = 339,
     tIntersect = 340,
     tMeshAlgorithm = 341,
     tLayers = 342,
     tHole = 343,
     tAlias = 344,
     tAliasWithOptions = 345,
     tQuadTriDbl = 346,
     tQuadTriSngl = 347,
     tRecombLaterals = 348,
     tTransfQuadTri = 349,
     tText2D = 350,
     tText3D = 351,
     tInterpolationScheme = 352,
     tTime = 353,
     tCombine = 354,
     tBSpline = 355,
     tBezier = 356,
     tNurbs = 357,
     tNurbsOrder = 358,
     tNurbsKnots = 359,
     tColor = 360,
     tColorTable = 361,
     tFor = 362,
     tIn = 363,
     tEndFor = 364,
     tIf = 365,
     tEndIf = 366,
     tExit = 367,
     tAbort = 368,
     tField = 369,
     tReturn = 370,
     tCall = 371,
     tFunction = 372,
     tShow = 373,
     tHide = 374,
     tGetValue = 375,
     tGetEnv = 376,
     tGetString = 377,
     tHomology = 378,
     tCohomology = 379,
     tGMSH_MAJOR_VERSION = 380,
     tGMSH_MINOR_VERSION = 381,
     tGMSH_PATCH_VERSION = 382,
     tAFFECTDIVIDE = 383,
     tAFFECTTIMES = 384,
     tAFFECTMINUS = 385,
     tAFFECTPLUS = 386,
     tOR = 387,
     tAND = 388,
     tNOTEQUAL = 389,
     tEQUAL = 390,
     tGREATEROREQUAL = 391,
     tLESSOREQUAL = 392,
     UNARYPREC = 393,
     tMINUSMINUS = 394,
     tPLUSPLUS = 395
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
#line 360 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 372 "Gmsh.tab.cpp"

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
#define YYLAST   7632

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  427
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1480

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   395

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   146,     2,   156,     2,   145,     2,     2,
     151,   152,   143,   141,   157,   142,   155,   144,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     137,     2,   138,   132,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   153,     2,   154,   150,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   158,     2,   159,   160,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   133,   134,   135,
     136,   139,   140,   147,   148,   149
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
     275,   285,   289,   296,   301,   308,   318,   325,   335,   341,
     350,   359,   371,   378,   388,   394,   402,   412,   422,   434,
     442,   452,   462,   463,   465,   466,   470,   476,   477,   487,
     491,   497,   498,   501,   505,   511,   515,   517,   519,   520,
     526,   527,   530,   538,   539,   549,   556,   564,   569,   577,
     586,   595,   603,   611,   623,   632,   641,   642,   652,   661,
     671,   675,   680,   691,   699,   707,   716,   725,   738,   739,
     749,   758,   766,   775,   776,   786,   792,   804,   810,   820,
     830,   835,   845,   855,   857,   859,   860,   863,   870,   877,
     884,   891,   900,   911,   926,   943,   956,   965,   974,   981,
     996,  1001,  1008,  1015,  1019,  1024,  1030,  1034,  1038,  1043,
    1048,  1052,  1060,  1068,  1072,  1080,  1084,  1087,  1090,  1093,
    1096,  1112,  1115,  1118,  1121,  1124,  1131,  1140,  1149,  1160,
    1162,  1165,  1167,  1171,  1176,  1178,  1184,  1196,  1210,  1211,
    1219,  1220,  1234,  1235,  1251,  1252,  1259,  1268,  1277,  1286,
    1299,  1312,  1325,  1340,  1355,  1370,  1371,  1384,  1385,  1398,
    1399,  1412,  1413,  1430,  1431,  1448,  1449,  1466,  1467,  1486,
    1487,  1506,  1507,  1526,  1528,  1531,  1537,  1545,  1555,  1558,
    1561,  1565,  1568,  1572,  1582,  1589,  1590,  1594,  1595,  1597,
    1598,  1601,  1602,  1605,  1613,  1620,  1629,  1635,  1639,  1647,
    1653,  1660,  1667,  1680,  1691,  1702,  1713,  1724,  1727,  1731,
    1738,  1740,  1742,  1745,  1751,  1759,  1770,  1772,  1776,  1779,
    1782,  1785,  1789,  1793,  1797,  1801,  1805,  1809,  1813,  1817,
    1821,  1825,  1829,  1833,  1837,  1841,  1847,  1852,  1857,  1862,
    1867,  1872,  1877,  1882,  1887,  1892,  1897,  1904,  1909,  1914,
    1919,  1924,  1929,  1934,  1941,  1948,  1955,  1960,  1965,  1970,
    1975,  1980,  1985,  1990,  1995,  2000,  2005,  2010,  2017,  2022,
    2027,  2032,  2037,  2042,  2047,  2054,  2061,  2068,  2073,  2075,
    2077,  2079,  2081,  2083,  2085,  2087,  2089,  2095,  2100,  2105,
    2108,  2114,  2118,  2125,  2130,  2138,  2145,  2147,  2150,  2153,
    2157,  2161,  2173,  2183,  2191,  2199,  2201,  2205,  2207,  2209,
    2212,  2216,  2221,  2227,  2229,  2231,  2234,  2238,  2242,  2248,
    2253,  2256,  2259,  2262,  2265,  2271,  2277,  2283,  2289,  2291,
    2293,  2297,  2302,  2309,  2311,  2313,  2317,  2321,  2331,  2339,
    2341,  2347,  2351,  2358,  2360,  2364,  2366,  2368,  2372,  2379,
    2381,  2383,  2388,  2395,  2402,  2407,  2412,  2417
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     162,     0,    -1,   163,    -1,     1,     6,    -1,    -1,   163,
     164,    -1,   167,    -1,   166,    -1,   185,    -1,   195,    -1,
     200,    -1,   204,    -1,   205,    -1,   206,    -1,   209,    -1,
     229,    -1,   230,    -1,   231,    -1,   232,    -1,   208,    -1,
     207,    -1,   203,    -1,   234,    -1,   138,    -1,   138,   138,
      -1,    36,   151,     5,   152,     6,    -1,    37,   151,     5,
     152,     6,    -1,    36,   151,     5,   152,   165,   247,     6,
      -1,    36,   151,     5,   157,   243,   152,     6,    -1,    37,
     151,     5,   157,   243,   152,     6,    -1,    36,   151,     5,
     157,   243,   152,   165,   247,     6,    -1,     4,     5,   158,
     168,   159,     6,    -1,    89,     4,   153,   235,   154,     6,
      -1,    90,     4,   153,   235,   154,     6,    -1,    -1,   168,
     171,    -1,   168,   175,    -1,   168,   178,    -1,   168,   180,
      -1,   168,   181,    -1,   235,    -1,   169,   157,   235,    -1,
     235,    -1,   170,   157,   235,    -1,    -1,    -1,     4,   172,
     151,   169,   152,   173,   158,   170,   159,     6,    -1,   247,
      -1,   174,   157,   247,    -1,    -1,    95,   151,   235,   157,
     235,   157,   235,   152,   176,   158,   174,   159,     6,    -1,
     247,    -1,   177,   157,   247,    -1,    -1,    96,   151,   235,
     157,   235,   157,   235,   157,   235,   152,   179,   158,   177,
     159,     6,    -1,    97,   158,   239,   159,   158,   239,   159,
       6,    -1,    97,   158,   239,   159,   158,   239,   159,   158,
     239,   159,   158,   239,   159,     6,    -1,    -1,    98,   182,
     158,   170,   159,     6,    -1,     7,    -1,   131,    -1,   130,
      -1,   129,    -1,   128,    -1,   149,    -1,   148,    -1,    49,
     153,   187,   154,     6,    -1,     4,   183,   240,     6,    -1,
       4,   153,   154,   183,   240,     6,    -1,     4,   153,   235,
     154,   183,   235,     6,    -1,     4,   153,   158,   243,   159,
     154,   183,   240,     6,    -1,     4,   184,     6,    -1,     4,
     153,   235,   154,   184,     6,    -1,     4,     7,   248,     6,
      -1,     4,   155,     4,     7,   248,     6,    -1,     4,   153,
     235,   154,   155,     4,     7,   248,     6,    -1,     4,   155,
       4,   183,   235,     6,    -1,     4,   153,   235,   154,   155,
       4,   183,   235,     6,    -1,     4,   155,     4,   184,     6,
      -1,     4,   153,   235,   154,   155,     4,   184,     6,    -1,
       4,   155,   105,   155,     4,     7,   244,     6,    -1,     4,
     153,   235,   154,   155,   105,   155,     4,     7,   244,     6,
      -1,     4,   155,   106,     7,   245,     6,    -1,     4,   153,
     235,   154,   155,   106,     7,   245,     6,    -1,     4,   114,
       7,   235,     6,    -1,   114,   153,   235,   154,     7,     4,
       6,    -1,   114,   153,   235,   154,   155,     4,     7,   235,
       6,    -1,   114,   153,   235,   154,   155,     4,     7,   248,
       6,    -1,   114,   153,   235,   154,   155,     4,     7,   158,
     243,   159,     6,    -1,   114,   153,   235,   154,   155,     4,
       6,    -1,    72,   151,     4,   152,   155,     4,     7,   235,
       6,    -1,    72,   151,     4,   152,   155,     4,     7,   248,
       6,    -1,    -1,   157,    -1,    -1,   187,   186,     4,    -1,
     187,   186,     4,     7,   235,    -1,    -1,   187,   186,     4,
       7,   158,   235,   188,   190,   159,    -1,   235,     7,   248,
      -1,   189,   157,   235,     7,   248,    -1,    -1,   190,   191,
      -1,   157,     4,   240,    -1,   157,     4,   158,   189,   159,
      -1,   157,     4,     5,    -1,   235,    -1,   248,    -1,    -1,
     108,    54,   158,   235,   159,    -1,    -1,    64,   237,    -1,
      50,   151,   235,   152,     7,   237,     6,    -1,    -1,    68,
      50,   196,   151,   192,   152,     7,   240,     6,    -1,    59,
      60,   240,     7,   235,     6,    -1,    53,   151,   235,   152,
       7,   240,     6,    -1,    73,    53,   240,     6,    -1,    57,
     151,   235,   152,     7,   240,     6,    -1,    51,   151,   235,
     152,     7,   240,   194,     6,    -1,    52,   151,   235,   152,
       7,   240,   194,     6,    -1,   100,   151,   235,   152,     7,
     240,     6,    -1,   101,   151,   235,   152,     7,   240,     6,
      -1,   102,   151,   235,   152,     7,   240,   104,   240,   103,
     235,     6,    -1,    53,     4,   151,   235,   152,     7,   240,
       6,    -1,    69,    53,   151,   235,   152,     7,   240,     6,
      -1,    -1,    68,    53,   197,   151,   192,   152,     7,   240,
       6,    -1,    64,    56,   151,   235,   152,     7,   240,     6,
      -1,    65,    56,   151,   235,   152,     7,   240,   193,     6,
      -1,    12,    13,     6,    -1,    13,    56,   235,     6,    -1,
      61,    56,   151,   235,   152,     7,     5,     5,     5,     6,
      -1,    54,   151,   235,   152,     7,   240,     6,    -1,    55,
     151,   235,   152,     7,   240,     6,    -1,    56,     4,   151,
     235,   152,     7,   240,     6,    -1,    69,    56,   151,   235,
     152,     7,   240,     6,    -1,    69,    56,   151,   235,   152,
       7,   240,     4,   158,   239,   159,     6,    -1,    -1,    68,
      56,   198,   151,   192,   152,     7,   240,     6,    -1,    67,
      58,   151,   235,   152,     7,   240,     6,    -1,    58,   151,
     235,   152,     7,   240,     6,    -1,    69,    58,   151,   235,
     152,     7,   240,     6,    -1,    -1,    68,    58,   199,   151,
     192,   152,     7,   240,     6,    -1,    75,   237,   158,   201,
     159,    -1,    74,   158,   237,   157,   237,   157,   235,   159,
     158,   201,   159,    -1,    76,   237,   158,   201,   159,    -1,
      77,   158,   237,   157,   235,   159,   158,   201,   159,    -1,
      77,   158,   237,   157,   237,   159,   158,   201,   159,    -1,
       4,   158,   201,   159,    -1,    85,    53,   158,   243,   159,
      56,   158,   235,   159,    -1,    82,    53,   151,   235,   152,
     158,   243,   159,     6,    -1,   202,    -1,   200,    -1,    -1,
     202,   195,    -1,   202,    50,   158,   243,   159,     6,    -1,
     202,    53,   158,   243,   159,     6,    -1,   202,    56,   158,
     243,   159,     6,    -1,   202,    58,   158,   243,   159,     6,
      -1,    79,    64,   151,   235,   152,     7,   240,     6,    -1,
      79,    50,   151,   235,   152,     7,   158,   239,   159,     6,
      -1,    79,    64,   151,   235,   152,     7,   158,   237,   157,
     237,   157,   243,   159,     6,    -1,    79,    64,   151,   235,
     152,     7,   158,   237,   157,   237,   157,   237,   157,   243,
     159,     6,    -1,    79,    54,   151,   235,   152,     7,   158,
     237,   157,   243,   159,     6,    -1,    79,     4,   151,   235,
     152,     7,   240,     6,    -1,    79,     4,   151,   235,   152,
       7,     5,     6,    -1,    79,     4,   158,   235,   159,     6,
      -1,    79,     4,   151,   235,   152,     7,   158,   237,   157,
     237,   157,   243,   159,     6,    -1,    83,   158,   202,   159,
      -1,    83,   114,   153,   235,   154,     6,    -1,    83,     4,
     153,   235,   154,     6,    -1,    83,     4,     6,    -1,    83,
       4,     4,     6,    -1,   105,   244,   158,   202,   159,    -1,
     118,     5,     6,    -1,   119,     5,     6,    -1,   118,   158,
     202,   159,    -1,   119,   158,   202,   159,    -1,     4,   248,
       6,    -1,     4,     4,   153,   235,   154,   247,     6,    -1,
       4,     4,     4,   153,   235,   154,     6,    -1,     4,   235,
       6,    -1,    72,   151,     4,   152,   155,     4,     6,    -1,
      99,     4,     6,    -1,   112,     6,    -1,   113,     6,    -1,
      45,     6,    -1,    42,     6,    -1,    42,   158,   235,   157,
     235,   157,   235,   157,   235,   157,   235,   157,   235,   159,
       6,    -1,    43,     6,    -1,    46,     6,    -1,    47,     6,
      -1,    63,     6,    -1,   107,   151,   235,     8,   235,   152,
      -1,   107,   151,   235,     8,   235,     8,   235,   152,    -1,
     107,     4,   108,   158,   235,     8,   235,   159,    -1,   107,
       4,   108,   158,   235,     8,   235,     8,   235,   159,    -1,
     109,    -1,   117,     4,    -1,   115,    -1,   116,     4,     6,
      -1,   110,   151,   235,   152,    -1,   111,    -1,    78,   237,
     158,   202,   159,    -1,    78,   158,   237,   157,   237,   157,
     235,   159,   158,   202,   159,    -1,    78,   158,   237,   157,
     237,   157,   237,   157,   235,   159,   158,   202,   159,    -1,
      -1,    78,   237,   158,   202,   210,   223,   159,    -1,    -1,
      78,   158,   237,   157,   237,   157,   235,   159,   158,   202,
     211,   223,   159,    -1,    -1,    78,   158,   237,   157,   237,
     157,   237,   157,   235,   159,   158,   202,   212,   223,   159,
      -1,    -1,    78,   158,   202,   213,   223,   159,    -1,    78,
      50,   158,   235,   157,   237,   159,     6,    -1,    78,    53,
     158,   235,   157,   237,   159,     6,    -1,    78,    56,   158,
     235,   157,   237,   159,     6,    -1,    78,    50,   158,   235,
     157,   237,   157,   237,   157,   235,   159,     6,    -1,    78,
      53,   158,   235,   157,   237,   157,   237,   157,   235,   159,
       6,    -1,    78,    56,   158,   235,   157,   237,   157,   237,
     157,   235,   159,     6,    -1,    78,    50,   158,   235,   157,
     237,   157,   237,   157,   237,   157,   235,   159,     6,    -1,
      78,    53,   158,   235,   157,   237,   157,   237,   157,   237,
     157,   235,   159,     6,    -1,    78,    56,   158,   235,   157,
     237,   157,   237,   157,   237,   157,   235,   159,     6,    -1,
      -1,    78,    50,   158,   235,   157,   237,   159,   214,   158,
     223,   159,     6,    -1,    -1,    78,    53,   158,   235,   157,
     237,   159,   215,   158,   223,   159,     6,    -1,    -1,    78,
      56,   158,   235,   157,   237,   159,   216,   158,   223,   159,
       6,    -1,    -1,    78,    50,   158,   235,   157,   237,   157,
     237,   157,   235,   159,   217,   158,   223,   159,     6,    -1,
      -1,    78,    53,   158,   235,   157,   237,   157,   237,   157,
     235,   159,   218,   158,   223,   159,     6,    -1,    -1,    78,
      56,   158,   235,   157,   237,   157,   237,   157,   235,   159,
     219,   158,   223,   159,     6,    -1,    -1,    78,    50,   158,
     235,   157,   237,   157,   237,   157,   237,   157,   235,   159,
     220,   158,   223,   159,     6,    -1,    -1,    78,    53,   158,
     235,   157,   237,   157,   237,   157,   237,   157,   235,   159,
     221,   158,   223,   159,     6,    -1,    -1,    78,    56,   158,
     235,   157,   237,   157,   237,   157,   237,   157,   235,   159,
     222,   158,   223,   159,     6,    -1,   224,    -1,   223,   224,
      -1,    87,   158,   235,   159,     6,    -1,    87,   158,   240,
     157,   240,   159,     6,    -1,    87,   158,   240,   157,   240,
     157,   240,   159,     6,    -1,    80,     6,    -1,    91,     6,
      -1,    91,    93,     6,    -1,    92,     6,    -1,    92,    93,
       6,    -1,    88,   151,   235,   152,     7,   240,    71,   235,
       6,    -1,    71,     4,   153,   235,   154,     6,    -1,    -1,
      71,     4,   235,    -1,    -1,     4,    -1,    -1,     7,   240,
      -1,    -1,     7,   235,    -1,    66,    53,   241,     7,   235,
     225,     6,    -1,    66,    56,   241,   227,   226,     6,    -1,
      62,    56,   158,   235,   159,     7,   240,     6,    -1,    66,
      58,   241,   227,     6,    -1,    94,   241,     6,    -1,    86,
      56,   158,   243,   159,   235,     6,    -1,    80,    56,   241,
     228,     6,    -1,    81,    56,   240,     7,   235,     6,    -1,
      70,    53,   240,     7,   240,     6,    -1,    70,    56,   235,
     158,   243,   159,     7,   235,   158,   243,   159,     6,    -1,
      50,   158,   243,   159,   108,    56,   158,   235,   159,     6,
      -1,    53,   158,   243,   159,   108,    56,   158,   235,   159,
       6,    -1,    53,   158,   243,   159,   108,    58,   158,   235,
     159,     6,    -1,    56,   158,   243,   159,   108,    58,   158,
     235,   159,     6,    -1,    84,     6,    -1,    84,     4,     6,
      -1,    84,    50,   158,   243,   159,     6,    -1,   123,    -1,
     124,    -1,   233,     6,    -1,   233,   158,   240,   159,     6,
      -1,   233,   158,   240,   157,   240,   159,     6,    -1,   233,
     151,   240,   152,   158,   240,   157,   240,   159,     6,    -1,
     236,    -1,   151,   235,   152,    -1,   142,   235,    -1,   141,
     235,    -1,   146,   235,    -1,   235,   142,   235,    -1,   235,
     141,   235,    -1,   235,   143,   235,    -1,   235,   144,   235,
      -1,   235,   145,   235,    -1,   235,   150,   235,    -1,   235,
     137,   235,    -1,   235,   138,   235,    -1,   235,   140,   235,
      -1,   235,   139,   235,    -1,   235,   136,   235,    -1,   235,
     135,   235,    -1,   235,   134,   235,    -1,   235,   133,   235,
      -1,   235,   132,   235,     8,   235,    -1,    14,   151,   235,
     152,    -1,    15,   151,   235,   152,    -1,    16,   151,   235,
     152,    -1,    17,   151,   235,   152,    -1,    18,   151,   235,
     152,    -1,    19,   151,   235,   152,    -1,    20,   151,   235,
     152,    -1,    21,   151,   235,   152,    -1,    22,   151,   235,
     152,    -1,    24,   151,   235,   152,    -1,    25,   151,   235,
     157,   235,   152,    -1,    26,   151,   235,   152,    -1,    27,
     151,   235,   152,    -1,    28,   151,   235,   152,    -1,    29,
     151,   235,   152,    -1,    30,   151,   235,   152,    -1,    31,
     151,   235,   152,    -1,    32,   151,   235,   157,   235,   152,
      -1,    33,   151,   235,   157,   235,   152,    -1,    34,   151,
     235,   157,   235,   152,    -1,    23,   151,   235,   152,    -1,
      14,   153,   235,   154,    -1,    15,   153,   235,   154,    -1,
      16,   153,   235,   154,    -1,    17,   153,   235,   154,    -1,
      18,   153,   235,   154,    -1,    19,   153,   235,   154,    -1,
      20,   153,   235,   154,    -1,    21,   153,   235,   154,    -1,
      22,   153,   235,   154,    -1,    24,   153,   235,   154,    -1,
      25,   153,   235,   157,   235,   154,    -1,    26,   153,   235,
     154,    -1,    27,   153,   235,   154,    -1,    28,   153,   235,
     154,    -1,    29,   153,   235,   154,    -1,    30,   153,   235,
     154,    -1,    31,   153,   235,   154,    -1,    32,   153,   235,
     157,   235,   154,    -1,    33,   153,   235,   157,   235,   154,
      -1,    34,   153,   235,   157,   235,   154,    -1,    23,   153,
     235,   154,    -1,     3,    -1,     9,    -1,    10,    -1,    11,
      -1,   125,    -1,   126,    -1,   127,    -1,     4,    -1,     4,
     160,   158,   235,   159,    -1,     4,   153,   235,   154,    -1,
     156,     4,   153,   154,    -1,     4,   184,    -1,     4,   153,
     235,   154,   184,    -1,     4,   155,     4,    -1,     4,   153,
     235,   154,   155,     4,    -1,     4,   155,     4,   184,    -1,
       4,   153,   235,   154,   155,     4,   184,    -1,   120,   151,
     247,   157,   235,   152,    -1,   238,    -1,   142,   237,    -1,
     141,   237,    -1,   237,   142,   237,    -1,   237,   141,   237,
      -1,   158,   235,   157,   235,   157,   235,   157,   235,   157,
     235,   159,    -1,   158,   235,   157,   235,   157,   235,   157,
     235,   159,    -1,   158,   235,   157,   235,   157,   235,   159,
      -1,   151,   235,   157,   235,   157,   235,   152,    -1,   240,
      -1,   239,   157,   240,    -1,   235,    -1,   242,    -1,   158,
     159,    -1,   158,   243,   159,    -1,   142,   158,   243,   159,
      -1,   235,   143,   158,   243,   159,    -1,   240,    -1,     5,
      -1,   142,   242,    -1,   235,   143,   242,    -1,   235,     8,
     235,    -1,   235,     8,   235,     8,   235,    -1,    50,   158,
     235,   159,    -1,    50,     5,    -1,    53,     5,    -1,    56,
       5,    -1,    58,     5,    -1,    68,    50,   158,   243,   159,
      -1,    68,    53,   158,   243,   159,    -1,    68,    56,   158,
     243,   159,    -1,    68,    58,   158,   243,   159,    -1,   200,
      -1,   209,    -1,     4,   153,   154,    -1,    35,   153,     4,
     154,    -1,     4,   153,   158,   243,   159,   154,    -1,   235,
      -1,   242,    -1,   243,   157,   235,    -1,   243,   157,   242,
      -1,   158,   235,   157,   235,   157,   235,   157,   235,   159,
      -1,   158,   235,   157,   235,   157,   235,   159,    -1,     4,
      -1,     4,   155,   105,   155,     4,    -1,   158,   246,   159,
      -1,     4,   153,   235,   154,   155,   106,    -1,   244,    -1,
     246,   157,   244,    -1,   248,    -1,     4,    -1,     4,   155,
       4,    -1,     4,   153,   235,   154,   155,     4,    -1,     5,
      -1,    44,    -1,   121,   151,   247,   152,    -1,   122,   151,
     247,   157,   247,   152,    -1,    39,   151,   247,   157,   247,
     152,    -1,    40,   151,   247,   152,    -1,    41,   151,   247,
     152,    -1,    38,   151,   247,   152,    -1,    38,   151,   247,
     157,   243,   152,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   164,   169,   171,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   195,   199,   206,   211,   216,   230,   243,
     256,   284,   298,   309,   324,   329,   330,   331,   332,   333,
     337,   339,   344,   346,   352,   456,   351,   474,   481,   492,
     491,   509,   516,   527,   526,   543,   560,   583,   582,   596,
     597,   598,   599,   600,   604,   605,   611,   613,   676,   706,
     739,   785,   800,   816,   825,   831,   840,   858,   876,   885,
     897,   902,   910,   930,   953,   964,   972,   994,  1017,  1043,
    1064,  1076,  1090,  1090,  1092,  1094,  1105,  1117,  1116,  1130,
    1136,  1143,  1144,  1148,  1159,  1174,  1187,  1191,  1202,  1205,
    1218,  1221,  1231,  1255,  1254,  1274,  1296,  1314,  1335,  1353,
    1383,  1413,  1431,  1449,  1475,  1493,  1512,  1511,  1534,  1552,
    1591,  1597,  1603,  1610,  1635,  1660,  1677,  1694,  1726,  1725,
    1749,  1767,  1784,  1801,  1800,  1826,  1831,  1836,  1841,  1846,
    1851,  1874,  1880,  1891,  1892,  1897,  1900,  1904,  1927,  1950,
    1973,  2001,  2022,  2045,  2066,  2088,  2108,  2220,  2239,  2277,
    2386,  2395,  2401,  2416,  2444,  2461,  2475,  2481,  2487,  2496,
    2510,  2555,  2572,  2587,  2606,  2618,  2642,  2646,  2651,  2658,
    2664,  2669,  2675,  2679,  2683,  2693,  2710,  2727,  2748,  2769,
    2804,  2812,  2818,  2825,  2829,  2838,  2846,  2854,  2863,  2862,
    2876,  2875,  2889,  2888,  2902,  2901,  2914,  2921,  2928,  2935,
    2942,  2949,  2956,  2963,  2970,  2978,  2977,  2990,  2989,  3002,
    3001,  3014,  3013,  3026,  3025,  3038,  3037,  3050,  3049,  3062,
    3061,  3074,  3073,  3089,  3092,  3098,  3107,  3127,  3150,  3154,
    3158,  3162,  3166,  3170,  3189,  3202,  3205,  3221,  3224,  3237,
    3240,  3246,  3249,  3256,  3312,  3382,  3387,  3454,  3490,  3499,
    3542,  3567,  3594,  3638,  3661,  3684,  3687,  3696,  3700,  3710,
    3745,  3746,  3750,  3755,  3766,  3783,  3811,  3812,  3813,  3814,
    3815,  3816,  3817,  3818,  3819,  3826,  3827,  3828,  3829,  3830,
    3831,  3832,  3833,  3834,  3835,  3836,  3837,  3838,  3839,  3840,
    3841,  3842,  3843,  3844,  3845,  3846,  3847,  3848,  3849,  3850,
    3851,  3852,  3853,  3854,  3855,  3856,  3857,  3859,  3860,  3861,
    3862,  3863,  3864,  3865,  3866,  3867,  3868,  3869,  3870,  3871,
    3872,  3873,  3874,  3875,  3876,  3877,  3878,  3879,  3888,  3889,
    3890,  3891,  3892,  3893,  3894,  3898,  3918,  3937,  3955,  3967,
    3984,  4005,  4010,  4015,  4025,  4035,  4043,  4047,  4051,  4055,
    4059,  4066,  4070,  4074,  4078,  4085,  4090,  4097,  4102,  4106,
    4111,  4115,  4123,  4134,  4138,  4150,  4158,  4166,  4173,  4184,
    4204,  4208,  4212,  4216,  4220,  4238,  4256,  4274,  4292,  4302,
    4312,  4324,  4336,  4357,  4362,  4366,  4370,  4382,  4386,  4398,
    4405,  4415,  4419,  4434,  4439,  4446,  4450,  4463,  4471,  4482,
    4486,  4494,  4502,  4510,  4518,  4532,  4546,  4550
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
  "tStrRelative", "tBoundingBox", "tDraw", "tToday", "tSyncModel",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tPoint", "tCircle", "tEllipse", "tLine", "tSphere",
  "tPolarSphere", "tSurface", "tSpline", "tVolume", "tCharacteristic",
  "tLength", "tParametric", "tElliptic", "tRefineMesh", "tPlane", "tRuled",
  "tTransfinite", "tComplex", "tPhysical", "tCompound", "tPeriodic",
  "tUsing", "tPlugin", "tDegenerated", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tLayers", "tHole", "tAlias", "tAliasWithOptions",
  "tQuadTriDbl", "tQuadTriSngl", "tRecombLaterals", "tTransfQuadTri",
  "tText2D", "tText3D", "tInterpolationScheme", "tTime", "tCombine",
  "tBSpline", "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit",
  "tAbort", "tField", "tReturn", "tCall", "tFunction", "tShow", "tHide",
  "tGetValue", "tGetEnv", "tGetString", "tHomology", "tCohomology",
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
     385,   386,    63,   387,   388,   389,   390,    60,    62,   391,
     392,    43,    45,    42,    47,    37,    33,   393,   394,   395,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   161,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   165,   165,   166,   166,   166,   166,   166,
     166,   167,   167,   167,   168,   168,   168,   168,   168,   168,
     169,   169,   170,   170,   172,   173,   171,   174,   174,   176,
     175,   177,   177,   179,   178,   180,   180,   182,   181,   183,
     183,   183,   183,   183,   184,   184,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   186,   186,   187,   187,   187,   188,   187,   189,
     189,   190,   190,   191,   191,   191,   192,   192,   193,   193,
     194,   194,   195,   196,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   197,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   198,   195,
     195,   195,   195,   199,   195,   200,   200,   200,   200,   200,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   202,
     202,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     204,   204,   204,   204,   204,   205,   206,   206,   206,   206,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   209,   209,   209,   210,   209,
     211,   209,   212,   209,   213,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   214,   209,   215,   209,   216,
     209,   217,   209,   218,   209,   219,   209,   220,   209,   221,
     209,   222,   209,   223,   223,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   225,   225,   226,   226,   227,
     227,   228,   228,   229,   229,   229,   229,   229,   229,   229,
     229,   230,   230,   231,   231,   231,   231,   232,   232,   232,
     233,   233,   234,   234,   234,   234,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   237,   237,   237,
     237,   238,   238,   238,   238,   239,   239,   240,   240,   240,
     240,   240,   240,   241,   241,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   243,   244,   244,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   248
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
       9,     3,     6,     4,     6,     9,     6,     9,     5,     8,
       8,    11,     6,     9,     5,     7,     9,     9,    11,     7,
       9,     9,     0,     1,     0,     3,     5,     0,     9,     3,
       5,     0,     2,     3,     5,     3,     1,     1,     0,     5,
       0,     2,     7,     0,     9,     6,     7,     4,     7,     8,
       8,     7,     7,    11,     8,     8,     0,     9,     8,     9,
       3,     4,    10,     7,     7,     8,     8,    12,     0,     9,
       8,     7,     8,     0,     9,     5,    11,     5,     9,     9,
       4,     9,     9,     1,     1,     0,     2,     6,     6,     6,
       6,     8,    10,    14,    16,    12,     8,     8,     6,    14,
       4,     6,     6,     3,     4,     5,     3,     3,     4,     4,
       3,     7,     7,     3,     7,     3,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     6,     8,     8,    10,     1,
       2,     1,     3,     4,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     8,     8,     8,    12,
      12,    12,    14,    14,    14,     0,    12,     0,    12,     0,
      12,     0,    16,     0,    16,     0,    16,     0,    18,     0,
      18,     0,    18,     1,     2,     5,     7,     9,     2,     2,
       3,     2,     3,     9,     6,     0,     3,     0,     1,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     7,     5,
       6,     6,    12,    10,    10,    10,    10,     2,     3,     6,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
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
       2,     2,     2,     2,     5,     5,     5,     5,     1,     1,
       3,     4,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       1,     4,     6,     6,     4,     4,     4,     6
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
       0,   199,     0,   204,     0,     0,     0,   201,     0,     0,
       0,     0,   280,   281,     5,     7,     6,     8,     9,    10,
      21,    11,    12,    13,    20,    19,    14,    15,    16,    17,
      18,     0,    22,   348,   355,   419,    59,   349,   350,   351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,     0,     0,     0,     0,
     352,   353,   354,    63,    62,    61,    60,     0,     0,     0,
      65,    64,     0,     0,     0,     0,   155,     0,     0,     0,
     286,     0,     0,     0,     0,     0,   189,     0,   191,   188,
     192,   193,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,   113,   126,   138,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   366,     0,     0,     0,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,   277,     0,     0,     0,     0,     0,   355,   384,
       0,     0,     0,     0,     0,     0,     0,     0,   398,   399,
     377,   383,     0,   378,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,   186,   187,     0,     0,   200,     0,
     155,     0,   155,   282,     0,     0,     0,     0,     0,     0,
     359,    34,   419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   355,   289,   288,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,    71,   183,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   130,
       0,     0,     0,     0,    92,     0,     0,   403,   404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   368,   367,     0,     0,     0,     0,   155,   155,
       0,     0,     0,     0,     0,     0,     0,   214,     0,   155,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   173,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,   390,     0,   391,   392,   393,     0,     0,     0,     0,
       0,   288,   385,   379,     0,     0,     0,   267,   185,     0,
       0,     0,     0,     0,   155,     0,     0,     0,     0,   202,
     176,     0,   177,     0,     0,     0,     0,     0,   361,     0,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   416,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,   287,    59,     0,     0,     0,
      59,     0,     0,     0,     0,     0,   150,     0,     0,     0,
       0,   156,    67,     0,   304,   303,   302,   301,   297,   298,
     300,   299,   292,   291,   293,   294,   295,   296,   131,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,   370,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
     170,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,   387,     0,   293,
     386,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,   178,   179,     0,     0,     0,     0,   357,   363,     0,
      44,     0,     0,     0,    57,     0,    35,    36,    37,    38,
      39,   306,   327,   307,   328,   308,   329,   309,   330,   310,
     331,   311,   332,   312,   333,   313,   334,   314,   335,   326,
     347,   315,   336,     0,     0,   317,   338,   318,   339,   319,
     340,   320,   341,   321,   342,   322,   343,     0,     0,     0,
       0,     0,     0,     0,     0,   426,     0,     0,   424,   425,
      84,     0,   421,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,   358,     0,     0,     0,
       0,     0,    25,    23,     0,     0,    26,     0,     0,    66,
      95,     0,   405,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   260,   258,     0,   266,     0,     0,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,   205,     0,
       0,     0,     0,     0,     0,   262,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   401,   389,
       0,     0,     0,     0,   381,     0,     0,     0,     0,     0,
       0,     0,   175,     0,     0,     0,     0,     0,     0,   283,
       0,     0,   360,     0,   356,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     417,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,    72,    74,    76,     0,     0,   413,     0,    82,     0,
       0,     0,     0,   305,    24,     0,     0,     0,     0,     0,
       0,     0,   110,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,     0,     0,   249,     0,   251,     0,   215,
     244,     0,     0,     0,   168,     0,     0,     0,   270,     0,
     172,   171,   279,     0,     0,    32,    33,     0,   394,   395,
     396,   397,   388,   382,     0,     0,     0,   410,     0,     0,
       0,   195,     0,     0,     0,     0,   182,   362,   181,     0,
       0,     0,     0,   375,     0,   316,   337,   323,   344,   324,
     345,   325,   346,     0,   427,   423,   365,   422,     0,    59,
       0,     0,     0,     0,    69,     0,     0,     0,   411,     0,
       0,     0,     0,    27,    28,     0,    29,     0,     0,    96,
     112,     0,     0,     0,     0,     0,   116,     0,     0,   133,
     134,     0,     0,   118,   141,     0,     0,     0,   108,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     184,     0,     0,     0,     0,   155,   155,     0,   225,     0,
     227,     0,   229,     0,   377,     0,     0,   250,   252,     0,
       0,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   402,   121,   122,     0,     0,     0,     0,    85,
      89,     0,     0,   284,   364,     0,    40,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,    79,     0,     0,
      80,     0,   414,   157,   158,   159,   160,     0,     0,    97,
       0,   111,   119,   120,   124,     0,     0,   135,     0,     0,
     265,   128,     0,     0,   256,   140,     0,     0,     0,     0,
     125,     0,   136,   142,     0,     0,     0,     0,   374,     0,
     373,     0,     0,     0,   216,     0,     0,   217,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,   166,     0,     0,     0,   161,     0,     0,     0,     0,
     408,     0,   197,   196,     0,     0,     0,     0,    45,     0,
       0,     0,   376,     0,     0,     0,   418,    70,    75,    77,
       0,    83,     0,    30,     0,   101,     0,     0,     0,     0,
       0,     0,   129,   114,   127,   139,   144,     0,     0,    90,
      91,   155,     0,   148,   149,     0,     0,     0,     0,     0,
       0,     0,   245,     0,     0,   155,     0,     0,     0,     0,
       0,   152,   151,     0,     0,     0,     0,    86,    87,     0,
       0,    41,     0,     0,     0,    43,    58,     0,   412,     0,
       0,   273,   274,   275,   276,   132,     0,     0,     0,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,   210,     0,     0,   162,     0,
       0,     0,   407,   198,     0,   285,     0,     0,     0,     0,
      81,     0,     0,    98,   102,     0,     0,     0,   146,     0,
     231,     0,     0,   233,     0,     0,   235,     0,     0,     0,
     246,     0,   206,     0,   155,     0,     0,     0,   123,    88,
       0,    49,     0,    55,     0,     0,     0,   109,   137,   272,
     371,   219,     0,     0,   226,   220,     0,     0,   228,   221,
       0,     0,   230,     0,     0,     0,   212,     0,   165,     0,
       0,     0,     0,     0,     0,     0,   105,     0,   103,     0,
     237,     0,   239,     0,   241,   247,   253,   211,   207,     0,
       0,     0,     0,    46,     0,    53,     0,     0,     0,   403,
       0,   222,     0,     0,   223,     0,     0,   224,     0,     0,
     169,     0,   163,     0,    47,     0,     0,   190,     0,   104,
       0,     0,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,     0,    99,   232,     0,   234,     0,   236,
       0,   164,    48,    50,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    56,   100,   238,   240,   242,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    74,   764,    75,    76,   480,  1125,  1131,
     686,   875,  1280,  1433,   687,  1392,  1464,   688,  1435,   689,
     690,   879,   147,   270,    77,   576,   364,  1235,  1418,  1290,
    1334,   797,  1163,  1053,   551,   390,   391,   392,   393,   238,
     338,   339,    80,    81,    82,    83,    84,    85,   239,   829,
    1353,  1409,   625,  1185,  1188,  1191,  1372,  1376,  1380,  1422,
    1425,  1428,   825,   826,   940,   794,   599,   634,    87,    88,
      89,    90,    91,    92,   240,   150,   403,   203,  1012,  1013,
     242,   243,   454,   250,   755,   907,   525,   526
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1105
static const yytype_int16 yypact[] =
{
    3973,    42,    92,  4057, -1105, -1105,  1839,    23,    13,   -53,
     -45,    35,   146,   151,   183,   191,    28,  -106,    53,    71,
       2,    87,    97,    17,   179,   189,   299,   313,   323,   398,
     335,   371,   389,   359,   584,   410,    27,   279,   391,   280,
     173,   173,   291,   538,    46,   401,   425,   488,    16,    64,
     492,   490,   548,   551,  1995,   555,   424,   427,   428,    18,
      34, -1105,   442, -1105,   577,   600,   466, -1105,   631,   632,
       0,    24, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105,    36, -1105, -1105,    31,   483,   421, -1105, -1105, -1105,
      -9,    -3,     3,    61,   176,   316,   327,   382,   416,   434,
     456,   477,   523,   567,   582,   587,   596,   599,   627,   645,
     648,   493,   503,   510,   522, -1105,   662,   537,   543,   544,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105,   497,   497,   497,
   -1105, -1105,   497,  3128,    15,   699,   321,  2451,   671,   797,
   -1105,   701,   702,   497,   714,   717, -1105,   497, -1105, -1105,
   -1105, -1105, -1105,   497,  3535,   497,   497,   591,   497,  3535,
     497,   497,   611,  3535,   497,   497,  2451,   612,   593, -1105,
     660,   674,  1995,  1995,  1995,   675, -1105, -1105, -1105, -1105,
     678,   679,   682,  2451,   497,   772,  2451,   173,   173,   173,
     497,   497,   -29, -1105,   220,   173,   646,   691,   696,  3351,
     232,   -12,   686,   689,   712,  1995,  2451,   727,    43,   705,
   -1105,   880, -1105,   724,   731,   732,   796,   826,   588, -1105,
     827,    32,   914,   945,   955,   721,  2601,  1648, -1105, -1105,
    3730, -1105,   903, -1105,   961,   497,   497,   497,   850,   497,
     855,   902,   497,   497, -1105, -1105,   497,  1015, -1105,  1020,
   -1105,  1024, -1105, -1105,  2451,  2451,   881,   497,  1037,   886,
   -1105, -1105, -1105,  1041,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   361,   361,   361,   361,
     497,   361,   361,   361,   350,   907,   907,   907,  6348,   100,
    3535,  5589,    88,   910,  1051,   920,   908, -1105,   919,  4132,
    1074, -1105, -1105,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497, -1105, -1105,
     849,   -66,   104,  4887,   114,  6369,  3535,  3750, -1105,   653,
    6390,  6411,   497,  6432,   677,  6453,  6474,   497,   687,  6495,
    6516,  1075,   497,   497,   497,   497,  1076,  1079,  1079,   497,
     930,   936,   937,   938,   497,   497,   497,  1083,  3439,   940,
    1087,   -83, -1105, -1105,  4913,  4939,   173,   173,   321,   321,
      69,   497,   497,   497,  3351,  3351,   497,  4132,    83, -1105,
     497,   497,   497,   497,   497,  1088,  1090,   497,  1093, -1105,
     497,   497,  1874, -1105,  3535,  3535,  3535,   497,   497,  3284,
    1094, -1105,   497, -1105, -1105, -1105,   944,   949,   951,   952,
    3535,   907, -1105, -1105,   688,   497,  2751, -1105, -1105,  6537,
    6558,  6579,   989,  4965, -1105,   953,  3769,  6600,  5612, -1105,
   -1105,  2187, -1105,  2337,   960,   693,   497,  5635,   -31,   497,
       6, -1105,  6621,  5658,  6642,  5681,  6663,  5704,  6684,  5727,
    6705,  5750,  6726,  5773,  6747,  5796,  6768,  5819,  6789,  5842,
    6810,  5865,  6831,  5888,  4991,  5017,  6852,  5911,  6873,  5934,
    6894,  5957,  6915,  5980,  6936,  6003,  6957,  6026,  5043,  5069,
    5095,  5121,  5147,  5173,   704,   165, -1105,   946,   962,   964,
    1193,   956,   966,   963,   497, -1105, -1105,  2451,   707,    72,
     421,   497,  1116,  1120,    20,   973, -1105,   101,    19,    30,
     106, -1105, -1105,  3788,  1642,  1026,  1325,  1325,   625,   625,
     625,   625,   471,   471,   907,   907,   907,   907, -1105,     9,
    3535,  1122,  3535,   497,  1123, -1105,  1126,  1125,  3535,  3535,
    1028,  1127,  1130,  6978,  1131,  1031,  1133,  1134,  6999,  1044,
    1142,  1146,   497,  7020,  4162,  7041,  7062,   497,  2451,  1150,
    1149,  7083,  3679,  3679,  3679,  3679,  7104,  7125,  7146,  2451,
    3535,  1001, -1105,   173,   497,   497, -1105, -1105,   998,  1000,
    3351,  5199,  5225,  5251,  4861,   384,   173,  2487,  7167,  4190,
    7188,  7209,  7230,   497,  1169,   497,  7251, -1105,  6049,  6072,
   -1105,   710,   711,   722,  6095,  6118, -1105,  3535,  6141,  1025,
    4218,  3535,  3535,  3535,  3535,   737, -1105,  3807,  3535,   907,
   -1105,  1171,  1174,  1176,  1029,   497,  2637,   497,   497, -1105,
       4, -1105, -1105,  1027,  2451,  1180,  6164,    84, -1105,  4246,
   -1105,  1036,  1038,  1032, -1105,  1185, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105,   497,   497, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105,   497,   497,   497,
     497,   497,   497,   497,  1188, -1105,  3535,   361, -1105, -1105,
   -1105,   497, -1105,   361,  1187,  1042,    21,   497,  1192,  1194,
    1279, -1105,  1195,  1048,    18,  1197, -1105,  3535,  3535,  3535,
    3535,   497, -1105,  1066,   361,   169, -1105,   206,  5277, -1105,
    1198,   173,  3750, -1105,  1152,  2451,  2451,  1199,  2451,   841,
    2451,  2451,  1203,  1153,  2451,  2451,  1452,  1206,  1207,  1208,
    1209,  3863, -1105, -1105,  1212, -1105,  1213,  1067,  7482, -1105,
    1069,  1071,  1086,  1232,  1233,  1234,  1237,   749,  1240,   178,
    5303,  5329, -1105, -1105,  4274,  -102,   173,   173,   173,  1241,
    1242,  1089,  1098,    12,    45,   -27, -1105,   274, -1105,   384,
    1245,  1248,  1249,  1251,  1252,  7482, -1105,  1612,  1102,  1255,
    1256,  1257,  1210,   497,  1258,  1259,   755,   -77, -1105, -1105,
     756,   763,   766,   769, -1105,   497,   786,  2451,  2451,  2451,
    1264,  5355, -1105,  3826,   352,  1265,  1266,  2451,  1113, -1105,
    1267,  1270, -1105,  1269, -1105,  1128,   497,   497,  2451,  1118,
   -1105,  7272,  6187,  7293,  6210,  7314,  6233,  7335,  6256,  6279,
   -1105,   215,  1138,  7356,  1139, -1105,   100,   208,  1140,  1271,
    1689, -1105, -1105, -1105,    18,   497, -1105,   789, -1105,   806,
     807,   811,   814,  7482, -1105,  1276,    11,  1290,   497,  3501,
      67,  1119,  1236,  1236,  2451,  1291,  1144,  1147,  1298,  1300,
    2451,  1151,  1301,  1306, -1105,  1308,  2451,  2451,  2451,  1311,
    1312, -1105,  2451,  1313,  1314,  1315,  1316,  2451,  2451,  2451,
   -1105,  1333,   263,   497,   497,   497,  1161,  1183,   -60,   -48,
     -26,  1191, -1105,  2451,   497, -1105,  1340, -1105,  1341, -1105,
   -1105,  3351,   -25,  2151, -1105,  1196,  1200,  2901, -1105,  3535,
   -1105, -1105, -1105,  1201,  1757, -1105, -1105,  1202, -1105, -1105,
   -1105, -1105,  7482, -1105,  1344,  1345,  1253, -1105,   497,   497,
     497, -1105,  1346,   417,  1204,  1356, -1105,   -31, -1105,   497,
    5381,  5407,   819, -1105,   497, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105,  1214, -1105, -1105, -1105, -1105,  2451,   421,
     497,  1362,  1366,    20, -1105,  1365,  6302,    18, -1105,  1367,
    1368,  1370,  1371, -1105, -1105,   361, -1105,  5433,   497,  7482,
   -1105,   497,   173,  1372,  1373,  1374, -1105,   497,   497, -1105,
   -1105,  1375,   497, -1105, -1105,  1377,  1378,  1380,  1275,   497,
   -1105,  1381,  2451,  2451,  2451,  2451,  1382,   996,  1387,   497,
   -1105,  3679,  4302,  7377,  4078,   321,   321,   173,  1388,   173,
    1391,   173,  1392,   497,   650,  1215,  7398, -1105, -1105,  4330,
     406, -1105,  1393,  1490,  1394,  2451,   173,  1490,  1396,   844,
     497, -1105, -1105, -1105, -1105,  2451,  4106,  1092,  7419, -1105,
   -1105,  3201,  2451, -1105, -1105,   219,  7482,   497,   497,  2451,
    1246,   847,  7482,  1399,  1400,  1401,  1966, -1105,  1398,  1402,
   -1105,  1272, -1105, -1105, -1105, -1105, -1105,  1404,   497,  7482,
    4358,   396, -1105, -1105, -1105,  4386,  4414, -1105,  4442,  1420,
   -1105, -1105,  1376,  1422,  7482, -1105,  1425,  1427,  1429,  1431,
   -1105,  1268, -1105, -1105,  4834,  3255,  1433,  1282, -1105,   497,
   -1105,  1283,  1284,   409, -1105,  1289,   415, -1105,  1293,   432,
   -1105,  1294,  6325,  1435,  2451,  1441,  1295,   497, -1105,  3051,
     463, -1105,   852,   469,   505, -1105,  1443,  4470,  1351,   497,
   -1105,   497, -1105, -1105,  3535,  3313,  1453,  1317, -1105,   497,
    5459,  5485, -1105,  2451,   497,  1454, -1105, -1105, -1105, -1105,
      18, -1105,  1383, -1105,  5511, -1105,  1466,  1467,  1471,  1472,
    1473,  1322, -1105, -1105, -1105, -1105, -1105,  2451,  3535, -1105,
   -1105,   321,  4134, -1105, -1105,  3351,   384,  3351,   384,  3351,
     384,  1476, -1105,   857,  2451, -1105,  4498,   173,  1477,  3535,
     173, -1105, -1105,   497,  4526,  4554,   860, -1105, -1105,  1478,
    1328,  7482,   497,   497,   861,  7482, -1105,  1481, -1105,   497,
     865, -1105, -1105, -1105, -1105, -1105,   497,   868,   872,  1329,
     497, -1105,  4582,   518,   175,  4610,   526,   297,  4638,   530,
     473, -1105,  2451,  1484,  1421,  2787,  1369,   540, -1105,   876,
     564,  3592, -1105, -1105,  1485, -1105,   497,  7440,  5537,    37,
   -1105,  5563,  1498, -1105, -1105,  4666,  1497,  1520, -1105,  4694,
    1522,   497,  1523,  1524,   497,  1525,  1526,   497,  1527,  1379,
   -1105,   497, -1105,   384, -1105,  3535,  1528,  3051, -1105, -1105,
     883, -1105,   497, -1105,  2451,   497,  2301, -1105, -1105, -1105,
   -1105, -1105,  1384,  4722, -1105, -1105,  1386,  4750, -1105, -1105,
    1389,  4778, -1105,  1529,  3612,   622,  2937,   891, -1105,   575,
     894,  1531,  1395,  7461,   895,  4806, -1105,  1648, -1105,   384,
    1533,   384,  1535,   384,  1539, -1105, -1105, -1105, -1105,   384,
    1543,  3535,  1544, -1105,   361, -1105,  1397,  1545,   904,  3631,
     673, -1105,  1403,   726, -1105,  1405,   736, -1105,  1411,   751,
   -1105,   905, -1105,   912, -1105,  1412,  2451, -1105,   497, -1105,
     421,  1546,   384,  1548,   384,  1550,   384, -1105,  1551,   361,
    1553,   361,   913,  3707, -1105, -1105,   785, -1105,   800, -1105,
     813, -1105, -1105, -1105,   917, -1105,  1554,   421,  1556,  1565,
    1567,   361,  1568, -1105, -1105, -1105, -1105, -1105, -1105, -1105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1105, -1105, -1105, -1105,   661, -1105, -1105, -1105, -1105,   250,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105,  -316,     1, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105,    95, -1105,   655,  1576, -1105, -1105, -1105, -1105,    -1,
    -400,  -206, -1105, -1105, -1105, -1105, -1105, -1105,  1595, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105,  -817,  -502, -1105, -1105,  1216, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105,    -2, -1105,    44, -1105, -1104,   508,
    -107,   738,   385,  -721,   568, -1105,  -291,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     151,  1202,    79,   417,   149,   259,   167,   148,   618,   619,
     680,   865,   972,   537,   432,   762,   541,  1044,   965,   332,
     218,   172,   248,   167,   753,   897,   527,   528,   529,   261,
     531,   532,   533,   906,   172,   266,   152,   441,   251,   406,
     407,   156,   263,  1363,   819,   163,   819,   428,     4,   429,
     211,   967,   164,   820,   471,   820,   473,   957,   406,   407,
     821,   822,   821,   822,   823,   824,   823,   824,   221,   153,
     222,   140,   141,  1050,   613,   386,   387,   388,   871,   536,
     193,   406,   407,   194,   202,   204,   569,   210,   524,   272,
     273,   570,     5,   406,   407,   540,   212,  1087,   154,  1088,
     213,   681,   682,   683,   684,   966,   155,   536,   425,  1089,
     214,  1090,   406,   407,   223,   406,   407,   140,   141,  1284,
     333,   334,   121,   122,   123,   124,   898,   899,   125,   408,
     219,  1091,   969,  1092,  1101,   325,   326,   327,   968,   420,
     328,   331,   274,  1297,   275,   337,   421,   763,   276,   763,
     277,   360,   158,   168,   278,   363,   279,   159,   260,   866,
     169,   365,   367,   370,   371,   685,   373,   367,   375,   376,
     168,   367,   379,   380,   220,   173,   249,   758,   754,   140,
     141,   162,   262,  1035,   267,   252,   268,   264,   759,   160,
     442,   269,   398,   157,   265,  1364,   430,   161,   404,   405,
     133,   134,   135,   136,   165,   128,   129,   405,   406,   407,
     406,   407,   280,   627,   281,  1029,   133,   134,   135,   136,
     140,   141,   166,   747,   406,   407,   620,   746,   133,   134,
     135,   136,   140,   141,   451,   367,   140,   141,   170,   871,
     626,   401,   402,   459,   460,   461,   819,   463,   171,   410,
     466,   467,   163,   418,   468,   820,   571,   175,   666,   757,
    1394,   572,   821,   822,   760,   477,   823,   824,   574,  1080,
    1081,   575,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   198,   199,  1142,   735,   530,   406,
     407,   916,   736,   970,   200,   336,   579,   282,   367,   283,
     174,   201,  1452,   542,  1342,   953,   133,   134,   135,   136,
     175,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   140,   141,   917,   176,
    1000,   406,   407,   579,   451,   524,   272,  1024,   819,   177,
     583,  1218,   579,   406,   407,   588,  1219,   820,   409,   178,
     593,   594,   595,   596,   821,   822,   873,   601,   823,   824,
     419,   180,   606,   607,   608,    39,    40,    41,    42,   121,
     122,   123,   124,    47,   179,   125,    50,   337,   337,   621,
     622,   623,   325,   326,   624,   406,   407,   185,   628,   629,
     630,   631,   632,  1120,  1121,   636,   272,   181,   638,   639,
     195,   971,   367,   367,   367,   644,   645,   648,   197,  1304,
     650,  1307,   182,  1310,   196,   183,   892,   184,   367,   205,
     616,   617,   894,   657,   659,   819,  1345,   215,   402,   121,
     122,   123,   124,   190,   820,   125,   191,   284,   192,   285,
     970,   821,   822,   915,   676,   823,   824,   679,   286,   678,
     287,   216,   128,   129,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   140,   141,
      93,   324,   357,   534,  1001,   268,    97,    98,    99,  1287,
     269,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   648,   288,   749,   289,  1385,   406,   407,   750,
     748,   217,   128,   129,   819,   224,   225,   406,   407,   369,
     406,   407,   226,   820,   374,   227,   406,   407,   378,   244,
     821,   822,   241,  1197,   823,   824,  1255,   290,   367,   291,
     367,   768,  1257,   406,   407,   245,   659,   772,   246,   247,
    1028,  1030,  1420,   254,  1423,   292,  1426,   293,   206,  1259,
     786,   207,  1429,   253,   208,   791,   799,   799,   799,   799,
     798,   798,   798,   798,   406,   407,   255,   294,   367,   295,
     406,   407,   810,   811,   354,   355,   356,   127,   814,   256,
    1267,   357,   130,   131,   132,  1456,  1269,  1458,   296,  1460,
     297,   835,  1348,   837,   186,   257,   258,   187,   137,   138,
     188,   271,   189,   139,   316,   367,   406,   407,   142,   367,
     367,   367,   367,   145,   317,   340,   367,   809,   455,   406,
     407,   318,  1270,   861,   815,   863,   864,   406,   407,   320,
     827,   406,   407,   319,   298,  1341,   299,   341,   872,   198,
     199,   406,   407,  1344,   381,  1181,  1182,  1347,   321,   200,
     241,   241,   241,   819,   322,   323,   209,  1355,   800,   801,
     802,   397,   820,   335,   400,   406,   407,   358,   359,   821,
     822,   881,   882,   823,   824,   538,   406,   407,   300,   361,
     301,  1357,   362,   241,   426,   883,   884,   885,   886,   887,
     888,   889,  1411,   302,   367,   303,   140,   141,   304,   893,
     305,   439,   372,   268,   819,   900,   146,   306,   269,   307,
     308,   383,   309,   820,  1147,   367,   367,   367,   367,   913,
     821,   822,   377,   382,   823,   824,   352,   353,   354,   355,
     356,   446,   474,   475,   447,   357,   399,   448,   310,   449,
     311,  1407,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   456,   355,   356,   312,   819,   313,   314,
     357,   315,   970,   342,   411,   970,   820,   819,   970,  1193,
     579,   384,   580,   821,   822,   920,   820,   823,   824,   641,
     642,   643,   819,   821,   822,   385,   389,   823,   824,   394,
     395,   820,  1441,   396,   579,   655,   585,   422,   821,   822,
     423,   984,   823,   824,   579,   579,   589,   656,   872,   412,
     674,  1299,   675,   992,   413,   568,   819,   733,   431,   734,
     958,   959,   960,   424,   579,   820,   745,   579,   579,   841,
     842,   819,   821,   822,  1010,  1011,   823,   824,   427,   579,
     820,   843,   434,   970,   819,  1443,   433,   821,   822,   435,
     436,   823,   824,   820,   579,  1445,   854,   926,  1031,   927,
     821,   822,   368,  1036,   823,   824,   579,   368,   951,   457,
    1447,   368,   579,   579,   987,   988,  1047,  1049,   970,   443,
     579,   970,   989,   579,   970,   990,   579,   970,   991,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   579,  1468,   993,  1037,   357,  1038,   437,
     444,  1082,  1083,  1084,   970,   765,   970,   767,   970,  1469,
     445,  1094,  1096,   579,   579,  1039,  1040,   458,   579,  1099,
    1041,   579,  1470,  1042,   452,   368,  1129,   367,  1130,   438,
     440,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   807,  1116,  1117,  1118,   357,
    1171,   579,  1172,  1206,  1224,   462,  1225,  1126,  1124,  1129,
     465,  1268,  1132,   464,  1312,  1100,  1313,   579,  1129,  1324,
    1329,   469,  1332,  1135,  1333,  1129,   470,  1336,  1136,   579,
     472,  1337,   846,   579,   476,  1356,   850,   851,   852,   853,
    1224,   478,  1391,   856,   479,   744,  1149,   481,   579,  1150,
    1410,   579,  1129,  1412,  1416,  1155,  1156,   357,   544,  1315,
    1158,  1438,   579,  1439,  1448,   543,   146,  1164,   368,  1449,
    1129,  1450,  1466,   545,  1471,  1176,  1472,  1174,   546,  1175,
     552,   602,   592,   597,   337,   337,   598,   603,   604,   605,
     609,  1192,   611,   612,   664,   633,  1151,   635,   649,   637,
    1211,   367,   651,   737,   452,   367,   792,   652,  1207,   653,
     654,   667,   673,   741,   738,  1216,   739,   806,   742,  1215,
     743,   891,   751,  1434,   752,  1220,  1221,   756,   766,   769,
     770,  1183,   771,  1186,   775,  1189,   774,   776,   778,   779,
     780,   781,   909,   910,   911,   912,  1234,  1200,  1386,   784,
    1203,  1204,   783,   785,   793,   795,   808,   812,  1462,   813,
    1465,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   368,   368,   368,   836,   357,  1252,   857,   848,
    1478,   858,   868,   859,   860,   867,   869,   876,   368,   877,
     878,   880,   890,   895,   660,  1266,   896,   451,   901,   740,
     902,   905,   904,   908,   914,   919,   924,  1274,   921,  1275,
     930,   931,   367,   935,   936,   937,   938,  1281,   941,   943,
     942,   944,  1285,   945,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   946,   947,
     948,   949,   357,   950,   952,   961,   367,   963,   962,   964,
     337,  1212,   973,  1302,   974,  1305,   975,  1308,   976,   977,
     979,   980,   981,   982,   985,   986,   983,   367,   997,  1002,
    1003,  1321,  1005,  1006,  1007,  1008,  1014,  1051,  1033,  1009,
    1327,  1328,  1043,   922,   923,   903,   925,  1331,   928,   929,
    1025,  1027,   932,   933,  1335,  1032,  1046,  1056,  1339,  1303,
    1052,  1306,  1057,  1309,  1059,  1058,  1060,  1063,   368,  1062,
     368,  1317,  1064,  1065,  1320,  1069,   660,   773,  1070,  1085,
    1072,  1073,  1074,  1075,  1132,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,  1373,
    1079,  1086,  1377,   357,  1093,  1381,  1097,  1098,   368,  1384,
    1113,  1114,  1119,   367,  1105,   367,  1112,  1115,  1106,  1110,
    1393,  1122,  1123,  1395,  1109,   994,   995,   996,  1137,  1133,
    1138,  1140,  1194,  1143,  1144,  1004,  1145,  1146,  1152,  1153,
    1154,  1157,  1159,  1162,  1160,   368,  1161,  1165,  1170,   368,
     368,   368,   368,  1173,  1184,  1419,   368,  1187,  1190,  1198,
    1201,  1389,  1205,  1226,  1223,  1230,  1227,  1228,  1231,   367,
    1233,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,  1240,  1247,  1232,  1242,   357,
    1241,  1243,  1055,  1244,  1454,  1245,  1453,  1246,  1061,  1250,
    1251,  1262,  1253,  1254,  1066,  1067,  1068,  1256,  1264,  1271,
    1071,  1258,  1260,  1265,  1273,  1076,  1077,  1078,   934,  1278,
    1286,  1474,   348,   349,   350,   351,   352,   353,   354,   355,
     356,  1095,  1291,  1292,   368,   357,  1279,  1293,  1294,  1295,
    1296,  1104,  1311,  1318,  1325,  1108,  1326,  1330,  1338,  1288,
    1350,  1359,  1351,    93,   228,   368,   368,   368,   368,    97,
      98,    99,  1366,  1368,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   230,  1369,  1354,  1371,  1374,
    1375,  1378,  1379,  1382,  1388,  1405,  1134,  1413,  1383,  1421,
     231,  1424,  1399,   232,  1401,  1427,   233,  1403,   234,  1430,
    1432,  1437,  1455,  1414,  1457,  1436,  1459,  1461,   235,  1463,
    1473,  1442,  1475,  1444,    39,    40,    41,    42,    43,  1446,
    1451,  1476,    47,  1477,  1479,    50,  1360,  1045,  1054,    78,
    1166,  1167,  1168,  1169,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,    86,  1276,
       0,  1139,   357,     0,   600,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,   130,   131,   132,   978,     0,
       0,     0,     0,  1208,     0,     0,     0,     0,     0,     0,
    1217,   414,  1199,  1298,     0,     0,   139,  1222,     0,     0,
       0,   416,     0,     0,     0,     0,   145,     0,   201,   453,
       0,    93,   228,     0,  1319,     0,     0,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1034,     0,     0,   231,     0,
       0,   232,  1263,     0,   233,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   368,     0,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
      47,     0,     0,    50,     0,     0,     0,     0,     0,     0,
    1387,     0,  1390,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,  1111,     0,     0,     0,     0,   127,     0,
       0,     0,  1314,   130,   131,   132,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,   137,
     366,     0,   357,     0,   139,     0,  1431,     0,     0,   142,
       0,     0,     0,     0,   145,     0,     0,   453,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1349,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   368,    93,    94,    95,   368,    96,     0,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,  1398,     0,     0,   121,   122,   123,
     124,     0,     0,   125,     0,     0,     7,     8,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   547,    18,    19,   548,    21,    22,
     549,    24,   550,    26,     0,    27,     0,   452,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,     0,     0,
       0,     0,   368,   126,     0,     0,     0,     0,     0,   127,
     128,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,  1229,     0,    56,    57,    58,     0,     0,     0,
     137,   138,     0,     0,     0,   139,   368,   140,   141,     0,
     142,     0,   143,     0,   144,   145,     0,   146,    93,   228,
     229,     0,     0,     0,    97,    98,    99,   368,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     230,     0,     0,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,     0,     0,   232,     0,
       0,   233,     0,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   368,     0,   368,     0,     0,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,   127,   357,     0,     0,     0,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   368,   137,   236,     0,     0,
       0,   139,     0,     0,     0,     0,   142,     0,     0,   368,
       0,   145,     0,   237,    93,   228,  1102,     0,     0,     0,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   236,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,  1396,   145,     0,  1103,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   671,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   236,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,     0,   145,     0,  1397,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   672,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   236,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,     0,   145,     0,   237,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   828,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   366,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,     0,   145,     0,   450,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   862,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   366,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,     0,   145,     0,   658,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1352,     0,     0,     7,
       8,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   547,    18,    19,
     548,    21,    22,   549,    24,   550,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,   137,   236,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   228,     0,   145,     0,  1107,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1408,     0,     0,     0,
       0,   231,     0,     0,   232,     0,     0,   233,     0,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,    93,   324,    47,     0,     0,    50,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,  1199,     0,     0,     0,   139,     0,     0,
       0,     0,   416,     0,    93,   324,   272,   145,     0,   201,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   121,
     122,   123,   124,     0,     0,   125,     0,     0,   127,     0,
       0,     0,     0,   130,   131,   132,     0,     0,     0,     0,
       0,  1249,     0,     0,     0,     0,     0,     0,     0,   137,
     138,     0,     0,     0,   139,     0,     0,     0,     0,   142,
       0,     0,   329,     0,   145,     0,   330,    93,   324,     0,
       0,     0,     0,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,  1277,
       0,   127,   128,   129,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,    93,   324,     0,   145,     0,  1214,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,   127,   357,     0,     0,     0,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,     0,     0,     0,
     139,     0,     0,     0,     0,   142,     0,     0,   646,     0,
     145,     0,   647,     0,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,   415,     0,     0,     0,   139,     0,     0,
       0,     0,   416,     0,    93,   324,     0,   145,     0,   201,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,    93,   228,
       0,     0,     0,     0,    97,    98,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     230,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   231,     0,     0,   232,   357,
       0,   233,     0,   234,     0,     0,     0,   610,  1358,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,  1406,     0,
      50,   127,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1440,   455,
       0,     0,   137,   138,     0,     0,     0,   139,     0,     0,
       0,     0,   142,     0,     0,   127,     0,   145,     0,  1048,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   366,     0,     0,
       0,   139,    93,   324,   272,     0,   142,     0,    97,    98,
      99,   145,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,  1467,     0,     0,   121,   122,   123,
     124,     0,     0,   125,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   455,     0,
       0,     0,   357,     0,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   455,     0,
       0,     0,   357,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   578,   355,   356,   668,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   761,     0,     0,   127,
     128,   129,     0,     0,   130,   131,   132,     0,     0,     0,
       0,     0,     0,     0,     0,   855,     0,     0,     0,     0,
     137,   138,     0,     0,     0,   139,     0,     0,     0,     0,
     142,     0,     0,     0,   999,   145,     0,     0,     0,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   456,   355,   356,     0,     0,     0,     0,
     357,     0,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   578,   355,   356,     0,     0,     0,     0,
     357,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   939,     0,     0,     0,   357,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,    -4,     1,     0,   357,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,    -4,
      -4,     0,     0,   357,     0,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     6,    -4,    -4,     0,     0,     0,    -4,     0,     7,
       8,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     9,    10,     0,    -4,    -4,     0,    11,
      12,     0,    13,    14,    15,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     7,     8,    52,    53,     0,     0,
       0,    54,     0,     0,     0,     0,    55,    56,    57,    58,
       0,     0,    59,     0,    60,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
      72,    73,   547,    18,    19,   548,    21,    22,   549,    24,
     550,    26,     0,    27,     0,     0,    30,    31,     0,    33,
      34,    35,     0,     0,     0,    38,     0,     0,     0,     0,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,    56,    57,    58,  1179,     0,  1180,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,  1209,     0,  1210,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,  1300,     0,  1301,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,   788,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,   831,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,   849,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,   874,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,   956,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,  1177,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,  1196,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,  1236,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,  1237,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,  1238,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,  1239,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,  1272,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,  1316,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,  1322,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,  1323,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,  1340,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,  1343,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,  1346,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,  1367,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,     0,  1370,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,  1400,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,  1402,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,     0,     0,     0,     0,     0,  1404,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,     0,  1417,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
       0,     0,  1248,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   535,     0,     0,     0,     0,   614,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,   573,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
     614,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,   615,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,   665,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,   713,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,   714,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
     727,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,   728,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,   729,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,   730,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,   731,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
     732,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,   816,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,   817,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,   818,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,   918,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
     954,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,   955,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,   998,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,  1127,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,  1128,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
    1148,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,     0,     0,     0,  1282,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,  1283,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,  1289,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,  1362,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,     0,     0,     0,
    1365,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,   539,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,   670,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,   677,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,   692,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,   694,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,   696,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,   698,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,   700,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,   702,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
     704,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,   706,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,   708,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,   710,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,   712,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,   716,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,   718,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,   720,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,   722,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,   724,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
     726,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,   839,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,   840,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,   844,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
       0,     0,   845,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,     0,     0,   847,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,     0,     0,   870,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,     0,
       0,  1016,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,     0,     0,  1018,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,     0,     0,  1020,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,     0,     0,
    1022,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,     0,     0,  1023,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,     0,     0,  1141,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,     0,     0,  1261,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
     535,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   577,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,   581,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   582,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,   584,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,   586,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,   587,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,   590,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,   591,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,   661,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
     662,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   663,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,   669,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   691,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,   693,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,   695,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,   697,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,   699,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,   701,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,   703,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
     705,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   707,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,   709,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   711,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,   715,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,   717,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,   719,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,   721,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,   723,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,   725,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
     777,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   782,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,   787,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   789,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,   790,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,   796,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,   803,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,   804,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,   805,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,   830,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
     832,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,   833,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,   834,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,   838,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357,     0,  1015,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,     0,
       0,     0,     0,   357,     0,  1017,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       0,     0,     0,     0,   357,     0,  1019,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,     0,     0,     0,     0,   357,     0,  1021,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     0,     0,     0,     0,   357,     0,  1026,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,     0,     0,     0,     0,   357,     0,  1178,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,     0,     0,     0,     0,   357,     0,
    1195,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,     0,     0,     0,     0,   357,
       0,  1213,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,     0,     0,     0,     0,
     357,     0,  1361,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,     0,     0,     0,
       0,   357,     0,  1415,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,     0,     0,
       0,     0,   357
};

static const yytype_int16 yycheck[] =
{
       6,  1105,     3,   209,     6,     5,     4,     6,   408,   409,
       4,     7,   829,   329,   220,     6,   332,     6,     6,     4,
       4,     4,     4,     4,     4,     4,   317,   318,   319,     5,
     321,   322,   323,   754,     4,     4,    13,     5,     4,   141,
     142,     6,     6,     6,    71,   151,    71,     4,     6,     6,
       4,     6,   158,    80,   260,    80,   262,   159,   141,   142,
      87,    88,    87,    88,    91,    92,    91,    92,     4,    56,
       6,   148,   149,     6,   157,   182,   183,   184,   155,     7,
      53,   141,   142,    56,    40,    41,   152,    43,     4,     5,
      96,   157,     0,   141,   142,     7,    50,   157,   151,   159,
      54,    95,    96,    97,    98,    93,   151,     7,   215,   157,
      64,   159,   141,   142,    50,   141,   142,   148,   149,  1223,
     105,   106,    38,    39,    40,    41,   105,   106,    44,   158,
     114,   157,   159,   159,   159,   137,   138,   139,    93,   151,
     142,   143,   151,  1247,   153,   146,   158,   138,   151,   138,
     153,   153,     6,   151,   151,   157,   153,     6,   158,   155,
     158,   163,   164,   165,   166,   159,   168,   169,   170,   171,
     151,   173,   174,   175,   158,   158,   158,   158,   158,   148,
     149,   153,   158,   904,   153,   151,   155,   151,   158,     6,
     158,   160,   194,   158,   158,   158,   153,     6,   200,   201,
     128,   129,   130,   131,   151,   121,   122,   209,   141,   142,
     141,   142,   151,   419,   153,     7,   128,   129,   130,   131,
     148,   149,   151,   539,   141,   142,   157,   155,   128,   129,
     130,   131,   148,   149,   236,   237,   148,   149,   151,   155,
     157,   197,   198,   245,   246,   247,    71,   249,   151,   205,
     252,   253,   151,   209,   256,    80,   152,   151,   464,   158,
    1364,   157,    87,    88,   158,   267,    91,    92,   154,     6,
       7,   157,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   141,   142,  1037,   152,   320,   141,
     142,   152,   157,   825,   151,     4,   157,   151,   330,   153,
     151,   158,  1436,   332,   159,   157,   128,   129,   130,   131,
     151,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   148,   149,   152,    60,
       8,   141,   142,   157,   366,     4,     5,   152,    71,    56,
     372,   152,   157,   141,   142,   377,   157,    80,   158,    56,
     382,   383,   384,   385,    87,    88,   677,   389,    91,    92,
     158,    56,   394,   395,   396,    74,    75,    76,    77,    38,
      39,    40,    41,    82,     6,    44,    85,   408,   409,   411,
     412,   413,   414,   415,   416,   141,   142,    58,   420,   421,
     422,   423,   424,     6,     7,   427,     5,    56,   430,   431,
     151,   157,   434,   435,   436,   437,   438,   439,   158,  1256,
     442,  1258,    53,  1260,    53,    56,   737,    58,   450,   158,
     406,   407,   743,   455,   456,    71,   159,    56,   414,    38,
      39,    40,    41,    53,    80,    44,    56,   151,    58,   153,
     972,    87,    88,   764,   476,    91,    92,   479,   151,   478,
     153,    56,   121,   122,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   148,   149,
       3,     4,   150,   153,   152,   155,     9,    10,    11,  1230,
     160,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   534,   151,   540,   153,  1353,   141,   142,   541,
     539,    53,   121,   122,    71,    53,    56,   141,   142,   164,
     141,   142,     4,    80,   169,     4,   141,   142,   173,     4,
      87,    88,    54,   157,    91,    92,   157,   151,   570,   153,
     572,   573,   157,   141,   142,   151,   578,   579,   151,   151,
     896,   897,  1399,     6,  1401,   151,  1403,   153,    50,   157,
     592,    53,  1409,   151,    56,   597,   602,   603,   604,   605,
     602,   603,   604,   605,   141,   142,     6,   151,   610,   153,
     141,   142,   614,   615,   143,   144,   145,   120,   620,   153,
     157,   150,   125,   126,   127,  1442,   157,  1444,   151,  1446,
     153,   633,   159,   635,    50,     4,     4,    53,   141,   142,
      56,   158,    58,   146,   151,   647,   141,   142,   151,   651,
     652,   653,   654,   156,   151,   147,   658,   613,     8,   141,
     142,   151,   157,   665,   620,   667,   668,   141,   142,     7,
     626,   141,   142,   151,   151,   157,   153,     6,   677,   141,
     142,   141,   142,   157,   176,  1085,  1086,   157,   151,   151,
     182,   183,   184,    71,   151,   151,   158,   157,   603,   604,
     605,   193,    80,     4,   196,   141,   142,     6,     6,    87,
      88,   713,   714,    91,    92,   330,   141,   142,   151,     5,
     153,   157,     5,   215,   216,   727,   728,   729,   730,   731,
     732,   733,   157,   151,   736,   153,   148,   149,   151,   741,
     153,   153,   151,   155,    71,   747,   158,   151,   160,   153,
     151,   158,   153,    80,  1045,   757,   758,   759,   760,   761,
      87,    88,   151,   151,    91,    92,   141,   142,   143,   144,
     145,    50,   264,   265,    53,   150,     4,    56,   151,    58,
     153,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   151,    71,   153,   151,
     150,   153,  1304,     6,   158,  1307,    80,    71,  1310,   159,
     157,   151,   159,    87,    88,   771,    80,    91,    92,   434,
     435,   436,    71,    87,    88,   151,   151,    91,    92,   151,
     151,    80,   159,   151,   157,   450,   159,   151,    87,    88,
     151,   843,    91,    92,   157,   157,   159,   159,   847,   158,
     157,  1251,   159,   855,   158,     6,    71,   153,   153,   155,
     816,   817,   818,   151,   157,    80,   159,   157,   157,   159,
     159,    71,    87,    88,   876,   877,    91,    92,   151,   157,
      80,   159,   158,  1385,    71,   159,     6,    87,    88,   158,
     158,    91,    92,    80,   157,   159,   159,    56,   897,    58,
      87,    88,   164,   905,    91,    92,   157,   169,   159,     6,
     159,   173,   157,   157,   159,   159,   918,   919,  1420,     5,
     157,  1423,   159,   157,  1426,   159,   157,  1429,   159,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   157,   159,   159,   157,   150,   159,   153,
       5,   953,   954,   955,  1456,   570,  1458,   572,  1460,   159,
       5,   963,   964,   157,   157,   159,   159,     6,   157,   971,
     159,   157,   159,   159,   236,   237,   157,   979,   159,   153,
     153,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   610,   998,   999,  1000,   150,
       4,   157,     6,   159,   157,   155,   159,  1009,  1007,   157,
     108,   159,  1014,   158,   157,   971,   159,   157,   157,   159,
     159,     6,   157,  1029,   159,   157,     6,   159,  1030,   157,
       6,   159,   647,   157,   153,   159,   651,   652,   653,   654,
     157,     4,   159,   658,   158,   537,  1048,     6,   157,  1051,
     159,   157,   157,   159,   159,  1057,  1058,   150,     7,  1265,
    1062,   157,   157,   159,   159,   155,   158,  1069,   330,   157,
     157,   159,   159,   153,   157,  1081,   159,  1079,   159,  1081,
       6,   151,     7,     7,  1085,  1086,     7,   151,   151,   151,
       7,  1093,   152,     6,   105,     7,  1052,     7,     4,     6,
       8,  1103,   158,   157,   366,  1107,   598,   158,  1110,   158,
     158,   158,   152,   157,   152,  1121,   152,   609,   152,  1121,
     157,   736,     6,  1414,     4,  1127,  1128,   154,     6,     6,
       4,  1087,     7,  1089,     7,  1091,   108,     7,     7,   108,
       7,     7,   757,   758,   759,   760,  1148,  1103,  1354,     7,
    1106,  1107,   108,     7,     4,     6,   155,   159,  1449,   159,
    1451,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   434,   435,   436,     6,   150,  1179,     7,   154,
    1471,     7,   674,     7,   155,   158,     6,   151,   450,   151,
     158,     6,     4,     6,   456,  1197,   154,  1199,     6,     6,
       6,   153,     7,     6,   138,     7,     7,  1209,    56,  1211,
       7,    58,  1214,     7,     7,     7,     7,  1219,     6,   152,
       7,   152,  1224,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   152,     7,
       7,     7,   150,     6,     4,     4,  1248,   158,     6,   151,
    1251,   159,     7,  1255,     6,  1257,     7,  1259,     7,     7,
     158,     6,     6,     6,     6,     6,    56,  1269,     4,     4,
       4,  1273,   159,     6,     4,     6,   158,   158,     7,   151,
    1282,  1283,     6,   775,   776,     6,   778,  1289,   780,   781,
     152,   152,   784,   785,  1296,   155,     6,     6,  1300,  1255,
      64,  1257,   158,  1259,     6,   158,     6,     6,   570,   158,
     572,  1267,     6,     5,  1270,     4,   578,   579,     6,   158,
       7,     7,     7,     7,  1326,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,  1341,
       7,   158,  1344,   150,   153,  1347,     6,     6,   610,  1351,
       6,     6,     6,  1355,   158,  1357,   154,   104,   158,   158,
    1362,   157,     6,  1365,   979,   857,   858,   859,     6,   155,
       4,     6,   157,     6,     6,   867,     6,     6,     6,     6,
       6,     6,     5,   108,     6,   647,     6,     6,     6,   651,
     652,   653,   654,     6,     6,  1397,   658,     6,     6,     6,
       6,  1357,     6,     4,   158,     7,     6,     6,     6,  1411,
       6,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     5,   158,   155,     6,   150,
      54,     6,   924,     6,  1440,     6,  1438,     6,   930,     6,
     158,     6,   159,   159,   936,   937,   938,   158,     7,     6,
     942,   158,   158,   158,   103,   947,   948,   949,     6,     6,
       6,  1467,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   963,     6,     6,   736,   150,   159,     6,     6,     6,
     158,   973,     6,     6,     6,   977,   158,     6,   159,   106,
       6,     6,    71,     3,     4,   757,   758,   759,   760,     9,
      10,    11,     4,     6,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     6,   158,     6,     6,
       6,     6,     6,     6,     6,     6,  1028,     6,   159,     6,
      50,     6,   158,    53,   158,     6,    56,   158,    58,     6,
       6,     6,     6,   158,     6,   158,     6,     6,    68,     6,
       6,   158,     6,   158,    74,    75,    76,    77,    78,   158,
     158,     6,    82,     6,     6,    85,  1326,   916,   923,     3,
    1072,  1073,  1074,  1075,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     3,  1214,
      -1,  1033,   150,    -1,   388,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,   125,   126,   127,     6,    -1,
      -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,    -1,    -1,
    1122,   141,   142,  1248,    -1,    -1,   146,  1129,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,
      -1,     3,     4,    -1,  1269,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    50,    -1,
      -1,    53,  1194,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,   979,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      82,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
    1355,    -1,  1357,    -1,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,     6,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,  1264,   125,   126,   127,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,   141,
     142,    -1,   150,    -1,   146,    -1,  1411,    -1,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1312,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,  1103,     3,     4,     5,  1107,     7,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,  1366,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    12,    13,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    -1,  1199,    64,    65,
      -1,    67,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,  1214,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,    -1,    -1,   125,   126,   127,   128,   129,   130,
     131,    -1,     6,    -1,   100,   101,   102,    -1,    -1,    -1,
     141,   142,    -1,    -1,    -1,   146,  1248,   148,   149,    -1,
     151,    -1,   153,    -1,   155,   156,    -1,   158,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,  1269,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1355,    -1,  1357,    -1,    -1,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   120,   150,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1397,   141,   142,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,  1411,
      -1,   156,    -1,   158,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,     5,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    12,
      13,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,     3,     4,    82,    -1,    -1,    85,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,     5,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,   120,    -1,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,   154,    -1,   156,    -1,   158,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     6,
      -1,   120,   121,   122,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,   120,   150,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,    -1,
     156,    -1,   158,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,     3,     4,    -1,   156,    -1,   158,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    50,    -1,    -1,    53,   150,
      -1,    56,    -1,    58,    -1,    -1,    -1,   158,     6,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    82,     6,    -1,
      85,   120,    -1,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
      -1,    -1,   141,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   120,    -1,   156,    -1,   158,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,    -1,    -1,
      -1,   146,     3,     4,     5,    -1,   151,    -1,     9,    10,
      11,   156,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     7,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    44,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     8,    -1,
      -1,    -1,   150,    -1,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     8,    -1,
      -1,    -1,   150,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     8,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,   120,
     121,   122,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,     8,   156,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    71,    -1,    -1,    -1,   150,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,     0,     1,    -1,   150,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    36,
      37,    -1,    -1,   150,    -1,    42,    43,    -1,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,     4,    89,    90,    -1,    -1,    -1,    94,    -1,    12,
      13,    -1,    99,   100,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    36,    37,    -1,   123,   124,    -1,    42,
      43,    -1,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    12,    13,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,   124,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   100,   101,   102,   157,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   154,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   154,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,   154,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
     154,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   154,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   154,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,   154,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
     154,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   154,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   154,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,   154,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
     154,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,   154,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,   154,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150,    -1,   152,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    -1,
      -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,   152,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
     152,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,   150,
      -1,   152,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,   152,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    -1,    -1,    -1,
      -1,   150,    -1,   152,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    -1,    -1,
      -1,    -1,   150
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   162,   163,     6,     0,     4,    12,    13,    36,
      37,    42,    43,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    94,    99,   100,   101,   102,   105,
     107,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   123,   124,   164,   166,   167,   185,   195,   200,
     203,   204,   205,   206,   207,   208,   209,   229,   230,   231,
     232,   233,   234,     3,     4,     5,     7,     9,    10,    11,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    38,    39,    40,    41,    44,   114,   120,   121,   122,
     125,   126,   127,   128,   129,   130,   131,   141,   142,   146,
     148,   149,   151,   153,   155,   156,   158,   183,   184,   235,
     236,   248,    13,    56,   151,   151,     6,   158,     6,     6,
       6,     6,   153,   151,   158,   151,   151,     4,   151,   158,
     151,   151,     4,   158,   151,   151,    60,    56,    56,     6,
      56,    56,    53,    56,    58,    58,    50,    53,    56,    58,
      53,    56,    58,    53,    56,   151,    53,   158,   141,   142,
     151,   158,   237,   238,   237,   158,    50,    53,    56,   158,
     237,     4,    50,    54,    64,    56,    56,    53,     4,   114,
     158,     4,     6,    50,    53,    56,     4,     4,     4,     5,
      35,    50,    53,    56,    58,    68,   142,   158,   200,   209,
     235,   240,   241,   242,     4,   151,   151,   151,     4,   158,
     244,     4,   151,   151,     6,     6,   153,     4,     4,     5,
     158,     5,   158,     6,   151,   158,     4,   153,   155,   160,
     184,   158,     5,   248,   151,   153,   151,   153,   151,   153,
     151,   153,   151,   153,   151,   153,   151,   153,   151,   153,
     151,   153,   151,   153,   151,   153,   151,   153,   151,   153,
     151,   153,   151,   153,   151,   153,   151,   153,   151,   153,
     151,   153,   151,   153,   151,   153,   151,   151,   151,   151,
       7,   151,   151,   151,     4,   235,   235,   235,   235,   154,
     158,   235,     4,   105,   106,     4,     4,   200,   201,   202,
     240,     6,     6,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   150,     6,     6,
     235,     5,     5,   235,   187,   235,   142,   235,   242,   243,
     235,   235,   151,   235,   243,   235,   235,   151,   243,   235,
     235,   240,   151,   158,   151,   151,   241,   241,   241,   151,
     196,   197,   198,   199,   151,   151,   151,   240,   235,     4,
     240,   237,   237,   237,   235,   235,   141,   142,   158,   158,
     237,   158,   158,   158,   141,   142,   151,   202,   237,   158,
     151,   158,   151,   151,   151,   241,   240,   151,     4,     6,
     153,   153,   202,     6,   158,   158,   158,   153,   153,   153,
     153,     5,   158,     5,     5,     5,    50,    53,    56,    58,
     158,   235,   242,   159,   243,     8,   143,     6,     6,   235,
     235,   235,   155,   235,   158,   108,   235,   235,   235,     6,
       6,   202,     6,   202,   240,   240,   153,   235,     4,   158,
     168,     6,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,     4,   247,   248,   247,   247,   247,
     235,   247,   247,   247,   153,   152,     7,   183,   243,   154,
       7,   183,   184,   155,     7,   153,   159,    50,    53,    56,
      58,   195,     6,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,     6,   152,
     157,   152,   157,   157,   154,   157,   186,   152,   143,   157,
     159,   152,   152,   235,   152,   159,   152,   152,   235,   159,
     152,   152,     7,   235,   235,   235,   235,     7,     7,   227,
     227,   235,   151,   151,   151,   151,   235,   235,   235,     7,
     158,   152,     6,   157,   157,   157,   237,   237,   201,   201,
     157,   235,   235,   235,   235,   213,   157,   202,   235,   235,
     235,   235,   235,     7,   228,     7,   235,     6,   235,   235,
     159,   243,   243,   243,   235,   235,   154,   158,   235,     4,
     235,   158,   158,   158,   158,   243,   159,   235,   158,   235,
     242,   152,   152,   152,   105,   157,   202,   158,     8,   152,
     154,   159,   159,   152,   157,   159,   235,   154,   184,   235,
       4,    95,    96,    97,    98,   159,   171,   175,   178,   180,
     181,   152,   154,   152,   154,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   152,   154,   152,
     154,   152,   154,   157,   157,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   157,   157,   157,
     157,   157,   157,   153,   155,   152,   157,   157,   152,   152,
       6,   157,   152,   157,   240,   159,   155,   183,   184,   248,
     235,     6,     4,     4,   158,   245,   154,   158,   158,   158,
     158,     8,     6,   138,   165,   243,     6,   243,   235,     6,
       4,     7,   235,   242,   108,     7,     7,   152,     7,   108,
       7,     7,   152,   108,     7,     7,   235,   152,   159,   152,
     152,   235,   240,     4,   226,     6,   152,   192,   235,   248,
     192,   192,   192,   152,   152,   152,   240,   243,   155,   237,
     235,   235,   159,   159,   235,   237,   157,   157,   157,    71,
      80,    87,    88,    91,    92,   223,   224,   237,   159,   210,
     152,   159,   152,   152,   152,   235,     6,   235,   152,   154,
     154,   159,   159,   159,   154,   154,   243,   154,   154,   159,
     243,   243,   243,   243,   159,     8,   243,     7,     7,     7,
     155,   235,   159,   235,   235,     7,   155,   158,   240,     6,
     154,   155,   184,   247,   159,   172,   151,   151,   158,   182,
       6,   235,   235,   235,   235,   235,   235,   235,   235,   235,
       4,   243,   247,   235,   247,     6,   154,     4,   105,   106,
     235,     6,     6,     6,     7,   153,   244,   246,     6,   243,
     243,   243,   243,   235,   138,   247,   152,   152,   157,     7,
     237,    56,   240,   240,     7,   240,    56,    58,   240,   240,
       7,    58,   240,   240,     6,     7,     7,     7,     7,    71,
     225,     6,     7,   152,   152,   152,   152,     7,     7,     7,
       6,   159,     4,   157,   157,   157,   159,   159,   237,   237,
     237,     4,     6,   158,   151,     6,    93,     6,    93,   159,
     224,   157,   223,     7,     6,     7,     7,     7,     6,   158,
       6,     6,     6,    56,   235,     6,     6,   159,   159,   159,
     159,   159,   235,   159,   240,   240,   240,     4,   157,     8,
       8,   152,     4,     4,   240,   159,     6,     4,     6,   151,
     235,   235,   239,   240,   158,   152,   154,   152,   154,   152,
     154,   152,   154,   154,   152,   152,   152,   152,   183,     7,
     183,   184,   155,     7,     6,   244,   235,   157,   159,   159,
     159,   159,   159,     6,     6,   165,     6,   235,   158,   235,
       6,   158,    64,   194,   194,   240,     6,   158,   158,     6,
       6,   240,   158,     6,     6,     5,   240,   240,   240,     4,
       6,   240,     7,     7,     7,     7,   240,   240,   240,     7,
       6,     7,   235,   235,   235,   158,   158,   157,   159,   157,
     159,   157,   159,   153,   235,   240,   235,     6,     6,   235,
     237,   159,     5,   158,   240,   158,   158,   158,   240,   243,
     158,     6,   154,     6,     6,   104,   235,   235,   235,     6,
       6,     7,   157,     6,   184,   169,   235,   157,   157,   157,
     159,   170,   235,   155,   240,   248,   235,     6,     4,   245,
       6,   154,   244,     6,     6,     6,     6,   247,   157,   235,
     235,   237,     6,     6,     6,   235,   235,     6,   235,     5,
       6,     6,   108,   193,   235,     6,   240,   240,   240,   240,
       6,     4,     6,     6,   235,   235,   248,   159,   152,   157,
     159,   201,   201,   237,     6,   214,   237,     6,   215,   237,
       6,   216,   235,   159,   157,   152,   159,   157,     6,   142,
     237,     6,   239,   237,   237,     6,   159,   235,   240,   157,
     159,     8,   159,   152,   158,   235,   248,   240,   152,   157,
     235,   235,   240,   158,   157,   159,     4,     6,     6,     6,
       7,     6,   155,     6,   235,   188,   159,   159,   159,   159,
       5,    54,     6,     6,     6,     6,     6,   158,   158,     6,
       6,   158,   235,   159,   159,   157,   158,   157,   158,   157,
     158,   154,     6,   240,     7,   158,   235,   157,   159,   157,
     157,     6,   159,   103,   235,   235,   243,     6,     6,   159,
     173,   235,   157,   157,   239,   235,     6,   244,   106,   157,
     190,     6,     6,     6,     6,     6,   158,   239,   243,   201,
     157,   159,   235,   237,   223,   235,   237,   223,   235,   237,
     223,     6,   157,   159,   240,   202,   159,   237,     6,   243,
     237,   235,   159,   159,   159,     6,   158,   235,   235,   159,
       6,   235,   157,   159,   191,   235,   159,   159,   159,   235,
     159,   157,   159,   159,   157,   159,   159,   157,   159,   240,
       6,    71,   159,   211,   158,   157,   159,   157,     6,     6,
     170,   152,   157,     6,   158,   157,     4,   159,     6,     6,
     159,     6,   217,   235,     6,     6,   218,   235,     6,     6,
     219,   235,     6,   159,   235,   223,   202,   243,     6,   237,
     243,   159,   176,   235,   239,   235,     5,   158,   240,   158,
     159,   158,   159,   158,   159,     6,     6,   159,   159,   212,
     159,   157,   159,     6,   158,   152,   159,   159,   189,   235,
     223,     6,   220,   223,     6,   221,   223,     6,   222,   223,
       6,   243,     6,   174,   247,   179,   158,     6,   157,   159,
       7,   159,   158,   159,   158,   159,   158,   159,   159,   157,
     159,   158,   239,   235,   248,     6,   223,     6,   223,     6,
     223,     6,   247,     6,   177,   247,   159,     7,   159,   159,
     159,   157,   159,     6,   248,     6,     6,     6,   247,     6
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
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 217 "Gmsh.y"
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
#line 231 "Gmsh.y"
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
#line 244 "Gmsh.y"
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
#line 257 "Gmsh.y"
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
#line 285 "Gmsh.y"
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
#line 299 "Gmsh.y"
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
#line 310 "Gmsh.y"
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
#line 324 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 338 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 340 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 345 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 347 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 352 "Gmsh.y"
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
#line 456 "Gmsh.y"
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
#line 466 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 475 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 482 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 492 "Gmsh.y"
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
#line 501 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 510 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 517 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 527 "Gmsh.y"
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
#line 535 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 545 "Gmsh.y"
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
#line 564 "Gmsh.y"
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
#line 583 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 589 "Gmsh.y"
    {
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 596 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 597 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 598 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 599 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 600 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 604 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 605 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 614 "Gmsh.y"
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
#line 677 "Gmsh.y"
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
#line 707 "Gmsh.y"
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
#line 740 "Gmsh.y"
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

  case 71:

/* Line 1464 of yacc.c  */
#line 786 "Gmsh.y"
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

  case 72:

/* Line 1464 of yacc.c  */
#line 801 "Gmsh.y"
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

  case 73:

/* Line 1464 of yacc.c  */
#line 817 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 826 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 832 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 841 "Gmsh.y"
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

  case 77:

/* Line 1464 of yacc.c  */
#line 859 "Gmsh.y"
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

  case 78:

/* Line 1464 of yacc.c  */
#line 877 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 886 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 898 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 903 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 911 "Gmsh.y"
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

  case 83:

/* Line 1464 of yacc.c  */
#line 931 "Gmsh.y"
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

  case 84:

/* Line 1464 of yacc.c  */
#line 954 "Gmsh.y"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 965 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 973 "Gmsh.y"
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

  case 87:

/* Line 1464 of yacc.c  */
#line 995 "Gmsh.y"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 1018 "Gmsh.y"
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

  case 89:

/* Line 1464 of yacc.c  */
#line 1044 "Gmsh.y"
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

  case 90:

/* Line 1464 of yacc.c  */
#line 1065 "Gmsh.y"
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

  case 91:

/* Line 1464 of yacc.c  */
#line 1077 "Gmsh.y"
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

  case 95:

/* Line 1464 of yacc.c  */
#line 1095 "Gmsh.y"
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

  case 96:

/* Line 1464 of yacc.c  */
#line 1106 "Gmsh.y"
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

  case 97:

/* Line 1464 of yacc.c  */
#line 1117 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1119 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
    ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1131 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1137 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1149 "Gmsh.y"
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

  case 104:

/* Line 1464 of yacc.c  */
#line 1160 "Gmsh.y"
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

  case 105:

/* Line 1464 of yacc.c  */
#line 1175 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1188 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1192 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1202 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1206 "Gmsh.y"
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

  case 110:

/* Line 1464 of yacc.c  */
#line 1218 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1222 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1232 "Gmsh.y"
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

  case 113:

/* Line 1464 of yacc.c  */
#line 1255 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1259 "Gmsh.y"
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

  case 115:

/* Line 1464 of yacc.c  */
#line 1275 "Gmsh.y"
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

  case 116:

/* Line 1464 of yacc.c  */
#line 1297 "Gmsh.y"
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

  case 117:

/* Line 1464 of yacc.c  */
#line 1315 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1336 "Gmsh.y"
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

  case 119:

/* Line 1464 of yacc.c  */
#line 1354 "Gmsh.y"
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

  case 120:

/* Line 1464 of yacc.c  */
#line 1384 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1414 "Gmsh.y"
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

  case 122:

/* Line 1464 of yacc.c  */
#line 1432 "Gmsh.y"
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

  case 123:

/* Line 1464 of yacc.c  */
#line 1450 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1476 "Gmsh.y"
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

  case 125:

/* Line 1464 of yacc.c  */
#line 1494 "Gmsh.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 1512 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1516 "Gmsh.y"
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

  case 128:

/* Line 1464 of yacc.c  */
#line 1535 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1553 "Gmsh.y"
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

  case 130:

/* Line 1464 of yacc.c  */
#line 1592 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 1598 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1604 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1611 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1636 "Gmsh.y"
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

  case 135:

/* Line 1464 of yacc.c  */
#line 1661 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1678 "Gmsh.y"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1696 "Gmsh.y"
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

  case 138:

/* Line 1464 of yacc.c  */
#line 1726 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1730 "Gmsh.y"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 1750 "Gmsh.y"
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

  case 141:

/* Line 1464 of yacc.c  */
#line 1768 "Gmsh.y"
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

  case 142:

/* Line 1464 of yacc.c  */
#line 1785 "Gmsh.y"
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

  case 143:

/* Line 1464 of yacc.c  */
#line 1801 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1805 "Gmsh.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1827 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1832 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1837 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1842 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1847 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1852 "Gmsh.y"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1875 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1881 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1891 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1892 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1897 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1901 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1905 "Gmsh.y"
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

  case 158:

/* Line 1464 of yacc.c  */
#line 1928 "Gmsh.y"
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

  case 159:

/* Line 1464 of yacc.c  */
#line 1951 "Gmsh.y"
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

  case 160:

/* Line 1464 of yacc.c  */
#line 1974 "Gmsh.y"
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

  case 161:

/* Line 1464 of yacc.c  */
#line 2002 "Gmsh.y"
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

  case 162:

/* Line 1464 of yacc.c  */
#line 2023 "Gmsh.y"
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

  case 163:

/* Line 1464 of yacc.c  */
#line 2047 "Gmsh.y"
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

  case 164:

/* Line 1464 of yacc.c  */
#line 2068 "Gmsh.y"
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

  case 165:

/* Line 1464 of yacc.c  */
#line 2089 "Gmsh.y"
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

  case 166:

/* Line 1464 of yacc.c  */
#line 2109 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2221 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2240 "Gmsh.y"
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

  case 169:

/* Line 1464 of yacc.c  */
#line 2279 "Gmsh.y"
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

  case 170:

/* Line 1464 of yacc.c  */
#line 2387 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2396 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2402 "Gmsh.y"
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

  case 173:

/* Line 1464 of yacc.c  */
#line 2417 "Gmsh.y"
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

  case 174:

/* Line 1464 of yacc.c  */
#line 2445 "Gmsh.y"
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

  case 175:

/* Line 1464 of yacc.c  */
#line 2462 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2476 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 2482 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 2488 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 2497 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 2511 "Gmsh.y"
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

  case 181:

/* Line 1464 of yacc.c  */
#line 2556 "Gmsh.y"
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

  case 182:

/* Line 1464 of yacc.c  */
#line 2573 "Gmsh.y"
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

  case 183:

/* Line 1464 of yacc.c  */
#line 2588 "Gmsh.y"
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

  case 184:

/* Line 1464 of yacc.c  */
#line 2607 "Gmsh.y"
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

  case 185:

/* Line 1464 of yacc.c  */
#line 2619 "Gmsh.y"
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

  case 186:

/* Line 1464 of yacc.c  */
#line 2643 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2647 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2652 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2659 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2665 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2670 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 2676 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 2680 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2684 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2694 "Gmsh.y"
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

  case 196:

/* Line 1464 of yacc.c  */
#line 2711 "Gmsh.y"
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

  case 197:

/* Line 1464 of yacc.c  */
#line 2728 "Gmsh.y"
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

  case 198:

/* Line 1464 of yacc.c  */
#line 2749 "Gmsh.y"
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

  case 199:

/* Line 1464 of yacc.c  */
#line 2770 "Gmsh.y"
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

  case 200:

/* Line 1464 of yacc.c  */
#line 2805 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2813 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2819 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2826 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2830 "Gmsh.y"
    {
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2839 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2847 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2855 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2863 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2868 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2876 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2881 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2889 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2894 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2902 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2907 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2915 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2922 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2929 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2936 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2943 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2950 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2957 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2964 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2978 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2983 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2990 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2995 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3002 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3007 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3014 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3019 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3026 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3031 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3038 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3043 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3050 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3055 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3062 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3067 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3074 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3079 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3090 "Gmsh.y"
    {
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3093 "Gmsh.y"
    {
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3099 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3108 "Gmsh.y"
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

  case 247:

/* Line 1464 of yacc.c  */
#line 3128 "Gmsh.y"
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

  case 248:

/* Line 1464 of yacc.c  */
#line 3151 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3155 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3159 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3167 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3171 "Gmsh.y"
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

  case 254:

/* Line 1464 of yacc.c  */
#line 3190 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3202 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 3206 "Gmsh.y"
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

  case 257:

/* Line 1464 of yacc.c  */
#line 3221 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3225 "Gmsh.y"
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

  case 259:

/* Line 1464 of yacc.c  */
#line 3237 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3241 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3246 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3250 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3257 "Gmsh.y"
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

  case 264:

/* Line 1464 of yacc.c  */
#line 3313 "Gmsh.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 3383 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3388 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3455 "Gmsh.y"
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

  case 268:

/* Line 1464 of yacc.c  */
#line 3491 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3500 "Gmsh.y"
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

  case 270:

/* Line 1464 of yacc.c  */
#line 3543 "Gmsh.y"
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

  case 271:

/* Line 1464 of yacc.c  */
#line 3568 "Gmsh.y"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 3596 "Gmsh.y"
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

  case 273:

/* Line 1464 of yacc.c  */
#line 3639 "Gmsh.y"
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

  case 274:

/* Line 1464 of yacc.c  */
#line 3662 "Gmsh.y"
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

  case 275:

/* Line 1464 of yacc.c  */
#line 3685 "Gmsh.y"
    {
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3688 "Gmsh.y"
    {
    ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3697 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3701 "Gmsh.y"
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

  case 279:

/* Line 1464 of yacc.c  */
#line 3711 "Gmsh.y"
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

  case 280:

/* Line 1464 of yacc.c  */
#line 3745 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3746 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3751 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3756 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (5)].l));
    ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3767 "Gmsh.y"
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
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3784 "Gmsh.y"
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

  case 286:

/* Line 1464 of yacc.c  */
#line 3811 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3812 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3813 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3814 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3815 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3816 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3817 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3818 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3820 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3826 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3827 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3828 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3829 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3830 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3831 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3832 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3833 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3834 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3835 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3836 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3837 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3838 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3839 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3840 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3841 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3842 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3843 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3844 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3845 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3846 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3847 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3848 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3849 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3850 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3851 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3852 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3853 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3854 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3855 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3856 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3857 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3860 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3861 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3862 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3863 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3864 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3865 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3866 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3867 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3868 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3869 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3870 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3871 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3872 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3873 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3874 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3875 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3876 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3877 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3878 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3879 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3888 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3889 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3890 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3891 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3892 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3893 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3894 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3899 "Gmsh.y"
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

  case 356:

/* Line 1464 of yacc.c  */
#line 3919 "Gmsh.y"
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

  case 357:

/* Line 1464 of yacc.c  */
#line 3938 "Gmsh.y"
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

  case 358:

/* Line 1464 of yacc.c  */
#line 3956 "Gmsh.y"
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

  case 359:

/* Line 1464 of yacc.c  */
#line 3968 "Gmsh.y"
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

  case 360:

/* Line 1464 of yacc.c  */
#line 3985 "Gmsh.y"
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

  case 361:

/* Line 1464 of yacc.c  */
#line 4006 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4011 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4016 "Gmsh.y"
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

  case 364:

/* Line 1464 of yacc.c  */
#line 4026 "Gmsh.y"
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

  case 365:

/* Line 1464 of yacc.c  */
#line 4036 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4044 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4052 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4056 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4060 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4067 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4071 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4075 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4079 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4086 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4091 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4103 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4107 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4112 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4116 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4124 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4135 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4139 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4151 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4159 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4167 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4174 "Gmsh.y"
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

  case 389:

/* Line 1464 of yacc.c  */
#line 4185 "Gmsh.y"
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

  case 390:

/* Line 1464 of yacc.c  */
#line 4205 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4209 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4213 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4217 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4221 "Gmsh.y"
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
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4239 "Gmsh.y"
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
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4257 "Gmsh.y"
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
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4275 "Gmsh.y"
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
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4293 "Gmsh.y"
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

  case 399:

/* Line 1464 of yacc.c  */
#line 4303 "Gmsh.y"
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

  case 400:

/* Line 1464 of yacc.c  */
#line 4313 "Gmsh.y"
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

  case 401:

/* Line 1464 of yacc.c  */
#line 4325 "Gmsh.y"
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

  case 402:

/* Line 1464 of yacc.c  */
#line 4337 "Gmsh.y"
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

  case 403:

/* Line 1464 of yacc.c  */
#line 4358 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4363 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4367 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4371 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4383 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4387 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4399 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4406 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4416 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 4420 "Gmsh.y"
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

  case 413:

/* Line 1464 of yacc.c  */
#line 4435 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 4440 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4447 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 4451 "Gmsh.y"
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

  case 417:

/* Line 1464 of yacc.c  */
#line 4464 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 4472 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4483 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4487 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4495 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4503 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4511 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4519 "Gmsh.y"
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

  case 425:

/* Line 1464 of yacc.c  */
#line 4533 "Gmsh.y"
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

  case 426:

/* Line 1464 of yacc.c  */
#line 4547 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4551 "Gmsh.y"
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



/* Line 1464 of yacc.c  */
#line 10279 "Gmsh.tab.cpp"
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
#line 4571 "Gmsh.y"


int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  int numFormats = 0;
  for(int i = 0; i < strlen(format); i++)
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

