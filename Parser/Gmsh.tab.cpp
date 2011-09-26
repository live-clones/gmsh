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

// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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

#if defined(HAVE_KBIPACK)
#include "Homology.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string > gmsh_yystringsymbols;
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

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);


/* Line 189 of yacc.c  */
#line 169 "Gmsh.tab.cpp"

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
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tSyncModel = 298,
     tCreateTopology = 299,
     tCreateTopologyNoHoles = 300,
     tDistanceFunction = 301,
     tPoint = 302,
     tCircle = 303,
     tEllipse = 304,
     tLine = 305,
     tSphere = 306,
     tPolarSphere = 307,
     tSurface = 308,
     tSpline = 309,
     tVolume = 310,
     tCharacteristic = 311,
     tLength = 312,
     tParametric = 313,
     tElliptic = 314,
     tRefineMesh = 315,
     tPlane = 316,
     tRuled = 317,
     tTransfinite = 318,
     tComplex = 319,
     tPhysical = 320,
     tCompound = 321,
     tPeriodic = 322,
     tUsing = 323,
     tPlugin = 324,
     tDegenerated = 325,
     tRotate = 326,
     tTranslate = 327,
     tSymmetry = 328,
     tDilate = 329,
     tExtrude = 330,
     tLevelset = 331,
     tLoop = 332,
     tRecombine = 333,
     tSmoother = 334,
     tSplit = 335,
     tDelete = 336,
     tCoherence = 337,
     tIntersect = 338,
     tLayers = 339,
     tHole = 340,
     tAlias = 341,
     tAliasWithOptions = 342,
     tQuadTriDbl = 343,
     tQuadTriSngl = 344,
     tRecombLaterals = 345,
     tTransfQuadTri = 346,
     tText2D = 347,
     tText3D = 348,
     tInterpolationScheme = 349,
     tTime = 350,
     tCombine = 351,
     tBSpline = 352,
     tBezier = 353,
     tNurbs = 354,
     tNurbsOrder = 355,
     tNurbsKnots = 356,
     tColor = 357,
     tColorTable = 358,
     tFor = 359,
     tIn = 360,
     tEndFor = 361,
     tIf = 362,
     tEndIf = 363,
     tExit = 364,
     tField = 365,
     tReturn = 366,
     tCall = 367,
     tFunction = 368,
     tShow = 369,
     tHide = 370,
     tGetValue = 371,
     tGetEnv = 372,
     tGetString = 373,
     tGMSH_MAJOR_VERSION = 374,
     tGMSH_MINOR_VERSION = 375,
     tGMSH_PATCH_VERSION = 376,
     tHomRank = 377,
     tHomGen = 378,
     tHomCut = 379,
     tHomSeq = 380,
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
#line 89 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 214 of yacc.c  */
#line 355 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 367 "Gmsh.tab.cpp"

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
#define YYLAST   7166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  401
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1434

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
     227,   229,   231,   233,   235,   240,   248,   258,   265,   272,
     279,   283,   290,   295,   302,   312,   319,   329,   335,   344,
     353,   365,   372,   382,   388,   396,   406,   416,   428,   438,
     448,   450,   452,   453,   459,   460,   463,   471,   472,   482,
     489,   497,   502,   510,   519,   528,   536,   544,   556,   565,
     574,   575,   585,   594,   604,   608,   613,   624,   632,   640,
     649,   658,   671,   672,   682,   691,   699,   708,   709,   719,
     725,   737,   743,   753,   758,   768,   778,   780,   782,   783,
     786,   793,   800,   807,   814,   823,   834,   849,   866,   879,
     888,   897,   904,   919,   924,   931,   938,   942,   947,   953,
     957,   961,   966,   971,   975,   983,   991,   995,  1003,  1007,
    1010,  1013,  1016,  1032,  1035,  1038,  1041,  1044,  1051,  1060,
    1069,  1080,  1082,  1085,  1087,  1091,  1096,  1098,  1104,  1116,
    1130,  1131,  1139,  1140,  1154,  1155,  1171,  1172,  1179,  1188,
    1197,  1206,  1219,  1232,  1245,  1260,  1275,  1290,  1291,  1304,
    1305,  1318,  1319,  1332,  1333,  1350,  1351,  1368,  1369,  1386,
    1387,  1406,  1407,  1426,  1427,  1446,  1448,  1451,  1457,  1465,
    1475,  1478,  1481,  1485,  1488,  1492,  1502,  1509,  1510,  1514,
    1515,  1517,  1518,  1521,  1522,  1525,  1533,  1540,  1549,  1555,
    1559,  1565,  1572,  1579,  1592,  1603,  1614,  1625,  1636,  1639,
    1643,  1650,  1662,  1674,  1686,  1698,  1700,  1704,  1707,  1710,
    1713,  1717,  1721,  1725,  1729,  1733,  1737,  1741,  1745,  1749,
    1753,  1757,  1761,  1765,  1769,  1775,  1780,  1785,  1790,  1795,
    1800,  1805,  1810,  1815,  1820,  1825,  1832,  1837,  1842,  1847,
    1852,  1857,  1862,  1869,  1876,  1883,  1888,  1893,  1898,  1903,
    1908,  1913,  1918,  1923,  1928,  1933,  1938,  1945,  1950,  1955,
    1960,  1965,  1970,  1975,  1982,  1989,  1996,  2001,  2003,  2005,
    2007,  2009,  2011,  2013,  2015,  2017,  2023,  2028,  2033,  2036,
    2042,  2046,  2053,  2058,  2066,  2073,  2075,  2078,  2081,  2085,
    2089,  2101,  2111,  2119,  2127,  2129,  2133,  2135,  2137,  2140,
    2144,  2149,  2155,  2157,  2159,  2162,  2166,  2170,  2176,  2181,
    2184,  2187,  2190,  2193,  2195,  2197,  2201,  2208,  2210,  2212,
    2216,  2220,  2230,  2238,  2240,  2246,  2250,  2257,  2259,  2263,
    2265,  2267,  2271,  2278,  2280,  2282,  2287,  2294,  2301,  2306,
    2311,  2316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     160,     0,    -1,   161,    -1,     1,     6,    -1,    -1,   161,
     162,    -1,   165,    -1,   164,    -1,   183,    -1,   187,    -1,
     192,    -1,   196,    -1,   197,    -1,   198,    -1,   201,    -1,
     221,    -1,   222,    -1,   223,    -1,   224,    -1,   200,    -1,
     199,    -1,   195,    -1,   225,    -1,   136,    -1,   136,   136,
      -1,    35,   149,     5,   150,     6,    -1,    35,   149,     5,
     150,   163,   238,     6,    -1,    35,   149,     5,   155,   234,
     150,     6,    -1,    35,   149,     5,   155,   234,   150,   163,
     238,     6,    -1,     4,     5,   156,   166,   157,     6,    -1,
      86,     4,   151,   226,   152,     6,    -1,    87,     4,   151,
     226,   152,     6,    -1,    -1,   166,   169,    -1,   166,   173,
      -1,   166,   176,    -1,   166,   178,    -1,   166,   179,    -1,
     226,    -1,   167,   155,   226,    -1,   226,    -1,   168,   155,
     226,    -1,    -1,    -1,     4,   170,   149,   167,   150,   171,
     156,   168,   157,     6,    -1,   238,    -1,   172,   155,   238,
      -1,    -1,    92,   149,   226,   155,   226,   155,   226,   150,
     174,   156,   172,   157,     6,    -1,   238,    -1,   175,   155,
     238,    -1,    -1,    93,   149,   226,   155,   226,   155,   226,
     155,   226,   150,   177,   156,   175,   157,     6,    -1,    94,
     156,   230,   157,   156,   230,   157,     6,    -1,    94,   156,
     230,   157,   156,   230,   157,   156,   230,   157,   156,   230,
     157,     6,    -1,    -1,    95,   180,   156,   168,   157,     6,
      -1,     7,    -1,   129,    -1,   128,    -1,   127,    -1,   126,
      -1,   147,    -1,   146,    -1,     4,   181,   226,     6,    -1,
       4,   151,   226,   152,   181,   226,     6,    -1,     4,   151,
     156,   234,   157,   152,   181,   231,     6,    -1,     4,   151,
     152,     7,   231,     6,    -1,     4,   151,   152,   129,   231,
       6,    -1,     4,   151,   152,   128,   231,     6,    -1,     4,
     182,     6,    -1,     4,   151,   226,   152,   182,     6,    -1,
       4,     7,   239,     6,    -1,     4,   153,     4,     7,   239,
       6,    -1,     4,   151,   226,   152,   153,     4,     7,   239,
       6,    -1,     4,   153,     4,   181,   226,     6,    -1,     4,
     151,   226,   152,   153,     4,   181,   226,     6,    -1,     4,
     153,     4,   182,     6,    -1,     4,   151,   226,   152,   153,
       4,   182,     6,    -1,     4,   153,   102,   153,     4,     7,
     235,     6,    -1,     4,   151,   226,   152,   153,   102,   153,
       4,     7,   235,     6,    -1,     4,   153,   103,     7,   236,
       6,    -1,     4,   151,   226,   152,   153,   103,     7,   236,
       6,    -1,     4,   110,     7,   226,     6,    -1,   110,   151,
     226,   152,     7,     4,     6,    -1,   110,   151,   226,   152,
     153,     4,     7,   226,     6,    -1,   110,   151,   226,   152,
     153,     4,     7,   239,     6,    -1,   110,   151,   226,   152,
     153,     4,     7,   156,   234,   157,     6,    -1,    69,   149,
       4,   150,   153,     4,     7,   226,     6,    -1,    69,   149,
       4,   150,   153,     4,     7,   239,     6,    -1,   226,    -1,
     239,    -1,    -1,   105,    51,   156,   226,   157,    -1,    -1,
      61,   228,    -1,    47,   149,   226,   150,     7,   228,     6,
      -1,    -1,    65,    47,   188,   149,   184,   150,     7,   231,
       6,    -1,    56,    57,   231,     7,   226,     6,    -1,    50,
     149,   226,   150,     7,   231,     6,    -1,    70,    50,   231,
       6,    -1,    54,   149,   226,   150,     7,   231,     6,    -1,
      48,   149,   226,   150,     7,   231,   186,     6,    -1,    49,
     149,   226,   150,     7,   231,   186,     6,    -1,    97,   149,
     226,   150,     7,   231,     6,    -1,    98,   149,   226,   150,
       7,   231,     6,    -1,    99,   149,   226,   150,     7,   231,
     101,   231,   100,   226,     6,    -1,    50,    77,   149,   226,
     150,     7,   231,     6,    -1,    66,    50,   149,   226,   150,
       7,   231,     6,    -1,    -1,    65,    50,   189,   149,   184,
     150,     7,   231,     6,    -1,    61,    53,   149,   226,   150,
       7,   231,     6,    -1,    62,    53,   149,   226,   150,     7,
     231,   185,     6,    -1,    12,    13,     6,    -1,    13,    53,
     226,     6,    -1,    58,    53,   149,   226,   150,     7,     5,
       5,     5,     6,    -1,    51,   149,   226,   150,     7,   231,
       6,    -1,    52,   149,   226,   150,     7,   231,     6,    -1,
      53,    77,   149,   226,   150,     7,   231,     6,    -1,    66,
      53,   149,   226,   150,     7,   231,     6,    -1,    66,    53,
     149,   226,   150,     7,   231,     4,   156,   230,   157,     6,
      -1,    -1,    65,    53,   190,   149,   184,   150,     7,   231,
       6,    -1,    64,    55,   149,   226,   150,     7,   231,     6,
      -1,    55,   149,   226,   150,     7,   231,     6,    -1,    66,
      55,   149,   226,   150,     7,   231,     6,    -1,    -1,    65,
      55,   191,   149,   184,   150,     7,   231,     6,    -1,    72,
     228,   156,   193,   157,    -1,    71,   156,   228,   155,   228,
     155,   226,   157,   156,   193,   157,    -1,    73,   228,   156,
     193,   157,    -1,    74,   156,   228,   155,   226,   157,   156,
     193,   157,    -1,     4,   156,   193,   157,    -1,    83,    50,
     156,   234,   157,    53,   156,   226,   157,    -1,    80,    50,
     149,   226,   150,   156,   234,   157,     6,    -1,   194,    -1,
     192,    -1,    -1,   194,   187,    -1,   194,    47,   156,   234,
     157,     6,    -1,   194,    50,   156,   234,   157,     6,    -1,
     194,    53,   156,   234,   157,     6,    -1,   194,    55,   156,
     234,   157,     6,    -1,    76,    61,   149,   226,   150,     7,
     231,     6,    -1,    76,    47,   149,   226,   150,     7,   156,
     230,   157,     6,    -1,    76,    61,   149,   226,   150,     7,
     156,   228,   155,   228,   155,   234,   157,     6,    -1,    76,
      61,   149,   226,   150,     7,   156,   228,   155,   228,   155,
     228,   155,   234,   157,     6,    -1,    76,    51,   149,   226,
     150,     7,   156,   228,   155,   234,   157,     6,    -1,    76,
       4,   149,   226,   150,     7,   231,     6,    -1,    76,     4,
     149,   226,   150,     7,     5,     6,    -1,    76,     4,   156,
     226,   157,     6,    -1,    76,     4,   149,   226,   150,     7,
     156,   228,   155,   228,   155,   234,   157,     6,    -1,    81,
     156,   194,   157,    -1,    81,   110,   151,   226,   152,     6,
      -1,    81,     4,   151,   226,   152,     6,    -1,    81,     4,
       6,    -1,    81,     4,     4,     6,    -1,   102,   235,   156,
     194,   157,    -1,   114,     5,     6,    -1,   115,     5,     6,
      -1,   114,   156,   194,   157,    -1,   115,   156,   194,   157,
      -1,     4,   239,     6,    -1,     4,     4,   151,   226,   152,
     238,     6,    -1,     4,     4,     4,   151,   226,   152,     6,
      -1,     4,   226,     6,    -1,    69,   149,     4,   150,   153,
       4,     6,    -1,    96,     4,     6,    -1,   109,     6,    -1,
      43,     6,    -1,    40,     6,    -1,    40,   156,   226,   155,
     226,   155,   226,   155,   226,   155,   226,   155,   226,   157,
       6,    -1,    41,     6,    -1,    44,     6,    -1,    45,     6,
      -1,    60,     6,    -1,   104,   149,   226,     8,   226,   150,
      -1,   104,   149,   226,     8,   226,     8,   226,   150,    -1,
     104,     4,   105,   156,   226,     8,   226,   157,    -1,   104,
       4,   105,   156,   226,     8,   226,     8,   226,   157,    -1,
     106,    -1,   113,     4,    -1,   111,    -1,   112,     4,     6,
      -1,   107,   149,   226,   150,    -1,   108,    -1,    75,   228,
     156,   194,   157,    -1,    75,   156,   228,   155,   228,   155,
     226,   157,   156,   194,   157,    -1,    75,   156,   228,   155,
     228,   155,   228,   155,   226,   157,   156,   194,   157,    -1,
      -1,    75,   228,   156,   194,   202,   215,   157,    -1,    -1,
      75,   156,   228,   155,   228,   155,   226,   157,   156,   194,
     203,   215,   157,    -1,    -1,    75,   156,   228,   155,   228,
     155,   228,   155,   226,   157,   156,   194,   204,   215,   157,
      -1,    -1,    75,   156,   194,   205,   215,   157,    -1,    75,
      47,   156,   226,   155,   228,   157,     6,    -1,    75,    50,
     156,   226,   155,   228,   157,     6,    -1,    75,    53,   156,
     226,   155,   228,   157,     6,    -1,    75,    47,   156,   226,
     155,   228,   155,   228,   155,   226,   157,     6,    -1,    75,
      50,   156,   226,   155,   228,   155,   228,   155,   226,   157,
       6,    -1,    75,    53,   156,   226,   155,   228,   155,   228,
     155,   226,   157,     6,    -1,    75,    47,   156,   226,   155,
     228,   155,   228,   155,   228,   155,   226,   157,     6,    -1,
      75,    50,   156,   226,   155,   228,   155,   228,   155,   228,
     155,   226,   157,     6,    -1,    75,    53,   156,   226,   155,
     228,   155,   228,   155,   228,   155,   226,   157,     6,    -1,
      -1,    75,    47,   156,   226,   155,   228,   157,   206,   156,
     215,   157,     6,    -1,    -1,    75,    50,   156,   226,   155,
     228,   157,   207,   156,   215,   157,     6,    -1,    -1,    75,
      53,   156,   226,   155,   228,   157,   208,   156,   215,   157,
       6,    -1,    -1,    75,    47,   156,   226,   155,   228,   155,
     228,   155,   226,   157,   209,   156,   215,   157,     6,    -1,
      -1,    75,    50,   156,   226,   155,   228,   155,   228,   155,
     226,   157,   210,   156,   215,   157,     6,    -1,    -1,    75,
      53,   156,   226,   155,   228,   155,   228,   155,   226,   157,
     211,   156,   215,   157,     6,    -1,    -1,    75,    47,   156,
     226,   155,   228,   155,   228,   155,   228,   155,   226,   157,
     212,   156,   215,   157,     6,    -1,    -1,    75,    50,   156,
     226,   155,   228,   155,   228,   155,   228,   155,   226,   157,
     213,   156,   215,   157,     6,    -1,    -1,    75,    53,   156,
     226,   155,   228,   155,   228,   155,   228,   155,   226,   157,
     214,   156,   215,   157,     6,    -1,   216,    -1,   215,   216,
      -1,    84,   156,   226,   157,     6,    -1,    84,   156,   231,
     155,   231,   157,     6,    -1,    84,   156,   231,   155,   231,
     155,   231,   157,     6,    -1,    78,     6,    -1,    88,     6,
      -1,    88,    90,     6,    -1,    89,     6,    -1,    89,    90,
       6,    -1,    85,   149,   226,   150,     7,   231,    68,   226,
       6,    -1,    68,     4,   151,   226,   152,     6,    -1,    -1,
      68,     4,   226,    -1,    -1,     4,    -1,    -1,     7,   231,
      -1,    -1,     7,   226,    -1,    63,    50,   232,     7,   226,
     217,     6,    -1,    63,    53,   232,   219,   218,     6,    -1,
      59,    53,   156,   226,   157,     7,   231,     6,    -1,    63,
      55,   232,   219,     6,    -1,    91,   232,     6,    -1,    78,
      53,   232,   220,     6,    -1,    79,    53,   231,     7,   226,
       6,    -1,    67,    50,   231,     7,   231,     6,    -1,    67,
      53,   226,   156,   234,   157,     7,   226,   156,   234,   157,
       6,    -1,    47,   156,   234,   157,   105,    53,   156,   226,
     157,     6,    -1,    50,   156,   234,   157,   105,    53,   156,
     226,   157,     6,    -1,    50,   156,   234,   157,   105,    55,
     156,   226,   157,     6,    -1,    53,   156,   234,   157,   105,
      55,   156,   226,   157,     6,    -1,    82,     6,    -1,    82,
       4,     6,    -1,    82,    47,   156,   234,   157,     6,    -1,
     122,   149,   238,   150,     7,   156,   231,   155,   231,   157,
       6,    -1,   123,   149,   238,   150,     7,   156,   231,   155,
     231,   157,     6,    -1,   124,   149,   238,   150,     7,   156,
     231,   155,   231,   157,     6,    -1,   125,   149,   238,   150,
       7,   156,   231,   155,   231,   157,     6,    -1,   227,    -1,
     149,   226,   150,    -1,   140,   226,    -1,   139,   226,    -1,
     144,   226,    -1,   226,   140,   226,    -1,   226,   139,   226,
      -1,   226,   141,   226,    -1,   226,   142,   226,    -1,   226,
     143,   226,    -1,   226,   148,   226,    -1,   226,   135,   226,
      -1,   226,   136,   226,    -1,   226,   138,   226,    -1,   226,
     137,   226,    -1,   226,   134,   226,    -1,   226,   133,   226,
      -1,   226,   132,   226,    -1,   226,   131,   226,    -1,   226,
     130,   226,     8,   226,    -1,    14,   149,   226,   150,    -1,
      15,   149,   226,   150,    -1,    16,   149,   226,   150,    -1,
      17,   149,   226,   150,    -1,    18,   149,   226,   150,    -1,
      19,   149,   226,   150,    -1,    20,   149,   226,   150,    -1,
      21,   149,   226,   150,    -1,    22,   149,   226,   150,    -1,
      24,   149,   226,   150,    -1,    25,   149,   226,   155,   226,
     150,    -1,    26,   149,   226,   150,    -1,    27,   149,   226,
     150,    -1,    28,   149,   226,   150,    -1,    29,   149,   226,
     150,    -1,    30,   149,   226,   150,    -1,    31,   149,   226,
     150,    -1,    32,   149,   226,   155,   226,   150,    -1,    33,
     149,   226,   155,   226,   150,    -1,    34,   149,   226,   155,
     226,   150,    -1,    23,   149,   226,   150,    -1,    14,   151,
     226,   152,    -1,    15,   151,   226,   152,    -1,    16,   151,
     226,   152,    -1,    17,   151,   226,   152,    -1,    18,   151,
     226,   152,    -1,    19,   151,   226,   152,    -1,    20,   151,
     226,   152,    -1,    21,   151,   226,   152,    -1,    22,   151,
     226,   152,    -1,    24,   151,   226,   152,    -1,    25,   151,
     226,   155,   226,   152,    -1,    26,   151,   226,   152,    -1,
      27,   151,   226,   152,    -1,    28,   151,   226,   152,    -1,
      29,   151,   226,   152,    -1,    30,   151,   226,   152,    -1,
      31,   151,   226,   152,    -1,    32,   151,   226,   155,   226,
     152,    -1,    33,   151,   226,   155,   226,   152,    -1,    34,
     151,   226,   155,   226,   152,    -1,    23,   151,   226,   152,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   119,
      -1,   120,    -1,   121,    -1,     4,    -1,     4,   158,   156,
     226,   157,    -1,     4,   151,   226,   152,    -1,   154,     4,
     151,   152,    -1,     4,   182,    -1,     4,   151,   226,   152,
     182,    -1,     4,   153,     4,    -1,     4,   151,   226,   152,
     153,     4,    -1,     4,   153,     4,   182,    -1,     4,   151,
     226,   152,   153,     4,   182,    -1,   116,   149,   238,   155,
     226,   150,    -1,   229,    -1,   140,   228,    -1,   139,   228,
      -1,   228,   140,   228,    -1,   228,   139,   228,    -1,   156,
     226,   155,   226,   155,   226,   155,   226,   155,   226,   157,
      -1,   156,   226,   155,   226,   155,   226,   155,   226,   157,
      -1,   156,   226,   155,   226,   155,   226,   157,    -1,   149,
     226,   155,   226,   155,   226,   150,    -1,   231,    -1,   230,
     155,   231,    -1,   226,    -1,   233,    -1,   156,   157,    -1,
     156,   234,   157,    -1,   140,   156,   234,   157,    -1,   226,
     141,   156,   234,   157,    -1,   231,    -1,     5,    -1,   140,
     233,    -1,   226,   141,   233,    -1,   226,     8,   226,    -1,
     226,     8,   226,     8,   226,    -1,    47,   156,   226,   157,
      -1,    47,     5,    -1,    50,     5,    -1,    53,     5,    -1,
      55,     5,    -1,   192,    -1,   201,    -1,     4,   151,   152,
      -1,     4,   151,   156,   234,   157,   152,    -1,   226,    -1,
     233,    -1,   234,   155,   226,    -1,   234,   155,   233,    -1,
     156,   226,   155,   226,   155,   226,   155,   226,   157,    -1,
     156,   226,   155,   226,   155,   226,   157,    -1,     4,    -1,
       4,   153,   102,   153,     4,    -1,   156,   237,   157,    -1,
       4,   151,   226,   152,   153,   103,    -1,   235,    -1,   237,
     155,   235,    -1,   239,    -1,     4,    -1,     4,   153,     4,
      -1,     4,   151,   226,   152,   153,     4,    -1,     5,    -1,
      42,    -1,   117,   149,   238,   150,    -1,   118,   149,   238,
     155,   238,   150,    -1,    37,   149,   238,   155,   238,   150,
      -1,    38,   149,   238,   150,    -1,    39,   149,   238,   150,
      -1,    36,   149,   238,   150,    -1,    36,   149,   238,   155,
     234,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   160,   160,   161,   166,   168,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   192,   196,   203,   208,   222,   235,   263,
     277,   288,   303,   308,   309,   310,   311,   312,   316,   318,
     323,   325,   331,   435,   330,   453,   460,   471,   470,   488,
     495,   506,   505,   522,   539,   562,   561,   575,   576,   577,
     578,   579,   583,   584,   591,   617,   644,   684,   694,   702,
     712,   724,   736,   745,   751,   760,   778,   796,   805,   817,
     822,   830,   850,   873,   882,   890,   912,   935,   963,   975,
     992,   996,  1007,  1010,  1023,  1026,  1036,  1060,  1059,  1079,
    1101,  1119,  1140,  1158,  1188,  1218,  1236,  1254,  1280,  1297,
    1316,  1315,  1338,  1356,  1395,  1401,  1407,  1414,  1439,  1464,
    1480,  1497,  1529,  1528,  1552,  1570,  1587,  1604,  1603,  1629,
    1634,  1639,  1644,  1649,  1672,  1678,  1689,  1690,  1695,  1698,
    1702,  1725,  1748,  1771,  1799,  1820,  1843,  1864,  1886,  1906,
    2018,  2037,  2063,  2172,  2181,  2187,  2202,  2230,  2247,  2261,
    2267,  2273,  2282,  2296,  2338,  2355,  2370,  2389,  2401,  2425,
    2429,  2436,  2442,  2447,  2453,  2457,  2461,  2471,  2488,  2505,
    2524,  2543,  2573,  2581,  2587,  2594,  2598,  2607,  2615,  2623,
    2632,  2631,  2645,  2644,  2658,  2657,  2671,  2670,  2683,  2690,
    2697,  2704,  2711,  2718,  2725,  2732,  2739,  2747,  2746,  2759,
    2758,  2771,  2770,  2783,  2782,  2795,  2794,  2807,  2806,  2819,
    2818,  2831,  2830,  2843,  2842,  2858,  2861,  2867,  2876,  2896,
    2919,  2923,  2927,  2931,  2935,  2939,  2958,  2971,  2974,  2990,
    2993,  3006,  3009,  3015,  3018,  3025,  3081,  3151,  3156,  3223,
    3259,  3302,  3327,  3354,  3398,  3421,  3444,  3447,  3456,  3460,
    3470,  3507,  3544,  3580,  3615,  3655,  3656,  3657,  3658,  3659,
    3660,  3661,  3662,  3663,  3670,  3671,  3672,  3673,  3674,  3675,
    3676,  3677,  3678,  3679,  3680,  3681,  3682,  3683,  3684,  3685,
    3686,  3687,  3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,
    3696,  3697,  3698,  3699,  3700,  3701,  3703,  3704,  3705,  3706,
    3707,  3708,  3709,  3710,  3711,  3712,  3713,  3714,  3715,  3716,
    3717,  3718,  3719,  3720,  3721,  3722,  3723,  3732,  3733,  3734,
    3735,  3736,  3737,  3738,  3742,  3761,  3779,  3794,  3804,  3820,
    3838,  3843,  3848,  3858,  3868,  3876,  3880,  3884,  3888,  3892,
    3899,  3903,  3907,  3911,  3918,  3923,  3930,  3935,  3939,  3944,
    3948,  3956,  3967,  3971,  3983,  3991,  3999,  4006,  4017,  4037,
    4041,  4045,  4049,  4053,  4063,  4073,  4083,  4103,  4108,  4112,
    4116,  4128,  4132,  4144,  4151,  4161,  4165,  4180,  4185,  4192,
    4196,  4209,  4217,  4228,  4232,  4240,  4248,  4256,  4264,  4278,
    4292,  4296
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
  "tPrintf", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tBoundingBox", "tDraw", "tToday", "tSyncModel", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tPoint", "tCircle",
  "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface", "tSpline",
  "tVolume", "tCharacteristic", "tLength", "tParametric", "tElliptic",
  "tRefineMesh", "tPlane", "tRuled", "tTransfinite", "tComplex",
  "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tLoop", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tLayers", "tHole", "tAlias",
  "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tField", "tReturn", "tCall", "tFunction", "tShow",
  "tHide", "tGetValue", "tGetEnv", "tGetString", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tHomRank", "tHomGen",
  "tHomCut", "tHomSeq", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "Affectation", "PhysicalId", "InSphereCenter",
  "CircleOptions", "Shape", "$@6", "$@7", "$@8", "$@9", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "Transfinite", "Periodic", "Embedding", "Coherence", "Homology", "FExpr",
  "FExpr_Single", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", 0
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
     184,   184,   185,   185,   186,   186,   187,   188,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     189,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   190,   187,   187,   187,   187,   191,   187,   192,
     192,   192,   192,   192,   192,   192,   193,   193,   194,   194,
     194,   194,   194,   194,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   196,   196,   196,   196,   196,   197,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   201,   201,   201,
     202,   201,   203,   201,   204,   201,   205,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   206,   201,   207,
     201,   208,   201,   209,   201,   210,   201,   211,   201,   212,
     201,   213,   201,   214,   201,   215,   215,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   221,   221,   221,   221,   221,
     221,   221,   222,   222,   223,   223,   223,   223,   224,   224,
     224,   225,   225,   225,   225,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   228,   228,   228,
     229,   229,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   234,   234,
     234,   235,   235,   235,   235,   236,   236,   237,   237,   238,
     238,   238,   238,   239,   239,   239,   239,   239,   239,   239,
     239,   239
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
       1,     1,     1,     1,     4,     7,     9,     6,     6,     6,
       3,     6,     4,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     9,     9,    11,     9,     9,
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
       6,    11,    11,    11,    11,     1,     3,     2,     2,     2,
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
       2,     2,     2,     1,     1,     3,     6,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     3,     6,     1,     1,     4,     6,     6,     4,     4,
       4,     6
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
       0,     0,     0,     0,     0,     0,     0,     0,   181,     0,
     186,     0,     0,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     7,     6,     8,     9,    10,    21,    11,
      12,    13,    20,    19,    14,    15,    16,    17,    18,    22,
     327,   334,   393,    57,   328,   329,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,     0,     0,   331,   332,   333,
      61,    60,    59,    58,     0,     0,     0,    63,    62,     0,
       0,     0,     0,   138,     0,     0,     0,   265,     0,     0,
       0,     0,   171,     0,   173,   170,   174,   175,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,    97,   110,   122,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,   258,     0,     0,
       0,     0,   334,   363,     0,     0,     0,     0,     0,     0,
     373,   374,   356,   362,     0,   357,     0,     0,     0,     0,
     383,     0,     0,     0,     0,     0,   169,     0,     0,   182,
       0,   138,     0,   138,     0,     0,     0,     0,     0,     0,
       0,     0,   338,    32,   393,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   334,   268,   267,   269,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,   136,     0,    70,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   114,     0,     0,     0,     0,     0,   377,   378,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,   346,     0,     0,     0,     0,   138,   138,
       0,     0,     0,     0,     0,     0,     0,   196,     0,   138,
       0,     0,     0,     0,     0,   243,     0,     0,     0,   156,
       0,     0,     0,   259,     0,     0,     0,     0,     0,   369,
       0,   370,   371,   372,     0,   267,   364,   358,     0,     0,
       0,   249,   168,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,   184,   159,     0,   160,     0,   390,     0,
     389,     0,     0,     0,     0,     0,   340,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,   133,     0,     0,     0,     0,   139,    64,
       0,   283,   282,   281,   280,   276,   277,   279,   278,   271,
     270,   272,   273,   274,   275,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,   349,   348,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   153,     0,     0,     0,     0,   375,     0,     0,
       0,     0,   359,   366,     0,   272,   365,     0,     0,     0,
       0,     0,     0,     0,     0,   185,     0,   161,   162,     0,
       0,     0,     0,     0,     0,     0,   336,   342,     0,    42,
       0,     0,     0,    55,     0,    33,    34,    35,    36,    37,
     285,   306,   286,   307,   287,   308,   288,   309,   289,   310,
     290,   311,   291,   312,   292,   313,   293,   314,   305,   326,
     294,   315,     0,     0,   296,   317,   297,   318,   298,   319,
     299,   320,   300,   321,   301,   322,     0,     0,     0,     0,
       0,     0,   400,     0,     0,   398,   399,    83,     0,   395,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   337,     0,     0,     0,
       0,     0,    25,    23,     0,     0,     0,     0,   379,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,   242,   240,
       0,   248,     0,     0,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,   187,     0,     0,     0,     0,     0,     0,
     244,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,   368,   360,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,   391,     0,     0,
       0,     0,     0,     0,   339,     0,   335,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    69,    68,     0,     0,
       0,     0,     0,    71,    73,    75,     0,     0,   387,     0,
      81,     0,     0,     0,     0,   284,    24,     0,     0,     0,
       0,     0,    94,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   230,     0,     0,   231,     0,   233,     0,   197,   226,
       0,     0,     0,   151,     0,     0,     0,   251,     0,   155,
     154,   260,     0,    30,    31,     0,   367,   361,     0,     0,
       0,   384,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,   165,   341,   164,     0,     0,     0,     0,
     354,     0,   295,   316,   302,   323,   303,   324,   304,   325,
     401,   397,   344,   396,     0,    57,     0,     0,     0,     0,
      65,     0,     0,     0,   385,     0,     0,     0,     0,    26,
      27,     0,     0,    96,     0,     0,     0,     0,     0,   100,
       0,     0,   117,   118,     0,     0,   102,   125,     0,     0,
       0,    92,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,     0,   138,     0,
     207,     0,   209,     0,   211,     0,   356,     0,     0,   232,
     234,     0,     0,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   376,   105,   106,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,   343,     0,    38,
       0,     0,     0,     0,     0,    40,     0,     0,     0,    78,
       0,     0,    79,     0,   388,   140,   141,   142,   143,     0,
       0,     0,    95,   103,   104,   108,     0,     0,   119,     0,
       0,   247,   112,     0,     0,   238,   124,     0,     0,     0,
       0,   109,     0,   120,   126,     0,     0,     0,     0,   353,
       0,   352,     0,     0,   198,     0,     0,   199,     0,     0,
     200,     0,     0,     0,     0,     0,     0,     0,   150,     0,
       0,   149,     0,     0,     0,   144,     0,     0,     0,     0,
     382,     0,   179,   178,     0,     0,     0,   392,     0,     0,
       0,     0,    43,     0,     0,     0,   355,     0,     0,     0,
      66,    74,    76,     0,    82,     0,    28,     0,     0,     0,
       0,     0,     0,     0,   113,    98,   111,   123,   128,     0,
       0,    88,    89,   138,     0,   132,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,   138,     0,     0,     0,
       0,     0,   135,   134,     0,     0,     0,     0,    85,    86,
       0,     0,     0,     0,     0,    39,     0,     0,     0,    41,
      56,     0,   386,     0,   254,   255,   256,   257,   116,     0,
       0,     0,     0,     0,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   192,     0,
       0,   145,     0,     0,     0,   381,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,   130,     0,   213,     0,     0,   215,     0,     0,   217,
       0,     0,     0,   228,     0,   188,     0,   138,     0,     0,
       0,   107,    87,   261,   262,   263,   264,     0,    47,     0,
      53,     0,     0,    93,   121,   253,   350,   201,     0,     0,
     208,   202,     0,     0,   210,   203,     0,     0,   212,     0,
       0,     0,   194,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,   221,     0,   223,   229,   235,
     193,   189,     0,     0,     0,     0,    44,     0,    51,     0,
       0,     0,   204,     0,     0,   205,     0,     0,   206,     0,
       0,   152,     0,   146,     0,    45,     0,     0,   172,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
       0,   214,     0,   216,     0,   218,     0,   147,    46,    48,
       0,    49,     0,     0,     0,     0,     0,     0,    54,   220,
     222,   224,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,   744,    73,    74,   468,  1088,  1094,
     665,   847,  1244,  1394,   666,  1358,  1420,   667,  1396,   668,
     669,   851,   144,   262,    75,   773,  1124,  1016,   538,   380,
     381,   382,   383,   230,   330,   331,    78,    79,    80,    81,
      82,    83,   231,   804,  1316,  1372,   607,  1145,  1148,  1151,
    1338,  1342,  1346,  1383,  1386,  1389,   800,   801,   910,   770,
     581,   616,    85,    86,    87,    88,    89,   232,   147,   393,
     198,   979,   980,   234,   235,   438,   242,   735,   879,   459,
     460
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1023
static const yytype_int16 yypact[] =
{
    3479,    33,    53,  3593, -1023, -1023,  1396,    86,    41,   -46,
      -5,   111,   139,   144,   180,  -113,   -36,    51,   -56,    66,
      76,   -42,    87,    91,   188,   196,   199,   212,   204,   250,
     310,   260,    -9,   435,    -3,   222,   303,   235,   -54,   -54,
     247,   421,    36,   360,   373,   380,     5,    25,   399,   446,
     475,  1950,   485,   377,   414,   426,    14,    24, -1023,   445,
   -1023,   503,   362, -1023,   525,   528,     0,    10,   448,   453,
     458,   463, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023,    21,   382,   481, -1023, -1023, -1023,   -61,    55,   107,
     239,   261,   276,   359,   415,   418,   425,   444,   454,   457,
     470,   490,   491,   516,   545,   546,   557,   564,   466,   474,
     477,   484, -1023,   549,   495,   500,   506, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,  3290,  3290,  3290, -1023, -1023,  3290,
     776,     7,   626,   383,  3290,   646,  1137, -1023,   652,   666,
    3290,   674, -1023,  3290, -1023, -1023, -1023, -1023,  3290,  3215,
    3290,  3290,   560,  3290,  3215,  3290,  3290,   561,  3215,  3290,
    3290,  2246,   565,   543, -1023,   579,   580,  1950,  1950,  1950,
     597, -1023, -1023, -1023, -1023,   603,   604,   614,  2246,  3290,
     754,  2246,   -54,   -54,   -54,  3290,  3290,   -83, -1023,    81,
     -54,   615,   620,   621,  3067,   103,   -88,   618,   639,   640,
    1950,  2246,   663,    26,   664, -1023,   813, -1023,   678,   679,
     687,   688,   478, -1023,    22,   844,   859,   862,  2394,  1795,
   -1023, -1023,   864, -1023,   884, -1023,   887,  3290,  3290,  3290,
     741,  3290,   742,   794,  3290,  3290, -1023,  3290,   923, -1023,
     934, -1023,   938, -1023,   347,   347,   347,   347,   803,  3290,
     877,   789, -1023, -1023, -1023,   949,  3290,  3290,  3290,  3290,
    3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,
    3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,
    3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,
    3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,   347,   347,
     347,   347,  3290,   347,   347,   347,   515,   814,   814,   814,
    5884,    63,  3215,  5125,   101,   823,   973,   831,   828, -1023,
     829,  3673,  1240, -1023, -1023,  3290,  3290,  3290,  3290,  3290,
    3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,  3290,
   -1023, -1023,  1434,   -76,  4423,  5905,  3215,  3013, -1023,   274,
    5926,  5947,  3290,  5968,   562,  5989,  6010,  3290,   567,  6031,
    6052,   978,  3290,  3290,  3290,  3290,   980,   981,   981,  3290,
     840,   842,   843,   860,  3290,  3290,  3290,  1003,  4343,   861,
    1007,   -28, -1023, -1023,  4449,  4475,   -54,   -54,   383,   383,
     207,  3290,  3290,  3290,  3067,  3067,  3290,  3673,   209, -1023,
    3290,  3290,  3290,  3290,  3290,  1009,  1011,  3290,  1015, -1023,
    3290,  3290,   804, -1023,  3215,  3215,  3290,  3290,  2913, -1023,
    3290, -1023, -1023, -1023,  3215,   814, -1023, -1023,   568,  3290,
    2542, -1023, -1023,  6073,  6094,  6115,   920,  4501, -1023,   869,
    3060,  6136,  5148, -1023, -1023,  1136, -1023,  1834,   588,   878,
   -1023,   879,   881,   883,  3290,  5171,   -10,  3290,    12, -1023,
    6157,  5194,  6178,  5217,  6199,  5240,  6220,  5263,  6241,  5286,
    6262,  5309,  6283,  5332,  6304,  5355,  6325,  5378,  6346,  5401,
    6367,  5424,  4527,  4553,  6388,  5447,  6409,  5470,  6430,  5493,
    6451,  5516,  6472,  5539,  6493,  5562,  4579,  4605,  4631,  4657,
    4683,  4709,   -66,   882,   885,   889,  1473,   886,   890,   888,
    3290, -1023,  2246,  2246,  2246,   585,    -4,   481,  3290,  1024,
    1030,    15,   893, -1023,   -85,   -17,   -40,    -8, -1023, -1023,
    3209,  1549,  1308,   982,   982,   550,   550,   550,   550,   169,
     169,   814,   814,   814,   814, -1023,    48,  3215,  3290,  1039,
    3215,  3215,   942,  1041,  1043,  6514,  1045,   948,  1048,  1049,
    6535,   952,  1051,  1055,  3290,  6556,  3032,  6577,  6598,  3290,
    2246,  1063,  1062,  6619,  3357,  3357,  3357,  3357,  6640,  6661,
    6682,  2246,  3215,   916, -1023,   -54,  3290,  3290, -1023, -1023,
     913,   917,  3290,  4735,  4761,  4787,  4397,   456,   -54,  1989,
    6703,  3478,  6724,  6745,  6766,  3290,  1070,  3290,  6787, -1023,
    5585,  5608, -1023,   594,   602,  5631,  5654, -1023,  3215,  5677,
    3727,   611, -1023,  3283,  3215,   814, -1023,  1071,  1073,  1079,
     924,  3290,  2137,  3290,  3290, -1023,    27, -1023, -1023,  3290,
    1097,  1096,  1099,  1101,  1102,  5700,   609, -1023,  3755, -1023,
     961,   962,   956, -1023,  1107, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023,  3290,  3290, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,  3290,  3290,  3290,  3290,
    3290,  3290, -1023,  3215,   347, -1023, -1023, -1023,  3290, -1023,
     347,  1108,  1110,  1125,   983, -1023,    16,  3290,  1126,  1130,
    1611, -1023,  1131,   986,    14,  1134, -1023,  3215,  3215,  3215,
    3215,  3290, -1023,  1005,   347,   -29,  4813,   -54,  3013, -1023,
    1089,  2246,  2246,  1138,  2246,   728,  2246,  2246,  1139,  1092,
    2246,  2246,  1639,  1145,  1147,  1148,  1149,  3614, -1023, -1023,
    1151, -1023,  1152,  1008,  7018, -1023,  1010,  1012,  1014,  1154,
    1159,  1160,  1163,   627,  1166,   215,  4839,  4865, -1023, -1023,
    3783,   -54,   -54,   -54,  1167,  1169,  1016,  1029,     6,    11,
     -26, -1023,   219, -1023,   456,  1172,  1174,  1188,  1189,  1192,
    7018, -1023,  2496,  1017,  1175,  1197,  1199,  1155,  1201,  1205,
     669,   161, -1023, -1023,  3290,   689,  2246,  2246,  2246,  1209,
    4891, -1023,  3317,   957,  1211,  1213,  5723, -1023,  1065,  1066,
    1067,  1069,  1212,  1215, -1023,  1220, -1023,  1078,  3290,  3290,
    2246,  1074, -1023,  6808,  5746,  6829,  5769,  6850,  5792,  6871,
    5815,   -15,  1081,  6892,  1082, -1023, -1023, -1023,    85,   198,
    1076,  1229,  2535, -1023, -1023, -1023,    14,  3290, -1023,   690,
   -1023,   693,   706,   721,   722,  7018, -1023,  1231,    49,  3290,
      42,  1083,  1181,  1181,  2246,  1237,  1088,  1093,  1244,  1245,
    2246,  1100,  1246,  1254, -1023,  1256,  2246,  2246,  2246,  1258,
    1257, -1023,  2246,  1259,  1275,  1276,  1277,  2246,  2246,  2246,
   -1023,  1280,   375,  3290,  3290,  3290,  1132,    62,    69,   165,
    1113, -1023,  2246,  3290, -1023,  1283, -1023,  1284, -1023, -1023,
    3067,   166,  2098, -1023,  1135,  1140,  2690, -1023,  3215, -1023,
   -1023, -1023,  1141, -1023, -1023,  1129,  7018, -1023,  1286,  1288,
    1198, -1023,  3290,  3290,  3290, -1023,  1294,  1295,  1150,  2246,
    2246,  2246,  2246, -1023,   -10, -1023,  3290,  4917,  4943,   725,
   -1023,  3290, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,  2246,   481,  3290,  1299,  1302,    15,
   -1023,  1301,  5838,    14, -1023,  1303,  1311,  1312,  1315, -1023,
   -1023,   347,  4969, -1023,  3290,   -54,  1316,  1318,  1319, -1023,
    3290,  3290, -1023, -1023,  1322,  3290, -1023, -1023,  1325,  1326,
    1328,  1230,  3290, -1023,  1330,  2246,  2246,  2246,  2246,  1332,
     880,  1333,  3290, -1023,  3357,  3811,  6913,  3643,   383,   -54,
    1334,   -54,  1335,   -54,  1337,  3290,   305,  1191,  6934, -1023,
   -1023,  3839,   237, -1023,  1338,  1646,  1341,  2246,   -54,  1646,
    1344,   730,  3290, -1023, -1023, -1023,  2246,  3671,   364,  6955,
   -1023,  2986,  1347,  1202,  1206,  1210,  1214, -1023,    38,  7018,
    3290,  3290,  2246,  1200,   734,  7018,  1348,  1354,  2644, -1023,
    1357,  1360, -1023,  1236, -1023, -1023, -1023, -1023, -1023,  1361,
    3290,  3867,   343, -1023, -1023, -1023,  3895,  3923, -1023,  3951,
    1379, -1023, -1023,  1339,  1385,  7018, -1023,  1386,  1387,  1388,
    1389, -1023,  1241, -1023, -1023,  4370,  2683,  1390,  1242, -1023,
    3290, -1023,  1247,   254, -1023,  1252,   277, -1023,  1281,   312,
   -1023,  1304,  5861,  1430,  2246,  1395,  1305,  3290, -1023,  2838,
     336, -1023,   749,   338,   376, -1023,  1433,  3979,  1355,  3290,
   -1023,  3290, -1023, -1023,  3215,  2831,  1451, -1023,  2246,  2246,
    2246,  2246, -1023,  3290,  4995,  5021, -1023,  2246,  3290,  1457,
   -1023, -1023, -1023,    14, -1023,  1367, -1023,  5047,  1458,  1468,
    1469,  1474,  1475,  1327, -1023, -1023, -1023, -1023, -1023,  2246,
    3215, -1023, -1023,   383,  3699, -1023,  3067,   456,  3067,   456,
    3067,   456,  1476, -1023,   750,  2246, -1023,  4007,   -54,  1478,
    3215,   -54, -1023, -1023,  3290,  4035,  4063,   753, -1023, -1023,
    1329,  1331,  1336,  1340,  1343,  7018,  3290,  3290,   756,  7018,
   -1023,  1479, -1023,  3290, -1023, -1023, -1023, -1023, -1023,  3290,
     757,   766,  1345,  3290, -1023,  4091,   388,   586,  4119,   407,
     676,  4147,   410,   743, -1023,  2246,  1481,  1421,  2285,  1351,
     432, -1023,   767,   449,  2908, -1023, -1023,  1484,  1486,  1488,
    1489,  1497,  3290,  6976,  5073,    20, -1023,  5099,  4175,  1498,
    1503, -1023,  4203,  1504,  3290,  1512,  1513,  3290,  1514,  1515,
    3290,  1520,  1370, -1023,  3290, -1023,   456, -1023,  3215,  1526,
    2838, -1023, -1023, -1023, -1023, -1023, -1023,   778, -1023,  3290,
   -1023,  2246,  3290, -1023, -1023, -1023, -1023, -1023,  1377,  4231,
   -1023, -1023,  1378,  4259, -1023, -1023,  1381,  4287, -1023,  1532,
    2979,   752,  2433,   781, -1023,   461,   782,  1533,  1398,  6997,
     811,  4315,   456,  1538,   456,  1540,   456,  1545, -1023, -1023,
   -1023, -1023,   456,  1550,  3215,  1551, -1023,   347, -1023,  1399,
    1552,   863, -1023,  1403,   875, -1023,  1404,   976, -1023,  1405,
    1170, -1023,   812, -1023,   816, -1023,  1406,  2246, -1023,  1572,
     456,  1573,   456,  1574,   456, -1023,  1575,   347,  1577,   347,
     817, -1023,  1274, -1023,  1384, -1023,  1554, -1023, -1023, -1023,
     822, -1023,  1578,  1579,  1580,  1581,   347,  1582, -1023, -1023,
   -1023, -1023, -1023, -1023
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1023, -1023, -1023, -1023,   701, -1023, -1023, -1023, -1023,   298,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023,  -310,     4, -1023,  -390, -1023,   698,  1589, -1023,
   -1023, -1023, -1023,     3,  -391,  -202, -1023, -1023, -1023, -1023,
   -1023, -1023,  1590, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,  -684,  -731, -1023, -1023,
    1223, -1023, -1023, -1023, -1023, -1023, -1023,    -6, -1023,   280,
   -1023, -1022,   559,  -112,   389,    35,  -701,   599, -1023,  -233,
      -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     146,   152,   407,   725,   148,   250,    77,   600,   601,   213,
     145,   324,   934,   422,   528,   252,   659,   936,   240,   733,
     869,   162,   461,   462,   463,   258,  1330,   429,   243,   216,
     418,   217,   419,   878,   834,   167,   158,   167,   181,     4,
     206,   182,   794,   159,   183,  1162,   184,   188,  1013,   455,
     189,   457,   795,     5,   742,  1010,   396,   397,   796,   797,
     162,   410,   798,   799,   158,   376,   377,   378,   411,   939,
     522,   737,   218,   398,   556,   512,   513,   514,   515,   557,
     517,   518,   519,   207,   712,   193,   194,   208,   266,   713,
     267,   265,   725,   163,   150,   195,   935,   209,   415,   149,
     164,   937,   196,   151,   660,   661,   662,   663,   527,   325,
     326,   396,   397,   160,   168,   214,   739,   154,   870,   871,
     941,   888,   130,   131,   132,   133,   561,   595,   317,   318,
     319,   938,   163,   320,   323,   990,   137,   138,   332,   738,
     561,   170,   137,   138,   352,   155,   329,   354,   740,   726,
     156,   153,   355,   357,   360,   361,   251,   363,   357,   365,
     366,   215,   357,   369,   370,  1248,   253,   137,   138,   664,
     241,   734,   259,   244,   260,  1001,  1331,   420,   430,   261,
     835,   396,   397,   388,   743,   743,   157,  1260,  1182,   394,
     395,   523,   524,  1183,   359,   776,   777,   778,   395,   364,
     161,   396,   397,   368,   268,   995,   269,   609,   396,   397,
     939,   130,   131,   132,   133,   165,   727,  1049,   174,  1050,
     396,   397,   435,   357,  1051,   166,  1052,   130,   131,   132,
     133,   443,   444,   445,   794,   447,   169,   399,   450,   451,
     170,   452,   396,   397,   795,   171,   642,   137,   138,   172,
     796,   797,   173,   465,   798,   799,   270,   175,   271,   409,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,  1104,   176,   396,   397,   516,   137,   138,  1360,
     346,   347,   348,   439,   843,   180,   357,   349,   197,   199,
    1053,   205,  1054,  1063,   130,   131,   132,   133,   529,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   137,   138,   396,   397,   396,   397,
     435,   458,   264,   191,   396,   397,   565,   525,   396,   397,
     177,   570,   602,   178,   608,   179,   575,   576,   577,   578,
     923,   190,  1171,   583,   940,  1410,   396,   397,   588,   589,
     590,  1043,  1044,   118,   119,   120,   121,   328,   272,   122,
     273,   192,  1157,   396,   397,   603,   604,   605,   317,   318,
     606,   329,   329,   200,   610,   611,   612,   613,   614,  1216,
     274,   618,   275,   210,   620,   621,   396,   397,   357,   357,
     625,   626,   629,   845,   630,   276,   211,   277,   357,   561,
     212,   562,  1218,   633,   635,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   440,   347,   348,   219,
     220,   396,   397,   349,    37,    38,    39,    40,   655,   623,
     624,   658,  1153,    45,   125,   126,    48,  1220,   201,   631,
     657,   202,   391,   392,   203,   396,   397,   396,   397,   221,
     400,   862,   396,   397,   408,   185,   264,   864,   186,   236,
     187,  1228,  1251,  1230,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   278,   246,
     279,   887,   349,   247,   629,   396,   397,   118,   119,   120,
     121,  1172,   730,   122,   794,   729,   237,   396,   397,   248,
     728,  1231,   249,  1267,   795,  1270,   939,  1273,   263,   939,
     796,   797,   939,  1304,   798,   799,   396,   397,   358,   396,
     397,   357,   746,   358,   635,   748,   312,   358,   994,   996,
     193,   194,  1307,   238,   280,  1310,   281,   282,   762,   283,
     195,   396,   397,   767,   284,   239,   285,   204,   774,   774,
     774,   774,   775,   775,   775,   775,   357,  1318,   396,   397,
     786,   787,   745,   286,   245,   287,   790,   254,   125,   126,
     396,   397,   255,   288,  1320,   289,   290,   256,   291,   810,
     233,   812,   257,   458,   264,   308,  1374,   436,   358,   292,
     939,   293,   357,   309,   137,   138,   310,   783,   357,   428,
     327,   260,  1351,   311,   143,   830,   261,   832,   833,   294,
     296,   295,   297,   836,   313,   118,   119,   120,   121,   314,
     939,   122,   333,   939,   794,   315,   939,  1142,   350,   939,
     844,   137,   138,   820,   795,   298,   520,   299,   260,   825,
     796,   797,   351,   261,   798,   799,   598,   599,  1381,   353,
    1384,   939,  1387,   939,   392,   939,   853,   854,  1390,   344,
     345,   346,   347,   348,   300,   302,   301,   303,   349,   373,
     855,   856,   857,   858,   859,   860,   304,   357,   305,   362,
     367,   358,   863,   306,   372,   307,  1412,   561,  1414,   567,
    1416,   872,   561,   561,   571,   632,   125,   126,   374,   375,
     371,   357,   357,   357,   357,   885,   233,   233,   233,   649,
     561,   650,   724,  1305,   794,   436,   379,   387,   861,   561,
     390,   816,   384,   385,   795,   137,   138,   561,   389,   817,
     796,   797,   843,   386,   798,   799,   561,   412,   823,   233,
     416,   401,   881,   882,   883,   884,   402,   403,  1109,    90,
     316,   896,   561,   897,   921,    94,    95,    96,   413,   414,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   794,   417,   358,   358,   421,     7,     8,   956,   423,
     794,   795,  1262,   358,   561,   844,   955,   796,   797,   636,
     795,   798,   799,  1308,   424,   425,   796,   797,   426,   427,
     798,   799,   977,   978,   561,  1003,   957,  1004,   561,   431,
    1005,   534,    16,    17,   535,    19,    20,   536,    22,   537,
      24,   561,    25,  1006,   432,    28,    29,   433,    31,    32,
      33,  1002,   439,   997,    36,   785,   561,   561,  1007,  1008,
    1092,   466,  1093,  1012,  1132,   561,  1133,  1166,   802,  1188,
     441,  1189,   124,   442,   446,   127,   128,   129,   448,   449,
    1311,    53,    54,    55,  1092,  1275,  1229,  1276,   561,  1370,
    1287,  1092,  1092,  1295,  1299,   134,   135,  1045,  1046,  1047,
     136,   561,   561,  1300,  1319,   139,  1056,  1058,   321,   453,
     142,   794,   322,  1188,  1061,  1357,   561,   561,  1373,  1375,
     454,   795,   357,   794,   456,   467,   358,   796,   797,   636,
     749,   798,   799,   795,   464,   469,  1077,  1078,  1079,   796,
     797,   622,   349,   798,   799,   964,  1092,   561,  1379,  1406,
    1089,  1407,  1092,  1408,  1422,  1095,   530,  1426,  1087,  1427,
     531,   358,   532,  1071,   143,   574,   533,   579,   580,   584,
    1098,   585,   586,  1097,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   440,   347,   348,  1111,   587,
     591,   593,   349,   594,  1116,  1117,   615,   358,   617,  1119,
    1399,   619,   640,   358,  1278,   643,  1125,   890,   651,   652,
     731,   653,  1401,   654,   732,   715,  1135,   714,  1136,   716,
     719,   718,  1137,   720,   794,   736,   747,   750,   751,  1152,
     752,   329,   754,   755,   795,   756,   757,   759,   760,   357,
     796,   797,   761,   357,   798,   799,  1167,   769,   771,   784,
     788,   927,   928,   929,   789,  1175,   811,   829,   826,  1176,
     827,   721,   722,   723,  1184,  1185,   828,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   837,   358,   838,  1197,   349,   839,   965,   840,   841,
     848,   849,   850,   852,   865,  1352,   866,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   358,   358,   358,   358,
     349,   867,   873,  1403,  1214,   868,   874,   877,   876,   768,
     880,   886,   891,   334,  1395,   894,   900,   901,     7,     8,
     782,  1227,   905,   435,   906,   907,   908,   911,   913,   912,
     914,   917,   915,  1235,   916,  1236,   918,   919,   357,   920,
     922,   930,   932,   948,  1418,   931,  1421,  1245,   933,   942,
     943,   949,  1249,   534,    16,    17,   535,    19,    20,   536,
      22,   537,    24,  1432,    25,   944,   945,    28,    29,   946,
      31,    32,    33,   950,   357,   951,    36,   953,   952,  1237,
    1265,   954,  1268,   961,  1271,   966,   329,   967,   973,   974,
    1062,   969,   970,   971,   357,   972,   975,   976,  1284,   998,
     981,   991,   993,    53,    54,    55,   999,  1009,   794,  1014,
    1293,  1294,  1015,  1019,  1020,  1261,   539,  1297,   795,  1021,
    1022,  1023,  1026,  1298,   796,   797,  1025,  1302,   798,   799,
    1027,  1028,  1032,  1033,  1055,  1282,  1035,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,  1073,  1036,  1037,  1038,   349,  1095,  1042,  1048,  1059,
    1060,  1067,  1074,   647,  1075,  1112,  1068,  1072,  1339,  1076,
    1080,  1343,  1081,  1082,  1347,  1099,  1100,  1102,  1350,  1105,
     892,   893,   357,   895,   357,   898,   899,  1106,  1107,   902,
     903,  1108,  1113,  1359,  1114,  1115,  1361,  1405,  1118,  1143,
    1120,  1146,  1121,  1149,  1122,  1123,  1126,   358,  1131,  1134,
    1144,  1147,   794,  1150,  1158,  1160,  1154,  1161,  1163,  1164,
    1165,  1177,   795,  1353,  1190,  1356,  1187,  1178,   796,   797,
    1191,  1179,   798,   799,  1193,  1180,  1194,  1196,   357,  1181,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,  1202,   958,   959,   960,   349,  1195,
    1203,  1204,  1205,  1206,  1207,  1208,  1212,  1209,  1213,    90,
      91,    92,  1225,    93,  1215,    94,    95,    96,  1217,  1392,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,  1423,   118,   119,   120,   121,  1223,  1219,   122,  1232,
     555,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   794,  1018,   358,  1234,   349,  1239,   358,  1024,
    1221,  1226,   795,  1250,  1254,  1029,  1030,  1031,   796,   797,
    1252,  1034,   798,   799,  1255,  1256,  1039,  1040,  1041,   717,
    1257,  1258,  1274,  1259,  1281,  1296,  1288,  1313,  1289,  1314,
    1322,  1057,  1323,  1290,  1324,  1325,  1266,  1291,  1269,  1292,
    1272,  1066,  1301,  1326,  1334,  1070,   123,  1317,  1280,  1335,
    1337,  1283,   124,   125,   126,   127,   128,   129,  1340,  1341,
    1344,  1345,   130,   131,   132,   133,  1348,  1349,  1083,  1084,
    1085,  1086,  1354,  1362,  1364,   134,   135,  1366,  1368,  1376,
     136,  1424,   137,   138,  1382,   139,  1385,   140,   436,   141,
     142,  1388,   143,  1096,  1377,  1397,  1391,  1393,  1398,  1400,
    1402,  1404,  1409,   358,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,  1411,  1413,
    1415,  1417,   349,  1419,  1428,  1429,  1430,  1431,  1433,  1011,
    1327,  1017,    76,    84,  1127,  1128,  1129,  1130,  1101,   358,
    1355,   582,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   875,     0,   358,
       0,   349,   794,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   795,     0,     0,  1168,     0,     0,   796,   797,
       0,     0,   798,   799,     0,   904,     0,     0,     0,    90,
     222,  1186,     0,     0,     0,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   224,     0,     0,   225,   349,     0,   226,
       0,   227,     0,     0,     0,     0,     0,   358,     0,   358,
       0,  1425,     0,  1224,     0,     0,     0,    37,    38,    39,
      40,    41,     0,     0,     0,     0,    45,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,  1240,  1241,  1242,
    1243,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,   124,   358,     0,   127,   128,   129,     0,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,  1277,   404,  1159,   349,     0,     0,
     136,     0,     0,     0,     0,   406,     0,     0,    90,   222,
     142,     0,   196,   437,    94,    95,    96,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,     0,  1312,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,   225,     7,     8,   226,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,     0,     0,     0,     0,    45,     0,     0,    48,     0,
       0,   534,    16,    17,   535,    19,    20,   536,    22,   537,
      24,     0,    25,     0,     0,    28,    29,     0,    31,    32,
      33,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,   124,     0,     0,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,   134,   356,     0,     0,     0,   136,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   142,
       0,     0,   437,    90,   222,   223,     0,     0,     0,    94,
      95,    96,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
       0,   648,     0,     0,     0,     0,     0,   224,     0,     0,
     225,     7,     8,   226,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,     0,     0,     0,     0,
      45,     0,     0,    48,     0,     0,   534,    16,    17,   535,
      19,    20,   536,    22,   537,    24,     0,    25,     0,     0,
      28,    29,     0,    31,    32,    33,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,   124,     0,     0,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,   134,
     228,     0,     0,     0,   136,     0,     0,     0,     0,   139,
       0,    90,   222,  1064,   142,     0,   229,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,   803,     0,   225,     7,
       8,   226,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,     0,     0,     0,     0,    45,     0,
       0,    48,     0,     0,   534,    16,    17,   535,    19,    20,
     536,    22,   537,    24,     0,    25,     0,     0,    28,    29,
       0,    31,    32,    33,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,   124,     0,     0,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,   134,   228,     0,
       0,     0,   136,     0,     0,     0,     0,   139,     0,    90,
     222,     0,   142,     0,  1065,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,   831,     0,   225,     7,     8,   226,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,     0,     0,     0,     0,    45,     0,     0,    48,
       0,     0,   534,    16,    17,   535,    19,    20,   536,    22,
     537,    24,     0,    25,     0,     0,    28,    29,     0,    31,
      32,    33,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,   124,     0,     0,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,   134,   228,     0,     0,     0,
     136,     0,     0,     0,     0,   139,     0,    90,   222,     0,
     142,     0,   229,    94,    95,    96,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,  1315,     0,   225,     7,     8,   226,     0,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
       0,     0,     0,     0,    45,     0,     0,    48,     0,     0,
     534,    16,    17,   535,    19,    20,   536,    22,   537,    24,
       0,    25,     0,     0,    28,    29,     0,    31,    32,    33,
       0,     0,   947,    36,     0,     0,     0,     0,     0,     0,
     124,     0,     0,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,   134,   356,     0,     0,     0,   136,     0,
       0,  1000,     0,   139,     0,    90,   222,     0,   142,     0,
     434,    94,    95,    96,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
    1371,     0,   225,     0,     0,   226,     0,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    38,    39,    40,    41,     0,     0,
       0,     0,    45,     0,     0,    48,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
    1192,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,   127,   128,   129,     0,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,   134,   356,   349,     0,     0,   136,     0,     0,  1211,
       0,   139,     0,    90,   222,     0,   142,     0,   634,    94,
      95,    96,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,     0,     0,
     225,     0,     0,   226,     0,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,     0,     0,     0,     0,
      45,     0,     0,    48,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,   127,
     128,   129,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,   134,
     228,   349,     0,     0,   136,     0,     0,  1238,     0,   139,
       0,    90,   222,     0,   142,     0,  1069,    94,    95,    96,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,     0,     0,   225,     0,
       0,   226,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,  1321,     0,    90,   316,    45,     0,
       0,    48,    94,    95,    96,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   124,     0,     0,   127,   128,   129,
       0,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,   404,  1159,   349,
       0,     0,   136,     0,     0,  1369,     0,   406,     0,    90,
     316,   264,   142,     0,   196,    94,    95,    96,     0,     0,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   439,   118,   119,   120,   121,     0,     0,   122,   124,
       0,     0,   127,   128,   129,     0,     0,     0,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   134,   135,     0,     0,   349,   136,     0,     0,
       0,     0,   139,     0,     0,   627,     0,   142,   644,   628,
      90,   316,     0,     0,     0,     0,    94,    95,    96,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   124,   125,   126,   127,   128,   129,     0,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,   134,   135,   349,     0,     0,
     136,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     142,     0,  1174,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   560,   347,   348,     0,     0,     0,
       0,   349,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,   124,     0,     0,   127,   128,   129,   764,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,   404,   405,   349,     0,
       0,   136,     0,     0,     0,     0,   406,   741,    90,   222,
       0,   142,     0,   196,    94,    95,    96,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,   225,     0,     0,   226,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,   824,     0,    90,   316,    45,     0,     0,    48,    94,
      95,    96,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   963,     0,     0,     0,     0,
       0,   124,     0,     0,   127,   128,   129,     0,     0,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,   134,   356,     0,   349,     0,   136,
      90,   316,   264,     0,   139,     0,    94,    95,    96,   142,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   118,   119,   120,   121,     0,     0,   122,
       0,     0,     0,     0,     0,     0,   124,     0,     0,   127,
     128,   129,     0,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,   134,
     135,   349,     0,     0,   136,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   142,     0,     0,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,   134,   135,     0,     0,
       0,   136,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   142,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     6,     0,     0,
       0,    -4,    -4,    -4,    -4,     7,     8,     0,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     9,     0,
       0,     0,     0,    10,    11,   806,    12,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,     0,   909,     0,    51,     7,     8,     0,     0,    52,
      53,    54,    55,     0,     0,    56,     0,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,     0,
     534,    16,    17,   535,    19,    20,   536,    22,   537,    24,
       0,    25,     0,     0,    28,    29,     0,    31,    32,    33,
       0,     0,     0,    36,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,  1140,     0,
    1141,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,  1169,     0,  1170,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,  1263,     0,  1264,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,   822,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,   846,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
     926,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,  1138,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,  1156,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,  1198,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,  1199,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
    1200,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,  1201,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,  1233,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,  1279,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,  1285,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
    1286,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,  1303,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,  1306,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,  1309,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,  1333,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
    1336,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,     0,     0,  1363,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,  1365,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,  1367,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,  1380,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,   592,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,     0,     0,  1210,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   521,     0,     0,
       0,     0,   596,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,   558,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,   596,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
     597,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,   641,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,   692,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,   693,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,   706,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
     707,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,   708,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,   709,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,   710,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,   711,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
     791,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,   792,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,   793,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,   889,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,   924,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
     925,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,   962,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,  1090,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,  1091,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,  1110,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
    1246,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,  1247,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,  1253,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,  1329,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,  1332,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   526,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
     646,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,   656,   335,   336,   337,   338,   339,   340,
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
       0,     0,   349,     0,     0,     0,   691,   335,   336,   337,
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
     349,     0,     0,     0,   705,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   814,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
     815,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,   818,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,     0,     0,   819,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,     0,     0,   821,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
       0,     0,   842,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,     0,     0,   968,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,     0,     0,   983,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,     0,
       0,   985,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,     0,     0,   987,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,     0,     0,   989,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,     0,     0,
    1103,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,     0,     0,  1222,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   521,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   559,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   563,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   564,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   566,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   568,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     569,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   572,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   573,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   637,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   638,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   639,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   645,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   670,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   672,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   674,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     676,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   678,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   680,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   682,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   684,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   686,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   688,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   690,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   694,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   696,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     698,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   700,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   702,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   704,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   753,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   758,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   763,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   765,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   766,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   772,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     779,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   780,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   781,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,   805,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,   807,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,   808,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,   809,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,   813,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349,     0,   982,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,     0,     0,     0,     0,   349,     0,   984,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,     0,     0,     0,     0,   349,     0,
     986,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,     0,     0,     0,     0,   349,
       0,   988,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,     0,     0,     0,     0,
     349,     0,   992,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,     0,     0,     0,
       0,   349,     0,  1139,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,     0,     0,
       0,     0,   349,     0,  1155,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,     0,
       0,     0,     0,   349,     0,  1173,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
       0,     0,     0,     0,   349,     0,  1328,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,     0,     0,     0,     0,   349,     0,  1378,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,     0,     0,     0,     0,   349
};

