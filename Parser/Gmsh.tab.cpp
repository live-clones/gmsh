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
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

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
    tAbsolutePath = 301,
    tDirName = 302,
    tFind = 303,
    tStrFind = 304,
    tStrCmp = 305,
    tStrChoice = 306,
    tUpperCase = 307,
    tLowerCase = 308,
    tLowerCaseIn = 309,
    tTextAttributes = 310,
    tBoundingBox = 311,
    tDraw = 312,
    tSetChanged = 313,
    tToday = 314,
    tFixRelativePath = 315,
    tCurrentDirectory = 316,
    tSyncModel = 317,
    tNewModel = 318,
    tOnelabAction = 319,
    tOnelabRun = 320,
    tCpu = 321,
    tMemory = 322,
    tTotalMemory = 323,
    tCreateTopology = 324,
    tCreateTopologyNoHoles = 325,
    tDistanceFunction = 326,
    tDefineConstant = 327,
    tUndefineConstant = 328,
    tDefineNumber = 329,
    tDefineString = 330,
    tSetNumber = 331,
    tSetString = 332,
    tPoint = 333,
    tCircle = 334,
    tEllipse = 335,
    tLine = 336,
    tSphere = 337,
    tPolarSphere = 338,
    tSurface = 339,
    tSpline = 340,
    tVolume = 341,
    tCharacteristic = 342,
    tLength = 343,
    tParametric = 344,
    tElliptic = 345,
    tRefineMesh = 346,
    tAdaptMesh = 347,
    tRelocateMesh = 348,
    tPlane = 349,
    tRuled = 350,
    tTransfinite = 351,
    tComplex = 352,
    tPhysical = 353,
    tCompound = 354,
    tPeriodic = 355,
    tUsing = 356,
    tPlugin = 357,
    tDegenerated = 358,
    tRecursive = 359,
    tRotate = 360,
    tTranslate = 361,
    tSymmetry = 362,
    tDilate = 363,
    tExtrude = 364,
    tLevelset = 365,
    tAffine = 366,
    tRecombine = 367,
    tSmoother = 368,
    tSplit = 369,
    tDelete = 370,
    tCoherence = 371,
    tIntersect = 372,
    tMeshAlgorithm = 373,
    tReverse = 374,
    tLayers = 375,
    tScaleLast = 376,
    tHole = 377,
    tAlias = 378,
    tAliasWithOptions = 379,
    tCopyOptions = 380,
    tQuadTriAddVerts = 381,
    tQuadTriNoNewVerts = 382,
    tQuadTriSngl = 383,
    tQuadTriDbl = 384,
    tRecombLaterals = 385,
    tTransfQuadTri = 386,
    tText2D = 387,
    tText3D = 388,
    tInterpolationScheme = 389,
    tTime = 390,
    tCombine = 391,
    tBSpline = 392,
    tBezier = 393,
    tNurbs = 394,
    tNurbsOrder = 395,
    tNurbsKnots = 396,
    tColor = 397,
    tColorTable = 398,
    tFor = 399,
    tIn = 400,
    tEndFor = 401,
    tIf = 402,
    tElseIf = 403,
    tElse = 404,
    tEndIf = 405,
    tExit = 406,
    tAbort = 407,
    tField = 408,
    tReturn = 409,
    tCall = 410,
    tMacro = 411,
    tShow = 412,
    tHide = 413,
    tGetValue = 414,
    tGetStringValue = 415,
    tGetEnv = 416,
    tGetString = 417,
    tGetNumber = 418,
    tHomology = 419,
    tCohomology = 420,
    tBetti = 421,
    tExists = 422,
    tFileExists = 423,
    tGMSH_MAJOR_VERSION = 424,
    tGMSH_MINOR_VERSION = 425,
    tGMSH_PATCH_VERSION = 426,
    tGmshExecutableName = 427,
    tSetPartition = 428,
    tNameToString = 429,
    tStringToName = 430,
    tAFFECTPLUS = 431,
    tAFFECTMINUS = 432,
    tAFFECTTIMES = 433,
    tAFFECTDIVIDE = 434,
    tOR = 435,
    tAND = 436,
    tEQUAL = 437,
    tNOTEQUAL = 438,
    tLESSOREQUAL = 439,
    tGREATEROREQUAL = 440,
    tPLUSPLUS = 441,
    tMINUSMINUS = 442,
    UNARYPREC = 443
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

#line 421 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 438 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   11817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  551
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1973

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   443

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   194,     2,   204,     2,   193,     2,     2,
     199,   200,   191,   189,   205,   190,   203,   192,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     185,     2,   187,   180,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   201,     2,   202,   198,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   206,     2,   207,   208,     2,     2,     2,
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
     175,   176,   177,   178,   179,   181,   182,   183,   184,   186,
     188,   195,   196,   197
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   198,   198,   199,   204,   206,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   229,   233,   240,   245,   250,   264,   277,   290,
     318,   332,   345,   358,   377,   382,   383,   384,   385,   386,
     390,   392,   397,   399,   405,   509,   404,   527,   534,   545,
     544,   562,   569,   580,   579,   596,   613,   636,   635,   649,
     650,   651,   652,   653,   657,   658,   664,   664,   665,   665,
     671,   672,   673,   678,   684,   746,   763,   792,   821,   826,
     831,   836,   841,   848,   858,   887,   916,   921,   926,   931,
     939,   948,   954,   960,   973,   986,  1001,  1018,  1024,  1030,
    1043,  1056,  1071,  1088,  1094,  1103,  1121,  1139,  1148,  1160,
    1165,  1173,  1193,  1216,  1227,  1235,  1257,  1280,  1306,  1327,
    1339,  1353,  1353,  1355,  1357,  1366,  1376,  1375,  1396,  1395,
    1414,  1413,  1431,  1441,  1440,  1454,  1456,  1464,  1470,  1477,
    1478,  1482,  1493,  1508,  1518,  1519,  1524,  1532,  1541,  1549,
    1567,  1571,  1577,  1585,  1589,  1595,  1603,  1607,  1613,  1621,
    1625,  1631,  1640,  1643,  1656,  1659,  1669,  1692,  1735,  1758,
    1776,  1797,  1815,  1845,  1875,  1893,  1911,  1938,  1956,  1974,
    2020,  2038,  2077,  2083,  2089,  2096,  2121,  2146,  2163,  2182,
    2216,  2263,  2281,  2298,  2314,  2362,  2367,  2372,  2377,  2382,
    2387,  2410,  2416,  2427,  2428,  2433,  2436,  2440,  2463,  2486,
    2509,  2537,  2558,  2584,  2605,  2627,  2647,  2759,  2778,  2816,
    2925,  2934,  2940,  2955,  2983,  3000,  3009,  3023,  3037,  3043,
    3049,  3058,  3067,  3076,  3090,  3149,  3167,  3184,  3199,  3225,
    3237,  3261,  3265,  3270,  3277,  3282,  3288,  3293,  3299,  3307,
    3311,  3315,  3320,  3380,  3397,  3414,  3436,  3458,  3493,  3501,
    3509,  3515,  3522,  3529,  3549,  3575,  3587,  3599,  3607,  3615,
    3624,  3623,  3638,  3637,  3652,  3651,  3666,  3665,  3679,  3686,
    3693,  3700,  3707,  3714,  3721,  3728,  3735,  3743,  3742,  3756,
    3755,  3769,  3768,  3782,  3781,  3795,  3794,  3808,  3807,  3821,
    3820,  3834,  3833,  3847,  3846,  3863,  3866,  3872,  3884,  3904,
    3928,  3932,  3936,  3940,  3944,  3948,  3954,  3960,  3964,  3968,
    3972,  3976,  3995,  4008,  4011,  4027,  4030,  4047,  4050,  4056,
    4059,  4066,  4069,  4076,  4132,  4202,  4207,  4274,  4310,  4318,
    4361,  4400,  4420,  4452,  4479,  4505,  4531,  4557,  4583,  4605,
    4633,  4661,  4665,  4669,  4697,  4736,  4775,  4796,  4817,  4844,
    4848,  4858,  4893,  4894,  4895,  4899,  4905,  4917,  4935,  4963,
    4964,  4965,  4966,  4967,  4968,  4969,  4970,  4971,  4978,  4979,
    4980,  4981,  4982,  4983,  4984,  4985,  4986,  4987,  4988,  4989,
    4990,  4991,  4992,  4993,  4994,  4995,  4996,  4997,  4998,  4999,
    5000,  5001,  5002,  5003,  5004,  5005,  5006,  5007,  5008,  5009,
    5010,  5019,  5020,  5021,  5022,  5023,  5024,  5025,  5026,  5027,
    5028,  5029,  5034,  5033,  5041,  5046,  5051,  5068,  5086,  5104,
    5122,  5140,  5145,  5151,  5166,  5183,  5201,  5219,  5237,  5258,
    5263,  5268,  5278,  5288,  5293,  5304,  5313,  5318,  5345,  5349,
    5353,  5357,  5361,  5368,  5372,  5376,  5380,  5387,  5392,  5399,
    5404,  5408,  5413,  5417,  5425,  5436,  5440,  5452,  5460,  5468,
    5475,  5485,  5514,  5518,  5522,  5526,  5530,  5534,  5538,  5542,
    5546,  5575,  5604,  5633,  5662,  5675,  5688,  5701,  5714,  5724,
    5734,  5746,  5759,  5771,  5775,  5779,  5783,  5787,  5805,  5826,
    5831,  5835,  5839,  5851,  5855,  5867,  5884,  5894,  5898,  5913,
    5918,  5925,  5929,  5942,  5956,  5970,  5984,  5998,  6006,  6017,
    6021,  6025,  6033,  6039,  6045,  6053,  6061,  6068,  6076,  6091,
    6105,  6119,  6131,  6147,  6156,  6165,  6175,  6186,  6190,  6209,
    6216,  6222,  6229,  6237,  6236,  6249,  6254,  6260,  6269,  6282,
    6285,  6289
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
  "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace", "tAbsolutePath",
  "tDirName", "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase",
  "tLowerCase", "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
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
  "Affectation", "Comma", "DefineConstants", "$@6", "$@7", "$@8", "$@9",
  "UndefineConstants", "Enumeration", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptions", "CharParameterOption",
  "PhysicalId0", "PhysicalId1", "PhysicalId2", "PhysicalId3",
  "InSphereCenter", "CircleOptions", "Shape", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Loop", "Extrude", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "ExtrudeParameters", "ExtrudeParameter", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "$@23", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@24",
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
      63,   435,   436,   437,   438,    60,   439,    62,   440,    43,
      45,    42,    47,    37,    33,   441,   442,   443,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1604

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1604)))

