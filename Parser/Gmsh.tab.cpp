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
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);

void addPeriodicEdge(int,int,const std::vector<double>&);
void addPeriodicFace(int,int,const std::map<int,int>&);
void addPeriodicFace(int,int,const std::vector<double>&);
void computeAffineTransformation(SPoint3&,SPoint3&,double,SPoint3&,std::vector<double>&);

struct doubleXstring{
  double d;
  char *s;
};


#line 178 "Gmsh.tab.cpp" /* yacc.c:339  */

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
    tExp = 269,
    tLog = 270,
    tLog10 = 271,
    tSqrt = 272,
    tSin = 273,
    tAsin = 274,
    tCos = 275,
    tAcos = 276,
    tTan = 277,
    tRand = 278,
    tAtan = 279,
    tAtan2 = 280,
    tSinh = 281,
    tCosh = 282,
    tTanh = 283,
    tFabs = 284,
    tFloor = 285,
    tCeil = 286,
    tRound = 287,
    tFmod = 288,
    tModulo = 289,
    tHypot = 290,
    tList = 291,
    tPrintf = 292,
    tError = 293,
    tStr = 294,
    tSprintf = 295,
    tStrCat = 296,
    tStrPrefix = 297,
    tStrRelative = 298,
    tStrReplace = 299,
    tFind = 300,
    tStrFind = 301,
    tStrCmp = 302,
    tStrChoice = 303,
    tTextAttributes = 304,
    tBoundingBox = 305,
    tDraw = 306,
    tSetChanged = 307,
    tToday = 308,
    tFixRelativePath = 309,
    tCurrentDirectory = 310,
    tSyncModel = 311,
    tNewModel = 312,
    tOnelabAction = 313,
    tOnelabRun = 314,
    tCpu = 315,
    tMemory = 316,
    tTotalMemory = 317,
    tCreateTopology = 318,
    tCreateTopologyNoHoles = 319,
    tDistanceFunction = 320,
    tDefineConstant = 321,
    tUndefineConstant = 322,
    tDefineNumber = 323,
    tDefineString = 324,
    tSetNumber = 325,
    tSetString = 326,
    tPoint = 327,
    tCircle = 328,
    tEllipse = 329,
    tLine = 330,
    tSphere = 331,
    tPolarSphere = 332,
    tSurface = 333,
    tSpline = 334,
    tVolume = 335,
    tCharacteristic = 336,
    tLength = 337,
    tParametric = 338,
    tElliptic = 339,
    tRefineMesh = 340,
    tAdaptMesh = 341,
    tRelocateMesh = 342,
    tPlane = 343,
    tRuled = 344,
    tTransfinite = 345,
    tComplex = 346,
    tPhysical = 347,
    tCompound = 348,
    tPeriodic = 349,
    tUsing = 350,
    tPlugin = 351,
    tDegenerated = 352,
    tRecursive = 353,
    tRotate = 354,
    tTranslate = 355,
    tSymmetry = 356,
    tDilate = 357,
    tExtrude = 358,
    tLevelset = 359,
    tAffine = 360,
    tRecombine = 361,
    tSmoother = 362,
    tSplit = 363,
    tDelete = 364,
    tCoherence = 365,
    tIntersect = 366,
    tMeshAlgorithm = 367,
    tReverse = 368,
    tLayers = 369,
    tScaleLast = 370,
    tHole = 371,
    tAlias = 372,
    tAliasWithOptions = 373,
    tCopyOptions = 374,
    tQuadTriAddVerts = 375,
    tQuadTriNoNewVerts = 376,
    tQuadTriSngl = 377,
    tQuadTriDbl = 378,
    tRecombLaterals = 379,
    tTransfQuadTri = 380,
    tText2D = 381,
    tText3D = 382,
    tInterpolationScheme = 383,
    tTime = 384,
    tCombine = 385,
    tBSpline = 386,
    tBezier = 387,
    tNurbs = 388,
    tNurbsOrder = 389,
    tNurbsKnots = 390,
    tColor = 391,
    tColorTable = 392,
    tFor = 393,
    tIn = 394,
    tEndFor = 395,
    tIf = 396,
    tEndIf = 397,
    tExit = 398,
    tAbort = 399,
    tField = 400,
    tReturn = 401,
    tCall = 402,
    tMacro = 403,
    tShow = 404,
    tHide = 405,
    tGetValue = 406,
    tGetEnv = 407,
    tGetString = 408,
    tGetNumber = 409,
    tHomology = 410,
    tCohomology = 411,
    tBetti = 412,
    tSetOrder = 413,
    tExists = 414,
    tFileExists = 415,
    tGMSH_MAJOR_VERSION = 416,
    tGMSH_MINOR_VERSION = 417,
    tGMSH_PATCH_VERSION = 418,
    tGmshExecutableName = 419,
    tSetPartition = 420,
    tNameFromString = 421,
    tStringFromName = 422,
    tAFFECTPLUS = 423,
    tAFFECTMINUS = 424,
    tAFFECTTIMES = 425,
    tAFFECTDIVIDE = 426,
    tOR = 427,
    tAND = 428,
    tEQUAL = 429,
    tNOTEQUAL = 430,
    tLESSOREQUAL = 431,
    tGREATEROREQUAL = 432,
    tPLUSPLUS = 433,
    tMINUSMINUS = 434,
    UNARYPREC = 435
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 105 "Gmsh.y" /* yacc.c:355  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;

#line 409 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 426 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   9969

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  201
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  515
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1823

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   435

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   186,     2,   196,     2,   185,     2,     2,
     191,   192,   183,   181,   197,   182,   195,   184,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     177,     2,   179,   172,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   193,     2,   194,   190,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   198,     2,   199,   200,     2,     2,     2,
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
     165,   166,   167,   168,   169,   170,   171,   173,   174,   175,
     176,   178,   180,   187,   188,   189
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   192,   192,   193,   198,   200,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   223,   227,   234,   239,   244,   258,   271,   284,
     312,   326,   339,   352,   371,   376,   377,   378,   379,   380,
     384,   386,   391,   393,   399,   503,   398,   521,   528,   539,
     538,   556,   563,   574,   573,   590,   607,   630,   629,   643,
     644,   645,   646,   647,   651,   652,   658,   658,   659,   659,
     665,   666,   667,   672,   678,   738,   767,   796,   801,   806,
     811,   816,   823,   830,   845,   850,   855,   860,   865,   874,
     880,   889,   907,   925,   934,   946,   951,   959,   979,  1002,
    1013,  1021,  1043,  1066,  1092,  1113,  1125,  1139,  1139,  1141,
    1143,  1152,  1162,  1161,  1179,  1189,  1188,  1202,  1204,  1212,
    1218,  1225,  1226,  1230,  1241,  1256,  1266,  1267,  1272,  1280,
    1289,  1297,  1315,  1319,  1325,  1333,  1337,  1343,  1351,  1355,
    1361,  1369,  1373,  1379,  1388,  1391,  1404,  1407,  1417,  1440,
    1472,  1495,  1513,  1534,  1552,  1582,  1612,  1630,  1648,  1675,
    1693,  1711,  1746,  1764,  1803,  1809,  1815,  1822,  1847,  1872,
    1889,  1908,  1942,  1978,  1996,  2013,  2029,  2066,  2071,  2076,
    2081,  2086,  2091,  2114,  2120,  2131,  2132,  2137,  2140,  2144,
    2167,  2190,  2213,  2241,  2262,  2288,  2309,  2331,  2351,  2463,
    2482,  2520,  2629,  2638,  2644,  2659,  2687,  2704,  2713,  2727,
    2741,  2747,  2753,  2762,  2771,  2780,  2794,  2850,  2868,  2885,
    2900,  2919,  2931,  2955,  2959,  2964,  2971,  2976,  2982,  2987,
    2993,  3001,  3005,  3009,  3014,  3069,  3082,  3099,  3116,  3138,
    3160,  3195,  3203,  3211,  3217,  3224,  3231,  3235,  3244,  3252,
    3260,  3269,  3268,  3283,  3282,  3297,  3296,  3311,  3310,  3324,
    3331,  3338,  3345,  3352,  3359,  3366,  3373,  3380,  3388,  3387,
    3401,  3400,  3414,  3413,  3427,  3426,  3440,  3439,  3453,  3452,
    3466,  3465,  3479,  3478,  3492,  3491,  3508,  3511,  3517,  3529,
    3549,  3573,  3577,  3581,  3585,  3589,  3595,  3601,  3605,  3609,
    3613,  3617,  3636,  3649,  3652,  3668,  3671,  3688,  3691,  3697,
    3700,  3707,  3710,  3717,  3773,  3843,  3848,  3915,  3951,  3959,
    4002,  4041,  4061,  4093,  4120,  4146,  4172,  4198,  4224,  4246,
    4274,  4302,  4306,  4310,  4338,  4377,  4416,  4437,  4458,  4485,
    4489,  4499,  4534,  4535,  4536,  4540,  4546,  4558,  4576,  4604,
    4605,  4606,  4607,  4608,  4609,  4610,  4611,  4612,  4619,  4620,
    4621,  4622,  4623,  4624,  4625,  4626,  4627,  4628,  4629,  4630,
    4631,  4632,  4633,  4634,  4635,  4636,  4637,  4638,  4639,  4640,
    4641,  4642,  4643,  4644,  4645,  4646,  4647,  4648,  4649,  4650,
    4651,  4660,  4661,  4662,  4663,  4664,  4665,  4666,  4667,  4668,
    4669,  4674,  4673,  4681,  4686,  4703,  4721,  4739,  4757,  4775,
    4780,  4786,  4798,  4815,  4833,  4851,  4869,  4890,  4895,  4900,
    4910,  4920,  4925,  4936,  4945,  4950,  4977,  4981,  4985,  4989,
    4993,  5000,  5004,  5008,  5012,  5019,  5024,  5031,  5036,  5040,
    5045,  5049,  5057,  5068,  5072,  5084,  5092,  5100,  5107,  5117,
    5146,  5150,  5154,  5158,  5162,  5166,  5170,  5174,  5178,  5207,
    5236,  5265,  5294,  5307,  5320,  5333,  5346,  5356,  5366,  5378,
    5391,  5403,  5421,  5442,  5447,  5451,  5455,  5467,  5471,  5483,
    5490,  5500,  5504,  5519,  5524,  5531,  5535,  5548,  5556,  5567,
    5571,  5575,  5583,  5589,  5595,  5603,  5611,  5618,  5633,  5647,
    5661,  5673,  5689,  5700,  5704,  5723,  5730,  5737,  5736,  5749,
    5754,  5760,  5769,  5782,  5785,  5789
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tPi", "tMPI_Rank", "tMPI_Size", "tEuclidian",
  "tCoordinates", "tExp", "tLog", "tLog10", "tSqrt", "tSin", "tAsin",
  "tCos", "tAcos", "tTan", "tRand", "tAtan", "tAtan2", "tSinh", "tCosh",
  "tTanh", "tFabs", "tFloor", "tCeil", "tRound", "tFmod", "tModulo",
  "tHypot", "tList", "tPrintf", "tError", "tStr", "tSprintf", "tStrCat",
  "tStrPrefix", "tStrRelative", "tStrReplace", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tTextAttributes", "tBoundingBox", "tDraw",
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
  "tIn", "tEndFor", "tIf", "tEndIf", "tExit", "tAbort", "tField",
  "tReturn", "tCall", "tMacro", "tShow", "tHide", "tGetValue", "tGetEnv",
  "tGetString", "tGetNumber", "tHomology", "tCohomology", "tBetti",
  "tSetOrder", "tExists", "tFileExists", "tGMSH_MAJOR_VERSION",
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
     425,   426,    63,   427,   428,   429,   430,    60,   431,    62,
     432,    43,    45,    42,    47,    37,    33,   433,   434,   435,
      94,    40,    41,    91,    93,    46,    35,    44,   123,   125,
     126
};
# endif

#define YYPACT_NINF -1335

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1335)))

#define YYTABLE_NINF -489

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6971,    47,    67,  7093, -1335, -1335,  3382,    26,   -19,  -118,
    -103,    30,   100,   138,   152,   171,    -5,   245,   253,    80,
     118,   106,   106,  -142,   133,   165,    24,   188,   197,    29,
     209,   218,   183,   208,   251,   432,   261,   314,   373,   395,
     300,   442,   637,   646,   267,   347,   478,   172,   370,   -31,
     -31,   430,   -20,    61,   229,   553,   547,     3,    60,   559,
     560,   268,   615,   642,   648,  4876,   666,   454,   486,   512,
      31,    59, -1335,   538, -1335,   736,   751,   540, -1335,  4762,
    5143,    35,    38, -1335, -1335, -1335,  6819,  6819,   565, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335,    51, -1335,   164,   108, -1335,
       4, -1335, -1335, -1335, -1335,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     579,   582,   586,   606,   607,   610,   106,   621, -1335,   106,
   -1335, -1335, -1335, -1335, -1335,   106,   106,   755,   628,   633,
     634,   106,   643,   653, -1335, -1335, -1335, -1335,   611,  6819,
    6819,  6819,  6819,  6819,    57,    16,    20,   647,   264,   877,
   -1335,   672,   851,   232,  -157,   884,  6819,  4953,  4953, -1335,
    6819, -1335, -1335, -1335, -1335,  4953, -1335, -1335, -1335, -1335,
   -1335, -1335,  1114,    16,  6819,  6635,  6819,  6819,   690,  6819,
    6635,  6819,  6819,   713,  6635,  6819,  6819,  5256,   717,   733,
   -1335,  6635,  4876,  4876,  4876,   741,   747,  4876,  4876,  4876,
     754,   783,   794,   810,   814,   818,   850,   853,   744,  6206,
     942,  5256,    31,   812,   815,   -31,   -31,   -31,  6819,  6819,
     -96, -1335,   -43,   -31,   832,   833,   847,  6261,   -28,   -98,
     885,   890,   898,  4876,  4876,  5256,   903,    17,   827, -1335,
     897,  1092,  1093, -1335,   919,   922,   924,  4876,  4876,   930,
     931,   932,   527, -1335,   933,     8,    18,    27,    40,   659,
    5446,  6819,  3858, -1335, -1335,   928, -1335,  1122, -1335,   349,
     -61,  1125,  6819,  6819,  6819,   937,  6819,   935,   997,  6819,
    6819, -1335, -1335,  6819,   940,  1136,  1140, -1335, -1335,  1142,
   -1335,  1143, -1335,   506,  1012,  4015,  4953, -1335,  5256,  5256,
    6819,  6819,   952,   292,  1114, -1335, -1335, -1335, -1335, -1335,
   -1335,  5256,  1145,   959,  6819,  6819,  1155,  6819,  6819,  6819,
    6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,
    6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  4953,
    4953,  4953,  4953,  4953,  4953,  5256,  4953,  4953,  6819,  4953,
    4953,  6819,  1114,  6819,  4953,  4953,  4953,  4953,    16,  1114,
      16,   974,   974,   974,  9002,  8657,   265,   968,  1158,   106,
     972, -1335,   967,  4289,  6819, -1335, -1335,  6635,   123, -1335,
    6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,  6819,
    6819,  6819,  6819,  6819,  6819, -1335, -1335,  6819,  6819, -1335,
   -1335,  1198,   473,  -101, -1335, -1335,   -74,  5061, -1335,   -33,
     202,   219,   977,   978,  9023,  6635,  3424, -1335,   351,  9044,
    9065,  6819,  9086,   378,  9107,  9128,  6819,   412,  9149,  9170,
    1164,  6819,  6819,   413,  1171,  1172,  1173,  6819,  6819,  1174,
    1191,  1191,  6819,  6451,  6451,  6451,  6451,  6819,  6819,  6819,
    6635,  6635,  7592,  1007,  1194,  1003, -1335, -1335,   -68, -1335,
   -1335,  5251,  5441,   -31,   -31,    20,    20,   103,  6819,  6819,
    6819,  6261,  6261,  6819,  4289,   131, -1335,  6819,  6819,  6819,
    6819,  6819,  1196,  1200,  1201,  6819,  1214,  6819,  6819,   915,
   -1335, -1335,  6635,  6635,  6635,  1222,  1223,  6819,  6819,  6819,
    6819,  6819,  1203,   443,    16, -1335,  1184,  6819, -1335,  1185,
   -1335,  1187, -1335,  1188,    39,    41,    42,    43,  6635,   974,
   -1335,  9191, -1335,   577,  6819,  5636, -1335,  6819,  6819,   502,
   -1335,  9212,  9233,  9254,  1069,  5631, -1335,  1041,  3447,  9275,
    8680, -1335, -1335, -1335,  1343, -1335,  1475,  6819, -1335, -1335,
    1046,  1049,   591,  9296,  8703,  6819,  6635,   123,  1237,  1238,
   -1335,  6819,  9317,  8726,   -63,  8634,  8634,  8634,  8634,  8634,
    8634,  8634,  8634,  8634,  8634,  8634,  5821,  8634,  8634,  8634,
    8634,  8634,  8634,  8634,  6011,  6256,  6630,   602,   613,   602,
    1053,  1054,  1051,  1056,  1062,  1072,  7646,   227,   617,  9779,
   -1335,  1280,  1073,  1058,   379,   617,  1059,  1080,  1079,   356,
      76,  1114,  6819,  1268,  1272,    33,   617, -1335,   -18,    25,
      34,   -15, -1335,  5196,   618, -1335,  5256,  3798,  2993,  1842,
     786,   786,   669,   669,   669,   669,   581,   581,   974,   974,
     974,   974,    14,  9338,  8749, -1335,  6819,  1273,    10,  6635,
    1274,  6635,  6819,  1278,  4953,  1279, -1335,    16,  1281,  4953,
    6819,  1114,  1282,  6635,  6635,  1149,  1283,  1284,  9359,  1286,
    1156,  1289,  1290,  9380,  1159,  1292,  1293,  6819,  9401,  5386,
    1081, -1335, -1335, -1335,  9422,  9443,  6819,  5256,  1297,  1298,
    9464,  1111,  9779,  1109,  1117,  9779,  1113,  1119,  9779,  1126,
    1124,  9779,  1127,  9485,  9506,  9527,   641,   661,  6635,  1131,
   -1335, -1335,  1561,  2116,   -31,  6819,  6819, -1335, -1335,  1128,
    1130,  6261,  7672,  7698,  7724,  4871,   325,   -31,  2279,  9548,
    5576,  9569,  9590,  9611,  6819,  1324, -1335,  6819,  9632, -1335,
    8772,  8795, -1335,   676,   679,   680, -1335, -1335,  8818,  8841,
    7750,  8864,   -61,  6635, -1335,  1137,  1135,  5766,  1150,  1151,
    1160, -1335,  6635, -1335,  6635, -1335,  6635, -1335,  6635,   683,
   -1335, -1335,  3818,  6635,   974, -1335,  6635, -1335,  1331,  1336,
    1350,  1165,  6819,  2373,  6819,  6819, -1335,    53, -1335, -1335,
    2530, -1335,  1161,  5256,  1356,   356,   356,  5956,   692,  5256,
   -1335, -1335,  8887,   -61,   262, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335,  6819, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335,  6819,  6819,  6819, -1335,  6635,
   -1335, -1335, -1335, -1335,  4953,  5256,  4953,  4953,  1114, -1335,
   -1335, -1335, -1335, -1335,  6819, -1335, -1335,  4953, -1335, -1335,
   -1335, -1335,  6819,  1357,   132,  6819,  1358,  1361,  1326, -1335,
    1377,  1175,    31,  1379, -1335,  6635,  6635,  6635,  6635, -1335,
     617,  1380,  6819, -1335,  1202,  1204,  1189, -1335,  1384, -1335,
   -1335, -1335, -1335, -1335,   -61,   -61,  8910, -1335, -1335,  1213,
    4953,   468, -1335,   510,  7776, -1335, -1335, -1335,  1387, -1335,
   -1335,  8634,   617,   -31,  3424, -1335,   806,  5256,  5256,  1389,
    5256,   819,  5256,  5256,  1390,  1319,  5256,  5256,  1408,  1396,
    1397,  6635,  1399,  1400,  3592, -1335, -1335,  1402, -1335,  1404,
     123,  6819,   123,  6819,   123,  6819,   123,  6819,  1405,  1406,
    1418,  1420,  1421,   703,  1426,  2576, -1335, -1335,   137,  7802,
    7828, -1335, -1335,  6159,   -65,   -31,   -31,   -31,  1429,  1403,
    1241,  1435,  1251,    44,    63,    72,    88,   -11, -1335,   154,
   -1335,   325,  1436,  1438,  1440,  1441,  1442,  9779, -1335,  1792,
    1247,  1444,  1460,  1461,  1391,  6819,  1462,  1466,  6819,    93,
     704, -1335,  6819, -1335,  6819,  6819,  6819,   708,   712,   715,
     716, -1335,  6819,   719,   723,  5256,  5256,  5256,  1469,  7854,
   -1335,  3996,   571,  1473,  1476, -1335,  5256,  1285, -1335,  6819,
    1477,  6819,  1479, -1335,   617,  1480,  1483, -1335,  1478, -1335,
    1484,  8634,  8634,  8634,  8634,   645,  1294,  1287,  1300,  1301,
    1316,   674,   675,  9653,  1302,  1923, -1335,   456,  1322,  1488,
    2080, -1335, -1335, -1335,    31,  6819, -1335,   727, -1335,   752,
     753,   757,   758,   123, -1335,  9779,  1306,  6819,  6819,  5256,
    1320, -1335, -1335, -1335,  1327, -1335,  1513,    19,  1515,  6819,
    4435,  1518,  1519,     9,  1328,  1329,  1445,  1445,  5256,  1522,
    1332,  1334,  1523,  1528,  5256,  1337,  1531,  1532, -1335,  1534,
    5256,   761,  5256,  5256,  1536,  1537, -1335,  5256,  5256,  9779,
    5256,  9779,  5256,  9779,  5256,  9779,  5256,  5256,  5256,  1346,
    1359,  1552,   481, -1335,  6819,  6819,  6819,  1362,  1363,  -110,
    -107,  -100,  1369, -1335,  5256, -1335,  6819, -1335,  1559, -1335,
    1563, -1335,  1564, -1335,  1565, -1335, -1335,  6261,   238,  5066,
   -1335,  1398,  1407,  5826, -1335,  6635, -1335, -1335, -1335,  1411,
    2502, -1335, -1335,  8933,  1590,   617,  7880,  7906,  7932,  7958,
   -1335, -1335, -1335, -1335,  9779, -1335,   617,  1589,  1594,  1467,
   -1335,  6819,  6819,  6819, -1335,  1597,   493,  1414,  1598,  2559,
   -1335,  2800, -1335,   123, -1335, -1335,   -42, -1335, -1335, -1335,
   -1335, -1335, -1335,  4953, -1335, -1335, -1335,  1114,  1608, -1335,
   -1335,    15, -1335, -1335, -1335, -1335, -1335,  1114,  6819,  1607,
    1610,    33, -1335,  1609,  8956,    31, -1335,  1611,  1617,  1622,
    1623,  5256,  6819,  7984,  8010,   776, -1335,  6819,  1612, -1335,
   -1335,  4953, -1335,  8036,  4055,  9779, -1335, -1335, -1335, -1335,
    6819,  6819,   -31,  1624,  1625,  1626, -1335,  6819,  6819, -1335,
   -1335,  1637,  6819, -1335, -1335,  1641,  1645,  1449,  1650,  1520,
    6819, -1335,  1654,  1655,  1657,  1658,  1659,  1661,   973,  1663,
    6635,  6635,  6819, -1335,  6451,  6201,  9674,  3340,    20,    20,
     -31,  1665,   -31,  1666,   -31,  1674,  6819,   382,  1487,  9695,
   -1335, -1335, -1335, -1335,  6349,   168, -1335,  1689,  3649,  1690,
    5256,   -31,  3649,  1691,   781,  6819, -1335,  1692,   -61, -1335,
    6819,  6819,  6819,  6819, -1335, -1335, -1335,  5256,  4394,   414,
    9716, -1335, -1335,  4496,  5256, -1335, -1335, -1335,  5256, -1335,
    1507,   617,  4245,  4686,  1114,  1694,  3038, -1335,  1702,  1695,
   -1335,  1525, -1335, -1335, -1335, -1335, -1335,  1707,   544,  9779,
    6819,  6819,  5256,  1516,   784,  9779, -1335,  1709,  6819, -1335,
   -1335,  6377,  6407,   348, -1335, -1335, -1335,  6575,  6716, -1335,
    6744,  1717, -1335,  5256, -1335,  1647,  1718,  9779, -1335, -1335,
   -1335, -1335, -1335, -1335,  1529, -1335, -1335,   785,   800,  7619,
    3098,  1722,  1533, -1335,  6819, -1335,  1530,  1538,   221, -1335,
    1540,   230, -1335,  1550,   273, -1335,  1554,  8979,  1724,  5256,
    1725,  1555,  6819, -1335,  6016,   279, -1335,   803,   354,   388,
   -1335,  1727,  6775, -1335,  8062,  8088,  8114,  8140,  1601,  6819,
   -1335,  6819, -1335, -1335,  6635,  3175,  1749,  1558,  1753, -1335,
   -1335,  3858, -1335, -1335,  4953,  9779, -1335, -1335, -1335, -1335,
      31, -1335,  1628, -1335, -1335,  6819,  8166,  8192, -1335,  5256,
    6819,  1766, -1335,  8218, -1335, -1335,  1767,  1769,  1770,  1771,
    1773,  1775,   817,  1584, -1335,  5256,   580,   687,  6635, -1335,
   -1335,    20,  4596, -1335, -1335,  6261,   325,  6261,   325,  6261,
     325,  1780, -1335,   822,  5256, -1335,  6814,   -31,  1782,  6635,
     -31, -1335, -1335,  6819,  6819,  6819,  6819,  6819,  7088,  7116,
     829, -1335, -1335,  1783, -1335,   830,  2223,   839,  1784, -1335,
    1593,  9779,  6819,  6819,   840,  9779, -1335,  6819,   843,   866,
   -1335, -1335, -1335, -1335, -1335, -1335,  1595,  6819,   867,  1599,
     -31,  5256,  1788,  1602,   -31,  1790,   871,  1600,  6819, -1335,
    7144,   419,   541,  7172,   421,   707,  7200,   424,  1141, -1335,
    5256,  1795,  1710,  2693,  1613,   433, -1335,   872,   451,  8244,
    8270,  8296,  8322,  3301, -1335, -1335,  1800, -1335,  6819, -1335,
    1114, -1335, -1335,  6819,  9737,  8348,    45,  8374, -1335, -1335,
    6819,  7228,  1801,   -31,    71, -1335, -1335,   -31,    74, -1335,
    1802, -1335,  7256,  1806,  6819,  1807,  1809,  6819,  1810,  1811,
    6819,  1812,  1620, -1335,  6819, -1335,   325, -1335,  6635,  1815,
    6016,  6819,  6819,  6819,  6819, -1335, -1335,   333, -1335,   875,
   -1335,  6819, -1335,  5256,  6819,  8400, -1335, -1335,   477, -1335,
     490, -1335, -1335, -1335, -1335,  1635,  7284, -1335, -1335,  1638,
    7312, -1335, -1335,  1642,  7340, -1335,  1829,  3321,  1199,  2862,
     876, -1335,   501,   880,  8426,  8452,  8478,  8504,  1114,  1836,
    1651,  9758,   883,  7368,  6819,   -31,   -31,   325,  1837,   325,
    1840,   325,  1844, -1335, -1335, -1335, -1335,   325,  1845,  6635,
    1846,  6819,  6819,  6819,  6819, -1335, -1335,  4953, -1335,  1656,
    1847,  7396,   507,   511,  1230, -1335,  1660,  1504, -1335,  1662,
    1567, -1335,  1664,  1596, -1335,   888, -1335,  8530,  8556,  8582,
    8608,   889, -1335,  1669,  5256, -1335,  1849,  6819,  6819,  1851,
     325,  1853,   325,  1855,   325, -1335,  1857,  6819,  6819,  6819,
    6819,  4953,  1858,  4953,   893, -1335,  7424,  7452, -1335,  1648,
   -1335,  1708, -1335,  2520, -1335,  7480,  7508,  7536,  7564, -1335,
   -1335,   896, -1335,  1862,  1863,  1864,  1865,  1867,  1868, -1335,
   -1335, -1335, -1335,  4953,  1869, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   513,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,     0,     0,     0,   243,     0,
       0,     0,     0,   342,   343,   344,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    20,    11,    12,    13,    14,
      19,    18,    15,    16,    17,     0,    21,   514,     0,   391,
     513,   489,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,     0,
     506,   493,   398,   399,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,   396,   397,   492,     0,     0,
       0,     0,    66,    67,     0,     0,   187,     0,     0,     0,
     349,     0,   485,   514,   404,     0,     0,     0,     0,   227,
       0,   229,   230,   225,   226,     0,   231,   232,   109,   117,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   513,     0,   187,
     514,     0,     0,   339,     0,     0,     0,     0,     0,     0,
       0,     0,   513,   444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,   467,   437,   443,     0,   438,   514,
     404,     0,     0,     0,     0,   479,     0,     0,     0,     0,
       0,   223,   224,     0,   513,     0,     0,   241,   242,     0,
     187,     0,   187,   513,     0,     0,     0,   345,     0,     0,
      66,    67,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   352,   351,   353,     0,     0,     0,     0,     0,     0,
       0,   186,     0,   185,     0,    68,    69,     0,     0,   220,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,   216,     0,     0,   412,
     164,     0,   513,     0,   485,   486,     0,     0,   509,     0,
     107,   107,     0,     0,     0,     0,   473,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   187,   187,     0,   428,
     427,     0,     0,     0,     0,   187,   187,     0,     0,     0,
       0,     0,     0,     0,   257,     0,   187,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
     205,   340,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    67,     0,     0,     0,   450,     0,     0,   451,     0,
     452,     0,   453,     0,     0,     0,     0,     0,     0,   351,
     445,     0,   439,     0,     0,     0,   317,    66,    67,     0,
     222,     0,     0,     0,     0,     0,   187,     0,     0,     0,
       0,   245,   244,   210,     0,   211,     0,     0,   235,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,   417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   401,
     507,     0,     0,     0,     0,     0,     0,     0,     0,   350,
       0,    59,     0,     0,     0,     0,     0,   182,     0,     0,
       0,     0,   188,     0,     0,    59,     0,     0,   367,   366,
     364,   365,   360,   362,   361,   363,   355,   354,   356,   357,
     358,   359,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,   337,   338,     0,     0,     0,     0,   305,     0,
       0,     0,   132,   133,     0,   135,   136,     0,   138,   139,
       0,   141,   142,     0,     0,     0,     0,     0,     0,     0,
     152,   187,     0,     0,     0,     0,     0,   430,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,   320,     0,     0,   206,
       0,     0,   202,     0,     0,     0,   335,   334,     0,     0,
       0,     0,   417,     0,   468,     0,     0,     0,     0,     0,
       0,   454,     0,   455,     0,   456,     0,   457,     0,     0,
     350,   440,   447,     0,   356,   446,     0,   469,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,   212,   214,
       0,   515,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    74,     0,   406,   405,   419,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   390,   378,     0,   380,   381,
     382,   383,   384,   385,   386,     0,     0,     0,   501,     0,
     503,   497,   498,   499,     0,     0,     0,     0,     0,   425,
     505,   121,   126,    99,     0,   494,   496,     0,   403,   409,
     410,   490,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,   411,     0,     0,     0,     0,   511,
       0,     0,     0,    44,     0,     0,     0,    57,     0,    35,
      36,    37,    38,    39,   408,   407,     0,   487,    24,    22,
       0,     0,    25,     0,     0,   217,   510,    70,   110,    71,
     118,     0,     0,     0,   475,   476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   308,   306,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,   215,     0,     0,
       0,   177,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
     248,     0,     0,     0,     0,     0,     0,   310,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   405,
       0,   470,     0,   449,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,   209,     0,     0,   346,     0,
       0,     0,     0,   512,     0,     0,     0,   414,     0,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,    84,    89,    91,     0,     0,   483,     0,    97,     0,
       0,     0,     0,     0,    75,   368,     0,     0,     0,     0,
       0,    30,   416,   415,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,   134,
       0,   137,     0,   140,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,   291,     0,   297,     0,   299,
       0,   293,     0,   295,     0,   258,   287,     0,     0,     0,
     200,     0,     0,     0,   321,     0,   204,   203,   341,     0,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
     458,   459,   460,   461,   448,   442,     0,     0,     0,     0,
     480,     0,     0,     0,   236,     0,     0,     0,     0,     0,
      87,     0,    86,     0,    76,   219,   418,   218,   379,   387,
     388,   389,   504,     0,   422,   423,   424,     0,     0,   402,
     122,     0,   508,   127,   421,   495,    78,    59,     0,     0,
       0,     0,    77,     0,     0,     0,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,     0,     0,    26,
      27,     0,    28,     0,     0,   111,   114,    72,    73,   148,
       0,     0,     0,     0,     0,     0,   151,     0,     0,   167,
     168,     0,     0,   153,   174,     0,     0,     0,     0,   144,
       0,   313,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,   187,   187,
       0,   268,     0,   270,     0,   272,     0,   437,     0,     0,
     298,   300,   294,   296,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   318,     0,   418,   471,
       0,     0,     0,     0,   472,   156,   157,     0,     0,     0,
       0,   100,   104,     0,     0,   347,    80,    79,     0,   420,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
      95,     0,   484,   189,   190,   191,   192,     0,     0,    40,
       0,     0,     0,     0,     0,    42,   488,     0,     0,   112,
     115,     0,     0,   147,   154,   155,   159,     0,     0,   169,
       0,     0,   315,     0,   162,     0,     0,   304,   173,   149,
     161,   172,   176,   160,     0,   170,   175,     0,     0,     0,
       0,     0,     0,   434,     0,   433,     0,     0,     0,   259,
       0,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,   198,     0,     0,     0,
     193,     0,     0,    33,     0,     0,     0,     0,     0,     0,
     478,     0,   238,   237,     0,     0,     0,     0,     0,   500,
     502,     0,   123,   125,     0,   128,   129,   130,    90,    92,
       0,    98,     0,    81,    45,     0,     0,     0,   436,     0,
       0,     0,    29,     0,   121,   126,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,   311,   311,     0,   105,
     106,   187,     0,   180,   181,     0,     0,     0,     0,     0,
       0,     0,   288,     0,     0,   187,     0,     0,     0,     0,
       0,   184,   183,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,     0,    82,     0,   473,     0,     0,   482,
       0,    41,     0,     0,     0,    43,    58,     0,     0,     0,
     329,   331,   330,   332,   333,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
       0,     0,     0,   253,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,   477,   239,     0,   348,     0,   124,
       0,   131,    96,     0,     0,     0,     0,     0,   113,   116,
       0,     0,     0,     0,     0,   312,   322,     0,     0,   323,
       0,   178,     0,   274,     0,     0,   276,     0,     0,   278,
       0,     0,     0,   289,     0,   249,     0,   187,     0,     0,
       0,     0,     0,     0,     0,   158,   103,     0,   119,     0,
      49,     0,    55,     0,     0,     0,   145,   171,     0,   326,
       0,   327,   328,   431,   262,     0,     0,   269,   263,     0,
       0,   271,   264,     0,     0,   273,     0,     0,     0,   255,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,     0,
     282,     0,   284,   290,   301,   254,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   120,    46,     0,    53,     0,
       0,     0,     0,     0,     0,   265,     0,     0,   266,     0,
       0,   267,     0,     0,   201,     0,   195,     0,     0,     0,
       0,     0,    47,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,   275,     0,
     277,     0,   279,     0,   196,     0,     0,     0,     0,    48,
      50,     0,    51,     0,     0,     0,     0,     0,     0,   462,
     463,   464,   465,     0,     0,    56,   324,   325,   281,   283,
     285,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1335, -1335, -1335, -1335,   770, -1335, -1335, -1335, -1335,   258,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335,  -382,   -66,  2026,   614, -1335,  1463, -1335, -1335,
   -1335, -1335, -1335,   401, -1335,   404, -1335, -1335, -1335, -1335,
   -1335, -1335,   789,  1908,    -1,  -486,  -252, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335,  1912, -1335, -1335, -1335, -1335, -1335,
   -1335, -1335, -1335, -1335, -1335, -1335, -1335, -1335,  -989,  -975,
   -1335, -1335,  1446, -1335,   402, -1335, -1335, -1335, -1335,  1535,
   -1335, -1335,   590, -1335, -1334,  2198,   269,  2307,   127,  -238,
     670, -1335,    21,    28, -1335,  -368,    -3,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    89,   920,    90,    91,   672,  1388,  1394,
     909,  1096,  1560,  1761,   910,  1710,  1801,   911,  1763,   912,
     913,  1100,   341,   429,   178,   408,    92,   687,   440,  1504,
    1505,   441,  1555,  1071,  1240,  1072,  1243,   721,   724,   727,
     730,  1416,  1283,   652,   293,   402,   403,    95,    96,    97,
      98,    99,   100,   101,   294,  1001,  1656,  1727,   756,  1440,
    1443,  1446,  1685,  1689,  1693,  1746,  1749,  1752,   997,   998,
    1135,   957,   718,   765,  1582,   103,   104,   105,   106,   295,
     180,   871,   490,   251,  1265,   296,   297,   298,   553,   307,
     893,  1087,   438,   434,   872,   439,   183,   300
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   617,    94,   619,   485,   504,  1457,   267,   343,   749,
     750,   627,  1178,   535,   642,  1279,   918,   519,   903,  1373,
     314,   516,  1176,   538,   400,  1270,   656,   181,   208,   208,
     339,   340,   540,   213,   182,   305,   189,   891,   213,   185,
     319,  -486,   342,   321,   791,   542,   793,   795,   797,   204,
    1167,  1672,   254,     4,   270,   255,   205,   327,   256,   186,
    1043,   396,   299,   308,   272,   259,   273,     5,   574,  1169,
     576,   493,   494,   187,   493,   494,   270,  1679,  1171,  1512,
    1681,   493,   494,   655,   988,   493,   494,  1320,   188,  1321,
    1322,   678,  1323,   507,  1173,   989,   679,  1324,   108,  1325,
     508,   184,   495,   990,   991,   992,   191,   315,   318,   993,
     994,   995,   996,   493,   494,   334,   493,   494,   680,    48,
      49,    50,    51,   681,   339,   340,   339,   340,    56,   744,
     655,    59,   274,   260,  1158,  -487,  1077,   261,   493,   494,
     904,   905,   906,   907,   192,   339,   340,   536,   268,   262,
     246,   247,   271,   493,   494,   496,  -488,   539,   193,   683,
     248,   246,   247,  1374,   684,  1564,   541,   249,  1168,    88,
     506,   248,   270,   204,   316,   401,   216,   194,   257,   543,
     895,  1578,    88,   898,   270,   270,   195,  1170,  1175,   919,
     493,   494,   270,   397,   398,   344,  1172,   345,   919,   346,
     270,   269,   299,  1176,   177,   829,   537,   299,   433,   436,
     517,   299,  1174,   908,   299,   209,   209,   177,   299,   299,
     299,   299,   210,   896,   299,   299,   299,   214,   190,   306,
     442,   892,   897,   320,   742,   743,   322,   792,   299,   794,
     796,   798,   328,  1673,   335,   336,   337,   338,  1044,   329,
     309,   196,   493,   494,   758,   493,   494,   882,   885,   197,
     299,   299,   299,   339,   340,   217,   432,   111,  1078,  1079,
     399,   884,   641,   198,   299,   299,   335,   336,   337,   338,
     339,   340,   435,   435,   493,   494,   218,   299,  1194,   299,
     435,   335,   336,   337,   338,   339,   340,   200,   443,   201,
     751,   137,   138,   139,   140,   141,   142,   263,   242,   264,
     146,   199,   493,   494,   813,   148,   149,   150,   493,   494,
     151,   243,   244,   270,   206,   299,   299,   820,   757,   219,
     643,   156,   448,   988,  1154,   493,   494,   453,   299,  1712,
    1708,   457,   238,   277,   989,   239,   278,   580,   463,   493,
     494,  1177,   990,   991,   992,   330,   207,   331,   993,   994,
     995,   996,   588,   655,   332,  1452,   270,   270,   270,   270,
     270,   270,   299,   270,   270,   227,   270,   270,   228,   211,
     229,   270,   270,   270,   270,   270,   222,   270,   212,   223,
     554,   618,   224,   620,   621,   622,   685,   624,   625,   686,
     215,   628,   493,   494,   299,   632,   633,   634,   635,   216,
     630,   493,   494,   688,   159,   160,   686,   637,  1525,   869,
     988,   435,  1471,   427,   684,   428,   167,  1527,    88,   168,
    1784,   989,   332,   335,   336,   337,   338,  1336,   220,   990,
     991,   992,   299,  1049,  1051,   993,   994,   995,   996,   339,
     340,   225,   339,   340,   493,   494,   405,  1058,   406,   221,
     493,   494,   407,  1247,   435,   435,   435,   435,   435,   435,
    1529,   435,   435,   226,   435,   435,  1537,   299,   299,   435,
     435,   435,   435,   636,   405,   638,   406,  1313,  1314,   975,
     586,   464,   465,   466,   401,   401,   469,   470,   471,  1362,
    1363,   723,   726,   729,   732,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   299,
     299,   299,   230,   424,   335,   336,   337,   338,   835,   493,
     494,   270,   512,   513,   654,   493,   494,  1592,   240,  1595,
     557,  1598,   558,   339,   340,   299,   525,   526,   694,   332,
     695,  1539,   299,   241,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   555,   422,   423,   245,   493,
     494,   876,   424,   883,   886,   694,   877,   700,  1138,  1213,
    1140,  1448,  1142,   299,  1144,  1540,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     493,   494,   493,   494,   424,   493,   494,   736,   737,   694,
     694,   704,   710,  1472,   493,   494,  1644,  1176,  1647,   279,
    1176,  1650,   266,  1176,   335,   336,   337,   338,   253,   785,
    1658,   265,   493,   494,   275,   405,   988,   406,   276,   250,
     252,   783,   258,   339,   340,   302,   280,   989,  1660,   773,
     774,   775,   281,   299,  1086,   990,   991,   992,   493,   494,
    1107,   993,   994,   995,   996,   694,   676,  1698,   677,   887,
     301,   493,   494,   177,  1715,   799,   299,   303,   299,  1579,
    1580,   270,   493,   494,   270,  1581,   270,  1716,   493,   494,
     299,   299,   493,   494,   405,  1248,   406,   344,  1729,   577,
     806,   532,  1108,   304,  1767,   926,   177,   694,  1768,   231,
     930,  1261,   232,   828,   299,   233,   835,   234,   530,   932,
     531,   235,   532,  1176,   236,   176,   237,   177,  1744,   310,
    1747,   544,  1750,   313,   545,   299,  1494,   546,  1753,   547,
    1645,  1495,   311,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   312,   326,  1050,
    1052,   424,   383,  1214,   421,   422,   423,  1057,  1059,  1176,
     372,   424,  1176,   373,   694,  1176,   801,   374,  1176,   435,
     299,  1789,   928,  1791,   435,  1793,  1583,  1584,   823,   299,
     824,   299,  1581,   299,   405,   299,   406,   375,   376,   684,
     299,   377,   988,   299,   390,   405,   921,   406,   923,   405,
     859,   406,   379,   989,  1176,   694,  1176,   900,  1176,   384,
     299,   990,   991,   992,   385,   386,   299,   993,   994,   995,
     996,   270,  1436,  1437,   388,   488,   489,   405,   694,   406,
     971,  1368,   694,   497,   389,   404,  1253,   505,  1102,  1103,
     419,   420,   421,   422,   423,  1060,   299,   426,   694,   424,
     972,   270,   299,   270,   270,   973,   405,   405,   406,   406,
     425,  1238,  1241,   694,   270,  1013,   694,   694,  1014,  1015,
     694,   451,  1031,   409,  1114,  1066,  1115,  1068,  1069,   694,
     430,  1054,   299,   299,   299,   299,  1070,  1120,  1074,  1121,
     694,   694,  1151,  1195,   456,   694,  1648,  1200,   461,   694,
    1020,  1201,   694,   694,  1202,  1203,   694,   270,  1205,  1027,
     694,  1028,  1206,  1029,  1255,  1030,  1256,     7,     8,   435,
    1033,   462,   467,  1034,   299,   299,   554,   299,   468,   299,
     299,  1106,   480,   299,   299,   472,   483,   587,   299,   694,
     694,  1257,  1258,  1059,   694,   694,  1259,  1260,   694,   435,
    1297,   435,   435,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   435,  1392,   473,  1393,   424,  1424,   694,  1425,
    1461,  1500,   694,  1501,  1516,   474,  1065,   648,    24,    25,
     649,    27,    28,   650,    30,   651,    32,   694,    33,  1517,
    1392,   475,  1538,    38,    39,   476,    41,    42,    43,   477,
     486,  1249,    46,   487,  1392,   435,  1576,  1382,   578,  1600,
     518,  1601,  1089,  1090,  1091,  1092,   694,  1618,  1616,  1619,
     498,   499,   299,   299,   299,  1587,   684,  1392,  1621,  1626,
    1238,   478,  1628,   299,   479,   500,    67,    68,    69,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,  1241,  1392,  1629,  1632,   424,   694,   694,
    1640,  1659,  1500,   694,  1709,  1728,   509,   694,  1131,  1730,
    1392,   510,  1739,   747,   748,   694,  1781,  1776,  1782,   511,
    1392,   489,  1803,  1813,   515,  1814,   299,   332,   520,   521,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   555,   422,   423,   772,   299,  1557,   522,   424,   111,
     523,   299,   524,   527,   528,   529,   534,   299,   556,   299,
     299,   560,   564,   566,   299,   299,   567,   299,  1276,   299,
     177,   299,   571,   299,   299,   299,   572,   784,   573,   575,
     585,   590,   591,   137,   138,   139,   140,   141,   142,   594,
    1369,   299,   146,   644,   424,   645,   647,   148,   149,   150,
     176,   707,   151,   807,   690,   691,   299,   711,   712,   713,
     299,   716,   299,   156,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   717,   739,
     740,   741,   424,   764,   675,   811,   766,   782,   767,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     769,   848,   849,   850,   851,   852,   853,   854,   776,   777,
     270,   858,   860,   861,   786,   788,   988,   789,   790,   814,
     821,   822,   870,   830,   831,   862,   863,   989,   864,   878,
     875,   879,  1558,   865,  1370,   990,   991,   992,   299,   866,
     894,   993,   994,   995,   996,  1371,   159,   160,   270,   867,
     874,   299,   880,   881,   889,  1375,   890,   917,   167,   951,
     922,   168,  1369,  1603,   925,   927,   873,   929,   936,   933,
     937,   938,  1397,   940,   988,   941,   942,   943,   945,   946,
     947,   956,  1400,   960,   958,   989,   961,   299,   299,   962,
     963,   964,  1344,   990,   991,   992,   966,   401,   401,   993,
     994,   995,   996,   965,   967,   988,   974,   981,   435,   982,
    1008,  1021,  1083,  1022,   978,   299,   989,   299,  1035,   299,
    1651,   984,  1431,  1036,   990,   991,   992,   999,  1024,  1025,
     993,   994,   995,   996,   299,     7,     8,  1037,  1026,  1046,
    1038,   299,  1048,  1076,  1081,   299,   435,  1082,  1085,   299,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,  1084,  1088,  1094,  1099,   424,   299,
    1101,  1476,  1105,  1097,  1110,  1098,  1118,  1124,  1725,  1125,
    1483,  1486,  1487,  1129,  1130,  1699,  1132,  1133,  1136,  1163,
     299,  1137,  1146,  1147,  1128,   648,    24,    25,   649,    27,
      28,   650,    30,   651,    32,  1148,    33,  1149,  1150,  1769,
    1152,    38,    39,  1162,    41,    42,    43,  1427,  1428,  1164,
      46,  1165,  1166,  1179,  1180,  1185,   299,  1181,  1182,  1183,
    1186,   299,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,  1187,  1188,  1191,  1189,
     424,   299,  1192,  1210,    67,    68,    69,  1215,   299,  1234,
    1216,   270,  1226,  1220,  1218,  1222,  1224,     7,     8,  1225,
    1227,  1233,  1235,  1236,  1245,  1251,   299,  1262,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   299,  1237,  1093,   299,   424,  1250,  1267,  1269,
     401,  1272,  1268,  1113,  1277,  1278,  1280,  1281,  1286,  1289,
    1287,   299,  1288,  1282,  1290,  1292,   299,  1293,  1294,  1295,
    1300,   179,   818,  1301,  1310,  1111,  1112,   648,    24,    25,
     649,    27,    28,   650,    30,   651,    32,  1311,    33,  1312,
    1318,  1319,  1326,    38,    39,  1330,    41,    42,    43,  1331,
    1332,  1333,    46,     7,     8,  1159,  1160,  1161,   299,   435,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,  1348,  1355,  1340,   299,   424,   988,
    1356,  1550,  1357,  1361,  1365,  1341,    67,    68,    69,  1345,
     989,  1364,  1372,  1377,  1378,  1380,  1396,  1383,   990,   991,
     992,   324,   325,  1384,   993,   994,   995,   996,  1385,  1386,
    1404,  1405,  1406,   648,    24,    25,   649,    27,    28,   650,
      30,   651,    32,  1409,    33,  1586,  1411,  1413,  1668,    38,
      39,  1412,    41,    42,    43,   299,  1414,   299,    46,  1415,
    1418,  1419,   988,  1420,  1421,  1422,  1607,  1423,  1223,  1426,
     299,  1439,  1442,   989,   819,  1228,  1229,  1230,  1231,  1232,
    1445,   990,   991,   992,  1449,  1239,  1242,   993,   994,   995,
     996,   988,    67,    68,    69,  1453,  1456,  1460,  1463,  1479,
    1488,  1491,   989,  1771,   391,   392,   393,   394,   395,  1490,
     990,   991,   992,  1493,  1499,  1502,   993,   994,   995,   996,
    1492,   431,  1511,  1513,  1514,   437,   299,  1515,  1520,  1523,
    1532,  1521,  1534,  1541,   270,  1547,  1735,  1524,  1526,   444,
     446,   449,   450,   988,   452,   446,   454,   455,  1528,   446,
     458,   459,  1530,  1535,   989,  1552,   446,  1553,  1762,  1554,
     976,   299,   990,   991,   992,  1559,  1773,  1335,   993,   994,
     995,   996,  1566,  1570,   482,  1571,  1572,  1573,   270,  1574,
     270,  1575,  1577,   491,   492,  1700,  1599,  1703,  1606,  1617,
    1622,  1623,   492,  1630,  1636,  1775,  1639,  1633,  1184,  1641,
    1637,  1653,  1799,   988,  1802,  1654,  1666,  1677,  1682,  1349,
     270,  1657,  1684,  1687,   989,  1688,  1691,  1692,  1695,  1696,
    1354,  1701,   990,   991,   992,   549,   551,   446,   993,   994,
     995,   996,   435,  1717,  1821,  1723,  1719,   561,   562,   563,
    1721,   565,  1736,  1745,   568,   569,  1748,  1806,   570,  1737,
    1751,  1754,  1756,  1765,  1764,  1785,  1755,  1788,  1770,  1790,
    1772,  1792,  1774,  1794,  1800,   583,   584,  1783,  1815,  1816,
    1817,  1818,  1403,  1819,  1820,  1822,   435,  1271,   435,   592,
     593,  1669,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   689,  1568,  1284,  1807,   435,  1569,
    1438,    93,  1441,   626,  1444,   102,   629,   719,   631,  1585,
       0,  1379,     0,     0,     0,     0,     0,     0,  1455,  1246,
       0,  1458,  1459,     0,     0,     0,     0,     0,     0,   653,
       0,     0,   446,     0,     0,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   669,   670,   671,
       0,     0,   673,   674,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
     549,     0,   424,     0,     0,  1480,   698,     0,     0,     0,
       0,   703,     0,     0,     0,     0,   708,   709,     0,     0,
       0,     0,   714,   715,     0,     0,     0,   720,   722,   725,
     728,   731,   733,   734,   735,   446,   446,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,   752,   753,   754,   391,   392,   755,     0,
       0,     0,   759,   760,   761,   762,   763,   202,   203,     0,
     768,     0,   770,   771,     0,     0,     0,   446,   446,   446,
       0,     0,   778,   779,   780,   592,   781,     0,     0,     0,
       0,     0,   787,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,     0,     0,  1252,     0,     0,   802,
     804,     0,   673,   674,     0,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,   781,   424,     0,  1591,     0,  1594,     0,  1597,
     827,   446,     0,     0,     0,     0,   832,  1605,     7,     8,
    1608,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,     0,     0,     0,     0,
    1634,     0,   378,     0,  1638,   380,     0,   888,     0,     0,
       0,   381,   382,     0,     0,     0,     0,   387,   648,    24,
      25,   649,    27,    28,   650,    30,   651,    32,     0,    33,
       0,     0,     0,     0,    38,    39,     0,    41,    42,    43,
       0,   916,     0,    46,   446,     0,   446,   924,     0,     0,
       0,     0,     0,  1678,     0,   931,     0,  1680,   804,   934,
    1620,   554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   948,     0,     0,     0,     0,    67,    68,    69,
    1702,   954,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,   446,     0,     0,     0,     0,     0,     0,
     979,   980,     0,     0,     0,     0,   983,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,  1009,     0,     0,  1742,  1743,     0,   533,     0,
       0,     0,     0,     0,     0,   977,     0,     0,   446,     0,
       0,     0,     0,     0,     0,   559,     0,   446,     0,   446,
       0,   446,     0,   446,     0,     0,     0,     0,   446,     0,
       0,   446,     0,     0,     0,     0,     0,  1039,     0,  1041,
    1042,   648,    24,    25,   649,    27,    28,   650,    30,   651,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,  1061,     0,     0,     7,     8,     0,     0,     0,
    1062,  1063,  1064,     0,   446,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   693,   422,   423,  1073,
      67,    68,    69,   424,     0,   460,     0,  1075,     0,     0,
    1080,     0,     0,     0,     0,   646,     0,     0,     0,     0,
     446,   446,   446,   446,     0,     0,     0,  1095,     0,   484,
       0,     0,     0,     0,     0,   648,    24,    25,   649,    27,
      28,   650,    30,   651,    32,     0,    33,     0,     0,     0,
       0,    38,    39,   514,    41,    42,    43,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,  1000,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1139,     0,  1141,     0,
    1143,     0,  1145,     0,    67,    68,    69,     0,  1346,     0,
       0,     0,   447,     0,     0,     0,     0,   447,     0,     0,
       0,   447,     0,     0,     0,     0,   581,   582,   447,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   589,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
    1190,     0,     0,  1193,     0,     0,     0,  1196,     0,  1197,
    1198,  1199,     0,     0,     0,  1366,     0,  1204,     0,     0,
       0,     0,  1040,   623,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1219,     0,  1221,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   550,     0,   447,
       0,     0,   648,    24,    25,   649,    27,    28,   650,    30,
     651,    32,     0,    33,     0,   988,     0,     0,    38,    39,
    1254,    41,    42,    43,     0,     0,   989,    46,     0,     0,
       0,     0,  1263,  1264,   990,   991,   992,     0,     0,     0,
     993,   994,   995,   996,  1273,  1275,     0,     0,   648,    24,
      25,   649,    27,    28,   650,    30,   651,    32,     0,    33,
       0,    67,    68,    69,    38,    39,     0,    41,    42,    43,
       0,     0,     0,    46,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,  1315,
    1316,  1317,   424,     0,     0,     0,     0,     0,     0,  1327,
       0,  1329,     0,     0,     0,     7,     8,    67,    68,    69,
       0,     0,  1334,     0,   447,     0,     0,     0,     0,  1808,
     446,     0,     0,     0,     0,     0,     0,     0,     0,  1045,
       0,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,  1358,  1359,  1360,   424,
       0,     0,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   648,    24,    25,   649,    27,
      28,   650,    30,   651,    32,  1153,    33,     0,     0,     0,
       0,    38,    39,  1376,    41,    42,    43,   447,   447,     0,
      46,     0,     0,     0,     0,     0,     0,  1389,     0,     0,
       0,     0,  1395,     0,     0,     0,  1367,     0,     0,     0,
       0,     0,     0,     0,     0,  1401,  1402,     0,     0,     0,
       0,     0,  1407,  1408,    67,    68,    69,  1410,     0,   447,
     447,   447,     0,     0,     0,  1417,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   446,   446,  1429,     0,  1430,
       0,     0,     0,     0,   901,   447,     0,     0,     0,     0,
       0,  1447,   805,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,     7,     8,     0,   446,     0,     0,
    1462,     0,     0,     0,     0,  1464,  1465,  1466,  1467,     0,
       0,     0,  1655,   447,     0,     0,     0,     0,  1475,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1485,     0,
       0,     0,     0,     0,     0,   955,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1496,  1497,     0,     0,     0,
       0,     0,     0,  1503,   648,    24,    25,   649,    27,    28,
     650,    30,   651,    32,     0,    33,     0,     0,     0,     0,
      38,    39,     0,    41,    42,    43,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1522,
       0,     0,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   447,  1536,   447,   549,
     424,     0,     0,    67,    68,    69,     0,     0,     0,     0,
     805,   935,     0,     0,  1548,     0,  1549,     0,     0,   446,
       0,     0,     0,     0,     0,     0,  1556,     0,     0,     0,
       0,  1047,     0,     0,     0,     0,     0,  1055,     0,     0,
    1561,     0,     0,     0,     0,  1565,     0,     0,     0,     0,
       0,     0,     0,     0,  1489,   447,     0,     0,     0,     0,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
    1590,  1726,  1593,  1067,  1596,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   446,     0,     0,     0,  1609,  1610,
    1611,  1612,  1613,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,     0,     0,     0,     0,  1624,  1625,   447,
       0,   447,  1627,   447,  1519,   447,     0,     0,     0,     0,
     447,     0,  1631,   447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1642,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1116,  1117,     0,  1119,     0,
    1122,  1123,     0,     0,  1126,  1127,     0,     0,     0,     0,
       0,     0,     0,  1667,     0,     0,     0,     0,  1395,     0,
       0,     0,     0,     0,     0,  1675,   447,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,  1686,
       0,  1551,  1690,   424,     0,  1694,     0,     0,     0,  1697,
       0,     0,     0,   446,     0,   446,  1704,  1705,  1706,  1707,
       0,     0,   447,   447,   447,   447,  1711,     0,     0,  1713,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,  1207,  1208,  1209,     0,     0,     0,     0,
       0,     0,     0,     0,  1217,     0,     0,     0,     0,  1741,
       0,     0,     0,     0,     0,     0,     0,     0,   447,     0,
       0,     0,     0,     0,   446,     0,  1757,  1758,  1759,  1760,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,  1266,     0,     0,
       0,     0,  1786,  1787,     0,     0,     0,  1665,     0,     0,
       0,     0,  1795,  1796,  1797,  1798,  1285,     0,     0,     0,
       0,     0,  1291,     0,     0,     0,     0,  1724,  1296,     0,
    1298,  1299,     0,     0,     0,  1302,  1303,     0,  1304,     0,
    1305,     0,  1306,     0,  1307,  1308,  1309,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,  1328,     0,     0,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1339,     0,     0,
       0,  1343,     0,     0,     0,   109,   110,   111,     0,     0,
       0,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   554,     0,     0,   148,   149,   150,     0,     0,
     151,     0,   152,   153,   154,     0,     0,     0,     0,     0,
     155,   156,     0,     0,     0,   815,     0,     0,     0,  1387,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1399,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,   447,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,   157,     0,     0,
     424,     0,     0,   158,   159,   160,   161,  1434,  1266,  1435,
       0,   162,   163,   164,   165,   166,   167,     0,    88,   168,
       0,     0,     0,     0,     0,  1468,     0,     0,     0,     0,
       0,     0,  1477,   169,   170,     0,  1478,     0,   171,     0,
    1482,     0,     0,   172,     0,   173,     0,   174,   175,     0,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
    1498,     0,     0,     0,     0,     0,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   693,   422,   423,
       0,  1266,     0,     0,   424,     0,     0,   447,   447,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,     0,
       0,     0,     0,     0,     0,   447,     0,  1533,     0,   447,
       0,     0,   109,   282,     0,     0,     0,     0,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   284,     0,  1134,     0,     0,
       0,     0,     0,     0,   143,   144,   145,  1266,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   154,     0,  1266,     0,     0,     0,   155,     0,     0,
       0,   285,     0,     0,   286,     0,     0,   287,     0,   288,
       0,     0,  1602,     0,     0,     0,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,   550,     0,     0,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,  1635,
       0,   447,   424,     0,     0,     0,     0,     0,   447,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1652,     0,
     158,     0,     0,   161,     0,     0,   902,     0,   162,   163,
     164,   165,   166,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   447,  1032,     0,     0,     0,
     501,  1454,     0,     0,     0,   171,     0,     0,     0,     0,
     503,     0,     0,     0,     0,   175,   447,   249,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   282,     0,     0,     0,     0,   112,   113,   114,
       0,  1266,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   284,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     154,     0,     0,     0,     0,     0,   155,     0,     0,     0,
     285,     0,     0,   286,     0,     0,   287,     0,   288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     289,     0,     0,     0,     0,     0,     0,    48,    49,    50,
      51,    52,  1266,     0,     0,   447,    56,   447,     0,    59,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,  1212,     0,     0,     0,   424,   158,
       0,     0,   161,     0,     0,     0,     0,   162,   163,   164,
     165,   166,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   447,     0,     0,   169,
     445,     0,     0,     0,   171,     0,     0,     0,     0,   291,
       0,     0,     0,     0,   175,     0,     0,   552,   109,   282,
     111,     0,     0,     0,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   284,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,     0,   148,   149,
     150,     0,     0,   151,     0,   152,   153,   154,     0,     0,
       0,     0,     0,   155,   156,     0,     0,   285,     0,     0,
     286,     0,     0,   287,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,   158,   159,   160,   161,
       0,     0,     0,   579,   162,   163,   164,   165,   166,   167,
       0,    88,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   290,     0,     0,
       0,   171,     0,     0,     0,     0,   291,     0,   109,   282,
     111,   175,     0,   292,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   284,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,     0,   148,   149,
     150,     7,     8,   151,     0,   152,   153,   154,     0,     0,
       0,     0,     0,   155,   156,     0,     0,   285,     0,     0,
     286,     0,     0,   287,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,     0,     0,
       0,   648,    24,    25,   649,    27,    28,   650,    30,   651,
      32,     0,    33,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,   160,   161,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,    88,   168,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,   169,   290,     0,     0,
       0,   171,     0,     0,     0,     0,   291,     0,   109,   323,
     111,   175,     0,  1481,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,     0,   148,   149,
     150,     0,     0,   151,     0,   152,   153,   154,     0,   109,
     323,   111,     0,   155,   156,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,     0,   148,
     149,   150,     0,     0,   151,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,   156,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,   158,   159,   160,   161,
       0,  1469,     0,  1470,   162,   163,   164,   165,   166,   167,
       0,    88,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,     0,     0,
       0,   171,     0,     0,     0,     0,   291,     0,     0,     0,
       0,   175,     0,  1274,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   159,   160,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,    88,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,     0,
       0,     0,   171,     0,     0,     0,     0,   291,     0,   109,
     323,   111,   175,     0,  1474,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,     0,     0,     0,   148,
     149,   150,     0,     0,   151,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   111,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1588,     0,  1589,     0,     0,     0,     0,
       0,   137,   138,   139,   140,   141,   142,     0,     0,     0,
     146,     0,     0,     0,     0,   148,   149,   150,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,   158,   159,   160,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,     0,    88,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,     0,
       0,     0,   171,     0,     0,     0,     0,   291,     0,   109,
     282,   283,   175,     0,  1484,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,   159,   160,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,   167,     0,    88,   168,
       0,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,   432,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   146,     0,     0,     0,     0,   148,   149,   150,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   290,     0,
       0,   424,   171,   800,     0,     0,     0,   291,   745,   109,
     282,  1337,   175,     0,   292,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,   159,   160,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,   167,     0,    88,
     168,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,   317,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   146,     0,     0,     0,     0,   148,   149,   150,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   290,     0,
       0,   424,   171,     0,     0,     0,     0,   291,   682,   109,
     282,     0,   175,     0,  1338,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,   159,   160,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,   167,     0,     0,
     168,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,   899,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   290,     0,
       0,   424,   171,     0,     0,     0,     0,   291,   745,   109,
     282,     0,   175,     0,   292,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,   950,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   445,     0,
       0,   424,   171,     0,     0,     0,     0,   291,   746,   109,
     282,     0,   175,     0,   548,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1003,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   445,     0,
       0,   424,   171,     0,     0,     0,     0,   291,   812,   109,
     282,     0,   175,     0,   803,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1023,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   290,     0,
       0,   424,   171,     0,     0,     0,     0,   291,   847,   109,
     282,     0,   175,     0,  1342,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   284,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   153,   154,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   285,     0,
       0,   286,     0,     0,   287,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1053,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   501,  1454,     0,
       0,   424,   171,     0,     0,     0,     0,   503,   855,   109,
     323,     0,   175,     0,   249,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   323,   152,   153,   154,     0,
     112,   113,   114,     0,   155,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,   154,     0,     0,     0,     0,     0,   155,
       0,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,     0,     0,     0,     0,     0,     0,   158,  1157,     0,
     161,     0,     0,     0,     0,   162,   163,   164,   165,   166,
       0,     0,    88,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   169,   170,     0,
       0,   424,   171,     0,     0,     0,     0,   291,     0,     0,
    1432,     0,   175,     0,   481,     0,     0,     0,     0,     0,
       0,     0,   158,     0,     0,   161,     0,     0,     0,     0,
     162,   163,   164,   165,   166,     0,     0,    88,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   501,   502,     0,     0,   424,   171,     0,     0,
       0,     0,   503,   856,   109,   323,   111,   175,     0,   249,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,     0,     0,     0,   148,   149,   150,     0,     0,   151,
       0,   152,   153,   154,     0,     0,     0,     0,     0,   155,
     156,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,     0,     0,     0,     0,     0,     0,     0,  1451,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,     0,
       0,     0,     0,     0,     0,     0,  1506,     0,     0,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,     0,
       0,     0,   158,   159,   160,   161,  1507,     0,     0,     0,
     162,   163,   164,   165,   166,   167,     0,    88,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,     0,     0,     0,   171,   109,   282,
       0,     0,   291,     0,   112,   113,   114,   175,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   284,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   145,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   153,   154,     0,     0,
       0,     0,     0,   155,     0,     0,     0,   285,     0,     0,
     286,     0,     0,   287,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,     0,     0,     0,
       0,     0,     0,     0,  1508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,     0,     0,   161,
       0,     0,     0,     0,   162,   163,   164,   165,   166,     0,
       0,    88,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   169,   445,     0,     0,
     424,   171,   109,   323,     0,     0,   291,   857,   112,   113,
     114,   175,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   154,     0,     0,     0,     0,     0,   155,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1509,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,  1510,     0,     0,     0,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,     0,     0,     0,
     158,    -4,     1,   161,  1542,    -4,     0,     0,   162,   163,
     164,   165,   166,    -4,    -4,    88,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     169,   170,     0,     0,   424,   171,     0,     0,    -4,    -4,
     291,     0,     0,  1604,     0,   175,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,     0,
      -4,     0,     0,     0,    -4,    -4,     0,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,     0,    -4,     6,     0,     0,
       0,    -4,    -4,    -4,    -4,     7,     8,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       9,    10,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,    63,    64,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    66,    67,    68,    69,     0,     0,    70,
       0,    71,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,    87,    88,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,  1614,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1615,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,  1643,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,  1646,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,  1649,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,  1676,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1683,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,  1718,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,  1720,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,  1722,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,  1740,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1766,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,  1804,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,  1805,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,  1809,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,  1810,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,  1811,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,  1812,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
     738,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,     0,     0,     0,     0,     0,     0,  1518,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,   868,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,   985,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,   986,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,   987,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1018,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1109,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1155,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1156,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1211,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1350,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1351,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1352,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1353,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1390,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1391,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1398,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1543,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1544,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1545,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1546,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1562,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1563,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1567,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1661,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1662,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1663,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1664,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1671,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1674,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1714,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1731,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1732,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1733,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,  1734,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,  1777,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,  1778,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,  1779,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,  1780,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,   405,     0,   406,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,     0,
       0,   640,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,   817,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,     0,     0,   826,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
     834,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,     0,     0,   915,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,     0,     0,  1011,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,     0,     0,  1012,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
       0,     0,  1016,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,     0,     0,     0,  1017,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,     0,     0,  1019,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,     0,
       0,  1056,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,     0,     0,  1104,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,     0,     0,  1347,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,     0,     0,
    1381,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,     0,     0,  1531,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,   639,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,   692,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,   696,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,   697,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,   699,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,   701,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
     702,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,   705,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,   706,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,     0,   800,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,   808,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,   809,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,   810,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,   816,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,   825,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,   833,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
     914,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,   939,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,   944,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,     0,   949,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,   952,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,   953,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,   959,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,   968,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,   969,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,   970,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
    1002,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424,
       0,  1004,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,     0,     0,     0,     0,
     424,     0,  1005,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,     0,
       0,   424,     0,  1006,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,     0,     0,
       0,     0,   424,     0,  1010,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,     0,
       0,     0,     0,   424,     0,  1244,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
       0,     0,     0,     0,   424,     0,  1433,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,     0,     0,     0,     0,   424,     0,  1450,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,     0,     0,     0,     0,   424,     0,  1473,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,     0,     0,     0,     0,   424,     0,  1670,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   424,     0,
    1738,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,     0,     0,     0,   424
};

static const yytype_int16 yycheck[] =
{
       3,   369,     3,   371,   242,   257,  1340,     4,     4,   495,
     496,   379,  1001,     5,   396,     6,     6,   269,     4,     4,
       4,     4,   997,     5,     4,     6,   408,     6,     4,     4,
     187,   188,     5,     4,     6,     4,     6,     4,     4,    13,
       5,   198,   108,     5,     5,     5,     5,     5,     5,   191,
       6,     6,    72,     6,    57,    75,   198,     6,    78,    78,
       7,     4,    65,     4,     4,     4,     6,     0,   320,     6,
     322,   181,   182,   191,   181,   182,    79,     6,     6,  1413,
       6,   181,   182,     7,    95,   181,   182,   197,   191,   199,
     197,   192,   199,   191,     6,   106,   197,   197,     3,   199,
     198,     6,   198,   114,   115,   116,     6,    79,    80,   120,
     121,   122,   123,   181,   182,     7,   181,   182,   192,    99,
     100,   101,   102,   197,   187,   188,   187,   188,   108,   197,
       7,   111,    72,    72,   199,   198,     4,    76,   181,   182,
     126,   127,   128,   129,     6,   187,   188,   139,   145,    88,
     181,   182,    57,   181,   182,   198,   198,   139,     6,   192,
     191,   181,   182,   148,   197,  1499,   139,   198,   124,   166,
     198,   191,   175,   191,    79,   176,   191,     6,   198,   139,
     198,  1515,   166,   198,   187,   188,   191,   124,   199,   179,
     181,   182,   195,   136,   137,   191,   124,   193,   179,   195,
     203,   198,   205,  1178,   200,   587,   198,   210,   187,   188,
     193,   214,   124,   199,   217,   191,   191,   200,   221,   222,
     223,   224,   198,   198,   227,   228,   229,   198,   198,   198,
     202,   198,   198,   198,   486,   487,   198,   198,   241,   198,
     198,   198,   191,   198,   168,   169,   170,   171,   195,   198,
     191,     6,   181,   182,   506,   181,   182,   639,   640,     6,
     263,   264,   265,   187,   188,    82,     4,     5,   136,   137,
     175,   195,     7,   193,   277,   278,   168,   169,   170,   171,
     187,   188,   187,   188,   181,   182,    78,   290,   195,   292,
     195,   168,   169,   170,   171,   187,   188,   191,   203,   193,
     197,    39,    40,    41,    42,    43,    44,    78,   136,    80,
      48,   193,   181,   182,   566,    53,    54,    55,   181,   182,
      58,   149,   150,   326,   191,   328,   329,   579,   197,    78,
     396,    69,   205,    95,   197,   181,   182,   210,   341,  1673,
       7,   214,    75,    75,   106,    78,    78,   326,   221,   181,
     182,   197,   114,   115,   116,   191,   191,   193,   120,   121,
     122,   123,   334,     7,   200,   197,   369,   370,   371,   372,
     373,   374,   375,   376,   377,    75,   379,   380,    78,   191,
      80,   384,   385,   386,   387,   388,    72,   390,   191,    75,
       8,   370,    78,   372,   373,   374,   194,   376,   377,   197,
     191,   380,   181,   182,   407,   384,   385,   386,   387,   191,
     382,   181,   182,   194,   152,   153,   197,   389,   197,   192,
      95,   326,     8,   191,   197,   193,   164,   197,   166,   167,
    1764,   106,   200,   168,   169,   170,   171,   199,     6,   114,
     115,   116,   445,   825,   826,   120,   121,   122,   123,   187,
     188,    78,   187,   188,   181,   182,   192,   195,   194,   198,
     181,   182,   198,     7,   369,   370,   371,   372,   373,   374,
     197,   376,   377,    78,   379,   380,   197,   480,   481,   384,
     385,   386,   387,   388,   192,   390,   194,     6,     7,   741,
     198,   222,   223,   224,   495,   496,   227,   228,   229,     6,
       7,   473,   474,   475,   476,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   522,
     523,   524,    80,   190,   168,   169,   170,   171,   594,   181,
     182,   534,   263,   264,   407,   181,   182,  1526,   191,  1528,
     191,  1530,   193,   187,   188,   548,   277,   278,   197,   200,
     199,   197,   555,    75,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   198,   181,
     182,   192,   190,   639,   640,   197,   197,   199,   960,     8,
     962,   199,   964,   586,   966,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     181,   182,   181,   182,   190,   181,   182,   480,   481,   197,
     197,   199,   199,   199,   181,   182,   197,  1592,   197,     4,
    1595,   197,    75,  1598,   168,   169,   170,   171,   198,   534,
     197,    78,   181,   182,    75,   192,    95,   194,    78,    49,
      50,   198,    52,   187,   188,   191,     4,   106,   197,   522,
     523,   524,     4,   656,   892,   114,   115,   116,   181,   182,
     192,   120,   121,   122,   123,   197,   193,  1656,   195,   641,
       4,   181,   182,   200,   197,   548,   679,   191,   681,    99,
     100,   684,   181,   182,   687,   105,   689,   197,   181,   182,
     693,   694,   181,   182,   192,  1077,   194,   191,   197,   193,
     198,   195,   192,   191,   197,   684,   200,   197,   197,    72,
     689,  1093,    75,   586,   717,    78,   782,    80,   191,   691,
     193,    75,   195,  1698,    78,   198,    80,   200,  1717,   191,
    1719,    72,  1721,   193,    75,   738,   192,    78,  1727,    80,
     199,   197,     6,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     6,   193,   825,
     826,   190,     7,   192,   183,   184,   185,   833,   834,  1744,
     191,   190,  1747,   191,   197,  1750,   199,   191,  1753,   684,
     783,  1770,   687,  1772,   689,  1774,    99,   100,   197,   792,
     199,   794,   105,   796,   192,   798,   194,   191,   191,   197,
     803,   191,    95,   806,   193,   192,   679,   194,   681,   192,
     197,   194,   191,   106,  1789,   197,  1791,   199,  1793,   191,
     823,   114,   115,   116,   191,   191,   829,   120,   121,   122,
     123,   834,  1318,  1319,   191,   245,   246,   192,   197,   194,
     199,  1223,   197,   253,   191,   198,  1084,   257,   914,   915,
     181,   182,   183,   184,   185,   834,   859,     6,   197,   190,
     199,   864,   865,   866,   867,   738,   192,   192,   194,   194,
     198,   197,   197,   197,   877,   199,   197,   197,   199,   199,
     197,   191,   199,     6,    78,   864,    80,   866,   867,   197,
       6,   199,   895,   896,   897,   898,   868,    78,   877,    80,
     197,   197,   199,   199,   191,   197,   199,   199,   191,   197,
     783,   199,   197,   197,   199,   199,   197,   920,   199,   792,
     197,   794,   199,   796,   197,   798,   199,    12,    13,   834,
     803,   198,   191,   806,   937,   938,     8,   940,   191,   942,
     943,   920,   198,   946,   947,   191,     4,   333,   951,   197,
     197,   199,   199,  1019,   197,   197,   199,   199,   197,   864,
     199,   866,   867,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   877,   197,   191,   199,   190,     4,   197,     6,
     199,   197,   197,   199,   199,   191,   859,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   197,    83,   199,
     197,   191,   199,    88,    89,   191,    91,    92,    93,   191,
     198,  1077,    97,   198,   197,   920,   199,  1255,     6,   197,
     193,   199,   895,   896,   897,   898,   197,   197,   199,   199,
     198,   198,  1035,  1036,  1037,  1521,   197,   197,   199,   199,
     197,   191,   199,  1046,   191,   198,   131,   132,   133,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   197,   197,   199,   199,   190,   197,   197,
     199,   199,   197,   197,   199,   199,   191,   197,   951,   199,
     197,   191,   199,   493,   494,   197,   197,   199,   199,   191,
     197,   501,   199,   197,   191,   199,  1099,   200,     6,     6,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   199,  1118,  1484,   198,   190,     5,
     198,  1124,   198,   193,   193,   193,   193,  1130,     6,  1132,
    1133,     6,   195,   198,  1137,  1138,   139,  1140,  1110,  1142,
     200,  1144,     6,  1146,  1147,  1148,     6,   533,     6,     6,
     198,     6,   193,    39,    40,    41,    42,    43,    44,     4,
    1226,  1164,    48,   195,   190,     7,   199,    53,    54,    55,
     198,     7,    58,   559,   197,   197,  1179,     6,     6,     6,
    1183,     7,  1185,    69,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     7,   192,
       6,   198,   190,     7,     6,   136,     6,     4,     7,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
       6,   607,   608,   609,   610,   611,   612,   613,     6,     6,
    1233,   617,   618,   619,    50,    50,    95,    50,    50,   198,
     194,   192,   628,     6,     6,   192,   192,   106,   197,   635,
     192,   192,  1490,   197,  1233,   114,   115,   116,  1261,   197,
     646,   120,   121,   122,   123,  1237,   152,   153,  1271,   197,
     197,  1274,   192,   194,     6,  1247,     4,     4,   164,   198,
       6,   167,  1348,  1535,     6,     6,     6,     6,   139,     7,
       7,     7,  1271,     7,    95,   139,     7,     7,   139,     7,
       7,     4,  1274,   192,     6,   106,   197,  1310,  1311,   192,
     197,   192,  1185,   114,   115,   116,   192,  1318,  1319,   120,
     121,   122,   123,   197,   197,    95,   195,   199,  1233,   199,
       6,   194,     6,   198,   744,  1338,   106,  1340,     7,  1342,
     199,   751,  1314,     7,   114,   115,   116,   757,   198,   198,
     120,   121,   122,   123,  1357,    12,    13,     7,   198,   198,
     195,  1364,     6,     6,     6,  1368,  1271,     6,   193,  1372,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     7,     6,     6,   198,   190,  1392,
       6,  1363,   179,   191,     7,   191,     7,     7,   199,    80,
    1372,  1373,  1374,     7,     7,  1657,     7,     7,     6,     6,
    1413,     7,     7,     7,     6,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     7,    83,     7,     7,   199,
       4,    88,    89,     4,    91,    92,    93,  1310,  1311,   198,
      97,     6,   191,     7,     6,   198,  1449,     7,     7,     7,
       6,  1454,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     6,     6,     6,    78,
     190,  1474,     6,     4,   131,   132,   133,     4,  1481,   192,
       4,  1484,     4,     6,   199,     6,     6,    12,    13,     6,
       6,   197,   192,   192,   192,     7,  1499,   191,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,  1515,   197,   900,  1518,   190,   195,   198,     6,
    1521,     6,   195,   933,     6,     6,   198,   198,     6,     6,
     198,  1534,   198,    88,     6,   198,  1539,     6,     6,     5,
       4,     6,   199,     6,   198,   931,   932,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,   198,    83,     7,
     198,   198,   193,    88,    89,     6,    91,    92,    93,     6,
       6,     6,    97,    12,    13,   985,   986,   987,  1581,  1484,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     4,     6,   198,  1600,   190,    95,
       6,  1474,   135,     6,     6,   198,   131,   132,   133,   198,
     106,   197,     4,     6,     4,     6,     4,     6,   114,   115,
     116,    86,    87,     6,   120,   121,   122,   123,     6,     6,
       6,     6,     6,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     6,    83,  1518,     5,   198,  1620,    88,
      89,     6,    91,    92,    93,  1658,     6,  1660,    97,   139,
       6,     6,    95,     6,     6,     6,  1539,     6,  1054,     6,
    1673,     6,     6,   106,   199,  1061,  1062,  1063,  1064,  1065,
       6,   114,   115,   116,   197,  1071,  1072,   120,   121,   122,
     123,    95,   131,   132,   133,     6,     6,     6,     6,   192,
       6,     6,   106,   199,   169,   170,   171,   172,   173,     7,
     114,   115,   116,     6,   198,     6,   120,   121,   122,   123,
     195,   186,     5,    76,     6,   190,  1729,   198,     6,   199,
       6,   198,     7,     6,  1737,   134,  1708,   199,   198,   204,
     205,   206,   207,    95,   209,   210,   211,   212,   198,   214,
     215,   216,   198,   198,   106,     6,   221,   199,  1737,     6,
     199,  1764,   114,   115,   116,   137,   199,  1177,   120,   121,
     122,   123,     6,     6,   239,     6,     6,     6,  1781,     6,
    1783,     6,   198,   248,   249,  1658,     6,  1660,     6,     6,
       6,   198,   257,   198,     6,   199,     6,   198,     6,   199,
     198,     6,  1781,    95,  1783,    95,     6,     6,     6,  1195,
    1813,   198,     6,     6,   106,     6,     6,     6,     6,   199,
    1206,     6,   114,   115,   116,   290,   291,   292,   120,   121,
     122,   123,  1737,   198,  1813,     6,   198,   302,   303,   304,
     198,   306,     6,     6,   309,   310,     6,   199,   313,   198,
       6,     6,     6,     6,   198,     6,  1729,     6,   198,     6,
     198,     6,   198,     6,     6,   330,   331,   198,     6,     6,
       6,     6,  1282,     6,     6,     6,  1781,  1107,  1783,   344,
     345,  1623,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   441,  1504,  1117,   199,  1813,  1505,
    1320,     3,  1322,   378,  1324,     3,   381,   471,   383,  1517,
      -1,  1251,    -1,    -1,    -1,    -1,    -1,    -1,  1338,     6,
      -1,  1341,  1342,    -1,    -1,    -1,    -1,    -1,    -1,   404,
      -1,    -1,   407,    -1,    -1,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
      -1,    -1,   427,   428,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
     445,    -1,   190,    -1,    -1,  1371,   451,    -1,    -1,    -1,
      -1,   456,    -1,    -1,    -1,    -1,   461,   462,    -1,    -1,
      -1,    -1,   467,   468,    -1,    -1,    -1,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,   498,   499,   500,   501,   502,   503,    -1,
      -1,    -1,   507,   508,   509,   510,   511,    21,    22,    -1,
     515,    -1,   517,   518,    -1,    -1,    -1,   522,   523,   524,
      -1,    -1,   527,   528,   529,   530,   531,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   548,    -1,    -1,     6,    -1,    -1,   554,
     555,    -1,   557,   558,    -1,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,   577,   190,    -1,  1525,    -1,  1527,    -1,  1529,
     585,   586,    -1,    -1,    -1,    -1,   591,  1537,    12,    13,
    1540,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
    1580,    -1,   146,    -1,  1584,   149,    -1,   642,    -1,    -1,
      -1,   155,   156,    -1,    -1,    -1,    -1,   161,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    -1,    91,    92,    93,
      -1,   676,    -1,    97,   679,    -1,   681,   682,    -1,    -1,
      -1,    -1,    -1,  1633,    -1,   690,    -1,  1637,   693,   694,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   707,    -1,    -1,    -1,    -1,   131,   132,   133,
    1660,   716,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,
     745,   746,    -1,    -1,    -1,    -1,   751,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,   764,
      -1,    -1,   767,    -1,    -1,  1715,  1716,    -1,   282,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,   783,    -1,
      -1,    -1,    -1,    -1,    -1,   299,    -1,   792,    -1,   794,
      -1,   796,    -1,   798,    -1,    -1,    -1,    -1,   803,    -1,
      -1,   806,    -1,    -1,    -1,    -1,    -1,   812,    -1,   814,
     815,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,   847,    -1,    -1,    12,    13,    -1,    -1,    -1,
     855,   856,   857,    -1,   859,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   874,
     131,   132,   133,   190,    -1,   217,    -1,   882,    -1,    -1,
     885,    -1,    -1,    -1,    -1,   399,    -1,    -1,    -1,    -1,
     895,   896,   897,   898,    -1,    -1,    -1,   902,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,
      -1,    88,    89,   265,    91,    92,    93,    -1,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   951,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   961,    -1,   963,    -1,
     965,    -1,   967,    -1,   131,   132,   133,    -1,     6,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,    -1,    -1,    -1,    -1,   328,   329,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
    1015,    -1,    -1,  1018,    -1,    -1,    -1,  1022,    -1,  1024,
    1025,  1026,    -1,    -1,    -1,     6,    -1,  1032,    -1,    -1,
      -1,    -1,   199,   375,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1049,    -1,  1051,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,    -1,   292,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    95,    -1,    -1,    88,    89,
    1085,    91,    92,    93,    -1,    -1,   106,    97,    -1,    -1,
      -1,    -1,  1097,  1098,   114,   115,   116,    -1,    -1,    -1,
     120,   121,   122,   123,  1109,  1110,    -1,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,   131,   132,   133,    88,    89,    -1,    91,    92,    93,
      -1,    -1,    -1,    97,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,  1154,
    1155,  1156,   190,    -1,    -1,    -1,    -1,    -1,    -1,  1164,
      -1,  1166,    -1,    -1,    -1,    12,    13,   131,   132,   133,
      -1,    -1,  1177,    -1,   407,    -1,    -1,    -1,    -1,   199,
    1185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,  1211,  1212,  1213,   190,
      -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   199,    83,    -1,    -1,    -1,
      -1,    88,    89,  1248,    91,    92,    93,   480,   481,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,  1262,    -1,    -1,
      -1,    -1,  1267,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1280,  1281,    -1,    -1,    -1,
      -1,    -1,  1287,  1288,   131,   132,   133,  1292,    -1,   522,
     523,   524,    -1,    -1,    -1,  1300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1310,  1311,  1312,    -1,  1314,
      -1,    -1,    -1,    -1,   656,   548,    -1,    -1,    -1,    -1,
      -1,  1326,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1338,    12,    13,    -1,  1342,    -1,    -1,
    1345,    -1,    -1,    -1,    -1,  1350,  1351,  1352,  1353,    -1,
      -1,    -1,   199,   586,    -1,    -1,    -1,    -1,  1363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1373,    -1,
      -1,    -1,    -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1390,  1391,    -1,    -1,    -1,
      -1,    -1,    -1,  1398,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1434,
      -1,    -1,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   679,  1452,   681,  1454,
     190,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,
     693,   694,    -1,    -1,  1469,    -1,  1471,    -1,    -1,  1474,
      -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,
      -1,   823,    -1,    -1,    -1,    -1,    -1,   829,    -1,    -1,
    1495,    -1,    -1,    -1,    -1,  1500,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,   738,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,    -1,
    1525,   199,  1527,   865,  1529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1539,    -1,    -1,    -1,  1543,  1544,
    1545,  1546,  1547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     783,    -1,    -1,    -1,    -1,    -1,    -1,  1562,  1563,   792,
      -1,   794,  1567,   796,     6,   798,    -1,    -1,    -1,    -1,
     803,    -1,  1577,   806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1588,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   937,   938,    -1,   940,    -1,
     942,   943,    -1,    -1,   946,   947,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1618,    -1,    -1,    -1,    -1,  1623,    -1,
      -1,    -1,    -1,    -1,    -1,  1630,   859,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,  1644,
      -1,     6,  1647,   190,    -1,  1650,    -1,    -1,    -1,  1654,
      -1,    -1,    -1,  1658,    -1,  1660,  1661,  1662,  1663,  1664,
      -1,    -1,   895,   896,   897,   898,  1671,    -1,    -1,  1674,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,  1035,  1036,  1037,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,    -1,    -1,    -1,    -1,  1714,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   951,    -1,
      -1,    -1,    -1,    -1,  1729,    -1,  1731,  1732,  1733,  1734,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1099,    -1,    -1,
      -1,    -1,  1767,  1768,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,  1777,  1778,  1779,  1780,  1118,    -1,    -1,    -1,
      -1,    -1,  1124,    -1,    -1,    -1,    -1,     6,  1130,    -1,
    1132,  1133,    -1,    -1,    -1,  1137,  1138,    -1,  1140,    -1,
    1142,    -1,  1144,    -1,  1146,  1147,  1148,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,  1164,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,
      -1,  1183,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     8,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    -1,    -1,     8,    -1,    -1,    -1,  1261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1274,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,  1185,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,   145,    -1,    -1,
     190,    -1,    -1,   151,   152,   153,   154,   197,  1340,   199,
      -1,   159,   160,   161,   162,   163,   164,    -1,   166,   167,
      -1,    -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,
      -1,    -1,  1364,   181,   182,    -1,  1368,    -1,   186,    -1,
    1372,    -1,    -1,   191,    -1,   193,    -1,   195,   196,    -1,
     198,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1392,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,  1413,    -1,    -1,   190,    -1,    -1,  1310,  1311,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1338,    -1,  1449,    -1,  1342,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,  1499,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,  1515,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,
      -1,    -1,  1534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,    -1,
     111,  1454,    -1,    -1,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,  1581,
      -1,  1474,   190,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,    -1,
     151,    -1,    -1,   154,    -1,    -1,     8,    -1,   159,   160,
     161,   162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1518,     8,    -1,    -1,    -1,
     181,   182,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,  1539,   198,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,  1673,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,  1764,    -1,    -1,  1658,   108,  1660,    -1,   111,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     8,    -1,    -1,    -1,   190,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1729,    -1,    -1,   181,
     182,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,   199,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   108,    -1,    -1,   111,    -1,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,   151,   152,   153,   154,
      -1,    -1,    -1,   198,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,   191,    -1,     3,     4,
       5,   196,    -1,   198,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    12,    13,    58,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    92,    93,    -1,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,   191,    -1,     3,     4,
       5,   196,    -1,   198,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,     3,
       4,     5,    -1,    68,    69,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   151,   152,   153,   154,
      -1,   197,    -1,   199,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,    -1,
      -1,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,    -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,     3,
       4,     5,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,    -1,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,    -1,
      -1,    -1,   186,    -1,    -1,    -1,    -1,   191,    -1,     3,
       4,     5,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,   152,   153,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,   164,    -1,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,   192,    -1,    -1,    -1,   191,   197,     3,
       4,     5,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,   164,    -1,   166,
     167,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,   152,   153,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,   164,    -1,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,   197,     3,
       4,    -1,   196,    -1,   198,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    60,    61,    62,    -1,
       9,    10,    11,    -1,    68,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,   199,    -1,
     154,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,    -1,   166,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   181,   182,    -1,
      -1,   190,   186,    -1,    -1,    -1,    -1,   191,    -1,    -1,
     199,    -1,   196,    -1,   198,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,    -1,    -1,   166,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   181,   182,    -1,    -1,   190,   186,    -1,    -1,
      -1,    -1,   191,   197,     3,     4,     5,   196,    -1,   198,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    54,    55,    -1,    -1,    58,
      -1,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   199,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,    -1,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,    -1,    -1,    -1,   186,     3,     4,
      -1,    -1,   191,    -1,     9,    10,    11,   196,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,   108,    -1,    -1,   111,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
      -1,   166,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   181,   182,    -1,    -1,
     190,   186,     3,     4,    -1,    -1,   191,   197,     9,    10,
      11,   196,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
     151,     0,     1,   154,   199,     4,    -1,    -1,   159,   160,
     161,   162,   163,    12,    13,   166,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     181,   182,    -1,    -1,   190,   186,    -1,    -1,    37,    38,
     191,    -1,    -1,   199,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      59,    -1,    -1,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,   125,     4,    -1,    -1,
      -1,   130,   131,   132,   133,    12,    13,   136,    -1,   138,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
      37,    38,    -1,    -1,    -1,    -1,   165,   166,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,    -1,    -1,   136,
      -1,   138,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,   194,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,    -1,    -1,   194,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,   194,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,   194,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,
      -1,   194,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,   194,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,   194,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     194,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,   194,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,   192,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
     192,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,   192,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,   192,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,   192,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,   192,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
     192,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,   192,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,   192,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,   192,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,   192,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
     192,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,   192,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,   192,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,   190,    -1,   192,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,   192,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,   192,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
     192,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,   190
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   202,   203,     6,     0,     4,    12,    13,    37,
      38,    50,    51,    52,    56,    57,    59,    63,    64,    66,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   117,   118,   119,   125,   130,   131,   132,   133,
     136,   138,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   155,   156,   157,   158,   165,   166,   204,
     206,   207,   227,   244,   245,   248,   249,   250,   251,   252,
     253,   254,   255,   276,   277,   278,   279,   297,   298,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    53,    54,
      55,    58,    60,    61,    62,    68,    69,   145,   151,   152,
     153,   154,   159,   160,   161,   162,   163,   164,   167,   181,
     182,   186,   191,   193,   195,   196,   198,   200,   225,   280,
     281,   293,   294,   297,   298,    13,    78,   191,   191,     6,
     198,     6,     6,     6,     6,   191,     6,     6,   193,   193,
     191,   193,   225,   225,   191,   198,   191,   191,     4,   191,
     198,   191,   191,     4,   198,   191,   191,    82,    78,    78,
       6,   198,    72,    75,    78,    78,    78,    75,    78,    80,
      80,    72,    75,    78,    80,    75,    78,    80,    75,    78,
     191,    75,   136,   149,   150,   198,   181,   182,   191,   198,
     283,   284,   283,   198,    72,    75,    78,   198,   283,     4,
      72,    76,    88,    78,    80,    78,    75,     4,   145,   198,
     297,   298,     4,     6,    72,    75,    78,    75,    78,     4,
       4,     4,     4,     5,    36,    72,    75,    78,    80,    92,
     182,   191,   198,   245,   255,   280,   286,   287,   288,   297,
     298,     4,   191,   191,   191,     4,   198,   290,     4,   191,
     191,     6,     6,   193,     4,   294,   298,     4,   294,     5,
     198,     5,   198,     4,   280,   280,   193,     6,   191,   198,
     191,   193,   200,   225,     7,   168,   169,   170,   171,   187,
     188,   223,   224,     4,   191,   193,   195,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   191,   191,   191,   191,   191,   191,   225,   191,
     225,   225,   225,     7,   191,   191,   191,   225,   191,   191,
     193,   280,   280,   280,   280,   280,     4,   136,   137,   298,
       4,   245,   246,   247,   198,   192,   194,   198,   226,     6,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   190,   198,     6,   191,   193,   224,
       6,   280,     4,   293,   294,   298,   293,   280,   293,   296,
     229,   232,   294,   298,   280,   182,   280,   288,   289,   280,
     280,   191,   280,   289,   280,   280,   191,   289,   280,   280,
     286,   191,   198,   289,   287,   287,   287,   191,   191,   287,
     287,   287,   191,   191,   191,   191,   191,   191,   191,   191,
     198,   198,   280,     4,   286,   290,   198,   198,   283,   283,
     283,   280,   280,   181,   182,   198,   198,   283,   198,   198,
     198,   181,   182,   191,   247,   283,   198,   191,   198,   191,
     191,   191,   287,   287,   286,   191,     4,   193,   193,   247,
       6,     6,   198,   198,   198,   287,   287,   193,   193,   193,
     191,   193,   195,   225,   193,     5,   139,   198,     5,   139,
       5,   139,     5,   139,    72,    75,    78,    80,   198,   280,
     288,   280,   199,   289,     8,   183,     6,   191,   193,   225,
       6,   280,   280,   280,   195,   280,   198,   139,   280,   280,
     280,     6,     6,     6,   247,     6,   247,   193,     6,   198,
     293,   286,   286,   280,   280,   198,   198,   226,   294,   286,
       6,   193,   280,   280,     4,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   296,   293,   296,
     293,   293,   293,   286,   293,   293,   280,   296,   293,   280,
     294,   280,   293,   293,   293,   293,   298,   294,   298,   192,
     194,     7,   223,   224,   195,     7,   225,   199,    72,    75,
      78,    80,   244,   280,   289,     7,   223,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   208,   280,   280,     6,   193,   195,   192,   197,
     192,   197,   197,   192,   197,   194,   197,   228,   194,   228,
     197,   197,   192,   183,   197,   199,   192,   192,   280,   192,
     199,   192,   192,   280,   199,   192,   192,     7,   280,   280,
     199,     6,     6,     6,   280,   280,     7,     7,   273,   273,
     280,   238,   280,   294,   239,   280,   294,   240,   280,   294,
     241,   280,   294,   280,   280,   280,   289,   289,   198,   192,
       6,   198,   247,   247,   197,   197,   197,   283,   283,   246,
     246,   197,   280,   280,   280,   280,   259,   197,   247,   280,
     280,   280,   280,   280,     7,   274,     6,     7,   280,     6,
     280,   280,   199,   289,   289,   289,     6,     6,   280,   280,
     280,   280,     4,   198,   226,   298,    50,   280,    50,    50,
      50,     5,   198,     5,   198,     5,   198,     5,   198,   289,
     192,   199,   280,   198,   280,   288,   198,   226,   192,   192,
     192,   136,   197,   247,   198,     8,   192,   194,   199,   199,
     247,   194,   192,   197,   199,   192,   194,   280,   289,   223,
       6,     6,   280,   192,   194,   224,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   197,   226,   226,
     226,   226,   226,   226,   226,   197,   197,   197,   226,   197,
     226,   226,   192,   192,   197,   197,   197,   197,   197,   192,
     226,   282,   295,     6,   197,   192,   192,   197,   226,   192,
     192,   194,   223,   224,   195,   223,   224,   294,   280,     6,
       4,     4,   198,   291,   226,   198,   198,   198,   198,   199,
     199,   286,     8,     4,   126,   127,   128,   129,   199,   211,
     215,   218,   220,   221,   192,   194,   280,     4,     6,   179,
     205,   289,     6,   289,   280,     6,   293,     6,   298,     6,
     293,   280,   294,     7,   280,   288,   139,     7,     7,   192,
       7,   139,     7,     7,   192,   139,     7,     7,   280,   192,
     199,   198,   192,   192,   280,   286,     4,   272,     6,   192,
     192,   197,   192,   197,   192,   197,   192,   197,   192,   192,
     192,   199,   199,   289,   195,   247,   199,   199,   283,   280,
     280,   199,   199,   280,   283,   197,   197,   197,    95,   106,
     114,   115,   116,   120,   121,   122,   123,   269,   270,   283,
     199,   256,   192,   199,   192,   192,   192,   280,     6,   280,
     192,   194,   194,   199,   199,   199,   194,   194,   197,   194,
     289,   194,   198,   199,   198,   198,   198,   289,   289,   289,
     289,   199,     8,   289,   289,     7,     7,     7,   195,   280,
     199,   280,   280,     7,   195,   199,   198,   286,     6,   223,
     224,   223,   224,   199,   199,   286,   194,   224,   195,   224,
     293,   280,   280,   280,   280,   289,   293,   286,   293,   293,
     294,   234,   236,   280,   293,   280,     6,     4,   136,   137,
     280,     6,     6,     6,     7,   193,   290,   292,     6,   289,
     289,   289,   289,   226,     6,   280,   212,   191,   191,   198,
     222,     6,   224,   224,   194,   179,   293,   192,   192,   197,
       7,   226,   226,   283,    78,    80,   286,   286,     7,   286,
      78,    80,   286,   286,     7,    80,   286,   286,     6,     7,
       7,   289,     7,     7,    95,   271,     6,     7,   223,   280,
     223,   280,   223,   280,   223,   280,     7,     7,     7,     7,
       7,   199,     4,   199,   197,   197,   197,   199,   199,   283,
     283,   283,     4,     6,   198,     6,   191,     6,   124,     6,
     124,     6,   124,     6,   124,   199,   270,   197,   269,     7,
       6,     7,     7,     7,     6,   198,     6,     6,     6,    78,
     280,     6,     6,   280,   195,   199,   280,   280,   280,   280,
     199,   199,   199,   199,   280,   199,   199,   286,   286,   286,
       4,   197,     8,     8,   192,     4,     4,   286,   199,   280,
       6,   280,     6,   226,     6,     6,     4,     6,   226,   226,
     226,   226,   226,   197,   192,   192,   192,   197,   197,   226,
     235,   197,   226,   237,   192,   192,     6,     7,   223,   224,
     195,     7,     6,   290,   280,   197,   199,   199,   199,   199,
     199,   223,   191,   280,   280,   285,   286,   198,   195,     6,
       6,   205,     6,   280,   198,   280,   294,     6,     6,     6,
     198,   198,    88,   243,   243,   286,     6,   198,   198,     6,
       6,   286,   198,     6,     6,     5,   286,   199,   286,   286,
       4,     6,   286,   286,   286,   286,   286,   286,   286,   286,
     198,   198,     7,     6,     7,   280,   280,   280,   198,   198,
     197,   199,   197,   199,   197,   199,   193,   280,   286,   280,
       6,     6,     6,     6,   280,   283,   199,     5,   198,   286,
     198,   198,   198,   286,   289,   198,     6,   194,     4,   226,
     197,   197,   197,   197,   226,     6,     6,   135,   280,   280,
     280,     6,     6,     7,   197,     6,     6,     6,   223,   224,
     293,   294,     4,     4,   148,   294,   280,     6,     4,   291,
       6,   194,   290,     6,     6,     6,     6,   286,   209,   280,
     197,   197,   197,   199,   210,   280,     4,   293,   197,   286,
     294,   280,   280,   283,     6,     6,     6,   280,   280,     6,
     280,     5,     6,   198,     6,   139,   242,   280,     6,     6,
       6,     6,     6,     6,     4,     6,     6,   289,   289,   280,
     280,   294,   199,   192,   197,   199,   246,   246,   283,     6,
     260,   283,     6,   261,   283,     6,   262,   280,   199,   197,
     192,   199,   197,     6,   182,   283,     6,   285,   283,   283,
       6,   199,   280,     6,   280,   280,   280,   280,   286,   197,
     199,     8,   199,   192,   198,   280,   294,   286,   286,   192,
     226,   198,   286,   294,   198,   280,   294,   294,     6,     6,
       7,     6,   195,     6,   192,   197,   280,   280,   286,   198,
     197,   199,     6,   280,   230,   231,   199,   199,   199,   199,
     199,     5,   285,    76,     6,   198,   199,   199,   198,     6,
       6,   198,   280,   199,   199,   197,   198,   197,   198,   197,
     198,   194,     6,   286,     7,   198,   280,   197,   199,   197,
     197,     6,   199,   197,   197,   197,   197,   134,   280,   280,
     289,     6,     6,   199,     6,   233,   280,   296,   290,   137,
     213,   280,   197,   197,   285,   280,     6,   197,   234,   236,
       6,     6,     6,     6,     6,     6,   199,   198,   285,    99,
     100,   105,   275,    99,   100,   275,   289,   246,   197,   199,
     280,   283,   269,   280,   283,   269,   280,   283,   269,     6,
     197,   199,   286,   247,   199,   283,     6,   289,   283,   280,
     280,   280,   280,   280,   199,   199,   199,     6,   197,   199,
       7,   199,     6,   198,   280,   280,   199,   280,   199,   199,
     198,   280,   199,   198,   283,   286,     6,   198,   283,     6,
     199,   199,   280,   199,   197,   199,   199,   197,   199,   199,
     197,   199,   286,     6,    95,   199,   257,   198,   197,   199,
     197,   197,   197,   197,   197,     6,     6,   280,   294,   210,
     192,   197,     6,   198,   197,   280,   199,     6,   283,     6,
     283,     6,     6,   199,     6,   263,   280,     6,     6,   264,
     280,     6,     6,   265,   280,     6,   199,   280,   269,   247,
     289,     6,   283,   289,   280,   280,   280,   280,     7,   199,
     216,   280,   285,   280,   197,   197,   197,   198,   199,   198,
     199,   198,   199,     6,     6,   199,   199,   258,   199,   197,
     199,   197,   197,   197,   197,   294,     6,   198,   192,   199,
     199,   280,   283,   283,   269,     6,   266,   269,     6,   267,
     269,     6,   268,   269,     6,   289,     6,   280,   280,   280,
     280,   214,   293,   219,   198,     6,   199,   197,   197,   199,
     198,   199,   198,   199,   198,   199,   199,   197,   197,   197,
     197,   197,   199,   198,   285,     6,   280,   280,     6,   269,
       6,   269,     6,   269,     6,   280,   280,   280,   280,   293,
       6,   217,   293,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   197,   199,     6,     6,     6,     6,     6,
       6,   293,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   201,   202,   202,   203,   203,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   206,   206,   206,   206,   206,
     207,   207,   207,   207,   208,   208,   208,   208,   208,   208,
     209,   209,   210,   210,   212,   213,   211,   214,   214,   216,
     215,   217,   217,   219,   218,   220,   220,   222,   221,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   228,   228,   229,
     229,   229,   230,   229,   229,   231,   229,   232,   232,   233,
     233,   234,   234,   235,   235,   235,   236,   236,   237,   237,
     237,   237,   238,   238,   238,   239,   239,   239,   240,   240,
     240,   241,   241,   241,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   246,   247,   247,   247,
     247,   247,   247,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   249,   249,   249,   249,   250,   250,   251,
     252,   252,   252,   252,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   255,   255,
     255,   256,   255,   257,   255,   258,   255,   259,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   260,   255,
     261,   255,   262,   255,   263,   255,   264,   255,   265,   255,
     266,   255,   267,   255,   268,   255,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   271,   271,   272,   272,   273,   273,   274,
     274,   275,   275,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   277,
     277,   277,   278,   278,   278,   279,   279,   279,   279,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   282,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   285,   285,   286,   286,   286,
     286,   286,   286,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   289,   289,   289,   289,   290,   290,   290,
     290,   291,   291,   292,   292,   293,   293,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   295,   294,   296,
     296,   297,   297,   298,   298,   298
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
       1,     2,     2,     1,     3,     3,     4,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     8,
       8,     8,    12,    12,    12,    14,    14,    14,     0,    12,
       0,    12,     0,    12,     0,    16,     0,    16,     0,    16,
       0,    18,     0,    18,     0,    18,     1,     2,     5,     7,
       9,     2,     2,     2,     3,     2,     3,     2,     3,     2,
       3,     9,     6,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     7,     6,     8,     5,     3,     7,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
      10,    10,    10,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     4,     1,     4,     4,     4,     4,     4,
       4,     4,     2,     5,     5,     5,     5,     3,     6,     4,
       7,     6,     6,     6,     6,     4,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     1,     2,     3,     3,     5,     4,
       2,     2,     2,     2,     3,     3,     3,     3,     5,     5,
       5,     5,    16,    16,    16,    16,     1,     1,     3,     3,
       4,     6,     6,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     3,     6,     1,
       4,     1,     1,     1,     4,     6,     4,     4,     4,     4,
       8,     4,     8,     4,     6,     4,     1,     0,     6,     1,
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
#line 193 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 4293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 204 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4311 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4323 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4341 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4353 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4371 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4389 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4423 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 245 "Gmsh.y" /* yacc.c:1646  */
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
#line 4441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 259 "Gmsh.y" /* yacc.c:1646  */
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
#line 4458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 272 "Gmsh.y" /* yacc.c:1646  */
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
#line 4475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 285 "Gmsh.y" /* yacc.c:1646  */
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
#line 4502 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "Gmsh.y" /* yacc.c:1646  */
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
#line 4520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 327 "Gmsh.y" /* yacc.c:1646  */
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
#line 4537 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 340 "Gmsh.y" /* yacc.c:1646  */
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
#line 4554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 353 "Gmsh.y" /* yacc.c:1646  */
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
#line 4573 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 371 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4583 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 385 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4589 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4601 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4607 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 399 "Gmsh.y" /* yacc.c:1646  */
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
#line 4715 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 503 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 4729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 513 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 522 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4750 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 529 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 539 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 4774 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 548 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 557 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 564 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 574 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 4818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 592 "Gmsh.y" /* yacc.c:1646  */
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
#line 4848 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 611 "Gmsh.y" /* yacc.c:1646  */
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
#line 4868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 630 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4878 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 668 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 4960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 4970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 679 "Gmsh.y" /* yacc.c:1646  */
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
#line 5034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 739 "Gmsh.y" /* yacc.c:1646  */
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
#line 5067 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 768 "Gmsh.y" /* yacc.c:1646  */
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
#line 5100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 797 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 802 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 807 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5127 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 812 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 817 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 824 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5158 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 831 "Gmsh.y" /* yacc.c:1646  */
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
#line 5177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 846 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5186 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 851 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5195 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 856 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 861 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5213 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 866 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 875 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5233 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 881 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5243 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 890 "Gmsh.y" /* yacc.c:1646  */
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
#line 5265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 908 "Gmsh.y" /* yacc.c:1646  */
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
#line 5287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 926 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 5300 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 935 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 5313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 947 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 952 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 960 "Gmsh.y" /* yacc.c:1646  */
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
#line 5355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 980 "Gmsh.y" /* yacc.c:1646  */
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
#line 5379 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1003 "Gmsh.y" /* yacc.c:1646  */
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
#line 5394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1014 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 5406 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1022 "Gmsh.y" /* yacc.c:1646  */
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
#line 5432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1044 "Gmsh.y" /* yacc.c:1646  */
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
#line 5459 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1067 "Gmsh.y" /* yacc.c:1646  */
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
#line 5489 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1093 "Gmsh.y" /* yacc.c:1646  */
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
#line 5511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1114 "Gmsh.y" /* yacc.c:1646  */
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
#line 5527 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1126 "Gmsh.y" /* yacc.c:1646  */
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
#line 5543 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1144 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 5556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1153 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 5569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1162 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1164 "Gmsh.y" /* yacc.c:1646  */
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
#line 5595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1180 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 5608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1189 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5614 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1191 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = val;
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 5628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1205 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1213 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5648 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1219 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1231 "Gmsh.y" /* yacc.c:1646  */
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
#line 5672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1242 "Gmsh.y" /* yacc.c:1646  */
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
#line 5690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1257 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5702 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1273 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1281 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 5725 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1290 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5736 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1298 "Gmsh.y" /* yacc.c:1646  */
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
#line 5753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1326 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5780 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1334 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5788 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5798 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1344 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1352 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5825 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1362 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1370 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5869 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1392 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)(yyvsp[-1].d));
      if(!v)
	yymsg(0, "Unknown point %d", (int)(yyvsp[-1].d));
      else{
	List_Add((yyval.l), &v);
      }
    }
