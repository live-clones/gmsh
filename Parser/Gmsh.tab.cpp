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
#define YYLAST   11790

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  552
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1978

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
    1783,  1801,  1822,  1840,  1870,  1900,  1918,  1936,  1963,  1981,
    1999,  2045,  2063,  2102,  2108,  2114,  2121,  2146,  2171,  2188,
    2207,  2241,  2288,  2306,  2323,  2339,  2387,  2392,  2397,  2402,
    2407,  2412,  2435,  2441,  2452,  2453,  2458,  2461,  2465,  2488,
    2511,  2534,  2562,  2583,  2609,  2630,  2652,  2672,  2784,  2803,
    2841,  2950,  2959,  2965,  2980,  3008,  3025,  3034,  3048,  3062,
    3068,  3074,  3083,  3092,  3101,  3115,  3174,  3192,  3209,  3224,
    3250,  3262,  3286,  3290,  3295,  3302,  3307,  3313,  3318,  3324,
    3332,  3336,  3340,  3345,  3405,  3422,  3439,  3461,  3483,  3518,
    3526,  3534,  3540,  3547,  3554,  3574,  3600,  3612,  3624,  3632,
    3640,  3649,  3648,  3663,  3662,  3677,  3676,  3691,  3690,  3704,
    3711,  3718,  3725,  3732,  3739,  3746,  3753,  3760,  3768,  3767,
    3781,  3780,  3794,  3793,  3807,  3806,  3820,  3819,  3833,  3832,
    3846,  3845,  3859,  3858,  3872,  3871,  3888,  3891,  3897,  3909,
    3929,  3953,  3957,  3961,  3965,  3969,  3973,  3979,  3985,  3989,
    3993,  3997,  4001,  4020,  4033,  4036,  4052,  4055,  4072,  4075,
    4081,  4084,  4091,  4094,  4101,  4157,  4227,  4232,  4299,  4335,
    4343,  4386,  4425,  4445,  4477,  4504,  4530,  4556,  4582,  4608,
    4630,  4658,  4686,  4690,  4694,  4722,  4761,  4800,  4821,  4842,
    4869,  4873,  4883,  4918,  4919,  4920,  4924,  4930,  4942,  4960,
    4988,  4989,  4990,  4991,  4992,  4993,  4994,  4995,  4996,  5003,
    5004,  5005,  5006,  5007,  5008,  5009,  5010,  5011,  5012,  5013,
    5014,  5015,  5016,  5017,  5018,  5019,  5020,  5021,  5022,  5023,
    5024,  5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,
    5034,  5035,  5044,  5045,  5046,  5047,  5048,  5049,  5050,  5051,
    5052,  5053,  5054,  5059,  5058,  5066,  5071,  5076,  5093,  5111,
    5129,  5147,  5165,  5170,  5176,  5191,  5208,  5226,  5244,  5262,
    5283,  5288,  5293,  5303,  5313,  5318,  5329,  5338,  5343,  5370,
    5374,  5378,  5382,  5386,  5393,  5397,  5401,  5405,  5412,  5417,
    5424,  5429,  5433,  5438,  5442,  5450,  5461,  5465,  5477,  5485,
    5493,  5500,  5510,  5539,  5543,  5547,  5551,  5555,  5559,  5563,
    5567,  5571,  5600,  5629,  5658,  5687,  5700,  5713,  5726,  5739,
    5749,  5759,  5771,  5784,  5796,  5800,  5804,  5808,  5812,  5830,
    5851,  5856,  5860,  5864,  5876,  5880,  5892,  5909,  5919,  5923,
    5938,  5943,  5950,  5954,  5967,  5981,  5995,  6009,  6023,  6031,
    6042,  6046,  6050,  6058,  6064,  6070,  6078,  6086,  6093,  6101,
    6116,  6130,  6144,  6156,  6172,  6181,  6190,  6200,  6211,  6215,
    6234,  6241,  6247,  6254,  6262,  6261,  6274,  6279,  6285,  6294,
    6307,  6310,  6314
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

#define YYPACT_NINF -1603

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1603)))

