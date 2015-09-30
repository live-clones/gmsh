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
    tUpperCase = 304,
    tLowerCase = 305,
    tLowerCaseIn = 306,
    tTextAttributes = 307,
    tBoundingBox = 308,
    tDraw = 309,
    tSetChanged = 310,
    tToday = 311,
    tFixRelativePath = 312,
    tCurrentDirectory = 313,
    tSyncModel = 314,
    tNewModel = 315,
    tOnelabAction = 316,
    tOnelabRun = 317,
    tCpu = 318,
    tMemory = 319,
    tTotalMemory = 320,
    tCreateTopology = 321,
    tCreateTopologyNoHoles = 322,
    tDistanceFunction = 323,
    tDefineConstant = 324,
    tUndefineConstant = 325,
    tDefineNumber = 326,
    tDefineString = 327,
    tSetNumber = 328,
    tSetString = 329,
    tPoint = 330,
    tCircle = 331,
    tEllipse = 332,
    tLine = 333,
    tSphere = 334,
    tPolarSphere = 335,
    tSurface = 336,
    tSpline = 337,
    tVolume = 338,
    tCharacteristic = 339,
    tLength = 340,
    tParametric = 341,
    tElliptic = 342,
    tRefineMesh = 343,
    tAdaptMesh = 344,
    tRelocateMesh = 345,
    tPlane = 346,
    tRuled = 347,
    tTransfinite = 348,
    tComplex = 349,
    tPhysical = 350,
    tCompound = 351,
    tPeriodic = 352,
    tUsing = 353,
    tPlugin = 354,
    tDegenerated = 355,
    tRecursive = 356,
    tRotate = 357,
    tTranslate = 358,
    tSymmetry = 359,
    tDilate = 360,
    tExtrude = 361,
    tLevelset = 362,
    tAffine = 363,
    tRecombine = 364,
    tSmoother = 365,
    tSplit = 366,
    tDelete = 367,
    tCoherence = 368,
    tIntersect = 369,
    tMeshAlgorithm = 370,
    tReverse = 371,
    tLayers = 372,
    tScaleLast = 373,
    tHole = 374,
    tAlias = 375,
    tAliasWithOptions = 376,
    tCopyOptions = 377,
    tQuadTriAddVerts = 378,
    tQuadTriNoNewVerts = 379,
    tQuadTriSngl = 380,
    tQuadTriDbl = 381,
    tRecombLaterals = 382,
    tTransfQuadTri = 383,
    tText2D = 384,
    tText3D = 385,
    tInterpolationScheme = 386,
    tTime = 387,
    tCombine = 388,
    tBSpline = 389,
    tBezier = 390,
    tNurbs = 391,
    tNurbsOrder = 392,
    tNurbsKnots = 393,
    tColor = 394,
    tColorTable = 395,
    tFor = 396,
    tIn = 397,
    tEndFor = 398,
    tIf = 399,
    tEndIf = 400,
    tExit = 401,
    tAbort = 402,
    tField = 403,
    tReturn = 404,
    tCall = 405,
    tMacro = 406,
    tShow = 407,
    tHide = 408,
    tGetValue = 409,
    tGetEnv = 410,
    tGetString = 411,
    tGetNumber = 412,
    tHomology = 413,
    tCohomology = 414,
    tBetti = 415,
    tSetOrder = 416,
    tExists = 417,
    tFileExists = 418,
    tGMSH_MAJOR_VERSION = 419,
    tGMSH_MINOR_VERSION = 420,
    tGMSH_PATCH_VERSION = 421,
    tGmshExecutableName = 422,
    tSetPartition = 423,
    tNameFromString = 424,
    tStringFromName = 425,
    tAFFECTPLUS = 426,
    tAFFECTMINUS = 427,
    tAFFECTTIMES = 428,
    tAFFECTDIVIDE = 429,
    tOR = 430,
    tAND = 431,
    tEQUAL = 432,
    tNOTEQUAL = 433,
    tLESSOREQUAL = 434,
    tGREATEROREQUAL = 435,
    tPLUSPLUS = 436,
    tMINUSMINUS = 437,
    UNARYPREC = 438
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

#line 412 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 429 "Gmsh.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   10143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  204
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1835

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   438

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   189,     2,   199,     2,   188,     2,     2,
     194,   195,   186,   184,   200,   185,   198,   187,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     180,     2,   182,   175,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   196,     2,   197,   193,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   201,     2,   202,   203,     2,     2,     2,
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
     176,   177,   178,   179,   181,   183,   190,   191,   192
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
    5661,  5673,  5689,  5698,  5707,  5717,  5728,  5732,  5751,  5758,
    5765,  5764,  5777,  5782,  5788,  5797,  5810,  5813,  5817
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
  "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tSyncModel", "tNewModel",
  "tOnelabAction", "tOnelabRun", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateTopologyNoHoles", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineString",
  "tSetNumber", "tSetString", "tPoint", "tCircle", "tEllipse", "tLine",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tPlane", "tRuled", "tTransfinite",
  "tComplex", "tPhysical", "tCompound", "tPeriodic", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tRotate", "tTranslate", "tSymmetry",
  "tDilate", "tExtrude", "tLevelset", "tAffine", "tRecombine", "tSmoother",
  "tSplit", "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm",
  "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tQuadTriSngl", "tQuadTriDbl", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tMacro",
  "tShow", "tHide", "tGetValue", "tGetEnv", "tGetString", "tGetNumber",
  "tHomology", "tCohomology", "tBetti", "tSetOrder", "tExists",
  "tFileExists", "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION",
  "tGMSH_PATCH_VERSION", "tGmshExecutableName", "tSetPartition",
  "tNameFromString", "tStringFromName", "tAFFECTPLUS", "tAFFECTMINUS",
  "tAFFECTTIMES", "tAFFECTDIVIDE", "'?'", "tOR", "tAND", "tEQUAL",
  "tNOTEQUAL", "'<'", "tLESSOREQUAL", "'>'", "tGREATEROREQUAL", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "tPLUSPLUS", "tMINUSMINUS",
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
     425,   426,   427,   428,   429,    63,   430,   431,   432,   433,
      60,   434,    62,   435,    43,    45,    42,    47,    37,    33,
     436,   437,   438,    94,    40,    41,    91,    93,    46,    35,
      44,   123,   125,   126
};
# endif

#define YYPACT_NINF -1344

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1344)))

