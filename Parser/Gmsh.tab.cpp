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
#define YYLAST   7832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  438
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1502

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
     275,   285,   289,   296,   301,   308,   318,   325,   335,   341,
     350,   359,   371,   378,   388,   394,   402,   412,   422,   434,
     442,   452,   462,   463,   465,   466,   470,   476,   477,   487,
     493,   494,   504,   508,   514,   515,   518,   522,   528,   532,
     533,   536,   540,   544,   550,   552,   554,   555,   561,   562,
     565,   573,   574,   584,   591,   599,   604,   612,   621,   630,
     638,   646,   658,   667,   676,   677,   687,   696,   706,   710,
     715,   726,   734,   742,   751,   760,   773,   774,   784,   793,
     801,   810,   811,   821,   827,   839,   845,   855,   865,   870,
     880,   890,   892,   894,   895,   898,   905,   912,   919,   926,
     935,   946,   961,   978,   991,  1000,  1009,  1016,  1031,  1036,
    1043,  1050,  1054,  1059,  1065,  1069,  1073,  1078,  1083,  1087,
    1095,  1103,  1107,  1115,  1119,  1122,  1125,  1128,  1131,  1147,
    1150,  1153,  1156,  1159,  1166,  1175,  1184,  1195,  1197,  1200,
    1202,  1206,  1211,  1213,  1219,  1231,  1245,  1246,  1254,  1255,
    1269,  1270,  1286,  1287,  1294,  1303,  1312,  1321,  1334,  1347,
    1360,  1375,  1390,  1405,  1406,  1419,  1420,  1433,  1434,  1447,
    1448,  1465,  1466,  1483,  1484,  1501,  1502,  1521,  1522,  1541,
    1542,  1561,  1563,  1566,  1572,  1580,  1590,  1593,  1596,  1600,
    1603,  1607,  1617,  1624,  1625,  1629,  1630,  1632,  1633,  1636,
    1637,  1640,  1648,  1655,  1664,  1670,  1674,  1682,  1688,  1695,
    1702,  1715,  1726,  1737,  1748,  1759,  1762,  1766,  1773,  1775,
    1777,  1780,  1786,  1794,  1805,  1807,  1811,  1814,  1817,  1820,
    1824,  1828,  1832,  1836,  1840,  1844,  1848,  1852,  1856,  1860,
    1864,  1868,  1872,  1876,  1882,  1887,  1892,  1897,  1902,  1907,
    1912,  1917,  1922,  1927,  1932,  1939,  1944,  1949,  1954,  1959,
    1964,  1969,  1976,  1983,  1990,  1995,  2000,  2005,  2010,  2015,
    2020,  2025,  2030,  2035,  2040,  2045,  2052,  2057,  2062,  2067,
    2072,  2077,  2082,  2089,  2096,  2103,  2108,  2110,  2112,  2114,
    2116,  2118,  2120,  2122,  2124,  2130,  2135,  2140,  2143,  2149,
    2153,  2160,  2165,  2173,  2180,  2187,  2189,  2192,  2195,  2199,
    2203,  2215,  2225,  2233,  2241,  2243,  2247,  2249,  2251,  2254,
    2258,  2263,  2269,  2271,  2273,  2276,  2280,  2284,  2290,  2295,
    2298,  2301,  2304,  2307,  2313,  2319,  2325,  2331,  2333,  2335,
    2339,  2344,  2351,  2353,  2355,  2359,  2363,  2373,  2381,  2383,
    2389,  2393,  2400,  2402,  2406,  2408,  2410,  2414,  2421,  2423,
    2425,  2430,  2437,  2444,  2449,  2454,  2459,  2466,  2468
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
     155,   184,   239,     6,    -1,     4,   154,   159,   247,   160,
     155,   184,   244,     6,    -1,     4,   185,     6,    -1,     4,
     154,   239,   155,   185,     6,    -1,     4,     7,   252,     6,
      -1,     4,   156,     4,     7,   252,     6,    -1,     4,   154,
     239,   155,   156,     4,     7,   252,     6,    -1,     4,   156,
       4,   184,   239,     6,    -1,     4,   154,   239,   155,   156,
       4,   184,   239,     6,    -1,     4,   156,     4,   185,     6,
      -1,     4,   154,   239,   155,   156,     4,   185,     6,    -1,
       4,   156,   106,   156,     4,     7,   248,     6,    -1,     4,
     154,   239,   155,   156,   106,   156,     4,     7,   248,     6,
      -1,     4,   156,   107,     7,   249,     6,    -1,     4,   154,
     239,   155,   156,   107,     7,   249,     6,    -1,     4,   115,
       7,   239,     6,    -1,   115,   154,   239,   155,     7,     4,
       6,    -1,   115,   154,   239,   155,   156,     4,     7,   239,
       6,    -1,   115,   154,   239,   155,   156,     4,     7,   252,
       6,    -1,   115,   154,   239,   155,   156,     4,     7,   159,
     247,   160,     6,    -1,   115,   154,   239,   155,   156,     4,
       6,    -1,    73,   152,     4,   153,   156,     4,     7,   239,
       6,    -1,    73,   152,     4,   153,   156,     4,     7,   252,
       6,    -1,    -1,   158,    -1,    -1,   188,   187,     4,    -1,
     188,   187,     4,     7,   239,    -1,    -1,   188,   187,     4,
       7,   159,   239,   189,   192,   160,    -1,   188,   187,     4,
       7,   252,    -1,    -1,   188,   187,     4,     7,   159,   252,
     190,   194,   160,    -1,   239,     7,   252,    -1,   191,   158,
     239,     7,   252,    -1,    -1,   192,   193,    -1,   158,     4,
     244,    -1,   158,     4,   159,   191,   160,    -1,   158,     4,
       5,    -1,    -1,   194,   195,    -1,   158,     4,   239,    -1,
     158,     4,     5,    -1,   158,     4,   159,   253,   160,    -1,
     239,    -1,   252,    -1,    -1,   109,    55,   159,   239,   160,
      -1,    -1,    65,   241,    -1,    51,   152,   239,   153,     7,
     241,     6,    -1,    -1,    69,    51,   200,   152,   196,   153,
       7,   244,     6,    -1,    60,    61,   244,     7,   239,     6,
      -1,    54,   152,   239,   153,     7,   244,     6,    -1,    74,
      54,   244,     6,    -1,    58,   152,   239,   153,     7,   244,
       6,    -1,    52,   152,   239,   153,     7,   244,   198,     6,
      -1,    53,   152,   239,   153,     7,   244,   198,     6,    -1,
     101,   152,   239,   153,     7,   244,     6,    -1,   102,   152,
     239,   153,     7,   244,     6,    -1,   103,   152,   239,   153,
       7,   244,   105,   244,   104,   239,     6,    -1,    54,     4,
     152,   239,   153,     7,   244,     6,    -1,    70,    54,   152,
     239,   153,     7,   244,     6,    -1,    -1,    69,    54,   201,
     152,   196,   153,     7,   244,     6,    -1,    65,    57,   152,
     239,   153,     7,   244,     6,    -1,    66,    57,   152,   239,
     153,     7,   244,   197,     6,    -1,    12,    13,     6,    -1,
      13,    57,   239,     6,    -1,    62,    57,   152,   239,   153,
       7,     5,     5,     5,     6,    -1,    55,   152,   239,   153,
       7,   244,     6,    -1,    56,   152,   239,   153,     7,   244,
       6,    -1,    57,     4,   152,   239,   153,     7,   244,     6,
      -1,    70,    57,   152,   239,   153,     7,   244,     6,    -1,
      70,    57,   152,   239,   153,     7,   244,     4,   159,   243,
     160,     6,    -1,    -1,    69,    57,   202,   152,   196,   153,
       7,   244,     6,    -1,    68,    59,   152,   239,   153,     7,
     244,     6,    -1,    59,   152,   239,   153,     7,   244,     6,
      -1,    70,    59,   152,   239,   153,     7,   244,     6,    -1,
      -1,    69,    59,   203,   152,   196,   153,     7,   244,     6,
      -1,    76,   241,   159,   205,   160,    -1,    75,   159,   241,
     158,   241,   158,   239,   160,   159,   205,   160,    -1,    77,
     241,   159,   205,   160,    -1,    78,   159,   241,   158,   239,
     160,   159,   205,   160,    -1,    78,   159,   241,   158,   241,
     160,   159,   205,   160,    -1,     4,   159,   205,   160,    -1,
      86,    54,   159,   247,   160,    57,   159,   239,   160,    -1,
      83,    54,   152,   239,   153,   159,   247,   160,     6,    -1,
     206,    -1,   204,    -1,    -1,   206,   199,    -1,   206,    51,
     159,   247,   160,     6,    -1,   206,    54,   159,   247,   160,
       6,    -1,   206,    57,   159,   247,   160,     6,    -1,   206,
      59,   159,   247,   160,     6,    -1,    80,    65,   152,   239,
     153,     7,   244,     6,    -1,    80,    51,   152,   239,   153,
       7,   159,   243,   160,     6,    -1,    80,    65,   152,   239,
     153,     7,   159,   241,   158,   241,   158,   247,   160,     6,
      -1,    80,    65,   152,   239,   153,     7,   159,   241,   158,
     241,   158,   241,   158,   247,   160,     6,    -1,    80,    55,
     152,   239,   153,     7,   159,   241,   158,   247,   160,     6,
      -1,    80,     4,   152,   239,   153,     7,   244,     6,    -1,
      80,     4,   152,   239,   153,     7,     5,     6,    -1,    80,
       4,   159,   239,   160,     6,    -1,    80,     4,   152,   239,
     153,     7,   159,   241,   158,   241,   158,   247,   160,     6,
      -1,    84,   159,   206,   160,    -1,    84,   115,   154,   239,
     155,     6,    -1,    84,     4,   154,   239,   155,     6,    -1,
      84,     4,     6,    -1,    84,     4,     4,     6,    -1,   106,
     248,   159,   206,   160,    -1,   119,     5,     6,    -1,   120,
       5,     6,    -1,   119,   159,   206,   160,    -1,   120,   159,
     206,   160,    -1,     4,   252,     6,    -1,     4,     4,   154,
     239,   155,   251,     6,    -1,     4,     4,     4,   154,   239,
     155,     6,    -1,     4,   239,     6,    -1,    73,   152,     4,
     153,   156,     4,     6,    -1,   100,     4,     6,    -1,   113,
       6,    -1,   114,     6,    -1,    46,     6,    -1,    43,     6,
      -1,    43,   159,   239,   158,   239,   158,   239,   158,   239,
     158,   239,   158,   239,   160,     6,    -1,    44,     6,    -1,
      47,     6,    -1,    48,     6,    -1,    64,     6,    -1,   108,
     152,   239,     8,   239,   153,    -1,   108,   152,   239,     8,
     239,     8,   239,   153,    -1,   108,     4,   109,   159,   239,
       8,   239,   160,    -1,   108,     4,   109,   159,   239,     8,
     239,     8,   239,   160,    -1,   110,    -1,   118,     4,    -1,
     116,    -1,   117,     4,     6,    -1,   111,   152,   239,   153,
      -1,   112,    -1,    79,   241,   159,   206,   160,    -1,    79,
     159,   241,   158,   241,   158,   239,   160,   159,   206,   160,
      -1,    79,   159,   241,   158,   241,   158,   241,   158,   239,
     160,   159,   206,   160,    -1,    -1,    79,   241,   159,   206,
     214,   227,   160,    -1,    -1,    79,   159,   241,   158,   241,
     158,   239,   160,   159,   206,   215,   227,   160,    -1,    -1,
      79,   159,   241,   158,   241,   158,   241,   158,   239,   160,
     159,   206,   216,   227,   160,    -1,    -1,    79,   159,   206,
     217,   227,   160,    -1,    79,    51,   159,   239,   158,   241,
     160,     6,    -1,    79,    54,   159,   239,   158,   241,   160,
       6,    -1,    79,    57,   159,   239,   158,   241,   160,     6,
      -1,    79,    51,   159,   239,   158,   241,   158,   241,   158,
     239,   160,     6,    -1,    79,    54,   159,   239,   158,   241,
     158,   241,   158,   239,   160,     6,    -1,    79,    57,   159,
     239,   158,   241,   158,   241,   158,   239,   160,     6,    -1,
      79,    51,   159,   239,   158,   241,   158,   241,   158,   241,
     158,   239,   160,     6,    -1,    79,    54,   159,   239,   158,
     241,   158,   241,   158,   241,   158,   239,   160,     6,    -1,
      79,    57,   159,   239,   158,   241,   158,   241,   158,   241,
     158,   239,   160,     6,    -1,    -1,    79,    51,   159,   239,
     158,   241,   160,   218,   159,   227,   160,     6,    -1,    -1,
      79,    54,   159,   239,   158,   241,   160,   219,   159,   227,
     160,     6,    -1,    -1,    79,    57,   159,   239,   158,   241,
     160,   220,   159,   227,   160,     6,    -1,    -1,    79,    51,
     159,   239,   158,   241,   158,   241,   158,   239,   160,   221,
     159,   227,   160,     6,    -1,    -1,    79,    54,   159,   239,
     158,   241,   158,   241,   158,   239,   160,   222,   159,   227,
     160,     6,    -1,    -1,    79,    57,   159,   239,   158,   241,
     158,   241,   158,   239,   160,   223,   159,   227,   160,     6,
      -1,    -1,    79,    51,   159,   239,   158,   241,   158,   241,
     158,   241,   158,   239,   160,   224,   159,   227,   160,     6,
      -1,    -1,    79,    54,   159,   239,   158,   241,   158,   241,
     158,   241,   158,   239,   160,   225,   159,   227,   160,     6,
      -1,    -1,    79,    57,   159,   239,   158,   241,   158,   241,
     158,   241,   158,   239,   160,   226,   159,   227,   160,     6,
      -1,   228,    -1,   227,   228,    -1,    88,   159,   239,   160,
       6,    -1,    88,   159,   244,   158,   244,   160,     6,    -1,
      88,   159,   244,   158,   244,   158,   244,   160,     6,    -1,
      81,     6,    -1,    92,     6,    -1,    92,    94,     6,    -1,
      93,     6,    -1,    93,    94,     6,    -1,    89,   152,   239,
     153,     7,   244,    72,   239,     6,    -1,    72,     4,   154,
     239,   155,     6,    -1,    -1,    72,     4,   239,    -1,    -1,
       4,    -1,    -1,     7,   244,    -1,    -1,     7,   239,    -1,
      67,    54,   245,     7,   239,   229,     6,    -1,    67,    57,
     245,   231,   230,     6,    -1,    63,    57,   159,   239,   160,
       7,   244,     6,    -1,    67,    59,   245,   231,     6,    -1,
      95,   245,     6,    -1,    87,    57,   159,   247,   160,   239,
       6,    -1,    81,    57,   245,   232,     6,    -1,    82,    57,
     244,     7,   239,     6,    -1,    71,    54,   244,     7,   244,
       6,    -1,    71,    57,   239,   159,   247,   160,     7,   239,
     159,   247,   160,     6,    -1,    51,   159,   247,   160,   109,
      57,   159,   239,   160,     6,    -1,    54,   159,   247,   160,
     109,    57,   159,   239,   160,     6,    -1,    54,   159,   247,
     160,   109,    59,   159,   239,   160,     6,    -1,    57,   159,
     247,   160,   109,    59,   159,   239,   160,     6,    -1,    85,
       6,    -1,    85,     4,     6,    -1,    85,    51,   159,   247,
     160,     6,    -1,   124,    -1,   125,    -1,   237,     6,    -1,
     237,   159,   244,   160,     6,    -1,   237,   159,   244,   158,
     244,   160,     6,    -1,   237,   152,   244,   153,   159,   244,
     158,   244,   160,     6,    -1,   240,    -1,   152,   239,   153,
      -1,   143,   239,    -1,   142,   239,    -1,   147,   239,    -1,
     239,   143,   239,    -1,   239,   142,   239,    -1,   239,   144,
     239,    -1,   239,   145,   239,    -1,   239,   146,   239,    -1,
     239,   151,   239,    -1,   239,   138,   239,    -1,   239,   139,
     239,    -1,   239,   141,   239,    -1,   239,   140,   239,    -1,
     239,   137,   239,    -1,   239,   136,   239,    -1,   239,   135,
     239,    -1,   239,   134,   239,    -1,   239,   133,   239,     8,
     239,    -1,    14,   152,   239,   153,    -1,    15,   152,   239,
     153,    -1,    16,   152,   239,   153,    -1,    17,   152,   239,
     153,    -1,    18,   152,   239,   153,    -1,    19,   152,   239,
     153,    -1,    20,   152,   239,   153,    -1,    21,   152,   239,
     153,    -1,    22,   152,   239,   153,    -1,    24,   152,   239,
     153,    -1,    25,   152,   239,   158,   239,   153,    -1,    26,
     152,   239,   153,    -1,    27,   152,   239,   153,    -1,    28,
     152,   239,   153,    -1,    29,   152,   239,   153,    -1,    30,
     152,   239,   153,    -1,    31,   152,   239,   153,    -1,    32,
     152,   239,   158,   239,   153,    -1,    33,   152,   239,   158,
     239,   153,    -1,    34,   152,   239,   158,   239,   153,    -1,
      23,   152,   239,   153,    -1,    14,   154,   239,   155,    -1,
      15,   154,   239,   155,    -1,    16,   154,   239,   155,    -1,
      17,   154,   239,   155,    -1,    18,   154,   239,   155,    -1,
      19,   154,   239,   155,    -1,    20,   154,   239,   155,    -1,
      21,   154,   239,   155,    -1,    22,   154,   239,   155,    -1,
      24,   154,   239,   155,    -1,    25,   154,   239,   158,   239,
     155,    -1,    26,   154,   239,   155,    -1,    27,   154,   239,
     155,    -1,    28,   154,   239,   155,    -1,    29,   154,   239,
     155,    -1,    30,   154,   239,   155,    -1,    31,   154,   239,
     155,    -1,    32,   154,   239,   158,   239,   155,    -1,    33,
     154,   239,   158,   239,   155,    -1,    34,   154,   239,   158,
     239,   155,    -1,    23,   154,   239,   155,    -1,     3,    -1,
       9,    -1,    10,    -1,    11,    -1,   126,    -1,   127,    -1,
     128,    -1,     4,    -1,     4,   161,   159,   239,   160,    -1,
       4,   154,   239,   155,    -1,   157,     4,   154,   155,    -1,
       4,   185,    -1,     4,   154,   239,   155,   185,    -1,     4,
     156,     4,    -1,     4,   154,   239,   155,   156,     4,    -1,
       4,   156,     4,   185,    -1,     4,   154,   239,   155,   156,
       4,   185,    -1,   121,   152,   251,   158,   239,   153,    -1,
      42,   152,   251,   158,   251,   153,    -1,   242,    -1,   143,
     241,    -1,   142,   241,    -1,   241,   143,   241,    -1,   241,
     142,   241,    -1,   159,   239,   158,   239,   158,   239,   158,
     239,   158,   239,   160,    -1,   159,   239,   158,   239,   158,
     239,   158,   239,   160,    -1,   159,   239,   158,   239,   158,
     239,   160,    -1,   152,   239,   158,   239,   158,   239,   153,
      -1,   244,    -1,   243,   158,   244,    -1,   239,    -1,   246,
      -1,   159,   160,    -1,   159,   247,   160,    -1,   143,   159,
     247,   160,    -1,   239,   144,   159,   247,   160,    -1,   244,
      -1,     5,    -1,   143,   246,    -1,   239,   144,   246,    -1,
     239,     8,   239,    -1,   239,     8,   239,     8,   239,    -1,
      51,   159,   239,   160,    -1,    51,     5,    -1,    54,     5,
      -1,    57,     5,    -1,    59,     5,    -1,    69,    51,   159,
     247,   160,    -1,    69,    54,   159,   247,   160,    -1,    69,
      57,   159,   247,   160,    -1,    69,    59,   159,   247,   160,
      -1,   204,    -1,   213,    -1,     4,   154,   155,    -1,    35,
     154,     4,   155,    -1,     4,   154,   159,   247,   160,   155,
      -1,   239,    -1,   246,    -1,   247,   158,   239,    -1,   247,
     158,   246,    -1,   159,   239,   158,   239,   158,   239,   158,
     239,   160,    -1,   159,   239,   158,   239,   158,   239,   160,
      -1,     4,    -1,     4,   156,   106,   156,     4,    -1,   159,
     250,   160,    -1,     4,   154,   239,   155,   156,   107,    -1,
     248,    -1,   250,   158,   248,    -1,   252,    -1,     4,    -1,
       4,   156,     4,    -1,     4,   154,   239,   155,   156,     4,
      -1,     5,    -1,    45,    -1,   122,   152,   251,   153,    -1,
     123,   152,   251,   158,   251,   153,    -1,    39,   152,   251,
     158,   251,   153,    -1,    40,   152,   251,   153,    -1,    41,
     152,   251,   153,    -1,    38,   152,   251,   153,    -1,    38,
     152,   251,   158,   247,   153,    -1,   251,    -1,   253,   158,
     251,    -1
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
     598,   599,   600,   601,   605,   606,   612,   614,   677,   707,
     740,   786,   801,   817,   826,   832,   841,   859,   877,   886,
     898,   903,   911,   931,   954,   965,   973,   995,  1018,  1044,
    1065,  1077,  1091,  1091,  1093,  1095,  1106,  1118,  1117,  1129,
    1141,  1140,  1155,  1161,  1168,  1169,  1173,  1184,  1199,  1209,
    1210,  1215,  1223,  1232,  1251,  1255,  1266,  1269,  1282,  1285,
    1295,  1319,  1318,  1338,  1360,  1378,  1399,  1417,  1447,  1477,
    1495,  1513,  1539,  1557,  1576,  1575,  1598,  1616,  1655,  1661,
    1667,  1674,  1699,  1724,  1741,  1758,  1790,  1789,  1813,  1831,
    1848,  1865,  1864,  1890,  1895,  1900,  1905,  1910,  1915,  1938,
    1944,  1955,  1956,  1961,  1964,  1968,  1991,  2014,  2037,  2065,
    2086,  2109,  2130,  2152,  2172,  2284,  2303,  2341,  2450,  2459,
    2465,  2480,  2508,  2525,  2539,  2545,  2551,  2560,  2574,  2619,
    2636,  2651,  2670,  2682,  2706,  2710,  2715,  2722,  2728,  2733,
    2739,  2743,  2747,  2757,  2774,  2791,  2812,  2833,  2868,  2876,
    2882,  2889,  2893,  2902,  2910,  2918,  2927,  2926,  2940,  2939,
    2953,  2952,  2966,  2965,  2978,  2985,  2992,  2999,  3006,  3013,
    3020,  3027,  3034,  3042,  3041,  3054,  3053,  3066,  3065,  3078,
    3077,  3090,  3089,  3102,  3101,  3114,  3113,  3126,  3125,  3138,
    3137,  3153,  3156,  3162,  3171,  3191,  3214,  3218,  3222,  3226,
    3230,  3234,  3253,  3266,  3269,  3285,  3288,  3301,  3304,  3310,
    3313,  3320,  3376,  3446,  3451,  3518,  3554,  3563,  3606,  3631,
    3658,  3702,  3725,  3748,  3751,  3760,  3764,  3774,  3809,  3810,
    3814,  3819,  3830,  3847,  3875,  3876,  3877,  3878,  3879,  3880,
    3881,  3882,  3883,  3890,  3891,  3892,  3893,  3894,  3895,  3896,
    3897,  3898,  3899,  3900,  3901,  3902,  3903,  3904,  3905,  3906,
    3907,  3908,  3909,  3910,  3911,  3912,  3913,  3914,  3915,  3916,
    3917,  3918,  3919,  3920,  3921,  3923,  3924,  3925,  3926,  3927,
    3928,  3929,  3930,  3931,  3932,  3933,  3934,  3935,  3936,  3937,
    3938,  3939,  3940,  3941,  3942,  3943,  3952,  3953,  3954,  3955,
    3956,  3957,  3958,  3962,  3982,  4001,  4019,  4031,  4048,  4069,
    4074,  4079,  4089,  4099,  4104,  4116,  4120,  4124,  4128,  4132,
    4139,  4143,  4147,  4151,  4158,  4163,  4170,  4175,  4179,  4184,
    4188,  4196,  4207,  4211,  4223,  4231,  4239,  4246,  4257,  4277,
    4281,  4285,  4289,  4293,  4311,  4329,  4347,  4365,  4375,  4385,
    4397,  4409,  4430,  4435,  4439,  4443,  4455,  4459,  4471,  4478,
    4488,  4492,  4507,  4512,  4519,  4523,  4536,  4544,  4555,  4559,
    4567,  4575,  4583,  4591,  4605,  4619,  4623,  4645,  4650
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
     186,   186,   187,   187,   188,   188,   188,   189,   188,   188,
     190,   188,   191,   191,   192,   192,   193,   193,   193,   194,
     194,   195,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   200,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   201,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   202,   199,   199,   199,
     199,   203,   199,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   205,   206,   206,   206,   206,   206,   206,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   208,   208,
     208,   208,   208,   209,   210,   210,   210,   210,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   213,   213,   213,   214,   213,   215,   213,
     216,   213,   217,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   218,   213,   219,   213,   220,   213,   221,
     213,   222,   213,   223,   213,   224,   213,   225,   213,   226,
     213,   227,   227,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   229,   229,   230,   230,   231,   231,   232,
     232,   233,   233,   233,   233,   233,   233,   233,   233,   234,
     234,   235,   235,   235,   235,   236,   236,   236,   237,   237,
     238,   238,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   241,   241,   241,   241,
     242,   242,   242,   242,   243,   243,   244,   244,   244,   244,
     244,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   247,   247,   247,   247,   248,   248,   248,   248,
     249,   249,   250,   250,   251,   251,   251,   251,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   253,   253
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
       9,     9,     0,     1,     0,     3,     5,     0,     9,     5,
       0,     9,     3,     5,     0,     2,     3,     5,     3,     0,
       2,     3,     3,     5,     1,     1,     0,     5,     0,     2,
       7,     0,     9,     6,     7,     4,     7,     8,     8,     7,
       7,    11,     8,     8,     0,     9,     8,     9,     3,     4,
      10,     7,     7,     8,     8,    12,     0,     9,     8,     7,
       8,     0,     9,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     6,     6,     6,     8,
      10,    14,    16,    12,     8,     8,     6,    14,     4,     6,
       6,     3,     4,     5,     3,     3,     4,     4,     3,     7,
       7,     3,     7,     3,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     3,     2,
       3,     9,     6,     0,     3,     0,     1,     0,     2,     0,
       2,     7,     6,     8,     5,     3,     7,     5,     6,     6,
      12,    10,    10,    10,    10,     2,     3,     6,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     2,     5,     3,
       6,     4,     7,     6,     6,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     5,     5,     5,     5,     1,     1,     3,
       4,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       4,     6,     6,     4,     4,     4,     6,     1,     3
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
       0,   207,     0,   212,     0,     0,     0,   209,     0,     0,
       0,     0,   288,   289,     5,     7,     6,     8,     9,    10,
      21,    11,    12,    13,    20,    19,    14,    15,    16,    17,
      18,     0,    22,   356,   363,   428,    59,   357,   358,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
       0,   360,   361,   362,    63,    62,    61,    60,     0,     0,
       0,    65,    64,     0,     0,     0,     0,   163,     0,     0,
       0,   294,     0,     0,     0,     0,     0,   197,     0,   199,
     196,   200,   201,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,   121,   134,   146,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   375,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,   285,     0,     0,     0,     0,     0,   363,
     393,     0,     0,     0,     0,     0,     0,     0,     0,   407,
     408,   386,   392,     0,   387,     0,     0,     0,     0,   418,
       0,     0,     0,     0,     0,   194,   195,     0,     0,   208,
       0,   163,     0,   163,   290,     0,     0,     0,     0,     0,
       0,   367,    34,   428,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,   297,   296,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,   161,     0,    71,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   138,     0,     0,     0,     0,    92,     0,     0,   412,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   377,   376,     0,     0,     0,     0,
     163,   163,     0,     0,     0,     0,     0,     0,     0,   222,
       0,   163,     0,     0,     0,     0,     0,   269,     0,     0,
       0,   181,     0,     0,     0,   286,     0,     0,     0,     0,
       0,     0,     0,   399,     0,   400,   401,   402,     0,     0,
       0,     0,     0,   296,   394,   388,     0,     0,     0,   275,
     193,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,   210,   184,     0,   185,     0,     0,     0,     0,     0,
     369,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   425,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,    59,
       0,     0,     0,    59,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,   164,    67,     0,   312,   311,   310,
     309,   305,   306,   308,   307,   300,   299,   301,   302,   303,
     304,   139,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,   379,
     378,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,   178,     0,     0,     0,     0,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   389,
     396,     0,   301,   395,     0,     0,     0,     0,     0,     0,
       0,     0,   211,     0,   186,   187,     0,     0,     0,     0,
     365,   371,     0,    44,     0,     0,     0,    57,     0,    35,
      36,    37,    38,    39,   314,   335,   315,   336,   316,   337,
     317,   338,   318,   339,   319,   340,   320,   341,   321,   342,
     322,   343,   334,   355,   323,   344,     0,     0,   325,   346,
     326,   347,   327,   348,   328,   349,   329,   350,   330,   351,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,   433,   434,     0,    84,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
     366,     0,     0,     0,     0,     0,    25,    23,     0,     0,
      26,     0,     0,    66,    95,     0,   414,   415,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   268,   266,     0,   274,
       0,     0,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,     0,   213,     0,     0,     0,     0,     0,     0,   270,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,   410,   398,     0,     0,     0,     0,   390,     0,
       0,     0,     0,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,   291,     0,     0,   368,     0,   364,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
      68,     0,     0,     0,     0,     0,    72,    74,    76,     0,
       0,   422,     0,    82,     0,     0,     0,     0,   313,    24,
       0,     0,     0,     0,     0,     0,     0,   118,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
     257,     0,   259,     0,   223,   252,     0,     0,     0,   176,
       0,     0,     0,   278,     0,   180,   179,   287,     0,     0,
      32,    33,     0,   403,   404,   405,   406,   397,   391,     0,
       0,     0,   419,     0,     0,     0,   203,     0,     0,     0,
       0,   190,   370,   189,     0,     0,     0,     0,   384,     0,
     324,   345,   331,   352,   332,   353,   333,   354,     0,   436,
     432,   374,   373,   431,     0,    59,     0,     0,     0,     0,
      69,     0,     0,     0,   420,     0,     0,     0,     0,    27,
      28,     0,    29,     0,     0,    96,    99,   120,     0,     0,
       0,     0,     0,   124,     0,     0,   141,   142,     0,     0,
     126,   149,     0,     0,     0,   116,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,     0,   163,   163,     0,   233,     0,   235,     0,   237,
       0,   386,     0,     0,   258,   260,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   411,
     129,   130,     0,     0,     0,     0,    85,    89,     0,     0,
     292,   372,     0,    40,     0,     0,     0,     0,     0,    42,
       0,     0,     0,     0,    79,     0,     0,    80,     0,   423,
     165,   166,   167,   168,     0,     0,    97,   100,     0,   119,
     127,   128,   132,     0,     0,   143,     0,     0,   273,   136,
       0,     0,   264,   148,     0,     0,     0,     0,   133,     0,
     144,   150,     0,     0,     0,     0,   383,     0,   382,     0,
       0,     0,   224,     0,     0,   225,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,   174,
       0,     0,     0,   169,     0,     0,     0,     0,   417,     0,
     205,   204,     0,     0,     0,     0,    45,     0,     0,     0,
     385,     0,     0,     0,   427,    70,    75,    77,     0,    83,
       0,    30,     0,   104,   109,     0,     0,     0,     0,     0,
       0,   137,   122,   135,   147,   152,     0,     0,    90,    91,
     163,     0,   156,   157,     0,     0,     0,     0,     0,     0,
       0,   253,     0,     0,   163,     0,     0,     0,     0,     0,
     160,   159,     0,     0,     0,     0,    86,    87,     0,     0,
      41,     0,     0,     0,    43,    58,     0,   421,     0,     0,
       0,   281,   282,   283,   284,   140,     0,     0,     0,     0,
       0,   381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   218,     0,     0,   170,     0,
       0,     0,   416,   206,     0,   293,     0,     0,     0,     0,
      81,     0,     0,    98,   105,     0,   101,   110,     0,     0,
       0,   154,     0,   239,     0,     0,   241,     0,     0,   243,
       0,     0,     0,   254,     0,   214,     0,   163,     0,     0,
       0,   131,    88,     0,    49,     0,    55,     0,     0,     0,
       0,   117,   145,   280,   380,   227,     0,     0,   234,   228,
       0,     0,   236,   229,     0,     0,   238,     0,     0,     0,
     220,     0,   173,     0,     0,     0,     0,     0,     0,     0,
     108,     0,   106,   112,     0,   111,     0,   245,     0,   247,
       0,   249,   255,   261,   219,   215,     0,     0,     0,     0,
      46,     0,    53,     0,     0,     0,   412,   437,     0,     0,
     230,     0,     0,   231,     0,     0,   232,     0,     0,   177,
       0,   171,     0,    47,     0,     0,   198,     0,   107,     0,
       0,   113,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,     0,     0,   102,   438,   240,     0,   242,
       0,   244,     0,   172,    48,    50,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    56,   103,   246,   248,   250,
      52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    74,   768,    75,    76,   482,  1132,  1138,
     689,   879,  1289,  1452,   690,  1406,  1486,   691,  1454,   692,
     693,   883,   148,   271,    77,   579,   366,  1243,  1244,  1435,
    1299,  1344,  1300,  1347,   801,  1171,  1060,   554,   392,   393,
     394,   395,   239,   340,   341,    80,    81,    82,    83,    84,
      85,   240,   833,  1366,  1426,   628,  1193,  1196,  1199,  1386,
    1390,  1394,  1441,  1444,  1447,   829,   830,   945,   798,   602,
     637,    87,    88,    89,    90,    91,    92,   241,   151,   405,
     204,  1017,  1018,   243,   244,   456,   251,   759,   912,   527,
     528,  1438
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1055
static const yytype_int16 yypact[] =
{
    4143,    40,    74,  4228, -1055, -1055,  2061,    67,   -44,   -68,
     -48,    37,   123,   134,   183,   201,    93,   -77,   108,   169,
      19,   182,   190,    17,   212,   217,   312,   319,   340,   394,
     346,   362,    58,   370,    22,   416,   103,   288,   389,   299,
     176,   176,   310,   351,    79,   400,   421,   428,    16,    45,
     429,   439,   500,   501,  2218,   504,   375,   378,   404,    31,
      49, -1055,   431, -1055,   580,   601,   387, -1055,   615,   621,
       7,    23, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055,    -5, -1055, -1055,    30,   459,   423, -1055, -1055, -1055,
    -116,  -112,    69,   239,   345,   357,   384,   395,   438,   486,
     497,   535,   564,   569,   570,   573,   592,   602,   614,   618,
     638,   480,   481,   492,   509,   520, -1055,   674,   523,   543,
     546, -1055, -1055, -1055, -1055, -1055, -1055, -1055,  3964,  3964,
    3964, -1055, -1055,  3964,  3509,    18,   684,   587,  2671,   707,
     566, -1055,   720,   730,  3964,   740,   750, -1055,  3964, -1055,
   -1055, -1055, -1055, -1055,  3964,  3886,  3964,  3964,   606,  3964,
    3886,  3964,  3964,   622,  3886,  3964,  3964,  2671,   639,   637,
   -1055,   645,   652,  2218,  2218,  2218,   655, -1055, -1055, -1055,
   -1055,   660,   661,   676,  2671,  3964,   827,  2671,   176,   176,
     176,  3964,  3964,   -54, -1055,    83,   176,   673,   677,   680,
    3735,   228,   -51,   688,   691,   694,  2218,  2671,   698,    44,
     699, -1055,   874, -1055,   695,   722,   733,   741,   756,   668,
   -1055,   762,    36,   915,   924,   949,   213,  2822,  1903, -1055,
   -1055,  2795, -1055,   879, -1055,   957,  3964,  3964,  3964,   808,
    3964,   809,   875,  3964,  3964, -1055, -1055,  3964,   979, -1055,
     994, -1055,  1001, -1055, -1055,  2671,  2671,   856,  3964,  1007,
     854, -1055, -1055, -1055,  1013,  3964,  3964,  3964,  3964,  3964,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,   322,   322,   322,
     322,   322,  3964,   322,   322,   322,   744,   869,   869,   869,
    6547,    80,  3886,  5788,   209,   867,  1021,   891,   878, -1055,
     873,  4304,  1043, -1055, -1055,  3964,  3964,  3964,  3964,  3964,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,  3964,
   -1055, -1055,   797,   -98,   -35,  5086,   210,  6568,  3886,  2934,
   -1055,    27,  6589,  6610,  3964,  6631,   418,  6652,  6673,  3964,
     590,  6694,  6715,  1054,  3964,  3964,  3964,  3964,  1058,  1061,
    1061,  3964,   920,   942,   954,   961,  3964,  3964,  3964,  1088,
    5006,   922,  1093,    76, -1055, -1055,  5112,  5138,   176,   176,
     587,   587,    85,  3964,  3964,  3964,  3735,  3735,  3964,  4304,
     275, -1055,  3964,  3964,  3964,  3964,  3964,  1117,  1121,  3964,
    1123, -1055,  3964,  3964,  1180, -1055,  3886,  3886,  3886,  3964,
    3964,  3666,  1126, -1055,  3964, -1055, -1055, -1055,   972,   975,
     976,   977,  3886,   869, -1055, -1055,   611,  3964,  2973, -1055,
   -1055,  6736,  6757,  6778,  1032,  5164, -1055,   980,  3078,  6799,
    5811, -1055, -1055,  1473, -1055,  1553,   987,   665,  3964,  5834,
     257,  3964,     1, -1055,  6820,  5857,  6841,  5880,  6862,  5903,
    6883,  5926,  6904,  5949,  6925,  5972,  6946,  5995,  6967,  6018,
    6988,  6041,  7009,  6064,  7030,  6087,  5190,  5216,  7051,  6110,
    7072,  6133,  7093,  6156,  7114,  6179,  7135,  6202,  7156,  6225,
    5242,  5268,  5294,  5320,  5346,  5372,   693,     0, -1055,   983,
     989,   990,   986,   853,   988,   995,   992,  3964, -1055, -1055,
    2671,   716,   109,   423,  3964,  1145,  1148,    33,   999, -1055,
     -20,    29,    35,   163, -1055, -1055,  3097,  1897,   724,  1068,
    1068,   596,   596,   596,   596,   356,   356,   869,   869,   869,
     869, -1055,     9,  3886,  1149,  3886,  3964,  1150, -1055,  1154,
    1152,  3886,  3886,  1051,  1155,  1160,  7177,  1162,  1062,  1163,
    1165,  7198,  1070,  1170,  1173,  3964,  7219,  4334,  7240,  7261,
    3964,  2671,  1177,  1176,  7282,  4031,  4031,  4031,  4031,  7303,
    7324,  7345,  2671,  3886,  1027, -1055,   176,  3964,  3964, -1055,
   -1055,  1024,  1026,  3735,  5398,  5424,  5450,  5060,    21,   176,
    1649,  7366,  4362,  7387,  7408,  7429,  3964,  1181,  3964,  7450,
   -1055,  6248,  6271, -1055,   726,   731,   743,  6294,  6317, -1055,
    3886,  6340,  1033,  4390,  3886,  3886,  3886,  3886,   746, -1055,
    3236,  3886,   869, -1055,  1183,  1184,  1187,  1039,  3964,  1781,
    3964,  3964, -1055,     3, -1055, -1055,  1037,  2671,  1191,  6363,
      81, -1055,  4418, -1055,  1046,  1048,  1042, -1055,  1196, -1055,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055, -1055, -1055, -1055, -1055,  3964,  3964, -1055, -1055,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
    3964,  3964,  3964,  3964,  3964,  3964,  3964,  1200, -1055,  3886,
     322, -1055, -1055,   322, -1055,  3964, -1055,   322,  1210,  1066,
     107,  3964,  1216,  1217,  1297, -1055,  1219,  1073,    31,  1218,
   -1055,  3886,  3886,  3886,  3886,  3964, -1055,  1089,   322,    62,
   -1055,    71,  5476, -1055,  1234,   176,  2934, -1055,  1186,  2671,
    2671,  1237,  2671,   855,  2671,  2671,  1240,  1192,  2671,  2671,
    1323,  1245,  1246,  1249,  1250,  1501, -1055, -1055,  1252, -1055,
    1253,  1108,  7681, -1055,  1110,  1112,  1114,  1261,  1262,  1263,
    1265,   755,  1268,   283,  5502,  5528, -1055, -1055,  4446,   -65,
     176,   176,   176,  1269,  1271,  1115,  1127,    12,    13,   -27,
   -1055,   323, -1055,    21,  1277,  1272,  1278,  1279,  1280,  7681,
   -1055,  1369,  1116,  1282,  1285,  1286,  1236,  3964,  1289,  1291,
     759,   298, -1055, -1055,   766,   767,   786,   787, -1055,  3964,
     791,  2671,  2671,  2671,  1294,  5554, -1055,  3991,   642,  1296,
    1298,  2671,  1141, -1055,  1299,  1302, -1055,  1301, -1055,  1157,
    3964,  3964,  2671,  1159, -1055,  7471,  6386,  7492,  6409,  7513,
    6432,  7534,  6455,  6478, -1055,   110,  1158,  1161,  7555,  1167,
   -1055,    80,   249,  1166,  1306,  1530, -1055, -1055, -1055,    31,
    3964, -1055,   792, -1055,   795,   801,   802,   815,  7681, -1055,
    1310,    10,  1315,  3964,  3426,    63,  1164,  1259,  1259,  2671,
    1319,  1169,  1172,  1320,  1326,  2671,  1174,  1329,  1330, -1055,
    1332,  2671,  2671,  2671,  1334,  1333, -1055,  2671,  1335,  1336,
    1337,  1338,  2671,  2671,  2671, -1055,  1339,   144,  3964,  3964,
    3964,  1182,  1188,   -15,   111,   232,  1194, -1055,  2671,  3964,
   -1055,  1343, -1055,  1345, -1055, -1055,  3735,   -25,  2369, -1055,
    1195,  1197,  3124, -1055,  3886, -1055, -1055, -1055,  1198,  1985,
   -1055, -1055,  1204, -1055, -1055, -1055, -1055,  7681, -1055,  1347,
    1354,  1256, -1055,  3964,  3964,  3964, -1055,  1357,   226,  1206,
    1359, -1055,   257, -1055,  3964,  5580,  5606,   819, -1055,  3964,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,  1211, -1055,
   -1055, -1055, -1055, -1055,  2671,   423,  3964,  1363,  1366,    33,
   -1055,  1365,  6501,    31, -1055,  1368,  1371,  1373,  1374, -1055,
   -1055,   322, -1055,  5632,  4031,  7681, -1055, -1055,  3964,   176,
    1375,  1376,  1377, -1055,  3964,  3964, -1055, -1055,  1378,  3964,
   -1055, -1055,  1367,  1379,  1380,  1281,  3964, -1055,  1382,  2671,
    2671,  2671,  2671,  1383,   974,  1389,  3964, -1055,  4031,  4474,
    7576,  4250,   587,   587,   176,  1394,   176,  1397,   176,  1398,
    3964,   380,  1254,  7597, -1055, -1055,  4502,   329, -1055,  1401,
    1745,  1402,  2671,   176,  1745,  1404,   823,  3964, -1055, -1055,
   -1055, -1055,  2671,  4278,   424,  7618, -1055, -1055,  3469,  2671,
   -1055, -1055,   171,  7681,  3964,  3964,  2671,  1255,   848,  7681,
    1407,  1409,  1410,  2173, -1055,  1406,  1411, -1055,  1264, -1055,
   -1055, -1055, -1055, -1055,  1412,  3964,  7681, -1055,  4530,   309,
   -1055, -1055, -1055,  4558,  4586, -1055,  4614,  1414, -1055, -1055,
    1372,  1416,  7681, -1055,  1417,  1418,  1422,  1438, -1055,  1287,
   -1055, -1055,  5033,  2192,  1439,  1288, -1055,  3964, -1055,  1290,
    1292,   348, -1055,  1295,   386, -1055,  1311,   390, -1055,  1312,
    6524,  1443,  2671,  1444,  1313,  3964, -1055,  3275,   452, -1055,
     858,   454,   466, -1055,  1467,  4642,  1385,  3964, -1055,  3964,
   -1055, -1055,  3886,  2334,  1469,  1317, -1055,  3964,  5658,  5684,
   -1055,  2671,  3964,  1475, -1055, -1055, -1055, -1055,    31, -1055,
    1384, -1055,  5710, -1055, -1055,  1476,  1478,  1481,  1484,  1486,
    1358, -1055, -1055, -1055, -1055, -1055,  2671,  3886, -1055, -1055,
     587,  4306, -1055, -1055,  3735,    21,  3735,    21,  3735,    21,
    1487, -1055,   880,  2671, -1055,  4670,   176,  1488,  3886,   176,
   -1055, -1055,  3964,  4698,  4726,   883, -1055, -1055,  1489,  1360,
    7681,  3964,  3964,   884,  7681, -1055,  1490, -1055,  3964,   895,
     899, -1055, -1055, -1055, -1055, -1055,  3964,   900,   906,  1356,
    3964, -1055,  4754,   471,   244,  4782,   485,   462,  4810,   488,
     604, -1055,  2671,  1491,  1446,  1951,  1362,   499, -1055,   913,
     536,  2475, -1055, -1055,  1517, -1055,  3964,  7639,  5736,    38,
   -1055,  5762,  1536, -1055, -1055,  1540, -1055, -1055,  4838,  1528,
    1539, -1055,  4866,  1542,  3964,  1543,  1544,  3964,  1545,  1547,
    3964,  1548,  1395, -1055,  3964, -1055,    21, -1055,  3886,  1550,
    3275, -1055, -1055,   923, -1055,  3964, -1055,  2671,  3964,  2520,
    3701, -1055, -1055, -1055, -1055, -1055,  1403,  4894, -1055, -1055,
    1408,  4922, -1055, -1055,  1419,  4950, -1055,  1551,  2494,   717,
    2104,   927, -1055,   577,   930,  1555,  1420,  7660,   944,  4978,
   -1055,  1903, -1055, -1055,   322,  7681,    21,  1557,    21,  1562,
      21,  1571, -1055, -1055, -1055, -1055,    21,  1574,  3886,  1575,
   -1055,   322, -1055,  1423,  1577,   947,  2635, -1055,   951,   727,
   -1055,  1425,   749, -1055,  1427,   763, -1055,  1428,   933, -1055,
     956, -1055,   959, -1055,  1429,  2671, -1055,  3964, -1055,   423,
     322, -1055,  1583,    21,  1584,    21,  1585,    21, -1055,  1586,
     322,  1588,   322,   963,  2776, -1055, -1055, -1055,   943, -1055,
     958, -1055,  1008, -1055, -1055, -1055,   967, -1055,  1590,   423,
    1591,  1592,  1594,   322,  1595, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1055, -1055, -1055, -1055,   681, -1055, -1055, -1055, -1055,   267,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055,  -320,    -3, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055, -1055, -1055,   -19, -1055,   686,  1613, -1055, -1055,
   -1055, -1055,    -1,  -402,  -204, -1055, -1055, -1055, -1055, -1055,
   -1055,  1614, -1055, -1055, -1055, -1055, -1055, -1055, -1055, -1055,
   -1055, -1055, -1055, -1055, -1055,  -781,  -822, -1055, -1055,  1230,
   -1055, -1055, -1055, -1055, -1055, -1055, -1055,    -2, -1055,    51,
   -1055, -1054,   617,  -113,   315,   737,  -726,   585, -1055,  -294,
      -6, -1055
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     152,   264,    79,   149,   150,   683,   419,   975,   621,   622,
     869,   540,   260,   154,   544,   766,  1050,   434,   970,   972,
     219,   173,   334,   168,   529,   530,   531,   532,   262,   534,
     535,   536,   911,   168,   267,   249,   275,   757,   276,   173,
     277,   443,   278,   157,  1376,   823,     4,   823,   430,   222,
     431,   223,   977,   252,   824,   572,   824,   473,  1210,   475,
     573,   825,   826,   825,   826,   827,   828,   827,   828,  1057,
     388,   389,   390,   187,     5,   164,   188,   408,   409,   189,
     153,   190,   165,   212,   155,   526,   273,   539,   408,   409,
     274,   203,   205,   823,   211,   962,   224,   684,   685,   686,
     687,   422,   824,   427,   156,   410,   971,   973,   423,   825,
     826,   902,   183,   827,   828,   184,   539,   185,   574,   121,
     122,   123,   124,   575,   335,   336,   126,   408,   409,   159,
     213,   220,   164,   974,   214,  1108,   327,   328,   329,   761,
     160,   330,   333,  1094,   215,  1095,   339,   265,   767,   767,
    1087,  1088,   362,   738,   266,   975,   365,   194,   739,   870,
     195,   688,   367,   369,   372,   373,   261,   375,   369,   377,
     378,   169,   369,   381,   382,   221,   174,  1293,   170,   141,
     142,   169,   263,  1041,   268,   582,   269,   583,   762,   161,
     250,   270,   758,   400,   763,   444,   158,  1377,   432,   406,
     407,   253,  1307,   129,   130,   408,   409,   162,   407,   134,
     135,   136,   137,   903,   904,   921,   543,   630,   408,   409,
     582,   279,   751,   280,   922,   408,   409,   408,   409,   582,
     141,   142,  1127,  1128,   616,   453,   369,   875,   134,   135,
     136,   137,   411,   623,   461,   462,   463,   163,   465,   403,
     404,   468,   469,   408,   409,   470,  1035,   412,   141,   142,
     166,   420,   669,  1029,   448,   750,   479,   449,   582,  1096,
     450,  1097,   451,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   176,   823,  1149,   199,   200,
     533,   167,   764,  1408,  1226,   824,   526,   273,   201,  1227,
     369,   545,   825,   826,   171,   202,   827,   828,   134,   135,
     136,   137,   172,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   141,   142,
     121,   122,   123,   124,   175,   577,   453,   126,   578,   176,
     408,   409,   586,   177,   408,   409,   178,   591,   134,   135,
     136,   137,   596,   597,   598,   599,   877,   421,   457,   604,
    1098,   281,  1099,   282,   609,   610,   611,   179,   141,   142,
     180,  1473,   207,   181,  1355,   208,   141,   142,   209,   339,
     339,   624,   625,   626,   327,   328,   627,   408,   409,   182,
     631,   632,   633,   634,   635,   408,   409,   639,   273,   186,
     641,   642,  1219,   629,   369,   369,   369,   647,   648,   651,
     196,   958,   653,   197,   129,   130,   896,   141,   142,   897,
     369,   408,   409,   899,   875,   660,   662,   216,   198,   619,
     620,   121,   122,   123,   124,   408,   409,   404,   126,   206,
     191,   408,   409,   192,   920,   193,   679,   681,   217,   682,
     370,   976,   218,   225,  1314,   370,  1317,  1205,  1320,   370,
     408,   409,   975,   199,   200,   975,   226,   283,   975,   284,
     356,   357,   358,   201,   227,   228,  1264,   359,   245,   285,
     210,   286,  1296,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   458,   357,   358,   246,   408,   409,
     247,   359,   408,   409,   823,   651,   287,   753,   288,   752,
    1201,   257,   754,   824,  1266,   129,   130,   289,  1268,   290,
     825,   826,   454,   370,   827,   828,   248,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   369,   344,   369,   772,   359,   582,   975,   588,   662,
     776,  1034,  1036,   254,  1220,  1399,   255,   804,   805,   806,
     291,   338,   292,   790,   408,   409,   408,   409,   795,   803,
     803,   803,   803,   802,   802,   802,   802,   256,   408,   409,
    1276,   369,  1278,   408,   409,   814,   815,   975,   272,   258,
     975,   818,  1358,   975,  1279,   259,   975,   408,   409,  1354,
     408,   409,   317,   318,   839,  1439,   841,  1442,   293,  1445,
     294,   408,   409,  1357,   319,  1448,  1360,   370,   369,   295,
    1005,   296,   369,   369,   369,   369,   975,  1368,   975,   369,
     975,   320,    39,    40,    41,    42,   865,   813,   867,   868,
      47,   242,   321,    50,   819,   323,   823,   876,   408,   409,
     831,   322,  1478,   454,  1480,   824,  1482,   297,   337,   298,
    1189,  1190,   825,   826,  1370,   324,   827,   828,   325,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   343,   885,   886,   299,   359,   300,   408,
     409,   301,   303,   302,   304,   305,   360,   306,   887,   888,
     889,   890,   891,   892,   893,  1428,   361,   369,   354,   355,
     356,   357,   358,   898,   307,   363,   308,   359,   582,   905,
     592,   370,   370,   370,   309,   364,   310,  1154,   374,   369,
     369,   369,   369,   918,  1361,   342,   311,   370,   312,   582,
     313,   659,   314,   663,   379,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   823,
     315,   384,   316,   359,   383,  1006,   385,   386,   824,   823,
     242,   242,   242,   571,   387,   825,   826,   391,   824,   827,
     828,   399,   396,   397,   402,   825,   826,   141,   142,   827,
     828,   823,   441,   677,   269,   678,   925,   147,   398,   270,
     824,   401,   413,   242,   428,   823,   414,   825,   826,   415,
     424,   827,   828,   425,   824,   989,   426,   736,   876,   737,
     429,   825,   826,   433,   436,   827,   828,   997,  1309,   744,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   963,   964,   965,   582,   359,   749,  1424,  1015,  1016,
     435,   437,   476,   477,   582,   459,   845,  1462,   370,   582,
     370,   846,   438,   141,   142,   439,   663,   777,   537,  1037,
     269,   582,   371,   847,   582,   270,   858,   376,  1042,  1464,
     440,   380,   931,   582,   932,   956,   442,   582,  1056,   992,
     445,  1053,  1055,  1466,   582,   582,   993,   994,   370,   446,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   582,   582,   995,   996,   359,   582,
    1043,   998,  1044,   582,   447,  1045,  1089,  1090,  1091,   582,
     582,  1046,  1047,   460,   464,   370,  1101,  1103,   466,   370,
     370,   370,   370,   582,  1106,  1048,   370,  1136,  1179,  1137,
    1180,   582,   369,  1214,   467,   471,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     472,  1123,  1124,  1125,   359,   823,  1232,   474,  1233,  1131,
     478,   480,  1133,   481,   824,   823,  1136,  1139,  1277,   483,
     359,   825,   826,   546,   824,   827,   828,  1107,   547,  1142,
     823,   825,   826,   549,  1143,   827,   828,   147,  1322,   824,
    1323,   582,  1136,  1334,  1339,   548,   825,   826,  1157,   555,
     827,   828,  1156,  1342,   370,  1343,  1158,  1345,  1136,  1346,
    1349,   595,  1163,  1164,   582,   600,  1350,  1166,   601,   541,
    1325,   582,   605,  1369,  1172,   614,   370,   370,   370,   370,
     823,  1232,  1184,  1405,  1182,   582,  1183,  1427,   582,   824,
    1429,   339,   339,  1468,   606,   612,   825,   826,  1200,   615,
     827,   828,  1136,  1490,  1433,  1457,   607,  1458,   369,  1460,
    1159,  1461,   369,   608,   582,  1215,  1469,  1470,  1491,  1471,
    1437,  1136,  1224,  1488,   636,  1493,  1223,  1494,   638,   640,
     652,   654,  1228,  1229,   655,   656,   657,  1453,   667,   670,
     676,   740,   741,   742,   743,  1191,   745,  1194,   746,  1197,
     747,   755,   756,  1242,   760,   770,   773,   748,   774,   775,
     778,  1208,   779,  1400,  1211,  1212,  1476,   780,  1492,   782,
     784,   783,   785,   644,   645,   646,  1484,   788,  1487,   787,
     789,   797,   799,   812,   816,  1261,   817,   840,   852,   658,
     861,   862,     7,     8,   863,   864,   871,   873,   880,  1500,
     881,   882,   884,  1275,   894,   453,   350,   351,   352,   353,
     354,   355,   356,   357,   358,  1283,   900,  1284,   796,   359,
     369,   901,   906,   907,   913,  1290,   909,   910,   919,   810,
    1294,   550,    18,    19,   551,    21,    22,   552,    24,   553,
      26,   924,    27,   926,   929,    30,    31,   935,    33,    34,
      35,   936,   940,   941,    38,   369,   942,   943,   946,   339,
     947,   948,  1312,   949,  1315,   950,  1318,   951,   952,   953,
     954,   955,   957,   966,   968,   984,   369,   967,   979,   969,
    1331,    56,    57,    58,   978,   980,   981,   982,   985,  1337,
    1338,   986,   987,   988,   872,   990,  1341,   991,  1002,   370,
    1007,  1010,  1008,   908,  1348,  1011,  1012,  1013,  1352,  1014,
     769,  1030,   771,  1039,  1031,  1313,  1049,  1316,  1019,  1319,
    1033,  1052,  1038,  1058,  1059,  1063,  1066,  1327,  1064,   939,
    1330,  1065,  1067,  1069,  1139,  1070,  1071,  1072,  1076,  1077,
     643,  1092,  1079,  1080,  1081,  1082,  1086,  1093,  1100,  1104,
     811,  1105,  1387,  1120,  1112,  1391,  1113,  1117,  1395,  1119,
    1121,  1122,  1398,  1126,  1129,  1130,   369,  1140,   369,  1144,
    1145,  1147,  1167,  1407,  1150,   983,  1409,  1151,  1415,  1152,
    1153,  1160,  1161,  1162,  1165,  1168,  1169,   850,  1173,  1178,
    1170,   854,   855,   856,   857,  1181,   927,   928,   860,   930,
    1192,   933,   934,  1195,  1198,   937,   938,  1206,  1209,  1436,
    1213,  1234,  1202,  1238,  1231,  1235,  1236,  1239,  1241,  1249,
    1240,  1403,  1251,  1252,  1253,   370,   369,  1250,  1254,   370,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,  1255,  1259,  1256,  1260,   359,  1271,
    1262,  1273,  1263,  1475,  1265,  1474,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
    1267,  1269,  1274,  1280,   359,  1287,   895,  1288,   999,  1000,
    1001,  1295,  1301,  1496,  1302,     7,     8,  1303,  1009,  1282,
    1304,  1297,  1305,  1321,  1328,  1335,  1340,  1363,   914,   915,
     916,   917,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,  1351,  1306,  1364,  1336,
     359,  1367,   454,  1372,   550,    18,    19,   551,    21,    22,
     552,    24,   553,    26,  1382,    27,  1040,   370,    30,    31,
    1379,    33,    34,    35,  1380,  1383,  1062,    38,  1385,  1388,
    1389,  1392,  1068,  1393,  1396,  1397,  1402,  1422,  1073,  1074,
    1075,  1430,  1416,  1440,  1078,     7,     8,  1418,  1443,  1083,
    1084,  1085,   370,   944,    56,    57,    58,  1446,  1420,  1431,
    1449,  1451,  1455,  1456,  1463,  1102,  1465,  1467,  1472,  1477,
    1479,  1481,  1483,   370,  1485,  1111,  1495,  1497,  1498,  1115,
    1499,  1501,  1051,  1373,   550,    18,    19,   551,    21,    22,
     552,    24,   553,    26,  1061,    27,    78,    86,    30,    31,
     603,    33,    34,    35,  1146,     0,     0,    38,     0,     0,
       0,     0,     0,   674,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,  1141,   359,     0,    56,    57,    58,     0,     0,     0,
       0,     7,     8,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   370,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1174,  1175,  1176,  1177,
     550,    18,    19,   551,    21,    22,   552,    24,   553,    26,
       0,    27,     0,   675,    30,    31,     0,    33,    34,    35,
       0,  1116,     0,    38,     0,     0,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1216,
       0,     0,     0,   370,     0,     0,  1225,     0,    93,   229,
      56,    57,    58,  1230,    97,    98,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     231,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     7,     8,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,   832,
       0,     0,     0,     0,   236,     0,     0,     0,     0,  1272,
      39,    40,    41,    42,    43,     0,     0,     0,    47,     0,
       0,    50,   550,    18,    19,   551,    21,    22,   552,    24,
     553,    26,     0,    27,     0,     0,    30,    31,     0,    33,
      34,    35,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,    58,     0,     0,   416,  1207,     0,
    1324,     0,   140,     0,     0,     0,     0,   418,     0,     0,
       0,     0,   146,     0,   202,   455,    93,   229,     0,     0,
       0,     0,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   231,  1362,
       0,   866,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,   233,     0,  1285,
     234,     0,   235,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,    47,     0,     0,    50,
       0,  1118,     0,     0,  1308,     0,  1412,     0,     0,     0,
       0,     0,   550,    18,    19,   551,    21,    22,   552,    24,
     553,    26,     0,    27,     0,  1329,    30,    31,     0,    33,
      34,    35,     0,     0,   128,    38,     0,     0,     0,   131,
     132,   133,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,   138,   368,     0,   359,     0,
     140,     0,    56,    57,    58,   143,     0,     0,     0,     0,
     146,     0,     0,   455,    93,    94,    95,     0,    96,     0,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   121,
     122,   123,   124,   125,     0,  1401,   126,  1404,     0,     0,
       0,  1365,     0,     0,     0,     0,     7,     8,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,    18,    19,   551,    21,
      22,   552,    24,   553,    26,  1450,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,   127,     0,    38,  1237,
       0,     0,   128,   129,   130,     0,     0,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,  1258,     0,
       0,     0,     0,   138,   139,    56,    57,    58,   140,     0,
     141,   142,     0,   143,     0,   144,     0,   145,   146,     0,
     147,    93,   229,   230,     0,     0,     0,    97,    98,    99,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   231,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,  1425,     0,     0,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,     0,     0,
       0,    47,     0,     0,    50,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   128,
    1286,     0,     0,   359,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   237,     0,     0,     0,   140,     0,     0,     0,     0,
     143,     0,    93,   229,  1109,   146,     0,   238,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   231,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,   233,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,     0,
       0,     0,    47,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,  1371,     0,     0,     0,   359,     0,     0,     0,     0,
     128,     0,     0,     0,     0,   131,   132,   133,     0,     0,
    1423,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   237,     0,     0,     0,   140,     0,     0,     0,
       0,   143,     0,    93,   229,  1410,   146,     0,  1110,    97,
      98,    99,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   231,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,   233,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
       0,     0,     0,    47,     0,     0,    50,     0,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   128,  1459,   457,     0,   359,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   237,     0,     0,     0,   140,     0,     0,
       0,     0,   143,     0,    93,   229,     0,   146,     0,  1411,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   231,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,     0,     0,     0,    47,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   581,
     357,   358,     0,  1489,     0,     0,   359,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,   131,   132,   133,
       0,     0,     0,   457,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   237,     0,     0,     0,   140,     0,
       0,     0,     0,   143,     0,    93,   229,     0,   146,     0,
     238,    97,    98,    99,     0,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   231,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,     0,   233,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    47,     0,     0,    50,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   458,
     357,   358,   457,   128,     0,     0,   359,     0,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   368,     0,     0,     0,   140,
       0,     0,     0,     0,   143,     0,    93,   229,     0,   146,
       0,   452,    97,    98,    99,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   231,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,     0,     0,     0,    47,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   581,   357,
     358,     0,     0,     0,     0,   359,   671,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,   131,
     132,   133,     0,     0,     0,   765,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   368,     0,     0,     0,
     140,     0,     0,     0,     0,   143,     0,    93,   229,     0,
     146,     0,   661,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   231,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,   232,     0,     0,   233,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,     0,     0,     0,    47,     0,     0,
      50,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   859,   128,     0,     0,   359,     0,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   237,     0,     0,
       0,   140,     0,     0,     0,     0,   143,     0,    93,   229,
       0,   146,     0,  1114,    97,    98,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     231,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,     0,     0,     0,    47,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   416,  1207,     0,
       0,     0,   140,     0,     0,     0,     0,   418,     0,    93,
     326,   273,   146,     0,   202,    97,    98,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,   121,   122,   123,   124,   125,     0,
       0,   126,    93,   326,   273,     0,     0,     0,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,   121,   122,   123,
     124,   125,    93,   326,   126,     0,     0,     0,    97,    98,
      99,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,   128,   129,   130,
       0,   125,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
       0,     0,     0,   140,     0,     0,     0,     0,   143,     0,
       0,     0,     0,   146,     0,  1054,     0,     0,     0,     0,
     128,   129,   130,     0,     0,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,     0,     0,     0,   140,     0,     0,     0,
       0,   143,     0,     0,     0,     0,   146,     0,  1222,     0,
     128,     0,     0,     0,     0,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,     0,     0,     0,   140,     0,     0,     0,
       0,   143,     0,     0,   331,     0,   146,     0,   332,    93,
     326,     0,     0,     0,     0,    97,    98,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,    93,   326,  1413,     0,   125,     0,
      97,    98,    99,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,    93,   326,
       0,     0,     0,   125,    97,    98,    99,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
       0,     0,     0,   140,     0,     0,     0,     0,   143,     0,
       0,   649,   128,   146,     0,   650,     0,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,     0,     0,     0,   140,     0,
       0,     0,     0,   143,     0,     0,   128,     0,   146,     0,
    1414,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   416,   417,     0,
       0,     0,   140,     0,     0,     0,     0,   418,     0,    93,
     229,     0,   146,     0,   202,    97,    98,    99,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   231,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,     0,
     233,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,     0,    93,   326,    47,
       0,     0,    50,    97,    98,    99,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,  1004,
       0,     0,     0,     0,     0,     0,   125,   128,     0,     0,
       0,     0,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   368,
       0,     0,     0,   140,    93,   326,   273,     0,   143,     0,
      97,    98,    99,   146,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   121,
     122,   123,   124,   125,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,     0,     0,
       0,   140,     0,     0,     0,     0,   143,     0,     0,     0,
       0,   146,     0,     0,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,   128,   129,   130,    -4,    -4,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,     0,     0,     0,   140,    -4,
      -4,     0,     0,   143,     0,     0,    -4,    -4,   146,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     6,    -4,    -4,     0,     0,     0,    -4,     0,
       7,     8,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     9,    10,     0,    -4,    -4,     0,
       0,    11,    12,     0,    13,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     7,     8,    52,    53,
       0,     0,     0,    54,     0,     0,     0,     0,    55,    56,
      57,    58,     0,     0,    59,     0,    60,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,     0,    72,    73,     0,   550,    18,    19,   551,    21,
      22,   552,    24,   553,    26,     0,    27,     0,     0,    30,
      31,     0,    33,    34,    35,     0,     0,     0,    38,     0,
       0,     0,     0,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,    56,    57,    58,  1187,     0,
    1188,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,  1217,     0,  1218,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,  1310,     0,  1311,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,   792,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,   835,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
     853,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,   878,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,   961,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,  1185,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,  1204,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
    1245,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,  1246,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,  1247,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,  1248,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,  1281,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
    1326,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,  1332,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,  1333,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,  1353,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,  1356,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
    1359,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,  1381,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,     0,  1384,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,  1417,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
       0,     0,  1419,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
    1421,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,  1434,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,     0,   613,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,     0,     0,     0,     0,
       0,     0,  1257,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   538,     0,     0,     0,     0,   617,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   576,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
     617,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,   618,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,   668,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,   716,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   717,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
     730,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,   731,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,   732,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,   733,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   734,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
     735,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,   820,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,   821,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,   822,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   923,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
     959,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,   960,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,  1003,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,  1134,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,  1135,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
    1155,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,  1291,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,  1292,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,  1298,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,  1375,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
    1378,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,   542,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,     0,     0,   673,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,   680,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
       0,     0,   695,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,   697,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,     0,     0,   699,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,   701,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,     0,     0,   703,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,   705,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,     0,     0,
     707,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,   709,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,     0,     0,   711,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,   713,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
       0,     0,   715,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,   719,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,     0,     0,   721,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,   723,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,     0,     0,   725,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,   727,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,     0,     0,
     729,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,   843,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,     0,     0,   844,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,   848,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
       0,     0,   849,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,     0,     0,   851,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,     0,     0,   874,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,     0,
       0,  1021,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,     0,     0,  1023,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,     0,     0,  1025,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,     0,     0,
    1027,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,     0,     0,  1028,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,     0,     0,  1148,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,     0,     0,  1270,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
     538,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,   580,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,   584,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   585,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,   587,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,   589,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,   590,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,   593,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,   594,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,   664,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
     665,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,   666,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,   672,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   694,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,   696,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,   698,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,   700,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,   702,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,   704,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,   706,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
     708,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,   710,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,   712,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   714,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,   718,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,   720,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,   722,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,   724,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,   726,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,   728,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
     781,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,   786,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,   791,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   793,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,   794,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,   800,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,   807,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,   808,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,   809,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,   834,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
     836,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,   837,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,   838,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,   842,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,     0,  1020,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,     0,     0,   359,     0,  1022,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       0,     0,     0,     0,   359,     0,  1024,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     0,     0,     0,     0,   359,     0,  1026,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,     0,  1032,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,     0,     0,     0,     0,   359,     0,  1186,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     0,     0,     0,     0,   359,     0,
    1203,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,     0,     0,     0,     0,   359,
       0,  1221,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,     0,     0,     0,     0,
     359,     0,  1374,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,     0,     0,     0,
       0,   359,     0,  1432,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359
};

