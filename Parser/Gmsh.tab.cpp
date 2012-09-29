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
     tField = 368,
     tReturn = 369,
     tCall = 370,
     tFunction = 371,
     tShow = 372,
     tHide = 373,
     tGetValue = 374,
     tGetEnv = 375,
     tGetString = 376,
     tHomology = 377,
     tCohomology = 378,
     tGMSH_MAJOR_VERSION = 379,
     tGMSH_MINOR_VERSION = 380,
     tGMSH_PATCH_VERSION = 381,
     tAFFECTDIVIDE = 382,
     tAFFECTTIMES = 383,
     tAFFECTMINUS = 384,
     tAFFECTPLUS = 385,
     tOR = 386,
     tAND = 387,
     tNOTEQUAL = 388,
     tEQUAL = 389,
     tGREATEROREQUAL = 390,
     tLESSOREQUAL = 391,
     UNARYPREC = 392,
     tMINUSMINUS = 393,
     tPLUSPLUS = 394
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
#line 359 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 371 "Gmsh.tab.cpp"

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
#define YYLAST   7573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  160
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  426
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1478

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   394

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,     2,   155,     2,   144,     2,     2,
     150,   151,   142,   140,   156,   141,   154,   143,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     136,     2,   137,   131,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   152,     2,   153,   149,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   157,     2,   158,   159,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   132,   133,   134,   135,
     138,   139,   146,   147,   148
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
    1109,  1112,  1115,  1118,  1121,  1128,  1137,  1146,  1157,  1159,
    1162,  1164,  1168,  1173,  1175,  1181,  1193,  1207,  1208,  1216,
    1217,  1231,  1232,  1248,  1249,  1256,  1265,  1274,  1283,  1296,
    1309,  1322,  1337,  1352,  1367,  1368,  1381,  1382,  1395,  1396,
    1409,  1410,  1427,  1428,  1445,  1446,  1463,  1464,  1483,  1484,
    1503,  1504,  1523,  1525,  1528,  1534,  1542,  1552,  1555,  1558,
    1562,  1565,  1569,  1579,  1586,  1587,  1591,  1592,  1594,  1595,
    1598,  1599,  1602,  1610,  1617,  1626,  1632,  1636,  1644,  1650,
    1657,  1664,  1677,  1688,  1699,  1710,  1721,  1724,  1728,  1735,
    1737,  1739,  1742,  1748,  1756,  1767,  1769,  1773,  1776,  1779,
    1782,  1786,  1790,  1794,  1798,  1802,  1806,  1810,  1814,  1818,
    1822,  1826,  1830,  1834,  1838,  1844,  1849,  1854,  1859,  1864,
    1869,  1874,  1879,  1884,  1889,  1894,  1901,  1906,  1911,  1916,
    1921,  1926,  1931,  1938,  1945,  1952,  1957,  1962,  1967,  1972,
    1977,  1982,  1987,  1992,  1997,  2002,  2007,  2014,  2019,  2024,
    2029,  2034,  2039,  2044,  2051,  2058,  2065,  2070,  2072,  2074,
    2076,  2078,  2080,  2082,  2084,  2086,  2092,  2097,  2102,  2105,
    2111,  2115,  2122,  2127,  2135,  2142,  2144,  2147,  2150,  2154,
    2158,  2170,  2180,  2188,  2196,  2198,  2202,  2204,  2206,  2209,
    2213,  2218,  2224,  2226,  2228,  2231,  2235,  2239,  2245,  2250,
    2253,  2256,  2259,  2262,  2268,  2274,  2280,  2286,  2288,  2290,
    2294,  2299,  2306,  2308,  2310,  2314,  2318,  2328,  2336,  2338,
    2344,  2348,  2355,  2357,  2361,  2363,  2365,  2369,  2376,  2378,
    2380,  2385,  2392,  2399,  2404,  2409,  2414
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     161,     0,    -1,   162,    -1,     1,     6,    -1,    -1,   162,
     163,    -1,   166,    -1,   165,    -1,   184,    -1,   194,    -1,
     199,    -1,   203,    -1,   204,    -1,   205,    -1,   208,    -1,
     228,    -1,   229,    -1,   230,    -1,   231,    -1,   207,    -1,
     206,    -1,   202,    -1,   233,    -1,   137,    -1,   137,   137,
      -1,    36,   150,     5,   151,     6,    -1,    37,   150,     5,
     151,     6,    -1,    36,   150,     5,   151,   164,   246,     6,
      -1,    36,   150,     5,   156,   242,   151,     6,    -1,    37,
     150,     5,   156,   242,   151,     6,    -1,    36,   150,     5,
     156,   242,   151,   164,   246,     6,    -1,     4,     5,   157,
     167,   158,     6,    -1,    89,     4,   152,   234,   153,     6,
      -1,    90,     4,   152,   234,   153,     6,    -1,    -1,   167,
     170,    -1,   167,   174,    -1,   167,   177,    -1,   167,   179,
      -1,   167,   180,    -1,   234,    -1,   168,   156,   234,    -1,
     234,    -1,   169,   156,   234,    -1,    -1,    -1,     4,   171,
     150,   168,   151,   172,   157,   169,   158,     6,    -1,   246,
      -1,   173,   156,   246,    -1,    -1,    95,   150,   234,   156,
     234,   156,   234,   151,   175,   157,   173,   158,     6,    -1,
     246,    -1,   176,   156,   246,    -1,    -1,    96,   150,   234,
     156,   234,   156,   234,   156,   234,   151,   178,   157,   176,
     158,     6,    -1,    97,   157,   238,   158,   157,   238,   158,
       6,    -1,    97,   157,   238,   158,   157,   238,   158,   157,
     238,   158,   157,   238,   158,     6,    -1,    -1,    98,   181,
     157,   169,   158,     6,    -1,     7,    -1,   130,    -1,   129,
      -1,   128,    -1,   127,    -1,   148,    -1,   147,    -1,    49,
     152,   186,   153,     6,    -1,     4,   182,   239,     6,    -1,
       4,   152,   153,   182,   239,     6,    -1,     4,   152,   234,
     153,   182,   234,     6,    -1,     4,   152,   157,   242,   158,
     153,   182,   239,     6,    -1,     4,   183,     6,    -1,     4,
     152,   234,   153,   183,     6,    -1,     4,     7,   247,     6,
      -1,     4,   154,     4,     7,   247,     6,    -1,     4,   152,
     234,   153,   154,     4,     7,   247,     6,    -1,     4,   154,
       4,   182,   234,     6,    -1,     4,   152,   234,   153,   154,
       4,   182,   234,     6,    -1,     4,   154,     4,   183,     6,
      -1,     4,   152,   234,   153,   154,     4,   183,     6,    -1,
       4,   154,   105,   154,     4,     7,   243,     6,    -1,     4,
     152,   234,   153,   154,   105,   154,     4,     7,   243,     6,
      -1,     4,   154,   106,     7,   244,     6,    -1,     4,   152,
     234,   153,   154,   106,     7,   244,     6,    -1,     4,   113,
       7,   234,     6,    -1,   113,   152,   234,   153,     7,     4,
       6,    -1,   113,   152,   234,   153,   154,     4,     7,   234,
       6,    -1,   113,   152,   234,   153,   154,     4,     7,   247,
       6,    -1,   113,   152,   234,   153,   154,     4,     7,   157,
     242,   158,     6,    -1,   113,   152,   234,   153,   154,     4,
       6,    -1,    72,   150,     4,   151,   154,     4,     7,   234,
       6,    -1,    72,   150,     4,   151,   154,     4,     7,   247,
       6,    -1,    -1,   156,    -1,    -1,   186,   185,     4,    -1,
     186,   185,     4,     7,   234,    -1,    -1,   186,   185,     4,
       7,   157,   234,   187,   189,   158,    -1,   234,     7,   247,
      -1,   188,   156,   234,     7,   247,    -1,    -1,   189,   190,
      -1,   156,     4,   239,    -1,   156,     4,   157,   188,   158,
      -1,   156,     4,     5,    -1,   234,    -1,   247,    -1,    -1,
     108,    54,   157,   234,   158,    -1,    -1,    64,   236,    -1,
      50,   150,   234,   151,     7,   236,     6,    -1,    -1,    68,
      50,   195,   150,   191,   151,     7,   239,     6,    -1,    59,
      60,   239,     7,   234,     6,    -1,    53,   150,   234,   151,
       7,   239,     6,    -1,    73,    53,   239,     6,    -1,    57,
     150,   234,   151,     7,   239,     6,    -1,    51,   150,   234,
     151,     7,   239,   193,     6,    -1,    52,   150,   234,   151,
       7,   239,   193,     6,    -1,   100,   150,   234,   151,     7,
     239,     6,    -1,   101,   150,   234,   151,     7,   239,     6,
      -1,   102,   150,   234,   151,     7,   239,   104,   239,   103,
     234,     6,    -1,    53,     4,   150,   234,   151,     7,   239,
       6,    -1,    69,    53,   150,   234,   151,     7,   239,     6,
      -1,    -1,    68,    53,   196,   150,   191,   151,     7,   239,
       6,    -1,    64,    56,   150,   234,   151,     7,   239,     6,
      -1,    65,    56,   150,   234,   151,     7,   239,   192,     6,
      -1,    12,    13,     6,    -1,    13,    56,   234,     6,    -1,
      61,    56,   150,   234,   151,     7,     5,     5,     5,     6,
      -1,    54,   150,   234,   151,     7,   239,     6,    -1,    55,
     150,   234,   151,     7,   239,     6,    -1,    56,     4,   150,
     234,   151,     7,   239,     6,    -1,    69,    56,   150,   234,
     151,     7,   239,     6,    -1,    69,    56,   150,   234,   151,
       7,   239,     4,   157,   238,   158,     6,    -1,    -1,    68,
      56,   197,   150,   191,   151,     7,   239,     6,    -1,    67,
      58,   150,   234,   151,     7,   239,     6,    -1,    58,   150,
     234,   151,     7,   239,     6,    -1,    69,    58,   150,   234,
     151,     7,   239,     6,    -1,    -1,    68,    58,   198,   150,
     191,   151,     7,   239,     6,    -1,    75,   236,   157,   200,
     158,    -1,    74,   157,   236,   156,   236,   156,   234,   158,
     157,   200,   158,    -1,    76,   236,   157,   200,   158,    -1,
      77,   157,   236,   156,   234,   158,   157,   200,   158,    -1,
      77,   157,   236,   156,   236,   158,   157,   200,   158,    -1,
       4,   157,   200,   158,    -1,    85,    53,   157,   242,   158,
      56,   157,   234,   158,    -1,    82,    53,   150,   234,   151,
     157,   242,   158,     6,    -1,   201,    -1,   199,    -1,    -1,
     201,   194,    -1,   201,    50,   157,   242,   158,     6,    -1,
     201,    53,   157,   242,   158,     6,    -1,   201,    56,   157,
     242,   158,     6,    -1,   201,    58,   157,   242,   158,     6,
      -1,    79,    64,   150,   234,   151,     7,   239,     6,    -1,
      79,    50,   150,   234,   151,     7,   157,   238,   158,     6,
      -1,    79,    64,   150,   234,   151,     7,   157,   236,   156,
     236,   156,   242,   158,     6,    -1,    79,    64,   150,   234,
     151,     7,   157,   236,   156,   236,   156,   236,   156,   242,
     158,     6,    -1,    79,    54,   150,   234,   151,     7,   157,
     236,   156,   242,   158,     6,    -1,    79,     4,   150,   234,
     151,     7,   239,     6,    -1,    79,     4,   150,   234,   151,
       7,     5,     6,    -1,    79,     4,   157,   234,   158,     6,
      -1,    79,     4,   150,   234,   151,     7,   157,   236,   156,
     236,   156,   242,   158,     6,    -1,    83,   157,   201,   158,
      -1,    83,   113,   152,   234,   153,     6,    -1,    83,     4,
     152,   234,   153,     6,    -1,    83,     4,     6,    -1,    83,
       4,     4,     6,    -1,   105,   243,   157,   201,   158,    -1,
     117,     5,     6,    -1,   118,     5,     6,    -1,   117,   157,
     201,   158,    -1,   118,   157,   201,   158,    -1,     4,   247,
       6,    -1,     4,     4,   152,   234,   153,   246,     6,    -1,
       4,     4,     4,   152,   234,   153,     6,    -1,     4,   234,
       6,    -1,    72,   150,     4,   151,   154,     4,     6,    -1,
      99,     4,     6,    -1,   112,     6,    -1,    45,     6,    -1,
      42,     6,    -1,    42,   157,   234,   156,   234,   156,   234,
     156,   234,   156,   234,   156,   234,   158,     6,    -1,    43,
       6,    -1,    46,     6,    -1,    47,     6,    -1,    63,     6,
      -1,   107,   150,   234,     8,   234,   151,    -1,   107,   150,
     234,     8,   234,     8,   234,   151,    -1,   107,     4,   108,
     157,   234,     8,   234,   158,    -1,   107,     4,   108,   157,
     234,     8,   234,     8,   234,   158,    -1,   109,    -1,   116,
       4,    -1,   114,    -1,   115,     4,     6,    -1,   110,   150,
     234,   151,    -1,   111,    -1,    78,   236,   157,   201,   158,
      -1,    78,   157,   236,   156,   236,   156,   234,   158,   157,
     201,   158,    -1,    78,   157,   236,   156,   236,   156,   236,
     156,   234,   158,   157,   201,   158,    -1,    -1,    78,   236,
     157,   201,   209,   222,   158,    -1,    -1,    78,   157,   236,
     156,   236,   156,   234,   158,   157,   201,   210,   222,   158,
      -1,    -1,    78,   157,   236,   156,   236,   156,   236,   156,
     234,   158,   157,   201,   211,   222,   158,    -1,    -1,    78,
     157,   201,   212,   222,   158,    -1,    78,    50,   157,   234,
     156,   236,   158,     6,    -1,    78,    53,   157,   234,   156,
     236,   158,     6,    -1,    78,    56,   157,   234,   156,   236,
     158,     6,    -1,    78,    50,   157,   234,   156,   236,   156,
     236,   156,   234,   158,     6,    -1,    78,    53,   157,   234,
     156,   236,   156,   236,   156,   234,   158,     6,    -1,    78,
      56,   157,   234,   156,   236,   156,   236,   156,   234,   158,
       6,    -1,    78,    50,   157,   234,   156,   236,   156,   236,
     156,   236,   156,   234,   158,     6,    -1,    78,    53,   157,
     234,   156,   236,   156,   236,   156,   236,   156,   234,   158,
       6,    -1,    78,    56,   157,   234,   156,   236,   156,   236,
     156,   236,   156,   234,   158,     6,    -1,    -1,    78,    50,
     157,   234,   156,   236,   158,   213,   157,   222,   158,     6,
      -1,    -1,    78,    53,   157,   234,   156,   236,   158,   214,
     157,   222,   158,     6,    -1,    -1,    78,    56,   157,   234,
     156,   236,   158,   215,   157,   222,   158,     6,    -1,    -1,
      78,    50,   157,   234,   156,   236,   156,   236,   156,   234,
     158,   216,   157,   222,   158,     6,    -1,    -1,    78,    53,
     157,   234,   156,   236,   156,   236,   156,   234,   158,   217,
     157,   222,   158,     6,    -1,    -1,    78,    56,   157,   234,
     156,   236,   156,   236,   156,   234,   158,   218,   157,   222,
     158,     6,    -1,    -1,    78,    50,   157,   234,   156,   236,
     156,   236,   156,   236,   156,   234,   158,   219,   157,   222,
     158,     6,    -1,    -1,    78,    53,   157,   234,   156,   236,
     156,   236,   156,   236,   156,   234,   158,   220,   157,   222,
     158,     6,    -1,    -1,    78,    56,   157,   234,   156,   236,
     156,   236,   156,   236,   156,   234,   158,   221,   157,   222,
     158,     6,    -1,   223,    -1,   222,   223,    -1,    87,   157,
     234,   158,     6,    -1,    87,   157,   239,   156,   239,   158,
       6,    -1,    87,   157,   239,   156,   239,   156,   239,   158,
       6,    -1,    80,     6,    -1,    91,     6,    -1,    91,    93,
       6,    -1,    92,     6,    -1,    92,    93,     6,    -1,    88,
     150,   234,   151,     7,   239,    71,   234,     6,    -1,    71,
       4,   152,   234,   153,     6,    -1,    -1,    71,     4,   234,
      -1,    -1,     4,    -1,    -1,     7,   239,    -1,    -1,     7,
     234,    -1,    66,    53,   240,     7,   234,   224,     6,    -1,
      66,    56,   240,   226,   225,     6,    -1,    62,    56,   157,
     234,   158,     7,   239,     6,    -1,    66,    58,   240,   226,
       6,    -1,    94,   240,     6,    -1,    86,    56,   157,   242,
     158,   234,     6,    -1,    80,    56,   240,   227,     6,    -1,
      81,    56,   239,     7,   234,     6,    -1,    70,    53,   239,
       7,   239,     6,    -1,    70,    56,   234,   157,   242,   158,
       7,   234,   157,   242,   158,     6,    -1,    50,   157,   242,
     158,   108,    56,   157,   234,   158,     6,    -1,    53,   157,
     242,   158,   108,    56,   157,   234,   158,     6,    -1,    53,
     157,   242,   158,   108,    58,   157,   234,   158,     6,    -1,
      56,   157,   242,   158,   108,    58,   157,   234,   158,     6,
      -1,    84,     6,    -1,    84,     4,     6,    -1,    84,    50,
     157,   242,   158,     6,    -1,   122,    -1,   123,    -1,   232,
       6,    -1,   232,   157,   239,   158,     6,    -1,   232,   157,
     239,   156,   239,   158,     6,    -1,   232,   150,   239,   151,
     157,   239,   156,   239,   158,     6,    -1,   235,    -1,   150,
     234,   151,    -1,   141,   234,    -1,   140,   234,    -1,   145,
     234,    -1,   234,   141,   234,    -1,   234,   140,   234,    -1,
     234,   142,   234,    -1,   234,   143,   234,    -1,   234,   144,
     234,    -1,   234,   149,   234,    -1,   234,   136,   234,    -1,
     234,   137,   234,    -1,   234,   139,   234,    -1,   234,   138,
     234,    -1,   234,   135,   234,    -1,   234,   134,   234,    -1,
     234,   133,   234,    -1,   234,   132,   234,    -1,   234,   131,
     234,     8,   234,    -1,    14,   150,   234,   151,    -1,    15,
     150,   234,   151,    -1,    16,   150,   234,   151,    -1,    17,
     150,   234,   151,    -1,    18,   150,   234,   151,    -1,    19,
     150,   234,   151,    -1,    20,   150,   234,   151,    -1,    21,
     150,   234,   151,    -1,    22,   150,   234,   151,    -1,    24,
     150,   234,   151,    -1,    25,   150,   234,   156,   234,   151,
      -1,    26,   150,   234,   151,    -1,    27,   150,   234,   151,
      -1,    28,   150,   234,   151,    -1,    29,   150,   234,   151,
      -1,    30,   150,   234,   151,    -1,    31,   150,   234,   151,
      -1,    32,   150,   234,   156,   234,   151,    -1,    33,   150,
     234,   156,   234,   151,    -1,    34,   150,   234,   156,   234,
     151,    -1,    23,   150,   234,   151,    -1,    14,   152,   234,
     153,    -1,    15,   152,   234,   153,    -1,    16,   152,   234,
     153,    -1,    17,   152,   234,   153,    -1,    18,   152,   234,
     153,    -1,    19,   152,   234,   153,    -1,    20,   152,   234,
     153,    -1,    21,   152,   234,   153,    -1,    22,   152,   234,
     153,    -1,    24,   152,   234,   153,    -1,    25,   152,   234,
     156,   234,   153,    -1,    26,   152,   234,   153,    -1,    27,
     152,   234,   153,    -1,    28,   152,   234,   153,    -1,    29,
     152,   234,   153,    -1,    30,   152,   234,   153,    -1,    31,
     152,   234,   153,    -1,    32,   152,   234,   156,   234,   153,
      -1,    33,   152,   234,   156,   234,   153,    -1,    34,   152,
     234,   156,   234,   153,    -1,    23,   152,   234,   153,    -1,
       3,    -1,     9,    -1,    10,    -1,    11,    -1,   124,    -1,
     125,    -1,   126,    -1,     4,    -1,     4,   159,   157,   234,
     158,    -1,     4,   152,   234,   153,    -1,   155,     4,   152,
     153,    -1,     4,   183,    -1,     4,   152,   234,   153,   183,
      -1,     4,   154,     4,    -1,     4,   152,   234,   153,   154,
       4,    -1,     4,   154,     4,   183,    -1,     4,   152,   234,
     153,   154,     4,   183,    -1,   119,   150,   246,   156,   234,
     151,    -1,   237,    -1,   141,   236,    -1,   140,   236,    -1,
     236,   141,   236,    -1,   236,   140,   236,    -1,   157,   234,
     156,   234,   156,   234,   156,   234,   156,   234,   158,    -1,
     157,   234,   156,   234,   156,   234,   156,   234,   158,    -1,
     157,   234,   156,   234,   156,   234,   158,    -1,   150,   234,
     156,   234,   156,   234,   151,    -1,   239,    -1,   238,   156,
     239,    -1,   234,    -1,   241,    -1,   157,   158,    -1,   157,
     242,   158,    -1,   141,   157,   242,   158,    -1,   234,   142,
     157,   242,   158,    -1,   239,    -1,     5,    -1,   141,   241,
      -1,   234,   142,   241,    -1,   234,     8,   234,    -1,   234,
       8,   234,     8,   234,    -1,    50,   157,   234,   158,    -1,
      50,     5,    -1,    53,     5,    -1,    56,     5,    -1,    58,
       5,    -1,    68,    50,   157,   242,   158,    -1,    68,    53,
     157,   242,   158,    -1,    68,    56,   157,   242,   158,    -1,
      68,    58,   157,   242,   158,    -1,   199,    -1,   208,    -1,
       4,   152,   153,    -1,    35,   152,     4,   153,    -1,     4,
     152,   157,   242,   158,   153,    -1,   234,    -1,   241,    -1,
     242,   156,   234,    -1,   242,   156,   241,    -1,   157,   234,
     156,   234,   156,   234,   156,   234,   158,    -1,   157,   234,
     156,   234,   156,   234,   158,    -1,     4,    -1,     4,   154,
     105,   154,     4,    -1,   157,   245,   158,    -1,     4,   152,
     234,   153,   154,   106,    -1,   243,    -1,   245,   156,   243,
      -1,   247,    -1,     4,    -1,     4,   154,     4,    -1,     4,
     152,   234,   153,   154,     4,    -1,     5,    -1,    44,    -1,
     120,   150,   246,   151,    -1,   121,   150,   246,   156,   246,
     151,    -1,    39,   150,   246,   156,   246,   151,    -1,    40,
     150,   246,   151,    -1,    41,   150,   246,   151,    -1,    38,
     150,   246,   151,    -1,    38,   150,   246,   156,   242,   151,
      -1
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
    2510,  2555,  2572,  2587,  2606,  2618,  2642,  2647,  2654,  2660,
    2665,  2671,  2675,  2679,  2689,  2706,  2723,  2744,  2765,  2800,
    2808,  2814,  2821,  2825,  2834,  2842,  2850,  2859,  2858,  2872,
    2871,  2885,  2884,  2898,  2897,  2910,  2917,  2924,  2931,  2938,
    2945,  2952,  2959,  2966,  2974,  2973,  2986,  2985,  2998,  2997,
    3010,  3009,  3022,  3021,  3034,  3033,  3046,  3045,  3058,  3057,
    3070,  3069,  3085,  3088,  3094,  3103,  3123,  3146,  3150,  3154,
    3158,  3162,  3166,  3185,  3198,  3201,  3217,  3220,  3233,  3236,
    3242,  3245,  3252,  3308,  3378,  3383,  3450,  3486,  3495,  3538,
    3563,  3590,  3634,  3657,  3680,  3683,  3692,  3696,  3706,  3741,
    3742,  3746,  3753,  3766,  3785,  3813,  3814,  3815,  3816,  3817,
    3818,  3819,  3820,  3821,  3828,  3829,  3830,  3831,  3832,  3833,
    3834,  3835,  3836,  3837,  3838,  3839,  3840,  3841,  3842,  3843,
    3844,  3845,  3846,  3847,  3848,  3849,  3850,  3851,  3852,  3853,
    3854,  3855,  3856,  3857,  3858,  3859,  3861,  3862,  3863,  3864,
    3865,  3866,  3867,  3868,  3869,  3870,  3871,  3872,  3873,  3874,
    3875,  3876,  3877,  3878,  3879,  3880,  3881,  3890,  3891,  3892,
    3893,  3894,  3895,  3896,  3900,  3920,  3939,  3957,  3969,  3986,
    4007,  4012,  4017,  4027,  4037,  4045,  4049,  4053,  4057,  4061,
    4068,  4072,  4076,  4080,  4087,  4092,  4099,  4104,  4108,  4113,
    4117,  4125,  4136,  4140,  4152,  4160,  4168,  4175,  4186,  4206,
    4210,  4214,  4218,  4222,  4240,  4258,  4276,  4294,  4304,  4314,
    4326,  4338,  4359,  4364,  4368,  4372,  4384,  4388,  4400,  4407,
    4417,  4421,  4436,  4441,  4448,  4452,  4465,  4473,  4484,  4488,
    4496,  4504,  4512,  4520,  4534,  4548,  4552
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
     385,    63,   386,   387,   388,   389,    60,    62,   390,   391,
      43,    45,    42,    47,    37,    33,   392,   393,   394,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   160,   161,   161,   162,   162,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   167,   167,   167,   167,   167,   167,
     168,   168,   169,   169,   171,   172,   170,   173,   173,   175,
     174,   176,   176,   178,   177,   179,   179,   181,   180,   182,
     182,   182,   182,   182,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   185,   185,   186,   186,   186,   187,   186,   188,
     188,   189,   189,   190,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   195,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   196,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   197,   194,
     194,   194,   194,   198,   194,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   201,   201,   201,   201,   201,
     201,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   203,   203,   203,   203,   204,   205,   205,   205,   205,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   208,   208,   208,   209,   208,   210,
     208,   211,   208,   212,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   213,   208,   214,   208,   215,   208,
     216,   208,   217,   208,   218,   208,   219,   208,   220,   208,
     221,   208,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   228,   228,   228,   228,   228,   228,   228,   228,
     229,   229,   230,   230,   230,   230,   231,   231,   231,   232,
     232,   233,   233,   233,   233,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   236,   236,   236,   236,   236,
     237,   237,   237,   237,   238,   238,   239,   239,   239,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   242,   242,   242,   242,   243,   243,   243,   243,
     244,   244,   245,   245,   246,   246,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247
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
       3,     7,     7,     3,     7,     3,     2,     2,     2,    15,
       2,     2,     2,     2,     6,     8,     8,    10,     1,     2,
       1,     3,     4,     1,     5,    11,    13,     0,     7,     0,
      13,     0,    15,     0,     6,     8,     8,     8,    12,    12,
      12,    14,    14,    14,     0,    12,     0,    12,     0,    12,
       0,    16,     0,    16,     0,    16,     0,    18,     0,    18,
       0,    18,     1,     2,     5,     7,     9,     2,     2,     3,
       2,     3,     9,     6,     0,     3,     0,     1,     0,     2,
       0,     2,     7,     6,     8,     5,     3,     7,     5,     6,
       6,    12,    10,    10,    10,    10,     2,     3,     6,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     4,     2,     5,
       3,     6,     4,     7,     6,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     5,     5,     5,     5,     1,     1,     3,
       4,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       4,     6,     6,     4,     4,     4,     6
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
       0,   198,     0,   203,     0,     0,   200,     0,     0,     0,
       0,   279,   280,     5,     7,     6,     8,     9,    10,    21,
      11,    12,    13,    20,    19,    14,    15,    16,    17,    18,
       0,    22,   347,   354,   418,    59,   348,   349,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   419,     0,     0,     0,     0,   351,
     352,   353,    63,    62,    61,    60,     0,     0,     0,    65,
      64,     0,     0,     0,     0,   155,     0,     0,     0,   285,
       0,     0,     0,     0,     0,   188,     0,   190,   187,   191,
     192,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,     0,   113,   126,   138,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
       0,   276,     0,     0,     0,     0,     0,   354,   383,     0,
       0,     0,     0,     0,     0,     0,     0,   397,   398,   376,
     382,     0,   377,     0,     0,     0,     0,   408,     0,     0,
       0,     0,     0,   186,     0,     0,   199,     0,   155,     0,
     155,   281,     0,     0,     0,     0,     0,     0,   358,    34,
     418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,   288,   287,   289,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,   153,     0,    71,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   130,     0,     0,
       0,     0,    92,     0,     0,   402,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     367,   366,     0,     0,     0,     0,   155,   155,     0,     0,
       0,     0,     0,     0,     0,   213,     0,   155,     0,     0,
       0,     0,     0,   260,     0,     0,     0,   173,     0,     0,
       0,   277,     0,     0,     0,     0,     0,     0,     0,   389,
       0,   390,   391,   392,     0,     0,     0,     0,     0,   287,
     384,   378,     0,     0,     0,   266,   185,     0,     0,     0,
       0,     0,   155,     0,     0,     0,     0,   201,   176,     0,
     177,     0,     0,     0,     0,     0,   360,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,     0,   414,     0,     0,     0,     0,     0,
       0,     0,     0,   286,    59,     0,     0,     0,    59,     0,
       0,     0,     0,     0,   150,     0,     0,     0,     0,   156,
      67,     0,   303,   302,   301,   300,   296,   297,   299,   298,
     291,   290,   292,   293,   294,   295,   131,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,   369,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,     0,     0,   170,     0,
       0,     0,     0,     0,   399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   379,   386,     0,   292,   385,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,   178,
     179,     0,     0,     0,     0,   356,   362,     0,    44,     0,
       0,     0,    57,     0,    35,    36,    37,    38,    39,   305,
     326,   306,   327,   307,   328,   308,   329,   309,   330,   310,
     331,   311,   332,   312,   333,   313,   334,   325,   346,   314,
     335,     0,     0,   316,   337,   317,   338,   318,   339,   319,
     340,   320,   341,   321,   342,     0,     0,     0,     0,     0,
       0,     0,     0,   425,     0,     0,   423,   424,    84,     0,
     420,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,   357,     0,     0,     0,     0,     0,
      25,    23,     0,     0,    26,     0,     0,    66,    95,     0,
     404,   405,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     259,   257,     0,   265,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,     0,   204,     0,     0,     0,
       0,     0,     0,   261,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,   400,   388,     0,     0,
       0,     0,   380,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,   282,     0,     0,
     359,     0,   355,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,    72,
      74,    76,     0,     0,   412,     0,    82,     0,     0,     0,
       0,   304,    24,     0,     0,     0,     0,     0,     0,     0,
     110,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,     0,     0,   248,     0,   250,     0,   214,   243,     0,
       0,     0,   168,     0,     0,     0,   269,     0,   172,   171,
     278,     0,     0,    32,    33,     0,   393,   394,   395,   396,
     387,   381,     0,     0,     0,   409,     0,     0,     0,   194,
       0,     0,     0,     0,   182,   361,   181,     0,     0,     0,
       0,   374,     0,   315,   336,   322,   343,   323,   344,   324,
     345,     0,   426,   422,   364,   421,     0,    59,     0,     0,
       0,     0,    69,     0,     0,     0,   410,     0,     0,     0,
       0,    27,    28,     0,    29,     0,     0,    96,   112,     0,
       0,     0,     0,     0,   116,     0,     0,   133,   134,     0,
       0,   118,   141,     0,     0,     0,   108,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,     0,
       0,     0,     0,   155,   155,     0,   224,     0,   226,     0,
     228,     0,   376,     0,     0,   249,   251,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     401,   121,   122,     0,     0,     0,     0,    85,    89,     0,
       0,   283,   363,     0,    40,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,    79,     0,     0,    80,     0,
     413,   157,   158,   159,   160,     0,     0,    97,     0,   111,
     119,   120,   124,     0,     0,   135,     0,     0,   264,   128,
       0,     0,   255,   140,     0,     0,     0,     0,   125,     0,
     136,   142,     0,     0,     0,     0,   373,     0,   372,     0,
       0,     0,   215,     0,     0,   216,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,   167,     0,     0,   166,
       0,     0,     0,   161,     0,     0,     0,     0,   407,     0,
     196,   195,     0,     0,     0,     0,    45,     0,     0,     0,
     375,     0,     0,     0,   417,    70,    75,    77,     0,    83,
       0,    30,     0,   101,     0,     0,     0,     0,     0,     0,
     129,   114,   127,   139,   144,     0,     0,    90,    91,   155,
       0,   148,   149,     0,     0,     0,     0,     0,     0,     0,
     244,     0,     0,   155,     0,     0,     0,     0,     0,   152,
     151,     0,     0,     0,     0,    86,    87,     0,     0,    41,
       0,     0,     0,    43,    58,     0,   411,     0,     0,   272,
     273,   274,   275,   132,     0,     0,     0,     0,     0,   371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
       0,     0,     0,   209,     0,     0,   162,     0,     0,     0,
     406,   197,     0,   284,     0,     0,     0,     0,    81,     0,
       0,    98,   102,     0,     0,     0,   146,     0,   230,     0,
       0,   232,     0,     0,   234,     0,     0,     0,   245,     0,
     205,     0,   155,     0,     0,     0,   123,    88,     0,    49,
       0,    55,     0,     0,     0,   109,   137,   271,   370,   218,
       0,     0,   225,   219,     0,     0,   227,   220,     0,     0,
     229,     0,     0,     0,   211,     0,   165,     0,     0,     0,
       0,     0,     0,     0,   105,     0,   103,     0,   236,     0,
     238,     0,   240,   246,   252,   210,   206,     0,     0,     0,
       0,    46,     0,    53,     0,     0,     0,   402,     0,   221,
       0,     0,   222,     0,     0,   223,     0,     0,   169,     0,
     163,     0,    47,     0,     0,   189,     0,   104,     0,     0,
       0,     0,     0,     0,     0,   212,     0,     0,     0,     0,
       0,     0,    99,   231,     0,   233,     0,   235,     0,   164,
      48,    50,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    56,   100,   237,   239,   241,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    73,   762,    74,    75,   478,  1123,  1129,
     684,   873,  1278,  1431,   685,  1390,  1462,   686,  1433,   687,
     688,   877,   146,   268,    76,   574,   362,  1233,  1416,  1288,
    1332,   795,  1161,  1051,   549,   388,   389,   390,   391,   237,
     336,   337,    79,    80,    81,    82,    83,    84,   238,   827,
    1351,  1407,   623,  1183,  1186,  1189,  1370,  1374,  1378,  1420,
    1423,  1426,   823,   824,   938,   792,   597,   632,    86,    87,
      88,    89,    90,    91,   239,   149,   401,   202,  1010,  1011,
     241,   242,   452,   249,   753,   905,   523,   524
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1103
static const yytype_int16 yypact[] =
{
    3862,    41,    55,  3945, -1103, -1103,  1941,    92,    20,   -32,
      -1,    37,   158,   179,   195,   212,    73,  -123,    81,    85,
      24,    91,   164,    26,   167,   170,   268,   301,   304,   357,
     316,   365,    74,   317,    40,    95,   154,   286,   394,   310,
     -99,   -99,   340,   265,    60,   405,   412,   421,    16,    63,
     445,   446,   450,   516,  2099,   517,   381,   390,   391,    29,
      49, -1103,   395, -1103,   565,   426, -1103,   578,   585,     2,
      33, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
      43, -1103, -1103,    28,   435,    21, -1103, -1103, -1103,  -113,
      64,   101,   351,   401,   465,   474,   503,   508,   526,   527,
     561,   625,   628,   634,   644,   747,   754,   755,   758,   761,
     433,   454,   458,   473, -1103,   620,   478,   482,   483, -1103,
   -1103, -1103, -1103, -1103, -1103, -1103,  3666,  3666,  3666, -1103,
   -1103,  3666,  1457,    52,   632,   319,  2546,   646,   675, -1103,
     653,   660,  3666,   635,   662, -1103,  3666, -1103, -1103, -1103,
   -1103, -1103,  3666,  3589,  3666,  3666,   520,  3666,  3589,  3666,
    3666,   523,  3589,  3666,  3666,  2546,   530,   550, -1103,   558,
     566,  2099,  2099,  2099,   571, -1103, -1103, -1103, -1103,   572,
     581,   584,  2546,  3666,   734,  2546,   -99,   -99,   -99,  3666,
    3666,   -69, -1103,   -58,   -99,   602,   609,   612,  3374,   225,
     -82,   591,   597,   624,  2099,  2546,   637,    44,   618, -1103,
     736, -1103,   642,   643,   664,   651,   673,   592, -1103,   684,
      35,   845,   864,   886,   311,  2695,  1782, -1103, -1103,  2967,
   -1103,   854, -1103,   894,  3666,  3666,  3666,   707,  3666,   759,
     795,  3666,  3666, -1103,  3666,   906, -1103,   926, -1103,   933,
   -1103, -1103,  2546,  2546,   796,  3666,   943,   798, -1103, -1103,
   -1103,   946,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  3666,  3666,   518,   518,   518,   518,  3666,   518,
     518,   518,   413,   807,   807,   807,  6290,    93,  3589,  5531,
     208,   811,   967,   838,   825, -1103,   839,  4020,   995, -1103,
   -1103,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  3666,  3666,  3666,  3666, -1103, -1103,   786,    76,
     233,  4829,   -28,  6311,  3589,  3047, -1103,   369,  6332,  6353,
    3666,  6374,   392,  6395,  6416,  3666,   456,  6437,  6458,   991,
    3666,  3666,  3666,  3666,  1015,  1034,  1034,  3666,   869,   892,
     900,   901,  3666,  3666,  3666,  1039,  4749,   904,  1050,    72,
   -1103, -1103,  4855,  4881,   -99,   -99,   319,   319,   230,  3666,
    3666,  3666,  3374,  3374,  3666,  4020,   247, -1103,  3666,  3666,
    3666,  3666,  3666,  1054,  1064,  3666,  1081, -1103,  3666,  3666,
     776, -1103,  3589,  3589,  3589,  3666,  3666,  3219,  1084, -1103,
    3666, -1103, -1103, -1103,   940,   945,   965,   982,  3589,   807,
   -1103, -1103,   775,  3666,  2844, -1103, -1103,  6479,  6500,  6521,
     988,  4907, -1103,   985,  3345,  6542,  5554, -1103, -1103,  1277,
   -1103,  1829,   958,   782,  3666,  5577,   -63,  3666,    11, -1103,
    6563,  5600,  6584,  5623,  6605,  5646,  6626,  5669,  6647,  5692,
    6668,  5715,  6689,  5738,  6710,  5761,  6731,  5784,  6752,  5807,
    6773,  5830,  4933,  4959,  6794,  5853,  6815,  5876,  6836,  5899,
    6857,  5922,  6878,  5945,  6899,  5968,  4985,  5011,  5037,  5063,
    5089,  5115,   790,   246, -1103,   997,   996,  1003,   896,  1013,
    1028,  1017,  3666, -1103, -1103,  2546,   787,   110,    21,  3666,
    1178,  1181,    31,  1035, -1103,   -55,    27,    32,   -53, -1103,
   -1103,  3401,   746,  1023,  1259,  1259,   715,   715,   715,   715,
     350,   350,   807,   807,   807,   807, -1103,    10,  3589,  1183,
    3589,  3666,  1184, -1103,  1187,  1180,  3589,  3589,  1086,  1185,
    1189,  6920,  1191,  1091,  1193,  1194,  6941,  1094,  1196,  1197,
    3666,  6962,  4077,  6983,  7004,  3666,  2546,  1202,  1203,  7025,
    3732,  3732,  3732,  3732,  7046,  7067,  7088,  2546,  3589,  1057,
   -1103,   -99,  3666,  3666, -1103, -1103,  1055,  1056,  3374,  5141,
    5167,  5193,  4803,   174,   -99,  1977,  7109,  4105,  7130,  7151,
    7172,  3666,  1206,  3666,  7193, -1103,  5991,  6014, -1103,   805,
     806,   810,  6037,  6060, -1103,  3589,  6083,  1063,  4133,  3589,
    3589,  3589,  3589,   814, -1103,  3494,  3589,   807, -1103,  1201,
    1210,  1211,  1065,  3666,  2284,  3666,  3666, -1103,     1, -1103,
   -1103,  1078,  2546,  1230,  6106,    82, -1103,  4161, -1103,  1087,
    1088,  1083, -1103,  1235, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103,  3666,  3666, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103, -1103, -1103, -1103,  3666,  3666,  3666,  3666,  3666,
    3666,  3666,  1238, -1103,  3589,   518, -1103, -1103, -1103,  3666,
   -1103,   518,  1237,  1095,    99,  3666,  1243,  1244,  1090, -1103,
    1245,  1102,    29,  1251, -1103,  3589,  3589,  3589,  3589,  3666,
   -1103,  1121,   518,   294, -1103,   297,  5219, -1103,  1252,   -99,
    3047, -1103,  1204,  2546,  2546,  1256,  2546,   913,  2546,  2546,
    1257,  1208,  2546,  2546,  1361,  1261,  1263,  1264,  1265,  3965,
   -1103, -1103,  1267, -1103,  1268,  1123,  7424, -1103,  1125,  1126,
    1129,  1274,  1275,  1276,  1278,   830,  1282,   288,  5245,  5271,
   -1103, -1103,  4189,   -95,   -99,   -99,   -99,  1283,  1285,  1131,
    1143,     8,    18,   -14, -1103,   388, -1103,   174,  1287,  1289,
    1290,  1291,  1292,  7424, -1103,  1587,  1144,  1294,  1296,  1297,
    1253,  3666,  1301,  1304,   831,   177, -1103, -1103,   835,   850,
     851,   855, -1103,  3666,   856,  2546,  2546,  2546,  1307,  5297,
   -1103,  3693,   555,  1308,  1309,  2546,  1156, -1103,  1311,  1314,
   -1103,  1315, -1103,  1165,  3666,  3666,  2546,  1163, -1103,  7214,
    6129,  7235,  6152,  7256,  6175,  7277,  6198,  6221, -1103,   306,
    1172,  7298,  1173, -1103,    93,   312,  1171,  1319,  1687, -1103,
   -1103, -1103,    29,  3666, -1103,   859, -1103,   860,   867,   910,
     911,  7424, -1103,  1333,    19,  1342,  3666,  3440,     5,  1192,
    1288,  1288,  2546,  1348,  1198,  1199,  1351,  1353,  2546,  1205,
    1354,  1359, -1103,  1365,  2546,  2546,  2546,  1367,  1368, -1103,
    2546,  1369,  1373,  1375,  1377,  2546,  2546,  2546, -1103,  1378,
     131,  3666,  3666,  3666,  1218,  1229,   -25,    68,   218,  1236,
   -1103,  2546,  3666, -1103,  1381, -1103,  1385, -1103, -1103,  3374,
     242,  2248, -1103,  1247,  1248,  2993, -1103,  3589, -1103, -1103,
   -1103,  1254,  1860, -1103, -1103,  1239, -1103, -1103, -1103, -1103,
    7424, -1103,  1388,  1403,  1306, -1103,  3666,  3666,  3666, -1103,
    1406,   418,  1258,  1407, -1103,   -63, -1103,  3666,  5323,  5349,
     916, -1103,  3666, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103,  1262, -1103, -1103, -1103, -1103,  2546,    21,  3666,  1409,
    1413,    31, -1103,  1412,  6244,    29, -1103,  1414,  1416,  1417,
    1418, -1103, -1103,   518, -1103,  5375,  3666,  7424, -1103,  3666,
     -99,  1419,  1420,  1421, -1103,  3666,  3666, -1103, -1103,  1422,
    3666, -1103, -1103,  1424,  1425,  1427,  1322,  3666, -1103,  1430,
    2546,  2546,  2546,  2546,  1431,  1072,  1432,  3666, -1103,  3732,
    4217,  7319,  3992,   319,   319,   -99,  1433,   -99,  1434,   -99,
    1435,  3666,   346,  1286,  7340, -1103, -1103,  4245,   398, -1103,
    1437,  1614,  1438,  2546,   -99,  1614,  1442,   923,  3666, -1103,
   -1103, -1103, -1103,  2546,  4021,   375,  7361, -1103, -1103,  3291,
    2546, -1103, -1103,   320,  7424,  3666,  3666,  2546,  1293,   924,
    7424,  1415,  1443,  1445,  2057, -1103,  1446,  1448, -1103,  1298,
   -1103, -1103, -1103, -1103, -1103,  1450,  3666,  7424,  4273,   258,
   -1103, -1103, -1103,  4301,  4329, -1103,  4357,  1452, -1103, -1103,
    1453,  1464,  7424, -1103,  1500,  1502,  1503,  1505, -1103,  1356,
   -1103, -1103,  4776,  2650,  1508,  1358, -1103,  3666, -1103,  1362,
    1363,   462, -1103,  1360,   479, -1103,  1366,   481, -1103,  1370,
    6267,  1510,  2546,  1512,  1371,  3666, -1103,  3142,   544, -1103,
     936,   574,   577, -1103,  1516,  4385,  1426,  3666, -1103,  3666,
   -1103, -1103,  3589,  2669,  1525,  1374, -1103,  3666,  5401,  5427,
   -1103,  2546,  3666,  1527, -1103, -1103, -1103, -1103,    29, -1103,
    1428, -1103,  5453, -1103,  1532,  1533,  1535,  1536,  1537,  1387,
   -1103, -1103, -1103, -1103, -1103,  2546,  3589, -1103, -1103,   319,
    4049, -1103, -1103,  3374,   174,  3374,   174,  3374,   174,  1539,
   -1103,   942,  2546, -1103,  4413,   -99,  1540,  3589,   -99, -1103,
   -1103,  3666,  4441,  4469,   949, -1103, -1103,  1542,  1392,  7424,
    3666,  3666,   952,  7424, -1103,  1544, -1103,  3666,   962, -1103,
   -1103, -1103, -1103, -1103,  3666,   963,   970,  1394,  3666, -1103,
    4497,   579,   378,  4525,   623,   455,  4553,   627,   493, -1103,
    2546,  1547,  1483,  2433,  1398,   682, -1103,   971,   706,  2749,
   -1103, -1103,  1550, -1103,  3666,  7382,  5479,    38, -1103,  5505,
    1553, -1103, -1103,  4581,  1552,  1554, -1103,  4609,  1556,  3666,
    1557,  1558,  3666,  1560,  1561,  3666,  1566,  1401, -1103,  3666,
   -1103,   174, -1103,  3589,  1567,  3142, -1103, -1103,   975, -1103,
    3666, -1103,  2546,  3666,  2397, -1103, -1103, -1103, -1103, -1103,
    1423,  4637, -1103, -1103,  1429,  4665, -1103, -1103,  1439,  4693,
   -1103,  1569,  2809,   499,  2582,   976, -1103,   753,   979,  1571,
    1444,  7403,   987,  4721, -1103,  1782, -1103,   174,  1572,   174,
    1573,   174,  1578, -1103, -1103, -1103, -1103,   174,  1579,  3589,
    1581, -1103,   518, -1103,  1447,  1582,   992,  2898,   554, -1103,
    1449,   710, -1103,  1451,   783, -1103,  1454,   866, -1103,  1012,
   -1103,  1018, -1103,  1456,  2546, -1103,  3666, -1103,    21,  1583,
     174,  1584,   174,  1585,   174, -1103,  1586,   518,  1588,   518,
    1022,  2948, -1103, -1103,   912, -1103,   972, -1103,  1024, -1103,
   -1103, -1103,  1025, -1103,  1593,    21,  1594,  1597,  1599,   518,
    1603, -1103, -1103, -1103, -1103, -1103, -1103, -1103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1103, -1103, -1103, -1103,   701, -1103, -1103, -1103, -1103,   295,
   -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103,  -318,    -3, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103,  -334, -1103,   699,  1618, -1103, -1103, -1103, -1103,     7,
    -401,  -206, -1103, -1103, -1103, -1103, -1103, -1103,  1619, -1103,
   -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103, -1103,
   -1103, -1103,  -649,  -753, -1103, -1103,  1240, -1103, -1103, -1103,
   -1103, -1103, -1103, -1103,    -2, -1103,    51, -1103, -1102,   590,
    -102,   813,   328,  -723,   596, -1103,  -298,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     150,  1200,   415,   147,   148,   616,   617,   257,   863,   535,
      78,  1048,   539,   430,   963,   678,   760,   525,   526,   527,
     217,   529,   530,   531,   965,  1042,   270,   162,   166,   904,
     171,   166,   264,   247,   163,   751,   171,   272,   259,   273,
     439,   197,   198,   155,  1361,   404,   405,     4,   426,   261,
     427,   199,   469,   250,   471,     5,   330,   817,   200,   120,
     121,   122,   123,   955,   210,   124,   818,   220,   418,   221,
     968,   404,   405,   819,   820,   419,   152,   821,   822,   384,
     385,   386,   404,   405,   139,   140,   522,   270,   406,   271,
     185,   201,   203,   186,   209,   162,   187,   174,   188,   407,
     534,   964,   755,   895,   758,   151,   679,   680,   681,   682,
     211,   966,   423,   222,   212,   404,   405,   534,   153,  1282,
     120,   121,   122,   123,   213,   572,   124,   181,   573,   218,
     182,  1085,   183,  1086,   323,   324,   325,  1078,  1079,   326,
     329,   127,   128,  1295,   967,   404,   405,   761,   189,   154,
     358,   190,   335,   191,   361,   864,   761,   331,   332,   258,
     363,   365,   368,   369,   157,   371,   365,   373,   374,   683,
     365,   377,   378,   219,   167,   139,   140,   167,   970,  1033,
     265,   168,   266,   172,   756,   158,   248,   267,   752,   757,
     260,   396,   440,   262,   156,  1362,   428,   402,   403,   251,
     263,   159,   127,   128,   896,   897,   403,   192,   404,   405,
     193,   625,   404,   405,   274,   538,   275,   968,   160,   745,
     132,   133,   134,   135,  1087,   161,  1088,   567,   611,   139,
     140,   164,   568,   449,   365,   165,   869,   132,   133,   134,
     135,   169,   457,   458,   459,   817,   461,   399,   400,   464,
     465,   276,   466,   277,   818,   408,   664,   139,   140,   416,
    1392,   819,   820,   475,   744,   821,   822,   798,   799,   800,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,  1140,   817,   170,   205,   528,   173,   206,  1027,
     174,   207,   818,   334,   139,   140,   365,   540,   175,   819,
     820,   869,  1450,   821,   822,   132,   133,   134,   135,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   453,   139,   140,   176,   404,   405,
     177,   444,   449,   178,   445,   404,   405,   446,   581,   447,
     404,   405,   179,   586,  1089,   184,  1090,   871,   591,   592,
     593,   594,   417,  1209,   569,   599,   618,   404,   405,   570,
     604,   605,   606,    39,    40,    41,    42,   733,   404,   405,
    1099,    47,   734,   624,    50,   197,   198,   619,   620,   621,
     323,   324,   622,   335,   335,   199,   626,   627,   628,   629,
     630,   180,   208,   634,  1118,  1119,   636,   637,   404,   405,
     365,   365,   365,   642,   643,   646,   194,   890,   648,   132,
     133,   134,   135,   892,   951,   914,   365,   195,   915,   817,
     577,   655,   657,   577,   225,   614,   615,  1022,   818,   139,
     140,   214,   577,   400,   913,   819,   820,   196,   215,   821,
     822,  1216,   674,   676,   216,   677,  1217,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   454,   353,
     354,   367,   352,   353,   354,   355,   372,   204,   223,   355,
     376,   278,   224,   279,  1191,  1285,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     226,   243,   522,   270,   355,   577,   817,   578,   404,   405,
     646,   244,   747,  1210,   746,   818,  1340,   748,   404,   405,
     245,   246,   819,   820,   969,   252,   821,   822,   577,   968,
     583,   280,   968,   281,  1195,   968,   120,   121,   122,   123,
     139,   140,   124,   998,   817,   532,   365,   266,   365,   766,
     817,   253,   267,   818,   657,   770,  1026,  1028,   254,   818,
     819,   820,   255,   314,   821,   822,   819,   820,   784,   256,
     821,   822,   269,   789,   797,   797,   797,   797,   796,   796,
     796,   796,   404,   405,   315,  1302,   365,  1305,   316,  1308,
     808,   809,   577,  1343,   587,   282,   812,   283,  1253,   404,
     405,   404,   405,   317,   284,   817,   285,   318,   319,   833,
     968,   835,   320,   321,   818,  1255,   333,  1257,   127,   128,
     359,   819,   820,   365,   240,   821,   822,   365,   365,   365,
     365,  1346,   339,   286,   365,   287,   536,  1405,   288,   356,
     289,   859,   807,   861,   862,   968,   357,   360,   968,   813,
     370,   968,   870,   375,   968,   825,   290,   292,   291,   293,
     380,   340,  1179,  1180,   404,   405,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
    1265,   968,  1383,   968,   355,   968,   999,   381,   382,   879,
     880,   294,  1439,   295,   404,   405,   383,   404,   405,   404,
     405,   387,   392,   881,   882,   883,   884,   885,   886,   887,
    1267,   393,   365,  1268,   394,  1339,   338,   891,   397,   139,
     140,   420,   431,   898,   437,  1145,   266,   421,  1418,   145,
    1421,   267,  1424,   365,   365,   365,   365,   911,  1427,   409,
     639,   640,   641,   404,   405,   379,   410,   404,   405,   411,
     429,   240,   240,   240,   422,   296,   653,   297,   298,  1342,
     299,   817,   395,  1345,   300,   398,   301,   425,     7,     8,
     818,  1454,   566,  1456,   302,  1458,   303,   819,   820,   432,
     433,   821,   822,   435,   240,   424,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     918,   434,   404,   405,   355,   436,   545,    18,    19,   546,
      21,    22,   547,    24,   548,    26,   438,    27,  1353,   982,
      30,    31,   870,    33,    34,    35,   404,   405,  1297,    38,
     441,   990,   472,   473,   817,   350,   351,   352,   353,   354,
     455,   460,  1355,   818,   355,   956,   957,   958,  1441,   442,
     819,   820,  1008,  1009,   821,   822,    56,    57,    58,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   443,  1029,   404,   405,   355,   763,   304,   765,   305,
     456,  1034,   738,   463,   306,   308,   307,   309,   310,  1409,
     311,   312,   467,   313,  1045,  1047,   462,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   577,   468,   654,   638,   355,   805,   817,   672,   470,
     673,  1443,   731,   577,   732,   743,   818,   476,   474,  1080,
    1081,  1082,   479,   819,   820,   477,   355,   821,   822,  1092,
    1094,   577,   577,   839,   840,   541,   577,  1097,   841,   924,
     577,   925,   852,   844,   542,   365,   366,   848,   849,   850,
     851,   366,   145,   817,   854,   366,   577,   577,   949,   985,
     543,   577,   818,   986,  1114,  1115,  1116,   544,   590,   819,
     820,   550,  1122,   821,   822,  1124,   577,   577,   987,   988,
    1130,   577,   577,   989,   991,  1035,   577,  1036,  1037,   600,
    1098,  1133,   595,   577,  1445,  1038,  1134,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   596,   601,   817,  1147,   355,   607,  1148,   450,   366,
     602,   603,   818,  1153,  1154,   609,   610,  1313,  1156,   819,
     820,   631,   889,   821,   822,  1162,   577,   577,  1039,  1040,
    1466,   633,  1127,  1174,  1128,  1172,  1169,  1173,  1170,   577,
    1222,  1204,  1223,   907,   908,   909,   910,   635,   647,  1190,
     335,   335,  1127,   662,  1266,   817,   901,   649,  1310,   365,
    1311,  1149,   650,   365,   818,   577,  1205,  1322,  1127,   671,
    1327,   819,   820,  1214,  1432,   821,   822,  1213,  1330,  1127,
    1331,  1334,   651,  1218,  1219,   742,   577,   577,  1335,  1354,
    1467,  1222,   577,  1389,  1408,   577,  1181,  1410,  1184,   652,
    1187,   366,   665,  1127,  1232,  1414,  1384,   736,  1436,  1460,
    1437,  1463,  1198,   735,   737,  1201,  1202,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   577,   739,
    1446,  1476,   355,   741,  1447,  1250,  1448,   450,  1127,   740,
    1464,  1469,  1468,  1470,   749,   750,   790,   769,   754,   764,
     767,   768,   773,  1264,   772,   449,   774,   804,   776,   777,
     778,   779,   781,   782,   783,  1272,   791,  1273,   855,   793,
     365,   806,   834,   810,   811,  1279,   846,   856,   857,   858,
    1283,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   865,   867,   874,   875,   355,
     876,   878,   888,   893,   365,   366,   366,   366,   894,   899,
     900,  1300,   902,  1303,   903,  1306,   335,   906,   912,   917,
     919,   366,   866,   922,   928,   365,   929,   658,   933,  1319,
     934,   935,   936,   939,   941,   940,   942,   943,  1325,  1326,
     944,   945,   946,   947,   948,  1329,   950,   959,   961,     7,
       8,   960,  1333,   962,   971,   972,  1337,   973,   974,   975,
     978,   977,   979,   980,  1301,  1107,  1304,   983,  1307,   981,
     984,   995,  1000,  1001,  1003,  1007,  1315,  1004,  1005,  1318,
    1012,  1006,  1130,  1023,  1025,  1030,  1031,   545,    18,    19,
     546,    21,    22,   547,    24,   548,    26,  1371,    27,  1041,
    1375,    30,    31,  1379,    33,    34,    35,  1382,  1044,  1049,
      38,   365,  1050,   365,  1054,  1055,  1056,  1057,  1391,  1058,
    1061,  1393,  1060,   920,   921,  1062,   923,   932,   926,   927,
    1063,  1067,   930,   931,  1068,  1083,  1070,    56,    57,    58,
    1071,   366,  1072,   366,  1073,  1077,  1084,  1095,  1091,   658,
     771,  1096,  1110,  1417,  1111,   346,   347,   348,   349,   350,
     351,   352,   353,   354,  1103,  1104,  1387,   365,   355,  1112,
    1113,  1108,  1117,  1121,  1120,  1135,  1131,  1136,  1138,  1224,
    1141,   366,  1142,  1143,  1144,  1150,  1151,  1152,  1155,  1157,
    1160,  1158,  1452,  1159,  1451,   669,  1163,  1168,  1171,  1182,
    1185,  1188,  1192,  1196,  1199,   992,   993,   994,  1203,  1225,
    1221,  1226,  1230,  1228,  1229,  1002,  1231,  1238,   366,  1472,
      92,   322,   366,   366,   366,   366,    96,    97,    98,   366,
    1240,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,  1241,  1239,  1242,  1243,
     355,  1244,  1053,  1245,  1248,  1249,  1260,  1254,  1059,  1262,
    1251,  1252,  1269,  1256,  1064,  1065,  1066,  1258,  1263,  1271,
    1069,  1276,  1277,  1284,  1286,  1074,  1075,  1076,  1289,  1290,
    1274,  1291,  1292,  1293,  1294,  1309,  1316,   366,  1323,  1324,
    1328,  1093,  1336,  1348,  1349,  1352,  1357,  1364,  1366,  1381,
    1367,  1102,  1369,  1372,  1373,  1106,  1376,  1377,   366,   366,
     366,   366,  1380,  1386,  1296,  1403,   126,  1411,  1419,  1422,
    1397,   129,   130,   131,  1425,  1428,  1399,  1430,  1435,  1453,
    1455,  1457,  1459,   976,  1461,  1317,  1401,   136,   137,  1471,
    1473,  1412,   138,  1474,  1434,  1475,  1440,   141,  1442,  1477,
     327,  1444,   144,  1449,   328,  1043,  1132,    92,   227,  1358,
    1052,    77,    85,    96,    97,    98,   598,  1137,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1164,  1165,  1166,  1167,   230,     0,     0,   231,     0,     0,
     232,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,  1385,   234,  1388,     0,     0,     0,     0,    39,    40,
      41,    42,    43,  1032,     0,     0,    47,     0,     0,    50,
       0,     0,     0,  1206,     0,     0,     0,     0,     0,     0,
    1215,     0,     0,     0,     0,     0,     0,  1220,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,   126,     0,     0,   355,  1429,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,  1197,     0,     0,     0,   138,
       0,     0,     0,     0,   414,     0,     0,     0,     0,   144,
       0,   200,   451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1261,     0,     0,    92,   227,     0,     0,     0,
     366,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   229,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   230,     0,     0,   231,   355,     0,   232,     0,
     233,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     234,     0,  1312,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     0,    47,     0,  1109,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   545,
      18,    19,   546,    21,    22,   547,    24,   548,    26,     0,
      27,     0,     0,    30,    31,     0,    33,    34,    35,     0,
    1347,   126,    38,     0,     0,     0,   129,   130,   131,     0,
       0,     0,     0,     0,   366,     0,     0,     0,   366,     0,
       0,     0,   136,   364,     0,     0,     0,   138,     0,    56,
      57,    58,   141,     0,     0,     0,     0,   144,     0,     0,
     451,     0,     0,     0,    92,    93,    94,     0,    95,     0,
      96,    97,    98,     0,  1396,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,   120,
     121,   122,   123,     0,     0,   124,     0,   670,     0,     7,
       8,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   366,     0,   545,    18,    19,
     546,    21,    22,   547,    24,   548,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,   125,     0,     0,     0,     0,   366,
     126,   127,   128,  1227,     0,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,    56,    57,    58,
     366,   136,   137,     0,     0,     0,   138,     0,   139,   140,
       0,   141,     0,   142,     0,   143,   144,     0,   145,     0,
       0,     0,    92,   227,   228,     0,     0,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   229,   826,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,     0,   231,     0,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   366,   234,   366,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,     0,     0,     0,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,   366,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,   366,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     235,     0,     0,     0,   138,     0,     0,     0,     0,   141,
       0,    92,   227,  1100,   144,     0,   236,    96,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,   230,     0,
       0,   231,     0,     0,   232,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
      47,     0,     0,    50,   545,    18,    19,   546,    21,    22,
     547,    24,   548,    26,     0,    27,     0,     0,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,     0,   136,   235,
       0,     0,     0,   138,     0,     0,     0,     0,   141,     0,
      92,   227,  1394,   144,     0,  1101,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   860,     0,     0,     7,     8,   230,     0,     0,
     231,     0,     0,   232,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,   545,    18,    19,   546,    21,    22,   547,
      24,   548,    26,     0,    27,     0,     0,    30,    31,     0,
      33,    34,    35,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,   136,   235,     0,
       0,     0,   138,     0,     0,     0,     0,   141,     0,    92,
     227,     0,   144,     0,  1395,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1350,     0,     0,     7,     8,   230,     0,     0,   231,
       0,     0,   232,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     0,     0,    47,     0,
       0,    50,   545,    18,    19,   546,    21,    22,   547,    24,
     548,    26,     0,    27,     0,     0,    30,    31,     0,    33,
      34,    35,     0,     0,     0,    38,  1247,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,     0,     0,     0,
     129,   130,   131,     0,     0,  1275,     0,     0,     0,     0,
       0,     0,    56,    57,    58,     0,   136,   235,     0,     0,
       0,   138,     0,     0,     0,     0,   141,     0,    92,   227,
       0,   144,     0,   236,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1406,     0,     0,     0,     0,   230,     0,     0,   231,     0,
       0,   232,     0,   233,     0,  1356,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   126,  1404,     0,     0,   355,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   364,     0,     0,     0,
     138,     0,     0,     0,     0,   141,     0,    92,   227,     0,
     144,     0,   448,    96,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   229,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   230,     0,     0,   231,   355,     0,
     232,     0,   233,     0,     0,  1438,   453,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,    47,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,  1465,     0,     0,   355,     0,
       0,     0,     0,   126,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,     0,   453,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   364,     0,     0,     0,   138,
       0,     0,     0,     0,   141,     0,    92,   227,     0,   144,
       0,   656,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   229,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     576,   353,   354,   230,     0,     0,   231,   355,     0,   232,
       0,   233,     0,     0,     0,   453,     0,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   454,
     353,   354,   126,     0,     0,     0,   355,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   235,     0,     0,     0,   138,     0,
       0,     0,     0,   141,     0,    92,   227,     0,   144,     0,
    1105,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   229,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   576,
     353,   354,   230,     0,     0,   231,   355,     0,   232,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,    92,   322,    47,     0,     0,    50,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   412,  1197,     0,     0,     0,   138,     0,     0,
       0,     0,   414,     0,    92,   322,   270,   144,     0,   200,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,   120,
     121,   122,   123,     0,     0,   124,     0,     0,   126,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,   666,     0,     0,     0,     0,     0,   136,
     137,     0,     0,     0,   138,     0,     0,     0,     0,   141,
       0,     0,   644,     0,   144,     0,   645,    92,   322,     0,
       0,     0,     0,    96,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   759,
     126,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,     0,     0,   138,     0,     0,     0,
       0,   141,     0,    92,   322,     0,   144,     0,  1212,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,   126,   355,     0,     0,     0,   129,   130,
     131,     0,   853,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,   413,     0,     0,     0,   138,
       0,     0,     0,     0,   414,     0,     0,     0,     0,   144,
       0,   200,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,     0,     0,     0,   138,     0,     0,     0,     0,
     141,     0,    92,   227,     0,   144,     0,  1046,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   229,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   230,
       0,     0,   231,   355,     0,   232,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,    92,
     322,    47,     0,     0,    50,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   997,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     364,     0,     0,     0,   138,    92,   322,   270,     0,   141,
       0,    96,    97,    98,   144,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
     120,   121,   122,   123,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,     0,     0,
       0,   138,     0,     0,     0,     0,   141,     0,     0,     0,
       0,   144,     0,     0,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,   136,   137,    -4,    -4,     0,   138,     0,     0,
       0,     0,   141,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     6,
       0,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     9,    10,     0,    -4,    -4,     0,    11,    12,     0,
      13,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     7,     8,    52,    53,   937,     0,     0,    54,
       0,     0,     0,     0,    55,    56,    57,    58,     0,     0,
      59,     0,    60,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,    71,    72,     0,
     545,    18,    19,   546,    21,    22,   547,    24,   548,    26,
       0,    27,     0,     0,    30,    31,     0,    33,    34,    35,
       0,     0,     0,    38,     0,     0,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
      56,    57,    58,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,     0,     0,     0,     0,     0,  1177,     0,
    1178,     0,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,  1207,     0,  1208,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,  1298,     0,  1299,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,   786,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,   829,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,   847,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,   872,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,   954,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,  1175,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,  1234,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,  1235,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,  1236,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,  1237,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,  1270,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,  1314,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,  1320,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,  1321,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,  1338,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,  1341,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,  1344,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,  1365,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,  1368,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,  1398,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,     0,     0,  1400,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,  1402,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,     0,     0,  1415,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,   608,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,     0,  1246,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   533,     0,     0,     0,     0,   612,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   571,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   612,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,   613,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,   663,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   711,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   712,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   725,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,   726,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,   727,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   728,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   729,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   730,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,   814,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,   815,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   816,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,   916,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,   952,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,   953,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,   996,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,  1125,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,  1126,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,  1146,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,     0,     0,     0,  1280,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,  1281,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,  1287,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,     0,     0,     0,  1360,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,     0,     0,
       0,  1363,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,   537,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,     0,     0,   668,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
     675,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,     0,     0,   690,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,   692,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,     0,     0,   694,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,   696,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,     0,     0,   698,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,   700,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,     0,
       0,   702,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,   704,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,     0,     0,   706,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
     708,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,     0,     0,   710,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,   714,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,     0,     0,   716,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,   718,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,     0,     0,   720,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,   722,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,     0,
       0,   724,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,   837,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,     0,     0,   838,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
     842,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,     0,     0,   843,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,     0,     0,   845,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,     0,     0,   868,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
       0,     0,  1014,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,     0,     0,  1016,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,     0,     0,  1018,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,     0,
       0,  1020,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,     0,     0,  1021,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,     0,     0,  1139,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,     0,     0,
    1259,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,   533,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,   575,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,   579,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   580,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,   582,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,   584,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,   585,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,   588,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,   589,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
     659,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,   660,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,   661,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,   667,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   689,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,   691,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,   693,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,   695,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,   697,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,   699,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
     701,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,   703,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,   705,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,   707,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   709,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,   713,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,   715,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,   717,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,   719,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,   721,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
     723,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,   775,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,   780,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,   785,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   787,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,   788,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,   794,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,   801,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,   802,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,   803,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
     828,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,   830,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,   831,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,   832,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,   836,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355,     0,  1013,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
       0,     0,     0,     0,   355,     0,  1015,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     0,     0,     0,   355,     0,  1017,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,     0,     0,     0,     0,   355,     0,  1019,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     0,     0,     0,     0,   355,     0,  1024,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,     0,     0,     0,     0,   355,     0,
    1176,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     0,     0,     0,     0,   355,
       0,  1193,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     355,     0,  1211,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,     0,     0,     0,
       0,   355,     0,  1359,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,     0,     0,
       0,     0,   355,     0,  1413,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,     0,
       0,     0,     0,   355
};