#define YYTABLE_NINF -489

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6580,    47,    59,  6699, -1344, -1344,  3508,    60,    70,  -100,
     -74,    45,   149,   153,   177,   225,   121,   319,   343,   144,
     182,  -151,  -151,  -138,   163,   192,    32,   215,   224,    31,
     282,   288,   174,   409,   424,   554,   323,   348,   504,   514,
     277,   528,   278,   625,   253,   426,   552,   -64,   458,   -57,
     -57,   468,   571,    28,    55,   605,   618,     8,    68,   643,
     657,   314,   720,   747,   753,  4841,   770,   569,   613,   620,
      35,    56, -1344,   627, -1344,   822,   827,   658, -1344,  1257,
    6079,     6,    39, -1344, -1344, -1344,  3709,  3709,   670, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344,    51, -1344,   212,   146, -1344,
      22, -1344, -1344, -1344, -1344,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
     669,   680,   681,   686,   693,   694,  -151,  -151,  -151,  -151,
     701, -1344,  -151, -1344, -1344, -1344, -1344, -1344,  -151,  -151,
     846,   709,   714,   715,  -151,   718,   743, -1344, -1344, -1344,
   -1344,   731,  3709,  3709,  3709,  3709,  3709,   122,    33,   317,
     740,   -28,   825, -1344,   765,   938,   299,    97,   952,  3709,
    2081,  2081, -1344,  3709, -1344, -1344, -1344, -1344,  2081, -1344,
   -1344, -1344, -1344, -1344, -1344,  6831,    33,  3709,  6442,  3709,
    3709,   769,  3709,  6442,  3709,  3709,   778,  6442,  3709,  3709,
    5227,   801,   795, -1344,  6442,  4841,  4841,  4841,   830,   831,
    4841,  4841,  4841,   838,   839,   843,   844,   853,   854,   862,
     887,   870,  3432,   973,  5227,    35,   898,   899,   -57,   -57,
     -57,  3709,  3709,  -104, -1344,  -101,   -57,   912,   920,   921,
    6192,   -51,  -102,   897,   932,   943,  4841,  4841,  5227,   944,
      12,   947, -1344,   818,  1134,  1138, -1344,   949,   951,   953,
    4841,  4841,   962,   963,   974,   255, -1344,   976,    -2,    20,
      23,    24,   484,  5420,  3709,  3998, -1344, -1344,   394, -1344,
    1139, -1344,   462,   537,  1142,  3709,  3709,  3709,   977,  3709,
     981,  1032,  3709,  3709, -1344, -1344,  3709,   975,  1177,  1180,
   -1344, -1344,  1181, -1344,  1184, -1344,   300,  1289,  7667,  2081,
   -1344,  5227,  5227,  3709,  3709,   990,   338,  6831, -1344, -1344,
   -1344, -1344, -1344, -1344,  5227,  1187,   999,  3709,  3709,  1192,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709,  3709,  2081,  2081,  2081,  2081,  2081,  2081,  5227,  2081,
    2081,  3709,  2081,  2081,  2081,  2081,  2081,  3709,  6831,  3709,
    2081,  2081,  2081,  2081,    33,  6831,    33,  1004,  1004,  1004,
    4549,  8889,   173,  1000,  1195,  -151,   998, -1344,  1001,  6818,
    3709, -1344, -1344,  6442,   108, -1344,  3709,  3709,  3709,  3709,
    3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,  3709,
    3709, -1344, -1344,  3709,  3709, -1344, -1344,  1381,   104,  -182,
   -1344, -1344,   -86,  5608, -1344,   306,   -15,   497,  1007,  1009,
    6220,  6442,  4613, -1344,     4,  9234,  9255,  3709,  9276,    72,
    9297,  9318,  3709,   264,  9339,  9360,  1197,  3709,  3709,   334,
    1204,  1205,  1207,  3709,  3709,  1211,  1215,  1215,  3709,  6255,
    6255,  6255,  6255,  3709,  3709,  3709,  6442,  6442,  7694,  1028,
    1222,  1033, -1344, -1344,   -98, -1344, -1344,  5801,  5994,   -57,
     -57,   317,   317,   -55,  3709,  3709,  3709,  6192,  6192,  3709,
    6818,    91, -1344,  3709,  3709,  3709,  3709,  3709,  1230,  1223,
    1232,  3709,  1234,  3709,  3709,  1085, -1344, -1344,  6442,  6442,
    6442,  1235,  1238,  3709,  3709,  3709,  3709,  3709,  1241,   396,
      33, -1344,  1196,  3709, -1344,  1198, -1344,  1203, -1344,  1206,
      41,    42,    43,    50,  6442,  1004, -1344,  9381, -1344,   419,
    3709,  5613, -1344,  3709,  3709,   557, -1344,  9402,  9423,  9444,
    1111,  7748, -1344,  1059,  5361,  9465,  8912, -1344, -1344, -1344,
    1419, -1344,  1522,  3709, -1344, -1344,  1066,  1069,   429,  9486,
    8935,  3709,  6442,   108,  1261,  1262, -1344,  3709,  9507,  8958,
     161,  8866,  8866,  8866,  8866,  8866,  8866,  8866,  8866,  8866,
    8866,  8866,  7774,  8866,  8866,  8866,  8866,  8866,  8866,  8866,
    7800,  7826,  7852,   116,   230,   116,  1074,  1076,  1072,  1073,
    1075,  1077,  7878,   473,   473,   473,   576,   473,  4163, -1344,
    1400,  1078,  1079,   578,   473,  1084,  1086,  1091,   194,   132,
    6831,  3709,  1276,  1298,    37,   473, -1344,   -70,    36,    38,
     -69, -1344,  5771,   534, -1344,  5227,  5380,  1212,   663,  1175,
    1175,   705,   705,   705,   705,   582,   582,  1004,  1004,  1004,
    1004,    17,  9528,  8981, -1344,  3709,  1299,    14,  6442,  1304,
    6442,  3709,  1306,  2081,  1310, -1344,    33,  1311,  2081,  3709,
    6831,  1315,  6442,  6442,  1182,  1318,  1319,  9549,  1320,  1186,
    1323,  1326,  9570,  1193,  1332,  1334,  3709,  9591,  6157,  1122,
   -1344, -1344, -1344,  9612,  9633,  3709,  5227,  1338,  1337,  9654,
    1149,  4163,  1145,  1151,  4163,  1152,  1169,  4163,  1165,  1172,
    4163,  1170,  9675,  9696,  9717,   535,   584,  6442,  1173, -1344,
   -1344,  2468,  2596,   -57,  3709,  3709, -1344, -1344,  1174,  1178,
    6192,  7904,  7930,  7956,  5415,   431,   -57,  2695,  9738,  6780,
    9759,  9780,  9801,  3709,  1366, -1344,  3709,  9822, -1344,  9004,
    9027, -1344,   594,   599,   603, -1344, -1344,  9050,  9073,  7982,
    9096,   537,  6442, -1344,  1188,  1183,  6827,  1185,  1201,  1202,
   -1344,  6442, -1344,  6442, -1344,  6442, -1344,  6442,   606, -1344,
   -1344,  5561,  6442,  1004, -1344,  6442, -1344,  1367,  1368,  1372,
    1209,  3709,  3077,  3709,  3709, -1344,    57, -1344, -1344,  3222,
   -1344,  1208,  5227,  1377,   194,   194,  6855,   615,  5227, -1344,
   -1344,  9119,   537,  1045, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344,  3709, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344,  3709,  3709,  3709, -1344,  6442, -1344,
   -1344, -1344, -1344,  2081,  5227,  2081,  2081,  6831, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344,  3709, -1344, -1344,  2081,
   -1344, -1344, -1344, -1344,  3709,  1398,   131,  3709,  1402,  1404,
    1520, -1344,  1408,  1220,    35,  1411, -1344,  6442,  6442,  6442,
    6442, -1344,   473,  1412,  3709, -1344,  1225,  1226,  1227, -1344,
    1415, -1344, -1344, -1344, -1344, -1344,   537,   537,  9142, -1344,
   -1344,  1247,  2081,   585, -1344,   595,  8008, -1344, -1344, -1344,
    1416, -1344, -1344,  8866,   473,   -57,  4613, -1344,   737,  5227,
    5227,  1423,  5227,   744,  5227,  5227,  1429,  1355,  5227,  5227,
    1648,  1436,  1437,  6442,  1438,  1442,  2307, -1344, -1344,  1444,
   -1344,  1445,   108,  3709,   108,  3709,   108,  3709,   108,  3709,
    1446,  1447,  1448,  1449,  1450,   659,  1455,  4882, -1344, -1344,
     110,  8034,  8060, -1344, -1344,  6883,   -94,   -57,   -57,   -57,
    1456,  1472,  1250,  1473,  1267,    27,    63,    64,    65,   -13,
   -1344,   112, -1344,   431,  1474,  1478,  1479,  1480,  1481,  4163,
   -1344,  1686,  1279,  1483,  1485,  1486,  1425,  3709,  1498,  1501,
    3709,  -160,   667, -1344,  3709, -1344,  3709,  3709,  3709,   679,
     699,   700,   730, -1344,  3709,   733,   734,  5227,  5227,  5227,
    1458,  8086, -1344,  5747,   335,  1505,  1508, -1344,  5227,  1283,
   -1344,  3709,  1510,  3709,  1511, -1344,   473,  1514,  1515, -1344,
    1518, -1344,  1517,  8866,  8866,  8866,  8866,   366,  1325,  1333,
    1335,  1336,  1329,   518,   564,  9843,  1341,  1759, -1344,   454,
    1340,  1525,  1804, -1344, -1344, -1344,    35,  3709, -1344,   748,
   -1344,   757,   762,   767,   776,   108, -1344,  4163,  1339,  3709,
    3709,  5227,  1343, -1344, -1344, -1344,  1344, -1344,  1539,    18,
    1540,  3709,  2159,  1541,  1545,     9,  1369,  1370,  1482,  1482,
    5227,  1566,  1388,  1393,  1589,  1601,  5227,  1409,  1605,  1606,
   -1344,  1610,  5227,   783,  5227,  5227,  1615,  1614, -1344,  5227,
    5227,  4163,  5227,  4163,  5227,  4163,  5227,  4163,  5227,  5227,
    5227,  1422,  1424,  1619,   804, -1344,  3709,  3709,  3709,  1426,
    1427,  -107,   -24,   -21,  1428, -1344,  5227, -1344,  3709, -1344,
    1623, -1344,  1626, -1344,  1627, -1344,  1628, -1344, -1344,  6192,
     624,  5034, -1344,  1434,  1435,  5806, -1344,  6442, -1344, -1344,
   -1344,  1439,  2440, -1344, -1344,  9165,  1633,   473,  8112,  8138,
    8164,  8190, -1344, -1344, -1344, -1344,  4163, -1344,   473,  1632,
    1635,  1504, -1344,  3709,  3709,  3709, -1344,  1637,   832,  1451,
    1638,  2757, -1344,  2800, -1344,   108, -1344, -1344,   272, -1344,
   -1344, -1344, -1344, -1344, -1344,  2081, -1344, -1344, -1344,  6831,
    1642, -1344, -1344,    19, -1344, -1344, -1344, -1344, -1344,  6831,
    3709,  1641,  1644,    37, -1344,  1646,  9188,    35, -1344,  1647,
    1649,  1653,  1655,  5227,  3709,  8216,  8242,   787, -1344,  3709,
    1658, -1344, -1344,  2081, -1344,  8268,  4198,  4163, -1344, -1344,
   -1344, -1344,  3709,  3709,   -57,  1657,  1659,  1660, -1344,  3709,
    3709, -1344, -1344,  1662,  3709, -1344, -1344,  1634,  1664,  1463,
    1667,  1532,  3709, -1344,  1669,  1670,  1671,  1672,  1677,  1678,
     984,  1683,  6442,  6442,  3709, -1344,  6255,  6911,  9864,  6187,
     317,   317,   -57,  1684,   -57,  1685,   -57,  1687,  3709,   496,
    1509,  9885, -1344, -1344, -1344, -1344,  6939,   124, -1344,  1704,
    3786,  1705,  5227,   -57,  3786,  1706,   791,  3709, -1344,  1708,
     537, -1344,  3709,  3709,  3709,  3709, -1344, -1344, -1344,  5227,
    6383,   738,  9906, -1344, -1344,  4584,  5227, -1344, -1344, -1344,
    5227, -1344,  1526,   473,  4391,  4648,  6831,  1716,  2836, -1344,
    1643,  1717, -1344,  1527, -1344, -1344, -1344, -1344, -1344,  1723,
     597,  4163,  3709,  3709,  5227,  1529,   792,  4163, -1344,  1725,
    3709, -1344, -1344,  6967,  6995,   598, -1344, -1344, -1344,  7023,
    7051, -1344,  7079,  1727, -1344,  5227, -1344,  1665,  1733,  4163,
   -1344, -1344, -1344, -1344, -1344, -1344,  1546, -1344, -1344,   814,
     817,  7721,  3947,  1739,  1547, -1344,  3709, -1344,  1548,  1553,
     148, -1344,  1559,   154, -1344,  1565,   232, -1344,  1568,  9211,
    1743,  5227,  1760,  1570,  3709, -1344,  5999,   347, -1344,   820,
     368,   399, -1344,  1766,  7107, -1344,  8294,  8320,  8346,  8372,
    1639,  3709, -1344,  3709, -1344, -1344,  6442,  3993,  1768,  1573,
    1771, -1344, -1344,  3998, -1344, -1344,  2081,  4163, -1344, -1344,
   -1344, -1344,    35, -1344,  1645, -1344, -1344,  3709,  8398,  8424,
   -1344,  5227,  3709,  1772, -1344,  8450, -1344, -1344,  1773,  1775,
    1777,  1778,  1781,  1782,   828,  1588, -1344,  5227,   181,   357,
    6442, -1344, -1344,   317,  6744, -1344, -1344,  6192,   431,  6192,
     431,  6192,   431,  1787, -1344,   829,  5227, -1344,  7135,   -57,
    1788,  6442,   -57, -1344, -1344,  3709,  3709,  3709,  3709,  3709,
    7163,  7191,   851, -1344, -1344,  1791, -1344,   852,  4350,   857,
    1792, -1344,  1602,  4163,  3709,  3709,   860,  4163, -1344,  3709,
     861,   864, -1344, -1344, -1344, -1344, -1344, -1344,  1608,  3709,
     867,  1611,   -57,  5227,  1796,  1612,   -57,  1805,   868,  1613,
    3709, -1344,  7219,   453,   759,  7247,   455,   856,  7275,   457,
     917, -1344,  5227,  1811,  1720,  5075,  1620,   463, -1344,   877,
     466,  8476,  8502,  8528,  8554,  4138, -1344, -1344,  1814, -1344,
    3709, -1344,  6831, -1344, -1344,  3709,  9927,  8580,    52,  8606,
   -1344, -1344,  3709,  7303,  1834,   -57,    13, -1344, -1344,   -57,
      73, -1344,  1836, -1344,  7331,  1837,  3709,  1839,  1841,  3709,
    1842,  1846,  3709,  1848,  1656, -1344,  3709, -1344,   431, -1344,
    6442,  1849,  5999,  3709,  3709,  3709,  3709, -1344, -1344,   259,
   -1344,   878, -1344,  3709, -1344,  5227,  3709,  8632, -1344, -1344,
     507, -1344,   517, -1344, -1344, -1344, -1344,  1674,  7359, -1344,
   -1344,  1675,  7387, -1344, -1344,  1679,  7415, -1344,  1853,  4331,
    1006,  5268,   890, -1344,   520,   905,  8658,  8684,  8710,  8736,
    6831,  1875,  1681,  9948,   909,  7443,  3709,   -57,   -57,   431,
    1877,   431,  1879,   431,  1880, -1344, -1344, -1344, -1344,   431,
    1881,  6442,  1883,  3709,  3709,  3709,  3709, -1344, -1344,  2081,
   -1344,  1692,  1910,  7471,   526,   545,  1107, -1344,  1718,  1129,
   -1344,  1721,  1167, -1344,  1722,  1316, -1344,   910, -1344,  8762,
    8788,  8814,  8840,   914, -1344,  1726,  5227, -1344,  1911,  3709,
    3709,  1912,   431,  1915,   431,  1918,   431, -1344,  1920,  3709,
    3709,  3709,  3709,  2081,  1922,  2081,   918, -1344,  7499,  7527,
   -1344,  1562, -1344,  1617, -1344,  1682, -1344,  7555,  7583,  7611,
    7639, -1344, -1344,   934, -1344,  1923,  1924,  1926,  1943,  1944,
    1945, -1344, -1344, -1344, -1344,  2081,  1947, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   247,     0,     0,     0,   243,     0,
       0,     0,     0,   342,   343,   344,     0,     0,     0,     5,
       7,     6,     8,     9,    10,    20,    11,    12,    13,    14,
      19,    18,    15,    16,    17,     0,    21,   517,     0,   391,
     516,   489,   392,   393,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,   509,   493,   398,   399,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   396,   397,
     492,     0,     0,     0,     0,    66,    67,     0,     0,   187,
       0,     0,     0,   349,     0,   485,   517,   404,     0,     0,
       0,     0,   227,     0,   229,   230,   225,   226,     0,   231,
     232,   109,   117,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     516,     0,   187,   517,     0,     0,   339,     0,     0,     0,
       0,     0,     0,     0,     0,   516,   444,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   467,   437,   443,
       0,   438,   517,   404,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,   223,   224,     0,   516,     0,     0,
     241,   242,     0,   187,     0,   187,   516,     0,     0,     0,
     345,     0,     0,    66,    67,     0,     0,    59,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,   351,   353,
       0,     0,     0,     0,     0,     0,     0,   186,     0,   185,
       0,    68,    69,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,   216,     0,     0,   412,   164,     0,   516,     0,
     485,   486,     0,     0,   512,     0,   107,   107,     0,     0,
       0,     0,   473,   474,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   187,   187,     0,   428,   427,     0,     0,     0,
       0,   187,   187,     0,     0,     0,     0,     0,     0,     0,
     257,     0,   187,     0,     0,     0,     0,     0,   309,     0,
       0,     0,     0,     0,     0,     0,   205,   340,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    67,     0,     0,
       0,   450,     0,     0,   451,     0,   452,     0,   453,     0,
       0,     0,     0,     0,     0,   351,   445,     0,   439,     0,
       0,     0,   317,    66,    67,     0,   222,     0,     0,     0,
       0,     0,   187,     0,     0,     0,     0,   245,   244,   210,
       0,   211,     0,     0,   235,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   401,   510,
       0,     0,     0,     0,     0,     0,     0,     0,   350,     0,
      59,     0,     0,     0,     0,     0,   182,     0,     0,     0,
       0,   188,     0,     0,    59,     0,     0,   367,   366,   364,
     365,   360,   362,   361,   363,   355,   354,   356,   357,   358,
     359,     0,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   337,   338,     0,     0,     0,     0,   305,     0,     0,
       0,   132,   133,     0,   135,   136,     0,   138,   139,     0,
     141,   142,     0,     0,     0,     0,     0,     0,     0,   152,
     187,     0,     0,     0,     0,     0,   430,   429,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
       0,     0,     0,     0,     0,   320,     0,     0,   206,     0,
       0,   202,     0,     0,     0,   335,   334,     0,     0,     0,
       0,   417,     0,   468,     0,     0,     0,     0,     0,     0,
     454,     0,   455,     0,   456,     0,   457,     0,     0,   350,
     440,   447,     0,   356,   446,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,   212,   214,     0,
     518,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      74,     0,   406,   405,   419,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   390,   378,     0,   380,   381,   382,
     383,   384,   385,   386,     0,     0,     0,   501,     0,   506,
     497,   498,   499,     0,     0,     0,     0,     0,   502,   503,
     504,   425,   508,   121,   126,    99,     0,   494,   496,     0,
     403,   409,   410,   490,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,   411,     0,     0,     0,
       0,   514,     0,     0,     0,    44,     0,     0,     0,    57,
       0,    35,    36,    37,    38,    39,   408,   407,     0,   487,
      24,    22,     0,     0,    25,     0,     0,   217,   513,    70,
     110,    71,   118,     0,     0,     0,   475,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   303,   308,   306,     0,
     316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   215,
       0,     0,     0,   177,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,   248,     0,     0,     0,     0,     0,     0,   310,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   405,     0,   470,     0,   449,     0,     0,     0,     0,
       0,     0,     0,   441,     0,     0,     0,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,   209,     0,     0,
     346,     0,     0,     0,     0,   515,     0,     0,     0,   414,
       0,   413,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,    84,    89,    91,     0,     0,   483,     0,
      97,     0,     0,     0,     0,     0,    75,   368,     0,     0,
       0,     0,     0,    30,   416,   415,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,   314,     0,
       0,   134,     0,   137,     0,   140,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,     0,   291,     0,   297,
       0,   299,     0,   293,     0,   295,     0,   258,   287,     0,
       0,     0,   200,     0,     0,     0,   321,     0,   204,   203,
     341,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,   458,   459,   460,   461,   448,   442,     0,     0,
       0,     0,   480,     0,     0,     0,   236,     0,     0,     0,
       0,     0,    87,     0,    86,     0,    76,   219,   418,   218,
     379,   387,   388,   389,   507,     0,   422,   423,   424,     0,
       0,   402,   122,     0,   511,   127,   421,   495,    78,    59,
       0,     0,     0,     0,    77,     0,     0,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,    26,    27,     0,    28,     0,     0,   111,   114,    72,
      73,   148,     0,     0,     0,     0,     0,     0,   151,     0,
       0,   167,   168,     0,     0,   153,   174,     0,     0,     0,
       0,   144,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   221,     0,     0,     0,     0,
     187,   187,     0,   268,     0,   270,     0,   272,     0,   437,
       0,     0,   298,   300,   294,   296,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
     418,   471,     0,     0,     0,     0,   472,   156,   157,     0,
       0,     0,     0,   100,   104,     0,     0,   347,    80,    79,
       0,   420,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,   484,   189,   190,   191,   192,     0,
       0,    40,     0,     0,     0,     0,     0,    42,   488,     0,
       0,   112,   115,     0,     0,   147,   154,   155,   159,     0,
       0,   169,     0,     0,   315,     0,   162,     0,     0,   304,
     173,   149,   161,   172,   176,   160,     0,   170,   175,     0,
       0,     0,     0,     0,     0,   434,     0,   433,     0,     0,
       0,   259,     0,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,   198,     0,
       0,     0,   193,     0,     0,    33,     0,     0,     0,     0,
       0,     0,   478,     0,   238,   237,     0,     0,     0,     0,
       0,   500,   505,     0,   123,   125,     0,   128,   129,   130,
      90,    92,     0,    98,     0,    81,    45,     0,     0,     0,
     436,     0,     0,     0,    29,     0,   121,   126,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,   311,   311,
       0,   105,   106,   187,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,   187,     0,     0,
       0,     0,     0,   184,   183,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,     0,    82,     0,   473,     0,
       0,   482,     0,    41,     0,     0,     0,    43,    58,     0,
       0,     0,   329,   331,   330,   332,   333,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,   253,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,   477,   239,     0,   348,
       0,   124,     0,   131,    96,     0,     0,     0,     0,     0,
     113,   116,     0,     0,     0,     0,     0,   312,   322,     0,
       0,   323,     0,   178,     0,   274,     0,     0,   276,     0,
       0,   278,     0,     0,     0,   289,     0,   249,     0,   187,
       0,     0,     0,     0,     0,     0,     0,   158,   103,     0,
     119,     0,    49,     0,    55,     0,     0,     0,   145,   171,
       0,   326,     0,   327,   328,   431,   262,     0,     0,   269,
     263,     0,     0,   271,   264,     0,     0,   273,     0,     0,
       0,   255,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,     0,   282,     0,   284,   290,   301,   254,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   120,    46,     0,
      53,     0,     0,     0,     0,     0,     0,   265,     0,     0,
     266,     0,     0,   267,     0,     0,   201,     0,   195,     0,
       0,     0,     0,     0,    47,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,     0,
     275,     0,   277,     0,   279,     0,   196,     0,     0,     0,
       0,    48,    50,     0,    51,     0,     0,     0,     0,     0,
       0,   462,   463,   464,   465,     0,     0,    56,   324,   325,
     281,   283,   285,    52,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1344, -1344, -1344, -1344,   836, -1344, -1344, -1344, -1344,   313,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344,  -380,  -103,  2255,    -1, -1344,  1512, -1344, -1344,
   -1344, -1344, -1344,   440, -1344,   441, -1344, -1344, -1344, -1344,
   -1344, -1344,   847,  1972,     7,  -494,  -258, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344,  1990, -1344, -1344, -1344, -1344, -1344,
   -1344, -1344, -1344, -1344, -1344, -1344, -1344, -1344,  -952,  -943,
   -1344, -1344,  1519, -1344,   465, -1344, -1344, -1344, -1344,  1544,
   -1344, -1344,     0, -1344, -1343,  2235,  -109,  2444,  1942,  -244,
     735, -1344,    21,    62, -1344,  -368,    -3,    95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    89,   932,    90,    91,   681,  1400,  1406,
     921,  1108,  1572,  1773,   922,  1722,  1813,   923,  1775,   924,
     925,  1112,   344,   435,   181,   414,    92,   696,   446,  1516,
    1517,   447,  1567,  1083,  1252,  1084,  1255,   730,   733,   736,
     739,  1428,  1295,   661,   296,   408,   409,    95,    96,    97,
      98,    99,   100,   101,   297,  1013,  1668,  1739,   765,  1452,
    1455,  1458,  1697,  1701,  1705,  1758,  1761,  1764,  1009,  1010,
    1147,   969,   727,   774,  1594,   103,   104,   105,   106,   298,
     183,   883,   496,   254,  1277,   299,   300,   301,   559,   310,
     905,  1099,   444,   440,   884,   445,   186,   303
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   491,   510,   541,   623,   345,   625,   758,   759,  1469,
      94,   322,   270,   687,   525,  1291,   522,   636,   688,  1691,
     930,   915,   651,  1385,  1282,   544,   346,   184,   546,   548,
     342,   343,   262,  1179,   665,   216,   211,   317,  1206,   308,
     211,   903,   216,   203,   324,   204,   800,   802,   804,   253,
     255,   192,   261,     4,   273,   806,   207,   330,  1684,     5,
     311,  1190,   302,   208,  1055,   580,  1188,   582,   185,  1181,
    1183,  1185,   275,   188,   276,   245,   273,   499,   500,  1693,
     499,   500,  1524,   499,   500,  1000,   499,   500,   246,   247,
     499,   500,   513,  1332,   190,  1333,  1001,   501,   108,   514,
     502,   187,   753,   263,  1002,  1003,  1004,   264,  1170,   689,
    1005,  1006,  1007,  1008,   690,   664,   470,   471,   472,   265,
     191,   475,   476,   477,   207,   219,   402,   249,   250,   499,
     500,   907,   910,   499,   500,  1089,   266,   251,   267,   664,
     542,   318,   321,   277,   252,   760,   916,   917,   918,   919,
     512,   189,   274,   337,  1180,   194,   271,   518,   519,   195,
     499,   500,   545,   499,   500,   547,   549,   411,  1576,   412,
    1386,   531,   532,   413,   319,   273,  1334,    88,  1335,  1336,
     650,  1337,   694,   196,  1590,   695,   407,   273,   273,  1187,
    1182,  1184,  1186,   499,   500,   273,   931,   499,   500,   543,
     931,   664,    88,   273,   703,   302,   704,   323,   523,   272,
     302,   439,   442,   838,   302,   180,   347,   302,   348,   920,
     349,   302,   302,   302,   302,   180,   212,   302,   302,   302,
     212,   197,   217,   213,   751,   752,   309,   908,   904,   909,
     325,   302,   801,   803,   805,   331,   193,  1188,   494,   495,
     312,   807,   332,  1685,   767,  1056,   503,   499,   500,   220,
     511,   403,   404,   302,   302,   302,  1720,   448,   894,   897,
    1090,  1091,   703,   405,   709,   499,   500,   302,   302,   338,
     339,   340,   341,  1591,  1592,   441,   441,   342,   343,  1593,
     302,   766,   302,   441,   499,   500,   499,   500,  -486,   652,
     685,   449,   686,   338,   339,   340,   341,   180,   499,   500,
    1166,   411,  1189,   412,   822,   198,   693,   338,   339,   340,
     341,   406,   342,   343,  1464,   199,   273,   829,   302,   302,
     896,   241,   499,   500,   242,   593,   342,   343,   499,   500,
     201,   302,  1724,  1225,   338,   339,   340,   341,  1537,   200,
     586,   342,   343,   234,  1539,   230,   235,   209,   231,   236,
     232,   237,  -487,   342,   343,   338,   339,   340,   341,   273,
     273,   273,   273,   273,   273,   302,   273,   273,   202,   273,
     273,   273,   273,   273,   342,   343,   210,   273,   273,   273,
     273,   273,   280,   273,   624,   281,   626,   627,   628,   594,
     630,   631,   560,   633,   634,   635,   333,   637,   334,   214,
     302,   641,   642,   643,   644,   335,   499,   500,   215,    48,
      49,    50,    51,   225,   441,   411,   226,   412,    56,   227,
     868,    59,  1541,  1796,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   302,   536,
     639,   537,   430,   538,  1061,  1063,   179,   646,   180,  1595,
    1596,  1259,   342,   343,   703,  1593,   713,   441,   441,   441,
     441,   441,   441,  -488,   441,   441,   218,   441,   441,   441,
     441,   441,   219,   302,   302,   441,   441,   441,   441,   645,
     221,   647,   987,   433,   347,   434,   583,   844,   538,   756,
     757,   692,   335,   180,   560,   222,   693,   495,   407,   407,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   224,   302,   302,   302,   430,  1000,
    1226,   499,   500,   411,   703,   412,   719,   273,   793,   592,
    1001,   732,   735,   738,   741,   895,   898,  1549,  1002,  1003,
    1004,   302,   499,   500,  1005,  1006,  1007,  1008,   302,   550,
     223,   411,   551,   412,   816,   552,   703,   553,  1551,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     561,   428,   429,   499,   500,   228,  1604,   430,  1607,   302,
    1610,   411,  1150,   412,  1152,   229,  1154,   792,  1156,  1552,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   233,   857,   858,   859,   860,   861,   862,   863,   703,
     243,   810,   867,   869,   870,   338,   339,   340,   341,   832,
     244,   833,   878,   879,   880,   794,   882,   499,   500,   499,
     500,   499,   500,   890,   342,   343,   257,   499,   500,   258,
     499,   500,   259,  1656,   906,  1659,   563,  1662,   564,   248,
    1098,  1188,   302,  1670,  1188,   335,  1672,  1188,   411,   256,
     412,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   561,   428,   429,   302,   268,   302,   844,   430,
     273,   499,   500,   273,   697,   273,   269,   695,  1460,   302,
     302,   499,   500,   238,   499,   500,   239,  1727,   240,  1260,
     499,   500,   899,   411,   938,   412,  1710,  1728,  1250,   942,
    1741,   278,  1000,   302,   282,  1273,  1779,   342,   343,   499,
     500,  1062,  1064,  1001,   703,   703,   912,   983,   279,  1069,
    1071,  1002,  1003,  1004,   302,  1780,  1483,  1005,  1006,  1007,
    1008,   283,   411,   990,   412,   249,   250,   284,   815,   411,
     996,   412,   944,   305,  1253,   251,  1011,  1188,   427,   428,
     429,   881,   260,   888,   304,   430,   693,  1756,   889,  1759,
    1119,  1762,   499,   500,   703,   703,   984,  1765,   441,   302,
    1120,   940,  1506,   441,   703,   703,  1025,  1507,   302,   703,
     302,  1026,   302,   703,   302,  1027,   703,   306,  1043,   302,
    1325,  1326,   302,  1188,   307,   703,  1188,  1066,  1126,  1188,
    1127,   313,  1188,  1114,  1115,  1132,  1348,  1133,   314,   302,
    1801,   415,  1803,   315,  1805,   302,  1448,  1449,  1374,  1375,
     273,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,  1265,   389,   316,  1380,   430,  1000,  1188,   703,
    1188,  1163,  1188,   375,  1072,   302,   329,   703,  1001,  1207,
     273,   302,   273,   273,   376,   377,  1002,  1003,  1004,   703,
     378,  1212,  1005,  1006,  1007,  1008,   273,   379,   380,   425,
     426,   427,   428,   429,  1078,   385,  1080,  1081,   430,   703,
     703,  1213,  1214,   390,   302,   302,   302,   302,   391,   392,
    1086,  1105,   394,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   396,  1071,   273,
     703,   430,  1215,   703,   703,  1217,  1218,   395,   441,  1082,
    1484,   410,  1123,  1124,   432,  1125,   302,   302,  1267,   302,
    1268,   302,   302,  1118,  1000,   302,   302,   703,   436,  1269,
     302,  1657,   703,   457,  1270,  1001,   431,   703,   441,  1271,
     441,   441,   462,  1002,  1003,  1004,   703,   489,  1272,  1005,
    1006,  1007,  1008,   703,   441,  1309,  1261,  1404,  1436,  1405,
    1437,   703,  1512,  1473,  1513,   467,   468,  1171,  1172,  1173,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   703,  1000,  1528,   703,   430,  1529,
    1404,   335,  1550,  1394,   473,   474,  1001,   441,  1404,  1612,
    1588,  1613,   478,   479,  1002,  1003,  1004,   480,   481,  1599,
    1005,  1006,  1007,  1008,   302,   302,   302,   482,   483,   438,
     111,   703,  1630,  1628,  1631,   302,   484,   693,  1660,  1633,
    1404,  1250,  1638,  1640,  1253,  1235,  1641,  1404,   703,  1644,
    1652,   486,  1240,  1241,  1242,  1243,  1244,   703,  1512,  1671,
    1721,   485,  1251,  1254,   137,   138,   139,   140,   141,   142,
     703,   515,  1740,   146,   147,   148,   149,     7,     8,   492,
     493,   151,   152,   153,  1000,   703,   154,  1742,   302,  1404,
     703,  1751,  1788,   504,  1793,  1001,  1794,   159,  1404,  1663,
    1815,   505,   506,  1002,  1003,  1004,   516,   302,  1569,  1005,
    1006,  1007,  1008,   302,  1825,  1381,  1826,   517,   521,   302,
     526,   302,   302,   524,   527,   562,   302,   302,   566,   302,
     528,   302,   529,   302,   530,   302,   302,   302,   533,   534,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
     535,    33,   540,   302,   573,   570,    38,    39,   180,    41,
      42,    43,   572,   577,  1288,    46,   578,   579,   302,  1347,
     581,   591,   302,   596,   302,   597,   600,   430,   653,   179,
     162,   163,   654,   656,   716,  1000,  1361,   699,  1737,   700,
     720,   721,   170,   722,    88,   171,  1001,  1366,   725,    67,
      68,    69,   726,   748,  1002,  1003,  1004,  1000,   749,   775,
    1005,  1006,  1007,  1008,   750,   342,   343,   773,  1001,   776,
     778,   785,   273,  1070,   786,   791,  1002,  1003,  1004,   795,
     820,   797,  1005,  1006,  1007,  1008,   798,  1381,  1570,   799,
     823,   317,   111,   830,   831,  1000,  1382,   839,   840,   871,
     302,   872,   873,   874,   887,   875,  1001,   876,   886,   891,
     273,   892,   901,   302,  1002,  1003,  1004,   781,   893,  1615,
    1005,  1006,  1007,  1008,  1415,   584,   137,   138,   139,   140,
     141,   142,   902,   929,  1409,   146,   147,   148,   149,  1781,
     934,  1383,   937,   151,   152,   153,   939,   941,   154,   302,
     302,  1387,   945,   963,   948,   949,   950,   952,   953,   159,
     954,  1783,  1450,   955,  1453,   957,  1456,   407,   407,   958,
     441,   959,   968,   970,   972,   973,   974,   302,  1412,   302,
    1467,   302,   975,  1470,  1471,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   976,   977,   302,   978,   430,  1785,
     979,   986,  1020,   302,  1047,  1048,   993,   302,   441,  1049,
     994,   302,  1492,  1060,  1034,  1033,  1036,   684,  1443,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   302,  1037,  1038,  1088,   430,   885,  1050,  1093,  1058,
    1094,  1711,   162,   163,  1000,  1096,  1097,  1100,  1106,  1109,
    1110,  1113,   302,  1122,   170,  1001,    88,   171,  1111,  1117,
    1130,     7,     8,  1002,  1003,  1004,  1136,  1488,  1137,  1005,
    1006,  1007,  1008,  1141,  1142,  1144,  1495,  1498,  1499,  1145,
    1148,  1176,  1149,  1158,  1159,  1160,  1161,  1162,   302,  1164,
    1174,  1178,  1222,   302,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,  1175,  1177,
    1197,  1191,   430,   302,  1192,  1230,  1193,  1194,  1195,  1198,
     302,  1199,  1200,   273,   657,    24,    25,   658,    27,    28,
     659,    30,   660,    32,  1203,    33,  1201,  1204,   302,  1227,
      38,    39,  1228,    41,    42,    43,  1232,  1234,  1787,    46,
    1236,  1237,  1238,  1239,   302,  1245,  1095,   302,  1246,  1249,
    1247,  1248,  1263,  1274,     7,     8,  1257,  1603,  1262,  1606,
     407,  1609,  1280,   302,  1279,  1281,  1284,  1289,   302,  1617,
     182,  1290,  1620,    67,    68,    69,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
    1292,  1293,  1298,  1294,   430,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1299,
     302,   441,  1646,   430,  1300,  1301,  1650,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,  1302,    33,   302,
    1304,  1305,  1306,    38,    39,  1307,    41,    42,    43,  1312,
    1313,   827,    46,  1322,  1338,  1323,  1324,  1330,  1331,  1342,
     327,   328,  1343,  1344,  1345,  1352,  1353,  1360,  1367,  1423,
    1357,  1368,  1369,  1373,  1377,  1690,  1384,  1389,  1390,  1692,
    1502,  1376,  1392,  1395,  1140,  1396,    67,    68,    69,  1397,
    1000,  1398,  1408,  1416,  1425,  1417,  1418,   302,  1421,   302,
    1424,  1001,  1714,  1426,  1427,  1430,  1431,  1432,  1433,  1002,
    1003,  1004,   302,  1434,  1435,  1005,  1006,  1007,  1008,  1438,
    1451,  1454,  1196,  1457,  1680,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1461,
    1465,  1468,  1472,   430,  1475,  1000,   397,   398,   399,   400,
     401,  1491,  1500,  1503,   828,  1504,  1001,  1754,  1755,  1505,
    1511,  1514,  1523,   437,  1002,  1003,  1004,   443,   302,  1526,
    1005,  1006,  1007,  1008,  1525,  1532,   273,  1527,  1533,  1544,
    1535,   450,   452,   455,   456,  1536,   458,   452,   460,   461,
    1538,   452,   464,   465,  1818,  1258,  1540,  1546,   452,  1542,
    1774,  1547,  1553,   302,  1564,  1565,  1559,  1566,  1578,  1582,
    1000,  1583,  1747,  1584,  1585,  1571,   488,  1586,  1587,  1589,
     273,  1001,   273,  1611,  1618,   497,   498,  1629,  1634,  1002,
    1003,  1004,  1648,  1635,   498,  1005,  1006,  1007,  1008,  1642,
    1264,  1651,  1645,  1649,  1811,  1653,  1814,  1665,  1666,  1819,
    1678,  1669,   273,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   555,   557,   452,
    1689,   430,  1694,  1696,   441,  1699,  1833,  1700,  1703,   567,
     568,   569,  1704,   571,  1707,  1713,   574,   575,  1708,  1735,
     576,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,  1729,  1731,   589,   590,   430,
    1733,  1748,  1749,  1757,  1820,  1760,  1763,  1766,   441,  1768,
     441,   598,   599,  1776,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,  1777,  1797,  1800,  1782,
     441,  1802,  1784,  1786,  1804,   632,  1806,  1795,  1812,  1827,
    1828,   638,  1829,   640,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,  1681,  1830,
    1831,  1832,   430,  1834,   662,  1283,  1580,   452,  1581,   698,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,    93,  1296,   682,   683,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   102,  1597,   555,   728,   430,  1391,     0,
       0,   707,     0,     0,     0,     0,   712,     0,     0,     0,
       0,   717,   718,     0,     0,     0,     0,   723,   724,     0,
       0,     0,   729,   731,   734,   737,   740,   742,   743,   744,
     452,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   761,   762,
     763,   397,   398,   764,     0,     0,     0,   768,   769,   770,
     771,   772,     0,     0,     0,   777,     0,   779,   780,     0,
       0,     0,   452,   452,   452,     0,     0,   787,   788,   789,
     598,   790,     0,     0,     0,   438,   111,   796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,     0,
       0,     0,     0,     0,   811,   813,     0,   682,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,     0,   790,     0,   146,
     147,   148,   149,     0,     0,   836,   452,   151,   152,   153,
       0,   841,   154,     0,     0,     0,     0,     0,     0,     0,
     454,     0,     0,   159,     0,   459,     0,     0,     0,   463,
       0,     0,   109,   326,   111,     0,   469,     0,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   900,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,     0,   151,   152,   153,     0,     0,
     154,     0,   155,   156,   157,     0,     0,     0,     0,   928,
     158,   159,   452,     0,   452,   936,   162,   163,     0,     0,
       0,     0,     0,   943,     0,     0,   813,   946,   170,     0,
      88,   171,     0,     0,     0,     0,     0,     0,     0,     0,
     960,     0,     0,     0,     0,     0,     0,     0,     0,   966,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,     0,     0,     0,     0,   991,   992,
       0,     0,     0,     0,   995,     0,     0,     0,     0,     0,
       0,     0,     0,   161,   162,   163,   164,  1019,     0,     0,
    1021,   165,   166,   167,   168,   169,   170,     0,    88,   171,
       0,     0,     0,     0,     0,     0,   452,     0,     0,     0,
       0,     0,     0,   172,   173,   452,     0,   452,   174,   452,
       0,   452,     0,   294,     0,   663,   452,     0,   178,   452,
    1286,     0,   336,     0,     0,  1051,     0,  1053,  1054,     0,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     0,     0,     0,     0,
    1073,   381,   382,   383,   384,  1146,     0,   386,  1074,  1075,
    1076,     0,   452,   387,   388,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,   745,   746,
    1085,     0,     0,     0,     0,     0,     0,     0,  1087,     0,
       0,  1092,     0,     0,     0,     0,  1358,     0,     0,     0,
       0,   452,   452,   452,   452,   466,     0,     0,  1107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,   783,   784,     0,     0,     0,     0,     0,     0,   490,
       7,     8,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   808,     0,     0,     0,
     430,     0,     0,   520,     0,     0,     0,   452,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1151,     0,  1153,
       0,  1155,     0,  1157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   837,     0,     0,     0,     0,     0,
     539,     0,     0,   657,    24,    25,   658,    27,    28,   659,
      30,   660,    32,     0,    33,     0,     0,   565,     0,    38,
      39,     0,    41,    42,    43,     0,   587,   588,    46,     0,
       0,  1202,     0,     0,  1205,     0,     0,     0,  1208,   595,
    1209,  1210,  1211,     0,     0,     0,     0,     0,  1216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,  1231,     0,  1233,     7,     8,
       0,     0,     0,   629,     0,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
     933,     0,   935,   430,     0,     0,     0,     0,     0,     0,
       0,  1266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   453,  1275,  1276,     0,     0,   453,     0,     0,
     655,   453,     0,     0,     0,  1285,  1287,     0,   453,     0,
     988,   657,    24,    25,   658,    27,    28,   659,    30,   660,
      32,     0,    33,     0,     0,     0,     0,    38,    39,   985,
      41,    42,    43,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
    1327,  1328,  1329,     0,     0,     0,     0,     0,     0,     0,
    1339,     0,  1341,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,  1346,  1032,     0,     0,   556,     0,   453,
       0,   452,     0,  1039,     0,  1040,     0,  1041,     0,  1042,
       0,     0,     0,     0,  1045,     0,     0,  1046,     0,     0,
       0,     0,     0,  1378,     0,     0,     0,  1370,  1371,  1372,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,   989,     0,
       0,     0,     0,     0,  1388,     0,  1379,     0,     0,     0,
    1077,     0,     0,     0,     0,     0,     0,     0,  1401,     0,
       0,     0,     0,  1407,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,  1413,  1414,     0,     0,
       0,     0,  1501,  1419,  1420,     0,     0,     0,  1422,  1101,
    1102,  1103,  1104,     0,     0,     0,  1429,   453,     0,     0,
       0,     0,     0,     0,     0,     0,   452,   452,  1441,     0,
    1442,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1459,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   452,   556,     0,  1012,   452,     0,
     913,  1474,     0,     0,     0,  1143,  1476,  1477,  1478,  1479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1497,
     453,   453,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,  1508,  1509,     0,     0,
     430,     0,     0,     0,  1515,     0,     0,     0,     0,     0,
       0,   967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   453,   453,   453,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
    1534,     0,     0,   430,     0,     0,     0,     0,   453,     0,
       0,     0,     0,     0,     0,   814,     0,     0,  1548,     0,
     555,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,  1560,     0,  1561,     0,   430,
     452,     0,     0,     0,     0,     0,   453,  1568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1573,     0,     0,     0,     0,  1577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1059,     0,     0,
       0,     0,     0,  1067,   452,     0,     0,     0,     0,     0,
       0,  1602,     0,  1605,     0,  1608,     0,     0,     0,     7,
       8,     0,     0,     0,     0,   452,     0,     0,     0,  1621,
    1622,  1623,  1624,  1625,     0,     0,     0,     0,     0,  1079,
       0,     0,     0,     0,     0,     0,     0,     0,  1636,  1637,
       0,     0,     0,  1639,     0,     0,     0,     0,     0,     0,
       0,     0,   453,  1643,   453,     0,     0,     0,     0,  1356,
       0,     0,     0,     0,  1654,     0,   814,   947,     0,     0,
       0,     0,   657,    24,    25,   658,    27,    28,   659,    30,
     660,    32,     0,    33,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,  1679,     0,     0,    46,     0,  1407,
       0,     0,     0,     0,  1128,  1129,  1687,  1131,     0,  1134,
    1135,   453,     0,  1138,  1139,     0,     0,     0,     0,     0,
    1698,     0,     0,  1702,     0,     0,  1706,     0,     0,     0,
    1709,    67,    68,    69,   452,     0,   452,  1716,  1717,  1718,
    1719,     0,     0,     0,     0,     0,     0,  1723,     0,     0,
    1725,     0,     0,     0,     7,     8,   453,     0,     0,     0,
       0,     0,     0,     0,     0,   453,     0,   453,     0,   453,
       0,   453,     0,     0,     0,     0,   453,     0,     0,   453,
       0,     0,     0,     0,  1439,  1440,     0,     0,     0,     0,
    1753,     0,     0,     0,     0,     0,     0,     0,     0,  1052,
       0,     0,  1219,  1220,  1221,   452,     0,  1769,  1770,  1771,
    1772,     0,     0,  1229,     0,     0,     0,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,     0,    33,     0,
       0,     0,   453,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,  1798,  1799,     0,     0,     0,     0,     0,
       0,     0,     0,  1807,  1808,  1809,  1810,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1278,     0,     0,     0,
       0,   453,   453,   453,   453,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,  1297,     0,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,  1308,     0,  1310,
    1311,     0,     0,     0,  1314,  1315,     0,  1316,     0,  1317,
       0,  1318,     0,  1319,  1320,  1321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,     0,     0,
       0,  1340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1057,     0,  1351,     0,  1562,     0,
    1355,     0,     0,     0,     0,   109,   326,     0,     0,     0,
       0,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,  1598,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,     0,   155,   156,   157,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,  1399,     0,
       0,   109,   110,   111,     0,     0,     0,   112,   113,   114,
       0,  1411,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,     0,     0,   161,  1278,     0,   164,
       0,     0,     0,     0,   165,   166,   167,   168,   169,     0,
       0,    88,     0,     0,  1480,     0,     0,     0,     0,     0,
       0,  1489,  1712,     0,  1715,  1490,   172,   173,     0,  1494,
       0,   174,     0,     0,     0,     0,   294,     0,     0,     0,
       0,   178,     0,   487,     0,     0,     0,     0,     0,  1510,
       0,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,     0,     0,
    1278,     0,   161,   162,   163,   164,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,  1767,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,     0,  1545,   174,     0,     0,
       0,     0,   175,     0,   176,     0,   177,   178,     0,   179,
       0,   180,   109,   326,     0,     0,     0,     0,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,  1278,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,   150,  1278,     0,     0,     0,   453,   453,     0,     0,
       0,     0,   155,   156,   157,     0,     0,     0,     0,     0,
     158,  1614,     0,     0,     0,     0,     0,     0,     0,   109,
     285,     0,     0,     0,   453,   112,   113,   114,   453,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   287,     0,     0,     0,     0,     0,  1647,     0,
       0,   143,   144,   145,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,  1664,     0,   155,
     156,   157,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   288,     0,   161,   289,     0,   164,   290,     0,   291,
       0,   165,   166,   167,   168,   169,     0,     0,    88,     0,
       0,   292,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,   172,   173,     0,     0,    56,   174,     0,
      59,     0,     0,   294,     0,     0,     0,     0,   178,     0,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1278,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,     0,     0,     0,     0,     0,   453,     0,     0,
     161,     0,     0,   164,     0,     0,     0,     0,   165,   166,
     167,   168,   169,  1531,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,  1466,     0,     0,   453,   174,     0,     0,     0,     0,
     509,     0,     0,     0,     0,   178,     0,   252,   558,     0,
       0,     0,     0,     0,     0,   453,     0,     0,     0,  1563,
       0,   109,   285,     0,     0,     0,     0,   112,   113,   114,
       0,  1278,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   287,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   145,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
       0,     0,     0,   288,     0,     0,   289,     0,     0,   290,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,     0,   453,     0,   453,     0,     0,     0,
       0,     0,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,  1677,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   164,     0,     0,     0,     0,
     165,   166,   167,   168,   169,     0,     0,    88,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   172,   451,     0,   453,   430,   174,     0,     0,
       0,     0,   294,     0,     0,     0,     0,   178,     0,     0,
     558,   109,   285,   111,     0,     0,     0,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   287,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,   288,     0,     0,   289,     0,     0,   290,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    56,
       0,     0,    59,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,  1736,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   161,   162,   163,   164,   430,  1632,   560,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   293,     0,     0,     0,   174,     0,     0,
       0,     0,   294,     0,   109,   285,   111,   178,     0,   295,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   287,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,   151,   152,   153,
       0,     0,   154,     0,   155,   156,   157,     0,     0,     0,
       0,     0,   158,   159,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   702,   428,   429,     0,
       0,     0,     0,   430,     0,   161,   162,   163,   164,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,     0,
      88,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,   293,     0,     0,     0,
     174,     0,     0,     0,     0,   294,     0,   109,   326,   111,
     178,     0,  1493,   112,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   560,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     151,   152,   153,     0,     0,   154,     0,   155,   156,   157,
       0,   109,   326,   111,     0,   158,   159,   112,   113,   114,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   152,   153,     0,     0,   154,
       0,   155,   156,   157,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   161,   162,
     163,   164,   430,     0,   648,     0,   165,   166,   167,   168,
     169,   170,     0,    88,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   173,
       0,     0,     0,   174,     0,     0,     0,     0,   294,     0,
       0,     0,     0,   178,     0,  1486,     0,     0,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   702,
     428,   429,   161,   162,   163,   164,   430,     0,     0,     0,
     165,   166,   167,   168,   169,   170,     0,    88,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   173,     0,     0,     0,   174,     0,     0,
       0,     0,   294,     0,   109,   285,   286,   178,     0,  1496,
     112,   113,   114,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   287,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   145,     0,
       0,     0,     0,   150,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,     0,     0,     0,
       0,     0,   158,     0,     0,     0,   288,     0,     0,   289,
       0,     0,   290,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,     0,     0,
       0,     0,    56,     0,     0,    59,     0,   657,    24,    25,
     658,    27,    28,   659,    30,   660,    32,     0,    33,     0,
       0,     0,     0,    38,    39,     0,    41,    42,    43,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   164,     0,
       0,     0,     0,   165,   166,   167,   168,   169,     0,     0,
      88,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,     0,     0,   172,   293,     0,     0,     0,
     174,     0,     0,     0,     0,   294,     0,   109,   285,  1349,
     178,     0,   295,   112,   113,   114,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     287,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   145,     0,     0,  1165,     0,   150,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
       0,     0,     0,     0,     0,   158,     0,     0,     0,   288,
       0,     0,   289,     0,     0,   290,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,    48,    49,    50,    51,
      52,     0,     0,     0,     0,    56,     0,     0,    59,     0,
     657,    24,    25,   658,    27,    28,   659,    30,   660,    32,
       0,    33,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   164,     0,     0,     0,     0,   165,   166,   167,   168,
     169,     0,     0,    88,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   172,   293,
       0,     0,     0,   174,     0,     0,     0,     0,   294,     0,
     109,   285,     0,   178,     0,  1350,   112,   113,   114,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   287,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   145,     0,     0,  1667,     0,   150,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     155,   156,   157,     0,     0,     0,     0,     0,   158,     0,
       0,     0,   288,     0,     0,   289,     0,     0,   290,     0,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,     0,     0,     0,     0,    56,     0,
       0,    59,     0,   657,    24,    25,   658,    27,    28,   659,
      30,   660,    32,     0,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   824,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   164,     0,     0,     0,   914,   165,
     166,   167,   168,   169,     0,     0,    88,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,   172,   293,     0,     0,     0,   174,     0,     0,     0,
       0,   294,     0,   109,   285,     0,   178,     0,   295,   112,
     113,   114,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   287,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   145,     0,     0,
    1738,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,     0,     0,     0,     0,
       0,   158,     0,     0,     0,   288,     0,     0,   289,     0,
       0,   290,     0,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,     0,     0,     0,
       0,    56,     0,     0,    59,     0,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,  1044,
       0,     0,     0,   430,   161,     0,     0,   164,     0,     0,
       0,     0,   165,   166,   167,   168,   169,     0,     0,    88,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   172,   451,     0,     0,   430,   174,
     809,     0,     0,     0,   294,   754,   109,   285,     0,   178,
       0,   554,   112,   113,   114,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   287,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     145,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,     0,
       0,     0,     0,     0,   158,     0,     0,     0,   288,     0,
       0,   289,     0,     0,   290,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,    56,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,  1224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     164,     0,     0,     0,     0,   165,   166,   167,   168,   169,
       0,     0,    88,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   172,   451,     0,
       0,   430,   174,     0,     0,     0,     0,   294,   691,   109,
     285,     0,   178,     0,   812,   112,   113,   114,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   287,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,     0,     0,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155,
     156,   157,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   288,     0,     0,   289,     0,     0,   290,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,     0,     0,     0,     0,    56,     0,     0,
      59,     0,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     161,     0,     0,   164,   430,     0,     0,     0,   165,   166,
     167,   168,   169,   911,     0,    88,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     172,   293,     0,     0,   430,   174,     0,     0,     0,     0,
     294,   754,   109,   285,     0,   178,     0,  1354,   112,   113,
     114,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   287,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   145,     0,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,     0,     0,     0,     0,     0,
     158,     0,     0,     0,   288,     0,     0,   289,     0,     0,
     290,     0,   291,   320,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
      56,     0,     0,    59,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,     0,     0,     0,   146,   147,   148,
     149,     0,     0,     0,     0,   151,   152,   153,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,     0,   161,     0,     0,   164,     0,     0,     0,
       0,   165,   166,   167,   168,   169,     0,     0,    88,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   507,  1466,     0,     0,   430,   174,     0,
       0,     0,     0,   509,   755,   109,   326,     0,   178,     0,
     252,   112,   113,   114,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,   162,   163,     0,   143,   144,   145,
       0,     0,     0,     0,   150,     0,   170,     0,     0,   171,
       0,     0,     0,     0,     0,   155,   156,   157,   109,   326,
     111,     0,     0,   158,   112,   113,   114,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   151,   152,   153,     0,     0,   154,     0,   155,   156,
     157,     0,     0,     0,     0,     0,   158,   159,     0,     0,
       0,     0,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   161,     0,     0,   164,
     430,     0,     0,     0,   165,   166,   167,   168,   169,   962,
       0,    88,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   507,   508,     0,     0,
     430,   174,     0,     0,     0,     0,   509,  1446,     0,  1447,
       0,   178,     0,   252,     0,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   161,
     162,   163,   164,   430,     0,   701,     0,   165,   166,   167,
     168,   169,   170,     0,    88,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     173,     0,     0,     0,   174,   109,   285,     0,     0,   294,
       0,   112,   113,   114,   178,     0,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   287,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   145,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,     0,     0,
       0,     0,     0,   158,     0,     0,     0,   288,     0,     0,
     289,     0,     0,   290,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,     0,
       0,     0,     0,    56,     0,     0,    59,     0,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
      -4,     1,     0,  1481,    -4,  1482,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,   161,     0,     0,   164,
       0,     0,     0,     0,   165,   166,   167,   168,   169,     0,
       0,    88,     0,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,   172,   451,     0,     0,
       0,   174,     0,    -4,    -4,    -4,   294,     0,     0,    -4,
      -4,   178,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,    -4,     6,     0,     0,     0,     0,    -4,     0,
       0,     7,     8,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     9,    10,    -4,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,    16,     0,     0,     0,    17,    18,     0,    19,    20,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,    65,     0,     0,
       7,     8,    66,    67,    68,    69,   111,     0,    70,     0,
      71,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,    87,    88,     0,
     137,   138,   139,   140,   141,   142,     0,     0,     0,   146,
     147,   148,   149,     0,     0,     0,     0,   151,   152,   153,
       0,     0,   154,   657,    24,    25,   658,    27,    28,   659,
      30,   660,    32,   159,    33,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,     0,     0,    46,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1600,     0,  1601,     0,     0,     0,
       0,     0,    67,    68,    69,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,  1015,     0,     0,     0,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   170,     0,
       0,   171,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1035,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1065,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1169,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1444,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1463,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1518,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1519,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1520,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1521,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1522,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1554,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1616,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1626,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1627,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1655,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1658,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1661,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1688,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1695,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1730,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1732,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1734,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1752,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1778,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1816,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,  1817,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,  1821,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
       0,     0,     0,     0,     0,  1822,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,  1823,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,  1824,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,   585,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,     0,   747,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,  1530,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,   821,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,   856,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
     864,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,   865,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,   866,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,   877,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,   997,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
     998,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,   999,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1030,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1121,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1167,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1168,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1223,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1362,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1363,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1364,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1365,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1402,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1403,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1410,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1555,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1556,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1557,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1558,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1574,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1575,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1579,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1673,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1674,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1675,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1676,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1683,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1686,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1726,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1743,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1744,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1745,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,  1746,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,     0,
       0,     0,  1789,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,  1790,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,     0,     0,     0,  1791,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,     0,     0,     0,
    1792,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   411,     0,   412,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,   649,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,   826,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,   835,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,   843,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,   927,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,     0,
       0,  1023,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,     0,     0,  1024,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,     0,     0,  1028,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,     0,     0,
    1029,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,     0,     0,  1031,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,     0,     0,  1068,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,     0,     0,  1116,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
       0,     0,  1359,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,     0,     0,  1393,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,     0,     0,  1543,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,   705,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
     706,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   708,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,   710,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,   711,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,   714,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,   715,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   809,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,   817,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,   818,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,   819,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
     825,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   834,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,   842,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,   926,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,   951,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,   956,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,   961,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,   964,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,   965,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,   971,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
     980,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,   981,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,   982,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,  1014,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,     0,     0,
       0,     0,   430,     0,  1016,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,     0,
       0,     0,     0,   430,     0,  1017,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
       0,     0,     0,     0,   430,     0,  1018,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,     0,     0,     0,     0,   430,     0,  1022,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,     0,     0,     0,     0,   430,     0,  1256,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,     0,     0,     0,     0,   430,     0,  1445,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,     0,     0,     0,     0,   430,     0,
    1462,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,     0,     0,     0,     0,   430,
       0,  1485,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,     0,     0,     0,     0,
     430,     0,  1682,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,     0,     0,     0,
       0,   430,     0,  1750
};

