/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs

#define yylval          gmsh_yylval
#define yychar          gmsh_yychar

/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y" /* yacc.c:339  */

// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include <map>
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
#define MAX_RECUR_TESTS 100
static int statusImbricatedTests[MAX_RECUR_TESTS];
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0, ImbricatedTest = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void skip_until_test(const char *skip, const char *until,
                     const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);

struct doubleXstring{
  double d;
  char *s;
};


#line 182 "Gmsh.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    tTestLevel = 269,
    tExp = 270,
    tLog = 271,
    tLog10 = 272,
    tSqrt = 273,
    tSin = 274,
    tAsin = 275,
    tCos = 276,
    tAcos = 277,
    tTan = 278,
    tRand = 279,
    tAtan = 280,
    tAtan2 = 281,
    tSinh = 282,
    tCosh = 283,
    tTanh = 284,
    tFabs = 285,
    tFloor = 286,
    tCeil = 287,
    tRound = 288,
    tFmod = 289,
    tModulo = 290,
    tHypot = 291,
    tList = 292,
    tPrintf = 293,
    tError = 294,
    tStr = 295,
    tSprintf = 296,
    tStrCat = 297,
    tStrPrefix = 298,
    tStrRelative = 299,
    tStrReplace = 300,
    tFind = 301,
    tStrFind = 302,
    tStrCmp = 303,
    tStrChoice = 304,
    tUpperCase = 305,
    tLowerCase = 306,
    tLowerCaseIn = 307,
    tTextAttributes = 308,
    tBoundingBox = 309,
    tDraw = 310,
    tSetChanged = 311,
    tToday = 312,
    tFixRelativePath = 313,
    tCurrentDirectory = 314,
    tSyncModel = 315,
    tNewModel = 316,
    tOnelabAction = 317,
    tOnelabRun = 318,
    tCpu = 319,
    tMemory = 320,
    tTotalMemory = 321,
    tCreateTopology = 322,
    tCreateTopologyNoHoles = 323,
    tDistanceFunction = 324,
    tDefineConstant = 325,
    tUndefineConstant = 326,
    tDefineNumber = 327,
    tDefineString = 328,
    tSetNumber = 329,
    tSetString = 330,
    tPoint = 331,
    tCircle = 332,
    tEllipse = 333,
    tLine = 334,
    tSphere = 335,
    tPolarSphere = 336,
    tSurface = 337,
    tSpline = 338,
    tVolume = 339,
    tCharacteristic = 340,
    tLength = 341,
    tParametric = 342,
    tElliptic = 343,
    tRefineMesh = 344,
    tAdaptMesh = 345,
    tRelocateMesh = 346,
    tPlane = 347,
    tRuled = 348,
    tTransfinite = 349,
    tComplex = 350,
    tPhysical = 351,
    tCompound = 352,
    tPeriodic = 353,
    tUsing = 354,
    tPlugin = 355,
    tDegenerated = 356,
    tRecursive = 357,
    tRotate = 358,
    tTranslate = 359,
    tSymmetry = 360,
    tDilate = 361,
    tExtrude = 362,
    tLevelset = 363,
    tAffine = 364,
    tRecombine = 365,
    tSmoother = 366,
    tSplit = 367,
    tDelete = 368,
    tCoherence = 369,
    tIntersect = 370,
    tMeshAlgorithm = 371,
    tReverse = 372,
    tLayers = 373,
    tScaleLast = 374,
    tHole = 375,
    tAlias = 376,
    tAliasWithOptions = 377,
    tCopyOptions = 378,
    tQuadTriAddVerts = 379,
    tQuadTriNoNewVerts = 380,
    tQuadTriSngl = 381,
    tQuadTriDbl = 382,
    tRecombLaterals = 383,
    tTransfQuadTri = 384,
    tText2D = 385,
    tText3D = 386,
    tInterpolationScheme = 387,
    tTime = 388,
    tCombine = 389,
    tBSpline = 390,
    tBezier = 391,
    tNurbs = 392,
    tNurbsOrder = 393,
    tNurbsKnots = 394,
    tColor = 395,
    tColorTable = 396,
    tFor = 397,
    tIn = 398,
    tEndFor = 399,
    tIf = 400,
    tElseIf = 401,
    tElse = 402,
    tEndIf = 403,
    tExit = 404,
    tAbort = 405,
    tField = 406,
    tReturn = 407,
    tCall = 408,
    tMacro = 409,
    tShow = 410,
    tHide = 411,
    tGetValue = 412,
    tGetStringValue = 413,
    tGetEnv = 414,
    tGetString = 415,
    tGetNumber = 416,
    tHomology = 417,
    tCohomology = 418,
    tBetti = 419,
    tExists = 420,
    tFileExists = 421,
    tGMSH_MAJOR_VERSION = 422,
    tGMSH_MINOR_VERSION = 423,
    tGMSH_PATCH_VERSION = 424,
    tGmshExecutableName = 425,
    tSetPartition = 426,
    tNameToString = 427,
    tStringToName = 428,
    tAFFECTPLUS = 429,
    tAFFECTMINUS = 430,
    tAFFECTTIMES = 431,
    tAFFECTDIVIDE = 432,
    tOR = 433,
    tAND = 434,
    tEQUAL = 435,
    tNOTEQUAL = 436,
    tLESSOREQUAL = 437,
    tGREATEROREQUAL = 438,
    tPLUSPLUS = 439,
    tMINUSMINUS = 440,
    UNARYPREC = 441
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 109 "Gmsh.y" /* yacc.c:355  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;

#line 419 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 436 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  522
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1849

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   441

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   192,     2,   202,     2,   191,     2,     2,
     197,   198,   189,   187,   203,   188,   201,   190,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     183,     2,   185,   178,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   199,     2,   200,   196,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   204,     2,   205,   206,     2,     2,     2,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   179,   180,   181,   182,   184,   186,   193,
     194,   195
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   198,   203,   205,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   228,   232,   239,   244,   249,   263,   276,   289,
     317,   331,   344,   357,   376,   381,   382,   383,   384,   385,
     389,   391,   396,   398,   404,   508,   403,   526,   533,   544,
     543,   561,   568,   579,   578,   595,   612,   635,   634,   648,
     649,   650,   651,   652,   656,   657,   663,   663,   664,   664,
     670,   671,   672,   677,   683,   743,   772,   801,   806,   811,
     816,   821,   828,   835,   850,   855,   860,   865,   870,   879,
     885,   894,   912,   930,   939,   951,   956,   964,   984,  1007,
    1018,  1026,  1048,  1071,  1097,  1118,  1130,  1144,  1144,  1146,
    1148,  1157,  1167,  1166,  1184,  1194,  1193,  1207,  1209,  1217,
    1223,  1230,  1231,  1235,  1246,  1261,  1271,  1272,  1277,  1285,
    1294,  1302,  1320,  1324,  1330,  1338,  1342,  1348,  1356,  1360,
    1366,  1374,  1378,  1384,  1393,  1396,  1409,  1412,  1422,  1445,
    1485,  1508,  1526,  1547,  1565,  1595,  1625,  1643,  1661,  1688,
    1706,  1724,  1767,  1785,  1824,  1830,  1836,  1843,  1868,  1893,
    1910,  1929,  1963,  2007,  2025,  2042,  2058,  2103,  2108,  2113,
    2118,  2123,  2128,  2151,  2157,  2168,  2169,  2174,  2177,  2181,
    2204,  2227,  2250,  2278,  2299,  2325,  2346,  2368,  2388,  2500,
    2519,  2557,  2666,  2675,  2681,  2696,  2724,  2741,  2750,  2764,
    2778,  2784,  2790,  2799,  2808,  2817,  2831,  2890,  2908,  2925,
    2940,  2966,  2978,  3002,  3006,  3011,  3018,  3023,  3029,  3034,
    3040,  3048,  3052,  3056,  3061,  3121,  3138,  3155,  3177,  3199,
    3234,  3242,  3250,  3256,  3263,  3270,  3290,  3316,  3328,  3340,
    3348,  3356,  3365,  3364,  3379,  3378,  3393,  3392,  3407,  3406,
    3420,  3427,  3434,  3441,  3448,  3455,  3462,  3469,  3476,  3484,
    3483,  3497,  3496,  3510,  3509,  3523,  3522,  3536,  3535,  3549,
    3548,  3562,  3561,  3575,  3574,  3588,  3587,  3604,  3607,  3613,
    3625,  3645,  3669,  3673,  3677,  3681,  3685,  3691,  3697,  3701,
    3705,  3709,  3713,  3732,  3745,  3748,  3764,  3767,  3784,  3787,
    3793,  3796,  3803,  3806,  3813,  3869,  3939,  3944,  4011,  4047,
    4055,  4098,  4137,  4157,  4189,  4216,  4242,  4268,  4294,  4320,
    4342,  4370,  4398,  4402,  4406,  4434,  4473,  4512,  4533,  4554,
    4581,  4585,  4595,  4630,  4631,  4632,  4636,  4642,  4654,  4672,
    4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,  4715,
    4716,  4717,  4718,  4719,  4720,  4721,  4722,  4723,  4724,  4725,
    4726,  4727,  4728,  4729,  4730,  4731,  4732,  4733,  4734,  4735,
    4736,  4737,  4738,  4739,  4740,  4741,  4742,  4743,  4744,  4745,
    4746,  4747,  4756,  4757,  4758,  4759,  4760,  4761,  4762,  4763,
    4764,  4765,  4766,  4771,  4770,  4778,  4783,  4788,  4805,  4823,
    4841,  4859,  4877,  4882,  4888,  4900,  4917,  4935,  4953,  4971,
    4992,  4997,  5002,  5012,  5022,  5027,  5038,  5047,  5052,  5079,
    5083,  5087,  5091,  5095,  5102,  5106,  5110,  5114,  5121,  5126,
    5133,  5138,  5142,  5147,  5151,  5159,  5170,  5174,  5186,  5194,
    5202,  5209,  5219,  5248,  5252,  5256,  5260,  5264,  5268,  5272,
    5276,  5280,  5309,  5338,  5367,  5396,  5409,  5422,  5435,  5448,
    5458,  5468,  5480,  5493,  5505,  5523,  5544,  5549,  5553,  5557,
    5569,  5573,  5585,  5595,  5605,  5609,  5624,  5629,  5636,  5640,
    5653,  5661,  5672,  5676,  5680,  5688,  5694,  5700,  5708,  5716,
    5723,  5731,  5746,  5760,  5774,  5786,  5802,  5811,  5820,  5830,
    5841,  5845,  5864,  5871,  5878,  5877,  5890,  5895,  5901,  5910,
    5923,  5926,  5930
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10", "tSqrt", "tSin",
  "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh",
  "tCosh", "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod",
  "tModulo", "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf",
  "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace", "tFind",
  "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase",
  "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tCurrentDirectory",
  "tSyncModel", "tNewModel", "tOnelabAction", "tOnelabRun", "tCpu",
  "tMemory", "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineString", "tSetNumber", "tSetString", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tPlane",
  "tRuled", "tTransfinite", "tComplex", "tPhysical", "tCompound",
  "tPeriodic", "tUsing", "tPlugin", "tDegenerated", "tRecursive",
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset",
  "tAffine", "tRecombine", "tSmoother", "tSplit", "tDelete", "tCoherence",
  "tIntersect", "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast",
  "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tMacro", "tShow", "tHide", "tGetValue",
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tHomology",
  "tCohomology", "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTPLUS",
  "tAFFECTMINUS", "tAFFECTTIMES", "tAFFECTDIVIDE", "'?'", "tOR", "tAND",
  "tEQUAL", "tNOTEQUAL", "'<'", "tLESSOREQUAL", "'>'", "tGREATEROREQUAL",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "tPLUSPLUS", "tMINUSMINUS",
  "UNARYPREC", "'^'", "'('", "')'", "'['", "']'", "'.'", "'#'", "','",
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
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Loop", "Extrude", "$@8", "$@9", "$@10", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "$@21", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@22",
  "RecursiveListOfStringExprVar", "StringIndex", "String__Index", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,    63,   433,
     434,   435,   436,    60,   437,    62,   438,    43,    45,    42,
      47,    37,    33,   439,   440,   441,    94,    40,    41,    91,
      93,    46,    35,    44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1343

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1343)))

#define YYTABLE_NINF -492

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7148,   126,    86,  7268, -1343, -1343,  3752,   127,    70,   -37,
     -13,    36,   267,   332,   342,   348,    72,   384,   391,    12,
     202,  -167,  -167,   -86,   210,   227,    18,   230,   234,    17,
     244,   285,   418,   352,   425,   531,   311,   405,   445,   475,
     370,   474,   654,   454,   205,   371,   508,   -36,   395,  -123,
    -123,   398,   215,    67,   252,   513,   524,    24,    53,   555,
     560,   232,   639,   651,   661,  5256,   673,   472,   495,   503,
      29,    41, -1343,   511,   519, -1343, -1343,   726,   729,   485,
   -1343,  5337,  5724,    19,    32, -1343, -1343, -1343,  7008,   545,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343, -1343, -1343,    50, -1343,   161,    85,
   -1343,    13, -1343, -1343, -1343, -1343, -1343,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   528,   557,   558,   573,   580,   588,  -167,  -167,
    -167,  -167,   594, -1343,  -167, -1343, -1343, -1343, -1343, -1343,
    -167,  -167,   794,   623,   626,   630,  -167,  -167,   637,   644,
   -1343, -1343, -1343, -1343,   646,  7008,  7008,  7008,  7008,  7008,
      40,     9,    62,   648,   -74,  1131, -1343,   649,   840,   162,
    -121,   857,  7008,  5533,  5533, -1343,  7008, -1343, -1343, -1343,
   -1343,  5533, -1343, -1343, -1343, -1343, -1343, -1343,  5920,     9,
    7008,  6818,  7008,  7008,   688,  7008,  6818,  7008,  7008,   715,
    6818,  7008,  7008,  5648,   721,   746, -1343,  6818,  5256,  5256,
    5256,   733,   736,  5256,  5256,  5256,   744,   756,   757,   765,
     766,   769,   770,   774,   784,  3428,   871,  5648,    29,   785,
     799,  -123,  -123,  -123,  7008,  7008,  -127, -1343,   -65,  -123,
     824,   828,   836,  3662,   -42,   -49,   803,   848,   868,  5256,
    5256,  5648,   875,     1,   797, -1343,   804,  1015,  1074, -1343,
     886,   890,   893,  5256,  5256,   903,   906,   914,   516, -1343,
     922,    14,    15,    20,    26,   658,  5844,  7008,  4171, -1343,
   -1343,  2819, -1343,  1120, -1343,   214,    11,  1121,  7008,  7008,
    7008,  -107,  7008,   930, -1343,   992,  7008,  7008,  7008, -1343,
   -1343,  7008,   934,  1136,  1137, -1343, -1343,  1139, -1343,  1140,
   -1343,   522,  8020,  5533, -1343,  5648,  5648,  7008,  7008,   944,
     324,  5920, -1343, -1343, -1343, -1343, -1343, -1343,  5648,  1143,
     952,  7008,  7008,  1150,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008,  5533,  5533,  5533,  5533,
    5533,  5533,  5648,  5533,  5533,  7008,  5533,  5533,  5533,  5533,
    5533,  7008,  5920,  7008,  5533,  5533,  5533,  5533,  5533,     9,
    5920,     9,   959,   959,   959,  9645,  6002,   124,   955,  1152,
    -167,   957, -1343,   958,  5102,  7008, -1343, -1343,  6818,    -4,
   -1343,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,  7008,
    7008,  7008,  7008,  7008,  7008,  7008, -1343, -1343,  7008,  7008,
   -1343, -1343,  1242,   345,   -82, -1343, -1343,    -2,  8127, -1343,
     287,  -157,   169,   962,   979,  9666,  6818,  4346, -1343,    80,
    9687,  9708,  7008,  9729,   211,  9750,  9771,  7008,   237,  9792,
    9813,  1178,  7008,  7008,   344,  1180,  1181,  1185,  7008,  7008,
    1191,  1203,  1203,  7008,  6628,  6628,  6628,  6628,  7008,  7008,
    7008,  6818,  6818,  8047,  1013,  1209,  1012, -1343, -1343,  -135,
   -1343, -1343,  8153,  8179,  -123,  -123,    62,    62,    89,  7008,
    7008,  7008,  3662,  3662,  7008,  5102,   101, -1343,  7008,  7008,
    7008,  7008,  7008,  1215,  1217,  1220,  7008,  1224,  7008,  7008,
    1452, -1343, -1343,  6818,  6818,  6818,  1225,  1226,  7008,  7008,
    7008,  7008,  7008,  1229,   426,     9, -1343,  1183,  7008, -1343,
    1186, -1343,  1187, -1343,  1188,    33,    35,    42,    44,  6818,
     959, -1343,  9834, -1343,   361,  7008,  6040, -1343,  7008,  7008,
     482, -1343,  9855,  9876,  9897,  1095,  8205, -1343,  1030,  4366,
    9918,  9939,  9323, -1343, -1343, -1343,  1489, -1343,  1583,  7008,
   -1343,  1043,  1046,   362,  9960,  9346,  7008,  6818,    -4,  1239,
    1240, -1343,  7008,  9981,  9369,   -43,  1525,  1525,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  1525,  1525,  8231,  1525,  1525,
    1525,  1525,  1525,  1525,  1525,  8257,  8283,  8309,   575,   586,
     575,  1049,  1051,  1047,  1048,  1052,  1053,  8335,   509,   509,
     509,   456,   509, 10443, -1343,  1300,  1054,  1055,  1056,   590,
     599,  1063,  1064,  1065,   131,    81,  5920,  7008,  1246,  1259,
      25,   509, -1343,    68,    37,    31,   105, -1343,  6524,   430,
   -1343,  5648,  4550,  2083,  2328,   987,   987,   402,   402,   402,
     402,   175,   175,   959,   959,   959,   959,     4, 10002,  9392,
   -1343,  7008,  1260,     3,  6818,  1264,  6818,  7008,  1265,  5533,
    1266, -1343,     9,  1267,  5533,  7008,  5920,  1269,  6818,  6818,
    1123,  1271,  1272, 10023,  1274,  1141,  1275,  1278, 10044,  1145,
    1279,  1282,  7008, 10065,  6552,  1086, -1343, -1343, -1343, 10086,
   10107,  7008,  5648,  1270,  1285, 10128,  1096, 10443,  1092,  1099,
   10443,  1097,  1100, 10443,  1098,  1104, 10443,  1101, 10149, 10170,
   10191,   521,   614,  6818,  1107, -1343, -1343,  1745,  1921,  -123,
    7008,  7008, -1343, -1343,  1118,  1119,  3662,  8361,  8387,  8413,
    8101,   -12,  -123,  2141, 10212,  6585, 10233, 10254, 10275,  7008,
    1319, -1343,  7008, 10296, -1343,  9415,  9438, -1343,   634,   656,
     665, -1343, -1343,  9461,  9484,  8439,  9507,    11,  6818, -1343,
    1126,  1124,  6756,  1125,  1127,  1132, -1343,  6818, -1343,  6818,
   -1343,  6818, -1343,  6818,   671, -1343, -1343,  4962,  6818,   959,
   -1343,  6818, -1343,  1323,  1328,  1330,  1138,  7008,  2317,  7008,
    7008, -1343, -1343,    51, -1343, -1343,  2407, -1343,  1134,  5648,
    1334,   131,   131,  6903,   681,  5648, -1343, -1343,  9530,    11,
    1066, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343,  7008, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343,  7008,  7008,  7008, -1343,  6818, -1343, -1343, -1343, -1343,
    5533,  5648,  5533,  5533,  5920, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343,  7008,  5533, -1343,  5533, -1343,  7008, -1343,
   -1343, -1343, -1343,  7008,  1335,    46,  7008,  1336,  1337,  1949,
   -1343,  1341,  1153,    29,  1338, -1343,  6818,  6818,  6818,  6818,
   -1343,   509,  1343,  7008, -1343,  1156,  1157,  1151, -1343,  1350,
   -1343, -1343, -1343, -1343, -1343,    11,    11,  9553, -1343, -1343,
    1173,  5533,   549, -1343,   602,  8465, -1343, -1343, -1343,  1352,
   -1343, -1343,  1525,   509,  -123,  4346, -1343,   812,  5648,  5648,
    1354,  5648,   813,  5648,  5648,  1356,  1284,  5648,  5648,  2107,
    1362,  1363,  6818,  1368,  1369,  5982, -1343, -1343,  1371, -1343,
    1373,    -4,  7008,    -4,  7008,    -4,  7008,    -4,  7008,  1374,
    1375,  1376,  1377,  1378,   695,  1383,  2485, -1343, -1343,   125,
    8491,  8517, -1343, -1343,  6931,   -78,  -123,  -123,  -123,  1384,
    1385,  1189,  1386,  1192,     5,    21,    28,    57,   435, -1343,
     132, -1343,   -12,  1390,  1392,  1393,  1394,  1396, 10443, -1343,
    2251,  1200,  1402,  1403,  1404,  1329,  1405,  1407,  1409,  7008,
     128,   698, -1343,  7008, -1343,  7008,  7008,  7008,   699,   702,
     703,   706, -1343,  7008,   714,   718,  5648,  5648,  5648,  1412,
    8543, -1343,  4981,   795,  1413,  1415, -1343,  5648,  1231, -1343,
    7008,  1428,  7008,  1434, -1343,   509,  1436,  1437, -1343,  1440,
   -1343,  1439,  1525,  1525,  1525,  1525,   609,  1243,  1249,  1250,
    1251,  1248,   613,   632, 10317,  1252,   509,  1525,  2522, -1343,
     303,  1253,  1446,  2800, -1343, -1343, -1343,    29,  7008, -1343,
     719, -1343,   722,   723,   731,   734,    -4, -1343, 10443,  1263,
    7008,  7008,  5648,  1257, -1343, -1343, -1343,  1256, -1343,  1456,
      10,  1457,  7008,  4799,  1460,  1461,     6,  1268,  1273,  1381,
    1381,  5648,  1462,  1288,  1289,  1463,  1464,  5648,  1290,  1468,
    1469, -1343,  1490,  5648,   737,  5648,  5648,  1494,  1497, -1343,
    5648,  5648, 10443,  5648, 10443,  5648, 10443,  5648, 10443,  5648,
    5648,  5648,  1296,  1301,  1499,   411, -1343,  7008,  7008,  7008,
    1304,  1305,  -112,  -108,  -103,  1312, -1343,  5648, -1343,  7008,
   -1343,  1506, -1343,  1508, -1343,  1509, -1343,  1510, -1343, -1343,
    3662,   526,  5452, -1343,  1313,  1317,  6236, -1343,  6818, -1343,
   -1343, -1343,  1339,  7008, -1343, -1343,  9576,  1519,   509,  8569,
    8595,  8621,  8647, -1343, -1343, -1343, -1343, 10443, -1343,   509,
    1534,  1536,  1411, -1343,  7008,  7008,  7008, -1343,  1540,   466,
    1348,  1546,  2855, -1343,  3149, -1343,    -4, -1343, -1343,   -40,
   -1343, -1343, -1343, -1343, -1343, -1343,  5533, -1343, -1343, -1343,
    5920,  1551, -1343, -1343,    22, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343,  5920,  7008,  1550,  1554,    25, -1343,  1555,  9599,
      29, -1343,  1557,  1558,  1569,  1571,  5648,  7008,  8673,  8699,
     743, -1343,  7008,  1556, -1343, -1343,  5533, -1343,  8725,  4407,
   10443, -1343, -1343, -1343, -1343,  7008,  7008,  -123,  1572,  1573,
    1574, -1343,  7008,  7008, -1343, -1343,  1577,  7008, -1343, -1343,
    1587,  1588,  1389,  1591,  1455,  7008, -1343,  1593,  1594,  1595,
    1597,  1600,  1601,   943,  1602,  6818,  6818,  7008, -1343,  6628,
    7264, 10338,  3375,    62,    62,  -123,  1603,  -123,  1607,  -123,
    1608,  7008,   278,  1417, 10359, -1343, -1343, -1343, -1343,  7292,
     139, -1343,  1609,  3963,  1615,  5648,  -123,  3963,  1616,   754,
    7008,  3182,  1621,    11, -1343,  7008,  7008,  7008,  7008, -1343,
   -1343, -1343,  5648,  6174,   578, 10380, -1343, -1343,  4864,  5648,
   -1343, -1343, -1343,  5648, -1343,  1430,   509,  4603,  5060,  5920,
    1623,  3201, -1343,  1624,  1627, -1343,  1429, -1343, -1343, -1343,
   -1343, -1343,  1628,   635, 10443,  7008,  7008,  5648,  1431,   789,
   10443, -1343,  1630,  7008, -1343, -1343,  7320,  7348,   263, -1343,
   -1343, -1343,  7376,  7404, -1343,  7432,  1632, -1343,  5648, -1343,
    1559,  1634, 10443, -1343, -1343, -1343, -1343, -1343, -1343,  1438,
   -1343, -1343,   792,   796,  8074,  3563,  1638,  1442, -1343,  7008,
   -1343,  1443,  1444,   153, -1343,  1447,   159, -1343,  1448,   201,
   -1343,  1449,  9622,  1644,  5648,  1649,  1465,  7008, -1343,  6432,
     218, -1343,   806,   222,   235, -1343,  1665,  7460, -1343, -1343,
    8751,  8777,  8803,  8829,  1535,  7008, -1343,  7008, -1343, -1343,
    6818,  3693,  1666,  1472,  1668, -1343, -1343,  4171, -1343, -1343,
    5533, 10443, -1343, -1343, -1343, -1343,    29, -1343,  1541, -1343,
   -1343,  7008,  8855,  8881, -1343,  5648,  7008,  1679, -1343,  8907,
   -1343, -1343,  1680,  1681,  1682,  1683,  1684,  1685,   814,  1488,
   -1343,  5648,   642,   678,  6818, -1343, -1343,    62,  6370, -1343,
   -1343,  3662,   -12,  3662,   -12,  3662,   -12,  1687, -1343,   817,
    5648, -1343,  7488,  -123,  1689,  6818,  -123, -1343, -1343,  7008,
    7008,  7008,  7008,  7008,  7516,  7544,   821, -1343, -1343,  1693,
   -1343,   822,  4202,   826,  1694, -1343,  1513, 10443,  7008,  7008,
     833, 10443, -1343,  7008,   834,   853, -1343, -1343, -1343, -1343,
   -1343, -1343,  1518,  7008,   854,  1520,  -123,  5648,  1695,  1522,
    -123,  1721,   870,  1528,  7008, -1343,  7572,   283,   730,  7600,
     288,   763,  7628,   338,   888, -1343,  5648,  1728,  1636,  2562,
    1532,   413, -1343,   873,   444,  8933,  8959,  8985,  9011,  3901,
   -1343, -1343,  1731, -1343,  7008, -1343,  5920, -1343, -1343,  7008,
   10401,  9037,    45,  9063, -1343, -1343,  7008,  7656,  1732,  -123,
      63, -1343, -1343,  -123,    76, -1343,  1733, -1343,  7684,  1734,
    7008,  1735,  1737,  7008,  1738,  1740,  7008,  1741,  1543, -1343,
    7008, -1343,   -12, -1343,  6818,  1744,  6432,  7008,  7008,  7008,
    7008, -1343, -1343,   392, -1343,   874, -1343,  7008, -1343,  5648,
    7008,  9089, -1343, -1343,   484, -1343,   487, -1343, -1343, -1343,
   -1343,  1549,  7712, -1343, -1343,  1552,  7740, -1343, -1343,  1563,
    7768, -1343,  1748,  4117,   924,  2667,   883, -1343,   501,   884,
    9115,  9141,  9167,  9193,  5920,  1753,  1568, 10422,   898,  7796,
    7008,  -123,  -123,   -12,  1755,   -12,  1756,   -12,  1770, -1343,
   -1343, -1343, -1343,   -12,  1771,  6818,  1773,  7008,  7008,  7008,
    7008, -1343, -1343,  5533, -1343,  1578,  1775,  7824,   507,   515,
     942, -1343,  1579,  1070, -1343,  1580,  1082, -1343,  1581,  1094,
   -1343,   909, -1343,  9219,  9245,  9271,  9297,   917, -1343,  1582,
    5648, -1343,  1783,  7008,  7008,  1784,   -12,  1785,   -12,  1786,
     -12, -1343,  1787,  7008,  7008,  7008,  7008,  5533,  1788,  5533,
     927, -1343,  7852,  7880, -1343,  1247, -1343,  1400, -1343,  1492,
   -1343,  7908,  7936,  7964,  7992, -1343, -1343,   928, -1343,  1789,
    1790,  1791,  1793,  1794,  1795, -1343, -1343, -1343, -1343,  5533,
    1796, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,   247,   248,     0,     0,     0,
     242,     0,     0,     0,     0,   343,   344,   345,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   521,     0,
     392,   520,   492,   393,   395,   396,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,   513,   496,   400,   401,   402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,   495,     0,     0,     0,     0,    66,    67,
       0,     0,   187,     0,     0,     0,   350,     0,   488,   521,
     407,     0,     0,     0,     0,   227,     0,   229,   230,   225,
     226,     0,   231,   232,   109,   117,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,     0,   187,   521,     0,     0,   340,
       0,     0,     0,     0,     0,     0,     0,     0,   520,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     470,   440,   446,     0,   441,   521,   407,     0,     0,     0,
       0,   520,     0,     0,   482,     0,     0,     0,     0,   223,
     224,     0,   520,     0,     0,   240,   241,     0,   187,     0,
     187,   520,     0,     0,   346,     0,     0,    66,    67,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   352,   354,     0,     0,     0,     0,     0,
       0,     0,   186,     0,   185,     0,    68,    69,     0,     0,
     220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   216,     0,     0,
     415,   164,     0,   520,     0,   488,   489,     0,     0,   516,
       0,   107,   107,     0,     0,     0,     0,   476,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   187,     0,
     431,   430,     0,     0,     0,     0,   187,   187,     0,     0,
       0,     0,     0,     0,     0,   258,     0,   187,     0,     0,
       0,     0,     0,   310,     0,     0,     0,     0,     0,     0,
       0,   205,   341,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,     0,   453,     0,     0,   454,
       0,   455,     0,   456,     0,     0,     0,     0,     0,     0,
     352,   448,     0,   442,     0,     0,     0,   318,    66,    67,
       0,   222,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,   244,   243,   210,     0,   211,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,     0,    59,     0,     0,     0,
       0,     0,   182,     0,     0,     0,     0,   188,     0,     0,
      59,     0,     0,   368,   367,   365,   366,   361,   363,   362,
     364,   356,   355,   357,   358,   359,   360,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   337,   338,   339,     0,
       0,     0,     0,   306,     0,     0,     0,   132,   133,     0,
     135,   136,     0,   138,   139,     0,   141,   142,     0,     0,
       0,     0,     0,     0,     0,   152,   187,     0,     0,     0,
       0,     0,   433,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,     0,     0,
       0,   321,     0,     0,   206,     0,     0,   202,     0,     0,
       0,   336,   335,     0,     0,     0,     0,   420,     0,   471,
       0,     0,     0,     0,     0,     0,   457,     0,   458,     0,
     459,     0,   460,     0,     0,   351,   443,   450,     0,   357,
     449,     0,   472,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,   212,   214,     0,   522,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    74,     0,   409,
     408,   422,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   391,   379,     0,   381,   382,   383,   384,   385,   386,
     387,     0,     0,     0,   505,     0,   510,   501,   502,   503,
       0,     0,     0,     0,     0,   506,   507,   508,   428,   512,
     121,   126,    99,     0,     0,   497,     0,   499,     0,   405,
     412,   413,   493,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,   414,     0,     0,     0,     0,
     518,     0,     0,     0,    44,     0,     0,     0,    57,     0,
      35,    36,    37,    38,    39,   411,   410,     0,   490,    24,
      22,     0,     0,    25,     0,     0,   217,   517,    70,   110,
      71,   118,     0,     0,     0,   478,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   309,   307,     0,   317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   215,     0,
       0,     0,   177,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
       0,   249,     0,     0,     0,     0,     0,     0,   311,   320,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,     0,   473,     0,   452,     0,     0,     0,     0,     0,
       0,     0,   444,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   209,     0,     0,   347,
       0,     0,     0,     0,   519,     0,     0,     0,   417,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,    84,    89,    91,     0,     0,   486,
       0,    97,     0,     0,     0,     0,     0,    75,   369,     0,
       0,     0,     0,     0,    30,   419,   418,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,   134,     0,   137,     0,   140,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,   292,     0,
     298,     0,   300,     0,   294,     0,   296,     0,   259,   288,
       0,     0,     0,   200,     0,     0,     0,   322,     0,   204,
     203,   342,     0,     0,    31,    32,     0,     0,     0,     0,
       0,     0,     0,   461,   462,   463,   464,   451,   445,     0,
       0,     0,     0,   483,     0,     0,     0,   235,     0,     0,
       0,     0,     0,    87,     0,    86,     0,    76,   219,   421,
     218,   380,   388,   389,   390,   511,     0,   425,   426,   427,
       0,     0,   404,   122,     0,   515,   127,   424,   498,   500,
     406,    78,    59,     0,     0,     0,     0,    77,     0,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,     0,     0,    26,    27,     0,    28,     0,     0,
     111,   114,    72,    73,   148,     0,     0,     0,     0,     0,
       0,   151,     0,     0,   167,   168,     0,     0,   153,   174,
       0,     0,     0,     0,   144,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,   187,   187,     0,   269,     0,   271,     0,
     273,     0,   440,     0,     0,   299,   301,   295,   297,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   474,     0,     0,     0,     0,   475,
     156,   157,     0,     0,     0,     0,   100,   104,     0,     0,
     348,    80,    79,     0,   423,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,   487,   189,   190,
     191,   192,     0,     0,    40,     0,     0,     0,     0,     0,
      42,   491,     0,     0,   112,   115,     0,     0,   147,   154,
     155,   159,     0,     0,   169,     0,     0,   316,     0,   162,
       0,     0,   305,   173,   149,   161,   172,   176,   160,     0,
     170,   175,     0,     0,     0,     0,     0,     0,   437,     0,
     436,     0,     0,     0,   260,     0,     0,   261,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   198,     0,     0,     0,   193,     0,     0,   319,    33,
       0,     0,     0,     0,     0,     0,   481,     0,   237,   236,
       0,     0,     0,     0,     0,   504,   509,     0,   123,   125,
       0,   128,   129,   130,    90,    92,     0,    98,     0,    81,
      45,     0,     0,     0,   439,     0,     0,     0,    29,     0,
     121,   126,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,   312,   312,     0,   105,   106,   187,     0,   180,
     181,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,   187,     0,     0,     0,     0,     0,   184,   183,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,     0,
      82,     0,   476,     0,     0,   485,     0,    41,     0,     0,
       0,    43,    58,     0,     0,     0,   330,   332,   331,   333,
     334,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,     0,     0,     0,   254,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
     480,   238,     0,   349,     0,   124,     0,   131,    96,     0,
       0,     0,     0,     0,   113,   116,     0,     0,     0,     0,
       0,   313,   323,     0,     0,   324,     0,   178,     0,   275,
       0,     0,   277,     0,     0,   279,     0,     0,     0,   290,
       0,   250,     0,   187,     0,     0,     0,     0,     0,     0,
       0,   158,   103,     0,   119,     0,    49,     0,    55,     0,
       0,     0,   145,   171,     0,   327,     0,   328,   329,   434,
     263,     0,     0,   270,   264,     0,     0,   272,   265,     0,
       0,   274,     0,     0,     0,   256,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,   283,     0,   285,   291,
     302,   255,   251,     0,     0,     0,     0,     0,     0,     0,
       0,   120,    46,     0,    53,     0,     0,     0,     0,     0,
       0,   266,     0,     0,   267,     0,     0,   268,     0,     0,
     201,     0,   195,     0,     0,     0,     0,     0,    47,     0,
       0,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,   276,     0,   278,     0,   280,     0,
     196,     0,     0,     0,     0,    48,    50,     0,    51,     0,
       0,     0,     0,     0,     0,   465,   466,   467,   468,     0,
       0,    56,   325,   326,   282,   284,   286,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1343, -1343, -1343, -1343,   675, -1343, -1343, -1343, -1343,   154,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343,  -302,   -70,  2048,    -1, -1343,  1357, -1343, -1343,
   -1343, -1343, -1343,   280, -1343,   282, -1343, -1343, -1343, -1343,
   -1343, -1343,   674,  1808,     7,  -500,  -227, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343,  1812, -1343, -1343, -1343, -1343, -1343,
   -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1343, -1004,  -948,
   -1343, -1343,  1349, -1343,   274, -1343, -1343, -1343, -1343,  1553,
   -1343, -1343,    92, -1343, -1342,  2114,   428,  2598,  2729,  -247,
     542, -1343,    49,     8, -1343,  -374,    -3,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   941,    91,    92,   687,  1413,  1419,
     930,  1119,  1586,  1787,   931,  1736,  1827,   932,  1789,   933,
     934,  1123,   348,   440,   184,   419,    93,   702,   451,  1530,
    1531,   452,  1581,  1092,  1263,  1093,  1266,   736,   739,   742,
     745,  1441,  1308,   667,   299,   413,   414,    96,    97,    98,
      99,   100,   101,   102,   300,  1022,  1682,  1753,   771,  1465,
    1468,  1471,  1711,  1715,  1719,  1772,  1775,  1778,  1018,  1019,
    1158,   978,   733,   780,  1608,   104,   105,   106,   107,   301,
     186,   890,   501,   257,  1290,   302,   303,   304,   564,   313,
     914,  1110,   449,   445,   891,   450,   189,   306
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   496,   628,   670,   630,   527,   764,   765,   924,   939,
      95,  1190,  1304,   322,   188,   641,  1295,   350,  1201,   546,
     549,   219,   214,  1482,   327,   551,  1398,  1192,   273,   912,
     206,   553,   207,   311,  1194,   219,   515,   329,   806,   349,
     808,   214,   195,   700,   407,   315,   701,   810,   530,   812,
    1100,  1698,   504,   505,   276,   187,   334,   278,  1064,   279,
     504,   505,   305,  1196,   252,   253,   411,   276,   759,  1705,
    1199,   265,   346,   347,   254,   504,   505,   506,   276,   504,
     505,   255,  1707,  -489,   504,   505,     5,  1009,   670,   323,
     326,  1345,   341,  1346,   575,  1347,  1538,  1348,  1010,   183,
    1349,   586,  1350,   588,   248,   657,  1011,  1012,  1013,   504,
     505,   210,  1014,  1015,  1016,  1017,   693,   671,   211,   249,
     250,   694,   504,   505,   416,   109,   417,  1181,   190,   280,
     418,   656,     4,  1191,   925,   926,   927,   928,   670,   507,
     191,   256,   258,   266,   264,   504,   505,   267,   518,  1193,
     346,   347,   192,   346,   347,   519,  1195,   547,   550,   268,
     193,  -490,   517,   552,  -491,    48,    49,    50,    51,   554,
     342,   343,   344,   345,    56,   274,  1399,    59,   276,   277,
     408,   409,    89,  1590,   194,  1197,  1101,  1102,   940,   412,
     276,   276,   314,   504,   505,   940,   695,    89,   276,  1604,
     528,   696,    89,   324,   346,   347,   276,   183,   305,   929,
     351,   204,   352,   305,   353,   215,   453,   305,   548,   183,
     305,   220,   216,   328,   305,   305,   305,   305,   275,   913,
     305,   305,   305,   312,   215,   918,   330,   807,   316,   809,
     196,   917,   444,   447,   305,   276,   811,   335,   813,  1699,
     504,   505,  1065,  1199,   336,   342,   343,   344,   345,   342,
     343,   344,   345,   504,   505,   210,   305,   305,   305,   201,
     757,   758,   916,   197,   346,   347,   504,   505,   346,   347,
     305,   305,   905,   709,   244,   710,   565,   245,   504,   505,
     773,   260,   766,   305,   261,   305,   845,   262,   342,   343,
     344,   345,   222,   410,   772,   342,   343,   344,   345,   919,
    1272,   283,   504,   505,   284,   446,   446,   346,   347,   504,
     505,   346,   347,   446,   346,   347,   504,   505,  1177,  1217,
     276,   454,   305,   305,   269,  1200,   270,   658,   198,   598,
     504,   505,  1477,   499,   500,   305,   504,   505,   199,   599,
     828,   508,   903,   906,   200,   516,  1551,  1738,   337,   438,
     338,   439,  1553,   836,   432,   433,   434,   339,   339,   703,
     314,   435,   701,   276,   276,   276,   276,   276,   276,   305,
     276,   276,   591,   276,   276,   276,   276,   276,   504,   505,
     202,   276,   276,   276,   276,   276,   276,   203,   276,  1734,
     644,   205,   252,   253,  1555,   504,   505,   212,   652,   504,
     505,   568,   254,   569,   709,   305,   715,  1338,  1339,   263,
     339,  1563,   504,   505,   213,  1565,   629,   217,   631,   632,
     633,   218,   635,   636,   224,   638,   639,   640,  1566,   642,
     709,   221,   719,   646,   647,   648,   649,   650,  1810,   233,
     504,   505,   234,   305,   235,   446,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   566,   433,   434,
     504,   505,  1387,  1388,   435,   504,   505,   342,   343,   344,
     345,   228,   222,  1473,   229,   698,  1670,   230,   305,   305,
     699,  1673,   738,   741,   744,   747,   346,   347,   446,   446,
     446,   446,   446,   446,   223,   446,   446,   225,   446,   446,
     446,   446,   446,   412,   412,   227,   446,   446,   446,   446,
     446,   651,   416,   653,   417,   504,   505,   231,   597,   996,
     305,   305,   305,   241,  1009,   851,   242,   226,   243,  1070,
    1072,  1676,   276,   799,   691,  1010,   692,   709,  1618,   725,
    1621,   183,  1624,  1011,  1012,  1013,   305,   232,   236,  1014,
    1015,  1016,  1017,   305,   709,   839,   816,   840,   246,   822,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   904,   907,  1497,   247,   435,   430,
     431,   432,   433,   434,   305,   271,   762,   763,   435,   251,
     504,   505,   259,   272,   500,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   862,  1684,   864,   865,   866,
     867,   868,   869,   870,   416,  1009,   417,   874,   876,   877,
     798,   504,   505,   709,   281,   921,  1010,   885,   886,   887,
    1198,   889,   282,   285,  1011,  1012,  1013,  1686,   897,   899,
    1014,  1015,  1016,  1017,   888,   286,   475,   476,   477,   699,
     915,   480,   481,   482,   908,   287,  1109,   800,   305,   308,
    1199,   504,   505,  1199,   504,   505,  1199,   307,  1724,  1161,
     416,  1163,   417,  1165,   321,  1167,   821,  1741,   504,   505,
    1742,   305,   309,   305,   504,   505,   276,   523,   524,   276,
     310,   276,   504,   505,  1755,   305,   305,   416,   317,   417,
    1793,   536,   537,   541,   953,   542,   318,   543,  1794,   351,
     182,   589,   183,   543,   709,   379,   992,   851,   183,   305,
     237,  1361,   319,   238,   555,   320,   239,   556,   240,  1770,
     557,  1773,   558,  1776,   333,  1605,  1606,  1130,   947,  1779,
     305,  1607,   709,   951,   380,   381,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     382,  1071,  1073,   416,   435,   417,  1199,   383,   699,  1078,
    1080,  1609,  1610,  1498,   416,   384,   417,  1607,   416,   875,
     417,   389,  1815,   896,  1817,   305,  1819,   416,  1273,   417,
    1131,   393,   898,  1236,   305,   709,   305,   416,   305,   417,
     305,   416,   709,   417,  1286,   305,  1261,   709,   305,   993,
     394,   446,  1199,   395,   949,  1199,   446,   396,  1199,  1009,
     416,  1199,   417,  1520,   399,  1264,   305,   709,  1521,  1034,
    1010,   400,   305,  1461,  1462,   401,   437,   276,  1011,  1012,
    1013,   999,   415,   436,  1014,  1015,  1016,  1017,  1005,   709,
    1278,  1035,  1009,   441,  1020,  1125,  1126,  1199,   709,  1199,
    1036,  1199,   305,  1010,   709,   494,  1052,   276,   305,   276,
     276,  1011,  1012,  1013,   709,   462,  1075,  1014,  1015,  1016,
    1017,   276,  1091,   276,  1137,  1143,  1138,  1144,   709,  1081,
    1174,   709,   709,  1218,  1223,   709,   709,  1224,  1225,   709,
     276,  1226,   467,   305,   305,   305,   305,   709,   472,  1228,
    1116,   709,  1280,  1229,  1281,   709,   709,  1282,  1283,  1087,
     478,  1089,  1090,   479,   709,  1671,  1284,   709,   276,  1285,
     709,   483,  1322,  1095,  1393,  1096,  1417,  1449,  1418,  1450,
     473,  1134,  1135,   484,   485,   305,   305,   709,   305,  1486,
     305,   305,   486,   487,   305,   305,   488,   489,  1674,   305,
    1080,   490,   446,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,  1009,   491,   497,
    1129,   435,  1526,  1237,  1527,   709,   529,  1542,  1010,   709,
     520,  1543,   446,   498,   446,   446,  1011,  1012,  1013,  1417,
     339,  1564,  1014,  1015,  1016,  1017,   446,  1417,   446,  1602,
    1626,   531,  1627,  1009,   709,  1644,  1642,  1645,   509,   699,
    1274,  1647,   510,  1407,  1010,   314,  1417,  1261,  1652,  1654,
     511,  1009,  1011,  1012,  1013,   521,  1136,  1613,  1014,  1015,
    1016,  1017,  1010,   305,   305,   305,  1264,  1417,  1655,  1658,
    1011,  1012,  1013,   446,   305,   522,  1014,  1015,  1016,  1017,
     443,   112,   526,   709,  1246,  1666,   709,  1526,  1685,  1735,
     532,  1251,  1252,  1253,  1254,  1255,   709,   709,  1754,  1756,
     533,  1262,  1265,  1677,   534,  1269,  1270,   535,  1182,  1183,
    1184,  1417,   538,  1765,   276,   539,   139,   140,   141,   142,
     143,   144,   709,   540,  1802,   148,   149,   150,   151,   305,
    1807,   545,  1808,   153,   154,   155,   567,   571,   156,  1751,
    1417,  1839,  1829,  1840,   577,   578,  1583,   420,   305,   161,
     183,  1301,   583,   584,   305,   585,   587,  1795,   596,   601,
     305,   602,   305,   305,   605,   435,   659,   305,   305,   660,
     305,   182,   305,   662,   305,   705,   305,   305,   305,  1009,
     426,   427,   428,   429,   430,   431,   432,   433,   434,  1394,
    1010,  1009,   706,   435,   305,   722,   726,   727,  1011,  1012,
    1013,   728,  1010,  1009,  1014,  1015,  1016,  1017,   731,   305,
    1011,  1012,  1013,   305,  1010,   305,  1014,  1015,  1016,  1017,
     732,   754,  1011,  1012,  1013,   755,   756,  1374,  1014,  1015,
    1016,  1017,   779,   781,   164,   165,   166,   782,  1379,   314,
     784,   791,   792,   797,   829,   826,   173,   801,   174,    89,
     803,   804,   805,   837,   838,   846,   847,   878,   690,   879,
     880,   881,   910,   276,   895,   882,   883,   893,   894,   346,
     347,   900,   901,   911,   938,   902,   957,  1079,  1396,  1584,
     943,   946,   948,   950,   977,  1797,   954,   276,   958,   959,
    1400,   961,   963,   305,   962,   964,   967,  1799,   966,   968,
     972,   979,  1360,   276,   981,   982,   305,   983,   985,  1801,
     984,   986,   987,  1394,   988,  1395,   892,  1425,   995,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,  1002,  1003,  1029,  1042,   435,  1043,  1045,
    1056,  1046,   305,   305,  1629,  1057,  1047,  1058,  1067,  1059,
    1069,  1099,  1104,  1105,  1111,  1422,  1009,  1456,  1107,  1117,
     412,   412,  1108,  1120,  1121,  1122,  1124,  1010,  1128,  1133,
     305,  1141,   305,  1147,   305,  1011,  1012,  1013,  1148,  1152,
    1153,  1014,  1015,  1016,  1017,  1155,  1156,  1159,   446,   305,
    1160,  1169,  1170,  1171,  1172,  1173,   305,  1175,  1185,  1189,
     305,  1186,  1188,  1187,   305,  1506,  1502,  1202,  1203,  1428,
    1204,  1205,   314,  1206,  1208,  1509,  1512,  1513,  1209,  1210,
    1211,  1212,  1213,  1214,   305,  1215,  1233,  1238,   446,  1239,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,  1243,   305,  1241,  1463,   435,  1466,
    1245,  1469,  1247,  1248,  1249,  1250,  1256,  1257,  1258,  1259,
    1268,  1260,  1832,  1276,  1275,  1480,  1725,  1293,  1483,  1484,
    1287,  1292,  1294,  1297,     7,     8,  1302,  1303,  1311,  1314,
    1315,   305,  1305,  1307,  1318,  1319,   305,  1306,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,  1312,  1313,  1317,  1320,   435,   305,  1325,  1009,
    1335,     7,     8,  1326,   305,  1336,  1337,   276,  1343,  1344,
    1010,  1351,  1355,   276,  1356,  1357,  1358,  1365,  1011,  1012,
    1013,  1366,   305,  1373,  1014,  1015,  1016,  1017,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,   305,    33,
    1380,   305,  1381,  1370,    38,    39,  1386,    41,    42,    43,
    1382,  1389,  1390,    46,   412,  1397,  1402,   305,  1403,   185,
    1421,  1405,   305,  1408,  1409,   663,    24,    25,   664,    27,
      28,   665,    30,   666,    32,  1410,    33,  1411,  1429,  1430,
    1431,    38,    39,  1434,    41,    42,    43,    67,    68,    69,
      46,  1009,  1436,  1438,  1437,     7,     8,  1439,  1440,  1443,
    1444,  1445,  1010,  1446,   305,  1833,  1447,  1448,  1451,  1464,
    1011,  1012,  1013,  1467,  1470,  1478,  1014,  1015,  1016,  1017,
    1474,  1481,  1485,   305,    67,    68,    69,  1489,  1505,  1514,
    1518,  1516,   446,  1517,  1519,  1525,  1528,  1537,   314,  1539,
    1540,   332,  1541,  1617,  1546,  1620,  1547,  1623,  1549,  1550,
    1558,  1552,  1554,  1556,  1694,  1631,  1560,   787,  1634,   663,
      24,    25,   664,    27,    28,   665,    30,   666,    32,  1561,
      33,  1567,  1578,  1573,  1580,    38,    39,  1579,    41,    42,
      43,   305,  1585,   305,    46,  1592,  1596,  1597,  1598,  1599,
    1600,  1601,  1603,  1625,   834,  1632,   305,  1834,  1660,  1643,
    1648,  1662,  1664,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,  1649,    67,    68,
      69,   435,  1656,   416,  1659,   417,  1663,  1665,   402,   403,
     404,   405,   406,  1667,  1679,  1680,  1683,  1692,  1703,  1708,
    1710,  1713,  1761,  1714,  1717,   442,  1718,  1721,  1722,   448,
    1727,  1704,   305,  1743,  1749,  1706,  1745,     7,     8,  1762,
     276,  1771,  1774,   455,   457,   460,   461,  1747,   463,   457,
     465,   466,  1763,   457,   469,   470,  1777,  1780,  1728,  1782,
     457,  1791,  1790,  1796,  1798,  1800,  1809,   305,   835,  1811,
    1814,  1816,  1818,  1820,  1826,  1841,  1842,  1843,   493,  1844,
    1845,  1846,  1848,  1695,   276,  1296,   276,   502,   503,   704,
    1594,    94,  1788,  1595,  1309,   103,   503,  1611,  1404,     0,
       0,   663,    24,    25,   664,    27,    28,   665,    30,   666,
      32,   734,    33,  1768,  1769,     0,   276,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,   560,
     562,   457,     0,     0,     0,     0,  1825,     0,  1828,     0,
       0,   572,   573,   574,     0,   576,     0,     0,     0,   579,
     580,   581,     0,     0,   582,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,   446,     0,     0,  1847,     0,
     594,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   603,   604,     0,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   446,
       0,   446,     0,     7,     8,     0,     0,     0,   637,     0,
       0,     0,     0,     0,   643,     0,   645,     0,     0,     0,
     997,     0,     0,     0,     0,  1106,     0,     0,     0,     0,
       0,   446,     0,     0,     0,     0,     0,     0,   668,     0,
       0,   457,     0,     0,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,     0,
       0,   688,   689,     0,     0,     0,     0,   663,    24,    25,
     664,    27,    28,   665,    30,   666,    32,     0,    33,   560,
       0,     0,     0,    38,    39,   713,    41,    42,    43,     0,
     718,     0,    46,     0,     0,   723,   724,     0,     0,     0,
       0,   729,   730,     0,     0,     0,   735,   737,   740,   743,
     746,   748,   749,   750,   457,   457,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,   767,   768,   769,   402,   403,   770,     0,   208,
     209,   774,   775,   776,   777,   778,     0,     0,     0,   783,
       0,   785,   786,     0,     0,     0,   457,   457,   457,     0,
       0,   793,   794,   795,   603,   796,     0,     0,     0,     0,
       0,   802,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,  1151,     0,     0,     0,     0,   817,   819,
       0,   688,   689,     0,     0,     0,   998,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,   796,     0,     0,   435,     0,     0,     0,   843,
     457,     0,     0,     7,     8,   848,   340,     0,     0,     0,
       0,     0,     0,     0,     0,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
       0,     0,   390,     0,     0,     0,     0,     0,   391,   392,
     909,     0,     0,     0,   397,   398,     0,   663,    24,    25,
     664,    27,    28,   665,    30,   666,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,   937,     0,     0,   457,     0,   457,
     945,     0,     0,     0,     0,     0,     0,  1207,   952,     0,
       0,   819,   955,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   969,    67,    68,    69,   435,
       0,     0,     0,     0,   975,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,   457,     0,     0,     0,
       0,     0,     0,  1000,  1001,     0,     0,     0,     0,  1004,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,  1028,     0,     0,  1030,   544,   471,     0,     0,
       0,     0,     0,     0,     0,     0,  1021,     0,     0,     0,
       0,   457,     0,   570,     0,     0,     0,     0,     0,     0,
     457,   495,   457,     0,   457,     0,   457,     0,     0,     0,
       0,   457,     0,     0,   457,     0,     0,     0,     0,     0,
    1060,     0,  1062,  1063,     0,   525,     0,     0,     0,     0,
       0,     0,     0,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,  1082,     0,    46,     7,
       8,     0,     0,     0,  1083,  1084,  1085,     0,   457,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,  1094,   435,     0,   592,
     593,  1097,    67,    68,    69,     0,  1098,     0,   661,  1103,
       0,     0,   600,     0,     0,     0,     0,     0,     0,   457,
     457,   457,   457,     0,     0,     0,  1118,     0,     0,     0,
       0,     0,     0,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,     0,    33,     0,   634,     7,     8,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,  1061,     0,   435,   457,     0,     0,  1271,     0,
       0,     0,     0,     0,     0,  1162,     0,  1164,     0,  1166,
       0,  1168,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   663,    24,    25,   664,    27,    28,   665,    30,   666,
      32,     0,    33,     0,     7,     8,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,  1216,     0,     0,     0,  1219,     0,  1220,  1221,
    1222,     0,     0,     0,     0,     0,  1227,     0,     0,     0,
       0,     0,  1066,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,  1242,     0,  1244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,  1279,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1288,  1289,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,  1298,  1300,     0,     0,     0,
    1176,     0,     0,     0,     0,     0,     0,    67,    68,    69,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1340,  1341,  1342,     0,     0,     0,     0,     0,     0,     0,
    1352,     0,  1354,   663,    24,    25,   664,    27,    28,   665,
      30,   666,    32,  1359,    33,     0,     0,     0,     0,    38,
      39,   457,    41,    42,    43,     0,  1371,  1681,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   922,     0,  1383,  1384,  1385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,  1277,     0,     0,   458,
       0,     0,     0,     0,   458,     0,     0,     0,   458,     0,
       0,     0,     0,     0,     0,   458,  1401,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1414,     0,     0,     0,     0,  1420,   976,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1426,  1427,
       0,  1391,     0,     0,     0,  1432,  1433,     0,     0,     0,
    1435,     0,  1752,     0,     0,     0,     0,     0,  1442,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   457,
    1454,     0,  1455,     0,   561,     0,   458,     0,     0,     0,
       0,     0,     0,     0,  1472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,     0,     0,     0,
     457,     0,     0,  1487,     0,     0,     0,     0,  1490,  1491,
    1492,  1493,     0,     0,     0,     0,     0,     0,     0,     0,
     459,  1501,     0,     0,     0,   464,     0,     0,     0,   468,
       0,  1511,     0,  1068,     0,     0,   474,     0,     0,  1076,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,  1523,
       0,     0,     0,     0,     0,     0,  1529,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,  1088,   435,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   566,   433,
     434,     0,  1548,     0,     0,   435,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1562,     0,   560,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,  1574,     0,
    1575,   435,     0,   457,   561,     0,     0,     0,     0,     0,
    1582,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1139,  1140,  1587,  1142,     0,  1145,  1146,  1591,
       0,  1149,  1150,     0,     0,     0,     0,     0,     0,   458,
     458,     0,     0,     0,     0,     0,     0,   457,     0,     0,
       0,     0,     0,     0,  1616,     0,  1619,     0,  1622,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,  1635,  1636,  1637,  1638,  1639,     0,     0,     0,
       0,   458,   458,   458,     0,     0,     0,     0,     0,     0,
       0,  1650,  1651,     0,     0,     0,  1653,   669,     0,     0,
       0,     0,     0,     0,     0,  1392,  1657,   458,     0,     0,
       0,     0,     0,     0,   820,     0,     0,  1668,     0,     0,
    1230,  1231,  1232,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,     0,     0,     0,     0,     0,     0,  1488,     0,
       0,     0,     0,     0,     0,   458,     0,  1693,     0,     0,
       0,     0,  1420,     0,     0,     0,     0,  1515,     0,  1701,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,   752,     0,  1712,     0,     0,  1716,     0,     0,  1720,
       0,     0,     0,  1723,     0,     0,  1291,   457,     0,   457,
    1730,  1731,  1732,  1733,     0,     0,     0,     0,     0,     0,
    1737,     0,     0,  1739,     0,  1310,     0,     0,     0,     0,
       0,  1316,   788,   789,   790,     0,     0,  1321,     0,  1323,
    1324,     0,     0,     0,  1327,  1328,     0,  1329,     0,  1330,
       0,  1331,     0,  1332,  1333,  1334,     0,     0,   814,     0,
       0,     0,   458,  1767,   458,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,   820,   956,   457,     0,
    1783,  1784,  1785,  1786,     0,     0,  1364,     0,     0,     0,
    1368,     0,     0,     0,     0,     0,   844,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,  1812,  1813,     0,     0,
       0,   458,     0,     0,     0,     0,  1821,  1822,  1823,  1824,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,   458,   435,     0,     0,
    1412,     0,     0,     0,     0,   458,     0,   458,     0,   458,
       0,   458,     0,  1424,     0,     0,   458,     0,     0,   458,
       0,     0,     0,   942,     0,   944,     0,     0,     0,     0,
       0,   110,   331,     0,     0,     0,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   145,   146,   147,     0,     0,  1291,
       0,   152,   994,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,  1494,     0,     0,     0,
     160,     0,     0,  1503,     0,     0,     0,  1504,     0,     0,
       0,  1508,     0,     0,   458,   458,   458,   458,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1041,     0,     0,
       0,  1524,     0,     0,     0,     0,  1048,     0,  1049,     0,
    1050,     0,  1051,     0,     0,     0,     0,  1054,     0,     0,
    1055,     0,  1291,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,  1545,
     458,   435,     0,     0,     0,     0,     0,     0,  1459,     0,
    1460,     0,     0,     0,     0,   163,     0,     0,  1559,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     181,     0,   492,     0,     0,     0,     0,     0,     0,  1291,
       0,     0,     0,     0,     0,  1112,  1113,  1114,  1115,     0,
       0,     0,     0,     0,     0,  1291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   331,     0,     0,     0,
       0,   113,   114,   115,  1628,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,  1577,
       0,  1154,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,  1661,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,     0,     0,
    1678,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   110,   111,   112,     0,   435,
       0,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   458,     0,     0,   153,
     154,   155,     0,  1291,   156,     0,   157,   158,   159,   163,
       0,     0,     0,   167,   160,   161,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
     513,     0,     0,     0,   177,     0,     0,     0,     0,   514,
       0,     0,     0,     0,   181,     0,   255,     0,     0,     0,
       0,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,  1291,     0,     0,  1691,     0,   163,
     164,   165,   166,   167,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,   174,    89,     0,     0,     0,     0,
       0,     0,     0,   458,   458,     0,     0,  1369,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   178,
       0,   179,     0,   180,   181,     0,   182,     0,   183,     0,
       0,   458,     0,     0,     0,   458,   110,   288,     0,     0,
       0,     0,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,  1452,  1453,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,   561,    59,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,   458,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,  1750,   167,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,     0,    89,     0,     0,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
     512,  1479,     0,     0,     0,   177,     0,     0,     0,     0,
     514,     0,     0,   458,     0,   181,     0,   255,   563,     0,
       0,     0,     0,     0,   110,   288,     0,     0,     0,     0,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   290,  1646,
     565,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,  1576,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,  1612,    48,    49,    50,    51,    52,     0,
       0,     0,   458,    56,   458,     0,    59,     0,     0,     0,
       0,     0,     0,     0,  1633,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   565,     0,     0,     0,   175,   456,
       0,     0,     0,   177,     0,     0,     0,     0,   297,     0,
       0,     0,     0,   181,   830,     0,   563,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   708,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   288,   112,  1726,     0,  1729,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   290,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,   291,  1781,     0,   292,     0,     0,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   708,   433,   434,     0,     0,
       0,     0,   435,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   923,     0,
       0,     0,   435,     0,   163,   164,   165,   166,   167,     0,
       0,     0,   168,   169,   170,   171,   172,   173,     0,   174,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   296,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,   110,   288,   112,   181,
       0,   298,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,   161,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   164,   165,   166,   167,     0,     0,     0,   168,   169,
     170,   171,   172,   173,     0,   174,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   296,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,   110,   331,   112,   181,     0,  1507,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,   110,   331,   112,
       0,   160,   161,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
     167,     0,     0,     0,   168,   169,   170,   171,   172,   173,
    1053,   174,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   176,     0,  1235,
       0,   177,     0,     0,     0,     0,   297,     0,     0,     0,
       0,   181,     0,  1299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,     0,     0,     0,   168,
     169,   170,   171,   172,   173,     0,   174,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   331,   112,   181,     0,  1500,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     7,     8,     0,   153,   154,   155,
       0,     0,   156,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,   663,    24,
      25,   664,    27,    28,   665,    30,   666,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,     0,     0,     0,   168,   169,   170,   171,   172,
     173,     0,   174,    89,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,   175,   176,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,   289,   181,     0,  1510,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,   322,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   148,   149,   150,   151,
       0,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   296,     0,     0,     0,   177,     0,
       0,     0,     0,   297,     0,   110,   288,  1362,   181,     0,
     298,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,   164,   165,   166,   145,   146,
     147,     0,     0,     0,     0,   152,     0,   173,     0,   174,
      89,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,   443,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,     0,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     296,     0,     0,     0,   177,     0,     0,     0,     0,   297,
       0,   110,   288,     0,   181,     0,  1363,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,     0,     0,     0,     0,
       0,   164,   165,   166,   145,   146,   147,     0,     0,     0,
       0,   152,     0,   173,     0,   174,    89,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   291,     0,     0,   292,   325,   112,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   148,   149,   150,   151,     0,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   296,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   110,   288,     0,
     181,     0,   298,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   290,   164,   165,   166,     0,     0,     0,     0,     0,
     145,   146,   147,     0,   173,     0,   174,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     291,     0,     0,   292,     0,   112,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   148,
     149,   150,   151,     0,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   167,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   456,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   288,     0,   181,     0,   559,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   290,   164,   165,
     166,  1157,     0,     0,     0,     0,   145,   146,   147,     0,
     173,     0,   174,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,   163,   435,     0,
       0,   167,   655,     0,     0,   168,   169,   170,   171,   172,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   456,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,     0,   181,     0,   818,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,  1495,     0,  1496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   296,     0,     0,     0,   177,     0,
       0,     0,     0,   297,     0,   110,   288,     0,   181,     0,
    1367,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,  1614,     0,  1615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
    1479,     0,     0,     0,   177,     0,     0,     0,     0,   514,
       0,   110,   331,   112,   181,     0,   255,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   161,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,   920,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,   971,     0,     0,
       0,     0,     0,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,   163,   164,   165,   166,   167,
    1024,     0,     0,   168,   169,   170,   171,   172,   173,     0,
     174,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,   110,   288,     0,     0,   297,     0,   113,   114,   115,
     181,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1044,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   456,     0,     0,     0,
     177,   110,   331,     0,     0,   297,     0,   113,   114,   115,
     181,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1074,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,   163,     0,     0,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,    -4,    -4,    -4,   297,     0,     0,    -4,    -4,
     181,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     9,    10,     0,     0,
      -4,    -4,    -4,     0,     0,     0,     0,     0,     0,    -4,
       0,    -4,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    88,
       0,    89,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1457,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1476,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1532,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1533,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1534,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1535,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1536,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1568,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1630,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1640,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1641,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1669,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1672,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1675,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1702,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1709,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1744,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1746,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1748,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1766,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1792,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1830,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1831,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1835,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1836,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1837,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1838,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,   590,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,   753,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,  1544,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   815,
       0,     0,     0,     0,   760,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     697,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   760,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   761,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   827,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   863,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     871,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   872,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   873,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   884,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1006,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1007,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1008,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1039,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1132,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1178,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1179,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1234,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1375,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1376,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1377,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1378,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1415,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1416,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1423,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1569,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1570,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1571,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1572,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1588,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1589,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1593,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1687,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1688,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1689,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1690,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1697,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1700,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1740,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1757,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1758,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1759,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1760,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1803,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1804,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1805,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1806,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,   833,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,   842,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,   850,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,   936,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,  1032,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,  1033,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,  1037,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,  1038,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,  1040,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
    1077,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,  1127,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,  1372,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,  1406,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,  1557,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   654,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   707,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   711,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   712,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   714,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   716,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   717,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     720,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   721,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   815,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   823,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   824,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   825,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   831,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   832,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   841,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   849,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     935,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   960,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   965,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   970,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   973,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   974,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   980,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   989,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   990,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   991,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1023,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1025,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1026,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1027,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1031,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1267,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1458,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1475,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1499,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1696,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1764,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435
};

static const yytype_int16 yycheck[] =
{
       3,   248,   376,     7,   378,     4,   506,   507,     4,     6,
       3,     6,     6,     4,     6,   389,     6,     4,  1022,     5,
       5,     4,     4,  1365,     5,     5,     4,     6,     4,     4,
     197,     5,   199,     4,     6,     4,   263,     5,     5,   109,
       5,     4,     6,   200,     4,     4,   203,     5,   275,     5,
       4,     6,   187,   188,    57,     6,     6,     4,     7,     6,
     187,   188,    65,     6,   187,   188,     4,    70,   203,     6,
    1018,     4,   193,   194,   197,   187,   188,   204,    81,   187,
     188,   204,     6,   204,   187,   188,     0,    99,     7,    81,
      82,   203,     7,   205,   201,   203,  1438,   205,   110,   206,
     203,   328,   205,   330,   140,   407,   118,   119,   120,   187,
     188,   197,   124,   125,   126,   127,   198,   419,   204,   155,
     156,   203,   187,   188,   198,     3,   200,   205,     6,    76,
     204,     7,     6,   128,   130,   131,   132,   133,     7,   204,
      13,    49,    50,    76,    52,   187,   188,    80,   197,   128,
     193,   194,    82,   193,   194,   204,   128,   143,   143,    92,
     197,   204,   204,   143,   204,   103,   104,   105,   106,   143,
     174,   175,   176,   177,   112,   151,   154,   115,   181,    57,
     140,   141,   173,  1525,   197,   128,   140,   141,   185,   182,
     193,   194,    70,   187,   188,   185,   198,   173,   201,  1541,
     199,   203,   173,    81,   193,   194,   209,   206,   211,   205,
     197,   199,   199,   216,   201,   197,   208,   220,   204,   206,
     223,   204,   204,   204,   227,   228,   229,   230,   204,   204,
     233,   234,   235,   204,   197,   204,   204,   204,   197,   204,
     204,   204,   193,   194,   247,   248,   204,   197,   204,   204,
     187,   188,   201,  1201,   204,   174,   175,   176,   177,   174,
     175,   176,   177,   187,   188,   197,   269,   270,   271,   197,
     497,   498,   204,     6,   193,   194,   187,   188,   193,   194,
     283,   284,   201,   203,    79,   205,     8,    82,   187,   188,
     517,    76,   203,   296,    79,   298,   598,    82,   174,   175,
     176,   177,   197,   181,   203,   174,   175,   176,   177,   204,
       7,    79,   187,   188,    82,   193,   194,   193,   194,   187,
     188,   193,   194,   201,   193,   194,   187,   188,   203,   201,
     333,   209,   335,   336,    82,   203,    84,   407,     6,   340,
     187,   188,   203,   251,   252,   348,   187,   188,     6,   341,
     577,   259,   654,   655,     6,   263,   203,  1699,   197,   197,
     199,   199,   203,   590,   189,   190,   191,   206,   206,   200,
     248,   196,   203,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   333,   386,   387,   388,   389,   390,   187,   188,
       6,   394,   395,   396,   397,   398,   399,     6,   401,     7,
     392,   199,   187,   188,   203,   187,   188,   197,   400,   187,
     188,   197,   197,   199,   203,   418,   205,     6,     7,   204,
     206,   203,   187,   188,   197,   203,   377,   197,   379,   380,
     381,   197,   383,   384,    82,   386,   387,   388,   203,   390,
     203,   197,   205,   394,   395,   396,   397,   398,  1790,    79,
     187,   188,    82,   456,    84,   333,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     187,   188,     6,     7,   196,   187,   188,   174,   175,   176,
     177,    76,   197,   205,    79,   198,   203,    82,   491,   492,
     203,   203,   484,   485,   486,   487,   193,   194,   376,   377,
     378,   379,   380,   381,    86,   383,   384,    82,   386,   387,
     388,   389,   390,   506,   507,   204,   394,   395,   396,   397,
     398,   399,   198,   401,   200,   187,   188,    82,   204,   756,
     533,   534,   535,    79,    99,   605,    82,     6,    84,   841,
     842,   203,   545,   544,   199,   110,   201,   203,  1552,   205,
    1554,   206,  1556,   118,   119,   120,   559,    82,    84,   124,
     125,   126,   127,   566,   203,   203,   205,   205,   197,   570,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   654,   655,     8,    79,   196,   187,
     188,   189,   190,   191,   597,    82,   504,   505,   196,   204,
     187,   188,   204,    79,   512,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   203,   618,   619,   620,
     621,   622,   623,   624,   198,    99,   200,   628,   629,   630,
     204,   187,   188,   203,    79,   205,   110,   638,   639,   640,
     205,   642,    82,     4,   118,   119,   120,   203,   649,   650,
     124,   125,   126,   127,   198,     4,   228,   229,   230,   203,
     661,   233,   234,   235,   656,     4,   913,   545,   671,   197,
    1618,   187,   188,  1621,   187,   188,  1624,     4,  1682,   981,
     198,   983,   200,   985,   199,   987,   204,   203,   187,   188,
     203,   694,   197,   696,   187,   188,   699,   269,   270,   702,
     197,   704,   187,   188,   203,   708,   709,   198,   197,   200,
     203,   283,   284,   197,   706,   199,   197,   201,   203,   197,
     204,   199,   206,   201,   203,   197,   205,   797,   206,   732,
      76,   205,     6,    79,    76,     6,    82,    79,    84,  1743,
      82,  1745,    84,  1747,   199,   103,   104,   198,   699,  1753,
     753,   109,   203,   704,   197,   197,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     197,   841,   842,   198,   196,   200,  1724,   197,   203,   849,
     850,   103,   104,   205,   198,   197,   200,   109,   198,   203,
     200,   197,  1796,   203,  1798,   798,  1800,   198,  1100,   200,
     198,     7,   203,     8,   807,   203,   809,   198,   811,   200,
     813,   198,   203,   200,  1116,   818,   203,   203,   821,   205,
     197,   699,  1770,   197,   702,  1773,   704,   197,  1776,    99,
     198,  1779,   200,   198,   197,   203,   839,   203,   203,   205,
     110,   197,   845,  1343,  1344,   199,     6,   850,   118,   119,
     120,   759,   204,   204,   124,   125,   126,   127,   766,   203,
    1107,   205,    99,     6,   772,   935,   936,  1815,   203,  1817,
     205,  1819,   875,   110,   203,     4,   205,   880,   881,   882,
     883,   118,   119,   120,   203,   197,   205,   124,   125,   126,
     127,   894,   884,   896,    82,    82,    84,    84,   203,   850,
     205,   203,   203,   205,   205,   203,   203,   205,   205,   203,
     913,   205,   197,   916,   917,   918,   919,   203,   197,   205,
     921,   203,   203,   205,   205,   203,   203,   205,   205,   880,
     197,   882,   883,   197,   203,   205,   205,   203,   941,   205,
     203,   197,   205,   894,  1246,   896,   203,     4,   205,     6,
     204,   952,   953,   197,   197,   958,   959,   203,   961,   205,
     963,   964,   197,   197,   967,   968,   197,   197,   205,   972,
    1040,   197,   850,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    99,   204,   204,
     941,   196,   203,   198,   205,   203,   199,   205,   110,   203,
     197,   205,   880,   204,   882,   883,   118,   119,   120,   203,
     206,   205,   124,   125,   126,   127,   894,   203,   896,   205,
     203,     6,   205,    99,   203,   203,   205,   205,   204,   203,
    1100,   205,   204,  1280,   110,   913,   203,   203,   205,   205,
     204,    99,   118,   119,   120,   197,   954,  1547,   124,   125,
     126,   127,   110,  1056,  1057,  1058,   203,   203,   205,   205,
     118,   119,   120,   941,  1067,   197,   124,   125,   126,   127,
       4,     5,   197,   203,  1075,   205,   203,   203,   205,   205,
       6,  1082,  1083,  1084,  1085,  1086,   203,   203,   205,   205,
     204,  1092,  1093,   205,   204,  1096,  1097,   204,  1006,  1007,
    1008,   203,   199,   205,  1107,   199,    40,    41,    42,    43,
      44,    45,   203,   199,   205,    49,    50,    51,    52,  1122,
     203,   199,   205,    57,    58,    59,     6,     6,    62,   205,
     203,   203,   205,   205,   204,   143,  1510,     6,  1141,    73,
     206,  1133,     6,     6,  1147,     6,     6,   205,   204,     6,
    1153,   199,  1155,  1156,     4,   196,   201,  1160,  1161,     7,
    1163,   204,  1165,   205,  1167,   203,  1169,  1170,  1171,    99,
     183,   184,   185,   186,   187,   188,   189,   190,   191,  1249,
     110,    99,   203,   196,  1187,     7,     6,     6,   118,   119,
     120,     6,   110,    99,   124,   125,   126,   127,     7,  1202,
     118,   119,   120,  1206,   110,  1208,   124,   125,   126,   127,
       7,   198,   118,   119,   120,     6,   204,  1218,   124,   125,
     126,   127,     7,     6,   158,   159,   160,     7,  1229,  1107,
       6,     6,     6,     4,   204,   140,   170,    54,   172,   173,
      54,    54,    54,   200,   198,     6,     6,   198,     6,   198,
     203,   203,     6,  1256,   198,   203,   203,   203,   203,   193,
     194,   198,   198,     4,     4,   200,   143,   201,  1260,  1516,
       6,     6,     6,     6,     4,   205,     7,  1280,     7,     7,
    1272,     7,     7,  1286,   143,     7,     7,   205,   143,     7,
     204,     6,  1200,  1296,   198,   203,  1299,   198,   198,   205,
     203,   203,   198,  1373,   203,  1256,     6,  1299,   201,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   205,   205,     6,   200,   196,   204,   204,
       7,   204,  1335,  1336,  1561,     7,   204,     7,   204,   201,
       6,     6,     6,     6,     6,  1296,    99,  1339,     7,     6,
    1343,  1344,   199,   197,   197,   204,     6,   110,   185,     7,
    1363,     7,  1365,     7,  1367,   118,   119,   120,    84,     7,
       7,   124,   125,   126,   127,     7,     7,     6,  1256,  1382,
       7,     7,     7,     7,     7,     7,  1389,     4,     4,   197,
    1393,     6,     6,   204,  1397,  1396,  1388,     7,     6,  1307,
       7,     7,  1280,     7,   204,  1397,  1398,  1399,     6,     6,
       6,    82,     7,     6,  1417,     6,     4,     4,  1296,     4,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     6,  1438,   205,  1345,   196,  1347,
       6,  1349,     6,     6,     4,     6,   203,   198,   198,   198,
     198,   203,   205,     7,   201,  1363,  1683,   201,  1366,  1367,
     197,   204,     6,     6,    12,    13,     6,     6,     6,     6,
       6,  1474,   204,    92,     6,     6,  1479,   204,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   204,   204,   204,     5,   196,  1500,     4,    99,
     204,    12,    13,     6,  1507,   204,     7,  1510,   204,   204,
     110,   199,     6,  1516,     6,     6,     6,   204,   118,   119,
     120,   204,  1525,     4,   124,   125,   126,   127,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,  1541,    87,
       6,  1544,     6,   204,    92,    93,     6,    95,    96,    97,
     139,   203,     6,   101,  1547,     4,     6,  1560,     4,     6,
       4,     6,  1565,     6,     6,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     6,    87,     6,     6,     6,
       6,    92,    93,     6,    95,    96,    97,   135,   136,   137,
     101,    99,     5,   204,     6,    12,    13,     6,   143,     6,
       6,     6,   110,     6,  1607,   205,     6,     6,     6,     6,
     118,   119,   120,     6,     6,     6,   124,   125,   126,   127,
     203,     6,     6,  1626,   135,   136,   137,     6,   198,     6,
     201,     7,  1510,     6,     6,   204,     6,     5,  1516,    80,
       6,    88,   204,  1551,     6,  1553,   204,  1555,   205,   205,
       6,   204,   204,   204,  1646,  1563,     7,   205,  1566,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   204,
      87,     6,     6,   138,     6,    92,    93,   205,    95,    96,
      97,  1684,   141,  1686,   101,     6,     6,     6,     6,     6,
       6,     6,   204,     6,   205,     6,  1699,   205,  1606,     6,
       6,     6,  1610,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   204,   135,   136,
     137,   196,   204,   198,   204,   200,   204,     6,   175,   176,
     177,   178,   179,   205,     6,    99,   204,     6,     6,     6,
       6,     6,  1734,     6,     6,   192,     6,     6,   205,   196,
       6,  1659,  1755,   204,     6,  1663,   204,    12,    13,     6,
    1763,     6,     6,   210,   211,   212,   213,   204,   215,   216,
     217,   218,   204,   220,   221,   222,     6,     6,  1686,     6,
     227,     6,   204,   204,   204,   204,   204,  1790,   205,     6,
       6,     6,     6,     6,     6,     6,     6,     6,   245,     6,
       6,     6,     6,  1649,  1807,  1130,  1809,   254,   255,   452,
    1530,     3,  1763,  1531,  1140,     3,   263,  1543,  1276,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   482,    87,  1741,  1742,    -1,  1839,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,   296,
     297,   298,    -1,    -1,    -1,    -1,  1807,    -1,  1809,    -1,
      -1,   308,   309,   310,    -1,   312,    -1,    -1,    -1,   316,
     317,   318,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,    -1,  1763,    -1,    -1,  1839,    -1,
     337,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   351,   352,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,  1807,
      -1,  1809,    -1,    12,    13,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,   391,    -1,   393,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,  1839,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
      -1,   418,    -1,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,   456,
      -1,    -1,    -1,    92,    93,   462,    95,    96,    97,    -1,
     467,    -1,   101,    -1,    -1,   472,   473,    -1,    -1,    -1,
      -1,   478,   479,    -1,    -1,    -1,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
      -1,    -1,   509,   510,   511,   512,   513,   514,    -1,    21,
      22,   518,   519,   520,   521,   522,    -1,    -1,    -1,   526,
      -1,   528,   529,    -1,    -1,    -1,   533,   534,   535,    -1,
      -1,   538,   539,   540,   541,   542,    -1,    -1,    -1,    -1,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   559,     6,    -1,    -1,    -1,    -1,   565,   566,
      -1,   568,   569,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   589,    -1,    -1,   196,    -1,    -1,    -1,   596,
     597,    -1,    -1,    12,    13,   602,   108,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,   161,
     657,    -1,    -1,    -1,   166,   167,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,
      -1,    -1,   101,    -1,   691,    -1,    -1,   694,    -1,   696,
     697,    -1,    -1,    -1,    -1,    -1,    -1,     6,   705,    -1,
      -1,   708,   709,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   722,   135,   136,   137,   196,
      -1,    -1,    -1,    -1,   731,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   753,    -1,    -1,    -1,
      -1,    -1,    -1,   760,   761,    -1,    -1,    -1,    -1,   766,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,   779,    -1,    -1,   782,   288,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   798,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
     807,   247,   809,    -1,   811,    -1,   813,    -1,    -1,    -1,
      -1,   818,    -1,    -1,   821,    -1,    -1,    -1,    -1,    -1,
     827,    -1,   829,   830,    -1,   271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,   863,    -1,   101,    12,
      13,    -1,    -1,    -1,   871,   872,   873,    -1,   875,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   893,   196,    -1,   335,
     336,   898,   135,   136,   137,    -1,   903,    -1,   410,   906,
      -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,   916,
     917,   918,   919,    -1,    -1,    -1,   923,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,   382,    12,    13,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,   205,    -1,   196,   972,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   982,    -1,   984,    -1,   986,
      -1,   988,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    -1,    12,    13,    -1,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,  1039,    -1,    -1,    -1,  1043,    -1,  1045,  1046,
    1047,    -1,    -1,    -1,    -1,    -1,  1053,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,  1070,    -1,  1072,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,
      -1,  1108,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1120,  1121,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1132,  1133,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1177,  1178,  1179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1187,    -1,  1189,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,  1200,    87,    -1,    -1,    -1,    -1,    92,
      93,  1208,    95,    96,    97,    -1,  1213,   205,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   671,    -1,  1234,  1235,  1236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,     6,    -1,    -1,   211,
      -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,   227,  1273,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,    -1,    -1,    -1,    -1,  1292,   732,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1305,  1306,
      -1,     6,    -1,    -1,    -1,  1312,  1313,    -1,    -1,    -1,
    1317,    -1,   205,    -1,    -1,    -1,    -1,    -1,  1325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,  1336,
    1337,    -1,  1339,    -1,   296,    -1,   298,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,
    1367,    -1,    -1,  1370,    -1,    -1,    -1,    -1,  1375,  1376,
    1377,  1378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,  1388,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,
      -1,  1398,    -1,   839,    -1,    -1,   227,    -1,    -1,   845,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,  1416,
      -1,    -1,    -1,    -1,    -1,    -1,  1423,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,   881,   196,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,  1459,    -1,    -1,   196,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1477,    -1,  1479,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,  1495,    -1,
    1497,   196,    -1,  1500,   456,    -1,    -1,    -1,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   958,   959,  1521,   961,    -1,   963,   964,  1526,
      -1,   967,   968,    -1,    -1,    -1,    -1,    -1,    -1,   491,
     492,    -1,    -1,    -1,    -1,    -1,    -1,  1544,    -1,    -1,
      -1,    -1,    -1,    -1,  1551,    -1,  1553,    -1,  1555,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1565,    -1,
      -1,    -1,  1569,  1570,  1571,  1572,  1573,    -1,    -1,    -1,
      -1,   533,   534,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,  1589,    -1,    -1,    -1,  1593,   418,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,  1603,   559,    -1,    -1,
      -1,    -1,    -1,    -1,   566,    -1,    -1,  1614,    -1,    -1,
    1056,  1057,  1058,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1067,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,  1644,    -1,    -1,
      -1,    -1,  1649,    -1,    -1,    -1,    -1,     6,    -1,  1656,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     491,   492,    -1,  1670,    -1,    -1,  1673,    -1,    -1,  1676,
      -1,    -1,    -1,  1680,    -1,    -1,  1122,  1684,    -1,  1686,
    1687,  1688,  1689,  1690,    -1,    -1,    -1,    -1,    -1,    -1,
    1697,    -1,    -1,  1700,    -1,  1141,    -1,    -1,    -1,    -1,
      -1,  1147,   533,   534,   535,    -1,    -1,  1153,    -1,  1155,
    1156,    -1,    -1,    -1,  1160,  1161,    -1,  1163,    -1,  1165,
      -1,  1167,    -1,  1169,  1170,  1171,    -1,    -1,   559,    -1,
      -1,    -1,   694,  1740,   696,    -1,    -1,    -1,    -1,    -1,
      -1,  1187,    -1,    -1,    -1,    -1,   708,   709,  1755,    -1,
    1757,  1758,  1759,  1760,    -1,    -1,  1202,    -1,    -1,    -1,
    1206,    -1,    -1,    -1,    -1,    -1,   597,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,  1793,  1794,    -1,    -1,
      -1,   753,    -1,    -1,    -1,    -1,  1803,  1804,  1805,  1806,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,   798,   196,    -1,    -1,
    1286,    -1,    -1,    -1,    -1,   807,    -1,   809,    -1,   811,
      -1,   813,    -1,  1299,    -1,    -1,   818,    -1,    -1,   821,
      -1,    -1,    -1,   694,    -1,   696,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   875,    46,    47,    48,    -1,    -1,  1365,
      -1,    53,   753,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,  1382,    -1,    -1,    -1,
      72,    -1,    -1,  1389,    -1,    -1,    -1,  1393,    -1,    -1,
      -1,  1397,    -1,    -1,   916,   917,   918,   919,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   798,    -1,    -1,
      -1,  1417,    -1,    -1,    -1,    -1,   807,    -1,   809,    -1,
     811,    -1,   813,    -1,    -1,    -1,    -1,   818,    -1,    -1,
     821,    -1,  1438,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,     6,
     972,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,    -1,    -1,    -1,   157,    -1,    -1,  1474,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,   875,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,  1525,
      -1,    -1,    -1,    -1,    -1,   916,   917,   918,   919,    -1,
      -1,    -1,    -1,    -1,    -1,  1541,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,  1560,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     6,
      -1,   972,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,  1607,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
    1626,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     3,     4,     5,    -1,   196,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,  1208,    -1,    -1,    57,
      58,    59,    -1,  1699,    62,    -1,    64,    65,    66,   157,
      -1,    -1,    -1,   161,    72,    73,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,  1790,    -1,    -1,     6,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1335,  1336,    -1,    -1,  1208,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,   201,   202,    -1,   204,    -1,   206,    -1,
      -1,  1363,    -1,    -1,    -1,  1367,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,  1335,  1336,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,  1479,   115,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,  1500,    -1,
      -1,    -1,    -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,     6,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,    -1,  1565,    -1,   202,    -1,   204,   205,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,  1500,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,  1544,   103,   104,   105,   106,   107,    -1,
      -1,    -1,  1684,   112,  1686,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1565,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1755,     8,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,   202,     8,    -1,   205,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,  1684,    -1,  1686,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,  1755,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     8,    -1,
      -1,    -1,   196,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,     3,     4,     5,   202,    -1,   204,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,     3,     4,     5,
      -1,    72,    73,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
       8,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,     8,
      -1,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,     5,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    12,    13,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,    -1,   172,   173,    -1,    -1,    -1,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,
       4,     5,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,
      84,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,   158,   159,   160,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,   158,   159,   160,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,     4,     5,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,    -1,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,   170,    -1,   172,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,     5,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,    -1,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   158,   159,
     160,    99,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
     170,    -1,   172,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,   157,   196,    -1,
      -1,   161,   200,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,     3,     4,    -1,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,     5,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     205,    -1,    -1,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,     3,     4,    -1,    -1,   197,    -1,     9,    10,    11,
     202,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,     3,     4,    -1,    -1,   197,    -1,     9,    10,    11,
     202,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    54,    55,    56,   197,    -1,    -1,    60,    61,
     202,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,     4,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      12,    13,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    38,    39,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,   173,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,   173,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   208,   209,     6,     0,     4,    12,    13,    38,
      39,    54,    55,    56,    60,    61,    63,    67,    68,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   110,   111,   112,   113,   114,   115,
     116,   117,   121,   122,   123,   129,   134,   135,   136,   137,
     140,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   162,   163,   164,   171,   173,
     210,   212,   213,   233,   250,   251,   254,   255,   256,   257,
     258,   259,   260,   261,   282,   283,   284,   285,   303,   304,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    57,    58,    59,    62,    64,    65,    66,
      72,    73,   151,   157,   158,   159,   160,   161,   165,   166,
     167,   168,   169,   170,   172,   187,   188,   192,   197,   199,
     201,   202,   204,   206,   231,   286,   287,   299,   300,   303,
     304,    13,    82,   197,   197,     6,   204,     6,     6,     6,
       6,   197,     6,     6,   199,   199,   197,   199,   231,   231,
     197,   204,   197,   197,     4,   197,   204,   197,   197,     4,
     204,   197,   197,    86,    82,    82,     6,   204,    76,    79,
      82,    82,    82,    79,    82,    84,    84,    76,    79,    82,
      84,    79,    82,    84,    79,    82,   197,    79,   140,   155,
     156,   204,   187,   188,   197,   204,   289,   290,   289,   204,
      76,    79,    82,   204,   289,     4,    76,    80,    92,    82,
      84,    82,    79,     4,   151,   204,   303,   304,     4,     6,
      76,    79,    82,    79,    82,     4,     4,     4,     4,     5,
      37,    76,    79,    82,    84,    96,   188,   197,   204,   251,
     261,   286,   292,   293,   294,   303,   304,     4,   197,   197,
     197,     4,   204,   296,   304,     4,   197,   197,   197,     6,
       6,   199,     4,   300,   304,     4,   300,     5,   204,     5,
     204,     4,   286,   199,     6,   197,   204,   197,   199,   206,
     231,     7,   174,   175,   176,   177,   193,   194,   229,   230,
       4,   197,   199,   201,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   197,
     197,   197,   197,   197,   197,   231,   231,   231,   231,   197,
     231,   231,   231,     7,   197,   197,   197,   231,   231,   197,
     197,   199,   286,   286,   286,   286,   286,     4,   140,   141,
     304,     4,   251,   252,   253,   204,   198,   200,   204,   232,
       6,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   196,   204,     6,   197,   199,
     230,     6,   286,     4,   299,   300,   304,   299,   286,   299,
     302,   235,   238,   300,   304,   286,   188,   286,   294,   295,
     286,   286,   197,   286,   295,   286,   286,   197,   295,   286,
     286,   292,   197,   204,   295,   293,   293,   293,   197,   197,
     293,   293,   293,   197,   197,   197,   197,   197,   197,   197,
     197,   204,   204,   286,     4,   292,   296,   204,   204,   289,
     289,   289,   286,   286,   187,   188,   204,   204,   289,   204,
     204,   204,   187,   188,   197,   253,   289,   204,   197,   204,
     197,   197,   197,   293,   293,   292,   197,     4,   199,   199,
     253,     6,     6,   204,   204,   204,   293,   293,   199,   199,
     199,   197,   199,   201,   231,   199,     5,   143,   204,     5,
     143,     5,   143,     5,   143,    76,    79,    82,    84,   204,
     286,   294,   286,   205,   295,     8,   189,     6,   197,   199,
     231,     6,   286,   286,   286,   201,   286,   204,   143,   286,
     286,   286,   286,     6,     6,     6,   253,     6,   253,   199,
     204,   299,   292,   292,   286,   286,   204,   204,   232,   300,
     292,     6,   199,   286,   286,     4,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   302,   299,
     302,   299,   299,   299,   292,   299,   299,   286,   299,   299,
     299,   302,   299,   286,   300,   286,   299,   299,   299,   299,
     299,   304,   300,   304,   198,   200,     7,   229,   230,   201,
       7,   231,   205,    76,    79,    82,    84,   250,   286,   295,
       7,   229,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   214,   286,   286,
       6,   199,   201,   198,   203,   198,   203,   203,   198,   203,
     200,   203,   234,   200,   234,   203,   203,   198,   189,   203,
     205,   198,   198,   286,   198,   205,   198,   198,   286,   205,
     198,   198,     7,   286,   286,   205,     6,     6,     6,   286,
     286,     7,     7,   279,   279,   286,   244,   286,   300,   245,
     286,   300,   246,   286,   300,   247,   286,   300,   286,   286,
     286,   295,   295,   204,   198,     6,   204,   253,   253,   203,
     203,   203,   289,   289,   252,   252,   203,   286,   286,   286,
     286,   265,   203,   253,   286,   286,   286,   286,   286,     7,
     280,     6,     7,   286,     6,   286,   286,   205,   295,   295,
     295,     6,     6,   286,   286,   286,   286,     4,   204,   232,
     304,    54,   286,    54,    54,    54,     5,   204,     5,   204,
       5,   204,     5,   204,   295,   198,   205,   286,   204,   286,
     294,   204,   232,   198,   198,   198,   140,   203,   253,   204,
       8,   198,   198,   200,   205,   205,   253,   200,   198,   203,
     205,   198,   200,   286,   295,   229,     6,     6,   286,   198,
     200,   230,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   203,   232,   232,   232,   232,   232,   232,
     232,   203,   203,   203,   232,   203,   232,   232,   198,   198,
     203,   203,   203,   203,   203,   232,   232,   232,   198,   232,
     288,   301,     6,   203,   203,   198,   203,   232,   203,   232,
     198,   198,   200,   229,   230,   201,   229,   230,   300,   286,
       6,     4,     4,   204,   297,   232,   204,   204,   204,   204,
     205,   205,   292,     8,     4,   130,   131,   132,   133,   205,
     217,   221,   224,   226,   227,   198,   200,   286,     4,     6,
     185,   211,   295,     6,   295,   286,     6,   299,     6,   304,
       6,   299,   286,   300,     7,   286,   294,   143,     7,     7,
     198,     7,   143,     7,     7,   198,   143,     7,     7,   286,
     198,   205,   204,   198,   198,   286,   292,     4,   278,     6,
     198,   198,   203,   198,   203,   198,   203,   198,   203,   198,
     198,   198,   205,   205,   295,   201,   253,   205,   205,   289,
     286,   286,   205,   205,   286,   289,   203,   203,   203,    99,
     110,   118,   119,   120,   124,   125,   126,   127,   275,   276,
     289,   205,   262,   198,   205,   198,   198,   198,   286,     6,
     286,   198,   200,   200,   205,   205,   205,   200,   200,   203,
     200,   295,   200,   204,   205,   204,   204,   204,   295,   295,
     295,   295,   205,     8,   295,   295,     7,     7,     7,   201,
     286,   205,   286,   286,     7,   201,   205,   204,   292,     6,
     229,   230,   229,   230,   205,   205,   292,   200,   230,   201,
     230,   299,   286,   286,   286,   286,   295,   299,   292,   299,
     299,   300,   240,   242,   286,   299,   299,   286,   286,     6,
       4,   140,   141,   286,     6,     6,     6,     7,   199,   296,
     298,     6,   295,   295,   295,   295,   232,     6,   286,   218,
     197,   197,   204,   228,     6,   230,   230,   200,   185,   299,
     198,   198,   203,     7,   232,   232,   289,    82,    84,   292,
     292,     7,   292,    82,    84,   292,   292,     7,    84,   292,
     292,     6,     7,     7,   295,     7,     7,    99,   277,     6,
       7,   229,   286,   229,   286,   229,   286,   229,   286,     7,
       7,     7,     7,     7,   205,     4,   205,   203,   203,   203,
     205,   205,   289,   289,   289,     4,     6,   204,     6,   197,
       6,   128,     6,   128,     6,   128,     6,   128,   205,   276,
     203,   275,     7,     6,     7,     7,     7,     6,   204,     6,
       6,     6,    82,     7,     6,     6,   286,   201,   205,   286,
     286,   286,   286,   205,   205,   205,   205,   286,   205,   205,
     292,   292,   292,     4,   203,     8,     8,   198,     4,     4,
     292,   205,   286,     6,   286,     6,   232,     6,     6,     4,
       6,   232,   232,   232,   232,   232,   203,   198,   198,   198,
     203,   203,   232,   241,   203,   232,   243,   198,   198,   232,
     232,     6,     7,   229,   230,   201,     7,     6,   296,   286,
     203,   205,   205,   205,   205,   205,   229,   197,   286,   286,
     291,   292,   204,   201,     6,     6,   211,     6,   286,   204,
     286,   300,     6,     6,     6,   204,   204,    92,   249,   249,
     292,     6,   204,   204,     6,     6,   292,   204,     6,     6,
       5,   292,   205,   292,   292,     4,     6,   292,   292,   292,
     292,   292,   292,   292,   292,   204,   204,     7,     6,     7,
     286,   286,   286,   204,   204,   203,   205,   203,   205,   203,
     205,   199,   286,   292,   286,     6,     6,     6,     6,   286,
     289,   205,     5,   204,   292,   204,   204,   204,   292,   295,
     204,   286,   200,     4,   232,   203,   203,   203,   203,   232,
       6,     6,   139,   286,   286,   286,     6,     6,     7,   203,
       6,     6,     6,   229,   230,   299,   300,     4,     4,   154,
     300,   286,     6,     4,   297,     6,   200,   296,     6,     6,
       6,     6,   292,   215,   286,   203,   203,   203,   205,   216,
     286,     4,   299,   203,   292,   300,   286,   286,   289,     6,
       6,     6,   286,   286,     6,   286,     5,     6,   204,     6,
     143,   248,   286,     6,     6,     6,     6,     6,     6,     4,
       6,     6,   295,   295,   286,   286,   300,   205,   198,   203,
     205,   252,   252,   289,     6,   266,   289,     6,   267,   289,
       6,   268,   286,   205,   203,   198,   205,   203,     6,   188,
     289,     6,   291,   289,   289,     6,   205,   286,     6,     6,
     286,   286,   286,   286,   292,   203,   205,     8,   205,   198,
     204,   286,   300,   292,   292,   198,   232,   204,   292,   300,
     204,   286,   300,   300,     6,     6,     7,     6,   201,     6,
     198,   203,   286,   286,   292,   204,   203,   205,     6,   286,
     236,   237,   205,   205,   205,   205,   205,     5,   291,    80,
       6,   204,   205,   205,   204,     6,     6,   204,   286,   205,
     205,   203,   204,   203,   204,   203,   204,   200,     6,   292,
       7,   204,   286,   203,   205,   203,   203,     6,   205,   203,
     203,   203,   203,   138,   286,   286,   295,     6,     6,   205,
       6,   239,   286,   302,   296,   141,   219,   286,   203,   203,
     291,   286,     6,   203,   240,   242,     6,     6,     6,     6,
       6,     6,   205,   204,   291,   103,   104,   109,   281,   103,
     104,   281,   295,   252,   203,   205,   286,   289,   275,   286,
     289,   275,   286,   289,   275,     6,   203,   205,   292,   253,
     205,   289,     6,   295,   289,   286,   286,   286,   286,   286,
     205,   205,   205,     6,   203,   205,     7,   205,     6,   204,
     286,   286,   205,   286,   205,   205,   204,   286,   205,   204,
     289,   292,     6,   204,   289,     6,   205,   205,   286,   205,
     203,   205,   205,   203,   205,   205,   203,   205,   292,     6,
      99,   205,   263,   204,   203,   205,   203,   203,   203,   203,
     203,     6,     6,   286,   300,   216,   198,   203,     6,   204,
     203,   286,   205,     6,   289,     6,   289,     6,     6,   205,
       6,   269,   286,     6,     6,   270,   286,     6,     6,   271,
     286,     6,   205,   286,   275,   253,   295,     6,   289,   295,
     286,   286,   286,   286,     7,   205,   222,   286,   291,   286,
     203,   203,   203,   204,   205,   204,   205,   204,   205,     6,
       6,   205,   205,   264,   205,   203,   205,   203,   203,   203,
     203,   300,     6,   204,   198,   205,   205,   286,   289,   289,
     275,     6,   272,   275,     6,   273,   275,     6,   274,   275,
       6,   295,     6,   286,   286,   286,   286,   220,   299,   225,
     204,     6,   205,   203,   203,   205,   204,   205,   204,   205,
     204,   205,   205,   203,   203,   203,   203,   203,   205,   204,
     291,     6,   286,   286,     6,   275,     6,   275,     6,   275,
       6,   286,   286,   286,   286,   299,     6,   223,   299,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   203,
     205,     6,     6,     6,     6,     6,     6,   299,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   207,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   212,   212,   212,   212,   212,   212,
     213,   213,   213,   213,   214,   214,   214,   214,   214,   214,
     215,   215,   216,   216,   218,   219,   217,   220,   220,   222,
     221,   223,   223,   225,   224,   226,   226,   228,   227,   229,
     229,   229,   229,   229,   230,   230,   231,   231,   232,   232,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   236,   235,   235,   237,   235,   238,   238,   239,
     239,   240,   240,   241,   241,   241,   242,   242,   243,   243,
     243,   243,   244,   244,   244,   245,   245,   245,   246,   246,
     246,   247,   247,   247,   248,   248,   249,   249,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   251,   251,   251,
     251,   251,   251,   251,   251,   252,   252,   253,   253,   253,
     253,   253,   253,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   255,   255,   255,   255,   256,   256,   257,
     258,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   261,   262,   261,   263,   261,   264,   261,   265,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   266,
     261,   267,   261,   268,   261,   269,   261,   270,   261,   271,
     261,   272,   261,   273,   261,   274,   261,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   277,   277,   278,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   283,   284,   284,   284,   285,   285,   285,   285,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   288,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   289,
     289,   289,   289,   289,   290,   290,   290,   290,   291,   291,
     292,   292,   292,   292,   292,   292,   293,   293,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   295,   295,   295,   295,
     296,   296,   296,   296,   297,   297,   298,   298,   299,   299,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   301,   300,   302,   302,   303,   303,
     304,   304,   304
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       3,     5,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     0,     5,     0,     2,     7,     8,
       6,     7,     4,     7,     8,     8,     7,     7,    11,     8,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     8,
       8,    12,     8,     8,     7,     8,     8,     5,    11,     5,
       9,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       6,     6,     6,     8,    10,    14,    16,    12,     8,     8,
       6,    14,     4,     6,     6,     3,     4,     5,     6,     5,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       8,     8,     8,    12,    12,    12,    14,    14,    14,     0,
      12,     0,    12,     0,    12,     0,    16,     0,    16,     0,
      16,     0,    18,     0,    18,     0,    18,     1,     2,     5,
       7,     9,     2,     2,     2,     3,     2,     3,     2,     3,
       2,     3,     9,     6,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     7,     6,     8,     5,     3,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,    10,    10,    10,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     4,     6,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     5,     5,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     4,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       4,     6,     4,     1,     0,     6,     1,     3,     5,     5,
       1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 198 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4490 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 250 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      FILE *fp = Fopen(tmp.c_str(), (yyvsp[-2].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[-4].c));
	fclose(fp);
      }
      Free((yyvsp[-4].c));
      Free((yyvsp[-1].c));
    }
#line 4596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 264 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 4613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 277 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 4630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 290 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[-6].c), (yyvsp[-4].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	FILE *fp = Fopen(tmp.c_str(), (yyvsp[-2].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[-4].l));
    }
#line 4657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-5].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[-4].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    }
#line 4675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[-4].c));
    }
#line 4692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 345 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[-4].c));
    }
#line 4709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 358 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-6].c), "View")){
	int index = (int)(yyvsp[-4].d), index2 = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free((yyvsp[-6].c));
    }
#line 4728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 390 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 397 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4756 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 399 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 404 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strncmp((yyvsp[0].c), "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp((yyvsp[0].c), "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp((yyvsp[0].c), "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp((yyvsp[0].c), "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[0].c), "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[0].c), "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", (yyvsp[0].c));
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free((yyvsp[0].c));
    }
#line 4870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 508 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 4884 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 518 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 527 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 534 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 544 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 4929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 553 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 562 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 579 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 4973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 587 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 597 "Gmsh.y" /* yacc.c:1646  */
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
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[-5].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-2].l)));
#endif
    }
