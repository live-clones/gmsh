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

// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

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
    tGetEnv = 413,
    tGetString = 414,
    tGetNumber = 415,
    tHomology = 416,
    tCohomology = 417,
    tBetti = 418,
    tSetOrder = 419,
    tExists = 420,
    tFileExists = 421,
    tGMSH_MAJOR_VERSION = 422,
    tGMSH_MINOR_VERSION = 423,
    tGMSH_PATCH_VERSION = 424,
    tGmshExecutableName = 425,
    tSetPartition = 426,
    tNameFromString = 427,
    tStringFromName = 428,
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
#define YYLAST   10222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  521
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1841

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
       0,   196,   196,   197,   202,   204,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   227,   231,   238,   243,   248,   262,   275,   288,
     316,   330,   343,   356,   375,   380,   381,   382,   383,   384,
     388,   390,   395,   397,   403,   507,   402,   525,   532,   543,
     542,   560,   567,   578,   577,   594,   611,   634,   633,   647,
     648,   649,   650,   651,   655,   656,   662,   662,   663,   663,
     669,   670,   671,   676,   682,   742,   771,   800,   805,   810,
     815,   820,   827,   834,   849,   854,   859,   864,   869,   878,
     884,   893,   911,   929,   938,   950,   955,   963,   983,  1006,
    1017,  1025,  1047,  1070,  1096,  1117,  1129,  1143,  1143,  1145,
    1147,  1156,  1166,  1165,  1183,  1193,  1192,  1206,  1208,  1216,
    1222,  1229,  1230,  1234,  1245,  1260,  1270,  1271,  1276,  1284,
    1293,  1301,  1319,  1323,  1329,  1337,  1341,  1347,  1355,  1359,
    1365,  1373,  1377,  1383,  1392,  1395,  1408,  1411,  1421,  1444,
    1476,  1499,  1517,  1538,  1556,  1586,  1616,  1634,  1652,  1679,
    1697,  1715,  1750,  1768,  1807,  1813,  1819,  1826,  1851,  1876,
    1893,  1912,  1946,  1982,  2000,  2017,  2033,  2070,  2075,  2080,
    2085,  2090,  2095,  2118,  2124,  2135,  2136,  2141,  2144,  2148,
    2171,  2194,  2217,  2245,  2266,  2292,  2313,  2335,  2355,  2467,
    2486,  2524,  2633,  2642,  2648,  2663,  2691,  2708,  2717,  2731,
    2745,  2751,  2757,  2766,  2775,  2784,  2798,  2854,  2872,  2889,
    2904,  2923,  2935,  2959,  2963,  2968,  2975,  2980,  2986,  2991,
    2997,  3005,  3009,  3013,  3018,  3073,  3086,  3103,  3120,  3142,
    3164,  3199,  3207,  3215,  3221,  3228,  3235,  3255,  3281,  3293,
    3305,  3313,  3321,  3330,  3329,  3344,  3343,  3358,  3357,  3372,
    3371,  3385,  3392,  3399,  3406,  3413,  3420,  3427,  3434,  3441,
    3449,  3448,  3462,  3461,  3475,  3474,  3488,  3487,  3501,  3500,
    3514,  3513,  3527,  3526,  3540,  3539,  3553,  3552,  3569,  3572,
    3578,  3590,  3610,  3634,  3638,  3642,  3646,  3650,  3656,  3662,
    3666,  3670,  3674,  3678,  3697,  3710,  3713,  3729,  3732,  3749,
    3752,  3758,  3761,  3768,  3771,  3778,  3834,  3904,  3909,  3976,
    4012,  4020,  4063,  4102,  4122,  4154,  4181,  4207,  4233,  4259,
    4285,  4307,  4335,  4363,  4367,  4371,  4399,  4438,  4477,  4498,
    4519,  4546,  4550,  4560,  4595,  4596,  4597,  4601,  4607,  4619,
    4637,  4665,  4666,  4667,  4668,  4669,  4670,  4671,  4672,  4673,
    4680,  4681,  4682,  4683,  4684,  4685,  4686,  4687,  4688,  4689,
    4690,  4691,  4692,  4693,  4694,  4695,  4696,  4697,  4698,  4699,
    4700,  4701,  4702,  4703,  4704,  4705,  4706,  4707,  4708,  4709,
    4710,  4711,  4712,  4721,  4722,  4723,  4724,  4725,  4726,  4727,
    4728,  4729,  4730,  4731,  4736,  4735,  4743,  4748,  4765,  4783,
    4801,  4819,  4837,  4842,  4848,  4860,  4877,  4895,  4913,  4931,
    4952,  4957,  4962,  4972,  4982,  4987,  4998,  5007,  5012,  5039,
    5043,  5047,  5051,  5055,  5062,  5066,  5070,  5074,  5081,  5086,
    5093,  5098,  5102,  5107,  5111,  5119,  5130,  5134,  5146,  5154,
    5162,  5169,  5179,  5208,  5212,  5216,  5220,  5224,  5228,  5232,
    5236,  5240,  5269,  5298,  5327,  5356,  5369,  5382,  5395,  5408,
    5418,  5428,  5440,  5453,  5465,  5483,  5504,  5509,  5513,  5517,
    5529,  5533,  5545,  5552,  5562,  5566,  5581,  5586,  5593,  5597,
    5610,  5618,  5629,  5633,  5637,  5645,  5651,  5657,  5665,  5673,
    5680,  5695,  5709,  5723,  5735,  5751,  5760,  5769,  5779,  5790,
    5794,  5813,  5820,  5827,  5826,  5839,  5844,  5850,  5859,  5872,
    5875,  5879
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
  "tGetEnv", "tGetString", "tGetNumber", "tHomology", "tCohomology",
  "tBetti", "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameFromString", "tStringFromName", "tAFFECTPLUS",
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

#define YYPACT_NINF -1353

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1353)))