#define YYTABLE_NINF -519

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    8187,    74,   114,  8309, -1604, -1604,  3709,   241,    98,   108,
     148,    42,   230,   288,   334,   362,   210,   433,   456,   256,
     306,  -175,  -175,  -138,   311,   329,     5,   343,   350,    17,
     354,   393,   187,   512,   518,   464,   479,   563,   552,   614,
     387,   609,   559,   411,    92,   508,   632,   -82,   515,   -91,
     -91,   537,   -15,    55,   335,   686,   702,     8,    46,   706,
     709,   115,   796,   817,   830,  5238,   845,   615,   664,   668,
      19,    52, -1604,   672,   675, -1604, -1604,   873,   879,   692,
   -1604,  5717,  5533,    25,    31, -1604, -1604, -1604,  8047,   698,
   -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604, -1604,    39, -1604,   -54,   109,
   -1604,     4, -1604, -1604, -1604, -1604, -1604,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,   710,   713,   714,  -175,  -175,   726,   737,   749,
    -175,  -175,  -175,  -175,   750, -1604,  -175, -1604, -1604, -1604,
   -1604, -1604,  -175,  -175,   947,   756,   768,   776,  -175,  -175,
     794,   797, -1604, -1604, -1604, -1604,   801,  8047,  8047,  8047,
    7470,  7531,     9,     3,   451,   802,   826,   546, -1604,   827,
    1006,   -46,  -102,  1010,  8047,  5915,  5915, -1604,  8047, -1604,
   -1604, -1604, -1604,  5915, -1604, -1604, -1604, -1604, -1604, -1604,
    6108,     3,  8047,  7278,  8047,  8047,   808,  8047,  7278,  8047,
    8047,   849,  7278,  8047,  8047,  5634,   854,   831, -1604,  7278,
    5238,  5238,  5238,   858,   875,  5238,  5238,  5238,   878,   883,
     888,   891,   896,   898,   902,   910,   908,  1321,  1098,  5634,
      19,   915,   916,   -91,   -91,   -91,  8047,  8047,    90, -1604,
     103,   -91,   944,   959,   960,  7020,   139,   -63,   928,   932,
     940,  5238,  5238,  5634,   980,     1,   971, -1604,   987,  1198,
    1212, -1604,  1024,  1026,  1039,  5238,  5238,  1045,  1047,  1049,
     565, -1604,   379,    12,    14,    15,    20,   721,  5832,  8047,
    4174, -1604, -1604,  3956, -1604,  1216, -1604,   326,   -99,  1245,
    8047,  8047,  8047,   237,  8047,  1050, -1604,  1108,  8047,  8047,
    8047, -1604, -1604,  8047,  1046,  1251,  1252, -1604, -1604,  1253,
   -1604,  1254, -1604,   131,  9089,   564,  5915, -1604,  5634,  5634,
    7728,  7789,  1055,  1056,  6108, -1604, -1604, -1604, -1604, -1604,
   -1604,  5634,  1257,  1064,  8047,  8047,  1262,  8047,  8047,  8047,
    8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,
    8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  5915,
    5915,  5915,  5915,  5915,  5915,  5915,  5915,  5634,  5915,  5915,
    8047,  5915,  5915,  5915,  5915,  5915,  8047,  6108,  8047,  5915,
    5915,  5915,  5915,  5915,     3,  6108,     3,  1070,  1070,  1070,
     135, 10737,   141,  7495,   178,  1066,  1263,  -175,  1068, -1604,
    1065,  4214,  8047,  7278, -1604,  8047,  8047,  8047,  8047,  8047,
    8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,  8047,
   -1604, -1604,  8047,  8047, -1604, -1604,   569,   467,  -135, -1604,
     590, -1604,   386,  9196, -1604,   472,   227,   267,  1072,  1073,
   10758,  7278,  4962, -1604,   404, 10779, 10800,  8047, 10821,   477,
   10842, 10863,  8047,   625, 10884, 10905,  1272,  8047,  8047,   655,
    1276,  1277,  1280,  8047,  8047,  1281,  1282,  1282,  8047,  7086,
    7086,  7086,  7086,  8047,  8047,  8047,  7278,  7278,  9116,  1087,
    1285,  1086, -1604, -1604,   -55, -1604, -1604,  9222,  9248,   -91,
     -91,   451,   451,    76,  8047,  8047,  8047,  7020,  7020,  8047,
    4214,   132, -1604,  8047,  8047,  8047,  8047,  8047,  1286,  1288,
    1289,  8047,  1292,  8047,  8047,   986, -1604, -1604,  7278,  7278,
    7278,  1293,  1294,  8047,  8047,  8047,  8047,  8047,  1297,  -149,
    6030,  6228, -1604,  1239,  8047, -1604,  1246, -1604,  1247, -1604,
    1248,    33,    34,    35,    36,  7278,  1070, -1604, 10926, -1604,
     661,  8047,  6426, -1604,  8047,  8047,   169, -1604, 10947, 10968,
   10989,  1163,  9274, -1604,  1100,  4981, 11010, 11031,  7753, -1604,
   -1604, -1604,  1504, -1604,  1670,  8047,  8047, -1604,  8047,  8047,
    1105,  1111,   665,   174, 11052,   182, 10392,  8047,  7278,  1302,
    1306, -1604,  8047, 11073, 10415,   -74,  6982,  6982,  6982,  6982,
    6982,  6982,  6982,  6982,  6982,  6982,  6982,  9300,  6982,  6982,
    6982,  6982,  6982,  6982,  6982,  9326,  9352,  9378,   492,   517,
     492,  1116,  1118,  1114,   592,   592,  1115,  1117,  1121,  9404,
     592,   592,   592,   478,   592, 11619, -1604,   838,  1122,  1124,
    1123,   610,   611,  1133,  1134,  1119,  1319,  1320,  5634,   246,
    1322,  1323,  5634,    95,  6108,  8047,  1355,  1361,    24,   592,
   -1604,   -20,    18,    29,    78, -1604,  6760,   670,  5000,  2141,
     999,  1051,  1051,   587,   587,   587,   587,   392,   392,  1070,
    1070,  1070,  1070,     6, 11094, 10438, -1604,  8047,  8047,  1362,
      75,  7278,  8047,  8047,  1366,  7278,  8047,  1369,  5915,  1372,
   -1604,     3,  1375,  5915,  8047,  6108,  1360,  7278,  7278,  1223,
    1376,  1378, 11115,  1379,  1234,  1383,  1384, 11136,  1237,  1386,
    1387,  8047, 11157,  7216,  1190, -1604, -1604, -1604, 11178, 11199,
    8047,  5634,  1393,  1392, 11220,  1201, 11619,  1199,  1205, 11619,
    1203,  1206, 11619,  1204,  1210, 11619,  1217, 11241, 11262, 11283,
     673,   677,  7278,  1218, -1604, -1604,  1900,  2434,   -91,  8047,
    8047, -1604, -1604,  1219,  1220,  7020,  9430,  9456,  9482,  9170,
     851,   -91,  2681, 11304,  7427, 11325, 11346, 11367,  8047,  1417,
   -1604,  8047, 11388, -1604, 10461, 10484, -1604,   681,   684,   693,
   -1604, -1604, 10507, 10530,  9508, 11409, 10553,   -99, -1604, -1604,
    7278, -1604,  7278,  4962,  1224,  7278,  1226,   106,  1225,  7685,
    1228,  1229,  1233, -1604,  7278, -1604,  7278, -1604,  7278, -1604,
    7278,   700, -1604, -1604,  5186,  7278,  1070, -1604, 11430, 10576,
    7278, -1604,  1418,  1433,  1434,  1240,  8047,  2828,  8047,  8047,
   -1604, -1604,    -6, -1604, -1604,  2855, -1604,  1236,  5634,  1443,
    1410,  1412,  5634,   246,  1413,  1414,  5634,   246,  7943,   703,
   -1604, -1604, 10599,   104,  2303, -1604, -1604, -1604, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604, -1604, -1604,  8047, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604,  8047,  8047,  8047, -1604,  7278,
   -1604, -1604, -1604, -1604,  5915, -1604, -1604,  5634,  5915,  5915,
    6108, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604,  8047,
    5915, -1604,  5915, -1604,  8047, -1604, -1604, -1604, -1604,  -175,
    -175,  1454, -1604,  8047,  1461,  -175,  -175,  1462,    27,  8047,
    1463,  1464,  1367, -1604,  1466,  1274,    19,  1470, -1604,  7278,
    7278,  7278,  7278, -1604,   592,  8047, -1604,  1278,  1279,  1298,
   -1604,  1477, -1604, -1604, -1604, -1604, -1604,   212,   231, 11451,
   10622, -1604, -1604,  1300,  5915,   509, 11472, 10645, -1604,   601,
    9534, -1604, -1604, -1604,    51, -1604, -1604,  6982,   592,   -91,
    4962, -1604,   833,  5634,  5634,  1496,  5634,   834,  5634,  5634,
    1498,  1420,  5634,  5634,  1512,  1500,  1501,  7278,  1502,  1506,
    3502, -1604, -1604,  1508, -1604,  1514,   188,  8047,   188,  8047,
     188,  8047,   188,  8047,  1517,  1519,  1521,  1522,  1523,   716,
    1515,  3048, -1604, -1604,   136,  9560,  9586, -1604, -1604,  8305,
    -143,   -91,   -91,   -91,  1527,  7986,  1326,  1528,  1334,    26,
      28,    37,    38,    -9, -1604,   223, -1604,   851,  1529,  1531,
    1534,  1538,  1554, 11619, -1604,  1594,  1356,  1557,  1558,  1560,
    1483,  1561,  1563,  1564,  8047,   -99,   199,   727,   730, -1604,
     736, -1604, -1604,  8047, -1604,  8047,  8047,  8047,   739,   740,
     757,   763, -1604,  8047,   769,   -99,   -99,   778,  5634,  5634,
    5634,  1568,  9612, -1604,  5374,   298,  1569,  1570, -1604,  5634,
    1368, -1604,  -175,  -175,  1571,  8047,  1572,  -175,  -175,  1573,
    8047,  1575, -1604,   592,  1588, -1604,  1591, -1604,  1590,  6982,
    6982,  6982,  6982,   618,  1399,  1405,  1406,  1409,  1407,   653,
     659, 11493,  1411,   592,  6982,  2802,  5915, -1604,  2199, -1604,
    2802,  5915, -1604,   257,  1415,  1607,  2830, -1604, -1604, -1604,
      19,  8047, -1604,   779, -1604,   783,   787,   806,   810,   188,
   11619,  1416,  8047,  8047,  5634,  1419, -1604, -1604, -1604, -1604,
    1421, -1604,  1610,    80, -1604, -1604,  1614,  8047,  4775,  1422,
    1424,  1615,  1624,    66,  1425,  1432,  1550,  1550,  5634,  1639,
    1440,  1441,  1643,  1645,  5634,  1446,  1648,  1649, -1604,  1612,
    5634,   836,  5634,  5634,  1655,  1654, -1604,  5634,  5634, 11619,
    5634, 11619,  5634, 11619,  5634, 11619,  5634,  5634,  5634,  1455,
    1460,  1660,   525, -1604,  8047,  8047,  8047,  1465,  1467,  -100,
     -80,   -61,  1475, -1604,  3138,  5634, -1604,  8047, -1604,  1671,
   -1604,  1672, -1604,  1673, -1604,  1674, -1604, -1604,  7020,   775,
    5436, -1604,  1478,  1479,  6624, -1604,  7278, -1604, -1604, -1604,
    1480,  8047, -1604, -1604, 10668,  1683,   592,  1488,  1487,  9638,
    9664,  9690,  9716, -1604, -1604, -1604, -1604, 11619, -1604,   592,
    1684,  1700,  1566, -1604,  8047,  8047,  8047, -1604,  1707,   606,
    1510,  1710,  2802,  5915, -1604,  3211, -1604,  2802,  5915, -1604,
    3345, -1604,   188, -1604,   269, -1604, -1604, -1604, -1604, -1604,
   -1604,  5915, -1604, -1604, -1604,  6108,  1705, -1604, -1604,     7,
   -1604, -1604, -1604, -1604, -1604, -1604,  1711,   492,   492, -1604,
    1712,   492,   492,  6108,  8047,  1713,  1716,    24, -1604,  1715,
   10691,    19, -1604,  1720,  1721,  1722,  1723,  5634,  8047,  9742,
    9768,   840, -1604,  8047,  1726, -1604, -1604,  5915, -1604,  9794,
    4379, 11619, -1604,  1727,  1728, -1604, -1604, -1604,  8047,  8047,
     -91,  1736,  1738,  1741, -1604,  8047,  8047, -1604, -1604,  1752,
    8047, -1604, -1604,  1755,  1756,  1555,  1757,  1621,  8047, -1604,
    1764,  1765,  1782,  1783,  1785,  1787,   922,  1788,  7278,  7278,
    8047, -1604,  7086,  8333, 11514,  6166,   451,   451,   -91,  1789,
     -91,  1790,   -91,  1791,  8047, -1604,   441,  1567, 11535, -1604,
   -1604, -1604, -1604,  8361,   225, -1604,  1792,  3926,  1793,  5634,
     -91,  3926,  1794,   844,  8047,  3608,  1796,   -99, -1604, -1604,
   -1604,  8047,  8047,  8047,  8047, -1604, -1604, -1604,  5634,  6364,
     469, 11556, -1604, -1604,  4842,  5634, -1604,  1798,   492,   492,
   -1604,  1799,   492,   492, -1604,  5634, -1604,  1606,   592,  4577,
    5040,  6108, -1604,  1804,  1806, -1604,  1808,  1809,  1811,  3648,
   -1604,  1812,  1839, -1604,  1644, -1604, -1604, -1604, -1604, -1604,
    1840,   624, 11619,  8047,  8047,  5634,  1646,   881, 11619, -1604,
    1844,  8047, -1604, -1604,  1651,  1652,  8389,  8417,   650, -1604,
   -1604, -1604,  8445,  8473, -1604,  8501,  1846, -1604,  5634, -1604,
    1778,  1855, 11619, -1604, -1604, -1604, -1604, -1604, -1604,  1656,
   -1604, -1604,   886,   889,  9143,  4328,  1857,  1658, -1604,  8047,
   -1604,  1661,  1662,   254, -1604,  1664,   258, -1604,  1667,   261,
   -1604,  1668, 10714,  1869,  5634,  1878,  1685,  8047, -1604,  6822,
     271, -1604,   893,   328,   340, -1604,  1884,  8529, -1604, -1604,
    9820,  9846,  9872,  9898,  1758,  8047, -1604,  8047, -1604, -1604,
    7278,  4516,  1891,  1692, -1604,  1895,  1896, -1604,  1897,  1898,
    1901, -1604, -1604,  4174, -1604, -1604,  5915, 11619, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604, -1604,    19, -1604,  1763, -1604,
   -1604,  8047,  9924,  9950, -1604,  5634,  8047,  1902, -1604,  9976,
   -1604, -1604,  5634,  5634,  1903,  1904,  1912,  1917,  1923,  1926,
     903,  1729, -1604,  5634,    -5,   238,  7278, -1604, -1604,   451,
    6562, -1604, -1604,  7020,   851,  7020,   851,  7020,   851,  1927,
   -1604,   921,  5634, -1604,  8557,   -91,  1928,  7278,   -91, -1604,
   -1604,  8047,  8047,  8047,  8047,  8047,  8585,  8613,   925, -1604,
   -1604,  1930, -1604, -1604, -1604, -1604, -1604,   930,  2101,   933,
    1931, -1604,  1733, 11619,  8047,  8047,   941, 11619, -1604,  8047,
     949,   954, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604,
    1734,  8047,   957,  1739,   -91,  5634,  1938,  1744,   -91,  1945,
     966,  1749,  8047, -1604,  8641,   365,   934,  8669,   371,   991,
    8697,   374,  1048, -1604,  5634,  1951,  1860,  3149,  1759,   377,
   -1604,   973,   382, 10002, 10028, 10054, 10080,  4537, -1604, -1604,
    1956, -1604,  8047, -1604,  6108, -1604, -1604,  8047, 11577, 10106,
      43, 10132, -1604, -1604, -1604, -1604,  8047,  8725,  1957,   -91,
      68, -1604, -1604,   -91,    71, -1604,  1958, -1604,  8753,  1960,
    8047,  1962,  1963,  8047,  1964,  1965,  8047,  1966,  1767, -1604,
    8047, -1604,   851, -1604,  7278,  1969,  6822,  8047,  8047,  8047,
    8047, -1604, -1604,  3082, -1604,   989, -1604,  8047, -1604,  5634,
    8047,   995,   996, 10158, -1604, -1604,   384, -1604,   430, -1604,
   -1604, -1604, -1604,  1770,  8781, -1604, -1604,  1771,  8809, -1604,
   -1604,  1784,  8837, -1604,  1982,  4942,  1291,  3974,  1001, -1604,
     474,  1002, 10184, 10210, 10236, 10262,  6108,  1985,  1786, 11598,
    1005,  8865, -1604, -1604,  8047,   -91,   -91,   851,  1990,   851,
    1998,   851,  1999, -1604, -1604, -1604, -1604,   851,  2000,  7278,
    2002,  8047,  8047,  8047,  8047, -1604, -1604,  5915, -1604,  1803,
    2005,  8893,   484,   491,  1335, -1604,  1813,  1373, -1604,  1817,
    1507, -1604,  1818,  1536, -1604,  1008, -1604, 10288, 10314, 10340,
   10366,  1009, -1604,  1820,  5634, -1604,  2009,  8047,  8047,  2011,
     851,  2012,   851,  2021,   851, -1604,  2022,  8047,  8047,  8047,
    8047,  5915,  2023,  5915,  1016, -1604,  8921,  8949, -1604,  1611,
   -1604,  1766, -1604,  1826, -1604,  8977,  9005,  9033,  9061, -1604,
   -1604,  1021, -1604,  2024,  2025,  2026,  2028,  2029,  2030, -1604,
   -1604, -1604, -1604,  5915,  2034, -1604, -1604, -1604, -1604, -1604,
   -1604, -1604, -1604
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,   265,   266,     0,     0,     0,
     260,     0,     0,     0,     0,   362,   363,   364,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   550,     0,
     411,   549,   519,   412,   414,   415,   413,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,   540,   523,   419,
     420,   421,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   416,   417,   418,   522,     0,     0,     0,     0,
      66,    67,     0,     0,   205,     0,     0,     0,   369,     0,
     511,   550,   426,     0,     0,     0,     0,   245,     0,   247,
     248,   243,   244,     0,   249,   250,   123,   135,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   448,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   549,     0,   205,   550,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
     549,   466,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,   489,   459,   465,     0,   460,   550,   426,     0,
       0,     0,     0,   549,     0,     0,   505,     0,     0,     0,
       0,   241,   242,     0,   549,     0,     0,   258,   259,     0,
     205,     0,   205,   549,     0,   550,     0,   365,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   372,   371,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,   203,     0,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   234,     0,     0,   434,   182,     0,   549,     0,   511,
     550,   512,     0,     0,   545,     0,   121,   121,     0,     0,
       0,     0,   499,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   327,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   205,     0,   450,   449,     0,     0,     0,
       0,   205,   205,     0,     0,     0,     0,     0,     0,     0,
     276,     0,   205,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,   223,   360,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,     0,   472,     0,     0,   473,     0,   474,     0,   475,
       0,     0,     0,     0,     0,     0,   371,   467,     0,   461,
       0,     0,     0,   337,    66,    67,     0,   240,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,   262,
     261,   228,     0,   229,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,     0,   370,
      59,    60,     0,     0,    59,     0,     0,     0,     0,     0,
     200,     0,     0,     0,     0,   206,     0,     0,     0,   387,
     386,   384,   385,   380,   382,   381,   383,   375,   374,   376,
     377,   378,   379,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,   357,   358,     0,     0,
       0,     0,   325,     0,     0,     0,   150,   151,     0,   153,
     154,     0,   156,   157,     0,   159,   160,     0,     0,     0,
       0,     0,     0,     0,   170,   205,     0,     0,     0,     0,
       0,   452,   451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,     0,
     340,     0,     0,   224,     0,     0,   220,     0,     0,     0,
     355,   354,     0,     0,     0,     0,     0,   439,    68,    69,
       0,   490,     0,     0,     0,     0,     0,   426,     0,     0,
       0,     0,     0,   476,     0,   477,     0,   478,     0,   479,
       0,     0,   370,   462,   469,     0,   376,   468,     0,     0,
       0,   491,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   264,     0,   230,   232,     0,   551,     0,     0,     0,
      59,    60,     0,     0,    59,    60,     0,     0,     0,     0,
      90,    74,     0,   428,   427,   441,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   410,   398,     0,   400,   401,
     402,   403,   404,   405,   406,     0,     0,     0,   532,     0,
     537,   528,   529,   530,     0,   542,   541,     0,     0,     0,
       0,   533,   534,   535,   447,   539,   139,   144,   113,     0,
       0,   524,     0,   526,     0,   424,   431,   432,   520,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   433,     0,
       0,     0,     0,   547,     0,     0,    44,     0,     0,     0,
      57,     0,    35,    36,    37,    38,    39,   430,   429,     0,
       0,   517,    24,    22,     0,     0,     0,     0,    25,     0,
       0,   235,   546,    70,   124,    71,   136,     0,     0,     0,
     501,   502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     323,   328,   326,     0,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   233,     0,     0,     0,   195,   197,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,     0,   267,     0,     0,     0,
       0,     0,     0,   330,   339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   428,   427,     0,     0,   494,
       0,   493,   492,     0,   471,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,   430,   429,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,   227,     0,
       0,   366,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,   436,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    88,
       0,     0,    76,     0,     0,     0,     0,    80,   103,   105,
       0,     0,   509,     0,   111,     0,     0,     0,     0,     0,
     388,     0,     0,     0,     0,     0,    30,   438,   437,   515,
     513,    23,     0,     0,   516,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,     0,
       0,     0,     0,     0,     0,     0,   334,     0,     0,   152,
       0,   155,     0,   158,     0,   161,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   311,     0,     0,   310,     0,   317,     0,
     319,     0,   313,     0,   315,     0,   277,   306,     0,     0,
       0,   218,     0,     0,     0,   341,     0,   222,   221,   361,
       0,     0,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   481,   482,   483,   470,   464,     0,
       0,     0,     0,   506,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,    85,     0,    89,     0,     0,    77,
       0,    81,     0,   237,   440,   236,   399,   407,   408,   409,
     538,     0,   444,   445,   446,     0,     0,   423,   140,     0,
     544,   145,   443,   525,   527,   425,     0,     0,     0,    86,
       0,     0,     0,    59,     0,     0,     0,     0,    78,     0,
       0,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   457,     0,     0,    26,    27,     0,    28,     0,
       0,   125,   132,     0,     0,    72,    73,   166,     0,     0,
       0,     0,     0,     0,   169,     0,     0,   185,   186,     0,
       0,   171,   192,     0,     0,     0,     0,   162,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,   205,   205,     0,   287,
       0,   289,     0,   291,     0,   312,   459,     0,     0,   318,
     320,   314,   316,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   497,   496,
     495,     0,     0,     0,     0,   498,   174,   175,     0,     0,
       0,     0,   114,   118,     0,     0,   367,     0,     0,     0,
      87,     0,     0,     0,    79,     0,   442,     0,     0,     0,
       0,     0,    97,     0,     0,    91,     0,     0,     0,     0,
     108,     0,     0,   109,     0,   510,   207,   208,   209,   210,
       0,     0,    40,     0,     0,     0,     0,     0,    42,   518,
       0,     0,   126,   133,     0,     0,     0,     0,   165,   172,
     173,   177,     0,     0,   187,     0,     0,   335,     0,   180,
       0,     0,   324,   191,   167,   179,   190,   194,   178,     0,
     188,   193,     0,     0,     0,     0,     0,     0,   456,     0,
     455,     0,     0,     0,   278,     0,     0,   279,     0,     0,
     280,     0,     0,     0,     0,     0,     0,     0,   217,     0,
       0,   216,     0,     0,     0,   211,     0,     0,   338,    33,
       0,     0,     0,     0,     0,     0,   504,     0,   255,   254,
       0,     0,     0,     0,    98,     0,     0,    92,     0,     0,
       0,   531,   536,     0,   141,   143,     0,   146,   147,   148,
      99,   101,    93,    95,   104,   106,     0,   112,     0,    82,
      45,     0,     0,     0,   458,     0,     0,     0,    29,     0,
     139,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,     0,   331,   331,     0,   119,   120,   205,
       0,   198,   199,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,   205,     0,     0,     0,     0,     0,   202,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,     0,   100,   102,    94,    96,    83,     0,   499,     0,
       0,   508,     0,    41,     0,     0,     0,    43,    58,     0,
       0,     0,   130,   128,   349,   351,   350,   352,   353,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   454,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,   272,     0,     0,
     212,     0,     0,     0,     0,     0,     0,     0,   503,   256,
       0,   368,     0,   142,     0,   149,   110,     0,     0,     0,
       0,     0,   127,   134,   139,   139,     0,     0,     0,     0,
       0,   332,   342,     0,     0,   343,     0,   196,     0,   293,
       0,     0,   295,     0,     0,   297,     0,     0,     0,   308,
       0,   268,     0,   205,     0,     0,     0,     0,     0,     0,
       0,   176,   117,     0,   137,     0,    49,     0,    55,     0,
       0,     0,     0,     0,   163,   189,     0,   346,     0,   347,
     348,   453,   281,     0,     0,   288,   282,     0,     0,   290,
     283,     0,     0,   292,     0,     0,     0,   274,     0,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   129,     0,     0,     0,     0,   299,     0,
     301,     0,   303,   309,   321,   273,   269,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    46,     0,    53,     0,
       0,     0,     0,     0,     0,   284,     0,     0,   285,     0,
       0,   286,     0,     0,   219,     0,   213,     0,     0,     0,
       0,     0,    47,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,     0,     0,   294,     0,
     296,     0,   298,     0,   214,     0,     0,     0,     0,    48,
      50,     0,    51,     0,     0,     0,     0,     0,     0,   484,
     485,   486,   487,     0,     0,    56,   344,   345,   300,   302,
     304,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1604, -1604, -1604, -1604,   848, -1604, -1604, -1604, -1604,   277,
   -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604,
   -1604, -1604,  -327,   -27,  1703,  3019, -1604,  1589, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604, -1603, -1604,   406, -1604, -1604,
   -1604, -1604, -1604, -1604,   841,  2042,    32,  -496,  -259, -1604,
   -1604, -1604, -1604, -1604, -1604, -1604,  2046, -1604, -1604, -1604,
   -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604, -1604,
    -880, -1049, -1604, -1604,  1565, -1604,   395, -1604, -1604, -1604,
   -1604,  1702, -1604, -1604,   890, -1604, -1447,  2337,   510,  -134,
    2209,  -246,   697, -1604,   215,    49, -1604,  -352,    -3,   120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   984,    91,    92,   703,  1511,  1517,
     972,  1181,  1702,  1911,   973,  1858,  1951,   974,  1913,   975,
     976,  1185,   351,   444,   186,   821,    93,   721,   456,  1640,
    1775,  1774,  1641,   457,  1697,  1149,  1338,  1150,  1341,   755,
     758,   761,   764,  1541,  1391,   685,   301,   420,   421,    96,
      97,    98,    99,   100,   101,   102,   302,  1067,  1802,  1877,
     790,  1565,  1568,  1571,  1833,  1837,  1841,  1896,  1899,  1902,
    1063,  1064,  1225,  1023,   752,   799,  1726,   104,   105,   106,
     107,   303,   188,   926,   506,   259,  1371,   304,   305,   306,
     570,   315,   957,  1173,   454,   449,   927,   455,   335,   308
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,  1116,  1582,   191,   501,   532,   520,   324,   353,   216,
     966,  1490,   275,   414,  1267,   783,   784,   552,   535,   555,
     557,   221,   216,   313,   208,   559,   209,   638,   955,   640,
     329,  1163,  1258,   221,  1260,    95,   331,  1710,   833,   835,
     837,   839,   653,  1262,  1264,   337,   509,   510,   197,  1818,
     280,   818,   281,   819,   278,   190,   317,   820,  1198,   267,
     250,   212,   307,   262,  1248,   710,   263,   278,   213,   264,
     711,   592,  1387,   594,  1827,   251,   252,  1829,   278,   463,
       4,   982,   352,   668,   463,   672,  1376,   675,   463,   509,
     510,  1650,  1054,   349,   350,   463,   349,   350,   254,   255,
    1723,  1724,   942,  1055,  -512,  1428,  1725,  1429,   256,   509,
     510,  1056,  1057,  1058,     5,   257,   344,  1059,  1060,  1061,
    1062,   349,   350,   109,   282,  1430,   192,  1431,   509,   510,
     325,   328,  -517,   268,   509,   510,   523,   269,   967,   968,
     969,   970,   666,   524,  1432,   340,  1433,   341,   670,   270,
     778,   415,   416,   442,   342,   443,  1259,   553,  1261,   556,
     558,   276,   342,  1491,   567,   560,   463,  1263,  1265,  1164,
    1165,  1821,  1822,   246,   254,   255,   247,   279,    89,   212,
     278,   870,   194,    89,   256,   674,   959,  1269,  1706,   874,
     316,   265,   450,   450,    89,   942,   285,  1117,  1266,   286,
     450,   326,   533,   354,   217,   355,  1722,   356,   278,   185,
     307,   218,   185,   971,   277,   307,   419,   217,   554,   307,
    1267,   189,   307,   222,   960,   314,   307,   307,   307,   307,
     956,   330,   307,   307,   307,   961,   199,   332,   338,   834,
     836,   838,   840,   776,   777,   339,   307,   278,   198,  1819,
    1199,   318,  1200,   942,   193,   509,   510,   509,   510,   458,
     509,   510,   983,   792,  1353,   509,   510,   983,   307,   307,
     307,   345,   346,   347,   348,   225,   872,   224,   876,   509,
     510,   785,   307,   307,   962,   345,   346,   347,   348,   463,
     349,   350,   509,   510,   200,   307,   511,   307,   948,   349,
     350,   349,   350,   417,   349,   350,  1306,   195,  1092,   512,
    -515,   667,   346,   347,   348,   451,   451,   671,   346,   347,
     348,   509,   510,   451,   857,   509,   510,   567,   509,   510,
     595,   459,   596,   450,   548,   307,   307,   791,   865,   185,
     201,  1244,   943,  1727,  1728,   522,   949,   196,   307,  1725,
     871,   346,   347,   348,   345,   346,   347,   348,   875,   346,
     347,   348,   463,   463,   345,   346,   347,   348,   202,   818,
     316,   819,  1860,   349,   350,   850,   450,   450,   450,   450,
     450,   450,   450,   450,   307,   450,   450,   676,   450,   450,
     450,   450,   450,   609,   349,   350,   450,   450,   450,   450,
     450,   278,  1285,   278,   463,   463,   463,   349,   350,   203,
     448,   452,   509,   510,   509,   510,   824,   826,  -516,   271,
     307,   272,   345,   346,   347,   348,   349,   350,  1268,   719,
    1577,   463,   720,   345,   346,   347,   348,  -514,   847,   204,
     581,   349,   350,   509,   510,   185,   656,   509,   510,   571,
     509,   510,   349,   350,   664,   418,   451,   206,   307,  1663,
     509,   510,   205,  1665,   349,   350,  1667,  1934,   235,   722,
     228,   236,   720,   237,   463,  -518,  1675,  1597,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   243,   307,   307,   244,   439,   245,  1307,   451,
     451,   451,   451,   451,   451,   451,   451,   207,   451,   451,
     214,   451,   451,   451,   451,   451,  1041,   509,   510,   451,
     451,   451,   451,   451,   663,   574,   665,   575,   215,   509,
     510,  1421,  1422,  1677,   342,   307,   307,   307,   757,   760,
     763,   766,   219,   419,   419,  1678,  1125,   307,   307,   220,
    1130,   600,   424,   223,   509,   510,    48,    49,    50,    51,
     509,   510,   307,   509,   510,    56,   509,   510,    59,   307,
    1790,   509,   510,   509,   510,   706,  1793,   463,   550,  1796,
     551,   463,  1804,   436,   437,   438,   714,  1806,   885,  1865,
     439,   715,   224,   847,  1001,   639,   226,   641,   642,   643,
     644,   645,   227,   647,   648,   307,   650,   651,   652,   728,
     654,   729,  1473,  1474,   658,   659,   660,   661,   662,   509,
     510,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   572,   437,   438,  1866,   233,   239,   463,   439,
     240,   230,   944,   241,   231,   242,   950,   232,  1573,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   509,   510,   307,   707,   439,   708,   307,
     709,   827,   717,   509,   510,   185,  1598,   718,   924,  1879,
     509,   510,   728,   718,   734,   229,   463,  1267,   463,  1917,
    1267,   463,   818,  1267,   819,   238,  1918,   718,   234,  1228,
     463,  1230,   463,  1232,   463,  1234,   463,   248,   307,  1193,
    1172,   463,   307,   249,   728,   450,   463,   818,   278,   819,
     450,   253,   909,   951,   307,   307,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     480,   481,   482,   261,   439,   485,   486,   487,   307,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   598,   546,   599,   547,   439,   548,   307,
     273,   184,   342,   185,   998,   463,   434,   435,   436,   437,
     438,   528,   529,   274,  1736,   439,  1739,   283,  1742,   712,
     885,   713,   818,   284,   819,   541,   542,  1267,   342,   561,
     287,  1196,   562,  1347,  1348,   563,   728,   564,  1351,  1352,
     818,   818,   819,   819,   310,   932,   934,   307,   818,   307,
     819,   288,   307,   728,  1630,   463,   463,   463,   463,  1631,
     728,   307,   738,   307,   289,   307,  1354,   307,   451,   509,
     510,   994,   307,   451,   928,  1267,  1126,   307,  1267,   309,
    1131,  1267,  1367,   818,  1267,   819,  1135,  1137,  1336,   818,
     728,   819,   744,   311,  1339,   307,   728,   312,   843,   307,
     868,   319,   869,   307,   320,   728,  1054,   964,   728,   321,
    1037,   450,   728,   463,  1038,   322,   728,  1055,  1079,   728,
    1267,  1080,  1267,   323,  1267,  1056,  1057,  1058,   728,   336,
    1081,  1059,  1060,  1061,  1062,   728,   307,  1102,   728,   382,
    1133,   450,   383,   384,   307,   450,   450,  1204,  1210,  1205,
    1211,   728,  1846,  1241,  1359,   387,  1549,   450,  1550,   450,
    1561,  1562,   728,   992,  1286,   728,   388,  1287,   996,   258,
     260,   728,   266,  1288,   728,   728,  1293,  1294,   389,   394,
    1187,  1188,  1054,   278,   398,   399,   307,   307,   307,   307,
    1478,  1479,   728,  1055,  1295,  1482,  1483,   400,   728,  1148,
    1296,  1056,  1057,  1058,   728,   401,  1298,  1059,  1060,  1061,
    1062,   450,  1445,   728,  1361,  1299,  1362,  1894,   728,  1897,
    1363,  1900,   728,   404,  1364,  1485,   405,  1903,     7,     8,
     307,   307,   406,   307,   451,   307,   307,   467,   422,   307,
     307,   728,   441,  1365,   307,   728,   445,  1366,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   423,   440,   451,  1054,   439,   478,   451,   451,
    1939,   728,  1941,  1405,  1943,  1515,  1055,  1516,   472,   728,
     451,  1586,   451,   477,  1056,  1057,  1058,   483,  1135,  1137,
    1059,  1060,  1061,  1062,   681,    24,    25,   682,    27,    28,
     683,    30,   684,    32,   484,    33,   316,   488,  1187,  1188,
      38,    39,   489,    41,    42,    43,  1636,   490,  1637,    46,
     491,   728,  1054,  1654,   728,   492,  1655,   493,  1515,  1138,
    1676,   494,   499,  1055,   451,   307,   307,   307,  1515,   495,
    1720,  1056,  1057,  1058,   496,  1505,   307,  1059,  1060,  1061,
    1062,   502,   503,    67,    68,    69,  1744,   525,  1745,  1144,
     728,   526,  1760,  1146,  1147,  1762,  1355,  1763,   718,   527,
    1765,  1791,   463,   504,   505,  1152,  1515,  1153,  1770,  1054,
     514,   513,   450,   450,  1336,   521,  1772,   450,   450,  1339,
    1055,  1773,  1515,  1731,  1778,   515,   516,   278,  1056,  1057,
    1058,   728,   534,  1786,  1059,  1060,  1061,  1062,   728,   531,
    1805,   307,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   806,  1636,   342,  1857,   439,  1794,  1192,
    1336,  1336,  1862,  1863,   536,   307,   728,   728,  1878,  1880,
    1515,   307,  1889,   728,  1931,  1926,  1932,   307,   537,   307,
     307,  1515,   573,  1953,   307,   307,  1963,   307,  1964,   307,
     538,   307,   539,   307,   307,   307,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   540,   543,  1382,   544,   439,
     545,   577,   307,   584,   185,  1797,   583,   589,   590,   591,
     593,   607,   608,   611,  1699,   612,   615,   307,   439,   677,
     678,   307,   680,   307,   184,   451,   451,   724,   725,   741,
     451,   451,   745,   746,   463,   463,   747,   773,   750,   751,
     316,   774,   775,   798,   800,   828,   801,  1486,   803,   810,
     811,   817,   830,   831,   832,   855,   858,   866,   880,   450,
     450,   867,   881,   463,   450,   450,   912,   463,   913,   914,
     917,   938,   918,   931,   110,   333,   919,   929,   450,   930,
     113,   114,   115,   936,   937,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   278,   939,
     940,   953,   945,   946,   307,   954,   981,   999,  1002,   147,
     148,   149,   988,  1169,   450,   991,   154,   307,   993,  1007,
    1700,   995,  1011,  1003,  1488,  1004,  1006,   159,   160,   161,
    1008,  1009,  1054,  1012,  1013,   162,  1017,  1022,  1024,   781,
     782,  1026,  1498,  1055,  1027,  1028,  1030,   505,  1029,  1031,
    1032,  1056,  1057,  1058,  1747,   307,   307,  1059,  1060,  1061,
    1062,  1040,  1033,  1074,  1089,  1108,  1047,  1048,  1091,  1523,
    1486,  1093,   451,   451,  1095,  1096,  1054,   451,   451,  1097,
    1109,  1110,  1119,  1111,   307,   567,   307,  1055,   307,  1121,
    1122,   451,  1123,  1127,  1128,  1056,  1057,  1058,   419,   419,
    1157,  1059,  1060,  1061,  1062,   307,   463,  1159,  1162,  1167,
    1168,  1556,   307,  1170,  1054,  1171,  1174,  1182,  1183,   463,
     165,   316,   307,  1186,   169,  1055,   307,  1191,   170,   171,
     172,   173,   174,  1056,  1057,  1058,    89,   451,  1875,  1059,
    1060,  1061,  1062,  1208,  1184,  1214,  1215,  1219,  1220,  1222,
     177,   178,   307,  1223,  1226,   179,     7,     8,  1218,  1242,
     299,  1227,   463,  1602,  1236,   183,  1237,   497,  1238,  1239,
    1240,  1252,  1255,  1257,  1256,   307,  1270,  1271,  1615,  1618,
    1619,  1272,  1919,   463,  1847,  1273,  1487,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,  1274,  1276,  1277,  1278,   439,  1279,  1280,  1281,  1282,
    1283,   307,  1303,  1308,  1309,  1311,   307,  1314,  1316,  1319,
    1921,  1321,   681,    24,    25,   682,    27,    28,   683,    30,
     684,    32,  1520,    33,  1323,  1324,  1325,   307,    38,    39,
    1275,    41,    42,    43,  1331,  1332,  1333,    46,  1054,  1334,
     307,  1343,  1335,   450,  1357,  1368,  1375,  1403,  1356,  1055,
    1378,  1385,  1383,   278,  1374,  1373,  1384,  1056,  1057,  1058,
    1386,  1388,   307,  1059,  1060,  1061,  1062,  1054,  1389,   307,
     307,    67,    68,    69,  1390,  1394,  1395,  1396,  1055,  1397,
     307,  1398,  1400,   307,  1401,  1402,  1056,  1057,  1058,  1408,
    1409,  1418,  1059,  1060,  1061,  1062,  1419,  1420,  1044,   307,
     463,  1426,   463,  1427,   307,  1050,  1434,  1439,  1440,  1441,
    1442,  1065,     7,     8,  1449,  1450,  1454,  1457,  1459,  1460,
    1466,   419,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1467,  1468,   187,  1489,
     439,   863,  1054,  1472,  1923,  1475,  1476,  1492,  1495,  1500,
    1501,  1503,   307,  1055,   210,   211,  1506,  1507,  1508,  1509,
    1519,  1056,  1057,  1058,  1524,  1525,   451,  1059,  1060,  1061,
    1062,   307,  1529,  1925,  1530,   463,   316,  1531,   681,    24,
      25,   682,    27,    28,   683,    30,   684,    32,  1534,    33,
    1536,  1538,  1537,  1539,    38,    39,  1540,    41,    42,    43,
    1543,  1544,  1574,    46,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,  1545,  1546,
     334,  1547,   439,  1548,  1551,  1564,  1567,  1570,  1578,  1581,
    1585,   307,  1589,   307,  1604,  1607,  1611,    67,    68,    69,
    1620,   343,  1621,  1814,  1622,  1623,   307,  1624,  1956,  1626,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,  1627,  1629,  1628,   385,   386,
    1638,  1649,  1635,   390,   391,   392,   393,  1642,  1643,   395,
    1651,  1652,  1653,  1658,  1659,   396,   397,  1054,  1661,  1662,
    1664,   402,   403,  1666,  1668,  1670,   307,   864,  1055,   407,
     408,   409,   411,   413,   450,  1672,  1056,  1057,  1058,  1203,
    1679,  1673,  1059,  1060,  1061,  1062,   446,  1690,  1685,  1691,
     453,  1692,  1693,  1694,  1695,  1885,  1701,  1696,  1708,  1714,
    1715,   307,     7,     8,   460,   462,   465,   466,  1716,   468,
     462,   470,   471,  1717,   462,   474,   475,  1054,   450,  1718,
     450,   462,  1719,  1743,  1750,  1721,  1761,  1766,  1055,  1767,
    1776,  1249,  1250,  1251,  1782,  1779,  1056,  1057,  1058,   498,
    1783,  1785,  1059,  1060,  1061,  1062,  1787,  1799,   507,   508,
     450,  1800,  1812,  1825,  1830,  1803,  1832,   508,  1835,  1836,
    1839,  1840,  1843,  1957,  1844,  1849,  1867,  1869,   681,    24,
      25,   682,    27,    28,   683,    30,   684,    32,  1873,    33,
    1871,  1886,  1887,   549,    38,    39,  1895,    41,    42,    43,
     566,   568,   462,    46,  1898,  1901,  1904,   451,  1906,  1914,
     576,  1915,   578,   579,   580,  1935,   582,  1938,  1940,  1920,
     585,   586,   587,  1922,  1924,   588,  1933,  1942,  1944,  1950,
    1965,  1966,  1967,  1958,  1968,  1969,  1970,    67,    68,    69,
    1972,  1377,   604,   606,  1815,    94,   723,  1711,  1392,   103,
    1729,   451,   753,   451,  1502,     0,   613,   614,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,     0,     0,   451,     0,     0,     0,     0,     0,     0,
       0,     0,   649,     0,     0,     0,     0,     0,   655,     0,
     657,     0,  1912,     0,     0,     0,     0,  1042,  1764,   571,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     679,     0,     0,     0,   686,   462,     0,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,     0,     0,   704,   705,  1949,     0,  1952,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1444,     0,
       0,     0,     0,   566,     0,     0,     0,     0,     0,   732,
       0,     0,     0,     0,   737,     0,     0,     0,  1971,   742,
     743,     0,     0,     0,     0,   748,   749,     0,     0,     0,
     754,   756,   759,   762,   765,   767,   768,   769,   462,   462,
       0,     0,     0,     0,     0,  1349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   786,   787,   788,   407,
     408,   789,     0,     0,     0,   793,   794,   795,   796,   797,
       0,     0,     0,   802,     0,   804,   805,     0,     0,     0,
     462,   462,   462,     0,     0,   812,   813,   814,   815,   816,
       0,     0,   823,   823,     0,     0,   829,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   462,     0,     0,
       0,     0,     0,   844,   846,     0,   848,   849,     0,     0,
    1528,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   727,   437,   438,     0,     0,   815,   816,   439,
     848,   849,     0,     0,     0,     0,     0,   447,   112,   878,
     462,     0,     0,     0,   882,     0,     0,     0,  1563,     0,
    1566,     0,  1569,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,  1580,     0,   439,
    1583,  1584,     0,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   155,   156,   157,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   952,   163,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   979,
     980,     0,     0,   462,   986,   987,     0,   462,   990,     0,
       0,     0,   464,     0,     0,     0,   997,   469,     0,   846,
    1000,   473,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,     0,  1014,     0,     0,     7,     8,     0,     0,
       0,     0,  1020,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,   462,   175,     0,   176,    89,     0,
       0,  1045,  1046,     0,     0,     0,     0,  1049,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   349,   350,
    1073,     0,     0,  1075,     0,     0,  1136,     0,     0,  -513,
       0,     0,   681,    24,    25,   682,    27,    28,   683,    30,
     684,    32,   462,    33,   462,     0,     0,   462,    38,    39,
       0,    41,    42,    43,     0,     0,   462,    46,   462,     0,
     462,     0,   462,     0,     0,     0,     0,   462,     0,     0,
       0,     0,   462,  1735,     0,  1738,     0,  1741,  1112,     0,
    1114,  1115,   476,     0,     0,  1749,     0,     0,  1752,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1139,
       0,     0,     0,     0,     0,     0,     0,  1140,  1141,  1142,
     530,   462,     0,     0,  1780,     0,     0,     0,  1784,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1151,   687,     0,     0,     0,  1154,     0,     0,     0,
       0,  1043,  1155,  1156,     0,  1158,     0,     0,  1160,  1161,
       0,  1166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   462,   462,   462,     0,     0,  1180,     0,  1826,
       0,     0,     0,  1828,     0,   601,   602,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   610,     0,
       0,     0,     0,     7,     8,     0,  1850,     0,     0,     0,
       0,     0,     0,     0,     0,   770,   771,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
       0,     0,     0,     0,   646,     0,     0,     0,     0,  1229,
       0,  1231,     0,  1233,     0,  1235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   807,   808,   809,
       0,     0,     0,     0,     0,  1892,  1893,  1254,     0,   681,
      24,    25,   682,    27,    28,   683,    30,   684,    32,     0,
      33,     0,     0,     0,   841,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,  1284,     0,     0,     0,
       0,     0,     0,     0,     0,  1289,     0,  1290,  1291,  1292,
       0,     0,     0,     0,     0,  1297,   447,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   879,    67,    68,
      69,     0,     0,     0,     0,  1312,  1313,  1315,     0,     0,
    1317,  1318,  1320,     0,     0,     0,  1358,     0,     0,     0,
       7,     8,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   155,   156,   157,     0,     0,   158,     7,     8,     0,
       0,     0,     0,  1360,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,  1369,  1370,     0,     0,  1066,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1379,
    1381,     0,     0,     0,     0,     0,   681,    24,    25,   682,
      27,    28,   683,    30,   684,    32,     0,    33,     0,     0,
     985,     0,    38,    39,   989,    41,    42,    43,     0,     0,
       0,    46,     0,   681,    24,    25,   682,    27,    28,   683,
      30,   684,    32,     0,    33,     0,  1423,  1424,  1425,    38,
      39,     0,    41,    42,    43,     0,     0,  1436,    46,  1438,
       0,     0,   166,   167,   168,    67,    68,    69,     0,     0,
    1443,     0,     0,     0,   175,     0,   176,    89,   462,     0,
       0,  1039,     0,  1455,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,   818,     0,   819,   941,  1469,  1470,  1471,   947,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,  1087,
       0,  1088,     0,     0,  1090,  1113,     0,     0,     0,     0,
       0,     0,     0,  1098,     0,  1099,     0,  1100,     0,  1101,
       0,     0,     0,     0,  1104,     0,  1499,     0,     0,  1107,
       7,     8,  1118,     0,     0,     0,     0,     0,     0,     0,
    1512,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1021,  1856,
    1526,  1527,     0,     0,     0,     0,     0,  1532,  1533,     0,
       0,     0,  1535,     0,     0,     0,     0,     0,     0,     0,
    1542,     0,     0,     0,     0,     0,     0,     0,  1143,     0,
     462,   462,  1554,     0,  1555,     0,   681,    24,    25,   682,
      27,    28,   683,    30,   684,    32,  1572,    33,     0,     0,
       0,     0,    38,    39,  1435,    41,    42,    43,     0,   462,
       0,    46,     0,   462,     0,     0,  1587,     0,     0,     0,
       0,     7,     8,  1590,  1591,  1592,  1593,     0,  1175,  1176,
    1177,  1178,     0,     0,     0,     0,  1601,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,     0,     0,
       0,     0,  1617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1120,     0,     0,     0,  1124,
       0,     0,     0,  1129,     0,  1632,  1633,  1480,     0,     0,
       0,     0,     0,  1639,     0,     0,  1221,   681,    24,    25,
     682,    27,    28,   683,    30,   684,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,  1145,  1243,     0,     0,     0,     0,
       0,  1660,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,  1674,
     439,   566,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,  1686,     0,  1687,
       0,     0,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1698,     0,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,  1703,     0,     0,   439,     0,  1707,     0,
    1206,  1207,     0,  1209,     0,  1212,  1213,     0,     0,  1216,
    1217,  1484,     0,     0,     0,     0,  1801,     0,   462,     0,
       0,     0,     0,     0,     0,  1734,     0,  1737,     0,  1740,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
       0,     0,     0,  1753,  1754,  1755,  1756,  1757,     0,     0,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,  1768,  1769,     0,   439,
       0,  1771,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1788,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1300,  1301,  1302,     0,     0,
       0,     0,     0,     0,     0,     0,  1310,     0,     0,     0,
       0,     0,     0,     0,  1813,     0,     0,     0,     0,  1518,
       0,     0,     0,     0,     0,     0,     0,     0,  1823,     0,
       0,     0,     0,     0,     0,  1453,     0,     0,     0,     0,
       0,     0,  1834,     0,     0,  1838,     0,     0,  1842,     0,
       0,     0,  1845,     0,     0,     0,   462,     0,   462,  1852,
    1853,  1854,  1855,     0,     0,     0,     0,     0,     0,  1859,
       0,  1372,  1861,     0,     0,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1393,     0,     0,     0,     0,
       0,  1399,     0,     0,     0,     0,     0,  1404,     0,  1406,
    1407,     0,     0,     0,  1410,  1411,  1891,  1412,     0,  1413,
       0,  1414,     0,  1415,  1416,  1417,     0,     0,     0,     0,
       0,   462,     0,  1907,  1908,  1909,  1910,     0,     0,     0,
       0,     0,  1437,     0,     0,   851,     0,     0,     0,     0,
       0,     0,     0,  1224,     0,     0,     0,  1448,     0,     0,
       0,  1452,     0,     0,  1588,     0,     0,     0,     0,  1936,
    1937,     0,     0,     0,     0,     0,     0,  1552,  1553,  1945,
    1946,  1947,  1948,     0,     0,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,     0,   898,   899,   900,
     901,   902,   903,   904,  1625,     0,     0,   908,   910,   911,
       0,     0,     0,   915,   916,     0,     0,     0,     0,   921,
     922,   923,     0,   925,     0,     0,     0,     0,     0,     0,
     933,   935,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,   958,     0,
     439,     0,     0,     0,  1510,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,     0,     0,  1522,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   155,   156,
     157,     0,     0,   158,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,   163,     0,  1372,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,  1594,   439,     0,     0,  1688,
       0,     0,  1603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1610,     0,     0,     0,  1614,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,  1730,     0,     0,   165,   166,
     167,   168,   169,     0,     0,  1372,   170,   171,   172,   173,
     174,   175,     0,   176,    89,     0,  1751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   179,     0,     0,     0,     0,   180,     0,
     181,  1671,   182,   183,     0,   184,     0,   185,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     290,     0,     0,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,   571,     0,     0,     0,     0,     0,
       0,     0,  1372,     0,   147,   148,   149,     0,     0,  1712,
    1713,   154,     0,  1179,     0,     0,     7,     8,     0,     0,
    1372,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   293,     0,     0,   294,     0,  1746,
     295,     0,   296,  1848,     0,  1851,  1201,  1202,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,   681,    24,    25,   682,    27,    28,   683,    30,
     684,    32,  1781,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,  1798,     0,     0,     0,   165,     0,     0,  1905,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,   517,  1579,     0,     0,     0,
     179,     0,     0,     0,     0,   519,     0,     0,     0,     0,
     183,     0,   257,   569,     0,     0,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   572,   437,   438,
       0,     0,  1322,     0,   439,     0,  1372,     0,  1326,  1327,
    1328,  1329,  1330,     0,     0,     0,     0,     0,  1337,  1340,
       0,     0,  1344,  1345,  1346,     0,     0,   110,   290,  1350,
       0,  1876,     0,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     7,     8,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     0,
       0,  1372,   293,     0,     0,   294,     0,     0,   295,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   681,    24,    25,   682,    27,    28,   683,    30,
     684,    32,     0,    33,     0,  1458,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,  1465,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1477,     0,   165,  1657,     0,  1481,   169,     0,     0,
       0,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   461,     0,  1493,  1494,   179,     0,
    1496,  1497,     0,   299,     0,     0,     0,     0,   183,     0,
       0,   569,   110,   290,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   155,   156,
     157,     0,     0,   158,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,   163,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,  1605,  1606,     0,
       0,  1608,  1609,     0,     0,     0,     0,  1612,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,  1689,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,  1811,     0,     0,   170,   171,   172,   173,
     174,   175,     0,   176,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   298,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,   112,   183,     0,   300,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   292,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,   155,   156,   157,     0,
       0,   158,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,   163,     0,     0,   293,     0,     0,   294,     0,
       0,   295,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,   165,   166,   167,   168,
     169,     0,     0,     0,   170,   171,   172,   173,   174,   175,
       0,   176,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   298,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   333,
     112,   183,     0,  1613,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,   155,   156,   157,     0,     0,   158,
       0,   159,   160,   161,     0,   110,   333,   112,     0,   162,
     163,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,   155,   156,   157,     0,     0,   158,     0,   159,   160,
     161,     0,     0,     0,     0,     0,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,     0,
       0,     0,   170,   171,   172,   173,   174,   175,  1874,   176,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,     0,     0,     0,   179,
     571,     0,     0,     0,   299,     0,     0,     0,     0,   183,
       0,  1380,     0,     0,     0,     0,     0,     0,     0,   859,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,     0,     0,   965,   170,
     171,   172,   173,   174,   175,     0,   176,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,     0,     0,     0,   179,     0,     0,     0,
       0,   299,     0,   110,   333,   112,   183,     0,  1600,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,   155,
     156,   157,     0,     0,   158,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,   163,     0,     0,     0,     0,
       0,     0,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   727,   437,   438,     0,     0,     0,     0,
     439,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1103,     0,     0,     0,   439,   165,
     166,   167,   168,   169,     0,     0,     0,   170,   171,   172,
     173,   174,   175,     0,   176,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,     0,     0,     0,   179,     0,     0,     0,     0,   299,
       0,   110,   290,   291,   183,     0,  1616,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,  1305,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   298,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     290,  1446,   183,     0,   300,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   293,     0,     0,   294,     0,     0,
     295,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,   327,   112,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   155,   156,   157,   165,     0,   158,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,   163,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   298,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,   110,   290,     0,
     183,     0,  1447,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
       0,     0,     0,   166,   167,   168,     0,     0,     0,     0,
     159,   160,   161,     0,     0,   175,     0,   176,   162,     0,
       0,     0,   293,     0,     0,   294,     0,     0,   295,     0,
     296,   324,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   150,   151,
     152,   153,     0,     0,     0,     0,   155,   156,   157,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   165,     0,     0,     0,   169,     0,     0,
       0,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   298,     0,     0,     0,   179,     0,
       0,     0,     0,   299,     0,   110,   290,     0,   183,     0,
     300,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   292,
       0,     0,     0,     0,     0,     0,     0,   166,   167,   168,
     147,   148,   149,     0,     0,     0,     0,   154,     0,   175,
       0,   176,    89,     0,     0,     0,     0,     0,   159,   160,
     161,     0,     0,     0,     0,     0,   162,     0,     0,     0,
     293,     0,     0,   294,     0,     0,   295,     0,   296,   447,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   150,   151,   152,   153,
       0,     0,     0,     0,   155,   156,   157,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   165,     0,     0,     0,   169,     0,     0,     0,   170,
     171,   172,   173,   174,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   461,     0,     0,     0,   179,     0,     0,     0,
       0,   299,     0,   110,   290,     0,   183,     0,   565,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   292,     0,     0,
       0,     0,     0,     0,     0,   166,   167,   168,   147,   148,
     149,     0,     0,     0,     0,   154,     0,   175,     0,   176,
      89,     0,     0,     0,     0,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,     0,     0,     0,   293,     0,
       0,   294,     0,   112,   295,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   155,   156,   157,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,   165,
       0,     0,     0,   169,     0,     0,     0,   170,   171,   172,
     173,   174,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     461,     0,     0,     0,   179,     0,     0,     0,     0,   299,
       0,   110,   290,     0,   183,     0,   822,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,   166,   167,
     168,     0,     0,     0,     0,     0,   147,   148,   149,     0,
     175,     0,   176,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1559,     0,  1560,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   461,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     290,     0,   183,     0,   825,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   293,     0,     0,   294,     0,     0,
     295,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1595,
       0,  1596,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   461,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,   110,   290,     0,
     183,     0,   845,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,   293,     0,     0,   294,     0,     0,   295,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1732,     0,  1733,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,   169,     0,     0,
       0,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   298,     0,     0,     0,   179,     0,
       0,     0,     0,   299,     0,   110,   290,     0,   183,     0,
    1451,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   292,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
     161,     0,     0,     0,     0,     0,   162,     0,     0,     0,
     293,     0,     0,   294,     0,     0,   295,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,     0,   169,     0,     0,     0,   170,
     171,   172,   173,   174,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   517,  1579,     0,     0,     0,   179,     0,     0,     0,
       0,   519,     0,   110,   333,     0,   183,     0,   257,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   148,
     149,     0,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,   161,   110,
     333,   112,     0,     0,   162,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,   156,   157,     0,     0,
     158,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,   163,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,   165,
     439,     0,   818,   169,   819,     0,     0,   170,   171,   172,
     173,   174,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   517,
     518,     0,     0,     0,   179,     0,     0,     0,     0,   519,
       0,     0,     0,     0,   183,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
       0,     0,     0,   170,   171,   172,   173,   174,   175,     0,
     176,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,   110,   290,     0,     0,   299,     0,   113,   114,   115,
     183,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1016,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   461,     0,
       0,     0,   179,   110,   333,     0,     0,   299,     0,   113,
     114,   115,   183,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   148,
     149,     0,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   333,   159,   160,   161,     0,
     113,   114,   115,     0,   162,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,     0,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,   165,
       0,     0,     0,   169,  1069,     0,     0,   170,   171,   172,
     173,   174,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,     0,     0,     0,   179,     0,     0,     0,     0,   299,
     410,     0,     0,     0,   183,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
     165,     0,     0,   439,   169,     0,     0,   673,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,     0,     0,     0,     0,
     299,   110,   333,   412,     0,   183,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   333,   159,   160,   161,     0,   113,   114,
     115,     0,   162,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,     0,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,   165,     0,     0,
       0,   169,  1094,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,     0,
       0,     0,   179,     0,     0,     0,     0,   299,   603,     0,
       0,     0,   183,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,   165,     0,
       0,   439,   169,     0,     0,   862,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   179,     0,     0,     0,     0,   299,   110,
     333,   605,  1253,   183,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   333,   159,   160,   161,     0,   113,   114,   115,     0,
     162,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,     0,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,   165,     0,     0,     0,   169,
    1132,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,    -4,     1,     0,
     183,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,     0,     0,
       0,   179,     0,    -4,    -4,    -4,   299,     0,     0,    -4,
      -4,   183,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     6,     0,     0,     0,     0,    -4,     0,
       0,     7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     9,    10,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,    11,    12,    13,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,    17,    18,
       0,    19,    20,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,    63,    64,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,    66,    67,    68,    69,     0,
       0,    70,     0,    71,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    88,     0,    89,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1247,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1557,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1576,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1644,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1645,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1646,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1647,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1648,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1680,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1748,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1758,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1759,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1789,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1792,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1795,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1824,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1831,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1868,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1870,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1872,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1890,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1916,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1954,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1955,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1959,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1960,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1961,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1962,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,   597,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,   772,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,  1656,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     842,     0,     0,     0,     0,   779,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,   716,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,   779,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,   780,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,   856,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,   897,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,   905,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,   906,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,   907,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,   920,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1051,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1052,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1053,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1084,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1197,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1245,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1246,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1304,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1461,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1462,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1463,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1464,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1513,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1514,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1521,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1681,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1682,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1683,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1684,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1704,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1705,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1709,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1807,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1808,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1809,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1810,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1817,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1820,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1864,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1881,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1882,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1883,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1884,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1927,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1928,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1929,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1930,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,   877,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,   884,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     978,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1077,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1078,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1082,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1083,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,  1086,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1106,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,  1134,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1190,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1195,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
    1456,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1504,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1669,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   669,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   726,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   730,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     731,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   733,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   735,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   736,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   739,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   740,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   842,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   852,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   853,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   854,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     860,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   861,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   873,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   883,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   977,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1005,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1010,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1015,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1018,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1019,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1025,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1034,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1035,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1036,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1068,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1070,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1071,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1072,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1076,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1085,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1105,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1189,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1194,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1342,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1558,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1575,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1599,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1816,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1888,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439
};