#line 5003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 616 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[-11].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-8].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-5].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-2].l)));
#endif
    }
#line 5023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 641 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5046 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 678 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 684 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yysymbols.count((yyvsp[-3].c)) && (yyvsp[-2].i) && List_Nbr((yyvsp[-1].l)) == 1){
        yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if(!(yyvsp[-2].i)) s.list = (List_Nbr((yyvsp[-1].l)) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr((yyvsp[-1].l)) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", (yyvsp[-3].c));
          }
          else{
            double d;
            List_Read((yyvsp[-1].l), 0, &d);
            if(s.value.empty()){
              if((yyvsp[-2].i)) yymsg(1, "Uninitialized variable '%s'", (yyvsp[-3].c));
              s.value.resize(1, 0.);
            }
            switch((yyvsp[-2].i)){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[-3].c), d);
              break;
            }
          }
        }
        else{ // list of expressions
          switch((yyvsp[-2].i)){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
              double d;
              List_Read((yyvsp[-1].l), i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
              double d;
              List_Read((yyvsp[-1].l), i, &d);
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
      Free((yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 744 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
      s.list = true;
      double d;
      switch((yyvsp[-2].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 773 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
      s.list = true;
      double d;
      switch((yyvsp[-2].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5255 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 802 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 807 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 812 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 817 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 822 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 829 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 836 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[-2].c));
        else if(!s.list)
          s.value[0] += (yyvsp[-1].i);
        else
          yymsg(0, "Variable '%s' is a list", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    }
#line 5332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 851 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5341 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 856 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 861 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 866 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 871 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 880 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 886 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 895 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-5].c), 0, (yyvsp[-3].c), d)){
	switch((yyvsp[-2].i)){
	case 0 : d = (yyvsp[-1].d); break;
	case 1 : d += (yyvsp[-1].d); break;
	case 2 : d -= (yyvsp[-1].d); break;
	case 3 : d *= (yyvsp[-1].d); break;
	case 4 :
	  if((yyvsp[-1].d)) d /= (yyvsp[-1].d);
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", (yyvsp[-5].c), (yyvsp[-3].c), (yyvsp[-1].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), d);
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c));
    }
#line 5420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 913 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), d)){
	switch((yyvsp[-2].i)){
	case 0 : d = (yyvsp[-1].d); break;
	case 1 : d += (yyvsp[-1].d); break;
	case 2 : d -= (yyvsp[-1].d); break;
	case 3 : d *= (yyvsp[-1].d); break;
	case 4 :
	  if((yyvsp[-1].d)) d /= (yyvsp[-1].d);
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), (yyvsp[-1].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), d);
      }
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c));
    }