#define YYTABLE_NINF -492

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6971,    58,   100,  7091, -1353, -1353,  3482,    82,   -52,  -155,
     -70,    15,   147,   162,   178,   248,   -66,   252,   321,   -25,
       2,    78,    78,  -114,   -57,   153,    25,   161,   175,     1,
     185,   193,   320,   187,   387,   406,   273,   381,   461,   478,
     103,   402,   544,   285,    72,   360,   484,   -20,   376,   -65,
     -65,   379,   418,    29,   347,   482,   525,     8,    61,   533,
     536,   331,   595,   615,   633,  4824,   662,   428,   477,   494,
      19,    56, -1353,   502,   505, -1353, -1353,   669,   697,   507,
   -1353,  4921,  5297,     6,    34, -1353, -1353, -1353,  6831,  6831,
     523, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,    51, -1353,  -103,
     123, -1353,    36, -1353, -1353, -1353, -1353, -1353,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,   547,   554,   559,   567,   573,   581,    78,
      78,    78,    78,   591, -1353,    78, -1353, -1353, -1353, -1353,
   -1353,    78,    78,   726,   619,   622,   654,    78,   671,   677,
   -1353, -1353, -1353, -1353,   539,  6831,  6831,  6831,  6831,  6831,
      31,    14,    52,   580,   298,   462, -1353,   588,   806,   132,
     195,   878,  6831,  5101,  5101, -1353,  6831, -1353, -1353, -1353,
   -1353,  5101, -1353, -1353, -1353, -1353, -1353, -1353,  5490,    14,
    6831,  6641,  6831,  6831,   693,  6831,  6641,  6831,  6831,   711,
    6641,  6831,  6831,  5216,   717,   694, -1353,  6641,  4824,  4824,
    4824,   721,   736,  4824,  4824,  4824,   753,   763,   767,   771,
     772,   791,   805,   809,   705,  6196,   934,  5216,    19,   768,
     840,   -65,   -65,   -65,  6831,  6831,   -80, -1353,   -59,   -65,
     841,   859,   860,  6255,   -54,  -111,   868,   869,   895,  4824,
    4824,  5216,   896,    12,   780, -1353,   888,  1089,  1090, -1353,
     893,   898,   899,  4824,  4824,   906,   907,   908,   551, -1353,
     909,    -1,    17,    26,    27,   690,  5412,  6831,  3968, -1353,
   -1353,  3555, -1353,  1103, -1353,   164,    97,  1106,  6831,  6831,
    6831,   912,  6831,   911,   974,  6831,  6831,  6831, -1353, -1353,
    6831,   913,  1112,  1114, -1353, -1353,  1115, -1353,  1116, -1353,
     355,   741,  7786,  5101, -1353,  5216,  5216,  6831,  6831,   919,
     410,  5490, -1353, -1353, -1353, -1353, -1353, -1353,  5216,  1118,
     926,  6831,  6831,  1122,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831,  6831,  5101,  5101,  5101,  5101,
    5101,  5101,  5216,  5101,  5101,  6831,  5101,  5101,  5101,  5101,
    5101,  6831,  5490,  6831,  5101,  5101,  5101,  5101,    14,  5490,
      14,   932,   932,   932,  4528,  8904,   131,   928,  1123,    78,
     927, -1353,   931,  5652,  6831, -1353, -1353,  6641,    18, -1353,
    6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831, -1353, -1353,  6831,  6831, -1353,
   -1353,   830,     3,  -126, -1353, -1353,   120,  5015, -1353,   159,
     267,   305,   935,   937,  9249,  6641,  4109, -1353,   304,  9270,
    9291,  6831,  9312,   337,  9333,  9354,  6831,   452,  9375,  9396,
    1125,  6831,  6831,   520,  1129,  1131,  1135,  6831,  6831,  1136,
    1139,  1139,  6831,  6451,  6451,  6451,  6451,  6831,  6831,  6831,
    6641,  6641,  7813,   952,  1145,   950, -1353, -1353,   -62, -1353,
   -1353,  5211,  5407,   -65,   -65,    52,    52,   -26,  6831,  6831,
    6831,  6255,  6255,  6831,  5652,    91, -1353,  6831,  6831,  6831,
    6831,  6831,  1149,  1152,  1153,  6831,  1158,  6831,  6831,  1424,
   -1353, -1353,  6641,  6641,  6641,  1174,  1178,  6831,  6831,  6831,
    6831,  6831,  1182,   479,    14, -1353,  1133,  6831, -1353,  1134,
   -1353,  1137, -1353,  1138,    41,    42,    43,    46,  6641,   932,
   -1353,  9417, -1353,   586,  6831,  5608, -1353,  6831,  6831,   516,
   -1353,  9438,  9459,  9480,  1049,  5799, -1353,   989,  4130,  9501,
    9522,  8927, -1353, -1353, -1353,  1527, -1353,  1614,  6831, -1353,
   -1353,   997,  1001,   592,  9543,  8950,  6831,  6641,    18,  1196,
    1197, -1353,  6831,  9564,  8973,   514,  8881,  8881,  8881,  8881,
    8881,  8881,  8881,  8881,  8881,  8881,  8881,  5995,  8881,  8881,
    8881,  8881,  8881,  8881,  8881,  6250,  6636,  7867,   456,   577,
     456,  1009,  1010,  1006,  1011,  1012,  1013,  7893,   601,   601,
     601,   303,   601, 10026, -1353,   987,  1020,  1026,   330,   601,
    1027,  1032,  1031,   166,   108,  5490,  6831,  1226,  1229,    24,
     601, -1353,   106,    39,    30,   122, -1353,  6150,   610, -1353,
    5216,  4314,  1649,  1857,   236,   236,   572,   572,   572,   572,
     541,   541,   932,   932,   932,   932,    16,  9585,  8996, -1353,
    6831,  1234,    11,  6641,  1235,  6641,  6831,  1236,  5101,  1237,
   -1353,    14,  1238,  5101,  6831,  5490,  1233,  6641,  6641,  1102,
    1240,  1242,  9606,  1244,  1109,  1246,  1249,  9627,  1117,  1251,
    1256,  6831,  9648,  6191,  1060, -1353, -1353, -1353,  9669,  9690,
    6831,  5216,  1261,  1262,  9711,  1069, 10026,  1067,  1075, 10026,
    1071,  1077, 10026,  1074,  1080, 10026,  1076,  9732,  9753,  9774,
     620,   621,  6641,  1079, -1353, -1353,  2134,  2300,   -65,  6831,
    6831, -1353, -1353,  1078,  1082,  6255,  7919,  7945,  7971,  4819,
     562,   -65,  2347,  9795,  6347,  9816,  9837,  9858,  6831,  1275,
   -1353,  6831,  9879, -1353,  9019,  9042, -1353,   624,   625,   628,
   -1353, -1353,  9065,  9088,  7997,  9111,    97,  6641, -1353,  1084,
    1081,  6375,  1088,  1091,  1092, -1353,  6641, -1353,  6641, -1353,
    6641, -1353,  6641,   629, -1353, -1353,  4593,  6641,   932, -1353,
    6641, -1353,  1281,  1283,  1287,  1098,  6831,  2630,  6831,  6831,
   -1353, -1353,    48, -1353, -1353,  2723, -1353,  1097,  5216,  1276,
     166,   166,  6407,   639,  5216, -1353, -1353,  9134,    97,  1177,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  6831, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
    6831,  6831,  6831, -1353,  6641, -1353, -1353, -1353, -1353,  5101,
    5216,  5101,  5101,  5490, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  6831, -1353, -1353,  5101, -1353, -1353, -1353, -1353,
    6831,  1296,    59,  6831,  1297,  1299,  1292, -1353,  1300,  1107,
      19,  1302, -1353,  6641,  6641,  6641,  6641, -1353,   601,  1303,
    6831, -1353,  1119,  1127,  1111, -1353,  1305, -1353, -1353, -1353,
   -1353, -1353,    97,    97,  9157, -1353, -1353,  1143,  5101,   341,
   -1353,   435,  8023, -1353, -1353, -1353,  1315, -1353, -1353,  8881,
     601,   -65,  4109, -1353,   761,  5216,  5216,  1322,  5216,   765,
    5216,  5216,  1323,  1247,  5216,  5216,  1384,  1325,  1326,  6641,
    1327,  1330,  3692, -1353, -1353,  1333, -1353,  1334,    18,  6831,
      18,  6831,    18,  6831,    18,  6831,  1338,  1341,  1344,  1345,
    1354,   645,  1362,  2887, -1353, -1353,   125,  8049,  8075, -1353,
   -1353,  6579,  -118,   -65,   -65,   -65,  1363,  1367,  1164,  1368,
    1172,    38,    47,    55,    60,    -8, -1353,   134, -1353,   562,
    1369,  1371,  1373,  1374,  1375, 10026, -1353,  1403,  1171,  1380,
    1382,  1383,  1309,  6831,  1386,  1387,  6831,  -156,   649, -1353,
    6831, -1353,  6831,  6831,  6831,   655,   659,   660,   664, -1353,
    6831,   670,   680,  5216,  5216,  5216,  1391,  8101, -1353,  4762,
     336,  1393,  1394, -1353,  5216,  1195, -1353,  6831,  1395,  6831,
    1396, -1353,   601,  1397,  1402, -1353,  1410, -1353,  1409,  8881,
    8881,  8881,  8881,   583,  1213,  1219,  1223,  1224,  1220,   587,
     608,  9900,  1227,  1765, -1353,   172,  1225,  1417,  1808, -1353,
   -1353, -1353,    19,  6831, -1353,   688, -1353,   691,   692,   696,
     701,    18, -1353, 10026,  1230,  6831,  6831,  5216,  1228, -1353,
   -1353, -1353,  1232, -1353,  1423,    79,  1428,  6831,  3402,  1429,
    1432,    69,  1245,  1252,  1350,  1350,  5216,  1438,  1253,  1254,
    1444,  1445,  5216,  1255,  1449,  1454, -1353,  1425,  5216,   702,
    5216,  5216,  1457,  1456, -1353,  5216,  5216, 10026,  5216, 10026,
    5216, 10026,  5216, 10026,  5216,  5216,  5216,  1259,  1263,  1461,
     107, -1353,  6831,  6831,  6831,  1280,  1282,  -129,  -106,   -99,
    1288, -1353,  5216, -1353,  6831, -1353,  1479, -1353,  1484, -1353,
    1486, -1353,  1487, -1353, -1353,  6255,   616,  5020, -1353,  1290,
    1291,  5804, -1353,  6641, -1353, -1353, -1353,  1293,  2099, -1353,
   -1353,  9180,  1494,   601,  8127,  8153,  8179,  8205, -1353, -1353,
   -1353, -1353, 10026, -1353,   601,  1504,  1506,  1376, -1353,  6831,
    6831,  6831, -1353,  1507,   308,  1319,  1512,  2380, -1353,  2600,
   -1353,    18, -1353, -1353,   517, -1353, -1353, -1353, -1353, -1353,
   -1353,  5101, -1353, -1353, -1353,  5490,  1519, -1353, -1353,     9,
   -1353, -1353, -1353, -1353, -1353,  5490,  6831,  1518,  1523,    24,
   -1353,  1522,  9203,    19, -1353,  1525,  1526,  1528,  1529,  5216,
    6831,  8231,  8257,   712, -1353,  6831,  1532, -1353, -1353,  5101,
   -1353,  8283,  4171, 10026, -1353, -1353, -1353, -1353,  6831,  6831,
     -65,  1531,  1535,  1536, -1353,  6831,  6831, -1353, -1353,  1538,
    6831, -1353, -1353,  1524,  1542,  1346,  1545,  1413,  6831, -1353,
    1547,  1551,  1570,  1571,  1572,  1573,   930,  1589,  6641,  6641,
    6831, -1353,  6451,  6726,  9921,  3963,    52,    52,   -65,  1594,
     -65,  1595,   -65,  1607,  6831,   257,  1335,  9942, -1353, -1353,
   -1353, -1353,  6754,   148, -1353,  1610,  3753,  1611,  5216,   -65,
    3753,  1612,   738,  6831, -1353,  1615,    97, -1353,  6831,  6831,
    6831,  6831, -1353, -1353, -1353,  5216,  5742,   388,  9963, -1353,
   -1353,  4563,  5216, -1353, -1353, -1353,  5216, -1353,  1427,   601,
    4367,  4628,  5490,  1624,  2821, -1353,  1625,  1627, -1353,  1430,
   -1353, -1353, -1353, -1353, -1353,  1644,   470, 10026,  6831,  6831,
    5216,  1452,   743, 10026, -1353,  1647,  6831, -1353, -1353,  7086,
    7114,   268, -1353, -1353, -1353,  7142,  7170, -1353,  7198,  1652,
   -1353,  5216, -1353,  1578,  1653, 10026, -1353, -1353, -1353, -1353,
   -1353, -1353,  1462, -1353, -1353,   744,   751,  7840,  3139,  1654,
    1463, -1353,  6831, -1353,  1460,  1464,   165, -1353,  1466,   168,
   -1353,  1467,   246, -1353,  1468,  9226,  1655,  5216,  1661,  1470,
    6831, -1353,  6000,   263, -1353,   760,   277,   348, -1353,  1670,
    7226, -1353,  8309,  8335,  8361,  8387,  1539,  6831, -1353,  6831,
   -1353, -1353,  6641,  3187,  1673,  1475,  1675, -1353, -1353,  3968,
   -1353, -1353,  5101, 10026, -1353, -1353, -1353, -1353,    19, -1353,
    1541, -1353, -1353,  6831,  8413,  8439, -1353,  5216,  6831,  1677,
   -1353,  8465, -1353, -1353,  1678,  1679,  1680,  1681,  1683,  1696,
     770,  1499, -1353,  5216,   183,   486,  6641, -1353, -1353,    52,
    5938, -1353, -1353,  6255,   562,  6255,   562,  6255,   562,  1698,
   -1353,   775,  5216, -1353,  7254,   -65,  1699,  6641,   -65, -1353,
   -1353,  6831,  6831,  6831,  6831,  6831,  7282,  7310,   781, -1353,
   -1353,  1702, -1353,   782,  1458,   786,  1706, -1353,  1509, 10026,
    6831,  6831,   789, 10026, -1353,  6831,   792,   793, -1353, -1353,
   -1353, -1353, -1353, -1353,  1510,  6831,   796,  1513,   -65,  5216,
    1710,  1514,   -65,  1713,   819,  1521,  6831, -1353,  7338,   350,
     762,  7366,   362,   929,  7394,   394,  1086, -1353,  5216,  1721,
    1629,  3037,  1533,   398, -1353,   820,   400,  8491,  8517,  8543,
    8569,  3434, -1353, -1353,  1723, -1353,  6831, -1353,  5490, -1353,
   -1353,  6831,  9984,  8595,    35,  8621, -1353, -1353,  6831,  7422,
    1724,   -65,    74, -1353, -1353,   -65,    86, -1353,  1729, -1353,
    7450,  1730,  6831,  1737,  1747,  6831,  1748,  1749,  6831,  1759,
    1555, -1353,  6831, -1353,   562, -1353,  6641,  1763,  6000,  6831,
    6831,  6831,  6831, -1353, -1353,  3715, -1353,   826, -1353,  6831,
   -1353,  5216,  6831,  8647, -1353, -1353,   404, -1353,   429, -1353,
   -1353, -1353, -1353,  1566,  7478, -1353, -1353,  1568,  7506, -1353,
   -1353,  1576,  7534, -1353,  1768,  3513,  1194,  4026,   827, -1353,
     475,   831,  8673,  8699,  8725,  8751,  5490,  1769,  1577, 10005,
     832,  7562,  6831,   -65,   -65,   562,  1776,   562,  1777,   562,
    1778, -1353, -1353, -1353, -1353,   562,  1779,  6641,  1780,  6831,
    6831,  6831,  6831, -1353, -1353,  5101, -1353,  1583,  1783,  7590,
     506,   509,  1286, -1353,  1586,  1321, -1353,  1588,  1621, -1353,
    1590,  1754, -1353,   835, -1353,  8777,  8803,  8829,  8855,   838,
   -1353,  1591,  5216, -1353,  1787,  6831,  6831,  1791,   562,  1793,
     562,  1796,   562, -1353,  1797,  6831,  6831,  6831,  6831,  5101,
    1798,  5101,   854, -1353,  7618,  7646, -1353,  1971, -1353,  2139,
   -1353,  2210, -1353,  7674,  7702,  7730,  7758, -1353, -1353,   857,
   -1353,  1799,  1800,  1801,  1802,  1804,  1805, -1353, -1353, -1353,
   -1353,  5101,  1806, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,     0,   248,   249,     0,     0,     0,
     243,     0,     0,     0,     0,   344,   345,   346,     0,     0,
       0,     5,     7,     6,     8,     9,    10,    20,    11,    12,
      13,    14,    19,    18,    15,    16,    17,     0,    21,   520,
       0,   393,   519,   492,   394,   396,   397,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,     0,   512,   496,   401,   402,
     403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     398,   399,   400,   495,     0,     0,     0,     0,    66,    67,
       0,     0,   187,     0,     0,     0,   351,     0,   488,   520,
     407,     0,     0,     0,     0,   227,     0,   229,   230,   225,
     226,     0,   231,   232,   109,   117,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,     0,   187,   520,     0,     0,   341,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     470,   440,   446,     0,   441,   520,   407,     0,     0,     0,
       0,   482,     0,     0,     0,     0,     0,     0,   223,   224,
       0,   519,     0,     0,   241,   242,     0,   187,     0,   187,
     519,     0,     0,     0,   347,     0,     0,    66,    67,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   353,   355,     0,     0,     0,     0,     0,     0,
       0,   186,     0,   185,     0,    68,    69,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,   216,     0,     0,   415,
     164,     0,   519,     0,   488,   489,     0,     0,   515,     0,
     107,   107,     0,     0,     0,     0,   476,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   187,     0,   431,
     430,     0,     0,     0,     0,   187,   187,     0,     0,     0,
       0,     0,     0,     0,   259,     0,   187,     0,     0,     0,
       0,     0,   311,     0,     0,     0,     0,     0,     0,     0,
     205,   342,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    67,     0,     0,     0,   453,     0,     0,   454,     0,
     455,     0,   456,     0,     0,     0,     0,     0,     0,   353,
     448,     0,   442,     0,     0,     0,   319,    66,    67,     0,
     222,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,     0,   245,   244,   210,     0,   211,     0,     0,   235,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   513,     0,     0,     0,     0,     0,
       0,     0,     0,   352,     0,    59,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,   188,     0,     0,    59,
       0,     0,   369,   368,   366,   367,   362,   364,   363,   365,
     357,   356,   358,   359,   360,   361,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   340,     0,     0,
       0,     0,   307,     0,     0,     0,   132,   133,     0,   135,
     136,     0,   138,   139,     0,   141,   142,     0,     0,     0,
       0,     0,     0,     0,   152,   187,     0,     0,     0,     0,
       0,   433,   432,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,   206,     0,     0,   202,     0,     0,     0,
     337,   336,     0,     0,     0,     0,   420,     0,   471,     0,
       0,     0,     0,     0,     0,   457,     0,   458,     0,   459,
       0,   460,     0,     0,   352,   443,   450,     0,   358,   449,
       0,   472,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,   212,   214,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    74,     0,   409,   408,
     422,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     392,   380,     0,   382,   383,   384,   385,   386,   387,   388,
       0,     0,     0,   504,     0,   509,   500,   501,   502,     0,
       0,     0,     0,     0,   505,   506,   507,   428,   511,   121,
     126,    99,     0,   497,   499,     0,   406,   412,   413,   493,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     0,   414,     0,     0,     0,     0,   517,     0,     0,
       0,    44,     0,     0,     0,    57,     0,    35,    36,    37,
      38,    39,   411,   410,     0,   490,    24,    22,     0,     0,
      25,     0,     0,   217,   516,    70,   110,    71,   118,     0,
       0,     0,   478,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,   310,   308,     0,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,   215,     0,     0,     0,   177,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,     0,   250,     0,
       0,     0,     0,     0,     0,   312,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     0,   473,
       0,   452,     0,     0,     0,     0,     0,     0,     0,   444,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,     0,     0,   209,     0,     0,   348,     0,     0,     0,
       0,   518,     0,     0,     0,   417,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,    84,
      89,    91,     0,     0,   486,     0,    97,     0,     0,     0,
       0,     0,    75,   370,     0,     0,     0,     0,     0,    30,
     419,   418,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,   134,     0,   137,
       0,   140,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,   293,     0,   299,     0,   301,     0,   295,
       0,   297,     0,   260,   289,     0,     0,     0,   200,     0,
       0,     0,   323,     0,   204,   203,   343,     0,     0,    31,
      32,     0,     0,     0,     0,     0,     0,     0,   461,   462,
     463,   464,   451,   445,     0,     0,     0,     0,   483,     0,
       0,     0,   236,     0,     0,     0,     0,     0,    87,     0,
      86,     0,    76,   219,   421,   218,   381,   389,   390,   391,
     510,     0,   425,   426,   427,     0,     0,   405,   122,     0,
     514,   127,   424,   498,    78,    59,     0,     0,     0,     0,
      77,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   438,     0,     0,    26,    27,     0,
      28,     0,     0,   111,   114,    72,    73,   148,     0,     0,
       0,     0,     0,     0,   151,     0,     0,   167,   168,     0,
       0,   153,   174,     0,     0,     0,     0,   144,     0,   315,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,   187,   187,     0,   270,
       0,   272,     0,   274,     0,   440,     0,     0,   300,   302,
     296,   298,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,   421,   474,     0,     0,
       0,     0,   475,   156,   157,     0,     0,     0,     0,   100,
     104,     0,     0,   349,    80,    79,     0,   423,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,    95,     0,
     487,   189,   190,   191,   192,     0,     0,    40,     0,     0,
       0,     0,     0,    42,   491,     0,     0,   112,   115,     0,
       0,   147,   154,   155,   159,     0,     0,   169,     0,     0,
     317,     0,   162,     0,     0,   306,   173,   149,   161,   172,
     176,   160,     0,   170,   175,     0,     0,     0,     0,     0,
       0,   437,     0,   436,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,   198,     0,     0,     0,   193,     0,
       0,    33,     0,     0,     0,     0,     0,     0,   481,     0,
     238,   237,     0,     0,     0,     0,     0,   503,   508,     0,
     123,   125,     0,   128,   129,   130,    90,    92,     0,    98,
       0,    81,    45,     0,     0,     0,   439,     0,     0,     0,
      29,     0,   121,   126,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,   313,   313,     0,   105,   106,   187,
       0,   180,   181,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   187,     0,     0,     0,     0,     0,   184,
     183,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,    82,     0,   476,     0,     0,   485,     0,    41,
       0,     0,     0,    43,    58,     0,     0,     0,   331,   333,
     332,   334,   335,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,   255,     0,     0,   194,     0,     0,     0,     0,     0,
       0,     0,   480,   239,     0,   350,     0,   124,     0,   131,
      96,     0,     0,     0,     0,     0,   113,   116,     0,     0,
       0,     0,     0,   314,   324,     0,     0,   325,     0,   178,
       0,   276,     0,     0,   278,     0,     0,   280,     0,     0,
       0,   291,     0,   251,     0,   187,     0,     0,     0,     0,
       0,     0,     0,   158,   103,     0,   119,     0,    49,     0,
      55,     0,     0,     0,   145,   171,     0,   328,     0,   329,
     330,   434,   264,     0,     0,   271,   265,     0,     0,   273,
     266,     0,     0,   275,     0,     0,     0,   257,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,   284,     0,
     286,   292,   303,   256,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   120,    46,     0,    53,     0,     0,     0,
       0,     0,     0,   267,     0,     0,   268,     0,     0,   269,
       0,     0,   201,     0,   195,     0,     0,     0,     0,     0,
      47,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,     0,     0,   277,     0,   279,     0,
     281,     0,   196,     0,     0,     0,     0,    48,    50,     0,
      51,     0,     0,     0,     0,     0,     0,   465,   466,   467,
     468,     0,     0,    56,   326,   327,   283,   285,   287,    52,
      54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1353, -1353, -1353, -1353,   698, -1353, -1353, -1353, -1353,   174,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  -382,   -95,   949,  1549, -1353,  1365, -1353, -1353,
   -1353, -1353, -1353,   291, -1353,   294, -1353, -1353, -1353, -1353,
   -1353, -1353,   683,  1818,     7,  -497,  -256, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,  1821, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  -935,  -989,
   -1353, -1353,  1360, -1353,   290, -1353, -1353, -1353, -1353,  1546,
   -1353, -1353,     0, -1353, -1352,  2198,   401,  2392,   449,  -246,
     558, -1353,    21,    62, -1353,  -375,    -3,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    91,   938,    92,    93,   686,  1406,  1412,
     927,  1114,  1578,  1779,   928,  1728,  1819,   929,  1781,   930,
     931,  1118,   348,   439,   184,   418,    94,   701,   450,  1522,
    1523,   451,  1573,  1089,  1258,  1090,  1261,   735,   738,   741,
     744,  1434,  1301,   666,   299,   412,   413,    97,    98,    99,
     100,   101,   102,   103,   300,  1019,  1674,  1745,   770,  1458,
    1461,  1464,  1703,  1707,  1711,  1764,  1767,  1770,  1015,  1016,
    1153,   975,   732,   779,  1600,   105,   106,   107,   108,   301,
     186,   889,   500,   257,  1283,   302,   303,   304,   563,   313,
     911,  1105,   448,   444,   890,   449,   189,   306
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   628,   495,   630,   545,   219,  1475,   514,   763,   764,
      96,   326,   273,  1391,   641,   349,   526,   936,   321,   529,
     921,   195,   548,   311,   656,   669,  1194,   187,   909,   214,
     192,   550,   552,   265,   219,   406,   670,   346,   347,   328,
     350,  1690,   193,   214,  1185,  1212,   805,   807,   809,   256,
     258,   811,   264,  1187,   276,  1061,   410,   334,   503,   504,
     314,  1189,   305,  1095,     4,   278,  1191,   279,   188,   503,
     504,   585,   692,   587,  1338,  1297,  1339,   693,   276,  1530,
    1697,   503,   504,   210,  1196,  1288,   517,  1176,   503,   504,
     211,  1006,  1699,   518,   337,   191,   338,  1340,   110,  1341,
       5,   190,  1007,   339,  1342,   266,  1343,   503,   504,   267,
    1008,  1009,  1010,  1331,  1332,   669,  1011,  1012,  1013,  1014,
     248,   268,   252,   253,   505,   503,   504,   194,   503,   504,
     341,   201,   254,   503,   504,   249,   250,   280,   655,   255,
     212,   758,   546,   322,   325,   506,   922,   923,   924,   925,
     516,   244,   277,   197,   245,    48,    49,    50,    51,   274,
     549,   503,   504,  1392,    56,  1582,  1186,    59,   198,   551,
     553,   407,   408,   669,   204,  1188,   323,   765,   276,  1265,
      90,  1596,   233,  1190,   199,   234,    90,   235,  1192,   411,
     276,   276,   342,   343,   344,   345,   937,  1193,   276,  1096,
    1097,   205,   690,   547,   691,   220,   276,  1194,   305,   183,
     327,   527,   275,   305,   443,   446,   844,   305,   183,   196,
     305,   926,   215,   312,   305,   305,   305,   305,   910,   216,
     305,   305,   305,   351,   915,   352,   215,   353,   329,  1691,
     756,   757,   183,   914,   305,   806,   808,   810,   335,  1062,
     812,   498,   499,   315,   200,   336,   503,   504,   202,   507,
     772,   503,   504,   515,   937,   564,   305,   305,   305,   224,
     452,   900,   903,   503,   504,   206,   409,   207,   503,   504,
     305,   305,   342,   343,   344,   345,  1597,  1598,   445,   445,
     346,   347,  1599,   305,   771,   305,   445,   342,   343,   344,
     345,   346,   347,   210,   453,   342,   343,   344,   345,   902,
     913,   657,   503,   504,  1380,  1381,   346,   347,   694,   222,
     827,   503,   504,   695,   346,   347,   916,   203,  1172,   437,
     276,   438,   305,   305,   835,   503,   504,  1195,   339,  1730,
     342,   343,   344,   345,  1231,   305,   342,   343,   344,   345,
     213,  1470,   503,   504,   591,   503,   504,   697,   217,   346,
     347,   567,   698,   568,   241,   346,   347,   242,  1543,   243,
     339,  1545,   218,   276,   276,   276,   276,   276,   276,   305,
     276,   276,   221,   276,   276,   276,   276,   276,   346,   347,
     222,   276,   276,   276,   276,   276,  1489,   276,   629,  -489,
     631,   632,   633,   599,   635,   636,   223,   638,   639,   640,
     283,   642,   226,   284,   305,   646,   647,   648,   649,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   445,   269,
    1802,   270,   434,   503,   504,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   565,   432,   433,  1547,
     503,   504,   305,   434,   644,   503,   504,   228,  1067,  1069,
     229,   651,  1466,   230,   503,   504,  1555,   699,   419,   225,
     700,   445,   445,   445,   445,   445,   445,   227,   445,   445,
    1557,   445,   445,   445,   445,   445,   236,   305,   305,   445,
     445,   445,   445,   650,   260,   652,   415,   261,   416,   993,
     262,   887,   417,   761,   762,   702,   698,   708,   700,   709,
     850,   499,   411,   411,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   894,   305,
     305,   305,   434,   895,  1232,   503,   504,   503,   504,  1125,
     708,   276,   714,   231,   708,   737,   740,   743,   746,   503,
     504,  1558,   351,  1662,   588,   305,   542,   246,   901,   904,
     232,   183,   305,   247,   271,  1665,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     251,   503,   504,   259,   434,   503,   504,   503,   504,  1601,
    1602,   503,   504,  1490,   305,  1599,  1156,  1668,  1158,   285,
    1160,  1676,  1162,  1678,   272,   252,   253,  1733,   415,  1610,
     416,  1613,   281,  1616,   597,   254,   503,   504,   282,   286,
     237,  1194,   263,   238,  1194,   308,   239,  1194,   240,   474,
     475,   476,  1734,  1126,   479,   480,   481,   287,   708,   799,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   415,   708,   416,   718,   434,   698,
     458,  1006,   503,   504,  1104,   463,   307,   305,  1512,   467,
     522,   523,  1007,  1513,   309,   318,   473,   415,  1747,   416,
    1008,  1009,  1010,   797,   535,   536,  1011,  1012,  1013,  1014,
     305,   310,   305,   503,   504,   276,   503,   504,   276,   316,
     276,   850,   317,   319,   305,   305,   320,   346,   347,  1785,
     346,   347,  1786,  1266,   415,  1006,   416,   905,  -490,   944,
     820,  -491,   333,   708,   948,   724,  1007,  1194,   305,  1279,
     431,   432,   433,   393,  1008,  1009,  1010,   434,   400,  1716,
    1011,  1012,  1013,  1014,   379,  1068,  1070,   589,   540,   305,
     541,   380,   542,  1075,  1077,   182,   381,   183,   996,   429,
     430,   431,   432,   433,   382,  1002,   554,   950,   434,   555,
     383,  1017,   556,  1194,   557,   415,  1194,   416,   384,  1194,
     874,   415,  1194,   416,   414,   415,   708,   416,   389,   708,
    1256,   815,   435,   445,   305,   838,   946,   839,   445,   415,
    1762,   416,  1765,   305,  1768,   305,   415,   305,   416,   305,
    1771,  1259,   436,   708,   305,   918,   394,   305,  1194,   395,
    1194,  1354,  1194,   708,   708,   989,   990,   708,   708,  1031,
    1032,   708,   708,  1033,  1049,   305,   689,  1120,  1121,  1454,
    1455,   305,   708,  1132,  1072,  1133,   276,  1138,   708,  1139,
    1169,   396,   708,  1807,  1213,  1809,  1271,  1811,   708,  1386,
    1218,  1006,   708,   708,  1219,  1220,   668,   708,   398,  1221,
    1078,   305,  1007,   708,   399,  1223,   276,   305,   276,   276,
    1008,  1009,  1010,   708,   440,  1224,  1011,  1012,  1013,  1014,
     461,  1273,   276,  1274,   708,   708,  1275,  1276,   472,   708,
    1084,  1277,  1086,  1087,   708,   708,  1278,  1315,   466,   490,
     305,   305,   305,   305,   471,  1410,  1092,  1411,   477,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   478,  1442,   276,  1443,   434,   493,   750,
     751,   708,  1077,  1479,   445,  1088,  1518,   708,  1519,  1534,
     482,  1131,   305,   305,   708,   305,  1535,   305,   305,  1124,
     483,   305,   305,  1410,   484,  1556,   305,  1663,   485,   486,
     208,   209,   496,  1410,   445,  1594,   445,   445,  1618,   528,
    1619,   787,   788,   789,   708,  1636,  1634,  1637,   487,   698,
     445,  1639,  1410,   891,  1644,  1256,  1259,  1646,  1647,  1410,
    1267,  1650,   488,  1177,  1178,  1179,   489,   813,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   708,   708,  1658,  1677,   434,  1400,  1006,  1518,
     708,  1727,  1746,   445,   708,  1410,  1748,  1757,   708,  1007,
    1794,  1799,  1605,  1800,   497,   508,   843,  1008,  1009,  1010,
     305,   305,   305,  1011,  1012,  1013,  1014,  1410,   340,  1821,
    1831,   305,  1832,   509,   510,   519,   520,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   521,   525,   339,   530,   531,   532,   385,   386,
     387,   388,   533,   534,   390,   537,   538,   539,   544,   566,
     391,   392,   570,   574,   305,   576,   397,   577,   582,   183,
     583,   584,   586,   596,   601,   602,   605,  1575,   434,   658,
     659,   182,   721,   305,  1666,   725,   661,   726,   704,   305,
     705,   727,   939,   730,   941,   305,   731,   305,   305,  1387,
     753,   754,   305,   305,   755,   305,   778,   305,   780,   305,
     781,   305,   305,   305,   783,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   305,
     790,   442,   113,   434,   791,  1006,   796,   800,   802,   825,
    1294,   803,   804,   828,   305,  1353,  1007,   836,   305,   837,
     305,   991,   845,   846,  1008,  1009,  1010,   877,   878,   879,
    1011,  1012,  1013,  1014,   880,   881,   882,   140,   141,   142,
     143,   144,   145,   892,   893,   897,   149,   150,   151,   152,
     898,   899,   907,   908,   154,   155,   156,   543,   935,   157,
     951,   940,   943,   945,   947,   954,  1038,   955,   276,   956,
     162,   958,   959,   960,   569,  1045,   961,  1046,   964,  1047,
     963,  1048,  1576,   965,   969,   974,  1051,   978,   976,  1052,
     979,  1387,  1388,   980,   981,   982,   305,   983,   984,   985,
     992,  1026,  1066,   999,  1039,  1040,   276,  1000,  1053,   305,
    1054,  1669,  1042,  1006,  1055,  1043,  1044,  1621,  1101,  1056,
    1421,  1064,  1094,  1099,  1007,  1100,  1103,  1102,  1106,  1112,
    1415,  1119,  1008,  1009,  1010,  1117,  1115,  1389,  1011,  1012,
    1013,  1014,  1128,  1083,  1116,   305,   305,  1393,  1123,  1136,
    1142,  1143,  1147,  1148,  1150,   165,   166,  1151,  1456,  1154,
    1459,  1155,  1462,   411,   411,  1164,   445,   173,  1165,    90,
     174,  1166,  1167,   305,  1418,   305,  1473,   305,   660,  1476,
    1477,  1168,  1107,  1108,  1109,  1110,  1170,  1180,  1182,  1184,
     346,   347,   305,  1181,  1183,  1203,  1197,  1198,  1076,   305,
    1199,  1200,  1201,   305,   445,  1006,  1204,   305,  1205,  1206,
    1146,  1207,  1209,  1210,  1449,  1228,  1007,  1233,  1234,  1743,
    1236,  1238,  1240,  1242,  1008,  1009,  1010,   305,  1243,  1202,
    1011,  1012,  1013,  1014,  1244,  1245,  1251,  1252,  1149,  1717,
    1006,  1253,  1254,  1255,  1269,  1263,  1268,  1280,   305,  1287,
    1313,  1007,  1285,  1286,  1290,  1295,     7,     8,  1296,  1008,
    1009,  1010,  1300,  1494,  1304,  1011,  1012,  1013,  1014,  1298,
    1307,  1308,  1501,  1504,  1505,  1311,  1299,  1305,  1306,  1310,
    1312,  1318,  1319,  1328,   305,  1638,   564,  1329,  1330,   305,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,  1336,  1348,  1337,  1344,   434,   305,
    1349,  1787,  1350,  1351,  1358,  1359,   305,  1363,  1366,   276,
     662,    24,    25,   663,    27,    28,   664,    30,   665,    32,
    1373,    33,  1374,  1379,   305,  1375,    38,    39,  1383,    41,
      42,    43,  1382,  1390,  1395,    46,  1789,  1396,  1398,  1429,
     305,  1401,  1402,   305,  1403,  1404,  1414,  1422,  1467,     7,
       8,  1423,  1424,  1609,  1427,  1612,   411,  1615,  1430,   305,
    1431,  1432,   185,  1436,   305,  1623,  1433,  1437,  1626,    67,
      68,    69,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,  1438,  1439,  1440,  1441,
     434,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,  1444,   305,   445,  1652,   434,
    1457,  1460,  1656,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,  1463,    33,   305,  1471,  1474,  1478,    38,
      39,  1481,    41,    42,    43,  1497,     7,     8,    46,   786,
    1506,  1510,  1508,  1509,   331,   332,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   707,   432,   433,
    1511,  1696,  1362,  1520,   434,  1698,  1517,  1529,  1531,  1532,
    1538,  1550,    67,    68,    69,  1541,  1533,  1539,  1552,  1542,
    1544,  1546,  1548,   305,  1553,   305,  1559,  1565,  1720,  1570,
    1571,  1572,  1577,  1584,  1588,  1589,  1590,  1591,   305,  1592,
     662,    24,    25,   663,    27,    28,   664,    30,   665,    32,
    1686,    33,  1593,  1595,  1617,  1624,    38,    39,  1635,    41,
      42,    43,  1640,  1641,  1648,    46,  1654,  1651,  1655,  1657,
    1006,   401,   402,   403,   404,   405,  1659,  1671,  1672,  1684,
    1695,  1007,   833,  1760,  1761,  1700,  1702,  1675,   441,  1008,
    1009,  1010,   447,  1705,   305,  1011,  1012,  1013,  1014,    67,
      68,    69,   276,  1706,  1709,  1710,   454,   456,   459,   460,
    1714,   462,   456,   464,   465,  1713,   456,   468,   469,  1719,
    1735,  1264,  1737,   456,  1741,  1754,  1780,  1445,  1446,   305,
    1739,  1755,  1763,  1766,  1769,  1772,  1774,  1782,  1753,  1783,
    1788,   492,  1790,  1803,  1792,  1801,   276,  1806,   276,  1808,
     501,   502,  1810,  1812,  1818,  1833,  1834,  1835,  1836,   502,
    1837,  1838,  1840,  1586,  1270,  1687,   703,  1587,  1302,   834,
    1817,    95,  1820,  1289,   104,  1603,  1791,  1397,   276,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   733,   559,   561,   456,   434,     0,     0,     0,     0,
     445,     0,  1839,  1006,   571,   572,   573,     0,   575,     0,
       0,   578,   579,   580,  1007,     0,   581,     0,     0,     0,
       0,     0,  1008,  1009,  1010,     0,     0,     0,  1011,  1012,
    1013,  1014,     0,   594,   595,     0,     0,     0,     0,   598,
       0,     0,     0,     0,   445,     0,   445,   603,   604,     0,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,     0,     0,     0,     0,   445,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,   643,     0,   645,
       0,  1568,     0,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,  1793,
     667,   434,     0,   456,     0,     0,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,     0,     0,   687,   688,  1604,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,   559,     0,     0,   434,     0,  1625,   712,     0,     0,
       0,     0,   717,     0,     0,     0,     0,   722,   723,     0,
       0,     0,     0,   728,   729,     0,     0,     0,   734,   736,
     739,   742,   745,   747,   748,   749,   456,   456,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,   766,   767,   768,   401,   402,   769,
       0,     0,     0,   773,   774,   775,   776,   777,     0,     0,
    1006,   782,     0,   784,   785,     0,     0,     0,   456,   456,
     456,  1007,     0,   792,   793,   794,   603,   795,     0,  1008,
    1009,  1010,   798,   801,     0,  1011,  1012,  1013,  1014,     0,
       0,     0,     0,     0,   456,  1364,     0,     0,     0,     0,
     816,   818,     0,   687,   688,     0,     0,     0,   821,     0,
       0,     0,     0,     0,     0,  1718,     0,  1721,     0,     0,
       0,     0,     0,     0,   795,     0,     0,     0,     0,     0,
       0,     0,   842,   456,     0,     0,     7,     8,   847,     0,
       0,     0,     0,     0,     0,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   861,     0,   863,   864,   865,
     866,   867,   868,   869,     0,     0,  1824,   873,   875,   876,
       0,     0,     0,     0,     0,     0,     0,   884,   885,   886,
       0,   888,     0,     0,     0,     0,  1773,     0,   896,     0,
       0,     0,   906,     0,     0,     0,     0,     0,     0,   912,
     662,    24,    25,   663,    27,    28,   664,    30,   665,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,   934,     0,  1006,   456,
       0,   456,   942,     0,     0,     0,     0,     0,     0,  1007,
     949,     0,     0,   818,   952,     0,     0,  1008,  1009,  1010,
       0,     0,     0,  1011,  1012,  1013,  1014,   966,     0,    67,
      68,    69,     0,     0,     0,     0,   972,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,   456,     0,
       0,     0,     0,     0,     0,   997,   998,     0,     0,  1006,
       0,  1001,     7,     8,     0,     0,     0,     0,     0,     0,
    1007,     0,     0,     0,  1025,     0,     0,  1027,  1008,  1009,
    1010,     0,     0,     0,  1011,  1012,  1013,  1014,     0,   994,
       0,     0,     0,   456,  1825,     0,     0,     0,     0,     0,
       0,     0,   456,     0,   456,     0,   456,     0,   456,     7,
       8,     0,     0,   456,     0,     0,   456,     0,     0,     0,
       0,     0,  1057,     0,  1059,  1060,   662,    24,    25,   663,
      27,    28,   664,    30,   665,    32,  1384,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,  1079,     0,
       0,     0,     0,     0,     0,  1826,  1080,  1081,  1082,     0,
     456,   470,     0,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,    67,    68,    69,  1091,    38,
      39,     0,    41,    42,    43,   494,  1093,     0,    46,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   456,
     456,   456,   456,     0,     0,     0,  1113,  1111,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1129,  1130,
       0,     0,     0,     0,     0,   995,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,     0,  1159,     0,  1161,
       0,  1163,     0,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,     0,     0,     0,
       0,     0,  1018,     0,     0,     0,     0,     0,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,  1208,
     634,     0,  1211,     0,     0,     0,  1214,     0,  1215,  1216,
    1217,     0,     0,     0,     0,     0,  1222,     0,     0,     0,
       0,     0,     0,   457,     0,     0,  1385,     0,   457,     0,
       0,     0,   457,  1237,     0,  1239,     0,     0,     0,   457,
       0,  1241,     0,     0,     0,     0,     0,     0,  1246,  1247,
    1248,  1249,  1250,     0,     0,     0,     0,     0,  1257,  1260,
       0,     0,     7,     8,     0,     0,     0,     0,     0,  1272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1281,  1282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1291,  1293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   560,     0,
     457,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   662,    24,    25,   663,
      27,    28,   664,    30,   665,    32,     0,    33,  1333,  1334,
    1335,     0,    38,    39,     0,    41,    42,    43,  1345,     0,
    1347,    46,     0,     0,     0,     7,     8,     0,     0,     0,
       0,  1352,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1367,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,  1372,     0,  1376,  1377,  1378,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,   662,
      24,    25,   663,    27,    28,   664,    30,   665,    32,   457,
      33,     0,  1394,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,  1407,  1507,     0,     0,
       0,  1413,     0,     0,     0,  1058,     0,     0,     0,     0,
       0,     0,     0,     0,  1419,  1420,     0,   560,     0,     0,
       0,  1425,  1426,     0,     0,     0,  1428,     0,    67,    68,
      69,     0,     0,     0,  1435,     0,     0,     0,   919,     0,
       0,     0,     0,     0,   456,   456,  1447,     0,  1448,     0,
       0,     0,   457,   457,     0,     0,     0,     0,     0,     0,
    1465,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,   456,     0,     0,     0,   456,     0,     0,  1480,
       0,     0,     0,     0,  1482,  1483,  1484,  1485,     0,     0,
       0,     0,     0,     0,   457,   457,   457,  1493,  1063,   973,
       0,     0,     0,     0,     0,     0,     0,  1503,  1498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,     0,     0,  1514,  1515,     0,   819,     0,     0,
       0,     0,  1521,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   457,
       0,     0,     0,     0,     0,     0,     0,     0,  1540,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,  1554,   434,   559,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,  1566,     0,  1567,  1065,     0,   456,     0,
       0,     0,  1073,     0,     0,  1574,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,  1579,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1085,     0,
       0,     0,   456,     0,     0,   457,     0,   457,     0,  1608,
       0,  1611,  1171,  1614,     0,     0,     0,     0,     0,   819,
     953,     0,     0,   456,     0,     0,     0,  1627,  1628,  1629,
    1630,  1631,     0,   662,    24,    25,   663,    27,    28,   664,
      30,   665,    32,     0,    33,     0,  1642,  1643,     0,    38,
      39,  1645,    41,    42,    43,     0,     0,     0,    46,     0,
       0,  1649,     0,     0,   457,  1537,     0,     0,     0,     0,
       0,     0,  1660,  1134,  1135,     0,  1137,     0,  1140,  1141,
       0,     0,  1144,  1145,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,  1685,     0,     0,     0,     0,  1413,     0,   457,
       0,     0,     0,  1569,  1693,     0,     0,     0,   457,     0,
     457,     0,   457,     0,   457,     0,     0,     0,  1704,   457,
       0,  1708,   457,     0,  1712,     0,     0,     0,  1715,     0,
       0,     0,   456,     0,   456,  1722,  1723,  1724,  1725,     0,
       0,     0,     0,     0,     0,  1729,     0,     0,  1731,     0,
       0,     0,  1673,     0,     0,     0,     0,     0,     0,     0,
       0,  1225,  1226,  1227,     0,     0,     0,     0,     0,     0,
       0,     0,  1235,     0,     0,     0,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,     0,  1775,  1776,  1777,  1778,     0,
       0,     0,     0,     0,     0,   457,   457,   457,   457,     0,
       0,     0,     0,     0,     0,  1284,     0,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,  1804,  1805,     0,  1303,   434,     0,     0,     0,     0,
    1309,  1813,  1814,  1815,  1816,     0,  1314,     0,  1316,  1317,
       0,     0,     0,  1320,  1321,     0,  1322,     0,  1323,     0,
    1324,   457,  1325,  1326,  1327,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
    1346,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1357,     0,     0,     0,  1361,
       0,     0,     0,     0,     0,   111,   330,   113,     0,     0,
       0,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
    1683,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,   156,     0,     0,   157,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,   162,     0,  1405,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,     0,     0,
    1417,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,  1742,
       0,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,   154,
     155,   156,     0,     0,   157,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,   162,  1284,     0,     0,   164,
     165,   166,   167,   564,     0,     0,     0,   168,   169,   170,
     171,   172,   173,  1486,    90,   174,     0,     0,     0,     0,
    1495,     0,     0,     0,  1496,     0,     0,     0,  1500,   175,
     176,     0,     0,     0,   177,   457,     0,     0,     0,   297,
       0,     0,     0,     0,   181,     0,  1292,     0,  1516,     0,
       0,     0,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,  1284,
     434,     0,     0,   163,     0,     0,     0,     0,     0,   164,
     165,   166,   167,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,    90,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1551,     0,     0,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   178,
       0,   179,     0,   180,   181,     0,   182,     0,   183,     0,
       0,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,  1284,     0,     0,     0,     0,
     457,   457,  1726,     0,     0,     0,     0,     0,     0,     0,
       0,  1284,     0,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   565,   432,   433,     0,   457,     0,
    1620,   434,   457,     0,     0,     0,   111,   288,     0,     0,
       0,     0,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     290,  1152,     0,     0,     0,     0,     0,  1653,     0,   146,
     147,   148,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1670,   158,   159,   160,
       0,     0,     0,     0,     0,   161,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,   560,    56,     0,     0,    59,     0,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   457,     0,     0,     0,   434,  1284,
       0,   457,     0,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
     164,   434,     0,   167,     0,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,    90,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,  1472,     0,     0,     0,   177,     0,     0,     0,   457,
     513,     0,     0,     0,     0,   181,     0,   255,   562,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   288,     0,     0,     0,     0,   114,   115,   116,
    1284,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   290,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,   160,     0,     0,     0,     7,     8,
     161,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,   457,     0,
     457,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   662,    24,    25,   663,    27,    28,   664,    30,
     665,    32,     0,    33,     0,     0,     0,   564,    38,    39,
       0,    41,    42,    43,     0,   164,     0,    46,   167,     0,
       0,     0,     0,   168,   169,   170,   171,   172,   829,   457,
      90,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   175,   455,     0,     0,   434,
     177,    67,    68,    69,     0,   297,  1452,     0,  1453,     0,
     181,     0,     0,   562,   111,   288,   113,     0,     0,     0,
     114,   115,   116,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   290,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,     0,   154,   155,
     156,  1744,     0,   157,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   162,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   707,   432,
     433,     0,     0,     0,     0,   434,     0,     0,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   920,     0,     0,     0,   434,     0,   164,   165,
     166,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,   173,     0,    90,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   296,
       0,     0,     0,   177,     0,     0,     0,     0,   297,     0,
     111,   288,   113,   181,     0,   298,   114,   115,   116,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   290,     0,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,     0,   154,   155,   156,     0,     0,   157,
       0,   158,   159,   160,     0,     0,     0,     0,     0,   161,
     162,     0,     0,   291,     0,     0,   292,     0,     0,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,     0,     0,
       0,     0,   168,   169,   170,   171,   172,   173,     0,    90,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   296,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,   111,   330,   113,   181,
       0,  1499,   114,   115,   116,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,  1050,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
     154,   155,   156,     0,     0,   157,     0,   158,   159,   160,
       0,   111,   330,   113,     0,   161,   162,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,   154,   155,   156,     0,     0,
     157,     0,   158,   159,   160,     0,     0,     0,     0,     0,
     161,   162,     0,     0,     0,     0,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     164,   165,   166,   167,   434,     0,   653,     0,   168,   169,
     170,   171,   172,   173,     0,    90,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   176,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   181,     0,  1492,     0,     0,
    1230,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   164,   165,   166,   167,   434,
       0,     0,     0,   168,   169,   170,   171,   172,   173,     0,
      90,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   176,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   111,   288,   289,
     181,     0,  1502,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   290,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
     160,     0,     0,     0,     0,     0,   161,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,   321,   113,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     149,   150,   151,   152,     0,     0,     0,     0,   154,   155,
     156,   164,     0,   157,   167,     0,     0,     0,     0,   168,
     169,   170,   171,   172,   162,     0,    90,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   175,   296,     0,     0,   434,   177,   814,     0,     0,
       0,   297,   759,   111,   288,  1355,   181,     0,   298,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   290,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,   165,
     166,     0,     0,     0,   158,   159,   160,     0,     0,     0,
       0,   173,   161,    90,   174,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,   442,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,     0,     0,     0,
       0,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     149,   150,   151,   152,     0,     0,     0,     0,   154,   155,
     156,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,   164,     0,     0,
     167,     0,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,    90,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   175,   296,     0,
       0,   434,   177,     0,     0,     0,     0,   297,   696,   111,
     288,     0,   181,     0,  1356,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   290,     0,     0,     0,     0,     0,   165,
     166,     0,   146,   147,   148,     0,     0,     0,     0,   153,
       0,   173,     0,    90,   174,     0,     0,     0,     0,     0,
     158,   159,   160,     0,     0,     0,     0,     0,   161,     0,
       0,     0,   291,     0,     0,   292,     0,     0,   293,     0,
     294,   324,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,     0,   140,   141,   142,
     143,   144,   145,     0,     0,     0,   149,   150,   151,   152,
       0,     0,     0,     0,   154,   155,   156,     0,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,   164,     0,     0,   167,     0,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,    90,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   175,   296,     0,     0,   434,   177,     0,
       0,     0,     0,   297,   759,   111,   288,     0,   181,     0,
     298,   114,   115,   116,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   290,
       0,     0,     0,     0,     0,   165,   166,     0,   146,   147,
     148,     0,     0,     0,     0,   153,     0,   173,     0,     0,
     174,     0,     0,     0,     0,     0,   158,   159,   160,     0,
       0,     0,     0,     0,   161,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,   113,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   149,
     150,   151,   152,     0,     0,     0,     0,   154,   155,   156,
       0,     0,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,   164,
       0,     0,   167,     0,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,    90,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   175,
     455,     0,     0,   434,   177,     0,     0,     0,     0,   297,
     760,   111,   288,     0,   181,     0,   558,   114,   115,   116,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   290,     0,     0,   165,   166,
       0,     0,     0,     0,   146,   147,   148,     0,     0,     0,
     173,   153,     0,   174,     7,     8,     0,     0,     0,     0,
       0,     0,   158,   159,   160,     0,     0,     0,     0,     0,
     161,     0,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,   662,    24,
      25,   663,    27,    28,   664,    30,   665,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,   167,     0,
       0,     0,     0,   168,   169,   170,   171,   172,     0,     0,
      90,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,   175,   455,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   111,   288,     0,
     181,     0,   817,   114,   115,   116,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   290,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
     160,     0,     0,     0,     0,     0,   161,     0,     0,     0,
     291,     0,     0,   292,     0,     0,   293,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,  1487,     0,  1488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,     0,     0,   167,     0,     0,     0,     0,   168,
     169,   170,   171,   172,     0,     0,    90,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   175,   296,     0,     0,   434,   177,     0,     0,     0,
       0,   297,   826,   111,   288,     0,   181,     0,  1360,   114,
     115,   116,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   290,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,   159,   160,     0,     0,     0,
       0,     0,   161,     0,     0,     0,   291,     0,     0,   292,
       0,     0,   293,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,  1606,     0,  1607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,     0,
     167,     0,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,    90,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   511,  1472,     0,
       0,   434,   177,     0,     0,     0,     0,   513,   862,   111,
     330,     0,   181,     0,   255,   114,   115,   116,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   330,
     158,   159,   160,     0,   114,   115,   116,     0,   161,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,   160,     0,     0,     0,     0,     0,   161,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,   164,     0,   917,   167,     0,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,    90,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   175,   176,     0,     0,   434,   177,     0,
       0,     0,     0,   297,     0,     0,   968,     0,   181,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,   167,     0,     0,     0,     0,
     168,   169,   170,   171,   172,     0,     0,    90,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   511,   512,     0,     0,   434,   177,     0,     0,
       0,     0,   513,   870,   111,   330,   113,   181,     0,   255,
     114,   115,   116,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,     0,   154,   155,
     156,     0,     0,   157,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   162,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
       0,     0,  1021,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
    1041,     0,     0,     0,     0,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,   164,   165,
     166,   167,  1071,     0,     0,     0,   168,   169,   170,   171,
     172,   173,     0,    90,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,   177,   111,   288,     0,     0,   297,     0,
     114,   115,   116,   181,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,     0,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,     0,     0,  1175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,    90,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   175,   455,
       0,     0,   434,   177,   111,   330,     0,     0,   297,   871,
     114,   115,   116,   181,     0,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,   160,     0,     0,
       0,     0,     0,   161,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1450,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,   164,     0,
       0,   167,     0,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,    90,     0,     0,     0,     0,     0,    -4,
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
      10,     0,    -4,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,    11,    12,    13,     0,     0,
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
       0,     0,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,    89,    90,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1524,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1525,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1526,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1527,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1528,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1560,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1622,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1632,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1633,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1661,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1664,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1667,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1694,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1701,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1736,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1738,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1740,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1758,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1784,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1822,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,  1823,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,  1827,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,     0,  1828,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,  1829,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,  1830,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
     590,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,   752,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,  1536,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
     872,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,   883,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1003,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1004,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1005,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1036,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1127,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1173,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1174,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1229,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1368,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1369,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1370,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1371,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1408,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1409,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1416,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1561,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1562,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1563,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1564,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1580,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1581,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1585,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1679,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1680,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1681,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1682,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1689,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1692,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1732,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1749,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1750,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1751,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,     0,     0,     0,  1752,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,     0,     0,     0,
    1795,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,  1796,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,     0,
       0,     0,  1797,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,  1798,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   415,
       0,   416,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,   654,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,   832,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
     841,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,   849,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,   933,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,     0,     0,  1029,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
       0,     0,  1030,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,     0,     0,  1034,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,     0,     0,  1035,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,     0,
       0,  1037,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,     0,     0,  1074,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,     0,     0,  1122,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,     0,     0,
    1365,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,     0,     0,  1399,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,     0,     0,  1549,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,   706,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,   710,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   711,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
     713,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   715,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   716,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   719,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,   720,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,   814,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,   822,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,   823,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,   824,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   830,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
     831,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   840,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   848,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,   932,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,   957,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,   962,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,   967,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,   970,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,   971,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,   977,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
     986,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,   987,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,   988,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,  1020,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434,     0,  1022,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,     0,
       0,     0,     0,   434,     0,  1023,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
       0,     0,     0,     0,   434,     0,  1024,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,     0,     0,     0,     0,   434,     0,  1028,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,     0,     0,     0,     0,   434,     0,  1262,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,     0,     0,     0,     0,   434,     0,  1451,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,     0,     0,     0,     0,   434,     0,
    1468,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,     0,     0,     0,     0,   434,
       0,  1491,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,     0,     0,     0,     0,
     434,     0,  1688,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,     0,     0,     0,
       0,   434,     0,  1756,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,     0,     0,
       0,     0,   434
};

