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
#include "HighOrder.h"
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
#line 173 "Gmsh.tab.cpp"

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
     tUndefineConstant = 307,
     tPoint = 308,
     tCircle = 309,
     tEllipse = 310,
     tLine = 311,
     tSphere = 312,
     tPolarSphere = 313,
     tSurface = 314,
     tSpline = 315,
     tVolume = 316,
     tCharacteristic = 317,
     tLength = 318,
     tParametric = 319,
     tElliptic = 320,
     tRefineMesh = 321,
     tPlane = 322,
     tRuled = 323,
     tTransfinite = 324,
     tComplex = 325,
     tPhysical = 326,
     tCompound = 327,
     tPeriodic = 328,
     tUsing = 329,
     tPlugin = 330,
     tDegenerated = 331,
     tRotate = 332,
     tTranslate = 333,
     tSymmetry = 334,
     tDilate = 335,
     tExtrude = 336,
     tLevelset = 337,
     tRecombine = 338,
     tSmoother = 339,
     tSplit = 340,
     tDelete = 341,
     tCoherence = 342,
     tIntersect = 343,
     tMeshAlgorithm = 344,
     tReverse = 345,
     tLayers = 346,
     tHole = 347,
     tAlias = 348,
     tAliasWithOptions = 349,
     tQuadTriDbl = 350,
     tQuadTriSngl = 351,
     tRecombLaterals = 352,
     tTransfQuadTri = 353,
     tText2D = 354,
     tText3D = 355,
     tInterpolationScheme = 356,
     tTime = 357,
     tCombine = 358,
     tBSpline = 359,
     tBezier = 360,
     tNurbs = 361,
     tNurbsOrder = 362,
     tNurbsKnots = 363,
     tColor = 364,
     tColorTable = 365,
     tFor = 366,
     tIn = 367,
     tEndFor = 368,
     tIf = 369,
     tEndIf = 370,
     tExit = 371,
     tAbort = 372,
     tField = 373,
     tReturn = 374,
     tCall = 375,
     tFunction = 376,
     tShow = 377,
     tHide = 378,
     tGetValue = 379,
     tGetEnv = 380,
     tGetString = 381,
     tHomology = 382,
     tCohomology = 383,
     tBetti = 384,
     tSetOrder = 385,
     tGMSH_MAJOR_VERSION = 386,
     tGMSH_MINOR_VERSION = 387,
     tGMSH_PATCH_VERSION = 388,
     tAFFECTDIVIDE = 389,
     tAFFECTTIMES = 390,
     tAFFECTMINUS = 391,
     tAFFECTPLUS = 392,
     tOR = 393,
     tAND = 394,
     tNOTEQUAL = 395,
     tEQUAL = 396,
     tGREATEROREQUAL = 397,
     tLESSOREQUAL = 398,
     UNARYPREC = 399,
     tMINUSMINUS = 400,
     tPLUSPLUS = 401
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 93 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 214 of yacc.c  */
#line 367 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 379 "Gmsh.tab.cpp"

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
#define YYLAST   8053

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  449
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1544

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   401

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   152,     2,   162,     2,   151,     2,     2,
     157,   158,   149,   147,   163,   148,   161,   150,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     143,     2,   144,   138,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   159,     2,   160,   156,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   164,     2,   165,   166,     2,     2,     2,
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
     135,   136,   137,   139,   140,   141,   142,   145,   146,   153,
     154,   155
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   115,   118,   121,   124,   127,   130,   132,
     136,   138,   142,   143,   144,   155,   157,   161,   162,   176,
     178,   182,   183,   199,   208,   223,   224,   231,   233,   235,
     237,   239,   241,   243,   245,   251,   257,   262,   269,   277,
     285,   295,   305,   309,   316,   321,   328,   338,   345,   355,
     361,   370,   379,   391,   398,   408,   414,   422,   432,   442,
     454,   462,   472,   482,   483,   485,   486,   490,   496,   497,
     507,   513,   514,   524,   525,   529,   533,   539,   540,   543,
     547,   553,   557,   558,   561,   565,   569,   575,   577,   579,
     580,   586,   587,   590,   598,   599,   609,   616,   624,   629,
     637,   646,   655,   663,   671,   683,   692,   701,   702,   712,
     721,   731,   735,   740,   751,   759,   767,   776,   785,   798,
     799,   809,   818,   826,   835,   836,   846,   852,   864,   870,
     880,   890,   895,   905,   915,   917,   919,   920,   923,   930,
     937,   944,   951,   960,   971,   986,  1003,  1016,  1025,  1034,
    1041,  1056,  1061,  1068,  1075,  1079,  1084,  1090,  1094,  1098,
    1103,  1108,  1112,  1120,  1128,  1132,  1140,  1144,  1147,  1150,
    1153,  1156,  1172,  1175,  1178,  1181,  1184,  1188,  1195,  1204,
    1213,  1224,  1226,  1229,  1231,  1235,  1240,  1242,  1248,  1260,
    1274,  1275,  1283,  1284,  1298,  1299,  1315,  1316,  1323,  1332,
    1341,  1350,  1363,  1376,  1389,  1404,  1419,  1434,  1435,  1448,
    1449,  1462,  1463,  1476,  1477,  1494,  1495,  1512,  1513,  1530,
    1531,  1550,  1551,  1570,  1571,  1590,  1592,  1595,  1601,  1609,
    1619,  1622,  1625,  1629,  1632,  1636,  1646,  1653,  1654,  1658,
    1659,  1661,  1662,  1665,  1666,  1669,  1677,  1684,  1693,  1699,
    1703,  1711,  1717,  1722,  1729,  1736,  1749,  1760,  1771,  1782,
    1793,  1798,  1803,  1806,  1810,  1817,  1819,  1821,  1823,  1826,
    1832,  1840,  1851,  1853,  1857,  1860,  1863,  1866,  1870,  1874,
    1878,  1882,  1886,  1890,  1894,  1898,  1902,  1906,  1910,  1914,
    1918,  1922,  1928,  1933,  1938,  1943,  1948,  1953,  1958,  1963,
    1968,  1973,  1978,  1985,  1990,  1995,  2000,  2005,  2010,  2015,
    2022,  2029,  2036,  2041,  2046,  2051,  2056,  2061,  2066,  2071,
    2076,  2081,  2086,  2091,  2098,  2103,  2108,  2113,  2118,  2123,
    2128,  2135,  2142,  2149,  2154,  2156,  2158,  2160,  2162,  2164,
    2166,  2168,  2170,  2176,  2181,  2186,  2189,  2195,  2199,  2206,
    2211,  2219,  2226,  2233,  2238,  2240,  2243,  2246,  2250,  2254,
    2266,  2276,  2284,  2292,  2294,  2298,  2300,  2302,  2305,  2309,
    2314,  2320,  2322,  2324,  2327,  2331,  2335,  2341,  2346,  2349,
    2352,  2355,  2358,  2364,  2370,  2376,  2382,  2384,  2386,  2390,
    2394,  2399,  2406,  2413,  2415,  2417,  2421,  2425,  2435,  2443,
    2445,  2451,  2455,  2462,  2464,  2468,  2470,  2472,  2476,  2483,
    2485,  2487,  2492,  2499,  2506,  2511,  2516,  2521,  2528,  2530
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,   169,    -1,     1,     6,    -1,    -1,   169,
     170,    -1,   173,    -1,   172,    -1,   191,    -1,   205,    -1,
     210,    -1,   214,    -1,   215,    -1,   216,    -1,   219,    -1,
     239,    -1,   240,    -1,   218,    -1,   217,    -1,   213,    -1,
     242,    -1,   144,    -1,   144,   144,    -1,    36,   157,     5,
     158,     6,    -1,    37,   157,     5,   158,     6,    -1,    36,
     157,     5,   158,   171,   255,     6,    -1,    36,   157,     5,
     163,   251,   158,     6,    -1,    37,   157,     5,   163,   251,
     158,     6,    -1,    36,   157,     5,   163,   251,   158,   171,
     255,     6,    -1,     4,     5,   164,   174,   165,     6,    -1,
      93,     4,   159,   243,   160,     6,    -1,    94,     4,   159,
     243,   160,     6,    -1,    -1,   174,   177,    -1,   174,   181,
      -1,   174,   184,    -1,   174,   186,    -1,   174,   187,    -1,
     243,    -1,   175,   163,   243,    -1,   243,    -1,   176,   163,
     243,    -1,    -1,    -1,     4,   178,   157,   175,   158,   179,
     164,   176,   165,     6,    -1,   255,    -1,   180,   163,   255,
      -1,    -1,    99,   157,   243,   163,   243,   163,   243,   158,
     182,   164,   180,   165,     6,    -1,   255,    -1,   183,   163,
     255,    -1,    -1,   100,   157,   243,   163,   243,   163,   243,
     163,   243,   158,   185,   164,   183,   165,     6,    -1,   101,
     164,   247,   165,   164,   247,   165,     6,    -1,   101,   164,
     247,   165,   164,   247,   165,   164,   247,   165,   164,   247,
     165,     6,    -1,    -1,   102,   188,   164,   176,   165,     6,
      -1,     7,    -1,   137,    -1,   136,    -1,   135,    -1,   134,
      -1,   155,    -1,   154,    -1,    51,   159,   193,   160,     6,
      -1,    52,   159,   196,   160,     6,    -1,     4,   189,   248,
       6,    -1,     4,   159,   160,   189,   248,     6,    -1,     4,
     159,   243,   160,   189,   243,     6,    -1,     4,   157,   243,
     158,   189,   243,     6,    -1,     4,   159,   164,   251,   165,
     160,   189,   248,     6,    -1,     4,   157,   164,   251,   165,
     158,   189,   248,     6,    -1,     4,   190,     6,    -1,     4,
     159,   243,   160,   190,     6,    -1,     4,     7,   256,     6,
      -1,     4,   161,     4,     7,   256,     6,    -1,     4,   159,
     243,   160,   161,     4,     7,   256,     6,    -1,     4,   161,
       4,   189,   243,     6,    -1,     4,   159,   243,   160,   161,
       4,   189,   243,     6,    -1,     4,   161,     4,   190,     6,
      -1,     4,   159,   243,   160,   161,     4,   190,     6,    -1,
       4,   161,   109,   161,     4,     7,   252,     6,    -1,     4,
     159,   243,   160,   161,   109,   161,     4,     7,   252,     6,
      -1,     4,   161,   110,     7,   253,     6,    -1,     4,   159,
     243,   160,   161,   110,     7,   253,     6,    -1,     4,   118,
       7,   243,     6,    -1,   118,   159,   243,   160,     7,     4,
       6,    -1,   118,   159,   243,   160,   161,     4,     7,   243,
       6,    -1,   118,   159,   243,   160,   161,     4,     7,   256,
       6,    -1,   118,   159,   243,   160,   161,     4,     7,   164,
     251,   165,     6,    -1,   118,   159,   243,   160,   161,     4,
       6,    -1,    75,   157,     4,   158,   161,     4,     7,   243,
       6,    -1,    75,   157,     4,   158,   161,     4,     7,   256,
       6,    -1,    -1,   163,    -1,    -1,   193,   192,     4,    -1,
     193,   192,     4,     7,   243,    -1,    -1,   193,   192,     4,
       7,   164,   243,   194,   198,   165,    -1,   193,   192,     4,
       7,   256,    -1,    -1,   193,   192,     4,     7,   164,   256,
     195,   200,   165,    -1,    -1,   196,   192,   255,    -1,   243,
       7,   256,    -1,   197,   163,   243,     7,   256,    -1,    -1,
     198,   199,    -1,   163,     4,   248,    -1,   163,     4,   164,
     197,   165,    -1,   163,     4,     5,    -1,    -1,   200,   201,
      -1,   163,     4,   243,    -1,   163,     4,     5,    -1,   163,
       4,   164,   257,   165,    -1,   243,    -1,   256,    -1,    -1,
     112,    57,   164,   243,   165,    -1,    -1,    67,   245,    -1,
      53,   157,   243,   158,     7,   245,     6,    -1,    -1,    71,
      53,   206,   157,   202,   158,     7,   248,     6,    -1,    62,
      63,   248,     7,   243,     6,    -1,    56,   157,   243,   158,
       7,   248,     6,    -1,    76,    56,   248,     6,    -1,    60,
     157,   243,   158,     7,   248,     6,    -1,    54,   157,   243,
     158,     7,   248,   204,     6,    -1,    55,   157,   243,   158,
       7,   248,   204,     6,    -1,   104,   157,   243,   158,     7,
     248,     6,    -1,   105,   157,   243,   158,     7,   248,     6,
      -1,   106,   157,   243,   158,     7,   248,   108,   248,   107,
     243,     6,    -1,    56,     4,   157,   243,   158,     7,   248,
       6,    -1,    72,    56,   157,   243,   158,     7,   248,     6,
      -1,    -1,    71,    56,   207,   157,   202,   158,     7,   248,
       6,    -1,    67,    59,   157,   243,   158,     7,   248,     6,
      -1,    68,    59,   157,   243,   158,     7,   248,   203,     6,
      -1,    12,    13,     6,    -1,    13,    59,   243,     6,    -1,
      64,    59,   157,   243,   158,     7,     5,     5,     5,     6,
      -1,    57,   157,   243,   158,     7,   248,     6,    -1,    58,
     157,   243,   158,     7,   248,     6,    -1,    59,     4,   157,
     243,   158,     7,   248,     6,    -1,    72,    59,   157,   243,
     158,     7,   248,     6,    -1,    72,    59,   157,   243,   158,
       7,   248,     4,   164,   247,   165,     6,    -1,    -1,    71,
      59,   208,   157,   202,   158,     7,   248,     6,    -1,    70,
      61,   157,   243,   158,     7,   248,     6,    -1,    61,   157,
     243,   158,     7,   248,     6,    -1,    72,    61,   157,   243,
     158,     7,   248,     6,    -1,    -1,    71,    61,   209,   157,
     202,   158,     7,   248,     6,    -1,    78,   245,   164,   211,
     165,    -1,    77,   164,   245,   163,   245,   163,   243,   165,
     164,   211,   165,    -1,    79,   245,   164,   211,   165,    -1,
      80,   164,   245,   163,   243,   165,   164,   211,   165,    -1,
      80,   164,   245,   163,   245,   165,   164,   211,   165,    -1,
       4,   164,   211,   165,    -1,    88,    56,   164,   251,   165,
      59,   164,   243,   165,    -1,    85,    56,   157,   243,   158,
     164,   251,   165,     6,    -1,   212,    -1,   210,    -1,    -1,
     212,   205,    -1,   212,    53,   164,   251,   165,     6,    -1,
     212,    56,   164,   251,   165,     6,    -1,   212,    59,   164,
     251,   165,     6,    -1,   212,    61,   164,   251,   165,     6,
      -1,    82,    67,   157,   243,   158,     7,   248,     6,    -1,
      82,    53,   157,   243,   158,     7,   164,   247,   165,     6,
      -1,    82,    67,   157,   243,   158,     7,   164,   245,   163,
     245,   163,   251,   165,     6,    -1,    82,    67,   157,   243,
     158,     7,   164,   245,   163,   245,   163,   245,   163,   251,
     165,     6,    -1,    82,    57,   157,   243,   158,     7,   164,
     245,   163,   251,   165,     6,    -1,    82,     4,   157,   243,
     158,     7,   248,     6,    -1,    82,     4,   157,   243,   158,
       7,     5,     6,    -1,    82,     4,   164,   243,   165,     6,
      -1,    82,     4,   157,   243,   158,     7,   164,   245,   163,
     245,   163,   251,   165,     6,    -1,    86,   164,   212,   165,
      -1,    86,   118,   159,   243,   160,     6,    -1,    86,     4,
     159,   243,   160,     6,    -1,    86,     4,     6,    -1,    86,
       4,     4,     6,    -1,   109,   252,   164,   212,   165,    -1,
     122,     5,     6,    -1,   123,     5,     6,    -1,   122,   164,
     212,   165,    -1,   123,   164,   212,   165,    -1,     4,   256,
       6,    -1,     4,     4,   159,   243,   160,   255,     6,    -1,
       4,     4,     4,   159,   243,   160,     6,    -1,     4,   243,
       6,    -1,    75,   157,     4,   158,   161,     4,     6,    -1,
     103,     4,     6,    -1,   116,     6,    -1,   117,     6,    -1,
      47,     6,    -1,    44,     6,    -1,    44,   164,   243,   163,
     243,   163,   243,   163,   243,   163,   243,   163,   243,   165,
       6,    -1,    45,     6,    -1,    48,     6,    -1,    49,     6,
      -1,    66,     6,    -1,   130,   243,     6,    -1,   111,   157,
     243,     8,   243,   158,    -1,   111,   157,   243,     8,   243,
       8,   243,   158,    -1,   111,     4,   112,   164,   243,     8,
     243,   165,    -1,   111,     4,   112,   164,   243,     8,   243,
       8,   243,   165,    -1,   113,    -1,   121,     4,    -1,   119,
      -1,   120,     4,     6,    -1,   114,   157,   243,   158,    -1,
     115,    -1,    81,   245,   164,   212,   165,    -1,    81,   164,
     245,   163,   245,   163,   243,   165,   164,   212,   165,    -1,
      81,   164,   245,   163,   245,   163,   245,   163,   243,   165,
     164,   212,   165,    -1,    -1,    81,   245,   164,   212,   220,
     233,   165,    -1,    -1,    81,   164,   245,   163,   245,   163,
     243,   165,   164,   212,   221,   233,   165,    -1,    -1,    81,
     164,   245,   163,   245,   163,   245,   163,   243,   165,   164,
     212,   222,   233,   165,    -1,    -1,    81,   164,   212,   223,
     233,   165,    -1,    81,    53,   164,   243,   163,   245,   165,
       6,    -1,    81,    56,   164,   243,   163,   245,   165,     6,
      -1,    81,    59,   164,   243,   163,   245,   165,     6,    -1,
      81,    53,   164,   243,   163,   245,   163,   245,   163,   243,
     165,     6,    -1,    81,    56,   164,   243,   163,   245,   163,
     245,   163,   243,   165,     6,    -1,    81,    59,   164,   243,
     163,   245,   163,   245,   163,   243,   165,     6,    -1,    81,
      53,   164,   243,   163,   245,   163,   245,   163,   245,   163,
     243,   165,     6,    -1,    81,    56,   164,   243,   163,   245,
     163,   245,   163,   245,   163,   243,   165,     6,    -1,    81,
      59,   164,   243,   163,   245,   163,   245,   163,   245,   163,
     243,   165,     6,    -1,    -1,    81,    53,   164,   243,   163,
     245,   165,   224,   164,   233,   165,     6,    -1,    -1,    81,
      56,   164,   243,   163,   245,   165,   225,   164,   233,   165,
       6,    -1,    -1,    81,    59,   164,   243,   163,   245,   165,
     226,   164,   233,   165,     6,    -1,    -1,    81,    53,   164,
     243,   163,   245,   163,   245,   163,   243,   165,   227,   164,
     233,   165,     6,    -1,    -1,    81,    56,   164,   243,   163,
     245,   163,   245,   163,   243,   165,   228,   164,   233,   165,
       6,    -1,    -1,    81,    59,   164,   243,   163,   245,   163,
     245,   163,   243,   165,   229,   164,   233,   165,     6,    -1,
      -1,    81,    53,   164,   243,   163,   245,   163,   245,   163,
     245,   163,   243,   165,   230,   164,   233,   165,     6,    -1,
      -1,    81,    56,   164,   243,   163,   245,   163,   245,   163,
     245,   163,   243,   165,   231,   164,   233,   165,     6,    -1,
      -1,    81,    59,   164,   243,   163,   245,   163,   245,   163,
     245,   163,   243,   165,   232,   164,   233,   165,     6,    -1,
     234,    -1,   233,   234,    -1,    91,   164,   243,   165,     6,
      -1,    91,   164,   248,   163,   248,   165,     6,    -1,    91,
     164,   248,   163,   248,   163,   248,   165,     6,    -1,    83,
       6,    -1,    95,     6,    -1,    95,    97,     6,    -1,    96,
       6,    -1,    96,    97,     6,    -1,    92,   157,   243,   158,
       7,   248,    74,   243,     6,    -1,    74,     4,   159,   243,
     160,     6,    -1,    -1,    74,     4,   243,    -1,    -1,     4,
      -1,    -1,     7,   248,    -1,    -1,     7,   243,    -1,    69,
      56,   249,     7,   243,   235,     6,    -1,    69,    59,   249,
     237,   236,     6,    -1,    65,    59,   164,   243,   165,     7,
     248,     6,    -1,    69,    61,   249,   237,     6,    -1,    98,
     249,     6,    -1,    89,    59,   164,   251,   165,   243,     6,
      -1,    83,    59,   249,   238,     6,    -1,    83,    61,   249,
       6,    -1,    84,    59,   248,     7,   243,     6,    -1,    73,
      56,   248,     7,   248,     6,    -1,    73,    59,   243,   164,
     251,   165,     7,   243,   164,   251,   165,     6,    -1,    53,
     164,   251,   165,   112,    59,   164,   243,   165,     6,    -1,
      56,   164,   251,   165,   112,    59,   164,   243,   165,     6,
      -1,    56,   164,   251,   165,   112,    61,   164,   243,   165,
       6,    -1,    59,   164,   251,   165,   112,    61,   164,   243,
     165,     6,    -1,    90,    59,   249,     6,    -1,    90,    56,
     249,     6,    -1,    87,     6,    -1,    87,     4,     6,    -1,
      87,    53,   164,   251,   165,     6,    -1,   127,    -1,   128,
      -1,   129,    -1,   241,     6,    -1,   241,   164,   248,   165,
       6,    -1,   241,   164,   248,   163,   248,   165,     6,    -1,
     241,   157,   248,   158,   164,   248,   163,   248,   165,     6,
      -1,   244,    -1,   157,   243,   158,    -1,   148,   243,    -1,
     147,   243,    -1,   152,   243,    -1,   243,   148,   243,    -1,
     243,   147,   243,    -1,   243,   149,   243,    -1,   243,   150,
     243,    -1,   243,   151,   243,    -1,   243,   156,   243,    -1,
     243,   143,   243,    -1,   243,   144,   243,    -1,   243,   146,
     243,    -1,   243,   145,   243,    -1,   243,   142,   243,    -1,
     243,   141,   243,    -1,   243,   140,   243,    -1,   243,   139,
     243,    -1,   243,   138,   243,     8,   243,    -1,    14,   157,
     243,   158,    -1,    15,   157,   243,   158,    -1,    16,   157,
     243,   158,    -1,    17,   157,   243,   158,    -1,    18,   157,
     243,   158,    -1,    19,   157,   243,   158,    -1,    20,   157,
     243,   158,    -1,    21,   157,   243,   158,    -1,    22,   157,
     243,   158,    -1,    24,   157,   243,   158,    -1,    25,   157,
     243,   163,   243,   158,    -1,    26,   157,   243,   158,    -1,
      27,   157,   243,   158,    -1,    28,   157,   243,   158,    -1,
      29,   157,   243,   158,    -1,    30,   157,   243,   158,    -1,
      31,   157,   243,   158,    -1,    32,   157,   243,   163,   243,
     158,    -1,    33,   157,   243,   163,   243,   158,    -1,    34,
     157,   243,   163,   243,   158,    -1,    23,   157,   243,   158,
      -1,    14,   159,   243,   160,    -1,    15,   159,   243,   160,
      -1,    16,   159,   243,   160,    -1,    17,   159,   243,   160,
      -1,    18,   159,   243,   160,    -1,    19,   159,   243,   160,
      -1,    20,   159,   243,   160,    -1,    21,   159,   243,   160,
      -1,    22,   159,   243,   160,    -1,    24,   159,   243,   160,
      -1,    25,   159,   243,   163,   243,   160,    -1,    26,   159,
     243,   160,    -1,    27,   159,   243,   160,    -1,    28,   159,
     243,   160,    -1,    29,   159,   243,   160,    -1,    30,   159,
     243,   160,    -1,    31,   159,   243,   160,    -1,    32,   159,
     243,   163,   243,   160,    -1,    33,   159,   243,   163,   243,
     160,    -1,    34,   159,   243,   163,   243,   160,    -1,    23,
     159,   243,   160,    -1,     3,    -1,     9,    -1,    10,    -1,
      11,    -1,   131,    -1,   132,    -1,   133,    -1,     4,    -1,
       4,   166,   164,   243,   165,    -1,     4,   159,   243,   160,
      -1,   162,     4,   159,   160,    -1,     4,   190,    -1,     4,
     159,   243,   160,   190,    -1,     4,   161,     4,    -1,     4,
     159,   243,   160,   161,     4,    -1,     4,   161,     4,   190,
      -1,     4,   159,   243,   160,   161,     4,   190,    -1,   124,
     157,   255,   163,   243,   158,    -1,    42,   157,   255,   163,
     255,   158,    -1,    43,   157,   257,   158,    -1,   246,    -1,
     148,   245,    -1,   147,   245,    -1,   245,   148,   245,    -1,
     245,   147,   245,    -1,   164,   243,   163,   243,   163,   243,
     163,   243,   163,   243,   165,    -1,   164,   243,   163,   243,
     163,   243,   163,   243,   165,    -1,   164,   243,   163,   243,
     163,   243,   165,    -1,   157,   243,   163,   243,   163,   243,
     158,    -1,   248,    -1,   247,   163,   248,    -1,   243,    -1,
     250,    -1,   164,   165,    -1,   164,   251,   165,    -1,   148,
     164,   251,   165,    -1,   243,   149,   164,   251,   165,    -1,
     248,    -1,     5,    -1,   148,   250,    -1,   243,   149,   250,
      -1,   243,     8,   243,    -1,   243,     8,   243,     8,   243,
      -1,    53,   164,   243,   165,    -1,    53,     5,    -1,    56,
       5,    -1,    59,     5,    -1,    61,     5,    -1,    71,    53,
     164,   251,   165,    -1,    71,    56,   164,   251,   165,    -1,
      71,    59,   164,   251,   165,    -1,    71,    61,   164,   251,
     165,    -1,   210,    -1,   219,    -1,     4,   159,   160,    -1,
       4,   157,   158,    -1,    35,   159,     4,   160,    -1,     4,
     159,   164,   251,   165,   160,    -1,     4,   157,   164,   251,
     165,   158,    -1,   243,    -1,   250,    -1,   251,   163,   243,
      -1,   251,   163,   250,    -1,   164,   243,   163,   243,   163,
     243,   163,   243,   165,    -1,   164,   243,   163,   243,   163,
     243,   165,    -1,     4,    -1,     4,   161,   109,   161,     4,
      -1,   164,   254,   165,    -1,     4,   159,   243,   160,   161,
     110,    -1,   252,    -1,   254,   163,   252,    -1,   256,    -1,
       4,    -1,     4,   161,     4,    -1,     4,   159,   243,   160,
     161,     4,    -1,     5,    -1,    46,    -1,   125,   157,   255,
     158,    -1,   126,   157,   255,   163,   255,   158,    -1,    39,
     157,   255,   163,   255,   158,    -1,    40,   157,   255,   158,
      -1,    41,   157,   255,   158,    -1,    38,   157,   255,   158,
      -1,    38,   157,   255,   163,   251,   158,    -1,   255,    -1,
     257,   163,   255,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   168,   173,   175,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   197,   201,   208,   213,   218,   232,   245,   258,   286,
     300,   311,   326,   331,   332,   333,   334,   335,   339,   341,
     346,   348,   354,   458,   353,   476,   483,   494,   493,   511,
     518,   529,   528,   545,   562,   585,   584,   598,   599,   600,
     601,   602,   606,   607,   613,   615,   617,   679,   709,   744,
     778,   826,   873,   888,   904,   913,   919,   928,   946,   964,
     973,   985,   990,   998,  1018,  1041,  1052,  1060,  1082,  1105,
    1131,  1152,  1164,  1178,  1178,  1180,  1182,  1193,  1205,  1204,
    1216,  1228,  1227,  1241,  1243,  1251,  1257,  1264,  1265,  1269,
    1280,  1295,  1305,  1306,  1311,  1319,  1328,  1346,  1350,  1361,
    1364,  1377,  1380,  1390,  1414,  1413,  1433,  1455,  1473,  1494,
    1512,  1542,  1572,  1590,  1608,  1634,  1652,  1671,  1670,  1693,
    1711,  1750,  1756,  1762,  1769,  1794,  1819,  1836,  1853,  1885,
    1884,  1908,  1926,  1943,  1960,  1959,  1985,  1990,  1995,  2000,
    2005,  2010,  2033,  2039,  2050,  2051,  2056,  2059,  2063,  2086,
    2109,  2132,  2160,  2181,  2204,  2225,  2247,  2267,  2379,  2398,
    2436,  2545,  2554,  2560,  2575,  2603,  2620,  2634,  2640,  2646,
    2655,  2669,  2714,  2731,  2746,  2765,  2777,  2801,  2805,  2810,
    2817,  2823,  2828,  2834,  2838,  2842,  2847,  2859,  2876,  2893,
    2914,  2935,  2970,  2978,  2984,  2991,  2995,  3004,  3012,  3020,
    3029,  3028,  3042,  3041,  3055,  3054,  3068,  3067,  3080,  3087,
    3094,  3101,  3108,  3115,  3122,  3129,  3136,  3144,  3143,  3156,
    3155,  3168,  3167,  3180,  3179,  3192,  3191,  3204,  3203,  3216,
    3215,  3228,  3227,  3240,  3239,  3255,  3258,  3264,  3273,  3293,
    3316,  3320,  3324,  3328,  3332,  3336,  3355,  3368,  3371,  3387,
    3390,  3403,  3406,  3412,  3415,  3422,  3478,  3548,  3553,  3620,
    3656,  3664,  3707,  3746,  3766,  3793,  3833,  3856,  3879,  3883,
    3887,  3926,  3971,  3975,  3985,  4020,  4021,  4022,  4026,  4032,
    4044,  4062,  4090,  4091,  4092,  4093,  4094,  4095,  4096,  4097,
    4098,  4105,  4106,  4107,  4108,  4109,  4110,  4111,  4112,  4113,
    4114,  4115,  4116,  4117,  4118,  4119,  4120,  4121,  4122,  4123,
    4124,  4125,  4126,  4127,  4128,  4129,  4130,  4131,  4132,  4133,
    4134,  4135,  4136,  4139,  4140,  4141,  4142,  4143,  4144,  4145,
    4146,  4147,  4148,  4149,  4150,  4151,  4152,  4153,  4154,  4155,
    4156,  4157,  4158,  4159,  4168,  4169,  4170,  4171,  4172,  4173,
    4174,  4178,  4199,  4218,  4236,  4248,  4265,  4286,  4291,  4296,
    4306,  4316,  4321,  4330,  4357,  4361,  4365,  4369,  4373,  4380,
    4384,  4388,  4392,  4399,  4404,  4411,  4416,  4420,  4425,  4429,
    4437,  4448,  4452,  4464,  4472,  4480,  4487,  4497,  4517,  4521,
    4525,  4529,  4533,  4562,  4591,  4620,  4649,  4659,  4669,  4682,
    4694,  4706,  4725,  4746,  4751,  4755,  4759,  4771,  4775,  4787,
    4794,  4804,  4808,  4823,  4828,  4835,  4839,  4852,  4860,  4871,
    4875,  4883,  4891,  4899,  4907,  4921,  4935,  4939,  4961,  4966
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
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tRecombine", "tSmoother", "tSplit", "tDelete",
  "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers",
  "tHole", "tAlias", "tAliasWithOptions", "tQuadTriDbl", "tQuadTriSngl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
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
  "$@7", "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId", "InSphereCenter", "CircleOptions", "Shape", "$@8", "$@9",
  "$@10", "$@11", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "Visibility", "Command", "Loop", "Extrude", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr",
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
     385,   386,   387,   388,   389,   390,   391,   392,    63,   393,
     394,   395,   396,    60,    62,   397,   398,    43,    45,    42,
      47,    37,    33,   399,   400,   401,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   167,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   171,   171,   172,   172,   172,   172,   172,   172,   173,
     173,   173,   174,   174,   174,   174,   174,   174,   175,   175,
     176,   176,   178,   179,   177,   180,   180,   182,   181,   183,
     183,   185,   184,   186,   186,   188,   187,   189,   189,   189,
     189,   189,   190,   190,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   192,   192,   193,   193,   193,   194,   193,
     193,   195,   193,   196,   196,   197,   197,   198,   198,   199,
     199,   199,   200,   200,   201,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   206,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   207,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   208,
     205,   205,   205,   205,   209,   205,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   212,   212,
     212,   212,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   214,   214,   214,   214,   214,   215,   216,   216,   216,
     216,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   219,   219,   219,
     220,   219,   221,   219,   222,   219,   223,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   224,   219,   225,
     219,   226,   219,   227,   219,   228,   219,   229,   219,   230,
     219,   231,   219,   232,   219,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   240,   240,   240,   241,   241,   241,   242,   242,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   245,   245,   245,   245,   246,
     246,   246,   246,   247,   247,   248,   248,   248,   248,   248,
     248,   249,   249,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   251,   251,   251,   251,   252,   252,   252,
     252,   253,   253,   254,   254,   255,   255,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   257,   257
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     0,     0,    10,     1,     3,     0,    13,     1,
       3,     0,    15,     8,    14,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     6,     7,     7,
       9,     9,     3,     6,     4,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     5,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       5,     0,     9,     0,     3,     3,     5,     0,     2,     3,
       5,     3,     0,     2,     3,     3,     5,     1,     1,     0,
       5,     0,     2,     7,     0,     9,     6,     7,     4,     7,
       8,     8,     7,     7,    11,     8,     8,     0,     9,     8,
       9,     3,     4,    10,     7,     7,     8,     8,    12,     0,
       9,     8,     7,     8,     0,     9,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     3,     3,     4,
       4,     3,     7,     7,     3,     7,     3,     2,     2,     2,
       2,    15,     2,     2,     2,     2,     3,     6,     8,     8,
      10,     1,     2,     1,     3,     4,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     2,     3,     2,     3,     9,     6,     0,     3,     0,
       1,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       7,     5,     4,     6,     6,    12,    10,    10,    10,    10,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     4,     2,     5,     3,     6,     4,
       7,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     5,     5,     5,     5,     1,     1,     3,     3,
       4,     6,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       1,     4,     6,     6,     4,     4,     4,     6,     1,     3
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
       0,     0,     0,   211,     0,   216,     0,     0,     0,   213,
       0,     0,     0,     0,   295,   296,   297,     0,     5,     7,
       6,     8,     9,    10,    19,    11,    12,    13,    18,    17,
      14,    15,    16,     0,    20,   364,   371,   439,    57,   365,
     366,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   440,
       0,     0,     0,     0,   368,   369,   370,    61,    60,    59,
      58,     0,     0,     0,    63,    62,     0,     0,     0,     0,
     166,     0,     0,     0,   302,     0,     0,     0,     0,     0,
     200,     0,   202,   199,   203,   204,    95,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,   124,   137,   149,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   384,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,     0,   292,     0,
       0,     0,     0,     0,     0,     0,   371,   402,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   416,   417,   395,
     401,     0,   396,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,   197,   198,     0,     0,   212,     0,   166,
       0,   166,   371,     0,   298,     0,     0,     0,     0,     0,
       0,   375,    32,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,   304,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,   164,     0,    72,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   141,     0,     0,     0,     0,    93,    93,     0,
       0,   423,   424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   386,   385,     0,     0,
       0,     0,   166,   166,     0,     0,     0,     0,     0,     0,
       0,   226,     0,   166,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   184,     0,     0,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   408,
       0,   409,   410,   411,     0,     0,     0,     0,     0,   304,
     403,     0,   397,     0,     0,     0,   279,   196,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,   214,   187,
       0,   188,     0,     0,   206,     0,     0,     0,     0,   377,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   436,     0,   435,     0,     0,
       0,     0,   448,     0,     0,     0,     0,     0,     0,   303,
      57,     0,     0,     0,    57,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,   167,    66,     0,   320,   319,
     318,   317,   313,   314,   316,   315,   308,   307,   309,   310,
     311,   312,   142,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,   388,   387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,   185,     0,     0,   181,     0,     0,
       0,   291,   290,     0,     0,   419,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303,   398,   405,
       0,   309,   404,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,   189,   190,     0,     0,     0,     0,   373,
     379,     0,    42,     0,     0,     0,    55,     0,    33,    34,
      35,    36,    37,   322,   343,   323,   344,   324,   345,   325,
     346,   326,   347,   327,   348,   328,   349,   329,   350,   330,
     351,   342,   363,   331,   352,     0,     0,   333,   354,   334,
     355,   335,   356,   336,   357,   337,   358,   338,   359,     0,
       0,     0,     0,     0,     0,     0,     0,   446,     0,     0,
     444,   445,     0,   383,     0,    85,     0,   441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,   374,     0,     0,     0,     0,     0,    23,
      21,     0,     0,    24,     0,     0,    64,    96,    65,   104,
       0,   425,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   272,   270,     0,   278,     0,     0,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,   217,     0,     0,
       0,     0,     0,     0,   274,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,   420,   407,
       0,     0,     0,     0,   399,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,   299,
       0,     0,   376,     0,   372,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     437,     0,     0,     0,   449,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,    73,    75,    77,     0,     0,
     433,     0,    83,     0,     0,     0,     0,   321,    22,     0,
       0,     0,     0,     0,     0,     0,   121,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,     0,   261,
       0,   263,     0,   227,   256,     0,     0,     0,   179,     0,
       0,     0,   283,     0,   183,   182,   294,     0,     0,    30,
      31,     0,     0,   412,   413,   414,   415,   406,   400,     0,
       0,     0,   430,     0,     0,     0,   207,     0,     0,     0,
       0,   193,   378,   192,     0,     0,     0,     0,   393,     0,
     332,   353,   339,   360,   340,   361,   341,   362,     0,   447,
     443,   382,   381,   442,     0,    69,     0,    57,     0,     0,
       0,     0,    68,     0,     0,     0,   431,     0,     0,     0,
       0,    25,    26,     0,    27,     0,     0,    97,   100,   123,
       0,     0,     0,     0,     0,   127,     0,     0,   144,   145,
       0,     0,   129,   152,     0,     0,     0,   119,     0,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,     0,     0,   166,   166,     0,   237,     0,   239,
       0,   241,     0,   395,     0,     0,   262,   264,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,   422,   421,   132,   133,     0,     0,     0,     0,    86,
      90,     0,     0,   300,   380,     0,    38,     0,     0,     0,
       0,     0,    40,     0,     0,     0,     0,     0,    80,     0,
       0,    81,     0,   434,   168,   169,   170,   171,     0,     0,
      98,   101,     0,   122,   130,   131,   135,     0,     0,   146,
       0,     0,   277,   139,     0,     0,   268,   151,     0,     0,
       0,     0,   136,     0,   147,   153,     0,     0,     0,     0,
     392,     0,   391,     0,     0,     0,   228,     0,     0,   229,
       0,     0,   230,     0,     0,     0,     0,     0,     0,     0,
     178,     0,     0,   177,     0,     0,     0,   172,     0,     0,
       0,     0,   428,     0,   209,   208,     0,     0,     0,     0,
      43,     0,     0,     0,   394,     0,     0,     0,   438,    71,
      70,    76,    78,     0,    84,     0,    28,     0,   107,   112,
       0,     0,     0,     0,     0,     0,   140,   125,   138,   150,
     155,     0,     0,    91,    92,   166,     0,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,   166,
       0,     0,     0,     0,     0,   163,   162,     0,     0,     0,
       0,    87,    88,     0,     0,    39,     0,     0,     0,    41,
      56,     0,   432,     0,     0,     0,   286,   287,   288,   289,
     143,     0,     0,     0,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   266,     0,     0,     0,
     222,     0,     0,   173,     0,     0,     0,   427,   210,     0,
     301,     0,     0,     0,     0,    82,     0,     0,    99,   108,
       0,   102,   113,     0,     0,     0,   157,     0,   243,     0,
       0,   245,     0,     0,   247,     0,     0,     0,   258,     0,
     218,     0,   166,     0,     0,     0,   134,    89,     0,    47,
       0,    53,     0,     0,     0,     0,   120,   148,   285,   389,
     231,     0,     0,   238,   232,     0,     0,   240,   233,     0,
       0,   242,     0,     0,     0,   224,     0,   176,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   109,   115,     0,
     114,     0,   249,     0,   251,     0,   253,   259,   265,   223,
     219,     0,     0,     0,     0,    44,     0,    51,     0,     0,
       0,   423,     0,     0,   234,     0,     0,   235,     0,     0,
     236,     0,     0,   180,     0,   174,     0,    45,     0,     0,
     201,     0,   110,     0,   116,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,   105,   244,
       0,   246,     0,   248,     0,   175,    46,    48,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    54,   106,   250,
     252,   254,    50,    52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    78,   801,    79,    80,   501,  1175,  1181,
     718,   915,  1334,  1496,   719,  1451,  1528,   720,  1498,   721,
     722,   919,   151,   281,    81,   600,   377,  1288,  1289,   378,
    1480,  1344,  1389,  1345,  1392,   836,  1215,  1102,   575,   404,
     405,   406,   407,   247,   351,   352,    84,    85,    86,    87,
      88,    89,   248,   868,  1411,  1471,   651,  1237,  1240,  1243,
    1431,  1435,  1439,  1485,  1488,  1491,   864,   865,   984,   833,
     625,   660,    91,    92,    93,    94,   249,   154,   417,   208,
    1057,   250,   251,   252,   473,   259,   792,   951,   552,   547,
     553
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1154
static const yytype_int16 yypact[] =
{
    4333,    36,    52,  4421, -1154, -1154,  1898,    57,   -41,  -123,
     -75,    34,    88,   107,   123,   131,    42,    81,   -34,    94,
     105,    18,   125,   169,    21,   216,   222,   170,   317,   344,
     407,   357,   360,   146,   377,   603,   219,    12,   274,   415,
     315,   -74,   -74,   333,   -33,    44,   212,   460,   490,    17,
      43,   491,   520,   199,   564,   571,  2060,   578,   429,   433,
     434,    23,     7, -1154,   447, -1154,   468,   599,   455, -1154,
     615,   633,    30,    31, -1154, -1154, -1154,  4007, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154, -1154, -1154,     1, -1154, -1154,    25,   486,   471, -1154,
   -1154, -1154,   335,   356,   367,   370,   371,   473,   504,   509,
     537,   543,   544,   548,   562,   566,   576,   579,   582,   594,
     608,   612,   616,   489,   497,   498,   515,   527,   547, -1154,
     721,   556,   585,   595, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154,  4007,  4007,  4007, -1154, -1154,  3625,  3393,    24,   669,
     521,  2528,   749,  1334, -1154,   750,   758,  4007,   786,   795,
   -1154,  4007, -1154, -1154, -1154, -1154, -1154, -1154,  4007,  3816,
    4007,  4007,   619,  4007,  3816,  4007,  4007,   642,  3816,  4007,
    4007,  2528,   648,   678, -1154,   686,   689,  2060,  2060,  2060,
     702, -1154, -1154, -1154, -1154,   703,   711,   715,  2528,  4007,
     829,  2528,   -74,   -74,   -74,  4007,  4007,   -71, -1154,   -45,
     -74,   699,   717,   722,  3781,   -22,   -11,   733,   737,   740,
    2060,  2060,  2528,   744,     4,   719, -1154,   903, -1154,   757,
     782,   787,  2060,  2060,   796,   804,   113, -1154,   807,    32,
     908,   945,   953,   671,  2684,  4007,  1735, -1154, -1154,  4077,
   -1154,   974, -1154,   977,  4007,  4007,  4007,   827,  4007,   840,
     902,  4007,  4007, -1154, -1154,  4007,  1011, -1154,  1021, -1154,
    1026, -1154,   226,  1518, -1154,  2528,  2528,   880,  4007,  1036,
     881, -1154, -1154, -1154,  1038,  4007,  4007,  4007,  4007,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  4007,   331,   331,   331,
     331,   331,   331,  4007,   331,   331,   331,   892,   892,   892,
    3816,  6742,   102,  3816,  5983,   111,   893,  1056,   913,   927,
   -1154,   922,  4500,  1089, -1154, -1154,  4007,  4007,  4007,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,  4007,
    4007, -1154, -1154,  1692,   -63,   171,  5281,   177,   190,  6763,
    3816,  4096, -1154,   388,  6784,  6805,  4007,  6826,   482,  6847,
    6868,  4007,   522,  6889,  6910,  1092,  4007,  4007,  4007,  4007,
    1096,  1099,  1099,  4007,   950,   951,   954,   956,  4007,  4007,
    4007,  1105,  5201,   957,  1108,   -31, -1154, -1154,  5307,  5333,
     -74,   -74,   521,   521,   -20,  4007,  4007,  4007,  3781,  3781,
    4007,  4500,   227, -1154,  4007,  4007,  4007,  4007,  4007,  1114,
    1119,  1120,  4007,  1123, -1154,  4007,  4007,   794, -1154,  3816,
    3816,  3816,  1124,  1125,  4007,  4007,   -79,  3555,  1128, -1154,
    4007, -1154, -1154, -1154,   971,   973,   975,   978,  3816,   892,
   -1154,  6931, -1154,   614,  4007,  2840, -1154, -1154,  6952,  6973,
    6994,  1032,  5359, -1154,   979,  4116,  7015,  6006, -1154, -1154,
     914, -1154,  1223,  4007, -1154,   986,   618,  4007,  6029,   310,
    4007,     5, -1154,  7036,  6052,  7057,  6075,  7078,  6098,  7099,
    6121,  7120,  6144,  7141,  6167,  7162,  6190,  7183,  6213,  7204,
    6236,  7225,  6259,  7246,  6282,  5385,  5411,  7267,  6305,  7288,
    6328,  7309,  6351,  7330,  6374,  7351,  6397,  7372,  6420,  5437,
    5463,  5489,  5515,  5541,  5567,   625,   186, -1154,   983,   987,
     991,   988, -1154,   228,  1820,   990,   997,   993,   622,   102,
   -1154,  2528,   659,    74,   471,  4007,  1152,  1155,    28,  1000,
   -1154,   -10,    26,    29,    49, -1154, -1154,  4135,  1729,  2032,
    1293,  1293,   598,   598,   598,   598,   261,   261,   892,   892,
     892,   892, -1154,     8,  3816,  1156,  3816,  4007,  1158, -1154,
    1157,  1161,   331,  1163,  3816,  3816,  1059,  1165,  1166,  7393,
    1167,  1065,  1172,  1173,  7414,  1069,  1175,  1177,  4007,  7435,
    4529,  7456,  7477,  4007,  2528,  1164,  1180,  7498,  3966,  3966,
    3966,  3966,  7519,  7540,  7561,  2528,  3816,  1028, -1154,   -74,
    4007,  4007, -1154, -1154,  1023,  1025,  3781,  5593,  5619,  5645,
    5255,   256,   -74,  1933,  7582,  4557,  7603,  7624,  7645,  4007,
    1185, -1154,  4007,  7666, -1154,  6443,  6466, -1154,   662,   666,
     667, -1154, -1154,  6489,  6512, -1154,  3816, -1154,  3816,  6535,
    1033,  4585,  3816,  3816,  3816,  3816,   672, -1154, -1154,  4154,
    3816,   892, -1154,  1187,  1189,  1191,  1039,  4007,  2096,  4007,
    4007, -1154,    39, -1154, -1154,  1037,  2528,  1199,  6558,   516,
   -1154,  4613, -1154,  1050,  1051,  1045, -1154,  1205, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154,  4007,  4007, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,  4007,
    4007,  4007,  4007,  4007,  4007,  4007,  1210, -1154,  3816,   331,
   -1154, -1154,   331, -1154,   331, -1154,  4007, -1154,   331,  1057,
    4007,  1213,  1061,    41,  4007,  1216,  1217,  2479, -1154,  1221,
    1071,    23,  1225, -1154,  3816,  3816,  3816,  3816,  4007, -1154,
    1093,   331,   230, -1154,   279,  5671, -1154,  1226, -1154, -1154,
     -74,  4096, -1154,  1179,  2528,  2528,  1232,  2528,   729,  2528,
    2528,  1233,  1181,  2528,  2528,  2500,  1234,  1237,  1239,  1241,
    4215, -1154, -1154,  1244, -1154,  1245,  1095,  7897, -1154,  1097,
    1098,  1100,  1247,  1250,  1253,  1256,   675,  1262,   235,  5697,
    5723, -1154, -1154,  4641,  -109,   -74,   -74,   -74,  1263,  1264,
    1087,  1111,    11,    13,   478, -1154,   252, -1154,   256,  1265,
    1267,  1268,  1281,  1282,  7897, -1154,  2647,  1107,  1286,  1290,
    1291,  1242,  4007,  1292,  1296,   676,   704,  -111, -1154, -1154,
     710,   714,   724,   742, -1154,  4007,   743,  2528,  2528,  2528,
    1299,  5749, -1154,  4180,   670,  1301,  1302,  2528,  1143, -1154,
    1306,  1309, -1154,  1308, -1154,  1159,  4007,  4007,  2528,  1151,
   -1154,  7687,  6581,  7708,  6604,  7729,  6627,  7750,  6650,  6673,
   -1154,   283,  1160,  1162, -1154,  7771,  1168,   102,  2793, -1154,
     102,   326,  1169,  1310,  2812, -1154, -1154, -1154,    23,  4007,
   -1154,   747, -1154,   754,   771,   772,   776,  7897, -1154,  1313,
      45,  1316,  4007,  3308,     9,  1182,  1257,  1257,  2528,  1317,
    1186,  1190,  1325,  1326,  2528,  1193,  1327,  1338, -1154,  1350,
    2528,  2528,  2528,  1355,  1356, -1154,  2528,  1354,  1357,  1358,
    1359,  2528,  2528,  2528, -1154,  1360,   444,  4007,  4007,  4007,
    1206,  1208,   -85,   -27,   180,  1204, -1154,  2528,  4007, -1154,
    1363, -1154,  1367, -1154, -1154,  3781,   493,  2216, -1154,  1211,
    1212,  2996, -1154,  3816, -1154, -1154, -1154,  1214,  2959, -1154,
   -1154,  1219,  1220, -1154, -1154, -1154, -1154,  7897, -1154,  1368,
    1375,  1274, -1154,  4007,  4007,  4007, -1154,  1377,   476,  1222,
    1378, -1154,   310, -1154,  4007,  5775,  5801,   779, -1154,  4007,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,  1228, -1154,
   -1154, -1154, -1154, -1154,  2528, -1154,  2528,   471,  4007,  1380,
    1383,    28, -1154,  1384,  6696,    23, -1154,  1385,  1387,  1388,
    1389, -1154, -1154,   331, -1154,  5827,  3966,  7897, -1154, -1154,
    4007,   -74,  1392,  1393,  1395, -1154,  4007,  4007, -1154, -1154,
    1396,  4007, -1154, -1154,  1399,  1400,  1402,  1297,  4007, -1154,
    1404,  2528,  2528,  2528,  2528,  1406,   939,  1408,  4007, -1154,
    3966,  4669,  7792,  4444,   521,   521,   -74,  1409,   -74,  1410,
     -74,  1411,  4007,    76,  1259,  7813, -1154, -1154,  4697,   257,
   -1154,  1413,  1557,  1414,  2528,   -74,  1557,  1418,   791,  4007,
   -1154, -1154, -1154, -1154, -1154,  2528,  4472,   394,  7834, -1154,
   -1154,  3352,  2528, -1154, -1154,   296,  7897,  4007,  4007,  2528,
    1266,   799,  7897,  1401,  1422,  1423,  1425,  3105, -1154,  1426,
    1428, -1154,  1271, -1154, -1154, -1154, -1154, -1154,  1439,  4007,
    7897, -1154,  4725,   353, -1154, -1154, -1154,  4753,  4781, -1154,
    4809,  1442, -1154, -1154,  1391,  1444,  7897, -1154,  1445,  1446,
    1447,  1449, -1154,  1294, -1154, -1154,  5228,  3124,  1450,  1295,
   -1154,  4007, -1154,  1298,  1300,   282, -1154,  1303,   322, -1154,
    1304,   330, -1154,  1305,  6719,  1451,  2528,  1453,  1322,  4007,
   -1154,  3152,   340, -1154,   814,   342,   359, -1154,  1455,  4837,
    1381,  4007, -1154,  4007, -1154, -1154,  3816,  3913,  1458,  1324,
   -1154,  4007,  5853,  5879, -1154,  2528,  4007,  1460, -1154, -1154,
   -1154, -1154, -1154,    23, -1154,  1382, -1154,  5905, -1154, -1154,
    1464,  1481,  1487,  1488,  1489,  1336, -1154, -1154, -1154, -1154,
   -1154,  2528,  3816, -1154, -1154,   521,  4501, -1154, -1154,  3781,
     256,  3781,   256,  3781,   256,  1492, -1154,   824,  2528, -1154,
    4865,   -74,  1495,  3816,   -74, -1154, -1154,  4007,  4893,  4921,
     835, -1154, -1154,  1497,  1340,  7897,  4007,  4007,   836,  7897,
   -1154,  1499, -1154,  4007,   844,   860, -1154, -1154, -1154, -1154,
   -1154,  4007,   861,   865,  1342,  4007, -1154,  4949,   401,   557,
    4977,   418,   706,  5005,   424,   800, -1154,  2528,  1505,  1438,
    2252,  1349,   430, -1154,   868,   470,  3933, -1154, -1154,  1509,
   -1154,  4007,  7855,  5931,    35, -1154,  5957,  1512, -1154, -1154,
    1513, -1154, -1154,  5033,  1516,  1517, -1154,  5061,  1520,  4007,
    1521,  1522,  4007,  1523,  1524,  4007,  1525,  1353, -1154,  4007,
   -1154,   256, -1154,  3816,  1526,  3152, -1154, -1154,   890, -1154,
    4007, -1154,  2528,  4007,  2372,  3590, -1154, -1154, -1154, -1154,
   -1154,  1369,  5089, -1154, -1154,  1370,  5117, -1154, -1154,  1372,
    5145, -1154,  1531,  4036,   837,  2408,   895, -1154,   488,   896,
    1532,  1376,  7876,   901,  5173, -1154,  1735, -1154, -1154,   331,
    7897,   256,  1533,   256,  1535,   256,  1537, -1154, -1154, -1154,
   -1154,   256,  1538,  3816,  1540, -1154,   331, -1154,  1386,  1541,
     904,  1586,   905,   857, -1154,  1390,   920, -1154,  1394,   955,
   -1154,  1398,   982, -1154,   917, -1154,   918, -1154,  1405,  2528,
   -1154,  4007, -1154,   471, -1154,  1542,   256,  1545,   256,  1546,
     256, -1154,  1547,   331,  1549,   331,   923,  4058, -1154, -1154,
    1001, -1154,  1027, -1154,  1121, -1154, -1154, -1154,   937, -1154,
    1550,   471,  1551,  1553,  1558,   331,  1564, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1154, -1154, -1154, -1154,   635, -1154, -1154, -1154, -1154,   215,
   -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154, -1154,  -329,    -3, -1154,  1227, -1154, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154,  -469, -1154,   630,  1595, -1154,
   -1154, -1154, -1154,    -1,  -417,  -202, -1154, -1154, -1154, -1154,
   -1154, -1154,  1598, -1154, -1154, -1154, -1154, -1154, -1154, -1154,
   -1154, -1154, -1154, -1154, -1154, -1154,  -796,  -752, -1154, -1154,
    1201, -1154, -1154, -1154, -1154, -1154,    -2, -1154,    47, -1154,
   -1153,   528,  -134,   240,   542,  -760,   525, -1154,  -270,    -6,
     148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -5
static const yytype_int16 yytable[] =
{
     155,  1254,    83,   152,   153,   644,   645,   274,   443,   712,
     444,   260,   431,   561,   799,  1099,   565,  1009,   157,  1011,
     211,   224,   172,   212,   447,   177,   213,   257,   345,   277,
     172,   950,   790,   177,   158,   268,   270,   459,   420,   421,
     160,  1421,     4,   144,   145,   941,   905,   227,   216,   228,
     911,  1092,     5,   400,   401,   402,  1001,   546,   548,   549,
     550,   551,   420,   421,   555,   556,   557,   490,   198,   492,
     156,   199,  1016,   203,   204,   273,   420,   421,  1136,   675,
    1137,   560,   159,   205,   474,   676,   439,   440,   207,   209,
     206,   215,   284,   422,   162,   593,   229,   217,   452,   453,
     594,   218,   420,   421,   713,   714,   715,   716,  1010,   560,
    1012,   219,  1014,   163,   203,   204,   420,   421,   564,   423,
     420,   421,  1338,   168,   205,   420,   421,   420,   421,   164,
     169,   214,   639,   346,   347,   225,  1138,   165,  1139,   337,
     338,   339,   433,   646,   341,   344,   434,   168,  1352,   350,
     942,   943,   800,   435,   794,   373,   420,   421,   275,   376,
     839,   840,   841,   445,   261,   276,   379,   381,   384,   385,
     717,   387,   381,   389,   390,   173,   381,   393,   394,   144,
     145,   226,   174,   173,   278,   178,   279,   258,  1083,   800,
     795,   280,   791,   796,   269,   271,   460,   412,   161,  1422,
     906,   166,   187,   418,   419,   188,   180,   189,   137,   138,
     139,   140,   419,   797,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   475,   368,   369,   144,   145,
     780,   653,   370,   181,   784,   783,   137,   138,   139,   140,
     167,  1245,   469,   471,   381,   137,   138,   139,   140,   415,
     416,   170,   478,   479,   480,   232,   482,   424,   233,   485,
     486,   432,   171,   487,  1014,   144,   145,   144,   145,  1453,
     456,   220,   457,   221,   279,   195,   498,   150,   196,   280,
     197,   698,   175,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,  1193,   176,   420,   421,   595,
     858,   554,   809,  1077,   596,   545,   283,   598,   381,   859,
     599,   381,   566,  1140,   767,  1141,  1516,   860,   861,   768,
     601,   862,   863,   599,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   123,
     124,   125,   126,   179,   420,   421,   182,   129,   469,   180,
     144,   145,   420,   421,   609,   493,   773,   279,   960,   614,
     652,   774,   280,   605,   619,   620,   621,   622,   997,   420,
     421,   627,  1263,   183,   420,   421,   632,   633,   634,   382,
     367,   368,   369,   184,   382,  1015,   185,   370,   382,   186,
    1249,   350,   350,   647,   648,   649,   337,   338,   650,   420,
     421,   200,   654,   655,   656,   657,   658,   961,   190,   913,
     663,  1069,   605,   665,   666,  1309,   605,   381,   381,   381,
    1129,  1130,   673,   674,  1270,   679,   132,   133,   681,  1271,
     137,   138,   139,   140,   144,   145,   381,   642,   643,   420,
     421,   201,   689,   691,   263,   416,   283,   420,   421,   202,
     144,   145,  1170,  1171,   470,  1311,   382,   420,   421,   420,
     421,   679,   285,  1313,   286,   708,   710,   210,   711,   932,
     420,   421,   933,  1321,   934,  1323,   420,   421,   936,   123,
     124,   125,   126,   287,  1359,   288,  1362,   129,  1365,   222,
     545,   283,  1324,  1341,   289,   349,   290,   291,   293,   292,
     294,   959,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   223,   230,   420,   421,
     370,   605,   858,   606,   123,   124,   125,   126,   786,  1264,
     785,   859,   129,   787,  1399,   420,   421,   858,   234,   860,
     861,   420,   421,   862,   863,   235,   859,   420,   421,   231,
     382,  1402,   253,   382,   860,   861,   254,  1405,   862,   863,
     255,   256,   381,  1413,   381,   805,   132,   133,    40,    41,
      42,    43,   691,   811,   262,   264,    48,  1014,  1074,    51,
    1014,  1076,  1078,  1014,   265,  1444,   825,   420,   421,   266,
     470,   830,   838,   838,   838,   838,   837,   837,   837,   837,
     295,   858,   296,  1415,   381,   420,   421,   267,   849,   850,
     859,   132,   133,  1013,   853,   605,   327,   611,   860,   861,
     282,  1473,   862,   863,   328,   329,   191,   874,  1150,   192,
     876,   297,   193,   298,   194,  1483,   299,  1486,   300,  1489,
     144,   145,   330,   348,   381,  1492,   381,   911,  1045,   353,
     381,   381,   381,   381,   331,   605,   848,   615,   381,   382,
     382,   382,  1014,   854,   301,   901,   302,   903,   904,   866,
     303,   305,   304,   306,   332,   307,   912,   308,   382,   395,
    1520,   383,  1522,   334,  1524,   692,   388,  1233,  1234,   309,
     392,   310,  1400,   311,   464,   312,   411,   465,   333,   414,
     466,  1014,   467,   313,  1014,   314,   315,  1014,   316,   317,
    1014,   318,   335,   921,   922,   365,   366,   367,   368,   369,
     441,   319,   336,   320,   370,   354,   371,   923,   924,   925,
     926,   927,   928,   929,   372,   321,   381,   322,  1014,   323,
    1014,   324,  1014,   325,   935,   326,   386,   605,   938,   688,
     858,   706,   944,   707,   765,   605,   766,   779,   970,   859,
     971,   374,   381,   381,   381,   381,   957,   860,   861,   391,
     375,   862,   863,   495,   496,   396,     7,     8,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   605,  1198,   782,   605,   370,   880,  1046,   605,
     605,   881,   882,   413,   382,   605,   382,   894,   605,   605,
     995,  1031,   397,   398,   692,   812,   399,   571,    19,    20,
     572,    22,    23,   573,    25,   574,    27,   964,    28,   403,
     408,    31,    32,   425,    34,    35,    36,   605,   409,  1032,
      39,  1403,   410,   605,   858,  1033,   382,   605,   446,  1034,
    1028,   426,   558,   859,   912,   562,   427,   605,  1354,  1035,
     436,   860,   861,  1037,   437,   862,   863,   438,    58,    59,
      60,   442,  1002,  1003,  1004,   605,   605,  1036,  1038,   448,
    1085,   858,  1086,   461,  1055,  1056,   382,   605,   382,  1087,
     859,   449,   382,   382,   382,   382,     7,     8,   860,   861,
     382,   858,   862,   863,   605,   605,  1088,  1089,  1079,   605,
     859,  1090,  1179,  1223,  1180,  1224,   450,  1084,   860,   861,
     462,   451,   862,   863,   605,   454,  1258,  1098,   463,   667,
    1095,  1097,  1276,   455,  1277,  1406,   458,   571,    19,    20,
     572,    22,    23,   573,    25,   574,    27,  1179,    28,  1322,
     476,    31,    32,   477,    34,    35,    36,  1367,   481,  1368,
      39,   668,   669,   670,   858,  1131,  1132,  1133,   605,  1179,
    1379,  1384,  1469,   859,   483,  1143,  1145,  1387,   382,  1388,
     686,   860,   861,  1148,   484,   862,   863,   488,    58,    59,
      60,   381,  1505,  1390,  1179,  1391,  1394,   489,   605,   858,
    1395,   605,   491,  1414,   382,   382,   382,   382,   859,   497,
     499,  1166,  1167,  1168,   502,   500,   860,   861,   370,  1174,
     862,   863,  1176,  1276,   567,  1450,   858,  1182,   605,   605,
    1472,  1474,  1149,   568,  1179,   859,  1478,  1501,   774,  1502,
    1504,  1186,   569,   860,   861,   858,  1187,   862,   863,   703,
     605,  1513,  1512,  1514,   859,  1507,  1179,   570,  1530,   781,
    1201,   150,   860,   861,  1200,   576,   862,   863,  1202,   618,
    1535,   858,  1536,   623,  1207,  1208,   624,   628,   629,  1210,
     859,   630,   635,   631,   638,   637,  1216,  1370,   860,   861,
    1509,   659,   862,   863,  1228,   661,  1226,   662,  1227,   664,
     671,   672,   680,   350,   350,   682,   802,   683,   804,   684,
    1244,   696,   685,   699,   705,   770,   769,  1511,  1203,   771,
     381,   772,   831,   776,   381,   777,   778,  1259,   788,   789,
     793,   807,   803,   845,   806,  1268,  1532,   808,   832,  1267,
     810,   813,   814,   815,   817,  1272,  1273,   818,   846,   819,
     820,   822,   823,  1235,   824,  1238,   834,  1241,   851,   847,
     852,   875,  1533,   888,   897,   858,   898,  1287,   899,  1252,
     900,   907,  1255,  1256,   859,   909,  1497,   916,   917,   918,
    1445,   920,   860,   861,   930,   937,   862,   863,   885,   939,
     886,   940,   945,   946,   890,   891,   892,   893,   948,  1306,
     949,   952,   896,   963,   908,     7,     8,   958,   965,   968,
     974,   979,   975,  1526,   980,  1529,   981,  1320,   982,   469,
     985,  1007,   986,   987,   991,   988,   989,   992,   990,  1328,
     993,  1329,   994,   382,   381,  1542,   996,  1005,  1008,  1335,
    1006,  1023,  1017,  1018,  1339,  1019,   571,    19,    20,   572,
      22,    23,   573,    25,   574,    27,  1534,    28,  1020,  1021,
      31,    32,  1024,    34,    35,    36,  1025,  1026,  1029,    39,
     381,  1027,  1030,  1042,   350,  1047,  1048,  1357,  1050,  1360,
     931,  1363,  1051,  1052,  1053,  1059,  1054,  1081,  1070,  1091,
    1071,   381,  1094,  1105,  1101,  1376,  1073,    58,    59,    60,
    1080,  1108,  1109,  1112,  1382,  1383,   953,   954,   955,   956,
     355,  1386,   966,   967,  1113,   969,  1100,   972,   973,  1393,
    1106,   976,   977,  1397,  1107,  1114,  1358,  1111,  1361,  1118,
    1364,  1121,  1119,  1142,  1122,  1123,  1124,  1128,  1372,  1146,
    1134,  1375,  1135,  1147,  1163,  1154,  1155,  1161,  1159,  1182,
    1162,  1164,  1165,  1169,  1173,  1172,  1188,  1189,   704,  1183,
    1191,  1194,   382,  1195,  1196,  1197,   382,  1432,  1204,  1205,
    1436,  1206,  1209,  1440,  1211,  1278,  1212,  1443,  1213,  1214,
    1217,   381,  1222,   381,  1225,  1236,  1239,  1242,  1452,  1250,
    1253,  1454,  1246,  1460,  1257,  1039,  1040,  1041,  1279,  1280,
    1275,  1281,  1285,  1283,  1284,  1049,   361,   362,   363,   364,
     365,   366,   367,   368,   369,  1286,  1058,  1294,  1295,   370,
    1296,  1297,  1298,  1299,  1481,  1300,  1304,  1316,  1301,  1305,
    1318,  1325,  1448,  1307,  1332,  1308,  1340,  1310,  1312,  1314,
    1346,   381,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,  1319,  1347,  1327,  1333,
     370,   470,  1342,  1348,  1349,  1350,  1104,  1518,  1366,  1517,
    1351,  1373,  1110,  1380,  1381,  1385,   382,  1396,  1115,  1116,
    1117,  1408,  1409,  1412,  1120,  1417,  1424,  1425,  1442,  1125,
    1126,  1127,  1427,  1428,   494,  1538,  1430,  1433,  1434,  1437,
    1438,  1441,  1447,  1461,  1463,  1144,  1465,  1467,  1475,  1484,
    1476,  1487,   382,  1490,  1493,  1153,  1495,  1500,  1519,  1157,
    1499,  1521,  1523,  1525,  1506,  1527,  1537,  1539,  1508,  1540,
      95,   236,  1510,   382,  1541,  1158,    99,   100,   101,  1515,
    1543,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   238,  1503,   474,  1093,  1418,  1103,    82,   127,
     128,    90,  1184,   626,  1185,   602,  1190,  1482,     0,     0,
     239,     0,     0,   240,     0,     0,   241,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,     0,
       0,     0,    48,     0,     0,    51,     0,     0,     0,  1218,
    1219,  1220,  1221,   382,     0,   382,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,     0,     0,     0,     0,
       0,   131,  1058,     0,     0,     0,     0,     0,   134,   135,
     136,     0,     0,  1260,     0,     0,   382,     0,   592,     0,
    1269,     0,     0,     0,   428,  1251,     0,  1274,     0,   143,
       0,     0,     0,   382,   430,     0,     0,     0,     0,   149,
       0,   206,   472,     0,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   604,   368,   369,    95,   236,
       0,     0,   370,     0,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     238,     0,     0,     0,  1317,     0,     0,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,   240,     0,     0,   241,     0,   242,     0,     0,     0,
       0,     0,     0,  1058,     0,     0,   243,     0,  1330,     0,
       0,     0,    40,    41,    42,    43,    44,     0,     0,     0,
      48,     0,     0,    51,     0,     0,   775,     0,     0,  1058,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,  1353,     0,  1369,     0,   370,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,  1374,   134,   135,   136,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,   141,   380,     0,   370,     0,   143,     0,     0,
       0,     0,   245,     0,     0,  1407,     0,   149,     0,     0,
     472,    95,    96,    97,     0,    98,     0,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,     7,     8,     0,     0,     0,
    1058,     0,  1457,     0,     0,  1446,     0,  1449,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   571,    19,    20,   572,
      22,    23,   573,    25,   574,    27,     0,    28,     0,     0,
      31,    32,     0,    34,    35,    36,     0,     0,     0,    39,
       0,     0,     0,     0,     0,  1494,   130,     0,     0,     0,
       0,     0,   131,   132,   133,     0,     0,  1058,     0,   134,
     135,   136,   137,   138,   139,   140,     0,    58,    59,    60,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
     143,     0,   144,   145,     0,   146,     0,   147,     0,   148,
     149,     0,   150,    95,   236,   237,     0,     0,     0,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   238,     0,     0,   867,     0,
       0,     0,   127,   128,     0,     0,     0,     0,     7,     8,
       0,     0,     0,   239,     0,     0,   240,     0,     0,   241,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,     0,     0,     0,    48,     0,     0,    51,   571,
      19,    20,   572,    22,    23,   573,    25,   574,    27,     0,
      28,     0,     0,    31,    32,     0,    34,    35,    36,     0,
       0,     0,    39,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   131,     0,     0,     0,   370,     0,
       0,   134,   135,   136,     0,     0,     0,     0,     0,     0,
      58,    59,    60,     0,     0,     0,     0,   141,   244,     0,
       0,     0,   143,     0,     0,     0,     0,   245,     0,    95,
     236,  1151,   149,     0,   246,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   238,     0,     0,     0,     0,     0,     0,   127,   128,
       0,   902,     0,     0,     7,     8,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,   571,    19,    20,   572,    22,
      23,   573,    25,   574,    27,     0,    28,     0,     0,    31,
      32,     0,    34,    35,    36,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,   134,   135,   136,
       0,     0,     0,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,   141,   244,     0,     0,     0,   143,     0,
       0,     0,     0,   245,     0,    95,   236,  1455,   149,     0,
    1152,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   238,     0,     0,
       0,     0,     0,     0,   127,   128,     0,  1410,     0,     0,
       7,     8,     0,     0,     0,   239,     0,     0,   240,     0,
       0,   241,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,     0,    48,     0,     0,
      51,   571,    19,    20,   572,    22,    23,   573,    25,   574,
      27,     0,    28,     0,     0,    31,    32,     0,    34,    35,
      36,     0,     0,     0,    39,   947,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   978,     0,     0,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,   141,
     244,     0,     0,     0,   143,     0,     0,     0,     0,   245,
       0,    95,   236,     0,   149,     0,  1456,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   238,     0,     0,     0,     0,     0,     0,
     127,   128,     0,  1470,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,   240,     0,     0,   241,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,    40,    41,    42,    43,    44,
       0,     0,     0,    48,     0,     0,    51,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   131,  1022,     0,     0,   370,     0,     0,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   244,     0,     0,     0,
     143,     0,     0,     0,     0,   245,     0,    95,   236,     0,
     149,     0,   246,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   238,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
     240,     0,     0,   241,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,    40,    41,    42,    43,    44,     0,     0,     0,    48,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,  1075,
       0,     0,     0,   370,     0,     0,     0,     0,   131,     0,
       0,     0,     0,     0,     0,   134,   135,   136,  1082,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   380,     0,     0,     0,   143,     0,     0,     0,
       0,   245,     0,    95,   236,     0,   149,     0,   468,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   238,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,   240,     0,     0,   241,
       0,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,     0,     0,     0,    48,     0,     0,    51,     0,
       0,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   131,  1160,     0,     0,   370,     0,
       0,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   380,     0,
       0,     0,   143,     0,     0,     0,     0,   245,     0,    95,
     236,     0,   149,     0,   690,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   238,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,  1282,     0,     0,     0,   370,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,   134,   135,   136,
    1303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   244,     0,     0,     0,   143,     0,
       0,     0,     0,   245,     0,    95,   236,     0,   149,     0,
    1156,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   238,     0,     0,
       0,     0,     0,     0,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,   240,     0,
       0,   241,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,     0,    48,     0,     0,
      51,     0,     0,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   131,     0,     0,     0,
     370,     0,     0,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
    1251,     0,     0,     0,   143,     0,     0,     0,     0,   430,
       0,    95,   272,   283,   149,     0,   206,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,   126,
     127,   128,     0,     0,   129,    95,   272,   283,     0,     0,
       0,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     123,   124,   125,   126,   127,   128,    95,   272,   129,     0,
       0,     0,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,   131,   132,   133,   127,   128,     0,     0,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,     0,     0,     0,
     143,     0,     0,     0,     0,   245,     0,     0,     0,     0,
     149,     0,  1096,     0,     0,     0,   131,   132,   133,     0,
       0,     0,     0,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   245,
       0,     0,     0,     0,   149,     0,  1266,   131,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,     0,     0,     0,   143,     0,     0,     0,     0,
     245,     0,     0,   342,     0,   149,     0,   343,    95,   272,
       0,     0,     0,     0,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,    95,   272,  1458,     0,   127,   128,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,    95,   272,
       0,     0,   127,   128,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,     0,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,     0,     0,     0,   143,     0,     0,
       0,     0,   245,     0,   131,   677,     0,   149,     0,   678,
       0,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,     0,
       0,     0,   143,     0,     0,     0,     0,   245,     0,   131,
       0,     0,   149,     0,  1459,     0,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,     0,     0,     0,   143,     0,     0,
       0,     0,   245,     0,    95,   272,     0,   149,     0,   340,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,    95,
     236,     0,     0,   127,   128,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   238,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,   240,     0,     0,   241,     0,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,     0,    40,    41,    42,    43,    44,     0,     0,
       0,    48,     0,     0,    51,   131,     0,     0,     0,     0,
       0,     0,   134,   135,   136,     0,     0,     0,     0,  1331,
       0,     0,     0,     0,     0,     0,     0,     0,   428,   429,
       0,     0,     0,   143,     0,     0,     0,     0,   430,  1416,
     131,     0,     0,   149,     0,   206,     0,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   380,     0,     0,     0,   143,    95,
     272,   283,     0,   245,     0,    99,   100,   101,   149,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,   125,   126,   127,   128,
      95,   272,   129,     0,     0,     0,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,  1468,     0,     0,     0,     0,     0,     0,   127,
     128,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,  1531,     0,     0,     0,   370,
       0,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   474,     0,     0,     0,   370,
     131,   132,   133,     0,     0,     0,     0,   134,   135,   136,
       0,     0,     0,     0,   474,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,     0,     0,     0,   143,     0,
       0,     0,     0,   245,   700,     0,     0,     0,   149,     0,
       0,   131,     0,     0,     0,     0,     0,     0,   134,   135,
     136,     0,     0,   798,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,     0,     0,     0,   143,
       0,     0,   895,     0,   245,     0,     0,     0,     0,   149,
       0,     0,     0,     0,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,  1044,     0,
       0,     0,   370,     0,     0,     0,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   475,   368,   369,     0,
       0,     0,     0,   370,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   604,   368,   369,     0,     0,
       0,     0,   370,     0,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,   983,
       0,   370,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,     0,     0,     0,     0,     0,     0,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,    -4,     1,     0,   370,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,    -4,
      -4,   370,     0,     0,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     6,    -4,    -4,     0,     0,
       0,    -4,     0,     7,     8,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     9,    10,     0,
      -4,    -4,    -4,    -4,     0,    11,    12,     0,    13,    14,
      15,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     7,     8,    54,    55,     0,     0,     0,    56,
       0,     0,     0,     0,    57,    58,    59,    60,     0,     0,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,    74,    75,
      76,    77,     0,   571,    19,    20,   572,    22,    23,   573,
      25,   574,    27,     0,    28,     0,     0,    31,    32,     0,
      34,    35,    36,     0,     0,     0,    39,     0,     0,     0,
       0,     0,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,     0,     0,    58,    59,    60,  1231,     0,  1232,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
       0,     0,     0,     0,     0,  1261,     0,  1262,     0,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,  1355,     0,  1356,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,   827,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,   870,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
     889,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,   914,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,     0,  1000,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1229,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,  1248,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
    1290,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,  1291,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,     0,  1292,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1293,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,  1326,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
    1371,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,  1377,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,     0,  1378,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1398,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,  1401,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
    1404,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,  1426,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,     0,  1429,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1462,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,  1464,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,     0,     0,
    1466,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,  1479,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,   636,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,     0,     0,     0,     0,
       0,     0,  1302,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   687,     0,     0,     0,     0,   640,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,   597,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
     640,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,   641,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,   697,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,   745,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,   746,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
     759,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,   760,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,   761,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,   762,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,   763,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
     764,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,   855,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,   856,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,   857,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,   962,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
     998,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,   999,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,  1043,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,  1177,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,  1178,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
    1199,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,  1336,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,  1337,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,     0,  1343,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,     0,  1420,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,     0,     0,     0,
    1423,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,   563,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,     0,     0,   702,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,   709,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
       0,     0,   724,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,   726,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,     0,     0,   728,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,   730,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,     0,     0,   732,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,   734,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,     0,     0,
     736,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,   738,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,     0,     0,   740,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,   742,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
       0,     0,   744,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,   748,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,     0,     0,   750,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,   752,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,     0,     0,   754,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,   756,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,     0,     0,
     758,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,   878,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,     0,     0,   879,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,   883,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
       0,     0,   884,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,     0,     0,   887,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,     0,     0,   910,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,     0,
       0,  1061,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,     0,     0,  1063,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,     0,     0,  1065,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,     0,     0,
    1067,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,     0,     0,  1068,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,     0,     0,  1192,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,     0,     0,  1315,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
     559,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,   603,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,   607,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   608,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,   610,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,   612,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,   613,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,   616,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,   617,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,   687,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
     693,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,   694,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,   695,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   701,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,   723,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,   725,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,   727,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,   729,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,   731,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,   733,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
     735,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,   737,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,   739,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   741,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,   743,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,   747,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,   749,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,   751,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,   753,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,   755,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
     757,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,   816,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,   821,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   826,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,   828,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,   829,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,   835,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,   842,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,   843,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,   844,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
     869,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,   871,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,   872,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,   873,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,   877,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370,     0,  1060,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
       0,     0,     0,     0,   370,     0,  1062,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,     0,     0,     0,     0,   370,     0,  1064,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,     0,     0,     0,     0,   370,     0,  1066,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,     0,     0,     0,     0,   370,     0,  1072,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,     0,     0,     0,     0,   370,     0,
    1230,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,     0,     0,     0,   370,
       0,  1247,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,     0,
     370,     0,  1265,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,     0,     0,     0,
       0,   370,     0,  1419,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,     0,     0,
       0,     0,   370,     0,  1477,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,     0,
       0,     0,     0,   370
};

static const yytype_int16 yycheck[] =
{
       6,  1154,     3,     6,     6,   422,   423,     6,     4,     4,
       6,     4,   214,   342,     6,     6,   345,     6,    59,     6,
      53,     4,     4,    56,   226,     4,    59,     4,     4,     4,
       4,   791,     4,     4,   157,     5,     5,     5,   147,   148,
       6,     6,     6,   154,   155,     4,     7,     4,     4,     6,
     161,     6,     0,   187,   188,   189,   165,   327,   328,   329,
     330,   331,   147,   148,   334,   335,   336,   269,    56,   271,
      13,    59,   868,   147,   148,    77,   147,   148,   163,   158,
     165,     7,   157,   157,     8,   164,   220,   221,    41,    42,
     164,    44,    98,   164,     6,   158,    53,    53,   232,   233,
     163,    57,   147,   148,    99,   100,   101,   102,    97,     7,
      97,    67,   864,     6,   147,   148,   147,   148,     7,   164,
     147,   148,  1275,   157,   157,   147,   148,   147,   148,     6,
     164,   164,   163,   109,   110,   118,   163,     6,   165,   141,
     142,   143,   164,   163,   146,   147,   157,   157,  1301,   150,
     109,   110,   144,   164,   164,   157,   147,   148,   157,   161,
     629,   630,   631,   159,   157,   164,   168,   169,   170,   171,
     165,   173,   174,   175,   176,   157,   178,   179,   180,   154,
     155,   164,   164,   157,   159,   164,   161,   164,   948,   144,
     164,   166,   164,   164,   164,   164,   164,   199,   164,   164,
     161,   159,    56,   205,   206,    59,   157,    61,   134,   135,
     136,   137,   214,   164,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   154,   155,
     559,   433,   156,    63,   563,   161,   134,   135,   136,   137,
     159,   165,   244,   245,   246,   134,   135,   136,   137,   202,
     203,   157,   254,   255,   256,    56,   258,   210,    59,   261,
     262,   214,   157,   265,  1016,   154,   155,   154,   155,  1422,
     157,    59,   159,    61,   161,    56,   278,   164,    59,   166,
      61,   483,   157,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,  1085,   157,   147,   148,   158,
      74,   333,   602,     7,   163,     4,     5,   160,   340,    83,
     163,   343,   345,   163,   158,   165,  1499,    91,    92,   163,
     160,    95,    96,   163,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,    38,
      39,    40,    41,   157,   147,   148,    59,    46,   380,   157,
     154,   155,   147,   148,   386,   159,   158,   161,   158,   391,
     163,   163,   166,   163,   396,   397,   398,   399,   163,   147,
     148,   403,     8,    59,   147,   148,   408,   409,   410,   169,
     149,   150,   151,     6,   174,   163,    59,   156,   178,    59,
     163,   422,   423,   425,   426,   427,   428,   429,   430,   147,
     148,   157,   434,   435,   436,   437,   438,   158,    61,   709,
     442,   158,   163,   445,   446,   163,   163,   449,   450,   451,
       6,     7,   454,   455,   158,   457,   125,   126,   460,   163,
     134,   135,   136,   137,   154,   155,   468,   420,   421,   147,
     148,    56,   474,   475,     6,   428,     5,   147,   148,   164,
     154,   155,     6,     7,   244,   163,   246,   147,   148,   147,
     148,   493,   157,   163,   159,   497,   499,   164,   500,   769,
     147,   148,   772,   163,   774,   163,   147,   148,   778,    38,
      39,    40,    41,   157,  1310,   159,  1312,    46,  1314,    59,
       4,     5,   163,  1283,   157,     4,   159,   157,   157,   159,
     159,   801,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    56,    56,   147,   148,
     156,   163,    74,   165,    38,    39,    40,    41,   564,   165,
     563,    83,    46,   565,   163,   147,   148,    74,     4,    91,
      92,   147,   148,    95,    96,     4,    83,   147,   148,    59,
     340,   163,     4,   343,    91,    92,   157,   163,    95,    96,
     157,   157,   594,   163,   596,   597,   125,   126,    77,    78,
      79,    80,   604,   605,   157,     6,    85,  1359,   937,    88,
    1362,   940,   941,  1365,   159,  1411,   618,   147,   148,     4,
     380,   623,   628,   629,   630,   631,   628,   629,   630,   631,
     157,    74,   159,   163,   636,   147,   148,     4,   640,   641,
      83,   125,   126,   165,   646,   163,   157,   165,    91,    92,
     164,   163,    95,    96,   157,   157,    53,   659,   165,    56,
     662,   157,    59,   159,    61,  1461,   157,  1463,   159,  1465,
     154,   155,   157,     4,   676,  1471,   678,   161,     8,   151,
     682,   683,   684,   685,   157,   163,   639,   165,   690,   449,
     450,   451,  1444,   646,   157,   697,   159,   699,   700,   652,
     157,   157,   159,   159,   157,   157,   709,   159,   468,   181,
    1506,   169,  1508,   157,  1510,   475,   174,  1134,  1135,   157,
     178,   159,   165,   157,    53,   159,   198,    56,     7,   201,
      59,  1483,    61,   157,  1486,   159,   157,  1489,   159,   157,
    1492,   159,   157,   745,   746,   147,   148,   149,   150,   151,
     222,   157,   157,   159,   156,     6,     6,   759,   760,   761,
     762,   763,   764,   765,     6,   157,   768,   159,  1520,   157,
    1522,   159,  1524,   157,   776,   159,   157,   163,   780,   165,
      74,   163,   784,   165,   159,   163,   161,   165,    59,    83,
      61,     5,   794,   795,   796,   797,   798,    91,    92,   157,
       5,    95,    96,   275,   276,   157,    12,    13,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   163,  1093,   165,   163,   156,   165,   158,   163,
     163,   165,   165,     4,   594,   163,   596,   165,   163,   163,
     165,   165,   164,   157,   604,   605,   157,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   810,    64,   157,
     157,    67,    68,   164,    70,    71,    72,   163,   157,   165,
      76,   165,   157,   163,    74,   165,   636,   163,   159,   165,
     882,   164,   340,    83,   887,   343,   164,   163,  1305,   165,
     157,    91,    92,   895,   157,    95,    96,   157,   104,   105,
     106,   157,   855,   856,   857,   163,   163,   165,   165,     6,
     163,    74,   165,     5,   916,   917,   676,   163,   678,   165,
      83,   164,   682,   683,   684,   685,    12,    13,    91,    92,
     690,    74,    95,    96,   163,   163,   165,   165,   941,   163,
      83,   165,   163,     4,   165,     6,   164,   949,    91,    92,
       5,   164,    95,    96,   163,   159,   165,   963,     5,   165,
     962,   963,   163,   159,   165,   165,   159,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   163,    64,   165,
       6,    67,    68,     6,    70,    71,    72,   163,   161,   165,
      76,   449,   450,   451,    74,   997,   998,   999,   163,   163,
     165,   165,   165,    83,   164,  1007,  1008,   163,   768,   165,
     468,    91,    92,  1015,   112,    95,    96,     6,   104,   105,
     106,  1023,   165,   163,   163,   165,   165,     6,   163,    74,
     165,   163,     6,   165,   794,   795,   796,   797,    83,   159,
       4,  1043,  1044,  1045,     6,   164,    91,    92,   156,  1052,
      95,    96,  1054,   163,   161,   165,    74,  1059,   163,   163,
     165,   165,  1015,     7,   163,    83,   165,   163,   163,   165,
     165,  1077,   159,    91,    92,    74,  1078,    95,    96,   165,
     163,   163,   165,   165,    83,   165,   163,   165,   165,   561,
    1096,   164,    91,    92,  1096,     6,    95,    96,  1100,     7,
     163,    74,   165,     7,  1106,  1107,     7,   157,   157,  1111,
      83,   157,     7,   157,     6,   158,  1118,  1319,    91,    92,
     165,     7,    95,    96,  1130,     6,  1128,     7,  1130,     6,
       6,     6,     4,  1134,  1135,   164,   594,   164,   596,   164,
    1142,   109,   164,   164,   158,   158,   163,   165,  1101,   158,
    1152,   163,   624,   163,  1156,   158,   163,  1159,     6,     4,
     160,     4,     6,   635,     6,  1171,   165,     6,     4,  1171,
       7,   112,     7,     7,     7,  1177,  1178,   112,   636,     7,
       7,   112,     7,  1136,     7,  1138,     6,  1140,   165,   161,
     165,     6,   165,   160,     7,    74,     7,  1199,     7,  1152,
     161,   164,  1155,  1156,    83,     6,  1476,   157,   157,   164,
    1412,     6,    91,    92,     4,   158,    95,    96,   676,     6,
     678,   160,     6,     6,   682,   683,   684,   685,     7,  1231,
     159,     6,   690,     7,   706,    12,    13,   144,    59,     7,
       7,     7,    61,  1513,     7,  1515,     7,  1249,     7,  1251,
       6,   164,     7,   158,     7,   158,   158,     7,   158,  1261,
       7,  1263,     6,  1023,  1266,  1535,     4,     4,   157,  1271,
       6,   164,     7,     6,  1276,     7,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   165,    64,     7,     7,
      67,    68,     6,    70,    71,    72,     6,     6,     6,    76,
    1302,    59,     6,     4,  1305,     4,     4,  1309,   165,  1311,
     768,  1313,     6,     4,     6,   164,   157,     7,   158,     6,
     158,  1323,     6,     6,    67,  1327,   158,   104,   105,   106,
     161,     6,     6,     6,  1336,  1337,   794,   795,   796,   797,
       6,  1343,   814,   815,     6,   817,   164,   819,   820,  1351,
     164,   823,   824,  1355,   164,     5,  1309,   164,  1311,     4,
    1313,     7,     6,   159,     7,     7,     7,     7,  1321,     6,
     164,  1324,   164,     6,     6,   164,   164,   158,   164,  1381,
     160,     6,   108,     6,     6,   163,     6,     4,   165,   161,
       6,     6,  1152,     6,     6,     6,  1156,  1399,     6,     6,
    1402,     6,     6,  1405,     5,     4,     6,  1409,     6,   112,
       6,  1413,     6,  1415,     6,     6,     6,     6,  1420,     6,
       6,  1423,   163,  1425,     6,   897,   898,   899,     6,     6,
     164,     6,   161,     7,     6,   907,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     6,   918,     5,    57,   156,
       6,     6,     6,     6,  1456,     6,     6,     6,   164,   164,
       7,     6,  1415,   165,     6,   165,     6,   164,   164,   164,
       6,  1473,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   164,     6,   107,   165,
     156,  1251,   110,     6,     6,     6,   968,  1503,     6,  1501,
     164,     6,   974,     6,   164,     6,  1266,   165,   980,   981,
     982,     6,    74,   164,   986,     6,     4,     4,   165,   991,
     992,   993,     6,     6,     6,  1531,     6,     6,     6,     6,
       6,     6,     6,   164,   164,  1007,   164,     6,     6,     6,
     164,     6,  1302,     6,     6,  1017,     6,     6,     6,  1021,
     164,     6,     6,     6,   164,     6,     6,     6,   164,     6,
       3,     4,   164,  1323,     6,  1023,     9,    10,    11,   164,
       6,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     7,     8,   960,  1381,   967,     3,    42,
      43,     3,  1074,   402,  1076,   378,  1081,  1459,    -1,    -1,
      53,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,  1121,
    1122,  1123,  1124,  1413,    -1,  1415,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,   124,  1154,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,  1165,    -1,    -1,  1456,    -1,     6,    -1,
    1172,    -1,    -1,    -1,   147,   148,    -1,  1179,    -1,   152,
      -1,    -1,    -1,  1473,   157,    -1,    -1,    -1,    -1,   162,
      -1,   164,   165,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     3,     4,
      -1,    -1,   156,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,  1246,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,  1275,    -1,    -1,    71,    -1,  1266,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,     6,    -1,    -1,  1301,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,  1302,    -1,  1318,    -1,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,  1323,   131,   132,   133,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,   147,   148,    -1,   156,    -1,   152,    -1,    -1,
      -1,    -1,   157,    -1,    -1,  1367,    -1,   162,    -1,    -1,
     165,     3,     4,     5,    -1,     7,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    12,    13,    -1,    -1,    -1,
    1422,    -1,  1424,    -1,    -1,  1413,    -1,  1415,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,  1473,   118,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,  1499,    -1,   131,
     132,   133,   134,   135,   136,   137,    -1,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,   147,   148,    -1,    -1,    -1,
     152,    -1,   154,   155,    -1,   157,    -1,   159,    -1,   161,
     162,    -1,   164,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,   165,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   124,    -1,    -1,    -1,   156,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,    -1,    -1,   147,   148,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,     3,
       4,     5,   162,    -1,   164,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,   165,    -1,    -1,    12,    13,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,    -1,     3,     4,     5,   162,    -1,
     164,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,   165,    -1,    -1,
      12,    13,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,
      -1,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    -1,    76,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,   133,     6,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,   147,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,
      -1,     3,     4,    -1,   162,    -1,   164,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   124,     6,    -1,    -1,   156,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,    -1,     3,     4,    -1,
     162,    -1,   164,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      56,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     6,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,    -1,     3,     4,    -1,   162,    -1,   164,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   124,     6,    -1,    -1,   156,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,     3,
       4,    -1,   162,    -1,   164,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     6,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,    -1,     3,     4,    -1,   162,    -1,
     164,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,
      -1,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   124,    -1,    -1,    -1,
     156,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,
      -1,     3,     4,     5,   162,    -1,   164,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,     3,     4,    46,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,   124,   125,   126,    42,    43,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,    -1,   164,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,   162,    -1,   164,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,    -1,   162,    -1,   164,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,     3,     4,     5,    -1,    42,    43,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,     3,     4,
      -1,    -1,    42,    43,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,    -1,   124,   160,    -1,   162,    -1,   164,
      -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,   157,    -1,   124,
      -1,    -1,   162,    -1,   164,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,    -1,     3,     4,    -1,   162,    -1,   164,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,     3,
       4,    -1,    -1,    42,    43,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,     6,
     124,    -1,    -1,   162,    -1,   164,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,     3,
       4,     5,    -1,   157,    -1,     9,    10,    11,   162,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
       3,     4,    46,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     6,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     7,    -1,    -1,    -1,   156,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     8,    -1,    -1,    -1,   156,
     124,   125,   126,    -1,    -1,    -1,    -1,   131,   132,   133,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,     8,    -1,    -1,    -1,   162,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,    -1,    -1,    -1,   152,
      -1,    -1,     8,    -1,   157,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     8,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    74,
      -1,   156,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,     0,     1,    -1,   156,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    36,
      37,   156,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,     4,    93,    94,    -1,    -1,
      -1,    98,    -1,    12,    13,    -1,   103,   104,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    36,    37,    -1,
     127,   128,   129,   130,    -1,    44,    45,    -1,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    12,    13,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,    -1,    -1,
     109,    -1,   111,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,   127,   128,
     129,   130,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    -1,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   104,   105,   106,   163,    -1,   165,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,   165,    -1,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,   165,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,   163,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,   160,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
     160,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,   160,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
     160,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
      -1,    -1,   160,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,   160,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   160,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
     160,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,   160,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,   160,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   168,   169,     6,     0,     4,    12,    13,    36,
      37,    44,    45,    47,    48,    49,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    93,    94,    98,   103,   104,   105,
     106,   109,   111,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   127,   128,   129,   130,   170,   172,
     173,   191,   205,   210,   213,   214,   215,   216,   217,   218,
     219,   239,   240,   241,   242,     3,     4,     5,     7,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    39,    40,    41,    42,    43,    46,
     118,   124,   125,   126,   131,   132,   133,   134,   135,   136,
     137,   147,   148,   152,   154,   155,   157,   159,   161,   162,
     164,   189,   190,   243,   244,   256,    13,    59,   157,   157,
       6,   164,     6,     6,     6,     6,   159,   159,   157,   164,
     157,   157,     4,   157,   164,   157,   157,     4,   164,   157,
     157,    63,    59,    59,     6,    59,    59,    56,    59,    61,
      61,    53,    56,    59,    61,    56,    59,    61,    56,    59,
     157,    56,   164,   147,   148,   157,   164,   245,   246,   245,
     164,    53,    56,    59,   164,   245,     4,    53,    57,    67,
      59,    61,    59,    56,     4,   118,   164,     4,     6,    53,
      56,    59,    56,    59,     4,     4,     4,     5,    35,    53,
      56,    59,    61,    71,   148,   157,   164,   210,   219,   243,
     248,   249,   250,     4,   157,   157,   157,     4,   164,   252,
       4,   157,   157,     6,     6,   159,     4,     4,     5,   164,
       5,   164,     4,   243,     6,   157,   164,     4,   159,   161,
     166,   190,   164,     5,   256,   157,   159,   157,   159,   157,
     159,   157,   159,   157,   159,   157,   159,   157,   159,   157,
     159,   157,   159,   157,   159,   157,   159,   157,   159,   157,
     159,   157,   159,   157,   159,   157,   159,   157,   159,   157,
     159,   157,   159,   157,   159,   157,   159,   157,   157,   157,
     157,   157,   157,     7,   157,   157,   157,   243,   243,   243,
     164,   243,   160,   164,   243,     4,   109,   110,     4,     4,
     210,   211,   212,   248,     6,     6,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     156,     6,     6,   243,     5,     5,   243,   193,   196,   243,
     148,   243,   250,   251,   243,   243,   157,   243,   251,   243,
     243,   157,   251,   243,   243,   248,   157,   164,   157,   157,
     249,   249,   249,   157,   206,   207,   208,   209,   157,   157,
     157,   248,   243,     4,   248,   245,   245,   245,   243,   243,
     147,   148,   164,   164,   245,   164,   164,   164,   147,   148,
     157,   212,   245,   164,   157,   164,   157,   157,   157,   249,
     249,   248,   157,     4,     6,   159,   159,   212,     6,   164,
     164,   164,   249,   249,   159,   159,   157,   159,   159,     5,
     164,     5,     5,     5,    53,    56,    59,    61,   164,   243,
     250,   243,   165,   251,     8,   149,     6,     6,   243,   243,
     243,   161,   243,   164,   112,   243,   243,   243,     6,     6,
     212,     6,   212,   159,     6,   248,   248,   159,   243,     4,
     164,   174,     6,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,     4,   255,   256,   255,   255,
     255,   255,   255,   257,   243,   255,   255,   255,   251,   158,
       7,   189,   251,   160,     7,   189,   190,   161,     7,   159,
     165,    53,    56,    59,    61,   205,     6,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,     6,   158,   163,   158,   163,   163,   160,   163,
     192,   160,   192,   158,   149,   163,   165,   158,   158,   243,
     158,   165,   158,   158,   243,   165,   158,   158,     7,   243,
     243,   243,   243,     7,     7,   237,   237,   243,   157,   157,
     157,   157,   243,   243,   243,     7,   164,   158,     6,   163,
     163,   163,   245,   245,   211,   211,   163,   243,   243,   243,
     243,   223,   163,   212,   243,   243,   243,   243,   243,     7,
     238,     6,     7,   243,     6,   243,   243,   165,   251,   251,
     251,     6,     6,   243,   243,   158,   164,   160,   164,   243,
       4,   243,   164,   164,   164,   164,   251,   158,   165,   243,
     164,   243,   250,   158,   158,   158,   109,   163,   212,   164,
       8,   158,   160,   165,   165,   158,   163,   165,   243,   160,
     190,   243,     4,    99,   100,   101,   102,   165,   177,   181,
     184,   186,   187,   158,   160,   158,   160,   158,   160,   158,
     160,   158,   160,   158,   160,   158,   160,   158,   160,   158,
     160,   158,   160,   158,   160,   163,   163,   158,   160,   158,
     160,   158,   160,   158,   160,   158,   160,   158,   160,   163,
     163,   163,   163,   163,   163,   159,   161,   158,   163,   163,
     158,   158,   163,   158,   163,     6,   163,   158,   163,   165,
     189,   248,   165,   161,   189,   190,   256,   243,     6,     4,
       4,   164,   253,   160,   164,   164,   164,   164,     8,     6,
     144,   171,   251,     6,   251,   243,     6,     4,     6,   255,
       7,   243,   250,   112,     7,     7,   158,     7,   112,     7,
       7,   158,   112,     7,     7,   243,   158,   165,   158,   158,
     243,   248,     4,   236,     6,   158,   202,   243,   256,   202,
     202,   202,   158,   158,   158,   248,   251,   161,   245,   243,
     243,   165,   165,   243,   245,   163,   163,   163,    74,    83,
      91,    92,    95,    96,   233,   234,   245,   165,   220,   158,
     165,   158,   158,   158,   243,     6,   243,   158,   160,   160,
     165,   165,   165,   160,   160,   251,   251,   160,   160,   165,
     251,   251,   251,   251,   165,     8,   251,     7,     7,     7,
     161,   243,   165,   243,   243,     7,   161,   164,   248,     6,
     160,   161,   190,   255,   165,   178,   157,   157,   164,   188,
       6,   243,   243,   243,   243,   243,   243,   243,   243,   243,
       4,   251,   255,   255,   255,   243,   255,   158,   243,     6,
     160,     4,   109,   110,   243,     6,     6,     6,     7,   159,
     252,   254,     6,   251,   251,   251,   251,   243,   144,   255,
     158,   158,   163,     7,   245,    59,   248,   248,     7,   248,
      59,    61,   248,   248,     7,    61,   248,   248,     6,     7,
       7,     7,     7,    74,   235,     6,     7,   158,   158,   158,
     158,     7,     7,     7,     6,   165,     4,   163,   163,   163,
     165,   165,   245,   245,   245,     4,     6,   164,   157,     6,
      97,     6,    97,   165,   234,   163,   233,     7,     6,     7,
       7,     7,     6,   164,     6,     6,     6,    59,   243,     6,
       6,   165,   165,   165,   165,   165,   165,   243,   165,   248,
     248,   248,     4,   163,     8,     8,   158,     4,     4,   248,
     165,     6,     4,     6,   157,   243,   243,   247,   248,   164,
     158,   160,   158,   160,   158,   160,   158,   160,   160,   158,
     158,   158,   158,   158,   189,     6,   189,     7,   189,   190,
     161,     7,     6,   252,   243,   163,   165,   165,   165,   165,
     165,     6,     6,   171,     6,   243,   164,   243,   256,     6,
     164,    67,   204,   204,   248,     6,   164,   164,     6,     6,
     248,   164,     6,     6,     5,   248,   248,   248,     4,     6,
     248,     7,     7,     7,     7,   248,   248,   248,     7,     6,
       7,   243,   243,   243,   164,   164,   163,   165,   163,   165,
     163,   165,   159,   243,   248,   243,     6,     6,   243,   245,
     165,     5,   164,   248,   164,   164,   164,   248,   251,   164,
       6,   158,   160,     6,     6,   108,   243,   243,   243,     6,
       6,     7,   163,     6,   190,   175,   243,   163,   163,   163,
     165,   176,   243,   161,   248,   248,   256,   243,     6,     4,
     253,     6,   160,   252,     6,     6,     6,     6,   255,   163,
     243,   256,   243,   245,     6,     6,     6,   243,   243,     6,
     243,     5,     6,     6,   112,   203,   243,     6,   248,   248,
     248,   248,     6,     4,     6,     6,   243,   243,   256,   165,
     158,   163,   165,   211,   211,   245,     6,   224,   245,     6,
     225,   245,     6,   226,   243,   165,   163,   158,   165,   163,
       6,   148,   245,     6,   247,   245,   245,     6,   165,   243,
     248,   163,   165,     8,   165,   158,   164,   243,   256,   248,
     158,   163,   243,   243,   248,   164,   163,   165,     4,     6,
       6,     6,     6,     7,     6,   161,     6,   243,   194,   195,
     165,   165,   165,   165,     5,    57,     6,     6,     6,     6,
       6,   164,   164,     6,     6,   164,   243,   165,   165,   163,
     164,   163,   164,   163,   164,   160,     6,   248,     7,   164,
     243,   163,   165,   163,   163,     6,   165,   107,   243,   243,
     251,     6,     6,   165,   179,   243,   163,   163,   247,   243,
       6,   252,   110,   163,   198,   200,     6,     6,     6,     6,
       6,   164,   247,   251,   211,   163,   165,   243,   245,   233,
     243,   245,   233,   243,   245,   233,     6,   163,   165,   248,
     212,   165,   245,     6,   251,   245,   243,   165,   165,   165,
       6,   164,   243,   243,   165,     6,   243,   163,   165,   199,
     163,   165,   201,   243,   165,   165,   165,   243,   165,   163,
     165,   165,   163,   165,   165,   163,   165,   248,     6,    74,
     165,   221,   164,   163,   165,   163,     6,     6,   176,   158,
     163,     6,   164,   163,     4,     4,   165,     6,     6,   165,
       6,   227,   243,     6,     6,   228,   243,     6,     6,   229,
     243,     6,   165,   243,   233,   212,   251,     6,   245,   251,
     165,   182,   243,   247,   243,     5,   164,   248,     5,   164,
     243,   164,   165,   164,   165,   164,   165,     6,     6,   165,
     165,   222,   165,   163,   165,     6,   164,   158,   165,   165,
     197,   243,   257,   233,     6,   230,   233,     6,   231,   233,
       6,   232,   233,     6,   251,     6,   180,   255,   185,   164,
       6,   163,   165,     7,   165,   165,   164,   165,   164,   165,
     164,   165,   165,   163,   165,   164,   247,   243,   256,     6,
     233,     6,   233,     6,   233,     6,   255,     6,   183,   255,
     165,     7,   165,   165,   165,   163,   165,     6,   256,     6,
       6,     6,   255,     6
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
#line 168 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 179 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 180 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 181 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 182 "Gmsh.y"
    { return 1; ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 183 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 184 "Gmsh.y"
    { return 1; ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 185 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 186 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 187 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 188 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 189 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 190 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 191 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 192 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 193 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 198 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 202 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 209 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 214 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 25:

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

  case 26:

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

  case 27:

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

  case 28:

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

  case 29:

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

  case 30:

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

  case 31:

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

  case 32:

/* Line 1464 of yacc.c  */
#line 326 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 340 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 342 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 347 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 349 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 42:

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

  case 43:

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

  case 44:

/* Line 1464 of yacc.c  */
#line 468 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 477 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 484 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 47:

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

  case 48:

/* Line 1464 of yacc.c  */
#line 503 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 51:

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

  case 52:

/* Line 1464 of yacc.c  */
#line 537 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 53:

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

  case 54:

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

  case 55:

/* Line 1464 of yacc.c  */
#line 585 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 591 "Gmsh.y"
    {
    ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 598 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 599 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 600 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 601 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 602 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 606 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 607 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 618 "Gmsh.y"
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

  case 67:

/* Line 1464 of yacc.c  */
#line 680 "Gmsh.y"
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

  case 68:

/* Line 1464 of yacc.c  */
#line 710 "Gmsh.y"
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

  case 69:

/* Line 1464 of yacc.c  */
#line 745 "Gmsh.y"
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
#line 779 "Gmsh.y"
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
#line 827 "Gmsh.y"
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
#line 874 "Gmsh.y"
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

  case 73:

/* Line 1464 of yacc.c  */
#line 889 "Gmsh.y"
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

  case 74:

/* Line 1464 of yacc.c  */
#line 905 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 914 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 920 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 929 "Gmsh.y"
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

  case 78:

/* Line 1464 of yacc.c  */
#line 947 "Gmsh.y"
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

  case 79:

/* Line 1464 of yacc.c  */
#line 965 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 974 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 986 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 991 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 999 "Gmsh.y"
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

  case 84:

/* Line 1464 of yacc.c  */
#line 1019 "Gmsh.y"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 1042 "Gmsh.y"
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

  case 86:

/* Line 1464 of yacc.c  */
#line 1053 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1061 "Gmsh.y"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 1083 "Gmsh.y"
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

  case 89:

/* Line 1464 of yacc.c  */
#line 1106 "Gmsh.y"
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

  case 90:

/* Line 1464 of yacc.c  */
#line 1132 "Gmsh.y"
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

  case 91:

/* Line 1464 of yacc.c  */
#line 1153 "Gmsh.y"
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

  case 92:

/* Line 1464 of yacc.c  */
#line 1165 "Gmsh.y"
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

  case 96:

/* Line 1464 of yacc.c  */
#line 1183 "Gmsh.y"
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

  case 97:

/* Line 1464 of yacc.c  */
#line 1194 "Gmsh.y"
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

  case 98:

/* Line 1464 of yacc.c  */
#line 1205 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1207 "Gmsh.y"
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

  case 100:

/* Line 1464 of yacc.c  */
#line 1217 "Gmsh.y"
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

  case 101:

/* Line 1464 of yacc.c  */
#line 1228 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1230 "Gmsh.y"
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
#line 1244 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 1252 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1258 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1270 "Gmsh.y"
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

  case 110:

/* Line 1464 of yacc.c  */
#line 1281 "Gmsh.y"
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

  case 111:

/* Line 1464 of yacc.c  */
#line 1296 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1312 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1320 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1329 "Gmsh.y"
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

  case 117:

/* Line 1464 of yacc.c  */
#line 1347 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1351 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), curPhysDim,
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1361 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1365 "Gmsh.y"
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

  case 121:

/* Line 1464 of yacc.c  */
#line 1377 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1381 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1391 "Gmsh.y"
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

  case 124:

/* Line 1464 of yacc.c  */
#line 1414 "Gmsh.y"
    {
      curPhysDim = 0;
    ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1418 "Gmsh.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 1434 "Gmsh.y"
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

  case 127:

/* Line 1464 of yacc.c  */
#line 1456 "Gmsh.y"
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

  case 128:

/* Line 1464 of yacc.c  */
#line 1474 "Gmsh.y"
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

  case 129:

/* Line 1464 of yacc.c  */
#line 1495 "Gmsh.y"
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

  case 130:

/* Line 1464 of yacc.c  */
#line 1513 "Gmsh.y"
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

  case 131:

/* Line 1464 of yacc.c  */
#line 1543 "Gmsh.y"
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

  case 132:

/* Line 1464 of yacc.c  */
#line 1573 "Gmsh.y"
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

  case 133:

/* Line 1464 of yacc.c  */
#line 1591 "Gmsh.y"
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

  case 134:

/* Line 1464 of yacc.c  */
#line 1609 "Gmsh.y"
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

  case 135:

/* Line 1464 of yacc.c  */
#line 1635 "Gmsh.y"
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

  case 136:

/* Line 1464 of yacc.c  */
#line 1653 "Gmsh.y"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1671 "Gmsh.y"
    {
      curPhysDim = 1;
    ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1675 "Gmsh.y"
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

  case 139:

/* Line 1464 of yacc.c  */
#line 1694 "Gmsh.y"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 1712 "Gmsh.y"
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

  case 141:

/* Line 1464 of yacc.c  */
#line 1751 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1757 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1763 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1770 "Gmsh.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1795 "Gmsh.y"
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

  case 146:

/* Line 1464 of yacc.c  */
#line 1820 "Gmsh.y"
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

  case 147:

/* Line 1464 of yacc.c  */
#line 1837 "Gmsh.y"
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

  case 148:

/* Line 1464 of yacc.c  */
#line 1855 "Gmsh.y"
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

  case 149:

/* Line 1464 of yacc.c  */
#line 1885 "Gmsh.y"
    {
      curPhysDim = 2;
    ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1889 "Gmsh.y"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1909 "Gmsh.y"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1927 "Gmsh.y"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 1944 "Gmsh.y"
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

  case 154:

/* Line 1464 of yacc.c  */
#line 1960 "Gmsh.y"
    {
      curPhysDim = 3;
    ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1964 "Gmsh.y"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 1986 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1991 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1996 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 2001 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 2006 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 2011 "Gmsh.y"
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

  case 162:

/* Line 1464 of yacc.c  */
#line 2034 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 2040 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 2050 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 2051 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 2056 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 2060 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 2064 "Gmsh.y"
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

  case 169:

/* Line 1464 of yacc.c  */
#line 2087 "Gmsh.y"
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

  case 170:

/* Line 1464 of yacc.c  */
#line 2110 "Gmsh.y"
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

  case 171:

/* Line 1464 of yacc.c  */
#line 2133 "Gmsh.y"
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

  case 172:

/* Line 1464 of yacc.c  */
#line 2161 "Gmsh.y"
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

  case 173:

/* Line 1464 of yacc.c  */
#line 2182 "Gmsh.y"
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

  case 174:

/* Line 1464 of yacc.c  */
#line 2206 "Gmsh.y"
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

  case 175:

/* Line 1464 of yacc.c  */
#line 2227 "Gmsh.y"
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

  case 176:

/* Line 1464 of yacc.c  */
#line 2248 "Gmsh.y"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 2268 "Gmsh.y"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 2380 "Gmsh.y"
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

  case 179:

/* Line 1464 of yacc.c  */
#line 2399 "Gmsh.y"
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

  case 180:

/* Line 1464 of yacc.c  */
#line 2438 "Gmsh.y"
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

  case 181:

/* Line 1464 of yacc.c  */
#line 2546 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 2555 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 2561 "Gmsh.y"
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

  case 184:

/* Line 1464 of yacc.c  */
#line 2576 "Gmsh.y"
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

  case 185:

/* Line 1464 of yacc.c  */
#line 2604 "Gmsh.y"
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

  case 186:

/* Line 1464 of yacc.c  */
#line 2621 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 2635 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 2641 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 2647 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 2656 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 2670 "Gmsh.y"
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

  case 192:

/* Line 1464 of yacc.c  */
#line 2715 "Gmsh.y"
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

  case 193:

/* Line 1464 of yacc.c  */
#line 2732 "Gmsh.y"
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

  case 194:

/* Line 1464 of yacc.c  */
#line 2747 "Gmsh.y"
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

  case 195:

/* Line 1464 of yacc.c  */
#line 2766 "Gmsh.y"
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

  case 196:

/* Line 1464 of yacc.c  */
#line 2778 "Gmsh.y"
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

  case 197:

/* Line 1464 of yacc.c  */
#line 2802 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 2806 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 2811 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 2818 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 2824 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 2829 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 2835 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 2839 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 2843 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 2848 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete);
#endif
    ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 2860 "Gmsh.y"
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

  case 208:

/* Line 1464 of yacc.c  */
#line 2877 "Gmsh.y"
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

  case 209:

/* Line 1464 of yacc.c  */
#line 2894 "Gmsh.y"
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

  case 210:

/* Line 1464 of yacc.c  */
#line 2915 "Gmsh.y"
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

  case 211:

/* Line 1464 of yacc.c  */
#line 2936 "Gmsh.y"
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

  case 212:

/* Line 1464 of yacc.c  */
#line 2971 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         ((yyvsp[(2) - (2)].c), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 2979 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 2985 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         ((yyvsp[(2) - (3)].c), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      //FIXME: wee leak $2
    ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 2992 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 2996 "Gmsh.y"
    {
    ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 3005 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 3013 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 3021 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 3029 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 3034 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 3042 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 3047 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 3055 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 3060 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 3068 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 3073 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 3081 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 3088 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 3095 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 3102 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 3109 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 3116 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 3123 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 3130 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 3137 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 3144 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 3149 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 3156 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 3161 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 3168 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 3173 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 3180 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 3185 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 3192 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 3197 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 3204 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 3209 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 3216 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 3221 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 3228 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 3233 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 3240 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
    ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 3256 "Gmsh.y"
    {
    ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 3259 "Gmsh.y"
    {
    ;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 3265 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
      extr.mesh.hLayer.push_back(1.);
    ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 3274 "Gmsh.y"
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

  case 259:

/* Line 1464 of yacc.c  */
#line 3294 "Gmsh.y"
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

  case 260:

/* Line 1464 of yacc.c  */
#line 3317 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 3321 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1;
    ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 3325 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_DBL_1_RECOMB;
    ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 3329 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1;
    ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 3333 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_SNGL_1_RECOMB;
    ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 3337 "Gmsh.y"
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

  case 266:

/* Line 1464 of yacc.c  */
#line 3356 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 3368 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 3372 "Gmsh.y"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 3387 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 3391 "Gmsh.y"
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

  case 271:

/* Line 1464 of yacc.c  */
#line 3403 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 3407 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 3412 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 3416 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 3423 "Gmsh.y"
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
            (*it)->meshAttributes.method = MESH_TRANSFINITE;
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
                ge->meshAttributes.method = MESH_TRANSFINITE;
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

  case 276:

/* Line 1464 of yacc.c  */
#line 3479 "Gmsh.y"
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
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
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
                gf->meshAttributes.method = MESH_TRANSFINITE;
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

  case 277:

/* Line 1464 of yacc.c  */
#line 3549 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    ;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 3554 "Gmsh.y"
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
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
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
                gr->meshAttributes.method = MESH_TRANSFINITE;
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

  case 279:

/* Line 1464 of yacc.c  */
#line 3621 "Gmsh.y"
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

  case 280:

/* Line 1464 of yacc.c  */
#line 3657 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 3665 "Gmsh.y"
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

  case 282:

/* Line 1464 of yacc.c  */
#line 3708 "Gmsh.y"
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

  case 283:

/* Line 1464 of yacc.c  */
#line 3747 "Gmsh.y"
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

  case 284:

/* Line 1464 of yacc.c  */
#line 3767 "Gmsh.y"
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

  case 285:

/* Line 1464 of yacc.c  */
#line 3795 "Gmsh.y"
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

  case 286:

/* Line 1464 of yacc.c  */
#line 3834 "Gmsh.y"
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

  case 287:

/* Line 1464 of yacc.c  */
#line 3857 "Gmsh.y"
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

  case 288:

/* Line 1464 of yacc.c  */
#line 3880 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 3884 "Gmsh.y"
    {
      Msg::Error("Surface in Volume not implemented yet");
    ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 3888 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->ReverseMesh = 1;
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 3927 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          Curve *c = FindCurve((int)d);
          if(c){
            c->ReverseMesh = 1;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag((int)d);
            if(ge){
              ge->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    ;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 3972 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    ;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 3976 "Gmsh.y"
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

  case 294:

/* Line 1464 of yacc.c  */
#line 3986 "Gmsh.y"
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

  case 295:

/* Line 1464 of yacc.c  */
#line 4020 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 4021 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 4022 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 4027 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 4033 "Gmsh.y"
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

  case 300:

/* Line 1464 of yacc.c  */
#line 4045 "Gmsh.y"
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

  case 301:

/* Line 1464 of yacc.c  */
#line 4063 "Gmsh.y"
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

  case 302:

/* Line 1464 of yacc.c  */
#line 4090 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 4091 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 4092 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 4093 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 4094 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 4095 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 4096 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 4097 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 4099 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 4105 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 4106 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 4107 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 4108 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 4109 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 4110 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 4111 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 4112 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 4113 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 4114 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 4115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 4116 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 4117 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 4118 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 4119 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 4120 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 4121 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 4122 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 4123 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 4124 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 4125 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 4126 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 4127 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 4128 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 4129 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 4130 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 4131 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 4132 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 4133 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 4134 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 4135 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 4136 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 4139 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 4140 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 4141 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 4142 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 4143 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 4144 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 4145 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 4146 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 4147 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 4148 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 4149 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 4150 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 4151 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 4152 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 4153 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 4154 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 4155 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 4156 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 4157 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 4158 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 4159 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 4168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 4169 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 4170 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 4171 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 4172 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 4173 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 4174 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 4179 "Gmsh.y"
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

  case 372:

/* Line 1464 of yacc.c  */
#line 4200 "Gmsh.y"
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

  case 373:

/* Line 1464 of yacc.c  */
#line 4219 "Gmsh.y"
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

  case 374:

/* Line 1464 of yacc.c  */
#line 4237 "Gmsh.y"
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

  case 375:

/* Line 1464 of yacc.c  */
#line 4249 "Gmsh.y"
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

  case 376:

/* Line 1464 of yacc.c  */
#line 4266 "Gmsh.y"
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

  case 377:

/* Line 1464 of yacc.c  */
#line 4287 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 4292 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 4297 "Gmsh.y"
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

  case 380:

/* Line 1464 of yacc.c  */
#line 4307 "Gmsh.y"
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

  case 381:

/* Line 1464 of yacc.c  */
#line 4317 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 4322 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 4331 "Gmsh.y"
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

  case 384:

/* Line 1464 of yacc.c  */
#line 4358 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 4362 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 4366 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 4370 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 4374 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 4381 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 4385 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 4389 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 4393 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 4400 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 4405 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 4412 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 4417 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 4421 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 4426 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 4430 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 4438 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 4449 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 4453 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    ;}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 4465 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 4473 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 4481 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 4488 "Gmsh.y"
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

  case 407:

/* Line 1464 of yacc.c  */
#line 4498 "Gmsh.y"
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

  case 408:

/* Line 1464 of yacc.c  */
#line 4518 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(0);
    ;}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 4522 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(1);
    ;}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 4526 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(2);
    ;}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 4530 "Gmsh.y"
    {
      (yyval.l) = GetAllEntityNumbers(3);
    ;}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 4534 "Gmsh.y"
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

  case 413:

/* Line 1464 of yacc.c  */
#line 4563 "Gmsh.y"
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

  case 414:

/* Line 1464 of yacc.c  */
#line 4592 "Gmsh.y"
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

  case 415:

/* Line 1464 of yacc.c  */
#line 4621 "Gmsh.y"
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

  case 416:

/* Line 1464 of yacc.c  */
#line 4650 "Gmsh.y"
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

  case 417:

/* Line 1464 of yacc.c  */
#line 4660 "Gmsh.y"
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

  case 418:

/* Line 1464 of yacc.c  */
#line 4670 "Gmsh.y"
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

  case 419:

/* Line 1464 of yacc.c  */
#line 4683 "Gmsh.y"
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

  case 420:

/* Line 1464 of yacc.c  */
#line 4695 "Gmsh.y"
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

  case 421:

/* Line 1464 of yacc.c  */
#line 4707 "Gmsh.y"
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

  case 422:

/* Line 1464 of yacc.c  */
#line 4726 "Gmsh.y"
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

  case 423:

/* Line 1464 of yacc.c  */
#line 4747 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 4756 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 4760 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 4772 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 4776 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 4788 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 4795 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 4805 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 4809 "Gmsh.y"
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

  case 433:

/* Line 1464 of yacc.c  */
#line 4824 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 4829 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 4836 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 4840 "Gmsh.y"
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

  case 437:

/* Line 1464 of yacc.c  */
#line 4853 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 4861 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 4872 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 4876 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 4884 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 4892 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 4900 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (6)].c)) + strlen((yyvsp[(5) - (6)].c)) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (6)].c));
      strcat((yyval.c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 4908 "Gmsh.y"
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

  case 445:

/* Line 1464 of yacc.c  */
#line 4922 "Gmsh.y"
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

  case 446:

/* Line 1464 of yacc.c  */
#line 4936 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 4940 "Gmsh.y"
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

  case 448:

/* Line 1464 of yacc.c  */
#line 4962 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 4967 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); ;}
    break;



/* Line 1464 of yacc.c  */
#line 10886 "Gmsh.tab.cpp"
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
#line 4970 "Gmsh.y"


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