static const yytype_int16 yycheck[] =
{
       6,     6,   204,     7,     6,     5,     3,   398,   399,     4,
       6,     4,     6,   215,   324,     5,     4,     6,     4,     4,
       4,    77,   255,   256,   257,     4,     6,     5,     4,     4,
       4,     6,     6,   734,     7,    77,   149,    77,    47,     6,
       4,    50,    68,   156,    53,  1067,    55,    50,     6,   251,
      53,   253,    78,     0,     6,     6,   139,   140,    84,    85,
      77,   149,    88,    89,   149,   177,   178,   179,   156,   800,
       7,   156,    47,   156,   150,   308,   309,   310,   311,   155,
     313,   314,   315,    47,   150,   139,   140,    51,   149,   155,
     151,    93,     7,   149,    53,   149,    90,    61,   210,    13,
     156,    90,   156,   149,    92,    93,    94,    95,     7,   102,
     103,   139,   140,   149,   156,   110,   156,     6,   102,   103,
     804,   150,   126,   127,   128,   129,   155,   155,   134,   135,
     136,   157,   149,   139,   140,   150,   146,   147,   144,   156,
     155,   149,   146,   147,   150,     6,   143,   153,   156,   153,
       6,   156,   158,   159,   160,   161,   156,   163,   164,   165,
     166,   156,   168,   169,   170,  1187,   156,   146,   147,   157,
     156,   156,   151,   149,   153,   876,   156,   151,   156,   158,
     153,   139,   140,   189,   136,   136,     6,  1209,   150,   195,
     196,   128,   129,   155,   159,   585,   586,   587,   204,   164,
     149,   139,   140,   168,   149,     7,   151,   409,   139,   140,
     941,   126,   127,   128,   129,   149,   526,   155,     6,   157,
     139,   140,   228,   229,   155,   149,   157,   126,   127,   128,
     129,   237,   238,   239,    68,   241,   149,   156,   244,   245,
     149,   247,   139,   140,    78,    57,   448,   146,   147,    53,
      84,    85,    53,   259,    88,    89,   149,    53,   151,   156,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,  1003,    53,   139,   140,   312,   146,   147,  1331,
     141,   142,   143,     8,   153,    55,   322,   148,    38,    39,
     155,    41,   157,   157,   126,   127,   128,   129,   324,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   146,   147,   139,   140,   139,   140,
     356,     4,     5,    50,   139,   140,   362,   322,   139,   140,
      50,   367,   155,    53,   155,    55,   372,   373,   374,   375,
     155,   149,     8,   379,   155,  1397,   139,   140,   384,   385,
     386,     6,     7,    36,    37,    38,    39,     4,   149,    42,
     151,   156,   155,   139,   140,   401,   402,   403,   404,   405,
     406,   398,   399,   156,   410,   411,   412,   413,   414,   155,
     149,   417,   151,    53,   420,   421,   139,   140,   424,   425,
     426,   427,   428,   656,   430,   149,    53,   151,   434,   155,
      50,   157,   155,   439,   440,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    50,
       4,   139,   140,   148,    71,    72,    73,    74,   464,   424,
     425,   467,   157,    80,   117,   118,    83,   155,    47,   434,
     466,    50,   192,   193,    53,   139,   140,   139,   140,     4,
     200,   714,   139,   140,   204,    50,     5,   720,    53,     4,
      55,   155,  1193,   155,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   149,     6,
     151,   744,   148,   151,   520,   139,   140,    36,    37,    38,
      39,   157,   528,    42,    68,   527,   149,   139,   140,     4,
     526,   155,     4,  1217,    78,  1219,  1267,  1221,   156,  1270,
      84,    85,  1273,   155,    88,    89,   139,   140,   159,   139,
     140,   557,   558,   164,   560,   561,     7,   168,   868,   869,
     139,   140,   155,   149,   149,   155,   151,   149,   574,   151,
     149,   139,   140,   579,   149,   149,   151,   156,   584,   585,
     586,   587,   584,   585,   586,   587,   592,   155,   139,   140,
     596,   597,   557,   149,   149,   151,   602,   149,   117,   118,
     139,   140,   149,   149,   155,   151,   149,   149,   151,   615,
      51,   617,   149,     4,     5,   149,   155,   228,   229,   149,
    1351,   151,   628,   149,   146,   147,   149,   592,   634,   151,
       4,   153,  1316,   149,   156,   641,   158,   643,   644,   149,
     149,   151,   151,   649,   149,    36,    37,    38,    39,   149,
    1381,    42,     6,  1384,    68,   149,  1387,  1048,     6,  1390,
     656,   146,   147,   628,    78,   149,   151,   151,   153,   634,
      84,    85,     6,   158,    88,    89,   396,   397,  1362,     5,
    1364,  1412,  1366,  1414,   404,  1416,   692,   693,  1372,   139,
     140,   141,   142,   143,   149,   149,   151,   151,   148,   156,
     706,   707,   708,   709,   710,   711,   149,   713,   151,   149,
     149,   322,   718,   149,   149,   151,  1400,   155,  1402,   157,
    1404,   727,   155,   155,   157,   157,   117,   118,   149,   149,
     171,   737,   738,   739,   740,   741,   177,   178,   179,   151,
     155,   153,   157,   157,    68,   356,   149,   188,   713,   155,
     191,   157,   149,   149,    78,   146,   147,   155,     4,   157,
      84,    85,   153,   149,    88,    89,   155,   149,   157,   210,
     211,   156,   737,   738,   739,   740,   156,   156,  1011,     3,
       4,    53,   155,    55,   157,     9,    10,    11,   149,   149,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    68,   149,   424,   425,   151,    12,    13,   824,     6,
      68,    78,  1213,   434,   155,   821,   157,    84,    85,   440,
      78,    88,    89,   157,   156,   156,    84,    85,   151,   151,
      88,    89,   848,   849,   155,   155,   157,   157,   155,     5,
     157,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   155,    58,   157,     5,    61,    62,     5,    64,    65,
      66,   877,     8,   869,    70,   595,   155,   155,   157,   157,
     155,     4,   157,   889,     4,   155,     6,   157,   608,   155,
       6,   157,   116,     6,   153,   119,   120,   121,   156,   105,
     157,    97,    98,    99,   155,   155,   157,   157,   155,   157,
     157,   155,   155,   157,   157,   139,   140,   923,   924,   925,
     144,   155,   155,   157,   157,   149,   932,   933,   152,     6,
     154,    68,   156,   155,   940,   157,   155,   155,   157,   157,
       6,    78,   948,    68,     6,   156,   557,    84,    85,   560,
     561,    88,    89,    78,   151,     6,   962,   963,   964,    84,
      85,   157,   148,    88,    89,     8,   155,   155,   157,   157,
     976,   155,   155,   157,   157,   981,   153,   155,   974,   157,
       7,   592,   151,   948,   156,     7,   157,     7,     7,   149,
     996,   149,   149,   995,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,  1014,   149,
       7,   150,   148,     6,  1020,  1021,     7,   628,     7,  1025,
     157,     6,   102,   634,  1226,   156,  1032,   747,   150,   150,
       6,   150,   157,   150,     4,   150,  1042,   155,  1044,   150,
     150,   155,  1044,   155,    68,   152,     7,   105,     7,  1055,
       7,  1048,     7,   105,    78,     7,     7,   105,     7,  1065,
      84,    85,     7,  1069,    88,    89,  1072,     4,     6,   153,
     157,   791,   792,   793,   157,  1081,     6,   153,     7,  1081,
       7,   522,   523,   524,  1090,  1091,     7,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     4,   713,     7,  1110,   148,     7,   150,     7,     7,
     149,   149,   156,     6,     6,  1317,     6,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   737,   738,   739,   740,
     148,     6,     6,   157,  1140,   152,     6,   151,     7,   580,
       6,   136,    53,     6,  1377,     7,     7,    55,    12,    13,
     591,  1157,     7,  1159,     7,     7,     7,     6,   150,     7,
     150,     7,   150,  1169,   150,  1171,     7,     7,  1174,     6,
       4,     4,   156,   156,  1407,     6,  1409,  1183,   149,     7,
       6,     6,  1188,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,  1426,    58,     7,     7,    61,    62,     7,
      64,    65,    66,     6,  1210,     6,    70,     6,    53,  1174,
    1216,     6,  1218,     4,  1220,     4,  1213,     4,     6,     4,
     940,   156,   156,   156,  1230,   156,     6,   149,  1234,   153,
     156,   150,   150,    97,    98,    99,     7,     6,    68,   156,
    1246,  1247,    61,     6,   156,  1210,     6,  1253,    78,   156,
       6,     6,     6,  1259,    84,    85,   156,  1263,    88,    89,
       6,     5,     4,     6,   151,  1230,     7,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   152,     7,     7,     7,   148,  1292,     7,   156,     6,
       6,   156,     6,   157,     6,  1015,   156,   156,  1304,   101,
       6,  1307,     7,   153,  1310,     6,     4,     6,  1314,     6,
     751,   752,  1318,   754,  1320,   756,   757,     6,     6,   760,
     761,     6,     6,  1329,     6,     6,  1332,   157,     6,  1049,
       5,  1051,     6,  1053,     6,   105,     6,   948,     6,     6,
       6,     6,    68,     6,     6,  1065,   155,     6,  1068,  1069,
       6,     4,    78,  1318,     6,  1320,   156,   155,    84,    85,
       6,   155,    88,    89,     7,   155,     6,     6,  1374,   155,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     5,   826,   827,   828,   148,   153,
      51,     6,     6,     6,     6,     6,     6,   156,   156,     3,
       4,     5,     7,     7,   157,     9,    10,    11,   156,  1374,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   157,    36,    37,    38,    39,     6,   156,    42,     6,
       6,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    68,   894,  1065,   100,   148,     6,  1069,   900,
     156,   156,    78,     6,     6,   906,   907,   908,    84,    85,
     103,   912,    88,    89,     6,     6,   917,   918,   919,     6,
       6,     6,     6,   156,     6,     6,   157,     6,   157,    68,
       6,   932,     6,   157,     6,     6,  1216,   157,  1218,   156,
    1220,   942,   157,     6,     6,   946,   110,   156,  1228,     6,
       6,  1231,   116,   117,   118,   119,   120,   121,     6,     6,
       6,     6,   126,   127,   128,   129,     6,   157,   969,   970,
     971,   972,     6,   156,   156,   139,   140,   156,     6,     6,
     144,   157,   146,   147,     6,   149,     6,   151,  1159,   153,
     154,     6,   156,   994,   156,   156,     6,     6,     6,   156,
     156,   156,   156,  1174,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     6,     6,
       6,     6,   148,     6,     6,     6,     6,     6,     6,   888,
    1292,   893,     3,     3,  1035,  1036,  1037,  1038,   999,  1210,
    1320,   378,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     6,    -1,  1230,
      -1,   148,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,  1076,    -1,    -1,    84,    85,
      -1,    -1,    88,    89,    -1,     6,    -1,    -1,    -1,     3,
       4,  1092,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    47,    -1,    -1,    50,   148,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,  1318,    -1,  1320,
      -1,   157,    -1,  1154,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,  1179,  1180,
    1181,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,   116,  1374,    -1,   119,   120,   121,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,  1225,   139,   140,   148,    -1,    -1,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,     3,     4,
     154,    -1,   156,   157,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    12,    13,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    -1,    -1,    61,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   139,   140,    -1,    -1,    -1,   144,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      -1,    -1,   157,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    12,    13,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    -1,
      61,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,     3,     4,     5,   154,    -1,   156,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,   157,    -1,    50,    12,
      13,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    83,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    -1,    61,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   139,   140,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,   149,    -1,     3,
       4,    -1,   154,    -1,   156,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,   157,    -1,    50,    12,    13,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    83,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    -1,    61,    62,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,   119,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   139,   140,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,   149,    -1,     3,     4,    -1,
     154,    -1,   156,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,   157,    -1,    50,    12,    13,    53,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    83,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    61,    62,    -1,    64,    65,    66,
      -1,    -1,     6,    70,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,   119,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   139,   140,    -1,    -1,    -1,   144,    -1,
      -1,     6,    -1,   149,    -1,     3,     4,    -1,   154,    -1,
     156,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
     157,    -1,    50,    -1,    -1,    53,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    83,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,   119,   120,   121,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,   139,   140,   148,    -1,    -1,   144,    -1,    -1,     6,
      -1,   149,    -1,     3,     4,    -1,   154,    -1,   156,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    83,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
     120,   121,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,   139,
     140,   148,    -1,    -1,   144,    -1,    -1,     6,    -1,   149,
      -1,     3,     4,    -1,   154,    -1,   156,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,
      -1,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,     6,    -1,     3,     4,    80,    -1,
      -1,    83,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,   120,   121,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,   139,   140,   148,
      -1,    -1,   144,    -1,    -1,     6,    -1,   149,    -1,     3,
       4,     5,   154,    -1,   156,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,     8,    36,    37,    38,    39,    -1,    -1,    42,   116,
      -1,    -1,   119,   120,   121,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   139,   140,    -1,    -1,   148,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,    -1,   154,     8,   156,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   116,   117,   118,   119,   120,   121,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,   139,   140,   148,    -1,    -1,
     144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
     154,    -1,   156,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,   116,    -1,    -1,   119,   120,   121,   157,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,   139,   140,   148,    -1,
      -1,   144,    -1,    -1,    -1,    -1,   149,     8,     3,     4,
      -1,   154,    -1,   156,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,     8,    -1,     3,     4,    80,    -1,    -1,    83,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     8,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,   120,   121,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,   139,   140,    -1,   148,    -1,   144,
       3,     4,     5,    -1,   149,    -1,     9,    10,    11,   154,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,
     120,   121,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,   139,
     140,   148,    -1,    -1,   144,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,   139,   140,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    -1,    43,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,   102,    -1,   104,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,     4,    -1,    -1,
      -1,   122,   123,   124,   125,    12,    13,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,   157,    43,    44,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    -1,    68,    -1,    91,    12,    13,    -1,    -1,    96,
      97,    98,    99,    -1,    -1,   102,    -1,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    -1,    61,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    70,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
     157,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   157,   130,   131,   132,
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
       0,     1,   160,   161,     6,     0,     4,    12,    13,    35,
      40,    41,    43,    44,    45,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    78,    79,    80,    81,    82,    83,    86,
      87,    91,    96,    97,    98,    99,   102,   104,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   122,   123,
     124,   125,   162,   164,   165,   183,   187,   192,   195,   196,
     197,   198,   199,   200,   201,   221,   222,   223,   224,   225,
       3,     4,     5,     7,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    36,    37,
      38,    39,    42,   110,   116,   117,   118,   119,   120,   121,
     126,   127,   128,   129,   139,   140,   144,   146,   147,   149,
     151,   153,   154,   156,   181,   182,   226,   227,   239,    13,
      53,   149,     6,   156,     6,     6,     6,     6,   149,   156,
     149,   149,    77,   149,   156,   149,   149,    77,   156,   149,
     149,    57,    53,    53,     6,    53,    53,    50,    53,    55,
      55,    47,    50,    53,    55,    50,    53,    55,    50,    53,
     149,    50,   156,   139,   140,   149,   156,   228,   229,   228,
     156,    47,    50,    53,   156,   228,     4,    47,    51,    61,
      53,    53,    50,     4,   110,   156,     4,     6,    47,    50,
       4,     4,     4,     5,    47,    50,    53,    55,   140,   156,
     192,   201,   226,   231,   232,   233,     4,   149,   149,   149,
       4,   156,   235,     4,   149,   149,     6,   151,     4,     4,
       5,   156,     5,   156,   149,   149,   149,   149,     4,   151,
     153,   158,   182,   156,     5,   239,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   149,
     149,   149,     7,   149,   149,   149,     4,   226,   226,   226,
     226,   152,   156,   226,     4,   102,   103,     4,     4,   192,
     193,   194,   226,     6,     6,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   148,
       6,     6,   226,     5,   226,   226,   140,   226,   233,   234,
     226,   226,   149,   226,   234,   226,   226,   149,   234,   226,
     226,   231,   149,   156,   149,   149,   232,   232,   232,   149,
     188,   189,   190,   191,   149,   149,   149,   231,   226,     4,
     231,   228,   228,   228,   226,   226,   139,   140,   156,   156,
     228,   156,   156,   156,   139,   140,   149,   194,   228,   156,
     149,   156,   149,   149,   149,   232,   231,   149,     4,     6,
     151,   151,   194,     6,   156,   156,   151,   151,   151,     5,
     156,     5,     5,     5,   156,   226,   233,   157,   234,     8,
     141,     6,     6,   226,   226,   226,   153,   226,   156,   105,
     226,   226,   226,     6,     6,   194,     6,   194,     4,   238,
     239,   238,   238,   238,   151,   226,     4,   156,   166,     6,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   238,   238,   238,   238,   226,   238,   238,   238,
     151,   150,     7,   128,   129,   234,   152,     7,   181,   182,
     153,     7,   151,   157,    47,    50,    53,    55,   187,     6,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,     6,   150,   155,   155,   150,
     141,   155,   157,   150,   150,   226,   150,   157,   150,   150,
     226,   157,   150,   150,     7,   226,   226,   226,   226,     7,
       7,   219,   219,   226,   149,   149,   149,   149,   226,   226,
     226,     7,   156,   150,     6,   155,   155,   155,   228,   228,
     193,   193,   155,   226,   226,   226,   226,   205,   155,   194,
     226,   226,   226,   226,   226,     7,   220,     7,   226,     6,
     226,   226,   157,   234,   234,   226,   226,   152,   156,   226,
     226,   234,   157,   226,   156,   226,   233,   150,   150,   150,
     102,   155,   194,   156,     8,   150,   152,   157,   157,   151,
     153,   150,   150,   150,   150,   226,   152,   182,   226,     4,
      92,    93,    94,    95,   157,   169,   173,   176,   178,   179,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   155,   155,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   155,   155,   155,   155,
     155,   155,   150,   155,   155,   150,   150,     6,   155,   150,
     155,   231,   231,   231,   157,     7,   153,   181,   182,   239,
     226,     6,     4,     4,   156,   236,   152,   156,   156,   156,
     156,     8,     6,   136,   163,   234,   226,     7,   226,   233,
     105,     7,     7,   150,     7,   105,     7,     7,   150,   105,
       7,     7,   226,   150,   157,   150,   150,   226,   231,     4,
     218,     6,   150,   184,   226,   239,   184,   184,   184,   150,
     150,   150,   231,   234,   153,   228,   226,   226,   157,   157,
     226,   155,   155,   155,    68,    78,    84,    85,    88,    89,
     215,   216,   228,   157,   202,   150,   157,   150,   150,   150,
     226,     6,   226,   150,   152,   152,   157,   157,   152,   152,
     234,   152,   157,   157,     8,   234,     7,     7,     7,   153,
     226,   157,   226,   226,     7,   153,   226,     4,     7,     7,
       7,     7,   152,   153,   182,   238,   157,   170,   149,   149,
     156,   180,     6,   226,   226,   226,   226,   226,   226,   226,
     226,   234,   238,   226,   238,     6,     6,     6,   152,     4,
     102,   103,   226,     6,     6,     6,     7,   151,   235,   237,
       6,   234,   234,   234,   234,   226,   136,   238,   150,   155,
     228,    53,   231,   231,     7,   231,    53,    55,   231,   231,
       7,    55,   231,   231,     6,     7,     7,     7,     7,    68,
     217,     6,     7,   150,   150,   150,   150,     7,     7,     7,
       6,   157,     4,   155,   155,   155,   157,   228,   228,   228,
       4,     6,   156,   149,     6,    90,     6,    90,   157,   216,
     155,   215,     7,     6,     7,     7,     7,     6,   156,     6,
       6,     6,    53,     6,     6,   157,   226,   157,   231,   231,
     231,     4,   155,     8,     8,   150,     4,     4,   152,   156,
     156,   156,   156,     6,     4,     6,   149,   226,   226,   230,
     231,   156,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   150,   150,   150,   181,     7,   181,   182,   153,     7,
       6,   235,   226,   155,   157,   157,   157,   157,   157,     6,
       6,   163,   226,     6,   156,    61,   186,   186,   231,     6,
     156,   156,     6,     6,   231,   156,     6,     6,     5,   231,
     231,   231,     4,     6,   231,     7,     7,     7,     7,   231,
     231,   231,     7,     6,     7,   226,   226,   226,   156,   155,
     157,   155,   157,   155,   157,   151,   226,   231,   226,     6,
       6,   226,   228,   157,     5,   156,   231,   156,   156,   156,
     231,   234,   156,   152,     6,     6,   101,   226,   226,   226,
       6,     7,   153,   231,   231,   231,   231,   182,   167,   226,
     155,   155,   155,   157,   168,   226,   231,   239,   226,     6,
       4,   236,     6,   152,   235,     6,     6,     6,     6,   238,
     155,   226,   228,     6,     6,     6,   226,   226,     6,   226,
       5,     6,     6,   105,   185,   226,     6,   231,   231,   231,
     231,     6,     4,     6,     6,   226,   226,   239,   157,   150,
     155,   157,   193,   228,     6,   206,   228,     6,   207,   228,
       6,   208,   226,   157,   155,   150,   157,   155,     6,   140,
     228,     6,   230,   228,   228,     6,   157,   226,   231,   155,
     157,     8,   157,   150,   156,   226,   239,     4,   155,   155,
     155,   155,   150,   155,   226,   226,   231,   156,   155,   157,
       6,     6,     6,     7,     6,   153,     6,   226,   157,   157,
     157,   157,     5,    51,     6,     6,     6,     6,     6,   156,
     156,     6,     6,   156,   226,   157,   155,   156,   155,   156,
     155,   156,   152,     6,   231,     7,   156,   226,   155,   157,
     155,   155,     6,   157,   100,   226,   226,   234,     6,     6,
     231,   231,   231,   231,   171,   226,   155,   155,   230,   226,
       6,   235,   103,   155,     6,     6,     6,     6,     6,   156,
     230,   234,   193,   155,   157,   226,   228,   215,   226,   228,
     215,   226,   228,   215,     6,   155,   157,   231,   194,   157,
     228,     6,   234,   228,   226,   157,   157,   157,   157,   157,
     157,   157,   156,   226,   226,   157,     6,   226,   226,   157,
     157,   157,   226,   157,   155,   157,   157,   155,   157,   157,
     155,   157,   231,     6,    68,   157,   203,   156,   155,   157,
     155,     6,     6,     6,     6,     6,     6,   168,   150,   155,
       6,   156,   155,   157,     6,     6,   157,     6,   209,   226,
       6,     6,   210,   226,     6,     6,   211,   226,     6,   157,
     226,   215,   194,   234,     6,   228,   234,   157,   174,   226,
     230,   226,   156,   157,   156,   157,   156,   157,     6,     6,
     157,   157,   204,   157,   155,   157,     6,   156,   150,   157,
     157,   215,     6,   212,   215,     6,   213,   215,     6,   214,
     215,     6,   234,     6,   172,   238,   177,   156,     6,   157,
     156,   157,   156,   157,   156,   157,   157,   155,   157,   156,
     230,     6,   215,     6,   215,     6,   215,     6,   238,     6,
     175,   238,   157,   157,   157,   157,   155,   157,     6,     6,
       6,     6,   238,     6
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
#line 161 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 172 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 173 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 174 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 175 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 176 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 193 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 197 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 204 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 209 "Gmsh.y"
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
#line 223 "Gmsh.y"
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
#line 236 "Gmsh.y"
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
#line 264 "Gmsh.y"
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
#line 278 "Gmsh.y"
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
#line 289 "Gmsh.y"
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
#line 303 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList(); 
#endif
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 317 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 319 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 324 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 326 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 331 "Gmsh.y"
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
#line 435 "Gmsh.y"
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
#line 445 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 454 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 461 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 471 "Gmsh.y"
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
#line 480 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 489 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 496 "Gmsh.y"
    { 
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 506 "Gmsh.y"
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
#line 514 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 524 "Gmsh.y"
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
#line 543 "Gmsh.y"
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
#line 562 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 568 "Gmsh.y"
    {
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 575 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 576 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 577 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 578 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 579 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 583 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 584 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 592 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	if(!(yyvsp[(2) - (4)].i))
	  gmsh_yysymbols[(yyvsp[(1) - (4)].c)].push_back((yyvsp[(3) - (4)].d));
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (4)].c)].empty()){
          if((yyvsp[(2) - (4)].i)) yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
          gmsh_yysymbols[(yyvsp[(1) - (4)].c)].resize(1, 0.);
        }
	switch((yyvsp[(2) - (4)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] = (yyvsp[(3) - (4)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] += (yyvsp[(3) - (4)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] -= (yyvsp[(3) - (4)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] *= (yyvsp[(3) - (4)].d); break;
	case 4 : 
	  if((yyvsp[(3) - (4)].d)) gmsh_yysymbols[(yyvsp[(1) - (4)].c)][0] /= (yyvsp[(3) - (4)].d); 
	  else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), (yyvsp[(3) - (4)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 618 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (7)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (7)].c))){
	if(!(yyvsp[(5) - (7)].i)){
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d);
	}
	else
	  yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (7)].c));
      }
      else{
	if((int)gmsh_yysymbols[(yyvsp[(1) - (7)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (7)].c)].resize(index + 1, 0.);
	switch((yyvsp[(5) - (7)].i)){
	case 0 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] = (yyvsp[(6) - (7)].d); break;
	case 1 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] += (yyvsp[(6) - (7)].d); break;
	case 2 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] -= (yyvsp[(6) - (7)].d); break;
	case 3 : gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] *= (yyvsp[(6) - (7)].d); break;
	case 4 : 
	  if((yyvsp[(6) - (7)].d)) gmsh_yysymbols[(yyvsp[(1) - (7)].c)][index] /= (yyvsp[(6) - (7)].d); 
	  else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (7)].c), index, (yyvsp[(6) - (7)].d));
	  break;
	}
      }
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 645 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(4) - (9)].l)) != List_Nbr((yyvsp[(8) - (9)].l))){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count((yyvsp[(1) - (9)].c))){
	  if(!(yyvsp[(7) - (9)].i)){
	    for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	      int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (9)].c));
	}
	else{
	  for(int i = 0; i < List_Nbr((yyvsp[(4) - (9)].l)); i++){
	    int index = (int)(*(double*)List_Pointer((yyvsp[(4) - (9)].l), i));
	    double d = *(double*)List_Pointer((yyvsp[(8) - (9)].l), i);
	    if((int)gmsh_yysymbols[(yyvsp[(1) - (9)].c)].size() < index + 1)
	      gmsh_yysymbols[(yyvsp[(1) - (9)].c)].resize(index + 1, 0.);
	    switch((yyvsp[(7) - (9)].i)){
	    case 0 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] = d; break;
	    case 1 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] += d; break;
	    case 2 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] -= d; break;
	    case 3 : gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] *= d; break;
	    case 4 : 
	      if((yyvsp[(8) - (9)].l)) gmsh_yysymbols[(yyvsp[(1) - (9)].c)][index] /= d; 
	      else yymsg(0, "Division by zero in '%s[%d] /= %g'", (yyvsp[(1) - (9)].c), index, d);
	      break;
	    }
	  }
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 685 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].clear();
      gmsh_yysymbols[(yyvsp[(1) - (6)].c)] = std::vector<double>();
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
        gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 695 "Gmsh.y"
    {
      // appends to the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)].push_back(*(double*)List_Pointer((yyvsp[(5) - (6)].l), i));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 703 "Gmsh.y"
    {
      // remove from the list
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++)
        gmsh_yysymbols[(yyvsp[(1) - (6)].c)].erase(std::find(gmsh_yysymbols[(yyvsp[(1) - (6)].c)].begin(), 
                                           gmsh_yysymbols[(yyvsp[(1) - (6)].c)].end(), 
                                           *(double*)List_Pointer((yyvsp[(5) - (6)].l), i)));
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 713 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c)); 
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (3)].c)].empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else
          gmsh_yysymbols[(yyvsp[(1) - (3)].c)][0] += (yyvsp[(2) - (3)].i);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 725 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c)); 
      else{
	int index = (int)(yyvsp[(3) - (6)].d);
	if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	  gmsh_yysymbols[(yyvsp[(1) - (6)].c)].resize(index + 1, 0.);
	gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index] += (yyvsp[(5) - (6)].i);
      }
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 737 "Gmsh.y"
    { 
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 746 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 752 "Gmsh.y"
    { 
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 761 "Gmsh.y"
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

  case 76:

/* Line 1464 of yacc.c  */
#line 779 "Gmsh.y"
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

  case 77:

/* Line 1464 of yacc.c  */
#line 797 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 806 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 818 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 823 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 831 "Gmsh.y"
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

  case 82:

/* Line 1464 of yacc.c  */
#line 851 "Gmsh.y"
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

  case 83:

/* Line 1464 of yacc.c  */
#line 874 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->background_field = (int)(yyvsp[(4) - (5)].d);
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[(1) - (5)].c));
#endif
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 883 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 891 "Gmsh.y"
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

  case 86:

/* Line 1464 of yacc.c  */
#line 913 "Gmsh.y"
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

  case 87:

/* Line 1464 of yacc.c  */
#line 936 "Gmsh.y"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 964 "Gmsh.y"
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
#line 976 "Gmsh.y"
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

  case 90:

/* Line 1464 of yacc.c  */
#line 993 "Gmsh.y"
    { 
      (yyval.i) = (int)(yyvsp[(1) - (1)].d); 
    ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 997 "Gmsh.y"
    { 
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1007 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1011 "Gmsh.y"
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

  case 94:

/* Line 1464 of yacc.c  */
#line 1023 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1027 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1037 "Gmsh.y"
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

  case 97:

/* Line 1464 of yacc.c  */
#line 1060 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1064 "Gmsh.y"
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

  case 99:

/* Line 1464 of yacc.c  */
#line 1080 "Gmsh.y"
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

  case 100:

/* Line 1464 of yacc.c  */
#line 1102 "Gmsh.y"
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

  case 101:

/* Line 1464 of yacc.c  */
#line 1120 "Gmsh.y"
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

  case 102:

/* Line 1464 of yacc.c  */
#line 1141 "Gmsh.y"
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

  case 103:

/* Line 1464 of yacc.c  */
#line 1159 "Gmsh.y"
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

  case 104:

/* Line 1464 of yacc.c  */
#line 1189 "Gmsh.y"
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

  case 105:

/* Line 1464 of yacc.c  */
#line 1219 "Gmsh.y"
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

  case 106:

/* Line 1464 of yacc.c  */
#line 1237 "Gmsh.y"
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

  case 107:

/* Line 1464 of yacc.c  */
#line 1255 "Gmsh.y"
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

  case 108:

/* Line 1464 of yacc.c  */
#line 1281 "Gmsh.y"
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
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1298 "Gmsh.y"
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

  case 110:

/* Line 1464 of yacc.c  */
#line 1316 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1320 "Gmsh.y"
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

  case 112:

/* Line 1464 of yacc.c  */
#line 1339 "Gmsh.y"
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

  case 113:

/* Line 1464 of yacc.c  */
#line 1357 "Gmsh.y"
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

  case 114:

/* Line 1464 of yacc.c  */
#line 1396 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1402 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1408 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1415 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1440 "Gmsh.y"
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

  case 119:

/* Line 1464 of yacc.c  */
#line 1465 "Gmsh.y"
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
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1481 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1499 "Gmsh.y"
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

  case 122:

/* Line 1464 of yacc.c  */
#line 1529 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1533 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1553 "Gmsh.y"
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

  case 125:

/* Line 1464 of yacc.c  */
#line 1571 "Gmsh.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 1588 "Gmsh.y"
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

  case 127:

/* Line 1464 of yacc.c  */
#line 1604 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 1608 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1630 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 1635 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 1640 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1645 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1650 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1673 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1679 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1689 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1690 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1695 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1699 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1703 "Gmsh.y"
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

  case 141:

/* Line 1464 of yacc.c  */
#line 1726 "Gmsh.y"
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

  case 142:

/* Line 1464 of yacc.c  */
#line 1749 "Gmsh.y"
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

  case 143:

/* Line 1464 of yacc.c  */
#line 1772 "Gmsh.y"
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

  case 144:

/* Line 1464 of yacc.c  */
#line 1800 "Gmsh.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1821 "Gmsh.y"
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

  case 146:

/* Line 1464 of yacc.c  */
#line 1845 "Gmsh.y"
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

  case 147:

/* Line 1464 of yacc.c  */
#line 1866 "Gmsh.y"
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

  case 148:

/* Line 1464 of yacc.c  */
#line 1887 "Gmsh.y"
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

  case 149:

/* Line 1464 of yacc.c  */
#line 1907 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl);
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
          std::vector<const gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl);
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
          std::vector<const gLevelset *> vl;
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

  case 150:

/* Line 1464 of yacc.c  */
#line 2019 "Gmsh.y"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 2038 "Gmsh.y"
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
        GM->setVisibility(0);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
        GM->setVisibility(0);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        GModel *GM = GModel::current();
        GM->buildCutGModel(FindLevelSet(t)->ls, false, true);
        GM->setVisibility(0);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[(2) - (6)].c));
