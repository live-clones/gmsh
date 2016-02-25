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
#define YYLAST   11324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  539
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1930

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
     670,   671,   672,   677,   683,   745,   762,   791,   796,   801,
     806,   811,   818,   828,   857,   886,   891,   896,   901,   909,
     918,   924,   930,   943,   956,   971,   988,   994,  1000,  1013,
    1026,  1041,  1058,  1064,  1073,  1091,  1109,  1118,  1130,  1135,
    1143,  1163,  1186,  1197,  1205,  1227,  1250,  1276,  1297,  1309,
    1323,  1323,  1325,  1327,  1336,  1346,  1345,  1363,  1373,  1372,
    1386,  1388,  1396,  1402,  1409,  1410,  1414,  1425,  1440,  1450,
    1451,  1456,  1464,  1473,  1481,  1499,  1503,  1509,  1517,  1521,
    1527,  1535,  1539,  1545,  1553,  1557,  1563,  1572,  1575,  1588,
    1591,  1601,  1624,  1664,  1687,  1705,  1726,  1744,  1774,  1804,
    1822,  1840,  1867,  1885,  1903,  1946,  1964,  2003,  2009,  2015,
    2022,  2047,  2072,  2089,  2108,  2142,  2186,  2204,  2221,  2237,
    2282,  2287,  2292,  2297,  2302,  2307,  2330,  2336,  2347,  2348,
    2353,  2356,  2360,  2383,  2406,  2429,  2457,  2478,  2504,  2525,
    2547,  2567,  2679,  2698,  2736,  2845,  2854,  2860,  2875,  2903,
    2920,  2929,  2943,  2957,  2963,  2969,  2978,  2987,  2996,  3010,
    3069,  3087,  3104,  3119,  3145,  3157,  3181,  3185,  3190,  3197,
    3202,  3208,  3213,  3219,  3227,  3231,  3235,  3240,  3300,  3317,
    3334,  3356,  3378,  3413,  3421,  3429,  3435,  3442,  3449,  3469,
    3495,  3507,  3519,  3527,  3535,  3544,  3543,  3558,  3557,  3572,
    3571,  3586,  3585,  3599,  3606,  3613,  3620,  3627,  3634,  3641,
    3648,  3655,  3663,  3662,  3676,  3675,  3689,  3688,  3702,  3701,
    3715,  3714,  3728,  3727,  3741,  3740,  3754,  3753,  3767,  3766,
    3783,  3786,  3792,  3804,  3824,  3848,  3852,  3856,  3860,  3864,
    3870,  3876,  3880,  3884,  3888,  3892,  3911,  3924,  3927,  3943,
    3946,  3963,  3966,  3972,  3975,  3982,  3985,  3992,  4048,  4118,
    4123,  4190,  4226,  4234,  4277,  4316,  4336,  4368,  4395,  4421,
    4447,  4473,  4499,  4521,  4549,  4577,  4581,  4585,  4613,  4652,
    4691,  4712,  4733,  4760,  4764,  4774,  4809,  4810,  4811,  4815,
    4821,  4833,  4851,  4879,  4880,  4881,  4882,  4883,  4884,  4885,
    4886,  4887,  4894,  4895,  4896,  4897,  4898,  4899,  4900,  4901,
    4902,  4903,  4904,  4905,  4906,  4907,  4908,  4909,  4910,  4911,
    4912,  4913,  4914,  4915,  4916,  4917,  4918,  4919,  4920,  4921,
    4922,  4923,  4924,  4925,  4926,  4935,  4936,  4937,  4938,  4939,
    4940,  4941,  4942,  4943,  4944,  4945,  4950,  4949,  4957,  4962,
    4967,  4984,  5002,  5020,  5038,  5056,  5061,  5067,  5082,  5099,
    5117,  5135,  5153,  5174,  5179,  5184,  5194,  5204,  5209,  5220,
    5229,  5234,  5261,  5265,  5269,  5273,  5277,  5284,  5288,  5292,
    5296,  5303,  5308,  5315,  5320,  5324,  5329,  5333,  5341,  5352,
    5356,  5368,  5376,  5384,  5391,  5401,  5430,  5434,  5438,  5442,
    5446,  5450,  5454,  5458,  5462,  5491,  5520,  5549,  5578,  5591,
    5604,  5617,  5630,  5640,  5650,  5662,  5675,  5687,  5705,  5726,
    5731,  5735,  5739,  5751,  5755,  5767,  5784,  5794,  5798,  5813,
    5818,  5825,  5829,  5842,  5856,  5859,  5862,  5865,  5873,  5884,
    5888,  5892,  5900,  5906,  5912,  5920,  5928,  5935,  5943,  5958,
    5972,  5986,  5998,  6014,  6023,  6032,  6042,  6053,  6057,  6076,
    6083,  6090,  6089,  6102,  6107,  6113,  6122,  6135,  6138,  6142
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

#define YYPACT_NINF -1417

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1417)))

