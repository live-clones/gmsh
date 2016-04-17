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
char  *strsave(char *ptr);

struct doubleXstring{
  double d;
  char *s;
};


#line 183 "Gmsh.tab.cpp" /* yacc.c:339  */

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
#line 110 "Gmsh.y" /* yacc.c:355  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;

#line 422 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 439 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   12402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  555
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1984

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
       0,   199,   199,   200,   205,   207,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   230,   234,   241,   246,   251,   265,   278,   291,
     319,   333,   346,   359,   378,   383,   384,   385,   386,   387,
     391,   393,   398,   400,   406,   510,   405,   528,   535,   546,
     545,   563,   570,   581,   580,   597,   614,   637,   636,   650,
     651,   652,   653,   654,   658,   659,   665,   665,   666,   666,
     672,   673,   674,   679,   685,   747,   764,   793,   822,   827,
     832,   837,   842,   849,   859,   888,   917,   922,   927,   932,
     940,   949,   955,   961,   974,   987,  1002,  1019,  1025,  1031,
    1044,  1057,  1072,  1089,  1095,  1104,  1122,  1140,  1149,  1161,
    1166,  1174,  1194,  1217,  1228,  1236,  1258,  1281,  1307,  1328,
    1340,  1354,  1354,  1356,  1358,  1367,  1377,  1376,  1397,  1396,
    1415,  1414,  1432,  1442,  1441,  1455,  1457,  1465,  1471,  1476,
    1502,  1503,  1507,  1518,  1533,  1543,  1544,  1549,  1557,  1566,
    1574,  1592,  1596,  1602,  1610,  1614,  1620,  1628,  1632,  1638,
    1646,  1650,  1656,  1665,  1668,  1681,  1684,  1694,  1717,  1760,
    1783,  1801,  1822,  1840,  1870,  1900,  1918,  1936,  1963,  1982,
    1987,  2005,  2051,  2069,  2108,  2114,  2120,  2127,  2152,  2177,
    2194,  2198,  2217,  2251,  2298,  2316,  2333,  2337,  2353,  2401,
    2406,  2411,  2416,  2421,  2426,  2449,  2455,  2466,  2467,  2472,
    2475,  2479,  2502,  2525,  2548,  2576,  2597,  2623,  2644,  2666,
    2686,  2798,  2817,  2855,  2964,  2973,  2979,  2994,  3022,  3039,
    3048,  3062,  3076,  3082,  3088,  3097,  3106,  3115,  3129,  3188,
    3206,  3223,  3238,  3264,  3276,  3300,  3304,  3309,  3316,  3321,
    3327,  3332,  3338,  3346,  3350,  3354,  3359,  3419,  3436,  3453,
    3475,  3497,  3532,  3540,  3548,  3554,  3561,  3568,  3588,  3614,
    3626,  3638,  3646,  3654,  3663,  3662,  3677,  3676,  3691,  3690,
    3705,  3704,  3718,  3725,  3732,  3739,  3746,  3753,  3760,  3767,
    3774,  3782,  3781,  3795,  3794,  3808,  3807,  3821,  3820,  3834,
    3833,  3847,  3846,  3860,  3859,  3873,  3872,  3886,  3885,  3902,
    3905,  3911,  3923,  3943,  3967,  3971,  3975,  3979,  3983,  3987,
    3993,  3999,  4003,  4007,  4011,  4015,  4034,  4047,  4050,  4066,
    4069,  4086,  4089,  4095,  4098,  4105,  4108,  4115,  4171,  4241,
    4246,  4313,  4349,  4357,  4400,  4439,  4459,  4491,  4518,  4544,
    4570,  4596,  4622,  4644,  4672,  4700,  4704,  4708,  4736,  4775,
    4814,  4835,  4856,  4883,  4887,  4897,  4932,  4933,  4934,  4938,
    4944,  4956,  4974,  5002,  5003,  5004,  5005,  5006,  5007,  5008,
    5009,  5010,  5017,  5018,  5019,  5020,  5021,  5022,  5023,  5024,
    5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,
    5035,  5036,  5037,  5038,  5039,  5040,  5041,  5042,  5043,  5044,
    5045,  5046,  5047,  5048,  5049,  5058,  5059,  5060,  5061,  5062,
    5063,  5064,  5065,  5066,  5067,  5068,  5073,  5072,  5080,  5085,
    5090,  5107,  5125,  5143,  5161,  5179,  5184,  5190,  5205,  5222,
    5240,  5258,  5276,  5297,  5302,  5307,  5317,  5327,  5332,  5343,
    5352,  5357,  5384,  5388,  5392,  5396,  5400,  5407,  5411,  5415,
    5419,  5426,  5431,  5438,  5443,  5447,  5452,  5456,  5464,  5475,
    5479,  5491,  5499,  5507,  5514,  5524,  5553,  5557,  5561,  5565,
    5569,  5573,  5577,  5581,  5585,  5614,  5643,  5672,  5701,  5714,
    5727,  5740,  5753,  5763,  5773,  5785,  5798,  5810,  5814,  5818,
    5822,  5826,  5844,  5865,  5870,  5874,  5878,  5890,  5894,  5906,
    5923,  5933,  5937,  5952,  5957,  5964,  5968,  5981,  5995,  6009,
    6023,  6037,  6045,  6056,  6060,  6064,  6072,  6078,  6084,  6092,
    6100,  6107,  6115,  6130,  6144,  6158,  6170,  6186,  6195,  6204,
    6214,  6225,  6229,  6248,  6255,  6261,  6268,  6276,  6275,  6288,
    6293,  6299,  6308,  6321,  6324,  6328
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

#define YYPACT_NINF -1620

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1620)))