#endif
    ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 2065 "Gmsh.y"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 2173 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 2182 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 2188 "Gmsh.y"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 2203 "Gmsh.y"
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

  case 157:

/* Line 1464 of yacc.c  */
#line 2231 "Gmsh.y"
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

  case 158:

/* Line 1464 of yacc.c  */
#line 2248 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));      
    ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 2262 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2268 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 2274 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2283 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 2297 "Gmsh.y"
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

  case 164:

/* Line 1464 of yacc.c  */
#line 2339 "Gmsh.y"
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

  case 165:

/* Line 1464 of yacc.c  */
#line 2356 "Gmsh.y"
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

  case 166:

/* Line 1464 of yacc.c  */
#line 2371 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2390 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2402 "Gmsh.y"
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

  case 169:

/* Line 1464 of yacc.c  */
#line 2426 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 2430 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 2437 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 2443 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 2448 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 2454 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 2458 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 2462 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 2472 "Gmsh.y"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 2489 "Gmsh.y"
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

  case 179:

/* Line 1464 of yacc.c  */
#line 2506 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (8)].c)][0] = (yyvsp[(5) - (8)].d);
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

  case 180:

/* Line 1464 of yacc.c  */
#line 2525 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)].resize(1);
      gmsh_yysymbols[(yyvsp[(2) - (10)].c)][0] = (yyvsp[(5) - (10)].d);
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

  case 181:

/* Line 1464 of yacc.c  */
#line 2544 "Gmsh.y"
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
            yymsg(0, "Unknown loop variable");
          else{
            gmsh_yysymbols[name][0] += step;
            LoopControlVariablesTab[ImbricatedLoop - 1][0] = gmsh_yysymbols[name][0];
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

  case 182:

/* Line 1464 of yacc.c  */
#line 2574 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2582 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 2588 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2595 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2599 "Gmsh.y"
    {
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2608 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l), 
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2616 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l), 
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2624 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l), 
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2632 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2637 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l), 
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 2645 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 2650 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l), 
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 2658 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2663 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l), 
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 2671 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2676 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2684 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2691 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2698 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d), 
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2705 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2712 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2719 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2726 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2733 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2740 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d), 
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2747 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 2752 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2759 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2764 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2771 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2776 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d), 
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2783 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2788 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2795 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2800 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2807 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2812 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d), 
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2819 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2824 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2831 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2836 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2843 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2848 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d), 
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2859 "Gmsh.y"
    {
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2862 "Gmsh.y"
    {
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 2868 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 2877 "Gmsh.y"
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

  case 229:

/* Line 1464 of yacc.c  */
#line 2897 "Gmsh.y"
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

  case 230:

/* Line 1464 of yacc.c  */
#line 2920 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 2924 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 2928 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 2932 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 2936 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 2940 "Gmsh.y"
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

  case 236:

/* Line 1464 of yacc.c  */
#line 2959 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 2975 "Gmsh.y"
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

  case 239:

/* Line 1464 of yacc.c  */
#line 2990 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 2994 "Gmsh.y"
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

  case 241:

/* Line 1464 of yacc.c  */
#line 3006 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3010 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3019 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3026 "Gmsh.y"
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

  case 246:

/* Line 1464 of yacc.c  */
#line 3082 "Gmsh.y"
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

  case 247:

/* Line 1464 of yacc.c  */
#line 3152 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3157 "Gmsh.y"
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

  case 249:

/* Line 1464 of yacc.c  */
#line 3224 "Gmsh.y"
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

  case 250:

/* Line 1464 of yacc.c  */
#line 3260 "Gmsh.y"
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

  case 251:

/* Line 1464 of yacc.c  */
#line 3303 "Gmsh.y"
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

  case 252:

/* Line 1464 of yacc.c  */
#line 3328 "Gmsh.y"
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

  case 253:

/* Line 1464 of yacc.c  */
#line 3356 "Gmsh.y"
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

  case 254:

/* Line 1464 of yacc.c  */
#line 3399 "Gmsh.y"
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

  case 255:

/* Line 1464 of yacc.c  */
#line 3422 "Gmsh.y"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 3445 "Gmsh.y"
    {
    ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3448 "Gmsh.y"
    {
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3457 "Gmsh.y"
    { 
      ReplaceAllDuplicates();
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3461 "Gmsh.y"
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

  case 260:

/* Line 1464 of yacc.c  */
#line 3471 "Gmsh.y"
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

  case 261:

/* Line 1464 of yacc.c  */
#line 3508 "Gmsh.y"
    {
    
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->computeRanks();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3545 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findGenerators();  
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3581 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findDualGenerators();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 3616 "Gmsh.y"
    {
    List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (11)].l));
    std::vector<int> domain;
    
    for (int i = 0; i < List_Nbr(temp); i++){
      int item = 0;
      List_Read(temp, i, &item);
      domain.push_back(item);
    }
    List_Delete((yyvsp[(7) - (11)].l));
    List_Delete(temp);
    
    List_T *temp2 = ListOfDouble2ListOfInt((yyvsp[(9) - (11)].l));
    std::vector<int> subdomain;
    for (int i = 0; i < List_Nbr(temp2); i++){
      int item = 0;
      List_Read(temp2, i, &item);
      subdomain.push_back(item);
    }
    List_Delete((yyvsp[(9) - (11)].l));
    List_Delete(temp2);
    
    std::string fileName = "";
    fileName = (yyvsp[(3) - (11)].c);
    
    #if defined(HAVE_KBIPACK)
    Homology* homology = new Homology(GModel::current(), domain, subdomain);
    homology->setFileName(fileName);
    homology->findHomSequence();
    delete homology;
    #else
    yymsg(0, "Gmsh needs to be configured with option Kbipack to use homology computation");
    #endif
    ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 3655 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3656 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 3657 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3658 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3659 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3660 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3661 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3662 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3664 "Gmsh.y"
    { 
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);     
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3670 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3671 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3672 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3673 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3674 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3675 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 3676 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3677 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 3678 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 3679 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3680 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3681 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3682 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3683 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3684 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3685 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3686 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3687 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3688 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3689 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3690 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3691 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3692 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3693 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3694 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3695 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3696 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3697 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3698 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3699 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3700 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3701 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3703 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3704 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3705 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3706 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3707 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3708 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3709 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3710 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3711 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3712 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3713 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3714 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3715 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3716 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3717 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3718 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3719 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3720 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3721 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3722 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3723 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3732 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3733 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3734 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3735 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3736 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3737 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3738 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3743 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (1)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (1)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (1)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (1)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (1)].c)][0];
      }
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3762 "Gmsh.y"
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", (yyvsp[(1) - (5)].c), (int)(yyvsp[(4) - (5)].d)) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[tmpstring].empty()){
          yymsg(0, "Uninitialized variable '%s'", tmpstring);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = gmsh_yysymbols[tmpstring][0];
      }
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3780 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (4)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (4)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(1) - (4)].c)][index];
      Free((yyvsp[(1) - (4)].c));
    ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3795 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = gmsh_yysymbols[(yyvsp[(2) - (4)].c)].size();
      Free((yyvsp[(2) - (4)].c));
    ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3805 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        if(gmsh_yysymbols[(yyvsp[(1) - (2)].c)].empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (2)].c)][0] += (yyvsp[(2) - (2)].i));
      }
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3821 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else if((int)gmsh_yysymbols[(yyvsp[(1) - (5)].c)].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
	(yyval.d) = 0.;
      }
      else
	(yyval.d) = (gmsh_yysymbols[(yyvsp[(1) - (5)].c)][index] += (yyvsp[(5) - (5)].i));
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3839 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3844 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3849 "Gmsh.y"
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

  case 343:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
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

  case 344:

/* Line 1464 of yacc.c  */
#line 3869 "Gmsh.y"
    { 
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3877 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3881 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3885 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3889 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3893 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3900 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3904 "Gmsh.y"
    { 
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3908 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3912 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3919 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3924 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 3931 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 3936 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 3940 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3945 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3949 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3957 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3968 "Gmsh.y"
    { 
      (yyval.l) = (yyvsp[(1) - (1)].l); 
    ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3972 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 3984 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 3992 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4000 "Gmsh.y"
    { 
      (yyval.l) = List_Create(2, 1, sizeof(double)); 
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d)); 
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.)) 
	List_Add((yyval.l), &d);
    ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4007 "Gmsh.y"
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

  case 368:

/* Line 1464 of yacc.c  */
#line 4018 "Gmsh.y"
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

  case 369:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4042 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4046 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4054 "Gmsh.y"
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

  case 374:

/* Line 1464 of yacc.c  */
#line 4064 "Gmsh.y"
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

  case 375:

/* Line 1464 of yacc.c  */
#line 4074 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else
	for(unsigned int i = 0; i < gmsh_yysymbols[(yyvsp[(1) - (3)].c)].size(); i++)
	  List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (3)].c)][i]);
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)gmsh_yysymbols[(yyvsp[(1) - (6)].c)].size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &gmsh_yysymbols[(yyvsp[(1) - (6)].c)][index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4104 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4109 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4113 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4117 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4129 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4133 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4145 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(ColorString, -1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4152 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4162 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4166 "Gmsh.y"
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

  case 387:

/* Line 1464 of yacc.c  */
#line 4181 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4186 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4193 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4197 "Gmsh.y"
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

  case 391:

/* Line 1464 of yacc.c  */
#line 4210 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4218 "Gmsh.y"
    { 
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4229 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4233 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4241 "Gmsh.y"
    { 
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4249 "Gmsh.y"
    { 
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4257 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4265 "Gmsh.y"
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

  case 399:

/* Line 1464 of yacc.c  */
#line 4279 "Gmsh.y"
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

  case 400:

/* Line 1464 of yacc.c  */
#line 4293 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4297 "Gmsh.y"
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
#line 9816 "Gmsh.tab.cpp"
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
#line 4317 "Gmsh.y"


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