static const yytype_int16 yycheck[] =
{
       6,  1103,   208,     6,     6,   406,   407,     5,     7,   327,
       3,     6,   330,   219,     6,     4,     6,   315,   316,   317,
       4,   319,   320,   321,     6,     6,     5,   150,     4,   752,
       4,     4,     4,     4,   157,     4,     4,   150,     5,   152,
       5,   140,   141,     6,     6,   140,   141,     6,     4,     6,
       6,   150,   258,     4,   260,     0,     4,    71,   157,    38,
      39,    40,    41,   158,     4,    44,    80,     4,   150,     6,
     823,   140,   141,    87,    88,   157,    56,    91,    92,   181,
     182,   183,   140,   141,   147,   148,     4,     5,   157,    95,
      50,    40,    41,    53,    43,   150,    56,   150,    58,   157,
       7,    93,   157,     4,   157,    13,    95,    96,    97,    98,
      50,    93,   214,    50,    54,   140,   141,     7,   150,  1221,
      38,    39,    40,    41,    64,   153,    44,    53,   156,   113,
      56,   156,    58,   158,   136,   137,   138,     6,     7,   141,
     142,   120,   121,  1245,   158,   140,   141,   137,    53,   150,
     152,    56,   145,    58,   156,   154,   137,   105,   106,   157,
     162,   163,   164,   165,     6,   167,   168,   169,   170,   158,
     172,   173,   174,   157,   150,   147,   148,   150,   827,   902,
     152,   157,   154,   157,   157,     6,   157,   159,   157,   157,
     157,   193,   157,   150,   157,   157,   152,   199,   200,   150,
     157,     6,   120,   121,   105,   106,   208,    53,   140,   141,
      56,   417,   140,   141,   150,     7,   152,   970,     6,   537,
     127,   128,   129,   130,   156,   152,   158,   151,   156,   147,
     148,   150,   156,   235,   236,   150,   154,   127,   128,   129,
     130,   150,   244,   245,   246,    71,   248,   196,   197,   251,
     252,   150,   254,   152,    80,   204,   462,   147,   148,   208,
    1362,    87,    88,   265,   154,    91,    92,   601,   602,   603,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,  1035,    71,   150,    50,   318,   150,    53,     7,
     150,    56,    80,     4,   147,   148,   328,   330,    60,    87,
      88,   154,  1434,    91,    92,   127,   128,   129,   130,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,     8,   147,   148,    56,   140,   141,
      56,    50,   364,     6,    53,   140,   141,    56,   370,    58,
     140,   141,    56,   375,   156,    58,   158,   675,   380,   381,
     382,   383,   157,     8,   151,   387,   156,   140,   141,   156,
     392,   393,   394,    74,    75,    76,    77,   151,   140,   141,
     158,    82,   156,   156,    85,   140,   141,   409,   410,   411,
     412,   413,   414,   406,   407,   150,   418,   419,   420,   421,
     422,    56,   157,   425,     6,     7,   428,   429,   140,   141,
     432,   433,   434,   435,   436,   437,   150,   735,   440,   127,
     128,   129,   130,   741,   156,   151,   448,    53,   151,    71,
     156,   453,   454,   156,     4,   404,   405,   151,    80,   147,
     148,    56,   156,   412,   762,    87,    88,   157,    56,    91,
      92,   151,   474,   476,    53,   477,   156,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   163,   142,   143,   144,   149,   168,   157,    53,   149,
     172,   150,    56,   152,   158,  1228,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       4,     4,     4,     5,   149,   156,    71,   158,   140,   141,
     532,   150,   538,   158,   537,    80,   158,   539,   140,   141,
     150,   150,    87,    88,   156,   150,    91,    92,   156,  1302,
     158,   150,  1305,   152,   156,  1308,    38,    39,    40,    41,
     147,   148,    44,     8,    71,   152,   568,   154,   570,   571,
      71,     6,   159,    80,   576,   577,   894,   895,   152,    80,
      87,    88,     4,   150,    91,    92,    87,    88,   590,     4,
      91,    92,   157,   595,   600,   601,   602,   603,   600,   601,
     602,   603,   140,   141,   150,  1254,   608,  1256,   150,  1258,
     612,   613,   156,   158,   158,   150,   618,   152,   156,   140,
     141,   140,   141,   150,   150,    71,   152,     7,   150,   631,
    1383,   633,   150,   150,    80,   156,     4,   156,   120,   121,
       5,    87,    88,   645,    54,    91,    92,   649,   650,   651,
     652,   158,     6,   150,   656,   152,   328,   158,   150,     6,
     152,   663,   611,   665,   666,  1418,     6,     5,  1421,   618,
     150,  1424,   675,   150,  1427,   624,   150,   150,   152,   152,
     150,     6,  1083,  1084,   140,   141,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     156,  1454,  1351,  1456,   149,  1458,   151,   157,   150,   711,
     712,   150,   158,   152,   140,   141,   150,   140,   141,   140,
     141,   150,   150,   725,   726,   727,   728,   729,   730,   731,
     156,   150,   734,   156,   150,   156,   146,   739,     4,   147,
     148,   150,     6,   745,   152,  1043,   154,   150,  1397,   157,
    1399,   159,  1401,   755,   756,   757,   758,   759,  1407,   157,
     432,   433,   434,   140,   141,   175,   157,   140,   141,   157,
     152,   181,   182,   183,   150,   150,   448,   152,   150,   156,
     152,    71,   192,   156,   150,   195,   152,   150,    12,    13,
      80,  1440,     6,  1442,   150,  1444,   152,    87,    88,   157,
     157,    91,    92,   152,   214,   215,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     769,   157,   140,   141,   149,   152,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   152,    61,   156,   841,
      64,    65,   845,    67,    68,    69,   140,   141,  1249,    73,
       5,   853,   262,   263,    71,   140,   141,   142,   143,   144,
       6,   154,   156,    80,   149,   814,   815,   816,   158,     5,
      87,    88,   874,   875,    91,    92,   100,   101,   102,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     5,   895,   140,   141,   149,   568,   150,   570,   152,
       6,   903,     6,   108,   150,   150,   152,   152,   150,   156,
     152,   150,     6,   152,   916,   917,   157,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   156,     6,   158,   158,   149,   608,    71,   156,     6,
     158,   158,   152,   156,   154,   158,    80,     4,   152,   951,
     952,   953,     6,    87,    88,   157,   149,    91,    92,   961,
     962,   156,   156,   158,   158,   154,   156,   969,   158,    56,
     156,    58,   158,   645,     7,   977,   163,   649,   650,   651,
     652,   168,   157,    71,   656,   172,   156,   156,   158,   158,
     152,   156,    80,   158,   996,   997,   998,   158,     7,    87,
      88,     6,  1005,    91,    92,  1007,   156,   156,   158,   158,
    1012,   156,   156,   158,   158,   156,   156,   158,   158,   150,
     969,  1027,     7,   156,   158,   158,  1028,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     7,   150,    71,  1046,   149,     7,  1049,   235,   236,
     150,   150,    80,  1055,  1056,   151,     6,  1263,  1060,    87,
      88,     7,   734,    91,    92,  1067,   156,   156,   158,   158,
     158,     7,   156,  1079,   158,  1077,     4,  1079,     6,   156,
     156,   158,   158,   755,   756,   757,   758,     6,     4,  1091,
    1083,  1084,   156,   105,   158,    71,     6,   157,   156,  1101,
     158,  1050,   157,  1105,    80,   156,  1108,   158,   156,   151,
     158,    87,    88,  1119,  1412,    91,    92,  1119,   156,   156,
     158,   158,   157,  1125,  1126,   535,   156,   156,   158,   158,
     158,   156,   156,   158,   158,   156,  1085,   158,  1087,   157,
    1089,   328,   157,   156,  1146,   158,  1352,   151,   156,  1447,
     158,  1449,  1101,   156,   151,  1104,  1105,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   156,   156,
     158,  1469,   149,   156,   156,  1177,   158,   364,   156,   151,
     158,   156,   158,   158,     6,     4,   596,     7,   153,     6,
       6,     4,     7,  1195,   108,  1197,     7,   607,     7,   108,
       7,     7,   108,     7,     7,  1207,     4,  1209,     7,     6,
    1212,   154,     6,   158,   158,  1217,   153,     7,     7,   154,
    1222,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   157,     6,   150,   150,   149,
     157,     6,     4,     6,  1246,   432,   433,   434,   153,     6,
       6,  1253,     7,  1255,   152,  1257,  1249,     6,   137,     7,
      56,   448,   672,     7,     7,  1267,    58,   454,     7,  1271,
       7,     7,     7,     6,   151,     7,   151,   151,  1280,  1281,
     151,     7,     7,     7,     6,  1287,     4,     4,   157,    12,
      13,     6,  1294,   150,     7,     6,  1298,     7,     7,     7,
       6,   157,     6,     6,  1253,   977,  1255,     6,  1257,    56,
       6,     4,     4,     4,   158,   150,  1265,     6,     4,  1268,
     157,     6,  1324,   151,   151,   154,     7,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,  1339,    61,     6,
    1342,    64,    65,  1345,    67,    68,    69,  1349,     6,   157,
      73,  1353,    64,  1355,     6,   157,   157,     6,  1360,     6,
       6,  1363,   157,   773,   774,     6,   776,     6,   778,   779,
       5,     4,   782,   783,     6,   157,     7,   100,   101,   102,
       7,   568,     7,   570,     7,     7,   157,     6,   152,   576,
     577,     6,   153,  1395,     6,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   157,   157,  1355,  1409,   149,     6,
     104,   157,     6,     6,   156,     6,   154,     4,     6,     4,
       6,   608,     6,     6,     6,     6,     6,     6,     6,     5,
     108,     6,  1438,     6,  1436,   158,     6,     6,     6,     6,
       6,     6,   156,     6,     6,   855,   856,   857,     6,     6,
     157,     6,   154,     7,     6,   865,     6,     5,   645,  1465,
       3,     4,   649,   650,   651,   652,     9,    10,    11,   656,
       6,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     6,    54,     6,     6,
     149,     6,   922,   157,     6,   157,     6,   157,   928,     7,
     158,   158,     6,   157,   934,   935,   936,   157,   157,   103,
     940,     6,   158,     6,   106,   945,   946,   947,     6,     6,
    1212,     6,     6,     6,   157,     6,     6,   734,     6,   157,
       6,   961,   158,     6,    71,   157,     6,     4,     6,   158,
       6,   971,     6,     6,     6,   975,     6,     6,   755,   756,
     757,   758,     6,     6,  1246,     6,   119,     6,     6,     6,
     157,   124,   125,   126,     6,     6,   157,     6,     6,     6,
       6,     6,     6,     6,     6,  1267,   157,   140,   141,     6,
       6,   157,   145,     6,   157,     6,   157,   150,   157,     6,
     153,   157,   155,   157,   157,   914,  1026,     3,     4,  1324,
     921,     3,     3,     9,    10,    11,   386,  1031,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1070,  1071,  1072,  1073,    50,    -1,    -1,    53,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1353,    68,  1355,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,     6,    -1,    -1,    82,    -1,    -1,    85,
      -1,    -1,    -1,  1113,    -1,    -1,    -1,    -1,    -1,    -1,
    1120,    -1,    -1,    -1,    -1,    -1,    -1,  1127,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,   119,    -1,    -1,   149,  1409,   124,   125,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1192,    -1,    -1,     3,     4,    -1,    -1,    -1,
     977,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    50,    -1,    -1,    53,   149,    -1,    56,    -1,
      58,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,  1262,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    82,    -1,     6,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    64,    65,    -1,    67,    68,    69,    -1,
    1310,   119,    73,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,  1105,    -1,
      -1,    -1,   140,   141,    -1,    -1,    -1,   145,    -1,   100,
     101,   102,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,
     158,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    -1,  1364,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    44,    -1,   158,    -1,    12,
      13,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
    1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1212,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,  1246,
     119,   120,   121,     6,    -1,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
    1267,   140,   141,    -1,    -1,    -1,   145,    -1,   147,   148,
      -1,   150,    -1,   152,    -1,   154,   155,    -1,   157,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1353,    68,  1355,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    -1,    -1,
      -1,    82,    -1,    -1,    85,    -1,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,  1395,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,  1409,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,   150,
      -1,     3,     4,     5,   155,    -1,   157,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    50,    -1,
      -1,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      82,    -1,    -1,    85,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    65,
      -1,    67,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,    -1,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,   150,    -1,
       3,     4,     5,   155,    -1,   157,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    12,    13,    50,    -1,    -1,
      53,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,    82,
      -1,    -1,    85,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,   124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,    -1,   140,   141,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,   150,    -1,     3,
       4,    -1,   155,    -1,   157,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    12,    13,    50,    -1,    -1,    53,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    82,    -1,
      -1,    85,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    64,    65,    -1,    67,
      68,    69,    -1,    -1,    -1,    73,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,    -1,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,   150,    -1,     3,     4,
      -1,   155,    -1,   157,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    56,    -1,    58,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   119,     6,    -1,    -1,   149,   124,
     125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,   150,    -1,     3,     4,    -1,
     155,    -1,   157,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    50,    -1,    -1,    53,   149,    -1,
      56,    -1,    58,    -1,    -1,     7,     8,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,     7,    -1,    -1,   149,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,   150,    -1,     3,     4,    -1,   155,
      -1,   157,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    50,    -1,    -1,    53,   149,    -1,    56,
      -1,    58,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   119,    -1,    -1,    -1,   149,   124,   125,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,   150,    -1,     3,     4,    -1,   155,    -1,
     157,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    50,    -1,    -1,    53,   149,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    -1,     3,     4,    82,    -1,    -1,    85,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,   150,    -1,     3,     4,     5,   155,    -1,   157,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    44,    -1,    -1,   119,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,   140,
     141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,    -1,   155,    -1,   157,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     8,
     119,   120,   121,    -1,    -1,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,   150,    -1,     3,     4,    -1,   155,    -1,   157,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   119,   149,    -1,    -1,    -1,   124,   125,
     126,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,
      -1,   157,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
     150,    -1,     3,     4,    -1,   155,    -1,   157,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    50,
      -1,    -1,    53,   149,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    -1,     3,
       4,    82,    -1,    -1,    85,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     8,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,    -1,    -1,    -1,   145,     3,     4,     5,    -1,   150,
      -1,     9,    10,    11,   155,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,   155,    -1,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,   120,   121,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,   140,   141,    12,    13,    -1,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     4,
      -1,    89,    90,    -1,    -1,    -1,    94,    12,    13,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    36,    37,    -1,   122,   123,    -1,    42,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    12,    13,    89,    90,    71,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,   123,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    64,    65,    -1,    67,    68,    69,
      -1,    -1,    -1,    73,    -1,    -1,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
     158,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,   158,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,   153,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     153,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,   153,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,   153,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,   153,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,   153,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     153,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,   153,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,   153,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,   153,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,   153,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     153,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,   153,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,   153,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,   153,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,   153,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,   153,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,   153,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
     153,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
     151,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
     151,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
     151,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
     151,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,   151,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,    -1,
     151,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,   149,
      -1,   151,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
     149,    -1,   151,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,   149,    -1,   151,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,   149,    -1,   151,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,   149
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   161,   162,     6,     0,     4,    12,    13,    36,
      37,    42,    43,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    94,    99,   100,   101,   102,   105,
     107,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   122,   123,   163,   165,   166,   184,   194,   199,   202,
     203,   204,   205,   206,   207,   208,   228,   229,   230,   231,
     232,   233,     3,     4,     5,     7,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      38,    39,    40,    41,    44,   113,   119,   120,   121,   124,
     125,   126,   127,   128,   129,   130,   140,   141,   145,   147,
     148,   150,   152,   154,   155,   157,   182,   183,   234,   235,
     247,    13,    56,   150,   150,     6,   157,     6,     6,     6,
       6,   152,   150,   157,   150,   150,     4,   150,   157,   150,
     150,     4,   157,   150,   150,    60,    56,    56,     6,    56,
      56,    53,    56,    58,    58,    50,    53,    56,    58,    53,
      56,    58,    53,    56,   150,    53,   157,   140,   141,   150,
     157,   236,   237,   236,   157,    50,    53,    56,   157,   236,
       4,    50,    54,    64,    56,    56,    53,     4,   113,   157,
       4,     6,    50,    53,    56,     4,     4,     4,     5,    35,
      50,    53,    56,    58,    68,   141,   157,   199,   208,   234,
     239,   240,   241,     4,   150,   150,   150,     4,   157,   243,
       4,   150,   150,     6,   152,     4,     4,     5,   157,     5,
     157,     6,   150,   157,     4,   152,   154,   159,   183,   157,
       5,   247,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   150,   150,   150,     7,   150,
     150,   150,     4,   234,   234,   234,   234,   153,   157,   234,
       4,   105,   106,     4,     4,   199,   200,   201,   239,     6,
       6,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   149,     6,     6,   234,     5,
       5,   234,   186,   234,   141,   234,   241,   242,   234,   234,
     150,   234,   242,   234,   234,   150,   242,   234,   234,   239,
     150,   157,   150,   150,   240,   240,   240,   150,   195,   196,
     197,   198,   150,   150,   150,   239,   234,     4,   239,   236,
     236,   236,   234,   234,   140,   141,   157,   157,   236,   157,
     157,   157,   140,   141,   150,   201,   236,   157,   150,   157,
     150,   150,   150,   240,   239,   150,     4,     6,   152,   152,
     201,     6,   157,   157,   157,   152,   152,   152,   152,     5,
     157,     5,     5,     5,    50,    53,    56,    58,   157,   234,
     241,   158,   242,     8,   142,     6,     6,   234,   234,   234,
     154,   234,   157,   108,   234,   234,   234,     6,     6,   201,
       6,   201,   239,   239,   152,   234,     4,   157,   167,     6,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,     4,   246,   247,   246,   246,   246,   234,   246,
     246,   246,   152,   151,     7,   182,   242,   153,     7,   182,
     183,   154,     7,   152,   158,    50,    53,    56,    58,   194,
       6,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,     6,   151,   156,   151,
     156,   156,   153,   156,   185,   151,   142,   156,   158,   151,
     151,   234,   151,   158,   151,   151,   234,   158,   151,   151,
       7,   234,   234,   234,   234,     7,     7,   226,   226,   234,
     150,   150,   150,   150,   234,   234,   234,     7,   157,   151,
       6,   156,   156,   156,   236,   236,   200,   200,   156,   234,
     234,   234,   234,   212,   156,   201,   234,   234,   234,   234,
     234,     7,   227,     7,   234,     6,   234,   234,   158,   242,
     242,   242,   234,   234,   153,   157,   234,     4,   234,   157,
     157,   157,   157,   242,   158,   234,   157,   234,   241,   151,
     151,   151,   105,   156,   201,   157,     8,   151,   153,   158,
     158,   151,   156,   158,   234,   153,   183,   234,     4,    95,
      96,    97,    98,   158,   170,   174,   177,   179,   180,   151,
     153,   151,   153,   151,   153,   151,   153,   151,   153,   151,
     153,   151,   153,   151,   153,   151,   153,   151,   153,   151,
     153,   156,   156,   151,   153,   151,   153,   151,   153,   151,
     153,   151,   153,   151,   153,   156,   156,   156,   156,   156,
     156,   152,   154,   151,   156,   156,   151,   151,     6,   156,
     151,   156,   239,   158,   154,   182,   183,   247,   234,     6,
       4,     4,   157,   244,   153,   157,   157,   157,   157,     8,
       6,   137,   164,   242,     6,   242,   234,     6,     4,     7,
     234,   241,   108,     7,     7,   151,     7,   108,     7,     7,
     151,   108,     7,     7,   234,   151,   158,   151,   151,   234,
     239,     4,   225,     6,   151,   191,   234,   247,   191,   191,
     191,   151,   151,   151,   239,   242,   154,   236,   234,   234,
     158,   158,   234,   236,   156,   156,   156,    71,    80,    87,
      88,    91,    92,   222,   223,   236,   158,   209,   151,   158,
     151,   151,   151,   234,     6,   234,   151,   153,   153,   158,
     158,   158,   153,   153,   242,   153,   153,   158,   242,   242,
     242,   242,   158,     8,   242,     7,     7,     7,   154,   234,
     158,   234,   234,     7,   154,   157,   239,     6,   153,   154,
     183,   246,   158,   171,   150,   150,   157,   181,     6,   234,
     234,   234,   234,   234,   234,   234,   234,   234,     4,   242,
     246,   234,   246,     6,   153,     4,   105,   106,   234,     6,
       6,     6,     7,   152,   243,   245,     6,   242,   242,   242,
     242,   234,   137,   246,   151,   151,   156,     7,   236,    56,
     239,   239,     7,   239,    56,    58,   239,   239,     7,    58,
     239,   239,     6,     7,     7,     7,     7,    71,   224,     6,
       7,   151,   151,   151,   151,     7,     7,     7,     6,   158,
       4,   156,   156,   156,   158,   158,   236,   236,   236,     4,
       6,   157,   150,     6,    93,     6,    93,   158,   223,   156,
     222,     7,     6,     7,     7,     7,     6,   157,     6,     6,
       6,    56,   234,     6,     6,   158,   158,   158,   158,   158,
     234,   158,   239,   239,   239,     4,   156,     8,     8,   151,
       4,     4,   239,   158,     6,     4,     6,   150,   234,   234,
     238,   239,   157,   151,   153,   151,   153,   151,   153,   151,
     153,   153,   151,   151,   151,   151,   182,     7,   182,   183,
     154,     7,     6,   243,   234,   156,   158,   158,   158,   158,
     158,     6,     6,   164,     6,   234,   157,   234,     6,   157,
      64,   193,   193,   239,     6,   157,   157,     6,     6,   239,
     157,     6,     6,     5,   239,   239,   239,     4,     6,   239,
       7,     7,     7,     7,   239,   239,   239,     7,     6,     7,
     234,   234,   234,   157,   157,   156,   158,   156,   158,   156,
     158,   152,   234,   239,   234,     6,     6,   234,   236,   158,
       5,   157,   239,   157,   157,   157,   239,   242,   157,     6,
     153,     6,     6,   104,   234,   234,   234,     6,     6,     7,
     156,     6,   183,   168,   234,   156,   156,   156,   158,   169,
     234,   154,   239,   247,   234,     6,     4,   244,     6,   153,
     243,     6,     6,     6,     6,   246,   156,   234,   234,   236,
       6,     6,     6,   234,   234,     6,   234,     5,     6,     6,
     108,   192,   234,     6,   239,   239,   239,   239,     6,     4,
       6,     6,   234,   234,   247,   158,   151,   156,   158,   200,
     200,   236,     6,   213,   236,     6,   214,   236,     6,   215,
     234,   158,   156,   151,   158,   156,     6,   141,   236,     6,
     238,   236,   236,     6,   158,   234,   239,   156,   158,     8,
     158,   151,   157,   234,   247,   239,   151,   156,   234,   234,
     239,   157,   156,   158,     4,     6,     6,     6,     7,     6,
     154,     6,   234,   187,   158,   158,   158,   158,     5,    54,
       6,     6,     6,     6,     6,   157,   157,     6,     6,   157,
     234,   158,   158,   156,   157,   156,   157,   156,   157,   153,
       6,   239,     7,   157,   234,   156,   158,   156,   156,     6,
     158,   103,   234,   234,   242,     6,     6,   158,   172,   234,
     156,   156,   238,   234,     6,   243,   106,   156,   189,     6,
       6,     6,     6,     6,   157,   238,   242,   200,   156,   158,
     234,   236,   222,   234,   236,   222,   234,   236,   222,     6,
     156,   158,   239,   201,   158,   236,     6,   242,   236,   234,
     158,   158,   158,     6,   157,   234,   234,   158,     6,   234,
     156,   158,   190,   234,   158,   158,   158,   234,   158,   156,
     158,   158,   156,   158,   158,   156,   158,   239,     6,    71,
     158,   210,   157,   156,   158,   156,     6,     6,   169,   151,
     156,     6,   157,   156,     4,   158,     6,     6,   158,     6,
     216,   234,     6,     6,   217,   234,     6,     6,   218,   234,
       6,   158,   234,   222,   201,   242,     6,   236,   242,   158,
     175,   234,   238,   234,     5,   157,   239,   157,   158,   157,
     158,   157,   158,     6,     6,   158,   158,   211,   158,   156,
     158,     6,   157,   151,   158,   158,   188,   234,   222,     6,
     219,   222,     6,   220,   222,     6,   221,   222,     6,   242,
       6,   173,   246,   178,   157,     6,   156,   158,     7,   158,
     157,   158,   157,   158,   157,   158,   158,   156,   158,   157,
     238,   234,   247,     6,   222,     6,   222,     6,   222,     6,
     246,     6,   176,   246,   158,     7,   158,   158,   158,   156,
     158,     6,   247,     6,     6,     6,   246,     6
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
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2648 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2655 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2661 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2666 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2672 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 2676 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 2680 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2690 "Gmsh.y"
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

  case 195:

/* Line 1464 of yacc.c  */
#line 2707 "Gmsh.y"
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

  case 196:

/* Line 1464 of yacc.c  */
#line 2724 "Gmsh.y"
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

  case 197:

/* Line 1464 of yacc.c  */
#line 2745 "Gmsh.y"
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

  case 198:

/* Line 1464 of yacc.c  */
#line 2766 "Gmsh.y"
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

  case 199:

/* Line 1464 of yacc.c  */
#line 2801 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2809 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2815 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2822 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2826 "Gmsh.y"
    {
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2835 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2843 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2851 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2859 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2864 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2872 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2877 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2885 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2890 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2898 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2903 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2911 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2918 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2925 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2932 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2939 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2946 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2953 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2960 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2967 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2974 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2986 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2991 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2998 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3010 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3022 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3027 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3034 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3039 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3046 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3051 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3058 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3063 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3070 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3075 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3086 "Gmsh.y"
    {
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3089 "Gmsh.y"
    {
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3095 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3104 "Gmsh.y"
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

  case 246:

/* Line 1464 of yacc.c  */
#line 3124 "Gmsh.y"
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

  case 247:

/* Line 1464 of yacc.c  */
#line 3147 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3151 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3155 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3159 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3167 "Gmsh.y"
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

  case 253:

/* Line 1464 of yacc.c  */
#line 3186 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3202 "Gmsh.y"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 3217 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3221 "Gmsh.y"
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

  case 258:

/* Line 1464 of yacc.c  */
#line 3233 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3237 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3242 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3246 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3253 "Gmsh.y"
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

  case 263:

/* Line 1464 of yacc.c  */
#line 3309 "Gmsh.y"
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

  case 264:

/* Line 1464 of yacc.c  */
#line 3379 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 3384 "Gmsh.y"
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

  case 266:

/* Line 1464 of yacc.c  */
#line 3451 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3487 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3496 "Gmsh.y"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 3539 "Gmsh.y"
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

  case 270:

/* Line 1464 of yacc.c  */
#line 3564 "Gmsh.y"
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

  case 271:

/* Line 1464 of yacc.c  */
#line 3592 "Gmsh.y"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 3635 "Gmsh.y"
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

  case 273:

/* Line 1464 of yacc.c  */
#line 3658 "Gmsh.y"
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

  case 274:

/* Line 1464 of yacc.c  */
#line 3681 "Gmsh.y"
    {
    ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3684 "Gmsh.y"
    {
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3693 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3697 "Gmsh.y"
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

  case 278:

/* Line 1464 of yacc.c  */
#line 3707 "Gmsh.y"
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

  case 279:

/* Line 1464 of yacc.c  */
#line 3741 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3742 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3747 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3754 "Gmsh.y"
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

  case 283:

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
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3786 "Gmsh.y"
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

  case 285:

/* Line 1464 of yacc.c  */
#line 3813 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3814 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3815 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3816 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3817 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3818 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3819 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3820 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3822 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3828 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3829 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3830 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3831 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3832 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3833 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3834 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3835 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3836 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3837 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3838 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3839 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3840 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3841 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3842 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3843 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3844 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3845 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3846 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3847 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3848 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3849 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3850 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3851 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3852 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3853 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3854 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3855 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3856 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3857 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3858 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3861 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3862 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3863 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3864 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3865 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3866 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3867 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3868 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3869 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3870 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3871 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3872 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3873 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3874 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3875 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3876 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3877 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3878 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3879 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3880 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3881 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3890 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3891 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3892 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3893 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3894 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3895 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3896 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3901 "Gmsh.y"
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

  case 355:

/* Line 1464 of yacc.c  */
#line 3921 "Gmsh.y"
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

  case 356:

/* Line 1464 of yacc.c  */
#line 3940 "Gmsh.y"
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

  case 357:

/* Line 1464 of yacc.c  */
#line 3958 "Gmsh.y"
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

  case 358:

/* Line 1464 of yacc.c  */
#line 3970 "Gmsh.y"
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

  case 359:

/* Line 1464 of yacc.c  */
#line 3987 "Gmsh.y"
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

  case 360:

/* Line 1464 of yacc.c  */
#line 4008 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4013 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4018 "Gmsh.y"
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

  case 363:

/* Line 1464 of yacc.c  */
#line 4028 "Gmsh.y"
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

  case 364:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4046 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4054 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4062 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4073 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4077 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4081 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4088 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4093 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4100 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4105 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4109 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4114 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4118 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4126 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4137 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4141 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4153 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4161 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4169 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4176 "Gmsh.y"
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

  case 388:

/* Line 1464 of yacc.c  */
#line 4187 "Gmsh.y"
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

  case 389:

/* Line 1464 of yacc.c  */
#line 4207 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4211 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4215 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4219 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4223 "Gmsh.y"
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

  case 394:

/* Line 1464 of yacc.c  */
#line 4241 "Gmsh.y"
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

  case 395:

/* Line 1464 of yacc.c  */
#line 4259 "Gmsh.y"
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

  case 396:

/* Line 1464 of yacc.c  */
#line 4277 "Gmsh.y"
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

  case 397:

/* Line 1464 of yacc.c  */
#line 4295 "Gmsh.y"
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

  case 398:

/* Line 1464 of yacc.c  */
#line 4305 "Gmsh.y"
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
#line 4315 "Gmsh.y"
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

  case 400:

/* Line 1464 of yacc.c  */
#line 4327 "Gmsh.y"
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

  case 401:

/* Line 1464 of yacc.c  */
#line 4339 "Gmsh.y"
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

  case 402:

/* Line 1464 of yacc.c  */
#line 4360 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4365 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4369 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4373 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4385 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4389 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4401 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4408 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4418 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4422 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4437 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 4442 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 4449 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4453 "Gmsh.y"
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

  case 416:

/* Line 1464 of yacc.c  */
#line 4466 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 4474 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 4485 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4489 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4497 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4505 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4513 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4521 "Gmsh.y"
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

  case 424:

/* Line 1464 of yacc.c  */
#line 4535 "Gmsh.y"
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

  case 425:

/* Line 1464 of yacc.c  */
#line 4549 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 4553 "Gmsh.y"
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
#line 10262 "Gmsh.tab.cpp"
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
#line 4573 "Gmsh.y"


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

