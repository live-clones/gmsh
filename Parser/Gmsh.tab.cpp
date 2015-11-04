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
#define YYLAST   10105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  520
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1838

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
    5535,  5547,  5554,  5564,  5568,  5583,  5588,  5595,  5599,  5612,
    5620,  5631,  5635,  5639,  5647,  5653,  5659,  5667,  5675,  5682,
    5697,  5711,  5725,  5737,  5753,  5762,  5771,  5781,  5792,  5796,
    5815,  5822,  5829,  5828,  5841,  5846,  5852,  5861,  5874,  5877,
    5881
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

#define YYPACT_NINF -1353

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1353)))

#define YYTABLE_NINF -491

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6918,    15,    44,  7038, -1353, -1353,  3408,    80,   -29,  -139,
    -130,    53,   144,   241,   275,   298,   -54,   374,   382,    70,
     210,  -119,  -119,  -155,   267,   282,    38,   288,   296,    18,
     299,   312,   448,   460,   483,   607,   366,   456,   540,   541,
     514,   546,   341,   609,    82,   437,   576,   -65,   459,  -100,
    -100,   462,   -12,   274,   116,   614,   605,    14,    57,   630,
     631,   170,   716,   723,   757,  4972,   771,   580,   587,   596,
      29,    65, -1353,   600,   613, -1353, -1353,   804,   807,   627,
   -1353,  4852,  5248,    34,    35, -1353, -1353, -1353,  6779,   633,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353,    52, -1353,   -25,   132,
   -1353,    22, -1353, -1353, -1353, -1353, -1353,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,   641,   644,   652,   655,   656,   666,  -119,  -119,
    -119,  -119,   670, -1353,  -119, -1353, -1353, -1353, -1353, -1353,
    -119,  -119,   849,   673,   681,   682,  -119,   687,   698, -1353,
   -1353, -1353, -1353,   707,  6779,  6779,  6779,  6779,  6779,   136,
      10,   458,   695,  -168,   827, -1353,   703,   905,   270,   -34,
     934,  6779,  5053,  5053, -1353,  6779, -1353, -1353, -1353, -1353,
    5053, -1353, -1353, -1353, -1353, -1353, -1353,  3489,    10,  6779,
    6590,  6779,  6779,   720,  6779,  6590,  6779,  6779,   737,  6590,
    6779,  6779,  5362,   740,   709, -1353,  6590,  4972,  4972,  4972,
     748,   751,  4972,  4972,  4972,   776,   780,   789,   792,   803,
     836,   847,   854,   754,  2149,   957,  5362,    29,   772,   853,
    -100,  -100,  -100,  6779,  6779,   131, -1353,   257,  -100,   871,
     877,   899,  6337,   262,    90,   898,   907,   929,  4972,  4972,
    5362,   941,     1,   859, -1353,   902,  1134,  1141, -1353,   971,
     974,   975,  4972,  4972,   964,   981,   984,   454, -1353,   988,
       8,    20,    25,    40,   510,  5557,  6779,  3922, -1353, -1353,
    2980, -1353,  1182, -1353,   383,    -6,  1184,  6779,  6779,  6779,
     993,  6779,   991,  1053,  6779,  6779,  6779, -1353, -1353,  6779,
     994,  1192,  1194, -1353, -1353,  1195, -1353,  1196, -1353,   155,
    7649,  5053, -1353,  5362,  5362,  6779,  6779,  1000,   225,  3489,
   -1353, -1353, -1353, -1353, -1353, -1353,  5362,  1198,  1009,  6779,
    6779,  1204,  6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,
    6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,
    6779,  6779,  6779,  6779,  5053,  5053,  5053,  5053,  5053,  5053,
    5362,  5053,  5053,  6779,  5053,  5053,  5053,  5053,  5053,  6779,
    3489,  6779,  5053,  5053,  5053,  5053,    10,  3489,    10,  1016,
    1016,  1016,  9112,  8767,   165,  1012,  1206,  -119,  1011, -1353,
    1013,  3721,  6779, -1353, -1353,  6590,   138, -1353,  6779,  6779,
    6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,  6779,
    6779,  6779,  6779, -1353, -1353,  6779,  6779, -1353, -1353,  1290,
     453,   -68, -1353, -1353,   357,  5162, -1353,   380,   160,   265,
    1020,  1024,  9133,  6590,  3861, -1353,   159,  9154,  9175,  6779,
    9196,   249,  9217,  9238,  6779,   427,  9259,  9280,  1208,  6779,
    6779,   549,  1221,  1222,  1226,  6779,  6779,  1227,  1234,  1234,
    6779,  6401,  6401,  6401,  6401,  6779,  6779,  6779,  6590,  6590,
    7676,  1045,  1237,  1030, -1353, -1353,   -20, -1353, -1353,  5357,
    5552,  -100,  -100,   458,   458,     6,  6779,  6779,  6779,  6337,
    6337,  6779,  3721,   140, -1353,  6779,  6779,  6779,  6779,  6779,
    1239,  1238,  1244,  6779,  1246,  6779,  6779,   842, -1353, -1353,
    6590,  6590,  6590,  1250,  1251,  6779,  6779,  6779,  6779,  6779,
    1254,   297,    10, -1353,  1207,  6779, -1353,  1209, -1353,  1210,
   -1353,  1211,    41,    42,    50,    51,  6590,  1016, -1353,  9301,
   -1353,   550,  6779,  5752, -1353,  6779,  6779,   602, -1353,  9322,
    9343,  9364,  1122,  5747, -1353,  1063,  3880,  9385,  9406,  8790,
   -1353, -1353, -1353,  1088, -1353,  1318,  6779, -1353,  1068,  1071,
     570,  9427,  8813,  6779,  6590,   138,  1264,  1265, -1353,  6779,
    9448,  8836,   117,  8744,  8744,  8744,  8744,  8744,  8744,  8744,
    8744,  8744,  8744,  8744,  5942,  8744,  8744,  8744,  8744,  8744,
    8744,  8744,  6137,  6585,  7730,   637,   647,   637,  1075,  1077,
    1073,  1074,  1076,  1078,  7756,   620,   620,   620,   442,   620,
    9910, -1353,  1383,  1079,  1080,   484,   620,  1082,  1085,  1086,
     172,   123,  3489,  6779,  1278,  1283,    30,   620, -1353,   153,
      39,    33,   201, -1353,  4288,   661, -1353,  5362,  4066,  2215,
    1858,   808,   808,   317,   317,   317,   317,   640,   640,  1016,
    1016,  1016,  1016,    24,  9469,  8859, -1353,  6779,  1284,    11,
    6590,  1285,  6590,  6779,  1287,  5053,  1288, -1353,    10,  1292,
    5053,  6779,  3489,  1293,  6590,  6590,  1156,  1294,  1295,  9490,
    1298,  1163,  1301,  1302,  9511,  1167,  1304,  1305,  6779,  9532,
    4483,  1110, -1353, -1353, -1353,  9553,  9574,  6779,  5362,  1312,
    1311,  9595,  1121,  9910,  1117,  1123,  9910,  1119,  1128,  9910,
    1124,  1130,  9910,  1126,  9616,  9637,  9658,   668,   680,  6590,
    1129, -1353, -1353,  1422,  1524,  -100,  6779,  6779, -1353, -1353,
    1132,  1138,  6337,  7782,  7808,  7834,  4967,   431,  -100,  1611,
    9679,  4548,  9700,  9721,  9742,  6779,  1326, -1353,  6779,  9763,
   -1353,  8882,  8905, -1353,   699,   700,   713, -1353, -1353,  8928,
    8951,  7860,  8974,    -6,  6590, -1353,  1135,  1142,  5886,  1143,
    1145,  1146, -1353,  6590, -1353,  6590, -1353,  6590, -1353,  6590,
     726, -1353, -1353,  4086,  6590,  1016, -1353,  6590, -1353,  1331,
    1337,  1348,  1133,  6779,  1793,  6779,  6779, -1353, -1353,     9,
   -1353, -1353,  2415, -1353,  1157,  5362,  1353,   172,   172,  6081,
     749,  5362, -1353, -1353,  8997,    -6,  1047, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  6779,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353,  6779,  6779,  6779,
   -1353,  6590, -1353, -1353, -1353, -1353,  5053,  5362,  5053,  5053,
    3489, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  6779,
   -1353, -1353,  5053, -1353, -1353, -1353, -1353,  6779,  1355,   142,
    6779,  1356,  1357,  1402, -1353,  1358,  1166,    29,  1364, -1353,
    6590,  6590,  6590,  6590, -1353,   620,  1365,  6779, -1353,  1181,
    1183,  1175, -1353,  1376, -1353, -1353, -1353, -1353, -1353,    -6,
      -6,  9020, -1353, -1353,  1199,  5053,   508, -1353,   527,  7886,
   -1353, -1353, -1353,  1379, -1353, -1353,  8744,   620,  -100,  3861,
   -1353,   251,  5362,  5362,  1380,  5362,   878,  5362,  5362,  1381,
    1306,  5362,  5362,  1651,  1385,  1386,  6590,  1399,  1400,  4685,
   -1353, -1353,  1403, -1353,  1405,   138,  6779,   138,  6779,   138,
    6779,   138,  6779,  1409,  1411,  1413,  1414,  1415,   762,  1419,
    2608, -1353, -1353,   259,  7912,  7938, -1353, -1353,  6303,   -55,
    -100,  -100,  -100,  1420,  1421,  1223,  1423,  1232,    32,    66,
      68,    74,   522, -1353,   350, -1353,   431,  1424,  1426,  1429,
    1430,  1431,  9910, -1353,  1938,  1230,  1433,  1435,  1436,  1361,
    6779,  1438,  1439,  6779,   129,   765, -1353,  6779, -1353,  6779,
    6779,  6779,   766,   778,   779,   782, -1353,  6779,   816,   817,
    5362,  5362,  5362,  1442,  7964, -1353,  4269,   336,  1443,  1444,
   -1353,  5362,  1252, -1353,  6779,  1451,  6779,  1452, -1353,   620,
    1453,  1454, -1353,  1458, -1353,  1457,  8744,  8744,  8744,  8744,
     648,  1228,  1267,  1268,  1286,  1279,   693,   694,  9784,  1291,
    2198, -1353,   194,  1282,  1477,  2384, -1353, -1353, -1353,    29,
    6779, -1353,   821, -1353,   824,   825,   829,   833,   138, -1353,
    9910,  1296,  6779,  6779,  5362,  1307, -1353, -1353, -1353,  1289,
   -1353,  1481,    26,  1484,  6779,  4517,  1485,  1488,    17,  1309,
    1310,  1416,  1416,  5362,  1489,  1313,  1317,  1491,  1515,  5362,
    1321,  1519,  1520, -1353,  1523,  5362,   834,  5362,  5362,  1525,
    1526, -1353,  5362,  5362,  9910,  5362,  9910,  5362,  9910,  5362,
    9910,  5362,  5362,  5362,  1328,  1330,  1527,   283, -1353,  6779,
    6779,  6779,  1332,  1335,  -105,  -102,    98,  1341, -1353,  5362,
   -1353,  6779, -1353,  1535, -1353,  1539, -1353,  1541, -1353,  1542,
   -1353, -1353,  6337,   612,  5167, -1353,  1346,  1347,  5947, -1353,
    6590, -1353, -1353, -1353,  1350,  2445, -1353, -1353,  9043,  1552,
     620,  7990,  8016,  8042,  8068, -1353, -1353, -1353, -1353,  9910,
   -1353,   620,  1568,  1569,  1437, -1353,  6779,  6779,  6779, -1353,
    1571,   412,  1394,  1592,  2612, -1353,  2797, -1353,   138, -1353,
   -1353,   218, -1353, -1353, -1353, -1353, -1353, -1353,  5053, -1353,
   -1353, -1353,  3489,  1606, -1353, -1353,    16, -1353, -1353, -1353,
   -1353, -1353,  3489,  6779,  1607,  1610,    30, -1353,  1609,  9066,
      29, -1353,  1612,  1616,  1621,  1622,  5362,  6779,  8094,  8120,
     837, -1353,  6779,  1625, -1353, -1353,  5053, -1353,  8146,  4127,
    9910, -1353, -1353, -1353, -1353,  6779,  6779,  -100,  1624,  1626,
    1627, -1353,  6779,  6779, -1353, -1353,  1628,  6779, -1353, -1353,
    1630,  1631,  1428,  1632,  1496,  6779, -1353,  1634,  1635,  1636,
    1637,  1638,  1639,  1036,  1640,  6590,  6590,  6779, -1353,  6401,
    6332,  9805,  5301,   458,   458,  -100,  1641,  -100,  1643,  -100,
    1644,  6779,   252,  1449,  9826, -1353, -1353, -1353, -1353,  6367,
     381, -1353,  1647,  3663,  1648,  5362,  -100,  3663,  1649,   861,
    6779, -1353,  1650,    -6, -1353,  6779,  6779,  6779,  6779, -1353,
   -1353, -1353,  5362,  5496,   490,  9847, -1353, -1353,  4582,  5362,
   -1353, -1353, -1353,  5362, -1353,  1461,   620,  4322,  4777,  3489,
    1656,  3177, -1353,  1657,  1659, -1353,  1463, -1353, -1353, -1353,
   -1353, -1353,  1660,   601,  9910,  6779,  6779,  5362,  1464,   862,
    9910, -1353,  1663,  6779, -1353, -1353,  6529,  6675,   268, -1353,
   -1353, -1353,  6703,  7033, -1353,  7061,  1666, -1353,  5362, -1353,
    1588,  1667,  9910, -1353, -1353, -1353, -1353, -1353, -1353,  1471,
   -1353, -1353,   865,   868,  7703,  3196,  1670,  1474, -1353,  6779,
   -1353,  1475,  1476,   385, -1353,  1478,   388, -1353,  1479,   398,
   -1353,  1480,  9089,  1672,  5362,  1677,  1483,  6779, -1353,  6142,
     441, -1353,   869,   496,   513, -1353,  1693,  7089, -1353,  8172,
    8198,  8224,  8250,  1562,  6779, -1353,  6779, -1353, -1353,  6590,
    3332,  1695,  1498,  1699, -1353, -1353,  3922, -1353, -1353,  5053,
    9910, -1353, -1353, -1353, -1353,    29, -1353,  1570, -1353, -1353,
    6779,  8276,  8302, -1353,  5362,  6779,  1703, -1353,  8328, -1353,
   -1353,  1704,  1707,  1708,  1709,  1710,  1711,   879,  1516, -1353,
    5362,   -15,   685,  6590, -1353, -1353,   458,  5691, -1353, -1353,
    6337,   431,  6337,   431,  6337,   431,  1712, -1353,   880,  5362,
   -1353,  7117,  -100,  1714,  6590,  -100, -1353, -1353,  6779,  6779,
    6779,  6779,  6779,  7145,  7173,   891, -1353, -1353,  1715, -1353,
     906,  3694,   910,  1721, -1353,  1529,  9910,  6779,  6779,   911,
    9910, -1353,  6779,   914,   915, -1353, -1353, -1353, -1353, -1353,
   -1353,  1530,  6779,   919,  1531,  -100,  5362,  1723,  1532,  -100,
    1730,   920,  1533,  6779, -1353,  7201,   517,   660,  7229,   521,
     761,  7257,   531,   935, -1353,  5362,  1732,  1645,  2686,  1537,
     554, -1353,   924,   558,  8354,  8380,  8406,  8432,  3439, -1353,
   -1353,  1736, -1353,  6779, -1353,  3489, -1353, -1353,  6779,  9868,
    8458,    54,  8484, -1353, -1353,  6779,  7285,  1739,  -100,    77,
   -1353, -1353,  -100,    86, -1353,  1744, -1353,  7313,  1745,  6779,
    1746,  1747,  6779,  1748,  1749,  6779,  1750,  1566, -1353,  6779,
   -1353,   431, -1353,  6590,  1760,  6142,  6779,  6779,  6779,  6779,
   -1353, -1353,  3734, -1353,   927, -1353,  6779, -1353,  5362,  6779,
    8510, -1353, -1353,   561, -1353,   563, -1353, -1353, -1353, -1353,
    1572,  7341, -1353, -1353,  1574,  7369, -1353, -1353,  1575,  7397,
   -1353,  1765,  3658,  1111,  2929,   930, -1353,   571,   931,  8536,
    8562,  8588,  8614,  3489,  1773,  1580,  9889,   939,  7425,  6779,
    -100,  -100,   431,  1778,   431,  1784,   431,  1785, -1353, -1353,
   -1353, -1353,   431,  1788,  6590,  1790,  6779,  6779,  6779,  6779,
   -1353, -1353,  5053, -1353,  1594,  1792,  7453,   595,   621,  1248,
   -1353,  1596,  1662, -1353,  1597,  1895, -1353,  1600,  1982, -1353,
     944, -1353,  8640,  8666,  8692,  8718,   949, -1353,  1601,  5362,
   -1353,  1801,  6779,  6779,  1802,   431,  1803,   431,  1805,   431,
   -1353,  1806,  6779,  6779,  6779,  6779,  5053,  1807,  5053,   953,
   -1353,  7481,  7509, -1353,  2030, -1353,  2159, -1353,  2314, -1353,
    7537,  7565,  7593,  7621, -1353, -1353,   959, -1353,  1808,  1810,
    1812,  1814,  1815,  1816, -1353, -1353, -1353, -1353,  5053,  1817,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353
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
     481,     0,     0,     0,     0,     0,     0,   223,   224,     0,
     518,     0,     0,   240,   241,     0,   187,     0,   187,   518,
       0,     0,   346,     0,     0,    66,    67,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     352,   354,     0,     0,     0,     0,     0,     0,     0,   186,
       0,   185,     0,    68,    69,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,   216,     0,     0,   414,   164,     0,
     518,     0,   487,   488,     0,     0,   514,     0,   107,   107,
       0,     0,     0,     0,   475,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   308,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   187,     0,   430,   429,     0,
       0,     0,     0,   187,   187,     0,     0,     0,     0,     0,
       0,     0,   258,     0,   187,     0,     0,     0,     0,     0,
     310,     0,     0,     0,     0,     0,     0,     0,   205,   341,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,     0,   452,     0,     0,   453,     0,   454,     0,
     455,     0,     0,     0,     0,     0,     0,   352,   447,     0,
     441,     0,     0,     0,   318,    66,    67,     0,   222,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
     244,   243,   210,     0,   211,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,   419,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     403,   512,     0,     0,     0,     0,     0,     0,     0,     0,
     351,     0,    59,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,   188,     0,     0,    59,     0,     0,   368,
     367,   365,   366,   361,   363,   362,   364,   356,   355,   357,
     358,   359,   360,     0,     0,     0,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   338,   339,     0,     0,     0,     0,   306,
       0,     0,     0,   132,   133,     0,   135,   136,     0,   138,
     139,     0,   141,   142,     0,     0,     0,     0,     0,     0,
       0,   152,   187,     0,     0,     0,     0,     0,   432,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,   321,     0,     0,
     206,     0,     0,   202,     0,     0,     0,   336,   335,     0,
       0,     0,     0,   419,     0,   470,     0,     0,     0,     0,
       0,     0,   456,     0,   457,     0,   458,     0,   459,     0,
       0,   351,   442,   449,     0,   357,   448,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
     212,   214,     0,   520,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    74,     0,   408,   407,   421,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   391,   379,     0,
     381,   382,   383,   384,   385,   386,   387,     0,     0,     0,
     503,     0,   508,   499,   500,   501,     0,     0,     0,     0,
       0,   504,   505,   506,   427,   510,   121,   126,    99,     0,
     496,   498,     0,   405,   411,   412,   492,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,   413,
       0,     0,     0,     0,   516,     0,     0,     0,    44,     0,
       0,     0,    57,     0,    35,    36,    37,    38,    39,   410,
     409,     0,   489,    24,    22,     0,     0,    25,     0,     0,
     217,   515,    70,   110,    71,   118,     0,     0,     0,   477,
     478,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
     309,   307,     0,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   215,     0,     0,     0,   177,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,     0,   249,     0,     0,     0,     0,
       0,     0,   311,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,   472,     0,   451,     0,
       0,     0,     0,     0,     0,     0,   443,     0,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
     209,     0,     0,   347,     0,     0,     0,     0,   517,     0,
       0,     0,   416,     0,   415,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,    84,    89,    91,     0,
       0,   485,     0,    97,     0,     0,     0,     0,     0,    75,
     369,     0,     0,     0,     0,     0,    30,   418,   417,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,   134,     0,   137,     0,   140,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
     292,     0,   298,     0,   300,     0,   294,     0,   296,     0,
     259,   288,     0,     0,     0,   200,     0,     0,     0,   322,
       0,   204,   203,   342,     0,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,   460,   461,   462,   463,   450,
     444,     0,     0,     0,     0,   482,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    87,     0,    86,     0,    76,
     219,   420,   218,   380,   388,   389,   390,   509,     0,   424,
     425,   426,     0,     0,   404,   122,     0,   513,   127,   423,
     497,    78,    59,     0,     0,     0,     0,    77,     0,     0,
       0,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   437,     0,     0,    26,    27,     0,    28,     0,     0,
     111,   114,    72,    73,   148,     0,     0,     0,     0,     0,
       0,   151,     0,     0,   167,   168,     0,     0,   153,   174,
       0,     0,     0,     0,   144,     0,   314,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   221,     0,
       0,     0,     0,   187,   187,     0,   269,     0,   271,     0,
     273,     0,   439,     0,     0,   299,   301,   295,   297,     0,
       0,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,     0,   420,   473,     0,     0,     0,     0,   474,
     156,   157,     0,     0,     0,     0,   100,   104,     0,     0,
     348,    80,    79,     0,   422,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,   486,   189,   190,
     191,   192,     0,     0,    40,     0,     0,     0,     0,     0,
      42,   490,     0,     0,   112,   115,     0,     0,   147,   154,
     155,   159,     0,     0,   169,     0,     0,   316,     0,   162,
       0,     0,   305,   173,   149,   161,   172,   176,   160,     0,
     170,   175,     0,     0,     0,     0,     0,     0,   436,     0,
     435,     0,     0,     0,   260,     0,     0,   261,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   198,     0,     0,     0,   193,     0,     0,    33,     0,
       0,     0,     0,     0,     0,   480,     0,   237,   236,     0,
       0,     0,     0,     0,   502,   507,     0,   123,   125,     0,
     128,   129,   130,    90,    92,     0,    98,     0,    81,    45,
       0,     0,     0,   438,     0,     0,     0,    29,     0,   121,
     126,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,   312,   312,     0,   105,   106,   187,     0,   180,   181,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
     187,     0,     0,     0,     0,     0,   184,   183,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,    82,
       0,   475,     0,     0,   484,     0,    41,     0,     0,     0,
      43,    58,     0,     0,     0,   330,   332,   331,   333,   334,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,     0,     0,     0,   254,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,   479,
     238,     0,   349,     0,   124,     0,   131,    96,     0,     0,
       0,     0,     0,   113,   116,     0,     0,     0,     0,     0,
     313,   323,     0,     0,   324,     0,   178,     0,   275,     0,
       0,   277,     0,     0,   279,     0,     0,     0,   290,     0,
     250,     0,   187,     0,     0,     0,     0,     0,     0,     0,
     158,   103,     0,   119,     0,    49,     0,    55,     0,     0,
       0,   145,   171,     0,   327,     0,   328,   329,   433,   263,
       0,     0,   270,   264,     0,     0,   272,   265,     0,     0,
     274,     0,     0,     0,   256,     0,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,   283,     0,   285,   291,   302,
     255,   251,     0,     0,     0,     0,     0,     0,     0,     0,
     120,    46,     0,    53,     0,     0,     0,     0,     0,     0,
     266,     0,     0,   267,     0,     0,   268,     0,     0,   201,
       0,   195,     0,     0,     0,     0,     0,    47,     0,     0,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,   276,     0,   278,     0,   280,     0,   196,
       0,     0,     0,     0,    48,    50,     0,    51,     0,     0,
       0,     0,     0,     0,   464,   465,   466,   467,     0,     0,
      56,   325,   326,   282,   284,   286,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1353, -1353, -1353, -1353,   702, -1353, -1353, -1353, -1353,   188,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353,  -380,  -103,   -13,    -1, -1353,  1378, -1353, -1353,
   -1353, -1353, -1353,   323, -1353,   328, -1353, -1353, -1353, -1353,
   -1353, -1353,   718,  1848,     7,  -492,  -255, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353,  1849, -1353, -1353, -1353, -1353, -1353,
   -1353, -1353, -1353, -1353, -1353, -1353, -1353, -1353,  -965,  -947,
   -1353, -1353,  1374, -1353,   322, -1353, -1353, -1353, -1353,  1548,
   -1353, -1353,     0, -1353, -1352,  2121,  1021,  2439,  1731,  -246,
     592, -1353,    21,    62, -1353,  -372,    -3,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   935,    91,    92,   683,  1403,  1409,
     924,  1111,  1575,  1776,   925,  1725,  1816,   926,  1778,   927,
     928,  1115,   346,   437,   183,   416,    93,   698,   448,  1519,
    1520,   449,  1570,  1086,  1255,  1087,  1258,   732,   735,   738,
     741,  1431,  1298,   663,   298,   410,   411,    96,    97,    98,
      99,   100,   101,   102,   299,  1016,  1671,  1742,   767,  1455,
    1458,  1461,  1700,  1704,  1708,  1761,  1764,  1767,  1012,  1013,
    1150,   972,   729,   776,  1597,   104,   105,   106,   107,   300,
     185,   886,   498,   256,  1280,   301,   302,   303,   561,   312,
     908,  1102,   446,   442,   887,   447,   188,   305
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   493,   625,  1472,   627,   524,   347,   512,   207,   208,
      95,   760,   761,   543,   320,   638,  1058,   933,   272,   527,
    1388,     4,   218,  1294,   653,   546,   348,   186,   918,   413,
     548,   414,  1285,   310,   906,   415,   667,   218,  1182,   325,
     327,   209,   213,   213,     5,   550,   802,   804,   210,   255,
     257,  1193,   263,   191,   275,   806,   808,   192,   332,   194,
    1687,   277,   304,   278,   259,  1191,   193,   260,   187,   313,
     261,   583,  1184,   585,  1186,   247,  1527,   205,   275,   206,
    1188,   501,   502,  1694,   501,   502,   251,   252,  1594,  1595,
     248,   249,  1696,   190,  1596,   338,   253,  1335,   109,  1336,
    1337,   189,  1338,   254,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   689,
     666,   501,   502,   279,   690,   383,   384,   385,   386,   339,
     404,   388,   200,   321,   324,   666,  1092,   389,   390,  1173,
     196,   544,   276,   395,   919,   920,   921,   922,   344,   345,
    1183,   243,  1579,   547,   244,   273,   501,   502,   549,  -488,
    1389,   335,   652,   336,   251,   252,   322,   275,  1593,   666,
     337,    89,   755,   551,   253,    89,   344,   345,   409,   275,
     275,   262,   501,   502,  1185,   934,  1187,   275,   268,   525,
     269,  1262,  1189,   501,   502,   275,   182,   304,   762,  1059,
     934,   545,   304,   441,   444,   841,   304,   274,   349,   304,
     350,   219,   351,   304,   304,   304,   304,   182,   923,   304,
     304,   304,   311,   907,   214,   214,   912,   326,   328,   753,
     754,   215,   911,   304,   803,   805,  1191,   197,   333,   282,
     496,   497,   283,   807,   809,   334,   195,  1688,   505,   769,
     562,   314,   513,   501,   502,   304,   304,   304,   203,   450,
     897,   900,   501,   502,   541,   407,   405,   406,   264,   304,
     304,   198,  1093,  1094,   501,   502,   515,   443,   443,  1328,
    1329,   567,   304,   516,   304,   443,   340,   341,   342,   343,
    1339,   654,  1340,   451,   199,   340,   341,   342,   343,   344,
     345,   340,   341,   342,   343,   344,   345,   501,   502,   824,
    -489,   344,   345,   899,   344,   345,   501,   502,   275,  1209,
     304,   304,   832,  1129,   503,  1130,  1727,   595,   340,   341,
     342,   343,   768,   304,  1228,   340,   341,   342,   343,   209,
     265,   349,   588,   586,   266,   540,   910,   344,   345,   696,
     182,   705,   697,   706,   344,   345,   267,   340,   341,   342,
     343,   275,   275,   275,   275,   275,   275,   304,   275,   275,
     201,   275,   275,   275,   275,   275,   344,   345,   202,   275,
     275,   275,   275,   275,   657,   275,   626,   221,   628,   629,
     630,   596,   632,   633,   913,   635,   636,   637,   204,   639,
     344,   345,   304,   643,   644,   645,   646,   236,  1377,  1378,
     237,  -490,   413,   238,   414,   239,   443,  1799,   594,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     563,   430,   431,   501,   502,   501,   502,   432,   501,   502,
     304,   705,   641,   711,   501,   502,  1463,  1064,  1066,   648,
     504,  1169,   408,   211,   699,   514,   435,   697,   436,   443,
     443,   443,   443,   443,   443,   337,   443,   443,   212,   443,
     443,   443,   443,   443,   216,   304,   304,   443,   443,   443,
     443,   647,   217,   649,   413,   220,   414,   990,  1486,   847,
     794,   758,   759,   427,   428,   429,   430,   431,   221,   497,
     409,   409,   432,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   304,   304,   304,
    1003,   432,   227,  1229,   222,   228,   501,   502,   229,   275,
     795,  1004,   223,   734,   737,   740,   743,   898,   901,  1005,
    1006,  1007,  1192,   304,   691,  1008,  1009,  1010,  1011,   692,
     304,    48,    49,    50,    51,   224,   818,   501,   502,   226,
      56,   501,   502,    59,   501,   502,  1607,   694,  1610,   565,
    1613,   566,   695,  1467,   501,   502,   552,  1540,   337,   553,
    1542,   304,   554,   232,   555,  1153,   233,  1155,   234,  1157,
    1544,  1159,   848,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   225,   860,   861,   862,   863,   864,   865,
     866,  1003,   230,   231,   870,   872,   873,   501,   502,   705,
     235,   715,  1004,   245,   881,   882,   883,   796,   885,   884,
    1005,  1006,  1007,  1552,   695,   893,  1008,  1009,  1010,  1011,
     538,   687,   539,   688,   540,   246,   909,   181,   182,   182,
    1191,  1101,   250,  1191,   304,   258,  1191,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   891,   501,   502,   271,   432,   892,   304,   240,   304,
     847,   241,   275,   242,  1487,   275,   270,   275,  1554,   501,
     502,   304,   304,   501,   502,  1122,  1713,   501,   502,   280,
     705,  1003,  1263,   281,   902,  1555,   941,   501,   502,  1659,
     284,   945,  1004,  1662,  1123,   304,  1190,   285,  1276,   705,
    1005,  1006,  1007,  1665,  1065,  1067,  1008,  1009,  1010,  1011,
     501,   502,  1072,  1074,   501,   502,   304,   501,   502,   501,
     502,   705,   705,   721,   812,   993,  1673,   501,   502,  1003,
    1675,   286,   999,  1730,   947,  1731,  1191,  1759,  1014,  1762,
    1004,  1765,   835,  1744,   836,   306,   307,  1768,  1005,  1006,
    1007,   501,   502,   308,  1008,  1009,  1010,  1011,  1598,  1599,
     443,   304,   309,   943,  1596,   443,   315,  1782,  1509,   413,
     304,   414,   304,  1510,   304,   817,   304,   501,   502,   316,
     317,   304,  1191,   318,   304,  1191,  1351,   413,  1191,   414,
    1804,  1191,  1806,  1783,  1808,   319,  1117,  1118,   429,   430,
     431,   331,   304,   417,   413,   432,   414,   377,   304,   695,
     378,  1451,  1452,   275,   413,   413,   414,   414,   379,   871,
     705,   380,   381,  1268,     7,     8,   391,  1191,  1383,  1191,
    1003,  1191,   382,   705,  1660,   915,   387,  1075,   304,   392,
     705,  1004,   986,   275,   304,   275,   275,   393,   394,  1005,
    1006,  1007,   705,   396,   987,  1008,  1009,  1010,  1011,   275,
     413,   413,   414,   414,   397,  1253,  1256,  1081,   412,  1083,
    1084,   705,   705,  1028,  1029,   398,   433,   304,   304,   304,
     304,   434,   470,  1089,  1108,   705,   459,  1030,   659,    24,
      25,   660,    27,    28,   661,    30,   662,    32,   705,    33,
    1046,  1074,   275,   464,    38,    39,   469,    41,    42,    43,
     438,   443,  1085,    46,   475,  1126,  1127,   476,  1128,   304,
     304,   705,   304,  1069,   304,   304,  1121,   488,   304,   304,
    1135,   491,  1136,   304,   705,  1663,  1166,   705,   705,  1210,
    1215,   443,   480,   443,   443,   494,   481,    67,    68,    69,
     705,   705,  1216,  1217,   705,   482,  1218,   443,   483,  1264,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   484,
    1174,  1175,  1176,   432,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   705,   705,
    1220,  1221,   432,  1270,  1397,  1271,   705,   705,  1272,  1273,
     443,   705,   485,  1274,  1003,   705,   705,  1275,  1312,  1407,
    1439,  1408,  1440,   486,  1602,  1004,   783,   304,   304,   304,
     487,   440,   112,  1005,  1006,  1007,   495,   526,   304,  1008,
    1009,  1010,  1011,   705,  1515,  1476,  1516,   705,  1238,  1531,
     705,  1407,  1532,  1553,   506,  1243,  1244,  1245,  1246,  1247,
     507,  1407,  1615,  1591,  1616,  1254,  1257,   139,   140,   141,
     142,   143,   144,   705,   517,  1631,   148,   149,   150,   151,
       7,     8,   508,   518,   153,   154,   155,   337,  1633,   156,
    1634,   304,   695,  1407,  1636,  1641,  1253,  1256,  1643,  1644,
     161,  1407,   705,  1647,  1655,   519,   705,  1572,  1674,  1515,
     304,  1724,   705,   705,  1743,  1745,   304,   523,  1384,  1666,
     528,  1407,   304,  1754,   304,   304,   705,   529,  1791,   304,
     304,  1796,   304,  1797,   304,  1407,   304,  1818,   304,   304,
     304,  1828,   535,  1829,   659,    24,    25,   660,    27,    28,
     661,    30,   662,    32,   530,    33,   304,   531,   532,   536,
      38,    39,   537,    41,    42,    43,   542,  1291,   564,    46,
     568,   304,  1350,   572,   574,   304,   575,   304,   580,   182,
     581,   582,   584,   593,   598,   164,   165,   599,   602,  1364,
    1003,   432,   655,   656,   181,   718,   172,   658,    89,   173,
    1369,  1004,   701,    67,    68,    69,   702,   722,   723,  1005,
    1006,  1007,   724,   752,   727,  1008,  1009,  1010,  1011,   344,
     345,   728,   750,   751,   777,   275,   775,  1073,   472,   473,
     474,   778,   780,   477,   478,   479,   787,   788,   793,  1573,
    1384,   797,   822,   799,   800,   801,   825,   833,   834,  1385,
     842,   843,   874,   304,   875,   876,   877,   890,   878,   894,
     879,   889,   895,   275,   904,   896,   304,   905,   932,   520,
     521,   937,   830,   940,   942,  1618,   686,  1418,   944,   951,
     948,   952,   953,   533,   534,   955,   956,  1412,   957,   958,
     960,   961,   962,   966,  1386,  1740,   971,   973,   975,   976,
     977,   978,   304,   304,  1390,   979,   980,   981,   982,   989,
       7,     8,  1023,  1053,  1036,  1453,   996,  1456,  1050,  1459,
     409,   409,   997,   443,  1051,  1037,  1039,  1003,  1040,  1041,
     304,  1415,   304,  1470,   304,  1052,  1473,  1474,  1004,  1063,
    1061,  1091,  1096,  1097,  1100,  1099,  1005,  1006,  1007,   304,
    1103,  1109,  1008,  1009,  1010,  1011,   304,  1112,  1114,  1113,
     304,   443,  1116,  1120,   304,  1495,  1125,  1133,  1139,   888,
    1140,  1446,  1144,  1145,   659,    24,    25,   660,    27,    28,
     661,    30,   662,    32,   304,    33,  1147,  1148,  1098,  1151,
      38,    39,  1152,    41,    42,    43,  1161,  1714,  1162,    46,
    1163,  1164,  1165,  1167,  1177,   304,  1179,  1178,  1181,  1180,
    1248,  1194,  1195,  1200,     7,     8,  1196,  1197,  1198,  1201,
    1491,  1202,  1203,  1204,  1206,  1207,  1225,  1230,  1231,  1498,
    1501,  1502,  1784,    67,    68,    69,  1233,  1235,  1237,  1239,
    1240,   304,  1241,  1242,  1249,  1250,   304,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,  1252,  1265,  1251,  1266,   432,   304,  1284,  1260,  1283,
    1287,  1292,  1277,   304,  1293,  1301,   275,  1304,   659,    24,
      25,   660,    27,    28,   661,    30,   662,    32,  1297,    33,
    1282,   304,  1295,  1296,    38,    39,  1302,    41,    42,    43,
    1303,  1305,   831,    46,  1307,  1308,  1309,   304,  1310,  1315,
     304,  1325,  1316,  1326,  1327,  1333,     7,     8,  1334,  1341,
    1606,  1345,  1609,   409,  1612,  1346,   304,  1347,  1348,  1355,
    1356,   304,  1620,  1360,   184,  1623,  1363,    67,    68,    69,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,  1370,  1371,  1372,  1376,   432,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   304,   443,  1649,  1379,   432,  1380,  1653,
     659,    24,    25,   660,    27,    28,   661,    30,   662,    32,
    1387,    33,   304,  1392,  1393,  1395,    38,    39,  1398,    41,
      42,    43,  1399,     7,     8,    46,   991,  1400,  1401,  1411,
    1419,  1428,  1420,  1421,  1424,  1426,   330,  1427,  1429,  1430,
    1433,  1434,  1435,  1436,  1437,  1438,  1441,  1454,  1693,  1457,
    1460,  1464,  1695,  1468,  1471,  1475,  1478,  1143,  1494,    67,
      68,    69,  1503,  1507,  1505,  1506,  1508,  1514,  1528,  1517,
     304,  1526,   304,  1529,  1530,  1717,  1535,  1536,  1547,  1538,
    1539,  1541,  1543,  1545,  1549,   304,  1550,   659,    24,    25,
     660,    27,    28,   661,    30,   662,    32,  1683,    33,  1556,
    1562,  1567,  1568,    38,    39,  1569,    41,    42,    43,  1581,
    1585,  1574,    46,  1586,  1587,  1588,  1589,  1590,  1614,  1592,
    1621,  1632,   399,   400,   401,   402,   403,  1637,   992,  1651,
    1757,  1758,  1638,  1645,  1648,  1652,  1654,  1656,  1668,   439,
    1672,   304,  1681,   445,  1669,  1692,    67,    68,    69,   275,
    1697,  1699,  1702,  1703,  1706,  1707,  1710,   452,   454,   457,
     458,  1003,   460,   454,   462,   463,  1716,   454,   466,   467,
    1711,  1738,  1004,  1777,   454,  1732,   304,  1734,  1736,  1751,
    1005,  1006,  1007,  1752,  1760,  1750,  1008,  1009,  1010,  1011,
    1763,  1766,   490,   275,  1769,   275,  1771,  1779,  1780,  1785,
    1787,   499,   500,  1789,  1798,     7,     8,  1800,  1803,  1805,
     500,  1807,  1809,  1815,  1830,  1015,  1831,  1814,  1832,  1817,
    1833,  1834,  1835,  1837,  1286,   275,  1684,   700,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,  1583,   557,   559,   454,   432,   443,  1584,  1836,
    1299,    94,   103,   730,  1600,   569,   570,   571,  1394,   573,
       0,     0,   576,   577,   578,     0,  1786,   579,     0,   659,
      24,    25,   660,    27,    28,   661,    30,   662,    32,     0,
      33,     0,     0,   591,   592,    38,    39,     0,    41,    42,
      43,   443,     0,   443,    46,     0,     0,   600,   601,     0,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,     0,   443,     0,     0,     0,     0,    67,    68,
      69,   634,     0,     0,     0,     0,     0,   640,     0,   642,
       0,   456,     0,     0,  1199,     0,   461,     0,     0,     0,
     465,     0,     0,     0,     0,     0,     0,   471,     0,     0,
     664,     0,     0,   454,     0,     0,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,     0,     0,   684,   685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1003,     0,     0,  1055,     0,     0,
       0,   557,     0,     0,     0,  1004,     0,   709,     0,     0,
       0,     0,   714,  1005,  1006,  1007,     0,   719,   720,  1008,
    1009,  1010,  1011,   725,   726,     0,     0,     0,   731,   733,
     736,   739,   742,   744,   745,   746,   454,   454,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,   763,   764,   765,   399,   400,   766,
       0,     0,     0,   770,   771,   772,   773,   774,     0,     0,
       0,   779,     0,   781,   782,     0,     0,     0,   454,   454,
     454,  1003,     0,   789,   790,   791,   600,   792,     0,     0,
       0,     0,  1004,   798,     0,     0,     0,     0,     0,  1788,
    1005,  1006,  1007,     0,   454,     0,  1008,  1009,  1010,  1011,
     813,   815,     0,   684,   685,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,  1003,
       0,     0,     0,   432,   792,     0,     0,     0,     0,     0,
    1004,   839,   454,     0,     0,     0,   665,   844,  1005,  1006,
    1007,     0,   110,   329,  1008,  1009,  1010,  1011,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,  1790,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,   903,   152,     0,  1261,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,   747,
     748,   160,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1821,   931,     0,     0,   454,     0,
     454,   939,     0,     0,     0,     0,     0,     0,     0,   946,
       0,     0,   815,   949,     0,     0,     0,     0,  1003,     0,
       0,   784,   785,   786,     0,     0,   963,     0,     0,  1004,
       0,     0,     0,     0,     0,   969,     0,  1005,  1006,  1007,
       0,     0,     0,  1008,  1009,  1010,  1011,   810,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   454,     0,     0,
       0,     0,     0,     0,   994,   995,   163,     0,     0,   166,
     998,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,     0,     0,  1022,     0,   840,  1024,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
     176,     0,   454,   468,     0,   296,     0,     0,     0,     0,
     180,   454,   489,   454,     0,   454,     0,   454,     0,     0,
       0,     0,   454,  1822,     0,   454,     0,   492,     0,     0,
       0,  1054,     0,  1056,  1057,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
    1267,   522,     0,   432,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,  1076,     0,     0,
     432,     0,     0,  1003,     0,  1077,  1078,  1079,     0,   454,
       0,   936,     0,   938,  1004,     0,     0,     7,     8,     0,
       0,     0,  1005,  1006,  1007,     0,     0,  1088,  1008,  1009,
    1010,  1011,     0,     0,     0,  1090,     0,     0,  1095,     0,
       0,  1361,     0,     0,   589,   590,     0,     0,   454,   454,
     454,   454,     0,     0,     0,  1110,     0,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   659,    24,    25,   660,    27,    28,   661,    30,   662,
      32,   631,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,   454,     0,    46,     0,  1823,     0,
       0,     0,     0,     0,  1154,  1035,  1156,     0,  1158,     0,
    1160,     0,     0,     0,  1042,     0,  1043,     0,  1044,     0,
    1045,     0,     0,     0,     0,  1048,     0,     0,  1049,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,  1205,   432,
       0,  1208,     0,     0,     0,  1211,     0,  1212,  1213,  1214,
       0,     0,     0,     0,     0,  1219,     0,     0,     0,     0,
       0,     0,  1080,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1234,     0,  1236,     0,     0,     0,  1381,  1060,
       7,     8,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,  1104,  1105,  1106,  1107,     0,     0,     0,  1269,   455,
       0,     0,     0,     0,   455,     0,     0,     0,   455,     0,
    1278,  1279,     0,     0,     0,   455,     0,     0,     0,     0,
       0,     0,  1288,  1290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   659,    24,    25,   660,    27,    28,
     661,    30,   662,    32,     0,    33,     0,  1146,     7,     8,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,  1330,  1331,  1332,
       0,     0,     0,     0,     0,     0,     0,  1342,     0,  1344,
       0,     0,     0,     0,   558,     0,   455,     0,     0,     0,
    1349,     0,     0,    67,    68,    69,     0,     0,   454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   659,    24,    25,   660,    27,    28,   661,    30,
     662,    32,     0,    33,  1373,  1374,  1375,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,   916,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,  1382,     0,     0,     0,   432,     0,     0,
       0,  1391,  1168,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,  1404,     0,     0,     0,     0,
    1410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1416,  1417,     0,     0,     0,     0,   970,
    1422,  1423,     0,     0,   455,  1425,     0,     0,     0,     0,
       0,     0,     0,  1432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   454,   454,  1444,     0,  1445,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1462,
    1670,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,   454,     0,     0,     0,   454,     0,     0,  1477,     0,
       0,     0,     0,  1479,  1480,  1481,  1482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1490,   455,   455,     0,
       0,  1359,     0,     0,     0,     0,  1500,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1511,  1512,     0,  1062,     0,     0,     0,
       0,  1518,  1070,     0,     0,     0,     0,     0,     0,   455,
     455,   455,     0,     0,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   562,     0,
       0,     0,   432,     0,     0,   455,     0,  1537,  1082,     0,
       0,     0,   816,     0,     0,   659,    24,    25,   660,    27,
      28,   661,    30,   662,    32,  1551,    33,   557,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,  1563,   455,  1564,     0,     0,   454,     0,     0,
       0,     0,     0,     0,  1571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1442,  1443,  1576,     0,
       0,     0,     0,  1580,    67,    68,    69,     0,     0,     0,
       0,     0,     0,  1131,  1132,     0,  1134,     0,  1137,  1138,
       0,   454,  1141,  1142,     0,     0,     0,     0,  1605,     0,
    1608,     0,  1611,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,     0,     0,     0,  1624,  1625,  1626,  1627,
    1628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1639,  1640,     0,     0,   455,
    1642,   455,     0,  1741,     0,     0,     0,     0,     0,     0,
    1646,     0,     0,   816,   950,     0,     0,     0,     0,     0,
       0,  1657,     0,     0,     0,     0,     0,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   563,   430,
     431,  1222,  1223,  1224,     0,   432,     0,     0,     0,     0,
       0,  1682,  1232,  1504,     0,     0,  1410,     0,   455,     0,
       0,     0,     0,  1690,     0,     0,     0,     0,     0,     0,
       0,     0,  1534,     0,     0,     0,     0,  1701,     0,     0,
    1705,     0,     0,  1709,     0,     0,     0,  1712,     0,     0,
    1565,   454,     0,   454,  1719,  1720,  1721,  1722,     0,     0,
       0,     0,     0,   455,  1726,  1281,     0,  1728,     0,     0,
       0,     0,   455,     0,   455,     0,   455,     0,   455,     0,
       0,     0,     0,   455,  1300,     0,   455,     0,     0,     0,
    1306,     0,     0,     0,  1601,     0,  1311,     0,  1313,  1314,
       0,     0,     0,  1317,  1318,     0,  1319,  1756,  1320,     0,
    1321,     0,  1322,  1323,  1324,  1622,     0,     0,     0,     0,
       0,     0,   454,     0,  1772,  1773,  1774,  1775,     0,     0,
    1343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     455,     0,     0,     0,     0,  1354,     0,     0,     0,  1358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1801,  1802,     0,     0,     0,     0,     0,     0,  1566,     0,
    1810,  1811,  1812,  1813,     0,     0,     0,     0,     0,   455,
     455,   455,   455,     0,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,  1402,     0,     0,
       0,     0,     0,     0,  1715,   455,  1718,     0,     0,     0,
    1414,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,  1680,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,   157,   158,   159,  1770,  1281,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1483,   112,     0,     0,     0,     0,     0,
    1492,     0,     0,     0,  1493,     0,     0,     0,  1497,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,  1513,   139,
     140,   141,   142,   143,   144,     0,     0,     0,   148,   149,
     150,   151,     0,     0,     0,     0,   153,   154,   155,  1281,
       0,   156,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   161,     0,     0,   163,   164,   165,   166,     0,
       0,     0,   167,   168,   169,   170,   171,   172,     0,    89,
     173,     0,     0,     0,     0,  1548,     0,     0,     0,     0,
       0,     0,     0,     0,   174,   175,     0,     0,     0,   176,
       0,     0,     0,     0,   177,     0,   178,     0,   179,   180,
       0,   181,     0,   182,     0,     0,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,  1281,     0,     0,     0,   455,
       0,     0,     0,     0,     0,     0,     0,   164,   165,     0,
       0,  1281,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   173,     0,     0,  1739,     0,   110,   287,     0,     0,
    1617,     0,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     289,  1635,   562,     0,     0,     0,     0,     0,     0,   145,
     146,   147,     0,     0,     0,     0,   152,  1650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
       0,     0,     0,     7,     8,   160,  1667,     0,     0,   290,
       0,  1723,   291,     0,     0,   292,     0,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   294,
       0,     0,     0,     0,   455,   455,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   455,     0,     0,     0,   455,   659,    24,    25,
     660,    27,    28,   661,    30,   662,    32,     0,    33,  1281,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
     163,     0,    46,   166,     0,     0,     0,   167,   168,   169,
     170,   171,     0,     0,    89,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   509,
    1469,     0,     0,   432,   176,     0,    67,    68,    69,   511,
       0,     0,     0,     0,   180,     0,   254,   560,     0,   562,
       0,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   704,   430,   431,     0,     0,     0,   826,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1281,     0,     0,     0,     0,     0,     0,     0,   558,     0,
       0,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   110,   287,     0,   455,   432,
       0,   113,   114,   115,     0,   455,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,   455,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,   455,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   704,
     430,   431,     0,     0,     0,     0,   432,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,   917,   432,     0,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   453,
       0,     0,   455,   176,   455,     0,     0,     0,   296,     0,
       0,     0,     0,   180,     0,     0,   560,     0,     0,     0,
     110,   287,   112,     0,     0,     0,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   289,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,   455,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,  1227,     0,     0,
       0,   432,     0,     0,   163,   164,   165,   166,     0,     0,
       0,   167,   168,   169,   170,   171,   172,     0,    89,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   295,     0,     0,     0,   176,     0,
       0,     0,     0,   296,     0,   110,   287,   112,   180,     0,
     297,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,   161,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   163,
     164,   165,   166,   432,     0,     0,   167,   168,   169,   170,
     171,   172,   914,    89,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   295,
       0,     0,     0,   176,     0,     0,     0,     0,   296,     0,
     110,   329,   112,   180,     0,  1496,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,   110,   329,   112,     0,   160,
     161,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   163,   164,   165,   166,   432,     0,
       0,   167,   168,   169,   170,   171,   172,   965,    89,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,     0,     0,     0,   176,     0,
       0,     0,     0,   296,     0,     0,     0,     0,   180,     0,
    1289,     0,     0,     0,     0,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   163,
     164,   165,   166,   432,     0,     0,   167,   168,   169,   170,
     171,   172,  1018,    89,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
       0,     0,     0,   176,     0,     0,     0,     0,   296,     0,
     110,   329,   112,   180,  1149,  1489,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,     0,     0,     0,   320,   112,     0,     0,
       0,     0,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   148,   149,   150,   151,     0,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   164,   165,   166,     0,     0,
       0,   167,   168,   169,   170,   171,   172,     0,    89,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   175,     0,     0,     0,   176,     0,
       0,     0,     0,   296,     0,   110,   287,   288,   180,     0,
    1499,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
     164,   165,     0,     0,     0,     0,     0,     0,   145,   146,
     147,   172,     0,    89,   173,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,   440,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,     0,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   174,   295,
       0,     0,   432,   176,   811,     0,     0,     0,   296,   756,
     110,   287,  1352,   180,     0,   297,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   289,     0,     0,     0,     0,     0,
       0,   164,   165,   145,   146,   147,     0,     0,     0,     0,
     152,     0,   172,     0,    89,   173,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,   293,   323,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   148,   149,   150,
     151,     0,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   163,     0,     0,   166,     0,     0,
       0,   167,   168,   169,   170,   171,     0,     0,    89,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   174,   295,     0,     0,   432,   176,     0,
       0,     0,     0,   296,   693,   110,   287,     0,   180,     0,
    1353,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,     0,     0,     0,     0,   164,   165,   145,   146,
     147,     0,     0,     0,     0,   152,     0,   172,     0,     0,
     173,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,  1449,     0,  1450,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   174,   295,
       0,     0,   432,   176,     0,     0,     0,     0,   296,   756,
     110,   287,     0,   180,     0,   297,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   289,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1484,     0,
    1485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   166,     0,     0,
       0,   167,   168,   169,   170,   171,     0,     0,    89,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   174,   453,     0,     0,   432,   176,     0,
       0,     0,     0,   296,   757,   110,   287,     0,   180,     0,
     556,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,  1603,     0,  1604,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   174,   453,
       0,     0,   432,   176,     0,     0,     0,     0,   296,   823,
     110,   287,     0,   180,     0,   814,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   289,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   292,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
    1038,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,   166,     0,     0,
       0,   167,   168,   169,   170,   171,     0,     0,    89,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   174,   295,     0,     0,   432,   176,     0,
       0,     0,     0,   296,   859,   110,   287,     0,   180,     0,
    1357,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   289,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   290,     0,
       0,   291,     0,     0,   292,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1068,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,   166,     0,     0,     0,   167,   168,   169,   170,
     171,     0,     0,    89,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   509,  1469,
       0,     0,   432,   176,     0,     0,     0,     0,   511,   867,
     110,   329,     0,   180,     0,   254,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   146,   147,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   110,   329,   112,     0,     0,   160,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,   153,   154,
     155,     0,     0,   156,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,   161,     0,     0,     0,     0,     0,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   163,     0,     0,   166,   432,     0,
       0,   167,   168,   169,   170,   171,     0,  1172,    89,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   509,   510,     0,     0,   432,   176,     0,
       0,     0,     0,   511,     0,     0,  1447,     0,   180,     0,
     254,     0,     0,     0,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   163,   164,
     165,   166,   432,     0,     0,   167,   168,   169,   170,   171,
     172,  1466,    89,   173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   175,     0,
       0,     0,   176,   110,   287,     0,     0,   296,     0,   113,
     114,   115,   180,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   289,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   290,     0,     0,   291,
       0,     0,   292,     0,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
     166,     0,     0,     0,   167,   168,   169,   170,   171,     0,
       0,    89,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   174,   453,     0,     0,
     432,   176,   110,   329,     0,     0,   296,   868,   113,   114,
     115,   180,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1522,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,     0,     0,   163,     0,     0,   166,
       0,     0,     0,   167,   168,   169,   170,   171,     0,     0,
      89,     0,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,   174,   175,     0,     0,     0,
     176,     0,    -4,    -4,    -4,   296,     0,     0,    -4,    -4,
     180,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,    -4,     6,     0,     0,     0,     0,    -4,     0,     0,
       7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     9,    10,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,    89,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1524,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1525,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1557,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1619,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1629,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1630,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1658,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1661,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1664,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1691,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1698,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1733,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1735,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1737,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1755,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1781,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1819,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,     0,  1820,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,  1824,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,     0,     0,     0,     0,     0,  1825,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,  1826,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,  1827,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,     0,   587,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,   749,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,  1533,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,   869,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,   880,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1000,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1001,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1002,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1033,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1124,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1170,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1171,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1226,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1365,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1366,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1367,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1368,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1405,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1406,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1413,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1558,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1559,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1560,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1561,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1577,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1578,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1582,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1676,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1677,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1678,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1679,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1686,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1689,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1729,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1746,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1747,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1748,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,  1749,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,  1792,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,  1793,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,  1794,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,     0,     0,     0,
    1795,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   413,     0,   414,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,   651,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,   829,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,   838,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,   846,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,   930,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,     0,
       0,  1026,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,     0,     0,  1027,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,     0,     0,  1031,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,     0,     0,
    1032,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,     0,     0,  1034,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,     0,     0,  1071,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,     0,     0,  1119,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
       0,     0,  1362,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,     0,     0,  1396,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,     0,     0,  1546,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   650,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     703,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   707,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,   708,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   710,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,   712,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,   713,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,   716,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,   717,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,   811,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   819,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     820,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   821,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,   827,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   828,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,   837,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,   845,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,   929,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,   954,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,   959,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,   964,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
     967,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,   968,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,   974,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,   983,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,   984,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,   985,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,  1017,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,     0,  1019,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,     0,  1020,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,   432,     0,  1021,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,     0,
    1025,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
       0,  1259,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,     0,     0,
     432,     0,  1448,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,     0,  1465,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,     0,  1488,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,     0,  1685,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,     0,  1753,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432
};

