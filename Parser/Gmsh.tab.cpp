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
    tGetEnv = 413,
    tGetString = 414,
    tGetNumber = 415,
    tHomology = 416,
    tCohomology = 417,
    tBetti = 418,
    tExists = 419,
    tFileExists = 420,
    tGMSH_MAJOR_VERSION = 421,
    tGMSH_MINOR_VERSION = 422,
    tGMSH_PATCH_VERSION = 423,
    tGmshExecutableName = 424,
    tSetPartition = 425,
    tNameFromString = 426,
    tStringFromName = 427,
    tAFFECTPLUS = 428,
    tAFFECTMINUS = 429,
    tAFFECTTIMES = 430,
    tAFFECTDIVIDE = 431,
    tOR = 432,
    tAND = 433,
    tEQUAL = 434,
    tNOTEQUAL = 435,
    tLESSOREQUAL = 436,
    tGREATEROREQUAL = 437,
    tPLUSPLUS = 438,
    tMINUSMINUS = 439,
    UNARYPREC = 440
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

#line 418 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 435 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   10189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  520
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1840

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   440

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   191,     2,   201,     2,   190,     2,     2,
     196,   197,   188,   186,   202,   187,   200,   189,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     182,     2,   184,   177,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   198,     2,   199,   195,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,     2,   204,   205,     2,     2,     2,
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
     175,   176,   178,   179,   180,   181,   183,   185,   192,   193,
     194
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
    2745,  2751,  2757,  2766,  2775,  2784,  2798,  2857,  2875,  2892,
    2907,  2933,  2945,  2969,  2973,  2978,  2985,  2990,  2996,  3001,
    3007,  3015,  3019,  3023,  3028,  3088,  3105,  3122,  3144,  3166,
    3201,  3209,  3217,  3223,  3230,  3237,  3257,  3283,  3295,  3307,
    3315,  3323,  3332,  3331,  3346,  3345,  3360,  3359,  3374,  3373,
    3387,  3394,  3401,  3408,  3415,  3422,  3429,  3436,  3443,  3451,
    3450,  3464,  3463,  3477,  3476,  3490,  3489,  3503,  3502,  3516,
    3515,  3529,  3528,  3542,  3541,  3555,  3554,  3571,  3574,  3580,
    3592,  3612,  3636,  3640,  3644,  3648,  3652,  3658,  3664,  3668,
    3672,  3676,  3680,  3699,  3712,  3715,  3731,  3734,  3751,  3754,
    3760,  3763,  3770,  3773,  3780,  3836,  3906,  3911,  3978,  4014,
    4022,  4065,  4104,  4124,  4156,  4183,  4209,  4235,  4261,  4287,
    4309,  4337,  4365,  4369,  4373,  4401,  4440,  4479,  4500,  4521,
    4548,  4552,  4562,  4597,  4598,  4599,  4603,  4609,  4621,  4639,
    4667,  4668,  4669,  4670,  4671,  4672,  4673,  4674,  4675,  4682,
    4683,  4684,  4685,  4686,  4687,  4688,  4689,  4690,  4691,  4692,
    4693,  4694,  4695,  4696,  4697,  4698,  4699,  4700,  4701,  4702,
    4703,  4704,  4705,  4706,  4707,  4708,  4709,  4710,  4711,  4712,
    4713,  4714,  4723,  4724,  4725,  4726,  4727,  4728,  4729,  4730,
    4731,  4732,  4733,  4738,  4737,  4745,  4750,  4767,  4785,  4803,
    4821,  4839,  4844,  4850,  4862,  4879,  4897,  4915,  4933,  4954,
    4959,  4964,  4974,  4984,  4989,  5000,  5009,  5014,  5041,  5045,
    5049,  5053,  5057,  5064,  5068,  5072,  5076,  5083,  5088,  5095,
    5100,  5104,  5109,  5113,  5121,  5132,  5136,  5148,  5156,  5164,
    5171,  5181,  5210,  5214,  5218,  5222,  5226,  5230,  5234,  5238,
    5242,  5271,  5300,  5329,  5358,  5371,  5384,  5397,  5410,  5420,
    5430,  5442,  5455,  5467,  5485,  5506,  5511,  5515,  5519,  5531,
    5535,  5547,  5557,  5567,  5571,  5586,  5591,  5598,  5602,  5615,
    5623,  5634,  5638,  5642,  5650,  5656,  5662,  5670,  5678,  5685,
    5700,  5714,  5728,  5740,  5756,  5765,  5774,  5784,  5795,  5799,
    5818,  5825,  5832,  5831,  5844,  5849,  5855,  5864,  5877,  5880,
    5884
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
  "tBetti", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
     425,   426,   427,   428,   429,   430,   431,    63,   432,   433,
     434,   435,    60,   436,    62,   437,    43,    45,    42,    47,
      37,    33,   438,   439,   440,    94,    40,    41,    91,    93,
      46,    35,    44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1342

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1342)))