#line 5883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1404 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5899 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1418 "Gmsh.y" /* yacc.c:1646  */
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
#line 5926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1441 "Gmsh.y" /* yacc.c:1646  */
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
#line 5962 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1473 "Gmsh.y" /* yacc.c:1646  */
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
#line 5986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1496 "Gmsh.y" /* yacc.c:1646  */
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
#line 6008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1514 "Gmsh.y" /* yacc.c:1646  */
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
#line 6033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1535 "Gmsh.y" /* yacc.c:1646  */
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
#line 6055 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1553 "Gmsh.y" /* yacc.c:1646  */
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
#line 6089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1583 "Gmsh.y" /* yacc.c:1646  */
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
#line 6123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1613 "Gmsh.y" /* yacc.c:1646  */
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
#line 6145 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1631 "Gmsh.y" /* yacc.c:1646  */
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
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1650 "Gmsh.y" /* yacc.c:1646  */
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
#line 6197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1676 "Gmsh.y" /* yacc.c:1646  */
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
#line 6219 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1694 "Gmsh.y" /* yacc.c:1646  */
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
#line 6241 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1712 "Gmsh.y" /* yacc.c:1646  */
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
#line 6277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1747 "Gmsh.y" /* yacc.c:1646  */
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
#line 6299 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1765 "Gmsh.y" /* yacc.c:1646  */
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
#line 6342 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1804 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1810 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6362 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1816 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1823 "Gmsh.y" /* yacc.c:1646  */
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
#line 6402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1848 "Gmsh.y" /* yacc.c:1646  */
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
#line 6431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1873 "Gmsh.y" /* yacc.c:1646  */
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
#line 6452 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1890 "Gmsh.y" /* yacc.c:1646  */
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
#line 6475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1910 "Gmsh.y" /* yacc.c:1646  */
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
#line 6512 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1943 "Gmsh.y" /* yacc.c:1646  */
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
#line 6548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1979 "Gmsh.y" /* yacc.c:1646  */
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
#line 6570 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1997 "Gmsh.y" /* yacc.c:1646  */
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
#line 6591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 2014 "Gmsh.y" /* yacc.c:1646  */
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
#line 6611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2030 "Gmsh.y" /* yacc.c:1646  */
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
#line 6647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2067 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2072 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6665 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2077 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2082 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2087 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2092 "Gmsh.y" /* yacc.c:1646  */
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
#line 6719 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2115 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2121 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt((yyvsp[-2].l));
      List_Delete((yyvsp[-2].l));
      SplitCurve((int)(yyvsp[-5].d), tmp, (yyval.l));
      List_Delete(tmp);
    }