static const yytype_int16 yycheck[] =
{
       3,     7,  1449,     6,   250,     4,   265,     4,     4,     4,
       4,     4,     4,     4,  1063,   511,   512,     5,   277,     5,
       5,     4,     4,     4,   199,     5,   201,   379,     4,   381,
       5,     4,     6,     4,     6,     3,     5,  1640,     5,     5,
       5,     5,   394,     6,     6,     6,   189,   190,     6,     6,
       4,   200,     6,   202,    57,     6,     4,   206,     7,     4,
     142,   199,    65,    78,   207,   200,    81,    70,   206,    84,
     205,   330,     6,   332,     6,   157,   158,     6,    81,   213,
       6,     6,   109,   410,   218,   412,     6,   414,   222,   189,
     190,  1538,   101,   195,   196,   229,   195,   196,   189,   190,
     105,   106,     7,   112,   206,   205,   111,   207,   199,   189,
     190,   120,   121,   122,     0,   206,     7,   126,   127,   128,
     129,   195,   196,     3,    78,   205,     6,   207,   189,   190,
      81,    82,   206,    78,   189,   190,   199,    82,   132,   133,
     134,   135,     7,   206,   205,   199,   207,   201,     7,    94,
     205,   142,   143,   199,   208,   201,   130,   145,   130,   145,
     145,   153,   208,   156,   298,   145,   300,   130,   130,   142,
     143,  1774,  1775,    81,   189,   190,    84,    57,   175,   199,
     183,     7,    84,   175,   199,     7,   206,  1067,  1635,     7,
      70,   206,   195,   196,   175,     7,    81,   203,   207,    84,
     203,    81,   201,   199,   199,   201,  1653,   203,   211,   208,
     213,   206,   208,   207,   206,   218,   184,   199,   206,   222,
    1269,     6,   225,   206,   206,   206,   229,   230,   231,   232,
     206,   206,   235,   236,   237,   206,     6,   206,   199,   206,
     206,   206,   206,   502,   503,   206,   249,   250,   206,   206,
     199,   199,   201,     7,    13,   189,   190,   189,   190,   210,
     189,   190,   187,   522,     7,   189,   190,   187,   271,   272,
     273,   176,   177,   178,   179,    88,   603,   199,   605,   189,
     190,   205,   285,   286,   206,   176,   177,   178,   179,   423,
     195,   196,   189,   190,     6,   298,   206,   300,   203,   195,
     196,   195,   196,   183,   195,   196,     8,   199,   202,   206,
     206,   176,   177,   178,   179,   195,   196,   176,   177,   178,
     179,   189,   190,   203,   583,   189,   190,   461,   189,   190,
     199,   211,   201,   336,   203,   338,   339,   205,   597,   208,
       6,   205,   669,   105,   106,   206,   673,   199,   351,   111,
     176,   177,   178,   179,   176,   177,   178,   179,   176,   177,
     178,   179,   496,   497,   176,   177,   178,   179,     6,   200,
     250,   202,  1819,   195,   196,   206,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   414,   391,   392,
     393,   394,   395,   344,   195,   196,   399,   400,   401,   402,
     403,   404,   203,   406,   538,   539,   540,   195,   196,   199,
     195,   196,   189,   190,   189,   190,   550,   551,   206,    84,
     423,    86,   176,   177,   178,   179,   195,   196,   205,   202,
     205,   565,   205,   176,   177,   178,   179,   206,   572,     6,
     203,   195,   196,   189,   190,   208,   397,   189,   190,     8,
     189,   190,   195,   196,   405,     4,   336,   201,   461,   205,
     189,   190,     6,   205,   195,   196,   205,  1914,    81,   202,
       6,    84,   205,    86,   608,   206,   205,     8,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    81,   496,   497,    84,   198,    86,   200,   379,
     380,   381,   382,   383,   384,   385,   386,   201,   388,   389,
     199,   391,   392,   393,   394,   395,   775,   189,   190,   399,
     400,   401,   402,   403,   404,   199,   406,   201,   199,   189,
     190,     6,     7,   205,   208,   538,   539,   540,   489,   490,
     491,   492,   199,   511,   512,   205,   873,   550,   551,   199,
     877,   336,     6,   199,   189,   190,   105,   106,   107,   108,
     189,   190,   565,   189,   190,   114,   189,   190,   117,   572,
     205,   189,   190,   189,   190,     6,   205,   711,   199,   205,
     201,   715,   205,   191,   192,   193,   200,   205,   615,   205,
     198,   205,   199,   727,   728,   380,    84,   382,   383,   384,
     385,   386,    84,   388,   389,   608,   391,   392,   393,   205,
     395,   207,     6,     7,   399,   400,   401,   402,   403,   189,
     190,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   205,    84,    78,   772,   198,
      81,    78,   669,    84,    81,    86,   673,    84,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   189,   190,   668,   199,   198,   201,   672,
     203,   551,   200,   189,   190,   208,   207,   205,   200,   205,
     189,   190,   205,   205,   207,   206,   820,  1736,   822,   205,
    1739,   825,   200,  1742,   202,    86,   205,   205,    84,  1026,
     834,  1028,   836,  1030,   838,  1032,   840,   199,   711,   200,
     956,   845,   715,    81,   205,   718,   850,   200,   721,   202,
     723,   206,   205,   674,   727,   728,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     230,   231,   232,   206,   198,   235,   236,   237,   751,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   199,   199,   201,   201,   198,   203,   772,
      84,   206,   208,   208,   725,   909,   189,   190,   191,   192,
     193,   271,   272,    81,  1664,   198,  1666,    81,  1668,   199,
     817,   201,   200,    84,   202,   285,   286,  1846,   208,    78,
       4,   200,    81,  1155,  1156,    84,   205,    86,  1160,  1161,
     200,   200,   202,   202,   199,   205,   205,   820,   200,   822,
     202,     4,   825,   205,   200,   959,   960,   961,   962,   205,
     205,   834,   207,   836,     4,   838,  1163,   840,   718,   189,
     190,   721,   845,   723,     6,  1894,   873,   850,  1897,     4,
     877,  1900,  1179,   200,  1903,   202,   883,   884,   205,   200,
     205,   202,   207,   199,   205,   868,   205,   199,   207,   872,
     205,   199,   207,   876,   199,   205,   101,   207,   205,     6,
     207,   884,   205,  1017,   207,     6,   205,   112,   207,   205,
    1939,   207,  1941,   201,  1943,   120,   121,   122,   205,   201,
     207,   126,   127,   128,   129,   205,   909,   207,   205,   199,
     207,   914,   199,   199,   917,   918,   919,    84,    84,    86,
      86,   205,  1802,   207,  1170,   199,     4,   930,     6,   932,
    1426,  1427,   205,   718,   207,   205,   199,   207,   723,    49,
      50,   205,    52,   207,   205,   205,   207,   207,   199,   199,
     977,   978,   101,   956,     7,   199,   959,   960,   961,   962,
    1312,  1313,   205,   112,   207,  1317,  1318,   199,   205,   920,
     207,   120,   121,   122,   205,   199,   207,   126,   127,   128,
     129,   984,   207,   205,   205,   207,   207,  1867,   205,  1869,
     207,  1871,   205,   199,   207,  1322,   199,  1877,    12,    13,
    1003,  1004,   201,  1006,   884,  1008,  1009,   199,   206,  1012,
    1013,   205,     6,   207,  1017,   205,     6,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   206,   206,   914,   101,   198,   206,   918,   919,
    1920,   205,  1922,   207,  1924,   205,   112,   207,   199,   205,
     930,   207,   932,   199,   120,   121,   122,   199,  1085,  1086,
     126,   127,   128,   129,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   199,    89,   956,   199,  1105,  1106,
      94,    95,   199,    97,    98,    99,   205,   199,   207,   103,
     199,   205,   101,   207,   205,   199,   207,   199,   205,   884,
     207,   199,     4,   112,   984,  1108,  1109,  1110,   205,   199,
     207,   120,   121,   122,   206,  1361,  1119,   126,   127,   128,
     129,   206,   206,   137,   138,   139,   205,   199,   207,   914,
     205,   199,   207,   918,   919,   205,  1163,   207,   205,   199,
     207,   207,  1276,   253,   254,   930,   205,   932,   207,   101,
     206,   261,  1155,  1156,   205,   265,   207,  1160,  1161,   205,
     112,   207,   205,  1659,   207,   206,   206,  1170,   120,   121,
     122,   205,   201,   207,   126,   127,   128,   129,   205,   199,
     207,  1184,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   207,   205,   208,   207,   198,   207,   984,
     205,   205,   207,   207,     6,  1208,   205,   205,   207,   207,
     205,  1214,   207,   205,   205,   207,   207,  1220,     6,  1222,
    1223,   205,     6,   207,  1227,  1228,   205,  1230,   207,  1232,
     206,  1234,   206,  1236,  1237,  1238,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   206,   201,  1198,   201,   198,
     201,     6,  1255,   145,   208,   207,   206,     6,     6,     6,
       6,   206,   206,     6,  1616,   201,     4,  1270,   198,   203,
       7,  1274,   207,  1276,   206,  1155,  1156,   205,   205,     7,
    1160,  1161,     6,     6,  1418,  1419,     6,   200,     7,     7,
    1170,     6,   206,     7,     6,    56,     7,  1324,     6,     6,
       6,     4,    56,    56,    56,   142,   206,   202,     6,  1312,
    1313,   200,     6,  1447,  1317,  1318,   200,  1451,   200,   205,
     205,   202,   205,   200,     3,     4,   205,   205,  1331,   205,
       9,    10,    11,   200,   200,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,  1361,    40,
      40,     6,    40,    40,  1367,     4,     4,     7,   145,    48,
      49,    50,     6,     6,  1377,     6,    55,  1380,     6,   145,
    1626,     6,   145,     7,  1335,     7,     7,    66,    67,    68,
       7,     7,   101,     7,     7,    74,   206,     4,     6,   509,
     510,   200,  1353,   112,   205,   200,   200,   517,   205,   205,
     200,   120,   121,   122,  1673,  1418,  1419,   126,   127,   128,
     129,   203,   205,     6,   200,     7,   207,   207,   202,  1380,
    1457,   206,  1312,  1313,   206,   206,   101,  1317,  1318,   206,
       7,     7,   206,   203,  1447,  1579,  1449,   112,  1451,     6,
      40,  1331,    40,    40,    40,   120,   121,   122,  1426,  1427,
       6,   126,   127,   128,   129,  1468,  1600,     6,     6,     6,
       6,  1422,  1475,     7,   101,   201,     6,   199,   199,  1613,
     159,  1361,  1485,     6,   163,   112,  1489,   187,   167,   168,
     169,   170,   171,   120,   121,   122,   175,  1377,   207,   126,
     127,   128,   129,     7,   206,     7,    86,     7,     7,     7,
     189,   190,  1515,     7,     6,   194,    12,    13,     6,     4,
     199,     7,  1656,  1474,     7,   204,     7,   206,     7,     7,
       7,     4,   206,   199,     6,  1538,     7,     6,  1489,  1490,
    1491,     7,   207,  1677,  1803,     7,  1331,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     7,   206,     6,     6,   198,     6,    84,     7,     6,
       6,  1574,     4,     4,     4,   207,  1579,     6,     6,     6,
     207,     6,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,  1377,    89,     6,     4,     6,  1600,    94,    95,
       6,    97,    98,    99,   205,   200,   200,   103,   101,   200,
    1613,   200,   205,  1616,     7,   199,     6,     5,   203,   112,
       6,     6,   200,  1626,   203,   206,   202,   120,   121,   122,
       6,   206,  1635,   126,   127,   128,   129,   101,   206,  1642,
    1643,   137,   138,   139,    94,     6,   206,   206,   112,     6,
    1653,     6,   206,  1656,     6,     6,   120,   121,   122,     4,
       6,   206,   126,   127,   128,   129,   206,     7,   778,  1672,
    1804,   206,  1806,   206,  1677,   785,   201,     6,     6,     6,
       6,   791,    12,    13,   206,   206,   206,     4,   200,   202,
       6,  1659,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     6,   141,     6,     4,
     198,   207,   101,     6,   207,   205,     6,     6,     6,     6,
       4,     6,  1725,   112,    21,    22,     6,     6,     6,     6,
       4,   120,   121,   122,     7,     7,  1616,   126,   127,   128,
     129,  1744,     6,   207,     6,  1879,  1626,     6,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     6,    89,
       5,   206,     6,     6,    94,    95,   145,    97,    98,    99,
       6,     6,   205,   103,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     6,     6,
      88,     6,   198,     6,     6,     6,     6,     6,     6,     6,
       6,  1804,     6,  1806,     6,     6,   200,   137,   138,   139,
       6,   108,     6,  1764,     6,     6,  1819,     6,   207,     7,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     6,     6,   203,   145,   146,
       6,     5,   206,   150,   151,   152,   153,   206,   206,   156,
      82,     6,   206,     6,   206,   162,   163,   101,   207,   207,
     206,   168,   169,   206,   206,     6,  1879,   207,   112,   177,
     178,   179,   180,   181,  1887,     7,   120,   121,   122,   999,
       6,   206,   126,   127,   128,   129,   194,     6,   140,   207,
     198,     6,     6,     6,     6,  1856,   143,     6,     6,     6,
       6,  1914,    12,    13,   212,   213,   214,   215,     6,   217,
     218,   219,   220,     6,   222,   223,   224,   101,  1931,     6,
    1933,   229,     6,     6,     6,   206,     6,     6,   112,   206,
     206,  1051,  1052,  1053,     6,   206,   120,   121,   122,   247,
     206,     6,   126,   127,   128,   129,   207,     6,   256,   257,
    1963,   101,     6,     6,     6,   206,     6,   265,     6,     6,
       6,     6,     6,   207,   207,     6,   206,   206,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     6,    89,
     206,     6,   206,   290,    94,    95,     6,    97,    98,    99,
     298,   299,   300,   103,     6,     6,     6,  1887,     6,   206,
     307,     6,   310,   311,   312,     6,   314,     6,     6,   206,
     318,   319,   320,   206,   206,   323,   206,     6,     6,     6,
       6,     6,     6,   207,     6,     6,     6,   137,   138,   139,
       6,  1193,   340,   341,  1767,     3,   457,  1641,  1207,     3,
    1655,  1931,   487,  1933,  1357,    -1,   354,   355,    -1,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,    -1,    -1,  1963,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,   396,    -1,
     398,    -1,  1887,    -1,    -1,    -1,    -1,   207,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     417,    -1,    -1,    -1,   422,   423,    -1,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    -1,    -1,   442,   443,  1931,    -1,  1933,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1268,    -1,
      -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,   467,
      -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,  1963,   477,
     478,    -1,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   514,   515,   516,   517,
     518,   519,    -1,    -1,    -1,   523,   524,   525,   526,   527,
      -1,    -1,    -1,   531,    -1,   533,   534,    -1,    -1,    -1,
     538,   539,   540,    -1,    -1,   543,   544,   545,   546,   547,
      -1,    -1,   550,   551,    -1,    -1,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   565,    -1,    -1,
      -1,    -1,    -1,   571,   572,    -1,   574,   575,    -1,    -1,
    1390,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   595,   596,   198,
     598,   599,    -1,    -1,    -1,    -1,    -1,     4,     5,   607,
     608,    -1,    -1,    -1,   612,    -1,    -1,    -1,  1428,    -1,
    1430,    -1,  1432,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,  1447,    -1,   198,
    1450,  1451,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    75,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,
     708,    -1,    -1,   711,   712,   713,    -1,   715,   716,    -1,
      -1,    -1,   213,    -1,    -1,    -1,   724,   218,    -1,   727,
     728,   222,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    -1,   741,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   772,   172,    -1,   174,   175,    -1,
      -1,   779,   780,    -1,    -1,    -1,    -1,   785,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     798,    -1,    -1,   801,    -1,    -1,   203,    -1,    -1,   206,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   820,    89,   822,    -1,    -1,   825,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   834,   103,   836,    -1,
     838,    -1,   840,    -1,    -1,    -1,    -1,   845,    -1,    -1,
      -1,    -1,   850,  1663,    -1,  1665,    -1,  1667,   856,    -1,
     858,   859,   225,    -1,    -1,  1675,    -1,    -1,  1678,    -1,
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,   906,   907,
     273,   909,    -1,    -1,  1724,    -1,    -1,    -1,  1728,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   929,   423,    -1,    -1,    -1,   934,    -1,    -1,    -1,
      -1,   207,   939,   940,    -1,   943,    -1,    -1,   945,   946,
      -1,   949,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   959,   960,   961,   962,    -1,    -1,   965,    -1,  1779,
      -1,    -1,    -1,  1783,    -1,   338,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    -1,    12,    13,    -1,  1806,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   496,   497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1017,
      -1,    -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,  1027,
      -1,  1029,    -1,  1031,    -1,  1033,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,   539,   540,
      -1,    -1,    -1,    -1,    -1,  1865,  1866,  1055,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    -1,   565,    94,    95,    -1,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1093,    -1,  1095,  1096,  1097,
      -1,    -1,    -1,    -1,    -1,  1103,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   608,   137,   138,
     139,    -1,    -1,    -1,    -1,  1122,  1123,  1125,    -1,    -1,
    1127,  1128,  1130,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      12,    13,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    12,    13,    -1,
      -1,    -1,    -1,  1171,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,  1182,  1183,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,
    1198,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    -1,    -1,
     711,    -1,    94,    95,   715,    97,    98,    99,    -1,    -1,
      -1,   103,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,  1244,  1245,  1246,    94,
      95,    -1,    97,    98,    99,    -1,    -1,  1255,   103,  1257,
      -1,    -1,   160,   161,   162,   137,   138,   139,    -1,    -1,
    1268,    -1,    -1,    -1,   172,    -1,   174,   175,  1276,    -1,
      -1,   772,    -1,  1281,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,   202,   668,  1304,  1305,  1306,   672,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,   820,
      -1,   822,    -1,    -1,   825,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   834,    -1,   836,    -1,   838,    -1,   840,
      -1,    -1,    -1,    -1,   845,    -1,  1354,    -1,    -1,   850,
      12,    13,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1368,    -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   751,     7,
    1388,  1389,    -1,    -1,    -1,    -1,    -1,  1395,  1396,    -1,
      -1,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,
    1418,  1419,  1420,    -1,  1422,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,  1434,    89,    -1,    -1,
      -1,    -1,    94,    95,     6,    97,    98,    99,    -1,  1447,
      -1,   103,    -1,  1451,    -1,    -1,  1454,    -1,    -1,    -1,
      -1,    12,    13,  1461,  1462,  1463,  1464,    -1,   959,   960,
     961,   962,    -1,    -1,    -1,    -1,  1474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,    -1,
      -1,    -1,  1490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   868,    -1,    -1,    -1,   872,
      -1,    -1,    -1,   876,    -1,  1513,  1514,     6,    -1,    -1,
      -1,    -1,    -1,  1521,    -1,    -1,  1017,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,   917,   207,    -1,    -1,    -1,    -1,
      -1,  1559,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,  1577,
     198,  1579,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1595,    -1,  1597,
      -1,    -1,  1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1613,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,  1631,    -1,    -1,   198,    -1,  1636,    -1,
    1003,  1004,    -1,  1006,    -1,  1008,  1009,    -1,    -1,  1012,
    1013,     6,    -1,    -1,    -1,    -1,   207,    -1,  1656,    -1,
      -1,    -1,    -1,    -1,    -1,  1663,    -1,  1665,    -1,  1667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,
      -1,    -1,    -1,  1681,  1682,  1683,  1684,  1685,    -1,    -1,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,  1704,  1705,    -1,   198,
      -1,  1709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1732,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1108,  1109,  1110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,    -1,  1767,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1776,    -1,
      -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,    -1,    -1,
      -1,    -1,  1790,    -1,    -1,  1793,    -1,    -1,  1796,    -1,
      -1,    -1,  1800,    -1,    -1,    -1,  1804,    -1,  1806,  1807,
    1808,  1809,  1810,    -1,    -1,    -1,    -1,    -1,    -1,  1817,
      -1,  1184,  1820,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,  1208,    -1,    -1,    -1,    -1,
      -1,  1214,    -1,    -1,    -1,    -1,    -1,  1220,    -1,  1222,
    1223,    -1,    -1,    -1,  1227,  1228,  1864,  1230,    -1,  1232,
      -1,  1234,    -1,  1236,  1237,  1238,    -1,    -1,    -1,    -1,
      -1,  1879,    -1,  1881,  1882,  1883,  1884,    -1,    -1,    -1,
      -1,    -1,  1255,    -1,    -1,   576,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,  1270,    -1,    -1,
      -1,  1274,    -1,    -1,     6,    -1,    -1,    -1,    -1,  1917,
    1918,    -1,    -1,    -1,    -1,    -1,    -1,  1418,  1419,  1927,
    1928,  1929,  1930,    -1,    -1,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,    -1,   628,   629,   630,
     631,   632,   633,   634,     6,    -1,    -1,   638,   639,   640,
      -1,    -1,    -1,   644,   645,    -1,    -1,    -1,    -1,   650,
     651,   652,    -1,   654,    -1,    -1,    -1,    -1,    -1,    -1,
     661,   662,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   679,    -1,
     198,    -1,    -1,    -1,  1367,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,  1380,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,  1449,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,  1468,   198,    -1,    -1,  1600,
      -1,    -1,  1475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1485,    -1,    -1,    -1,  1489,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,  1515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,  1656,    -1,    -1,   159,   160,
     161,   162,   163,    -1,    -1,  1538,   167,   168,   169,   170,
     171,   172,    -1,   174,   175,    -1,  1677,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
     201,  1574,   203,   204,    -1,   206,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1635,    -1,    48,    49,    50,    -1,    -1,  1642,
    1643,    55,    -1,   964,    -1,    -1,    12,    13,    -1,    -1,
    1653,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,  1672,
      84,    -1,    86,  1804,    -1,  1806,   997,   998,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,  1725,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,
      -1,  1744,    -1,    -1,    -1,   159,    -1,    -1,  1879,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   207,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,  1133,    -1,   198,    -1,  1819,    -1,  1139,  1140,
    1141,  1142,  1143,    -1,    -1,    -1,    -1,    -1,  1149,  1150,
      -1,    -1,  1153,  1154,  1155,    -1,    -1,     3,     4,  1160,
      -1,   207,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    12,    13,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,  1914,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,  1286,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,  1299,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1312,    -1,   159,     6,    -1,  1317,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,  1347,  1348,   194,    -1,
    1351,  1352,    -1,   199,    -1,    -1,    -1,    -1,   204,    -1,
      -1,   207,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,  1478,  1479,    -1,
      -1,  1482,  1483,    -1,    -1,    -1,    -1,  1488,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     6,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,     6,    -1,    -1,   167,   168,   169,   170,
     171,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,     5,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
      -1,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
       5,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    66,    67,    68,    -1,     3,     4,     5,    -1,    74,
      75,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,     6,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
       8,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,    -1,     8,   167,
     168,   169,   170,   171,   172,    -1,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,     3,     4,     5,   204,    -1,   206,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     8,    -1,    -1,    -1,   198,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
      -1,     3,     4,     5,   204,    -1,   206,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,     8,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,
       4,     5,   204,    -1,   206,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,     4,     5,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,   159,    -1,    64,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    75,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,    -1,
     204,    -1,   206,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,   172,    -1,   174,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,
      86,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,   159,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,
     206,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,   172,
      -1,   174,   175,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,   162,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,   172,    -1,   174,
     175,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,     5,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
      -1,     3,     4,    -1,   204,    -1,   206,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
     172,    -1,   174,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,
       4,    -1,   204,    -1,   206,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,    -1,
     204,    -1,   206,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,
     206,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,     3,
       4,     5,    -1,    -1,    74,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,   159,
     198,    -1,   200,   163,   202,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,   204,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,     3,     4,    -1,    -1,   199,    -1,     9,    10,    11,
     204,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,     3,     4,    -1,    -1,   199,    -1,     9,
      10,    11,   204,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    66,    67,    68,    -1,
       9,    10,    11,    -1,    74,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,   207,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
     200,    -1,    -1,    -1,   204,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
     159,    -1,    -1,   198,   163,    -1,    -1,   202,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,     3,     4,   202,    -1,   204,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    66,    67,    68,    -1,     9,    10,
      11,    -1,    74,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,   207,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,    -1,   204,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,   159,    -1,
      -1,   198,   163,    -1,    -1,   202,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,     3,
       4,   202,     6,   204,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    66,    67,    68,    -1,     9,    10,    11,    -1,
      74,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
     207,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     0,     1,    -1,
     204,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    56,    57,    58,   199,    -1,    -1,    62,
      63,   204,    65,    -1,    -1,    -1,    69,    70,    -1,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,   124,   125,     4,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    12,    13,   136,   137,   138,   139,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    38,    39,    -1,
      -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,   136,   137,   138,   139,    -1,
      -1,   142,    -1,   144,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,   173,    -1,   175,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   202,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,   202,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     202,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,   202,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   202,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   202,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,   202,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,   202,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   202,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,   202,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     202,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,   202,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,   202,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,   200,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,   200,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,   200,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,   200,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   210,   211,     6,     0,     4,    12,    13,    38,
      39,    56,    57,    58,    62,    63,    65,    69,    70,    72,
      73,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   112,   113,   114,   115,   116,   117,
     118,   119,   123,   124,   125,   131,   136,   137,   138,   139,
     142,   144,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   164,   165,   166,   173,   175,
     212,   214,   215,   235,   254,   255,   258,   259,   260,   261,
     262,   263,   264,   265,   286,   287,   288,   289,   307,   308,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    59,    60,    61,    64,    66,
      67,    68,    74,    75,   153,   159,   160,   161,   162,   163,
     167,   168,   169,   170,   171,   172,   174,   189,   190,   194,
     199,   201,   203,   204,   206,   208,   233,   290,   291,   303,
     304,   307,   308,    13,    84,   199,   199,     6,   206,     6,
       6,     6,     6,   199,     6,     6,   201,   201,   199,   201,
     233,   233,   199,   206,   199,   199,     4,   199,   206,   199,
     199,     4,   206,   199,   199,    88,    84,    84,     6,   206,
      78,    81,    84,    84,    84,    81,    84,    86,    86,    78,
      81,    84,    86,    81,    84,    86,    81,    84,   199,    81,
     142,   157,   158,   206,   189,   190,   199,   206,   293,   294,
     293,   206,    78,    81,    84,   206,   293,     4,    78,    82,
      94,    84,    86,    84,    81,     4,   153,   206,   307,   308,
       4,     6,    78,    81,    84,    81,    84,     4,     4,     4,
       4,     5,    37,    78,    81,    84,    86,    98,   190,   199,
     206,   255,   265,   290,   296,   297,   298,   307,   308,     4,
     199,   199,   199,     4,   206,   300,   308,     4,   199,   199,
     199,     6,     6,   201,     4,   304,   308,     4,   304,     5,
     206,     5,   206,     4,   290,   307,   201,     6,   199,   206,
     199,   201,   208,   233,     7,   176,   177,   178,   179,   195,
     196,   231,   232,     4,   199,   201,   203,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   199,   199,   199,   233,   233,   199,   199,   199,
     233,   233,   233,   233,   199,   233,   233,   233,     7,   199,
     199,   199,   233,   233,   199,   199,   201,   290,   290,   290,
     200,   290,   202,   290,     4,   142,   143,   308,     4,   255,
     256,   257,   206,   206,     6,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   198,
     206,     6,   199,   201,   232,     6,   290,     4,   303,   304,
     307,   308,   303,   290,   303,   306,   237,   242,   304,   308,
     290,   190,   290,   298,   299,   290,   290,   199,   290,   299,
     290,   290,   199,   299,   290,   290,   296,   199,   206,   299,
     297,   297,   297,   199,   199,   297,   297,   297,   199,   199,
     199,   199,   199,   199,   199,   199,   206,   206,   290,     4,
     296,   300,   206,   206,   293,   293,   293,   290,   290,   189,
     190,   206,   206,   293,   206,   206,   206,   189,   190,   199,
     257,   293,   206,   199,   206,   199,   199,   199,   297,   297,
     296,   199,     4,   201,   201,   257,     6,     6,   206,   206,
     206,   297,   297,   201,   201,   201,   199,   201,   203,   233,
     199,   201,     5,   145,   206,     5,   145,     5,   145,     5,
     145,    78,    81,    84,    86,   206,   290,   298,   290,   207,
     299,     8,   191,     6,   199,   201,   233,     6,   290,   290,
     290,   203,   290,   206,   145,   290,   290,   290,   290,     6,
       6,     6,   257,     6,   257,   199,   201,   206,   199,   201,
     303,   296,   296,   200,   290,   202,   290,   206,   206,   304,
     296,     6,   201,   290,   290,     4,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   306,   303,
     306,   303,   303,   303,   303,   303,   296,   303,   303,   290,
     303,   303,   303,   306,   303,   290,   304,   290,   303,   303,
     303,   303,   303,   308,   304,   308,     7,   176,   231,   200,
       7,   176,   231,   202,     7,   231,   232,   203,     7,   233,
     207,    78,    81,    84,    86,   254,   290,   299,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   216,   290,   290,     6,   199,   201,   203,
     200,   205,   199,   201,   200,   205,   205,   200,   205,   202,
     205,   236,   202,   236,   205,   205,   200,   191,   205,   207,
     200,   200,   290,   200,   207,   200,   200,   290,   207,   200,
     200,     7,   290,   290,   207,     6,     6,     6,   290,   290,
       7,     7,   283,   283,   290,   248,   290,   304,   249,   290,
     304,   250,   290,   304,   251,   290,   304,   290,   290,   290,
     299,   299,   206,   200,     6,   206,   257,   257,   205,   205,
     205,   293,   293,   256,   256,   205,   290,   290,   290,   290,
     269,   205,   257,   290,   290,   290,   290,   290,     7,   284,
       6,     7,   290,     6,   290,   290,   207,   299,   299,   299,
       6,     6,   290,   290,   290,   290,   290,     4,   200,   202,
     206,   234,   206,   290,   298,   206,   298,   308,    56,   290,
      56,    56,    56,     5,   206,     5,   206,     5,   206,     5,
     206,   299,   200,   207,   290,   206,   290,   298,   290,   290,
     206,   234,   200,   200,   200,   142,   205,   257,   206,     8,
     200,   200,   202,   207,   207,   257,   202,   200,   205,   207,
       7,   176,   231,   200,     7,   176,   231,   202,   290,   299,
       6,     6,   290,   200,   202,   232,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   205,   234,   234,
     234,   234,   234,   234,   234,   205,   205,   205,   234,   205,
     234,   234,   200,   200,   205,   234,   234,   205,   205,   205,
     205,   234,   234,   234,   200,   234,   292,   305,     6,   205,
     205,   200,   205,   234,   205,   234,   200,   200,   202,    40,
      40,   296,     7,   231,   232,    40,    40,   296,   203,   231,
     232,   304,   290,     6,     4,     4,   206,   301,   234,   206,
     206,   206,   206,   207,   207,     8,     4,   132,   133,   134,
     135,   207,   219,   223,   226,   228,   229,   200,   202,   290,
     290,     4,     6,   187,   213,   299,   290,   290,     6,   299,
     290,     6,   303,     6,   308,     6,   303,   290,   304,     7,
     290,   298,   145,     7,     7,   200,     7,   145,     7,     7,
     200,   145,     7,     7,   290,   200,   207,   206,   200,   200,
     290,   296,     4,   282,     6,   200,   200,   205,   200,   205,
     200,   205,   200,   205,   200,   200,   200,   207,   207,   299,
     203,   257,   207,   207,   293,   290,   290,   207,   207,   290,
     293,   205,   205,   205,   101,   112,   120,   121,   122,   126,
     127,   128,   129,   279,   280,   293,   207,   266,   200,   207,
     200,   200,   200,   290,     6,   290,   200,   202,   202,   207,
     207,   207,   202,   202,   205,   200,   202,   299,   299,   200,
     299,   202,   202,   206,   207,   206,   206,   206,   299,   299,
     299,   299,   207,     8,   299,   200,   202,   299,     7,     7,
       7,   203,   290,   207,   290,   290,     7,   203,   207,   206,
     296,     6,    40,    40,   296,   231,   232,    40,    40,   296,
     231,   232,   207,   207,   202,   232,   203,   232,   303,   290,
     290,   290,   290,   299,   303,   296,   303,   303,   304,   244,
     246,   290,   303,   303,   290,   233,   233,     6,   290,     6,
     233,   233,     6,     4,   142,   143,   290,     6,     6,     6,
       7,   201,   300,   302,     6,   299,   299,   299,   299,   234,
     290,   220,   199,   199,   206,   230,     6,   232,   232,   200,
     202,   187,   303,   200,   200,   202,   200,   205,     7,   199,
     201,   234,   234,   293,    84,    86,   296,   296,     7,   296,
      84,    86,   296,   296,     7,    86,   296,   296,     6,     7,
       7,   299,     7,     7,   101,   281,     6,     7,   231,   290,
     231,   290,   231,   290,   231,   290,     7,     7,     7,     7,
       7,   207,     4,   207,   205,   205,   205,   207,   207,   293,
     293,   293,     4,     6,   290,   206,     6,   199,     6,   130,
       6,   130,     6,   130,     6,   130,   207,   280,   205,   279,
       7,     6,     7,     7,     7,     6,   206,     6,     6,     6,
      84,     7,     6,     6,   290,   203,   207,   207,   207,   290,
     290,   290,   290,   207,   207,   207,   207,   290,   207,   207,
     296,   296,   296,     4,   205,     8,     8,   200,     4,     4,
     296,   207,   233,   233,     6,   290,     6,   233,   233,     6,
     290,     6,   234,     6,     4,     6,   234,   234,   234,   234,
     234,   205,   200,   200,   200,   205,   205,   234,   245,   205,
     234,   247,   200,   200,   234,   234,   234,   306,   306,     6,
     234,   306,   306,     7,   231,   232,   203,     7,     6,   300,
     290,   205,   207,   207,   207,   207,   207,   231,   199,   290,
     290,   295,   296,   206,   203,     6,     6,   213,     6,   290,
     206,   290,   304,   200,   202,     6,     6,     6,   206,   206,
      94,   253,   253,   296,     6,   206,   206,     6,     6,   296,
     206,     6,     6,     5,   296,   207,   296,   296,     4,     6,
     296,   296,   296,   296,   296,   296,   296,   296,   206,   206,
       7,     6,     7,   290,   290,   290,   206,   206,   205,   207,
     205,   207,   205,   207,   201,     6,   290,   296,   290,     6,
       6,     6,     6,   290,   293,   207,     5,   206,   296,   206,
     206,   206,   296,   299,   206,   290,   202,     4,   234,   200,
     202,   205,   205,   205,   205,   234,     6,     6,   141,   290,
     290,   290,     6,     6,     7,   205,     6,   234,   306,   306,
       6,   234,   306,   306,     6,   231,   232,   303,   304,     4,
       4,   156,     6,   234,   234,     6,   234,   234,   304,   290,
       6,     4,   301,     6,   202,   300,     6,     6,     6,     6,
     296,   217,   290,   205,   205,   205,   207,   218,   290,     4,
     303,   205,   296,   304,     7,     7,   290,   290,   293,     6,
       6,     6,   290,   290,     6,   290,     5,     6,   206,     6,
     145,   252,   290,     6,     6,     6,     6,     6,     6,     4,
       6,     6,   299,   299,   290,   290,   304,   207,   200,   205,
     207,   256,   256,   293,     6,   270,   293,     6,   271,   293,
       6,   272,   290,   207,   205,   200,   207,   205,     6,   190,
     293,     6,   295,   293,   293,     6,   207,   290,     6,     6,
     290,   290,   290,   290,   296,   205,   207,     8,   207,   200,
     206,   290,   304,   296,     6,   234,   234,     6,   234,   234,
     296,   200,   234,   206,   296,   304,   206,   290,   304,   304,
       6,     6,     6,     6,     6,     6,     7,     6,   203,     6,
     200,   205,   290,   290,   296,   206,   205,   207,     6,   290,
     238,   241,   206,   206,   207,   207,   207,   207,   207,     5,
     295,    82,     6,   206,   207,   207,   206,     6,     6,   206,
     290,   207,   207,   205,   206,   205,   206,   205,   206,   202,
       6,   296,     7,   206,   290,   205,   207,   205,   205,     6,
     207,   205,   205,   205,   205,   140,   290,   290,   299,     6,
       6,   207,     6,     6,     6,     6,     6,   243,   290,   306,
     300,   143,   221,   290,   205,   205,   295,   290,     6,   205,
     244,   246,   296,   296,     6,     6,     6,     6,     6,     6,
     207,   206,   295,   105,   106,   111,   285,   105,   106,   285,
     299,   256,   205,   207,   290,   293,   279,   290,   293,   279,
     290,   293,   279,     6,   205,   207,   296,   257,   207,   293,
       6,   299,   293,   290,   290,   290,   290,   290,   207,   207,
     207,     6,   205,   207,     7,   207,     6,   206,   290,   290,
     207,   290,   207,   207,   240,   239,   206,   290,   207,   206,
     293,   296,     6,   206,   293,     6,   207,   207,   290,   207,
     205,   207,   207,   205,   207,   207,   205,   207,   296,     6,
     101,   207,   267,   206,   205,   207,   205,   205,   205,   205,
     205,     6,     6,   290,   304,   218,   200,   205,     6,   206,
     205,   244,   244,   290,   207,     6,   293,     6,   293,     6,
       6,   207,     6,   273,   290,     6,     6,   274,   290,     6,
       6,   275,   290,     6,   207,   290,   279,   257,   299,     6,
     293,   299,   290,   290,   290,   290,     7,   207,   224,   290,
     295,   290,   207,   207,   205,   205,   205,   206,   207,   206,
     207,   206,   207,     6,     6,   207,   207,   268,   207,   205,
     207,   205,   205,   205,   205,   304,     6,   206,   200,   207,
     207,   290,   293,   293,   279,     6,   276,   279,     6,   277,
     279,     6,   278,   279,     6,   299,     6,   290,   290,   290,
     290,   222,   303,   227,   206,     6,   207,   205,   205,   207,
     206,   207,   206,   207,   206,   207,   207,   205,   205,   205,
     205,   205,   207,   206,   295,     6,   290,   290,     6,   279,
       6,   279,     6,   279,     6,   290,   290,   290,   290,   303,
       6,   225,   303,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   205,   207,     6,     6,     6,     6,     6,
       6,   303,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   209,   210,   210,   211,   211,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   214,   214,   214,   214,   214,   214,
     215,   215,   215,   215,   216,   216,   216,   216,   216,   216,
     217,   217,   218,   218,   220,   221,   219,   222,   222,   224,
     223,   225,   225,   227,   226,   228,   228,   230,   229,   231,
     231,   231,   231,   231,   232,   232,   233,   233,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   236,   236,   237,   237,   237,   238,   237,   239,   237,
     240,   237,   237,   241,   237,   242,   242,   243,   243,   244,
     244,   245,   245,   245,   246,   246,   247,   247,   247,   247,
     248,   248,   248,   249,   249,   249,   250,   250,   250,   251,
     251,   251,   252,   252,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   255,   255,   255,
     255,   255,   255,   256,   256,   257,   257,   257,   257,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     259,   259,   259,   259,   259,   260,   260,   261,   262,   262,
     262,   262,   262,   262,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   265,   265,   265,
     266,   265,   267,   265,   268,   265,   269,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   270,   265,   271,
     265,   272,   265,   273,   265,   274,   265,   275,   265,   276,
     265,   277,   265,   278,   265,   279,   279,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     284,   285,   285,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   287,
     287,   287,   288,   288,   288,   289,   289,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   292,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   293,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   296,
     296,   296,   296,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   299,
     299,   299,   299,   300,   300,   300,   300,   301,   301,   302,
     302,   303,   303,   303,   303,   303,   303,   303,   303,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   304,   306,   306,   307,   307,   308,
     308,   308
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
       5,     5,     7,     7,     4,     3,     6,     6,     7,     7,
       6,     6,     9,     9,     6,     6,     7,     7,     6,     6,
       4,     8,     8,     9,     9,     9,     9,     8,     8,     9,
       9,     9,     9,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     9,     9,    11,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     0,    11,
       0,    11,     5,     0,     9,     0,     3,     3,     5,     0,
       2,     3,     5,     3,     0,     2,     3,     3,     3,     5,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     0,     5,     0,     2,     7,     8,     6,     7,
       4,     7,     8,     8,     7,     7,    11,     8,     8,     8,
       8,     9,     3,     4,    10,     7,     7,     8,     8,    12,
       8,     8,     7,     8,     8,     5,    11,     5,     9,     9,
       4,     9,     9,     1,     1,     0,     2,     6,     6,     6,
       6,     8,    10,    14,    16,    12,     8,     8,     6,    14,
       4,     6,     6,     3,     4,     5,     6,     5,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
       2,     2,    16,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     8,     8,
       8,    12,    12,    12,    14,    14,    14,     0,    12,     0,
      12,     0,    12,     0,    16,     0,    16,     0,    16,     0,
      18,     0,    18,     0,    18,     1,     2,     5,     7,     9,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     9,     6,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     4,     6,     1,     4,     4,     4,
       4,     4,     4,     4,     2,     5,     5,     5,     5,     3,
       6,     4,     7,     6,     6,     6,     6,     4,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
       5,     5,     5,     5,    16,    16,    16,    16,     1,     1,
       3,     3,     4,     4,     4,     6,     6,     6,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     4,     4,     3,     6,     1,
       4,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     4,     6,     4,
       1,     4,     4,     0,     6,     1,     3,     5,     5,     1,
       1,     4
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
#line 199 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4758 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4764 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4788 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4864 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 251 "Gmsh.y" /* yacc.c:1646  */
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
#line 4882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 265 "Gmsh.y" /* yacc.c:1646  */
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
#line 4899 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 278 "Gmsh.y" /* yacc.c:1646  */
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
#line 4916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 291 "Gmsh.y" /* yacc.c:1646  */
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
#line 4943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 319 "Gmsh.y" /* yacc.c:1646  */
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
#line 4961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 333 "Gmsh.y" /* yacc.c:1646  */
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
#line 4978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 346 "Gmsh.y" /* yacc.c:1646  */
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
#line 4995 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 359 "Gmsh.y" /* yacc.c:1646  */
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
#line 5014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 377 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 5024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 393 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 405 "Gmsh.y" /* yacc.c:1646  */
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
#line 5156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 509 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 5170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 519 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 528 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 535 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 545 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 5215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5225 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 570 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 580 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 5259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 588 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 598 "Gmsh.y" /* yacc.c:1646  */
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
#line 5289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 617 "Gmsh.y" /* yacc.c:1646  */
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
#line 5309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 642 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 674 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 679 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 685 "Gmsh.y" /* yacc.c:1646  */
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
        else{
          // list of expressions; this is not recommended (should use [] or ()
          // notation instead)
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
#line 5477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 747 "Gmsh.y" /* yacc.c:1646  */
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
#line 5496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 764 "Gmsh.y" /* yacc.c:1646  */
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
#line 5529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 793 "Gmsh.y" /* yacc.c:1646  */
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
#line 5562 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 822 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 827 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 832 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5589 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 837 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 842 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 849 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 859 "Gmsh.y" /* yacc.c:1646  */
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
#line 5653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 888 "Gmsh.y" /* yacc.c:1646  */
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
#line 5686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 917 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 927 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 932 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 940 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 949 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 955 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 961 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[-2].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[-8].c)] = s;
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 974 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[-2].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[-8].c)] = s;
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 987 "Gmsh.y" /* yacc.c:1646  */
    {
      if(gmsh_yystringsymbols.count((yyvsp[-8].c))){
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[-2].l), i);
          gmsh_yystringsymbols[(yyvsp[-8].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[-8].c));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1002 "Gmsh.y" /* yacc.c:1646  */
    {
      if(gmsh_yystringsymbols.count((yyvsp[-8].c))){
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[-2].l), i);
          gmsh_yystringsymbols[(yyvsp[-8].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[-8].c));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1019 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1025 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1031 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[-2].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[-8].c)] = s;
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1044 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[-2].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[-8].c)] = s;
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1057 "Gmsh.y" /* yacc.c:1646  */
    {
      if(gmsh_yystringsymbols.count((yyvsp[-8].c))){
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[-2].l), i);
          gmsh_yystringsymbols[(yyvsp[-8].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[-8].c));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1072 "Gmsh.y" /* yacc.c:1646  */
    {
      if(gmsh_yystringsymbols.count((yyvsp[-8].c))){
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[-2].l), i);
          gmsh_yystringsymbols[(yyvsp[-8].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[-8].c));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 5904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1089 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5914 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1095 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1104 "Gmsh.y" /* yacc.c:1646  */
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
#line 5946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1122 "Gmsh.y" /* yacc.c:1646  */
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
#line 5968 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1140 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1149 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1161 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1174 "Gmsh.y" /* yacc.c:1646  */
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
#line 6036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1194 "Gmsh.y" /* yacc.c:1646  */
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
#line 6060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1217 "Gmsh.y" /* yacc.c:1646  */
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
#line 6075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1228 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 6087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1236 "Gmsh.y" /* yacc.c:1646  */
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
#line 6113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1258 "Gmsh.y" /* yacc.c:1646  */
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
#line 6140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1281 "Gmsh.y" /* yacc.c:1646  */
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
#line 6170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1307 "Gmsh.y" /* yacc.c:1646  */
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
#line 6192 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1328 "Gmsh.y" /* yacc.c:1646  */
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
#line 6208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1340 "Gmsh.y" /* yacc.c:1646  */
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
#line 6224 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1358 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 6237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1367 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 6250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1376 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1378 "Gmsh.y" /* yacc.c:1646  */
    {
      if(List_Nbr((yyvsp[-3].l)) != 1)
	yymsg(1, "List notation should be used to define list '%s[]'", (yyvsp[-6].c));
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
#line 6278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1396 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1398 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-8].c));
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
      Free((yyvsp[-8].c));
      Free((yyvsp[-3].l));
    }