#define YYTABLE_NINF -491

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7030,    41,    58,  7150, -1342, -1342,  3448,    57,   -16,   -93,
     -82,    42,   150,   167,   186,   214,   -58,   258,   262,    92,
     112,   130,   130,  -106,   118,   138,    14,   145,   160,    25,
     166,   173,   188,   299,   306,   426,   217,   380,   361,   397,
     414,   401,   379,   626,   289,   301,   422,   -23,   318,   -91,
     -91,   336,   261,   329,   207,   461,   472,    15,    55,   479,
     484,   316,   586,   662,   678,  4894,   697,   456,   501,   508,
      24,    52, -1342,   515,   541, -1342, -1342,   736,   760,   579,
   -1342,  4774,  5170,    31,    32, -1342, -1342, -1342,  6891,   604,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342,    46, -1342,   271,   108,
   -1342,     4, -1342, -1342, -1342, -1342, -1342,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   597,   610,   624,   656,   657,   660,   130,   130,
     130,   130,   667, -1342,   130, -1342, -1342, -1342, -1342, -1342,
     130,   130,   819,   682,   683,   688,   130,   703,   707, -1342,
   -1342, -1342, -1342,   650,  6891,  6891,  6891,  6891,  6891,    53,
      13,    22,   704,   459,   739, -1342,   727,   925,   357,  -109,
     934,  6891,  4975,  4975, -1342,  6891, -1342, -1342, -1342, -1342,
    4975, -1342, -1342, -1342, -1342, -1342, -1342,  5362,    13,  6891,
    6702,  6891,  6891,   710,  6891,  6702,  6891,  6891,   748,  6702,
    6891,  6891,  5284,   749,   745, -1342,  6702,  4894,  4894,  4894,
     753,   777,  4894,  4894,  4894,   790,   798,   832,   846,   860,
     861,   864,   865,   755,  6259,   958,  5284,    24,   843,   862,
     -91,   -91,   -91,  6891,  6891,   -87, -1342,   -80,   -91,   867,
     868,   882,  6318,   -68,   -74,   897,   903,   906,  4894,  4894,
    5284,   914,     1,   801, -1342,   828,  1105,  1112, -1342,   916,
     926,   938,  4894,  4894,   937,   949,   950,   230, -1342,   951,
       8,    20,    26,    27,   630,  5479,  6891,  3847, -1342, -1342,
    3787, -1342,  1148, -1342,   489,   219,  1150,  6891,  6891,  6891,
    -170,  6891,   955, -1342,  1019,  6891,  6891,  6891, -1342, -1342,
    6891,   969,  1157,  1170, -1342, -1342,  1172, -1342,  1173, -1342,
     455,  7733,  4975, -1342,  5284,  5284,  6891,  6891,   979,   601,
    5362, -1342, -1342, -1342, -1342, -1342, -1342,  5284,  1181,   992,
    6891,  6891,  1187,  6891,  6891,  6891,  6891,  6891,  6891,  6891,
    6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,
    6891,  6891,  6891,  6891,  6891,  4975,  4975,  4975,  4975,  4975,
    4975,  5284,  4975,  4975,  6891,  4975,  4975,  4975,  4975,  4975,
    6891,  5362,  6891,  4975,  4975,  4975,  4975,    13,  5362,    13,
     999,   999,   999,  9196,  8851,   123,   993,  1192,   130,  1000,
   -1342,   997,  5523,  6891, -1342, -1342,  6702,     7, -1342,  6891,
    6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,  6891,
    6891,  6891,  6891,  6891, -1342, -1342,  6891,  6891, -1342, -1342,
    1049,  -145,  -158, -1342, -1342,   -42,  5084, -1342,   107,   432,
     490,  1002,  1006,  9217,  6702,  3806, -1342,   185,  9238,  9259,
    6891,  9280,   227,  9301,  9322,  6891,   264,  9343,  9364,  1195,
    6891,  6891,   376,  1203,  1209,  1210,  6891,  6891,  1211,  1212,
    1212,  6891,  6513,  6513,  6513,  6513,  6891,  6891,  6891,  6702,
    6702,  7760,  1020,  1214,  1037, -1342, -1342,   -78, -1342, -1342,
    5279,  5669,   -91,   -91,    22,    22,   -66,  6891,  6891,  6891,
    6318,  6318,  6891,  5523,   -45, -1342,  6891,  6891,  6891,  6891,
    6891,  1215,  1235,  1236,  6891,  1239,  6891,  6891,   900, -1342,
   -1342,  6702,  6702,  6702,  1241,  1242,  6891,  6891,  6891,  6891,
    6891,  1238,   611,    13, -1342,  1196,  6891, -1342,  1197, -1342,
    1199, -1342,  1201,    33,    36,    37,    38,  6702,   999, -1342,
    9385, -1342,   384,  6891,  5674, -1342,  6891,  6891,   632, -1342,
    9406,  9427,  9448,  1109,  5864, -1342,  1053,  3989,  9469,  9490,
    8874, -1342, -1342, -1342,  1088, -1342,  1462,  6891, -1342,  1058,
    1061,   428,  9511,  8897,  6891,  6702,     7,  1253,  1254, -1342,
    6891,  9532,  8920,   -39,  8828,  8828,  8828,  8828,  8828,  8828,
    8828,  8828,  8828,  8828,  8828,  6059,  8828,  8828,  8828,  8828,
    8828,  8828,  8828,  6313,  6697,  7814,   635,   648,   635,  1067,
    1068,  1064,  1065,  1073,  1074,  7840,   524,   524,   524,   116,
     524,  9994, -1342,  1387,  1081,  1072,   125,   524,  1089,  1091,
    1090,   132,    78,  5362,  6891,  1287,  1286,    29,   524, -1342,
     -18,    19,    30,     5, -1342,  4210,   526, -1342,  5284,  4008,
     600,  1545,  1649,  1649,   407,   407,   407,   407,   530,   530,
     999,   999,   999,   999,    17,  9553,  8943, -1342,  6891,  1291,
      66,  6702,  1292,  6702,  6891,  1293,  4975,  1294, -1342,    13,
    1295,  4975,  6891,  5362,  1290,  6702,  6702,  1159,  1296,  1300,
    9574,  1302,  1188,  1309,  1323,  9595,  1194,  1331,  1333,  6891,
    9616,  4405,  1138, -1342, -1342, -1342,  9637,  9658,  6891,  5284,
    1339,  1336,  9679,  1149,  9994,  1145,  1151,  9994,  1147,  1161,
    9994,  1152,  1163,  9994,  1154,  9700,  9721,  9742,   527,   544,
    6702,  1162, -1342, -1342,  1548,  2135,   -91,  6891,  6891, -1342,
   -1342,  1160,  1164,  6318,  7866,  7892,  7918,  4889,  1284,   -91,
    2316,  9763,  5808,  9784,  9805,  9826,  6891,  1355, -1342,  6891,
    9847, -1342,  8966,  8989, -1342,   571,   572,   595, -1342, -1342,
    9012,  9035,  7944,  9058,   219,  6702, -1342,  1166,  1168,  6003,
    1169,  1171,  1175, -1342,  6702, -1342,  6702, -1342,  6702, -1342,
    6702,   607, -1342, -1342,  4191,  6702,   999, -1342,  6702, -1342,
    1356,  1360,  1362,  1176,  6891,  2454,  6891,  6891, -1342, -1342,
      -4, -1342, -1342,  2540, -1342,  1177,  5284,  1367,   132,   132,
    6214,   634,  5284, -1342, -1342,  9081,   219,  1277, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
    6891, -1342, -1342, -1342, -1342, -1342, -1342, -1342,  6891,  6891,
    6891, -1342,  6702, -1342, -1342, -1342, -1342,  4975,  5284,  4975,
    4975,  5362, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
    6891, -1342, -1342,  4975, -1342, -1342, -1342, -1342,  6891,  1369,
     136,  6891,  1373,  1378,  1690, -1342,  1382,  1193,    24,  1389,
   -1342,  6702,  6702,  6702,  6702, -1342,   524,  1390,  6891, -1342,
    1202,  1204,  1217, -1342,  1400, -1342, -1342, -1342, -1342, -1342,
     219,   219,  9104, -1342, -1342,  1223,  4975,   368, -1342,   443,
    7970, -1342, -1342, -1342,  1405, -1342, -1342,  8828,   524,   -91,
    3806, -1342,   775,  5284,  5284,  1406,  5284,   782,  5284,  5284,
    1407,  1337,  5284,  5284,  1762,  1410,  1415,  6702,  1416,  1417,
    3187, -1342, -1342,  1419, -1342,  1420,     7,  6891,     7,  6891,
       7,  6891,     7,  6891,  1421,  1425,  1426,  1427,  1430,   669,
    1434,  3183, -1342, -1342,   -41,  7996,  8022, -1342, -1342,  6254,
    -111,   -91,   -91,   -91,  1435,  1436,  1237,  1437,  1248,    34,
      39,    40,    43,   240, -1342,   -28, -1342,  1284,  1438,  1441,
    1446,  1447,  1449,  9994, -1342,  1807,  1255,  1451,  1453,  1454,
    1379,  1456,  1458,  1459,  6891,    93,   681, -1342,  6891, -1342,
    6891,  6891,  6891,   690,   693,   700,   733, -1342,  6891,   734,
     737,  5284,  5284,  5284,  1464,  8048, -1342,  4470,   574,  1467,
    1468, -1342,  5284,  1262, -1342,  6891,  1470,  6891,  1472, -1342,
     524,  1473,  1475, -1342,  1469, -1342,  1476,  8828,  8828,  8828,
    8828,   652,  1281,  1288,  1289,  1297,  1282,   668,   694,  9868,
    1299,  2098, -1342,   249,  1303,  1480,  2291, -1342, -1342, -1342,
      24,  6891, -1342,   750, -1342,   759,   763,   766,   767,     7,
   -1342,  9994,  1301,  6891,  6891,  5284,  1306, -1342, -1342, -1342,
    1310, -1342,  1483,    71,  1484,  6891,  4439,  1486,  1496,    74,
    1308,  1311,  1439,  1439,  5284,  1506,  1327,  1332,  1528,  1531,
    5284,  1347,  1550,  1556, -1342,  1573,  5284,   787,  5284,  5284,
    1547,  1574, -1342,  5284,  5284,  9994,  5284,  9994,  5284,  9994,
    5284,  9994,  5284,  5284,  5284,  1376,  1380,  1577,   594, -1342,
    6891,  6891,  6891,  1383,  1384,  -123,  -113,  -100,  1392, -1342,
    5284, -1342,  6891, -1342,  1575, -1342,  1582, -1342,  1586, -1342,
    1587, -1342, -1342,  6318,   523,  5089, -1342,  1391,  1397,  5869,
   -1342,  6702, -1342, -1342, -1342,  1398,  6891, -1342, -1342,  9127,
    1600,   524,  8074,  8100,  8126,  8152, -1342, -1342, -1342, -1342,
    9994, -1342,   524,  1602,  1603,  1471, -1342,  6891,  6891,  6891,
   -1342,  1605,   617,  1404,  1606,  2320, -1342,  2381, -1342,     7,
   -1342, -1342,    -5, -1342, -1342, -1342, -1342, -1342, -1342,  4975,
   -1342, -1342, -1342,  5362,  1609, -1342, -1342,    18, -1342, -1342,
   -1342, -1342, -1342,  5362,  6891,  1610,  1613,    29, -1342,  1614,
    9150,    24, -1342,  1615,  1616,  1617,  1630,  5284,  6891,  8178,
    8204,   796, -1342,  6891,  1633, -1342, -1342,  4975, -1342,  8230,
    4049,  9994, -1342, -1342, -1342, -1342,  6891,  6891,   -91,  1632,
    1636,  1640, -1342,  6891,  6891, -1342, -1342,  1641,  6891, -1342,
   -1342,  1634,  1644,  1448,  1646,  1510,  6891, -1342,  1648,  1650,
    1651,  1653,  1654,  1655,   998,  1657,  6702,  6702,  6891, -1342,
    6513,  6410,  9889,  3842,    22,    22,   -91,  1658,   -91,  1659,
     -91,  1661,  6891,   327,  1466,  9910, -1342, -1342, -1342, -1342,
    6438,   134, -1342,  1663,  3651,  1664,  5284,   -91,  3651,  1665,
     803,  6891,  2887,  1667,   219, -1342,  6891,  6891,  6891,  6891,
   -1342, -1342, -1342,  5284,  4603,   491,  9931, -1342, -1342,  4504,
    5284, -1342, -1342, -1342,  5284, -1342,  1422,   524,  4244,  4699,
    5362,  1669,  2977, -1342,  1670,  1672, -1342,  1455, -1342, -1342,
   -1342, -1342, -1342,  1673,   457,  9994,  6891,  6891,  5284,  1477,
     804,  9994, -1342,  1675,  6891, -1342, -1342,  6470,  6641,   563,
   -1342, -1342, -1342,  6787,  6815, -1342,  7145,  1671, -1342,  5284,
   -1342,  1608,  1676,  9994, -1342, -1342, -1342, -1342, -1342, -1342,
    1487, -1342, -1342,   807,   825,  7787,  3127,  1680,  1488, -1342,
    6891, -1342,  1485,  1490,   159, -1342,  1489,   161, -1342,  1492,
     168, -1342,  1494,  9173,  1692,  5284,  1693,  1498,  6891, -1342,
    6064,   232, -1342,   830,   250,   252, -1342,  1697,  7173, -1342,
   -1342,  8256,  8282,  8308,  8334,  1567,  6891, -1342,  6891, -1342,
   -1342,  6702,  3168,  1701,  1505,  1704, -1342, -1342,  3847, -1342,
   -1342,  4975,  9994, -1342, -1342, -1342, -1342,    24, -1342,  1571,
   -1342, -1342,  6891,  8360,  8386, -1342,  5284,  6891,  1708, -1342,
    8412, -1342, -1342,  1711,  1712,  1713,  1730,  1733,  1736,   836,
    1541, -1342,  5284,   248,   429,  6702, -1342, -1342,    22,  5613,
   -1342, -1342,  6318,  1284,  6318,  1284,  6318,  1284,  1739, -1342,
     837,  5284, -1342,  7201,   -91,  1740,  6702,   -91, -1342, -1342,
    6891,  6891,  6891,  6891,  6891,  7229,  7257,   841, -1342, -1342,
    1741, -1342,   849,   835,   850,  1742, -1342,  1551,  9994,  6891,
    6891,   879,  9994, -1342,  6891,   880,   886, -1342, -1342, -1342,
   -1342, -1342, -1342,  1561,  6891,   887,  1566,   -91,  5284,  1743,
    1568,   -91,  1744,   890,  1549,  6891, -1342,  7285,   263,   614,
    7313,   340,   762,  7341,   348,   948, -1342,  5284,  1753,  1674,
    3496,  1576,   350, -1342,   894,   370,  8438,  8464,  8490,  8516,
    3353, -1342, -1342,  1768, -1342,  6891, -1342,  5362, -1342, -1342,
    6891,  9952,  8542,    44,  8568, -1342, -1342,  6891,  7369,  1770,
     -91,    76, -1342, -1342,   -91,    86, -1342,  1771, -1342,  7397,
    1774,  6891,  1775,  1776,  6891,  1777,  1778,  6891,  1779,  1584,
   -1342,  6891, -1342,  1284, -1342,  6702,  1780,  6064,  6891,  6891,
    6891,  6891, -1342, -1342,  1338, -1342,   901, -1342,  6891, -1342,
    5284,  6891,  8594, -1342, -1342,   382, -1342,   389, -1342, -1342,
   -1342, -1342,  1588,  7425, -1342, -1342,  1589,  7453, -1342, -1342,
    1593,  7481, -1342,  1783,  3375,   996,  3693,   905, -1342,   412,
     923,  8620,  8646,  8672,  8698,  5362,  1792,  1598,  9973,   924,
    7509,  6891,   -91,   -91,  1284,  1796,  1284,  1797,  1284,  1798,
   -1342, -1342, -1342, -1342,  1284,  1799,  6702,  1800,  6891,  6891,
    6891,  6891, -1342, -1342,  4975, -1342,  1604,  1808,  7537,   442,
     497,  1087, -1342,  1612,  1153, -1342,  1619,  1186, -1342,  1620,
    1381, -1342,   928, -1342,  8724,  8750,  8776,  8802,   932, -1342,
    1621,  5284, -1342,  1810,  6891,  6891,  1811,  1284,  1812,  1284,
    1814,  1284, -1342,  1819,  6891,  6891,  6891,  6891,  4975,  1820,
    4975,   936, -1342,  7565,  7593, -1342,  1970, -1342,  2025, -1342,
    2058, -1342,  7621,  7649,  7677,  7705, -1342, -1342,   940, -1342,
    1822,  1823,  1824,  1834,  1839,  1840, -1342, -1342, -1342, -1342,
    4975,  1841, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     0,     0,   247,   248,     0,     0,     0,
     242,     0,     0,     0,     0,   343,   344,   345,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   519,     0,
     392,   518,   491,   393,   395,   396,   394,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   493,     0,   511,   495,   400,   401,   402,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
     398,   399,   494,     0,     0,     0,     0,    66,    67,     0,
       0,   187,     0,     0,     0,   350,     0,   487,   519,   406,
       0,     0,     0,     0,   227,     0,   229,   230,   225,   226,
       0,   231,   232,   109,   117,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,     0,   187,   519,     0,     0,   340,     0,
       0,     0,     0,     0,     0,     0,     0,   518,   446,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   468,   469,
     439,   445,     0,   440,   519,   406,     0,     0,     0,     0,
     518,     0,     0,   481,     0,     0,     0,     0,   223,   224,
       0,   518,     0,     0,   240,   241,     0,   187,     0,   187,
     518,     0,     0,   346,     0,     0,    66,    67,     0,     0,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     353,   352,   354,     0,     0,     0,     0,     0,     0,     0,
     186,     0,   185,     0,    68,    69,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,   216,     0,     0,   414,   164,
       0,   518,     0,   487,   488,     0,     0,   514,     0,   107,
     107,     0,     0,     0,     0,   475,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   187,   187,     0,   430,   429,
       0,     0,     0,     0,   187,   187,     0,     0,     0,     0,
       0,     0,     0,   258,     0,   187,     0,     0,     0,     0,
       0,   310,     0,     0,     0,     0,     0,     0,     0,   205,
     341,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,   452,     0,     0,   453,     0,   454,
       0,   455,     0,     0,     0,     0,     0,     0,   352,   447,
       0,   441,     0,     0,     0,   318,    66,    67,     0,   222,
       0,     0,     0,     0,     0,   187,     0,     0,     0,     0,
       0,   244,   243,   210,     0,   211,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,   512,     0,     0,     0,     0,     0,     0,     0,
       0,   351,     0,    59,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,   188,     0,     0,    59,     0,     0,
     368,   367,   365,   366,   361,   363,   362,   364,   356,   355,
     357,   358,   359,   360,     0,     0,     0,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   337,   338,   339,     0,     0,     0,     0,
     306,     0,     0,     0,   132,   133,     0,   135,   136,     0,
     138,   139,     0,   141,   142,     0,     0,     0,     0,     0,
       0,     0,   152,   187,     0,     0,     0,     0,     0,   432,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,   321,     0,
       0,   206,     0,     0,   202,     0,     0,     0,   336,   335,
       0,     0,     0,     0,   419,     0,   470,     0,     0,     0,
       0,     0,     0,   456,     0,   457,     0,   458,     0,   459,
       0,     0,   351,   442,   449,     0,   357,   448,     0,   471,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
       0,   212,   214,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    74,     0,   408,   407,   421,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   391,   379,
       0,   381,   382,   383,   384,   385,   386,   387,     0,     0,
       0,   503,     0,   508,   499,   500,   501,     0,     0,     0,
       0,     0,   504,   505,   506,   427,   510,   121,   126,    99,
       0,   496,   498,     0,   405,   411,   412,   492,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,     0,
     413,     0,     0,     0,     0,   516,     0,     0,     0,    44,
       0,     0,     0,    57,     0,    35,    36,    37,    38,    39,
     410,   409,     0,   489,    24,    22,     0,     0,    25,     0,
       0,   217,   515,    70,   110,    71,   118,     0,     0,     0,
     477,   478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   309,   307,     0,   317,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   215,     0,     0,     0,   177,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,     0,   249,     0,     0,     0,
       0,     0,     0,   311,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   407,     0,   472,     0,   451,
       0,     0,     0,     0,     0,     0,     0,   443,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   209,     0,     0,   347,     0,     0,     0,     0,   517,
       0,     0,     0,   416,     0,   415,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     0,    84,    89,    91,
       0,     0,   485,     0,    97,     0,     0,     0,     0,     0,
      75,   369,     0,     0,     0,     0,     0,    30,   418,   417,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,   315,     0,     0,   134,     0,   137,     0,   140,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,   292,     0,   298,     0,   300,     0,   294,     0,   296,
       0,   259,   288,     0,     0,     0,   200,     0,     0,     0,
     322,     0,   204,   203,   342,     0,     0,    31,    32,     0,
       0,     0,     0,     0,     0,     0,   460,   461,   462,   463,
     450,   444,     0,     0,     0,     0,   482,     0,     0,     0,
     235,     0,     0,     0,     0,     0,    87,     0,    86,     0,
      76,   219,   420,   218,   380,   388,   389,   390,   509,     0,
     424,   425,   426,     0,     0,   404,   122,     0,   513,   127,
     423,   497,    78,    59,     0,     0,     0,     0,    77,     0,
       0,     0,   483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   437,     0,     0,    26,    27,     0,    28,     0,
       0,   111,   114,    72,    73,   148,     0,     0,     0,     0,
       0,     0,   151,     0,     0,   167,   168,     0,     0,   153,
     174,     0,     0,     0,     0,   144,     0,   314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,   187,   187,     0,   269,     0,   271,
       0,   273,     0,   439,     0,     0,   299,   301,   295,   297,
       0,     0,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   420,   473,     0,     0,     0,     0,
     474,   156,   157,     0,     0,     0,     0,   100,   104,     0,
       0,   348,    80,    79,     0,   422,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,    95,     0,   486,   189,
     190,   191,   192,     0,     0,    40,     0,     0,     0,     0,
       0,    42,   490,     0,     0,   112,   115,     0,     0,   147,
     154,   155,   159,     0,     0,   169,     0,     0,   316,     0,
     162,     0,     0,   305,   173,   149,   161,   172,   176,   160,
       0,   170,   175,     0,     0,     0,     0,     0,     0,   436,
       0,   435,     0,     0,     0,   260,     0,     0,   261,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,   198,     0,     0,     0,   193,     0,     0,   319,
      33,     0,     0,     0,     0,     0,     0,   480,     0,   237,
     236,     0,     0,     0,     0,     0,   502,   507,     0,   123,
     125,     0,   128,   129,   130,    90,    92,     0,    98,     0,
      81,    45,     0,     0,     0,   438,     0,     0,     0,    29,
       0,   121,   126,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,   312,   312,     0,   105,   106,   187,     0,
     180,   181,     0,     0,     0,     0,     0,     0,     0,   289,
       0,     0,   187,     0,     0,     0,     0,     0,   184,   183,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
       0,    82,     0,   475,     0,     0,   484,     0,    41,     0,
       0,     0,    43,    58,     0,     0,     0,   330,   332,   331,
     333,   334,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,     0,
     254,     0,     0,   194,     0,     0,     0,     0,     0,     0,
       0,   479,   238,     0,   349,     0,   124,     0,   131,    96,
       0,     0,     0,     0,     0,   113,   116,     0,     0,     0,
       0,     0,   313,   323,     0,     0,   324,     0,   178,     0,
     275,     0,     0,   277,     0,     0,   279,     0,     0,     0,
     290,     0,   250,     0,   187,     0,     0,     0,     0,     0,
       0,     0,   158,   103,     0,   119,     0,    49,     0,    55,
       0,     0,     0,   145,   171,     0,   327,     0,   328,   329,
     433,   263,     0,     0,   270,   264,     0,     0,   272,   265,
       0,     0,   274,     0,     0,     0,   256,     0,   197,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,   283,     0,   285,
     291,   302,   255,   251,     0,     0,     0,     0,     0,     0,
       0,     0,   120,    46,     0,    53,     0,     0,     0,     0,
       0,     0,   266,     0,     0,   267,     0,     0,   268,     0,
       0,   201,     0,   195,     0,     0,     0,     0,     0,    47,
       0,     0,   228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,   276,     0,   278,     0,   280,
       0,   196,     0,     0,     0,     0,    48,    50,     0,    51,
       0,     0,     0,     0,     0,     0,   464,   465,   466,   467,
       0,     0,    56,   325,   326,   282,   284,   286,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1342, -1342, -1342, -1342,   725, -1342, -1342, -1342, -1342,   210,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342,  -393,  -103,  3281,    -1, -1342,  1402, -1342, -1342,
   -1342, -1342, -1342,   335, -1342,   337, -1342, -1342, -1342, -1342,
   -1342, -1342,   731,  1855,    -2,  -494,  -258, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342,  1857, -1342, -1342, -1342, -1342, -1342,
   -1342, -1342, -1342, -1342, -1342, -1342, -1342, -1342,  -966,  -948,
   -1342, -1342,  1401, -1342,   352, -1342, -1342, -1342, -1342,  1546,
   -1342, -1342,    61, -1342, -1341,  1828,   291,  1892,   898,  -245,
     620, -1342,    21,    62, -1342,  -368,    -3,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   936,    91,    92,   684,  1404,  1410,
     925,  1112,  1577,  1778,   926,  1727,  1818,   927,  1780,   928,
     929,  1116,   347,   438,   183,   417,    93,   699,   449,  1521,
    1522,   450,  1572,  1087,  1256,  1088,  1259,   733,   736,   739,
     742,  1432,  1299,   664,   298,   411,   412,    96,    97,    98,
      99,   100,   101,   102,   299,  1017,  1673,  1744,   768,  1456,
    1459,  1462,  1702,  1706,  1710,  1763,  1766,  1769,  1013,  1014,
    1151,   973,   730,   777,  1599,   104,   105,   106,   107,   300,
     185,   887,   499,   256,  1281,   301,   302,   303,   562,   312,
     909,  1103,   447,   443,   888,   448,   188,   305
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,    95,   494,  1059,   513,   525,   348,   626,   349,   628,
     761,   762,   654,   544,   667,  1473,   528,   321,   213,   272,
     639,   919,  1389,   213,   668,   547,   409,   186,   310,   218,
     573,   549,   551,   907,   218,   182,   326,   328,   803,   690,
    1183,   805,   807,   809,   691,  1185,  1187,     4,   194,  1189,
    1689,  1194,   333,   688,   275,   689,   314,   405,     5,   277,
     182,   278,   304,   502,   503,  1192,   191,   275,   187,   584,
     190,   586,   934,   502,   503,   502,   503,  1286,   275,  1336,
    1295,  1337,  1696,   345,   346,   667,   502,   503,  1529,  1338,
     209,  1339,  1698,  1174,  -488,   251,   252,   210,   109,   502,
     503,   189,  1340,   192,  1341,   253,   502,   503,   502,   503,
     255,   257,   254,   263,   193,   340,   504,   247,   502,   503,
     502,   503,   516,   505,   756,    48,    49,    50,    51,   517,
     653,   279,   248,   249,    56,   515,   763,    59,   200,   667,
    1093,   502,   503,   322,   325,   502,   503,   920,   921,   922,
     923,   545,   276,   345,   346,   692,   196,   769,   502,   503,
     693,  1170,  1184,   548,  -489,   313,   273,  1186,  1188,   550,
     552,  1190,  1390,   197,  1193,  1581,   323,   275,   209,   410,
     341,   342,   343,   344,    89,   911,    89,   345,   346,   275,
     275,  1595,   198,   406,   407,    89,  1060,   275,  -490,   526,
     350,   221,   351,   842,   352,   275,   182,   304,   914,   182,
     214,   546,   304,   442,   445,   214,   304,   215,   274,   304,
     199,   924,   912,   304,   304,   304,   304,   311,   219,   304,
     304,   304,   908,   913,   327,   329,   804,   754,   755,   806,
     808,   810,   334,   304,   275,   195,  1192,  1690,   315,   335,
     935,   341,   342,   343,   344,   935,  1263,   770,   898,   901,
     502,   503,   502,   503,   201,   304,   304,   304,   202,   451,
     345,   346,   502,   503,   222,   408,  1094,  1095,   900,   304,
     304,   341,   342,   343,   344,   345,   346,   444,   444,   268,
     203,   269,   304,  1210,   304,   444,   341,   342,   343,   344,
     345,   346,   655,   452,   695,   341,   342,   343,   344,   696,
     204,   497,   498,   885,   211,   345,   346,   825,   696,   506,
     502,   503,   892,   514,   345,   346,   205,   893,   206,   275,
     833,   304,   304,   264,   212,   563,  1468,   259,   596,  1004,
     260,   216,   313,   261,   304,   502,   503,   502,   503,  1729,
    1005,  1596,  1597,   589,   502,   503,   217,  1598,  1006,  1007,
    1008,  1542,   220,  1544,  1009,  1010,  1011,  1012,   243,   221,
    1546,   244,   275,   275,   275,   275,   275,   275,   304,   275,
     275,   223,   275,   275,   275,   275,   275,   706,   224,   707,
     275,   275,   275,   275,   275,   282,   275,   627,   283,   629,
     630,   631,   597,   633,   634,   265,   636,   637,   638,   266,
     640,   345,   346,   304,   644,   645,   646,   647,   502,   503,
     226,   267,   341,   342,   343,   344,   539,   444,   540,   706,
     541,   712,   225,   181,  1554,   182,   502,   503,   502,   503,
    1801,   345,   346,   230,  1191,  1065,  1067,   251,   252,   502,
     503,   304,  1556,   642,  1557,   236,   227,   253,   237,   228,
     649,   238,   229,   239,   262,  1661,   706,   336,   716,   337,
     444,   444,   444,   444,   444,   444,   338,   444,   444,   231,
     444,   444,   444,   444,   444,   235,   304,   304,   444,   444,
     444,   444,   648,   232,   650,   991,   233,   245,   234,  1488,
     848,   246,   410,   410,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   564,   431,   432,   473,   474,
     475,   250,   433,   478,   479,   480,   502,   503,   304,   304,
     304,  1464,  1600,  1601,   502,   503,   502,   503,  1598,   258,
     275,   796,  1664,   270,   735,   738,   741,   744,   899,   902,
    1667,   271,  1675,   436,   304,   437,   502,   503,   280,   521,
     522,   304,   338,   759,   760,  1123,   281,   819,   502,   503,
     706,   498,  1677,   534,   535,   502,   503,  1609,   706,  1612,
     722,  1615,  1229,  1154,  1732,  1156,   706,  1158,   813,  1160,
     284,  1733,   304,   428,   429,   430,   431,   432,   502,   503,
    1329,  1330,   433,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   859,  1746,   861,   862,   863,   864,   865,
     866,   867,  1004,  1378,  1379,   871,   873,   874,   502,   503,
     836,   697,   837,  1005,   698,   882,   883,   884,   797,   886,
    1124,  1006,  1007,  1008,  1784,   706,   894,  1009,  1010,  1011,
    1012,   350,   307,   587,  1511,   541,   414,   910,   415,  1512,
     182,  1192,   416,  1102,  1192,   304,   285,  1192,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   286,   502,   503,   566,   433,   567,   304,   700,
     304,   848,   698,   275,   338,  1489,   275,   308,   275,  1785,
    1264,   306,   304,   304,   309,   240,   553,  1715,   241,   554,
     242,   316,   555,  1004,   556,   903,  1277,   942,   430,   431,
     432,   414,   946,   415,  1005,   433,   304,  1352,   706,   706,
     916,   987,  1006,  1007,  1008,  1066,  1068,   317,  1009,  1010,
    1011,  1012,   318,  1073,  1075,   418,   706,   304,   988,   502,
     503,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   948,   319,  1192,  1761,   433,
    1764,  1230,  1767,   706,   706,  1029,  1030,   320,  1770,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   444,   304,   378,   944,   433,   444,   706,   414,  1031,
     415,   304,   332,   304,   595,   304,   379,   304,   414,   706,
     415,  1047,   304,  1192,   795,   304,  1192,   994,  1662,  1192,
     380,  1806,  1192,  1808,  1000,  1810,   392,  1118,  1119,   414,
    1015,   415,   414,   304,   415,   818,   706,   696,  1070,   304,
    1452,  1453,  1637,   563,   275,   414,  1384,   415,   399,   414,
     872,   415,   381,   382,   706,  1269,   383,  1130,  1192,  1131,
    1192,  1004,  1192,   388,  1136,   414,  1137,   415,  1076,   304,
    1254,   706,  1005,  1167,   275,   304,   275,   275,   393,   394,
    1006,  1007,  1008,   706,   395,  1211,  1009,  1010,  1011,  1012,
     275,   414,   706,   415,  1216,   706,  1257,  1217,  1082,   397,
    1084,  1085,   706,   398,  1218,   275,   460,   413,   304,   304,
     304,   304,     7,     8,  1090,  1109,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     434,   435,  1075,   275,   433,   706,   706,  1219,  1221,   706,
     439,  1222,   444,  1086,   465,   470,  1127,  1128,   471,   476,
     304,   304,  1271,   304,  1272,   304,   304,  1122,   489,   304,
     304,   706,   492,  1273,   304,   706,  1665,  1274,   706,   706,
    1275,  1276,   444,   477,   444,   444,   660,    24,    25,   661,
      27,    28,   662,    30,   663,    32,   481,    33,   444,   706,
    1265,  1313,    38,    39,   482,    41,    42,    43,  1408,   527,
    1409,    46,  1440,   313,  1441,   706,  1517,  1477,  1518,   706,
    1129,  1533,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   705,   431,   432,  1398,   706,   483,  1534,
     433,   444,  1408,   338,  1555,    67,    68,    69,  1408,  1617,
    1593,  1618,   484,   706,  1604,  1633,   495,  1004,   304,   304,
     304,  1635,   696,  1636,  1638,   687,   485,   486,  1005,   304,
     487,   488,  1175,  1176,  1177,   496,  1006,  1007,  1008,  1239,
     507,   508,  1009,  1010,  1011,  1012,  1244,  1245,  1246,  1247,
    1248,  1408,  1254,  1643,  1645,   509,  1255,  1258,  1257,  1408,
    1646,  1649,   706,   518,  1657,  1004,   706,   275,  1676,   519,
       7,     8,   520,  1517,   784,  1726,  1005,   706,   457,  1745,
     524,   529,   304,   462,  1006,  1007,  1008,   466,   530,   531,
    1009,  1010,  1011,  1012,   472,   706,  1408,  1747,  1756,   532,
     706,   304,  1793,  1574,  1798,   536,  1799,   304,  1408,  1385,
    1820,   533,  1830,   304,  1831,   304,   304,   537,   538,   543,
     304,   304,  1668,   304,   565,   304,   569,   304,   575,   304,
     304,   304,   576,   581,   660,    24,    25,   661,    27,    28,
     662,    30,   663,    32,   182,    33,   582,   304,   583,   585,
      38,    39,   594,    41,    42,    43,  1004,   599,  1292,    46,
     600,   603,   304,   656,   433,   313,   304,  1005,   304,   657,
    1742,   659,   719,   181,   702,  1006,  1007,  1008,   703,   723,
    1365,  1009,  1010,  1011,  1012,   724,   725,   751,   728,   729,
     752,  1370,   776,    67,    68,    69,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     753,   778,   794,   779,   433,   781,   275,   788,   789,   823,
     798,   800,  1004,   801,  1351,   802,   826,   834,   835,   843,
     844,  1385,  1575,  1005,   875,   876,   877,   878,   275,   891,
    1386,  1006,  1007,  1008,   304,   879,   880,  1009,  1010,  1011,
    1012,   441,   112,   890,   275,  1004,   895,   304,   896,   897,
     906,  1786,   831,   905,  1620,   933,  1005,   949,   938,   941,
     943,   945,   952,   953,  1006,  1007,  1008,   954,  1413,   956,
    1009,  1010,  1011,  1012,   666,  1387,   958,   139,   140,   141,
     142,   143,   144,   304,   304,  1391,   148,   149,   150,   151,
     959,   957,   410,   410,   153,   154,   155,   961,   962,   156,
     963,   967,   974,   972,   444,  1725,   976,   977,   978,   979,
     161,   304,  1416,   304,   981,   304,   983,  1788,   980,  1419,
     982,  1024,   990,  1051,   997,  1037,   313,  1052,   998,  1053,
     304,  1038,  1040,  1064,  1041,  1092,  1054,   304,  1042,  1097,
    1062,   304,   444,  1004,  1098,   304,  1497,   748,   749,  1100,
    1790,  1101,  1447,   889,  1005,  1104,  1110,  1454,  1113,  1457,
    1114,  1460,  1006,  1007,  1008,   304,  1117,  1121,  1009,  1010,
    1011,  1012,  1126,  1134,  1140,  1471,  1716,  1145,  1474,  1475,
    1115,  1141,  1146,  1148,  1149,  1152,   304,  1153,  1162,   785,
     786,   787,  1163,  1164,  1165,   164,   165,  1166,  1168,  1178,
    1180,  1493,  1179,  1181,  1182,  1195,   172,  1196,    89,   173,
    1500,  1503,  1504,  1197,  1198,   811,  1199,  1202,  1201,  1203,
    1204,  1205,   304,  1206,  1207,  1208,  1234,   304,  1226,   345,
     346,  1231,  1232,  1242,     7,     8,  1236,  1074,  1238,  1240,
    1004,  1241,  1243,  1249,  1253,  1250,  1251,  1267,   304,  1285,
    1288,  1005,  1293,   841,  1252,   304,  1261,  1278,   275,  1006,
    1007,  1008,  1294,  1266,   275,  1009,  1010,  1011,  1012,  1283,
    1284,  1296,  1302,   304,  1297,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   304,
    1303,  1298,   304,   433,  1305,  1304,   410,  1306,   660,    24,
      25,   661,    27,    28,   662,    30,   663,    32,   304,    33,
    1308,  1316,   184,   304,    38,    39,  1309,    41,    42,    43,
       7,     8,  1310,    46,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,  1311,  1326,
    1317,  1346,   433,  1327,  1328,  1792,  1334,  1335,  1347,   937,
    1342,   939,  1348,  1349,  1356,   304,   444,    67,    68,    69,
    1357,  1361,   313,  1608,  1364,  1611,  1380,  1614,  1371,  1372,
    1373,  1377,  1381,  1388,   304,  1622,  1393,  1394,  1625,  1496,
    1396,  1399,  1400,  1401,   660,    24,    25,   661,    27,    28,
     662,    30,   663,    32,   331,    33,  1402,  1412,  1420,  1427,
      38,    39,  1421,    41,    42,    43,  1422,  1425,   989,    46,
    1428,  1429,  1430,  1431,  1434,  1509,  1435,  1436,  1651,  1437,
    1438,  1439,  1655,  1442,  1455,  1458,   832,  1461,  1465,  1469,
    1472,  1476,   304,  1480,   304,  1505,  1528,  1507,  1508,  1510,
    1516,  1519,  1531,    67,    68,    69,  1537,   304,  1530,  1540,
    1532,  1538,  1543,  1036,  1541,  1545,  1099,  1547,  1549,  1685,
    1551,  1552,  1043,  1558,  1044,  1564,  1045,  1569,  1046,  1570,
    1571,  1695,  1576,  1049,  1583,  1697,  1050,  1587,  1588,  1589,
     400,   401,   402,   403,   404,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,  1590,   440,  1719,  1591,
     433,   446,  1592,   304,  1594,  1616,  1623,  1634,  1639,  1653,
    1656,   275,   992,  1658,  1640,   453,   455,   458,   459,  1670,
     461,   455,   463,   464,  1647,   455,   467,   468,  1144,  1650,
    1081,  1654,   455,  1671,  1683,  1779,  1694,  1699,   304,  1674,
    1701,  1704,  1705,  1708,  1709,  1712,  1718,  1752,  1713,  1740,
     491,  1734,  1736,  1759,  1760,   275,  1738,   275,  1753,   500,
     501,  1754,  1762,  1765,  1768,  1771,  1773,  1781,   501,  1105,
    1106,  1107,  1108,  1200,  1782,  1787,  1802,  1805,  1807,  1816,
    1809,  1819,  1789,  1791,  1800,  1811,  1817,   275,  1832,  1833,
    1834,   424,   425,   426,   427,   428,   429,   430,   431,   432,
    1835,   558,   560,   455,   433,  1836,  1837,  1839,  1287,   444,
    1686,  1838,   701,   570,   571,   572,  1585,   574,    94,  1586,
     103,   577,   578,   579,  1300,  1147,   580,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   731,   592,   593,     0,   433,  1602,  1395,     0,     0,
       0,     0,     0,   444,     0,   444,   601,   602,     0,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,     0,     0,     0,     0,   444,     0,     0,     0,     0,
     635,     0,     0,     0,     0,     0,   641,     0,   643,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,   665,
       0,     0,   455,     0,     0,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
       0,     0,   685,   686,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
     558,     0,   433,     0,     0,     0,   710,     0,     0,     0,
       0,   715,     0,     0,     0,     0,   720,   721,     0,     0,
       0,     0,   726,   727,     0,     0,     0,   732,   734,   737,
     740,   743,   745,   746,   747,   455,   455,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,   764,   765,   766,   400,   401,   767,     0,
       0,     0,   771,   772,   773,   774,   775,     0,     0,  1004,
     780,     0,   782,   783,   493,     0,     0,   455,   455,   455,
    1005,     0,   790,   791,   792,   601,   793,     0,  1006,  1007,
    1008,     0,   799,     0,  1009,  1010,  1011,  1012,   523,  1360,
       0,     0,   456,   455,  1262,     0,     0,   456,     0,   814,
     816,   456,   685,   686,     0,     0,     0,     0,   456,     0,
       0,     0,     0,     0,  1004,     0,     0,     0,     0,     0,
       0,     0,     0,   793,     0,  1005,     0,     0,     0,     0,
     840,   455,     0,  1006,  1007,  1008,   845,     7,     8,  1009,
    1010,  1011,  1012,     0,     0,     0,     0,  1004,     0,     0,
       0,     0,   590,   591,     0,     0,     0,     0,  1005,     0,
       0,     0,     0,     0,  1823,   598,  1006,  1007,  1008,     0,
       0,     0,  1009,  1010,  1011,  1012,     0,   559,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     904,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,   660,    24,    25,   661,    27,    28,   662,    30,   663,
      32,     0,    33,     0,  1443,  1444,     0,    38,    39,  1824,
      41,    42,    43,     0,   932,     0,    46,   455,     0,   455,
     940,     0,     0,     0,     0,     0,     0,     0,   947,     0,
       0,   816,   950,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1825,     0,     0,   964,     0,     0,     0,     0,
      67,    68,    69,     0,   970,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,   455,  1268,     0,     0,
       0,     0,     0,   995,   996,     0,     0,     0,   456,   999,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1023,     0,     0,  1025,  1382,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   993,
       0,   455,     0,     0,     0,     0,   559,     0,     0,     0,
     455,     0,   455,     0,   455,     0,   455,     0,     0,     0,
       0,   455,     0,     0,   455,     0,     0,     0,     0,     0,
    1055,     0,  1057,  1058,     0,     0,     0,     0,     0,     0,
       0,   456,   456,     0,     0,     0,     0,  1383,     0,  1567,
       0,     0,   660,    24,    25,   661,    27,    28,   662,    30,
     663,    32,     0,    33,     0,     0,  1077,     0,    38,    39,
       0,    41,    42,    43,  1078,  1079,  1080,    46,   455,     0,
       0,     0,     0,   456,   456,   456,     0,     0,     0,     0,
       0,     0,     0,  1603,     0,     0,  1089,     0,     0,     0,
       0,     0,     0,     0,  1091,     0,     0,  1096,     0,   456,
       0,    67,    68,    69,  1624,     0,   817,   455,   455,   455,
     455,     0,     0,     0,  1111,     0,     7,     8,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,   456,     0,     0,
       0,     0,     0,     0,     0,     0,   917,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,   455,     0,   433,     0,     0,     0,     0,
    1016,     0,     0,  1155,     0,  1157,     0,  1159,     0,  1161,
     660,    24,    25,   661,    27,    28,   662,    30,   663,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     7,     8,     0,    46,     0,   971,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,  1717,     0,  1720,   433,     0,     0,     0,
    1209,     0,     0,   456,  1212,   456,  1213,  1214,  1215,    67,
      68,    69,     0,     0,  1220,     0,     0,   817,   951,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1235,     0,  1237,     0,     0,   660,    24,    25,   661,
      27,    28,   662,    30,   663,    32,     0,    33,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,     0,
       0,    46,   456,     0,  1772,     0,     0,  1270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1056,  1279,
    1280,     0,     0,     0,  1063,     0,     0,     0,     0,     0,
    1071,  1289,  1291,     0,     0,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   456,     0,     0,
       0,     0,     0,     0,     0,     0,   456,     0,   456,     0,
     456,     0,   456,     0,     0,     0,  1083,   456,     0,     0,
     456,     0,     0,     0,     0,     0,  1331,  1332,  1333,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,  1345,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1350,
       0,     0,     0,     0,  1061,     0,     0,   455,     0,     0,
       0,     0,  1362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   456,     0,     0,     0,     0,     0,
       0,     0,     0,  1374,  1375,  1376,     0,     0,     0,     0,
       0,  1132,  1133,     0,  1135,     0,  1138,  1139,     0,     0,
    1142,  1143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   456,   456,   456,     0,     0,     0,
    1392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1405,     0,     0,     0,     0,  1411,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1417,  1418,     0,     0,     0,     0,     0,  1423,
    1424,     0,     0,     0,  1426,     0,     0,     0,     0,   456,
       0,     0,  1433,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   455,   455,  1445,     0,  1446,     0,     0,  1223,
    1224,  1225,     0,     0,     0,     0,     0,     0,  1463,     0,
    1233,     0,     0,  1479,     0,     0,     0,     0,     0,     0,
     455,     0,     0,     0,   455,     0,     0,  1478,     0,     0,
       0,     0,  1481,  1482,  1483,  1484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1502,     0,     0,     0,     0,
       0,     0,     0,  1282,     0,     0,     0,     0,     0,     0,
       0,     0,  1513,  1514,     0,     0,     0,     0,     0,     0,
    1520,     0,  1301,     0,     0,     0,     0,     0,  1307,     0,
       0,     0,     0,     0,  1312,     0,  1314,  1315,     0,     0,
       0,  1318,  1319,  1506,  1320,     0,  1321,     0,  1322,     0,
    1323,  1324,  1325,     0,     0,     0,  1539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1344,     0,
       0,     0,     0,     0,  1553,     0,   558,     0,     0,     0,
       0,     0,     0,  1355,     0,     0,     0,  1359,     0,     0,
       0,     0,  1565,     0,  1566,     0,     0,   455,     0,     0,
       0,     0,     0,     0,  1573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1578,     0,
       0,     0,     0,  1582,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,   455,   433,     0,     0,     0,     0,     0,  1607,     0,
    1610,     0,  1613,   456,     0,     0,     0,     0,     0,     0,
       0,     0,   455,     0,     0,  1403,  1626,  1627,  1628,  1629,
    1630,     0,     0,     0,     0,     0,     0,     0,  1415,     0,
       0,     0,     0,     0,     0,  1641,  1642,     0,     0,     0,
    1644,     0,     0,  1536,     0,     0,     0,     0,     0,     0,
    1648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1659,     0,     0,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,  1568,     0,     0,     0,     0,     0,
       0,  1684,     0,     0,  1282,     0,  1411,     0,     0,     0,
       0,     0,     0,  1692,     0,     7,     8,     0,     0,     0,
       0,  1485,     0,     0,     0,     0,     0,  1703,  1494,     0,
    1707,     0,  1495,  1711,     0,     0,  1499,  1714,   456,   456,
       0,   455,     0,   455,  1721,  1722,  1723,  1724,     0,     0,
       0,     0,     0,     0,  1728,     0,  1515,  1730,     0,     0,
       0,     0,     0,     0,     0,     0,   456,     0,     0,     0,
     456,     0,     0,     0,     0,     0,     0,  1282,     0,   660,
      24,    25,   661,    27,    28,   662,    30,   663,    32,     0,
      33,     0,     0,     0,     0,    38,    39,  1758,    41,    42,
      43,     0,     0,     0,    46,     0,  1150,     0,     0,     0,
       0,     0,   455,  1550,  1774,  1775,  1776,  1777,     0,     0,
       0,     0,   207,   208,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,    67,    68,
      69,     0,   433,     0,     0,     0,     0,     0,     0,     0,
    1803,  1804,     0,     0,     0,     0,     0,     0,     0,     0,
    1812,  1813,  1814,  1815,  1282,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,  1682,
    1282,     0,   559,   433,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,  1619,
       0,  1741,   433,   456,     0,     0,     0,  1169,     0,   339,
     456,     0,     0,     0,     0,     0,     0,     0,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,     0,     0,     0,  1652,   456,     0,   384,
     385,   386,   387,     0,     0,   389,     0,     0,     0,     0,
       0,   390,   391,     0,     0,  1669,     0,   396,   456,     0,
       0,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   153,   154,   155,     7,     8,
     156,     0,   157,   158,   159,     0,     0,     0,  1282,     0,
     160,   161,     0,     0,     0,     0,     0,     0,     0,     0,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,   456,   542,   456,
     433,     0,   660,    24,    25,   661,    27,    28,   662,    30,
     663,    32,     0,    33,     0,   568,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,   162,
       0,     0,     0,     0,     0,   163,   164,   165,   166,  1282,
       0,     0,   167,   168,   169,   170,   171,   172,     0,    89,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,   174,   175,     0,     0,   456,   176,
       0,     0,     0,     0,   177,     0,   178,     0,   179,   180,
       0,   181,     0,   182,   110,   287,     0,     0,     0,     0,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   289,   658,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
    1672,     0,     0,     0,   152,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   290,     0,     0,
     291,     0,     0,   292,     0,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,   660,
      24,    25,   661,    27,    28,   662,    30,   663,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,   563,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,   166,     0,     0,   563,   167,   168,   169,   170,   171,
       0,     0,    89,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,     0,   510,  1470,     0,
       0,     0,   176,     0,     0,     0,     0,   512,     0,     0,
     110,   287,   180,     0,   254,   561,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   289,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,  1743,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   564,   431,   432,     0,     0,
       0,     0,   433,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   705,   431,   432,   827,     0,     0,
       0,   433,     0,     0,   163,     0,     0,   166,     0,     0,
       0,   167,   168,   169,   170,   171,   918,     0,    89,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   174,   454,     0,     0,   433,   176,     0,
       0,     0,     0,   296,  1450,     0,  1451,     0,   180,     0,
       0,   561,   110,   287,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   289,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   161,     0,     0,   290,     0,     0,   291,     0,
       0,   292,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,  1048,
       0,     0,     0,   433,     0,     0,   163,   164,   165,   166,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
      89,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   295,     0,     0,     0,
     176,     0,     0,     0,     0,   296,     0,   110,   287,   112,
     180,     0,   297,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   289,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,   161,     0,     0,
     290,     0,     0,   291,     0,     0,   292,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,     0,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   163,   164,   165,   166,   433,     0,     0,   167,   168,
     169,   170,   171,   172,   915,    89,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   295,     0,     0,     0,   176,     0,     0,     0,     0,
     296,     0,   110,   330,   112,   180,     0,  1498,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,  1228,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,   110,   330,   112,
       0,   160,   161,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   163,   164,   165,   166,
     433,     0,     0,   167,   168,   169,   170,   171,   172,   966,
      89,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
     176,     0,     0,     0,     0,   296,     0,     0,     0,     0,
     180,     0,  1290,     0,     0,     0,     0,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   163,   164,   165,   166,   433,     0,     0,   167,   168,
     169,   170,   171,   172,     0,    89,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,   175,     0,     0,     0,   176,     0,     0,     0,     0,
     296,     0,   110,   330,   112,   180,     0,  1491,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   161,     0,     0,     0,     0,     0,   321,   112,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,  1486,     0,  1487,     0,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   148,   149,   150,   151,     0,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
       0,     0,     0,   167,   168,   169,   170,   171,   172,     0,
      89,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
     176,     0,     0,     0,     0,   296,     0,   110,   287,   288,
     180,     0,  1501,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   289,   164,   165,     0,     0,     0,     0,     0,     0,
     145,   146,   147,   172,     0,    89,   173,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     290,     0,     0,   291,     0,     0,   292,     0,   293,   441,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   148,   149,   150,   151,     0,     0,
       0,     0,   153,   154,   155,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   163,     0,     0,   166,     0,     0,     0,   167,   168,
     169,   170,   171,     0,     0,    89,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     174,   295,     0,     0,   433,   176,   812,     0,     0,     0,
     296,   757,   110,   287,  1353,   180,     0,   297,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   289,     0,     0,     0,
       0,     0,     0,   164,   165,   145,   146,   147,     0,     0,
       0,     0,   152,     0,   172,     0,    89,   173,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   290,     0,     0,   291,     0,
       0,   292,     0,   293,   324,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   148,
     149,   150,   151,     0,     0,     0,     0,   153,   154,   155,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   163,     0,     0,   166,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   174,   295,     0,     0,   433,
     176,     0,     0,     0,     0,   296,   694,   110,   287,     0,
     180,     0,  1354,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   289,     0,     0,     0,     0,     0,     0,   164,   165,
     145,   146,   147,     0,     0,     0,     0,   152,     0,   172,
       0,     0,   173,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     290,     0,     0,   291,     0,     0,   292,   112,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
       0,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   148,   149,   150,   151,     0,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,   163,     0,     0,   166,     0,     0,     0,   167,   168,
     169,   170,   171,     0,     0,    89,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     174,   295,     0,     0,   433,   176,     0,     0,     0,     0,
     296,   757,   110,   287,     0,   180,     0,   297,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   289,     0,     0,     0,
     164,   165,     0,     0,     0,   145,   146,   147,     0,     0,
       0,   172,   152,     0,   173,     7,     8,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   290,     0,     0,   291,     0,
       0,   292,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,   660,
      24,    25,   661,    27,    28,   662,    30,   663,    32,     0,
      33,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,   166,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,   174,   454,     0,     0,     0,
     176,     0,     0,     0,     0,   296,     0,   110,   287,     0,
     180,     0,   557,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   289,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     290,     0,     0,   291,     0,     0,   292,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,  1605,     0,  1606,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,   166,     0,     0,     0,   167,   168,
     169,   170,   171,     0,     0,    89,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     174,   454,     0,     0,   433,   176,     0,     0,     0,     0,
     296,   758,   110,   287,     0,   180,     0,   815,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   289,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   290,     0,     0,   291,     0,
       0,   292,     0,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
       0,     0,  1019,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,   166,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   174,   295,     0,     0,   433,
     176,     0,     0,     0,     0,   296,   824,   110,   287,     0,
     180,     0,  1358,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   289,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   146,   147,     0,     0,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     290,     0,     0,   291,     0,     0,   292,     0,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     0,     0,     0,     0,    56,     0,     0,    59,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,  1039,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,   166,     0,     0,     0,   167,   168,
     169,   170,   171,     0,     0,    89,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     510,  1470,     0,     0,   433,   176,     0,     0,     0,     0,
     512,   860,   110,   330,     0,   180,     0,   254,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   330,   157,   158,   159,     0,   113,   114,   115,
       0,   160,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   146,   147,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,   163,     0,  1069,   166,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   174,   175,     0,     0,   433,
     176,     0,     0,     0,     0,   296,     0,     0,  1173,     0,
     180,     0,   490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,     0,     0,   166,     0,
       0,     0,   167,   168,   169,   170,   171,     0,     0,    89,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   510,   511,     0,     0,   433,   176,
       0,     0,     0,     0,   512,   868,   110,   330,   112,   180,
       0,   254,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,   161,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,     0,     0,  1448,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
       0,     0,  1467,     0,     0,     0,     0,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
     163,   164,   165,   166,  1523,     0,     0,   167,   168,   169,
     170,   171,   172,     0,    89,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     175,     0,     0,     0,   176,   110,   287,     0,     0,   296,
       0,   113,   114,   115,   180,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,  1524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   174,   454,
       0,     0,   433,   176,   110,   330,     0,     0,   296,   869,
     113,   114,   115,   180,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,  1525,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,   163,     0,
       0,   166,     0,     0,     0,   167,   168,   169,   170,   171,
       0,     0,    89,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,   174,   175,     0,
       0,     0,   176,     0,    -4,    -4,    -4,   296,     0,     0,
      -4,    -4,   180,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     6,     0,     0,     0,     0,    -4,
       0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     9,    10,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,    11,    12,    13,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,    18,     0,
      19,    20,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,    63,    64,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,    66,    67,    68,    69,     0,     0,
      70,     0,    71,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,    89,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1527,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,  1559,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,  1621,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,  1631,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,  1632,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1660,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,  1663,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,  1666,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,  1700,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1735,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,  1737,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,  1739,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,  1757,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,  1783,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1821,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,  1822,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
       0,     0,     0,     0,     0,  1826,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,  1827,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
       0,  1828,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,  1829,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,   588,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,     0,   750,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,     0,     0,     0,     0,
    1535,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,   870,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,   881,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1001,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1002,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1003,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1034,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1125,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1171,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1172,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1227,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1366,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1367,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1368,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1369,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1406,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1407,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1414,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1560,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1561,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1562,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1563,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1579,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1580,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1584,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1678,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1679,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1680,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1681,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1688,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1691,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1731,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1748,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1749,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1750,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,     0,     0,     0,
    1751,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,  1794,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,  1795,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,  1796,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,  1797,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,   414,     0,   415,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
     652,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,   830,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,   839,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,   847,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,   931,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,     0,     0,  1027,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,     0,     0,  1028,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,     0,
       0,  1032,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,     0,     0,  1033,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,     0,     0,  1035,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,     0,     0,
    1072,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,     0,     0,  1120,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,     0,     0,  1363,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,     0,     0,  1397,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
       0,     0,  1548,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,   651,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,   704,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,   708,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,   709,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,   711,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,   713,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,   714,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
     717,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,   718,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,   812,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,   820,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,   821,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,   822,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,   828,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,   829,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,   838,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,   846,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
     930,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,   955,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,   960,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,   965,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,   968,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,   969,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,   975,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,   984,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,   985,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,   986,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
    1018,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433,
       0,  1020,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,     0,     0,     0,     0,
     433,     0,  1021,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,     0,     0,     0,
       0,   433,     0,  1022,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,     0,     0,
       0,     0,   433,     0,  1026,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,     0,
       0,     0,     0,   433,     0,  1260,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
       0,     0,     0,     0,   433,     0,  1449,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,     0,     0,     0,     0,   433,     0,  1466,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,     0,     0,     0,     0,   433,     0,  1490,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,     0,     0,     0,     0,   433,     0,  1687,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,     0,     0,     0,     0,   433,     0,
    1755,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     0,     0,     0,     0,   433
};