#define YYTABLE_NINF -523

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    9182,    34,    58,  9304, -1620, -1620,  3998,    56,   -60,  -124,
     -84,    44,   120,   130,   297,   314,    68,   396,   400,   -98,
     194,  -113,  -113,  -153,   215,   226,    17,   236,   278,    24,
     292,   310,   359,   462,   465,   526,   382,   414,   513,   543,
     545,   544,   514,   688,   337,   468,   566,   -40,   496,   -92,
     -92,   527,   381,    22,   449,   668,   686,    29,    53,   713,
     723,   422,   806,   820,   834,  5639,   843,   634,   635,   652,
      37,     2, -1620,   661,   670, -1620, -1620,   867,   875,   655,
   -1620,  5518,  5915,    -4,    12, -1620, -1620, -1620,  9042,   681,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620,    45, -1620,    97,    98,
   -1620,     6, -1620, -1620, -1620, -1620, -1620,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,   689,   694,   700,  -113,  -113,   707,   712,   716,
    -113,  -113,  -113,  -113,   720, -1620,  -113, -1620, -1620, -1620,
   -1620, -1620,  -113,  -113,   903,   724,   725,   732,  -113,  -113,
     738,   743, -1620, -1620, -1620, -1620,   750,  9042,  9042,  9042,
    8465,  8526,    27,    28,   305,   754,   755,   175, -1620,   773,
     951,   141,  -130,   982,  9042,  5722,  5722, -1620,  9042, -1620,
   -1620, -1620, -1620,  5722, -1620, -1620, -1620, -1620, -1620, -1620,
    6113,    28,  9042,  8273,  9042,  9042,   786,  9042,  8273,  9042,
    9042,   790,  8273,  9042,  9042,  6035,   805,   799, -1620,  8273,
    5639,  5639,  5639,   811,   814,  5639,  5639,  5639,   815,   832,
     851,   863,   892,  6233,  6431,  6629,   837,  1688,  1024,  6035,
      37,   886,   889,   -92,   -92,   -92,  9042,  9042,  -129, -1620,
    -116,   -92,   899,   914,   925,  8015,   -69,  -150,   942,   949,
     958,  5639,  5639,  6035,   962,     5,   959, -1620,   957,  1169,
    1173, -1620,  1006,  1007,  1018,  5639,  5639,  1020,  1045,  1049,
     144, -1620,   323,    31,    20,    33,    40,   698,  6827,  9042,
    4575, -1620, -1620,  1832, -1620,  1222, -1620,   538,    91,  1250,
    9042,  9042,  9042,   143,  9042,  1053, -1620,  1117,  9042,  9042,
    9042, -1620, -1620,  9042,  1055,  1259,  1262, -1620, -1620,  1264,
   -1620,  1265, -1620,   463,  5203,   560,  5722, -1620,  6035,  6035,
    8723,  8784,  1063,  1068,  6113, -1620, -1620, -1620, -1620, -1620,
   -1620,  6035,  1272,  1082,  9042,  9042,  1280,  9042,  9042,  9042,
    9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,
    9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  5722,
    5722,  5722,  5722,  5722,  5722,  5722,  5722,  6035,  5722,  5722,
    9042,  5722,  5722,  5722,  5722,  5722,  9042,  6113,  9042,  5722,
    5722,  5722,  5722,  5722,    28,  6113,    28,  1087,  1087,  1087,
     272,  3763,   308,  8490,   112,  1088,  1283,  -113,  1089, -1620,
    1086,  4389,  9042,  8273, -1620,  9042,  9042,  9042,  9042,  9042,
    9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,  9042,
   -1620, -1620,  9042,  9042, -1620, -1620,   430,   504,   355, -1620,
     563, -1620,   363,  9802, -1620,   478,   129,   313,  1093,  1094,
   11343,  8273,  3934, -1620,   340, 11364, 11385,  9042, 11406,   448,
   11427, 11448,  9042,   479, 11469, 11490,  1290,  9042,  9042,   599,
    1294,  1295,  1296,  9042,  9042,  1297,  1298,  1298,  9042,  8081,
    8081,  8081,  8081,  9042,  1300,  9042,  1301,  9042,  1302,  8273,
    8273,  9748,  1110,  1306,  1107, -1620, -1620,   127, -1620, -1620,
    9828,  9854,   -92,   -92,   305,   305,   132,  9042,  9042,  9042,
    8015,  8015,  9042,  4389,   136, -1620,  9042,  9042,  9042,  9042,
    9042,  1307,  1311,  1312,  9042,  1317,  9042,  9042,  1263, -1620,
   -1620,  8273,  8273,  8273,  1318,  1319,  9042,  9042,  9042,  9042,
    9042,  1314,   169,  7025,  7223, -1620,  1270,  9042, -1620,  1271,
   -1620,  1273, -1620,  1279,    32,    39,    42,    43,  8273,  1087,
   -1620, 11511, -1620,   639,  9042,  7421, -1620,  9042,  9042,   261,
   -1620, 11532, 11553, 11574,  1186,  9880, -1620,  1127,  4027, 11595,
   11616,  8748, -1620, -1620, -1620,  1448, -1620,  2236,  9042,  9042,
   -1620,  9042,  9042,  1138,  1153,   645,   365, 11637,   380, 10998,
    9042,  8273,  1348,  1349, -1620,  9042, 11658, 11021,   -73,  7977,
    7977,  7977,  7977,  7977,  7977,  7977,  7977,  7977,  7977,  7977,
    9906,  7977,  7977,  7977,  7977,  7977,  7977,  7977,  9932,  9958,
    9984,   578,   640,   578,  1156,  1159,  1158,   615,   615,  1163,
    1166,  1167, 10010,   615,   615,   615,   517,   615, 12204, -1620,
    1017,  1168,  1170,  1165,   657,   672,  1174,  1176,  1175,  1339,
    1341,  6035,   123,  1342,  1345,  6035,    77,  6113,  9042,  1380,
    1383,    25,   615, -1620,  -100,    18,    30,   -74, -1620,  2670,
     658,  4046,  1790,  1740,  1369,  1369,   610,   610,   610,   610,
     638,   638,  1087,  1087,  1087,  1087,    64, 11679, 11044, -1620,
    9042,  9042,  1384,     7,  8273,  9042,  9042,  1385,  8273,  9042,
    1386,  5722,  1388, -1620,    28,  1389,  5722,  9042,  6113,  1400,
    8273,  8273,  1245,  1401,  1403, 11700,  1404,  1267,  1406,  1407,
   11721,  1281,  1408,  1409,  9042, 11742,  4718,  1219, -1620, -1620,
   -1620, 11763, 11784,  9042,  6035,  1423,  1425, 11805,  1239, 12204,
    1235,  1241, 12204,  1237,  1246, 12204,  1240,  1248, 12204,  1244,
   11826, -1620, 11847, -1620, 11868, -1620,   673,   702,  8273,  1252,
   -1620, -1620,  2372,  2534,   -92,  9042,  9042, -1620, -1620,  1249,
    1255,  8015, 10036, 10062, 10088,  3806,  1375,   -92,  2817, 11889,
    4916, 11910, 11931, 11952,  9042,  1445, -1620,  9042, 11973, -1620,
   11067, 11090, -1620,   711,   727,   736, -1620, -1620, 11113, 11136,
   10114, 11994, 11159,    91, -1620, -1620,  8273, -1620,  8273,  3934,
    1253,  8273,  1257,   235,  1251,  5344,  1258,  1274,  1275, -1620,
    8273, -1620,  8273, -1620,  8273, -1620,  8273,   751, -1620, -1620,
    4069,  8273,  1087, -1620, 12015, 11182,  8273, -1620,  1456,  1462,
    1470,  1276,  9042,  2932,  9042,  9042, -1620, -1620,     8, -1620,
   -1620,  2959, -1620,  1285,  6035,  1476,  1443,  1446,  6035,   123,
    1453,  1454,  6035,   123,  6171,   763, -1620, -1620, 11205,   248,
     429, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620,  9042, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620,  9042,  9042,  9042, -1620,  8273, -1620, -1620, -1620, -1620,
    5722, -1620, -1620,  6035,  5722,  5722,  6113, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620,  9042,  5722, -1620,  5722, -1620,
    9042, -1620, -1620, -1620, -1620,  -113,  -113,  1479, -1620,  9042,
    1492,  -113,  -113,  1493,   187,  9042,  1494,  1502,  1607, -1620,
    1503,  1313,    37,  1506, -1620,  8273,  8273,  8273,  8273, -1620,
     615,  9042, -1620,  1310,  1320,  1315, -1620,  1507, -1620, -1620,
   -1620, -1620, -1620,   260,   390, 12036, 11228, -1620, -1620,  1329,
    5722,   558, 12057, 11251, -1620,   621, 10140, -1620, -1620, -1620,
      63, -1620, -1620,  7977,   615,   -92,  3934, -1620,   885,  6035,
    6035,  1513,  6035,   890,  6035,  6035,  1515,  1437,  6035,  6035,
    1646,  1517,  1518,  8273,  1529,  1531,  2089, -1620, -1620,  1533,
   -1620,  1537,   397,  9042,   397,  9042,   397,  9042,   397,  9042,
    1541,  1542,  1543,  1545,  1556,   770,  1536,  3179, -1620, -1620,
     204, 10166, 10192, -1620, -1620,  6369,   -94,   -92,   -92,   -92,
    1561,  8981,  1360,  1562,  1374,    49,   162,   180,   275,   553,
   -1620,   227, -1620,  1375,  1567,  1572,  1577,  1581,  1582, 12204,
   -1620,  1906,  1373,  1584,  1589,  1590,  1520,  1594,  1596,  1599,
    9042,    91,   -68,   775,   779, -1620,   822, -1620, -1620,  9042,
   -1620,  9042,  9042,  9042,   829,   830,   844,   849, -1620,  9042,
     850,    91,    91,   853,  6035,  6035,  6035,  1602, 10218, -1620,
    4130,  1481,  1603,  1604, -1620,  6035,  1402, -1620,  -113,  -113,
    1605,  9042,  1606,  -113,  -113,  1608,  9042,  1609, -1620,   615,
    1611, -1620,  1614, -1620,  1615,  7977,  7977,  7977,  7977,   692,
    1405,  1420,  1426,  1427,  1418,   696,   703, 12078,  1428,   615,
    7977,  1092,  5722, -1620,  1951, -1620,  1092,  5722, -1620,   250,
    1422,  1623,  2160, -1620, -1620, -1620,    37,  9042, -1620,   854,
   -1620,   858,   876,   879,   882,   397, 12204,  1432,  9042,  9042,
    6035,  1429, -1620, -1620, -1620, -1620,  1431, -1620,  1626,    74,
   -1620, -1620,  1630,  9042,  5176,  1439,  1435,  1638,  1645,    -2,
    1447,  1451,  1560,  1560,  6035,  1652,  1477,  1478,  1654,  1671,
    6035,  1480,  1676,  1679, -1620,  1682,  6035,   883,  6035,  6035,
    1684,  1683, -1620,  6035,  6035, 12204,  6035, 12204,  6035, 12204,
    6035, 12204,  6035,  6035,  6035,  1484,  1488,  1689,   306, -1620,
    9042,  9042,  9042,  1489,  1495,  -126,  -118,   -96,  1499, -1620,
    2373,  6035, -1620,  9042, -1620,  1719, -1620,  1720, -1620,  1721,
   -1620,  1724, -1620, -1620,  8015,   628,  5837, -1620,  1525,  1526,
    7619, -1620,  8273, -1620, -1620, -1620,  1527,  9042, -1620, -1620,
   11274,  1730,   615,  1535,  1538, 10244, 10270, 10296, 10322, -1620,
   -1620, -1620, -1620, 12204, -1620,   615,  1733,  1735,  1601, -1620,
    9042,  9042,  9042, -1620,  1738,   737,  1540,  1741,  1092,  5722,
   -1620,  2494, -1620,  1092,  5722, -1620,  2743, -1620,   397, -1620,
     438, -1620, -1620, -1620, -1620, -1620, -1620,  5722, -1620, -1620,
   -1620,  6113,  1742, -1620, -1620,    19, -1620, -1620, -1620, -1620,
   -1620, -1620,  1743,   578,   578, -1620,  1744,   578,   578,  6113,
    9042,  1745,  1748,    25, -1620,  1747, 11297,    37, -1620,  1751,
    1752,  1753,  1754,  6035,  9042, 10348, 10374,   893, -1620,  9042,
    1757, -1620, -1620,  5722, -1620, 10400,  4780, 12204, -1620,  1756,
    1758, -1620, -1620, -1620,  9042,  9042,   -92,  1760,  1761,  1762,
   -1620,  9042,  9042, -1620, -1620,  1764,  9042, -1620, -1620,  1759,
    1765,  1566,  1767,  1629,  9042, -1620,  1770,  1771,  1772,  1773,
    1774,  1776,  1100,  1777,  8273,  8273,  9042, -1620,  8081,  6567,
   12099,  4149,   305,   305,   -92,  1778,   -92,  1779,   -92,  1795,
    9042, -1620,   810,  1597, 12120, -1620, -1620, -1620, -1620,  6765,
     234, -1620,  1797,  4348,  1798,  6035,   -92,  4348,  1800,   909,
    9042,  3045,  1801,    91, -1620, -1620, -1620,  9042,  9042,  9042,
    9042, -1620, -1620, -1620,  6035,  4376,   887, 12141, -1620, -1620,
    5243,  6035, -1620,  1802,   578,   578, -1620,  1804,   578,   578,
   -1620,  6035, -1620,  1612,   615,  4978,  5441,  6113, -1620,  1807,
    1808, -1620,  1809,  1810,  1811,  3261, -1620,  1812,  1814, -1620,
    1618, -1620, -1620, -1620, -1620, -1620,  1816,   627, 12204,  9042,
    9042,  6035,  1617,   910, 12204, -1620,  1818,  9042, -1620, -1620,
    1635,  1636,  6963,  7161,   596, -1620, -1620, -1620,  7359,  7557,
   -1620,  7755,  1813, -1620,  6035, -1620,  1763,  1837, 12204, -1620,
   -1620, -1620, -1620, -1620, -1620,  1640, -1620, -1620,   916,   919,
    9775,  3552,  1842,  1643, -1620,  9042, -1620,  1647,  1653,   252,
   -1620,  1644,   289, -1620,  1655,   347, -1620,  1656, 11320,  1846,
    6035,  1862,  1664,  9042, -1620,  7817,   364, -1620,   922,   377,
     389, -1620,  1847,  8211, -1620, -1620, 10426, 10452, 10478, 10504,
    1731,  9042, -1620,  9042, -1620, -1620,  8273,  3646,  1866,  1666,
   -1620,  1868,  1870, -1620,  1874,  1877,  1878, -1620, -1620,  4575,
   -1620, -1620,  5722, 12204, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620,    37, -1620,  1750, -1620, -1620,  9042, 10530, 10556,
   -1620,  6035,  9042,  1882, -1620, 10582, -1620, -1620,  6035,  6035,
    1884,  1885,  1890,  1891,  1892,  1897,   923,  1707, -1620,  6035,
     620,   636,  8273, -1620, -1620,   305,  4513, -1620, -1620,  8015,
    1375,  8015,  1375,  8015,  1375,  1908, -1620,   935,  6035, -1620,
    8422,   -92,  1909,  8273,   -92, -1620, -1620,  9042,  9042,  9042,
    9042,  9042,  8680,  8938,   961, -1620, -1620,  1911, -1620, -1620,
   -1620, -1620, -1620,   964,  3340,  1912,   965,  1914, -1620,  1712,
   12204,  9042,  9042,   969, 12204, -1620,  9042,   973,   978, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620,  1715,  9042,   979,
    1729,   -92,  6035,  1930,  1734,   -92,  1931,   984,  1746,  9042,
   -1620,  9300,   394,   669,  9328,   480,   826,  9356,   487,   918,
   -1620,  6035,  1936,  1844,  3468,  1749,   499, -1620,   985,   501,
   10608, 10634, 10660, 10686,  3665, -1620, -1620,  1941, -1620,  9042,
   -1620,  6113,    28, -1620, -1620,  9042, 12162, 10712,    46, 10738,
   -1620, -1620, -1620, -1620,  9042,  9384,  1943,   -92,    76, -1620,
   -1620,   -92,    95, -1620,  1945, -1620,  9412,  1948,  9042,  1950,
    1952,  9042,  1953,  1954,  9042,  1955,  1755, -1620,  9042, -1620,
    1375, -1620,  8273,  1957,  7817,  9042,  9042,  9042,  9042, -1620,
   -1620,  3785, -1620,  1768,   989, -1620,  9042, -1620,  6035,  9042,
    1011,  1015, 10764, -1620, -1620,   505, -1620,   508, -1620, -1620,
   -1620, -1620,  1783,  9440, -1620, -1620,  1784,  9468, -1620, -1620,
    1785,  9496, -1620,  1958,  3740,   981,  3505,  1022, -1620,   511,
    1027, 10790, 10816, 10842, 10868,  6113,  1766,  1964,  1786, 12183,
    1031,  9524, -1620, -1620,  9042,   -92,   -92,  1375,  1978,  1375,
    1987,  1375,  1988, -1620, -1620, -1620, -1620,  1375,  1989,  8273,
    1990,  9042,  9042,  9042,  9042, -1620, -1620, -1620,  5722, -1620,
    1794,  1996,  9552,   519,   530,  1160, -1620,  1803,  1210, -1620,
    1805,  1277, -1620,  1825,  1308, -1620,  1037, -1620, 10894, 10920,
   10946, 10972,  1038, -1620,  1826,  6035, -1620,  1997,  9042,  9042,
    1998,  1375,  2002,  1375,  2027,  1375, -1620,  2028,  9042,  9042,
    9042,  9042,  5722,  2029,  5722,  1044, -1620,  9580,  9608, -1620,
    1346, -1620,  1471, -1620,  1521, -1620,  9636,  9664,  9692,  9720,
   -1620, -1620,  1050, -1620,  2030,  2031,  2032,  2033,  2034,  2037,
   -1620, -1620, -1620, -1620,  5722,  2060, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,   269,   270,     0,     0,     0,
     264,     0,     0,     0,     0,   366,   367,   368,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   554,     0,
     415,   553,   523,   416,   418,   419,   417,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   525,     0,   544,   527,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   421,   422,   526,     0,     0,     0,     0,
      66,    67,     0,     0,   209,     0,     0,     0,   373,     0,
     515,   554,   430,     0,     0,     0,     0,   249,     0,   251,
     252,   247,   248,     0,   253,   254,   123,   135,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   452,
       0,     0,     0,     0,     0,   209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   553,     0,   209,   554,     0,
       0,   363,     0,     0,     0,     0,     0,     0,     0,     0,
     553,   470,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   492,   493,   463,   469,     0,   464,   554,   430,     0,
       0,     0,     0,   553,     0,     0,   509,     0,     0,     0,
       0,   245,   246,     0,   553,     0,     0,   262,   263,     0,
     209,     0,   209,   553,     0,   554,     0,   369,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   375,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,   207,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   238,     0,     0,   438,   184,     0,   553,     0,   515,
     554,   516,     0,     0,   549,     0,   121,   121,     0,     0,
       0,     0,   503,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,   209,     0,   454,   453,
       0,     0,     0,     0,   209,   209,     0,     0,     0,     0,
       0,     0,     0,   280,     0,   209,     0,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,   227,
     364,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,     0,   476,     0,     0,   477,     0,
     478,     0,   479,     0,     0,     0,     0,     0,     0,   375,
     471,     0,   465,     0,     0,     0,   341,    66,    67,     0,
     244,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,     0,   266,   265,   232,     0,   233,     0,     0,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,   443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   426,   547,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,   374,    59,    60,     0,     0,    59,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,   210,     0,
       0,     0,   391,   390,   388,   389,   384,   386,   385,   387,
     379,   378,   380,   381,   382,   383,     0,     0,     0,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,   361,
     362,     0,     0,     0,     0,   329,     0,     0,     0,   151,
     152,     0,   154,   155,     0,   157,   158,     0,   160,   161,
       0,   179,     0,   190,     0,   196,     0,     0,     0,     0,
     171,   209,     0,     0,     0,     0,     0,   456,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,     0,     0,     0,   344,     0,     0,   228,
       0,     0,   224,     0,     0,     0,   359,   358,     0,     0,
       0,     0,     0,   443,    68,    69,     0,   494,     0,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,   480,
       0,   481,     0,   482,     0,   483,     0,     0,   374,   466,
     473,     0,   380,   472,     0,     0,     0,   495,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,     0,   234,
     236,     0,   555,     0,     0,     0,    59,    60,     0,     0,
      59,    60,     0,     0,     0,     0,    90,    74,     0,   432,
     431,   445,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   414,   402,     0,   404,   405,   406,   407,   408,   409,
     410,     0,     0,     0,   536,     0,   541,   532,   533,   534,
       0,   546,   545,     0,     0,     0,     0,   537,   538,   539,
     451,   543,   140,   145,   113,     0,     0,   528,     0,   530,
       0,   428,   435,   436,   524,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,   437,     0,     0,     0,     0,   551,
       0,     0,    44,     0,     0,     0,    57,     0,    35,    36,
      37,    38,    39,   434,   433,     0,     0,   521,    24,    22,
       0,     0,     0,     0,    25,     0,     0,   239,   550,    70,
     124,    71,   136,     0,     0,     0,   505,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   327,   332,   330,     0,
     340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,   374,   374,     0,     0,     0,     0,     0,   235,   237,
       0,     0,     0,   199,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,   271,     0,     0,     0,     0,     0,     0,   334,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   431,     0,     0,   498,     0,   497,   496,     0,
     475,     0,     0,     0,     0,     0,     0,     0,   467,     0,
       0,   434,   433,     0,     0,     0,     0,     0,     0,   229,
       0,     0,     0,     0,   231,     0,     0,   370,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   552,     0,
       0,   440,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    88,     0,     0,    76,     0,
       0,     0,     0,    80,   103,   105,     0,     0,   513,     0,
     111,     0,     0,     0,     0,     0,   392,     0,     0,     0,
       0,     0,    30,   442,   441,   519,   517,    23,     0,     0,
     520,   518,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,     0,     0,     0,     0,     0,
       0,     0,   338,     0,     0,   153,     0,   156,     0,   159,
       0,   162,     0,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   315,
       0,     0,   314,     0,   321,     0,   323,     0,   317,     0,
     319,     0,   281,   310,     0,     0,     0,   222,     0,     0,
       0,   345,     0,   226,   225,   365,     0,     0,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
     485,   486,   487,   474,   468,     0,     0,     0,     0,   510,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
      85,     0,    89,     0,     0,    77,     0,    81,     0,   241,
     444,   240,   403,   411,   412,   413,   542,     0,   448,   449,
     450,     0,     0,   427,   141,     0,   548,   146,   447,   529,
     531,   429,     0,     0,     0,    86,     0,     0,     0,    59,
       0,     0,     0,     0,    78,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   461,     0,
       0,    26,    27,     0,    28,     0,     0,   125,   132,     0,
       0,    72,    73,   167,     0,     0,     0,     0,     0,     0,
     170,     0,     0,   187,   188,     0,     0,   172,   195,     0,
       0,     0,     0,   163,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,   209,   209,     0,   291,     0,   293,     0,   295,
       0,   316,   463,     0,     0,   322,   324,   318,   320,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   444,   501,   500,   499,     0,     0,     0,
       0,   502,   175,   176,     0,     0,     0,     0,   114,   118,
       0,     0,   371,     0,     0,     0,    87,     0,     0,     0,
      79,     0,   446,     0,     0,     0,     0,     0,    97,     0,
       0,    91,     0,     0,     0,     0,   108,     0,     0,   109,
       0,   514,   211,   212,   213,   214,     0,     0,    40,     0,
       0,     0,     0,     0,    42,   522,     0,     0,   126,   133,
       0,     0,     0,     0,   166,   173,   174,   178,     0,     0,
     189,     0,     0,   339,     0,   182,     0,     0,   328,   194,
     168,   181,   193,   198,   180,     0,   191,   197,     0,     0,
       0,     0,     0,     0,   460,     0,   459,     0,     0,     0,
     282,     0,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,     0,     0,   221,     0,     0,   220,     0,     0,
       0,   215,     0,     0,   342,    33,     0,     0,     0,     0,
       0,     0,   508,     0,   259,   258,     0,     0,     0,     0,
      98,     0,     0,    92,     0,     0,     0,   535,   540,     0,
     142,   144,     0,   147,   148,   149,    99,   101,    93,    95,
     104,   106,     0,   112,     0,    82,    45,     0,     0,     0,
     462,     0,     0,     0,    29,     0,   140,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,     0,
     335,   335,     0,   119,   120,   209,     0,   202,   203,     0,
       0,     0,     0,     0,     0,     0,   311,     0,     0,   209,
       0,     0,     0,     0,     0,   206,   205,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,     0,   100,   102,
      94,    96,    83,     0,   503,   504,     0,     0,   512,     0,
      41,     0,     0,     0,    43,    58,     0,     0,     0,   130,
     128,   353,   355,   354,   356,   357,   186,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,     0,   276,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,   507,   260,     0,   372,     0,
     143,     0,     0,   150,   110,     0,     0,     0,     0,     0,
     127,   134,   140,   140,     0,     0,     0,     0,     0,   336,
     346,     0,     0,   347,     0,   200,     0,   297,     0,     0,
     299,     0,     0,   301,     0,     0,     0,   312,     0,   272,
       0,   209,     0,     0,     0,     0,     0,     0,     0,   177,
     117,     0,   137,     0,     0,    49,     0,    55,     0,     0,
       0,     0,     0,   164,   192,     0,   350,     0,   351,   352,
     457,   285,     0,     0,   292,   286,     0,     0,   294,   287,
       0,     0,   296,     0,     0,     0,   278,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   129,     0,     0,     0,     0,   303,     0,
     305,     0,   307,   313,   325,   277,   273,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,    46,     0,    53,
       0,     0,     0,     0,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,     0,   223,     0,   217,     0,     0,
       0,     0,     0,    47,     0,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   298,
       0,   300,     0,   302,     0,   218,     0,     0,     0,     0,
      48,    50,     0,    51,     0,     0,     0,     0,     0,     0,
     488,   489,   490,   491,     0,     0,    56,   348,   349,   304,
     306,   308,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1620, -1620, -1620, -1620,   868, -1620, -1620, -1620, -1620,   293,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620,  -302,   -70,    21,  3143, -1620,  1616, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1619, -1620,   424, -1620, -1620,
   -1620, -1620, -1620, -1620,   856,  2071,    11,  -503,  -247, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620,  2072, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1065, -1050, -1620, -1620,  1591, -1620,   415, -1620, -1620, -1620,
   -1620,  1687, -1620, -1620,   512, -1620, -1420,  2420,   654,  2274,
    2846,  -248,   717, -1620,   128,    10, -1620,  -374,    -3,   257
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   990,    91,    92,   706,  1517,  1523,
     978,  1187,  1709,  1922,   979,  1868,  1962,   980,  1924,   981,
     982,  1191,   351,   444,   186,   827,    93,   724,   456,  1646,
    1783,  1782,  1647,   457,  1703,  1155,  1344,  1156,  1347,   758,
     761,   764,   767,  1547,  1397,   688,   301,   420,   421,    96,
      97,    98,    99,   100,   101,   102,   302,  1073,  1810,  1887,
     796,  1571,  1574,  1577,  1842,  1846,  1850,  1907,  1910,  1913,
    1069,  1070,  1231,  1029,   755,   805,  1733,   104,   105,   106,
     107,   303,   188,   932,   509,   259,  1377,   304,   305,   306,
     573,   315,   963,  1179,   454,   449,   933,   455,   335,   308
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   329,   504,   191,  1393,   641,   317,   643,  1275,   535,
     353,   789,   790,   988,    95,  1122,   190,   331,   523,  1273,
     656,   216,   216,  1496,   194,   558,   267,  1717,   221,   961,
     538,   414,   324,   275,   221,  1588,   555,   839,   560,   352,
       4,   313,   210,   211,   841,   562,   212,   843,   845,   526,
     197,   337,  1827,   213,   278,  1264,   527,   280,     5,   281,
     512,   513,   307,   512,   513,   349,   350,   278,   972,   193,
    1204,   512,   513,   512,   513,   195,  -516,   514,   278,  1434,
    1382,  1435,  1836,   595,   948,   597,   208,  1436,   209,  1437,
     515,   325,   328,   512,   513,   512,   513,   254,   255,   212,
     268,  1838,   250,   206,   269,   344,   965,   256,   671,  1438,
     675,  1439,   678,  1254,   257,   196,   270,   251,   252,   677,
     512,   513,   349,   350,  1656,   224,   199,   349,   350,   343,
     948,   282,   968,  -521,   189,  1291,   200,   525,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,  1830,  1831,   559,   385,   386,  1266,   415,
     416,   390,   391,   392,   393,  1497,   556,   395,   561,  1265,
     278,   424,   276,   396,   397,   563,  1268,   512,   513,   402,
     403,  1169,   450,   450,   989,   419,   973,   974,   975,   976,
     450,   318,   330,    89,    89,   354,   536,   355,   278,   356,
     307,  1123,    89,   185,   185,   307,   217,   217,   332,   307,
     458,  1713,   307,   218,   966,  1273,   307,   307,   307,   307,
     222,   962,   307,   307,   307,   277,   967,   557,   840,  1729,
     307,   307,   307,   314,   338,   842,   307,   278,   844,   846,
     198,   339,  1828,   345,   346,   347,   348,  1359,   782,   783,
     109,   989,  1205,   192,  1206,   512,   513,   203,   307,   307,
     307,   977,   349,   350,   345,   346,   347,   348,   798,   669,
     954,  1270,   307,   307,   512,   513,   349,   350,   345,   346,
     347,   348,  1267,   349,   350,   307,   340,   307,   341,   345,
     346,   347,   348,   201,   878,   342,   882,   349,   350,   418,
    1269,   552,  1427,  1428,   279,   673,   512,   513,   349,   350,
     202,   512,   513,   448,   452,   512,   513,   316,   579,  1170,
    1171,   722,   784,   450,   723,   307,   307,   791,   326,   863,
     442,   797,   443,   549,   679,   550,   584,   551,   307,   342,
     184,   185,   185,   871,   612,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   824,
     949,   825,   876,   439,   955,   826,   450,   450,   450,   450,
     450,   450,   450,   450,   307,   450,   450,   880,   450,   450,
     450,   450,   450,   512,   513,   207,   450,   450,   450,   450,
     450,   278,   204,   278,   948,  1271,   205,   659,  1870,  1250,
      48,    49,    50,    51,   214,   667,   512,   513,   246,    56,
     307,   247,    59,   512,   513,   215,   345,   346,   347,   348,
     349,   350,  1274,   447,   112,   219,   709,  1098,   682,  1583,
     417,   512,   513,   349,   350,   349,   350,   225,   670,   346,
     347,   348,   451,   451,  -519,   349,   350,  1669,   307,   262,
     451,   824,   263,   825,   603,   264,  -520,   856,   459,   139,
     140,   141,   142,   143,   144,   145,   146,   220,   512,   513,
     150,   151,   152,   153,   674,   346,   347,   348,   155,   156,
     157,   223,   230,   158,  1671,   231,   307,   307,   232,   760,
     763,   766,   769,   285,   163,  1945,   286,   316,   642,   224,
     644,   645,   646,   647,   648,   725,   650,   651,   723,   653,
     654,   655,   553,   657,   554,   419,   419,   661,   662,   663,
     664,   665,   228,   271,  1047,   272,   512,   513,   307,   307,
     307,   877,   346,   347,   348,   731,   226,   732,   891,   227,
     307,   307,  1673,   512,   513,   713,   881,   346,   347,   348,
     714,   258,   260,   717,   266,   307,   512,   513,   718,  1681,
     254,   255,   307,   345,   346,   347,   348,  1131,   512,   513,
     256,  1136,  1683,   512,   513,   349,   350,   265,   229,   166,
     167,   168,   239,   451,  1684,   240,  -518,   233,   241,  1798,
     242,   175,   950,   176,    89,  1743,   956,  1746,   307,  1749,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   349,   350,   235,   234,   439,   236,
     238,   237,  1142,   349,   350,  -517,   451,   451,   451,   451,
     451,   451,   451,   451,  -522,   451,   451,   249,   451,   451,
     451,   451,   451,   731,  1060,   737,   451,   451,   451,   451,
     451,   666,   598,   668,   599,  1061,   551,   248,   307,   512,
     513,   185,   307,  1062,  1063,  1064,   512,   513,   720,  1065,
    1066,  1067,  1068,   721,   731,  1801,   741,   957,   512,   513,
     512,   513,  1804,  1273,   512,   513,  1273,   512,   513,  1273,
     512,   513,   253,   710,  1812,   711,  1814,   712,   512,   513,
    1875,   307,   185,  1876,  1178,   307,  1889,   930,   450,   512,
     513,   278,   721,   450,  1928,  1730,  1731,   307,   307,  1060,
    1234,  1732,  1236,   261,  1238,  1929,  1240,   577,  1004,   578,
    1061,  1734,  1735,  1479,  1480,  1855,   342,  1732,  1062,  1063,
    1064,   307,   273,   891,  1065,  1066,  1067,  1068,  1199,   601,
    1272,   602,   715,   731,   716,   507,   508,   274,   342,   243,
    1060,   342,   244,   516,   245,   307,   564,   524,   824,   565,
     825,  1061,   566,   721,   567,   512,   513,  1353,  1354,  1062,
    1063,  1064,  1357,  1358,   283,  1065,  1066,  1067,  1068,   434,
     435,   436,   437,   438,   731,  1273,   747,   284,   439,  1132,
     287,   833,  1905,  1137,  1908,   824,  1911,   825,   574,  1141,
    1143,  1202,  1914,   307,   288,   307,   731,  1636,   307,   436,
     437,   438,  1637,   310,   311,  1451,   439,   307,   289,   307,
     824,   307,   825,   307,   731,   915,   849,   309,   307,   998,
     874,   312,   875,   307,  1002,  1273,   323,   824,  1273,   825,
     319,  1273,   938,   731,  1273,   970,  1950,  1360,  1952,   320,
    1954,   307,   824,   321,   825,   307,  1799,   940,   731,   307,
    1043,   322,   336,  1373,   480,   481,   482,   450,   382,   485,
     486,   487,   824,   383,   825,  1603,   824,   731,   825,   384,
    1273,  1342,  1273,   824,  1273,   825,   387,   731,  1345,  1044,
     398,   388,   307,  1193,  1194,   389,   731,   450,  1085,   394,
     307,   450,   450,   399,   400,   531,   532,  1060,  1365,  1567,
    1568,   401,   731,   450,  1086,   450,  1154,   404,  1061,   544,
     545,   731,   405,  1087,  1484,  1485,  1062,  1063,  1064,  1488,
    1489,   406,  1065,  1066,  1067,  1068,   731,   441,  1108,   278,
     422,   423,   307,   307,   307,   307,  1161,  1162,   731,  1210,
    1139,  1211,  1166,  1167,  1216,   731,  1217,  1247,   451,   440,
     731,  1000,  1292,   451,   731,   467,  1293,   450,   445,   472,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   575,   437,   438,   477,   478,   307,   307,   439,   307,
     483,   307,   307,   484,   488,   307,   307,  1579,  1144,  1060,
     307,  1141,  1143,   934,   787,   788,  1491,   731,   502,  1294,
    1061,   489,   508,  1802,   731,   731,  1299,  1300,  1062,  1063,
    1064,  1193,  1194,   499,  1065,  1066,  1067,  1068,  1150,   731,
     490,  1301,  1152,  1153,   731,   731,  1302,  1304,   731,  1367,
    1305,  1368,   491,   731,  1158,  1369,  1159,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   731,  1060,  1370,   731,   439,  1371,   731,   731,  1372,
    1411,   492,   505,  1061,  1604,   506,   447,   112,  1521,  1361,
    1522,  1062,  1063,  1064,  1555,   517,  1556,  1065,  1066,  1067,
    1068,   307,   307,   307,   731,  1642,  1592,  1643,  1198,  1511,
     518,   731,   307,  1660,   731,  1805,  1661,  1521,  1521,  1682,
    1727,   519,   139,   140,   141,   142,   143,   144,   145,   146,
    1751,   528,  1752,   150,   151,   152,   153,   451,   529,  1318,
    1319,   155,   156,   157,  1323,  1324,   158,   530,   450,   450,
     537,   534,  1738,   450,   450,   342,   731,   163,  1767,  1769,
     721,  1770,  1773,   278,  1521,   539,  1778,   451,  1342,   540,
    1780,   451,   451,  1345,  1521,  1781,  1786,   307,  1885,   731,
     731,  1794,  1813,   451,  1642,   451,  1867,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   307,   541,   542,  1388,   439,  1342,   307,  1872,   316,
    1342,   546,  1873,   307,   543,   307,   307,   731,   576,  1888,
     307,   307,   731,   307,  1890,   307,  1521,   307,  1900,   307,
     307,   307,   731,  1942,  1937,  1943,   547,   451,  1706,  1521,
     548,  1964,   166,   167,   168,  1974,   580,  1975,   307,   586,
    1492,  1060,   587,   185,   175,   592,   176,    89,   593,   610,
     594,   596,  1061,   307,   611,     7,     8,   307,   614,   307,
    1062,  1063,  1064,   615,   618,   439,  1065,  1066,  1067,  1068,
     681,   680,   824,   683,   825,   184,  1050,   744,   727,   728,
     748,   749,   750,  1056,   753,   754,   771,   773,   775,  1071,
     779,  1060,   780,   781,   804,   450,   450,   806,   823,   807,
     450,   450,  1061,   809,   816,   817,   834,   836,   861,   837,
    1062,  1063,  1064,   864,   450,   838,  1065,  1066,  1067,  1068,
     872,   684,    24,    25,   685,    27,    28,   686,    30,   687,
      32,  1494,    33,   873,   886,   887,   918,    38,    39,   919,
      41,    42,    43,   920,   278,   937,    46,  1930,   923,  1504,
     307,   924,   925,   935,   942,   936,   943,   944,  1060,   945,
     450,   946,   951,   307,  1707,   952,   959,   960,   987,  1061,
    1008,   994,   997,  1492,   999,  1001,  1529,  1062,  1063,  1064,
      67,    68,    69,  1065,  1066,  1067,  1068,  1005,  1009,  1060,
    1010,  1012,  1013,  1014,  1015,  1018,  1019,  1932,   451,   451,
    1061,   307,   307,   451,   451,  1023,  1017,  1028,  1062,  1063,
    1064,  1030,  1754,   316,  1065,  1066,  1067,  1068,  1562,  1032,
    1033,  1034,  1035,   419,   419,  1037,  1036,  1060,  1038,  1039,
     307,  1080,   307,  1095,   307,  1046,  1053,  1099,  1061,  1097,
       7,     8,  1054,  1114,  1101,  1493,  1062,  1063,  1064,  1115,
     812,   307,  1065,  1066,  1067,  1068,  1060,  1116,   307,  1117,
    1102,  1103,  1127,  1128,  1934,  1163,  1129,  1061,   307,  1312,
    1608,  1125,   307,  1133,  1134,  1062,  1063,  1064,  1165,  1168,
    1173,  1065,  1066,  1067,  1068,  1621,  1624,  1625,  1174,  1188,
    1176,  1526,  1180,  1192,  1177,  1936,  1197,  1209,   307,  1189,
    1214,  1190,  1220,  1221,  1225,  1226,   684,    24,    25,   685,
      27,    28,   686,    30,   687,    32,  1228,    33,  1229,  1232,
    1248,   307,    38,    39,  1233,    41,    42,    43,  1242,  1243,
    1244,    46,  1245,  1967,   430,   431,   432,   433,   434,   435,
     436,   437,   438,  1246,  1856,  1258,  1261,   439,  1262,  1255,
    1256,  1257,  1060,  1263,  1276,   451,   451,   307,  1277,  1282,
     451,   451,   307,  1061,  1278,    67,    68,    69,  1279,  1280,
    1283,  1062,  1063,  1064,   451,  1284,  1285,  1065,  1066,  1067,
    1068,  1287,  1288,   307,  1286,  1289,  1309,  1314,  1315,  1317,
    1337,  1320,  1322,  1175,  1325,  1327,   307,  1329,  1330,   450,
    1338,  1331,  1060,  1341,   316,  1362,  1339,  1340,  1349,   278,
    1363,  1374,  1381,  1061,  1380,  1379,  1384,  1390,   307,  1389,
     451,  1062,  1063,  1064,  1391,   307,   307,  1065,  1066,  1067,
    1068,  1392,  1224,  1394,  1396,   869,   307,  1395,  1400,   307,
    1403,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   307,   419,  1404,  1968,   439,
     307,  1313,  1407,  1401,  1402,  1408,  1406,  1409,  1414,  1415,
    1424,   110,   333,   187,  1425,  1432,  1426,   113,   114,   115,
    1440,  1433,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,  1445,  1446,  1447,  1969,   307,
    1448,  1455,  1456,  1460,  1463,  1465,   147,   148,   149,  1472,
    1466,  1473,  1474,   154,  1478,  1481,  1495,  1482,   307,  1498,
    1501,  1506,  1507,  1509,   159,   160,   161,  1512,  1513,  1514,
    1515,  1525,   162,  1530,  1542,  1531,  1535,  1536,  1537,   278,
    1540,  1543,  1544,  1545,  1546,   334,  1549,  1550,  1551,  1552,
    1553,  1822,  1554,  1557,  1570,  1573,  1450,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,  1576,  1580,  1584,  1587,   439,  1591,  1595,  1610,   307,
    1613,   307,  1617,  1626,  1627,  1628,  1629,  1630,  1655,  1632,
    1633,  1634,  1635,  1641,  1644,   307,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     574,  1648,  1649,  1658,   439,  1657,  1659,   165,  1664,  1665,
    1670,   169,  1676,  1685,  1667,   170,   171,   172,   173,   174,
    1668,  1672,  1674,    89,   407,   408,   409,   411,   413,  1678,
    1679,  1691,  1696,  1697,  1698,  1895,  1699,   177,   178,   451,
    1700,   446,   179,  1701,  1702,   453,   307,   299,  1715,   316,
    1721,  1722,   183,  1708,   500,   450,  1723,  1724,  1725,   460,
     462,   465,   466,  1726,   468,   462,   470,   471,  1534,   462,
     474,   475,  1281,  1728,  1750,  1757,   462,  1768,  1775,  1772,
    1774,  1784,   307,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   501,  1787,  1790,  1793,   439,   450,
    1791,   450,  1807,   510,   511,  1808,  1569,  1820,  1572,  1834,
    1575,  1839,   511,  1795,  1841,  1811,  1844,  1355,  1845,  1848,
    1849,  1852,  1853,  1858,  1883,  1586,  1896,  1866,  1589,  1590,
    1897,   450,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1906,   569,   571,   462,   439,  1877,
    1879,  1881,  1898,  1909,  1912,  1915,  1917,   581,   582,   583,
    1925,   585,  1926,  1946,  1949,   588,   589,   590,  1951,  1931,
     591,  1933,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   575,   437,   438,  1923,   607,   609,  1823,
     439,  1935,  1944,  1953,  1955,  1961,  1976,  1977,  1978,  1979,
    1980,   616,   617,  1981,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,  1983,  1383,  1824,  1398,
    1960,  1718,  1963,   726,    94,   103,  1736,   652,   756,     0,
    1508,     0,     0,   658,     0,   660,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,  1982,     0,   439,     0,     0,     0,     0,   689,
     462,     0,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,     0,     0,   707,
     708,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,   569,   439,
       0,     0,     0,     0,   735,   451,     0,     0,     0,   740,
       0,     0,     0,     0,   745,   746,  1364,     0,     0,     0,
     751,   752,     0,     0,     0,   757,   759,   762,   765,   768,
     770,  1742,   772,  1745,   774,  1748,   462,   462,     0,     0,
    1230,     0,     0,  1756,     0,     0,  1759,     0,     0,   451,
       0,   451,     0,     0,   792,   793,   794,   407,   408,   795,
       0,     0,     0,   799,   800,   801,   802,   803,     0,     0,
       0,   808,     0,   810,   811,     0,     0,     0,   462,   462,
     462,   451,     0,   818,   819,   820,   821,   822,     0,     0,
     829,   829,     0,  1788,   835,     0,     0,  1792,     7,     8,
       0,     0,     0,     0,     0,   462,     0,     0,     0,     0,
       0,   850,   852,     0,   854,   855,     0,     0,     0,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,   821,   822,   439,   854,   855,
       0,     0,     0,     0,     0,     0,     0,   884,   462,  1835,
       0,     0,   888,  1837,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   684,    24,    25,   685,    27,    28,
     686,    30,   687,    32,     0,    33,  1859,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,   958,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,     0,     0,     0,  1441,
       0,     0,     0,     0,     7,     8,     0,  1903,  1904,     0,
       0,     0,     0,     0,     0,     0,     0,   985,   986,     0,
       0,   462,   992,   993,     0,   462,   996,     0,     0,     0,
       0,     0,     0,     0,  1003,     0,     0,   852,  1006,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1020,     0,     0,     0,     0,     0,     0,     0,     0,
    1026,     0,     0,   870,     0,     0,     0,     0,     0,     0,
     684,    24,    25,   685,    27,    28,   686,    30,   687,    32,
       0,    33,     0,     0,     0,   462,    38,    39,     0,    41,
      42,    43,  1051,  1052,     0,    46,     0,     0,  1055,     0,
       0,     0,     0,     0,     0,     0,     0,   463,     0,     0,
       0,  1079,   463,     0,  1081,     0,   463,     0,     0,     0,
    1486,     0,     0,   463,     0,     0,     0,     0,     0,    67,
      68,    69,     0,   462,     0,   462,     0,     0,   462,     0,
       0,     0,     0,     0,     0,     0,     0,   462,     0,   462,
       0,   462,     0,   462,     0,     0,     0,     0,   462,     0,
       0,     0,     0,   462,     0,     0,     7,     8,     0,  1118,
       0,  1120,  1121,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,   570,     0,   463,     0,     0,     0,     0,  1048,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1145,     0,     0,     0,     0,     0,     0,     0,  1146,  1147,
    1148,     0,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   684,    24,    25,   685,    27,    28,   686,    30,
     687,    32,  1157,    33,     0,     0,     0,  1160,    38,    39,
       0,    41,    42,    43,     0,     0,  1164,    46,     0,     0,
       0,     0,  1172,     0,     0,   476,     0,     0,     0,     0,
       0,     0,   462,   462,   462,   462,     0,     0,  1186,     0,
       0,     0,     0,   494,   496,   498,     0,     0,     0,   503,
       0,    67,    68,    69,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,   533,     0,     0,     0,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1235,     0,  1237,     0,  1239,     0,  1241,     0,     0,     0,
       0,     0,     0,     0,     0,   570,     0,     0,     0,     0,
       0,  1049,     0,     0,     0,     0,     0,     0,  1260,  1490,
       0,     0,     0,     0,     0,     0,     0,     0,   604,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,     0,   463,   463,     0,     0,  1290,     0,     0,
       0,     0,     0,     0,     0,     0,  1295,     0,  1296,  1297,
    1298,     0,     0,     0,     0,     0,  1303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   649,     0,     0,
       0,     0,     0,     0,     0,   463,   463,   463,  1321,     0,
       0,     0,     0,  1326,     0,     0,     0,   830,   832,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,   853,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1366,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1375,  1376,   969,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,     0,
    1385,  1387,     0,     0,     0,   684,    24,    25,   685,    27,
      28,   686,    30,   687,    32,     0,    33,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,     0,     0,
      46,     0,     0,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,  1429,  1430,  1431,
       0,   439,     0,     0,     7,     8,     0,     0,  1442,     0,
    1444,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,  1449,     0,     0,     0,     0,     0,     0,     0,   462,
       0,     7,     8,     0,  1461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,   463,     0,     0,     0,     0,  1475,  1476,  1477,
       0,     0,     0,     0,   853,  1007,     0,     0,     0,     0,
     684,    24,    25,   685,    27,    28,   686,    30,   687,    32,
       0,    33,     0,     0,  1072,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,   684,    24,    25,
     685,    27,    28,   686,    30,   687,    32,  1505,    33,     0,
       0,  1594,   463,    38,    39,     0,    41,    42,    43,   464,
       0,  1518,    46,     0,   469,     0,  1524,     0,   473,    67,
      68,    69,     0,     0,     0,   479,     0,     0,     0,     0,
       0,  1532,  1533,     0,     0,     0,     0,     0,  1538,  1539,
       0,   947,     0,  1541,     0,   953,    67,    68,    69,     0,
     463,  1548,   463,     0,     0,   463,     0,     0,     0,     0,
       0,   462,   462,  1560,   463,  1561,   463,     0,   463,     0,
     463,     0,     0,     0,     0,   463,     0,  1578,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,  1119,
     462,     0,     0,     0,   462,     0,     0,  1593,     0,     0,
       0,     0,     0,     0,  1596,  1597,  1598,  1599,     0,     0,
       0,     0,     0,     0,     0,     0,  1124,  1607,     0,     0,
       0,     0,     0,     0,  1027,     0,     0,     0,     0,     0,
       0,     0,     0,  1623,     0,     0,     0,     0,     0,   463,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1638,  1639,     0,     0,
       0,     0,     0,     0,  1645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   463,
     463,   463,   463,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1666,     0,     0,     0,     0,   684,    24,    25,
     685,    27,    28,   686,    30,   687,    32,  1631,    33,   690,
    1680,     0,   569,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,  1692,     0,
    1693,     0,     0,   462,  1126,     0,     0,   463,  1130,     0,
       0,     0,  1135,     0,     0,     0,  1704,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,  1710,     0,     0,     0,     0,  1714,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1151,     0,   776,   777,  1771,   574,   462,
       0,     0,     0,     0,     0,     0,  1741,     0,  1744,     0,
    1747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,     0,     0,     0,  1760,  1761,  1762,  1763,  1764,     0,
       0,     0,     0,     0,     0,     0,  1249,   813,   814,   815,
       0,     0,     0,     0,     0,     0,     0,     0,  1776,  1777,
       0,     0,     0,  1779,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   847,  1785,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1796,     0,     0,  1212,
    1213,     0,  1215,     0,  1218,  1219,     0,     0,  1222,  1223,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,  1821,   885,     0,   439,
       0,     0,  1524,     0,     0,     0,     0,     0,     0,     0,
       0,  1832,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,  1843,     0,     0,  1847,     0,
       0,  1851,     0,     0,     0,  1854,     0,     0,     0,   462,
       0,   462,  1861,  1862,  1863,  1864,     0,     0,     0,     0,
       0,     0,     0,  1869,     0,     0,  1871,     7,     8,     0,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   730,   437,   438,  1306,  1307,  1308,     0,   439,     0,
       0,     0,     0,     0,     0,  1316,   684,    24,    25,   685,
      27,    28,   686,    30,   687,    32,   463,    33,  1663,     0,
     991,  1902,    38,    39,   995,    41,    42,    43,     0,     0,
       0,    46,     0,     0,     0,     0,   462,     0,  1918,  1919,
    1920,  1921,     0,   684,    24,    25,   685,    27,    28,   686,
      30,   687,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,    67,    68,    69,    46,     0,
    1378,     0,     0,     0,     0,  1947,  1948,     0,     0,     0,
       0,     0,     0,     0,  1045,  1956,  1957,  1958,  1959,     0,
       0,     0,     0,     0,  1399,     0,     0,     0,     0,     0,
    1405,     0,    67,    68,    69,     0,  1410,     0,  1412,  1413,
       0,     0,  1695,  1416,  1417,     0,  1418,     0,  1419,     0,
    1420,     0,  1421,  1422,  1423,     0,     0,     0,     0,     0,
       0,  1819,  1093,     0,  1094,  1809,     0,  1096,     0,     0,
       0,  1443,     0,     0,     0,     0,  1104,     0,  1105,     0,
    1106,     0,  1107,     0,     0,     0,  1454,  1110,   463,   463,
    1458,     0,  1113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1886,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   857,     0,     0,     0,     0,   463,     0,     0,
       0,   463,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,  1884,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1149,   892,   893,   894,   895,   896,   897,   898,   899,
     900,   901,   902,     0,   904,   905,   906,   907,   908,   909,
     910,     0,     0,     0,   914,   916,   917,     0,     0,     0,
     921,   922,  1865,  1516,     0,     0,   927,   928,   929,     0,
     931,     0,     0,     0,     0,     0,  1528,   939,   941,     0,
       0,  1181,  1182,  1183,  1184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   964,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   570,
       0,     0,     0,   439,     0,     0,     0,     0,     0,  1227,
       0,     0,     0,     0,     0,  1378,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1705,  1600,     0,     0,     0,     0,     0,
       0,  1609,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1616,     0,     0,     0,  1620,     0,     0,     0,     0,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,   463,     0,   439,     0,
       0,  1640,   574,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   463,     0,     0,
       0,   439,     0,   672,  1378,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
    1677,   110,   111,   112,   439,     0,   848,   113,   114,   115,
       0,   785,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   865,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   971,     0,     0,   155,   156,   157,
       0,  1378,   158,     0,   159,   160,   161,     0,  1719,  1720,
       0,     0,   162,   163,     0,     0,     0,  1109,     0,  1378,
       0,     0,     0,     0,     0,     0,   463,     0,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1753,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1185,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   730,   437,   438,  1459,     0,
       0,     0,   439,     0,     0,     0,     0,     0,  1311,     0,
       0,     0,     0,     0,     0,     0,  1207,  1208,     0,     0,
       0,   164,  1789,     0,     0,     0,     0,   165,   166,   167,
     168,   169,     0,   463,     0,   170,   171,   172,   173,   174,
     175,  1806,   176,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,     0,
       0,     0,   179,     0,     0,     0,     0,   180,     0,   181,
       0,   182,   183,     0,   184,     0,   185,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1378,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
    1558,  1559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1328,     0,     0,     0,     0,     0,  1332,  1333,
    1334,  1335,  1336,     0,     0,     0,     0,     0,  1343,  1346,
       0,     0,  1350,  1351,  1352,     0,     0,     0,     0,  1356,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,  1378,     0,   439,     0,     0,
       0,   110,   290,     0,  1565,     0,  1566,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     7,     8,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,  1464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,  1471,     0,
       0,     0,  1694,    48,    49,    50,    51,    52,     0,     0,
       0,  1483,    56,     0,     0,    59,  1487,   684,    24,    25,
     685,    27,    28,   686,    30,   687,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,  1499,  1500,     0,     0,
    1502,  1503,     0,     0,     0,     0,     0,   165,  1737,     0,
       0,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,    67,    68,    69,  1758,
       0,     0,     0,     0,     0,     0,     0,   520,  1585,     0,
       0,     0,   179,     0,     0,     0,     0,   522,     0,     0,
       0,     0,   183,     0,   257,   572,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,   110,   290,
       0,  1601,     0,  1602,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,  1611,  1612,     0,
     154,  1614,  1615,     0,     0,     0,     0,  1618,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,  1857,   295,
    1860,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,  1739,     0,
    1740,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,  1916,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   461,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,     0,     0,     0,   183,
       0,     0,   572,   110,   290,   112,     0,     0,     0,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   292,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,   155,
     156,   157,     0,     0,   158,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,   163,     0,     0,   293,     0,
       0,   294,     0,     0,   295,     0,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1022,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,     0,     0,     0,   170,   171,   172,
     173,   174,   175,     0,   176,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     298,     0,     0,     0,   179,     0,     0,     0,     0,   299,
       0,   110,   290,   112,   183,     0,   300,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   292,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,     0,   155,   156,   157,
       0,     0,   158,     0,   159,   160,   161,     0,     0,     0,
       0,     0,   162,   163,     0,     0,   293,     0,     0,   294,
       0,     0,   295,     0,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,     0,     0,     0,   170,   171,   172,   173,   174,
     175,     0,   176,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   298,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     333,   112,   183,     0,  1619,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,   156,   157,     0,     0,
     158,     0,   159,   160,   161,     0,   110,   333,   112,     0,
     162,   163,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,   155,   156,   157,     0,     0,   158,     0,   159,
     160,   161,     0,     0,     0,     0,     0,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
       0,     0,     0,   170,   171,   172,   173,   174,   175,     0,
     176,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   299,     0,     0,     0,     0,
     183,     0,  1386,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,   165,   166,   167,   168,   169,     0,     0,   600,
     170,   171,   172,   173,   174,   175,     0,   176,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,     0,     0,     0,   179,     0,     0,
       0,     0,   299,     0,   110,   333,   112,   183,     0,  1606,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
     155,   156,   157,     0,     0,   158,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,   163,     0,     0,     0,
       0,     0,   324,   112,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,     0,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   150,
     151,   152,   153,     0,     0,     0,     0,   155,   156,   157,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,     0,     0,     0,   170,   171,
     172,   173,   174,   175,     0,   176,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,   110,   290,   291,   183,     0,  1622,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,   166,   167,
     168,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     175,     0,   176,    89,   154,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   177,   298,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,  1452,   183,     0,   300,   113,   114,   115,     0,
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
       0,     0,     0,     0,     0,     0,   177,   298,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
       0,   183,     0,  1453,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,   166,   167,   168,     0,     0,
       0,     0,     0,   147,   148,   149,     0,   175,     0,   176,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,   112,   295,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   150,   151,   152,   153,     0,     0,
       0,     0,   155,   156,   157,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   298,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,   110,   290,     0,   183,
       0,   300,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     292,     0,     0,   166,   167,   168,     0,     0,     0,     0,
       0,   147,   148,   149,     0,   175,     0,   176,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     160,   161,     0,     0,     0,     0,     0,   162,     0,     0,
       0,   293,     0,     0,   294,     0,     0,   295,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   298,     0,     0,     0,   179,     0,     0,
       0,     0,   493,     0,   110,   290,     0,   183,     0,   300,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,     0,     0,     0,   293,
       0,     0,   294,     0,     0,   295,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,   169,     0,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   298,     0,     0,     0,   179,     0,     0,     0,     0,
     495,     0,   110,   290,     0,   183,     0,   300,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
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
       0,     0,     0,     0,  1563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   298,
       0,     0,     0,   179,     0,     0,     0,     0,   497,     0,
     110,   290,     0,   183,     0,   300,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,     0,     0,     0,   293,     0,     0,   294,     0,
       0,   295,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   461,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
       0,   183,     0,   568,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,     0,     0,   295,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,     0,
    1650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   461,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,   110,   290,     0,   183,
       0,   828,   113,   114,   115,     0,     0,   116,   117,   118,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1651,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   461,     0,     0,     0,   179,     0,     0,
       0,     0,   299,     0,   110,   290,     0,   183,     0,   831,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   149,     0,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,     0,     0,     0,   293,
       0,     0,   294,     0,     0,   295,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,   169,     0,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   461,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,   110,   290,     0,   183,     0,   851,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
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
       0,     0,     0,     0,  1653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   298,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,     0,   183,     0,  1457,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,     0,     0,
       0,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,     0,     0,     0,   293,     0,     0,   294,     0,
       0,   295,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1654,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,  1585,     0,     0,
       0,   179,     0,     0,     0,     0,   522,     0,   110,   333,
       0,   183,     0,   257,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,   160,   161,   110,   333,   112,     0,     0,   162,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
     155,   156,   157,     0,     0,   158,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,   163,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,   165,   439,     0,   824,   169,   825,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   520,   521,     0,     0,     0,   179,
       0,     0,     0,     0,   522,     0,     0,     0,     0,   183,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,     0,     0,     0,   170,   171,
     172,   173,   174,   175,     0,   176,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,   110,   290,     0,     0,
     299,     0,   113,   114,   115,   183,     0,   116,   117,   118,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1686,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   461,     0,     0,     0,   179,   110,   333,
       0,     0,   299,     0,   113,   114,   115,   183,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   148,   149,     0,     0,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,   110,
     333,   159,   160,   161,     0,   113,   114,   115,     0,   162,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,   165,     0,     0,     0,   169,  1755,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,     0,     0,     0,   179,
       0,     0,     0,     0,   299,   410,     0,     0,     0,   183,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,   165,     0,     0,   439,   169,
       0,     0,   676,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   299,   110,   333,   412,     0,
     183,     0,   113,   114,   115,     0,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,   149,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   333,   159,
     160,   161,     0,   113,   114,   115,     0,   162,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     0,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,   165,     0,     0,     0,   169,  1765,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,     0,     0,     0,   179,     0,     0,
       0,     0,   299,   606,     0,     0,     0,   183,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,   165,     0,     0,   439,   169,     0,     0,
     868,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,     0,     0,     0,   179,     0,
       0,     0,     0,   299,   110,   333,   608,  1259,   183,     0,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
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
     165,     0,     0,     0,   169,  1766,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,    -4,     1,     0,   183,    -4,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,   165,     0,     0,     0,   169,     0,     0,     0,   170,
     171,   172,   173,   174,     0,     0,     0,    89,     0,     0,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,     0,     0,     0,   179,     0,    -4,    -4,
      -4,   299,     0,     0,    -4,    -4,   183,    -4,     0,     0,
       0,    -4,    -4,     0,    -4,    -4,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     6,     0,
       0,     0,     0,    -4,     0,     0,     7,     8,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     9,    10,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,    -4,     0,    -4,     0,     0,
      11,    12,    13,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,    62,    63,    64,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
      66,    67,    68,    69,     0,     0,    70,     0,    71,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,    85,    86,
      87,     0,     0,     0,     0,     0,     0,    88,     0,    89,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1797,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1800,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1803,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1833,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1840,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1878,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1880,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1882,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1901,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1927,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1965,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1966,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1970,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1971,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1972,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1973,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,   778,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,  1662,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,   719,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,   785,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,   786,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,   862,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,   903,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,   911,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,   912,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,   913,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,   926,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1057,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1058,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1059,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1090,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1203,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1251,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1252,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1310,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1467,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1468,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1469,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1470,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1519,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1520,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1527,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1687,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1688,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1689,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1690,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1711,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1712,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1716,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1815,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1816,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1817,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1818,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1826,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1829,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1874,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1891,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1892,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1893,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1894,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1938,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1939,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1940,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1941,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     883,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,   890,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,   984,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1083,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1084,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,  1088,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1089,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,  1092,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1112,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1140,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
    1196,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1201,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1462,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1510,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1675,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   729,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   733,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   734,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   736,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   738,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   739,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   742,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     743,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   848,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   858,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   859,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   860,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   866,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   867,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   879,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   889,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   983,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1011,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1016,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1021,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1024,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1025,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1031,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1040,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1041,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1042,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1074,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1076,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1077,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1078,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1082,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1091,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1111,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1195,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1200,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1348,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1564,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1581,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1605,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1825,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1899,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439
};