static const yytype_int16 yycheck[] =
{
       3,   245,   260,     5,   372,   108,   374,   501,   502,  1352,
       3,     5,     4,   195,   272,     6,     4,   385,   200,     6,
       6,     4,   402,     4,     6,     5,     4,     6,     5,     5,
     190,   191,     4,     6,   414,     4,     4,     4,   198,     4,
       4,     4,     4,   194,     5,   196,     5,     5,     5,    49,
      50,     6,    52,     6,    57,     5,   194,     6,     6,     0,
       4,  1013,    65,   201,     7,   323,  1009,   325,     6,     6,
       6,     6,     4,    13,     6,   139,    79,   184,   185,     6,
     184,   185,  1425,   184,   185,    98,   184,   185,   152,   153,
     184,   185,   194,   200,   194,   202,   109,   201,     3,   201,
     201,     6,   200,    75,   117,   118,   119,    79,   202,   195,
     123,   124,   125,   126,   200,     7,   225,   226,   227,    91,
     194,   230,   231,   232,   194,   194,     4,   184,   185,   184,
     185,   201,   201,   184,   185,     4,    81,   194,    83,     7,
     142,    79,    80,    75,   201,   200,   129,   130,   131,   132,
     201,    81,    57,     7,   127,     6,   148,   266,   267,     6,
     184,   185,   142,   184,   185,   142,   142,   195,  1511,   197,
     151,   280,   281,   201,    79,   178,   200,   169,   202,   200,
       7,   202,   197,     6,  1527,   200,   179,   190,   191,   202,
     127,   127,   127,   184,   185,   198,   182,   184,   185,   201,
     182,     7,   169,   206,   200,   208,   202,   201,   196,   201,
     213,   190,   191,   593,   217,   203,   194,   220,   196,   202,
     198,   224,   225,   226,   227,   203,   194,   230,   231,   232,
     194,     6,   201,   201,   492,   493,   201,   201,   201,   201,
     201,   244,   201,   201,   201,   194,   201,  1190,   248,   249,
     194,   201,   201,   201,   512,   198,   256,   184,   185,    85,
     260,   139,   140,   266,   267,   268,     7,   205,   648,   649,
     139,   140,   200,   178,   202,   184,   185,   280,   281,   171,
     172,   173,   174,   102,   103,   190,   191,   190,   191,   108,
     293,   200,   295,   198,   184,   185,   184,   185,   201,   402,
     196,   206,   198,   171,   172,   173,   174,   203,   184,   185,
     200,   195,   200,   197,   572,   194,   200,   171,   172,   173,
     174,     4,   190,   191,   200,     6,   329,   585,   331,   332,
     198,    78,   184,   185,    81,   336,   190,   191,   184,   185,
     196,   344,  1685,     8,   171,   172,   173,   174,   200,     6,
     329,   190,   191,    75,   200,    78,    78,   194,    81,    81,
      83,    83,   201,   190,   191,   171,   172,   173,   174,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   196,   382,
     383,   384,   385,   386,   190,   191,   194,   390,   391,   392,
     393,   394,    78,   396,   373,    81,   375,   376,   377,   337,
     379,   380,     8,   382,   383,   384,   194,   386,   196,   194,
     413,   390,   391,   392,   393,   203,   184,   185,   194,   102,
     103,   104,   105,    75,   329,   195,    78,   197,   111,    81,
     200,   114,   200,  1776,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   451,   194,
     388,   196,   193,   198,   834,   835,   201,   395,   203,   102,
     103,     7,   190,   191,   200,   108,   202,   372,   373,   374,
     375,   376,   377,   201,   379,   380,   194,   382,   383,   384,
     385,   386,   194,   486,   487,   390,   391,   392,   393,   394,
      81,   396,   750,   194,   194,   196,   196,   600,   198,   499,
     500,   195,   203,   203,     8,    81,   200,   507,   501,   502,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   201,   528,   529,   530,   193,    98,
     195,   184,   185,   195,   200,   197,   202,   540,   539,   201,
     109,   479,   480,   481,   482,   648,   649,   200,   117,   118,
     119,   554,   184,   185,   123,   124,   125,   126,   561,    75,
       6,   195,    78,   197,   565,    81,   200,    83,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   184,   185,    81,  1538,   193,  1540,   592,
    1542,   195,   972,   197,   974,    81,   976,   201,   978,   200,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,    83,   613,   614,   615,   616,   617,   618,   619,   200,
     194,   202,   623,   624,   625,   171,   172,   173,   174,   200,
      78,   202,   633,   634,   635,   540,   637,   184,   185,   184,
     185,   184,   185,   644,   190,   191,    75,   184,   185,    78,
     184,   185,    81,   200,   655,   200,   194,   200,   196,   201,
     904,  1604,   665,   200,  1607,   203,   200,  1610,   195,   201,
     197,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   688,    81,   690,   791,   193,
     693,   184,   185,   696,   197,   698,    78,   200,   202,   702,
     703,   184,   185,    78,   184,   185,    81,   200,    83,  1089,
     184,   185,   650,   195,   693,   197,  1668,   200,   200,   698,
     200,    78,    98,   726,     4,  1105,   200,   190,   191,   184,
     185,   834,   835,   109,   200,   200,   202,   202,    81,   842,
     843,   117,   118,   119,   747,   200,     8,   123,   124,   125,
     126,     4,   195,   753,   197,   184,   185,     4,   201,   195,
     760,   197,   700,   194,   200,   194,   766,  1710,   186,   187,
     188,   195,   201,   195,     4,   193,   200,  1729,   200,  1731,
     195,  1733,   184,   185,   200,   200,   202,  1739,   693,   792,
     195,   696,   195,   698,   200,   200,   202,   200,   801,   200,
     803,   202,   805,   200,   807,   202,   200,   194,   202,   812,
       6,     7,   815,  1756,   194,   200,  1759,   202,    81,  1762,
      83,   194,  1765,   926,   927,    81,   202,    83,     6,   832,
    1782,     6,  1784,     6,  1786,   838,  1330,  1331,     6,     7,
     843,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,  1096,     7,   196,  1235,   193,    98,  1801,   200,
    1803,   202,  1805,   194,   843,   868,   196,   200,   109,   202,
     873,   874,   875,   876,   194,   194,   117,   118,   119,   200,
     194,   202,   123,   124,   125,   126,   889,   194,   194,   184,
     185,   186,   187,   188,   873,   194,   875,   876,   193,   200,
     200,   202,   202,   194,   907,   908,   909,   910,   194,   194,
     889,   912,   194,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   196,  1031,   932,
     200,   193,   202,   200,   200,   202,   202,   194,   843,   877,
     202,   201,   943,   944,     6,   945,   949,   950,   200,   952,
     202,   954,   955,   932,    98,   958,   959,   200,     6,   202,
     963,   202,   200,   194,   202,   109,   201,   200,   873,   202,
     875,   876,   194,   117,   118,   119,   200,     4,   202,   123,
     124,   125,   126,   200,   889,   202,  1089,   200,     4,   202,
       6,   200,   200,   202,   202,   194,   201,   997,   998,   999,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   200,    98,   202,   200,   193,   202,
     200,   203,   202,  1267,   194,   194,   109,   932,   200,   200,
     202,   202,   194,   194,   117,   118,   119,   194,   194,  1533,
     123,   124,   125,   126,  1047,  1048,  1049,   194,   194,     4,
       5,   200,   200,   202,   202,  1058,   194,   200,   202,   202,
     200,   200,   202,   202,   200,  1066,   202,   200,   200,   202,
     202,   201,  1073,  1074,  1075,  1076,  1077,   200,   200,   202,
     202,   194,  1083,  1084,    39,    40,    41,    42,    43,    44,
     200,   194,   202,    48,    49,    50,    51,    12,    13,   201,
     201,    56,    57,    58,    98,   200,    61,   202,  1111,   200,
     200,   202,   202,   201,   200,   109,   202,    72,   200,   202,
     202,   201,   201,   117,   118,   119,   194,  1130,  1496,   123,
     124,   125,   126,  1136,   200,  1238,   202,   194,   194,  1142,
       6,  1144,  1145,   196,     6,     6,  1149,  1150,     6,  1152,
     201,  1154,   201,  1156,   201,  1158,  1159,  1160,   196,   196,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     196,    86,   196,  1176,   142,   198,    91,    92,   203,    94,
      95,    96,   201,     6,  1122,   100,     6,     6,  1191,  1189,
       6,   201,  1195,     6,  1197,   196,     4,   193,   198,   201,
     155,   156,     7,   202,     7,    98,  1207,   200,   202,   200,
       6,     6,   167,     6,   169,   170,   109,  1218,     7,   134,
     135,   136,     7,   195,   117,   118,   119,    98,     6,     6,
     123,   124,   125,   126,   201,   190,   191,     7,   109,     7,
       6,     6,  1245,   198,     6,     4,   117,   118,   119,    53,
     139,    53,   123,   124,   125,   126,    53,  1360,  1502,    53,
     201,     4,     5,   197,   195,    98,  1245,     6,     6,   195,
    1273,   195,   200,   200,   195,   200,   109,   200,   200,   195,
    1283,   195,     6,  1286,   117,   118,   119,   202,   197,  1547,
     123,   124,   125,   126,  1294,     6,    39,    40,    41,    42,
      43,    44,     4,     4,  1283,    48,    49,    50,    51,   202,
       6,  1249,     6,    56,    57,    58,     6,     6,    61,  1322,
    1323,  1259,     7,   201,   142,     7,     7,     7,   142,    72,
       7,   202,  1332,     7,  1334,   142,  1336,  1330,  1331,     7,
    1245,     7,     4,     6,   195,   200,   195,  1350,  1286,  1352,
    1350,  1354,   200,  1353,  1354,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   195,   200,  1369,   195,   193,   202,
     200,   198,     6,  1376,     7,     7,   202,  1380,  1283,     7,
     202,  1384,  1383,     6,   201,   197,   201,     6,  1326,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,  1404,   201,   201,     6,   193,     6,   198,     6,   201,
       6,  1669,   155,   156,    98,     7,   196,     6,     6,   194,
     194,     6,  1425,     7,   167,   109,   169,   170,   201,   182,
       7,    12,    13,   117,   118,   119,     7,  1375,    83,   123,
     124,   125,   126,     7,     7,     7,  1384,  1385,  1386,     7,
       6,   201,     7,     7,     7,     7,     7,     7,  1461,     4,
       4,   194,     4,  1466,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     6,     6,
     201,     7,   193,  1486,     6,   202,     7,     7,     7,     6,
    1493,     6,     6,  1496,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     6,    86,    81,     6,  1511,     4,
      91,    92,     4,    94,    95,    96,     6,     6,   202,   100,
       6,     6,     4,     6,  1527,   200,     6,  1530,   195,   200,
     195,   195,     7,   194,    12,    13,   195,  1537,   198,  1539,
    1533,  1541,   198,  1546,   201,     6,     6,     6,  1551,  1549,
       6,     6,  1552,   134,   135,   136,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     201,   201,     6,    91,   193,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   201,
    1593,  1496,  1592,   193,   201,     6,  1596,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     6,    86,  1612,
     201,     6,     6,    91,    92,     5,    94,    95,    96,     4,
       6,   202,   100,   201,   196,   201,     7,   201,   201,     6,
      86,    87,     6,     6,     6,   201,   201,     4,     6,     5,
     201,     6,   138,     6,     6,  1645,     4,     6,     4,  1649,
       7,   200,     6,     6,     6,     6,   134,   135,   136,     6,
      98,     6,     4,     6,   201,     6,     6,  1670,     6,  1672,
       6,   109,  1672,     6,   142,     6,     6,     6,     6,   117,
     118,   119,  1685,     6,     6,   123,   124,   125,   126,     6,
       6,     6,     6,     6,  1632,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   200,
       6,     6,     6,   193,     6,    98,   172,   173,   174,   175,
     176,   195,     6,     6,   202,   198,   109,  1727,  1728,     6,
     201,     6,     5,   189,   117,   118,   119,   193,  1741,     6,
     123,   124,   125,   126,    79,     6,  1749,   201,   201,     6,
     202,   207,   208,   209,   210,   202,   212,   213,   214,   215,
     201,   217,   218,   219,   202,     6,   201,     7,   224,   201,
    1749,   201,     6,  1776,     6,   202,   137,     6,     6,     6,
      98,     6,  1720,     6,     6,   140,   242,     6,     6,   201,
    1793,   109,  1795,     6,     6,   251,   252,     6,     6,   117,
     118,   119,     6,   201,   260,   123,   124,   125,   126,   201,
       6,     6,   201,   201,  1793,   202,  1795,     6,    98,   202,
       6,   201,  1825,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   293,   294,   295,
       6,   193,     6,     6,  1749,     6,  1825,     6,     6,   305,
     306,   307,     6,   309,     6,     6,   312,   313,   202,     6,
     316,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   201,   201,   333,   334,   193,
     201,     6,   201,     6,   202,     6,     6,     6,  1793,     6,
    1795,   347,   348,   201,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,     6,     6,     6,   201,
    1825,     6,   201,   201,     6,   381,     6,   201,     6,     6,
       6,   387,     6,   389,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,  1635,     6,
       6,     6,   193,     6,   410,  1119,  1516,   413,  1517,   447,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,     3,  1129,   433,   434,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     3,  1529,   451,   477,   193,  1263,    -1,
      -1,   457,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,
      -1,   467,   468,    -1,    -1,    -1,    -1,   473,   474,    -1,
      -1,    -1,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,   505,
     506,   507,   508,   509,    -1,    -1,    -1,   513,   514,   515,
     516,   517,    -1,    -1,    -1,   521,    -1,   523,   524,    -1,
      -1,    -1,   528,   529,   530,    -1,    -1,   533,   534,   535,
     536,   537,    -1,    -1,    -1,     4,     5,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,   560,   561,    -1,   563,   564,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,   583,    -1,    48,
      49,    50,    51,    -1,    -1,   591,   592,    56,    57,    58,
      -1,   597,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    72,    -1,   213,    -1,    -1,    -1,   217,
      -1,    -1,     3,     4,     5,    -1,   224,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   651,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,   685,
      71,    72,   688,    -1,   690,   691,   155,   156,    -1,    -1,
      -1,    -1,    -1,   699,    -1,    -1,   702,   703,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   725,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   747,    -1,    -1,    -1,    -1,    -1,    -1,   754,   755,
      -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   773,    -1,    -1,
     776,   162,   163,   164,   165,   166,   167,    -1,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,   801,    -1,   803,   189,   805,
      -1,   807,    -1,   194,    -1,   413,   812,    -1,   199,   815,
     201,    -1,   107,    -1,    -1,   821,    -1,   823,   824,    -1,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
     856,   146,   147,   148,   149,    98,    -1,   152,   864,   865,
     866,    -1,   868,   158,   159,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,   487,
     886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   894,    -1,
      -1,   897,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,   907,   908,   909,   910,   220,    -1,    -1,   914,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,   529,   530,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      12,    13,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   554,    -1,    -1,    -1,
     193,    -1,    -1,   268,    -1,    -1,    -1,   963,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   973,    -1,   975,
      -1,   977,    -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    -1,    -1,   302,    -1,    91,
      92,    -1,    94,    95,    96,    -1,   331,   332,   100,    -1,
      -1,  1027,    -1,    -1,  1030,    -1,    -1,    -1,  1034,   344,
    1036,  1037,  1038,    -1,    -1,    -1,    -1,    -1,  1044,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,  1061,    -1,  1063,    12,    13,
      -1,    -1,    -1,   378,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
     688,    -1,   690,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1097,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,  1109,  1110,    -1,    -1,   213,    -1,    -1,
     405,   217,    -1,    -1,    -1,  1121,  1122,    -1,   224,    -1,
     202,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,   747,
      94,    95,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    -1,
    1166,  1167,  1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1176,    -1,  1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,  1189,   792,    -1,    -1,   293,    -1,   295,
      -1,  1197,    -1,   801,    -1,   803,    -1,   805,    -1,   807,
      -1,    -1,    -1,    -1,   812,    -1,    -1,   815,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,  1223,  1224,  1225,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,  1260,    -1,     6,    -1,    -1,    -1,
     868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,
      -1,    -1,    -1,  1279,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,  1292,  1293,    -1,    -1,
      -1,    -1,     6,  1299,  1300,    -1,    -1,    -1,  1304,   907,
     908,   909,   910,    -1,    -1,    -1,  1312,   413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1322,  1323,  1324,    -1,
    1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1350,   451,    -1,   202,  1354,    -1,
     665,  1357,    -1,    -1,    -1,   963,  1362,  1363,  1364,  1365,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1375,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,
     486,   487,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,  1402,  1403,    -1,    -1,
     193,    -1,    -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,
      -1,   726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,   529,   530,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
    1446,    -1,    -1,   193,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,  1464,    -1,
    1466,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,  1481,    -1,  1483,    -1,   193,
    1486,    -1,    -1,    -1,    -1,    -1,   592,  1493,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1507,    -1,    -1,    -1,    -1,  1512,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,    -1,    -1,
      -1,    -1,    -1,   838,  1530,    -1,    -1,    -1,    -1,    -1,
      -1,  1537,    -1,  1539,    -1,  1541,    -1,    -1,    -1,    12,
      13,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,  1555,
    1556,  1557,  1558,  1559,    -1,    -1,    -1,    -1,    -1,   874,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1574,  1575,
      -1,    -1,    -1,  1579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   688,  1589,   690,    -1,    -1,    -1,    -1,  1197,
      -1,    -1,    -1,    -1,  1600,    -1,   702,   703,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,
      -1,    94,    95,    96,  1630,    -1,    -1,   100,    -1,  1635,
      -1,    -1,    -1,    -1,   949,   950,  1642,   952,    -1,   954,
     955,   747,    -1,   958,   959,    -1,    -1,    -1,    -1,    -1,
    1656,    -1,    -1,  1659,    -1,    -1,  1662,    -1,    -1,    -1,
    1666,   134,   135,   136,  1670,    -1,  1672,  1673,  1674,  1675,
    1676,    -1,    -1,    -1,    -1,    -1,    -1,  1683,    -1,    -1,
    1686,    -1,    -1,    -1,    12,    13,   792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   801,    -1,   803,    -1,   805,
      -1,   807,    -1,    -1,    -1,    -1,   812,    -1,    -1,   815,
      -1,    -1,    -1,    -1,  1322,  1323,    -1,    -1,    -1,    -1,
    1726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,  1047,  1048,  1049,  1741,    -1,  1743,  1744,  1745,
    1746,    -1,    -1,  1058,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,   868,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,  1779,  1780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1789,  1790,  1791,  1792,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1111,    -1,    -1,    -1,
      -1,   907,   908,   909,   910,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,  1130,    -1,    -1,    -1,    -1,
      -1,  1136,    -1,    -1,    -1,    -1,    -1,  1142,    -1,  1144,
    1145,    -1,    -1,    -1,  1149,  1150,    -1,  1152,    -1,  1154,
      -1,  1156,    -1,  1158,  1159,  1160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   963,    -1,    -1,
      -1,  1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,  1191,    -1,  1486,    -1,
    1195,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,  1530,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1551,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,  1273,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,  1286,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    -1,    -1,   154,  1352,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,
      -1,   169,    -1,    -1,  1369,    -1,    -1,    -1,    -1,    -1,
      -1,  1376,  1670,    -1,  1672,  1380,   184,   185,    -1,  1384,
      -1,   189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   199,    -1,   201,    -1,    -1,    -1,    -1,    -1,  1404,
      -1,  1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
    1425,    -1,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,  1461,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,    -1,   201,
      -1,   203,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,  1511,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,  1527,    -1,    -1,    -1,  1322,  1323,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,  1546,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,  1350,     9,    10,    11,  1354,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,  1593,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,   154,    78,    -1,   157,    81,    -1,    83,
      -1,   162,   163,   164,   165,   166,    -1,    -1,   169,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   184,   185,    -1,    -1,   111,   189,    -1,
     114,    -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,
    1466,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1685,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1486,    -1,    -1,    -1,    -1,    -1,    -1,  1493,    -1,    -1,
     154,    -1,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,     6,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   185,    -1,    -1,  1530,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,     6,
      -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,  1776,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,    -1,  1670,    -1,  1672,    -1,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,   157,    -1,    -1,    -1,    -1,
     162,   163,   164,   165,   166,    -1,    -1,   169,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   184,   185,    -1,  1741,   193,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,   199,    -1,    -1,
     202,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,     6,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   154,   155,   156,   157,   193,     7,     8,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,   194,    -1,     3,     4,     5,   199,    -1,   201,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   114,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,    -1,
     169,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   194,    -1,     3,     4,     5,
     199,    -1,   201,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,     8,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    63,    64,    65,
      -1,     3,     4,     5,    -1,    71,    72,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   154,   155,
     156,   157,   193,    -1,   195,    -1,   162,   163,   164,   165,
     166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,   201,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   154,   155,   156,   157,   193,    -1,    -1,    -1,
     162,   163,   164,   165,   166,   167,    -1,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,
      -1,    -1,   194,    -1,     3,     4,     5,   199,    -1,   201,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    52,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,   114,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,    -1,
     169,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   194,    -1,     3,     4,     5,
     199,    -1,   201,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    -1,   202,    -1,    52,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    92,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,    -1,
       3,     4,    -1,   199,    -1,   201,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,   202,    -1,    52,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,   111,    -1,
      -1,   114,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,    -1,   157,    -1,    -1,    -1,     8,   162,
     163,   164,   165,   166,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   185,    -1,    -1,    -1,   189,    -1,    -1,    -1,
      -1,   194,    -1,     3,     4,    -1,   199,    -1,   201,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
     202,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,   114,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     8,
      -1,    -1,    -1,   193,   154,    -1,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,   165,   166,    -1,    -1,   169,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   184,   185,    -1,    -1,   193,   189,
     195,    -1,    -1,    -1,   194,   200,     3,     4,    -1,   199,
      -1,   201,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
      -1,    -1,   169,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   184,   185,    -1,
      -1,   193,   189,    -1,    -1,    -1,    -1,   194,   200,     3,
       4,    -1,   199,    -1,   201,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,
     114,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     154,    -1,    -1,   157,   193,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   202,    -1,   169,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     184,   185,    -1,    -1,   193,   189,    -1,    -1,    -1,    -1,
     194,   200,     3,     4,    -1,   199,    -1,   201,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      81,    -1,    83,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,   154,    -1,    -1,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,    -1,    -1,   169,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   184,   185,    -1,    -1,   193,   189,    -1,
      -1,    -1,    -1,   194,   200,     3,     4,    -1,   199,    -1,
     201,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,   167,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,     3,     4,
       5,    -1,    -1,    71,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   154,    -1,    -1,   157,
     193,    -1,    -1,    -1,   162,   163,   164,   165,   166,   202,
      -1,   169,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   184,   185,    -1,    -1,
     193,   189,    -1,    -1,    -1,    -1,   194,   200,    -1,   202,
      -1,   199,    -1,   201,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   154,
     155,   156,   157,   193,    -1,   195,    -1,   162,   163,   164,
     165,   166,   167,    -1,   169,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     185,    -1,    -1,    -1,   189,     3,     4,    -1,    -1,   194,
      -1,     9,    10,    11,   199,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
       0,     1,    -1,   200,     4,   202,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,   154,    -1,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,    -1,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,
      -1,   189,    -1,    53,    54,    55,   194,    -1,    -1,    59,
      60,   199,    62,    -1,    -1,    -1,    66,    67,    -1,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
     120,   121,   122,     4,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    12,    13,   133,   134,   135,   136,    -1,    -1,   139,
      -1,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    -1,    -1,    37,    38,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
      -1,    -1,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    66,    67,    -1,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,    -1,    -1,    -1,   120,
     121,   122,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      12,    13,   133,   134,   135,   136,     5,    -1,   139,    -1,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    72,    86,    -1,    -1,    -1,    -1,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,   202,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   155,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,   170,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,   197,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   197,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,   197,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
     197,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,   197,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
      -1,    -1,   197,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,   197,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,   195,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,   195,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,
     195,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,   193,
      -1,   195,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
     193,    -1,   195,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,   195
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   205,   206,     6,     0,     4,    12,    13,    37,
      38,    53,    54,    55,    59,    60,    62,    66,    67,    69,
      70,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   109,   110,   111,   112,   113,   114,
     115,   116,   120,   121,   122,   128,   133,   134,   135,   136,
     139,   141,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   158,   159,   160,   161,   168,   169,   207,
     209,   210,   230,   247,   248,   251,   252,   253,   254,   255,
     256,   257,   258,   279,   280,   281,   282,   300,   301,     3,
       4,     5,     9,    10,    11,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    56,    57,    58,    61,    63,    64,    65,    71,    72,
     148,   154,   155,   156,   157,   162,   163,   164,   165,   166,
     167,   170,   184,   185,   189,   194,   196,   198,   199,   201,
     203,   228,   283,   284,   296,   297,   300,   301,    13,    81,
     194,   194,     6,   201,     6,     6,     6,     6,   194,     6,
       6,   196,   196,   194,   196,   228,   228,   194,   201,   194,
     194,     4,   194,   201,   194,   194,     4,   201,   194,   194,
      85,    81,    81,     6,   201,    75,    78,    81,    81,    81,
      78,    81,    83,    83,    75,    78,    81,    83,    78,    81,
      83,    78,    81,   194,    78,   139,   152,   153,   201,   184,
     185,   194,   201,   286,   287,   286,   201,    75,    78,    81,
     201,   286,     4,    75,    79,    91,    81,    83,    81,    78,
       4,   148,   201,   300,   301,     4,     6,    75,    78,    81,
      78,    81,     4,     4,     4,     4,     5,    36,    75,    78,
      81,    83,    95,   185,   194,   201,   248,   258,   283,   289,
     290,   291,   300,   301,     4,   194,   194,   194,     4,   201,
     293,     4,   194,   194,     6,     6,   196,     4,   297,   301,
       4,   297,     5,   201,     5,   201,     4,   283,   283,   196,
       6,   194,   201,   194,   196,   203,   228,     7,   171,   172,
     173,   174,   190,   191,   226,   227,     4,   194,   196,   198,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   194,   194,   194,   194,   194,
     194,   228,   228,   228,   228,   194,   228,   228,   228,     7,
     194,   194,   194,   228,   194,   194,   196,   283,   283,   283,
     283,   283,     4,   139,   140,   301,     4,   248,   249,   250,
     201,   195,   197,   201,   229,     6,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     193,   201,     6,   194,   196,   227,     6,   283,     4,   296,
     297,   301,   296,   283,   296,   299,   232,   235,   297,   301,
     283,   185,   283,   291,   292,   283,   283,   194,   283,   292,
     283,   283,   194,   292,   283,   283,   289,   194,   201,   292,
     290,   290,   290,   194,   194,   290,   290,   290,   194,   194,
     194,   194,   194,   194,   194,   194,   201,   201,   283,     4,
     289,   293,   201,   201,   286,   286,   286,   283,   283,   184,
     185,   201,   201,   286,   201,   201,   201,   184,   185,   194,
     250,   286,   201,   194,   201,   194,   194,   194,   290,   290,
     289,   194,     4,   196,   196,   250,     6,     6,   201,   201,
     201,   290,   290,   196,   196,   196,   194,   196,   198,   228,
     196,     5,   142,   201,     5,   142,     5,   142,     5,   142,
      75,    78,    81,    83,   201,   283,   291,   283,   202,   292,
       8,   186,     6,   194,   196,   228,     6,   283,   283,   283,
     198,   283,   201,   142,   283,   283,   283,     6,     6,     6,
     250,     6,   250,   196,     6,   201,   296,   289,   289,   283,
     283,   201,   201,   229,   297,   289,     6,   196,   283,   283,
       4,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   299,   296,   299,   296,   296,   296,   289,
     296,   296,   283,   296,   296,   296,   299,   296,   283,   297,
     283,   296,   296,   296,   296,   301,   297,   301,   195,   197,
       7,   226,   227,   198,     7,   228,   202,    75,    78,    81,
      83,   247,   283,   292,     7,   226,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   211,   283,   283,     6,   196,   198,   195,   200,   195,
     200,   200,   195,   200,   197,   200,   231,   197,   231,   200,
     200,   195,   186,   200,   202,   195,   195,   283,   195,   202,
     195,   195,   283,   202,   195,   195,     7,   283,   283,   202,
       6,     6,     6,   283,   283,     7,     7,   276,   276,   283,
     241,   283,   297,   242,   283,   297,   243,   283,   297,   244,
     283,   297,   283,   283,   283,   292,   292,   201,   195,     6,
     201,   250,   250,   200,   200,   200,   286,   286,   249,   249,
     200,   283,   283,   283,   283,   262,   200,   250,   283,   283,
     283,   283,   283,     7,   277,     6,     7,   283,     6,   283,
     283,   202,   292,   292,   292,     6,     6,   283,   283,   283,
     283,     4,   201,   229,   301,    53,   283,    53,    53,    53,
       5,   201,     5,   201,     5,   201,     5,   201,   292,   195,
     202,   283,   201,   283,   291,   201,   229,   195,   195,   195,
     139,   200,   250,   201,     8,   195,   197,   202,   202,   250,
     197,   195,   200,   202,   195,   197,   283,   292,   226,     6,
       6,   283,   195,   197,   227,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   200,   229,   229,   229,
     229,   229,   229,   229,   200,   200,   200,   229,   200,   229,
     229,   195,   195,   200,   200,   200,   200,   200,   229,   229,
     229,   195,   229,   285,   298,     6,   200,   195,   195,   200,
     229,   195,   195,   197,   226,   227,   198,   226,   227,   297,
     283,     6,     4,     4,   201,   294,   229,   201,   201,   201,
     201,   202,   202,   289,     8,     4,   129,   130,   131,   132,
     202,   214,   218,   221,   223,   224,   195,   197,   283,     4,
       6,   182,   208,   292,     6,   292,   283,     6,   296,     6,
     301,     6,   296,   283,   297,     7,   283,   291,   142,     7,
       7,   195,     7,   142,     7,     7,   195,   142,     7,     7,
     283,   195,   202,   201,   195,   195,   283,   289,     4,   275,
       6,   195,   195,   200,   195,   200,   195,   200,   195,   200,
     195,   195,   195,   202,   202,   292,   198,   250,   202,   202,
     286,   283,   283,   202,   202,   283,   286,   200,   200,   200,
      98,   109,   117,   118,   119,   123,   124,   125,   126,   272,
     273,   286,   202,   259,   195,   202,   195,   195,   195,   283,
       6,   283,   195,   197,   197,   202,   202,   202,   197,   197,
     200,   197,   292,   197,   201,   202,   201,   201,   201,   292,
     292,   292,   292,   202,     8,   292,   292,     7,     7,     7,
     198,   283,   202,   283,   283,     7,   198,   202,   201,   289,
       6,   226,   227,   226,   227,   202,   202,   289,   197,   227,
     198,   227,   296,   283,   283,   283,   283,   292,   296,   289,
     296,   296,   297,   237,   239,   283,   296,   283,     6,     4,
     139,   140,   283,     6,     6,     6,     7,   196,   293,   295,
       6,   292,   292,   292,   292,   229,     6,   283,   215,   194,
     194,   201,   225,     6,   227,   227,   197,   182,   296,   195,
     195,   200,     7,   229,   229,   286,    81,    83,   289,   289,
       7,   289,    81,    83,   289,   289,     7,    83,   289,   289,
       6,     7,     7,   292,     7,     7,    98,   274,     6,     7,
     226,   283,   226,   283,   226,   283,   226,   283,     7,     7,
       7,     7,     7,   202,     4,   202,   200,   200,   200,   202,
     202,   286,   286,   286,     4,     6,   201,     6,   194,     6,
     127,     6,   127,     6,   127,     6,   127,   202,   273,   200,
     272,     7,     6,     7,     7,     7,     6,   201,     6,     6,
       6,    81,   283,     6,     6,   283,   198,   202,   283,   283,
     283,   283,   202,   202,   202,   202,   283,   202,   202,   289,
     289,   289,     4,   200,     8,     8,   195,     4,     4,   289,
     202,   283,     6,   283,     6,   229,     6,     6,     4,     6,
     229,   229,   229,   229,   229,   200,   195,   195,   195,   200,
     200,   229,   238,   200,   229,   240,   195,   195,     6,     7,
     226,   227,   198,     7,     6,   293,   283,   200,   202,   202,
     202,   202,   202,   226,   194,   283,   283,   288,   289,   201,
     198,     6,     6,   208,     6,   283,   201,   283,   297,     6,
       6,     6,   201,   201,    91,   246,   246,   289,     6,   201,
     201,     6,     6,   289,   201,     6,     6,     5,   289,   202,
     289,   289,     4,     6,   289,   289,   289,   289,   289,   289,
     289,   289,   201,   201,     7,     6,     7,   283,   283,   283,
     201,   201,   200,   202,   200,   202,   200,   202,   196,   283,
     289,   283,     6,     6,     6,     6,   283,   286,   202,     5,
     201,   289,   201,   201,   201,   289,   292,   201,     6,   197,
       4,   229,   200,   200,   200,   200,   229,     6,     6,   138,
     283,   283,   283,     6,     6,     7,   200,     6,     6,     6,
     226,   227,   296,   297,     4,     4,   151,   297,   283,     6,
       4,   294,     6,   197,   293,     6,     6,     6,     6,   289,
     212,   283,   200,   200,   200,   202,   213,   283,     4,   296,
     200,   289,   297,   283,   283,   286,     6,     6,     6,   283,
     283,     6,   283,     5,     6,   201,     6,   142,   245,   283,
       6,     6,     6,     6,     6,     6,     4,     6,     6,   292,
     292,   283,   283,   297,   202,   195,   200,   202,   249,   249,
     286,     6,   263,   286,     6,   264,   286,     6,   265,   283,
     202,   200,   195,   202,   200,     6,   185,   286,     6,   288,
     286,   286,     6,   202,   283,     6,   283,   283,   283,   283,
     289,   200,   202,     8,   202,   195,   201,   283,   297,   289,
     289,   195,   229,   201,   289,   297,   201,   283,   297,   297,
       6,     6,     7,     6,   198,     6,   195,   200,   283,   283,
     289,   201,   200,   202,     6,   283,   233,   234,   202,   202,
     202,   202,   202,     5,   288,    79,     6,   201,   202,   202,
     201,     6,     6,   201,   283,   202,   202,   200,   201,   200,
     201,   200,   201,   197,     6,   289,     7,   201,   283,   200,
     202,   200,   200,     6,   202,   200,   200,   200,   200,   137,
     283,   283,   292,     6,     6,   202,     6,   236,   283,   299,
     293,   140,   216,   283,   200,   200,   288,   283,     6,   200,
     237,   239,     6,     6,     6,     6,     6,     6,   202,   201,
     288,   102,   103,   108,   278,   102,   103,   278,   292,   249,
     200,   202,   283,   286,   272,   283,   286,   272,   283,   286,
     272,     6,   200,   202,   289,   250,   202,   286,     6,   292,
     286,   283,   283,   283,   283,   283,   202,   202,   202,     6,
     200,   202,     7,   202,     6,   201,   283,   283,   202,   283,
     202,   202,   201,   283,   202,   201,   286,   289,     6,   201,
     286,     6,   202,   202,   283,   202,   200,   202,   202,   200,
     202,   202,   200,   202,   289,     6,    98,   202,   260,   201,
     200,   202,   200,   200,   200,   200,   200,     6,     6,   283,
     297,   213,   195,   200,     6,   201,   200,   283,   202,     6,
     286,     6,   286,     6,     6,   202,     6,   266,   283,     6,
       6,   267,   283,     6,     6,   268,   283,     6,   202,   283,
     272,   250,   292,     6,   286,   292,   283,   283,   283,   283,
       7,   202,   219,   283,   288,   283,   200,   200,   200,   201,
     202,   201,   202,   201,   202,     6,     6,   202,   202,   261,
     202,   200,   202,   200,   200,   200,   200,   297,     6,   201,
     195,   202,   202,   283,   286,   286,   272,     6,   269,   272,
       6,   270,   272,     6,   271,   272,     6,   292,     6,   283,
     283,   283,   283,   217,   296,   222,   201,     6,   202,   200,
     200,   202,   201,   202,   201,   202,   201,   202,   202,   200,
     200,   200,   200,   200,   202,   201,   288,     6,   283,   283,
       6,   272,     6,   272,     6,   272,     6,   283,   283,   283,
     283,   296,     6,   220,   296,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   200,   202,     6,     6,     6,
       6,     6,     6,   296,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   204,   205,   205,   206,   206,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   209,
     210,   210,   210,   210,   211,   211,   211,   211,   211,   211,
     212,   212,   213,   213,   215,   216,   214,   217,   217,   219,
     218,   220,   220,   222,   221,   223,   223,   225,   224,   226,
     226,   226,   226,   226,   227,   227,   228,   228,   229,   229,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   231,   231,   232,
     232,   232,   233,   232,   232,   234,   232,   235,   235,   236,
     236,   237,   237,   238,   238,   238,   239,   239,   240,   240,
     240,   240,   241,   241,   241,   242,   242,   242,   243,   243,
     243,   244,   244,   244,   245,   245,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   248,
     248,   248,   248,   248,   248,   249,   249,   250,   250,   250,
     250,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   252,   252,   252,   252,   252,   253,   253,   254,
     255,   255,   255,   255,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   258,   258,
     258,   259,   258,   260,   258,   261,   258,   262,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   263,   258,
     264,   258,   265,   258,   266,   258,   267,   258,   268,   258,
     269,   258,   270,   258,   271,   258,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   274,   274,   275,   275,   276,   276,   277,
     277,   278,   278,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   280,
     280,   280,   281,   281,   281,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   286,   286,   286,   286,
     286,   287,   287,   287,   287,   288,   288,   289,   289,   289,
     289,   289,   289,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   292,   292,   292,   292,   293,   293,   293,
     293,   294,   294,   295,   295,   296,   296,   296,   296,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     298,   297,   299,   299,   300,   300,   301,   301,   301
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
       8,     4,     4,     4,     4,     8,     4,     6,     4,     1,
       0,     6,     1,     3,     5,     5,     1,     1,     4
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
#line 4336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 204 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4342 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4348 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4354 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 208 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4366 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 209 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4384 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 4396 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4402 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 215 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4408 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 216 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4414 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4420 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 218 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 219 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 4432 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 224 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 4440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 4448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4457 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 4466 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4484 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4501 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4518 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4545 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4563 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4580 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4597 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 371 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 4626 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 385 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4632 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 387 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 4638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4644 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 4650 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4758 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4772 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 513 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 4782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 522 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4793 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 529 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4804 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4817 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 548 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 4827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 557 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4838 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 564 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 4849 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4861 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 4871 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4891 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 4911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 630 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 4921 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 636 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 4928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 4934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 4946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 4952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 4958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 4964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 652 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 4970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 4976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 658 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 4982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 4988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 659 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 4994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 668 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 5003 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 673 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 5013 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5077 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5110 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5143 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 797 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5152 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 802 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 807 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5170 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 812 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 5179 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 817 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5190 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 824 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 5201 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 846 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 851 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 856 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 861 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 5256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 866 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::string((yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 5266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 875 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5276 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 881 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 5286 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5308 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5330 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5343 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 947 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 5365 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 952 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 5374 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5398 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5422 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5437 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5449 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5475 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5502 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5532 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5554 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5570 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5586 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5599 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1162 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5618 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5638 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1189 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 5657 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1205 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 5681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1213 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1219 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 5700 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5715 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5733 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5745 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1273 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 5756 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5768 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1290 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 5779 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1316 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5814 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1326 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 0, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1334 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5831 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1338 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1344 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 1, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5850 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1352 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5858 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1356 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5868 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1362 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 2, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5877 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1370 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 5885 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName
        (std::string((yyvsp[0].c)), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free((yyvsp[0].c));
    }
#line 5895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1380 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), 3, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 5904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1388 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = 0;
    }