#line 5442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 931 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 940 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5468 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 952 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 957 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 965 "Gmsh.y" /* yacc.c:1646  */
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 985 "Gmsh.y" /* yacc.c:1646  */
    {
      GmshColorTable *ct = GetColorTable((int)(yyvsp[-6].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[-6].d));
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[-6].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5534 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1008 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[-4].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[-1].d));
      else if(!strcmp((yyvsp[-4].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[-1].d));
      else
	yymsg(0, "Unknown command %s Field", (yyvsp[-4].c));
#endif
    }
#line 5549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1019 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 5561 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1027 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option){
	  try { option->numericalValue((yyvsp[-1].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-6].d));
#endif
      Free((yyvsp[-3].c));
    }
#line 5587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1049 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option){
	  try { option->string((yyvsp[-1].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-6].d));
#endif
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1072 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-8].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-5].c)];
	if(option){
	  std::list<int> vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	    double id;
	    List_Read((yyvsp[-2].l), i, &id);
	    vl.push_back((int)id);
	  }
          option->list(vl);
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-5].c), (int)(yyvsp[-8].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-8].d));
#endif
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1098 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-4].d));
      if(field){
        FieldCallback *callback = field->callbacks[(yyvsp[-1].c)];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              (yyvsp[-1].c), (int)(yyvsp[-4].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-4].d));
