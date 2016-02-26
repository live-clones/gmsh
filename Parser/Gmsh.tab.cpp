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
#define YYLAST   11463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  540
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1933

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
     670,   671,   672,   677,   683,   745,   762,   791,   820,   825,
     830,   835,   840,   847,   857,   886,   915,   920,   925,   930,
     938,   947,   953,   959,   972,   985,  1000,  1017,  1023,  1029,
    1042,  1055,  1070,  1087,  1093,  1102,  1120,  1138,  1147,  1159,
    1164,  1172,  1192,  1215,  1226,  1234,  1256,  1279,  1305,  1326,
    1338,  1352,  1352,  1354,  1356,  1365,  1375,  1374,  1392,  1402,
    1401,  1415,  1417,  1425,  1431,  1438,  1439,  1443,  1454,  1469,
    1479,  1480,  1485,  1493,  1502,  1510,  1528,  1532,  1538,  1546,
    1550,  1556,  1564,  1568,  1574,  1582,  1586,  1592,  1601,  1604,
    1617,  1620,  1630,  1653,  1693,  1716,  1734,  1755,  1773,  1803,
    1833,  1851,  1869,  1896,  1914,  1932,  1975,  1993,  2032,  2038,
    2044,  2051,  2076,  2101,  2118,  2137,  2171,  2215,  2233,  2250,
    2266,  2311,  2316,  2321,  2326,  2331,  2336,  2359,  2365,  2376,
    2377,  2382,  2385,  2389,  2412,  2435,  2458,  2486,  2507,  2533,
    2554,  2576,  2596,  2708,  2727,  2765,  2874,  2883,  2889,  2904,
    2932,  2949,  2958,  2972,  2986,  2992,  2998,  3007,  3016,  3025,
    3039,  3098,  3116,  3133,  3148,  3174,  3186,  3210,  3214,  3219,
    3226,  3231,  3237,  3242,  3248,  3256,  3260,  3264,  3269,  3329,
    3346,  3363,  3385,  3407,  3442,  3450,  3458,  3464,  3471,  3478,
    3498,  3524,  3536,  3548,  3556,  3564,  3573,  3572,  3587,  3586,
    3601,  3600,  3615,  3614,  3628,  3635,  3642,  3649,  3656,  3663,
    3670,  3677,  3684,  3692,  3691,  3705,  3704,  3718,  3717,  3731,
    3730,  3744,  3743,  3757,  3756,  3770,  3769,  3783,  3782,  3796,
    3795,  3812,  3815,  3821,  3833,  3853,  3877,  3881,  3885,  3889,
    3893,  3899,  3905,  3909,  3913,  3917,  3921,  3940,  3953,  3956,
    3972,  3975,  3992,  3995,  4001,  4004,  4011,  4014,  4021,  4077,
    4147,  4152,  4219,  4255,  4263,  4306,  4345,  4365,  4397,  4424,
    4450,  4476,  4502,  4528,  4550,  4578,  4606,  4610,  4614,  4642,
    4681,  4720,  4741,  4762,  4789,  4793,  4803,  4838,  4839,  4840,
    4844,  4850,  4862,  4880,  4908,  4909,  4910,  4911,  4912,  4913,
    4914,  4915,  4916,  4923,  4924,  4925,  4926,  4927,  4928,  4929,
    4930,  4931,  4932,  4933,  4934,  4935,  4936,  4937,  4938,  4939,
    4940,  4941,  4942,  4943,  4944,  4945,  4946,  4947,  4948,  4949,
    4950,  4951,  4952,  4953,  4954,  4955,  4964,  4965,  4966,  4967,
    4968,  4969,  4970,  4971,  4972,  4973,  4974,  4979,  4978,  4986,
    4991,  4996,  5013,  5031,  5049,  5067,  5085,  5090,  5096,  5111,
    5128,  5146,  5164,  5182,  5203,  5208,  5213,  5223,  5233,  5238,
    5249,  5258,  5263,  5290,  5294,  5298,  5302,  5306,  5313,  5317,
    5321,  5325,  5332,  5337,  5344,  5349,  5353,  5358,  5362,  5370,
    5381,  5385,  5397,  5405,  5413,  5420,  5430,  5459,  5463,  5467,
    5471,  5475,  5479,  5483,  5487,  5491,  5520,  5549,  5578,  5607,
    5620,  5633,  5646,  5659,  5669,  5679,  5691,  5704,  5716,  5734,
    5755,  5760,  5764,  5768,  5780,  5784,  5796,  5813,  5823,  5827,
    5842,  5847,  5854,  5858,  5871,  5885,  5888,  5891,  5894,  5902,
    5913,  5917,  5921,  5929,  5935,  5941,  5949,  5957,  5964,  5972,
    5987,  6001,  6015,  6027,  6043,  6052,  6061,  6071,  6082,  6086,
    6105,  6112,  6119,  6118,  6131,  6136,  6142,  6151,  6164,  6167,
    6171
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

#define YYPACT_NINF -1418

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1418)))