#line 6741 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2132 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2137 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2145 "Gmsh.y" /* yacc.c:1646  */
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
#line 6796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2168 "Gmsh.y" /* yacc.c:1646  */
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
#line 6823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2191 "Gmsh.y" /* yacc.c:1646  */
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
#line 6850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2214 "Gmsh.y" /* yacc.c:1646  */
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
#line 6877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2242 "Gmsh.y" /* yacc.c:1646  */
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
#line 6902 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2263 "Gmsh.y" /* yacc.c:1646  */
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
#line 6932 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2290 "Gmsh.y" /* yacc.c:1646  */
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
#line 6956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2311 "Gmsh.y" /* yacc.c:1646  */
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
#line 6981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2332 "Gmsh.y" /* yacc.c:1646  */
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
#line 7005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2352 "Gmsh.y" /* yacc.c:1646  */
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
#line 7121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2464 "Gmsh.y" /* yacc.c:1646  */
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
#line 7144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2483 "Gmsh.y" /* yacc.c:1646  */
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
#line 7186 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2522 "Gmsh.y" /* yacc.c:1646  */
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
#line 7293 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2630 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7306 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2639 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2645 "Gmsh.y" /* yacc.c:1646  */
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
#line 7335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2660 "Gmsh.y" /* yacc.c:1646  */
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
#line 7367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2688 "Gmsh.y" /* yacc.c:1646  */
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
#line 7383 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2705 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2714 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, (yyvsp[-3].u), true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2728 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, (yyvsp[-3].d));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7422 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2742 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2748 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2754 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7455 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2763 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7468 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2772 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2781 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	Shape TheShape;
	List_Read((yyvsp[-1].l), i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 7494 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2795 "Gmsh.y" /* yacc.c:1646  */
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
#line 7554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2851 "Gmsh.y" /* yacc.c:1646  */
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
#line 7576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2869 "Gmsh.y" /* yacc.c:1646  */
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
#line 7597 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2886 "Gmsh.y" /* yacc.c:1646  */
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
#line 7616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2901 "Gmsh.y" /* yacc.c:1646  */
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
#line 7639 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2920 "Gmsh.y" /* yacc.c:1646  */
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
#line 7655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2932 "Gmsh.y" /* yacc.c:1646  */
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
#line 7683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2956 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2960 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2965 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7711 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2972 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2977 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2983 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2988 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 2994 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 7761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3002 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 3016 "Gmsh.y" /* yacc.c:1646  */
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
#line 7844 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 3070 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                CTX::instance()->mesh.secondOrderIncomplete,
                CTX::instance()->mesh.meshOnlyVisible);
