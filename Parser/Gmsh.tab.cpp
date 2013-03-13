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
     tGMSH_MAJOR_VERSION = 383,
     tGMSH_MINOR_VERSION = 384,
     tGMSH_PATCH_VERSION = 385,
     tAFFECTDIVIDE = 386,
     tAFFECTTIMES = 387,
     tAFFECTMINUS = 388,
     tAFFECTPLUS = 389,
     tOR = 390,
     tAND = 391,
     tNOTEQUAL = 392,
     tEQUAL = 393,
     tGREATEROREQUAL = 394,
     tLESSOREQUAL = 395,
     UNARYPREC = 396,
     tMINUSMINUS = 397,
     tPLUSPLUS = 398
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
#line 363 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 375 "Gmsh.tab.cpp"

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
#define YYLAST   8028

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  445
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1529

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   398

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   149,     2,   159,     2,   148,     2,     2,
     154,   155,   146,   144,   160,   145,   158,   147,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     140,     2,   141,   135,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   156,     2,   157,   153,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   161,     2,   162,   163,     2,     2,     2,
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
     136,   137,   138,   139,   142,   143,   150,   151,   152
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
    2217,  2219,  2222,  2225,  2229,  2233,  2245,  2255,  2263,  2271,
    2273,  2277,  2279,  2281,  2284,  2288,  2293,  2299,  2301,  2303,
    2306,  2310,  2314,  2320,  2325,  2328,  2331,  2334,  2337,  2343,
    2349,  2355,  2361,  2363,  2365,  2369,  2373,  2378,  2385,  2392,
    2394,  2396,  2400,  2404,  2414,  2422,  2424,  2430,  2434,  2441,
    2443,  2447,  2449,  2451,  2455,  2462,  2464,  2466,  2471,  2478,
    2485,  2490,  2495,  2500,  2507,  2509
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,   166,    -1,     1,     6,    -1,    -1,   166,
     167,    -1,   170,    -1,   169,    -1,   188,    -1,   201,    -1,
     206,    -1,   210,    -1,   211,    -1,   212,    -1,   215,    -1,
     235,    -1,   236,    -1,   237,    -1,   238,    -1,   214,    -1,
     213,    -1,   209,    -1,   240,    -1,   141,    -1,   141,   141,
      -1,    36,   154,     5,   155,     6,    -1,    37,   154,     5,
     155,     6,    -1,    36,   154,     5,   155,   168,   253,     6,
      -1,    36,   154,     5,   160,   249,   155,     6,    -1,    37,
     154,     5,   160,   249,   155,     6,    -1,    36,   154,     5,
     160,   249,   155,   168,   253,     6,    -1,     4,     5,   161,
     171,   162,     6,    -1,    91,     4,   156,   241,   157,     6,
      -1,    92,     4,   156,   241,   157,     6,    -1,    -1,   171,
     174,    -1,   171,   178,    -1,   171,   181,    -1,   171,   183,
      -1,   171,   184,    -1,   241,    -1,   172,   160,   241,    -1,
     241,    -1,   173,   160,   241,    -1,    -1,    -1,     4,   175,
     154,   172,   155,   176,   161,   173,   162,     6,    -1,   253,
      -1,   177,   160,   253,    -1,    -1,    97,   154,   241,   160,
     241,   160,   241,   155,   179,   161,   177,   162,     6,    -1,
     253,    -1,   180,   160,   253,    -1,    -1,    98,   154,   241,
     160,   241,   160,   241,   160,   241,   155,   182,   161,   180,
     162,     6,    -1,    99,   161,   245,   162,   161,   245,   162,
       6,    -1,    99,   161,   245,   162,   161,   245,   162,   161,
     245,   162,   161,   245,   162,     6,    -1,    -1,   100,   185,
     161,   173,   162,     6,    -1,     7,    -1,   134,    -1,   133,
      -1,   132,    -1,   131,    -1,   152,    -1,   151,    -1,    51,
     156,   190,   157,     6,    -1,     4,   186,   246,     6,    -1,
       4,   156,   157,   186,   246,     6,    -1,     4,   156,   241,
     157,   186,   241,     6,    -1,     4,   154,   241,   155,   186,
     241,     6,    -1,     4,   156,   161,   249,   162,   157,   186,
     246,     6,    -1,     4,   154,   161,   249,   162,   155,   186,
     246,     6,    -1,     4,   187,     6,    -1,     4,   156,   241,
     157,   187,     6,    -1,     4,     7,   254,     6,    -1,     4,
     158,     4,     7,   254,     6,    -1,     4,   156,   241,   157,
     158,     4,     7,   254,     6,    -1,     4,   158,     4,   186,
     241,     6,    -1,     4,   156,   241,   157,   158,     4,   186,
     241,     6,    -1,     4,   158,     4,   187,     6,    -1,     4,
     156,   241,   157,   158,     4,   187,     6,    -1,     4,   158,
     107,   158,     4,     7,   250,     6,    -1,     4,   156,   241,
     157,   158,   107,   158,     4,     7,   250,     6,    -1,     4,
     158,   108,     7,   251,     6,    -1,     4,   156,   241,   157,
     158,   108,     7,   251,     6,    -1,     4,   116,     7,   241,
       6,    -1,   116,   156,   241,   157,     7,     4,     6,    -1,
     116,   156,   241,   157,   158,     4,     7,   241,     6,    -1,
     116,   156,   241,   157,   158,     4,     7,   254,     6,    -1,
     116,   156,   241,   157,   158,     4,     7,   161,   249,   162,
       6,    -1,   116,   156,   241,   157,   158,     4,     6,    -1,
      74,   154,     4,   155,   158,     4,     7,   241,     6,    -1,
      74,   154,     4,   155,   158,     4,     7,   254,     6,    -1,
      -1,   160,    -1,    -1,   190,   189,     4,    -1,   190,   189,
       4,     7,   241,    -1,    -1,   190,   189,     4,     7,   161,
     241,   191,   194,   162,    -1,   190,   189,     4,     7,   254,
      -1,    -1,   190,   189,     4,     7,   161,   254,   192,   196,
     162,    -1,   241,     7,   254,    -1,   193,   160,   241,     7,
     254,    -1,    -1,   194,   195,    -1,   160,     4,   246,    -1,
     160,     4,   161,   193,   162,    -1,   160,     4,     5,    -1,
      -1,   196,   197,    -1,   160,     4,   241,    -1,   160,     4,
       5,    -1,   160,     4,   161,   255,   162,    -1,   241,    -1,
     254,    -1,    -1,   110,    56,   161,   241,   162,    -1,    -1,
      66,   243,    -1,    52,   154,   241,   155,     7,   243,     6,
      -1,    -1,    70,    52,   202,   154,   198,   155,     7,   246,
       6,    -1,    61,    62,   246,     7,   241,     6,    -1,    55,
     154,   241,   155,     7,   246,     6,    -1,    75,    55,   246,
       6,    -1,    59,   154,   241,   155,     7,   246,     6,    -1,
      53,   154,   241,   155,     7,   246,   200,     6,    -1,    54,
     154,   241,   155,     7,   246,   200,     6,    -1,   102,   154,
     241,   155,     7,   246,     6,    -1,   103,   154,   241,   155,
       7,   246,     6,    -1,   104,   154,   241,   155,     7,   246,
     106,   246,   105,   241,     6,    -1,    55,     4,   154,   241,
     155,     7,   246,     6,    -1,    71,    55,   154,   241,   155,
       7,   246,     6,    -1,    -1,    70,    55,   203,   154,   198,
     155,     7,   246,     6,    -1,    66,    58,   154,   241,   155,
       7,   246,     6,    -1,    67,    58,   154,   241,   155,     7,
     246,   199,     6,    -1,    12,    13,     6,    -1,    13,    58,
     241,     6,    -1,    63,    58,   154,   241,   155,     7,     5,
       5,     5,     6,    -1,    56,   154,   241,   155,     7,   246,
       6,    -1,    57,   154,   241,   155,     7,   246,     6,    -1,
      58,     4,   154,   241,   155,     7,   246,     6,    -1,    71,
      58,   154,   241,   155,     7,   246,     6,    -1,    71,    58,
     154,   241,   155,     7,   246,     4,   161,   245,   162,     6,
      -1,    -1,    70,    58,   204,   154,   198,   155,     7,   246,
       6,    -1,    69,    60,   154,   241,   155,     7,   246,     6,
      -1,    60,   154,   241,   155,     7,   246,     6,    -1,    71,
      60,   154,   241,   155,     7,   246,     6,    -1,    -1,    70,
      60,   205,   154,   198,   155,     7,   246,     6,    -1,    77,
     243,   161,   207,   162,    -1,    76,   161,   243,   160,   243,
     160,   241,   162,   161,   207,   162,    -1,    78,   243,   161,
     207,   162,    -1,    79,   161,   243,   160,   241,   162,   161,
     207,   162,    -1,    79,   161,   243,   160,   243,   162,   161,
     207,   162,    -1,     4,   161,   207,   162,    -1,    87,    55,
     161,   249,   162,    58,   161,   241,   162,    -1,    84,    55,
     154,   241,   155,   161,   249,   162,     6,    -1,   208,    -1,
     206,    -1,    -1,   208,   201,    -1,   208,    52,   161,   249,
     162,     6,    -1,   208,    55,   161,   249,   162,     6,    -1,
     208,    58,   161,   249,   162,     6,    -1,   208,    60,   161,
     249,   162,     6,    -1,    81,    66,   154,   241,   155,     7,
     246,     6,    -1,    81,    52,   154,   241,   155,     7,   161,
     245,   162,     6,    -1,    81,    66,   154,   241,   155,     7,
     161,   243,   160,   243,   160,   249,   162,     6,    -1,    81,
      66,   154,   241,   155,     7,   161,   243,   160,   243,   160,
     243,   160,   249,   162,     6,    -1,    81,    56,   154,   241,
     155,     7,   161,   243,   160,   249,   162,     6,    -1,    81,
       4,   154,   241,   155,     7,   246,     6,    -1,    81,     4,
     154,   241,   155,     7,     5,     6,    -1,    81,     4,   161,
     241,   162,     6,    -1,    81,     4,   154,   241,   155,     7,
     161,   243,   160,   243,   160,   249,   162,     6,    -1,    85,
     161,   208,   162,    -1,    85,   116,   156,   241,   157,     6,
      -1,    85,     4,   156,   241,   157,     6,    -1,    85,     4,
       6,    -1,    85,     4,     4,     6,    -1,   107,   250,   161,
     208,   162,    -1,   120,     5,     6,    -1,   121,     5,     6,
      -1,   120,   161,   208,   162,    -1,   121,   161,   208,   162,
      -1,     4,   254,     6,    -1,     4,     4,   156,   241,   157,
     253,     6,    -1,     4,     4,     4,   156,   241,   157,     6,
      -1,     4,   241,     6,    -1,    74,   154,     4,   155,   158,
       4,     6,    -1,   101,     4,     6,    -1,   114,     6,    -1,
     115,     6,    -1,    47,     6,    -1,    44,     6,    -1,    44,
     161,   241,   160,   241,   160,   241,   160,   241,   160,   241,
     160,   241,   162,     6,    -1,    45,     6,    -1,    48,     6,
      -1,    49,     6,    -1,    65,     6,    -1,   109,   154,   241,
       8,   241,   155,    -1,   109,   154,   241,     8,   241,     8,
     241,   155,    -1,   109,     4,   110,   161,   241,     8,   241,
     162,    -1,   109,     4,   110,   161,   241,     8,   241,     8,
     241,   162,    -1,   111,    -1,   119,     4,    -1,   117,    -1,
     118,     4,     6,    -1,   112,   154,   241,   155,    -1,   113,
      -1,    80,   243,   161,   208,   162,    -1,    80,   161,   243,
     160,   243,   160,   241,   162,   161,   208,   162,    -1,    80,
     161,   243,   160,   243,   160,   243,   160,   241,   162,   161,
     208,   162,    -1,    -1,    80,   243,   161,   208,   216,   229,
     162,    -1,    -1,    80,   161,   243,   160,   243,   160,   241,
     162,   161,   208,   217,   229,   162,    -1,    -1,    80,   161,
     243,   160,   243,   160,   243,   160,   241,   162,   161,   208,
     218,   229,   162,    -1,    -1,    80,   161,   208,   219,   229,
     162,    -1,    80,    52,   161,   241,   160,   243,   162,     6,
      -1,    80,    55,   161,   241,   160,   243,   162,     6,    -1,
      80,    58,   161,   241,   160,   243,   162,     6,    -1,    80,
      52,   161,   241,   160,   243,   160,   243,   160,   241,   162,
       6,    -1,    80,    55,   161,   241,   160,   243,   160,   243,
     160,   241,   162,     6,    -1,    80,    58,   161,   241,   160,
     243,   160,   243,   160,   241,   162,     6,    -1,    80,    52,
     161,   241,   160,   243,   160,   243,   160,   243,   160,   241,
     162,     6,    -1,    80,    55,   161,   241,   160,   243,   160,
     243,   160,   243,   160,   241,   162,     6,    -1,    80,    58,
     161,   241,   160,   243,   160,   243,   160,   243,   160,   241,
     162,     6,    -1,    -1,    80,    52,   161,   241,   160,   243,
     162,   220,   161,   229,   162,     6,    -1,    -1,    80,    55,
     161,   241,   160,   243,   162,   221,   161,   229,   162,     6,
      -1,    -1,    80,    58,   161,   241,   160,   243,   162,   222,
     161,   229,   162,     6,    -1,    -1,    80,    52,   161,   241,
     160,   243,   160,   243,   160,   241,   162,   223,   161,   229,
     162,     6,    -1,    -1,    80,    55,   161,   241,   160,   243,
     160,   243,   160,   241,   162,   224,   161,   229,   162,     6,
      -1,    -1,    80,    58,   161,   241,   160,   243,   160,   243,
     160,   241,   162,   225,   161,   229,   162,     6,    -1,    -1,
      80,    52,   161,   241,   160,   243,   160,   243,   160,   243,
     160,   241,   162,   226,   161,   229,   162,     6,    -1,    -1,
      80,    55,   161,   241,   160,   243,   160,   243,   160,   243,
     160,   241,   162,   227,   161,   229,   162,     6,    -1,    -1,
      80,    58,   161,   241,   160,   243,   160,   243,   160,   243,
     160,   241,   162,   228,   161,   229,   162,     6,    -1,   230,
      -1,   229,   230,    -1,    89,   161,   241,   162,     6,    -1,
      89,   161,   246,   160,   246,   162,     6,    -1,    89,   161,
     246,   160,   246,   160,   246,   162,     6,    -1,    82,     6,
      -1,    93,     6,    -1,    93,    95,     6,    -1,    94,     6,
      -1,    94,    95,     6,    -1,    90,   154,   241,   155,     7,
     246,    73,   241,     6,    -1,    73,     4,   156,   241,   157,
       6,    -1,    -1,    73,     4,   241,    -1,    -1,     4,    -1,
      -1,     7,   246,    -1,    -1,     7,   241,    -1,    68,    55,
     247,     7,   241,   231,     6,    -1,    68,    58,   247,   233,
     232,     6,    -1,    64,    58,   161,   241,   162,     7,   246,
       6,    -1,    68,    60,   247,   233,     6,    -1,    96,   247,
       6,    -1,    88,    58,   161,   249,   162,   241,     6,    -1,
      82,    58,   247,   234,     6,    -1,    82,    60,   247,     6,
      -1,    83,    58,   246,     7,   241,     6,    -1,    72,    55,
     246,     7,   246,     6,    -1,    72,    58,   241,   161,   249,
     162,     7,   241,   161,   249,   162,     6,    -1,    52,   161,
     249,   162,   110,    58,   161,   241,   162,     6,    -1,    55,
     161,   249,   162,   110,    58,   161,   241,   162,     6,    -1,
      55,   161,   249,   162,   110,    60,   161,   241,   162,     6,
      -1,    58,   161,   249,   162,   110,    60,   161,   241,   162,
       6,    -1,    86,     6,    -1,    86,     4,     6,    -1,    86,
      52,   161,   249,   162,     6,    -1,   125,    -1,   126,    -1,
     127,    -1,   239,     6,    -1,   239,   161,   246,   162,     6,
      -1,   239,   161,   246,   160,   246,   162,     6,    -1,   239,
     154,   246,   155,   161,   246,   160,   246,   162,     6,    -1,
     242,    -1,   154,   241,   155,    -1,   145,   241,    -1,   144,
     241,    -1,   149,   241,    -1,   241,   145,   241,    -1,   241,
     144,   241,    -1,   241,   146,   241,    -1,   241,   147,   241,
      -1,   241,   148,   241,    -1,   241,   153,   241,    -1,   241,
     140,   241,    -1,   241,   141,   241,    -1,   241,   143,   241,
      -1,   241,   142,   241,    -1,   241,   139,   241,    -1,   241,
     138,   241,    -1,   241,   137,   241,    -1,   241,   136,   241,
      -1,   241,   135,   241,     8,   241,    -1,    14,   154,   241,
     155,    -1,    15,   154,   241,   155,    -1,    16,   154,   241,
     155,    -1,    17,   154,   241,   155,    -1,    18,   154,   241,
     155,    -1,    19,   154,   241,   155,    -1,    20,   154,   241,
     155,    -1,    21,   154,   241,   155,    -1,    22,   154,   241,
     155,    -1,    24,   154,   241,   155,    -1,    25,   154,   241,
     160,   241,   155,    -1,    26,   154,   241,   155,    -1,    27,
     154,   241,   155,    -1,    28,   154,   241,   155,    -1,    29,
     154,   241,   155,    -1,    30,   154,   241,   155,    -1,    31,
     154,   241,   155,    -1,    32,   154,   241,   160,   241,   155,
      -1,    33,   154,   241,   160,   241,   155,    -1,    34,   154,
     241,   160,   241,   155,    -1,    23,   154,   241,   155,    -1,
      14,   156,   241,   157,    -1,    15,   156,   241,   157,    -1,
      16,   156,   241,   157,    -1,    17,   156,   241,   157,    -1,
      18,   156,   241,   157,    -1,    19,   156,   241,   157,    -1,
      20,   156,   241,   157,    -1,    21,   156,   241,   157,    -1,
      22,   156,   241,   157,    -1,    24,   156,   241,   157,    -1,
      25,   156,   241,   160,   241,   157,    -1,    26,   156,   241,
     157,    -1,    27,   156,   241,   157,    -1,    28,   156,   241,
     157,    -1,    29,   156,   241,   157,    -1,    30,   156,   241,
     157,    -1,    31,   156,   241,   157,    -1,    32,   156,   241,
     160,   241,   157,    -1,    33,   156,   241,   160,   241,   157,
      -1,    34,   156,   241,   160,   241,   157,    -1,    23,   156,
     241,   157,    -1,     3,    -1,     9,    -1,    10,    -1,    11,
      -1,   128,    -1,   129,    -1,   130,    -1,     4,    -1,     4,
     163,   161,   241,   162,    -1,     4,   156,   241,   157,    -1,
     159,     4,   156,   157,    -1,     4,   187,    -1,     4,   156,
     241,   157,   187,    -1,     4,   158,     4,    -1,     4,   156,
     241,   157,   158,     4,    -1,     4,   158,     4,   187,    -1,
       4,   156,   241,   157,   158,     4,   187,    -1,   122,   154,
     253,   160,   241,   155,    -1,    42,   154,   253,   160,   253,
     155,    -1,    43,   154,   255,   155,    -1,   244,    -1,   145,
     243,    -1,   144,   243,    -1,   243,   145,   243,    -1,   243,
     144,   243,    -1,   161,   241,   160,   241,   160,   241,   160,
     241,   160,   241,   162,    -1,   161,   241,   160,   241,   160,
     241,   160,   241,   162,    -1,   161,   241,   160,   241,   160,
     241,   162,    -1,   154,   241,   160,   241,   160,   241,   155,
      -1,   246,    -1,   245,   160,   246,    -1,   241,    -1,   248,
      -1,   161,   162,    -1,   161,   249,   162,    -1,   145,   161,
     249,   162,    -1,   241,   146,   161,   249,   162,    -1,   246,
      -1,     5,    -1,   145,   248,    -1,   241,   146,   248,    -1,
     241,     8,   241,    -1,   241,     8,   241,     8,   241,    -1,
      52,   161,   241,   162,    -1,    52,     5,    -1,    55,     5,
      -1,    58,     5,    -1,    60,     5,    -1,    70,    52,   161,
     249,   162,    -1,    70,    55,   161,   249,   162,    -1,    70,
      58,   161,   249,   162,    -1,    70,    60,   161,   249,   162,
      -1,   206,    -1,   215,    -1,     4,   156,   157,    -1,     4,
     154,   155,    -1,    35,   156,     4,   157,    -1,     4,   156,
     161,   249,   162,   157,    -1,     4,   154,   161,   249,   162,
     155,    -1,   241,    -1,   248,    -1,   249,   160,   241,    -1,
     249,   160,   248,    -1,   161,   241,   160,   241,   160,   241,
     160,   241,   162,    -1,   161,   241,   160,   241,   160,   241,
     162,    -1,     4,    -1,     4,   158,   107,   158,     4,    -1,
     161,   252,   162,    -1,     4,   156,   241,   157,   158,   108,
      -1,   250,    -1,   252,   160,   250,    -1,   254,    -1,     4,
      -1,     4,   158,     4,    -1,     4,   156,   241,   157,   158,
       4,    -1,     5,    -1,    46,    -1,   123,   154,   253,   155,
      -1,   124,   154,   253,   160,   253,   155,    -1,    39,   154,
     253,   160,   253,   155,    -1,    40,   154,   253,   155,    -1,
      41,   154,   253,   155,    -1,    38,   154,   253,   155,    -1,
      38,   154,   253,   160,   249,   155,    -1,   253,    -1,   255,
     160,   253,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   166,   171,   173,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   197,   201,   208,   213,   218,   232,   245,
     258,   286,   300,   311,   326,   331,   332,   333,   334,   335,
     339,   341,   346,   348,   354,   458,   353,   476,   483,   494,
     493,   511,   518,   529,   528,   545,   562,   585,   584,   598,
     599,   600,   601,   602,   606,   607,   613,   615,   677,   707,
     742,   776,   824,   871,   886,   902,   911,   917,   926,   944,
     962,   971,   983,   988,   996,  1016,  1039,  1050,  1058,  1080,
    1103,  1129,  1150,  1162,  1176,  1176,  1178,  1180,  1191,  1203,
    1202,  1214,  1226,  1225,  1240,  1246,  1253,  1254,  1258,  1269,
    1284,  1294,  1295,  1300,  1308,  1317,  1336,  1340,  1351,  1354,
    1367,  1370,  1380,  1404,  1403,  1423,  1445,  1463,  1484,  1502,
    1532,  1562,  1580,  1598,  1624,  1642,  1661,  1660,  1683,  1701,
    1740,  1746,  1752,  1759,  1784,  1809,  1826,  1843,  1875,  1874,
    1898,  1916,  1933,  1950,  1949,  1975,  1980,  1985,  1990,  1995,
    2000,  2023,  2029,  2040,  2041,  2046,  2049,  2053,  2076,  2099,
    2122,  2150,  2171,  2194,  2215,  2237,  2257,  2369,  2388,  2426,
    2535,  2544,  2550,  2565,  2593,  2610,  2624,  2630,  2636,  2645,
    2659,  2704,  2721,  2736,  2755,  2767,  2791,  2795,  2800,  2807,
    2813,  2818,  2824,  2828,  2832,  2842,  2859,  2876,  2897,  2918,
    2953,  2961,  2967,  2974,  2978,  2987,  2995,  3003,  3012,  3011,
    3025,  3024,  3038,  3037,  3051,  3050,  3063,  3070,  3077,  3084,
    3091,  3098,  3105,  3112,  3119,  3127,  3126,  3139,  3138,  3151,
    3150,  3163,  3162,  3175,  3174,  3187,  3186,  3199,  3198,  3211,
    3210,  3223,  3222,  3238,  3241,  3247,  3256,  3276,  3299,  3303,
    3307,  3311,  3315,  3319,  3338,  3351,  3354,  3370,  3373,  3386,
    3389,  3395,  3398,  3405,  3461,  3531,  3536,  3603,  3639,  3648,
    3691,  3730,  3755,  3782,  3829,  3852,  3875,  3878,  3887,  3891,
    3901,  3936,  3937,  3938,  3942,  3948,  3960,  3978,  4006,  4007,
    4008,  4009,  4010,  4011,  4012,  4013,  4014,  4021,  4022,  4023,
    4024,  4025,  4026,  4027,  4028,  4029,  4030,  4031,  4032,  4033,
    4034,  4035,  4036,  4037,  4038,  4039,  4040,  4041,  4042,  4043,
    4044,  4045,  4046,  4047,  4048,  4049,  4050,  4051,  4052,  4055,
    4056,  4057,  4058,  4059,  4060,  4061,  4062,  4063,  4064,  4065,
    4066,  4067,  4068,  4069,  4070,  4071,  4072,  4073,  4074,  4075,
    4084,  4085,  4086,  4087,  4088,  4089,  4090,  4094,  4115,  4134,
    4152,  4164,  4181,  4202,  4207,  4212,  4222,  4232,  4237,  4246,
    4273,  4277,  4281,  4285,  4289,  4296,  4300,  4304,  4308,  4315,
    4320,  4327,  4332,  4336,  4341,  4345,  4353,  4364,  4368,  4380,
    4388,  4396,  4403,  4413,  4433,  4437,  4441,  4445,  4449,  4478,
    4507,  4536,  4565,  4575,  4585,  4598,  4610,  4622,  4641,  4662,
    4667,  4671,  4675,  4687,  4691,  4703,  4710,  4720,  4724,  4739,
    4744,  4751,  4755,  4768,  4776,  4787,  4791,  4799,  4807,  4815,
    4823,  4837,  4851,  4855,  4877,  4882
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
     385,   386,   387,   388,   389,    63,   390,   391,   392,   393,
      60,    62,   394,   395,    43,    45,    42,    47,    37,    33,
     396,   397,   398,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   164,   165,   165,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   168,   168,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   171,   171,   171,   171,   171,   171,
     172,   172,   173,   173,   175,   176,   174,   177,   177,   179,
     178,   180,   180,   182,   181,   183,   183,   185,   184,   186,
     186,   186,   186,   186,   187,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   189,   190,   190,   190,   191,
     190,   190,   192,   190,   193,   193,   194,   194,   195,   195,
     195,   196,   196,   197,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   202,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   203,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   204,   201,
     201,   201,   201,   205,   201,   206,   206,   206,   206,   206,
     206,   206,   206,   207,   207,   208,   208,   208,   208,   208,
     208,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     210,   210,   210,   210,   210,   211,   212,   212,   212,   212,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   215,   215,   215,   216,   215,
     217,   215,   218,   215,   219,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   220,   215,   221,   215,   222,
     215,   223,   215,   224,   215,   225,   215,   226,   215,   227,
     215,   228,   215,   229,   229,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   236,   236,   237,   237,   237,   237,   238,   238,
     238,   239,   239,   239,   240,   240,   240,   240,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     243,   243,   243,   243,   243,   244,   244,   244,   244,   245,
     245,   246,   246,   246,   246,   246,   246,   247,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   249,
     249,   249,   249,   250,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   255,   255
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
       4,     2,     5,     3,     6,     4,     7,     6,     6,     4,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     1,     1,     2,
       3,     3,     5,     4,     2,     2,     2,     2,     5,     5,
       5,     5,     1,     1,     3,     3,     4,     6,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     3,     6,     1,     1,     4,     6,     6,
       4,     4,     4,     6,     1,     3
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
      17,    18,     0,    22,   360,   367,   435,    59,   361,   362,
     363,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   436,     0,
       0,     0,     0,   364,   365,   366,    63,    62,    61,    60,
       0,     0,     0,    65,    64,     0,     0,     0,     0,   165,
       0,     0,     0,   298,     0,     0,     0,     0,     0,   199,
       0,   201,   198,   202,   203,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   204,     0,     0,     0,     0,     0,     0,   123,
     136,   148,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,   288,     0,     0,     0,
       0,     0,   367,   398,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   412,   413,   391,   397,     0,   392,     0,
       0,     0,     0,   425,     0,     0,     0,     0,     0,   196,
     197,     0,     0,   210,     0,   165,     0,   165,   294,     0,
       0,     0,     0,     0,     0,   371,    34,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   301,   300,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,   163,     0,    73,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   140,     0,     0,
       0,     0,    94,     0,     0,   419,   420,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,   381,     0,     0,     0,     0,   165,   165,     0,     0,
       0,     0,     0,     0,     0,   224,     0,   165,     0,     0,
       0,     0,     0,   271,     0,     0,     0,     0,   183,     0,
       0,     0,   289,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,   405,   406,   407,     0,     0,     0,     0,
       0,   300,   399,     0,   393,     0,     0,     0,   277,   195,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
     212,   186,     0,   187,     0,     0,     0,     0,     0,   373,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   432,     0,   431,     0,     0,
       0,     0,   444,     0,     0,     0,     0,     0,     0,     0,
     299,    59,     0,     0,     0,    59,     0,     0,     0,     0,
       0,   160,     0,     0,     0,     0,   166,    67,     0,   316,
     315,   314,   313,   309,   310,   312,   311,   304,   303,   305,
     306,   307,   308,   141,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   384,   383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
     280,     0,     0,   184,     0,     0,   180,     0,     0,     0,
       0,     0,   415,     0,   414,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,   394,   401,     0,   305,   400,
       0,     0,     0,     0,     0,     0,     0,     0,   213,     0,
     188,   189,     0,     0,     0,     0,   369,   375,     0,    44,
       0,     0,     0,    57,     0,    35,    36,    37,    38,    39,
     318,   339,   319,   340,   320,   341,   321,   342,   322,   343,
     323,   344,   324,   345,   325,   346,   326,   347,   338,   359,
     327,   348,     0,     0,   329,   350,   330,   351,   331,   352,
     332,   353,   333,   354,   334,   355,     0,     0,     0,     0,
       0,     0,     0,     0,   442,     0,     0,   440,   441,     0,
     379,     0,    86,     0,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
     370,     0,     0,     0,     0,     0,    25,    23,     0,     0,
      26,     0,     0,    66,    97,     0,   421,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   270,   268,     0,   276,
       0,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,   215,     0,     0,     0,     0,     0,     0,   272,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   369,   416,   403,     0,     0,     0,     0,   395,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,     0,     0,     0,   295,     0,     0,   372,     0,   368,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,     0,   445,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
      74,    76,    78,     0,     0,   429,     0,    84,     0,     0,
       0,     0,   317,    24,     0,     0,     0,     0,     0,     0,
       0,   120,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
     274,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,     0,   259,     0,   261,     0,   225,   254,
       0,     0,     0,   178,     0,     0,     0,   281,     0,   182,
     181,   290,     0,     0,    32,    33,     0,     0,   408,   409,
     410,   411,   402,   396,     0,     0,     0,   426,     0,     0,
       0,   205,     0,     0,     0,     0,   192,   374,   191,     0,
       0,     0,     0,   389,     0,   328,   349,   335,   356,   336,
     357,   337,   358,     0,   443,   439,   378,   377,   438,     0,
      70,     0,    59,     0,     0,     0,     0,    69,     0,     0,
       0,   427,     0,     0,     0,     0,    27,    28,     0,    29,
       0,     0,    98,   101,   122,     0,     0,     0,     0,     0,
     126,     0,     0,   143,   144,     0,     0,   128,   151,     0,
       0,     0,   118,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,   165,
     165,     0,   235,     0,   237,     0,   239,     0,   391,     0,
       0,   260,   262,     0,     0,   219,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   418,   417,   131,   132,
       0,     0,     0,     0,    87,    91,     0,     0,   296,   376,
       0,    40,     0,     0,     0,     0,     0,    42,     0,     0,
       0,     0,     0,    81,     0,     0,    82,     0,   430,   167,
     168,   169,   170,     0,     0,    99,   102,     0,   121,   129,
     130,   134,     0,     0,   145,     0,     0,   275,   138,     0,
       0,   266,   150,     0,     0,     0,     0,   135,     0,   146,
     152,     0,     0,     0,     0,   388,     0,   387,     0,     0,
       0,   226,     0,     0,   227,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,   176,     0,
       0,     0,   171,     0,     0,     0,     0,   424,     0,   207,
     206,     0,     0,     0,     0,    45,     0,     0,     0,   390,
       0,     0,     0,   434,    72,    71,    77,    79,     0,    85,
       0,    30,     0,   106,   111,     0,     0,     0,     0,     0,
       0,   139,   124,   137,   149,   154,     0,     0,    92,    93,
     165,     0,   158,   159,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,   165,     0,     0,     0,     0,     0,
     162,   161,     0,     0,     0,     0,    88,    89,     0,     0,
      41,     0,     0,     0,    43,    58,     0,   428,     0,     0,
       0,   284,   285,   286,   287,   142,     0,     0,     0,     0,
       0,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   220,     0,     0,   172,     0,
       0,     0,   423,   208,     0,   297,     0,     0,     0,     0,
      83,     0,     0,   100,   107,     0,   103,   112,     0,     0,
       0,   156,     0,   241,     0,     0,   243,     0,     0,   245,
       0,     0,     0,   256,     0,   216,     0,   165,     0,     0,
       0,   133,    90,     0,    49,     0,    55,     0,     0,     0,
       0,   119,   147,   283,   385,   229,     0,     0,   236,   230,
       0,     0,   238,   231,     0,     0,   240,     0,     0,     0,
     222,     0,   175,     0,     0,     0,     0,     0,     0,     0,
     110,     0,   108,   114,     0,   113,     0,   247,     0,   249,
       0,   251,   257,   263,   221,   217,     0,     0,     0,     0,
      46,     0,    53,     0,     0,     0,   419,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,     0,   179,     0,
     173,     0,    47,     0,     0,   200,     0,   109,     0,   115,
       0,     0,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,     0,   104,   242,     0,   244,     0,   246,     0,
     174,    48,    50,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    56,   105,   248,   250,   252,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    75,   788,    76,    77,   491,  1160,  1166,
     705,   900,  1319,  1481,   706,  1436,  1513,   707,  1483,   708,
     709,   904,   150,   275,    78,   591,   372,  1273,  1274,  1465,
    1329,  1374,  1330,  1377,   821,  1200,  1087,   566,   398,   399,
     400,   401,   243,   346,   347,    81,    82,    83,    84,    85,
      86,   244,   853,  1396,  1456,   640,  1222,  1225,  1228,  1416,
    1420,  1424,  1470,  1473,  1476,   849,   850,   969,   818,   614,
     649,    88,    89,    90,    91,    92,    93,   245,   153,   411,
     206,  1042,   246,   247,   248,   465,   255,   779,   936,   542,
     537,   543
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1137
static const yytype_int16 yypact[] =
{
    4344,    37,    74,  4430, -1137, -1137,  2224,    75,   -44,   -52,
     -48,    33,   139,   151,   154,   171,    53,  -116,    44,    78,
       2,    91,    97,    12,   103,   115,   166,   269,   282,   328,
     347,   367,   462,   380,   319,   503,    49,   292,   394,   295,
     184,   184,   301,   178,    60,   327,   408,   432,     7,    40,
     444,   468,   541,   553,  2400,   556,   430,   435,   455,    20,
       8, -1137,   465, -1137,   594,   616,   473, -1137,   626,   633,
      30,    31, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137,    42, -1137, -1137,    27,   481,    95, -1137, -1137,
   -1137,   257,   299,   337,   341,   397,   478,   506,   510,   559,
     564,   587,   604,   608,   619,   680,   683,   684,   692,   705,
     708,   720,   505,   511,   517,   518,   525,   537, -1137,   689,
     574,   579,   583, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
    4225,  4225,  4225, -1137, -1137,  3848,  3553,    11,   712,   320,
    2859,   723,   429, -1137,   746,   753,  4225,   758,   762, -1137,
    4225, -1137, -1137, -1137, -1137, -1137,  4225,  4037,  4225,  4225,
     624,  4225,  4037,  4225,  4225,   632,  4037,  4225,  4225,  2859,
     636,   605, -1137,   637,   642,  2400,  2400,  2400,   643, -1137,
   -1137, -1137, -1137,   647,   648,   671,  2859,  4225,   766,  2859,
     184,   184,   184,  4225,  4225,   -68, -1137,   -60,   184,   665,
     682,   686,  4001,   -36,  -102,   698,   704,   709,  2400,  2400,
    2859,   716,    43,   631, -1137,   860, -1137,   724,   749,   754,
     713,   728,  1065, -1137,   742,    32,   875,   911,   915,   354,
    3012,  4225,  2063, -1137, -1137,  2966, -1137,   930, -1137,   945,
    4225,  4225,  4225,   786,  4225,   791,   811,  4225,  4225, -1137,
   -1137,  4225,   967, -1137,   973, -1137,   977, -1137, -1137,  2859,
    2859,   830,  4225,   990,   839, -1137, -1137, -1137,   995,  4225,
    4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,
    4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,
    4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,
    4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,
    4225,    29,    29,    29,    29,    29,    29,  4225,    29,    29,
      29,   -53,   858,   858,   858,  4037,  6720,   142,  4037,  5961,
      83,   846,  1022,   880,   889, -1137,   882,  4219,  1048, -1137,
   -1137,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,  4225,
    4225,  4225,  4225,  4225,  4225,  4225, -1137, -1137,   818,   -18,
     215,  5259,    69,  6741,  4037,  2985, -1137,   428,  6762,  6783,
    4225,  6804,   488,  6825,  6846,  4225,   572,  6867,  6888,  1052,
    4225,  4225,  4225,  4225,  1056,  1061,  1061,  4225,   913,   917,
     923,   928,  4225,  4225,  4225,  1085,  5179,   940,  1093,   -79,
   -1137, -1137,  5285,  5311,   184,   184,   320,   320,    77,  4225,
    4225,  4225,  4001,  4001,  4225,  4219,   279, -1137,  4225,  4225,
    4225,  4225,  4225,  1095,  1099,  1115,  4225,  1100, -1137,  4225,
    4225,  1460, -1137,  4037,  4037,  4037,  4225,  4225,     0,  3777,
    1126, -1137,  4225, -1137, -1137, -1137,   982,   996,  1012,  1013,
    4037,   858, -1137,  6909, -1137,   715,  4225,  3165, -1137, -1137,
    6930,  6951,  6972,  1030,  5337, -1137,  1020,  3127,  6993,  5984,
   -1137, -1137,  1557, -1137,  1587,   997,   719,  4225,  6007,   168,
    4225,    -3, -1137,  7014,  6030,  7035,  6053,  7056,  6076,  7077,
    6099,  7098,  6122,  7119,  6145,  7140,  6168,  7161,  6191,  7182,
    6214,  7203,  6237,  7224,  6260,  5363,  5389,  7245,  6283,  7266,
    6306,  7287,  6329,  7308,  6352,  7329,  6375,  7350,  6398,  5415,
    5441,  5467,  5493,  5519,  5545,   737,   221, -1137,  1018,  1001,
    1037,  1025, -1137,   276,   877,  1064,  1042,  1070,  4225,   734,
     142, -1137,  2859,   763,    73,    95,  4225,  1145,  1207,    21,
    1055, -1137,   -98,    26,    28,    99, -1137, -1137,  3271,   561,
    1062,   761,   761,   119,   119,   119,   119,   368,   368,   858,
     858,   858,   858, -1137,    45,  4037,  1219,  4037,  4225,  1225,
   -1137,  1229,  1228,  4037,  4037,  1127,  1231,  1232,  7371,  1233,
    1131,  1235,  1236,  7392,  1135,  1240,  1241,  4225,  7413,  4507,
    7434,  7455,  4225,  2859,  1246,  1230,  7476,  4184,  4184,  4184,
    4184,  7497,  7518,  7539,  2859,  4037,  1094, -1137,   184,  4225,
    4225, -1137, -1137,  1089,  1091,  4001,  5571,  5597,  5623,  5233,
     253,   184,  1698,  7560,  4535,  7581,  7602,  7623,  4225,  1249,
   -1137,  4225,  7644, -1137,  6421,  6444, -1137,   764,   768,   769,
    6467,  6490, -1137,  4037, -1137,  4037,  6513,  1101,  4563,  4037,
    4037,  4037,  4037,   775, -1137, -1137,  3290,  4037,   858, -1137,
    1250,  1253,  1254,  1098,  4225,  2107,  4225,  4225, -1137,    50,
   -1137, -1137,  1105,  2859,  1256,  6536,   851, -1137,  4591, -1137,
    1113,  1116,  1108, -1137,  1265, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137,  4225,  4225, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137, -1137, -1137,  4225,  4225,  4225,  4225,
    4225,  4225,  4225,  1268, -1137,  4037,    29, -1137, -1137,    29,
   -1137,    29, -1137,  4225, -1137,    29,  1118,  4225,  1269,  1117,
      14,  4225,  1270,  1271,  1280, -1137,  1272,  1122,    20,  1275,
   -1137,  4037,  4037,  4037,  4037,  4225, -1137,  1141,    29,   392,
   -1137,   442,  5649, -1137,  1276,   184,  2985, -1137,  1226,  2859,
    2859,  1281,  2859,   881,  2859,  2859,  1283,  1237,  2859,  2859,
    1559,  1284,  1286,  1288,  1291,  1640, -1137, -1137,  1293, -1137,
    1294,  1147,  7875, -1137,  1148,  1149,  1150,  1300,  1301,  1302,
    1305,   787,  1296,   288,  5675,  5701, -1137, -1137,  4619,   -90,
     184,   184,   184,  1308,  1307,  1153,  1161,    34,    35,   -11,
   -1137,   307, -1137,   253,  1309,  1311,  1314,  1315,  1316,  7875,
   -1137,  1702,  1157,  1318,  1319,  1321,  1273,  4225,  1322,  1323,
     807,   810,   179, -1137, -1137,   816,   833,   837,   845, -1137,
    4225,   848,  2859,  2859,  2859,  1326,  5727, -1137,  3580,   395,
    1328,  1329,  2859,  1173, -1137,  1330,  1333, -1137,  1335, -1137,
    1185,  4225,  4225,  2859,  1184, -1137,  7665,  6559,  7686,  6582,
    7707,  6605,  7728,  6628,  6651, -1137,   446,  1192,  1193, -1137,
    7749,  1194,   142,  1827, -1137,   142,   110,  1195,  1343,  1895,
   -1137, -1137, -1137,    20,  4225, -1137,   872, -1137,   873,   879,
     883,   893,  7875, -1137,  1345,    47,  1348,  4225,   789,    67,
    1196,  1290,  1290,  2859,  1352,  1198,  1199,  1355,  1356,  2859,
    1202,  1359,  1360, -1137,  1362,  2859,  2859,  2859,  1364,  1363,
   -1137,  2859,  1365,  1366,  1369,  1371,  2859,  2859,  2859, -1137,
    1374,   360,  4225,  4225,  4225,  1209,  1210,   220,   224,   248,
    1234, -1137,  2859,  4225, -1137,  1380, -1137,  1381, -1137, -1137,
    4001,    38,  2553, -1137,  1238,  1239,  3318, -1137,  4037, -1137,
   -1137, -1137,  1243,  2145, -1137, -1137,  1242,  1244, -1137, -1137,
   -1137, -1137,  7875, -1137,  1383,  1385,  1287, -1137,  4225,  4225,
    4225, -1137,  1388,   463,  1251,  1389, -1137,   168, -1137,  4225,
    5753,  5779,   912, -1137,  4225, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137,  1252, -1137, -1137, -1137, -1137, -1137,  2859,
   -1137,  2859,    95,  4225,  1396,  1405,    21, -1137,  1406,  6674,
      20, -1137,  1423,  1424,  1425,  1426, -1137, -1137,    29, -1137,
    5805,  4184,  7875, -1137, -1137,  4225,   184,  1428,  1429,  1430,
   -1137,  4225,  4225, -1137, -1137,  1431,  4225, -1137, -1137,  1433,
    1434,  1435,  1332,  4225, -1137,  1437,  2859,  2859,  2859,  2859,
    1438,  1072,  1441,  4225, -1137,  4184,  4647,  7770,  4423,   320,
     320,   184,  1442,   184,  1443,   184,  1444,  4225,   336,  1295,
    7791, -1137, -1137,  4675,   384, -1137,  1448,  1865,  1454,  2859,
     184,  1865,  1455,   926,  4225, -1137, -1137, -1137, -1137, -1137,
    2859,  4451,   365,  7812, -1137, -1137,  3624,  2859, -1137, -1137,
     471,  7875,  4225,  4225,  2859,  1303,   931,  7875,  1458,  1457,
    1459,  1463,  2165, -1137,  1464,  1468, -1137,  1312, -1137, -1137,
   -1137, -1137, -1137,  1469,  4225,  7875, -1137,  4703,   436, -1137,
   -1137, -1137,  4731,  4759, -1137,  4787,  1461, -1137, -1137,  1420,
    1471,  7875, -1137,  1473,  1474,  1475,  1480, -1137,  1327, -1137,
   -1137,  5206,  2184,  1481,  1334, -1137,  4225, -1137,  1331,  1336,
     434, -1137,  1338,   476, -1137,  1339,   480, -1137,  1340,  6697,
    1488,  2859,  1489,  1341,  4225, -1137,  3471,   494, -1137,   938,
     513,   533, -1137,  1497,  4815,  1399,  4225, -1137,  4225, -1137,
   -1137,  4037,  2254,  1499,  1344, -1137,  4225,  5831,  5857, -1137,
    2859,  4225,  1501, -1137, -1137, -1137, -1137, -1137,    20, -1137,
    1400, -1137,  5883, -1137, -1137,  1503,  1505,  1516,  1518,  1519,
    1372, -1137, -1137, -1137, -1137, -1137,  2859,  4037, -1137, -1137,
     320,  4479, -1137, -1137,  4001,   253,  4001,   253,  4001,   253,
    1526, -1137,   950,  2859, -1137,  4843,   184,  1530,  4037,   184,
   -1137, -1137,  4225,  4871,  4899,   954, -1137, -1137,  1531,  1377,
    7875,  4225,  4225,   955,  7875, -1137,  1533, -1137,  4225,   961,
     966, -1137, -1137, -1137, -1137, -1137,  4225,   969,   974,  1382,
    4225, -1137,  4927,   550,   514,  4955,   578,   562,  4983,   582,
     695, -1137,  2859,  1537,  1472,  2436,  1386,   591, -1137,   986,
     595,  2659, -1137, -1137,  1542, -1137,  4225,  7833,  5909,    36,
   -1137,  5935,  1545, -1137, -1137,  1546, -1137, -1137,  5011,  1548,
    1549, -1137,  5039,  1550,  4225,  1551,  1552,  4225,  1553,  1554,
    4225,  1555,  1404, -1137,  4225, -1137,   253, -1137,  4037,  1562,
    3471, -1137, -1137,   987, -1137,  4225, -1137,  2859,  4225,  2706,
    3813, -1137, -1137, -1137, -1137, -1137,  1410,  5067, -1137, -1137,
    1411,  5095, -1137, -1137,  1412,  5123, -1137,  1568,  2678,   760,
    2589,  1002, -1137,   612,  1003,  1570,  1417,  7854,  1006,  5151,
   -1137,  2063, -1137, -1137,    29,  7875,   253,  1573,   253,  1574,
     253,  1576, -1137, -1137, -1137, -1137,   253,  1577,  4037,  1578,
   -1137,    29, -1137,  1427,  1579,  1010,  1679,  1017,   778, -1137,
    1436,   895, -1137,  1445,   958, -1137,  1446,   976, -1137,  1029,
   -1137,  1033, -1137,  1447,  2859, -1137,  4225, -1137,    95, -1137,
    1580,   253,  1581,   253,  1583,   253, -1137,  1584,    29,  1585,
      29,  1060,  2820, -1137, -1137,   991, -1137,  1014, -1137,  1051,
   -1137, -1137, -1137,  1067, -1137,  1586,    95,  1588,  1590,  1592,
      29,  1599, -1137, -1137, -1137, -1137, -1137, -1137, -1137
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1137, -1137, -1137, -1137,   674, -1137, -1137, -1137, -1137,   255,
   -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137,  -327,     1, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137,   -95, -1137,   673,  1626, -1137, -1137,
   -1137, -1137,    -1,  -408,  -207, -1137, -1137, -1137, -1137, -1137,
   -1137,  1627, -1137, -1137, -1137, -1137, -1137, -1137, -1137, -1137,
   -1137, -1137, -1137, -1137, -1137,  -803,  -788, -1137, -1137,  1255,
   -1137, -1137, -1137, -1137, -1137, -1137, -1137,    -2, -1137,    46,
   -1137, -1136,   575,   -72,   820,  1008,  -749,   565, -1137,  -302,
      -6,   191
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     154,   699,    80,  1239,   152,   425,   170,   151,   633,   634,
     552,   222,   256,   556,   156,   340,   175,   441,   926,   536,
     538,   539,   540,   541,   253,   777,   545,   546,   547,   935,
     170,   271,   175,   535,   277,   264,   266,   451,   166,   159,
     994,   996,  1406,     4,   225,   167,   226,   437,   268,   438,
    1001,   786,   428,  1077,   414,   415,   166,   890,   482,   429,
     484,   999,   843,   781,   214,   414,   415,   122,   123,   124,
     125,   844,   986,  1084,     5,   128,   414,   415,   845,   846,
     551,   628,   847,   848,   414,   415,   205,   207,   155,   213,
     555,   278,   227,   416,   700,   701,   702,   703,   143,   144,
     277,   417,   157,   548,   196,   273,   158,   197,   414,   415,
     274,   843,   215,   394,   395,   396,   216,  1062,   341,   342,
     844,   927,   928,   223,  1323,   427,   217,   845,   846,   995,
     997,   847,   848,   122,   123,   124,   125,   584,   332,   333,
     334,   128,   585,   336,   339,   161,   433,   434,   345,   551,
    1337,   998,   131,   132,   368,   662,   171,   162,   371,   704,
     163,   663,   257,   172,   373,   375,   378,   379,   224,   381,
     375,   383,   384,   176,   375,   387,   388,   164,   143,   144,
     171,   254,   778,   272,  1068,   273,   787,   782,   787,   783,
     274,   265,   267,   452,   160,   406,   269,  1407,   168,   439,
    1135,   412,   413,   270,   136,   137,   138,   139,   891,   165,
     413,   414,   415,   999,   136,   137,   138,   139,   131,   132,
     642,   414,   415,   767,   143,   144,   589,   771,   179,   590,
     209,   770,   169,   210,   143,   144,   211,   635,   461,   463,
     375,   136,   137,   138,   139,   173,   409,   410,   470,   471,
     472,   174,   474,   178,   418,   477,   478,   177,   426,   479,
     784,   143,   144,   360,   361,   362,   363,   364,   685,   178,
     488,  1438,   365,   136,   137,   138,   139,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   143,
     144,  1178,   201,   202,   344,   544,   843,   180,   201,   202,
     143,   144,   203,   375,   182,   844,   375,   896,   203,   212,
     181,   557,   845,   846,   466,   204,   847,   848,  1501,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   414,   415,  1114,  1115,   414,   415,
     586,   189,   461,  1248,   190,   587,   754,   191,   598,   192,
    1121,   755,  1122,   603,  1123,   218,  1124,   219,   608,   609,
     610,   611,   414,   415,   898,   616,    39,    40,    41,    42,
     621,   622,   623,  1030,    47,   183,   456,    50,  1125,   457,
    1126,   279,   458,   280,   459,   345,   345,   636,   637,   638,
     332,   333,   639,   414,   415,   184,   643,   644,   645,   646,
     647,   760,   414,   415,   652,   350,   761,   654,   655,   641,
     188,   375,   375,   375,   660,   661,   198,   666,   982,   199,
     668,   414,   415,   281,   917,   282,   200,   918,   375,   919,
     631,   632,   208,   921,   676,   678,   220,  1000,   410,  1155,
    1156,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   467,   363,   364,   695,   944,   221,   698,   365,
     697,   283,  1344,   284,  1347,   285,  1350,   286,  1230,   228,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   362,   363,   364,   185,   365,  1326,
     186,   365,   187,   824,   825,   826,   229,  1249,   414,   415,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,  1234,   230,   666,   945,   365,   773,
    1031,   287,   594,   288,   774,   772,   999,   231,   193,   999,
     249,   194,   999,   195,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   414,   415,
     414,   415,   365,   375,   250,   375,   792,   843,   594,   251,
     595,   678,   796,  1429,  1294,  1059,   844,   946,  1061,  1063,
     259,  1054,   594,   845,   846,   810,   594,   847,   848,   252,
     815,   823,   823,   823,   823,   822,   822,   822,   822,   258,
     414,   415,   260,   375,   414,   415,  1255,   834,   835,   261,
     262,  1256,   289,   838,   290,   843,  1296,   263,   414,   415,
    1298,   999,   276,  1468,   844,  1471,   859,  1474,   594,   861,
     600,   845,   846,  1477,  1306,   847,   848,   414,   415,   321,
     291,   375,   292,   375,   293,   322,   294,   375,   375,   375,
     375,   323,   324,  1308,   833,   375,  1385,   414,   415,   325,
     999,   839,   886,   999,   888,   889,   999,   851,  1505,   999,
    1507,   326,  1509,  1309,   414,   415,   327,   897,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
    1384,  1218,  1219,   295,   365,   296,   343,   999,   297,   999,
     298,   999,   414,   415,  1388,   348,   414,   415,   328,   349,
     906,   907,   594,   329,   604,   414,   415,   330,  1387,   414,
     415,   299,  1390,   300,   908,   909,   910,   911,   912,   913,
     914,  1398,   366,   375,   389,  1400,   414,   415,   301,   367,
     302,   920,   303,   369,   304,   923,   391,   370,   843,   929,
     407,   405,  1458,   305,   408,   306,  1183,   844,   380,   375,
     375,   375,   375,   942,   845,   846,   385,   440,   847,   848,
     390,   392,    94,   331,   277,   435,   393,   397,    98,    99,
     100,   402,   403,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   583,   404,   419,   122,   123,   124,
     125,   126,   127,   843,   307,   128,   308,   309,   311,   310,
     312,   949,   844,   420,   485,   486,   313,   421,   314,   845,
     846,   843,   430,   847,   848,   535,   277,  1391,   431,   315,
     844,   316,   317,   432,   318,  1013,   442,   845,   846,   446,
     436,   847,   848,   897,   319,   594,   320,   675,  1022,   693,
     453,   694,  1339,   762,   447,   443,   987,   988,   989,   122,
     123,   124,   125,   752,   594,   753,   766,   128,   450,  1040,
    1041,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     444,   130,   131,   132,   365,   445,   454,   133,   134,   135,
     455,   476,  1454,   594,   594,   769,   865,  1064,   594,   594,
     866,   867,  1069,   140,   141,   594,   468,   879,   142,   955,
    1490,   956,  1083,   241,   473,  1080,  1082,   594,   148,   980,
    1081,   469,   475,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   594,   843,  1016,
     594,   365,  1017,   480,   131,   132,   594,   844,  1018,   481,
    1116,  1117,  1118,   483,   845,   846,   487,   376,   847,   848,
    1128,  1130,   376,   594,   489,  1019,   376,   594,  1133,  1020,
     490,   492,   143,   144,   558,   594,   375,  1021,   594,   896,
    1023,   365,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,  1151,  1152,  1153,   559,
     365,   843,  1070,   594,  1071,  1072,   560,  1161,  1159,   594,
     844,  1073,  1167,   594,   561,  1074,  1134,   845,   846,   843,
     149,   847,   848,   594,   567,  1075,  1171,  1492,   844,   607,
     462,  1172,   376,   612,   843,   845,   846,   617,   613,   847,
     848,   618,  1164,   844,  1165,  1186,  1208,   619,  1209,  1185,
     845,   846,   620,  1187,   847,   848,   594,   843,  1243,  1192,
    1193,  1261,   624,  1262,  1195,   626,   844,  1355,  1164,   627,
    1307,  1201,   648,   845,   846,   650,   653,   847,   848,  1213,
    1352,  1211,  1353,  1212,   594,  1164,  1364,  1369,   345,   345,
    1494,  1372,   651,  1373,   843,  1229,  1375,   768,  1376,  1164,
     667,  1379,  1188,   844,   594,   375,  1380,   683,  1496,   375,
     845,   846,  1244,   669,   847,   848,   594,  1261,  1399,  1435,
    1253,   775,   692,  1517,  1252,   376,   757,   670,   376,  1482,
    1257,  1258,   594,   594,  1457,  1459,  1164,  1220,  1463,  1223,
    1486,  1226,  1487,   671,   672,   377,  1518,   761,   756,  1489,
     382,   686,  1272,  1237,   386,   759,  1240,  1241,   816,   594,
    1430,  1497,   758,  1498,   462,  1499,  1511,   764,  1514,   830,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   776,   780,  1519,  1291,   365,   143,   144,  1527,   448,
    1164,   449,  1515,   273,   763,   790,   149,  1520,   274,  1521,
     765,   793,  1305,   794,   461,   795,   819,   798,   799,   800,
     802,   803,   804,   805,  1313,   807,  1314,   808,   809,   375,
     817,   836,   832,   837,  1320,   860,   885,   882,   873,  1324,
     883,   884,   894,   376,   376,   376,   892,   901,   893,   903,
     902,   905,   915,   922,   925,   924,   930,   931,   934,   933,
     376,   937,   943,   948,   950,   375,   932,   679,   953,   345,
     959,   964,  1342,   965,  1345,   966,  1348,   960,   967,   970,
     981,   971,   972,   973,   974,   975,   375,   976,   977,   978,
    1361,   979,   990,   991,   992,   993,  1002,  1003,  1008,  1367,
    1368,  1004,  1005,  1006,  1009,  1010,  1371,  1011,  1014,  1015,
    1027,  1012,  1032,  1033,  1378,  1035,  1036,  1037,  1382,  1039,
    1343,  1038,  1346,   549,  1349,  1044,   553,  1055,  1056,  1058,
    1066,  1076,  1357,  1065,  1079,  1360,  1086,  1085,  1090,  1091,
    1092,  1093,  1094,  1096,  1167,  1097,  1098,  1099,  1103,  1104,
    1119,  1120,  1106,  1107,   951,   952,  1108,   954,  1109,   957,
     958,  1113,  1417,   961,   962,  1421,  1131,  1132,  1425,  1148,
    1127,  1149,  1428,  1150,  1154,  1158,   375,  1146,   375,  1139,
    1140,  1147,  1173,  1437,  1144,   376,  1439,   376,  1445,  1174,
    1168,  1157,  1176,   679,   797,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,  1179,
    1180,  1181,  1182,   365,  1189,  1190,  1191,  1194,  1196,  1466,
    1197,  1198,  1199,  1202,  1207,   376,  1433,  1210,  1221,  1224,
    1227,   657,   658,   659,  1235,  1231,   375,  1024,  1025,  1026,
    1238,  1242,  1263,  1264,  1260,  1265,  1279,  1034,   673,  1266,
    1270,  1268,     7,     8,  1269,  1271,  1280,  1281,  1043,  1282,
    1283,  1284,  1503,   376,  1502,   376,  1285,  1289,  1286,   376,
     376,   376,   376,  1292,  1301,  1290,  1303,   376,  1293,  1295,
    1297,  1299,  1304,  1310,  1312,  1317,  1318,  1325,  1327,  1331,
    1523,  1332,   562,    18,    19,   563,    21,    22,   564,    24,
     565,    26,  1333,    27,  1334,  1335,    30,    31,  1089,    33,
      34,    35,  1351,  1336,  1095,    38,  1358,  1365,  1366,  1370,
    1100,  1101,  1102,  1393,  1381,  1394,  1105,  1397,  1402,  1409,
    1410,  1110,  1111,  1112,  1412,  1413,  1415,  1418,  1419,  1422,
    1423,  1426,    56,    57,    58,   963,  1427,  1129,  1432,     7,
       8,  1446,  1448,  1450,  1452,   376,  1460,  1138,  1461,  1469,
    1472,  1142,  1475,  1478,  1480,  1485,  1504,  1506,  1484,  1508,
    1510,  1512,  1522,   789,  1524,   791,  1525,  1491,  1526,     7,
       8,   376,   376,   376,   376,  1528,  1493,  1495,  1500,   562,
      18,    19,   563,    21,    22,   564,    24,   565,    26,  1078,
      27,  1403,   656,    30,    31,  1088,    33,    34,    35,    79,
      87,  1175,    38,   831,  1169,  1467,  1170,     0,     0,   562,
      18,    19,   563,    21,    22,   564,    24,   565,    26,     0,
      27,   615,     0,    30,    31,     0,    33,    34,    35,    56,
      57,    58,    38,     0,     0,     0,     0,     0,     0,     0,
       0,   870,     0,   871,     0,     0,     0,   875,   876,   877,
     878,  1203,  1204,  1205,  1206,   881,  1488,   466,     0,    56,
      57,    58,     0,     0,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,  1007,     0,
       7,     8,   365,   968,  1043,     0,     0,     0,     0,   690,
       0,     0,     0,     0,     0,  1245,     0,     0,     0,     0,
       0,     0,  1254,     0,     0,     0,     0,     0,     0,  1259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   691,
     562,    18,    19,   563,    21,    22,   564,    24,   565,    26,
       0,    27,     0,   916,    30,    31,     0,    33,    34,    35,
       0,     0,     0,    38,     0,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   938,
     939,   940,   941,   365,     0,     0,     0,     0,     0,     0,
      56,    57,    58,     0,     0,     0,  1302,     0,     0,     0,
       0,     0,     0,     0,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   593,   363,   364,   376,     0,
       0,     0,   365,  1060,     0,  1043,     0,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,     0,     0,     0,
     852,  1043,     0,     0,     0,     0,     0,     0,    94,   232,
       0,     0,     0,     0,    98,    99,   100,     0,  1354,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     234,  1067,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   235,     0,     0,
     236,     0,     0,   237,     0,   238,     0,  1392,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,     0,     0,     0,     0,   376,     0,     0,
       0,   376,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,  1043,     0,  1442,     0,     0,   130,     0,     0,
       0,     0,     0,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   422,
    1236,     0,     0,     0,   142,     0,  1143,     0,     0,   424,
       0,     0,     0,     0,   148,     0,   204,   464,     0,     0,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,   462,     0,     0,  1043,
       0,     0,     0,     0,     0,     0,    94,   232,     0,     0,
       0,   376,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   234,     0,
       0,     0,     0,     0,     0,   126,   127,   376,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,   236,     7,
       8,   237,     0,   238,     0,     0,     0,     0,   376,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,  1145,     0,     0,     0,     0,     0,     0,     0,   562,
      18,    19,   563,    21,    22,   564,    24,   565,    26,     0,
      27,  1267,     0,    30,    31,     0,    33,    34,    35,     0,
       0,     0,    38,     0,     0,   130,     0,     0,     0,     0,
    1288,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   374,    56,
      57,    58,   142,     0,     0,     0,     0,   241,   376,     0,
     376,     0,   148,     0,     0,   464,     0,    94,    95,    96,
       0,    97,     0,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,  1315,
    1316,   376,   122,   123,   124,   125,   126,   127,     0,   887,
     128,     0,     0,     0,     0,     0,     0,     0,   376,     0,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,  1338,     0,     0,   365,     0,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,  1359,     0,   365,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,     0,
     129,     0,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
       0,     0,     0,   142,     0,   143,   144,     0,   145,     0,
     146,     0,   147,   148,     0,   149,     0,     0,     0,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,    94,   232,   233,  1431,   365,  1434,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   234,     0,     0,     0,     0,
       0,     0,   126,   127,     0,     0,     0,     0,     7,     8,
       0,     0,   235,     0,     0,   236,     0,     0,   237,     0,
     238,     0,     0,     0,     0,     0,  1479,     0,     0,     0,
     239,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     0,    47,     0,     0,    50,   562,    18,
      19,   563,    21,    22,   564,    24,   565,    26,     0,    27,
       0,     0,    30,    31,     0,    33,    34,    35,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,     0,     0,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      58,     0,     0,     0,   140,   240,     0,     0,     0,   142,
       0,     0,     0,     0,   241,     0,    94,   232,  1136,   148,
       0,   242,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   234,     0,
       0,     0,     0,     0,     0,   126,   127,     0,  1395,     0,
       0,     7,     8,     0,     0,   235,     0,     0,   236,     0,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,   562,    18,    19,   563,    21,    22,   564,    24,   565,
      26,     0,    27,     0,     0,    30,    31,     0,    33,    34,
      35,     0,     0,     0,    38,  1401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,     0,
       0,   133,   134,   135,  1453,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,     0,     0,   140,   240,     0,
       0,     0,   142,     0,     0,     0,     0,   241,     0,    94,
     232,  1440,   148,     0,  1137,    98,    99,   100,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   234,     0,     0,     0,     0,     0,     0,   126,   127,
       0,  1455,     0,     0,     0,     0,     0,     0,   235,     0,
       0,   236,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,     0,     0,     0,
      47,     0,     0,    50,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,  1516,   130,     0,
       0,   365,     0,     0,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   240,     0,     0,     0,   142,     0,     0,     0,     0,
     241,     0,    94,   232,     0,   148,     0,  1441,    98,    99,
     100,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   234,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   235,     0,     0,   236,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,   466,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,     0,     0,   133,   134,   135,
       0,     0,     0,   466,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   240,     0,     0,     0,   142,     0,
       0,     0,     0,   241,     0,    94,   232,     0,   148,     0,
     242,    98,    99,   100,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   234,     0,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,   235,     0,     0,   236,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,    47,     0,     0,    50,
       0,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   467,   363,   364,     0,     0,     0,     0,   365,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   593,   363,   364,   130,   687,     0,     0,   365,     0,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   374,     0,     0,
       0,   142,     0,     0,     0,     0,   241,     0,    94,   232,
       0,   148,     0,   460,    98,    99,   100,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     234,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   235,     0,     0,
     236,     0,     0,   237,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,     0,     0,    47,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,   785,
     365,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,     0,     0,   133,   134,   135,     0,     0,   880,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     374,     0,     0,     0,   142,     0,     0,     0,     0,   241,
       0,    94,   232,     0,   148,     0,   677,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   234,     0,     0,     0,     0,     0,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
     235,     0,     0,   236,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,     0,
       0,     0,    47,     0,     0,    50,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
     130,     0,     0,   365,     0,     0,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   240,     0,     0,     0,   142,     0,     0,
       0,     0,   241,     0,    94,   232,     0,   148,     0,  1141,
      98,    99,   100,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   234,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,   235,     0,     0,   236,     0,     0,   237,
       0,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,    94,   331,    50,     0,
       0,     0,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,  1029,     0,
       0,     0,     0,   130,     0,   126,   127,     0,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,  1236,     0,     0,     0,
     142,     0,     0,     0,     0,   424,     0,    94,   331,   277,
     148,     0,   204,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,   122,   123,   124,   125,   126,   127,     0,     0,
     128,     0,     0,     0,     0,   130,     0,     0,     0,     0,
       0,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,   142,     0,     0,     0,     0,   241,     0,     0,
     337,     0,   148,     0,   338,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
       0,     0,     0,   142,     0,     0,     0,     0,   241,     0,
      94,   331,     0,   148,     0,  1251,    98,    99,   100,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,     0,     0,    94,   331,  1443,   126,
     127,     0,    98,    99,   100,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,    94,   331,     0,     0,   126,   127,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,     0,     0,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,     0,     0,     0,   142,     0,     0,     0,
       0,   241,     0,     0,   664,   130,   148,     0,   665,     0,
       0,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,   142,     0,     0,     0,     0,   241,     0,     0,
     130,     0,   148,     0,  1444,     0,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,     0,     0,     0,   142,     0,     0,
       0,     0,   241,     0,    94,   331,     0,   148,     0,   335,
      98,    99,   100,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,     0,     0,
      94,   232,     0,   126,   127,     0,    98,    99,   100,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   234,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,     0,   236,     0,     0,   237,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,   130,    50,     0,     0,     0,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   423,     0,     0,     0,
     142,     0,     0,     0,     0,   424,     0,     0,     0,   130,
     148,     0,   204,     0,     0,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   374,     0,     0,     0,   142,    94,   331,   277,
       0,   241,     0,    98,    99,   100,   148,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,   122,   123,   124,   125,   126,   127,    94,   331,
     128,     7,     8,     0,    98,    99,   100,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,   562,    18,    19,   563,    21,    22,   564,    24,   565,
      26,     0,    27,     0,     0,    30,    31,     0,    33,    34,
      35,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,     0,
       0,     0,   133,   134,   135,     0,     0,     0,     0,     0,
       0,    56,    57,    58,     0,     0,     0,     0,   140,   141,
       0,     0,     0,   142,     0,     0,     0,     0,   241,     0,
       0,     0,     0,   148,    -4,     1,     0,   130,    -4,     0,
       0,     0,     0,   133,   134,   135,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,     0,   142,     0,     0,     0,     0,   241,
      -4,    -4,     0,     0,   148,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,     0,
      -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,    -4,
      -4,    -4,     0,     0,    11,    12,     0,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
       0,    52,    53,     0,     0,     0,    54,     0,     0,     0,
       0,    55,    56,    57,    58,     0,     0,    59,     0,    60,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,    72,    73,    74,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,  1216,     0,  1217,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,  1246,     0,  1247,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,  1340,
       0,  1341,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,   812,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,   855,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,     0,   874,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,   899,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
       0,   985,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,  1214,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,  1233,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,     0,  1275,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,  1276,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
       0,  1277,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,  1278,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,  1311,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,     0,  1356,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,  1362,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
       0,  1363,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,  1383,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,  1386,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,     0,  1389,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,  1411,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
       0,  1414,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,  1447,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,  1449,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,     0,     0,  1451,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,     0,     0,  1464,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,     0,
     625,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,     0,     0,     0,     0,     0,     0,  1287,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   674,     0,
       0,     0,     0,   629,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   588,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   629,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   630,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,   684,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,   732,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   733,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   746,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   747,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,   748,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,   749,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   750,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   751,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   840,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,   841,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,   842,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   947,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   983,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   984,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,  1028,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,  1162,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,  1163,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,  1184,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,  1321,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,  1322,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,     0,  1328,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,  1405,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,  1408,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,   554,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,     0,
       0,   689,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,   696,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,     0,     0,   711,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
     713,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,     0,     0,   715,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,   717,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,     0,     0,   719,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,   721,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,     0,     0,   723,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,   725,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,     0,
       0,   727,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,   729,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,     0,     0,   731,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
     735,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,     0,     0,   737,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,   739,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,     0,     0,   741,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,   743,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,     0,     0,   745,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,   863,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,     0,
       0,   864,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,   868,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,     0,     0,   869,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,     0,     0,
     872,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,     0,     0,   895,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,     0,     0,  1046,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,     0,     0,  1048,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
       0,     0,  1050,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,     0,     0,  1052,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,     0,     0,  1053,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,     0,
       0,  1177,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,     0,     0,  1300,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,   550,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,   592,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,   596,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   597,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,   599,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
     601,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,   602,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,   605,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,   606,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,   674,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,   680,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,   681,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,   682,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   688,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,   710,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
     712,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,   714,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,   716,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,   718,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,   720,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,   722,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,   724,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,   726,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   728,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,   730,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
     734,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,   736,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,   738,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,   740,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,   742,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,   744,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,   801,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,   806,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   811,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,   813,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
     814,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,   820,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,   827,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,   828,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,   829,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,   854,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,   856,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,   857,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,   858,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,   862,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365,     0,
    1045,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,     0,     0,     0,     0,   365,
       0,  1047,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,     0,     0,     0,     0,
     365,     0,  1049,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,     0,     0,     0,
       0,   365,     0,  1051,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,     0,     0,
       0,     0,   365,     0,  1057,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,     0,
       0,     0,     0,   365,     0,  1215,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
       0,     0,     0,     0,   365,     0,  1232,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     0,     0,     0,     0,   365,     0,  1250,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,     0,     0,     0,     0,   365,     0,  1404,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     0,     0,     0,     0,   365,     0,  1462,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,     0,     0,     0,     0,   365
};

