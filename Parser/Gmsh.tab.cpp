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
#define YYLAST   11528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  543
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1943

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
    3906,  3910,  3916,  3922,  3926,  3930,  3934,  3938,  3957,  3970,
    3973,  3989,  3992,  4009,  4012,  4018,  4021,  4028,  4031,  4038,
    4094,  4164,  4169,  4236,  4272,  4280,  4323,  4362,  4382,  4414,
    4441,  4467,  4493,  4519,  4545,  4567,  4595,  4623,  4627,  4631,
    4659,  4698,  4737,  4758,  4779,  4806,  4810,  4820,  4855,  4856,
    4857,  4861,  4867,  4879,  4897,  4925,  4926,  4927,  4928,  4929,
    4930,  4931,  4932,  4933,  4940,  4941,  4942,  4943,  4944,  4945,
    4946,  4947,  4948,  4949,  4950,  4951,  4952,  4953,  4954,  4955,
    4956,  4957,  4958,  4959,  4960,  4961,  4962,  4963,  4964,  4965,
    4966,  4967,  4968,  4969,  4970,  4971,  4972,  4981,  4982,  4983,
    4984,  4985,  4986,  4987,  4988,  4989,  4990,  4991,  4996,  4995,
    5003,  5008,  5013,  5030,  5048,  5066,  5084,  5102,  5107,  5113,
    5128,  5145,  5163,  5181,  5199,  5220,  5225,  5230,  5240,  5250,
    5255,  5266,  5275,  5280,  5307,  5311,  5315,  5319,  5323,  5330,
    5334,  5338,  5342,  5349,  5354,  5361,  5366,  5370,  5375,  5379,
    5387,  5398,  5402,  5414,  5422,  5430,  5437,  5447,  5476,  5480,
    5484,  5488,  5492,  5496,  5500,  5504,  5508,  5537,  5566,  5595,
    5624,  5637,  5650,  5663,  5676,  5686,  5696,  5708,  5721,  5733,
    5751,  5772,  5777,  5781,  5785,  5797,  5801,  5813,  5830,  5840,
    5844,  5859,  5864,  5871,  5875,  5888,  5902,  5905,  5908,  5911,
    5919,  5930,  5934,  5938,  5946,  5952,  5958,  5966,  5974,  5981,
    5989,  6004,  6018,  6032,  6044,  6060,  6069,  6078,  6088,  6099,
    6103,  6122,  6129,  6135,  6142,  6150,  6149,  6162,  6167,  6173,
    6182,  6195,  6198,  6202
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

#define YYPACT_NINF -1428

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1428)))