static const yytype_int16 yycheck[] =
{
       3,   376,   248,   378,     5,     4,  1358,   263,   505,   506,
       3,     5,     4,     4,   389,   110,     4,     6,     4,   275,
       4,     6,     5,     4,   406,     7,  1015,     6,     4,     4,
      82,     5,     5,     4,     4,     4,   418,   193,   194,     5,
       4,     6,   197,     4,     6,   201,     5,     5,     5,    49,
      50,     5,    52,     6,    57,     7,     4,     6,   187,   188,
       4,     6,    65,     4,     6,     4,     6,     6,     6,   187,
     188,   327,   198,   329,   203,     6,   205,   203,    81,  1431,
       6,   187,   188,   197,  1019,     6,   197,   205,   187,   188,
     204,    99,     6,   204,   197,    13,   199,   203,     3,   205,
       0,     6,   110,   206,   203,    76,   205,   187,   188,    80,
     118,   119,   120,     6,     7,     7,   124,   125,   126,   127,
     140,    92,   187,   188,   204,   187,   188,   197,   187,   188,
       7,   197,   197,   187,   188,   155,   156,    76,     7,   204,
     197,   203,   143,    81,    82,   204,   130,   131,   132,   133,
     204,    79,    57,     6,    82,   103,   104,   105,   106,   151,
     143,   187,   188,   154,   112,  1517,   128,   115,     6,   143,
     143,   140,   141,     7,   199,   128,    81,   203,   181,     7,
     172,  1533,    79,   128,     6,    82,   172,    84,   128,   182,
     193,   194,   174,   175,   176,   177,   185,   205,   201,   140,
     141,   199,   199,   204,   201,   204,   209,  1196,   211,   206,
     204,   199,   204,   216,   193,   194,   598,   220,   206,   204,
     223,   205,   197,   204,   227,   228,   229,   230,   204,   204,
     233,   234,   235,   197,   204,   199,   197,   201,   204,   204,
     496,   497,   206,   204,   247,   204,   204,   204,   197,   201,
     204,   251,   252,   197,     6,   204,   187,   188,     6,   259,
     516,   187,   188,   263,   185,     8,   269,   270,   271,    82,
     208,   653,   654,   187,   188,   197,   181,   199,   187,   188,
     283,   284,   174,   175,   176,   177,   103,   104,   193,   194,
     193,   194,   109,   296,   203,   298,   201,   174,   175,   176,
     177,   193,   194,   197,   209,   174,   175,   176,   177,   201,
     204,   406,   187,   188,     6,     7,   193,   194,   198,   197,
     576,   187,   188,   203,   193,   194,   204,     6,   203,   197,
     333,   199,   335,   336,   590,   187,   188,   203,   206,  1691,
     174,   175,   176,   177,     8,   348,   174,   175,   176,   177,
     197,   203,   187,   188,   333,   187,   188,   198,   197,   193,
     194,   197,   203,   199,    79,   193,   194,    82,   203,    84,
     206,   203,   197,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   197,   386,   387,   388,   389,   390,   193,   194,
     197,   394,   395,   396,   397,   398,     8,   400,   377,   204,
     379,   380,   381,   341,   383,   384,    86,   386,   387,   388,
      79,   390,     6,    82,   417,   394,   395,   396,   397,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   333,    82,
    1782,    84,   196,   187,   188,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   203,
     187,   188,   455,   196,   392,   187,   188,    76,   840,   841,
      79,   399,   205,    82,   187,   188,   203,   200,     6,    82,
     203,   376,   377,   378,   379,   380,   381,   204,   383,   384,
     203,   386,   387,   388,   389,   390,    84,   490,   491,   394,
     395,   396,   397,   398,    76,   400,   198,    79,   200,   755,
      82,   198,   204,   503,   504,   200,   203,   203,   203,   205,
     605,   511,   505,   506,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   198,   532,
     533,   534,   196,   203,   198,   187,   188,   187,   188,   198,
     203,   544,   205,    82,   203,   483,   484,   485,   486,   187,
     188,   203,   197,   203,   199,   558,   201,   197,   653,   654,
      82,   206,   565,    79,    82,   203,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     204,   187,   188,   204,   196,   187,   188,   187,   188,   103,
     104,   187,   188,   205,   597,   109,   978,   203,   980,     4,
     982,   203,   984,   203,    79,   187,   188,   203,   198,  1544,
     200,  1546,    79,  1548,   204,   197,   187,   188,    82,     4,
      76,  1610,   204,    79,  1613,   197,    82,  1616,    84,   228,
     229,   230,   203,   198,   233,   234,   235,     4,   203,   544,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   198,   203,   200,   205,   196,   203,
     211,    99,   187,   188,   910,   216,     4,   670,   198,   220,
     269,   270,   110,   203,   197,     6,   227,   198,   203,   200,
     118,   119,   120,   204,   283,   284,   124,   125,   126,   127,
     693,   197,   695,   187,   188,   698,   187,   188,   701,   197,
     703,   796,   197,     6,   707,   708,   199,   193,   194,   203,
     193,   194,   203,  1095,   198,    99,   200,   655,   204,   698,
     204,   204,   199,   203,   703,   205,   110,  1716,   731,  1111,
     189,   190,   191,     7,   118,   119,   120,   196,   199,  1674,
     124,   125,   126,   127,   197,   840,   841,     6,   197,   752,
     199,   197,   201,   848,   849,   204,   197,   206,   758,   187,
     188,   189,   190,   191,   197,   765,    76,   705,   196,    79,
     197,   771,    82,  1762,    84,   198,  1765,   200,   197,  1768,
     203,   198,  1771,   200,   204,   198,   203,   200,   197,   203,
     203,   205,   204,   698,   797,   203,   701,   205,   703,   198,
    1735,   200,  1737,   806,  1739,   808,   198,   810,   200,   812,
    1745,   203,     6,   203,   817,   205,   197,   820,  1807,   197,
    1809,   205,  1811,   203,   203,   205,   205,   203,   203,   205,
     205,   203,   203,   205,   205,   838,     6,   932,   933,  1336,
    1337,   844,   203,    82,   205,    84,   849,    82,   203,    84,
     205,   197,   203,  1788,   205,  1790,  1102,  1792,   203,  1241,
     205,    99,   203,   203,   205,   205,   417,   203,   197,   205,
     849,   874,   110,   203,   197,   205,   879,   880,   881,   882,
     118,   119,   120,   203,     6,   205,   124,   125,   126,   127,
     197,   203,   895,   205,   203,   203,   205,   205,   204,   203,
     879,   205,   881,   882,   203,   203,   205,   205,   197,   204,
     913,   914,   915,   916,   197,   203,   895,   205,   197,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   197,     4,   938,     6,   196,     4,   490,
     491,   203,  1037,   205,   849,   883,   203,   203,   205,   205,
     197,   951,   955,   956,   203,   958,   205,   960,   961,   938,
     197,   964,   965,   203,   197,   205,   969,   205,   197,   197,
      21,    22,   204,   203,   879,   205,   881,   882,   203,   199,
     205,   532,   533,   534,   203,   203,   205,   205,   197,   203,
     895,   205,   203,     6,   205,   203,   203,   205,   205,   203,
    1095,   205,   197,  1003,  1004,  1005,   197,   558,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   203,   203,   205,   205,   196,  1273,    99,   203,
     203,   205,   205,   938,   203,   203,   205,   205,   203,   110,
     205,   203,  1539,   205,   204,   204,   597,   118,   119,   120,
    1053,  1054,  1055,   124,   125,   126,   127,   203,   109,   205,
     203,  1064,   205,   204,   204,   197,   197,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   197,   197,   206,     6,     6,   204,   149,   150,
     151,   152,   204,   204,   155,   199,   199,   199,   199,     6,
     161,   162,     6,   201,  1117,   204,   167,   143,     6,   206,
       6,     6,     6,   204,     6,   199,     4,  1502,   196,   201,
       7,   204,     7,  1136,   205,     6,   205,     6,   203,  1142,
     203,     6,   693,     7,   695,  1148,     7,  1150,  1151,  1244,
     198,     6,  1155,  1156,   204,  1158,     7,  1160,     6,  1162,
       7,  1164,  1165,  1166,     6,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,  1182,
       6,     4,     5,   196,     6,    99,     4,    54,    54,   140,
    1128,    54,    54,   204,  1197,  1195,   110,   200,  1201,   198,
    1203,   752,     6,     6,   118,   119,   120,   198,   198,   203,
     124,   125,   126,   127,   203,   203,   203,    40,    41,    42,
      43,    44,    45,   203,   198,   198,    49,    50,    51,    52,
     198,   200,     6,     4,    57,    58,    59,   288,     4,    62,
       7,     6,     6,     6,     6,   143,   797,     7,  1251,     7,
      73,     7,   143,     7,   305,   806,     7,   808,     7,   810,
     143,   812,  1508,     7,   204,     4,   817,   198,     6,   820,
     203,  1366,  1251,   198,   203,   198,  1279,   203,   198,   203,
     201,     6,     6,   205,   200,   204,  1289,   205,     7,  1292,
       7,   205,   204,    99,     7,   204,   204,  1553,     6,   201,
    1300,   204,     6,     6,   110,     6,   199,     7,     6,     6,
    1289,     6,   118,   119,   120,   204,   197,  1255,   124,   125,
     126,   127,     7,   874,   197,  1328,  1329,  1265,   185,     7,
       7,    84,     7,     7,     7,   158,   159,     7,  1338,     6,
    1340,     7,  1342,  1336,  1337,     7,  1251,   170,     7,   172,
     173,     7,     7,  1356,  1292,  1358,  1356,  1360,   409,  1359,
    1360,     7,   913,   914,   915,   916,     4,     4,   204,   197,
     193,   194,  1375,     6,     6,   204,     7,     6,   201,  1382,
       7,     7,     7,  1386,  1289,    99,     6,  1390,     6,     6,
       6,    82,     6,     6,  1332,     4,   110,     4,     4,   205,
     205,     6,     6,     6,   118,   119,   120,  1410,     6,     6,
     124,   125,   126,   127,     4,     6,   203,   198,   969,  1675,
      99,   198,   198,   203,     7,   198,   201,   197,  1431,     6,
       5,   110,   204,   201,     6,     6,    12,    13,     6,   118,
     119,   120,    92,  1381,     6,   124,   125,   126,   127,   204,
       6,     6,  1390,  1391,  1392,     6,   204,   204,   204,   204,
       6,     4,     6,   204,  1467,     7,     8,   204,     7,  1472,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   204,     6,   204,   199,   196,  1492,
       6,   205,     6,     6,   204,   204,  1499,   204,     4,  1502,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       6,    87,     6,     6,  1517,   139,    92,    93,     6,    95,
      96,    97,   203,     4,     6,   101,   205,     4,     6,     5,
    1533,     6,     6,  1536,     6,     6,     4,     6,   203,    12,
      13,     6,     6,  1543,     6,  1545,  1539,  1547,     6,  1552,
     204,     6,     6,     6,  1557,  1555,   143,     6,  1558,   135,
     136,   137,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     6,     6,     6,     6,
     196,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     6,  1599,  1502,  1598,   196,
       6,     6,  1602,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     6,    87,  1618,     6,     6,     6,    92,
      93,     6,    95,    96,    97,   198,    12,    13,   101,   205,
       6,   201,     7,     6,    88,    89,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       6,  1651,  1203,     6,   196,  1655,   204,     5,    80,     6,
       6,     6,   135,   136,   137,   205,   204,   204,     7,   205,
     204,   204,   204,  1676,   204,  1678,     6,   138,  1678,     6,
     205,     6,   141,     6,     6,     6,     6,     6,  1691,     6,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    1638,    87,     6,   204,     6,     6,    92,    93,     6,    95,
      96,    97,     6,   204,   204,   101,     6,   204,   204,     6,
      99,   175,   176,   177,   178,   179,   205,     6,    99,     6,
       6,   110,   205,  1733,  1734,     6,     6,   204,   192,   118,
     119,   120,   196,     6,  1747,   124,   125,   126,   127,   135,
     136,   137,  1755,     6,     6,     6,   210,   211,   212,   213,
     205,   215,   216,   217,   218,     6,   220,   221,   222,     6,
     204,     6,   204,   227,     6,     6,  1755,  1328,  1329,  1782,
     204,   204,     6,     6,     6,     6,     6,   204,  1726,     6,
     204,   245,   204,     6,   204,   204,  1799,     6,  1801,     6,
     254,   255,     6,     6,     6,     6,     6,     6,     6,   263,
       6,     6,     6,  1522,     6,  1641,   451,  1523,  1135,   205,
    1799,     3,  1801,  1125,     3,  1535,   205,  1269,  1831,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   481,   296,   297,   298,   196,    -1,    -1,    -1,    -1,
    1755,    -1,  1831,    99,   308,   309,   310,    -1,   312,    -1,
      -1,   315,   316,   317,   110,    -1,   320,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,    -1,    -1,    -1,   124,   125,
     126,   127,    -1,   337,   338,    -1,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,  1799,    -1,  1801,   351,   352,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,    -1,    -1,    -1,    -1,  1831,    -1,    -1,    -1,
      -1,   385,    -1,    -1,    -1,    -1,    -1,   391,    -1,   393,
      -1,  1492,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,   205,
     414,   196,    -1,   417,    -1,    -1,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,    -1,    -1,   437,   438,  1536,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   455,    -1,    -1,   196,    -1,  1557,   461,    -1,    -1,
      -1,    -1,   466,    -1,    -1,    -1,    -1,   471,   472,    -1,
      -1,    -1,    -1,   477,   478,    -1,    -1,    -1,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,   508,   509,   510,   511,   512,   513,
      -1,    -1,    -1,   517,   518,   519,   520,   521,    -1,    -1,
      99,   525,    -1,   527,   528,    -1,    -1,    -1,   532,   533,
     534,   110,    -1,   537,   538,   539,   540,   541,    -1,   118,
     119,   120,   543,   547,    -1,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,   558,     6,    -1,    -1,    -1,    -1,
     564,   565,    -1,   567,   568,    -1,    -1,    -1,   569,    -1,
      -1,    -1,    -1,    -1,    -1,  1676,    -1,  1678,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   596,   597,    -1,    -1,    12,    13,   602,    -1,
      -1,    -1,    -1,    -1,    -1,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,    -1,   618,   619,   620,
     621,   622,   623,   624,    -1,    -1,   205,   628,   629,   630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,   640,
      -1,   642,    -1,    -1,    -1,    -1,  1747,    -1,   649,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,   660,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,   690,    -1,    99,   693,
      -1,   695,   696,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     704,    -1,    -1,   707,   708,    -1,    -1,   118,   119,   120,
      -1,    -1,    -1,   124,   125,   126,   127,   721,    -1,   135,
     136,   137,    -1,    -1,    -1,    -1,   730,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   752,    -1,
      -1,    -1,    -1,    -1,    -1,   759,   760,    -1,    -1,    99,
      -1,   765,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,   778,    -1,    -1,   781,   118,   119,
     120,    -1,    -1,    -1,   124,   125,   126,   127,    -1,   205,
      -1,    -1,    -1,   797,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   806,    -1,   808,    -1,   810,    -1,   812,    12,
      13,    -1,    -1,   817,    -1,    -1,   820,    -1,    -1,    -1,
      -1,    -1,   826,    -1,   828,   829,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     6,    87,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,   862,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   870,   871,   872,    -1,
     874,   223,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,   135,   136,   137,   892,    92,
      93,    -1,    95,    96,    97,   247,   900,    -1,   101,   903,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,
     914,   915,   916,    -1,    -1,    -1,   920,   918,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   949,   950,
      -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   979,    -1,   981,    -1,   983,
      -1,   985,    -1,   335,   336,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,  1033,
     382,    -1,  1036,    -1,    -1,    -1,  1040,    -1,  1042,  1043,
    1044,    -1,    -1,    -1,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,     6,    -1,   216,    -1,
      -1,    -1,   220,  1067,    -1,  1069,    -1,    -1,    -1,   227,
      -1,  1072,    -1,    -1,    -1,    -1,    -1,    -1,  1079,  1080,
    1081,  1082,  1083,    -1,    -1,    -1,    -1,    -1,  1089,  1090,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,  1103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1115,  1116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1127,  1128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,
     298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,  1172,  1173,
    1174,    -1,    92,    93,    -1,    95,    96,    97,  1182,    -1,
    1184,   101,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,  1195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1213,    -1,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,  1224,    -1,  1229,  1230,  1231,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   417,
      87,    -1,  1266,    -1,    -1,    92,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,   101,    -1,  1280,     6,    -1,    -1,
      -1,  1285,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1298,  1299,    -1,   455,    -1,    -1,
      -1,  1305,  1306,    -1,    -1,    -1,  1310,    -1,   135,   136,
     137,    -1,    -1,    -1,  1318,    -1,    -1,    -1,   670,    -1,
      -1,    -1,    -1,    -1,  1328,  1329,  1330,    -1,  1332,    -1,
      -1,    -1,   490,   491,    -1,    -1,    -1,    -1,    -1,    -1,
    1344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,  1356,    -1,    -1,    -1,  1360,    -1,    -1,  1363,
      -1,    -1,    -1,    -1,  1368,  1369,  1370,  1371,    -1,    -1,
      -1,    -1,    -1,    -1,   532,   533,   534,  1381,   205,   731,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1391,  1389,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    -1,    -1,  1408,  1409,    -1,   565,    -1,    -1,
      -1,    -1,  1416,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,   597,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1452,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,  1470,   196,  1472,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1487,    -1,  1489,   838,    -1,  1492,    -1,
      -1,    -1,   844,    -1,    -1,  1499,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,
      -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,
      -1,    -1,  1536,    -1,    -1,   693,    -1,   695,    -1,  1543,
      -1,  1545,   205,  1547,    -1,    -1,    -1,    -1,    -1,   707,
     708,    -1,    -1,  1557,    -1,    -1,    -1,  1561,  1562,  1563,
    1564,  1565,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,  1580,  1581,    -1,    92,
      93,  1585,    95,    96,    97,    -1,    -1,    -1,   101,    -1,
      -1,  1595,    -1,    -1,   752,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  1606,   955,   956,    -1,   958,    -1,   960,   961,
      -1,    -1,   964,   965,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1636,    -1,    -1,    -1,    -1,  1641,    -1,   797,
      -1,    -1,    -1,     6,  1648,    -1,    -1,    -1,   806,    -1,
     808,    -1,   810,    -1,   812,    -1,    -1,    -1,  1662,   817,
      -1,  1665,   820,    -1,  1668,    -1,    -1,    -1,  1672,    -1,
      -1,    -1,  1676,    -1,  1678,  1679,  1680,  1681,  1682,    -1,
      -1,    -1,    -1,    -1,    -1,  1689,    -1,    -1,  1692,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1053,  1054,  1055,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1064,    -1,    -1,    -1,   874,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1747,    -1,  1749,  1750,  1751,  1752,    -1,
      -1,    -1,    -1,    -1,    -1,   913,   914,   915,   916,    -1,
      -1,    -1,    -1,    -1,    -1,  1117,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,  1785,  1786,    -1,  1136,   196,    -1,    -1,    -1,    -1,
    1142,  1795,  1796,  1797,  1798,    -1,  1148,    -1,  1150,  1151,
      -1,    -1,    -1,  1155,  1156,    -1,  1158,    -1,  1160,    -1,
    1162,   969,  1164,  1165,  1166,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
    1182,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1197,    -1,    -1,    -1,  1201,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
       6,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,  1279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
    1292,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     6,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,  1358,    -1,    -1,   157,
     158,   159,   160,     8,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,  1375,   172,   173,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,  1386,    -1,    -1,    -1,  1390,   187,
     188,    -1,    -1,    -1,   192,  1203,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,   202,    -1,   204,    -1,  1410,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,  1431,
     196,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1467,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,   201,   202,    -1,   204,    -1,   206,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,    -1,
    1328,  1329,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1533,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,  1356,    -1,
    1552,   196,  1360,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    99,    -1,    -1,    -1,    -1,    -1,  1599,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1618,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,  1472,   112,    -1,    -1,   115,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,  1492,    -1,    -1,    -1,   196,  1691,
      -1,  1499,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
     157,   196,    -1,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,   172,    -1,    -1,  1536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,  1557,
     197,    -1,    -1,    -1,    -1,   202,    -1,   204,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
    1782,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    12,    13,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,  1676,    -1,
    1678,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,     8,    92,    93,
      -1,    95,    96,    97,    -1,   157,    -1,   101,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,     8,  1747,
     172,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   187,   188,    -1,    -1,   196,
     192,   135,   136,   137,    -1,   197,   203,    -1,   205,    -1,
     202,    -1,    -1,   205,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,   205,    -1,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     8,    -1,    -1,    -1,   196,    -1,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
       3,     4,     5,   202,    -1,   204,     9,    10,    11,    -1,
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
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,     8,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,     3,     4,     5,    -1,    72,    73,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     157,   158,   159,   160,   196,    -1,   198,    -1,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,
       8,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   157,   158,   159,   160,   196,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,     4,     5,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      59,   157,    -1,    62,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    73,    -1,   172,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   187,   188,    -1,    -1,   196,   192,   198,    -1,    -1,
      -1,   197,   203,     3,     4,     5,   202,    -1,   204,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   158,
     159,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,   170,    72,   172,   173,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,   172,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   187,   188,    -1,
      -1,   196,   192,    -1,    -1,    -1,    -1,   197,   203,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,   158,
     159,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,
      84,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,   172,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   187,   188,    -1,    -1,   196,   192,    -1,
      -1,    -1,    -1,   197,   203,     3,     4,    -1,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,   158,   159,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,   170,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,     5,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,   172,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   187,
     188,    -1,    -1,   196,   192,    -1,    -1,    -1,    -1,   197,
     203,     3,     4,    -1,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
     170,    53,    -1,   173,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,    -1,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
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
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,    -1,    -1,   172,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   187,   188,    -1,    -1,   196,   192,    -1,    -1,    -1,
      -1,   197,   203,     3,     4,    -1,   202,    -1,   204,     9,
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
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,   172,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   187,   188,    -1,
      -1,   196,   192,    -1,    -1,    -1,    -1,   197,   203,     3,
       4,    -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      64,    65,    66,    -1,     9,    10,    11,    -1,    72,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,   205,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,   172,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   187,   188,    -1,    -1,   196,   192,    -1,
      -1,    -1,    -1,   197,    -1,    -1,   205,    -1,   202,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,    -1,   172,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   187,   188,    -1,    -1,   196,   192,    -1,    -1,
      -1,    -1,   197,   203,     3,     4,     5,   202,    -1,   204,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   205,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,     3,     4,    -1,    -1,   197,    -1,
       9,    10,    11,   202,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,   172,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   187,   188,
      -1,    -1,   196,   192,     3,     4,    -1,    -1,   197,   203,
       9,    10,    11,   202,    -1,    14,    15,    16,    17,    18,
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
      -1,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    38,
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
      39,    -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,    -1,    54,    55,    56,    -1,    -1,
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
      -1,    -1,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   178,   179,   180,   181,   182,   183,
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
      -1,    -1,    -1,    -1,    -1,   205,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   178,   179,   180,   181,   182,
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
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
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
      -1,    -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,   200,   178,   179,   180,
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
      -1,    -1,   196
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
     152,   153,   154,   155,   156,   161,   162,   163,   164,   171,
     172,   210,   212,   213,   233,   250,   251,   254,   255,   256,
     257,   258,   259,   260,   261,   282,   283,   284,   285,   303,
     304,     3,     4,     5,     9,    10,    11,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    57,    58,    59,    62,    64,    65,
      66,    72,    73,   151,   157,   158,   159,   160,   165,   166,
     167,   168,   169,   170,   173,   187,   188,   192,   197,   199,
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
     197,     4,   204,   296,     4,   197,   197,   197,     6,     6,
     199,     4,   300,   304,     4,   300,     5,   204,     5,   204,
       4,   286,   286,   199,     6,   197,   204,   197,   199,   206,
     231,     7,   174,   175,   176,   177,   193,   194,   229,   230,
       4,   197,   199,   201,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   197,
     197,   197,   197,   197,   197,   231,   231,   231,   231,   197,
     231,   231,   231,     7,   197,   197,   197,   231,   197,   197,
     199,   286,   286,   286,   286,   286,     4,   140,   141,   304,
       4,   251,   252,   253,   204,   198,   200,   204,   232,     6,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   196,   204,     6,   197,   199,   230,
       6,   286,     4,   299,   300,   304,   299,   286,   299,   302,
     235,   238,   300,   304,   286,   188,   286,   294,   295,   286,
     286,   197,   286,   295,   286,   286,   197,   295,   286,   286,
     292,   197,   204,   295,   293,   293,   293,   197,   197,   293,
     293,   293,   197,   197,   197,   197,   197,   197,   197,   197,
     204,   204,   286,     4,   292,   296,   204,   204,   289,   289,
     289,   286,   286,   187,   188,   204,   204,   289,   204,   204,
     204,   187,   188,   197,   253,   289,   204,   197,   204,   197,
     197,   197,   293,   293,   292,   197,     4,   199,   199,   253,
       6,     6,   204,   204,   204,   293,   293,   199,   199,   199,
     197,   199,   201,   231,   199,     5,   143,   204,     5,   143,
       5,   143,     5,   143,    76,    79,    82,    84,   204,   286,
     294,   286,   205,   295,     8,   189,     6,   197,   199,   231,
       6,   286,   286,   286,   201,   286,   204,   143,   286,   286,
     286,   286,     6,     6,     6,   253,     6,   253,   199,     6,
     204,   299,   292,   292,   286,   286,   204,   204,   232,   300,
     292,     6,   199,   286,   286,     4,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   302,   299,
     302,   299,   299,   299,   292,   299,   299,   286,   299,   299,
     299,   302,   299,   286,   300,   286,   299,   299,   299,   299,
     304,   300,   304,   198,   200,     7,   229,   230,   201,     7,
     231,   205,    76,    79,    82,    84,   250,   286,   295,     7,
     229,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   214,   286,   286,     6,
     199,   201,   198,   203,   198,   203,   203,   198,   203,   200,
     203,   234,   200,   234,   203,   203,   198,   189,   203,   205,
     198,   198,   286,   198,   205,   198,   198,   286,   205,   198,
     198,     7,   286,   286,   205,     6,     6,     6,   286,   286,
       7,     7,   279,   279,   286,   244,   286,   300,   245,   286,
     300,   246,   286,   300,   247,   286,   300,   286,   286,   286,
     295,   295,   204,   198,     6,   204,   253,   253,   203,   203,
     203,   289,   289,   252,   252,   203,   286,   286,   286,   286,
     265,   203,   253,   286,   286,   286,   286,   286,     7,   280,
       6,     7,   286,     6,   286,   286,   205,   295,   295,   295,
       6,     6,   286,   286,   286,   286,     4,   204,   232,   304,
      54,   286,    54,    54,    54,     5,   204,     5,   204,     5,
     204,     5,   204,   295,   198,   205,   286,   204,   286,   294,
     204,   232,   198,   198,   198,   140,   203,   253,   204,     8,
     198,   198,   200,   205,   205,   253,   200,   198,   203,   205,
     198,   200,   286,   295,   229,     6,     6,   286,   198,   200,
     230,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   203,   232,   232,   232,   232,   232,   232,   232,
     203,   203,   203,   232,   203,   232,   232,   198,   198,   203,
     203,   203,   203,   203,   232,   232,   232,   198,   232,   288,
     301,     6,   203,   198,   198,   203,   232,   198,   198,   200,
     229,   230,   201,   229,   230,   300,   286,     6,     4,     4,
     204,   297,   232,   204,   204,   204,   204,   205,   205,   292,
       8,     4,   130,   131,   132,   133,   205,   217,   221,   224,
     226,   227,   198,   200,   286,     4,     6,   185,   211,   295,
       6,   295,   286,     6,   299,     6,   304,     6,   299,   286,
     300,     7,   286,   294,   143,     7,     7,   198,     7,   143,
       7,     7,   198,   143,     7,     7,   286,   198,   205,   204,
     198,   198,   286,   292,     4,   278,     6,   198,   198,   203,
     198,   203,   198,   203,   198,   203,   198,   198,   198,   205,
     205,   295,   201,   253,   205,   205,   289,   286,   286,   205,
     205,   286,   289,   203,   203,   203,    99,   110,   118,   119,
     120,   124,   125,   126,   127,   275,   276,   289,   205,   262,
     198,   205,   198,   198,   198,   286,     6,   286,   198,   200,
     200,   205,   205,   205,   200,   200,   203,   200,   295,   200,
     204,   205,   204,   204,   204,   295,   295,   295,   295,   205,
       8,   295,   295,     7,     7,     7,   201,   286,   205,   286,
     286,     7,   201,   205,   204,   292,     6,   229,   230,   229,
     230,   205,   205,   292,   200,   230,   201,   230,   299,   286,
     286,   286,   286,   295,   299,   292,   299,   299,   300,   240,
     242,   286,   299,   286,     6,     4,   140,   141,   286,     6,
       6,     6,     7,   199,   296,   298,     6,   295,   295,   295,
     295,   232,     6,   286,   218,   197,   197,   204,   228,     6,
     230,   230,   200,   185,   299,   198,   198,   203,     7,   232,
     232,   289,    82,    84,   292,   292,     7,   292,    82,    84,
     292,   292,     7,    84,   292,   292,     6,     7,     7,   295,
       7,     7,    99,   277,     6,     7,   229,   286,   229,   286,
     229,   286,   229,   286,     7,     7,     7,     7,     7,   205,
       4,   205,   203,   203,   203,   205,   205,   289,   289,   289,
       4,     6,   204,     6,   197,     6,   128,     6,   128,     6,
     128,     6,   128,   205,   276,   203,   275,     7,     6,     7,
       7,     7,     6,   204,     6,     6,     6,    82,   286,     6,
       6,   286,   201,   205,   286,   286,   286,   286,   205,   205,
     205,   205,   286,   205,   205,   292,   292,   292,     4,   203,
       8,     8,   198,     4,     4,   292,   205,   286,     6,   286,
       6,   232,     6,     6,     4,     6,   232,   232,   232,   232,
     232,   203,   198,   198,   198,   203,   203,   232,   241,   203,
     232,   243,   198,   198,     6,     7,   229,   230,   201,     7,
       6,   296,   286,   203,   205,   205,   205,   205,   205,   229,
     197,   286,   286,   291,   292,   204,   201,     6,     6,   211,
       6,   286,   204,   286,   300,     6,     6,     6,   204,   204,
      92,   249,   249,   292,     6,   204,   204,     6,     6,   292,
     204,     6,     6,     5,   292,   205,   292,   292,     4,     6,
     292,   292,   292,   292,   292,   292,   292,   292,   204,   204,
       7,     6,     7,   286,   286,   286,   204,   204,   203,   205,
     203,   205,   203,   205,   199,   286,   292,   286,     6,     6,
       6,     6,   286,   289,   205,     5,   204,   292,   204,   204,
     204,   292,   295,   204,     6,   200,     4,   232,   203,   203,
     203,   203,   232,     6,     6,   139,   286,   286,   286,     6,
       6,     7,   203,     6,     6,     6,   229,   230,   299,   300,
       4,     4,   154,   300,   286,     6,     4,   297,     6,   200,
     296,     6,     6,     6,     6,   292,   215,   286,   203,   203,
     203,   205,   216,   286,     4,   299,   203,   292,   300,   286,
     286,   289,     6,     6,     6,   286,   286,     6,   286,     5,
       6,   204,     6,   143,   248,   286,     6,     6,     6,     6,
       6,     6,     4,     6,     6,   295,   295,   286,   286,   300,
     205,   198,   203,   205,   252,   252,   289,     6,   266,   289,
       6,   267,   289,     6,   268,   286,   205,   203,   198,   205,
     203,     6,   188,   289,     6,   291,   289,   289,     6,   205,
     286,     6,   286,   286,   286,   286,   292,   203,   205,     8,
     205,   198,   204,   286,   300,   292,   292,   198,   232,   204,
     292,   300,   204,   286,   300,   300,     6,     6,     7,     6,
     201,     6,   198,   203,   286,   286,   292,   204,   203,   205,
       6,   286,   236,   237,   205,   205,   205,   205,   205,     5,
     291,    80,     6,   204,   205,   205,   204,     6,     6,   204,
     286,   205,   205,   203,   204,   203,   204,   203,   204,   200,
       6,   292,     7,   204,   286,   203,   205,   203,   203,     6,
     205,   203,   203,   203,   203,   138,   286,   286,   295,     6,
       6,   205,     6,   239,   286,   302,   296,   141,   219,   286,
     203,   203,   291,   286,     6,   203,   240,   242,     6,     6,
       6,     6,     6,     6,   205,   204,   291,   103,   104,   109,
     281,   103,   104,   281,   295,   252,   203,   205,   286,   289,
     275,   286,   289,   275,   286,   289,   275,     6,   203,   205,
     292,   253,   205,   289,     6,   295,   289,   286,   286,   286,
     286,   286,   205,   205,   205,     6,   203,   205,     7,   205,
       6,   204,   286,   286,   205,   286,   205,   205,   204,   286,
     205,   204,   289,   292,     6,   204,   289,     6,   205,   205,
     286,   205,   203,   205,   205,   203,   205,   205,   203,   205,
     292,     6,    99,   205,   263,   204,   203,   205,   203,   203,
     203,   203,   203,     6,     6,   286,   300,   216,   198,   203,
       6,   204,   203,   286,   205,     6,   289,     6,   289,     6,
       6,   205,     6,   269,   286,     6,     6,   270,   286,     6,
       6,   271,   286,     6,   205,   286,   275,   253,   295,     6,
     289,   295,   286,   286,   286,   286,     7,   205,   222,   286,
     291,   286,   203,   203,   203,   204,   205,   204,   205,   204,
     205,     6,     6,   205,   205,   264,   205,   203,   205,   203,
     203,   203,   203,   300,     6,   204,   198,   205,   205,   286,
     289,   289,   275,     6,   272,   275,     6,   273,   275,     6,
     274,   275,     6,   295,     6,   286,   286,   286,   286,   220,
     299,   225,   204,     6,   205,   203,   203,   205,   204,   205,
     204,   205,   204,   205,   205,   203,   203,   203,   203,   203,
     205,   204,   291,     6,   286,   286,     6,   275,     6,   275,
       6,   275,     6,   286,   286,   286,   286,   299,     6,   223,
     299,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   203,   205,     6,     6,     6,     6,     6,     6,   299,
       6
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
     259,   259,   259,   259,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     261,   261,   261,   262,   261,   263,   261,   264,   261,   265,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     266,   261,   267,   261,   268,   261,   269,   261,   270,   261,
     271,   261,   272,   261,   273,   261,   274,   261,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   277,   277,   278,   278,   279,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   283,   284,   284,   284,   285,   285,   285,
     285,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   287,   287,   287,   287,   287,
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
     300,   300,   300,   301,   300,   302,   302,   303,   303,   304,
     304,   304
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
       2,     2,     2,     2,    16,     3,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     8,     8,     8,    12,    12,    12,    14,    14,    14,
       0,    12,     0,    12,     0,    12,     0,    16,     0,    16,
       0,    16,     0,    18,     0,    18,     0,    18,     1,     2,
       5,     7,     9,     2,     2,     2,     3,     2,     3,     2,
       3,     2,     3,     9,     6,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     7,     6,     8,     5,     3,
       7,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,    10,    10,    10,    10,     4,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     5,     5,     5,     5,
       3,     6,     4,     7,     6,     6,     6,     6,     4,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     1,     2,     3,
       3,     5,     4,     2,     2,     2,     2,     3,     3,     3,
       3,     5,     5,     5,     5,    16,    16,    16,    16,     1,
       1,     3,     3,     4,     6,     6,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       3,     6,     1,     4,     1,     1,     1,     4,     6,     4,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     4,
       6,     4,     1,     0,     6,     1,     3,     5,     5,     1,
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
#line 197 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 239 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 249 "Gmsh.y" /* yacc.c:1646  */
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
#line 4514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 263 "Gmsh.y" /* yacc.c:1646  */
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
#line 4531 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 276 "Gmsh.y" /* yacc.c:1646  */
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
#line 4548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 289 "Gmsh.y" /* yacc.c:1646  */
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
#line 4575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 317 "Gmsh.y" /* yacc.c:1646  */
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
#line 4593 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 331 "Gmsh.y" /* yacc.c:1646  */
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
#line 4610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "Gmsh.y" /* yacc.c:1646  */
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
#line 4627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 357 "Gmsh.y" /* yacc.c:1646  */
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
#line 4646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 375 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 389 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 403 "Gmsh.y" /* yacc.c:1646  */
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
#line 4788 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 507 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 4802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 517 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 526 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 533 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 543 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 4847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 552 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 561 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 568 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 578 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 4891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 586 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 596 "Gmsh.y" /* yacc.c:1646  */
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
#line 4921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 615 "Gmsh.y" /* yacc.c:1646  */
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
#line 4941 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 634 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 640 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 655 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5018 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 672 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 677 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5043 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 683 "Gmsh.y" /* yacc.c:1646  */
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
#line 5107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 743 "Gmsh.y" /* yacc.c:1646  */
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
#line 5140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 772 "Gmsh.y" /* yacc.c:1646  */
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
#line 5173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 801 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5182 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 806 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 811 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 816 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 821 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 828 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 835 "Gmsh.y" /* yacc.c:1646  */
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
#line 5250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 855 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 860 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 865 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 870 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 879 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 885 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 894 "Gmsh.y" /* yacc.c:1646  */
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
#line 5338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 912 "Gmsh.y" /* yacc.c:1646  */
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
#line 5360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 930 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 939 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 951 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 956 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 964 "Gmsh.y" /* yacc.c:1646  */
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
#line 5428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 984 "Gmsh.y" /* yacc.c:1646  */
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
#line 5452 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1007 "Gmsh.y" /* yacc.c:1646  */
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
#line 5467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1018 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 5479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1026 "Gmsh.y" /* yacc.c:1646  */
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
#line 5505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1048 "Gmsh.y" /* yacc.c:1646  */
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
#line 5532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1071 "Gmsh.y" /* yacc.c:1646  */
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
#line 5562 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1097 "Gmsh.y" /* yacc.c:1646  */
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
#line 5584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1118 "Gmsh.y" /* yacc.c:1646  */
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
#line 5600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1130 "Gmsh.y" /* yacc.c:1646  */
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
#line 5616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1148 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 5629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1157 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 5642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5648 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1168 "Gmsh.y" /* yacc.c:1646  */
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
#line 5668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1184 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 5681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1193 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1195 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 5701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1209 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1217 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1223 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1235 "Gmsh.y" /* yacc.c:1646  */
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
#line 5745 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1246 "Gmsh.y" /* yacc.c:1646  */
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
#line 5763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1261 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1277 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1285 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1294 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1302 "Gmsh.y" /* yacc.c:1646  */
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
#line 5826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1330 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5853 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1342 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1348 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1378 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1384 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1392 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1396 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 5956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1412 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1422 "Gmsh.y" /* yacc.c:1646  */
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
#line 5999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1445 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_POINT;
      (yyval.s).Num = num;
    }