#line 5912 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5926 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1404 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 5934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1408 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 5942 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5969 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6005 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6029 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6051 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6076 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6098 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6132 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6166 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6188 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6210 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6240 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6262 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6284 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6320 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6342 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6385 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1804 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6395 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1810 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 6405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1816 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 6416 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6445 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6474 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6495 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6518 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6555 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6591 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6613 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6634 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6654 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2067 "Gmsh.y" /* yacc.c:1646  */
    {
      TranslateShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2072 "Gmsh.y" /* yacc.c:1646  */
    {
      RotateShapes((yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2077 "Gmsh.y" /* yacc.c:1646  */
    {
      SymmetryShapes((yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6717 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2082 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2087 "Gmsh.y" /* yacc.c:1646  */
    {
      DilatShapes((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-1].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 6735 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6762 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2115 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      IntersectCurvesWithSurface((yyvsp[-5].l), (int)(yyvsp[-1].d), (yyval.l));
      List_Delete((yyvsp[-5].l));
    }
#line 6772 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6784 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2132 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 6796 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2137 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 6804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2141 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 6812 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6839 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6866 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6893 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6920 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6945 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6975 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 6999 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7024 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7048 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7164 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7187 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7229 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7336 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7349 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2639 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 7359 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7378 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7410 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7426 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7439 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7452 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7465 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2742 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 1, false);
      Free((yyvsp[-1].c));
    }
#line 7475 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2748 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape((yyvsp[-1].c), i, 0, false);
      Free((yyvsp[-1].c));
    }
#line 7485 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7498 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7511 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7524 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7537 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7597 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7619 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7640 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7659 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7682 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7698 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2956 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 7734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2960 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 7743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2965 "Gmsh.y" /* yacc.c:1646  */
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
    }
#line 7754 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2972 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 7763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2977 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
      SetBoundingBox();
    }
#line 7773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2983 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 7782 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2988 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 7792 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7804 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 3002 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 7812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 3006 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 7820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 7829 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7887 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7899 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7920 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7941 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7967 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 7993 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8032 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8044 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8056 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3212 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 8066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3218 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3225 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 8088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3232 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[-1].d)) skip_until("If", "EndIf");
    }
#line 8096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3236 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8103 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8115 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8127 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8139 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3269 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8149 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8161 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3283 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8171 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3297 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8193 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8205 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3311 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3317 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, (yyvsp[-3].l), 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, (yyval.l));
      List_Delete((yyvsp[-3].l));
    }
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3325 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3332 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8248 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3339 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-4].d),
		   (yyvsp[-2].v)[0], (yyvsp[-2].v)[1], (yyvsp[-2].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, (yyval.l));
    }