#define YYTABLE_NINF -509

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7871,    17,    84,  7991, -1417, -1417,  3883,    88,   -51,  -128,
    -105,    24,   101,   107,   113,   165,   -13,   191,   212,   100,
     111,   -46,   -46,   -99,    68,    81,    18,   125,   135,    25,
     144,   150,   206,   281,   284,   364,   194,   602,   307,   352,
     472,   333,   685,   770,    70,   251,   366,   158,   272,   203,
     203,   279,   221,    20,   195,   405,   412,    36,    93,   425,
     445,   230,   551,   554,   565,  5216,   569,   411,   446,   453,
      10,    38, -1417,   459,   466, -1417, -1417,   616,   658,   468,
   -1417,  3965,  5488,    12,    33, -1417, -1417, -1417,  7731,   475,
   -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417, -1417, -1417, -1417, -1417,    53, -1417,  -141,     0,
   -1417,     4, -1417, -1417, -1417, -1417, -1417,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   480,   509,   510,   528,   532,   539,   -46,   -46,
     -46,   -46,   552, -1417,   -46, -1417, -1417, -1417, -1417, -1417,
     -46,   -46,   712,   553,   560,   561,   -46,   -46,   571,   583,
   -1417, -1417, -1417, -1417,   588,  7731,  7731,  7731,  7223,  7282,
     146,    78,     5,   590,   593,  1490, -1417,   596,   805,   274,
    -157,   809,  7731,  5297,  5297, -1417,  7731, -1417, -1417, -1417,
   -1417,  5297, -1417, -1417, -1417, -1417, -1417, -1417,  5684,    78,
    7731,  7033,  7731,  7731,   619,  7731,  7033,  7731,  7731,   636,
    7033,  7731,  7731,  5608,   639,   635, -1417,  7033,  5216,  5216,
    5216,   665,   670,  5216,  5216,  5216,   681,   699,   719,   725,
     752,   758,   765,   786,   735,  6588,   963,  5608,    10,   736,
     780,   203,   203,   203,  7731,  7731,  -100, -1417,   245,   203,
     785,   800,   818,  6647,   248,    -8,   832,   837,   867,  5216,
    5216,  5608,   871,     1,   727, -1417,   868,  1055,  1079, -1417,
     886,   887,   891,  5216,  5216,   897,   908,   927,   608, -1417,
     949,    15,    56,    69,   117,   707,  5804,  7731,  4164, -1417,
   -1417,  3433, -1417,  1106, -1417,   311,   217,  1107,  7731,  7731,
    7731,  -151,  7731,   926, -1417,   992,  7731,  7731,  7731, -1417,
   -1417,  7731,   953,  1149,  1156, -1417, -1417,  1161, -1417,  1179,
   -1417,   621,  1509,   393,  5297, -1417,  5608,  5608,  7477,  7536,
    1023,  1024,  5684, -1417, -1417, -1417, -1417, -1417, -1417,  5608,
    1187,   997,  7731,  7731,  1196,  7731,  7731,  7731,  7731,  7731,
    7731,  7731,  7731,  7731,  7731,  7731,  7731,  7731,  7731,  7731,
    7731,  7731,  7731,  7731,  7731,  7731,  7731,  5297,  5297,  5297,
    5297,  5297,  5297,  5608,  5297,  5297,  7731,  5297,  5297,  5297,
    5297,  5297,  7731,  5684,  7731,  5297,  5297,  5297,  5297,  5297,
      78,  5684,    78,  1020,  1020,  1020,    99,  3452,   141,  9876,
     108,  1030,  1225,   -46,  1042, -1417,  1032,  5846,  7731,  7033,
   -1417,  7731,  7731,  7731,  7731,  7731,  7731,  7731,  7731,  7731,
    7731,  7731,  7731,  7731,  7731,  7731, -1417, -1417,  7731,  7731,
   -1417, -1417,  2036,   641,   398, -1417,   497, -1417,   420,  8657,
   -1417,   487,  -117,   241,  1062,  1066, 10267,  7033,  4521, -1417,
     335, 10288, 10309,  7731, 10330,   601, 10351, 10372,  7731,   643,
   10393, 10414,  1267,  7731,  7731,   655,  1271,  1272,  1273,  7731,
    7731,  1274,  1275,  1275,  7731,  6843,  6843,  6843,  6843,  7731,
    7731,  7731,  7033,  7033,  2496,  1082,  1277,  1083, -1417, -1417,
     236, -1417, -1417,  8683,  8709,   203,   203,     5,     5,   250,
    7731,  7731,  7731,  6647,  6647,  7731,  5846,   259, -1417,  7731,
    7731,  7731,  7731,  7731,  1279,  1285,  1287,  7731,  1286,  7731,
    7731,  1175, -1417, -1417,  7033,  7033,  7033,  1289,  1290,  7731,
    7731,  7731,  7731,  7731,  1293,   512,    78, -1417,  1247,  7731,
   -1417,  1249, -1417,  1250, -1417,  1251,    34,    39,    43,    44,
    7033,  1020, -1417, 10435, -1417,   671,  7731,  6000, -1417,  7731,
    7731,   540, -1417, 10456, 10477, 10498,  1158,  8735, -1417,  1113,
    4922, 10519, 10540,  9899, -1417, -1417, -1417,  1433, -1417,  1566,
    7731,  7731, -1417,  7731,  7731,  1118,  1121,   702,   152, 10561,
      14,  9922,  7731,  7033,  1315,  1327, -1417,  7731, 10582,  9945,
    -114,  9853,  9853,  9853,  9853,  9853,  9853,  9853,  9853,  9853,
    9853,  9853,  8761,  9853,  9853,  9853,  9853,  9853,  9853,  9853,
    8787,  8813,  8839,   -82,   626,   -82,  1136,  1137,  1134,  1138,
    1139,  1141,  8865,   661,   661,   661,   530,   661, 11128, -1417,
    2540,  1142,  1143,  1151,   710,   717,  1152,  1154,  1153,  1299,
    1316,  5608,   163,  1317,  1318,  5608,    95,  5684,  7731,  1349,
    1355,    29,   661, -1417,   139,    42,    30,   161, -1417,  6330,
     706,  4941,  1240,  1538,  1140,  1140,   325,   325,   325,   325,
     470,   470,  1020,  1020,  1020,  1020,    31, 10603,  9968, -1417,
    7731,  7731,  1357,    26,  7033,  7731,  7731,  1359,  7033,  7731,
    1360,  5297,  1366, -1417,    78,  1367,  5297,  7731,  5684,  1368,
    7033,  7033,  1231,  1369,  1370, 10624,  1371,  1236,  1375,  1376,
   10645,  1243,  1384,  1385,  7731, 10666,  6542,  1191, -1417, -1417,
   -1417, 10687, 10708,  7731,  5608,  1389,  1392, 10729,  1202, 11128,
    1198,  1205, 11128,  1201,  1207, 11128,  1203,  1210, 11128,  1206,
   10750, 10771, 10792,   716,   722,  7033,  1209, -1417, -1417,  1729,
    2098,   203,  7731,  7731, -1417, -1417,  1208,  1211,  6647,  8891,
    8917,  8943,  8631,   974,   203,  2324, 10813,  6739, 10834, 10855,
   10876,  7731,  1405, -1417,  7731, 10897, -1417,  9991, 10014, -1417,
     729,   730,   742, -1417, -1417, 10037, 10060,  8969, 10918, 10083,
     217, -1417, -1417,  7033, -1417,  1212,  1214,  6767,  1228,  1233,
    1234, -1417,  7033, -1417,  7033, -1417,  7033, -1417,  7033,   743,
   -1417, -1417,  4960,  7033,  1020, -1417, 10939, 10106,  7033, -1417,
    1407,  1428,  1436,  1241,  7731,  2424,  7731,  7731, -1417, -1417,
       3, -1417, -1417,  2559, -1417,  1246,  5608,  1441,  1417,  1422,
    5608,   163,  1423,  1424,   163,  6800,   806, -1417, -1417, 10129,
     179,   562, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417, -1417, -1417,  7731, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417,  7731,  7731,  7731, -1417,  7033, -1417, -1417, -1417,
   -1417,  5297,  5608,  5297,  5297,  5684, -1417, -1417, -1417, -1417,
   -1417, -1417, -1417, -1417,  7731,  5297, -1417,  5297, -1417,  7731,
   -1417, -1417, -1417, -1417,   -46,   -46,  1459, -1417,  7731,  1460,
     -46,   -46,  1461,   164,  7731,  1462,  1463,  2867, -1417,  1467,
    1283,    10,  1464, -1417,  7033,  7033,  7033,  7033, -1417,   661,
    7731, -1417,  1291,  1292,  1294, -1417,  1477, -1417, -1417, -1417,
   -1417, -1417,   209,   211, 10960, 10152, -1417, -1417,  1305,  5297,
     545, 10981, 10175, -1417,   572,  8995, -1417, -1417, -1417,  1484,
   -1417, -1417,  9853,   661,   203,  4521, -1417,   939,  5608,  5608,
    1488,  5608,   968,  5608,  5608,  1492,  1416,  5608,  5608,  3215,
    1494,  1496,  7033,  1497,  1498,  1935, -1417, -1417,  1513, -1417,
    1514,   185,  7731,   185,  7731,   185,  7731,   185,  7731,  1515,
    1516,  1517,  1520,  1524,   850,  1528,  2754, -1417, -1417,   269,
    9021,  9047, -1417, -1417,  6971,  -135,   203,   203,   203,  1529,
    1534,  1331,  1540,  1347,    37,    51,    54,    57,   302, -1417,
     315, -1417,   974,  1541,  1543,  1544,  1545,  1546, 11128, -1417,
    3249,  1343,  1549,  1550,  1551,  1468,  1554,  1556,  1557,  7731,
     217,   151,   854, -1417,  7731, -1417,  7731,  7731,  7731,   855,
     860,   864,   877, -1417,  7731,   878,   217,   217,   899,  5608,
    5608,  5608,  1561,  9073, -1417,  4979,   858,  1562,  1563, -1417,
    5608,  1377, -1417,   -46,   -46,  1565,  7731,  1567,   -46,   -46,
    7731,  1568, -1417,   661,  1569, -1417,  1572, -1417,  1575,  9853,
    9853,  9853,  9853,   761,  1380,  1374,  1387,  1388,  1386,   810,
     817, 11002,  1390,   661,  9853,  1435,  5297, -1417,  3339, -1417,
    1435,  5297, -1417,   174,  1391,  1580,  3358, -1417, -1417, -1417,
      10,  7731, -1417,   900, -1417,   903,   913,   914,   918,   185,
   11128,  1394,  7731,  7731,  5608,  1393, -1417, -1417, -1417, -1417,
    1395, -1417,  1592,    79, -1417, -1417,  1595,  7731,  4759,  1596,
    1597,    66,  1400,  1402,  1518,  1518,  5608,  1603,  1408,  1409,
    1605,  1608,  5608,  1412,  1611,  1613, -1417,  1615,  5608,   919,
    5608,  5608,  1617,  1618, -1417,  5608,  5608, 11128,  5608, 11128,
    5608, 11128,  5608, 11128,  5608,  5608,  5608,  1419,  1421,  1619,
     463, -1417,  7731,  7731,  7731,  1425,  1426,  -112,   120,   166,
    1429, -1417,  5608, -1417,  7731, -1417,  1625, -1417,  1626, -1417,
    1630, -1417,  1631, -1417, -1417,  6647,   341,  5412, -1417,  1437,
    1448,  6196, -1417,  7033, -1417, -1417, -1417,  1450,  7731, -1417,
   -1417, 10198,  1636,   661,  9099,  9125,  9151,  9177, -1417, -1417,
   -1417, -1417, 11128, -1417,   661,  1649,  1650,  1521, -1417,  7731,
    7731,  7731, -1417,  1651,   575,  1479,  1658,  1435,  5297, -1417,
    3384, -1417,  1435,  5297,  3474, -1417,   185, -1417,   270, -1417,
   -1417, -1417, -1417, -1417, -1417,  5297, -1417, -1417, -1417,  5684,
    1661, -1417, -1417,    41, -1417, -1417, -1417, -1417, -1417, -1417,
    1660,   -82,   -82, -1417,  1677,   -82,   -82,  5684,  7731,  1678,
    1702,    29, -1417,  1701, 10221,    10, -1417,  1703,  1704,  1705,
    1706,  5608,  7731,  9203,  9229,   922, -1417,  7731,  1726, -1417,
   -1417,  5297, -1417,  9255,  4367, 11128, -1417, -1417, -1417, -1417,
    7731,  7731,   203,  1727,  1730,  1731, -1417,  7731,  7731, -1417,
   -1417,  1732,  7731, -1417, -1417,  1734,  1737,  1504,  1738,  1589,
    7731, -1417,  1739,  1740,  1741,  1742,  1747,  1752,  1125,  1757,
    7033,  7033,  7731, -1417,  6843,  7177, 11023,  2395,     5,     5,
     203,  1759,   203,  1762,   203,  1763,  7731,   701,  1570, 11044,
   -1417, -1417, -1417, -1417,  7431,   336, -1417,  1764,  3676,  1766,
    5608,   203,  3676,  1768,   931,  7731,  3620,  1769,   217, -1417,
    7731,  7731,  7731,  7731, -1417, -1417, -1417,  5608,  5938,   791,
   11065, -1417, -1417,  4824,  5608, -1417,  1770,   -82,   -82, -1417,
    1772,   -82,   -82, -1417,  5608, -1417,  1581,   661,  4563,  5020,
    5684, -1417,  1774,  1775, -1417,  1776,  1777,  1779,  3807, -1417,
    1780,  1782, -1417,  1585, -1417, -1417, -1417, -1417, -1417,  1783,
     581, 11128,  7731,  7731,  5608,  1586,   936, 11128, -1417,  1785,
    7731, -1417, -1417,  7626,  7654,   401, -1417, -1417, -1417,  7987,
    8015, -1417,  8043,  1787, -1417,  5608, -1417,  1715,  1790, 11128,
   -1417, -1417, -1417, -1417, -1417, -1417,  1593, -1417, -1417,   937,
     940,  2824,  3914,  1792,  1599, -1417,  7731, -1417,  1594,  1610,
     338, -1417,  1600,   357, -1417,  1614,   360, -1417,  1616, 10244,
    1794,  5608,  1810,  1623,  7731, -1417,  6392,   362, -1417,   941,
     365,   374, -1417,  1795,  8071, -1417, -1417,  9281,  9307,  9333,
    9359,  1681,  7731, -1417,  7731, -1417, -1417,  7033,  3962,  1817,
    1624, -1417,  1825,  1828, -1417,  1832,  1833,  1834, -1417, -1417,
    4164, -1417, -1417,  5297, 11128, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417, -1417,    10, -1417,  1709, -1417, -1417,  7731,  9385,
    9411, -1417,  5608,  7731,  1837, -1417,  9437, -1417, -1417,  1838,
    1839,  1840,  1846,  1847,  1848,   946,  1654, -1417,  5608,   656,
     747,  7033, -1417, -1417,     5,  6134, -1417, -1417,  6647,   974,
    6647,   974,  6647,   974,  1853, -1417,   951,  5608, -1417,  8099,
     203,  1855,  7033,   203, -1417, -1417,  7731,  7731,  7731,  7731,
    7731,  8127,  8155,   955, -1417, -1417,  1856, -1417, -1417, -1417,
   -1417, -1417,   960,  4501,   979,  1857, -1417,  1663, 11128,  7731,
    7731,   989, 11128, -1417,  7731,   996,  1001, -1417, -1417, -1417,
   -1417, -1417, -1417,  1665,  7731,  1005,  1666,   203,  5608,  1865,
    1668,   203,  1867,  1012,  1669,  7731, -1417,  8183,   388,   410,
    8211,   422,   460,  8239,   429,   573, -1417,  5608,  1869,  1781,
    2859,  1672,   454, -1417,  1017,   465,  9463,  9489,  9515,  9541,
    4124, -1417, -1417,  1873, -1417,  7731, -1417,  5684, -1417, -1417,
    7731, 11086,  9567,    45,  9593, -1417, -1417,  7731,  8267,  1875,
     203,    71, -1417, -1417,   203,    75, -1417,  1876, -1417,  8295,
    1877,  7731,  1880,  1882,  7731,  1883,  1884,  7731,  1887,  1711,
   -1417,  7731, -1417,   974, -1417,  7033,  1912,  6392,  7731,  7731,
    7731,  7731, -1417, -1417,   990, -1417,  1018, -1417,  7731, -1417,
    5608,  7731,  9619, -1417, -1417,   467, -1417,   499, -1417, -1417,
   -1417, -1417,  1716,  8323, -1417, -1417,  1717,  8351, -1417, -1417,
    1719,  8379, -1417,  1913,  4310,   627,  3166,  1021, -1417,   501,
    1033,  9645,  9671,  9697,  9723,  5684,  1921,  1724, 11107,  1040,
    8407,  7731,   203,   203,   974,  1923,   974,  1924,   974,  1926,
   -1417, -1417, -1417, -1417,   974,  1929,  7033,  1930,  7731,  7731,
    7731,  7731, -1417, -1417,  5297, -1417,  1733,  1932,  8435,   527,
     536,   745, -1417,  1735,   906, -1417,  1743,   952, -1417,  1744,
    1115, -1417,  1044, -1417,  9749,  9775,  9801,  9827,  1058, -1417,
    1745,  5608, -1417,  1936,  7731,  7731,  1939,   974,  1940,   974,
    1944,   974, -1417,  1945,  7731,  7731,  7731,  7731,  5297,  1946,
    5297,  1061, -1417,  8463,  8491, -1417,  1189, -1417,  1244, -1417,
    1334, -1417,  8519,  8547,  8575,  8603, -1417, -1417,  1070, -1417,
    1947,  1948,  1949,  1950,  1953,  1969, -1417, -1417, -1417, -1417,
    5297,  1970, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     0,   260,   261,     0,     0,     0,
     255,     0,     0,     0,     0,   356,   357,   358,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   538,     0,
     405,   537,   509,   406,   408,   409,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   511,     0,   530,   513,   413,   414,   415,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   512,     0,     0,     0,     0,    66,    67,
       0,     0,   200,     0,     0,     0,   363,     0,   501,   538,
     420,     0,     0,     0,     0,   240,     0,   242,   243,   238,
     239,     0,   244,   245,   122,   130,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,   200,   538,     0,     0,   353,
       0,     0,     0,     0,     0,     0,     0,     0,   537,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
     483,   453,   459,     0,   454,   538,   420,     0,     0,     0,
       0,   537,     0,     0,   495,     0,     0,     0,     0,   236,
     237,     0,   537,     0,     0,   253,   254,     0,   200,     0,
     200,   537,     0,   538,     0,   359,     0,     0,    66,    67,
       0,     0,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   366,   365,   367,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,   198,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   229,     0,     0,
     428,   177,     0,   537,     0,   501,   538,   502,     0,     0,
     533,     0,   120,   120,     0,     0,     0,     0,   489,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   321,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   200,
       0,   444,   443,     0,     0,     0,     0,   200,   200,     0,
       0,     0,     0,     0,     0,     0,   271,     0,   200,     0,
       0,     0,     0,     0,   323,     0,     0,     0,     0,     0,
       0,     0,   218,   354,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,   466,     0,     0,
     467,     0,   468,     0,   469,     0,     0,     0,     0,     0,
       0,   365,   461,     0,   455,     0,     0,     0,   331,    66,
      67,     0,   235,     0,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,   257,   256,   223,     0,   224,     0,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,   531,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,   364,    59,    60,     0,     0,    59,     0,     0,
       0,     0,     0,   195,     0,     0,     0,     0,   201,     0,
       0,     0,   381,   380,   378,   379,   374,   376,   375,   377,
     369,   368,   370,   371,   372,   373,     0,     0,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   350,   351,
     352,     0,     0,     0,     0,   319,     0,     0,     0,   145,
     146,     0,   148,   149,     0,   151,   152,     0,   154,   155,
       0,     0,     0,     0,     0,     0,     0,   165,   200,     0,
       0,     0,     0,     0,   446,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,   334,     0,     0,   219,     0,     0,   215,
       0,     0,     0,   349,   348,     0,     0,     0,     0,     0,
     433,    68,    69,     0,   484,     0,     0,     0,     0,     0,
       0,   470,     0,   471,     0,   472,     0,   473,     0,     0,
     364,   456,   463,     0,   370,   462,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
       0,   225,   227,     0,   539,     0,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,    89,    74,     0,
     422,   421,   435,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   404,   392,     0,   394,   395,   396,   397,   398,
     399,   400,     0,     0,     0,   522,     0,   527,   518,   519,
     520,     0,     0,     0,     0,     0,   523,   524,   525,   441,
     529,   134,   139,   112,     0,     0,   514,     0,   516,     0,
     418,   425,   426,   510,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,   427,     0,     0,     0,     0,   535,     0,
       0,    44,     0,     0,     0,    57,     0,    35,    36,    37,
      38,    39,   424,   423,     0,     0,   507,    24,    22,     0,
       0,     0,     0,    25,     0,     0,   230,   534,    70,   123,
      71,   131,     0,     0,     0,   491,   492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,   322,   320,     0,   330,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   228,     0,
       0,     0,   190,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   300,
       0,   262,     0,     0,     0,     0,     0,     0,   324,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     422,   421,     0,   486,     0,   465,     0,     0,     0,     0,
       0,     0,     0,   457,     0,     0,   424,   423,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,   222,
       0,     0,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,     0,   430,     0,   429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    87,
       0,     0,    76,     0,     0,     0,     0,    79,   102,   104,
       0,     0,   499,     0,   110,     0,     0,     0,     0,     0,
     382,     0,     0,     0,     0,     0,    30,   432,   431,   505,
     503,    23,     0,     0,   506,   504,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,   328,     0,     0,   147,     0,   150,
       0,   153,     0,   156,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,   305,     0,   311,     0,   313,     0,   307,
       0,   309,     0,   272,   301,     0,     0,     0,   213,     0,
       0,     0,   335,     0,   217,   216,   355,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   458,     0,     0,     0,     0,   496,     0,
       0,     0,   248,     0,     0,     0,     0,     0,     0,    84,
       0,    88,     0,     0,     0,    80,     0,   232,   434,   231,
     393,   401,   402,   403,   528,     0,   438,   439,   440,     0,
       0,   417,   135,     0,   532,   140,   437,   515,   517,   419,
       0,     0,     0,    85,     0,     0,     0,    59,     0,     0,
       0,     0,    77,     0,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,     0,     0,    26,
      27,     0,    28,     0,     0,   124,   127,    72,    73,   161,
       0,     0,     0,     0,     0,     0,   164,     0,     0,   180,
     181,     0,     0,   166,   187,     0,     0,     0,     0,   157,
       0,   327,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,     0,     0,   200,   200,
       0,   282,     0,   284,     0,   286,     0,   453,     0,     0,
     312,   314,   308,   310,     0,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,   487,
       0,     0,     0,     0,   488,   169,   170,     0,     0,     0,
       0,   113,   117,     0,     0,   361,     0,     0,     0,    86,
       0,     0,     0,    78,     0,   436,     0,     0,     0,     0,
       0,    96,     0,     0,    90,     0,     0,     0,     0,   107,
       0,     0,   108,     0,   500,   202,   203,   204,   205,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   508,     0,
       0,   125,   128,     0,     0,   160,   167,   168,   172,     0,
       0,   182,     0,     0,   329,     0,   175,     0,     0,   318,
     186,   162,   174,   185,   189,   173,     0,   183,   188,     0,
       0,     0,     0,     0,     0,   450,     0,   449,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,   212,     0,     0,   211,     0,
       0,     0,   206,     0,     0,   332,    33,     0,     0,     0,
       0,     0,     0,   494,     0,   250,   249,     0,     0,     0,
       0,    97,     0,     0,    91,     0,     0,     0,   521,   526,
       0,   136,   138,     0,   141,   142,   143,    98,   100,    92,
      94,   103,   105,     0,   111,     0,    81,    45,     0,     0,
       0,   452,     0,     0,     0,    29,     0,   134,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   176,     0,   325,
     325,     0,   118,   119,   200,     0,   193,   194,     0,     0,
       0,     0,     0,     0,     0,   302,     0,     0,   200,     0,
       0,     0,     0,     0,   197,   196,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,     0,    99,   101,    93,
      95,    82,     0,   489,     0,     0,   498,     0,    41,     0,
       0,     0,    43,    58,     0,     0,     0,   343,   345,   344,
     346,   347,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   316,     0,     0,     0,
     267,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,   493,   251,     0,   362,     0,   137,     0,   144,   109,
       0,     0,     0,     0,     0,   126,   129,     0,     0,     0,
       0,     0,   326,   336,     0,     0,   337,     0,   191,     0,
     288,     0,     0,   290,     0,     0,   292,     0,     0,     0,
     303,     0,   263,     0,   200,     0,     0,     0,     0,     0,
       0,     0,   171,   116,     0,   132,     0,    49,     0,    55,
       0,     0,     0,   158,   184,     0,   340,     0,   341,   342,
     447,   276,     0,     0,   283,   277,     0,     0,   285,   278,
       0,     0,   287,     0,     0,     0,   269,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,   296,     0,   298,
     304,   315,   268,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   133,    46,     0,    53,     0,     0,     0,     0,
       0,     0,   279,     0,     0,   280,     0,     0,   281,     0,
       0,   214,     0,   208,     0,     0,     0,     0,     0,    47,
       0,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,   289,     0,   291,     0,   293,
       0,   209,     0,     0,     0,     0,    48,    50,     0,    51,
       0,     0,     0,     0,     0,     0,   478,   479,   480,   481,
       0,     0,    56,   338,   339,   295,   297,   299,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1417, -1417, -1417, -1417,   807, -1417, -1417, -1417, -1417,   252,
   -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417,  -342,   -68,     6,  2844, -1417,  1526, -1417, -1417,
   -1417, -1417, -1417,   376, -1417,   373, -1417, -1417, -1417, -1417,
   -1417, -1417,   799,  1983,    -2,  -496,  -257, -1417, -1417, -1417,
   -1417, -1417, -1417, -1417,  1985, -1417, -1417, -1417, -1417, -1417,
   -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1417, -1036, -1023,
   -1417, -1417,  1506, -1417,   370, -1417, -1417, -1417, -1417,  1539,
   -1417, -1417,   522, -1417, -1416,  2141,   723,  2030,  2254,  -246,
     660, -1417,    97,    13, -1417,  -364,    -3,   249
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   969,    91,    92,   696,  1480,  1486,
     957,  1161,  1667,  1868,   958,  1817,  1908,   959,  1870,   960,
     961,  1165,   349,   440,   184,   814,    93,   714,   452,  1607,
    1608,   453,  1662,  1129,  1312,  1130,  1315,   748,   751,   754,
     757,  1508,  1363,   678,   299,   416,   417,    96,    97,    98,
      99,   100,   101,   102,   300,  1052,  1763,  1834,   783,  1532,
    1535,  1538,  1792,  1796,  1800,  1853,  1856,  1859,  1048,  1049,
    1203,  1008,   745,   792,  1689,   104,   105,   106,   107,   301,
     186,   911,   502,   257,  1345,   302,   303,   304,   565,   313,
     942,  1153,   450,   445,   912,   451,   333,   306
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,    95,   497,   189,  1549,   528,   516,   342,   351,   414,
    1097,   776,   777,   633,   311,   635,  1246,   327,   531,   188,
     547,   862,   214,     4,   265,  1244,   646,   208,   209,   219,
     195,   192,   967,   940,   219,   951,   347,   348,   329,   821,
     273,   350,   315,  1235,   823,  1459,   214,  -502,   825,   827,
     576,  1779,   505,   506,   276,   183,   338,  1237,   339,   335,
    1239,   550,   305,  1241,   661,   340,   665,   276,   668,   193,
    1226,   587,  1359,   589,   552,   505,   506,  1786,   276,   347,
     348,  1788,   322,   712,     5,  1350,   713,   505,   506,  1615,
    -507,  1400,   194,  1401,   323,   326,   266,   278,   210,   279,
     267,   191,   927,   187,   507,   211,   659,   197,    48,    49,
      50,    51,   268,   198,   341,   667,   811,    56,   812,   199,
      59,   711,   554,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   663,   244,
     410,   206,   245,   207,   386,   387,   388,   389,   548,   858,
     391,   952,   953,   954,   955,  1236,   392,   393,  1143,   280,
     927,   200,   398,   399,   343,   344,   345,   346,   276,  1238,
     415,  1327,  1240,    89,   201,  1242,  1671,   274,   863,   519,
     446,   446,   927,   347,   348,  1460,   520,   202,   446,   551,
     529,   352,  1685,   353,  1098,   354,   276,   183,   305,    89,
     183,   968,   553,   305,   312,   215,   328,   305,   203,   549,
     305,   454,   216,  1244,   305,   305,   305,   305,   196,   220,
     305,   305,   305,   941,   946,   316,   956,   330,   822,   215,
     275,   769,   770,   824,   305,   276,   945,   826,   828,  1780,
     336,    89,   109,   505,   506,   190,   860,   337,   505,   506,
     555,   785,   505,   506,   968,   212,   305,   305,   305,   343,
     344,   345,   346,   660,   344,   345,   346,   269,   213,   270,
     305,   305,   343,   344,   345,   346,   411,   412,   347,   348,
     444,   448,   223,   305,   545,   305,   933,   260,   248,   204,
     261,   347,   348,   262,  1144,  1145,   277,   505,   506,   283,
     205,   571,   284,   249,   250,   664,   344,   345,   346,   314,
     928,   845,   217,  1402,   934,  1403,   859,   344,   345,   346,
     324,   446,   218,   305,   305,   853,   210,   343,   344,   345,
     346,   221,   669,   944,   347,   348,   305,   222,   343,   344,
     345,   346,  1262,   505,   506,   604,   347,   348,   222,   343,
     344,   345,   346,   224,  1819,   947,   225,   347,   348,  1404,
     226,  1405,   347,   348,   446,   446,   446,   446,   446,   446,
     305,   446,   446,  -505,   446,   446,   446,   446,   446,   231,
     252,   253,   446,   446,   446,   446,   446,   276,   227,   276,
     254,  1039,   347,   348,   347,   348,   649,   255,   252,   253,
     347,   348,  1040,  -506,   657,  -504,   305,   236,   254,   672,
    1041,  1042,  1043,   505,   506,   263,  1044,  1045,  1046,  1047,
     413,   595,   505,   506,   232,   505,   506,   505,   506,   771,
    1039,   715,   447,   447,   713,   247,   505,   506,   246,   508,
     447,  1040,   518,   778,   305,  1891,   505,   506,   455,  1041,
    1042,  1043,   784,   347,   348,  1044,  1045,  1046,  1047,  1393,
    1394,   438,  1222,   439,  -508,   634,   251,   636,   637,   638,
     340,   640,   641,   259,   643,   644,   645,   271,   647,   305,
     305,   272,   651,   652,   653,   654,   655,   314,   750,   753,
     756,   759,   505,   506,   281,   415,   415,  1243,   569,  1039,
     570,  1026,   430,   431,   432,   433,   434,   340,  1245,  1106,
    1040,   435,  1110,   505,   506,   505,   506,   282,  1041,  1042,
    1043,   305,   305,   305,  1044,  1045,  1046,  1047,   721,  1544,
     722,  1628,   872,   276,   505,   506,  1416,   505,   506,   505,
     506,   233,   505,   506,   234,   285,   235,   305,   286,  1039,
    1630,   505,   506,  1632,   305,  1640,   443,   112,  1642,   287,
    1040,   256,   258,   307,   264,   505,   506,  1643,  1041,  1042,
    1043,  1442,  1443,   447,  1044,  1045,  1046,  1047,   505,   506,
     593,  1751,   594,  1699,   929,  1702,   703,  1705,   935,   340,
     305,   704,   139,   140,   141,   142,   143,   144,   308,   505,
     506,   148,   149,   150,   151,  1752,   505,   506,   707,   153,
     154,   155,   319,   708,   156,  1754,   447,   447,   447,   447,
     447,   447,  1757,   447,   447,   161,   447,   447,   447,   447,
     447,   505,   506,   309,   447,   447,   447,   447,   447,   656,
     310,   658,   505,   506,   505,   506,   317,  1765,   305,   432,
     433,   434,   305,   318,   320,  1755,   435,   321,  1767,  1206,
    1822,  1208,  1039,  1210,   334,  1212,  1244,   380,   228,  1244,
     936,   229,  1244,  1040,   230,   710,   505,   506,   505,   506,
     711,  1041,  1042,  1043,   705,  1152,   706,  1044,  1045,  1046,
    1047,   305,  1823,   340,  1836,   305,   381,   382,   446,   566,
     811,   276,   812,   446,   505,   506,   813,   305,   305,   394,
     164,   165,   166,   505,   506,   383,  1039,  1805,   909,   384,
    1874,   983,   173,   711,   174,    89,   385,  1040,   811,  1875,
     812,   305,   872,  1173,   838,  1041,  1042,  1043,   721,   390,
     395,  1044,  1045,  1046,  1047,   347,   348,   396,   397,  1686,
    1687,   237,   305,  1116,   238,  1688,  -503,   239,   400,   240,
    1176,  1321,  1322,   500,   501,   721,  1325,  1326,  1758,  1597,
     401,   509,  1244,   556,  1598,   517,   557,   402,  1851,   558,
    1854,   559,  1857,  1107,   418,   815,  1111,   419,  1860,  1564,
     436,  1328,  1115,  1117,   721,   542,   727,   543,   977,   544,
     305,   437,   182,   981,   183,   441,   463,  1341,   590,   305,
     591,   305,   544,   305,   811,   305,   812,   183,  1244,   896,
     305,  1244,  1832,   468,  1244,   305,   473,  1244,   700,   474,
     701,  1896,   702,  1898,  1039,  1900,   721,   183,   731,   241,
    1690,  1691,   242,   305,   243,  1040,  1688,   305,   721,   811,
     737,   812,   479,  1041,  1042,  1043,  1281,   480,   446,  1044,
    1045,  1046,  1047,  1244,   721,  1244,   831,  1244,   484,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     567,   433,   434,   305,  1167,  1168,   485,   435,   446,   305,
     446,   446,  1528,  1529,  1333,   856,  1540,   857,   811,   721,
     812,   949,   446,   917,   446,   811,   486,   812,  1128,   721,
     919,  1022,   487,  1447,  1448,   721,   530,  1023,  1451,  1452,
    1135,  1136,   721,   721,  1064,  1065,  1140,  1141,   276,   492,
     498,   305,   305,   305,   305,   721,   721,  1066,  1083,   488,
    1876,   476,   477,   478,  1454,   489,   481,   482,   483,   811,
     447,   812,   490,   979,   721,   447,   446,   495,  1118,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   491,   499,   305,   305,   435,   305,   510,
     305,   305,   524,   525,   305,   305,  1565,  1815,  1124,   305,
    1126,  1127,  1115,  1117,   511,  1039,   537,   538,   811,   721,
     812,  1113,  1132,  1310,  1133,   811,  1040,   812,  1167,  1168,
    1313,  1182,   512,  1183,  1041,  1042,  1043,   774,   775,   521,
    1044,  1045,  1046,  1047,   522,   501,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
    1188,  1039,  1189,   721,   435,  1219,  1282,   721,   721,  1263,
    1268,   532,  1040,   721,   523,  1269,  1172,   721,   527,  1270,
    1041,  1042,  1043,  1039,   340,  1329,  1044,  1045,  1046,  1047,
     721,   721,  1271,  1273,  1040,   533,   305,   305,   305,  1474,
     534,   535,  1041,  1042,  1043,   536,   539,   305,  1044,  1045,
    1046,  1047,   721,  1335,  1274,  1336,   721,   540,  1337,  1287,
    1288,  1878,   568,   572,  1292,  1293,   721,   721,  1338,  1339,
     447,   721,   721,  1340,  1377,  1484,   541,  1485,  1694,  1516,
     578,  1517,   446,   446,   721,   579,  1553,   446,   446,  1603,
     721,  1604,  1619,   721,  1484,  1620,  1641,   276,   546,  1484,
     447,  1683,   447,   447,  1707,   584,  1708,  1880,   721,   183,
    1723,   305,   585,  1725,   447,  1726,   447,   586,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   711,   305,  1728,   588,   435,     7,     8,   305,
     314,  1356,  1484,   606,  1733,   305,   607,   305,   305,  1310,
     610,  1735,   305,   305,  1313,   305,  1736,   305,  1484,   305,
    1739,   305,   305,   305,  1039,   721,   435,  1747,   447,  1664,
     721,  1603,  1766,  1816,   721,  1040,  1835,   602,   603,   305,
    1455,   670,   671,  1041,  1042,  1043,   721,   673,  1837,  1044,
    1045,  1046,  1047,  1484,   305,  1846,   182,   721,   305,  1883,
     305,   674,    24,    25,   675,    27,    28,   676,    30,   677,
      32,  1888,    33,  1889,  1484,   717,  1910,    38,    39,   718,
      41,    42,    43,  1920,   734,  1921,    46,   738,   739,   740,
     766,   743,   744,   767,   446,   446,   791,   768,  1039,   446,
     446,   793,   796,  1029,   794,   803,   804,   810,   843,  1040,
    1035,   816,   446,   818,   819,   820,  1050,  1041,  1042,  1043,
      67,    68,    69,  1044,  1045,  1046,  1047,   846,   854,   855,
    1882,   867,  1457,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   276,   868,   899,   900,   435,   901,   305,   924,
    1467,   902,   903,  1039,   904,   914,   915,  1665,   446,   916,
     921,   305,   922,   923,  1040,   938,   925,   930,   931,   939,
    1455,   966,  1041,  1042,  1043,   973,   976,  1492,  1044,  1045,
    1046,  1047,   978,   980,   987,   984,   988,   989,   991,   992,
     799,  1710,   993,   994,   447,   447,   996,   305,   305,   447,
     447,   997,   998,  1007,  1913,  1002,   415,   415,  1009,   314,
    1011,  1012,  1456,  1013,  1014,  1015,  1016,  1523,  1017,  1018,
    1025,  1059,  1073,  1032,  1089,   305,  1033,   305,  1074,   305,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,  1076,  1039,   305,  1090,   435,  1077,  1078,   443,
     112,   305,  1092,  1091,  1040,     7,     8,  1102,  1489,  1914,
    1100,   305,  1041,  1042,  1043,   305,  1569,  1103,  1044,  1045,
    1046,  1047,  1104,  1108,  1109,  1137,  1139,  1142,  1147,  1148,
    1154,  1582,  1585,  1586,  1150,   139,   140,   141,   142,   143,
     144,   305,  1151,  1166,   148,   149,   150,   151,  1162,  1163,
    1171,  1178,   153,   154,   155,  1186,   420,   156,  1164,  1192,
    1193,  1197,   305,  1198,  1200,  1201,  1181,  1806,   161,   674,
      24,    25,   675,    27,    28,   676,    30,   677,    32,  1204,
      33,  1205,  1214,  1215,  1216,    38,    39,  1217,    41,    42,
      43,  1218,  1220,  1230,    46,  1232,   447,   447,   305,  1915,
    1231,   447,   447,   305,  1234,   185,  1233,  1253,  1247,  1248,
    1257,  1249,  1250,  1251,   447,  1254,  1255,  1256,  1227,  1228,
    1229,  1258,  1259,  1260,   305,  1278,  1283,  1284,    67,    68,
      69,  1289,  1306,  1291,  1295,  1297,  1298,   305,     7,     8,
     446,  1299,  1286,  1305,   314,  1307,  1308,  1331,  1317,  1309,
     276,  1342,  1330,   164,   165,   166,  1348,  1347,  1349,   305,
     447,  1352,  1357,  1358,  1360,   173,  1361,   174,    89,  1366,
    1362,  1369,  1367,  1368,  1370,   305,  1372,  1373,   305,  1374,
    1375,  1380,   415,  1390,  1381,  1391,  1392,   332,  1406,  1398,
    1399,  1410,  1411,   811,   305,   812,  1412,  1413,   851,   305,
    1428,  1420,   674,    24,    25,   675,    27,    28,   676,    30,
     677,    32,  1421,    33,  1425,  1435,  1436,  1441,    38,    39,
    1437,    41,    42,    43,  1445,  1458,  1461,    46,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,  1444,  1464,  1469,   305,   435,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,    67,    68,    69,   305,   435,  1470,  1472,  1505,  1475,
    1476,  1477,  1478,   592,   403,   404,   405,   407,   409,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
    1488,   442,  1507,  1496,   435,   449,  1497,  1498,  1501,  1503,
    1775,     7,     8,  1504,  1506,  1510,  1511,  1512,  1513,   456,
     458,   461,   462,  1514,   464,   458,   466,   467,  1515,   458,
     470,   471,   305,  1518,   305,  1531,   458,  1415,  1534,  1537,
    1545,   852,  1548,  1541,  1552,  1556,  1571,   305,  1574,  1578,
    1587,  1588,  1589,  1590,   494,  1591,  1595,  1593,  1594,  1596,
    1602,  1605,  1614,   503,   504,  1616,  1617,  1618,  1623,  1626,
    1635,  1644,   504,  1624,  1629,   674,    24,    25,   675,    27,
      28,   676,    30,   677,    32,  1627,    33,  1637,  1631,  1650,
    1633,    38,    39,  1655,    41,    42,    43,  1638,  1842,  1656,
      46,  1657,   447,   305,  1658,   561,   563,   458,  1659,  1660,
    1661,   446,   314,  1673,  1677,  1678,  1679,   573,   574,   575,
    1666,   577,  1680,  1681,  1682,   580,   581,   582,  1684,  1706,
     583,  1713,  1724,  1729,    67,    68,    69,  1730,   305,  1737,
    1740,  1743,  1744,  1746,  1748,  1760,  1764,   599,   601,  1773,
    1761,  1784,  1789,  1791,  1495,   446,  1794,   446,  1795,  1798,
    1799,   608,   609,  1802,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,  1803,   446,  1808,  1830,
    1824,  1826,  1530,  1828,  1533,   642,  1536,  1843,  1844,  1852,
    1855,   648,  1858,   650,  1027,  1861,  1863,  1871,  1872,  1877,
    1547,  1869,  1892,  1550,  1551,  1895,  1897,  1879,  1881,  1890,
    1899,  1901,  1907,  1922,  1923,  1924,  1925,   679,   458,  1926,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,  1927,  1929,   697,   698,   716,
    1351,  1676,  1776,  1675,  1364,  1906,    94,  1909,   103,   746,
    1692,  1471,     0,     0,     0,     0,   561,     0,     0,     0,
       0,     0,   725,     0,     0,     0,     0,   730,     0,     0,
       0,     0,   735,   736,     0,     0,     0,  1928,   741,   742,
       0,     0,     0,   747,   749,   752,   755,   758,   760,   761,
     762,   458,   458,     0,  1202,     0,     0,     0,     0,     0,
       0,     0,   699,     0,     0,     0,     0,     0,     0,   779,
     780,   781,   403,   404,   782,     0,     0,     0,   786,   787,
     788,   789,   790,     0,     0,     0,   795,     0,   797,   798,
       0,     0,     0,   458,   458,   458,     0,     0,   805,   806,
     807,   808,   809,     0,     0,     0,     0,     0,   817,     0,
       0,     0,     0,   447,     0,     0,     0,     0,     0,   458,
       0,     0,     0,     0,     0,   832,   834,     0,   836,   837,
       7,     8,     0,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,   808,
     809,   435,   836,   837,     0,     0,     0,   447,     0,   447,
       0,   865,   458,     0,     0,     0,   869,     0,     0,     0,
    1698,     0,  1701,     0,  1704,     0,     0,     0,     0,     0,
       0,     0,  1712,     0,     0,  1715,     0,     0,     0,   447,
       0,     0,     0,     0,   674,    24,    25,   675,    27,    28,
     676,    30,   677,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,   937,     0,  1741,
       0,     0,     0,  1745,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,    67,    68,    69,     0,     0,     0,   964,
     965,   459,     0,   458,   971,   972,   459,   458,   975,     0,
     459,     0,     0,     0,     0,     0,   982,   459,     0,   834,
     985,     0,  1785,     0,     0,     0,  1787,     0,     0,     0,
       0,     0,     0,   999,     0,     0,     0,     0,     0,     0,
       0,     0,  1005,     0,     0,     0,     0,     0,     0,  1809,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1028,   458,     0,     0,     0,     0,     0,
       0,  1030,  1031,     0,     0,     0,     0,  1034,     0,     0,
       0,     0,     0,     0,     0,     0,   562,     0,   459,     0,
    1058,     0,     0,  1060,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,  1849,  1850,     0,     0,     0,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
       0,   458,     0,   458,   472,   458,     0,   458,     0,     0,
       0,     0,   458,     0,     0,     0,     0,   458,     0,     0,
       0,     0,     0,  1093,     0,  1095,  1096,     0,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     674,    24,    25,   675,    27,    28,   676,    30,   677,    32,
       0,    33,   526,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,  1119,     0,    46,     0,     0,     0,     0,
       0,  1120,  1121,  1122,     0,   458,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
       0,     0,     0,  1131,     0,     0,     0,     0,  1134,    67,
      68,    69,     0,     0,     0,   460,     0,  1138,     0,     0,
     465,     0,     0,  1146,   469,     0,     0,   596,   597,     0,
       0,   475,     0,   458,   458,   458,   458,   562,     0,  1160,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     674,    24,    25,   675,    27,    28,   676,    30,   677,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,   459,   459,   639,    46,     0,     0,     0,  1051,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,     0,     0,     0,     0,   913,     0,     0,     0,
       0,  1207,     0,  1209,     0,  1211,     0,  1213,     0,    67,
      68,    69,     0,     0,   459,   459,   459,     0,     0,     0,
       0,     7,     8,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
     459,   435,     0,     0,     0,     0,     0,   835,  1526,     0,
    1527,     0,     0,     0,     0,     0,     0,     0,  1261,     0,
       0,     0,     0,  1264,     0,  1265,  1266,  1267,     0,     0,
       0,     0,     0,  1272,     0,     0,     0,     0,     0,  1094,
       0,     0,     0,   459,     0,   674,    24,    25,   675,    27,
      28,   676,    30,   677,    32,  1290,    33,     0,     0,  1294,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   680,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
    1334,     0,   435,     0,    67,    68,    69,     0,     0,     0,
     765,  1343,  1344,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1353,  1355,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,   459,     0,   435,     0,   459,     0,
       0,     0,     0,     0,     0,     0,   763,   764,     0,     0,
     835,   986,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1395,  1396,  1397,  1099,     0,     7,     8,     0,     0,
       0,  1407,     0,  1409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1414,     0,     0,     0,   800,   801,
     802,     0,   458,     0,     0,   459,     0,  1426,     0,     0,
       0,     0,   926,     0,     0,     0,   932,     0,     0,     0,
       0,     0,     0,     0,   829,     0,     0,     0,  1438,  1439,
    1440,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     674,    24,    25,   675,    27,    28,   676,    30,   677,    32,
       0,    33,     0,   459,     0,     0,    38,    39,     0,    41,
      42,    43,   459,     0,   459,    46,   459,   866,   459,     0,
       0,     0,     0,   459,     0,     0,     0,  1468,   459,     0,
       0,     7,     8,  1149,     0,     0,     0,     0,     0,     0,
       0,  1481,     0,     0,     0,  1006,  1487,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,  1493,
    1494,     0,     0,     0,     0,     0,  1499,  1500,     0,     0,
       0,  1502,     0,     0,     0,     0,     0,     0,     0,  1509,
       0,     0,     0,     0,     0,     0,   459,     0,     0,   458,
     458,  1521,     0,  1522,     0,   674,    24,    25,   675,    27,
      28,   676,    30,   677,    32,  1539,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,   458,   970,  1221,
      46,   458,   974,     0,  1554,     0,     0,     0,     0,  1557,
    1558,  1559,  1560,     0,   459,   459,   459,   459,     0,     0,
       0,     0,  1568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,  1101,  1584,     0,
       0,  1105,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,  1024,
     435,  1599,  1600,     0,     0,     0,     0,     0,  1621,  1606,
       0,     0,   459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1125,     0,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,  1762,  1625,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,  1079,     0,  1080,     0,
    1081,     0,  1082,  1639,     0,   561,     0,  1085,     0,     0,
       0,     0,  1088,     0,     0,     0,     0,     0,     0,     0,
       0,  1651,     0,  1652,     0,     0,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1663,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1184,
    1185,     0,  1187,     0,  1190,  1191,     0,  1668,  1194,  1195,
       0,     0,  1672,     0,     0,     0,     0,     0,     0,     0,
    1123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,     0,     0,     0,     0,     0,  1697,     0,  1700,
       0,  1703,     0,     0,     0,     0,     0,     0,     7,     8,
       0,   458,     0,     0,     0,  1716,  1717,  1718,  1719,  1720,
       0,     0,     0,     0,     0,     0,     0,     0,  1155,  1156,
    1157,  1158,     0,     0,     0,     0,     0,     0,  1731,  1732,
       0,     0,     0,  1734,     0,     0,     0,     0,     0,     0,
       0,  1196,     0,  1738,     0,     0,     0,     0,     0,     0,
    1275,  1276,  1277,     0,  1749,     0,     0,     0,     0,     0,
       0,  1285,   674,    24,    25,   675,    27,    28,   676,    30,
     677,    32,     0,    33,     0,  1252,  1199,     0,    38,    39,
       0,    41,    42,    43,  1774,     0,     0,    46,     0,  1487,
       0,     0,     0,     0,     0,     0,  1782,     0,     0,     0,
       0,     0,     0,   459,     0,     0,     0,     0,     0,     0,
    1793,     0,     0,  1797,     0,     0,  1801,     0,     0,     0,
    1804,    67,    68,    69,   458,  1346,   458,  1811,  1812,  1813,
    1814,     0,     0,     0,     0,     0,     0,  1818,     0,     0,
    1820,     0,     0,     0,     0,     0,     0,  1365,     0,     0,
       0,     0,     0,  1371,     0,     0,     0,     0,     0,  1376,
       0,  1378,  1379,     0,     0,  1323,  1382,  1383,     0,  1384,
       0,  1385,     0,  1386,     0,  1387,  1388,  1389,     0,     0,
    1848,     0,     0,     0,  1332,     0,     0,     0,     0,     0,
       0,  1833,     0,  1408,     0,   458,     0,  1864,  1865,  1866,
    1867,     0,     0,     0,     0,     0,     0,     0,  1419,     0,
    1449,     0,  1423,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1893,  1894,   839,     0,     0,     0,     0,
     459,   459,     0,  1902,  1903,  1904,  1905,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   566,     0,     0,     0,   435,     0,     0,   459,     0,
       0,     0,   459,     0,     0,   873,   874,   875,   876,   877,
     878,   879,   880,   881,   882,   883,     0,   885,   886,   887,
     888,   889,   890,   891,     0,     0,     0,   895,   897,   898,
    1453,     0,  1479,     0,     0,     0,     0,   906,   907,   908,
       0,   910,     0,     0,     0,  1491,     0,     0,   918,   920,
       0,     0,     0,     0,     0,     0,     0,  1424,     0,     0,
       0,     0,     0,     0,     0,     0,   943,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,  1346,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   562,     0,  1561,     0,
     435,     0,     0,     0,     0,  1570,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1577,     0,   459,     0,  1581,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   567,   433,   434,  1601,  1555,     0,     0,   435,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,  1519,  1520,  1346,     0,   435,     0,
     662,   459,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   459,     0,     0,     0,     0,     0,     0,   110,
     288,     0,  1636,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,  1346,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,  1346,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,  1709,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,  1159,     0,   459,     0,   459,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,  1592,     0,     0,   435,     0,     0,     0,
       0,  1653,     0,     0,     0,     0,  1179,  1180,     0,  1742,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,  1759,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   513,  1546,     0,   459,     0,   177,     0,
       0,     0,     0,   515,     0,  1693,     0,     0,   181,     0,
     255,   564,     0,     0,     0,     0,   110,   111,   112,     0,
       0,     0,   113,   114,   115,     0,  1714,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
    1622,  1346,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,   161,  1296,     0,     0,
       0,     0,     0,  1300,  1301,  1302,  1303,  1304,  1654,   322,
     112,     0,     0,  1311,  1314,     0,     0,  1318,  1319,  1320,
       0,     0,     0,     0,  1324,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   139,   140,   141,   142,   143,
     144,     0,  1346,     0,   148,   149,   150,   151,     0,  1807,
       0,  1810,   153,   154,   155,     0,     0,   156,     0,     0,
       0,     0,     0,     0,   162,     0,     0,     0,   161,     0,
     163,   164,   165,   166,   167,     0,     0,     0,   168,   169,
     170,   171,   172,   173,     0,   174,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,     0,     0,     0,   177,     0,     0,     0,     0,
     178,     0,   179,     0,   180,   181,     0,   182,     0,   183,
    1862,     0,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,  1429,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,  1434,     0,
       0,     0,     0,   164,   165,   166,     0,     0,     0,     0,
    1772,  1446,     0,     0,     0,   173,  1450,   174,    89,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,  1462,  1463,   110,   288,  1465,
    1466,     0,     0,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   290,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,  1573,     0,     0,  1575,  1576,     0,     0,     0,
       0,  1579,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,  1831,     0,     0,     0,
     435,   163,     0,     0,     0,   167,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   457,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   181,     0,     0,   564,
     110,   288,   112,     0,     0,     0,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   290,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,   291,     0,     0,   292,     0,     0,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1727,   566,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,   167,   566,
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
      52,     0,     0,     0,     0,    56,     0,     0,    59,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     720,   433,   434,     0,     0,     0,     0,   435,     0,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     720,   433,   434,     0,     0,     0,     0,   435,     0,     0,
     163,   164,   165,   166,   167,     0,     0,     0,   168,   169,
     170,   171,   172,   173,     0,   174,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   296,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,   110,   331,   112,   181,     0,  1580,   113,   114,
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
     847,   174,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   176,     0,   950,
       0,   177,     0,     0,     0,     0,   297,     0,     0,     0,
       0,   181,     0,  1354,     0,     0,     0,     0,  1084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,     0,  1280,     0,   168,
     169,   170,   171,   172,   173,     0,   174,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   331,   112,   181,     0,  1567,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   163,   164,   165,
     166,   167,     0,     0,     0,   168,   169,   170,   171,   172,
     173,     0,   174,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   176,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,   289,   181,     0,  1583,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   290,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,   443,   112,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   297,     0,   110,   288,  1417,   181,     0,
     298,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,   164,   165,   166,   145,   146,
     147,     0,     0,     0,     0,   152,     0,   173,     0,   174,
      89,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,   325,   112,   293,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   148,   149,   150,
     151,     0,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     296,     0,     0,     0,   177,     0,     0,     0,     0,   297,
       0,   110,   288,     0,   181,     0,  1418,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,   164,   165,   166,     0,
       0,     0,     0,     0,   145,   146,   147,     0,   173,     0,
     174,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,     0,     0,     0,   291,     0,     0,   292,     0,   112,
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
     145,   146,   147,     0,   173,     0,   174,   152,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,   674,    24,    25,   675,    27,    28,   676,    30,
     677,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   167,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,     0,    89,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,   175,   457,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,   110,   288,     0,   181,     0,   560,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   290,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,  1562,     0,  1563,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   167,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   457,     0,
       0,     0,   177,     0,     0,     0,     0,   297,     0,   110,
     288,     0,   181,     0,   833,   113,   114,   115,     0,     0,
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
     435,     0,     0,     0,     0,     0,     0,  1695,     0,  1696,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   296,     0,     0,     0,   177,     0,
       0,     0,     0,   297,     0,   110,   288,     0,   181,     0,
    1422,   113,   114,   115,     0,     0,   116,   117,   118,   119,
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
       0,     0,     0,     0,     0,   948,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
    1546,     0,     0,     0,   177,     0,     0,     0,     0,   515,
       0,   110,   331,     0,   181,     0,   255,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   331,   157,   158,   159,     0,   113,   114,   115,     0,
     160,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,   163,     0,  1001,     0,   167,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     181,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   167,     0,
       0,     0,   168,   169,   170,   171,   172,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   513,   514,     0,     0,     0,   177,
       0,     0,     0,     0,   515,     0,   110,   331,   112,   181,
       0,   255,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,   161,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,  1054,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1075,     0,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
     163,   164,   165,   166,   167,  1112,     0,     0,   168,   169,
     170,   171,   172,   173,     0,   174,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,     0,     0,     0,   177,   110,   288,     0,     0,
     297,     0,   113,   114,   115,   181,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,   167,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   457,     0,     0,     0,   177,   110,   331,     0,     0,
     297,     0,   113,   114,   115,   181,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   331,   157,   158,   159,
       0,   113,   114,   115,     0,   160,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     163,     0,  1524,     0,   167,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,     0,     0,     0,   177,     0,     0,     0,     0,
     297,   406,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   297,
     110,   331,   408,     0,   181,     0,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     331,   157,   158,   159,     0,   113,   114,   115,     0,   160,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   163,     0,  1543,     0,   167,     0,
       0,     0,   168,   169,   170,   171,   172,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   176,     0,     0,     0,   177,
       0,     0,     0,     0,   297,   598,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   176,     0,     0,     0,   177,     0,
       0,     0,     0,   297,   110,   331,   600,     0,   181,     0,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1609,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,   177,     0,    -4,    -4,    -4,   297,     0,
       0,    -4,    -4,   181,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     6,     0,     0,     0,     0,
      -4,     0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     9,
      10,     0,     0,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,    11,    12,    13,     0,     0,
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
       0,     0,    88,     0,    89,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1611,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1612,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1613,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1645,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,  1711,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1721,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1722,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1750,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1753,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,  1756,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1783,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1790,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1825,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1827,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,  1829,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1847,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1873,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1911,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,  1912,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,     0,     0,  1916,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,  1917,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1918,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1919,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   830,
       0,     0,     0,     0,   772,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     709,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   772,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   773,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   844,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   884,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     892,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   893,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   894,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   905,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1036,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1037,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1038,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1069,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1177,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1223,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1224,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1279,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1430,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1431,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1432,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1433,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1482,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1483,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1490,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1646,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1647,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1648,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1649,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1669,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1670,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1674,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1768,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1769,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1770,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1771,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1778,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1781,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1821,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1838,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1839,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1840,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1841,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1884,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1885,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1886,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1887,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   811,     0,   812,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,   666,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,   850,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,   864,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,   871,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,   963,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,  1062,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,  1063,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,  1067,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
    1068,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,  1071,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,  1087,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,  1114,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,  1170,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,  1175,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,  1427,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,  1473,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,  1634,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   719,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   723,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   724,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   726,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   728,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     729,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   732,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   733,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   830,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   840,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   841,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   842,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   848,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   849,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   861,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     870,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   962,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   990,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   995,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1000,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1003,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1004,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1010,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1019,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1020,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1021,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1053,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1055,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1056,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1057,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1061,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1070,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1086,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1169,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1174,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1316,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1525,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1542,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1566,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1777,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1845,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435
};

