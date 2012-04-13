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


/* Line 189 of yacc.c  */
#line 166 "Gmsh.tab.cpp"

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
#line 86 "Gmsh.y"

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
#define YYLAST   7456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  415
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1428

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
     448,   449,   451,   452,   456,   462,   463,   473,   474,   477,
     481,   485,   487,   489,   490,   496,   497,   500,   508,   509,
     519,   526,   534,   539,   547,   556,   565,   573,   581,   593,
     602,   611,   612,   622,   631,   641,   645,   650,   661,   669,
     677,   686,   695,   708,   709,   719,   728,   736,   745,   746,
     756,   762,   774,   780,   790,   795,   805,   815,   817,   819,
     820,   823,   830,   837,   844,   851,   860,   871,   886,   903,
     916,   925,   934,   941,   956,   961,   968,   975,   979,   984,
     990,   994,   998,  1003,  1008,  1012,  1020,  1028,  1032,  1040,
    1044,  1047,  1050,  1053,  1069,  1072,  1075,  1078,  1081,  1088,
    1097,  1106,  1117,  1119,  1122,  1124,  1128,  1133,  1135,  1141,
    1153,  1167,  1168,  1176,  1177,  1191,  1192,  1208,  1209,  1216,
    1225,  1234,  1243,  1256,  1269,  1282,  1297,  1312,  1327,  1328,
    1341,  1342,  1355,  1356,  1369,  1370,  1387,  1388,  1405,  1406,
    1423,  1424,  1443,  1444,  1463,  1464,  1483,  1485,  1488,  1494,
    1502,  1512,  1515,  1518,  1522,  1525,  1529,  1539,  1546,  1547,
    1551,  1552,  1554,  1555,  1558,  1559,  1562,  1570,  1577,  1586,
    1592,  1596,  1604,  1610,  1617,  1624,  1637,  1648,  1659,  1670,
    1681,  1684,  1688,  1695,  1697,  1699,  1702,  1708,  1716,  1718,
    1722,  1725,  1728,  1731,  1735,  1739,  1743,  1747,  1751,  1755,
    1759,  1763,  1767,  1771,  1775,  1779,  1783,  1787,  1793,  1798,
    1803,  1808,  1813,  1818,  1823,  1828,  1833,  1838,  1843,  1850,
    1855,  1860,  1865,  1870,  1875,  1880,  1887,  1894,  1901,  1906,
    1911,  1916,  1921,  1926,  1931,  1936,  1941,  1946,  1951,  1956,
    1963,  1968,  1973,  1978,  1983,  1988,  1993,  2000,  2007,  2014,
    2019,  2021,  2023,  2025,  2027,  2029,  2031,  2033,  2035,  2041,
    2046,  2051,  2054,  2060,  2064,  2071,  2076,  2084,  2091,  2093,
    2096,  2099,  2103,  2107,  2119,  2129,  2137,  2145,  2147,  2151,
    2153,  2155,  2158,  2162,  2167,  2173,  2175,  2177,  2180,  2184,
    2188,  2194,  2199,  2202,  2205,  2208,  2211,  2213,  2215,  2219,
    2224,  2231,  2233,  2235,  2239,  2243,  2253,  2261,  2263,  2269,
    2273,  2280,  2282,  2286,  2288,  2290,  2294,  2301,  2303,  2305,
    2310,  2317,  2324,  2329,  2334,  2339
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,   161,    -1,     1,     6,    -1,    -1,   161,
     162,    -1,   165,    -1,   164,    -1,   183,    -1,   192,    -1,
     197,    -1,   201,    -1,   202,    -1,   203,    -1,   206,    -1,
     226,    -1,   227,    -1,   228,    -1,   229,    -1,   205,    -1,
     204,    -1,   200,    -1,   231,    -1,   136,    -1,   136,   136,
      -1,    36,   149,     5,   150,     6,    -1,    36,   149,     5,
     150,   163,   244,     6,    -1,    36,   149,     5,   155,   240,
     150,     6,    -1,    36,   149,     5,   155,   240,   150,   163,
     244,     6,    -1,     4,     5,   156,   166,   157,     6,    -1,
      88,     4,   151,   232,   152,     6,    -1,    89,     4,   151,
     232,   152,     6,    -1,    -1,   166,   169,    -1,   166,   173,
      -1,   166,   176,    -1,   166,   178,    -1,   166,   179,    -1,
     232,    -1,   167,   155,   232,    -1,   232,    -1,   168,   155,
     232,    -1,    -1,    -1,     4,   170,   149,   167,   150,   171,
     156,   168,   157,     6,    -1,   244,    -1,   172,   155,   244,
      -1,    -1,    94,   149,   232,   155,   232,   155,   232,   150,
     174,   156,   172,   157,     6,    -1,   244,    -1,   175,   155,
     244,    -1,    -1,    95,   149,   232,   155,   232,   155,   232,
     155,   232,   150,   177,   156,   175,   157,     6,    -1,    96,
     156,   236,   157,   156,   236,   157,     6,    -1,    96,   156,
     236,   157,   156,   236,   157,   156,   236,   157,   156,   236,
     157,     6,    -1,    -1,    97,   180,   156,   168,   157,     6,
      -1,     7,    -1,   129,    -1,   128,    -1,   127,    -1,   126,
      -1,   147,    -1,   146,    -1,    48,   151,   185,   152,     6,
      -1,     4,   181,   237,     6,    -1,     4,   151,   152,   181,
     237,     6,    -1,     4,   151,   232,   152,   181,   232,     6,
      -1,     4,   151,   156,   240,   157,   152,   181,   237,     6,
      -1,     4,   182,     6,    -1,     4,   151,   232,   152,   182,
       6,    -1,     4,     7,   245,     6,    -1,     4,   153,     4,
       7,   245,     6,    -1,     4,   151,   232,   152,   153,     4,
       7,   245,     6,    -1,     4,   153,     4,   181,   232,     6,
      -1,     4,   151,   232,   152,   153,     4,   181,   232,     6,
      -1,     4,   153,     4,   182,     6,    -1,     4,   151,   232,
     152,   153,     4,   182,     6,    -1,     4,   153,   104,   153,
       4,     7,   241,     6,    -1,     4,   151,   232,   152,   153,
     104,   153,     4,     7,   241,     6,    -1,     4,   153,   105,
       7,   242,     6,    -1,     4,   151,   232,   152,   153,   105,
       7,   242,     6,    -1,     4,   112,     7,   232,     6,    -1,
     112,   151,   232,   152,     7,     4,     6,    -1,   112,   151,
     232,   152,   153,     4,     7,   232,     6,    -1,   112,   151,
     232,   152,   153,     4,     7,   245,     6,    -1,   112,   151,
     232,   152,   153,     4,     7,   156,   240,   157,     6,    -1,
     112,   151,   232,   152,   153,     4,     6,    -1,    71,   149,
       4,   150,   153,     4,     7,   232,     6,    -1,    71,   149,
       4,   150,   153,     4,     7,   245,     6,    -1,    -1,   155,
      -1,    -1,   185,   184,     4,    -1,   185,   184,     4,     7,
     232,    -1,    -1,   185,   184,     4,     7,   156,   232,   186,
     187,   157,    -1,    -1,   187,   188,    -1,   155,     4,   237,
      -1,   155,     4,     5,    -1,   232,    -1,   245,    -1,    -1,
     107,    53,   156,   232,   157,    -1,    -1,    63,   234,    -1,
      49,   149,   232,   150,     7,   234,     6,    -1,    -1,    67,
      49,   193,   149,   189,   150,     7,   237,     6,    -1,    58,
      59,   237,     7,   232,     6,    -1,    52,   149,   232,   150,
       7,   237,     6,    -1,    72,    52,   237,     6,    -1,    56,
     149,   232,   150,     7,   237,     6,    -1,    50,   149,   232,
     150,     7,   237,   191,     6,    -1,    51,   149,   232,   150,
       7,   237,   191,     6,    -1,    99,   149,   232,   150,     7,
     237,     6,    -1,   100,   149,   232,   150,     7,   237,     6,
      -1,   101,   149,   232,   150,     7,   237,   103,   237,   102,
     232,     6,    -1,    52,     4,   149,   232,   150,     7,   237,
       6,    -1,    68,    52,   149,   232,   150,     7,   237,     6,
      -1,    -1,    67,    52,   194,   149,   189,   150,     7,   237,
       6,    -1,    63,    55,   149,   232,   150,     7,   237,     6,
      -1,    64,    55,   149,   232,   150,     7,   237,   190,     6,
      -1,    12,    13,     6,    -1,    13,    55,   232,     6,    -1,
      60,    55,   149,   232,   150,     7,     5,     5,     5,     6,
      -1,    53,   149,   232,   150,     7,   237,     6,    -1,    54,
     149,   232,   150,     7,   237,     6,    -1,    55,     4,   149,
     232,   150,     7,   237,     6,    -1,    68,    55,   149,   232,
     150,     7,   237,     6,    -1,    68,    55,   149,   232,   150,
       7,   237,     4,   156,   236,   157,     6,    -1,    -1,    67,
      55,   195,   149,   189,   150,     7,   237,     6,    -1,    66,
      57,   149,   232,   150,     7,   237,     6,    -1,    57,   149,
     232,   150,     7,   237,     6,    -1,    68,    57,   149,   232,
     150,     7,   237,     6,    -1,    -1,    67,    57,   196,   149,
     189,   150,     7,   237,     6,    -1,    74,   234,   156,   198,
     157,    -1,    73,   156,   234,   155,   234,   155,   232,   157,
     156,   198,   157,    -1,    75,   234,   156,   198,   157,    -1,
      76,   156,   234,   155,   232,   157,   156,   198,   157,    -1,
       4,   156,   198,   157,    -1,    84,    52,   156,   240,   157,
      55,   156,   232,   157,    -1,    81,    52,   149,   232,   150,
     156,   240,   157,     6,    -1,   199,    -1,   197,    -1,    -1,
     199,   192,    -1,   199,    49,   156,   240,   157,     6,    -1,
     199,    52,   156,   240,   157,     6,    -1,   199,    55,   156,
     240,   157,     6,    -1,   199,    57,   156,   240,   157,     6,
      -1,    78,    63,   149,   232,   150,     7,   237,     6,    -1,
      78,    49,   149,   232,   150,     7,   156,   236,   157,     6,
      -1,    78,    63,   149,   232,   150,     7,   156,   234,   155,
     234,   155,   240,   157,     6,    -1,    78,    63,   149,   232,
     150,     7,   156,   234,   155,   234,   155,   234,   155,   240,
     157,     6,    -1,    78,    53,   149,   232,   150,     7,   156,
     234,   155,   240,   157,     6,    -1,    78,     4,   149,   232,
     150,     7,   237,     6,    -1,    78,     4,   149,   232,   150,
       7,     5,     6,    -1,    78,     4,   156,   232,   157,     6,
      -1,    78,     4,   149,   232,   150,     7,   156,   234,   155,
     234,   155,   240,   157,     6,    -1,    82,   156,   199,   157,
      -1,    82,   112,   151,   232,   152,     6,    -1,    82,     4,
     151,   232,   152,     6,    -1,    82,     4,     6,    -1,    82,
       4,     4,     6,    -1,   104,   241,   156,   199,   157,    -1,
     116,     5,     6,    -1,   117,     5,     6,    -1,   116,   156,
     199,   157,    -1,   117,   156,   199,   157,    -1,     4,   245,
       6,    -1,     4,     4,   151,   232,   152,   244,     6,    -1,
       4,     4,     4,   151,   232,   152,     6,    -1,     4,   232,
       6,    -1,    71,   149,     4,   150,   153,     4,     6,    -1,
      98,     4,     6,    -1,   111,     6,    -1,    44,     6,    -1,
      41,     6,    -1,    41,   156,   232,   155,   232,   155,   232,
     155,   232,   155,   232,   155,   232,   157,     6,    -1,    42,
       6,    -1,    45,     6,    -1,    46,     6,    -1,    62,     6,
      -1,   106,   149,   232,     8,   232,   150,    -1,   106,   149,
     232,     8,   232,     8,   232,   150,    -1,   106,     4,   107,
     156,   232,     8,   232,   157,    -1,   106,     4,   107,   156,
     232,     8,   232,     8,   232,   157,    -1,   108,    -1,   115,
       4,    -1,   113,    -1,   114,     4,     6,    -1,   109,   149,
     232,   150,    -1,   110,    -1,    77,   234,   156,   199,   157,
      -1,    77,   156,   234,   155,   234,   155,   232,   157,   156,
     199,   157,    -1,    77,   156,   234,   155,   234,   155,   234,
     155,   232,   157,   156,   199,   157,    -1,    -1,    77,   234,
     156,   199,   207,   220,   157,    -1,    -1,    77,   156,   234,
     155,   234,   155,   232,   157,   156,   199,   208,   220,   157,
      -1,    -1,    77,   156,   234,   155,   234,   155,   234,   155,
     232,   157,   156,   199,   209,   220,   157,    -1,    -1,    77,
     156,   199,   210,   220,   157,    -1,    77,    49,   156,   232,
     155,   234,   157,     6,    -1,    77,    52,   156,   232,   155,
     234,   157,     6,    -1,    77,    55,   156,   232,   155,   234,
     157,     6,    -1,    77,    49,   156,   232,   155,   234,   155,
     234,   155,   232,   157,     6,    -1,    77,    52,   156,   232,
     155,   234,   155,   234,   155,   232,   157,     6,    -1,    77,
      55,   156,   232,   155,   234,   155,   234,   155,   232,   157,
       6,    -1,    77,    49,   156,   232,   155,   234,   155,   234,
     155,   234,   155,   232,   157,     6,    -1,    77,    52,   156,
     232,   155,   234,   155,   234,   155,   234,   155,   232,   157,
       6,    -1,    77,    55,   156,   232,   155,   234,   155,   234,
     155,   234,   155,   232,   157,     6,    -1,    -1,    77,    49,
     156,   232,   155,   234,   157,   211,   156,   220,   157,     6,
      -1,    -1,    77,    52,   156,   232,   155,   234,   157,   212,
     156,   220,   157,     6,    -1,    -1,    77,    55,   156,   232,
     155,   234,   157,   213,   156,   220,   157,     6,    -1,    -1,
      77,    49,   156,   232,   155,   234,   155,   234,   155,   232,
     157,   214,   156,   220,   157,     6,    -1,    -1,    77,    52,
     156,   232,   155,   234,   155,   234,   155,   232,   157,   215,
     156,   220,   157,     6,    -1,    -1,    77,    55,   156,   232,
     155,   234,   155,   234,   155,   232,   157,   216,   156,   220,
     157,     6,    -1,    -1,    77,    49,   156,   232,   155,   234,
     155,   234,   155,   234,   155,   232,   157,   217,   156,   220,
     157,     6,    -1,    -1,    77,    52,   156,   232,   155,   234,
     155,   234,   155,   234,   155,   232,   157,   218,   156,   220,
     157,     6,    -1,    -1,    77,    55,   156,   232,   155,   234,
     155,   234,   155,   234,   155,   232,   157,   219,   156,   220,
     157,     6,    -1,   221,    -1,   220,   221,    -1,    86,   156,
     232,   157,     6,    -1,    86,   156,   237,   155,   237,   157,
       6,    -1,    86,   156,   237,   155,   237,   155,   237,   157,
       6,    -1,    79,     6,    -1,    90,     6,    -1,    90,    92,
       6,    -1,    91,     6,    -1,    91,    92,     6,    -1,    87,
     149,   232,   150,     7,   237,    70,   232,     6,    -1,    70,
       4,   151,   232,   152,     6,    -1,    -1,    70,     4,   232,
      -1,    -1,     4,    -1,    -1,     7,   237,    -1,    -1,     7,
     232,    -1,    65,    52,   238,     7,   232,   222,     6,    -1,
      65,    55,   238,   224,   223,     6,    -1,    61,    55,   156,
     232,   157,     7,   237,     6,    -1,    65,    57,   238,   224,
       6,    -1,    93,   238,     6,    -1,    85,    55,   156,   240,
     157,   232,     6,    -1,    79,    55,   238,   225,     6,    -1,
      80,    55,   237,     7,   232,     6,    -1,    69,    52,   237,
       7,   237,     6,    -1,    69,    55,   232,   156,   240,   157,
       7,   232,   156,   240,   157,     6,    -1,    49,   156,   240,
     157,   107,    55,   156,   232,   157,     6,    -1,    52,   156,
     240,   157,   107,    55,   156,   232,   157,     6,    -1,    52,
     156,   240,   157,   107,    57,   156,   232,   157,     6,    -1,
      55,   156,   240,   157,   107,    57,   156,   232,   157,     6,
      -1,    83,     6,    -1,    83,     4,     6,    -1,    83,    49,
     156,   240,   157,     6,    -1,   121,    -1,   122,    -1,   230,
       6,    -1,   230,   156,   237,   157,     6,    -1,   230,   156,
     237,   155,   237,   157,     6,    -1,   233,    -1,   149,   232,
     150,    -1,   140,   232,    -1,   139,   232,    -1,   144,   232,
      -1,   232,   140,   232,    -1,   232,   139,   232,    -1,   232,
     141,   232,    -1,   232,   142,   232,    -1,   232,   143,   232,
      -1,   232,   148,   232,    -1,   232,   135,   232,    -1,   232,
     136,   232,    -1,   232,   138,   232,    -1,   232,   137,   232,
      -1,   232,   134,   232,    -1,   232,   133,   232,    -1,   232,
     132,   232,    -1,   232,   131,   232,    -1,   232,   130,   232,
       8,   232,    -1,    14,   149,   232,   150,    -1,    15,   149,
     232,   150,    -1,    16,   149,   232,   150,    -1,    17,   149,
     232,   150,    -1,    18,   149,   232,   150,    -1,    19,   149,
     232,   150,    -1,    20,   149,   232,   150,    -1,    21,   149,
     232,   150,    -1,    22,   149,   232,   150,    -1,    24,   149,
     232,   150,    -1,    25,   149,   232,   155,   232,   150,    -1,
      26,   149,   232,   150,    -1,    27,   149,   232,   150,    -1,
      28,   149,   232,   150,    -1,    29,   149,   232,   150,    -1,
      30,   149,   232,   150,    -1,    31,   149,   232,   150,    -1,
      32,   149,   232,   155,   232,   150,    -1,    33,   149,   232,
     155,   232,   150,    -1,    34,   149,   232,   155,   232,   150,
      -1,    23,   149,   232,   150,    -1,    14,   151,   232,   152,
      -1,    15,   151,   232,   152,    -1,    16,   151,   232,   152,
      -1,    17,   151,   232,   152,    -1,    18,   151,   232,   152,
      -1,    19,   151,   232,   152,    -1,    20,   151,   232,   152,
      -1,    21,   151,   232,   152,    -1,    22,   151,   232,   152,
      -1,    24,   151,   232,   152,    -1,    25,   151,   232,   155,
     232,   152,    -1,    26,   151,   232,   152,    -1,    27,   151,
     232,   152,    -1,    28,   151,   232,   152,    -1,    29,   151,
     232,   152,    -1,    30,   151,   232,   152,    -1,    31,   151,
     232,   152,    -1,    32,   151,   232,   155,   232,   152,    -1,
      33,   151,   232,   155,   232,   152,    -1,    34,   151,   232,
     155,   232,   152,    -1,    23,   151,   232,   152,    -1,     3,
      -1,     9,    -1,    10,    -1,    11,    -1,   123,    -1,   124,
      -1,   125,    -1,     4,    -1,     4,   158,   156,   232,   157,
      -1,     4,   151,   232,   152,    -1,   154,     4,   151,   152,
      -1,     4,   182,    -1,     4,   151,   232,   152,   182,    -1,
       4,   153,     4,    -1,     4,   151,   232,   152,   153,     4,
      -1,     4,   153,     4,   182,    -1,     4,   151,   232,   152,
     153,     4,   182,    -1,   118,   149,   244,   155,   232,   150,
      -1,   235,    -1,   140,   234,    -1,   139,   234,    -1,   234,
     140,   234,    -1,   234,   139,   234,    -1,   156,   232,   155,
     232,   155,   232,   155,   232,   155,   232,   157,    -1,   156,
     232,   155,   232,   155,   232,   155,   232,   157,    -1,   156,
     232,   155,   232,   155,   232,   157,    -1,   149,   232,   155,
     232,   155,   232,   150,    -1,   237,    -1,   236,   155,   237,
      -1,   232,    -1,   239,    -1,   156,   157,    -1,   156,   240,
     157,    -1,   140,   156,   240,   157,    -1,   232,   141,   156,
     240,   157,    -1,   237,    -1,     5,    -1,   140,   239,    -1,
     232,   141,   239,    -1,   232,     8,   232,    -1,   232,     8,
     232,     8,   232,    -1,    49,   156,   232,   157,    -1,    49,
       5,    -1,    52,     5,    -1,    55,     5,    -1,    57,     5,
      -1,   197,    -1,   206,    -1,     4,   151,   152,    -1,    35,
     151,     4,   152,    -1,     4,   151,   156,   240,   157,   152,
      -1,   232,    -1,   239,    -1,   240,   155,   232,    -1,   240,
     155,   239,    -1,   156,   232,   155,   232,   155,   232,   155,
     232,   157,    -1,   156,   232,   155,   232,   155,   232,   157,
      -1,     4,    -1,     4,   153,   104,   153,     4,    -1,   156,
     243,   157,    -1,     4,   151,   232,   152,   153,   105,    -1,
     241,    -1,   243,   155,   241,    -1,   245,    -1,     4,    -1,
       4,   153,     4,    -1,     4,   151,   232,   152,   153,     4,
      -1,     5,    -1,    43,    -1,   119,   149,   244,   150,    -1,
     120,   149,   244,   155,   244,   150,    -1,    38,   149,   244,
     155,   244,   150,    -1,    39,   149,   244,   150,    -1,    40,
     149,   244,   150,    -1,    37,   149,   244,   150,    -1,    37,
     149,   244,   155,   240,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   158,   163,   165,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   189,   193,   200,   205,   219,   232,   260,
     274,   285,   300,   305,   306,   307,   308,   309,   313,   315,
     320,   322,   328,   432,   327,   450,   457,   468,   467,   485,
     492,   503,   502,   519,   536,   559,   558,   572,   573,   574,
     575,   576,   580,   581,   587,   589,   652,   682,   715,   761,
     776,   792,   801,   807,   816,   834,   852,   861,   873,   878,
     886,   906,   929,   940,   948,   970,   993,  1018,  1039,  1051,
    1065,  1065,  1067,  1069,  1080,  1092,  1091,  1104,  1105,  1109,
    1120,  1133,  1137,  1148,  1151,  1164,  1167,  1177,  1201,  1200,
    1220,  1242,  1260,  1281,  1299,  1329,  1359,  1377,  1395,  1421,
    1439,  1458,  1457,  1480,  1498,  1537,  1543,  1549,  1556,  1581,
    1606,  1623,  1640,  1672,  1671,  1695,  1713,  1730,  1747,  1746,
    1772,  1777,  1782,  1787,  1792,  1815,  1821,  1832,  1833,  1838,
    1841,  1845,  1868,  1891,  1914,  1942,  1963,  1986,  2007,  2029,
    2049,  2161,  2180,  2218,  2327,  2336,  2342,  2357,  2385,  2402,
    2416,  2422,  2428,  2437,  2451,  2496,  2513,  2528,  2547,  2559,
    2583,  2587,  2594,  2600,  2605,  2611,  2615,  2619,  2629,  2646,
    2663,  2684,  2705,  2740,  2748,  2754,  2761,  2765,  2774,  2782,
    2790,  2799,  2798,  2812,  2811,  2825,  2824,  2838,  2837,  2850,
    2857,  2864,  2871,  2878,  2885,  2892,  2899,  2906,  2914,  2913,
    2926,  2925,  2938,  2937,  2950,  2949,  2962,  2961,  2974,  2973,
    2986,  2985,  2998,  2997,  3010,  3009,  3025,  3028,  3034,  3043,
    3063,  3086,  3090,  3094,  3098,  3102,  3106,  3125,  3138,  3141,
    3157,  3160,  3173,  3176,  3182,  3185,  3192,  3248,  3318,  3323,
    3390,  3426,  3435,  3478,  3503,  3530,  3574,  3597,  3620,  3623,
    3632,  3636,  3646,  3681,  3682,  3686,  3691,  3702,  3724,  3725,
    3726,  3727,  3728,  3729,  3730,  3731,  3732,  3739,  3740,  3741,
    3742,  3743,  3744,  3745,  3746,  3747,  3748,  3749,  3750,  3751,
    3752,  3753,  3754,  3755,  3756,  3757,  3758,  3759,  3760,  3761,
    3762,  3763,  3764,  3765,  3766,  3767,  3768,  3769,  3770,  3772,
    3773,  3774,  3775,  3776,  3777,  3778,  3779,  3780,  3781,  3782,
    3783,  3784,  3785,  3786,  3787,  3788,  3789,  3790,  3791,  3792,
    3801,  3802,  3803,  3804,  3805,  3806,  3807,  3811,  3831,  3850,
    3868,  3880,  3897,  3918,  3923,  3928,  3938,  3948,  3956,  3960,
    3964,  3968,  3972,  3979,  3983,  3987,  3991,  3998,  4003,  4010,
    4015,  4019,  4024,  4028,  4036,  4047,  4051,  4063,  4071,  4079,
    4086,  4097,  4117,  4121,  4125,  4129,  4133,  4143,  4153,  4165,
    4177,  4198,  4203,  4207,  4211,  4223,  4227,  4239,  4246,  4256,
    4260,  4275,  4280,  4287,  4291,  4304,  4312,  4323,  4327,  4335,
    4343,  4351,  4359,  4373,  4387,  4391
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
     188,   189,   189,   190,   190,   191,   191,   192,   193,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   194,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   195,   192,   192,   192,   192,   196,   192,
     197,   197,   197,   197,   197,   197,   197,   198,   198,   199,
     199,   199,   199,   199,   199,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   201,   201,   201,   201,   201,   202,
     203,   203,   203,   203,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   206,   206,
     206,   207,   206,   208,   206,   209,   206,   210,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   211,   206,
     212,   206,   213,   206,   214,   206,   215,   206,   216,   206,
     217,   206,   218,   206,   219,   206,   220,   220,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   222,   222,
     223,   223,   224,   224,   225,   225,   226,   226,   226,   226,
     226,   226,   226,   226,   227,   227,   228,   228,   228,   228,
     229,   229,   229,   230,   230,   231,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   236,   236,   237,
     237,   237,   237,   237,   237,   238,   238,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   240,   240,   240,   240,   241,   241,   241,   241,   242,
     242,   243,   243,   244,   244,   244,   244,   245,   245,   245,
     245,   245,   245,   245,   245,   245
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
       0,     1,     0,     3,     5,     0,     9,     0,     2,     3,
       3,     1,     1,     0,     5,     0,     2,     7,     0,     9,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       8,     0,     9,     8,     9,     3,     4,    10,     7,     7,
       8,     8,    12,     0,     9,     8,     7,     8,     0,     9,
       5,    11,     5,     9,     4,     9,     9,     1,     1,     0,
       2,     6,     6,     6,     6,     8,    10,    14,    16,    12,
       8,     8,     6,    14,     4,     6,     6,     3,     4,     5,
       3,     3,     4,     4,     3,     7,     7,     3,     7,     3,
       2,     2,     2,    15,     2,     2,     2,     2,     6,     8,
       8,    10,     1,     2,     1,     3,     4,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     7,     5,     6,     6,    12,    10,    10,    10,    10,
       2,     3,     6,     1,     1,     2,     5,     7,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       4,     2,     5,     3,     6,     4,     7,     6,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     1,     1,     3,     4,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     4,
       6,     6,     4,     4,     4,     6
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
     192,     0,   197,     0,     0,   194,     0,     0,     0,     0,
     273,   274,     5,     7,     6,     8,     9,    10,    21,    11,
      12,    13,    20,    19,    14,    15,    16,    17,    18,     0,
      22,   340,   347,   407,    57,   341,   342,   343,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,     0,     0,     0,     0,   344,   345,
     346,    61,    60,    59,    58,     0,     0,     0,    63,    62,
       0,     0,     0,     0,   149,     0,     0,     0,   278,     0,
       0,     0,     0,   182,     0,   184,   181,   185,   186,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,     0,   108,   121,   133,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   270,
       0,     0,     0,     0,     0,   347,   376,     0,     0,     0,
       0,     0,     0,     0,   386,   387,   369,   375,     0,   370,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
     180,     0,     0,   193,     0,   149,     0,   149,   275,     0,
       0,     0,     0,     0,   351,    32,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   281,
     280,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,   147,     0,    69,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,   125,     0,     0,     0,    90,     0,     0,
     391,   392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,   359,     0,     0,     0,
       0,   149,   149,     0,     0,     0,     0,     0,     0,     0,
     207,     0,   149,     0,     0,     0,     0,     0,   254,     0,
       0,     0,   167,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,   382,     0,   383,   384,   385,     0,
     280,   377,   371,     0,     0,     0,   260,   179,     0,     0,
       0,     0,     0,   149,     0,     0,     0,     0,   195,   170,
       0,   171,     0,     0,     0,     0,   353,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,   279,    57,     0,     0,     0,    57,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,   150,
      65,     0,   296,   295,   294,   293,   289,   290,   292,   291,
     284,   283,   285,   286,   287,   288,   126,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   362,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,     0,     0,   164,     0,     0,     0,
       0,     0,   388,     0,     0,     0,     0,     0,   372,   379,
       0,   285,   378,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,   172,   173,     0,     0,     0,   349,   355,
       0,    42,     0,     0,     0,    55,     0,    33,    34,    35,
      36,    37,   298,   319,   299,   320,   300,   321,   301,   322,
     302,   323,   303,   324,   304,   325,   305,   326,   306,   327,
     318,   339,   307,   328,     0,     0,   309,   330,   310,   331,
     311,   332,   312,   333,   313,   334,   314,   335,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,     0,   412,
     413,    82,     0,   409,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,   350,     0,     0,
       0,     0,     0,    25,    23,     0,     0,     0,    64,    93,
       0,   393,   394,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   253,   251,     0,   259,     0,     0,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,   198,     0,     0,     0,
       0,     0,     0,   255,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   349,   389,   381,   373,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,     0,
       0,     0,   276,     0,     0,   352,     0,   348,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,    70,    72,    74,     0,     0,   401,
       0,    80,     0,     0,     0,     0,   297,    24,     0,     0,
       0,     0,     0,     0,   105,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,     0,     0,   242,     0,   244,     0,
     208,   237,     0,     0,     0,   162,     0,     0,     0,   263,
       0,   166,   165,   272,     0,     0,    30,    31,     0,   380,
     374,     0,     0,     0,   398,     0,     0,     0,   188,     0,
       0,     0,   176,   354,   175,     0,     0,     0,     0,   367,
       0,   308,   329,   315,   336,   316,   337,   317,   338,     0,
     415,   411,   357,   410,     0,    57,     0,     0,     0,     0,
      67,     0,     0,     0,   399,     0,     0,     0,     0,    26,
      27,     0,     0,     0,    94,   107,     0,     0,     0,     0,
       0,   111,     0,     0,   128,   129,     0,     0,   113,   136,
       0,     0,     0,   103,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,     0,     0,     0,     0,
     149,     0,   218,     0,   220,     0,   222,     0,   369,     0,
       0,   243,   245,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   390,   116,   117,     0,
       0,     0,     0,    83,    87,     0,   277,   356,     0,    38,
       0,     0,     0,     0,     0,    40,     0,     0,     0,     0,
      77,     0,     0,    78,     0,   402,   151,   152,   153,   154,
       0,     0,    95,     0,   106,   114,   115,   119,     0,     0,
     130,     0,     0,   258,   123,     0,     0,   249,   135,     0,
       0,     0,     0,   120,     0,   131,   137,     0,     0,     0,
       0,   366,     0,   365,     0,     0,   209,     0,     0,   210,
       0,     0,   211,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   160,     0,     0,     0,   155,     0,     0,
       0,     0,   396,     0,   190,   189,     0,     0,     0,    43,
       0,     0,     0,   368,     0,     0,     0,   406,    68,    73,
      75,     0,    81,     0,    28,     0,    97,     0,     0,     0,
       0,     0,     0,   124,   109,   122,   134,   139,     0,     0,
      88,    89,   149,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,   149,     0,     0,     0,     0,
       0,   146,   145,     0,     0,     0,     0,    84,    85,     0,
      39,     0,     0,     0,    41,    56,     0,   400,     0,     0,
     266,   267,   268,   269,   127,     0,     0,     0,     0,     0,
     364,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,     0,     0,     0,   203,     0,     0,   156,     0,     0,
       0,   395,   191,     0,     0,     0,     0,     0,    79,     0,
       0,    96,    98,     0,     0,     0,   141,     0,   224,     0,
       0,   226,     0,     0,   228,     0,     0,     0,   239,     0,
     199,     0,   149,     0,     0,     0,   118,    86,     0,    47,
       0,    53,     0,     0,     0,   104,   132,   265,   363,   212,
       0,     0,   219,   213,     0,     0,   221,   214,     0,     0,
     223,     0,     0,     0,   205,     0,   159,     0,     0,     0,
       0,     0,     0,     0,   100,    99,     0,   230,     0,   232,
       0,   234,   240,   246,   204,   200,     0,     0,     0,     0,
      44,     0,    51,     0,     0,     0,   215,     0,     0,   216,
       0,     0,   217,     0,     0,   163,     0,   157,     0,    45,
       0,     0,   183,     0,     0,     0,     0,     0,     0,   206,
       0,     0,     0,     0,     0,   225,     0,   227,     0,   229,
       0,   158,    46,    48,     0,    49,     0,     0,     0,     0,
       0,     0,    54,   231,   233,   235,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,   745,    73,    74,   468,  1088,  1094,
     667,   848,  1239,  1388,   668,  1350,  1414,   669,  1390,   670,
     671,   852,   145,   264,    75,   562,   357,  1196,  1249,  1292,
     776,  1126,  1018,   539,   383,   384,   385,   386,   234,   332,
     333,    78,    79,    80,    81,    82,    83,   235,   807,  1311,
    1366,   611,  1147,  1150,  1153,  1330,  1334,  1338,  1377,  1380,
    1383,   803,   804,   912,   773,   585,   620,    85,    86,    87,
      88,    89,    90,   236,   148,   396,   200,   978,   979,   238,
     239,   443,   246,   736,   880,   513,   514
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1063
static const yytype_int16 yypact[] =
{
    3830,    11,     9,  3912, -1063, -1063,  1725,    71,   -15,   -99,
      -3,    98,   113,   117,   180,    56,   -59,    40,    70,    20,
      84,    97,    17,   104,   158,   264,   271,   272,   324,   297,
     318,   177,   309,   521,   375,    85,   230,   328,   278,    82,
      82,   295,    69,    42,   358,   401,   376,    14,    43,   414,
     421,   480,   485,  1879,   497,   357,   360,   384,    19,    33,
   -1063,   390, -1063,   540,   399, -1063,   553,   557,    15,    34,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,    38,
   -1063, -1063,    21,   406,   317, -1063, -1063, -1063,   -13,    66,
     293,   320,   332,   361,   370,   437,   456,   467,   505,   535,
     549,   550,   561,   564,   574,   589,   607,   613,   617,   420,
     430,   431,   443, -1063,   568,   444,   460,   470, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063,  3435,  3435,  3435, -1063, -1063,
    3435,  1649,    47,   602,   311,  2323,   624,  1188, -1063,   627,
     636,  3435,   654, -1063,  3435, -1063, -1063, -1063, -1063, -1063,
    3435,  3359,  3435,  3435,   504,  3435,  3359,  3435,  3435,   525,
    3359,  3435,  3435,  2323,   531,   527, -1063,   541,   542,  1879,
    1879,  1879,   545, -1063, -1063, -1063, -1063,   560,   565,   575,
    2323,  3435,   737,  2323,    82,    82,    82,  3435,  3435,   -76,
   -1063,   -63,    82,   586,   592,   593,  3145,   -28,   -43,   608,
     644,   645,  1879,  2323,   655,    50,   609, -1063,   802, -1063,
     628,   653,   657,   665,   668,   103, -1063,   669,    37,   828,
     840,   841,  2471,  1570, -1063, -1063,  1149, -1063,   854, -1063,
     861,  3435,  3435,  3435,   683,  3435,   707,   772,  3435,  3435,
   -1063,  3435,   862, -1063,   876, -1063,   877, -1063, -1063,  2323,
     739,  3435,   890,   744, -1063, -1063, -1063,   885,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,
      22,    22,    22,    22,  3435,    22,    22,    22,   166,   747,
     747,   747,  6174,    76,  3359,  5415,   321,   755,   904,   776,
     784, -1063,   777,  3986,   935, -1063, -1063,  3435,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,  3435,
    3435,  3435, -1063, -1063,  1233,    61,  4713,    92,  6195,  3359,
    3600, -1063,   159,  6216,  6237,  3435,  6258,   630,  6279,  6300,
    3435,   634,  6321,  6342,   944,  3435,  3435,  3435,  3435,   945,
     969,   969,  3435,   832,   843,   866,   869,  3435,  3435,  3435,
     970,  4633,   896,  1013,   -30, -1063, -1063,  4739,  4765,    82,
      82,   311,   311,   165,  3435,  3435,  3435,  3145,  3145,  3435,
    3986,   222, -1063,  3435,  3435,  3435,  3435,  3435,  1019,  1040,
    3435,  1042, -1063,  3435,  3435,   798, -1063,  3359,  3359,  3359,
    3435,  3435,  2991,  1046, -1063,  3435, -1063, -1063, -1063,  3359,
     747, -1063, -1063,   635,  3435,  2619, -1063, -1063,  6363,  6384,
    6405,   948,  4791, -1063,   908,  3619,  6426,  5438, -1063, -1063,
    1758, -1063,  1926,   643,  3435,  5461,   -77,  3435,     6, -1063,
    6447,  5484,  6468,  5507,  6489,  5530,  6510,  5553,  6531,  5576,
    6552,  5599,  6573,  5622,  6594,  5645,  6615,  5668,  6636,  5691,
    6657,  5714,  4817,  4843,  6678,  5737,  6699,  5760,  6720,  5783,
    6741,  5806,  6762,  5829,  6783,  5852,  4869,  4895,  4921,  4947,
    4973,  4999,   648,   196, -1063,   905,   920,   923,  1371,   919,
     927,   925,  3435, -1063, -1063,  2323,   673,   221,   317,  3435,
    1072,  1077,    27,   930, -1063,    28,    32,    31,    64, -1063,
   -1063,  3638,  1205,  1303,  1257,  1257,   578,   578,   578,   578,
     611,   611,   747,   747,   747,   747, -1063,     7,  3359,  3435,
    1080, -1063,  1079,  1082,  3359,  3359,   980,  1083,  1085,  6804,
    1086,   987,  1088,  1089,  6825,   993,  1095,  1096,  3435,  6846,
    3716,  6867,  6888,  3435,  2323,  1100,  1101,  6909,  3501,  3501,
    3501,  3501,  6930,  6951,  6972,  2323,  3359,   953, -1063,    82,
    3435,  3435, -1063, -1063,   951,   952,  3435,  5025,  5051,  5077,
    4687,   477,    82,  2074,  6993,  3989,  7014,  7035,  7056,  3435,
    1106,  3435,  7077, -1063,  5875,  5898, -1063,   674,   702,   720,
    5921,  5944, -1063,  3359,  5967,   962,  4017,   721, -1063,  3666,
    3359,   747, -1063,  1108,  1112,  1114,   985,  3435,  2222,  3435,
    3435, -1063,     5, -1063, -1063,  2323,  1133,  5990,    77, -1063,
    4045, -1063,   997,   998,   986, -1063,  1135, -1063, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,
   -1063, -1063, -1063, -1063,  3435,  3435, -1063, -1063, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,  3435,  3435,
    3435,  3435,  3435,  3435,  3435,  1144, -1063,  3359,    22, -1063,
   -1063, -1063,  3435, -1063,    22,  1143,   999,    94,  3435,  1146,
    1148,  1428, -1063,  1151,  1005,    19,  1153, -1063,  3359,  3359,
    3359,  3359,  3435, -1063,  1014,    22,   208,  5103, -1063,  1154,
      82,  3600, -1063,  1105,  2323,  2323,  1155,  2323,   831,  2323,
    2323,  1156,  1107,  2323,  2323,  2574,  1159,  1161,  1162,  1164,
     992, -1063, -1063,  1166, -1063,  1168,  1023,  7308, -1063,  1026,
    1027,  1028,  1189,  1192,  1193,  1195,   732,  1198,   251,  5129,
    5155, -1063, -1063,  4073,    82,    82,    82,  1200,  1204,  1056,
    1057,    16,    35,   373, -1063,   257, -1063,   477,  1209,  1211,
    1212,  1217,  1218,  7308, -1063,  2593,  1062,  1222,  1223,  1224,
    1179,  3435,  1231,  1232,   746,   -14, -1063, -1063, -1063,  3435,
     749,  2323,  2323,  2323,  1236,  5181, -1063,  3685,   863,  1237,
    1239,  1087, -1063,  1241,  1244, -1063,  1245, -1063,  1103,  3435,
    3435,  2323,  1098, -1063,  7098,  6013,  7119,  6036,  7140,  6059,
    7161,  6082,  6105, -1063,   238,  1109,  7182,  1117, -1063,    76,
     371,  1092,  1248,  2732, -1063, -1063, -1063,    19,  3435, -1063,
     760, -1063,   761,   768,   769,   775,  7308, -1063,  1251,     8,
    3435,  3211,    10,  1102,  1199,  1199,  2323,  1258,  1113,  1115,
    1262,  1264,  2323,  1116,  1268,  1269, -1063,  1272,  2323,  2323,
    2323,  1290,  1289, -1063,  2323,  1291,  1293,  1294,  1295,  2323,
    2323,  2323, -1063,  1297,   413,  3435,  3435,  3435,  1152,   -82,
     -68,   -61,  1160, -1063,  2323,  3435, -1063,  1299, -1063,  1304,
   -1063, -1063,  3145,   417,  2027, -1063,  1157,  1176,  2767, -1063,
    3359, -1063, -1063, -1063,  1177,  3116, -1063, -1063,  1163,  7308,
   -1063,  1306,  1310,  1252, -1063,  3435,  3435,  3435, -1063,  1328,
     536,  1329, -1063,   -77, -1063,  3435,  5207,  5233,   778, -1063,
    3435, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,  1201,
   -1063, -1063, -1063, -1063,  2323,   317,  3435,  1350,  1353,    27,
   -1063,  1352,  6128,    19, -1063,  1354,  1372,  1373,  1374, -1063,
   -1063,    22,  5259,  3435,  7308, -1063,  3435,    82,  1376,  1378,
    1379, -1063,  3435,  3435, -1063, -1063,  1380,  3435, -1063, -1063,
    1383,  1384,  1397,  1282,  3435, -1063,  1400,  2323,  2323,  2323,
    2323,  1404,   941,  1405,  3435, -1063,  3501,  4101,  7203,  1050,
     311,    82,  1429,    82,  1442,    82,  1443,  3435,   530,  1301,
    7224, -1063, -1063,  4129,   276, -1063,  1446,  1398,  1448,  2323,
      82,  1398,  1451,   793,  3435, -1063, -1063, -1063, -1063,  2323,
    3933,   640,  7245, -1063, -1063,  3063, -1063, -1063,   239,  7308,
    3435,  3435,  2323,  1203,   808,  7308,  1454,  1453,  1455,  3174,
   -1063,  1456,  1458, -1063,  1307, -1063, -1063, -1063, -1063, -1063,
    1459,  3435,  7308,  4157,   118, -1063, -1063, -1063,  4185,  4213,
   -1063,  4241,  1457, -1063, -1063,  1413,  1461,  7308, -1063,  1463,
    1464,  1470,  1472, -1063,  1324, -1063, -1063,  4660,  3464,  1475,
    1327, -1063,  3435, -1063,  1330,   315, -1063,  1332,   333, -1063,
    1333,   335, -1063,  1334,  6151,  1478,  2323,  1479,  1335,  3435,
   -1063,  2915,   340, -1063,   809,   374,   396, -1063,  1487,  4269,
    1392,  3435, -1063,  3435, -1063, -1063,  3359,  3530,  1489, -1063,
    3435,  5285,  5311, -1063,  2323,  3435,  1490, -1063, -1063, -1063,
   -1063,    19, -1063,  1393, -1063,  5337, -1063,  1491,  1493,  1494,
    1509,  1511,  1362, -1063, -1063, -1063, -1063, -1063,  2323,  3359,
   -1063, -1063,   311,  3961, -1063,  3145,   477,  3145,   477,  3145,
     477,  1514, -1063,   813,  2323, -1063,  4297,    82,  1518,  3359,
      82, -1063, -1063,  3435,  4325,  4353,   818, -1063, -1063,  1370,
    7308,  3435,  3435,   829,  7308, -1063,  1521, -1063,  3435,   830,
   -1063, -1063, -1063, -1063, -1063,  3435,   834,   857,  1375,  3435,
   -1063,  4381,   405,   441,  4409,   426,   538,  4437,   457,   606,
   -1063,  2323,  1522,  1415,  2370,  1377,   471, -1063,   865,   492,
    3549, -1063, -1063,  1523,  3435,  7266,  5363,    39, -1063,  5389,
    1526, -1063, -1063,  4465,  1525,  1528, -1063,  4493,  1529,  3435,
    1533,  1534,  3435,  1535,  1537,  3435,  1538,  1389, -1063,  3435,
   -1063,   477, -1063,  3359,  1542,  2915, -1063, -1063,   870, -1063,
    3435, -1063,  2323,  3435,  2175, -1063, -1063, -1063, -1063, -1063,
    1394,  4521, -1063, -1063,  1395,  4549, -1063, -1063,  1401,  4577,
   -1063,  1543,  3570,   660,  2518,   874, -1063,   496,   875,  1547,
    1416,  7287,   879,  4605, -1063, -1063,   477,  1550,   477,  1569,
     477,  1571, -1063, -1063, -1063, -1063,   477,  1572,  3359,  1576,
   -1063,    22, -1063,  1450,  1601,   716, -1063,  1452,   735, -1063,
    1460,   748, -1063,  1462,   823, -1063,   880, -1063,   884, -1063,
    1465,  2323, -1063,  1603,   477,  1604,   477,  1605,   477, -1063,
    1606,    22,  1607,    22,   887, -1063,   852, -1063,   867, -1063,
     892, -1063, -1063, -1063,   888, -1063,  1608,  1609,  1611,  1614,
      22,  1617, -1063, -1063, -1063, -1063, -1063, -1063
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1063, -1063, -1063, -1063,   741, -1063, -1063, -1063, -1063,   342,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,
   -1063, -1063,  -315,    -1, -1063, -1063, -1063, -1063, -1063, -1063,
      48, -1063,   729,  1625, -1063, -1063, -1063, -1063,     3,  -400,
    -202, -1063, -1063, -1063, -1063, -1063, -1063,  1629, -1063, -1063,
   -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063, -1063,
   -1063,  -629,  -729, -1063, -1063,  1253, -1063, -1063, -1063, -1063,
   -1063, -1063, -1063,    -6, -1063,    46, -1063, -1062,   312,  -113,
     316,  -118,  -697,   638, -1063,  -283,    13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     147,   604,   605,   153,   410,   146,    77,  1164,   525,     5,
     661,   529,   839,   743,  1010,   425,  1015,     4,   215,   149,
     254,   169,   936,   244,   164,   260,   512,   266,   515,   516,
     517,   734,   519,   520,   521,   169,   164,   247,   879,   256,
     151,   938,   434,   362,   258,  1321,   208,   218,   367,   219,
     152,   326,   371,   460,   421,   462,   422,   399,   400,   119,
     120,   121,   122,   399,   400,   123,   379,   380,   381,   138,
     139,   399,   400,  1051,   941,  1052,   399,   400,   399,   400,
     401,   512,   266,   524,   150,   199,   201,  1053,   207,  1054,
     160,   209,   220,   402,  1055,   210,  1056,   161,   870,   418,
     662,   663,   664,   665,   155,   211,   413,   267,   937,   399,
     400,   399,   400,   414,   119,   120,   121,   122,   203,   156,
     123,   204,  1243,   157,   205,   599,   216,   939,   412,   319,
     320,   321,   138,   139,   322,   325,   268,   190,   269,   844,
     191,   126,   127,   744,   744,   354,  1256,   331,   356,   399,
     400,   327,   328,   154,   358,   360,   363,   364,   840,   366,
     360,   368,   369,   666,   360,   372,   373,   138,   139,   165,
     217,   255,   261,   170,   262,   245,   166,   160,   943,   263,
    1001,   165,   248,   735,   738,   391,   158,   740,   739,   162,
     257,   397,   398,   435,   259,  1322,   126,   127,   871,   872,
     398,   423,   131,   132,   133,   134,   526,   159,   195,   196,
     613,   557,   728,   172,   941,   270,   558,   271,   197,   163,
     741,   195,   196,   138,   139,   206,   440,   360,   524,   179,
     844,   197,   180,   167,   181,   448,   449,   450,   198,   452,
     394,   395,   455,   456,   560,   457,   168,   561,   403,   138,
     139,   648,   411,   171,   432,   465,   262,   399,   400,   144,
    1352,   263,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   399,   400,  1105,   172,   518,   627,
     628,   629,   138,   139,   565,   330,   566,   522,   360,   262,
     606,   637,   266,   173,   263,   530,   174,   175,   528,  1404,
     176,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   716,   131,   132,   133,
     134,   717,   177,   440,   119,   120,   121,   122,   889,   569,
     123,   399,   400,   565,   574,   237,   182,   138,   139,   579,
     580,   581,   582,   178,   727,   846,   587,   612,   995,   192,
     193,   592,   593,   594,    38,    39,    40,    41,   990,  1179,
     399,   400,    46,   565,  1180,    49,   399,   400,   607,   608,
     609,   319,   320,   610,   331,   331,   925,   614,   615,   616,
     617,   618,   942,   212,   622,   399,   400,   624,   625,  1045,
    1046,   360,   360,   360,   630,   631,   634,   187,   214,   636,
     188,  1159,   189,   360,   194,   865,   126,   127,   639,   641,
     746,   867,   272,   797,   273,   602,   603,   131,   132,   133,
     134,   202,   798,   395,   399,   400,   213,   334,   657,   799,
     800,   660,   888,   801,   802,   659,   221,   138,   139,   274,
    1215,   275,   399,   400,   399,   400,   222,   361,   786,   399,
     400,   276,   361,   277,   223,   374,   361,   797,  1217,   224,
    1219,   237,   237,   237,  1246,  1227,   798,   131,   132,   133,
     134,   240,   390,   799,   800,   393,   241,   801,   802,   242,
     278,   797,   279,   399,   400,   824,   634,   138,   139,   280,
     798,   281,   830,   731,   237,   419,   729,   799,   800,  1229,
     940,   801,   802,   243,   941,   399,   400,   941,   444,   249,
     941,   730,  1084,  1085,   399,   400,   250,   797,   441,   361,
     251,  1230,   360,   747,   994,   996,   798,   252,   641,   751,
    1299,   253,   265,   799,   800,   399,   400,   801,   802,   310,
     183,   463,   765,   184,  1065,   314,   185,   770,   186,   311,
     312,  1302,   777,   777,   777,   777,   282,  1263,   283,  1266,
     360,  1269,   313,   315,   789,   790,   399,   400,  1300,   864,
     793,   778,   778,   778,   778,   284,   329,   285,   797,   316,
     399,   400,  1305,   813,   941,   815,   286,   798,   287,   317,
     882,   883,   884,   885,   799,   800,  1313,   360,   801,   802,
     335,   399,   400,   352,   360,   399,   400,   779,   780,   781,
     361,   835,   353,   837,   838,   788,   941,  1315,  1173,   941,
    1144,  1368,   941,   365,   288,   941,   289,   845,   805,   355,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   445,   349,   350,   370,   441,   797,   941,   351,   941,
     375,   941,  1343,   376,   290,   798,   291,  1155,   854,   855,
     377,   378,   799,   800,   382,  1303,   801,   802,   292,   294,
     293,   295,   856,   857,   858,   859,   860,   861,   862,   387,
     296,   360,   297,   298,   388,   299,   866,   346,   347,   348,
     349,   350,   873,   300,   389,   301,   351,  1375,  1110,  1378,
     797,  1381,   360,   360,   360,   360,   886,  1384,   302,   798,
     303,   392,   404,   361,   361,   361,   799,   800,   405,   406,
     801,   802,   348,   349,   350,   361,   304,   415,   305,   351,
     424,   642,   306,  1306,   307,  1406,   308,  1408,   309,  1410,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   427,   565,   797,   571,   351,   565,
     565,   575,   638,   416,   417,   798,   892,  1174,   655,   714,
     656,   715,   799,   800,   420,   797,   801,   802,   426,   428,
       7,     8,  1258,   429,   798,   955,   430,  1364,   797,   431,
     433,   799,   800,   959,   845,   801,   802,   798,   565,   565,
     726,   819,  1073,   436,   799,   800,   451,   725,   801,   802,
     929,   930,   931,   976,   977,   437,   438,   535,    17,    18,
     536,    20,    21,   537,    23,   538,    25,   565,    26,   820,
     446,    29,    30,   453,    32,    33,    34,   447,   458,   997,
      37,   967,  1002,  1393,   361,   565,   565,   821,   828,   454,
     642,   752,   459,   461,  1012,  1014,   898,   565,   899,   923,
     464,   469,  1395,   797,   466,   351,   771,    55,    56,    57,
     467,   565,   798,   958,   565,  1397,   960,   785,   531,   799,
     800,   532,   361,   801,   802,  1003,   565,  1004,  1005,  1047,
    1048,  1049,   797,   565,   565,  1006,  1007,   533,  1058,  1060,
     565,   798,  1008,  1092,   534,  1093,  1063,   797,   799,   800,
     144,   540,   801,   802,   360,  1134,   798,  1135,   565,   361,
    1168,   578,   583,   799,   800,   626,   361,   801,   802,  1080,
    1081,  1082,   797,  1185,  1092,  1186,  1228,   841,  1271,  1089,
    1272,   798,  1087,   565,  1095,  1283,   584,   595,   799,   800,
    1399,   588,   801,   802,  1092,  1290,  1287,  1291,  1064,  1092,
    1099,  1294,   589,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,  1112,  1098,  1417,
    1113,   351,   565,   968,  1295,   590,  1118,  1119,   591,   598,
     565,  1121,  1314,  1274,  1418,  1185,   619,  1349,  1127,   565,
     565,  1367,  1369,   361,  1092,   565,  1373,  1400,  1137,  1401,
    1138,  1402,  1092,  1420,  1416,  1421,   597,   621,   623,  1419,
     635,  1154,   646,   331,   361,   361,   361,   361,  1236,  1139,
     718,   360,   911,  1114,   649,   360,   894,   895,  1169,   897,
     719,   900,   901,   720,   722,   904,   905,   723,   732,  1177,
     724,   733,   737,   749,  1181,  1182,   748,   753,  1389,   750,
     754,  1257,   755,   757,   758,   759,   760,  1145,  1178,  1148,
     762,  1151,   763,   764,   772,  1195,   787,   774,   791,   792,
    1344,  1278,   814,  1162,   826,   831,  1165,  1166,  1412,   832,
    1415,   833,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,  1213,  1426,   834,   842,
     351,   853,   851,   961,   962,   963,   849,   850,   863,   868,
     887,   869,   874,  1226,   875,   440,   878,   444,   877,   881,
     893,   891,   896,   902,   903,  1234,   907,  1235,   908,   909,
     360,   910,   913,   915,  1240,   914,   916,   917,   918,  1244,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   336,  1345,   919,  1348,   351,   920,
     921,   922,   924,   360,   932,  1142,   935,  1143,  1020,  1261,
     933,  1264,   934,  1267,  1026,   331,   944,   945,   950,   946,
    1031,  1032,  1033,   360,   947,   948,  1036,  1280,   951,   952,
     953,  1041,  1042,  1043,   954,  1285,  1286,   956,   957,   556,
     964,   969,  1289,   970,   971,   998,  1059,   972,   973,  1293,
    1386,   974,   975,  1297,   980,   999,  1068,  1009,  1016,   991,
    1072,  1262,  1017,  1265,  1021,  1268,   361,   993,  1024,  1022,
    1025,  1023,  1027,  1276,  1028,  1029,  1279,  1030,  1095,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     445,   349,   350,  1331,  1034,  1035,  1335,   351,  1037,  1339,
    1038,  1039,  1040,  1342,  1044,  1061,  1097,   360,  1050,   360,
    1062,  1057,  1077,  1069,  1351,  1076,  1078,  1353,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,  1070,  1074,  1083,  1086,   351,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,  1129,
    1130,  1131,  1132,   351,  1096,  1079,  1100,  1101,  1103,  1184,
    1106,  1347,   360,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   721,  1107,  1108,
    1109,   351,  1115,   361,  1116,  1117,  1120,   361,  1122,  1125,
    1123,  1170,   342,   343,   344,   345,   346,   347,   348,   349,
     350,    91,   225,  1124,  1183,   351,  1128,    95,    96,    97,
    1133,  1136,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   227,   876,  1146,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   228,  1149,  1152,
     229,   351,  1160,   230,  1163,   231,  1156,  1167,  1187,  1188,
    1193,  1189,  1201,  1191,  1192,  1194,  1202,  1203,  1223,  1204,
    1205,    38,    39,    40,    41,    42,  1206,   441,  1207,    46,
    1208,  1211,    49,  1212,  1222,  1309,  1224,  1214,  1216,  1218,
    1220,  1225,   361,  1231,  1233,  1238,  1245,  1250,  1247,  1251,
    1252,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,  1253,   125,  1254,  1255,   351,
    1270,   128,   129,   130,  1277,   361,  1284,  1288,  1308,  1317,
    1324,  1326,  1296,  1312,  1327,  1329,  1273,   407,  1161,  1332,
    1333,  1336,   137,  1337,  1340,   361,  1341,   409,  1346,  1362,
    1356,  1358,   143,  1370,   198,   442,  1376,  1360,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,  1371,    91,   225,  1379,   351,  1382,  1385,    95,
      96,    97,  1387,  1307,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   227,  1391,  1392,  1394,  1405,
    1407,  1409,  1411,  1413,  1422,  1423,  1396,  1424,  1398,   228,
    1425,  1403,   229,  1427,  1019,   230,  1318,   231,    76,   361,
    1011,   361,    84,     0,   586,     0,  1355,  1102,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,    46,    91,   318,    49,     0,     0,     0,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   361,     0,     0,     0,   125,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     359,     0,     0,     0,   137,     0,     0,     0,     0,   140,
       0,     0,     0,     0,   143,     0,     0,   442,    91,    92,
      93,     0,    94,     0,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,   120,   121,   122,     0,   125,   123,     0,
       7,     8,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   136,
       0,     0,     0,   137,     0,     0,     0,     0,   140,     0,
       0,   323,     0,   143,     0,   324,     0,   535,    17,    18,
     536,    20,    21,   537,    23,   538,    25,     0,    26,     0,
       0,    29,    30,     0,    32,    33,    34,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,   125,   126,   127,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,    55,    56,    57,
       0,     0,     0,     0,   135,   136,     0,     0,     0,   137,
       0,   138,   139,     0,   140,     0,   141,     0,   142,   143,
       0,   144,    91,   225,   226,     0,     0,     0,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,   653,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   229,     0,     0,   230,     0,   231,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
      46,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   535,    17,    18,   536,    20,
      21,   537,    23,   538,    25,     0,    26,     0,     0,    29,
      30,     0,    32,    33,    34,     0,     0,   125,    37,     0,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   232,
       0,     0,     0,   137,     0,    55,    56,    57,   140,     0,
      91,   225,  1066,   143,     0,   233,    95,    96,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,     0,   229,
       0,     0,   230,   654,   231,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,    46,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   535,    17,    18,   536,    20,    21,   537,
      23,   538,    25,     0,    26,     0,     0,    29,    30,     0,
      32,    33,    34,     0,     0,   125,    37,     0,     0,     0,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   232,     0,     0,
       0,   137,     0,    55,    56,    57,   140,     0,    91,   225,
    1354,   143,     0,  1067,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,     0,     0,   229,     0,     0,
     230,   806,   231,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,     0,     0,     0,    46,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   535,    17,    18,   536,    20,    21,   537,    23,   538,
      25,     0,    26,     0,     0,    29,    30,     0,    32,    33,
      34,     0,     0,   125,    37,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   232,     0,     0,     0,   137,
       0,    55,    56,    57,   140,     0,    91,   225,     0,   143,
       0,   233,    95,    96,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,     0,     0,   229,     0,     0,   230,   836,
     231,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,    46,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   535,
      17,    18,   536,    20,    21,   537,    23,   538,    25,     0,
      26,     0,     0,    29,    30,     0,    32,    33,    34,     0,
       0,   125,    37,     0,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   232,     0,     0,     0,   137,     0,    55,
      56,    57,   140,     0,    91,   225,     0,   143,     0,   233,
      95,    96,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,   229,     0,     0,   230,  1310,   231,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,     0,
       0,     0,    46,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   535,    17,    18,
     536,    20,    21,   537,    23,   538,    25,     0,    26,     0,
     906,    29,    30,     0,    32,    33,    34,     0,     0,   125,
      37,     0,     0,     0,   128,   129,   130,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   359,     0,     0,     0,   137,     0,    55,    56,    57,
     140,     0,    91,   225,     0,   143,     0,   439,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   229,     0,     0,   230,  1365,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
      46,     0,     0,    49,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   125,  1000,     0,
       0,   351,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   359,
       0,     0,     0,   137,     0,     0,     0,     0,   140,     0,
      91,   225,     0,   143,     0,   640,    95,    96,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,     0,   229,
       0,     0,   230,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,    46,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,     0,   125,     0,     0,     0,     0,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   232,     0,     0,
       0,   137,     0,     0,     0,     0,   140,     0,    91,   225,
       0,   143,     0,  1071,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,     0,     0,   229,     0,     0,
     230,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,     0,    91,   318,    46,     0,     0,    49,
      95,    96,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,  1161,     0,     0,     0,   137,
       0,     0,     0,     0,   409,     0,    91,   318,   266,   143,
       0,   198,    95,    96,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,   122,     0,     0,   123,     0,     0,   125,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,  1075,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,     0,   632,     0,   143,     0,   633,    91,   318,
       0,     0,     0,     0,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
    1190,   125,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,     0,     0,     0,   137,     0,     0,
       0,     0,   140,     0,    91,   318,     0,   143,     0,  1176,
      95,    96,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,   125,   351,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,   408,     0,     0,     0,   137,
       0,     0,     0,     0,   409,     0,     0,     0,     0,   143,
       0,   198,     0,     0,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,    91,   225,     0,   143,     0,  1013,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   229,     0,     0,   230,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,    91,   318,
      46,     0,     0,    49,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
    1210,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   359,
       0,     0,     0,   137,    91,   318,   266,     0,   140,     0,
      95,    96,    97,   143,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,  1237,     0,   119,   120,
     121,   122,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,  1316,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,  1363,     0,     0,   137,
       0,     0,     0,     0,   140,     0,     0,     0,     0,   143,
       0,     0,     0,     0,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   444,     0,
       0,     0,   351,     0,     0,     0,     0,     0,     0,   125,
     126,   127,     0,     0,   128,   129,   130,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,   742,     0,     0,     0,
     140,     0,     0,     0,     0,   143,     0,     0,     0,     0,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   829,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   966,     0,     0,     0,   351,     0,     0,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   564,   349,   350,     0,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
      -4,     1,     0,   351,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,    -4,     0,     0,     0,
       0,    -4,    -4,   767,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     6,     0,    -4,    -4,
       0,     0,     0,    -4,     7,     8,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     9,     0,
       0,    -4,    -4,    10,    11,     0,    12,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     7,     8,
      51,    52,     0,     0,     0,    53,     0,     0,     0,     0,
      54,    55,    56,    57,     0,     0,    58,     0,    59,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,    70,    71,   535,    17,    18,   536,    20,
      21,   537,    23,   538,    25,     0,    26,     0,     0,    29,
      30,     0,    32,    33,    34,     0,     0,     0,    37,     0,
       0,     0,     0,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,    55,    56,    57,  1171,     0,
    1172,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,  1259,     0,  1260,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,   809,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,   827,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,   847,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
     928,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1140,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1158,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1197,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1198,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1199,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1200,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1232,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1275,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1281,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1282,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1298,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1301,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1304,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1325,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1328,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1357,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1359,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1361,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1374,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,   596,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,     0,     0,     0,     0,  1209,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   523,     0,     0,
       0,     0,   600,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   559,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   600,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     601,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   647,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   694,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   695,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   708,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     709,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   710,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   711,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   712,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   713,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     794,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   795,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   796,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   890,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   926,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     927,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   965,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,  1090,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,  1091,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,  1111,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
    1241,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,  1242,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,  1248,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,  1320,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,  1323,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   527,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     652,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   658,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   673,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   675,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   677,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   679,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   681,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   683,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   685,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   687,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     689,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   691,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   693,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   697,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   699,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   701,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   703,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   705,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   707,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   817,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     818,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   822,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   823,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   825,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   843,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   982,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   984,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   986,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   988,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   989,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
    1104,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,  1221,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   523,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   563,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   567,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   568,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   570,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   572,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     573,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   576,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   577,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   643,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   644,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   645,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   651,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   672,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   674,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   676,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     678,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   680,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   682,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   684,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   686,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   688,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   690,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   692,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   696,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   698,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     700,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   702,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   704,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   706,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   756,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   761,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   766,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   768,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   769,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   775,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     782,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   783,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   784,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   808,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   810,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   811,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   812,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   816,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   981,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   983,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     985,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   987,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   992,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,  1141,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,  1157,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,  1175,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,  1319,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,  1372,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351
};

