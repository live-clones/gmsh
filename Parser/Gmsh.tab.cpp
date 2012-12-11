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
     tStrFind = 297,
     tBoundingBox = 298,
     tDraw = 299,
     tToday = 300,
     tSyncModel = 301,
     tCreateTopology = 302,
     tCreateTopologyNoHoles = 303,
     tDistanceFunction = 304,
     tDefineConstant = 305,
     tPoint = 306,
     tCircle = 307,
     tEllipse = 308,
     tLine = 309,
     tSphere = 310,
     tPolarSphere = 311,
     tSurface = 312,
     tSpline = 313,
     tVolume = 314,
     tCharacteristic = 315,
     tLength = 316,
     tParametric = 317,
     tElliptic = 318,
     tRefineMesh = 319,
     tPlane = 320,
     tRuled = 321,
     tTransfinite = 322,
     tComplex = 323,
     tPhysical = 324,
     tCompound = 325,
     tPeriodic = 326,
     tUsing = 327,
     tPlugin = 328,
     tDegenerated = 329,
     tRotate = 330,
     tTranslate = 331,
     tSymmetry = 332,
     tDilate = 333,
     tExtrude = 334,
     tLevelset = 335,
     tRecombine = 336,
     tSmoother = 337,
     tSplit = 338,
     tDelete = 339,
     tCoherence = 340,
     tIntersect = 341,
     tMeshAlgorithm = 342,
     tLayers = 343,
     tHole = 344,
     tAlias = 345,
     tAliasWithOptions = 346,
     tQuadTriDbl = 347,
     tQuadTriSngl = 348,
     tRecombLaterals = 349,
     tTransfQuadTri = 350,
     tText2D = 351,
     tText3D = 352,
     tInterpolationScheme = 353,
     tTime = 354,
     tCombine = 355,
     tBSpline = 356,
     tBezier = 357,
     tNurbs = 358,
     tNurbsOrder = 359,
     tNurbsKnots = 360,
     tColor = 361,
     tColorTable = 362,
     tFor = 363,
     tIn = 364,
     tEndFor = 365,
     tIf = 366,
     tEndIf = 367,
     tExit = 368,
     tAbort = 369,
     tField = 370,
     tReturn = 371,
     tCall = 372,
     tFunction = 373,
     tShow = 374,
     tHide = 375,
     tGetValue = 376,
     tGetEnv = 377,
     tGetString = 378,
     tHomology = 379,
     tCohomology = 380,
     tGMSH_MAJOR_VERSION = 381,
     tGMSH_MINOR_VERSION = 382,
     tGMSH_PATCH_VERSION = 383,
     tAFFECTDIVIDE = 384,
     tAFFECTTIMES = 385,
     tAFFECTMINUS = 386,
     tAFFECTPLUS = 387,
     tOR = 388,
     tAND = 389,
     tNOTEQUAL = 390,
     tEQUAL = 391,
     tGREATEROREQUAL = 392,
     tLESSOREQUAL = 393,
     UNARYPREC = 394,
     tMINUSMINUS = 395,
     tPLUSPLUS = 396
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
#line 361 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 373 "Gmsh.tab.cpp"

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
#define YYLAST   8055

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  442
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1521

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   396

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   147,     2,   157,     2,   146,     2,     2,
     152,   153,   144,   142,   158,   143,   156,   145,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     138,     2,   139,   133,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   154,     2,   155,   151,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   159,     2,   160,   161,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   134,   135,
     136,   137,   140,   141,   148,   149,   150
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
    1149,  1165,  1168,  1171,  1174,  1177,  1184,  1193,  1202,  1213,
    1215,  1218,  1220,  1224,  1229,  1231,  1237,  1249,  1263,  1264,
    1272,  1273,  1287,  1288,  1304,  1305,  1312,  1321,  1330,  1339,
    1352,  1365,  1378,  1393,  1408,  1423,  1424,  1437,  1438,  1451,
    1452,  1465,  1466,  1483,  1484,  1501,  1502,  1519,  1520,  1539,
    1540,  1559,  1560,  1579,  1581,  1584,  1590,  1598,  1608,  1611,
    1614,  1618,  1621,  1625,  1635,  1642,  1643,  1647,  1648,  1650,
    1651,  1654,  1655,  1658,  1666,  1673,  1682,  1688,  1692,  1700,
    1706,  1713,  1720,  1733,  1744,  1755,  1766,  1777,  1780,  1784,
    1791,  1793,  1795,  1798,  1804,  1812,  1823,  1825,  1829,  1832,
    1835,  1838,  1842,  1846,  1850,  1854,  1858,  1862,  1866,  1870,
    1874,  1878,  1882,  1886,  1890,  1894,  1900,  1905,  1910,  1915,
    1920,  1925,  1930,  1935,  1940,  1945,  1950,  1957,  1962,  1967,
    1972,  1977,  1982,  1987,  1994,  2001,  2008,  2013,  2018,  2023,
    2028,  2033,  2038,  2043,  2048,  2053,  2058,  2063,  2070,  2075,
    2080,  2085,  2090,  2095,  2100,  2107,  2114,  2121,  2126,  2128,
    2130,  2132,  2134,  2136,  2138,  2140,  2142,  2148,  2153,  2158,
    2161,  2167,  2171,  2178,  2183,  2191,  2198,  2205,  2207,  2210,
    2213,  2217,  2221,  2233,  2243,  2251,  2259,  2261,  2265,  2267,
    2269,  2272,  2276,  2281,  2287,  2289,  2291,  2294,  2298,  2302,
    2308,  2313,  2316,  2319,  2322,  2325,  2331,  2337,  2343,  2349,
    2351,  2353,  2357,  2361,  2366,  2373,  2380,  2382,  2384,  2388,
    2392,  2402,  2410,  2412,  2418,  2422,  2429,  2431,  2435,  2437,
    2439,  2443,  2450,  2452,  2454,  2459,  2466,  2473,  2478,  2483,
    2488,  2495,  2497
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     163,     0,    -1,   164,    -1,     1,     6,    -1,    -1,   164,
     165,    -1,   168,    -1,   167,    -1,   186,    -1,   199,    -1,
     204,    -1,   208,    -1,   209,    -1,   210,    -1,   213,    -1,
     233,    -1,   234,    -1,   235,    -1,   236,    -1,   212,    -1,
     211,    -1,   207,    -1,   238,    -1,   139,    -1,   139,   139,
      -1,    36,   152,     5,   153,     6,    -1,    37,   152,     5,
     153,     6,    -1,    36,   152,     5,   153,   166,   251,     6,
      -1,    36,   152,     5,   158,   247,   153,     6,    -1,    37,
     152,     5,   158,   247,   153,     6,    -1,    36,   152,     5,
     158,   247,   153,   166,   251,     6,    -1,     4,     5,   159,
     169,   160,     6,    -1,    90,     4,   154,   239,   155,     6,
      -1,    91,     4,   154,   239,   155,     6,    -1,    -1,   169,
     172,    -1,   169,   176,    -1,   169,   179,    -1,   169,   181,
      -1,   169,   182,    -1,   239,    -1,   170,   158,   239,    -1,
     239,    -1,   171,   158,   239,    -1,    -1,    -1,     4,   173,
     152,   170,   153,   174,   159,   171,   160,     6,    -1,   251,
      -1,   175,   158,   251,    -1,    -1,    96,   152,   239,   158,
     239,   158,   239,   153,   177,   159,   175,   160,     6,    -1,
     251,    -1,   178,   158,   251,    -1,    -1,    97,   152,   239,
     158,   239,   158,   239,   158,   239,   153,   180,   159,   178,
     160,     6,    -1,    98,   159,   243,   160,   159,   243,   160,
       6,    -1,    98,   159,   243,   160,   159,   243,   160,   159,
     243,   160,   159,   243,   160,     6,    -1,    -1,    99,   183,
     159,   171,   160,     6,    -1,     7,    -1,   132,    -1,   131,
      -1,   130,    -1,   129,    -1,   150,    -1,   149,    -1,    50,
     154,   188,   155,     6,    -1,     4,   184,   244,     6,    -1,
       4,   154,   155,   184,   244,     6,    -1,     4,   154,   239,
     155,   184,   239,     6,    -1,     4,   152,   239,   153,   184,
     239,     6,    -1,     4,   154,   159,   247,   160,   155,   184,
     244,     6,    -1,     4,   152,   159,   247,   160,   153,   184,
     244,     6,    -1,     4,   185,     6,    -1,     4,   154,   239,
     155,   185,     6,    -1,     4,     7,   252,     6,    -1,     4,
     156,     4,     7,   252,     6,    -1,     4,   154,   239,   155,
     156,     4,     7,   252,     6,    -1,     4,   156,     4,   184,
     239,     6,    -1,     4,   154,   239,   155,   156,     4,   184,
     239,     6,    -1,     4,   156,     4,   185,     6,    -1,     4,
     154,   239,   155,   156,     4,   185,     6,    -1,     4,   156,
     106,   156,     4,     7,   248,     6,    -1,     4,   154,   239,
     155,   156,   106,   156,     4,     7,   248,     6,    -1,     4,
     156,   107,     7,   249,     6,    -1,     4,   154,   239,   155,
     156,   107,     7,   249,     6,    -1,     4,   115,     7,   239,
       6,    -1,   115,   154,   239,   155,     7,     4,     6,    -1,
     115,   154,   239,   155,   156,     4,     7,   239,     6,    -1,
     115,   154,   239,   155,   156,     4,     7,   252,     6,    -1,
     115,   154,   239,   155,   156,     4,     7,   159,   247,   160,
       6,    -1,   115,   154,   239,   155,   156,     4,     6,    -1,
      73,   152,     4,   153,   156,     4,     7,   239,     6,    -1,
      73,   152,     4,   153,   156,     4,     7,   252,     6,    -1,
      -1,   158,    -1,    -1,   188,   187,     4,    -1,   188,   187,
       4,     7,   239,    -1,    -1,   188,   187,     4,     7,   159,
     239,   189,   192,   160,    -1,   188,   187,     4,     7,   252,
      -1,    -1,   188,   187,     4,     7,   159,   252,   190,   194,
     160,    -1,   239,     7,   252,    -1,   191,   158,   239,     7,
     252,    -1,    -1,   192,   193,    -1,   158,     4,   244,    -1,
     158,     4,   159,   191,   160,    -1,   158,     4,     5,    -1,
      -1,   194,   195,    -1,   158,     4,   239,    -1,   158,     4,
       5,    -1,   158,     4,   159,   253,   160,    -1,   239,    -1,
     252,    -1,    -1,   109,    55,   159,   239,   160,    -1,    -1,
      65,   241,    -1,    51,   152,   239,   153,     7,   241,     6,
      -1,    -1,    69,    51,   200,   152,   196,   153,     7,   244,
       6,    -1,    60,    61,   244,     7,   239,     6,    -1,    54,
     152,   239,   153,     7,   244,     6,    -1,    74,    54,   244,
       6,    -1,    58,   152,   239,   153,     7,   244,     6,    -1,
      52,   152,   239,   153,     7,   244,   198,     6,    -1,    53,
     152,   239,   153,     7,   244,   198,     6,    -1,   101,   152,
     239,   153,     7,   244,     6,    -1,   102,   152,   239,   153,
       7,   244,     6,    -1,   103,   152,   239,   153,     7,   244,
     105,   244,   104,   239,     6,    -1,    54,     4,   152,   239,
     153,     7,   244,     6,    -1,    70,    54,   152,   239,   153,
       7,   244,     6,    -1,    -1,    69,    54,   201,   152,   196,
     153,     7,   244,     6,    -1,    65,    57,   152,   239,   153,
       7,   244,     6,    -1,    66,    57,   152,   239,   153,     7,
     244,   197,     6,    -1,    12,    13,     6,    -1,    13,    57,
     239,     6,    -1,    62,    57,   152,   239,   153,     7,     5,
       5,     5,     6,    -1,    55,   152,   239,   153,     7,   244,
       6,    -1,    56,   152,   239,   153,     7,   244,     6,    -1,
      57,     4,   152,   239,   153,     7,   244,     6,    -1,    70,
      57,   152,   239,   153,     7,   244,     6,    -1,    70,    57,
     152,   239,   153,     7,   244,     4,   159,   243,   160,     6,
      -1,    -1,    69,    57,   202,   152,   196,   153,     7,   244,
       6,    -1,    68,    59,   152,   239,   153,     7,   244,     6,
      -1,    59,   152,   239,   153,     7,   244,     6,    -1,    70,
      59,   152,   239,   153,     7,   244,     6,    -1,    -1,    69,
      59,   203,   152,   196,   153,     7,   244,     6,    -1,    76,
     241,   159,   205,   160,    -1,    75,   159,   241,   158,   241,
     158,   239,   160,   159,   205,   160,    -1,    77,   241,   159,
     205,   160,    -1,    78,   159,   241,   158,   239,   160,   159,
     205,   160,    -1,    78,   159,   241,   158,   241,   160,   159,
     205,   160,    -1,     4,   159,   205,   160,    -1,    86,    54,
     159,   247,   160,    57,   159,   239,   160,    -1,    83,    54,
     152,   239,   153,   159,   247,   160,     6,    -1,   206,    -1,
     204,    -1,    -1,   206,   199,    -1,   206,    51,   159,   247,
     160,     6,    -1,   206,    54,   159,   247,   160,     6,    -1,
     206,    57,   159,   247,   160,     6,    -1,   206,    59,   159,
     247,   160,     6,    -1,    80,    65,   152,   239,   153,     7,
     244,     6,    -1,    80,    51,   152,   239,   153,     7,   159,
     243,   160,     6,    -1,    80,    65,   152,   239,   153,     7,
     159,   241,   158,   241,   158,   247,   160,     6,    -1,    80,
      65,   152,   239,   153,     7,   159,   241,   158,   241,   158,
     241,   158,   247,   160,     6,    -1,    80,    55,   152,   239,
     153,     7,   159,   241,   158,   247,   160,     6,    -1,    80,
       4,   152,   239,   153,     7,   244,     6,    -1,    80,     4,
     152,   239,   153,     7,     5,     6,    -1,    80,     4,   159,
     239,   160,     6,    -1,    80,     4,   152,   239,   153,     7,
     159,   241,   158,   241,   158,   247,   160,     6,    -1,    84,
     159,   206,   160,    -1,    84,   115,   154,   239,   155,     6,
      -1,    84,     4,   154,   239,   155,     6,    -1,    84,     4,
       6,    -1,    84,     4,     4,     6,    -1,   106,   248,   159,
     206,   160,    -1,   119,     5,     6,    -1,   120,     5,     6,
      -1,   119,   159,   206,   160,    -1,   120,   159,   206,   160,
      -1,     4,   252,     6,    -1,     4,     4,   154,   239,   155,
     251,     6,    -1,     4,     4,     4,   154,   239,   155,     6,
      -1,     4,   239,     6,    -1,    73,   152,     4,   153,   156,
       4,     6,    -1,   100,     4,     6,    -1,   113,     6,    -1,
     114,     6,    -1,    46,     6,    -1,    43,     6,    -1,    43,
     159,   239,   158,   239,   158,   239,   158,   239,   158,   239,
     158,   239,   160,     6,    -1,    44,     6,    -1,    47,     6,
      -1,    48,     6,    -1,    64,     6,    -1,   108,   152,   239,
       8,   239,   153,    -1,   108,   152,   239,     8,   239,     8,
     239,   153,    -1,   108,     4,   109,   159,   239,     8,   239,
     160,    -1,   108,     4,   109,   159,   239,     8,   239,     8,
     239,   160,    -1,   110,    -1,   118,     4,    -1,   116,    -1,
     117,     4,     6,    -1,   111,   152,   239,   153,    -1,   112,
      -1,    79,   241,   159,   206,   160,    -1,    79,   159,   241,
     158,   241,   158,   239,   160,   159,   206,   160,    -1,    79,
     159,   241,   158,   241,   158,   241,   158,   239,   160,   159,
     206,   160,    -1,    -1,    79,   241,   159,   206,   214,   227,
     160,    -1,    -1,    79,   159,   241,   158,   241,   158,   239,
     160,   159,   206,   215,   227,   160,    -1,    -1,    79,   159,
     241,   158,   241,   158,   241,   158,   239,   160,   159,   206,
     216,   227,   160,    -1,    -1,    79,   159,   206,   217,   227,
     160,    -1,    79,    51,   159,   239,   158,   241,   160,     6,
      -1,    79,    54,   159,   239,   158,   241,   160,     6,    -1,
      79,    57,   159,   239,   158,   241,   160,     6,    -1,    79,
      51,   159,   239,   158,   241,   158,   241,   158,   239,   160,
       6,    -1,    79,    54,   159,   239,   158,   241,   158,   241,
     158,   239,   160,     6,    -1,    79,    57,   159,   239,   158,
     241,   158,   241,   158,   239,   160,     6,    -1,    79,    51,
     159,   239,   158,   241,   158,   241,   158,   241,   158,   239,
     160,     6,    -1,    79,    54,   159,   239,   158,   241,   158,
     241,   158,   241,   158,   239,   160,     6,    -1,    79,    57,
     159,   239,   158,   241,   158,   241,   158,   241,   158,   239,
     160,     6,    -1,    -1,    79,    51,   159,   239,   158,   241,
     160,   218,   159,   227,   160,     6,    -1,    -1,    79,    54,
     159,   239,   158,   241,   160,   219,   159,   227,   160,     6,
      -1,    -1,    79,    57,   159,   239,   158,   241,   160,   220,
     159,   227,   160,     6,    -1,    -1,    79,    51,   159,   239,
     158,   241,   158,   241,   158,   239,   160,   221,   159,   227,
     160,     6,    -1,    -1,    79,    54,   159,   239,   158,   241,
     158,   241,   158,   239,   160,   222,   159,   227,   160,     6,
      -1,    -1,    79,    57,   159,   239,   158,   241,   158,   241,
     158,   239,   160,   223,   159,   227,   160,     6,    -1,    -1,
      79,    51,   159,   239,   158,   241,   158,   241,   158,   241,
     158,   239,   160,   224,   159,   227,   160,     6,    -1,    -1,
      79,    54,   159,   239,   158,   241,   158,   241,   158,   241,
     158,   239,   160,   225,   159,   227,   160,     6,    -1,    -1,
      79,    57,   159,   239,   158,   241,   158,   241,   158,   241,
     158,   239,   160,   226,   159,   227,   160,     6,    -1,   228,
      -1,   227,   228,    -1,    88,   159,   239,   160,     6,    -1,
      88,   159,   244,   158,   244,   160,     6,    -1,    88,   159,
     244,   158,   244,   158,   244,   160,     6,    -1,    81,     6,
      -1,    92,     6,    -1,    92,    94,     6,    -1,    93,     6,
      -1,    93,    94,     6,    -1,    89,   152,   239,   153,     7,
     244,    72,   239,     6,    -1,    72,     4,   154,   239,   155,
       6,    -1,    -1,    72,     4,   239,    -1,    -1,     4,    -1,
      -1,     7,   244,    -1,    -1,     7,   239,    -1,    67,    54,
     245,     7,   239,   229,     6,    -1,    67,    57,   245,   231,
     230,     6,    -1,    63,    57,   159,   239,   160,     7,   244,
       6,    -1,    67,    59,   245,   231,     6,    -1,    95,   245,
       6,    -1,    87,    57,   159,   247,   160,   239,     6,    -1,
      81,    57,   245,   232,     6,    -1,    82,    57,   244,     7,
     239,     6,    -1,    71,    54,   244,     7,   244,     6,    -1,
      71,    57,   239,   159,   247,   160,     7,   239,   159,   247,
     160,     6,    -1,    51,   159,   247,   160,   109,    57,   159,
     239,   160,     6,    -1,    54,   159,   247,   160,   109,    57,
     159,   239,   160,     6,    -1,    54,   159,   247,   160,   109,
      59,   159,   239,   160,     6,    -1,    57,   159,   247,   160,
     109,    59,   159,   239,   160,     6,    -1,    85,     6,    -1,
      85,     4,     6,    -1,    85,    51,   159,   247,   160,     6,
      -1,   124,    -1,   125,    -1,   237,     6,    -1,   237,   159,
     244,   160,     6,    -1,   237,   159,   244,   158,   244,   160,
       6,    -1,   237,   152,   244,   153,   159,   244,   158,   244,
     160,     6,    -1,   240,    -1,   152,   239,   153,    -1,   143,
     239,    -1,   142,   239,    -1,   147,   239,    -1,   239,   143,
     239,    -1,   239,   142,   239,    -1,   239,   144,   239,    -1,
     239,   145,   239,    -1,   239,   146,   239,    -1,   239,   151,
     239,    -1,   239,   138,   239,    -1,   239,   139,   239,    -1,
     239,   141,   239,    -1,   239,   140,   239,    -1,   239,   137,
     239,    -1,   239,   136,   239,    -1,   239,   135,   239,    -1,
     239,   134,   239,    -1,   239,   133,   239,     8,   239,    -1,
      14,   152,   239,   153,    -1,    15,   152,   239,   153,    -1,
      16,   152,   239,   153,    -1,    17,   152,   239,   153,    -1,
      18,   152,   239,   153,    -1,    19,   152,   239,   153,    -1,
      20,   152,   239,   153,    -1,    21,   152,   239,   153,    -1,
      22,   152,   239,   153,    -1,    24,   152,   239,   153,    -1,
      25,   152,   239,   158,   239,   153,    -1,    26,   152,   239,
     153,    -1,    27,   152,   239,   153,    -1,    28,   152,   239,
     153,    -1,    29,   152,   239,   153,    -1,    30,   152,   239,
     153,    -1,    31,   152,   239,   153,    -1,    32,   152,   239,
     158,   239,   153,    -1,    33,   152,   239,   158,   239,   153,
      -1,    34,   152,   239,   158,   239,   153,    -1,    23,   152,
     239,   153,    -1,    14,   154,   239,   155,    -1,    15,   154,
     239,   155,    -1,    16,   154,   239,   155,    -1,    17,   154,
     239,   155,    -1,    18,   154,   239,   155,    -1,    19,   154,
     239,   155,    -1,    20,   154,   239,   155,    -1,    21,   154,
     239,   155,    -1,    22,   154,   239,   155,    -1,    24,   154,
     239,   155,    -1,    25,   154,   239,   158,   239,   155,    -1,
      26,   154,   239,   155,    -1,    27,   154,   239,   155,    -1,
      28,   154,   239,   155,    -1,    29,   154,   239,   155,    -1,
      30,   154,   239,   155,    -1,    31,   154,   239,   155,    -1,
      32,   154,   239,   158,   239,   155,    -1,    33,   154,   239,
     158,   239,   155,    -1,    34,   154,   239,   158,   239,   155,
      -1,    23,   154,   239,   155,    -1,     3,    -1,     9,    -1,
      10,    -1,    11,    -1,   126,    -1,   127,    -1,   128,    -1,
       4,    -1,     4,   161,   159,   239,   160,    -1,     4,   154,
     239,   155,    -1,   157,     4,   154,   155,    -1,     4,   185,
      -1,     4,   154,   239,   155,   185,    -1,     4,   156,     4,
      -1,     4,   154,   239,   155,   156,     4,    -1,     4,   156,
       4,   185,    -1,     4,   154,   239,   155,   156,     4,   185,
      -1,   121,   152,   251,   158,   239,   153,    -1,    42,   152,
     251,   158,   251,   153,    -1,   242,    -1,   143,   241,    -1,
     142,   241,    -1,   241,   143,   241,    -1,   241,   142,   241,
      -1,   159,   239,   158,   239,   158,   239,   158,   239,   158,
     239,   160,    -1,   159,   239,   158,   239,   158,   239,   158,
     239,   160,    -1,   159,   239,   158,   239,   158,   239,   160,
      -1,   152,   239,   158,   239,   158,   239,   153,    -1,   244,
      -1,   243,   158,   244,    -1,   239,    -1,   246,    -1,   159,
     160,    -1,   159,   247,   160,    -1,   143,   159,   247,   160,
      -1,   239,   144,   159,   247,   160,    -1,   244,    -1,     5,
      -1,   143,   246,    -1,   239,   144,   246,    -1,   239,     8,
     239,    -1,   239,     8,   239,     8,   239,    -1,    51,   159,
     239,   160,    -1,    51,     5,    -1,    54,     5,    -1,    57,
       5,    -1,    59,     5,    -1,    69,    51,   159,   247,   160,
      -1,    69,    54,   159,   247,   160,    -1,    69,    57,   159,
     247,   160,    -1,    69,    59,   159,   247,   160,    -1,   204,
      -1,   213,    -1,     4,   154,   155,    -1,     4,   152,   153,
      -1,    35,   154,     4,   155,    -1,     4,   154,   159,   247,
     160,   155,    -1,     4,   152,   159,   247,   160,   153,    -1,
     239,    -1,   246,    -1,   247,   158,   239,    -1,   247,   158,
     246,    -1,   159,   239,   158,   239,   158,   239,   158,   239,
     160,    -1,   159,   239,   158,   239,   158,   239,   160,    -1,
       4,    -1,     4,   156,   106,   156,     4,    -1,   159,   250,
     160,    -1,     4,   154,   239,   155,   156,   107,    -1,   248,
      -1,   250,   158,   248,    -1,   252,    -1,     4,    -1,     4,
     156,     4,    -1,     4,   154,   239,   155,   156,     4,    -1,
       5,    -1,    45,    -1,   122,   152,   251,   153,    -1,   123,
     152,   251,   158,   251,   153,    -1,    39,   152,   251,   158,
     251,   153,    -1,    40,   152,   251,   153,    -1,    41,   152,
     251,   153,    -1,    38,   152,   251,   153,    -1,    38,   152,
     251,   158,   247,   153,    -1,   251,    -1,   253,   158,   251,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   165,   170,   172,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   196,   200,   207,   212,   217,   231,   244,
     257,   285,   299,   310,   325,   330,   331,   332,   333,   334,
     338,   340,   345,   347,   353,   457,   352,   475,   482,   493,
     492,   510,   517,   528,   527,   544,   561,   584,   583,   597,
     598,   599,   600,   601,   605,   606,   612,   614,   676,   706,
     741,   775,   823,   870,   885,   901,   910,   916,   925,   943,
     961,   970,   982,   987,   995,  1015,  1038,  1049,  1057,  1079,
    1102,  1128,  1149,  1161,  1175,  1175,  1177,  1179,  1190,  1202,
    1201,  1213,  1225,  1224,  1239,  1245,  1252,  1253,  1257,  1268,
    1283,  1293,  1294,  1299,  1307,  1316,  1335,  1339,  1350,  1353,
    1366,  1369,  1379,  1403,  1402,  1422,  1444,  1462,  1483,  1501,
    1531,  1561,  1579,  1597,  1623,  1641,  1660,  1659,  1682,  1700,
    1739,  1745,  1751,  1758,  1783,  1808,  1825,  1842,  1874,  1873,
    1897,  1915,  1932,  1949,  1948,  1974,  1979,  1984,  1989,  1994,
    1999,  2022,  2028,  2039,  2040,  2045,  2048,  2052,  2075,  2098,
    2121,  2149,  2170,  2193,  2214,  2236,  2256,  2368,  2387,  2425,
    2534,  2543,  2549,  2564,  2592,  2609,  2623,  2629,  2635,  2644,
    2658,  2703,  2720,  2735,  2754,  2766,  2790,  2794,  2799,  2806,
    2812,  2817,  2823,  2827,  2831,  2841,  2858,  2875,  2896,  2917,
    2952,  2960,  2966,  2973,  2977,  2986,  2994,  3002,  3011,  3010,
    3024,  3023,  3037,  3036,  3050,  3049,  3062,  3069,  3076,  3083,
    3090,  3097,  3104,  3111,  3118,  3126,  3125,  3138,  3137,  3150,
    3149,  3162,  3161,  3174,  3173,  3186,  3185,  3198,  3197,  3210,
    3209,  3222,  3221,  3237,  3240,  3246,  3255,  3275,  3298,  3302,
    3306,  3310,  3314,  3318,  3337,  3350,  3353,  3369,  3372,  3385,
    3388,  3394,  3397,  3404,  3460,  3530,  3535,  3602,  3638,  3647,
    3690,  3715,  3742,  3786,  3809,  3832,  3835,  3844,  3848,  3858,
    3893,  3894,  3898,  3903,  3914,  3931,  3959,  3960,  3961,  3962,
    3963,  3964,  3965,  3966,  3967,  3974,  3975,  3976,  3977,  3978,
    3979,  3980,  3981,  3982,  3983,  3984,  3985,  3986,  3987,  3988,
    3989,  3990,  3991,  3992,  3993,  3994,  3995,  3996,  3997,  3998,
    3999,  4000,  4001,  4002,  4003,  4004,  4005,  4008,  4009,  4010,
    4011,  4012,  4013,  4014,  4015,  4016,  4017,  4018,  4019,  4020,
    4021,  4022,  4023,  4024,  4025,  4026,  4027,  4028,  4037,  4038,
    4039,  4040,  4041,  4042,  4043,  4047,  4068,  4087,  4105,  4117,
    4134,  4155,  4160,  4165,  4175,  4185,  4190,  4202,  4206,  4210,
    4214,  4218,  4225,  4229,  4233,  4237,  4244,  4249,  4256,  4261,
    4265,  4270,  4274,  4282,  4293,  4297,  4309,  4317,  4325,  4332,
    4343,  4363,  4367,  4371,  4375,  4379,  4397,  4415,  4433,  4451,
    4461,  4471,  4484,  4496,  4508,  4527,  4548,  4553,  4557,  4561,
    4573,  4577,  4589,  4596,  4606,  4610,  4625,  4630,  4637,  4641,
    4654,  4662,  4673,  4677,  4685,  4693,  4701,  4709,  4723,  4737,
    4741,  4763,  4768
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
  "tStrRelative", "tStrFind", "tBoundingBox", "tDraw", "tToday",
  "tSyncModel", "tCreateTopology", "tCreateTopologyNoHoles",
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
  "tCohomology", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
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
  "$@7", "Enumeration", "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptions", "CharParameterOption", "PhysicalId",
  "InSphereCenter", "CircleOptions", "Shape", "$@8", "$@9", "$@10", "$@11",
  "Transform", "MultipleShape", "ListOfShapes", "LevelSet", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "$@23", "$@24", "ExtrudeParameters", "ExtrudeParameter",
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
     385,   386,   387,    63,   388,   389,   390,   391,    60,    62,
     392,   393,    43,    45,    42,    47,    37,    33,   394,   395,
     396,    94,    40,    41,    91,    93,    46,    35,    44,   123,
     125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   162,   163,   163,   164,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   166,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   169,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   173,   174,   172,   175,   175,   177,
     176,   178,   178,   180,   179,   181,   181,   183,   182,   184,
     184,   184,   184,   184,   185,   185,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   187,   187,   188,   188,   188,   189,
     188,   188,   190,   188,   191,   191,   192,   192,   193,   193,
     193,   194,   194,   195,   195,   195,   196,   196,   197,   197,
     198,   198,   199,   200,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   201,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   202,   199,
     199,   199,   199,   203,   199,   204,   204,   204,   204,   204,
     204,   204,   204,   205,   205,   206,   206,   206,   206,   206,
     206,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     208,   208,   208,   208,   208,   209,   210,   210,   210,   210,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   213,   213,   213,   214,   213,
     215,   213,   216,   213,   217,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   218,   213,   219,   213,   220,
     213,   221,   213,   222,   213,   223,   213,   224,   213,   225,
     213,   226,   213,   227,   227,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   233,   233,   233,   233,   233,
     233,   234,   234,   235,   235,   235,   235,   236,   236,   236,
     237,   237,   238,   238,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   241,   241,   241,
     241,   241,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   245,   245,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247,   247,   247,   247,
     248,   248,   248,   248,   249,   249,   250,   250,   251,   251,
     251,   251,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   253,   253
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
       5,     3,     6,     4,     7,     6,     6,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     1,     2,     3,     3,     5,
       4,     2,     2,     2,     2,     5,     5,     5,     5,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     1,     4,     6,     6,     4,     4,     4,
       6,     1,     3
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
       0,   209,     0,   214,     0,     0,     0,   211,     0,     0,
       0,     0,   290,   291,     5,     7,     6,     8,     9,    10,
      21,    11,    12,    13,    20,    19,    14,    15,    16,    17,
      18,     0,    22,   358,   365,   432,    59,   359,   360,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,     0,     0,     0,
       0,   362,   363,   364,    63,    62,    61,    60,     0,     0,
       0,    65,    64,     0,     0,     0,     0,   165,     0,     0,
       0,   296,     0,     0,     0,     0,     0,   199,     0,   201,
     198,   202,   203,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,   123,   136,   148,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   377,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,   287,     0,     0,     0,     0,     0,   365,
     395,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,   410,   388,   394,     0,   389,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,   196,   197,     0,     0,
     210,     0,   165,     0,   165,   292,     0,     0,     0,     0,
       0,     0,   369,    34,   432,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,   299,   298,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,   163,     0,    73,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   140,     0,     0,     0,     0,    94,     0,
       0,   416,   417,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   379,   378,     0,     0,
       0,     0,   165,   165,     0,     0,     0,     0,     0,     0,
       0,   224,     0,   165,     0,     0,     0,     0,     0,   271,
       0,     0,     0,   183,     0,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,   402,   403,
     404,     0,     0,     0,     0,     0,   298,   396,     0,   390,
       0,     0,     0,   277,   195,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   212,   186,     0,   187,     0,
       0,     0,     0,     0,   371,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,    59,     0,     0,     0,    59,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,   166,
      67,     0,   314,   313,   312,   311,   307,   308,   310,   309,
     302,   301,   303,   304,   305,   306,   141,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,   381,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,     0,     0,   180,     0,
       0,     0,     0,     0,   412,     0,   411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,   391,   398,     0,
     303,   397,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,   188,   189,     0,     0,     0,     0,   367,   373,
       0,    44,     0,     0,     0,    57,     0,    35,    36,    37,
      38,    39,   316,   337,   317,   338,   318,   339,   319,   340,
     320,   341,   321,   342,   322,   343,   323,   344,   324,   345,
     336,   357,   325,   346,     0,     0,   327,   348,   328,   349,
     329,   350,   330,   351,   331,   352,   332,   353,     0,     0,
       0,     0,     0,     0,     0,     0,   439,     0,     0,   437,
     438,     0,    86,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
     368,     0,     0,     0,     0,     0,    25,    23,     0,     0,
      26,     0,     0,    66,    97,     0,   418,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   270,   268,     0,   276,
       0,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,   215,     0,     0,     0,     0,     0,     0,   272,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   367,   413,   400,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,   293,     0,     0,   370,     0,   366,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,    74,
      76,    78,     0,     0,   426,     0,    84,     0,     0,     0,
       0,   315,    24,     0,     0,     0,     0,     0,     0,     0,
     120,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,     0,   259,     0,   261,     0,   225,   254,     0,
       0,     0,   178,     0,     0,     0,   280,     0,   182,   181,
     289,     0,     0,    32,    33,     0,     0,   405,   406,   407,
     408,   399,   393,     0,     0,     0,   423,     0,     0,     0,
     205,     0,     0,     0,     0,   192,   372,   191,     0,     0,
       0,     0,   386,     0,   326,   347,   333,   354,   334,   355,
     335,   356,     0,   440,   436,   376,   375,   435,     0,    70,
       0,    59,     0,     0,     0,     0,    69,     0,     0,     0,
     424,     0,     0,     0,     0,    27,    28,     0,    29,     0,
       0,    98,   101,   122,     0,     0,     0,     0,     0,   126,
       0,     0,   143,   144,     0,     0,   128,   151,     0,     0,
       0,   118,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,     0,     0,     0,     0,   165,   165,
       0,   235,     0,   237,     0,   239,     0,   388,     0,     0,
     260,   262,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   415,   414,   131,   132,     0,
       0,     0,     0,    87,    91,     0,     0,   294,   374,     0,
      40,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,    81,     0,     0,    82,     0,   427,   167,   168,
     169,   170,     0,     0,    99,   102,     0,   121,   129,   130,
     134,     0,     0,   145,     0,     0,   275,   138,     0,     0,
     266,   150,     0,     0,     0,     0,   135,     0,   146,   152,
       0,     0,     0,     0,   385,     0,   384,     0,     0,     0,
     226,     0,     0,   227,     0,     0,   228,     0,     0,     0,
       0,     0,     0,     0,   177,     0,     0,   176,     0,     0,
       0,   171,     0,     0,     0,     0,   421,     0,   207,   206,
       0,     0,     0,     0,    45,     0,     0,     0,   387,     0,
       0,     0,   431,    72,    71,    77,    79,     0,    85,     0,
      30,     0,   106,   111,     0,     0,     0,     0,     0,     0,
     139,   124,   137,   149,   154,     0,     0,    92,    93,   165,
       0,   158,   159,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,   165,     0,     0,     0,     0,     0,   162,
     161,     0,     0,     0,     0,    88,    89,     0,     0,    41,
       0,     0,     0,    43,    58,     0,   425,     0,     0,     0,
     283,   284,   285,   286,   142,     0,     0,     0,     0,     0,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   220,     0,     0,   172,     0,     0,
       0,   420,   208,     0,   295,     0,     0,     0,     0,    83,
       0,     0,   100,   107,     0,   103,   112,     0,     0,     0,
     156,     0,   241,     0,     0,   243,     0,     0,   245,     0,
       0,     0,   256,     0,   216,     0,   165,     0,     0,     0,
     133,    90,     0,    49,     0,    55,     0,     0,     0,     0,
     119,   147,   282,   382,   229,     0,     0,   236,   230,     0,
       0,   238,   231,     0,     0,   240,     0,     0,     0,   222,
       0,   175,     0,     0,     0,     0,     0,     0,     0,   110,
       0,   108,   114,     0,   113,     0,   247,     0,   249,     0,
     251,   257,   263,   221,   217,     0,     0,     0,     0,    46,
       0,    53,     0,     0,     0,   416,   441,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,     0,   179,     0,
     173,     0,    47,     0,     0,   200,     0,   109,     0,     0,
     115,     0,     0,     0,     0,     0,     0,   223,     0,     0,
       0,     0,     0,     0,   104,   442,   242,     0,   244,     0,
     246,     0,   174,    48,    50,     0,    51,     0,     0,     0,
       0,     0,     0,     0,    56,   105,   248,   250,   252,    52,
      54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    74,   778,    75,    76,   486,  1149,  1155,
     697,   890,  1308,  1471,   698,  1425,  1505,   699,  1473,   700,
     701,   894,   148,   272,    77,   584,   368,  1262,  1263,  1454,
    1318,  1363,  1319,  1366,   811,  1189,  1076,   559,   394,   395,
     396,   397,   240,   342,   343,    80,    81,    82,    83,    84,
      85,   241,   843,  1385,  1445,   633,  1211,  1214,  1217,  1405,
    1409,  1413,  1460,  1463,  1466,   839,   840,   958,   808,   607,
     642,    87,    88,    89,    90,    91,    92,   242,   151,   407,
     204,  1031,  1032,   244,   245,   460,   252,   769,   925,   531,
     532,  1457
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1072
static const yytype_int16 yypact[] =
{
    4345,    66,    19,  4430, -1072, -1072,  2019,    45,    48,   -58,
     -37,    36,   110,   128,   138,   145,    21,   -74,    57,    71,
      25,    78,   108,    26,   111,   121,   122,   156,   259,   318,
     273,   287,   312,   311,   269,   348,   187,   229,   367,   285,
      79,    79,   289,    60,    47,   331,   411,   424,    20,    40,
     483,   477,   537,   571,  2176,   579,   413,   466,   467,    27,
      46, -1072,   481, -1072,   584,   621,   478, -1072,   633,   653,
      31,    32, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072,    42, -1072, -1072,     5,   492,   436, -1072, -1072, -1072,
     179,   247,   256,   330,   334,   340,   386,   441,   445,   488,
     491,   495,   498,   504,   512,   542,   546,   561,   565,   572,
     573,   513,   519,   520,   527,   530, -1072,   676,   535,   551,
     568, -1072, -1072, -1072, -1072, -1072, -1072, -1072,  3921,  3921,
    3921, -1072, -1072,  3658,  1942,    13,   726,   443,  2629,   725,
    1278, -1072,   728,   729,  3921,   758,   761, -1072,  3921, -1072,
   -1072, -1072, -1072, -1072,  3921,  3843,  3921,  3921,   610,  3921,
    3843,  3921,  3921,   615,  3843,  3921,  3921,  2629,   622,   632,
   -1072,   636,   643,  2176,  2176,  2176,   644, -1072, -1072, -1072,
   -1072,   652,   657,   663,  2629,  3921,   780,  2629,    79,    79,
      79,  3921,  3921,   -16, -1072,   -11,    79,   664,   665,   668,
    3692,   100,   -70,   679,   683,   694,  2176,  2629,   695,    43,
     645, -1072,   822, -1072,   699,   700,   706,   712,   716,   801,
   -1072,   720,    33,   848,   849,   883,   321,  2780,  3921,  1861,
   -1072, -1072,  4109, -1072,   908, -1072,   913,  3921,  3921,  3921,
     773,  3921,   774,   843,  3921,  3921, -1072, -1072,  3921,   952,
   -1072,   957, -1072,   961, -1072, -1072,  2629,  2629,   814,  3921,
     968,   824, -1072, -1072, -1072,   978,  3921,  3921,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,    35,    35,
      35,    35,    35,  3921,    35,    35,    35,   475,   837,   837,
     837,  3843,  6749,    96,  3843,  5990,   233,   844,  1000,   906,
     869, -1072,   888,  4506,  1002, -1072, -1072,  3921,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,  3921,
    3921,  3921, -1072, -1072,  1374,    23,    76,  5288,    -5,  6770,
    3843,  4128, -1072,   589,  6791,  6812,  3921,  6833,   590,  6854,
    6875,  3921,   594,  6896,  6917,  1022,  3921,  3921,  3921,  3921,
    1036,  1044,  1044,  3921,   910,   911,   914,   918,  3921,  3921,
    3921,  1058,  5208,   927,  1065,   -72, -1072, -1072,  5314,  5340,
      79,    79,   443,   443,   -13,  3921,  3921,  3921,  3692,  3692,
    3921,  4506,   234, -1072,  3921,  3921,  3921,  3921,  3921,  1075,
    1078,  3921,  1080, -1072,  3921,  3921,  1199, -1072,  3843,  3843,
    3843,  3921,  3921,  -118,  3467,  1083, -1072,  3921, -1072, -1072,
   -1072,   929,   930,   932,   933,  3843,   837, -1072,  6938, -1072,
     598,  3921,  2931, -1072, -1072,  6959,  6980,  7001,   987,  5366,
   -1072,   935,  4156,  7022,  6013, -1072, -1072,  1480, -1072,  1613,
     942,   619,  3921,  6036,   278,  3921,    11, -1072,  7043,  6059,
    7064,  6082,  7085,  6105,  7106,  6128,  7127,  6151,  7148,  6174,
    7169,  6197,  7190,  6220,  7211,  6243,  7232,  6266,  7253,  6289,
    5392,  5418,  7274,  6312,  7295,  6335,  7316,  6358,  7337,  6381,
    7358,  6404,  7379,  6427,  5444,  5470,  5496,  5522,  5548,  5574,
     626,   113, -1072,   938,   944,   946,   943,  1670,   945,   951,
     947,  3921,   625,    96, -1072,  2629,   629,   211,   436,  3921,
    1100,  1105,    29,   956, -1072,   -55,    28,    30,   -34, -1072,
   -1072,  4176,  1322,  1469,  1055,  1055,   735,   735,   735,   735,
     345,   345,   837,   837,   837,   837, -1072,     8,  3843,  1104,
    3843,  3921,  1106, -1072,  1109,  1108,  3843,  3843,  1007,  1110,
    1111,  7400,  1112,  1011,  1114,  1115,  7421,  1014,  1118,  1119,
    3921,  7442,  4536,  7463,  7484,  3921,  2629,  1125,  1124,  7505,
    3988,  3988,  3988,  3988,  7526,  7547,  7568,  2629,  3843,   976,
   -1072,    79,  3921,  3921, -1072, -1072,   973,   975,  3692,  5600,
    5626,  5652,  5262,   741,    79,  2053,  7589,  4564,  7610,  7631,
    7652,  3921,  1130,  3921,  7673, -1072,  6450,  6473, -1072,   647,
     654,   660,  6496,  6519, -1072,  3843, -1072,  3843,  6542,   982,
    4592,  3843,  3843,  3843,  3843,   661, -1072, -1072,  4197,  3843,
     837, -1072,  1131,  1133,  1134,   986,  3921,  2212,  3921,  3921,
   -1072,     4, -1072, -1072,   985,  2629,  1139,  6565,    83, -1072,
    4620, -1072,   994,   995,   989, -1072,  1146, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072,  3921,  3921, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,  3921,  3921,
    3921,  3921,  3921,  3921,  3921,  1149, -1072,  3843,    35, -1072,
   -1072,    35, -1072,  3921, -1072,    35,  1003,  3921,  1151,  1005,
     109,  3921,  1152,  1155,  2583, -1072,  1148,  1009,    27,  1159,
   -1072,  3843,  3843,  3843,  3843,  3921, -1072,  1028,    35,   164,
   -1072,   308,  5678, -1072,  1161,    79,  4128, -1072,  1113,  2629,
    2629,  1162,  2629,   779,  2629,  2629,  1165,  1116,  2629,  2629,
    2602,  1166,  1167,  1169,  1172,  1557, -1072, -1072,  1181, -1072,
    1182,  1035,  7904, -1072,  1038,  1049,  1051,  1198,  1200,  1201,
    1203,   681,  1206,   251,  5704,  5730, -1072, -1072,  4648,   -83,
      79,    79,    79,  1210,  1211,  1057,  1066,     2,    12,   -27,
   -1072,   277, -1072,   741,  1212,  1214,  1215,  1217,  1218,  7904,
   -1072,  2743,  1069,  1223,  1224,  1225,  1175,  3921,  1228,  1230,
     684,   685,    61, -1072, -1072,   704,   713,   737,   738, -1072,
    3921,   757,  2629,  2629,  2629,  1233,  5756, -1072,  4229,   803,
    1235,  1236,  2629,  1081, -1072,  1238,  1241, -1072,  1240, -1072,
    1090,  3921,  3921,  2629,  1088, -1072,  7694,  6588,  7715,  6611,
    7736,  6634,  7757,  6657,  6680, -1072,   396,  1096,  1107,  7778,
    1117,    96,  2885, -1072,    96,   383,  1120,  1255,  2904, -1072,
   -1072, -1072,    27,  3921, -1072,   762, -1072,   765,   766,   772,
     806,  7904, -1072,  1257,    10,  1260,  3921,  3384,    -3,  1121,
    1207,  1207,  2629,  1265,  1123,  1127,  1269,  1271,  2629,  1128,
    1273,  1282, -1072,  1284,  2629,  2629,  2629,  1286,  1285, -1072,
    2629,  1289,  1290,  1291,  1296,  2629,  2629,  2629, -1072,  1297,
     458,  3921,  3921,  3921,  1147,  1153,   -79,   -59,   112,  1138,
   -1072,  2629,  3921, -1072,  1287, -1072,  1299, -1072, -1072,  3692,
     176,  2327, -1072,  1154,  1157,  3082, -1072,  3843, -1072, -1072,
   -1072,  1158,  3045, -1072, -1072,  1168,  1156, -1072, -1072, -1072,
   -1072,  7904, -1072,  1301,  1304,  1209, -1072,  3921,  3921,  3921,
   -1072,  1312,   517,  1164,  1313, -1072,   278, -1072,  3921,  5782,
    5808,   815, -1072,  3921, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072,  1170, -1072, -1072, -1072, -1072, -1072,  2629, -1072,
    2629,   436,  3921,  1314,  1320,    29, -1072,  1319,  6703,    27,
   -1072,  1323,  1324,  1325,  1326, -1072, -1072,    35, -1072,  5834,
    3988,  7904, -1072, -1072,  3921,    79,  1327,  1328,  1330, -1072,
    3921,  3921, -1072, -1072,  1332,  3921, -1072, -1072,  1335,  1336,
    1337,  1219,  3921, -1072,  1338,  2629,  2629,  2629,  2629,  1339,
     955,  1340,  3921, -1072,  3988,  4676,  7799,  4452,   443,   443,
      79,  1342,    79,  1343,    79,  1345,  3921,   365,  1183,  7820,
   -1072, -1072,  4704,   288, -1072,  1346,  1709,  1348,  2629,    79,
    1709,  1349,   818,  3921, -1072, -1072, -1072, -1072, -1072,  2629,
    4480,   767,  7841, -1072, -1072,  3427,  2629, -1072, -1072,   399,
    7904,  3921,  3921,  2629,  1202,   833,  7904,  1353,  1352,  1356,
    1357,  3187, -1072,  1358,  1360, -1072,  1208, -1072, -1072, -1072,
   -1072, -1072,  1361,  3921,  7904, -1072,  4732,   388, -1072, -1072,
   -1072,  4760,  4788, -1072,  4816,  1363, -1072, -1072,  1315,  1366,
    7904, -1072,  1367,  1369,  1370,  1372, -1072,  1220, -1072, -1072,
    5235,  3206,  1376,  1227, -1072,  3921, -1072,  1229,  1231,   315,
   -1072,  1234,   329, -1072,  1237,   385, -1072,  1243,  6726,  1377,
    2629,  1362,  1246,  3921, -1072,  3233,   393, -1072,   836,   402,
     429, -1072,  1378,  4844,  1302,  3921, -1072,  3921, -1072, -1072,
    3843,  3950,  1382,  1250, -1072,  3921,  5860,  5886, -1072,  2629,
    3921,  1384, -1072, -1072, -1072, -1072, -1072,    27, -1072,  1293,
   -1072,  5912, -1072, -1072,  1388,  1419,  1420,  1421,  1424,  1272,
   -1072, -1072, -1072, -1072, -1072,  2629,  3843, -1072, -1072,   443,
    4508, -1072, -1072,  3692,   741,  3692,   741,  3692,   741,  1426,
   -1072,   839,  2629, -1072,  4872,    79,  1427,  3843,    79, -1072,
   -1072,  3921,  4900,  4928,   853, -1072, -1072,  1428,  1276,  7904,
    3921,  3921,   854,  7904, -1072,  1430, -1072,  3921,   860,   861,
   -1072, -1072, -1072, -1072, -1072,  3921,   864,   865,  1277,  3921,
   -1072,  4956,   431,   246,  4984,   438,   362,  5012,   459,   474,
   -1072,  2629,  1432,  1368,  2363,  1280,   470, -1072,   874,   472,
    4017, -1072, -1072,  1436, -1072,  3921,  7862,  5938,    37, -1072,
    5964,  1439, -1072, -1072,  1440, -1072, -1072,  5040,  1441,  1442,
   -1072,  5068,  1443,  3921,  1444,  1445,  3921,  1446,  1447,  3921,
    1448,  1309, -1072,  3921, -1072,   741, -1072,  3843,  1450,  3233,
   -1072, -1072,   875, -1072,  3921, -1072,  2629,  3921,  2478,  3624,
   -1072, -1072, -1072, -1072, -1072,  1316,  5096, -1072, -1072,  1317,
    5124, -1072, -1072,  1318,  5152, -1072,  1465,  4037,   616,  2514,
     878, -1072,   480,   879,  1472,  1321,  7883,   882,  5180, -1072,
    1861, -1072, -1072,    35,  7904,   741,  1473,   741,  1478,   741,
    1479, -1072, -1072, -1072, -1072,   741,  1481,  3843,  1482, -1072,
      35, -1072,  1331,  1483,   886,  4058, -1072,   889,   618, -1072,
    1341,   640, -1072,  1344,   672, -1072,  1364,   709, -1072,   894,
   -1072,   897, -1072,  1365,  2629, -1072,  3921, -1072,   436,    35,
   -1072,  1488,   741,  1489,   741,  1490,   741, -1072,  1491,    35,
    1492,    35,   898,  4090, -1072, -1072, -1072,   768, -1072,   893,
   -1072,   917, -1072, -1072, -1072,   901, -1072,  1493,   436,  1495,
    1498,  1499,    35,  1515, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1072, -1072, -1072, -1072,   552, -1072, -1072, -1072, -1072,    91,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072,  -323,     1, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072,   -43, -1072,   581,  1523, -1072, -1072,
   -1072, -1072,    -1,  -407,  -209, -1072, -1072, -1072, -1072, -1072,
   -1072,  1525, -1072, -1072, -1072, -1072, -1072, -1072, -1072, -1072,
   -1072, -1072, -1072, -1072, -1072,  -791,  -783, -1072, -1072,  1137,
   -1072, -1072, -1072, -1072, -1072, -1072, -1072,    -2, -1072,    52,
   -1072, -1071,   609,  -116,   230,   412,  -740,   486, -1072,  -299,
      -6, -1072
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     152,   421,    79,  1073,   150,   626,   627,   149,   983,   268,
     545,   880,   436,   549,   776,   691,  1066,   336,   985,     5,
     533,   534,   535,   536,   219,   538,   539,   540,   924,   168,
     173,   250,   168,   767,   173,   654,   261,   263,   446,   530,
     274,   655,   157,  1395,   222,   833,   223,   432,   265,   433,
     253,   212,   990,   477,   834,   479,   988,  1228,   153,   410,
     411,   835,   836,   410,   411,   837,   838,   390,   391,   392,
     410,   411,     4,   121,   122,   123,   124,   975,   164,  1110,
     126,  1111,   424,   410,   411,   165,   621,   530,   274,   425,
     275,   224,   203,   205,   155,   211,   984,   164,   213,  1112,
     429,  1113,   214,   544,   771,   154,   986,   692,   693,   694,
     695,   207,   215,   915,   208,   156,   159,   209,   176,   337,
     338,   121,   122,   123,   124,   774,   410,   411,   126,   410,
     411,   410,   411,   987,   160,   220,   328,   329,   330,   410,
     411,   332,   335,   412,   161,   628,   341,   777,   413,   777,
     582,   162,   364,   583,   141,   142,   367,   129,   130,   269,
     881,   270,   369,   371,   374,   375,   271,   377,   371,   379,
     380,   696,   371,   383,   384,   163,   577,   169,  1312,   221,
     169,   578,  1057,   177,   170,   174,   251,   772,   768,   773,
     262,   264,   447,   402,   266,   158,  1396,   434,   254,   408,
     409,   267,   199,   200,  1326,   129,   130,   988,   409,   166,
     141,   142,   201,   178,   635,   916,   917,   886,   544,   210,
     757,   199,   200,   167,   761,   134,   135,   136,   137,   579,
     171,   201,   141,   142,   580,   456,   458,   371,   202,   886,
     548,   194,   410,   411,   195,   465,   466,   467,   833,   469,
     405,   406,   472,   473,   410,   411,   474,   834,   414,   423,
     172,   677,   422,   175,   835,   836,   746,   483,   837,   838,
    1114,   747,  1115,   176,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   179,   934,   833,  1167,
     187,   537,   587,   188,   180,  1427,   189,   834,   190,   371,
     181,   276,   371,   277,   835,   836,  1124,   550,   837,   838,
     134,   135,   136,   137,   182,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     141,   142,   134,   135,   136,   137,   183,   760,   456,   184,
     186,   185,   451,   461,   591,   452,   410,   411,   453,   596,
     454,   196,   141,   142,   601,   602,   603,   604,   216,   888,
    1051,   609,   634,   410,   411,   372,   614,   615,   616,   278,
     372,   279,   191,  1492,   372,   192,  1374,   193,   280,   971,
     281,   341,   341,   629,   630,   631,   328,   329,   632,   410,
     411,   197,   636,   637,   638,   639,   640,   141,   142,   644,
     410,   411,   646,   647,   833,   989,   371,   371,   371,   652,
     653,   274,   658,   834,   198,   660,  1223,   340,   206,   907,
     835,   836,   908,   371,   837,   838,   910,   410,   411,   668,
     670,   935,   624,   625,  1103,  1104,   587,   457,   217,   372,
     406,   410,   411,  1283,   121,   122,   123,   124,   218,   933,
     687,   126,   282,   690,   283,   689,   284,  1285,   285,   358,
     359,   360,   286,  1333,   287,  1336,   361,  1339,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   462,
     359,   360,   134,   135,   136,   137,   361,  1315,    39,    40,
      41,    42,  1377,  1144,  1145,  1219,    47,   410,   411,    50,
     410,   411,   141,   142,   226,   410,   411,   225,   288,   658,
     289,   227,   763,  1287,   410,   411,   833,   764,   762,  1043,
     988,  1295,  1244,   988,   587,   834,   988,  1245,   129,   130,
    1297,   372,   835,   836,   372,   247,   837,   838,   814,   815,
     816,   410,   411,   410,   411,   228,   371,   373,   371,   782,
     410,   411,   378,   246,   670,   786,   382,  1298,  1048,  1373,
     256,  1050,  1052,   290,  1418,   291,  1376,   292,   800,   293,
     457,   410,   411,   805,   813,   813,   813,   813,   812,   812,
     812,   812,   410,   411,   410,   411,   371,  1379,   248,   249,
     824,   825,   410,   411,   141,   142,   828,   257,  1387,   541,
    1389,   270,   258,   255,  1380,   988,   271,   259,  1447,   849,
     294,   851,   295,   296,  1458,   297,  1461,   298,  1464,   299,
     300,   273,   301,   371,  1467,   371,   302,   260,   303,   371,
     371,   371,   371,   243,   304,   318,   305,   371,   372,   372,
     372,   319,   320,   823,   876,   988,   878,   879,   988,   321,
     829,   988,   322,   323,   988,   372,   841,   324,   833,   887,
     833,  1497,   671,  1499,   306,  1501,   307,   834,   308,   834,
     309,  1207,  1208,   325,   835,   836,   835,   836,   837,   838,
     837,   838,   833,   310,   988,   311,   988,   312,   988,   313,
     326,   834,   896,   897,   314,   316,   315,   317,   835,   836,
     339,   345,   837,   838,   362,   363,   898,   899,   900,   901,
     902,   903,   904,   542,   833,   371,   546,   587,   587,   588,
     593,   909,   587,   834,   597,   912,   587,   344,   667,   918,
     835,   836,   376,   365,   837,   838,   366,   381,  1172,   371,
     371,   371,   371,   931,   386,  1237,  1443,   685,  1481,   686,
     744,   833,   745,   587,   403,   756,   385,   587,   388,   759,
     834,   387,   243,   243,   243,   389,   393,   835,   836,   435,
    1483,   837,   838,   401,   398,   587,   404,   855,   372,   399,
     372,  1019,   587,   833,   856,   400,   671,   787,   587,   587,
     857,   869,   834,   415,   416,   243,   430,   417,   437,   835,
     836,   426,  1485,   837,   838,   427,   944,   938,   945,   587,
     833,   969,   587,   587,  1005,  1006,   428,   431,   372,   834,
     649,   650,   651,   448,   449,  1002,   835,   836,   438,   439,
     837,   838,   587,   887,  1007,   440,   441,   665,  1011,  1487,
     442,   587,  1328,  1008,   445,   480,   481,   356,   357,   358,
     359,   360,   976,   977,   978,   372,   361,   372,   450,  1029,
    1030,   372,   372,   372,   372,   587,   587,  1009,  1010,   372,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   463,   587,  1053,  1012,   361,   464,
    1059,  1058,  1060,   587,   587,  1061,  1062,  1238,  1509,   468,
     587,  1072,  1063,   470,  1069,  1071,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     141,   142,   471,   443,   361,   444,  1020,   270,   475,  1197,
     147,  1198,   271,   476,   587,   833,  1064,   478,   482,  1105,
    1106,  1107,   484,  1153,   834,  1154,   587,   372,  1232,  1117,
    1119,   835,   836,   485,   487,   837,   838,  1122,   361,   833,
     779,  1250,   781,  1251,  1153,   371,  1296,  1341,   834,  1342,
     551,   372,   372,   372,   372,   835,   836,   552,   560,   837,
     838,   587,  1153,  1353,  1358,  1140,  1141,  1142,  1361,  1364,
    1362,  1365,  1153,   587,  1368,  1369,  1150,  1148,   147,   600,
     821,  1156,   587,  1250,  1388,  1424,   587,   587,  1446,  1448,
    1153,  1123,  1452,   605,  1476,  1160,  1477,  1479,   554,  1480,
    1161,   606,   587,  1510,  1488,  1489,  1153,  1490,  1507,  1512,
     553,  1513,   610,   611,  1175,   617,   612,   860,  1174,   861,
     613,   620,  1176,   865,   866,   867,   868,  1511,  1181,  1182,
     619,   871,   641,  1184,  1344,   643,   645,   659,   661,   662,
    1190,   663,   664,   675,   678,   684,   748,   749,  1202,   750,
    1200,   751,  1201,   753,   754,   755,   765,   341,   341,   766,
     780,   770,   783,   784,  1218,   785,   788,   789,   790,   792,
     793,   794,   795,   797,   371,   798,   799,  1177,   371,   807,
     809,  1233,   822,   826,  1456,   827,   850,   863,   872,  1242,
     873,   874,   875,  1241,   882,   884,   891,   892,   893,  1246,
    1247,  1472,   895,   905,   758,   922,   911,   913,   919,   906,
     914,   920,  1209,   923,  1212,   926,  1215,   932,   937,   942,
     939,  1261,   948,   953,   954,   949,   955,  1419,  1226,   956,
    1495,  1229,  1230,   927,   928,   929,   930,   959,   961,   960,
    1503,   962,  1506,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   963,  1280,   964,   965,   361,   966,   967,   968,
     970,     7,     8,  1519,   979,   806,   981,   980,   982,   991,
     992,  1294,   993,   456,   994,   995,   820,   372,   997,   998,
     999,  1000,  1001,  1302,  1003,  1303,  1004,  1016,   371,  1021,
    1022,  1024,  1028,  1309,  1025,  1026,  1027,  1033,  1313,  1044,
     555,    18,    19,   556,    21,    22,   557,    24,   558,    26,
    1045,    27,  1055,  1065,    30,    31,  1068,    33,    34,    35,
    1047,  1079,  1075,    38,   371,  1082,  1054,  1083,   341,  1086,
    1074,  1331,  1080,  1334,   346,  1337,  1081,  1085,  1087,  1088,
    1092,  1093,  1116,  1120,   883,   371,  1095,  1096,  1097,  1350,
      56,    57,    58,  1098,  1102,  1121,  1108,  1137,  1356,  1357,
    1138,  1136,  1109,  1128,  1139,  1360,  1129,  1133,  1143,  1147,
    1162,  1135,  1146,  1367,  1163,  1165,  1157,  1371,  1188,  1168,
    1169,  1170,  1171,  1178,  1179,  1332,  1180,  1335,  1183,  1338,
    1185,  1220,  1186,  1187,  1191,  1196,  1199,  1346,  1210,  1213,
    1349,  1216,  1224,  1156,  1227,  1231,   372,  1252,  1253,   648,
     372,  1249,  1254,  1255,  1259,  1257,  1258,  1260,  1268,  1292,
    1269,  1406,  1270,  1271,  1410,  1272,  1273,  1414,  1274,  1275,
     576,  1417,  1278,  1290,  1299,   371,  1279,   371,  1306,  1281,
    1314,  1282,  1426,  1284,  1320,  1428,  1286,  1434,   940,   941,
    1316,   943,  1288,   946,   947,  1293,  1301,   950,   951,  1132,
    1307,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,  1321,  1322,  1323,  1455,   361,
    1324,  1325,  1340,  1347,  1354,  1355,  1359,  1370,  1382,  1386,
    1383,  1422,  1391,  1398,  1399,   371,  1392,  1401,  1402,  1404,
    1407,  1408,  1411,  1412,  1415,   457,  1421,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,  1416,
     372,  1441,  1494,   361,  1493,  1435,  1437,  1439,  1449,  1459,
    1450,  1013,  1014,  1015,  1462,  1465,  1067,  1468,  1470,  1475,
    1474,  1023,     7,     8,  1496,  1498,  1500,  1502,  1504,  1514,
    1482,  1516,  1515,  1484,  1517,  1518,   372,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,  1520,  1077,  1486,  1491,   361,    78,   372,    86,   608,
       0,   555,    18,    19,   556,    21,    22,   557,    24,   558,
      26,  1164,    27,     0,     0,    30,    31,     0,    33,    34,
      35,  1078,     0,     0,    38,     0,     0,  1084,     0,     0,
       0,     0,     0,  1089,  1090,  1091,     0,     0,     0,  1094,
       0,     0,     0,     0,  1099,  1100,  1101,     0,     0,     0,
       0,    56,    57,    58,     0,     0,     0,     0,     0,     0,
    1118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1127,     0,     0,     0,  1131,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,   372,     0,   372,
     361,     0,     0,     0,     0,     7,     8,     0,     0,   957,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     682,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1304,     0,     0,     0,     0,  1158,     0,  1159,
     372,     0,     0,     0,   555,    18,    19,   556,    21,    22,
     557,    24,   558,    26,     0,    27,   752,   372,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,  1327,     0,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,  1192,  1193,  1194,  1195,   361,  1348,
       0,     0,    93,   229,    56,    57,    58,     0,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   231,     0,     0,     0,  1234,     0,
       0,   125,     0,     0,     0,  1243,     0,     0,     0,     0,
     232,     0,  1248,   233,     0,     0,   234,     0,   235,     0,
       0,     0,     0,   683,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,     0,
       0,     0,    47,     0,     0,    50,     0,     0,     0,  1420,
       0,  1423,     0,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,  1291,
     128,     0,     0,     0,     0,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   418,  1225,     0,     0,     0,   140,     0,     0,  1469,
       0,   420,     0,     0,    93,   229,   146,     0,   202,   459,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   231,     0,     0,     0,
       0,  1343,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     0,    47,    93,   327,    50,     0,     0,
    1381,    97,    98,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,   128,     0,   125,     0,     0,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   370,     0,     0,  1431,   140,     0,
       0,     0,     0,   238,     0,     0,     0,     0,   146,     0,
       0,   459,    93,    94,    95,     0,    96,     0,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,   121,   122,   123,
     124,   125,     0,   128,   126,     7,     8,     0,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,     0,     0,     0,   140,
       0,     0,     0,     0,   238,     0,     0,   333,     0,   146,
       0,   334,     0,     0,   555,    18,    19,   556,    21,    22,
     557,    24,   558,    26,     0,    27,     0,     0,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
     128,   129,   130,     0,     0,   131,   132,   133,   134,   135,
     136,   137,     0,     0,    56,    57,    58,     0,     0,     0,
       0,   138,   139,     0,     0,     0,   140,     0,   141,   142,
       0,   143,     0,   144,     0,   145,   146,     0,   147,    93,
     229,   230,     0,     0,     0,    97,    98,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   231,     0,   842,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     7,     8,     0,   232,     0,     0,
     233,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,   555,    18,    19,   556,    21,    22,   557,
      24,   558,    26,     0,    27,     0,     0,    30,    31,     0,
      33,    34,    35,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,     0,   138,   237,
       0,     0,     0,   140,     0,     0,     0,     0,   238,     0,
      93,   229,  1125,   146,     0,   239,    97,    98,    99,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   231,     0,     0,     0,     0,     0,     0,   125,
       0,     0,   877,     0,     0,     7,     8,     0,   232,     0,
       0,   233,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
      47,     0,     0,    50,   555,    18,    19,   556,    21,    22,
     557,    24,   558,    26,     0,    27,     0,     0,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,     0,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,     0,     0,   138,
     237,     0,     0,     0,   140,     0,     0,     0,     0,   238,
       0,    93,   229,  1429,   146,     0,  1126,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   231,     0,     0,     0,     0,     0,     0,
     125,     0,     0,  1384,     0,     0,     7,     8,     0,   232,
       0,     0,   233,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,   555,    18,    19,   556,    21,
      22,   557,    24,   558,    26,     0,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,     0,     0,    38,   921,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,   131,   132,   133,     0,   952,     0,
       0,     0,     0,     0,     0,    56,    57,    58,     0,     0,
     138,   237,     0,     0,     0,   140,     0,     0,     0,     0,
     238,     0,    93,   229,     0,   146,     0,  1430,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   231,     0,     0,     0,     0,     0,
       0,   125,     0,     0,  1444,     0,     0,     0,     0,     0,
     232,     0,     0,   233,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,     0,
       0,     0,    47,     0,     0,    50,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   996,
     128,     0,     0,   361,     0,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   237,     0,     0,     0,   140,     0,     0,     0,
       0,   238,     0,    93,   229,     0,   146,     0,   239,    97,
      98,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   231,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,   233,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,  1049,     0,     0,   361,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,     0,   131,   132,   133,     0,
    1056,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   370,     0,     0,     0,   140,     0,     0,
       0,     0,   238,     0,    93,   229,     0,   146,     0,   455,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   231,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     0,    47,     0,     0,    50,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,  1134,   128,     0,     0,   361,     0,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   370,     0,     0,     0,   140,     0,
       0,     0,     0,   238,     0,    93,   229,     0,   146,     0,
     669,    97,    98,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   231,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,   233,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,  1256,     0,     0,   361,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,   131,   132,
     133,     0,  1277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   237,     0,     0,     0,   140,
       0,     0,     0,     0,   238,     0,    93,   229,     0,   146,
       0,  1130,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   231,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,    47,     0,     0,    50,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,   128,     0,     0,   361,     0,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   418,  1225,     0,     0,     0,
     140,     0,     0,     0,     0,   420,     0,    93,   327,   274,
     146,     0,   202,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,   121,   122,   123,   124,   125,     0,     0,   126,
      93,   327,   274,     0,     0,     0,    97,    98,    99,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,   121,   122,   123,   124,   125,
      93,   327,   126,     0,     0,     0,    97,    98,    99,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,   128,   129,   130,     0,   125,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,     0,     0,
       0,   140,     0,     0,     0,     0,   238,     0,     0,     0,
       0,   146,     0,  1070,     0,     0,     0,     0,   128,   129,
     130,     0,     0,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,     0,     0,     0,   140,     0,     0,     0,     0,   238,
       0,     0,     0,     0,   146,     0,  1240,     0,   128,     0,
       0,     0,     0,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,     0,     0,     0,   140,     0,     0,     0,     0,   238,
       0,     0,   656,     0,   146,     0,   657,    93,   327,  1432,
       0,     0,     0,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,    93,   327,     0,     0,     0,   125,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,    93,   327,     0,     0,     0,
     125,    97,    98,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,     0,     0,
       0,   140,     0,     0,     0,     0,   238,     0,     0,   128,
       0,   146,     0,  1433,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,     0,     0,     0,   140,     0,     0,     0,     0,
     238,     0,     0,   128,     0,   146,     0,   331,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   418,   419,     0,     0,     0,   140,
       0,     0,     0,     0,   420,     0,    93,   229,     0,   146,
       0,   202,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   231,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,    93,   327,    47,     0,     0,    50,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,  1305,     0,     0,     0,
       0,     0,     0,   125,   128,     0,     0,     0,     0,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   370,     0,     0,     0,
     140,    93,   327,   274,     0,   238,     0,    97,    98,    99,
     146,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,  1390,     0,     0,   121,   122,   123,   124,
     125,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,   128,  1442,     0,     0,     0,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,  1478,   461,     0,   140,     0,
       0,     0,     0,   238,     0,     0,     0,     0,   146,     0,
       0,     0,     0,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,  1508,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,   128,
     129,   130,     0,     0,   131,   132,   133,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,     0,     0,     0,   140,   461,     0,     0,     0,
     238,     0,     0,     0,     0,   146,     0,     0,     0,     0,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   679,     0,     0,     0,   361,     0,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   775,     0,     0,     0,   361,     0,
       0,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   586,   359,   360,   870,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,  1018,     0,     0,
       0,   361,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   462,   359,   360,     0,     0,     0,     0,
     361,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   586,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,    -4,     1,     0,   361,    -4,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,    -4,    -4,     0,     0,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,     0,
      -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,    -4,
      -4,     0,     0,    11,    12,     0,    13,    14,    15,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     7,     8,
      52,    53,     0,     0,     0,    54,     0,     0,     0,     0,
      55,    56,    57,    58,     0,     0,    59,     0,    60,     0,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,    72,    73,     0,   555,    18,    19,
     556,    21,    22,   557,    24,   558,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,     0,     0,     0,     0,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,    56,    57,    58,
    1205,     0,  1206,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,  1235,     0,
    1236,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,  1329,     0,  1330,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,   802,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,   845,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,   864,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
     889,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,   974,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,  1203,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,  1222,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,  1264,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
    1265,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,  1266,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,  1267,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,  1300,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,  1345,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
    1351,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,  1352,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,  1372,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,  1375,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,  1378,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
    1400,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,  1403,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,  1436,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,     0,     0,  1438,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,  1440,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
    1453,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,   618,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,     0,     0,
       0,     0,     0,     0,  1276,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   666,     0,     0,     0,     0,
     622,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,   581,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,   622,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,   623,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,   676,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     724,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,   725,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,   738,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,   739,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,   740,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     741,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,   742,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,   743,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,   830,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,   831,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     832,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,   936,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,   972,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,   973,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,  1017,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
    1151,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,  1152,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,  1173,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,     0,     0,     0,  1310,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,  1311,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
    1317,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,  1394,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,  1397,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,   547,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,     0,     0,   681,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,   688,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,     0,     0,   703,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,   705,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,     0,     0,
     707,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,   709,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,     0,     0,   711,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,   713,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
       0,     0,   715,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,   717,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,     0,     0,   719,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,   721,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,     0,     0,   723,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,   727,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,     0,     0,
     729,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,   731,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,     0,     0,   733,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,   735,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
       0,     0,   737,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,   853,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,     0,     0,   854,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,   858,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,     0,     0,   859,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,     0,     0,   862,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,     0,     0,
     885,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,     0,     0,  1035,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,     0,     0,  1037,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,     0,     0,  1039,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
       0,     0,  1041,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,     0,     0,  1042,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,     0,     0,  1166,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,     0,
       0,  1289,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,   543,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,   585,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,   589,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   590,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,   592,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,   594,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,   595,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,   598,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
     599,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,   666,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,   672,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,   673,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,   674,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   680,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,   702,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,   704,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,   706,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,   708,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
     710,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,   712,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,   714,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,   716,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,   718,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   720,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,   722,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,   726,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,   728,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,   730,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
     732,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,   734,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,   736,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,   791,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,   796,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   801,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,   803,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,   804,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,   810,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,   817,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
     818,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,   819,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,   844,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,   846,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,   847,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,   848,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,   852,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361,     0,  1034,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,     0,     0,     0,     0,   361,     0,  1036,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,     0,     0,     0,     0,   361,     0,  1038,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,     0,     0,     0,     0,   361,     0,
    1040,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,     0,     0,     0,     0,   361,
       0,  1046,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,     0,     0,     0,     0,
     361,     0,  1204,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,     0,     0,     0,
       0,   361,     0,  1221,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,     0,     0,
       0,     0,   361,     0,  1239,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,     0,
       0,     0,     0,   361,     0,  1393,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
       0,     0,     0,     0,   361,     0,  1451,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,     0,     0,     0,     0,   361
};