#define YYTABLE_NINF -511

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    8065,    26,    23,  8187, -1428, -1428,  4106,    64,   -34,  -153,
    -143,    31,    67,    82,   104,   108,   -67,   135,   141,   -28,
       1,   -46,   -46,  -124,    12,    81,    15,   105,   188,    18,
     239,   245,   178,   246,   320,   157,    66,   371,   397,   406,
     113,   365,   361,   392,   233,   319,   452,   192,   336,   -38,
     -38,   381,   359,    60,   100,   479,   486,     3,    47,   527,
     542,   335,   638,   642,   697,  5578,   704,   510,   516,   522,
      14,    53, -1428,   558,   589, -1428, -1428,   783,   802,   620,
   -1428,  5859,  6250,    34,    37, -1428, -1428, -1428,  7925,   637,
   -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428,
   -1428, -1428, -1428, -1428, -1428, -1428,    54, -1428,   166,   129,
   -1428,     4, -1428, -1428, -1428, -1428, -1428,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   640,   644,   652,   -46,   -46,   658,   663,   666,
     -46,   -46,   -46,   -46,   677, -1428,   -46, -1428, -1428, -1428,
   -1428, -1428,   -46,   -46,   870,   684,   690,   691,   -46,   -46,
     695,   696, -1428, -1428, -1428, -1428,   701,  7925,  7925,  7925,
    7348,  7409,    17,    16,   471,   700,   708,   468, -1428,   709,
     901,   351,  -126,   912,  7925,  6057,  6057, -1428,  7925, -1428,
   -1428, -1428, -1428,  6057, -1428, -1428, -1428, -1428, -1428, -1428,
    6448,    16,  7925,  7156,  7925,  7925,   725,  7925,  7156,  7925,
    7925,   731,  7156,  7925,  7925,  5974,   746,   713, -1428,  7156,
    5578,  5578,  5578,   750,   756,  5578,  5578,  5578,   766,   777,
     778,   781,   786,   793,   797,   803,   730,  1514,   997,  5974,
      14,   742,   752,   -38,   -38,   -38,  7925,  7925,  -179, -1428,
     -82,   -38,   807,   824,   825,  2346,   -32,   -97,   839,   846,
     862,  5578,  5578,  5974,   902,     5,   805, -1428,   858,  1098,
    1099, -1428,   913,   926,   931,  5578,  5578,   911,   919,   940,
     466, -1428,   943,    25,    19,    20,    21,   632,  6172,  7925,
    4514, -1428, -1428,  3555, -1428,  1139, -1428,   472,   -99,  1144,
    7925,  7925,  7925,   -36,  7925,   952, -1428,  1041,  7925,  7925,
    7925, -1428, -1428,  7925,   899,  1164,  1184, -1428, -1428,  1204,
   -1428,  1223, -1428,   214,  5142,   571,  6057, -1428,  5974,  5974,
    7606,  7667,  1027,  1032,  6448, -1428, -1428, -1428, -1428, -1428,
   -1428,  5974,  1236,  1045,  7925,  7925,  1243,  7925,  7925,  7925,
    7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,
    7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  6057,
    6057,  6057,  6057,  6057,  6057,  6057,  6057,  5974,  6057,  6057,
    7925,  6057,  6057,  6057,  6057,  6057,  7925,  6448,  7925,  6057,
    6057,  6057,  6057,  6057,    16,  6448,    16,  1050,  1050,  1050,
      99, 10448,   122,  7373,   133,  1051,  1246,   -46,  1052, -1428,
    1053,  3319,  7925,  7156, -1428,  7925,  7925,  7925,  7925,  7925,
    7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,  7925,
   -1428, -1428,  7925,  7925, -1428, -1428,   501,   288,    79, -1428,
     576, -1428,   248,  8907, -1428,   325,   395,   493,  1057,  1058,
   10469,  7156,  3699, -1428,   357, 10490, 10511,  7925, 10532,   413,
   10553, 10574,  7925,   541, 10595, 10616,  1250,  7925,  7925,   556,
    1258,  1261,  1262,  7925,  7925,  1265,  1266,  1266,  7925,  6964,
    6964,  6964,  6964,  7925,  7925,  7925,  7156,  7156,  8827,  1069,
    1268,  1070, -1428, -1428,   205, -1428, -1428,  8933,  8959,   -38,
     -38,   471,   471,   290,  7925,  7925,  7925,  2346,  2346,  7925,
    3319,   327, -1428,  7925,  7925,  7925,  7925,  7925,  1270,  1269,
    1271,  7925,  1273,  7925,  7925,  2506, -1428, -1428,  7156,  7156,
    7156,  1275,  1291,  7925,  7925,  7925,  7925,  7925,  1294,    88,
      16, -1428,  1247,  7925, -1428,  1248, -1428,  1249, -1428,  1254,
      38,    42,    43,    44,  7156,  1050, -1428, 10637, -1428,   600,
    7925,  6370, -1428,  7925,  7925,   654, -1428, 10658, 10679, 10700,
    1160,  8985, -1428,  1105,  3799, 10721, 10742,  7631, -1428, -1428,
   -1428,  2772, -1428,  3123,  7925,  7925, -1428,  7925,  7925,  1110,
    1113,   617,   164, 10763,   168, 10103,  7925,  7156,  1309,  1310,
   -1428,  7925, 10784, 10126,   -91,  4452,  4452,  4452,  4452,  4452,
    4452,  4452,  4452,  4452,  4452,  4452,  9011,  4452,  4452,  4452,
    4452,  4452,  4452,  4452,  9037,  9063,  9089,   329,   664,   329,
    1126,  1127,  1128,   668,   668,  1129,  1130,  1131,  9115,   668,
     668,   668,   355,   668, 11330, -1428,   545,  1135,  1136,  1143,
     711,   720,  1145,  1146,  1147,  1288,  1307,  5974,   143,  1308,
    1311,  5974,    78,  6448,  7925,  1346,  1350,    24,   668, -1428,
     169,    36,    30,   203, -1428,  5276,   627,  3819,   446,  1101,
     831,   831,   655,   655,   655,   655,   689,   689,  1050,  1050,
    1050,  1050,    11, 10805, 10149, -1428,  7925,  7925,  1352,    80,
    7156,  7925,  7925,  1351,  7156,  7925,  1353,  6057,  1355, -1428,
      16,  1356,  6057,  7925,  6448,  1358,  7156,  7156,  1221,  1360,
    1361, 10826,  1362,  1226,  1379,  1382, 10847,  1251,  1384,  1385,
    7925, 10868,  6506,  1187, -1428, -1428, -1428, 10889, 10910,  7925,
    5974,  1390,  1389, 10931,  1197, 11330,  1193,  1201, 11330,  1198,
    1202, 11330,  1199,  1205, 11330,  1206, 10952, 10973, 10994,   681,
     737,  7156,  1203, -1428, -1428,  3156,  3595,   -38,  7925,  7925,
   -1428, -1428,  1207,  1209,  2346,  9141,  9167,  9193,  8881,  1123,
     -38,  3691, 11015,  6704, 11036, 11057, 11078,  7925,  1404, -1428,
    7925, 11099, -1428, 10172, 10195, -1428,   749,   759,   763, -1428,
   -1428, 10218, 10241,  9219, 11120, 10264,   -99, -1428, -1428,  7156,
   -1428,  1210,  1211,  6860,  1214,  1215,  1216, -1428,  7156, -1428,
    7156, -1428,  7156, -1428,  7156,   764, -1428, -1428,  3897,  7156,
    1050, -1428, 11141, 10287,  7156, -1428,  1406,  1418,  1419,  1224,
    7925,  3839,  7925,  7925, -1428, -1428,    58, -1428, -1428,  4363,
   -1428,  1225,  5974,  1423,  1393,  1394,  5974,   143,  1395,  1396,
    5974,   143,  6888,   767, -1428, -1428, 10310,    90,  1278, -1428,
   -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428,
   -1428,  7925, -1428, -1428, -1428, -1428, -1428, -1428, -1428,  7925,
    7925,  7925, -1428,  7156, -1428, -1428, -1428, -1428,  6057, -1428,
   -1428,  5974,  6057,  6057,  6448, -1428, -1428, -1428, -1428, -1428,
   -1428, -1428, -1428,  7925,  6057, -1428,  6057, -1428,  7925, -1428,
   -1428, -1428, -1428,   -46,   -46,  1435, -1428,  7925,  1436,   -46,
     -46,  1439,    40,  7925,  1440,  1443,   611, -1428,  1444,  1255,
      14,  1451, -1428,  7156,  7156,  7156,  7156, -1428,   668,  7925,
   -1428,  1260,  1263,  1257, -1428,  1454, -1428, -1428, -1428, -1428,
   -1428,    96,   131, 11162, 10333, -1428, -1428,  1274,  6057,   414,
   11183, 10356, -1428,   578,  9245, -1428, -1428, -1428,  1458, -1428,
   -1428,  4452,   668,   -38,  3699, -1428,   900,  5974,  5974,  1459,
    5974,   907,  5974,  5974,  1462,  1386,  5974,  5974,   867,  1463,
    1464,  7156,  1468,  1469,  3528, -1428, -1428,  1471, -1428,  1475,
     306,  7925,   306,  7925,   306,  7925,   306,  7925,  1478,  1479,
    1480,  1481,  1482,   800,  1474,  4577, -1428, -1428,   338,  9271,
    9297, -1428, -1428,  6921,  -106,   -38,   -38,   -38,  1476,  7864,
    1284,  1485,  1293,    32,    46,    55,    57,    -9, -1428,   364,
   -1428,  1123,  1486,  1489,  1490,  1491,  1492, 11330, -1428,   892,
    1290,  1494,  1495,  1496,  1420,  1499,  1497,  1501,  7925,   -99,
     388,   804, -1428,  7925, -1428,  7925,  7925,  7925,   820,   832,
     857,   864, -1428,  7925,   886,   -99,   -99,   887,  5974,  5974,
    5974,  1504,  9323, -1428,  4034,   171,  1505,  1506, -1428,  5974,
    1304, -1428,   -46,   -46,  1508,  7925,  1510,   -46,   -46,  1513,
    7925,  1520, -1428,   668,  1546, -1428,  1549, -1428,  1548,  4452,
    4452,  4452,  4452,   726,  1354,  1312,  1357,  1366,  1363,   735,
     741, 11204,  1367,   668,  4452,  1798,  6057, -1428,  1192, -1428,
    1798,  6057, -1428,   563,  1368,  1551,  1452, -1428, -1428, -1428,
      14,  7925, -1428,   906, -1428,   920,   921,   924,   928,   306,
   11330,  1371,  7925,  7925,  5974,  1349, -1428, -1428, -1428, -1428,
    1369, -1428,  1554,    84, -1428, -1428,  1555,  7925,  5115,  1568,
    1569,     6,  1370,  1372,  1498,  1498,  5974,  1573,  1377,  1378,
    1579,  1580,  5974,  1381,  1583,  1585, -1428,  1590,  5974,   933,
    5974,  5974,  1592,  1591, -1428,  5974,  5974, 11330,  5974, 11330,
    5974, 11330,  5974, 11330,  5974,  5974,  5974,  1392,  1398,  1593,
     366, -1428,  7925,  7925,  7925,  1400,  1401,  -131,  -118,   -68,
    1407, -1428,  1473,  5974, -1428,  7925, -1428,  1595, -1428,  1596,
   -1428,  1603, -1428,  1604, -1428, -1428,  2346,   861,  5776, -1428,
    1405,  1410,  6568, -1428,  7156, -1428, -1428, -1428,  1417,  7925,
   -1428, -1428, 10379,  1620,   668,  9349,  9375,  9401,  9427, -1428,
   -1428, -1428, -1428, 11330, -1428,   668,  1619,  1621,  1488, -1428,
    7925,  7925,  7925, -1428,  1624,   491,  1421,  1642,  1798,  6057,
   -1428,  1559, -1428,  1798,  6057, -1428,  1703, -1428,   306, -1428,
     212, -1428, -1428, -1428, -1428, -1428, -1428,  6057, -1428, -1428,
   -1428,  6448,  1645, -1428, -1428,    13, -1428, -1428, -1428, -1428,
   -1428, -1428,  1662,   329,   329, -1428,  1663,   329,   329,  6448,
    7925,  1666,  1647,    24, -1428,  1668, 10402,    14, -1428,  1669,
    1670,  1673,  1674,  5974,  7925,  9453,  9479,   944, -1428,  7925,
    1686, -1428, -1428,  6057, -1428,  9505,  4719, 11330, -1428, -1428,
   -1428, -1428,  7925,  7925,   -38,  1685,  1690,  1691, -1428,  7925,
    7925, -1428, -1428,  1693,  7925, -1428, -1428,  1594,  1695,  1500,
    1696,  1560,  7925, -1428,  1701,  1704,  1705,  1706,  1708,  1709,
    1149,  1713,  7156,  7156,  7925, -1428,  6964,  7094, 11225,  3407,
     471,   471,   -38,  1715,   -38,  1716,   -38,  1717,  7925, -1428,
     243,  1519, 11246, -1428, -1428, -1428, -1428,  7305,   367, -1428,
    1719,  4315,  1721,  5974,   -38,  4315,  1722,   949,  7925,  1993,
    1723,   -99, -1428,  7925,  7925,  7925,  7925, -1428, -1428, -1428,
    5974,  4657,   279, 11267, -1428, -1428,  5182,  5974, -1428,  1724,
     329,   329, -1428,  1725,   329,   329, -1428,  5974, -1428,  1532,
     668,  4917,  5380,  6448, -1428,  1727,  1729, -1428,  1731,  1732,
    1747,  2123, -1428,  1751,  1748, -1428,  1556, -1428, -1428, -1428,
   -1428, -1428,  1755,   582, 11330,  7925,  7925,  5974,  1557,   954,
   11330, -1428,  1756,  7925, -1428, -1428,  7563,  7821,   487, -1428,
   -1428, -1428,  8183,  8211, -1428,  8239,  1759, -1428,  5974, -1428,
    1683,  1760, 11330, -1428, -1428, -1428, -1428, -1428, -1428,  1561,
   -1428, -1428,   957,   958,  8854,  2514,  1762,  1563, -1428,  7925,
   -1428,  1565,  1575,   384, -1428,  1564,   417, -1428,  1577,   435,
   -1428,  1578, 10425,  1785,  5974,  1787,  1586,  7925, -1428,  6766,
     473, -1428,   961,   507,   515, -1428,  1789,  8267, -1428, -1428,
    9531,  9557,  9583,  9609,  1658,  7925, -1428,  7925, -1428, -1428,
    7156,  2538,  1793,  1597, -1428,  1794,  1795, -1428,  1799,  1800,
    1801, -1428, -1428,  4514, -1428, -1428,  6057, 11330, -1428, -1428,
   -1428, -1428, -1428, -1428, -1428, -1428,    14, -1428,  1665, -1428,
   -1428,  7925,  9635,  9661, -1428,  5974,  7925,  1803, -1428,  9687,
   -1428, -1428,  1804,  1805,  1806,  1807,  1808,  1809,   962,  1611,
   -1428,  5974,    22,   475,  7156, -1428, -1428,   471,  4855, -1428,
   -1428,  2346,  1123,  2346,  1123,  2346,  1123,  1812, -1428,   968,
    5974, -1428,  8295,   -38,  1827,  7156,   -38, -1428, -1428,  7925,
    7925,  7925,  7925,  7925,  8323,  8351,   969, -1428, -1428,  1828,
   -1428, -1428, -1428, -1428, -1428,   972,  3088,   973,  1829, -1428,
    1630, 11330,  7925,  7925,   977, 11330, -1428,  7925,   984,   989,
   -1428, -1428, -1428, -1428, -1428, -1428,  1641,  7925,   995,  1649,
     -38,  5974,  1842,  1650,   -38,  1847,   996,  1653,  7925, -1428,
    8379,   555,   914,  8407,   560,   988,  8435,   562,  1493, -1428,
    5974,  1855,  1763,  5424,  1657,   564, -1428,   999,   566,  9713,
    9739,  9765,  9791,  2576, -1428, -1428,  1859, -1428,  7925, -1428,
    6448, -1428, -1428,  7925, 11288,  9817,    35,  9843, -1428, -1428,
    7925,  8463,  1861,   -38,    73, -1428, -1428,   -38,    75, -1428,
    1862, -1428,  8491,  1863,  7925,  1864,  1865,  7925,  1866,  1869,
    7925,  1870,  1667, -1428,  7925, -1428,  1123, -1428,  7156,  1872,
    6766,  7925,  7925,  7925,  7925, -1428, -1428,  1639, -1428,  1004,
   -1428,  7925, -1428,  5974,  7925,  9869, -1428, -1428,   621, -1428,
     623, -1428, -1428, -1428, -1428,  1676,  8519, -1428, -1428,  1697,
    8547, -1428, -1428,  1698,  8575, -1428,  1873,  2765,  1566,  5622,
    1009, -1428,   625,  1013,  9895,  9921,  9947,  9973,  6448,  1874,
    1707, 11309,  1020,  8603,  7925,   -38,   -38,  1123,  1891,  1123,
    1893,  1123,  1896, -1428, -1428, -1428, -1428,  1123,  1904,  7156,
    1905,  7925,  7925,  7925,  7925, -1428, -1428,  6057, -1428,  1710,
    1906,  8631,   628,   630,  1659, -1428,  1711,  1868, -1428,  1712,
    2216, -1428,  1714,  2304, -1428,  1021, -1428,  9999, 10025, 10051,
   10077,  1025, -1428,  1718,  5974, -1428,  1908,  7925,  7925,  1909,
    1123,  1913,  1123,  1915,  1123, -1428,  1917,  7925,  7925,  7925,
    7925,  6057,  1919,  6057,  1029, -1428,  8659,  8687, -1428,  2336,
   -1428,  2358, -1428,  2696, -1428,  8715,  8743,  8771,  8799, -1428,
   -1428,  1034, -1428,  1921,  1922,  1923,  1925,  1926,  1928, -1428,
   -1428, -1428, -1428,  6057,  1929, -1428, -1428, -1428, -1428, -1428,
   -1428, -1428, -1428
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   541,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,   261,   262,     0,     0,     0,
     256,     0,     0,     0,     0,   358,   359,   360,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   542,     0,
     407,   541,   511,   408,   410,   411,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,     0,   532,   515,   415,
     416,   417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   412,   413,   414,   514,     0,     0,     0,     0,
      66,    67,     0,     0,   201,     0,     0,     0,   365,     0,
     503,   542,   422,     0,     0,     0,     0,   241,     0,   243,
     244,   239,   240,     0,   245,   246,   123,   131,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   444,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   541,     0,   201,   542,     0,
       0,   355,     0,     0,     0,     0,     0,     0,     0,     0,
     541,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,   485,   455,   461,     0,   456,   542,   422,     0,
       0,     0,     0,   541,     0,     0,   497,     0,     0,     0,
       0,   237,   238,     0,   541,     0,     0,   254,   255,     0,
     201,     0,   201,   541,     0,   542,     0,   361,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   368,   367,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,   199,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   230,     0,     0,   430,   178,     0,   541,     0,   503,
     542,   504,     0,     0,   537,     0,   121,   121,     0,     0,
       0,     0,   491,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   323,   323,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,   201,     0,   446,   445,     0,     0,     0,
       0,   201,   201,     0,     0,     0,     0,     0,     0,     0,
     272,     0,   201,     0,     0,     0,     0,     0,   325,     0,
       0,     0,     0,     0,     0,     0,   219,   356,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,   468,     0,     0,   469,     0,   470,     0,   471,     0,
       0,     0,     0,     0,     0,   367,   463,     0,   457,     0,
       0,     0,   333,    66,    67,     0,   236,     0,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,   258,   257,
     224,     0,   225,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   418,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,   366,    59,
      60,     0,     0,    59,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,   202,     0,     0,     0,   383,   382,
     380,   381,   376,   378,   377,   379,   371,   370,   372,   373,
     374,   375,     0,     0,     0,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   352,   353,   354,     0,     0,     0,
       0,   321,     0,     0,     0,   146,   147,     0,   149,   150,
       0,   152,   153,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,   166,   201,     0,     0,     0,     0,     0,
     448,   447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,   220,     0,     0,   216,     0,     0,     0,   351,
     350,     0,     0,     0,     0,     0,   435,    68,    69,     0,
     486,     0,     0,     0,     0,     0,     0,   472,     0,   473,
       0,   474,     0,   475,     0,     0,   366,   458,   465,     0,
     372,   464,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   260,     0,   226,   228,     0,
     543,     0,     0,     0,    59,    60,     0,     0,    59,    60,
       0,     0,     0,     0,    90,    74,     0,   424,   423,   437,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   406,
     394,     0,   396,   397,   398,   399,   400,   401,   402,     0,
       0,     0,   524,     0,   529,   520,   521,   522,     0,   534,
     533,     0,     0,     0,     0,   525,   526,   527,   443,   531,
     135,   140,   113,     0,     0,   516,     0,   518,     0,   420,
     427,   428,   512,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   429,     0,     0,     0,     0,   539,     0,     0,
      44,     0,     0,     0,    57,     0,    35,    36,    37,    38,
      39,   426,   425,     0,     0,   509,    24,    22,     0,     0,
       0,     0,    25,     0,     0,   231,   538,    70,   124,    71,
     132,     0,     0,     0,   493,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   319,   324,   322,     0,   332,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   229,     0,     0,
       0,   191,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301,     0,
     263,     0,     0,     0,     0,     0,     0,   326,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   424,
     423,     0,   488,     0,   467,     0,     0,     0,     0,     0,
       0,     0,   459,     0,     0,   426,   425,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,   223,     0,
       0,   362,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   540,     0,     0,   432,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    88,
       0,     0,    76,     0,     0,     0,     0,    80,   103,   105,
       0,     0,   501,     0,   111,     0,     0,     0,     0,     0,
     384,     0,     0,     0,     0,     0,    30,   434,   433,   507,
     505,    23,     0,     0,   508,   506,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,     0,     0,   330,     0,     0,   148,     0,   151,
       0,   154,     0,   157,     0,     0,     0,     0,     0,     0,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   307,     0,     0,   306,     0,   313,     0,   315,     0,
     309,     0,   311,     0,   273,   302,     0,     0,     0,   214,
       0,     0,     0,   337,     0,   218,   217,   357,     0,     0,
      31,    32,     0,     0,     0,     0,     0,     0,     0,   476,
     477,   478,   479,   466,   460,     0,     0,     0,     0,   498,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
      85,     0,    89,     0,     0,    77,     0,    81,     0,   233,
     436,   232,   395,   403,   404,   405,   530,     0,   440,   441,
     442,     0,     0,   419,   136,     0,   536,   141,   439,   517,
     519,   421,     0,     0,     0,    86,     0,     0,     0,    59,
       0,     0,     0,     0,    78,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   453,     0,
       0,    26,    27,     0,    28,     0,     0,   125,   128,    72,
      73,   162,     0,     0,     0,     0,     0,     0,   165,     0,
       0,   181,   182,     0,     0,   167,   188,     0,     0,     0,
       0,   158,     0,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,     0,     0,
     201,   201,     0,   283,     0,   285,     0,   287,     0,   308,
     455,     0,     0,   314,   316,   310,   312,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   436,   489,     0,     0,     0,     0,   490,   170,   171,
       0,     0,     0,     0,   114,   118,     0,     0,   363,     0,
       0,     0,    87,     0,     0,     0,    79,     0,   438,     0,
       0,     0,     0,     0,    97,     0,     0,    91,     0,     0,
       0,     0,   108,     0,     0,   109,     0,   502,   203,   204,
     205,   206,     0,     0,    40,     0,     0,     0,     0,     0,
      42,   510,     0,     0,   126,   129,     0,     0,   161,   168,
     169,   173,     0,     0,   183,     0,     0,   331,     0,   176,
       0,     0,   320,   187,   163,   175,   186,   190,   174,     0,
     184,   189,     0,     0,     0,     0,     0,     0,   452,     0,
     451,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,   213,     0,
       0,   212,     0,     0,     0,   207,     0,     0,   334,    33,
       0,     0,     0,     0,     0,     0,   496,     0,   251,   250,
       0,     0,     0,     0,    98,     0,     0,    92,     0,     0,
       0,   523,   528,     0,   137,   139,     0,   142,   143,   144,
      99,   101,    93,    95,   104,   106,     0,   112,     0,    82,
      45,     0,     0,     0,   454,     0,     0,     0,    29,     0,
     135,   140,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,   327,   327,     0,   119,   120,   201,     0,   194,
     195,     0,     0,     0,     0,     0,     0,     0,   303,     0,
       0,   201,     0,     0,     0,     0,     0,   198,   197,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,     0,
     100,   102,    94,    96,    83,     0,   491,     0,     0,   500,
       0,    41,     0,     0,     0,    43,    58,     0,     0,     0,
     345,   347,   346,   348,   349,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   318,
       0,     0,     0,   268,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,   495,   252,     0,   364,     0,   138,
       0,   145,   110,     0,     0,     0,     0,     0,   127,   130,
       0,     0,     0,     0,     0,   328,   338,     0,     0,   339,
       0,   192,     0,   289,     0,     0,   291,     0,     0,   293,
       0,     0,     0,   304,     0,   264,     0,   201,     0,     0,
       0,     0,     0,     0,     0,   172,   117,     0,   133,     0,
      49,     0,    55,     0,     0,     0,   159,   185,     0,   342,
       0,   343,   344,   449,   277,     0,     0,   284,   278,     0,
       0,   286,   279,     0,     0,   288,     0,     0,     0,   270,
       0,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
     297,     0,   299,   305,   317,   269,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   134,    46,     0,    53,     0,
       0,     0,     0,     0,     0,   280,     0,     0,   281,     0,
       0,   282,     0,     0,   215,     0,   209,     0,     0,     0,
       0,     0,    47,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,     0,     0,   290,     0,
     292,     0,   294,     0,   210,     0,     0,     0,     0,    48,
      50,     0,    51,     0,     0,     0,     0,     0,     0,   480,
     481,   482,   483,     0,     0,    56,   340,   341,   296,   298,
     300,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1428, -1428, -1428, -1428,   753, -1428, -1428, -1428, -1428,   194,
   -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428,
   -1428, -1428,  -379,     7,  2909,  2908, -1428,  1487, -1428, -1428,
   -1428, -1428, -1428,   318, -1428,   328, -1428, -1428, -1428, -1428,
   -1428, -1428,   744,  1950,    33,  -507,  -264, -1428, -1428, -1428,
   -1428, -1428, -1428, -1428,  1951, -1428, -1428, -1428, -1428, -1428,
   -1428, -1428, -1428, -1428, -1428, -1428, -1428, -1428,  -880, -1012,
   -1428, -1428,  1477, -1428,   322, -1428, -1428, -1428, -1428,  1728,
   -1428, -1428,   362, -1428, -1427,  2444,  -137,  2171,   353,  -248,
     613, -1428,   210,    49, -1428,  -365,    -3,   120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   978,    91,    92,   702,  1493,  1499,
     966,  1171,  1680,  1881,   967,  1830,  1921,   968,  1883,   969,
     970,  1175,   351,   444,   186,   820,    93,   720,   456,  1620,
    1621,   457,  1675,  1139,  1324,  1140,  1327,   754,   757,   760,
     763,  1521,  1375,   684,   301,   420,   421,    96,    97,    98,
      99,   100,   101,   102,   302,  1061,  1776,  1847,   789,  1545,
    1548,  1551,  1805,  1809,  1813,  1866,  1869,  1872,  1057,  1058,
    1213,  1017,   751,   798,  1702,   104,   105,   106,   107,   303,
     188,   920,   506,   259,  1357,   304,   305,   306,   569,   315,
     951,  1163,   454,   449,   921,   455,   335,   308
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   520,   501,   191,   782,   783,  1562,   275,   353,   532,
     509,   510,  1371,   535,   637,   960,   639,  1472,   313,   216,
     324,   414,   221,     5,   554,   556,   558,   511,   949,   652,
     551,   667,     4,   671,   221,   674,    95,   197,  1246,   329,
     216,  1792,   331,   827,  1153,  1255,   195,   829,   831,   833,
     194,   280,  1248,   281,   278,   190,   196,   317,   509,   510,
     337,  1250,   307,  1252,   267,  1106,   591,   278,   593,   349,
     350,   509,   510,   199,  1412,   212,  1413,   193,   278,  1799,
    -504,  1801,   213,   509,   510,   936,   976,  1414,   200,  1415,
    1362,  1628,  1048,   480,   481,   482,   349,   350,   485,   486,
     487,  1236,   523,  1049,   349,   350,   665,   509,   510,   524,
     201,  1050,  1051,  1052,   202,  -509,   352,  1053,  1054,  1055,
    1056,   509,   510,   109,   512,   282,   192,  1699,  1700,   669,
     325,   328,   203,  1701,   528,   529,   344,  1416,   268,  1417,
     673,   204,   269,   961,   962,   963,   964,   205,   541,   542,
     936,   254,   255,   208,   270,   209,   276,   509,   510,   415,
     416,   256,  1247,   228,   555,   557,   559,   580,   257,  1473,
     552,   864,   185,   206,   522,   868,  1249,   279,    89,  1292,
     278,  1257,  1154,  1155,   271,  1251,   272,  1253,  1684,    89,
     316,    89,   450,   450,   235,   509,   510,   236,  1254,   237,
     450,   326,   207,   354,  1698,   355,   533,   356,   278,   277,
     307,   214,   185,   185,   217,   307,   189,   419,   965,   307,
     314,   218,   307,   866,   222,   870,   307,   307,   307,   307,
     950,   553,   307,   307,   307,   217,   955,   198,   775,   776,
     330,  1793,   954,   332,   828,  1255,   307,   278,   830,   832,
     834,   570,   318,   338,   345,   346,   347,   348,   791,   458,
     339,  1107,   509,   510,   509,   510,   225,   977,   307,   307,
     307,   977,   229,   349,   350,   666,   346,   347,   348,   709,
     215,   942,   307,   307,   710,   349,   350,  1577,   817,   937,
     818,   349,   350,   943,   819,   307,  -507,   307,   670,   346,
     347,   348,  -508,   417,   219,   345,   346,   347,   348,   345,
     346,   347,   348,   936,   246,   451,   451,   247,   851,   345,
     346,   347,   348,   451,   349,   350,   349,   350,   349,   350,
     226,   459,   859,   450,   250,   307,   307,  -506,   349,   350,
     865,   346,   347,   348,   869,   346,   347,   348,   307,   251,
     252,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   340,  1832,   341,   212,   439,
     316,  1293,  1405,  1406,   342,   953,   450,   450,   450,   450,
     450,   450,   450,   450,   307,   450,   450,   220,   450,   450,
     450,   450,   450,   608,   509,   510,   450,   450,   450,   450,
     450,   278,   224,   278,   227,   448,   452,   349,   350,   956,
     777,   258,   260,   594,   266,   595,   285,   548,  -510,   286,
     307,   675,   185,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   571,   437,   438,   262,   223,   239,
     263,   439,   240,   264,   224,   241,   655,   242,   713,   230,
    1553,   238,   231,   714,   663,   232,   451,  1904,   307,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   243,   424,   418,   244,   439,   245,   509,
     510,   233,   345,   346,   347,   348,  1578,   706,  1115,   707,
     234,   708,  1120,   307,   307,   784,   185,  1455,  1456,   451,
     451,   451,   451,   451,   451,   451,   451,   705,   451,   451,
    1035,   451,   451,   451,   451,   451,   509,   510,   248,   451,
     451,   451,   451,   451,   662,   716,   664,   509,   510,   817,
     717,   818,   790,   249,   717,   307,   307,   307,   756,   759,
     762,   765,   253,  1232,   419,   419,   599,   278,   254,   255,
     442,   922,   443,   509,   510,   918,   509,   510,   256,   342,
     717,   307,   727,   273,   728,   265,   464,   274,   307,  1256,
    1339,   469,  1557,   509,   510,   473,    48,    49,    50,    51,
    1703,  1704,   479,   349,   350,    56,  1701,   261,    59,  1641,
     638,  1273,   640,   641,   642,   643,   644,   718,   646,   647,
     719,   649,   650,   651,   307,   653,   509,   510,   283,   657,
     658,   659,   660,   661,  1183,   504,   505,  1159,   727,   727,
     733,   879,  1643,   513,   509,   510,   284,   521,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
    1645,  1216,   287,  1218,   439,  1220,   288,  1222,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   509,   510,   307,   546,   439,   547,   307,   548,
     821,   573,   184,   574,   185,   938,   509,   510,  1653,   944,
     342,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   721,   509,   510,   719,   439,
    1255,   289,  1162,  1255,   509,   510,  1255,   307,   309,   310,
     560,   307,  1655,   561,   450,   311,   562,   278,   563,   450,
    1656,   312,   945,   307,   307,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   345,
     346,   347,   348,   439,   509,   510,   727,   307,   737,   509,
     510,   509,   510,   509,   510,   509,   510,   319,   349,   350,
    1764,   727,  1712,   743,  1715,  1767,  1718,  1770,   307,  1778,
     597,  1780,   598,   992,  1340,   711,   686,   712,  1186,   342,
    1333,  1334,  1610,   727,   342,  1337,  1338,  1611,   320,   321,
    1353,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   727,  1255,   837,   322,   439,
     509,   510,   509,   510,   509,   510,   307,   509,   510,   509,
     510,   323,   862,   879,   863,   307,  1835,   307,  1836,   307,
    1849,   307,   727,  1887,   958,  1888,   307,   451,   336,   382,
     988,   307,   451,   383,   434,   435,   436,   437,   438,   769,
     770,   384,  1255,   439,   817,  1255,   818,   387,  1255,   307,
     844,  1255,   388,   307,   817,   389,   818,   307,   817,   903,
     818,   780,   781,  1206,  1116,   450,   394,   398,  1121,   505,
     436,   437,   438,   399,  1125,  1127,   727,   439,  1031,   400,
     401,   806,   807,   808,   404,   405,  1818,  1255,  1263,  1255,
     307,  1255,   406,  1541,  1542,   450,   422,   441,   307,   450,
     450,   817,  1345,   818,   423,   440,   926,   835,   445,   478,
     817,   450,   818,   450,   467,   928,   817,   986,   818,  1467,
     472,   727,   990,  1460,  1461,   817,   496,   818,  1464,  1465,
    1322,   817,   727,   818,  1032,   477,  1325,   278,   502,   483,
     307,   307,   307,   307,   727,   484,  1073,  1864,   503,  1867,
     873,  1870,  1048,  1138,   727,   488,  1074,  1873,   727,   727,
    1075,  1092,   727,  1049,  1123,   450,   489,   490,  1177,  1178,
     491,  1050,  1051,  1052,  1192,   492,  1193,  1053,  1054,  1055,
    1056,  1198,   493,  1199,   307,   307,   494,   307,   451,   307,
     307,   499,   495,   307,   307,   727,   534,  1229,   307,   727,
    1909,  1274,  1911,   514,  1913,  1048,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   727,  1049,  1279,   451,   439,
     515,   516,   451,   451,  1050,  1051,  1052,   727,   525,  1280,
    1053,  1054,  1055,  1056,   451,   526,   451,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   527,   727,   979,  1281,   439,   342,   983,  1429,   727,
     316,  1282,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1125,  1127,  1128,  1048,
     439,   727,   727,  1284,  1285,   307,   307,   307,   451,  1487,
    1049,   531,  1177,  1178,   536,   537,   307,   185,  1050,  1051,
    1052,  1347,   543,  1348,  1053,  1054,  1055,  1056,  1134,   538,
     544,  1765,  1136,  1137,  1033,   727,   727,  1349,  1350,   727,
    1707,  1351,   539,   727,  1142,  1352,  1143,   540,   727,  1038,
    1389,   545,   450,   450,   550,   572,  1044,   450,   450,  1497,
     576,  1498,  1059,  1529,   727,  1530,  1566,   278,   582,  1616,
    1341,  1617,   727,   727,  1632,  1633,  1497,  1497,  1654,  1696,
     588,   307,  1081,  1720,   727,  1721,  1736,  1738,   717,  1739,
    1741,  1088,  1497,  1089,  1746,  1090,   583,  1091,  1182,  1322,
     589,  1748,  1094,   307,  1325,  1768,  1749,  1097,  1335,   307,
    1497,   727,  1752,  1760,   727,   307,  1779,   307,   307,  1616,
     590,  1829,   307,   307,   727,   307,  1848,   307,   727,   307,
    1850,   307,   307,   307,  1048,  1497,   727,  1859,  1896,   592,
    1901,  1677,  1902,   606,  1497,  1049,  1923,  1368,   607,  1933,
     307,  1934,   610,  1050,  1051,  1052,   611,   614,   439,  1053,
    1054,  1055,  1056,   677,   676,   307,  1133,   740,   184,   307,
     679,   307,   723,   724,   744,   451,   451,   745,   746,   772,
     451,   451,   749,   750,   773,   799,   774,   797,   800,   802,
     316,   809,   447,   112,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   450,   450,   810,   816,   439,
     450,   450,   849,   822,   824,   825,  1165,  1166,  1167,  1168,
     826,   852,   860,   861,   450,   874,   875,  1468,   139,   140,
     141,   142,   143,   144,   145,   146,   906,   907,   933,   150,
     151,   152,   153,   908,   911,   912,   913,   155,   156,   157,
     923,   924,   158,   925,   278,   930,   931,   934,   939,   932,
     307,   940,   947,   163,   948,  1191,   975,   982,  1678,   985,
     450,   987,   989,   307,  1209,   993,   996,   997,   998,  1000,
    1470,  1001,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1002,  1723,  1480,  1003,
     439,  1006,  1007,  1011,  1016,  1018,  1005,  1020,  1021,   307,
     307,  1022,  1024,  1023,  1025,  1026,  1034,  1237,  1238,  1239,
    1068,  1027,  1082,  1098,  1041,  1505,  1042,  1083,   451,   451,
    1085,  1086,  1087,   451,   451,  1099,  1100,  1101,   307,  1111,
     307,  1109,   307,  1112,  1113,  1117,  1118,   451,   166,   167,
     168,  1147,  1149,   419,   419,  1152,  1157,   307,  1468,  1158,
     175,  1160,   176,    89,   307,  1536,  1161,  1164,  1344,  1172,
    1176,  1181,  1173,  1174,   307,  1188,  1196,   316,   307,  1202,
    1207,  1208,  1203,   349,   350,  1210,  1211,  1214,  1230,  1419,
    1240,  1126,  1215,   451,  -505,  1224,  1225,  1226,  1227,  1228,
    1243,  1244,  1245,  1258,   307,  1259,  1264,  1260,  1261,  1262,
    1265,  1266,  1267,  1270,  1268,  1582,  1269,  1271,  1289,  1294,
    1295,  1297,  1318,  1819,  1300,   307,  1302,   110,   333,  1305,
    1595,  1598,  1599,   113,   114,   115,  1307,  1469,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   307,  1309,  1310,  1311,  1359,   307,  1319,  1343,  1317,
    1361,  1364,   147,   148,   149,  1462,  1320,  1329,  1321,   154,
    1354,  1342,  1360,  1502,  1369,  1370,  1372,   307,  1373,  1378,
     159,   160,   161,  1379,  1380,  1381,  1382,  1384,   162,  1385,
     307,  1386,  1374,   450,  1048,  1387,  1392,  1393,  1402,  1516,
    1404,  1423,  1424,   278,  1403,  1049,  1410,  1411,  1418,  1425,
    1426,  1433,   307,  1050,  1051,  1052,  1434,  1437,  1428,  1053,
    1054,  1055,  1056,  1438,  1441,  1448,  1457,  1449,   307,  1450,
    1454,   307,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1828,   307,  1458,  1471,
     439,  1483,   307,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,  1048,  1474,  1477,
     419,   439,  1482,   165,  1485,  1488,  1489,   169,  1049,  1490,
    1491,   170,   171,   172,   173,   174,  1050,  1051,  1052,    89,
    1501,  1509,  1053,  1054,  1055,  1056,  1510,  1511,   307,  1514,
    1771,  1517,  1519,   177,   178,  1520,  1518,  1523,   179,  1466,
    1524,  1525,  1526,   299,  1527,  1528,   451,   307,   183,  1531,
     497,  1544,  1547,  1550,  1554,  1558,   316,  1561,  1565,  1569,
    1584,  1587,  1591,  1600,   187,  1601,  1508,  1602,  1603,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,  1604,  1607,  1532,  1533,   439,  1606,  1608,
    1048,  1609,  1618,  1615,  1627,  1629,  1630,  1631,  1636,  1637,
    1642,  1049,  1639,  1845,  1543,   307,  1546,   307,  1549,  1050,
    1051,  1052,  1640,  1644,  1646,  1053,  1054,  1055,  1056,  1788,
     307,  1648,  1651,  1560,  1650,  1657,  1563,  1564,  1663,  1668,
    1670,  1671,   447,   112,  1669,  1672,  1673,  1674,  1679,  1686,
    1690,  1691,  1692,  1693,  1694,  1695,   334,  1697,  1719,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,  1726,  1737,  1742,  1743,   439,   139,   140,
     141,   142,   143,   144,   145,   146,   307,  1750,  1756,   150,
     151,   152,   153,  1759,   450,  1753,  1757,   155,   156,   157,
    1761,  1773,   158,  1777,  1774,  1786,  1889,  1797,  1802,  1804,
    1807,  1808,  1811,   163,  1816,  1812,  1815,  1855,  1821,  1843,
    1856,   307,  1837,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,  1865,   450,  1868,
     450,   439,  1871,  1839,  1841,   407,   408,   409,   411,   413,
    1874,  1876,  1885,  1857,  1905,  1908,  1884,  1890,  1892,  1910,
    1894,  1912,   446,  1914,  1903,  1920,   453,  1935,  1936,  1937,
     450,  1938,  1939,  1666,  1940,  1942,  1363,  1789,  1688,  1376,
     460,   462,   465,   466,   722,   468,   462,   470,   471,  1689,
     462,   474,   475,    94,   103,  1705,  1484,   462,   166,   167,
     168,     0,     0,     0,   752,     0,     0,     0,     0,  1048,
     175,     0,   176,    89,     0,   498,     0,   451,     0,     0,
    1049,     0,     0,     0,   507,   508,     0,  1706,  1050,  1051,
    1052,     0,     0,   508,  1053,  1054,  1055,  1056,   817,  1568,
     818,     0,     0,  1711,     0,  1714,     0,  1717,  1727,     0,
       0,     0,     0,     0,     0,  1725,     0,     0,  1728,     0,
       0,   451,     0,   451,     0,     0,   565,   567,   462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,   578,
     579,     0,   581,     0,     0,     0,   584,   585,   586,     0,
       0,   587,     0,   451,     0,     0,     0,     0,     0,     0,
       0,     0,  1754,     0,     0,     0,  1758,  1882,   603,   605,
       0,     0,     0,     0,     0,  1891,     0,     0,     0,     0,
       0,     0,   612,   613,     0,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,     0,     0,     0,
       0,  1919,     0,  1922,     0,  1798,     0,     0,   648,  1800,
       0,     0,     0,     0,   654,     0,   656,     0,     0,  1605,
       0,  1820,     0,  1823,     0,     0,     0,     0,     0,     0,
       0,     0,  1822,  1941,     0,     0,     0,     0,     0,     0,
     685,   462,     0,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,     0,     0,
     703,   704,     0,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,   565,
       0,   439,     0,     0,     0,   731,     0,  1862,  1863,     0,
     736,     0,  1875,     0,     0,   741,   742,     0,     0,     0,
       0,   747,   748,     0,     0,     0,   753,   755,   758,   761,
     764,   766,   767,   768,   462,   462,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   785,   786,   787,   407,   408,   788,     0,     0,
       0,   792,   793,   794,   795,   796,     0,     0,     0,   801,
       0,   803,   804,     0,     0,     0,   462,   462,   462,     0,
       0,   811,   812,   813,   814,   815,     0,     0,     0,     0,
       0,   823,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   462,     0,     0,     0,     0,     0,   838,   840,
       0,   842,   843,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,  1048,     0,     0,
       0,   439,   814,   815,     0,   842,   843,     0,  1049,     0,
       0,     0,     0,     0,   872,   462,  1050,  1051,  1052,   876,
       0,     0,  1053,  1054,  1055,  1056,     0,     0,     0,   110,
     333,     0,     0,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,   463,     0,     0,     0,     0,   463,
       0,     0,     0,   463,   147,   148,   149,     0,     0,     0,
     463,   154,   946,     0,     0,  1048,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,  1049,     0,     0,     0,
     162,     0,     0,  1893,  1050,  1051,  1052,     0,     0,     0,
    1053,  1054,  1055,  1056,   973,   974,     0,  1048,   462,   980,
     981,     0,   462,   984,     0,     0,     0,     0,  1049,     0,
       0,   991,     0,     0,   840,   994,  1050,  1051,  1052,  1048,
       0,     0,  1053,  1054,  1055,  1056,     0,     0,  1008,   566,
    1049,   463,     0,     0,     0,     0,     0,  1014,  1050,  1051,
    1052,     0,     0,     0,  1053,  1054,  1055,  1056,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
       0,     0,     0,     0,     0,   165,  1039,  1040,     0,   169,
       0,  1895,  1043,   170,   171,   172,   173,   174,     7,     8,
    1635,    89,     0,     0,     0,  1067,     0,     0,  1069,     0,
       0,     0,     0,     0,     0,   517,   518,     0,     0,     0,
     179,     0,     0,  1926,  1667,   519,     0,   462,     0,     0,
     183,     0,   257,     0,     0,     0,   462,     0,   462,     0,
     462,     0,   462,     0,     0,  1927,     0,   462,     0,     0,
       0,     0,   462,     0,     0,     0,     0,     0,  1102,     0,
    1104,  1105,  1785,     0,   680,    24,    25,   681,    27,    28,
     682,    30,   683,    32,   463,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1129,
       0,     0,     0,     0,     0,     0,     0,  1130,  1131,  1132,
       0,   462,   566,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,  1141,     0,     0,     0,     0,  1144,     0,     0,     0,
       0,     0,     0,     0,     0,  1148,     0,   463,   463,   476,
       0,  1156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   462,   462,   462,     0,     0,  1170,     0,     0,
       0,     0,     0,   500,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,   463,
     463,   463,   439,   805,     0,     0,     0,   530,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,   463,   439,     0,     0,   462,
       0,     0,   841,     0,     0,     0,     0,     0,     0,  1217,
       0,  1219,     0,  1221,     0,  1223,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,  1844,     0,     0,   439,     0,     0,  1242,   463,     0,
       0,     0,   600,   601,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   609,     0,  1048,     0,     0,
       0,     0,     0,     0,     0,     0,  1272,     0,  1049,     0,
       0,  1275,     0,  1276,  1277,  1278,  1050,  1051,  1052,     0,
       0,  1283,  1053,  1054,  1055,  1056,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1301,     0,     0,     0,     0,  1306,     0,
     680,    24,    25,   681,    27,    28,   682,    30,   683,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,   463,     0,     0,     0,   463,     0,     0,     0,  1346,
       0,     0,     0,     0,     0,     0,     0,   841,   995,     0,
    1355,  1356,     0,  1928,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,  1365,  1367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     210,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
    1407,  1408,  1409,   439,     0,     0,     0,     0,     0,     0,
       0,  1420,     0,  1422,     0,     0,     0,     0,     0,   857,
       0,     0,     0,     0,  1427,     0,     0,     0,     0,     0,
     463,     0,   462,     0,     0,     0,     0,  1439,     0,   463,
       0,   463,     0,   463,     0,   463,     0,     0,     0,     0,
     463,     0,     0,     0,     0,   463,     0,   343,  1451,  1452,
    1453,     0,     0,     0,     0,     0,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,     0,     0,     0,   385,   386,     0,     0,     0,   390,
     391,   392,   393,     0,     0,   395,     0,     0,  1481,     0,
       0,   396,   397,     0,   463,     0,     0,   402,   403,     0,
       0,     0,  1494,     0,     0,     0,     0,  1500,     0,     0,
       0,     0,     0,     0,     0,  1740,   570,     0,     0,     0,
    1506,  1507,     0,     0,     0,     0,     0,  1512,  1513,     0,
       0,   935,  1515,     0,     0,   941,     0,     0,     0,     0,
    1522,     0,     0,     0,   463,   463,   463,   463,     0,     0,
     462,   462,  1534,     0,  1535,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
       0,     0,     0,   462,     0,     0,  1567,     0,     7,     8,
       0,  1570,  1571,  1572,  1573,     0,     0,     0,     0,     0,
       0,     0,   463,     0,  1581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1015,     0,     0,     0,     0,   549,
    1597,   680,    24,    25,   681,    27,    28,   682,    30,   683,
      32,     0,    33,     0,     0,     0,   575,    38,    39,     0,
      41,    42,    43,  1612,  1613,     0,    46,     0,     0,     0,
       0,  1619,     0,     0,   680,    24,    25,   681,    27,    28,
     682,    30,   683,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
      67,    68,    69,     0,     0,     0,     0,  1638,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   726,
     437,   438,     0,     0,     0,  1652,   439,   565,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,  1664,     0,  1665,  1110,     0,   462,     0,
    1114,     0,     0,     0,  1119,     0,     0,     0,     0,     0,
       0,  1676,     0,     0,     0,     0,   678,     0,     0,     0,
     858,     7,     8,     0,     0,     0,     0,     0,     0,  1681,
       0,     0,     0,     0,  1685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1135,     0,     0,     0,     0,
       0,     0,   462,  1036,     0,     0,     0,     0,     0,  1710,
       0,  1713,     0,  1716,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,     0,     0,     0,  1729,  1730,  1731,
    1732,  1733,     0,     0,     0,     0,     0,   680,    24,    25,
     681,    27,    28,   682,    30,   683,    32,     0,    33,     0,
    1744,  1745,     0,    38,    39,  1747,    41,    42,    43,     0,
       0,     0,    46,     0,     0,  1751,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,  1762,     0,     0,     0,
       0,  1194,  1195,     0,  1197,     0,  1200,  1201,     0,     0,
    1204,  1205,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,  1787,     0,     0,     0,
       0,  1500,     0,     0,     0,     0,     0,     0,  1795,     0,
       0,     0,     0,   845,     0,     0,     0,     0,     0,     0,
       0,     0,  1806,     0,     0,  1810,     0,     0,  1814,     0,
       0,     0,  1817,     0,     0,     0,   462,     0,   462,  1824,
    1825,  1826,  1827,     0,     0,     0,     0,     0,     0,  1831,
       0,     0,  1833,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,     0,   892,   893,   894,   895,   896,
     897,   898,  1286,  1287,  1288,   902,   904,   905,     0,     0,
       0,   909,   910,  1296,     0,     0,     0,   915,   916,   917,
       0,   919,  1861,   570,     0,     0,     0,     0,   927,   929,
       0,     0,     0,   463,   463,     0,     0,   462,     0,  1877,
    1878,  1879,  1880,     0,     0,     0,   952,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,   463,     0,     0,   439,   463,     7,     8,     0,
       0,     0,  1539,     0,  1540,  1906,  1907,     0,  1358,     0,
       0,     0,     0,     0,     0,  1915,  1916,  1917,  1918,  1212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1377,     0,     0,     0,     0,     0,  1383,     0,     0,     0,
       0,     0,  1388,     0,  1390,  1391,     0,     0,     0,  1394,
    1395,     0,  1396,     0,  1397,     0,  1398,     0,  1399,  1400,
    1401,     0,     0,   680,    24,    25,   681,    27,    28,   682,
      30,   683,    32,     0,    33,     0,     0,  1421,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,  1432,     7,     8,     0,  1436,   570,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     566,     0,    67,    68,    69,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   571,   437,   438,     0,
       0,   463,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,   680,
      24,    25,   681,    27,    28,   682,    30,   683,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,  1492,     0,     0,
       0,     0,  1037,     0,     0,   463,     0,   853,     0,     0,
    1504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   463,   959,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1145,  1146,     0,     0,     0,     0,  1150,  1151,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1358,     0,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     726,   437,   438,     0,  1574,     0,     0,   439,  1060,  1189,
    1190,  1583,     0,     0,     0,  1093,     0,     0,     0,     0,
       0,  1590,     0,     0,     0,  1594,     0,   680,    24,    25,
     681,    27,    28,   682,    30,   683,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,  1614,    46,     0,     0,     0,     0,     0,     0,   463,
       0,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,  1649,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
     463,  1298,  1299,     0,     0,     0,  1303,  1304,     0,     0,
       0,  1308,     0,     0,     0,     0,     0,  1312,  1313,  1314,
    1315,  1316,  1291,     0,     0,     0,  1103,  1323,  1326,     0,
       0,  1330,  1331,  1332,     0,     0,     0,     0,  1336,  1358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1358,     0,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,  1722,   439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,  1755,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,  1772,   155,   156,   157,     0,     0,
     158,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,   163,  1442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1459,     0,     0,     0,
       0,  1463,     0,     0,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,  1358,     0,     0,
       0,  1475,  1476,     0,     0,  1478,  1479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
       0,     0,     0,   170,   171,   172,   173,   174,   175,     0,
     176,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   180,     0,   181,     0,   182,
     183,     0,   184,     0,   185,     0,     0,     0,   110,   290,
       0,     0,     0,     0,   113,   114,   115,     0,  1358,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,  1585,  1586,
     154,     0,  1588,  1589,     0,     7,     8,     0,  1592,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,     0,   295,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,   680,    24,    25,   681,    27,    28,   682,    30,   683,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,   517,  1559,     0,     0,     0,   179,
       0,     0,     0,     0,   519,     0,     0,   110,   290,   183,
       0,   257,   568,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
    1108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     7,
       8,     0,   293,     0,     0,   294,     0,     0,   295,     0,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   817,     0,   818,   680,    24,    25,   681,    27,
      28,   682,    30,   683,    32,     0,    33,     0,     0,     0,
       0,    38,    39,   165,    41,    42,    43,   169,     0,     0,
      46,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   461,     0,     0,     0,   179,     0,
       0,     0,     0,   299,    67,    68,    69,     0,   183,     0,
       0,   568,   110,   290,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   155,   156,
     157,     0,     0,   158,  1231,   159,   160,   161,     0,     0,
       0,     0,     0,   162,   163,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1575,     0,  1576,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,     0,     0,     0,   170,   171,   172,   173,
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
       0,    56,     0,     0,    59,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1708,     0,  1709,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,     0,     0,     0,   170,   171,   172,   173,   174,   175,
       0,   176,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   298,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   333,
     112,   183,     0,  1593,   113,   114,   115,     0,     0,   116,
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
       0,     0,   170,   171,   172,   173,   174,   175,     0,   176,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,     0,     0,     0,   183,
       0,  1366,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,   165,   166,   167,   168,   169,     0,     0,   596,   170,
     171,   172,   173,   174,   175,     0,   176,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,     0,     0,     0,   179,     0,     0,     0,
       0,   299,     0,   110,   333,   112,   183,     0,  1580,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     7,     8,     0,   155,
     156,   157,     0,     0,   158,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,   163,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,   957,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,    24,    25,   681,    27,    28,   682,    30,
     683,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,     0,     0,     0,   170,   171,   172,
     173,   174,   175,     0,   176,    89,     0,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,   177,
     178,     0,     0,     0,   179,     0,     0,     0,     0,   299,
       0,   110,   290,   291,   183,     0,  1596,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,  1775,     0,   154,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
     680,    24,    25,   681,    27,    28,   682,    30,   683,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,   177,   298,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     290,  1430,   183,     0,   300,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,  1846,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   293,     0,     0,   294,     0,     0,
     295,     0,   296,   324,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,     0,
     150,   151,   152,   153,     0,     0,     0,     0,   155,   156,
     157,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   298,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,   110,   290,     0,
     183,     0,  1431,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   292,     0,     0,     0,     0,     0,     0,     0,   166,
     167,   168,   147,   148,   149,     0,     0,     0,     0,   154,
       0,   175,     0,   176,    89,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,   293,     0,     0,   294,     0,     0,   295,     0,
     296,   447,   112,     0,     0,     0,     0,     0,     0,     0,
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
     293,     0,     0,   294,   327,   112,   295,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,   155,
     156,   157,     0,     0,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,     0,
       0,   165,     0,     0,     0,   169,     0,     0,     0,   170,
     171,   172,   173,   174,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   461,     0,     0,     0,   179,     0,     0,     0,
       0,   299,     0,   110,   290,     0,   183,     0,   564,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   292,     0,     0,
     166,   167,   168,     0,     0,     0,     0,     0,   147,   148,
     149,     0,   175,     0,   176,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,   161,     0,
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
       0,   110,   290,     0,   183,     0,   839,   113,   114,   115,
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
       0,     0,     0,  1010,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   298,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     290,     0,   183,     0,  1435,   113,   114,   115,     0,     0,
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
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1063,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   517,  1559,     0,     0,     0,
     179,     0,     0,     0,     0,   519,     0,   110,   333,   112,
     183,     0,   257,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,   155,   156,   157,     0,     0,   158,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,   163,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1084,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1122,     0,     0,     0,     0,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,   165,   166,   167,   168,   169,  1235,     0,
       0,   170,   171,   172,   173,   174,   175,     0,   176,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,     0,     0,     0,   179,   110,
     290,     0,     0,   299,     0,   113,   114,   115,   183,     0,
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
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   461,     0,     0,     0,
     179,   110,   333,     0,     0,   299,     0,   113,   114,   115,
     183,     0,   116,   117,   118,   119,   120,   121,   122,   123,
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
       0,   169,  1556,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,     0,
       0,     0,   179,     0,     0,     0,     0,   299,   410,     0,
       0,     0,   183,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,   165,     0,
       0,   439,   169,     0,     0,   672,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
       0,     0,     0,   179,     0,     0,     0,     0,   299,   110,
     333,   412,     0,   183,     0,   113,   114,   115,     0,     0,
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
    1622,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   299,   602,     0,     0,     0,
     183,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,   165,     0,     0,   439,
     169,     0,     0,   856,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,     0,     0,
       0,   179,     0,     0,     0,     0,   299,   110,   333,   604,
    1241,   183,     0,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   333,
     159,   160,   161,     0,   113,   114,   115,     0,   162,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,   165,     0,     0,     0,   169,  1623,     0,
       0,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,     0,     0,     0,   179,     0,
       0,     0,     0,   299,     0,    -4,     1,     0,   183,    -4,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,     0,     0,     0,   179,
       0,    -4,    -4,    -4,   299,     0,     0,    -4,    -4,   183,
      -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     6,     0,     0,     0,     0,    -4,     0,     0,     7,
       8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     9,    10,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,    63,    64,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    66,    67,    68,    69,     0,     0,    70,
       0,    71,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,     0,    89,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1624,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1625,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1626,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1658,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1724,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1734,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1735,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1763,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1766,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1769,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1796,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1803,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1838,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1840,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1842,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1860,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1886,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1924,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1925,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1929,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1930,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1931,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1932,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,   771,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
    1634,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   836,     0,     0,     0,     0,   778,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,   715,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,   778,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,   779,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
     850,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,   891,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,   899,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,   900,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,   901,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
     914,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1045,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1046,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1047,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1078,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1187,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1233,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1234,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1290,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1443,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1444,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1445,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1446,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1495,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1496,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1503,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1659,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1660,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1661,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1662,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1682,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1683,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1687,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1781,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1782,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1783,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1784,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1791,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1794,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1834,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1851,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1852,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1853,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1854,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,  1897,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
    1898,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1899,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,  1900,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,   871,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,   878,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,   972,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1071,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1072,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
    1076,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1077,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1080,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1096,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1124,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,  1180,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1185,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,  1440,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1486,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1647,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   668,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   725,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     729,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   730,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   732,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   734,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   735,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   738,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   739,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   836,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   846,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   847,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     848,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   854,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   855,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   867,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   877,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   971,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   999,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1004,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1009,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1012,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1013,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1019,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1028,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1029,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1030,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1062,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1064,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1065,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1066,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1070,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1079,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1095,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1179,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1184,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1328,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1538,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1555,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1579,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1790,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1858,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439
};