#define YYTABLE_NINF -510

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7880,    79,   105,  8000, -1418, -1418,  3646,    20,    71,   -79,
     -68,    31,   157,   173,   188,   242,    68,   263,   269,    95,
     106,  -124,  -124,  -101,   147,   186,     5,   192,   240,    14,
     291,   295,   417,   330,   370,   501,   309,   -16,   486,   508,
     380,   529,   794,   581,   -35,   419,   540,   -42,   423,   163,
     163,   434,   203,    55,   202,   579,   607,     8,    44,   615,
     609,   -21,   694,   702,   718,  5225,   760,   547,   554,   587,
      11,     0, -1418,   599,   621, -1418, -1418,   767,   816,   629,
   -1418,  3152,  5497,    33,    34, -1418, -1418, -1418,  7740,   656,
   -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418,
   -1418, -1418, -1418, -1418, -1418, -1418,    19, -1418,   -51,   125,
   -1418,     4, -1418, -1418, -1418, -1418, -1418,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   636,   671,   689,   699,   711,   719,  -124,  -124,
    -124,  -124,   720, -1418,  -124, -1418, -1418, -1418, -1418, -1418,
    -124,  -124,   872,   724,   725,   728,  -124,  -124,   729,   737,
   -1418, -1418, -1418, -1418,   698,  7740,  7740,  7740,  7232,  7291,
      17,     3,   415,   766,   812,  1131, -1418,   820,   945,   553,
     155,   972,  7740,  5322,  5322, -1418,  7740, -1418, -1418, -1418,
   -1418,  5322, -1418, -1418, -1418, -1418, -1418, -1418,  5693,     3,
    7740,  7042,  7740,  7740,   828,  7740,  7042,  7740,  7740,   831,
    7042,  7740,  7740,  5617,   833,   837, -1418,  7042,  5225,  5225,
    5225,   847,   884,  5225,  5225,  5225,   893,   902,   928,   929,
     931,   935,   936,   948,   946,  6597,  1048,  5617,    11,   947,
     988,   163,   163,   163,  7740,  7740,  -105, -1418,   -54,   163,
     989,   990,   991,  6656,   -27,   -12,   964,   999,  1001,  5225,
    5225,  5617,  1004,     1,   886, -1418,   996,  1197,  1200, -1418,
    1006,  1008,  1012,  5225,  5225,  1009,  1018,  1019,   515, -1418,
    1020,    29,    21,    25,    27,   856,  5813,  7740,  4369, -1418,
   -1418,   823, -1418,  1215, -1418,   564,   142,  1216,  7740,  7740,
    7740,   -52,  7740,  1021, -1418,  1080,  7740,  7740,  7740, -1418,
   -1418,  7740,  1022,  1218,  1220, -1418, -1418,  1221, -1418,  1223,
   -1418,   458,  8668,   588,  5322, -1418,  5617,  5617,  7486,  7545,
    1030,  1031,  5693, -1418, -1418, -1418, -1418, -1418, -1418,  5617,
    1226,  1038,  7740,  7740,  1234,  7740,  7740,  7740,  7740,  7740,
    7740,  7740,  7740,  7740,  7740,  7740,  7740,  7740,  7740,  7740,
    7740,  7740,  7740,  7740,  7740,  7740,  7740,  5322,  5322,  5322,
    5322,  5322,  5322,  5617,  5322,  5322,  7740,  5322,  5322,  5322,
    5322,  5322,  7740,  5693,  7740,  5322,  5322,  5322,  5322,  5322,
       3,  5693,     3,  1043,  1043,  1043,    80, 10385,    86,  9994,
     134,  1039,  1236,  -124,  1037, -1418,  1040,  5855,  7740,  7042,
   -1418,  7740,  7740,  7740,  7740,  7740,  7740,  7740,  7740,  7740,
    7740,  7740,  7740,  7740,  7740,  7740, -1418, -1418,  7740,  7740,
   -1418, -1418,  1177,   498,   -36, -1418,   641, -1418,   200,  8775,
   -1418,   343,   326,   402,  1041,  1044, 10406,  7042,   923, -1418,
     117, 10427, 10448,  7740, 10469,   166, 10490, 10511,  7740,   215,
   10532, 10553,  1241,  7740,  7740,   245,  1243,  1245,  1247,  7740,
    7740,  1248,  1250,  1250,  7740,  6852,  6852,  6852,  6852,  7740,
    7740,  7740,  7042,  7042,  8695,  1056,  1252,  1055, -1418, -1418,
      89, -1418, -1418,  8801,  8827,   163,   163,   415,   415,   101,
    7740,  7740,  7740,  6656,  6656,  7740,  5855,   129, -1418,  7740,
    7740,  7740,  7740,  7740,  1254,  1258,  1259,  7740,  1261,  7740,
    7740,  1478, -1418, -1418,  7042,  7042,  7042,  1262,  1263,  7740,
    7740,  7740,  7740,  7740,  1266,    -5,     3, -1418,  1211,  7740,
   -1418,  1217, -1418,  1219, -1418,  1224,    35,    36,    37,    38,
    7042,  1043, -1418, 10574, -1418,   373,  7740,  6009, -1418,  7740,
    7740,   591, -1418, 10595, 10616, 10637,  1132,  8853, -1418,  1071,
    4510, 10658, 10679, 10017, -1418, -1418, -1418,  1594, -1418,  1815,
    7740,  7740, -1418,  7740,  7740,  1077,  1081,   391,   138, 10700,
     257, 10040,  7740,  7042,  1274,  1275, -1418,  7740, 10721, 10063,
     164,  9971,  9971,  9971,  9971,  9971,  9971,  9971,  9971,  9971,
    9971,  9971,  8879,  9971,  9971,  9971,  9971,  9971,  9971,  9971,
    8905,  8931,  8957,  -114,   -77,  -114,  1084,  1085,  1082,  1086,
    1087,  1090,  8983,   428,   428,   428,   360,   428, 11267, -1418,
    1626,  1091,  1092,  1098,   227,   634,  1099,  1100,  1088,  1244,
    1264,  5617,   149,  1267,  1268,  5617,    97,  5693,  7740,  1293,
    1297,    18,   428, -1418,    -8,    32,    24,    99, -1418,  6551,
     431,  4531,   460,  1347,   849,   849,   612,   612,   612,   612,
     491,   491,  1043,  1043,  1043,  1043,     6, 10742, 10086, -1418,
    7740,  7740,  1298,    49,  7042,  7740,  7740,  1300,  7042,  7740,
    1317,  5322,  1318, -1418,     3,  1320,  5322,  7740,  5693,  1296,
    7042,  7042,  1186,  1323,  1324, 10763,  1325,  1190,  1327,  1329,
   10784,  1194,  1331,  1332,  7740, 10805,  6748,  1136, -1418, -1418,
   -1418, 10826, 10847,  7740,  5617,  1338,  1339, 10868,  1145, 11267,
    1141,  1148, 11267,  1144,  1150, 11267,  1146,  1154, 11267,  1166,
   10889, 10910, 10931,   480,   504,  7042,  1152, -1418, -1418,  2001,
    2314,   163,  7740,  7740, -1418, -1418,  1165,  1167,  6656,  9009,
    9035,  9061,  8749,   740,   163,  2472, 10952,  6776, 10973, 10994,
   11015,  7740,  1365, -1418,  7740, 11036, -1418, 10109, 10132, -1418,
     525,   639,   649, -1418, -1418, 10155, 10178,  9087, 11057, 10201,
     142, -1418, -1418,  7042, -1418,  1175,  1172,  6809,  1173,  1174,
    1176, -1418,  7042, -1418,  7042, -1418,  7042, -1418,  7042,   682,
   -1418, -1418,  4715,  7042,  1043, -1418, 11078, 10224,  7042, -1418,
    1372,  1374,  1375,  1183,  7740,  2641,  7740,  7740, -1418, -1418,
      13, -1418, -1418,  2719, -1418,  1181,  5617,  1381,  1348,  1349,
    5617,   149,  1355,  1356,  5617,   149,  6980,   700, -1418, -1418,
   10247,   362,   530, -1418, -1418, -1418, -1418, -1418, -1418, -1418,
   -1418, -1418, -1418, -1418, -1418,  7740, -1418, -1418, -1418, -1418,
   -1418, -1418, -1418,  7740,  7740,  7740, -1418,  7042, -1418, -1418,
   -1418, -1418,  5322,  5617,  5322,  5322,  5693, -1418, -1418, -1418,
   -1418, -1418, -1418, -1418, -1418,  7740,  5322, -1418,  5322, -1418,
    7740, -1418, -1418, -1418, -1418,  -124,  -124,  1391, -1418,  7740,
    1392,  -124,  -124,  1400,    42,  7740,  1401,  1406,  2246, -1418,
    1407,  1214,    11,  1409, -1418,  7042,  7042,  7042,  7042, -1418,
     428,  7740, -1418,  1230,  1231,  1225, -1418,  1417, -1418, -1418,
   -1418, -1418, -1418,   414,   416, 11099, 10270, -1418, -1418,  1249,
    5322,   517, 11120, 10293, -1418,   576,  9113, -1418, -1418, -1418,
    1428, -1418, -1418,  9971,   428,   163,   923, -1418,   733,  5617,
    5617,  1431,  5617,   825,  5617,  5617,  1432,  1358,  5617,  5617,
    2319,  1433,  1438,  7042,  1439,  1441,  1806, -1418, -1418,  1443,
   -1418,  1444,   340,  7740,   340,  7740,   340,  7740,   340,  7740,
    1445,  1446,  1453,  1458,  1459,   709,  1464,  2806, -1418, -1418,
     214,  9139,  9165, -1418, -1418,  7186,  -111,   163,   163,   163,
    1465,  1466,  1246,  1467,  1273,    43,    45,    46,    47,   -18,
   -1418,   218, -1418,   740,  1468,  1470,  1471,  1472,  1473, 11267,
   -1418,  2784,  1270,  1476,  1480,  1481,  1389,  1485,  1487,  1488,
    7740,   142,   169,   743, -1418,  7740, -1418,  7740,  7740,  7740,
     744,   747,   770,   774, -1418,  7740,   778,   142,   142,   779,
    5617,  5617,  5617,  1493,  9191, -1418,  5163,   289,  1494,  1500,
   -1418,  5617,  1272, -1418,  -124,  -124,  1503,  7740,  1506,  -124,
    -124,  1507,  7740,  1508, -1418,   428,  1509, -1418,  1512, -1418,
    1511,  9971,  9971,  9971,  9971,   648,  1315,  1322,  1328,  1341,
    1319,   677,   695, 11141,  1342,   428,  9971,  1546,  5322, -1418,
    2837, -1418,  1546,  5322, -1418,   179,  1343,  1514,  3108, -1418,
   -1418, -1418,    11,  7740, -1418,   785, -1418,   817,   818,   844,
     845,   340, 11267,  1350,  7740,  7740,  5617,  1344, -1418, -1418,
   -1418, -1418,  1351, -1418,  1539,    64, -1418, -1418,  1543,  7740,
    3717,  1558,  1560,    59,  1364,  1368,  1477,  1477,  5617,  1570,
    1373,  1377,  1572,  1576,  5617,  1380,  1579,  1586, -1418,  1589,
    5617,   848,  5617,  5617,  1595,  1603, -1418,  5617,  5617, 11267,
    5617, 11267,  5617, 11267,  5617, 11267,  5617,  5617,  5617,  1396,
    1397,  1604,   647, -1418,  7740,  7740,  7740,  1408,  1412,  -131,
    -108,   -63,  1411, -1418,  5617, -1418,  7740, -1418,  1611, -1418,
    1614, -1418,  1616, -1418,  1617, -1418, -1418,  6656,   505,  5421,
   -1418,  1420,  1424,  6205, -1418,  7042, -1418, -1418, -1418,  1425,
    7740, -1418, -1418, 10316,  1627,   428,  9217,  9243,  9269,  9295,
   -1418, -1418, -1418, -1418, 11267, -1418,   428,  1628,  1629,  1497,
   -1418,  7740,  7740,  7740, -1418,  1632,   726,  1430,  1633,  1546,
    5322, -1418,  3184, -1418,  1546,  5322, -1418,  3372, -1418,   340,
   -1418,   418, -1418, -1418, -1418, -1418, -1418, -1418,  5322, -1418,
   -1418, -1418,  5693,  1636, -1418, -1418,    15, -1418, -1418, -1418,
   -1418, -1418, -1418,  1637,  -114,  -114, -1418,  1638,  -114,  -114,
    5693,  7740,  1639,  1642,    18, -1418,  1648, 10339,    11, -1418,
    1653,  1654,  1655,  1656,  5617,  7740,  9321,  9347,   851, -1418,
    7740,  1659, -1418, -1418,  5322, -1418,  9373,  4572, 11267, -1418,
   -1418, -1418, -1418,  7740,  7740,   163,  1658,  1661,  1662, -1418,
    7740,  7740, -1418, -1418,  1674,  7740, -1418, -1418,  1660,  1676,
    1489,  1678,  1526,  7740, -1418,  1679,  1686,  1688,  1691,  1692,
    1693,   993,  1694,  7042,  7042,  7740, -1418,  6852,  7440, 11162,
    5947,   415,   415,   163,  1695,   163,  1696,   163,  1697,  7740,
     488,  1505, 11183, -1418, -1418, -1418, -1418,  7635,   221, -1418,
    1704,  4172,  1709,  5617,   163,  4172,  1711,   855,  7740,  3421,
    1714,   142, -1418,  7740,  7740,  7740,  7740, -1418, -1418, -1418,
    5617,  6143,   775, 11204, -1418, -1418,  4964,  5617, -1418,  1716,
    -114,  -114, -1418,  1717,  -114,  -114, -1418,  5617, -1418,  1528,
     428,  4768,  5029,  5693, -1418,  1721,  1722, -1418,  1726,  1731,
    1732,  3819, -1418,  1736,  1739, -1418,  1547, -1418, -1418, -1418,
   -1418, -1418,  1741,   606, 11267,  7740,  7740,  5617,  1545,   859,
   11267, -1418,  1745,  7740, -1418, -1418,  7663,  7996,   684, -1418,
   -1418, -1418,  8024,  8052, -1418,  8080,  1747, -1418,  5617, -1418,
    1673,  1748, 11267, -1418, -1418, -1418, -1418, -1418, -1418,  1551,
   -1418, -1418,   862,   865,  8722,  3894,  1750,  1553, -1418,  7740,
   -1418,  1555,  1559,   223, -1418,  1554,   226, -1418,  1562,   235,
   -1418,  1575, 10362,  1757,  5617,  1767,  1580,  7740, -1418,  6401,
     248, -1418,   870,   253,   255, -1418,  1779,  8108, -1418, -1418,
    9399,  9425,  9451,  9477,  1657,  7740, -1418,  7740, -1418, -1418,
    7042,  3916,  1780,  1588, -1418,  1785,  1788, -1418,  1790,  1791,
    1792, -1418, -1418,  4369, -1418, -1418,  5322, 11267, -1418, -1418,
   -1418, -1418, -1418, -1418, -1418, -1418,    11, -1418,  1677, -1418,
   -1418,  7740,  9503,  9529, -1418,  5617,  7740,  1794, -1418,  9555,
   -1418, -1418,  1795,  1796,  1813,  1817,  1818,  1820,   873,  1625,
   -1418,  5617,   236,   433,  7042, -1418, -1418,   415,  6339, -1418,
   -1418,  6656,   740,  6656,   740,  6656,   740,  1824, -1418,   874,
    5617, -1418,  8136,   163,  1826,  7042,   163, -1418, -1418,  7740,
    7740,  7740,  7740,  7740,  8164,  8192,   877, -1418, -1418,  1827,
   -1418, -1418, -1418, -1418, -1418,   881,   986,   888,  1831, -1418,
    1634, 11267,  7740,  7740,   891, 11267, -1418,  7740,   892,   915,
   -1418, -1418, -1418, -1418, -1418, -1418,  1635,  7740,   918,  1643,
     163,  5617,  1834,  1645,   163,  1836,   919,  1641,  7740, -1418,
    8220,   258,   687,  8248,   278,   764,  8276,   296,  1028, -1418,
    5617,  1837,  1751,  3171,  1647,   335, -1418,   926,   337,  9581,
    9607,  9633,  9659,  3964, -1418, -1418,  1846, -1418,  7740, -1418,
    5693, -1418, -1418,  7740, 11225,  9685,    39,  9711, -1418, -1418,
    7740,  8304,  1852,   163,    63, -1418, -1418,   163,    65, -1418,
    1857, -1418,  8332,  1858,  7740,  1859,  1860,  7740,  1861,  1863,
    7740,  1864,  1667, -1418,  7740, -1418,   740, -1418,  7042,  1867,
    6401,  7740,  7740,  7740,  7740, -1418, -1418,  4313, -1418,   938,
   -1418,  7740, -1418,  5617,  7740,  9737, -1418, -1418,   357, -1418,
     366, -1418, -1418, -1418, -1418,  1670,  8360, -1418, -1418,  1671,
    8388, -1418, -1418,  1672,  8416, -1418,  1871,  4128,  1284,  3847,
     939, -1418,   374,   953,  9763,  9789,  9815,  9841,  5693,  1873,
    1680, 11246,   954,  8444,  7740,   163,   163,   740,  1875,   740,
    1876,   740,  1877, -1418, -1418, -1418, -1418,   740,  1879,  7042,
    1880,  7740,  7740,  7740,  7740, -1418, -1418,  5322, -1418,  1683,
    1883,  8472,   398,   411,  1306, -1418,  1702,  1337, -1418,  1705,
    1531, -1418,  1713,  1615, -1418,   957, -1418,  9867,  9893,  9919,
    9945,   981, -1418,  1715,  5617, -1418,  1895,  7740,  7740,  1907,
     740,  1909,   740,  1912,   740, -1418,  1915,  7740,  7740,  7740,
    7740,  5322,  1916,  5322,   984, -1418,  8500,  8528, -1418,  1651,
   -1418,  1663, -1418,  1735, -1418,  8556,  8584,  8612,  8640, -1418,
   -1418,   985, -1418,  1917,  1918,  1919,  1920,  1921,  1927, -1418,
   -1418, -1418, -1418,  5322,  1928, -1418, -1418, -1418, -1418, -1418,
   -1418, -1418, -1418
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,     0,   261,   262,     0,     0,     0,
     256,     0,     0,     0,     0,   357,   358,   359,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   539,     0,
     406,   538,   510,   407,   409,   410,   408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,   531,   514,   414,   415,   416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     411,   412,   413,   513,     0,     0,     0,     0,    66,    67,
       0,     0,   201,     0,     0,     0,   364,     0,   502,   539,
     421,     0,     0,     0,     0,   241,     0,   243,   244,   239,
     240,     0,   245,   246,   123,   131,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   443,     0,     0,
       0,     0,     0,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   538,     0,   201,   539,     0,     0,   354,
       0,     0,     0,     0,     0,     0,     0,     0,   538,   461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
     484,   454,   460,     0,   455,   539,   421,     0,     0,     0,
       0,   538,     0,     0,   496,     0,     0,     0,     0,   237,
     238,     0,   538,     0,     0,   254,   255,     0,   201,     0,
     201,   538,     0,   539,     0,   360,     0,     0,    66,    67,
       0,     0,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   367,   366,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,   199,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,   230,     0,     0,
     429,   178,     0,   538,     0,   502,   539,   503,     0,     0,
     534,     0,   121,   121,     0,     0,     0,     0,   490,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   322,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   201,
       0,   445,   444,     0,     0,     0,     0,   201,   201,     0,
       0,     0,     0,     0,     0,     0,   272,     0,   201,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,   219,   355,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,   467,     0,     0,
     468,     0,   469,     0,   470,     0,     0,     0,     0,     0,
       0,   366,   462,     0,   456,     0,     0,     0,   332,    66,
      67,     0,   236,     0,     0,     0,     0,     0,   201,     0,
       0,     0,     0,     0,   258,   257,   224,     0,   225,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,   365,    59,    60,     0,     0,    59,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,   202,     0,
       0,     0,   382,   381,   379,   380,   375,   377,   376,   378,
     370,   369,   371,   372,   373,   374,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,   352,
     353,     0,     0,     0,     0,   320,     0,     0,     0,   146,
     147,     0,   149,   150,     0,   152,   153,     0,   155,   156,
       0,     0,     0,     0,     0,     0,     0,   166,   201,     0,
       0,     0,     0,     0,   447,   446,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,     0,     0,   335,     0,     0,   220,     0,     0,   216,
       0,     0,     0,   350,   349,     0,     0,     0,     0,     0,
     434,    68,    69,     0,   485,     0,     0,     0,     0,     0,
       0,   471,     0,   472,     0,   473,     0,   474,     0,     0,
     365,   457,   464,     0,   371,   463,     0,     0,     0,   486,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
       0,   226,   228,     0,   540,     0,     0,     0,    59,    60,
       0,     0,    59,    60,     0,     0,     0,     0,    90,    74,
       0,   423,   422,   436,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   405,   393,     0,   395,   396,   397,   398,
     399,   400,   401,     0,     0,     0,   523,     0,   528,   519,
     520,   521,     0,     0,     0,     0,     0,   524,   525,   526,
     442,   530,   135,   140,   113,     0,     0,   515,     0,   517,
       0,   419,   426,   427,   511,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   428,     0,     0,     0,     0,   536,
       0,     0,    44,     0,     0,     0,    57,     0,    35,    36,
      37,    38,    39,   425,   424,     0,     0,   508,    24,    22,
       0,     0,     0,     0,    25,     0,     0,   231,   535,    70,
     124,    71,   132,     0,     0,     0,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   318,   323,   321,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   229,
       0,     0,     0,   191,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,   263,     0,     0,     0,     0,     0,     0,   325,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,   422,     0,   487,     0,   466,     0,     0,     0,
       0,     0,     0,     0,   458,     0,     0,   425,   424,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
     223,     0,     0,   361,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,   431,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    88,     0,     0,    76,     0,     0,     0,     0,    80,
     103,   105,     0,     0,   500,     0,   111,     0,     0,     0,
       0,     0,   383,     0,     0,     0,     0,     0,    30,   433,
     432,   506,   504,    23,     0,     0,   507,   505,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
       0,     0,     0,     0,     0,     0,   329,     0,     0,   148,
       0,   151,     0,   154,     0,   157,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,     0,   306,     0,   312,     0,   314,
       0,   308,     0,   310,     0,   273,   302,     0,     0,     0,
     214,     0,     0,     0,   336,     0,   218,   217,   356,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
     475,   476,   477,   478,   465,   459,     0,     0,     0,     0,
     497,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,    85,     0,    89,     0,     0,    77,     0,    81,     0,
     233,   435,   232,   394,   402,   403,   404,   529,     0,   439,
     440,   441,     0,     0,   418,   136,     0,   533,   141,   438,
     516,   518,   420,     0,     0,     0,    86,     0,     0,     0,
      59,     0,     0,     0,     0,    78,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   452,
       0,     0,    26,    27,     0,    28,     0,     0,   125,   128,
      72,    73,   162,     0,     0,     0,     0,     0,     0,   165,
       0,     0,   181,   182,     0,     0,   167,   188,     0,     0,
       0,     0,   158,     0,   328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,     0,     0,
       0,   201,   201,     0,   283,     0,   285,     0,   287,     0,
     454,     0,     0,   313,   315,   309,   311,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,   488,     0,     0,     0,     0,   489,   170,   171,
       0,     0,     0,     0,   114,   118,     0,     0,   362,     0,
       0,     0,    87,     0,     0,     0,    79,     0,   437,     0,
       0,     0,     0,     0,    97,     0,     0,    91,     0,     0,
       0,     0,   108,     0,     0,   109,     0,   501,   203,   204,
     205,   206,     0,     0,    40,     0,     0,     0,     0,     0,
      42,   509,     0,     0,   126,   129,     0,     0,   161,   168,
     169,   173,     0,     0,   183,     0,     0,   330,     0,   176,
       0,     0,   319,   187,   163,   175,   186,   190,   174,     0,
     184,   189,     0,     0,     0,     0,     0,     0,   451,     0,
     450,     0,     0,     0,   274,     0,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,   213,     0,
       0,   212,     0,     0,     0,   207,     0,     0,   333,    33,
       0,     0,     0,     0,     0,     0,   495,     0,   251,   250,
       0,     0,     0,     0,    98,     0,     0,    92,     0,     0,
       0,   522,   527,     0,   137,   139,     0,   142,   143,   144,
      99,   101,    93,    95,   104,   106,     0,   112,     0,    82,
      45,     0,     0,     0,   453,     0,     0,     0,    29,     0,
     135,   140,     0,     0,     0,     0,     0,     0,     0,     0,
     177,     0,   326,   326,     0,   119,   120,   201,     0,   194,
     195,     0,     0,     0,     0,     0,     0,     0,   303,     0,
       0,   201,     0,     0,     0,     0,     0,   198,   197,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,     0,
     100,   102,    94,    96,    83,     0,   490,     0,     0,   499,
       0,    41,     0,     0,     0,    43,    58,     0,     0,     0,
     344,   346,   345,   347,   348,   180,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,     0,     0,   268,     0,     0,   208,     0,     0,     0,
       0,     0,     0,     0,   494,   252,     0,   363,     0,   138,
       0,   145,   110,     0,     0,     0,     0,     0,   127,   130,
       0,     0,     0,     0,     0,   327,   337,     0,     0,   338,
       0,   192,     0,   289,     0,     0,   291,     0,     0,   293,
       0,     0,     0,   304,     0,   264,     0,   201,     0,     0,
       0,     0,     0,     0,     0,   172,   117,     0,   133,     0,
      49,     0,    55,     0,     0,     0,   159,   185,     0,   341,
       0,   342,   343,   448,   277,     0,     0,   284,   278,     0,
       0,   286,   279,     0,     0,   288,     0,     0,     0,   270,
       0,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
     297,     0,   299,   305,   316,   269,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   134,    46,     0,    53,     0,
       0,     0,     0,     0,     0,   280,     0,     0,   281,     0,
       0,   282,     0,     0,   215,     0,   209,     0,     0,     0,
       0,     0,    47,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,     0,     0,   290,     0,
     292,     0,   294,     0,   210,     0,     0,     0,     0,    48,
      50,     0,    51,     0,     0,     0,     0,     0,     0,   479,
     480,   481,   482,     0,     0,    56,   339,   340,   296,   298,
     300,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1418, -1418, -1418, -1418,   761, -1418, -1418, -1418, -1418,   204,
   -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418,
   -1418, -1418,  -379,   -45,  2939,  2844, -1418,  1482, -1418, -1418,
   -1418, -1418, -1418,   328, -1418,   331, -1418, -1418, -1418, -1418,
   -1418, -1418,   752,  1938,    -2,  -491,  -240, -1418, -1418, -1418,
   -1418, -1418, -1418, -1418,  1940, -1418, -1418, -1418, -1418, -1418,
   -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1418, -1039,  -927,
   -1418, -1418,  1463, -1418,   324, -1418, -1418, -1418, -1418,  1753,
   -1418, -1418,    78, -1418, -1417,  1170,  -118,  2447,   233,  -246,
     614, -1418,   113,    62, -1418,  -366,    -3,   358
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   970,    91,    92,   696,  1483,  1489,
     958,  1163,  1670,  1871,   959,  1820,  1911,   960,  1873,   961,
     962,  1167,   349,   440,   184,   814,    93,   714,   452,  1610,
    1611,   453,  1665,  1131,  1315,  1132,  1318,   748,   751,   754,
     757,  1511,  1366,   678,   299,   416,   417,    96,    97,    98,
      99,   100,   101,   102,   300,  1053,  1766,  1837,   783,  1535,
    1538,  1541,  1795,  1799,  1803,  1856,  1859,  1862,  1049,  1050,
    1205,  1009,   745,   792,  1692,   104,   105,   106,   107,   301,
     186,   912,   502,   257,  1348,   302,   303,   304,   565,   313,
     943,  1155,   450,   445,   913,   451,   333,   306
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,    95,   497,   189,   315,   528,  1552,   322,   351,   214,
     952,   633,   273,   635,  1248,   311,   776,   777,   219,  1462,
    1098,   410,   941,   516,   646,   335,   550,   661,   219,   665,
     552,   668,   554,   191,   547,   531,   214,   195,   327,   329,
     821,   823,   825,   827,   244,  1782,  1145,   245,   278,  1237,
     279,  1239,  1241,  1243,   276,   968,   505,   506,   283,   265,
     228,   284,   305,   229,   350,  1362,   230,   276,   188,  1789,
    1353,  1791,  1403,   206,  1404,   207,   505,   506,   276,   505,
     506,  1040,   505,   506,   811,     4,   812,   659,   587,   711,
     589,  1618,  1041,   663,  1228,  1405,   210,  1406,   248,   507,
    1042,  1043,  1044,   211,   928,     5,  1045,  1046,  1047,  1048,
     476,   477,   478,   249,   250,   481,   482,   483,   193,   187,
     280,   811,  1246,   812,   505,   506,   897,   256,   258,   194,
     264,   266,   342,   505,   506,   267,   953,   954,   955,   956,
    1407,   667,  1408,   323,   326,   858,   338,   268,   339,   576,
     508,   524,   525,   192,   183,   340,   928,   411,   412,   274,
     505,   506,   703,   197,   551,   537,   538,   704,   553,  1463,
     555,  1238,   548,  1240,  1242,  1244,    89,   518,   276,   198,
     415,    89,  1146,  1147,    89,   519,  1330,  1245,  1674,   210,
     446,   446,   520,   811,   199,   812,   945,   316,   446,   813,
     529,   352,   215,   353,  1688,   354,   276,   183,   305,   216,
     183,   957,   275,   305,  1099,   312,   336,   305,   220,   860,
     305,   864,   942,   337,   305,   305,   305,   305,   947,   215,
     305,   305,   305,   549,   969,   196,   946,   328,   330,   822,
     824,   826,   828,  1783,   305,   276,   505,   506,   200,   969,
     505,   506,   505,   506,   660,   344,   345,   346,   769,   770,
     664,   344,   345,   346,   862,   201,   305,   305,   305,   202,
     454,   343,   344,   345,   346,   203,   505,   506,   785,   260,
     305,   305,   261,   929,   269,   262,   270,   935,   505,   506,
     347,   348,   771,   305,   204,   305,   222,  1283,   934,   343,
     344,   345,   346,   948,   778,   205,   444,   448,   343,   344,
     345,   346,   859,   344,   345,   346,   505,   506,   347,   348,
     721,  1246,   722,   343,   344,   345,   346,   347,   348,   500,
     501,   446,   784,   305,   305,   347,   348,   509,   845,  1689,
    1690,   517,   347,   348,   212,  1691,   305,   928,   347,   348,
     252,   253,   853,   343,   344,   345,   346,   347,   348,  -503,
     254,   109,   347,   348,   190,   669,  1822,   255,  -508,   721,
    1264,   727,   347,   348,   446,   446,   446,   446,   446,   446,
     305,   446,   446,   213,   446,   446,   446,   446,   446,   217,
     252,   253,   446,   446,   446,   446,   446,   276,   707,   276,
     254,   505,   506,   708,   604,   505,   506,   263,   505,   506,
     505,   506,   224,   505,   506,   277,   305,  1224,   721,   414,
     731,  1247,   505,   506,  1547,   811,  1631,   812,   314,  1633,
     918,   863,   344,   345,   346,   505,   506,   218,  1635,   324,
     505,   506,   505,   506,   460,   505,   506,   595,   721,   465,
     737,  1643,   225,   469,   305,   649,  1645,  1894,  1646,   233,
     475,  1754,   234,   657,   235,   505,   506,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,  1757,  1107,   505,   506,   435,  1112,  1284,   221,   305,
     305,   634,   222,   636,   637,   638,   566,   640,   641,  1760,
     643,   644,   645,   223,   647,   415,   415,   226,   651,   652,
     653,   654,   655,   227,   343,   344,   345,   346,    48,    49,
      50,    51,   505,   506,   505,   506,   712,    56,  1027,   713,
      59,   305,   305,   305,   443,   112,  1693,  1694,  1768,   413,
    1770,   710,  1691,   276,   505,   506,   711,   750,   753,   756,
     759,   447,   447,   505,   506,   347,   348,   305,   910,   447,
    1825,   505,   506,   711,   305,   873,  -506,   455,   231,  1826,
     139,   140,   141,   142,   143,   144,   721,  1839,   831,   148,
     149,   150,   151,   774,   775,   505,   506,   153,   154,   155,
     232,   501,   156,  1702,   856,  1705,   857,  1708,   505,   506,
     305,  1877,   715,   161,  1040,   713,   314,   347,   348,   347,
     348,   347,   348,   236,  1878,  1041,   246,   930,  -507,   247,
    -505,   936,  -509,  1042,  1043,  1044,   811,   251,   812,  1045,
    1046,  1047,  1048,  1208,   721,  1210,   950,  1212,   259,  1214,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   680,  1396,  1397,   590,   435,   591,   305,   544,
     241,   271,   305,   242,   183,   243,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   567,   433,   434,
     432,   433,   434,   721,   435,  1023,   272,   435,   164,   165,
     166,   282,   447,  1543,   281,   700,  1154,   701,   285,   702,
     173,   305,   174,    89,   183,   305,   286,   721,   446,  1024,
    1419,   276,   542,   446,   543,  1175,   544,   305,   305,   182,
     721,   183,   287,   347,   348,   763,   764,  1808,   721,   937,
    1065,  1118,  1445,  1446,  -504,   447,   447,   447,   447,   447,
     447,   305,   447,   447,   308,   447,   447,   447,   447,   447,
     438,   309,   439,   447,   447,   447,   447,   447,   656,   340,
     658,   569,   305,   570,   307,   873,  1331,   800,   801,   802,
     340,  1324,  1325,   319,  1178,  1246,  1328,  1329,  1246,   721,
     984,  1246,  1344,  1567,   310,   593,  1040,   594,  1854,   811,
    1857,   812,  1860,   829,   340,   838,   317,  1041,  1863,   430,
     431,   432,   433,   434,  1600,  1042,  1043,  1044,   435,  1601,
     305,  1045,  1046,  1047,  1048,  1184,  1108,  1185,   318,   305,
    1113,   305,   320,   305,   978,   305,  1117,  1119,   321,   982,
     305,   566,   811,   380,   812,   305,   867,   920,   705,  1040,
     706,  1899,   721,  1901,  1066,  1903,   811,   340,   812,  1030,
    1041,   721,   721,   305,  1067,   334,  1036,   305,  1042,  1043,
    1044,   305,  1051,  1040,  1045,  1046,  1047,  1048,   381,   446,
     237,   505,   506,   238,  1041,   811,   239,   812,   240,   394,
    1313,  1246,  1042,  1043,  1044,   721,   382,  1084,  1045,  1046,
    1047,  1048,  1755,   811,   305,   812,   383,   402,  1316,   446,
     305,   446,   446,   721,   815,  1115,  1336,  1190,   384,  1191,
    1531,  1532,   721,   446,  1221,   446,   385,   390,  1169,  1170,
    1457,   395,   396,  1450,  1451,   397,   400,  1246,  1454,  1455,
    1246,   566,   556,  1246,   401,   557,  1246,   971,   558,   276,
     559,   975,   305,   305,   305,   305,   721,   721,  1265,  1270,
     721,   437,  1271,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   446,  1130,  1758,
     418,   435,  1246,   721,  1246,  1272,  1246,   721,   441,  1273,
    1568,   721,   721,  1275,  1276,  1120,   305,   305,  1338,   305,
    1339,   305,   305,  1730,   566,   305,   305,  1519,  1025,  1520,
     305,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   567,   433,   434,  1126,   419,  1128,  1129,   435,
     721,   721,  1340,  1341,   436,   463,  1117,  1119,   468,  1134,
     473,  1135,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   474,  1169,  1170,   479,   435,  1073,   721,   721,  1342,
    1343,   721,   495,  1380,  1487,  1080,  1488,  1081,   721,  1082,
    1556,  1083,  1606,  1183,  1607,   721,  1086,  1622,   721,   447,
    1623,  1089,   980,  1487,   447,  1644,  1487,  1710,  1686,  1711,
     721,   480,  1726,  1174,  1728,   530,  1729,   305,   305,   305,
     484,   711,  1477,  1731,  1487,  1313,  1736,  1738,   305,   485,
    1332,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   720,   433,   434,  1229,  1230,  1231,  1316,   435,
    1739,  1487,   721,  1742,  1750,   486,   487,  1040,   488,   721,
    1125,  1769,   489,   490,   446,   446,  1697,   420,  1041,   446,
     446,  1606,   721,  1819,  1838,   491,  1042,  1043,  1044,   276,
     492,   498,  1045,  1046,  1047,  1048,   721,  1487,  1840,  1849,
     721,   521,  1886,   305,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   720,   433,   434,  1157,  1158,
    1159,  1160,   435,   699,  1891,   305,  1892,  1487,  1923,  1913,
    1924,   305,   499,   510,   511,   512,   522,   305,   523,   305,
     305,   527,   340,   532,   305,   305,   533,   305,   539,   305,
     534,   305,   535,   305,   305,   305,   536,   540,   541,   546,
    1667,   568,   572,   579,   584,   578,   585,   586,   183,   588,
     447,   305,   606,  1761,   602,   603,  1201,   607,   610,   435,
     670,   182,  1359,   671,   717,   673,   305,   718,   734,   738,
     305,   739,   305,   740,   766,   743,  1458,   744,   767,   768,
     447,   791,   447,   447,   793,   816,   794,   796,   803,   804,
     810,   818,   843,   819,   447,   846,   447,   854,   820,   855,
     868,   869,   900,   901,   925,   902,   446,   446,   924,   903,
     904,   446,   446,   905,   915,   916,   917,   922,   923,   939,
     314,   940,   967,   985,   926,   446,   974,   931,   932,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   977,   979,  1418,   981,   435,   447,   988,
     989,   990,   992,   993,   994,   276,   995,   997,   998,   999,
    1003,   305,  1008,  1012,  1013,  1010,  1014,  1015,  1016,  1017,
    1668,   446,  1018,  1026,   305,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,  1019,
    1033,  1060,  1034,   435,  1460,  1074,  1075,  1077,  1078,  1090,
    1079,  1091,  1092,  1040,  1093,  1101,  1458,  1103,  1104,  1105,
     305,   305,  1470,   472,  1041,  1109,  1110,  1139,  1141,   415,
     415,  1713,  1042,  1043,  1044,  1040,  1144,  1149,  1045,  1046,
    1047,  1048,  1150,  1153,  1152,  1156,  1041,   496,   305,  1495,
     305,  1459,   305,  1168,  1042,  1043,  1044,  1164,  1165,  1166,
    1045,  1046,  1047,  1048,  1173,  1180,  1040,   305,  1188,  1194,
    1199,   526,  1195,  1498,   305,  1200,  1202,  1041,  1203,  1206,
    1234,  1207,  1216,  1217,   305,  1042,  1043,  1044,   305,  1526,
    1218,  1045,  1046,  1047,  1048,  1219,  1220,  1492,  1222,  1232,
    1236,  1259,  1233,  1235,  1255,  1249,  1250,  1288,  1251,  1252,
    1253,  1533,  1256,  1536,   305,  1539,  1257,  1258,  1427,  1835,
       7,     8,  1260,  1261,  1262,   447,   447,  1280,  1285,  1550,
     447,   447,  1553,  1554,  1286,   305,   596,   597,  1572,  1291,
     314,  1879,  1293,  1296,  1298,  1300,  1301,  1302,  1308,   605,
    1309,  1334,  1312,  1585,  1588,  1589,  1310,  1809,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,  1311,
    1320,   305,  1881,   435,  1333,  1352,   305,  1345,  1350,  1355,
     443,   112,  1351,   639,   674,    24,    25,   675,    27,    28,
     676,    30,   677,    32,  1360,    33,  1361,   305,  1363,  1365,
      38,    39,  1364,    41,    42,    43,  1369,  1370,  1372,    46,
     305,  1371,  1373,   446,  1375,  1376,   139,   140,   141,   142,
     143,   144,  1377,   276,  1378,   148,   149,   150,   151,  1383,
    1393,  1394,   305,   153,   154,   155,     7,     8,   156,  1384,
    1409,  1395,  1401,    67,    68,    69,  1402,  1413,   305,   161,
    1414,   305,  1415,  1416,  1423,   415,  1522,  1523,  1424,  1428,
    1040,  1431,   914,  1447,  1438,  1439,  1440,   305,  1444,  1448,
    1461,  1041,   305,  1464,  1467,  1472,  1473,   447,   447,  1042,
    1043,  1044,   447,   447,  1475,  1045,  1046,  1047,  1048,  1478,
    1479,  1480,  1481,  1491,  1499,  1506,   447,  1500,  1501,  1510,
     674,    24,    25,   675,    27,    28,   676,    30,   677,    32,
    1504,    33,  1507,   799,  1509,  1513,    38,    39,   305,    41,
      42,    43,  1514,  1508,  1515,    46,   314,  1516,  1517,  1518,
    1521,  1534,  1537,  1540,   164,   165,   166,   305,  1544,  1701,
    1548,  1704,   447,  1707,  1040,  1551,   173,  1555,   174,    89,
    1559,  1715,  1574,  1577,  1718,  1041,  1581,  1590,  1591,    67,
      68,    69,  1592,  1042,  1043,  1044,  1883,  1593,  1594,  1045,
    1046,  1047,  1048,  1596,   811,  1597,   812,  1599,  1598,  1605,
    1040,  1608,  1617,  1619,  1620,  1621,  1626,  1627,  1632,   185,
    1629,  1041,  1040,  1638,  1630,   305,  1634,   305,  1744,  1042,
    1043,  1044,  1748,  1041,  1640,  1045,  1046,  1047,  1048,  1636,
     305,  1042,  1043,  1044,  1641,  1647,  1658,  1045,  1046,  1047,
    1048,  1660,  1778,  1659,  1661,  1653,  1662,  1663,  1664,   851,
    1676,  1680,  1681,  1656,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,  1669,  1682,
    1885,  1788,   435,  1683,  1684,  1790,  1685,     7,     8,  1687,
    1709,   927,  1716,  1727,  1040,   933,   305,  1732,  1733,  1740,
    1746,   332,  1749,  1763,   446,  1041,  1751,  1743,  1812,  1747,
    1764,  1767,  1776,  1042,  1043,  1044,  1916,  1696,  1787,  1045,
    1046,  1047,  1048,  1792,  1794,  1797,  1798,  1801,  1917,  1802,
    1805,   305,  1806,  1811,  1827,  1829,  1831,  1833,  1717,  1846,
    1845,  1855,  1858,  1861,  1847,  1864,  1866,  1874,   446,  1875,
     446,   674,    24,    25,   675,    27,    28,   676,    30,   677,
      32,  1895,    33,  1852,  1853,  1204,  1880,    38,    39,  1882,
      41,    42,    43,  1898,  1007,  1900,    46,  1884,  1902,  1893,
     446,  1904,  1910,  1925,  1926,  1927,  1928,  1929,   403,   404,
     405,   407,   409,  1930,  1932,   716,  1354,  1779,  1678,  1367,
    1918,    94,  1679,   103,   447,   442,   746,  1695,  1474,   449,
      67,    68,    69,     0,   314,     0,     0,     0,     0,     0,
    1872,     0,     0,   456,   458,   461,   462,     0,   464,   458,
     466,   467,     0,   458,   470,   471,     0,     0,     0,     0,
     458,     0,     0,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   494,     0,
       0,  1810,   435,  1813,  1909,     0,  1912,   503,   504,     0,
       0,     0,     0,     7,     8,     0,   504,     0,     0,     0,
     852,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
    1106,     0,     0,     0,  1111,     0,  1931,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   561,
     563,   458,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,   574,   575,     0,   577,     0,     0,     0,   580,
     581,   582,  1865,  1127,   583,     0,     0,   674,    24,    25,
     675,    27,    28,   676,    30,   677,    32,     0,    33,     0,
       0,   599,   601,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,   608,   609,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
       0,     0,     0,     0,     0,     0,    67,    68,    69,   642,
       0,     0,     0,     0,     0,   648,     0,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1186,
    1187,     0,  1189,     0,  1192,  1193,     0,     0,  1196,  1197,
       0,   679,   458,     0,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,     0,
       0,   697,   698,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   447,  1028,     0,     0,     0,
     561,     0,     0,     0,     0,     0,   725,     0,     0,     0,
       0,   730,     0,     0,     0,     0,   735,   736,     0,     0,
       0,     0,   741,   742,     0,     0,     0,   747,   749,   752,
     755,   758,   760,   761,   762,   458,   458,     0,     0,   447,
       0,   447,  1151,     0,     0,     0,     0,     0,     0,     0,
    1277,  1278,  1279,   779,   780,   781,   403,   404,   782,     0,
       0,  1287,   786,   787,   788,   789,   790,     0,     0,     0,
     795,   447,   797,   798,     0,     0,     0,   458,   458,   458,
       0,     0,   805,   806,   807,   808,   809,     0,     0,     0,
       0,     0,   817,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,     0,     0,     0,     0,     0,   832,
     834,     0,   836,   837,     0,  1198,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,  1349,     0,     0,     0,
       0,     0,     0,   808,   809,     0,   836,   837,     0,     0,
       0,     0,     0,     0,     0,   866,   458,     0,  1368,     0,
     870,     0,     0,     0,  1374,     0,     0,     0,     0,     0,
    1379,     0,  1381,  1382,     0,     0,     0,  1385,  1386,     0,
    1387,     0,  1388,     0,  1389,     0,  1390,  1391,  1392,     0,
     674,    24,    25,   675,    27,    28,   676,    30,   677,    32,
       0,    33,     0,     0,  1411,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,  1422,
       0,   938,     0,  1426,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,   965,   966,     0,     0,   458,   972,   973,
       0,   458,   976,     0,     0,     0,     0,     0,     0,     0,
     983,     0,     0,   834,   986,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,  1000,     0,     0,
       0,     0,     0,     0,     0,     0,  1006,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,  1482,   435,     0,     0,   458,  1029,
       0,     0,     0,     0,     0,  1031,  1032,  1494,     0,     0,
       0,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1059,     0,     0,  1061,   674,    24,
      25,   675,    27,    28,   676,    30,   677,    32,     0,    33,
       0,     0,     0,     0,    38,    39,   458,    41,    42,    43,
       0,     0,     0,    46,     0,   458,     0,   458,     0,   458,
       0,   458,     0,     0,     0,     0,   458,     0,     0,     0,
       0,   458,     0,  1349,     0,     0,     0,  1094,     0,  1096,
    1097,     0,     0,     0,     0,     0,     0,    67,    68,    69,
    1564,     0,     0,     0,     0,     0,     0,  1573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1580,     0,     0,
       0,  1584,     0,     0,     0,     0,     0,     0,  1121,     0,
       0,     0,     0,     0,     0,     0,  1122,  1123,  1124,     0,
     458,     0,     0,     7,     8,     0,     0,  1604,   459,     0,
       0,     0,     0,   459,     0,     0,     0,   459,  1133,     0,
       0,     0,     0,  1136,   459,     0,     0,  1052,  1349,     0,
       0,     0,  1140,     0,     0,     0,     0,     0,  1148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   458,   458,
     458,   458,     0,     0,  1162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1639,     0,     0,   674,    24,    25,
     675,    27,    28,   676,    30,   677,    32,     0,    33,     0,
       0,     7,     8,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,   562,     0,   459,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1209,     0,  1211,     0,
    1213,     0,  1215,     0,     0,  1349,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1254,  1349,     0,     0,     0,   674,    24,    25,   675,    27,
      28,   676,    30,   677,    32,     0,    33,     0,     0,     0,
    1712,    38,    39,     0,    41,    42,    43,     0,     7,     8,
      46,     0,     0,  1263,     0,     0,     0,     0,  1266,     0,
    1267,  1268,  1269,     0,     0,     0,     0,     0,  1274,     0,
       0,     0,     0,  1326,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
    1292,  1745,     0,     0,     0,  1297,   459,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1762,     0,   674,    24,    25,   675,    27,    28,   676,    30,
     677,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,   562,     0,  1337,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1346,  1347,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,     0,  1356,  1358,     0,     0,     0,     0,     0,   459,
     459,    67,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1349,     0,     0,     0,     0,     0,     0,
     208,   209,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,  1398,  1399,  1400,
     435,   459,   459,   459,     0,     0,     0,  1410,     0,  1412,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1417,     0,     0,     0,     0,     0,     0,   459,   458,     0,
       0,  1223,     0,  1429,   835,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,  1441,  1442,  1443,     0,     0,     0,
       0,     0,     0,     0,  1349,     0,     0,   341,     0,     0,
     459,     0,     0,     0,     0,     0,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,  1471,     0,     0,   386,   387,   388,
     389,     0,     0,   391,     0,     0,     0,     0,  1484,   392,
     393,     0,     0,  1490,     0,   398,   399,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,  1496,  1497,     0,     0,
       0,     0,     0,  1502,  1503,     0,     0,     0,  1505,     0,
       0,     0,     0,     0,     0,     0,  1512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,   458,  1524,     0,
    1525,   459,     0,     0,     0,   459,   322,   112,     0,     0,
       0,     0,  1542,     0,     0,     0,     0,   835,   987,     0,
       0,     0,     0,     0,   458,     0,     0,     0,   458,     0,
       0,  1557,     0,     7,     8,     0,  1560,  1561,  1562,  1563,
    1452,     0,   139,   140,   141,   142,   143,   144,     0,  1571,
       0,   148,   149,   150,   151,     0,     0,     0,     0,   153,
     154,   155,   459,     0,   156,  1587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,   545,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1602,  1603,
       0,     0,     0,     0,   571,     0,  1609,   674,    24,    25,
     675,    27,    28,   676,    30,   677,    32,     0,    33,     0,
     459,     0,     0,    38,    39,     0,    41,    42,    43,   459,
       0,   459,    46,   459,     0,   459,     0,     0,     0,     0,
     459,     0,  1628,     0,     0,   459,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
    1642,     0,   561,     0,   435,     0,    67,    68,    69,     0,
     164,   165,   166,     0,     0,     0,     0,     0,  1654,     0,
    1655,     0,   173,   458,   174,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1666,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,     0,     0,     0,
       0,     0,   672,     0,  1671,     0,     0,     0,     0,  1675,
       0,     0,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,  1765,   458,  1456,     0,
     435,     0,     0,     0,  1700,     0,  1703,     0,  1706,     0,
       0,     0,   459,   459,   459,   459,     0,     0,   458,     0,
       0,     0,  1719,  1720,  1721,  1722,  1723,     0,     0,     0,
       0,     0,     0,     0,     0,   839,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1734,  1735,  1558,     0,     0,
    1737,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1741,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,  1752,     0,     0,     0,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,     0,   886,   887,   888,
     889,   890,   891,   892,     0,     0,     0,   896,   898,   899,
       0,  1777,     0,     0,     0,     0,  1490,   907,   908,   909,
       0,   911,     0,  1785,     0,     0,     0,     0,   919,   921,
       0,     0,     0,     0,     0,     0,     0,  1796,     0,     0,
    1800,     0,     0,  1804,     0,     0,   944,  1807,     0,     0,
       0,   458,     0,   458,  1814,  1815,  1816,  1817,     0,     0,
       0,     0,     0,     0,  1821,     0,     0,  1823,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1851,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,     0,  1867,  1868,  1869,  1870,     0,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1896,  1897,     0,     0,     0,     0,     0,     0,     0,     0,
    1905,  1906,  1907,  1908,     0,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   459,   153,   154,   155,     0,     0,   156,     0,
     157,   158,   159,     0,     0,     0,     0,     0,   160,   161,
     110,   331,   112,     0,     0,     0,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
     161,     0,     0,     0,  1161,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   166,   167,     0,     0,
       0,   168,   169,   170,   171,   172,   173,     0,   174,    89,
       0,     0,     0,     0,     0,  1595,     0,  1181,  1182,     0,
       0,     0,     0,   175,   176,     0,     0,     0,   177,     0,
     459,   459,     0,   178,     0,   179,     0,   180,   181,     0,
     182,     0,   183,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,  1137,  1138,     0,     0,   459,     0,
    1142,  1143,   459,     0,   163,   164,   165,   166,   167,     0,
       0,     0,   168,   169,   170,   171,   172,   173,     0,   174,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1625,     0,     0,     0,   175,   176,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   181,
       0,  1357,  1657,   674,    24,    25,   675,    27,    28,   676,
      30,   677,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1299,
       0,     0,     0,     0,     0,  1303,  1304,  1305,  1306,  1307,
    1775,     0,     0,     0,     0,  1314,  1317,     0,     0,  1321,
    1322,  1323,    67,    68,    69,     0,  1327,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   459,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1289,  1290,     0,     0,     0,  1294,  1295,
       0,     0,  1836,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   459,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   459,     0,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,  1432,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
    1437,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1449,  1834,     0,     0,     0,  1453,     0,
       0,     0,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,  1465,  1466,
       0,     0,  1468,  1469,     0,   110,   288,     0,     0,     0,
       0,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,     0,     0,     0,   459,     0,   459,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,     0,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,   459,    59,     0,     0,
       0,     0,     0,     0,  1575,  1576,     0,     0,  1578,  1579,
       0,     0,     0,     0,  1582,     0,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
    1818,     0,     0,     0,   435,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
    1549,     0,     0,     0,   177,     0,     0,     0,     0,   515,
       0,     0,   110,   288,   181,     0,   255,   564,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   290,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   291,     0,     0,   292,     0,
       0,   293,     0,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,     0,
       0,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,   847,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     167,     0,     0,     0,   168,   169,   170,   171,   172,   951,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   457,     0,     0,
       0,   177,     0,     0,     0,     0,   297,     0,     0,     0,
       0,   181,     0,     0,   564,   110,   288,   112,     0,     0,
       0,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,   161,     0,     0,   291,     0,
       0,   292,     0,     0,   293,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,  1085,     0,     0,     0,   435,     0,   163,
     164,   165,   166,   167,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,   174,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     296,     0,     0,     0,   177,     0,     0,     0,     0,   297,
       0,   110,   288,   112,   181,     0,   298,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   290,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   153,   154,   155,     0,     0,
     156,     0,   157,   158,   159,     0,     0,     0,     0,     0,
     160,   161,     0,     0,   291,     0,     0,   292,     0,     0,
     293,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167,
       0,     0,     0,   168,   169,   170,   171,   172,   173,     0,
     174,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,   296,     0,     0,     0,
     177,     0,     0,     0,     0,   297,     0,   110,   331,   112,
     181,     0,  1583,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,   153,   154,   155,     0,     0,   156,     0,   157,   158,
     159,     0,   110,   331,   112,     0,   160,   161,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   153,   154,   155,     0,
       0,   156,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,     0,     0,     0,   168,
     169,   170,   171,   172,   173,     0,   174,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,   176,     0,     0,     0,   177,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   181,     0,  1570,     0,
       0,  1282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
     167,     0,     0,     0,   168,   169,   170,   171,   172,   173,
       0,   174,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   176,     0,     0,
       0,   177,     0,     0,     0,     0,   297,     0,   110,   288,
     289,   181,     0,  1586,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   290,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   291,     0,     0,   292,     0,     0,   293,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,   443,   112,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   148,   149,   150,   151,     0,     0,     0,     0,   153,
     154,   155,   163,     0,   156,     0,   167,     0,     0,     0,
     168,   169,   170,   171,   172,   161,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,   296,     0,     0,     0,   177,     0,     0,
       0,     0,   297,     0,   110,   288,  1420,   181,     0,   298,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
     164,   165,   166,     0,     0,   157,   158,   159,     0,     0,
       0,     0,   173,   160,   174,    89,     0,   291,     0,     0,
     292,   325,   112,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   148,   149,   150,   151,
       0,     0,     0,     0,   153,   154,   155,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   296,
       0,     0,     0,   177,     0,     0,     0,     0,   297,     0,
     110,   288,     0,   181,     0,  1421,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   290,   164,   165,   166,     0,     0,
       0,     0,     0,   145,   146,   147,     0,   173,     0,   174,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   291,     0,     0,   292,     0,   112,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   148,   149,   150,   151,     0,     0,     0,     0,
     153,   154,   155,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   167,     0,
       0,     0,   168,   169,   170,   171,   172,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   296,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,   110,   288,     0,   181,
       0,   298,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     290,   164,   165,   166,     0,     0,     0,     0,     0,   145,
     146,   147,     0,   173,     0,   174,   152,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   160,     0,     0,     0,   291,
       0,     0,   292,     0,     0,   293,     0,   294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
       0,   674,    24,    25,   675,    27,    28,   676,    30,   677,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,   167,     0,     0,     0,   168,   169,
     170,   171,   172,     0,     0,     0,    89,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
     175,   457,     0,     0,     0,   177,     0,     0,     0,     0,
     297,     0,   110,   288,     0,   181,     0,   560,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   290,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   146,   147,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   291,     0,     0,   292,     0,
       0,   293,     0,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1529,     0,  1530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     167,     0,     0,     0,   168,   169,   170,   171,   172,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   457,     0,     0,
       0,   177,     0,     0,     0,     0,   297,     0,   110,   288,
       0,   181,     0,   833,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   290,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,     0,     0,
       0,   291,     0,     0,   292,     0,     0,   293,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1565,     0,  1566,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   167,     0,     0,     0,
     168,   169,   170,   171,   172,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,   296,     0,     0,     0,   177,     0,     0,
       0,     0,   297,     0,   110,   288,     0,   181,     0,  1425,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   290,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   291,     0,     0,
     292,     0,     0,   293,     0,   294,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1698,     0,  1699,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   513,  1549,
       0,     0,     0,   177,     0,     0,     0,     0,   515,     0,
     110,   331,     0,   181,     0,   255,   113,   114,   115,     0,
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
       0,     0,     0,     0,   163,     0,   949,     0,   167,     0,
       0,     0,   168,   169,   170,   171,   172,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   175,   176,     0,     0,     0,   177,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   181,
       0,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   513,   514,     0,     0,     0,   177,     0,
       0,     0,     0,   515,     0,   110,   331,   112,   181,     0,
     255,   113,   114,   115,     0,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   153,
     154,   155,     0,     0,   156,     0,   157,   158,   159,     0,
       0,     0,     0,     0,   160,   161,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1002,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1055,     0,     0,     0,     0,     0,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,   163,
     164,   165,   166,   167,  1076,     0,     0,   168,   169,   170,
     171,   172,   173,     0,   174,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     176,     0,     0,     0,   177,   110,   288,     0,     0,   297,
       0,   113,   114,   115,   181,     0,   116,   117,   118,   119,
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
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     457,     0,     0,     0,   177,   110,   331,     0,     0,   297,
       0,   113,   114,   115,   181,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
     147,     0,     0,     0,     0,   152,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   331,   157,   158,   159,     0,
     113,   114,   115,     0,   160,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,   147,
       0,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,     0,     0,
       0,     0,     0,   160,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,   163,
       0,  1227,     0,   167,     0,     0,     0,   168,   169,   170,
     171,   172,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
     176,     0,     0,     0,   177,     0,     0,     0,     0,   297,
     406,     0,     0,     0,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   167,     0,     0,     0,   168,   169,   170,   171,
     172,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   176,
       0,     0,     0,   177,     0,     0,     0,     0,   297,   110,
     331,   408,     0,   181,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,   146,   147,     0,     0,     0,     0,   152,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   331,
     157,   158,   159,     0,   113,   114,   115,     0,   160,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   146,   147,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,     0,     0,     0,     0,   160,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,   163,     0,  1527,     0,   167,     0,     0,
       0,   168,   169,   170,   171,   172,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,   176,     0,     0,     0,   177,     0,
       0,     0,     0,   297,   598,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   167,     0,     0,     0,
     168,   169,   170,   171,   172,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,   176,     0,     0,     0,   177,     0,     0,
       0,     0,   297,   110,   331,   600,     0,   181,     0,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,   146,   147,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
       0,     0,   160,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
    1546,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,     0,     0,  1612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,   163,     0,     0,
       0,   167,     0,     0,     0,   168,   169,   170,   171,   172,
       0,     0,     0,    89,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,     0,   175,   176,     0,
       0,     0,   177,     0,    -4,    -4,    -4,   297,     0,     0,
      -4,    -4,   181,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     6,     0,     0,     0,     0,    -4,
       0,     0,     7,     8,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     9,    10,
       0,     0,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,    11,    12,    13,     0,     0,     0,
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
       0,     0,    85,    86,    87,     0,     0,     0,     0,     0,
       0,    88,     0,    89,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1613,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1614,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1615,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1616,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1648,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1714,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1724,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1725,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1753,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1756,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1759,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1786,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1793,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1828,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1830,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1832,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1850,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1876,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1914,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,  1915,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,  1919,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,     0,     0,     0,     0,     0,  1920,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,  1921,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,  1922,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,   592,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,   765,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,  1624,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   830,     0,     0,
       0,     0,   772,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   709,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   772,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     773,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   844,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,   885,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,   893,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,   894,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
     895,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,   906,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1037,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1038,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1039,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1070,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1179,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1225,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1226,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1281,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1433,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1434,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1435,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1436,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1485,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1486,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1493,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1649,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1650,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1651,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1652,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1672,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1673,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1677,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1771,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1772,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1773,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1774,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1781,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1784,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1824,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1841,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1842,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1843,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,  1844,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
    1887,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,     0,     0,     0,  1888,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,     0,
       0,     0,  1889,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,  1890,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   811,
       0,   812,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,   666,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,   850,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
     865,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,   872,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,   964,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,  1063,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,  1064,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,     0,     0,  1068,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,     0,     0,  1069,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,     0,
       0,  1072,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,     0,     0,  1088,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,     0,     0,  1116,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,     0,     0,
    1172,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,     0,     0,  1177,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,     0,     0,  1430,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,     0,     0,  1476,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
       0,     0,  1637,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   662,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   719,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   723,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   724,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   726,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   728,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   729,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     732,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   733,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   830,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,   840,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,   841,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,   842,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,   848,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,   849,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,   861,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,   871,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
     963,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,   991,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,   996,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1001,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1004,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1005,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1011,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1020,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1021,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1022,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1054,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1056,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1057,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1058,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1062,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435,     0,  1071,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,   435,     0,  1087,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,     0,     0,     0,     0,   435,     0,  1171,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,     0,     0,     0,     0,   435,     0,  1176,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,     0,     0,     0,     0,   435,     0,  1319,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,     0,     0,     0,     0,   435,     0,
    1528,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,     0,     0,     0,     0,   435,
       0,  1545,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,     0,     0,     0,     0,
     435,     0,  1569,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     0,     0,     0,
       0,   435,     0,  1780,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,     0,     0,
       0,     0,   435,     0,  1848,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,     0,
       0,     0,     0,   435
};