#define YYTABLE_NINF -520

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    8416,    50,   154,  8538, -1603, -1603,  4316,    23,    -7,   -85,
     -58,    18,   152,   166,   189,   206,    82,   232,   288,   107,
     117,   -77,   -77,   -47,   103,   129,    19,   151,   205,    14,
     254,   258,   326,   412,   426,   482,   312,   676,   441,   444,
     658,   456,   586,   778,    -8,   360,   490,   -70,   383,   219,
     219,   396,   291,    62,    78,   529,   555,     7,    47,   566,
     578,   265,   672,   706,   709,  5599,   717,   531,   536,   554,
      11,     5, -1603,   564,   576, -1603, -1603,   737,   744,   575,
   -1603,  3492,  6073,    34,    39, -1603, -1603, -1603,  8276,   601,
   -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603, -1603,    54, -1603,   563,   143,
   -1603,    36, -1603, -1603, -1603, -1603, -1603,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   597,   609,   619,   -77,   -77,   635,   646,   649,
     -77,   -77,   -77,   -77,   653, -1603,   -77, -1603, -1603, -1603,
   -1603, -1603,   -77,   -77,   848,   679,   711,   714,   -77,   -77,
     726,   729, -1603, -1603, -1603, -1603,   659,  8276,  8276,  8276,
    3780,  7765,    26,    16,   447,   677,   725,   252, -1603,   733,
     865,   581,    90,   943,  8276,  5880,  5880, -1603,  8276, -1603,
   -1603, -1603, -1603,  5880, -1603, -1603, -1603, -1603, -1603, -1603,
    6271,    16,  8276,  7573,  8276,  8276,   776,  8276,  7573,  8276,
    8276,   783,  7573,  8276,  8276,  5995,   784,   792, -1603,  7573,
    5599,  5599,  5599,   800,   808,  5599,  5599,  5599,   809,   813,
     817,   833,   834,   845,   849,   854,   831,  2386,  1053,  5995,
      11,   871,   875,   219,   219,   219,  8276,  8276,  -121, -1603,
    -115,   219,   890,   891,   909,  4248,   -74,     0,   928,   932,
     933,  5599,  5599,  5995,   936,     1,   901, -1603,   931,  1137,
    1144, -1603,   950,   976,   977,  5599,  5599,   959,   994,  1017,
     357, -1603,    64,     8,    20,    21,    22,   743,  6193,  8276,
    4529, -1603, -1603,   394, -1603,  1200, -1603,   608,   -99,  1216,
    8276,  8276,  8276,   -19,  8276,  1042, -1603,  1092,  8276,  8276,
    8276, -1603, -1603,  8276,  1037,  1259,  1263, -1603, -1603,  1268,
   -1603,  1272, -1603,   430,  5163,   624,  5880, -1603,  5995,  5995,
    7826,  8018,  1085,  1086,  6271, -1603, -1603, -1603, -1603, -1603,
   -1603,  5995,  1297,  1111,  8276,  8276,  1322,  8276,  8276,  8276,
    8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,
    8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  5880,
    5880,  5880,  5880,  5880,  5880,  5880,  5880,  5995,  5880,  5880,
    8276,  5880,  5880,  5880,  5880,  5880,  8276,  6271,  8276,  5880,
    5880,  5880,  5880,  5880,    16,  6271,    16,  1136,  1136,  1136,
     101, 10710,   122,  7980,   148,  1128,  1343,   -77,  1147, -1603,
    1148,  4070,  8276,  7573, -1603,  8276,  8276,  8276,  8276,  8276,
    8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,  8276,
   -1603, -1603,  8276,  8276, -1603, -1603,   705,   506,    84, -1603,
     650, -1603,   247,  9146, -1603,   345,   272,   284,  1151,  1152,
   10731,  7573,  3271, -1603,   127, 10752, 10773,  8276, 10794,   222,
   10815, 10836,  8276,   365, 10857, 10878,  1352,  8276,  8276,   415,
    1354,  1355,  1356,  8276,  8276,  1358,  1359,  1359,  8276,  7381,
    7381,  7381,  7381,  8276,  8276,  8276,  7573,  7573,  9066,  1163,
    1361,  1162, -1603, -1603,  -147, -1603, -1603,  9172,  9198,   219,
     219,   447,   447,  -125,  8276,  8276,  8276,  4248,  4248,  8276,
    4070,   -95, -1603,  8276,  8276,  8276,  8276,  8276,  1364,  1367,
    1368,  8276,  1370,  8276,  8276,   599, -1603, -1603,  7573,  7573,
    7573,  1372,  1373,  8276,  8276,  8276,  8276,  8276,  1376,   435,
    6391,  6589, -1603,  1325,  8276, -1603,  1326, -1603,  1327, -1603,
    1329,    42,    43,    44,    45,  7573,  1136, -1603, 10899, -1603,
     494,  8276,  6787, -1603,  8276,  8276,   595, -1603, 10920, 10941,
   10962,  1253,  9224, -1603,  1190,  3490, 10983, 11004, 10342, -1603,
   -1603, -1603,  1760, -1603,  1956,  8276,  8276, -1603,  8276,  8276,
    1195,  1203,   663,   128, 11025,   135, 10365,  8276,  7573,  1398,
    1399, -1603,  8276, 11046, 10388,   146,  7790,  7790,  7790,  7790,
    7790,  7790,  7790,  7790,  7790,  7790,  7790,  9250,  7790,  7790,
    7790,  7790,  7790,  7790,  7790,  9276,  9302,  9328,   661,   674,
     661,  1209,  1210,  1207,   675,   675,  1208,  1212,  1213,  9354,
     675,   675,   675,   463,   675, 11592, -1603,   804,  1214,  1215,
    1221,   699,   700,  1223,  1224,  1226,  1374,  1385,  5995,   448,
    1386,  1391,  5995,   114,  6271,  8276,  1428,  1431,    25,   675,
   -1603,   141,    24,    30,   220, -1603,  5297,   738,  3727,   882,
    1070,  1131,  1131,   622,   622,   622,   622,   375,   375,  1136,
    1136,  1136,  1136,     4, 11067, 10411, -1603,  8276,  8276,  1432,
      55,  7573,  8276,  8276,  1433,  7573,  8276,  1434,  5880,  1437,
   -1603,    16,  1439,  5880,  8276,  6271,  1435,  7573,  7573,  1302,
    1442,  1443, 11088,  1446,  1309,  1448,  1449, 11109,  1312,  1456,
    1463,  8276, 11130,  6329,  1267, -1603, -1603, -1603, 11151, 11172,
    8276,  5995,  1470,  1471, 11193,  1276, 11592,  1273,  1279, 11592,
    1282,  1288, 11592,  1289,  1293, 11592,  1290, 11214, 11235, 11256,
     741,   760,  7573,  1295, -1603, -1603,  2133,  2824,   219,  8276,
    8276, -1603, -1603,  1292,  1296,  4248,  9380,  9406,  9432,  9120,
     851,   219,  2999, 11277,  6527, 11298, 11319, 11340,  8276,  1490,
   -1603,  8276, 11361, -1603, 10434, 10457, -1603,   763,   769,   806,
   -1603, -1603, 10480, 10503,  9458, 11382, 10526,   -99, -1603, -1603,
    7573, -1603,  7573,  3271,  1300,  7573,  1304,   172,  1298,  6725,
    1305,  1307,  1308, -1603,  7573, -1603,  7573, -1603,  7573, -1603,
    7573,   810, -1603, -1603,  3918,  7573,  1136, -1603, 11403, 10549,
    7573, -1603,  1503,  1508,  1510,  1299,  8276,  3206,  8276,  8276,
   -1603, -1603,    -6, -1603, -1603,  3233, -1603,  1314,  5995,  1512,
    1487,  1488,  5995,   448,  1489,  1494,  5995,   448,  6923,   835,
   -1603, -1603, 10572,   199,  1347, -1603, -1603, -1603, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603, -1603, -1603,  8276, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603,  8276,  8276,  8276, -1603,  7573,
   -1603, -1603, -1603, -1603,  5880, -1603, -1603,  5995,  5880,  5880,
    6271, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603,  8276,
    5880, -1603,  5880, -1603,  8276, -1603, -1603, -1603, -1603,   -77,
     -77,  1530, -1603,  8276,  1535,   -77,   -77,  1538,    28,  8276,
    1539,  1543,   838, -1603,  1544,  1351,    11,  1548, -1603,  7573,
    7573,  7573,  7573, -1603,   675,  8276, -1603,  1362,  1369,  1349,
   -1603,  1554, -1603, -1603, -1603, -1603, -1603,   211,   253, 11424,
   10595, -1603, -1603,  1379,  5880,   487, 11445, 10618, -1603,   495,
    9484, -1603, -1603, -1603,    63, -1603, -1603,  7790,   675,   219,
    3271, -1603,   684,  5995,  5995,  1560,  5995,   957,  5995,  5995,
    1562,  1486,  5995,  5995,   902,  1568,  1570,  7573,  1571,  1572,
    2161, -1603, -1603,  1574, -1603,  1575,   245,  8276,   245,  8276,
     245,  8276,   245,  8276,  1576,  1577,  1579,  1580,  1582,   840,
    1584,  4102, -1603, -1603,   -42,  9510,  9536, -1603, -1603,  7121,
    -144,   219,   219,   219,  1586,  8084,  1387,  1585,  1395,    27,
      31,    46,    53,   -22, -1603,    -2, -1603,   851,  1588,  1590,
    1591,  1592,  1597, 11592, -1603,  1156,  1400,  1595,  1599,  1601,
    1524,  1602,  1606,  1608,  8276,   -99,   -94,   844,   896, -1603,
     903, -1603, -1603,  8276, -1603,  8276,  8276,  8276,   906,   907,
     915,   923, -1603,  8276,   935,   -99,   -99,   941,  5995,  5995,
    5995,  1611,  9562, -1603,  4486,   173,  1612,  1613, -1603,  5995,
    1411, -1603,   -77,   -77,  1614,  8276,  1615,   -77,   -77,  1616,
    8276,  1618, -1603,   675,  1619, -1603,  1622, -1603,  1621,  7790,
    7790,  7790,  7790,   707,  1414,  1429,  1430,  1438,  1423,   732,
     742, 11466,  1441,   675,  7790,  1133,  5880, -1603,  1474, -1603,
    1133,  5880, -1603,   550,  1444,  1624,  1495, -1603, -1603, -1603,
      11,  8276, -1603,   944, -1603,   954,   961,   983,   984,   245,
   11592,  1445,  8276,  8276,  5995,  1427, -1603, -1603, -1603, -1603,
    1465, -1603,  1628,    87, -1603, -1603,  1629,  8276,  5136,  1451,
    1440,  1630,  1631,    65,  1464,  1467,  1551,  1551,  5995,  1640,
    1484,  1491,  1642,  1643,  5995,  1518,  1646,  1665, -1603,  1687,
    5995,   991,  5995,  5995,  1690,  1719, -1603,  5995,  5995, 11592,
    5995, 11592,  5995, 11592,  5995, 11592,  5995,  5995,  5995,  1522,
    1523,  1688,   912, -1603,  8276,  8276,  8276,  1529,  1532,   -62,
     -56,   -11,  1540, -1603,  1594,  5995, -1603,  8276, -1603,  1724,
   -1603,  1733, -1603,  1734, -1603,  1741, -1603, -1603,  4248,    -9,
    5797, -1603,  1542,  1545,  6985, -1603,  7573, -1603, -1603, -1603,
    1546,  8276, -1603, -1603, 10641,  1692,   675,  1553,  1552,  9588,
    9614,  9640,  9666, -1603, -1603, -1603, -1603, 11592, -1603,   675,
    1749,  1750,  1617, -1603,  8276,  8276,  8276, -1603,  1751,   948,
    1555,  1753,  1133,  5880, -1603,  1739, -1603,  1133,  5880, -1603,
    1984, -1603,   245, -1603,   289, -1603, -1603, -1603, -1603, -1603,
   -1603,  5880, -1603, -1603, -1603,  6271,  1757, -1603, -1603,    17,
   -1603, -1603, -1603, -1603, -1603, -1603,  1756,   661,   661, -1603,
    1758,   661,   661,  6271,  8276,  1759,  1763,    25, -1603,  1764,
   10664,    11, -1603,  1765,  1782,  1783,  1785,  5995,  8276,  9692,
    9718,   995, -1603,  8276,  1789, -1603, -1603,  5880, -1603,  9744,
    4734, 11592, -1603,  1787,  1788, -1603, -1603, -1603,  8276,  8276,
     219,  1790,  1791,  1792, -1603,  8276,  8276, -1603, -1603,  1793,
    8276, -1603, -1603,  1761,  1794,  1563,  1796,  1659,  8276, -1603,
    1800,  1801,  1802,  1806,  1807,  1814,  1197,  1815,  7573,  7573,
    8276, -1603,  7381,  7277, 11487,  4275,   447,   447,   219,  1816,
     219,  1817,   219,  1818,  8276, -1603,   280,  1620, 11508, -1603,
   -1603, -1603, -1603,  7305,   140, -1603,  1820,  3972,  1821,  5995,
     219,  3972,  1822,  1002,  8276,  2443,  1825,   -99, -1603, -1603,
   -1603,  8276,  8276,  8276,  8276, -1603, -1603, -1603,  5995,  4681,
     468, 11529, -1603, -1603,  5203,  5995, -1603,  1826,   661,   661,
   -1603,  1827,   661,   661, -1603,  5995, -1603,  1634,   675,  4938,
    5401,  6271, -1603,  1829,  1830, -1603,  1842,  1845,  1846,  2462,
   -1603,  1853,  1847, -1603,  1658, -1603, -1603, -1603, -1603, -1603,
    1856,   517, 11592,  8276,  8276,  5995,  1660,  1005, 11592, -1603,
    1858,  8276, -1603, -1603,  1662,  1663,  7338,  7511,   771, -1603,
   -1603, -1603,  7722,  8043, -1603,  8171,  1860, -1603,  5995, -1603,
    1797,  1864, 11592, -1603, -1603, -1603, -1603, -1603, -1603,  1666,
   -1603, -1603,  1008,  1009,  9093,  2492,  1867,  1668, -1603,  8276,
   -1603,  1671,  1678,   223, -1603,  1681,   226, -1603,  1684,   293,
   -1603,  1685, 10687,  1886,  5995,  1887,  1694,  8276, -1603,  7183,
     302, -1603,  1016,   327,   341, -1603,  1889,  8199, -1603, -1603,
    9770,  9796,  9822,  9848,  1766,  8276, -1603,  8276, -1603, -1603,
    7573,  2616,  1895,  1686, -1603,  1896,  1897, -1603,  1898,  1899,
    1901, -1603, -1603,  4529, -1603, -1603,  5880, 11592, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603, -1603,    11, -1603,  1767, -1603,
   -1603,  8276,  9874,  9900, -1603,  5995,  8276,  1903, -1603,  9926,
   -1603, -1603,  5995,  5995,  1905,  1906,  1907,  1908,  1909,  1911,
    1021,  1712, -1603,  5995,   485,   534,  7573, -1603, -1603,   447,
    4876, -1603, -1603,  4248,   851,  4248,   851,  4248,   851,  1928,
   -1603,  1025,  5995, -1603,  8534,   219,  1930,  7573,   219, -1603,
   -1603,  8276,  8276,  8276,  8276,  8276,  8562,  8590,  1031, -1603,
   -1603,  1932, -1603, -1603, -1603, -1603, -1603,  1035,  2195,  1937,
    1036,  1939, -1603,  1740, 11592,  8276,  8276,  1039, 11592, -1603,
    8276,  1044,  1059, -1603, -1603, -1603, -1603, -1603, -1603, -1603,
   -1603,  1742,  8276,  1065,  1743,   219,  5995,  1941,  1744,   219,
    1945,  1072,  1745,  8276, -1603,  8618,   344,   665,  8646,   404,
     934,  8674,   484,   997, -1603,  5995,  1947,  1854,  5445,  1748,
     501, -1603,  1077,   514,  9952,  9978, 10004, 10030,  2686, -1603,
   -1603,  1951, -1603,  8276, -1603,  6271,    16, -1603, -1603,  8276,
   11550, 10056,    35, 10082, -1603, -1603, -1603, -1603,  8276,  8702,
    1952,   219,    77, -1603, -1603,   219,    83, -1603,  1953, -1603,
    8730,  1955,  8276,  1957,  1958,  8276,  1960,  1964,  8276,  1965,
    1771, -1603,  8276, -1603,   851, -1603,  7573,  1966,  7183,  8276,
    8276,  8276,  8276, -1603, -1603,  3198, -1603,  1774,  1078, -1603,
    8276, -1603,  5995,  8276,  1081,  1082, 10108, -1603, -1603,   542,
   -1603,   544, -1603, -1603, -1603, -1603,  1777,  8758, -1603, -1603,
    1781,  8786, -1603, -1603,  1786,  8814, -1603,  1982,  2784,  1043,
    5643,  1091, -1603,   551,  1094, 10134, 10160, 10186, 10212,  6271,
    1799,  1983,  1795, 11571,  1095,  8842, -1603, -1603,  8276,   219,
     219,   851,  1987,   851,  1988,   851,  1990, -1603, -1603, -1603,
   -1603,   851,  1991,  7573,  1994,  8276,  8276,  8276,  8276, -1603,
   -1603, -1603,  5880, -1603,  1798,  1996,  8870,   562,   583,  1340,
   -1603,  1804,  1363, -1603,  1805,  1404, -1603,  1811,  1436, -1603,
    1099, -1603, 10238, 10264, 10290, 10316,  1106, -1603,  1819,  5995,
   -1603,  1997,  8276,  8276,  1999,   851,  2001,   851,  2002,   851,
   -1603,  2007,  8276,  8276,  8276,  8276,  5880,  2018,  5880,  1120,
   -1603,  8898,  8926, -1603,  1689, -1603,  1755, -1603,  1894, -1603,
    8954,  8982,  9010,  9038, -1603, -1603,  1125, -1603,  2020,  2022,
    2023,  2024,  2025,  2026, -1603, -1603, -1603, -1603,  5880,  2027,
   -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,   266,   267,     0,     0,     0,
     261,     0,     0,     0,     0,   363,   364,   365,     0,     0,
       5,     7,     6,     8,     9,    10,    20,    11,    12,    13,
      14,    19,    18,    15,    16,    17,     0,    21,   551,     0,
     412,   550,   520,   413,   415,   416,   414,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,   541,   524,   420,
     421,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   417,   418,   419,   523,     0,     0,     0,     0,
      66,    67,     0,     0,   206,     0,     0,     0,   370,     0,
     512,   551,   427,     0,     0,     0,     0,   246,     0,   248,
     249,   244,   245,     0,   250,   251,   123,   135,    66,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   550,     0,   206,   551,     0,
       0,   360,     0,     0,     0,     0,     0,     0,     0,     0,
     550,   467,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   460,   466,     0,   461,   551,   427,     0,
       0,     0,     0,   550,     0,     0,   506,     0,     0,     0,
       0,   242,   243,     0,   550,     0,     0,   259,   260,     0,
     206,     0,   206,   550,     0,   551,     0,   366,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,   372,   374,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,   204,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   235,     0,     0,   435,   183,     0,   550,     0,   512,
     551,   513,     0,     0,   546,     0,   121,   121,     0,     0,
       0,     0,   500,   501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,   206,     0,   451,   450,     0,     0,     0,
       0,   206,   206,     0,     0,     0,     0,     0,     0,     0,
     277,     0,   206,     0,     0,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,     0,   224,   361,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,     0,   473,     0,     0,   474,     0,   475,     0,   476,
       0,     0,     0,     0,     0,     0,   372,   468,     0,   462,
       0,     0,     0,   338,    66,    67,     0,   241,     0,     0,
       0,     0,     0,   206,     0,     0,     0,     0,     0,   263,
     262,   229,     0,   230,     0,     0,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,   440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   423,   544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,     0,   371,
      59,    60,     0,     0,    59,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,   207,     0,     0,     0,   388,
     387,   385,   386,   381,   383,   382,   384,   376,   375,   377,
     378,   379,   380,     0,     0,     0,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   357,   358,   359,     0,     0,
       0,     0,   326,     0,     0,     0,   151,   152,     0,   154,
     155,     0,   157,   158,     0,   160,   161,     0,     0,     0,
       0,     0,     0,     0,   171,   206,     0,     0,     0,     0,
       0,   453,   452,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
     341,     0,     0,   225,     0,     0,   221,     0,     0,     0,
     356,   355,     0,     0,     0,     0,     0,   440,    68,    69,
       0,   491,     0,     0,     0,     0,     0,   427,     0,     0,
       0,     0,     0,   477,     0,   478,     0,   479,     0,   480,
       0,     0,   371,   463,   470,     0,   377,   469,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,     0,   231,   233,     0,   552,     0,     0,     0,
      59,    60,     0,     0,    59,    60,     0,     0,     0,     0,
      90,    74,     0,   429,   428,   442,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   411,   399,     0,   401,   402,
     403,   404,   405,   406,   407,     0,     0,     0,   533,     0,
     538,   529,   530,   531,     0,   543,   542,     0,     0,     0,
       0,   534,   535,   536,   448,   540,   140,   145,   113,     0,
       0,   525,     0,   527,     0,   425,   432,   433,   521,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,   434,     0,
       0,     0,     0,   548,     0,     0,    44,     0,     0,     0,
      57,     0,    35,    36,    37,    38,    39,   431,   430,     0,
       0,   518,    24,    22,     0,     0,     0,     0,    25,     0,
       0,   236,   547,    70,   124,    71,   136,     0,     0,     0,
     502,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     324,   329,   327,     0,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   234,     0,     0,     0,   196,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   306,     0,   268,     0,     0,     0,
       0,     0,     0,   331,   340,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   429,   428,     0,     0,   495,
       0,   494,   493,     0,   472,     0,     0,     0,     0,     0,
       0,     0,   464,     0,     0,   431,   430,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,   228,     0,
       0,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   549,     0,     0,   437,     0,   436,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    88,
       0,     0,    76,     0,     0,     0,     0,    80,   103,   105,
       0,     0,   510,     0,   111,     0,     0,     0,     0,     0,
     389,     0,     0,     0,     0,     0,    30,   439,   438,   516,
     514,    23,     0,     0,   517,   515,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,     0,     0,     0,     0,     0,   335,     0,     0,   153,
       0,   156,     0,   159,     0,   162,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   312,     0,     0,   311,     0,   318,     0,
     320,     0,   314,     0,   316,     0,   278,   307,     0,     0,
       0,   219,     0,     0,     0,   342,     0,   223,   222,   362,
       0,     0,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,   484,   471,   465,     0,
       0,     0,     0,   507,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,    85,     0,    89,     0,     0,    77,
       0,    81,     0,   238,   441,   237,   400,   408,   409,   410,
     539,     0,   445,   446,   447,     0,     0,   424,   141,     0,
     545,   146,   444,   526,   528,   426,     0,     0,     0,    86,
       0,     0,     0,    59,     0,     0,     0,     0,    78,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,     0,     0,    26,    27,     0,    28,     0,
       0,   125,   132,     0,     0,    72,    73,   167,     0,     0,
       0,     0,     0,     0,   170,     0,     0,   186,   187,     0,
       0,   172,   193,     0,     0,     0,     0,   163,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,     0,   206,   206,     0,   288,
       0,   290,     0,   292,     0,   313,   460,     0,     0,   319,
     321,   315,   317,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   498,   497,
     496,     0,     0,     0,     0,   499,   175,   176,     0,     0,
       0,     0,   114,   118,     0,     0,   368,     0,     0,     0,
      87,     0,     0,     0,    79,     0,   443,     0,     0,     0,
       0,     0,    97,     0,     0,    91,     0,     0,     0,     0,
     108,     0,     0,   109,     0,   511,   208,   209,   210,   211,
       0,     0,    40,     0,     0,     0,     0,     0,    42,   519,
       0,     0,   126,   133,     0,     0,     0,     0,   166,   173,
     174,   178,     0,     0,   188,     0,     0,   336,     0,   181,
       0,     0,   325,   192,   168,   180,   191,   195,   179,     0,
     189,   194,     0,     0,     0,     0,     0,     0,   457,     0,
     456,     0,     0,     0,   279,     0,     0,   280,     0,     0,
     281,     0,     0,     0,     0,     0,     0,     0,   218,     0,
       0,   217,     0,     0,     0,   212,     0,     0,   339,    33,
       0,     0,     0,     0,     0,     0,   505,     0,   256,   255,
       0,     0,     0,     0,    98,     0,     0,    92,     0,     0,
       0,   532,   537,     0,   142,   144,     0,   147,   148,   149,
      99,   101,    93,    95,   104,   106,     0,   112,     0,    82,
      45,     0,     0,     0,   459,     0,     0,     0,    29,     0,
     140,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,   332,   332,     0,   119,   120,   206,
       0,   199,   200,     0,     0,     0,     0,     0,     0,     0,
     308,     0,     0,   206,     0,     0,     0,     0,     0,   203,
     202,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,     0,   100,   102,    94,    96,    83,     0,   500,   501,
       0,     0,   509,     0,    41,     0,     0,     0,    43,    58,
       0,     0,     0,   130,   128,   350,   352,   351,   353,   354,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,     0,   273,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,   504,
     257,     0,   369,     0,   143,     0,     0,   150,   110,     0,
       0,     0,     0,     0,   127,   134,   140,   140,     0,     0,
       0,     0,     0,   333,   343,     0,     0,   344,     0,   197,
       0,   294,     0,     0,   296,     0,     0,   298,     0,     0,
       0,   309,     0,   269,     0,   206,     0,     0,     0,     0,
       0,     0,     0,   177,   117,     0,   137,     0,     0,    49,
       0,    55,     0,     0,     0,     0,     0,   164,   190,     0,
     347,     0,   348,   349,   454,   282,     0,     0,   289,   283,
       0,     0,   291,   284,     0,     0,   293,     0,     0,     0,
     275,     0,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   129,     0,     0,
       0,     0,   300,     0,   302,     0,   304,   310,   322,   274,
     270,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,    46,     0,    53,     0,     0,     0,     0,     0,     0,
     285,     0,     0,   286,     0,     0,   287,     0,     0,   220,
       0,   214,     0,     0,     0,     0,     0,    47,     0,     0,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,   295,     0,   297,     0,   299,     0,   215,
       0,     0,     0,     0,    48,    50,     0,    51,     0,     0,
       0,     0,     0,     0,   485,   486,   487,   488,     0,     0,
      56,   345,   346,   301,   303,   305,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1603, -1603, -1603, -1603,   853, -1603, -1603, -1603, -1603,   275,
   -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603,
   -1603, -1603,  -398,   -27,  1581,  3093, -1603,  1600, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603, -1602, -1603,   406, -1603, -1603,
   -1603, -1603, -1603, -1603,   841,  2046,    32,  -505,  -246, -1603,
   -1603, -1603, -1603, -1603, -1603, -1603,  2049, -1603, -1603, -1603,
   -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603, -1603,
   -1045,  -982, -1603, -1603,  1578, -1603,   408, -1603, -1603, -1603,
   -1603,  1762, -1603, -1603,  1320, -1603, -1392,  2391,   568,  3052,
    2289,  -240,   710, -1603,   215,    49, -1603,  -377,    -3,   120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,   984,    91,    92,   703,  1511,  1517,
     972,  1181,  1703,  1916,   973,  1862,  1956,   974,  1918,   975,
     976,  1185,   351,   444,   186,   821,    93,   721,   456,  1640,
    1777,  1776,  1641,   457,  1697,  1149,  1338,  1150,  1341,   755,
     758,   761,   764,  1541,  1391,   685,   301,   420,   421,    96,
      97,    98,    99,   100,   101,   102,   302,  1067,  1804,  1881,
     790,  1565,  1568,  1571,  1836,  1840,  1844,  1901,  1904,  1907,
    1063,  1064,  1225,  1023,   752,   799,  1727,   104,   105,   106,
     107,   303,   188,   926,   506,   259,  1371,   304,   305,   306,
     570,   315,   957,  1173,   454,   449,   927,   455,   335,   308
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,  1116,   638,   191,   640,   532,   783,   784,   966,   317,
     501,   275,   668,   552,   672,   313,   675,   653,   221,   520,
     324,  1490,  1269,   216,   197,   555,   557,   559,   216,   955,
     414,   535,  1163,  1258,   221,    95,   193,  1260,  1711,   329,
     353,  1821,   509,   510,   331,   509,   510,   833,   835,   837,
     839,   280,  1262,   281,   278,   190,     4,  1582,   778,  1264,
     337,   982,   307,  1248,   509,   510,   267,   278,   509,   510,
    1198,  1387,   250,   246,   509,   510,   247,   194,   278,  1054,
     785,  1267,   352,  1830,   592,   511,   594,   251,   252,  1832,
    1055,   512,  1054,  1376,   509,   510,   349,   350,  1056,  1057,
    1058,   349,   350,  1055,  1059,  1060,  1061,  1062,   666,  1285,
     791,  1056,  1057,  1058,   195,   509,   510,  1059,  1060,  1061,
    1062,   942,   208,   109,   209,   282,   192,   509,   510,   670,
     325,   328,   522,   509,   510,   870,   967,   968,   969,   970,
     268,   196,   874,  1428,   269,  1429,  1650,   509,   510,  1430,
     344,  1431,   212,   553,     5,   674,   270,  1259,   199,   213,
     276,  1261,   271,  1244,   272,   556,   558,   560,   415,   416,
    1164,  1165,   200,  1491,  1824,  1825,  1263,   279,   509,   510,
     278,  1306,    89,  1265,   581,  1266,    89,   509,   510,   185,
     316,    89,   450,   450,  1432,   201,  1433,  1117,  1445,   523,
     450,   326,   533,  1268,   318,   872,   524,   876,   278,   185,
     307,   971,   202,   277,   554,   307,   419,   314,   217,   307,
     222,   189,   307,   217,   198,   218,   307,   307,   307,   307,
     960,   956,   307,   307,   307,   354,   961,   355,   204,   356,
     330,  1822,   983,  1707,   185,   332,   307,   278,   834,   836,
     838,   840,   942,   338,   509,   510,   776,   777,   424,   458,
     339,  1723,  1199,   550,  1200,   551,   509,   510,   307,   307,
     307,   943,   509,   510,   983,   949,   792,   667,   346,   347,
     348,   203,   307,   307,   710,   349,   350,  1267,   571,   711,
     345,   346,   347,   348,   205,   307,  -513,   307,   671,   346,
     347,   348,   214,   417,   871,   346,   347,   348,   206,   349,
     350,   875,   346,   347,   348,   451,   451,   948,   207,   345,
     346,   347,   348,   451,   345,   346,   347,   348,   215,   509,
     510,   459,   728,   450,   729,   307,   307,   857,   349,   350,
     212,   349,   350,   349,   350,  1577,   285,   959,   307,   286,
     219,   865,  -518,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   349,   350,   262,
     316,   439,   263,  1307,  1092,   264,   450,   450,   450,   450,
     450,   450,   450,   450,   307,   450,   450,   676,   450,   450,
     450,   450,   450,   609,   349,   350,   450,   450,   450,   450,
     450,   278,   571,   278,   220,  -516,   349,   350,   254,   255,
     448,   452,   509,   510,   225,   509,   510,  -517,   256,   224,
     307,   345,   346,   347,   348,   257,   962,   728,  1663,   734,
    1864,  1665,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   656,   714,   349,   350,
     439,   418,   715,   223,   664,   942,   451,   224,   307,  -515,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   572,   437,   438,   719,  1125,  1597,   720,   439,  1130,
     254,   255,   509,   510,   349,   350,   722,  1573,   228,   720,
     256,   509,   510,   307,   307,  -519,   226,   265,  1667,   451,
     451,   451,   451,   451,   451,   451,   451,  1675,   451,   451,
     227,   451,   451,   451,   451,   451,   509,   510,   229,   451,
     451,   451,   451,   451,   663,   233,   665,  1939,   234,  1041,
     509,   510,  1677,   509,   510,   307,   307,   307,   757,   760,
     763,   766,   238,   419,   419,   717,  1678,   307,   307,  1792,
     718,   600,    48,    49,    50,    51,   546,  1353,   547,   248,
     548,    56,   307,   184,    59,   185,   436,   437,   438,   307,
     728,   249,   738,   439,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   572,   437,   438,   885,   253,
    1724,  1725,   439,   509,   510,   639,  1726,   641,   642,   643,
     644,   645,   261,   647,   648,   307,   650,   651,   652,  1795,
     654,     7,     8,   273,   658,   659,   660,   661,   662,  1737,
     728,  1740,   744,  1743,   345,   346,   347,   348,  1228,   595,
    1230,   596,  1232,   548,  1234,   818,   274,   819,   185,  1728,
    1729,   820,   944,   349,   350,  1726,   950,   283,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   284,   924,   239,   307,   439,   240,   718,   307,
     241,   827,   242,   509,   510,  1598,   287,   681,    24,    25,
     682,    27,    28,   683,    30,   684,    32,  1193,    33,  1798,
     509,   510,   728,    38,    39,  1196,    41,    42,    43,   728,
     728,   843,    46,   509,   510,   707,  1806,   708,   307,   709,
     288,   706,   307,   289,   185,   450,  1172,  1630,   278,  1808,
     450,   309,  1631,   951,   307,   307,   345,   346,   347,   348,
     310,   509,   510,   509,   510,   311,    67,    68,    69,   235,
     509,   510,   236,   321,   237,   349,   350,  1869,   307,  1870,
     322,   509,   510,   312,   230,  1267,  1883,   231,  1267,  1849,
     232,  1267,   340,   319,   341,  1354,  1054,  1922,  1204,   307,
    1205,   342,   509,   510,   998,   320,   323,  1055,  1347,  1348,
     442,  1367,   443,  1351,  1352,  1056,  1057,  1058,  1923,   342,
     885,  1059,  1060,  1061,  1062,   818,   382,   819,   480,   481,
     482,   850,   336,   485,   486,   487,   806,   574,   383,   575,
     928,   434,   435,   436,   437,   438,   342,   307,   384,   307,
     439,   561,   307,   598,   562,   599,  1899,   563,  1902,   564,
    1905,   307,   342,   307,   387,   307,  1908,   307,   451,   528,
     529,   994,   307,   451,  1169,   388,  1126,   307,   389,   712,
    1131,   713,   394,   541,   542,   398,  1135,  1137,   342,   243,
     406,   818,   244,   819,   245,   307,   718,  1267,   868,   307,
     869,   441,  1793,   307,   818,   818,   819,   819,   399,   909,
    1944,   450,  1946,   422,  1948,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   818,
     818,   819,   819,   439,   932,   934,   307,   818,  1218,   819,
     400,   450,   728,   401,   307,   450,   450,  1267,  1421,  1422,
    1267,  1561,  1562,  1267,  1485,   404,  1267,   450,   405,   450,
    1359,   423,   818,   992,   819,  1478,  1479,  1336,   996,   440,
    1482,  1483,   818,   728,   819,   964,   728,  1339,  1037,   445,
    1187,  1188,  1054,   278,  1473,  1474,   307,   307,   307,   307,
     509,   510,  1267,  1055,  1267,   728,  1267,  1038,   728,  1148,
    1079,  1056,  1057,  1058,   728,   467,  1080,  1059,  1060,  1061,
    1062,   450,   472,   477,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   478,   483,
     307,   307,   439,   307,   451,   307,   307,   484,   488,   307,
     307,   728,   489,  1081,   307,   728,   490,  1102,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   491,   492,   451,  1054,   439,   496,   451,   451,
     728,  1210,  1133,  1211,   493,   728,  1055,  1241,   494,   728,
     451,  1286,   451,   495,  1056,  1057,  1058,   499,  1135,  1137,
    1059,  1060,  1061,  1062,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   316,   502,  1187,  1188,
     439,   503,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   514,   515,  1054,  1138,
     439,   728,   534,  1287,   451,   307,   307,   307,   728,  1055,
    1288,   728,   728,  1293,  1294,   516,   307,  1056,  1057,  1058,
     728,  1505,  1295,  1059,  1060,  1061,  1062,   525,   728,  1144,
    1296,   526,   527,  1146,  1147,   531,  1355,   447,   112,   342,
     728,  1796,  1298,   536,  1054,  1152,   728,  1153,  1299,  1361,
     537,  1362,   450,   450,  1732,  1055,   538,   450,   450,   728,
     543,  1363,  1275,  1056,  1057,  1058,   728,   278,  1364,  1059,
    1060,  1061,  1062,   139,   140,   141,   142,   143,   144,   145,
     146,   307,   539,   540,   150,   151,   152,   153,   728,   728,
    1365,  1366,   155,   156,   157,   544,   728,   158,  1405,  1192,
    1515,  1549,  1516,  1550,  1799,   307,   573,   728,   163,  1586,
    1636,   307,  1637,   728,   728,  1654,  1655,   307,   545,   307,
     307,  1515,   577,  1676,   307,   307,  1515,   307,  1721,   307,
    1745,   307,  1746,   307,   307,   307,   728,   584,  1761,  1700,
    1763,   718,  1764,  1767,  1515,   185,  1772,  1382,   583,  1336,
    1879,  1774,   307,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1339,   589,  1775,   307,   439,   590,
    1515,   307,  1780,   307,   591,   451,   451,   728,   593,  1788,
     451,   451,   728,  1636,  1807,  1861,  1336,  1336,  1866,  1867,
     316,   607,   608,   166,   167,   168,   728,  1486,  1882,   728,
    1515,  1884,  1894,   611,   728,   175,  1931,   176,    89,   450,
     450,  1936,   612,  1937,   450,   450,   430,   431,   432,   433,
     434,   435,   436,   437,   438,  1515,   615,  1958,   450,   439,
    1968,   677,  1969,   818,   439,   819,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     678,   447,   112,   184,   439,   680,   724,   725,   278,   741,
     745,   746,   747,   773,   307,   750,   751,   774,   775,   258,
     260,   798,   266,   800,   450,   801,   803,   307,   810,   811,
     817,   828,   830,   831,  1488,   832,  1701,   139,   140,   141,
     142,   143,   144,   145,   146,   855,   858,   866,   150,   151,
     152,   153,  1498,   867,   880,   881,   155,   156,   157,   912,
     913,   158,   914,   917,   939,   307,   307,   918,   919,   929,
     930,   931,   163,   936,   937,   940,   945,  1748,   938,  1523,
    1486,   946,   451,   451,   953,   954,   981,   451,   451,   988,
     991,  1054,   999,   993,   307,   995,   307,  1002,   307,  1003,
    1004,   451,  1055,  1006,  1007,  1008,  1009,  1011,   419,   419,
    1056,  1057,  1058,  1012,  1054,   307,  1059,  1060,  1061,  1062,
    1013,  1556,   307,  1017,  1022,  1055,  1026,  1024,  1027,  1028,
    1349,   316,   307,  1056,  1057,  1058,   307,  1029,  1030,  1059,
    1060,  1061,  1062,  1032,  1031,  1033,  1074,   451,  1040,  1047,
    1089,  1358,  1111,  1048,  1093,  1054,  1091,   166,   167,   168,
    1108,  1095,   307,  1096,  1097,  1109,  1055,  1110,  1121,   175,
    1119,   176,    89,  1602,  1056,  1057,  1058,  1122,  1123,  1127,
    1059,  1060,  1061,  1062,  1128,   307,  1157,  1054,  1615,  1618,
    1619,  1159,   349,   350,  1162,  1167,  1487,  1924,  1055,  1168,
    1136,  1170,  1171,  -514,  1174,  1184,  1056,  1057,  1058,  1850,
    1186,  1182,  1059,  1060,  1061,  1062,  1191,  1208,  1183,  1214,
    1926,   307,  1215,   504,   505,  1219,   307,  1220,  1222,  1223,
    1226,   513,  1227,  1236,  1237,   521,  1238,  1239,  1242,  1240,
    1252,  1256,  1520,  1255,  1257,  1270,  1271,   307,  1272,  1273,
    1435,  1277,   210,   211,  1274,  1278,  1276,  1279,  1280,  1281,
     307,  1928,  1282,   450,  1283,  1303,  1308,  1309,  1311,  1331,
    1314,  1316,  1319,   278,  1321,  1323,  1324,  1325,  1335,  1332,
    1333,  1357,   307,  1373,  1375,  1378,  1385,  1386,  1334,   307,
     307,  1343,  1384,  1930,  1368,  1390,  1394,  1356,  1397,  1398,
     307,  1383,  1401,   307,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,  1374,   307,
    1388,  1402,   439,  1389,   307,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   343,
    1395,   419,  1403,   439,  1408,  1420,  1457,  1396,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   307,  1400,  1409,   385,   386,  1418,  1419,
    1439,   390,   391,   392,   393,  1426,   451,   395,  1427,  1440,
    1441,  1434,   307,   396,   397,  1480,   316,  1442,  1449,   402,
     403,  1450,  1454,  1459,  1460,  1466,  1467,  1472,  1468,  1476,
    1475,  1489,  1492,   278,  1495,  1500,  1536,  1501,   187,  1538,
    1503,  1506,     7,     8,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,  1507,  1508,
    1054,  1509,   439,  1519,  1524,  1525,  1529,  1530,  1531,  1534,
    1537,  1055,  1539,   307,  1540,   307,  1543,  1544,  1545,  1056,
    1057,  1058,  1546,  1547,  1816,  1059,  1060,  1061,  1062,   307,
    1548,  1551,  1564,  1567,  1570,  1574,  1578,  1581,  1585,   781,
     782,  1589,  1604,  1607,  1611,  1620,  1621,   505,   681,    24,
      25,   682,    27,    28,   683,    30,   684,    32,  1622,    33,
     334,  1623,  1624,  1627,    38,    39,  1054,    41,    42,    43,
    1626,  1628,  1629,    46,  1638,  1649,  1635,  1055,  1642,  1643,
    1652,   549,  1653,  1658,  1659,  1056,  1057,  1058,  1661,  1651,
     307,  1059,  1060,  1061,  1062,  1662,  1817,  1664,   576,   450,
    1666,  1668,  1670,  1691,  1672,  1679,  1961,    67,    68,    69,
    1673,  1690,  1692,  1693,  1694,  1695,  1685,  1696,  1889,  1709,
    1702,  1715,  1716,  1717,  1718,  1719,   307,  1720,  1722,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   450,  1744,   450,  1751,   439,  1762,   407,
     408,   409,   411,   413,  1766,  1768,  1769,  1784,  1778,  1781,
    1785,  1787,  1789,  1801,  1805,  1802,   446,  1814,  1828,  1833,
     453,  1835,  1962,  1838,  1839,   450,  1842,   863,     7,     8,
    1843,  1846,  1852,  1860,   460,   462,   465,   466,  1847,   468,
     462,   470,   471,  1871,   462,   474,   475,  1873,  1877,  1891,
    1484,   462,  1875,  1900,  1903,  1054,  1906,  1909,   679,  1890,
    1911,  1892,  1920,  1940,  1919,  1943,  1055,  1945,  1947,   498,
    1925,  1927,   451,  1949,  1056,  1057,  1058,  1929,   507,   508,
    1059,  1060,  1061,  1062,  1955,  1938,  1970,   508,  1971,  1972,
    1973,  1974,  1975,  1977,   681,    24,    25,   682,    27,    28,
     683,    30,   684,    32,  1818,    33,  1377,  1712,  1392,    94,
      38,    39,   103,    41,    42,    43,   451,   723,   451,    46,
     566,   568,   462,  1730,     0,   753,     0,  1502,     0,     0,
       0,     0,   578,   579,   580,     0,   582,     0,     0,     0,
     585,   586,   587,     0,     0,   588,     0,     0,   451,     0,
       0,     0,     0,    67,    68,    69,     0,     0,  1044,     0,
       0,  1963,   604,   606,     0,  1050,     0,  1917,     0,     0,
       0,  1065,     0,     0,     0,     0,   613,   614,     0,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,  1954,   649,  1957,     0,     0,     0,     0,   655,     0,
     657,     0,     0,   864,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,  1976,   686,   462,     0,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,  1765,   571,   704,   705,     0,     0,     0,     0,
       0,   681,    24,    25,   682,    27,    28,   683,    30,   684,
      32,     0,    33,   566,     0,     0,     0,    38,    39,   732,
      41,    42,    43,     0,   737,     0,    46,     0,     0,   742,
     743,     0,     0,     0,     0,   748,   749,     0,     0,     0,
     754,   756,   759,   762,   765,   767,   768,   769,   462,   462,
       0,     0,  1224,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,   786,   787,   788,   407,
     408,   789,     0,     0,     0,   793,   794,   795,   796,   797,
       0,     0,     0,   802,     0,   804,   805,     0,     0,     0,
     462,   462,   462,     0,     0,   812,   813,   814,   815,   816,
       0,     0,   823,   823,     0,     0,   829,     0,     0,  1203,
       0,     0,     0,     0,     0,     0,     0,   462,     0,     0,
       0,     0,     0,   844,   846,     0,   848,   849,     0,     0,
    1042,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,   815,   816,   439,
     848,   849,     0,     0,     0,     0,     0,     0,     0,   878,
     462,  1249,  1250,  1251,   882,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   727,   437,   438,   110,
     333,     0,     0,   439,     0,   113,   114,   115,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,   952,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,  1588,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,  1625,   979,
     980,     0,     0,   462,   986,   987,     0,   462,   990,     0,
       0,     0,     0,     0,     0,     0,   997,     0,     0,   846,
    1000,     0,     0,     0,     0,     0,     0,     0,  1657,     0,
       0,     0,   464,  1014,     0,     0,     0,   469,     0,     0,
       0,   473,  1020,     0,     0,     0,     0,     0,   479,     0,
    1155,  1156,     0,     0,     0,     0,  1160,  1161,     0,     0,
       0,     0,     0,     0,   462,     0,     0,     0,     0,     0,
       0,  1045,  1046,     0,     0,   165,     0,  1049,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
    1073,    89,     0,  1075,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,   462,     0,   462,   299,     0,   462,  1444,     0,
     183,     0,   497,     0,     0,     0,   462,     0,   462,     0,
     462,     0,   462,     0,     0,     0,     0,   462,     0,     0,
       0,     0,   462,     0,     0,     0,   476,     0,  1112,     0,
    1114,  1115,  1689,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
     500,   439,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,  1139,
     439,     0,     0,     0,   530,     0,     0,  1140,  1141,  1142,
       0,   462,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,  1151,  1813,     0,     0,     0,  1154,     0,     0,     0,
       0,     0,     0,  1312,  1313,  1158,     0,     0,  1317,  1318,
    1528,  1166,   687,     0,     0,     0,     0,     0,     0,     0,
       0,   462,   462,   462,   462,     0,     0,  1180,     0,   601,
     602,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   610,     0,     0,     0,     0,     0,  1563,     0,
    1566,     0,  1569,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1580,     0,     0,
    1583,  1584,     0,     0,     0,     0,     0,     0,   646,   462,
       0,     0,     0,     0,     0,   770,   771,     0,     0,  1229,
    1878,  1231,     0,  1233,     0,  1235,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,  1254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   807,   808,   809,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,  1284,     0,     0,     0,
       0,     0,     0,     0,   841,  1289,     0,  1290,  1291,  1292,
       0,     0,     0,     0,     0,  1297,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,  1315,     0,     0,
       0,     0,  1320,     0,     0,     0,     0,   879,     0,     0,
       0,     0,   681,    24,    25,   682,    27,    28,   683,    30,
     684,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,     0,     0,    46,     0,     0,
       0,     0,     0,  1360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1369,  1370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1379,
    1381,    67,    68,    69,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,  1736,     0,  1739,     0,  1742,     0,     0,
       0,     0,     0,     0,     0,  1750,     0,     0,  1753,     0,
     985,     0,     0,     0,   989,     0,  1423,  1424,  1425,     0,
       0,     7,     8,     0,     0,     0,     0,  1436,     0,  1438,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1443,  1043,     0,     0,     0,     0,     0,     0,   462,     0,
       0,     0,     0,  1455,     0,  1782,     0,     0,     0,  1786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   941,
       0,  1039,     0,   947,     0,     0,  1469,  1470,  1471,     0,
       0,     0,     0,     0,     0,     0,     0,   681,    24,    25,
     682,    27,    28,   683,    30,   684,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,  1829,    46,     0,     0,  1831,     0,     0,     0,  1087,
       0,  1088,     0,     0,  1090,     0,  1499,     0,     0,     0,
       0,     0,     0,  1098,     0,  1099,     0,  1100,  1853,  1101,
    1512,     0,     0,     0,  1104,  1518,    67,    68,    69,  1107,
       0,     0,  1021,     0,     0,     0,     0,     0,     0,     0,
    1526,  1527,     0,     0,     0,     0,     0,  1532,  1533,     0,
       0,     0,  1535,     0,     0,     0,     0,     0,     0,     0,
    1542,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     462,   462,  1554,     0,  1555,     0,     0,     0,     0,  1897,
    1898,     0,     0,     0,     0,     0,  1572,     0,  1143,     0,
       0,     0,     0,     0,     0,  1859,  1066,     0,     0,   462,
       0,     0,     0,   462,     0,     0,  1587,     0,     7,     8,
       0,     0,     0,  1590,  1591,  1592,  1593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1601,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,  1175,  1176,
    1177,  1178,  1617,     0,     0,     0,     0,     0,     0,  1120,
       0,     0,     0,  1124,     0,   463,     0,  1129,     0,     0,
     463,     0,     0,     0,   463,  1632,  1633,     0,     0,   571,
       0,   463,     0,  1639,   681,    24,    25,   682,    27,    28,
     683,    30,   684,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,  1221,     0,  1145,    46,
       0,   681,    24,    25,   682,    27,    28,   683,    30,   684,
      32,  1660,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,  1674,
       0,   566,     0,    67,    68,    69,     0,     0,     0,     0,
     567,     0,   463,     0,     0,     0,     0,  1686,     0,  1687,
       0,     0,   462,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,  1698,     0,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,  1704,  1206,  1207,   439,  1209,  1708,  1212,
    1213,     0,     0,  1216,  1217,     0,     0,     0,     0,     0,
       0,     0,     0,  1113,     0,     0,     0,     0,   462,     0,
       0,     0,     0,     0,     0,  1735,     0,  1738,     0,  1741,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
    1118,     0,     0,  1754,  1755,  1756,  1757,  1758,     0,     0,
       0,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   727,   437,   438,     0,     0,  1770,  1771,   439,
       0,     0,  1773,     0,     0,   463,     0,     0,     0,     0,
       0,     0,     0,     0,  1779,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1790,   324,   112,   859,  1300,
    1301,  1302,     0,     0,     0,     0,     0,     0,     0,     0,
    1310,     0,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1815,     0,     0,     0,     0,
       0,  1518,   139,   140,   141,   142,   143,   144,   145,   146,
    1826,     0,     0,   150,   151,   152,   153,     0,   463,   463,
       0,   155,   156,   157,  1837,     0,   158,  1841,     0,     0,
    1845,     0,     0,     0,  1848,  1453,     0,   163,   462,     0,
     462,  1855,  1856,  1857,  1858,  1372,     0,     0,     0,     0,
       0,     0,  1863,     0,     0,  1865,     0,     0,     0,     0,
     463,   463,   463,     0,     0,     0,     0,     0,     0,  1393,
       0,     0,   824,   826,     0,  1399,     0,     0,     0,     0,
       0,  1404,     0,  1406,  1407,     0,     0,   463,  1410,  1411,
       0,  1412,     0,  1413,   847,  1414,     0,  1415,  1416,  1417,
    1896,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   462,  1437,  1912,  1913,  1914,
    1915,     0,   166,   167,   168,     0,     0,     0,     0,     0,
     463,  1448,     0,     0,   175,  1452,   176,    89,     0,   851,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,  1941,  1942,     0,     0,   439,     0,
       0,     0,     0,     0,  1950,  1951,  1952,  1953,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1552,  1553,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
       0,   898,   899,   900,   901,   902,   903,   904,     0,     0,
       0,   908,   910,   911,     0,   965,     0,   915,   916,     0,
       0,     0,     0,   921,   922,   923,     0,   925,     0,     0,
       0,     0,     0,     0,   933,   935,     0,     0,  1510,     0,
       0,     0,     0,   463,     0,     0,     0,   463,     0,     0,
       0,  1522,   958,     0,     0,     0,     0,     0,     0,   847,
    1001,     0,     0,   110,   333,     0,     0,     0,     0,   113,
     114,   115,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,   147,   148,
     149,     0,     0,     0,     0,   154,     0,     0,     0,     0,
    1372,     0,     0,     0,     0,     0,   159,   160,   161,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,  1594,
       0,     0,     0,     0,     0,     0,  1603,     0,     0,     0,
       0,     0,   463,     0,   463,     0,  1610,   463,     0,     0,
    1614,     0,     0,     0,     0,     0,   463,     0,   463,  1688,
     463,     0,   463,     0,     0,     0,     0,   463,     0,     0,
       0,     0,   463,     0,     0,     0,  1634,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,  1103,     0,     0,  1372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,   169,     0,  1731,     0,   170,   171,   172,
     173,   174,     0,     0,     0,    89,     0,     0,     0,     0,
       0,   463,     0,     0,     0,  1671,  1752,     0,     0,   177,
     178,     0,     0,     0,   179,   110,   290,     0,     0,   299,
     410,   113,   114,   115,   183,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   292,
       0,   463,   463,   463,   463,     0,     0,     0,     0,     0,
     147,   148,   149,     0,     0,     0,  1372,   154,     0,     0,
       0,     0,     0,  1713,  1714,     0,     0,     0,   159,   160,
     161,     0,     0,     0,  1372,     0,   162,     0,     0,     0,
     293,     0,     0,   294,     0,     0,   295,  1179,   296,     0,
       0,     0,     0,  1747,     0,     0,     0,     0,     0,   463,
     297,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,     7,     8,     0,     0,    56,     0,     0,    59,
    1201,  1202,     0,     0,     0,  1851,     0,  1854,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     7,     8,   439,  1783,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,     0,   169,  1800,     0,     0,   170,
     171,   172,   173,   174,     0,     0,     0,    89,   681,    24,
      25,   682,    27,    28,   683,    30,   684,    32,     0,    33,
       0,   517,  1579,     0,    38,    39,   179,    41,    42,    43,
       0,   519,  1910,    46,     0,     0,   183,     0,   257,   569,
     681,    24,    25,   682,    27,    28,   683,    30,   684,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,    67,    68,    69,
       0,     0,     0,  1372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1322,     0,     0,     0,
       0,     0,  1326,  1327,  1328,  1329,  1330,     0,     0,    67,
      68,    69,  1337,  1340,     0,     0,  1344,  1345,  1346,     0,
       0,   110,   333,  1350,     0,     0,     0,   113,   114,   115,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,  1243,
    1372,     0,     0,     0,   159,   160,   161,     0,     0,   110,
     111,   112,   162,     0,     0,   113,   114,   115,   463,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,   156,   157,     0,  1458,
     158,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,   163,  1465,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1477,     0,   165,     0,     0,
    1481,   169,     0,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   517,   518,     0,
    1493,  1494,   179,     0,  1496,  1497,     0,   519,     0,     0,
       0,     0,   183,     0,   257,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   164,
     463,   463,     0,   439,     0,   165,   166,   167,   168,   169,
    1559,     0,  1560,   170,   171,   172,   173,   174,   175,     0,
     176,    89,     0,     0,  1305,     0,     0,     0,     0,   463,
       0,     0,     0,   463,     0,   177,   178,     0,     0,     0,
     179,     0,     0,     0,     0,   180,     0,   181,     0,   182,
     183,     0,   184,     0,   185,     0,     0,     0,     0,     0,
       0,     0,   110,   290,     0,     0,     0,     0,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,     0,
       0,  1605,  1606,     0,     0,  1608,  1609,   147,   148,   149,
       0,  1612,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,     0,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,   567,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1699,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   461,
       0,     0,     0,   179,     0,     0,     0,     0,   299,   463,
       0,     0,     0,   183,     0,     0,   569,   110,   290,   112,
       0,     0,     0,   113,   114,   115,     0,     0,   116,   117,
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
       0,    59,     0,     0,     0,     0,     0,     0,   463,     0,
     463,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,  1595,     0,  1596,     0,
       0,     0,     0,   165,   166,   167,   168,   169,     0,     0,
       0,   170,   171,   172,   173,   174,   175,     0,   176,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   298,     0,     0,     0,   179,     0,
       0,     0,     0,   299,     0,   463,     0,     0,   183,     0,
     300,   110,   290,   112,     0,     0,     0,   113,   114,   115,
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
       0,  1733,     0,  1734,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,     0,     0,     0,   170,   171,   172,   173,   174,
     175,     0,   176,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   298,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,   110,
     333,   112,   183,     0,  1613,   113,   114,   115,     0,     0,
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
     183,     0,  1380,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,   165,   166,   167,   168,   169,     0,     0,   597,
     170,   171,   172,   173,   174,   175,     0,   176,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,     0,     0,     0,   179,     0,     0,
       0,     0,   299,     0,   110,   333,   112,   183,     0,  1600,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     7,     8,     0,
     155,   156,   157,     0,     0,   158,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,   163,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   681,    24,    25,   682,    27,    28,   683,
      30,   684,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,     0,     0,     0,   170,   171,
     172,   173,   174,   175,     0,   176,    89,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
     177,   178,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,   110,   290,   291,   183,     0,  1616,   113,   114,
     115,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
       0,     0,  1803,     0,   154,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,     0,     0,
       0,     0,     0,   162,     0,     0,     0,   293,     0,     0,
     294,     0,     0,   295,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,   681,    24,    25,   682,    27,    28,   683,    30,   684,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,   177,   298,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,  1446,   183,     0,   300,   113,   114,   115,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,     0,     0,
    1880,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   161,     0,     0,     0,     0,
       0,   162,     0,     0,     0,   293,     0,     0,   294,     0,
       0,   295,     0,   296,   447,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,   155,
     156,   157,     0,     0,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   298,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
       0,   183,     0,  1447,   113,   114,   115,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   292,     0,     0,     0,     0,     0,     0,     0,
     166,   167,   168,   147,   148,   149,     0,     0,     0,     0,
     154,     0,   175,     0,   176,    89,     0,     0,     0,     0,
       0,   159,   160,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   293,     0,     0,   294,   327,   112,   295,
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
       0,   293,     0,     0,   294,     0,   112,   295,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,   150,   151,   152,   153,     0,     0,     0,     0,
     155,   156,   157,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   461,     0,     0,     0,   179,     0,     0,
       0,     0,   299,     0,   110,   290,     0,   183,     0,   565,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   292,     0,
       0,   166,   167,   168,     0,     0,     0,     0,     0,   147,
     148,   149,     0,   175,     0,   176,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,     0,     0,     0,   293,
       0,     0,   294,     0,     0,   295,     0,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1016,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,   169,     0,     0,     0,   170,   171,
     172,   173,   174,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   461,     0,     0,     0,   179,     0,     0,     0,     0,
     299,     0,   110,   290,     0,   183,     0,   822,   113,   114,
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
       0,     0,     0,     0,  1069,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,   169,     0,     0,     0,   170,   171,   172,   173,
     174,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   461,
       0,     0,     0,   179,     0,     0,     0,     0,   299,     0,
     110,   290,     0,   183,     0,   825,   113,   114,   115,     0,
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
       0,     0,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,     0,     0,     0,
     169,     0,     0,     0,   170,   171,   172,   173,   174,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   461,     0,     0,
       0,   179,     0,     0,     0,     0,   299,     0,   110,   290,
       0,   183,     0,   845,   113,   114,   115,     0,     0,   116,
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
    1132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,   169,     0,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   298,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,   110,   290,     0,   183,
       0,  1451,   113,   114,   115,     0,     0,   116,   117,   118,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,     0,     0,     0,   169,     0,     0,     0,
     170,   171,   172,   173,   174,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,  1579,     0,     0,     0,   179,     0,     0,
       0,     0,   519,     0,   110,   333,   112,   183,     0,   257,
     113,   114,   115,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
     155,   156,   157,     0,     0,   158,     0,   159,   160,   161,
       0,     0,     0,     0,     0,   162,   163,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,     0,
       0,     0,     0,     0,  1557,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,  1576,     0,     0,     0,     0,     0,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     165,   166,   167,   168,   169,  1644,     0,     0,   170,   171,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1645,     0,
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
     439,     0,     0,     0,   165,     0,     0,     0,   169,  1646,
       0,     0,   170,   171,   172,   173,   174,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,     0,     0,     0,   179,
       0,     0,     0,     0,   299,     0,     0,   412,     0,   183,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,   165,     0,     0,   439,   169,
     818,     0,   819,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,   110,   333,     0,     0,   299,   603,   113,   114,   115,
     183,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,     0,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,   110,   333,     0,
    1253,     0,   162,   113,   114,   115,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   148,   149,     0,     0,     0,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     159,   160,   161,     0,     0,     0,     0,     0,   162,     0,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,   165,   439,     0,
       0,   169,   673,     0,     0,   170,   171,   172,   173,   174,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,     0,
       0,     0,   179,     0,     0,     0,     0,   299,     0,     0,
     605,     0,   183,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   165,     0,     0,     0,   169,     0,     0,
    1647,   170,   171,   172,   173,   174,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,     0,     0,     0,   179,   110,
     333,     0,     0,   299,     0,   113,   114,   115,   183,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   160,   161,     0,     0,     0,     0,     0,
     162,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,  1648,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,  1680,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,   165,     0,     0,     0,   169,
       0,     0,     0,   170,   171,   172,   173,   174,     0,     0,
       0,    89,     0,     0,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,     0,     0,     0,
     179,     0,    -4,    -4,    -4,   299,     0,     0,    -4,    -4,
     183,    -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,
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
       0,    -4,     0,     0,    11,    12,    13,     0,     0,     0,
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
       0,    88,     0,    89,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1749,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1759,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1760,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1791,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1794,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1797,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1827,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1834,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1874,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1876,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1895,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1921,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1959,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,     0,     0,  1960,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,     0,
       0,  1964,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,  1965,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,     0,     0,  1966,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,  1967,   425,   426,   427,   428,
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
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1705,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1706,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1710,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1809,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1810,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1811,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1812,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1820,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1823,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1868,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1885,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1886,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1887,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,  1888,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,  1932,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,     0,     0,     0,  1933,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,  1934,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,     0,     0,
       0,  1935,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,   862,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,   877,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
     884,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,   978,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1077,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1078,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
       0,     0,  1082,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,     0,     0,  1083,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,     0,     0,  1086,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,     0,
       0,  1106,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,     0,     0,  1134,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,     0,     0,  1190,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,     0,     0,
    1195,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,     0,     0,  1456,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,     0,     0,  1504,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,     0,     0,  1669,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     669,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   726,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   730,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   731,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   733,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   735,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   736,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   739,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,   740,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,   842,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
     852,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,   853,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,   854,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,   860,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,   861,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,   873,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,   883,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,   977,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1005,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1010,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1015,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1018,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1019,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1025,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1034,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1035,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1036,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1068,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1070,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1071,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1072,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1076,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439,     0,  1085,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,     0,     0,     0,
       0,   439,     0,  1105,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,     0,     0,
       0,     0,   439,     0,  1189,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,     0,
       0,     0,     0,   439,     0,  1194,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       0,     0,     0,     0,   439,     0,  1342,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,     0,     0,     0,     0,   439,     0,  1558,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,     0,     0,     0,     0,   439,     0,  1575,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,     0,     0,     0,     0,   439,     0,  1599,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,     0,     0,     0,     0,   439,     0,
    1819,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,     0,     0,     0,     0,   439,
       0,  1893,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,     0,     0,     0,     0,
     439
};