static const yytype_int16 yycheck[] =
{
       6,     4,     3,  1139,     6,   212,     4,     6,   416,   417,
     337,     4,     4,   340,    58,     4,     4,   224,     4,   321,
     322,   323,   324,   325,     4,     4,   328,   329,   330,   778,
       4,     4,     4,     4,     5,     5,     5,     5,   154,     6,
       6,     6,     6,     6,     4,   161,     6,     4,     6,     6,
     853,     6,   154,     6,   144,   145,   154,     7,   265,   161,
     267,   849,    73,   161,     4,   144,   145,    38,    39,    40,
      41,    82,   162,     6,     0,    46,   144,   145,    89,    90,
       7,   160,    93,    94,   144,   145,    40,    41,    13,    43,
       7,    97,    52,   161,    97,    98,    99,   100,   151,   152,
       5,   161,   154,   156,    55,   158,   154,    58,   144,   145,
     163,    73,    52,   185,   186,   187,    56,     7,   107,   108,
      82,   107,   108,   116,  1260,   161,    66,    89,    90,    95,
      95,    93,    94,    38,    39,    40,    41,   155,   140,   141,
     142,    46,   160,   145,   146,     6,   218,   219,   149,     7,
    1286,   162,   123,   124,   156,   155,   154,     6,   160,   162,
       6,   161,   154,   161,   166,   167,   168,   169,   161,   171,
     172,   173,   174,   161,   176,   177,   178,     6,   151,   152,
     154,   161,   161,   156,   933,   158,   141,   161,   141,   161,
     163,   161,   161,   161,   161,   197,   154,   161,   154,   156,
     162,   203,   204,   161,   131,   132,   133,   134,   158,   156,
     212,   144,   145,  1001,   131,   132,   133,   134,   123,   124,
     427,   144,   145,   550,   151,   152,   157,   554,    62,   160,
      52,   158,   154,    55,   151,   152,    58,   160,   240,   241,
     242,   131,   132,   133,   134,   154,   200,   201,   250,   251,
     252,   154,   254,   154,   208,   257,   258,   154,   212,   261,
     161,   151,   152,   144,   145,   146,   147,   148,   475,   154,
     272,  1407,   153,   131,   132,   133,   134,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   151,
     152,  1070,   144,   145,     4,   327,    73,    58,   144,   145,
     151,   152,   154,   335,     6,    82,   338,   158,   154,   161,
      58,   340,    89,    90,     8,   161,    93,    94,  1484,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   144,   145,     6,     7,   144,   145,
     155,    52,   374,     8,    55,   160,   155,    58,   380,    60,
     160,   160,   162,   385,   160,    58,   162,    60,   390,   391,
     392,   393,   144,   145,   696,   397,    76,    77,    78,    79,
     402,   403,   404,     8,    84,    58,    52,    87,   160,    55,
     162,   154,    58,   156,    60,   416,   417,   419,   420,   421,
     422,   423,   424,   144,   145,    58,   428,   429,   430,   431,
     432,   155,   144,   145,   436,     6,   160,   439,   440,   160,
      60,   443,   444,   445,   446,   447,   154,   449,   160,    55,
     452,   144,   145,   154,   756,   156,   161,   759,   460,   761,
     414,   415,   161,   765,   466,   467,    58,   160,   422,     6,
       7,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   487,   788,    55,   490,   153,
     489,   154,  1295,   156,  1297,   154,  1299,   156,   162,    55,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   146,   147,   148,    55,   153,  1268,
      58,   153,    60,   618,   619,   620,    58,   162,   144,   145,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   160,     4,   548,   155,   153,   555,
     155,   154,   160,   156,   556,   554,  1344,     4,    55,  1347,
       4,    58,  1350,    60,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   144,   145,
     144,   145,   153,   585,   154,   587,   588,    73,   160,   154,
     162,   593,   594,  1396,   160,   922,    82,   155,   925,   926,
       6,   155,   160,    89,    90,   607,   160,    93,    94,   154,
     612,   617,   618,   619,   620,   617,   618,   619,   620,   154,
     144,   145,     6,   625,   144,   145,   155,   629,   630,   156,
       4,   160,   154,   635,   156,    73,   160,     4,   144,   145,
     160,  1429,   161,  1446,    82,  1448,   648,  1450,   160,   651,
     162,    89,    90,  1456,   160,    93,    94,   144,   145,   154,
     154,   663,   156,   665,   154,   154,   156,   669,   670,   671,
     672,   154,   154,   160,   628,   677,   162,   144,   145,   154,
    1468,   635,   684,  1471,   686,   687,  1474,   641,  1491,  1477,
    1493,   154,  1495,   160,   144,   145,     7,   696,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     160,  1119,  1120,   154,   153,   156,     4,  1505,   154,  1507,
     156,  1509,   144,   145,   162,   150,   144,   145,   154,     6,
     732,   733,   160,   154,   162,   144,   145,   154,   160,   144,
     145,   154,   160,   156,   746,   747,   748,   749,   750,   751,
     752,   160,     6,   755,   179,   160,   144,   145,   154,     6,
     156,   763,   154,     5,   156,   767,   161,     5,    73,   771,
       4,   196,   160,   154,   199,   156,  1078,    82,   154,   781,
     782,   783,   784,   785,    89,    90,   154,   156,    93,    94,
     154,   154,     3,     4,     5,   220,   154,   154,     9,    10,
      11,   154,   154,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     6,   154,   161,    38,    39,    40,
      41,    42,    43,    73,   154,    46,   156,   154,   154,   156,
     156,   795,    82,   161,   269,   270,   154,   161,   156,    89,
      90,    73,   154,    93,    94,     4,     5,   162,   154,   154,
      82,   156,   154,   154,   156,   867,     6,    89,    90,   156,
     154,    93,    94,   872,   154,   160,   156,   162,   880,   160,
       5,   162,  1290,     6,   156,   161,   840,   841,   842,    38,
      39,    40,    41,   156,   160,   158,   162,    46,   156,   901,
     902,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     161,   122,   123,   124,   153,   161,     5,   128,   129,   130,
       5,   110,   162,   160,   160,   162,   162,   926,   160,   160,
     162,   162,   934,   144,   145,   160,     6,   162,   149,    58,
     162,    60,   948,   154,   158,   947,   948,   160,   159,   162,
     161,     6,   161,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   160,    73,   162,
     160,   153,   162,     6,   123,   124,   160,    82,   162,     6,
     982,   983,   984,     6,    89,    90,   156,   167,    93,    94,
     992,   993,   172,   160,     4,   162,   176,   160,  1000,   162,
     161,     6,   151,   152,   158,   160,  1008,   162,   160,   158,
     162,   153,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,  1028,  1029,  1030,     7,
     153,    73,   160,   160,   162,   162,   156,  1039,  1037,   160,
      82,   162,  1044,   160,   162,   162,  1000,    89,    90,    73,
     161,    93,    94,   160,     6,   162,  1062,   162,    82,     7,
     240,  1063,   242,     7,    73,    89,    90,   154,     7,    93,
      94,   154,   160,    82,   162,  1081,     4,   154,     6,  1081,
      89,    90,   154,  1085,    93,    94,   160,    73,   162,  1091,
    1092,   160,     7,   162,  1096,   155,    82,  1304,   160,     6,
     162,  1103,     7,    89,    90,     6,     6,    93,    94,  1115,
     160,  1113,   162,  1115,   160,   160,   162,   162,  1119,  1120,
     162,   160,     7,   162,    73,  1127,   160,   552,   162,   160,
       4,   162,  1086,    82,   160,  1137,   162,   107,   162,  1141,
      89,    90,  1144,   161,    93,    94,   160,   160,   162,   162,
    1156,     6,   155,   162,  1156,   335,   155,   161,   338,  1461,
    1162,  1163,   160,   160,   162,   162,   160,  1121,   162,  1123,
     160,  1125,   162,   161,   161,   167,   162,   160,   160,   162,
     172,   161,  1184,  1137,   176,   160,  1140,  1141,   613,   160,
    1397,   162,   155,   160,   374,   162,  1498,   155,  1500,   624,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     4,   157,   162,  1216,   153,   151,   152,  1520,   154,
     160,   156,   162,   158,   160,     6,   161,   160,   163,   162,
     160,     6,  1234,     4,  1236,     7,     6,   110,     7,     7,
       7,   110,     7,     7,  1246,   110,  1248,     7,     7,  1251,
       4,   162,   158,   162,  1256,     6,   158,     7,   157,  1261,
       7,     7,     6,   443,   444,   445,   161,   154,   693,   161,
     154,     6,     4,   155,   157,     6,     6,     6,   156,     7,
     460,     6,   141,     7,    58,  1287,     6,   467,     7,  1290,
       7,     7,  1294,     7,  1296,     7,  1298,    60,     7,     6,
       4,     7,   155,   155,   155,   155,  1308,     7,     7,     7,
    1312,     6,     4,     6,   161,   154,     7,     6,   161,  1321,
    1322,     7,     7,     7,     6,     6,  1328,     6,     6,     6,
       4,    58,     4,     4,  1336,   162,     6,     4,  1340,   154,
    1294,     6,  1296,   335,  1298,   161,   338,   155,   155,   155,
       7,     6,  1306,   158,     6,  1309,    66,   161,     6,   161,
     161,     6,     6,   161,  1366,     6,     6,     5,     4,     6,
     161,   161,     7,     7,   799,   800,     7,   802,     7,   804,
     805,     7,  1384,   808,   809,  1387,     6,     6,  1390,     6,
     156,     6,  1394,   106,     6,     6,  1398,   155,  1400,   161,
     161,   157,     6,  1405,   161,   585,  1408,   587,  1410,     4,
     158,   160,     6,   593,   594,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     6,
       6,     6,     6,   153,     6,     6,     6,     6,     5,  1441,
       6,     6,   110,     6,     6,   625,  1400,     6,     6,     6,
       6,   443,   444,   445,     6,   160,  1458,   882,   883,   884,
       6,     6,     4,     6,   161,     6,     5,   892,   460,     6,
     158,     7,    12,    13,     6,     6,    56,     6,   903,     6,
       6,     6,  1488,   663,  1486,   665,     6,     6,   161,   669,
     670,   671,   672,   162,     6,   161,     7,   677,   162,   161,
     161,   161,   161,     6,   105,     6,   162,     6,   108,     6,
    1516,     6,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     6,    63,     6,     6,    66,    67,   953,    69,
      70,    71,     6,   161,   959,    75,     6,     6,   161,     6,
     965,   966,   967,     6,   162,    73,   971,   161,     6,     4,
       4,   976,   977,   978,     6,     6,     6,     6,     6,     6,
       6,     6,   102,   103,   104,     6,   162,   992,     6,    12,
      13,   161,   161,   161,     6,   755,     6,  1002,   161,     6,
       6,  1006,     6,     6,     6,     6,     6,     6,   161,     6,
       6,     6,     6,   585,     6,   587,     6,   161,     6,    12,
      13,   781,   782,   783,   784,     6,   161,   161,   161,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   945,
      63,  1366,   162,    66,    67,   952,    69,    70,    71,     3,
       3,  1066,    75,   625,  1059,  1444,  1061,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,   396,    -1,    66,    67,    -1,    69,    70,    71,   102,
     103,   104,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   663,    -1,   665,    -1,    -1,    -1,   669,   670,   671,
     672,  1106,  1107,  1108,  1109,   677,     7,     8,    -1,   102,
     103,   104,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     6,    -1,
      12,    13,   153,    73,  1139,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,
      -1,    -1,  1157,    -1,    -1,    -1,    -1,    -1,    -1,  1164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    63,    -1,   755,    66,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   781,
     782,   783,   784,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,    -1,    -1,    -1,  1231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,  1008,    -1,
      -1,    -1,   153,     6,    -1,  1260,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     162,  1286,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,  1303,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     6,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    58,    -1,    60,    -1,  1352,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,  1137,    -1,    -1,
      -1,  1141,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,  1407,    -1,  1409,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,   149,    -1,  1008,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   162,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1236,    -1,    -1,  1484,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,  1251,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,  1287,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    12,
      13,    58,    -1,    60,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      63,     6,    -1,    66,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    75,    -1,    -1,   122,    -1,    -1,    -1,    -1,
       6,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   102,
     103,   104,   149,    -1,    -1,    -1,    -1,   154,  1398,    -1,
    1400,    -1,   159,    -1,    -1,   162,    -1,     3,     4,     5,
      -1,     7,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,  1251,
       6,  1441,    38,    39,    40,    41,    42,    43,    -1,   162,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,  1287,    -1,    -1,   153,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,  1308,    -1,   153,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,   149,    -1,   151,   152,    -1,   154,    -1,
     156,    -1,   158,   159,    -1,   161,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     3,     4,     5,  1398,   153,  1400,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    58,    -1,
      60,    -1,    -1,    -1,    -1,    -1,  1458,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      -1,    -1,    66,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,   154,    -1,     3,     4,     5,   159,
      -1,   161,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,   162,    -1,
      -1,    12,    13,    -1,    -1,    52,    -1,    -1,    55,    -1,
      -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,     3,
       4,     5,   159,    -1,   161,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     7,   122,    -1,
      -1,   153,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
     154,    -1,     3,     4,    -1,   159,    -1,   161,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,     8,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,   154,    -1,     3,     4,    -1,   159,    -1,
     161,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,
      58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   122,     8,    -1,    -1,   153,    -1,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,   154,    -1,     3,     4,
      -1,   159,    -1,   161,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,     8,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      -1,     3,     4,    -1,   159,    -1,   161,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
     122,    -1,    -1,   153,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,   154,    -1,     3,     4,    -1,   159,    -1,   161,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    84,     3,     4,    87,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     8,    -1,
      -1,    -1,    -1,   122,    -1,    42,    43,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,   154,    -1,     3,     4,     5,
     159,    -1,   161,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
     157,    -1,   159,    -1,   161,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,
       3,     4,    -1,   159,    -1,   161,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,     3,     4,     5,    42,
      43,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,     3,     4,    -1,    -1,    42,    43,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,   157,   122,   159,    -1,   161,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,    -1,
     122,    -1,   159,    -1,   161,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,   154,    -1,     3,     4,    -1,   159,    -1,   161,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
       3,     4,    -1,    42,    43,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    84,    -1,   122,    87,    -1,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,    -1,    -1,    -1,
     149,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   122,
     159,    -1,   161,    -1,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,    -1,    -1,   149,     3,     4,     5,
      -1,   154,    -1,     9,    10,    11,   159,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,     3,     4,
      46,    12,    13,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    63,    -1,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,    -1,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,    -1,    -1,    -1,    -1,   144,   145,
      -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   159,     0,     1,    -1,   122,     4,    -1,
      -1,    -1,    -1,   128,   129,   130,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,   154,
      36,    37,    -1,    -1,   159,    -1,    -1,    -1,    44,    45,
      -1,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    -1,     4,    91,    92,    -1,    -1,    -1,
      96,    -1,    12,    13,    -1,   101,   102,   103,   104,    -1,
      -1,   107,    -1,   109,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    36,    37,    -1,   125,
     126,   127,    -1,    -1,    44,    45,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,    -1,    -1,   107,    -1,   109,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,   126,   127,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
      -1,   162,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   160,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,   157,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,   157,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
     157,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,   157,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,   157,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,   157,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,   157,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
     157,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,   157,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,   157,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,   157,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,   157,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
     157,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,   157,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,   157,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,   157,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,   157,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,   157,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,   157,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
     155,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,   155,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,   155,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
     155,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,   155,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,   155,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
     155,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,   155,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,   155,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
     155,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,   155,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,   155,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,
     155,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,   153,
      -1,   155,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,   153,    -1,   155,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,   153,    -1,   155,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,   153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,   165,   166,     6,     0,     4,    12,    13,    36,
      37,    44,    45,    47,    48,    49,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    91,    92,    96,   101,   102,   103,   104,   107,
     109,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   125,   126,   127,   167,   169,   170,   188,   201,
     206,   209,   210,   211,   212,   213,   214,   215,   235,   236,
     237,   238,   239,   240,     3,     4,     5,     7,     9,    10,
      11,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    38,    39,    40,    41,    42,    43,    46,   116,
     122,   123,   124,   128,   129,   130,   131,   132,   133,   134,
     144,   145,   149,   151,   152,   154,   156,   158,   159,   161,
     186,   187,   241,   242,   254,    13,    58,   154,   154,     6,
     161,     6,     6,     6,     6,   156,   154,   161,   154,   154,
       4,   154,   161,   154,   154,     4,   161,   154,   154,    62,
      58,    58,     6,    58,    58,    55,    58,    60,    60,    52,
      55,    58,    60,    55,    58,    60,    55,    58,   154,    55,
     161,   144,   145,   154,   161,   243,   244,   243,   161,    52,
      55,    58,   161,   243,     4,    52,    56,    66,    58,    60,
      58,    55,     4,   116,   161,     4,     6,    52,    55,    58,
       4,     4,     4,     5,    35,    52,    55,    58,    60,    70,
     145,   154,   161,   206,   215,   241,   246,   247,   248,     4,
     154,   154,   154,     4,   161,   250,     4,   154,   154,     6,
       6,   156,     4,     4,     5,   161,     5,   161,     6,   154,
     161,     4,   156,   158,   163,   187,   161,     5,   254,   154,
     156,   154,   156,   154,   156,   154,   156,   154,   156,   154,
     156,   154,   156,   154,   156,   154,   156,   154,   156,   154,
     156,   154,   156,   154,   156,   154,   156,   154,   156,   154,
     156,   154,   156,   154,   156,   154,   156,   154,   156,   154,
     156,   154,   154,   154,   154,   154,   154,     7,   154,   154,
     154,     4,   241,   241,   241,   161,   241,   157,   161,   241,
       4,   107,   108,     4,     4,   206,   207,   208,   246,     6,
       6,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   153,     6,     6,   241,     5,
       5,   241,   190,   241,   145,   241,   248,   249,   241,   241,
     154,   241,   249,   241,   241,   154,   249,   241,   241,   246,
     154,   161,   154,   154,   247,   247,   247,   154,   202,   203,
     204,   205,   154,   154,   154,   246,   241,     4,   246,   243,
     243,   243,   241,   241,   144,   145,   161,   161,   243,   161,
     161,   161,   144,   145,   154,   208,   243,   161,   154,   161,
     154,   154,   154,   247,   247,   246,   154,     4,     6,   156,
     156,   208,     6,   161,   161,   161,   156,   156,   154,   156,
     156,     5,   161,     5,     5,     5,    52,    55,    58,    60,
     161,   241,   248,   241,   162,   249,     8,   146,     6,     6,
     241,   241,   241,   158,   241,   161,   110,   241,   241,   241,
       6,     6,   208,     6,   208,   246,   246,   156,   241,     4,
     161,   171,     6,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,     4,   253,   254,   253,   253,
     253,   253,   253,   255,   241,   253,   253,   253,   156,   249,
     155,     7,   186,   249,   157,     7,   186,   187,   158,     7,
     156,   162,    52,    55,    58,    60,   201,     6,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,     6,   155,   160,   155,   160,   160,   157,
     160,   189,   155,   146,   160,   162,   155,   155,   241,   155,
     162,   155,   155,   241,   162,   155,   155,     7,   241,   241,
     241,   241,     7,     7,   233,   233,   241,   154,   154,   154,
     154,   241,   241,   241,     7,   161,   155,     6,   160,   160,
     160,   243,   243,   207,   207,   160,   241,   241,   241,   241,
     219,   160,   208,   241,   241,   241,   241,   241,     7,   234,
       6,     7,   241,     6,   241,   241,   162,   249,   249,   249,
     241,   241,   155,   161,   157,   161,   241,     4,   241,   161,
     161,   161,   161,   249,   155,   162,   241,   161,   241,   248,
     155,   155,   155,   107,   160,   208,   161,     8,   155,   157,
     162,   162,   155,   160,   162,   241,   157,   187,   241,     4,
      97,    98,    99,   100,   162,   174,   178,   181,   183,   184,
     155,   157,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   157,   155,   157,   155,   157,
     155,   157,   160,   160,   155,   157,   155,   157,   155,   157,
     155,   157,   155,   157,   155,   157,   160,   160,   160,   160,
     160,   160,   156,   158,   155,   160,   160,   155,   155,   160,
     155,   160,     6,   160,   155,   160,   162,   186,   246,   162,
     158,   186,   187,   254,   241,     6,     4,     4,   161,   251,
     157,   161,   161,   161,   161,     8,     6,   141,   168,   249,
       6,   249,   241,     6,     4,     7,   241,   248,   110,     7,
       7,   155,     7,   110,     7,     7,   155,   110,     7,     7,
     241,   155,   162,   155,   155,   241,   246,     4,   232,     6,
     155,   198,   241,   254,   198,   198,   198,   155,   155,   155,
     246,   249,   158,   243,   241,   241,   162,   162,   241,   243,
     160,   160,   160,    73,    82,    89,    90,    93,    94,   229,
     230,   243,   162,   216,   155,   162,   155,   155,   155,   241,
       6,   241,   155,   157,   157,   162,   162,   162,   157,   157,
     249,   249,   157,   157,   162,   249,   249,   249,   249,   162,
       8,   249,     7,     7,     7,   158,   241,   162,   241,   241,
       7,   158,   161,   246,     6,   157,   158,   187,   253,   162,
     175,   154,   154,   161,   185,     6,   241,   241,   241,   241,
     241,   241,   241,   241,   241,     4,   249,   253,   253,   253,
     241,   253,   155,   241,     6,   157,     4,   107,   108,   241,
       6,     6,     6,     7,   156,   250,   252,     6,   249,   249,
     249,   249,   241,   141,   253,   155,   155,   160,     7,   243,
      58,   246,   246,     7,   246,    58,    60,   246,   246,     7,
      60,   246,   246,     6,     7,     7,     7,     7,    73,   231,
       6,     7,   155,   155,   155,   155,     7,     7,     7,     6,
     162,     4,   160,   160,   160,   162,   162,   243,   243,   243,
       4,     6,   161,   154,     6,    95,     6,    95,   162,   230,
     160,   229,     7,     6,     7,     7,     7,     6,   161,     6,
       6,     6,    58,   241,     6,     6,   162,   162,   162,   162,
     162,   162,   241,   162,   246,   246,   246,     4,   160,     8,
       8,   155,     4,     4,   246,   162,     6,     4,     6,   154,
     241,   241,   245,   246,   161,   155,   157,   155,   157,   155,
     157,   155,   157,   157,   155,   155,   155,   155,   155,   186,
       6,   186,     7,   186,   187,   158,     7,     6,   250,   241,
     160,   162,   162,   162,   162,   162,     6,     6,   168,     6,
     241,   161,   241,   254,     6,   161,    66,   200,   200,   246,
       6,   161,   161,     6,     6,   246,   161,     6,     6,     5,
     246,   246,   246,     4,     6,   246,     7,     7,     7,     7,
     246,   246,   246,     7,     6,     7,   241,   241,   241,   161,
     161,   160,   162,   160,   162,   160,   162,   156,   241,   246,
     241,     6,     6,   241,   243,   162,     5,   161,   246,   161,
     161,   161,   246,   249,   161,     6,   155,   157,     6,     6,
     106,   241,   241,   241,     6,     6,     7,   160,     6,   187,
     172,   241,   160,   160,   160,   162,   173,   241,   158,   246,
     246,   254,   241,     6,     4,   251,     6,   157,   250,     6,
       6,     6,     6,   253,   160,   241,   254,   241,   243,     6,
       6,     6,   241,   241,     6,   241,     5,     6,     6,   110,
     199,   241,     6,   246,   246,   246,   246,     6,     4,     6,
       6,   241,   241,   254,   162,   155,   160,   162,   207,   207,
     243,     6,   220,   243,     6,   221,   243,     6,   222,   241,
     162,   160,   155,   162,   160,     6,   145,   243,     6,   245,
     243,   243,     6,   162,   241,   246,   160,   162,     8,   162,
     155,   161,   241,   254,   246,   155,   160,   241,   241,   246,
     161,   160,   162,     4,     6,     6,     6,     6,     7,     6,
     158,     6,   241,   191,   192,   162,   162,   162,   162,     5,
      56,     6,     6,     6,     6,     6,   161,   161,     6,     6,
     161,   241,   162,   162,   160,   161,   160,   161,   160,   161,
     157,     6,   246,     7,   161,   241,   160,   162,   160,   160,
       6,   162,   105,   241,   241,   249,     6,     6,   162,   176,
     241,   160,   160,   245,   241,     6,   250,   108,   160,   194,
     196,     6,     6,     6,     6,     6,   161,   245,   249,   207,
     160,   162,   241,   243,   229,   241,   243,   229,   241,   243,
     229,     6,   160,   162,   246,   208,   162,   243,     6,   249,
     243,   241,   162,   162,   162,     6,   161,   241,   241,   162,
       6,   241,   160,   162,   195,   160,   162,   197,   241,   162,
     162,   162,   241,   162,   160,   162,   162,   160,   162,   162,
     160,   162,   246,     6,    73,   162,   217,   161,   160,   162,
     160,     6,     6,   173,   155,   160,     6,   161,   160,     4,
       4,   162,     6,     6,   162,     6,   223,   241,     6,     6,
     224,   241,     6,     6,   225,   241,     6,   162,   241,   229,
     208,   249,     6,   243,   249,   162,   179,   241,   245,   241,
       5,   161,   246,     5,   161,   241,   161,   162,   161,   162,
     161,   162,     6,     6,   162,   162,   218,   162,   160,   162,
       6,   161,   155,   162,   162,   193,   241,   255,   229,     6,
     226,   229,     6,   227,   229,     6,   228,   229,     6,   249,
       6,   177,   253,   182,   161,     6,   160,   162,     7,   162,
     162,   161,   162,   161,   162,   161,   162,   162,   160,   162,
     161,   245,   241,   254,     6,   229,     6,   229,     6,   229,
       6,   253,     6,   180,   253,   162,     7,   162,   162,   162,
     160,   162,     6,   254,     6,     6,     6,   253,     6
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
#line 166 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 177 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 178 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 198 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 202 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 209 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 214 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 219 "Gmsh.y"
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
#line 233 "Gmsh.y"
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
#line 246 "Gmsh.y"
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
#line 259 "Gmsh.y"
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
#line 287 "Gmsh.y"
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
#line 301 "Gmsh.y"
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
#line 312 "Gmsh.y"
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
#line 326 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 340 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 342 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 347 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 349 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 354 "Gmsh.y"
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
#line 458 "Gmsh.y"
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
#line 468 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 477 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 484 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 494 "Gmsh.y"
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
#line 503 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 529 "Gmsh.y"
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
#line 537 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 547 "Gmsh.y"
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
#line 566 "Gmsh.y"
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
#line 585 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 591 "Gmsh.y"
    {
    ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 598 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 599 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 600 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 601 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 602 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 606 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 607 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 616 "Gmsh.y"
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
#line 678 "Gmsh.y"
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
#line 708 "Gmsh.y"
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
#line 743 "Gmsh.y"
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
#line 777 "Gmsh.y"
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
#line 825 "Gmsh.y"
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
#line 872 "Gmsh.y"
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
#line 887 "Gmsh.y"
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
#line 903 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 912 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 918 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 927 "Gmsh.y"
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
#line 945 "Gmsh.y"
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
#line 963 "Gmsh.y"
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
#line 972 "Gmsh.y"
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
#line 984 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 989 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 997 "Gmsh.y"
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
#line 1017 "Gmsh.y"
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
#line 1040 "Gmsh.y"
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
#line 1051 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1081 "Gmsh.y"
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
#line 1104 "Gmsh.y"
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
#line 1130 "Gmsh.y"
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
#line 1151 "Gmsh.y"
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
#line 1163 "Gmsh.y"
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
#line 1181 "Gmsh.y"
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
#line 1192 "Gmsh.y"
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
#line 1203 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1205 "Gmsh.y"
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
#line 1215 "Gmsh.y"
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
#line 1226 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1228 "Gmsh.y"
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
#line 1241 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1247 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1259 "Gmsh.y"
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
#line 1270 "Gmsh.y"
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
#line 1285 "Gmsh.y"
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
#line 1301 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1309 "Gmsh.y"
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
#line 1318 "Gmsh.y"
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
#line 1337 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1341 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1351 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1355 "Gmsh.y"
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
#line 1367 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1371 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1381 "Gmsh.y"
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
#line 1404 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 1408 "Gmsh.y"
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
#line 1424 "Gmsh.y"
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
#line 1446 "Gmsh.y"
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
#line 1464 "Gmsh.y"
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
#line 1485 "Gmsh.y"
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
#line 1503 "Gmsh.y"
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
#line 1533 "Gmsh.y"
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
#line 1563 "Gmsh.y"
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
#line 1581 "Gmsh.y"
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
#line 1599 "Gmsh.y"
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
#line 1625 "Gmsh.y"
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
#line 1643 "Gmsh.y"
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
#line 1661 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1665 "Gmsh.y"
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
#line 1684 "Gmsh.y"
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
#line 1702 "Gmsh.y"
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
#line 1741 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1747 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1753 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1760 "Gmsh.y"
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
#line 1785 "Gmsh.y"
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
#line 1810 "Gmsh.y"
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
#line 1827 "Gmsh.y"
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
#line 1845 "Gmsh.y"
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
#line 1875 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1879 "Gmsh.y"
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
#line 1899 "Gmsh.y"
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
#line 1917 "Gmsh.y"
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
#line 1934 "Gmsh.y"
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
#line 1950 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1954 "Gmsh.y"
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
#line 1976 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1981 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1986 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1991 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1996 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2001 "Gmsh.y"
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
#line 2024 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 2030 "Gmsh.y"
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
#line 2040 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2041 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2046 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2050 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2054 "Gmsh.y"
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
#line 2077 "Gmsh.y"
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
#line 2100 "Gmsh.y"
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
#line 2123 "Gmsh.y"
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
#line 2151 "Gmsh.y"
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
#line 2172 "Gmsh.y"
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
#line 2196 "Gmsh.y"
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
#line 2217 "Gmsh.y"
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
#line 2238 "Gmsh.y"
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
#line 2258 "Gmsh.y"
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
#line 2370 "Gmsh.y"
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
#line 2389 "Gmsh.y"
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
#line 2428 "Gmsh.y"
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
#line 2536 "Gmsh.y"
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
#line 2545 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2551 "Gmsh.y"
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
#line 2566 "Gmsh.y"
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
#line 2594 "Gmsh.y"
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
#line 2611 "Gmsh.y"
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
#line 2625 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2631 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2637 "Gmsh.y"
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
#line 2646 "Gmsh.y"
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
#line 2660 "Gmsh.y"
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
#line 2705 "Gmsh.y"
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
#line 2722 "Gmsh.y"
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
#line 2737 "Gmsh.y"
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
#line 2756 "Gmsh.y"
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
#line 2768 "Gmsh.y"
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
#line 2792 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2796 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2801 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2808 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2814 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2819 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2825 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2829 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2833 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2843 "Gmsh.y"
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
#line 2860 "Gmsh.y"
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
#line 2877 "Gmsh.y"
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
#line 2898 "Gmsh.y"
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
#line 2919 "Gmsh.y"
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
#line 2954 "Gmsh.y"
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
#line 2962 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2968 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2975 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2988 "Gmsh.y"
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
#line 2996 "Gmsh.y"
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
#line 3004 "Gmsh.y"
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
#line 3012 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 3017 "Gmsh.y"
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
#line 3025 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 3030 "Gmsh.y"
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
#line 3038 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 3043 "Gmsh.y"
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
#line 3051 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 3056 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 3064 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 3071 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 3078 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3085 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3092 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3099 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3106 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3113 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3127 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3132 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3139 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3144 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3151 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3156 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3168 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3175 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3180 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3187 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3192 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3199 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3204 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3211 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3223 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3228 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3239 "Gmsh.y"
    {
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3242 "Gmsh.y"
    {
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3248 "Gmsh.y"
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
#line 3257 "Gmsh.y"
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
#line 3277 "Gmsh.y"
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
#line 3300 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3304 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3308 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3312 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3320 "Gmsh.y"
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
#line 3339 "Gmsh.y"
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
#line 3351 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3355 "Gmsh.y"
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
#line 3370 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3374 "Gmsh.y"
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
#line 3386 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3390 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3395 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3399 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3406 "Gmsh.y"
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
#line 3462 "Gmsh.y"
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
#line 3532 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 3537 "Gmsh.y"
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
#line 3604 "Gmsh.y"
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
#line 3640 "Gmsh.y"
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
#line 3649 "Gmsh.y"
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
#line 3692 "Gmsh.y"
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
#line 3731 "Gmsh.y"
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
#line 3756 "Gmsh.y"
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
#line 3784 "Gmsh.y"
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
#line 3830 "Gmsh.y"
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
#line 3853 "Gmsh.y"
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
#line 3876 "Gmsh.y"
    {
    ;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 3879 "Gmsh.y"
    {
    ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 3888 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3892 "Gmsh.y"
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
#line 3902 "Gmsh.y"
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
#line 3936 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3937 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3938 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 3943 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3949 "Gmsh.y"
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
#line 3961 "Gmsh.y"
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
#line 3979 "Gmsh.y"
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
#line 4006 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 4007 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 4008 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 4009 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 4010 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 4011 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 4012 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 4013 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 4015 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 4021 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 4022 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 4023 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 4024 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 4025 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 4026 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 4028 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 4029 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 4030 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 4031 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 4032 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 4033 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 4034 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 4035 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 4036 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 4037 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 4038 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 4039 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 4040 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 4041 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 4042 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 4043 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 4044 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 4045 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 4046 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 4047 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 4048 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 4049 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 4050 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 4051 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 4052 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 4055 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 4056 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 4057 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 4058 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 4059 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 4060 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 4061 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 4062 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 4063 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 4064 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 4065 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 4066 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 4067 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 4068 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 4069 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 4070 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 4071 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 4072 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 4073 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 4074 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 4075 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 4084 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4085 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4086 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4087 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4088 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4089 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4090 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4095 "Gmsh.y"
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
#line 4116 "Gmsh.y"
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
#line 4135 "Gmsh.y"
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
#line 4153 "Gmsh.y"
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
#line 4165 "Gmsh.y"
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
#line 4182 "Gmsh.y"
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
#line 4203 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4208 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4213 "Gmsh.y"
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
#line 4223 "Gmsh.y"
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
#line 4233 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4238 "Gmsh.y"
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
#line 4247 "Gmsh.y"
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

  case 380:

/* Line 1464 of yacc.c  */
#line 4274 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4278 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4282 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4286 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4290 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4297 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4301 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4305 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4309 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4321 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4328 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4333 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4337 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4342 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4346 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4354 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4365 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4369 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4381 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4389 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4397 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4404 "Gmsh.y"
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

  case 403:

/* Line 1464 of yacc.c  */
#line 4414 "Gmsh.y"
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

  case 404:

/* Line 1464 of yacc.c  */
#line 4434 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4438 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4442 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 4446 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 4450 "Gmsh.y"
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

  case 409:

/* Line 1464 of yacc.c  */
#line 4479 "Gmsh.y"
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

  case 410:

/* Line 1464 of yacc.c  */
#line 4508 "Gmsh.y"
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

  case 411:

/* Line 1464 of yacc.c  */
#line 4537 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4566 "Gmsh.y"
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
#line 4576 "Gmsh.y"
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
#line 4586 "Gmsh.y"
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
#line 4599 "Gmsh.y"
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
#line 4611 "Gmsh.y"
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

  case 417:

/* Line 1464 of yacc.c  */
#line 4623 "Gmsh.y"
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
#line 4642 "Gmsh.y"
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
#line 4663 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4668 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4672 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 4676 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4688 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4692 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4704 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 4711 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4721 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 4725 "Gmsh.y"
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

  case 429:

/* Line 1464 of yacc.c  */
#line 4740 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 4745 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 4756 "Gmsh.y"
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

  case 433:

/* Line 1464 of yacc.c  */
#line 4769 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4777 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4788 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4792 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 4800 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4808 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4816 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 4824 "Gmsh.y"
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

  case 441:

/* Line 1464 of yacc.c  */
#line 4838 "Gmsh.y"
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

  case 442:

/* Line 1464 of yacc.c  */
#line 4852 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 4856 "Gmsh.y"
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

  case 444:

/* Line 1464 of yacc.c  */
#line 4878 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 4883 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10767 "Gmsh.tab.cpp"
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
#line 4886 "Gmsh.y"


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

