/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         gmsh_yyparse
#define yylex           gmsh_yylex
#define yyerror         gmsh_yyerror
#define yylval          gmsh_yylval
#define yychar          gmsh_yychar
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <sstream>
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
std::map<std::string, std::string> gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static const char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

struct doubleXstring{
  double d;
  char *s;
};


/* Line 371 of yacc.c  */
#line 173 "Gmsh.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Gmsh.tab.hpp".  */
#ifndef YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
# define YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
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
     tRound = 287,
     tFmod = 288,
     tModulo = 289,
     tHypot = 290,
     tList = 291,
     tPrintf = 292,
     tError = 293,
     tStr = 294,
     tSprintf = 295,
     tStrCat = 296,
     tStrPrefix = 297,
     tStrRelative = 298,
     tStrReplace = 299,
     tStrFind = 300,
     tStrCmp = 301,
     tStrChoice = 302,
     tTextAttributes = 303,
     tBoundingBox = 304,
     tDraw = 305,
     tSetChanged = 306,
     tToday = 307,
     tFixRelativePath = 308,
     tSyncModel = 309,
     tOnelabAction = 310,
     tOnelabRun = 311,
     tCpu = 312,
     tMemory = 313,
     tTotalMemory = 314,
     tCreateTopology = 315,
     tCreateTopologyNoHoles = 316,
     tDistanceFunction = 317,
     tDefineConstant = 318,
     tUndefineConstant = 319,
     tDefineNumber = 320,
     tDefineString = 321,
     tPoint = 322,
     tCircle = 323,
     tEllipse = 324,
     tLine = 325,
     tSphere = 326,
     tPolarSphere = 327,
     tSurface = 328,
     tSpline = 329,
     tVolume = 330,
     tCharacteristic = 331,
     tLength = 332,
     tParametric = 333,
     tElliptic = 334,
     tRefineMesh = 335,
     tAdaptMesh = 336,
     tRelocateMesh = 337,
     tPlane = 338,
     tRuled = 339,
     tTransfinite = 340,
     tComplex = 341,
     tPhysical = 342,
     tCompound = 343,
     tPeriodic = 344,
     tUsing = 345,
     tPlugin = 346,
     tDegenerated = 347,
     tRecursive = 348,
     tRotate = 349,
     tTranslate = 350,
     tSymmetry = 351,
     tDilate = 352,
     tExtrude = 353,
     tLevelset = 354,
     tRecombine = 355,
     tSmoother = 356,
     tSplit = 357,
     tDelete = 358,
     tCoherence = 359,
     tIntersect = 360,
     tMeshAlgorithm = 361,
     tReverse = 362,
     tLayers = 363,
     tScaleLast = 364,
     tHole = 365,
     tAlias = 366,
     tAliasWithOptions = 367,
     tCopyOptions = 368,
     tQuadTriAddVerts = 369,
     tQuadTriNoNewVerts = 370,
     tQuadTriSngl = 371,
     tQuadTriDbl = 372,
     tRecombLaterals = 373,
     tTransfQuadTri = 374,
     tText2D = 375,
     tText3D = 376,
     tInterpolationScheme = 377,
     tTime = 378,
     tCombine = 379,
     tBSpline = 380,
     tBezier = 381,
     tNurbs = 382,
     tNurbsOrder = 383,
     tNurbsKnots = 384,
     tColor = 385,
     tColorTable = 386,
     tFor = 387,
     tIn = 388,
     tEndFor = 389,
     tIf = 390,
     tEndIf = 391,
     tExit = 392,
     tAbort = 393,
     tField = 394,
     tReturn = 395,
     tCall = 396,
     tFunction = 397,
     tShow = 398,
     tHide = 399,
     tGetValue = 400,
     tGetEnv = 401,
     tGetString = 402,
     tHomology = 403,
     tCohomology = 404,
     tBetti = 405,
     tSetOrder = 406,
     tExists = 407,
     tFileExists = 408,
     tGMSH_MAJOR_VERSION = 409,
     tGMSH_MINOR_VERSION = 410,
     tGMSH_PATCH_VERSION = 411,
     tAFFECTDIVIDE = 412,
     tAFFECTTIMES = 413,
     tAFFECTMINUS = 414,
     tAFFECTPLUS = 415,
     tOR = 416,
     tAND = 417,
     tNOTEQUAL = 418,
     tEQUAL = 419,
     tGREATEROREQUAL = 420,
     tLESSOREQUAL = 421,
     UNARYPREC = 422,
     tMINUSMINUS = 423,
     tPLUSPLUS = 424
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 99 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 387 of yacc.c  */
#line 396 "Gmsh.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void *YYPARSE_PARAM);
#else
int gmsh_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void);
#else
int gmsh_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 424 "Gmsh.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  190
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  484
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1709

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   424

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   175,     2,   185,     2,   174,     2,     2,
     180,   181,   172,   170,   186,   171,   184,   173,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     166,     2,   167,   161,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   182,     2,   183,   179,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   187,     2,   188,   189,     2,     2,     2,
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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   162,   163,   164,   165,
     168,   169,   176,   177,   178
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    47,    53,    59,    67,    75,    83,    93,
     100,   107,   114,   123,   124,   127,   130,   133,   136,   139,
     141,   145,   147,   151,   152,   153,   164,   166,   170,   171,
     185,   187,   191,   192,   208,   217,   232,   233,   240,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     268,   274,   279,   286,   293,   301,   309,   317,   327,   337,
     341,   348,   355,   360,   367,   377,   384,   394,   400,   409,
     418,   430,   437,   447,   453,   461,   471,   481,   493,   501,
     511,   521,   522,   524,   525,   529,   535,   536,   546,   552,
     553,   563,   564,   568,   572,   578,   579,   582,   586,   592,
     596,   597,   600,   604,   608,   614,   616,   618,   620,   622,
     624,   626,   628,   630,   631,   637,   638,   641,   649,   658,
     665,   673,   678,   686,   695,   704,   712,   720,   732,   741,
     750,   759,   768,   778,   782,   787,   798,   806,   814,   823,
     832,   845,   854,   863,   871,   880,   889,   895,   907,   913,
     923,   933,   938,   948,   958,   960,   962,   963,   966,   973,
     980,   987,   994,  1003,  1014,  1029,  1046,  1059,  1068,  1077,
    1084,  1099,  1104,  1111,  1118,  1122,  1127,  1133,  1140,  1144,
    1148,  1153,  1159,  1164,  1170,  1174,  1180,  1188,  1196,  1200,
    1208,  1212,  1215,  1218,  1221,  1224,  1240,  1243,  1246,  1249,
    1252,  1255,  1272,  1276,  1283,  1292,  1301,  1312,  1314,  1317,
    1319,  1323,  1328,  1330,  1336,  1348,  1362,  1363,  1371,  1372,
    1386,  1387,  1403,  1404,  1411,  1420,  1429,  1438,  1451,  1464,
    1477,  1492,  1507,  1522,  1523,  1536,  1537,  1550,  1551,  1564,
    1565,  1582,  1583,  1600,  1601,  1618,  1619,  1638,  1639,  1658,
    1659,  1678,  1680,  1683,  1689,  1697,  1707,  1710,  1713,  1716,
    1720,  1723,  1727,  1730,  1734,  1737,  1741,  1751,  1758,  1759,
    1763,  1764,  1766,  1767,  1770,  1771,  1774,  1775,  1778,  1786,
    1793,  1802,  1808,  1812,  1820,  1826,  1831,  1838,  1845,  1859,
    1870,  1881,  1892,  1903,  1914,  1919,  1924,  1929,  1934,  1939,
    1942,  1946,  1953,  1955,  1957,  1959,  1962,  1968,  1976,  1987,
    1989,  1993,  1996,  1999,  2002,  2006,  2010,  2014,  2018,  2022,
    2026,  2030,  2034,  2038,  2042,  2046,  2050,  2054,  2058,  2064,
    2069,  2074,  2079,  2084,  2089,  2094,  2099,  2104,  2109,  2114,
    2121,  2126,  2131,  2136,  2141,  2146,  2151,  2156,  2163,  2170,
    2177,  2182,  2184,  2186,  2188,  2190,  2192,  2194,  2196,  2198,
    2200,  2202,  2203,  2210,  2212,  2217,  2222,  2227,  2232,  2237,
    2240,  2246,  2252,  2256,  2263,  2268,  2276,  2283,  2290,  2297,
    2302,  2304,  2307,  2310,  2314,  2318,  2330,  2340,  2348,  2356,
    2358,  2362,  2364,  2366,  2369,  2373,  2378,  2384,  2386,  2388,
    2391,  2395,  2399,  2405,  2410,  2413,  2416,  2419,  2422,  2426,
    2430,  2434,  2438,  2444,  2450,  2456,  2462,  2479,  2496,  2513,
    2530,  2532,  2534,  2538,  2542,  2547,  2554,  2561,  2563,  2565,
    2569,  2573,  2583,  2591,  2593,  2599,  2603,  2610,  2612,  2616,
    2618,  2620,  2624,  2631,  2633,  2635,  2637,  2642,  2649,  2654,
    2659,  2664,  2673,  2678,  2687,  2692,  2699,  2704,  2705,  2712,
    2714,  2718,  2724,  2730,  2732
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     191,     0,    -1,   192,    -1,     1,     6,    -1,    -1,   192,
     193,    -1,   196,    -1,   195,    -1,   216,    -1,   233,    -1,
     234,    -1,   238,    -1,   239,    -1,   240,    -1,   243,    -1,
     264,    -1,   265,    -1,   242,    -1,   241,    -1,   237,    -1,
     267,    -1,   167,    -1,   167,   167,    -1,    37,   180,   281,
     181,     6,    -1,    38,   180,   281,   181,     6,    -1,    37,
     180,   281,   181,   194,   281,     6,    -1,    37,   180,   281,
     186,   277,   181,     6,    -1,    38,   180,   281,   186,   277,
     181,     6,    -1,    37,   180,   281,   186,   277,   181,   194,
     281,     6,    -1,     4,   281,   187,   197,   188,     6,    -1,
     111,     4,   182,   268,   183,     6,    -1,   112,     4,   182,
     268,   183,     6,    -1,   113,     4,   182,   268,   186,   268,
     183,     6,    -1,    -1,   197,   200,    -1,   197,   204,    -1,
     197,   207,    -1,   197,   209,    -1,   197,   210,    -1,   268,
      -1,   198,   186,   268,    -1,   268,    -1,   199,   186,   268,
      -1,    -1,    -1,     4,   201,   180,   198,   181,   202,   187,
     199,   188,     6,    -1,   281,    -1,   203,   186,   281,    -1,
      -1,   120,   180,   268,   186,   268,   186,   268,   181,   205,
     187,   203,   188,     6,    -1,   281,    -1,   206,   186,   281,
      -1,    -1,   121,   180,   268,   186,   268,   186,   268,   186,
     268,   181,   208,   187,   206,   188,     6,    -1,   122,   187,
     273,   188,   187,   273,   188,     6,    -1,   122,   187,   273,
     188,   187,   273,   188,   187,   273,   188,   187,   273,   188,
       6,    -1,    -1,   123,   211,   187,   199,   188,     6,    -1,
       7,    -1,   160,    -1,   159,    -1,   158,    -1,   157,    -1,
     178,    -1,   177,    -1,   180,    -1,   182,    -1,   181,    -1,
     183,    -1,    63,   182,   218,   183,     6,    -1,    64,   182,
     221,   183,     6,    -1,   286,   212,   274,     6,    -1,     4,
     182,   183,   212,   274,     6,    -1,   285,   182,   183,   212,
     274,     6,    -1,     4,   182,   268,   183,   212,   268,     6,
      -1,     4,   180,   268,   181,   212,   268,     6,    -1,   285,
     182,   268,   183,   212,   268,     6,    -1,     4,   214,   187,
     277,   188,   215,   212,   274,     6,    -1,   285,   214,   187,
     277,   188,   215,   212,   274,     6,    -1,   286,   213,     6,
      -1,     4,   182,   268,   183,   213,     6,    -1,   285,   182,
     268,   183,   213,     6,    -1,   286,     7,   282,     6,    -1,
       4,   184,     4,     7,   282,     6,    -1,     4,   182,   268,
     183,   184,     4,     7,   282,     6,    -1,     4,   184,     4,
     212,   268,     6,    -1,     4,   182,   268,   183,   184,     4,
     212,   268,     6,    -1,     4,   184,     4,   213,     6,    -1,
       4,   182,   268,   183,   184,     4,   213,     6,    -1,     4,
     184,   130,   184,     4,     7,   278,     6,    -1,     4,   182,
     268,   183,   184,   130,   184,     4,     7,   278,     6,    -1,
       4,   184,   131,     7,   279,     6,    -1,     4,   182,   268,
     183,   184,   131,     7,   279,     6,    -1,     4,   139,     7,
     268,     6,    -1,   139,   182,   268,   183,     7,     4,     6,
      -1,   139,   182,   268,   183,   184,     4,     7,   268,     6,
      -1,   139,   182,   268,   183,   184,     4,     7,   282,     6,
      -1,   139,   182,   268,   183,   184,     4,     7,   187,   277,
     188,     6,    -1,   139,   182,   268,   183,   184,     4,     6,
      -1,    91,   180,     4,   181,   184,     4,     7,   268,     6,
      -1,    91,   180,     4,   181,   184,     4,     7,   282,     6,
      -1,    -1,   186,    -1,    -1,   218,   217,   286,    -1,   218,
     217,   286,     7,   268,    -1,    -1,   218,   217,   286,     7,
     187,   268,   219,   223,   188,    -1,   218,   217,   286,     7,
     282,    -1,    -1,   218,   217,   286,     7,   187,   282,   220,
     225,   188,    -1,    -1,   221,   217,   281,    -1,   268,     7,
     282,    -1,   222,   186,   268,     7,   282,    -1,    -1,   223,
     224,    -1,   186,     4,   274,    -1,   186,     4,   187,   222,
     188,    -1,   186,     4,   282,    -1,    -1,   225,   226,    -1,
     186,     4,   268,    -1,   186,     4,   282,    -1,   186,     4,
     187,   284,   188,    -1,   268,    -1,   282,    -1,   268,    -1,
     282,    -1,   268,    -1,   282,    -1,   268,    -1,   282,    -1,
      -1,   133,    71,   187,   268,   188,    -1,    -1,    83,   271,
      -1,    67,   180,   268,   181,     7,   271,     6,    -1,    87,
      67,   180,   227,   181,     7,   274,     6,    -1,    76,    77,
     274,     7,   268,     6,    -1,    70,   180,   268,   181,     7,
     274,     6,    -1,    92,    70,   274,     6,    -1,    74,   180,
     268,   181,     7,   274,     6,    -1,    68,   180,   268,   181,
       7,   274,   232,     6,    -1,    69,   180,   268,   181,     7,
     274,   232,     6,    -1,   125,   180,   268,   181,     7,   274,
       6,    -1,   126,   180,   268,   181,     7,   274,     6,    -1,
     127,   180,   268,   181,     7,   274,   129,   274,   128,   268,
       6,    -1,    70,     4,   180,   268,   181,     7,   274,     6,
      -1,    88,    70,   180,   268,   181,     7,   274,     6,    -1,
      87,    70,   180,   228,   181,     7,   274,     6,    -1,    83,
      73,   180,   268,   181,     7,   274,     6,    -1,    84,    73,
     180,   268,   181,     7,   274,   231,     6,    -1,    12,    13,
       6,    -1,    13,    73,   268,     6,    -1,    78,    73,   180,
     268,   181,     7,     5,     5,     5,     6,    -1,    71,   180,
     268,   181,     7,   274,     6,    -1,    72,   180,   268,   181,
       7,   274,     6,    -1,    73,     4,   180,   268,   181,     7,
     274,     6,    -1,    88,    73,   180,   268,   181,     7,   274,
       6,    -1,    88,    73,   180,   268,   181,     7,   274,     4,
     187,   273,   188,     6,    -1,    87,    73,   180,   229,   181,
       7,   274,     6,    -1,    86,    75,   180,   268,   181,     7,
     274,     6,    -1,    75,   180,   268,   181,     7,   274,     6,
      -1,    88,    75,   180,   268,   181,     7,   274,     6,    -1,
      87,    75,   180,   230,   181,     7,   274,     6,    -1,    95,
     271,   187,   235,   188,    -1,    94,   187,   271,   186,   271,
     186,   268,   188,   187,   235,   188,    -1,    96,   271,   187,
     235,   188,    -1,    97,   187,   271,   186,   268,   188,   187,
     235,   188,    -1,    97,   187,   271,   186,   271,   188,   187,
     235,   188,    -1,     4,   187,   235,   188,    -1,   105,    70,
     187,   277,   188,    73,   187,   268,   188,    -1,   102,    70,
     180,   268,   181,   187,   277,   188,     6,    -1,   236,    -1,
     234,    -1,    -1,   236,   233,    -1,   236,    67,   187,   277,
     188,     6,    -1,   236,    70,   187,   277,   188,     6,    -1,
     236,    73,   187,   277,   188,     6,    -1,   236,    75,   187,
     277,   188,     6,    -1,    99,    83,   180,   268,   181,     7,
     274,     6,    -1,    99,    67,   180,   268,   181,     7,   187,
     273,   188,     6,    -1,    99,    83,   180,   268,   181,     7,
     187,   271,   186,   271,   186,   277,   188,     6,    -1,    99,
      83,   180,   268,   181,     7,   187,   271,   186,   271,   186,
     271,   186,   277,   188,     6,    -1,    99,    71,   180,   268,
     181,     7,   187,   271,   186,   277,   188,     6,    -1,    99,
       4,   180,   268,   181,     7,   274,     6,    -1,    99,     4,
     180,   268,   181,     7,     5,     6,    -1,    99,     4,   187,
     268,   188,     6,    -1,    99,     4,   180,   268,   181,     7,
     187,   271,   186,   271,   186,   277,   188,     6,    -1,   103,
     187,   236,   188,    -1,   103,   139,   182,   268,   183,     6,
      -1,   103,     4,   182,   268,   183,     6,    -1,   103,     4,
       6,    -1,   103,     4,     4,     6,    -1,   130,   278,   187,
     236,   188,    -1,    93,   130,   278,   187,   236,   188,    -1,
     143,     5,     6,    -1,   144,     5,     6,    -1,   143,   187,
     236,   188,    -1,    93,   143,   187,   236,   188,    -1,   144,
     187,   236,   188,    -1,    93,   144,   187,   236,   188,    -1,
       4,   282,     6,    -1,    56,   180,   284,   181,     6,    -1,
       4,     4,   182,   268,   183,   281,     6,    -1,     4,     4,
       4,   182,   268,   183,     6,    -1,     4,   268,     6,    -1,
      91,   180,     4,   181,   184,     4,     6,    -1,   124,     4,
       6,    -1,   137,     6,    -1,   138,     6,    -1,    54,     6,
      -1,    49,     6,    -1,    49,   187,   268,   186,   268,   186,
     268,   186,   268,   186,   268,   186,   268,   188,     6,    -1,
      50,     6,    -1,    51,     6,    -1,    60,     6,    -1,    61,
       6,    -1,    80,     6,    -1,    81,   187,   277,   188,   187,
     277,   188,   187,   273,   188,   187,   268,   186,   268,   188,
       6,    -1,   151,   268,     6,    -1,   132,   180,   268,     8,
     268,   181,    -1,   132,   180,   268,     8,   268,     8,   268,
     181,    -1,   132,     4,   133,   187,   268,     8,   268,   188,
      -1,   132,     4,   133,   187,   268,     8,   268,     8,   268,
     188,    -1,   134,    -1,   142,     4,    -1,   140,    -1,   141,
     286,     6,    -1,   135,   180,   268,   181,    -1,   136,    -1,
      98,   271,   187,   236,   188,    -1,    98,   187,   271,   186,
     271,   186,   268,   188,   187,   236,   188,    -1,    98,   187,
     271,   186,   271,   186,   271,   186,   268,   188,   187,   236,
     188,    -1,    -1,    98,   271,   187,   236,   244,   257,   188,
      -1,    -1,    98,   187,   271,   186,   271,   186,   268,   188,
     187,   236,   245,   257,   188,    -1,    -1,    98,   187,   271,
     186,   271,   186,   271,   186,   268,   188,   187,   236,   246,
     257,   188,    -1,    -1,    98,   187,   236,   247,   257,   188,
      -1,    98,    67,   187,   268,   186,   271,   188,     6,    -1,
      98,    70,   187,   268,   186,   271,   188,     6,    -1,    98,
      73,   187,   268,   186,   271,   188,     6,    -1,    98,    67,
     187,   268,   186,   271,   186,   271,   186,   268,   188,     6,
      -1,    98,    70,   187,   268,   186,   271,   186,   271,   186,
     268,   188,     6,    -1,    98,    73,   187,   268,   186,   271,
     186,   271,   186,   268,   188,     6,    -1,    98,    67,   187,
     268,   186,   271,   186,   271,   186,   271,   186,   268,   188,
       6,    -1,    98,    70,   187,   268,   186,   271,   186,   271,
     186,   271,   186,   268,   188,     6,    -1,    98,    73,   187,
     268,   186,   271,   186,   271,   186,   271,   186,   268,   188,
       6,    -1,    -1,    98,    67,   187,   268,   186,   271,   188,
     248,   187,   257,   188,     6,    -1,    -1,    98,    70,   187,
     268,   186,   271,   188,   249,   187,   257,   188,     6,    -1,
      -1,    98,    73,   187,   268,   186,   271,   188,   250,   187,
     257,   188,     6,    -1,    -1,    98,    67,   187,   268,   186,
     271,   186,   271,   186,   268,   188,   251,   187,   257,   188,
       6,    -1,    -1,    98,    70,   187,   268,   186,   271,   186,
     271,   186,   268,   188,   252,   187,   257,   188,     6,    -1,
      -1,    98,    73,   187,   268,   186,   271,   186,   271,   186,
     268,   188,   253,   187,   257,   188,     6,    -1,    -1,    98,
      67,   187,   268,   186,   271,   186,   271,   186,   271,   186,
     268,   188,   254,   187,   257,   188,     6,    -1,    -1,    98,
      70,   187,   268,   186,   271,   186,   271,   186,   271,   186,
     268,   188,   255,   187,   257,   188,     6,    -1,    -1,    98,
      73,   187,   268,   186,   271,   186,   271,   186,   271,   186,
     268,   188,   256,   187,   257,   188,     6,    -1,   258,    -1,
     257,   258,    -1,   108,   187,   268,   188,     6,    -1,   108,
     187,   274,   186,   274,   188,     6,    -1,   108,   187,   274,
     186,   274,   186,   274,   188,     6,    -1,   109,     6,    -1,
     100,     6,    -1,   116,     6,    -1,   116,   118,     6,    -1,
     117,     6,    -1,   117,   118,     6,    -1,   114,     6,    -1,
     114,   118,     6,    -1,   115,     6,    -1,   115,   118,     6,
      -1,   110,   180,   268,   181,     7,   274,    90,   268,     6,
      -1,    90,     4,   182,   268,   183,     6,    -1,    -1,    90,
       4,   268,    -1,    -1,     4,    -1,    -1,     7,   274,    -1,
      -1,     7,   268,    -1,    -1,    90,   274,    -1,    85,    70,
     275,     7,   268,   259,     6,    -1,    85,    73,   275,   261,
     260,     6,    -1,    79,    73,   187,   268,   188,     7,   274,
       6,    -1,    85,    75,   275,   261,     6,    -1,   119,   275,
       6,    -1,   106,    73,   187,   277,   188,   268,     6,    -1,
     100,    73,   275,   262,     6,    -1,   100,    75,   275,     6,
      -1,   101,    73,   274,     7,   268,     6,    -1,    89,    70,
     274,     7,   274,     6,    -1,    89,    73,   268,   187,   277,
     188,     7,   268,   187,   277,   188,   263,     6,    -1,    67,
     187,   277,   188,   133,    73,   187,   268,   188,     6,    -1,
      70,   187,   277,   188,   133,    73,   187,   268,   188,     6,
      -1,    67,   187,   277,   188,   133,    75,   187,   268,   188,
       6,    -1,    70,   187,   277,   188,   133,    75,   187,   268,
     188,     6,    -1,    73,   187,   277,   188,   133,    75,   187,
     268,   188,     6,    -1,   107,    73,   275,     6,    -1,   107,
      70,   275,     6,    -1,    82,    67,   275,     6,    -1,    82,
      70,   275,     6,    -1,    82,    73,   275,     6,    -1,   104,
       6,    -1,   104,     4,     6,    -1,   104,    67,   187,   277,
     188,     6,    -1,   148,    -1,   149,    -1,   150,    -1,   266,
       6,    -1,   266,   187,   274,   188,     6,    -1,   266,   187,
     274,   186,   274,   188,     6,    -1,   266,   180,   274,   181,
     187,   274,   186,   274,   188,     6,    -1,   269,    -1,   180,
     268,   181,    -1,   171,   268,    -1,   170,   268,    -1,   175,
     268,    -1,   268,   171,   268,    -1,   268,   170,   268,    -1,
     268,   172,   268,    -1,   268,   173,   268,    -1,   268,   174,
     268,    -1,   268,   179,   268,    -1,   268,   166,   268,    -1,
     268,   167,   268,    -1,   268,   169,   268,    -1,   268,   168,
     268,    -1,   268,   165,   268,    -1,   268,   164,   268,    -1,
     268,   163,   268,    -1,   268,   162,   268,    -1,   268,   161,
     268,     8,   268,    -1,    14,   214,   268,   215,    -1,    15,
     214,   268,   215,    -1,    16,   214,   268,   215,    -1,    17,
     214,   268,   215,    -1,    18,   214,   268,   215,    -1,    19,
     214,   268,   215,    -1,    20,   214,   268,   215,    -1,    21,
     214,   268,   215,    -1,    22,   214,   268,   215,    -1,    24,
     214,   268,   215,    -1,    25,   214,   268,   186,   268,   215,
      -1,    26,   214,   268,   215,    -1,    27,   214,   268,   215,
      -1,    28,   214,   268,   215,    -1,    29,   214,   268,   215,
      -1,    30,   214,   268,   215,    -1,    31,   214,   268,   215,
      -1,    32,   214,   268,   215,    -1,    33,   214,   268,   186,
     268,   215,    -1,    34,   214,   268,   186,   268,   215,    -1,
      35,   214,   268,   186,   268,   215,    -1,    23,   214,   268,
     215,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
     154,    -1,   155,    -1,   156,    -1,    57,    -1,    58,    -1,
      59,    -1,    -1,    65,   214,   268,   270,   223,   215,    -1,
     286,    -1,     4,   182,   268,   183,    -1,   285,   182,   268,
     183,    -1,   152,   180,   286,   181,    -1,   153,   180,   282,
     181,    -1,   185,   286,   182,   183,    -1,   286,   213,    -1,
       4,   182,   268,   183,   213,    -1,   285,   182,   268,   183,
     213,    -1,     4,   184,     4,    -1,     4,   182,   268,   183,
     184,     4,    -1,     4,   184,     4,   213,    -1,     4,   182,
     268,   183,   184,     4,   213,    -1,   145,   180,   281,   186,
     268,   181,    -1,    45,   180,   281,   186,   281,   181,    -1,
      46,   180,   281,   186,   281,   181,    -1,    48,   180,   284,
     181,    -1,   272,    -1,   171,   271,    -1,   170,   271,    -1,
     271,   171,   271,    -1,   271,   170,   271,    -1,   187,   268,
     186,   268,   186,   268,   186,   268,   186,   268,   188,    -1,
     187,   268,   186,   268,   186,   268,   186,   268,   188,    -1,
     187,   268,   186,   268,   186,   268,   188,    -1,   180,   268,
     186,   268,   186,   268,   181,    -1,   274,    -1,   273,   186,
     274,    -1,   268,    -1,   276,    -1,   187,   188,    -1,   187,
     277,   188,    -1,   171,   187,   277,   188,    -1,   268,   172,
     187,   277,   188,    -1,   274,    -1,     5,    -1,   171,   276,
      -1,   268,   172,   276,    -1,   268,     8,   268,    -1,   268,
       8,   268,     8,   268,    -1,    67,   187,   268,   188,    -1,
      67,     5,    -1,    70,     5,    -1,    73,     5,    -1,    75,
       5,    -1,    87,    67,     5,    -1,    87,    70,     5,    -1,
      87,    73,     5,    -1,    87,    75,     5,    -1,    87,    67,
     187,   277,   188,    -1,    87,    70,   187,   277,   188,    -1,
      87,    73,   187,   277,   188,    -1,    87,    75,   187,   277,
     188,    -1,    67,   133,    49,   187,   268,   186,   268,   186,
     268,   186,   268,   186,   268,   186,   268,   188,    -1,    70,
     133,    49,   187,   268,   186,   268,   186,   268,   186,   268,
     186,   268,   186,   268,   188,    -1,    73,   133,    49,   187,
     268,   186,   268,   186,   268,   186,   268,   186,   268,   186,
     268,   188,    -1,    75,   133,    49,   187,   268,   186,   268,
     186,   268,   186,   268,   186,   268,   186,   268,   188,    -1,
     234,    -1,   243,    -1,     4,   214,   215,    -1,   285,   214,
     215,    -1,    36,   182,   286,   183,    -1,     4,   214,   187,
     277,   188,   215,    -1,   285,   214,   187,   277,   188,   215,
      -1,   268,    -1,   276,    -1,   277,   186,   268,    -1,   277,
     186,   276,    -1,   187,   268,   186,   268,   186,   268,   186,
     268,   188,    -1,   187,   268,   186,   268,   186,   268,   188,
      -1,     4,    -1,     4,   184,   130,   184,     4,    -1,   187,
     280,   188,    -1,     4,   182,   268,   183,   184,   131,    -1,
     278,    -1,   280,   186,   278,    -1,   282,    -1,   286,    -1,
       4,   184,     4,    -1,     4,   182,   268,   183,   184,     4,
      -1,     5,    -1,    52,    -1,    55,    -1,   146,   180,   281,
     181,    -1,   147,   180,   281,   186,   281,   181,    -1,    41,
     214,   284,   215,    -1,    42,   180,   281,   181,    -1,    43,
     180,   281,   181,    -1,    44,   180,   281,   186,   281,   186,
     281,   181,    -1,    39,   214,   284,   215,    -1,    47,   214,
     268,   186,   282,   186,   282,   215,    -1,    40,   214,   281,
     215,    -1,    40,   214,   281,   186,   277,   215,    -1,    53,
     214,   281,   215,    -1,    -1,    66,   214,   282,   283,   225,
     215,    -1,   281,    -1,   284,   186,   281,    -1,     4,   189,
     187,   268,   188,    -1,   285,   189,   187,   268,   188,    -1,
       4,    -1,   285,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   189,   191,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   213,   217,   224,   229,   234,   248,   261,   274,   302,
     316,   329,   342,   361,   366,   367,   368,   369,   370,   374,
     376,   381,   383,   389,   493,   388,   511,   518,   529,   528,
     546,   553,   564,   563,   580,   597,   620,   619,   633,   634,
     635,   636,   637,   641,   642,   648,   648,   649,   649,   655,
     656,   657,   718,   747,   776,   781,   786,   791,   798,   805,
     820,   825,   830,   839,   845,   854,   872,   890,   899,   911,
     916,   924,   944,   967,   978,   986,  1008,  1031,  1057,  1078,
    1090,  1104,  1104,  1106,  1108,  1117,  1127,  1126,  1138,  1148,
    1147,  1161,  1163,  1171,  1177,  1184,  1185,  1189,  1200,  1215,
    1225,  1226,  1231,  1239,  1248,  1266,  1270,  1279,  1283,  1292,
    1296,  1305,  1309,  1319,  1322,  1335,  1338,  1348,  1371,  1387,
    1410,  1428,  1449,  1467,  1497,  1527,  1545,  1563,  1590,  1608,
    1626,  1645,  1663,  1702,  1708,  1714,  1721,  1746,  1771,  1788,
    1807,  1841,  1861,  1879,  1896,  1912,  1933,  1938,  1943,  1948,
    1953,  1958,  1981,  1987,  1998,  1999,  2004,  2007,  2011,  2034,
    2057,  2080,  2108,  2129,  2155,  2176,  2198,  2218,  2330,  2349,
    2387,  2496,  2505,  2511,  2526,  2554,  2571,  2580,  2594,  2600,
    2606,  2615,  2624,  2633,  2647,  2703,  2721,  2738,  2753,  2772,
    2784,  2808,  2812,  2817,  2824,  2830,  2835,  2841,  2849,  2853,
    2857,  2862,  2917,  2930,  2947,  2964,  2985,  3006,  3041,  3049,
    3055,  3062,  3066,  3075,  3083,  3091,  3100,  3099,  3114,  3113,
    3128,  3127,  3142,  3141,  3155,  3162,  3169,  3176,  3183,  3190,
    3197,  3204,  3211,  3219,  3218,  3232,  3231,  3245,  3244,  3258,
    3257,  3271,  3270,  3284,  3283,  3297,  3296,  3310,  3309,  3323,
    3322,  3339,  3342,  3348,  3360,  3380,  3404,  3408,  3412,  3416,
    3420,  3426,  3432,  3436,  3440,  3444,  3448,  3467,  3480,  3483,
    3499,  3502,  3519,  3522,  3528,  3531,  3538,  3541,  3548,  3604,
    3674,  3679,  3746,  3782,  3790,  3833,  3872,  3892,  3919,  3968,
    3996,  4024,  4028,  4032,  4060,  4099,  4138,  4159,  4180,  4207,
    4211,  4221,  4256,  4257,  4258,  4262,  4268,  4280,  4298,  4326,
    4327,  4328,  4329,  4330,  4331,  4332,  4333,  4334,  4341,  4342,
    4343,  4344,  4345,  4346,  4347,  4348,  4349,  4350,  4351,  4352,
    4353,  4354,  4355,  4356,  4357,  4358,  4359,  4360,  4361,  4362,
    4363,  4364,  4365,  4366,  4367,  4368,  4369,  4370,  4371,  4372,
    4373,  4382,  4383,  4384,  4385,  4386,  4387,  4388,  4389,  4390,
    4391,  4396,  4395,  4403,  4420,  4438,  4456,  4461,  4467,  4479,
    4496,  4514,  4535,  4540,  4545,  4555,  4565,  4570,  4579,  4584,
    4611,  4615,  4619,  4623,  4627,  4634,  4638,  4642,  4646,  4653,
    4658,  4665,  4670,  4674,  4679,  4683,  4691,  4702,  4706,  4718,
    4726,  4734,  4741,  4751,  4780,  4784,  4788,  4792,  4796,  4800,
    4804,  4808,  4812,  4841,  4870,  4899,  4928,  4941,  4954,  4967,
    4980,  4990,  5000,  5012,  5024,  5036,  5054,  5075,  5080,  5084,
    5088,  5100,  5104,  5116,  5123,  5133,  5137,  5152,  5157,  5164,
    5168,  5181,  5189,  5200,  5204,  5212,  5218,  5226,  5234,  5249,
    5263,  5277,  5289,  5305,  5316,  5320,  5339,  5347,  5346,  5359,
    5364,  5370,  5379,  5392,  5395
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tExp", "tLog", "tLog10", "tSqrt", "tSin", "tAsin",
  "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh", "tCosh",
  "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod", "tModulo",
  "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tStrFind", "tStrCmp",
  "tStrChoice", "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged",
  "tToday", "tFixRelativePath", "tSyncModel", "tOnelabAction",
  "tOnelabRun", "tCpu", "tMemory", "tTotalMemory", "tCreateTopology",
  "tCreateTopologyNoHoles", "tDistanceFunction", "tDefineConstant",
  "tUndefineConstant", "tDefineNumber", "tDefineString", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tPlane",
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast",
  "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tAFFECTDIVIDE",
  "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", "tOR", "tAND",
  "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL", "tLESSOREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
  "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "$@1", "$@2", "Text2DValues", "Text2D",
  "$@3", "Text3DValues", "Text3D", "$@4", "InterpolationMatrix", "Time",
  "$@5", "NumericAffectation", "NumericIncrement", "LP", "RP",
  "Affectation", "Comma", "DefineConstants", "$@6", "$@7",
  "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId0", "PhysicalId1", "PhysicalId2", "PhysicalId3",
  "InSphereCenter", "CircleOptions", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "Visibility",
  "Command", "Loop", "Extrude", "$@8", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "$@21", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@22",
  "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULL
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,    63,   416,   417,   418,   419,    60,    62,   420,   421,
      43,    45,    42,    47,    37,    33,   422,   423,   424,    94,
      40,    41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   190,   191,   191,   192,   192,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   194,   194,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   196,   197,   197,   197,   197,   197,   197,   198,
     198,   199,   199,   201,   202,   200,   203,   203,   205,   204,
     206,   206,   208,   207,   209,   209,   211,   210,   212,   212,
     212,   212,   212,   213,   213,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   217,   217,   218,   218,   218,   219,   218,   218,   220,
     218,   221,   221,   222,   222,   223,   223,   224,   224,   224,
     225,   225,   226,   226,   226,   227,   227,   228,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   234,   234,   234,   234,
     234,   234,   234,   234,   235,   235,   236,   236,   236,   236,
     236,   236,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   238,   238,   238,   238,   238,   239,   239,   240,   240,
     240,   240,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   244,   243,   245,   243,
     246,   243,   247,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   248,   243,   249,   243,   250,   243,   251,
     243,   252,   243,   253,   243,   254,   243,   255,   243,   256,
     243,   257,   257,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   261,   261,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   265,
     265,   265,   266,   266,   266,   267,   267,   267,   267,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   270,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     271,   271,   271,   271,   271,   272,   272,   272,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   277,   277,   277,
     277,   278,   278,   278,   278,   279,   279,   280,   280,   281,
     281,   281,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   283,   282,   284,
     284,   285,   285,   286,   286
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     5,     7,     7,     7,     9,     6,
       6,     6,     8,     0,     2,     2,     2,     2,     2,     1,
       3,     1,     3,     0,     0,    10,     1,     3,     0,    13,
       1,     3,     0,    15,     8,    14,     0,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     6,     6,     7,     7,     7,     9,     9,     3,
       6,     6,     4,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     9,     9,    11,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     5,     0,
       9,     0,     3,     3,     5,     0,     2,     3,     5,     3,
       0,     2,     3,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     0,     2,     7,     8,     6,
       7,     4,     7,     8,     8,     7,     7,    11,     8,     8,
       8,     8,     9,     3,     4,    10,     7,     7,     8,     8,
      12,     8,     8,     7,     8,     8,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     6,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,    15,     2,     2,     2,     2,
       2,    16,     3,     6,     8,     8,    10,     1,     2,     1,
       3,     4,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     7,     6,
       8,     5,     3,     7,     5,     4,     6,     6,    13,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     4,     4,     4,     4,     2,
       5,     5,     3,     6,     4,     7,     6,     6,     6,     4,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     1,     1,     2,
       3,     3,     5,     4,     2,     2,     2,     2,     3,     3,
       3,     3,     5,     5,     5,     5,    16,    16,    16,    16,
       1,     1,     3,     3,     4,     6,     6,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     3,     6,     1,     1,     1,     4,     6,     4,     4,
       4,     8,     4,     8,     4,     6,     4,     0,     6,     1,
       3,     5,     5,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   232,     0,     0,     0,   229,     0,     0,     0,     0,
     322,   323,   324,     0,     5,     7,     6,     8,     9,    10,
      19,    11,    12,    13,    18,    17,    14,    15,    16,     0,
      20,   484,     0,   371,   483,   463,   372,   373,   374,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,   465,   378,   379,   380,     0,     0,     0,
       0,     0,     0,     0,     0,   375,   376,   377,     0,     0,
       0,    65,    66,     0,     0,   176,     0,     0,     0,   329,
       0,   459,   484,   383,     0,     0,     0,     0,   214,     0,
     216,   217,   213,     0,   218,   219,   103,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   400,     0,     0,     0,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   319,     0,     0,     0,     0,
       0,     0,     0,     0,   483,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,   441,   411,   417,     0,
     412,   484,   383,     0,     0,     0,     0,   453,     0,     0,
       0,     0,     0,   211,   212,     0,   483,   484,     0,   228,
       0,   176,     0,   176,   483,     0,   325,     0,     0,    65,
      66,     0,     0,    58,    62,    61,    60,    59,    64,    63,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,   331,   333,
       0,     0,     0,     0,     0,     0,     0,     0,   175,     0,
     174,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
     204,     0,   389,   153,     0,   483,     0,   459,   460,     0,
       0,   479,     0,   101,   101,     0,     0,   447,   448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   292,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   176,     0,   402,
     401,     0,     0,     0,     0,   176,   176,     0,     0,     0,
       0,     0,     0,     0,   242,     0,   176,     0,     0,     0,
       0,     0,   294,     0,     0,     0,     0,   194,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     0,   424,     0,     0,   425,     0,   426,
       0,   427,     0,     0,     0,     0,     0,     0,   331,   419,
       0,   413,     0,     0,     0,   302,    66,     0,   210,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,   230,
     198,     0,   199,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,   477,     0,     0,     0,     0,     0,     0,   330,
      58,     0,     0,    58,     0,     0,     0,     0,     0,   171,
       0,     0,     0,     0,   177,     0,     0,     0,   347,   346,
     345,   344,   340,   341,   343,   342,   335,   334,   336,   337,
     338,   339,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,   317,
     318,     0,     0,     0,     0,   290,     0,     0,     0,   125,
     126,     0,   127,   128,     0,   129,   130,     0,   131,   132,
       0,     0,     0,     0,     0,     0,   141,   176,     0,     0,
       0,     0,     0,   404,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,     0,     0,
       0,     0,   305,     0,     0,   195,     0,     0,   191,     0,
       0,     0,   315,   314,     0,     0,     0,     0,   392,    67,
      68,     0,   442,     0,     0,     0,     0,     0,     0,   428,
       0,   429,     0,   430,     0,   431,     0,     0,   330,   414,
     421,     0,   336,   420,     0,   443,     0,     0,     0,     0,
       0,     0,     0,     0,   231,     0,   200,   202,     0,     0,
       0,     0,     0,     0,     0,    82,    71,     0,   384,   394,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   370,
     358,     0,   360,   361,   362,   363,   364,   365,   366,     0,
       0,     0,   472,     0,   474,   468,   469,   470,     0,     0,
       0,     0,   399,   476,   115,   120,    93,     0,   466,     0,
     386,   387,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,   388,     0,     0,     0,     0,   481,
       0,     0,    43,     0,     0,     0,    56,     0,    34,    35,
      36,    37,    38,   385,     0,   461,    23,    21,     0,     0,
      24,     0,     0,   205,   480,    69,   104,    70,   112,     0,
     449,   450,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   293,   291,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   203,     0,
       0,     0,   166,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,   233,     0,     0,     0,     0,     0,     0,   295,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,     0,   444,     0,   423,     0,     0,     0,     0,     0,
       0,     0,   415,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,     0,   326,     0,
       0,     0,   482,     0,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,    80,    83,    85,
       0,     0,   457,     0,    91,     0,     0,     0,     0,     0,
     348,     0,     0,     0,     0,     0,    29,   391,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,   307,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,   276,     0,   282,     0,   284,     0,   278,     0,
     280,     0,   243,   272,     0,     0,     0,   189,     0,     0,
       0,   306,     0,   193,   192,   321,     0,     0,    30,    31,
       0,     0,     0,     0,     0,     0,     0,   432,   433,   434,
     435,   422,   416,     0,     0,     0,     0,   454,     0,     0,
       0,   223,     0,     0,     0,     0,    73,     0,    81,     0,
     207,   393,   206,   359,   367,   368,   369,   475,     0,   397,
     398,     0,     0,   382,   116,     0,   478,   121,   396,   467,
      75,    58,     0,     0,     0,     0,    74,     0,     0,     0,
     455,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,     0,     0,    25,    26,     0,    27,     0,     0,   105,
     108,   137,     0,     0,     0,     0,     0,     0,   140,     0,
       0,   156,   157,     0,     0,   142,   163,     0,     0,     0,
       0,   133,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,     0,     0,   176,   176,
       0,   253,     0,   255,     0,   257,     0,   411,     0,     0,
     283,   285,   279,   281,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     0,   393,   445,
       0,     0,     0,     0,   446,   145,   146,     0,     0,     0,
       0,    94,    98,     0,     0,   327,    76,     0,   395,     0,
       0,     0,     0,     0,     0,    88,     0,     0,    89,     0,
     458,   178,   179,   180,   181,     0,     0,    39,     0,     0,
       0,     0,     0,    41,   462,     0,     0,   106,   109,     0,
       0,   136,   143,   144,   148,     0,     0,   158,     0,     0,
     300,     0,   151,     0,     0,   289,   162,   138,   150,   161,
     165,   149,     0,   159,   164,     0,     0,     0,     0,   408,
       0,   407,     0,     0,     0,   244,     0,     0,   245,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,   188,
       0,     0,   187,     0,     0,     0,   182,     0,     0,    32,
       0,     0,     0,     0,     0,     0,   452,     0,   225,   224,
       0,     0,     0,     0,     0,   471,   473,     0,   117,   119,
       0,   122,   123,    84,    86,     0,    92,     0,    77,    44,
       0,     0,     0,   410,     0,     0,     0,    28,     0,   115,
     120,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,    99,   100,   176,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,   273,     0,     0,   176,     0,
       0,     0,     0,     0,   173,   172,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,     0,    78,     0,   447,
       0,     0,   456,     0,    40,     0,     0,     0,    42,    57,
       0,     0,     0,   309,   311,   310,   312,   313,   155,     0,
       0,     0,     0,     0,     0,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,   238,
       0,     0,   183,     0,     0,     0,     0,     0,     0,     0,
     451,   226,     0,   328,     0,   118,     0,   124,    90,     0,
       0,     0,     0,     0,   107,   110,     0,     0,     0,   296,
     167,     0,   259,     0,     0,   261,     0,     0,   263,     0,
       0,     0,   274,     0,   234,     0,   176,     0,     0,     0,
       0,     0,     0,     0,   147,    97,     0,   113,     0,    48,
       0,    54,     0,     0,     0,   134,   160,     0,     0,   405,
     247,     0,     0,   254,   248,     0,     0,   256,   249,     0,
       0,   258,     0,     0,     0,   240,     0,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,   308,     0,   265,     0,   267,     0,   269,   275,
     286,   239,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   114,    45,     0,    52,     0,     0,     0,     0,   250,
       0,     0,   251,     0,     0,   252,     0,     0,   190,     0,
     184,     0,     0,     0,     0,     0,    46,     0,     0,   215,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   221,   260,     0,
     262,     0,   264,     0,   185,     0,     0,     0,     0,    47,
      49,     0,    50,     0,     0,     0,     0,   436,   437,   438,
     439,     0,     0,    55,   266,   268,   270,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    84,   868,    85,    86,   632,  1306,  1312,
     858,  1031,  1473,  1655,   859,  1606,  1691,   860,  1657,   861,
     862,  1035,   320,   402,   167,   742,    87,   646,   413,  1419,
    1420,   414,  1468,  1007,  1164,  1008,  1167,   678,   681,   684,
     687,  1334,  1205,   614,   275,   379,   380,    90,    91,    92,
      93,    94,    95,   276,   942,  1555,  1623,   712,  1356,  1359,
    1362,  1581,  1585,  1589,  1640,  1643,  1646,   938,   939,  1067,
     903,   675,   721,  1578,    97,    98,    99,   100,   277,   169,
     824,   460,   235,  1189,   278,   279,   280,   522,   289,   843,
    1023,   411,   407,   825,   412,   172,   282
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1250
static const yytype_int16 yypact[] =
{
    5908,    75,    26,  6024, -1250, -1250,  3187,    34,    71,   -66,
     -61,    42,   156,   178,   245,    82,   261,   293,   136,   171,
    -116,   110,   159,     3,   188,   194,    19,   198,   222,   330,
     361,   401,   454,   366,   535,   414,   477,   396,   496,   345,
     479,   -36,   424,   603,   -22,   452,   -64,   -64,   481,   297,
     239,    85,   601,   615,    14,    16,   627,   606,   168,   701,
     706,   714,  3919,   720,   529,   551,   583,    27,    -1, -1250,
     597, -1250,   742,   777,   617, -1250,   783,   790,     9,    30,
   -1250, -1250, -1250,  5762, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,    43,
   -1250,  -128,   106, -1250,     5, -1250, -1250, -1250, -1250,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   622,   629,   645,   660,   671,   -91,
     679, -1250,   -91, -1250, -1250, -1250, -1250,   -91,   -91,   806,
     683,   702,   707,   708,   716, -1250, -1250, -1250,  5762,  5762,
    5762,  5762,  2348,    15,   783,   309,   717,   743,   459, -1250,
     748,   894,   -72,  -121,   930,  5762,  1107,  1107, -1250,  5762,
   -1250, -1250, -1250,  1107, -1250, -1250, -1250, -1250,  5762,  5537,
    5762,  5762,   759,  5762,  5537,  5762,  5762,   773,  5537,  5762,
    5762,  4578,   792,   770, -1250,  5537,  3919,  3919,  3919,   802,
     841,  3919,  3919,  3919,   846,   849,   850,   852,   853,   854,
     855,   856,  4578,  5762,  1034,  4578,    27,   859,   862,   -64,
     -64,   -64,  5762,  5762,   -94, -1250,   -75,   -64,   865,   867,
     868,  3120,   -67,   221,   860,   877,   878,  3919,  3919,  4578,
     880,    49,   881, -1250,  1036, -1250,   887,   888,   889,  3919,
    3919,   882,   883,   895,   462, -1250,   896,    37,    31,    80,
     104,   426,  4757,  5762,  3554, -1250, -1250,  2925, -1250,  1079,
   -1250,    98,   108,  1080,  5762,  5762,  5762,   906,  5762,   904,
     961,  5762,  5762, -1250, -1250,  5762,   907,   908,  1092, -1250,
    1093, -1250,  1095, -1250,   -30,   491, -1250,  4578,  4578, -1250,
    5710,   915,   918,  1156, -1250, -1250, -1250, -1250, -1250, -1250,
    4578,  1102,   928,  5762,  1109, -1250,  5762,  5762,  5762,  5762,
    5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762,
    5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762,  1107,  1107,
    1107,  1107,  1107,  1107,  1107,  1107,  5762,  1107,  1107,  5762,
    1156,  5762,  1107,  1107,  1107,   783,  1156,   936,   936,   936,
    8443,    18,  8098,   117,   932,  1111,   937,   933, -1250,   938,
    4796,  5762,  5537, -1250,  5762,  5762,  5762,  5762,  5762,  5762,
    5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762,  5762, -1250,
   -1250,  5762, -1250, -1250,   705,   291,    61, -1250, -1250,   157,
    6879, -1250,   196,   -86,   -68,  8464,  5537,  3148, -1250,   128,
    8485,  8506,  5762,  8527,   300,  8548,  8569,  5762,   331,  8590,
    8611,  1114,  5762,  5762,   384,  1119,  1121,  1130,  5762,  5762,
    1131,  1132,  1132,  5762,  5473,  5473,  5473,  5473,  5762,  5762,
    5762,  1134,  6799,   956,  1136,   957, -1250, -1250,   121, -1250,
   -1250,  6905,  6931,   -64,   -64,   309,   309,   126,  5762,  5762,
    5762,  3120,  3120,  5762,  4796,   170, -1250,  5762,  5762,  5762,
    5762,  5762,  1138,  1137,  1145,  5762,  1147, -1250,  5762,  5762,
    1263, -1250,  5537,  5537,  5537,  1152,  1157,  5762,  5762,  5762,
    5762,  1160,   182,   783, -1250,  1116,  5762, -1250,  1117, -1250,
    1120, -1250,  1122,    38,    39,    40,    41,  5537,   936, -1250,
    8632, -1250,   409,  5762,  4936, -1250,  5762,   358, -1250,  8653,
    8674,  8695,  1038,  6957, -1250,   983,  3499,  8716,  8121, -1250,
   -1250,  1391, -1250,  1517,  5762, -1250,   991,   507,    18,  8144,
    5762,  5537,  1168,  1169, -1250,  5762,  8167,    81,  8075,  8075,
    8075,  8075,  8075,  8075,  8075,  8075,  8075,  8075,  8075,  6983,
    8075,  8075,  8075,  8075,  8075,  8075,  8075,  7009,  7035,  7061,
     494,   501,   494,   995,   997,   993,   994,   999,  7087,   235,
     546,  9157, -1250,   744,  1002,  1008,  1004,  1010,  1013,    18,
   -1250,  4578,    95,  1156,  5762,  1177,  1197,    28,  1022, -1250,
     325,    20,    29,   326, -1250,  4368,   549,  3523,  1731,  2790,
     662,   662,   440,   440,   440,   440,   270,   270,   936,   936,
     936,   936,    46,  8190, -1250,  5762,  1203,    21,  5537,  1204,
    5537,  5762,  1207,  1107,  1208, -1250,   783,  1209,  1107,  1212,
    5537,  5537,  1083,  1213,  1214,  8737,  1218,  1099,  1219,  1227,
    8758,  1105,  1228,  1232,  5762,  8779,  5498,  1057, -1250, -1250,
   -1250,  8800,  8821,  5762,  4578,  1241,  1240,  8842,  1070,  9157,
   -1250,  1081,  9157, -1250,  1082,  9157, -1250,  1084,  9157, -1250,
    8863,  8884,  8905,  4578,  5537,  1076, -1250, -1250,  2014,  2472,
     -64,  5762,  5762, -1250, -1250,  1073,  1078,  3120,  7113,  7139,
    7165,  6853,   598,   -64,  2765,  8926,  5668,  8947,  8968,  8989,
    5762,  1258, -1250,  5762,  9010, -1250,  8213,  8236, -1250,   554,
     558,   568, -1250, -1250,  8259,  8282,  7191,  8305,   108, -1250,
   -1250,  5537, -1250,  1086,  1085,  6015,  1090,  1091,  1096, -1250,
    5537, -1250,  5537, -1250,  5537, -1250,  5537,   569, -1250, -1250,
    4126,  5537,   936, -1250,  5537, -1250,  1260,  1264,  1266,  1098,
    5762,  3413,  5762,  5762, -1250,    51, -1250, -1250,  1100,  4578,
    1273,  4578,   143,  6043,   574, -1250, -1250,  8328,  1040, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250,  5762, -1250, -1250, -1250, -1250, -1250, -1250, -1250,  5762,
    5762,  5762, -1250,  5537, -1250, -1250, -1250, -1250,  1107,  1107,
    1107,  1156, -1250, -1250, -1250, -1250, -1250,  5762, -1250,  1107,
   -1250, -1250,  5762,  1274,    25,  5762,  1279,  1284,   797, -1250,
    1286,  1088,    27,  1285, -1250,  5537,  5537,  5537,  5537, -1250,
     546,  5762, -1250,  1115,  1124,  1112, -1250,  1294, -1250, -1250,
   -1250, -1250, -1250,   108,  8351, -1250, -1250,  1139,  1107,   420,
   -1250,   455,  7217, -1250, -1250, -1250,  1298, -1250, -1250,   -64,
    3148, -1250,   659,  4578,  4578,  1301,  4578,   691,  4578,  4578,
    1302,  1226,  4578,  4578,  1252,  1304,  1305,  5537,  1308,  1309,
    2906, -1250, -1250,  1311, -1250,  1312,  1315,  1316,  1317,  1318,
    1319,  1320,  1322,  1334,   581,  1314,  3791, -1250, -1250,   187,
    7243,  7269, -1250, -1250,  6071,   -83,   -64,   -64,   -64,  1338,
    1337,  1158,  1342,  1164,    33,    54,    64,   130,  1014, -1250,
     205, -1250,   598,  1345,  1347,  1349,  1350,  1352,  9157, -1250,
    1588,  1167,  1354,  1355,  1357,  1291,  5762,  1359,  1360,  5762,
     131,   582, -1250,  5762, -1250,  5762,  5762,  5762,   586,   596,
     604,   605, -1250,  5762,   609,   612,  4578,  4578,  4578,  1365,
    7295, -1250,  4305,   163,  1366,  1367,  4578,  1184, -1250,  1368,
    5762,  1373, -1250,   546,  1374,  1377, -1250,  1380,  8075,  8075,
    8075,  8075,   518,  1205,  1211,  1215,  1216,   536,   542,  9031,
    1217,  1627, -1250,   281,  1221,  1386,  1693, -1250, -1250, -1250,
      27,  5762, -1250,   619, -1250,   620,   626,   632,   633,    18,
    9157,  1220,  5762,  5762,  4578,  1222, -1250, -1250,  1223, -1250,
    1389,    66,  1395,  5762,  4098,    22,  1225,  1243,  1323,  1323,
    4578,  1402,  1246,  1247,  1404,  1430,  4578,  1250,  1432,  1433,
   -1250,  1435,  4578,   636,  4578,  4578,  1437,  1436, -1250,  4578,
    4578,  4578,  4578,  4578,  4578,  4578,  4578, -1250,  1438,   504,
   -1250,  5762,  5762,  5762,  1256,  1259,  -108,  -102,   -96,  1265,
   -1250,  4578, -1250,  5762, -1250,  1442, -1250,  1444, -1250,  1446,
   -1250,  1447, -1250, -1250,  3120,  1133,  4162, -1250,  1267,  1270,
    5115, -1250,  5537, -1250, -1250, -1250,  1281,  1947, -1250, -1250,
    8374,  1451,   546,  7321,  7347,  7373,  7399, -1250, -1250, -1250,
   -1250,  9157, -1250,   546,  1464,  1465,  1343, -1250,  5762,  5762,
    5762, -1250,  1467,   557,  1295,  1474, -1250,  2006, -1250,    18,
   -1250,    83, -1250, -1250, -1250, -1250, -1250, -1250,  1107, -1250,
   -1250,  1156,  1478, -1250, -1250,  1480, -1250, -1250, -1250, -1250,
   -1250,  1156,  5762,  1482,  1489,    28, -1250,  1491,  8397,    27,
   -1250,  1494,  1498,  1500,  1501,  4578,  5762,  7425,  7451,   651,
   -1250,  5762,  1504, -1250, -1250,  1107, -1250,  7477,  5473,  9157,
   -1250, -1250,  5762,  5762,   -64,  1503,  1506,  1507, -1250,  5762,
    5762, -1250, -1250,  1508,  5762, -1250, -1250,  1481,  1509,  1335,
    1518,  1362,  5762, -1250,  1525,  1528,  1529,  1530,  1531,  1532,
     842,  1533,  5762, -1250,  5473,  6099,  9052,  4881,   309,   309,
     -64,  1534,   -64,  1535,   -64,  1536,  5762,   363,  1324,  9073,
   -1250, -1250, -1250, -1250,  6127,   210, -1250,  1538,  3374,  1540,
    4578,   -64,  3374,  1541,   661,  5762, -1250,  1544,   108, -1250,
    5762,  5762,  5762,  5762, -1250, -1250, -1250,  4578,  5060,   415,
    9094, -1250, -1250,  4341,  4578, -1250, -1250,  4578, -1250,  1381,
     546,  3740,  4399,  1549,  2056, -1250,  1516,  1555, -1250,  1379,
   -1250, -1250, -1250, -1250, -1250,  1558,   486,  9157,  5762,  5762,
    4578,  1378,   664,  9157, -1250,  1560,  5762,  9157, -1250,  6155,
    6183,   446, -1250, -1250, -1250,  6211,  6239, -1250,  6267,  1562,
   -1250,  4578, -1250,  1497,  1564,  9157, -1250, -1250, -1250, -1250,
   -1250, -1250,  1384, -1250, -1250,  6826,  2116,  1566,  1390, -1250,
    5762, -1250,  1385,  1388,   224, -1250,  1409,   259, -1250,  1410,
     262, -1250,  1415,  8420,  1572,  4578,  1591,  1419,  5762, -1250,
    5294,   276, -1250,   670,   284,   286, -1250,  1601,  6295, -1250,
    7503,  7529,  7555,  7581,  1484,  5762, -1250,  5762, -1250, -1250,
    5537,  2268,  1602,  1425,  1608, -1250, -1250,  3554, -1250, -1250,
    1107,  9157, -1250, -1250, -1250,    27, -1250,  1485, -1250, -1250,
    5762,  7607,  7633, -1250,  4578,  5762,  1609, -1250,  7659, -1250,
   -1250,  1611,  1612,  1613,  1614,  1615,  1617,   674,  1439, -1250,
    4578,  5537, -1250, -1250,   309,  5239, -1250, -1250,  3120,   598,
    3120,   598,  3120,   598,  1618, -1250,   709,  4578, -1250,  6323,
     -64,  1619,  5537,   -64, -1250, -1250,  5762,  5762,  5762,  5762,
    5762,  6351,  6379,   713, -1250, -1250,  1621, -1250,   733,  2748,
     734,  1622, -1250,  1448,  9157,  5762,  5762,   740,  9157, -1250,
    5762,   746,   756, -1250, -1250, -1250, -1250, -1250, -1250,  1449,
    5762,   757,   760,  1441,  5762, -1250,  6407,   308,  1268,  6435,
     312,  1411,  6463,   376,  1443, -1250,  4578,  1628,  1547,  3959,
    1452,   387, -1250,   761,   421,  7685,  7711,  7737,  7763,  2307,
   -1250, -1250,  1632, -1250,  5762, -1250,  1156, -1250, -1250,  5762,
    9115,  7789,    45,  7815, -1250, -1250,  5762,  6491,  1634,  1551,
   -1250,  6519,  1639,  5762,  1640,  1641,  5762,  1642,  1643,  5762,
    1650,  1470, -1250,  5762, -1250,   598, -1250,  5537,  1653,  5294,
    5762,  5762,  5762,  5762, -1250, -1250,  2838, -1250,   764, -1250,
    5762, -1250,  4578,  5762,  7841, -1250, -1250,  4578,  1654, -1250,
   -1250,  1475,  6547, -1250, -1250,  1476,  6575, -1250, -1250,  1477,
    6603, -1250,  1655,  2444,  1940,  4618,   768, -1250,   429,   824,
    7867,  7893,  7919,  7945,  1156,  1659,  1479,  9136,   825,  6631,
    5762, -1250, -1250,   598,  1663,   598,  1667,   598,  1668, -1250,
   -1250, -1250, -1250,   598,  1669,  5537,  1670,  5762,  5762,  5762,
    5762, -1250, -1250,  1107, -1250,  1502,  1672,  6659,  2044, -1250,
    1513,  2300, -1250,  1514,  2462, -1250,  1515,  2553, -1250,   828,
   -1250,  7971,  7997,  8023,  8049,   831, -1250,  1520,  4578, -1250,
    1673,  1687,   598,  1688,   598,  1689,   598, -1250,  1690,  5762,
    5762,  5762,  5762,  1107,  1697,  1107,   834, -1250, -1250,  2565,
   -1250,  2603, -1250,  2680, -1250,  6687,  6715,  6743,  6771, -1250,
   -1250,   839, -1250,  1698,  1703,  1705,  1706, -1250, -1250, -1250,
   -1250,  1107,  1707, -1250, -1250, -1250, -1250, -1250, -1250
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1250, -1250, -1250, -1250,   673, -1250, -1250, -1250, -1250,   190,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250,  -363,   -62,   876,  -433, -1250,  1303, -1250, -1250,
   -1250, -1250, -1250,   301, -1250,   302, -1250, -1250, -1250, -1250,
   -1250, -1250,   667,  1718,    -2,  -450,  -236, -1250, -1250, -1250,
   -1250, -1250, -1250,  1720, -1250, -1250, -1250, -1250, -1250, -1250,
   -1250, -1250, -1250, -1250, -1250, -1250, -1250,  -921,  -908, -1250,
   -1250,  1287, -1250, -1250, -1250, -1250, -1250, -1250,  1492, -1250,
   -1250,    52, -1250, -1249,  1753,   296,   287,   735,  -224,   552,
   -1250,    73,     6, -1250,  -344,    -3,    35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -463
static const yytype_int16 yytable[] =
{
     101,    89,   455,   290,   580,   474,   582,   192,   601,   322,
     604,  1373,   171,   589,   300,   705,   706,   490,   251,   373,
     254,  1105,   255,   197,   192,   600,     5,   866,  1201,  1013,
    1103,   287,   841,   197,   222,   302,   507,   223,   102,  1094,
     321,   173,   504,   749,   751,   753,   755,   174,   178,   306,
     852,  1571,   309,   486,   310,   487,   318,   319,   984,   281,
    1096,   311,   463,   464,   188,   541,  -460,   543,   463,   464,
    1098,   189,  1194,   297,   463,   464,   463,   464,  1240,   170,
    1241,     4,  1427,   256,  1242,   509,  1243,   463,   464,   309,
    1244,   325,  1245,   465,   765,   463,   464,   644,   234,   236,
     645,   242,   600,   463,   464,  1085,   230,   231,   226,   511,
     401,   298,   466,   313,   176,   647,   232,   311,   645,   177,
     476,   227,   228,   233,   603,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,  1100,   802,   803,   804,
     805,   806,   807,   808,   175,   374,   375,   812,   814,   815,
     600,  1095,   544,   252,   501,  1014,  1015,   823,   247,   166,
     248,   297,   180,   378,   508,  1477,   853,   854,   855,   856,
     505,  1140,  1097,   297,   297,   314,   315,   316,   317,   291,
     297,  1491,  1099,   193,   181,   781,   281,   323,   867,   324,
     194,   281,   463,   464,   166,   281,   301,  1103,   281,   376,
     193,   253,   281,   281,   281,   281,   198,   846,   281,   281,
     281,   408,   408,   510,   288,   842,   847,   303,   408,   281,
     698,   699,   281,   307,   506,   750,   752,   754,   756,   179,
     308,   488,  1572,   867,   857,   985,   832,   512,   259,   835,
     714,   260,   637,   243,   281,   281,   281,   638,  1101,   406,
     409,   182,   314,   315,   316,   317,   281,   281,   318,   319,
     318,   319,   183,   314,   315,   316,   317,   184,  -461,   281,
    -462,   281,   318,   319,   314,   315,   316,   317,   309,   834,
     526,   458,   459,   318,   319,   318,   319,   311,  1171,   467,
     190,   463,   464,   475,   318,   319,   463,   464,   771,   185,
     314,   315,   316,   317,   281,   281,   244,   700,   318,   319,
     245,   605,   707,   377,   651,  1121,   652,   281,   186,   552,
     318,   319,   246,  1608,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   639,   191,
     463,   464,   398,   640,  1141,   297,   297,   297,   297,   297,
     297,   297,   297,   187,   297,   297,   713,   463,   464,   297,
     297,   297,   297,   739,   238,   740,   592,   239,   195,   741,
     240,   523,   598,  1081,   196,   463,   464,   642,   199,   281,
     463,   464,   643,   408,   408,   408,   408,   408,   408,   408,
     408,  1104,   408,   408,   463,   464,  1368,   408,   408,   408,
     597,   477,   200,    45,    46,    47,    48,   201,   478,  1676,
    1438,    53,   215,   281,    56,   216,   822,  1029,   217,   990,
     218,   643,   581,  1387,   583,   584,   585,   586,   587,   463,
     464,   590,   463,   464,   202,   594,   595,   596,   314,   315,
     316,   317,   395,   396,   397,  1440,   463,   464,  1442,   398,
     680,   683,   686,   689,   463,   464,   463,   464,   318,   319,
     204,   916,  1450,   378,   378,   383,   211,   230,   231,   212,
    1452,   213,  1453,   635,   203,   636,   418,   232,   463,   464,
     166,   418,   463,   464,   241,   418,   651,   209,   657,   281,
     281,   281,   418,   513,  1543,   789,   514,   545,  1546,   515,
     297,   516,   435,   436,   437,   188,   200,   440,   441,   442,
    1233,  1234,   845,   848,   281,   703,   704,   651,  1498,   661,
    1501,   281,  1504,   459,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   524,   396,   397,   743,   739,
     836,   740,   398,   482,   483,   764,   463,   464,   281,   219,
     210,  1364,   220,   205,   221,   495,   496,   463,   464,   519,
    1149,   418,  1549,  1282,  1283,  1153,  1154,  1155,  1156,  1157,
     651,   214,   667,  1557,  1163,  1166,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
    1103,   463,   464,  1103,   398,   651,  1103,   759,   281,   463,
     464,  1041,   206,  1388,   224,   207,   651,  1559,   208,   837,
     393,   394,   395,   396,   397,  1625,   463,   464,  1022,   398,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,  1594,   281,  1042,   281,   398,   229,
     297,   651,   309,   297,   500,   297,   501,   281,   281,   165,
    1172,   166,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,  1185,  1409,   237,   418,
     398,   281,  1410,   225,   249,   739,   789,   740,   408,   258,
     643,   876,   739,   408,   740,   250,  1103,   813,   929,  1269,
     281,   281,  1638,   779,  1641,   780,  1644,   257,   930,   739,
    1274,   740,  1647,   519,   651,   261,   931,   932,   933,   284,
     262,   634,   934,   935,   936,   937,   874,   739,   263,   740,
     991,   878,  1162,   739,   283,   740,   996,   739,  1165,   740,
    1103,   285,  1046,  1103,  1047,   651,  1103,   850,   281,  1103,
     651,  1679,   954,  1681,   651,  1683,   955,   281,   293,   281,
     826,   281,   919,   281,   651,   651,   956,   972,   281,   925,
     651,   281,   993,   286,  1052,   940,  1053,   651,   651,  1078,
    1122,  1103,   651,  1103,  1127,  1103,   281,   292,   281,   418,
     418,   418,   651,   294,  1128,   297,  1287,   296,  1352,  1353,
     651,   651,  1129,  1130,   299,   651,  1177,  1132,   651,   295,
    1133,  1037,   351,  1019,   418,  1179,   651,  1180,  1181,   352,
     281,   763,   651,   361,  1182,   297,   297,   297,   651,   651,
    1183,  1184,   651,   408,  1219,   353,   297,  1006,   389,   390,
     391,   392,   393,   394,   395,   396,   397,  1310,   418,  1311,
     354,   398,   281,   281,   281,   281,  1342,   651,  1343,  1377,
    1415,   355,  1416,   408,   408,   408,  1310,  1396,  1451,   357,
    1310,   997,  1489,   362,   408,   297,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     281,   281,   363,   281,   398,   281,   281,   364,   365,   281,
     281,  1003,  1004,  1005,   281,  1506,   366,  1507,   996,   651,
     400,  1522,  1010,   408,   381,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,  1524,
     643,  1525,  1527,   398,   419,   418,  1310,   418,  1532,   424,
     382,  1045,  1162,   428,  1534,   399,   403,   763,   881,   422,
     434,  1040,  1165,  1310,  1535,  1538,   651,   651,  1539,  1558,
    1415,  1173,  1605,   427,   651,  1300,  1624,   433,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   432,   281,   281,   281,   398,   312,  1086,  1087,
    1088,   418,   438,   281,  1493,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     651,  1310,  1626,  1635,   651,   356,  1668,  1673,   358,  1674,
    1310,   439,  1693,   359,   360,  1701,   443,  1702,   418,   444,
     445,   281,   446,   447,   448,   449,   450,   418,   453,   418,
     479,   418,   491,   418,   405,   105,   456,   281,   418,   457,
    1200,   418,   468,   281,   469,   470,  1470,   480,   481,   281,
     485,   281,   281,   489,   497,   498,   281,   281,   281,   281,
     281,   281,   281,   281,   492,   493,   494,   499,   503,   131,
     132,   133,   134,   135,   136,   525,   528,   139,   281,  1288,
     532,   534,   141,   142,   535,   143,   166,   311,   539,   540,
     418,   542,   550,   281,   929,   551,   148,   281,   554,   281,
     555,   405,   105,   557,   930,   398,   606,   616,   607,   608,
     165,   664,   931,   932,   933,   668,   609,   669,   934,   935,
     936,   937,   418,   418,   418,   418,   670,   695,   673,   674,
     502,   693,   696,   722,   697,   720,   131,   132,   133,   134,
     135,   136,   723,   725,   139,   297,  1255,   527,   732,   141,
     142,   105,   143,   733,   738,   744,   746,  1290,   769,   747,
     772,   748,   778,   148,   785,   786,   816,  1293,   817,   818,
     819,  1471,   281,   839,   418,   820,   151,   152,   827,   828,
     829,   830,   297,   408,   831,   131,   132,   133,   134,   135,
     136,   840,  1102,   139,  1318,   844,  1288,   865,   141,   142,
     870,   143,  1509,   873,   875,   877,   882,   318,   319,   879,
     883,   884,   148,   929,   995,   886,   888,   729,   730,   731,
     408,  1289,   887,   930,   889,   892,   378,   378,   891,   893,
    1347,   931,   932,   933,   897,   902,   904,   934,   935,   936,
     937,   906,   757,   151,   152,   281,  1321,   281,  1060,   281,
     915,   922,   907,   908,   949,   909,   923,   976,  1315,   962,
    1021,   977,   963,   978,   281,     7,     8,   965,   966,   988,
    1012,   281,   979,   967,   281,  1017,   784,   986,   281,  1392,
    1018,  1024,  1354,  1020,  1357,  1032,  1360,  1399,  1402,  1034,
    1036,  1057,   151,   152,  1033,  1044,  1039,   281,  1050,  1056,
    1371,  1061,  1062,  1374,  1375,  1064,  1065,  1068,  1079,  1069,
    1595,  1256,  1070,  1071,  1072,  1073,  1074,  1075,   281,  1076,
     610,    21,    22,   611,    24,    25,   612,    27,   613,    29,
    1077,    30,  1089,  1090,  1093,  1091,    35,    36,  1092,    38,
      39,    40,  1106,  1107,  1112,    43,  1108,  1109,   929,  1110,
    1113,  1114,   281,  1115,  1116,  1118,  1119,   281,   930,  1137,
    1142,  1143,  1145,   869,  1146,   871,   931,   932,   933,  1148,
    1150,  1151,   934,   935,   936,   937,  1152,   281,    64,    65,
      66,  1158,  1159,  1175,   281,  1193,  1160,   297,  1169,   418,
    1186,  1196,  1161,     7,     8,  1174,  1204,  1192,  1208,  1191,
    1211,   281,  1202,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   281,   281,   914,
    1203,   398,   378,  1209,  1210,   408,  1212,  1214,  1215,  1216,
    1217,  1222,  1223,  1238,   281,  1232,  1239,  1246,  1250,   281,
    1251,   728,  1252,  1253,  1260,  1268,  1544,  1261,   610,    21,
      22,   611,    24,    25,   612,    27,   613,    29,  1265,    30,
    1275,  1276,  1277,  1281,    35,    36,   961,    38,    39,    40,
    1285,  1284,  1291,    43,  1292,   968,  1329,   969,  1295,   970,
    1497,   971,  1500,  1296,  1503,  1333,   974,  1298,   168,   975,
    1301,   929,  1511,   281,  1302,  1514,  1303,  1304,  1314,  1322,
    1365,   930,  1323,  1324,  1327,  1330,    64,    65,    66,   931,
     932,   933,  1331,  1405,  1332,   934,   935,   936,   937,     7,
       8,  1336,  1567,   929,  1337,  1338,  1339,  1340,  1341,  1344,
    1355,  1358,  1361,   930,  1369,   418,  1372,  1376,  1002,   418,
    1379,   931,   932,   933,   281,  1403,   281,   934,   935,   936,
     937,  1406,  1395,  1407,  1408,  1414,  1417,  1426,  1428,   281,
    1429,  1430,  1433,  1436,   281,   305,  1437,  1434,  1445,   776,
    1025,  1026,  1027,  1028,   610,    21,    22,   611,    24,    25,
     612,    27,   613,    29,  1111,    30,  1439,  1441,  1447,  1547,
      35,    36,  1443,    38,    39,    40,  1448,  1454,  1465,    43,
    1631,  1598,  1460,  1466,  1467,  1479,  1472,  1483,  1484,  1485,
    1486,  1487,   281,  1488,  1505,  1512,  1490,  1523,  1528,  1540,
     297,  1550,  1063,  1170,  1552,  1529,  1536,  1553,  1565,  1556,
    1576,  1577,    64,    65,    66,  1580,  1583,  1584,  1587,  1588,
     367,   368,   369,   370,   372,   281,  1591,   519,  1592,  1597,
    1612,  1619,  1613,  1615,  1617,  1632,  1633,   404,   408,  1639,
     297,   410,   297,  1642,  1645,  1648,  1650,   418,  1659,  1677,
     415,   417,   420,   421,   418,   423,   417,   425,   426,  1658,
     417,   429,   430,  1678,  1680,  1682,  1684,   417,   297,  1176,
    1662,  1664,  1666,  1690,  1703,   777,  1656,  1675,   408,  1704,
     408,  1705,  1706,  1708,  1195,   452,  1206,   648,   418,  1568,
    1481,    88,  1482,    96,   461,   462,     0,  1297,     0,   676,
       0,     0,     0,   462,     0,     0,   408,     0,     0,   418,
       0,     0,     0,     0,     0,     0,  1689,     0,  1692,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,   518,   520,   417,   398,     0,     0,
       0,     0,     0,     0,  1707,     0,   529,   530,   531,     0,
     533,     0,     0,   536,   537,     0,     0,   538,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   549,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,   556,     0,     0,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
       0,     0,     0,     0,   418,     0,   418,  1264,   588,     0,
       0,   591,     0,   593,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,   615,   417,     0,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,     0,     0,   633,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,   518,     0,
     398,     0,   418,     0,   655,     0,     0,     0,     0,   660,
       0,     0,     0,     0,   665,   666,     0,     0,     0,     0,
     671,   672,     0,     0,     0,   677,   679,   682,   685,   688,
     690,   691,   692,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1266,   431,     0,     0,     0,     0,     0,
     708,   709,   710,   367,   368,   711,     0,     0,     0,   715,
     716,   717,   718,   719,     0,   451,     0,   724,   454,     0,
     726,   727,     0,     0,   417,   417,   417,     0,     0,   734,
     735,   736,   737,     0,     0,     0,     0,     0,   745,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,   417,
       0,     0,  1286,     0,     0,   760,   762,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
     929,     0,     0,     0,     0,     0,   737,     0,     0,     0,
     930,     0,   783,   417,     0,     0,     0,   787,   931,   932,
     933,     0,     0,     0,   934,   935,   936,   937,     0,     0,
     546,   547,  1404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   553,     0,     0,     0,     0,     0,     0,
       0,   610,    21,    22,   611,    24,    25,   612,    27,   613,
      29,     0,    30,     0,     0,     0,   838,    35,    36,     0,
      38,    39,    40,     0,     0,     0,    43,     0,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,  1432,     0,     0,  1463,   398,   864,  1621,     0,
     417,     0,   417,   872,   929,     0,     0,     0,     0,    64,
      65,    66,   762,   880,   930,     0,     0,     0,     0,     0,
       0,     0,   931,   932,   933,     0,   894,     0,   934,   935,
     936,   937,     0,     0,     0,   900,  1492,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,   417,  1513,     0,     0,
       0,     0,     0,   920,   921,     0,     0,     0,     0,   924,
       0,     0,   917,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   948,     0,     0,   950,     0,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,  1661,   417,     0,   398,     0,     0,     0,     0,
       0,     0,   417,     0,   417,     0,   417,     0,   417,     0,
       0,     0,     0,   417,     0,     0,   417,     0,     0,     0,
       0,     0,   980,     0,   982,   983,     0,     0,     0,     0,
       0,     0,     0,     0,  1464,     0,     0,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,  1596,   998,  1599,   398,     0,     0,     0,     0,
       0,   999,  1000,  1001,     0,   417,     0,     0,     0,     0,
       0,     0,     0,  1564,     0,     0,     0,     0,     0,  1009,
       0,     0,     0,     0,  1011,     0,     0,  1016,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,   417,   417,
     417,     0,     0,  1030,     0,     0,     0,     0,     0,     0,
       0,   103,   304,     0,   833,     0,     0,   106,   107,   108,
    1649,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,   417,
     929,     0,     0,   137,   138,     0,   140,     0,     0,     0,
     930,     0,     0,     0,     0,   144,   145,   146,   931,   932,
     933,     0,     0,   147,   934,   935,   936,   937,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   901,     0,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,   913,   398,  1117,     0,
    1620,  1120,     0,     0,     0,  1123,     0,  1124,  1125,  1126,
       0,     0,     0,     0,     0,  1131,     0,     0,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,  1147,     0,     7,     8,   398,     0,  1663,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,  1178,     0,     0,     0,     0,   158,   159,
       0,     0,     0,   160,  1187,  1188,     0,     0,   273,     0,
       0,   371,   987,   164,   989,  1197,  1199,     0,     0,   610,
      21,    22,   611,    24,    25,   612,    27,   613,    29,     0,
      30,     0,   929,     0,     0,    35,    36,     0,    38,    39,
      40,     0,   930,     0,    43,     0,     0,     0,     0,     0,
     931,   932,   933,  1235,  1236,  1237,   934,   935,   936,   937,
       0,     0,     0,  1247,     0,  1249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1254,    64,    65,    66,
       0,     0,     0,     0,   417,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,     0,     0,     0,     0,     0,
    1278,  1279,  1280,     0,     0,     0,  1048,  1049,     0,  1051,
       0,  1054,  1055,   929,     0,  1058,  1059,     0,     0,     0,
    1665,     0,     0,   930,     0,   929,     0,     0,     0,     0,
     918,   931,   932,   933,  1294,   930,     0,   934,   935,   936,
     937,     0,     0,   931,   932,   933,     0,     0,  1307,   934,
     935,   936,   937,  1313,     0,     0,     0,     0,     0,     0,
    1317,     0,     0,   929,  1319,  1320,     0,     0,     0,     0,
       0,  1325,  1326,   930,     0,     0,  1328,     0,     0,     0,
       0,   931,   932,   933,  1335,     0,     0,   934,   935,   936,
     937,     0,     0,     0,  1345,     0,  1346,     0,     0,  1134,
    1135,  1136,     0,     0,     0,     0,     0,     0,  1363,  1144,
       0,  1667,     0,     0,     0,     0,     0,     0,     0,     0,
     417,     0,     0,  1694,   417,  1526,   523,  1378,     0,     0,
       0,     0,  1380,  1381,  1382,  1383,     0,     0,     0,     0,
     929,     0,     0,     0,     0,  1391,     0,     7,     8,     0,
     930,     0,     0,     0,  1401,     0,     0,  1190,   931,   932,
     933,  1695,     0,     0,   934,   935,   936,   937,     0,     0,
    1411,  1412,     0,  1207,     0,     0,     0,     0,  1418,  1213,
       0,     0,     0,     0,     0,  1218,     0,  1220,  1221,     0,
       0,     0,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,
       0,     0,   610,    21,    22,   611,    24,    25,   612,    27,
     613,    29,  1435,    30,  1248,  1604,     0,     0,    35,    36,
       0,    38,    39,    40,     0,     0,     0,    43,     0,  1259,
    1449,     0,   518,  1263,     0,     0,     0,     0,  1696,     0,
       0,     0,     0,     0,     0,     0,     0,  1461,     0,  1462,
       0,     0,   417,     0,     0,     0,     0,     0,     0,  1469,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1474,     0,     0,     0,     0,  1478,     0,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     650,   396,   397,   417,     0,     0,     0,   398,     0,     0,
    1496,     0,  1499,   523,  1502,     0,     0,     0,  1305,     0,
       0,     0,     0,     0,   417,     0,     0,     0,  1515,  1516,
    1517,  1518,  1519,   941,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,  1530,  1531,   398,
       0,     0,  1533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1537,     0,     0,     0,  1541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1066,     0,     0,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,  1190,     0,     0,  1566,   398,     0,     0,
       0,  1313,     0,     0,     0,     0,     0,     0,  1574,     0,
    1384,     0,     0,     0,     0,  1582,     0,  1393,  1586,     0,
    1394,  1590,     0,     0,  1398,  1593,     0,     0,     0,   417,
       0,   417,  1600,  1601,  1602,  1603,     0,     0,     0,     0,
       0,     0,  1607,  1413,     0,  1609,     0,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,  1190,   398,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   524,   396,   397,
       0,     0,  1637,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,  1446,  1651,
    1652,  1653,  1654,   103,   304,     0,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   523,     0,     0,     0,
       0,  1685,  1686,  1687,  1688,   137,   138,  1190,   140,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,   146,
       0,     0,     0,  1190,     0,   147,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,   106,   107,   108,     0,
    1508,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,   141,
     142,     0,   143,     0,   144,   145,   146,     0,     0,     0,
       0,     0,   147,   148,     0,     0,     0,     0,     0,  1551,
       0,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   472,     0,     0,     0,   160,     0,     0,     0,     0,
     473,     0,     0,     0,     0,   164,     0,   233,     0,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     650,   396,   397,     0,     0,  1190,   149,   398,     0,     0,
    1611,     0,   150,   151,   152,     0,     0,     0,     0,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   159,     0,
       0,     0,   160,     0,     0,     0,     0,   161,     0,   162,
       0,   163,   164,     0,   165,     0,   166,   103,   264,     0,
       0,     0,     0,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     266,  1190,     0,     0,     0,     0,     0,     0,     0,   137,
     138,     0,   140,     0,     0,     7,     8,     0,     0,     0,
       0,   144,   145,   146,     0,     0,     0,     0,     0,   147,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     610,    21,    22,   611,    24,    25,   612,    27,   613,    29,
       0,    30,     0,     0,     0,     0,    35,    36,     0,    38,
      39,    40,     0,     0,     0,    43,     0,   773,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   851,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,     0,   471,  1370,     0,     0,     0,   160,
       0,     0,     0,     0,   473,     0,     0,   103,   264,   164,
       0,   233,   521,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,   981,   140,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,   146,     0,     0,     0,     0,     0,   147,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,   150,
       0,     0,   398,     0,     0,     0,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   416,     0,     0,     0,   160,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   164,
       0,     0,   521,   103,   264,   105,     0,     0,     0,   106,
     107,   108,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   266,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,   141,   142,     0,   143,     0,   144,   145,   146,
       0,     0,     0,     7,     8,   147,   148,   267,     0,     0,
     268,     0,     0,   269,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,     0,
       0,     0,    53,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   610,    21,
      22,   611,    24,    25,   612,    27,   613,    29,     0,    30,
       0,     0,     0,     0,    35,    36,     0,    38,    39,    40,
       0,     0,     0,    43,     0,   150,   151,   152,     0,     0,
       0,     0,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   272,     0,     0,     0,   160,    64,    65,    66,     0,
     273,     0,   103,   264,   265,   164,     0,  1397,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,     0,   140,     0,     0,
       0,     7,     8,     0,     0,     0,   144,   145,   146,  1080,
       0,     0,     0,     0,   147,     0,   267,     0,     0,   268,
       0,     0,   269,     0,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,    45,    46,    47,    48,    49,     0,     0,
       0,    53,     0,     0,    56,     0,   610,    21,    22,   611,
      24,    25,   612,    27,   613,    29,     0,    30,     0,     0,
       0,     0,    35,    36,     0,    38,    39,    40,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,     0,   158,
     272,     0,     0,     0,   160,     0,     0,     0,     0,   273,
       0,   103,   304,   105,   164,     0,   274,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   973,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,  1554,     0,     0,
     141,   142,     0,   143,     0,   144,   145,   146,     0,     0,
       0,     0,     0,   147,   148,   103,   264,  1257,     0,     0,
       0,   106,   107,   108,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     145,   146,     0,     0,     0,     0,     0,   147,     0,   267,
       0,     0,   268,     0,     0,   269,     0,   270,     0,     0,
       0,     0,     0,   150,   151,   152,     0,     0,     0,   271,
     153,   154,   155,   156,   157,     0,    45,    46,    47,    48,
      49,     0,     0,     0,    53,     0,     0,    56,   158,   159,
       0,     0,     0,   160,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   164,     0,  1198,     0,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,   150,     0,     0,
       0,     0,     0,  1139,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   272,     0,     0,     0,   160,     0,     0,
       0,     0,   273,     0,   103,   304,   105,   164,     0,  1258,
     106,   107,   108,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,   141,   142,     0,   143,     0,   144,   145,
     146,     0,   103,   304,   105,     0,   147,   148,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,   141,   142,     0,   143,     0,   144,   145,   146,     0,
       0,     0,     0,     0,   147,   148,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,   150,   151,   152,     0,
       0,     0,     0,   153,   154,   155,   156,   157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,   159,     0,     0,     0,   160,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   164,     0,  1390,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,   150,   151,   152,   398,     0,     0,
       0,   153,   154,   155,   156,   157,   849,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,   160,     0,     0,     0,     0,   273,
       0,   103,   264,     0,   164,     0,  1400,   106,   107,   108,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,     0,   140,     0,     0,     0,
       7,     8,     0,     0,     0,   144,   145,   146,     0,     0,
       0,     0,     0,   147,     0,   267,     0,     0,   268,     0,
       0,   269,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,    49,     0,     0,     0,
      53,     0,     0,    56,     0,   610,    21,    22,   611,    24,
      25,   612,    27,   613,    29,     0,    30,     0,     0,     0,
       0,    35,    36,     0,    38,    39,    40,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,   158,   272,
       0,     0,     0,   160,     0,     0,     0,     0,   273,     0,
     103,   264,     0,   164,     0,   274,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,     0,   140,  1622,     0,     7,     8,
       0,     0,     0,     0,   144,   145,   146,     0,     0,     0,
       0,     0,   147,     0,   267,     0,     0,   268,     0,     0,
     269,     0,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   610,    21,    22,   611,    24,    25,   612,
      27,   613,    29,     0,    30,     0,     0,     0,     0,    35,
      36,     0,    38,    39,    40,     0,     0,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     0,     0,   158,   416,     0,
       0,     0,   160,     0,     0,     0,     0,   273,     0,   103,
     264,     0,   164,     0,   517,   106,   107,   108,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   138,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,     0,     0,     0,     0,
       0,   147,     0,   267,     0,     0,   268,     0,     0,   269,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,     0,     0,     0,    53,     0,
       0,    56,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1350,     0,  1351,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   416,     0,     0,
       0,   160,     0,     0,     0,     0,   273,     0,   103,   264,
       0,   164,     0,   761,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,     0,   140,     0,     0,     0,     0,     0,     0,
       0,     0,   144,   145,   146,     0,     0,     0,     0,     0,
     147,     0,   267,     0,     0,   268,     0,     0,   269,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,     0,     0,     0,    53,     0,     0,
      56,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,     0,     0,     0,     0,     0,  1385,     0,  1386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,   153,   154,   155,
     156,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   272,     0,     0,     0,
     160,     0,     0,     0,     0,   273,     0,   103,   264,     0,
     164,     0,  1262,   106,   107,   108,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,     0,   140,     0,     0,     0,     0,     0,     0,     0,
       0,   144,   145,   146,     0,     0,     0,     0,     0,   147,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,     0,     0,     0,    53,     0,     0,    56,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1494,     0,  1495,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   471,  1370,     0,     0,     0,   160,
       0,     0,     0,     0,   473,     0,   103,   304,   105,   164,
       0,   233,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,   141,   142,     0,   143,     0,
     144,   145,   146,     0,     0,     0,     0,     0,   147,   148,
     103,   264,     0,     0,     0,     0,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,   146,     0,     0,     0,
       0,     0,   147,     0,   267,     0,     0,   268,     0,     0,
     269,     0,   270,     0,     0,     0,     0,     0,   150,   151,
     152,     0,     0,     0,   271,   153,   154,   155,   156,   157,
       0,    45,    46,    47,    48,    49,     0,     0,     0,    53,
       0,     0,    56,   158,   159,     0,     0,     0,   160,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   164,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,     0,
       0,     0,   150,     0,     0,     0,   896,     0,     0,   153,
     154,   155,   156,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   416,     0,
       0,     0,   160,   103,   304,     0,     0,   273,     0,   106,
     107,   108,   164,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   138,     0,   140,     0,
       0,     0,     0,     0,     0,   103,   304,   144,   145,   146,
       0,   106,   107,   108,     0,   147,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   138,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,   144,
     145,   146,     0,     0,     0,     0,     0,   147,     0,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,     0,
       0,     0,     0,     0,     0,   150,   944,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     158,   159,     0,     0,     0,   160,     0,     0,     0,     0,
     273,     0,     0,   548,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,    -4,     1,
       0,     0,    -4,     0,   153,   154,   155,   156,   157,     0,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,     0,     0,     0,   160,     0,     0,
       0,     0,   273,     0,     0,    -4,    -4,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,    -4,     6,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,    14,     0,
      15,     0,     0,     0,    16,    17,     0,    18,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,    59,    60,    61,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,    63,    64,
      65,    66,     0,     0,    67,     0,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    80,    81,    82,    83,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,   964,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,   992,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1084,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,  1348,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,  1367,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1421,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,  1422,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1423,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,  1424,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,  1425,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1455,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,  1510,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1520,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,  1521,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,  1542,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1545,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,  1548,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1575,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,  1579,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,  1614,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1616,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,  1618,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1636,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,  1660,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,  1697,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1698,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,  1699,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,  1700,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,     0,   694,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,     0,     0,  1431,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,   758,     0,     0,     0,     0,   701,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,   641,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,   701,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,   702,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,   770,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,   801,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,   809,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,   810,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,   811,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,   821,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,   926,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,   927,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,   928,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,   959,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1043,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1082,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1083,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1138,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1270,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1271,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1272,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1273,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1308,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1309,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1316,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1456,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1457,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1458,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1459,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1475,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1476,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1480,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1560,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1561,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1562,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1563,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1570,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1573,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1610,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1627,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1628,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1629,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
       0,  1630,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,  1669,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
       0,     0,     0,  1670,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,     0,     0,     0,  1671,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,     0,     0,     0,  1672,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,   739,     0,   740,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,     0,
       0,   602,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,   775,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,     0,     0,   782,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
     788,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,     0,     0,   863,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,     0,     0,   952,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,     0,     0,   953,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
       0,     0,   957,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,   398,     0,     0,     0,   958,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,     0,     0,   960,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,     0,
       0,   994,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,     0,     0,  1038,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,     0,     0,  1267,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,     0,     0,
    1299,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,     0,     0,  1444,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,   599,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,   649,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,   653,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,   654,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,   656,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,   658,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
     659,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,   662,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,   663,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,   398,     0,   758,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,   766,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,   767,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,   768,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,   774,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,   885,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,   890,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
     895,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,   898,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,   899,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,   398,     0,   905,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,   910,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,   911,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,   912,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,   943,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398,     0,   945,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,     0,     0,     0,     0,   398,     0,   946,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,     0,
     947,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
       0,   951,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,     0,  1168,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,   398,     0,  1349,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,     0,     0,
       0,     0,   398,     0,  1366,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,     0,  1389,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
       0,     0,     0,     0,   398,     0,  1569,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,     0,     0,     0,     0,   398,     0,  1634,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,     0,     0,     0,     0,   398
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1250)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,   226,     4,   348,   241,   350,     4,   371,     4,
     373,  1260,     6,   357,     5,   465,   466,   253,     4,     4,
       4,   942,     6,     4,     4,     7,     0,     6,     6,     4,
     938,     4,     4,     4,    70,     5,     5,    73,     3,     6,
     102,     6,     5,     5,     5,     5,     5,    13,     6,     6,
       4,     6,   180,     4,   182,     6,   177,   178,     7,    62,
       6,   189,   170,   171,   180,   301,   187,   303,   170,   171,
       6,   187,     6,    76,   170,   171,   170,   171,   186,     6,
     188,     6,  1331,    67,   186,     5,   188,   170,   171,   180,
     186,   182,   188,   187,   527,   170,   171,   183,    46,    47,
     186,    49,     7,   170,   171,   188,   170,   171,   130,     5,
     182,    76,   187,     7,   180,   183,   180,   189,   186,   180,
     187,   143,   144,   187,     7,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,     6,   570,   571,   572,
     573,   574,   575,   576,    73,   130,   131,   580,   581,   582,
       7,   118,   182,   139,   184,   130,   131,   590,    73,   189,
      75,   164,     6,   165,   133,  1414,   120,   121,   122,   123,
     133,     8,   118,   176,   177,   157,   158,   159,   160,   180,
     183,  1430,   118,   180,     6,   548,   189,   182,   167,   184,
     187,   194,   170,   171,   189,   198,   187,  1105,   201,   164,
     180,   187,   205,   206,   207,   208,   187,   187,   211,   212,
     213,   176,   177,   133,   187,   187,   187,   187,   183,   222,
     456,   457,   225,   180,   187,   187,   187,   187,   187,   187,
     187,   182,   187,   167,   188,   184,   599,   133,    70,   602,
     476,    73,   181,     4,   247,   248,   249,   186,   118,   176,
     177,     6,   157,   158,   159,   160,   259,   260,   177,   178,
     177,   178,   180,   157,   158,   159,   160,     6,   187,   272,
     187,   274,   177,   178,   157,   158,   159,   160,   180,   184,
     182,   229,   230,   177,   178,   177,   178,   189,     7,   237,
     180,   170,   171,   241,   177,   178,   170,   171,   534,     6,
     157,   158,   159,   160,   307,   308,    67,   186,   177,   178,
      71,   373,   186,     4,   186,   184,   188,   320,   182,   313,
     177,   178,    83,  1572,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   181,   180,
     170,   171,   179,   186,   181,   348,   349,   350,   351,   352,
     353,   354,   355,   182,   357,   358,   186,   170,   171,   362,
     363,   364,   365,   181,    67,   183,   360,    70,   180,   187,
      73,     8,   366,   186,   180,   170,   171,   181,   180,   382,
     170,   171,   186,   348,   349,   350,   351,   352,   353,   354,
     355,   186,   357,   358,   170,   171,   186,   362,   363,   364,
     365,   180,   180,    94,    95,    96,    97,    77,   187,  1658,
     186,   102,    67,   416,   105,    70,   181,   850,    73,   782,
      75,   186,   349,     8,   351,   352,   353,   354,   355,   170,
     171,   358,   170,   171,    73,   362,   363,   364,   157,   158,
     159,   160,   172,   173,   174,   186,   170,   171,   186,   179,
     444,   445,   446,   447,   170,   171,   170,   171,   177,   178,
       6,   697,   186,   465,   466,     6,    70,   170,   171,    73,
     186,    75,   186,   182,    73,   184,   189,   180,   170,   171,
     189,   194,   170,   171,   187,   198,   186,    73,   188,   492,
     493,   494,   205,    67,   186,   557,    70,     6,   186,    73,
     503,    75,   206,   207,   208,   180,   180,   211,   212,   213,
       6,     7,   187,   187,   517,   463,   464,   186,  1439,   188,
    1441,   524,  1443,   471,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   503,   181,
     602,   183,   179,   247,   248,   187,   170,   171,   551,    70,
      73,   188,    73,   187,    75,   259,   260,   170,   171,   272,
     993,   274,   186,     6,     7,   998,   999,  1000,  1001,  1002,
     186,    75,   188,   186,  1007,  1008,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
    1498,   170,   171,  1501,   179,   186,  1504,   188,   601,   170,
     171,   181,    67,   188,   180,    70,   186,   186,    73,   603,
     170,   171,   172,   173,   174,   186,   170,   171,   842,   179,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,  1555,   638,   181,   640,   179,   187,
     643,   186,   180,   646,   182,   648,   184,   650,   651,   187,
    1013,   189,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,  1029,   181,   187,   382,
     179,   674,   186,    70,    73,   181,   738,   183,   643,    73,
     186,   646,   181,   648,   183,    70,  1594,   186,    90,  1122,
     693,   694,  1613,   186,  1615,   188,  1617,    70,   100,   181,
    1133,   183,  1623,   416,   186,     4,   108,   109,   110,   180,
       4,     6,   114,   115,   116,   117,   643,   181,     4,   183,
     782,   648,   186,   181,     4,   183,   788,   181,   186,   183,
    1638,   180,    73,  1641,    75,   186,  1644,   188,   741,  1647,
     186,  1662,   188,  1664,   186,  1666,   188,   750,     6,   752,
       6,   754,   700,   756,   186,   186,   188,   188,   761,   707,
     186,   764,   188,   180,    73,   713,    75,   186,   186,   188,
     188,  1679,   186,  1681,   188,  1683,   779,   180,   781,   492,
     493,   494,   186,     6,   188,   788,  1149,     4,  1238,  1239,
     186,   186,   188,   188,     4,   186,  1020,   188,   186,   182,
     188,   863,   180,     6,   517,   186,   186,   188,   188,   180,
     813,   524,   186,     7,   188,   818,   819,   820,   186,   186,
     188,   188,   186,   788,   188,   180,   829,   821,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   186,   551,   188,
     180,   179,   845,   846,   847,   848,     4,   186,     6,   188,
     186,   180,   188,   818,   819,   820,   186,  1290,   188,   180,
     186,   788,   188,   180,   829,   868,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     883,   884,   180,   886,   179,   888,   889,   180,   180,   892,
     893,   818,   819,   820,   897,   186,   180,   188,   960,   186,
       6,   188,   829,   868,   187,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   186,
     186,   188,   188,   179,   189,   638,   186,   640,   188,   194,
     187,   879,   186,   198,   188,   187,     6,   650,   651,   180,
     205,   868,   186,   186,   188,   188,   186,   186,   188,   188,
     186,  1013,   188,   180,   186,  1179,   188,   187,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   180,   976,   977,   978,   179,   101,   926,   927,
     928,   694,   180,   986,  1434,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     186,   186,   188,   188,   186,   139,   188,   186,   142,   188,
     186,   180,   188,   147,   148,   186,   180,   188,   741,   180,
     180,  1034,   180,   180,   180,   180,   180,   750,     4,   752,
     180,   754,     6,   756,     4,     5,   187,  1050,   761,   187,
    1044,   764,   187,  1056,   187,   187,  1400,   180,   180,  1062,
     180,  1064,  1065,   182,   182,   182,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,   187,   187,   187,   182,   182,    39,
      40,    41,    42,    43,    44,     6,     6,    47,  1091,  1151,
     184,   187,    52,    53,   133,    55,   189,   189,     6,     6,
     813,     6,   187,  1106,    90,   187,    66,  1110,     6,  1112,
     182,     4,     5,     4,   100,   179,   184,   382,     7,   182,
     187,     7,   108,   109,   110,     6,   188,     6,   114,   115,
     116,   117,   845,   846,   847,   848,     6,   181,     7,     7,
     264,     7,     6,     6,   187,     7,    39,    40,    41,    42,
      43,    44,     7,     6,    47,  1158,  1104,   281,     6,    52,
      53,     5,    55,     6,     4,    49,    49,  1161,   130,    49,
     187,    49,   181,    66,     6,     6,   181,  1171,   181,   186,
     186,  1405,  1185,     6,   897,   186,   146,   147,   186,   181,
     186,   181,  1195,  1158,   181,    39,    40,    41,    42,    43,
      44,     4,   188,    47,  1198,   183,  1268,     4,    52,    53,
       6,    55,  1448,     6,     6,     6,   133,   177,   178,     7,
       7,     7,    66,    90,   184,     7,     7,   492,   493,   494,
    1195,  1158,   133,   100,     7,     7,  1238,  1239,   133,     7,
    1234,   108,   109,   110,   187,     4,     6,   114,   115,   116,
     117,   181,   517,   146,   147,  1258,  1204,  1260,     6,  1262,
     184,   188,   181,   181,     6,   181,   188,     7,  1195,   183,
     182,     7,   187,     7,  1277,    12,    13,   187,   187,     6,
       6,  1284,   184,   187,  1287,     6,   551,   187,  1291,  1283,
       6,     6,  1240,     7,  1242,   180,  1244,  1291,  1292,   187,
       6,    75,   146,   147,   180,     7,   167,  1310,     7,     7,
    1258,     7,     7,  1261,  1262,     7,     7,     6,     4,     7,
    1556,   188,     7,     7,     7,     7,     7,     7,  1331,     7,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       6,    78,     4,     6,   180,   187,    83,    84,     6,    86,
      87,    88,     7,     6,   187,    92,     7,     7,    90,     7,
       6,     6,  1365,     6,    73,     6,     6,  1370,   100,     4,
       4,     4,   188,   638,     6,   640,   108,   109,   110,     6,
       6,     4,   114,   115,   116,   117,     6,  1390,   125,   126,
     127,   186,   181,     7,  1397,     6,   181,  1400,   181,  1112,
     180,     6,   186,    12,    13,   184,    83,   184,     6,   187,
       6,  1414,   187,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,  1430,  1431,   694,
     187,   179,  1434,   187,   187,  1400,     6,   187,     6,     6,
       5,     4,     6,   187,  1447,     7,   187,   182,     6,  1452,
       6,   188,     6,     6,   187,     4,   188,   187,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   187,    78,
       6,     6,   129,     6,    83,    84,   741,    86,    87,    88,
       6,   186,     4,    92,     4,   750,     5,   752,     6,   754,
    1438,   756,  1440,     4,  1442,   133,   761,     6,     6,   764,
       6,    90,  1450,  1506,     6,  1453,     6,     6,     4,     6,
     186,   100,     6,     6,     6,     6,   125,   126,   127,   108,
     109,   110,   187,     7,     6,   114,   115,   116,   117,    12,
      13,     6,  1526,    90,     6,     6,     6,     6,     6,     6,
       6,     6,     6,   100,     6,  1258,     6,     6,   813,  1262,
       6,   108,   109,   110,  1557,     6,  1559,   114,   115,   116,
     117,     6,   181,   184,     6,   187,     6,     5,    71,  1572,
       6,   187,     6,   188,  1577,    83,   188,   187,     6,   188,
     845,   846,   847,   848,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     6,    78,   187,   187,     7,   188,
      83,    84,   187,    86,    87,    88,   187,     6,     6,    92,
    1604,  1559,   128,   188,     6,     6,   131,     6,     6,     6,
       6,     6,  1625,     6,     6,     6,   187,     6,     6,   188,
    1633,   188,   897,     6,     6,   187,   187,    90,     6,   187,
       6,    90,   125,   126,   127,     6,     6,     6,     6,     6,
     158,   159,   160,   161,   162,  1658,     6,  1370,   188,     6,
       6,     6,   187,   187,   187,     6,   187,   175,  1633,     6,
    1673,   179,  1675,     6,     6,     6,     6,  1390,     6,     6,
     188,   189,   190,   191,  1397,   193,   194,   195,   196,   187,
     198,   199,   200,     6,     6,     6,     6,   205,  1701,     6,
     187,   187,   187,     6,     6,   188,  1633,   187,  1673,     6,
    1675,     6,     6,     6,  1041,   223,  1049,   414,  1431,  1529,
    1419,     3,  1420,     3,   232,   233,    -1,  1175,    -1,   442,
      -1,    -1,    -1,   241,    -1,    -1,  1701,    -1,    -1,  1452,
      -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,  1675,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   272,   273,   274,   179,    -1,    -1,
      -1,    -1,    -1,    -1,  1701,    -1,   284,   285,   286,    -1,
     288,    -1,    -1,   291,   292,    -1,    -1,   295,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   310,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
      -1,    -1,    -1,    -1,  1557,    -1,  1559,  1112,   356,    -1,
      -1,   359,    -1,   361,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,   381,   382,    -1,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,    -1,    -1,   401,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,   416,    -1,
     179,    -1,  1625,    -1,   422,    -1,    -1,    -1,    -1,   427,
      -1,    -1,    -1,    -1,   432,   433,    -1,    -1,    -1,    -1,
     438,   439,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   201,    -1,    -1,    -1,    -1,    -1,
     468,   469,   470,   471,   472,   473,    -1,    -1,    -1,   477,
     478,   479,   480,   481,    -1,   222,    -1,   485,   225,    -1,
     488,   489,    -1,    -1,   492,   493,   494,    -1,    -1,   497,
     498,   499,   500,    -1,    -1,    -1,    -1,    -1,   506,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,   517,
      -1,    -1,     6,    -1,    -1,   523,   524,    -1,   526,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,
     100,    -1,   550,   551,    -1,    -1,    -1,   555,   108,   109,
     110,    -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,
     307,   308,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    -1,   604,    83,    84,    -1,
      86,    87,    88,    -1,    -1,    -1,    92,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     6,    -1,    -1,  1390,   179,   635,   188,    -1,
     638,    -1,   640,   641,    90,    -1,    -1,    -1,    -1,   125,
     126,   127,   650,   651,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,   664,    -1,   114,   115,
     116,   117,    -1,    -1,    -1,   673,  1431,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,   694,  1452,    -1,    -1,
      -1,    -1,    -1,   701,   702,    -1,    -1,    -1,    -1,   707,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   720,    -1,    -1,   723,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   188,   741,    -1,   179,    -1,    -1,    -1,    -1,
      -1,    -1,   750,    -1,   752,    -1,   754,    -1,   756,    -1,
      -1,    -1,    -1,   761,    -1,    -1,   764,    -1,    -1,    -1,
      -1,    -1,   770,    -1,   772,   773,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,  1557,   801,  1559,   179,    -1,    -1,    -1,    -1,
      -1,   809,   810,   811,    -1,   813,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,   827,
      -1,    -1,    -1,    -1,   832,    -1,    -1,   835,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   845,   846,   847,
     848,    -1,    -1,   851,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,   601,    -1,    -1,     9,    10,    11,
    1625,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,   897,
      90,    -1,    -1,    45,    46,    -1,    48,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,    57,    58,    59,   108,   109,
     110,    -1,    -1,    65,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   674,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,   693,   179,   956,    -1,
       6,   959,    -1,    -1,    -1,   963,    -1,   965,   966,   967,
      -1,    -1,    -1,    -1,    -1,   973,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   990,    -1,    12,    13,   179,    -1,   188,    -1,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1021,    -1,    -1,    -1,    -1,   170,   171,
      -1,    -1,    -1,   175,  1032,  1033,    -1,    -1,   180,    -1,
      -1,   183,   779,   185,   781,  1043,  1044,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    -1,    90,    -1,    -1,    83,    84,    -1,    86,    87,
      88,    -1,   100,    -1,    92,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,  1081,  1082,  1083,   114,   115,   116,   117,
      -1,    -1,    -1,  1091,    -1,  1093,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1104,   125,   126,   127,
      -1,    -1,    -1,    -1,  1112,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,
    1138,  1139,  1140,    -1,    -1,    -1,   883,   884,    -1,   886,
      -1,   888,   889,    90,    -1,   892,   893,    -1,    -1,    -1,
     188,    -1,    -1,   100,    -1,    90,    -1,    -1,    -1,    -1,
     188,   108,   109,   110,  1172,   100,    -1,   114,   115,   116,
     117,    -1,    -1,   108,   109,   110,    -1,    -1,  1186,   114,
     115,   116,   117,  1191,    -1,    -1,    -1,    -1,    -1,    -1,
    1198,    -1,    -1,    90,  1202,  1203,    -1,    -1,    -1,    -1,
      -1,  1209,  1210,   100,    -1,    -1,  1214,    -1,    -1,    -1,
      -1,   108,   109,   110,  1222,    -1,    -1,   114,   115,   116,
     117,    -1,    -1,    -1,  1232,    -1,  1234,    -1,    -1,   976,
     977,   978,    -1,    -1,    -1,    -1,    -1,    -1,  1246,   986,
      -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1258,    -1,    -1,   188,  1262,     7,     8,  1265,    -1,    -1,
      -1,    -1,  1270,  1271,  1272,  1273,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,  1283,    -1,    12,    13,    -1,
     100,    -1,    -1,    -1,  1292,    -1,    -1,  1034,   108,   109,
     110,   188,    -1,    -1,   114,   115,   116,   117,    -1,    -1,
    1308,  1309,    -1,  1050,    -1,    -1,    -1,    -1,  1316,  1056,
      -1,    -1,    -1,    -1,    -1,  1062,    -1,  1064,  1065,    -1,
      -1,    -1,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,  1350,    78,  1091,     7,    -1,    -1,    83,    84,
      -1,    86,    87,    88,    -1,    -1,    -1,    92,    -1,  1106,
    1368,    -1,  1370,  1110,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,  1387,
      -1,    -1,  1390,    -1,    -1,    -1,    -1,    -1,    -1,  1397,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1410,    -1,    -1,    -1,    -1,  1415,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,  1431,    -1,    -1,    -1,   179,    -1,    -1,
    1438,    -1,  1440,     8,  1442,    -1,    -1,    -1,  1185,    -1,
      -1,    -1,    -1,    -1,  1452,    -1,    -1,    -1,  1456,  1457,
    1458,  1459,  1460,   188,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,  1475,  1476,   179,
      -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1490,    -1,    -1,    -1,  1494,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,  1260,    -1,    -1,  1524,   179,    -1,    -1,
      -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,  1536,    -1,
    1277,    -1,    -1,    -1,    -1,  1543,    -1,  1284,  1546,    -1,
    1287,  1549,    -1,    -1,  1291,  1553,    -1,    -1,    -1,  1557,
      -1,  1559,  1560,  1561,  1562,  1563,    -1,    -1,    -1,    -1,
      -1,    -1,  1570,  1310,    -1,  1573,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,  1331,   179,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,  1610,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,  1365,  1627,
    1628,  1629,  1630,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     8,    -1,    -1,    -1,
      -1,  1669,  1670,  1671,  1672,    45,    46,  1414,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    -1,  1430,    -1,    65,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
    1447,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    52,
      53,    -1,    55,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,  1506,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   185,    -1,   187,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,  1572,   139,   179,    -1,    -1,
    1577,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,   180,    -1,   182,
      -1,   184,   185,    -1,   187,    -1,   189,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,  1658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      87,    88,    -1,    -1,    -1,    92,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,     8,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,     3,     4,   185,
      -1,   187,   188,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,   188,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   145,
      -1,    -1,   179,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,   188,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    52,    53,    -1,    55,    -1,    57,    58,    59,
      -1,    -1,    -1,    12,    13,    65,    66,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    87,    88,
      -1,    -1,    -1,    92,    -1,   145,   146,   147,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,    -1,    -1,    -1,   175,   125,   126,   127,    -1,
     180,    -1,     3,     4,     5,   185,    -1,   187,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    48,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    57,    58,    59,   188,
      -1,    -1,    -1,    -1,    65,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    78,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,   180,
      -1,     3,     4,     5,   185,    -1,   187,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,     8,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   188,    -1,    -1,
      52,    53,    -1,    55,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    65,    66,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    75,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,    -1,    -1,    87,
     152,   153,   154,   155,   156,    -1,    94,    95,    96,    97,
      98,    -1,    -1,    -1,   102,    -1,    -1,   105,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,   180,    -1,
      -1,    -1,    -1,   185,    -1,   187,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,   145,    -1,    -1,
      -1,    -1,    -1,     8,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,   180,    -1,     3,     4,     5,   185,    -1,   187,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    52,    53,    -1,    55,    -1,    57,    58,
      59,    -1,     3,     4,     5,    -1,    65,    66,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    53,    -1,    55,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    65,    66,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   145,   146,   147,   179,    -1,    -1,
      -1,   152,   153,   154,   155,   156,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,   180,
      -1,     3,     4,    -1,   185,    -1,   187,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    87,    88,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,   180,    -1,
       3,     4,    -1,   185,    -1,   187,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    48,   188,    -1,    12,    13,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,   102,
      -1,    -1,   105,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,    83,
      84,    -1,    86,    87,    88,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,   180,    -1,     3,
       4,    -1,   185,    -1,   187,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    -1,    -1,    -1,   102,    -1,
      -1,   105,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,
     154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,   180,    -1,     3,     4,
      -1,   185,    -1,   187,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,
     155,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,   180,    -1,     3,     4,    -1,
     185,    -1,   187,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,   180,    -1,     3,     4,     5,   185,
      -1,   187,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    -1,    55,    -1,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,    -1,    -1,    87,   152,   153,   154,   155,   156,
      -1,    94,    95,    96,    97,    98,    -1,    -1,    -1,   102,
      -1,    -1,   105,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,   180,    -1,    -1,    -1,    -1,   185,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,   188,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,    -1,
      -1,    -1,   175,     3,     4,    -1,    -1,   180,    -1,     9,
      10,    11,   185,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    57,    58,    59,
      -1,     9,    10,    11,    -1,    65,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    -1,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   188,    -1,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,     0,     1,
      -1,    -1,     4,    -1,   152,   153,   154,   155,   156,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,   180,    -1,    -1,    37,    38,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    64,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,   119,     4,    -1,
      -1,    -1,   124,   125,   126,   127,    12,    13,   130,    -1,
     132,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    54,    -1,
      56,    -1,    -1,    -1,    60,    61,    -1,    63,    64,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,    -1,   130,    -1,   132,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   188,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   181,    -1,   183,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,   183,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   183,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,   183,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,   183,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,   183,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
      -1,    -1,   183,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,    -1,    -1,   183,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   183,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,   183,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   183,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,   183,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,
     183,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,    -1,    -1,   183,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
     181,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,   181,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,   181,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,   181,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
     181,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,   181,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,   181,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,   181,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,   181,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,    -1,
     181,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,   179,
      -1,   181,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,   181,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,   179,    -1,   181,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,   181,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,   179,    -1,   181,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,   179
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   191,   192,     6,     0,     4,    12,    13,    37,
      38,    49,    50,    51,    54,    56,    60,    61,    63,    64,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   111,
     112,   113,   119,   124,   125,   126,   127,   130,   132,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     148,   149,   150,   151,   193,   195,   196,   216,   233,   234,
     237,   238,   239,   240,   241,   242,   243,   264,   265,   266,
     267,   285,   286,     3,     4,     5,     9,    10,    11,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    52,    53,    55,    57,    58,    59,    65,    66,   139,
     145,   146,   147,   152,   153,   154,   155,   156,   170,   171,
     175,   180,   182,   184,   185,   187,   189,   214,   268,   269,
     281,   282,   285,   286,    13,    73,   180,   180,     6,   187,
       6,     6,     6,   180,     6,     6,   182,   182,   180,   187,
     180,   180,     4,   180,   187,   180,   180,     4,   187,   180,
     180,    77,    73,    73,     6,   187,    67,    70,    73,    73,
      73,    70,    73,    75,    75,    67,    70,    73,    75,    70,
      73,    75,    70,    73,   180,    70,   130,   143,   144,   187,
     170,   171,   180,   187,   271,   272,   271,   187,    67,    70,
      73,   187,   271,     4,    67,    71,    83,    73,    75,    73,
      70,     4,   139,   187,     4,     6,    67,    70,    73,    70,
      73,     4,     4,     4,     4,     5,    36,    67,    70,    73,
      75,    87,   171,   180,   187,   234,   243,   268,   274,   275,
     276,   285,   286,     4,   180,   180,   180,     4,   187,   278,
       4,   180,   180,     6,     6,   182,     4,   285,   286,     4,
       5,   187,     5,   187,     4,   268,     6,   180,   187,   180,
     182,   189,   214,     7,   157,   158,   159,   160,   177,   178,
     212,   213,     4,   182,   184,   182,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   180,   180,   180,   180,   180,   214,   180,   214,   214,
     214,     7,   180,   180,   180,   180,   180,   268,   268,   268,
     268,   183,   268,     4,   130,   131,   286,     4,   234,   235,
     236,   187,   187,     6,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   179,   187,
       6,   182,   213,     6,   268,     4,   281,   282,   286,   281,
     268,   281,   284,   218,   221,   268,   171,   268,   276,   277,
     268,   268,   180,   268,   277,   268,   268,   180,   277,   268,
     268,   274,   180,   187,   277,   275,   275,   275,   180,   180,
     275,   275,   275,   180,   180,   180,   180,   180,   180,   180,
     180,   274,   268,     4,   274,   278,   187,   187,   271,   271,
     271,   268,   268,   170,   171,   187,   187,   271,   187,   187,
     187,   170,   171,   180,   236,   271,   187,   180,   187,   180,
     180,   180,   275,   275,   274,   180,     4,     6,   182,   182,
     236,     6,   187,   187,   187,   275,   275,   182,   182,   182,
     182,   184,   214,   182,     5,   133,   187,     5,   133,     5,
     133,     5,   133,    67,    70,    73,    75,   187,   268,   276,
     268,   188,   277,     8,   172,     6,   182,   214,     6,   268,
     268,   268,   184,   268,   187,   133,   268,   268,   268,     6,
       6,   236,     6,   236,   182,     6,   274,   274,   183,   268,
     187,   187,   282,   274,     6,   182,   268,     4,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     284,   281,   284,   281,   281,   281,   281,   281,   268,   284,
     281,   268,   282,   268,   281,   281,   281,   286,   282,   181,
       7,   212,   183,     7,   212,   213,   184,     7,   182,   188,
      67,    70,    73,    75,   233,   268,   277,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   197,   268,     6,   182,   184,   181,   186,   181,
     186,   186,   181,   186,   183,   186,   217,   183,   217,   181,
     172,   186,   188,   181,   181,   268,   181,   188,   181,   181,
     268,   188,   181,   181,     7,   268,   268,   188,     6,     6,
       6,   268,   268,     7,     7,   261,   261,   268,   227,   268,
     282,   228,   268,   282,   229,   268,   282,   230,   268,   282,
     268,   268,   268,     7,   187,   181,     6,   187,   236,   236,
     186,   186,   186,   271,   271,   235,   235,   186,   268,   268,
     268,   268,   247,   186,   236,   268,   268,   268,   268,   268,
       7,   262,     6,     7,   268,     6,   268,   268,   188,   277,
     277,   277,     6,     6,   268,   268,   268,   268,     4,   181,
     183,   187,   215,   286,    49,   268,    49,    49,    49,     5,
     187,     5,   187,     5,   187,     5,   187,   277,   181,   188,
     268,   187,   268,   276,   187,   215,   181,   181,   181,   130,
     186,   236,   187,     8,   181,   183,   188,   188,   181,   186,
     188,   212,   183,   268,   277,     6,     6,   268,   183,   213,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   186,   215,   215,   215,   215,   215,   215,   215,   186,
     186,   186,   215,   186,   215,   215,   181,   181,   186,   186,
     186,   186,   181,   215,   270,   283,     6,   186,   181,   186,
     181,   181,   212,   274,   184,   212,   213,   282,   268,     6,
       4,     4,   187,   279,   183,   187,   187,   187,   187,   188,
     188,     8,     4,   120,   121,   122,   123,   188,   200,   204,
     207,   209,   210,   183,   268,     4,     6,   167,   194,   277,
       6,   277,   268,     6,   281,     6,   286,     6,   281,     7,
     268,   276,   133,     7,     7,   181,     7,   133,     7,     7,
     181,   133,     7,     7,   268,   181,   188,   187,   181,   181,
     268,   274,     4,   260,     6,   181,   181,   181,   181,   181,
     181,   181,   181,   274,   277,   184,   236,   188,   188,   271,
     268,   268,   188,   188,   268,   271,   186,   186,   186,    90,
     100,   108,   109,   110,   114,   115,   116,   117,   257,   258,
     271,   188,   244,   181,   188,   181,   181,   181,   268,     6,
     268,   181,   183,   183,   188,   188,   188,   183,   183,   186,
     183,   277,   183,   187,   188,   187,   187,   187,   277,   277,
     277,   277,   188,     8,   277,   277,     7,     7,     7,   184,
     268,   188,   268,   268,     7,   184,   187,   274,     6,   274,
     212,   213,   188,   188,   183,   184,   213,   281,   268,   268,
     268,   268,   277,   281,   281,   281,   282,   223,   225,   268,
     281,   268,     6,     4,   130,   131,   268,     6,     6,     6,
       7,   182,   278,   280,     6,   277,   277,   277,   277,   215,
     268,   201,   180,   180,   187,   211,     6,   213,   183,   167,
     281,   181,   181,   186,     7,   271,    73,    75,   274,   274,
       7,   274,    73,    75,   274,   274,     7,    75,   274,   274,
       6,     7,     7,   277,     7,     7,    90,   259,     6,     7,
       7,     7,     7,     7,     7,     7,     7,     6,   188,     4,
     188,   186,   186,   186,   188,   188,   271,   271,   271,     4,
       6,   187,     6,   180,     6,   118,     6,   118,     6,   118,
       6,   118,   188,   258,   186,   257,     7,     6,     7,     7,
       7,     6,   187,     6,     6,     6,    73,   268,     6,     6,
     268,   184,   188,   268,   268,   268,   268,   188,   188,   188,
     188,   268,   188,   188,   274,   274,   274,     4,   186,     8,
       8,   181,     4,     4,   274,   188,     6,   268,     6,   215,
       6,     4,     6,   215,   215,   215,   215,   215,   186,   181,
     181,   186,   186,   215,   224,   186,   215,   226,   181,   181,
       6,     7,   212,   213,   184,     7,     6,   278,   268,   186,
     188,   188,   188,   188,   188,   212,   180,   268,   268,   273,
     274,   187,   184,     6,     6,   194,     6,   268,   187,   268,
     282,     6,   187,   187,    83,   232,   232,   274,     6,   187,
     187,     6,     6,   274,   187,     6,     6,     5,   274,   188,
     274,   274,     4,     6,   274,   274,   274,   274,   274,   274,
     274,   274,     7,     6,     7,   268,   268,   268,   187,   187,
     186,   188,   186,   188,   186,   188,   182,   268,   274,   268,
       6,     6,     6,     6,   268,   271,   188,     5,   187,   274,
     187,   187,   187,   274,   277,   187,     6,   183,     4,   215,
     186,   186,   186,   186,   215,     6,     6,   129,   268,   268,
     268,     6,     6,     7,   186,     6,     6,   212,   213,   281,
     282,     4,     4,   282,   268,     6,     4,   279,     6,   183,
     278,     6,     6,     6,     6,   274,   198,   268,   186,   186,
     186,   188,   199,   268,     4,   281,   186,   268,   282,   268,
     268,   271,     6,     6,     6,   268,   268,     6,   268,     5,
       6,   187,     6,   133,   231,   268,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   268,   268,   282,   188,   181,
     186,   188,   235,   235,   271,     6,   248,   271,     6,   249,
     271,     6,   250,   268,   188,   186,   181,   188,   186,     6,
     171,   271,     6,   273,   271,   271,     6,   188,   268,     6,
     268,   268,   268,   268,   274,   186,   188,     8,   188,   181,
     187,   268,   282,   274,   274,   181,   215,   187,   274,   282,
     187,   268,   282,     6,     6,     7,     6,   184,     6,   181,
     186,   268,   268,   274,   187,   186,   188,     6,   268,   219,
     220,   188,   188,   188,   188,   188,     5,   273,    71,     6,
     187,   187,     6,     6,   187,   268,   188,   188,   186,   187,
     186,   187,   186,   187,   183,     6,   274,     7,   187,   268,
     186,   188,   186,   186,     6,   188,   186,   186,   186,   186,
     128,   268,   268,   277,     6,     6,   188,     6,   222,   268,
     284,   278,   131,   202,   268,   186,   186,   273,   268,     6,
     186,   223,   225,     6,     6,     6,     6,     6,     6,   188,
     187,   273,   277,   235,   186,   188,   268,   271,   257,   268,
     271,   257,   268,   271,   257,     6,   186,   188,   274,   236,
     188,   271,     6,   277,   271,   268,   268,   268,   268,   268,
     188,   188,   188,     6,   186,   188,     7,   188,     6,   187,
     268,   268,   188,   268,   188,   188,   187,   268,   188,   188,
     188,   268,   188,   186,   188,   188,   186,   188,   188,   186,
     188,   274,     6,    90,   188,   245,   187,   186,   188,   186,
     186,   186,   186,   186,     6,     6,   268,   282,   199,   181,
     186,     6,   187,   186,   268,   188,     6,    90,   263,   188,
       6,   251,   268,     6,     6,   252,   268,     6,     6,   253,
     268,     6,   188,   268,   257,   236,   277,     6,   271,   277,
     268,   268,   268,   268,     7,   188,   205,   268,   273,   268,
     186,   274,     6,   187,   188,   187,   188,   187,   188,     6,
       6,   188,   188,   246,   188,   186,   188,   186,   186,   186,
     186,   282,     6,   187,   181,   188,   188,   268,   257,     6,
     254,   257,     6,   255,   257,     6,   256,   257,     6,   277,
       6,   268,   268,   268,   268,   203,   281,   208,   187,     6,
     188,   188,   187,   188,   187,   188,   187,   188,   188,   186,
     186,   186,   186,   186,   188,   187,   273,     6,     6,   257,
       6,   257,     6,   257,     6,   268,   268,   268,   268,   281,
       6,   206,   281,   188,   188,   188,   188,   188,   188,   188,
     188,   186,   188,     6,     6,     6,     6,   281,     6
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1787 of yacc.c  */
#line 184 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 195 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 196 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 197 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 198 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 199 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 200 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 201 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 202 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 214 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 218 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 225 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 230 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 235 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
      FILE *fp = Fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
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

  case 26:
/* Line 1787 of yacc.c  */
#line 249 "Gmsh.y"
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
    }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 262 "Gmsh.y"
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
    }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 275 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(8) - (9)].c));
	FILE *fp = Fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
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
/* Line 1787 of yacc.c  */
#line 303 "Gmsh.y"
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
/* Line 1787 of yacc.c  */
#line 317 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 330 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 343 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (8)].c), "View")){
	int index = (int)(yyvsp[(4) - (8)].d), index2 = (int)(yyvsp[(6) - (8)].d);
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free((yyvsp[(2) - (8)].c));
    }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 361 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 375 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 377 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 382 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 384 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 389 "Gmsh.y"
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

  case 44:
/* Line 1787 of yacc.c  */
#line 493 "Gmsh.y"
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

  case 45:
/* Line 1787 of yacc.c  */
#line 503 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 512 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 519 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 529 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 538 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 547 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 554 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 564 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 572 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 582 "Gmsh.y"
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

  case 55:
/* Line 1787 of yacc.c  */
#line 601 "Gmsh.y"
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

  case 56:
/* Line 1787 of yacc.c  */
#line 620 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 626 "Gmsh.y"
    {
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 633 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 634 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 635 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 641 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 642 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 648 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 648 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 649 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 658 "Gmsh.y"
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

  case 72:
/* Line 1787 of yacc.c  */
#line 719 "Gmsh.y"
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

  case 73:
/* Line 1787 of yacc.c  */
#line 748 "Gmsh.y"
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

  case 74:
/* Line 1787 of yacc.c  */
#line 777 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 782 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 787 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 792 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 799 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 806 "Gmsh.y"
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

  case 80:
/* Line 1787 of yacc.c  */
#line 821 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 826 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 831 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 840 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 846 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 855 "Gmsh.y"
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

  case 86:
/* Line 1787 of yacc.c  */
#line 873 "Gmsh.y"
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

  case 87:
/* Line 1787 of yacc.c  */
#line 891 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 900 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 912 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 917 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 925 "Gmsh.y"
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

  case 92:
/* Line 1787 of yacc.c  */
#line 945 "Gmsh.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 968 "Gmsh.y"
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

  case 94:
/* Line 1787 of yacc.c  */
#line 979 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 987 "Gmsh.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 1009 "Gmsh.y"
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

  case 97:
/* Line 1787 of yacc.c  */
#line 1032 "Gmsh.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 1058 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 1079 "Gmsh.y"
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

  case 100:
/* Line 1787 of yacc.c  */
#line 1091 "Gmsh.y"
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

  case 104:
/* Line 1787 of yacc.c  */
#line 1109 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 1118 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 1127 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 1129 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val(1, (yyvsp[(6) - (9)].d));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
    }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 1139 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1148 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 1150 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1164 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1172 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 1178 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 1190 "Gmsh.y"
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

  case 118:
/* Line 1787 of yacc.c  */
#line 1201 "Gmsh.y"
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

  case 119:
/* Line 1787 of yacc.c  */
#line 1216 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 1232 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1240 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 1249 "Gmsh.y"
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
    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1267 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1271 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 1280 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1284 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1293 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1297 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 1306 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1310 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1323 "Gmsh.y"
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

  case 135:
/* Line 1787 of yacc.c  */
#line 1335 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1339 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1349 "Gmsh.y"
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

  case 138:
/* Line 1787 of yacc.c  */
#line 1372 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1388 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v){
	  v->lc = (yyvsp[(5) - (6)].d);
        }
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

  case 140:
/* Line 1787 of yacc.c  */
#line 1411 "Gmsh.y"
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1429 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1450 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1468 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1498 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1528 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1546 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1565 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1591 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1609 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1627 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1646 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1664 "Gmsh.y"
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

  case 153:
/* Line 1787 of yacc.c  */
#line 1703 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1709 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1715 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1722 "Gmsh.y"
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

  case 157:
/* Line 1787 of yacc.c  */
#line 1747 "Gmsh.y"
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

  case 158:
/* Line 1787 of yacc.c  */
#line 1772 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1789 "Gmsh.y"
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
        // Added by Trevor Strickler
	setSurfaceGeneratrices(s, (List_T*) 0 );
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1809 "Gmsh.y"
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
        // Added by Trevor Strickler
        setSurfaceGeneratrices(s, (List_T*) 0 );

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

  case 161:
/* Line 1787 of yacc.c  */
#line 1842 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1862 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1880 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1897 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1913 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1934 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1939 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1944 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1949 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1954 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1959 "Gmsh.y"
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

  case 172:
/* Line 1787 of yacc.c  */
#line 1982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1988 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1998 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1999 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2004 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2008 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2012 "Gmsh.y"
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

  case 179:
/* Line 1787 of yacc.c  */
#line 2035 "Gmsh.y"
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

  case 180:
/* Line 1787 of yacc.c  */
#line 2058 "Gmsh.y"
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

  case 181:
/* Line 1787 of yacc.c  */
#line 2081 "Gmsh.y"
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

  case 182:
/* Line 1787 of yacc.c  */
#line 2109 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2130 "Gmsh.y"
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
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i));
      List_Delete((yyvsp[(8) - (10)].l));
#endif
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 2157 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2178 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2199 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2219 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2331 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2350 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2389 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2497 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 2506 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 2512 "Gmsh.y"
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

  case 194:
/* Line 1787 of yacc.c  */
#line 2527 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
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

  case 195:
/* Line 1787 of yacc.c  */
#line 2555 "Gmsh.y"
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

  case 196:
/* Line 1787 of yacc.c  */
#line 2572 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 2581 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 2595 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2601 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2607 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2616 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2625 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2634 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2648 "Gmsh.y"
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall")){
	SystemCall((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall")){
	SystemCall((yyvsp[(2) - (3)].c), true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName")){
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateSingleDir(tmp);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "OnelabRun")){
        Msg::RunOnelabClient((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2704 "Gmsh.y"
    {
      int n = List_Nbr((yyvsp[(3) - (5)].l));
      if(n == 1){
        char *s; List_Read((yyvsp[(3) - (5)].l), 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read((yyvsp[(3) - (5)].l), 0, &s); List_Read((yyvsp[(3) - (5)].l), 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2722 "Gmsh.y"
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

  case 207:
/* Line 1787 of yacc.c  */
#line 2739 "Gmsh.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 2754 "Gmsh.y"
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

  case 209:
/* Line 1787 of yacc.c  */
#line 2773 "Gmsh.y"
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

  case 210:
/* Line 1787 of yacc.c  */
#line 2785 "Gmsh.y"
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

  case 211:
/* Line 1787 of yacc.c  */
#line 2809 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 2813 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 2818 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2825 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2831 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2836 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2842 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2850 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2854 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2858 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2864 "Gmsh.y"
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (16)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (16)].l), i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yyerror("Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (16)].l)); i++){
          double d;
          List_Read((yyvsp[(6) - (16)].l), i, &d);
          LevelSet *l = FindLevelSet((int)d);
          if(l) f.push_back(l->ls);
          else yymsg(0, "Unknown Levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yyerror("Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[(9) - (16)].l)) != f.size()){
            yyerror("Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr((yyvsp[(9) - (16)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++){
              List_T *l = *(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)(yyvsp[(12) - (16)].d);
            bool meshAll = ((yyvsp[(14) - (16)].d) == 0) ? false : true;
            GModel::current()->importGEOInternals();
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete((yyvsp[(3) - (16)].l));
      List_Delete((yyvsp[(6) - (16)].l));
      for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i));
      List_Delete((yyvsp[(9) - (16)].l));
      CTX::instance()->lock = lock;
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2918 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2931 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 224:
/* Line 1787 of yacc.c  */
#line 2948 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 225:
/* Line 1787 of yacc.c  */
#line 2965 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 226:
/* Line 1787 of yacc.c  */
#line 2986 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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

  case 227:
/* Line 1787 of yacc.c  */
#line 3007 "Gmsh.y"
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
	  gmshsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 3042 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 3050 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 3056 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3063 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3067 "Gmsh.y"
    {
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3092 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3100 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3106 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3114 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3120 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3128 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3134 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3142 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3148 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3156 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3163 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3170 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3177 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3184 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3191 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3205 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3212 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3219 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3225 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3232 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3238 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3251 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3258 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3264 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3271 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3277 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3284 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3297 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3310 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3323 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3329 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3340 "Gmsh.y"
    {
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3343 "Gmsh.y"
    {
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3349 "Gmsh.y"
    {
      int n = (int)fabs((yyvsp[(3) - (5)].d));
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
        extr.mesh.hLayer.push_back(1.);
      }
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3361 "Gmsh.y"
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

  case 275:
/* Line 1787 of yacc.c  */
#line 3381 "Gmsh.y"
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

  case 276:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3409 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3413 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3417 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3421 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3427 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3433 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3437 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3441 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3445 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3449 "Gmsh.y"
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

  case 287:
/* Line 1787 of yacc.c  */
#line 3468 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3480 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3484 "Gmsh.y"
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

  case 290:
/* Line 1787 of yacc.c  */
#line 3499 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3503 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
	(yyval.i) = -1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateRight"))
	(yyval.i) = 2;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateLeft"))
	(yyval.i) = -2;
      else // "Alternate" -> "Alternate Right"
	(yyval.i) = 2;
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3519 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3523 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3528 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 3532 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3542 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3549 "Gmsh.y"
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
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3605 "Gmsh.y"
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
    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 3675 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3680 "Gmsh.y"
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
    }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3747 "Gmsh.y"
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
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 3783 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3791 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3834 "Gmsh.y"
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
    }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3873 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3893 "Gmsh.y"
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
    }
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 3921 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (13)].l)) != List_Nbr((yyvsp[(10) - (13)].l))){
	yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (13)].l)), List_Nbr((yyvsp[(5) - (13)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (13)].d);
        int j_slave = (int)(yyvsp[(3) - (13)].d);
        Surface *s_slave = FindSurface(abs(j_slave));
	std::vector<double> transfo;
	for(int i = 0; i < List_Nbr((yyvsp[(12) - (13)].l)); i++){
	  double d;
	  List_Read((yyvsp[(12) - (13)].l), i, &d);
	  transfo.push_back(d);
	}
        if(s_slave){
	  GModel::current()->getGEOInternals()->periodicFaces[j_slave] = j_master;
          for (int i = 0; i < List_Nbr((yyvsp[(5) - (13)].l)); i++){
            double dm, ds;
            List_Read((yyvsp[(5) - (13)].l), i, &ds);
            List_Read((yyvsp[(10) - (13)].l), i, &dm);
	    GModel::current()->getGEOInternals()->periodicEdges[(int)ds] = (int)dm;
            s_slave->edgeCounterparts[(int)ds] = (int)dm;
            s_slave->affineTransform = transfo;
          }
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(abs(j_slave));
          if(gf){
            gf->setMeshMaster(j_master);
            for (int i = 0; i < List_Nbr((yyvsp[(5) - (13)].l)); i++){
              double dm, ds;
              List_Read((yyvsp[(5) - (13)].l), i, &ds);
              List_Read((yyvsp[(10) - (13)].l), i, &dm);
              gf->edgeCounterparts[(int)ds] = (int)dm;
	      gf->affineTransform = transfo;
	      GEdge *ges = GModel::current()->getEdgeByTag(abs((int)ds));
	      ges->setMeshMaster((int)dm);
            }
          }
          else yymsg(0, "Unknown surface %d", j_slave);
        }
      }
      List_Delete((yyvsp[(5) - (13)].l));
      List_Delete((yyvsp[(10) - (13)].l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3969 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded point is a .geo point
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3997 "Gmsh.y"
    {
      Surface *s = FindSurface((int)(yyvsp[(8) - (10)].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[(3) - (10)].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[(8) - (10)].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iCurve = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
            if(!ge){ // sync model in case the embedded line is a .geo line
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iCurve);
            }
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4025 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 4029 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 4033 "Gmsh.y"
    {
      Volume *v = FindVolume((int)(yyvsp[(8) - (10)].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[(3) - (10)].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[(8) - (10)].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
            double d;
            List_Read((yyvsp[(3) - (10)].l), i, &d);
            int iSurface = (int)d;
            GFace *gf = GModel::current()->getFaceByTag(iSurface);
            if(!gf){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gf = GModel::current()->getFaceByTag(iSurface);
            }
            if(gf)
              gr->addEmbeddedFace(gf);
            else
              yymsg(0, "Unknown surface %d", iSurface);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)(yyvsp[(8) - (10)].d));
      }
    }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 4061 "Gmsh.y"
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
    }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 4100 "Gmsh.y"
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
              yymsg(1, "Unknown line %d", (int)d);
          }
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 4139 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::viter it = GModel::current()->firstVertex();
            it != GModel::current()->lastVertex(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GVertex *gv = GModel::current()->getVertexByTag((int)d);
          if(gv){
            gv->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown point %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 4160 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GEdge *ge = GModel::current()->getEdgeByTag((int)d);
          if(ge){
            ge->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown line %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 4181 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          GFace *gf = GModel::current()->getFaceByTag((int)d);
          if(gf){
            gf->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown surface %d", (int)d);
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 4208 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4212 "Gmsh.y"
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

  case 321:
/* Line 1787 of yacc.c  */
#line 4222 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4256 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4257 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 4258 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 4263 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4269 "Gmsh.y"
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
    }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4281 "Gmsh.y"
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
    }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4299 "Gmsh.y"
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
    }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 4327 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4328 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4329 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4330 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4331 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4332 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4335 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4341 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4342 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4348 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4350 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4352 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4353 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4354 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4355 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4356 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4357 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4358 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4359 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4360 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4361 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4362 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4363 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4364 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4365 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4366 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4367 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4368 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4370 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4371 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4372 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4373 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4382 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4383 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4384 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4385 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4386 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4387 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4388 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4389 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4390 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4391 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4396 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4398 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4404 "Gmsh.y"
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

  case 384:
/* Line 1787 of yacc.c  */
#line 4421 "Gmsh.y"
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

  case 385:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
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

  case 386:
/* Line 1787 of yacc.c  */
#line 4457 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4462 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
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

  case 389:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4497 "Gmsh.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 4515 "Gmsh.y"
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

  case 392:
/* Line 1787 of yacc.c  */
#line 4536 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 4541 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 4546 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4556 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4566 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4571 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4580 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4585 "Gmsh.y"
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
    }
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 4612 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4616 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4624 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 4635 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4639 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4647 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4654 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4659 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4666 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4671 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4675 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4680 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4692 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4703 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4707 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4719 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4727 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4735 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4742 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[(3) - (4)].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
        GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[(3) - (4)].d));
        if(gv){
          double x = gv->x(), y = gv->y(), z = gv->z();
          List_Add((yyval.l), &x);
          List_Add((yyval.l), &y);
          List_Add((yyval.l), &z);
        }
        else{
          yymsg(0, "Unknown point '%d'", (int)(yyvsp[(3) - (4)].d));
          double d = 0.0;
          List_Add((yyval.l), &d);
          List_Add((yyval.l), &d);
          List_Add((yyval.l), &d);
        }
      }
      else{
	List_Add((yyval.l), &v->Pos.X);
	List_Add((yyval.l), &v->Pos.Y);
	List_Add((yyval.l), &v->Pos.Z);
      }
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4781 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4785 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4789 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4793 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4797 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4801 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4805 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4809 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4813 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(0, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4842 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(1, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4871 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(2, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4900 "Gmsh.y"
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
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(3, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add((yyval.l), &d);
            }
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4930 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 4943 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 4956 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4969 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4981 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 4991 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 5001 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5013 "Gmsh.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 5025 "Gmsh.y"
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

  case 445:
/* Line 1787 of yacc.c  */
#line 5037 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5055 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5076 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 448:
/* Line 1787 of yacc.c  */
#line 5081 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 5085 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 450:
/* Line 1787 of yacc.c  */
#line 5089 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 451:
/* Line 1787 of yacc.c  */
#line 5101 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 5105 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5117 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5124 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5134 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5138 "Gmsh.y"
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

  case 457:
/* Line 1787 of yacc.c  */
#line 5153 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5158 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5165 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5169 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5182 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5190 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5201 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5205 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5213 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5219 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5227 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5235 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5250 "Gmsh.y"
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

  case 470:
/* Line 1787 of yacc.c  */
#line 5264 "Gmsh.y"
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

  case 471:
/* Line 1787 of yacc.c  */
#line 5278 "Gmsh.y"
    {
      std::string input = (yyvsp[(3) - (8)].c);
      std::string substr_old = (yyvsp[(5) - (8)].c);
      std::string substr_new = (yyvsp[(7) - (8)].c);
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      (yyval.c) = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy((yyval.c), ret.c_str());
      Free((yyvsp[(3) - (8)].c));
      Free((yyvsp[(5) - (8)].c));
      Free((yyvsp[(7) - (8)].c));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5290 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
        if(i != List_Nbr((yyvsp[(3) - (4)].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5306 "Gmsh.y"
    {
      if((yyvsp[(3) - (8)].d)){
        (yyval.c) = (yyvsp[(5) - (8)].c);
        Free((yyvsp[(7) - (8)].c));
      }
      else{
        (yyval.c) = (yyvsp[(7) - (8)].c);
        Free((yyvsp[(5) - (8)].c));
      }
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5317 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5321 "Gmsh.y"
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
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5340 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5347 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5349 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5360 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5365 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5371 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5380 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5393 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5396 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11368 "Gmsh.tab.cpp"
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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


/* Line 2050 of yacc.c  */
#line 5400 "Gmsh.y"


void assignVariable(const std::string &name, int index, int assignType,
                    double value)
{
  if(!gmsh_yysymbols.count(name)){
    if(!assignType){
      gmsh_yysymbol &s(gmsh_yysymbols[name]);
      s.list = true;
      s.value.resize(index + 1, 0.);
      s.value[index] = value;
    }
    else
      yymsg(0, "Unknown variable '%s'", name.c_str());
  }
  else{
    gmsh_yysymbol &s(gmsh_yysymbols[name]);
    if(s.list){
      if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
      switch(assignType){
      case 0 : s.value[index] = value; break;
      case 1 : s.value[index] += value; break;
      case 2 : s.value[index] -= value; break;
      case 3 : s.value[index] *= value; break;
      case 4 :
        if(value) s.value[index] /= value;
        else yymsg(0, "Division by zero in '%s[%d] /= %g'",
                   name.c_str(), index, value);
        break;
      }
    }
    else
      yymsg(0, "Variable '%s' is not a list", name.c_str());
  }
}

void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values)
{
  if(List_Nbr(indices) != List_Nbr(values)){
    yymsg(0, "Incompatible array dimensions in affectation");
  }
  else{
    if(!gmsh_yysymbols.count(name)){
      if(!assignType){
        gmsh_yysymbol &s(gmsh_yysymbols[name]);
        s.list = true;
        for(int i = 0; i < List_Nbr(indices); i++){
          int index = (int)(*(double*)List_Pointer(indices, i));
          s.value.resize(index + 1, 0.);
          s.value[index] = *(double*)List_Pointer(values, i);
        }
      }
      else
        yymsg(0, "Unknown variable '%s'", name.c_str());
    }
    else{
      gmsh_yysymbol &s(gmsh_yysymbols[name]);
      if(s.list){
        for(int i = 0; i < List_Nbr(indices); i++){
          int index = (int)(*(double*)List_Pointer(indices, i));
          double d = *(double*)List_Pointer(values, i);
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch(assignType){
          case 0 : s.value[index] = d; break;
          case 1 : s.value[index] += d; break;
          case 2 : s.value[index] -= d; break;
          case 3 : s.value[index] *= d; break;
          case 4 :
            if(d) s.value[index] /= d;
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", name.c_str(), index, d);
            break;
          }
        }
      }
      else
        yymsg(0, "Variable '%s' is not a list", name.c_str());
    }
  }
}

void incrementVariable(const std::string &name, int index, double value)
{
  if(!gmsh_yysymbols.count(name))
    yymsg(0, "Unknown variable '%s'", name.c_str());
  else{
    gmsh_yysymbol &s(gmsh_yysymbols[name]);
    if(s.list){
      if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
      s.value[index] += value;
    }
    else
      yymsg(0, "Variable '%s' is not a list", name.c_str());
  }
}

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

void PrintParserSymbols(bool help, std::vector<std::string> &vec)
{
  if(help){
    vec.push_back("//");
    vec.push_back("// Numbers");
    vec.push_back("//");
  }
  for(std::map<std::string, gmsh_yysymbol>::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); it++){
    gmsh_yysymbol s(it->second);
    std::ostringstream sstream;
    sstream << it->first;
    if(s.list){
      sstream << "[] = {";
      for(unsigned int i = 0; i < s.value.size(); i++){
        if(i) sstream << ", ";
        sstream << s.value[i];
      }
      sstream << "}";
    }
    else
      sstream << " = " << s.value[0];
    sstream << ";";
    vec.push_back(sstream.str());
  }
  if(help){
    vec.push_back("//");
    vec.push_back("// Strings");
    vec.push_back("//");
  }
  for(std::map<std::string, std::string>::iterator it = gmsh_yystringsymbols.begin();
      it != gmsh_yystringsymbols.end(); it++){
    vec.push_back(it->first + " = \"" + it->second + "\";");
  }
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
  else{
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
}
