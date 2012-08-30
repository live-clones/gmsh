/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 171 "Gmsh.tab.cpp"

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

/* Line 293 of yacc.c  */
#line 92 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 293 of yacc.c  */
#line 357 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 369 "Gmsh.tab.cpp"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7568

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  419
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1442

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
     752,   761,   762,   772,   778,   790,   796,   806,   811,   821,
     831,   833,   835,   836,   839,   846,   853,   860,   867,   876,
     887,   902,   919,   932,   941,   950,   957,   972,   977,   984,
     991,   995,  1000,  1006,  1010,  1014,  1019,  1024,  1028,  1036,
    1044,  1048,  1056,  1060,  1063,  1066,  1069,  1085,  1088,  1091,
    1094,  1097,  1104,  1113,  1122,  1133,  1135,  1138,  1140,  1144,
    1149,  1151,  1157,  1169,  1183,  1184,  1192,  1193,  1207,  1208,
    1224,  1225,  1232,  1241,  1250,  1259,  1272,  1285,  1298,  1313,
    1328,  1343,  1344,  1357,  1358,  1371,  1372,  1385,  1386,  1403,
    1404,  1421,  1422,  1439,  1440,  1459,  1460,  1479,  1480,  1499,
    1501,  1504,  1510,  1518,  1528,  1531,  1534,  1538,  1541,  1545,
    1555,  1562,  1563,  1567,  1568,  1570,  1571,  1574,  1575,  1578,
    1586,  1593,  1602,  1608,  1612,  1620,  1626,  1633,  1640,  1653,
    1664,  1675,  1686,  1697,  1700,  1704,  1711,  1713,  1715,  1718,
    1724,  1732,  1742,  1744,  1748,  1751,  1754,  1757,  1761,  1765,
    1769,  1773,  1777,  1781,  1785,  1789,  1793,  1797,  1801,  1805,
    1809,  1813,  1819,  1824,  1829,  1834,  1839,  1844,  1849,  1854,
    1859,  1864,  1869,  1876,  1881,  1886,  1891,  1896,  1901,  1906,
    1913,  1920,  1927,  1932,  1937,  1942,  1947,  1952,  1957,  1962,
    1967,  1972,  1977,  1982,  1989,  1994,  1999,  2004,  2009,  2014,
    2019,  2026,  2033,  2040,  2045,  2047,  2049,  2051,  2053,  2055,
    2057,  2059,  2061,  2067,  2072,  2077,  2080,  2086,  2090,  2097,
    2102,  2110,  2117,  2119,  2122,  2125,  2129,  2133,  2145,  2155,
    2163,  2171,  2173,  2177,  2179,  2181,  2184,  2188,  2193,  2199,
    2201,  2203,  2206,  2210,  2214,  2220,  2225,  2228,  2231,  2234,
    2237,  2239,  2241,  2245,  2250,  2257,  2259,  2261,  2265,  2269,
    2279,  2287,  2289,  2295,  2299,  2306,  2308,  2312,  2314,  2316,
    2320,  2327,  2329,  2331,  2336,  2343,  2350,  2355,  2360,  2365
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
     233,   157,   156,   199,   157,    -1,     4,   156,   199,   157,
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
       6,    -1,   231,   156,   238,   155,   238,   155,   238,   157,
       6,    -1,   234,    -1,   149,   233,   150,    -1,   140,   233,
      -1,   139,   233,    -1,   144,   233,    -1,   233,   140,   233,
      -1,   233,   139,   233,    -1,   233,   141,   233,    -1,   233,
     142,   233,    -1,   233,   143,   233,    -1,   233,   148,   233,
      -1,   233,   135,   233,    -1,   233,   136,   233,    -1,   233,
     138,   233,    -1,   233,   137,   233,    -1,   233,   134,   233,
      -1,   233,   133,   233,    -1,   233,   132,   233,    -1,   233,
     131,   233,    -1,   233,   130,   233,     8,   233,    -1,    14,
     149,   233,   150,    -1,    15,   149,   233,   150,    -1,    16,
     149,   233,   150,    -1,    17,   149,   233,   150,    -1,    18,
     149,   233,   150,    -1,    19,   149,   233,   150,    -1,    20,
     149,   233,   150,    -1,    21,   149,   233,   150,    -1,    22,
     149,   233,   150,    -1,    24,   149,   233,   150,    -1,    25,
     149,   233,   155,   233,   150,    -1,    26,   149,   233,   150,
      -1,    27,   149,   233,   150,    -1,    28,   149,   233,   150,
      -1,    29,   149,   233,   150,    -1,    30,   149,   233,   150,
      -1,    31,   149,   233,   150,    -1,    32,   149,   233,   155,
     233,   150,    -1,    33,   149,   233,   155,   233,   150,    -1,
      34,   149,   233,   155,   233,   150,    -1,    23,   149,   233,
     150,    -1,    14,   151,   233,   152,    -1,    15,   151,   233,
     152,    -1,    16,   151,   233,   152,    -1,    17,   151,   233,
     152,    -1,    18,   151,   233,   152,    -1,    19,   151,   233,
     152,    -1,    20,   151,   233,   152,    -1,    21,   151,   233,
     152,    -1,    22,   151,   233,   152,    -1,    24,   151,   233,
     152,    -1,    25,   151,   233,   155,   233,   152,    -1,    26,
     151,   233,   152,    -1,    27,   151,   233,   152,    -1,    28,
     151,   233,   152,    -1,    29,   151,   233,   152,    -1,    30,
     151,   233,   152,    -1,    31,   151,   233,   152,    -1,    32,
     151,   233,   155,   233,   152,    -1,    33,   151,   233,   155,
     233,   152,    -1,    34,   151,   233,   155,   233,   152,    -1,
      23,   151,   233,   152,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,   123,    -1,   124,    -1,   125,    -1,     4,
      -1,     4,   158,   156,   233,   157,    -1,     4,   151,   233,
     152,    -1,   154,     4,   151,   152,    -1,     4,   182,    -1,
       4,   151,   233,   152,   182,    -1,     4,   153,     4,    -1,
       4,   151,   233,   152,   153,     4,    -1,     4,   153,     4,
     182,    -1,     4,   151,   233,   152,   153,     4,   182,    -1,
     118,   149,   245,   155,   233,   150,    -1,   236,    -1,   140,
     235,    -1,   139,   235,    -1,   235,   140,   235,    -1,   235,
     139,   235,    -1,   156,   233,   155,   233,   155,   233,   155,
     233,   155,   233,   157,    -1,   156,   233,   155,   233,   155,
     233,   155,   233,   157,    -1,   156,   233,   155,   233,   155,
     233,   157,    -1,   149,   233,   155,   233,   155,   233,   150,
      -1,   238,    -1,   237,   155,   238,    -1,   233,    -1,   240,
      -1,   156,   157,    -1,   156,   241,   157,    -1,   140,   156,
     241,   157,    -1,   233,   141,   156,   241,   157,    -1,   238,
      -1,     5,    -1,   140,   240,    -1,   233,   141,   240,    -1,
     233,     8,   233,    -1,   233,     8,   233,     8,   233,    -1,
      49,   156,   233,   157,    -1,    49,     5,    -1,    52,     5,
      -1,    55,     5,    -1,    57,     5,    -1,   198,    -1,   207,
      -1,     4,   151,   152,    -1,    35,   151,     4,   152,    -1,
       4,   151,   156,   241,   157,   152,    -1,   233,    -1,   240,
      -1,   241,   155,   233,    -1,   241,   155,   240,    -1,   156,
     233,   155,   233,   155,   233,   155,   233,   157,    -1,   156,
     233,   155,   233,   155,   233,   157,    -1,     4,    -1,     4,
     153,   104,   153,     4,    -1,   156,   244,   157,    -1,     4,
     151,   233,   152,   153,   105,    -1,   242,    -1,   244,   155,
     242,    -1,   246,    -1,     4,    -1,     4,   153,     4,    -1,
       4,   151,   233,   152,   153,     4,    -1,     5,    -1,    43,
      -1,   119,   149,   245,   150,    -1,   120,   149,   245,   155,
     245,   150,    -1,    38,   149,   245,   155,   245,   150,    -1,
      39,   149,   245,   150,    -1,    40,   149,   245,   150,    -1,
      37,   149,   245,   150,    -1,    37,   149,   245,   155,   241,
     150,    -1
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
    1766,  1783,  1782,  1808,  1813,  1818,  1823,  1828,  1851,  1857,
    1868,  1869,  1874,  1877,  1881,  1904,  1927,  1950,  1978,  1999,
    2022,  2043,  2065,  2085,  2197,  2216,  2254,  2363,  2372,  2378,
    2393,  2421,  2438,  2452,  2458,  2464,  2473,  2487,  2532,  2549,
    2564,  2583,  2595,  2619,  2623,  2630,  2636,  2641,  2647,  2651,
    2655,  2665,  2682,  2699,  2720,  2741,  2776,  2784,  2790,  2797,
    2801,  2810,  2818,  2826,  2835,  2834,  2848,  2847,  2861,  2860,
    2874,  2873,  2886,  2893,  2900,  2907,  2914,  2921,  2928,  2935,
    2942,  2950,  2949,  2962,  2961,  2974,  2973,  2986,  2985,  2998,
    2997,  3010,  3009,  3022,  3021,  3034,  3033,  3046,  3045,  3061,
    3064,  3070,  3079,  3099,  3122,  3126,  3130,  3134,  3138,  3142,
    3161,  3174,  3177,  3193,  3196,  3209,  3212,  3218,  3221,  3228,
    3284,  3354,  3359,  3426,  3462,  3471,  3514,  3539,  3566,  3610,
    3633,  3656,  3659,  3668,  3672,  3682,  3717,  3718,  3722,  3729,
    3742,  3761,  3789,  3790,  3791,  3792,  3793,  3794,  3795,  3796,
    3797,  3804,  3805,  3806,  3807,  3808,  3809,  3810,  3811,  3812,
    3813,  3814,  3815,  3816,  3817,  3818,  3819,  3820,  3821,  3822,
    3823,  3824,  3825,  3826,  3827,  3828,  3829,  3830,  3831,  3832,
    3833,  3834,  3835,  3837,  3838,  3839,  3840,  3841,  3842,  3843,
    3844,  3845,  3846,  3847,  3848,  3849,  3850,  3851,  3852,  3853,
    3854,  3855,  3856,  3857,  3866,  3867,  3868,  3869,  3870,  3871,
    3872,  3876,  3896,  3915,  3933,  3945,  3962,  3983,  3988,  3993,
    4003,  4013,  4021,  4025,  4029,  4033,  4037,  4044,  4048,  4052,
    4056,  4063,  4068,  4075,  4080,  4084,  4089,  4093,  4101,  4112,
    4116,  4128,  4136,  4144,  4151,  4162,  4182,  4186,  4190,  4194,
    4198,  4208,  4218,  4230,  4242,  4263,  4268,  4272,  4276,  4288,
    4292,  4304,  4311,  4321,  4325,  4340,  4345,  4352,  4356,  4369,
    4377,  4388,  4392,  4400,  4408,  4416,  4424,  4438,  4452,  4456
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
     199,   199,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   202,   202,   202,
     202,   202,   203,   204,   204,   204,   204,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   207,   207,   208,   207,   209,   207,   210,   207,
     211,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   212,   207,   213,   207,   214,   207,   215,   207,   216,
     207,   217,   207,   218,   207,   219,   207,   220,   207,   221,
     221,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   227,
     227,   227,   227,   227,   227,   227,   227,   228,   228,   229,
     229,   229,   229,   230,   230,   230,   231,   231,   232,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   235,   235,   235,   235,   235,   236,   236,   236,
     236,   237,   237,   238,   238,   238,   238,   238,   238,   239,
     239,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   241,   241,   242,
     242,   242,   242,   243,   243,   244,   244,   245,   245,   245,
     245,   246,   246,   246,   246,   246,   246,   246,   246,   246
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
       8,     0,     9,     5,    11,     5,     9,     4,     9,     9,
       1,     1,     0,     2,     6,     6,     6,     6,     8,    10,
      14,    16,    12,     8,     8,     6,    14,     4,     6,     6,
       3,     4,     5,     3,     3,     4,     4,     3,     7,     7,
       3,     7,     3,     2,     2,     2,    15,     2,     2,     2,
       2,     6,     8,     8,    10,     1,     2,     1,     3,     4,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     8,     8,     8,    12,    12,    12,    14,    14,
      14,     0,    12,     0,    12,     0,    12,     0,    16,     0,
      16,     0,    16,     0,    18,     0,    18,     0,    18,     1,
       2,     5,     7,     9,     2,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     7,     5,     6,     6,    12,    10,
      10,    10,    10,     2,     3,     6,     1,     1,     2,     5,
       7,     9,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       1,     1,     3,     4,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     3,
       6,     1,     1,     4,     6,     6,     4,     4,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,     0,   200,     0,     0,   197,     0,     0,     0,     0,
     276,   277,     5,     7,     6,     8,     9,    10,    21,    11,
      12,    13,    20,    19,    14,    15,    16,    17,    18,     0,
      22,   344,   351,   411,    57,   345,   346,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,     0,     0,     0,   348,   349,
     350,    61,    60,    59,    58,     0,     0,     0,    63,    62,
       0,     0,     0,     0,   152,     0,     0,     0,   282,     0,
       0,     0,     0,   185,     0,   187,   184,   188,   189,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,     0,   111,   124,   136,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,     0,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   273,
       0,     0,     0,     0,     0,   351,   380,     0,     0,     0,
       0,     0,     0,     0,   390,   391,   373,   379,     0,   374,
       0,     0,     0,     0,   401,     0,     0,     0,     0,     0,
     183,     0,     0,   196,     0,   152,     0,   152,   278,     0,
       0,     0,     0,     0,   355,    32,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,   285,
     284,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,     0,   150,     0,    69,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   128,     0,     0,     0,    90,     0,     0,
     395,   396,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   364,   363,     0,     0,     0,
       0,   152,   152,     0,     0,     0,     0,     0,     0,     0,
     210,     0,   152,     0,     0,     0,     0,     0,   257,     0,
       0,     0,   170,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,     0,   386,     0,   387,   388,   389,     0,
     284,   381,   375,     0,     0,     0,   263,   182,     0,     0,
       0,     0,     0,   152,     0,     0,     0,     0,   198,   173,
       0,   174,     0,     0,     0,     0,   357,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   408,     0,   407,     0,     0,     0,     0,     0,
       0,     0,     0,   283,    57,     0,     0,     0,    57,     0,
       0,     0,     0,     0,   147,     0,     0,     0,     0,   153,
      65,     0,   300,   299,   298,   297,   293,   294,   296,   295,
     288,   287,   289,   290,   291,   292,   129,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,   366,   365,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,   167,     0,     0,     0,
       0,     0,   392,     0,     0,     0,     0,     0,   376,   383,
       0,   289,   382,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,   175,   176,     0,     0,     0,   353,   359,
       0,    42,     0,     0,     0,    55,     0,    33,    34,    35,
      36,    37,   302,   323,   303,   324,   304,   325,   305,   326,
     306,   327,   307,   328,   308,   329,   309,   330,   310,   331,
     322,   343,   311,   332,     0,     0,   313,   334,   314,   335,
     315,   336,   316,   337,   317,   338,   318,   339,     0,     0,
       0,     0,     0,     0,     0,     0,   418,     0,     0,   416,
     417,    82,     0,   413,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,   354,     0,     0,
       0,     0,     0,    25,    23,     0,     0,     0,    64,    93,
       0,   397,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,   256,   254,     0,   262,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,   201,     0,     0,     0,
       0,     0,     0,   258,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,   393,   385,   377,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,     0,   279,     0,     0,   356,     0,   352,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,    70,    72,    74,     0,     0,   405,
       0,    80,     0,     0,     0,     0,   301,    24,     0,     0,
       0,     0,     0,     0,   108,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,   245,     0,   247,     0,
     211,   240,     0,     0,     0,   165,     0,     0,     0,   266,
       0,   169,   168,   275,     0,     0,    30,    31,     0,   384,
     378,     0,     0,     0,   402,     0,     0,     0,   191,     0,
       0,     0,     0,   179,   358,   178,     0,     0,     0,     0,
     371,     0,   312,   333,   319,   340,   320,   341,   321,   342,
       0,   419,   415,   361,   414,     0,    57,     0,     0,     0,
       0,    67,     0,     0,     0,   403,     0,     0,     0,     0,
      26,    27,     0,     0,     0,    94,   110,     0,     0,     0,
       0,     0,   114,     0,     0,   131,   132,     0,     0,   116,
     139,     0,     0,     0,   106,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,   152,     0,   221,     0,   223,     0,   225,     0,   373,
       0,     0,   246,   248,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   394,   119,   120,
       0,     0,     0,     0,    83,    87,     0,     0,   280,   360,
       0,    38,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,    77,     0,     0,    78,     0,   406,   154,   155,
     156,   157,     0,     0,    95,     0,   109,   117,   118,   122,
       0,     0,   133,     0,     0,   261,   126,     0,     0,   252,
     138,     0,     0,     0,     0,   123,     0,   134,   140,     0,
       0,     0,     0,   370,     0,   369,     0,     0,   212,     0,
       0,   213,     0,     0,   214,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,   163,     0,     0,     0,   158,
       0,     0,     0,     0,   400,     0,   193,   192,     0,     0,
       0,     0,    43,     0,     0,     0,   372,     0,     0,     0,
     410,    68,    73,    75,     0,    81,     0,    28,     0,    99,
       0,     0,     0,     0,     0,     0,   127,   112,   125,   137,
     142,     0,     0,    88,    89,   152,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,   152,     0,
       0,     0,     0,     0,   149,   148,     0,     0,     0,     0,
      84,    85,   281,     0,    39,     0,     0,     0,    41,    56,
       0,   404,     0,     0,   269,   270,   271,   272,   130,     0,
       0,     0,     0,     0,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,     0,   206,     0,
       0,   159,     0,     0,     0,   399,   194,     0,     0,     0,
       0,     0,    79,     0,     0,    96,   100,     0,     0,     0,
     144,     0,   227,     0,     0,   229,     0,     0,   231,     0,
       0,     0,   242,     0,   202,     0,   152,     0,     0,     0,
     121,    86,     0,    47,     0,    53,     0,     0,     0,   107,
     135,   268,   367,   215,     0,     0,   222,   216,     0,     0,
     224,   217,     0,     0,   226,     0,     0,     0,   208,     0,
     162,     0,     0,     0,     0,     0,     0,     0,   103,     0,
     101,     0,   233,     0,   235,     0,   237,   243,   249,   207,
     203,     0,     0,     0,     0,    44,     0,    51,     0,     0,
       0,   395,     0,   218,     0,     0,   219,     0,     0,   220,
       0,     0,   166,     0,   160,     0,    45,     0,     0,   186,
       0,   102,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,    97,   228,     0,   230,
       0,   232,     0,   161,    46,    48,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    54,    98,   234,   236,   238,
      50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    72,   745,    73,    74,   468,  1090,  1096,
     667,   848,  1243,  1395,   668,  1354,  1426,   669,  1397,   670,
     671,   852,   145,   264,    75,   562,   357,  1199,  1380,  1253,
    1296,   776,  1128,  1019,   539,   383,   384,   385,   386,   234,
     332,   333,    78,    79,    80,    81,    82,    83,   235,   807,
    1315,  1371,   611,  1149,  1152,  1155,  1334,  1338,  1342,  1384,
    1387,  1390,   803,   804,   912,   773,   585,   620,    85,    86,
      87,    88,    89,    90,   236,   148,   396,   200,   979,   980,
     238,   239,   443,   246,   736,   880,   513,   514
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1070
static const yytype_int16 yypact[] =
{
    3914,    79,    32,  3996, -1070, -1070,  1905,    85,    51,   -21,
      30,   131,   148,   193,   204,    91,   102,    99,   105,     6,
     171,   183,    18,   201,   229,   329,   334,   353,   432,   436,
     437,    10,   418,   -14,   379,    62,   356,   461,   369,   174,
     174,   391,   341,    87,   495,   506,   522,    11,    54,   523,
     524,   591,   598,  2059,   603,   431,   462,   466,    21,     2,
   -1070,   476, -1070,   622,   478, -1070,   628,   633,     0,    28,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,    31,
   -1070, -1070,    25,   487,   471, -1070, -1070, -1070,  -107,   -88,
     218,   248,   320,   336,   368,   372,   375,   397,   420,   467,
     472,   475,   491,   501,   505,   515,   519,   538,   545,   511,
     512,   520,   541, -1070,   637,   549,   556,   564, -1070, -1070,
   -1070, -1070, -1070, -1070, -1070,  1421,  1421,  1421, -1070, -1070,
    1421,  1832,    22,   724,    20,  2503,   729,   993, -1070,   745,
     746,  1421,   753, -1070,  1421, -1070, -1070, -1070, -1070, -1070,
    1421,  3539,  1421,  1421,   617,  1421,  3539,  1421,  1421,   625,
    3539,  1421,  1421,  2503,   630,   629, -1070,   656,   692,  2059,
    2059,  2059,   693, -1070, -1070, -1070, -1070,   701,   712,   713,
    2503,  1421,   782,  2503,   174,   174,   174,  1421,  1421,   -56,
   -1070,    68,   174,   727,   731,   756,  3325,    80,   172,   720,
     786,   792,  2059,  2503,   800,    49,   769, -1070,   874, -1070,
     765,   788,   799,   805,   810,   450, -1070,   811,    29,   946,
     963,   967,  2651,  1750, -1070, -1070,  3614, -1070,   972, -1070,
     976,  1421,  1421,  1421,   820,  1421,   827,   877,  1421,  1421,
   -1070,  1421,   979, -1070,   980, -1070,   981, -1070, -1070,  2503,
     837,  1421,   985,   835, -1070, -1070, -1070,   987,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
     321,   321,   321,   321,  1421,   321,   321,   321,   488,   846,
     846,   846,  6286,   134,  3539,  5527,   225,   843,   991,   849,
     845, -1070,   850,  4070,   996, -1070, -1070,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421, -1070, -1070,  1206,  -138,  4825,   344,  6307,  3539,
    3633, -1070,    48,  6328,  6349,  1421,  6370,   542,  6391,  6412,
    1421,   546,  6433,  6454,   999,  1421,  1421,  1421,  1421,  1001,
    1003,  1003,  1421,   864,   865,   868,   869,  1421,  1421,  1421,
    1009,  4745,   873,  1013,   -31, -1070, -1070,  4851,  4877,   174,
     174,    20,    20,   176,  1421,  1421,  1421,  3325,  3325,  1421,
    4070,   178, -1070,  1421,  1421,  1421,  1421,  1421,  1022,  1023,
    1421,  1028, -1070,  1421,  1421,   757, -1070,  3539,  3539,  3539,
    1421,  1421,  3171,  1032, -1070,  1421, -1070, -1070, -1070,  3539,
     846, -1070, -1070,   547,  1421,  2799, -1070, -1070,  6475,  6496,
    6517,   934,  4903, -1070,   883,  3708,  6538,  5550, -1070, -1070,
    1139, -1070,  1940,   561,  1421,  5573,    67,  1421,    16, -1070,
    6559,  5596,  6580,  5619,  6601,  5642,  6622,  5665,  6643,  5688,
    6664,  5711,  6685,  5734,  6706,  5757,  6727,  5780,  6748,  5803,
    6769,  5826,  4929,  4955,  6790,  5849,  6811,  5872,  6832,  5895,
    6853,  5918,  6874,  5941,  6895,  5964,  4981,  5007,  5033,  5059,
    5085,  5111,   566,   169, -1070,   885,   892,   894,  1245,   891,
     898,   896,  1421, -1070, -1070,  2503,   572,    65,   471,  1421,
    1043,  1048,    23,   901, -1070,   221,    26,    24,   235, -1070,
   -1070,  3731,  1415,  1225,  1321,  1321,   582,   582,   582,   582,
     424,   424,   846,   846,   846,   846, -1070,    12,  3539,  1421,
    1049, -1070,  1050,  1051,  3539,  3539,   950,  1052,  1053,  6916,
    1054,   955,  1056,  1057,  6937,   958,  1060,  1062,  1421,  6958,
    4073,  6979,  7000,  1421,  2503,  1067,  1068,  7021,  3681,  3681,
    3681,  3681,  7042,  7063,  7084,  2503,  3539,   922, -1070,   174,
    1421,  1421, -1070, -1070,   920,   921,  1421,  5137,  5163,  5189,
    4799,   136,   174,  2106,  7105,  4101,  7126,  7147,  7168,  1421,
    1075,  1421,  7189, -1070,  5987,  6010, -1070,   576,   577,   586,
    6033,  6056, -1070,  3539,  6079,   930,  4129,   590, -1070,  3750,
    3539,   846, -1070,  1076,  1079,  1080,   935,  1421,  2254,  1421,
    1421, -1070,     4, -1070, -1070,  2503,  1083,  6102,    82, -1070,
    4157, -1070,   951,   952,   939, -1070,  1093, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070,  1421,  1421, -1070, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1099, -1070,  3539,   321, -1070,
   -1070, -1070,  1421, -1070,   321,  1101,   953,    27,  1421,  1102,
    1103,  1273, -1070,  1105,   964,    21,  1108, -1070,  3539,  3539,
    3539,  3539,  1421, -1070,   983,   321,   296,  5215, -1070,  1109,
     174,  3633, -1070,  1065,  2503,  2503,  1110,  2503,   699,  2503,
    2503,  1130,  1081,  2503,  2503,  1388,  1132,  1133,  1136,  1137,
    3805, -1070, -1070,  1140, -1070,  1141,  1000,  7420, -1070,  1004,
    1005,  1007,  1142,  1151,  1153,  1156,   600,  1161,   226,  5241,
    5267, -1070, -1070,  4185,   174,   174,   174,  1162,  1163,  1012,
    1021,    13,    15,   -13, -1070,   243, -1070,   136,  1165,  1168,
    1175,  1176,  1177,  7420, -1070,  1598,  1019,  1179,  1181,  1192,
    1145,  1421,  1195,  1198,   616,   209, -1070, -1070, -1070,  1421,
     620,  2503,  2503,  2503,  1204,  5293, -1070,  3769,   760,  1205,
    1209,   623, -1070,  1211,  1215, -1070,  1216, -1070,  1066,  1421,
    1421,  2503,  1069, -1070,  7210,  6125,  7231,  6148,  7252,  6171,
    7273,  6194,  6217, -1070,   309,  1071,  7294,  1073, -1070,   134,
     327,  1074,  1219,  2606, -1070, -1070, -1070,    21,  1421, -1070,
     634, -1070,   635,   642,   646,   647,  7420, -1070,  1222,    17,
    1421,  3391,    58,  1085,  1166,  1166,  2503,  1226,  1086,  1089,
    1229,  1230,  2503,  1090,  1231,  1241, -1070,  1243,  2503,  2503,
    2503,  1227,  1246, -1070,  2503,  1242,  1247,  1248,  1249,  2503,
    2503,  2503, -1070,  1251,   109,  1421,  1421,  1421,  1097,   -58,
     -10,    98,  1111, -1070,  2503,  1421, -1070,  1253, -1070,  1254,
   -1070, -1070,  3325,   -11,  2207, -1070,  1107,  1113,  2947, -1070,
    3539, -1070, -1070, -1070,  1115,  2625, -1070, -1070,  1112,  7420,
   -1070,  1259,  1260,  1170, -1070,  1421,  1421,  1421, -1070,  1268,
     227,  2503,  1269, -1070,    67, -1070,  1421,  5319,  5345,   661,
   -1070,  1421, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
    1123, -1070, -1070, -1070, -1070,  2503,   471,  1421,  1271,  1274,
      23, -1070,  1275,  6240,    21, -1070,  1276,  1278,  1279,  1282,
   -1070, -1070,   321,  5371,  1421,  7420, -1070,  1421,   174,  1283,
    1284,  1285, -1070,  1421,  1421, -1070, -1070,  1286,  1421, -1070,
   -1070,  1288,  1289,  1291,  1187,  1421, -1070,  1292,  2503,  2503,
    2503,  2503,  1293,   826,  1294,  1421, -1070,  3681,  4213,  7315,
    3654,    20,   174,  1296,   174,  1297,   174,  1299,  1421,   401,
    1154,  7336, -1070, -1070,  4241,   255, -1070,  1300,  1563,  1302,
    2503,   174,  1563,  1304,   678,  1421, -1070, -1070, -1070, -1070,
    2503,  4017,   543,  7357, -1070, -1070,  3243,  1155, -1070, -1070,
     311,  7420,  1421,  1421,  2503,  1157,   679,  7420,  1310,  1312,
    1313,  2764, -1070,  1309,  1314, -1070,  1174, -1070, -1070, -1070,
   -1070, -1070,  1315,  1421,  7420,  4269,   125, -1070, -1070, -1070,
    4297,  4325, -1070,  4353,  1325, -1070, -1070,  1281,  1329,  7420,
   -1070,  1344,  1345,  1346,  1347, -1070,  1199, -1070, -1070,  4772,
    2902,  1350,  1214, -1070,  1421, -1070,  1233,   277, -1070,  1235,
     280, -1070,  1236,   284, -1070,  1239,  6263,  1391,  2503,  1324,
    1261,  1421, -1070,  3095,   305, -1070,   682,   308,   338, -1070,
    1393,  4381,  1316,  1421, -1070,  1421, -1070, -1070,  3539,  2921,
    1413,  1414, -1070,  1421,  5397,  5423, -1070,  2503,  1421,  1416,
   -1070, -1070, -1070, -1070,    21, -1070,  1322, -1070,  5449, -1070,
    1420,  1423,  1427,  1428,  1460,  1311, -1070, -1070, -1070, -1070,
   -1070,  2503,  3539, -1070, -1070,    20,  4045, -1070,  3325,   136,
    3325,   136,  3325,   136,  1462, -1070,   683,  2503, -1070,  4409,
     174,  1464,  3539,   174, -1070, -1070,  1421,  4437,  4465,   694,
   -1070, -1070, -1070,  1317,  7420,  1421,  1421,   698,  7420, -1070,
    1466, -1070,  1421,   715, -1070, -1070, -1070, -1070, -1070,  1421,
     718,   722,  1318,  1421, -1070,  4493,   349,   416,  4521,   361,
     674,  4549,   390,   697, -1070,  2503,  1468,  1406,  2402,  1326,
     413, -1070,   749,   415,  3296, -1070, -1070,  1474,  1421,  7378,
    5475,    34, -1070,  5501,  1477, -1070, -1070,  4577,  1478,  1479,
   -1070,  4605,  1480,  1421,  1481,  1485,  1421,  1486,  1487,  1421,
    1488,  1338, -1070,  1421, -1070,   136, -1070,  3539,  1490,  3095,
   -1070, -1070,   750, -1070,  1421, -1070,  2503,  1421,  2355, -1070,
   -1070, -1070, -1070, -1070,  1341,  4633, -1070, -1070,  1342,  4661,
   -1070, -1070,  1343,  4689, -1070,  1494,  3354,   773,  2550,   754,
   -1070,   438,   758,  1495,  1348,  7399,   761,  4717, -1070,  1750,
   -1070,   136,  1496,   136,  1499,   136,  1500, -1070, -1070, -1070,
   -1070,   136,  1502,  3539,  1503, -1070,   321, -1070,  1354,  1506,
     762,  3496,   795, -1070,  1358,   852, -1070,  1359,   867, -1070,
    1360,   880, -1070,   771, -1070,   772, -1070,  1376,  2503, -1070,
    1421, -1070,   471,  1527,   136,  1528,   136,  1529,   136, -1070,
    1531,   321,  1532,   321,   779,  3595, -1070, -1070,   890, -1070,
     941, -1070,  1006, -1070, -1070, -1070,   790, -1070,  1535,   471,
    1536,  1537,  1553,   321,  1556, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1070, -1070, -1070, -1070,   680, -1070, -1070, -1070, -1070,   283,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070,  -310,     1, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070,  -280, -1070,   673,  1573, -1070, -1070, -1070, -1070,    -1,
    -393,  -203, -1070, -1070, -1070, -1070, -1070, -1070,  1596, -1070,
   -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070, -1070,
   -1070, -1070,  -751,  -755, -1070, -1070,  1220, -1070, -1070, -1070,
   -1070, -1070, -1070, -1070,    -2, -1070,    50, -1070, -1069,   569,
    -110,   439,    55,  -696,   605, -1070,  -266,    -6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     149,  1166,    77,   410,   147,   254,   247,   146,   604,   605,
     164,   839,   557,   525,   425,   215,   529,   558,   743,   936,
     661,   938,   169,  1011,   330,   244,   326,   734,   169,   260,
     164,   870,     5,   256,   434,   183,   153,   258,   184,   879,
    1325,   185,   268,   186,   269,   515,   516,   517,   941,   519,
     520,   521,   460,   421,   462,   422,   943,   797,   218,   797,
     219,   270,   179,   271,  1016,   180,   798,   181,   798,   379,
     380,   381,   524,   799,   800,   799,   800,   801,   802,   801,
     802,   399,   400,   399,   400,     4,   512,   266,   267,   199,
     201,   208,   207,    38,    39,    40,    41,  1052,   150,  1053,
     401,    46,   418,   220,    49,   937,   151,   939,   399,   400,
     662,   663,   664,   665,   190,  1046,  1047,   191,  1247,   119,
     120,   121,   122,   216,   599,   123,   327,   328,   152,   399,
     400,   871,   872,   319,   320,   321,   209,   155,   322,   325,
     210,   524,  1260,   331,   940,  1054,  1066,  1055,   744,   354,
     211,   248,   356,   744,   156,   165,   255,   840,   358,   360,
     363,   364,   166,   366,   360,   368,   369,   217,   360,   372,
     373,   138,   139,   666,   170,   165,   261,   245,   262,   735,
     740,  1002,   739,   263,   257,   435,   154,   259,   941,   391,
    1326,   131,   132,   133,   134,   397,   398,   399,   400,   157,
     423,   126,   127,   565,   398,   566,   797,   399,   400,   613,
     158,   138,   139,   138,   139,   798,   362,   728,   727,   399,
     400,   367,   799,   800,   402,   371,   801,   802,   138,   139,
     440,   360,   528,  1085,  1086,   844,   412,   399,   400,   448,
     449,   450,   159,   452,   394,   395,   455,   456,   162,   457,
     648,   160,   403,  1056,   163,  1057,   411,  1356,   161,   465,
     131,   132,   133,   134,   399,   400,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,  1107,   779,
     780,   781,   518,   195,   196,   399,   400,   399,   400,   716,
     167,   413,   360,   197,   717,   512,   266,   530,   414,  1414,
     198,   606,   168,   612,   996,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     171,   131,   132,   133,   134,   138,   139,   440,   119,   120,
     121,   122,   844,   569,   123,   399,   400,   272,   574,   273,
     160,   138,   139,   579,   580,   581,   582,   738,   172,   526,
     587,   925,   399,   400,   172,   592,   593,   594,   173,   174,
     203,   741,   846,   204,   399,   400,   205,   274,   942,   275,
     331,   331,   607,   608,   609,   319,   320,   610,   175,   444,
    1161,   614,   615,   616,   617,   618,   399,   400,   622,   399,
     400,   624,   625,   399,   400,   360,   360,   360,   630,   631,
     634,   187,  1218,   636,   188,  1220,   189,   360,   176,  1222,
     126,   127,   639,   641,   399,   400,   889,   399,   400,   602,
     603,   565,   865,   131,   132,   133,   134,   395,   867,   991,
    1230,  1182,   657,  1232,   565,   660,  1183,   659,  1267,   276,
    1270,   277,  1273,   138,   139,   182,   266,   399,   400,   888,
     195,   196,   627,   628,   629,   278,   797,   279,   399,   400,
     197,   177,   178,  1233,   637,   798,   560,   206,  1250,   561,
     399,   400,   799,   800,  1303,   192,   801,   802,   119,   120,
     121,   122,   941,   193,   123,   941,  1306,   280,   941,   281,
     634,   282,   730,   283,   284,   194,   285,   731,   729,   399,
     400,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   445,   349,   350,  1309,   286,   202,   287,   351,
     212,  1175,   399,   400,   399,   400,   360,   747,  1157,   995,
     997,   213,   641,   751,  1347,   348,   349,   350,  1317,   288,
    1319,   289,   351,  1304,   214,   221,   765,   399,   400,   222,
     241,   770,   778,   778,   778,   778,   777,   777,   777,   777,
     126,   127,   941,  1373,   360,   223,   138,   139,   789,   790,
     361,   432,   224,   262,   793,   361,   144,   240,   263,   361,
    1382,   242,  1385,   746,  1388,   243,   290,   813,   291,   815,
    1391,   292,   237,   293,   294,   249,   295,   941,   250,   251,
     941,   360,   252,   941,   138,   139,   941,   253,   360,   522,
     296,   262,   297,   265,   314,   835,   263,   837,   838,   788,
     298,   786,   299,  1418,   300,  1420,   301,  1422,  1146,   845,
     310,   311,   805,   941,   302,   941,   303,   941,   304,   312,
     305,   441,   361,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   306,   824,   307,
     313,   351,   854,   855,   308,   830,   309,   565,   315,   571,
    1176,   565,   565,   575,   638,   316,   856,   857,   858,   859,
     860,   861,   862,   317,   334,   360,   655,   714,   656,   715,
     866,   346,   347,   348,   349,   350,   873,   565,   329,   726,
     351,   565,   565,   819,   820,   335,   360,   360,   360,   360,
     886,   565,   374,   821,   797,   565,  1112,   828,   237,   237,
     237,   352,   353,   798,   898,   565,   899,   923,   355,   390,
     799,   800,   393,   361,   801,   802,   365,   797,   967,     7,
       8,   565,   864,   958,   370,   565,   798,   960,   971,   375,
     972,   237,   419,   799,   800,   376,   392,   801,   802,  1004,
     565,  1005,  1006,   882,   883,   884,   885,   565,   441,  1007,
     892,   565,   565,  1008,  1009,   377,   535,    17,    18,   536,
      20,    21,   537,    23,   538,    25,  1094,    26,  1095,   955,
      29,    30,  1262,    32,    33,    34,   845,   959,   463,    37,
    1136,  1307,  1137,   565,  1188,  1170,  1189,  1094,  1275,  1231,
    1276,   378,   382,   797,   929,   930,   931,   977,   978,   565,
     387,  1287,   798,  1094,  1310,  1291,    55,    56,    57,   799,
     800,   388,   389,   801,   802,   797,   361,   361,   361,   415,
    1294,   998,  1295,  1094,   798,  1298,  1003,   565,   361,  1299,
     426,   799,   800,   404,   642,   801,   802,   405,  1013,  1015,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   565,  1188,  1318,  1353,   351,   565,
     968,  1372,   406,   565,   626,  1374,  1094,  1400,  1378,  1401,
     424,   427,   797,  1048,  1049,  1050,   565,  1411,  1410,  1412,
    1369,   798,  1059,  1061,  1094,   416,  1428,   797,   799,   800,
    1064,   417,   801,   802,   428,  1433,   798,  1434,   360,   420,
     797,   436,  1403,   799,   800,   429,   430,   801,   802,   798,
     797,   431,   433,  1081,  1082,  1083,   799,   800,   437,   798,
     801,   802,   438,   451,  1091,  1089,   799,   800,   446,  1097,
     801,   802,   447,   453,   454,   458,   459,   461,   464,   466,
    1100,   467,  1065,   469,   351,  1101,   531,   361,   532,   336,
     533,   144,   540,   642,   752,  1074,   578,   534,   583,  1405,
     584,   797,  1114,   588,   589,  1115,   595,   590,   591,   598,
     798,  1120,  1121,   597,  1407,  1278,  1123,   799,   800,   619,
     621,   801,   802,  1129,   623,   361,   635,  1409,   646,   649,
     718,  1141,   719,  1139,   720,  1140,   722,  1430,   723,   732,
     331,   724,   733,   737,   749,   748,  1156,   753,   750,   754,
     755,   757,   758,   759,   760,   762,   360,   763,  1116,   764,
     360,   772,   361,  1171,   774,   787,   797,   791,   792,   361,
    1180,   814,   826,   831,  1179,   798,   832,   833,   834,   842,
    1184,  1185,   799,   800,   725,   851,   801,   802,  1431,   853,
     849,   850,  1147,   863,  1150,   869,  1153,   868,   874,   875,
    1396,  1198,   877,  1348,   881,   878,   891,   896,  1164,   887,
     893,  1167,  1168,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   902,   903,   907,
     908,   351,  1216,   909,   910,  1424,   913,  1427,   914,   919,
     915,     7,     8,   771,   916,   917,   361,   918,   920,  1229,
     921,   440,   922,  1432,   785,   924,   932,  1440,   934,   933,
     935,  1237,   944,  1238,   945,   950,   360,   361,   361,   361,
     361,  1244,   946,   947,   948,   951,  1248,   952,   535,    17,
      18,   536,    20,    21,   537,    23,   538,    25,   953,    26,
     954,   956,    29,    30,   957,    32,    33,    34,   964,   969,
     360,    37,   556,   970,   331,   976,  1265,   973,  1268,   974,
    1271,   992,   975,   994,   841,   981,  1000,   999,  1010,  1018,
     360,  1035,  1022,  1239,  1284,  1025,  1026,  1029,    55,    56,
      57,  1017,  1023,  1289,  1290,  1024,  1028,  1030,  1031,  1038,
    1293,   721,  1036,  1051,  1039,  1040,  1041,  1297,  1045,  1062,
    1063,  1301,  1058,  1070,  1077,  1078,  1079,  1261,  1266,  1071,
    1269,  1075,  1272,  1080,  1084,  1088,  1098,  1102,  1103,   876,
    1280,  1105,  1108,  1283,  1109,  1110,  1097,  1282,  1111,  1117,
    1118,  1119,  1122,  1124,  1127,  1125,   653,  1126,  1130,  1135,
    1138,  1335,  1148,  1151,  1339,  1154,  1162,  1343,  1165,  1158,
    1169,  1346,  1181,  1187,  1190,   360,  1194,   360,  1191,  1192,
    1195,  1197,  1355,   894,   895,  1357,   897,  1196,   900,   901,
    1204,  1227,   904,   905,  1205,  1206,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
    1207,  1208,  1209,  1210,   351,  1211,  1214,  1381,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,  1351,
    1215,   360,  1349,   351,  1352,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   361,
    1217,  1219,  1221,   351,   906,  1223,  1416,  1225,  1415,  1234,
     961,   962,   963,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,  1228,  1236,  1241,
    1242,   351,  1249,  1436,    91,   318,  1254,  1251,  1393,  1255,
      95,    96,    97,  1256,  1257,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   342,   343,   344,   345,
     346,   347,   348,   349,   350,  1021,  1258,  1259,  1274,   351,
    1281,  1027,  1292,  1288,  1312,  1300,  1313,  1032,  1033,  1034,
    1321,  1328,  1316,  1037,  1330,  1331,  1333,  1336,  1042,  1043,
    1044,  1337,  1340,  1341,  1344,  1345,  1350,  1361,  1363,  1365,
    1367,  1375,  1383,  1060,  1376,  1386,  1389,   361,  1392,  1394,
    1398,   361,  1399,  1069,  1404,  1406,  1408,  1073,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,  1413,  1417,  1419,  1421,   351,  1423,  1425,   125,
    1087,  1435,  1437,  1438,   128,   129,   130,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,  1439,
     135,   136,  1441,   351,  1099,   137,    91,   225,  1020,  1012,
     140,  1322,    95,    96,    97,   143,    76,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   227,    84,
       0,   586,   441,     0,   949,  1104,     0,  1131,  1132,  1133,
    1134,     0,   228,     0,     0,   229,     0,   361,   230,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,    46,     0,     0,    49,     0,  1172,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1186,     0,     0,     0,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,  1163,     0,     0,     0,   137,     0,     0,
       0,     0,   409,     0,     0,     0,     0,   143,     0,   198,
     442,     0,     0,     0,     0,     0,     0,  1226,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,    91,   225,     0,   361,     0,   361,    95,
      96,    97,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   227,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1277,     0,   361,   228,
       0,     0,   229,     0,     0,   230,     0,   231,     0,     0,
       0,     0,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,     0,     0,
       0,    46,     0,     0,    49,    91,   318,     0,     0,     0,
       0,    95,    96,    97,  1311,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   125,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   135,
     359,     0,     0,     0,   137,     0,     0,  1360,     0,   140,
       0,     0,     0,     0,   143,     0,     0,   442,    91,    92,
      93,     0,    94,     0,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
       0,     0,   119,   120,   121,   122,     0,     0,   123,     0,
     125,     0,     7,     8,     0,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,     0,     0,     0,   137,     0,     0,     0,
       0,   140,     0,     0,   323,     0,   143,     0,   324,   535,
      17,    18,   536,    20,    21,   537,    23,   538,    25,     0,
      26,     0,     0,    29,    30,     0,    32,    33,    34,     0,
       0,     0,    37,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,   125,   126,   127,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,    55,
      56,    57,     0,     0,   135,   136,     0,     0,     0,   137,
       0,   138,   139,     0,   140,     0,   141,     0,   142,   143,
       0,   144,    91,   225,   226,     0,     0,     0,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,     0,     0,   654,     0,     0,
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
      91,   225,  1067,   143,     0,   233,    95,    96,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,     0,   229,
       0,     0,   230,   806,   231,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,     0,     0,     0,    46,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   535,    17,    18,   536,    20,    21,   537,
      23,   538,    25,     0,    26,     0,     0,    29,    30,     0,
      32,    33,    34,     0,     0,   125,    37,     0,     0,     0,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   232,     0,     0,
       0,   137,     0,    55,    56,    57,   140,     0,    91,   225,
    1358,   143,     0,  1068,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,     0,     0,   229,     0,     0,
     230,   836,   231,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,     0,     0,     0,    46,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   535,    17,    18,   536,    20,    21,   537,    23,   538,
      25,     0,    26,     0,     0,    29,    30,     0,    32,    33,
      34,     0,     0,   125,    37,     0,     0,     0,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   232,     0,     0,     0,   137,
       0,    55,    56,    57,   140,     0,    91,   225,     0,   143,
       0,  1359,    95,    96,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,     0,     0,   229,     0,     0,   230,  1314,
     231,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,     0,     0,     0,    46,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   535,
      17,    18,   536,    20,    21,   537,    23,   538,    25,     0,
      26,     0,  1001,    29,    30,     0,    32,    33,    34,     0,
       0,   125,    37,     0,     0,     0,   128,   129,   130,     0,
       0,  1076,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   232,     0,     0,     0,   137,     0,    55,
      56,    57,   140,     0,    91,   225,     0,   143,     0,   233,
      95,    96,    97,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,   229,     0,     0,   230,  1370,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,     0,
       0,     0,    46,     0,     0,    49,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   125,
    1193,     0,     0,   351,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   359,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,    91,   225,     0,   143,     0,   439,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   229,     0,     0,   230,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
      46,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,  1213,     0,
       0,     0,   351,     0,     0,     0,     0,   125,     0,     0,
       0,     0,   128,   129,   130,     0,     0,  1240,     0,     0,
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
       0,    49,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   125,     0,     0,     0,   351,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   232,     0,     0,
       0,   137,     0,     0,     0,     0,   140,     0,    91,   225,
       0,   143,     0,  1072,    95,    96,    97,     0,     0,    98,
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
       0,     0,     0,     0,   407,  1163,     0,     0,     0,   137,
       0,     0,     0,     0,   409,     0,    91,   318,   266,   143,
       0,   198,    95,    96,    97,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
     119,   120,   121,   122,     0,     0,   123,     0,     0,   125,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,  1320,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,     0,   632,     0,   143,     0,   633,    91,   318,
       0,     0,     0,     0,    95,    96,    97,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
    1368,   125,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,     0,     0,     0,   137,     0,     0,
       0,     0,   140,     0,    91,   318,     0,   143,     0,  1178,
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
       0,     0,   351,  1402,   444,     0,     0,     0,     0,   125,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,    91,   225,     0,   143,     0,  1014,    95,    96,
      97,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,     0,
       0,   229,     0,     0,   230,     0,   231,     0,     0,     0,
       0,     0,  1429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,     0,     0,     0,
      46,     0,   444,    49,     0,     0,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   564,   349,   350,
       0,   444,     0,     0,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   359,
       0,     0,     0,   137,    91,   318,   266,     0,   140,     0,
      95,    96,    97,   143,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   650,     0,   119,   120,
     121,   122,     0,     0,   123,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   742,
       0,     0,     0,   351,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   445,   349,   350,   829,     0,
       0,     0,   351,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   564,   349,   350,   966,     0,     0,
       0,   351,     0,     0,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,   125,
     126,   127,   351,     0,   128,   129,   130,     0,     0,  1144,
       0,  1145,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,     0,     0,     0,   137,     0,     0,     0,     0,
     140,     0,     0,     0,     0,   143,     0,     0,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
       0,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   911,     0,     0,     0,   351,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,    -4,     1,     0,   351,    -4,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
      -4,     0,     0,   351,     0,    -4,    -4,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       6,     0,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     9,     0,     0,    -4,    -4,    10,    11,     0,
      12,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     7,     8,    51,    52,     0,     0,     0,    53,
       0,     0,     0,     0,    54,    55,    56,    57,     0,     0,
      58,     0,    59,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    70,    71,   535,
      17,    18,   536,    20,    21,   537,    23,   538,    25,     0,
      26,     0,     0,    29,    30,     0,    32,    33,    34,     0,
       0,     0,    37,     0,     0,     0,     0,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,    55,
      56,    57,  1173,     0,  1174,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
    1263,     0,  1264,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
     767,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,   809,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,   827,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,   847,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,   928,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1142,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1160,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1200,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1201,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1202,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1203,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1235,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1279,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1285,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1286,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1302,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1305,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1308,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1329,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,  1332,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,     0,     0,
    1362,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,     0,  1364,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,  1366,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,     0,     0,  1379,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,   596,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,     0,     0,     0,     0,  1212,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   523,
       0,     0,     0,     0,   600,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     559,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   600,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   601,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   647,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   694,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     695,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   708,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   709,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   710,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   711,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     712,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   713,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   794,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   795,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,   796,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
     890,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,   926,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,   927,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,   965,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,  1092,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
    1093,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,  1113,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,     0,
       0,     0,  1245,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,     0,     0,     0,  1246,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,     0,     0,     0,  1252,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
    1324,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,     0,     0,     0,  1327,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   527,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   652,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   658,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   673,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   675,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   677,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   679,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     681,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   683,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   685,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   687,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   689,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   691,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   693,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   697,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   699,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   701,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     703,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   705,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   707,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   817,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,   818,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,   822,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,     0,     0,   823,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,     0,
       0,   825,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,     0,     0,   843,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,     0,     0,   983,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,     0,     0,
     985,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,     0,     0,   987,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,     0,     0,   989,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,     0,     0,   990,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
       0,     0,  1106,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,     0,     0,  1224,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   523,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   563,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   567,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   568,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     570,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   572,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   573,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   576,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   577,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   643,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   644,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   645,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   651,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   672,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     674,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   676,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   678,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   680,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   682,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   684,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   686,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   688,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   690,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   692,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     696,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   698,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   700,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   702,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   704,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   706,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   756,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   761,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   766,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   768,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     769,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   775,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   782,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   783,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   784,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,   808,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,   810,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,   811,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,   812,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,   816,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351,     0,
     982,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,     0,     0,     0,     0,   351,
       0,   984,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,     0,     0,     0,     0,
     351,     0,   986,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,     0,     0,     0,
       0,   351,     0,   988,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,     0,     0,
       0,     0,   351,     0,   993,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,     0,
       0,     0,     0,   351,     0,  1143,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   351,     0,  1159,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,     0,     0,     0,     0,   351,     0,  1177,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,     0,     0,     0,     0,   351,     0,  1323,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,     0,     0,     0,     0,   351,     0,  1377,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,     0,     0,     0,     0,   351
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-1070))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,  1070,     3,   206,     6,     5,     4,     6,   401,   402,
       4,     7,   150,   323,   217,     4,   326,   155,     6,     6,
       4,     6,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     5,    49,     6,     6,    52,   735,
       6,    55,   149,    57,   151,   311,   312,   313,   803,   315,
     316,   317,   255,     4,   257,     6,   807,    70,     4,    70,
       6,   149,    52,   151,     6,    55,    79,    57,    79,   179,
     180,   181,     7,    86,    87,    86,    87,    90,    91,    90,
      91,   139,   140,   139,   140,     6,     4,     5,    94,    39,
      40,     4,    42,    73,    74,    75,    76,   155,    13,   157,
     156,    81,   212,    49,    84,    92,    55,    92,   139,   140,
      94,    95,    96,    97,    52,     6,     7,    55,  1187,    37,
      38,    39,    40,   112,   155,    43,   104,   105,   149,   139,
     140,   104,   105,   135,   136,   137,    49,     6,   140,   141,
      53,     7,  1211,   144,   157,   155,   157,   157,   136,   151,
      63,   149,   154,   136,     6,   149,   156,   153,   160,   161,
     162,   163,   156,   165,   166,   167,   168,   156,   170,   171,
     172,   146,   147,   157,   156,   149,   151,   156,   153,   156,
     156,   877,   156,   158,   156,   156,   156,   156,   943,   191,
     156,   126,   127,   128,   129,   197,   198,   139,   140,     6,
     151,   119,   120,   155,   206,   157,    70,   139,   140,   412,
       6,   146,   147,   146,   147,    79,   161,   527,   153,   139,
     140,   166,    86,    87,   156,   170,    90,    91,   146,   147,
     232,   233,     7,     6,     7,   153,   156,   139,   140,   241,
     242,   243,   151,   245,   194,   195,   248,   249,   149,   251,
     453,   149,   202,   155,   149,   157,   206,  1326,   156,   261,
     126,   127,   128,   129,   139,   140,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,  1004,   589,
     590,   591,   314,   139,   140,   139,   140,   139,   140,   150,
     149,   149,   324,   149,   155,     4,     5,   326,   156,  1398,
     156,   155,   149,   155,     7,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     149,   126,   127,   128,   129,   146,   147,   359,    37,    38,
      39,    40,   153,   365,    43,   139,   140,   149,   370,   151,
     149,   146,   147,   375,   376,   377,   378,   156,   149,   324,
     382,   155,   139,   140,   149,   387,   388,   389,    59,    55,
      49,   156,   658,    52,   139,   140,    55,   149,   155,   151,
     401,   402,   404,   405,   406,   407,   408,   409,    55,     8,
     155,   413,   414,   415,   416,   417,   139,   140,   420,   139,
     140,   423,   424,   139,   140,   427,   428,   429,   430,   431,
     432,    52,   155,   435,    55,   155,    57,   439,     6,   155,
     119,   120,   444,   445,   139,   140,   150,   139,   140,   399,
     400,   155,   718,   126,   127,   128,   129,   407,   724,   150,
     155,   150,   464,   155,   155,   467,   155,   466,  1219,   149,
    1221,   151,  1223,   146,   147,    57,     5,   139,   140,   745,
     139,   140,   427,   428,   429,   149,    70,   151,   139,   140,
     149,    55,    55,   155,   439,    79,   152,   156,  1194,   155,
     139,   140,    86,    87,   155,   149,    90,    91,    37,    38,
      39,    40,  1267,    52,    43,  1270,   155,   149,  1273,   151,
     522,   149,   528,   151,   149,   156,   151,   529,   527,   139,
     140,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   155,   149,   156,   151,   148,
      55,     8,   139,   140,   139,   140,   558,   559,   157,   869,
     870,    55,   564,   565,  1315,   141,   142,   143,   155,   149,
     155,   151,   148,   157,    52,    52,   578,   139,   140,    55,
     149,   583,   588,   589,   590,   591,   588,   589,   590,   591,
     119,   120,  1347,   155,   596,     4,   146,   147,   600,   601,
     161,   151,     4,   153,   606,   166,   156,     4,   158,   170,
    1361,   149,  1363,   558,  1365,   149,   149,   619,   151,   621,
    1371,   149,    53,   151,   149,   149,   151,  1382,     6,   151,
    1385,   633,     4,  1388,   146,   147,  1391,     4,   640,   151,
     149,   153,   151,   156,     7,   647,   158,   649,   650,   599,
     149,   596,   151,  1404,   149,  1406,   151,  1408,  1051,   658,
     149,   149,   612,  1418,   149,  1420,   151,  1422,   149,   149,
     151,   232,   233,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   149,   633,   151,
     149,   148,   694,   695,   149,   640,   151,   155,   149,   157,
     157,   155,   155,   157,   157,   149,   708,   709,   710,   711,
     712,   713,   714,   149,   145,   717,   155,   151,   157,   153,
     722,   139,   140,   141,   142,   143,   728,   155,     4,   157,
     148,   155,   155,   157,   157,     6,   738,   739,   740,   741,
     742,   155,   173,   157,    70,   155,  1012,   157,   179,   180,
     181,     6,     6,    79,    55,   155,    57,   157,     5,   190,
      86,    87,   193,   324,    90,    91,   149,    70,     8,    12,
      13,   155,   717,   157,   149,   155,    79,   157,   155,   149,
     157,   212,   213,    86,    87,   156,     4,    90,    91,   155,
     155,   157,   157,   738,   739,   740,   741,   155,   359,   157,
     750,   155,   155,   157,   157,   149,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   155,    60,   157,   821,
      63,    64,  1215,    66,    67,    68,   825,   829,   259,    72,
       4,   157,     6,   155,   155,   157,   157,   155,   155,   157,
     157,   149,   149,    70,   794,   795,   796,   849,   850,   155,
     149,   157,    79,   155,   157,   157,    99,   100,   101,    86,
      87,   149,   149,    90,    91,    70,   427,   428,   429,   149,
     155,   870,   157,   155,    79,   157,   878,   155,   439,   157,
       6,    86,    87,   156,   445,    90,    91,   156,   890,   891,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   155,   155,   157,   157,   148,   155,
     150,   157,   156,   155,   157,   157,   155,   155,   157,   157,
     151,   156,    70,   925,   926,   927,   155,   155,   157,   157,
     157,    79,   934,   935,   155,   149,   157,    70,    86,    87,
     942,   149,    90,    91,   156,   155,    79,   157,   950,   149,
      70,     5,   157,    86,    87,   156,   151,    90,    91,    79,
      70,   151,   151,   965,   966,   967,    86,    87,     5,    79,
      90,    91,     5,   153,   976,   974,    86,    87,     6,   981,
      90,    91,     6,   156,   107,     6,     6,     6,   151,     4,
     996,   156,   942,     6,   148,   997,   153,   558,     7,     6,
     151,   156,     6,   564,   565,   950,     7,   157,     7,   157,
       7,    70,  1014,   149,   149,  1017,     7,   149,   149,     6,
      79,  1023,  1024,   150,   157,  1228,  1028,    86,    87,     7,
       7,    90,    91,  1035,     6,   596,     4,   157,   104,   156,
     155,  1047,   150,  1045,   150,  1047,   155,   157,   150,     6,
    1051,   155,     4,   152,     4,     6,  1058,   107,     7,     7,
       7,     7,   107,     7,     7,   107,  1068,     7,  1018,     7,
    1072,     4,   633,  1075,     6,   153,    70,   157,   157,   640,
    1086,     6,   152,     7,  1086,    79,     7,     7,   153,     6,
    1092,  1093,    86,    87,   525,   156,    90,    91,   157,     6,
     149,   149,  1052,     4,  1054,   152,  1056,     6,     6,     6,
    1376,  1113,     7,  1316,     6,   151,     7,     7,  1068,   136,
      55,  1071,  1072,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     7,    57,     7,
       7,   148,  1144,     7,     7,  1411,     6,  1413,     7,     7,
     150,    12,    13,   584,   150,   150,   717,   150,     7,  1161,
       7,  1163,     6,   157,   595,     4,     4,  1433,   156,     6,
     149,  1173,     7,  1175,     6,   156,  1178,   738,   739,   740,
     741,  1183,     7,     7,     7,     6,  1188,     6,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     6,    60,
      55,     6,    63,    64,     6,    66,    67,    68,     4,     4,
    1212,    72,     6,     4,  1215,   149,  1218,     6,  1220,     4,
    1222,   150,     6,   150,   655,   156,     7,   153,     6,    63,
    1232,     4,     6,  1178,  1236,     6,     6,     6,    99,   100,
     101,   156,   156,  1245,  1246,   156,   156,     6,     5,     7,
    1252,     6,     6,   156,     7,     7,     7,  1259,     7,     6,
       6,  1263,   151,   156,   152,     6,     6,  1212,  1218,   156,
    1220,   156,  1222,   103,     6,     6,   153,     6,     4,     6,
    1230,     6,     6,  1233,     6,     6,  1288,  1232,     6,     6,
       6,     6,     6,     5,   107,     6,   157,     6,     6,     6,
       6,  1303,     6,     6,  1306,     6,     6,  1309,     6,   155,
       6,  1313,   157,   156,     4,  1317,     7,  1319,     6,     6,
       6,     6,  1324,   754,   755,  1327,   757,   153,   759,   760,
       5,     7,   763,   764,    53,     6,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       6,     6,     6,     6,   148,   156,     6,  1359,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,  1319,
     156,  1373,  1317,   148,  1319,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   950,
     157,   156,   156,   148,     6,   156,  1402,     6,  1400,     6,
     831,   832,   833,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   156,   102,     6,
       6,   148,     6,  1429,     3,     4,     6,   105,  1373,     6,
       9,    10,    11,     6,     6,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   896,     6,   156,     6,   148,
       6,   902,     6,   156,     6,   157,    70,   908,   909,   910,
       6,     4,   156,   914,     6,     6,     6,     6,   919,   920,
     921,     6,     6,     6,     6,   157,     6,   156,   156,   156,
       6,     6,     6,   934,   156,     6,     6,  1068,     6,     6,
     156,  1072,     6,   944,   156,   156,   156,   948,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   156,     6,     6,     6,   148,     6,     6,   118,
     971,     6,     6,     6,   123,   124,   125,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     6,
     139,   140,     6,   148,   995,   144,     3,     4,   895,   889,
     149,  1288,     9,    10,    11,   154,     3,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     3,
      -1,   381,  1163,    -1,     6,  1000,    -1,  1038,  1039,  1040,
    1041,    -1,    49,    -1,    -1,    52,    -1,  1178,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,  1080,
      -1,  1212,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1094,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,   156,
     157,    -1,    -1,    -1,    -1,    -1,    -1,  1158,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,  1317,    -1,  1319,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1227,    -1,  1359,    49,
      -1,    -1,    52,    -1,    -1,    55,    -1,    57,    -1,    -1,
      -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    81,    -1,    -1,    84,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,  1275,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,   118,    -1,
      -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,    -1,    -1,    -1,   144,    -1,    -1,  1328,    -1,   149,
      -1,    -1,    -1,    -1,   154,    -1,    -1,   157,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    43,    -1,
     118,    -1,    12,    13,    -1,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,   152,    -1,   154,    -1,   156,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    99,
     100,   101,    -1,    -1,   139,   140,    -1,    -1,    -1,   144,
      -1,   146,   147,    -1,   149,    -1,   151,    -1,   153,   154,
      -1,   156,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,   157,    -1,    -1,
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
      60,    -1,     6,    63,    64,    -1,    66,    67,    68,    -1,
      -1,   118,    72,    -1,    -1,    -1,   123,   124,   125,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,   144,    -1,    99,
     100,   101,   149,    -1,     3,     4,    -1,   154,    -1,   156,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    55,   157,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    -1,    -1,    84,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,    -1,   148,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   118,
       6,    -1,    -1,   148,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
     149,    -1,     3,     4,    -1,   154,    -1,   156,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     6,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,     6,    -1,    -1,
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
      -1,    84,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   118,    -1,    -1,    -1,   148,
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
      -1,    -1,   148,     7,     8,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
     149,    -1,     3,     4,    -1,   154,    -1,   156,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    55,    -1,    57,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      81,    -1,     8,    84,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,     8,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,   144,     3,     4,     5,    -1,   149,    -1,
       9,    10,    11,   154,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     8,    -1,    37,    38,
      39,    40,    -1,    -1,    43,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     8,
      -1,    -1,    -1,   148,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     8,    -1,
      -1,    -1,   148,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     8,    -1,    -1,
      -1,   148,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   118,
     119,   120,   148,    -1,   123,   124,   125,    -1,    -1,   155,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    70,    -1,    -1,    -1,   148,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,     0,     1,    -1,   148,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      36,    -1,    -1,   148,    -1,    41,    42,    -1,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,    -1,    88,    89,    -1,    -1,    -1,    93,    12,    13,
      -1,    -1,    98,    99,   100,   101,    -1,    -1,   104,    -1,
     106,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    36,    -1,    -1,   121,   122,    41,    42,    -1,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    12,    13,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,    -1,    -1,
     104,    -1,   106,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    99,
     100,   101,   155,    -1,   157,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   157,   130,   131,   132,   133,   134,   135,   136,
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
      -1,   156,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
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
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   130,   131,   132,
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
     143,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,
      -1,    -1,   152,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,   152,   130,   131,   132,   133,
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
     142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,    -1,   148,    -1,   150,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   148
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
       6,   151,     4,     4,     5,   156,     5,   156,     6,   156,
       4,   151,   153,   158,   182,   156,     5,   246,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   151,   149,   151,   149,   151,   149,   151,   149,   151,
     149,   149,   149,   149,     7,   149,   149,   149,     4,   233,
     233,   233,   233,   152,   156,   233,     4,   104,   105,     4,
       4,   198,   199,   200,   238,     6,     6,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   148,     6,     6,   233,     5,   233,   185,   233,   140,
     233,   240,   241,   233,   233,   149,   233,   241,   233,   233,
     149,   241,   233,   233,   238,   149,   156,   149,   149,   239,
     239,   239,   149,   194,   195,   196,   197,   149,   149,   149,
     238,   233,     4,   238,   235,   235,   235,   233,   233,   139,
     140,   156,   156,   235,   156,   156,   156,   139,   140,   149,
     200,   235,   156,   149,   156,   149,   149,   149,   239,   238,
     149,     4,     6,   151,   151,   200,     6,   156,   156,   156,
     151,   151,   151,   151,     5,   156,     5,     5,     5,   156,
     233,   240,   157,   241,     8,   141,     6,     6,   233,   233,
     233,   153,   233,   156,   107,   233,   233,   233,     6,     6,
     200,     6,   200,   238,   151,   233,     4,   156,   166,     6,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,     4,   245,   246,   245,   245,   245,   233,   245,
     245,   245,   151,   150,     7,   181,   241,   152,     7,   181,
     182,   153,     7,   151,   157,    49,    52,    55,    57,   193,
       6,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,     6,   150,   155,   155,
     152,   155,   184,   150,   141,   155,   157,   150,   150,   233,
     150,   157,   150,   150,   233,   157,   150,   150,     7,   233,
     233,   233,   233,     7,     7,   225,   225,   233,   149,   149,
     149,   149,   233,   233,   233,     7,   156,   150,     6,   155,
     155,   155,   235,   235,   199,   199,   155,   233,   233,   233,
     233,   211,   155,   200,   233,   233,   233,   233,   233,     7,
     226,     7,   233,     6,   233,   233,   157,   241,   241,   241,
     233,   233,   152,   156,   233,     4,   233,   241,   157,   233,
     156,   233,   240,   150,   150,   150,   104,   155,   200,   156,
       8,   150,   152,   157,   157,   155,   157,   233,   152,   182,
     233,     4,    94,    95,    96,    97,   157,   169,   173,   176,
     178,   179,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   150,   152,
     150,   152,   150,   152,   155,   155,   150,   152,   150,   152,
     150,   152,   150,   152,   150,   152,   150,   152,   155,   155,
     155,   155,   155,   155,   151,   153,   150,   155,   155,   150,
     150,     6,   155,   150,   155,   238,   157,   153,   181,   182,
     246,   233,     6,     4,     4,   156,   243,   152,   156,   156,
     156,   156,     8,     6,   136,   163,   241,   233,     6,     4,
       7,   233,   240,   107,     7,     7,   150,     7,   107,     7,
       7,   150,   107,     7,     7,   233,   150,   157,   150,   150,
     233,   238,     4,   224,     6,   150,   190,   233,   246,   190,
     190,   190,   150,   150,   150,   238,   241,   153,   235,   233,
     233,   157,   157,   233,   155,   155,   155,    70,    79,    86,
      87,    90,    91,   221,   222,   235,   157,   208,   150,   157,
     150,   150,   150,   233,     6,   233,   150,   152,   152,   157,
     157,   157,   152,   152,   241,   152,   152,   157,   157,     8,
     241,     7,     7,     7,   153,   233,   157,   233,   233,     7,
     153,   238,     6,   152,   153,   182,   245,   157,   170,   149,
     149,   156,   180,     6,   233,   233,   233,   233,   233,   233,
     233,   233,   233,     4,   241,   245,   233,   245,     6,   152,
       4,   104,   105,   233,     6,     6,     6,     7,   151,   242,
     244,     6,   241,   241,   241,   241,   233,   136,   245,   150,
     155,     7,   235,    55,   238,   238,     7,   238,    55,    57,
     238,   238,     7,    57,   238,   238,     6,     7,     7,     7,
       7,    70,   223,     6,     7,   150,   150,   150,   150,     7,
       7,     7,     6,   157,     4,   155,   155,   155,   157,   235,
     235,   235,     4,     6,   156,   149,     6,    92,     6,    92,
     157,   222,   155,   221,     7,     6,     7,     7,     7,     6,
     156,     6,     6,     6,    55,   233,     6,     6,   157,   233,
     157,   238,   238,   238,     4,   155,     8,     8,   150,     4,
       4,   155,   157,     6,     4,     6,   149,   233,   233,   237,
     238,   156,   150,   152,   150,   152,   150,   152,   150,   152,
     152,   150,   150,   150,   150,   181,     7,   181,   182,   153,
       7,     6,   242,   233,   155,   157,   157,   157,   157,   157,
       6,     6,   163,   233,   156,   233,     6,   156,    63,   192,
     192,   238,     6,   156,   156,     6,     6,   238,   156,     6,
       6,     5,   238,   238,   238,     4,     6,   238,     7,     7,
       7,     7,   238,   238,   238,     7,     6,     7,   233,   233,
     233,   156,   155,   157,   155,   157,   155,   157,   151,   233,
     238,   233,     6,     6,   233,   235,   157,     5,   156,   238,
     156,   156,   156,   238,   241,   156,     6,   152,     6,     6,
     103,   233,   233,   233,     6,     6,     7,   238,     6,   182,
     167,   233,   155,   155,   155,   157,   168,   233,   153,   238,
     246,   233,     6,     4,   243,     6,   152,   242,     6,     6,
       6,     6,   245,   155,   233,   233,   235,     6,     6,     6,
     233,   233,     6,   233,     5,     6,     6,   107,   191,   233,
       6,   238,   238,   238,   238,     6,     4,     6,     6,   233,
     233,   246,   157,   150,   155,   157,   199,   235,     6,   212,
     235,     6,   213,   235,     6,   214,   233,   157,   155,   150,
     157,   155,     6,   140,   235,     6,   237,   235,   235,     6,
     157,   233,   238,   155,   157,     8,   157,   150,   156,   233,
     246,   157,   150,   155,   233,   233,   238,   156,   155,   157,
       4,     6,     6,     6,     7,     6,   153,     6,   233,   186,
     157,   157,   157,   157,     5,    53,     6,     6,     6,     6,
       6,   156,   156,     6,     6,   156,   233,   157,   155,   156,
     155,   156,   155,   156,   152,     6,   238,     7,   156,   233,
     155,   157,   155,   155,     6,   157,   102,   233,   233,   241,
       6,     6,     6,   171,   233,   155,   155,   237,   233,     6,
     242,   105,   155,   188,     6,     6,     6,     6,     6,   156,
     237,   241,   199,   155,   157,   233,   235,   221,   233,   235,
     221,   233,   235,   221,     6,   155,   157,   238,   200,   157,
     235,     6,   241,   235,   233,   157,   157,   157,   156,   233,
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 164 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 175 "Gmsh.y"
    { return 1; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 176 "Gmsh.y"
    { return 1; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 179 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 183 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 196 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 200 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 207 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 26:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 27:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 28:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 29:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 30:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 306 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 320 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 322 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 327 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 329 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 438 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 448 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 457 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 464 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 474 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 483 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 492 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 499 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 509 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 517 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 54:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 565 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 571 "Gmsh.y"
    {
    }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 578 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 579 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 580 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 581 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 582 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 586 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 587 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 65:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 69:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 70:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 799 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 808 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 814 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 74:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 75:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 859 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 868 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 880 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 885 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 80:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 81:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 947 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 85:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 86:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 88:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 93:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 94:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1099 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1101 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
    }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1113 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1119 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 101:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 102:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1157 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1170 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1174 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1184 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1188 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[(4) - (5)].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[(4) - (5)].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1200 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1204 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1237 "Gmsh.y"
    {
      curPhysDim = 0;
    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 113:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 114:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 115:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 116:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 117:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 118:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 119:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 120:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 121:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 122:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 123:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1494 "Gmsh.y"
    {
      curPhysDim = 1;
    }
    break;

  case 125:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 126:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 127:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1574 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1580 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1586 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 131:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 132:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 133:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 134:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 135:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1708 "Gmsh.y"
    {
      curPhysDim = 2;
    }
    break;

  case 137:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 138:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 139:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 140:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1783 "Gmsh.y"
    {
      curPhysDim = 3;
    }
    break;

  case 142:

/* Line 1806 of yacc.c  */
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
    }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1809 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1814 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1819 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1824 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1829 "Gmsh.y"
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
    }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1852 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1858 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1868 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1869 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1874 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1878 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1882 "Gmsh.y"
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
    }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1905 "Gmsh.y"
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
    }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1928 "Gmsh.y"
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
    }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1951 "Gmsh.y"
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
    }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1979 "Gmsh.y"
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
    }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 2000 "Gmsh.y"
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
    }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 2024 "Gmsh.y"
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
    }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 2045 "Gmsh.y"
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
    }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 2066 "Gmsh.y"
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
    }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 2086 "Gmsh.y"
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
    }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 2198 "Gmsh.y"
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
    }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 2217 "Gmsh.y"
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
    }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 2256 "Gmsh.y"
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
    }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 2364 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 2373 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 2379 "Gmsh.y"
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
    }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 2394 "Gmsh.y"
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
    }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 2422 "Gmsh.y"
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
    }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 2439 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 2453 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 2459 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 2465 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 2474 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 2488 "Gmsh.y"
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
    }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 2533 "Gmsh.y"
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
    }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 2550 "Gmsh.y"
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
    }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 2565 "Gmsh.y"
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
    }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 2584 "Gmsh.y"
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
     }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 2596 "Gmsh.y"
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
    }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 2620 "Gmsh.y"
    {
      exit(0);
    }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 2624 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 2631 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 2637 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 2642 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 2648 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 2652 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 2656 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 2666 "Gmsh.y"
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
    }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 2683 "Gmsh.y"
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
    }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 2700 "Gmsh.y"
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
    }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 2721 "Gmsh.y"
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
    }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 2742 "Gmsh.y"
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
    }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 2777 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 2785 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 2791 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 2798 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 2802 "Gmsh.y"
    {
    }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 2811 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 2819 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 2827 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 2835 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 2840 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 2848 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 2853 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 2861 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 2866 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 2874 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 2879 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 2887 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 2894 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 2901 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 2908 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 2915 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 2922 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 2929 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 2936 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 2943 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 2950 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 2955 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 2962 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 2967 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 2974 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 2986 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 2991 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 2998 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 3010 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 3015 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 3022 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 3027 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 3034 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 3039 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 3046 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 3051 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 3062 "Gmsh.y"
    {
    }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 3065 "Gmsh.y"
    {
    }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 3071 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 3080 "Gmsh.y"
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
    }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 3100 "Gmsh.y"
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
    }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 3123 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 3127 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 3131 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 3135 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 3139 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 3143 "Gmsh.y"
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
    }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 3162 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 3174 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 3178 "Gmsh.y"
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
    }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 3193 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 3197 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
        (yyval.i) = -1;
      else // alternated
        (yyval.i) = 0;
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 3209 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 3213 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 3218 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 3222 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 3229 "Gmsh.y"
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
    }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 3285 "Gmsh.y"
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
    }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 3355 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 3360 "Gmsh.y"
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
    }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 3427 "Gmsh.y"
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
    }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 3463 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 3472 "Gmsh.y"
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
    }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 3515 "Gmsh.y"
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
    }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 3540 "Gmsh.y"
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
    }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 3568 "Gmsh.y"
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
    }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 3611 "Gmsh.y"
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
    }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 3634 "Gmsh.y"
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
    }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 3657 "Gmsh.y"
    {
    }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 3660 "Gmsh.y"
    {
    }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 3669 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 3673 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 3683 "Gmsh.y"
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
    }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 3717 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 3718 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 3723 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      if(GModel::current()->getDim() != 1) dim.push_back(1);
      if(GModel::current()->getDim() != 2) dim.push_back(2);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 3730 "Gmsh.y"
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
    }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 3743 "Gmsh.y"
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
    }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 3762 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (9)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(5) - (9)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(7) - (9)].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (9)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(5) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 3789 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 3790 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 3791 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 3792 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 3793 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 3794 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 3795 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 3796 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 3798 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 3804 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 3805 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 3806 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 3807 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 3808 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 3809 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 3810 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 3811 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 3812 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 3813 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 3814 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 3815 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 3816 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 3817 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 3818 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 3819 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 3820 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 3821 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 3822 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 3823 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 3824 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 3825 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 3826 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 3827 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 3828 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 3829 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 3830 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 3831 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 3832 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 3833 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 3834 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 3835 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 3837 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 3838 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 3839 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 3840 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 3841 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 3842 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 3843 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 3844 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 3845 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 3846 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 3847 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 3848 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 3849 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 3850 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 3851 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 3852 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 3853 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 3854 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 3855 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 3856 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 3857 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 3866 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 3867 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 3868 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 3869 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 3870 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 3871 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 3872 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 3877 "Gmsh.y"
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
    }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 3897 "Gmsh.y"
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
    }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 3916 "Gmsh.y"
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
    }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 3934 "Gmsh.y"
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
    }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 3946 "Gmsh.y"
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
    }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 3963 "Gmsh.y"
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
    }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 3984 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 3989 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 3994 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d)){
	d += (yyvsp[(4) - (4)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 4004 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d)){
	d += (yyvsp[(7) - (7)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 4014 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 4022 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 4026 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 4030 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 4034 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 4038 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 4045 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 4049 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 4053 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 4057 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 4064 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 4069 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 4076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 4081 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 4085 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 4090 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 4094 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 4102 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 4113 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 4117 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 4129 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 4137 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 4145 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 4152 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d) || ((yyvsp[(1) - (5)].d) < (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) < 0) || ((yyvsp[(1) - (5)].d) > (yyvsp[(3) - (5)].d) && (yyvsp[(5) - (5)].d) > 0)){
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
	List_Add((yyval.l), &((yyvsp[(1) - (5)].d)));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 4163 "Gmsh.y"
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
    }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 4183 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 4187 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 4191 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 4195 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 4199 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 4209 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 4219 "Gmsh.y"
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
    }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 4231 "Gmsh.y"
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
    }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 4243 "Gmsh.y"
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
    }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 4264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 4269 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 4273 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 4277 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 4289 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 4293 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 4305 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 4312 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 4322 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 4326 "Gmsh.y"
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
    }
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 4341 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 4346 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 4353 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 4357 "Gmsh.y"
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
    }
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 4370 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 4378 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 4389 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 4393 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 4401 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 4409 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 4417 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 4425 "Gmsh.y"
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
    }
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 4439 "Gmsh.y"
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
    }
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 4453 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 4457 "Gmsh.y"
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
    }
    break;



/* Line 1806 of yacc.c  */
#line 10132 "Gmsh.tab.cpp"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 4477 "Gmsh.y"


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