#endif
    }
#line 7856 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 3083 "Gmsh.y" /* yacc.c:1646  */
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
#line 7877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 3100 "Gmsh.y" /* yacc.c:1646  */
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
#line 7898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3117 "Gmsh.y" /* yacc.c:1646  */
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
#line 7924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3139 "Gmsh.y" /* yacc.c:1646  */
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
#line 7950 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3161 "Gmsh.y" /* yacc.c:1646  */
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
#line 7989 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3196 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3204 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip_until(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 8013 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3212 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3218 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8034 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3225 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3232 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    }
#line 8053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3236 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3245 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-1].l),
		    (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3253 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-1].l),
		    0., 0., 0., (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8084 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3261 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-1].l),
		    (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d),
		    NULL, (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 8096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3269 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3275 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, (yyvsp[-3].l),
		    (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3283 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8128 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3289 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, (yyvsp[-3].l),
		    0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3297 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3303 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, (yyvsp[-3].l),
		    (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8162 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3311 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3317 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8194 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3332 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8216 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3346 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8227 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8249 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8260 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8271 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3381 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3394 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3401 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3407 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8324 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3414 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3420 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8345 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3427 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8355 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3433 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3440 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3446 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3453 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3459 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3466 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8429 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3479 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8439 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3492 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3498 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3512 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3518 "Gmsh.y" /* yacc.c:1646  */
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
#line 8501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3530 "Gmsh.y" /* yacc.c:1646  */
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
#line 8525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3550 "Gmsh.y" /* yacc.c:1646  */
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
#line 8552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3574 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3578 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3582 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3590 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8594 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3596 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3602 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3606 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8620 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3610 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8636 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3618 "Gmsh.y" /* yacc.c:1646  */
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
#line 8659 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3637 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 8671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3653 "Gmsh.y" /* yacc.c:1646  */
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
#line 8696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3668 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8704 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3672 "Gmsh.y" /* yacc.c:1646  */
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
#line 8722 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3688 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8730 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3692 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3697 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3701 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3707 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3718 "Gmsh.y" /* yacc.c:1646  */
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
#line 8830 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3774 "Gmsh.y" /* yacc.c:1646  */
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
#line 8904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3844 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 8913 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3849 "Gmsh.y" /* yacc.c:1646  */
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
#line 8984 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3916 "Gmsh.y" /* yacc.c:1646  */
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
#line 9024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3952 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
    }
#line 9036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3960 "Gmsh.y" /* yacc.c:1646  */
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
#line 9083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4003 "Gmsh.y" /* yacc.c:1646  */
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
#line 9126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4042 "Gmsh.y" /* yacc.c:1646  */
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
#line 9150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4063 "Gmsh.y" /* yacc.c:1646  */
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
#line 9185 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4095 "Gmsh.y" /* yacc.c:1646  */
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
            addPeriodicFace(d_slave,d_master,transfo);
          }
        }
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 9215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4122 "Gmsh.y" /* yacc.c:1646  */
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
#line 9244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4148 "Gmsh.y" /* yacc.c:1646  */
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
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-14].l));
      List_Delete((yyvsp[-10].l));
    }