#endif
      Free((yyvsp[-1].c));
    }
#line 5666 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1119 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].d));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c));
    }
#line 5682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1131 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].c));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1149 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 5711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1158 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 5724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1167 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1169 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].l));
    }
#line 5750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1185 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 5763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1194 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1196 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 5783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1210 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1218 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1224 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1236 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        double v;
        List_Read((yyvsp[0].l), i, &v);
        floatOptions[key].push_back(v);
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 5827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1247 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-3].c));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[-1].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[-3].c));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[-1].l), i))->s);
      List_Delete((yyvsp[-1].l));
    }
#line 5845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1262 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1278 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1286 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1295 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1303 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-3].c));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        char *s;
        List_Read((yyvsp[-1].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
    }
#line 5908 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1321 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5935 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1343 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1349 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5962 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1357 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1361 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5980 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5989 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1375 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1379 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6007 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1385 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6016 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1393 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1397 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1409 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6046 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1413 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6054 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1423 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
      }
      else{
	double x = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[0];
	double y = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[1];
	double z = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[2];
	double lc = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[3];
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
#line 6081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1446 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
#line 6125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1486 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	Vertex *v = FindPoint((int)d);
	if(v){
	  v->lc = (yyvsp[-1].d);
        }
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv)
	    gv->setPrescribedMeshSizeAtVertex((yyvsp[-1].d));
	}
      }
      List_Delete((yyvsp[-3].l));
      // dummy values
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1509 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    }
#line 6171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1527 "Gmsh.y" /* yacc.c:1646  */
    {
      for (int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	double dnum;
	List_Read((yyvsp[-1].l), i, &dnum);
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
#line 6196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1548 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    }
#line 6218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1566 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-5].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-2].l));
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[-1].v)[0] || (yyvsp[-1].v)[1] || (yyvsp[-1].v)[2]){
          c->Circle.n[0] = (yyvsp[-1].v)[0];
          c->Circle.n[1] = (yyvsp[-1].v)[1];
          c->Circle.n[2] = (yyvsp[-1].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[-1].v)[0] || (yyvsp[-1].v)[1] || (yyvsp[-1].v)[2]){
          rc->Circle.n[0] = (yyvsp[-1].v)[0];
          rc->Circle.n[1] = (yyvsp[-1].v)[1];
          rc->Circle.n[2] = (yyvsp[-1].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    }
#line 6252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1596 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-5].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-2].l));
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
        if((yyvsp[-1].v)[0] || (yyvsp[-1].v)[1] || (yyvsp[-1].v)[2]){
          c->Circle.n[0] = (yyvsp[-1].v)[0];
          c->Circle.n[1] = (yyvsp[-1].v)[1];
          c->Circle.n[2] = (yyvsp[-1].v)[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if((yyvsp[-1].v)[0] || (yyvsp[-1].v)[1] || (yyvsp[-1].v)[2]){
          rc->Circle.n[0] = (yyvsp[-1].v)[0];
          rc->Circle.n[1] = (yyvsp[-1].v)[1];
          rc->Circle.n[2] = (yyvsp[-1].v)[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    }
#line 6286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1626 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
#line 6308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1644 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    }
#line 6330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1663 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-8].d);
      if(List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1 != List_Nbr((yyvsp[-3].l))){
	yymsg(0, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)(yyvsp[-8].d), List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-5].l)), (int)(yyvsp[-1].d), List_Nbr((yyvsp[-5].l)) + (int)(yyvsp[-1].d) + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(0, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-5].l));
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)(yyvsp[-1].d), temp, (yyvsp[-3].l),
				  -1, -1, 0., 1.);
	  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    }
