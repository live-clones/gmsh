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
     tBetti = 381,
     tGMSH_MAJOR_VERSION = 382,
     tGMSH_MINOR_VERSION = 383,
     tGMSH_PATCH_VERSION = 384,
     tAFFECTDIVIDE = 385,
     tAFFECTTIMES = 386,
     tAFFECTMINUS = 387,
     tAFFECTPLUS = 388,
     tOR = 389,
     tAND = 390,
     tNOTEQUAL = 391,
     tEQUAL = 392,
     tGREATEROREQUAL = 393,
     tLESSOREQUAL = 394,
     UNARYPREC = 395,
     tMINUSMINUS = 396,
     tPLUSPLUS = 397
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
#line 362 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 374 "Gmsh.tab.cpp"

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
#define YYLAST   8106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  444
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1525

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   397

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   148,     2,   158,     2,   147,     2,     2,
     153,   154,   145,   143,   159,   144,   157,   146,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     139,     2,   140,   134,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   155,     2,   156,   152,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   160,     2,   161,   162,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   135,
     136,   137,   138,   141,   142,   149,   150,   151
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
    1706,  1711,  1718,  1725,  1738,  1749,  1760,  1771,  1782,  1785,
    1789,  1796,  1798,  1800,  1802,  1805,  1811,  1819,  1830,  1832,
    1836,  1839,  1842,  1845,  1849,  1853,  1857,  1861,  1865,  1869,
    1873,  1877,  1881,  1885,  1889,  1893,  1897,  1901,  1907,  1912,
    1917,  1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,  1964,
    1969,  1974,  1979,  1984,  1989,  1994,  2001,  2008,  2015,  2020,
    2025,  2030,  2035,  2040,  2045,  2050,  2055,  2060,  2065,  2070,
    2077,  2082,  2087,  2092,  2097,  2102,  2107,  2114,  2121,  2128,
    2133,  2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2155,
    2160,  2165,  2168,  2174,  2178,  2185,  2190,  2198,  2205,  2212,
    2214,  2217,  2220,  2224,  2228,  2240,  2250,  2258,  2266,  2268,
    2272,  2274,  2276,  2279,  2283,  2288,  2294,  2296,  2298,  2301,
    2305,  2309,  2315,  2320,  2323,  2326,  2329,  2332,  2338,  2344,
    2350,  2356,  2358,  2360,  2364,  2368,  2373,  2380,  2387,  2389,
    2391,  2395,  2399,  2409,  2417,  2419,  2425,  2429,  2436,  2438,
    2442,  2444,  2446,  2450,  2457,  2459,  2461,  2466,  2473,  2480,
    2485,  2490,  2495,  2502,  2504
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     164,     0,    -1,   165,    -1,     1,     6,    -1,    -1,   165,
     166,    -1,   169,    -1,   168,    -1,   187,    -1,   200,    -1,
     205,    -1,   209,    -1,   210,    -1,   211,    -1,   214,    -1,
     234,    -1,   235,    -1,   236,    -1,   237,    -1,   213,    -1,
     212,    -1,   208,    -1,   239,    -1,   140,    -1,   140,   140,
      -1,    36,   153,     5,   154,     6,    -1,    37,   153,     5,
     154,     6,    -1,    36,   153,     5,   154,   167,   252,     6,
      -1,    36,   153,     5,   159,   248,   154,     6,    -1,    37,
     153,     5,   159,   248,   154,     6,    -1,    36,   153,     5,
     159,   248,   154,   167,   252,     6,    -1,     4,     5,   160,
     170,   161,     6,    -1,    90,     4,   155,   240,   156,     6,
      -1,    91,     4,   155,   240,   156,     6,    -1,    -1,   170,
     173,    -1,   170,   177,    -1,   170,   180,    -1,   170,   182,
      -1,   170,   183,    -1,   240,    -1,   171,   159,   240,    -1,
     240,    -1,   172,   159,   240,    -1,    -1,    -1,     4,   174,
     153,   171,   154,   175,   160,   172,   161,     6,    -1,   252,
      -1,   176,   159,   252,    -1,    -1,    96,   153,   240,   159,
     240,   159,   240,   154,   178,   160,   176,   161,     6,    -1,
     252,    -1,   179,   159,   252,    -1,    -1,    97,   153,   240,
     159,   240,   159,   240,   159,   240,   154,   181,   160,   179,
     161,     6,    -1,    98,   160,   244,   161,   160,   244,   161,
       6,    -1,    98,   160,   244,   161,   160,   244,   161,   160,
     244,   161,   160,   244,   161,     6,    -1,    -1,    99,   184,
     160,   172,   161,     6,    -1,     7,    -1,   133,    -1,   132,
      -1,   131,    -1,   130,    -1,   151,    -1,   150,    -1,    50,
     155,   189,   156,     6,    -1,     4,   185,   245,     6,    -1,
       4,   155,   156,   185,   245,     6,    -1,     4,   155,   240,
     156,   185,   240,     6,    -1,     4,   153,   240,   154,   185,
     240,     6,    -1,     4,   155,   160,   248,   161,   156,   185,
     245,     6,    -1,     4,   153,   160,   248,   161,   154,   185,
     245,     6,    -1,     4,   186,     6,    -1,     4,   155,   240,
     156,   186,     6,    -1,     4,     7,   253,     6,    -1,     4,
     157,     4,     7,   253,     6,    -1,     4,   155,   240,   156,
     157,     4,     7,   253,     6,    -1,     4,   157,     4,   185,
     240,     6,    -1,     4,   155,   240,   156,   157,     4,   185,
     240,     6,    -1,     4,   157,     4,   186,     6,    -1,     4,
     155,   240,   156,   157,     4,   186,     6,    -1,     4,   157,
     106,   157,     4,     7,   249,     6,    -1,     4,   155,   240,
     156,   157,   106,   157,     4,     7,   249,     6,    -1,     4,
     157,   107,     7,   250,     6,    -1,     4,   155,   240,   156,
     157,   107,     7,   250,     6,    -1,     4,   115,     7,   240,
       6,    -1,   115,   155,   240,   156,     7,     4,     6,    -1,
     115,   155,   240,   156,   157,     4,     7,   240,     6,    -1,
     115,   155,   240,   156,   157,     4,     7,   253,     6,    -1,
     115,   155,   240,   156,   157,     4,     7,   160,   248,   161,
       6,    -1,   115,   155,   240,   156,   157,     4,     6,    -1,
      73,   153,     4,   154,   157,     4,     7,   240,     6,    -1,
      73,   153,     4,   154,   157,     4,     7,   253,     6,    -1,
      -1,   159,    -1,    -1,   189,   188,     4,    -1,   189,   188,
       4,     7,   240,    -1,    -1,   189,   188,     4,     7,   160,
     240,   190,   193,   161,    -1,   189,   188,     4,     7,   253,
      -1,    -1,   189,   188,     4,     7,   160,   253,   191,   195,
     161,    -1,   240,     7,   253,    -1,   192,   159,   240,     7,
     253,    -1,    -1,   193,   194,    -1,   159,     4,   245,    -1,
     159,     4,   160,   192,   161,    -1,   159,     4,     5,    -1,
      -1,   195,   196,    -1,   159,     4,   240,    -1,   159,     4,
       5,    -1,   159,     4,   160,   254,   161,    -1,   240,    -1,
     253,    -1,    -1,   109,    55,   160,   240,   161,    -1,    -1,
      65,   242,    -1,    51,   153,   240,   154,     7,   242,     6,
      -1,    -1,    69,    51,   201,   153,   197,   154,     7,   245,
       6,    -1,    60,    61,   245,     7,   240,     6,    -1,    54,
     153,   240,   154,     7,   245,     6,    -1,    74,    54,   245,
       6,    -1,    58,   153,   240,   154,     7,   245,     6,    -1,
      52,   153,   240,   154,     7,   245,   199,     6,    -1,    53,
     153,   240,   154,     7,   245,   199,     6,    -1,   101,   153,
     240,   154,     7,   245,     6,    -1,   102,   153,   240,   154,
       7,   245,     6,    -1,   103,   153,   240,   154,     7,   245,
     105,   245,   104,   240,     6,    -1,    54,     4,   153,   240,
     154,     7,   245,     6,    -1,    70,    54,   153,   240,   154,
       7,   245,     6,    -1,    -1,    69,    54,   202,   153,   197,
     154,     7,   245,     6,    -1,    65,    57,   153,   240,   154,
       7,   245,     6,    -1,    66,    57,   153,   240,   154,     7,
     245,   198,     6,    -1,    12,    13,     6,    -1,    13,    57,
     240,     6,    -1,    62,    57,   153,   240,   154,     7,     5,
       5,     5,     6,    -1,    55,   153,   240,   154,     7,   245,
       6,    -1,    56,   153,   240,   154,     7,   245,     6,    -1,
      57,     4,   153,   240,   154,     7,   245,     6,    -1,    70,
      57,   153,   240,   154,     7,   245,     6,    -1,    70,    57,
     153,   240,   154,     7,   245,     4,   160,   244,   161,     6,
      -1,    -1,    69,    57,   203,   153,   197,   154,     7,   245,
       6,    -1,    68,    59,   153,   240,   154,     7,   245,     6,
      -1,    59,   153,   240,   154,     7,   245,     6,    -1,    70,
      59,   153,   240,   154,     7,   245,     6,    -1,    -1,    69,
      59,   204,   153,   197,   154,     7,   245,     6,    -1,    76,
     242,   160,   206,   161,    -1,    75,   160,   242,   159,   242,
     159,   240,   161,   160,   206,   161,    -1,    77,   242,   160,
     206,   161,    -1,    78,   160,   242,   159,   240,   161,   160,
     206,   161,    -1,    78,   160,   242,   159,   242,   161,   160,
     206,   161,    -1,     4,   160,   206,   161,    -1,    86,    54,
     160,   248,   161,    57,   160,   240,   161,    -1,    83,    54,
     153,   240,   154,   160,   248,   161,     6,    -1,   207,    -1,
     205,    -1,    -1,   207,   200,    -1,   207,    51,   160,   248,
     161,     6,    -1,   207,    54,   160,   248,   161,     6,    -1,
     207,    57,   160,   248,   161,     6,    -1,   207,    59,   160,
     248,   161,     6,    -1,    80,    65,   153,   240,   154,     7,
     245,     6,    -1,    80,    51,   153,   240,   154,     7,   160,
     244,   161,     6,    -1,    80,    65,   153,   240,   154,     7,
     160,   242,   159,   242,   159,   248,   161,     6,    -1,    80,
      65,   153,   240,   154,     7,   160,   242,   159,   242,   159,
     242,   159,   248,   161,     6,    -1,    80,    55,   153,   240,
     154,     7,   160,   242,   159,   248,   161,     6,    -1,    80,
       4,   153,   240,   154,     7,   245,     6,    -1,    80,     4,
     153,   240,   154,     7,     5,     6,    -1,    80,     4,   160,
     240,   161,     6,    -1,    80,     4,   153,   240,   154,     7,
     160,   242,   159,   242,   159,   248,   161,     6,    -1,    84,
     160,   207,   161,    -1,    84,   115,   155,   240,   156,     6,
      -1,    84,     4,   155,   240,   156,     6,    -1,    84,     4,
       6,    -1,    84,     4,     4,     6,    -1,   106,   249,   160,
     207,   161,    -1,   119,     5,     6,    -1,   120,     5,     6,
      -1,   119,   160,   207,   161,    -1,   120,   160,   207,   161,
      -1,     4,   253,     6,    -1,     4,     4,   155,   240,   156,
     252,     6,    -1,     4,     4,     4,   155,   240,   156,     6,
      -1,     4,   240,     6,    -1,    73,   153,     4,   154,   157,
       4,     6,    -1,   100,     4,     6,    -1,   113,     6,    -1,
     114,     6,    -1,    46,     6,    -1,    43,     6,    -1,    43,
     160,   240,   159,   240,   159,   240,   159,   240,   159,   240,
     159,   240,   161,     6,    -1,    44,     6,    -1,    47,     6,
      -1,    48,     6,    -1,    64,     6,    -1,   108,   153,   240,
       8,   240,   154,    -1,   108,   153,   240,     8,   240,     8,
     240,   154,    -1,   108,     4,   109,   160,   240,     8,   240,
     161,    -1,   108,     4,   109,   160,   240,     8,   240,     8,
     240,   161,    -1,   110,    -1,   118,     4,    -1,   116,    -1,
     117,     4,     6,    -1,   111,   153,   240,   154,    -1,   112,
      -1,    79,   242,   160,   207,   161,    -1,    79,   160,   242,
     159,   242,   159,   240,   161,   160,   207,   161,    -1,    79,
     160,   242,   159,   242,   159,   242,   159,   240,   161,   160,
     207,   161,    -1,    -1,    79,   242,   160,   207,   215,   228,
     161,    -1,    -1,    79,   160,   242,   159,   242,   159,   240,
     161,   160,   207,   216,   228,   161,    -1,    -1,    79,   160,
     242,   159,   242,   159,   242,   159,   240,   161,   160,   207,
     217,   228,   161,    -1,    -1,    79,   160,   207,   218,   228,
     161,    -1,    79,    51,   160,   240,   159,   242,   161,     6,
      -1,    79,    54,   160,   240,   159,   242,   161,     6,    -1,
      79,    57,   160,   240,   159,   242,   161,     6,    -1,    79,
      51,   160,   240,   159,   242,   159,   242,   159,   240,   161,
       6,    -1,    79,    54,   160,   240,   159,   242,   159,   242,
     159,   240,   161,     6,    -1,    79,    57,   160,   240,   159,
     242,   159,   242,   159,   240,   161,     6,    -1,    79,    51,
     160,   240,   159,   242,   159,   242,   159,   242,   159,   240,
     161,     6,    -1,    79,    54,   160,   240,   159,   242,   159,
     242,   159,   242,   159,   240,   161,     6,    -1,    79,    57,
     160,   240,   159,   242,   159,   242,   159,   242,   159,   240,
     161,     6,    -1,    -1,    79,    51,   160,   240,   159,   242,
     161,   219,   160,   228,   161,     6,    -1,    -1,    79,    54,
     160,   240,   159,   242,   161,   220,   160,   228,   161,     6,
      -1,    -1,    79,    57,   160,   240,   159,   242,   161,   221,
     160,   228,   161,     6,    -1,    -1,    79,    51,   160,   240,
     159,   242,   159,   242,   159,   240,   161,   222,   160,   228,
     161,     6,    -1,    -1,    79,    54,   160,   240,   159,   242,
     159,   242,   159,   240,   161,   223,   160,   228,   161,     6,
      -1,    -1,    79,    57,   160,   240,   159,   242,   159,   242,
     159,   240,   161,   224,   160,   228,   161,     6,    -1,    -1,
      79,    51,   160,   240,   159,   242,   159,   242,   159,   242,
     159,   240,   161,   225,   160,   228,   161,     6,    -1,    -1,
      79,    54,   160,   240,   159,   242,   159,   242,   159,   242,
     159,   240,   161,   226,   160,   228,   161,     6,    -1,    -1,
      79,    57,   160,   240,   159,   242,   159,   242,   159,   242,
     159,   240,   161,   227,   160,   228,   161,     6,    -1,   229,
      -1,   228,   229,    -1,    88,   160,   240,   161,     6,    -1,
      88,   160,   245,   159,   245,   161,     6,    -1,    88,   160,
     245,   159,   245,   159,   245,   161,     6,    -1,    81,     6,
      -1,    92,     6,    -1,    92,    94,     6,    -1,    93,     6,
      -1,    93,    94,     6,    -1,    89,   153,   240,   154,     7,
     245,    72,   240,     6,    -1,    72,     4,   155,   240,   156,
       6,    -1,    -1,    72,     4,   240,    -1,    -1,     4,    -1,
      -1,     7,   245,    -1,    -1,     7,   240,    -1,    67,    54,
     246,     7,   240,   230,     6,    -1,    67,    57,   246,   232,
     231,     6,    -1,    63,    57,   160,   240,   161,     7,   245,
       6,    -1,    67,    59,   246,   232,     6,    -1,    95,   246,
       6,    -1,    87,    57,   160,   248,   161,   240,     6,    -1,
      81,    57,   246,   233,     6,    -1,    81,    59,   246,     6,
      -1,    82,    57,   245,     7,   240,     6,    -1,    71,    54,
     245,     7,   245,     6,    -1,    71,    57,   240,   160,   248,
     161,     7,   240,   160,   248,   161,     6,    -1,    51,   160,
     248,   161,   109,    57,   160,   240,   161,     6,    -1,    54,
     160,   248,   161,   109,    57,   160,   240,   161,     6,    -1,
      54,   160,   248,   161,   109,    59,   160,   240,   161,     6,
      -1,    57,   160,   248,   161,   109,    59,   160,   240,   161,
       6,    -1,    85,     6,    -1,    85,     4,     6,    -1,    85,
      51,   160,   248,   161,     6,    -1,   124,    -1,   125,    -1,
     126,    -1,   238,     6,    -1,   238,   160,   245,   161,     6,
      -1,   238,   160,   245,   159,   245,   161,     6,    -1,   238,
     153,   245,   154,   160,   245,   159,   245,   161,     6,    -1,
     241,    -1,   153,   240,   154,    -1,   144,   240,    -1,   143,
     240,    -1,   148,   240,    -1,   240,   144,   240,    -1,   240,
     143,   240,    -1,   240,   145,   240,    -1,   240,   146,   240,
      -1,   240,   147,   240,    -1,   240,   152,   240,    -1,   240,
     139,   240,    -1,   240,   140,   240,    -1,   240,   142,   240,
      -1,   240,   141,   240,    -1,   240,   138,   240,    -1,   240,
     137,   240,    -1,   240,   136,   240,    -1,   240,   135,   240,
      -1,   240,   134,   240,     8,   240,    -1,    14,   153,   240,
     154,    -1,    15,   153,   240,   154,    -1,    16,   153,   240,
     154,    -1,    17,   153,   240,   154,    -1,    18,   153,   240,
     154,    -1,    19,   153,   240,   154,    -1,    20,   153,   240,
     154,    -1,    21,   153,   240,   154,    -1,    22,   153,   240,
     154,    -1,    24,   153,   240,   154,    -1,    25,   153,   240,
     159,   240,   154,    -1,    26,   153,   240,   154,    -1,    27,
     153,   240,   154,    -1,    28,   153,   240,   154,    -1,    29,
     153,   240,   154,    -1,    30,   153,   240,   154,    -1,    31,
     153,   240,   154,    -1,    32,   153,   240,   159,   240,   154,
      -1,    33,   153,   240,   159,   240,   154,    -1,    34,   153,
     240,   159,   240,   154,    -1,    23,   153,   240,   154,    -1,
      14,   155,   240,   156,    -1,    15,   155,   240,   156,    -1,
      16,   155,   240,   156,    -1,    17,   155,   240,   156,    -1,
      18,   155,   240,   156,    -1,    19,   155,   240,   156,    -1,
      20,   155,   240,   156,    -1,    21,   155,   240,   156,    -1,
      22,   155,   240,   156,    -1,    24,   155,   240,   156,    -1,
      25,   155,   240,   159,   240,   156,    -1,    26,   155,   240,
     156,    -1,    27,   155,   240,   156,    -1,    28,   155,   240,
     156,    -1,    29,   155,   240,   156,    -1,    30,   155,   240,
     156,    -1,    31,   155,   240,   156,    -1,    32,   155,   240,
     159,   240,   156,    -1,    33,   155,   240,   159,   240,   156,
      -1,    34,   155,   240,   159,   240,   156,    -1,    23,   155,
     240,   156,    -1,     3,    -1,     9,    -1,    10,    -1,    11,
      -1,   127,    -1,   128,    -1,   129,    -1,     4,    -1,     4,
     162,   160,   240,   161,    -1,     4,   155,   240,   156,    -1,
     158,     4,   155,   156,    -1,     4,   186,    -1,     4,   155,
     240,   156,   186,    -1,     4,   157,     4,    -1,     4,   155,
     240,   156,   157,     4,    -1,     4,   157,     4,   186,    -1,
       4,   155,   240,   156,   157,     4,   186,    -1,   121,   153,
     252,   159,   240,   154,    -1,    42,   153,   252,   159,   252,
     154,    -1,   243,    -1,   144,   242,    -1,   143,   242,    -1,
     242,   144,   242,    -1,   242,   143,   242,    -1,   160,   240,
     159,   240,   159,   240,   159,   240,   159,   240,   161,    -1,
     160,   240,   159,   240,   159,   240,   159,   240,   161,    -1,
     160,   240,   159,   240,   159,   240,   161,    -1,   153,   240,
     159,   240,   159,   240,   154,    -1,   245,    -1,   244,   159,
     245,    -1,   240,    -1,   247,    -1,   160,   161,    -1,   160,
     248,   161,    -1,   144,   160,   248,   161,    -1,   240,   145,
     160,   248,   161,    -1,   245,    -1,     5,    -1,   144,   247,
      -1,   240,   145,   247,    -1,   240,     8,   240,    -1,   240,
       8,   240,     8,   240,    -1,    51,   160,   240,   161,    -1,
      51,     5,    -1,    54,     5,    -1,    57,     5,    -1,    59,
       5,    -1,    69,    51,   160,   248,   161,    -1,    69,    54,
     160,   248,   161,    -1,    69,    57,   160,   248,   161,    -1,
      69,    59,   160,   248,   161,    -1,   205,    -1,   214,    -1,
       4,   155,   156,    -1,     4,   153,   154,    -1,    35,   155,
       4,   156,    -1,     4,   155,   160,   248,   161,   156,    -1,
       4,   153,   160,   248,   161,   154,    -1,   240,    -1,   247,
      -1,   248,   159,   240,    -1,   248,   159,   247,    -1,   160,
     240,   159,   240,   159,   240,   159,   240,   161,    -1,   160,
     240,   159,   240,   159,   240,   161,    -1,     4,    -1,     4,
     157,   106,   157,     4,    -1,   160,   251,   161,    -1,     4,
     155,   240,   156,   157,   107,    -1,   249,    -1,   251,   159,
     249,    -1,   253,    -1,     4,    -1,     4,   157,     4,    -1,
       4,   155,   240,   156,   157,     4,    -1,     5,    -1,    45,
      -1,   122,   153,   252,   154,    -1,   123,   153,   252,   159,
     252,   154,    -1,    39,   153,   252,   159,   252,   154,    -1,
      40,   153,   252,   154,    -1,    41,   153,   252,   154,    -1,
      38,   153,   252,   154,    -1,    38,   153,   252,   159,   248,
     154,    -1,   252,    -1,   254,   159,   252,    -1
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
    3690,  3729,  3754,  3781,  3828,  3851,  3874,  3877,  3886,  3890,
    3900,  3935,  3936,  3937,  3941,  3947,  3959,  3977,  4005,  4006,
    4007,  4008,  4009,  4010,  4011,  4012,  4013,  4020,  4021,  4022,
    4023,  4024,  4025,  4026,  4027,  4028,  4029,  4030,  4031,  4032,
    4033,  4034,  4035,  4036,  4037,  4038,  4039,  4040,  4041,  4042,
    4043,  4044,  4045,  4046,  4047,  4048,  4049,  4050,  4051,  4054,
    4055,  4056,  4057,  4058,  4059,  4060,  4061,  4062,  4063,  4064,
    4065,  4066,  4067,  4068,  4069,  4070,  4071,  4072,  4073,  4074,
    4083,  4084,  4085,  4086,  4087,  4088,  4089,  4093,  4114,  4133,
    4151,  4163,  4180,  4201,  4206,  4211,  4221,  4231,  4236,  4248,
    4252,  4256,  4260,  4264,  4271,  4275,  4279,  4283,  4290,  4295,
    4302,  4307,  4311,  4316,  4320,  4328,  4339,  4343,  4355,  4363,
    4371,  4378,  4388,  4408,  4412,  4416,  4420,  4424,  4453,  4482,
    4511,  4540,  4550,  4560,  4573,  4585,  4597,  4616,  4637,  4642,
    4646,  4650,  4662,  4666,  4678,  4685,  4695,  4699,  4714,  4719,
    4726,  4730,  4743,  4751,  4762,  4766,  4774,  4782,  4790,  4798,
    4812,  4826,  4830,  4852,  4857
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
  "tCohomology", "tBetti", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
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
     385,   386,   387,   388,    63,   389,   390,   391,   392,    60,
      62,   393,   394,    43,    45,    42,    47,    37,    33,   395,
     396,   397,    94,    40,    41,    91,    93,    46,    35,    44,
     123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   163,   164,   164,   165,   165,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   170,   170,   170,   170,   170,   170,
     171,   171,   172,   172,   174,   175,   173,   176,   176,   178,
     177,   179,   179,   181,   180,   182,   182,   184,   183,   185,
     185,   185,   185,   185,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   189,   189,   189,   190,
     189,   189,   191,   189,   192,   192,   193,   193,   194,   194,
     194,   195,   195,   196,   196,   196,   197,   197,   198,   198,
     199,   199,   200,   201,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   202,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   203,   200,
     200,   200,   200,   204,   200,   205,   205,   205,   205,   205,
     205,   205,   205,   206,   206,   207,   207,   207,   207,   207,
     207,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     209,   209,   209,   209,   209,   210,   211,   211,   211,   211,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   214,   215,   214,
     216,   214,   217,   214,   218,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   219,   214,   220,   214,   221,
     214,   222,   214,   223,   214,   224,   214,   225,   214,   226,
     214,   227,   214,   228,   228,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   230,   230,   231,   231,   232,
     232,   233,   233,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   235,   235,   236,   236,   236,   236,   237,   237,
     237,   238,   238,   238,   239,   239,   239,   239,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   242,
     242,   242,   242,   242,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   248,   248,
     248,   248,   249,   249,   249,   249,   250,   250,   251,   251,
     252,   252,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   254,   254
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
       4,     6,     6,    12,    10,    10,    10,    10,     2,     3,
       6,     1,     1,     1,     2,     5,     7,    10,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       4,     2,     5,     3,     6,     4,     7,     6,     6,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     5,     5,     5,
       5,     1,     1,     3,     3,     4,     6,     6,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     3,     6,     1,     1,     4,     6,     6,     4,
       4,     4,     6,     1,     3
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
       0,     0,   291,   292,   293,     5,     7,     6,     8,     9,
      10,    21,    11,    12,    13,    20,    19,    14,    15,    16,
      17,    18,     0,    22,   360,   367,   434,    59,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,     0,
       0,     0,   364,   365,   366,    63,    62,    61,    60,     0,
       0,     0,    65,    64,     0,     0,     0,     0,   165,     0,
       0,     0,   298,     0,     0,     0,     0,     0,   199,     0,
     201,   198,   202,   203,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     0,   123,   136,
     148,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,   288,     0,     0,     0,     0,
       0,   367,   397,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   411,   412,   390,   396,     0,   391,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,   196,   197,
       0,     0,   210,     0,   165,     0,   165,   294,     0,     0,
       0,     0,     0,     0,   371,    34,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   367,
     301,   300,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,     0,   163,     0,    73,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   140,     0,     0,     0,     0,
      94,     0,     0,   418,   419,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,   269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,   380,
       0,     0,     0,     0,   165,   165,     0,     0,     0,     0,
       0,     0,     0,   224,     0,   165,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,   183,     0,     0,     0,
     289,     0,     0,     0,     0,     0,     0,     0,     0,   403,
       0,   404,   405,   406,     0,     0,     0,     0,     0,   300,
     398,     0,   392,     0,     0,     0,   277,   195,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   212,   186,
       0,   187,     0,     0,     0,     0,     0,   373,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   431,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,    59,     0,     0,
       0,    59,     0,     0,     0,     0,     0,   160,     0,     0,
       0,     0,   166,    67,     0,   316,   315,   314,   313,   309,
     310,   312,   311,   304,   303,   305,   306,   307,   308,   141,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   383,   382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,   280,     0,     0,   184,
       0,     0,   180,     0,     0,     0,     0,     0,   414,     0,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,   393,   400,     0,   305,   399,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,   188,   189,     0,     0,
       0,     0,   369,   375,     0,    44,     0,     0,     0,    57,
       0,    35,    36,    37,    38,    39,   318,   339,   319,   340,
     320,   341,   321,   342,   322,   343,   323,   344,   324,   345,
     325,   346,   326,   347,   338,   359,   327,   348,     0,     0,
     329,   350,   330,   351,   331,   352,   332,   353,   333,   354,
     334,   355,     0,     0,     0,     0,     0,     0,     0,     0,
     441,     0,     0,   439,   440,     0,    86,     0,   436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,   370,     0,     0,     0,     0,     0,
      25,    23,     0,     0,    26,     0,     0,    66,    97,     0,
     420,   421,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     270,   268,     0,   276,     0,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,   215,     0,     0,     0,
       0,     0,     0,   272,   279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   369,   415,   402,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,     0,
       0,   185,     0,     0,     0,     0,     0,     0,   295,     0,
       0,   372,     0,   368,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,     0,     0,    74,    76,    78,     0,     0,   428,     0,
      84,     0,     0,     0,     0,   317,    24,     0,     0,     0,
       0,     0,     0,     0,   120,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,     0,     0,   259,     0,   261,
       0,   225,   254,     0,     0,     0,   178,     0,     0,     0,
     281,     0,   182,   181,   290,     0,     0,    32,    33,     0,
       0,   407,   408,   409,   410,   401,   395,     0,     0,     0,
     425,     0,     0,     0,   205,     0,     0,     0,     0,   192,
     374,   191,     0,     0,     0,     0,   388,     0,   328,   349,
     335,   356,   336,   357,   337,   358,     0,   442,   438,   378,
     377,   437,     0,    70,     0,    59,     0,     0,     0,     0,
      69,     0,     0,     0,   426,     0,     0,     0,     0,    27,
      28,     0,    29,     0,     0,    98,   101,   122,     0,     0,
       0,     0,     0,   126,     0,     0,   143,   144,     0,     0,
     128,   151,     0,     0,     0,   118,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,     0,     0,
       0,     0,   165,   165,     0,   235,     0,   237,     0,   239,
       0,   390,     0,     0,   260,   262,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   417,
     416,   131,   132,     0,     0,     0,     0,    87,    91,     0,
       0,   296,   376,     0,    40,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,    81,     0,     0,    82,
       0,   429,   167,   168,   169,   170,     0,     0,    99,   102,
       0,   121,   129,   130,   134,     0,     0,   145,     0,     0,
     275,   138,     0,     0,   266,   150,     0,     0,     0,     0,
     135,     0,   146,   152,     0,     0,     0,     0,   387,     0,
     386,     0,     0,     0,   226,     0,     0,   227,     0,     0,
     228,     0,     0,     0,     0,     0,     0,     0,   177,     0,
       0,   176,     0,     0,     0,   171,     0,     0,     0,     0,
     423,     0,   207,   206,     0,     0,     0,     0,    45,     0,
       0,     0,   389,     0,     0,     0,   433,    72,    71,    77,
      79,     0,    85,     0,    30,     0,   106,   111,     0,     0,
       0,     0,     0,     0,   139,   124,   137,   149,   154,     0,
       0,    92,    93,   165,     0,   158,   159,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,   165,     0,     0,
       0,     0,     0,   162,   161,     0,     0,     0,     0,    88,
      89,     0,     0,    41,     0,     0,     0,    43,    58,     0,
     427,     0,     0,     0,   284,   285,   286,   287,   142,     0,
       0,     0,     0,     0,   385,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   220,     0,
       0,   172,     0,     0,     0,   422,   208,     0,   297,     0,
       0,     0,     0,    83,     0,     0,   100,   107,     0,   103,
     112,     0,     0,     0,   156,     0,   241,     0,     0,   243,
       0,     0,   245,     0,     0,     0,   256,     0,   216,     0,
     165,     0,     0,     0,   133,    90,     0,    49,     0,    55,
       0,     0,     0,     0,   119,   147,   283,   384,   229,     0,
       0,   236,   230,     0,     0,   238,   231,     0,     0,   240,
       0,     0,     0,   222,     0,   175,     0,     0,     0,     0,
       0,     0,     0,   110,     0,   108,   114,     0,   113,     0,
     247,     0,   249,     0,   251,   257,   263,   221,   217,     0,
       0,     0,     0,    46,     0,    53,     0,     0,     0,   418,
     443,     0,     0,   232,     0,     0,   233,     0,     0,   234,
       0,     0,   179,     0,   173,     0,    47,     0,     0,   200,
       0,   109,     0,     0,   115,     0,     0,     0,     0,     0,
       0,   223,     0,     0,     0,     0,     0,     0,   104,   444,
     242,     0,   244,     0,   246,     0,   174,    48,    50,     0,
      51,     0,     0,     0,     0,     0,     0,     0,    56,   105,
     248,   250,   252,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    75,   782,    76,    77,   489,  1153,  1159,
     701,   894,  1312,  1475,   702,  1429,  1509,   703,  1477,   704,
     705,   898,   149,   274,    78,   587,   370,  1266,  1267,  1458,
    1322,  1367,  1323,  1370,   815,  1193,  1080,   562,   396,   397,
     398,   399,   242,   344,   345,    81,    82,    83,    84,    85,
      86,   243,   847,  1389,  1449,   636,  1215,  1218,  1221,  1409,
    1413,  1417,  1464,  1467,  1470,   843,   844,   962,   812,   610,
     645,    88,    89,    90,    91,    92,    93,   244,   152,   409,
     205,  1035,   245,   246,   247,   463,   254,   773,   929,   534,
     535,  1461
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1076
static const yytype_int16 yypact[] =
{
    4396,    49,    18,  4481, -1076, -1076,  2055,    32,    89,   -69,
     -44,    36,    53,   148,   155,   189,    57,  -129,    50,    65,
       7,    69,    87,    16,    91,   103,   277,   193,   289,   366,
     322,   335,   435,   345,   216,   489,   390,   280,   400,   301,
     -68,   -68,   307,   -32,     9,    73,   436,   480,    12,    47,
     511,   492,   564,   573,  2214,   581,   420,   438,   441,    17,
       6, -1076,   444, -1076,   574,   616,   470, -1076,   664,   665,
      23,    27, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076,     2, -1076, -1076,    29,   493,   482, -1076, -1076,
   -1076,   -19,   119,   169,   364,   377,   445,   475,   488,   491,
     494,   495,   499,   503,   507,   532,   535,   546,   554,   555,
     582,   583,   508,   522,   523,   526,   549, -1076,   691,   558,
     561,   562, -1076, -1076, -1076, -1076, -1076, -1076, -1076,  3969,
    3969,  3969, -1076, -1076,  3705,  2008,    13,   720,   374,  2670,
     629,  1284, -1076,   719,   733,  3969,   752,   755, -1076,  3969,
   -1076, -1076, -1076, -1076, -1076,  3969,  3891,  3969,  3969,   608,
    3969,  3891,  3969,  3969,   612,  3891,  3969,  3969,  2670,   627,
     609, -1076,   633,   638,  2214,  2214,  2214,   683, -1076, -1076,
   -1076, -1076,   689,   701,   705,  2670,  3969,   777,  2670,   -68,
     -68,   -68,  3969,  3969,   -63, -1076,   -38,   -68,   706,   723,
     726,  3739,    71,   -50,   734,   738,   742,  2214,  2214,  2670,
     763,    42,   715, -1076,   873, -1076,   748,   759,   767,   789,
     800,   693, -1076,   803,    33,   931,   932,   956,   276,  2822,
    3969,  1852, -1076, -1076,  1076, -1076,   917, -1076,   960,  3969,
    3969,  3969,   824,  3969,   820,   883,  3969,  3969, -1076, -1076,
    3969,   987, -1076,   998, -1076,   999, -1076, -1076,  2670,  2670,
     859,  3969,  1014,   874, -1076, -1076, -1076,  1017,  3969,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
     473,   473,   473,   473,   473,  3969,   473,   473,   473,   218,
     886,   886,   886,  3891,  6799,    97,  3891,  6040,   212,   895,
    1044,   905,   909, -1076,   896,  4557,  1059, -1076, -1076,  3969,
    3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  3969,
    3969,  3969,  3969,  3969, -1076, -1076,  1442,   -76,    62,  5338,
     323,  6820,  3891,  4159, -1076,   589,  6841,  6862,  3969,  6883,
     592,  6904,  6925,  3969,   593,  6946,  6967,  1067,  3969,  3969,
    3969,  3969,  1071,  1073,  1073,  3969,   933,   935,   937,   938,
    3969,  3969,  3969,  1074,  5258,   939,  1079,   -94, -1076, -1076,
    5364,  5390,   -68,   -68,   374,   374,   -42,  3969,  3969,  3969,
    3739,  3739,  3969,  4557,   -36, -1076,  3969,  3969,  3969,  3969,
    3969,  1085,  1089,  1090,  3969,  1092, -1076,  3969,  3969,   894,
   -1076,  3891,  3891,  3891,  3969,  3969,   -91,  3513,  1095, -1076,
    3969, -1076, -1076, -1076,   936,   940,   941,   943,  3891,   886,
   -1076,  6988, -1076,   597,  3969,  2974, -1076, -1076,  7009,  7030,
    7051,  1001,  5416, -1076,   948,  4178,  7072,  6063, -1076, -1076,
    1678, -1076,  1743,   955,   607,  3969,  6086,   271,  3969,    -3,
   -1076,  7093,  6109,  7114,  6132,  7135,  6155,  7156,  6178,  7177,
    6201,  7198,  6224,  7219,  6247,  7240,  6270,  7261,  6293,  7282,
    6316,  7303,  6339,  5442,  5468,  7324,  6362,  7345,  6385,  7366,
    6408,  7387,  6431,  7408,  6454,  7429,  6477,  5494,  5520,  5546,
    5572,  5598,  5624,   615,   112, -1076,   951,   959,   961,   957,
    1468,   962,   965,   963,  3969,   628,    97, -1076,  2670,   631,
      75,   482,  3969,  1108,  1116,    22,   967, -1076,   166,    39,
      25,   168, -1076, -1076,  4206,  1405,  1623,   901,   901,   576,
     576,   576,   576,   324,   324,   886,   886,   886,   886, -1076,
       8,  3891,  1118,  3891,  3969,  1120, -1076,  1123,  1122,  3891,
    3891,  1021,  1124,  1126,  7450,  1127,  1027,  1130,  1131,  7471,
    1031,  1134,  1135,  3969,  7492,  4586,  7513,  7534,  3969,  2670,
    1140,  1139,  7555,  4037,  4037,  4037,  4037,  7576,  7597,  7618,
    2670,  3891,   989, -1076,   -68,  3969,  3969, -1076, -1076,   988,
     990,  3739,  5650,  5676,  5702,  5312,   302,   -68,  2250,  7639,
    4614,  7660,  7681,  7702,  3969,  1142, -1076,  3969,  7723, -1076,
    6500,  6523, -1076,   648,   649,   654,  6546,  6569, -1076,  3891,
   -1076,  3891,  6592,   996,  4642,  3891,  3891,  3891,  3891,   657,
   -1076, -1076,  4225,  3891,   886, -1076,  1148,  1150,  1151,  1004,
    3969,  2402,  3969,  3969, -1076,    45, -1076, -1076,  1003,  2670,
    1159,  6615,   111, -1076,  4670, -1076,  1013,  1015,  1009, -1076,
    1164, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,  3969,  3969,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076,  3969,  3969,  3969,  3969,  3969,  3969,  3969,  1167,
   -1076,  3891,   473, -1076, -1076,   473, -1076,  3969, -1076,   473,
    1018,  3969,  1168,  1025,    19,  3969,  1171,  1177,  1691, -1076,
    1166,  1029,    17,  1179, -1076,  3891,  3891,  3891,  3891,  3969,
   -1076,  1046,   473,   223, -1076,   242,  5728, -1076,  1180,   -68,
    4159, -1076,  1133,  2670,  2670,  1181,  2670,   760,  2670,  2670,
    1184,  1138,  2670,  2670,  1970,  1185,  1186,  1187,  1191,  4282,
   -1076, -1076,  1193, -1076,  1194,  1048,  7954, -1076,  1049,  1050,
    1051,  1202,  1217,  1219,  1224,   686,  1196,   264,  5754,  5780,
   -1076, -1076,  4698,   -73,   -68,   -68,   -68,  1227,  1228,  1075,
    1080,    24,    41,    52, -1076,   287, -1076,   302,  1229,  1232,
    1233,  1234,  1236,  7954, -1076,  2775,  1084,  1239,  1240,  1242,
    1192,  3969,  1244,  1245,   703,   704,    85, -1076, -1076,   710,
     714,   717,   741, -1076,  3969,   744,  2670,  2670,  2670,  1249,
    5806, -1076,  4247,   687,  1250,  1251,  2670,  1096, -1076,  1253,
    1252, -1076,  1254, -1076,  1109,  3969,  3969,  2670,  1101, -1076,
    7744,  6638,  7765,  6661,  7786,  6684,  7807,  6707,  6730, -1076,
     275,  1113,  1114,  7828,  1115,    97,  2794, -1076,    97,   234,
    1106,  1263,  2936, -1076, -1076, -1076,    17,  3969, -1076,   750,
   -1076,   753,   754,   765,   769,  7954, -1076,  1265,    48,  1266,
    3969,  3430,    67,  1117,  1208,  1208,  2670,  1268,  1119,  1132,
    1269,  1270,  2670,  1136,  1274,  1277, -1076,  1279,  2670,  2670,
    2670,  1282,  1285, -1076,  2670,  1286,  1287,  1288,  1290,  2670,
    2670,  2670, -1076,  1291,   183,  3969,  3969,  3969,  1141,  1144,
     -82,   -30,   294,  1145, -1076,  2670,  3969, -1076,  1296, -1076,
    1299, -1076, -1076,  3739,   171,  2366, -1076,  1146,  1147,  3126,
   -1076,  3891, -1076, -1076, -1076,  1149,  3079, -1076, -1076,  1154,
    1155, -1076, -1076, -1076, -1076,  7954, -1076,  1304,  1308,  1210,
   -1076,  3969,  3969,  3969, -1076,  1310,   533,  1158,  1312, -1076,
     271, -1076,  3969,  5832,  5858,   772, -1076,  3969, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076, -1076,  1163, -1076, -1076, -1076,
   -1076, -1076,  2670, -1076,  2670,   482,  3969,  1315,  1318,    22,
   -1076,  1317,  6753,    17, -1076,  1319,  1320,  1322,  1323, -1076,
   -1076,   473, -1076,  5884,  4037,  7954, -1076, -1076,  3969,   -68,
    1324,  1326,  1328, -1076,  3969,  3969, -1076, -1076,  1330,  3969,
   -1076, -1076,  1333,  1334,  1335,  1215,  3969, -1076,  1336,  2670,
    2670,  2670,  2670,  1337,   928,  1338,  3969, -1076,  4037,  4726,
    7849,  4502,   374,   374,   -68,  1340,   -68,  1341,   -68,  1343,
    3969,   363,  1195,  7870, -1076, -1076,  4754,   331, -1076,  1344,
    1630,  1345,  2670,   -68,  1630,  1346,   781,  3969, -1076, -1076,
   -1076, -1076, -1076,  2670,  4530,   659,  7891, -1076, -1076,  3473,
    2670, -1076, -1076,   337,  7954,  3969,  3969,  2670,  1198,   782,
    7954,  1349,  1350,  1353,  1354,  3098, -1076,  1332,  1355, -1076,
    1207, -1076, -1076, -1076, -1076, -1076,  1360,  3969,  7954, -1076,
    4782,   413, -1076, -1076, -1076,  4810,  4838, -1076,  4866,  1364,
   -1076, -1076,  1300,  1367,  7954, -1076,  1368,  1370,  1371,  1373,
   -1076,  1220, -1076, -1076,  5285,  3240,  1376,  1223, -1076,  3969,
   -1076,  1209,  1225,   382, -1076,  1230,   385, -1076,  1235,   393,
   -1076,  1237,  6776,  1378,  2670,  1380,  1238,  3969, -1076,  3278,
     417, -1076,   806,   419,   427, -1076,  1382,  4894,  1289,  3969,
   -1076,  3969, -1076, -1076,  3891,  3998,  1386,  1241, -1076,  3969,
    5910,  5936, -1076,  2670,  3969,  1388, -1076, -1076, -1076, -1076,
   -1076,    17, -1076,  1293, -1076,  5962, -1076, -1076,  1397,  1399,
    1401,  1402,  1403,  1255, -1076, -1076, -1076, -1076, -1076,  2670,
    3891, -1076, -1076,   374,  4558, -1076, -1076,  3739,   302,  3739,
     302,  3739,   302,  1404, -1076,   810,  2670, -1076,  4922,   -68,
    1408,  3891,   -68, -1076, -1076,  3969,  4950,  4978,   811, -1076,
   -1076,  1410,  1257,  7954,  3969,  3969,   817,  7954, -1076,  1427,
   -1076,  3969,   818,   826, -1076, -1076, -1076, -1076, -1076,  3969,
     827,   841,  1273,  3969, -1076,  5006,   431,   248,  5034,   440,
     392,  5062,   459,   466, -1076,  2670,  1429,  1339,  2554,  1278,
     472, -1076,   842,   477,  4066, -1076, -1076,  1431, -1076,  3969,
    7912,  5988,    38, -1076,  6014,  1436, -1076, -1076,  1437, -1076,
   -1076,  5090,  1444,  1445, -1076,  5118,  1446,  3969,  1447,  1448,
    3969,  1450,  1451,  3969,  1452,  1281, -1076,  3969, -1076,   302,
   -1076,  3891,  1453,  3278, -1076, -1076,   851, -1076,  3969, -1076,
    2670,  3969,  2518,  3671, -1076, -1076, -1076, -1076, -1076,  1283,
    5146, -1076, -1076,  1301,  5174, -1076, -1076,  1302,  5202, -1076,
    1454,  4085,   545,  2706,   852, -1076,   496,   856,  1457,  1305,
    7933,   863,  5230, -1076,  1852, -1076, -1076,   473,  7954,   302,
    1458,   302,  1461,   302,  1462, -1076, -1076, -1076, -1076,   302,
    1463,  3891,  1464, -1076,   473, -1076,  1311,  1466,   867,  4107,
   -1076,   868,   624, -1076,  1313,   690, -1076,  1321,   768, -1076,
    1325,   796, -1076,   897, -1076,   902, -1076,  1327,  2670, -1076,
    3969, -1076,   482,   473, -1076,  1471,   302,  1473,   302,  1474,
     302, -1076,  1477,   473,  1480,   473,   914,  4139, -1076, -1076,
   -1076,   829, -1076,   944, -1076,   978, -1076, -1076, -1076,   918,
   -1076,  1486,   482,  1487,  1488,  1489,   473,  1491, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1076, -1076, -1076, -1076,   560, -1076, -1076, -1076, -1076,   140,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076,  -326,     1, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076, -1076, -1076,  -204, -1076,   556,  1497, -1076, -1076,
   -1076, -1076,    -1,  -409,  -208, -1076, -1076, -1076, -1076, -1076,
   -1076,  1499, -1076, -1076, -1076, -1076, -1076, -1076, -1076, -1076,
   -1076, -1076, -1076, -1076, -1076,  -757,  -771, -1076, -1076,  1110,
   -1076, -1076, -1076, -1076, -1076, -1076, -1076,    -2, -1076,    46,
   -1076, -1075,   569,  -118,   823,   231,  -745,   446, -1076,  -287,
      -6, -1076
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     153,   695,    80,   423,   151,   629,   630,   150,   267,   548,
     255,   169,   552,   213,   780,   439,   221,   338,     5,   208,
     174,   252,   209,   919,   165,   210,   771,   928,   263,   174,
     987,   166,   265,   270,   536,   537,   538,   539,   449,   541,
     542,   543,   158,   169,  1399,   154,   435,   989,   436,   412,
     413,   224,   884,   225,  1070,     4,   480,  1232,   482,   160,
     214,   412,   413,   658,   215,   624,   392,   393,   394,   659,
     412,   413,   992,  1077,   216,   200,   201,  1114,   580,  1115,
     412,   413,   547,   581,   156,   202,   204,   206,   979,   212,
     994,   277,   203,   696,   697,   698,   699,   414,   226,   431,
     432,   412,   413,   426,   547,   412,   413,   412,   413,   157,
     427,   200,   201,   412,   413,   533,   276,   631,   988,   339,
     340,   202,   415,   637,   837,   920,   921,   222,   211,  1116,
     217,  1117,   218,   838,   278,   990,   279,   330,   331,   332,
     839,   840,   334,   337,   841,   842,   155,   343,   781,   122,
     123,   124,   125,   366,   161,   268,   127,   369,   700,   256,
     170,   162,   269,   371,   373,   376,   377,   171,   379,   373,
     381,   382,   223,   373,   385,   386,   175,   253,  1316,   142,
     143,  1061,   772,   264,   271,   777,   272,   266,   781,  1107,
    1108,   273,   170,   450,   404,   163,   159,   437,  1400,   776,
     410,   411,   885,   167,  1330,   135,   136,   137,   138,   411,
     412,   413,   164,   991,   412,   413,   582,   638,   168,   551,
     761,   583,   172,   992,   765,   142,   143,   135,   136,   137,
     138,   425,   764,   130,   131,   142,   143,   459,   461,   373,
     173,  1055,   890,   837,   176,   407,   408,   468,   469,   470,
     179,   472,   838,   416,   475,   476,   177,   424,   477,   839,
     840,   142,   143,   841,   842,   681,   750,   188,   890,   486,
     189,   751,   280,   190,   281,   191,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,  1171,   165,
     837,   177,   282,   540,   283,  1431,   775,   454,   778,   838,
     455,   373,  1128,   456,   373,   457,   839,   840,   178,   553,
     841,   842,   135,   136,   137,   138,   180,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   142,   143,   135,   136,   137,   138,   142,   143,
     459,   464,   181,   544,   837,   272,   594,   938,   342,   182,
     273,   599,   590,   838,   142,   143,   604,   605,   606,   607,
     839,   840,   183,   612,   841,   842,   939,   375,   617,   618,
     619,   590,   380,  1496,   187,   892,   384,   412,   413,  1378,
     818,   819,   820,   343,   343,   632,   633,   634,   330,   331,
     635,   142,   143,   975,   639,   640,   641,   642,   643,  1047,
     412,   413,   648,   197,   590,   650,   651,   412,   413,   373,
     373,   373,   656,   657,   195,   662,   993,   196,   664,    39,
      40,    41,    42,  1118,   198,  1119,   373,    47,   627,   628,
      50,   199,   672,   674,   837,   911,   408,   207,   912,   360,
     361,   362,   914,   838,   412,   413,   363,   533,   276,   585,
     839,   840,   586,   691,   841,   842,   694,   276,   693,   184,
    1227,  1248,   185,   219,   186,   937,  1249,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   465,   361,
     362,   122,   123,   124,   125,   363,  1319,   284,   127,   285,
     122,   123,   124,   125,  1223,   412,   413,   127,   412,   413,
     286,  1337,   287,  1340,   220,  1343,   412,   413,   837,  1148,
    1149,  1287,   662,   192,  1289,   767,   193,   838,   194,   228,
     768,   766,  1291,  1381,   839,   840,   412,   413,   841,   842,
     412,   413,   412,   413,   545,   227,   992,   549,   229,   992,
     412,   413,   992,   249,   412,   413,  1299,   230,  1301,   373,
     258,   373,   786,   412,   413,   248,  1302,   674,   790,  1052,
    1377,   250,  1054,  1056,   251,   130,   131,   257,   288,  1380,
     289,   804,   412,   413,   130,   131,   809,   817,   817,   817,
     817,   816,   816,   816,   816,   412,   413,   837,  1383,   373,
     412,   413,   259,   828,   829,   260,   838,  1384,   290,   832,
     291,  1391,  1422,   839,   840,   347,  1393,   841,   842,   412,
     413,   292,   853,   293,   294,   855,   295,   296,   298,   297,
     299,   992,   300,   275,   301,  1451,   302,   373,   303,   373,
     304,   320,   305,   373,   373,   373,   373,  1241,   261,   262,
     827,   373,   653,   654,   655,   321,   322,   833,   880,   323,
     882,   883,  1462,   845,  1465,   306,  1468,   307,   308,   669,
     309,   992,  1471,   891,   992,  1023,   837,   992,   325,   310,
     992,   311,   324,  1211,  1212,   838,  1447,   312,   314,   313,
     315,   326,   839,   840,   327,   328,   841,   842,   346,   358,
     359,   360,   361,   362,   341,   364,   900,   901,   363,  1501,
     992,  1503,   992,  1505,   992,   316,   318,   317,   319,   365,
     902,   903,   904,   905,   906,   907,   908,   387,   590,   373,
     591,   590,   590,   596,   600,   913,   590,   367,   671,   916,
     368,   378,   837,   922,   403,   383,   689,   406,   690,   389,
     748,   838,   749,   373,   373,   373,   373,   935,   839,   840,
     388,   405,   841,   842,  1176,  1485,   390,   590,   433,   760,
     590,   391,   763,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   590,   590,   859,
     860,   363,   783,   590,   785,   861,   590,   948,   873,   949,
    1242,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   942,   395,   483,   484,   363,
     837,  1024,   400,   142,   143,   590,   446,   973,   447,   838,
     272,  1487,   825,   148,   401,   273,   839,   840,   402,  1006,
     841,   842,   590,   590,  1009,  1010,   417,   891,   837,   590,
     438,  1011,  1015,   590,  1332,  1012,   590,   838,  1013,   440,
     980,   981,   982,   418,   839,   840,   419,   428,   841,   842,
     864,   429,   865,  1033,  1034,   430,   869,   870,   871,   872,
     590,   837,  1014,   590,   875,  1016,     7,     8,   441,  1063,
     838,  1064,   590,   590,  1065,  1066,   434,   839,   840,   442,
    1057,   841,   842,   466,   590,  1062,  1067,   443,   590,  1489,
    1068,  1157,  1201,  1158,  1202,  1076,   451,   452,  1073,  1075,
     590,  1254,  1236,  1255,   444,   558,    18,    19,   559,    21,
      22,   560,    24,   561,    26,   445,    27,  1491,   448,    30,
      31,   453,    33,    34,    35,  1157,   467,  1300,    38,  1345,
     590,  1346,  1357,  1109,  1110,  1111,  1157,  1365,  1362,  1366,
     473,   471,   910,  1121,  1123,  1368,  1157,  1369,  1372,   374,
    1513,  1126,   474,   478,   374,    56,    57,    58,   374,   373,
     590,   590,  1373,  1392,   479,   481,   931,   932,   933,   934,
    1254,   590,  1428,  1450,   485,   590,   837,  1452,   487,  1144,
    1145,  1146,  1157,   490,  1456,   838,  1480,  1483,  1481,  1484,
    1154,  1152,   839,   840,   488,  1160,   841,   842,   363,  1127,
     354,   355,   356,   357,   358,   359,   360,   361,   362,  1164,
     837,   555,   554,   363,  1165,   652,   590,   557,  1492,   838,
     556,  1493,   460,  1494,   374,   563,   839,   840,  1179,   148,
     841,   842,  1178,  1157,   603,  1511,  1180,  1516,   608,  1517,
     609,   620,  1185,  1186,   464,   623,   613,  1188,   614,  1348,
     615,   616,   644,   622,  1194,   646,   665,   647,   649,   663,
     666,   667,  1206,   668,  1204,  1514,  1205,   679,   682,   688,
     752,   343,   343,   753,   769,   754,   755,   762,  1222,   758,
     770,   757,   759,   774,   784,  1181,   787,   788,   373,   789,
     792,   793,   373,   794,   796,  1237,   797,   798,   799,  1515,
     801,   802,   803,  1246,   811,   813,   826,  1245,   854,   830,
    1460,   831,   867,  1250,  1251,   876,   374,   877,   878,   374,
    1213,   879,  1216,   886,  1219,   888,   895,  1476,   896,   897,
     899,   909,   915,   926,   917,  1265,  1230,   923,   810,  1233,
    1234,   918,  1423,   924,   927,   930,   936,   941,   946,   824,
     943,   952,   957,   958,   959,   460,  1499,   953,   960,   963,
     974,   964,   965,   966,   967,   968,  1507,  1284,  1510,   969,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   465,   361,   362,   970,  1298,   971,   459,   363,  1523,
     972,   983,  1136,   986,   984,   985,   995,  1306,   996,  1307,
     997,   998,   373,   999,  1001,  1002,  1003,  1313,  1004,  1005,
    1007,  1008,  1317,  1020,  1025,  1026,  1030,  1028,   887,  1029,
    1031,  1037,  1032,  1058,   374,   374,   374,  1048,  1049,  1051,
    1059,  1069,  1072,  1079,  1083,  1086,  1087,  1078,   373,  1084,
    1090,   374,   343,  1091,  1092,  1335,  1096,  1338,   675,  1341,
     348,  1097,  1085,  1099,  1100,  1101,  1089,  1102,  1106,   373,
    1120,  1112,  1124,  1354,  1113,  1125,  1132,  1133,  1139,  1137,
    1141,  1140,  1360,  1361,  1142,  1143,  1147,  1150,  1151,  1364,
    1161,  1166,  1167,  1169,  1192,  1172,  1173,  1371,  1174,  1175,
    1182,  1375,  1183,  1336,  1184,  1339,  1187,  1342,  1189,  1261,
    1190,  1191,  1195,  1200,  1203,  1350,  1214,  1217,  1353,  1220,
    1228,  1231,  1235,  1256,  1224,  1273,  1257,  1160,  1253,  1258,
    1259,  1262,   944,   945,  1263,   947,  1264,   950,   951,  1272,
    1285,   954,   955,  1274,  1275,  1410,  1276,  1277,  1414,  1278,
    1279,  1418,  1282,  1283,  1294,  1421,  1286,  1296,  1303,   373,
    1288,   373,  1310,  1305,  1318,  1290,  1430,  1292,  1297,  1432,
    1320,  1438,  1311,  1324,   374,  1325,   374,  1326,  1327,  1328,
    1344,  1387,   675,   791,  1351,  1329,  1358,  1359,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,  1459,  1363,  1374,  1386,   363,  1395,  1390,  1426,
    1402,  1403,  1420,  1439,   374,  1017,  1018,  1019,   579,   373,
    1405,  1406,  1408,  1411,  1412,  1027,  1415,  1416,  1419,  1425,
    1445,  1441,  1443,  1453,  1463,  1454,  1036,  1466,  1469,  1472,
    1474,  1478,  1479,  1486,   756,  1308,  1498,  1500,  1497,  1502,
    1504,  1488,   374,  1506,   374,  1490,  1508,  1495,   374,   374,
     374,   374,  1518,  1520,  1521,  1522,   374,  1524,  1071,  1396,
      79,  1081,    87,     0,   611,  1168,  1519,     0,     0,     0,
       0,  1331,     0,     0,     0,  1082,     0,     0,     0,     0,
       0,  1088,     0,     0,     0,     0,     0,  1093,  1094,  1095,
       0,     0,  1352,  1098,     0,     0,     0,     0,  1103,  1104,
    1105,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,  1122,     0,     0,   363,     0,     0,
       0,     0,     0,     0,  1131,     0,     0,     0,  1135,     0,
       0,     0,     0,     0,   374,     0,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,   374,   374,
     374,   374,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,  1162,  1424,  1163,  1427,     0,     0,     0,     0,     0,
       0,     0,     0,    94,   231,     0,     0,     0,     0,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   233,     0,     0,  1196,  1197,
    1198,  1199,   126,     0,     0,     0,     0,     0,     0,     0,
       0,   234,  1473,     0,   235,     0,     0,   236,     0,   237,
       7,     8,     0,     0,     0,     0,     0,   925,     0,   238,
       0,  1036,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,  1238,    47,     0,     0,    50,     0,     0,  1247,
       0,     0,     0,     0,     0,     0,  1252,     0,     0,   558,
      18,    19,   559,    21,    22,   560,    24,   561,    26,     0,
      27,     0,     0,    30,    31,     0,    33,    34,    35,     0,
       0,   129,    38,     0,     0,     7,     8,   132,   133,   134,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,   420,  1229,   363,     0,     0,   141,    56,
      57,    58,     0,   422,     0,     0,     0,     0,   147,     0,
     203,   462,     0,  1295,   558,    18,    19,   559,    21,    22,
     560,    24,   561,    26,     0,    27,     0,     0,    30,    31,
       0,    33,    34,    35,     0,     0,     0,    38,     0,     0,
       0,     0,  1036,     0,   374,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   686,
       0,     0,     0,   363,    56,    57,    58,     0,  1036,     0,
       0,     0,     0,     0,     0,    94,   231,     0,     0,     0,
       0,    98,    99,   100,     0,  1347,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   233,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   687,     0,   235,     0,     0,   236,
       0,   237,     0,     0,  1385,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,     0,     0,     0,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1036,
       0,  1435,     0,   129,     0,     0,   956,     0,     0,   132,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   372,     0,     0,     0,
     141,     0,     0,     0,     0,   240,     0,     0,     0,     0,
     147,    94,   329,   462,     0,     0,     0,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,  1036,     0,     0,
     126,     0,   460,     0,     0,     0,     0,     0,    94,    95,
      96,     0,    97,     0,    98,    99,   100,   374,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,   122,   123,   124,   125,   126,     0,     0,
     127,     0,     0,   374,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   374,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,   132,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,   140,     0,     0,     0,   141,     0,     0,     0,
       0,   240,     0,     0,   335,     0,   147,     0,   336,     0,
     128,     0,     0,     0,     0,     0,   129,   130,   131,     0,
       0,     0,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,     0,   141,     0,   142,   143,     0,   144,     0,
     145,     0,   146,   147,   374,   148,   374,    94,   231,   232,
       0,     0,     0,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   233,
       0,     0,     0,     0,     0,     0,   126,   374,     0,     0,
       0,     0,     7,     8,     0,   234,     0,     0,   235,     0,
       0,   236,     0,   237,   374,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,   558,    18,    19,   559,    21,    22,   560,    24,   561,
      26,     0,    27,     0,     0,    30,    31,     0,    33,    34,
      35,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
       0,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,     0,     0,   139,   239,     0,
       0,     0,   141,     0,     0,     0,     0,   240,     0,    94,
     231,  1129,   147,     0,   241,    98,    99,   100,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   233,     0,     0,     0,     0,     0,     0,   126,     0,
       0,   846,     0,     0,     7,     8,     0,   234,     0,     0,
     235,     0,     0,   236,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,   558,    18,    19,   559,    21,    22,   560,
      24,   561,    26,     0,    27,     0,     0,    30,    31,     0,
      33,    34,    35,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
       0,     0,     0,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,     0,     0,     0,   139,
     239,     0,     0,     0,   141,     0,     0,     0,     0,   240,
       0,    94,   231,  1433,   147,     0,  1130,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   233,     0,     0,     0,     0,     0,     0,
     126,     0,     0,   881,     0,     0,     7,     8,     0,   234,
       0,     0,   235,     0,     0,   236,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,   558,    18,    19,   559,    21,
      22,   560,    24,   561,    26,     0,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,   132,   133,   134,     0,     0,
       0,     0,     0,     0,     0,    56,    57,    58,     0,     0,
       0,   139,   239,     0,     0,     0,   141,     0,     0,     0,
       0,   240,     0,    94,   231,     0,   147,     0,  1434,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   233,     0,     0,     0,     0,
       0,     0,   126,     0,     0,  1388,     0,     0,     7,     8,
       0,   234,     0,     0,   235,     0,     0,   236,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,   558,    18,    19,
     559,    21,    22,   560,    24,   561,    26,     0,    27,     0,
       0,    30,    31,     0,    33,    34,    35,     0,     0,     0,
      38,  1000,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   132,   133,   134,
    1053,     0,     0,     0,     0,     0,     0,    56,    57,    58,
       0,     0,     0,   139,   239,     0,     0,     0,   141,     0,
       0,     0,     0,   240,     0,    94,   231,     0,   147,     0,
     241,    98,    99,   100,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   233,     0,     0,
       0,     0,     0,     0,   126,     0,     0,  1448,     0,     0,
       0,     0,     0,   234,     0,     0,   235,     0,     0,   236,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,  1060,   129,     0,     0,   363,     0,     0,   132,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   372,     0,     0,     0,
     141,     0,     0,     0,     0,   240,     0,    94,   231,     0,
     147,     0,   458,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   233,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,   235,     0,
       0,   236,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,  1138,     0,     0,   363,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0,
       0,   132,   133,   134,  1260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   372,     0,
       0,     0,   141,     0,     0,     0,     0,   240,     0,    94,
     231,     0,   147,     0,   673,    98,    99,   100,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   233,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     235,     0,     0,   236,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,  1281,   129,     0,     0,
     363,     0,     0,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     239,     0,     0,     0,   141,     0,     0,     0,     0,   240,
       0,    94,   231,     0,   147,     0,  1134,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   233,     0,     0,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,   235,     0,     0,   236,     0,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,   132,   133,   134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,  1229,     0,     0,     0,   141,     0,     0,     0,
       0,   422,     0,    94,   329,   276,   147,     0,   203,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   122,   123,
     124,   125,   126,     0,     0,   127,    94,   329,   276,     0,
       0,     0,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,   122,   123,   124,   125,   126,    94,   329,   127,     0,
       0,     0,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,   129,   130,   131,     0,   126,     0,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139,   140,     0,     0,     0,   141,     0,
       0,     0,     0,   240,     0,     0,     0,     0,   147,     0,
    1074,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,   141,     0,     0,     0,     0,   240,     0,     0,     0,
       0,   147,     0,  1244,   129,     0,     0,     0,     0,     0,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,   141,     0,     0,     0,     0,   240,     0,     0,   660,
       0,   147,     0,   661,    94,   329,  1436,     0,     0,     0,
      98,    99,   100,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,    94,   329,
       0,     0,     0,   126,    98,    99,   100,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,    94,   329,     0,     0,     0,   126,    98,    99,
     100,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   140,     0,     0,     0,   141,
       0,     0,     0,     0,   240,     0,   129,     0,     0,   147,
       0,  1437,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   140,
       0,     0,     0,   141,     0,     0,     0,     0,   240,     0,
     129,     0,     0,   147,     0,   333,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   421,     0,     0,     0,   141,     0,     0,
       0,     0,   422,     0,    94,   231,     0,   147,     0,   203,
      98,    99,   100,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   233,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,   235,     0,     0,   236,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,    94,   329,    47,     0,     0,    50,    98,    99,
     100,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,  1309,     0,     0,     0,     0,     0,
       0,   126,   129,     0,     0,     0,     0,     0,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   372,     0,     0,     0,   141,
      94,   329,   276,     0,   240,     0,    98,    99,   100,   147,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,  1394,     0,     0,   122,   123,   124,   125,   126,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
     129,  1446,     0,     0,     0,     0,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,  1482,   464,     0,   141,     0,     0,
       0,     0,   240,     0,     0,     0,     0,   147,     0,     0,
       0,     0,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,  1512,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   132,   133,   134,   464,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   140,     0,     0,     0,   141,   683,     0,     0,     0,
     240,     0,     0,     0,     0,   147,     0,     0,     0,     0,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   779,     0,     0,     0,   363,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   874,     0,     0,     0,   363,     0,     0,
       0,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   589,   361,   362,  1022,     0,     0,     0,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   589,   361,   362,     0,     0,     0,
       0,   363,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   961,     0,     0,     0,   363,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,     0,
       0,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,    -4,     1,     0,   363,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,    -4,    -4,   363,     0,     0,     0,     0,    -4,
      -4,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,
       0,    -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,
      -4,    -4,    -4,     0,    11,    12,     0,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     7,
       8,    52,    53,     0,     0,     0,    54,     0,     0,     0,
       0,    55,    56,    57,    58,     0,     0,    59,     0,    60,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,    72,    73,    74,   558,    18,
      19,   559,    21,    22,   560,    24,   561,    26,     0,    27,
       0,     0,    30,    31,     0,    33,    34,    35,     0,     0,
       0,    38,     0,     0,     0,     0,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,    56,    57,
      58,  1209,     0,  1210,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,  1239,
       0,  1240,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,  1333,     0,  1334,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,   806,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,   849,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,   868,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,   893,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,     0,   978,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,  1207,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,  1226,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,  1268,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,  1269,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,     0,  1270,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,  1271,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,  1304,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,  1349,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,  1355,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,     0,  1356,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,  1376,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,  1379,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,  1382,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,  1404,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,     0,  1407,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,  1440,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,  1442,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,     0,     0,  1444,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,  1457,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,     0,   621,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,     0,
       0,     0,     0,     0,     0,  1280,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   670,     0,     0,     0,
       0,   625,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   584,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,   625,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   626,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,   680,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,   728,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   729,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,   742,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   743,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,   744,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,   745,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   746,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,   747,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   834,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,   835,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,   836,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   940,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,   976,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   977,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,  1021,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,  1155,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,  1156,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,  1177,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,  1314,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,  1315,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,  1321,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,  1398,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,  1401,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,   550,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,     0,     0,   685,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,   692,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,     0,     0,   707,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,   709,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,     0,
       0,   711,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,   713,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,     0,     0,   715,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
     717,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,     0,     0,   719,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,   721,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,     0,     0,   723,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,   725,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,     0,     0,   727,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,   731,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,     0,
       0,   733,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,   735,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,     0,     0,   737,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
     739,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,     0,     0,   741,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,   857,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,     0,     0,   858,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,   862,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,     0,     0,   863,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,     0,     0,   866,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,     0,
       0,   889,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,     0,     0,  1039,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,     0,     0,  1041,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,     0,     0,
    1043,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,     0,     0,  1045,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,     0,     0,  1046,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,     0,     0,  1170,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
       0,     0,  1293,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   546,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   588,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,   592,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   593,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,   595,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,   597,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,   598,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
     601,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,   602,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,   670,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   676,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   677,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,   678,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   684,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,   706,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,   708,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,   710,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
     712,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,   714,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,   716,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   718,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   720,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,   722,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   724,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,   726,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,   730,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,   732,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
     734,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,   736,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,   738,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   740,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   795,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,   800,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   805,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,   807,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,   808,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,   814,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
     821,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,   822,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,   823,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,   848,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,   850,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,   851,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,   852,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,   856,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363,     0,  1038,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,     0,     0,   363,     0,  1040,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,     0,     0,     0,     0,   363,     0,
    1042,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,     0,     0,     0,   363,
       0,  1044,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     0,     0,     0,     0,
     363,     0,  1050,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     0,     0,     0,
       0,   363,     0,  1208,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,   363,     0,  1225,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,     0,   363,     0,  1243,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
       0,     0,     0,     0,   363,     0,  1397,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,     0,     0,   363,     0,  1455,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,     0,     0,   363
};