static const yytype_int16 yycheck[] =
{
       3,     3,   248,     6,  1420,     4,   263,     7,     4,     4,
       7,   507,   508,   377,     4,   379,  1052,     5,   275,     6,
       5,     7,     4,     6,     4,  1048,   390,    21,    22,     4,
       6,    82,     6,     4,     4,     4,   193,   194,     5,     5,
       4,   109,     4,     6,     5,     4,     4,   204,     5,     5,
     201,     6,   187,   188,    57,   206,   197,     6,   199,     6,
       6,     5,    65,     6,   406,   206,   408,    70,   410,   197,
     205,   328,     6,   330,     5,   187,   188,     6,    81,   193,
     194,     6,     4,   200,     0,     6,   203,   187,   188,  1505,
     204,   203,   197,   205,    81,    82,    76,     4,   197,     6,
      80,    13,     7,     6,   204,   204,     7,     6,   103,   104,
     105,   106,    92,     6,   108,     7,   198,   112,   200,     6,
     115,   203,     5,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     7,    79,
       4,   197,    82,   199,   148,   149,   150,   151,   143,     7,
     154,   130,   131,   132,   133,   128,   160,   161,     4,    76,
       7,     6,   166,   167,   174,   175,   176,   177,   181,   128,
     182,     7,   128,   173,   197,   128,  1602,   151,   174,   197,
     193,   194,     7,   193,   194,   154,   204,     6,   201,   143,
     199,   197,  1618,   199,   201,   201,   209,   206,   211,   173,
     206,   185,   143,   216,   204,   197,   204,   220,     6,   204,
     223,   208,   204,  1246,   227,   228,   229,   230,   204,   204,
     233,   234,   235,   204,   204,   197,   205,   204,   204,   197,
     204,   498,   499,   204,   247,   248,   204,   204,   204,   204,
     197,   173,     3,   187,   188,     6,   598,   204,   187,   188,
     143,   518,   187,   188,   185,   197,   269,   270,   271,   174,
     175,   176,   177,   174,   175,   176,   177,    82,   197,    84,
     283,   284,   174,   175,   176,   177,   140,   141,   193,   194,
     193,   194,    86,   296,   288,   298,   201,    76,   140,   199,
      79,   193,   194,    82,   140,   141,    57,   187,   188,    79,
     199,   305,    82,   155,   156,   174,   175,   176,   177,    70,
     662,   578,   197,   203,   666,   205,   174,   175,   176,   177,
      81,   334,   197,   336,   337,   592,   197,   174,   175,   176,
     177,   197,   410,   204,   193,   194,   349,   197,   174,   175,
     176,   177,   201,   187,   188,   342,   193,   194,   197,   174,
     175,   176,   177,    82,  1780,   204,    82,   193,   194,   203,
       6,   205,   193,   194,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   204,   387,   388,   389,   390,   391,    82,
     187,   188,   395,   396,   397,   398,   399,   400,   204,   402,
     197,    99,   193,   194,   193,   194,   393,   204,   187,   188,
     193,   194,   110,   204,   401,   204,   419,    84,   197,   413,
     118,   119,   120,   187,   188,   204,   124,   125,   126,   127,
     181,   334,   187,   188,    82,   187,   188,   187,   188,   203,
      99,   200,   193,   194,   203,    79,   187,   188,   197,   204,
     201,   110,   204,   203,   457,  1871,   187,   188,   209,   118,
     119,   120,   203,   193,   194,   124,   125,   126,   127,     6,
       7,   197,   203,   199,   204,   378,   204,   380,   381,   382,
     206,   384,   385,   204,   387,   388,   389,    82,   391,   492,
     493,    79,   395,   396,   397,   398,   399,   248,   485,   486,
     487,   488,   187,   188,    79,   507,   508,   205,   197,    99,
     199,   768,   187,   188,   189,   190,   191,   206,   203,   861,
     110,   196,   864,   187,   188,   187,   188,    82,   118,   119,
     120,   534,   535,   536,   124,   125,   126,   127,   203,   203,
     205,   203,   610,   546,   187,   188,   205,   187,   188,   187,
     188,    79,   187,   188,    82,     4,    84,   560,     4,    99,
     203,   187,   188,   203,   567,   203,     4,     5,   203,     4,
     110,    49,    50,     4,    52,   187,   188,   203,   118,   119,
     120,     6,     7,   334,   124,   125,   126,   127,   187,   188,
     197,   203,   199,  1629,   662,  1631,   198,  1633,   666,   206,
     603,   203,    40,    41,    42,    43,    44,    45,   197,   187,
     188,    49,    50,    51,    52,   205,   187,   188,   198,    57,
      58,    59,     6,   203,    62,   203,   377,   378,   379,   380,
     381,   382,   203,   384,   385,    73,   387,   388,   389,   390,
     391,   187,   188,   197,   395,   396,   397,   398,   399,   400,
     197,   402,   187,   188,   187,   188,   197,   203,   661,   189,
     190,   191,   665,   197,     6,   205,   196,   199,   203,  1011,
     203,  1013,    99,  1015,   199,  1017,  1699,   197,    76,  1702,
     667,    79,  1705,   110,    82,   198,   187,   188,   187,   188,
     203,   118,   119,   120,   197,   941,   199,   124,   125,   126,
     127,   704,   203,   206,   203,   708,   197,   197,   711,     8,
     198,   714,   200,   716,   187,   188,   204,   720,   721,     7,
     158,   159,   160,   187,   188,   197,    99,  1763,   198,   197,
     203,   718,   170,   203,   172,   173,   197,   110,   198,   203,
     200,   744,   810,   198,   204,   118,   119,   120,   203,   197,
     197,   124,   125,   126,   127,   193,   194,   197,   197,   103,
     104,    76,   765,   201,    79,   109,   204,    82,   197,    84,
     198,  1135,  1136,   251,   252,   203,  1140,  1141,   205,   198,
     197,   259,  1805,    76,   203,   263,    79,   199,  1824,    82,
    1826,    84,  1828,   861,   204,   546,   864,   204,  1834,     8,
     204,  1143,   870,   871,   203,   197,   205,   199,   711,   201,
     813,     6,   204,   716,   206,     6,   197,  1159,   197,   822,
     199,   824,   201,   826,   198,   828,   200,   206,  1851,   203,
     833,  1854,   205,   197,  1857,   838,   197,  1860,   197,   204,
     199,  1877,   201,  1879,    99,  1881,   203,   206,   205,    79,
     103,   104,    82,   856,    84,   110,   109,   860,   203,   198,
     205,   200,   197,   118,   119,   120,     8,   197,   871,   124,
     125,   126,   127,  1896,   203,  1898,   205,  1900,   197,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   896,   962,   963,   197,   196,   901,   902,
     903,   904,  1398,  1399,  1150,   203,   205,   205,   198,   203,
     200,   205,   915,   203,   917,   198,   197,   200,   905,   203,
     203,   205,   197,  1287,  1288,   203,   199,   205,  1292,  1293,
     924,   925,   203,   203,   205,   205,   930,   931,   941,   204,
     204,   944,   945,   946,   947,   203,   203,   205,   205,   197,
     205,   228,   229,   230,  1296,   197,   233,   234,   235,   198,
     711,   200,   197,   714,   203,   716,   969,     4,   871,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   197,   204,   988,   989,   196,   991,   204,
     993,   994,   269,   270,   997,   998,   205,     7,   901,  1002,
     903,   904,  1070,  1071,   204,    99,   283,   284,   198,   203,
     200,   205,   915,   203,   917,   198,   110,   200,  1086,  1087,
     203,    82,   204,    84,   118,   119,   120,   505,   506,   197,
     124,   125,   126,   127,   197,   513,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      82,    99,    84,   203,   196,   205,   198,   203,   203,   205,
     205,     6,   110,   203,   197,   205,   969,   203,   197,   205,
     118,   119,   120,    99,   206,  1143,   124,   125,   126,   127,
     203,   203,   205,   205,   110,     6,  1089,  1090,  1091,  1335,
     204,   204,   118,   119,   120,   204,   199,  1100,   124,   125,
     126,   127,   203,   203,   205,   205,   203,   199,   205,  1103,
    1104,   205,     6,     6,  1108,  1109,   203,   203,   205,   205,
     871,   203,   203,   205,   205,   203,   199,   205,  1624,     4,
     204,     6,  1135,  1136,   203,   143,   205,  1140,  1141,   203,
     203,   205,   205,   203,   203,   205,   205,  1150,   199,   203,
     901,   205,   903,   904,   203,     6,   205,   205,   203,   206,
     205,  1164,     6,   203,   915,   205,   917,     6,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   203,  1186,   205,     6,   196,    12,    13,  1192,
     941,  1178,   203,     6,   205,  1198,   199,  1200,  1201,   203,
       4,   205,  1205,  1206,   203,  1208,   205,  1210,   203,  1212,
     205,  1214,  1215,  1216,    99,   203,   196,   205,   969,  1583,
     203,   203,   205,   205,   203,   110,   205,   204,   204,  1232,
    1298,   201,     7,   118,   119,   120,   203,   205,   205,   124,
     125,   126,   127,   203,  1247,   205,   204,   203,  1251,   205,
    1253,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   203,    87,   205,   203,   203,   205,    92,    93,   203,
      95,    96,    97,   203,     7,   205,   101,     6,     6,     6,
     198,     7,     7,     6,  1287,  1288,     7,   204,    99,  1292,
    1293,     6,     6,   771,     7,     6,     6,     4,   140,   110,
     778,    54,  1305,    54,    54,    54,   784,   118,   119,   120,
     135,   136,   137,   124,   125,   126,   127,   204,   200,   198,
     205,     6,  1309,   183,   184,   185,   186,   187,   188,   189,
     190,   191,  1335,     6,   198,   198,   196,   203,  1341,    40,
    1327,   203,   203,    99,   203,   203,   203,  1593,  1351,   198,
     198,  1354,   198,   200,   110,     6,    40,    40,    40,     4,
    1428,     4,   118,   119,   120,     6,     6,  1354,   124,   125,
     126,   127,     6,     6,   143,     7,     7,     7,     7,   143,
     205,  1638,     7,     7,  1135,  1136,   143,  1390,  1391,  1140,
    1141,     7,     7,     4,   205,   204,  1398,  1399,     6,  1150,
     198,   203,  1305,   198,   203,   198,   203,  1394,   198,   203,
     201,     6,   200,   205,     7,  1418,   205,  1420,   204,  1422,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   204,    99,  1437,     7,   196,   204,   204,     4,
       5,  1444,   201,     7,   110,    12,    13,     6,  1351,   205,
     204,  1454,   118,   119,   120,  1458,  1443,    40,   124,   125,
     126,   127,    40,    40,    40,     6,     6,     6,     6,     6,
       6,  1458,  1459,  1460,     7,    40,    41,    42,    43,    44,
      45,  1484,   199,     6,    49,    50,    51,    52,   197,   197,
     185,     7,    57,    58,    59,     7,     6,    62,   204,     7,
      84,     7,  1505,     7,     7,     7,   984,  1764,    73,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     6,
      87,     7,     7,     7,     7,    92,    93,     7,    95,    96,
      97,     7,     4,     4,   101,   204,  1287,  1288,  1541,   205,
       6,  1292,  1293,  1546,   197,     6,     6,   204,     7,     6,
      82,     7,     7,     7,  1305,     6,     6,     6,  1036,  1037,
    1038,     7,     6,     6,  1567,     4,     4,     4,   135,   136,
     137,     6,   198,     6,     6,     6,     4,  1580,    12,    13,
    1583,     6,   205,   203,  1335,   198,   198,     7,   198,   203,
    1593,   197,   201,   158,   159,   160,   201,   204,     6,  1602,
    1351,     6,     6,     6,   204,   170,   204,   172,   173,     6,
      92,     6,   204,   204,     6,  1618,   204,     6,  1621,     6,
       5,     4,  1624,   204,     6,   204,     7,    88,   199,   204,
     204,     6,     6,   198,  1637,   200,     6,     6,   205,  1642,
       4,   204,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   204,    87,   204,     6,     6,     6,    92,    93,
     139,    95,    96,    97,     6,     4,     6,   101,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   203,     6,     6,  1688,   196,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   135,   136,   137,  1707,   196,     4,     6,   204,     6,
       6,     6,     6,   204,   175,   176,   177,   178,   179,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       4,   192,   143,     6,   196,   196,     6,     6,     6,     5,
    1727,    12,    13,     6,     6,     6,     6,     6,     6,   210,
     211,   212,   213,     6,   215,   216,   217,   218,     6,   220,
     221,   222,  1765,     6,  1767,     6,   227,  1245,     6,     6,
       6,   205,     6,   203,     6,     6,     6,  1780,     6,   198,
       6,     6,     6,     6,   245,     6,   201,     7,     6,     6,
     204,     6,     5,   254,   255,    80,     6,   204,     6,   205,
       6,     6,   263,   204,   204,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   205,    87,     7,   204,   138,
     204,    92,    93,     6,    95,    96,    97,   204,  1815,   205,
     101,     6,  1583,  1836,     6,   296,   297,   298,     6,     6,
       6,  1844,  1593,     6,     6,     6,     6,   308,   309,   310,
     141,   312,     6,     6,     6,   316,   317,   318,   204,     6,
     321,     6,     6,     6,   135,   136,   137,   204,  1871,   204,
     204,     6,   204,     6,   205,     6,   204,   338,   339,     6,
      99,     6,     6,     6,  1362,  1888,     6,  1890,     6,     6,
       6,   352,   353,     6,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   205,  1920,     6,     6,
     204,   204,  1400,   204,  1402,   386,  1404,     6,   204,     6,
       6,   392,     6,   394,   205,     6,     6,   204,     6,   204,
    1418,  1844,     6,  1421,  1422,     6,     6,   204,   204,   204,
       6,     6,     6,     6,     6,     6,     6,   418,   419,     6,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,     6,     6,   438,   439,   453,
    1173,  1608,  1730,  1607,  1185,  1888,     3,  1890,     3,   483,
    1620,  1331,    -1,    -1,    -1,    -1,   457,    -1,    -1,    -1,
      -1,    -1,   463,    -1,    -1,    -1,    -1,   468,    -1,    -1,
      -1,    -1,   473,   474,    -1,    -1,    -1,  1920,   479,   480,
      -1,    -1,    -1,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,   510,
     511,   512,   513,   514,   515,    -1,    -1,    -1,   519,   520,
     521,   522,   523,    -1,    -1,    -1,   527,    -1,   529,   530,
      -1,    -1,    -1,   534,   535,   536,    -1,    -1,   539,   540,
     541,   542,   543,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,  1844,    -1,    -1,    -1,    -1,    -1,   560,
      -1,    -1,    -1,    -1,    -1,   566,   567,    -1,   569,   570,
      12,    13,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   590,
     591,   196,   593,   594,    -1,    -1,    -1,  1888,    -1,  1890,
      -1,   602,   603,    -1,    -1,    -1,   607,    -1,    -1,    -1,
    1628,    -1,  1630,    -1,  1632,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1640,    -1,    -1,  1643,    -1,    -1,    -1,  1920,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,  1687,
      -1,    -1,    -1,  1691,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,   135,   136,   137,    -1,    -1,    -1,   700,
     701,   211,    -1,   704,   705,   706,   216,   708,   709,    -1,
     220,    -1,    -1,    -1,    -1,    -1,   717,   227,    -1,   720,
     721,    -1,  1740,    -1,    -1,    -1,  1744,    -1,    -1,    -1,
      -1,    -1,    -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   743,    -1,    -1,    -1,    -1,    -1,    -1,  1767,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   765,    -1,    -1,    -1,    -1,    -1,
      -1,   772,   773,    -1,    -1,    -1,    -1,   778,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,   298,    -1,
     791,    -1,    -1,   794,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,  1822,  1823,    -1,    -1,    -1,    -1,
      -1,    -1,   813,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   822,    -1,   824,   223,   826,    -1,   828,    -1,    -1,
      -1,    -1,   833,    -1,    -1,    -1,    -1,   838,    -1,    -1,
      -1,    -1,    -1,   844,    -1,   846,   847,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,   271,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    97,    -1,   884,    -1,   101,    -1,    -1,    -1,    -1,
      -1,   892,   893,   894,    -1,   896,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   419,
      -1,    -1,    -1,   914,    -1,    -1,    -1,    -1,   919,   135,
     136,   137,    -1,    -1,    -1,   211,    -1,   928,    -1,    -1,
     216,    -1,    -1,   934,   220,    -1,    -1,   336,   337,    -1,
      -1,   227,    -1,   944,   945,   946,   947,   457,    -1,   950,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    97,   492,   493,   383,   101,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1002,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,  1012,    -1,  1014,    -1,  1016,    -1,  1018,    -1,   135,
     136,   137,    -1,    -1,   534,   535,   536,    -1,    -1,    -1,
      -1,    12,    13,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     560,   196,    -1,    -1,    -1,    -1,    -1,   567,   203,    -1,
     205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1069,    -1,
      -1,    -1,    -1,  1074,    -1,  1076,  1077,  1078,    -1,    -1,
      -1,    -1,    -1,  1084,    -1,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,   603,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,  1106,    87,    -1,    -1,  1110,
      -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   419,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
    1151,    -1,   196,    -1,   135,   136,   137,    -1,    -1,    -1,
     204,  1162,  1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1177,  1178,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,   704,    -1,   196,    -1,   708,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   492,   493,    -1,    -1,
     720,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1222,  1223,  1224,   205,    -1,    12,    13,    -1,    -1,
      -1,  1232,    -1,  1234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1245,    -1,    -1,    -1,   534,   535,
     536,    -1,  1253,    -1,    -1,   765,    -1,  1258,    -1,    -1,
      -1,    -1,   661,    -1,    -1,    -1,   665,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,  1279,  1280,
    1281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,   813,    -1,    -1,    92,    93,    -1,    95,
      96,    97,   822,    -1,   824,   101,   826,   603,   828,    -1,
      -1,    -1,    -1,   833,    -1,    -1,    -1,  1328,   838,    -1,
      -1,    12,    13,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1342,    -1,    -1,    -1,   744,  1347,    -1,    -1,   135,
     136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1360,
    1361,    -1,    -1,    -1,    -1,    -1,  1367,  1368,    -1,    -1,
      -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1380,
      -1,    -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,  1390,
    1391,  1392,    -1,  1394,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,  1406,    87,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,    96,    97,  1418,   704,   205,
     101,  1422,   708,    -1,  1425,    -1,    -1,    -1,    -1,  1430,
    1431,  1432,  1433,    -1,   944,   945,   946,   947,    -1,    -1,
      -1,    -1,  1443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   856,  1459,    -1,
      -1,   860,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,   765,
     196,  1482,  1483,    -1,    -1,    -1,    -1,    -1,   204,  1490,
      -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   902,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,   205,  1526,    -1,   813,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,   824,    -1,
     826,    -1,   828,  1544,    -1,  1546,    -1,   833,    -1,    -1,
      -1,    -1,   838,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1562,    -1,  1564,    -1,    -1,  1567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   988,
     989,    -1,   991,    -1,   993,   994,    -1,  1598,   997,   998,
      -1,    -1,  1603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1621,    -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,  1630,
      -1,  1632,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,  1642,    -1,    -1,    -1,  1646,  1647,  1648,  1649,  1650,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,   945,
     946,   947,    -1,    -1,    -1,    -1,    -1,    -1,  1669,  1670,
      -1,    -1,    -1,  1674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,
    1089,  1090,  1091,    -1,  1695,    -1,    -1,    -1,    -1,    -1,
      -1,  1100,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,     6,  1002,    -1,    92,    93,
      -1,    95,    96,    97,  1725,    -1,    -1,   101,    -1,  1730,
      -1,    -1,    -1,    -1,    -1,    -1,  1737,    -1,    -1,    -1,
      -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,    -1,    -1,
    1751,    -1,    -1,  1754,    -1,    -1,  1757,    -1,    -1,    -1,
    1761,   135,   136,   137,  1765,  1164,  1767,  1768,  1769,  1770,
    1771,    -1,    -1,    -1,    -1,    -1,    -1,  1778,    -1,    -1,
    1781,    -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,
      -1,    -1,    -1,  1192,    -1,    -1,    -1,    -1,    -1,  1198,
      -1,  1200,  1201,    -1,    -1,     6,  1205,  1206,    -1,  1208,
      -1,  1210,    -1,  1212,    -1,  1214,  1215,  1216,    -1,    -1,
    1821,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,  1232,    -1,  1836,    -1,  1838,  1839,  1840,
    1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,    -1,
       6,    -1,  1251,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,  1874,  1875,   571,    -1,    -1,    -1,    -1,
    1390,  1391,    -1,  1884,  1885,  1886,  1887,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     8,    -1,    -1,    -1,   196,    -1,    -1,  1418,    -1,
      -1,    -1,  1422,    -1,    -1,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,    -1,   623,   624,   625,
     626,   627,   628,   629,    -1,    -1,    -1,   633,   634,   635,
       6,    -1,  1341,    -1,    -1,    -1,    -1,   643,   644,   645,
      -1,   647,    -1,    -1,    -1,  1354,    -1,    -1,   654,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   672,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,  1420,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,  1546,    -1,  1437,    -1,
     196,    -1,    -1,    -1,    -1,  1444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1454,    -1,  1567,    -1,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1580,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,  1484,     6,    -1,    -1,   196,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,  1390,  1391,  1505,    -1,   196,    -1,
     198,  1621,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,  1541,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,  1602,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,  1618,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,  1637,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,   949,    -1,  1765,    -1,  1767,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,     6,    -1,    -1,   196,    -1,    -1,    -1,
      -1,  1567,    -1,    -1,    -1,    -1,   982,   983,    -1,  1688,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,  1707,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,  1836,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,  1621,    -1,    -1,   202,    -1,
     204,   205,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,  1642,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       6,  1780,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,  1113,    -1,    -1,
      -1,    -1,    -1,  1119,  1120,  1121,  1122,  1123,     6,     4,
       5,    -1,    -1,  1129,  1130,    -1,    -1,  1133,  1134,  1135,
      -1,    -1,    -1,    -1,  1140,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    40,    41,    42,    43,    44,
      45,    -1,  1871,    -1,    49,    50,    51,    52,    -1,  1765,
      -1,  1767,    57,    58,    59,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    73,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,   199,    -1,   201,   202,    -1,   204,    -1,   206,
    1836,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,  1263,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,
      -1,    -1,    -1,   158,   159,   160,    -1,    -1,    -1,    -1,
       6,  1287,    -1,    -1,    -1,   170,  1292,   172,   173,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,  1321,  1322,     3,     4,  1325,
    1326,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1447,  1448,    -1,    -1,  1451,  1452,    -1,    -1,    -1,
      -1,  1457,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     6,    -1,    -1,    -1,
     196,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,    -1,   205,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,     8,
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
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
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
      -1,   202,    -1,   204,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,     8,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,     5,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    79,     4,     5,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,   170,    -1,
     172,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,     5,
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
      46,    47,    48,    -1,   170,    -1,   172,    53,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,     3,     4,    -1,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
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
      -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    64,    65,    66,    -1,     9,    10,    11,    -1,
      72,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   205,    -1,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   205,    -1,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,     3,     4,    -1,    -1,
     197,    -1,     9,    10,    11,   202,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,     3,     4,    -1,    -1,
     197,    -1,     9,    10,    11,   202,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    64,    65,    66,
      -1,     9,    10,    11,    -1,    72,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,   205,    -1,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,   198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
       3,     4,   200,    -1,   202,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    64,    65,    66,    -1,     9,    10,    11,    -1,    72,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   205,    -1,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,     3,     4,   200,    -1,   202,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    54,    55,    56,   197,    -1,
      -1,    60,    61,   202,    63,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,     4,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    12,    13,   134,   135,   136,   137,    -1,
      -1,   140,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    38,
      39,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,   173,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,   134,   135,   136,   137,    -1,
      -1,   140,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,   173,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   178,
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
      -1,   198,    -1,   200,   178,   179,   180,   181,   182,   183,
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
      -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   200,   178,   179,   180,   181,   182,
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
      -1,    -1,    -1,    -1,   196
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
     204,     4,   286,   303,   199,     6,   197,   204,   197,   199,
     206,   231,     7,   174,   175,   176,   177,   193,   194,   229,
     230,     4,   197,   199,   201,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     197,   197,   197,   197,   197,   197,   231,   231,   231,   231,
     197,   231,   231,   231,     7,   197,   197,   197,   231,   231,
     197,   197,   199,   286,   286,   286,   198,   286,   200,   286,
       4,   140,   141,   304,     4,   251,   252,   253,   204,   204,
       6,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   196,   204,     6,   197,   199,
     230,     6,   286,     4,   299,   300,   303,   304,   299,   286,
     299,   302,   235,   238,   300,   304,   286,   188,   286,   294,
     295,   286,   286,   197,   286,   295,   286,   286,   197,   295,
     286,   286,   292,   197,   204,   295,   293,   293,   293,   197,
     197,   293,   293,   293,   197,   197,   197,   197,   197,   197,
     197,   197,   204,   204,   286,     4,   292,   296,   204,   204,
     289,   289,   289,   286,   286,   187,   188,   204,   204,   289,
     204,   204,   204,   187,   188,   197,   253,   289,   204,   197,
     204,   197,   197,   197,   293,   293,   292,   197,     4,   199,
     199,   253,     6,     6,   204,   204,   204,   293,   293,   199,
     199,   199,   197,   199,   201,   231,   199,     5,   143,   204,
       5,   143,     5,   143,     5,   143,    76,    79,    82,    84,
     204,   286,   294,   286,   205,   295,     8,   189,     6,   197,
     199,   231,     6,   286,   286,   286,   201,   286,   204,   143,
     286,   286,   286,   286,     6,     6,     6,   253,     6,   253,
     197,   199,   204,   197,   199,   299,   292,   292,   198,   286,
     200,   286,   204,   204,   300,   292,     6,   199,   286,   286,
       4,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   302,   299,   302,   299,   299,   299,   292,
     299,   299,   286,   299,   299,   299,   302,   299,   286,   300,
     286,   299,   299,   299,   299,   299,   304,   300,   304,     7,
     174,   229,   198,     7,   174,   229,   200,     7,   229,   230,
     201,     7,   231,   205,    76,    79,    82,    84,   250,   286,
     295,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   214,   286,   286,     6,
     197,   199,   201,   198,   203,   197,   199,   198,   203,   203,
     198,   203,   200,   203,   234,   200,   234,   203,   203,   198,
     189,   203,   205,   198,   198,   286,   198,   205,   198,   198,
     286,   205,   198,   198,     7,   286,   286,   205,     6,     6,
       6,   286,   286,     7,     7,   279,   279,   286,   244,   286,
     300,   245,   286,   300,   246,   286,   300,   247,   286,   300,
     286,   286,   286,   295,   295,   204,   198,     6,   204,   253,
     253,   203,   203,   203,   289,   289,   252,   252,   203,   286,
     286,   286,   286,   265,   203,   253,   286,   286,   286,   286,
     286,     7,   280,     6,     7,   286,     6,   286,   286,   205,
     295,   295,   295,     6,     6,   286,   286,   286,   286,   286,
       4,   198,   200,   204,   232,   304,    54,   286,    54,    54,
      54,     5,   204,     5,   204,     5,   204,     5,   204,   295,
     198,   205,   286,   204,   286,   294,   286,   286,   204,   232,
     198,   198,   198,   140,   203,   253,   204,     8,   198,   198,
     200,   205,   205,   253,   200,   198,   203,   205,     7,   174,
     229,   198,     7,   174,   200,   286,   295,     6,     6,   286,
     198,   200,   230,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   203,   232,   232,   232,   232,   232,
     232,   232,   203,   203,   203,   232,   203,   232,   232,   198,
     198,   203,   203,   203,   203,   203,   232,   232,   232,   198,
     232,   288,   301,     6,   203,   203,   198,   203,   232,   203,
     232,   198,   198,   200,    40,    40,   292,     7,   229,   230,
      40,    40,   292,   201,   229,   230,   300,   286,     6,     4,
       4,   204,   297,   232,   204,   204,   204,   204,   205,   205,
       8,     4,   130,   131,   132,   133,   205,   217,   221,   224,
     226,   227,   198,   200,   286,   286,     4,     6,   185,   211,
     295,   286,   286,     6,   295,   286,     6,   299,     6,   304,
       6,   299,   286,   300,     7,   286,   294,   143,     7,     7,
     198,     7,   143,     7,     7,   198,   143,     7,     7,   286,
     198,   205,   204,   198,   198,   286,   292,     4,   278,     6,
     198,   198,   203,   198,   203,   198,   203,   198,   203,   198,
     198,   198,   205,   205,   295,   201,   253,   205,   205,   289,
     286,   286,   205,   205,   286,   289,   203,   203,   203,    99,
     110,   118,   119,   120,   124,   125,   126,   127,   275,   276,
     289,   205,   262,   198,   205,   198,   198,   198,   286,     6,
     286,   198,   200,   200,   205,   205,   205,   200,   200,   203,
     198,   200,   295,   200,   204,   205,   204,   204,   204,   295,
     295,   295,   295,   205,     8,   295,   198,   200,   295,     7,
       7,     7,   201,   286,   205,   286,   286,     7,   201,   205,
     204,   292,     6,    40,    40,   292,   229,   230,    40,    40,
     229,   230,   205,   205,   200,   230,   201,   230,   299,   286,
     286,   286,   286,   295,   299,   292,   299,   299,   300,   240,
     242,   286,   299,   299,   286,   231,   231,     6,   286,     6,
     231,   231,     6,     4,   140,   141,   286,     6,     6,     6,
       7,   199,   296,   298,     6,   295,   295,   295,   295,   232,
     286,   218,   197,   197,   204,   228,     6,   230,   230,   198,
     200,   185,   299,   198,   198,   200,   198,   203,     7,   232,
     232,   289,    82,    84,   292,   292,     7,   292,    82,    84,
     292,   292,     7,    84,   292,   292,     6,     7,     7,   295,
       7,     7,    99,   277,     6,     7,   229,   286,   229,   286,
     229,   286,   229,   286,     7,     7,     7,     7,     7,   205,
       4,   205,   203,   203,   203,   205,   205,   289,   289,   289,
       4,     6,   204,     6,   197,     6,   128,     6,   128,     6,
     128,     6,   128,   205,   276,   203,   275,     7,     6,     7,
       7,     7,     6,   204,     6,     6,     6,    82,     7,     6,
       6,   286,   201,   205,   286,   286,   286,   286,   205,   205,
     205,   205,   286,   205,   205,   292,   292,   292,     4,   203,
       8,     8,   198,     4,     4,   292,   205,   231,   231,     6,
     286,     6,   231,   231,   286,     6,   232,     6,     4,     6,
     232,   232,   232,   232,   232,   203,   198,   198,   198,   203,
     203,   232,   241,   203,   232,   243,   198,   198,   232,   232,
     232,   302,   302,     6,   232,   302,   302,     7,   229,   230,
     201,     7,     6,   296,   286,   203,   205,   205,   205,   205,
     205,   229,   197,   286,   286,   291,   292,   204,   201,     6,
       6,   211,     6,   286,   204,   286,   300,     6,     6,     6,
     204,   204,    92,   249,   249,   292,     6,   204,   204,     6,
       6,   292,   204,     6,     6,     5,   292,   205,   292,   292,
       4,     6,   292,   292,   292,   292,   292,   292,   292,   292,
     204,   204,     7,     6,     7,   286,   286,   286,   204,   204,
     203,   205,   203,   205,   203,   205,   199,   286,   292,   286,
       6,     6,     6,     6,   286,   289,   205,     5,   204,   292,
     204,   204,   204,   292,   295,   204,   286,   200,     4,   232,
     203,   203,   203,   203,   232,     6,     6,   139,   286,   286,
     286,     6,     6,     7,   203,     6,   232,   302,   302,     6,
     232,   302,   302,     6,   229,   230,   299,   300,     4,     4,
     154,     6,   232,   232,     6,   232,   232,   300,   286,     6,
       4,   297,     6,   200,   296,     6,     6,     6,     6,   292,
     215,   286,   203,   203,   203,   205,   216,   286,     4,   299,
     203,   292,   300,   286,   286,   289,     6,     6,     6,   286,
     286,     6,   286,     5,     6,   204,     6,   143,   248,   286,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   295,
     295,   286,   286,   300,   205,   198,   203,   205,   252,   252,
     289,     6,   266,   289,     6,   267,   289,     6,   268,   286,
     205,   203,   198,   205,   203,     6,   188,   289,     6,   291,
     289,   289,     6,   205,   286,     6,     6,   286,   286,   286,
     286,   292,   203,   205,     8,   205,   198,   204,   286,   300,
     292,     6,   232,   232,     6,   232,   232,   292,   198,   232,
     204,   292,   300,   204,   286,   300,   300,     6,     6,     6,
       6,     6,     6,     7,     6,   201,     6,   198,   203,   286,
     286,   292,   204,   203,   205,     6,   286,   236,   237,   205,
     205,   205,   205,   205,     5,   291,    80,     6,   204,   205,
     205,   204,     6,     6,   204,   286,   205,   205,   203,   204,
     203,   204,   203,   204,   200,     6,   292,     7,   204,   286,
     203,   205,   203,   203,     6,   205,   203,   203,   203,   203,
     138,   286,   286,   295,     6,     6,   205,     6,     6,     6,
       6,     6,   239,   286,   302,   296,   141,   219,   286,   203,
     203,   291,   286,     6,   203,   240,   242,     6,     6,     6,
       6,     6,     6,   205,   204,   291,   103,   104,   109,   281,
     103,   104,   281,   295,   252,   203,   205,   286,   289,   275,
     286,   289,   275,   286,   289,   275,     6,   203,   205,   292,
     253,   205,   289,     6,   295,   289,   286,   286,   286,   286,
     286,   205,   205,   205,     6,   203,   205,     7,   205,     6,
     204,   286,   286,   205,   286,   205,   205,   204,   286,   205,
     204,   289,   292,     6,   204,   289,     6,   205,   205,   286,
     205,   203,   205,   205,   203,   205,   205,   203,   205,   292,
       6,    99,   205,   263,   204,   203,   205,   203,   203,   203,
     203,   203,     6,     6,   286,   300,   216,   198,   203,     6,
     204,   203,   286,   205,     6,   289,     6,   289,     6,     6,
     205,     6,   269,   286,     6,     6,   270,   286,     6,     6,
     271,   286,     6,   205,   286,   275,   253,   295,     6,   289,
     295,   286,   286,   286,   286,     7,   205,   222,   286,   291,
     286,   203,   203,   203,   204,   205,   204,   205,   204,   205,
       6,     6,   205,   205,   264,   205,   203,   205,   203,   203,
     203,   203,   300,     6,   204,   198,   205,   205,   286,   289,
     289,   275,     6,   272,   275,     6,   273,   275,     6,   274,
     275,     6,   295,     6,   286,   286,   286,   286,   220,   299,
     225,   204,     6,   205,   203,   203,   205,   204,   205,   204,
     205,   204,   205,   205,   203,   203,   203,   203,   203,   205,
     204,   291,     6,   286,   286,     6,   275,     6,   275,     6,
     275,     6,   286,   286,   286,   286,   299,     6,   223,   299,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     203,   205,     6,     6,     6,     6,     6,     6,   299,     6
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
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     234,   234,   235,   235,   235,   236,   235,   235,   237,   235,
     238,   238,   239,   239,   240,   240,   241,   241,   241,   242,
     242,   243,   243,   243,   243,   244,   244,   244,   245,   245,
     245,   246,   246,   246,   247,   247,   247,   248,   248,   249,
     249,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   255,   255,   255,
     256,   256,   257,   258,   258,   258,   258,   258,   258,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   261,   261,   261,   262,   261,   263,   261,   264,
     261,   265,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   266,   261,   267,   261,   268,   261,   269,   261,
     270,   261,   271,   261,   272,   261,   273,   261,   274,   261,
     275,   275,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   277,   277,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   283,   283,   283,   284,   284,   284,   285,
     285,   285,   285,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   288,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   289,   289,   289,   289,   289,   290,   290,   290,
     290,   291,   291,   292,   292,   292,   292,   292,   292,   293,
     293,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   295,
     295,   295,   295,   296,   296,   296,   296,   297,   297,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   301,   300,   302,   302,   303,   303,   304,   304,   304
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
       5,     5,     7,     7,     4,     3,     6,     7,     7,     6,
       6,     9,     9,     6,     6,     7,     7,     6,     6,     4,
       8,     8,     9,     9,     9,     9,     8,     8,     9,     9,
       9,     9,     6,     9,     6,     9,     5,     8,     8,    11,
       6,     9,     5,     7,     9,     9,    11,     7,     9,     9,
       0,     1,     0,     3,     5,     0,     9,     5,     0,     9,
       0,     3,     3,     5,     0,     2,     3,     5,     3,     0,
       2,     3,     3,     3,     5,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     0,     5,     0,
       2,     7,     8,     6,     7,     4,     7,     8,     8,     7,
       7,    11,     8,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     8,     8,    12,     8,     8,     7,     8,     8,
       5,    11,     5,     9,     9,     4,     9,     9,     1,     1,
       0,     2,     6,     6,     6,     6,     8,    10,    14,    16,
      12,     8,     8,     6,    14,     4,     6,     6,     3,     4,
       5,     6,     5,     3,     3,     4,     5,     4,     5,     3,
       5,     7,     7,     3,     7,     3,     2,     2,     2,     2,
       2,    15,     2,     2,     2,     2,     2,    16,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     8,     8,     8,    12,    12,    12,    14,
      14,    14,     0,    12,     0,    12,     0,    12,     0,    16,
       0,    16,     0,    16,     0,    18,     0,    18,     0,    18,
       1,     2,     5,     7,     9,     2,     2,     2,     3,     2,
       3,     2,     3,     2,     3,     9,     6,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     7,     6,     8,
       5,     3,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,    10,    10,    10,    10,     4,     4,
       4,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     4,     6,
       1,     4,     4,     4,     4,     4,     4,     4,     2,     5,
       5,     5,     5,     3,     6,     4,     7,     6,     6,     6,
       6,     4,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       1,     2,     3,     3,     5,     4,     2,     2,     2,     2,
       3,     3,     3,     3,     5,     5,     5,     5,    16,    16,
      16,    16,     1,     1,     3,     3,     4,     6,     6,     1,
       1,     3,     3,     9,     7,     1,     5,     3,     6,     1,
       3,     1,     1,     4,     4,     4,     4,     3,     6,     1,
       4,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     4,     6,     4,
       1,     0,     6,     1,     3,     5,     5,     1,     1,     4
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
#line 4613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4667 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4685 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4697 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4743 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4761 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4778 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4795 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4822 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4840 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4857 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4874 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 390 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 397 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 399 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4927 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5035 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5049 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 518 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 527 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 534 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5081 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 553 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5104 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 562 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5126 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 587 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5148 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5168 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 641 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5253 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 678 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5290 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 746 "Gmsh.y" /* yacc.c:1646  */
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
#line 5375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 763 "Gmsh.y" /* yacc.c:1646  */
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
#line 5408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 792 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5417 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 797 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 802 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 807 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 812 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 819 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 829 "Gmsh.y" /* yacc.c:1646  */
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
#line 5499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 858 "Gmsh.y" /* yacc.c:1646  */
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
#line 5532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 887 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 892 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 897 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 902 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 910 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 919 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 925 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 931 "Gmsh.y" /* yacc.c:1646  */
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
#line 5612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 944 "Gmsh.y" /* yacc.c:1646  */
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
#line 5628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 957 "Gmsh.y" /* yacc.c:1646  */
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
#line 5646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 972 "Gmsh.y" /* yacc.c:1646  */
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
#line 5664 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 989 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 995 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1001 "Gmsh.y" /* yacc.c:1646  */
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
#line 5698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1014 "Gmsh.y" /* yacc.c:1646  */
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
#line 5714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1027 "Gmsh.y" /* yacc.c:1646  */
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
#line 5732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1042 "Gmsh.y" /* yacc.c:1646  */
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
#line 5750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1059 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1065 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1074 "Gmsh.y" /* yacc.c:1646  */
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
#line 5792 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1092 "Gmsh.y" /* yacc.c:1646  */
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
#line 5814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1110 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1119 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1131 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1136 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5858 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1144 "Gmsh.y" /* yacc.c:1646  */
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
#line 5882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1164 "Gmsh.y" /* yacc.c:1646  */
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
#line 5906 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1187 "Gmsh.y" /* yacc.c:1646  */
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
#line 5921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1198 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 5933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1206 "Gmsh.y" /* yacc.c:1646  */
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
#line 5959 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1228 "Gmsh.y" /* yacc.c:1646  */
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
#line 5986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1251 "Gmsh.y" /* yacc.c:1646  */
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
#line 6016 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1277 "Gmsh.y" /* yacc.c:1646  */
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
#line 6038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1298 "Gmsh.y" /* yacc.c:1646  */
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
#line 6054 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1310 "Gmsh.y" /* yacc.c:1646  */
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
#line 6070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1328 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 6083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1337 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 6096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1346 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1348 "Gmsh.y" /* yacc.c:1646  */
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
#line 6122 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1364 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1373 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1375 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1389 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6165 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1397 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1403 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1415 "Gmsh.y" /* yacc.c:1646  */
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
#line 6199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1426 "Gmsh.y" /* yacc.c:1646  */
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
#line 6217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1441 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1457 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1465 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1474 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6263 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1482 "Gmsh.y" /* yacc.c:1646  */
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
#line 6280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1500 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1504 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1510 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1518 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1522 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1528 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1536 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6342 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1540 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1546 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1554 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6369 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1558 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1564 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1572 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1576 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1588 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1592 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1602 "Gmsh.y" /* yacc.c:1646  */
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
#line 6453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1625 "Gmsh.y" /* yacc.c:1646  */
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
#line 6497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1665 "Gmsh.y" /* yacc.c:1646  */
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
#line 6521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1688 "Gmsh.y" /* yacc.c:1646  */
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
#line 6543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1706 "Gmsh.y" /* yacc.c:1646  */
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
#line 6568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1727 "Gmsh.y" /* yacc.c:1646  */
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
#line 6590 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1745 "Gmsh.y" /* yacc.c:1646  */
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
#line 6624 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1775 "Gmsh.y" /* yacc.c:1646  */
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
#line 6658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1805 "Gmsh.y" /* yacc.c:1646  */
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
#line 6680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1823 "Gmsh.y" /* yacc.c:1646  */
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
#line 6702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1842 "Gmsh.y" /* yacc.c:1646  */
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
#line 6732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1868 "Gmsh.y" /* yacc.c:1646  */
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
#line 6754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1886 "Gmsh.y" /* yacc.c:1646  */
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
#line 6776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1904 "Gmsh.y" /* yacc.c:1646  */
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
#line 6820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1947 "Gmsh.y" /* yacc.c:1646  */
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
#line 6842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1965 "Gmsh.y" /* yacc.c:1646  */
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
#line 6885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2004 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2010 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2016 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2023 "Gmsh.y" /* yacc.c:1646  */
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
#line 6945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2048 "Gmsh.y" /* yacc.c:1646  */
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
#line 6974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2073 "Gmsh.y" /* yacc.c:1646  */
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
#line 6995 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2090 "Gmsh.y" /* yacc.c:1646  */
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
#line 7018 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2110 "Gmsh.y" /* yacc.c:1646  */
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
#line 7055 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2143 "Gmsh.y" /* yacc.c:1646  */
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
#line 7099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2187 "Gmsh.y" /* yacc.c:1646  */
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
#line 7121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2205 "Gmsh.y" /* yacc.c:1646  */
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
#line 7142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2222 "Gmsh.y" /* yacc.c:1646  */
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
#line 7162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2238 "Gmsh.y" /* yacc.c:1646  */
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
#line 7206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2283 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2288 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7224 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2293 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2298 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2303 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2308 "Gmsh.y" /* yacc.c:1646  */
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
#line 7278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2337 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2347 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2348 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2357 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2361 "Gmsh.y" /* yacc.c:1646  */
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
#line 7355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2384 "Gmsh.y" /* yacc.c:1646  */
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
#line 7382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2407 "Gmsh.y" /* yacc.c:1646  */
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
#line 7409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2430 "Gmsh.y" /* yacc.c:1646  */
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
#line 7436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2458 "Gmsh.y" /* yacc.c:1646  */
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
#line 7461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2479 "Gmsh.y" /* yacc.c:1646  */
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
#line 7491 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2506 "Gmsh.y" /* yacc.c:1646  */
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
#line 7515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2527 "Gmsh.y" /* yacc.c:1646  */
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
#line 7540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2548 "Gmsh.y" /* yacc.c:1646  */
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
#line 7564 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2568 "Gmsh.y" /* yacc.c:1646  */
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
#line 7680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2680 "Gmsh.y" /* yacc.c:1646  */
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
#line 7703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2699 "Gmsh.y" /* yacc.c:1646  */
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
#line 7745 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2738 "Gmsh.y" /* yacc.c:1646  */
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
#line 7852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2846 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7865 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2855 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2861 "Gmsh.y" /* yacc.c:1646  */
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
#line 7894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2876 "Gmsh.y" /* yacc.c:1646  */
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
#line 7926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2904 "Gmsh.y" /* yacc.c:1646  */
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
#line 7942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2921 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2930 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7968 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2944 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2958 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2964 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2970 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2979 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2988 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2997 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3011 "Gmsh.y" /* yacc.c:1646  */
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
#line 8116 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3070 "Gmsh.y" /* yacc.c:1646  */
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
#line 8138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3088 "Gmsh.y" /* yacc.c:1646  */
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
#line 8159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3105 "Gmsh.y" /* yacc.c:1646  */
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
#line 8178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3120 "Gmsh.y" /* yacc.c:1646  */
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
#line 8208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3146 "Gmsh.y" /* yacc.c:1646  */
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
#line 8224 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3158 "Gmsh.y" /* yacc.c:1646  */
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
#line 8252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3182 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3186 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3191 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3198 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3203 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3209 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3214 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3220 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3228 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3232 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3236 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3242 "Gmsh.y" /* yacc.c:1646  */
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
#line 8413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3301 "Gmsh.y" /* yacc.c:1646  */
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
#line 8434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3318 "Gmsh.y" /* yacc.c:1646  */
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
#line 8455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3335 "Gmsh.y" /* yacc.c:1646  */
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
#line 8481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3357 "Gmsh.y" /* yacc.c:1646  */
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
#line 8507 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3379 "Gmsh.y" /* yacc.c:1646  */
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
#line 8546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3414 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3422 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8570 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3430 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3436 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3443 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3450 "Gmsh.y" /* yacc.c:1646  */
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
#line 8626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3470 "Gmsh.y" /* yacc.c:1646  */
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
#line 8656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3496 "Gmsh.y" /* yacc.c:1646  */
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
#line 8672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3508 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3520 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3528 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3536 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3544 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3550 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3558 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3564 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3572 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3578 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3592 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3600 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8816 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3607 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3621 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3628 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3635 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3642 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3656 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8914 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3669 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3676 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8935 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3682 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3689 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3695 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3702 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3708 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3715 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8998 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3721 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3728 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9019 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3734 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3741 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9040 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3747 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3754 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3760 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3767 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3773 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3784 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3787 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3793 "Gmsh.y" /* yacc.c:1646  */
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
#line 9123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3805 "Gmsh.y" /* yacc.c:1646  */
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
#line 9147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3825 "Gmsh.y" /* yacc.c:1646  */
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
#line 9174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3849 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9182 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3853 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9190 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3857 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3861 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3865 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9216 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3871 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3877 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3881 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3885 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3889 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3893 "Gmsh.y" /* yacc.c:1646  */
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
#line 9281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3912 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3924 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9301 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3928 "Gmsh.y" /* yacc.c:1646  */
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
#line 9318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3943 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3947 "Gmsh.y" /* yacc.c:1646  */
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
#line 9344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3963 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 3967 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 3972 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 3976 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 3982 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 3986 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 3993 "Gmsh.y" /* yacc.c:1646  */
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
#line 9452 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4049 "Gmsh.y" /* yacc.c:1646  */
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
#line 9526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4119 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4124 "Gmsh.y" /* yacc.c:1646  */
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
#line 9606 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4191 "Gmsh.y" /* yacc.c:1646  */
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
#line 9646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4227 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4235 "Gmsh.y" /* yacc.c:1646  */
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
#line 9705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4278 "Gmsh.y" /* yacc.c:1646  */
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
#line 9748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4317 "Gmsh.y" /* yacc.c:1646  */
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
#line 9772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4338 "Gmsh.y" /* yacc.c:1646  */
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
#line 9807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4370 "Gmsh.y" /* yacc.c:1646  */
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
#line 9837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4397 "Gmsh.y" /* yacc.c:1646  */
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
#line 9866 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4423 "Gmsh.y" /* yacc.c:1646  */
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
#line 9895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4449 "Gmsh.y" /* yacc.c:1646  */
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
#line 9924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4475 "Gmsh.y" /* yacc.c:1646  */
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
#line 9953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4501 "Gmsh.y" /* yacc.c:1646  */
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
#line 9978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4522 "Gmsh.y" /* yacc.c:1646  */
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
#line 10010 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4550 "Gmsh.y" /* yacc.c:1646  */
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
#line 10042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4578 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4582 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4586 "Gmsh.y" /* yacc.c:1646  */
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
#line 10090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4614 "Gmsh.y" /* yacc.c:1646  */
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
#line 10133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4653 "Gmsh.y" /* yacc.c:1646  */
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
#line 10176 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4692 "Gmsh.y" /* yacc.c:1646  */
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
#line 10201 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4713 "Gmsh.y" /* yacc.c:1646  */
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
#line 10226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4734 "Gmsh.y" /* yacc.c:1646  */
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
#line 10251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4761 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4765 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4775 "Gmsh.y" /* yacc.c:1646  */
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
#line 10307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4809 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4810 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4811 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4816 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4822 "Gmsh.y" /* yacc.c:1646  */
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
#line 10351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4834 "Gmsh.y" /* yacc.c:1646  */
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
#line 10373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4852 "Gmsh.y" /* yacc.c:1646  */
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
#line 10400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4879 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4880 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10412 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4881 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4882 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4883 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4884 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4885 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4886 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4888 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4894 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10465 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4895 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4897 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4898 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10489 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4899 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4900 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4901 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10507 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4902 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4903 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4904 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4905 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10531 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4906 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4907 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4908 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4909 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10555 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4910 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10561 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4911 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4912 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4913 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4914 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4915 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4916 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10597 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4917 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4918 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4919 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10615 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4920 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4922 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4923 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4924 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4926 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4935 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4937 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4938 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4939 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4940 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4941 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4942 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4943 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4944 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10723 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4950 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4952 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4958 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4963 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10757 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4968 "Gmsh.y" /* yacc.c:1646  */
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
#line 10778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
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
#line 10800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5003 "Gmsh.y" /* yacc.c:1646  */
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
#line 10822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5021 "Gmsh.y" /* yacc.c:1646  */
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
#line 10844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5039 "Gmsh.y" /* yacc.c:1646  */
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
#line 10866 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5057 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5062 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5068 "Gmsh.y" /* yacc.c:1646  */
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
#line 10904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5083 "Gmsh.y" /* yacc.c:1646  */
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
#line 10925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5100 "Gmsh.y" /* yacc.c:1646  */
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
#line 10947 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5118 "Gmsh.y" /* yacc.c:1646  */
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
#line 10969 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5136 "Gmsh.y" /* yacc.c:1646  */
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
#line 10991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5154 "Gmsh.y" /* yacc.c:1646  */
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
#line 11013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5175 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11022 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5180 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11031 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5185 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5195 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5205 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11068 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5210 "Gmsh.y" /* yacc.c:1646  */
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
#line 11083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5221 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5230 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5235 "Gmsh.y" /* yacc.c:1646  */
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
#line 11133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5262 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5266 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5270 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11157 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5274 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11165 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5278 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5285 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5289 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5293 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5297 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5304 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5309 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5321 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5325 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5330 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5334 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5342 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5357 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11301 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5369 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5377 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5385 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5392 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5402 "Gmsh.y" /* yacc.c:1646  */
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
#line 11383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5431 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5435 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11399 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5439 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11415 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5447 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5451 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5455 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11439 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5459 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11447 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5463 "Gmsh.y" /* yacc.c:1646  */
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
#line 11480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5492 "Gmsh.y" /* yacc.c:1646  */
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
#line 11513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5521 "Gmsh.y" /* yacc.c:1646  */
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
#line 11546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5550 "Gmsh.y" /* yacc.c:1646  */
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
#line 11579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5580 "Gmsh.y" /* yacc.c:1646  */
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
#line 11595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5593 "Gmsh.y" /* yacc.c:1646  */
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
#line 11611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5606 "Gmsh.y" /* yacc.c:1646  */
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
#line 11627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5619 "Gmsh.y" /* yacc.c:1646  */
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
#line 11643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5631 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5641 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5651 "Gmsh.y" /* yacc.c:1646  */
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
#line 11687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5663 "Gmsh.y" /* yacc.c:1646  */
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
#line 11703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5676 "Gmsh.y" /* yacc.c:1646  */
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
#line 11719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5688 "Gmsh.y" /* yacc.c:1646  */
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
#line 11741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5706 "Gmsh.y" /* yacc.c:1646  */
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
#line 11763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5727 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5732 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11780 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5736 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11788 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5740 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5752 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5756 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5768 "Gmsh.y" /* yacc.c:1646  */
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
#line 11838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5785 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5795 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5799 "Gmsh.y" /* yacc.c:1646  */
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
#line 11873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5814 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5819 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11890 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5826 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5830 "Gmsh.y" /* yacc.c:1646  */
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
#line 11915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5843 "Gmsh.y" /* yacc.c:1646  */
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
#line 11933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5857 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 11940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5860 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 11947 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5863 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 11954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5866 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11966 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5874 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5885 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5889 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5893 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5901 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12016 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5907 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5913 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5921 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5929 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5936 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5944 "Gmsh.y" /* yacc.c:1646  */
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
#line 12092 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5959 "Gmsh.y" /* yacc.c:1646  */
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
#line 12110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5973 "Gmsh.y" /* yacc.c:1646  */
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
#line 12128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 5987 "Gmsh.y" /* yacc.c:1646  */
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
#line 12144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 5999 "Gmsh.y" /* yacc.c:1646  */
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
#line 12164 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6015 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6024 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12190 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6033 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6043 "Gmsh.y" /* yacc.c:1646  */
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
#line 12219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6054 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6058 "Gmsh.y" /* yacc.c:1646  */
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
#line 12250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6077 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12261 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6084 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6090 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6092 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6103 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6108 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6114 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6123 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6136 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6139 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6143 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12350 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6146 "Gmsh.y" /* yacc.c:1906  */


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