static const yytype_int16 yycheck[] =
{
       3,     5,   250,     6,     6,   379,     4,   381,  1073,     4,
       4,   514,   515,     6,     3,     7,     6,     5,   265,  1069,
     394,     4,     4,     4,    84,     5,     4,  1646,     4,     4,
     277,     4,     4,     4,     4,  1455,     5,     5,     5,   109,
       6,     4,    21,    22,     5,     5,   199,     5,     5,   199,
       6,     6,     6,   206,    57,     6,   206,     4,     0,     6,
     189,   190,    65,   189,   190,   195,   196,    70,     4,    13,
       7,   189,   190,   189,   190,   199,   206,   206,    81,   205,
       6,   207,     6,   330,     7,   332,   199,   205,   201,   207,
     206,    81,    82,   189,   190,   189,   190,   189,   190,   199,
      78,     6,   142,   201,    82,     7,   206,   199,   410,   205,
     412,   207,   414,   207,   206,   199,    94,   157,   158,     7,
     189,   190,   195,   196,  1544,   199,     6,   195,   196,   108,
       7,    78,   206,   206,     6,   203,     6,   206,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,  1782,  1783,   145,   145,   146,     6,   142,
     143,   150,   151,   152,   153,   156,   145,   156,   145,   130,
     183,     6,   153,   162,   163,   145,     6,   189,   190,   168,
     169,     4,   195,   196,   187,   184,   132,   133,   134,   135,
     203,   199,   206,   175,   175,   199,   201,   201,   211,   203,
     213,   203,   175,   208,   208,   218,   199,   199,   206,   222,
     210,  1641,   225,   206,   206,  1275,   229,   230,   231,   232,
     206,   206,   235,   236,   237,   206,   206,   206,   206,  1659,
     243,   244,   245,   206,   199,   206,   249,   250,   206,   206,
     206,   206,   206,   176,   177,   178,   179,     7,   505,   506,
       3,   187,   199,     6,   201,   189,   190,   199,   271,   272,
     273,   207,   195,   196,   176,   177,   178,   179,   525,     7,
     203,     6,   285,   286,   189,   190,   195,   196,   176,   177,
     178,   179,   130,   195,   196,   298,   199,   300,   201,   176,
     177,   178,   179,     6,   606,   208,   608,   195,   196,     4,
     130,   290,     6,     7,    57,     7,   189,   190,   195,   196,
       6,   189,   190,   195,   196,   189,   190,    70,   307,   142,
     143,   202,   205,   336,   205,   338,   339,   205,    81,   586,
     199,   205,   201,   199,   414,   201,   203,   203,   351,   208,
     206,   208,   208,   600,   344,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   200,
     672,   202,     7,   198,   676,   206,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,     7,   391,   392,
     393,   394,   395,   189,   190,   201,   399,   400,   401,   402,
     403,   404,     6,   406,     7,   130,     6,   397,  1828,   205,
     105,   106,   107,   108,   199,   405,   189,   190,    81,   114,
     423,    84,   117,   189,   190,   199,   176,   177,   178,   179,
     195,   196,   205,     4,     5,   199,     6,   202,   417,   205,
     183,   189,   190,   195,   196,   195,   196,    88,   176,   177,
     178,   179,   195,   196,   206,   195,   196,   205,   461,    78,
     203,   200,    81,   202,   336,    84,   206,   206,   211,    40,
      41,    42,    43,    44,    45,    46,    47,   199,   189,   190,
      51,    52,    53,    54,   176,   177,   178,   179,    59,    60,
      61,   199,    78,    64,   205,    81,   499,   500,    84,   489,
     490,   491,   492,    81,    75,  1925,    84,   250,   380,   199,
     382,   383,   384,   385,   386,   202,   388,   389,   205,   391,
     392,   393,   199,   395,   201,   514,   515,   399,   400,   401,
     402,   403,     6,    84,   781,    86,   189,   190,   541,   542,
     543,   176,   177,   178,   179,   205,    84,   207,   618,    84,
     553,   554,   205,   189,   190,   200,   176,   177,   178,   179,
     205,    49,    50,   200,    52,   568,   189,   190,   205,   205,
     189,   190,   575,   176,   177,   178,   179,   879,   189,   190,
     199,   883,   205,   189,   190,   195,   196,   206,   206,   160,
     161,   162,    78,   336,   205,    81,   206,    84,    84,   205,
      86,   172,   672,   174,   175,  1670,   676,  1672,   611,  1674,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   195,   196,    81,    84,   198,    84,
      86,    86,   203,   195,   196,   206,   379,   380,   381,   382,
     383,   384,   385,   386,   206,   388,   389,    81,   391,   392,
     393,   394,   395,   205,   101,   207,   399,   400,   401,   402,
     403,   404,   199,   406,   201,   112,   203,   199,   671,   189,
     190,   208,   675,   120,   121,   122,   189,   190,   200,   126,
     127,   128,   129,   205,   205,   205,   207,   677,   189,   190,
     189,   190,   205,  1743,   189,   190,  1746,   189,   190,  1749,
     189,   190,   206,   199,   205,   201,   205,   203,   189,   190,
     205,   714,   208,   205,   962,   718,   205,   200,   721,   189,
     190,   724,   205,   726,   205,   105,   106,   730,   731,   101,
    1032,   111,  1034,   206,  1036,   205,  1038,   199,   728,   201,
     112,   105,   106,     6,     7,  1810,   208,   111,   120,   121,
     122,   754,    84,   823,   126,   127,   128,   129,   200,   199,
     207,   201,   199,   205,   201,   253,   254,    81,   208,    81,
     101,   208,    84,   261,    86,   778,    78,   265,   200,    81,
     202,   112,    84,   205,    86,   189,   190,  1161,  1162,   120,
     121,   122,  1166,  1167,    81,   126,   127,   128,   129,   189,
     190,   191,   192,   193,   205,  1855,   207,    84,   198,   879,
       4,   554,  1877,   883,  1879,   200,  1881,   202,     8,   889,
     890,   200,  1887,   826,     4,   828,   205,   200,   831,   191,
     192,   193,   205,   199,   199,   207,   198,   840,     4,   842,
     200,   844,   202,   846,   205,   205,   207,     4,   851,   721,
     205,   199,   207,   856,   726,  1905,   201,   200,  1908,   202,
     199,  1911,   205,   205,  1914,   207,  1931,  1169,  1933,   199,
    1935,   874,   200,     6,   202,   878,   207,   205,   205,   882,
     207,     6,   201,  1185,   230,   231,   232,   890,   199,   235,
     236,   237,   200,   199,   202,     8,   200,   205,   202,   199,
    1950,   205,  1952,   200,  1954,   202,   199,   205,   205,   207,
       7,   199,   915,   983,   984,   199,   205,   920,   207,   199,
     923,   924,   925,   199,   199,   271,   272,   101,  1176,  1432,
    1433,   199,   205,   936,   207,   938,   926,   199,   112,   285,
     286,   205,   199,   207,  1318,  1319,   120,   121,   122,  1323,
    1324,   201,   126,   127,   128,   129,   205,     6,   207,   962,
     206,   206,   965,   966,   967,   968,   945,   946,   205,    84,
     207,    86,   951,   952,    84,   205,    86,   207,   721,   206,
     205,   724,   207,   726,   205,   199,   207,   990,     6,   199,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   199,   206,  1009,  1010,   198,  1012,
     199,  1014,  1015,   199,   199,  1018,  1019,   207,   890,   101,
    1023,  1091,  1092,     6,   512,   513,  1328,   205,     4,   207,
     112,   199,   520,   207,   205,   205,   207,   207,   120,   121,
     122,  1111,  1112,   206,   126,   127,   128,   129,   920,   205,
     199,   207,   924,   925,   205,   205,   207,   207,   205,   205,
     207,   207,   199,   205,   936,   207,   938,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   205,   101,   207,   205,   198,   207,   205,   205,   207,
     207,   199,   206,   112,   207,   206,     4,     5,   205,  1169,
     207,   120,   121,   122,     4,   206,     6,   126,   127,   128,
     129,  1114,  1115,  1116,   205,   205,   207,   207,   990,  1367,
     206,   205,  1125,   207,   205,   207,   207,   205,   205,   207,
     207,   206,    40,    41,    42,    43,    44,    45,    46,    47,
     205,   199,   207,    51,    52,    53,    54,   890,   199,  1128,
    1129,    59,    60,    61,  1133,  1134,    64,   199,  1161,  1162,
     201,   199,  1665,  1166,  1167,   208,   205,    75,   207,   205,
     205,   207,   207,  1176,   205,     6,   207,   920,   205,     6,
     207,   924,   925,   205,   205,   207,   207,  1190,   207,   205,
     205,   207,   207,   936,   205,   938,   207,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,  1214,   206,   206,  1204,   198,   205,  1220,   207,   962,
     205,   201,   207,  1226,   206,  1228,  1229,   205,     6,   207,
    1233,  1234,   205,  1236,   207,  1238,   205,  1240,   207,  1242,
    1243,  1244,   205,   205,   207,   207,   201,   990,  1622,   205,
     201,   207,   160,   161,   162,   205,     6,   207,  1261,   206,
    1330,   101,   145,   208,   172,     6,   174,   175,     6,   206,
       6,     6,   112,  1276,   206,    12,    13,  1280,     6,  1282,
     120,   121,   122,   201,     4,   198,   126,   127,   128,   129,
       7,   203,   200,   207,   202,   206,   784,     7,   205,   205,
       6,     6,     6,   791,     7,     7,     6,     6,     6,   797,
     200,   101,     6,   206,     7,  1318,  1319,     6,     4,     7,
    1323,  1324,   112,     6,     6,     6,    56,    56,   142,    56,
     120,   121,   122,   206,  1337,    56,   126,   127,   128,   129,
     202,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,  1341,    89,   200,     6,     6,   200,    94,    95,   200,
      97,    98,    99,   205,  1367,   200,   103,   207,   205,  1359,
    1373,   205,   205,   205,   200,   205,   200,   202,   101,    40,
    1383,    40,    40,  1386,  1632,    40,     6,     4,     4,   112,
     145,     6,     6,  1463,     6,     6,  1386,   120,   121,   122,
     137,   138,   139,   126,   127,   128,   129,     7,     7,   101,
       7,     7,   145,     7,     7,     7,     7,   207,  1161,  1162,
     112,  1424,  1425,  1166,  1167,   206,   145,     4,   120,   121,
     122,     6,  1679,  1176,   126,   127,   128,   129,  1428,   200,
     205,   200,   205,  1432,  1433,   205,   200,   101,   200,   205,
    1453,     6,  1455,   200,  1457,   203,   207,   206,   112,   202,
      12,    13,   207,     7,   206,  1337,   120,   121,   122,     7,
     207,  1474,   126,   127,   128,   129,   101,     7,  1481,   203,
     206,   206,     6,    40,   207,     6,    40,   112,  1491,     8,
    1480,   206,  1495,    40,    40,   120,   121,   122,     6,     6,
       6,   126,   127,   128,   129,  1495,  1496,  1497,     6,   199,
       7,  1383,     6,     6,   201,   207,   187,  1005,  1521,   199,
       7,   206,     7,    86,     7,     7,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     7,    89,     7,     6,
       4,  1544,    94,    95,     7,    97,    98,    99,     7,     7,
       7,   103,     7,   207,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     7,  1811,     4,   206,   198,     6,  1057,
    1058,  1059,   101,   199,     7,  1318,  1319,  1580,     6,   206,
    1323,  1324,  1585,   112,     7,   137,   138,   139,     7,     7,
       6,   120,   121,   122,  1337,     6,     6,   126,   127,   128,
     129,     7,     6,  1606,    84,     6,     4,     4,     4,   207,
     205,     6,     6,     6,     6,     6,  1619,     6,     4,  1622,
     200,     6,   101,   205,  1367,   203,   200,   200,   200,  1632,
       7,   199,     6,   112,   203,   206,     6,   202,  1641,   200,
    1383,   120,   121,   122,     6,  1648,  1649,   126,   127,   128,
     129,     6,     6,   206,    94,   207,  1659,   206,     6,  1662,
       6,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,  1678,  1665,     6,   207,   198,
    1683,   200,     6,   206,   206,     6,   206,     5,     4,     6,
     206,     3,     4,     6,   206,   206,     7,     9,    10,    11,
     201,   206,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     6,     6,     6,   207,  1732,
       6,   206,   206,   206,     4,   200,    48,    49,    50,     6,
     202,     6,   141,    55,     6,   205,     4,     6,  1751,     6,
       6,     6,     4,     6,    66,    67,    68,     6,     6,     6,
       6,     4,    74,     7,     5,     7,     6,     6,     6,  1772,
       6,     6,   206,     6,   145,    88,     6,     6,     6,     6,
       6,  1771,     6,     6,     6,     6,  1274,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     6,   205,     6,     6,   198,     6,     6,     6,  1812,
       6,  1814,   200,     6,     6,     6,     6,     6,     5,     7,
       6,   203,     6,   206,     6,  1828,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       8,   206,   206,     6,   198,    82,   206,   159,     6,   206,
     206,   163,     6,     6,   207,   167,   168,   169,   170,   171,
     207,   206,   206,   175,   177,   178,   179,   180,   181,     7,
     206,   140,     6,   207,     6,  1865,     6,   189,   190,  1622,
       6,   194,   194,     6,     6,   198,  1889,   199,     6,  1632,
       6,     6,   204,   143,   206,  1898,     6,     6,     6,   212,
     213,   214,   215,     6,   217,   218,   219,   220,  1396,   222,
     223,   224,     6,   206,     6,     6,   229,     6,   206,     7,
       6,   206,  1925,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   247,   206,     6,     6,   198,  1942,
     206,  1944,     6,   256,   257,   101,  1434,     6,  1436,     6,
    1438,     6,   265,   207,     6,   206,     6,     6,     6,     6,
       6,     6,   207,     6,     6,  1453,   200,   199,  1456,  1457,
       6,  1974,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     6,   298,   299,   300,   198,   206,
     206,   206,   206,     6,     6,     6,     6,   310,   311,   312,
     206,   314,     6,     6,     6,   318,   319,   320,     6,   206,
     323,   206,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,  1898,   340,   341,  1772,
     198,   206,   206,     6,     6,     6,     6,     6,     6,     6,
       6,   354,   355,     6,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,     6,  1199,  1775,  1213,
    1942,  1647,  1944,   457,     3,     3,  1661,   390,   487,    -1,
    1363,    -1,    -1,   396,    -1,   398,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,  1974,    -1,   198,    -1,    -1,    -1,    -1,   422,
     423,    -1,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,    -1,    -1,   442,
     443,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,   461,   198,
      -1,    -1,    -1,    -1,   467,  1898,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,   477,   478,     6,    -1,    -1,    -1,
     483,   484,    -1,    -1,    -1,   488,   489,   490,   491,   492,
     493,  1669,   495,  1671,   497,  1673,   499,   500,    -1,    -1,
     101,    -1,    -1,  1681,    -1,    -1,  1684,    -1,    -1,  1942,
      -1,  1944,    -1,    -1,   517,   518,   519,   520,   521,   522,
      -1,    -1,    -1,   526,   527,   528,   529,   530,    -1,    -1,
      -1,   534,    -1,   536,   537,    -1,    -1,    -1,   541,   542,
     543,  1974,    -1,   546,   547,   548,   549,   550,    -1,    -1,
     553,   554,    -1,  1731,   557,    -1,    -1,  1735,    12,    13,
      -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,
      -1,   574,   575,    -1,   577,   578,    -1,    -1,    -1,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   598,   599,   198,   601,   602,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,   611,  1787,
      -1,    -1,   615,  1791,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,  1814,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   678,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    12,    13,    -1,  1875,  1876,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,   711,    -1,
      -1,   714,   715,   716,    -1,   718,   719,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   727,    -1,    -1,   730,   731,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     753,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    -1,   778,    94,    95,    -1,    97,
      98,    99,   785,   786,    -1,   103,    -1,    -1,   791,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,   804,   218,    -1,   807,    -1,   222,    -1,    -1,    -1,
       6,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,   137,
     138,   139,    -1,   826,    -1,   828,    -1,    -1,   831,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   840,    -1,   842,
      -1,   844,    -1,   846,    -1,    -1,    -1,    -1,   851,    -1,
      -1,    -1,    -1,   856,    -1,    -1,    12,    13,    -1,   862,
      -1,   864,   865,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,   298,    -1,   300,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   911,   912,
     913,    -1,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   935,    89,    -1,    -1,    -1,   940,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   949,   103,    -1,    -1,
      -1,    -1,   955,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,   965,   966,   967,   968,    -1,    -1,   971,    -1,
      -1,    -1,    -1,   243,   244,   245,    -1,    -1,    -1,   249,
      -1,   137,   138,   139,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,   273,    -1,    -1,    -1,   423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1033,    -1,  1035,    -1,  1037,    -1,  1039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,  1061,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,   339,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,   499,   500,    -1,    -1,  1090,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1099,    -1,  1101,  1102,
    1103,    -1,    -1,    -1,    -1,    -1,  1109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   541,   542,   543,  1131,    -1,
      -1,    -1,    -1,  1136,    -1,    -1,    -1,   553,   554,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,   575,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,  1177,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,  1189,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   611,    -1,    -1,    -1,    -1,
    1203,  1204,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    98,    99,    -1,    -1,    -1,
     103,    -1,    -1,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,  1250,  1251,  1252,
      -1,   198,    -1,    -1,    12,    13,    -1,    -1,  1261,    -1,
    1263,    -1,    -1,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1282,
      -1,    12,    13,    -1,  1287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,    -1,
      -1,    -1,   718,    -1,    -1,    -1,    -1,  1310,  1311,  1312,
      -1,    -1,    -1,    -1,   730,   731,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,   207,    -1,    94,    95,    -1,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,  1360,    89,    -1,
      -1,     6,   778,    94,    95,    -1,    97,    98,    99,   213,
      -1,  1374,   103,    -1,   218,    -1,  1379,    -1,   222,   137,
     138,   139,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,  1394,  1395,    -1,    -1,    -1,    -1,    -1,  1401,  1402,
      -1,   671,    -1,  1406,    -1,   675,   137,   138,   139,    -1,
     826,  1414,   828,    -1,    -1,   831,    -1,    -1,    -1,    -1,
      -1,  1424,  1425,  1426,   840,  1428,   842,    -1,   844,    -1,
     846,    -1,    -1,    -1,    -1,   851,    -1,  1440,    -1,    -1,
     856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
    1453,    -1,    -1,    -1,  1457,    -1,    -1,  1460,    -1,    -1,
      -1,    -1,    -1,    -1,  1467,  1468,  1469,  1470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,  1480,    -1,    -1,
      -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1496,    -1,    -1,    -1,    -1,    -1,   915,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1519,  1520,    -1,    -1,
      -1,    -1,    -1,    -1,  1527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   965,
     966,   967,   968,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1565,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     6,    89,   423,
    1583,    -1,  1585,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,  1601,    -1,
    1603,    -1,    -1,  1606,   874,    -1,    -1,  1023,   878,    -1,
      -1,    -1,   882,    -1,    -1,    -1,  1619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,    -1,  1642,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   923,    -1,   499,   500,     7,     8,  1662,
      -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,  1671,    -1,
    1673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1683,    -1,    -1,    -1,  1687,  1688,  1689,  1690,  1691,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   541,   542,   543,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1711,  1712,
      -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   568,  1728,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1739,    -1,    -1,  1009,
    1010,    -1,  1012,    -1,  1014,  1015,    -1,    -1,  1018,  1019,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,  1769,   611,    -1,   198,
      -1,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,  1798,    -1,    -1,  1801,    -1,
      -1,  1804,    -1,    -1,    -1,  1808,    -1,    -1,    -1,  1812,
      -1,  1814,  1815,  1816,  1817,  1818,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1826,    -1,    -1,  1829,    12,    13,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,  1114,  1115,  1116,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,  1125,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,  1282,    89,     6,    -1,
     714,  1874,    94,    95,   718,    97,    98,    99,    -1,    -1,
      -1,   103,    -1,    -1,    -1,    -1,  1889,    -1,  1891,  1892,
    1893,  1894,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    98,    99,   137,   138,   139,   103,    -1,
    1190,    -1,    -1,    -1,    -1,  1928,  1929,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   778,  1938,  1939,  1940,  1941,    -1,
      -1,    -1,    -1,    -1,  1214,    -1,    -1,    -1,    -1,    -1,
    1220,    -1,   137,   138,   139,    -1,  1226,    -1,  1228,  1229,
      -1,    -1,     6,  1233,  1234,    -1,  1236,    -1,  1238,    -1,
    1240,    -1,  1242,  1243,  1244,    -1,    -1,    -1,    -1,    -1,
      -1,     6,   826,    -1,   828,   207,    -1,   831,    -1,    -1,
      -1,  1261,    -1,    -1,    -1,    -1,   840,    -1,   842,    -1,
     844,    -1,   846,    -1,    -1,    -1,  1276,   851,  1424,  1425,
    1280,    -1,   856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   579,    -1,    -1,    -1,    -1,  1453,    -1,    -1,
      -1,  1457,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     6,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   915,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,    -1,   631,   632,   633,   634,   635,   636,
     637,    -1,    -1,    -1,   641,   642,   643,    -1,    -1,    -1,
     647,   648,     7,  1373,    -1,    -1,   653,   654,   655,    -1,
     657,    -1,    -1,    -1,    -1,    -1,  1386,   664,   665,    -1,
      -1,   965,   966,   967,   968,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   682,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,  1585,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,  1023,
      -1,    -1,    -1,    -1,    -1,  1455,    -1,    -1,    -1,    -1,
    1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1619,  1474,    -1,    -1,    -1,    -1,    -1,
      -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1491,    -1,    -1,    -1,  1495,    -1,    -1,    -1,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,  1662,    -1,   198,    -1,
      -1,  1521,     8,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,  1683,    -1,    -1,
      -1,   198,    -1,   200,  1544,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
    1580,     3,     4,     5,   198,    -1,   200,     9,    10,    11,
      -1,   205,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     8,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     8,    -1,    -1,    59,    60,    61,
      -1,  1641,    64,    -1,    66,    67,    68,    -1,  1648,  1649,
      -1,    -1,    74,    75,    -1,    -1,    -1,     8,    -1,  1659,
      -1,    -1,    -1,    -1,    -1,    -1,  1812,    -1,  1814,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   970,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,  1282,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1003,  1004,    -1,    -1,
      -1,   153,  1732,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,  1889,    -1,   167,   168,   169,   170,   171,
     172,  1751,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,   201,
      -1,   203,   204,    -1,   206,    -1,   208,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,  1828,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
    1424,  1425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1139,    -1,    -1,    -1,    -1,    -1,  1145,  1146,
    1147,  1148,  1149,    -1,    -1,    -1,    -1,    -1,  1155,  1156,
      -1,    -1,  1159,  1160,  1161,    -1,    -1,    -1,    -1,  1166,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,  1925,    -1,   198,    -1,    -1,
      -1,     3,     4,    -1,   205,    -1,   207,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    12,    13,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,  1292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,  1305,    -1,
      -1,    -1,  1606,   105,   106,   107,   108,   109,    -1,    -1,
      -1,  1318,   114,    -1,    -1,   117,  1323,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,    -1,   103,    -1,    -1,    -1,  1353,  1354,    -1,    -1,
    1357,  1358,    -1,    -1,    -1,    -1,    -1,   159,  1662,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,   137,   138,   139,  1683,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   207,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,     3,     4,
      -1,   205,    -1,   207,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,  1484,  1485,    -1,
      55,  1488,  1489,    -1,    -1,    -1,    -1,  1494,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,  1812,    84,
    1814,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,  1889,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
      -1,    -1,   207,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,
      -1,     3,     4,     5,   204,    -1,   206,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,
       4,     5,   204,    -1,   206,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,    -1,
      64,    -1,    66,    67,    68,    -1,     3,     4,     5,    -1,
      74,    75,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
     204,    -1,   206,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,   159,   160,   161,   162,   163,    -1,    -1,   206,
     167,   168,   169,   170,   171,   172,    -1,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,     5,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,     4,     5,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     3,     4,     5,   204,    -1,   206,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
     172,    -1,   174,   175,    55,    -1,    -1,    -1,    -1,    -1,
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
       3,     4,     5,   204,    -1,   206,     9,    10,    11,    -1,
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
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,     5,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,     3,     4,    -1,   204,
      -1,   206,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,   172,    -1,   174,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     3,     4,    -1,   204,    -1,   206,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,    -1,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
      -1,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     3,     4,    -1,   204,    -1,   206,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,    -1,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
      -1,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,     3,     4,     5,    -1,    -1,    74,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,   159,   198,    -1,   200,   163,   202,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,     3,     4,    -1,    -1,
     199,    -1,     9,    10,    11,   204,    -1,    14,    15,    16,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,     3,     4,
      -1,    -1,   199,    -1,     9,    10,    11,   204,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    66,    67,    68,    -1,     9,    10,    11,    -1,    74,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,   207,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   199,   200,    -1,    -1,    -1,   204,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,   159,    -1,    -1,   198,   163,
      -1,    -1,   202,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,     3,     4,   202,    -1,
     204,    -1,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    66,
      67,    68,    -1,     9,    10,    11,    -1,    74,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,   207,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,   159,    -1,    -1,   198,   163,    -1,    -1,
     202,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,     3,     4,   202,     6,   204,    -1,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
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
     159,    -1,    -1,    -1,   163,   207,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     0,     1,    -1,   204,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,    -1,    -1,    -1,   194,    -1,    56,    57,
      58,   199,    -1,    -1,    62,    63,   204,    65,    -1,    -1,
      -1,    69,    70,    -1,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,   124,   125,     4,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    12,    13,   136,   137,
     138,   139,    -1,    -1,   142,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    -1,    38,    39,    -1,    -1,   164,   165,   166,    -1,
      -1,    -1,    -1,    -1,    -1,   173,    -1,   175,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    69,    70,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,    -1,    -1,   142,    -1,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,   175,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   180,   181,   182,   183,   184,   185,   186,   187,
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
     198,    -1,    -1,    -1,    -1,    -1,    -1,   205,   180,   181,
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
      -1,    -1,   198
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
     199,   199,   199,   199,   296,   199,   296,   199,   296,   206,
     206,   290,     4,   296,   300,   206,   206,   293,   293,   293,
     290,   290,   189,   190,   206,   206,   293,   206,   206,   206,
     189,   190,   199,   257,   293,   206,   199,   206,   199,   199,
     199,   297,   297,   296,   199,     4,   201,   201,   257,     6,
       6,   206,   206,   206,   297,   297,   201,   201,   201,   199,
     201,   203,   233,   199,   201,     5,   145,   206,     5,   145,
       5,   145,     5,   145,    78,    81,    84,    86,   206,   290,
     298,   290,   207,   299,     8,   191,     6,   199,   201,   233,
       6,   290,   290,   290,   203,   290,   206,   145,   290,   290,
     290,   290,     6,     6,     6,   257,     6,   257,   199,   201,
     206,   199,   201,   303,   296,   296,   200,   290,   202,   290,
     206,   206,   304,   296,     6,   201,   290,   290,     4,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   306,   303,   306,   303,   303,   303,   303,   303,   296,
     303,   303,   290,   303,   303,   303,   306,   303,   290,   304,
     290,   303,   303,   303,   303,   303,   308,   304,   308,     7,
     176,   231,   200,     7,   176,   231,   202,     7,   231,   232,
     203,     7,   233,   207,    78,    81,    84,    86,   254,   290,
     299,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   216,   290,   290,     6,
     199,   201,   203,   200,   205,   199,   201,   200,   205,   205,
     200,   205,   202,   205,   236,   202,   236,   205,   205,   200,
     191,   205,   207,   200,   200,   290,   200,   207,   200,   200,
     290,   207,   200,   200,     7,   290,   290,   207,     6,     6,
       6,   290,   290,     7,     7,   283,   283,   290,   248,   290,
     304,   249,   290,   304,   250,   290,   304,   251,   290,   304,
     290,     6,   290,     6,   290,     6,   299,   299,   206,   200,
       6,   206,   257,   257,   205,   205,   205,   293,   293,   256,
     256,   205,   290,   290,   290,   290,   269,   205,   257,   290,
     290,   290,   290,   290,     7,   284,     6,     7,   290,     6,
     290,   290,   207,   299,   299,   299,     6,     6,   290,   290,
     290,   290,   290,     4,   200,   202,   206,   234,   206,   290,
     298,   206,   298,   308,    56,   290,    56,    56,    56,     5,
     206,     5,   206,     5,   206,     5,   206,   299,   200,   207,
     290,   206,   290,   298,   290,   290,   206,   234,   200,   200,
     200,   142,   205,   257,   206,     8,   200,   200,   202,   207,
     207,   257,   202,   200,   205,   207,     7,   176,   231,   200,
       7,   176,   231,   202,   290,   299,     6,     6,   290,   200,
     202,   232,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   205,   234,   234,   234,   234,   234,   234,
     234,   205,   205,   205,   234,   205,   234,   234,   200,   200,
     205,   234,   234,   205,   205,   205,   205,   234,   234,   234,
     200,   234,   292,   305,     6,   205,   205,   200,   205,   234,
     205,   234,   200,   200,   202,    40,    40,   296,     7,   231,
     232,    40,    40,   296,   203,   231,   232,   304,   290,     6,
       4,     4,   206,   301,   234,   206,   206,   206,   206,   207,
     207,     8,     4,   132,   133,   134,   135,   207,   219,   223,
     226,   228,   229,   200,   202,   290,   290,     4,     6,   187,
     213,   299,   290,   290,     6,   299,   290,     6,   303,     6,
     308,     6,   303,   290,   304,     7,   290,   298,   145,     7,
       7,   200,     7,   145,     7,     7,   200,   145,     7,     7,
     290,   200,   207,   206,   200,   200,   290,   296,     4,   282,
       6,   200,   200,   205,   200,   205,   200,   205,   200,   205,
     200,   200,   200,   207,   207,   299,   203,   257,   207,   207,
     293,   290,   290,   207,   207,   290,   293,   205,   205,   205,
     101,   112,   120,   121,   122,   126,   127,   128,   129,   279,
     280,   293,   207,   266,   200,   207,   200,   200,   200,   290,
       6,   290,   200,   202,   202,   207,   207,   207,   202,   202,
     205,   200,   202,   299,   299,   200,   299,   202,   202,   206,
     207,   206,   206,   206,   299,   299,   299,   299,   207,     8,
     299,   200,   202,   299,     7,     7,     7,   203,   290,   207,
     290,   290,     7,   203,   207,   206,   296,     6,    40,    40,
     296,   231,   232,    40,    40,   296,   231,   232,   207,   207,
     202,   232,   203,   232,   303,   290,   290,   290,   290,   299,
     303,   296,   303,   303,   304,   244,   246,   290,   303,   303,
     290,   233,   233,     6,   290,     6,   233,   233,     6,     4,
     142,   143,   290,     6,     6,     6,     7,   201,   300,   302,
       6,   299,   299,   299,   299,   234,   290,   220,   199,   199,
     206,   230,     6,   232,   232,   200,   202,   187,   303,   200,
     200,   202,   200,   205,     7,   199,   201,   234,   234,   293,
      84,    86,   296,   296,     7,   296,    84,    86,   296,   296,
       7,    86,   296,   296,     6,     7,     7,   299,     7,     7,
     101,   281,     6,     7,   231,   290,   231,   290,   231,   290,
     231,   290,     7,     7,     7,     7,     7,   207,     4,   207,
     205,   205,   205,   207,   207,   293,   293,   293,     4,     6,
     290,   206,     6,   199,     6,   130,     6,   130,     6,   130,
       6,   130,   207,   280,   205,   279,     7,     6,     7,     7,
       7,     6,   206,     6,     6,     6,    84,     7,     6,     6,
     290,   203,   207,   207,   207,   290,   290,   290,   290,   207,
     207,   207,   207,   290,   207,   207,   296,   296,   296,     4,
     205,     8,     8,   200,     4,     4,   296,   207,   233,   233,
       6,   290,     6,   233,   233,     6,   290,     6,   234,     6,
       4,     6,   234,   234,   234,   234,   234,   205,   200,   200,
     200,   205,   205,   234,   245,   205,   234,   247,   200,   200,
     234,   234,   234,   306,   306,     6,   234,   306,   306,     7,
     231,   232,   203,     7,     6,   300,   290,   205,   207,   207,
     207,   207,   207,   231,   199,   290,   290,   295,   296,   206,
     203,     6,     6,   213,     6,   290,   206,   290,   304,   200,
     202,     6,     6,     6,   206,   206,    94,   253,   253,   296,
       6,   206,   206,     6,     6,   296,   206,     6,     6,     5,
     296,   207,   296,   296,     4,     6,   296,   296,   296,   296,
     296,   296,   296,   296,   206,   206,     7,     6,     7,   290,
     290,   290,   206,   206,   205,   207,   205,   207,   205,   207,
     201,     6,   290,   296,   290,     6,     6,     6,     6,   290,
     293,   207,     5,   206,   296,   206,   206,   206,   296,   299,
     206,   290,   202,     4,   234,   200,   202,   205,   205,   205,
     205,   234,     6,     6,   141,   290,   290,   290,     6,     6,
       7,   205,     6,   234,   306,   306,     6,   234,   306,   306,
       6,   231,   232,   303,   304,     4,     4,   156,     6,   234,
     234,     6,   234,   234,   304,   290,     6,     4,   301,     6,
     202,   300,     6,     6,     6,     6,   296,   217,   290,   205,
     205,   205,   207,   218,   290,     4,   303,   205,   296,   304,
       7,     7,   290,   290,   293,     6,     6,     6,   290,   290,
       6,   290,     5,     6,   206,     6,   145,   252,   290,     6,
       6,     6,     6,     6,     6,     4,     6,     6,   299,   299,
     290,   290,   304,   207,   200,   205,   207,   256,   256,   293,
       6,   270,   293,     6,   271,   293,     6,   272,   290,   207,
     205,   200,   207,   205,     6,   190,   293,     6,   295,   293,
     293,     6,   207,   290,     6,     6,   290,   290,   290,   290,
     296,   205,   207,     8,   207,   200,   206,   290,   304,   296,
       6,   234,   234,     6,   234,   234,   296,   200,   234,   206,
     296,   304,   206,   290,   304,   304,     6,     6,     6,     6,
       6,     6,     7,     6,   203,     6,   200,   205,   290,   290,
     296,   206,   205,   207,     6,   290,   238,   241,   206,   206,
     207,   207,   207,   207,   207,     5,   295,    82,     6,   206,
     207,   207,   206,     6,     6,   206,   290,   207,   207,   205,
     206,   205,   206,   205,   206,   202,     6,   296,     7,   206,
     290,   205,   207,   205,   205,     6,   207,   205,   205,   205,
     205,   140,   290,   290,   299,     6,     6,   207,     6,     6,
       6,     6,     6,   243,   290,   298,   306,   300,   143,   221,
     290,   205,   205,   295,   290,     6,   205,   244,   246,   296,
     296,     6,     6,     6,     6,     6,     6,   207,   206,   295,
     105,   106,   111,   285,   105,   106,   285,   299,   256,   205,
     207,   290,   293,   279,   290,   293,   279,   290,   293,   279,
       6,   205,   207,   296,   257,   207,   293,     6,   299,   293,
     290,   290,   290,   290,   290,   207,   207,   207,     6,   205,
     207,     7,     7,   207,     6,   206,   290,   290,   207,   290,
     207,   207,   240,   239,   206,   290,   207,   206,   293,   296,
       6,   206,   293,     6,   207,   207,   290,   207,   205,   207,
     207,   205,   207,   207,   205,   207,   296,     6,   101,   207,
     267,   206,   205,   207,   205,   205,   205,   205,   205,     6,
       6,   290,   304,   308,   218,   200,   205,     6,   206,   205,
     244,   244,   290,   207,     6,   293,     6,   293,     6,     6,
     207,     6,   273,   290,     6,     6,   274,   290,     6,     6,
     275,   290,     6,   207,   290,   279,   257,   299,     6,   293,
     299,   290,   290,   290,   290,     7,   199,   207,   224,   290,
     295,   290,   207,   207,   205,   205,   205,   206,   207,   206,
     207,   206,   207,     6,     6,   207,   207,   268,   207,   205,
     207,   205,   205,   205,   205,   304,   200,     6,   206,   200,
     207,   207,   290,   293,   293,   279,     6,   276,   279,     6,
     277,   279,     6,   278,   279,     6,   299,     6,   290,   290,
     290,   290,   222,   303,   227,   206,     6,   207,   205,   205,
     207,   206,   207,   206,   207,   206,   207,   207,   205,   205,
     205,   205,   205,   207,   206,   295,     6,   290,   290,     6,
     279,     6,   279,     6,   279,     6,   290,   290,   290,   290,
     303,     6,   225,   303,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   205,   207,     6,     6,     6,     6,
       6,     6,   303,     6
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
     240,   237,   237,   241,   237,   242,   242,   243,   243,   243,
     244,   244,   245,   245,   245,   246,   246,   247,   247,   247,
     247,   248,   248,   248,   249,   249,   249,   250,   250,   250,
     251,   251,   251,   252,   252,   253,   253,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   255,
     255,   255,   255,   255,   255,   255,   255,   256,   256,   257,
     257,   257,   257,   257,   257,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   259,   259,   259,   259,   259,   260,
     260,   261,   262,   262,   262,   262,   262,   262,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   265,   265,   265,   266,   265,   267,   265,   268,   265,
     269,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   270,   265,   271,   265,   272,   265,   273,   265,   274,
     265,   275,   265,   276,   265,   277,   265,   278,   265,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   281,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   288,   288,   288,   289,
     289,   289,   289,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   292,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   293,   293,   293,   293,   293,   294,   294,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   297,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   299,   299,   299,   299,   300,   300,   300,
     300,   301,   301,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   304,   306,
     306,   307,   307,   308,   308,   308
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
       0,    11,     5,     0,     9,     0,     3,     3,     5,     5,
       0,     2,     3,     5,     3,     0,     2,     3,     3,     3,
       5,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     0,     5,     0,     2,     7,     8,     6,
       7,     4,     7,     8,     8,     7,     7,    11,     8,     4,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     8,
       4,     8,    12,     8,     8,     7,     4,     8,     8,     5,
      11,     5,     9,     9,     4,     9,     9,     1,     1,     0,
       2,     6,     6,     6,     6,     8,    10,    14,    16,    12,
       8,     8,     6,    14,     4,     6,     6,     3,     4,     5,
       6,     5,     3,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     2,     2,    16,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     8,     8,     8,    12,    12,    12,    14,    14,
      14,     0,    12,     0,    12,     0,    12,     0,    16,     0,
      16,     0,    16,     0,    18,     0,    18,     0,    18,     1,
       2,     5,     7,     9,     2,     2,     3,     2,     3,     2,
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
      16,    16,     1,     1,     3,     3,     4,     4,     4,     6,
       6,     6,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     4,
       4,     3,     6,     1,     4,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     4,     8,     4,     4,     4,     4,
       8,     4,     6,     4,     1,     4,     4,     0,     6,     1,
       3,     5,     5,     1,     1,     4
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
#line 200 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 225 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 226 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 235 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4968 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 242 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 247 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 252 "Gmsh.y" /* yacc.c:1646  */
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
#line 5004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 266 "Gmsh.y" /* yacc.c:1646  */
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
#line 5021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 279 "Gmsh.y" /* yacc.c:1646  */
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
#line 5038 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 292 "Gmsh.y" /* yacc.c:1646  */
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
#line 5065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 320 "Gmsh.y" /* yacc.c:1646  */
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
#line 5083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 334 "Gmsh.y" /* yacc.c:1646  */
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
#line 5100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 347 "Gmsh.y" /* yacc.c:1646  */
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
#line 5117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 360 "Gmsh.y" /* yacc.c:1646  */
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
#line 5136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 378 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 5146 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 394 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 399 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5164 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 401 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 406 "Gmsh.y" /* yacc.c:1646  */
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
#line 5278 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 510 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 5292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 520 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 529 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 536 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 546 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 5337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 555 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 564 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 571 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5369 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 581 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 5381 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 589 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 599 "Gmsh.y" /* yacc.c:1646  */
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
#line 5411 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 618 "Gmsh.y" /* yacc.c:1646  */
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
#line 5431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 637 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 654 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5490 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 675 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 680 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 686 "Gmsh.y" /* yacc.c:1646  */
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
#line 5599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 748 "Gmsh.y" /* yacc.c:1646  */
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
#line 5618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 765 "Gmsh.y" /* yacc.c:1646  */
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
#line 5651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 794 "Gmsh.y" /* yacc.c:1646  */
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
#line 5684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 823 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 828 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 833 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 838 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 843 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 860 "Gmsh.y" /* yacc.c:1646  */
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
#line 5775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 889 "Gmsh.y" /* yacc.c:1646  */
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
#line 5808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 918 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 923 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 928 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 933 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 941 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 950 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5863 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 956 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5872 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 962 "Gmsh.y" /* yacc.c:1646  */
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
#line 5888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 975 "Gmsh.y" /* yacc.c:1646  */
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
#line 5904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 988 "Gmsh.y" /* yacc.c:1646  */
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
#line 5922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1003 "Gmsh.y" /* yacc.c:1646  */
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
#line 5940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1020 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1026 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1032 "Gmsh.y" /* yacc.c:1646  */
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
#line 5974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1045 "Gmsh.y" /* yacc.c:1646  */
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
#line 5990 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1058 "Gmsh.y" /* yacc.c:1646  */
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
#line 6008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1073 "Gmsh.y" /* yacc.c:1646  */
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
#line 6026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1090 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1096 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6046 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1105 "Gmsh.y" /* yacc.c:1646  */
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
#line 6068 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1123 "Gmsh.y" /* yacc.c:1646  */
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
#line 6090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1141 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 6103 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1150 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 6116 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1162 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1167 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1175 "Gmsh.y" /* yacc.c:1646  */
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
#line 6158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1195 "Gmsh.y" /* yacc.c:1646  */
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
#line 6182 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1218 "Gmsh.y" /* yacc.c:1646  */
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
#line 6197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1229 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 6209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1237 "Gmsh.y" /* yacc.c:1646  */
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
#line 6235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1259 "Gmsh.y" /* yacc.c:1646  */
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
#line 6262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1282 "Gmsh.y" /* yacc.c:1646  */
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
#line 6292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1308 "Gmsh.y" /* yacc.c:1646  */
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
#line 6314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1329 "Gmsh.y" /* yacc.c:1646  */
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
#line 6330 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1341 "Gmsh.y" /* yacc.c:1646  */
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
#line 6346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1359 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 6359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1368 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 6372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1377 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1379 "Gmsh.y" /* yacc.c:1646  */
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
#line 6400 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1397 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1399 "Gmsh.y" /* yacc.c:1646  */
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
#line 6426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1415 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1417 "Gmsh.y" /* yacc.c:1646  */
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
#line 6452 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1433 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6465 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1442 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1444 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1458 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1466 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1472 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1477 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      int n = List_Nbr((yyvsp[-4].l));
      if(!gmsh_yystringsymbols.count((yyvsp[-2].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[-2].c));
      }
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[-2].c)]);
        int m = s.size();
        if(n == m){
          for(int i = 0; i < n; i++){
            double d;
            List_Read((yyvsp[-4].l), i, &d);
            doubleXstring v = {d, strsave((char*)s[i].c_str())};
            List_Add((yyval.l), &v);
          }
        }
        else{
          yymsg(0, "Size mismatch in enumeration: %d != %d", n, m);
        }
      }
      List_Delete((yyvsp[-4].l));
    }