#line 6360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1689 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindEdgeLoop(num)){
	yymsg(0, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-6].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
#line 6382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1707 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
        Curve *c = Create_Curve(num, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
          c->compound.push_back((int)*(double*)List_Pointer((yyvsp[-1].l), i));
	End_Curve(c);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_COMPOUND;
      (yyval.s).Num = num;
    }
#line 6404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1725 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
#line 6448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1768 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
#line 6470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1786 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-5].d), type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read((yyvsp[-2].l), 0, &d);
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
	  List_T *temp = ListOfDouble2ListOfInt((yyvsp[-2].l));
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  s->InSphereCenter = (yyvsp[-1].l);
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = type;
      (yyval.s).Num = num;
    }
#line 6513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1825 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1831 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1837 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1844 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if (List_Nbr((yyvsp[-1].l)) != 2){
	yymsg(0, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[-1].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[-1].l), 0, &p1);
	List_Read((yyvsp[-1].l), 1, &p2);
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
#line 6573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1869 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if (List_Nbr((yyvsp[-1].l)) != 2){
	yymsg(0, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr((yyvsp[-1].l)));
      }
      else{
	double p1,p2;
	List_Read((yyvsp[-1].l), 0, &p1);
	List_Read((yyvsp[-1].l), 1, &p2);
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
#line 6602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1894 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-6].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    }
#line 6623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1911 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[-1].l), i));
	}
        // Added by Trevor Strickler
	setSurfaceGeneratrices(s, (List_T*) 0 );
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    }
#line 6646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1931 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-8].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
        Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[-5].l)); i++)
          s->compound.push_back((int)*(double*)List_Pointer((yyvsp[-5].l), i));
	for (int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          if(i > 3){
            yymsg(0, "Too many boundary specifiers in compound surface");
            break;
          }
	  List_T *l = *(List_T**)List_Pointer((yyvsp[-2].l), i);
          for (int j = 0; j < List_Nbr(l); j++){
            s->compoundBoundary[i].push_back((int)*(double*)List_Pointer(l, j));
	  }
	}
        // Added by Trevor Strickler
        setSurfaceGeneratrices(s, (List_T*) 0 );

	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete((yyvsp[-5].l));
      for (int i = 0; i < List_Nbr((yyvsp[-2].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[-2].l), i));
      List_Delete((yyvsp[-2].l));
      Free((yyvsp[-4].c));
      (yyval.s).Type = MSH_SURF_COMPOUND;
      (yyval.s).Num = num;
    }
