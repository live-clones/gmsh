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
#define YYLAST   11483

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  542
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1941

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
    1339,  1353,  1353,  1355,  1357,  1366,  1376,  1375,  1393,  1403,
    1402,  1416,  1418,  1426,  1432,  1439,  1440,  1444,  1455,  1470,
    1480,  1481,  1486,  1494,  1503,  1511,  1529,  1533,  1539,  1547,
    1551,  1557,  1565,  1569,  1575,  1583,  1587,  1593,  1602,  1605,
    1618,  1621,  1631,  1654,  1697,  1720,  1738,  1759,  1777,  1807,
    1837,  1855,  1873,  1900,  1918,  1936,  1982,  2000,  2039,  2045,
    2051,  2058,  2083,  2108,  2125,  2144,  2178,  2225,  2243,  2260,
    2276,  2324,  2329,  2334,  2339,  2344,  2349,  2372,  2378,  2389,
    2390,  2395,  2398,  2402,  2425,  2448,  2471,  2499,  2520,  2546,
    2567,  2589,  2609,  2721,  2740,  2778,  2887,  2896,  2902,  2917,
    2945,  2962,  2971,  2985,  2999,  3005,  3011,  3020,  3029,  3038,
    3052,  3111,  3129,  3146,  3161,  3187,  3199,  3223,  3227,  3232,
    3239,  3244,  3250,  3255,  3261,  3269,  3273,  3277,  3282,  3342,
    3359,  3376,  3398,  3420,  3455,  3463,  3471,  3477,  3484,  3491,
    3511,  3537,  3549,  3561,  3569,  3577,  3586,  3585,  3600,  3599,
    3614,  3613,  3628,  3627,  3641,  3648,  3655,  3662,  3669,  3676,
    3683,  3690,  3697,  3705,  3704,  3718,  3717,  3731,  3730,  3744,
    3743,  3757,  3756,  3770,  3769,  3783,  3782,  3796,  3795,  3809,
    3808,  3825,  3828,  3834,  3846,  3866,  3890,  3894,  3898,  3902,
    3906,  3912,  3918,  3922,  3926,  3930,  3934,  3953,  3966,  3969,
    3985,  3988,  4005,  4008,  4014,  4017,  4024,  4027,  4034,  4090,
    4160,  4165,  4232,  4268,  4276,  4319,  4358,  4378,  4410,  4437,
    4463,  4489,  4515,  4541,  4563,  4591,  4619,  4623,  4627,  4655,
    4694,  4733,  4754,  4775,  4802,  4806,  4816,  4851,  4852,  4853,
    4857,  4863,  4875,  4893,  4921,  4922,  4923,  4924,  4925,  4926,
    4927,  4928,  4929,  4936,  4937,  4938,  4939,  4940,  4941,  4942,
    4943,  4944,  4945,  4946,  4947,  4948,  4949,  4950,  4951,  4952,
    4953,  4954,  4955,  4956,  4957,  4958,  4959,  4960,  4961,  4962,
    4963,  4964,  4965,  4966,  4967,  4968,  4977,  4978,  4979,  4980,
    4981,  4982,  4983,  4984,  4985,  4986,  4987,  4992,  4991,  4999,
    5004,  5009,  5026,  5044,  5062,  5080,  5098,  5103,  5109,  5124,
    5141,  5159,  5177,  5195,  5216,  5221,  5226,  5236,  5246,  5251,
    5262,  5271,  5276,  5303,  5307,  5311,  5315,  5319,  5326,  5330,
    5334,  5338,  5345,  5350,  5357,  5362,  5366,  5371,  5375,  5383,
    5394,  5398,  5410,  5418,  5426,  5433,  5443,  5472,  5476,  5480,
    5484,  5488,  5492,  5496,  5500,  5504,  5533,  5562,  5591,  5620,
    5633,  5646,  5659,  5672,  5682,  5692,  5704,  5717,  5729,  5747,
    5768,  5773,  5777,  5781,  5793,  5797,  5809,  5826,  5836,  5840,
    5855,  5860,  5867,  5871,  5884,  5898,  5901,  5904,  5907,  5915,
    5926,  5930,  5934,  5942,  5948,  5954,  5962,  5970,  5977,  5985,
    6000,  6014,  6028,  6040,  6056,  6065,  6074,  6084,  6095,  6099,
    6118,  6125,  6131,  6138,  6146,  6145,  6158,  6163,  6169,  6178,
    6191,  6194,  6198
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
      63,   435,   436,   437,   438,    60,   439,    62,   440,    43,
      45,    42,    47,    37,    33,   441,   442,   443,    94,    40,
      41,    91,    93,    46,    35,    44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1431

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1431)))