#line 6035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1477 "Gmsh.y" /* yacc.c:1646  */
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
#line 6059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1500 "Gmsh.y" /* yacc.c:1646  */
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
#line 6081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1518 "Gmsh.y" /* yacc.c:1646  */
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
#line 6106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1539 "Gmsh.y" /* yacc.c:1646  */
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
#line 6128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1557 "Gmsh.y" /* yacc.c:1646  */
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
#line 6162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1587 "Gmsh.y" /* yacc.c:1646  */
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
#line 6196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1617 "Gmsh.y" /* yacc.c:1646  */
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
#line 6218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1635 "Gmsh.y" /* yacc.c:1646  */
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
#line 6240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1654 "Gmsh.y" /* yacc.c:1646  */
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
#line 6270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1680 "Gmsh.y" /* yacc.c:1646  */
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
#line 6292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1698 "Gmsh.y" /* yacc.c:1646  */
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
#line 6314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1716 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_LINE;
      (yyval.s).Num = num;
    }
#line 6350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1751 "Gmsh.y" /* yacc.c:1646  */
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
#line 6372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1769 "Gmsh.y" /* yacc.c:1646  */
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
#line 6415 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1808 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6425 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1814 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1820 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6446 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1827 "Gmsh.y" /* yacc.c:1646  */
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
#line 6475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1852 "Gmsh.y" /* yacc.c:1646  */
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
#line 6504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1877 "Gmsh.y" /* yacc.c:1646  */
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
#line 6525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1894 "Gmsh.y" /* yacc.c:1646  */
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
#line 6548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1914 "Gmsh.y" /* yacc.c:1646  */
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
#line 6585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1947 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_SURFACE;
      (yyval.s).Num = num;
    }