static const yytype_int16 yycheck[] =
{
       6,   210,     3,     6,     6,   412,   413,     6,     6,     4,
     333,     7,   221,   336,     6,     4,     6,     4,     6,     0,
     319,   320,   321,   322,     4,   324,   325,   326,   768,     4,
       4,     4,     4,     4,     4,   153,     5,     5,     5,     4,
       5,   159,     6,     6,     4,    72,     6,     4,     6,     6,
       4,     4,   843,   262,    81,   264,   839,  1128,    13,   142,
     143,    88,    89,   142,   143,    92,    93,   183,   184,   185,
     142,   143,     6,    38,    39,    40,    41,   160,   152,   158,
      45,   160,   152,   142,   143,   159,   158,     4,     5,   159,
      96,    51,    40,    41,   152,    43,    94,   152,    51,   158,
     216,   160,    55,     7,   159,    57,    94,    96,    97,    98,
      99,    51,    65,     4,    54,   152,     6,    57,   152,   106,
     107,    38,    39,    40,    41,   159,   142,   143,    45,   142,
     143,   142,   143,   160,     6,   115,   138,   139,   140,   142,
     143,   143,   144,   159,     6,   158,   147,   139,   159,   139,
     155,     6,   154,   158,   149,   150,   158,   122,   123,   154,
     156,   156,   164,   165,   166,   167,   161,   169,   170,   171,
     172,   160,   174,   175,   176,   154,   153,   152,  1249,   159,
     152,   158,   922,    61,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   195,   152,   159,   159,   154,   152,   201,
     202,   159,   142,   143,  1275,   122,   123,   990,   210,   152,
     149,   150,   152,    57,   423,   106,   107,   156,     7,   159,
     543,   142,   143,   152,   547,   129,   130,   131,   132,   153,
     152,   152,   149,   150,   158,   237,   238,   239,   159,   156,
       7,    54,   142,   143,    57,   247,   248,   249,    72,   251,
     198,   199,   254,   255,   142,   143,   258,    81,   206,   159,
     152,   470,   210,   152,    88,    89,   153,   269,    92,    93,
     158,   158,   160,   152,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    57,   153,    72,  1059,
      51,   323,   158,    54,     6,  1396,    57,    81,    59,   331,
      57,   152,   334,   154,    88,    89,   160,   336,    92,    93,
     129,   130,   131,   132,    57,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     149,   150,   129,   130,   131,   132,    54,   156,   370,    57,
      59,    59,    51,     8,   376,    54,   142,   143,    57,   381,
      59,   152,   149,   150,   386,   387,   388,   389,    57,   688,
       7,   393,   158,   142,   143,   165,   398,   399,   400,   152,
     170,   154,    54,  1474,   174,    57,   160,    59,   152,   158,
     154,   412,   413,   415,   416,   417,   418,   419,   420,   142,
     143,    54,   424,   425,   426,   427,   428,   149,   150,   431,
     142,   143,   434,   435,    72,   158,   438,   439,   440,   441,
     442,     5,   444,    81,   159,   447,   158,     4,   159,   748,
      88,    89,   751,   455,    92,    93,   755,   142,   143,   461,
     462,   153,   410,   411,     6,     7,   158,   237,    57,   239,
     418,   142,   143,   158,    38,    39,    40,    41,    54,   778,
     482,    45,   152,   485,   154,   484,   152,   158,   154,   144,
     145,   146,   152,  1284,   154,  1286,   151,  1288,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   129,   130,   131,   132,   151,  1257,    75,    76,
      77,    78,   160,     6,     7,   160,    83,   142,   143,    86,
     142,   143,   149,   150,    57,   142,   143,    54,   152,   541,
     154,     4,   548,   158,   142,   143,    72,   549,   547,   153,
    1333,   158,   153,  1336,   158,    81,  1339,   158,   122,   123,
     158,   331,    88,    89,   334,   152,    92,    93,   611,   612,
     613,   142,   143,   142,   143,     4,   578,   165,   580,   581,
     142,   143,   170,     4,   586,   587,   174,   158,   911,   158,
       6,   914,   915,   152,  1385,   154,   158,   152,   600,   154,
     370,   142,   143,   605,   610,   611,   612,   613,   610,   611,
     612,   613,   142,   143,   142,   143,   618,   158,   152,   152,
     622,   623,   142,   143,   149,   150,   628,     6,   158,   154,
     158,   156,   154,   152,   160,  1418,   161,     4,   158,   641,
     152,   643,   154,   152,  1435,   154,  1437,   152,  1439,   154,
     152,   159,   154,   655,  1445,   657,   152,     4,   154,   661,
     662,   663,   664,    54,   152,   152,   154,   669,   438,   439,
     440,   152,   152,   621,   676,  1458,   678,   679,  1461,   152,
     628,  1464,   152,     7,  1467,   455,   634,   152,    72,   688,
      72,  1482,   462,  1484,   152,  1486,   154,    81,   152,    81,
     154,  1108,  1109,   152,    88,    89,    88,    89,    92,    93,
      92,    93,    72,   152,  1497,   154,  1499,   152,  1501,   154,
     152,    81,   724,   725,   152,   152,   154,   154,    88,    89,
       4,     6,    92,    93,     6,     6,   738,   739,   740,   741,
     742,   743,   744,   331,    72,   747,   334,   158,   158,   160,
     160,   753,   158,    81,   160,   757,   158,   148,   160,   761,
      88,    89,   152,     5,    92,    93,     5,   152,  1067,   771,
     772,   773,   774,   775,   152,     8,   160,   158,   160,   160,
     154,    72,   156,   158,     4,   160,   177,   158,   152,   160,
      81,   159,   183,   184,   185,   152,   152,    88,    89,   154,
     160,    92,    93,   194,   152,   158,   197,   160,   578,   152,
     580,     8,   158,    72,   160,   152,   586,   587,   158,   158,
     160,   160,    81,   159,   159,   216,   217,   159,     6,    88,
      89,   152,   160,    92,    93,   152,    57,   785,    59,   158,
      72,   160,   158,   158,   160,   160,   152,   152,   618,    81,
     438,   439,   440,     5,     5,   857,    88,    89,   159,   159,
      92,    93,   158,   862,   160,   159,   154,   455,   870,   160,
     154,   158,  1279,   160,   154,   266,   267,   142,   143,   144,
     145,   146,   830,   831,   832,   655,   151,   657,     5,   891,
     892,   661,   662,   663,   664,   158,   158,   160,   160,   669,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     6,   158,   915,   160,   151,     6,
     158,   923,   160,   158,   158,   160,   160,   160,   160,   156,
     158,   937,   160,   159,   936,   937,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     149,   150,   109,   152,   151,   154,   153,   156,     6,     4,
     159,     6,   161,     6,   158,    72,   160,     6,   154,   971,
     972,   973,     4,   158,    81,   160,   158,   747,   160,   981,
     982,    88,    89,   159,     6,    92,    93,   989,   151,    72,
     578,   158,   580,   160,   158,   997,   160,   158,    81,   160,
     156,   771,   772,   773,   774,    88,    89,     7,     6,    92,
      93,   158,   158,   160,   160,  1017,  1018,  1019,   158,   158,
     160,   160,   158,   158,   160,   160,  1028,  1026,   159,     7,
     618,  1033,   158,   158,   160,   160,   158,   158,   160,   160,
     158,   989,   160,     7,   158,  1051,   160,   158,   160,   160,
    1052,     7,   158,   160,   160,   158,   158,   160,   160,   158,
     154,   160,   152,   152,  1070,     7,   152,   655,  1070,   657,
     152,     6,  1074,   661,   662,   663,   664,   160,  1080,  1081,
     153,   669,     7,  1085,  1293,     7,     6,     4,   159,   159,
    1092,   159,   159,   106,   159,   153,   158,   153,  1104,   153,
    1102,   158,  1104,   158,   153,   158,     6,  1108,  1109,     4,
       6,   155,     6,     4,  1116,     7,   109,     7,     7,     7,
     109,     7,     7,   109,  1126,     7,     7,  1075,  1130,     4,
       6,  1133,   156,   160,  1433,   160,     6,   155,     7,  1145,
       7,     7,   156,  1145,   159,     6,   152,   152,   159,  1151,
    1152,  1450,     6,     4,   545,     7,   153,     6,     6,   747,
     155,     6,  1110,   154,  1112,     6,  1114,   139,     7,     7,
      57,  1173,     7,     7,     7,    59,     7,  1386,  1126,     7,
    1479,  1129,  1130,   771,   772,   773,   774,     6,   153,     7,
    1489,   153,  1491,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   153,  1205,   153,     7,   151,     7,     7,     6,
       4,    12,    13,  1512,     4,   606,   159,     6,   152,     7,
       6,  1223,     7,  1225,     7,     7,   617,   997,   159,     6,
       6,     6,    57,  1235,     6,  1237,     6,     4,  1240,     4,
       4,   160,   152,  1245,     6,     4,     6,   159,  1250,   153,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     153,    62,     7,     6,    65,    66,     6,    68,    69,    70,
     153,     6,    65,    74,  1276,     6,   156,     6,  1279,     6,
     159,  1283,   159,  1285,     6,  1287,   159,   159,     6,     5,
       4,     6,   154,     6,   685,  1297,     7,     7,     7,  1301,
     101,   102,   103,     7,     7,     6,   159,     6,  1310,  1311,
       6,   155,   159,   159,   105,  1317,   159,   159,     6,     6,
       6,   153,   158,  1325,     4,     6,   156,  1329,   109,     6,
       6,     6,     6,     6,     6,  1283,     6,  1285,     6,  1287,
       5,   158,     6,     6,     6,     6,     6,  1295,     6,     6,
    1298,     6,     6,  1355,     6,     6,  1126,     4,     6,   160,
    1130,   159,     6,     6,   156,     7,     6,     6,     5,     7,
      55,  1373,     6,     6,  1376,     6,     6,  1379,     6,   159,
       6,  1383,     6,     6,     6,  1387,   159,  1389,     6,   160,
       6,   160,  1394,   159,     6,  1397,   159,  1399,   789,   790,
     107,   792,   159,   794,   795,   159,   104,   798,   799,   997,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     6,     6,     6,  1430,   151,
       6,   159,     6,     6,     6,   159,     6,   160,     6,   159,
      72,  1389,     6,     4,     4,  1447,  1355,     6,     6,     6,
       6,     6,     6,     6,     6,  1225,     6,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   160,
    1240,     6,  1478,   151,  1476,   159,   159,   159,     6,     6,
     159,   872,   873,   874,     6,     6,   934,     6,     6,     6,
     159,   882,    12,    13,     6,     6,     6,     6,     6,     6,
     159,     6,  1508,   159,     6,     6,  1276,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     6,   941,   159,   159,   151,     3,  1297,     3,   392,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,  1055,    62,    -1,    -1,    65,    66,    -1,    68,    69,
      70,   942,    -1,    -1,    74,    -1,    -1,   948,    -1,    -1,
      -1,    -1,    -1,   954,   955,   956,    -1,    -1,    -1,   960,
      -1,    -1,    -1,    -1,   965,   966,   967,    -1,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     991,    -1,    -1,    -1,   995,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,  1387,    -1,  1389,
     151,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1240,    -1,    -1,    -1,    -1,  1048,    -1,  1050,
    1430,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,     6,  1447,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,  1276,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,  1095,  1096,  1097,  1098,   151,  1297,
      -1,    -1,     3,     4,   101,   102,   103,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,  1139,    -1,
      -1,    42,    -1,    -1,    -1,  1146,    -1,    -1,    -1,    -1,
      51,    -1,  1153,    54,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,  1387,
      -1,  1389,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1220,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,  1447,
      -1,   152,    -1,    -1,     3,     4,   157,    -1,   159,   160,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,  1292,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,     3,     4,    86,    -1,    -1,
    1341,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    42,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,  1398,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,     3,     4,     5,    -1,     7,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    -1,   121,    45,    12,    13,    -1,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,   155,    -1,   157,
      -1,   159,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,   149,   150,
      -1,   152,    -1,   154,    -1,   156,   157,    -1,   159,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,   160,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    -1,    65,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,    -1,    -1,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,
       3,     4,     5,   157,    -1,   159,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,   160,    -1,    -1,    12,    13,    -1,    51,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      83,    -1,    -1,    86,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,
      -1,     3,     4,     5,   157,    -1,   159,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,   160,    -1,    -1,    12,    13,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,   126,   127,   128,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
     152,    -1,     3,     4,    -1,   157,    -1,   159,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     6,
     121,    -1,    -1,   151,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,   152,    -1,     3,     4,    -1,   157,    -1,   159,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,     6,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,   152,    -1,     3,     4,    -1,   157,    -1,   159,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     6,   121,    -1,    -1,   151,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,   152,    -1,     3,     4,    -1,   157,    -1,
     159,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,     6,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,   127,
     128,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,   152,    -1,     3,     4,    -1,   157,
      -1,   159,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,   121,    -1,    -1,   151,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,   152,    -1,     3,     4,     5,
     157,    -1,   159,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    -1,    45,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    40,    41,    42,
       3,     4,    45,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,   121,   122,   123,    -1,    42,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   121,    -1,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,   155,    -1,   157,    -1,   159,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,     3,     4,    -1,    -1,    -1,    42,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,     3,     4,    -1,    -1,    -1,
      42,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,   121,
      -1,   157,    -1,   159,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,   121,    -1,   157,    -1,   159,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,
      -1,    -1,    -1,    -1,   152,    -1,     3,     4,    -1,   157,
      -1,   159,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    -1,     3,     4,    83,    -1,    -1,    86,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    42,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,
     147,     3,     4,     5,    -1,   152,    -1,     9,    10,    11,
     157,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     6,    -1,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,     6,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,     7,     8,    -1,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     7,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,    -1,    -1,   126,   127,   128,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,    -1,   147,     8,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     8,    -1,    -1,    -1,   151,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     8,    -1,    -1,    -1,   151,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     8,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     8,    -1,    -1,
      -1,   151,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,     0,     1,    -1,   151,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,     4,    90,    91,    -1,    -1,    -1,
      95,    -1,    12,    13,    -1,   100,   101,   102,   103,    -1,
      -1,   106,    -1,   108,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    36,    37,    -1,   124,
     125,    -1,    -1,    43,    44,    -1,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    12,    13,
      90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,   106,    -1,   108,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,   125,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   101,   102,   103,
     158,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   158,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,   155,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,   155,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,   155,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,   155,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,   155,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,   155,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     155,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,   155,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,   155,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
     153,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,   153,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
     153,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,   153,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
     153,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,   153,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
     153,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,   153,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,   153,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
     153,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,   153,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,
     151,    -1,   153,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,   153,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,   153,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   163,   164,     6,     0,     4,    12,    13,    36,
      37,    43,    44,    46,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    90,    91,    95,   100,   101,   102,   103,   106,
     108,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   124,   125,   165,   167,   168,   186,   199,   204,
     207,   208,   209,   210,   211,   212,   213,   233,   234,   235,
     236,   237,   238,     3,     4,     5,     7,     9,    10,    11,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    38,    39,    40,    41,    42,    45,   115,   121,   122,
     123,   126,   127,   128,   129,   130,   131,   132,   142,   143,
     147,   149,   150,   152,   154,   156,   157,   159,   184,   185,
     239,   240,   252,    13,    57,   152,   152,     6,   159,     6,
       6,     6,     6,   154,   152,   159,   152,   152,     4,   152,
     159,   152,   152,     4,   159,   152,   152,    61,    57,    57,
       6,    57,    57,    54,    57,    59,    59,    51,    54,    57,
      59,    54,    57,    59,    54,    57,   152,    54,   159,   142,
     143,   152,   159,   241,   242,   241,   159,    51,    54,    57,
     159,   241,     4,    51,    55,    65,    57,    57,    54,     4,
     115,   159,     4,     6,    51,    54,    57,     4,     4,     4,
       5,    35,    51,    54,    57,    59,    69,   143,   152,   159,
     204,   213,   239,   244,   245,   246,     4,   152,   152,   152,
       4,   159,   248,     4,   152,   152,     6,     6,   154,     4,
       4,     5,   159,     5,   159,     6,   152,   159,     4,   154,
     156,   161,   185,   159,     5,   252,   152,   154,   152,   154,
     152,   154,   152,   154,   152,   154,   152,   154,   152,   154,
     152,   154,   152,   154,   152,   154,   152,   154,   152,   154,
     152,   154,   152,   154,   152,   154,   152,   154,   152,   154,
     152,   154,   152,   154,   152,   154,   152,   154,   152,   152,
     152,   152,   152,     7,   152,   152,   152,     4,   239,   239,
     239,   159,   239,   155,   159,   239,     4,   106,   107,     4,
       4,   204,   205,   206,   244,     6,     6,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   151,     6,     6,   239,     5,     5,   239,   188,   239,
     143,   239,   246,   247,   239,   239,   152,   239,   247,   239,
     239,   152,   247,   239,   239,   244,   152,   159,   152,   152,
     245,   245,   245,   152,   200,   201,   202,   203,   152,   152,
     152,   244,   239,     4,   244,   241,   241,   241,   239,   239,
     142,   143,   159,   159,   241,   159,   159,   159,   142,   143,
     152,   206,   241,   159,   152,   159,   152,   152,   152,   245,
     244,   152,     4,     6,   154,   154,   206,     6,   159,   159,
     159,   154,   154,   152,   154,   154,     5,   159,     5,     5,
       5,    51,    54,    57,    59,   159,   239,   246,   239,   160,
     247,     8,   144,     6,     6,   239,   239,   239,   156,   239,
     159,   109,   239,   239,   239,     6,     6,   206,     6,   206,
     244,   244,   154,   239,     4,   159,   169,     6,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
       4,   251,   252,   251,   251,   251,   251,   239,   251,   251,
     251,   154,   247,   153,     7,   184,   247,   155,     7,   184,
     185,   156,     7,   154,   160,    51,    54,    57,    59,   199,
       6,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,     6,   153,   158,   153,
     158,   158,   155,   158,   187,   153,   144,   158,   160,   153,
     153,   239,   153,   160,   153,   153,   239,   160,   153,   153,
       7,   239,   239,   239,   239,     7,     7,   231,   231,   239,
     152,   152,   152,   152,   239,   239,   239,     7,   159,   153,
       6,   158,   158,   158,   241,   241,   205,   205,   158,   239,
     239,   239,   239,   217,   158,   206,   239,   239,   239,   239,
     239,     7,   232,     7,   239,     6,   239,   239,   160,   247,
     247,   247,   239,   239,   153,   159,   155,   159,   239,     4,
     239,   159,   159,   159,   159,   247,   153,   160,   239,   159,
     239,   246,   153,   153,   153,   106,   158,   206,   159,     8,
     153,   155,   160,   160,   153,   158,   160,   239,   155,   185,
     239,     4,    96,    97,    98,    99,   160,   172,   176,   179,
     181,   182,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   158,   158,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   158,   158,
     158,   158,   158,   158,   154,   156,   153,   158,   158,   153,
     153,   158,     6,   158,   153,   158,   160,   184,   244,   160,
     156,   184,   185,   252,   239,     6,     4,     4,   159,   249,
     155,   159,   159,   159,   159,     8,     6,   139,   166,   247,
       6,   247,   239,     6,     4,     7,   239,   246,   109,     7,
       7,   153,     7,   109,     7,     7,   153,   109,     7,     7,
     239,   153,   160,   153,   153,   239,   244,     4,   230,     6,
     153,   196,   239,   252,   196,   196,   196,   153,   153,   153,
     244,   247,   156,   241,   239,   239,   160,   160,   239,   241,
     158,   158,   158,    72,    81,    88,    89,    92,    93,   227,
     228,   241,   160,   214,   153,   160,   153,   153,   153,   239,
       6,   239,   153,   155,   155,   160,   160,   160,   155,   155,
     247,   247,   155,   155,   160,   247,   247,   247,   247,   160,
       8,   247,     7,     7,     7,   156,   239,   160,   239,   239,
       7,   156,   159,   244,     6,   155,   156,   185,   251,   160,
     173,   152,   152,   159,   183,     6,   239,   239,   239,   239,
     239,   239,   239,   239,   239,     4,   247,   251,   251,   239,
     251,   153,   239,     6,   155,     4,   106,   107,   239,     6,
       6,     6,     7,   154,   248,   250,     6,   247,   247,   247,
     247,   239,   139,   251,   153,   153,   158,     7,   241,    57,
     244,   244,     7,   244,    57,    59,   244,   244,     7,    59,
     244,   244,     6,     7,     7,     7,     7,    72,   229,     6,
       7,   153,   153,   153,   153,     7,     7,     7,     6,   160,
       4,   158,   158,   158,   160,   160,   241,   241,   241,     4,
       6,   159,   152,     6,    94,     6,    94,   160,   228,   158,
     227,     7,     6,     7,     7,     7,     6,   159,     6,     6,
       6,    57,   239,     6,     6,   160,   160,   160,   160,   160,
     160,   239,   160,   244,   244,   244,     4,   158,     8,     8,
     153,     4,     4,   244,   160,     6,     4,     6,   152,   239,
     239,   243,   244,   159,   153,   155,   153,   155,   153,   155,
     153,   155,   155,   153,   153,   153,   153,   153,   184,     6,
     184,     7,   184,   185,   156,     7,     6,   248,   239,   158,
     160,   160,   160,   160,   160,     6,     6,   166,     6,   239,
     159,   239,   252,     6,   159,    65,   198,   198,   244,     6,
     159,   159,     6,     6,   244,   159,     6,     6,     5,   244,
     244,   244,     4,     6,   244,     7,     7,     7,     7,   244,
     244,   244,     7,     6,     7,   239,   239,   239,   159,   159,
     158,   160,   158,   160,   158,   160,   154,   239,   244,   239,
       6,     6,   239,   241,   160,     5,   159,   244,   159,   159,
     159,   244,   247,   159,     6,   153,   155,     6,     6,   105,
     239,   239,   239,     6,     6,     7,   158,     6,   185,   170,
     239,   158,   158,   158,   160,   171,   239,   156,   244,   244,
     252,   239,     6,     4,   249,     6,   155,   248,     6,     6,
       6,     6,   251,   158,   239,   252,   239,   241,     6,     6,
       6,   239,   239,     6,   239,     5,     6,     6,   109,   197,
     239,     6,   244,   244,   244,   244,     6,     4,     6,     6,
     239,   239,   252,   160,   153,   158,   160,   205,   205,   241,
       6,   218,   241,     6,   219,   241,     6,   220,   239,   160,
     158,   153,   160,   158,     6,   143,   241,     6,   243,   241,
     241,     6,   160,   239,   244,   158,   160,     8,   160,   153,
     159,   239,   252,   244,   153,   158,   239,   239,   244,   159,
     158,   160,     4,     6,     6,     6,     6,     7,     6,   156,
       6,   239,   189,   190,   160,   160,   160,   160,     5,    55,
       6,     6,     6,     6,     6,   159,   159,     6,     6,   159,
     239,   160,   160,   158,   159,   158,   159,   158,   159,   155,
       6,   244,     7,   159,   239,   158,   160,   158,   158,     6,
     160,   104,   239,   239,   247,     6,     6,   160,   174,   239,
     158,   158,   243,   239,     6,   248,   107,   158,   192,   194,
       6,     6,     6,     6,     6,   159,   243,   247,   205,   158,
     160,   239,   241,   227,   239,   241,   227,   239,   241,   227,
       6,   158,   160,   244,   206,   160,   241,     6,   247,   241,
     239,   160,   160,   160,     6,   159,   239,   239,   160,     6,
     239,   158,   160,   193,   158,   160,   195,   239,   160,   160,
     160,   239,   160,   158,   160,   160,   158,   160,   160,   158,
     160,   244,     6,    72,   160,   215,   159,   158,   160,   158,
       6,     6,   171,   153,   158,     6,   159,   158,     4,     4,
     160,     6,     6,   160,     6,   221,   239,     6,     6,   222,
     239,     6,     6,   223,   239,     6,   160,   239,   227,   206,
     247,     6,   241,   247,   160,   177,   239,   243,   239,     5,
     159,   244,     5,   159,   239,   159,   160,   159,   160,   159,
     160,     6,     6,   160,   160,   216,   160,   158,   160,     6,
     159,   153,   160,   160,   191,   239,   251,   253,   227,     6,
     224,   227,     6,   225,   227,     6,   226,   227,     6,   247,
       6,   175,   251,   180,   159,     6,   158,   160,     7,   158,
     160,   160,   159,   160,   159,   160,   159,   160,   160,   158,
     160,   159,   243,   239,   252,   251,     6,   227,     6,   227,
       6,   227,     6,   251,     6,   178,   251,   160,     7,   160,
     160,   160,   158,   160,     6,   252,     6,     6,     6,   251,
       6
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
#line 165 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 176 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 197 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 201 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 208 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 213 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 218 "Gmsh.y"
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
#line 232 "Gmsh.y"
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
#line 245 "Gmsh.y"
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
#line 258 "Gmsh.y"
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
#line 286 "Gmsh.y"
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
#line 300 "Gmsh.y"
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
#line 311 "Gmsh.y"
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
#line 325 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 339 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 341 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 346 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 348 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 353 "Gmsh.y"
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
#line 457 "Gmsh.y"
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
#line 467 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 476 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 483 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 493 "Gmsh.y"
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
#line 502 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 511 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 518 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 528 "Gmsh.y"
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
#line 536 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 546 "Gmsh.y"
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
#line 565 "Gmsh.y"
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
#line 584 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 590 "Gmsh.y"
    {
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 597 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 598 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 599 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 600 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 601 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 605 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 606 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 615 "Gmsh.y"
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
#line 742 "Gmsh.y"
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
#line 776 "Gmsh.y"
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
#line 824 "Gmsh.y"
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
#line 871 "Gmsh.y"
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
#line 886 "Gmsh.y"
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
#line 902 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 911 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 917 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 926 "Gmsh.y"
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
#line 944 "Gmsh.y"
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
#line 962 "Gmsh.y"
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
#line 971 "Gmsh.y"
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
#line 983 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 988 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 996 "Gmsh.y"
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
#line 1016 "Gmsh.y"
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
#line 1039 "Gmsh.y"
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
#line 1050 "Gmsh.y"
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
#line 1058 "Gmsh.y"
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
#line 1080 "Gmsh.y"
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
#line 1103 "Gmsh.y"
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
#line 1129 "Gmsh.y"
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
#line 1150 "Gmsh.y"
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
#line 1162 "Gmsh.y"
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
#line 1180 "Gmsh.y"
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
#line 1191 "Gmsh.y"
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
#line 1202 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1204 "Gmsh.y"
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
#line 1214 "Gmsh.y"
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
#line 1225 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1227 "Gmsh.y"
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
#line 1240 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1246 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1258 "Gmsh.y"
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
#line 1269 "Gmsh.y"
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
#line 1284 "Gmsh.y"
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
#line 1300 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1308 "Gmsh.y"
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
#line 1317 "Gmsh.y"
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
#line 1336 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1340 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1350 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1354 "Gmsh.y"
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
#line 1366 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1370 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1380 "Gmsh.y"
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
#line 1403 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 1407 "Gmsh.y"
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
#line 1423 "Gmsh.y"
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
#line 1445 "Gmsh.y"
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
#line 1463 "Gmsh.y"
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
#line 1484 "Gmsh.y"
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
#line 1502 "Gmsh.y"
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
#line 1532 "Gmsh.y"
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
#line 1562 "Gmsh.y"
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
#line 1580 "Gmsh.y"
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
#line 1598 "Gmsh.y"
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
#line 1624 "Gmsh.y"
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
#line 1642 "Gmsh.y"
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
#line 1660 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1664 "Gmsh.y"
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
#line 1683 "Gmsh.y"
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
#line 1701 "Gmsh.y"
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
#line 1740 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1746 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1752 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1759 "Gmsh.y"
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
#line 1784 "Gmsh.y"
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
#line 1809 "Gmsh.y"
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
#line 1826 "Gmsh.y"
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
#line 1844 "Gmsh.y"
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
#line 1874 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1878 "Gmsh.y"
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
#line 1898 "Gmsh.y"
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
#line 1916 "Gmsh.y"
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
#line 1933 "Gmsh.y"
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
#line 1949 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1953 "Gmsh.y"
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
#line 1975 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1980 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1985 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1990 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1995 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2000 "Gmsh.y"
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
#line 2023 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2029 "Gmsh.y"
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
#line 2039 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2040 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2045 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2049 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2053 "Gmsh.y"
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
#line 2076 "Gmsh.y"
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
#line 2099 "Gmsh.y"
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
#line 2122 "Gmsh.y"
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
#line 2150 "Gmsh.y"
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
#line 2171 "Gmsh.y"
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
#line 2195 "Gmsh.y"
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
#line 2216 "Gmsh.y"
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
#line 2237 "Gmsh.y"
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
#line 2257 "Gmsh.y"
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
#line 2369 "Gmsh.y"
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
#line 2388 "Gmsh.y"
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
#line 2427 "Gmsh.y"
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
#line 2535 "Gmsh.y"
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
#line 2544 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2550 "Gmsh.y"
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
#line 2565 "Gmsh.y"
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
#line 2593 "Gmsh.y"
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
#line 2610 "Gmsh.y"
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
#line 2624 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2630 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2636 "Gmsh.y"
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
#line 2645 "Gmsh.y"
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
#line 2659 "Gmsh.y"
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
#line 2704 "Gmsh.y"
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
#line 2721 "Gmsh.y"
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
#line 2736 "Gmsh.y"
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
#line 2755 "Gmsh.y"
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
#line 2767 "Gmsh.y"
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
#line 2791 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2795 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2800 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2807 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2813 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2818 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2824 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2828 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2832 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2842 "Gmsh.y"
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

  case 206:

/* Line 1464 of yacc.c  */
#line 2859 "Gmsh.y"
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

  case 207:

/* Line 1464 of yacc.c  */
#line 2876 "Gmsh.y"
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

  case 208:

/* Line 1464 of yacc.c  */
#line 2897 "Gmsh.y"
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

  case 209:

/* Line 1464 of yacc.c  */
#line 2918 "Gmsh.y"
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

  case 210:

/* Line 1464 of yacc.c  */
#line 2953 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2961 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2967 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2974 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2978 "Gmsh.y"
    {
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2987 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2995 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 3003 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 3011 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 3016 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 3024 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 3029 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 3037 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 3042 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 3050 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 3055 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 3063 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 3070 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 3077 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3091 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3098 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3105 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3112 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3131 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3143 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3150 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3155 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3162 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3167 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3174 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3179 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3186 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3191 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3210 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3215 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3222 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3227 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3238 "Gmsh.y"
    {
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3241 "Gmsh.y"
    {
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3247 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 3256 "Gmsh.y"
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

  case 257:

/* Line 1464 of yacc.c  */
#line 3276 "Gmsh.y"
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

  case 258:

/* Line 1464 of yacc.c  */
#line 3299 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3303 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3307 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3311 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3315 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3319 "Gmsh.y"
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

  case 264:

/* Line 1464 of yacc.c  */
#line 3338 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 3350 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3354 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3369 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3373 "Gmsh.y"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 3385 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3389 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3394 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3398 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3405 "Gmsh.y"
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

  case 274:

/* Line 1464 of yacc.c  */
#line 3461 "Gmsh.y"
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

  case 275:

/* Line 1464 of yacc.c  */
#line 3531 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3536 "Gmsh.y"
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

  case 277:

/* Line 1464 of yacc.c  */
#line 3603 "Gmsh.y"
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

  case 278:

/* Line 1464 of yacc.c  */
#line 3639 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 3648 "Gmsh.y"
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

  case 280:

/* Line 1464 of yacc.c  */
#line 3691 "Gmsh.y"
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

  case 281:

/* Line 1464 of yacc.c  */
#line 3716 "Gmsh.y"
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

  case 282:

/* Line 1464 of yacc.c  */
#line 3744 "Gmsh.y"
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

  case 283:

/* Line 1464 of yacc.c  */
#line 3787 "Gmsh.y"
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

  case 284:

/* Line 1464 of yacc.c  */
#line 3810 "Gmsh.y"
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

  case 285:

/* Line 1464 of yacc.c  */
#line 3833 "Gmsh.y"
    {
    ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3836 "Gmsh.y"
    {
    ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3845 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3849 "Gmsh.y"
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

  case 289:

/* Line 1464 of yacc.c  */
#line 3859 "Gmsh.y"
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

  case 290:

/* Line 1464 of yacc.c  */
#line 3893 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3894 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3899 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3904 "Gmsh.y"
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

  case 294:

/* Line 1464 of yacc.c  */
#line 3915 "Gmsh.y"
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

  case 295:

/* Line 1464 of yacc.c  */
#line 3932 "Gmsh.y"
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

  case 296:

/* Line 1464 of yacc.c  */
#line 3959 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3960 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3961 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3962 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3963 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3964 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3965 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3966 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3968 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3974 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3975 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3976 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3977 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3978 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3979 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3980 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3981 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3982 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3983 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3984 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3985 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3986 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3987 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3988 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3989 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3990 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3991 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3992 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3993 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3994 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3995 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3996 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3997 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3998 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3999 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 4000 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 4001 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 4002 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 4003 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 4004 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 4005 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 4008 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 4009 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 4010 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 4011 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 4012 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 4013 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 4014 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 4015 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 4016 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 4017 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 4018 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 4019 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 4020 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 4021 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 4022 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 4023 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 4024 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 4025 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 4026 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 4028 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 4037 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 4039 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4040 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4041 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4042 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
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

  case 366:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
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

  case 367:

/* Line 1464 of yacc.c  */
#line 4088 "Gmsh.y"
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

  case 368:

/* Line 1464 of yacc.c  */
#line 4106 "Gmsh.y"
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

  case 369:

/* Line 1464 of yacc.c  */
#line 4118 "Gmsh.y"
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

  case 370:

/* Line 1464 of yacc.c  */
#line 4135 "Gmsh.y"
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

  case 371:

/* Line 1464 of yacc.c  */
#line 4156 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 4161 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 4166 "Gmsh.y"
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

  case 374:

/* Line 1464 of yacc.c  */
#line 4176 "Gmsh.y"
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

  case 375:

/* Line 1464 of yacc.c  */
#line 4186 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4191 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4203 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4207 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4211 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4215 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4219 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4226 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4230 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4234 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4238 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4250 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4257 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4262 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4266 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4271 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4275 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4283 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4294 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4298 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4310 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4318 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4326 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4333 "Gmsh.y"
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

  case 400:

/* Line 1464 of yacc.c  */
#line 4344 "Gmsh.y"
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

  case 401:

/* Line 1464 of yacc.c  */
#line 4364 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4368 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4372 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4376 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4380 "Gmsh.y"
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

  case 406:

/* Line 1464 of yacc.c  */
#line 4398 "Gmsh.y"
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

  case 407:

/* Line 1464 of yacc.c  */
#line 4416 "Gmsh.y"
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

  case 408:

/* Line 1464 of yacc.c  */
#line 4434 "Gmsh.y"
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

  case 409:

/* Line 1464 of yacc.c  */
#line 4452 "Gmsh.y"
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

  case 410:

/* Line 1464 of yacc.c  */
#line 4462 "Gmsh.y"
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

  case 411:

/* Line 1464 of yacc.c  */
#line 4472 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4485 "Gmsh.y"
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

  case 413:

/* Line 1464 of yacc.c  */
#line 4497 "Gmsh.y"
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

  case 414:

/* Line 1464 of yacc.c  */
#line 4509 "Gmsh.y"
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

  case 415:

/* Line 1464 of yacc.c  */
#line 4528 "Gmsh.y"
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

  case 416:

/* Line 1464 of yacc.c  */
#line 4549 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 4554 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 4558 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4562 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4574 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4578 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4590 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4597 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4607 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4611 "Gmsh.y"
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

  case 426:

/* Line 1464 of yacc.c  */
#line 4626 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4631 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 4638 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 4642 "Gmsh.y"
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

  case 430:

/* Line 1464 of yacc.c  */
#line 4655 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4663 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 4674 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4678 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4686 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4694 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4702 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4710 "Gmsh.y"
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

  case 438:

/* Line 1464 of yacc.c  */
#line 4724 "Gmsh.y"
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

  case 439:

/* Line 1464 of yacc.c  */
#line 4738 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 4742 "Gmsh.y"
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

  case 441:

/* Line 1464 of yacc.c  */
#line 4764 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4769 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10641 "Gmsh.tab.cpp"
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
#line 4772 "Gmsh.y"


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