#define YYTABLE_NINF -510

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7847,    88,    43,  7969, -1431, -1431,  3952,    22,   -74,  -168,
    -133,    10,   107,   119,   156,   173,   -31,   188,   265,   121,
     133,   229,   229,   -56,   163,   166,    -2,   220,   261,    18,
     270,   274,   264,   303,   320,   443,   276,   327,   369,   404,
     -10,   416,   619,   481,    42,   306,   440,   -43,   339,  -110,
    -110,   348,   228,    55,   233,   479,   485,    14,    69,   488,
     509,    54,   595,   599,   621,  5355,   624,   503,   532,   533,
      11,     3, -1431,   540,   550, -1431, -1431,   729,   744,   477,
   -1431,  5834,  6225,    29,    31, -1431, -1431, -1431,  7707,   552,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431,    39, -1431,  -175,   125,
   -1431,     4, -1431, -1431, -1431, -1431, -1431,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   575,   582,   583,   229,   229,   594,   604,   618,
     229,   229,   229,   229,   639, -1431,   229, -1431, -1431, -1431,
   -1431, -1431,   229,   229,   677,   640,   648,   654,   229,   229,
     659,   663, -1431, -1431, -1431, -1431,   617,  7707,  7707,  7707,
    7191,  7252,   123,    26,   417,   637,   665,  1352, -1431,   673,
     817,  -152,  -105,   859,  7707,  6032,  6032, -1431,  7707, -1431,
   -1431, -1431, -1431,  6032, -1431, -1431, -1431, -1431, -1431, -1431,
    2828,    26,  7707,  6999,  7707,  7707,   681,  7707,  6999,  7707,
    7707,   699,  6999,  7707,  7707,  5751,   704,   700, -1431,  6999,
    5355,  5355,  5355,   708,   731,  5355,  5355,  5355,   732,   742,
     746,   749,   765,   766,   774,   789,   743,  1651,   950,  5751,
      11,   786,   795,  -110,  -110,  -110,  7707,  7707,  -129, -1431,
     136,  -110,   800,   808,   888,  6741,   160,    61,   822,   826,
     905,  5355,  5355,  5751,   925,     5,   780, -1431,   848,  1028,
    1115, -1431,   924,   932,   933,  5355,  5355,   930,   939,   940,
     537, -1431,   945,    33,     0,    46,    76,   670,  5949,  7707,
    4273, -1431, -1431,  2453, -1431,  1143, -1431,    77,    60,  1144,
    7707,  7707,  7707,  -115,  7707,   946, -1431,  1006,  7707,  7707,
    7707, -1431, -1431,  7707,   947,  1147,  1148, -1431, -1431,  1150,
   -1431,  1152, -1431,   576,  4919,   234,  6032, -1431,  5751,  5751,
    7449,  7510,   953,   956,  2828, -1431, -1431, -1431, -1431, -1431,
   -1431,  5751,  1157,   963,  7707,  7707,  1161,  7707,  7707,  7707,
    7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,
    7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  6032,
    6032,  6032,  6032,  6032,  6032,  6032,  6032,  5751,  6032,  6032,
    7707,  6032,  6032,  6032,  6032,  6032,  7707,  2828,  7707,  6032,
    6032,  6032,  6032,  6032,    26,  2828,    26,   968,   968,   968,
     113, 10403,   153,  6703,   162,   964,  1162,   229,   962, -1431,
     969,  6389,  7707,  6999, -1431,  7707,  7707,  7707,  7707,  7707,
    7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,  7707,
   -1431, -1431,  7707,  7707, -1431, -1431,  1552,   653,  -103, -1431,
     237, -1431,   328,  8885, -1431,   400,   169,   245,   965,   986,
   10424,  6999,  3981, -1431,   304, 10445, 10466,  7707, 10487,   432,
   10508, 10529,  7707,   505, 10550, 10571,  1185,  7707,  7707,   573,
    1190,  1191,  1192,  7707,  7707,  1187,  1196,  1196,  7707,  6807,
    6807,  6807,  6807,  7707,  7707,  7707,  6999,  6999,  8805,  1002,
    1200,  1003, -1431, -1431,   -61, -1431, -1431,  8911,  8937,  -110,
    -110,   417,   417,   138,  7707,  7707,  7707,  6741,  6741,  7707,
    6389,   170, -1431,  7707,  7707,  7707,  7707,  7707,  1203,  1205,
    1207,  7707,  1210,  7707,  7707,  1188, -1431, -1431,  6999,  6999,
    6999,  1214,  1218,  7707,  7707,  7707,  7707,  7707,  1222,   344,
      26, -1431,  1171,  7707, -1431,  1172, -1431,  1173, -1431,  1175,
      34,    35,    36,    37,  6999,   968, -1431, 10592, -1431,   597,
    7707,  6147, -1431,  7707,  7707,   430, -1431, 10613, 10634, 10655,
    1090,  8963, -1431,  1027,  4632, 10676, 10697,  7216, -1431, -1431,
   -1431,  1974, -1431,  2262,  7707,  7707, -1431,  7707,  7707,  1032,
    1035,   606,   191, 10718,   247,  7474,  7707,  6999,  1232,  1234,
   -1431,  7707, 10739, 10081,   118,  4237,  4237,  4237,  4237,  4237,
    4237,  4237,  4237,  4237,  4237,  4237,  8989,  4237,  4237,  4237,
    4237,  4237,  4237,  4237,  9015,  9041,  9067,   -54,   483,   -54,
    1041,  1042,  1038,   622,   622,  1043,  1044,  1050,  9093,   622,
     622,   622,   513,   622, 11285, -1431,  1573,  1051,  1052,  1047,
     644,   655,  1059,  1061,  1060,  1224,  1225,  5751,   168,  1236,
    1238,  5751,    85,  2828,  7707,  1273,  1276,    24,   622, -1431,
      99,    19,    25,   117, -1431,  7406,   623,  4652,  1250,  1615,
    1308,  1308,   536,   536,   536,   536,   642,   642,   968,   968,
     968,   968,     7, 10760, 10104, -1431,  7707,  7707,  1277,    63,
    6999,  7707,  7707,  1282,  6999,  7707,  1283,  6032,  1284, -1431,
      26,  1286,  6032,  7707,  2828,  1290,  6999,  6999,  1153,  1294,
    1296, 10781,  1297,  1160,  1299,  1301, 10802,  1164,  1303,  1304,
    7707, 10823,  7602,  1087, -1431, -1431, -1431, 10844, 10865,  7707,
    5751,  1298,  1306, 10886,  1120, 11285,  1123,  1129, 11285,  1128,
    1134, 11285,  1130,  1138, 11285,  1135, 10907, 10928, 10949,   671,
     678,  6999,  1136, -1431, -1431,  2290,  2447,  -110,  7707,  7707,
   -1431, -1431,  1139,  1140,  6741,  9119,  9145,  9171,  8859,   890,
    -110,  2693, 10970,  7630, 10991, 11012, 11033,  7707,  1335, -1431,
    7707, 11054, -1431, 10127, 10150, -1431,   683,   689,   690, -1431,
   -1431, 10173, 10196,  9197, 11075, 10219,    60, -1431, -1431,  6999,
   -1431,  1149,  1151,  7965,  1155,  1158,  1159, -1431,  6999, -1431,
    6999, -1431,  6999, -1431,  6999,   694, -1431, -1431,  5057,  6999,
     968, -1431, 11096, 10242,  6999, -1431,  1338,  1343,  1346,  1163,
    7707,  2847,  7707,  7707, -1431, -1431,    20, -1431, -1431,  3189,
   -1431,  1169,  5751,  1336,  1314,  1315,  5751,   168,  1327,  1328,
    5751,   168,  7993,   697, -1431, -1431, 10265,   324,   112, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431,  7707, -1431, -1431, -1431, -1431, -1431, -1431, -1431,  7707,
    7707,  7707, -1431,  6999, -1431, -1431, -1431, -1431,  6032, -1431,
   -1431,  5751,  6032,  6032,  2828, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431,  7707,  6032, -1431,  6032, -1431,  7707, -1431,
   -1431, -1431, -1431,   229,   229,  1364, -1431,  7707,  1370,   229,
     229,  1375,   157,  7707,  1376,  1377,  1701, -1431,  1378,  1189,
      11,  1380, -1431,  6999,  6999,  6999,  6999, -1431,   622,  7707,
   -1431,  1193,  1194,  1182, -1431,  1383, -1431, -1431, -1431, -1431,
   -1431,   474,   480, 11117, 10288, -1431, -1431,  1204,  6032,   541,
   11138, 10311, -1431,   561,  9223, -1431, -1431, -1431,  1387, -1431,
   -1431,  4237,   622,  -110,  3981, -1431,   829,  5751,  5751,  1390,
    5751,   833,  5751,  5751,  1393,  1317,  5751,  5751,  1774,  1394,
    1398,  6999,  1399,  1401,  2848, -1431, -1431,  1403, -1431,  1405,
     289,  7707,   289,  7707,   289,  7707,   289,  7707,  1406,  1411,
    1412,  1413,  1418,   713,  1423,  5201, -1431, -1431,   205,  9249,
    9275, -1431, -1431,  8021,  -137,  -110,  -110,  -110,  1425,  1438,
    1240,  1441,  1252,    40,    51,    52,    58,   -17, -1431,   217,
   -1431,   890,  1442,  1444,  1446,  1448,  1449, 11285, -1431,  2227,
    1254,  1451,  1455,  1457,  1381,  1460,  1458,  1462,  7707,    60,
     395,   717, -1431,  7707, -1431,  7707,  7707,  7707,   720,   721,
     733,   739, -1431,  7707,   750,    60,    60,   754,  5751,  5751,
    5751,  1465,  9301, -1431,  5076,   394,  1467,  1468, -1431,  5751,
    1266, -1431,   229,   229,  1469,  7707,  1470,   229,   229,  1475,
    7707,  1477, -1431,   622,  1482, -1431,  1485, -1431,  1484,  4237,
    4237,  4237,  4237,   664,  1269,  1291,  1305,  1307,  1309,   668,
     672, 11159,  1310,   622,  4237,  2557,  6032, -1431,  2504, -1431,
    2557,  6032, -1431,   177,  1312,  1501,  2665, -1431, -1431, -1431,
      11,  7707, -1431,   755, -1431,   763,   769,   775,   782,   289,
   11285,  1313,  7707,  7707,  5751,  1311, -1431, -1431, -1431, -1431,
    1318, -1431,  1503,    66, -1431, -1431,  1505,  7707,  4892,  1510,
    1516,     6,  1319,  1320,  1429,  1429,  5751,  1518,  1321,  1322,
    1523,  1525,  5751,  1340,  1541,  1542, -1431,  1548,  5751,   791,
    5751,  5751,  1551,  1553, -1431,  5751,  5751, 11285,  5751, 11285,
    5751, 11285,  5751, 11285,  5751,  5751,  5751,  1354,  1355,  1555,
     287, -1431,  7707,  7707,  7707,  1357,  1361,  -107,   -83,   -71,
    1363, -1431,  5751, -1431,  7707, -1431,  1562, -1431,  1563, -1431,
    1564, -1431,  1565, -1431, -1431,  6741,   363,  5553, -1431,  1366,
    1367,  6345, -1431,  6999, -1431, -1431, -1431,  1368,  7707, -1431,
   -1431, 10334,  1572,   622,  9327,  9353,  9379,  9405, -1431, -1431,
   -1431, -1431, 11285, -1431,   622,  1571,  1574,  1437, -1431,  7707,
    7707,  7707, -1431,  1575,   634,  1379,  1576,  2557,  6032, -1431,
    2999, -1431,  2557,  6032, -1431,  3449, -1431,   289, -1431,   486,
   -1431, -1431, -1431, -1431, -1431, -1431,  6032, -1431, -1431, -1431,
    2828,  1579, -1431, -1431,    21, -1431, -1431, -1431, -1431, -1431,
   -1431,  1580,   -54,   -54, -1431,  1581,   -54,   -54,  2828,  7707,
    1583,  1586,    24, -1431,  1588, 10357,    11, -1431,  1589,  1590,
    1591,  1592,  5751,  7707,  9431,  9457,   802, -1431,  7707,  1595,
   -1431, -1431,  6032, -1431,  9483,  4496, 11285, -1431, -1431, -1431,
   -1431,  7707,  7707,  -110,  1596,  1597,  1598, -1431,  7707,  7707,
   -1431, -1431,  1599,  7707, -1431, -1431,  1601,  1602,  1407,  1603,
    1440,  7707, -1431,  1605,  1606,  1608,  1609,  1610,  1611,  1009,
    1612,  6999,  6999,  7707, -1431,  6807,  8049, 11180,  6481,   417,
     417,  -110,  1613,  -110,  1616,  -110,  1617,  7707,   885,  1402,
   11201, -1431, -1431, -1431, -1431,  8077,   224, -1431,  1618,  3706,
    1619,  5751,  -110,  3706,  1621,   815,  7707,  3745,  1622,    60,
   -1431,  7707,  7707,  7707,  7707, -1431, -1431, -1431,  5751,  6937,
     997, 11222, -1431, -1431,  4959,  5751, -1431,  1624,   -54,   -54,
   -1431,  1625,   -54,   -54, -1431,  5751, -1431,  1432,   622,  4694,
    5157,  2828, -1431,  1627,  1628, -1431,  1629,  1631,  1632,  3898,
   -1431,  1633,  1635, -1431,  1436, -1431, -1431, -1431, -1431, -1431,
    1636,   562, 11285,  7707,  7707,  5751,  1443,   819, 11285, -1431,
    1637,  7707, -1431, -1431,  8105,  8133,   531, -1431, -1431, -1431,
    8161,  8189, -1431,  8217,  1639, -1431,  5751, -1431,  1566,  1640,
   11285, -1431, -1431, -1431, -1431, -1431, -1431,  1445, -1431, -1431,
     824,   825,  8832,  4030,  1641,  1447, -1431,  7707, -1431,  1450,
    1452,   226, -1431,  1483,   250, -1431,  1486,   254, -1431,  1487,
   10380,  1646,  5751,  1649,  1488,  7707, -1431,  6543,   267, -1431,
     828,   272,   281, -1431,  1652,  8245, -1431, -1431,  9509,  9535,
    9561,  9587,  1524,  7707, -1431,  7707, -1431, -1431,  6999,  4060,
    1657,  1481, -1431,  1684,  1685, -1431,  1689,  1691,  1692, -1431,
   -1431,  4273, -1431, -1431,  6032, 11285, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,    11, -1431,  1559, -1431, -1431,  7707,
    9613,  9639, -1431,  5751,  7707,  1699, -1431,  9665, -1431, -1431,
    1704,  1705,  1706,  1707,  1708,  1710,   835,  1514, -1431,  5751,
     502,   593,  6999, -1431, -1431,   417,  7148, -1431, -1431,  6741,
     890,  6741,   890,  6741,   890,  1715, -1431,   838,  5751, -1431,
    8273,  -110,  1717,  6999,  -110, -1431, -1431,  7707,  7707,  7707,
    7707,  7707,  8301,  8329,   839, -1431, -1431,  1718, -1431, -1431,
   -1431, -1431, -1431,   843,  4438,   847,  1720, -1431,  1521, 11285,
    7707,  7707,   850, 11285, -1431,  7707,   854,   855, -1431, -1431,
   -1431, -1431, -1431, -1431,  1522,  7707,   874,  1540,  -110,  5751,
    1723,  1543,  -110,  1725,   875,  1544,  7707, -1431,  8357,   291,
     431,  8385,   337,   494,  8413,   359,   523, -1431,  5751,  1741,
    1647,  5399,  1561,   366, -1431,   879,   383,  9691,  9717,  9743,
    9769,  4218, -1431, -1431,  1763, -1431,  7707, -1431,  2828, -1431,
   -1431,  7707, 11243,  9795,    38,  9821, -1431, -1431,  7707,  8441,
    1764,  -110,    59, -1431, -1431,  -110,    62, -1431,  1766, -1431,
    8469,  1768,  7707,  1770,  1771,  7707,  1772,  1773,  7707,  1775,
    1577, -1431,  7707, -1431,   890, -1431,  6999,  1776,  6543,  7707,
    7707,  7707,  7707, -1431, -1431,   927, -1431,   880, -1431,  7707,
   -1431,  5751,  7707,  9847, -1431, -1431,   407, -1431,   421, -1431,
   -1431, -1431, -1431,  1584,  8497, -1431, -1431,  1585,  8525, -1431,
   -1431,  1587,  8553, -1431,  1777,  4305,   545,  5597,   883, -1431,
     429,   884,  9873,  9899,  9925,  9951,  2828,  1779,  1623, 11264,
     893,  8581,  7707,  -110,  -110,   890,  1780,   890,  1783,   890,
    1786, -1431, -1431, -1431, -1431,   890,  1788,  6999,  1789,  7707,
    7707,  7707,  7707, -1431, -1431,  6032, -1431,  1626,  1790,  8609,
     458,   472,   643, -1431,  1630,   857, -1431,  1642,  1124, -1431,
    1643,  1195, -1431,   894, -1431,  9977, 10003, 10029, 10055,   898,
   -1431,  1648,  5751, -1431,  1803,  7707,  7707,  1805,   890,  1809,
     890,  1810,   890, -1431,  1811,  7707,  7707,  7707,  7707,  6032,
    1817,  6032,   922, -1431,  8637,  8665, -1431,  1251, -1431,  1295,
   -1431,  1358, -1431,  8693,  8721,  8749,  8777, -1431, -1431,   929,
   -1431,  1818,  1819,  1821,  1822,  1824,  1825, -1431, -1431, -1431,
   -1431,  6032,  1827, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,   261,   262,     0,     0,     0,
     256,     0,     0,     0,     0,   357,   358,   359,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   541,     0,
     406,   540,   510,   407,   409,   410,   408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,   531,   514,   414,
     415,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   411,   412,   413,   513,     0,     0,     0,     0,
      66,    67,     0,     0,   201,     0,     0,     0,   364,     0,
     502,   541,   421,     0,     0,     0,     0,   241,     0,   243,
     244,   239,   240,     0,   245,   246,   123,   131,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   540,     0,   201,   541,     0,
       0,   354,     0,     0,     0,     0,     0,     0,     0,     0,
     540,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,   484,   454,   460,     0,   455,   541,   421,     0,
       0,     0,     0,   540,     0,     0,   496,     0,     0,     0,
       0,   237,   238,     0,   540,     0,     0,   254,   255,     0,
     201,     0,   201,   540,     0,   541,     0,   360,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,   366,   368,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,   199,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   230,     0,     0,   429,   178,     0,   540,     0,   502,
     541,   503,     0,     0,   536,     0,   121,   121,     0,     0,
       0,     0,   490,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,   322,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   201,     0,   445,   444,     0,     0,     0,
       0,   201,   201,     0,     0,     0,     0,     0,     0,     0,
     272,     0,   201,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,   219,   355,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,   467,     0,     0,   468,     0,   469,     0,   470,     0,
       0,     0,     0,     0,     0,   366,   462,     0,   456,     0,
       0,     0,   332,    66,    67,     0,   236,     0,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,   258,   257,
     224,     0,   225,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   417,   534,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,   365,    59,
      60,     0,     0,    59,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,   202,     0,     0,     0,   382,   381,
     379,   380,   375,   377,   376,   378,   370,   369,   371,   372,
     373,   374,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,   352,   353,     0,     0,     0,
       0,   320,     0,     0,     0,   146,   147,     0,   149,   150,
       0,   152,   153,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,   166,   201,     0,     0,     0,     0,     0,
     447,   446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,     0,     0,     0,   335,
       0,     0,   220,     0,     0,   216,     0,     0,     0,   350,
     349,     0,     0,     0,     0,     0,   434,    68,    69,     0,
     485,     0,     0,     0,     0,     0,     0,   471,     0,   472,
       0,   473,     0,   474,     0,     0,   365,   457,   464,     0,
     371,   463,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   260,     0,   226,   228,     0,
     542,     0,     0,     0,    59,    60,     0,     0,    59,    60,
       0,     0,     0,     0,    90,    74,     0,   423,   422,   436,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   405,
     393,     0,   395,   396,   397,   398,   399,   400,   401,     0,
       0,     0,   523,     0,   528,   519,   520,   521,     0,   533,
     532,     0,     0,     0,     0,   524,   525,   526,   442,   530,
     135,   140,   113,     0,     0,   515,     0,   517,     0,   419,
     426,   427,   511,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   428,     0,     0,     0,     0,   538,     0,     0,
      44,     0,     0,     0,    57,     0,    35,    36,    37,    38,
      39,   425,   424,     0,     0,   508,    24,    22,     0,     0,
       0,     0,    25,     0,     0,   231,   537,    70,   124,    71,
     132,     0,     0,     0,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,   323,   321,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   229,     0,     0,
       0,   191,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,     0,
     263,     0,     0,     0,     0,     0,     0,   325,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   423,
     422,     0,   487,     0,   466,     0,     0,     0,     0,     0,
       0,     0,   458,     0,     0,   425,   424,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,   223,     0,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,   431,     0,   430,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    88,
       0,     0,    76,     0,     0,     0,     0,    80,   103,   105,
       0,     0,   500,     0,   111,     0,     0,     0,     0,     0,
     383,     0,     0,     0,     0,     0,    30,   433,   432,   506,
     504,    23,     0,     0,   507,   505,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,     0,     0,   329,     0,     0,   148,     0,   151,
       0,   154,     0,   157,     0,     0,     0,     0,     0,     0,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   307,     0,   306,     0,   312,     0,   314,     0,   308,
       0,   310,     0,   273,   302,     0,     0,     0,   214,     0,
       0,     0,   336,     0,   218,   217,   356,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   475,   476,
     477,   478,   465,   459,     0,     0,     0,     0,   497,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,    85,
       0,    89,     0,     0,    77,     0,    81,     0,   233,   435,
     232,   394,   402,   403,   404,   529,     0,   439,   440,   441,
       0,     0,   418,   136,     0,   535,   141,   438,   516,   518,
     420,     0,     0,     0,    86,     0,     0,     0,    59,     0,
       0,     0,     0,    78,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   452,     0,     0,
      26,    27,     0,    28,     0,     0,   125,   128,    72,    73,
     162,     0,     0,     0,     0,     0,     0,   165,     0,     0,
     181,   182,     0,     0,   167,   188,     0,     0,     0,     0,
     158,     0,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,     0,     0,     0,     0,   201,
     201,     0,   283,     0,   285,     0,   287,     0,   454,     0,
       0,   313,   315,   309,   311,     0,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   435,
     488,     0,     0,     0,     0,   489,   170,   171,     0,     0,
       0,     0,   114,   118,     0,     0,   362,     0,     0,     0,
      87,     0,     0,     0,    79,     0,   437,     0,     0,     0,
       0,     0,    97,     0,     0,    91,     0,     0,     0,     0,
     108,     0,     0,   109,     0,   501,   203,   204,   205,   206,
       0,     0,    40,     0,     0,     0,     0,     0,    42,   509,
       0,     0,   126,   129,     0,     0,   161,   168,   169,   173,
       0,     0,   183,     0,     0,   330,     0,   176,     0,     0,
     319,   187,   163,   175,   186,   190,   174,     0,   184,   189,
       0,     0,     0,     0,     0,     0,   451,     0,   450,     0,
       0,     0,   274,     0,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,   212,
       0,     0,     0,   207,     0,     0,   333,    33,     0,     0,
       0,     0,     0,     0,   495,     0,   251,   250,     0,     0,
       0,     0,    98,     0,     0,    92,     0,     0,     0,   522,
     527,     0,   137,   139,     0,   142,   143,   144,    99,   101,
      93,    95,   104,   106,     0,   112,     0,    82,    45,     0,
       0,     0,   453,     0,     0,     0,    29,     0,   135,   140,
       0,     0,     0,     0,     0,     0,     0,     0,   177,     0,
     326,   326,     0,   119,   120,   201,     0,   194,   195,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,   201,
       0,     0,     0,     0,     0,   198,   197,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,     0,   100,   102,
      94,    96,    83,     0,   490,     0,     0,   499,     0,    41,
       0,     0,     0,    43,    58,     0,     0,     0,   344,   346,
     345,   347,   348,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   449,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,     0,     0,
       0,   268,     0,     0,   208,     0,     0,     0,     0,     0,
       0,     0,   494,   252,     0,   363,     0,   138,     0,   145,
     110,     0,     0,     0,     0,     0,   127,   130,     0,     0,
       0,     0,     0,   327,   337,     0,     0,   338,     0,   192,
       0,   289,     0,     0,   291,     0,     0,   293,     0,     0,
       0,   304,     0,   264,     0,   201,     0,     0,     0,     0,
       0,     0,     0,   172,   117,     0,   133,     0,    49,     0,
      55,     0,     0,     0,   159,   185,     0,   341,     0,   342,
     343,   448,   277,     0,     0,   284,   278,     0,     0,   286,
     279,     0,     0,   288,     0,     0,     0,   270,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,   297,     0,
     299,   305,   316,   269,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   134,    46,     0,    53,     0,     0,     0,
       0,     0,     0,   280,     0,     0,   281,     0,     0,   282,
       0,     0,   215,     0,   209,     0,     0,     0,     0,     0,
      47,     0,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,     0,     0,   290,     0,   292,     0,
     294,     0,   210,     0,     0,     0,     0,    48,    50,     0,
      51,     0,     0,     0,     0,     0,     0,   479,   480,   481,
     482,     0,     0,    56,   339,   340,   296,   298,   300,    52,
      54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1431, -1431, -1431, -1431,   651, -1431, -1431, -1431, -1431,    94,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431,  -393,    65,  3536,  2902, -1431,  1382, -1431, -1431,
   -1431, -1431, -1431,   225, -1431,   218, -1431, -1431, -1431, -1431,
   -1431, -1431,   647,  1835,     1,  -498,  -245, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431,  1843, -1431, -1431, -1431, -1431, -1431,
   -1431, -1431, -1431, -1431, -1431, -1431, -1431, -1431,  -953, -1020,
   -1431, -1431,  1360, -1431,   222, -1431, -1431, -1431, -1431,  1724,
   -1431, -1431,  1083, -1431, -1430,  2133,   423,  2486,   219,  -244,
     514, -1431,   115,    49, -1431,  -331,    -3,   406
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   978,    91,    92,   702,  1491,  1497,
     966,  1171,  1678,  1879,   967,  1828,  1919,   968,  1881,   969,
     970,  1175,   351,   444,   186,   820,    93,   720,   456,  1618,
    1619,   457,  1673,  1139,  1323,  1140,  1326,   754,   757,   760,
     763,  1519,  1374,   684,   301,   420,   421,    96,    97,    98,
      99,   100,   101,   102,   302,  1061,  1774,  1845,   789,  1543,
    1546,  1549,  1803,  1807,  1811,  1864,  1867,  1870,  1057,  1058,
    1213,  1017,   751,   798,  1700,   104,   105,   106,   107,   303,
     188,   920,   506,   259,  1356,   304,   305,   306,   569,   315,
     951,  1163,   454,   449,   921,   455,   335,   308
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,  1560,   216,   191,    95,   554,   501,   317,   353,   532,
     194,   960,  1370,   782,   783,   313,   197,   667,   275,   671,
     520,   674,   221,   216,   340,  1470,   341,  1106,   949,   221,
     324,   195,   535,   342,   329,   193,   331,  1254,   551,   827,
     829,   831,   833,     5,  1790,   337,  1245,   442,   637,   443,
     639,   556,   509,   510,   278,   190,   342,  1247,  1249,   267,
     509,   510,   307,   652,  1251,  1797,   196,   278,  1799,   976,
    1236,   235,  1361,   280,   236,   281,   237,   511,   278,   254,
     255,   558,   509,   510,  1048,   591,  1626,   593,   580,   256,
     349,   350,   936,   185,     4,  1049,   257,   709,  1411,   250,
    1412,  -503,   710,  1050,  1051,  1052,   509,   510,  1256,  1053,
    1054,  1055,  1056,   199,   251,   252,   447,   112,   509,   510,
     665,   189,  1413,   246,  1414,   200,   247,   414,   509,   510,
     325,   328,   344,   268,  1415,   285,  1416,   269,   286,   961,
     962,   963,   964,   212,   777,   555,   817,   282,   818,   270,
     213,   717,   139,   140,   141,   142,   143,   144,   145,   146,
     669,  1153,   201,   150,   151,   152,   153,   276,   203,   673,
    1246,   155,   156,   157,   352,   936,   158,  1471,   552,   202,
     278,  1248,  1250,  1682,  1338,   419,    89,   163,  1252,    89,
    1253,   557,   450,   450,   204,   509,   510,   217,   864,  1696,
     450,    89,   318,   354,   218,   355,   533,   356,   278,   866,
     307,   870,   185,   185,   965,   307,   198,   314,   217,   307,
     277,   559,   307,  1107,   222,   954,   307,   307,   307,   307,
     950,   955,   307,   307,   307,   330,  1254,   332,   338,   553,
     828,   830,   832,   834,  1791,   339,   307,   278,   509,   510,
     977,   509,   510,   977,   868,   349,   350,   775,   776,   458,
     523,   345,   346,   347,   348,   415,   416,   524,   307,   307,
     307,   205,   166,   167,   168,   937,   573,   791,   574,   943,
     349,   350,   307,   307,   175,   342,   176,    89,   942,   666,
     346,   347,   348,  1404,  1405,   307,   936,   307,   212,  1154,
    1155,   345,   346,   347,   348,   953,   262,   349,   350,   263,
     448,   452,   264,   349,   350,  1126,   224,   271,  -504,   272,
     349,   350,   206,   956,  -508,   509,   510,   509,   510,   670,
     346,   347,   348,   450,   207,   307,   307,   851,   345,   346,
     347,   348,   512,   784,   345,   346,   347,   348,   307,   509,
     510,   859,   225,   345,   346,   347,   348,   349,   350,   509,
     510,  1830,   214,   349,   350,   215,   522,   865,   346,   347,
     348,   718,   349,   350,   719,   790,   450,   450,   450,   450,
     450,   450,   450,   450,   307,   450,   450,   226,   450,   450,
     450,   450,   450,   608,   509,   510,   450,   450,   450,   450,
     450,   278,  1291,   278,   227,   230,   509,   510,   231,   109,
    1232,   232,   192,   509,   510,   509,   510,   254,   255,   219,
     307,   418,  1255,   869,   346,   347,   348,   256,   208,  1555,
     209,  1639,   464,   597,   265,   598,   711,   469,   712,   509,
     510,   473,   342,   509,   510,   342,   655,   721,   479,   228,
     719,   599,  1902,   233,   663,  1641,   509,   510,   307,  1643,
     220,   509,   510,   279,  1048,   345,   346,   347,   348,   223,
     509,   510,  1651,   224,  1115,  1049,   316,  1653,  1120,   675,
     509,   510,   229,  1050,  1051,  1052,  1654,   326,   234,  1053,
    1054,  1055,  1056,   307,   307,   638,  1762,   640,   641,   642,
     643,   644,   238,   646,   647,   248,   649,   650,   651,   727,
     653,   728,   419,   419,   657,   658,   659,   660,   661,   349,
     350,   249,    48,    49,    50,    51,   509,   510,   713,  1035,
    -506,    56,  1048,   714,    59,   307,   307,   307,   756,   759,
     762,   765,  1765,  1049,   817,   253,   818,   278,   509,   510,
     819,  1050,  1051,  1052,   261,   509,   510,  1053,  1054,  1055,
    1056,   307,   243,   273,  1768,   244,   274,   245,   307,   283,
    1427,  1776,   509,   510,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,  1778,   417,
     349,   350,   439,   284,  1292,  1048,   509,   510,  1272,   287,
     716,   451,   451,   288,   307,   717,  1049,  1697,  1698,   451,
     509,   510,  1833,  1699,  1050,  1051,  1052,   459,   509,   510,
    1053,  1054,  1055,  1056,  1048,   289,  1834,  1216,   309,  1218,
     817,  1220,   818,  1222,  1847,  1049,   844,   727,  1763,   733,
    1453,  1454,   686,  1050,  1051,  1052,  1048,   509,   510,  1053,
    1054,  1055,  1056,   480,   481,   482,   316,  1049,   485,   486,
     487,   509,   510,  1885,   307,  1050,  1051,  1052,   307,   349,
     350,  1053,  1054,  1055,  1056,   349,   350,  1886,   323,   879,
    -507,   349,   350,   817,   398,   818,  -505,  1710,   903,  1713,
    1254,  1716,  -509,  1254,   528,   529,  1254,   239,  1701,  1702,
     240,  1766,   310,   241,  1699,   242,  1162,   307,   541,   542,
     727,   307,   737,   918,   450,   769,   770,   278,   717,   450,
     509,   510,   945,   307,   307,   434,   435,   436,   437,   438,
    1769,   311,   312,   938,   439,   321,   546,   944,   547,   319,
     548,  1183,   451,   184,  1048,   185,   727,   307,   560,   320,
     322,   561,  1843,   336,   562,  1049,   563,   806,   807,   808,
    1339,  1186,  1608,  1050,  1051,  1052,   727,  1609,   307,  1053,
    1054,  1055,  1056,   992,   382,   594,  1352,   595,   727,   548,
     743,   383,   384,   835,   185,   451,   451,   451,   451,   451,
     451,   451,   451,   387,   451,   451,  1254,   451,   451,   451,
     451,   451,   727,   388,   837,   451,   451,   451,   451,   451,
     662,   862,   664,   863,  1332,  1333,   307,   389,   406,  1336,
    1337,  1816,   817,   441,   818,   307,   873,   307,   727,   307,
     958,   307,   986,   436,   437,   438,   307,   990,   394,   399,
     439,   307,  1254,   422,   817,  1254,   818,   400,  1254,   926,
    1887,  1254,   706,   401,   707,   817,   708,   818,   404,   307,
     928,   185,   405,   307,   817,   445,   818,   307,   817,   727,
     818,   423,   817,  1321,   818,   450,   727,  1324,  1031,   440,
     467,   879,  1862,   727,  1865,  1032,  1868,  1254,   727,  1254,
    1073,  1254,  1871,   570,   727,   727,  1074,  1075,   472,   727,
     307,  1092,   727,   477,  1123,   450,   478,   483,   307,   450,
     450,  1539,  1540,  1192,  1465,  1193,  1344,  1198,   727,  1199,
    1229,   450,   727,   450,  1273,   727,   727,  1278,  1279,   979,
     484,   488,  1116,   983,  1826,  1907,  1121,  1909,   727,  1911,
    1280,   489,  1125,  1127,   727,   490,  1281,   278,   491,   496,
     307,   307,   307,   307,   499,   727,   821,  1283,  1048,   727,
    1346,  1284,  1347,  1138,   492,   493,  1458,  1459,   727,  1049,
    1348,  1462,  1463,   494,   727,   450,  1349,  1050,  1051,  1052,
     727,   534,  1350,  1053,  1054,  1055,  1056,   727,   495,  1351,
    1033,  1048,   502,  1128,   307,   307,   727,   307,  1388,   307,
     307,   503,  1049,   307,   307,  1575,   514,  1495,   307,  1496,
    1050,  1051,  1052,  1527,   515,  1528,  1053,  1054,  1055,  1056,
     727,   525,  1564,  1134,  1614,   526,  1615,  1136,  1137,   727,
     727,  1630,  1631,  1495,   536,  1652,  1177,  1178,  1081,  1142,
    1495,  1143,  1694,  1718,   727,  1719,  1734,  1088,  1736,  1089,
    1737,  1090,   717,  1091,  1739,  1495,   342,  1744,  1094,  1321,
    1324,  1746,  1747,  1097,  1889,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   571,   437,   438,  1495,
     727,  1750,  1758,   439,   727,  1614,  1777,  1827,   727,   727,
    1846,  1848,  1551,  1182,   516,   307,   307,   307,  1495,   727,
    1857,  1894,  1485,  1899,   527,  1900,   307,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   537,  1133,   451,   531,   439,   988,  1495,   451,  1921,
     538,   543,   258,   260,  1931,   266,  1932,  1705,   539,   540,
     544,   545,   450,   450,  1125,  1127,   550,   450,   450,   572,
     576,   583,   582,   588,   589,   185,   590,   278,   592,   606,
    1177,  1178,   607,   610,   611,   614,   439,   676,   184,   677,
     723,   307,  1165,  1166,  1167,  1168,   679,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   724,   740,   307,   749,   439,   744,   745,   746,   307,
       7,     8,   772,   750,  1576,   307,   773,   307,   307,   774,
     797,   799,   307,   307,   800,   307,   802,   307,  1340,   307,
     809,   307,   307,   307,   810,  1048,   816,   822,   824,   825,
    1209,   826,   849,   852,   860,   861,  1049,  1367,   874,   307,
     875,   906,   907,   908,  1050,  1051,  1052,   925,   911,   912,
    1053,  1054,  1055,  1056,   307,   913,   923,   924,   307,   930,
     307,   931,   932,  1675,   933,   934,   680,    24,    25,   681,
      27,    28,   682,    30,   683,    32,   939,    33,   940,   947,
     948,   975,    38,    39,   451,    41,    42,    43,   982,   985,
     987,    46,   989,  1011,   450,   450,  1048,   993,   996,   450,
     450,   997,  1016,   998,  1000,  1001,  1002,  1049,  1003,  1005,
    1006,  1007,  1018,   450,   451,  1050,  1051,  1052,   451,   451,
    1020,  1053,  1054,  1055,  1056,    67,    68,    69,  1021,  1022,
     451,  1891,   451,  1023,  1024,  1025,   504,   505,  1026,  1034,
    1027,  1068,  1111,   278,   513,  1098,  1041,  1042,   521,   307,
    1099,  1082,  1048,  1100,  1112,  1113,   316,  1083,   424,   450,
    1676,  1085,   307,  1049,  1086,  1087,  1101,  1117,  1118,  1468,
    1147,  1050,  1051,  1052,  1466,  1109,  1149,  1053,  1054,  1055,
    1056,  1152,  1157,  1158,   451,  1160,  1164,  1478,  1174,  1176,
    1161,  1181,  1172,  1173,  1188,   805,  1048,  1196,   307,   307,
    1202,  1207,  1893,  1203,  1721,  1208,  1210,  1049,  1211,  1214,
     419,   419,  1215,  1224,  1503,  1050,  1051,  1052,  1225,  1226,
    1227,  1053,  1054,  1055,  1056,  1228,   307,  1230,   307,  1240,
     307,  1467,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1241,   307,  1242,  1243,   439,  1257,
    1258,  1244,   307,  1259,  1534,  1260,  1261,  1264,  1924,  1048,
    1263,  1265,   307,  1266,  1269,  1267,   307,  1268,  1270,  1288,
    1049,  1293,  1294,  1296,  1316,  1299,  1301,  1500,  1050,  1051,
    1052,  1304,  1435,  1306,  1053,  1054,  1055,  1056,  1308,  1309,
    1310,  1317,   307,   430,   431,   432,   433,   434,   435,   436,
     437,   438,  1925,  1580,  1466,  1318,   439,  1319,  1342,  1360,
    1328,  1363,  1353,   307,  1320,  1341,  1368,  1358,  1593,  1596,
    1597,  1359,  1369,  1373,  1377,  1371,  1372,  1378,  1379,  1380,
    1817,  1381,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1383,  1384,  1385,   307,
     439,   451,   451,  1386,   307,  1391,   451,   451,   705,  1392,
    1401,  1402,  1403,  1409,  1417,  1926,   316,  1410,  1421,  1422,
    1423,  1424,  1431,  1432,  1436,   307,  1439,  1446,  1448,   922,
    1447,  1452,  1456,  1469,  1455,  1518,  1472,  1475,   307,  1480,
    1481,   450,   780,   781,  1483,  1486,  1487,  1488,  1489,  1499,
     505,   278,  1507,  1508,  1509,  1512,  1514,  1552,  1515,  1517,
     307,  1521,  1522,  1516,  1523,  1524,  1525,  1526,  1529,  1542,
    1530,  1531,  1545,  1548,  1556,  1559,   307,  1563,  1567,   307,
    1582,  1585,  1589,  1598,  1599,  1600,   419,  1601,  1602,  1606,
    1604,  1605,  1607,  1616,  1625,   307,  1628,  1634,  1627,  1613,
     307,  1629,  1646,  1635,   110,   333,  1648,  1637,  1655,  1638,
     113,   114,   115,  1666,  1661,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,  1667,  1640,
    1668,  1669,  1642,  1644,  1649,  1670,   307,  1671,  1672,   147,
     148,   149,  1677,   451,   451,  1684,   154,  1159,   451,   451,
    1688,  1689,  1690,  1691,  1692,   307,  1693,   159,   160,   161,
    1695,  1717,   451,  1724,  1735,   162,  1740,  1741,  1748,  1754,
     187,  1757,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1751,  1771,  1772,  1755,
     439,  1759,   316,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,  1775,   451,  1784,
    1795,   439,  1800,   307,  1802,   307,  1805,  1806,  1809,  1810,
    1206,  1813,  1819,  1841,  1814,  1854,  1863,  1786,   307,  1866,
    1835,  1837,  1869,  1839,  1872,  1874,  1883,  1664,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,  1903,
     165,  1906,   334,   439,   169,  1908,  1910,  1912,   170,   171,
     172,   173,   174,  1918,  1933,  1934,    89,  1935,  1936,  1855,
    1937,  1938,  1882,  1940,  1362,  1787,  1888,  1687,    94,   722,
     177,   178,  1375,  1686,   307,   179,   103,   752,  1890,  1892,
     299,  1704,   450,  1703,  1901,   183,  1482,   497,     0,     0,
    1038,     0,     0,     0,     0,     0,     0,  1044,     0,     0,
       0,     0,  1725,  1059,     0,  1853,     0,     0,     0,   307,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,   450,     0,   450,   439,
       0,   407,   408,   409,   411,   413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   446,     0,
       0,     0,   453,     0,     0,     0,     0,     0,   450,     0,
       0,     0,     0,     0,     0,     0,   460,   462,   465,   466,
       0,   468,   462,   470,   471,     0,   462,   474,   475,     0,
       0,     0,     0,   462,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
    1880,   498,   439,     0,     0,     0,     0,     0,     0,     0,
     507,   508,     0,     0,     0,     0,     7,     8,     0,   508,
       0,     0,     0,     0,     0,  1818,     0,  1821,     0,     0,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     0,     0,     0,  1917,     0,  1920,     0,     0,     0,
       0,     0,   565,   567,   462,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,   578,   579,     0,   581,     0,
       0,     0,   584,   585,   586,     0,  1939,   587,     0,     0,
       0,     0,   680,    24,    25,   681,    27,    28,   682,    30,
     683,    32,     0,    33,   603,   605,  1873,     0,    38,    39,
       0,    41,    42,    43,     0,     0,  1191,    46,   612,   613,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,   648,     0,     0,     0,     0,     0,
     654,     0,   656,     0,     0,     0,     0,     0,  1237,  1238,
    1239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   685,   462,     0,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,     0,     0,   703,   704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   857,     0,     0,     0,   565,     0,     0,     0,     0,
       0,   731,     0,     0,     0,     0,   736,     0,     0,     0,
       0,   741,   742,     0,     0,     0,     0,   747,   748,     0,
       0,     0,   753,   755,   758,   761,   764,   766,   767,   768,
     462,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1262,     0,     0,     0,     0,   785,   786,
     787,   407,   408,   788,     0,     0,     0,   792,   793,   794,
     795,   796,     0,     0,     0,   801,     0,   803,   804,     0,
       0,   451,   462,   462,   462,     0,     0,   811,   812,   813,
     814,   815,     0,     0,     7,     8,     0,   823,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   462,     0,
       0,     0,     0,     0,   838,   840,     0,   842,   843,     0,
       0,     0,     7,     8,     0,   451,     0,   451,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   814,   815,
       0,   842,   843,     0,     0,     0,     0,     0,     0,     0,
     872,   462,     0,     0,     0,   876,     0,   451,  1426,     0,
     680,    24,    25,   681,    27,    28,   682,    30,   683,    32,
       0,    33,     0,     0,     0,     0,    38,    39,   476,    41,
      42,    43,     0,     0,     0,    46,     0,     0,   680,    24,
      25,   681,    27,    28,   682,    30,   683,    32,     0,    33,
       0,     0,   500,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,   946,    67,
      68,    69,     0,     0,     0,     0,   530,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,    67,    68,    69,
     973,   974,     0,     0,   462,   980,   981,     0,   462,   984,
       0,     0,     0,     0,     0,     0,     0,   991,     0,     0,
     840,   994,     0,     0,     0,     0,  1506,     0,     0,     7,
       8,   570,     0,     0,  1008,     0,     0,     0,     0,   858,
       0,   600,   601,  1014,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1541,   462,  1544,  1036,  1547,     0,
       0,     0,  1039,  1040,     0,     0,     0,     0,  1043,     0,
    1334,     0,  1558,     0,     0,  1561,  1562,     0,     0,     0,
     645,  1067,     0,     0,  1069,   680,    24,    25,   681,    27,
      28,   682,    30,   683,    32,     0,    33,     0,     0,     0,
       0,    38,    39,   462,    41,    42,    43,     0,     0,     0,
      46,     0,   462,     0,   462,     0,   462,     0,   462,     0,
       0,   447,   112,   462,     0,     0,     0,     0,   462,     0,
       0,     0,     0,     0,  1102,     0,  1104,  1105,     0,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,   150,   151,
     152,   153,     0,     0,     0,  1129,   155,   156,   157,     0,
       0,   158,     0,  1130,  1131,  1132,     0,   462,     0,     0,
       0,     0,   163,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   571,   437,   438,  1141,     0,     0,
       0,   439,  1144,     0,  1037,     0,     0,     0,     0,     0,
       0,  1148,     0,     0,     0,     0,     0,  1156,     0,     0,
       0,  1343,     0,     0,     0,     0,     0,   462,   462,   462,
     462,     0,     0,  1170,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,   463,
       0,     0,   439,     0,   463,     7,     8,     0,   463,     0,
       0,     0,     0,     0,     0,   463,     0,   166,   167,   168,
       0,     0,  1709,     0,  1712,     0,  1715,     0,     0,   175,
       0,   176,    89,     0,  1723,   462,     0,  1726,     0,     0,
       0,     0,     0,     0,     0,  1217,     0,  1219,     0,  1221,
       0,  1223,     0,     0,     0,     0,     0,   817,     0,   818,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   680,    24,    25,   681,    27,    28,   682,    30,   683,
      32,  1752,    33,     0,   566,  1756,   463,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
     935,     0,  1271,     0,   941,     0,     0,  1274,     0,  1275,
    1276,  1277,     0,     0,     0,     0,     0,  1282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,   112,  1796,     0,     0,     0,  1798,  1300,
       0,     0,     0,     0,  1305,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     7,
       8,  1820,     0,   439,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   150,
     151,   152,   153,  1015,     0,  1345,     0,   155,   156,   157,
       0,     0,   158,     0,     0,     0,  1354,  1355,     0,     0,
    1060,     0,     0,   163,     0,     0,     0,     0,     0,   463,
       0,  1364,  1366,     0,     0,     0,  1860,  1861,     0,     0,
       0,     0,     0,     0,     0,   680,    24,    25,   681,    27,
      28,   682,    30,   683,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,   566,     0,  1212,
      46,     0,     0,     0,     0,     0,  1406,  1407,  1408,     0,
       0,     0,     0,     0,     0,     0,  1418,     0,  1420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1425,
       0,     0,   463,   463,    67,    68,    69,   462,   166,   167,
     168,     0,  1437,     0,     0,  1110,     0,     0,     0,  1114,
     175,     0,   176,  1119,     0,  1460,     0,     0,     0,     0,
       0,     0,     0,  1449,  1450,  1451,     0,     0,     0,     0,
       0,     0,     0,     0,   463,   463,   463,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,  1135,     0,   439,     0,     0,     0,
     463,     0,     0,     0,  1103,     0,     0,   841,     0,     0,
       0,     0,     0,  1479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1492,     0,     0,
       0,     0,  1498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,  1504,  1505,     0,     0,     0,
       0,     0,  1510,  1511,     0,     0,     0,  1513,     0,     0,
       0,     0,     0,     0,     0,  1520,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   462,   462,  1532,     0,  1533,
    1194,  1195,     0,  1197,     0,  1200,  1201,     0,     0,  1204,
    1205,  1550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,     0,     0,     0,   462,     0,     0,
    1565,     0,     0,     0,     0,  1568,  1569,  1570,  1571,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1579,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,  1595,     0,   463,   439,     0,     0,
     463,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   841,   995,     0,     0,     0,  1610,  1611,     0,
       0,     0,     0,     0,     0,  1617,     0,     0,     0,     0,
       0,  1285,  1286,  1287,     0,     0,     0,     0,     0,     0,
       0,     0,  1295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,     0,     0,
       0,  1636,     0,     0,     0,     0,     0,   680,    24,    25,
     681,    27,    28,   682,    30,   683,    32,     0,    33,  1650,
       0,   565,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,  1662,     0,  1663,
       0,     0,   462,     0,     0,   463,     0,  1357,     0,     0,
       0,     0,     0,     0,   463,  1674,   463,     0,   463,     0,
     463,     0,     0,     0,     0,   463,    67,    68,    69,  1376,
     463,     0,     0,  1679,     0,  1382,     0,     0,  1683,     0,
       0,  1387,     0,  1389,  1390,     0,     0,     0,  1393,  1394,
       0,  1395,     0,  1396,     0,  1397,   462,  1398,  1399,  1400,
       0,     0,     0,  1708,     0,  1711,     0,  1714,     0,     0,
       0,     0,     0,     0,     0,  1419,     0,   462,     0,     0,
       0,  1727,  1728,  1729,  1730,  1731,     0,     0,     0,   463,
    1430,     0,     0,     0,  1434,     0,  1108,     0,     0,     0,
       0,     0,     0,     0,  1742,  1743,     0,     0,     0,  1745,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1749,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1760,     0,     0,     0,     0,     0,     0,     0,     0,   463,
     463,   463,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1464,     0,     0,     0,     0,
    1785,     0,     0,     0,     0,  1498,     0,     0,     0,     0,
       0,     0,  1793,     0,     0,     0,     0,   845,     0,     0,
       0,     0,     0,     0,     0,  1490,  1804,     0,     0,  1808,
       0,     0,  1812,     0,     0,     0,  1815,   463,  1502,     0,
     462,     0,   462,  1822,  1823,  1824,  1825,     0,     0,     0,
       0,     0,     0,  1829,     0,     0,  1831,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,     0,   892,
     893,   894,   895,   896,   897,   898,     0,     0,     0,   902,
     904,   905,     0,     0,     0,   909,   910,     0,     0,     0,
       0,   915,   916,   917,     0,   919,  1859,   210,   211,     0,
       0,     0,   927,   929,  1357,     0,     0,     0,     0,     0,
       0,   462,     0,  1875,  1876,  1877,  1878,     0,     0,     0,
     952,  1572,     0,     0,     0,     0,     0,     0,  1581,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1588,     0,
       0,     0,  1592,     0,     0,     0,     0,     0,     0,  1904,
    1905,     0,     0,     0,     0,     0,     0,     0,     0,  1913,
    1914,  1915,  1916,     0,     0,     0,     0,     0,  1612,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,   343,     0,     0,   439,     0,  1357,
       0,     0,     0,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,     0,     0,
       0,   385,   386,     0,     0,  1647,   390,   391,   392,   393,
       0,     0,   395,     0,     0,     0,     0,     0,   396,   397,
       0,     0,     0,     0,   402,   403,     0,     0,     0,   110,
     290,     0,     0,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,     0,     0,  1357,     0,     0,   463,
       0,  1566,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,  1357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,  1720,     0,     0,   293,     0,     0,   294,     0,     0,
     295,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,   549,     0,     0,     0,
       0,     0,  1753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   575,     0,     0,     0,     0,     0,     0,
       0,  1770,     0,     0,     0,     0,     0,     0,     0,     0,
    1169,     0,     0,     0,     0,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,   463,   463,     0,
       0,     0,     0,  1189,  1190,   517,  1557,     0,     0,     0,
     179,     0,     0,     0,  1603,   519,     0,     0,     0,     0,
     183,     0,   257,   568,     0,   463,     0,     0,     0,   463,
       0,     0,     0,     0,  1357,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   678,     0,   110,   111,   112,     0,     0,
       0,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   570,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,   155,   156,   157,     0,  1357,   158,     0,   159,   160,
     161,     0,     0,     0,     0,  1307,   162,   163,     0,     0,
       0,  1311,  1312,  1313,  1314,  1315,  1633,     0,     0,     0,
       0,  1322,  1325,   566,     0,  1329,  1330,  1331,     0,     0,
       0,     0,  1335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,  1665,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,     0,     0,   463,   170,
     171,   172,   173,   174,   175,     0,   176,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
       0,   177,   178,     0,     0,     0,   179,     0,     0,     0,
       0,   180,     0,   181,     0,   182,   183,     0,   184,     0,
     185,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   726,   437,   438,  1440,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1457,
       0,     0,     0,     0,  1461,     0,     0,     0,     0,     0,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1783,     0,     0,     0,   439,     0,
       0,     0,     0,     0,  1473,  1474,     0,     0,  1476,  1477,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,   463,     0,   463,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   290,     0,     0,
       0,     0,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     292,  1842,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,     0,     0,     0,   154,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,   159,
     160,   161,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   293,     0,     0,   294,     0,     0,   295,     0,   296,
    1583,  1584,     0,     0,  1586,  1587,     0,     0,     0,     0,
    1590,   297,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,   165,     0,     0,   439,   169,   817,     0,   818,
     170,   171,   172,   173,   174,  1738,   570,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   461,     0,     0,     0,   179,     0,  1145,
    1146,     0,   299,     0,     0,  1150,  1151,   183,     0,     0,
     568,     0,     0,     0,     0,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   110,
     290,   112,     0,   439,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,   156,   157,     0,     0,
     158,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,   163,     0,     0,   293,     0,     0,   294,     0,     0,
     295,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   726,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     853,     0,     0,     0,     0,     0,     0,     0,  1297,  1298,
       0,     0,     0,  1302,  1303,   165,   166,   167,   168,   169,
     959,     0,     0,   170,   171,   172,   173,   174,   175,     0,
     176,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   298,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,   110,   290,   112,
     183,     0,   300,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,   155,   156,   157,     0,     0,   158,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,   163,
       0,     0,   293,     0,     0,   294,     0,     0,   295,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,   165,   166,   167,   168,   169,     0,     0,
       0,   170,   171,   172,   173,   174,   175,     0,   176,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   298,     0,     0,     0,   179,     0,
       0,     0,     0,   299,     0,   110,   333,   112,   183,     0,
    1591,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,   155,   156,   157,     0,     0,   158,     0,   159,   160,
     161,     0,   110,   333,   112,     0,   162,   163,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   155,   156,
     157,     0,     0,   158,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,     0,     0,     0,   170,
     171,   172,   173,   174,   175,  1093,   176,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,     0,  1290,     0,   179,     0,     0,     0,
       0,   299,     0,     0,     0,     0,   183,     0,  1365,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,   165,   166,
     167,   168,   169,     0,     0,   596,   170,   171,   172,   173,
     174,   175,     0,   176,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   333,   112,   183,     0,  1578,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     7,     8,     0,   155,   156,   157,     0,
       0,   158,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,   163,     0,     0,     0,     0,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,   680,
      24,    25,   681,    27,    28,   682,    30,   683,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,     0,     0,     0,   170,   171,   172,   173,   174,   175,
       0,   176,    89,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,   177,   178,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
     291,   183,     0,  1594,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,  1231,     0,
     154,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,     0,   295,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,   680,    24,    25,
     681,    27,    28,   682,    30,   683,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,   177,   298,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,   110,   290,  1428,   183,
       0,   300,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,     0,  1773,     0,   154,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,   161,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   293,     0,     0,   294,     0,     0,   295,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,     0,     0,     0,   680,    24,    25,   681,    27,
      28,   682,    30,   683,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,     0,   177,   298,     0,     0,     0,   179,     0,     0,
       0,     0,   299,     0,   110,   290,     0,   183,     0,  1429,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,  1844,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,     0,     0,     0,   293,
       0,     0,   294,     0,     0,   295,     0,   296,   324,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,     0,   150,   151,   152,   153,     0,
       0,     0,     0,   155,   156,   157,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
     165,     0,     0,     0,   169,     0,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   298,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,   110,   290,     0,   183,     0,   300,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,     0,
       0,     0,     0,     0,   166,   167,   168,   147,   148,   149,
       0,     0,     0,     0,   154,     0,   175,     0,   176,    89,
       0,     0,     0,     0,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,     0,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,   447,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   150,   151,   152,   153,     0,     0,     0,
       0,   155,   156,   157,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   461,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,     0,   183,     0,   564,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   292,     0,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   147,   148,   149,     0,     0,
       0,     0,   154,     0,   175,     0,   176,    89,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,     0,     0,     0,   293,     0,     0,   294,   327,
     112,   295,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   150,   151,   152,   153,
       0,     0,     0,     0,   155,   156,   157,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   461,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
       0,   183,     0,   839,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,   166,   167,   168,     0,     0,
       0,     0,     0,   147,   148,   149,     0,   175,     0,   176,
     154,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,     0,   295,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,   680,    24,    25,
     681,    27,    28,   682,    30,   683,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,   177,   298,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,   110,   290,     0,   183,
       0,  1433,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,   161,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   293,     0,     0,   294,     0,     0,   295,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1537,     0,  1538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,  1557,     0,     0,     0,   179,     0,     0,
       0,     0,   519,     0,   110,   333,     0,   183,     0,   257,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     110,   333,   112,     0,     0,   162,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,   155,   156,   157,     0,
       0,   158,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,   163,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
     165,   439,     0,     0,   169,   672,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     517,   518,     0,     0,     0,   179,     0,     0,     0,     0,
     519,     0,     0,     0,     0,   183,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,     0,     0,     0,   170,   171,   172,   173,   174,   175,
       0,   176,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,     0,     0,
       0,   179,   110,   290,     0,     0,   299,     0,   113,   114,
     115,   183,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,     0,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1573,     0,  1574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   461,
       0,     0,     0,   179,   110,   333,     0,     0,   299,     0,
     113,   114,   115,   183,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   333,   159,   160,   161,
       0,   113,   114,   115,     0,   162,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
     161,     0,     0,     0,     0,     0,   162,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     165,     0,     0,  1706,   169,  1707,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,     0,     0,     0,     0,
     299,   410,     0,     0,     0,   183,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,   165,     0,     0,   439,   169,     0,     0,   856,   170,
     171,   172,   173,   174,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,     0,     0,     0,   179,     0,     0,     0,
       0,   299,   110,   333,   412,     0,   183,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   333,   159,   160,   161,     0,   113,
     114,   115,     0,   162,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   148,
     149,     0,     0,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,     0,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,   165,     0,
       0,     0,   169,   957,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   179,     0,     0,     0,     0,   299,   602,
       0,     0,     0,   183,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,   165,
       0,     0,   439,   169,     0,     0,   871,   170,   171,   172,
     173,   174,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,     0,     0,     0,   179,     0,     0,     0,     0,   299,
     110,   333,   604,     0,   183,     0,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1010,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1063,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     1,     0,
       0,    -4,     0,     0,     0,     0,     0,     0,     0,    -4,
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
       0,     0,  1084,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1122,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1235,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1535,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1554,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1620,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1621,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1622,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1623,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1624,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1656,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1722,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1732,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1733,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1761,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1764,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1767,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1794,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1801,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1836,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1838,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1840,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1858,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1884,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1922,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1923,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1927,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1928,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1929,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1930,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,   771,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,  1632,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   836,
       0,     0,     0,     0,   778,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
     715,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,   778,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,   779,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,   850,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,   891,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
     899,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,   900,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,   901,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,   914,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1045,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1046,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1047,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1078,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1187,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1233,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1234,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1289,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1441,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1442,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1443,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1444,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1493,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1494,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1501,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1657,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1658,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1659,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1660,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1680,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1681,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1685,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1779,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1780,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1781,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1782,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1789,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1792,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1832,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1849,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1850,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1851,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1852,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1895,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1896,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1897,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1898,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,   878,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,   972,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1071,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1072,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,  1076,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1077,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,  1080,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1096,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1124,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
    1180,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1185,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1438,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1484,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1645,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   668,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   725,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   729,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   730,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   732,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   734,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   735,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     738,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   739,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   836,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   846,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   847,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   848,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   854,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   855,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   867,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   877,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     971,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   999,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1004,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1009,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1012,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1013,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1019,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1028,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1029,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1030,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1062,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1064,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1065,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1066,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1070,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1079,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1095,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1179,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1184,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1327,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1536,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1553,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1577,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1788,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1856,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439
};