#line 8259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3346 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8270 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3353 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3360 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   0., 0., 0., (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8303 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3374 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8314 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3381 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-10].d),
		   (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], (yyvsp[-2].d),
		   NULL, (yyval.l));
    }
#line 8325 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3394 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3401 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3407 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3414 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8377 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3420 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)(yyvsp[-8].d),
		   (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, (yyval.l));
    }
#line 8388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3427 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3433 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8409 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3440 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8419 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3446 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3453 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8440 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3459 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-12].d),
		   0., 0., 0., (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8451 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3466 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8461 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3479 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3485 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3492 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 8503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3498 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)(yyvsp[-14].d),
		   (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-6].d),
		   &extr, (yyval.l));
    }
#line 8514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8521 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3512 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 8528 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8544 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8568 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3574 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 8603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3578 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 8611 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3582 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3586 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
#line 8627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3590 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8637 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3596 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
#line 8647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3602 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 8655 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3606 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 8663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3610 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 8671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3614 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8702 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8714 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3649 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 8722 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8739 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3668 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 8747 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8765 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3688 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 8773 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3692 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 8781 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3697 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 8789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3701 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3707 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 8805 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3711 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 8813 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8873 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 8947 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3844 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete((yyvsp[-1].l));
    }
#line 8956 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9027 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9067 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9079 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9126 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9169 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9193 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9228 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9258 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9287 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9316 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9345 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9374 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9399 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9431 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4303 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Point in Volume not implemented yet");
    }