#line 6542 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1508 "Gmsh.y" /* yacc.c:1646  */
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
#line 6557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1519 "Gmsh.y" /* yacc.c:1646  */
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
#line 6575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1534 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1550 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1558 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1567 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1575 "Gmsh.y" /* yacc.c:1646  */
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
#line 6638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1593 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1597 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1603 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6665 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1611 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1615 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1621 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1629 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1633 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1639 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1647 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1651 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1657 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1665 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1669 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 6768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1681 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1685 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1695 "Gmsh.y" /* yacc.c:1646  */
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
#line 6811 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1718 "Gmsh.y" /* yacc.c:1646  */
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
#line 6858 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1761 "Gmsh.y" /* yacc.c:1646  */
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
#line 6882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1784 "Gmsh.y" /* yacc.c:1646  */
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
#line 6904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1802 "Gmsh.y" /* yacc.c:1646  */
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
#line 6929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1823 "Gmsh.y" /* yacc.c:1646  */
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
#line 6951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1841 "Gmsh.y" /* yacc.c:1646  */
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
#line 6985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1871 "Gmsh.y" /* yacc.c:1646  */
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
#line 7019 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1901 "Gmsh.y" /* yacc.c:1646  */
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
#line 7041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1919 "Gmsh.y" /* yacc.c:1646  */
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
#line 7063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1938 "Gmsh.y" /* yacc.c:1646  */
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
#line 7093 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1964 "Gmsh.y" /* yacc.c:1646  */
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
#line 7115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1983 "Gmsh.y" /* yacc.c:1646  */
    {
     GModel::current()->getGEOInternals()->addCompoundMesh ( 1 , (yyvsp[-1].l) );      
   }