#line 9273 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4174 "Gmsh.y" /* yacc.c:1646  */
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
#line 9302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4200 "Gmsh.y" /* yacc.c:1646  */
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
          addPeriodicFace(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-8].l));
      List_Delete((yyvsp[-4].l));
    }
#line 9331 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4226 "Gmsh.y" /* yacc.c:1646  */
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
        addPeriodicFace(j_slave,j_master,edgeCounterParts);
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-2].l));
    }
#line 9356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4247 "Gmsh.y" /* yacc.c:1646  */
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
#line 9388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4275 "Gmsh.y" /* yacc.c:1646  */
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
#line 9420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4303 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4307 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9436 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4311 "Gmsh.y" /* yacc.c:1646  */
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
#line 9468 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4339 "Gmsh.y" /* yacc.c:1646  */
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
#line 9511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4378 "Gmsh.y" /* yacc.c:1646  */
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
#line 9554 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4417 "Gmsh.y" /* yacc.c:1646  */
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
#line 9579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4438 "Gmsh.y" /* yacc.c:1646  */
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
#line 9604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4459 "Gmsh.y" /* yacc.c:1646  */
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
#line 9629 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4486 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4490 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 9651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4500 "Gmsh.y" /* yacc.c:1646  */
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
#line 9685 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4534 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4535 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9697 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4536 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4541 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4547 "Gmsh.y" /* yacc.c:1646  */
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
#line 9729 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4559 "Gmsh.y" /* yacc.c:1646  */
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
#line 9751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4577 "Gmsh.y" /* yacc.c:1646  */
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
#line 9778 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4605 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4609 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4611 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4613 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9837 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4619 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9843 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9849 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4621 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9855 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4623 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9867 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4625 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4626 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4627 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9891 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 9897 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4629 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 9903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 9909 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 9915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 9921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4633 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 9927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 9933 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4635 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 9939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4636 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 9945 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4637 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 9951 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4638 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 9957 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4639 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 9963 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4640 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 9969 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4641 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 9975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 9981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 9987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 9993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10005 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10011 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4661 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10071 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10083 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10089 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10095 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4676 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10111 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4687 "Gmsh.y" /* yacc.c:1646  */
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
#line 10141 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4704 "Gmsh.y" /* yacc.c:1646  */
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
#line 10163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4722 "Gmsh.y" /* yacc.c:1646  */
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
#line 10185 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4740 "Gmsh.y" /* yacc.c:1646  */
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
#line 10207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4758 "Gmsh.y" /* yacc.c:1646  */
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
#line 10229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4781 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4787 "Gmsh.y" /* yacc.c:1646  */
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
#line 10264 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4799 "Gmsh.y" /* yacc.c:1646  */
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
#line 10285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4816 "Gmsh.y" /* yacc.c:1646  */
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
#line 10307 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4834 "Gmsh.y" /* yacc.c:1646  */
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
#line 10329 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4852 "Gmsh.y" /* yacc.c:1646  */
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
#line 10351 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4870 "Gmsh.y" /* yacc.c:1646  */
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
#line 10373 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4891 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10382 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4901 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4911 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10428 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4926 "Gmsh.y" /* yacc.c:1646  */
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
#line 10443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4937 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10456 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10465 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 4951 "Gmsh.y" /* yacc.c:1646  */
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
#line 10493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10501 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10517 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10533 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5001 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10541 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10565 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10582 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10591 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5037 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5041 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 5050 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10628 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 5058 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 10640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10648 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 5073 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 10661 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5085 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 10673 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5093 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 10685 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10696 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5108 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 10710 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5118 "Gmsh.y" /* yacc.c:1646  */
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
#line 10743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10751 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5151 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10759 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5155 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10767 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5159 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10775 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5163 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5167 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10791 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5171 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5175 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5179 "Gmsh.y" /* yacc.c:1646  */
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
#line 10840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5208 "Gmsh.y" /* yacc.c:1646  */
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
#line 10873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5237 "Gmsh.y" /* yacc.c:1646  */
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
#line 10906 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5266 "Gmsh.y" /* yacc.c:1646  */
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
#line 10939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5296 "Gmsh.y" /* yacc.c:1646  */
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
#line 10955 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5309 "Gmsh.y" /* yacc.c:1646  */
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
#line 10971 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5322 "Gmsh.y" /* yacc.c:1646  */
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
#line 10987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5335 "Gmsh.y" /* yacc.c:1646  */
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
#line 11003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5347 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5357 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11031 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5367 "Gmsh.y" /* yacc.c:1646  */
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
#line 11047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5379 "Gmsh.y" /* yacc.c:1646  */
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
#line 11063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5392 "Gmsh.y" /* yacc.c:1646  */
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
#line 11079 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5404 "Gmsh.y" /* yacc.c:1646  */
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
#line 11101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5422 "Gmsh.y" /* yacc.c:1646  */
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
#line 11123 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11132 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5448 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5452 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5456 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 11161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11169 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5484 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5491 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5505 "Gmsh.y" /* yacc.c:1646  */
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
#line 11223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5520 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5525 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11240 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5532 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5536 "Gmsh.y" /* yacc.c:1646  */
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
#line 11265 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5549 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 11277 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5557 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11289 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11297 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5572 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11305 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5576 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 11317 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5584 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11327 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5590 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11337 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5596 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 11349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5604 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 11361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5612 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5619 "Gmsh.y" /* yacc.c:1646  */
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
#line 11391 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5634 "Gmsh.y" /* yacc.c:1646  */
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
#line 11409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5648 "Gmsh.y" /* yacc.c:1646  */
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
#line 11427 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5662 "Gmsh.y" /* yacc.c:1646  */
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
#line 11443 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5674 "Gmsh.y" /* yacc.c:1646  */
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
#line 11463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5690 "Gmsh.y" /* yacc.c:1646  */
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
#line 11478 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5701 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11486 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5705 "Gmsh.y" /* yacc.c:1646  */
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
#line 11509 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5724 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5731 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11530 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5737 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11536 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5739 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11548 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5750 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11557 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5755 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11563 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5761 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5770 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11587 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5783 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11593 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5786 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11599 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5790 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11609 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5793 "Gmsh.y" /* yacc.c:1906  */


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

void addPeriodicFace(int iTarget,int iSource,
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
    target->setMeshMaster(source,affineTransform);
  }
}

void addPeriodicFace(int iTarget,int iSource,
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
    target->setMeshMaster(source,edgeCounterparts);
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
      target->setMeshMaster(source,affineTransform);
    }
    else {
      target->setMeshMaster(source,iSource*iTarget < 0 ? -1:1);
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