static const yytype_int16 yycheck[] =
{
       6,     4,     3,   211,     6,   414,   415,     6,     6,   335,
       4,     4,   338,     4,     6,   223,     4,     4,     0,    51,
       4,     4,    54,     4,   153,    57,     4,   772,     5,     4,
       6,   160,     5,     4,   321,   322,   323,   324,     5,   326,
     327,   328,     6,     4,     6,    13,     4,     6,     6,   143,
     144,     4,     7,     6,     6,     6,   264,  1132,   266,     6,
      51,   143,   144,   154,    55,   159,   184,   185,   186,   160,
     143,   144,   843,     6,    65,   143,   144,   159,   154,   161,
     143,   144,     7,   159,   153,   153,    40,    41,   161,    43,
     847,    97,   160,    96,    97,    98,    99,   160,    51,   217,
     218,   143,   144,   153,     7,   143,   144,   143,   144,   153,
     160,   143,   144,   143,   144,     4,     5,   159,    94,   106,
     107,   153,   160,   159,    72,   106,   107,   115,   160,   159,
      57,   161,    59,    81,   153,    94,   155,   139,   140,   141,
      88,    89,   144,   145,    92,    93,    57,   148,   140,    38,
      39,    40,    41,   155,     6,   153,    45,   159,   161,   153,
     153,     6,   160,   165,   166,   167,   168,   160,   170,   171,
     172,   173,   160,   175,   176,   177,   160,   160,  1253,   150,
     151,   926,   160,   160,   155,   160,   157,   160,   140,     6,
       7,   162,   153,   160,   196,     6,   160,   155,   160,   160,
     202,   203,   157,   153,  1279,   130,   131,   132,   133,   211,
     143,   144,   155,   161,   143,   144,   154,   425,   153,     7,
     546,   159,   153,   994,   550,   150,   151,   130,   131,   132,
     133,   160,   157,   122,   123,   150,   151,   239,   240,   241,
     153,     7,   157,    72,   153,   199,   200,   249,   250,   251,
      57,   253,    81,   207,   256,   257,   153,   211,   260,    88,
      89,   150,   151,    92,    93,   473,   154,    51,   157,   271,
      54,   159,   153,    57,   155,    59,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,  1063,   153,
      72,   153,   153,   325,   155,  1400,   160,    51,   160,    81,
      54,   333,   161,    57,   336,    59,    88,    89,    61,   338,
      92,    93,   130,   131,   132,   133,    57,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   150,   151,   130,   131,   132,   133,   150,   151,
     372,     8,     6,   155,    72,   157,   378,   154,     4,    57,
     162,   383,   159,    81,   150,   151,   388,   389,   390,   391,
      88,    89,    57,   395,    92,    93,   154,   166,   400,   401,
     402,   159,   171,  1478,    59,   692,   175,   143,   144,   161,
     614,   615,   616,   414,   415,   417,   418,   419,   420,   421,
     422,   150,   151,   159,   426,   427,   428,   429,   430,   154,
     143,   144,   434,   153,   159,   437,   438,   143,   144,   441,
     442,   443,   444,   445,    54,   447,   159,    57,   450,    75,
      76,    77,    78,   159,    54,   161,   458,    83,   412,   413,
      86,   160,   464,   465,    72,   752,   420,   160,   755,   145,
     146,   147,   759,    81,   143,   144,   152,     4,     5,   156,
      88,    89,   159,   485,    92,    93,   488,     5,   487,    54,
     159,   154,    57,    57,    59,   782,   159,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    38,    39,    40,    41,   152,  1261,   153,    45,   155,
      38,    39,    40,    41,   161,   143,   144,    45,   143,   144,
     153,  1288,   155,  1290,    54,  1292,   143,   144,    72,     6,
       7,   159,   544,    54,   159,   551,    57,    81,    59,    57,
     552,   550,   159,   161,    88,    89,   143,   144,    92,    93,
     143,   144,   143,   144,   333,    54,  1337,   336,     4,  1340,
     143,   144,  1343,   153,   143,   144,   159,     4,   159,   581,
       6,   583,   584,   143,   144,     4,   159,   589,   590,   915,
     159,   153,   918,   919,   153,   122,   123,   153,   153,   159,
     155,   603,   143,   144,   122,   123,   608,   613,   614,   615,
     616,   613,   614,   615,   616,   143,   144,    72,   159,   621,
     143,   144,     6,   625,   626,   155,    81,   161,   153,   631,
     155,   159,  1389,    88,    89,     6,   159,    92,    93,   143,
     144,   153,   644,   155,   153,   647,   155,   153,   153,   155,
     155,  1422,   153,   160,   155,   159,   153,   659,   155,   661,
     153,   153,   155,   665,   666,   667,   668,     8,     4,     4,
     624,   673,   441,   442,   443,   153,   153,   631,   680,   153,
     682,   683,  1439,   637,  1441,   153,  1443,   155,   153,   458,
     155,  1462,  1449,   692,  1465,     8,    72,  1468,     7,   153,
    1471,   155,   153,  1112,  1113,    81,   161,   153,   153,   155,
     155,   153,    88,    89,   153,   153,    92,    93,   149,   143,
     144,   145,   146,   147,     4,     6,   728,   729,   152,  1486,
    1501,  1488,  1503,  1490,  1505,   153,   153,   155,   155,     6,
     742,   743,   744,   745,   746,   747,   748,   178,   159,   751,
     161,   159,   159,   161,   161,   757,   159,     5,   161,   761,
       5,   153,    72,   765,   195,   153,   159,   198,   161,   160,
     155,    81,   157,   775,   776,   777,   778,   779,    88,    89,
     153,     4,    92,    93,  1071,   161,   153,   159,   219,   161,
     159,   153,   161,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   159,   159,   161,
     161,   152,   581,   159,   583,   161,   159,    57,   161,    59,
     161,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   789,   153,   268,   269,   152,
      72,   154,   153,   150,   151,   159,   153,   161,   155,    81,
     157,   161,   621,   160,   153,   162,    88,    89,   153,   861,
      92,    93,   159,   159,   161,   161,   160,   866,    72,   159,
     155,   161,   874,   159,  1283,   161,   159,    81,   161,     6,
     834,   835,   836,   160,    88,    89,   160,   153,    92,    93,
     659,   153,   661,   895,   896,   153,   665,   666,   667,   668,
     159,    72,   161,   159,   673,   161,    12,    13,   160,   159,
      81,   161,   159,   159,   161,   161,   153,    88,    89,   160,
     919,    92,    93,     6,   159,   927,   161,   160,   159,   161,
     161,   159,     4,   161,     6,   941,     5,     5,   940,   941,
     159,   159,   161,   161,   155,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   155,    62,   161,   155,    65,
      66,     5,    68,    69,    70,   159,     6,   161,    74,   159,
     159,   161,   161,   975,   976,   977,   159,   159,   161,   161,
     160,   157,   751,   985,   986,   159,   159,   161,   161,   166,
     161,   993,   109,     6,   171,   101,   102,   103,   175,  1001,
     159,   159,   161,   161,     6,     6,   775,   776,   777,   778,
     159,   159,   161,   161,   155,   159,    72,   161,     4,  1021,
    1022,  1023,   159,     6,   161,    81,   159,   159,   161,   161,
    1032,  1030,    88,    89,   160,  1037,    92,    93,   152,   993,
     139,   140,   141,   142,   143,   144,   145,   146,   147,  1055,
      72,     7,   157,   152,  1056,   161,   159,   161,   161,    81,
     155,   159,   239,   161,   241,     6,    88,    89,  1074,   160,
      92,    93,  1074,   159,     7,   161,  1078,   159,     7,   161,
       7,     7,  1084,  1085,     8,     6,   153,  1089,   153,  1297,
     153,   153,     7,   154,  1096,     6,   160,     7,     6,     4,
     160,   160,  1108,   160,  1106,   161,  1108,   106,   160,   154,
     159,  1112,  1113,   154,     6,   154,   159,   548,  1120,   154,
       4,   159,   159,   156,     6,  1079,     6,     4,  1130,     7,
     109,     7,  1134,     7,     7,  1137,   109,     7,     7,   161,
     109,     7,     7,  1149,     4,     6,   157,  1149,     6,   161,
    1437,   161,   156,  1155,  1156,     7,   333,     7,     7,   336,
    1114,   157,  1116,   160,  1118,     6,   153,  1454,   153,   160,
       6,     4,   154,     7,     6,  1177,  1130,     6,   609,  1133,
    1134,   156,  1390,     6,   155,     6,   140,     7,     7,   620,
      57,     7,     7,     7,     7,   372,  1483,    59,     7,     6,
       4,     7,   154,   154,   154,   154,  1493,  1209,  1495,     7,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     7,  1227,     7,  1229,   152,  1516,
       6,     4,  1001,   153,     6,   160,     7,  1239,     6,  1241,
       7,     7,  1244,     7,   160,     6,     6,  1249,     6,    57,
       6,     6,  1254,     4,     4,     4,     4,   161,   689,     6,
       6,   160,   153,   157,   441,   442,   443,   154,   154,   154,
       7,     6,     6,    65,     6,     6,     6,   160,  1280,   160,
       6,   458,  1283,     6,     5,  1287,     4,  1289,   465,  1291,
       6,     6,   160,     7,     7,     7,   160,     7,     7,  1301,
     155,   160,     6,  1305,   160,     6,   160,   160,   154,   160,
       6,   156,  1314,  1315,     6,   105,     6,   159,     6,  1321,
     157,     6,     4,     6,   109,     6,     6,  1329,     6,     6,
       6,  1333,     6,  1287,     6,  1289,     6,  1291,     5,     7,
       6,     6,     6,     6,     6,  1299,     6,     6,  1302,     6,
       6,     6,     6,     4,   159,    55,     6,  1359,   160,     6,
       6,     6,   793,   794,   157,   796,     6,   798,   799,     5,
     161,   802,   803,     6,     6,  1377,     6,     6,  1380,     6,
     160,  1383,     6,   160,     6,  1387,   161,     7,     6,  1391,
     160,  1393,     6,   104,     6,   160,  1398,   160,   160,  1401,
     107,  1403,   161,     6,   581,     6,   583,     6,     6,     6,
       6,    72,   589,   590,     6,   160,     6,   160,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,  1434,     6,   161,     6,   152,     6,   160,  1393,
       4,     4,   161,   160,   621,   876,   877,   878,     6,  1451,
       6,     6,     6,     6,     6,   886,     6,     6,     6,     6,
       6,   160,   160,     6,     6,   160,   897,     6,     6,     6,
       6,   160,     6,   160,     6,  1244,  1482,     6,  1480,     6,
       6,   160,   659,     6,   661,   160,     6,   160,   665,   666,
     667,   668,     6,     6,     6,     6,   673,     6,   938,  1359,
       3,   945,     3,    -1,   394,  1059,  1512,    -1,    -1,    -1,
      -1,  1280,    -1,    -1,    -1,   946,    -1,    -1,    -1,    -1,
      -1,   952,    -1,    -1,    -1,    -1,    -1,   958,   959,   960,
      -1,    -1,  1301,   964,    -1,    -1,    -1,    -1,   969,   970,
     971,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,   985,    -1,    -1,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,   999,    -1,
      -1,    -1,    -1,    -1,   751,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   775,   776,
     777,   778,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,  1052,  1391,  1054,  1393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,  1099,  1100,
    1101,  1102,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,  1451,    -1,    54,    -1,    -1,    57,    -1,    59,
      12,    13,    -1,    -1,    -1,    -1,    -1,     6,    -1,    69,
      -1,  1132,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    -1,  1143,    83,    -1,    -1,    86,    -1,    -1,  1150,
      -1,    -1,    -1,    -1,    -1,    -1,  1157,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    65,    66,    -1,    68,    69,    70,    -1,
      -1,   121,    74,    -1,    -1,    12,    13,   127,   128,   129,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,   143,   144,   152,    -1,    -1,   148,   101,
     102,   103,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,   161,    -1,  1224,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,  1253,    -1,  1001,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   161,
      -1,    -1,    -1,   152,   101,   102,   103,    -1,  1279,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,  1296,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,   161,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,  1345,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1130,    -1,    -1,    -1,  1134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1400,
      -1,  1402,    -1,   121,    -1,    -1,     6,    -1,    -1,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,     3,     4,   161,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,  1478,    -1,    -1,
      42,    -1,  1229,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,     9,    10,    11,  1244,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,  1280,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,  1301,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   153,    -1,    -1,   156,    -1,   158,    -1,   160,    -1,
     115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,   148,    -1,   150,   151,    -1,   153,    -1,
     155,    -1,   157,   158,  1391,   160,  1393,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,  1434,    -1,    -1,
      -1,    -1,    12,    13,    -1,    51,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,  1451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      86,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    66,    -1,    68,    69,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,    -1,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   153,    -1,     3,
       4,     5,   158,    -1,   160,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,   161,    -1,    -1,    12,    13,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    -1,    -1,    65,    66,    -1,
      68,    69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,   153,
      -1,     3,     4,     5,   158,    -1,   160,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,   161,    -1,    -1,    12,    13,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   153,    -1,     3,     4,    -1,   158,    -1,   160,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,   161,    -1,    -1,    12,    13,
      -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    86,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      74,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,   153,    -1,     3,     4,    -1,   158,    -1,
     160,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     6,   121,    -1,    -1,   152,    -1,    -1,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,   153,    -1,     3,     4,    -1,
     158,    -1,   160,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,     6,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   153,    -1,     3,
       4,    -1,   158,    -1,   160,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     6,   121,    -1,    -1,
     152,    -1,    -1,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,   153,
      -1,     3,     4,    -1,   158,    -1,   160,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   153,    -1,     3,     4,     5,   158,    -1,   160,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    45,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,     3,     4,    45,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,   121,   122,   123,    -1,    42,    -1,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,    -1,   160,   121,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,   156,
      -1,   158,    -1,   160,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,     3,     4,
      -1,    -1,    -1,    42,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,     3,     4,    -1,    -1,    -1,    42,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,   153,    -1,   121,    -1,    -1,   158,
      -1,   160,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,   153,    -1,
     121,    -1,    -1,   158,    -1,   160,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,   153,    -1,     3,     4,    -1,   158,    -1,   160,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    -1,     3,     4,    83,    -1,    -1,    86,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    42,   121,    -1,    -1,    -1,    -1,    -1,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   148,
       3,     4,     5,    -1,   153,    -1,     9,    10,    11,   158,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,    -1,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,     6,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,     7,     8,    -1,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     7,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,   127,   128,   129,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,    -1,    -1,   148,     8,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,     8,    -1,    -1,    -1,   152,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     8,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     8,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    72,    -1,    -1,    -1,   152,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,     0,     1,    -1,   152,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    36,    37,   152,    -1,    -1,    -1,    -1,    43,
      44,    -1,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,     4,    90,    91,    -1,    -1,
      -1,    95,    -1,    12,    13,    -1,   100,   101,   102,   103,
      -1,    -1,   106,    -1,   108,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    36,    37,    -1,
     124,   125,   126,    -1,    43,    44,    -1,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    12,
      13,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,   106,    -1,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,   125,   126,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      -1,    -1,    65,    66,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   101,   102,
     103,   159,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,   161,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   156,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   156,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   156,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   156,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   156,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,   156,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
     156,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,   156,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
     154,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,   154,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
     154,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,   154,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
     154,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,   154,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
     154,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,   154,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,   154,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
     154,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
      -1,   154,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
     152,    -1,   154,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,   152,    -1,   154,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,    -1,   154,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,    -1,   152,    -1,   154,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,   152
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   164,   165,     6,     0,     4,    12,    13,    36,
      37,    43,    44,    46,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    90,    91,    95,   100,   101,   102,   103,   106,
     108,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   124,   125,   126,   166,   168,   169,   187,   200,
     205,   208,   209,   210,   211,   212,   213,   214,   234,   235,
     236,   237,   238,   239,     3,     4,     5,     7,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    38,    39,    40,    41,    42,    45,   115,   121,
     122,   123,   127,   128,   129,   130,   131,   132,   133,   143,
     144,   148,   150,   151,   153,   155,   157,   158,   160,   185,
     186,   240,   241,   253,    13,    57,   153,   153,     6,   160,
       6,     6,     6,     6,   155,   153,   160,   153,   153,     4,
     153,   160,   153,   153,     4,   160,   153,   153,    61,    57,
      57,     6,    57,    57,    54,    57,    59,    59,    51,    54,
      57,    59,    54,    57,    59,    54,    57,   153,    54,   160,
     143,   144,   153,   160,   242,   243,   242,   160,    51,    54,
      57,   160,   242,     4,    51,    55,    65,    57,    59,    57,
      54,     4,   115,   160,     4,     6,    51,    54,    57,     4,
       4,     4,     5,    35,    51,    54,    57,    59,    69,   144,
     153,   160,   205,   214,   240,   245,   246,   247,     4,   153,
     153,   153,     4,   160,   249,     4,   153,   153,     6,     6,
     155,     4,     4,     5,   160,     5,   160,     6,   153,   160,
       4,   155,   157,   162,   186,   160,     5,   253,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   153,   153,   153,   153,     7,   153,   153,   153,     4,
     240,   240,   240,   160,   240,   156,   160,   240,     4,   106,
     107,     4,     4,   205,   206,   207,   245,     6,     6,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   152,     6,     6,   240,     5,     5,   240,
     189,   240,   144,   240,   247,   248,   240,   240,   153,   240,
     248,   240,   240,   153,   248,   240,   240,   245,   153,   160,
     153,   153,   246,   246,   246,   153,   201,   202,   203,   204,
     153,   153,   153,   245,   240,     4,   245,   242,   242,   242,
     240,   240,   143,   144,   160,   160,   242,   160,   160,   160,
     143,   144,   153,   207,   242,   160,   153,   160,   153,   153,
     153,   246,   246,   245,   153,     4,     6,   155,   155,   207,
       6,   160,   160,   160,   155,   155,   153,   155,   155,     5,
     160,     5,     5,     5,    51,    54,    57,    59,   160,   240,
     247,   240,   161,   248,     8,   145,     6,     6,   240,   240,
     240,   157,   240,   160,   109,   240,   240,   240,     6,     6,
     207,     6,   207,   245,   245,   155,   240,     4,   160,   170,
       6,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,     4,   252,   253,   252,   252,   252,   252,
     240,   252,   252,   252,   155,   248,   154,     7,   185,   248,
     156,     7,   185,   186,   157,     7,   155,   161,    51,    54,
      57,    59,   200,     6,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,     6,
     154,   159,   154,   159,   159,   156,   159,   188,   154,   145,
     159,   161,   154,   154,   240,   154,   161,   154,   154,   240,
     161,   154,   154,     7,   240,   240,   240,   240,     7,     7,
     232,   232,   240,   153,   153,   153,   153,   240,   240,   240,
       7,   160,   154,     6,   159,   159,   159,   242,   242,   206,
     206,   159,   240,   240,   240,   240,   218,   159,   207,   240,
     240,   240,   240,   240,     7,   233,     6,     7,   240,     6,
     240,   240,   161,   248,   248,   248,   240,   240,   154,   160,
     156,   160,   240,     4,   240,   160,   160,   160,   160,   248,
     154,   161,   240,   160,   240,   247,   154,   154,   154,   106,
     159,   207,   160,     8,   154,   156,   161,   161,   154,   159,
     161,   240,   156,   186,   240,     4,    96,    97,    98,    99,
     161,   173,   177,   180,   182,   183,   154,   156,   154,   156,
     154,   156,   154,   156,   154,   156,   154,   156,   154,   156,
     154,   156,   154,   156,   154,   156,   154,   156,   159,   159,
     154,   156,   154,   156,   154,   156,   154,   156,   154,   156,
     154,   156,   159,   159,   159,   159,   159,   159,   155,   157,
     154,   159,   159,   154,   154,   159,     6,   159,   154,   159,
     161,   185,   245,   161,   157,   185,   186,   253,   240,     6,
       4,     4,   160,   250,   156,   160,   160,   160,   160,     8,
       6,   140,   167,   248,     6,   248,   240,     6,     4,     7,
     240,   247,   109,     7,     7,   154,     7,   109,     7,     7,
     154,   109,     7,     7,   240,   154,   161,   154,   154,   240,
     245,     4,   231,     6,   154,   197,   240,   253,   197,   197,
     197,   154,   154,   154,   245,   248,   157,   242,   240,   240,
     161,   161,   240,   242,   159,   159,   159,    72,    81,    88,
      89,    92,    93,   228,   229,   242,   161,   215,   154,   161,
     154,   154,   154,   240,     6,   240,   154,   156,   156,   161,
     161,   161,   156,   156,   248,   248,   156,   156,   161,   248,
     248,   248,   248,   161,     8,   248,     7,     7,     7,   157,
     240,   161,   240,   240,     7,   157,   160,   245,     6,   156,
     157,   186,   252,   161,   174,   153,   153,   160,   184,     6,
     240,   240,   240,   240,   240,   240,   240,   240,   240,     4,
     248,   252,   252,   240,   252,   154,   240,     6,   156,     4,
     106,   107,   240,     6,     6,     6,     7,   155,   249,   251,
       6,   248,   248,   248,   248,   240,   140,   252,   154,   154,
     159,     7,   242,    57,   245,   245,     7,   245,    57,    59,
     245,   245,     7,    59,   245,   245,     6,     7,     7,     7,
       7,    72,   230,     6,     7,   154,   154,   154,   154,     7,
       7,     7,     6,   161,     4,   159,   159,   159,   161,   161,
     242,   242,   242,     4,     6,   160,   153,     6,    94,     6,
      94,   161,   229,   159,   228,     7,     6,     7,     7,     7,
       6,   160,     6,     6,     6,    57,   240,     6,     6,   161,
     161,   161,   161,   161,   161,   240,   161,   245,   245,   245,
       4,   159,     8,     8,   154,     4,     4,   245,   161,     6,
       4,     6,   153,   240,   240,   244,   245,   160,   154,   156,
     154,   156,   154,   156,   154,   156,   156,   154,   154,   154,
     154,   154,   185,     6,   185,     7,   185,   186,   157,     7,
       6,   249,   240,   159,   161,   161,   161,   161,   161,     6,
       6,   167,     6,   240,   160,   240,   253,     6,   160,    65,
     199,   199,   245,     6,   160,   160,     6,     6,   245,   160,
       6,     6,     5,   245,   245,   245,     4,     6,   245,     7,
       7,     7,     7,   245,   245,   245,     7,     6,     7,   240,
     240,   240,   160,   160,   159,   161,   159,   161,   159,   161,
     155,   240,   245,   240,     6,     6,   240,   242,   161,     5,
     160,   245,   160,   160,   160,   245,   248,   160,     6,   154,
     156,     6,     6,   105,   240,   240,   240,     6,     6,     7,
     159,     6,   186,   171,   240,   159,   159,   159,   161,   172,
     240,   157,   245,   245,   253,   240,     6,     4,   250,     6,
     156,   249,     6,     6,     6,     6,   252,   159,   240,   253,
     240,   242,     6,     6,     6,   240,   240,     6,   240,     5,
       6,     6,   109,   198,   240,     6,   245,   245,   245,   245,
       6,     4,     6,     6,   240,   240,   253,   161,   154,   159,
     161,   206,   206,   242,     6,   219,   242,     6,   220,   242,
       6,   221,   240,   161,   159,   154,   161,   159,     6,   144,
     242,     6,   244,   242,   242,     6,   161,   240,   245,   159,
     161,     8,   161,   154,   160,   240,   253,   245,   154,   159,
     240,   240,   245,   160,   159,   161,     4,     6,     6,     6,
       6,     7,     6,   157,     6,   240,   190,   191,   161,   161,
     161,   161,     5,    55,     6,     6,     6,     6,     6,   160,
     160,     6,     6,   160,   240,   161,   161,   159,   160,   159,
     160,   159,   160,   156,     6,   245,     7,   160,   240,   159,
     161,   159,   159,     6,   161,   104,   240,   240,   248,     6,
       6,   161,   175,   240,   159,   159,   244,   240,     6,   249,
     107,   159,   193,   195,     6,     6,     6,     6,     6,   160,
     244,   248,   206,   159,   161,   240,   242,   228,   240,   242,
     228,   240,   242,   228,     6,   159,   161,   245,   207,   161,
     242,     6,   248,   242,   240,   161,   161,   161,     6,   160,
     240,   240,   161,     6,   240,   159,   161,   194,   159,   161,
     196,   240,   161,   161,   161,   240,   161,   159,   161,   161,
     159,   161,   161,   159,   161,   245,     6,    72,   161,   216,
     160,   159,   161,   159,     6,     6,   172,   154,   159,     6,
     160,   159,     4,     4,   161,     6,     6,   161,     6,   222,
     240,     6,     6,   223,   240,     6,     6,   224,   240,     6,
     161,   240,   228,   207,   248,     6,   242,   248,   161,   178,
     240,   244,   240,     5,   160,   245,     5,   160,   240,   160,
     161,   160,   161,   160,   161,     6,     6,   161,   161,   217,
     161,   159,   161,     6,   160,   154,   161,   161,   192,   240,
     252,   254,   228,     6,   225,   228,     6,   226,   228,     6,
     227,   228,     6,   248,     6,   176,   252,   181,   160,     6,
     159,   161,     7,   159,   161,   161,   160,   161,   160,   161,
     160,   161,   161,   159,   161,   160,   244,   240,   253,   252,
       6,   228,     6,   228,     6,   228,     6,   252,     6,   179,
     252,   161,     7,   161,   161,   161,   159,   161,     6,   253,
       6,     6,     6,   252,     6
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
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 917 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
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

  case 281:

/* Line 1464 of yacc.c  */
#line 3730 "Gmsh.y"
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

  case 282:

/* Line 1464 of yacc.c  */
#line 3755 "Gmsh.y"
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

  case 283:

/* Line 1464 of yacc.c  */
#line 3783 "Gmsh.y"
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

  case 284:

/* Line 1464 of yacc.c  */
#line 3829 "Gmsh.y"
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

  case 285:

/* Line 1464 of yacc.c  */
#line 3852 "Gmsh.y"
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

  case 286:

/* Line 1464 of yacc.c  */
#line 3875 "Gmsh.y"
    {
    ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3878 "Gmsh.y"
    {
    ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3887 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3891 "Gmsh.y"
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

  case 290:

/* Line 1464 of yacc.c  */
#line 3901 "Gmsh.y"
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

  case 291:

/* Line 1464 of yacc.c  */
#line 3935 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3936 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3937 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3942 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3948 "Gmsh.y"
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

  case 296:

/* Line 1464 of yacc.c  */
#line 3960 "Gmsh.y"
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

  case 297:

/* Line 1464 of yacc.c  */
#line 3978 "Gmsh.y"
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

  case 298:

/* Line 1464 of yacc.c  */
#line 4005 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 4006 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 4007 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 4008 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 4009 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 4010 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 4011 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 4012 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 4014 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 4020 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 4021 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 4022 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 4023 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 4024 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 4025 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 4026 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 4028 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 4029 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 4030 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 4031 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 4032 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 4033 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 4034 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 4035 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 4036 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 4037 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 4039 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 4040 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 4041 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 4042 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 4044 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 4045 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 4046 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 4047 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 4049 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 4051 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 4054 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 4055 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 4056 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 4057 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 4059 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 4060 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 4061 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 4062 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 4063 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 4064 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 4065 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 4066 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 4067 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 4068 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 4070 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 4071 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 4072 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 4073 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 4074 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 4083 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4084 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4085 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4086 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4087 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4088 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4089 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4094 "Gmsh.y"
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

  case 368:

/* Line 1464 of yacc.c  */
#line 4115 "Gmsh.y"
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

  case 369:

/* Line 1464 of yacc.c  */
#line 4134 "Gmsh.y"
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

  case 370:

/* Line 1464 of yacc.c  */
#line 4152 "Gmsh.y"
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

  case 371:

/* Line 1464 of yacc.c  */
#line 4164 "Gmsh.y"
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

  case 372:

/* Line 1464 of yacc.c  */
#line 4181 "Gmsh.y"
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

  case 373:

/* Line 1464 of yacc.c  */
#line 4202 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4207 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4212 "Gmsh.y"
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

  case 376:

/* Line 1464 of yacc.c  */
#line 4222 "Gmsh.y"
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

  case 377:

/* Line 1464 of yacc.c  */
#line 4232 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4237 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4249 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4253 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4257 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4261 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4265 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4272 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4276 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4280 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4284 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4291 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4296 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4308 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4312 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4317 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4321 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4329 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4340 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4344 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4356 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4364 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4372 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4379 "Gmsh.y"
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

  case 402:

/* Line 1464 of yacc.c  */
#line 4389 "Gmsh.y"
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

  case 403:

/* Line 1464 of yacc.c  */
#line 4409 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4413 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4417 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4421 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4425 "Gmsh.y"
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

  case 408:

/* Line 1464 of yacc.c  */
#line 4454 "Gmsh.y"
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

  case 409:

/* Line 1464 of yacc.c  */
#line 4483 "Gmsh.y"
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

  case 410:

/* Line 1464 of yacc.c  */
#line 4512 "Gmsh.y"
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

  case 411:

/* Line 1464 of yacc.c  */
#line 4541 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4551 "Gmsh.y"
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

  case 413:

/* Line 1464 of yacc.c  */
#line 4561 "Gmsh.y"
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

  case 414:

/* Line 1464 of yacc.c  */
#line 4574 "Gmsh.y"
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

  case 415:

/* Line 1464 of yacc.c  */
#line 4586 "Gmsh.y"
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

  case 416:

/* Line 1464 of yacc.c  */
#line 4598 "Gmsh.y"
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

  case 417:

/* Line 1464 of yacc.c  */
#line 4617 "Gmsh.y"
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

  case 418:

/* Line 1464 of yacc.c  */
#line 4638 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4643 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4647 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4651 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4663 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4667 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4679 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4686 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 4696 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4700 "Gmsh.y"
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

  case 428:

/* Line 1464 of yacc.c  */
#line 4715 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 4720 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 4727 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4731 "Gmsh.y"
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

  case 432:

/* Line 1464 of yacc.c  */
#line 4744 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4763 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4767 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4775 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4783 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4791 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4799 "Gmsh.y"
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

  case 440:

/* Line 1464 of yacc.c  */
#line 4813 "Gmsh.y"
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

  case 441:

/* Line 1464 of yacc.c  */
#line 4827 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4831 "Gmsh.y"
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

  case 443:

/* Line 1464 of yacc.c  */
#line 4853 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 4858 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10752 "Gmsh.tab.cpp"
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
#line 4861 "Gmsh.y"


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