#line 9471 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4307 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error("Line in Volume not implemented yet");
    }
#line 9479 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9511 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9554 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9597 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9622 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9647 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9672 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4486 "Gmsh.y" /* yacc.c:1646  */
    {
      ReplaceAllDuplicates();
    }
#line 9680 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9694 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4534 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 9734 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4535 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 9740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4536 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 9746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4541 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 9756 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9772 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9794 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 9821 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4604 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9827 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4605 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 9833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4606 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 9839 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4607 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 9845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4608 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 9851 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4609 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 9857 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4610 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 9863 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4611 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 9869 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4613 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 9880 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4619 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d);  }
#line 9886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4620 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 9892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4621 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 9898 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4622 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 9904 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4623 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 9910 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4624 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4625 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 9922 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4626 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 9928 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4627 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 9934 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4628 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 9940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4629 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 9946 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 9952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4631 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 9958 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4632 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 9964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4633 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 9970 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4634 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 9976 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4635 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 9982 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4636 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 9988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4637 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 9994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4638 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 10000 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4639 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 10006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4640 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 10012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4641 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 10018 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4642 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 10024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4643 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 10030 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4644 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 10036 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 10042 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4646 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 10048 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4647 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 10054 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4648 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10060 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4649 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 10066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4650 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 10072 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4651 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 10078 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4660 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 10084 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4661 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 10090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4662 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 10096 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4663 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 10102 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4664 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 10108 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 10114 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 10120 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 10126 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4668 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 10132 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4669 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 10138 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4674 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 10144 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4676 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 10154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4682 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10163 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10184 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10206 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10228 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10250 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10272 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = gmsh_yysymbols.count((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10281 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4781 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 10291 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10307 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10328 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10350 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10372 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10394 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10416 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4891 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-2].c), 0, (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-2].c)); Free((yyvsp[0].c));
    }