static const yytype_int16 yycheck[] =
{
       3,  1431,     4,     6,     3,     5,   250,     4,     4,     4,
      84,     4,     6,   511,   512,     4,     6,   410,     4,   412,
     265,   414,     4,     4,   199,     4,   201,     7,     4,     4,
       4,   199,   277,   208,     5,    13,     5,  1057,     5,     5,
       5,     5,     5,     0,     6,     6,     6,   199,   379,   201,
     381,     5,   189,   190,    57,     6,   208,     6,     6,     4,
     189,   190,    65,   394,     6,     6,   199,    70,     6,     6,
     207,    81,     6,     4,    84,     6,    86,   206,    81,   189,
     190,     5,   189,   190,   101,   330,  1516,   332,   203,   199,
     195,   196,     7,   208,     6,   112,   206,   200,   205,   142,
     207,   206,   205,   120,   121,   122,   189,   190,  1061,   126,
     127,   128,   129,     6,   157,   158,     4,     5,   189,   190,
       7,     6,   205,    81,   207,     6,    84,     4,   189,   190,
      81,    82,     7,    78,   205,    81,   207,    82,    84,   132,
     133,   134,   135,   199,   205,   145,   200,    78,   202,    94,
     206,   205,    40,    41,    42,    43,    44,    45,    46,    47,
       7,     4,     6,    51,    52,    53,    54,   153,   199,     7,
     130,    59,    60,    61,   109,     7,    64,   156,   145,     6,
     183,   130,   130,  1613,     7,   184,   175,    75,   130,   175,
     207,   145,   195,   196,     6,   189,   190,   199,     7,  1629,
     203,   175,   199,   199,   206,   201,   201,   203,   211,   602,
     213,   604,   208,   208,   207,   218,   206,   206,   199,   222,
     206,   145,   225,   203,   206,   206,   229,   230,   231,   232,
     206,   206,   235,   236,   237,   206,  1256,   206,   199,   206,
     206,   206,   206,   206,   206,   206,   249,   250,   189,   190,
     187,   189,   190,   187,     7,   195,   196,   502,   503,   210,
     199,   176,   177,   178,   179,   142,   143,   206,   271,   272,
     273,     6,   160,   161,   162,   668,   199,   522,   201,   672,
     195,   196,   285,   286,   172,   208,   174,   175,   203,   176,
     177,   178,   179,     6,     7,   298,     7,   300,   199,   142,
     143,   176,   177,   178,   179,   206,    78,   195,   196,    81,
     195,   196,    84,   195,   196,   203,   199,    84,   206,    86,
     195,   196,   201,   206,   206,   189,   190,   189,   190,   176,
     177,   178,   179,   336,   201,   338,   339,   582,   176,   177,
     178,   179,   206,   205,   176,   177,   178,   179,   351,   189,
     190,   596,    88,   176,   177,   178,   179,   195,   196,   189,
     190,  1791,   199,   195,   196,   199,   206,   176,   177,   178,
     179,   202,   195,   196,   205,   205,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,    84,   391,   392,
     393,   394,   395,   344,   189,   190,   399,   400,   401,   402,
     403,   404,     8,   406,    84,    78,   189,   190,    81,     3,
     205,    84,     6,   189,   190,   189,   190,   189,   190,   199,
     423,     4,   205,   176,   177,   178,   179,   199,   199,   205,
     201,   205,   213,   199,   206,   201,   199,   218,   201,   189,
     190,   222,   208,   189,   190,   208,   397,   202,   229,     6,
     205,   336,  1882,    84,   405,   205,   189,   190,   461,   205,
     199,   189,   190,    57,   101,   176,   177,   178,   179,   199,
     189,   190,   205,   199,   867,   112,    70,   205,   871,   414,
     189,   190,   206,   120,   121,   122,   205,    81,    84,   126,
     127,   128,   129,   496,   497,   380,   205,   382,   383,   384,
     385,   386,    86,   388,   389,   199,   391,   392,   393,   205,
     395,   207,   511,   512,   399,   400,   401,   402,   403,   195,
     196,    81,   105,   106,   107,   108,   189,   190,   200,   774,
     206,   114,   101,   205,   117,   538,   539,   540,   489,   490,
     491,   492,   205,   112,   200,   206,   202,   550,   189,   190,
     206,   120,   121,   122,   206,   189,   190,   126,   127,   128,
     129,   564,    81,    84,   205,    84,    81,    86,   571,    81,
     207,   205,   189,   190,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   205,   183,
     195,   196,   198,    84,   200,   101,   189,   190,   203,     4,
     200,   195,   196,     4,   607,   205,   112,   105,   106,   203,
     189,   190,   205,   111,   120,   121,   122,   211,   189,   190,
     126,   127,   128,   129,   101,     4,   205,  1020,     4,  1022,
     200,  1024,   202,  1026,   205,   112,   206,   205,   207,   207,
       6,     7,   423,   120,   121,   122,   101,   189,   190,   126,
     127,   128,   129,   230,   231,   232,   250,   112,   235,   236,
     237,   189,   190,   205,   667,   120,   121,   122,   671,   195,
     196,   126,   127,   128,   129,   195,   196,   205,   201,   614,
     206,   195,   196,   200,     7,   202,   206,  1640,   205,  1642,
    1710,  1644,   206,  1713,   271,   272,  1716,    78,   105,   106,
      81,   207,   199,    84,   111,    86,   950,   710,   285,   286,
     205,   714,   207,   200,   717,   496,   497,   720,   205,   722,
     189,   190,   673,   726,   727,   189,   190,   191,   192,   193,
     207,   199,   199,   668,   198,     6,   199,   672,   201,   199,
     203,   200,   336,   206,   101,   208,   205,   750,    78,   199,
       6,    81,   207,   201,    84,   112,    86,   538,   539,   540,
    1153,   200,   200,   120,   121,   122,   205,   205,   771,   126,
     127,   128,   129,   724,   199,   199,  1169,   201,   205,   203,
     207,   199,   199,   564,   208,   379,   380,   381,   382,   383,
     384,   385,   386,   199,   388,   389,  1816,   391,   392,   393,
     394,   395,   205,   199,   207,   399,   400,   401,   402,   403,
     404,   205,   406,   207,  1145,  1146,   819,   199,   201,  1150,
    1151,  1774,   200,     6,   202,   828,   607,   830,   205,   832,
     207,   834,   717,   191,   192,   193,   839,   722,   199,   199,
     198,   844,  1862,   206,   200,  1865,   202,   199,  1868,   205,
     207,  1871,   199,   199,   201,   200,   203,   202,   199,   862,
     205,   208,   199,   866,   200,     6,   202,   870,   200,   205,
     202,   206,   200,   205,   202,   878,   205,   205,   207,   206,
     199,   816,  1835,   205,  1837,   207,  1839,  1907,   205,  1909,
     207,  1911,  1845,     8,   205,   205,   207,   207,   199,   205,
     903,   207,   205,   199,   207,   908,   206,   199,   911,   912,
     913,  1409,  1410,    84,  1307,    86,  1160,    84,   205,    86,
     207,   924,   205,   926,   207,   205,   205,   207,   207,   710,
     199,   199,   867,   714,     7,  1888,   871,  1890,   205,  1892,
     207,   199,   877,   878,   205,   199,   207,   950,   199,   206,
     953,   954,   955,   956,     4,   205,   550,   207,   101,   205,
     205,   207,   207,   914,   199,   199,  1297,  1298,   205,   112,
     207,  1302,  1303,   199,   205,   978,   207,   120,   121,   122,
     205,   201,   207,   126,   127,   128,   129,   205,   199,   207,
     771,   101,   206,   878,   997,   998,   205,  1000,   207,  1002,
    1003,   206,   112,  1006,  1007,     8,   206,   205,  1011,   207,
     120,   121,   122,     4,   206,     6,   126,   127,   128,   129,
     205,   199,   207,   908,   205,   199,   207,   912,   913,   205,
     205,   207,   207,   205,     6,   207,   971,   972,   819,   924,
     205,   926,   207,   205,   205,   207,   207,   828,   205,   830,
     207,   832,   205,   834,   207,   205,   208,   207,   839,   205,
     205,   207,   207,   844,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   205,
     205,   207,   207,   198,   205,   205,   207,   207,   205,   205,
     207,   207,   207,   978,   206,  1098,  1099,  1100,   205,   205,
     207,   207,  1346,   205,   199,   207,  1109,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     6,   903,   717,   199,   198,   720,   205,   722,   207,
     206,   201,    49,    50,   205,    52,   207,  1635,   206,   206,
     201,   201,  1145,  1146,  1079,  1080,   201,  1150,  1151,     6,
       6,   145,   206,     6,     6,   208,     6,  1160,     6,   206,
    1095,  1096,   206,     6,   201,     4,   198,   203,   206,     7,
     205,  1174,   953,   954,   955,   956,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   205,     7,  1196,     7,   198,     6,     6,     6,  1202,
      12,    13,   200,     7,   207,  1208,     6,  1210,  1211,   206,
       7,     6,  1215,  1216,     7,  1218,     6,  1220,  1153,  1222,
       6,  1224,  1225,  1226,     6,   101,     4,    56,    56,    56,
    1011,    56,   142,   206,   202,   200,   112,  1188,     6,  1242,
       6,   200,   200,   205,   120,   121,   122,   200,   205,   205,
     126,   127,   128,   129,  1257,   205,   205,   205,  1261,   200,
    1263,   200,   202,  1594,    40,    40,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    40,    89,    40,     6,
       4,     4,    94,    95,   878,    97,    98,    99,     6,     6,
       6,   103,     6,   206,  1297,  1298,   101,     7,   145,  1302,
    1303,     7,     4,     7,     7,   145,     7,   112,     7,   145,
       7,     7,     6,  1316,   908,   120,   121,   122,   912,   913,
     200,   126,   127,   128,   129,   137,   138,   139,   205,   200,
     924,   207,   926,   205,   200,   205,   253,   254,   200,   203,
     205,     6,     6,  1346,   261,     7,   207,   207,   265,  1352,
       7,   202,   101,     7,    40,    40,   950,   206,     6,  1362,
    1604,   206,  1365,   112,   206,   206,   203,    40,    40,  1320,
       6,   120,   121,   122,  1309,   206,     6,   126,   127,   128,
     129,     6,     6,     6,   978,     7,     6,  1338,   206,     6,
     201,   187,   199,   199,     7,   207,   101,     7,  1401,  1402,
       7,     7,   207,    86,  1649,     7,     7,   112,     7,     6,
    1409,  1410,     7,     7,  1365,   120,   121,   122,     7,     7,
       7,   126,   127,   128,   129,     7,  1429,     4,  1431,     4,
    1433,  1316,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     6,  1448,   206,     6,   198,     7,
       6,   199,  1455,     7,  1405,     7,     7,     6,   207,   101,
     206,     6,  1465,     6,     6,    84,  1469,     7,     6,     4,
     112,     4,     4,   207,   205,     6,     6,  1362,   120,   121,
     122,     6,  1263,     6,   126,   127,   128,   129,     6,     4,
       6,   200,  1495,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   207,  1454,  1439,   200,   198,   200,     7,     6,
     200,     6,   199,  1516,   205,   203,     6,   206,  1469,  1470,
    1471,   203,     6,    94,     6,   206,   206,   206,   206,     6,
    1775,     6,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   206,     6,     6,  1552,
     198,  1145,  1146,     5,  1557,     4,  1150,  1151,     6,     6,
     206,   206,     7,   206,   201,   207,  1160,   206,     6,     6,
       6,     6,   206,   206,   206,  1578,     4,     6,   141,     6,
       6,     6,     6,     4,   205,   145,     6,     6,  1591,     6,
       4,  1594,   509,   510,     6,     6,     6,     6,     6,     4,
     517,  1604,     6,     6,     6,     6,     5,   205,     6,     6,
    1613,     6,     6,   206,     6,     6,     6,     6,     6,     6,
    1401,  1402,     6,     6,     6,     6,  1629,     6,     6,  1632,
       6,     6,   200,     6,     6,     6,  1635,     6,     6,   203,
       7,     6,     6,     6,     5,  1648,     6,     6,    82,   206,
    1653,   206,     6,   206,     3,     4,     7,   207,     6,   207,
       9,    10,    11,     6,   140,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,   207,   206,
       6,     6,   206,   206,   206,     6,  1699,     6,     6,    48,
      49,    50,   143,  1297,  1298,     6,    55,     6,  1302,  1303,
       6,     6,     6,     6,     6,  1718,     6,    66,    67,    68,
     206,     6,  1316,     6,     6,    74,     6,   206,   206,     6,
       6,     6,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   206,     6,   101,   206,
     198,   207,  1346,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   206,  1362,     6,
       6,   198,     6,  1776,     6,  1778,     6,     6,     6,     6,
       6,     6,     6,     6,   207,     6,     6,  1738,  1791,     6,
     206,   206,     6,   206,     6,     6,     6,  1578,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     6,
     159,     6,    88,   198,   163,     6,     6,     6,   167,   168,
     169,   170,   171,     6,     6,     6,   175,     6,     6,   206,
       6,     6,   206,     6,  1183,  1741,   206,  1619,     3,   457,
     189,   190,  1195,  1618,  1847,   194,     3,   487,   206,   206,
     199,  1632,  1855,  1631,   206,   204,  1342,   206,    -1,    -1,
     777,    -1,    -1,    -1,    -1,    -1,    -1,   784,    -1,    -1,
      -1,    -1,  1653,   790,    -1,  1826,    -1,    -1,    -1,  1882,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,  1899,    -1,  1901,   198,
      -1,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,  1931,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,
      -1,   217,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,    -1,   229,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
    1855,   247,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,    -1,    -1,    -1,    -1,    12,    13,    -1,   265,
      -1,    -1,    -1,    -1,    -1,  1776,    -1,  1778,    -1,    -1,
    1594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1604,    -1,    -1,    -1,  1899,    -1,  1901,    -1,    -1,    -1,
      -1,    -1,   298,   299,   300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,   311,   312,    -1,   314,    -1,
      -1,    -1,   318,   319,   320,    -1,  1931,   323,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,   340,   341,  1847,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   993,   103,   354,   355,
      -1,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   390,    -1,    -1,    -1,    -1,    -1,
     396,    -1,   398,    -1,    -1,    -1,    -1,    -1,  1045,  1046,
    1047,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   422,   423,    -1,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,    -1,    -1,   442,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,   467,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,
      -1,   477,   478,    -1,    -1,    -1,    -1,   483,   484,    -1,
      -1,    -1,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   514,   515,
     516,   517,   518,   519,    -1,    -1,    -1,   523,   524,   525,
     526,   527,    -1,    -1,    -1,   531,    -1,   533,   534,    -1,
      -1,  1855,   538,   539,   540,    -1,    -1,   543,   544,   545,
     546,   547,    -1,    -1,    12,    13,    -1,   553,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,    -1,
      -1,    -1,    -1,    -1,   570,   571,    -1,   573,   574,    -1,
      -1,    -1,    12,    13,    -1,  1899,    -1,  1901,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,   595,
      -1,   597,   598,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     606,   607,    -1,    -1,    -1,   611,    -1,  1931,  1255,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    95,   225,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,    -1,   249,    -1,    94,    95,    -1,    97,    98,    99,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,   674,   137,
     138,   139,    -1,    -1,    -1,    -1,   273,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,   137,   138,   139,
     706,   707,    -1,    -1,   710,   711,   712,    -1,   714,   715,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,    -1,
     726,   727,    -1,    -1,    -1,    -1,  1373,    -1,    -1,    12,
      13,     8,    -1,    -1,   740,    -1,    -1,    -1,    -1,   207,
      -1,   338,   339,   749,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1411,   771,  1413,   207,  1415,    -1,
      -1,    -1,   778,   779,    -1,    -1,    -1,    -1,   784,    -1,
       6,    -1,  1429,    -1,    -1,  1432,  1433,    -1,    -1,    -1,
     387,   797,    -1,    -1,   800,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,   819,    97,    98,    99,    -1,    -1,    -1,
     103,    -1,   828,    -1,   830,    -1,   832,    -1,   834,    -1,
      -1,     4,     5,   839,    -1,    -1,    -1,    -1,   844,    -1,
      -1,    -1,    -1,    -1,   850,    -1,   852,   853,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,   891,    59,    60,    61,    -1,
      -1,    64,    -1,   899,   900,   901,    -1,   903,    -1,    -1,
      -1,    -1,    75,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   923,    -1,    -1,
      -1,   198,   928,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,   937,    -1,    -1,    -1,    -1,    -1,   943,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   953,   954,   955,
     956,    -1,    -1,   959,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,   213,
      -1,    -1,   198,    -1,   218,    12,    13,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,   229,    -1,   160,   161,   162,
      -1,    -1,  1639,    -1,  1641,    -1,  1643,    -1,    -1,   172,
      -1,   174,   175,    -1,  1651,  1011,    -1,  1654,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1021,    -1,  1023,    -1,  1025,
      -1,  1027,    -1,    -1,    -1,    -1,    -1,   200,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,  1698,    89,    -1,   298,  1702,   300,    94,    95,    -1,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
     667,    -1,  1078,    -1,   671,    -1,    -1,  1083,    -1,  1085,
    1086,  1087,    -1,    -1,    -1,    -1,    -1,  1093,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,     5,  1751,    -1,    -1,    -1,  1755,  1115,
      -1,    -1,    -1,    -1,  1120,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    12,
      13,  1778,    -1,   198,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    54,   750,    -1,  1161,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,  1172,  1173,    -1,    -1,
     207,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,   423,
      -1,  1187,  1188,    -1,    -1,    -1,  1833,  1834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    98,    99,   461,    -1,   101,
     103,    -1,    -1,    -1,    -1,    -1,  1232,  1233,  1234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1242,    -1,  1244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1255,
      -1,    -1,   496,   497,   137,   138,   139,  1263,   160,   161,
     162,    -1,  1268,    -1,    -1,   862,    -1,    -1,    -1,   866,
     172,    -1,   174,   870,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1289,  1290,  1291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   538,   539,   540,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,   911,    -1,   198,    -1,    -1,    -1,
     564,    -1,    -1,    -1,   207,    -1,    -1,   571,    -1,    -1,
      -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1353,    -1,    -1,
      -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   607,    -1,  1371,  1372,    -1,    -1,    -1,
      -1,    -1,  1378,  1379,    -1,    -1,    -1,  1383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1391,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1401,  1402,  1403,    -1,  1405,
     997,   998,    -1,  1000,    -1,  1002,  1003,    -1,    -1,  1006,
    1007,  1417,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1429,    -1,    -1,    -1,  1433,    -1,    -1,
    1436,    -1,    -1,    -1,    -1,  1441,  1442,  1443,  1444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1454,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,  1470,    -1,   710,   198,    -1,    -1,
     714,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   726,   727,    -1,    -1,    -1,  1493,  1494,    -1,
      -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,    -1,
      -1,  1098,  1099,  1100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,    -1,    -1,
      -1,  1537,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,  1555,
      -1,  1557,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,  1573,    -1,  1575,
      -1,    -1,  1578,    -1,    -1,   819,    -1,  1174,    -1,    -1,
      -1,    -1,    -1,    -1,   828,  1591,   830,    -1,   832,    -1,
     834,    -1,    -1,    -1,    -1,   839,   137,   138,   139,  1196,
     844,    -1,    -1,  1609,    -1,  1202,    -1,    -1,  1614,    -1,
      -1,  1208,    -1,  1210,  1211,    -1,    -1,    -1,  1215,  1216,
      -1,  1218,    -1,  1220,    -1,  1222,  1632,  1224,  1225,  1226,
      -1,    -1,    -1,  1639,    -1,  1641,    -1,  1643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1242,    -1,  1653,    -1,    -1,
      -1,  1657,  1658,  1659,  1660,  1661,    -1,    -1,    -1,   903,
    1257,    -1,    -1,    -1,  1261,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1680,  1681,    -1,    -1,    -1,  1685,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1695,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   953,
     954,   955,   956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
    1736,    -1,    -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,
      -1,    -1,  1748,    -1,    -1,    -1,    -1,   575,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1352,  1762,    -1,    -1,  1765,
      -1,    -1,  1768,    -1,    -1,    -1,  1772,  1011,  1365,    -1,
    1776,    -1,  1778,  1779,  1780,  1781,  1782,    -1,    -1,    -1,
      -1,    -1,    -1,  1789,    -1,    -1,  1792,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,    -1,   627,
     628,   629,   630,   631,   632,   633,    -1,    -1,    -1,   637,
     638,   639,    -1,    -1,    -1,   643,   644,    -1,    -1,    -1,
      -1,   649,   650,   651,    -1,   653,  1832,    21,    22,    -1,
      -1,    -1,   660,   661,  1431,    -1,    -1,    -1,    -1,    -1,
      -1,  1847,    -1,  1849,  1850,  1851,  1852,    -1,    -1,    -1,
     678,  1448,    -1,    -1,    -1,    -1,    -1,    -1,  1455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,
      -1,    -1,  1469,    -1,    -1,    -1,    -1,    -1,    -1,  1885,
    1886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1895,
    1896,  1897,  1898,    -1,    -1,    -1,    -1,    -1,  1495,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,   108,    -1,    -1,   198,    -1,  1516,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,    -1,    -1,  1552,   150,   151,   152,   153,
      -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,  1613,    -1,    -1,  1263,
      -1,     6,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,  1629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,  1648,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,   290,    -1,    -1,    -1,
      -1,    -1,  1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     958,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,  1401,  1402,    -1,
      -1,    -1,    -1,   991,   992,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,     6,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   207,    -1,  1429,    -1,    -1,    -1,  1433,
      -1,    -1,    -1,    -1,  1791,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   417,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     8,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,  1882,    64,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,  1123,    74,    75,    -1,    -1,
      -1,  1129,  1130,  1131,  1132,  1133,     6,    -1,    -1,    -1,
      -1,  1139,  1140,  1557,    -1,  1143,  1144,  1145,    -1,    -1,
      -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1578,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,    -1,  1632,   167,
     168,   169,   170,   171,   172,    -1,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1653,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,    -1,   203,   204,    -1,   206,    -1,
     208,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,  1273,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1297,
      -1,    -1,    -1,    -1,  1302,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     6,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,  1332,  1333,    -1,    -1,  1336,  1337,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,  1776,    -1,  1778,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,  1847,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
    1458,  1459,    -1,    -1,  1462,  1463,    -1,    -1,    -1,    -1,
    1468,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,   159,    -1,    -1,   198,   163,   200,    -1,   202,
     167,   168,   169,   170,   171,     7,     8,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,   933,
     934,    -1,   199,    -1,    -1,   939,   940,   204,    -1,    -1,
     207,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     3,
       4,     5,    -1,   198,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1112,  1113,
      -1,    -1,    -1,  1117,  1118,   159,   160,   161,   162,   163,
       8,    -1,    -1,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,     5,
     204,    -1,   206,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,    -1,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,     3,     4,     5,   204,    -1,
     206,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,    67,
      68,    -1,     3,     4,     5,    -1,    74,    75,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,     8,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,     8,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,   204,    -1,   206,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,   159,   160,
     161,   162,   163,    -1,    -1,   206,   167,   168,   169,   170,
     171,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,     5,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    12,    13,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
      -1,   174,   175,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
       5,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,   207,    -1,
      55,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,     3,     4,     5,   204,
      -1,   206,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,   207,    -1,    55,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,   207,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    -1,    86,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
     159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     3,     4,    -1,   204,    -1,   206,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,   172,    -1,   174,   175,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,    -1,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,   172,    -1,   174,   175,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,     4,
       5,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
      -1,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,   172,    -1,   174,
      55,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,     3,     4,    -1,   204,
      -1,   206,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
       3,     4,     5,    -1,    -1,    74,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,
      -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     159,   198,    -1,    -1,   163,   202,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
      -1,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,     3,     4,    -1,    -1,   199,    -1,     9,    10,
      11,   204,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,     3,     4,    -1,    -1,   199,    -1,
       9,    10,    11,   204,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    66,    67,    68,
      -1,     9,    10,    11,    -1,    74,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    74,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     159,    -1,    -1,   205,   163,   207,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,   200,    -1,    -1,    -1,   204,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,   159,    -1,    -1,   198,   163,    -1,    -1,   202,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,     3,     4,   202,    -1,   204,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    66,    67,    68,    -1,     9,
      10,    11,    -1,    74,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,   207,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,   200,
      -1,    -1,    -1,   204,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,   159,
      -1,    -1,   198,   163,    -1,    -1,   202,   167,   168,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
       3,     4,   202,    -1,   204,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   180,   181,   182,   183,   184,   185,   186,   187,   188,
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
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   202,   180,   181,   182,   183,   184,   185,   186,
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
      -1,    -1,    -1,   198
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
     212,   214,   215,   235,   252,   253,   256,   257,   258,   259,
     260,   261,   262,   263,   284,   285,   286,   287,   305,   306,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    59,    60,    61,    64,    66,
      67,    68,    74,    75,   153,   159,   160,   161,   162,   163,
     167,   168,   169,   170,   171,   172,   174,   189,   190,   194,
     199,   201,   203,   204,   206,   208,   233,   288,   289,   301,
     302,   305,   306,    13,    84,   199,   199,     6,   206,     6,
       6,     6,     6,   199,     6,     6,   201,   201,   199,   201,
     233,   233,   199,   206,   199,   199,     4,   199,   206,   199,
     199,     4,   206,   199,   199,    88,    84,    84,     6,   206,
      78,    81,    84,    84,    84,    81,    84,    86,    86,    78,
      81,    84,    86,    81,    84,    86,    81,    84,   199,    81,
     142,   157,   158,   206,   189,   190,   199,   206,   291,   292,
     291,   206,    78,    81,    84,   206,   291,     4,    78,    82,
      94,    84,    86,    84,    81,     4,   153,   206,   305,   306,
       4,     6,    78,    81,    84,    81,    84,     4,     4,     4,
       4,     5,    37,    78,    81,    84,    86,    98,   190,   199,
     206,   253,   263,   288,   294,   295,   296,   305,   306,     4,
     199,   199,   199,     4,   206,   298,   306,     4,   199,   199,
     199,     6,     6,   201,     4,   302,   306,     4,   302,     5,
     206,     5,   206,     4,   288,   305,   201,     6,   199,   206,
     199,   201,   208,   233,     7,   176,   177,   178,   179,   195,
     196,   231,   232,     4,   199,   201,   203,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   199,   199,   199,   233,   233,   199,   199,   199,
     233,   233,   233,   233,   199,   233,   233,   233,     7,   199,
     199,   199,   233,   233,   199,   199,   201,   288,   288,   288,
     200,   288,   202,   288,     4,   142,   143,   306,     4,   253,
     254,   255,   206,   206,     6,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   198,
     206,     6,   199,   201,   232,     6,   288,     4,   301,   302,
     305,   306,   301,   288,   301,   304,   237,   240,   302,   306,
     288,   190,   288,   296,   297,   288,   288,   199,   288,   297,
     288,   288,   199,   297,   288,   288,   294,   199,   206,   297,
     295,   295,   295,   199,   199,   295,   295,   295,   199,   199,
     199,   199,   199,   199,   199,   199,   206,   206,   288,     4,
     294,   298,   206,   206,   291,   291,   291,   288,   288,   189,
     190,   206,   206,   291,   206,   206,   206,   189,   190,   199,
     255,   291,   206,   199,   206,   199,   199,   199,   295,   295,
     294,   199,     4,   201,   201,   255,     6,     6,   206,   206,
     206,   295,   295,   201,   201,   201,   199,   201,   203,   233,
     201,     5,   145,   206,     5,   145,     5,   145,     5,   145,
      78,    81,    84,    86,   206,   288,   296,   288,   207,   297,
       8,   191,     6,   199,   201,   233,     6,   288,   288,   288,
     203,   288,   206,   145,   288,   288,   288,   288,     6,     6,
       6,   255,     6,   255,   199,   201,   206,   199,   201,   301,
     294,   294,   200,   288,   202,   288,   206,   206,   302,   294,
       6,   201,   288,   288,     4,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   304,   301,   304,
     301,   301,   301,   301,   301,   294,   301,   301,   288,   301,
     301,   301,   304,   301,   288,   302,   288,   301,   301,   301,
     301,   301,   306,   302,   306,     7,   176,   231,   200,     7,
     176,   231,   202,     7,   231,   232,   203,     7,   233,   207,
      78,    81,    84,    86,   252,   288,   297,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   216,   288,   288,     6,   199,   201,   203,   200,
     205,   199,   201,   200,   205,   205,   200,   205,   202,   205,
     236,   202,   236,   205,   205,   200,   191,   205,   207,   200,
     200,   288,   200,   207,   200,   200,   288,   207,   200,   200,
       7,   288,   288,   207,     6,     6,     6,   288,   288,     7,
       7,   281,   281,   288,   246,   288,   302,   247,   288,   302,
     248,   288,   302,   249,   288,   302,   288,   288,   288,   297,
     297,   206,   200,     6,   206,   255,   255,   205,   205,   205,
     291,   291,   254,   254,   205,   288,   288,   288,   288,   267,
     205,   255,   288,   288,   288,   288,   288,     7,   282,     6,
       7,   288,     6,   288,   288,   207,   297,   297,   297,     6,
       6,   288,   288,   288,   288,   288,     4,   200,   202,   206,
     234,   306,    56,   288,    56,    56,    56,     5,   206,     5,
     206,     5,   206,     5,   206,   297,   200,   207,   288,   206,
     288,   296,   288,   288,   206,   234,   200,   200,   200,   142,
     205,   255,   206,     8,   200,   200,   202,   207,   207,   255,
     202,   200,   205,   207,     7,   176,   231,   200,     7,   176,
     231,   202,   288,   297,     6,     6,   288,   200,   202,   232,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   205,   234,   234,   234,   234,   234,   234,   234,   205,
     205,   205,   234,   205,   234,   234,   200,   200,   205,   234,
     234,   205,   205,   205,   205,   234,   234,   234,   200,   234,
     290,   303,     6,   205,   205,   200,   205,   234,   205,   234,
     200,   200,   202,    40,    40,   294,     7,   231,   232,    40,
      40,   294,   203,   231,   232,   302,   288,     6,     4,     4,
     206,   299,   234,   206,   206,   206,   206,   207,   207,     8,
       4,   132,   133,   134,   135,   207,   219,   223,   226,   228,
     229,   200,   202,   288,   288,     4,     6,   187,   213,   297,
     288,   288,     6,   297,   288,     6,   301,     6,   306,     6,
     301,   288,   302,     7,   288,   296,   145,     7,     7,   200,
       7,   145,     7,     7,   200,   145,     7,     7,   288,   200,
     207,   206,   200,   200,   288,   294,     4,   280,     6,   200,
     200,   205,   200,   205,   200,   205,   200,   205,   200,   200,
     200,   207,   207,   297,   203,   255,   207,   207,   291,   288,
     288,   207,   207,   288,   291,   205,   205,   205,   101,   112,
     120,   121,   122,   126,   127,   128,   129,   277,   278,   291,
     207,   264,   200,   207,   200,   200,   200,   288,     6,   288,
     200,   202,   202,   207,   207,   207,   202,   202,   205,   200,
     202,   297,   202,   206,   207,   206,   206,   206,   297,   297,
     297,   297,   207,     8,   297,   200,   202,   297,     7,     7,
       7,   203,   288,   207,   288,   288,     7,   203,   207,   206,
     294,     6,    40,    40,   294,   231,   232,    40,    40,   294,
     231,   232,   207,   207,   202,   232,   203,   232,   301,   288,
     288,   288,   288,   297,   301,   294,   301,   301,   302,   242,
     244,   288,   301,   301,   288,   233,   233,     6,   288,     6,
     233,   233,     6,     4,   142,   143,   288,     6,     6,     6,
       7,   201,   298,   300,     6,   297,   297,   297,   297,   234,
     288,   220,   199,   199,   206,   230,     6,   232,   232,   200,
     202,   187,   301,   200,   200,   202,   200,   205,     7,   234,
     234,   291,    84,    86,   294,   294,     7,   294,    84,    86,
     294,   294,     7,    86,   294,   294,     6,     7,     7,   297,
       7,     7,   101,   279,     6,     7,   231,   288,   231,   288,
     231,   288,   231,   288,     7,     7,     7,     7,     7,   207,
       4,   207,   205,   205,   205,   207,   207,   291,   291,   291,
       4,     6,   206,     6,   199,     6,   130,     6,   130,     6,
     130,     6,   130,   207,   278,   205,   277,     7,     6,     7,
       7,     7,     6,   206,     6,     6,     6,    84,     7,     6,
       6,   288,   203,   207,   288,   288,   288,   288,   207,   207,
     207,   207,   288,   207,   207,   294,   294,   294,     4,   205,
       8,     8,   200,     4,     4,   294,   207,   233,   233,     6,
     288,     6,   233,   233,     6,   288,     6,   234,     6,     4,
       6,   234,   234,   234,   234,   234,   205,   200,   200,   200,
     205,   205,   234,   243,   205,   234,   245,   200,   200,   234,
     234,   234,   304,   304,     6,   234,   304,   304,     7,   231,
     232,   203,     7,     6,   298,   288,   205,   207,   207,   207,
     207,   207,   231,   199,   288,   288,   293,   294,   206,   203,
       6,     6,   213,     6,   288,   206,   288,   302,     6,     6,
       6,   206,   206,    94,   251,   251,   294,     6,   206,   206,
       6,     6,   294,   206,     6,     6,     5,   294,   207,   294,
     294,     4,     6,   294,   294,   294,   294,   294,   294,   294,
     294,   206,   206,     7,     6,     7,   288,   288,   288,   206,
     206,   205,   207,   205,   207,   205,   207,   201,   288,   294,
     288,     6,     6,     6,     6,   288,   291,   207,     5,   206,
     294,   206,   206,   206,   294,   297,   206,   288,   202,     4,
     234,   205,   205,   205,   205,   234,     6,     6,   141,   288,
     288,   288,     6,     6,     7,   205,     6,   234,   304,   304,
       6,   234,   304,   304,     6,   231,   232,   301,   302,     4,
       4,   156,     6,   234,   234,     6,   234,   234,   302,   288,
       6,     4,   299,     6,   202,   298,     6,     6,     6,     6,
     294,   217,   288,   205,   205,   205,   207,   218,   288,     4,
     301,   205,   294,   302,   288,   288,   291,     6,     6,     6,
     288,   288,     6,   288,     5,     6,   206,     6,   145,   250,
     288,     6,     6,     6,     6,     6,     6,     4,     6,     6,
     297,   297,   288,   288,   302,   207,   200,   205,   207,   254,
     254,   291,     6,   268,   291,     6,   269,   291,     6,   270,
     288,   207,   205,   200,   207,   205,     6,   190,   291,     6,
     293,   291,   291,     6,   207,   288,     6,     6,   288,   288,
     288,   288,   294,   205,   207,     8,   207,   200,   206,   288,
     302,   294,     6,   234,   234,     6,   234,   234,   294,   200,
     234,   206,   294,   302,   206,   288,   302,   302,     6,     6,
       6,     6,     6,     6,     7,     6,   203,     6,   200,   205,
     288,   288,   294,   206,   205,   207,     6,   288,   238,   239,
     207,   207,   207,   207,   207,     5,   293,    82,     6,   206,
     207,   207,   206,     6,     6,   206,   288,   207,   207,   205,
     206,   205,   206,   205,   206,   202,     6,   294,     7,   206,
     288,   205,   207,   205,   205,     6,   207,   205,   205,   205,
     205,   140,   288,   288,   297,     6,     6,   207,     6,     6,
       6,     6,     6,   241,   288,   304,   298,   143,   221,   288,
     205,   205,   293,   288,     6,   205,   242,   244,     6,     6,
       6,     6,     6,     6,   207,   206,   293,   105,   106,   111,
     283,   105,   106,   283,   297,   254,   205,   207,   288,   291,
     277,   288,   291,   277,   288,   291,   277,     6,   205,   207,
     294,   255,   207,   291,     6,   297,   291,   288,   288,   288,
     288,   288,   207,   207,   207,     6,   205,   207,     7,   207,
       6,   206,   288,   288,   207,   288,   207,   207,   206,   288,
     207,   206,   291,   294,     6,   206,   291,     6,   207,   207,
     288,   207,   205,   207,   207,   205,   207,   207,   205,   207,
     294,     6,   101,   207,   265,   206,   205,   207,   205,   205,
     205,   205,   205,     6,     6,   288,   302,   218,   200,   205,
       6,   206,   205,   288,   207,     6,   291,     6,   291,     6,
       6,   207,     6,   271,   288,     6,     6,   272,   288,     6,
       6,   273,   288,     6,   207,   288,   277,   255,   297,     6,
     291,   297,   288,   288,   288,   288,     7,   207,   224,   288,
     293,   288,   205,   205,   205,   206,   207,   206,   207,   206,
     207,     6,     6,   207,   207,   266,   207,   205,   207,   205,
     205,   205,   205,   302,     6,   206,   200,   207,   207,   288,
     291,   291,   277,     6,   274,   277,     6,   275,   277,     6,
     276,   277,     6,   297,     6,   288,   288,   288,   288,   222,
     301,   227,   206,     6,   207,   205,   205,   207,   206,   207,
     206,   207,   206,   207,   207,   205,   205,   205,   205,   205,
     207,   206,   293,     6,   288,   288,     6,   277,     6,   277,
       6,   277,     6,   288,   288,   288,   288,   301,     6,   225,
     301,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   205,   207,     6,     6,     6,     6,     6,     6,   301,
       6
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
     235,   236,   236,   237,   237,   237,   238,   237,   237,   239,
     237,   240,   240,   241,   241,   242,   242,   243,   243,   243,
     244,   244,   245,   245,   245,   245,   246,   246,   246,   247,
     247,   247,   248,   248,   248,   249,   249,   249,   250,   250,
     251,   251,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   257,   257,   257,   257,
     257,   258,   258,   259,   260,   260,   260,   260,   260,   260,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   263,   263,   263,   264,   263,   265,   263,
     266,   263,   267,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   268,   263,   269,   263,   270,   263,   271,
     263,   272,   263,   273,   263,   274,   263,   275,   263,   276,
     263,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   285,   285,   285,   286,   286,   286,
     287,   287,   287,   287,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   290,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   291,   291,   291,   291,   291,   292,   292,
     292,   292,   293,   293,   294,   294,   294,   294,   294,   294,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   297,   297,   297,   298,   298,   298,   298,   299,   299,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   303,   302,   304,   304,   305,   305,
     306,   306,   306
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
       9,     0,     1,     0,     3,     5,     0,     9,     5,     0,
       9,     0,     3,     3,     5,     0,     2,     3,     5,     3,
       0,     2,     3,     3,     3,     5,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     3,     0,     5,
       0,     2,     7,     8,     6,     7,     4,     7,     8,     8,
       7,     7,    11,     8,     8,     8,     8,     9,     3,     4,
      10,     7,     7,     8,     8,    12,     8,     8,     7,     8,
       8,     5,    11,     5,     9,     9,     4,     9,     9,     1,
       1,     0,     2,     6,     6,     6,     6,     8,    10,    14,
      16,    12,     8,     8,     6,    14,     4,     6,     6,     3,
       4,     5,     6,     5,     3,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     2,     2,    16,     6,
       8,     8,    10,     1,     2,     2,     1,     3,     3,     4,
       4,     1,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     8,     8,     8,    12,    12,    12,
      14,    14,    14,     0,    12,     0,    12,     0,    12,     0,
      16,     0,    16,     0,    16,     0,    18,     0,    18,     0,
      18,     1,     2,     5,     7,     9,     2,     2,     2,     3,
       2,     3,     2,     3,     2,     3,     9,     6,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     7,     6,
       8,     5,     3,     8,     5,     4,     6,    11,    11,    18,
      18,    12,    12,    12,    10,    10,    10,    10,    10,     4,
       4,     4,     4,     4,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     4,
       6,     1,     4,     4,     4,     4,     4,     4,     4,     2,
       5,     5,     5,     5,     3,     6,     4,     7,     6,     6,
       6,     6,     4,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     1,     2,     3,     3,     5,     4,     2,     2,     2,
       2,     3,     3,     3,     3,     5,     5,     5,     5,    16,
      16,    16,    16,     1,     1,     3,     3,     4,     6,     6,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     4,     4,     3,     6,
       1,     4,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     4,     6,
       4,     1,     4,     4,     0,     6,     1,     3,     5,     5,
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
#line 199 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4716 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4786 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4804 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4821 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4838 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4865 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4883 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4900 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4917 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 377 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 393 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4970 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5078 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5092 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 519 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 528 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 535 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5124 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 570 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5169 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 588 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5191 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5211 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 642 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5290 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 674 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 679 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5333 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5399 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5418 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5451 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 822 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 827 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 832 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 837 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 842 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5531 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 849 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5542 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5575 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 917 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 927 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 932 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 940 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 949 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 955 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5672 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5688 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5704 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5722 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1019 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1025 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5758 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5774 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5790 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5808 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1089 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1095 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5846 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5868 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5890 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5903 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1161 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5934 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5958 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5982 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5997 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6009 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6035 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6062 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6092 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6114 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6130 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6146 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6159 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1376 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1378 "Gmsh.y" /* yacc.c:1646  */
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
#line 6198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1394 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1403 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1405 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1419 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1427 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1433 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1445 "Gmsh.y" /* yacc.c:1646  */
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
#line 6275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1456 "Gmsh.y" /* yacc.c:1646  */
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
#line 6293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1471 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1487 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1495 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1504 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1512 "Gmsh.y" /* yacc.c:1646  */
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
#line 6356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1530 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6364 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1534 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1540 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1548 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1552 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1558 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1566 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1570 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1576 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1584 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1588 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1594 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6464 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1602 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1606 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1618 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1622 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1632 "Gmsh.y" /* yacc.c:1646  */
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
#line 6529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1655 "Gmsh.y" /* yacc.c:1646  */
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
#line 6576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1698 "Gmsh.y" /* yacc.c:1646  */
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
#line 6600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1721 "Gmsh.y" /* yacc.c:1646  */
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
#line 6622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1739 "Gmsh.y" /* yacc.c:1646  */
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
#line 6647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1760 "Gmsh.y" /* yacc.c:1646  */
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
#line 6669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1778 "Gmsh.y" /* yacc.c:1646  */
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
#line 6703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1808 "Gmsh.y" /* yacc.c:1646  */
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
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1838 "Gmsh.y" /* yacc.c:1646  */
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
#line 6759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1856 "Gmsh.y" /* yacc.c:1646  */
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
#line 6781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1875 "Gmsh.y" /* yacc.c:1646  */
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
#line 6811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1901 "Gmsh.y" /* yacc.c:1646  */
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
#line 6833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1919 "Gmsh.y" /* yacc.c:1646  */
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
#line 6855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1937 "Gmsh.y" /* yacc.c:1646  */
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
#line 6902 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1983 "Gmsh.y" /* yacc.c:1646  */
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
#line 6924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2001 "Gmsh.y" /* yacc.c:1646  */
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
#line 6967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2040 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2046 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2052 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6998 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2059 "Gmsh.y" /* yacc.c:1646  */
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
#line 7027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2084 "Gmsh.y" /* yacc.c:1646  */
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
#line 7056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2109 "Gmsh.y" /* yacc.c:1646  */
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
#line 7077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2126 "Gmsh.y" /* yacc.c:1646  */
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
#line 7100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2146 "Gmsh.y" /* yacc.c:1646  */
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
#line 7137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2179 "Gmsh.y" /* yacc.c:1646  */
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
#line 7184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2226 "Gmsh.y" /* yacc.c:1646  */
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
#line 7206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2244 "Gmsh.y" /* yacc.c:1646  */
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
#line 7227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2261 "Gmsh.y" /* yacc.c:1646  */
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
#line 7247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2277 "Gmsh.y" /* yacc.c:1646  */
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
#line 7294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2325 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2330 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2335 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2340 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2345 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2350 "Gmsh.y" /* yacc.c:1646  */
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
#line 7366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2379 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2389 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2390 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2395 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2399 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7416 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2403 "Gmsh.y" /* yacc.c:1646  */
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
#line 7443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2426 "Gmsh.y" /* yacc.c:1646  */
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
#line 7470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2449 "Gmsh.y" /* yacc.c:1646  */
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
#line 7497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2472 "Gmsh.y" /* yacc.c:1646  */
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
#line 7524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2500 "Gmsh.y" /* yacc.c:1646  */
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
#line 7549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2521 "Gmsh.y" /* yacc.c:1646  */
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
#line 7579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2548 "Gmsh.y" /* yacc.c:1646  */
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
#line 7603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2569 "Gmsh.y" /* yacc.c:1646  */
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
#line 7628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2590 "Gmsh.y" /* yacc.c:1646  */
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
#line 7652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2610 "Gmsh.y" /* yacc.c:1646  */
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
#line 7768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2722 "Gmsh.y" /* yacc.c:1646  */
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
#line 7791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2741 "Gmsh.y" /* yacc.c:1646  */
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
#line 7833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2780 "Gmsh.y" /* yacc.c:1646  */
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
#line 7940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2888 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2897 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2903 "Gmsh.y" /* yacc.c:1646  */
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
#line 7982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2918 "Gmsh.y" /* yacc.c:1646  */
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
#line 8014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2946 "Gmsh.y" /* yacc.c:1646  */
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
#line 8030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2963 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8043 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2972 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2986 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 3000 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 3012 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 3021 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3030 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3039 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3053 "Gmsh.y" /* yacc.c:1646  */
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
#line 8204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3112 "Gmsh.y" /* yacc.c:1646  */
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
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3130 "Gmsh.y" /* yacc.c:1646  */
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
#line 8247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3147 "Gmsh.y" /* yacc.c:1646  */
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
#line 8266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3162 "Gmsh.y" /* yacc.c:1646  */
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
#line 8296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3188 "Gmsh.y" /* yacc.c:1646  */
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
#line 8312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3200 "Gmsh.y" /* yacc.c:1646  */
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
#line 8340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3228 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3233 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3240 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3245 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3251 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3256 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3262 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3270 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3274 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3278 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3284 "Gmsh.y" /* yacc.c:1646  */
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
#line 8501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3343 "Gmsh.y" /* yacc.c:1646  */
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
#line 8522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
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
#line 8543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3377 "Gmsh.y" /* yacc.c:1646  */
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
#line 8569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3399 "Gmsh.y" /* yacc.c:1646  */
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
#line 8595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3421 "Gmsh.y" /* yacc.c:1646  */
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
#line 8634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3456 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3464 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3478 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3485 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3492 "Gmsh.y" /* yacc.c:1646  */
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
#line 8714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3512 "Gmsh.y" /* yacc.c:1646  */
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
#line 8744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3538 "Gmsh.y" /* yacc.c:1646  */
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
#line 8760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3550 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3562 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3570 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3578 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8816 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3592 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3600 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3606 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3620 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8872 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3628 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3634 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3642 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3656 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3670 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8959 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3684 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3698 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3705 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9002 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3718 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3724 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3731 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9044 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3737 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9055 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3744 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3750 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3757 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9086 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3763 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3770 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3783 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3789 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9139 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3796 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3802 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3809 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3815 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3826 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3829 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9195 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3835 "Gmsh.y" /* yacc.c:1646  */
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
#line 9211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3847 "Gmsh.y" /* yacc.c:1646  */
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
#line 9235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3867 "Gmsh.y" /* yacc.c:1646  */
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
#line 9262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3891 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3895 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3899 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3903 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3907 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3913 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3919 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3923 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3927 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3931 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3935 "Gmsh.y" /* yacc.c:1646  */
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
#line 9369 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3954 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9381 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3966 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3970 "Gmsh.y" /* yacc.c:1646  */
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
#line 9406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3985 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3989 "Gmsh.y" /* yacc.c:1646  */
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
#line 9432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4005 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4009 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4014 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4018 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9464 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4024 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4028 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4035 "Gmsh.y" /* yacc.c:1646  */
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
#line 9540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4091 "Gmsh.y" /* yacc.c:1646  */
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
#line 9614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4161 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4166 "Gmsh.y" /* yacc.c:1646  */
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
#line 9694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4233 "Gmsh.y" /* yacc.c:1646  */
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
#line 9734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4269 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4277 "Gmsh.y" /* yacc.c:1646  */
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
#line 9793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4320 "Gmsh.y" /* yacc.c:1646  */
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
#line 9836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4359 "Gmsh.y" /* yacc.c:1646  */
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
#line 9860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4380 "Gmsh.y" /* yacc.c:1646  */
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
#line 9895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4412 "Gmsh.y" /* yacc.c:1646  */
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
#line 9925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4439 "Gmsh.y" /* yacc.c:1646  */
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
#line 9954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4465 "Gmsh.y" /* yacc.c:1646  */
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
#line 9983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4491 "Gmsh.y" /* yacc.c:1646  */
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
#line 10012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4517 "Gmsh.y" /* yacc.c:1646  */
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
#line 10041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4543 "Gmsh.y" /* yacc.c:1646  */
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
#line 10066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4564 "Gmsh.y" /* yacc.c:1646  */
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
#line 10098 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4592 "Gmsh.y" /* yacc.c:1646  */
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
#line 10130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10146 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
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
#line 10178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4656 "Gmsh.y" /* yacc.c:1646  */
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
#line 10221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4695 "Gmsh.y" /* yacc.c:1646  */
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
#line 10264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4734 "Gmsh.y" /* yacc.c:1646  */
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
#line 10289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4755 "Gmsh.y" /* yacc.c:1646  */
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
#line 10314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
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
#line 10339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4803 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4807 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4817 "Gmsh.y" /* yacc.c:1646  */
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
#line 10395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4851 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4852 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4853 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4858 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4864 "Gmsh.y" /* yacc.c:1646  */
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
#line 10439 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4876 "Gmsh.y" /* yacc.c:1646  */
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
#line 10461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4894 "Gmsh.y" /* yacc.c:1646  */
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
#line 10488 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4922 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10500 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4923 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10506 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4924 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10518 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4926 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4927 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10530 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4928 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10536 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4930 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10547 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4937 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4938 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4939 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4940 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4941 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4942 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10589 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4943 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4944 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10601 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4947 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4948 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4949 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4950 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4951 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4952 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4953 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4954 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4955 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10667 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4956 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4957 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4958 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10685 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4959 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4960 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10697 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4961 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4962 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4963 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4964 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4965 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4966 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10733 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4967 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4968 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10745 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4977 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10757 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4979 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4980 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4983 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4984 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4987 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4992 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 5000 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 5010 "Gmsh.y" /* yacc.c:1646  */
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
#line 10866 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5027 "Gmsh.y" /* yacc.c:1646  */
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
#line 10888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5045 "Gmsh.y" /* yacc.c:1646  */
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
#line 10910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5063 "Gmsh.y" /* yacc.c:1646  */
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
#line 10932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5081 "Gmsh.y" /* yacc.c:1646  */
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
#line 10954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5099 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5104 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5110 "Gmsh.y" /* yacc.c:1646  */
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
#line 10992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5125 "Gmsh.y" /* yacc.c:1646  */
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
#line 11013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5142 "Gmsh.y" /* yacc.c:1646  */
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
#line 11035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5160 "Gmsh.y" /* yacc.c:1646  */
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
#line 11057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5178 "Gmsh.y" /* yacc.c:1646  */
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
#line 11079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5196 "Gmsh.y" /* yacc.c:1646  */
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
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5217 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5222 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5227 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5237 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5247 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5252 "Gmsh.y" /* yacc.c:1646  */
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
#line 11171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5263 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5272 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5277 "Gmsh.y" /* yacc.c:1646  */
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
#line 11221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5304 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5308 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5312 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5316 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11253 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5320 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11261 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5327 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5335 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5346 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5351 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5358 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5363 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5367 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5372 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5376 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5384 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5395 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5399 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5411 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5419 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5427 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5434 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5444 "Gmsh.y" /* yacc.c:1646  */
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
#line 11471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5473 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5477 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5481 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5489 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5493 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5497 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11527 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5505 "Gmsh.y" /* yacc.c:1646  */
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
#line 11568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5534 "Gmsh.y" /* yacc.c:1646  */
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
#line 11601 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5563 "Gmsh.y" /* yacc.c:1646  */
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
#line 11634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5592 "Gmsh.y" /* yacc.c:1646  */
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
#line 11667 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5622 "Gmsh.y" /* yacc.c:1646  */
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
#line 11683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5635 "Gmsh.y" /* yacc.c:1646  */
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
#line 11699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5648 "Gmsh.y" /* yacc.c:1646  */
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
#line 11715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5661 "Gmsh.y" /* yacc.c:1646  */
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
#line 11731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5673 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11745 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5683 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5693 "Gmsh.y" /* yacc.c:1646  */
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
#line 11775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5705 "Gmsh.y" /* yacc.c:1646  */
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
#line 11791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5718 "Gmsh.y" /* yacc.c:1646  */
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
#line 11807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5730 "Gmsh.y" /* yacc.c:1646  */
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
#line 11829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5748 "Gmsh.y" /* yacc.c:1646  */
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
#line 11851 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5769 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5774 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5778 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5782 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5794 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5798 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5810 "Gmsh.y" /* yacc.c:1646  */
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
#line 11926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5827 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5837 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5841 "Gmsh.y" /* yacc.c:1646  */
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
#line 11961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5856 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5861 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5868 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5872 "Gmsh.y" /* yacc.c:1646  */
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
#line 12003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5885 "Gmsh.y" /* yacc.c:1646  */
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
#line 12021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5899 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5902 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5905 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5908 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12054 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5916 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5927 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12074 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5931 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5935 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5943 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12104 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5949 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5955 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5963 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5971 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5978 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5986 "Gmsh.y" /* yacc.c:1646  */
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
#line 12180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 6001 "Gmsh.y" /* yacc.c:1646  */
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
#line 12198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6015 "Gmsh.y" /* yacc.c:1646  */
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
#line 12216 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6029 "Gmsh.y" /* yacc.c:1646  */
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
#line 12232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6041 "Gmsh.y" /* yacc.c:1646  */
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
#line 12252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6057 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6066 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6075 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6085 "Gmsh.y" /* yacc.c:1646  */
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
#line 12307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6096 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6100 "Gmsh.y" /* yacc.c:1646  */
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
#line 12338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6119 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6126 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6132 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12370 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6139 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12381 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6146 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6148 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12399 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6159 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6164 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6170 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6179 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6192 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 6195 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 6199 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12460 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6202 "Gmsh.y" /* yacc.c:1906  */


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
