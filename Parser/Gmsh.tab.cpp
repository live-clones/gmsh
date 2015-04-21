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
     tFind = 300,
     tStrFind = 301,
     tStrCmp = 302,
     tStrChoice = 303,
     tTextAttributes = 304,
     tBoundingBox = 305,
     tDraw = 306,
     tSetChanged = 307,
     tToday = 308,
     tFixRelativePath = 309,
     tSyncModel = 310,
     tNewModel = 311,
     tOnelabAction = 312,
     tOnelabRun = 313,
     tCpu = 314,
     tMemory = 315,
     tTotalMemory = 316,
     tCreateTopology = 317,
     tCreateTopologyNoHoles = 318,
     tDistanceFunction = 319,
     tDefineConstant = 320,
     tUndefineConstant = 321,
     tDefineNumber = 322,
     tDefineString = 323,
     tSetNumber = 324,
     tSetString = 325,
     tPoint = 326,
     tCircle = 327,
     tEllipse = 328,
     tLine = 329,
     tSphere = 330,
     tPolarSphere = 331,
     tSurface = 332,
     tSpline = 333,
     tVolume = 334,
     tCharacteristic = 335,
     tLength = 336,
     tParametric = 337,
     tElliptic = 338,
     tRefineMesh = 339,
     tAdaptMesh = 340,
     tRelocateMesh = 341,
     tPlane = 342,
     tRuled = 343,
     tTransfinite = 344,
     tComplex = 345,
     tPhysical = 346,
     tCompound = 347,
     tPeriodic = 348,
     tUsing = 349,
     tPlugin = 350,
     tDegenerated = 351,
     tRecursive = 352,
     tRotate = 353,
     tTranslate = 354,
     tSymmetry = 355,
     tDilate = 356,
     tExtrude = 357,
     tLevelset = 358,
     tRecombine = 359,
     tSmoother = 360,
     tSplit = 361,
     tDelete = 362,
     tCoherence = 363,
     tIntersect = 364,
     tMeshAlgorithm = 365,
     tReverse = 366,
     tLayers = 367,
     tScaleLast = 368,
     tHole = 369,
     tAlias = 370,
     tAliasWithOptions = 371,
     tCopyOptions = 372,
     tQuadTriAddVerts = 373,
     tQuadTriNoNewVerts = 374,
     tQuadTriSngl = 375,
     tQuadTriDbl = 376,
     tRecombLaterals = 377,
     tTransfQuadTri = 378,
     tText2D = 379,
     tText3D = 380,
     tInterpolationScheme = 381,
     tTime = 382,
     tCombine = 383,
     tBSpline = 384,
     tBezier = 385,
     tNurbs = 386,
     tNurbsOrder = 387,
     tNurbsKnots = 388,
     tColor = 389,
     tColorTable = 390,
     tFor = 391,
     tIn = 392,
     tEndFor = 393,
     tIf = 394,
     tEndIf = 395,
     tExit = 396,
     tAbort = 397,
     tField = 398,
     tReturn = 399,
     tCall = 400,
     tFunction = 401,
     tShow = 402,
     tHide = 403,
     tGetValue = 404,
     tGetEnv = 405,
     tGetString = 406,
     tGetNumber = 407,
     tHomology = 408,
     tCohomology = 409,
     tBetti = 410,
     tSetOrder = 411,
     tExists = 412,
     tFileExists = 413,
     tGMSH_MAJOR_VERSION = 414,
     tGMSH_MINOR_VERSION = 415,
     tGMSH_PATCH_VERSION = 416,
     tGmshExecutableName = 417,
     tAFFECTDIVIDE = 418,
     tAFFECTTIMES = 419,
     tAFFECTMINUS = 420,
     tAFFECTPLUS = 421,
     tOR = 422,
     tAND = 423,
     tNOTEQUAL = 424,
     tEQUAL = 425,
     tGREATEROREQUAL = 426,
     tLESSOREQUAL = 427,
     UNARYPREC = 428,
     tMINUSMINUS = 429,
     tPLUSPLUS = 430
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
#line 402 "Gmsh.tab.cpp"
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
#line 430 "Gmsh.tab.cpp"

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
#define YYLAST   9388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  196
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  491
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1737

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   430

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   181,     2,   191,     2,   180,     2,     2,
     186,   187,   178,   176,   192,   177,   190,   179,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     172,     2,   173,   167,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   188,     2,   189,   185,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   193,     2,   194,   195,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   168,   169,   170,   171,   174,   175,   182,   183,
     184
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
     268,   274,   282,   290,   295,   302,   309,   317,   325,   333,
     343,   353,   357,   364,   371,   376,   383,   393,   400,   410,
     416,   425,   434,   446,   453,   463,   469,   477,   487,   497,
     509,   517,   527,   537,   538,   540,   541,   545,   551,   552,
     562,   568,   569,   579,   580,   584,   588,   594,   595,   598,
     602,   608,   612,   613,   616,   620,   624,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   647,   653,   654,   657,
     665,   674,   681,   689,   694,   702,   711,   720,   728,   736,
     748,   757,   766,   775,   784,   794,   798,   803,   814,   822,
     830,   839,   848,   861,   870,   879,   887,   896,   905,   911,
     923,   929,   939,   949,   954,   964,   974,   976,   978,   979,
     982,   989,   996,  1003,  1010,  1019,  1030,  1045,  1062,  1075,
    1084,  1093,  1100,  1115,  1120,  1127,  1134,  1138,  1143,  1149,
    1156,  1160,  1164,  1169,  1175,  1180,  1186,  1190,  1196,  1204,
    1212,  1216,  1224,  1228,  1231,  1234,  1237,  1240,  1243,  1259,
    1262,  1265,  1268,  1271,  1274,  1291,  1295,  1302,  1311,  1320,
    1331,  1333,  1336,  1338,  1342,  1347,  1349,  1355,  1367,  1381,
    1382,  1390,  1391,  1405,  1406,  1422,  1423,  1430,  1439,  1448,
    1457,  1470,  1483,  1496,  1511,  1526,  1541,  1542,  1555,  1556,
    1569,  1570,  1583,  1584,  1601,  1602,  1619,  1620,  1637,  1638,
    1657,  1658,  1677,  1678,  1697,  1699,  1702,  1708,  1716,  1726,
    1729,  1732,  1735,  1739,  1742,  1746,  1749,  1753,  1756,  1760,
    1770,  1777,  1778,  1782,  1783,  1785,  1786,  1789,  1790,  1793,
    1794,  1797,  1805,  1812,  1821,  1827,  1831,  1839,  1845,  1850,
    1857,  1864,  1878,  1889,  1900,  1911,  1922,  1933,  1938,  1943,
    1948,  1953,  1958,  1961,  1965,  1972,  1974,  1976,  1978,  1981,
    1987,  1995,  2006,  2008,  2012,  2015,  2018,  2021,  2025,  2029,
    2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,  2065,  2069,
    2073,  2077,  2083,  2088,  2093,  2098,  2103,  2108,  2113,  2118,
    2123,  2128,  2133,  2140,  2145,  2150,  2155,  2160,  2165,  2170,
    2175,  2182,  2189,  2196,  2201,  2203,  2205,  2207,  2209,  2211,
    2213,  2215,  2217,  2219,  2221,  2222,  2229,  2234,  2236,  2241,
    2246,  2251,  2256,  2261,  2264,  2270,  2276,  2280,  2287,  2292,
    2300,  2307,  2314,  2321,  2328,  2333,  2335,  2338,  2341,  2345,
    2349,  2361,  2371,  2379,  2387,  2389,  2393,  2395,  2397,  2400,
    2404,  2409,  2415,  2417,  2419,  2422,  2426,  2430,  2436,  2441,
    2444,  2447,  2450,  2453,  2457,  2461,  2465,  2469,  2475,  2481,
    2487,  2493,  2510,  2527,  2544,  2561,  2563,  2565,  2569,  2573,
    2578,  2585,  2592,  2594,  2596,  2600,  2604,  2614,  2622,  2624,
    2630,  2634,  2641,  2643,  2647,  2649,  2651,  2655,  2662,  2664,
    2666,  2668,  2670,  2675,  2682,  2687,  2692,  2697,  2702,  2711,
    2716,  2725,  2730,  2737,  2742,  2743,  2750,  2752,  2756,  2762,
    2768,  2770
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     197,     0,    -1,   198,    -1,     1,     6,    -1,    -1,   198,
     199,    -1,   202,    -1,   201,    -1,   222,    -1,   239,    -1,
     240,    -1,   244,    -1,   245,    -1,   246,    -1,   249,    -1,
     270,    -1,   271,    -1,   248,    -1,   247,    -1,   243,    -1,
     273,    -1,   173,    -1,   173,   173,    -1,    37,   186,   287,
     187,     6,    -1,    38,   186,   287,   187,     6,    -1,    37,
     186,   287,   187,   200,   287,     6,    -1,    37,   186,   287,
     192,   283,   187,     6,    -1,    38,   186,   287,   192,   283,
     187,     6,    -1,    37,   186,   287,   192,   283,   187,   200,
     287,     6,    -1,     4,   287,   193,   203,   194,     6,    -1,
     115,     4,   188,   274,   189,     6,    -1,   116,     4,   188,
     274,   189,     6,    -1,   117,     4,   188,   274,   192,   274,
     189,     6,    -1,    -1,   203,   206,    -1,   203,   210,    -1,
     203,   213,    -1,   203,   215,    -1,   203,   216,    -1,   274,
      -1,   204,   192,   274,    -1,   274,    -1,   205,   192,   274,
      -1,    -1,    -1,     4,   207,   186,   204,   187,   208,   193,
     205,   194,     6,    -1,   287,    -1,   209,   192,   287,    -1,
      -1,   124,   186,   274,   192,   274,   192,   274,   187,   211,
     193,   209,   194,     6,    -1,   287,    -1,   212,   192,   287,
      -1,    -1,   125,   186,   274,   192,   274,   192,   274,   192,
     274,   187,   214,   193,   212,   194,     6,    -1,   126,   193,
     279,   194,   193,   279,   194,     6,    -1,   126,   193,   279,
     194,   193,   279,   194,   193,   279,   194,   193,   279,   194,
       6,    -1,    -1,   127,   217,   193,   205,   194,     6,    -1,
       7,    -1,   166,    -1,   165,    -1,   164,    -1,   163,    -1,
     184,    -1,   183,    -1,   186,    -1,   188,    -1,   187,    -1,
     189,    -1,    65,   188,   224,   189,     6,    -1,    66,   188,
     227,   189,     6,    -1,    69,   220,   288,   192,   274,   221,
       6,    -1,    70,   220,   292,   192,   288,   221,     6,    -1,
     292,   218,   280,     6,    -1,     4,   188,   189,   218,   280,
       6,    -1,   291,   188,   189,   218,   280,     6,    -1,     4,
     188,   274,   189,   218,   274,     6,    -1,     4,   186,   274,
     187,   218,   274,     6,    -1,   291,   188,   274,   189,   218,
     274,     6,    -1,     4,   220,   193,   283,   194,   221,   218,
     280,     6,    -1,   291,   220,   193,   283,   194,   221,   218,
     280,     6,    -1,   292,   219,     6,    -1,     4,   188,   274,
     189,   219,     6,    -1,   291,   188,   274,   189,   219,     6,
      -1,   292,     7,   288,     6,    -1,     4,   190,     4,     7,
     288,     6,    -1,     4,   188,   274,   189,   190,     4,     7,
     288,     6,    -1,     4,   190,     4,   218,   274,     6,    -1,
       4,   188,   274,   189,   190,     4,   218,   274,     6,    -1,
       4,   190,     4,   219,     6,    -1,     4,   188,   274,   189,
     190,     4,   219,     6,    -1,     4,   190,   134,   190,     4,
       7,   284,     6,    -1,     4,   188,   274,   189,   190,   134,
     190,     4,     7,   284,     6,    -1,     4,   190,   135,     7,
     285,     6,    -1,     4,   188,   274,   189,   190,   135,     7,
     285,     6,    -1,     4,   143,     7,   274,     6,    -1,   143,
     188,   274,   189,     7,     4,     6,    -1,   143,   188,   274,
     189,   190,     4,     7,   274,     6,    -1,   143,   188,   274,
     189,   190,     4,     7,   288,     6,    -1,   143,   188,   274,
     189,   190,     4,     7,   193,   283,   194,     6,    -1,   143,
     188,   274,   189,   190,     4,     6,    -1,    95,   186,     4,
     187,   190,     4,     7,   274,     6,    -1,    95,   186,     4,
     187,   190,     4,     7,   288,     6,    -1,    -1,   192,    -1,
      -1,   224,   223,   292,    -1,   224,   223,   292,     7,   274,
      -1,    -1,   224,   223,   292,     7,   193,   274,   225,   229,
     194,    -1,   224,   223,   292,     7,   288,    -1,    -1,   224,
     223,   292,     7,   193,   288,   226,   231,   194,    -1,    -1,
     227,   223,   287,    -1,   274,     7,   288,    -1,   228,   192,
     274,     7,   288,    -1,    -1,   229,   230,    -1,   192,     4,
     280,    -1,   192,     4,   193,   228,   194,    -1,   192,     4,
     288,    -1,    -1,   231,   232,    -1,   192,     4,   274,    -1,
     192,     4,   288,    -1,   192,     4,   193,   290,   194,    -1,
     274,    -1,   288,    -1,   274,    -1,   288,    -1,   274,    -1,
     288,    -1,   274,    -1,   288,    -1,    -1,   137,    75,   193,
     274,   194,    -1,    -1,    87,   277,    -1,    71,   186,   274,
     187,     7,   277,     6,    -1,    91,    71,   186,   233,   187,
     218,   280,     6,    -1,    80,    81,   280,     7,   274,     6,
      -1,    74,   186,   274,   187,     7,   280,     6,    -1,    96,
      74,   280,     6,    -1,    78,   186,   274,   187,     7,   280,
       6,    -1,    72,   186,   274,   187,     7,   280,   238,     6,
      -1,    73,   186,   274,   187,     7,   280,   238,     6,    -1,
     129,   186,   274,   187,     7,   280,     6,    -1,   130,   186,
     274,   187,     7,   280,     6,    -1,   131,   186,   274,   187,
       7,   280,   133,   280,   132,   274,     6,    -1,    74,     4,
     186,   274,   187,     7,   280,     6,    -1,    92,    74,   186,
     274,   187,     7,   280,     6,    -1,    91,    74,   186,   234,
     187,   218,   280,     6,    -1,    87,    77,   186,   274,   187,
       7,   280,     6,    -1,    88,    77,   186,   274,   187,     7,
     280,   237,     6,    -1,    12,    13,     6,    -1,    13,    77,
     274,     6,    -1,    82,    77,   186,   274,   187,     7,     5,
       5,     5,     6,    -1,    75,   186,   274,   187,     7,   280,
       6,    -1,    76,   186,   274,   187,     7,   280,     6,    -1,
      77,     4,   186,   274,   187,     7,   280,     6,    -1,    92,
      77,   186,   274,   187,     7,   280,     6,    -1,    92,    77,
     186,   274,   187,     7,   280,     4,   193,   279,   194,     6,
      -1,    91,    77,   186,   235,   187,   218,   280,     6,    -1,
      90,    79,   186,   274,   187,     7,   280,     6,    -1,    79,
     186,   274,   187,     7,   280,     6,    -1,    92,    79,   186,
     274,   187,     7,   280,     6,    -1,    91,    79,   186,   236,
     187,   218,   280,     6,    -1,    99,   277,   193,   241,   194,
      -1,    98,   193,   277,   192,   277,   192,   274,   194,   193,
     241,   194,    -1,   100,   277,   193,   241,   194,    -1,   101,
     193,   277,   192,   274,   194,   193,   241,   194,    -1,   101,
     193,   277,   192,   277,   194,   193,   241,   194,    -1,     4,
     193,   241,   194,    -1,   109,    74,   193,   283,   194,    77,
     193,   274,   194,    -1,   106,    74,   186,   274,   187,   193,
     283,   194,     6,    -1,   242,    -1,   240,    -1,    -1,   242,
     239,    -1,   242,    71,   193,   283,   194,     6,    -1,   242,
      74,   193,   283,   194,     6,    -1,   242,    77,   193,   283,
     194,     6,    -1,   242,    79,   193,   283,   194,     6,    -1,
     103,    87,   186,   274,   187,     7,   280,     6,    -1,   103,
      71,   186,   274,   187,     7,   193,   279,   194,     6,    -1,
     103,    87,   186,   274,   187,     7,   193,   277,   192,   277,
     192,   283,   194,     6,    -1,   103,    87,   186,   274,   187,
       7,   193,   277,   192,   277,   192,   277,   192,   283,   194,
       6,    -1,   103,    75,   186,   274,   187,     7,   193,   277,
     192,   283,   194,     6,    -1,   103,     4,   186,   274,   187,
       7,   280,     6,    -1,   103,     4,   186,   274,   187,     7,
       5,     6,    -1,   103,     4,   193,   274,   194,     6,    -1,
     103,     4,   186,   274,   187,     7,   193,   277,   192,   277,
     192,   283,   194,     6,    -1,   107,   193,   242,   194,    -1,
     107,   143,   188,   274,   189,     6,    -1,   107,     4,   188,
     274,   189,     6,    -1,   107,     4,     6,    -1,   107,     4,
       4,     6,    -1,   134,   284,   193,   242,   194,    -1,    97,
     134,   284,   193,   242,   194,    -1,   147,     5,     6,    -1,
     148,     5,     6,    -1,   147,   193,   242,   194,    -1,    97,
     147,   193,   242,   194,    -1,   148,   193,   242,   194,    -1,
      97,   148,   193,   242,   194,    -1,     4,   288,     6,    -1,
      58,   186,   290,   187,     6,    -1,     4,     4,   188,   274,
     189,   287,     6,    -1,     4,     4,     4,   188,   274,   189,
       6,    -1,     4,   274,     6,    -1,    95,   186,     4,   187,
     190,     4,     6,    -1,   128,     4,     6,    -1,   141,     6,
      -1,   142,     6,    -1,    55,     6,    -1,    56,     6,    -1,
      50,     6,    -1,    50,   193,   274,   192,   274,   192,   274,
     192,   274,   192,   274,   192,   274,   194,     6,    -1,    51,
       6,    -1,    52,     6,    -1,    62,     6,    -1,    63,     6,
      -1,    84,     6,    -1,    85,   193,   283,   194,   193,   283,
     194,   193,   279,   194,   193,   274,   192,   274,   194,     6,
      -1,   156,   274,     6,    -1,   136,   186,   274,     8,   274,
     187,    -1,   136,   186,   274,     8,   274,     8,   274,   187,
      -1,   136,     4,   137,   193,   274,     8,   274,   194,    -1,
     136,     4,   137,   193,   274,     8,   274,     8,   274,   194,
      -1,   138,    -1,   146,     4,    -1,   144,    -1,   145,   292,
       6,    -1,   139,   186,   274,   187,    -1,   140,    -1,   102,
     277,   193,   242,   194,    -1,   102,   193,   277,   192,   277,
     192,   274,   194,   193,   242,   194,    -1,   102,   193,   277,
     192,   277,   192,   277,   192,   274,   194,   193,   242,   194,
      -1,    -1,   102,   277,   193,   242,   250,   263,   194,    -1,
      -1,   102,   193,   277,   192,   277,   192,   274,   194,   193,
     242,   251,   263,   194,    -1,    -1,   102,   193,   277,   192,
     277,   192,   277,   192,   274,   194,   193,   242,   252,   263,
     194,    -1,    -1,   102,   193,   242,   253,   263,   194,    -1,
     102,    71,   193,   274,   192,   277,   194,     6,    -1,   102,
      74,   193,   274,   192,   277,   194,     6,    -1,   102,    77,
     193,   274,   192,   277,   194,     6,    -1,   102,    71,   193,
     274,   192,   277,   192,   277,   192,   274,   194,     6,    -1,
     102,    74,   193,   274,   192,   277,   192,   277,   192,   274,
     194,     6,    -1,   102,    77,   193,   274,   192,   277,   192,
     277,   192,   274,   194,     6,    -1,   102,    71,   193,   274,
     192,   277,   192,   277,   192,   277,   192,   274,   194,     6,
      -1,   102,    74,   193,   274,   192,   277,   192,   277,   192,
     277,   192,   274,   194,     6,    -1,   102,    77,   193,   274,
     192,   277,   192,   277,   192,   277,   192,   274,   194,     6,
      -1,    -1,   102,    71,   193,   274,   192,   277,   194,   254,
     193,   263,   194,     6,    -1,    -1,   102,    74,   193,   274,
     192,   277,   194,   255,   193,   263,   194,     6,    -1,    -1,
     102,    77,   193,   274,   192,   277,   194,   256,   193,   263,
     194,     6,    -1,    -1,   102,    71,   193,   274,   192,   277,
     192,   277,   192,   274,   194,   257,   193,   263,   194,     6,
      -1,    -1,   102,    74,   193,   274,   192,   277,   192,   277,
     192,   274,   194,   258,   193,   263,   194,     6,    -1,    -1,
     102,    77,   193,   274,   192,   277,   192,   277,   192,   274,
     194,   259,   193,   263,   194,     6,    -1,    -1,   102,    71,
     193,   274,   192,   277,   192,   277,   192,   277,   192,   274,
     194,   260,   193,   263,   194,     6,    -1,    -1,   102,    74,
     193,   274,   192,   277,   192,   277,   192,   277,   192,   274,
     194,   261,   193,   263,   194,     6,    -1,    -1,   102,    77,
     193,   274,   192,   277,   192,   277,   192,   277,   192,   274,
     194,   262,   193,   263,   194,     6,    -1,   264,    -1,   263,
     264,    -1,   112,   193,   274,   194,     6,    -1,   112,   193,
     280,   192,   280,   194,     6,    -1,   112,   193,   280,   192,
     280,   192,   280,   194,     6,    -1,   113,     6,    -1,   104,
       6,    -1,   120,     6,    -1,   120,   122,     6,    -1,   121,
       6,    -1,   121,   122,     6,    -1,   118,     6,    -1,   118,
     122,     6,    -1,   119,     6,    -1,   119,   122,     6,    -1,
     114,   186,   274,   187,     7,   280,    94,   274,     6,    -1,
      94,     4,   188,   274,   189,     6,    -1,    -1,    94,     4,
     274,    -1,    -1,     4,    -1,    -1,     7,   280,    -1,    -1,
       7,   274,    -1,    -1,    94,   280,    -1,    89,    74,   281,
       7,   274,   265,     6,    -1,    89,    77,   281,   267,   266,
       6,    -1,    83,    77,   193,   274,   194,     7,   280,     6,
      -1,    89,    79,   281,   267,     6,    -1,   123,   281,     6,
      -1,   110,    77,   193,   283,   194,   274,     6,    -1,   104,
      77,   281,   268,     6,    -1,   104,    79,   281,     6,    -1,
     105,    77,   280,     7,   274,     6,    -1,    93,    74,   280,
       7,   280,     6,    -1,    93,    77,   274,   193,   283,   194,
       7,   274,   193,   283,   194,   269,     6,    -1,    71,   193,
     283,   194,   137,    77,   193,   274,   194,     6,    -1,    74,
     193,   283,   194,   137,    77,   193,   274,   194,     6,    -1,
      71,   193,   283,   194,   137,    79,   193,   274,   194,     6,
      -1,    74,   193,   283,   194,   137,    79,   193,   274,   194,
       6,    -1,    77,   193,   283,   194,   137,    79,   193,   274,
     194,     6,    -1,   111,    77,   281,     6,    -1,   111,    74,
     281,     6,    -1,    86,    71,   281,     6,    -1,    86,    74,
     281,     6,    -1,    86,    77,   281,     6,    -1,   108,     6,
      -1,   108,     4,     6,    -1,   108,    71,   193,   283,   194,
       6,    -1,   153,    -1,   154,    -1,   155,    -1,   272,     6,
      -1,   272,   193,   280,   194,     6,    -1,   272,   193,   280,
     192,   280,   194,     6,    -1,   272,   186,   280,   187,   193,
     280,   192,   280,   194,     6,    -1,   275,    -1,   186,   274,
     187,    -1,   177,   274,    -1,   176,   274,    -1,   181,   274,
      -1,   274,   177,   274,    -1,   274,   176,   274,    -1,   274,
     178,   274,    -1,   274,   179,   274,    -1,   274,   180,   274,
      -1,   274,   185,   274,    -1,   274,   172,   274,    -1,   274,
     173,   274,    -1,   274,   175,   274,    -1,   274,   174,   274,
      -1,   274,   171,   274,    -1,   274,   170,   274,    -1,   274,
     169,   274,    -1,   274,   168,   274,    -1,   274,   167,   274,
       8,   274,    -1,    14,   220,   274,   221,    -1,    15,   220,
     274,   221,    -1,    16,   220,   274,   221,    -1,    17,   220,
     274,   221,    -1,    18,   220,   274,   221,    -1,    19,   220,
     274,   221,    -1,    20,   220,   274,   221,    -1,    21,   220,
     274,   221,    -1,    22,   220,   274,   221,    -1,    24,   220,
     274,   221,    -1,    25,   220,   274,   192,   274,   221,    -1,
      26,   220,   274,   221,    -1,    27,   220,   274,   221,    -1,
      28,   220,   274,   221,    -1,    29,   220,   274,   221,    -1,
      30,   220,   274,   221,    -1,    31,   220,   274,   221,    -1,
      32,   220,   274,   221,    -1,    33,   220,   274,   192,   274,
     221,    -1,    34,   220,   274,   192,   274,   221,    -1,    35,
     220,   274,   192,   274,   221,    -1,    23,   220,   274,   221,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   159,
      -1,   160,    -1,   161,    -1,    59,    -1,    60,    -1,    61,
      -1,    -1,    67,   220,   274,   276,   229,   221,    -1,   152,
     220,   287,   221,    -1,   292,    -1,     4,   188,   274,   189,
      -1,   291,   188,   274,   189,    -1,   157,   186,   292,   187,
      -1,   158,   186,   288,   187,    -1,   191,   292,   188,   189,
      -1,   292,   219,    -1,     4,   188,   274,   189,   219,    -1,
     291,   188,   274,   189,   219,    -1,     4,   190,     4,    -1,
       4,   188,   274,   189,   190,     4,    -1,     4,   190,     4,
     219,    -1,     4,   188,   274,   189,   190,     4,   219,    -1,
     149,   186,   287,   192,   274,   187,    -1,    45,   186,   280,
     192,   280,   187,    -1,    46,   186,   287,   192,   287,   187,
      -1,    47,   186,   287,   192,   287,   187,    -1,    49,   186,
     290,   187,    -1,   278,    -1,   177,   277,    -1,   176,   277,
      -1,   277,   177,   277,    -1,   277,   176,   277,    -1,   193,
     274,   192,   274,   192,   274,   192,   274,   192,   274,   194,
      -1,   193,   274,   192,   274,   192,   274,   192,   274,   194,
      -1,   193,   274,   192,   274,   192,   274,   194,    -1,   186,
     274,   192,   274,   192,   274,   187,    -1,   280,    -1,   279,
     192,   280,    -1,   274,    -1,   282,    -1,   193,   194,    -1,
     193,   283,   194,    -1,   177,   193,   283,   194,    -1,   274,
     178,   193,   283,   194,    -1,   280,    -1,     5,    -1,   177,
     282,    -1,   274,   178,   282,    -1,   274,     8,   274,    -1,
     274,     8,   274,     8,   274,    -1,    71,   193,   274,   194,
      -1,    71,     5,    -1,    74,     5,    -1,    77,     5,    -1,
      79,     5,    -1,    91,    71,     5,    -1,    91,    74,     5,
      -1,    91,    77,     5,    -1,    91,    79,     5,    -1,    91,
      71,   193,   283,   194,    -1,    91,    74,   193,   283,   194,
      -1,    91,    77,   193,   283,   194,    -1,    91,    79,   193,
     283,   194,    -1,    71,   137,    50,   193,   274,   192,   274,
     192,   274,   192,   274,   192,   274,   192,   274,   194,    -1,
      74,   137,    50,   193,   274,   192,   274,   192,   274,   192,
     274,   192,   274,   192,   274,   194,    -1,    77,   137,    50,
     193,   274,   192,   274,   192,   274,   192,   274,   192,   274,
     192,   274,   194,    -1,    79,   137,    50,   193,   274,   192,
     274,   192,   274,   192,   274,   192,   274,   192,   274,   194,
      -1,   240,    -1,   249,    -1,     4,   220,   221,    -1,   291,
     220,   221,    -1,    36,   188,   292,   189,    -1,     4,   220,
     193,   283,   194,   221,    -1,   291,   220,   193,   283,   194,
     221,    -1,   274,    -1,   282,    -1,   283,   192,   274,    -1,
     283,   192,   282,    -1,   193,   274,   192,   274,   192,   274,
     192,   274,   194,    -1,   193,   274,   192,   274,   192,   274,
     194,    -1,     4,    -1,     4,   190,   134,   190,     4,    -1,
     193,   286,   194,    -1,     4,   188,   274,   189,   190,   135,
      -1,   284,    -1,   286,   192,   284,    -1,   288,    -1,   292,
      -1,     4,   190,     4,    -1,     4,   188,   274,   189,   190,
       4,    -1,     5,    -1,    53,    -1,   162,    -1,    57,    -1,
     150,   186,   287,   187,    -1,   151,   186,   287,   192,   287,
     187,    -1,   151,   186,   287,   187,    -1,    41,   220,   290,
     221,    -1,    42,   186,   287,   187,    -1,    43,   186,   287,
     187,    -1,    44,   186,   287,   192,   287,   192,   287,   187,
      -1,    39,   220,   290,   221,    -1,    48,   220,   274,   192,
     288,   192,   288,   221,    -1,    40,   220,   287,   221,    -1,
      40,   220,   287,   192,   283,   221,    -1,    54,   220,   287,
     221,    -1,    -1,    68,   220,   288,   289,   231,   221,    -1,
     287,    -1,   290,   192,   287,    -1,     4,   195,   193,   274,
     194,    -1,   291,   195,   193,   274,   194,    -1,     4,    -1,
     291,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   191,   193,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   215,   219,   226,   231,   236,   250,   263,   276,   304,
     318,   331,   344,   363,   368,   369,   370,   371,   372,   376,
     378,   383,   385,   391,   495,   390,   513,   520,   531,   530,
     548,   555,   566,   565,   582,   599,   622,   621,   635,   636,
     637,   638,   639,   643,   644,   650,   650,   651,   651,   657,
     658,   659,   664,   670,   731,   760,   789,   794,   799,   804,
     811,   818,   833,   838,   843,   852,   858,   867,   885,   903,
     912,   924,   929,   937,   957,   980,   991,   999,  1021,  1044,
    1070,  1091,  1103,  1117,  1117,  1119,  1121,  1130,  1140,  1139,
    1151,  1161,  1160,  1174,  1176,  1184,  1190,  1197,  1198,  1202,
    1213,  1228,  1238,  1239,  1244,  1252,  1261,  1279,  1283,  1292,
    1296,  1305,  1309,  1318,  1322,  1332,  1335,  1348,  1351,  1361,
    1384,  1416,  1439,  1457,  1478,  1496,  1526,  1556,  1574,  1592,
    1619,  1637,  1655,  1690,  1708,  1747,  1753,  1759,  1766,  1791,
    1816,  1833,  1852,  1886,  1922,  1940,  1957,  1973,  2010,  2015,
    2020,  2025,  2030,  2035,  2058,  2064,  2075,  2076,  2081,  2084,
    2088,  2111,  2134,  2157,  2185,  2206,  2232,  2253,  2275,  2295,
    2407,  2426,  2464,  2573,  2582,  2588,  2603,  2631,  2648,  2657,
    2671,  2677,  2683,  2692,  2701,  2710,  2724,  2780,  2798,  2815,
    2830,  2849,  2861,  2885,  2889,  2894,  2901,  2906,  2912,  2917,
    2923,  2931,  2935,  2939,  2944,  2999,  3012,  3029,  3046,  3067,
    3088,  3123,  3131,  3137,  3144,  3148,  3157,  3165,  3173,  3182,
    3181,  3196,  3195,  3210,  3209,  3224,  3223,  3237,  3244,  3251,
    3258,  3265,  3272,  3279,  3286,  3293,  3301,  3300,  3314,  3313,
    3327,  3326,  3340,  3339,  3353,  3352,  3366,  3365,  3379,  3378,
    3392,  3391,  3405,  3404,  3421,  3424,  3430,  3442,  3462,  3486,
    3490,  3494,  3498,  3502,  3508,  3514,  3518,  3522,  3526,  3530,
    3549,  3562,  3565,  3581,  3584,  3601,  3604,  3610,  3613,  3620,
    3623,  3630,  3686,  3756,  3761,  3828,  3864,  3872,  3915,  3954,
    3974,  4001,  4050,  4078,  4106,  4110,  4114,  4142,  4181,  4220,
    4241,  4262,  4289,  4293,  4303,  4338,  4339,  4340,  4344,  4350,
    4362,  4380,  4408,  4409,  4410,  4411,  4412,  4413,  4414,  4415,
    4416,  4423,  4424,  4425,  4426,  4427,  4428,  4429,  4430,  4431,
    4432,  4433,  4434,  4435,  4436,  4437,  4438,  4439,  4440,  4441,
    4442,  4443,  4444,  4445,  4446,  4447,  4448,  4449,  4450,  4451,
    4452,  4453,  4454,  4455,  4464,  4465,  4466,  4467,  4468,  4469,
    4470,  4471,  4472,  4473,  4478,  4477,  4485,  4490,  4507,  4525,
    4543,  4548,  4554,  4566,  4583,  4601,  4622,  4627,  4632,  4642,
    4652,  4657,  4668,  4677,  4682,  4709,  4713,  4717,  4721,  4725,
    4732,  4736,  4740,  4744,  4751,  4756,  4763,  4768,  4772,  4777,
    4781,  4789,  4800,  4804,  4816,  4824,  4832,  4839,  4849,  4878,
    4882,  4886,  4890,  4894,  4898,  4902,  4906,  4910,  4939,  4968,
    4997,  5026,  5039,  5052,  5065,  5078,  5088,  5098,  5110,  5122,
    5134,  5152,  5173,  5178,  5182,  5186,  5198,  5202,  5214,  5221,
    5231,  5235,  5250,  5255,  5262,  5266,  5279,  5287,  5298,  5302,
    5310,  5316,  5322,  5330,  5338,  5345,  5360,  5374,  5388,  5400,
    5416,  5427,  5431,  5450,  5458,  5457,  5470,  5475,  5481,  5490,
    5503,  5506
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
  "tStrPrefix", "tStrRelative", "tStrReplace", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tSyncModel", "tNewModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineString",
  "tSetNumber", "tSetString", "tPoint", "tCircle", "tEllipse", "tLine",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverse",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl",
  "tQuadTriDbl", "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tFunction", "tShow", "tHide", "tGetValue",
  "tGetEnv", "tGetString", "tGetNumber", "tHomology", "tCohomology",
  "tBetti", "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATEROREQUAL",
  "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARYPREC",
  "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'.'",
  "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All", "GeoFormatItems",
  "GeoFormatItem", "SendToFile", "Printf", "View", "Views",
  "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "$@6", "$@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId0", "PhysicalId1", "PhysicalId2",
  "PhysicalId3", "InSphereCenter", "CircleOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "Visibility", "Command", "Loop", "Extrude", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
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
     415,   416,   417,   418,   419,   420,   421,    63,   422,   423,
     424,   425,    60,    62,   426,   427,    43,    45,    42,    47,
      37,    33,   428,   429,   430,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   196,   197,   197,   198,   198,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   200,   200,   201,   201,   201,   201,   201,   201,   202,
     202,   202,   202,   203,   203,   203,   203,   203,   203,   204,
     204,   205,   205,   207,   208,   206,   209,   209,   211,   210,
     212,   212,   214,   213,   215,   215,   217,   216,   218,   218,
     218,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   223,   223,   224,   224,   224,   225,   224,
     224,   226,   224,   227,   227,   228,   228,   229,   229,   230,
     230,   230,   231,   231,   232,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   238,   238,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     240,   240,   240,   240,   240,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   246,   246,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   249,   250,
     249,   251,   249,   252,   249,   253,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   254,   249,   255,   249,
     256,   249,   257,   249,   258,   249,   259,   249,   260,   249,
     261,   249,   262,   249,   263,   263,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   271,   271,   271,   272,   272,   272,   273,   273,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   277,   277,   277,   277,   277,
     278,   278,   278,   278,   279,   279,   280,   280,   280,   280,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   283,   283,   283,   283,   284,   284,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   287,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   289,   288,   290,   290,   291,   291,
     292,   292
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
       5,     7,     7,     4,     6,     6,     7,     7,     7,     9,
       9,     3,     6,     6,     4,     6,     9,     6,     9,     5,
       8,     8,    11,     6,     9,     5,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       5,     0,     9,     0,     3,     3,     5,     0,     2,     3,
       5,     3,     0,     2,     3,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     0,     2,     7,
       8,     6,     7,     4,     7,     8,     8,     7,     7,    11,
       8,     8,     8,     8,     9,     3,     4,    10,     7,     7,
       8,     8,    12,     8,     8,     7,     8,     8,     5,    11,
       5,     9,     9,     4,     9,     9,     1,     1,     0,     2,
       6,     6,     6,     6,     8,    10,    14,    16,    12,     8,
       8,     6,    14,     4,     6,     6,     3,     4,     5,     6,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,     3,     6,     8,     8,    10,
       1,     2,     1,     3,     4,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     8,     8,     8,
      12,    12,    12,    14,    14,    14,     0,    12,     0,    12,
       0,    12,     0,    16,     0,    16,     0,    16,     0,    18,
       0,    18,     0,    18,     1,     2,     5,     7,     9,     2,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     9,
       6,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     7,     6,     8,     5,     3,     7,     5,     4,     6,
       6,    13,    10,    10,    10,    10,    10,     4,     4,     4,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     4,     1,     4,     4,
       4,     4,     4,     2,     5,     5,     3,     6,     4,     7,
       6,     6,     6,     6,     4,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     1,     2,     3,     3,     5,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     5,     5,     5,
       5,    16,    16,    16,    16,     1,     1,     3,     3,     4,
       6,     6,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     3,     6,     1,     1,
       1,     1,     4,     6,     4,     4,     4,     4,     8,     4,
       8,     4,     6,     4,     0,     6,     1,     3,     5,     5,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,   235,     0,     0,     0,   232,     0,
       0,     0,     0,   325,   326,   327,     0,     5,     7,     6,
       8,     9,    10,    19,    11,    12,    13,    18,    17,    14,
      15,    16,     0,    20,   491,     0,   374,   490,   468,   375,
     376,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   469,     0,   471,   381,   382,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,   379,   380,   470,     0,     0,     0,    65,    66,     0,
       0,   178,     0,     0,     0,   332,     0,   464,   491,   387,
       0,     0,     0,     0,   217,     0,   219,   220,   215,   216,
       0,   221,   222,   105,   113,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,   490,   423,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   445,   446,   416,   422,
       0,   417,   491,   387,     0,     0,     0,     0,   458,     0,
       0,     0,     0,     0,   213,   214,     0,   490,   491,     0,
     231,     0,   178,     0,   178,   490,     0,   328,     0,     0,
      66,     0,     0,    58,    62,    61,    60,    59,    64,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   335,   334,
     336,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,   176,     0,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,   206,     0,   393,   155,     0,   490,     0,   464,   465,
       0,     0,   486,     0,   103,   103,     0,     0,     0,     0,
     452,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   178,
     178,     0,   407,   406,     0,     0,     0,     0,   178,   178,
       0,     0,     0,     0,     0,     0,     0,   245,     0,   178,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     196,     0,     0,     0,   323,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,   429,     0,     0,
     430,     0,   431,     0,   432,     0,     0,     0,     0,     0,
       0,   334,   424,     0,   418,     0,     0,     0,   305,    66,
       0,   212,     0,     0,     0,     0,     0,   178,     0,     0,
       0,     0,   233,   200,     0,   201,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,   484,     0,     0,     0,
       0,     0,     0,     0,   333,    58,     0,     0,    58,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,   179,
       0,     0,     0,   350,   349,   348,   347,   343,   344,   346,
     345,   338,   337,   339,   340,   341,   342,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,   320,   321,     0,     0,
       0,     0,   293,     0,     0,     0,   127,   128,     0,   129,
     130,     0,   131,   132,     0,   133,   134,     0,     0,     0,
       0,     0,     0,   143,   178,     0,     0,     0,     0,     0,
     409,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,   197,     0,     0,   193,     0,     0,     0,   318,
     317,     0,     0,     0,     0,   396,    67,    68,     0,   447,
       0,     0,     0,     0,     0,     0,   433,     0,   434,     0,
     435,     0,   436,     0,     0,   333,   419,   426,     0,   339,
     425,     0,   448,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,   202,   204,     0,     0,     0,     0,     0,
       0,     0,    84,    73,     0,   388,   398,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   373,   361,     0,   363,
     364,   365,   366,   367,   368,   369,     0,     0,     0,   479,
       0,   481,   475,   476,   477,     0,     0,     0,     0,     0,
     404,   483,   117,   122,    95,     0,   472,   474,     0,   386,
     390,   391,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,   392,     0,     0,     0,     0,   488,
       0,     0,    43,     0,     0,     0,    56,     0,    34,    35,
      36,    37,    38,   389,     0,   466,    23,    21,     0,     0,
      24,     0,     0,   207,   487,    69,   106,    70,   114,     0,
       0,     0,   454,   455,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   296,   294,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
     205,     0,     0,     0,   168,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,     0,   236,     0,     0,     0,     0,     0,     0,
     298,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   388,     0,   449,     0,   428,     0,     0,     0,
       0,     0,     0,     0,   420,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,     0,
     329,     0,     0,     0,   489,     0,     0,     0,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
      82,    85,    87,     0,     0,   462,     0,    93,     0,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,    29,
     395,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,     0,   310,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   280,     0,   279,     0,   285,
       0,   287,     0,   281,     0,   283,     0,   246,   275,     0,
       0,     0,   191,     0,     0,     0,   309,     0,   195,   194,
     324,     0,     0,    30,    31,     0,     0,     0,     0,     0,
       0,     0,   437,   438,   439,   440,   427,   421,     0,     0,
       0,     0,   459,     0,     0,     0,   226,     0,     0,     0,
       0,    75,     0,    83,     0,   209,   397,   208,   362,   370,
     371,   372,   482,     0,   401,   402,   403,     0,     0,   385,
     118,     0,   485,   123,   400,   473,    77,    58,     0,     0,
       0,     0,    76,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,     0,    25,
      26,     0,    27,     0,     0,   107,   110,    71,    72,   139,
       0,     0,     0,     0,     0,     0,   142,     0,     0,   158,
     159,     0,     0,   144,   165,     0,     0,     0,     0,   135,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   211,     0,     0,     0,     0,   178,   178,     0,   256,
       0,   258,     0,   260,     0,   416,     0,     0,   286,   288,
     282,   284,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,   397,   450,     0,     0,
       0,     0,   451,   147,   148,     0,     0,     0,     0,    96,
     100,     0,     0,   330,    78,     0,   399,     0,     0,     0,
       0,     0,     0,    90,     0,     0,    91,     0,   463,   180,
     181,   182,   183,     0,     0,    39,     0,     0,     0,     0,
       0,    41,   467,     0,     0,   108,   111,     0,     0,   138,
     145,   146,   150,     0,     0,   160,     0,     0,   303,     0,
     153,     0,     0,   292,   164,   140,   152,   163,   167,   151,
       0,   161,   166,     0,     0,     0,     0,   413,     0,   412,
       0,     0,     0,   247,     0,     0,   248,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
     189,     0,     0,     0,   184,     0,     0,    32,     0,     0,
       0,     0,     0,     0,   457,     0,   228,   227,     0,     0,
       0,     0,     0,   478,   480,     0,   119,   121,     0,   124,
     125,    86,    88,     0,    94,     0,    79,    44,     0,     0,
       0,   415,     0,     0,     0,    28,     0,   117,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     101,   102,   178,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,   276,     0,     0,   178,     0,     0,     0,
       0,     0,   175,   174,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,    80,     0,   452,     0,     0,
     461,     0,    40,     0,     0,     0,    42,    57,     0,     0,
       0,   312,   314,   313,   315,   316,   157,     0,     0,     0,
       0,     0,     0,   411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,   241,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,   456,   229,
       0,   331,     0,   120,     0,   126,    92,     0,     0,     0,
       0,     0,   109,   112,     0,     0,     0,   299,   169,     0,
     262,     0,     0,   264,     0,     0,   266,     0,     0,     0,
     277,     0,   237,     0,   178,     0,     0,     0,     0,     0,
       0,     0,   149,    99,     0,   115,     0,    48,     0,    54,
       0,     0,     0,   136,   162,     0,     0,   410,   250,     0,
       0,   257,   251,     0,     0,   259,   252,     0,     0,   261,
       0,     0,     0,   243,     0,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   300,
     311,     0,   268,     0,   270,     0,   272,   278,   289,   242,
     238,     0,     0,     0,     0,     0,     0,     0,     0,   116,
      45,     0,    52,     0,     0,     0,     0,   253,     0,     0,
     254,     0,     0,   255,     0,     0,   192,     0,   186,     0,
       0,     0,     0,     0,    46,     0,     0,   218,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,   263,     0,   265,     0,
     267,     0,   187,     0,     0,     0,     0,    47,    49,     0,
      50,     0,     0,     0,     0,   441,   442,   443,   444,     0,
       0,    55,   269,   271,   273,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    87,   888,    88,    89,   647,  1334,  1340,
     878,  1054,  1501,  1683,   879,  1634,  1719,   880,  1685,   881,
     882,  1058,   330,   413,   173,   759,    90,   661,   424,  1447,
    1448,   425,  1496,  1030,  1190,  1031,  1193,   695,   698,   701,
     704,  1362,  1233,   629,   286,   390,   391,    93,    94,    95,
      96,    97,    98,   287,   964,  1583,  1651,   729,  1384,  1387,
    1390,  1609,  1613,  1617,  1668,  1671,  1674,   960,   961,  1092,
     925,   692,   738,  1606,   100,   101,   102,   103,   288,   175,
     842,   473,   246,  1215,   289,   290,   291,   535,   300,   863,
    1046,   422,   418,   843,   423,   178,   293
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1269
static const yytype_int16 yypact[] =
{
    6433,    50,    74,  6547, -1269, -1269,  3160,    89,    73,   -80,
     -28,    39,   172,   180,   188,   248,    91,   311,   340,   187,
     190,    76,    76,   -89,   198,   202,     6,   211,   218,    15,
     233,   239,   350,   431,   447,   458,   357,   494,   493,   520,
     451,   487,   530,   592,   -39,   425,   552,   -75,   436,   -16,
     -16,   439,    67,    28,   252,   559,   585,     8,    51,   593,
     606,   201,   682,   693,   705,  4351,   706,   541,   555,   561,
      19,    49, -1269,   562, -1269,   745,   752,   574, -1269,   763,
     783,    24,    36, -1269, -1269, -1269,  6301, -1269, -1269, -1269,
   -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269,
   -1269, -1269,    -5, -1269,  -125,   136, -1269,     1, -1269, -1269,
   -1269, -1269,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,   590,   605,   608,
     614,   629,   638,    76,   639, -1269,    76, -1269, -1269, -1269,
   -1269,    76,    76,   807,   645,   650,   651,    76,   668,   680,
   -1269, -1269, -1269, -1269,  6301,  6301,  6301,  6301,  6063,    30,
     763,   420,   611,   674,   278, -1269,   678,   868,    71,  -118,
     875,  6301,  4239,  4239, -1269,  6301, -1269, -1269, -1269, -1269,
    4239, -1269, -1269, -1269, -1269, -1269, -1269,  3248,   763,  6301,
    5884,  6301,  6301,   701,  6301,  5884,  6301,  6301,   704,  5884,
    6301,  6301,  4721,   715,   717, -1269,  5884,  4351,  4351,  4351,
     728,   731,  4351,  4351,  4351,   732,   751,   757,   782,   789,
     790,   794,   802,  4721,  6301,   891,  4721,    19,   813,   831,
     -16,   -16,   -16,  6301,  6301,   -66, -1269,   -44,   -16,   832,
     845,   846,  5646,    72,   -38,   817,   857,   861,  4351,  4351,
    4721,   862,    54,   805, -1269,   993, -1269,   869,   870,   872,
    4351,  4351,   878,   879,   881,   505, -1269,   882,    17,     2,
      20,    26,   577,  4906,  6301,  3544, -1269, -1269,  3326, -1269,
    1054, -1269,   -74,   328,  1065,  6301,  6301,  6301,   883,  6301,
     886,   937,  6301,  6301, -1269, -1269,  6301,   885,   888,  1070,
   -1269,  1075, -1269,  1079, -1269,  -111,   545, -1269,  4721,  4721,
    6117,   895,   896,  3248, -1269, -1269, -1269, -1269, -1269, -1269,
    4721,  1084,   921,  6301,  1110,  6301,  6301,  6301,  6301,  6301,
    6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,
    6301,  6301,  6301,  6301,  6301,  6301,  6301,  4239,  4239,  4239,
    4239,  4239,  4239,  4721,  4239,  4239,  6301,  4239,  4239,  6301,
    3248,  6301,  4239,  4239,  4239,  4239,   763,  3248,   936,   936,
     936,  5673,   106,  8165,   276,   927,  1115,   939,   938, -1269,
     931,  4390,  6301,  5884, -1269,  6301,  6301,  6301,  6301,  6301,
    6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,  6301,
   -1269, -1269,  6301, -1269, -1269,   778,   364,  -141, -1269, -1269,
      58,  4716, -1269,   153,    87,   185,   943,   944,  8510,  5884,
    3500, -1269,   174,  8531,  8552,  6301,  8573,   289,  8594,  8615,
    6301,   290,  8636,  8657,  1122,  6301,  6301,   366,  1124,  1131,
    1132,  6301,  6301,  1133,  1138,  1138,  6301,  5705,  5705,  5705,
    5705,  6301,  6301,  6301,  1139,  3353,   952,  1145,   959, -1269,
   -1269,   -40, -1269, -1269,  4901,  5086,   -16,   -16,   420,   420,
     -30,  6301,  6301,  6301,  5646,  5646,  6301,  4390,   121, -1269,
    6301,  6301,  6301,  6301,  6301,  1146,  1148,  1149,  6301,  1154,
   -1269,  6301,  6301,   543, -1269,  5884,  5884,  5884,  1155,  1157,
    6301,  6301,  6301,  6301,  1151,   -70,   763, -1269,  1114,  6301,
   -1269,  1116, -1269,  1117, -1269,  1118,    43,    44,    45,    47,
    5884,   936, -1269,  8678, -1269,   375,  6301,  5091, -1269,  6301,
     419, -1269,  8699,  8720,  8741,  1031,  5271, -1269,   976,  3679,
    8762,  8188, -1269, -1269,   848, -1269,  1028,  6301, -1269,   995,
     411,   106,  8211,  6301,  5884,  1177,  1178, -1269,  6301,  8234,
     -59,  6112,  6112,  6112,  6112,  6112,  6112,  6112,  6112,  6112,
    6112,  6112,  5456,  6112,  6112,  6112,  6112,  6112,  6112,  6112,
    5879,  7125,  7151,   498,   514,   498,   998,  1001,  1000,  1002,
    1004,  1007,  7177,   288,   457,  9203, -1269,  1209,  1008,  1006,
     489,   457,  1014,  1016,   106, -1269,  4721,   128,  3248,  6301,
    1199,  1202,    29,  1020, -1269,   117,    32,    35,   148, -1269,
    4849,   476,  3698,  1416,  1832,  1461,  1461,   129,   129,   129,
     129,   164,   164,   936,   936,   936,   936,     4,  8257, -1269,
    6301,  1206,     9,  5884,  1205,  5884,  6301,  1207,  4239,  1208,
   -1269,   763,  1210,  4239,  6301,  3248,  1212,  5884,  5884,  1080,
    1213,  1218,  8783,  1219,  1090,  1225,  1228,  8804,  1100,  1229,
    1232,  6301,  8825,  5034,  1019, -1269, -1269, -1269,  8846,  8867,
    6301,  4721,  1236,  1237,  8888,  1057,  9203, -1269,  1059,  9203,
   -1269,  1060,  9203, -1269,  1066,  9203, -1269,  8909,  8930,  8951,
    4721,  5884,  1064, -1269, -1269,  1099,  1355,   -16,  6301,  6301,
   -1269, -1269,  1067,  1069,  5646,  7203,  7229,  7255,  4531,   316,
     -16,  1480,  8972,  5219,  8993,  9014,  9035,  6301,  1253, -1269,
    6301,  9056, -1269,  8280,  8303, -1269,   534,   579,   580, -1269,
   -1269,  8326,  8349,  7281,  8372,   328, -1269, -1269,  5884, -1269,
    1071,  1076,  5404,  1081,  1082,  1083, -1269,  5884, -1269,  5884,
   -1269,  5884, -1269,  5884,   588, -1269, -1269,  3883,  5884,   936,
   -1269,  5884, -1269,  1257,  1271,  1272,  1091,  6301,  2015,  6301,
    6301, -1269,    57, -1269, -1269,  1089,  4721,  1280,  4721,   569,
    5607,   591, -1269, -1269,  8395,   282, -1269, -1269, -1269, -1269,
   -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269,  6301, -1269,
   -1269, -1269, -1269, -1269, -1269, -1269,  6301,  6301,  6301, -1269,
    5884, -1269, -1269, -1269, -1269,  4239,  4721,  4239,  4239,  3248,
   -1269, -1269, -1269, -1269, -1269,  6301, -1269, -1269,  4239, -1269,
   -1269, -1269,  6301,  1285,    38,  6301,  1292,  1293,  1349, -1269,
    1297,  1112,    19,  1300, -1269,  5884,  5884,  5884,  5884, -1269,
     457,  6301, -1269,  1121,  1125,  1120, -1269,  1302, -1269, -1269,
   -1269, -1269, -1269,   328,  8418, -1269, -1269,  1141,  4239,   490,
   -1269,   502,  7307, -1269, -1269, -1269,  1303, -1269, -1269,  6112,
     457,   -16,  3500, -1269,   709,  4721,  4721,  1308,  4721,   713,
    4721,  4721,  1310,  1241,  4721,  4721,  1709,  1317,  1318,  5884,
    1320,  1325,  2382, -1269, -1269,  1327, -1269,  1332,   106,   106,
     106,   106,  1333,  1339,  1340,  1328,   609,  1344,  2087, -1269,
   -1269,   161,  7333,  7359, -1269, -1269,  5641,   -68,   -16,   -16,
     -16,  1345,  1346,  1161,  1354,  1164,    18,    31,    34,    37,
     -26, -1269,   171, -1269,   316,  1358,  1360,  1362,  1364,  1365,
    9203, -1269,  2090,  1168,  1367,  1368,  1386,  1316,  6301,  1390,
    1391,  6301,   105,   615, -1269,  6301, -1269,  6301,  6301,  6301,
     618,   619,   628,   636, -1269,  6301,   648,   658,  4721,  4721,
    4721,  1396,  7385, -1269,  3949,   413,  1397,  1398,  4721,  1211,
   -1269,  1400,  6301,  1401, -1269,   457,  1403,  1399, -1269,  1406,
    6112,  6112,  6112,  6112,   551,  1221,  1217,  1227,  1230,  1231,
     557,   567,  9077,  1233,  2192, -1269,   633,  1226,  1412,  2739,
   -1269, -1269, -1269,    19,  6301, -1269,   659, -1269,   663,   683,
     688,   692,   106,  9203,  1235,  6301,  6301,  4721,  1243, -1269,
   -1269,  1234, -1269,  1432,    61,  1434,  6301,  3921,  1435,  1438,
       7,  1255,  1256,  1363,  1363,  4721,  1446,  1260,  1261,  1451,
    1452,  4721,  1266,  1454,  1458, -1269,  1460,  4721,   702,  4721,
    4721,  1466,  1465, -1269,  4721,  4721,  4721,  4721,  4721,  4721,
    4721,  4721, -1269,  1459,   467, -1269,  6301,  6301,  6301,  1281,
    1282,   -96,   -87,   -76,  1288, -1269,  4721, -1269,  6301, -1269,
    1472, -1269,  1473, -1269,  1485, -1269,  1488, -1269, -1269,  5646,
     779,  4536, -1269,  1287,  1305,  5276, -1269,  5884, -1269, -1269,
   -1269,  1307,  2820, -1269, -1269,  8441,  1491,   457,  7411,  7437,
    7463,  7489, -1269, -1269, -1269, -1269,  9203, -1269,   457,  1490,
    1496,  1371, -1269,  6301,  6301,  6301, -1269,  1499,   526,  1314,
    1501, -1269,  2897, -1269,   106, -1269,    -8, -1269, -1269, -1269,
   -1269, -1269, -1269,  4239, -1269, -1269, -1269,  3248,  1504, -1269,
   -1269,  1505, -1269, -1269, -1269, -1269, -1269,  3248,  6301,  1506,
    1509,    29, -1269,  1524,  8464,    19, -1269,  1526,  1529,  1530,
    1531,  4721,  6301,  7515,  7541,   712, -1269,  6301,  1511, -1269,
   -1269,  4239, -1269,  7567,  5705,  9203, -1269, -1269, -1269, -1269,
    6301,  6301,   -16,  1533,  1534,  1535, -1269,  6301,  6301, -1269,
   -1269,  1536,  6301, -1269, -1269,  1538,  1539,  1351,  1540,  1373,
    6301, -1269,  1541,  1544,  1555,  1559,  1560,  1563,   909,  1571,
    6301, -1269,  5705,  5827,  9098,  4078,   420,   420,   -16,  1572,
     -16,  1573,   -16,  1574,  6301,   320,  1389,  9119, -1269, -1269,
   -1269, -1269,  6019,   175, -1269,  1577,  3358,  1593,  4721,   -16,
    3358,  1594,   767,  6301, -1269,  1597,   328, -1269,  6301,  6301,
    6301,  6301, -1269, -1269, -1269,  4721,  4479,   368,  9140, -1269,
   -1269,  3981,  4721, -1269, -1269,  4721, -1269,  1417,   457,  3736,
    4166,  1600,  2916, -1269,  1601,  1606, -1269,  1423, -1269, -1269,
   -1269, -1269, -1269,  1608,   573,  9203,  6301,  6301,  4721,  1414,
     768,  9203, -1269,  1609,  6301,  9203, -1269,  6202,  6230,   401,
   -1269, -1269, -1269,  6537,  6565, -1269,  6593,  1611, -1269,  4721,
   -1269,  1542,  1612,  9203, -1269, -1269, -1269, -1269, -1269, -1269,
    1428, -1269, -1269,  6058,  2954,  1616,  1430, -1269,  6301, -1269,
    1431,  1437,   215, -1269,  1455,   235, -1269,  1456,   246, -1269,
    1463,  8487,  1618,  4721,  1637,  1464,  6301, -1269,  5461,   285,
   -1269,   772,   309,   330, -1269,  1639,  6621, -1269,  7593,  7619,
    7645,  7671,  1519,  6301, -1269,  6301, -1269, -1269,  5884,  2973,
    1646,  1471,  1647, -1269, -1269,  3544, -1269, -1269,  4239,  9203,
   -1269, -1269, -1269,    19, -1269,  1520, -1269, -1269,  6301,  7697,
    7723, -1269,  4721,  6301,  1648, -1269,  7749, -1269, -1269,  1653,
    1654,  1664,  1669,  1670,  1671,   773,  1486, -1269,  4721,  5884,
   -1269, -1269,   420,  4664, -1269, -1269,  5646,   316,  5646,   316,
    5646,   316,  1674, -1269,   777,  4721, -1269,  6649,   -16,  1675,
    5884,   -16, -1269, -1269,  6301,  6301,  6301,  6301,  6301,  6677,
    6705,   780, -1269, -1269,  1678, -1269,   792,  2677,   793,  1679,
   -1269,  1493,  9203,  6301,  6301,   797,  9203, -1269,  6301,   800,
     806, -1269, -1269, -1269, -1269, -1269, -1269,  1494,  6301,   810,
     815,  1495,  6301, -1269,  6733,   339,   932,  6761,   387,  1029,
    6789,   418,  1137, -1269,  4721,  1682,  1596,  2532,  1498,   461,
   -1269,   818,   465,  7775,  7801,  7827,  7853,  3072, -1269, -1269,
    1686, -1269,  6301, -1269,  3248, -1269, -1269,  6301,  9161,  7879,
      48,  7905, -1269, -1269,  6301,  6817,  1688,  1603, -1269,  6845,
    1689,  6301,  1693,  1695,  6301,  1698,  1701,  6301,  1702,  1515,
   -1269,  6301, -1269,   316, -1269,  5884,  1704,  5461,  6301,  6301,
    6301,  6301, -1269, -1269,  3306, -1269,   819, -1269,  6301, -1269,
    4721,  6301,  7931, -1269, -1269,  4721,  1710, -1269, -1269,  1532,
    6873, -1269, -1269,  1537,  6901, -1269, -1269,  1545,  6929, -1269,
    1721,  3091,  1176,  2737,   823, -1269,   486,   824,  7957,  7983,
    8009,  8035,  3248,  1722,  1546,  9182,   827,  6957,  6301, -1269,
   -1269,   316,  1723,   316,  1725,   316,  1726, -1269, -1269, -1269,
   -1269,   316,  1727,  5884,  1728,  6301,  6301,  6301,  6301, -1269,
   -1269,  4239, -1269,  1547,  1731,  6985,  1224, -1269,  1548,  1369,
   -1269,  1550,  1599, -1269,  1556,  1876, -1269,   843, -1269,  8061,
    8087,  8113,  8139,   863, -1269,  1558,  4721, -1269,  1742,  1746,
     316,  1747,   316,  1748,   316, -1269,  1749,  6301,  6301,  6301,
    6301,  4239,  1750,  4239,   864, -1269, -1269,  2019, -1269,  2222,
   -1269,  2318, -1269,  7013,  7041,  7069,  7097, -1269, -1269,   867,
   -1269,  1754,  1756,  1757,  1760, -1269, -1269, -1269, -1269,  4239,
    1761, -1269, -1269, -1269, -1269, -1269, -1269
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1269, -1269, -1269, -1269,   707, -1269, -1269, -1269, -1269,   212,
   -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269, -1269,
   -1269, -1269,  -356,   -94,  2272,  1474, -1269,  1347, -1269, -1269,
   -1269, -1269, -1269,   326, -1269,   327, -1269, -1269, -1269, -1269,
   -1269, -1269,   700,  1773,     0,  -461,  -243, -1269, -1269, -1269,
   -1269, -1269, -1269,  1774, -1269, -1269, -1269, -1269, -1269, -1269,
   -1269, -1269, -1269, -1269, -1269, -1269, -1269,  -822,  -930, -1269,
   -1269,  1323, -1269, -1269, -1269, -1269, -1269, -1269,  1462, -1269,
   -1269,    33, -1269, -1268,   -67,  1140,  1068,  1815,  -235,   582,
   -1269,    21,    10, -1269,  -353,    -3,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -468
static const yytype_int16 yytable[] =
{
     104,   317,   468,    92,   593,   332,   595,   520,   872,   487,
     203,   331,   262,  1229,   603,   886,   177,   722,   723,   208,
    1401,   503,   517,   298,  1119,   522,   616,   176,   619,   311,
    1128,   524,   254,   861,   384,   233,   203,  1121,   234,   208,
    1123,   313,  1036,  1125,   105,   184,   652,   179,   766,   768,
     770,   653,   772,   301,  1599,   265,     4,   266,   499,   237,
     500,   195,   292,   320,  1006,   328,   329,  1220,   951,   554,
     321,   556,   238,   239,     5,  -465,   308,   557,   952,   514,
     476,   477,   245,   247,   172,   253,   953,   954,   955,   476,
     477,  1455,   956,   957,   958,   959,  1268,   199,  1269,   255,
     476,   477,   180,   256,   200,  1270,   182,  1271,   476,   477,
     476,   477,   195,   615,   539,   257,  1272,   756,  1273,   757,
     309,   321,   267,   758,   328,   329,  1110,   478,   873,   874,
     875,   876,   476,   477,  -466,   615,   476,   477,   249,   521,
    1120,   250,  1130,   323,   251,   444,   476,   477,   490,   479,
     181,   263,   717,  1122,   518,   491,  1124,   523,   183,  1126,
     241,   242,   724,   525,   385,   386,   464,   308,  1127,   467,
     243,   389,  1037,  1038,  1505,   328,   329,   244,   186,   308,
     308,   318,   887,   476,   477,  -467,   187,   308,   319,   333,
    1519,   334,   204,   497,   188,   308,   172,   292,   877,   205,
    1128,   264,   292,   417,   420,   798,   292,   426,   209,   292,
     519,   387,   299,   292,   292,   292,   292,   312,   204,   292,
     292,   292,   862,   419,   419,   866,   715,   716,   867,   314,
     292,   419,   185,   292,   887,   302,   767,   769,   771,   427,
     773,  1600,   501,   241,   242,   654,   731,  1007,   476,   477,
     655,   559,   560,   243,   189,   292,   292,   292,   852,   412,
     252,   855,   195,   566,   196,   489,   321,   292,   292,   324,
     325,   326,   327,   471,   472,   270,   659,   190,   271,   660,
     292,   480,   292,   618,   394,   488,   416,   108,   328,   329,
     620,   324,   325,   326,   327,  1146,   599,   476,   477,   324,
     325,   326,   327,   199,   788,   404,   405,   406,   407,   408,
     865,   328,   329,   730,   409,   292,   292,   191,   854,   328,
     329,   134,   135,   136,   137,   138,   139,   292,   536,   258,
     143,   259,  1636,   565,   211,   145,   146,   476,   477,   147,
     657,   868,   406,   407,   408,   658,   192,   476,   477,   409,
     152,   476,   477,  1106,   308,   308,   308,   308,   308,   308,
     292,   308,   308,  1129,   308,   308,   668,  1396,   669,   308,
     308,   308,   308,   308,   662,   193,  1415,   660,   194,   594,
     606,   596,   597,   598,   201,   600,   601,   613,   202,   604,
     292,   476,   477,   608,   609,   610,   611,   206,   419,   419,
     419,   419,   419,   419,   207,   419,   419,  1466,   419,   419,
     951,   476,   477,   419,   419,   419,   419,   612,  1704,   210,
     952,  1165,   476,   477,   388,   211,   292,  1468,   953,   954,
     955,   212,   155,   156,   956,   957,   958,   959,  1470,   324,
     325,   326,   327,  1012,   163,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   328,
     329,   476,   477,   409,   215,   328,   329,   697,   700,   703,
     706,   938,  1017,  1261,  1262,   840,   806,  1478,   389,   389,
     658,   668,   668,   674,   678,   476,   477,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   537,   407,
     408,  1480,   292,   292,   292,   409,   476,   477,   213,   720,
     721,   328,   329,   308,  1392,   476,   477,   472,    48,    49,
      50,    51,  1481,   856,   214,   222,    56,   292,   223,    59,
     224,  1571,  1310,  1311,   292,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   853,
     216,   558,   650,   409,   651,     7,     8,   760,   668,   172,
     684,   292,  1416,   476,   477,   217,   225,   668,   218,   776,
     220,   219,  1095,  1096,  1097,  1098,   615,   476,   477,  1574,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   476,   477,  1128,   221,   409,  1128,
    1166,   226,  1128,   796,   227,   797,   756,   228,   757,   229,
    1577,   235,   781,   292,   625,    24,    25,   626,    27,    28,
     627,    30,   628,    32,   923,    33,   236,  1045,   857,   240,
      38,    39,   248,    41,    42,    43,   260,   476,   477,    46,
    1197,   476,   477,   935,   756,  1526,   757,  1529,   526,  1532,
     292,   527,   292,  1585,   528,   308,   529,  1587,   308,   261,
     308,   806,   476,   477,   292,   292,   230,   268,   668,   231,
     870,   232,    67,    68,    69,   900,   847,  1064,  1653,   894,
    1198,   848,   668,   269,   898,   756,   272,   757,   292,  1065,
     658,   195,  1128,   513,   668,   514,  1211,   273,   171,   419,
     172,   756,   896,   757,   419,  1013,   830,   292,   292,   274,
     294,  1018,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   668,   295,   976,  1009,
     409,  1011,   324,   325,   326,   327,  1128,   745,   756,  1128,
     757,   296,  1128,   668,   756,  1128,   757,   297,   303,  1188,
     941,   304,   328,   329,   756,   292,   757,   947,   305,  1191,
    1437,  1622,   306,   962,   292,  1438,   292,   307,   292,  1026,
     292,   668,   668,   977,   978,   292,   360,  1128,   292,  1128,
     668,  1128,   994,   668,   649,  1015,  1071,   310,  1072,  1060,
    1077,   361,  1078,   292,   362,   292,   324,   325,   326,   327,
     363,   668,   308,  1103,   392,  1380,  1381,   668,  1203,  1147,
     668,   668,  1152,  1153,   371,   364,   328,   329,  1315,  1666,
     668,  1669,  1154,  1672,   365,   367,  1019,   292,   668,  1675,
    1155,   372,   308,   292,   308,   308,   373,   374,  1073,  1074,
     668,  1076,  1157,  1079,  1080,   308,   419,  1083,  1084,  1029,
     668,  1205,  1158,  1206,   376,   668,  1025,  1207,  1027,  1028,
       7,     8,   292,   292,   292,   292,   377,   393,  1707,  1033,
    1709,   410,  1711,   951,   411,   668,   419,  1208,   419,   419,
     668,   414,  1209,   952,   668,   308,  1210,   435,  1018,   419,
     440,   953,   954,   955,   668,   466,  1247,   956,   957,   958,
     959,   445,   292,   292,  1338,   292,  1339,   292,   292,  1063,
     446,   292,   292,  1370,   451,  1371,   292,   452,   456,   625,
      24,    25,   626,    27,    28,   627,    30,   628,    32,   419,
      33,  1159,  1160,  1161,  1070,    38,    39,   457,    41,    42,
      43,  1169,  1199,   458,    46,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   668,
    1443,  1405,  1444,   409,  1338,  1338,  1479,  1517,   459,  1534,
    1328,  1535,   668,  1284,  1550,   460,   461,    67,    68,    69,
     462,  1111,  1112,  1113,  1552,   658,  1553,  1555,   463,  1338,
    1216,  1560,  1188,   502,  1562,   292,   292,   292,  1191,   504,
    1563,  1521,  1338,   492,  1566,   292,   469,   668,  1235,  1567,
     668,  1443,  1586,  1633,  1241,   668,   668,  1652,  1654,  1338,
    1246,  1663,  1248,  1249,   470,   481,   951,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,   668,   952,  1696,   482,   483,
       7,     8,   793,   493,   953,   954,   955,   494,   498,  1276,
     956,   957,   958,   959,   292,  1701,  1338,  1702,  1721,  1729,
     538,  1730,   505,   506,  1287,   507,   510,   511,  1291,   512,
     516,   541,   292,   545,   548,  1498,   552,  1226,   292,   547,
     172,   553,  1316,   321,   292,   555,   292,   292,   563,   564,
     567,   292,   292,   292,   292,   292,   292,   292,   292,   625,
      24,    25,   626,    27,    28,   627,    30,   628,    32,   568,
      33,     7,     8,   292,   570,    38,    39,   621,    41,    42,
      43,   409,   622,   951,    46,   624,  1572,   623,   292,   681,
     685,   171,   292,   952,   292,   664,   665,   686,   687,   712,
     690,   953,   954,   955,  1333,   691,   710,   956,   957,   958,
     959,   713,   714,   737,   739,   755,   740,    67,    68,    69,
     742,   749,  1283,   750,   761,   786,   763,   764,   765,   789,
     625,    24,    25,   626,    27,    28,   627,    30,   628,    32,
     308,    33,   795,   802,   803,   833,    38,    39,   834,    41,
      42,    43,   835,   846,   836,    46,   837,  1318,  1499,   838,
     845,   850,  1316,   851,  1317,   859,   860,  1321,   292,   864,
     885,   890,   919,   893,   895,   844,   897,   904,   308,   901,
     905,  1216,   794,  1575,   419,   906,   908,   909,    67,    68,
      69,   951,   910,  1537,  1346,   911,   914,   913,  1412,   915,
     924,   952,  1343,   926,   928,  1421,   929,   930,  1422,   953,
     954,   955,  1426,   931,   937,   956,   957,   958,   959,   971,
     984,   944,   419,   945,   998,  1349,   389,   389,   431,   985,
     951,  1441,  1375,   431,   987,   988,   989,   431,   999,  1000,
     952,  1001,  1008,   292,   431,   292,  1010,   292,   953,   954,
     955,  1035,  1216,   939,   956,   957,   958,   959,  1040,  1041,
    1044,  1382,   292,  1385,  1043,  1388,  1047,  1055,  1059,   292,
    1067,  1056,   292,  1057,  1062,  1075,   292,  1081,   951,  1399,
    1082,  1420,  1402,  1403,  1086,  1087,  1474,  1089,   952,  1427,
    1430,  1578,  1090,  1093,  1102,   292,   953,   954,   955,  1094,
    1099,  1623,   956,   957,   958,   959,  1100,  1101,  1104,  1114,
    1118,   532,  1115,   431,  1116,  1042,   292,   448,   449,   450,
    1117,  1137,   453,   454,   455,  1131,  1132,     7,     8,  1133,
    1649,  1134,  1135,  1138,  1139,  1216,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     292,  1216,  1140,  1141,   409,   292,  1143,  1144,   495,   496,
    1162,  1167,  1168,  1176,  1184,  1170,  1171,  1173,  1536,  1175,
     508,   509,  1177,  1183,  1185,   292,  1200,  1186,  1689,  1201,
    1195,  1212,   292,  1187,  1218,   308,   625,    24,    25,   626,
      27,    28,   627,    30,   628,    32,  1217,    33,  1219,   292,
    1222,  1227,    38,    39,  1228,    41,    42,    43,  1230,  1231,
    1232,    46,  1236,  1237,  1238,   292,   292,  1239,  1240,  1242,
    1243,   431,   389,   951,  1244,  1245,  1260,  1579,   174,   419,
    1250,  1251,   292,   952,  1266,  1267,  1274,   292,  1278,  1279,
    1288,   953,   954,   955,    67,    68,    69,   956,   957,   958,
     959,  1280,     7,     8,  1281,  1296,  1303,   532,  1289,  1525,
    1293,  1528,  1304,  1531,  1305,  1309,  1312,  1313,  1319,  1320,
    1361,  1539,  1323,  1324,  1542,  1342,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
    1326,   292,  1329,  1216,   409,  1330,  1331,  1332,  1639,  1350,
    1351,  1352,  1355,  1357,  1359,  1358,  1360,  1364,   316,   940,
    1365,   625,    24,    25,   626,    27,    28,   627,    30,   628,
      32,  1366,    33,  1691,  1595,  1367,  1368,    38,    39,  1369,
      41,    42,    43,   431,   431,   431,    46,  1372,  1383,  1386,
    1389,  1393,   292,  1397,   292,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   292,   431,  1400,
    1404,   409,   292,  1407,  1423,   780,  1431,  1442,  1433,    67,
      68,    69,  1434,  1435,  1436,  1445,  1454,  1456,  1457,  1216,
    1626,  1458,  1461,  1462,  1473,  1464,   378,   379,   380,   381,
     383,  1465,   431,   400,   401,   402,   403,   404,   405,   406,
     407,   408,  1659,   415,  1475,  1482,   409,   421,  1467,  1469,
     292,  1488,  1493,  1495,  1507,  1500,  1471,  1476,   308,  1511,
    1512,   428,   430,   433,   434,  1494,   436,   430,   438,   439,
    1513,   430,   442,   443,   963,  1514,  1515,  1516,   430,  1518,
    1533,  1540,  1684,   292,  1551,  1556,  1557,  1564,  1580,  1568,
    1581,  1584,  1593,   951,  1604,  1608,   465,  1605,   308,  1611,
     308,  1612,   419,   952,  1615,   474,   475,  1616,  1619,  1620,
    1625,   953,   954,   955,   475,  1085,  1640,   956,   957,   958,
     959,   431,  1717,   431,  1720,  1641,   308,  1647,  1660,  1667,
    1643,  1670,  1673,  1676,  1678,   780,   903,  1687,  1645,  1661,
    1686,  1690,   419,  1692,   419,   531,   533,   430,  1705,  1694,
    1735,  1703,  1706,  1708,  1710,  1712,  1718,   542,   543,   544,
    1731,   546,  1732,  1733,   549,   550,  1734,  1736,   551,  1596,
     419,  1221,   663,  1509,  1234,  1510,    91,    99,   693,   431,
       0,     0,   562,  1325,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,     0,   569,     0,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,     0,
       0,     0,     0,     0,     0,     0,   431,     0,   602,     0,
       0,   605,     0,   607,     0,   431,     0,   431,     0,   431,
       0,   431,     0,     0,     0,     0,   431,     0,     0,   431,
       0,     0,     0,     0,   630,   430,     0,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,     0,     0,   648,     0,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,   531,     0,     0,   409,     0,     0,   672,   431,     0,
       0,     0,   677,     0,     0,     0,     0,   682,   683,     0,
       0,     0,     0,   688,   689,     0,     0,     0,   694,   696,
     699,   702,   705,   707,   708,   709,     0,     0,     0,     0,
       0,     0,     0,   431,   431,   431,   431,     0,     0,     0,
       0,     0,     0,   725,   726,   727,   378,   379,   728,     0,
       0,     0,   732,   733,   734,   735,   736,     0,     0,     0,
     741,     0,     0,   743,   744,     0,     0,   430,   430,   430,
     951,     0,   751,   752,   753,   754,     0,     0,     0,     0,
     952,   762,     0,     0,     0,     0,     0,   431,   953,   954,
     955,     0,   430,     0,   956,   957,   958,   959,   777,   779,
       0,   648,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,   782,   432,     0,   409,     0,   754,
     437,     0,     0,     0,   441,   800,   430,     7,     8,     0,
     804,   447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   807,   808,   809,   810,   811,
     812,   813,   814,   815,   816,   817,     0,   819,   820,   821,
     822,   823,   824,   825,     0,     0,     0,   829,   831,   832,
    1695,     0,     0,     0,     0,     0,     0,     0,   841,     0,
       0,   858,     0,     0,     0,   849,   625,    24,    25,   626,
      27,    28,   627,    30,   628,    32,  1136,    33,     0,     7,
       8,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,   884,   951,     0,   430,     0,   430,   892,     0,
       0,     0,     0,   952,     0,     0,   899,     0,     0,   779,
     902,   953,   954,   955,     0,     0,     0,   956,   957,   958,
     959,     0,     0,   916,    67,    68,    69,     0,     0,     0,
       0,     0,   922,     0,     0,     0,     0,     0,   625,    24,
      25,   626,    27,    28,   627,    30,   628,    32,     0,    33,
       0,     0,     0,   430,    38,    39,     0,    41,    42,    43,
     942,   943,     0,    46,     0,     0,   946,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1196,   970,
       0,     0,   972,     0,     0,   431,     0,     0,   631,  1003,
       0,     0,     0,  1722,     0,     0,    67,    68,    69,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,   430,
       0,   430,     0,   430,     0,   430,     0,     0,     0,     0,
     430,     0,     0,   430,     0,     0,     0,     0,     0,  1002,
       0,  1004,  1005,     0,     0,     0,     0,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,     0,     0,     0,
    1020,  1105,     0,     0,     0,     0,     0,     0,  1021,  1022,
    1023,     0,   430,   197,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1032,     0,     0,
       0,     0,     0,     0,  1034,     0,   951,  1039,     0,     0,
     746,   747,   748,     0,     0,     0,   952,   430,   430,   430,
     430,     0,     0,  1053,   953,   954,   955,     0,     0,     0,
     956,   957,   958,   959,  1052,   774,     0,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   431,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,  1068,  1069,     0,   322,   409,     0,   801,
       0,   430,     0,     0,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,     0,
       0,     0,   951,     0,     0,   366,  1723,     0,   368,     0,
       0,     0,   952,   369,   370,     0,     0,     0,     0,   375,
     953,   954,   955,     0,     0,     0,   956,   957,   958,   959,
    1142,     0,     0,  1145,     0,     0,     0,  1148,     0,  1149,
    1150,  1151,     0,     0,     0,     0,     0,  1156,     0,     0,
       0,     0,     0,     0,     0,     0,   532,     0,   889,     0,
     891,     0,     0,     0,  1172,     0,  1091,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,     0,     0,  1174,
       0,     0,     0,   431,  1178,  1179,  1180,  1181,  1182,     0,
       0,     0,     0,     0,  1189,  1192,  1204,     0,     0,     0,
       0,     0,  1724,     0,     0,     0,     0,  1213,  1214,     0,
       0,     0,     0,     0,     0,     0,   936,   431,  1223,  1225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,   515,   431,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,   540,     0,     0,   409,  1263,  1264,
    1265,     0,     0,   983,     0,     0,     0,     0,  1275,     0,
    1277,     0,   990,     0,   991,     0,   992,     0,   993,     0,
       0,  1282,     0,   996,     0,     0,   997,     0,     0,   430,
       0,     0,     0,   625,    24,    25,   626,    27,    28,   627,
      30,   628,    32,     0,    33,     0,     0,     0,     0,    38,
      39,  1297,    41,    42,    43,  1306,  1307,  1308,    46,     0,
       0,     0,  1302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1024,     0,     0,     0,     0,
       0,     0,     0,   431,     0,   431,     0,     0,     0,     0,
    1322,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,     0,     0,     0,  1341,
    1048,  1049,  1050,  1051,  1554,   536,  1345,     0,     0,     0,
       0,     0,  1347,  1348,     0,     0,     0,     0,     0,  1353,
    1354,     0,     0,     0,  1356,     0,     0,     0,     0,     0,
       0,     0,  1363,     0,     0,     0,     0,     0,     0,     0,
       0,   431,  1373,     0,  1374,     0,  1582,     0,     0,     0,
       0,     0,     0,     0,  1088,     0,  1391,     0,     0,     0,
       0,     0,     0,     0,     0,  1202,     0,     0,   430,     7,
       8,     0,   430,     0,     0,  1406,     0,     0,     0,     0,
    1408,  1409,  1410,  1411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1419,     0,     0,     0,     0,     0,     0,
       0,     0,  1429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1424,     0,     0,     0,     0,     0,  1439,  1440,
       0,     0,     0,     0,     0,     0,  1446,     0,   625,    24,
      25,   626,    27,    28,   627,    30,   628,    32,     0,    33,
       0,     0,     0,     0,    38,    39,  1294,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
    1463,     0,     0,     0,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   667,   407,   408,  1477,     0,
     531,     0,   409,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,  1489,     0,  1490,     0,     0,
     430,     0,     0,     0,     0,     0,     0,  1497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1502,     0,     0,  1314,     0,  1506,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,   430,  1432,     0,   409,     0,     0,     0,  1524,     0,
    1527,  1650,  1530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,     0,  1543,  1544,  1545,  1546,
    1547,     0,  1292,     0,     0,     0,     0,     0,     0,     0,
    1460,     0,     0,     0,     0,  1558,  1559,     0,     0,     0,
    1561,     0,     0,     0,     0,     0,     0,     0,     0,  1492,
    1565,     0,     0,     0,  1569,     0,     0,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,  1594,     0,     0,     0,     0,  1341,
       0,     0,     0,     0,     0,     0,  1602,     0,     0,     0,
       0,     0,     0,  1610,     0,     0,  1614,     0,     0,  1618,
       0,     0,     0,  1621,     0,     0,     0,   430,     0,   430,
    1628,  1629,  1630,  1631,     0,     0,     0,     0,     0,     0,
    1635,     0,     0,  1637,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,  1592,     0,
       0,     0,   409,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,  1648,     0,     0,
    1665,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   430,     0,  1679,  1680,  1681,
    1682,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,  1713,
    1714,  1715,  1716,   106,   107,   108,     0,     0,     0,   109,
     110,   111,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,     0,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   145,   146,     0,     0,   147,     0,   148,
     149,   150,     0,     0,     0,     0,     0,   151,   152,     0,
       0,     0,     0,  1491,     0,     0,     0,     0,     0,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   108,     0,     0,     0,   409,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,  1520,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,     0,     0,  1541,   143,     0,     0,     0,
       0,   145,   146,   153,     0,   147,     0,     0,     0,   154,
     155,   156,   157,  1632,     0,     0,   152,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,   164,   165,     0,     0,
       0,   166,     0,     0,     0,     0,   167,     0,   168,     0,
     169,   170,     0,   171,     0,   172,     0,     0,     0,     0,
       0,   106,   275,     0,     0,     0,     0,   109,   110,   111,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   277,     0,     0,     0,   155,   156,
    1624,     0,  1627,   140,   141,   142,     0,   144,     0,     0,
     163,     0,     0,     0,     0,     0,     0,   148,   149,   150,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   278,
       0,     0,   279,     0,     0,   280,     0,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,    56,     0,     0,    59,  1677,     0,
       0,     0,     0,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,     0,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   537,   407,   408,   154,   536,     0,
     157,   409,     0,     0,     0,   158,   159,   160,   161,   162,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   484,  1398,     0,     0,   409,   166,
       0,     0,     0,     0,   486,     0,   711,   106,   275,   170,
       0,   244,   534,   109,   110,   111,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     277,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
       0,   151,     0,     0,     0,   278,     0,     0,   279,     0,
       0,   280,     0,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   667,   407,
     408,     0,     0,     0,     0,   409,     0,   790,     0,     0,
       0,     0,     0,   154,     0,     0,   157,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   429,     0,     0,     0,   166,     0,     0,     0,     0,
     284,     0,     0,     0,     0,   170,     0,     0,   534,   106,
     275,   108,     0,     0,     0,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   277,     0,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   145,
     146,     0,     0,   147,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   151,   152,     0,     0,   278,     0,     0,
     279,     0,     0,   280,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,   154,   155,   156,   157,     0,
       0,   995,     0,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   283,     0,     0,     0,   166,     0,     0,
       0,     0,   284,     0,   106,   315,   108,   170,     0,  1425,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,  1164,     0,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   145,   146,     0,     0,   147,     0,
     148,   149,   150,     0,   106,   315,   108,     0,   151,   152,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   145,   146,     0,     0,   147,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,   152,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
     154,   155,   156,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,     0,
       0,     0,   166,     0,     0,     0,     0,   284,     0,     0,
       0,     0,   170,     0,  1224,     0,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     154,   155,   156,   157,   409,     0,     0,     0,   158,   159,
     160,   161,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,     0,
       0,     0,   166,     0,     0,     0,     0,   284,     0,   106,
     315,   108,   170,     0,  1418,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   145,
     146,     0,     0,   147,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   151,   152,     0,     0,     0,     0,     0,
       0,     0,     0,   416,   108,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,     0,     0,     0,     0,     0,
    1378,     0,  1379,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,     0,     0,     0,   143,     0,     0,
       0,     0,   145,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,     0,
       0,     0,     0,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,     0,     0,     0,   166,     0,     0,
       0,     0,   284,     0,   106,   275,   276,   170,     0,  1428,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   277,     0,   155,
     156,     0,     0,     0,     0,     0,   140,   141,   142,     0,
     144,   163,     7,     8,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   278,     0,     0,   279,     0,     0,   280,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   625,    24,    25,   626,    27,    28,   627,    30,   628,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,   164,   283,     0,
       0,     0,   166,     0,     0,     0,     0,   284,     0,   106,
     275,  1285,   170,     0,   285,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   277,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   278,     0,     0,
     279,     0,     0,   280,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1413,     0,  1414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   157,     0,
       0,     0,     0,   158,   159,   160,   161,   162,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   164,   283,     0,     0,   409,   166,   775,     0,
       0,     0,   284,   718,   106,   275,     0,   170,     0,  1286,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   277,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   278,     0,     0,   279,     0,     0,   280,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,     0,     0,     0,     0,     0,  1522,     0,  1523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   164,   283,     0,
       0,   409,   166,     0,     0,     0,     0,   284,   656,   106,
     275,     0,   170,     0,   285,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   277,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   278,     0,     0,
     279,     0,     0,   280,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,   869,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   157,     0,
       0,     0,     0,   158,   159,   160,   161,   162,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   164,   429,     0,     0,   409,   166,     0,     0,
       0,     0,   284,   718,   106,   275,     0,   170,     0,   530,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   277,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   278,     0,     0,   279,     0,     0,   280,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,   918,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   164,   429,     0,
       0,   409,   166,     0,     0,     0,     0,   284,   719,   106,
     275,     0,   170,     0,   778,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   277,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   278,     0,     0,
     279,     0,     0,   280,     0,   281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,   966,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   157,     0,
       0,     0,     0,   158,   159,   160,   161,   162,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   164,   283,     0,     0,   409,   166,     0,     0,
       0,     0,   284,   787,   106,   275,     0,   170,     0,  1290,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   277,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   278,     0,     0,   279,     0,     0,   280,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,   986,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   484,  1398,     0,
       0,   409,   166,     0,     0,     0,     0,   486,   818,   106,
     315,     0,   170,     0,   244,   109,   110,   111,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   106,   315,
     108,     0,     0,   151,   109,   110,   111,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,   145,   146,
       0,     0,   147,     0,   148,   149,   150,     0,     0,     0,
       0,     0,   151,   152,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,   154,     0,     0,   157,     0,
       0,  1014,     0,   158,   159,   160,   161,   162,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   484,   485,     0,     0,   409,   166,     0,     0,
       0,     0,   486,     0,     0,  1109,     0,   170,     0,   244,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   154,   155,   156,   157,   409,     0,
     614,     0,   158,   159,   160,   161,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,     0,     0,     0,   166,   106,   275,     0,
       0,   284,     0,   109,   110,   111,   170,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     277,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,   142,     0,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
       0,   151,     0,     0,     0,   278,     0,     0,   279,     0,
       0,   280,     0,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
      56,     0,     0,    59,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1376,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,     0,     0,   157,     0,     0,     0,
       0,   158,   159,   160,   161,   162,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     164,   429,     0,     0,   409,   166,   106,   315,     0,     0,
     284,   826,   109,   110,   111,   170,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,     0,   144,     0,     0,     0,     0,     0,     0,     0,
     106,   315,   148,   149,   150,     0,   109,   110,   111,     0,
     151,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   142,     0,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,     0,
       0,     0,     0,     0,   151,     0,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,   154,  1395,     0,   157,     0,     0,     0,     0,
     158,   159,   160,   161,   162,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   164,
     165,     0,     0,   409,   166,     0,     0,     0,     0,   284,
       0,  1459,   382,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   157,
       0,     0,     0,     0,   158,   159,   160,   161,   162,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   164,   165,     0,     0,   409,   166,   756,
       0,   757,     0,   284,   106,   315,   561,     0,   170,     0,
     109,   110,   111,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   151,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,     0,
       0,     0,     0,     0,     0,     0,  1449,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,  1450,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
     154,     0,     0,   157,     0,     0,     0,     0,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,     0,   164,   165,     0,
       0,     0,   166,    -4,    -4,    -4,     0,   284,    -4,    -4,
       0,    -4,   170,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     6,     0,     0,     0,     0,    -4,     0,     0,     7,
       8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     9,    10,    -4,    -4,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
       0,     0,    14,    15,     0,    16,     0,     0,     0,    17,
      18,     0,    19,    20,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,    63,    64,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,    67,    68,    69,     0,
       0,    70,     0,    71,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
      83,    84,    85,    86,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1451,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,  1452,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,     0,     0,  1453,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,  1483,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,  1538,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1548,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,  1549,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,     0,     0,  1570,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,  1573,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,  1576,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1603,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,  1607,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,     0,     0,  1642,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,  1644,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,  1646,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1664,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,  1688,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,     0,     0,  1725,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,  1726,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,     0,     0,  1727,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,  1728,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,   827,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,   828,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,   839,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,   948,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,   949,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,   950,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,   981,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1066,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1107,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1108,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1163,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1298,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1299,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1300,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1301,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1336,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1337,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1344,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1484,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1485,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1486,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1487,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1503,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1504,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1508,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1588,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1589,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1590,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1591,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1598,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1601,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1638,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1655,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1656,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1657,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,  1658,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,  1697,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,  1698,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,     0,     0,     0,  1699,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,     0,     0,
       0,  1700,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,   617,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,     0,     0,   792,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
     799,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,     0,     0,   805,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,   883,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,     0,     0,   974,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
       0,     0,   975,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,     0,     0,     0,   979,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,     0,     0,   980,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,     0,
       0,   982,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,     0,     0,  1016,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,     0,     0,  1061,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,     0,     0,
    1295,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,     0,     0,  1327,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,     0,     0,  1472,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,   666,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,   670,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,   671,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
     673,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,   675,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,   676,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,     0,   679,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,   680,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,   775,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,   783,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,   784,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,   785,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,   791,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
     907,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,   912,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,   917,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,     0,   920,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,   921,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,   927,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,   932,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,   933,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,   934,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,   965,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409,     0,
     967,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,     0,     0,     0,     0,   409,
       0,   968,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,     0,     0,     0,     0,
     409,     0,   969,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,     0,     0,     0,
       0,   409,     0,   973,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,   409,     0,  1194,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,     0,
       0,     0,     0,   409,     0,  1377,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,   409,     0,  1394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,     0,     0,     0,     0,   409,     0,  1417,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,     0,     0,     0,     0,   409,     0,  1597,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,     0,     0,     0,     0,   409,     0,  1662,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,     0,     0,     0,     0,   409
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1269)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     6,   237,     3,   357,     4,   359,     5,     4,   252,
       4,   105,     4,     6,   367,     6,     6,   478,   479,     4,
    1288,   264,     5,     4,     6,     5,   382,     6,   384,     5,
     960,     5,     4,     4,     4,    74,     4,     6,    77,     4,
       6,     5,     4,     6,     3,     6,   187,     6,     5,     5,
       5,   192,     5,     4,     6,     4,     6,     6,     4,   134,
       6,   186,    65,   188,     7,   183,   184,     6,    94,   312,
     195,   314,   147,   148,     0,   193,    79,   188,   104,   190,
     176,   177,    49,    50,   195,    52,   112,   113,   114,   176,
     177,  1359,   118,   119,   120,   121,   192,   186,   194,    71,
     176,   177,    13,    75,   193,   192,   186,   194,   176,   177,
     176,   177,   186,     7,   188,    87,   192,   187,   194,   189,
      79,   195,    71,   193,   183,   184,   194,   193,   124,   125,
     126,   127,   176,   177,   193,     7,   176,   177,    71,   137,
     122,    74,   964,     7,    77,   212,   176,   177,   186,   193,
      77,   143,   192,   122,   137,   193,   122,   137,   186,   122,
     176,   177,   192,   137,   134,   135,   233,   170,   194,   236,
     186,   171,   134,   135,  1442,   183,   184,   193,     6,   182,
     183,   186,   173,   176,   177,   193,     6,   190,   193,   188,
    1458,   190,   186,   260,     6,   198,   195,   200,   194,   193,
    1130,   193,   205,   182,   183,   561,   209,   197,   193,   212,
     193,   170,   193,   216,   217,   218,   219,   193,   186,   222,
     223,   224,   193,   182,   183,   193,   469,   470,   193,   193,
     233,   190,   193,   236,   173,   186,   193,   193,   193,   198,
     193,   193,   188,   176,   177,   187,   489,   190,   176,   177,
     192,   318,   319,   186,     6,   258,   259,   260,   614,   188,
     193,   617,   186,   330,   188,   193,   195,   270,   271,   163,
     164,   165,   166,   240,   241,    74,   189,   186,    77,   192,
     283,   248,   285,     7,     6,   252,     4,     5,   183,   184,
     384,   163,   164,   165,   166,   190,   363,   176,   177,   163,
     164,   165,   166,   186,   547,   176,   177,   178,   179,   180,
     193,   183,   184,   192,   185,   318,   319,     6,   190,   183,
     184,    39,    40,    41,    42,    43,    44,   330,     8,    77,
      48,    79,  1600,   323,   186,    53,    54,   176,   177,    57,
     187,   193,   178,   179,   180,   192,     6,   176,   177,   185,
      68,   176,   177,   192,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   192,   367,   368,   192,   192,   194,   372,
     373,   374,   375,   376,   189,   188,     8,   192,   188,   358,
     370,   360,   361,   362,   186,   364,   365,   377,   186,   368,
     393,   176,   177,   372,   373,   374,   375,   186,   357,   358,
     359,   360,   361,   362,   186,   364,   365,   192,   367,   368,
      94,   176,   177,   372,   373,   374,   375,   376,  1686,   186,
     104,     8,   176,   177,     4,   186,   429,   192,   112,   113,
     114,    81,   150,   151,   118,   119,   120,   121,   192,   163,
     164,   165,   166,   799,   162,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   183,
     184,   176,   177,   185,     6,   183,   184,   457,   458,   459,
     460,   714,   190,     6,     7,   187,   570,   192,   478,   479,
     192,   192,   192,   194,   194,   176,   177,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   192,   505,   506,   507,   185,   176,   177,    77,   476,
     477,   183,   184,   516,   194,   176,   177,   484,    98,    99,
     100,   101,   192,   617,    77,    74,   106,   530,    77,   109,
      79,   192,     6,     7,   537,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   616,
     193,     6,   188,   185,   190,    12,    13,   516,   192,   195,
     194,   564,   194,   176,   177,    71,    79,   192,    74,   194,
      77,    77,   928,   929,   930,   931,     7,   176,   177,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   176,   177,  1526,    77,   185,  1529,
     187,    71,  1532,   192,    74,   194,   187,    77,   189,    79,
     192,   186,   193,   616,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   691,    82,    74,   862,   618,   193,
      87,    88,   193,    90,    91,    92,    77,   176,   177,    96,
       7,   176,   177,   710,   187,  1467,   189,  1469,    71,  1471,
     653,    74,   655,   192,    77,   658,    79,   192,   661,    74,
     663,   755,   176,   177,   667,   668,    74,    74,   192,    77,
     194,    79,   129,   130,   131,   665,   187,   187,   192,   658,
    1036,   192,   192,    77,   663,   187,     4,   189,   691,   187,
     192,   186,  1622,   188,   192,   190,  1052,     4,   193,   658,
     195,   187,   661,   189,   663,   799,   192,   710,   711,     4,
       4,   805,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   192,   186,   194,   796,
     185,   798,   163,   164,   165,   166,  1666,   194,   187,  1669,
     189,   186,  1672,   192,   187,  1675,   189,   186,   186,   192,
     717,     6,   183,   184,   187,   758,   189,   724,     6,   192,
     187,  1583,   188,   730,   767,   192,   769,     4,   771,   836,
     773,   192,   192,   194,   194,   778,   186,  1707,   781,  1709,
     192,  1711,   194,   192,     6,   194,    77,     4,    79,   883,
      77,   186,    79,   796,   186,   798,   163,   164,   165,   166,
     186,   192,   805,   194,   193,  1266,  1267,   192,  1043,   194,
     192,   192,   194,   194,     7,   186,   183,   184,  1174,  1641,
     192,  1643,   194,  1645,   186,   186,   805,   830,   192,  1651,
     194,   186,   835,   836,   837,   838,   186,   186,   905,   906,
     192,   908,   194,   910,   911,   848,   805,   914,   915,   839,
     192,   192,   194,   194,   186,   192,   835,   194,   837,   838,
      12,    13,   865,   866,   867,   868,   186,   193,  1690,   848,
    1692,   193,  1694,    94,     6,   192,   835,   194,   837,   838,
     192,     6,   194,   104,   192,   888,   194,   186,   982,   848,
     186,   112,   113,   114,   192,     4,   194,   118,   119,   120,
     121,   186,   905,   906,   192,   908,   194,   910,   911,   888,
     193,   914,   915,     4,   186,     6,   919,   186,   186,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   888,
      82,   998,   999,  1000,   901,    87,    88,   186,    90,    91,
      92,  1008,  1036,   186,    96,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   192,
     192,   194,   194,   185,   192,   192,   194,   194,   186,   192,
    1205,   194,   192,   194,   194,   186,   186,   129,   130,   131,
     186,   948,   949,   950,   192,   192,   194,   194,   186,   192,
    1057,   194,   192,   188,   194,   998,   999,  1000,   192,     6,
     194,  1462,   192,   186,   194,  1008,   193,   192,  1075,   194,
     192,   192,   194,   194,  1081,   192,   192,   194,   194,   192,
    1087,   194,  1089,  1090,   193,   193,    94,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,   192,   104,   194,   193,   193,
      12,    13,   194,   186,   112,   113,   114,   186,   186,  1116,
     118,   119,   120,   121,  1057,   192,   192,   194,   194,   192,
       6,   194,   193,   193,  1131,   193,   188,   188,  1135,   188,
     188,     6,  1075,   190,   137,  1428,     6,  1067,  1081,   193,
     195,     6,  1176,   195,  1087,     6,  1089,  1090,   193,   193,
       6,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   188,
      82,    12,    13,  1116,     4,    87,    88,   190,    90,    91,
      92,   185,     7,    94,    96,   194,   194,   188,  1131,     7,
       6,   193,  1135,   104,  1137,   192,   192,     6,     6,   187,
       7,   112,   113,   114,  1211,     7,     7,   118,   119,   120,
     121,     6,   193,     7,     6,     4,     7,   129,   130,   131,
       6,     6,  1129,     6,    50,   134,    50,    50,    50,   193,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    1183,    82,   187,     6,     6,   187,    87,    88,   187,    90,
      91,    92,   192,   187,   192,    96,   192,  1187,  1433,   192,
     192,   187,  1296,   187,  1183,     6,     4,  1197,  1211,   189,
       4,     6,   193,     6,     6,     6,     6,   137,  1221,     7,
       7,  1288,   194,   194,  1183,     7,     7,   137,   129,   130,
     131,    94,     7,  1476,  1224,     7,     7,   137,  1305,     7,
       4,   104,  1221,     6,   187,  1312,   187,   187,  1315,   112,
     113,   114,  1319,   187,   190,   118,   119,   120,   121,     6,
     189,   194,  1221,   194,     7,  1232,  1266,  1267,   200,   193,
      94,  1338,  1262,   205,   193,   193,   193,   209,     7,     7,
     104,   190,   193,  1286,   216,  1288,     6,  1290,   112,   113,
     114,     6,  1359,   194,   118,   119,   120,   121,     6,     6,
     188,  1268,  1305,  1270,     7,  1272,     6,   186,     6,  1312,
       7,   186,  1315,   193,   173,     7,  1319,     7,    94,  1286,
      79,  1311,  1289,  1290,     7,     7,  1393,     7,   104,  1319,
    1320,   194,     7,     6,     6,  1338,   112,   113,   114,     7,
       7,  1584,   118,   119,   120,   121,     7,     7,     4,     4,
     186,   283,     6,   285,   193,     6,  1359,   217,   218,   219,
       6,   193,   222,   223,   224,     7,     6,    12,    13,     7,
     194,     7,     7,     6,     6,  1442,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
    1393,  1458,     6,    77,   185,  1398,     6,     6,   258,   259,
       4,     4,     4,     4,   187,   194,     6,     6,  1475,     6,
     270,   271,     6,   192,   187,  1418,   190,   187,   194,     7,
     187,   186,  1425,   192,   190,  1428,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   193,    82,     6,  1442,
       6,     6,    87,    88,     6,    90,    91,    92,   193,   193,
      87,    96,     6,   193,   193,  1458,  1459,     6,     6,   193,
       6,   393,  1462,    94,     6,     5,     7,  1534,     6,  1428,
       4,     6,  1475,   104,   193,   193,   188,  1480,     6,     6,
     193,   112,   113,   114,   129,   130,   131,   118,   119,   120,
     121,     6,    12,    13,     6,     4,     6,   429,   193,  1466,
     193,  1468,     6,  1470,   133,     6,   192,     6,     4,     4,
     137,  1478,     6,     4,  1481,     4,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
       6,  1534,     6,  1600,   185,     6,     6,     6,  1605,     6,
       6,     6,     6,     5,   193,     6,     6,     6,    86,   194,
       6,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     6,    82,   194,  1554,     6,     6,    87,    88,     6,
      90,    91,    92,   505,   506,   507,    96,     6,     6,     6,
       6,   192,  1585,     6,  1587,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,  1600,   530,     6,
       6,   185,  1605,     6,   187,   537,     6,   193,     7,   129,
     130,   131,     6,   190,     6,     6,     5,    75,     6,  1686,
    1587,   193,     6,   193,     6,   194,   164,   165,   166,   167,
     168,   194,   564,   172,   173,   174,   175,   176,   177,   178,
     179,   180,  1632,   181,     7,     6,   185,   185,   193,   193,
    1653,   132,     6,     6,     6,   135,   193,   193,  1661,     6,
       6,   199,   200,   201,   202,   194,   204,   205,   206,   207,
       6,   209,   210,   211,   194,     6,     6,     6,   216,   193,
       6,     6,  1661,  1686,     6,     6,   193,   193,     6,   194,
      94,   193,     6,    94,     6,     6,   234,    94,  1701,     6,
    1703,     6,  1661,   104,     6,   243,   244,     6,     6,   194,
       6,   112,   113,   114,   252,     6,     6,   118,   119,   120,
     121,   653,  1701,   655,  1703,   193,  1729,     6,     6,     6,
     193,     6,     6,     6,     6,   667,   668,     6,   193,   193,
     193,   193,  1701,   193,  1703,   283,   284,   285,     6,   193,
    1729,   193,     6,     6,     6,     6,     6,   295,   296,   297,
       6,   299,     6,     6,   302,   303,     6,     6,   306,  1557,
    1729,  1064,   425,  1447,  1074,  1448,     3,     3,   455,   711,
      -1,    -1,   320,  1201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   333,    -1,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   758,    -1,   366,    -1,
      -1,   369,    -1,   371,    -1,   767,    -1,   769,    -1,   771,
      -1,   773,    -1,    -1,    -1,    -1,   778,    -1,    -1,   781,
      -1,    -1,    -1,    -1,   392,   393,    -1,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,    -1,    -1,   412,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,   429,    -1,    -1,   185,    -1,    -1,   435,   830,    -1,
      -1,    -1,   440,    -1,    -1,    -1,    -1,   445,   446,    -1,
      -1,    -1,    -1,   451,   452,    -1,    -1,    -1,   456,   457,
     458,   459,   460,   461,   462,   463,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   865,   866,   867,   868,    -1,    -1,    -1,
      -1,    -1,    -1,   481,   482,   483,   484,   485,   486,    -1,
      -1,    -1,   490,   491,   492,   493,   494,    -1,    -1,    -1,
     498,    -1,    -1,   501,   502,    -1,    -1,   505,   506,   507,
      94,    -1,   510,   511,   512,   513,    -1,    -1,    -1,    -1,
     104,   519,    -1,    -1,    -1,    -1,    -1,   919,   112,   113,
     114,    -1,   530,    -1,   118,   119,   120,   121,   536,   537,
      -1,   539,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,   540,   200,    -1,   185,    -1,   557,
     205,    -1,    -1,    -1,   209,   563,   564,    12,    13,    -1,
     568,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,    -1,   583,   584,   585,
     586,   587,   588,   589,    -1,    -1,    -1,   593,   594,   595,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,
      -1,   619,    -1,    -1,    -1,   611,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     6,    82,    -1,    12,
      13,    -1,    87,    88,    -1,    90,    91,    92,    -1,    -1,
      -1,    96,   650,    94,    -1,   653,    -1,   655,   656,    -1,
      -1,    -1,    -1,   104,    -1,    -1,   664,    -1,    -1,   667,
     668,   112,   113,   114,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,   681,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,   690,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      -1,    -1,    -1,   711,    87,    88,    -1,    90,    91,    92,
     718,   719,    -1,    96,    -1,    -1,   724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,   737,
      -1,    -1,   740,    -1,    -1,  1137,    -1,    -1,   393,   194,
      -1,    -1,    -1,   194,    -1,    -1,   129,   130,   131,    -1,
     758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,   771,    -1,   773,    -1,    -1,    -1,    -1,
     778,    -1,    -1,   781,    -1,    -1,    -1,    -1,    -1,   787,
      -1,   789,   790,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
     818,   194,    -1,    -1,    -1,    -1,    -1,    -1,   826,   827,
     828,    -1,   830,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,
      -1,    -1,    -1,    -1,   852,    -1,    94,   855,    -1,    -1,
     505,   506,   507,    -1,    -1,    -1,   104,   865,   866,   867,
     868,    -1,    -1,   871,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,   870,   530,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1286,    -1,    -1,    -1,  1290,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   899,   900,    -1,   104,   185,    -1,   564,
      -1,   919,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    -1,
      -1,    -1,    94,    -1,    -1,   143,   194,    -1,   146,    -1,
      -1,    -1,   104,   151,   152,    -1,    -1,    -1,    -1,   157,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
     978,    -1,    -1,   981,    -1,    -1,    -1,   985,    -1,   987,
     988,   989,    -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1398,    -1,   653,    -1,
     655,    -1,    -1,    -1,  1012,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1418,    -1,    -1,  1015,
      -1,    -1,    -1,  1425,  1020,  1021,  1022,  1023,  1024,    -1,
      -1,    -1,    -1,    -1,  1030,  1031,  1044,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,  1055,  1056,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   711,  1459,  1066,  1067,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,   275,  1480,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,   292,    -1,    -1,   185,  1106,  1107,
    1108,    -1,    -1,   758,    -1,    -1,    -1,    -1,  1116,    -1,
    1118,    -1,   767,    -1,   769,    -1,   771,    -1,   773,    -1,
      -1,  1129,    -1,   778,    -1,    -1,   781,    -1,    -1,  1137,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,  1147,    90,    91,    92,  1163,  1164,  1165,    96,    -1,
      -1,    -1,  1158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1585,    -1,  1587,    -1,    -1,    -1,    -1,
    1198,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1212,    -1,    -1,    -1,    -1,  1217,
     865,   866,   867,   868,     7,     8,  1224,    -1,    -1,    -1,
      -1,    -1,  1230,  1231,    -1,    -1,    -1,    -1,    -1,  1237,
    1238,    -1,    -1,    -1,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1653,  1260,    -1,  1262,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   919,    -1,  1274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  1286,    12,
      13,    -1,  1290,    -1,    -1,  1293,    -1,    -1,    -1,    -1,
    1298,  1299,  1300,  1301,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1318,    -1,    -1,    -1,    -1,    -1,  1336,  1337,
      -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      -1,    -1,    -1,    -1,    87,    88,     6,    90,    91,    92,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
    1378,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,  1396,    -1,
    1398,    -1,   185,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,  1413,    -1,  1415,    -1,    -1,
    1418,    -1,    -1,    -1,    -1,    -1,    -1,  1425,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1438,    -1,    -1,     6,    -1,  1443,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,  1459,     6,    -1,   185,    -1,    -1,    -1,  1466,    -1,
    1468,   194,  1470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1480,    -1,    -1,    -1,  1484,  1485,  1486,  1487,
    1488,    -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,  1503,  1504,    -1,    -1,    -1,
    1508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
    1518,    -1,    -1,    -1,  1522,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,    -1,  1557,
      -1,    -1,    -1,    -1,    -1,    -1,  1564,    -1,    -1,    -1,
      -1,    -1,    -1,  1571,    -1,    -1,  1574,    -1,    -1,  1577,
      -1,    -1,    -1,  1581,    -1,    -1,    -1,  1585,    -1,  1587,
    1588,  1589,  1590,  1591,    -1,    -1,    -1,    -1,    -1,    -1,
    1598,    -1,    -1,  1601,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,     6,    -1,
      -1,    -1,   185,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     6,    -1,    -1,
    1638,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1653,    -1,  1655,  1656,  1657,
    1658,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,  1697,
    1698,  1699,  1700,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,  1418,    -1,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     5,    -1,    -1,    -1,   185,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,  1459,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,  1480,    48,    -1,    -1,    -1,
      -1,    53,    54,   143,    -1,    57,    -1,    -1,    -1,   149,
     150,   151,   152,     7,    -1,    -1,    68,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,   176,   177,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,    -1,
     190,   191,    -1,   193,    -1,   195,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,   150,   151,
    1585,    -1,  1587,    45,    46,    47,    -1,    49,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,   106,    -1,    -1,   109,  1653,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,   185,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   149,     8,    -1,
     152,   185,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   176,   177,    -1,    -1,   185,   181,
      -1,    -1,    -1,    -1,   186,    -1,   193,     3,     4,   191,
      -1,   193,   194,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   177,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,   191,    -1,    -1,   194,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,   109,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,   149,   150,   151,   152,    -1,
      -1,     8,    -1,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,   186,    -1,     3,     4,     5,   191,    -1,   193,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     8,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,     3,     4,     5,    -1,    67,    68,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    -1,    -1,    57,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,   191,    -1,   193,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     149,   150,   151,   152,   185,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,   186,    -1,     3,
       4,     5,   191,    -1,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   194,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   177,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,   186,    -1,     3,     4,     5,   191,    -1,   193,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,   150,
     151,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,   162,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
     109,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    91,    92,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,   186,    -1,     3,
       4,     5,   191,    -1,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,   109,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   176,   177,    -1,    -1,   185,   181,   187,    -1,
      -1,    -1,   186,   192,     3,     4,    -1,   191,    -1,   193,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
     109,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   176,   177,    -1,
      -1,   185,   181,    -1,    -1,    -1,    -1,   186,   192,     3,
       4,    -1,   191,    -1,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,   109,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   176,   177,    -1,    -1,   185,   181,    -1,    -1,
      -1,    -1,   186,   192,     3,     4,    -1,   191,    -1,   193,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
     109,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   176,   177,    -1,
      -1,   185,   181,    -1,    -1,    -1,    -1,   186,   192,     3,
       4,    -1,   191,    -1,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,   109,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   176,   177,    -1,    -1,   185,   181,    -1,    -1,
      -1,    -1,   186,   192,     3,     4,    -1,   191,    -1,   193,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
     109,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   176,   177,    -1,
      -1,   185,   181,    -1,    -1,    -1,    -1,   186,   192,     3,
       4,    -1,   191,    -1,   193,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,     3,     4,
       5,    -1,    -1,    67,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,   194,    -1,   157,   158,   159,   160,   161,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   176,   177,    -1,    -1,   185,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,   194,    -1,   191,    -1,   193,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   149,   150,   151,   152,   185,    -1,
     187,    -1,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,   177,    -1,    -1,    -1,   181,     3,     4,    -1,
      -1,   186,    -1,     9,    10,    11,   191,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,    -1,    -1,   109,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     176,   177,    -1,    -1,   185,   181,     3,     4,    -1,    -1,
     186,   192,     9,    10,    11,   191,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    59,    60,    61,    -1,     9,    10,    11,    -1,
      67,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   194,    -1,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   176,
     177,    -1,    -1,   185,   181,    -1,    -1,    -1,    -1,   186,
      -1,   193,   189,    -1,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   176,   177,    -1,    -1,   185,   181,   187,
      -1,   189,    -1,   186,     3,     4,   189,    -1,   191,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,   181,    50,    51,    52,    -1,   186,    55,    56,
      -1,    58,   191,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,   115,   116,
     117,     4,    -1,    -1,    -1,    -1,   123,    -1,    -1,    12,
      13,   128,   129,   130,   131,    -1,    -1,   134,    -1,   136,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    37,    38,   153,   154,   155,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    55,    56,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
      -1,   134,    -1,   136,    -1,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,   192,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,   189,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
     189,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,   189,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,   189,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   189,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,   189,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,   189,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,   189,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,    -1,    -1,   189,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
     189,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,   189,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,   189,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
     187,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,   187,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,   185,    -1,   187,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,   187,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
     187,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,   187,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,   185,    -1,   187,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,   187,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,
     187,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,   185,
      -1,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
     185,    -1,   187,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,   185,    -1,   187,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,   185,    -1,   187,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,   185,    -1,   187,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,   185
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   197,   198,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    55,    56,    58,    62,    63,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   115,   116,   117,   123,   128,   129,   130,   131,
     134,   136,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   153,   154,   155,   156,   199,   201,   202,
     222,   239,   240,   243,   244,   245,   246,   247,   248,   249,
     270,   271,   272,   273,   291,   292,     3,     4,     5,     9,
      10,    11,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    53,    54,    57,    59,    60,
      61,    67,    68,   143,   149,   150,   151,   152,   157,   158,
     159,   160,   161,   162,   176,   177,   181,   186,   188,   190,
     191,   193,   195,   220,   274,   275,   287,   288,   291,   292,
      13,    77,   186,   186,     6,   193,     6,     6,     6,     6,
     186,     6,     6,   188,   188,   186,   188,   220,   220,   186,
     193,   186,   186,     4,   186,   193,   186,   186,     4,   193,
     186,   186,    81,    77,    77,     6,   193,    71,    74,    77,
      77,    77,    74,    77,    79,    79,    71,    74,    77,    79,
      74,    77,    79,    74,    77,   186,    74,   134,   147,   148,
     193,   176,   177,   186,   193,   277,   278,   277,   193,    71,
      74,    77,   193,   277,     4,    71,    75,    87,    77,    79,
      77,    74,     4,   143,   193,     4,     6,    71,    74,    77,
      74,    77,     4,     4,     4,     4,     5,    36,    71,    74,
      77,    79,    91,   177,   186,   193,   240,   249,   274,   280,
     281,   282,   291,   292,     4,   186,   186,   186,     4,   193,
     284,     4,   186,   186,     6,     6,   188,     4,   291,   292,
       4,     5,   193,     5,   193,     4,   274,     6,   186,   193,
     188,   195,   220,     7,   163,   164,   165,   166,   183,   184,
     218,   219,     4,   188,   190,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     186,   186,   186,   186,   186,   186,   220,   186,   220,   220,
     220,     7,   186,   186,   186,   220,   186,   186,   274,   274,
     274,   274,   189,   274,     4,   134,   135,   292,     4,   240,
     241,   242,   193,   193,     6,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   185,
     193,     6,   188,   219,     6,   274,     4,   287,   288,   292,
     287,   274,   287,   290,   224,   227,   288,   292,   274,   177,
     274,   282,   283,   274,   274,   186,   274,   283,   274,   274,
     186,   283,   274,   274,   280,   186,   193,   283,   281,   281,
     281,   186,   186,   281,   281,   281,   186,   186,   186,   186,
     186,   186,   186,   186,   280,   274,     4,   280,   284,   193,
     193,   277,   277,   277,   274,   274,   176,   177,   193,   193,
     277,   193,   193,   193,   176,   177,   186,   242,   277,   193,
     186,   193,   186,   186,   186,   281,   281,   280,   186,     4,
       6,   188,   188,   242,     6,   193,   193,   193,   281,   281,
     188,   188,   188,   188,   190,   220,   188,     5,   137,   193,
       5,   137,     5,   137,     5,   137,    71,    74,    77,    79,
     193,   274,   282,   274,   194,   283,     8,   178,     6,   188,
     220,     6,   274,   274,   274,   190,   274,   193,   137,   274,
     274,   274,     6,     6,   242,     6,   242,   188,     6,   280,
     280,   189,   274,   193,   193,   288,   280,     6,   188,   274,
       4,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   290,   287,   290,   287,   287,   287,   280,
     287,   287,   274,   290,   287,   274,   288,   274,   287,   287,
     287,   287,   292,   288,   187,     7,   218,   189,     7,   218,
     219,   190,     7,   188,   194,    71,    74,    77,    79,   239,
     274,   283,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   203,   274,     6,
     188,   190,   187,   192,   187,   192,   192,   187,   192,   189,
     192,   223,   189,   223,   192,   192,   187,   178,   192,   194,
     187,   187,   274,   187,   194,   187,   187,   274,   194,   187,
     187,     7,   274,   274,   194,     6,     6,     6,   274,   274,
       7,     7,   267,   267,   274,   233,   274,   288,   234,   274,
     288,   235,   274,   288,   236,   274,   288,   274,   274,   274,
       7,   193,   187,     6,   193,   242,   242,   192,   192,   192,
     277,   277,   241,   241,   192,   274,   274,   274,   274,   253,
     192,   242,   274,   274,   274,   274,   274,     7,   268,     6,
       7,   274,     6,   274,   274,   194,   283,   283,   283,     6,
       6,   274,   274,   274,   274,     4,   187,   189,   193,   221,
     292,    50,   274,    50,    50,    50,     5,   193,     5,   193,
       5,   193,     5,   193,   283,   187,   194,   274,   193,   274,
     282,   193,   221,   187,   187,   187,   134,   192,   242,   193,
       8,   187,   189,   194,   194,   187,   192,   194,   218,   189,
     274,   283,     6,     6,   274,   189,   219,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   192,   221,
     221,   221,   221,   221,   221,   221,   192,   192,   192,   221,
     192,   221,   221,   187,   187,   192,   192,   192,   192,   192,
     187,   221,   276,   289,     6,   192,   187,   187,   192,   221,
     187,   187,   218,   280,   190,   218,   219,   288,   274,     6,
       4,     4,   193,   285,   189,   193,   193,   193,   193,   194,
     194,     8,     4,   124,   125,   126,   127,   194,   206,   210,
     213,   215,   216,   189,   274,     4,     6,   173,   200,   283,
       6,   283,   274,     6,   287,     6,   292,     6,   287,   274,
     288,     7,   274,   282,   137,     7,     7,   187,     7,   137,
       7,     7,   187,   137,     7,     7,   274,   187,   194,   193,
     187,   187,   274,   280,     4,   266,     6,   187,   187,   187,
     187,   187,   187,   187,   187,   280,   283,   190,   242,   194,
     194,   277,   274,   274,   194,   194,   274,   277,   192,   192,
     192,    94,   104,   112,   113,   114,   118,   119,   120,   121,
     263,   264,   277,   194,   250,   187,   194,   187,   187,   187,
     274,     6,   274,   187,   189,   189,   194,   194,   194,   189,
     189,   192,   189,   283,   189,   193,   194,   193,   193,   193,
     283,   283,   283,   283,   194,     8,   283,   283,     7,     7,
       7,   190,   274,   194,   274,   274,     7,   190,   193,   280,
       6,   280,   218,   219,   194,   194,   189,   190,   219,   287,
     274,   274,   274,   274,   283,   287,   280,   287,   287,   288,
     229,   231,   274,   287,   274,     6,     4,   134,   135,   274,
       6,     6,     6,     7,   188,   284,   286,     6,   283,   283,
     283,   283,   221,   274,   207,   186,   186,   193,   217,     6,
     219,   189,   173,   287,   187,   187,   192,     7,   221,   221,
     277,    77,    79,   280,   280,     7,   280,    77,    79,   280,
     280,     7,    79,   280,   280,     6,     7,     7,   283,     7,
       7,    94,   265,     6,     7,   218,   218,   218,   218,     7,
       7,     7,     6,   194,     4,   194,   192,   192,   192,   194,
     194,   277,   277,   277,     4,     6,   193,     6,   186,     6,
     122,     6,   122,     6,   122,     6,   122,   194,   264,   192,
     263,     7,     6,     7,     7,     7,     6,   193,     6,     6,
       6,    77,   274,     6,     6,   274,   190,   194,   274,   274,
     274,   274,   194,   194,   194,   194,   274,   194,   194,   280,
     280,   280,     4,   192,     8,     8,   187,     4,     4,   280,
     194,     6,   274,     6,   221,     6,     4,     6,   221,   221,
     221,   221,   221,   192,   187,   187,   187,   192,   192,   221,
     230,   192,   221,   232,   187,   187,     6,     7,   218,   219,
     190,     7,     6,   284,   274,   192,   194,   194,   194,   194,
     194,   218,   186,   274,   274,   279,   280,   193,   190,     6,
       6,   200,     6,   274,   193,   274,   288,     6,     6,     6,
     193,   193,    87,   238,   238,   280,     6,   193,   193,     6,
       6,   280,   193,     6,     6,     5,   280,   194,   280,   280,
       4,     6,   280,   280,   280,   280,   280,   280,   280,   280,
       7,     6,     7,   274,   274,   274,   193,   193,   192,   194,
     192,   194,   192,   194,   188,   274,   280,   274,     6,     6,
       6,     6,   274,   277,   194,     5,   193,   280,   193,   193,
     193,   280,   283,   193,     6,   189,     4,   221,   192,   192,
     192,   192,   221,     6,     6,   133,   274,   274,   274,     6,
       6,     7,   192,     6,     6,   218,   219,   287,   288,     4,
       4,   288,   274,     6,     4,   285,     6,   189,   284,     6,
       6,     6,     6,   280,   204,   274,   192,   192,   192,   194,
     205,   274,     4,   287,   192,   274,   288,   274,   274,   277,
       6,     6,     6,   274,   274,     6,   274,     5,     6,   193,
       6,   137,   237,   274,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   274,   274,   288,   194,   187,   192,   194,
     241,   241,   277,     6,   254,   277,     6,   255,   277,     6,
     256,   274,   194,   192,   187,   194,   192,     6,   177,   277,
       6,   279,   277,   277,     6,   194,   274,     6,   274,   274,
     274,   274,   280,   192,   194,     8,   194,   187,   193,   274,
     288,   280,   280,   187,   221,   193,   280,   288,   193,   274,
     288,     6,     6,     7,     6,   190,     6,   187,   192,   274,
     274,   280,   193,   192,   194,     6,   274,   225,   226,   194,
     194,   194,   194,   194,     5,   279,    75,     6,   193,   193,
       6,     6,   193,   274,   194,   194,   192,   193,   192,   193,
     192,   193,   189,     6,   280,     7,   193,   274,   192,   194,
     192,   192,     6,   194,   192,   192,   192,   192,   132,   274,
     274,   283,     6,     6,   194,     6,   228,   274,   290,   284,
     135,   208,   274,   192,   192,   279,   274,     6,   192,   229,
     231,     6,     6,     6,     6,     6,     6,   194,   193,   279,
     283,   241,   192,   194,   274,   277,   263,   274,   277,   263,
     274,   277,   263,     6,   192,   194,   280,   242,   194,   277,
       6,   283,   277,   274,   274,   274,   274,   274,   194,   194,
     194,     6,   192,   194,     7,   194,     6,   193,   274,   274,
     194,   274,   194,   194,   193,   274,   194,   194,   194,   274,
     194,   192,   194,   194,   192,   194,   194,   192,   194,   280,
       6,    94,   194,   251,   193,   192,   194,   192,   192,   192,
     192,   192,     6,     6,   274,   288,   205,   187,   192,     6,
     193,   192,   274,   194,     6,    94,   269,   194,     6,   257,
     274,     6,     6,   258,   274,     6,     6,   259,   274,     6,
     194,   274,   263,   242,   283,     6,   277,   283,   274,   274,
     274,   274,     7,   194,   211,   274,   279,   274,   192,   280,
       6,   193,   194,   193,   194,   193,   194,     6,     6,   194,
     194,   252,   194,   192,   194,   192,   192,   192,   192,   288,
       6,   193,   187,   194,   194,   274,   263,     6,   260,   263,
       6,   261,   263,     6,   262,   263,     6,   283,     6,   274,
     274,   274,   274,   209,   287,   214,   193,     6,   194,   194,
     193,   194,   193,   194,   193,   194,   194,   192,   192,   192,
     192,   192,   194,   193,   279,     6,     6,   263,     6,   263,
       6,   263,     6,   274,   274,   274,   274,   287,     6,   212,
     287,   194,   194,   194,   194,   194,   194,   194,   194,   192,
     194,     6,     6,     6,     6,   287,     6
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
#line 186 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 197 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 198 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 199 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 200 "Gmsh.y"
    { return 1; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 201 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 202 "Gmsh.y"
    { return 1; }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 203 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 204 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 205 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { return 1; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 207 "Gmsh.y"
    { return 1; }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 208 "Gmsh.y"
    { return 1; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 209 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 210 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 211 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 216 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 220 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 227 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 232 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 237 "Gmsh.y"
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
#line 251 "Gmsh.y"
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
#line 264 "Gmsh.y"
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
#line 277 "Gmsh.y"
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
#line 305 "Gmsh.y"
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
#line 319 "Gmsh.y"
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
#line 332 "Gmsh.y"
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
#line 345 "Gmsh.y"
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
#line 363 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 377 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 379 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 384 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 386 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 391 "Gmsh.y"
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
#line 495 "Gmsh.y"
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
#line 505 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 514 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 521 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 531 "Gmsh.y"
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
#line 540 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 549 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 556 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 566 "Gmsh.y"
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
#line 574 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 584 "Gmsh.y"
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
#line 603 "Gmsh.y"
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
#line 622 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 628 "Gmsh.y"
    {
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 635 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 638 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 639 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 643 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 644 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 650 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 650 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 660 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 665 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 671 "Gmsh.y"
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

  case 74:
/* Line 1787 of yacc.c  */
#line 732 "Gmsh.y"
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

  case 75:
/* Line 1787 of yacc.c  */
#line 761 "Gmsh.y"
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

  case 76:
/* Line 1787 of yacc.c  */
#line 790 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 795 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 800 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 805 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 812 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 819 "Gmsh.y"
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

  case 82:
/* Line 1787 of yacc.c  */
#line 834 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 839 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 844 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 853 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 859 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 868 "Gmsh.y"
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

  case 88:
/* Line 1787 of yacc.c  */
#line 886 "Gmsh.y"
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

  case 89:
/* Line 1787 of yacc.c  */
#line 904 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 913 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 925 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 930 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 938 "Gmsh.y"
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

  case 94:
/* Line 1787 of yacc.c  */
#line 958 "Gmsh.y"
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

  case 95:
/* Line 1787 of yacc.c  */
#line 981 "Gmsh.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 992 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 1000 "Gmsh.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 1022 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 1045 "Gmsh.y"
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

  case 100:
/* Line 1787 of yacc.c  */
#line 1071 "Gmsh.y"
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

  case 101:
/* Line 1787 of yacc.c  */
#line 1092 "Gmsh.y"
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

  case 102:
/* Line 1787 of yacc.c  */
#line 1104 "Gmsh.y"
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

  case 106:
/* Line 1787 of yacc.c  */
#line 1122 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 1131 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 1140 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 1142 "Gmsh.y"
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

  case 110:
/* Line 1787 of yacc.c  */
#line 1152 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1161 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1163 "Gmsh.y"
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

  case 114:
/* Line 1787 of yacc.c  */
#line 1177 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1185 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1191 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1203 "Gmsh.y"
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

  case 120:
/* Line 1787 of yacc.c  */
#line 1214 "Gmsh.y"
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

  case 121:
/* Line 1787 of yacc.c  */
#line 1229 "Gmsh.y"
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
#line 1245 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 1253 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 1262 "Gmsh.y"
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
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
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
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
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
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1319 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1323 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1332 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1336 "Gmsh.y"
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

  case 137:
/* Line 1787 of yacc.c  */
#line 1348 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1352 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1362 "Gmsh.y"
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

  case 140:
/* Line 1787 of yacc.c  */
#line 1385 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 1417 "Gmsh.y"
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

  case 142:
/* Line 1787 of yacc.c  */
#line 1440 "Gmsh.y"
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

  case 143:
/* Line 1787 of yacc.c  */
#line 1458 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1479 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1497 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1527 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1557 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1575 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1594 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1620 "Gmsh.y"
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

  case 151:
/* Line 1787 of yacc.c  */
#line 1638 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1656 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1691 "Gmsh.y"
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

  case 154:
/* Line 1787 of yacc.c  */
#line 1709 "Gmsh.y"
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

  case 155:
/* Line 1787 of yacc.c  */
#line 1748 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1754 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1760 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1767 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1792 "Gmsh.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1817 "Gmsh.y"
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

  case 161:
/* Line 1787 of yacc.c  */
#line 1834 "Gmsh.y"
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

  case 162:
/* Line 1787 of yacc.c  */
#line 1854 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1887 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1923 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1941 "Gmsh.y"
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

  case 166:
/* Line 1787 of yacc.c  */
#line 1958 "Gmsh.y"
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

  case 167:
/* Line 1787 of yacc.c  */
#line 1974 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].i);
      int op = (yyvsp[(6) - (8)].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exists", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[(7) - (8)].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++){
          double d;
          List_Read((yyvsp[(7) - (8)].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 2011 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 2016 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 2021 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 2026 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 2031 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2036 "Gmsh.y"
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

  case 174:
/* Line 1787 of yacc.c  */
#line 2059 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2065 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2075 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2076 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 2081 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2085 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2089 "Gmsh.y"
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

  case 181:
/* Line 1787 of yacc.c  */
#line 2112 "Gmsh.y"
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

  case 182:
/* Line 1787 of yacc.c  */
#line 2135 "Gmsh.y"
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

  case 183:
/* Line 1787 of yacc.c  */
#line 2158 "Gmsh.y"
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

  case 184:
/* Line 1787 of yacc.c  */
#line 2186 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2207 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2234 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2255 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2276 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2296 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2408 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2427 "Gmsh.y"
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

  case 192:
/* Line 1787 of yacc.c  */
#line 2466 "Gmsh.y"
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

  case 193:
/* Line 1787 of yacc.c  */
#line 2574 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 2583 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 2589 "Gmsh.y"
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

  case 196:
/* Line 1787 of yacc.c  */
#line 2604 "Gmsh.y"
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

  case 197:
/* Line 1787 of yacc.c  */
#line 2632 "Gmsh.y"
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

  case 198:
/* Line 1787 of yacc.c  */
#line 2649 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2658 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 2672 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 2678 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 2684 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2693 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2702 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2711 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2725 "Gmsh.y"
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

  case 207:
/* Line 1787 of yacc.c  */
#line 2781 "Gmsh.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 2799 "Gmsh.y"
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

  case 209:
/* Line 1787 of yacc.c  */
#line 2816 "Gmsh.y"
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

  case 210:
/* Line 1787 of yacc.c  */
#line 2831 "Gmsh.y"
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

  case 211:
/* Line 1787 of yacc.c  */
#line 2850 "Gmsh.y"
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

  case 212:
/* Line 1787 of yacc.c  */
#line 2862 "Gmsh.y"
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

  case 213:
/* Line 1787 of yacc.c  */
#line 2886 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 2890 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 2895 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 2902 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 2907 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 2913 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2918 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2924 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2932 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2936 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2940 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2946 "Gmsh.y"
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

  case 225:
/* Line 1787 of yacc.c  */
#line 3000 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 3013 "Gmsh.y"
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

  case 227:
/* Line 1787 of yacc.c  */
#line 3030 "Gmsh.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 3047 "Gmsh.y"
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

  case 229:
/* Line 1787 of yacc.c  */
#line 3068 "Gmsh.y"
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

  case 230:
/* Line 1787 of yacc.c  */
#line 3089 "Gmsh.y"
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

  case 231:
/* Line 1787 of yacc.c  */
#line 3124 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 3132 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 3138 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 3145 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 3149 "Gmsh.y"
    {
    }
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 3158 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3166 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3182 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3188 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3196 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3210 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3216 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3224 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3230 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3238 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3252 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3266 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3280 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3287 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3294 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3301 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3307 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3314 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3320 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3327 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3340 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3346 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3353 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3359 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3366 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3372 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3379 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3385 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3392 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3398 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3411 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3422 "Gmsh.y"
    {
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3425 "Gmsh.y"
    {
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3431 "Gmsh.y"
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

  case 277:
/* Line 1787 of yacc.c  */
#line 3443 "Gmsh.y"
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

  case 278:
/* Line 1787 of yacc.c  */
#line 3463 "Gmsh.y"
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

  case 279:
/* Line 1787 of yacc.c  */
#line 3487 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3491 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3495 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 3499 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 3503 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 3509 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3515 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3519 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3523 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3527 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3531 "Gmsh.y"
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

  case 290:
/* Line 1787 of yacc.c  */
#line 3550 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3562 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3566 "Gmsh.y"
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

  case 293:
/* Line 1787 of yacc.c  */
#line 3581 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3585 "Gmsh.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 3601 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3605 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3610 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 3614 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3620 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 3624 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3631 "Gmsh.y"
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

  case 302:
/* Line 1787 of yacc.c  */
#line 3687 "Gmsh.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 3757 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3762 "Gmsh.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 3829 "Gmsh.y"
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

  case 306:
/* Line 1787 of yacc.c  */
#line 3865 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 3873 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3916 "Gmsh.y"
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

  case 309:
/* Line 1787 of yacc.c  */
#line 3955 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3975 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 4003 "Gmsh.y"
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

  case 312:
/* Line 1787 of yacc.c  */
#line 4051 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 4079 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 4107 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 4111 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 4115 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4143 "Gmsh.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 4182 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4221 "Gmsh.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 4242 "Gmsh.y"
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

  case 321:
/* Line 1787 of yacc.c  */
#line 4263 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4290 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 4294 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4304 "Gmsh.y"
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

  case 325:
/* Line 1787 of yacc.c  */
#line 4338 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 4339 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 4340 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4345 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 4351 "Gmsh.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 4363 "Gmsh.y"
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

  case 331:
/* Line 1787 of yacc.c  */
#line 4381 "Gmsh.y"
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

  case 332:
/* Line 1787 of yacc.c  */
#line 4408 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4409 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4410 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 4411 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 4412 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 4413 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4414 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4415 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4417 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4423 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4424 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4425 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4426 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4427 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4428 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4429 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4430 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4431 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4432 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4433 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4434 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4435 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4436 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4440 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4441 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4442 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4444 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4445 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4447 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4448 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4449 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4450 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4451 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4453 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4454 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4455 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4464 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4465 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4466 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4467 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4469 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4470 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4471 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4472 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4473 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4478 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4486 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4491 "Gmsh.y"
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

  case 388:
/* Line 1787 of yacc.c  */
#line 4508 "Gmsh.y"
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

  case 389:
/* Line 1787 of yacc.c  */
#line 4526 "Gmsh.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 4544 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4549 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4555 "Gmsh.y"
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

  case 393:
/* Line 1787 of yacc.c  */
#line 4567 "Gmsh.y"
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

  case 394:
/* Line 1787 of yacc.c  */
#line 4584 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4602 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4623 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 4628 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4633 "Gmsh.y"
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

  case 399:
/* Line 1787 of yacc.c  */
#line 4643 "Gmsh.y"
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

  case 400:
/* Line 1787 of yacc.c  */
#line 4653 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 4658 "Gmsh.y"
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        matches += List_Search((yyvsp[(5) - (6)].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[(3) - (6)].l)); Free((yyvsp[(5) - (6)].l));
    }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 4669 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 4678 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 4683 "Gmsh.y"
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

  case 405:
/* Line 1787 of yacc.c  */
#line 4710 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4714 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4718 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 4722 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 4726 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4733 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 4737 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4741 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4745 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 4752 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4757 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4764 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4769 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4773 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4778 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4782 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4790 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4801 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4805 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4817 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4825 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4833 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4840 "Gmsh.y"
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

  case 428:
/* Line 1787 of yacc.c  */
#line 4850 "Gmsh.y"
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

  case 429:
/* Line 1787 of yacc.c  */
#line 4879 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4883 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4887 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4891 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4895 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4899 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4903 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4907 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 4911 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 4940 "Gmsh.y"
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

  case 439:
/* Line 1787 of yacc.c  */
#line 4969 "Gmsh.y"
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

  case 440:
/* Line 1787 of yacc.c  */
#line 4998 "Gmsh.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 5028 "Gmsh.y"
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

  case 442:
/* Line 1787 of yacc.c  */
#line 5041 "Gmsh.y"
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

  case 443:
/* Line 1787 of yacc.c  */
#line 5054 "Gmsh.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 5067 "Gmsh.y"
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

  case 445:
/* Line 1787 of yacc.c  */
#line 5079 "Gmsh.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 5089 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5099 "Gmsh.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 5111 "Gmsh.y"
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

  case 449:
/* Line 1787 of yacc.c  */
#line 5123 "Gmsh.y"
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

  case 450:
/* Line 1787 of yacc.c  */
#line 5135 "Gmsh.y"
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

  case 451:
/* Line 1787 of yacc.c  */
#line 5153 "Gmsh.y"
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

  case 452:
/* Line 1787 of yacc.c  */
#line 5174 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 453:
/* Line 1787 of yacc.c  */
#line 5179 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 5183 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 455:
/* Line 1787 of yacc.c  */
#line 5187 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 456:
/* Line 1787 of yacc.c  */
#line 5199 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 457:
/* Line 1787 of yacc.c  */
#line 5203 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 458:
/* Line 1787 of yacc.c  */
#line 5215 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 459:
/* Line 1787 of yacc.c  */
#line 5222 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 460:
/* Line 1787 of yacc.c  */
#line 5232 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 461:
/* Line 1787 of yacc.c  */
#line 5236 "Gmsh.y"
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

  case 462:
/* Line 1787 of yacc.c  */
#line 5251 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5256 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5263 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5267 "Gmsh.y"
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

  case 466:
/* Line 1787 of yacc.c  */
#line 5280 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5288 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5299 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5303 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5311 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 471:
/* Line 1787 of yacc.c  */
#line 5317 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5323 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5331 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5339 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 475:
/* Line 1787 of yacc.c  */
#line 5346 "Gmsh.y"
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

  case 476:
/* Line 1787 of yacc.c  */
#line 5361 "Gmsh.y"
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

  case 477:
/* Line 1787 of yacc.c  */
#line 5375 "Gmsh.y"
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

  case 478:
/* Line 1787 of yacc.c  */
#line 5389 "Gmsh.y"
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

  case 479:
/* Line 1787 of yacc.c  */
#line 5401 "Gmsh.y"
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

  case 480:
/* Line 1787 of yacc.c  */
#line 5417 "Gmsh.y"
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

  case 481:
/* Line 1787 of yacc.c  */
#line 5428 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5432 "Gmsh.y"
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

  case 483:
/* Line 1787 of yacc.c  */
#line 5451 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5458 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 485:
/* Line 1787 of yacc.c  */
#line 5460 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 5471 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 5476 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 5482 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 5491 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 5504 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 5507 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11540 "Gmsh.tab.cpp"
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
#line 5511 "Gmsh.y"


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
    sstream.precision(12);
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