#line 6683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1964 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
#line 6727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 2008 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 6749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 2026 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 6770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2043 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME_COMPOUND);
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
          v->compound.push_back((int)*(double*)List_Pointer((yyvsp[-1].l), i));
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME_COMPOUND;
      (yyval.s).Num = num;
    }
#line 6790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2059 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt((yyvsp[-1].l));
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
#line 6834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2104 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2109 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2114 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2119 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2124 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2129 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
      if(!strcmp((yyvsp[-3].c), "Duplicata")){
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          Shape TheShape;
          List_Read((yyvsp[-1].l), i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add((yyval.l), &TheShape);
        }
      }
      else if(!strcmp((yyvsp[-3].c), "Boundary")){
        BoundaryShapes((yyvsp[-1].l), (yyval.l), false);
      }
      else if(!strcmp((yyvsp[-3].c), "CombinedBoundary")){
        BoundaryShapes((yyvsp[-1].l), (yyval.l), true);
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", (yyvsp[-3].c));
      }
      Free((yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
    }
#line 6906 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2152 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2158 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 6928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2168 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2169 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2174 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2178 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2182 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
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
#line 6983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2205 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
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
#line 7010 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2228 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
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
#line 7037 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2251 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
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
#line 7064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2279 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[-1].l)) == 4){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[-1].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-4].d));
#endif
    }