static const yytype_int16 yycheck[] =
{
       3,   247,   374,  1355,   376,     4,   109,   262,    21,    22,
       3,   503,   504,     5,     4,   387,     7,     6,     4,   274,
       4,     6,     4,     6,   404,     5,     4,     6,     4,   197,
       5,   199,     6,     4,     4,   203,   416,     4,     6,     5,
       5,   196,     4,     4,     0,     5,     5,     5,   203,    49,
      50,  1016,    52,    82,    57,     5,     5,   196,     6,     6,
       6,     4,    65,     6,    76,  1012,   196,    79,     6,     4,
      82,   326,     6,   328,     6,   140,  1428,   196,    81,   198,
       6,   186,   187,     6,   186,   187,   186,   187,   103,   104,
     155,   156,     6,    13,   109,   108,   196,   202,     3,   204,
     202,     6,   204,   203,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   197,
       7,   186,   187,    76,   202,   148,   149,   150,   151,     7,
       4,   154,   196,    81,    82,     7,     4,   160,   161,   204,
       6,   143,    57,   166,   130,   131,   132,   133,   192,   193,
     128,    79,  1514,   143,    82,   151,   186,   187,   143,   203,
     154,   196,     7,   198,   186,   187,    81,   180,  1530,     7,
     205,   171,   202,   143,   196,   171,   192,   193,   181,   192,
     193,   203,   186,   187,   128,   184,   128,   200,    82,   198,
      84,     7,   128,   186,   187,   208,   205,   210,   202,   200,
     184,   203,   215,   192,   193,   595,   219,   203,   196,   222,
     198,   203,   200,   226,   227,   228,   229,   205,   204,   232,
     233,   234,   203,   203,   196,   196,   203,   203,   203,   494,
     495,   203,   203,   246,   203,   203,  1193,     6,   196,    79,
     250,   251,    82,   203,   203,   203,   203,   203,   258,   514,
       8,   196,   262,   186,   187,   268,   269,   270,   198,   207,
     650,   651,   186,   187,   287,   180,   140,   141,     4,   282,
     283,     6,   140,   141,   186,   187,   196,   192,   193,     6,
       7,   304,   295,   203,   297,   200,   173,   174,   175,   176,
     202,   404,   204,   208,     6,   173,   174,   175,   176,   192,
     193,   173,   174,   175,   176,   192,   193,   186,   187,   574,
     203,   192,   193,   200,   192,   193,   186,   187,   331,   200,
     333,   334,   587,    82,   203,    84,  1688,   338,   173,   174,
     175,   176,   202,   346,     8,   173,   174,   175,   176,   196,
      76,   196,   331,   198,    80,   200,   203,   192,   193,   199,
     205,   202,   202,   204,   192,   193,    92,   173,   174,   175,
     176,   374,   375,   376,   377,   378,   379,   380,   381,   382,
       6,   384,   385,   386,   387,   388,   192,   193,     6,   392,
     393,   394,   395,   396,   407,   398,   375,   196,   377,   378,
     379,   339,   381,   382,   203,   384,   385,   386,   198,   388,
     192,   193,   415,   392,   393,   394,   395,    76,     6,     7,
      79,   203,   197,    82,   199,    84,   331,  1779,   203,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,   186,   187,   195,   186,   187,
     453,   202,   390,   204,   186,   187,   204,   837,   838,   397,
     203,   202,     4,   196,   199,   203,   196,   202,   198,   374,
     375,   376,   377,   378,   379,   205,   381,   382,   196,   384,
     385,   386,   387,   388,   196,   488,   489,   392,   393,   394,
     395,   396,   196,   398,   197,   196,   199,   752,     8,   602,
     203,   501,   502,   186,   187,   188,   189,   190,   196,   509,
     503,   504,   195,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   530,   531,   532,
      99,   195,    76,   197,    86,    79,   186,   187,    82,   542,
     541,   110,    82,   481,   482,   483,   484,   650,   651,   118,
     119,   120,   202,   556,   197,   124,   125,   126,   127,   202,
     563,   103,   104,   105,   106,    82,   567,   186,   187,   203,
     112,   186,   187,   115,   186,   187,  1541,   197,  1543,   196,
    1545,   198,   202,   202,   186,   187,    76,   202,   205,    79,
     202,   594,    82,    79,    84,   975,    82,   977,    84,   979,
     202,   981,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,     6,   615,   616,   617,   618,   619,   620,
     621,    99,    82,    82,   625,   626,   627,   186,   187,   202,
      84,   204,   110,   196,   635,   636,   637,   542,   639,   197,
     118,   119,   120,   202,   202,   646,   124,   125,   126,   127,
     196,   198,   198,   200,   200,    79,   657,   203,   205,   205,
    1607,   907,   203,  1610,   667,   203,  1613,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   197,   186,   187,    79,   195,   202,   690,    79,   692,
     793,    82,   695,    84,   204,   698,    82,   700,   202,   186,
     187,   704,   705,   186,   187,   197,  1671,   186,   187,    79,
     202,    99,  1092,    82,   652,   202,   695,   186,   187,   202,
       4,   700,   110,   202,   197,   728,   204,     4,  1108,   202,
     118,   119,   120,   202,   837,   838,   124,   125,   126,   127,
     186,   187,   845,   846,   186,   187,   749,   186,   187,   186,
     187,   202,   202,   204,   204,   755,   202,   186,   187,    99,
     202,     4,   762,   202,   702,   202,  1713,  1732,   768,  1734,
     110,  1736,   202,   202,   204,     4,   196,  1742,   118,   119,
     120,   186,   187,   196,   124,   125,   126,   127,   103,   104,
     695,   794,   196,   698,   109,   700,   196,   202,   197,   197,
     803,   199,   805,   202,   807,   203,   809,   186,   187,   196,
       6,   814,  1759,     6,   817,  1762,   204,   197,  1765,   199,
    1785,  1768,  1787,   202,  1789,   198,   929,   930,   188,   189,
     190,   198,   835,     6,   197,   195,   199,   196,   841,   202,
     196,  1333,  1334,   846,   197,   197,   199,   199,   196,   202,
     202,   196,   196,  1099,    12,    13,     7,  1804,  1238,  1806,
      99,  1808,   196,   202,   204,   204,   196,   846,   871,   196,
     202,   110,   204,   876,   877,   878,   879,   196,   196,   118,
     119,   120,   202,   196,   204,   124,   125,   126,   127,   892,
     197,   197,   199,   199,   196,   202,   202,   876,   203,   878,
     879,   202,   202,   204,   204,   198,   203,   910,   911,   912,
     913,     6,   203,   892,   915,   202,   196,   204,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   202,    87,
     204,  1034,   935,   196,    92,    93,   196,    95,    96,    97,
       6,   846,   880,   101,   196,   946,   947,   196,   948,   952,
     953,   202,   955,   204,   957,   958,   935,   203,   961,   962,
      82,     4,    84,   966,   202,   204,   204,   202,   202,   204,
     204,   876,   196,   878,   879,   203,   196,   135,   136,   137,
     202,   202,   204,   204,   202,   196,   204,   892,   196,  1092,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   196,
    1000,  1001,  1002,   195,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   202,   202,
     204,   204,   195,   202,  1270,   204,   202,   202,   204,   204,
     935,   202,   196,   204,    99,   202,   202,   204,   204,   202,
       4,   204,     6,   196,  1536,   110,   204,  1050,  1051,  1052,
     196,     4,     5,   118,   119,   120,   203,   198,  1061,   124,
     125,   126,   127,   202,   202,   204,   204,   202,  1069,   204,
     202,   202,   204,   204,   203,  1076,  1077,  1078,  1079,  1080,
     203,   202,   202,   204,   204,  1086,  1087,    40,    41,    42,
      43,    44,    45,   202,   196,   204,    49,    50,    51,    52,
      12,    13,   203,   196,    57,    58,    59,   205,   202,    62,
     204,  1114,   202,   202,   204,   204,   202,   202,   204,   204,
      73,   202,   202,   204,   204,   196,   202,  1499,   204,   202,
    1133,   204,   202,   202,   204,   204,  1139,   196,  1241,   204,
       6,   202,  1145,   204,  1147,  1148,   202,     6,   204,  1152,
    1153,   202,  1155,   204,  1157,   202,  1159,   204,  1161,  1162,
    1163,   202,   198,   204,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   203,    87,  1179,   203,   203,   198,
      92,    93,   198,    95,    96,    97,   198,  1125,     6,   101,
       6,  1194,  1192,   200,   203,  1198,   143,  1200,     6,   205,
       6,     6,     6,   203,     6,   158,   159,   198,     4,  1210,
      99,   195,   200,     7,   203,     7,   169,   204,   171,   172,
    1221,   110,   202,   135,   136,   137,   202,     6,     6,   118,
     119,   120,     6,   203,     7,   124,   125,   126,   127,   192,
     193,     7,   197,     6,     6,  1248,     7,   200,   227,   228,
     229,     7,     6,   232,   233,   234,     6,     6,     4,  1505,
    1363,    54,   140,    54,    54,    54,   203,   199,   197,  1248,
       6,     6,   197,  1276,   197,   202,   202,   197,   202,   197,
     202,   202,   197,  1286,     6,   199,  1289,     4,     4,   268,
     269,     6,   204,     6,     6,  1550,     6,  1297,     6,   143,
       7,     7,     7,   282,   283,     7,   143,  1286,     7,     7,
     143,     7,     7,   203,  1252,   204,     4,     6,   197,   202,
     197,   202,  1325,  1326,  1262,   197,   202,   197,   202,   200,
      12,    13,     6,   200,   199,  1335,   204,  1337,     7,  1339,
    1333,  1334,   204,  1248,     7,   203,   203,    99,   203,   203,
    1353,  1289,  1355,  1353,  1357,     7,  1356,  1357,   110,     6,
     203,     6,     6,     6,   198,     7,   118,   119,   120,  1372,
       6,     6,   124,   125,   126,   127,  1379,   196,   203,   196,
    1383,  1286,     6,   184,  1387,  1386,     7,     7,     7,     6,
      84,  1329,     7,     7,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,  1407,    87,     7,     7,     6,     6,
      92,    93,     7,    95,    96,    97,     7,  1672,     7,   101,
       7,     7,     7,     4,     4,  1428,   203,     6,   196,     6,
     202,     7,     6,   203,    12,    13,     7,     7,     7,     6,
    1378,     6,     6,    82,     6,     6,     4,     4,     4,  1387,
    1388,  1389,   204,   135,   136,   137,   204,     6,     6,     6,
       6,  1464,     4,     6,   197,   197,  1469,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   202,   200,   197,     7,   195,  1489,     6,   197,   200,
       6,     6,   196,  1496,     6,     6,  1499,     6,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    92,    87,
     203,  1514,   203,   203,    92,    93,   203,    95,    96,    97,
     203,     6,   204,   101,   203,     6,     6,  1530,     5,     4,
    1533,   203,     6,   203,     7,   203,    12,    13,   203,   198,
    1540,     6,  1542,  1536,  1544,     6,  1549,     6,     6,   203,
     203,  1554,  1552,   203,     6,  1555,     4,   135,   136,   137,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     6,     6,   139,     6,   195,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,  1596,  1499,  1595,   202,   195,     6,  1599,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,    87,  1615,     6,     4,     6,    92,    93,     6,    95,
      96,    97,     6,    12,    13,   101,   204,     6,     6,     4,
       6,   203,     6,     6,     6,     5,    88,     6,     6,   143,
       6,     6,     6,     6,     6,     6,     6,     6,  1648,     6,
       6,   202,  1652,     6,     6,     6,     6,     6,   197,   135,
     136,   137,     6,   200,     7,     6,     6,   203,    80,     6,
    1673,     5,  1675,     6,   203,  1675,     6,   203,     6,   204,
     204,   203,   203,   203,     7,  1688,   203,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,  1635,    87,     6,
     138,     6,   204,    92,    93,     6,    95,    96,    97,     6,
       6,   141,   101,     6,     6,     6,     6,     6,     6,   203,
       6,     6,   174,   175,   176,   177,   178,     6,   204,     6,
    1730,  1731,   203,   203,   203,   203,     6,   204,     6,   191,
     203,  1744,     6,   195,    99,     6,   135,   136,   137,  1752,
       6,     6,     6,     6,     6,     6,     6,   209,   210,   211,
     212,    99,   214,   215,   216,   217,     6,   219,   220,   221,
     204,     6,   110,  1752,   226,   203,  1779,   203,   203,     6,
     118,   119,   120,   203,     6,  1723,   124,   125,   126,   127,
       6,     6,   244,  1796,     6,  1798,     6,   203,     6,   203,
     203,   253,   254,   203,   203,    12,    13,     6,     6,     6,
     262,     6,     6,     6,     6,   204,     6,  1796,     6,  1798,
       6,     6,     6,     6,  1122,  1828,  1638,   449,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,  1519,   295,   296,   297,   195,  1752,  1520,  1828,
    1132,     3,     3,   479,  1532,   307,   308,   309,  1266,   311,
      -1,    -1,   314,   315,   316,    -1,   204,   319,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    -1,    -1,   335,   336,    92,    93,    -1,    95,    96,
      97,  1796,    -1,  1798,   101,    -1,    -1,   349,   350,    -1,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,    -1,  1828,    -1,    -1,    -1,    -1,   135,   136,
     137,   383,    -1,    -1,    -1,    -1,    -1,   389,    -1,   391,
      -1,   210,    -1,    -1,     6,    -1,   215,    -1,    -1,    -1,
     219,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,    -1,
     412,    -1,    -1,   415,    -1,    -1,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,    -1,    -1,   435,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,   204,    -1,    -1,
      -1,   453,    -1,    -1,    -1,   110,    -1,   459,    -1,    -1,
      -1,    -1,   464,   118,   119,   120,    -1,   469,   470,   124,
     125,   126,   127,   475,   476,    -1,    -1,    -1,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
      -1,    -1,    -1,   195,   506,   507,   508,   509,   510,   511,
      -1,    -1,    -1,   515,   516,   517,   518,   519,    -1,    -1,
      -1,   523,    -1,   525,   526,    -1,    -1,    -1,   530,   531,
     532,    99,    -1,   535,   536,   537,   538,   539,    -1,    -1,
      -1,    -1,   110,   545,    -1,    -1,    -1,    -1,    -1,   204,
     118,   119,   120,    -1,   556,    -1,   124,   125,   126,   127,
     562,   563,    -1,   565,   566,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    99,
      -1,    -1,    -1,   195,   586,    -1,    -1,    -1,    -1,    -1,
     110,   593,   594,    -1,    -1,    -1,   415,   599,   118,   119,
     120,    -1,     3,     4,   124,   125,   126,   127,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,   653,    53,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,   488,
     489,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   687,    -1,    -1,   690,    -1,
     692,   693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   701,
      -1,    -1,   704,   705,    -1,    -1,    -1,    -1,    99,    -1,
      -1,   530,   531,   532,    -1,    -1,   718,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   727,    -1,   118,   119,   120,
      -1,    -1,    -1,   124,   125,   126,   127,   556,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   749,    -1,    -1,
      -1,    -1,    -1,    -1,   756,   757,   157,    -1,    -1,   160,
     762,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,    -1,    -1,   775,    -1,   594,   778,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,   794,   222,    -1,   196,    -1,    -1,    -1,    -1,
     201,   803,   203,   805,    -1,   807,    -1,   809,    -1,    -1,
      -1,    -1,   814,   204,    -1,   817,    -1,   246,    -1,    -1,
      -1,   823,    -1,   825,   826,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,    -1,
       6,   270,    -1,   195,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,   859,    -1,    -1,
     195,    -1,    -1,    99,    -1,   867,   868,   869,    -1,   871,
      -1,   690,    -1,   692,   110,    -1,    -1,    12,    13,    -1,
      -1,    -1,   118,   119,   120,    -1,    -1,   889,   124,   125,
     126,   127,    -1,    -1,    -1,   897,    -1,    -1,   900,    -1,
      -1,     6,    -1,    -1,   333,   334,    -1,    -1,   910,   911,
     912,   913,    -1,    -1,    -1,   917,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   380,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    96,    97,    -1,   966,    -1,   101,    -1,   204,    -1,
      -1,    -1,    -1,    -1,   976,   794,   978,    -1,   980,    -1,
     982,    -1,    -1,    -1,   803,    -1,   805,    -1,   807,    -1,
     809,    -1,    -1,    -1,    -1,   814,    -1,    -1,   817,    -1,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,  1030,   195,
      -1,  1033,    -1,    -1,    -1,  1037,    -1,  1039,  1040,  1041,
      -1,    -1,    -1,    -1,    -1,  1047,    -1,    -1,    -1,    -1,
      -1,    -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1064,    -1,  1066,    -1,    -1,    -1,     6,   204,
      12,    13,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,   910,   911,   912,   913,    -1,    -1,    -1,  1100,   210,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,
    1112,  1113,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,  1124,  1125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    -1,   966,    12,    13,
      92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1169,  1170,  1171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,  1181,
      -1,    -1,    -1,    -1,   295,    -1,   297,    -1,    -1,    -1,
    1192,    -1,    -1,   135,   136,   137,    -1,    -1,  1200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,  1226,  1227,  1228,    -1,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,   667,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     6,    -1,    -1,    -1,   195,    -1,    -1,
      -1,  1263,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,  1277,    -1,    -1,    -1,    -1,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1295,  1296,    -1,    -1,    -1,    -1,   728,
    1302,  1303,    -1,    -1,   415,  1307,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1325,  1326,  1327,    -1,  1329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1341,
     204,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1353,    -1,    -1,    -1,  1357,    -1,    -1,  1360,    -1,
      -1,    -1,    -1,  1365,  1366,  1367,  1368,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1378,   488,   489,    -1,
      -1,  1200,    -1,    -1,    -1,    -1,  1388,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1405,  1406,    -1,   835,    -1,    -1,    -1,
      -1,  1413,   841,    -1,    -1,    -1,    -1,    -1,    -1,   530,
     531,   532,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     8,    -1,
      -1,    -1,   195,    -1,    -1,   556,    -1,  1449,   877,    -1,
      -1,    -1,   563,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,  1467,    87,  1469,    -1,    -1,
      -1,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,    -1,  1484,   594,  1486,    -1,    -1,  1489,    -1,    -1,
      -1,    -1,    -1,    -1,  1496,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1325,  1326,  1510,    -1,
      -1,    -1,    -1,  1515,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,    -1,   952,   953,    -1,   955,    -1,   957,   958,
      -1,  1533,   961,   962,    -1,    -1,    -1,    -1,  1540,    -1,
    1542,    -1,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1554,    -1,    -1,    -1,  1558,  1559,  1560,  1561,
    1562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1577,  1578,    -1,    -1,   690,
    1582,   692,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
    1592,    -1,    -1,   704,   705,    -1,    -1,    -1,    -1,    -1,
      -1,  1603,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,  1050,  1051,  1052,    -1,   195,    -1,    -1,    -1,    -1,
      -1,  1633,  1061,     6,    -1,    -1,  1638,    -1,   749,    -1,
      -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,  1659,    -1,    -1,
    1662,    -1,    -1,  1665,    -1,    -1,    -1,  1669,    -1,    -1,
    1489,  1673,    -1,  1675,  1676,  1677,  1678,  1679,    -1,    -1,
      -1,    -1,    -1,   794,  1686,  1114,    -1,  1689,    -1,    -1,
      -1,    -1,   803,    -1,   805,    -1,   807,    -1,   809,    -1,
      -1,    -1,    -1,   814,  1133,    -1,   817,    -1,    -1,    -1,
    1139,    -1,    -1,    -1,  1533,    -1,  1145,    -1,  1147,  1148,
      -1,    -1,    -1,  1152,  1153,    -1,  1155,  1729,  1157,    -1,
    1159,    -1,  1161,  1162,  1163,  1554,    -1,    -1,    -1,    -1,
      -1,    -1,  1744,    -1,  1746,  1747,  1748,  1749,    -1,    -1,
    1179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     871,    -1,    -1,    -1,    -1,  1194,    -1,    -1,    -1,  1198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1782,  1783,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
    1792,  1793,  1794,  1795,    -1,    -1,    -1,    -1,    -1,   910,
     911,   912,   913,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,    -1,    -1,
      -1,    -1,   195,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,
      -1,    -1,    -1,    -1,  1673,   966,  1675,    -1,    -1,    -1,
    1289,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     6,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,  1744,  1355,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1372,     5,    -1,    -1,    -1,    -1,    -1,
    1379,    -1,    -1,    -1,  1383,    -1,    -1,    -1,  1387,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,  1407,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    57,    58,    59,  1428,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    73,    -1,    -1,   157,   158,   159,   160,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,    -1,   171,
     172,    -1,    -1,    -1,    -1,  1464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
      -1,   203,    -1,   205,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,  1514,    -1,    -1,    -1,  1200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,  1530,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,     6,    -1,     3,     4,    -1,    -1,
    1549,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    53,  1596,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    12,    13,    72,  1615,    -1,    -1,    76,
      -1,     7,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,  1325,  1326,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1353,    -1,    -1,    -1,  1357,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,  1688,
      -1,    -1,    -1,    92,    93,    -1,    95,    96,    97,    -1,
     157,    -1,   101,   160,    -1,    -1,    -1,   164,   165,   166,
     167,   168,    -1,    -1,   171,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   186,
     187,    -1,    -1,   195,   191,    -1,   135,   136,   137,   196,
      -1,    -1,    -1,    -1,   201,    -1,   203,   204,    -1,     8,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,     8,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1469,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     3,     4,    -1,  1489,   195,
      -1,     9,    10,    11,    -1,  1496,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,  1533,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,  1554,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,    -1,    -1,    -1,     8,   195,    -1,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,
     168,    -1,    -1,   171,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,  1673,   191,  1675,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,   204,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,  1744,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     8,    -1,    -1,
      -1,   195,    -1,    -1,   157,   158,   159,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,     3,     4,     5,   201,    -1,
     203,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   157,
     158,   159,   160,   195,    -1,    -1,   164,   165,   166,   167,
     168,   169,   204,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
       3,     4,     5,   201,    -1,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,     3,     4,     5,    -1,    72,
      73,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   157,   158,   159,   160,   195,    -1,
      -1,   164,   165,   166,   167,   168,   169,   204,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    -1,
     203,    -1,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   157,
     158,   159,   160,   195,    -1,    -1,   164,   165,   166,   167,
     168,   169,   204,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
       3,     4,     5,   201,    99,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,   169,    -1,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,     3,     4,     5,   201,    -1,
     203,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,   169,    -1,   171,   172,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,
     168,    -1,    -1,   171,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   186,   187,
      -1,    -1,   195,   191,   197,    -1,    -1,    -1,   196,   202,
       3,     4,     5,   201,    -1,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,   169,    -1,   171,   172,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,    -1,    -1,   171,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,    -1,    -1,   195,   191,    -1,
      -1,    -1,    -1,   196,   202,     3,     4,    -1,   201,    -1,
     203,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,   169,    -1,    -1,
     172,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,
     168,    -1,    -1,   171,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   186,   187,
      -1,    -1,   195,   191,    -1,    -1,    -1,    -1,   196,   202,
       3,     4,    -1,   201,    -1,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,    -1,    -1,   171,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,    -1,    -1,   195,   191,    -1,
      -1,    -1,    -1,   196,   202,     3,     4,    -1,   201,    -1,
     203,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
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
      -1,    -1,    -1,   202,    -1,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,   160,    -1,    -1,    -1,   164,   165,   166,   167,
     168,    -1,    -1,   171,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   186,   187,
      -1,    -1,   195,   191,    -1,    -1,    -1,    -1,   196,   202,
       3,     4,    -1,   201,    -1,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
      -1,   164,   165,   166,   167,   168,    -1,    -1,   171,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,    -1,    -1,   195,   191,    -1,
      -1,    -1,    -1,   196,   202,     3,     4,    -1,   201,    -1,
     203,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
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
      -1,    -1,   195,   191,    -1,    -1,    -1,    -1,   196,   202,
       3,     4,    -1,   201,    -1,   203,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,     3,     4,     5,    -1,    -1,    72,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   157,    -1,    -1,   160,   195,    -1,
      -1,   164,   165,   166,   167,   168,    -1,   204,   171,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   186,   187,    -1,    -1,   195,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   204,    -1,   201,    -1,
     203,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   157,   158,
     159,   160,   195,    -1,    -1,   164,   165,   166,   167,   168,
     169,   204,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,    -1,
      -1,    -1,   191,     3,     4,    -1,    -1,   196,    -1,     9,
      10,    11,   201,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    82,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,
      -1,   171,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   186,   187,    -1,    -1,
     195,   191,     3,     4,    -1,    -1,   196,   202,     9,    10,
      11,   201,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,   164,   165,   166,   167,   168,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,    -1,    -1,    -1,
     191,    -1,    54,    55,    56,   196,    -1,    -1,    60,    61,
     201,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,     4,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      12,    13,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    38,    39,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   177,   178,   179,
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
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,   177,   178,   179,   180,   181,   182,
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
      -1,   195,    -1,    -1,    -1,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   199,   177,
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
     190,    -1,    -1,    -1,    -1,   195
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
       4,   203,   295,     4,   196,   196,   196,     6,     6,   198,
       4,   299,   303,     4,   299,     5,   203,     5,   203,     4,
     285,   198,     6,   196,   203,   196,   198,   205,   230,     7,
     173,   174,   175,   176,   192,   193,   228,   229,     4,   196,
     198,   200,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   196,   196,   196,
     196,   196,   196,   230,   230,   230,   230,   196,   230,   230,
     230,     7,   196,   196,   196,   230,   196,   196,   198,   285,
     285,   285,   285,   285,     4,   140,   141,   303,     4,   250,
     251,   252,   203,   197,   199,   203,   231,     6,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   195,   203,     6,   196,   198,   229,     6,   285,
       4,   298,   299,   303,   298,   285,   298,   301,   234,   237,
     299,   303,   285,   187,   285,   293,   294,   285,   285,   196,
     285,   294,   285,   285,   196,   294,   285,   285,   291,   196,
     203,   294,   292,   292,   292,   196,   196,   292,   292,   292,
     196,   196,   196,   196,   196,   196,   196,   196,   203,   203,
     285,     4,   291,   295,   203,   203,   288,   288,   288,   285,
     285,   186,   187,   203,   203,   288,   203,   203,   203,   186,
     187,   196,   252,   288,   203,   196,   203,   196,   196,   196,
     292,   292,   291,   196,     4,   198,   198,   252,     6,     6,
     203,   203,   203,   292,   292,   198,   198,   198,   196,   198,
     200,   230,   198,     5,   143,   203,     5,   143,     5,   143,
       5,   143,    76,    79,    82,    84,   203,   285,   293,   285,
     204,   294,     8,   188,     6,   196,   198,   230,     6,   285,
     285,   285,   200,   285,   203,   143,   285,   285,   285,   285,
       6,     6,     6,   252,     6,   252,   198,   203,   298,   291,
     291,   285,   285,   203,   203,   231,   299,   291,     6,   198,
     285,   285,     4,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   301,   298,   301,   298,   298,
     298,   291,   298,   298,   285,   298,   298,   298,   301,   298,
     285,   299,   285,   298,   298,   298,   298,   303,   299,   303,
     197,   199,     7,   228,   229,   200,     7,   230,   204,    76,
      79,    82,    84,   249,   285,   294,     7,   228,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   213,   285,   285,     6,   198,   200,   197,
     202,   197,   202,   202,   197,   202,   199,   202,   233,   199,
     233,   202,   202,   197,   188,   202,   204,   197,   197,   285,
     197,   204,   197,   197,   285,   204,   197,   197,     7,   285,
     285,   204,     6,     6,     6,   285,   285,     7,     7,   278,
     278,   285,   243,   285,   299,   244,   285,   299,   245,   285,
     299,   246,   285,   299,   285,   285,   285,   294,   294,   203,
     197,     6,   203,   252,   252,   202,   202,   202,   288,   288,
     251,   251,   202,   285,   285,   285,   285,   264,   202,   252,
     285,   285,   285,   285,   285,     7,   279,     6,     7,   285,
       6,   285,   285,   204,   294,   294,   294,     6,     6,   285,
     285,   285,   285,     4,   203,   231,   303,    54,   285,    54,
      54,    54,     5,   203,     5,   203,     5,   203,     5,   203,
     294,   197,   204,   285,   203,   285,   293,   203,   231,   197,
     197,   197,   140,   202,   252,   203,     8,   197,   197,   199,
     204,   204,   252,   199,   197,   202,   204,   197,   199,   285,
     294,   228,     6,     6,   285,   197,   199,   229,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   202,
     231,   231,   231,   231,   231,   231,   231,   202,   202,   202,
     231,   202,   231,   231,   197,   197,   202,   202,   202,   202,
     202,   231,   231,   231,   197,   231,   287,   300,     6,   202,
     197,   197,   202,   231,   197,   197,   199,   228,   229,   200,
     228,   229,   299,   285,     6,     4,     4,   203,   296,   231,
     203,   203,   203,   203,   204,   204,   291,     8,     4,   130,
     131,   132,   133,   204,   216,   220,   223,   225,   226,   197,
     199,   285,     4,     6,   184,   210,   294,     6,   294,   285,
       6,   298,     6,   303,     6,   298,   285,   299,     7,   285,
     293,   143,     7,     7,   197,     7,   143,     7,     7,   197,
     143,     7,     7,   285,   197,   204,   203,   197,   197,   285,
     291,     4,   277,     6,   197,   197,   202,   197,   202,   197,
     202,   197,   202,   197,   197,   197,   204,   204,   294,   200,
     252,   204,   204,   288,   285,   285,   204,   204,   285,   288,
     202,   202,   202,    99,   110,   118,   119,   120,   124,   125,
     126,   127,   274,   275,   288,   204,   261,   197,   204,   197,
     197,   197,   285,     6,   285,   197,   199,   199,   204,   204,
     204,   199,   199,   202,   199,   294,   199,   203,   204,   203,
     203,   203,   294,   294,   294,   294,   204,     8,   294,   294,
       7,     7,     7,   200,   285,   204,   285,   285,     7,   200,
     204,   203,   291,     6,   228,   229,   228,   229,   204,   204,
     291,   199,   229,   200,   229,   298,   285,   285,   285,   285,
     294,   298,   291,   298,   298,   299,   239,   241,   285,   298,
     285,     6,     4,   140,   141,   285,     6,     6,     6,     7,
     198,   295,   297,     6,   294,   294,   294,   294,   231,     6,
     285,   217,   196,   196,   203,   227,     6,   229,   229,   199,
     184,   298,   197,   197,   202,     7,   231,   231,   288,    82,
      84,   291,   291,     7,   291,    82,    84,   291,   291,     7,
      84,   291,   291,     6,     7,     7,   294,     7,     7,    99,
     276,     6,     7,   228,   285,   228,   285,   228,   285,   228,
     285,     7,     7,     7,     7,     7,   204,     4,   204,   202,
     202,   202,   204,   204,   288,   288,   288,     4,     6,   203,
       6,   196,     6,   128,     6,   128,     6,   128,     6,   128,
     204,   275,   202,   274,     7,     6,     7,     7,     7,     6,
     203,     6,     6,     6,    82,   285,     6,     6,   285,   200,
     204,   285,   285,   285,   285,   204,   204,   204,   204,   285,
     204,   204,   291,   291,   291,     4,   202,     8,     8,   197,
       4,     4,   291,   204,   285,     6,   285,     6,   231,     6,
       6,     4,     6,   231,   231,   231,   231,   231,   202,   197,
     197,   197,   202,   202,   231,   240,   202,   231,   242,   197,
     197,     6,     7,   228,   229,   200,     7,     6,   295,   285,
     202,   204,   204,   204,   204,   204,   228,   196,   285,   285,
     290,   291,   203,   200,     6,     6,   210,     6,   285,   203,
     285,   299,     6,     6,     6,   203,   203,    92,   248,   248,
     291,     6,   203,   203,     6,     6,   291,   203,     6,     6,
       5,   291,   204,   291,   291,     4,     6,   291,   291,   291,
     291,   291,   291,   291,   291,   203,   203,     7,     6,     7,
     285,   285,   285,   203,   203,   202,   204,   202,   204,   202,
     204,   198,   285,   291,   285,     6,     6,     6,     6,   285,
     288,   204,     5,   203,   291,   203,   203,   203,   291,   294,
     203,     6,   199,     4,   231,   202,   202,   202,   202,   231,
       6,     6,   139,   285,   285,   285,     6,     6,     7,   202,
       6,     6,     6,   228,   229,   298,   299,     4,     4,   154,
     299,   285,     6,     4,   296,     6,   199,   295,     6,     6,
       6,     6,   291,   214,   285,   202,   202,   202,   204,   215,
     285,     4,   298,   202,   291,   299,   285,   285,   288,     6,
       6,     6,   285,   285,     6,   285,     5,     6,   203,     6,
     143,   247,   285,     6,     6,     6,     6,     6,     6,     4,
       6,     6,   294,   294,   285,   285,   299,   204,   197,   202,
     204,   251,   251,   288,     6,   265,   288,     6,   266,   288,
       6,   267,   285,   204,   202,   197,   204,   202,     6,   187,
     288,     6,   290,   288,   288,     6,   204,   285,     6,   285,
     285,   285,   285,   291,   202,   204,     8,   204,   197,   203,
     285,   299,   291,   291,   197,   231,   203,   291,   299,   203,
     285,   299,   299,     6,     6,     7,     6,   200,     6,   197,
     202,   285,   285,   291,   203,   202,   204,     6,   285,   235,
     236,   204,   204,   204,   204,   204,     5,   290,    80,     6,
     203,   204,   204,   203,     6,     6,   203,   285,   204,   204,
     202,   203,   202,   203,   202,   203,   199,     6,   291,     7,
     203,   285,   202,   204,   202,   202,     6,   204,   202,   202,
     202,   202,   138,   285,   285,   294,     6,     6,   204,     6,
     238,   285,   301,   295,   141,   218,   285,   202,   202,   290,
     285,     6,   202,   239,   241,     6,     6,     6,     6,     6,
       6,   204,   203,   290,   103,   104,   109,   280,   103,   104,
     280,   294,   251,   202,   204,   285,   288,   274,   285,   288,
     274,   285,   288,   274,     6,   202,   204,   291,   252,   204,
     288,     6,   294,   288,   285,   285,   285,   285,   285,   204,
     204,   204,     6,   202,   204,     7,   204,     6,   203,   285,
     285,   204,   285,   204,   204,   203,   285,   204,   203,   288,
     291,     6,   203,   288,     6,   204,   204,   285,   204,   202,
     204,   204,   202,   204,   204,   202,   204,   291,     6,    99,
     204,   262,   203,   202,   204,   202,   202,   202,   202,   202,
       6,     6,   285,   299,   215,   197,   202,     6,   203,   202,
     285,   204,     6,   288,     6,   288,     6,     6,   204,     6,
     268,   285,     6,     6,   269,   285,     6,     6,   270,   285,
       6,   204,   285,   274,   252,   294,     6,   288,   294,   285,
     285,   285,   285,     7,   204,   221,   285,   290,   285,   202,
     202,   202,   203,   204,   203,   204,   203,   204,     6,     6,
     204,   204,   263,   204,   202,   204,   202,   202,   202,   202,
     299,     6,   203,   197,   204,   204,   285,   288,   288,   274,
       6,   271,   274,     6,   272,   274,     6,   273,   274,     6,
     294,     6,   285,   285,   285,   285,   219,   298,   224,   203,
       6,   204,   202,   202,   204,   203,   204,   203,   204,   203,
     204,   204,   202,   202,   202,   202,   202,   204,   203,   290,
       6,   285,   285,     6,   274,     6,   274,     6,   274,     6,
     285,   285,   285,   285,   298,     6,   222,   298,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   202,   204,
       6,     6,     6,     6,     6,     6,   298,     6
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
       0,     2,     0,     2,     7,     6,     8,     5,     3,     7,
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
#line 4338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4416 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 232 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 239 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 244 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4468 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4486 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4503 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4520 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4547 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4565 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4582 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4599 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 375 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 389 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 391 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 398 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4652 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4760 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4774 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 517 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 526 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 533 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4806 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4819 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 552 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 561 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 568 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4851 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4863 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 586 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4873 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4893 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 634 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 640 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4930 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 655 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4966 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4978 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4984 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4990 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4996 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 672 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 677 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5015 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5079 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5112 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 801 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 806 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 811 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 816 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 821 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5192 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 828 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5203 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 855 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 860 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 865 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 870 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 879 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 885 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5288 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5310 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5332 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5345 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 951 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 956 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5376 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5400 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5424 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5439 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5451 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5477 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5504 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5534 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5556 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5572 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5588 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5601 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1166 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5620 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5640 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1193 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5659 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1209 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1217 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1223 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5702 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5717 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5735 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1277 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5758 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1294 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5781 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5816 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1330 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5825 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1342 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1348 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5860 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5887 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1378 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1384 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5906 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1392 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5914 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1412 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5944 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5971 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6007 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6031 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6053 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6078 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6100 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6134 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6168 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6190 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6212 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6242 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6264 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6286 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6322 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6344 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1808 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1814 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1820 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6418 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6447 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6476 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6497 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6520 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6557 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6593 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6615 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6636 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6656 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2071 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2076 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2081 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2086 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2091 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6764 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2119 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6774 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2135 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6792 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2136 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2145 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6814 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6841 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6868 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6895 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6922 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6947 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6977 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7001 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7026 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7050 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7166 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7189 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7231 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7338 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2643 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7361 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7380 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7412 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7428 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7441 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7454 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2746 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2752 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7487 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7500 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7513 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7526 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7539 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7602 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7624 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7645 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7664 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7694 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7710 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2970 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2974 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7755 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2979 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2986 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2991 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2997 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3002 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7804 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7816 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3016 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3020 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3024 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7841 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7899 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7920 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7941 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7967 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7993 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8032 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8044 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3218 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3231 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8088 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8112 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8142 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3296 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8168 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8180 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8192 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3332 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8214 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3346 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8236 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8258 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3374 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3395 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3402 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3409 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3416 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3423 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3430 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3437 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3444 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3451 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3457 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3464 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3470 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3477 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3483 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3490 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3496 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8474 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3503 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3516 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3522 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3529 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3535 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3542 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8547 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3548 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3555 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3561 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3572 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3575 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8593 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8609 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8633 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8660 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3637 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3641 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3645 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3653 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3659 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3665 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3669 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3673 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8744 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8767 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3712 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8787 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3731 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8812 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3751 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3755 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3760 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3764 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3770 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8870 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3774 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8878 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8938 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3907 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9021 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9092 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9132 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 4015 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9144 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9191 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9234 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9258 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9293 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9323 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9352 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9381 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9410 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9439 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9464 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9496 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4366 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9536 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4370 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9544 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9576 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9619 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9662 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9687 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9712 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4549 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9745 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9759 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4597 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4598 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4599 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9821 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9837 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9859 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4670 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4671 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4672 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4673 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4676 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4683 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4684 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4685 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9969 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4686 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4687 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4688 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4689 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4690 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4691 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4692 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10011 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4693 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4694 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4695 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4696 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4697 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4698 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4699 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4700 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4701 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4702 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10071 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4703 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4704 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4705 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4706 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4707 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4708 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4709 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4710 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4711 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4712 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10131 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4713 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4714 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10143 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4723 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4724 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4725 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4726 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4727 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4728 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10179 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4729 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10185 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4730 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4731 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4732 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10203 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4733 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4740 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10225 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4746 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10234 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10255 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10277 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10299 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10321 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4840 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4845 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10362 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10378 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10399 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10421 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10443 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10465 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4955 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4960 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10505 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10519 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10542 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10557 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10570 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5010 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10579 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5042 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10615 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10623 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5050 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5054 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5058 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5065 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5073 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5077 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5084 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10688 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5089 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5096 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5105 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5110 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10730 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10742 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5133 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10762 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10775 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10787 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5165 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10810 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10824 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5211 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10865 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5215 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5219 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10881 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5223 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5227 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5231 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5235 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5239 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10921 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10954 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10987 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11020 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11053 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11085 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11117 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11131 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11145 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11161 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11177 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11193 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11215 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5507 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11246 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5512 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5516 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11262 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5532 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11283 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5536 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5548 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5555 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5565 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5569 "Gmsh.y" /* yacc.c:1646  */
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
#line 11337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5584 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5589 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5596 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5600 "Gmsh.y" /* yacc.c:1646  */
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
#line 11379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5613 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5621 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5632 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5636 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5640 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5648 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5654 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5660 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5668 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5676 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5683 "Gmsh.y" /* yacc.c:1646  */
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
#line 11505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5698 "Gmsh.y" /* yacc.c:1646  */
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
#line 11523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5712 "Gmsh.y" /* yacc.c:1646  */
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
#line 11541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5726 "Gmsh.y" /* yacc.c:1646  */
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
#line 11557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5738 "Gmsh.y" /* yacc.c:1646  */
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
#line 11577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5754 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11590 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5763 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5772 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5782 "Gmsh.y" /* yacc.c:1646  */
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
#line 11632 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5793 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5797 "Gmsh.y" /* yacc.c:1646  */
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
#line 11663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5816 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5823 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5829 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5831 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5842 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5847 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5853 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5862 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5875 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5878 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5882 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11763 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5885 "Gmsh.y" /* yacc.c:1906  */


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