static const yytype_int16 yycheck[] =
{
       6,     6,     3,     6,     6,     4,   210,   829,   410,   411,
       7,   331,     5,    57,   334,     6,     6,   221,     6,     6,
       4,     4,     4,     4,   318,   319,   320,   321,     5,   323,
     324,   325,   758,     4,     4,     4,   152,     4,   154,     4,
     152,     5,   154,     6,     6,    72,     6,    72,     4,     4,
       6,     6,   833,     4,    81,   153,    81,   261,  1112,   263,
     158,    88,    89,    88,    89,    92,    93,    92,    93,     6,
     183,   184,   185,    51,     0,   152,    54,   142,   143,    57,
      13,    59,   159,     4,   152,     4,     5,     7,   142,   143,
      96,    40,    41,    72,    43,   160,    51,    96,    97,    98,
      99,   152,    81,   216,   152,   159,    94,    94,   159,    88,
      89,     4,    54,    92,    93,    57,     7,    59,   153,    38,
      39,    40,    41,   158,   106,   107,    45,   142,   143,     6,
      51,   115,   152,   160,    55,   160,   138,   139,   140,   159,
       6,   143,   144,   158,    65,   160,   147,   152,   139,   139,
       6,     7,   154,   153,   159,   977,   158,    54,   158,   156,
      57,   160,   164,   165,   166,   167,   159,   169,   170,   171,
     172,   152,   174,   175,   176,   159,   159,  1231,   159,   149,
     150,   152,   159,   909,   154,   158,   156,   160,   159,     6,
     159,   161,   159,   195,   159,   159,   159,   159,   154,   201,
     202,   152,  1256,   122,   123,   142,   143,     6,   210,   129,
     130,   131,   132,   106,   107,   153,     7,   421,   142,   143,
     158,   152,   542,   154,   153,   142,   143,   142,   143,   158,
     149,   150,     6,     7,   158,   237,   238,   156,   129,   130,
     131,   132,   159,   158,   246,   247,   248,   154,   250,   198,
     199,   253,   254,   142,   143,   257,     7,   206,   149,   150,
     152,   210,   466,   153,    51,   156,   268,    54,   158,   158,
      57,   160,    59,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   152,    72,  1043,   142,   143,
     322,   152,   159,  1377,   153,    81,     4,     5,   152,   158,
     332,   334,    88,    89,   152,   159,    92,    93,   129,   130,
     131,   132,   152,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   149,   150,
      38,    39,    40,    41,   152,   155,   368,    45,   158,   152,
     142,   143,   374,    61,   142,   143,    57,   379,   129,   130,
     131,   132,   384,   385,   386,   387,   680,   159,     8,   391,
     158,   152,   160,   154,   396,   397,   398,    57,   149,   150,
       6,  1455,    51,    57,   160,    54,   149,   150,    57,   410,
     411,   413,   414,   415,   416,   417,   418,   142,   143,    57,
     422,   423,   424,   425,   426,   142,   143,   429,     5,    59,
     432,   433,     8,   158,   436,   437,   438,   439,   440,   441,
     152,   158,   444,    54,   122,   123,   740,   149,   150,   743,
     452,   142,   143,   747,   156,   457,   458,    57,   159,   408,
     409,    38,    39,    40,    41,   142,   143,   416,    45,   159,
      54,   142,   143,    57,   768,    59,   478,   480,    57,   481,
     165,   158,    54,    54,  1265,   170,  1267,   158,  1269,   174,
     142,   143,  1314,   142,   143,  1317,    57,   152,  1320,   154,
     144,   145,   146,   152,     4,     4,   158,   151,     4,   152,
     159,   154,  1238,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   152,   142,   143,
     152,   151,   142,   143,    72,   537,   152,   543,   154,   542,
     160,   154,   544,    81,   158,   122,   123,   152,   158,   154,
      88,    89,   237,   238,    92,    93,   152,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   573,     6,   575,   576,   151,   158,  1399,   160,   581,
     582,   901,   902,   152,   160,  1366,     6,   606,   607,   608,
     152,     4,   154,   595,   142,   143,   142,   143,   600,   605,
     606,   607,   608,   605,   606,   607,   608,     6,   142,   143,
     158,   613,   158,   142,   143,   617,   618,  1439,   159,     4,
    1442,   623,   160,  1445,   158,     4,  1448,   142,   143,   158,
     142,   143,   152,   152,   636,  1416,   638,  1418,   152,  1420,
     154,   142,   143,   158,   152,  1426,   158,   332,   650,   152,
       8,   154,   654,   655,   656,   657,  1478,   158,  1480,   661,
    1482,   152,    75,    76,    77,    78,   668,   616,   670,   671,
      83,    54,   152,    86,   623,   152,    72,   680,   142,   143,
     629,     7,  1463,   368,  1465,    81,  1467,   152,     4,   154,
    1092,  1093,    88,    89,   158,   152,    92,    93,   152,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     6,   716,   717,   152,   151,   154,   142,
     143,   152,   152,   154,   154,   152,     6,   154,   730,   731,
     732,   733,   734,   735,   736,   158,     6,   739,   142,   143,
     144,   145,   146,   745,   152,     5,   154,   151,   158,   751,
     160,   436,   437,   438,   152,     5,   154,  1051,   152,   761,
     762,   763,   764,   765,   160,   148,   152,   452,   154,   158,
     152,   160,   154,   458,   152,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    72,
     152,   152,   154,   151,   177,   153,   159,   152,    81,    72,
     183,   184,   185,     6,   152,    88,    89,   152,    81,    92,
      93,   194,   152,   152,   197,    88,    89,   149,   150,    92,
      93,    72,   154,   158,   156,   160,   775,   159,   152,   161,
      81,     4,   159,   216,   217,    72,   159,    88,    89,   159,
     152,    92,    93,   152,    81,   847,   152,   154,   851,   156,
     152,    88,    89,   154,   159,    92,    93,   859,  1260,     6,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   820,   821,   822,   158,   151,   160,   160,   880,   881,
       6,   159,   265,   266,   158,     6,   160,   160,   573,   158,
     575,   160,   159,   149,   150,   154,   581,   582,   154,   902,
     156,   158,   165,   160,   158,   161,   160,   170,   910,   160,
     154,   174,    57,   158,    59,   160,   154,   158,   924,   160,
       5,   923,   924,   160,   158,   158,   160,   160,   613,     5,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   158,   158,   160,   160,   151,   158,
     158,   160,   160,   158,     5,   160,   958,   959,   960,   158,
     158,   160,   160,     6,   156,   650,   968,   969,   159,   654,
     655,   656,   657,   158,   976,   160,   661,   158,     4,   160,
       6,   158,   984,   160,   109,     6,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       6,  1003,  1004,  1005,   151,    72,   158,     6,   160,  1012,
     154,     4,  1014,   159,    81,    72,   158,  1019,   160,     6,
     151,    88,    89,   156,    81,    92,    93,   976,     7,  1035,
      72,    88,    89,   160,  1036,    92,    93,   159,   158,    81,
     160,   158,   158,   160,   160,   154,    88,    89,  1054,     6,
      92,    93,  1054,   158,   739,   160,  1058,   158,   158,   160,
     160,     7,  1064,  1065,   158,     7,   160,  1069,     7,   332,
    1274,   158,   152,   160,  1076,   153,   761,   762,   763,   764,
      72,   158,  1088,   160,  1086,   158,  1088,   160,   158,    81,
     160,  1092,  1093,   160,   152,     7,    88,    89,  1100,     6,
      92,    93,   158,   160,   160,   158,   152,   160,  1110,   158,
    1059,   160,  1114,   152,   158,  1117,   160,   158,   160,   160,
    1414,   158,  1128,   160,     7,   158,  1128,   160,     7,     6,
       4,   159,  1134,  1135,   159,   159,   159,  1431,   106,   159,
     153,   158,   153,   153,   158,  1094,   158,  1096,   153,  1098,
     158,     6,     4,  1155,   155,     6,     6,   540,     4,     7,
     109,  1110,     7,  1367,  1113,  1114,  1460,     7,   160,     7,
       7,   109,     7,   436,   437,   438,  1470,     7,  1472,   109,
       7,     4,     6,   156,   160,  1187,   160,     6,   155,   452,
       7,     7,    12,    13,     7,   156,   159,     6,   152,  1493,
     152,   159,     6,  1205,     4,  1207,   138,   139,   140,   141,
     142,   143,   144,   145,   146,  1217,     6,  1219,   601,   151,
    1222,   155,     6,     6,     6,  1227,     7,   154,   139,   612,
    1232,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,     7,    62,    57,     7,    65,    66,     7,    68,    69,
      70,    59,     7,     7,    74,  1257,     7,     7,     6,  1260,
       7,   153,  1264,   153,  1266,   153,  1268,   153,     7,     7,
       7,     6,     4,     4,   159,   159,  1278,     6,     6,   152,
    1282,   101,   102,   103,     7,     7,     7,     7,     6,  1291,
    1292,     6,     6,    57,   677,     6,  1298,     6,     4,   984,
       4,   160,     4,     6,  1306,     6,     4,     6,  1310,   152,
     573,   153,   575,     7,   153,  1264,     6,  1266,   159,  1268,
     153,     6,   156,   159,    65,     6,     6,  1276,   159,     6,
    1279,   159,     6,   159,  1336,     6,     6,     5,     4,     6,
     160,   159,     7,     7,     7,     7,     7,   159,   154,     6,
     613,     6,  1354,     6,   159,  1357,   159,   159,  1360,   155,
       6,   105,  1364,     6,   158,     6,  1368,   156,  1370,     6,
       4,     6,     5,  1375,     6,     6,  1378,     6,  1380,     6,
       6,     6,     6,     6,     6,     6,     6,   650,     6,     6,
     109,   654,   655,   656,   657,     6,   779,   780,   661,   782,
       6,   784,   785,     6,     6,   788,   789,     6,     6,  1411,
       6,     4,   158,     7,   159,     6,     6,     6,     6,     5,
     156,  1370,     6,     6,     6,  1110,  1428,    55,     6,  1114,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     6,     6,   159,   159,   151,     6,
     160,     7,   160,  1459,   159,  1457,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     159,   159,   159,     6,   151,     6,   739,   160,   861,   862,
     863,     6,     6,  1489,     6,    12,    13,     6,   871,   104,
       6,   107,     6,     6,     6,     6,     6,     6,   761,   762,
     763,   764,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   160,   159,    72,   159,
     151,   159,  1207,     6,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     6,    62,     6,  1222,    65,    66,
       4,    68,    69,    70,     4,     6,   929,    74,     6,     6,
       6,     6,   935,     6,     6,   160,     6,     6,   941,   942,
     943,     6,   159,     6,   947,    12,    13,   159,     6,   952,
     953,   954,  1257,    72,   101,   102,   103,     6,   159,   159,
       6,     6,   159,     6,   159,   968,   159,   159,   159,     6,
       6,     6,     6,  1278,     6,   978,     6,     6,     6,   982,
       6,     6,   921,  1336,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   928,    62,     3,     3,    65,    66,
     390,    68,    69,    70,  1039,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,   160,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,  1034,   151,    -1,   101,   102,   103,    -1,    -1,    -1,
      -1,    12,    13,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,  1368,    -1,  1370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1079,  1080,  1081,  1082,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    -1,   160,    65,    66,    -1,    68,    69,    70,
      -1,   984,    -1,    74,    -1,    -1,  1411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1122,
      -1,    -1,    -1,  1428,    -1,    -1,  1129,    -1,     3,     4,
     101,   102,   103,  1136,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    51,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,  1202,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    -1,    -1,    65,    66,    -1,    68,
      69,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,    -1,   142,   143,    -1,
    1273,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,    -1,   159,   160,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,  1322,
      -1,   160,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,  1222,
      57,    -1,    59,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,
      -1,     6,    -1,    -1,  1257,    -1,  1379,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    -1,  1278,    65,    66,    -1,    68,
      69,    70,    -1,    -1,   121,    74,    -1,    -1,    -1,   126,
     127,   128,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    -1,   142,   143,    -1,   151,    -1,
     147,    -1,   101,   102,   103,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,     3,     4,     5,    -1,     7,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    -1,  1368,    45,  1370,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    12,    13,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,  1428,    62,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    -1,   115,    -1,    74,     6,
      -1,    -1,   121,   122,   123,    -1,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,   142,   143,   101,   102,   103,   147,    -1,
     149,   150,    -1,   152,    -1,   154,    -1,   156,   157,    -1,
     159,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    -1,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   121,
       6,    -1,    -1,   151,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
     152,    -1,     3,     4,     5,   157,    -1,   159,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     6,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,   152,    -1,     3,     4,     5,   157,    -1,   159,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    -1,    86,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,    -1,    -1,    -1,   151,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   121,     7,     8,    -1,   151,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,   152,    -1,     3,     4,    -1,   157,    -1,   159,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    -1,     7,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,   152,    -1,     3,     4,    -1,   157,    -1,
     159,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     8,   121,    -1,    -1,   151,    -1,   126,   127,
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
      77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,   152,    -1,     3,     4,    -1,
     157,    -1,   159,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      86,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     8,   121,    -1,    -1,   151,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,   152,    -1,     3,     4,
      -1,   157,    -1,   159,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,     3,
       4,     5,   157,    -1,   159,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    45,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    42,     3,     4,    45,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,   121,   122,   123,
      -1,    42,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
     121,    -1,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,   152,    -1,    -1,   155,    -1,   157,    -1,   159,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,     3,     4,     5,    -1,    42,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,     3,     4,
      -1,    -1,    -1,    42,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,   155,   121,   157,    -1,   159,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,   152,    -1,    -1,   121,    -1,   157,    -1,
     159,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,     3,
       4,    -1,   157,    -1,   159,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    -1,     3,     4,    83,
      -1,    -1,    86,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    42,   121,    -1,    -1,
      -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
      -1,    -1,    -1,   147,     3,     4,     5,    -1,   152,    -1,
       9,    10,    11,   157,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,   121,   122,   123,    12,    13,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,    -1,    -1,    -1,   147,    36,
      37,    -1,    -1,   152,    -1,    -1,    43,    44,   157,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,     4,    90,    91,    -1,    -1,    -1,    95,    -1,
      12,    13,    -1,   100,   101,   102,   103,    -1,    -1,   106,
      -1,   108,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    36,    37,    -1,   124,   125,    -1,
      -1,    43,    44,    -1,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    12,    13,    90,    91,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,    -1,    -1,   106,    -1,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,   125,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   101,   102,   103,   158,    -1,
     160,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,   160,   133,   134,   135,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   133,
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
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   133,   134,   135,   136,   137,   138,   139,   140,   141,
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
      -1,    -1,   151
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
       5,    35,    51,    54,    57,    59,    69,   143,   159,   204,
     213,   239,   244,   245,   246,     4,   152,   152,   152,     4,
     159,   248,     4,   152,   152,     6,     6,   154,     4,     4,
       5,   159,     5,   159,     6,   152,   159,     4,   154,   156,
     161,   185,   159,     5,   252,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   152,   154,   152,
     154,   152,   154,   152,   154,   152,   154,   152,   152,   152,
     152,   152,     7,   152,   152,   152,     4,   239,   239,   239,
     239,   155,   159,   239,     4,   106,   107,     4,     4,   204,
     205,   206,   244,     6,     6,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   151,
       6,     6,   239,     5,     5,   239,   188,   239,   143,   239,
     246,   247,   239,   239,   152,   239,   247,   239,   239,   152,
     247,   239,   239,   244,   152,   159,   152,   152,   245,   245,
     245,   152,   200,   201,   202,   203,   152,   152,   152,   244,
     239,     4,   244,   241,   241,   241,   239,   239,   142,   143,
     159,   159,   241,   159,   159,   159,   142,   143,   152,   206,
     241,   159,   152,   159,   152,   152,   152,   245,   244,   152,
       4,     6,   154,   154,   206,     6,   159,   159,   159,   154,
     154,   154,   154,     5,   159,     5,     5,     5,    51,    54,
      57,    59,   159,   239,   246,   160,   247,     8,   144,     6,
       6,   239,   239,   239,   156,   239,   159,   109,   239,   239,
     239,     6,     6,   206,     6,   206,   244,   244,   154,   239,
       4,   159,   169,     6,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,     4,   251,   252,   251,
     251,   251,   251,   239,   251,   251,   251,   154,   153,     7,
     184,   247,   155,     7,   184,   185,   156,     7,   154,   160,
      51,    54,    57,    59,   199,     6,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,     6,   153,   158,   153,   158,   158,   155,   158,   187,
     153,   144,   158,   160,   153,   153,   239,   153,   160,   153,
     153,   239,   160,   153,   153,     7,   239,   239,   239,   239,
       7,     7,   231,   231,   239,   152,   152,   152,   152,   239,
     239,   239,     7,   159,   153,     6,   158,   158,   158,   241,
     241,   205,   205,   158,   239,   239,   239,   239,   217,   158,
     206,   239,   239,   239,   239,   239,     7,   232,     7,   239,
       6,   239,   239,   160,   247,   247,   247,   239,   239,   155,
     159,   239,     4,   239,   159,   159,   159,   159,   247,   160,
     239,   159,   239,   246,   153,   153,   153,   106,   158,   206,
     159,     8,   153,   155,   160,   160,   153,   158,   160,   239,
     155,   185,   239,     4,    96,    97,    98,    99,   160,   172,
     176,   179,   181,   182,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     153,   155,   153,   155,   153,   155,   158,   158,   153,   155,
     153,   155,   153,   155,   153,   155,   153,   155,   153,   155,
     158,   158,   158,   158,   158,   158,   154,   156,   153,   158,
     158,   153,   153,   158,     6,   158,   153,   158,   244,   160,
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
     247,   155,   155,   160,   247,   247,   247,   247,   160,     8,
     247,     7,     7,     7,   156,   239,   160,   239,   239,     7,
     156,   159,   244,     6,   155,   156,   185,   251,   160,   173,
     152,   152,   159,   183,     6,   239,   239,   239,   239,   239,
     239,   239,   239,   239,     4,   247,   251,   251,   239,   251,
       6,   155,     4,   106,   107,   239,     6,     6,     6,     7,
     154,   248,   250,     6,   247,   247,   247,   247,   239,   139,
     251,   153,   153,   158,     7,   241,    57,   244,   244,     7,
     244,    57,    59,   244,   244,     7,    59,   244,   244,     6,
       7,     7,     7,     7,    72,   229,     6,     7,   153,   153,
     153,   153,     7,     7,     7,     6,   160,     4,   158,   158,
     158,   160,   160,   241,   241,   241,     4,     6,   159,   152,
       6,    94,     6,    94,   160,   228,   158,   227,     7,     6,
       7,     7,     7,     6,   159,     6,     6,     6,    57,   239,
       6,     6,   160,   160,   160,   160,   160,   239,   160,   244,
     244,   244,     4,   158,     8,     8,   153,     4,     4,   244,
     160,     6,     4,     6,   152,   239,   239,   243,   244,   159,
     153,   155,   153,   155,   153,   155,   153,   155,   155,   153,
     153,   153,   153,   153,   184,     7,   184,   185,   156,     7,
       6,   248,   239,   158,   160,   160,   160,   160,   160,     6,
       6,   166,     6,   239,   159,   239,   252,     6,   159,    65,
     198,   198,   244,     6,   159,   159,     6,     6,   244,   159,
       6,     6,     5,   244,   244,   244,     4,     6,   244,     7,
       7,     7,     7,   244,   244,   244,     7,     6,     7,   239,
     239,   239,   159,   159,   158,   160,   158,   160,   158,   160,
     154,   239,   244,   239,     6,     6,   239,   241,   160,     5,
     159,   244,   159,   159,   159,   244,   247,   159,     6,   155,
       6,     6,   105,   239,   239,   239,     6,     6,     7,   158,
       6,   185,   170,   239,   158,   158,   158,   160,   171,   239,
     156,   244,   252,   239,     6,     4,   249,     6,   155,   248,
       6,     6,     6,     6,   251,   158,   239,   252,   239,   241,
       6,     6,     6,   239,   239,     6,   239,     5,     6,     6,
     109,   197,   239,     6,   244,   244,   244,   244,     6,     4,
       6,     6,   239,   239,   252,   160,   153,   158,   160,   205,
     205,   241,     6,   218,   241,     6,   219,   241,     6,   220,
     239,   160,   158,   153,   160,   158,     6,   143,   241,     6,
     243,   241,   241,     6,   160,   239,   244,   158,   160,     8,
     160,   153,   159,   239,   252,   244,   153,   158,   239,   239,
     244,   159,   158,   160,     4,     6,     6,     6,     7,     6,
     156,     6,   239,   189,   190,   160,   160,   160,   160,     5,
      55,     6,     6,     6,     6,     6,   159,   159,     6,     6,
     159,   239,   160,   160,   158,   159,   158,   159,   158,   159,
     155,     6,   244,     7,   159,   239,   158,   160,   158,   158,
       6,   160,   104,   239,   239,   247,     6,     6,   160,   174,
     239,   158,   158,   243,   239,     6,   248,   107,   158,   192,
     194,     6,     6,     6,     6,     6,   159,   243,   247,   205,
     158,   160,   239,   241,   227,   239,   241,   227,   239,   241,
     227,     6,   158,   160,   244,   206,   160,   241,     6,   247,
     241,   239,   160,   160,   160,     6,   159,   239,   239,   160,
       6,   239,   158,   160,   193,   158,   160,   195,   239,   160,
     160,   160,   239,   160,   158,   160,   160,   158,   160,   160,
     158,   160,   244,     6,    72,   160,   215,   159,   158,   160,
     158,     6,     6,   171,   153,   158,     6,   159,   158,     4,
       4,   160,     6,     6,   160,     6,   221,   239,     6,     6,
     222,   239,     6,     6,   223,   239,     6,   160,   239,   227,
     206,   247,     6,   241,   247,   160,   177,   239,   243,   239,
       5,   159,   244,     5,   159,   239,   159,   160,   159,   160,
     159,   160,     6,     6,   160,   160,   216,   160,   158,   160,
       6,   159,   153,   160,   160,   191,   239,   251,   253,   227,
       6,   224,   227,     6,   225,   227,     6,   226,   227,     6,
     247,     6,   175,   251,   180,   159,     6,   158,   160,     7,
     158,   160,   160,   159,   160,   159,   160,   159,   160,   160,
     158,   160,   159,   243,   239,   252,   251,     6,   227,     6,
     227,     6,   227,     6,   251,     6,   178,   251,   160,     7,
     160,   160,   160,   158,   160,     6,   252,     6,     6,     6,
     251,     6
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
#line 741 "Gmsh.y"
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
#line 787 "Gmsh.y"
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
#line 802 "Gmsh.y"
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
#line 818 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 827 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c))
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 833 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c))
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 842 "Gmsh.y"
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
#line 860 "Gmsh.y"
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
#line 878 "Gmsh.y"
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
#line 887 "Gmsh.y"
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
#line 899 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 904 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 912 "Gmsh.y"
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
#line 932 "Gmsh.y"
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
#line 955 "Gmsh.y"
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
#line 966 "Gmsh.y"
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
#line 974 "Gmsh.y"
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
#line 996 "Gmsh.y"
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
#line 1019 "Gmsh.y"
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
#line 1045 "Gmsh.y"
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
#line 1066 "Gmsh.y"
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
#line 1078 "Gmsh.y"
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
#line 1096 "Gmsh.y"
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
#line 1107 "Gmsh.y"
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
#line 1118 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1120 "Gmsh.y"
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

  case 99:

/* Line 1464 of yacc.c  */
#line 1130 "Gmsh.y"
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

  case 100:

/* Line 1464 of yacc.c  */
#line 1141 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1143 "Gmsh.y"
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

  case 102:

/* Line 1464 of yacc.c  */
#line 1156 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 1162 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1174 "Gmsh.y"
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

  case 107:

/* Line 1464 of yacc.c  */
#line 1185 "Gmsh.y"
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

  case 108:

/* Line 1464 of yacc.c  */
#line 1200 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1216 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1224 "Gmsh.y"
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
#line 1233 "Gmsh.y"
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

  case 114:

/* Line 1464 of yacc.c  */
#line 1252 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1256 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1266 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1270 "Gmsh.y"
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

  case 118:

/* Line 1464 of yacc.c  */
#line 1282 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1286 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1296 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1323 "Gmsh.y"
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

  case 123:

/* Line 1464 of yacc.c  */
#line 1339 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1361 "Gmsh.y"
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

  case 125:

/* Line 1464 of yacc.c  */
#line 1379 "Gmsh.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 1400 "Gmsh.y"
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

  case 127:

/* Line 1464 of yacc.c  */
#line 1418 "Gmsh.y"
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

  case 128:

/* Line 1464 of yacc.c  */
#line 1448 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1478 "Gmsh.y"
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

  case 130:

/* Line 1464 of yacc.c  */
#line 1496 "Gmsh.y"
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

  case 131:

/* Line 1464 of yacc.c  */
#line 1514 "Gmsh.y"
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

  case 132:

/* Line 1464 of yacc.c  */
#line 1540 "Gmsh.y"
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

  case 133:

/* Line 1464 of yacc.c  */
#line 1558 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1576 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1580 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1599 "Gmsh.y"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1617 "Gmsh.y"
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

  case 138:

/* Line 1464 of yacc.c  */
#line 1656 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1662 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1668 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1675 "Gmsh.y"
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

  case 142:

/* Line 1464 of yacc.c  */
#line 1700 "Gmsh.y"
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

  case 143:

/* Line 1464 of yacc.c  */
#line 1725 "Gmsh.y"
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

  case 144:

/* Line 1464 of yacc.c  */
#line 1742 "Gmsh.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1760 "Gmsh.y"
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

  case 146:

/* Line 1464 of yacc.c  */
#line 1790 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1794 "Gmsh.y"
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

  case 148:

/* Line 1464 of yacc.c  */
#line 1814 "Gmsh.y"
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

  case 149:

/* Line 1464 of yacc.c  */
#line 1832 "Gmsh.y"
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

  case 150:

/* Line 1464 of yacc.c  */
#line 1849 "Gmsh.y"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1865 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1869 "Gmsh.y"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 1891 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1896 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1901 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1906 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1911 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1916 "Gmsh.y"
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

  case 159:

/* Line 1464 of yacc.c  */
#line 1939 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1945 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1955 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1956 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1961 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1965 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1969 "Gmsh.y"
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

  case 166:

/* Line 1464 of yacc.c  */
#line 1992 "Gmsh.y"
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

  case 167:

/* Line 1464 of yacc.c  */
#line 2015 "Gmsh.y"
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

  case 168:

/* Line 1464 of yacc.c  */
#line 2038 "Gmsh.y"
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

  case 169:

/* Line 1464 of yacc.c  */
#line 2066 "Gmsh.y"
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

  case 170:

/* Line 1464 of yacc.c  */
#line 2087 "Gmsh.y"
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

  case 171:

/* Line 1464 of yacc.c  */
#line 2111 "Gmsh.y"
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

  case 172:

/* Line 1464 of yacc.c  */
#line 2132 "Gmsh.y"
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

  case 173:

/* Line 1464 of yacc.c  */
#line 2153 "Gmsh.y"
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

  case 174:

/* Line 1464 of yacc.c  */
#line 2173 "Gmsh.y"
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

  case 175:

/* Line 1464 of yacc.c  */
#line 2285 "Gmsh.y"
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

  case 176:

/* Line 1464 of yacc.c  */
#line 2304 "Gmsh.y"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 2343 "Gmsh.y"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 2451 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 2460 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 2466 "Gmsh.y"
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

  case 181:

/* Line 1464 of yacc.c  */
#line 2481 "Gmsh.y"
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

  case 182:

/* Line 1464 of yacc.c  */
#line 2509 "Gmsh.y"
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

  case 183:

/* Line 1464 of yacc.c  */
#line 2526 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 2540 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 2546 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 2552 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2561 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2575 "Gmsh.y"
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

  case 189:

/* Line 1464 of yacc.c  */
#line 2620 "Gmsh.y"
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

  case 190:

/* Line 1464 of yacc.c  */
#line 2637 "Gmsh.y"
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

  case 191:

/* Line 1464 of yacc.c  */
#line 2652 "Gmsh.y"
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

  case 192:

/* Line 1464 of yacc.c  */
#line 2671 "Gmsh.y"
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

  case 193:

/* Line 1464 of yacc.c  */
#line 2683 "Gmsh.y"
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

  case 194:

/* Line 1464 of yacc.c  */
#line 2707 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 2711 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 2716 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 2723 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2729 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2734 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2740 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2744 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2748 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2758 "Gmsh.y"
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

  case 204:

/* Line 1464 of yacc.c  */
#line 2775 "Gmsh.y"
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

  case 205:

/* Line 1464 of yacc.c  */
#line 2792 "Gmsh.y"
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

  case 206:

/* Line 1464 of yacc.c  */
#line 2813 "Gmsh.y"
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

  case 207:

/* Line 1464 of yacc.c  */
#line 2834 "Gmsh.y"
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

  case 208:

/* Line 1464 of yacc.c  */
#line 2869 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 2877 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 2883 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 2890 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 2894 "Gmsh.y"
    {
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2903 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2911 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2919 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2927 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 2932 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 2940 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 2945 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 2953 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 2958 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 2966 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 2986 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 2993 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 3000 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 3007 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3014 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3021 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3028 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3035 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3042 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3047 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3054 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3059 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3066 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3071 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3078 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3083 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3090 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3095 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3102 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3107 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3114 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3119 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3126 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3131 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3143 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3154 "Gmsh.y"
    {
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3157 "Gmsh.y"
    {
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3172 "Gmsh.y"
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

  case 255:

/* Line 1464 of yacc.c  */
#line 3192 "Gmsh.y"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 3215 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3219 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3223 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 3227 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 3231 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3235 "Gmsh.y"
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

  case 262:

/* Line 1464 of yacc.c  */
#line 3254 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3266 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 3270 "Gmsh.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 3285 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 3289 "Gmsh.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 3301 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3305 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3314 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 3321 "Gmsh.y"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 3377 "Gmsh.y"
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

  case 273:

/* Line 1464 of yacc.c  */
#line 3447 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3452 "Gmsh.y"
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

  case 275:

/* Line 1464 of yacc.c  */
#line 3519 "Gmsh.y"
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

  case 276:

/* Line 1464 of yacc.c  */
#line 3555 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 3564 "Gmsh.y"
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

  case 278:

/* Line 1464 of yacc.c  */
#line 3607 "Gmsh.y"
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

  case 279:

/* Line 1464 of yacc.c  */
#line 3632 "Gmsh.y"
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

  case 280:

/* Line 1464 of yacc.c  */
#line 3660 "Gmsh.y"
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

  case 281:

/* Line 1464 of yacc.c  */
#line 3703 "Gmsh.y"
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

  case 282:

/* Line 1464 of yacc.c  */
#line 3726 "Gmsh.y"
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

  case 283:

/* Line 1464 of yacc.c  */
#line 3749 "Gmsh.y"
    {
    ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 3752 "Gmsh.y"
    {
    ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 3761 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 3765 "Gmsh.y"
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

  case 287:

/* Line 1464 of yacc.c  */
#line 3775 "Gmsh.y"
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

  case 288:

/* Line 1464 of yacc.c  */
#line 3809 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3810 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3815 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3820 "Gmsh.y"
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

  case 292:

/* Line 1464 of yacc.c  */
#line 3831 "Gmsh.y"
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

  case 293:

/* Line 1464 of yacc.c  */
#line 3848 "Gmsh.y"
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

  case 294:

/* Line 1464 of yacc.c  */
#line 3875 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 3876 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 3877 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 3878 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 3879 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 3880 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 3881 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 3882 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 3884 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 3890 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 3891 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 3892 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 3893 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 3894 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 3895 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 3896 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 3897 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 3898 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 3899 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 3900 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 3901 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 3902 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 3903 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 3904 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 3905 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 3906 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 3907 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 3908 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 3909 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 3910 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 3911 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 3912 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 3913 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 3914 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 3915 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 3916 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 3917 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 3918 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 3919 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 3920 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 3921 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 3923 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 3924 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 3925 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 3926 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 3927 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 3928 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 3929 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 3930 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 3931 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 3932 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 3933 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 3934 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 3935 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 3936 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 3937 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 3938 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 3939 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 3940 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 3941 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 3942 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 3943 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 3952 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 3953 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 3954 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 3955 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 3956 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 3957 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 3958 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 3963 "Gmsh.y"
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

  case 364:

/* Line 1464 of yacc.c  */
#line 3983 "Gmsh.y"
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

  case 365:

/* Line 1464 of yacc.c  */
#line 4002 "Gmsh.y"
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

  case 366:

/* Line 1464 of yacc.c  */
#line 4020 "Gmsh.y"
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

  case 367:

/* Line 1464 of yacc.c  */
#line 4032 "Gmsh.y"
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

  case 368:

/* Line 1464 of yacc.c  */
#line 4049 "Gmsh.y"
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

  case 369:

/* Line 1464 of yacc.c  */
#line 4070 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4075 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4080 "Gmsh.y"
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

  case 372:

/* Line 1464 of yacc.c  */
#line 4090 "Gmsh.y"
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

  case 373:

/* Line 1464 of yacc.c  */
#line 4100 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 4105 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 4117 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 4121 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 4125 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4129 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4133 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 4140 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 4144 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4148 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4152 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 4159 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4164 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4171 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4176 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4180 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4185 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4189 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4197 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4208 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4212 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4224 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4232 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4240 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4247 "Gmsh.y"
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

  case 398:

/* Line 1464 of yacc.c  */
#line 4258 "Gmsh.y"
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

  case 399:

/* Line 1464 of yacc.c  */
#line 4278 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4282 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4286 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4290 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4294 "Gmsh.y"
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

  case 404:

/* Line 1464 of yacc.c  */
#line 4312 "Gmsh.y"
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

  case 405:

/* Line 1464 of yacc.c  */
#line 4330 "Gmsh.y"
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

  case 406:

/* Line 1464 of yacc.c  */
#line 4348 "Gmsh.y"
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

  case 407:

/* Line 1464 of yacc.c  */
#line 4366 "Gmsh.y"
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

  case 408:

/* Line 1464 of yacc.c  */
#line 4376 "Gmsh.y"
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

  case 409:

/* Line 1464 of yacc.c  */
#line 4386 "Gmsh.y"
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

  case 410:

/* Line 1464 of yacc.c  */
#line 4398 "Gmsh.y"
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

  case 411:

/* Line 1464 of yacc.c  */
#line 4410 "Gmsh.y"
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

  case 412:

/* Line 1464 of yacc.c  */
#line 4431 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 4436 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 4440 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 4444 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 4456 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 4460 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 4472 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 4479 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 4489 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 4493 "Gmsh.y"
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

  case 422:

/* Line 1464 of yacc.c  */
#line 4508 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 4513 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4520 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4524 "Gmsh.y"
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

  case 426:

/* Line 1464 of yacc.c  */
#line 4537 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4545 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 4556 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 4560 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 4568 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4576 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 4584 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 4592 "Gmsh.y"
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

  case 434:

/* Line 1464 of yacc.c  */
#line 4606 "Gmsh.y"
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

  case 435:

/* Line 1464 of yacc.c  */
#line 4620 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4624 "Gmsh.y"
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

  case 437:

/* Line 1464 of yacc.c  */
#line 4646 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4651 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10455 "Gmsh.tab.cpp"
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
#line 4654 "Gmsh.y"


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