#line 6621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1983 "Gmsh.y" /* yacc.c:1646  */
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
#line 6643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 2001 "Gmsh.y" /* yacc.c:1646  */
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
#line 6664 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2018 "Gmsh.y" /* yacc.c:1646  */
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
#line 6684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2034 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exists", num);
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
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_PHYSICAL_VOLUME;
      (yyval.s).Num = num;
    }
#line 6720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2071 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2076 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2081 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2086 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6756 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2091 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6765 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2096 "Gmsh.y" /* yacc.c:1646  */
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
#line 6792 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2119 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2125 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 6814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2135 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2136 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2145 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2149 "Gmsh.y" /* yacc.c:1646  */
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
#line 6869 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2172 "Gmsh.y" /* yacc.c:1646  */
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
#line 6896 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2195 "Gmsh.y" /* yacc.c:1646  */
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
#line 6923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2218 "Gmsh.y" /* yacc.c:1646  */
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
#line 6950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2246 "Gmsh.y" /* yacc.c:1646  */
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
#line 6975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2267 "Gmsh.y" /* yacc.c:1646  */
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
#line 7005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2294 "Gmsh.y" /* yacc.c:1646  */
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
#line 7029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2315 "Gmsh.y" /* yacc.c:1646  */
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
#line 7054 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2336 "Gmsh.y" /* yacc.c:1646  */
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
#line 7078 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2356 "Gmsh.y" /* yacc.c:1646  */
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
#line 7194 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2468 "Gmsh.y" /* yacc.c:1646  */
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
#line 7217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2487 "Gmsh.y" /* yacc.c:1646  */
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
#line 7259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2526 "Gmsh.y" /* yacc.c:1646  */
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
#line 7366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2634 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2643 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2649 "Gmsh.y" /* yacc.c:1646  */
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
#line 7408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2664 "Gmsh.y" /* yacc.c:1646  */
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
#line 7440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2692 "Gmsh.y" /* yacc.c:1646  */
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
#line 7456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2709 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2718 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2732 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2746 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2752 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2758 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2767 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2776 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2785 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2799 "Gmsh.y" /* yacc.c:1646  */
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
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 7627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2855 "Gmsh.y" /* yacc.c:1646  */
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
#line 7649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2873 "Gmsh.y" /* yacc.c:1646  */
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
#line 7670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2890 "Gmsh.y" /* yacc.c:1646  */
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
#line 7689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2905 "Gmsh.y" /* yacc.c:1646  */
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
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 7712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2924 "Gmsh.y" /* yacc.c:1646  */
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
#line 7728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2936 "Gmsh.y" /* yacc.c:1646  */
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
#line 7756 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2960 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7764 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2964 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2969 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2976 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2981 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2987 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2992 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 2998 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 7834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3014 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3020 "Gmsh.y" /* yacc.c:1646  */
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
#line 7917 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3074 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
#line 7929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3087 "Gmsh.y" /* yacc.c:1646  */
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
#line 7950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3104 "Gmsh.y" /* yacc.c:1646  */
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
#line 7971 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3121 "Gmsh.y" /* yacc.c:1646  */
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
#line 7997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3143 "Gmsh.y" /* yacc.c:1646  */
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
#line 8023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3165 "Gmsh.y" /* yacc.c:1646  */
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
#line 8062 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3200 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8074 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3208 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8086 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3216 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3222 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3229 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3236 "Gmsh.y" /* yacc.c:1646  */
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
        if(!type_until2) ImbricatedTest--;
      }
    }