static const yytype_int16 yycheck[] =
{
       3,   265,   250,     6,   511,   512,  1433,     4,     4,     4,
     189,   190,     6,   277,   379,     4,   381,     4,     4,     4,
       4,     4,     4,     0,     5,     5,     5,   206,     4,   394,
       5,   410,     6,   412,     4,   414,     3,     6,     6,     5,
       4,     6,     5,     5,     4,  1057,   199,     5,     5,     5,
      84,     4,     6,     6,    57,     6,   199,     4,   189,   190,
       6,     6,    65,     6,     4,     7,   330,    70,   332,   195,
     196,   189,   190,     6,   205,   199,   207,    13,    81,     6,
     206,     6,   206,   189,   190,     7,     6,   205,     6,   207,
       6,  1518,   101,   230,   231,   232,   195,   196,   235,   236,
     237,   207,   199,   112,   195,   196,     7,   189,   190,   206,
       6,   120,   121,   122,     6,   206,   109,   126,   127,   128,
     129,   189,   190,     3,   206,    78,     6,   105,   106,     7,
      81,    82,   199,   111,   271,   272,     7,   205,    78,   207,
       7,     6,    82,   132,   133,   134,   135,     6,   285,   286,
       7,   189,   190,   199,    94,   201,   153,   189,   190,   142,
     143,   199,   130,     6,   145,   145,   145,   203,   206,   156,
     145,     7,   208,   201,   206,     7,   130,    57,   175,     8,
     183,  1061,   142,   143,    84,   130,    86,   130,  1615,   175,
      70,   175,   195,   196,    81,   189,   190,    84,   207,    86,
     203,    81,   201,   199,  1631,   201,   201,   203,   211,   206,
     213,   199,   208,   208,   199,   218,     6,   184,   207,   222,
     206,   206,   225,   602,   206,   604,   229,   230,   231,   232,
     206,   206,   235,   236,   237,   199,   206,   206,   502,   503,
     206,   206,   206,   206,   206,  1257,   249,   250,   206,   206,
     206,     8,   199,   199,   176,   177,   178,   179,   522,   210,
     206,   203,   189,   190,   189,   190,    88,   187,   271,   272,
     273,   187,   206,   195,   196,   176,   177,   178,   179,   200,
     199,   203,   285,   286,   205,   195,   196,     8,   200,   668,
     202,   195,   196,   672,   206,   298,   206,   300,   176,   177,
     178,   179,   206,   183,   199,   176,   177,   178,   179,   176,
     177,   178,   179,     7,    81,   195,   196,    84,   582,   176,
     177,   178,   179,   203,   195,   196,   195,   196,   195,   196,
      84,   211,   596,   336,   142,   338,   339,   206,   195,   196,
     176,   177,   178,   179,   176,   177,   178,   179,   351,   157,
     158,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   199,  1793,   201,   199,   198,
     250,   200,     6,     7,   208,   206,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   199,   391,   392,
     393,   394,   395,   344,   189,   190,   399,   400,   401,   402,
     403,   404,   199,   406,    84,   195,   196,   195,   196,   206,
     205,    49,    50,   199,    52,   201,    81,   203,   206,    84,
     423,   414,   208,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    78,   199,    78,
      81,   198,    81,    84,   199,    84,   397,    86,   200,    78,
     207,    86,    81,   205,   405,    84,   336,  1884,   461,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    81,     6,     4,    84,   198,    86,   189,
     190,    84,   176,   177,   178,   179,   207,   199,   867,   201,
      84,   203,   871,   496,   497,   205,   208,     6,     7,   379,
     380,   381,   382,   383,   384,   385,   386,     6,   388,   389,
     774,   391,   392,   393,   394,   395,   189,   190,   199,   399,
     400,   401,   402,   403,   404,   200,   406,   189,   190,   200,
     205,   202,   205,    81,   205,   538,   539,   540,   489,   490,
     491,   492,   206,   205,   511,   512,   336,   550,   189,   190,
     199,     6,   201,   189,   190,   200,   189,   190,   199,   208,
     205,   564,   205,    84,   207,   206,   213,    81,   571,   205,
       7,   218,   205,   189,   190,   222,   105,   106,   107,   108,
     105,   106,   229,   195,   196,   114,   111,   206,   117,   205,
     380,   203,   382,   383,   384,   385,   386,   202,   388,   389,
     205,   391,   392,   393,   607,   395,   189,   190,    81,   399,
     400,   401,   402,   403,   200,   253,   254,     6,   205,   205,
     207,   614,   205,   261,   189,   190,    84,   265,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     205,  1020,     4,  1022,   198,  1024,     4,  1026,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   189,   190,   667,   199,   198,   201,   671,   203,
     550,   199,   206,   201,   208,   668,   189,   190,   205,   672,
     208,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   202,   189,   190,   205,   198,
    1712,     4,   950,  1715,   189,   190,  1718,   710,     4,   199,
      78,   714,   205,    81,   717,   199,    84,   720,    86,   722,
     205,   199,   673,   726,   727,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   176,
     177,   178,   179,   198,   189,   190,   205,   750,   207,   189,
     190,   189,   190,   189,   190,   189,   190,   199,   195,   196,
     205,   205,  1642,   207,  1644,   205,  1646,   205,   771,   205,
     199,   205,   201,   724,  1153,   199,   423,   201,   200,   208,
    1145,  1146,   200,   205,   208,  1150,  1151,   205,   199,     6,
    1169,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   205,  1818,   207,     6,   198,
     189,   190,   189,   190,   189,   190,   819,   189,   190,   189,
     190,   201,   205,   816,   207,   828,   205,   830,   205,   832,
     205,   834,   205,   205,   207,   205,   839,   717,   201,   199,
     720,   844,   722,   199,   189,   190,   191,   192,   193,   496,
     497,   199,  1864,   198,   200,  1867,   202,   199,  1870,   862,
     206,  1873,   199,   866,   200,   199,   202,   870,   200,   205,
     202,   509,   510,     6,   867,   878,   199,     7,   871,   517,
     191,   192,   193,   199,   877,   878,   205,   198,   207,   199,
     199,   538,   539,   540,   199,   199,  1776,  1909,     6,  1911,
     903,  1913,   201,  1410,  1411,   908,   206,     6,   911,   912,
     913,   200,  1160,   202,   206,   206,   205,   564,     6,   206,
     200,   924,   202,   926,   199,   205,   200,   717,   202,  1308,
     199,   205,   722,  1298,  1299,   200,   206,   202,  1303,  1304,
     205,   200,   205,   202,   207,   199,   205,   950,   206,   199,
     953,   954,   955,   956,   205,   199,   207,  1837,   206,  1839,
     607,  1841,   101,   914,   205,   199,   207,  1847,   205,   205,
     207,   207,   205,   112,   207,   978,   199,   199,   971,   972,
     199,   120,   121,   122,    84,   199,    86,   126,   127,   128,
     129,    84,   199,    86,   997,   998,   199,  1000,   878,  1002,
    1003,     4,   199,  1006,  1007,   205,   201,   207,  1011,   205,
    1890,   207,  1892,   206,  1894,   101,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   205,   112,   207,   908,   198,
     206,   206,   912,   913,   120,   121,   122,   205,   199,   207,
     126,   127,   128,   129,   924,   199,   926,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   199,   205,   710,   207,   198,   208,   714,   207,   205,
     950,   207,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,  1079,  1080,   878,   101,
     198,   205,   205,   207,   207,  1098,  1099,  1100,   978,  1347,
     112,   199,  1095,  1096,     6,     6,  1109,   208,   120,   121,
     122,   205,   201,   207,   126,   127,   128,   129,   908,   206,
     201,   207,   912,   913,   771,   205,   205,   207,   207,   205,
    1637,   207,   206,   205,   924,   207,   926,   206,   205,   777,
     207,   201,  1145,  1146,   201,     6,   784,  1150,  1151,   205,
       6,   207,   790,     4,   205,     6,   207,  1160,   206,   205,
    1153,   207,   205,   205,   207,   207,   205,   205,   207,   207,
       6,  1174,   819,   205,   205,   207,   207,   205,   205,   207,
     207,   828,   205,   830,   207,   832,   145,   834,   978,   205,
       6,   207,   839,  1196,   205,   207,   207,   844,     6,  1202,
     205,   205,   207,   207,   205,  1208,   207,  1210,  1211,   205,
       6,   207,  1215,  1216,   205,  1218,   207,  1220,   205,  1222,
     207,  1224,  1225,  1226,   101,   205,   205,   207,   207,     6,
     205,  1596,   207,   206,   205,   112,   207,  1188,   206,   205,
    1243,   207,     6,   120,   121,   122,   201,     4,   198,   126,
     127,   128,   129,     7,   203,  1258,   903,     7,   206,  1262,
     207,  1264,   205,   205,     6,  1145,  1146,     6,     6,   200,
    1150,  1151,     7,     7,     6,     6,   206,     7,     7,     6,
    1160,     6,     4,     5,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,  1298,  1299,     6,     4,   198,
    1303,  1304,   142,    56,    56,    56,   953,   954,   955,   956,
      56,   206,   202,   200,  1317,     6,     6,  1310,    40,    41,
      42,    43,    44,    45,    46,    47,   200,   200,    40,    51,
      52,    53,    54,   205,   205,   205,   205,    59,    60,    61,
     205,   205,    64,   200,  1347,   200,   200,    40,    40,   202,
    1353,    40,     6,    75,     4,   993,     4,     6,  1606,     6,
    1363,     6,     6,  1366,  1011,     7,   145,     7,     7,     7,
    1321,   145,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     7,  1651,  1339,     7,
     198,     7,     7,   206,     4,     6,   145,   200,   205,  1402,
    1403,   200,   200,   205,   205,   200,   203,  1045,  1046,  1047,
       6,   205,   202,     7,   207,  1366,   207,   206,  1298,  1299,
     206,   206,   206,  1303,  1304,     7,     7,   203,  1431,     6,
    1433,   206,  1435,    40,    40,    40,    40,  1317,   160,   161,
     162,     6,     6,  1410,  1411,     6,     6,  1450,  1441,     6,
     172,     7,   174,   175,  1457,  1406,   201,     6,     6,   199,
       6,   187,   199,   206,  1467,     7,     7,  1347,  1471,     7,
       7,     7,    86,   195,   196,     7,     7,     6,     4,     6,
       4,   203,     7,  1363,   206,     7,     7,     7,     7,     7,
     206,     6,   199,     7,  1497,     6,   206,     7,     7,     7,
       6,     6,     6,     6,    84,  1456,     7,     6,     4,     4,
       4,   207,   200,  1777,     6,  1518,     6,     3,     4,     6,
    1471,  1472,  1473,     9,    10,    11,     6,  1317,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,  1554,     6,     4,     6,   206,  1559,   200,     7,   205,
       6,     6,    48,    49,    50,     6,   200,   200,   205,    55,
     199,   203,   203,  1363,     6,     6,   206,  1580,   206,     6,
      66,    67,    68,   206,   206,     6,     6,   206,    74,     6,
    1593,     6,    94,  1596,   101,     5,     4,     6,   206,     5,
       7,     6,     6,  1606,   206,   112,   206,   206,   201,     6,
       6,   206,  1615,   120,   121,   122,   206,  1264,  1256,   126,
     127,   128,   129,   206,     4,     6,   205,     6,  1631,   141,
       6,  1634,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     7,  1650,     6,     4,
     198,     4,  1655,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   101,     6,     6,
    1637,   198,     6,   159,     6,     6,     6,   163,   112,     6,
       6,   167,   168,   169,   170,   171,   120,   121,   122,   175,
       4,     6,   126,   127,   128,   129,     6,     6,  1701,     6,
     207,     6,     6,   189,   190,   145,   206,     6,   194,     6,
       6,     6,     6,   199,     6,     6,  1596,  1720,   204,     6,
     206,     6,     6,     6,   205,     6,  1606,     6,     6,     6,
       6,     6,   200,     6,     6,     6,  1374,     6,     6,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     6,     6,  1402,  1403,   198,     7,   203,
     101,     6,     6,   206,     5,    82,     6,   206,     6,   206,
     206,   112,   207,   207,  1412,  1778,  1414,  1780,  1416,   120,
     121,   122,   207,   206,   206,   126,   127,   128,   129,  1740,
    1793,     6,   206,  1431,     7,     6,  1434,  1435,   140,     6,
       6,     6,     4,     5,   207,     6,     6,     6,   143,     6,
       6,     6,     6,     6,     6,     6,    88,   206,     6,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     6,     6,     6,   206,   198,    40,    41,
      42,    43,    44,    45,    46,    47,  1849,   206,     6,    51,
      52,    53,    54,     6,  1857,   206,   206,    59,    60,    61,
     207,     6,    64,   206,   101,     6,   207,     6,     6,     6,
       6,     6,     6,    75,   207,     6,     6,  1828,     6,     6,
       6,  1884,   206,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     6,  1901,     6,
    1903,   198,     6,   206,   206,   177,   178,   179,   180,   181,
       6,     6,     6,   206,     6,     6,   206,   206,   206,     6,
     206,     6,   194,     6,   206,     6,   198,     6,     6,     6,
    1933,     6,     6,  1580,     6,     6,  1183,  1743,  1620,  1195,
     212,   213,   214,   215,   457,   217,   218,   219,   220,  1621,
     222,   223,   224,     3,     3,  1633,  1343,   229,   160,   161,
     162,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,   101,
     172,    -1,   174,   175,    -1,   247,    -1,  1857,    -1,    -1,
     112,    -1,    -1,    -1,   256,   257,    -1,  1634,   120,   121,
     122,    -1,    -1,   265,   126,   127,   128,   129,   200,     6,
     202,    -1,    -1,  1641,    -1,  1643,    -1,  1645,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,  1653,    -1,    -1,  1656,    -1,
      -1,  1901,    -1,  1903,    -1,    -1,   298,   299,   300,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,   311,
     312,    -1,   314,    -1,    -1,    -1,   318,   319,   320,    -1,
      -1,   323,    -1,  1933,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1700,    -1,    -1,    -1,  1704,  1857,   340,   341,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,   354,   355,    -1,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,    -1,    -1,    -1,
      -1,  1901,    -1,  1903,    -1,  1753,    -1,    -1,   390,  1757,
      -1,    -1,    -1,    -1,   396,    -1,   398,    -1,    -1,     6,
      -1,  1778,    -1,  1780,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1780,  1933,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,    -1,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,    -1,    -1,
     442,   443,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   461,
      -1,   198,    -1,    -1,    -1,   467,    -1,  1835,  1836,    -1,
     472,    -1,  1849,    -1,    -1,   477,   478,    -1,    -1,    -1,
      -1,   483,   484,    -1,    -1,    -1,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   514,   515,   516,   517,   518,   519,    -1,    -1,
      -1,   523,   524,   525,   526,   527,    -1,    -1,    -1,   531,
      -1,   533,   534,    -1,    -1,    -1,   538,   539,   540,    -1,
      -1,   543,   544,   545,   546,   547,    -1,    -1,    -1,    -1,
      -1,   553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,   570,   571,
      -1,   573,   574,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   101,    -1,    -1,
      -1,   198,   594,   595,    -1,   597,   598,    -1,   112,    -1,
      -1,    -1,    -1,    -1,   606,   607,   120,   121,   122,   611,
      -1,    -1,   126,   127,   128,   129,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,   213,    -1,    -1,    -1,    -1,   218,
      -1,    -1,    -1,   222,    48,    49,    50,    -1,    -1,    -1,
     229,    55,   674,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,   112,    -1,    -1,    -1,
      74,    -1,    -1,   207,   120,   121,   122,    -1,    -1,    -1,
     126,   127,   128,   129,   706,   707,    -1,   101,   710,   711,
     712,    -1,   714,   715,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   723,    -1,    -1,   726,   727,   120,   121,   122,   101,
      -1,    -1,   126,   127,   128,   129,    -1,    -1,   740,   298,
     112,   300,    -1,    -1,    -1,    -1,    -1,   749,   120,   121,
     122,    -1,    -1,    -1,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,    -1,    -1,    -1,   159,   778,   779,    -1,   163,
      -1,   207,   784,   167,   168,   169,   170,   171,    12,    13,
       6,   175,    -1,    -1,    -1,   797,    -1,    -1,   800,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,   207,     6,   199,    -1,   819,    -1,    -1,
     204,    -1,   206,    -1,    -1,    -1,   828,    -1,   830,    -1,
     832,    -1,   834,    -1,    -1,   207,    -1,   839,    -1,    -1,
      -1,    -1,   844,    -1,    -1,    -1,    -1,    -1,   850,    -1,
     852,   853,     6,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   423,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   899,   900,   901,
      -1,   903,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,   923,    -1,    -1,    -1,    -1,   928,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   937,    -1,   496,   497,   225,
      -1,   943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   953,   954,   955,   956,    -1,    -1,   959,    -1,    -1,
      -1,    -1,    -1,   249,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,   538,
     539,   540,   198,   207,    -1,    -1,    -1,   273,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,   564,   198,    -1,    -1,  1011,
      -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,  1021,
      -1,  1023,    -1,  1025,    -1,  1027,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,     6,    -1,    -1,   198,    -1,    -1,  1049,   607,    -1,
      -1,    -1,   338,   339,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1078,    -1,   112,    -1,
      -1,  1083,    -1,  1085,  1086,  1087,   120,   121,   122,    -1,
      -1,  1093,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,  1120,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   710,    -1,    -1,    -1,   714,    -1,    -1,    -1,  1161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   726,   727,    -1,
    1172,  1173,    -1,   207,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,    -1,    -1,  1187,  1188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   771,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
    1232,  1233,  1234,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1243,    -1,  1245,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,    -1,  1256,    -1,    -1,    -1,    -1,    -1,
     819,    -1,  1264,    -1,    -1,    -1,    -1,  1269,    -1,   828,
      -1,   830,    -1,   832,    -1,   834,    -1,    -1,    -1,    -1,
     839,    -1,    -1,    -1,    -1,   844,    -1,   108,  1290,  1291,
    1292,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,   150,
     151,   152,   153,    -1,    -1,   156,    -1,    -1,  1340,    -1,
      -1,   162,   163,    -1,   903,    -1,    -1,   168,   169,    -1,
      -1,    -1,  1354,    -1,    -1,    -1,    -1,  1359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,    -1,    -1,    -1,
    1372,  1373,    -1,    -1,    -1,    -1,    -1,  1379,  1380,    -1,
      -1,   667,  1384,    -1,    -1,   671,    -1,    -1,    -1,    -1,
    1392,    -1,    -1,    -1,   953,   954,   955,   956,    -1,    -1,
    1402,  1403,  1404,    -1,  1406,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1431,
      -1,    -1,    -1,  1435,    -1,    -1,  1438,    -1,    12,    13,
      -1,  1443,  1444,  1445,  1446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1011,    -1,  1456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   750,    -1,    -1,    -1,    -1,   290,
    1472,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    -1,   307,    94,    95,    -1,
      97,    98,    99,  1495,  1496,    -1,   103,    -1,    -1,    -1,
      -1,  1503,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
     137,   138,   139,    -1,    -1,    -1,    -1,  1539,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,  1557,   198,  1559,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1575,    -1,  1577,   862,    -1,  1580,    -1,
     866,    -1,    -1,    -1,   870,    -1,    -1,    -1,    -1,    -1,
      -1,  1593,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,
     207,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,  1611,
      -1,    -1,    -1,    -1,  1616,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,
      -1,    -1,  1634,   207,    -1,    -1,    -1,    -1,    -1,  1641,
      -1,  1643,    -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1655,    -1,    -1,    -1,  1659,  1660,  1661,
    1662,  1663,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
    1682,  1683,    -1,    94,    95,  1687,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,  1697,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1264,  1708,    -1,    -1,    -1,
      -1,   997,   998,    -1,  1000,    -1,  1002,  1003,    -1,    -1,
    1006,  1007,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1738,    -1,    -1,    -1,
      -1,  1743,    -1,    -1,    -1,    -1,    -1,    -1,  1750,    -1,
      -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1764,    -1,    -1,  1767,    -1,    -1,  1770,    -1,
      -1,    -1,  1774,    -1,    -1,    -1,  1778,    -1,  1780,  1781,
    1782,  1783,  1784,    -1,    -1,    -1,    -1,    -1,    -1,  1791,
      -1,    -1,  1794,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,    -1,   627,   628,   629,   630,   631,
     632,   633,  1098,  1099,  1100,   637,   638,   639,    -1,    -1,
      -1,   643,   644,  1109,    -1,    -1,    -1,   649,   650,   651,
      -1,   653,  1834,     8,    -1,    -1,    -1,    -1,   660,   661,
      -1,    -1,    -1,  1402,  1403,    -1,    -1,  1849,    -1,  1851,
    1852,  1853,  1854,    -1,    -1,    -1,   678,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,  1431,    -1,    -1,   198,  1435,    12,    13,    -1,
      -1,    -1,   205,    -1,   207,  1887,  1888,    -1,  1174,    -1,
      -1,    -1,    -1,    -1,    -1,  1897,  1898,  1899,  1900,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1196,    -1,    -1,    -1,    -1,    -1,  1202,    -1,    -1,    -1,
      -1,    -1,  1208,    -1,  1210,  1211,    -1,    -1,    -1,  1215,
    1216,    -1,  1218,    -1,  1220,    -1,  1222,    -1,  1224,  1225,
    1226,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,  1243,    -1,    94,
      95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,  1258,    12,    13,    -1,  1262,     8,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
    1559,    -1,   137,   138,   139,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,  1580,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1593,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    98,
      99,    -1,    -1,    -1,   103,    -1,    -1,  1353,    -1,    -1,
      -1,    -1,   207,    -1,    -1,  1634,    -1,     8,    -1,    -1,
    1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1655,     8,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   933,   934,    -1,    -1,    -1,    -1,   939,   940,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   958,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1433,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,  1450,    -1,    -1,   198,   207,   991,
     992,  1457,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,  1467,    -1,    -1,    -1,  1471,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,  1497,   103,    -1,    -1,    -1,    -1,    -1,    -1,  1778,
      -1,  1780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,  1554,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
    1849,  1112,  1113,    -1,    -1,    -1,  1117,  1118,    -1,    -1,
      -1,  1123,    -1,    -1,    -1,    -1,    -1,  1129,  1130,  1131,
    1132,  1133,     8,    -1,    -1,    -1,   207,  1139,  1140,    -1,
      -1,  1143,  1144,  1145,    -1,    -1,    -1,    -1,  1150,  1615,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1631,    -1,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,  1650,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,  1701,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,  1720,    59,    60,    61,    -1,    -1,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,  1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1298,    -1,    -1,    -1,
      -1,  1303,    -1,    -1,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,  1793,    -1,    -1,
      -1,  1333,  1334,    -1,    -1,  1337,  1338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,    -1,   203,
     204,    -1,   206,    -1,   208,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,  1884,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,  1460,  1461,
      55,    -1,  1464,  1465,    -1,    12,    13,    -1,  1470,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,     3,     4,   204,
      -1,   206,   207,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    12,
      13,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   117,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,    -1,   202,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,   159,    97,    98,    99,   163,    -1,    -1,
     103,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,   137,   138,   139,    -1,   204,    -1,
      -1,   207,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,   207,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,   168,   169,   170,
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
      -1,   114,    -1,    -1,   117,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
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
      -1,    -1,   167,   168,   169,   170,   171,   172,    -1,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,   159,   160,   161,   162,   163,    -1,    -1,   206,   167,
     168,   169,   170,   171,   172,    -1,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,     3,     4,     5,   204,    -1,   206,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    12,    13,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
      -1,     3,     4,     5,   204,    -1,   206,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,   207,    -1,    55,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,
       4,     5,   204,    -1,   206,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,   207,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    -1,    86,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,    -1,
     204,    -1,   206,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
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
      78,    -1,    -1,    81,     4,     5,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    -1,   172,    -1,   174,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
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
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,     5,
     204,    -1,   206,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,   159,   160,   161,   162,   163,   207,    -1,
      -1,   167,   168,   169,   170,   171,   172,    -1,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,     3,
       4,    -1,    -1,   199,    -1,     9,    10,    11,   204,    -1,
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
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,     3,     4,    -1,    -1,   199,    -1,     9,    10,    11,
     204,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
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
       4,   202,    -1,   204,    -1,     9,    10,    11,    -1,    -1,
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
     194,    -1,    -1,    -1,    -1,   199,   200,    -1,    -1,    -1,
     204,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,   159,    -1,    -1,   198,
     163,    -1,    -1,   202,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,     3,     4,   202,
       6,   204,    -1,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      66,    67,    68,    -1,     9,    10,    11,    -1,    74,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   207,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,     0,     1,    -1,   204,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    56,    57,    58,   199,    -1,    -1,    62,    63,   204,
      65,    -1,    -1,    -1,    69,    70,    -1,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,   124,
     125,     4,    -1,    -1,    -1,    -1,   131,    -1,    -1,    12,
      13,   136,   137,   138,   139,    -1,    -1,   142,    -1,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,    -1,    38,    39,    -1,    -1,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,   136,   137,   138,   139,    -1,    -1,   142,
      -1,   144,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     173,    -1,   175,   180,   181,   182,   183,   184,   185,   186,
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
      -1,    -1,    -1,   206,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
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
      -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   180,   181,   182,   183,   184,   185,   186,
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
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198
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
       4,     6,   288,   206,     6,   199,     6,   130,     6,   130,
       6,   130,     6,   130,   207,   278,   205,   277,     7,     6,
       7,     7,     7,     6,   206,     6,     6,     6,    84,     7,
       6,     6,   288,   203,   207,   288,   288,   288,   288,   207,
     207,   207,   207,   288,   207,   207,   294,   294,   294,     4,
     205,     8,     8,   200,     4,     4,   294,   207,   233,   233,
       6,   288,     6,   233,   233,     6,   288,     6,   234,     6,
       4,     6,   234,   234,   234,   234,   234,   205,   200,   200,
     200,   205,   205,   234,   243,   205,   234,   245,   200,   200,
     234,   234,   234,   304,   304,     6,   234,   304,   304,     7,
     231,   232,   203,     7,     6,   298,   288,   205,   207,   207,
     207,   207,   207,   231,   199,   288,   288,   293,   294,   206,
     203,     6,     6,   213,     6,   288,   206,   288,   302,     6,
       6,     6,   206,   206,    94,   251,   251,   294,     6,   206,
     206,     6,     6,   294,   206,     6,     6,     5,   294,   207,
     294,   294,     4,     6,   294,   294,   294,   294,   294,   294,
     294,   294,   206,   206,     7,     6,     7,   288,   288,   288,
     206,   206,   205,   207,   205,   207,   205,   207,   201,     6,
     288,   294,   288,     6,     6,     6,     6,   288,   291,   207,
       5,   206,   294,   206,   206,   206,   294,   297,   206,   288,
     202,     4,   234,   205,   205,   205,   205,   234,     6,     6,
     141,   288,   288,   288,     6,     6,     7,   205,     6,   234,
     304,   304,     6,   234,   304,   304,     6,   231,   232,   301,
     302,     4,     4,   156,     6,   234,   234,     6,   234,   234,
     302,   288,     6,     4,   299,     6,   202,   298,     6,     6,
       6,     6,   294,   217,   288,   205,   205,   205,   207,   218,
     288,     4,   301,   205,   294,   302,   288,   288,   291,     6,
       6,     6,   288,   288,     6,   288,     5,     6,   206,     6,
     145,   250,   288,     6,     6,     6,     6,     6,     6,     4,
       6,     6,   297,   297,   288,   288,   302,   207,   200,   205,
     207,   254,   254,   291,     6,   268,   291,     6,   269,   291,
       6,   270,   288,   207,   205,   200,   207,   205,     6,   190,
     291,     6,   293,   291,   291,     6,   207,   288,     6,     6,
     288,   288,   288,   288,   294,   205,   207,     8,   207,   200,
     206,   288,   302,   294,     6,   234,   234,     6,   234,   234,
     294,   200,   234,   206,   294,   302,   206,   288,   302,   302,
       6,     6,     6,     6,     6,     6,     7,     6,   203,     6,
     200,   205,   288,   288,   294,   206,   205,   207,     6,   288,
     238,   239,   207,   207,   207,   207,   207,     5,   293,    82,
       6,   206,   207,   207,   206,     6,     6,   206,   288,   207,
     207,   205,   206,   205,   206,   205,   206,   202,     6,   294,
       7,   206,   288,   205,   207,   205,   205,     6,   207,   205,
     205,   205,   205,   140,   288,   288,   297,     6,     6,   207,
       6,     6,     6,     6,     6,   241,   288,   304,   298,   143,
     221,   288,   205,   205,   293,   288,     6,   205,   242,   244,
       6,     6,     6,     6,     6,     6,   207,   206,   293,   105,
     106,   111,   283,   105,   106,   283,   297,   254,   205,   207,
     288,   291,   277,   288,   291,   277,   288,   291,   277,     6,
     205,   207,   294,   255,   207,   291,     6,   297,   291,   288,
     288,   288,   288,   288,   207,   207,   207,     6,   205,   207,
       7,   207,     6,   206,   288,   288,   207,   288,   207,   207,
     206,   288,   207,   206,   291,   294,     6,   206,   291,     6,
     207,   207,   288,   207,   205,   207,   207,   205,   207,   207,
     205,   207,   294,     6,   101,   207,   265,   206,   205,   207,
     205,   205,   205,   205,   205,     6,     6,   288,   302,   218,
     200,   205,     6,   206,   205,   288,   207,     6,   291,     6,
     291,     6,     6,   207,     6,   271,   288,     6,     6,   272,
     288,     6,     6,   273,   288,     6,   207,   288,   277,   255,
     297,     6,   291,   297,   288,   288,   288,   288,     7,   207,
     224,   288,   293,   288,   205,   205,   205,   206,   207,   206,
     207,   206,   207,     6,     6,   207,   207,   266,   207,   205,
     207,   205,   205,   205,   205,   302,     6,   206,   200,   207,
     207,   288,   291,   291,   277,     6,   274,   277,     6,   275,
     277,     6,   276,   277,     6,   297,     6,   288,   288,   288,
     288,   222,   301,   227,   206,     6,   207,   205,   205,   207,
     206,   207,   206,   207,   206,   207,   207,   205,   205,   205,
     205,   205,   207,   206,   293,     6,   288,   288,     6,   277,
       6,   277,     6,   277,     6,   288,   288,   288,   288,   301,
       6,   225,   301,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   205,   207,     6,     6,     6,     6,     6,
       6,   301,     6
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
     278,   278,   278,   278,   278,   278,   278,   278,   278,   279,
     279,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   285,   286,   286,
     286,   287,   287,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   290,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   291,   291,   291,   291,   291,   292,
     292,   292,   292,   293,   293,   294,   294,   294,   294,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   297,   297,   297,   297,   298,   298,   298,   298,   299,
     299,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   302,   304,   304,   305,
     305,   306,   306,   306
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
      18,     1,     2,     5,     7,     9,     2,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     9,     6,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     7,
       6,     8,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,    10,    10,    10,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       4,     6,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     5,     5,     3,     6,     4,     7,     6,
       6,     6,     6,     4,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     1,     2,     3,     3,     5,     4,     2,     2,
       2,     2,     3,     3,     3,     3,     5,     5,     5,     5,
      16,    16,    16,    16,     1,     1,     3,     3,     4,     6,
       6,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     4,     4,     3,
       6,     1,     4,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     4,
       6,     4,     1,     4,     4,     0,     6,     1,     3,     5,
       5,     1,     1,     4
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
#line 4664 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4688 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 225 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 241 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4794 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4812 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4829 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4846 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4873 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4891 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4908 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4925 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4944 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 377 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 393 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4966 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 400 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4978 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5086 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 519 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 528 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 535 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5132 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 570 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5177 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 588 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5199 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5219 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 642 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 674 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 679 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5341 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5407 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5426 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5459 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5492 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 822 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 827 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 832 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 837 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 842 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5539 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 849 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5550 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5583 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 917 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 922 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 927 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 932 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 940 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 949 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 955 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5680 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5696 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5712 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5730 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1019 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5757 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1025 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5766 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5782 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5798 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5816 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1089 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1095 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5854 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5876 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5898 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5911 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1161 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5942 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5966 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5990 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6005 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6017 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6043 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6070 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6100 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6122 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6138 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6154 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1376 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6186 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6206 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1403 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6225 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1419 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1427 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1433 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6268 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6283 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6301 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1487 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6324 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1504 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6347 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6364 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1530 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1534 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1540 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1548 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6399 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1552 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1558 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1566 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1570 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1576 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1584 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1588 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1594 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1602 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6480 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1618 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1622 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6510 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6537 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6584 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6608 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6630 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6655 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6677 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6711 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6745 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6767 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6789 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6819 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6841 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6863 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6910 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6932 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2040 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2046 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6995 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2052 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7006 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7035 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7064 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7085 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7108 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7145 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7192 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7214 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7235 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7255 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2325 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2330 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2335 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2340 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2345 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7347 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2373 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7384 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2389 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2390 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2395 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7416 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2399 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7424 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7451 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7478 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7505 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7532 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7557 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7587 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7611 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7636 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7660 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7776 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7799 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7841 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7948 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2897 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7971 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7990 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8022 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8038 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8051 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8064 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 3000 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8097 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8110 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8123 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8136 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8149 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8212 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8234 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8255 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8274 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8304 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8320 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3228 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3233 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3240 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3245 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3251 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3256 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8414 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3270 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3274 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3278 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8451 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8509 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8530 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8551 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8577 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8603 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8642 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8654 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8666 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3478 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3485 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8698 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8722 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8752 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3550 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8778 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8790 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8802 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8824 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3600 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8846 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8858 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8868 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3628 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8890 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3634 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3642 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8912 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3656 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3670 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3684 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8989 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3698 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3705 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9010 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3718 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9031 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3724 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3731 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3737 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3744 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3750 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9084 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3757 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3763 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3770 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3783 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3789 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3796 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9157 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3802 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9168 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3809 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3815 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3826 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3829 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9203 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9219 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9243 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3891 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3895 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3899 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 9294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3903 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3907 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3911 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3917 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3923 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3927 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3931 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3935 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3939 "Gmsh.y" /* yacc.c:1646  */
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
#line 9385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3958 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3970 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3974 "Gmsh.y" /* yacc.c:1646  */
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
#line 9422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3989 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 3993 "Gmsh.y" /* yacc.c:1646  */
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
#line 9448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4009 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4013 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9464 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4018 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4022 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4028 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9488 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4032 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4039 "Gmsh.y" /* yacc.c:1646  */
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
#line 9556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4095 "Gmsh.y" /* yacc.c:1646  */
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
#line 9630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4165 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4170 "Gmsh.y" /* yacc.c:1646  */
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
#line 9710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4237 "Gmsh.y" /* yacc.c:1646  */
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
#line 9750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4273 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4281 "Gmsh.y" /* yacc.c:1646  */
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
#line 9809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4324 "Gmsh.y" /* yacc.c:1646  */
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
#line 9852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4363 "Gmsh.y" /* yacc.c:1646  */
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
#line 9876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4384 "Gmsh.y" /* yacc.c:1646  */
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
#line 9911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4416 "Gmsh.y" /* yacc.c:1646  */
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
#line 9941 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4443 "Gmsh.y" /* yacc.c:1646  */
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
#line 9970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4469 "Gmsh.y" /* yacc.c:1646  */
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
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4495 "Gmsh.y" /* yacc.c:1646  */
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
#line 10028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4521 "Gmsh.y" /* yacc.c:1646  */
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
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4547 "Gmsh.y" /* yacc.c:1646  */
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
#line 10082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4568 "Gmsh.y" /* yacc.c:1646  */
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
#line 10114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4596 "Gmsh.y" /* yacc.c:1646  */
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
#line 10146 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
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
#line 10194 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
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
#line 10237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4699 "Gmsh.y" /* yacc.c:1646  */
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
#line 10280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
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
#line 10305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4759 "Gmsh.y" /* yacc.c:1646  */
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
#line 10330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4780 "Gmsh.y" /* yacc.c:1646  */
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
#line 10355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4807 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10363 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4811 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4821 "Gmsh.y" /* yacc.c:1646  */
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
#line 10411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4855 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10417 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4856 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4857 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4862 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10439 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4868 "Gmsh.y" /* yacc.c:1646  */
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
#line 10455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4880 "Gmsh.y" /* yacc.c:1646  */
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
#line 10477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4898 "Gmsh.y" /* yacc.c:1646  */
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
#line 10504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4926 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4927 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4928 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4929 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10534 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4930 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4931 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4932 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4934 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4940 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4941 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4942 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10581 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4943 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4944 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10593 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4947 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4948 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4949 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4950 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4951 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4952 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10641 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4953 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4954 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4955 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4956 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10665 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4957 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4958 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10677 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4959 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4960 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4961 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4962 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4963 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4964 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4965 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4966 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4967 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4968 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4969 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4970 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4971 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10755 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4972 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10767 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4983 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4984 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4987 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4988 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4989 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4991 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4996 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4998 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5014 "Gmsh.y" /* yacc.c:1646  */
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
#line 10882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5031 "Gmsh.y" /* yacc.c:1646  */
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
#line 10904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5049 "Gmsh.y" /* yacc.c:1646  */
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
#line 10926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5067 "Gmsh.y" /* yacc.c:1646  */
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
#line 10948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5085 "Gmsh.y" /* yacc.c:1646  */
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
#line 10970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5103 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5108 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10989 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5114 "Gmsh.y" /* yacc.c:1646  */
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
#line 11008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5129 "Gmsh.y" /* yacc.c:1646  */
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
#line 11029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5146 "Gmsh.y" /* yacc.c:1646  */
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
#line 11051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5164 "Gmsh.y" /* yacc.c:1646  */
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
#line 11073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5182 "Gmsh.y" /* yacc.c:1646  */
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
#line 11095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5200 "Gmsh.y" /* yacc.c:1646  */
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
#line 11117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5221 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5226 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5231 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5241 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5251 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5256 "Gmsh.y" /* yacc.c:1646  */
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
#line 11187 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5267 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5276 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5281 "Gmsh.y" /* yacc.c:1646  */
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
#line 11237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5308 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5312 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11253 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5316 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11261 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5320 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5324 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5335 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11301 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5343 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5350 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5355 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5362 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5371 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5376 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5399 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5403 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5415 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11417 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5423 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5431 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5438 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5448 "Gmsh.y" /* yacc.c:1646  */
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
#line 11487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5477 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5481 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5489 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5493 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11527 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5497 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5505 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11551 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5509 "Gmsh.y" /* yacc.c:1646  */
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
#line 11584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5538 "Gmsh.y" /* yacc.c:1646  */
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
#line 11617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5567 "Gmsh.y" /* yacc.c:1646  */
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
#line 11650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5596 "Gmsh.y" /* yacc.c:1646  */
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
#line 11683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5626 "Gmsh.y" /* yacc.c:1646  */
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
#line 11699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5639 "Gmsh.y" /* yacc.c:1646  */
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
#line 11715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5652 "Gmsh.y" /* yacc.c:1646  */
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
#line 11731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5665 "Gmsh.y" /* yacc.c:1646  */
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
#line 11747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5677 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5687 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5697 "Gmsh.y" /* yacc.c:1646  */
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
#line 5709 "Gmsh.y" /* yacc.c:1646  */
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
#line 11807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5722 "Gmsh.y" /* yacc.c:1646  */
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
#line 11823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5734 "Gmsh.y" /* yacc.c:1646  */
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
#line 11845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5752 "Gmsh.y" /* yacc.c:1646  */
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
#line 11867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5773 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5778 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11884 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5782 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5786 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5798 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5802 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5814 "Gmsh.y" /* yacc.c:1646  */
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
#line 11942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5831 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11953 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5841 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5845 "Gmsh.y" /* yacc.c:1646  */
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
#line 11977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5860 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5865 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5872 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12002 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5876 "Gmsh.y" /* yacc.c:1646  */
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
#line 12019 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5889 "Gmsh.y" /* yacc.c:1646  */
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
#line 12037 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5903 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12044 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5906 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5909 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5912 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5920 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5931 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5935 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12098 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5939 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5947 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5953 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5959 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5967 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5975 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12165 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5982 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5990 "Gmsh.y" /* yacc.c:1646  */
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
#line 12196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6005 "Gmsh.y" /* yacc.c:1646  */
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
#line 12214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6019 "Gmsh.y" /* yacc.c:1646  */
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
#line 12232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6033 "Gmsh.y" /* yacc.c:1646  */
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
#line 12248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6045 "Gmsh.y" /* yacc.c:1646  */
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
#line 12268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6061 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6070 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6079 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6089 "Gmsh.y" /* yacc.c:1646  */
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
#line 12323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6100 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6104 "Gmsh.y" /* yacc.c:1646  */
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
#line 12354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6123 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6130 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6136 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6143 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6150 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6152 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12415 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6163 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6168 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6174 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6183 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 6196 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 6199 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 6203 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12476 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6206 "Gmsh.y" /* yacc.c:1906  */


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