#line 7089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2300 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      int t = (int)(yyvsp[-6].d);
      if(FindLevelSet(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	//Msg::Info("nb = %d \n",List_Nbr($8) );
	fullMatrix<double> centers(List_Nbr((yyvsp[-2].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[-2].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    //Msg::Info("nb j = %d \n",List_Nbr(l) );
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        LevelSet *l = Create_LevelSet(ls->getTag(), ls);
        Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[-2].l), i));
      List_Delete((yyvsp[-2].l));
#endif
    }
#line 7119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2327 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[-2].l)) == 0){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double n[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt, n, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-10].d));
#endif
    }
#line 7143 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2348 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[-2].l)) == 0){
        int t = (int)(yyvsp[-12].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt1[3] = {(yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2]};
          double pt2[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double pt3[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-12].d));
#endif
    }
#line 7168 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2369 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-8].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-8].d));
#endif
    }
#line 7192 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2389 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[-6].c), "Union")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Intersection")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Cut")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Crack")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Crack %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCrack(vl);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Reverse")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-1].l), 0, &d);
          LevelSet *pl = FindLevelSet((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Levelset Reverse %d : unknown levelset %d", t, (int)d);
          else ls = new gLevelsetReverse(pl->ls);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[-6].c), "PostView")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[-1].l)) > 0){
            double d; List_Read((yyvsp[-1].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            LevelSet *l = Create_LevelSet(ls->getTag(), ls);
            Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-4].d));
      Free((yyvsp[-6].c));
#endif
    }
#line 7308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2501 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[-6].c), "MathEval")){
        int t = (int)(yyvsp[-4].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[-1].c), t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
#endif
    }
#line 7331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2520 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[-4].c), "CutMesh")){
        int t = (int)(yyvsp[-2].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[-4].c), "CutMeshTri")){
        int t = (int)(yyvsp[-2].d);
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp((yyvsp[-4].c), "SplitMesh")){
        int t = (int)(yyvsp[-2].d);
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
      Free((yyvsp[-4].c));
#endif
    }
#line 7373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2559 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp((yyvsp[-12].c), "Cylinder") && List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-12].c), "Cone") && List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-12].c), "Cylinder") && List_Nbr((yyvsp[-2].l)) == 2){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-12].c), "Cylinder") && List_Nbr((yyvsp[-2].l)) == 3){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-12].c), "Ellipsoid") && List_Nbr((yyvsp[-2].l)) == 3){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp((yyvsp[-12].c), "Quadric") && List_Nbr((yyvsp[-2].l)) == 5){
        int t = (int)(yyvsp[-10].d);
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", (yyvsp[-10].d));
      Free((yyvsp[-12].c));
#endif
    }
#line 7480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2667 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2676 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2682 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[-4].c));
#endif
      Free((yyvsp[-4].c));
    }
#line 7522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2697 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Meshes") || !strcmp((yyvsp[-1].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[-1].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[-1].c), "Physicals")){
	GModel::current()->getGEOInternals()->reset_physicals();
	GModel::current()->deletePhysicalGroups();
      }
      else if(!strcmp((yyvsp[-1].c), "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp((yyvsp[-1].c), "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count((yyvsp[-1].c)))
	  gmsh_yysymbols.erase((yyvsp[-1].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[-1].c));
      }
      Free((yyvsp[-1].c));
    }
#line 7554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2725 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-2].c), "Empty") && !strcmp((yyvsp[-1].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", (yyvsp[-2].c), (yyvsp[-1].c));
#endif
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 7570 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2742 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2751 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2765 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2779 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2785 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2791 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2800 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2809 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2818 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2832 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-2].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
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
      else if(!strcmp((yyvsp[-2].c), "Print")){
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[-2].c), "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[-2].c), "Merge") || !strcmp((yyvsp[-2].c), "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[-2].c), "NonBlockingSystemCall")){
	SystemCall((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "System") || !strcmp((yyvsp[-2].c), "SystemCall")){
	SystemCall((yyvsp[-1].c), true);
      }
      else if(!strcmp((yyvsp[-2].c), "SetName")){
	GModel::current()->setName((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateSingleDir(tmp);
      }
      else if(!strcmp((yyvsp[-2].c), "OnelabRun")){
        Msg::RunOnelabClient((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[-1].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 7744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2891 "Gmsh.y" /* yacc.c:1646  */
    {
      int n = List_Nbr((yyvsp[-2].l));
      if(n == 1){
        char *s; List_Read((yyvsp[-2].l), 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read((yyvsp[-2].l), 0, &s); List_Read((yyvsp[-2].l), 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete((yyvsp[-2].l));
    }
#line 7766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2909 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-6].c), "Save") && !strcmp((yyvsp[-5].c), "View")){
	int index = (int)(yyvsp[-3].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-6].c));
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-1].c));
    }
#line 7787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2926 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[-6].c), "Background") && !strcmp((yyvsp[-5].c), "Mesh")  && !strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-6].c));
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    }
#line 7806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2941 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")){
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
	GModel::current()->importGEOInternals();
	GModel::current()->mesh((int)(yyvsp[-1].d));
	CTX::instance()->lock = lock;
      }
      else if(!strcmp((yyvsp[-2].c), "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 7836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2967 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[-4].c), (yyvsp[-1].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[-1].c), (yyvsp[-4].c));
       }
#endif
       Free((yyvsp[-4].c)); Free((yyvsp[-1].c));
     }
#line 7852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2979 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-1].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[-1].c));
    }
#line 7880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 3003 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 3007 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 3012 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7908 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 3019 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7917 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 3024 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3030 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3035 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3041 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 7958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3049 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7966 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3053 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3057 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3063 "Gmsh.y" /* yacc.c:1646  */
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr((yyvsp[-13].l)); i++){
        double d;
        List_Read((yyvsp[-13].l), i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yyerror("Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[-10].l)); i++){
          double d;
          List_Read((yyvsp[-10].l), i, &d);
          LevelSet *l = FindLevelSet((int)d);
          if(l) f.push_back(l->ls);
          else yymsg(0, "Unknown Levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yyerror("Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[-7].l)) != (int)f.size()){
            yyerror("Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr((yyvsp[-7].l)));
            for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
              List_T *l = *(List_T**)List_Pointer((yyvsp[-7].l), i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)(yyvsp[-4].d);
            bool meshAll = ((yyvsp[-2].d) == 0) ? false : true;
            GModel::current()->importGEOInternals();
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete((yyvsp[-13].l));
      List_Delete((yyvsp[-10].l));
      for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[-7].l), i));
      List_Delete((yyvsp[-7].l));
      CTX::instance()->lock = lock;
    }
#line 8041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3122 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[-3].d) > (yyvsp[-1].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
#line 8062 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3139 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
#line 8083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3156 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-6].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-6].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-3].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[-3].d) > (yyvsp[-1].d))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[-6].c));
    }
#line 8109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3178 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-8].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-8].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-5].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[-8].c));
    }
#line 8135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3200 "Gmsh.y" /* yacc.c:1646  */
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        std::string name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name.size()){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name.c_str());
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name.c_str());
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
#line 8174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3235 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8186 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3243 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3251 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3257 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3264 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8230 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3271 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if((yyvsp[-1].d)){
        // Current test is true
        statusImbricatedTests[ImbricatedTest] = 1;
      }
      else{
        statusImbricatedTests[ImbricatedTest] = 0;
        // Go after the next ElseIf or Else or EndIf
        int type_until2 = 0;
        skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    }
#line 8254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3291 "Gmsh.y" /* yacc.c:1646  */
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip_until("If", "EndIf");
          ImbricatedTest--;
        }
        else{
          // Previous test(s) (If and ElseIf) not yet true
          if((yyvsp[-1].d)){
            statusImbricatedTests[ImbricatedTest] = 1;
          }
          else{
            // Current test still not true: statusImbricatedTests[ImbricatedTest] = 0;
            // Go after the next ElseIf or Else or EndIf
            int type_until2 = 0;
            skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
            if(!type_until2) ImbricatedTest--;
          }
        }
      }
      else{
	yymsg(0, "Orphan ElseIf");
      }
    }
#line 8284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3317 "Gmsh.y" /* yacc.c:1646  */
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          skip_until("If", "EndIf");
          ImbricatedTest--;
        }
      }
      else{
	yymsg(0, "Orphan Else");
      }
    }
#line 8300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3329 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3341 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3349 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3357 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3365 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3371 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3379 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3385 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3393 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3399 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8412 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3407 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3413 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3421 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3428 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3435 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3442 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3449 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8488 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3456 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3463 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3470 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3477 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3484 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8542 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3490 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3497 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3503 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3510 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3516 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3523 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3529 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3536 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3542 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3549 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3555 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3562 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3575 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3581 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3588 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3594 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3605 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3608 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      int n = (int)fabs((yyvsp[-2].d));
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[-2].d)));
        extr.mesh.hLayer.push_back(1.);
      }
    }
#line 8751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3626 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-4].l));
      if(List_Nbr((yyvsp[-4].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	  double d;
	  List_Read((yyvsp[-4].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-2].l)));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    }
#line 8775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3646 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Explicit region numbers in layers are deprecated");
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-6].l));
      if(List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-4].l)) && List_Nbr((yyvsp[-6].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-6].l)); i++){
	  double d;
	  List_Read((yyvsp[-6].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d, %d}", List_Nbr((yyvsp[-6].l)),
	      List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-2].l)));
      List_Delete((yyvsp[-6].l));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    }
#line 8802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3670 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8810 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3674 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3678 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3682 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3686 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3692 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3698 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3702 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3706 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8878 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3710 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3714 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	extr.mesh.Holes[num].first = (yyvsp[-1].d);
	extr.mesh.Holes[num].second.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	  double d;
	  List_Read((yyvsp[-3].l), i, &d);
	  extr.mesh.Holes[num].second.push_back((int)d);
	}
      }
      List_Delete((yyvsp[-3].l));
    }
#line 8909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3733 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3745 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3749 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Progression") || !strcmp((yyvsp[-1].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[-1].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[0].d);
      Free((yyvsp[-1].c));
    }
#line 8946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3764 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3768 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[0].c), "Left"))
	(yyval.i) = -1;
      else if(!strcmp((yyvsp[0].c), "AlternateRight"))
	(yyval.i) = 2;
      else if(!strcmp((yyvsp[0].c), "AlternateLeft"))
	(yyval.i) = -2;
      else // "Alternate" -> "Alternate Right"
	(yyval.i) = 2;
      Free((yyvsp[0].c));
    }