static const yytype_int16 yycheck[] =
{
       6,   401,   402,     6,   206,     6,     3,  1069,   323,     0,
       4,   326,     7,     6,     6,   217,     6,     6,     4,     6,
       5,     4,     6,     4,     4,     4,     4,     5,   311,   312,
     313,     4,   315,   316,   317,     4,     4,     4,   735,     5,
      55,     6,     5,   161,     6,     6,     4,     4,   166,     6,
     149,     4,   170,   255,     4,   257,     6,   139,   140,    37,
      38,    39,    40,   139,   140,    43,   179,   180,   181,   146,
     147,   139,   140,   155,   803,   157,   139,   140,   139,   140,
     156,     4,     5,     7,    13,    39,    40,   155,    42,   157,
     149,    49,    49,   156,   155,    53,   157,   156,     4,   212,
      94,    95,    96,    97,     6,    63,   149,    94,    92,   139,
     140,   139,   140,   156,    37,    38,    39,    40,    49,     6,
      43,    52,  1184,     6,    55,   155,   112,    92,   156,   135,
     136,   137,   146,   147,   140,   141,   149,    52,   151,   153,
      55,   119,   120,   136,   136,   151,  1208,   144,   154,   139,
     140,   104,   105,   156,   160,   161,   162,   163,   153,   165,
     166,   167,   168,   157,   170,   171,   172,   146,   147,   149,
     156,   156,   151,   156,   153,   156,   156,   149,   807,   158,
     877,   149,   149,   156,   156,   191,     6,   156,   156,   149,
     156,   197,   198,   156,   156,   156,   119,   120,   104,   105,
     206,   151,   126,   127,   128,   129,   324,   151,   139,   140,
     412,   150,   527,   149,   943,   149,   155,   151,   149,   149,
     156,   139,   140,   146,   147,   156,   232,   233,     7,    52,
     153,   149,    55,   149,    57,   241,   242,   243,   156,   245,
     194,   195,   248,   249,   152,   251,   149,   155,   202,   146,
     147,   453,   206,   149,   151,   261,   153,   139,   140,   156,
    1322,   158,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   139,   140,  1003,   149,   314,   427,
     428,   429,   146,   147,   155,     4,   157,   151,   324,   153,
     155,   439,     5,    59,   158,   326,    55,    55,     7,  1391,
       6,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   150,   126,   127,   128,
     129,   155,    55,   359,    37,    38,    39,    40,   150,   365,
      43,   139,   140,   155,   370,    53,    57,   146,   147,   375,
     376,   377,   378,    55,   153,   658,   382,   155,     7,   149,
      52,   387,   388,   389,    73,    74,    75,    76,   150,   150,
     139,   140,    81,   155,   155,    84,   139,   140,   404,   405,
     406,   407,   408,   409,   401,   402,   155,   413,   414,   415,
     416,   417,   155,    55,   420,   139,   140,   423,   424,     6,
       7,   427,   428,   429,   430,   431,   432,    52,    52,   435,
      55,   155,    57,   439,   156,   718,   119,   120,   444,   445,
     558,   724,   149,    70,   151,   399,   400,   126,   127,   128,
     129,   156,    79,   407,   139,   140,    55,   145,   464,    86,
      87,   467,   745,    90,    91,   466,    52,   146,   147,   149,
     155,   151,   139,   140,   139,   140,    55,   161,   596,   139,
     140,   149,   166,   151,     4,   173,   170,    70,   155,     4,
     155,   179,   180,   181,  1191,   155,    79,   126,   127,   128,
     129,     4,   190,    86,    87,   193,   149,    90,    91,   149,
     149,    70,   151,   139,   140,   633,   522,   146,   147,   149,
      79,   151,   640,   529,   212,   213,   527,    86,    87,   155,
     157,    90,    91,   149,  1263,   139,   140,  1266,     8,   149,
    1269,   528,     6,     7,   139,   140,     6,    70,   232,   233,
     151,   155,   558,   559,   869,   870,    79,     4,   564,   565,
     155,     4,   156,    86,    87,   139,   140,    90,    91,   149,
      49,   259,   578,    52,   157,     7,    55,   583,    57,   149,
     149,   155,   588,   589,   590,   591,   149,  1216,   151,  1218,
     596,  1220,   149,   149,   600,   601,   139,   140,   157,   717,
     606,   588,   589,   590,   591,   149,     4,   151,    70,   149,
     139,   140,   155,   619,  1343,   621,   149,    79,   151,   149,
     738,   739,   740,   741,    86,    87,   155,   633,    90,    91,
       6,   139,   140,     6,   640,   139,   140,   589,   590,   591,
     324,   647,     6,   649,   650,   599,  1375,   155,     8,  1378,
    1050,   155,  1381,   149,   149,  1384,   151,   658,   612,     5,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   149,   359,    70,  1406,   148,  1408,
     149,  1410,  1311,   156,   149,    79,   151,   157,   694,   695,
     149,   149,    86,    87,   149,   157,    90,    91,   149,   149,
     151,   151,   708,   709,   710,   711,   712,   713,   714,   149,
     149,   717,   151,   149,   149,   151,   722,   139,   140,   141,
     142,   143,   728,   149,   149,   151,   148,  1356,  1011,  1358,
      70,  1360,   738,   739,   740,   741,   742,  1366,   149,    79,
     151,     4,   156,   427,   428,   429,    86,    87,   156,   156,
      90,    91,   141,   142,   143,   439,   149,   149,   151,   148,
     151,   445,   149,   157,   151,  1394,   149,  1396,   151,  1398,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   156,   155,    70,   157,   148,   155,
     155,   157,   157,   149,   149,    79,   750,   157,   155,   151,
     157,   153,    86,    87,   149,    70,    90,    91,     6,   156,
      12,    13,  1212,   156,    79,   821,   151,   157,    70,   151,
     151,    86,    87,   829,   825,    90,    91,    79,   155,   155,
     157,   157,   950,     5,    86,    87,   153,   525,    90,    91,
     794,   795,   796,   849,   850,     5,     5,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   155,    60,   157,
       6,    63,    64,   156,    66,    67,    68,     6,     6,   870,
      72,     8,   878,   157,   558,   155,   155,   157,   157,   107,
     564,   565,     6,     6,   890,   891,    55,   155,    57,   157,
     151,     6,   157,    70,     4,   148,   584,    99,   100,   101,
     156,   155,    79,   157,   155,   157,   157,   595,   153,    86,
      87,     7,   596,    90,    91,   155,   155,   157,   157,   925,
     926,   927,    70,   155,   155,   157,   157,   151,   934,   935,
     155,    79,   157,   155,   157,   157,   942,    70,    86,    87,
     156,     6,    90,    91,   950,     4,    79,     6,   155,   633,
     157,     7,     7,    86,    87,   157,   640,    90,    91,   965,
     966,   967,    70,   155,   155,   157,   157,   655,   155,   975,
     157,    79,   973,   155,   980,   157,     7,     7,    86,    87,
     157,   149,    90,    91,   155,   155,   157,   157,   942,   155,
     996,   157,   149,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,  1013,   995,   157,
    1016,   148,   155,   150,   157,   149,  1022,  1023,   149,     6,
     155,  1027,   157,  1225,   157,   155,     7,   157,  1034,   155,
     155,   157,   157,   717,   155,   155,   157,   157,  1044,   155,
    1046,   157,   155,   155,   157,   157,   150,     7,     6,   157,
       4,  1057,   104,  1050,   738,   739,   740,   741,  1176,  1046,
     155,  1067,    70,  1017,   156,  1071,   754,   755,  1074,   757,
     150,   759,   760,   150,   155,   763,   764,   150,     6,  1085,
     155,     4,   152,     4,  1090,  1091,     6,   107,  1371,     7,
       7,  1209,     7,     7,   107,     7,     7,  1051,  1085,  1053,
     107,  1055,     7,     7,     4,  1111,   153,     6,   157,   157,
    1312,  1229,     6,  1067,   152,     7,  1070,  1071,  1401,     7,
    1403,     7,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,  1142,  1420,   153,     6,
     148,     6,   156,   831,   832,   833,   149,   149,     4,     6,
     136,   152,     6,  1159,     6,  1161,   151,     8,     7,     6,
      55,     7,     7,     7,    57,  1171,     7,  1173,     7,     7,
    1176,     7,     6,   150,  1180,     7,   150,   150,   150,  1185,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     6,  1313,     7,  1315,   148,     7,
       7,     6,     4,  1209,     4,   155,   149,   157,   896,  1215,
       6,  1217,   156,  1219,   902,  1212,     7,     6,   156,     7,
     908,   909,   910,  1229,     7,     7,   914,  1233,     6,     6,
       6,   919,   920,   921,    55,  1241,  1242,     6,     6,     6,
       4,     4,  1248,     4,   157,   153,   934,     6,     4,  1255,
    1368,     6,   149,  1259,   156,     7,   944,     6,   156,   150,
     948,  1215,    63,  1217,     6,  1219,   950,   150,     6,   156,
       6,   156,   156,  1227,     6,     6,  1230,     5,  1284,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,  1299,     4,     6,  1302,   148,     7,  1305,
       7,     7,     7,  1309,     7,     6,   994,  1313,   156,  1315,
       6,   151,     6,   156,  1320,   152,     6,  1323,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   156,   156,     6,     6,   148,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,  1037,
    1038,  1039,  1040,   148,   153,   103,     6,     4,     6,   156,
       6,  1315,  1368,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     6,     6,     6,
       6,   148,     6,  1067,     6,     6,     6,  1071,     5,   107,
       6,  1079,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     3,     4,     6,  1092,   148,     6,     9,    10,    11,
       6,     6,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     6,     6,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    49,     6,     6,
      52,   148,     6,    55,     6,    57,   155,     6,     4,     6,
     153,     6,     5,     7,     6,     6,    53,     6,  1156,     6,
       6,    73,    74,    75,    76,    77,     6,  1161,     6,    81,
     156,     6,    84,   156,     6,    70,     7,   157,   156,   156,
     156,   156,  1176,     6,   102,     6,     6,     6,   105,     6,
       6,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     6,   118,     6,   156,   148,
       6,   123,   124,   125,     6,  1209,   156,     6,     6,     6,
       4,     6,   157,   156,     6,     6,  1224,   139,   140,     6,
       6,     6,   144,     6,     6,  1229,   157,   149,     6,     6,
     156,   156,   154,     6,   156,   157,     6,   156,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   156,     3,     4,     6,   148,     6,     6,     9,
      10,    11,     6,  1271,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,   156,     6,   156,     6,
       6,     6,     6,     6,     6,     6,   156,     6,   156,    49,
       6,   156,    52,     6,   895,    55,  1284,    57,     3,  1313,
     889,  1315,     3,    -1,   381,    -1,  1324,   999,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    81,     3,     4,    84,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,  1368,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,   157,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    39,    40,    -1,   118,    43,    -1,
      12,    13,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,   154,    -1,   156,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    99,   100,   101,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,
      -1,   146,   147,    -1,   149,    -1,   151,    -1,   153,   154,
      -1,   156,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,    63,
      64,    -1,    66,    67,    68,    -1,    -1,   118,    72,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,   144,    -1,    99,   100,   101,   149,    -1,
       3,     4,     5,   154,    -1,   156,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,   157,    57,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    63,    64,    -1,
      66,    67,    68,    -1,    -1,   118,    72,    -1,    -1,    -1,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,   144,    -1,    99,   100,   101,   149,    -1,     3,     4,
       5,   154,    -1,   156,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,   157,    57,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    -1,    -1,    63,    64,    -1,    66,    67,
      68,    -1,    -1,   118,    72,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,
      -1,    99,   100,   101,   149,    -1,     3,     4,    -1,   154,
      -1,   156,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    55,   157,
      57,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    68,    -1,
      -1,   118,    72,    -1,    -1,    -1,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,    99,
     100,   101,   149,    -1,     3,     4,    -1,   154,    -1,   156,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,   157,    57,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    -1,
       6,    63,    64,    -1,    66,    67,    68,    -1,    -1,   118,
      72,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    99,   100,   101,
     149,    -1,     3,     4,    -1,   154,    -1,   156,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,   157,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,    84,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   118,     6,    -1,
      -1,   148,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,
       3,     4,    -1,   154,    -1,   156,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    55,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,   149,    -1,     3,     4,
      -1,   154,    -1,   156,     9,    10,    11,    -1,    -1,    14,
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
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,
      -1,    -1,    -1,    -1,   149,    -1,     3,     4,     5,   154,
      -1,   156,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    -1,   118,
      -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,   154,    -1,   156,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       6,   118,   119,   120,    -1,    -1,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,   149,    -1,     3,     4,    -1,   154,    -1,   156,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   118,   148,    -1,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
     149,    -1,     3,     4,    -1,   154,    -1,   156,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,     3,     4,
      81,    -1,    -1,    84,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,   144,     3,     4,     5,    -1,   149,    -1,
       9,    10,    11,   154,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     6,    -1,    37,    38,
      39,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,     6,    -1,    -1,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,     6,    -1,    -1,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     8,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,    -1,    -1,   123,   124,   125,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,     8,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     8,    -1,    -1,    -1,   148,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     8,    -1,    -1,    -1,   148,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
       0,     1,    -1,   148,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,   157,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,    -1,    88,    89,
      -1,    -1,    -1,    93,    12,    13,    -1,    -1,    98,    99,
     100,   101,    -1,    -1,   104,    -1,   106,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    36,    -1,
      -1,   121,   122,    41,    42,    -1,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    12,    13,
      88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,    -1,    -1,   104,    -1,   106,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,   121,   122,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    -1,    63,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    99,   100,   101,   155,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   130,   131,   132,   133,   134,
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
     142,   143,    -1,    -1,    -1,    -1,   148
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
     121,   122,   162,   164,   165,   183,   192,   197,   200,   201,
     202,   203,   204,   205,   206,   226,   227,   228,   229,   230,
     231,     3,     4,     5,     7,     9,    10,    11,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    37,
      38,    39,    40,    43,   112,   118,   119,   120,   123,   124,
     125,   126,   127,   128,   129,   139,   140,   144,   146,   147,
     149,   151,   153,   154,   156,   181,   182,   232,   233,   245,
      13,    55,   149,     6,   156,     6,     6,     6,     6,   151,
     149,   156,   149,   149,     4,   149,   156,   149,   149,     4,
     156,   149,   149,    59,    55,    55,     6,    55,    55,    52,
      55,    57,    57,    49,    52,    55,    57,    52,    55,    57,
      52,    55,   149,    52,   156,   139,   140,   149,   156,   234,
     235,   234,   156,    49,    52,    55,   156,   234,     4,    49,
      53,    63,    55,    55,    52,     4,   112,   156,     4,     6,
      49,    52,    55,     4,     4,     4,     5,    35,    49,    52,
      55,    57,   140,   156,   197,   206,   232,   237,   238,   239,
       4,   149,   149,   149,     4,   156,   241,     4,   149,   149,
       6,   151,     4,     4,     5,   156,     5,   156,     6,   156,
       4,   151,   153,   158,   182,   156,     5,   245,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   149,   149,   149,     7,   149,   149,   149,     4,   232,
     232,   232,   232,   152,   156,   232,     4,   104,   105,     4,
       4,   197,   198,   199,   237,     6,     6,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   148,     6,     6,   232,     5,   232,   185,   232,   140,
     232,   239,   240,   232,   232,   149,   232,   240,   232,   232,
     149,   240,   232,   232,   237,   149,   156,   149,   149,   238,
     238,   238,   149,   193,   194,   195,   196,   149,   149,   149,
     237,   232,     4,   237,   234,   234,   234,   232,   232,   139,
     140,   156,   156,   234,   156,   156,   156,   139,   140,   149,
     199,   234,   156,   149,   156,   149,   149,   149,   238,   237,
     149,     4,     6,   151,   151,   199,     6,   156,   156,   156,
     151,   151,   151,   151,     5,   156,     5,     5,     5,   156,
     232,   239,   157,   240,     8,   141,     6,     6,   232,   232,
     232,   153,   232,   156,   107,   232,   232,   232,     6,     6,
     199,     6,   199,   237,   151,   232,     4,   156,   166,     6,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,     4,   244,   245,   244,   244,   244,   232,   244,
     244,   244,   151,   150,     7,   181,   240,   152,     7,   181,
     182,   153,     7,   151,   157,    49,    52,    55,    57,   192,
       6,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,     6,   150,   155,   155,
     152,   155,   184,   150,   141,   155,   157,   150,   150,   232,
     150,   157,   150,   150,   232,   157,   150,   150,     7,   232,
     232,   232,   232,     7,     7,   224,   224,   232,   149,   149,
     149,   149,   232,   232,   232,     7,   156,   150,     6,   155,
     155,   155,   234,   234,   198,   198,   155,   232,   232,   232,
     232,   210,   155,   199,   232,   232,   232,   232,   232,     7,
     225,     7,   232,     6,   232,   232,   157,   240,   240,   240,
     232,   232,   152,   156,   232,     4,   232,   240,   157,   232,
     156,   232,   239,   150,   150,   150,   104,   155,   199,   156,
       8,   150,   152,   157,   157,   155,   157,   232,   152,   182,
     232,     4,    94,    95,    96,    97,   157,   169,   173,   176,
     178,   179,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   155,   155,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   155,   155,
     155,   155,   155,   155,   151,   153,   150,   155,   155,   150,
     150,     6,   155,   150,   155,   237,   157,   153,   181,   182,
     245,   232,     6,     4,     4,   156,   242,   152,   156,   156,
     156,   156,     8,     6,   136,   163,   240,   232,     6,     4,
       7,   232,   239,   107,     7,     7,   150,     7,   107,     7,
       7,   150,   107,     7,     7,   232,   150,   157,   150,   150,
     232,   237,     4,   223,     6,   150,   189,   232,   245,   189,
     189,   189,   150,   150,   150,   237,   240,   153,   234,   232,
     232,   157,   157,   232,   155,   155,   155,    70,    79,    86,
      87,    90,    91,   220,   221,   234,   157,   207,   150,   157,
     150,   150,   150,   232,     6,   232,   150,   152,   152,   157,
     157,   157,   152,   152,   240,   152,   152,   157,   157,     8,
     240,     7,     7,     7,   153,   232,   157,   232,   232,     7,
     153,   237,     6,   152,   153,   182,   244,   157,   170,   149,
     149,   156,   180,     6,   232,   232,   232,   232,   232,   232,
     232,   232,   232,     4,   240,   244,   232,   244,     6,   152,
       4,   104,   105,   232,     6,     6,     6,     7,   151,   241,
     243,     6,   240,   240,   240,   240,   232,   136,   244,   150,
     155,     7,   234,    55,   237,   237,     7,   237,    55,    57,
     237,   237,     7,    57,   237,   237,     6,     7,     7,     7,
       7,    70,   222,     6,     7,   150,   150,   150,   150,     7,
       7,     7,     6,   157,     4,   155,   155,   155,   157,   234,
     234,   234,     4,     6,   156,   149,     6,    92,     6,    92,
     157,   221,   155,   220,     7,     6,     7,     7,     7,     6,
     156,     6,     6,     6,    55,   232,     6,     6,   157,   232,
     157,   237,   237,   237,     4,   155,     8,     8,   150,     4,
       4,   157,     6,     4,     6,   149,   232,   232,   236,   237,
     156,   150,   152,   150,   152,   150,   152,   150,   152,   152,
     150,   150,   150,   150,   181,     7,   181,   182,   153,     7,
       6,   241,   232,   155,   157,   157,   157,   157,   157,     6,
       6,   163,   232,   156,   232,     6,   156,    63,   191,   191,
     237,     6,   156,   156,     6,     6,   237,   156,     6,     6,
       5,   237,   237,   237,     4,     6,   237,     7,     7,     7,
       7,   237,   237,   237,     7,     6,     7,   232,   232,   232,
     156,   155,   157,   155,   157,   155,   157,   151,   232,   237,
     232,     6,     6,   232,   234,   157,     5,   156,   237,   156,
     156,   156,   237,   240,   156,     6,   152,     6,     6,   103,
     232,   232,   232,     6,     6,     7,     6,   182,   167,   232,
     155,   155,   155,   157,   168,   232,   153,   237,   245,   232,
       6,     4,   242,     6,   152,   241,     6,     6,     6,     6,
     244,   155,   232,   232,   234,     6,     6,     6,   232,   232,
       6,   232,     5,     6,     6,   107,   190,   232,     6,   237,
     237,   237,   237,     6,     4,     6,     6,   232,   232,   245,
     157,   150,   155,   157,   198,   234,     6,   211,   234,     6,
     212,   234,     6,   213,   232,   157,   155,   150,   157,   155,
       6,   140,   234,     6,   236,   234,   234,     6,   157,   232,
     237,   155,   157,     8,   157,   150,   156,   232,   245,   150,
     155,   232,   232,   237,   156,   155,   157,     4,     6,     6,
       6,     7,     6,   153,     6,   232,   186,   157,   157,   157,
     157,     5,    53,     6,     6,     6,     6,     6,   156,   156,
       6,     6,   156,   232,   157,   155,   156,   155,   156,   155,
     156,   152,     6,   237,     7,   156,   232,   155,   157,   155,
     155,     6,   157,   102,   232,   232,   240,     6,     6,   171,
     232,   155,   155,   236,   232,     6,   241,   105,   155,   187,
       6,     6,     6,     6,     6,   156,   236,   240,   198,   155,
     157,   232,   234,   220,   232,   234,   220,   232,   234,   220,
       6,   155,   157,   237,   199,   157,   234,     6,   240,   234,
     232,   157,   157,   157,   156,   232,   232,   157,     6,   232,
     155,   157,   188,   232,   157,   157,   157,   232,   157,   155,
     157,   157,   155,   157,   157,   155,   157,   237,     6,    70,
     157,   208,   156,   155,   157,   155,     6,     6,   168,   150,
     155,     6,   156,   155,     4,   157,     6,     6,   157,     6,
     214,   232,     6,     6,   215,   232,     6,     6,   216,   232,
       6,   157,   232,   220,   199,   240,     6,   234,   240,   157,
     174,   232,   236,   232,     5,   237,   156,   157,   156,   157,
     156,   157,     6,     6,   157,   157,   209,   157,   155,   157,
       6,   156,   150,   157,   157,   220,     6,   217,   220,     6,
     218,   220,     6,   219,   220,     6,   240,     6,   172,   244,
     177,   156,     6,   157,   156,   157,   156,   157,   156,   157,
     157,   155,   157,   156,   236,     6,   220,     6,   220,     6,
     220,     6,   244,     6,   175,   244,   157,   157,   157,   157,
     155,   157,     6,     6,     6,     6,   244,     6
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
#line 158 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 169 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 170 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 171 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 172 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 173 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 174 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 194 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 201 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 206 "Gmsh.y"
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
#line 220 "Gmsh.y"
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
#line 233 "Gmsh.y"
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
#line 261 "Gmsh.y"
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
#line 275 "Gmsh.y"
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
#line 286 "Gmsh.y"
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
#line 300 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 314 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 316 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 321 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 323 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 328 "Gmsh.y"
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
#line 432 "Gmsh.y"
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
#line 442 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 451 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 458 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 468 "Gmsh.y"
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
#line 477 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 486 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 493 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 503 "Gmsh.y"
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
#line 511 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 521 "Gmsh.y"
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
#line 540 "Gmsh.y"
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
#line 559 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 565 "Gmsh.y"
    {
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 572 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 573 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 574 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 575 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 576 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 580 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 581 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 590 "Gmsh.y"
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
#line 653 "Gmsh.y"
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
#line 683 "Gmsh.y"
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
#line 716 "Gmsh.y"
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
#line 762 "Gmsh.y"
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
#line 777 "Gmsh.y"
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
#line 793 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 802 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 808 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 817 "Gmsh.y"
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
#line 835 "Gmsh.y"
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
#line 853 "Gmsh.y"
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
#line 862 "Gmsh.y"
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
#line 874 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 879 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 887 "Gmsh.y"
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
#line 907 "Gmsh.y"
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
#line 930 "Gmsh.y"
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
#line 941 "Gmsh.y"
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
#line 949 "Gmsh.y"
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
#line 971 "Gmsh.y"
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
#line 994 "Gmsh.y"
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
#line 1019 "Gmsh.y"
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
#line 1040 "Gmsh.y"
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
#line 1052 "Gmsh.y"
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
#line 1070 "Gmsh.y"
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
#line 1081 "Gmsh.y"
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
#line 1092 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1094 "Gmsh.y"
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
#line 1110 "Gmsh.y"
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

  case 100:

/* Line 1464 of yacc.c  */
#line 1121 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1134 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1138 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1148 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1152 "Gmsh.y"
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

  case 105:

/* Line 1464 of yacc.c  */
#line 1164 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1168 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1178 "Gmsh.y"
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

  case 108:

/* Line 1464 of yacc.c  */
#line 1201 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1205 "Gmsh.y"
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

  case 110:

/* Line 1464 of yacc.c  */
#line 1221 "Gmsh.y"
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

  case 111:

/* Line 1464 of yacc.c  */
#line 1243 "Gmsh.y"
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

  case 112:

/* Line 1464 of yacc.c  */
#line 1261 "Gmsh.y"
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

  case 113:

/* Line 1464 of yacc.c  */
#line 1282 "Gmsh.y"
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

  case 114:

/* Line 1464 of yacc.c  */
#line 1300 "Gmsh.y"
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

  case 115:

/* Line 1464 of yacc.c  */
#line 1330 "Gmsh.y"
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

  case 116:

/* Line 1464 of yacc.c  */
#line 1360 "Gmsh.y"
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

  case 117:

/* Line 1464 of yacc.c  */
#line 1378 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1396 "Gmsh.y"
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

  case 119:

/* Line 1464 of yacc.c  */
#line 1422 "Gmsh.y"
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

  case 120:

/* Line 1464 of yacc.c  */
#line 1440 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1458 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1462 "Gmsh.y"
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

  case 123:

/* Line 1464 of yacc.c  */
#line 1481 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1499 "Gmsh.y"
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

  case 125:

/* Line 1464 of yacc.c  */
#line 1538 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1544 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1550 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 1557 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1582 "Gmsh.y"
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

  case 130:

/* Line 1464 of yacc.c  */
#line 1607 "Gmsh.y"
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

  case 131:

/* Line 1464 of yacc.c  */
#line 1624 "Gmsh.y"
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

  case 132:

/* Line 1464 of yacc.c  */
#line 1642 "Gmsh.y"
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

  case 133:

/* Line 1464 of yacc.c  */
#line 1672 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1676 "Gmsh.y"
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

  case 135:

/* Line 1464 of yacc.c  */
#line 1696 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1714 "Gmsh.y"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1731 "Gmsh.y"
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

  case 138:

/* Line 1464 of yacc.c  */
#line 1747 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1751 "Gmsh.y"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 1773 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1778 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1783 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1788 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1793 "Gmsh.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1816 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1822 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1832 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1833 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1838 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1842 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1846 "Gmsh.y"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1869 "Gmsh.y"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 1892 "Gmsh.y"
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

  case 154:

/* Line 1464 of yacc.c  */
#line 1915 "Gmsh.y"
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

  case 155:

/* Line 1464 of yacc.c  */
#line 1943 "Gmsh.y"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 1964 "Gmsh.y"
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

  case 157:

/* Line 1464 of yacc.c  */
#line 1988 "Gmsh.y"
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

  case 158:

/* Line 1464 of yacc.c  */
#line 2009 "Gmsh.y"
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

  case 159:

/* Line 1464 of yacc.c  */
#line 2030 "Gmsh.y"
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

  case 160:

/* Line 1464 of yacc.c  */
#line 2050 "Gmsh.y"
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

  case 161:

/* Line 1464 of yacc.c  */
#line 2162 "Gmsh.y"
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

  case 162:

/* Line 1464 of yacc.c  */
#line 2181 "Gmsh.y"
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

  case 163:

/* Line 1464 of yacc.c  */
#line 2220 "Gmsh.y"
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

  case 164:

/* Line 1464 of yacc.c  */
#line 2328 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2337 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2343 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2358 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2386 "Gmsh.y"
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

  case 169:

/* Line 1464 of yacc.c  */
#line 2403 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2417 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2423 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2429 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 2438 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2452 "Gmsh.y"
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

  case 175:

/* Line 1464 of yacc.c  */
#line 2497 "Gmsh.y"
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

  case 176:

/* Line 1464 of yacc.c  */
#line 2514 "Gmsh.y"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 2529 "Gmsh.y"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 2548 "Gmsh.y"
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

  case 179:

/* Line 1464 of yacc.c  */
#line 2560 "Gmsh.y"
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

  case 180:

/* Line 1464 of yacc.c  */
#line 2584 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 2588 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2595 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2601 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 2606 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2612 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2616 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2620 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2630 "Gmsh.y"
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

  case 189:

/* Line 1464 of yacc.c  */
#line 2647 "Gmsh.y"
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

  case 190:

/* Line 1464 of yacc.c  */
#line 2664 "Gmsh.y"
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

  case 191:

/* Line 1464 of yacc.c  */
#line 2685 "Gmsh.y"
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

  case 192:

/* Line 1464 of yacc.c  */
#line 2706 "Gmsh.y"
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

  case 193:

/* Line 1464 of yacc.c  */
#line 2741 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2749 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2755 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 2762 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2766 "Gmsh.y"
    {
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2775 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2783 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2791 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2799 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2804 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2812 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2817 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2825 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2830 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2838 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2843 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2851 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2858 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2865 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2872 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2879 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2886 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2893 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2900 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2907 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2914 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2919 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2926 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2931 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2938 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2943 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2950 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2955 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2962 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2967 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2974 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 2986 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 2991 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 2998 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3010 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3026 "Gmsh.y"
    {
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3029 "Gmsh.y"
    {
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3035 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3044 "Gmsh.y"
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

  case 240:

/* Line 1464 of yacc.c  */
#line 3064 "Gmsh.y"
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

  case 241:

/* Line 1464 of yacc.c  */
#line 3087 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3091 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3095 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3099 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3103 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3107 "Gmsh.y"
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

  case 247:

/* Line 1464 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3142 "Gmsh.y"
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

  case 250:

/* Line 1464 of yacc.c  */
#line 3157 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3161 "Gmsh.y"
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

  case 252:

/* Line 1464 of yacc.c  */
#line 3173 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3177 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3182 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3186 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 3193 "Gmsh.y"
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

  case 257:

/* Line 1464 of yacc.c  */
#line 3249 "Gmsh.y"
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

  case 258:

/* Line 1464 of yacc.c  */
#line 3319 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3324 "Gmsh.y"
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

  case 260:

/* Line 1464 of yacc.c  */
#line 3391 "Gmsh.y"
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

  case 261:

/* Line 1464 of yacc.c  */
#line 3427 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3436 "Gmsh.y"
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

  case 263:

/* Line 1464 of yacc.c  */
#line 3479 "Gmsh.y"
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

  case 264:

/* Line 1464 of yacc.c  */
#line 3504 "Gmsh.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 3532 "Gmsh.y"
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

  case 266:

/* Line 1464 of yacc.c  */
#line 3575 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3598 "Gmsh.y"
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

  case 268:

/* Line 1464 of yacc.c  */
#line 3621 "Gmsh.y"
    {
    ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3624 "Gmsh.y"
    {
    ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3633 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3637 "Gmsh.y"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 3647 "Gmsh.y"
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

  case 273:

/* Line 1464 of yacc.c  */
#line 3681 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3682 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3687 "Gmsh.y"
    {
      std::vector<int> domain, subdomain;
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain);
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3692 "Gmsh.y"
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

  case 277:

/* Line 1464 of yacc.c  */
#line 3703 "Gmsh.y"
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

  case 278:

/* Line 1464 of yacc.c  */
#line 3724 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3725 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3726 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3727 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3728 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3729 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3730 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3731 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3733 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3739 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3740 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3741 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3742 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3743 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3744 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3745 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3746 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3747 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3748 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3749 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3750 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3751 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3752 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3753 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3754 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3755 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3756 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3757 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3758 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3759 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3760 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3761 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3762 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3763 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3764 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3765 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3766 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3767 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3768 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3769 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3770 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3772 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3773 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3774 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3775 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3776 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3777 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3778 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3779 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3780 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3781 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3782 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3783 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3784 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3785 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3786 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3787 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3788 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3789 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3790 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3791 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3792 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3801 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3802 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3803 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3804 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3805 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3806 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3807 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3812 "Gmsh.y"
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

  case 348:

/* Line 1464 of yacc.c  */
#line 3832 "Gmsh.y"
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

  case 349:

/* Line 1464 of yacc.c  */
#line 3851 "Gmsh.y"
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

  case 350:

/* Line 1464 of yacc.c  */
#line 3869 "Gmsh.y"
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

  case 351:

/* Line 1464 of yacc.c  */
#line 3881 "Gmsh.y"
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

  case 352:

/* Line 1464 of yacc.c  */
#line 3898 "Gmsh.y"
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

  case 353:

/* Line 1464 of yacc.c  */
#line 3919 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3924 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3929 "Gmsh.y"
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

  case 356:

/* Line 1464 of yacc.c  */
#line 3939 "Gmsh.y"
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

  case 357:

/* Line 1464 of yacc.c  */
#line 3949 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 3957 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3961 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3965 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3969 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3973 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3980 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 3984 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 3988 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 3992 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 3999 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4004 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4011 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4016 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4020 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4025 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4029 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4037 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4052 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4064 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4072 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4080 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4087 "Gmsh.y"
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

  case 381:

/* Line 1464 of yacc.c  */
#line 4098 "Gmsh.y"
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

  case 382:

/* Line 1464 of yacc.c  */
#line 4118 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4122 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4126 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4130 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4134 "Gmsh.y"
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

  case 387:

/* Line 1464 of yacc.c  */
#line 4144 "Gmsh.y"
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

  case 388:

/* Line 1464 of yacc.c  */
#line 4154 "Gmsh.y"
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

  case 389:

/* Line 1464 of yacc.c  */
#line 4166 "Gmsh.y"
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

  case 390:

/* Line 1464 of yacc.c  */
#line 4178 "Gmsh.y"
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

  case 391:

/* Line 1464 of yacc.c  */
#line 4199 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4204 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4208 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4212 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4224 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4228 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4240 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4247 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4257 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4261 "Gmsh.y"
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

  case 401:

/* Line 1464 of yacc.c  */
#line 4276 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4281 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4288 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4292 "Gmsh.y"
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

  case 405:

/* Line 1464 of yacc.c  */
#line 4305 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4313 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4324 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4328 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4336 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4344 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4352 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 4360 "Gmsh.y"
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

  case 413:

/* Line 1464 of yacc.c  */
#line 4374 "Gmsh.y"
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

  case 414:

/* Line 1464 of yacc.c  */
#line 4388 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4392 "Gmsh.y"
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
#line 9998 "Gmsh.tab.cpp"
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
#line 4412 "Gmsh.y"


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