#line 8142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3256 "Gmsh.y" /* yacc.c:1646  */
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
#line 8172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3282 "Gmsh.y" /* yacc.c:1646  */
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
#line 8188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3294 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3306 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8210 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3314 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3322 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3330 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3336 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3344 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3350 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3358 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3364 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3372 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3378 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3386 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3393 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3400 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3407 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3414 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3421 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3428 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3435 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3442 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3449 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3455 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3462 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3468 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3475 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3481 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3488 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3494 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3501 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3507 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3514 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3520 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3527 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3533 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3540 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3546 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3553 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3559 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3570 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3573 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3579 "Gmsh.y" /* yacc.c:1646  */
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
#line 8639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3591 "Gmsh.y" /* yacc.c:1646  */
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
#line 8663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3611 "Gmsh.y" /* yacc.c:1646  */
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
#line 8690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3635 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3639 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3643 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3647 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3651 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3657 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3667 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8758 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3671 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3675 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8774 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3679 "Gmsh.y" /* yacc.c:1646  */
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
#line 8797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3698 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3710 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3714 "Gmsh.y" /* yacc.c:1646  */
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
#line 8834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3729 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3733 "Gmsh.y" /* yacc.c:1646  */
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
#line 8860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3749 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3753 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3758 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8884 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3762 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3768 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3772 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8908 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3779 "Gmsh.y" /* yacc.c:1646  */
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
#line 8968 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3835 "Gmsh.y" /* yacc.c:1646  */
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
#line 9042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3905 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3910 "Gmsh.y" /* yacc.c:1646  */
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
#line 9122 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3977 "Gmsh.y" /* yacc.c:1646  */
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
#line 9162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4013 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4021 "Gmsh.y" /* yacc.c:1646  */
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
#line 9221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4064 "Gmsh.y" /* yacc.c:1646  */
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
#line 9264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4103 "Gmsh.y" /* yacc.c:1646  */
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
#line 9288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4124 "Gmsh.y" /* yacc.c:1646  */
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
#line 9323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4156 "Gmsh.y" /* yacc.c:1646  */
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
#line 9353 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4183 "Gmsh.y" /* yacc.c:1646  */
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
#line 9382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4209 "Gmsh.y" /* yacc.c:1646  */
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
#line 9411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4235 "Gmsh.y" /* yacc.c:1646  */
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
#line 9440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4261 "Gmsh.y" /* yacc.c:1646  */
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
#line 9469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4287 "Gmsh.y" /* yacc.c:1646  */
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
#line 9494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4308 "Gmsh.y" /* yacc.c:1646  */
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
#line 9526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4336 "Gmsh.y" /* yacc.c:1646  */
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
#line 9558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4364 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4368 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4372 "Gmsh.y" /* yacc.c:1646  */
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
#line 9606 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4400 "Gmsh.y" /* yacc.c:1646  */
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
#line 9649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4439 "Gmsh.y" /* yacc.c:1646  */
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
#line 9692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4478 "Gmsh.y" /* yacc.c:1646  */
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
#line 9717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4499 "Gmsh.y" /* yacc.c:1646  */
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
#line 9742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4520 "Gmsh.y" /* yacc.c:1646  */
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
#line 9767 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4547 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4551 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4561 "Gmsh.y" /* yacc.c:1646  */
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
#line 9823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4595 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4596 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4597 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4602 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9851 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
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
#line 9867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
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
#line 9889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4638 "Gmsh.y" /* yacc.c:1646  */
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
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4670 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4671 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4672 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4680 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4681 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4683 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4684 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4685 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10011 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4686 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4687 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4688 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4689 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4690 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4691 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4692 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4693 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4694 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4695 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10071 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4696 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4697 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4698 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4699 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4700 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4701 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4702 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4703 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4704 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4705 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10131 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4706 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4707 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10143 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4708 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4709 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4710 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4711 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4712 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4721 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10179 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4722 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10185 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4723 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4724 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4725 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10203 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4726 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4727 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4728 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4729 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4730 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4731 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4736 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10255 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4744 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4749 "Gmsh.y" /* yacc.c:1646  */
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
#line 10285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4766 "Gmsh.y" /* yacc.c:1646  */
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
#line 10307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4784 "Gmsh.y" /* yacc.c:1646  */
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
#line 10329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4802 "Gmsh.y" /* yacc.c:1646  */
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
#line 10351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4820 "Gmsh.y" /* yacc.c:1646  */
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
#line 10373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4838 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4843 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4849 "Gmsh.y" /* yacc.c:1646  */
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
#line 10408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4861 "Gmsh.y" /* yacc.c:1646  */
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
#line 10429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4878 "Gmsh.y" /* yacc.c:1646  */
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
#line 10451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
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
#line 10473 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4914 "Gmsh.y" /* yacc.c:1646  */
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
#line 10495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4932 "Gmsh.y" /* yacc.c:1646  */
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
#line 10517 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4953 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4958 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4963 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4973 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4983 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10572 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 4988 "Gmsh.y" /* yacc.c:1646  */
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
#line 10587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4999 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5008 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
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
#line 10637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5040 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5044 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5048 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5052 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5056 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10677 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5063 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10685 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5067 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5071 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5075 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5082 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5087 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5094 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5099 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5103 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5108 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5112 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5120 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5131 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10792 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5135 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5155 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5163 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5170 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5180 "Gmsh.y" /* yacc.c:1646  */
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
#line 10887 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5209 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5213 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5217 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5221 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5225 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10935 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5233 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5237 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5241 "Gmsh.y" /* yacc.c:1646  */
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
#line 10984 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5270 "Gmsh.y" /* yacc.c:1646  */
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
#line 11017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5299 "Gmsh.y" /* yacc.c:1646  */
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
#line 11050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5328 "Gmsh.y" /* yacc.c:1646  */
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
#line 11083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5358 "Gmsh.y" /* yacc.c:1646  */
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
#line 11099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5371 "Gmsh.y" /* yacc.c:1646  */
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
#line 11115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5384 "Gmsh.y" /* yacc.c:1646  */
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
#line 11131 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5397 "Gmsh.y" /* yacc.c:1646  */
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
#line 11147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5409 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5419 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5429 "Gmsh.y" /* yacc.c:1646  */
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
#line 11191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5441 "Gmsh.y" /* yacc.c:1646  */
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
#line 11207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5454 "Gmsh.y" /* yacc.c:1646  */
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
#line 11223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5466 "Gmsh.y" /* yacc.c:1646  */
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
#line 11245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5484 "Gmsh.y" /* yacc.c:1646  */
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
#line 11267 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5505 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11276 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5510 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5514 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5518 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5530 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5534 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5546 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5553 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5563 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5567 "Gmsh.y" /* yacc.c:1646  */
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
#line 11367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5582 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5587 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5594 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5598 "Gmsh.y" /* yacc.c:1646  */
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
#line 11409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5611 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5619 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5630 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5634 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11449 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5638 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5646 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5652 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5658 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5666 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5674 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5681 "Gmsh.y" /* yacc.c:1646  */
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
#line 11535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5696 "Gmsh.y" /* yacc.c:1646  */
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
#line 11553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5710 "Gmsh.y" /* yacc.c:1646  */
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
#line 11571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5724 "Gmsh.y" /* yacc.c:1646  */
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
#line 11587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5736 "Gmsh.y" /* yacc.c:1646  */
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
#line 11607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5752 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5761 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5770 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5780 "Gmsh.y" /* yacc.c:1646  */
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
#line 11662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5791 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5795 "Gmsh.y" /* yacc.c:1646  */
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
#line 11693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5814 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5821 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5827 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5829 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5840 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5845 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5851 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5860 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5873 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5876 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 5880 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11793 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5883 "Gmsh.y" /* yacc.c:1906  */


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