#line 8972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3784 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8980 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3788 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3793 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8996 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3797 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3803 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3807 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9020 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3814 "Gmsh.y" /* yacc.c:1646  */
    {
      int type = (int)(yyvsp[-1].v)[0];
      double coef = fabs((yyvsp[-1].v)[1]);
      if(!(yyvsp[-4].l)){
        List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->Method = MESH_TRANSFINITE;
            c->nbPointsTransfinite = ((yyvsp[-2].d) > 2) ? (int)(yyvsp[-2].d) : 2;
            c->typeTransfinite = type;
            c->coeffTransfinite = coef;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.method = MESH_TRANSFINITE;
            (*it)->meshAttributes.nbPointsTransfinite = ((yyvsp[-2].d) > 2) ? (int)(yyvsp[-2].d) : 2;
            (*it)->meshAttributes.typeTransfinite = type;
            (*it)->meshAttributes.coeffTransfinite = coef;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
          double d;
          List_Read((yyvsp[-4].l), i, &d);
          int j = (int)fabs(d);
          for(int sign = -1; sign <= 1; sign += 2){
            Curve *c = FindCurve(sign * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ((yyvsp[-2].d) > 2) ? (int)(yyvsp[-2].d) : 2;
              c->typeTransfinite = type * sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sign * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ((yyvsp[-2].d) > 2) ? (int)(yyvsp[-2].d) : 2;
                ge->meshAttributes.typeTransfinite = type * sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sign > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete((yyvsp[-4].l));
      }
    }
#line 9080 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3870 "Gmsh.y" /* yacc.c:1646  */
    {
      int k = List_Nbr((yyvsp[-2].l));
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
      }
      else{
        if(!(yyvsp[-3].l)){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Surface *s;
              List_Read(tmp, i, &s);
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[-1].i);
              List_Reset(s->TrsfPoints);
            }
          }
          else{
            for(GModel::fiter it = GModel::current()->firstFace();
                it != GModel::current()->lastFace(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
              (*it)->meshAttributes.transfiniteArrangement = (yyvsp[-1].i);
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
            double d;
            List_Read((yyvsp[-3].l), i, &d);
            Surface *s = FindSurface((int)d);
            if(s){
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = (yyvsp[-1].i);
              List_Reset(s->TrsfPoints);
              for(int j = 0; j < k; j++){
                double p;
                List_Read((yyvsp[-2].l), j, &p);
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
                gf->meshAttributes.transfiniteArrangement = (yyvsp[-1].i);
                for(int j = 0; j < k; j++){
                  double p;
                  List_Read((yyvsp[-2].l), j, &p);
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
          List_Delete((yyvsp[-3].l));
        }
      }
      List_Delete((yyvsp[-2].l));
    }
#line 9154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3940 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3945 "Gmsh.y" /* yacc.c:1646  */
    {
      int k = List_Nbr((yyvsp[-1].l));
      if(k != 0 && k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume: "
              "%d points instead of 6 or 8", k);
      }
      else{
        if(!(yyvsp[-2].l)){
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
          for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
            double d;
            List_Read((yyvsp[-2].l), i, &d);
            Volume *v = FindVolume((int)d);
            if(v){
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
              for(int i = 0; i < k; i++){
                double p;
                List_Read((yyvsp[-1].l), i, &p);
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
                  List_Read((yyvsp[-1].l), i, &p);
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
          List_Delete((yyvsp[-2].l));
        }
      }
      List_Delete((yyvsp[-1].l));
    }
#line 9234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 4012 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
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
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 4048 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4056 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-2].l)){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[-1].i);
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.recombine = 1;
            (*it)->meshAttributes.recombineAngle = (yyvsp[-1].i);
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          double d;
          List_Read((yyvsp[-2].l), i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->Recombine = 1;
            s->RecombineAngle = (yyvsp[-1].i);
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.recombine = 1;
              gf->meshAttributes.recombineAngle = (yyvsp[-1].i);
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete((yyvsp[-2].l));
      }
    }
#line 9333 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4099 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
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
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4138 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        int j = (int)d;
        Surface *s = FindSurface(j);
        if(s){
          s->TransfiniteSmoothing = (int)(yyvsp[-1].d);
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(j);
          if(gf)
            gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[-1].d);
          else
            yymsg(1, "Unknown surface %d", (int)(yyvsp[-1].d));
        }
      }
      List_Delete((yyvsp[-3].l));
    }
#line 9400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4159 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[-1].l)) != 0) {
          if (List_Nbr((yyvsp[-1].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[-1].l)));
          }
          else {
            transfo.resize(List_Nbr((yyvsp[-1].l)));
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
              List_Read((yyvsp[-1].l), i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-3].l), i, &d_master);
          List_Read((yyvsp[-7].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 9435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4191 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        if (List_Nbr((yyvsp[-1].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
            List_Read((yyvsp[-1].l), i, &transfo[i]);
          for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
            double d_master, d_slave;
            List_Read((yyvsp[-3].l), i, &d_master);
            List_Read((yyvsp[-7].l), i, &d_slave);
            addPeriodicFace(d_slave, d_master, transfo);
          }
        }
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 9465 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4218 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 axis((yyvsp[-6].v)[0],(yyvsp[-6].v)[1],(yyvsp[-6].v)[2]);
        SPoint3 origin((yyvsp[-4].v)[0],(yyvsp[-4].v)[1],(yyvsp[-4].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-14].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-10].l), i, &d_master);
          List_Read((yyvsp[-14].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-14].l));
      List_Delete((yyvsp[-10].l));
    }
#line 9494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4244 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 origin((yyvsp[-4].v)[0],(yyvsp[-4].v)[1],(yyvsp[-4].v)[2]);
        SPoint3 axis((yyvsp[-6].v)[0],(yyvsp[-6].v)[1],(yyvsp[-6].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-14].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-10].l), i, &d_master);
          List_Read((yyvsp[-14].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[-14].l));
      List_Delete((yyvsp[-10].l));
    }
#line 9523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4270 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0],(yyvsp[-1].v)[1],(yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-8].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-4].l), i, &d_master);
          List_Read((yyvsp[-8].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-8].l));
      List_Delete((yyvsp[-4].l));
    }
#line 9552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4296 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0],(yyvsp[-1].v)[1],(yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-8].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-4].l), i, &d_master);
          List_Read((yyvsp[-8].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[-8].l));
      List_Delete((yyvsp[-4].l));
    }
#line 9581 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4322 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-2].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[-2].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        int j_master = (int)(yyvsp[-4].d);
        int j_slave = (int)(yyvsp[-9].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
          double ds,dm;
          List_Read((yyvsp[-7].l),i,&ds);
          List_Read((yyvsp[-2].l),i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave, j_master, edgeCounterParts);
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-2].l));
    }
#line 9606 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4343 "Gmsh.y" /* yacc.c:1646  */
    {
      Surface *s = FindSurface((int)(yyvsp[-2].d));
      if(s){
	setSurfaceEmbeddedPoints(s, (yyvsp[-7].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[-2].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
            double d;
            List_Read((yyvsp[-7].l), i, &d);
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
          yymsg(0, "Unknown surface %d", (int)(yyvsp[-2].d));
      }
    }
#line 9638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4371 "Gmsh.y" /* yacc.c:1646  */
    {
      Surface *s = FindSurface((int)(yyvsp[-2].d));
      if(s){
	setSurfaceEmbeddedCurves(s, (yyvsp[-7].l));
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[-2].d));
        if(gf){
          for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
            double d;
            List_Read((yyvsp[-7].l), i, &d);
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
          yymsg(0, "Unknown surface %d", (int)(yyvsp[-2].d));
      }
    }
#line 9670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4399 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9678 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4403 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4407 "Gmsh.y" /* yacc.c:1646  */
    {
      Volume *v = FindVolume((int)(yyvsp[-2].d));
      if(v){
	setVolumeEmbeddedSurfaces(v, (yyvsp[-7].l));
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)(yyvsp[-2].d));
        if(gr){
          for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
            double d;
            List_Read((yyvsp[-7].l), i, &d);
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
          yymsg(0, "Unknown volume %d", (int)(yyvsp[-2].d));
      }
    }
#line 9718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4435 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
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
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4474 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
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
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4513 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
        for(GModel::viter it = GModel::current()->firstVertex();
            it != GModel::current()->lastVertex(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          GVertex *gv = GModel::current()->getVertexByTag((int)d);
          if(gv){
            gv->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown point %d", (int)d);
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4534 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          GEdge *ge = GModel::current()->getEdgeByTag((int)d);
          if(ge){
            ge->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown line %d", (int)d);
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4555 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].l)){
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          GFace *gf = GModel::current()->getFaceByTag((int)d);
          if(gf){
            gf->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown surface %d", (int)d);
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 9879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4582 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9887 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4586 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4596 "Gmsh.y" /* yacc.c:1646  */
    {
      if(List_Nbr((yyvsp[-2].l)) >= 2){
        double d;
        List_Read((yyvsp[-2].l), 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target)
          yymsg(0, "Could not find Point %d", (int)d);
        else{
          double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
          for(int i = 1; i < List_Nbr((yyvsp[-2].l)); i++){
            List_Read((yyvsp[-2].l), i, &d);
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
      List_Delete((yyvsp[-2].l));
    }
#line 9935 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9941 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9947 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4637 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-4].c), domain, subdomain, dim);
      List_Delete((yyvsp[-2].l));
    }
#line 9979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4655 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-6].c), domain, subdomain, dim);
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    }
#line 10001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4673 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
        double d;
        List_Read((yyvsp[-7].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[-9].c), domain, subdomain, dim);
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
      List_Delete((yyvsp[-7].l));
    }
#line 10028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4700 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4701 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4702 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10046 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4703 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4704 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4705 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4706 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4707 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4709 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4715 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4716 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4717 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4718 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10111 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4719 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4720 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4721 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4722 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4723 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4724 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4725 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10153 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4726 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4727 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10165 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4728 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4729 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4730 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4731 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4732 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10195 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4733 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10201 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4734 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4735 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10213 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4736 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4737 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10225 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4739 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4740 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4741 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4742 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10255 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4743 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10261 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4744 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10267 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4745 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4746 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10279 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4747 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4756 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4757 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10297 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4758 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4759 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4760 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4761 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4762 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4763 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10333 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4764 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4765 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4766 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4771 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4773 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4779 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4784 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4789 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yysymbols.count((yyvsp[0].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[0].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[0].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[0].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[0];
      }
      Free((yyvsp[0].c));
    }
#line 10406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4806 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-1].d);
      if(!gmsh_yysymbols.count((yyvsp[-3].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-3].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[-3].c));
    }
#line 10428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4824 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-1].d);
      if(!gmsh_yysymbols.count((yyvsp[-3].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-3].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[-3].c));
    }
#line 10450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4842 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-1].d);
      if(!gmsh_yysymbols.count((yyvsp[-3].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-3].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[-3].c));
    }
#line 10472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4860 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-1].d);
      if(!gmsh_yysymbols.count((yyvsp[-3].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-3].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = s.value[index];
      }
      Free((yyvsp[-3].c));
    }
#line 10494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4878 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4883 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4889 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yysymbols.count((yyvsp[-2].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	(yyval.d) = s.value.size();
      }
      Free((yyvsp[-2].c));
    }
#line 10529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4901 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yysymbols.count((yyvsp[-1].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-1].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-1].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[-1].c));
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[0] += (yyvsp[0].i));
      }
      Free((yyvsp[-1].c));
    }
#line 10550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4918 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[0].i));
      }
      Free((yyvsp[-4].c));
    }
#line 10572 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[0].i));
      }
      Free((yyvsp[-4].c));
    }
#line 10594 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4954 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[0].i));
      }
      Free((yyvsp[-4].c));
    }
#line 10616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4972 "Gmsh.y" /* yacc.c:1646  */
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else
          (yyval.d) = (s.value[index] += (yyvsp[0].i));
      }
      Free((yyvsp[-4].c));
    }
#line 10638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4993 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4998 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5003 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5023 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5028 "Gmsh.y" /* yacc.c:1646  */
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        matches += List_Search((yyvsp[-1].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[-3].l)); Free((yyvsp[-1].l));
    }
#line 10708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5039 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5048 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5053 "Gmsh.y" /* yacc.c:1646  */
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[-1].l)) % 2){
        yyerror("Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr((yyvsp[-1].l)); i += 2){
          char *s1, *s2; List_Read((yyvsp[-1].l), i, &s1); List_Read((yyvsp[-1].l), i + 1, &s2);
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
      List_Delete((yyvsp[-1].l));
      (yyval.d) = (double)((align<<16)|(font<<8)|(fontsize));
    }
#line 10758 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5080 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5084 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10774 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5088 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5092 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5096 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5103 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5107 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5111 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5115 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5122 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5127 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5134 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5139 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10864 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5143 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5148 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10881 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5152 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5160 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5171 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5175 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5187 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10938 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5195 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5203 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5210 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5220 "Gmsh.y" /* yacc.c:1646  */
    {
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      (yyval.l) = List_Create(3, 1, sizeof(double));
      if(!v) {
        GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[-1].d));
        if(gv){
          double x = gv->x(), y = gv->y(), z = gv->z();
          List_Add((yyval.l), &x);
          List_Add((yyval.l), &y);
          List_Add((yyval.l), &z);
        }
        else{
          yymsg(0, "Unknown point '%d'", (int)(yyvsp[-1].d));
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
#line 11008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5249 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11016 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5253 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5257 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11032 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5261 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5265 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5269 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5273 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5277 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5281 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double num;
        List_Read((yyvsp[-1].l), i, &num);
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
      List_Delete((yyvsp[-1].l));
    }
#line 11105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5310 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double num;
        List_Read((yyvsp[-1].l), i, &num);
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
      List_Delete((yyvsp[-1].l));
    }
#line 11138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double num;
        List_Read((yyvsp[-1].l), i, &num);
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
      List_Delete((yyvsp[-1].l));
    }
#line 11171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5368 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double num;
        List_Read((yyvsp[-1].l), i, &num);
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
      List_Delete((yyvsp[-1].l));
    }
#line 11204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5398 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
#line 11220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5411 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
#line 11236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5424 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
#line 11252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5437 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box((yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d));
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add((yyval.l), &d);
      }
    }
#line 11268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5449 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5459 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5469 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-2].c));
    }
#line 11312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5481 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-2].c));
    }
#line 11328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5494 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-1].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-1].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-1].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-1].c));
    }
#line 11344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5506 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-5].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-5].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[-2].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    }
#line 11366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5524 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-5].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-5].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[-2].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    }
#line 11388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5545 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5550 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5554 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5558 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5570 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5574 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5586 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      if(gmsh_yystringsymbols.count((yyvsp[0].c)))
        (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[0].c)].c_str(), &flag);
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5596 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5606 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5610 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)(yyvsp[-3].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[-3].d));
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[-5].c));
    }
#line 11491 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5625 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11500 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5630 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5637 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5641 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!gmsh_yystringsymbols.count((yyvsp[0].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[0].c));
	(yyval.c) = (yyvsp[0].c);
      }
      else{
	std::string val = gmsh_yystringsymbols[(yyvsp[0].c)];
	(yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
	strcpy((yyval.c), val.c_str());
	Free((yyvsp[0].c));
      }
    }
#line 11533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5654 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11545 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5662 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5673 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5677 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5681 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5689 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5695 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5701 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5709 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5717 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5724 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5732 "Gmsh.y" /* yacc.c:1646  */
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[-1].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        char *s;
        List_Read((yyvsp[-1].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 11671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5747 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c)) - 1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[-1].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5761 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c)) - 1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '/' || (yyvsp[-1].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[-1].c));
      else
	strcpy((yyval.c), &(yyvsp[-1].c)[i+1]);
      Free((yyvsp[-1].c));
    }
#line 11707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5775 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string input = (yyvsp[-5].c);
      std::string substr_old = (yyvsp[-3].c);
      std::string substr_new = (yyvsp[-1].c);
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      (yyval.c) = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy((yyval.c), ret.c_str());
      Free((yyvsp[-5].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11723 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5787 "Gmsh.y" /* yacc.c:1646  */
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[-1].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        char *s;
        List_Read((yyvsp[-1].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
        if(i != List_Nbr((yyvsp[-1].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[-1].l));
    }
#line 11743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5803 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11756 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5812 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5821 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5831 "Gmsh.y" /* yacc.c:1646  */
    {
      if((yyvsp[-5].d)){
        (yyval.c) = (yyvsp[-3].c);
        Free((yyvsp[-1].c));
      }
      else{
        (yyval.c) = (yyvsp[-1].c);
        Free((yyvsp[-3].c));
      }
    }
#line 11798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5842 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5846 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstring[5000];
      int i = PrintListOfDouble((yyvsp[-3].c), (yyvsp[-1].l), tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[-3].c);
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	(yyval.c) = (yyvsp[-3].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[-3].c));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 11829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5865 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5872 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5878 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5880 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5891 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5896 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5902 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5911 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5924 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 5927 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 5931 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11929 "Gmsh.tab.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 5934 "Gmsh.y" /* yacc.c:1906  */


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

void addPeriodicFace(int iTarget, int iSource,
                     const std::vector<double>& affineTransform)
{
  Surface *target = FindSurface(abs(iTarget));

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts.clear();
    mf.affineTransform = affineTransform;
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target)  Msg::Error("Could not find edge %d for periodic copy from %d",
                             iTarget,iSource);
    target->setMeshMaster(source, affineTransform);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  Surface *target = FindSurface(abs(iTarget));

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts = edgeCounterparts;
    mf.affineTransform.clear();
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source)
      Msg::Error("Could not find surface %d or %d for periodic copy",
                 iTarget,iSource);
    target->setMeshMaster(source, edgeCounterparts);
  }
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  Curve *target = FindCurve(abs(iTarget));
  if (target) {
    GEO_Internals::MasterEdge& me =
      GModel::current()->getGEOInternals()->periodicEdges[iTarget];
    me.tag = iSource;
    me.affineTransform = affineTransform;
  }
  else{
    GEdge *target = GModel::current()->getEdgeByTag(abs(iTarget));
    GEdge *source = GModel::current()->getEdgeByTag(abs(iSource));
    if (!target || !source)
      Msg::Error("Could not find surface %d or %d for periodic copy",
                 iTarget,iSource);
    if (affineTransform.size() >= 12) {
      target->setMeshMaster(source, affineTransform);
    }
    else {
      target->setMeshMaster(source, iSource * iTarget < 0 ? -1 : 1);
    }
  }
}

void computeAffineTransformation(SPoint3& origin, SPoint3& axis,
                                 double angle, SPoint3& translation,
                                 std::vector<double>& tfo)
{
  tfo.resize(16,0.0);

  double ca = cos(angle);
  double sa = sin(angle);

  double ux = axis.x();
  double uy = axis.y();
  double uz = axis.z();

  tfo.resize(16);

  tfo[0*4+0] = ca + ux*ux*(1.-ca);
  tfo[0*4+1] = ux*uy*(1.-ca) - uz * sa;
  tfo[0*4+2] = ux*uz*(1.-ca) + uy * sa;

  tfo[1*4+0] = ux*uy*(1.-ca) + uz * sa;
  tfo[1*4+1] = ca + uy*uy*(1.-ca);
  tfo[1*4+2] = uy*uz*(1.-ca) - ux * sa;

  tfo[2*4+0] = ux*uz*(1.-ca) - uy * sa;
  tfo[2*4+1] = uy*uz*(1.-ca) + ux * sa;
  tfo[2*4+2] = ca + uz*uz*(1.-ca);

  int idx = 0;
  for (size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i*4+3;
    tfo[tIdx] = origin[i] + translation[i];
    for (int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for (int i = 0; i < 4; i++) tfo[12+i] = 0;
  tfo[15] = 1;
}