static const yytype_int16 yycheck[] =
{
       3,     3,   248,     6,     4,     4,  1423,     4,     4,     4,
       4,   377,     4,   379,  1053,     4,   507,   508,     4,     4,
       7,     4,     4,   263,   390,     6,     5,   406,     4,   408,
       5,   410,     5,    13,     5,   275,     4,     6,     5,     5,
       5,     5,     5,     5,    79,     6,     4,    82,     4,     6,
       6,     6,     6,     6,    57,     6,   187,   188,    79,     4,
      76,    82,    65,    79,   109,     6,    82,    70,     6,     6,
       6,     6,   203,   197,   205,   199,   187,   188,    81,   187,
     188,    99,   187,   188,   198,     6,   200,     7,   328,   203,
     330,  1508,   110,     7,   205,   203,   197,   205,   140,   204,
     118,   119,   120,   204,     7,     0,   124,   125,   126,   127,
     228,   229,   230,   155,   156,   233,   234,   235,   197,     6,
      76,   198,  1049,   200,   187,   188,   203,    49,    50,   197,
      52,    76,     7,   187,   188,    80,   130,   131,   132,   133,
     203,     7,   205,    81,    82,     7,   197,    92,   199,   201,
     204,   269,   270,    82,   206,   206,     7,   140,   141,   151,
     187,   188,   198,     6,   143,   283,   284,   203,   143,   154,
     143,   128,   143,   128,   128,   128,   173,   204,   181,     6,
     182,   173,   140,   141,   173,   197,     7,   205,  1605,   197,
     193,   194,   204,   198,     6,   200,   204,   197,   201,   204,
     199,   197,   197,   199,  1621,   201,   209,   206,   211,   204,
     206,   205,   204,   216,   201,   204,   197,   220,   204,   598,
     223,   600,   204,   204,   227,   228,   229,   230,   204,   197,
     233,   234,   235,   204,   185,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   247,   248,   187,   188,     6,   185,
     187,   188,   187,   188,   174,   175,   176,   177,   498,   499,
     174,   175,   176,   177,     7,   197,   269,   270,   271,     6,
     208,   174,   175,   176,   177,     6,   187,   188,   518,    76,
     283,   284,    79,   662,    82,    82,    84,   666,   187,   188,
     193,   194,   203,   296,   199,   298,   197,     8,   201,   174,
     175,   176,   177,   204,   203,   199,   193,   194,   174,   175,
     176,   177,   174,   175,   176,   177,   187,   188,   193,   194,
     203,  1248,   205,   174,   175,   176,   177,   193,   194,   251,
     252,   334,   203,   336,   337,   193,   194,   259,   578,   103,
     104,   263,   193,   194,   197,   109,   349,     7,   193,   194,
     187,   188,   592,   174,   175,   176,   177,   193,   194,   204,
     197,     3,   193,   194,     6,   410,  1783,   204,   204,   203,
     201,   205,   193,   194,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   197,   387,   388,   389,   390,   391,   197,
     187,   188,   395,   396,   397,   398,   399,   400,   198,   402,
     197,   187,   188,   203,   342,   187,   188,   204,   187,   188,
     187,   188,    82,   187,   188,    57,   419,   203,   203,     4,
     205,   203,   187,   188,   203,   198,   203,   200,    70,   203,
     203,   174,   175,   176,   177,   187,   188,   197,   203,    81,
     187,   188,   187,   188,   211,   187,   188,   334,   203,   216,
     205,   203,    82,   220,   457,   393,   203,  1874,   203,    79,
     227,   203,    82,   401,    84,   187,   188,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   203,   861,   187,   188,   196,   865,   198,   197,   492,
     493,   378,   197,   380,   381,   382,     8,   384,   385,   203,
     387,   388,   389,    86,   391,   507,   508,     6,   395,   396,
     397,   398,   399,   204,   174,   175,   176,   177,   103,   104,
     105,   106,   187,   188,   187,   188,   200,   112,   768,   203,
     115,   534,   535,   536,     4,     5,   103,   104,   203,   181,
     203,   198,   109,   546,   187,   188,   203,   485,   486,   487,
     488,   193,   194,   187,   188,   193,   194,   560,   198,   201,
     203,   187,   188,   203,   567,   610,   204,   209,    82,   203,
      40,    41,    42,    43,    44,    45,   203,   203,   205,    49,
      50,    51,    52,   505,   506,   187,   188,    57,    58,    59,
      82,   513,    62,  1632,   203,  1634,   205,  1636,   187,   188,
     603,   203,   200,    73,    99,   203,   248,   193,   194,   193,
     194,   193,   194,    84,   203,   110,   197,   662,   204,    79,
     204,   666,   204,   118,   119,   120,   198,   204,   200,   124,
     125,   126,   127,  1012,   203,  1014,   205,  1016,   204,  1018,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   419,     6,     7,   197,   196,   199,   661,   201,
      79,    82,   665,    82,   206,    84,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     189,   190,   191,   203,   196,   205,    79,   196,   158,   159,
     160,    82,   334,   205,    79,   197,   942,   199,     4,   201,
     170,   704,   172,   173,   206,   708,     4,   203,   711,   205,
     205,   714,   197,   716,   199,   198,   201,   720,   721,   204,
     203,   206,     4,   193,   194,   492,   493,  1766,   203,   667,
     205,   201,     6,     7,   204,   377,   378,   379,   380,   381,
     382,   744,   384,   385,   197,   387,   388,   389,   390,   391,
     197,   197,   199,   395,   396,   397,   398,   399,   400,   206,
     402,   197,   765,   199,     4,   810,  1145,   534,   535,   536,
     206,  1137,  1138,     6,   198,  1702,  1142,  1143,  1705,   203,
     718,  1708,  1161,     8,   197,   197,    99,   199,  1827,   198,
    1829,   200,  1831,   560,   206,   204,   197,   110,  1837,   187,
     188,   189,   190,   191,   198,   118,   119,   120,   196,   203,
     813,   124,   125,   126,   127,    82,   861,    84,   197,   822,
     865,   824,     6,   826,   711,   828,   871,   872,   199,   716,
     833,     8,   198,   197,   200,   838,   603,   203,   197,    99,
     199,  1880,   203,  1882,   205,  1884,   198,   206,   200,   771,
     110,   203,   203,   856,   205,   199,   778,   860,   118,   119,
     120,   864,   784,    99,   124,   125,   126,   127,   197,   872,
      76,   187,   188,    79,   110,   198,    82,   200,    84,     7,
     203,  1808,   118,   119,   120,   203,   197,   205,   124,   125,
     126,   127,   205,   198,   897,   200,   197,   199,   203,   902,
     903,   904,   905,   203,   546,   205,  1152,    82,   197,    84,
    1401,  1402,   203,   916,   205,   918,   197,   197,   963,   964,
    1299,   197,   197,  1289,  1290,   197,   197,  1854,  1294,  1295,
    1857,     8,    76,  1860,   197,    79,  1863,   704,    82,   942,
      84,   708,   945,   946,   947,   948,   203,   203,   205,   205,
     203,     6,   205,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   970,   906,   205,
     204,   196,  1899,   203,  1901,   205,  1903,   203,     6,   205,
     205,   203,   203,   205,   205,   872,   989,   990,   203,   992,
     205,   994,   995,     7,     8,   998,   999,     4,   765,     6,
    1003,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   902,   204,   904,   905,   196,
     203,   203,   205,   205,   204,   197,  1071,  1072,   197,   916,
     197,   918,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   204,  1087,  1088,   197,   196,   813,   203,   203,   205,
     205,   203,     4,   205,   203,   822,   205,   824,   203,   826,
     205,   828,   203,   985,   205,   203,   833,   205,   203,   711,
     205,   838,   714,   203,   716,   205,   203,   203,   205,   205,
     203,   197,   205,   970,   203,   199,   205,  1090,  1091,  1092,
     197,   203,  1338,   205,   203,   203,   205,   205,  1101,   197,
    1145,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,  1037,  1038,  1039,   203,   196,
     205,   203,   203,   205,   205,   197,   197,    99,   197,   203,
     897,   205,   197,   197,  1137,  1138,  1627,     6,   110,  1142,
    1143,   203,   203,   205,   205,   197,   118,   119,   120,  1152,
     204,   204,   124,   125,   126,   127,   203,   203,   205,   205,
     203,   197,   205,  1166,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   945,   946,
     947,   948,   196,     6,   203,  1188,   205,   203,   203,   205,
     205,  1194,   204,   204,   204,   204,   197,  1200,   197,  1202,
    1203,   197,   206,     6,  1207,  1208,     6,  1210,   199,  1212,
     204,  1214,   204,  1216,  1217,  1218,   204,   199,   199,   199,
    1586,     6,     6,   143,     6,   204,     6,     6,   206,     6,
     872,  1234,     6,   205,   204,   204,  1003,   199,     4,   196,
     201,   204,  1180,     7,   203,   205,  1249,   203,     7,     6,
    1253,     6,  1255,     6,   198,     7,  1301,     7,     6,   204,
     902,     7,   904,   905,     6,    54,     7,     6,     6,     6,
       4,    54,   140,    54,   916,   204,   918,   200,    54,   198,
       6,     6,   198,   198,    40,   203,  1289,  1290,   200,   203,
     203,  1294,  1295,   203,   203,   203,   198,   198,   198,     6,
     942,     4,     4,     7,    40,  1308,     6,    40,    40,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     6,     6,  1247,     6,   196,   970,   143,
       7,     7,     7,   143,     7,  1338,     7,   143,     7,     7,
     204,  1344,     4,   198,   203,     6,   198,   203,   198,   203,
    1596,  1354,   198,   201,  1357,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   203,
     205,     6,   205,   196,  1312,   200,   204,   204,   204,     7,
     204,     7,     7,    99,   201,   204,  1431,     6,    40,    40,
    1393,  1394,  1330,   223,   110,    40,    40,     6,     6,  1401,
    1402,  1641,   118,   119,   120,    99,     6,     6,   124,   125,
     126,   127,     6,   199,     7,     6,   110,   247,  1421,  1357,
    1423,  1308,  1425,     6,   118,   119,   120,   197,   197,   204,
     124,   125,   126,   127,   185,     7,    99,  1440,     7,     7,
       7,   271,    84,  1365,  1447,     7,     7,   110,     7,     6,
     204,     7,     7,     7,  1457,   118,   119,   120,  1461,  1397,
       7,   124,   125,   126,   127,     7,     7,  1354,     4,     4,
     197,    82,     6,     6,   204,     7,     6,   205,     7,     7,
       7,  1403,     6,  1405,  1487,  1407,     6,     6,  1255,   205,
      12,    13,     7,     6,     6,  1137,  1138,     4,     4,  1421,
    1142,  1143,  1424,  1425,     4,  1508,   336,   337,  1446,     6,
    1152,   205,     6,     6,     6,     6,     4,     6,   203,   349,
     198,     7,   203,  1461,  1462,  1463,   198,  1767,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   198,
     198,  1544,   205,   196,   201,     6,  1549,   197,   204,     6,
       4,     5,   201,   383,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     6,    87,     6,  1570,   204,    92,
      92,    93,   204,    95,    96,    97,     6,   204,     6,   101,
    1583,   204,     6,  1586,   204,     6,    40,    41,    42,    43,
      44,    45,     6,  1596,     5,    49,    50,    51,    52,     4,
     204,   204,  1605,    57,    58,    59,    12,    13,    62,     6,
     199,     7,   204,   135,   136,   137,   204,     6,  1621,    73,
       6,  1624,     6,     6,   204,  1627,  1393,  1394,   204,   204,
      99,     4,     6,   203,     6,     6,   139,  1640,     6,     6,
       4,   110,  1645,     6,     6,     6,     4,  1289,  1290,   118,
     119,   120,  1294,  1295,     6,   124,   125,   126,   127,     6,
       6,     6,     6,     4,     6,     5,  1308,     6,     6,   143,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       6,    87,     6,   205,     6,     6,    92,    93,  1691,    95,
      96,    97,     6,   204,     6,   101,  1338,     6,     6,     6,
       6,     6,     6,     6,   158,   159,   160,  1710,   203,  1631,
       6,  1633,  1354,  1635,    99,     6,   170,     6,   172,   173,
       6,  1643,     6,     6,  1646,   110,   198,     6,     6,   135,
     136,   137,     6,   118,   119,   120,   205,     6,     6,   124,
     125,   126,   127,     7,   198,     6,   200,     6,   201,   204,
      99,     6,     5,    80,     6,   204,     6,   204,   204,     6,
     205,   110,    99,     6,   205,  1768,   204,  1770,  1690,   118,
     119,   120,  1694,   110,     7,   124,   125,   126,   127,   204,
    1783,   118,   119,   120,   204,     6,     6,   124,   125,   126,
     127,     6,  1730,   205,     6,   138,     6,     6,     6,   205,
       6,     6,     6,  1570,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   141,     6,
     205,  1743,   196,     6,     6,  1747,     6,    12,    13,   204,
       6,   661,     6,     6,    99,   665,  1839,     6,   204,   204,
       6,    88,     6,     6,  1847,   110,   205,   204,  1770,   204,
      99,   204,     6,   118,   119,   120,   205,  1624,     6,   124,
     125,   126,   127,     6,     6,     6,     6,     6,   205,     6,
       6,  1874,   205,     6,   204,   204,   204,     6,  1645,     6,
    1818,     6,     6,     6,   204,     6,     6,   204,  1891,     6,
    1893,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     6,    87,  1825,  1826,    99,   204,    92,    93,   204,
      95,    96,    97,     6,   744,     6,   101,   204,     6,   204,
    1923,     6,     6,     6,     6,     6,     6,     6,   175,   176,
     177,   178,   179,     6,     6,   453,  1175,  1733,  1610,  1187,
     205,     3,  1611,     3,  1586,   192,   483,  1623,  1334,   196,
     135,   136,   137,    -1,  1596,    -1,    -1,    -1,    -1,    -1,
    1847,    -1,    -1,   210,   211,   212,   213,    -1,   215,   216,
     217,   218,    -1,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   245,    -1,
      -1,  1768,   196,  1770,  1891,    -1,  1893,   254,   255,    -1,
      -1,    -1,    -1,    12,    13,    -1,   263,    -1,    -1,    -1,
     205,    -1,    -1,    -1,    -1,    -1,   856,    -1,    -1,    -1,
     860,    -1,    -1,    -1,   864,    -1,  1923,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,
     297,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,   309,   310,    -1,   312,    -1,    -1,    -1,   316,
     317,   318,  1839,   903,   321,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
      -1,   338,   339,    92,    93,    -1,    95,    96,    97,    -1,
      -1,    -1,   101,    -1,    -1,   352,   353,    -1,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   386,
      -1,    -1,    -1,    -1,    -1,   392,    -1,   394,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   989,
     990,    -1,   992,    -1,   994,   995,    -1,    -1,   998,   999,
      -1,   418,   419,    -1,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,    -1,
      -1,   438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1847,   205,    -1,    -1,    -1,
     457,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,   473,   474,    -1,    -1,
      -1,    -1,   479,   480,    -1,    -1,    -1,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,    -1,    -1,  1891,
      -1,  1893,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1090,  1091,  1092,   510,   511,   512,   513,   514,   515,    -1,
      -1,  1101,   519,   520,   521,   522,   523,    -1,    -1,    -1,
     527,  1923,   529,   530,    -1,    -1,    -1,   534,   535,   536,
      -1,    -1,   539,   540,   541,   542,   543,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,    -1,   566,
     567,    -1,   569,   570,    -1,     6,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1166,    -1,    -1,    -1,
      -1,    -1,    -1,   590,   591,    -1,   593,   594,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   602,   603,    -1,  1188,    -1,
     607,    -1,    -1,    -1,  1194,    -1,    -1,    -1,    -1,    -1,
    1200,    -1,  1202,  1203,    -1,    -1,    -1,  1207,  1208,    -1,
    1210,    -1,  1212,    -1,  1214,    -1,  1216,  1217,  1218,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    87,    -1,    -1,  1234,    -1,    92,    93,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,  1249,
      -1,   668,    -1,  1253,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   700,   701,    -1,    -1,   704,   705,   706,
      -1,   708,   709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     717,    -1,    -1,   720,   721,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,   734,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   743,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,  1344,   196,    -1,    -1,   765,   205,
      -1,    -1,    -1,    -1,    -1,   772,   773,  1357,    -1,    -1,
      -1,   778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   791,    -1,    -1,   794,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    92,    93,   813,    95,    96,    97,
      -1,    -1,    -1,   101,    -1,   822,    -1,   824,    -1,   826,
      -1,   828,    -1,    -1,    -1,    -1,   833,    -1,    -1,    -1,
      -1,   838,    -1,  1423,    -1,    -1,    -1,   844,    -1,   846,
     847,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
    1440,    -1,    -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1457,    -1,    -1,
      -1,  1461,    -1,    -1,    -1,    -1,    -1,    -1,   885,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   893,   894,   895,    -1,
     897,    -1,    -1,    12,    13,    -1,    -1,  1487,   211,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,   915,    -1,
      -1,    -1,    -1,   920,   227,    -1,    -1,   205,  1508,    -1,
      -1,    -1,   929,    -1,    -1,    -1,    -1,    -1,   935,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   945,   946,
     947,   948,    -1,    -1,   951,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1544,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
      -1,    12,    13,    92,    93,    -1,    95,    96,    97,    -1,
      -1,    -1,   101,   296,    -1,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1003,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1013,    -1,  1015,    -1,
    1017,    -1,  1019,    -1,    -1,  1605,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,  1621,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    -1,    -1,    -1,
    1640,    92,    93,    -1,    95,    96,    97,    -1,    12,    13,
     101,    -1,    -1,  1070,    -1,    -1,    -1,    -1,  1075,    -1,
    1077,  1078,  1079,    -1,    -1,    -1,    -1,    -1,  1085,    -1,
      -1,    -1,    -1,     6,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,    -1,    -1,
    1107,  1691,    -1,    -1,    -1,  1112,   419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1710,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    96,    97,   457,    -1,  1153,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,  1165,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1179,  1180,    -1,    -1,    -1,    -1,    -1,   492,
     493,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1783,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,  1224,  1225,  1226,
     196,   534,   535,   536,    -1,    -1,    -1,  1234,    -1,  1236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1247,    -1,    -1,    -1,    -1,    -1,    -1,   560,  1255,    -1,
      -1,   205,    -1,  1260,   567,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,  1281,  1282,  1283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1874,    -1,    -1,   108,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    -1,  1331,    -1,    -1,   148,   149,   150,
     151,    -1,    -1,   154,    -1,    -1,    -1,    -1,  1345,   160,
     161,    -1,    -1,  1350,    -1,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,  1363,  1364,    -1,    -1,
      -1,    -1,    -1,  1370,  1371,    -1,    -1,    -1,  1375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1393,  1394,  1395,    -1,
    1397,   704,    -1,    -1,    -1,   708,     4,     5,    -1,    -1,
      -1,    -1,  1409,    -1,    -1,    -1,    -1,   720,   721,    -1,
      -1,    -1,    -1,    -1,  1421,    -1,    -1,    -1,  1425,    -1,
      -1,  1428,    -1,    12,    13,    -1,  1433,  1434,  1435,  1436,
       6,    -1,    40,    41,    42,    43,    44,    45,    -1,  1446,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,   765,    -1,    62,  1462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,   288,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1485,  1486,
      -1,    -1,    -1,    -1,   305,    -1,  1493,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    -1,
     813,    -1,    -1,    92,    93,    -1,    95,    96,    97,   822,
      -1,   824,   101,   826,    -1,   828,    -1,    -1,    -1,    -1,
     833,    -1,  1529,    -1,    -1,   838,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
    1547,    -1,  1549,    -1,   196,    -1,   135,   136,   137,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,  1565,    -1,
    1567,    -1,   170,  1570,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   413,    -1,  1601,    -1,    -1,    -1,    -1,  1606,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   205,  1624,     6,    -1,
     196,    -1,    -1,    -1,  1631,    -1,  1633,    -1,  1635,    -1,
      -1,    -1,   945,   946,   947,   948,    -1,    -1,  1645,    -1,
      -1,    -1,  1649,  1650,  1651,  1652,  1653,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1672,  1673,     6,    -1,    -1,
    1677,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1687,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1003,  1698,    -1,    -1,    -1,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,    -1,   623,   624,   625,
     626,   627,   628,   629,    -1,    -1,    -1,   633,   634,   635,
      -1,  1728,    -1,    -1,    -1,    -1,  1733,   643,   644,   645,
      -1,   647,    -1,  1740,    -1,    -1,    -1,    -1,   654,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,    -1,
    1757,    -1,    -1,  1760,    -1,    -1,   672,  1764,    -1,    -1,
      -1,  1768,    -1,  1770,  1771,  1772,  1773,  1774,    -1,    -1,
      -1,    -1,    -1,    -1,  1781,    -1,    -1,  1784,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1824,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1839,    -1,  1841,  1842,  1843,  1844,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1877,  1878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1887,  1888,  1889,  1890,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,  1255,    57,    58,    59,    -1,    -1,    62,    -1,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,    73,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,   950,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,    -1,   172,   173,
      -1,    -1,    -1,    -1,    -1,     6,    -1,   983,   984,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
    1393,  1394,    -1,   197,    -1,   199,    -1,   201,   202,    -1,
     204,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,   925,   926,    -1,    -1,  1421,    -1,
     931,   932,  1425,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,
      -1,   204,     6,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,
      -1,    -1,    -1,    -1,    -1,  1121,  1122,  1123,  1124,  1125,
       6,    -1,    -1,    -1,    -1,  1131,  1132,    -1,    -1,  1135,
    1136,  1137,   135,   136,   137,    -1,  1142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1549,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,  1570,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1104,  1105,    -1,    -1,    -1,  1109,  1110,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1624,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,  1645,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,  1265,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1289,     6,    -1,    -1,    -1,  1294,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1324,  1325,
      -1,    -1,  1328,  1329,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,  1768,    -1,  1770,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,  1839,   115,    -1,    -1,
      -1,    -1,    -1,    -1,  1450,  1451,    -1,    -1,  1454,  1455,
      -1,    -1,    -1,    -1,  1460,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       7,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,    -1,     3,     4,   202,    -1,   204,   205,     9,    10,
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
      -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,     8,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,   202,    -1,    -1,   205,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,   112,    -1,    -1,   115,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     8,    -1,    -1,    -1,   196,    -1,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
      -1,     3,     4,     5,   202,    -1,   204,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      82,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,     5,
     202,    -1,   204,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    -1,     3,     4,     5,    -1,    72,    73,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,    -1,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,   202,    -1,   204,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,
       5,   202,    -1,   204,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,     4,     5,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,   157,    -1,    62,    -1,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    73,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,   197,    -1,     3,     4,     5,   202,    -1,   204,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
     158,   159,   160,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,   170,    72,   172,   173,    -1,    76,    -1,    -1,
      79,     4,     5,    82,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
       3,     4,    -1,   202,    -1,   204,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,   170,    -1,   172,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    79,    -1,     5,    82,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,   197,    -1,     3,     4,    -1,   202,
      -1,   204,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,   170,    -1,   172,    53,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    82,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
     197,    -1,     3,     4,    -1,   202,    -1,   204,     9,    10,
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
      -1,   112,    -1,    -1,   115,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,   197,    -1,     3,     4,
      -1,   202,    -1,   204,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    82,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,
     115,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,   197,    -1,     3,     4,    -1,   202,    -1,   204,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
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
      -1,    -1,   203,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,    -1,
       3,     4,    -1,   202,    -1,   204,     9,    10,    11,    -1,
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
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,   202,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,    -1,     3,     4,     5,   202,    -1,
     204,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    72,    73,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   205,    -1,    -1,   165,   166,   167,
     168,   169,   170,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,     3,     4,    -1,    -1,   197,
      -1,     9,    10,    11,   202,    -1,    14,    15,    16,    17,
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
     188,    -1,    -1,    -1,   192,     3,     4,    -1,    -1,   197,
      -1,     9,    10,    11,   202,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    64,    65,    66,    -1,
       9,    10,    11,    -1,    72,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,   205,    -1,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,    -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,   197,     3,
       4,   200,    -1,   202,    -1,     9,    10,    11,    -1,    -1,
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
      -1,    -1,    -1,   157,    -1,   205,    -1,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,    -1,    -1,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
      -1,    -1,   197,     3,     4,   200,    -1,   202,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,    -1,
      -1,    -1,   192,    -1,    54,    55,    56,   197,    -1,    -1,
      60,    61,   202,    63,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,     4,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    12,    13,   134,   135,   136,   137,    -1,    -1,
     140,    -1,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,    38,    39,
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,    54,    55,    56,    -1,    -1,    -1,
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
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,   178,   179,   180,   181,   182,   183,
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
      -1,    -1,   204,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,    -1,
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
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196
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
     229,   198,     7,   174,   229,   200,   286,   295,     6,     6,
     286,   198,   200,   230,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   203,   232,   232,   232,   232,
     232,   232,   232,   203,   203,   203,   232,   203,   232,   232,
     198,   198,   203,   203,   203,   203,   203,   232,   232,   232,
     198,   232,   288,   301,     6,   203,   203,   198,   203,   232,
     203,   232,   198,   198,   200,    40,    40,   292,     7,   229,
     230,    40,    40,   292,   201,   229,   230,   300,   286,     6,
       4,     4,   204,   297,   232,   204,   204,   204,   204,   205,
     205,     8,     4,   130,   131,   132,   133,   205,   217,   221,
     224,   226,   227,   198,   200,   286,   286,     4,     6,   185,
     211,   295,   286,   286,     6,   295,   286,     6,   299,     6,
     304,     6,   299,   286,   300,     7,   286,   294,   143,     7,
       7,   198,     7,   143,     7,     7,   198,   143,     7,     7,
     286,   198,   205,   204,   198,   198,   286,   292,     4,   278,
       6,   198,   198,   203,   198,   203,   198,   203,   198,   203,
     198,   198,   198,   205,   205,   295,   201,   253,   205,   205,
     289,   286,   286,   205,   205,   286,   289,   203,   203,   203,
      99,   110,   118,   119,   120,   124,   125,   126,   127,   275,
     276,   289,   205,   262,   198,   205,   198,   198,   198,   286,
       6,   286,   198,   200,   200,   205,   205,   205,   200,   200,
     203,   198,   200,   295,   200,   204,   205,   204,   204,   204,
     295,   295,   295,   295,   205,     8,   295,   198,   200,   295,
       7,     7,     7,   201,   286,   205,   286,   286,     7,   201,
     205,   204,   292,     6,    40,    40,   292,   229,   230,    40,
      40,   292,   229,   230,   205,   205,   200,   230,   201,   230,
     299,   286,   286,   286,   286,   295,   299,   292,   299,   299,
     300,   240,   242,   286,   299,   299,   286,   231,   231,     6,
     286,     6,   231,   231,     6,     4,   140,   141,   286,     6,
       6,     6,     7,   199,   296,   298,     6,   295,   295,   295,
     295,   232,   286,   218,   197,   197,   204,   228,     6,   230,
     230,   198,   200,   185,   299,   198,   198,   200,   198,   203,
       7,   232,   232,   289,    82,    84,   292,   292,     7,   292,
      82,    84,   292,   292,     7,    84,   292,   292,     6,     7,
       7,   295,     7,     7,    99,   277,     6,     7,   229,   286,
     229,   286,   229,   286,   229,   286,     7,     7,     7,     7,
       7,   205,     4,   205,   203,   203,   203,   205,   205,   289,
     289,   289,     4,     6,   204,     6,   197,     6,   128,     6,
     128,     6,   128,     6,   128,   205,   276,   203,   275,     7,
       6,     7,     7,     7,     6,   204,     6,     6,     6,    82,
       7,     6,     6,   286,   201,   205,   286,   286,   286,   286,
     205,   205,   205,   205,   286,   205,   205,   292,   292,   292,
       4,   203,     8,     8,   198,     4,     4,   292,   205,   231,
     231,     6,   286,     6,   231,   231,     6,   286,     6,   232,
       6,     4,     6,   232,   232,   232,   232,   232,   203,   198,
     198,   198,   203,   203,   232,   241,   203,   232,   243,   198,
     198,   232,   232,   232,   302,   302,     6,   232,   302,   302,
       7,   229,   230,   201,     7,     6,   296,   286,   203,   205,
     205,   205,   205,   205,   229,   197,   286,   286,   291,   292,
     204,   201,     6,     6,   211,     6,   286,   204,   286,   300,
       6,     6,     6,   204,   204,    92,   249,   249,   292,     6,
     204,   204,     6,     6,   292,   204,     6,     6,     5,   292,
     205,   292,   292,     4,     6,   292,   292,   292,   292,   292,
     292,   292,   292,   204,   204,     7,     6,     7,   286,   286,
     286,   204,   204,   203,   205,   203,   205,   203,   205,   199,
     286,   292,   286,     6,     6,     6,     6,   286,   289,   205,
       5,   204,   292,   204,   204,   204,   292,   295,   204,   286,
     200,     4,   232,   203,   203,   203,   203,   232,     6,     6,
     139,   286,   286,   286,     6,     6,     7,   203,     6,   232,
     302,   302,     6,   232,   302,   302,     6,   229,   230,   299,
     300,     4,     4,   154,     6,   232,   232,     6,   232,   232,
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
     204,   286,   300,   292,     6,   232,   232,     6,   232,   232,
     292,   198,   232,   204,   292,   300,   204,   286,   300,   300,
       6,     6,     6,     6,     6,     6,     7,     6,   201,     6,
     198,   203,   286,   286,   292,   204,   203,   205,     6,   286,
     236,   237,   205,   205,   205,   205,   205,     5,   291,    80,
       6,   204,   205,   205,   204,     6,     6,   204,   286,   205,
     205,   203,   204,   203,   204,   203,   204,   200,     6,   292,
       7,   204,   286,   203,   205,   203,   203,     6,   205,   203,
     203,   203,   203,   138,   286,   286,   295,     6,     6,   205,
       6,     6,     6,     6,     6,   239,   286,   302,   296,   141,
     219,   286,   203,   203,   291,   286,     6,   203,   240,   242,
       6,     6,     6,     6,     6,     6,   205,   204,   291,   103,
     104,   109,   281,   103,   104,   281,   295,   252,   203,   205,
     286,   289,   275,   286,   289,   275,   286,   289,   275,     6,
     203,   205,   292,   253,   205,   289,     6,   295,   289,   286,
     286,   286,   286,   286,   205,   205,   205,     6,   203,   205,
       7,   205,     6,   204,   286,   286,   205,   286,   205,   205,
     204,   286,   205,   204,   289,   292,     6,   204,   289,     6,
     205,   205,   286,   205,   203,   205,   205,   203,   205,   205,
     203,   205,   292,     6,    99,   205,   263,   204,   203,   205,
     203,   203,   203,   203,   203,     6,     6,   286,   300,   216,
     198,   203,     6,   204,   203,   286,   205,     6,   289,     6,
     289,     6,     6,   205,     6,   269,   286,     6,     6,   270,
     286,     6,     6,   271,   286,     6,   205,   286,   275,   253,
     295,     6,   289,   295,   286,   286,   286,   286,     7,   205,
     222,   286,   291,   286,   203,   203,   203,   204,   205,   204,
     205,   204,   205,     6,     6,   205,   205,   264,   205,   203,
     205,   203,   203,   203,   203,   300,     6,   204,   198,   205,
     205,   286,   289,   289,   275,     6,   272,   275,     6,   273,
     275,     6,   274,   275,     6,   295,     6,   286,   286,   286,
     286,   220,   299,   225,   204,     6,   205,   203,   203,   205,
     204,   205,   204,   205,   204,   205,   205,   203,   203,   203,
     203,   203,   205,   204,   291,     6,   286,   286,     6,   275,
       6,   275,     6,   275,     6,   286,   286,   286,   286,   299,
       6,   223,   299,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   203,   205,     6,     6,     6,     6,     6,
       6,   299,     6
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
     233,   234,   234,   235,   235,   235,   236,   235,   235,   237,
     235,   238,   238,   239,   239,   240,   240,   241,   241,   241,
     242,   242,   243,   243,   243,   243,   244,   244,   244,   245,
     245,   245,   246,   246,   246,   247,   247,   247,   248,   248,
     249,   249,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   251,   251,   251,   251,   251,   251,   251,   251,   252,
     252,   253,   253,   253,   253,   253,   253,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   256,   256,   257,   258,   258,   258,   258,   258,   258,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   261,   262,   261,   263,   261,
     264,   261,   265,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   266,   261,   267,   261,   268,   261,   269,
     261,   270,   261,   271,   261,   272,   261,   273,   261,   274,
     261,   275,   275,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   280,   281,   281,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   283,   283,   283,   284,   284,   284,
     285,   285,   285,   285,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   288,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   289,   289,   289,   289,   289,   290,   290,
     290,   290,   291,   291,   292,   292,   292,   292,   292,   292,
     293,   293,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   295,   295,   295,   296,   296,   296,   296,   297,   297,
     298,   298,   299,   299,   299,   299,   299,   299,   299,   299,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   301,   300,   302,   302,   303,   303,   304,   304,
     304
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
#line 198 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4665 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4677 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4707 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4777 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4795 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4812 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4829 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4856 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4874 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4891 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4908 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 376 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 390 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 397 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 399 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4961 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5069 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 518 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 527 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5104 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 534 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5115 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 553 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 562 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5160 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 587 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5182 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5202 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 641 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5257 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5263 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 656 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 657 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 678 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5324 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5390 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5409 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 792 "Gmsh.y" /* yacc.c:1646  */
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
#line 5475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 821 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 826 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 831 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 836 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 841 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 848 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5533 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 887 "Gmsh.y" /* yacc.c:1646  */
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
#line 5599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 916 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 921 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 926 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 931 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 939 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 948 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 954 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 960 "Gmsh.y" /* yacc.c:1646  */
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
#line 5679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 973 "Gmsh.y" /* yacc.c:1646  */
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
#line 5695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 986 "Gmsh.y" /* yacc.c:1646  */
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
#line 5713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1001 "Gmsh.y" /* yacc.c:1646  */
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
#line 5731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1018 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1024 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1030 "Gmsh.y" /* yacc.c:1646  */
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
#line 5765 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1043 "Gmsh.y" /* yacc.c:1646  */
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
#line 5781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1056 "Gmsh.y" /* yacc.c:1646  */
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
#line 5799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1071 "Gmsh.y" /* yacc.c:1646  */
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
#line 5817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1088 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1094 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1103 "Gmsh.y" /* yacc.c:1646  */
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
#line 5859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1121 "Gmsh.y" /* yacc.c:1646  */
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
#line 5881 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1139 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1148 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1160 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1165 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1173 "Gmsh.y" /* yacc.c:1646  */
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
#line 5949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1193 "Gmsh.y" /* yacc.c:1646  */
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
#line 5973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1216 "Gmsh.y" /* yacc.c:1646  */
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
#line 5988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1227 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 6000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1235 "Gmsh.y" /* yacc.c:1646  */
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
#line 6026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1257 "Gmsh.y" /* yacc.c:1646  */
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
#line 6053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1280 "Gmsh.y" /* yacc.c:1646  */
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
#line 6083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1306 "Gmsh.y" /* yacc.c:1646  */
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
#line 6105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1327 "Gmsh.y" /* yacc.c:1646  */
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
#line 6121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1339 "Gmsh.y" /* yacc.c:1646  */
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
#line 6137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1357 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 6150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1366 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 6163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1375 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6169 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1377 "Gmsh.y" /* yacc.c:1646  */
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
#line 6189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1393 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1402 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1404 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1418 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1426 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1432 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1444 "Gmsh.y" /* yacc.c:1646  */
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
#line 6266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1455 "Gmsh.y" /* yacc.c:1646  */
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
#line 6284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1470 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1486 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1494 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1503 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1511 "Gmsh.y" /* yacc.c:1646  */
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
#line 6347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1529 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1533 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1539 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1547 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1551 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1557 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1565 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1569 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1575 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1583 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1587 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6446 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1593 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1601 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1605 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6477 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1617 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1621 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1631 "Gmsh.y" /* yacc.c:1646  */
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
#line 6520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1654 "Gmsh.y" /* yacc.c:1646  */
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
#line 6564 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1694 "Gmsh.y" /* yacc.c:1646  */
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
#line 6588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1717 "Gmsh.y" /* yacc.c:1646  */
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
#line 6610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1735 "Gmsh.y" /* yacc.c:1646  */
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
#line 6635 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1756 "Gmsh.y" /* yacc.c:1646  */
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
#line 6657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1774 "Gmsh.y" /* yacc.c:1646  */
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
#line 6691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1804 "Gmsh.y" /* yacc.c:1646  */
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
#line 6725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1834 "Gmsh.y" /* yacc.c:1646  */
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
#line 6747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1852 "Gmsh.y" /* yacc.c:1646  */
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
#line 6769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1871 "Gmsh.y" /* yacc.c:1646  */
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
#line 6799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1897 "Gmsh.y" /* yacc.c:1646  */
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
#line 6821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1915 "Gmsh.y" /* yacc.c:1646  */
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
#line 6843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1933 "Gmsh.y" /* yacc.c:1646  */
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
#line 6887 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1976 "Gmsh.y" /* yacc.c:1646  */
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
#line 6909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1994 "Gmsh.y" /* yacc.c:1646  */
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
#line 6952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2033 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6962 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2039 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2045 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2052 "Gmsh.y" /* yacc.c:1646  */
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
#line 7012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2077 "Gmsh.y" /* yacc.c:1646  */
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
#line 7041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2102 "Gmsh.y" /* yacc.c:1646  */
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
#line 7062 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2119 "Gmsh.y" /* yacc.c:1646  */
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
#line 7085 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2139 "Gmsh.y" /* yacc.c:1646  */
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
#line 7122 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2172 "Gmsh.y" /* yacc.c:1646  */
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
#line 7166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2216 "Gmsh.y" /* yacc.c:1646  */
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
#line 7188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2234 "Gmsh.y" /* yacc.c:1646  */
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
#line 7209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2251 "Gmsh.y" /* yacc.c:1646  */
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
#line 7229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2267 "Gmsh.y" /* yacc.c:1646  */
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
#line 7273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2312 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2317 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2322 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2327 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2332 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2337 "Gmsh.y" /* yacc.c:1646  */
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
#line 7345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2366 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2376 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2377 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2382 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2386 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2390 "Gmsh.y" /* yacc.c:1646  */
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
#line 7422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2413 "Gmsh.y" /* yacc.c:1646  */
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
#line 7449 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2436 "Gmsh.y" /* yacc.c:1646  */
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
#line 7476 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2459 "Gmsh.y" /* yacc.c:1646  */
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
#line 7503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2487 "Gmsh.y" /* yacc.c:1646  */
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
#line 7528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2508 "Gmsh.y" /* yacc.c:1646  */
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
#line 7558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2535 "Gmsh.y" /* yacc.c:1646  */
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
#line 7582 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2556 "Gmsh.y" /* yacc.c:1646  */
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
#line 7607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2577 "Gmsh.y" /* yacc.c:1646  */
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
#line 7631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2597 "Gmsh.y" /* yacc.c:1646  */
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
#line 7747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2709 "Gmsh.y" /* yacc.c:1646  */
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
#line 7770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2728 "Gmsh.y" /* yacc.c:1646  */
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
#line 7812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2767 "Gmsh.y" /* yacc.c:1646  */
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
#line 7919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2875 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2884 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2890 "Gmsh.y" /* yacc.c:1646  */
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
#line 7961 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2905 "Gmsh.y" /* yacc.c:1646  */
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
#line 7993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2933 "Gmsh.y" /* yacc.c:1646  */
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
#line 8009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2950 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8022 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2959 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2973 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2987 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2993 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8068 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2999 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 3008 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3017 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3026 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3040 "Gmsh.y" /* yacc.c:1646  */
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
#line 8183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3099 "Gmsh.y" /* yacc.c:1646  */
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
#line 8205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3117 "Gmsh.y" /* yacc.c:1646  */
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
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3134 "Gmsh.y" /* yacc.c:1646  */
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
#line 8245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3149 "Gmsh.y" /* yacc.c:1646  */
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
#line 8275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3175 "Gmsh.y" /* yacc.c:1646  */
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
#line 8291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3187 "Gmsh.y" /* yacc.c:1646  */
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
#line 8319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3211 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3215 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3220 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3227 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3232 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3238 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3243 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3249 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3257 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3261 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3265 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3271 "Gmsh.y" /* yacc.c:1646  */
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
#line 8480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3330 "Gmsh.y" /* yacc.c:1646  */
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
#line 8501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3347 "Gmsh.y" /* yacc.c:1646  */
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
#line 8522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3364 "Gmsh.y" /* yacc.c:1646  */
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
#line 8548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3386 "Gmsh.y" /* yacc.c:1646  */
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
#line 8574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3408 "Gmsh.y" /* yacc.c:1646  */
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
#line 8613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3443 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3451 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3459 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3465 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8669 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3479 "Gmsh.y" /* yacc.c:1646  */
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
#line 8693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3499 "Gmsh.y" /* yacc.c:1646  */
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
#line 8723 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3525 "Gmsh.y" /* yacc.c:1646  */
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
#line 8739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3537 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3549 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3557 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3565 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3573 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3579 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3587 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3593 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3601 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3607 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8851 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3615 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3621 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8872 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3629 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3636 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3643 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3650 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3657 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3664 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8938 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3671 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3678 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3685 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8971 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3692 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3698 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3705 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9002 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3718 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3724 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3731 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9044 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3737 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9055 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3744 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3750 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3757 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9086 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3763 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3770 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3783 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3789 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9139 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3796 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3802 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3813 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3816 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3822 "Gmsh.y" /* yacc.c:1646  */
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
#line 9190 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3834 "Gmsh.y" /* yacc.c:1646  */
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
#line 9214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3854 "Gmsh.y" /* yacc.c:1646  */
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
#line 9241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3878 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3882 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9257 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3886 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3890 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3894 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9283 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3900 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3906 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9301 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3910 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3914 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3918 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3922 "Gmsh.y" /* yacc.c:1646  */
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
#line 9348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3941 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3953 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3957 "Gmsh.y" /* yacc.c:1646  */
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
#line 9385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3972 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9393 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3976 "Gmsh.y" /* yacc.c:1646  */
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
#line 9411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 3992 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 3996 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9427 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4001 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4005 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4011 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4015 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4022 "Gmsh.y" /* yacc.c:1646  */
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
#line 9519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4078 "Gmsh.y" /* yacc.c:1646  */
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
#line 9593 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4148 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4153 "Gmsh.y" /* yacc.c:1646  */
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
#line 9673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4220 "Gmsh.y" /* yacc.c:1646  */
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
#line 9713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4256 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4264 "Gmsh.y" /* yacc.c:1646  */
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
#line 9772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4307 "Gmsh.y" /* yacc.c:1646  */
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
#line 9815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4346 "Gmsh.y" /* yacc.c:1646  */
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
#line 9839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4367 "Gmsh.y" /* yacc.c:1646  */
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
#line 9874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4399 "Gmsh.y" /* yacc.c:1646  */
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
#line 9904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4426 "Gmsh.y" /* yacc.c:1646  */
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
#line 9933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4452 "Gmsh.y" /* yacc.c:1646  */
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
#line 9962 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4478 "Gmsh.y" /* yacc.c:1646  */
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
#line 9991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4504 "Gmsh.y" /* yacc.c:1646  */
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
#line 10020 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4530 "Gmsh.y" /* yacc.c:1646  */
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
#line 10045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4551 "Gmsh.y" /* yacc.c:1646  */
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
#line 10077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4579 "Gmsh.y" /* yacc.c:1646  */
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
#line 10109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4611 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4615 "Gmsh.y" /* yacc.c:1646  */
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
#line 10157 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
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
#line 10200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
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
#line 10243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4721 "Gmsh.y" /* yacc.c:1646  */
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
#line 10268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4742 "Gmsh.y" /* yacc.c:1646  */
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
#line 10293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4763 "Gmsh.y" /* yacc.c:1646  */
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
#line 10318 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4790 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4794 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4804 "Gmsh.y" /* yacc.c:1646  */
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
#line 10374 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4838 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4839 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4840 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4845 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4851 "Gmsh.y" /* yacc.c:1646  */
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
#line 10418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4863 "Gmsh.y" /* yacc.c:1646  */
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
#line 10440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4881 "Gmsh.y" /* yacc.c:1646  */
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
#line 10467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4908 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10473 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4909 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4910 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4911 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10491 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4912 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4913 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4914 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4915 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4917 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4923 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4924 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4926 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4927 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4928 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10562 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4929 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4930 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4931 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4932 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4933 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4934 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4935 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4936 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4937 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4938 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4939 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4940 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4941 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4942 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4943 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4944 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10664 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4947 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4948 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4949 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10688 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4950 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4951 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4952 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4953 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4954 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4955 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4964 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4965 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4966 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4967 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4968 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4969 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4970 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4971 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4972 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4973 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4974 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4979 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4987 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4992 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4997 "Gmsh.y" /* yacc.c:1646  */
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
#line 10845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5014 "Gmsh.y" /* yacc.c:1646  */
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
#line 10867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
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
#line 10889 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5050 "Gmsh.y" /* yacc.c:1646  */
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
#line 10911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5068 "Gmsh.y" /* yacc.c:1646  */
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
#line 10933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5086 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5091 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5097 "Gmsh.y" /* yacc.c:1646  */
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
#line 10971 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5112 "Gmsh.y" /* yacc.c:1646  */
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
#line 10992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5129 "Gmsh.y" /* yacc.c:1646  */
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
#line 11014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
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
#line 11036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5165 "Gmsh.y" /* yacc.c:1646  */
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
#line 11058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5183 "Gmsh.y" /* yacc.c:1646  */
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
#line 11080 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5204 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5209 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11098 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5214 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11112 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5224 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5234 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11135 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5239 "Gmsh.y" /* yacc.c:1646  */
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
#line 11150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5250 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5259 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5264 "Gmsh.y" /* yacc.c:1646  */
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
#line 11200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5291 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5295 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11216 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5299 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11224 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5303 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5307 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5314 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5318 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5322 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5326 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5333 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5338 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5345 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5350 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5354 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11315 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5359 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5363 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5371 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5382 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5386 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5398 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5406 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5414 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5421 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11417 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5431 "Gmsh.y" /* yacc.c:1646  */
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
#line 11450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5460 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5464 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11474 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5476 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11490 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5480 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5484 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11506 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5488 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5492 "Gmsh.y" /* yacc.c:1646  */
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
#line 11547 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5521 "Gmsh.y" /* yacc.c:1646  */
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
#line 11580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5550 "Gmsh.y" /* yacc.c:1646  */
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
#line 11613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5579 "Gmsh.y" /* yacc.c:1646  */
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
#line 11646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5609 "Gmsh.y" /* yacc.c:1646  */
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
#line 11662 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5622 "Gmsh.y" /* yacc.c:1646  */
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
#line 11678 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5635 "Gmsh.y" /* yacc.c:1646  */
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
#line 11694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5648 "Gmsh.y" /* yacc.c:1646  */
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
#line 11710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5660 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5670 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5680 "Gmsh.y" /* yacc.c:1646  */
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
#line 11754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5692 "Gmsh.y" /* yacc.c:1646  */
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
#line 11770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5705 "Gmsh.y" /* yacc.c:1646  */
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
#line 11786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5717 "Gmsh.y" /* yacc.c:1646  */
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
#line 11808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5735 "Gmsh.y" /* yacc.c:1646  */
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
#line 11830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5756 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5761 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5765 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5769 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5781 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5785 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11884 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5797 "Gmsh.y" /* yacc.c:1646  */
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
#line 11905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5814 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5824 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5828 "Gmsh.y" /* yacc.c:1646  */
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
#line 11940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5843 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5848 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5855 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11965 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5859 "Gmsh.y" /* yacc.c:1646  */
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
#line 11982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5872 "Gmsh.y" /* yacc.c:1646  */
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
#line 12000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5886 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12007 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5889 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5892 "Gmsh.y" /* yacc.c:1646  */
    {      //FIXME
    }
#line 12021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5895 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5903 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5914 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5918 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5922 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5930 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5936 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5942 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5950 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5958 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5965 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5973 "Gmsh.y" /* yacc.c:1646  */
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
#line 12159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5988 "Gmsh.y" /* yacc.c:1646  */
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
#line 12177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6002 "Gmsh.y" /* yacc.c:1646  */
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
#line 12195 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6016 "Gmsh.y" /* yacc.c:1646  */
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
#line 12211 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6028 "Gmsh.y" /* yacc.c:1646  */
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
#line 12231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6044 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6053 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12257 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6062 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6072 "Gmsh.y" /* yacc.c:1646  */
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
#line 12286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6083 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6087 "Gmsh.y" /* yacc.c:1646  */
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
#line 12317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6106 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6113 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6119 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6121 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6132 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6137 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12371 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6143 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6152 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6165 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6168 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12407 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6172 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12417 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6175 "Gmsh.y" /* yacc.c:1906  */


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