#line 10425 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 10434 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10448 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10462 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4921 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 10471 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10486 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10499 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4946 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 10508 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10536 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4978 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 10544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4982 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 10552 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4986 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 10560 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 10568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 10576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 5001 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 10584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 5005 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 10592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 5009 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 5013 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 10608 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 5020 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 5025 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 10625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 10634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 5037 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 5041 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 10651 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 5046 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 10659 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10671 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10683 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 5069 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10691 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10704 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10716 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10728 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 10739 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10753 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10786 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(0);
    }
#line 10794 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5151 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(1);
    }
#line 10802 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5155 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(2);
    }
#line 10810 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5159 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllElementaryEntityNumbers(3);
    }
#line 10818 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5163 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(0);
    }
#line 10826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5167 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(1);
    }
#line 10834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5171 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(2);
    }
#line 10842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5175 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = GetAllPhysicalEntityNumbers(3);
    }
#line 10850 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10883 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10916 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10949 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10982 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 10998 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11014 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11030 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11046 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11060 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11074 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11090 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11106 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11122 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11144 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5443 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5448 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11183 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5452 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11191 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11204 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5468 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 11212 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5472 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 11220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5484 "Gmsh.y" /* yacc.c:1646  */
    {
      int flag;
      (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 11231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5491 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 11242 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5501 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11250 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11266 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5520 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11275 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5525 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 11283 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5532 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11291 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11308 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11320 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5568 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 11340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5572 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11348 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11360 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5584 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 11370 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5590 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 11380 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11392 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5612 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 11415 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11434 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11452 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11470 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11486 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 11506 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5690 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5699 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5708 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11546 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5718 "Gmsh.y" /* yacc.c:1646  */
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
#line 11561 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5729 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 11569 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5733 "Gmsh.y" /* yacc.c:1646  */
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
#line 11592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5752 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 11603 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5759 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 11613 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5765 "Gmsh.y" /* yacc.c:1646  */
    { floatOptions.clear(); charOptions.clear(); }
#line 11619 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5767 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 11631 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5778 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 11640 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5783 "Gmsh.y" /* yacc.c:1646  */
    { List_Add((yyval.l), &((yyvsp[0].c))); }
#line 11646 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5789 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 11658 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5798 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 11670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5811 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11676 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5814 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 11682 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5818 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 11688 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 11692 "Gmsh.tab.cpp" /* yacc.c:1646  */
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
#line 5821 "Gmsh.y" /* yacc.c:1906  */


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
