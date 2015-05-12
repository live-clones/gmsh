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
     tMacro = 401,
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
     tSetPartition = 418,
     tAFFECTDIVIDE = 419,
     tAFFECTTIMES = 420,
     tAFFECTMINUS = 421,
     tAFFECTPLUS = 422,
     tOR = 423,
     tAND = 424,
     tNOTEQUAL = 425,
     tEQUAL = 426,
     tGREATEROREQUAL = 427,
     tLESSOREQUAL = 428,
     UNARYPREC = 429,
     tMINUSMINUS = 430,
     tPLUSPLUS = 431
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
#line 403 "Gmsh.tab.cpp"
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
#line 431 "Gmsh.tab.cpp"

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
#define YYLAST   9315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  197
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  500
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1763

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   431

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   182,     2,   192,     2,   181,     2,     2,
     187,   188,   179,   177,   193,   178,   191,   180,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     173,     2,   174,   168,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   189,     2,   190,   186,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   194,     2,   195,   196,     2,     2,     2,
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
     165,   166,   167,   169,   170,   171,   172,   175,   176,   183,
     184,   185
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    49,    55,    61,    69,    77,    85,
      95,   102,   109,   116,   125,   126,   129,   132,   135,   138,
     141,   143,   147,   149,   153,   154,   155,   166,   168,   172,
     173,   187,   189,   193,   194,   210,   219,   234,   235,   242,
     244,   246,   248,   250,   252,   254,   256,   258,   260,   262,
     264,   270,   276,   284,   292,   297,   304,   311,   319,   327,
     335,   343,   353,   363,   367,   374,   381,   388,   395,   400,
     407,   417,   424,   434,   440,   449,   458,   470,   477,   487,
     493,   501,   511,   521,   533,   541,   551,   561,   562,   564,
     565,   569,   575,   576,   586,   592,   593,   603,   604,   608,
     612,   618,   619,   622,   626,   632,   636,   637,   640,   644,
     648,   654,   656,   658,   660,   662,   664,   666,   668,   670,
     671,   677,   678,   681,   689,   698,   705,   713,   718,   726,
     735,   744,   752,   760,   772,   781,   790,   799,   808,   818,
     822,   827,   838,   846,   854,   863,   872,   885,   894,   903,
     911,   920,   929,   935,   947,   953,   963,   973,   978,   988,
     998,  1000,  1002,  1003,  1006,  1013,  1020,  1027,  1034,  1043,
    1054,  1069,  1086,  1099,  1108,  1117,  1124,  1139,  1144,  1151,
    1158,  1162,  1167,  1173,  1180,  1186,  1190,  1194,  1199,  1205,
    1210,  1216,  1220,  1226,  1234,  1242,  1246,  1254,  1258,  1261,
    1264,  1267,  1270,  1273,  1289,  1292,  1295,  1298,  1301,  1304,
    1321,  1325,  1332,  1341,  1350,  1361,  1363,  1366,  1368,  1372,
    1377,  1379,  1385,  1397,  1411,  1412,  1420,  1421,  1435,  1436,
    1452,  1453,  1460,  1469,  1478,  1487,  1500,  1513,  1526,  1541,
    1556,  1571,  1572,  1585,  1586,  1599,  1600,  1613,  1614,  1631,
    1632,  1649,  1650,  1667,  1668,  1687,  1688,  1707,  1708,  1727,
    1729,  1732,  1738,  1746,  1756,  1759,  1762,  1765,  1769,  1772,
    1776,  1779,  1783,  1786,  1790,  1800,  1807,  1808,  1812,  1813,
    1815,  1816,  1819,  1820,  1823,  1824,  1827,  1835,  1842,  1851,
    1857,  1861,  1869,  1875,  1880,  1887,  1894,  1908,  1919,  1930,
    1941,  1952,  1963,  1968,  1973,  1978,  1983,  1988,  1991,  1995,
    2002,  2004,  2006,  2008,  2011,  2017,  2025,  2036,  2038,  2042,
    2045,  2048,  2051,  2055,  2059,  2063,  2067,  2071,  2075,  2079,
    2083,  2087,  2091,  2095,  2099,  2103,  2107,  2113,  2118,  2123,
    2128,  2133,  2138,  2143,  2148,  2153,  2158,  2163,  2170,  2175,
    2180,  2185,  2190,  2195,  2200,  2205,  2212,  2219,  2226,  2231,
    2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,
    2252,  2259,  2264,  2266,  2271,  2276,  2281,  2286,  2291,  2296,
    2301,  2304,  2310,  2316,  2322,  2328,  2332,  2339,  2344,  2352,
    2359,  2366,  2373,  2380,  2385,  2387,  2390,  2393,  2397,  2401,
    2413,  2423,  2431,  2439,  2441,  2445,  2447,  2449,  2452,  2456,
    2461,  2467,  2469,  2471,  2474,  2478,  2482,  2488,  2493,  2496,
    2499,  2502,  2505,  2509,  2513,  2517,  2521,  2527,  2533,  2539,
    2545,  2562,  2579,  2596,  2613,  2615,  2617,  2621,  2625,  2630,
    2637,  2644,  2646,  2648,  2652,  2656,  2666,  2674,  2676,  2682,
    2686,  2693,  2695,  2699,  2701,  2703,  2707,  2714,  2716,  2718,
    2720,  2722,  2727,  2734,  2739,  2744,  2749,  2754,  2763,  2768,
    2777,  2782,  2789,  2794,  2795,  2802,  2804,  2808,  2814,  2820,
    2822
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     198,     0,    -1,   199,    -1,     1,     6,    -1,    -1,   199,
     200,    -1,   203,    -1,   202,    -1,   223,    -1,   240,    -1,
     241,    -1,   245,    -1,   246,    -1,   247,    -1,   248,    -1,
     251,    -1,   272,    -1,   273,    -1,   250,    -1,   249,    -1,
     244,    -1,   275,    -1,   174,    -1,   174,   174,    -1,    37,
     187,   289,   188,     6,    -1,    38,   187,   289,   188,     6,
      -1,    37,   187,   289,   188,   201,   289,     6,    -1,    37,
     187,   289,   193,   285,   188,     6,    -1,    38,   187,   289,
     193,   285,   188,     6,    -1,    37,   187,   289,   193,   285,
     188,   201,   289,     6,    -1,     4,   289,   194,   204,   195,
       6,    -1,   115,     4,   189,   276,   190,     6,    -1,   116,
       4,   189,   276,   190,     6,    -1,   117,     4,   189,   276,
     193,   276,   190,     6,    -1,    -1,   204,   207,    -1,   204,
     211,    -1,   204,   214,    -1,   204,   216,    -1,   204,   217,
      -1,   276,    -1,   205,   193,   276,    -1,   276,    -1,   206,
     193,   276,    -1,    -1,    -1,     4,   208,   187,   205,   188,
     209,   194,   206,   195,     6,    -1,   289,    -1,   210,   193,
     289,    -1,    -1,   124,   187,   276,   193,   276,   193,   276,
     188,   212,   194,   210,   195,     6,    -1,   289,    -1,   213,
     193,   289,    -1,    -1,   125,   187,   276,   193,   276,   193,
     276,   193,   276,   188,   215,   194,   213,   195,     6,    -1,
     126,   194,   281,   195,   194,   281,   195,     6,    -1,   126,
     194,   281,   195,   194,   281,   195,   194,   281,   195,   194,
     281,   195,     6,    -1,    -1,   127,   218,   194,   206,   195,
       6,    -1,     7,    -1,   167,    -1,   166,    -1,   165,    -1,
     164,    -1,   185,    -1,   184,    -1,   187,    -1,   189,    -1,
     188,    -1,   190,    -1,    65,   189,   225,   190,     6,    -1,
      66,   189,   228,   190,     6,    -1,    69,   221,   290,   193,
     276,   222,     6,    -1,    70,   221,   294,   193,   290,   222,
       6,    -1,   294,   219,   282,     6,    -1,     4,   221,   222,
     219,   282,     6,    -1,   293,   221,   222,   219,   282,     6,
      -1,     4,   189,   276,   190,   219,   276,     6,    -1,     4,
     187,   276,   188,   219,   276,     6,    -1,   293,   189,   276,
     190,   219,   276,     6,    -1,   293,   187,   276,   188,   219,
     276,     6,    -1,     4,   221,   194,   285,   195,   222,   219,
     282,     6,    -1,   293,   221,   194,   285,   195,   222,   219,
     282,     6,    -1,   294,   220,     6,    -1,     4,   189,   276,
     190,   220,     6,    -1,     4,   187,   276,   188,   220,     6,
      -1,   293,   189,   276,   190,   220,     6,    -1,   293,   187,
     276,   188,   220,     6,    -1,   294,     7,   290,     6,    -1,
       4,   191,     4,     7,   290,     6,    -1,     4,   189,   276,
     190,   191,     4,     7,   290,     6,    -1,     4,   191,     4,
     219,   276,     6,    -1,     4,   189,   276,   190,   191,     4,
     219,   276,     6,    -1,     4,   191,     4,   220,     6,    -1,
       4,   189,   276,   190,   191,     4,   220,     6,    -1,     4,
     191,   134,   191,     4,     7,   286,     6,    -1,     4,   189,
     276,   190,   191,   134,   191,     4,     7,   286,     6,    -1,
       4,   191,   135,     7,   287,     6,    -1,     4,   189,   276,
     190,   191,   135,     7,   287,     6,    -1,     4,   143,     7,
     276,     6,    -1,   143,   189,   276,   190,     7,     4,     6,
      -1,   143,   189,   276,   190,   191,     4,     7,   276,     6,
      -1,   143,   189,   276,   190,   191,     4,     7,   290,     6,
      -1,   143,   189,   276,   190,   191,     4,     7,   194,   285,
     195,     6,    -1,   143,   189,   276,   190,   191,     4,     6,
      -1,    95,   187,     4,   188,   191,     4,     7,   276,     6,
      -1,    95,   187,     4,   188,   191,     4,     7,   290,     6,
      -1,    -1,   193,    -1,    -1,   225,   224,   294,    -1,   225,
     224,   294,     7,   276,    -1,    -1,   225,   224,   294,     7,
     194,   276,   226,   230,   195,    -1,   225,   224,   294,     7,
     290,    -1,    -1,   225,   224,   294,     7,   194,   290,   227,
     232,   195,    -1,    -1,   228,   224,   289,    -1,   276,     7,
     290,    -1,   229,   193,   276,     7,   290,    -1,    -1,   230,
     231,    -1,   193,     4,   282,    -1,   193,     4,   194,   229,
     195,    -1,   193,     4,   290,    -1,    -1,   232,   233,    -1,
     193,     4,   276,    -1,   193,     4,   290,    -1,   193,     4,
     194,   292,   195,    -1,   276,    -1,   290,    -1,   276,    -1,
     290,    -1,   276,    -1,   290,    -1,   276,    -1,   290,    -1,
      -1,   137,    75,   194,   276,   195,    -1,    -1,    87,   279,
      -1,    71,   187,   276,   188,     7,   279,     6,    -1,    91,
      71,   187,   234,   188,   219,   282,     6,    -1,    80,    81,
     282,     7,   276,     6,    -1,    74,   187,   276,   188,     7,
     282,     6,    -1,    96,    74,   282,     6,    -1,    78,   187,
     276,   188,     7,   282,     6,    -1,    72,   187,   276,   188,
       7,   282,   239,     6,    -1,    73,   187,   276,   188,     7,
     282,   239,     6,    -1,   129,   187,   276,   188,     7,   282,
       6,    -1,   130,   187,   276,   188,     7,   282,     6,    -1,
     131,   187,   276,   188,     7,   282,   133,   282,   132,   276,
       6,    -1,    74,     4,   187,   276,   188,     7,   282,     6,
      -1,    92,    74,   187,   276,   188,     7,   282,     6,    -1,
      91,    74,   187,   235,   188,   219,   282,     6,    -1,    87,
      77,   187,   276,   188,     7,   282,     6,    -1,    88,    77,
     187,   276,   188,     7,   282,   238,     6,    -1,    12,    13,
       6,    -1,    13,    77,   276,     6,    -1,    82,    77,   187,
     276,   188,     7,     5,     5,     5,     6,    -1,    75,   187,
     276,   188,     7,   282,     6,    -1,    76,   187,   276,   188,
       7,   282,     6,    -1,    77,     4,   187,   276,   188,     7,
     282,     6,    -1,    92,    77,   187,   276,   188,     7,   282,
       6,    -1,    92,    77,   187,   276,   188,     7,   282,     4,
     194,   281,   195,     6,    -1,    91,    77,   187,   236,   188,
     219,   282,     6,    -1,    90,    79,   187,   276,   188,     7,
     282,     6,    -1,    79,   187,   276,   188,     7,   282,     6,
      -1,    92,    79,   187,   276,   188,     7,   282,     6,    -1,
      91,    79,   187,   237,   188,   219,   282,     6,    -1,    99,
     279,   194,   242,   195,    -1,    98,   194,   279,   193,   279,
     193,   276,   195,   194,   242,   195,    -1,   100,   279,   194,
     242,   195,    -1,   101,   194,   279,   193,   276,   195,   194,
     242,   195,    -1,   101,   194,   279,   193,   279,   195,   194,
     242,   195,    -1,     4,   194,   242,   195,    -1,   109,    74,
     194,   285,   195,    77,   194,   276,   195,    -1,   106,    74,
     187,   276,   188,   194,   285,   195,     6,    -1,   243,    -1,
     241,    -1,    -1,   243,   240,    -1,   243,    71,   194,   285,
     195,     6,    -1,   243,    74,   194,   285,   195,     6,    -1,
     243,    77,   194,   285,   195,     6,    -1,   243,    79,   194,
     285,   195,     6,    -1,   103,    87,   187,   276,   188,     7,
     282,     6,    -1,   103,    71,   187,   276,   188,     7,   194,
     281,   195,     6,    -1,   103,    87,   187,   276,   188,     7,
     194,   279,   193,   279,   193,   285,   195,     6,    -1,   103,
      87,   187,   276,   188,     7,   194,   279,   193,   279,   193,
     279,   193,   285,   195,     6,    -1,   103,    75,   187,   276,
     188,     7,   194,   279,   193,   285,   195,     6,    -1,   103,
       4,   187,   276,   188,     7,   282,     6,    -1,   103,     4,
     187,   276,   188,     7,     5,     6,    -1,   103,     4,   194,
     276,   195,     6,    -1,   103,     4,   187,   276,   188,     7,
     194,   279,   193,   279,   193,   285,   195,     6,    -1,   107,
     194,   243,   195,    -1,   107,   143,   189,   276,   190,     6,
      -1,   107,     4,   189,   276,   190,     6,    -1,   107,     4,
       6,    -1,   107,     4,     4,     6,    -1,   134,   286,   194,
     243,   195,    -1,    97,   134,   286,   194,   243,   195,    -1,
     163,   276,   194,   243,   195,    -1,   147,     5,     6,    -1,
     148,     5,     6,    -1,   147,   194,   243,   195,    -1,    97,
     147,   194,   243,   195,    -1,   148,   194,   243,   195,    -1,
      97,   148,   194,   243,   195,    -1,     4,   290,     6,    -1,
      58,   187,   292,   188,     6,    -1,     4,     4,   189,   276,
     190,   289,     6,    -1,     4,     4,     4,   189,   276,   190,
       6,    -1,     4,   276,     6,    -1,    95,   187,     4,   188,
     191,     4,     6,    -1,   128,     4,     6,    -1,   141,     6,
      -1,   142,     6,    -1,    55,     6,    -1,    56,     6,    -1,
      50,     6,    -1,    50,   194,   276,   193,   276,   193,   276,
     193,   276,   193,   276,   193,   276,   195,     6,    -1,    51,
       6,    -1,    52,     6,    -1,    62,     6,    -1,    63,     6,
      -1,    84,     6,    -1,    85,   194,   285,   195,   194,   285,
     195,   194,   281,   195,   194,   276,   193,   276,   195,     6,
      -1,   156,   276,     6,    -1,   136,   187,   276,     8,   276,
     188,    -1,   136,   187,   276,     8,   276,     8,   276,   188,
      -1,   136,     4,   137,   194,   276,     8,   276,   195,    -1,
     136,     4,   137,   194,   276,     8,   276,     8,   276,   195,
      -1,   138,    -1,   146,     4,    -1,   144,    -1,   145,   294,
       6,    -1,   139,   187,   276,   188,    -1,   140,    -1,   102,
     279,   194,   243,   195,    -1,   102,   194,   279,   193,   279,
     193,   276,   195,   194,   243,   195,    -1,   102,   194,   279,
     193,   279,   193,   279,   193,   276,   195,   194,   243,   195,
      -1,    -1,   102,   279,   194,   243,   252,   265,   195,    -1,
      -1,   102,   194,   279,   193,   279,   193,   276,   195,   194,
     243,   253,   265,   195,    -1,    -1,   102,   194,   279,   193,
     279,   193,   279,   193,   276,   195,   194,   243,   254,   265,
     195,    -1,    -1,   102,   194,   243,   255,   265,   195,    -1,
     102,    71,   194,   276,   193,   279,   195,     6,    -1,   102,
      74,   194,   276,   193,   279,   195,     6,    -1,   102,    77,
     194,   276,   193,   279,   195,     6,    -1,   102,    71,   194,
     276,   193,   279,   193,   279,   193,   276,   195,     6,    -1,
     102,    74,   194,   276,   193,   279,   193,   279,   193,   276,
     195,     6,    -1,   102,    77,   194,   276,   193,   279,   193,
     279,   193,   276,   195,     6,    -1,   102,    71,   194,   276,
     193,   279,   193,   279,   193,   279,   193,   276,   195,     6,
      -1,   102,    74,   194,   276,   193,   279,   193,   279,   193,
     279,   193,   276,   195,     6,    -1,   102,    77,   194,   276,
     193,   279,   193,   279,   193,   279,   193,   276,   195,     6,
      -1,    -1,   102,    71,   194,   276,   193,   279,   195,   256,
     194,   265,   195,     6,    -1,    -1,   102,    74,   194,   276,
     193,   279,   195,   257,   194,   265,   195,     6,    -1,    -1,
     102,    77,   194,   276,   193,   279,   195,   258,   194,   265,
     195,     6,    -1,    -1,   102,    71,   194,   276,   193,   279,
     193,   279,   193,   276,   195,   259,   194,   265,   195,     6,
      -1,    -1,   102,    74,   194,   276,   193,   279,   193,   279,
     193,   276,   195,   260,   194,   265,   195,     6,    -1,    -1,
     102,    77,   194,   276,   193,   279,   193,   279,   193,   276,
     195,   261,   194,   265,   195,     6,    -1,    -1,   102,    71,
     194,   276,   193,   279,   193,   279,   193,   279,   193,   276,
     195,   262,   194,   265,   195,     6,    -1,    -1,   102,    74,
     194,   276,   193,   279,   193,   279,   193,   279,   193,   276,
     195,   263,   194,   265,   195,     6,    -1,    -1,   102,    77,
     194,   276,   193,   279,   193,   279,   193,   279,   193,   276,
     195,   264,   194,   265,   195,     6,    -1,   266,    -1,   265,
     266,    -1,   112,   194,   276,   195,     6,    -1,   112,   194,
     282,   193,   282,   195,     6,    -1,   112,   194,   282,   193,
     282,   193,   282,   195,     6,    -1,   113,     6,    -1,   104,
       6,    -1,   120,     6,    -1,   120,   122,     6,    -1,   121,
       6,    -1,   121,   122,     6,    -1,   118,     6,    -1,   118,
     122,     6,    -1,   119,     6,    -1,   119,   122,     6,    -1,
     114,   187,   276,   188,     7,   282,    94,   276,     6,    -1,
      94,     4,   189,   276,   190,     6,    -1,    -1,    94,     4,
     276,    -1,    -1,     4,    -1,    -1,     7,   282,    -1,    -1,
       7,   276,    -1,    -1,    94,   282,    -1,    89,    74,   283,
       7,   276,   267,     6,    -1,    89,    77,   283,   269,   268,
       6,    -1,    83,    77,   194,   276,   195,     7,   282,     6,
      -1,    89,    79,   283,   269,     6,    -1,   123,   283,     6,
      -1,   110,    77,   194,   285,   195,   276,     6,    -1,   104,
      77,   283,   270,     6,    -1,   104,    79,   283,     6,    -1,
     105,    77,   282,     7,   276,     6,    -1,    93,    74,   282,
       7,   282,     6,    -1,    93,    77,   276,   194,   285,   195,
       7,   276,   194,   285,   195,   271,     6,    -1,    71,   194,
     285,   195,   137,    77,   194,   276,   195,     6,    -1,    74,
     194,   285,   195,   137,    77,   194,   276,   195,     6,    -1,
      71,   194,   285,   195,   137,    79,   194,   276,   195,     6,
      -1,    74,   194,   285,   195,   137,    79,   194,   276,   195,
       6,    -1,    77,   194,   285,   195,   137,    79,   194,   276,
     195,     6,    -1,   111,    77,   283,     6,    -1,   111,    74,
     283,     6,    -1,    86,    71,   283,     6,    -1,    86,    74,
     283,     6,    -1,    86,    77,   283,     6,    -1,   108,     6,
      -1,   108,     4,     6,    -1,   108,    71,   194,   285,   195,
       6,    -1,   153,    -1,   154,    -1,   155,    -1,   274,     6,
      -1,   274,   194,   282,   195,     6,    -1,   274,   194,   282,
     193,   282,   195,     6,    -1,   274,   187,   282,   188,   194,
     282,   193,   282,   195,     6,    -1,   277,    -1,   187,   276,
     188,    -1,   178,   276,    -1,   177,   276,    -1,   182,   276,
      -1,   276,   178,   276,    -1,   276,   177,   276,    -1,   276,
     179,   276,    -1,   276,   180,   276,    -1,   276,   181,   276,
      -1,   276,   186,   276,    -1,   276,   173,   276,    -1,   276,
     174,   276,    -1,   276,   176,   276,    -1,   276,   175,   276,
      -1,   276,   172,   276,    -1,   276,   171,   276,    -1,   276,
     170,   276,    -1,   276,   169,   276,    -1,   276,   168,   276,
       8,   276,    -1,    14,   221,   276,   222,    -1,    15,   221,
     276,   222,    -1,    16,   221,   276,   222,    -1,    17,   221,
     276,   222,    -1,    18,   221,   276,   222,    -1,    19,   221,
     276,   222,    -1,    20,   221,   276,   222,    -1,    21,   221,
     276,   222,    -1,    22,   221,   276,   222,    -1,    24,   221,
     276,   222,    -1,    25,   221,   276,   193,   276,   222,    -1,
      26,   221,   276,   222,    -1,    27,   221,   276,   222,    -1,
      28,   221,   276,   222,    -1,    29,   221,   276,   222,    -1,
      30,   221,   276,   222,    -1,    31,   221,   276,   222,    -1,
      32,   221,   276,   222,    -1,    33,   221,   276,   193,   276,
     222,    -1,    34,   221,   276,   193,   276,   222,    -1,    35,
     221,   276,   193,   276,   222,    -1,    23,   221,   276,   222,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,   159,
      -1,   160,    -1,   161,    -1,    59,    -1,    60,    -1,    61,
      -1,    -1,    67,   221,   276,   278,   230,   222,    -1,   152,
     221,   289,   222,    -1,   294,    -1,     4,   189,   276,   190,
      -1,     4,   187,   276,   188,    -1,   293,   189,   276,   190,
      -1,   293,   187,   276,   188,    -1,   157,   187,   294,   188,
      -1,   158,   187,   290,   188,    -1,   192,   294,   221,   222,
      -1,   294,   220,    -1,     4,   189,   276,   190,   220,    -1,
       4,   187,   276,   188,   220,    -1,   293,   189,   276,   190,
     220,    -1,   293,   187,   276,   188,   220,    -1,     4,   191,
       4,    -1,     4,   189,   276,   190,   191,     4,    -1,     4,
     191,     4,   220,    -1,     4,   189,   276,   190,   191,     4,
     220,    -1,   149,   187,   289,   193,   276,   188,    -1,    45,
     187,   282,   193,   282,   188,    -1,    46,   187,   289,   193,
     289,   188,    -1,    47,   187,   289,   193,   289,   188,    -1,
      49,   187,   292,   188,    -1,   280,    -1,   178,   279,    -1,
     177,   279,    -1,   279,   178,   279,    -1,   279,   177,   279,
      -1,   194,   276,   193,   276,   193,   276,   193,   276,   193,
     276,   195,    -1,   194,   276,   193,   276,   193,   276,   193,
     276,   195,    -1,   194,   276,   193,   276,   193,   276,   195,
      -1,   187,   276,   193,   276,   193,   276,   188,    -1,   282,
      -1,   281,   193,   282,    -1,   276,    -1,   284,    -1,   194,
     195,    -1,   194,   285,   195,    -1,   178,   194,   285,   195,
      -1,   276,   179,   194,   285,   195,    -1,   282,    -1,     5,
      -1,   178,   284,    -1,   276,   179,   284,    -1,   276,     8,
     276,    -1,   276,     8,   276,     8,   276,    -1,    71,   194,
     276,   195,    -1,    71,     5,    -1,    74,     5,    -1,    77,
       5,    -1,    79,     5,    -1,    91,    71,     5,    -1,    91,
      74,     5,    -1,    91,    77,     5,    -1,    91,    79,     5,
      -1,    91,    71,   194,   285,   195,    -1,    91,    74,   194,
     285,   195,    -1,    91,    77,   194,   285,   195,    -1,    91,
      79,   194,   285,   195,    -1,    71,   137,    50,   194,   276,
     193,   276,   193,   276,   193,   276,   193,   276,   193,   276,
     195,    -1,    74,   137,    50,   194,   276,   193,   276,   193,
     276,   193,   276,   193,   276,   193,   276,   195,    -1,    77,
     137,    50,   194,   276,   193,   276,   193,   276,   193,   276,
     193,   276,   193,   276,   195,    -1,    79,   137,    50,   194,
     276,   193,   276,   193,   276,   193,   276,   193,   276,   193,
     276,   195,    -1,   241,    -1,   251,    -1,     4,   221,   222,
      -1,   293,   221,   222,    -1,    36,   189,   294,   190,    -1,
       4,   221,   194,   285,   195,   222,    -1,   293,   221,   194,
     285,   195,   222,    -1,   276,    -1,   284,    -1,   285,   193,
     276,    -1,   285,   193,   284,    -1,   194,   276,   193,   276,
     193,   276,   193,   276,   195,    -1,   194,   276,   193,   276,
     193,   276,   195,    -1,     4,    -1,     4,   191,   134,   191,
       4,    -1,   194,   288,   195,    -1,     4,   189,   276,   190,
     191,   135,    -1,   286,    -1,   288,   193,   286,    -1,   290,
      -1,   294,    -1,     4,   191,     4,    -1,     4,   189,   276,
     190,   191,     4,    -1,     5,    -1,    53,    -1,   162,    -1,
      57,    -1,   150,   187,   289,   188,    -1,   151,   187,   289,
     193,   289,   188,    -1,   151,   187,   289,   188,    -1,    41,
     221,   292,   222,    -1,    42,   187,   289,   188,    -1,    43,
     187,   289,   188,    -1,    44,   187,   289,   193,   289,   193,
     289,   188,    -1,    39,   221,   292,   222,    -1,    48,   221,
     276,   193,   290,   193,   290,   222,    -1,    40,   221,   289,
     222,    -1,    40,   221,   289,   193,   285,   222,    -1,    54,
     221,   289,   222,    -1,    -1,    68,   221,   290,   291,   232,
     222,    -1,   289,    -1,   292,   193,   289,    -1,     4,   196,
     194,   276,   195,    -1,   293,   196,   194,   276,   195,    -1,
       4,    -1,   293,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   191,   193,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   216,   220,   227,   232,   237,   251,   264,   277,
     305,   319,   332,   345,   364,   369,   370,   371,   372,   373,
     377,   379,   384,   386,   392,   496,   391,   514,   521,   532,
     531,   549,   556,   567,   566,   583,   600,   623,   622,   636,
     637,   638,   639,   640,   644,   645,   651,   651,   652,   652,
     658,   659,   660,   665,   671,   731,   760,   789,   794,   799,
     804,   809,   816,   823,   838,   843,   848,   853,   858,   867,
     873,   882,   900,   918,   927,   939,   944,   952,   972,   995,
    1006,  1014,  1036,  1059,  1085,  1106,  1118,  1132,  1132,  1134,
    1136,  1145,  1155,  1154,  1166,  1176,  1175,  1189,  1191,  1199,
    1205,  1212,  1213,  1217,  1228,  1243,  1253,  1254,  1259,  1267,
    1276,  1294,  1298,  1307,  1311,  1320,  1324,  1333,  1337,  1347,
    1350,  1363,  1366,  1376,  1399,  1431,  1454,  1472,  1493,  1511,
    1541,  1571,  1589,  1607,  1634,  1652,  1670,  1705,  1723,  1762,
    1768,  1774,  1781,  1806,  1831,  1848,  1867,  1901,  1937,  1955,
    1972,  1988,  2025,  2030,  2035,  2040,  2045,  2050,  2073,  2079,
    2090,  2091,  2096,  2099,  2103,  2126,  2149,  2172,  2200,  2221,
    2247,  2268,  2290,  2310,  2422,  2441,  2479,  2588,  2597,  2603,
    2618,  2646,  2663,  2672,  2686,  2700,  2706,  2712,  2721,  2730,
    2739,  2753,  2809,  2827,  2844,  2859,  2878,  2890,  2914,  2918,
    2923,  2930,  2935,  2941,  2946,  2952,  2960,  2964,  2968,  2973,
    3028,  3041,  3058,  3075,  3096,  3117,  3152,  3160,  3166,  3173,
    3177,  3186,  3194,  3202,  3211,  3210,  3225,  3224,  3239,  3238,
    3253,  3252,  3266,  3273,  3280,  3287,  3294,  3301,  3308,  3315,
    3322,  3330,  3329,  3343,  3342,  3356,  3355,  3369,  3368,  3382,
    3381,  3395,  3394,  3408,  3407,  3421,  3420,  3434,  3433,  3450,
    3453,  3459,  3471,  3491,  3515,  3519,  3523,  3527,  3531,  3537,
    3543,  3547,  3551,  3555,  3559,  3578,  3591,  3594,  3610,  3613,
    3630,  3633,  3639,  3642,  3649,  3652,  3659,  3715,  3785,  3790,
    3857,  3893,  3901,  3944,  3983,  4003,  4030,  4079,  4107,  4135,
    4139,  4143,  4171,  4210,  4249,  4270,  4291,  4318,  4322,  4332,
    4367,  4368,  4369,  4373,  4379,  4391,  4409,  4437,  4438,  4439,
    4440,  4441,  4442,  4443,  4444,  4445,  4452,  4453,  4454,  4455,
    4456,  4457,  4458,  4459,  4460,  4461,  4462,  4463,  4464,  4465,
    4466,  4467,  4468,  4469,  4470,  4471,  4472,  4473,  4474,  4475,
    4476,  4477,  4478,  4479,  4480,  4481,  4482,  4483,  4484,  4493,
    4494,  4495,  4496,  4497,  4498,  4499,  4500,  4501,  4502,  4507,
    4506,  4514,  4519,  4536,  4554,  4572,  4590,  4608,  4613,  4619,
    4631,  4648,  4666,  4684,  4702,  4723,  4728,  4733,  4743,  4753,
    4758,  4769,  4778,  4783,  4810,  4814,  4818,  4822,  4826,  4833,
    4837,  4841,  4845,  4852,  4857,  4864,  4869,  4873,  4878,  4882,
    4890,  4901,  4905,  4917,  4925,  4933,  4940,  4950,  4979,  4983,
    4987,  4991,  4995,  4999,  5003,  5007,  5011,  5040,  5069,  5098,
    5127,  5140,  5153,  5166,  5179,  5189,  5199,  5211,  5224,  5236,
    5254,  5275,  5280,  5284,  5288,  5300,  5304,  5316,  5323,  5333,
    5337,  5352,  5357,  5364,  5368,  5381,  5389,  5400,  5404,  5412,
    5418,  5424,  5432,  5440,  5447,  5462,  5476,  5490,  5502,  5518,
    5529,  5533,  5552,  5560,  5559,  5572,  5577,  5583,  5592,  5605,
    5608
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
  "tReturn", "tCall", "tMacro", "tShow", "tHide", "tGetValue", "tGetEnv",
  "tGetString", "tGetNumber", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS",
  "tAFFECTPLUS", "'?'", "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'",
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", "'('", "')'",
  "'['", "']'", "'.'", "'#'", "','", "'{'", "'}'", "'~'", "$accept", "All",
  "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "$@6", "$@7", "UndefineConstants", "Enumeration",
  "FloatParameterOptions", "FloatParameterOption", "CharParameterOptions",
  "CharParameterOption", "PhysicalId0", "PhysicalId1", "PhysicalId2",
  "PhysicalId3", "InSphereCenter", "CircleOptions", "Shape", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Loop", "Extrude", "$@8", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "ExtrudeParameters", "ExtrudeParameter",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "$@21", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "$@22", "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULL
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
     415,   416,   417,   418,   419,   420,   421,   422,    63,   423,
     424,   425,   426,    60,    62,   427,   428,    43,    45,    42,
      47,    37,    33,   429,   430,   431,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   197,   198,   198,   199,   199,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   201,   201,   202,   202,   202,   202,   202,   202,
     203,   203,   203,   203,   204,   204,   204,   204,   204,   204,
     205,   205,   206,   206,   208,   209,   207,   210,   210,   212,
     211,   213,   213,   215,   214,   216,   216,   218,   217,   219,
     219,   219,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   224,   224,   225,
     225,   225,   226,   225,   225,   227,   225,   228,   228,   229,
     229,   230,   230,   231,   231,   231,   232,   232,   233,   233,
     233,   234,   234,   235,   235,   236,   236,   237,   237,   238,
     238,   239,   239,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   241,   241,   241,   241,   241,   241,   241,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   245,   245,   245,
     245,   245,   246,   246,   247,   248,   248,   248,   248,   248,
     248,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   251,   251,   251,   252,   251,   253,   251,   254,   251,
     255,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   256,   251,   257,   251,   258,   251,   259,   251,   260,
     251,   261,   251,   262,   251,   263,   251,   264,   251,   265,
     265,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     269,   269,   270,   270,   271,   271,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   273,
     274,   274,   274,   275,   275,   275,   275,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   278,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   279,   279,   279,   279,   279,   280,
     280,   280,   280,   281,   281,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   285,   285,   286,   286,   286,   286,   287,
     287,   288,   288,   289,   289,   289,   289,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   291,   290,   292,   292,   293,   293,   294,
     294
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     5,     7,     7,     7,     9,
       6,     6,     6,     8,     0,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     0,     0,    10,     1,     3,     0,
      13,     1,     3,     0,    15,     8,    14,     0,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     7,     7,     4,     6,     6,     7,     7,     7,
       7,     9,     9,     3,     6,     6,     6,     6,     4,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,    11,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     5,     0,     9,     0,     3,     3,
       5,     0,     2,     3,     5,     3,     0,     2,     3,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     2,     7,     8,     6,     7,     4,     7,     8,
       8,     7,     7,    11,     8,     8,     8,     8,     9,     3,
       4,    10,     7,     7,     8,     8,    12,     8,     8,     7,
       8,     8,     5,    11,     5,     9,     9,     4,     9,     9,
       1,     1,     0,     2,     6,     6,     6,     6,     8,    10,
      14,    16,    12,     8,     8,     6,    14,     4,     6,     6,
       3,     4,     5,     6,     5,     3,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     7,     3,     2,     2,
       2,     2,     2,    15,     2,     2,     2,     2,     2,    16,
       3,     6,     8,     8,    10,     1,     2,     1,     3,     4,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     8,     8,     8,    12,    12,    12,    14,    14,
      14,     0,    12,     0,    12,     0,    12,     0,    16,     0,
      16,     0,    16,     0,    18,     0,    18,     0,    18,     1,
       2,     5,     7,     9,     2,     2,     2,     3,     2,     3,
       2,     3,     2,     3,     9,     6,     0,     3,     0,     1,
       0,     2,     0,     2,     0,     2,     7,     6,     8,     5,
       3,     7,     5,     4,     6,     6,    13,    10,    10,    10,
      10,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     5,     5,     3,     6,     4,     7,     6,
       6,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     3,     3,     4,     6,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     3,     6,     1,     1,     1,
       1,     4,     6,     4,     4,     4,     4,     8,     4,     8,
       4,     6,     4,     0,     6,     1,     3,     5,     5,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,     0,   240,     0,     0,     0,   237,     0,
       0,     0,     0,   330,   331,   332,     0,     0,     5,     7,
       6,     8,     9,    10,    20,    11,    12,    13,    14,    19,
      18,    15,    16,    17,     0,    21,   500,     0,   379,   499,
     477,   380,   381,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   478,     0,   480,
     386,   387,   388,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,   384,   385,   479,     0,     0,     0,    66,
      67,     0,     0,   182,     0,     0,     0,   337,     0,   473,
     500,   392,     0,     0,     0,     0,   222,     0,   224,   225,
     220,   221,     0,   226,   227,   109,   117,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   414,     0,
       0,     0,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   182,     0,   327,     0,
       0,     0,     0,     0,     0,     0,     0,   499,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,   455,
     425,   431,     0,   426,   500,   392,     0,     0,     0,     0,
     467,     0,     0,     0,     0,     0,   218,   219,     0,   499,
     500,     0,   236,     0,   182,     0,   182,   499,     0,     0,
     333,     0,     0,    66,    67,     0,     0,    59,    63,    62,
      61,    60,    65,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,   339,   341,     0,     0,     0,     0,
       0,     0,     0,   181,     0,   180,     0,    68,    69,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,   211,     0,
       0,   400,   159,     0,   499,     0,   473,   474,     0,     0,
     495,     0,   107,   107,     0,     0,     0,     0,   461,   462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   300,   300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,   182,     0,
     416,   415,     0,     0,     0,     0,   182,   182,     0,     0,
       0,     0,     0,     0,     0,   250,     0,   182,     0,     0,
       0,     0,     0,   302,     0,     0,     0,     0,   200,     0,
       0,     0,   328,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,     0,   438,     0,     0,   439,
       0,   440,     0,   441,     0,     0,     0,     0,     0,     0,
     339,   433,     0,   427,     0,     0,     0,   310,    66,    67,
       0,   217,     0,     0,     0,     0,     0,   182,     0,     0,
       0,     0,   238,   205,     0,   206,     0,     0,   230,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   389,   493,
       0,     0,     0,     0,     0,     0,     0,   338,     0,    59,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
     183,     0,     0,    59,     0,     0,   355,   354,   353,   352,
     348,   349,   351,   350,   343,   342,   344,   345,   346,   347,
       0,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   324,
     325,   326,     0,     0,     0,     0,   298,     0,     0,     0,
     131,   132,     0,   133,   134,     0,   135,   136,     0,   137,
     138,     0,     0,     0,     0,     0,     0,   147,   182,     0,
       0,     0,     0,     0,   418,   417,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,   201,     0,     0,   197,
       0,     0,     0,   323,   322,     0,     0,     0,     0,   405,
       0,   456,     0,     0,     0,     0,     0,     0,   442,     0,
     443,     0,   444,     0,   445,     0,     0,   338,   428,   435,
       0,   344,   434,     0,   457,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,   207,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    74,     0,   394,
     393,   407,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   378,   366,     0,   368,   369,   370,   371,   372,   373,
     374,     0,     0,     0,   488,     0,   490,   484,   485,   486,
       0,     0,     0,     0,     0,   413,   492,   121,   126,    99,
       0,   481,   483,     0,   391,   397,   398,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,   399,
       0,     0,     0,     0,   497,     0,     0,     0,    44,     0,
       0,     0,    57,     0,    35,    36,    37,    38,    39,   396,
     395,     0,   475,    24,    22,     0,     0,    25,     0,     0,
     212,   496,    70,   110,    71,   118,     0,     0,     0,   463,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
     301,   299,     0,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   210,     0,     0,
       0,   172,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
     241,     0,     0,     0,     0,     0,     0,   303,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   393,
       0,   458,     0,   437,     0,     0,     0,     0,     0,     0,
       0,   429,     0,     0,     0,     0,     0,     0,     0,     0,
     202,     0,     0,     0,     0,   204,     0,     0,   334,     0,
       0,     0,     0,   498,     0,     0,     0,   402,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,    84,    89,    91,     0,     0,   471,     0,    97,     0,
       0,     0,     0,     0,    75,   356,     0,     0,     0,     0,
       0,    30,   404,   403,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   315,     0,     0,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,     0,
     284,     0,   290,     0,   292,     0,   286,     0,   288,     0,
     251,   280,     0,     0,     0,   195,     0,     0,     0,   314,
       0,   199,   198,   329,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,   446,   447,   448,   449,   436,
     430,     0,     0,     0,     0,   468,     0,     0,     0,   231,
       0,     0,     0,     0,     0,    87,     0,    86,     0,    76,
     214,   406,   213,   367,   375,   376,   377,   491,     0,   410,
     411,   412,     0,     0,   390,   122,     0,   494,   127,   409,
     482,    78,    59,     0,     0,     0,     0,    77,     0,     0,
       0,   469,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,    26,    27,     0,    28,     0,     0,
     111,   114,    72,    73,   143,     0,     0,     0,     0,     0,
       0,   146,     0,     0,   162,   163,     0,     0,   148,   169,
       0,     0,     0,     0,   139,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,     0,     0,
       0,   182,   182,     0,   261,     0,   263,     0,   265,     0,
     425,     0,     0,   291,   293,   287,   289,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   311,
       0,   406,   459,     0,     0,     0,     0,   460,   151,   152,
       0,     0,     0,     0,   100,   104,     0,     0,   335,    80,
      79,     0,   408,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,   472,   184,   185,   186,   187,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   476,     0,
       0,   112,   115,     0,     0,   142,   149,   150,   154,     0,
       0,   164,     0,     0,   308,     0,   157,     0,     0,   297,
     168,   144,   156,   167,   171,   155,     0,   165,   170,     0,
       0,     0,     0,   422,     0,   421,     0,     0,     0,   252,
       0,     0,   253,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,   194,     0,     0,   193,     0,     0,     0,
     188,     0,     0,    33,     0,     0,     0,     0,     0,     0,
     466,     0,   233,   232,     0,     0,     0,     0,     0,   487,
     489,     0,   123,   125,     0,   128,   129,    90,    92,     0,
      98,     0,    81,    45,     0,     0,     0,   424,     0,     0,
       0,    29,     0,   121,   126,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,   105,   106,   182,     0,
     175,   176,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,   182,     0,     0,     0,     0,     0,   179,   178,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
       0,    82,     0,   461,     0,     0,   470,     0,    41,     0,
       0,     0,    43,    58,     0,     0,     0,   317,   319,   318,
     320,   321,   161,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,   246,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,   465,   234,     0,   336,     0,   124,
       0,   130,    96,     0,     0,     0,     0,     0,   113,   116,
       0,     0,     0,   304,   173,     0,   267,     0,     0,   269,
       0,     0,   271,     0,     0,     0,   282,     0,   242,     0,
     182,     0,     0,     0,     0,     0,     0,     0,   153,   103,
       0,   119,     0,    49,     0,    55,     0,     0,     0,   140,
     166,     0,     0,   419,   255,     0,     0,   262,   256,     0,
       0,   264,   257,     0,     0,   266,     0,     0,     0,   248,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,   316,     0,   273,     0,
     275,     0,   277,   283,   294,   247,   243,     0,     0,     0,
       0,     0,     0,     0,     0,   120,    46,     0,    53,     0,
       0,     0,     0,   258,     0,     0,   259,     0,     0,   260,
       0,     0,   196,     0,   190,     0,     0,     0,     0,     0,
      47,     0,     0,   223,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,   268,     0,   270,     0,   272,     0,   191,     0,
       0,     0,     0,    48,    50,     0,    51,     0,     0,     0,
       0,   450,   451,   452,   453,     0,     0,    56,   274,   276,
     278,    52,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    88,   905,    89,    90,   660,  1360,  1366,
     894,  1076,  1527,  1709,   895,  1660,  1745,   896,  1711,   897,
     898,  1080,   334,   421,   175,   400,    91,   675,   432,  1473,
    1474,   433,  1522,  1051,  1215,  1052,  1218,   709,   712,   715,
     718,  1388,  1258,   640,   288,   394,   395,    94,    95,    96,
      97,    98,    99,   100,   289,   981,  1609,  1677,   743,  1410,
    1413,  1416,  1635,  1639,  1643,  1694,  1697,  1700,   977,   978,
    1115,   942,   706,   752,  1632,   102,   103,   104,   105,   290,
     177,   857,   481,   248,  1240,   291,   292,   293,   544,   302,
     878,  1067,   430,   426,   858,   431,   180,   295
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1311
static const yytype_int16 yypact[] =
{
    6459,    47,    67,  6573, -1311, -1311,  3394,     0,   -51,  -114,
     -97,    48,    96,   102,   121,   143,    69,   151,   194,   117,
     147,   -46,   -46,  -142,   167,   185,     8,   196,   206,    16,
     222,   285,   155,   253,   312,   473,   292,   560,   369,   427,
     630,   434,   561,   707,    40,   333,   449,   141,   367,   113,
     113,   374,   -52,    53,   109,   518,   536,    13,    29,   545,
     553,   186,   646,   676,   696,  4605,   720,   524,   540,   552,
      20,    61, -1311,   559, -1311,   736,   759,   584, -1311,   770,
     779,    34,    37, -1311, -1311, -1311,  6326,  6326, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,    -4, -1311,   355,   168, -1311,     7,
   -1311, -1311, -1311, -1311,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   602,
     605,   609,   610,   614,   615,   -46,   624, -1311,   -46, -1311,
   -1311, -1311, -1311,   -46,   -46,   817,   628,   629,   656,   -46,
     667,   678, -1311, -1311, -1311, -1311,  6326,  6326,  6326,  6326,
    6326,    27,   770,   431,   672,   459,   319, -1311,   675,   832,
     366,   243,   876,  6326,  3683,  3683, -1311,  6326, -1311, -1311,
   -1311, -1311,  3683, -1311, -1311, -1311, -1311, -1311, -1311,  1091,
     770,  6326,  6146,  6326,  6326,   705,  6326,  6146,  6326,  6326,
     713,  6146,  6326,  6326,  4977,   719,   715, -1311,  6146,  4605,
    4605,  4605,   734,   740,  4605,  4605,  4605,   760,   761,   766,
     767,   772,   798,   799,   810,  4977,  6326,   926,  4977,    20,
     847,   850,   113,   113,   113,  6326,  6326,   -96, -1311,   -55,
     113,   880,   881,   904,  5907,    77,  -109,   824,   874,   894,
    4605,  4605,  4977,   906,    55,   842, -1311,  1093, -1311,   917,
     918,   919,  4605,  4605,   933,   935,   936,   505, -1311,   937,
      33,     9,    23,    36,   661,  5163,  6326,  3794, -1311, -1311,
    3120, -1311,  1121, -1311,   378,   439,  1132,  6326,  6326,  6326,
     950,  6326,   948,  1006,  6326,  6326, -1311, -1311,  6326,   951,
     953,  1140, -1311,  1144, -1311,  1146, -1311,   499,  1299,  4599,
   -1311,  4977,  4977,  6326,  6326,   959,   497,  1091, -1311, -1311,
   -1311, -1311, -1311, -1311,  4977,  1148,   967,  6326,  6326,  1154,
    6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,
    6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,
    6326,  6326,  3683,  3683,  3683,  3683,  3683,  3683,  4977,  3683,
    3683,  6326,  3683,  3683,  6326,  1091,  6326,  3683,  3683,  3683,
    3683,   770,  1091,   976,   976,   976,  4200,  8028,   259,   972,
    1157,   -46,   971, -1311,   973,  3834,  6326, -1311, -1311,  6146,
      86, -1311,  6326,  6326,  6326,  6326,  6326,  6326,  6326,  6326,
    6326,  6326,  6326,  6326,  6326,  6326,  6326, -1311, -1311,  6326,
    6326, -1311, -1311,  1695,   418,  -156, -1311, -1311,   -99,  4228,
   -1311,   122,    84,   104,   974,   977,  8373,  6146,  3144, -1311,
     108,  8394,  8415,  6326,  8436,   127,  8457,  8478,  6326,   162,
    8499,  8520,  1159,  6326,  6326,   178,  1163,  1165,  1167,  6326,
    6326,  1168,  1169,  1169,  6326,  5966,  5966,  5966,  5966,  6326,
    6326,  6326,  1170,  4785,   990,  1173,   986, -1311, -1311,   -90,
   -1311, -1311,  4414,  5158,   113,   113,   431,   431,   -30,  6326,
    6326,  6326,  5907,  5907,  6326,  3834,    90, -1311,  6326,  6326,
    6326,  6326,  6326,  1174,  1176,  1177,  6326,  1179, -1311,  6326,
    6326,  1116, -1311,  6146,  6146,  6146,  1180,  1191,  6326,  6326,
    6326,  6326,  6326,  1195,   535,   770, -1311,  1133,  6326, -1311,
    1150, -1311,  1152, -1311,  1160,    43,    44,    45,    46,  6146,
     976, -1311,  8541, -1311,   278,  6326,  5349, -1311,  6326,  6326,
     555, -1311,  8562,  8583,  8604,  1075,  5344, -1311,  1019,  3170,
    8625,  8051, -1311, -1311,  1301, -1311,  1327,  6326, -1311, -1311,
    1026,   308,  8646,  8074,  6326,  6146,    86,  1209,  1210, -1311,
    6326,  8667,  8097,   354,  8005,  8005,  8005,  8005,  8005,  8005,
    8005,  8005,  8005,  8005,  8005,  5530,  8005,  8005,  8005,  8005,
    8005,  8005,  8005,  5716,  5961,  6141,   644,   665,   644,  1029,
    1030,  1037,  1038,  1041,  1042,  7017,   135,   359,  9129, -1311,
    1739,  1043,  1035,   224,   359,  1050,  1051,   297,   114,  1091,
    6326,  1234,  1240,    26,   359, -1311,   -50,    25,    30,   -10,
   -1311,  4320,   478, -1311,  4977,  3206,  1583,  1440,   737,   737,
     641,   641,   641,   641,   571,   571,   976,   976,   976,   976,
       6,  8688,  8120, -1311,  6326,  1244,    17,  6146,  1245,  6146,
    6326,  1246,  3683,  1249, -1311,   770,  1250,  3683,  6326,  1091,
    1251,  6146,  6146,  1124,  1255,  1256,  8709,  1257,  1128,  1259,
    1264,  8730,  1135,  1266,  1271,  6326,  8751,  4348,  1086, -1311,
   -1311, -1311,  8772,  8793,  6326,  4977,  1277,  1276,  8814,  1095,
    9129, -1311,  1096,  9129, -1311,  1097,  9129, -1311,  1098,  9129,
   -1311,  8835,  8856,  8877,  4977,  6146,  1100, -1311, -1311,  1471,
    1507,   113,  6326,  6326, -1311, -1311,  1099,  1101,  5907,  7043,
    7069,  7095,  3982,   837,   113,  1998,  8898,  4377,  8919,  8940,
    8961,  6326,  1282, -1311,  6326,  8982, -1311,  8143,  8166, -1311,
     566,   600,   638, -1311, -1311,  8189,  8212,  7121,  8235,   439,
    6146, -1311,  1102,  1104,  4547,  1105,  1106,  1109, -1311,  6146,
   -1311,  6146, -1311,  6146, -1311,  6146,   651, -1311, -1311,  3299,
    6146,   976, -1311,  6146, -1311,  1286,  1288,  1294,  1113,  6326,
    2170,  6326,  6326, -1311,    56, -1311, -1311,  2338,  1112,  4977,
    1303,   297,   297,  4733,   694,  4977, -1311, -1311,  8258,   439,
     111, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311,  6326, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311,  6326,  6326,  6326, -1311,  6146, -1311, -1311, -1311, -1311,
    3683,  4977,  3683,  3683,  1091, -1311, -1311, -1311, -1311, -1311,
    6326, -1311, -1311,  3683, -1311, -1311, -1311,  6326,  1310,    32,
    6326,  1312,  1314,  1871, -1311,  1300,  1134,    20,  1315, -1311,
    6146,  6146,  6146,  6146, -1311,   359,  1316,  6326, -1311,  1137,
    1138,  1136, -1311,  1320, -1311, -1311, -1311, -1311, -1311,   439,
     439,  8281, -1311, -1311,  1155,  3683,   328, -1311,   477,  7147,
   -1311, -1311, -1311,  1321, -1311, -1311,  8005,   359,   113,  3144,
   -1311,   534,  4977,  4977,  1324,  4977,   746,  4977,  4977,  1325,
    1262,  4977,  4977,  1962,  1336,  1337,  6146,  1338,  1340,  3601,
   -1311, -1311,  1342, -1311,  1343,    86,    86,    86,    86,  1345,
    1346,  1347,  1351,   695,  1354,  2431, -1311, -1311,   115,  7173,
    7199, -1311, -1311,  4919,   -59,   113,   113,   113,  1355,  1357,
    1166,  1358,  1162,    50,    54,    58,    63,    -8, -1311,   134,
   -1311,   837,  1359,  1361,  1362,  1363,  1377,  9129, -1311,  2027,
    1171,  1379,  1380,  1381,  1291,  6326,  1384,  1388,  6326,   248,
     702, -1311,  6326, -1311,  6326,  6326,  6326,   703,   706,   710,
     739, -1311,  6326,   743,   744,  4977,  4977,  4977,  1391,  7225,
   -1311,  3344,   170,  1392,  1404, -1311,  4977,  1215, -1311,  6326,
    1405,  6326,  1407, -1311,   359,  1414,  1416, -1311,  1420, -1311,
    1419,  8005,  8005,  8005,  8005,   669,  1233,  1239,  1241,  1248,
    1235,   682,   693,  9003,  1252,  2215, -1311,   361,  1243,  1430,
    2369, -1311, -1311, -1311,    20,  6326, -1311,   749, -1311,   750,
     797,   803,   808,    86, -1311,  9129,  1260,  6326,  6326,  4977,
    1258, -1311, -1311, -1311,  1247, -1311,  1433,    71,  1436,  6326,
    4173,  1437,  1438,    15,  1269,  1270,  1400,  1400,  4977,  1443,
    1272,  1295,  1444,  1482,  4977,  1296,  1485,  1487, -1311,  1441,
    4977,   809,  4977,  4977,  1490,  1491, -1311,  4977,  4977,  4977,
    4977,  4977,  4977,  4977,  4977, -1311,  1492,   637, -1311,  6326,
    6326,  6326,  1306,  1307,   -98,   -94,   -86,  1313, -1311,  4977,
   -1311,  6326, -1311,  1498, -1311,  1499, -1311,  1500, -1311,  1501,
   -1311, -1311,  5907,   508,  4791, -1311,  1317,  1318,  5535, -1311,
    6146, -1311, -1311, -1311,  1319,  2522, -1311, -1311,  8304,  1504,
     359,  7251,  7277,  7303,  7329, -1311, -1311, -1311, -1311,  9129,
   -1311,   359,  1503,  1509,  1390, -1311,  6326,  6326,  6326, -1311,
    1511,   652,  1328,  1518,  2698, -1311,  2723, -1311,    86, -1311,
   -1311,   375, -1311, -1311, -1311, -1311, -1311, -1311,  3683, -1311,
   -1311, -1311,  1091,  1506, -1311, -1311,  1521, -1311, -1311, -1311,
   -1311, -1311,  1091,  6326,  1522,  1523,    26, -1311,  1524,  8327,
      20, -1311,  1525,  1526,  1527,  1529,  4977,  6326,  7355,  7381,
     813, -1311,  6326,  1530, -1311, -1311,  3683, -1311,  7407,  5966,
    9129, -1311, -1311, -1311, -1311,  6326,  6326,   113,  1531,  1533,
    1535, -1311,  6326,  6326, -1311, -1311,  1546,  6326, -1311, -1311,
    1549,  1550,  1366,  1558,  1418,  6326, -1311,  1559,  1560,  1562,
    1563,  1564,  1565,   432,  1568,  6326, -1311,  5966,  5105,  9024,
    3929,   431,   431,   113,  1569,   113,  1570,   113,  1571,  6326,
     279,  1395,  9045, -1311, -1311, -1311, -1311,  5291,   136, -1311,
    1585,  3607,  1586,  4977,   113,  3607,  1587,   814,  6326, -1311,
    1590,   439, -1311,  6326,  6326,  6326,  6326, -1311, -1311, -1311,
    4977,  4134,   877,  9066, -1311, -1311,  4233,  4977, -1311, -1311,
   -1311,  4977, -1311,  1417,   359,  3987,  4419,  1598,  2788, -1311,
    1600,  1603, -1311,  1434, -1311, -1311, -1311, -1311, -1311,  1618,
     526,  9129,  6326,  6326,  4977,  1435,   822,  9129, -1311,  1621,
    6326,  9129, -1311,  5477,  5663,   556, -1311, -1311, -1311,  5867,
    5901, -1311,  6088,  1625, -1311,  4977, -1311,  1556,  1627,  9129,
   -1311, -1311, -1311, -1311, -1311, -1311,  1445, -1311, -1311,  4971,
    2833,  1628,  1449, -1311,  6326, -1311,  1450,  1455,   202, -1311,
    1457,   204, -1311,  1463,   238, -1311,  1464,  8350,  1638,  4977,
    1652,  1466,  6326, -1311,  5721,   252, -1311,   823,   290,   331,
   -1311,  1655,  6226, -1311,  7433,  7459,  7485,  7511,  1532,  6326,
   -1311,  6326, -1311, -1311,  6146,  2946,  1656,  1468,  1659, -1311,
   -1311,  3794, -1311, -1311,  3683,  9129, -1311, -1311, -1311,    20,
   -1311,  1536, -1311, -1311,  6326,  7537,  7563, -1311,  4977,  6326,
    1661, -1311,  7589, -1311, -1311,  1664,  1666,  1668,  1669,  1671,
    1672,   826,  1488, -1311,  4977,  6146, -1311, -1311,   431,  4168,
   -1311, -1311,  5907,   837,  5907,   837,  5907,   837,  1673, -1311,
     827,  4977, -1311,  6254,   113,  1674,  6146,   113, -1311, -1311,
    6326,  6326,  6326,  6326,  6326,  6569,  6597,   831, -1311, -1311,
    1675, -1311,   834,  2137,   835,  1677, -1311,  1497,  9129,  6326,
    6326,   844,  9129, -1311,  6326,   845,   867, -1311, -1311, -1311,
   -1311, -1311, -1311,  1502,  6326,   871,   872,  1505,  6326, -1311,
    6625,   340,   542,  6653,   357,   563,  6681,   380,   650, -1311,
    4977,  1679,  1592,  2512,  1512,   393, -1311,   875,   423,  7615,
    7641,  7667,  7693,  3011, -1311, -1311,  1697, -1311,  6326, -1311,
    1091, -1311, -1311,  6326,  9087,  7719,    49,  7745, -1311, -1311,
    6326,  6709,  1699,  1613, -1311,  6737,  1704,  6326,  1705,  1706,
    6326,  1707,  1708,  6326,  1709,  1534, -1311,  6326, -1311,   837,
   -1311,  6146,  1710,  5721,  6326,  6326,  6326,  6326, -1311, -1311,
    2743, -1311,   878, -1311,  6326, -1311,  4977,  6326,  7771, -1311,
   -1311,  4977,  1712, -1311, -1311,  1539,  6765, -1311, -1311,  1540,
    6793, -1311, -1311,  1544,  6821, -1311,  1713,  3076,   965,  2557,
     887, -1311,   440,   895,  7797,  7823,  7849,  7875,  1091,  1714,
    1545,  9108,   896,  6849,  6326, -1311, -1311,   837,  1715,   837,
    1719,   837,  1724, -1311, -1311, -1311, -1311,   837,  1740,  6146,
    1741,  6326,  6326,  6326,  6326, -1311, -1311,  3683, -1311,  1555,
    1745,  6877,  1107, -1311,  1572,  1156, -1311,  1573,  1341, -1311,
    1580,  1528, -1311,   899, -1311,  7901,  7927,  7953,  7979,   909,
   -1311,  1581,  4977, -1311,  1759,  1771,   837,  1772,   837,  1774,
     837, -1311,  1775,  6326,  6326,  6326,  6326,  3683,  1776,  3683,
     910, -1311, -1311,  1623, -1311,  1685, -1311,  1909, -1311,  6905,
    6933,  6961,  6989, -1311, -1311,   913, -1311,  1780,  1782,  1786,
    1787, -1311, -1311, -1311, -1311,  3683,  1789, -1311, -1311, -1311,
   -1311, -1311, -1311
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1311, -1311, -1311, -1311,   714, -1311, -1311, -1311, -1311,   217,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311,  -342,   -64,   846,    -9, -1311,  1369, -1311, -1311,
   -1311, -1311, -1311,   334, -1311,   337, -1311, -1311, -1311, -1311,
   -1311, -1311,   711,  1809,    -2,  -478,  -248, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311,  1810, -1311, -1311, -1311, -1311, -1311,
   -1311, -1311, -1311, -1311, -1311, -1311, -1311, -1311,  -941,  -907,
   -1311, -1311,  1352, -1311, -1311, -1311, -1311, -1311, -1311,  1486,
   -1311, -1311,    22, -1311, -1310,  2119,   579,  1885,   -73,  -235,
     588, -1311,    21,    10, -1311,  -357,    -3,    41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -477
static const yytype_int16 yytable[] =
{
     106,    93,   320,  1427,   476,   606,   495,   608,   736,   737,
     888,   336,   205,   182,   529,   616,   179,   264,   511,   251,
     210,  1254,   252,   903,   300,   253,   183,   178,   531,   205,
     876,   388,   666,   267,   210,   268,  1057,   667,   526,   313,
    1153,   533,   315,   335,   107,   201,   630,   181,   778,   780,
     782,   784,   202,     4,   186,  1625,  1142,   256,   644,   507,
    1144,   508,   294,  1023,  1146,   303,   564,     5,   566,  1148,
    1151,   247,   249,   184,   255,  1481,   310,  1245,   498,   484,
     485,   484,   485,   484,   485,   499,   968,   484,   485,   668,
     185,   484,   485,   643,   669,  1293,   969,  1294,   486,  1295,
     269,  1296,   188,   731,   970,   971,   972,  1297,   189,  1298,
     973,   974,   975,   976,   235,   424,   110,   236,   484,   485,
     311,   643,   484,   485,   257,   243,   244,   190,   258,   440,
     889,   890,   891,   892,   445,   245,  1133,   201,   449,   487,
     259,   197,   254,   198,   880,   455,   530,   484,   485,   191,
     136,   137,   138,   139,   140,   141,   265,   193,  1531,   145,
     532,   389,   390,   738,   147,   148,  1058,  1059,   149,   310,
     527,   393,  1143,   534,  1545,   327,  1145,   213,  1188,   154,
    1147,   310,   310,   321,   883,  1149,   260,  1150,   261,   310,
     322,   904,   484,   485,   337,   206,   338,   310,   339,   294,
     194,   893,   207,   174,   294,   425,   428,   266,   294,   434,
     211,   294,   206,   391,   301,   294,   294,   294,   294,   881,
     877,   294,   294,   294,   882,   427,   427,   528,   314,   729,
     730,   316,   294,   427,   815,   294,   214,   779,   781,   783,
     785,   435,   187,  1626,   509,   904,  1151,  1024,   304,   745,
     328,   329,   330,   331,   484,   485,   192,   294,   294,   294,
     272,   157,   158,   273,   479,   480,   629,   484,   485,   294,
     294,   497,   488,   165,   673,   239,   496,   674,   328,   329,
     330,   331,   294,   744,   294,   867,   870,   545,   240,   241,
     243,   244,   484,   485,   676,   332,   333,   674,   332,   333,
     245,   682,  1038,   683,   643,   869,   195,   246,  1129,   800,
     671,   484,   485,   484,   485,   672,  1662,   576,   294,   294,
     682,   807,   688,   855,   631,   401,   642,  1152,   672,  1422,
     215,   294,   328,   329,   330,   331,   196,   577,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   332,   333,   203,   682,   416,   692,  1189,   310,
     310,   310,   310,   310,   310,   294,   310,   310,  1222,   310,
     310,   682,   204,   698,   310,   310,   310,   310,   310,   484,
     485,   484,   485,   208,   607,   619,   609,   610,   611,   216,
     613,   614,   626,   209,   617,  1492,   294,  1494,   621,   622,
     623,   624,  1730,   427,   427,   427,   427,   427,   427,   212,
     427,   427,   862,   427,   427,   484,   485,   863,   427,   427,
     427,   427,   625,   328,   329,   330,   331,   332,   333,   484,
     485,  1496,   332,   333,   294,   392,  1396,  -474,  1397,  1169,
     760,   761,   762,   332,   333,  1504,   222,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   546,   414,
     415,   328,   329,   330,   331,   416,   786,   484,   485,  1029,
    1031,   682,   213,   788,  1418,   711,   714,   717,   720,   217,
     955,   332,   333,  1506,   393,   393,   218,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   809,   814,   810,   223,   416,   734,   735,   484,   485,
     294,   294,   294,   227,   480,   771,  1087,   484,   485,   821,
     237,   682,   310,   238,  1507,   328,   329,   330,   331,    48,
      49,    50,    51,  1597,   484,   485,   294,    56,   332,   333,
      59,   794,   323,   294,   324,   332,   333,   397,  -475,   398,
    1600,   325,  1552,   419,  1555,   420,  1558,   484,   485,   332,
     333,   242,   325,   868,   871,   548,   772,   549,   250,  -476,
     484,   485,   294,  1603,   325,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,  1611,   834,   835,   836,
     837,   838,   839,   840,   906,   262,   908,   844,   846,   847,
     484,   485,   968,  1118,  1119,  1120,  1121,   664,   856,   665,
     263,  1094,   969,  1095,   174,   864,  1613,   484,   485,   270,
     970,   971,   972,   332,   333,   879,   973,   974,   975,   976,
     271,   219,   228,  1679,   220,   229,   968,   221,   230,   872,
     231,   294,  1066,  1286,  1287,  1151,   969,   397,  1151,   398,
     274,  1151,   953,   399,   970,   971,   972,   968,  1335,  1336,
     973,   974,   975,   976,   294,  1088,   294,   969,  1648,   310,
     682,   682,   310,   885,   310,   970,   971,   972,   294,   294,
     275,   973,   974,   975,   976,   397,   337,   398,   567,   917,
     523,   575,   521,   911,   522,   174,   523,  1000,   915,   173,
     276,   174,   294,  1309,   224,   821,  1007,   225,  1008,   226,
    1009,   297,  1010,   427,  1463,  1223,   913,  1013,   427,  1464,
    1014,   294,   294,   397,   296,   398,  1692,   298,  1695,   770,
    1698,  1236,   535,   484,   485,   536,  1701,  1598,   537,   299,
     538,  1151,   306,   397,   968,   398,   305,  1030,  1032,   793,
     413,   414,   415,   958,   969,  1037,  1039,   416,  1601,   682,
     964,   993,   970,   971,   972,   307,   979,   294,   973,   974,
     975,   976,  1045,   308,   309,  1733,   294,  1735,   294,  1737,
     294,   232,   294,   312,   233,  1151,   234,   294,  1151,   365,
     294,  1151,   366,   682,  1151,   994,   367,   368,   456,   457,
     458,   369,   370,   461,   462,   463,   294,  1069,  1070,  1071,
    1072,   372,   294,  1406,  1407,   377,   378,   310,   411,   412,
     413,   414,   415,  1100,   376,  1101,  1151,   416,  1151,  1228,
    1151,   682,   397,   995,   398,  1082,  1083,   672,   418,   503,
     504,  1040,   294,   379,   682,  1604,  1011,   310,   294,   310,
     310,   516,   517,   397,   381,   398,  1341,   397,   845,   398,
     310,   427,   682,  1111,  1050,   382,   396,   199,   200,   417,
     397,  1046,   398,  1048,  1049,  1213,  1073,   294,   294,   294,
     294,   397,   422,   398,  1054,  1441,  1216,   682,   682,  1034,
    1126,   427,   443,   427,   427,   682,   682,  1170,  1175,   682,
     448,  1176,   310,   682,   427,  1177,   453,  1091,  1092,   454,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   294,
     294,   459,   294,   416,   294,   294,  1086,   460,   294,   294,
     474,   968,   682,   294,  1178,  1039,   682,   682,  1180,  1181,
    1093,   969,  1230,   682,  1231,  1232,   427,   464,   465,   970,
     971,   972,   326,   466,   467,   973,   974,   975,   976,   468,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   469,   470,  1134,  1135,  1136,
     682,   371,  1233,  1224,   373,  1354,   682,   471,  1234,   374,
     375,   682,   682,  1235,  1272,   380,  1364,   682,  1365,  1431,
    1547,   500,   294,   294,   294,  1469,  1364,  1470,  1505,  1364,
    1560,  1543,  1561,   294,   682,  1198,  1576,  1578,   672,  1579,
    1581,   510,  1203,  1204,  1205,  1206,  1207,  1364,  1213,  1586,
    1588,   477,  1214,  1217,   478,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   968,
    1216,   501,  1589,   416,  1364,   682,  1592,  1593,   682,   969,
    1612,  1469,  1442,  1659,   489,   490,   294,   970,   971,   972,
     682,   502,  1678,   973,   974,   975,   976,  1317,   682,  1364,
    1680,  1689,   682,   506,  1722,   294,   110,  1524,   491,   512,
    1251,   294,  1727,  1364,  1728,  1747,  1755,   294,  1756,   294,
     294,   513,   514,   515,   294,   294,   294,   294,   294,   294,
     294,   294,   518,   524,   519,   520,   525,   547,     7,     8,
     136,   137,   138,   139,   140,   141,   294,  1342,   551,   145,
     550,   555,   557,   558,   147,   148,   562,   174,   149,   325,
     563,   294,   565,   574,   579,   294,   580,   294,   583,   154,
    1675,  1322,   416,   632,   633,   173,   695,   678,   635,   699,
     679,   700,  1327,   701,  1308,   704,   705,   724,   726,   727,
     728,   751,   753,   773,   754,   756,   763,   636,    24,    25,
     637,    27,    28,   638,    30,   639,    32,   764,    33,   769,
     775,   968,   776,    38,    39,   310,    41,    42,    43,   798,
     777,   969,    46,   801,   808,   816,   817,   848,   849,   970,
     971,   972,  1344,   861,  1525,   973,   974,   975,   976,  1343,
     850,   851,  1347,   294,   852,   853,   860,   634,   865,   866,
     874,   157,   158,   310,   875,    67,    68,    69,   902,   427,
     968,   907,   910,   165,  1563,   912,   914,  1342,   918,  1372,
     969,   921,   922,   923,   925,   926,   927,  1369,   970,   971,
     972,   928,   930,   931,   973,   974,   975,   976,   932,  1375,
     936,   941,   943,   945,   946,   947,   948,   427,   988,   393,
     393,   954,  1001,  1015,   961,  1016,   962,  1401,  1002,  1004,
    1005,  1017,  1715,  1006,  1018,   568,  1026,  1064,   294,  1028,
     294,   759,   294,     7,     8,  1408,  1056,  1411,  1061,  1414,
    1062,  1068,  1074,  1065,  1077,  1078,  1081,   294,  1090,  1085,
    1079,  1098,  1104,  1425,   294,  1450,  1428,  1429,   294,     7,
       8,  1105,   294,  1109,  1110,  1112,  1446,  1113,  1116,  1141,
    1117,  1717,  1122,  1123,  1124,  1453,  1456,  1125,  1127,  1137,
    1139,   294,  1649,  1138,  1140,  1160,  1154,  1155,  1164,  1156,
    1157,  1517,   636,    24,    25,   637,    27,    28,   638,    30,
     639,    32,   294,    33,  1158,  1161,  1162,  1163,    38,    39,
    1166,    41,    42,    43,  1167,  1185,  1190,    46,   636,    24,
      25,   637,    27,    28,   638,    30,   639,    32,  1191,    33,
    1193,  1195,  1546,  1197,    38,    39,   294,    41,    42,    43,
    1199,   294,  1200,    46,  1201,  1202,  1208,  1209,  1212,  1210,
      67,    68,    69,  1567,  1225,   968,  1211,  1226,  1243,  1244,
    1220,   294,  1247,  1252,  1253,   969,  1270,  1237,   294,  1261,
    1264,   310,  1242,   970,   971,   972,    67,    68,    69,   973,
     974,   975,   976,  1255,  1256,   294,  1262,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   294,   294,     7,     8,   416,   393,  1257,  1265,  1263,
    1267,  1268,   176,  1269,  1275,   427,   805,  1276,   294,  1285,
    1291,  1292,  1299,   294,  1303,  1304,  1305,  1306,  1321,  1328,
    1345,  1313,  1314,  1318,  1551,  1329,  1554,  1334,  1557,     7,
       8,  1337,   806,  1330,  1338,  1346,  1565,  1350,  1349,  1568,
    1352,  1355,  1356,  1357,  1368,  1358,  1719,  1376,  1650,  1377,
    1653,  1378,   636,    24,    25,   637,    27,    28,   638,    30,
     639,    32,  1381,    33,  1383,  1387,  1384,   294,    38,    39,
    1385,    41,    42,    43,  1386,  1390,  1391,    46,  1392,  1393,
    1394,  1395,   318,   319,  1398,  1409,  1412,  1415,   636,    24,
      25,   637,    27,    28,   638,    30,   639,    32,  1419,    33,
    1621,  1423,  1426,  1430,    38,    39,  1433,    41,    42,    43,
      67,    68,    69,    46,  1457,  1449,  1703,  1459,   294,  1460,
     294,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   968,   294,  1462,  1461,   416,  1471,   294,  1468,
    1480,  1482,   969,  1483,  1487,  1652,    67,    68,    69,  1484,
     970,   971,   972,  1488,  1499,  1490,   973,   974,   975,   976,
    1491,  1493,   383,   384,   385,   386,   387,  1495,  1497,  1501,
    1502,  1508,  1519,  1520,  1514,  1521,   956,  1533,  1685,   423,
    1537,  1526,  1538,   429,  1539,  1540,   294,  1541,  1542,  1559,
    1566,  1577,  1544,  1582,   310,  1606,  1607,   436,   438,   441,
     442,  1583,   444,   438,   446,   447,  1590,   438,   450,   451,
    1594,   663,   957,  1619,   438,  1630,  1610,  1631,  1710,   294,
    1634,  1637,  1638,  1641,  1642,  1645,  1651,   968,  1666,  1673,
    1686,  1693,   473,  1721,   310,  1696,   310,   969,   427,  1646,
    1699,   482,   483,  1667,  1669,   970,   971,   972,  1671,  1687,
     483,   973,   974,   975,   976,   859,  1702,  1704,  1743,  1712,
    1746,  1713,   310,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,  1731,  1716,  1718,   427,   416,
     427,   540,   542,   438,  1720,  1729,  1761,  1732,  1734,   968,
    1736,  1738,  1744,   552,   553,   554,  1757,   556,  1758,   969,
     559,   560,  1759,  1760,   561,  1762,   427,   970,   971,   972,
    1622,  1246,   677,   973,   974,   975,   976,  1535,  1259,   572,
     573,  1536,    92,   101,  1351,   707,     0,     0,  1748,     0,
       0,     0,     0,   581,   582,     0,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   615,     0,     0,
     618,     0,   620,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,  1063,     0,     0,
    1749,   416,   641,     0,     0,   438,     0,     0,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,     0,     0,   661,   662,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,   540,     0,   416,     0,     0,     0,   686,
       0,     0,     0,     0,   691,     0,     0,     0,     0,   696,
     697,     0,     0,     0,     0,   702,   703,     0,     0,     0,
     708,   710,   713,   716,   719,   721,   722,   723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,   739,   740,   741,   383,   384,
     742,     0,     0,     0,   746,   747,   748,   749,   750,     0,
       0,     0,   755,     0,     0,   757,   758,     0,     0,   438,
     438,   438,     0,   968,   765,   766,   767,   581,   768,     0,
       7,     8,     0,   969,   774,     0,     0,     0,     0,     0,
       0,   970,   971,   972,     0,   438,     0,   973,   974,   975,
     976,   789,   791,  1159,   661,   662,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   768,     0,     0,     0,   416,     0,     0,
     813,   438,     0,     0,     0,     0,   818,     0,     0,   636,
      24,    25,   637,    27,    28,   638,    30,   639,    32,     0,
      33,     0,     0,     0,     0,    38,    39,   439,    41,    42,
      43,     0,   439,     0,    46,     0,   439,     0,     0,     0,
       0,     0,     0,   439,  1750,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,  1580,   545,     0,     0,   416,     0,
     901,     0,     0,   438,     0,   438,   909,     0,     0,     0,
       0,     0,     0,     0,   916,     0,     0,   791,   919,     0,
     541,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,   933,     7,     8,     0,     0,     0,     0,     0,     0,
     939,     0,     0,   980,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,   438,     0,   416,     0,     0,     0,     0,   959,   960,
       0,  1221,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   987,     0,     0,
     989,   636,    24,    25,   637,    27,    28,   638,    30,   639,
      32,     0,    33,     0,     0,     0,   438,    38,    39,     0,
      41,    42,    43,     0,     0,   438,    46,   438,     0,   438,
       0,   438,     0,     0,     0,     0,   438,     0,     0,   438,
       0,     0,     0,     0,   439,  1019,     0,  1021,  1022,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   681,   414,   415,  1041,
       0,     0,   541,   416,     0,     0,     0,  1042,  1043,  1044,
       0,   438,     0,   452,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1053,     0,     0,     0,
       7,     8,     0,  1055,   472,     0,  1060,   475,     0,     0,
       0,     0,     0,     0,     0,  1020,   438,   438,   438,   438,
       0,     0,     0,  1075,     0,  1227,     0,     0,     0,     0,
       0,   505,     0,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,   439,   439,
     439,   416,     0,     0,     0,     0,     0,     0,     0,   636,
      24,    25,   637,    27,    28,   638,    30,   639,    32,     0,
      33,     0,   438,     0,   439,    38,    39,     0,    41,    42,
      43,   792,     0,     0,    46,     0,     0,     0,     0,     0,
     570,   571,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   578,     0,     0,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1165,     0,     0,  1168,     0,     0,   612,  1171,     0,
    1172,  1173,  1174,     0,     0,     0,     0,     0,  1179,     0,
       0,     0,   636,    24,    25,   637,    27,    28,   638,    30,
     639,    32,     0,    33,     0,  1194,     0,  1196,    38,    39,
       0,    41,    42,    43,     7,     8,     0,    46,  1319,     0,
       0,     0,     0,  1025,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,  1229,   439,     0,   439,   416,     0,     0,     0,     0,
      67,    68,    69,  1238,  1239,     0,   792,   920,     0,     7,
       8,     0,     0,     0,     0,  1248,  1250,     0,     0,     0,
       0,     0,     0,   636,    24,    25,   637,    27,    28,   638,
      30,   639,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
     439,     0,     0,     0,     0,  1288,  1289,  1290,     0,     0,
       0,     0,     0,     0,     0,  1300,  1128,  1302,   636,    24,
      25,   637,    27,    28,   638,    30,   639,    32,  1307,    33,
       0,    67,    68,    69,    38,    39,   438,    41,    42,    43,
       0,     0,     0,    46,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,   439,     0,   439,     0,   439,     0,
     439,     0,  1331,  1332,  1333,   439,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,  1339,     0,     0,  1608,   416,  1348,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1361,     0,     0,     0,     0,  1367,  1340,
     439,     0,     0,     0,     0,  1371,     0,     0,     0,     0,
       0,  1373,  1374,     0,     0,     0,     0,     0,  1379,  1380,
    1658,     0,  1676,  1382,     0,     0,     0,     0,     0,     0,
       0,  1389,     0,   886,     0,   439,   439,   439,   439,     0,
       0,  1399,     0,  1400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1417,     0,     0,     0,     0,
       0,     0,     0,     0,  1458,     0,     0,   438,     0,     0,
       0,   438,     0,     0,  1432,     0,     0,     0,     0,  1434,
    1435,  1436,  1437,     0,     0,     0,     0,     0,     0,     0,
       0,   439,  1445,     0,   940,     0,     0,     0,     0,     0,
       0,     0,  1455,     0,     0,     0,     0,     0,     0,  1486,
       0,     0,     0,   952,     0,     0,     0,     0,  1465,  1466,
       0,     0,     0,     0,     0,     0,  1472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
    1489,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,  1503,   416,
     540,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,  1515,     0,  1516,  1027,   416,
     438,     0,     0,     0,  1035,     0,     0,  1523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1528,     0,  1518,     0,     0,  1532,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
    1047,   438,     0,     0,   416,     0,     0,     0,  1550,     0,
    1553,     0,  1556,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,  1569,  1570,  1571,  1572,
    1573,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,  1584,  1585,  1618,     0,   416,
    1587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1591,     0,     0,     0,  1595,     0,     0,     0,     0,     0,
       0,  1096,  1097,     0,  1099,   439,  1102,  1103,     0,     0,
    1106,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1620,     0,     0,     0,     0,  1367,
       0,     0,     0,     0,     0,     0,  1628,     0,     0,     0,
       0,     0,  1674,  1636,     0,     0,  1640,     0,     0,  1644,
       0,     0,     0,  1647,     0,     0,     0,   438,     0,   438,
    1654,  1655,  1656,  1657,     0,     0,     0,     0,     0,     0,
    1661,     0,     0,  1663,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   545,     0,
       0,     0,   416,     0,  1182,  1183,  1184,     0,     0,     0,
       0,     0,     0,     0,     0,  1192,     0,     0,     0,     0,
    1691,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,     0,  1705,  1706,  1707,
    1708,     0,     0,     0,     0,     0,     0,     0,   802,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,   439,   416,  1241,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1739,
    1740,  1741,  1742,     0,   887,     0,     0,  1260,     0,     0,
       0,     0,     0,  1266,     0,     0,     0,     0,     0,  1271,
       0,  1273,  1274,     0,     0,     0,  1277,  1278,  1279,  1280,
    1281,  1282,  1283,  1284,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,  1301,     0,
       0,     0,   416,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1312,     0,     0,     0,  1316,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   546,
     414,   415,     0,     0,     0,     0,   416,  1012,     0,   541,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   681,   414,   415,     0,     0,     0,   439,
     416,     0,     0,     0,     0,     0,   439,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,  1187,     0,     0,  1359,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     439,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,   439,   416,     0,     0,     0,     0,   108,   109,   110,
       0,     0,     0,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,  1241,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,     0,   147,   148,  1438,
       0,   149,     0,   150,   151,   152,  1447,     0,     0,     0,
    1448,   153,   154,     0,  1452,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,  1467,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   439,     0,   439,     0,
       0,     0,     0,     0,  1241,     0,     0,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,   155,  1500,     0,
       0,     0,     0,   156,   157,   158,   159,     0,     0,     0,
       0,   160,   161,   162,   163,   164,   165,     0,     0,     0,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,   166,   167,     0,     0,     0,   168,     0,     0,     0,
       0,   169,     0,   170,     0,   171,   172,  1241,   173,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1241,     0,     0,     0,     0,     0,     0,
     108,   277,     0,     0,     0,     0,   111,   112,   113,     0,
    1562,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   279,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,     0,     0,     0,   280,  1605,
       0,   281,     0,     0,   282,     0,   283,   424,   110,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,   284,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,     0,     0,
       0,   145,     0,     0,     0,     0,   147,   148,     0,     0,
     149,     0,     0,     0,     0,  1241,     0,     0,     0,     0,
    1665,   154,     0,     0,     0,     0,   156,     0,     0,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,   492,  1424,     0,   416,     0,   168,
       0,     0,     0,     0,   494,     0,     0,   108,   277,   172,
       0,   246,   543,   111,   112,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     279,  1241,     0,   157,   158,     0,     0,     0,     0,   142,
     143,   144,     0,   146,     0,   165,     7,     8,     0,     0,
       0,     0,     0,   150,   151,   152,     0,     0,     0,     0,
       0,   153,     0,     0,     0,   280,     0,     0,   281,     0,
       0,   282,     0,   283,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
      56,     0,     0,    59,     0,   636,    24,    25,   637,    27,
      28,   638,    30,   639,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,   159,     0,     0,     0,
       0,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,   166,   437,     0,     0,     0,   168,     0,     0,     0,
       0,   286,     0,     0,     0,     0,   172,     0,     0,   543,
     108,   277,   110,     0,     0,     0,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   279,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     147,   148,     0,     0,   149,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,   154,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1404,     0,  1405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   165,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   166,   285,     0,     0,   416,   168,
     787,     0,     0,     0,   286,   732,   108,   317,   110,   172,
       0,  1451,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   147,   148,     0,     0,
     149,     0,   150,   151,   152,     0,   108,   317,   110,     0,
     153,   154,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   147,   148,     0,     0,
     149,     0,   150,   151,   152,     0,     0,     0,     0,     0,
     153,   154,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,   156,   157,   158,   159,     0,  1439,     0,  1440,
     160,   161,   162,   163,   164,   165,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     166,   167,     0,     0,   416,   168,     0,     0,     0,     0,
     286,  1548,     0,  1549,     0,   172,     0,  1249,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   156,   157,   158,   159,   416,     0,   627,     0,
     160,   161,   162,   163,   164,   165,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     166,   167,     0,     0,   416,   168,     0,     0,     0,     0,
     286,   670,   108,   317,   110,   172,     0,  1444,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,   147,   148,     0,     0,   149,     0,   150,   151,
     152,     0,     0,     0,     0,     0,   153,   154,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,   884,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
       0,     0,     0,   935,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,   156,   157,
     158,   159,   983,     0,     0,     0,   160,   161,   162,   163,
     164,   165,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   166,   167,     0,     0,
     416,   168,     0,     0,     0,     0,   286,   732,   108,   277,
     278,   172,     0,  1454,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   279,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,     0,     0,     0,
       0,     0,   153,     0,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,    56,     0,     0,    59,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,  1003,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,   159,     0,     0,
       0,     0,   160,   161,   162,   163,   164,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,   166,   285,     0,   416,     0,   168,     0,     0,
       0,     0,   286,   569,   108,   277,  1310,   172,     0,   287,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   279,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,     0,     0,     0,     0,     0,   153,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,  1033,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,   159,     0,     0,     0,     0,   160,   161,
     162,   163,   164,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,   166,   285,
       0,   416,     0,   168,     0,     0,     0,     0,   286,   725,
     108,   277,     0,   172,     0,  1311,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   279,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,     0,
       0,     0,     0,     0,   153,     0,     0,     0,   280,     0,
       0,   281,     0,     0,   282,     0,   283,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,    56,     0,     0,    59,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,  1132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,     0,   159,
       0,     0,     0,     0,   160,   161,   162,   163,   164,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,   166,   285,     0,   416,     0,   168,
       0,     0,     0,     0,   286,  1485,   108,   277,     0,   172,
       0,   287,   111,   112,   113,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   279,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   152,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   280,     0,     0,   281,     0,     0,
     282,     0,   283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,    56,
       0,     0,    59,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
    1402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,   159,     0,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     166,   437,     0,     0,   416,   168,     0,     0,     0,     0,
     286,   733,   108,   277,     0,   172,     0,   539,   111,   112,
     113,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   279,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
     152,     0,     0,     0,     0,     0,   153,     0,     0,     0,
     280,     0,     0,   281,     0,     0,   282,     0,   283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,    56,     0,     0,    59,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,  1421,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,   159,     0,     0,     0,     0,   160,   161,   162,   163,
     164,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   166,   437,     0,     0,
     416,   168,     0,     0,     0,     0,   286,   799,   108,   277,
       0,   172,     0,   790,   111,   112,   113,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   279,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,     0,   146,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   152,     0,     0,     0,
       0,     0,   153,     0,     0,     0,   280,     0,     0,   281,
       0,     0,   282,     0,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,    56,     0,     0,    59,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,  1475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,   159,     0,     0,
       0,     0,   160,   161,   162,   163,   164,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   166,   285,     0,     0,   416,   168,     0,     0,
       0,     0,   286,   833,   108,   277,     0,   172,     0,  1315,
     111,   112,   113,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   279,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   151,   152,     0,     0,     0,     0,     0,   153,     0,
       0,     0,   280,     0,     0,   281,     0,     0,   282,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,    56,     0,     0,
      59,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,   159,     0,     0,     0,     0,   160,   161,
     162,   163,   164,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   492,  1424,
       0,     0,   416,   168,     0,     0,     0,     0,   494,   841,
     108,   317,     0,   172,     0,   246,   111,   112,   113,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,     0,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   108,
     317,   110,     0,     0,   153,   111,   112,   113,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   147,
     148,     0,     0,   149,     0,   150,   151,   152,     0,     0,
       0,     0,     0,   153,   154,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,   156,     0,     0,   159,
       0,     0,  1477,     0,   160,   161,   162,   163,   164,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,   492,   493,     0,   416,     0,   168,
       0,     0,     0,     0,   494,     0,  1478,     0,     0,   172,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,   158,   159,     0,
       0,     0,     0,   160,   161,   162,   163,   164,   165,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   166,   167,     0,     0,   416,   168,   108,
     277,     0,     0,   286,   842,   111,   112,   113,   172,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   279,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,     0,     0,
       0,     0,     0,   153,     0,     0,     0,   280,     0,     0,
     281,     0,     0,   282,     0,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,    56,     0,     0,    59,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
       0,     0,     0,  1479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,   159,     0,
       0,     0,     0,   160,   161,   162,   163,   164,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   166,   437,     0,     0,   416,   168,   108,
     317,     0,     0,   286,   843,   111,   112,   113,   172,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,   152,     0,     0,
       0,     0,     0,   153,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,     0,     0,     0,     0,     0,     0,
       0,  1509,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,  1564,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,     0,   156,     0,     0,   159,     0,
       0,     0,     0,   160,   161,   162,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,   166,   167,     0,     0,     0,   168,    -4,
      -4,    -4,     0,   286,    -4,    -4,     0,    -4,   172,     0,
       0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     6,     0,     0,
       0,     0,    -4,     0,     0,     7,     8,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       9,    10,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,    11,    12,    13,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,    66,    67,    68,    69,     0,     0,    70,     0,    71,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,    87,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,  1574,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,  1575,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
    1596,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,  1599,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,  1602,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,  1629,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,  1633,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
    1668,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,  1670,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,  1672,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,  1690,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,  1714,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
    1751,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,     0,     0,  1752,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,  1753,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,     0,     0,  1754,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
     854,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,   965,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,   966,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,   967,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,   998,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1089,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1130,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1131,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1186,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1323,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1324,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1325,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1326,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1362,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1363,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1370,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1510,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1511,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1512,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1513,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1529,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1530,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1534,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1614,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1615,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1616,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1617,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1624,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1627,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1664,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1681,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1682,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1683,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,  1684,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,  1723,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,     0,     0,     0,
    1724,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,     0,     0,     0,  1725,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,     0,
       0,     0,  1726,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,   397,     0,   398,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,     0,     0,   628,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,   804,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,     0,     0,   812,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,   820,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,     0,     0,
     900,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,     0,     0,   991,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,     0,     0,   992,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,     0,     0,   996,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,     0,     0,     0,     0,   416,     0,
       0,     0,   997,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,     0,     0,   999,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,     0,     0,  1036,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,     0,
       0,  1084,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,     0,     0,  1320,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,     0,     0,  1353,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,     0,     0,
    1498,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,   680,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,   684,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,   685,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,   687,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,   689,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,   690,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,   693,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,   694,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,   787,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,     0,     0,     0,     0,   416,     0,
     795,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,   796,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,   797,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,   803,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,   811,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,   819,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,   899,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,   924,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,   929,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,   934,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,     0,     0,     0,     0,   416,     0,
     937,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,   938,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,   944,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,   949,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,   950,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,   951,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,   982,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416,     0,   984,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,     0,   985,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,     0,   986,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,     0,     0,     0,     0,   416,     0,
     990,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,     0,     0,     0,     0,   416,
       0,  1219,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,     0,  1403,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,     0,  1420,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,     0,     0,
       0,     0,   416,     0,  1443,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,     0,
       0,     0,     0,   416,     0,  1623,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
       0,     0,     0,     0,   416,     0,  1688,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,     0,     0,     0,     0,   416
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1311)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,     6,  1313,   239,   362,   254,   364,   486,   487,
       4,     4,     4,    13,     5,   372,     6,     4,   266,    71,
       4,     6,    74,     6,     4,    77,    77,     6,     5,     4,
       4,     4,   188,     4,     4,     6,     4,   193,     5,     5,
     981,     5,     5,   107,     3,   187,   388,     6,     5,     5,
       5,     5,   194,     6,     6,     6,     6,     4,   400,     4,
       6,     6,    65,     7,     6,     4,   314,     0,   316,     6,
     977,    49,    50,   187,    52,  1385,    79,     6,   187,   177,
     178,   177,   178,   177,   178,   194,    94,   177,   178,   188,
     187,   177,   178,     7,   193,   193,   104,   195,   194,   193,
      71,   195,     6,   193,   112,   113,   114,   193,     6,   195,
     118,   119,   120,   121,    74,     4,     5,    77,   177,   178,
      79,     7,   177,   178,    71,   177,   178,     6,    75,   202,
     124,   125,   126,   127,   207,   187,   195,   187,   211,   194,
      87,   187,   194,   189,   194,   218,   137,   177,   178,     6,
      39,    40,    41,    42,    43,    44,   143,     6,  1468,    48,
     137,   134,   135,   193,    53,    54,   134,   135,    57,   172,
     137,   173,   122,   137,  1484,     7,   122,   187,     8,    68,
     122,   184,   185,   187,   194,   122,    77,   195,    79,   192,
     194,   174,   177,   178,   187,   187,   189,   200,   191,   202,
       6,   195,   194,   196,   207,   184,   185,   194,   211,   199,
     194,   214,   187,   172,   194,   218,   219,   220,   221,   194,
     194,   224,   225,   226,   194,   184,   185,   194,   194,   477,
     478,   194,   235,   192,   576,   238,    81,   194,   194,   194,
     194,   200,   194,   194,   189,   174,  1153,   191,   187,   497,
     164,   165,   166,   167,   177,   178,   187,   260,   261,   262,
      74,   150,   151,    77,   242,   243,     7,   177,   178,   272,
     273,   194,   250,   162,   190,   134,   254,   193,   164,   165,
     166,   167,   285,   193,   287,   627,   628,     8,   147,   148,
     177,   178,   177,   178,   190,   184,   185,   193,   184,   185,
     187,   193,   191,   195,     7,   191,   189,   194,   193,   557,
     188,   177,   178,   177,   178,   193,  1626,   326,   321,   322,
     193,   569,   195,   188,   388,     6,   399,   193,   193,   193,
      77,   334,   164,   165,   166,   167,   189,   327,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   184,   185,   187,   193,   186,   195,   188,   362,
     363,   364,   365,   366,   367,   368,   369,   370,     7,   372,
     373,   193,   187,   195,   377,   378,   379,   380,   381,   177,
     178,   177,   178,   187,   363,   375,   365,   366,   367,    77,
     369,   370,   382,   187,   373,   193,   399,   193,   377,   378,
     379,   380,  1712,   362,   363,   364,   365,   366,   367,   187,
     369,   370,   188,   372,   373,   177,   178,   193,   377,   378,
     379,   380,   381,   164,   165,   166,   167,   184,   185,   177,
     178,   193,   184,   185,   437,     4,     4,   194,     6,   191,
     513,   514,   515,   184,   185,   193,    77,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   164,   165,   166,   167,   186,   539,   177,   178,   811,
     812,   193,   187,   195,   195,   465,   466,   467,   468,     6,
     728,   184,   185,   193,   486,   487,   194,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   193,   575,   195,    77,   186,   484,   485,   177,   178,
     513,   514,   515,    79,   492,   524,   188,   177,   178,   583,
     187,   193,   525,    74,   193,   164,   165,   166,   167,    98,
      99,   100,   101,   193,   177,   178,   539,   106,   184,   185,
     109,   550,   187,   546,   189,   184,   185,   188,   194,   190,
     193,   196,  1493,   187,  1495,   189,  1497,   177,   178,   184,
     185,   194,   196,   627,   628,   187,   525,   189,   194,   194,
     177,   178,   575,   193,   196,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   193,   596,   597,   598,
     599,   600,   601,   602,   667,    77,   669,   606,   607,   608,
     177,   178,    94,   945,   946,   947,   948,   189,   617,   191,
      74,    77,   104,    79,   196,   624,   193,   177,   178,    74,
     112,   113,   114,   184,   185,   634,   118,   119,   120,   121,
      77,    71,    71,   193,    74,    74,    94,    77,    77,   629,
      79,   644,   877,     6,     7,  1552,   104,   188,  1555,   190,
       4,  1558,   725,   194,   112,   113,   114,    94,     6,     7,
     118,   119,   120,   121,   667,   188,   669,   104,  1609,   672,
     193,   193,   675,   195,   677,   112,   113,   114,   681,   682,
       4,   118,   119,   120,   121,   188,   187,   190,   189,   679,
     191,   194,   187,   672,   189,   196,   191,   770,   677,   194,
       4,   196,   705,   195,    74,   769,   779,    77,   781,    79,
     783,   187,   785,   672,   188,  1057,   675,   790,   677,   193,
     793,   724,   725,   188,     4,   190,  1667,   187,  1669,   194,
    1671,  1073,    71,   177,   178,    74,  1677,   195,    77,   187,
      79,  1648,     6,   188,    94,   190,   187,   811,   812,   194,
     179,   180,   181,   731,   104,   819,   820,   186,   195,   193,
     738,   195,   112,   113,   114,     6,   744,   770,   118,   119,
     120,   121,   845,   189,     4,  1716,   779,  1718,   781,  1720,
     783,    74,   785,     4,    77,  1692,    79,   790,  1695,   187,
     793,  1698,   187,   193,  1701,   195,   187,   187,   219,   220,
     221,   187,   187,   224,   225,   226,   809,   880,   881,   882,
     883,   187,   815,  1291,  1292,   187,   187,   820,   177,   178,
     179,   180,   181,    77,     7,    79,  1733,   186,  1735,  1064,
    1737,   193,   188,   195,   190,   899,   900,   193,     6,   260,
     261,   820,   845,   187,   193,   195,   195,   850,   851,   852,
     853,   272,   273,   188,   187,   190,  1198,   188,   193,   190,
     863,   820,   193,   936,   854,   187,   194,    21,    22,   194,
     188,   850,   190,   852,   853,   193,   885,   880,   881,   882,
     883,   188,     6,   190,   863,     8,   193,   193,   193,   195,
     195,   850,   187,   852,   853,   193,   193,   195,   195,   193,
     187,   195,   905,   193,   863,   195,   187,   916,   917,   194,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   922,
     923,   187,   925,   186,   927,   928,   905,   187,   931,   932,
       4,    94,   193,   936,   195,   999,   193,   193,   195,   195,
     918,   104,   193,   193,   195,   195,   905,   187,   187,   112,
     113,   114,   106,   187,   187,   118,   119,   120,   121,   187,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   187,   187,   965,   966,   967,
     193,   145,   195,  1057,   148,  1230,   193,   187,   195,   153,
     154,   193,   193,   195,   195,   159,   193,   193,   195,   195,
    1488,   187,  1015,  1016,  1017,   193,   193,   195,   195,   193,
     193,   195,   195,  1026,   193,  1034,   195,   193,   193,   195,
     195,   189,  1041,  1042,  1043,  1044,  1045,   193,   193,   195,
     195,   194,  1051,  1052,   194,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    94,
     193,   187,   195,   186,   193,   193,   195,   195,   193,   104,
     195,   193,   195,   195,   194,   194,  1079,   112,   113,   114,
     193,   187,   195,   118,   119,   120,   121,  1160,   193,   193,
     195,   195,   193,   187,   195,  1098,     5,  1454,   194,     6,
    1090,  1104,   193,   193,   195,   195,   193,  1110,   195,  1112,
    1113,   194,   194,   194,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,   189,   277,   189,   189,   189,     6,    12,    13,
      39,    40,    41,    42,    43,    44,  1139,  1201,     6,    48,
     294,   191,   194,   137,    53,    54,     6,   196,    57,   196,
       6,  1154,     6,   194,     6,  1158,   189,  1160,     4,    68,
     195,  1170,   186,   191,     7,   194,     7,   193,   195,     6,
     193,     6,  1181,     6,  1152,     7,     7,     7,   188,     6,
     194,     7,     6,    50,     7,     6,     6,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     6,    82,     4,
      50,    94,    50,    87,    88,  1208,    90,    91,    92,   134,
      50,   104,    96,   194,   188,     6,     6,   188,   188,   112,
     113,   114,  1212,   188,  1459,   118,   119,   120,   121,  1208,
     193,   193,  1222,  1236,   193,   193,   193,   391,   188,   188,
       6,   150,   151,  1246,     4,   129,   130,   131,     4,  1208,
      94,     6,     6,   162,  1502,     6,     6,  1321,     7,  1249,
     104,   137,     7,     7,     7,   137,     7,  1246,   112,   113,
     114,     7,   137,     7,   118,   119,   120,   121,     7,  1257,
     194,     4,     6,   188,   188,   188,   188,  1246,     6,  1291,
    1292,   191,   190,     7,   195,     7,   195,  1287,   194,   194,
     194,     7,   195,   194,   191,     6,   194,     7,  1311,     6,
    1313,   195,  1315,    12,    13,  1293,     6,  1295,     6,  1297,
       6,     6,     6,   189,   187,   187,     6,  1330,     7,   174,
     194,     7,     7,  1311,  1337,  1344,  1314,  1315,  1341,    12,
      13,    79,  1345,     7,     7,     7,  1336,     7,     6,   187,
       7,   195,     7,     7,     7,  1345,  1346,     6,     4,     4,
     194,  1364,  1610,     6,     6,   194,     7,     6,    77,     7,
       7,  1444,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,  1385,    82,     7,     6,     6,     6,    87,    88,
       6,    90,    91,    92,     6,     4,     4,    96,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     4,    82,
     195,     6,  1485,     6,    87,    88,  1419,    90,    91,    92,
       6,  1424,     6,    96,     4,     6,   193,   188,   193,   188,
     129,   130,   131,  1506,   191,    94,   188,     7,   191,     6,
     188,  1444,     6,     6,     6,   104,     5,   187,  1451,     6,
       6,  1454,   194,   112,   113,   114,   129,   130,   131,   118,
     119,   120,   121,   194,   194,  1468,   194,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,  1484,  1485,    12,    13,   186,  1488,    87,     6,   194,
     194,     6,     6,     6,     4,  1454,   195,     6,  1501,     7,
     194,   194,   189,  1506,     6,     6,     6,     6,     4,     6,
       4,   194,   194,   194,  1492,     6,  1494,     6,  1496,    12,
      13,   193,   195,   133,     6,     4,  1504,     4,     6,  1507,
       6,     6,     6,     6,     4,     6,   195,     6,  1611,     6,
    1613,     6,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     6,    82,     5,   137,     6,  1560,    87,    88,
     194,    90,    91,    92,     6,     6,     6,    96,     6,     6,
       6,     6,    86,    87,     6,     6,     6,     6,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   193,    82,
    1580,     6,     6,     6,    87,    88,     6,    90,    91,    92,
     129,   130,   131,    96,     6,   188,  1679,     7,  1611,     6,
    1613,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    94,  1626,     6,   191,   186,     6,  1631,   194,
       5,    75,   104,     6,     6,  1613,   129,   130,   131,   194,
     112,   113,   114,   194,     6,   195,   118,   119,   120,   121,
     195,   194,   166,   167,   168,   169,   170,   194,   194,     7,
     194,     6,     6,   195,   132,     6,   195,     6,  1658,   183,
       6,   135,     6,   187,     6,     6,  1679,     6,     6,     6,
       6,     6,   194,     6,  1687,     6,    94,   201,   202,   203,
     204,   194,   206,   207,   208,   209,   194,   211,   212,   213,
     195,     6,   195,     6,   218,     6,   194,    94,  1687,  1712,
       6,     6,     6,     6,     6,     6,     6,    94,     6,     6,
       6,     6,   236,   195,  1727,     6,  1729,   104,  1687,   195,
       6,   245,   246,   194,   194,   112,   113,   114,   194,   194,
     254,   118,   119,   120,   121,     6,     6,     6,  1727,   194,
    1729,     6,  1755,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     6,   194,   194,  1727,   186,
    1729,   285,   286,   287,   194,   194,  1755,     6,     6,    94,
       6,     6,     6,   297,   298,   299,     6,   301,     6,   104,
     304,   305,     6,     6,   308,     6,  1755,   112,   113,   114,
    1583,  1087,   433,   118,   119,   120,   121,  1473,  1097,   323,
     324,  1474,     3,     3,  1226,   463,    -1,    -1,   195,    -1,
      -1,    -1,    -1,   337,   338,    -1,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,
     374,    -1,   376,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,     6,    -1,    -1,
     195,   186,   396,    -1,    -1,   399,    -1,    -1,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,    -1,    -1,   419,   420,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,   437,    -1,   186,    -1,    -1,    -1,   443,
      -1,    -1,    -1,    -1,   448,    -1,    -1,    -1,    -1,   453,
     454,    -1,    -1,    -1,    -1,   459,   460,    -1,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   489,   490,   491,   492,   493,
     494,    -1,    -1,    -1,   498,   499,   500,   501,   502,    -1,
      -1,    -1,   506,    -1,    -1,   509,   510,    -1,    -1,   513,
     514,   515,    -1,    94,   518,   519,   520,   521,   522,    -1,
      12,    13,    -1,   104,   528,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,    -1,   539,    -1,   118,   119,   120,
     121,   545,   546,     6,   548,   549,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   567,    -1,    -1,    -1,   186,    -1,    -1,
     574,   575,    -1,    -1,    -1,    -1,   580,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    -1,    -1,    -1,    -1,    87,    88,   202,    90,    91,
      92,    -1,   207,    -1,    96,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,   218,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     7,     8,    -1,    -1,   186,    -1,
     664,    -1,    -1,   667,    -1,   669,   670,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   678,    -1,    -1,   681,   682,    -1,
     285,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
     704,    -1,    -1,   195,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,   725,    -1,   186,    -1,    -1,    -1,    -1,   732,   733,
      -1,     6,    -1,    -1,   738,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   751,    -1,    -1,
     754,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,   770,    87,    88,    -1,
      90,    91,    92,    -1,    -1,   779,    96,   781,    -1,   783,
      -1,   785,    -1,    -1,    -1,    -1,   790,    -1,    -1,   793,
      -1,    -1,    -1,    -1,   399,   799,    -1,   801,   802,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   833,
      -1,    -1,   437,   186,    -1,    -1,    -1,   841,   842,   843,
      -1,   845,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   860,    -1,    -1,    -1,
      12,    13,    -1,   867,   235,    -1,   870,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   880,   881,   882,   883,
      -1,    -1,    -1,   887,    -1,     6,    -1,    -1,    -1,    -1,
      -1,   262,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,   513,   514,
     515,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      82,    -1,   936,    -1,   539,    87,    88,    -1,    90,    91,
      92,   546,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
     321,   322,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,
     575,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   995,    -1,    -1,   998,    -1,    -1,   368,  1002,    -1,
    1004,  1005,  1006,    -1,    -1,    -1,    -1,    -1,  1012,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    82,    -1,  1029,    -1,  1031,    87,    88,
      -1,    90,    91,    92,    12,    13,    -1,    96,     6,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,  1065,   667,    -1,   669,   186,    -1,    -1,    -1,    -1,
     129,   130,   131,  1077,  1078,    -1,   681,   682,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1089,  1090,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    82,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    91,    92,    -1,    -1,    -1,    96,    -1,
     725,    -1,    -1,    -1,    -1,  1129,  1130,  1131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1139,   195,  1141,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,  1152,    82,
      -1,   129,   130,   131,    87,    88,  1160,    90,    91,    92,
      -1,    -1,    -1,    96,    -1,   770,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   779,    -1,   781,    -1,   783,    -1,
     785,    -1,  1186,  1187,  1188,   790,    -1,    -1,   793,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,     6,    -1,    -1,   195,   186,  1223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1237,    -1,    -1,    -1,    -1,  1242,     6,
     845,    -1,    -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,
      -1,  1255,  1256,    -1,    -1,    -1,    -1,    -1,  1262,  1263,
       7,    -1,   195,  1267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1275,    -1,   644,    -1,   880,   881,   882,   883,    -1,
      -1,  1285,    -1,  1287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,  1311,    -1,    -1,
      -1,  1315,    -1,    -1,  1318,    -1,    -1,    -1,    -1,  1323,
    1324,  1325,  1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   936,  1336,    -1,   705,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1346,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,  1362,  1363,
      -1,    -1,    -1,    -1,    -1,    -1,  1370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
    1404,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,  1422,   186,
    1424,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,  1439,    -1,  1441,   809,   186,
    1444,    -1,    -1,    -1,   815,    -1,    -1,  1451,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1464,    -1,     6,    -1,    -1,  1469,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     851,  1485,    -1,    -1,   186,    -1,    -1,    -1,  1492,    -1,
    1494,    -1,  1496,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1506,    -1,    -1,    -1,  1510,  1511,  1512,  1513,
    1514,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,  1529,  1530,     6,    -1,   186,
    1534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1544,    -1,    -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,
      -1,   922,   923,    -1,   925,  1160,   927,   928,    -1,    -1,
     931,   932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1578,    -1,    -1,    -1,    -1,  1583,
      -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,    -1,    -1,
      -1,    -1,     6,  1597,    -1,    -1,  1600,    -1,    -1,  1603,
      -1,    -1,    -1,  1607,    -1,    -1,    -1,  1611,    -1,  1613,
    1614,  1615,  1616,  1617,    -1,    -1,    -1,    -1,    -1,    -1,
    1624,    -1,    -1,  1627,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,     8,    -1,
      -1,    -1,   186,    -1,  1015,  1016,  1017,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1026,    -1,    -1,    -1,    -1,
    1664,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1679,    -1,  1681,  1682,  1683,
    1684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,  1311,   186,  1079,    -1,
    1315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1723,
    1724,  1725,  1726,    -1,     8,    -1,    -1,  1098,    -1,    -1,
      -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,  1110,
      -1,  1112,  1113,    -1,    -1,    -1,  1117,  1118,  1119,  1120,
    1121,  1122,  1123,  1124,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,  1139,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1154,    -1,    -1,    -1,  1158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,     8,    -1,  1424,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,  1444,
     186,    -1,    -1,    -1,    -1,    -1,  1451,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,     8,    -1,    -1,  1236,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1485,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,  1506,   186,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,  1313,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,  1330,
      -1,    57,    -1,    59,    60,    61,  1337,    -1,    -1,    -1,
    1341,    67,    68,    -1,  1345,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,  1364,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1611,    -1,  1613,    -1,
      -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,   143,  1419,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1679,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,   187,    -1,   189,    -1,   191,   192,  1468,   194,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1484,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
    1501,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,  1560,
      -1,    74,    -1,    -1,    77,    -1,    79,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    -1,    -1,    -1,  1626,    -1,    -1,    -1,    -1,
    1631,    68,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,   177,   178,    -1,   186,    -1,   182,
      -1,    -1,    -1,    -1,   187,    -1,    -1,     3,     4,   192,
      -1,   194,   195,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,  1712,    -1,   150,   151,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,   162,    12,    13,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     106,    -1,    -1,   109,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    91,    92,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,
      -1,   187,    -1,    -1,    -1,    -1,   192,    -1,    -1,   195,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    -1,    -1,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   177,   178,    -1,    -1,   186,   182,
     188,    -1,    -1,    -1,   187,   193,     3,     4,     5,   192,
      -1,   194,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    -1,     3,     4,     5,    -1,
      67,    68,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   149,   150,   151,   152,    -1,   193,    -1,   195,
     157,   158,   159,   160,   161,   162,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     177,   178,    -1,    -1,   186,   182,    -1,    -1,    -1,    -1,
     187,   193,    -1,   195,    -1,   192,    -1,   194,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   149,   150,   151,   152,   186,    -1,   188,    -1,
     157,   158,   159,   160,   161,   162,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     177,   178,    -1,    -1,   186,   182,    -1,    -1,    -1,    -1,
     187,   193,     3,     4,     5,   192,    -1,   194,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   195,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   177,   178,    -1,    -1,
     186,   182,    -1,    -1,    -1,    -1,   187,   193,     3,     4,
       5,   192,    -1,   194,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,   109,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,   177,   178,    -1,   186,    -1,   182,    -1,    -1,
      -1,    -1,   187,   194,     3,     4,     5,   192,    -1,   194,
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
     109,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,   177,   178,
      -1,   186,    -1,   182,    -1,    -1,    -1,    -1,   187,   194,
       3,     4,    -1,   192,    -1,   194,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,   109,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,   177,   178,    -1,   186,    -1,   182,
      -1,    -1,    -1,    -1,   187,   194,     3,     4,    -1,   192,
      -1,   194,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,   109,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     177,   178,    -1,    -1,   186,   182,    -1,    -1,    -1,    -1,
     187,   193,     3,     4,    -1,   192,    -1,   194,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,   109,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   177,   178,    -1,    -1,
     186,   182,    -1,    -1,    -1,    -1,   187,   193,     3,     4,
      -1,   192,    -1,   194,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,   109,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   177,   178,    -1,    -1,   186,   182,    -1,    -1,
      -1,    -1,   187,   193,     3,     4,    -1,   192,    -1,   194,
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
     109,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   177,   178,
      -1,    -1,   186,   182,    -1,    -1,    -1,    -1,   187,   193,
       3,     4,    -1,   192,    -1,   194,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,     3,
       4,     5,    -1,    -1,    67,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    -1,    -1,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,   149,    -1,    -1,   152,
      -1,    -1,   195,    -1,   157,   158,   159,   160,   161,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,   177,   178,    -1,   186,    -1,   182,
      -1,    -1,    -1,    -1,   187,    -1,   195,    -1,    -1,   192,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   177,   178,    -1,    -1,   186,   182,     3,
       4,    -1,    -1,   187,   193,     9,    10,    11,   192,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,   109,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   177,   178,    -1,    -1,   186,   182,     3,
       4,    -1,    -1,   187,   193,     9,    10,    11,   192,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,   149,    -1,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,   177,   178,    -1,    -1,    -1,   182,    50,
      51,    52,    -1,   187,    55,    56,    -1,    58,   192,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    -1,    -1,    -1,   115,   116,   117,     4,    -1,    -1,
      -1,    -1,   123,    -1,    -1,    12,    13,   128,   129,   130,
     131,    -1,    -1,   134,    -1,   136,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    -1,    -1,
      37,    38,   153,   154,   155,   156,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    50,    51,    52,    -1,    -1,    55,    56,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,    -1,   134,    -1,   136,
      -1,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,   153,   154,   155,   156,
      -1,    -1,    -1,    -1,    -1,    -1,   163,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,   193,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,    -1,   190,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,   190,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
      -1,    -1,   190,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,    -1,    -1,   190,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,   190,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,   190,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,    -1,   190,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
     190,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,   188,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,    -1,
     188,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,   186,
      -1,   188,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
     186,    -1,   188,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,   186,    -1,   188,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,    -1,    -1,
      -1,    -1,   186,    -1,   188,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      -1,    -1,    -1,    -1,   186,    -1,   188,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,    -1,    -1,    -1,    -1,   186
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   198,   199,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    55,    56,    58,    62,    63,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   115,   116,   117,   123,   128,   129,   130,   131,
     134,   136,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   153,   154,   155,   156,   163,   200,   202,
     203,   223,   240,   241,   244,   245,   246,   247,   248,   249,
     250,   251,   272,   273,   274,   275,   293,   294,     3,     4,
       5,     9,    10,    11,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    53,    54,    57,
      59,    60,    61,    67,    68,   143,   149,   150,   151,   152,
     157,   158,   159,   160,   161,   162,   177,   178,   182,   187,
     189,   191,   192,   194,   196,   221,   276,   277,   289,   290,
     293,   294,    13,    77,   187,   187,     6,   194,     6,     6,
       6,     6,   187,     6,     6,   189,   189,   187,   189,   221,
     221,   187,   194,   187,   187,     4,   187,   194,   187,   187,
       4,   194,   187,   187,    81,    77,    77,     6,   194,    71,
      74,    77,    77,    77,    74,    77,    79,    79,    71,    74,
      77,    79,    74,    77,    79,    74,    77,   187,    74,   134,
     147,   148,   194,   177,   178,   187,   194,   279,   280,   279,
     194,    71,    74,    77,   194,   279,     4,    71,    75,    87,
      77,    79,    77,    74,     4,   143,   194,     4,     6,    71,
      74,    77,    74,    77,     4,     4,     4,     4,     5,    36,
      71,    74,    77,    79,    91,   178,   187,   194,   241,   251,
     276,   282,   283,   284,   293,   294,     4,   187,   187,   187,
       4,   194,   286,     4,   187,   187,     6,     6,   189,     4,
     293,   294,     4,     5,   194,     5,   194,     4,   276,   276,
       6,   187,   194,   187,   189,   196,   221,     7,   164,   165,
     166,   167,   184,   185,   219,   220,     4,   187,   189,   191,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   187,   187,   187,   187,   187,
     187,   221,   187,   221,   221,   221,     7,   187,   187,   187,
     221,   187,   187,   276,   276,   276,   276,   276,     4,   134,
     135,   294,     4,   241,   242,   243,   194,   188,   190,   194,
     222,     6,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   186,   194,     6,   187,
     189,   220,     6,   276,     4,   289,   290,   294,   289,   276,
     289,   292,   225,   228,   290,   294,   276,   178,   276,   284,
     285,   276,   276,   187,   276,   285,   276,   276,   187,   285,
     276,   276,   282,   187,   194,   285,   283,   283,   283,   187,
     187,   283,   283,   283,   187,   187,   187,   187,   187,   187,
     187,   187,   282,   276,     4,   282,   286,   194,   194,   279,
     279,   279,   276,   276,   177,   178,   194,   194,   279,   194,
     194,   194,   177,   178,   187,   243,   279,   194,   187,   194,
     187,   187,   187,   283,   283,   282,   187,     4,     6,   189,
     189,   243,     6,   194,   194,   194,   283,   283,   189,   189,
     189,   187,   189,   191,   221,   189,     5,   137,   194,     5,
     137,     5,   137,     5,   137,    71,    74,    77,    79,   194,
     276,   284,   276,   195,   285,     8,   179,     6,   187,   189,
     221,     6,   276,   276,   276,   191,   276,   194,   137,   276,
     276,   276,     6,     6,   243,     6,   243,   189,     6,   194,
     282,   282,   276,   276,   194,   194,   222,   290,   282,     6,
     189,   276,   276,     4,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   292,   289,   292,   289,
     289,   289,   282,   289,   289,   276,   292,   289,   276,   290,
     276,   289,   289,   289,   289,   294,   290,   188,   190,     7,
     219,   220,   191,     7,   221,   195,    71,    74,    77,    79,
     240,   276,   285,     7,   219,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     204,   276,   276,     6,   189,   191,   188,   193,   188,   193,
     193,   188,   193,   190,   193,   224,   190,   224,   193,   193,
     188,   179,   193,   195,   188,   188,   276,   188,   195,   188,
     188,   276,   195,   188,   188,     7,   276,   276,   195,     6,
       6,     6,   276,   276,     7,     7,   269,   269,   276,   234,
     276,   290,   235,   276,   290,   236,   276,   290,   237,   276,
     290,   276,   276,   276,     7,   194,   188,     6,   194,   243,
     243,   193,   193,   193,   279,   279,   242,   242,   193,   276,
     276,   276,   276,   255,   193,   243,   276,   276,   276,   276,
     276,     7,   270,     6,     7,   276,     6,   276,   276,   195,
     285,   285,   285,     6,     6,   276,   276,   276,   276,     4,
     194,   222,   294,    50,   276,    50,    50,    50,     5,   194,
       5,   194,     5,   194,     5,   194,   285,   188,   195,   276,
     194,   276,   284,   194,   222,   188,   188,   188,   134,   193,
     243,   194,     8,   188,   190,   195,   195,   243,   188,   193,
     195,   188,   190,   276,   285,   219,     6,     6,   276,   188,
     190,   220,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   193,   222,   222,   222,   222,   222,   222,
     222,   193,   193,   193,   222,   193,   222,   222,   188,   188,
     193,   193,   193,   193,   193,   188,   222,   278,   291,     6,
     193,   188,   188,   193,   222,   188,   188,   219,   220,   191,
     219,   220,   290,   276,     6,     4,     4,   194,   287,   222,
     194,   194,   194,   194,   195,   195,   282,     8,     4,   124,
     125,   126,   127,   195,   207,   211,   214,   216,   217,   188,
     190,   276,     4,     6,   174,   201,   285,     6,   285,   276,
       6,   289,     6,   294,     6,   289,   276,   290,     7,   276,
     284,   137,     7,     7,   188,     7,   137,     7,     7,   188,
     137,     7,     7,   276,   188,   195,   194,   188,   188,   276,
     282,     4,   268,     6,   188,   188,   188,   188,   188,   188,
     188,   188,   282,   285,   191,   243,   195,   195,   279,   276,
     276,   195,   195,   276,   279,   193,   193,   193,    94,   104,
     112,   113,   114,   118,   119,   120,   121,   265,   266,   279,
     195,   252,   188,   195,   188,   188,   188,   276,     6,   276,
     188,   190,   190,   195,   195,   195,   190,   190,   193,   190,
     285,   190,   194,   195,   194,   194,   194,   285,   285,   285,
     285,   195,     8,   285,   285,     7,     7,     7,   191,   276,
     195,   276,   276,     7,   191,   195,   194,   282,     6,   219,
     220,   219,   220,   195,   195,   282,   190,   220,   191,   220,
     289,   276,   276,   276,   276,   285,   289,   282,   289,   289,
     290,   230,   232,   276,   289,   276,     6,     4,   134,   135,
     276,     6,     6,     6,     7,   189,   286,   288,     6,   285,
     285,   285,   285,   222,     6,   276,   208,   187,   187,   194,
     218,     6,   220,   220,   190,   174,   289,   188,   188,   193,
       7,   222,   222,   279,    77,    79,   282,   282,     7,   282,
      77,    79,   282,   282,     7,    79,   282,   282,     6,     7,
       7,   285,     7,     7,    94,   267,     6,     7,   219,   219,
     219,   219,     7,     7,     7,     6,   195,     4,   195,   193,
     193,   193,   195,   195,   279,   279,   279,     4,     6,   194,
       6,   187,     6,   122,     6,   122,     6,   122,     6,   122,
     195,   266,   193,   265,     7,     6,     7,     7,     7,     6,
     194,     6,     6,     6,    77,   276,     6,     6,   276,   191,
     195,   276,   276,   276,   276,   195,   195,   195,   195,   276,
     195,   195,   282,   282,   282,     4,   193,     8,     8,   188,
       4,     4,   282,   195,   276,     6,   276,     6,   222,     6,
       6,     4,     6,   222,   222,   222,   222,   222,   193,   188,
     188,   188,   193,   193,   222,   231,   193,   222,   233,   188,
     188,     6,     7,   219,   220,   191,     7,     6,   286,   276,
     193,   195,   195,   195,   195,   195,   219,   187,   276,   276,
     281,   282,   194,   191,     6,     6,   201,     6,   276,   194,
     276,   290,     6,     6,     6,   194,   194,    87,   239,   239,
     282,     6,   194,   194,     6,     6,   282,   194,     6,     6,
       5,   282,   195,   282,   282,     4,     6,   282,   282,   282,
     282,   282,   282,   282,   282,     7,     6,     7,   276,   276,
     276,   194,   194,   193,   195,   193,   195,   193,   195,   189,
     276,   282,   276,     6,     6,     6,     6,   276,   279,   195,
       5,   194,   282,   194,   194,   194,   282,   285,   194,     6,
     190,     4,   222,   193,   193,   193,   193,   222,     6,     6,
     133,   276,   276,   276,     6,     6,     7,   193,     6,     6,
       6,   219,   220,   289,   290,     4,     4,   290,   276,     6,
       4,   287,     6,   190,   286,     6,     6,     6,     6,   282,
     205,   276,   193,   193,   193,   195,   206,   276,     4,   289,
     193,   276,   290,   276,   276,   279,     6,     6,     6,   276,
     276,     6,   276,     5,     6,   194,     6,   137,   238,   276,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   276,
     276,   290,   195,   188,   193,   195,   242,   242,   279,     6,
     256,   279,     6,   257,   279,     6,   258,   276,   195,   193,
     188,   195,   193,     6,   178,   279,     6,   281,   279,   279,
       6,   195,   276,     6,   276,   276,   276,   276,   282,   193,
     195,     8,   195,   188,   194,   276,   290,   282,   282,   188,
     222,   194,   282,   290,   194,   276,   290,     6,     6,     7,
       6,   191,     6,   188,   193,   276,   276,   282,   194,   193,
     195,     6,   276,   226,   227,   195,   195,   195,   195,   195,
       5,   281,    75,     6,   194,   194,     6,     6,   194,   276,
     195,   195,   193,   194,   193,   194,   193,   194,   190,     6,
     282,     7,   194,   276,   193,   195,   193,   193,     6,   195,
     193,   193,   193,   193,   132,   276,   276,   285,     6,     6,
     195,     6,   229,   276,   292,   286,   135,   209,   276,   193,
     193,   281,   276,     6,   193,   230,   232,     6,     6,     6,
       6,     6,     6,   195,   194,   281,   285,   242,   193,   195,
     276,   279,   265,   276,   279,   265,   276,   279,   265,     6,
     193,   195,   282,   243,   195,   279,     6,   285,   279,   276,
     276,   276,   276,   276,   195,   195,   195,     6,   193,   195,
       7,   195,     6,   194,   276,   276,   195,   276,   195,   195,
     194,   276,   195,   195,   195,   276,   195,   193,   195,   195,
     193,   195,   195,   193,   195,   282,     6,    94,   195,   253,
     194,   193,   195,   193,   193,   193,   193,   193,     6,     6,
     276,   290,   206,   188,   193,     6,   194,   193,   276,   195,
       6,    94,   271,   195,     6,   259,   276,     6,     6,   260,
     276,     6,     6,   261,   276,     6,   195,   276,   265,   243,
     285,     6,   279,   285,   276,   276,   276,   276,     7,   195,
     212,   276,   281,   276,   193,   282,     6,   194,   195,   194,
     195,   194,   195,     6,     6,   195,   195,   254,   195,   193,
     195,   193,   193,   193,   193,   290,     6,   194,   188,   195,
     195,   276,   265,     6,   262,   265,     6,   263,   265,     6,
     264,   265,     6,   285,     6,   276,   276,   276,   276,   210,
     289,   215,   194,     6,   195,   195,   194,   195,   194,   195,
     194,   195,   195,   193,   193,   193,   193,   193,   195,   194,
     281,     6,     6,   265,     6,   265,     6,   265,     6,   276,
     276,   276,   276,   289,     6,   213,   289,   195,   195,   195,
     195,   195,   195,   195,   195,   193,   195,     6,     6,     6,
       6,   289,     6
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
    { return 1; }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 206 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
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
#line 212 "Gmsh.y"
    { return 1; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 217 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 221 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 228 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 233 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 238 "Gmsh.y"
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

  case 27:
/* Line 1787 of yacc.c  */
#line 252 "Gmsh.y"
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

  case 28:
/* Line 1787 of yacc.c  */
#line 265 "Gmsh.y"
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

  case 29:
/* Line 1787 of yacc.c  */
#line 278 "Gmsh.y"
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

  case 30:
/* Line 1787 of yacc.c  */
#line 306 "Gmsh.y"
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

  case 31:
/* Line 1787 of yacc.c  */
#line 320 "Gmsh.y"
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

  case 32:
/* Line 1787 of yacc.c  */
#line 333 "Gmsh.y"
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

  case 33:
/* Line 1787 of yacc.c  */
#line 346 "Gmsh.y"
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

  case 34:
/* Line 1787 of yacc.c  */
#line 364 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 378 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 380 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 385 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 387 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 392 "Gmsh.y"
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

  case 45:
/* Line 1787 of yacc.c  */
#line 496 "Gmsh.y"
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

  case 46:
/* Line 1787 of yacc.c  */
#line 506 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 515 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 522 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 532 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 541 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 550 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 557 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 567 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 575 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 585 "Gmsh.y"
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

  case 56:
/* Line 1787 of yacc.c  */
#line 604 "Gmsh.y"
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

  case 57:
/* Line 1787 of yacc.c  */
#line 623 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 629 "Gmsh.y"
    {
    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 636 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 637 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 638 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 639 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 640 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 644 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 645 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 651 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 652 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 652 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 661 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 666 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 672 "Gmsh.y"
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

  case 75:
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

  case 76:
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

  case 77:
/* Line 1787 of yacc.c  */
#line 790 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 795 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 800 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 805 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 810 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 817 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 824 "Gmsh.y"
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

  case 84:
/* Line 1787 of yacc.c  */
#line 839 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 844 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 849 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 854 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 859 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::string((yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 868 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 874 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 883 "Gmsh.y"
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

  case 92:
/* Line 1787 of yacc.c  */
#line 901 "Gmsh.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 919 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 928 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 940 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 945 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 953 "Gmsh.y"
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

  case 98:
/* Line 1787 of yacc.c  */
#line 973 "Gmsh.y"
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

  case 99:
/* Line 1787 of yacc.c  */
#line 996 "Gmsh.y"
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

  case 100:
/* Line 1787 of yacc.c  */
#line 1007 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 1015 "Gmsh.y"
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

  case 102:
/* Line 1787 of yacc.c  */
#line 1037 "Gmsh.y"
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

  case 103:
/* Line 1787 of yacc.c  */
#line 1060 "Gmsh.y"
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

  case 104:
/* Line 1787 of yacc.c  */
#line 1086 "Gmsh.y"
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

  case 105:
/* Line 1787 of yacc.c  */
#line 1107 "Gmsh.y"
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

  case 106:
/* Line 1787 of yacc.c  */
#line 1119 "Gmsh.y"
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

  case 110:
/* Line 1787 of yacc.c  */
#line 1137 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 1146 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 1155 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 1157 "Gmsh.y"
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

  case 114:
/* Line 1787 of yacc.c  */
#line 1167 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 1176 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 1178 "Gmsh.y"
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

  case 118:
/* Line 1787 of yacc.c  */
#line 1192 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 1200 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 1206 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 1218 "Gmsh.y"
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

  case 124:
/* Line 1787 of yacc.c  */
#line 1229 "Gmsh.y"
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

  case 125:
/* Line 1787 of yacc.c  */
#line 1244 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 1260 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      double val = (yyvsp[(3) - (3)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 1268 "Gmsh.y"
    {
      std::string key((yyvsp[(2) - (3)].c));
      std::string val((yyvsp[(3) - (3)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (3)].c));
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 1277 "Gmsh.y"
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

  case 131:
/* Line 1787 of yacc.c  */
#line 1295 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 1299 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 1308 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 1312 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 1321 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 1325 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 1334 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 1338 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[(1) - (1)].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 1347 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 1351 "Gmsh.y"
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

  case 141:
/* Line 1787 of yacc.c  */
#line 1363 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 1367 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1377 "Gmsh.y"
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1400 "Gmsh.y"
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

  case 145:
/* Line 1787 of yacc.c  */
#line 1432 "Gmsh.y"
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

  case 146:
/* Line 1787 of yacc.c  */
#line 1455 "Gmsh.y"
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

  case 147:
/* Line 1787 of yacc.c  */
#line 1473 "Gmsh.y"
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

  case 148:
/* Line 1787 of yacc.c  */
#line 1494 "Gmsh.y"
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

  case 149:
/* Line 1787 of yacc.c  */
#line 1512 "Gmsh.y"
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

  case 150:
/* Line 1787 of yacc.c  */
#line 1542 "Gmsh.y"
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

  case 151:
/* Line 1787 of yacc.c  */
#line 1572 "Gmsh.y"
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

  case 152:
/* Line 1787 of yacc.c  */
#line 1590 "Gmsh.y"
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

  case 153:
/* Line 1787 of yacc.c  */
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
    }
    break;

  case 154:
/* Line 1787 of yacc.c  */
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
    }
    break;

  case 155:
/* Line 1787 of yacc.c  */
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
    }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1671 "Gmsh.y"
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

  case 157:
/* Line 1787 of yacc.c  */
#line 1706 "Gmsh.y"
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

  case 158:
/* Line 1787 of yacc.c  */
#line 1724 "Gmsh.y"
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

  case 159:
/* Line 1787 of yacc.c  */
#line 1763 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1769 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1775 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1782 "Gmsh.y"
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

  case 163:
/* Line 1787 of yacc.c  */
#line 1807 "Gmsh.y"
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

  case 164:
/* Line 1787 of yacc.c  */
#line 1832 "Gmsh.y"
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

  case 165:
/* Line 1787 of yacc.c  */
#line 1849 "Gmsh.y"
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

  case 166:
/* Line 1787 of yacc.c  */
#line 1869 "Gmsh.y"
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

  case 167:
/* Line 1787 of yacc.c  */
#line 1902 "Gmsh.y"
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

  case 168:
/* Line 1787 of yacc.c  */
#line 1938 "Gmsh.y"
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

  case 169:
/* Line 1787 of yacc.c  */
#line 1956 "Gmsh.y"
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

  case 170:
/* Line 1787 of yacc.c  */
#line 1973 "Gmsh.y"
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

  case 171:
/* Line 1787 of yacc.c  */
#line 1989 "Gmsh.y"
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

  case 172:
/* Line 1787 of yacc.c  */
#line 2026 "Gmsh.y"
    {
      TranslateShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 2031 "Gmsh.y"
    {
      RotateShapes((yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d), (yyvsp[(10) - (11)].l));
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 2036 "Gmsh.y"
    {
      SymmetryShapes((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3], (yyvsp[(4) - (5)].l));
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 2041 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 2046 "Gmsh.y"
    {
      DilatShapes((yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2], (yyvsp[(8) - (9)].l));
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 2051 "Gmsh.y"
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

  case 178:
/* Line 1787 of yacc.c  */
#line 2074 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[(4) - (9)].l), (int)(yyvsp[(8) - (9)].d), (yyval.l));
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 2080 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[(7) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
      SplitCurve((int)(yyvsp[(4) - (9)].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 2090 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 2091 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 2096 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 2100 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 2104 "Gmsh.y"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 2127 "Gmsh.y"
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

  case 186:
/* Line 1787 of yacc.c  */
#line 2150 "Gmsh.y"
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

  case 187:
/* Line 1787 of yacc.c  */
#line 2173 "Gmsh.y"
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

  case 188:
/* Line 1787 of yacc.c  */
#line 2201 "Gmsh.y"
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

  case 189:
/* Line 1787 of yacc.c  */
#line 2222 "Gmsh.y"
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

  case 190:
/* Line 1787 of yacc.c  */
#line 2249 "Gmsh.y"
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

  case 191:
/* Line 1787 of yacc.c  */
#line 2270 "Gmsh.y"
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

  case 192:
/* Line 1787 of yacc.c  */
#line 2291 "Gmsh.y"
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

  case 193:
/* Line 1787 of yacc.c  */
#line 2311 "Gmsh.y"
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

  case 194:
/* Line 1787 of yacc.c  */
#line 2423 "Gmsh.y"
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

  case 195:
/* Line 1787 of yacc.c  */
#line 2442 "Gmsh.y"
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

  case 196:
/* Line 1787 of yacc.c  */
#line 2481 "Gmsh.y"
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

  case 197:
/* Line 1787 of yacc.c  */
#line 2589 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 2598 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 2604 "Gmsh.y"
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

  case 200:
/* Line 1787 of yacc.c  */
#line 2619 "Gmsh.y"
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

  case 201:
/* Line 1787 of yacc.c  */
#line 2647 "Gmsh.y"
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

  case 202:
/* Line 1787 of yacc.c  */
#line 2664 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].u), false);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 2673 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(5) - (6)].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[(3) - (6)].u), true);
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 2687 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[(2) - (5)].d));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 2701 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 2707 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[(2) - (3)].c), i, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 2713 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 2722 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 2731 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(3) - (4)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 2740 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[(4) - (5)].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 2754 "Gmsh.y"
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

  case 212:
/* Line 1787 of yacc.c  */
#line 2810 "Gmsh.y"
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

  case 213:
/* Line 1787 of yacc.c  */
#line 2828 "Gmsh.y"
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

  case 214:
/* Line 1787 of yacc.c  */
#line 2845 "Gmsh.y"
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

  case 215:
/* Line 1787 of yacc.c  */
#line 2860 "Gmsh.y"
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

  case 216:
/* Line 1787 of yacc.c  */
#line 2879 "Gmsh.y"
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

  case 217:
/* Line 1787 of yacc.c  */
#line 2891 "Gmsh.y"
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

  case 218:
/* Line 1787 of yacc.c  */
#line 2915 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 2919 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 2924 "Gmsh.y"
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 2931 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 2936 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 2942 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 2947 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 2953 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 2961 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 2965 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 2969 "Gmsh.y"
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 2975 "Gmsh.y"
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

  case 230:
/* Line 1787 of yacc.c  */
#line 3029 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 3042 "Gmsh.y"
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

  case 232:
/* Line 1787 of yacc.c  */
#line 3059 "Gmsh.y"
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

  case 233:
/* Line 1787 of yacc.c  */
#line 3076 "Gmsh.y"
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

  case 234:
/* Line 1787 of yacc.c  */
#line 3097 "Gmsh.y"
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

  case 235:
/* Line 1787 of yacc.c  */
#line 3118 "Gmsh.y"
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

  case 236:
/* Line 1787 of yacc.c  */
#line 3153 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip_until(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 3161 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 3167 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 3174 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].d)) skip_until("If", "EndIf");
    }
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 3178 "Gmsh.y"
    {
    }
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 3187 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (5)].l),
		    (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 3195 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (11)].l),
		    0., 0., 0., (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(7) - (11)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(10) - (11)].l));
    }
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 3203 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (13)].l),
		    (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(9) - (13)].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[(12) - (13)].l));
    }
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 3211 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 3217 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[(4) - (7)].l),
		    (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(4) - (7)].l));
    }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 3225 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 3231 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[(10) - (13)].l),
		    0., 0., 0., (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(7) - (13)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(10) - (13)].l));
    }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 3239 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 3245 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[(12) - (15)].l),
		    (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2], (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(9) - (15)].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[(12) - (15)].l));
    }
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 3253 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 3259 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[(3) - (6)].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 3267 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 3274 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 3281 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (8)].d),
		   (yyvsp[(6) - (8)].v)[0], (yyvsp[(6) - (8)].v)[1], (yyvsp[(6) - (8)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 3288 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 3295 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 3302 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   0., 0., 0., (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], (yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], (yyvsp[(10) - (12)].d),
		   NULL, (yyval.l));
    }
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 3309 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 3323 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (14)].d),
		   (yyvsp[(6) - (14)].v)[0], (yyvsp[(6) - (14)].v)[1], (yyvsp[(6) - (14)].v)[2], (yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2], (yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2], (yyvsp[(12) - (14)].d),
		   NULL, (yyval.l));
    }
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 3330 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 3336 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 3343 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 3349 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 3356 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 3362 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (12)].d),
		   (yyvsp[(6) - (12)].v)[0], (yyvsp[(6) - (12)].v)[1], (yyvsp[(6) - (12)].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 3369 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 3375 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 3382 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 3388 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 3395 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 3401 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (16)].d),
		   0., 0., 0., (yyvsp[(6) - (16)].v)[0], (yyvsp[(6) - (16)].v)[1], (yyvsp[(6) - (16)].v)[2], (yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2], (yyvsp[(10) - (16)].d),
		   &extr, (yyval.l));
    }
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 3408 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 3414 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 3421 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 3427 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 3434 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 3440 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[(4) - (18)].d),
		   (yyvsp[(6) - (18)].v)[0], (yyvsp[(6) - (18)].v)[1], (yyvsp[(6) - (18)].v)[2], (yyvsp[(8) - (18)].v)[0], (yyvsp[(8) - (18)].v)[1], (yyvsp[(8) - (18)].v)[2], (yyvsp[(10) - (18)].v)[0], (yyvsp[(10) - (18)].v)[1], (yyvsp[(10) - (18)].v)[2], (yyvsp[(12) - (18)].d),
		   &extr, (yyval.l));
    }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 3451 "Gmsh.y"
    {
    }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 3454 "Gmsh.y"
    {
    }
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 3460 "Gmsh.y"
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

  case 282:
/* Line 1787 of yacc.c  */
#line 3472 "Gmsh.y"
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

  case 283:
/* Line 1787 of yacc.c  */
#line 3492 "Gmsh.y"
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

  case 284:
/* Line 1787 of yacc.c  */
#line 3516 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 3520 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 3524 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 3528 "Gmsh.y"
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 3532 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 3538 "Gmsh.y"
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 3544 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 3548 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 3552 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 3556 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 3560 "Gmsh.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 3579 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 3591 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 3595 "Gmsh.y"
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

  case 298:
/* Line 1787 of yacc.c  */
#line 3610 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 3614 "Gmsh.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 3630 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 3634 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 3639 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 3643 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 3649 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 3653 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 3660 "Gmsh.y"
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

  case 307:
/* Line 1787 of yacc.c  */
#line 3716 "Gmsh.y"
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

  case 308:
/* Line 1787 of yacc.c  */
#line 3786 "Gmsh.y"
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 3791 "Gmsh.y"
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

  case 310:
/* Line 1787 of yacc.c  */
#line 3858 "Gmsh.y"
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

  case 311:
/* Line 1787 of yacc.c  */
#line 3894 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (7)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (7)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(6) - (7)].d);
      }
    }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 3902 "Gmsh.y"
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

  case 313:
/* Line 1787 of yacc.c  */
#line 3945 "Gmsh.y"
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

  case 314:
/* Line 1787 of yacc.c  */
#line 3984 "Gmsh.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 4004 "Gmsh.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 4032 "Gmsh.y"
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

  case 317:
/* Line 1787 of yacc.c  */
#line 4080 "Gmsh.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 4108 "Gmsh.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 4136 "Gmsh.y"
    {
      Msg::Error("Point in Volume not implemented yet");
    }
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 4140 "Gmsh.y"
    {
      Msg::Error("Line in Volume not implemented yet");
    }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 4144 "Gmsh.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 4172 "Gmsh.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 4211 "Gmsh.y"
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

  case 324:
/* Line 1787 of yacc.c  */
#line 4250 "Gmsh.y"
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

  case 325:
/* Line 1787 of yacc.c  */
#line 4271 "Gmsh.y"
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

  case 326:
/* Line 1787 of yacc.c  */
#line 4292 "Gmsh.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 4319 "Gmsh.y"
    {
      ReplaceAllDuplicates();
    }
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 4323 "Gmsh.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 4333 "Gmsh.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 4367 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 4368 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 4369 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 4374 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 4380 "Gmsh.y"
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

  case 335:
/* Line 1787 of yacc.c  */
#line 4392 "Gmsh.y"
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

  case 336:
/* Line 1787 of yacc.c  */
#line 4410 "Gmsh.y"
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

  case 337:
/* Line 1787 of yacc.c  */
#line 4437 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 4438 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 4439 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 4440 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 4441 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 4442 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 4443 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 4444 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 4446 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 4452 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d);  }
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 4453 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 4454 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 4455 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 4456 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 4457 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 4458 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 4459 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 4460 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 4461 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 4462 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 4463 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 4464 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 4465 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 4466 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 4467 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 4468 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 4469 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 4470 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 4471 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 4472 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 4473 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 4474 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 4475 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 4476 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 4477 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 4478 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 4479 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 4480 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 4481 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 4482 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 4483 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 4484 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 4493 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 4494 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 4495 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 4496 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 4497 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 4498 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 4499 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 4500 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 4501 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 4502 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 4507 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 4509 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 4515 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 4520 "Gmsh.y"
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

  case 393:
/* Line 1787 of yacc.c  */
#line 4537 "Gmsh.y"
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

  case 394:
/* Line 1787 of yacc.c  */
#line 4555 "Gmsh.y"
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

  case 395:
/* Line 1787 of yacc.c  */
#line 4573 "Gmsh.y"
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

  case 396:
/* Line 1787 of yacc.c  */
#line 4591 "Gmsh.y"
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

  case 397:
/* Line 1787 of yacc.c  */
#line 4609 "Gmsh.y"
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 4614 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 4620 "Gmsh.y"
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

  case 400:
/* Line 1787 of yacc.c  */
#line 4632 "Gmsh.y"
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

  case 401:
/* Line 1787 of yacc.c  */
#line 4649 "Gmsh.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 4667 "Gmsh.y"
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

  case 403:
/* Line 1787 of yacc.c  */
#line 4685 "Gmsh.y"
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

  case 404:
/* Line 1787 of yacc.c  */
#line 4703 "Gmsh.y"
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

  case 405:
/* Line 1787 of yacc.c  */
#line 4724 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), (yyval.d));
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 4729 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 4734 "Gmsh.y"
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

  case 408:
/* Line 1787 of yacc.c  */
#line 4744 "Gmsh.y"
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

  case 409:
/* Line 1787 of yacc.c  */
#line 4754 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 4759 "Gmsh.y"
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

  case 411:
/* Line 1787 of yacc.c  */
#line 4770 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 4779 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 4784 "Gmsh.y"
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

  case 414:
/* Line 1787 of yacc.c  */
#line 4811 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 4815 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 4819 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 4823 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 4827 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 4834 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 4838 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 4842 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 4846 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 4853 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 4858 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 4865 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 4870 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 4874 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 4879 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 4883 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 4891 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 4902 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 4906 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 4918 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 4926 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 435:
/* Line 1787 of yacc.c  */
#line 4934 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 436:
/* Line 1787 of yacc.c  */
#line 4941 "Gmsh.y"
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

  case 437:
/* Line 1787 of yacc.c  */
#line 4951 "Gmsh.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 4980 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 4984 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 4988 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
    break;

  case 441:
/* Line 1787 of yacc.c  */
#line 4992 "Gmsh.y"
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 4996 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 5000 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 5004 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 5008 "Gmsh.y"
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 5012 "Gmsh.y"
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

  case 447:
/* Line 1787 of yacc.c  */
#line 5041 "Gmsh.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 5070 "Gmsh.y"
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

  case 449:
/* Line 1787 of yacc.c  */
#line 5099 "Gmsh.y"
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

  case 450:
/* Line 1787 of yacc.c  */
#line 5129 "Gmsh.y"
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

  case 451:
/* Line 1787 of yacc.c  */
#line 5142 "Gmsh.y"
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

  case 452:
/* Line 1787 of yacc.c  */
#line 5155 "Gmsh.y"
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

  case 453:
/* Line 1787 of yacc.c  */
#line 5168 "Gmsh.y"
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

  case 454:
/* Line 1787 of yacc.c  */
#line 5180 "Gmsh.y"
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

  case 455:
/* Line 1787 of yacc.c  */
#line 5190 "Gmsh.y"
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

  case 456:
/* Line 1787 of yacc.c  */
#line 5200 "Gmsh.y"
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

  case 457:
/* Line 1787 of yacc.c  */
#line 5212 "Gmsh.y"
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

  case 458:
/* Line 1787 of yacc.c  */
#line 5225 "Gmsh.y"
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

  case 459:
/* Line 1787 of yacc.c  */
#line 5237 "Gmsh.y"
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

  case 460:
/* Line 1787 of yacc.c  */
#line 5255 "Gmsh.y"
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

  case 461:
/* Line 1787 of yacc.c  */
#line 5276 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 462:
/* Line 1787 of yacc.c  */
#line 5281 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 463:
/* Line 1787 of yacc.c  */
#line 5285 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 464:
/* Line 1787 of yacc.c  */
#line 5289 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 465:
/* Line 1787 of yacc.c  */
#line 5301 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 466:
/* Line 1787 of yacc.c  */
#line 5305 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 467:
/* Line 1787 of yacc.c  */
#line 5317 "Gmsh.y"
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 468:
/* Line 1787 of yacc.c  */
#line 5324 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 469:
/* Line 1787 of yacc.c  */
#line 5334 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 470:
/* Line 1787 of yacc.c  */
#line 5338 "Gmsh.y"
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

  case 471:
/* Line 1787 of yacc.c  */
#line 5353 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 472:
/* Line 1787 of yacc.c  */
#line 5358 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 473:
/* Line 1787 of yacc.c  */
#line 5365 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 474:
/* Line 1787 of yacc.c  */
#line 5369 "Gmsh.y"
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

  case 475:
/* Line 1787 of yacc.c  */
#line 5382 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (3)].c), 0, (yyvsp[(3) - (3)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 476:
/* Line 1787 of yacc.c  */
#line 5390 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 477:
/* Line 1787 of yacc.c  */
#line 5401 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 478:
/* Line 1787 of yacc.c  */
#line 5405 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 479:
/* Line 1787 of yacc.c  */
#line 5413 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 480:
/* Line 1787 of yacc.c  */
#line 5419 "Gmsh.y"
    {
      std::string action = Msg::GetGmshOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 481:
/* Line 1787 of yacc.c  */
#line 5425 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 482:
/* Line 1787 of yacc.c  */
#line 5433 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 483:
/* Line 1787 of yacc.c  */
#line 5441 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 484:
/* Line 1787 of yacc.c  */
#line 5448 "Gmsh.y"
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

  case 485:
/* Line 1787 of yacc.c  */
#line 5463 "Gmsh.y"
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

  case 486:
/* Line 1787 of yacc.c  */
#line 5477 "Gmsh.y"
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

  case 487:
/* Line 1787 of yacc.c  */
#line 5491 "Gmsh.y"
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

  case 488:
/* Line 1787 of yacc.c  */
#line 5503 "Gmsh.y"
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

  case 489:
/* Line 1787 of yacc.c  */
#line 5519 "Gmsh.y"
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

  case 490:
/* Line 1787 of yacc.c  */
#line 5530 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 5534 "Gmsh.y"
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

  case 492:
/* Line 1787 of yacc.c  */
#line 5553 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 5560 "Gmsh.y"
    { floatOptions.clear(); charOptions.clear(); }
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 5562 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 5573 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 5578 "Gmsh.y"
    { List_Add((yyval.l), &((yyvsp[(3) - (3)].c))); }
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 5584 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 5593 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 5606 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 5609 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;


/* Line 1787 of yacc.c  */
#line 11679 "Gmsh.tab.cpp"
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
#line 5613 "Gmsh.y"


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