#line 7123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1988 "Gmsh.y" /* yacc.c:1646  */
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
#line 7145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2006 "Gmsh.y" /* yacc.c:1646  */
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
#line 7192 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2052 "Gmsh.y" /* yacc.c:1646  */
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
#line 7214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2070 "Gmsh.y" /* yacc.c:1646  */
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
#line 7257 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2109 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7267 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2115 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2121 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2128 "Gmsh.y" /* yacc.c:1646  */
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
#line 7317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2153 "Gmsh.y" /* yacc.c:1646  */
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
#line 7346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2178 "Gmsh.y" /* yacc.c:1646  */
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
#line 7367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2195 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 2 , (yyvsp[-1].l) );      
    }
#line 7375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2199 "Gmsh.y" /* yacc.c:1646  */
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
#line 7398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2219 "Gmsh.y" /* yacc.c:1646  */
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
#line 7435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2252 "Gmsh.y" /* yacc.c:1646  */
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
#line 7482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2299 "Gmsh.y" /* yacc.c:1646  */
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
#line 7504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2317 "Gmsh.y" /* yacc.c:1646  */
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
#line 7525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2334 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->getGEOInternals()->addCompoundMesh ( 3 , (yyvsp[-1].l) );      
    }
#line 7533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2338 "Gmsh.y" /* yacc.c:1646  */
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
#line 7553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2354 "Gmsh.y" /* yacc.c:1646  */
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
#line 7600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2402 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2407 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2412 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2417 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7636 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2422 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2427 "Gmsh.y" /* yacc.c:1646  */
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
#line 7672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2450 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2456 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2466 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2467 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2476 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2480 "Gmsh.y" /* yacc.c:1646  */
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
#line 7749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2503 "Gmsh.y" /* yacc.c:1646  */
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
#line 7776 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2526 "Gmsh.y" /* yacc.c:1646  */
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
#line 7803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2549 "Gmsh.y" /* yacc.c:1646  */
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
#line 7830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2577 "Gmsh.y" /* yacc.c:1646  */
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
#line 7855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2598 "Gmsh.y" /* yacc.c:1646  */
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
#line 7885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2625 "Gmsh.y" /* yacc.c:1646  */
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
#line 7909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2646 "Gmsh.y" /* yacc.c:1646  */
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
#line 7934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2667 "Gmsh.y" /* yacc.c:1646  */
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
#line 7958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2687 "Gmsh.y" /* yacc.c:1646  */
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
#line 8074 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2799 "Gmsh.y" /* yacc.c:1646  */
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
#line 8097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2818 "Gmsh.y" /* yacc.c:1646  */
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
#line 8139 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2857 "Gmsh.y" /* yacc.c:1646  */
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
#line 8246 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2965 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2974 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 8269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2980 "Gmsh.y" /* yacc.c:1646  */
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
#line 8288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2995 "Gmsh.y" /* yacc.c:1646  */
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
#line 8320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3023 "Gmsh.y" /* yacc.c:1646  */
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
#line 8336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3040 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3049 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3063 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8375 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3077 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3083 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3089 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3098 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3107 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3116 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8447 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3130 "Gmsh.y" /* yacc.c:1646  */
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
#line 8510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3189 "Gmsh.y" /* yacc.c:1646  */
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
#line 8532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3207 "Gmsh.y" /* yacc.c:1646  */
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
#line 8553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3224 "Gmsh.y" /* yacc.c:1646  */
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
#line 8572 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3239 "Gmsh.y" /* yacc.c:1646  */
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
#line 8602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3265 "Gmsh.y" /* yacc.c:1646  */
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
#line 8618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3277 "Gmsh.y" /* yacc.c:1646  */
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
#line 8646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3301 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3305 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3310 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3317 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3322 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8693 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3328 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3333 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3339 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3347 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3351 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3355 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3361 "Gmsh.y" /* yacc.c:1646  */
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
#line 8807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3420 "Gmsh.y" /* yacc.c:1646  */
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
#line 8828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3437 "Gmsh.y" /* yacc.c:1646  */
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
#line 8849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3454 "Gmsh.y" /* yacc.c:1646  */
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
#line 8875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3476 "Gmsh.y" /* yacc.c:1646  */
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
#line 8901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3498 "Gmsh.y" /* yacc.c:1646  */
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
#line 8940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3533 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3541 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3549 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3555 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3562 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8996 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3569 "Gmsh.y" /* yacc.c:1646  */
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
#line 9020 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3589 "Gmsh.y" /* yacc.c:1646  */
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
#line 9050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3615 "Gmsh.y" /* yacc.c:1646  */
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
#line 9066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3627 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 9076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3639 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 9088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3647 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 9100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3655 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 9112 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9122 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3669 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3683 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3697 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3705 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3719 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9210 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3726 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9221 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3733 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3740 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3747 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3754 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3761 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9276 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3768 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3775 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3782 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9308 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3788 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9319 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3795 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3801 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3808 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3814 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3821 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9371 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3827 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3834 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3840 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3847 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3853 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3860 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3866 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3873 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3879 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3886 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9476 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3892 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3903 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3906 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3912 "Gmsh.y" /* yacc.c:1646  */
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
#line 9517 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3924 "Gmsh.y" /* yacc.c:1646  */
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
#line 9541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3944 "Gmsh.y" /* yacc.c:1646  */
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
#line 9568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3968 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3972 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3976 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 9592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3980 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3984 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3988 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9618 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3994 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4000 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9636 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4004 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4008 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4012 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9660 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4016 "Gmsh.y" /* yacc.c:1646  */
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
#line 9683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4035 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4047 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4051 "Gmsh.y" /* yacc.c:1646  */
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
#line 9720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4066 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4070 "Gmsh.y" /* yacc.c:1646  */
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
#line 9746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4086 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4090 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4095 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4099 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4105 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4109 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4116 "Gmsh.y" /* yacc.c:1646  */
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
#line 9854 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4172 "Gmsh.y" /* yacc.c:1646  */
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
#line 9928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4242 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9937 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4247 "Gmsh.y" /* yacc.c:1646  */
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
#line 10008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4314 "Gmsh.y" /* yacc.c:1646  */
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
#line 10048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4350 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 10060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4358 "Gmsh.y" /* yacc.c:1646  */
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
#line 10107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4401 "Gmsh.y" /* yacc.c:1646  */
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
#line 10150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4440 "Gmsh.y" /* yacc.c:1646  */
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
#line 10174 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4461 "Gmsh.y" /* yacc.c:1646  */
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
#line 10209 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4493 "Gmsh.y" /* yacc.c:1646  */
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
#line 10239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4520 "Gmsh.y" /* yacc.c:1646  */
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
#line 10268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4546 "Gmsh.y" /* yacc.c:1646  */
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
#line 10297 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4572 "Gmsh.y" /* yacc.c:1646  */
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
#line 10326 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4598 "Gmsh.y" /* yacc.c:1646  */
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
#line 10355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
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
#line 10380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
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
#line 10412 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4673 "Gmsh.y" /* yacc.c:1646  */
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
#line 10444 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4701 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10452 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4705 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4709 "Gmsh.y" /* yacc.c:1646  */
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
#line 10492 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4737 "Gmsh.y" /* yacc.c:1646  */
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
#line 10535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
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
#line 10578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4815 "Gmsh.y" /* yacc.c:1646  */
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
#line 10603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4836 "Gmsh.y" /* yacc.c:1646  */
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
#line 10628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4857 "Gmsh.y" /* yacc.c:1646  */
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
#line 10653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4884 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4888 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10675 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4898 "Gmsh.y" /* yacc.c:1646  */
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
#line 10709 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4932 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4933 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4934 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4939 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4945 "Gmsh.y" /* yacc.c:1646  */
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
#line 10753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4957 "Gmsh.y" /* yacc.c:1646  */
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
#line 10775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4975 "Gmsh.y" /* yacc.c:1646  */
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
#line 10802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 5002 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 5003 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 5006 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 5007 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 5008 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 5011 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 5017 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 5018 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 5019 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 5021 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 5022 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 5023 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 5024 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 5026 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 5027 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 5028 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 5029 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 5030 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 5031 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 5033 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 5034 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10969 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 5035 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 5036 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 5037 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 5038 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 5039 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 5040 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 11005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 5041 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 11011 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 5042 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 11017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 5043 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 11023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 5044 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 11029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 5045 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 11035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 5047 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 5048 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 11053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 5049 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 11059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 5058 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 11065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 5059 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 11071 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 5060 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 11077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 5061 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 11083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 5062 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 11089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 5063 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 11095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 5064 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5065 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 11107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5066 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 11113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5067 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 11119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5068 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 11125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5073 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11131 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5075 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 11141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5081 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5086 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5091 "Gmsh.y" /* yacc.c:1646  */
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
#line 11180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5108 "Gmsh.y" /* yacc.c:1646  */
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
#line 11202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5126 "Gmsh.y" /* yacc.c:1646  */
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
#line 11224 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5144 "Gmsh.y" /* yacc.c:1646  */
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
#line 11246 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5162 "Gmsh.y" /* yacc.c:1646  */
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
#line 11268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5180 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5185 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 11287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5191 "Gmsh.y" /* yacc.c:1646  */
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
#line 11306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5206 "Gmsh.y" /* yacc.c:1646  */
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
#line 11327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5223 "Gmsh.y" /* yacc.c:1646  */
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
#line 11349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5241 "Gmsh.y" /* yacc.c:1646  */
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
#line 11371 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5259 "Gmsh.y" /* yacc.c:1646  */
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
#line 11393 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5277 "Gmsh.y" /* yacc.c:1646  */
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
#line 11415 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5298 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11424 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5303 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5308 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11447 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5318 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5328 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5333 "Gmsh.y" /* yacc.c:1646  */
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
#line 11485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5344 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11507 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5358 "Gmsh.y" /* yacc.c:1646  */
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
#line 11535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5385 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5389 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11551 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5393 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5397 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5401 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5408 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5412 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5416 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5420 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5427 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5432 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11624 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5439 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5444 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11641 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5448 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11650 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5453 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5457 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5465 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5476 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5480 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5492 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5500 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11727 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5508 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5515 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5525 "Gmsh.y" /* yacc.c:1646  */
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
#line 11785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5554 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5558 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5562 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5566 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5570 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11825 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5574 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5578 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5582 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5586 "Gmsh.y" /* yacc.c:1646  */
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
#line 11882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5615 "Gmsh.y" /* yacc.c:1646  */
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
#line 11915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5644 "Gmsh.y" /* yacc.c:1646  */
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
#line 11948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5673 "Gmsh.y" /* yacc.c:1646  */
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
#line 11981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5703 "Gmsh.y" /* yacc.c:1646  */
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
#line 11997 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5716 "Gmsh.y" /* yacc.c:1646  */
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
#line 12013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5729 "Gmsh.y" /* yacc.c:1646  */
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
#line 12029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5742 "Gmsh.y" /* yacc.c:1646  */
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
#line 12045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5754 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5764 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5774 "Gmsh.y" /* yacc.c:1646  */
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
#line 12089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5786 "Gmsh.y" /* yacc.c:1646  */
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
#line 12105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5799 "Gmsh.y" /* yacc.c:1646  */
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
#line 12121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5811 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5815 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12137 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5819 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 12145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5823 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 12153 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5827 "Gmsh.y" /* yacc.c:1646  */
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
#line 12175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5845 "Gmsh.y" /* yacc.c:1646  */
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
#line 12197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5866 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5871 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5875 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5879 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12235 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5891 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 12243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5895 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 12251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5907 "Gmsh.y" /* yacc.c:1646  */
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
#line 12272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5924 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 12283 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5934 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12291 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5938 "Gmsh.y" /* yacc.c:1646  */
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
#line 12307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5953 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5958 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5965 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5969 "Gmsh.y" /* yacc.c:1646  */
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
#line 12349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5982 "Gmsh.y" /* yacc.c:1646  */
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
#line 12367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5996 "Gmsh.y" /* yacc.c:1646  */
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
#line 12385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 6010 "Gmsh.y" /* yacc.c:1646  */
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
#line 12403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 6024 "Gmsh.y" /* yacc.c:1646  */
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
#line 12421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6038 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6046 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12445 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6057 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6061 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6065 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12473 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6073 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12483 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6079 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6085 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6093 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12517 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6101 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12528 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6108 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6116 "Gmsh.y" /* yacc.c:1646  */
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
#line 12559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6131 "Gmsh.y" /* yacc.c:1646  */
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
#line 12577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6145 "Gmsh.y" /* yacc.c:1646  */
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
#line 12595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6159 "Gmsh.y" /* yacc.c:1646  */
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
#line 12611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6171 "Gmsh.y" /* yacc.c:1646  */
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
#line 12631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6187 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6196 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6205 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6215 "Gmsh.y" /* yacc.c:1646  */
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
#line 12686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 6226 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 6230 "Gmsh.y" /* yacc.c:1646  */
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
#line 12717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 6249 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 6256 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 6262 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 6269 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 6276 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 6278 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 6289 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 6294 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 6300 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 6309 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 6322 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 6325 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 6329 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12839 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6332 "Gmsh.y" /* yacc.c:1906  */


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