static const yytype_int16 yycheck[] =
{
       3,     3,   247,     7,   262,     4,   109,   375,     4,   377,
     504,   505,   405,     5,     7,  1356,   274,     4,     4,     4,
     388,     4,     4,     4,   417,     5,     4,     6,     4,     4,
     200,     5,     5,     4,     4,   205,     5,     5,     5,   197,
       6,     5,     5,     5,   202,     6,     6,     6,     6,     6,
       6,  1017,     6,   198,    57,   200,     4,     4,     0,     4,
     205,     6,    65,   186,   187,  1013,    82,    70,     6,   327,
      13,   329,     6,   186,   187,   186,   187,     6,    81,   202,
       6,   204,     6,   192,   193,     7,   186,   187,  1429,   202,
     196,   204,     6,   204,   203,   186,   187,   203,     3,   186,
     187,     6,   202,   196,   204,   196,   186,   187,   186,   187,
      49,    50,   203,    52,   196,     7,   203,   140,   186,   187,
     186,   187,   196,   203,   202,   103,   104,   105,   106,   203,
       7,    76,   155,   156,   112,   203,   202,   115,   196,     7,
       4,   186,   187,    81,    82,   186,   187,   130,   131,   132,
     133,   143,    57,   192,   193,   197,     6,   202,   186,   187,
     202,   202,   128,   143,   203,    70,   151,   128,   128,   143,
     143,   128,   154,     6,   202,  1516,    81,   180,   196,   181,
     173,   174,   175,   176,   171,   203,   171,   192,   193,   192,
     193,  1532,     6,   140,   141,   171,   200,   200,   203,   198,
     196,   196,   198,   596,   200,   208,   205,   210,   203,   205,
     196,   203,   215,   192,   193,   196,   219,   203,   203,   222,
       6,   204,   203,   226,   227,   228,   229,   203,   203,   232,
     233,   234,   203,   203,   203,   203,   203,   495,   496,   203,
     203,   203,   196,   246,   247,   203,  1194,   203,   196,   203,
     184,   173,   174,   175,   176,   184,     7,   515,   651,   652,
     186,   187,   186,   187,     6,   268,   269,   270,     6,   207,
     192,   193,   186,   187,    86,   180,   140,   141,   200,   282,
     283,   173,   174,   175,   176,   192,   193,   192,   193,    82,
     198,    84,   295,   200,   297,   200,   173,   174,   175,   176,
     192,   193,   405,   208,   197,   173,   174,   175,   176,   202,
     198,   250,   251,   197,   196,   192,   193,   575,   202,   258,
     186,   187,   197,   262,   192,   193,   196,   202,   198,   332,
     588,   334,   335,     4,   196,     8,   202,    76,   339,    99,
      79,   196,   247,    82,   347,   186,   187,   186,   187,  1690,
     110,   103,   104,   332,   186,   187,   196,   109,   118,   119,
     120,   202,   196,   202,   124,   125,   126,   127,    79,   196,
     202,    82,   375,   376,   377,   378,   379,   380,   381,   382,
     383,    82,   385,   386,   387,   388,   389,   202,    82,   204,
     393,   394,   395,   396,   397,    79,   399,   376,    82,   378,
     379,   380,   340,   382,   383,    76,   385,   386,   387,    80,
     389,   192,   193,   416,   393,   394,   395,   396,   186,   187,
     203,    92,   173,   174,   175,   176,   196,   332,   198,   202,
     200,   204,     6,   203,   202,   205,   186,   187,   186,   187,
    1781,   192,   193,    82,   204,   838,   839,   186,   187,   186,
     187,   454,   202,   391,   202,    76,    76,   196,    79,    79,
     398,    82,    82,    84,   203,   202,   202,   196,   204,   198,
     375,   376,   377,   378,   379,   380,   205,   382,   383,    82,
     385,   386,   387,   388,   389,    84,   489,   490,   393,   394,
     395,   396,   397,    79,   399,   753,    82,   196,    84,     8,
     603,    79,   504,   505,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   227,   228,
     229,   203,   195,   232,   233,   234,   186,   187,   531,   532,
     533,   204,   103,   104,   186,   187,   186,   187,   109,   203,
     543,   542,   202,    82,   482,   483,   484,   485,   651,   652,
     202,    79,   202,   196,   557,   198,   186,   187,    79,   268,
     269,   564,   205,   502,   503,   197,    82,   568,   186,   187,
     202,   510,   202,   282,   283,   186,   187,  1543,   202,  1545,
     204,  1547,     8,   976,   202,   978,   202,   980,   204,   982,
       4,   202,   595,   186,   187,   188,   189,   190,   186,   187,
       6,     7,   195,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   202,   616,   617,   618,   619,   620,
     621,   622,    99,     6,     7,   626,   627,   628,   186,   187,
     202,   199,   204,   110,   202,   636,   637,   638,   543,   640,
     197,   118,   119,   120,   202,   202,   647,   124,   125,   126,
     127,   196,   196,   198,   197,   200,   197,   658,   199,   202,
     205,  1609,   203,   908,  1612,   668,     4,  1615,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     4,   186,   187,   196,   195,   198,   691,   199,
     693,   794,   202,   696,   205,   204,   699,   196,   701,   202,
    1093,     4,   705,   706,   196,    79,    76,  1673,    82,    79,
      84,   196,    82,    99,    84,   653,  1109,   696,   188,   189,
     190,   197,   701,   199,   110,   195,   729,   204,   202,   202,
     204,   204,   118,   119,   120,   838,   839,   196,   124,   125,
     126,   127,     6,   846,   847,     6,   202,   750,   204,   186,
     187,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   703,     6,  1715,  1734,   195,
    1736,   197,  1738,   202,   202,   204,   204,   198,  1744,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   696,   795,   196,   699,   195,   701,   202,   197,   204,
     199,   804,   198,   806,   203,   808,   196,   810,   197,   202,
     199,   204,   815,  1761,   203,   818,  1764,   756,   204,  1767,
     196,  1787,  1770,  1789,   763,  1791,     7,   930,   931,   197,
     769,   199,   197,   836,   199,   203,   202,   202,   204,   842,
    1334,  1335,     7,     8,   847,   197,  1239,   199,   198,   197,
     202,   199,   196,   196,   202,  1100,   196,    82,  1806,    84,
    1808,    99,  1810,   196,    82,   197,    84,   199,   847,   872,
     202,   202,   110,   204,   877,   878,   879,   880,   196,   196,
     118,   119,   120,   202,   196,   204,   124,   125,   126,   127,
     893,   197,   202,   199,   204,   202,   202,   204,   877,   196,
     879,   880,   202,   196,   204,   908,   196,   203,   911,   912,
     913,   914,    12,    13,   893,   916,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     203,     6,  1035,   936,   195,   202,   202,   204,   204,   202,
       6,   204,   847,   881,   196,   196,   947,   948,   203,   196,
     953,   954,   202,   956,   204,   958,   959,   936,   203,   962,
     963,   202,     4,   204,   967,   202,   204,   204,   202,   202,
     204,   204,   877,   196,   879,   880,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   196,    87,   893,   202,
    1093,   204,    92,    93,   196,    95,    96,    97,   202,   198,
     204,   101,     4,   908,     6,   202,   202,   204,   204,   202,
     949,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,  1271,   202,   196,   204,
     195,   936,   202,   205,   204,   135,   136,   137,   202,   202,
     204,   204,   196,   202,  1538,   204,   203,    99,  1051,  1052,
    1053,   202,   202,   204,   204,     6,   196,   196,   110,  1062,
     196,   196,  1001,  1002,  1003,   203,   118,   119,   120,  1070,
     203,   203,   124,   125,   126,   127,  1077,  1078,  1079,  1080,
    1081,   202,   202,   204,   204,   203,  1087,  1088,   202,   202,
     204,   204,   202,   196,   204,    99,   202,  1100,   204,   196,
      12,    13,   196,   202,   204,   204,   110,   202,   210,   204,
     196,     6,  1115,   215,   118,   119,   120,   219,     6,   203,
     124,   125,   126,   127,   226,   202,   202,   204,   204,   203,
     202,  1134,   204,  1501,   202,   198,   204,  1140,   202,  1242,
     204,   203,   202,  1146,   204,  1148,  1149,   198,   198,   198,
    1153,  1154,   204,  1156,     6,  1158,     6,  1160,   203,  1162,
    1163,  1164,   143,     6,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   205,    87,     6,  1180,     6,     6,
      92,    93,   203,    95,    96,    97,    99,     6,  1126,   101,
     198,     4,  1195,   200,   195,  1100,  1199,   110,  1201,     7,
     204,   204,     7,   203,   202,   118,   119,   120,   202,     6,
    1211,   124,   125,   126,   127,     6,     6,   197,     7,     7,
       6,  1222,     7,   135,   136,   137,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     203,     6,     4,     7,   195,     6,  1249,     6,     6,   140,
      54,    54,    99,    54,  1193,    54,   203,   199,   197,     6,
       6,  1364,  1507,   110,   197,   197,   202,   202,  1271,   197,
    1249,   118,   119,   120,  1277,   202,   202,   124,   125,   126,
     127,     4,     5,   202,  1287,    99,   197,  1290,   197,   199,
       4,   204,   204,     6,  1552,     4,   110,     7,     6,     6,
       6,     6,   143,     7,   118,   119,   120,     7,  1287,     7,
     124,   125,   126,   127,   416,  1253,     7,    40,    41,    42,
      43,    44,    45,  1326,  1327,  1263,    49,    50,    51,    52,
       7,   143,  1334,  1335,    57,    58,    59,   143,     7,    62,
       7,   203,     6,     4,  1249,     7,   197,   202,   197,   202,
      73,  1354,  1290,  1356,   202,  1358,   202,   204,   197,  1298,
     197,     6,   200,     7,   204,   199,  1271,     7,   204,     7,
    1373,   203,   203,     6,   203,     6,   200,  1380,   203,     6,
     203,  1384,  1287,    99,     6,  1388,  1387,   489,   490,     7,
     204,   198,  1330,     6,   110,     6,     6,  1336,   196,  1338,
     196,  1340,   118,   119,   120,  1408,     6,   184,   124,   125,
     126,   127,     7,     7,     7,  1354,  1674,     7,  1357,  1358,
     203,    84,     7,     7,     7,     6,  1429,     7,     7,   531,
     532,   533,     7,     7,     7,   158,   159,     7,     4,     4,
     203,  1379,     6,     6,   196,     7,   169,     6,   171,   172,
    1388,  1389,  1390,     7,     7,   557,     7,     6,   203,     6,
       6,    82,  1465,     7,     6,     6,   204,  1470,     4,   192,
     193,     4,     4,     4,    12,    13,     6,   200,     6,     6,
      99,     6,     6,   202,   202,   197,   197,     7,  1491,     6,
       6,   110,     6,   595,   197,  1498,   197,   196,  1501,   118,
     119,   120,     6,   200,  1507,   124,   125,   126,   127,   203,
     200,   203,     6,  1516,   203,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,  1532,
     203,    92,  1535,   195,     6,   203,  1538,     6,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,  1551,    87,
     203,     4,     6,  1556,    92,    93,     6,    95,    96,    97,
      12,    13,     6,   101,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     5,   203,
       6,     6,   195,   203,     7,   204,   203,   203,     6,   691,
     198,   693,     6,     6,   203,  1598,  1501,   135,   136,   137,
     203,   203,  1507,  1542,     4,  1544,   202,  1546,     6,     6,
     139,     6,     6,     4,  1617,  1554,     6,     4,  1557,   197,
       6,     6,     6,     6,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    88,    87,     6,     4,     6,     5,
      92,    93,     6,    95,    96,    97,     6,     6,   750,   101,
       6,   203,     6,   143,     6,   200,     6,     6,  1597,     6,
       6,     6,  1601,     6,     6,     6,   204,     6,   202,     6,
       6,     6,  1675,     6,  1677,     6,     5,     7,     6,     6,
     203,     6,     6,   135,   136,   137,     6,  1690,    80,   204,
     203,   203,   203,   795,   204,   203,     6,   203,     6,  1637,
       7,   203,   804,     6,   806,   138,   808,     6,   810,   204,
       6,  1650,   141,   815,     6,  1654,   818,     6,     6,     6,
     174,   175,   176,   177,   178,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     6,   191,  1677,     6,
     195,   195,     6,  1746,   203,     6,     6,     6,     6,     6,
       6,  1754,   204,   204,   203,   209,   210,   211,   212,     6,
     214,   215,   216,   217,   203,   219,   220,   221,     6,   203,
     872,   203,   226,    99,     6,  1754,     6,     6,  1781,   203,
       6,     6,     6,     6,     6,     6,     6,  1725,   204,     6,
     244,   203,   203,  1732,  1733,  1798,   203,  1800,     6,   253,
     254,   203,     6,     6,     6,     6,     6,   203,   262,   911,
     912,   913,   914,     6,     6,   203,     6,     6,     6,  1798,
       6,  1800,   203,   203,   203,     6,     6,  1830,     6,     6,
       6,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       6,   295,   296,   297,   195,     6,     6,     6,  1123,  1754,
    1640,  1830,   450,   307,   308,   309,  1521,   311,     3,  1522,
       3,   315,   316,   317,  1133,   967,   320,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   480,   336,   337,    -1,   195,  1534,  1267,    -1,    -1,
      -1,    -1,    -1,  1798,    -1,  1800,   350,   351,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,    -1,    -1,    -1,    -1,  1830,    -1,    -1,    -1,    -1,
     384,    -1,    -1,    -1,    -1,    -1,   390,    -1,   392,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   413,
      -1,    -1,   416,    -1,    -1,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
      -1,    -1,   436,   437,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
     454,    -1,   195,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,   465,    -1,    -1,    -1,    -1,   470,   471,    -1,    -1,
      -1,    -1,   476,   477,    -1,    -1,    -1,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     222,    -1,    -1,   507,   508,   509,   510,   511,   512,    -1,
      -1,    -1,   516,   517,   518,   519,   520,    -1,    -1,    99,
     524,    -1,   526,   527,   246,    -1,    -1,   531,   532,   533,
     110,    -1,   536,   537,   538,   539,   540,    -1,   118,   119,
     120,    -1,   546,    -1,   124,   125,   126,   127,   270,  1201,
      -1,    -1,   210,   557,     6,    -1,    -1,   215,    -1,   563,
     564,   219,   566,   567,    -1,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   587,    -1,   110,    -1,    -1,    -1,    -1,
     594,   595,    -1,   118,   119,   120,   600,    12,    13,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,   334,   335,    -1,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   204,   347,   118,   119,   120,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,   295,    -1,   297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    -1,  1326,  1327,    -1,    92,    93,   204,
      95,    96,    97,    -1,   688,    -1,   101,   691,    -1,   693,
     694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
      -1,   705,   706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,   719,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,   728,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,   750,     6,    -1,    -1,
      -1,    -1,    -1,   757,   758,    -1,    -1,    -1,   416,   763,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   776,    -1,    -1,   779,     6,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,   795,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,
     804,    -1,   806,    -1,   808,    -1,   810,    -1,    -1,    -1,
      -1,   815,    -1,    -1,   818,    -1,    -1,    -1,    -1,    -1,
     824,    -1,   826,   827,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   489,   490,    -1,    -1,    -1,    -1,     6,    -1,  1491,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,   860,    -1,    92,    93,
      -1,    95,    96,    97,   868,   869,   870,   101,   872,    -1,
      -1,    -1,    -1,   531,   532,   533,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1535,    -1,    -1,   890,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   898,    -1,    -1,   901,    -1,   557,
      -1,   135,   136,   137,  1556,    -1,   564,   911,   912,   913,
     914,    -1,    -1,    -1,   918,    -1,    12,    13,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,   595,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   668,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,   967,    -1,   195,    -1,    -1,    -1,    -1,
     204,    -1,    -1,   977,    -1,   979,    -1,   981,    -1,   983,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      96,    97,    12,    13,    -1,   101,    -1,   729,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,  1675,    -1,  1677,   195,    -1,    -1,    -1,
    1034,    -1,    -1,   691,  1038,   693,  1040,  1041,  1042,   135,
     136,   137,    -1,    -1,  1048,    -1,    -1,   705,   706,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1065,    -1,  1067,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,   750,    -1,  1746,    -1,    -1,  1101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,  1113,
    1114,    -1,    -1,    -1,   836,    -1,    -1,    -1,    -1,    -1,
     842,  1125,  1126,    -1,    -1,   135,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   795,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   804,    -1,   806,    -1,
     808,    -1,   810,    -1,    -1,    -1,   878,   815,    -1,    -1,
     818,    -1,    -1,    -1,    -1,    -1,  1170,  1171,  1172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1180,    -1,  1182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1193,
      -1,    -1,    -1,    -1,   204,    -1,    -1,  1201,    -1,    -1,
      -1,    -1,  1206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1227,  1228,  1229,    -1,    -1,    -1,    -1,
      -1,   953,   954,    -1,   956,    -1,   958,   959,    -1,    -1,
     962,   963,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   911,   912,   913,   914,    -1,    -1,    -1,
    1264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1278,    -1,    -1,    -1,    -1,  1283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1296,  1297,    -1,    -1,    -1,    -1,    -1,  1303,
    1304,    -1,    -1,    -1,  1308,    -1,    -1,    -1,    -1,   967,
      -1,    -1,  1316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1326,  1327,  1328,    -1,  1330,    -1,    -1,  1051,
    1052,  1053,    -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,
    1062,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
    1354,    -1,    -1,    -1,  1358,    -1,    -1,  1361,    -1,    -1,
      -1,    -1,  1366,  1367,  1368,  1369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1379,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1406,  1407,    -1,    -1,    -1,    -1,    -1,    -1,
    1414,    -1,  1134,    -1,    -1,    -1,    -1,    -1,  1140,    -1,
      -1,    -1,    -1,    -1,  1146,    -1,  1148,  1149,    -1,    -1,
      -1,  1153,  1154,     6,  1156,    -1,  1158,    -1,  1160,    -1,
    1162,  1163,  1164,    -1,    -1,    -1,  1450,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1180,    -1,
      -1,    -1,    -1,    -1,  1468,    -1,  1470,    -1,    -1,    -1,
      -1,    -1,    -1,  1195,    -1,    -1,    -1,  1199,    -1,    -1,
      -1,    -1,  1486,    -1,  1488,    -1,    -1,  1491,    -1,    -1,
      -1,    -1,    -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1512,    -1,
      -1,    -1,    -1,  1517,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,  1535,   195,    -1,    -1,    -1,    -1,    -1,  1542,    -1,
    1544,    -1,  1546,  1201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1556,    -1,    -1,  1277,  1560,  1561,  1562,  1563,
    1564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1290,    -1,
      -1,    -1,    -1,    -1,    -1,  1579,  1580,    -1,    -1,    -1,
    1584,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
    1594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1605,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,  1635,    -1,    -1,  1356,    -1,  1640,    -1,    -1,    -1,
      -1,    -1,    -1,  1647,    -1,    12,    13,    -1,    -1,    -1,
      -1,  1373,    -1,    -1,    -1,    -1,    -1,  1661,  1380,    -1,
    1664,    -1,  1384,  1667,    -1,    -1,  1388,  1671,  1326,  1327,
      -1,  1675,    -1,  1677,  1678,  1679,  1680,  1681,    -1,    -1,
      -1,    -1,    -1,    -1,  1688,    -1,  1408,  1691,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,    -1,    -1,
    1358,    -1,    -1,    -1,    -1,    -1,    -1,  1429,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    92,    93,  1731,    95,    96,
      97,    -1,    -1,    -1,   101,    -1,    99,    -1,    -1,    -1,
      -1,    -1,  1746,  1465,  1748,  1749,  1750,  1751,    -1,    -1,
      -1,    -1,    21,    22,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   135,   136,
     137,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1784,  1785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1794,  1795,  1796,  1797,  1516,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     6,
    1532,    -1,  1470,   195,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,  1551,
      -1,     6,   195,  1491,    -1,    -1,    -1,   204,    -1,   108,
    1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,  1598,  1535,    -1,   148,
     149,   150,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,   160,   161,    -1,    -1,  1617,    -1,   166,  1556,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    12,    13,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,  1690,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,  1675,   287,  1677,
     195,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,   304,    -1,    -1,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,   151,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,  1781,
      -1,    -1,   164,   165,   166,   167,   168,   169,    -1,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   186,   187,    -1,    -1,  1746,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
      -1,   203,    -1,   205,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
     204,    -1,    -1,    -1,    53,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,   101,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,     8,   164,   165,   166,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
       3,     4,   201,    -1,   203,   204,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,   204,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     8,    -1,    -1,
      -1,   195,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,     8,    -1,   171,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,    -1,    -1,   195,   191,    -1,
      -1,    -1,    -1,   196,   202,    -1,   204,    -1,   201,    -1,
      -1,   204,     3,     4,     5,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     8,
      -1,    -1,    -1,   195,    -1,    -1,   157,   158,   159,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,     3,     4,     5,
     201,    -1,   203,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   157,   158,   159,   160,   195,    -1,    -1,   164,   165,
     166,   167,   168,   169,   204,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     196,    -1,     3,     4,     5,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,     8,    40,
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
      -1,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   157,   158,   159,   160,
     195,    -1,    -1,   164,   165,   166,   167,   168,   169,   204,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,    -1,   203,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   157,   158,   159,   160,   195,    -1,    -1,   164,   165,
     166,   167,   168,   169,    -1,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     196,    -1,     3,     4,     5,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,     4,     5,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,   169,    -1,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,     3,     4,     5,
     201,    -1,   203,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,   169,    -1,   171,   172,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,   164,   165,
     166,   167,   168,    -1,    -1,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,    -1,    -1,   195,   191,   197,    -1,    -1,    -1,
     196,   202,     3,     4,     5,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,   158,   159,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,   169,    -1,   171,   172,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    82,    -1,    84,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   186,   187,    -1,    -1,   195,
     191,    -1,    -1,    -1,    -1,   196,   202,     3,     4,    -1,
     201,    -1,   203,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,   169,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    82,     5,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,   164,   165,
     166,   167,   168,    -1,    -1,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,    -1,
     196,   202,     3,     4,    -1,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
     158,   159,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,   169,    53,    -1,   172,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,     3,     4,    -1,
     201,    -1,   203,     9,    10,    11,    -1,    -1,    14,    15,
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
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,   164,   165,
     166,   167,   168,    -1,    -1,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,    -1,
     196,   202,     3,     4,    -1,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,   112,    -1,    -1,   115,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   186,   187,    -1,    -1,   195,
     191,    -1,    -1,    -1,    -1,   196,   202,     3,     4,    -1,
     201,    -1,   203,     9,    10,    11,    -1,    -1,    14,    15,
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
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,    -1,   164,   165,
     166,   167,   168,    -1,    -1,   171,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     186,   187,    -1,    -1,   195,   191,    -1,    -1,    -1,    -1,
     196,   202,     3,     4,    -1,   201,    -1,   203,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    64,    65,    66,    -1,     9,    10,    11,
      -1,    72,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   204,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   186,   187,    -1,    -1,   195,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   204,    -1,
     201,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,
      -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,   171,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   186,   187,    -1,    -1,   195,   191,
      -1,    -1,    -1,    -1,   196,   202,     3,     4,     5,   201,
      -1,   203,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    73,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   204,    -1,    -1,   164,   165,   166,
     167,   168,   169,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,    -1,    -1,    -1,   191,     3,     4,    -1,    -1,   196,
      -1,     9,    10,    11,   201,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,
     168,    -1,    -1,   171,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   186,   187,
      -1,    -1,   195,   191,     3,     4,    -1,    -1,   196,   202,
       9,    10,    11,   201,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,    -1,
      -1,    -1,   191,    -1,    54,    55,    56,   196,    -1,    -1,
      60,    61,   201,    63,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,     4,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    12,    13,   134,   135,   136,   137,    -1,    -1,
     140,    -1,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,    38,    39,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,    -1,    -1,
     140,    -1,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,
      -1,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,    -1,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   207,   208,     6,     0,     4,    12,    13,    38,
      39,    54,    55,    56,    60,    61,    63,    67,    68,    70,
      71,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   110,   111,   112,   113,   114,   115,
     116,   117,   121,   122,   123,   129,   134,   135,   136,   137,
     140,   142,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   161,   162,   163,   170,   171,
     209,   211,   212,   232,   249,   250,   253,   254,   255,   256,
     257,   258,   259,   260,   281,   282,   283,   284,   302,   303,
       3,     4,     5,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    57,    58,    59,    62,    64,    65,    66,
      72,    73,   151,   157,   158,   159,   160,   164,   165,   166,
     167,   168,   169,   172,   186,   187,   191,   196,   198,   200,
     201,   203,   205,   230,   285,   286,   298,   299,   302,   303,
      13,    82,   196,   196,     6,   203,     6,     6,     6,     6,
     196,     6,     6,   198,   198,   196,   198,   230,   230,   196,
     203,   196,   196,     4,   196,   203,   196,   196,     4,   203,
     196,   196,    86,    82,    82,     6,   203,    76,    79,    82,
      82,    82,    79,    82,    84,    84,    76,    79,    82,    84,
      79,    82,    84,    79,    82,   196,    79,   140,   155,   156,
     203,   186,   187,   196,   203,   288,   289,   288,   203,    76,
      79,    82,   203,   288,     4,    76,    80,    92,    82,    84,
      82,    79,     4,   151,   203,   302,   303,     4,     6,    76,
      79,    82,    79,    82,     4,     4,     4,     4,     5,    37,
      76,    79,    82,    84,    96,   187,   196,   203,   250,   260,
     285,   291,   292,   293,   302,   303,     4,   196,   196,   196,
       4,   203,   295,   303,     4,   196,   196,   196,     6,     6,
     198,     4,   299,   303,     4,   299,     5,   203,     5,   203,
       4,   285,   198,     6,   196,   203,   196,   198,   205,   230,
       7,   173,   174,   175,   176,   192,   193,   228,   229,     4,
     196,   198,   200,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   196,   196,
     196,   196,   196,   196,   230,   230,   230,   230,   196,   230,
     230,   230,     7,   196,   196,   196,   230,   196,   196,   198,
     285,   285,   285,   285,   285,     4,   140,   141,   303,     4,
     250,   251,   252,   203,   197,   199,   203,   231,     6,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   195,   203,     6,   196,   198,   229,     6,
     285,     4,   298,   299,   303,   298,   285,   298,   301,   234,
     237,   299,   303,   285,   187,   285,   293,   294,   285,   285,
     196,   285,   294,   285,   285,   196,   294,   285,   285,   291,
     196,   203,   294,   292,   292,   292,   196,   196,   292,   292,
     292,   196,   196,   196,   196,   196,   196,   196,   196,   203,
     203,   285,     4,   291,   295,   203,   203,   288,   288,   288,
     285,   285,   186,   187,   203,   203,   288,   203,   203,   203,
     186,   187,   196,   252,   288,   203,   196,   203,   196,   196,
     196,   292,   292,   291,   196,     4,   198,   198,   252,     6,
       6,   203,   203,   203,   292,   292,   198,   198,   198,   196,
     198,   200,   230,   198,     5,   143,   203,     5,   143,     5,
     143,     5,   143,    76,    79,    82,    84,   203,   285,   293,
     285,   204,   294,     8,   188,     6,   196,   198,   230,     6,
     285,   285,   285,   200,   285,   203,   143,   285,   285,   285,
     285,     6,     6,     6,   252,     6,   252,   198,   203,   298,
     291,   291,   285,   285,   203,   203,   231,   299,   291,     6,
     198,   285,   285,     4,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   301,   298,   301,   298,
     298,   298,   291,   298,   298,   285,   298,   298,   298,   301,
     298,   285,   299,   285,   298,   298,   298,   298,   303,   299,
     303,   197,   199,     7,   228,   229,   200,     7,   230,   204,
      76,    79,    82,    84,   249,   285,   294,     7,   228,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   213,   285,   285,     6,   198,   200,
     197,   202,   197,   202,   202,   197,   202,   199,   202,   233,
     199,   233,   202,   202,   197,   188,   202,   204,   197,   197,
     285,   197,   204,   197,   197,   285,   204,   197,   197,     7,
     285,   285,   204,     6,     6,     6,   285,   285,     7,     7,
     278,   278,   285,   243,   285,   299,   244,   285,   299,   245,
     285,   299,   246,   285,   299,   285,   285,   285,   294,   294,
     203,   197,     6,   203,   252,   252,   202,   202,   202,   288,
     288,   251,   251,   202,   285,   285,   285,   285,   264,   202,
     252,   285,   285,   285,   285,   285,     7,   279,     6,     7,
     285,     6,   285,   285,   204,   294,   294,   294,     6,     6,
     285,   285,   285,   285,     4,   203,   231,   303,    54,   285,
      54,    54,    54,     5,   203,     5,   203,     5,   203,     5,
     203,   294,   197,   204,   285,   203,   285,   293,   203,   231,
     197,   197,   197,   140,   202,   252,   203,     8,   197,   197,
     199,   204,   204,   252,   199,   197,   202,   204,   197,   199,
     285,   294,   228,     6,     6,   285,   197,   199,   229,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     202,   231,   231,   231,   231,   231,   231,   231,   202,   202,
     202,   231,   202,   231,   231,   197,   197,   202,   202,   202,
     202,   202,   231,   231,   231,   197,   231,   287,   300,     6,
     202,   197,   197,   202,   231,   197,   197,   199,   228,   229,
     200,   228,   229,   299,   285,     6,     4,     4,   203,   296,
     231,   203,   203,   203,   203,   204,   204,   291,     8,     4,
     130,   131,   132,   133,   204,   216,   220,   223,   225,   226,
     197,   199,   285,     4,     6,   184,   210,   294,     6,   294,
     285,     6,   298,     6,   303,     6,   298,   285,   299,     7,
     285,   293,   143,     7,     7,   197,     7,   143,     7,     7,
     197,   143,     7,     7,   285,   197,   204,   203,   197,   197,
     285,   291,     4,   277,     6,   197,   197,   202,   197,   202,
     197,   202,   197,   202,   197,   197,   197,   204,   204,   294,
     200,   252,   204,   204,   288,   285,   285,   204,   204,   285,
     288,   202,   202,   202,    99,   110,   118,   119,   120,   124,
     125,   126,   127,   274,   275,   288,   204,   261,   197,   204,
     197,   197,   197,   285,     6,   285,   197,   199,   199,   204,
     204,   204,   199,   199,   202,   199,   294,   199,   203,   204,
     203,   203,   203,   294,   294,   294,   294,   204,     8,   294,
     294,     7,     7,     7,   200,   285,   204,   285,   285,     7,
     200,   204,   203,   291,     6,   228,   229,   228,   229,   204,
     204,   291,   199,   229,   200,   229,   298,   285,   285,   285,
     285,   294,   298,   291,   298,   298,   299,   239,   241,   285,
     298,   285,     6,     4,   140,   141,   285,     6,     6,     6,
       7,   198,   295,   297,     6,   294,   294,   294,   294,   231,
       6,   285,   217,   196,   196,   203,   227,     6,   229,   229,
     199,   184,   298,   197,   197,   202,     7,   231,   231,   288,
      82,    84,   291,   291,     7,   291,    82,    84,   291,   291,
       7,    84,   291,   291,     6,     7,     7,   294,     7,     7,
      99,   276,     6,     7,   228,   285,   228,   285,   228,   285,
     228,   285,     7,     7,     7,     7,     7,   204,     4,   204,
     202,   202,   202,   204,   204,   288,   288,   288,     4,     6,
     203,     6,   196,     6,   128,     6,   128,     6,   128,     6,
     128,   204,   275,   202,   274,     7,     6,     7,     7,     7,
       6,   203,     6,     6,     6,    82,     7,     6,     6,   285,
     200,   204,   285,   285,   285,   285,   204,   204,   204,   204,
     285,   204,   204,   291,   291,   291,     4,   202,     8,     8,
     197,     4,     4,   291,   204,   285,     6,   285,     6,   231,
       6,     6,     4,     6,   231,   231,   231,   231,   231,   202,
     197,   197,   197,   202,   202,   231,   240,   202,   231,   242,
     197,   197,     6,     7,   228,   229,   200,     7,     6,   295,
     285,   202,   204,   204,   204,   204,   204,   228,   196,   285,
     285,   290,   291,   203,   200,     6,     6,   210,     6,   285,
     203,   285,   299,     6,     6,     6,   203,   203,    92,   248,
     248,   291,     6,   203,   203,     6,     6,   291,   203,     6,
       6,     5,   291,   204,   291,   291,     4,     6,   291,   291,
     291,   291,   291,   291,   291,   291,   203,   203,     7,     6,
       7,   285,   285,   285,   203,   203,   202,   204,   202,   204,
     202,   204,   198,   285,   291,   285,     6,     6,     6,     6,
     285,   288,   204,     5,   203,   291,   203,   203,   203,   291,
     294,   203,   285,   199,     4,   231,   202,   202,   202,   202,
     231,     6,     6,   139,   285,   285,   285,     6,     6,     7,
     202,     6,     6,     6,   228,   229,   298,   299,     4,     4,
     154,   299,   285,     6,     4,   296,     6,   199,   295,     6,
       6,     6,     6,   291,   214,   285,   202,   202,   202,   204,
     215,   285,     4,   298,   202,   291,   299,   285,   285,   288,
       6,     6,     6,   285,   285,     6,   285,     5,     6,   203,
       6,   143,   247,   285,     6,     6,     6,     6,     6,     6,
       4,     6,     6,   294,   294,   285,   285,   299,   204,   197,
     202,   204,   251,   251,   288,     6,   265,   288,     6,   266,
     288,     6,   267,   285,   204,   202,   197,   204,   202,     6,
     187,   288,     6,   290,   288,   288,     6,   204,   285,     6,
       6,   285,   285,   285,   285,   291,   202,   204,     8,   204,
     197,   203,   285,   299,   291,   291,   197,   231,   203,   291,
     299,   203,   285,   299,   299,     6,     6,     7,     6,   200,
       6,   197,   202,   285,   285,   291,   203,   202,   204,     6,
     285,   235,   236,   204,   204,   204,   204,   204,     5,   290,
      80,     6,   203,   204,   204,   203,     6,     6,   203,   285,
     204,   204,   202,   203,   202,   203,   202,   203,   199,     6,
     291,     7,   203,   285,   202,   204,   202,   202,     6,   204,
     202,   202,   202,   202,   138,   285,   285,   294,     6,     6,
     204,     6,   238,   285,   301,   295,   141,   218,   285,   202,
     202,   290,   285,     6,   202,   239,   241,     6,     6,     6,
       6,     6,     6,   204,   203,   290,   103,   104,   109,   280,
     103,   104,   280,   294,   251,   202,   204,   285,   288,   274,
     285,   288,   274,   285,   288,   274,     6,   202,   204,   291,
     252,   204,   288,     6,   294,   288,   285,   285,   285,   285,
     285,   204,   204,   204,     6,   202,   204,     7,   204,     6,
     203,   285,   285,   204,   285,   204,   204,   203,   285,   204,
     203,   288,   291,     6,   203,   288,     6,   204,   204,   285,
     204,   202,   204,   204,   202,   204,   204,   202,   204,   291,
       6,    99,   204,   262,   203,   202,   204,   202,   202,   202,
     202,   202,     6,     6,   285,   299,   215,   197,   202,     6,
     203,   202,   285,   204,     6,   288,     6,   288,     6,     6,
     204,     6,   268,   285,     6,     6,   269,   285,     6,     6,
     270,   285,     6,   204,   285,   274,   252,   294,     6,   288,
     294,   285,   285,   285,   285,     7,   204,   221,   285,   290,
     285,   202,   202,   202,   203,   204,   203,   204,   203,   204,
       6,     6,   204,   204,   263,   204,   202,   204,   202,   202,
     202,   202,   299,     6,   203,   197,   204,   204,   285,   288,
     288,   274,     6,   271,   274,     6,   272,   274,     6,   273,
     274,     6,   294,     6,   285,   285,   285,   285,   219,   298,
     224,   203,     6,   204,   202,   202,   204,   203,   204,   203,
     204,   203,   204,   204,   202,   202,   202,   202,   202,   204,
     203,   290,     6,   285,   285,     6,   274,     6,   274,     6,
     274,     6,   285,   285,   285,   285,   298,     6,   222,   298,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     202,   204,     6,     6,     6,     6,     6,     6,   298,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   210,   211,   211,   211,   211,   211,   211,
     212,   212,   212,   212,   213,   213,   213,   213,   213,   213,
     214,   214,   215,   215,   217,   218,   216,   219,   219,   221,
     220,   222,   222,   224,   223,   225,   225,   227,   226,   228,
     228,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   234,
     234,   234,   235,   234,   234,   236,   234,   237,   237,   238,
     238,   239,   239,   240,   240,   240,   241,   241,   242,   242,
     242,   242,   243,   243,   243,   244,   244,   244,   245,   245,
     245,   246,   246,   246,   247,   247,   248,   248,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   250,   250,   250,
     250,   250,   250,   250,   250,   251,   251,   252,   252,   252,
     252,   252,   252,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   254,   254,   254,   254,   255,   255,   256,
     257,   257,   257,   257,   257,   257,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   260,
     260,   260,   261,   260,   262,   260,   263,   260,   264,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   265,
     260,   266,   260,   267,   260,   268,   260,   269,   260,   270,
     260,   271,   260,   272,   260,   273,   260,   274,   274,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     282,   282,   282,   283,   283,   283,   284,   284,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   288,   288,
     288,   288,   288,   289,   289,   289,   289,   290,   290,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   294,   294,   295,
     295,   295,   295,   296,   296,   297,   297,   298,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   299,   301,   301,   302,   302,   303,   303,
     303
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
       1,     1,     1,     0,     6,     4,     1,     4,     4,     4,
       4,     4,     4,     4,     2,     5,     5,     5,     5,     3,
       6,     4,     7,     6,     6,     6,     6,     4,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     2,     2,     2,     3,     3,     3,     3,
       5,     5,     5,     5,    16,    16,    16,    16,     1,     1,
       3,     3,     4,     6,     6,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     3,
       6,     1,     4,     1,     1,     1,     4,     6,     4,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     4,     6,
       4,     1,     0,     6,     1,     3,     5,     5,     1,     1,
       4
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
#line 4354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 239 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4484 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4502 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4519 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4536 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4563 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4581 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4598 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4615 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 375 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 389 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4668 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4776 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 517 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 526 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 533 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4822 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 552 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 561 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 568 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4867 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 586 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4889 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4909 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 634 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 640 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 655 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 672 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 677 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5031 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5095 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5128 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 801 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 806 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5179 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 811 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 816 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 821 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 828 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5219 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 855 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 860 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 865 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 870 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 879 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 885 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5304 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5326 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5348 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5361 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 951 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 956 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5392 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5416 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5440 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5455 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5467 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5493 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5520 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5550 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5572 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5588 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5604 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5617 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5636 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5656 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1193 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5675 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1209 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1217 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1223 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5718 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5733 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5751 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1277 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5774 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1294 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5797 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1330 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1342 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1348 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1378 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1384 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1392 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5930 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5944 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1412 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5960 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5987 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6023 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6047 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6069 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6094 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6116 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6150 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6184 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6206 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6228 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6258 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6280 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6302 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6338 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6360 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1808 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1814 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1820 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6434 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6463 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6492 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6513 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6536 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6573 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6609 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6631 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6652 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6672 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2071 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2076 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2081 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2086 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2091 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6753 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6780 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2119 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6790 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2135 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2136 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2145 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6830 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6857 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6884 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6911 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6938 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6963 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6993 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7017 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7042 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7066 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7182 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7205 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7247 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7354 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2643 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7377 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7396 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7428 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7444 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7457 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7470 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2746 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2752 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7503 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7516 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7529 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7542 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7555 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
      else if(!strcmp((yyvsp[-2].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[-1].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 7618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2858 "Gmsh.y" /* yacc.c:1646  */
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
#line 7640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2876 "Gmsh.y" /* yacc.c:1646  */
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
#line 7661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2893 "Gmsh.y" /* yacc.c:1646  */
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
#line 7680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2908 "Gmsh.y" /* yacc.c:1646  */
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
#line 7710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2934 "Gmsh.y" /* yacc.c:1646  */
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
#line 7726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2946 "Gmsh.y" /* yacc.c:1646  */
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
#line 7754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2970 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2974 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2979 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2986 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2991 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2997 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7810 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3002 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3008 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 7832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3016 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3020 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7848 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3024 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3030 "Gmsh.y" /* yacc.c:1646  */
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
#line 7915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3089 "Gmsh.y" /* yacc.c:1646  */
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
#line 7936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3106 "Gmsh.y" /* yacc.c:1646  */
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
#line 7957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3123 "Gmsh.y" /* yacc.c:1646  */
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
#line 7983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3145 "Gmsh.y" /* yacc.c:1646  */
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
#line 8009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3167 "Gmsh.y" /* yacc.c:1646  */
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
#line 8048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3202 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3210 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3218 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3231 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8104 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3238 "Gmsh.y" /* yacc.c:1646  */
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
#line 8128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3258 "Gmsh.y" /* yacc.c:1646  */
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
#line 8158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3284 "Gmsh.y" /* yacc.c:1646  */
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
#line 8174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3296 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3308 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3332 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8230 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3346 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8252 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3352 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3374 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3395 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3402 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3409 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3416 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3423 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3430 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3437 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3444 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3451 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8416 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3457 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8427 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3464 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3470 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3477 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3483 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3490 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3496 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8490 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3503 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8500 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3516 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3522 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3529 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8542 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3535 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3542 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3548 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3555 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3561 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3572 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3575 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3581 "Gmsh.y" /* yacc.c:1646  */
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
#line 8625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3593 "Gmsh.y" /* yacc.c:1646  */
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
#line 8649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3613 "Gmsh.y" /* yacc.c:1646  */
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
#line 8676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3637 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3641 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3645 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3653 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3659 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3665 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3669 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8744 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3673 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3681 "Gmsh.y" /* yacc.c:1646  */
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
#line 8783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3700 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3712 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3716 "Gmsh.y" /* yacc.c:1646  */
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
#line 8820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3731 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3735 "Gmsh.y" /* yacc.c:1646  */
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
#line 8846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3751 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3755 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3760 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3764 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8878 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3770 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3774 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3781 "Gmsh.y" /* yacc.c:1646  */
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
#line 8954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3837 "Gmsh.y" /* yacc.c:1646  */
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
#line 9028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3907 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9037 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3912 "Gmsh.y" /* yacc.c:1646  */
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
#line 9108 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3979 "Gmsh.y" /* yacc.c:1646  */
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
#line 9148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 4015 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4023 "Gmsh.y" /* yacc.c:1646  */
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
#line 9207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4066 "Gmsh.y" /* yacc.c:1646  */
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
#line 9250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4105 "Gmsh.y" /* yacc.c:1646  */
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
#line 9274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4126 "Gmsh.y" /* yacc.c:1646  */
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
#line 9309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4158 "Gmsh.y" /* yacc.c:1646  */
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
#line 9339 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4185 "Gmsh.y" /* yacc.c:1646  */
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
#line 9368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4211 "Gmsh.y" /* yacc.c:1646  */
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
#line 9397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4237 "Gmsh.y" /* yacc.c:1646  */
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
#line 9426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4263 "Gmsh.y" /* yacc.c:1646  */
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
#line 9455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4289 "Gmsh.y" /* yacc.c:1646  */
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
#line 9480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4310 "Gmsh.y" /* yacc.c:1646  */
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
#line 9512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4338 "Gmsh.y" /* yacc.c:1646  */
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
#line 9544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4366 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4370 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4374 "Gmsh.y" /* yacc.c:1646  */
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
#line 9592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4402 "Gmsh.y" /* yacc.c:1646  */
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
#line 9635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4441 "Gmsh.y" /* yacc.c:1646  */
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
#line 9678 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4480 "Gmsh.y" /* yacc.c:1646  */
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
#line 9703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4501 "Gmsh.y" /* yacc.c:1646  */
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
#line 9728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4522 "Gmsh.y" /* yacc.c:1646  */
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
#line 9753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4549 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4553 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4563 "Gmsh.y" /* yacc.c:1646  */
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
#line 9809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4597 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4598 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4599 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
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
#line 9853 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
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
#line 9875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4640 "Gmsh.y" /* yacc.c:1646  */
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
#line 9902 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9908 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9914 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9920 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4670 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4671 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4672 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9938 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4673 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9944 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4676 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9967 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4683 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4684 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9979 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4685 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4686 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4687 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4688 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4689 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4690 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10015 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4691 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4692 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4693 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4694 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4695 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4696 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4697 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4698 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4699 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4700 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4701 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4702 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10087 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4703 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4704 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10099 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4705 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4706 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10111 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4707 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4708 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4709 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4710 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4711 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4712 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4713 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10153 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4714 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4723 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10165 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4724 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4725 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4726 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4727 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4728 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10195 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4729 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10201 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4730 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4731 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10213 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4732 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4733 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10225 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4740 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4746 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4751 "Gmsh.y" /* yacc.c:1646  */
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
#line 10271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4768 "Gmsh.y" /* yacc.c:1646  */
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
#line 10293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4786 "Gmsh.y" /* yacc.c:1646  */
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
#line 10315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4804 "Gmsh.y" /* yacc.c:1646  */
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
#line 10337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4822 "Gmsh.y" /* yacc.c:1646  */
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
#line 10359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4840 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4845 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4851 "Gmsh.y" /* yacc.c:1646  */
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
#line 10394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4863 "Gmsh.y" /* yacc.c:1646  */
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
#line 10415 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4880 "Gmsh.y" /* yacc.c:1646  */
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
#line 10437 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4898 "Gmsh.y" /* yacc.c:1646  */
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
#line 10459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4916 "Gmsh.y" /* yacc.c:1646  */
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
#line 10481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4934 "Gmsh.y" /* yacc.c:1646  */
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
#line 10503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4955 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4960 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4965 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4975 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
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
#line 10573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5001 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5010 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5015 "Gmsh.y" /* yacc.c:1646  */
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
#line 10623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5042 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5050 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5054 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5058 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5065 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5073 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5077 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5084 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5089 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5096 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5105 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5110 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5114 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10758 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5122 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5133 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5137 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5149 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5157 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5165 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5172 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5182 "Gmsh.y" /* yacc.c:1646  */
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
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5211 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10881 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5215 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5219 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5223 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5227 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5231 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5235 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5239 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5243 "Gmsh.y" /* yacc.c:1646  */
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
#line 10970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5272 "Gmsh.y" /* yacc.c:1646  */
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
#line 11003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5301 "Gmsh.y" /* yacc.c:1646  */
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
#line 11036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5330 "Gmsh.y" /* yacc.c:1646  */
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
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5360 "Gmsh.y" /* yacc.c:1646  */
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
#line 11085 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5373 "Gmsh.y" /* yacc.c:1646  */
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
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5386 "Gmsh.y" /* yacc.c:1646  */
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
#line 11117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5399 "Gmsh.y" /* yacc.c:1646  */
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
#line 11133 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5411 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5421 "Gmsh.y" /* yacc.c:1646  */
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
#line 5431 "Gmsh.y" /* yacc.c:1646  */
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
#line 11177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
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
#line 11193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5456 "Gmsh.y" /* yacc.c:1646  */
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
#line 11209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
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
#line 11231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5486 "Gmsh.y" /* yacc.c:1646  */
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
#line 11253 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5507 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5512 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5516 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5520 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5532 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5536 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5548 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      if(gmsh_yystringsymbols.count((yyvsp[0].c)))
        (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[0].c)].c_str(), &flag);
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5558 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5572 "Gmsh.y" /* yacc.c:1646  */
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
#line 11356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5587 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5592 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5599 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11381 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5603 "Gmsh.y" /* yacc.c:1646  */
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
#line 11398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5616 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5624 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5635 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5639 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11438 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5643 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5651 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5657 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5663 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5671 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5679 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5686 "Gmsh.y" /* yacc.c:1646  */
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
#line 11524 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5701 "Gmsh.y" /* yacc.c:1646  */
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
#line 11542 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5715 "Gmsh.y" /* yacc.c:1646  */
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
#line 11560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5729 "Gmsh.y" /* yacc.c:1646  */
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
#line 11576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5741 "Gmsh.y" /* yacc.c:1646  */
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
#line 11596 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5757 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5766 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5775 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11636 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5785 "Gmsh.y" /* yacc.c:1646  */
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
#line 11651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5796 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5800 "Gmsh.y" /* yacc.c:1646  */
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
#line 11682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5819 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5826 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5832 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5834 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5845 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5850 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5856 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5865 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5878 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5881 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5885 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11782 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5888 "Gmsh.y" /* yacc.c:1906  */


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