static const yytype_int16 yycheck[] =
{
       3,     7,   379,     6,   381,     4,   511,   512,     4,     4,
     250,     4,   410,     5,   412,     4,   414,   394,     4,   265,
       4,     4,  1067,     4,     6,     5,     5,     5,     4,     4,
       4,   277,     4,     6,     4,     3,    13,     6,  1640,     5,
       4,     6,   189,   190,     5,   189,   190,     5,     5,     5,
       5,     4,     6,     6,    57,     6,     6,  1449,   205,     6,
       6,     6,    65,   207,   189,   190,     4,    70,   189,   190,
       7,     6,   142,    81,   189,   190,    84,    84,    81,   101,
     205,  1063,   109,     6,   330,   206,   332,   157,   158,     6,
     112,   206,   101,     6,   189,   190,   195,   196,   120,   121,
     122,   195,   196,   112,   126,   127,   128,   129,     7,   203,
     205,   120,   121,   122,   199,   189,   190,   126,   127,   128,
     129,     7,   199,     3,   201,    78,     6,   189,   190,     7,
      81,    82,   206,   189,   190,     7,   132,   133,   134,   135,
      78,   199,     7,   205,    82,   207,  1538,   189,   190,   205,
       7,   207,   199,   145,     0,     7,    94,   130,     6,   206,
     153,   130,    84,   205,    86,   145,   145,   145,   142,   143,
     142,   143,     6,   156,  1776,  1777,   130,    57,   189,   190,
     183,     8,   175,   130,   203,   207,   175,   189,   190,   208,
      70,   175,   195,   196,   205,     6,   207,   203,   207,   199,
     203,    81,   201,   205,   199,   603,   206,   605,   211,   208,
     213,   207,     6,   206,   206,   218,   184,   206,   199,   222,
     206,     6,   225,   199,   206,   206,   229,   230,   231,   232,
     206,   206,   235,   236,   237,   199,   206,   201,     6,   203,
     206,   206,   187,  1635,   208,   206,   249,   250,   206,   206,
     206,   206,     7,   199,   189,   190,   502,   503,     6,   210,
     206,  1653,   199,   199,   201,   201,   189,   190,   271,   272,
     273,   669,   189,   190,   187,   673,   522,   176,   177,   178,
     179,   199,   285,   286,   200,   195,   196,  1269,     8,   205,
     176,   177,   178,   179,     6,   298,   206,   300,   176,   177,
     178,   179,   199,   183,   176,   177,   178,   179,   201,   195,
     196,   176,   177,   178,   179,   195,   196,   203,   201,   176,
     177,   178,   179,   203,   176,   177,   178,   179,   199,   189,
     190,   211,   205,   336,   207,   338,   339,   583,   195,   196,
     199,   195,   196,   195,   196,   205,    81,   206,   351,    84,
     199,   597,   206,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   195,   196,    78,
     250,   198,    81,   200,   202,    84,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   414,   391,   392,
     393,   394,   395,   344,   195,   196,   399,   400,   401,   402,
     403,   404,     8,   406,   199,   206,   195,   196,   189,   190,
     195,   196,   189,   190,    88,   189,   190,   206,   199,   199,
     423,   176,   177,   178,   179,   206,   206,   205,   205,   207,
    1822,   205,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   397,   200,   195,   196,
     198,     4,   205,   199,   405,     7,   336,   199,   461,   206,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   202,   873,     8,   205,   198,   877,
     189,   190,   189,   190,   195,   196,   202,   207,     6,   205,
     199,   189,   190,   496,   497,   206,    84,   206,   205,   379,
     380,   381,   382,   383,   384,   385,   386,   205,   388,   389,
      84,   391,   392,   393,   394,   395,   189,   190,   206,   399,
     400,   401,   402,   403,   404,    84,   406,  1919,    84,   775,
     189,   190,   205,   189,   190,   538,   539,   540,   489,   490,
     491,   492,    86,   511,   512,   200,   205,   550,   551,   205,
     205,   336,   105,   106,   107,   108,   199,     7,   201,   199,
     203,   114,   565,   206,   117,   208,   191,   192,   193,   572,
     205,    81,   207,   198,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   615,   206,
     105,   106,   198,   189,   190,   380,   111,   382,   383,   384,
     385,   386,   206,   388,   389,   608,   391,   392,   393,   205,
     395,    12,    13,    84,   399,   400,   401,   402,   403,  1664,
     205,  1666,   207,  1668,   176,   177,   178,   179,  1026,   199,
    1028,   201,  1030,   203,  1032,   200,    81,   202,   208,   105,
     106,   206,   669,   195,   196,   111,   673,    81,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    84,   200,    78,   668,   198,    81,   205,   672,
      84,   551,    86,   189,   190,   207,     4,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   200,    89,   205,
     189,   190,   205,    94,    95,   200,    97,    98,    99,   205,
     205,   207,   103,   189,   190,   199,   205,   201,   711,   203,
       4,     6,   715,     4,   208,   718,   956,   200,   721,   205,
     723,     4,   205,   674,   727,   728,   176,   177,   178,   179,
     199,   189,   190,   189,   190,   199,   137,   138,   139,    81,
     189,   190,    84,     6,    86,   195,   196,   205,   751,   205,
       6,   189,   190,   199,    78,  1737,   205,    81,  1740,  1804,
      84,  1743,   199,   199,   201,  1163,   101,   205,    84,   772,
      86,   208,   189,   190,   725,   199,   201,   112,  1155,  1156,
     199,  1179,   201,  1160,  1161,   120,   121,   122,   205,   208,
     817,   126,   127,   128,   129,   200,   199,   202,   230,   231,
     232,   206,   201,   235,   236,   237,   207,   199,   199,   201,
       6,   189,   190,   191,   192,   193,   208,   820,   199,   822,
     198,    78,   825,   199,    81,   201,  1871,    84,  1873,    86,
    1875,   834,   208,   836,   199,   838,  1881,   840,   718,   271,
     272,   721,   845,   723,     6,   199,   873,   850,   199,   199,
     877,   201,   199,   285,   286,     7,   883,   884,   208,    81,
     201,   200,    84,   202,    86,   868,   205,  1849,   205,   872,
     207,     6,   207,   876,   200,   200,   202,   202,   199,   205,
    1925,   884,  1927,   206,  1929,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   200,
     200,   202,   202,   198,   205,   205,   909,   200,     6,   202,
     199,   914,   205,   199,   917,   918,   919,  1899,     6,     7,
    1902,  1426,  1427,  1905,  1322,   199,  1908,   930,   199,   932,
    1170,   206,   200,   718,   202,  1312,  1313,   205,   723,   206,
    1317,  1318,   200,   205,   202,   207,   205,   205,   207,     6,
     977,   978,   101,   956,     6,     7,   959,   960,   961,   962,
     189,   190,  1944,   112,  1946,   205,  1948,   207,   205,   920,
     207,   120,   121,   122,   205,   199,   207,   126,   127,   128,
     129,   984,   199,   199,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   206,   199,
    1003,  1004,   198,  1006,   884,  1008,  1009,   199,   199,  1012,
    1013,   205,   199,   207,  1017,   205,   199,   207,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   199,   199,   914,   101,   198,   206,   918,   919,
     205,    84,   207,    86,   199,   205,   112,   207,   199,   205,
     930,   207,   932,   199,   120,   121,   122,     4,  1085,  1086,
     126,   127,   128,   129,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   956,   206,  1105,  1106,
     198,   206,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   206,   206,   101,   884,
     198,   205,   201,   207,   984,  1108,  1109,  1110,   205,   112,
     207,   205,   205,   207,   207,   206,  1119,   120,   121,   122,
     205,  1361,   207,   126,   127,   128,   129,   199,   205,   914,
     207,   199,   199,   918,   919,   199,  1163,     4,     5,   208,
     205,   207,   207,     6,   101,   930,   205,   932,   207,   205,
       6,   207,  1155,  1156,  1659,   112,   206,  1160,  1161,   205,
     201,   207,     6,   120,   121,   122,   205,  1170,   207,   126,
     127,   128,   129,    40,    41,    42,    43,    44,    45,    46,
      47,  1184,   206,   206,    51,    52,    53,    54,   205,   205,
     207,   207,    59,    60,    61,   201,   205,    64,   207,   984,
     205,     4,   207,     6,   207,  1208,     6,   205,    75,   207,
     205,  1214,   207,   205,   205,   207,   207,  1220,   201,  1222,
    1223,   205,     6,   207,  1227,  1228,   205,  1230,   207,  1232,
     205,  1234,   207,  1236,  1237,  1238,   205,   145,   207,  1616,
     205,   205,   207,   207,   205,   208,   207,  1198,   206,   205,
     207,   207,  1255,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   205,     6,   207,  1270,   198,     6,
     205,  1274,   207,  1276,     6,  1155,  1156,   205,     6,   207,
    1160,  1161,   205,   205,   207,   207,   205,   205,   207,   207,
    1170,   206,   206,   160,   161,   162,   205,  1324,   207,   205,
     205,   207,   207,     6,   205,   172,   207,   174,   175,  1312,
    1313,   205,   201,   207,  1317,  1318,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   205,     4,   207,  1331,   198,
     205,   203,   207,   200,   198,   202,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       7,     4,     5,   206,   198,   207,   205,   205,  1361,     7,
       6,     6,     6,   200,  1367,     7,     7,     6,   206,    49,
      50,     7,    52,     6,  1377,     7,     6,  1380,     6,     6,
       4,    56,    56,    56,  1335,    56,  1626,    40,    41,    42,
      43,    44,    45,    46,    47,   142,   206,   202,    51,    52,
      53,    54,  1353,   200,     6,     6,    59,    60,    61,   200,
     200,    64,   205,   205,    40,  1418,  1419,   205,   205,   205,
     205,   200,    75,   200,   200,    40,    40,  1673,   202,  1380,
    1457,    40,  1312,  1313,     6,     4,     4,  1317,  1318,     6,
       6,   101,     7,     6,  1447,     6,  1449,   145,  1451,     7,
       7,  1331,   112,     7,   145,     7,     7,   145,  1426,  1427,
     120,   121,   122,     7,   101,  1468,   126,   127,   128,   129,
       7,  1422,  1475,   206,     4,   112,   200,     6,   205,   200,
       6,  1361,  1485,   120,   121,   122,  1489,   205,   200,   126,
     127,   128,   129,   200,   205,   205,     6,  1377,   203,   207,
     200,     6,   203,   207,   206,   101,   202,   160,   161,   162,
       7,   206,  1515,   206,   206,     7,   112,     7,     6,   172,
     206,   174,   175,  1474,   120,   121,   122,    40,    40,    40,
     126,   127,   128,   129,    40,  1538,     6,   101,  1489,  1490,
    1491,     6,   195,   196,     6,     6,  1331,   207,   112,     6,
     203,     7,   201,   206,     6,   206,   120,   121,   122,  1805,
       6,   199,   126,   127,   128,   129,   187,     7,   199,     7,
     207,  1574,    86,   253,   254,     7,  1579,     7,     7,     7,
       6,   261,     7,     7,     7,   265,     7,     7,     4,     7,
       4,     6,  1377,   206,   199,     7,     6,  1600,     7,     7,
       6,     6,    21,    22,     7,     6,   206,     6,    84,     7,
    1613,   207,     6,  1616,     6,     4,     4,     4,   207,   205,
       6,     6,     6,  1626,     6,     6,     4,     6,   205,   200,
     200,     7,  1635,   206,     6,     6,     6,     6,   200,  1642,
    1643,   200,   202,   207,   199,    94,     6,   203,     6,     6,
    1653,   200,     6,  1656,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   203,  1672,
     206,     6,   198,   206,  1677,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   108,
     206,  1659,     5,   198,     4,     7,     4,   206,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,  1726,   206,     6,   145,   146,   206,   206,
       6,   150,   151,   152,   153,   206,  1616,   156,   206,     6,
       6,   201,  1745,   162,   163,     6,  1626,     6,   206,   168,
     169,   206,   206,   200,   202,     6,     6,     6,   141,     6,
     205,     4,     6,  1766,     6,     6,     5,     4,     6,   206,
       6,     6,    12,    13,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     6,     6,
     101,     6,   198,     4,     7,     7,     6,     6,     6,     6,
       6,   112,     6,  1806,   145,  1808,     6,     6,     6,   120,
     121,   122,     6,     6,  1765,   126,   127,   128,   129,  1822,
       6,     6,     6,     6,     6,   205,     6,     6,     6,   509,
     510,     6,     6,     6,   200,     6,     6,   517,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     6,    89,
      88,     6,     6,     6,    94,    95,   101,    97,    98,    99,
       7,   203,     6,   103,     6,     5,   206,   112,   206,   206,
       6,   290,   206,     6,   206,   120,   121,   122,   207,    82,
    1883,   126,   127,   128,   129,   207,  1766,   206,   307,  1892,
     206,   206,     6,   207,     7,     6,   207,   137,   138,   139,
     206,     6,     6,     6,     6,     6,   140,     6,  1859,     6,
     143,     6,     6,     6,     6,     6,  1919,     6,   206,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,  1936,     6,  1938,     6,   198,     6,   177,
     178,   179,   180,   181,     7,     6,   206,     6,   206,   206,
     206,     6,   207,     6,   206,   101,   194,     6,     6,     6,
     198,     6,   207,     6,     6,  1968,     6,   207,    12,    13,
       6,     6,     6,   199,   212,   213,   214,   215,   207,   217,
     218,   219,   220,   206,   222,   223,   224,   206,     6,     6,
       6,   229,   206,     6,     6,   101,     6,     6,   417,   200,
       6,   206,     6,     6,   206,     6,   112,     6,     6,   247,
     206,   206,  1892,     6,   120,   121,   122,   206,   256,   257,
     126,   127,   128,   129,     6,   206,     6,   265,     6,     6,
       6,     6,     6,     6,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,  1769,    89,  1193,  1641,  1207,     3,
      94,    95,     3,    97,    98,    99,  1936,   457,  1938,   103,
     298,   299,   300,  1655,    -1,   487,    -1,  1357,    -1,    -1,
      -1,    -1,   310,   311,   312,    -1,   314,    -1,    -1,    -1,
     318,   319,   320,    -1,    -1,   323,    -1,    -1,  1968,    -1,
      -1,    -1,    -1,   137,   138,   139,    -1,    -1,   778,    -1,
      -1,   207,   340,   341,    -1,   785,    -1,  1892,    -1,    -1,
      -1,   791,    -1,    -1,    -1,    -1,   354,   355,    -1,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,
      -1,  1936,   390,  1938,    -1,    -1,    -1,    -1,   396,    -1,
     398,    -1,    -1,   207,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,  1968,   422,   423,    -1,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,     7,     8,   442,   443,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,   461,    -1,    -1,    -1,    94,    95,   467,
      97,    98,    99,    -1,   472,    -1,   103,    -1,    -1,   477,
     478,    -1,    -1,    -1,    -1,   483,   484,    -1,    -1,    -1,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,    -1,    -1,   514,   515,   516,   517,
     518,   519,    -1,    -1,    -1,   523,   524,   525,   526,   527,
      -1,    -1,    -1,   531,    -1,   533,   534,    -1,    -1,    -1,
     538,   539,   540,    -1,    -1,   543,   544,   545,   546,   547,
      -1,    -1,   550,   551,    -1,    -1,   554,    -1,    -1,   999,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   565,    -1,    -1,
      -1,    -1,    -1,   571,   572,    -1,   574,   575,    -1,    -1,
     207,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   595,   596,   198,
     598,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,
     608,  1051,  1052,  1053,   612,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     3,
       4,    -1,    -1,   198,    -1,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,   675,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,   707,
     708,    -1,    -1,   711,   712,   713,    -1,   715,   716,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,    -1,   727,
     728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,   213,   741,    -1,    -1,    -1,   218,    -1,    -1,
      -1,   222,   750,    -1,    -1,    -1,    -1,    -1,   229,    -1,
     939,   940,    -1,    -1,    -1,    -1,   945,   946,    -1,    -1,
      -1,    -1,    -1,    -1,   772,    -1,    -1,    -1,    -1,    -1,
      -1,   779,   780,    -1,    -1,   159,    -1,   785,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
     798,   175,    -1,   801,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,   820,    -1,   822,   199,    -1,   825,  1268,    -1,
     204,    -1,   206,    -1,    -1,    -1,   834,    -1,   836,    -1,
     838,    -1,   840,    -1,    -1,    -1,    -1,   845,    -1,    -1,
      -1,    -1,   850,    -1,    -1,    -1,   225,    -1,   856,    -1,
     858,   859,     6,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
     249,   198,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,   897,
     198,    -1,    -1,    -1,   273,    -1,    -1,   905,   906,   907,
      -1,   909,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,   929,     6,    -1,    -1,    -1,   934,    -1,    -1,    -1,
      -1,    -1,    -1,  1122,  1123,   943,    -1,    -1,  1127,  1128,
    1390,   949,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   959,   960,   961,   962,    -1,    -1,   965,    -1,   338,
     339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,  1428,    -1,
    1430,    -1,  1432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,
    1450,  1451,    -1,    -1,    -1,    -1,    -1,    -1,   387,  1017,
      -1,    -1,    -1,    -1,    -1,   496,   497,    -1,    -1,  1027,
       6,  1029,    -1,  1031,    -1,  1033,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,  1055,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,   539,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   565,  1093,    -1,  1095,  1096,  1097,
      -1,    -1,    -1,    -1,    -1,  1103,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,  1125,    -1,    -1,
      -1,    -1,  1130,    -1,    -1,    -1,    -1,   608,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1182,  1183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1197,
    1198,   137,   138,   139,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,  1663,    -1,  1665,    -1,  1667,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1675,    -1,    -1,  1678,    -1,
     711,    -1,    -1,    -1,   715,    -1,  1244,  1245,  1246,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,  1255,    -1,  1257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1268,   207,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,
      -1,    -1,    -1,  1281,    -1,  1725,    -1,    -1,    -1,  1729,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,
      -1,   772,    -1,   672,    -1,    -1,  1304,  1305,  1306,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    98,    99,    -1,
      -1,  1781,   103,    -1,    -1,  1785,    -1,    -1,    -1,   820,
      -1,   822,    -1,    -1,   825,    -1,  1354,    -1,    -1,    -1,
      -1,    -1,    -1,   834,    -1,   836,    -1,   838,  1808,   840,
    1368,    -1,    -1,    -1,   845,  1373,   137,   138,   139,   850,
      -1,    -1,   751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1388,  1389,    -1,    -1,    -1,    -1,    -1,  1395,  1396,    -1,
      -1,    -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1418,  1419,  1420,    -1,  1422,    -1,    -1,    -1,    -1,  1869,
    1870,    -1,    -1,    -1,    -1,    -1,  1434,    -1,   909,    -1,
      -1,    -1,    -1,    -1,    -1,     7,   207,    -1,    -1,  1447,
      -1,    -1,    -1,  1451,    -1,    -1,  1454,    -1,    12,    13,
      -1,    -1,    -1,  1461,  1462,  1463,  1464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    -1,   959,   960,
     961,   962,  1490,    -1,    -1,    -1,    -1,    -1,    -1,   868,
      -1,    -1,    -1,   872,    -1,   213,    -1,   876,    -1,    -1,
     218,    -1,    -1,    -1,   222,  1513,  1514,    -1,    -1,     8,
      -1,   229,    -1,  1521,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    98,    99,  1017,    -1,   917,   103,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,  1559,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,  1577,
      -1,  1579,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,
     298,    -1,   300,    -1,    -1,    -1,    -1,  1595,    -1,  1597,
      -1,    -1,  1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,    -1,  1613,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,  1631,  1003,  1004,   198,  1006,  1636,  1008,
    1009,    -1,    -1,  1012,  1013,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,  1656,    -1,
      -1,    -1,    -1,    -1,    -1,  1663,    -1,  1665,    -1,  1667,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,
     207,    -1,    -1,  1681,  1682,  1683,  1684,  1685,    -1,    -1,
      -1,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,  1705,  1706,   198,
      -1,    -1,  1710,    -1,    -1,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1722,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1733,     4,     5,     8,  1108,
    1109,  1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1119,    -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1763,    -1,    -1,    -1,    -1,
      -1,  1769,    40,    41,    42,    43,    44,    45,    46,    47,
    1778,    -1,    -1,    51,    52,    53,    54,    -1,   496,   497,
      -1,    59,    60,    61,  1792,    -1,    64,  1795,    -1,    -1,
    1798,    -1,    -1,    -1,  1802,  1276,    -1,    75,  1806,    -1,
    1808,  1809,  1810,  1811,  1812,  1184,    -1,    -1,    -1,    -1,
      -1,    -1,  1820,    -1,    -1,  1823,    -1,    -1,    -1,    -1,
     538,   539,   540,    -1,    -1,    -1,    -1,    -1,    -1,  1208,
      -1,    -1,   550,   551,    -1,  1214,    -1,    -1,    -1,    -1,
      -1,  1220,    -1,  1222,  1223,    -1,    -1,   565,  1227,  1228,
      -1,  1230,    -1,  1232,   572,  1234,    -1,  1236,  1237,  1238,
    1868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1883,  1255,  1885,  1886,  1887,
    1888,    -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
     608,  1270,    -1,    -1,   172,  1274,   174,   175,    -1,   576,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,  1922,  1923,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,  1932,  1933,  1934,  1935,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,  1419,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
      -1,   628,   629,   630,   631,   632,   633,   634,    -1,    -1,
      -1,   638,   639,   640,    -1,     8,    -1,   644,   645,    -1,
      -1,    -1,    -1,   650,   651,   652,    -1,   654,    -1,    -1,
      -1,    -1,    -1,    -1,   661,   662,    -1,    -1,  1367,    -1,
      -1,    -1,    -1,   711,    -1,    -1,    -1,   715,    -1,    -1,
      -1,  1380,   679,    -1,    -1,    -1,    -1,    -1,    -1,   727,
     728,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   772,    -1,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,
    1449,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,  1468,
      -1,    -1,    -1,    -1,    -1,    -1,  1475,    -1,    -1,    -1,
      -1,    -1,   820,    -1,   822,    -1,  1485,   825,    -1,    -1,
    1489,    -1,    -1,    -1,    -1,    -1,   834,    -1,   836,  1600,
     838,    -1,   840,    -1,    -1,    -1,    -1,   845,    -1,    -1,
      -1,    -1,   850,    -1,    -1,    -1,  1515,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,     8,    -1,    -1,  1538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,   163,    -1,  1656,    -1,   167,   168,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   909,    -1,    -1,    -1,  1574,  1677,    -1,    -1,   189,
     190,    -1,    -1,    -1,   194,     3,     4,    -1,    -1,   199,
     200,     9,    10,    11,   204,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,   959,   960,   961,   962,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,  1635,    55,    -1,    -1,
      -1,    -1,    -1,  1642,  1643,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,  1653,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,   964,    86,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,  1017,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,    12,    13,    -1,    -1,   114,    -1,    -1,   117,
     997,   998,    -1,    -1,    -1,  1806,    -1,  1808,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    12,    13,   198,  1726,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,   163,  1745,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    -1,    89,
      -1,   189,   190,    -1,    94,    95,   194,    97,    98,    99,
      -1,   199,  1883,   103,    -1,    -1,   204,    -1,   206,   207,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      -1,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
      98,    99,    -1,    -1,    -1,   103,    -1,   137,   138,   139,
      -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1133,    -1,    -1,    -1,
      -1,    -1,  1139,  1140,  1141,  1142,  1143,    -1,    -1,   137,
     138,   139,  1149,  1150,    -1,    -1,  1153,  1154,  1155,    -1,
      -1,     3,     4,  1160,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,   207,
    1919,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,     3,
       4,     5,    74,    -1,    -1,     9,    10,    11,  1276,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    61,    -1,  1286,
      64,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    75,  1299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,    -1,   159,    -1,    -1,
    1317,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
    1347,  1348,   194,    -1,  1351,  1352,    -1,   199,    -1,    -1,
      -1,    -1,   204,    -1,   206,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   153,
    1418,  1419,    -1,   198,    -1,   159,   160,   161,   162,   163,
     205,    -1,   207,   167,   168,   169,   170,   171,   172,    -1,
     174,   175,    -1,    -1,     8,    -1,    -1,    -1,    -1,  1447,
      -1,    -1,    -1,  1451,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,    -1,   203,
     204,    -1,   206,    -1,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,  1478,  1479,    -1,    -1,  1482,  1483,    48,    49,    50,
      -1,  1488,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,  1579,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,  1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1613,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,  1656,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,  1677,
      -1,    -1,    -1,   204,    -1,    -1,   207,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,    15,
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
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,
    1808,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,
      -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,    -1,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,  1883,    -1,    -1,   204,    -1,
     206,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
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
      -1,   205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,
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
      49,    50,    51,    52,    53,    54,    55,    12,    13,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    98,    99,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,    -1,   174,   175,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
     189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,     3,     4,     5,   204,    -1,   206,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,   207,    -1,    55,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    98,    99,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,   189,   190,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
       3,     4,     5,   204,    -1,   206,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,
     207,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    -1,    86,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,   159,    -1,    -1,    -1,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   199,    -1,     3,     4,
      -1,   204,    -1,   206,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    -1,   172,    -1,   174,   175,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,     4,     5,    84,
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
      -1,    78,    -1,    -1,    81,    -1,     5,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,    -1,    -1,
     117,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,   199,    -1,     3,     4,    -1,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    -1,   172,    -1,   174,    55,    -1,    -1,    -1,
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
      -1,    -1,   199,    -1,     3,     4,     5,   204,    -1,   206,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    64,    -1,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   207,    -1,    -1,   167,   168,
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
      -1,    -1,    -1,    -1,   199,    -1,    -1,   202,    -1,   204,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,   159,    -1,    -1,   198,   163,
     200,    -1,   202,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,     3,     4,    -1,    -1,   199,   200,     9,    10,    11,
     204,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,     3,     4,    -1,
       6,    -1,    74,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,   159,   198,    -1,
      -1,   163,   202,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
     202,    -1,   204,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,   198,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,
     207,   167,   168,   169,   170,   171,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,    -1,    -1,    -1,   194,     3,
       4,    -1,    -1,   199,    -1,     9,    10,    11,   204,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   189,   190,    -1,    -1,    -1,
     194,    -1,    56,    57,    58,   199,    -1,    -1,    62,    63,
     204,    65,    -1,    -1,    -1,    69,    70,    -1,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
     124,   125,     4,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      12,    13,   136,   137,   138,   139,    -1,    -1,   142,    -1,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    38,    39,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,   173,
      -1,   175,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,    -1,    -1,
     142,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   173,    -1,   175,   180,   181,   182,   183,   184,   185,
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
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,
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
     190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,
     200,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
     198
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
       6,   207,     6,     6,     6,     6,     6,   243,   290,   298,
     306,   300,   143,   221,   290,   205,   205,   295,   290,     6,
     205,   244,   246,   296,   296,     6,     6,     6,     6,     6,
       6,   207,   206,   295,   105,   106,   111,   285,   105,   106,
     285,   299,   256,   205,   207,   290,   293,   279,   290,   293,
     279,   290,   293,   279,     6,   205,   207,   296,   257,   207,
     293,     6,   299,   293,   290,   290,   290,   290,   290,   207,
     207,   207,     6,   205,   207,     7,     7,   207,     6,   206,
     290,   290,   207,   290,   207,   207,   240,   239,   206,   290,
     207,   206,   293,   296,     6,   206,   293,     6,   207,   207,
     290,   207,   205,   207,   207,   205,   207,   207,   205,   207,
     296,     6,   101,   207,   267,   206,   205,   207,   205,   205,
     205,   205,   205,     6,     6,   290,   304,   308,   218,   200,
     205,     6,   206,   205,   244,   244,   290,   207,     6,   293,
       6,   293,     6,     6,   207,     6,   273,   290,     6,     6,
     274,   290,     6,     6,   275,   290,     6,   207,   290,   279,
     257,   299,     6,   293,   299,   290,   290,   290,   290,     7,
     199,   207,   224,   290,   295,   290,   207,   207,   205,   205,
     205,   206,   207,   206,   207,   206,   207,     6,     6,   207,
     207,   268,   207,   205,   207,   205,   205,   205,   205,   304,
     200,     6,   206,   200,   207,   207,   290,   293,   293,   279,
       6,   276,   279,     6,   277,   279,     6,   278,   279,     6,
     299,     6,   290,   290,   290,   290,   222,   303,   227,   206,
       6,   207,   205,   205,   207,   206,   207,   206,   207,   206,
     207,   207,   205,   205,   205,   205,   205,   207,   206,   295,
       6,   290,   290,     6,   279,     6,   279,     6,   279,     6,
     290,   290,   290,   290,   303,     6,   225,   303,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   205,   207,
       6,     6,     6,     6,     6,     6,   303,     6
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
     254,   254,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   256,   256,   257,   257,   257,   257,
     257,   257,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   259,   259,   259,   259,   259,   260,   260,   261,   262,
     262,   262,   262,   262,   262,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   265,   265,
     265,   266,   265,   267,   265,   268,   265,   269,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   270,   265,
     271,   265,   272,   265,   273,   265,   274,   265,   275,   265,
     276,   265,   277,   265,   278,   265,   279,   279,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     287,   287,   287,   288,   288,   288,   289,   289,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   292,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   293,
     293,   293,   293,   293,   294,   294,   294,   294,   295,   295,
     296,   296,   296,   296,   296,   296,   297,   297,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     299,   299,   299,   299,   300,   300,   300,   300,   301,   301,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   305,   304,   306,   306,   307,   307,
     308,   308,   308
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
       7,     4,     7,     8,     8,     7,     7,    11,     8,     8,
       8,     8,     9,     3,     4,    10,     7,     7,     8,     8,
      12,     8,     8,     7,     8,     8,     5,    11,     5,     9,
       9,     4,     9,     9,     1,     1,     0,     2,     6,     6,
       6,     6,     8,    10,    14,    16,    12,     8,     8,     6,
      14,     4,     6,     6,     3,     4,     5,     6,     5,     3,
       3,     4,     5,     4,     5,     3,     5,     7,     7,     3,
       7,     3,     2,     2,     2,     2,     2,    15,     2,     2,
       2,     2,     2,    16,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     3,     2,     3,     2,     3,     2,     3,
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
       1,     3,     3,     4,     4,     4,     6,     6,     6,     6,
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
#line 200 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4755 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4767 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 220 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 222 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 223 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 225 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 226 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 235 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 242 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 247 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4861 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4879 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4896 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4913 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4940 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4958 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4975 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4992 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5011 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 378 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 5021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 394 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 399 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 401 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5045 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5153 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 520 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 529 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 536 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5199 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5212 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 555 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 5222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 564 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 571 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5244 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 589 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 5266 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5286 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 637 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 5316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 5323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 5329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 5341 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 5347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 654 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 5353 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 5359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 5365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 5371 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 5377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 5383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 5389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 675 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 680 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5408 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5474 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5493 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5526 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5559 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 823 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 828 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 833 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 838 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 843 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5606 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 850 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5617 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5650 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 918 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 923 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 928 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 933 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 941 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 950 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 956 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5747 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5763 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5779 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5797 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1020 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5824 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1026 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 5833 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5849 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5865 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5883 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1090 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1096 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5921 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5943 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5965 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5978 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5991 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1162 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1167 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6009 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6033 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6057 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6072 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6084 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6110 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6137 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6189 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6205 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6221 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6234 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1377 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6253 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1397 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6281 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6301 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1415 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6307 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6327 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1442 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 6346 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1458 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6370 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1466 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6380 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1472 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6389 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6417 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6432 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6450 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1550 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 6473 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1567 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 6496 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6513 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1593 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1597 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6531 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1603 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1611 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1615 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6558 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1621 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6567 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1629 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1633 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1639 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6594 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1647 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 6602 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1651 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 6612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1657 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 6621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1665 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 6629 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6643 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1681 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 6651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1685 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 6659 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6686 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6733 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6757 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6779 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6804 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6826 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6860 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6894 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6916 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6938 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6968 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6990 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1982 "Gmsh.y" /* yacc.c:1646  */
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
#line 7012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2000 "Gmsh.y" /* yacc.c:1646  */
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
#line 7059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2046 "Gmsh.y" /* yacc.c:1646  */
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
#line 7081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2064 "Gmsh.y" /* yacc.c:1646  */
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
#line 7124 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2103 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2109 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2115 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2122 "Gmsh.y" /* yacc.c:1646  */
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
#line 7184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2147 "Gmsh.y" /* yacc.c:1646  */
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
#line 7213 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2172 "Gmsh.y" /* yacc.c:1646  */
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
#line 7234 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2189 "Gmsh.y" /* yacc.c:1646  */
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
#line 7257 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2209 "Gmsh.y" /* yacc.c:1646  */
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
#line 7294 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2242 "Gmsh.y" /* yacc.c:1646  */
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
#line 7341 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2289 "Gmsh.y" /* yacc.c:1646  */
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
#line 7363 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2307 "Gmsh.y" /* yacc.c:1646  */
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
#line 7384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2324 "Gmsh.y" /* yacc.c:1646  */
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
#line 7404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2340 "Gmsh.y" /* yacc.c:1646  */
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
#line 7451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2388 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2393 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2398 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2403 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2408 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7496 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2413 "Gmsh.y" /* yacc.c:1646  */
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
#line 7523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2436 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 7533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2442 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 7545 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2452 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7551 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2453 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 7557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2458 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 7565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2462 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 7573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2466 "Gmsh.y" /* yacc.c:1646  */
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
#line 7600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2489 "Gmsh.y" /* yacc.c:1646  */
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
#line 7627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2512 "Gmsh.y" /* yacc.c:1646  */
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
#line 7654 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2535 "Gmsh.y" /* yacc.c:1646  */
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
#line 7681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2563 "Gmsh.y" /* yacc.c:1646  */
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
#line 7706 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2584 "Gmsh.y" /* yacc.c:1646  */
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
#line 7736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2611 "Gmsh.y" /* yacc.c:1646  */
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
#line 7760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2632 "Gmsh.y" /* yacc.c:1646  */
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
#line 7785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2653 "Gmsh.y" /* yacc.c:1646  */
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
#line 7809 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2673 "Gmsh.y" /* yacc.c:1646  */
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
#line 7925 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2785 "Gmsh.y" /* yacc.c:1646  */
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
#line 7948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2804 "Gmsh.y" /* yacc.c:1646  */
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
#line 7990 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2843 "Gmsh.y" /* yacc.c:1646  */
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
#line 8097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2951 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2960 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 8120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2966 "Gmsh.y" /* yacc.c:1646  */
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
#line 8139 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2981 "Gmsh.y" /* yacc.c:1646  */
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
#line 8171 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 3009 "Gmsh.y" /* yacc.c:1646  */
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
#line 8187 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 3026 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 3035 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8213 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 3049 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 3063 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 3069 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8246 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3075 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3084 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3093 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3102 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 8298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3116 "Gmsh.y" /* yacc.c:1646  */
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
#line 8361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3175 "Gmsh.y" /* yacc.c:1646  */
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
#line 8383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3193 "Gmsh.y" /* yacc.c:1646  */
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
#line 8404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3210 "Gmsh.y" /* yacc.c:1646  */
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
#line 8423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3225 "Gmsh.y" /* yacc.c:1646  */
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
#line 8453 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3251 "Gmsh.y" /* yacc.c:1646  */
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
#line 8469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3263 "Gmsh.y" /* yacc.c:1646  */
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
#line 8497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3287 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 8505 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3291 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 8514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3296 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 8525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3303 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 8534 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3308 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 8544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3314 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 8553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3319 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 8563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3325 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 8575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3333 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 8583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3337 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 8591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3341 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 8600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3347 "Gmsh.y" /* yacc.c:1646  */
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
#line 8658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3406 "Gmsh.y" /* yacc.c:1646  */
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
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3423 "Gmsh.y" /* yacc.c:1646  */
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
#line 8700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3440 "Gmsh.y" /* yacc.c:1646  */
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
#line 8726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3462 "Gmsh.y" /* yacc.c:1646  */
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
#line 8752 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3484 "Gmsh.y" /* yacc.c:1646  */
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
#line 8791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3519 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8803 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3527 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3535 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8825 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3541 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8836 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3548 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3555 "Gmsh.y" /* yacc.c:1646  */
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
#line 8871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3575 "Gmsh.y" /* yacc.c:1646  */
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
#line 8901 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3601 "Gmsh.y" /* yacc.c:1646  */
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
#line 8917 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3613 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 8927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3625 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3633 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3641 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8973 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3655 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8985 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3663 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8995 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3669 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9007 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3677 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3683 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3691 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3697 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 9050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3705 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3712 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3719 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 9083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3726 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3733 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3740 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9116 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3747 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9127 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3754 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3761 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 9149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3768 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9159 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3774 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3781 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9180 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3787 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3794 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9201 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3800 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 9212 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3807 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3813 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3820 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3826 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3833 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3839 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3846 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3852 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3859 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3865 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3872 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3878 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 9338 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3889 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3892 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3898 "Gmsh.y" /* yacc.c:1646  */
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
#line 9368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3910 "Gmsh.y" /* yacc.c:1646  */
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
#line 9392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3930 "Gmsh.y" /* yacc.c:1646  */
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
#line 9419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3954 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9427 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3958 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3962 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 9443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3966 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3970 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 9459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3974 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3980 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 9479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3986 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9487 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3990 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 3994 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 3998 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4002 "Gmsh.y" /* yacc.c:1646  */
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
#line 9534 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4021 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 9546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4033 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 9554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4037 "Gmsh.y" /* yacc.c:1646  */
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
#line 9571 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4052 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 9579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4056 "Gmsh.y" /* yacc.c:1646  */
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
#line 9597 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4072 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 9605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4076 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 9613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4081 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 9621 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4085 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 9629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4091 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 9637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4095 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 9645 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4102 "Gmsh.y" /* yacc.c:1646  */
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
#line 9705 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4158 "Gmsh.y" /* yacc.c:1646  */
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
#line 9779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4228 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 9788 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4233 "Gmsh.y" /* yacc.c:1646  */
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
#line 9859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4300 "Gmsh.y" /* yacc.c:1646  */
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
#line 9899 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4336 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4344 "Gmsh.y" /* yacc.c:1646  */
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
#line 9958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4387 "Gmsh.y" /* yacc.c:1646  */
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
#line 10001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4426 "Gmsh.y" /* yacc.c:1646  */
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
#line 10025 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4447 "Gmsh.y" /* yacc.c:1646  */
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
#line 10060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4479 "Gmsh.y" /* yacc.c:1646  */
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
#line 10090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4506 "Gmsh.y" /* yacc.c:1646  */
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
#line 10119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4532 "Gmsh.y" /* yacc.c:1646  */
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
#line 10148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4558 "Gmsh.y" /* yacc.c:1646  */
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
#line 10177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4584 "Gmsh.y" /* yacc.c:1646  */
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
#line 10206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
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
#line 10231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
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
#line 10263 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4659 "Gmsh.y" /* yacc.c:1646  */
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
#line 10295 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4687 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 10303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4691 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 10311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4695 "Gmsh.y" /* yacc.c:1646  */
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
#line 10343 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4723 "Gmsh.y" /* yacc.c:1646  */
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
#line 10386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4762 "Gmsh.y" /* yacc.c:1646  */
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
#line 10429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4801 "Gmsh.y" /* yacc.c:1646  */
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
#line 10454 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4822 "Gmsh.y" /* yacc.c:1646  */
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
#line 10479 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4843 "Gmsh.y" /* yacc.c:1646  */
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
#line 10504 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4870 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 10512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4874 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4884 "Gmsh.y" /* yacc.c:1646  */
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
#line 10560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4918 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4919 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10572 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4920 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4925 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4931 "Gmsh.y" /* yacc.c:1646  */
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
#line 10604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4943 "Gmsh.y" /* yacc.c:1646  */
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
#line 10626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4961 "Gmsh.y" /* yacc.c:1646  */
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
#line 10653 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4988 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4989 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 10665 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4991 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 10677 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4992 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 10683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4993 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 10689 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 10695 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4995 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 10701 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4997 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 10712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 5003 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 10718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 5004 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 10724 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 10730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 5006 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 10736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 5007 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 10742 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 5008 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 10748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 10754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 5010 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 10760 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 5011 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 10766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 5012 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 10772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 10778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 5014 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 10784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 5015 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 10790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 5016 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 10796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 5017 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 10802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 5018 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 10808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 5019 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 10814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 10820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 5021 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 10826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 5022 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 5023 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 5024 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 5026 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 5027 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 5028 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 5029 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10874 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 5030 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 5031 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 5033 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 5034 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 5035 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 5044 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 5045 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 10928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 5047 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 5048 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 5049 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 5050 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 5051 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 5052 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 5053 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 5054 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 5059 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 5061 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10992 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 5067 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 5072 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11010 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 5077 "Gmsh.y" /* yacc.c:1646  */
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
#line 11031 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 5094 "Gmsh.y" /* yacc.c:1646  */
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
#line 11053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 5112 "Gmsh.y" /* yacc.c:1646  */
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
#line 11075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 5130 "Gmsh.y" /* yacc.c:1646  */
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
#line 11097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5148 "Gmsh.y" /* yacc.c:1646  */
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
#line 11119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5166 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5171 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 11138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5177 "Gmsh.y" /* yacc.c:1646  */
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
#line 11157 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5192 "Gmsh.y" /* yacc.c:1646  */
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
#line 11178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5209 "Gmsh.y" /* yacc.c:1646  */
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
#line 11200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5227 "Gmsh.y" /* yacc.c:1646  */
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
#line 11222 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5245 "Gmsh.y" /* yacc.c:1646  */
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
#line 11244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5263 "Gmsh.y" /* yacc.c:1646  */
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
#line 11266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5284 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5289 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5294 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5304 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5314 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5319 "Gmsh.y" /* yacc.c:1646  */
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
#line 11336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5330 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5344 "Gmsh.y" /* yacc.c:1646  */
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
#line 11386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5371 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5375 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5379 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5383 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5387 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5394 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5398 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5402 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5406 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5413 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11467 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5418 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5425 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11484 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5430 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11492 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5434 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5439 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5451 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 11533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5462 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5466 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 11554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5478 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 11566 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5486 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 11578 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5494 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 11589 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 11603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5511 "Gmsh.y" /* yacc.c:1646  */
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
#line 11636 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5540 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 11644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5544 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 11652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5548 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 11660 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5552 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 11668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5556 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 11676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5560 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 11684 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5564 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 11692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 11700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5572 "Gmsh.y" /* yacc.c:1646  */
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
#line 11733 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5601 "Gmsh.y" /* yacc.c:1646  */
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
#line 11766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5630 "Gmsh.y" /* yacc.c:1646  */
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
#line 11799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5659 "Gmsh.y" /* yacc.c:1646  */
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
#line 11832 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5689 "Gmsh.y" /* yacc.c:1646  */
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
#line 11848 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5702 "Gmsh.y" /* yacc.c:1646  */
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
#line 11864 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5715 "Gmsh.y" /* yacc.c:1646  */
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
#line 11880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5728 "Gmsh.y" /* yacc.c:1646  */
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
#line 11896 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5740 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5750 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5760 "Gmsh.y" /* yacc.c:1646  */
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
#line 11940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5772 "Gmsh.y" /* yacc.c:1646  */
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
#line 11956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5785 "Gmsh.y" /* yacc.c:1646  */
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
#line 11972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5797 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11980 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5801 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5805 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 11996 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5809 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 12004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5813 "Gmsh.y" /* yacc.c:1646  */
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
#line 12026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5831 "Gmsh.y" /* yacc.c:1646  */
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
#line 12048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5852 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5857 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5861 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12073 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5865 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12086 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5877 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 12094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5881 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 12102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5893 "Gmsh.y" /* yacc.c:1646  */
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
#line 12123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5910 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 12134 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5920 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5924 "Gmsh.y" /* yacc.c:1646  */
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
#line 12158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5939 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5944 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5951 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5955 "Gmsh.y" /* yacc.c:1646  */
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
#line 12200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5968 "Gmsh.y" /* yacc.c:1646  */
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
#line 12218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
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
#line 12236 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
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
#line 12254 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
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
#line 12272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 6024 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 12284 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 6032 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12296 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 6043 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 6047 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12312 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 6051 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 6059 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 6065 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12344 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 6071 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 6079 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 6087 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 6094 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 6102 "Gmsh.y" /* yacc.c:1646  */
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
#line 12410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 6117 "Gmsh.y" /* yacc.c:1646  */
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
#line 12428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 6131 "Gmsh.y" /* yacc.c:1646  */
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
#line 12446 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 6145 "Gmsh.y" /* yacc.c:1646  */
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
#line 12462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 6157 "Gmsh.y" /* yacc.c:1646  */
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
#line 12482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 6173 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12495 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 6182 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12508 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 6191 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12522 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 6201 "Gmsh.y" /* yacc.c:1646  */
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
#line 12537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 6212 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12545 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 6216 "Gmsh.y" /* yacc.c:1646  */
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
#line 12568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 6235 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 6242 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12589 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 6248 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 6255 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 6262 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 12617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 6264 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 12629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 6275 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 12638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 6280 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 12644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 6286 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 12656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 6295 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 12668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 6308 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 6311 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 12680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 6315 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 12686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 12690 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6318 "Gmsh.y" /* yacc.c:1906  */


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