#line 6304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1414 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1416 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-8].c));
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
      Free((yyvsp[-8].c));
      Free((yyvsp[-3].l));
    }
#line 6330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1432 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1441 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1443 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6363 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1457 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1465 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1471 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1483 "Gmsh.y" /* yacc.c:1646  */
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
#line 6407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1494 "Gmsh.y" /* yacc.c:1646  */
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
#line 6425 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1509 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1525 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1533 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1542 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1550 "Gmsh.y" /* yacc.c:1646  */
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
#line 6488 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1572 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6506 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1578 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1586 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1590 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1596 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6542 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1604 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1608 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1614 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1622 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1626 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1632 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1640 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1644 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1656 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1660 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1670 "Gmsh.y" /* yacc.c:1646  */
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
#line 6661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1693 "Gmsh.y" /* yacc.c:1646  */
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
        if(!List_Nbr(p->Entities)){
          DeletePhysicalPoint(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
#line 6708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1736 "Gmsh.y" /* yacc.c:1646  */
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
#line 6732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1759 "Gmsh.y" /* yacc.c:1646  */
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
#line 6754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1777 "Gmsh.y" /* yacc.c:1646  */
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
#line 6779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1798 "Gmsh.y" /* yacc.c:1646  */
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
#line 6801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1816 "Gmsh.y" /* yacc.c:1646  */
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
#line 6835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1846 "Gmsh.y" /* yacc.c:1646  */
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
#line 6869 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1876 "Gmsh.y" /* yacc.c:1646  */
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
#line 6891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1894 "Gmsh.y" /* yacc.c:1646  */
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
#line 6913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1913 "Gmsh.y" /* yacc.c:1646  */
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
#line 6943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1939 "Gmsh.y" /* yacc.c:1646  */
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
#line 6965 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1957 "Gmsh.y" /* yacc.c:1646  */
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
#line 6987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1975 "Gmsh.y" /* yacc.c:1646  */
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
        if(!List_Nbr(p->Entities)){
          DeletePhysicalLine(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
#line 7034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2021 "Gmsh.y" /* yacc.c:1646  */
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
#line 7056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2039 "Gmsh.y" /* yacc.c:1646  */
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
#line 7099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2078 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2084 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2090 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2097 "Gmsh.y" /* yacc.c:1646  */
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
#line 7159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2122 "Gmsh.y" /* yacc.c:1646  */
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
#line 7188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2147 "Gmsh.y" /* yacc.c:1646  */
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
#line 7209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2164 "Gmsh.y" /* yacc.c:1646  */
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
#line 7232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2184 "Gmsh.y" /* yacc.c:1646  */
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
#line 7269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2217 "Gmsh.y" /* yacc.c:1646  */
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
        if(!List_Nbr(p->Entities)){
          DeletePhysicalSurface(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
#line 7316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2264 "Gmsh.y" /* yacc.c:1646  */
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
#line 7338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2282 "Gmsh.y" /* yacc.c:1646  */
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
#line 7359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2299 "Gmsh.y" /* yacc.c:1646  */
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
#line 7379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2315 "Gmsh.y" /* yacc.c:1646  */
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
        if(!List_Nbr(p->Entities)){
          DeletePhysicalVolume(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
#line 7426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2363 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2368 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2373 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2378 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2383 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2388 "Gmsh.y" /* yacc.c:1646  */
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
#line 7498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2411 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2417 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2427 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2428 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2433 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2437 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2441 "Gmsh.y" /* yacc.c:1646  */
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
#line 7575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2464 "Gmsh.y" /* yacc.c:1646  */
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
#line 7602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2487 "Gmsh.y" /* yacc.c:1646  */
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
#line 7629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2510 "Gmsh.y" /* yacc.c:1646  */
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
#line 7656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2538 "Gmsh.y" /* yacc.c:1646  */
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
#line 7681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2559 "Gmsh.y" /* yacc.c:1646  */
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
#line 7711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2586 "Gmsh.y" /* yacc.c:1646  */
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
#line 7735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2607 "Gmsh.y" /* yacc.c:1646  */
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
#line 7760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2628 "Gmsh.y" /* yacc.c:1646  */
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
#line 7784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2648 "Gmsh.y" /* yacc.c:1646  */
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
#line 7900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2760 "Gmsh.y" /* yacc.c:1646  */
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
#line 7923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2779 "Gmsh.y" /* yacc.c:1646  */
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
#line 7965 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2818 "Gmsh.y" /* yacc.c:1646  */
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
#line 8072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2926 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8085 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2935 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 8095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2941 "Gmsh.y" /* yacc.c:1646  */
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
#line 8114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2956 "Gmsh.y" /* yacc.c:1646  */
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
#line 8146 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2984 "Gmsh.y" /* yacc.c:1646  */
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
#line 8162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 3001 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 3024 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8201 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3038 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3044 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3050 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3059 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3068 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3077 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3091 "Gmsh.y" /* yacc.c:1646  */
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
#line 8336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3150 "Gmsh.y" /* yacc.c:1646  */
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
#line 8358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3168 "Gmsh.y" /* yacc.c:1646  */
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
#line 8379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3185 "Gmsh.y" /* yacc.c:1646  */
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
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3200 "Gmsh.y" /* yacc.c:1646  */
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
#line 8428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3226 "Gmsh.y" /* yacc.c:1646  */
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
#line 8444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3238 "Gmsh.y" /* yacc.c:1646  */
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
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3262 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3266 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8489 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3271 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8500 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3278 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3283 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3289 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3294 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3300 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3308 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3312 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3316 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3322 "Gmsh.y" /* yacc.c:1646  */
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
#line 8633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3381 "Gmsh.y" /* yacc.c:1646  */
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
#line 8654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3398 "Gmsh.y" /* yacc.c:1646  */
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
#line 8675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3415 "Gmsh.y" /* yacc.c:1646  */
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
#line 8701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3437 "Gmsh.y" /* yacc.c:1646  */
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
#line 8727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3459 "Gmsh.y" /* yacc.c:1646  */
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
#line 8766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3494 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3502 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3510 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3516 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3523 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3530 "Gmsh.y" /* yacc.c:1646  */
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
#line 8846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3550 "Gmsh.y" /* yacc.c:1646  */
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
#line 8876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3576 "Gmsh.y" /* yacc.c:1646  */
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
#line 8892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3588 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8902 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3600 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8914 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3608 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3616 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8938 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3624 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3630 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3638 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3644 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3652 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3658 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3666 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3672 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9025 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3680 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3687 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3694 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3701 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3708 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9080 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3715 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9091 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3722 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3729 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3736 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9124 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3743 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3749 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3756 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3762 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3769 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9176 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3775 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9187 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3782 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3788 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3795 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3801 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3808 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3814 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3821 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3827 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3834 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3840 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3847 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3853 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3864 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3867 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3873 "Gmsh.y" /* yacc.c:1646  */
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
#line 9343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3885 "Gmsh.y" /* yacc.c:1646  */
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
#line 9367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3905 "Gmsh.y" /* yacc.c:1646  */
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
#line 9394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3929 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3933 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3937 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 9418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3941 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3945 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3949 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3955 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3961 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3965 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3969 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3973 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3977 "Gmsh.y" /* yacc.c:1646  */
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
#line 9509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 3996 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4008 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4012 "Gmsh.y" /* yacc.c:1646  */
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
#line 9546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4027 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4031 "Gmsh.y" /* yacc.c:1646  */
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
#line 9572 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4047 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4051 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4056 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4060 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4066 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4070 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4077 "Gmsh.y" /* yacc.c:1646  */
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
#line 9680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4133 "Gmsh.y" /* yacc.c:1646  */
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
#line 9754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4203 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4208 "Gmsh.y" /* yacc.c:1646  */
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
#line 9834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4275 "Gmsh.y" /* yacc.c:1646  */
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
#line 9874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4311 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4319 "Gmsh.y" /* yacc.c:1646  */
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
#line 9933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4362 "Gmsh.y" /* yacc.c:1646  */
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
#line 9976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4401 "Gmsh.y" /* yacc.c:1646  */
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
#line 10000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4422 "Gmsh.y" /* yacc.c:1646  */
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
#line 10035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4454 "Gmsh.y" /* yacc.c:1646  */
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
#line 10065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4481 "Gmsh.y" /* yacc.c:1646  */
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
#line 10094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4507 "Gmsh.y" /* yacc.c:1646  */
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
#line 10123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4533 "Gmsh.y" /* yacc.c:1646  */
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
#line 10152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4559 "Gmsh.y" /* yacc.c:1646  */
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
#line 10181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4585 "Gmsh.y" /* yacc.c:1646  */
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
#line 10206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
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
#line 10238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
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
#line 10270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4662 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4670 "Gmsh.y" /* yacc.c:1646  */
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
#line 10318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4698 "Gmsh.y" /* yacc.c:1646  */
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
#line 10361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4737 "Gmsh.y" /* yacc.c:1646  */
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
#line 10404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
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
#line 10429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4797 "Gmsh.y" /* yacc.c:1646  */
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
#line 10454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4818 "Gmsh.y" /* yacc.c:1646  */
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
#line 10479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4845 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4849 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4859 "Gmsh.y" /* yacc.c:1646  */
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
#line 10535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4893 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4894 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10547 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4895 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4900 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4906 "Gmsh.y" /* yacc.c:1646  */
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
#line 10579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4918 "Gmsh.y" /* yacc.c:1646  */
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
#line 10601 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
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
#line 10628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4963 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4964 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4965 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4966 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4967 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4968 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10664 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4969 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4970 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4972 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4979 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4980 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4983 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10723 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4984 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4987 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4988 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4989 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10765 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4991 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4992 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4993 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4995 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4996 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4997 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4998 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10813 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4999 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10819 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 5000 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10825 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 5001 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10831 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 5002 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 5003 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 5006 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 5007 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 5008 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 5010 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 5019 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 5021 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 5022 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 5023 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 5024 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 5026 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 5027 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 5028 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 5029 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5034 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5036 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5042 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5047 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5052 "Gmsh.y" /* yacc.c:1646  */
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
#line 11006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
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
#line 11028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5087 "Gmsh.y" /* yacc.c:1646  */
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
#line 11050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5105 "Gmsh.y" /* yacc.c:1646  */
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
#line 11072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5123 "Gmsh.y" /* yacc.c:1646  */
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
#line 11094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5141 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11103 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5146 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 11113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5152 "Gmsh.y" /* yacc.c:1646  */
    {
      if(gmsh_yysymbols.count((yyvsp[-2].c))){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	(yyval.d) = s.value.size();
      }
      else if(gmsh_yystringsymbols.count((yyvsp[-2].c))){
	(yyval.d) = gmsh_yystringsymbols[(yyvsp[-2].c)].size();
      }
      else{
        yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
	(yyval.d) = 0.;
      }
      Free((yyvsp[-2].c));
    }
#line 11132 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5167 "Gmsh.y" /* yacc.c:1646  */
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
#line 11153 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5184 "Gmsh.y" /* yacc.c:1646  */
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
#line 11175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5202 "Gmsh.y" /* yacc.c:1646  */
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
#line 11197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5220 "Gmsh.y" /* yacc.c:1646  */
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
#line 11219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5238 "Gmsh.y" /* yacc.c:1646  */
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
#line 11241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5259 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5264 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5269 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5279 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5289 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5294 "Gmsh.y" /* yacc.c:1646  */
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
#line 11311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5305 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5314 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11333 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5319 "Gmsh.y" /* yacc.c:1646  */
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
#line 11361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5346 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11369 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5350 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5354 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5358 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11393 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5362 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5369 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11417 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5377 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11425 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5381 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5393 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5400 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5405 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5409 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11476 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5414 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5418 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5426 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5437 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5441 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5453 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5461 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5469 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11564 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5476 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5486 "Gmsh.y" /* yacc.c:1646  */
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
#line 11611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5515 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5519 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5523 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5527 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5531 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5535 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5539 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11667 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5543 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5547 "Gmsh.y" /* yacc.c:1646  */
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
#line 11708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5576 "Gmsh.y" /* yacc.c:1646  */
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
#line 11741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5605 "Gmsh.y" /* yacc.c:1646  */
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
#line 11774 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5634 "Gmsh.y" /* yacc.c:1646  */
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
#line 11807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5664 "Gmsh.y" /* yacc.c:1646  */
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
#line 11823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5677 "Gmsh.y" /* yacc.c:1646  */
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
#line 11839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5690 "Gmsh.y" /* yacc.c:1646  */
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
#line 11855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5703 "Gmsh.y" /* yacc.c:1646  */
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
#line 11871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5715 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5725 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11899 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5735 "Gmsh.y" /* yacc.c:1646  */
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
#line 11915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5747 "Gmsh.y" /* yacc.c:1646  */
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
#line 11931 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5760 "Gmsh.y" /* yacc.c:1646  */
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
#line 11947 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5772 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5780 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 11971 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5784 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 11979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5788 "Gmsh.y" /* yacc.c:1646  */
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
#line 12001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5806 "Gmsh.y" /* yacc.c:1646  */
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
#line 12023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5827 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12032 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5832 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5836 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5840 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5852 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 12069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5856 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 12077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5868 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag = 0;
      if(gmsh_yystringsymbols.count((yyvsp[0].c))){
        if(gmsh_yystringsymbols[(yyvsp[0].c)].size()){
          (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[0].c)][0].c_str(), &flag);
        }
        else{
          yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
          (yyval.u) = 0;
        }
      }
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 12098 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5885 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 12109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5895 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5899 "Gmsh.y" /* yacc.c:1646  */
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
#line 12133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5914 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5919 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5926 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5930 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val;
      if(!gmsh_yystringsymbols.count((yyvsp[0].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[0].c));
      else if(gmsh_yystringsymbols[(yyvsp[0].c)].size() == 1)
        val = gmsh_yystringsymbols[(yyvsp[0].c)][0];
      else
        yymsg(0, "Expected single valued string variable '%s'", (yyvsp[0].c));
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[0].c));
    }
#line 12175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5943 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5957 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5971 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5985 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5999 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 6007 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 6018 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12279 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 6022 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6026 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6034 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6040 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6046 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6054 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6062 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6069 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6077 "Gmsh.y" /* yacc.c:1646  */
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
#line 12385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6092 "Gmsh.y" /* yacc.c:1646  */
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
#line 12403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6106 "Gmsh.y" /* yacc.c:1646  */
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
#line 12421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6120 "Gmsh.y" /* yacc.c:1646  */
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
#line 12437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6132 "Gmsh.y" /* yacc.c:1646  */
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
#line 12457 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6148 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6157 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6166 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6176 "Gmsh.y" /* yacc.c:1646  */
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
#line 12512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6187 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6191 "Gmsh.y" /* yacc.c:1646  */
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
#line 12543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6210 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6217 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12564 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 6223 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 6230 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 6237 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 6239 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 6250 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 6255 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 6261 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 6270 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 6283 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 6286 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 6290 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12665 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6293 "Gmsh.y" /* yacc.c:1906  */


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
  for(std::map<std::string, std::vector<std::string> >::iterator it =
        gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end(); it++){
    if(it->second.size() == 1)
      vec.push_back(it->first + " = \"" + it->second[0] + "\";");
    else{
      std::string s = it->first + "[] = Str(";
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += ");";
      vec.push_back(s);
    }
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
